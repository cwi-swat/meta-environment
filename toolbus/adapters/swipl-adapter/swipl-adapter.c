/*
	swipl-adapter.c - a SWI-Prolog adapter for the ToolBus
	1995, Vincent Partington, partingt@fwi.uva.nl
*/

#include	<fcntl.h>
#include	<signal.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<SWI-Prolog.h>
/*
 * Undefine backwards compatibility definitions in SWI-Prolog.h.
 * They mess up TB.h.
 */
#undef		atomic
#undef		functor
#undef		module
#undef		term
#include	<TB.h>

#define DEBUG 1

/*
 * Global constants, can be overriden in Makefile.
 * PL_VAR_NAME has a reasonable default;
 * ADAPTER_LOC does not, so it best to override it in the Makefile.
 */
#ifndef	PL_VAR_NAME
#define	PL_VAR_NAME	"pl-var"
#endif

#ifndef	ADAPTER_LOC
#define	ADAPTER_LOC	"/usr/local/ToolBus/bin/swipl-adapter"
#endif

/*
 * Globals.
 */
static term	*tb_error_term;

/*
 * Prolog extensions: none.
 */
PL_extension PL_extensions [] =
{ { NULL,	0,	NULL,	0} };

/*****
 *****
 ***** DISPLAY FUNCTIONS
 *****
 *****/

#ifdef	DEBUG
/*
 * Print a prolog term to stderr. Useful for debugging purposes.
 * IN:
 *		t		a prolog term
 */
static void do_pl_display(term_t t)
{
	functor_t	functor;
	int			arity, n;

	switch(PL_term_type(t))
	{
	case PL_VARIABLE:
		fprintf(stderr, "_%d", (int) t);
		break;
	case PL_ATOM:
		fprintf(stderr, "%s", PL_atom_value(PL_atomic(t)));
		break;
	case PL_STRING:
		fprintf(stderr, "\"%s\"", PL_atom_value(PL_atomic(t)));
		break;
	case PL_INTEGER:
		fprintf(stderr, "%ld", PL_integer_value(PL_atomic(t)));
		break;
	case PL_FLOAT:
		fprintf(stderr, "%f", PL_float_value(PL_atomic(t)));
		break;
	case PL_TERM:
		functor = PL_functor(t);
		arity = PL_functor_arity(functor);
		fprintf(stderr, "%s(", PL_atom_value(PL_functor_name(functor)));
		do_pl_display(PL_arg(t, 1));
		for(n = 2; n <= arity; n++)
		{
			fprintf(stderr, ", ");
			do_pl_display(PL_arg(t, n));
		}
		fprintf(stderr, ")");
		break;
	default:
		PL_fatal_error("Illegal type in PL_display!");
	}
}

/*
 * Same as do_pl_display but adds a newline.
 */
static void pl_display(term_t t)
{
	do_pl_display(t);
	fprintf(stderr, "\n");
}
#endif

/*
 * Report an error to the Toolbus system and to the user
 * IN:
 *		err_string		the error to report
 */
static void report_error(char *err_string)
{
#if	0
/* if you want swipl-adapter errors to be printed to stderr, change 0 to 1. */
	fprintf(stderr, "swipl-adapter error: %s\n", err_string);
#endif

	tb_error_term = TBmake("snd-value(error(%s))", err_string);
}

/*****
 *****
 *****		TOOLBUS -> PROLOG CONVERSION
 *****
 *****/
static int tb_to_pl_list(term *tb_term, term_t *p_pl_term);
static int tb_to_pl_term(term *tb_term, term_t *p_pl_term);

/*
 * Convert a toolbus list to a prolog list.
 * IN:
 *		tb_list		toolbus list
 * OUT:
 *		*p_pl_list	prolog list
 *		result		non-zero in case of an error
 */
static int tb_to_pl_list(term *tb_list, term_t *p_pl_list)
{
	term_t	pl_head, pl_tail, pl_list;

	if(tb_list == NULL)
	{
		pl_list = PL_new_term();
		PL_unify_atomic(pl_list, PL_new_atom("[]"));
	}
	else
	{
		if(tb_to_pl_term(first(tb_list), &pl_head) != 0 ||
				tb_to_pl_list(next(tb_list), &pl_tail) != 0)
			return -1;

		pl_list = PL_new_term();
		PL_unify_functor(pl_list, PL_new_functor(PL_new_atom("."), 2));
		if(pl_head != NULL)
			PL_unify(PL_arg(pl_list, 1), pl_head);
		if(pl_tail != NULL)
			PL_unify(PL_arg(pl_list, 2), pl_tail);
	}

	*p_pl_list = pl_list;
	return 0;
}

/*
 * Convert a toolbus term to a prolog term.
 * IN:
 *		tb_term		toolbus term
 * OUT:
 *		*p_pl_term	prolog term
 *		result		non-zero in case of an error
 */
static int tb_to_pl_term(term *tb_term, term_t *p_pl_term)
{
	int			an_int;
	double		a_double;
	char		*a_string;
	term		*a_list;
	atomic_t	pl_atom = NULL;

	if(TBmatch(tb_term, "%d", &an_int))
		pl_atom = PL_new_integer((long) an_int);
	else if(TBmatch(tb_term, "%r", &a_double))
		pl_atom = PL_new_float(a_double);
	else if(TBmatch(tb_term, "%s", &a_string))
		pl_atom = PL_new_string(a_string);
	else if(TBmatch(tb_term, "%f", &a_string))
	{
		if(strcmp(a_string, PL_VAR_NAME) != 0)
			pl_atom = PL_new_atom(a_string);
	}
	else if(TBmatch(tb_term, "[%l]", &a_list))
		return tb_to_pl_list(a_list, p_pl_term);
	else
	{
		report_error("unknown toolbus data type");
		return -1;
	}

	*p_pl_term = PL_new_term();
	PL_unify_atomic(*p_pl_term, pl_atom);
	return 0;
}

/*
 * Convert a toolbus function to a prolog function.
 * IN:
 *		s			function name
 *		args		list of arguments
 * OUT:
 *		*p_pl_term	prolog function term
 *		result		non-zero in case of an error
 */
static int tb_to_pl_function(char *s, term *args, term_t *p_pl_term)
{
	int			arg_nr, nr_args;
	term		*cur_tb;
	term_t		pl_term, pl_arg;

/* count number of arguments */
	nr_args = 0;
	for(cur_tb = args; cur_tb != NULL; cur_tb = next(cur_tb))
		nr_args++;

/* make prolog functor term */
	pl_term = PL_new_term();
	PL_unify_functor(pl_term, PL_new_functor(PL_new_atom(s), nr_args));

/* convert toolbus parameters to prolog parameters */
	arg_nr = 1;
	for(cur_tb = args; cur_tb != NULL; cur_tb = next(cur_tb))
	{
		if(tb_to_pl_term(first(cur_tb), &pl_arg) != 0)
			return -1;

		if(pl_arg != NULL)
			PL_unify(PL_arg(pl_term, arg_nr++), pl_arg);
	}

	*p_pl_term = pl_term;
	return 0;
}

/*****
 *****
 *****		PROLOG -> TOOLBUS CONVERSION
 *****
 *****/
static int pl_to_tb_list(term_t pl_term, term **p_tb_list);
static int pl_to_tb_term(term_t pl_term, term **p_tb_list);

/*
 * Convert a prolog list to a toolbus list.
 * IN:
 *		pl_list		prolog list
 * OUT:
 *		*p_tb_list	toolbus list
 *		result		non-zero in case of an error
 */
int pl_to_tb_list(term_t pl_list, term **p_tb_list)
{
	term		*tb_head, *tb_tail;
	functor_t	functor;

	functor = PL_functor(pl_list);
	if(strcmp(PL_atom_value(PL_functor_name(functor)), ".") != 0 ||
			PL_functor_arity(functor) != 2)
	{
		report_error("unknown prolog term");
		return -1;
	}

	if(pl_to_tb_term(PL_arg(pl_list, 1), &tb_head) != 0)
		return -1;

	if(pl_to_tb_term(PL_arg(pl_list, 2), &tb_tail) != 0)
		return -1;

	*p_tb_list = mk_list(tb_head, tb_tail);
	return 0;
}

/*
 * Convert a prolog term to a toolbus term.
 * IN:
 *		pl_term		prolog term
 * OUT:
 *		*p_tb_term	toolbus term
 *		result		non-zero in case of an error
 */
static int pl_to_tb_term(term_t pl_term, term **p_tb_term)
{
	char	*a_string;
	term	*tb_term;

	switch(PL_type(pl_term))
	{
	case PL_VARIABLE:
		report_error("unresolved prolog variable");
		return -1;
	case PL_ATOM:
		a_string = PL_atom_value(PL_atomic(pl_term));
		if(strcmp(a_string, "[]") == 0)
			tb_term = TBmake("[]");
		else
			tb_term = TBmake("%f", a_string);
		break;
	case PL_STRING:
		tb_term = TBmake("%s", PL_atom_value(PL_atomic(pl_term)));
		break;
	case PL_INTEGER:
		tb_term = TBmake("%d", PL_integer_value(PL_atomic(pl_term)));
		break;
	case PL_FLOAT:
		tb_term = TBmake("%r", PL_float_value(PL_atomic(pl_term)));
		break;
	case PL_TERM:
		return pl_to_tb_list(pl_term, p_tb_term);
	default:	
		report_error("unknown prolog data type");
		return -1;
	}

	*p_tb_term = tb_term;
	return 0;
}

/*
 * Convert a prolog function to a toolbus term.
 * IN:
 *		pl_term		the prolog term
 * OUT:
 *		*p_tb_term	the toolbus term
 *		result		non-zero in case of an error
 */
static int pl_to_tb_function(term_t pl_term, term **p_tb_term)
{
	char		*functor_name;
	int			arg_nr, nr_args;
	term		*tb_arg, *tb_arg_list;
	functor_t	functor;

/* sanity check */
	if(PL_type(pl_term) != PL_TERM)
	{
		report_error("unknown prolog term");
		return -1;
	}

/* get functor info */
	functor = PL_functor(pl_term);
	nr_args = PL_functor_arity(functor);
	functor_name = PL_atom_value(PL_functor_name(functor));

/* convert prolog parameters to toolbus parameters */
	tb_arg_list = NULL;
	for(arg_nr = nr_args; arg_nr > 0; arg_nr--)
	{
		if(pl_to_tb_term(PL_arg(pl_term, arg_nr), &tb_arg) != 0)
			return -1;
		tb_arg_list = mk_list(tb_arg, tb_arg_list);
	}

/* make the final term */
	*p_tb_term = TBmake("%f(%l)", functor_name, tb_arg_list);
	return 0;
}

/*****
 *****
 *****		TOOL INTERFACE
 *****
 *****/

/*
 * Handle a toolbus term that represents a prolog term: 
 * 1. convert it into a prolog term
 * 2. hand it to the prolog system
 * 3. convert the result back into a toolbus term
 *    or generate an error
 * 
 * IN:
 * 		s			function name
 * 		args		list of arguments
 * OUT:
 * 		result		the toolbus term to return to the toolbus
 */
static term *handle_prolog_term(char *s, term *args)
{
	int		pl_res;
	term	*tb_term;
	term_t	pl_term;

/* convert toolbus to prolog term */
	if(tb_to_pl_function(s, args, &pl_term) != 0)
		return tb_error_term;

/* call prolog interpreter */
#if	DEBUG
	fprintf(stderr, "Before calling the prolog system: ");
	pl_display(pl_term);
#endif

	pl_res = PL_call(pl_term, NULL);

#if	DEBUG
	fprintf(stderr, "After calling the prolog system: ");
	pl_display(pl_term);
#endif

/* return toolbus term */
	if(!pl_res)
		return TBmake("snd-value(result(false,%f(%l)))", s, args);

	if(pl_to_tb_function(pl_term, &tb_term) != 0)
		return tb_error_term;

	return TBmake("snd-value(result(true,%t))", tb_term);
}

/*
 * Toolbus callback function, called when a term from the toolbus is received
 * IN:
 * 		inp			the toolbus term to handle
 * OUT:
 * 		result		a new toolbus term or NULL in case of an error
 */
static term *swipl_handler(term *inp)
{
	char	*s;
	term	*arg;

	if(TBmatch(inp, "rec-eval(query(%f(%l)))", &s, &arg))
		return handle_prolog_term(s, arg);
	else if(TBmatch(inp, "rec-terminate(%t)", &arg))
		exit(0);
	else
		TBprintf(stderr, "swipl-adapter error: wrong input %t received.\n",
																		inp);

	return NULL;
}

/*
 * Init prolog system
 * IN:
 *		argc, argv	self-generated arguments
 *		env			the real environment
 */
static void init_prolog(int argc, char **argv, char **env)
{
	if(!PL_initialise(argc, argv, env))
	{
		fprintf(stderr, "swipl-adapter error: could not initialise prolog.\n");
		PL_halt(1);
	}
}

/*
 * Connect to toolbus and wait for events (never returns)
 * IN:
 *		argc, argv	command line arguments
 */
static void connect_to_toolbus(int argc, char **argv)
{
	TBinit(argv[0], argc, argv, swipl_handler, NULL);
	TBeventloop();
}

/*
 * Main function.
 */
#define	NR_PROLOG_ARGS	5
int main(int argc, char **argv, char **env)
{
	int		i, prolog_argc;
	char	*prolog_argv[NR_PROLOG_ARGS+1],
			*binary_name = NULL;

/* get command line parameters */
	i = 1;
	while(i < argc)
	{
		if(streq(argv[i], "-binary"))
			binary_name = argv[++i];
		i++;
	}

/* init prolog system */
	prolog_argc = 0;
	prolog_argv[prolog_argc++] = ADAPTER_LOC;
	if(binary_name != NULL)
	{
		prolog_argv[prolog_argc++] = "-x";
		prolog_argv[prolog_argc++] = binary_name;
	}
	prolog_argv[prolog_argc++] = "-g";
	prolog_argv[prolog_argc++] = "true";
	prolog_argv[prolog_argc] = NULL;
	init_prolog(prolog_argc, prolog_argv, env);

/* install signal handlers */
	for(i = 0; i < 32; i++)
		signal(i, SIG_DFL);

/* connect to the toolbus */
	connect_to_toolbus(argc, argv);

	return 0;
}
