/*
 *
 * ctif -- C Tool Interface Generator
 *
 * This program takes a Tool Interfaces (tifs) file as produced
 * by the ToolBus interpreter and generates C code for the
 * interfacing of one tool.
 *
 * The global structure of the generated interface is:
 * - prototype declarations of functions called by the generated event handler.
 * - a function
 *      term *Tool_handler(term *e)
 *   for handling the term e coming from the ToolBus
 * - a function
 *      term *Tool_check_in_sign(term_list *reqs)
 *   for dynamically checking that the required input signature is
 *   compatible with the generated input signature of the tool.
 *
 * Author: Paul Klint, February, 1995.
 */

#include "TB.h"
#include <fcntl.h>
#include <limits.h>
#include "terms.h"
 
FILE *handler;             /* Output file for handler code */
FILE *tmp1;                /* Temp file for TBmatch code */
FILE *tmp2;                /* Temp file for signature testing code */
FILE *fout;                /* Output destination (handler or tmp) */

int tot[N_TERM_KINDS];     /* max number of vars per type */

int cur[N_TERM_KINDS];    /* number of vars per type in current call */

TBbool oldstyle = TBtrue;  /* old style handlers */

void reset_arg_counters(void)
{
  int i;

  for(i = 0; i < N_TERM_KINDS; i++){
    if(cur[i] > tot[i])
      tot[i] = cur[i];
    cur[i] = 0;
  }
}

/* Generate variable declarations for all types of variables that
 * occur in tests. For each type an array is generated reflecting
 * the maximal, simultaneous, use of that variable in a single
 * test, e.g.
 *    int int_arg[3];
 */

void gen_var_decls(FILE *fout)
{
  int i;
  for(i = 0; i < N_TERM_KINDS; i++){
    if(tot[i] > 0){
      switch(i)
	{    
	case t_bool:      fprintf(fout, "\tint bool_arg[%d];\n", tot[i]); break;
	case t_int:       fprintf(fout, "\tint int_arg[%d];\n", tot[i]); break;
	case t_real:      fprintf(fout, "\tdouble real_arg[%d];\n", tot[i]); break;
	case t_str:       fprintf(fout, "\tchar *str_arg[%d];\n", tot[i]); break;
	case t_bstr:      fprintf(fout, "\tchar *bstr_arg[%d]; int bstr_size[%d];\n", 
				  tot[i], tot[i]); break;
	case t_list:      fprintf(fout, "\tterm_list *term_list_arg[%d];\n", tot[i]); break;
	case t_term:      fprintf(fout, "\tterm *term_arg[%d];\n", tot[i]); break;  
	}
    }
  }
  fprintf(fout, "\n");
}

/* Visit the arguments of a function:
 * - args: the list of arguments
 * - pref: a prefix to be printed for each argument
 * - f:    function to be called for each argument with three arguments:
 *         . a term (the argument)
 *         . a prefix
 *         . the index of the argument in the argument list
 *         For f we will use:
 *         C_proto_arg:  handle argument position in function prototype
 *         C_format_arg: handle argument position in TBmatch format string
 *         C_var_arg:    handle argument position as variable address in
 *                       TBmatch arguments
 */

void C_visit_args(term_list *args, char *pref, void (*f)(term *, char *, int))
{
  int n = 0;
  reset_arg_counters();
   for( ; args; args = next(args)){
      (*f)(first(args), pref, n);
      n++;
      if(next(args))
	fprintf(fout, ", ");
    }
}

/* Handle one argument position and generate corresponding code
 * for a C function prototype. Arguments pref and n are unused.
 */

void C_proto_arg(term *a, char *pref, int n)
{
       if(TBmatch(a, "<bool>")) fprintf(fout, "int");
  else if(TBmatch(a, "<int>"))  fprintf(fout, "int");
  else if(TBmatch(a, "<real>")) fprintf(fout, "double");
  else if(TBmatch(a, "<str>"))  fprintf(fout, "char *");
  else if(TBmatch(a, "<bstr>")) fprintf(fout, "char *, int");
  else if(TBmatch(a, "<list>")) fprintf(fout, "term_list *");
  else 
    fprintf(fout, "term *");
}

/* Handle one argument position and generate corresponding code
 * for a TBmatch format string. Arguments pref and n are unused.
 */

void C_format_arg(term *a, char *pref, int n)
{
       if(TBmatch(a, "<bool>")) fprintf(fout, "%%d");
  else if(TBmatch(a, "<int>"))  fprintf(fout, "%%d");
  else if(TBmatch(a, "<real>")) fprintf(fout, "%%r");
  else if(TBmatch(a, "<str>"))  fprintf(fout, "%%s");
  else if(TBmatch(a, "<bstr>")) fprintf(fout, "%%b");
  else if(TBmatch(a, "<list>")) fprintf(fout, "[%%l]");
  else 
    fprintf(fout, "%%t");
}

/* Handle one argument position and generate corresponding code
 * for a variable address in a TBmatch' argument list.
 */

void C_var_arg(term *a, char *pref, int n)
{
  tkind vt = t_bool;

  if(TBmatch(a, "<bool>")){      vt = t_bool; fprintf(fout, "%sint_arg[%d]", pref, cur[vt]); }
  else if(TBmatch(a, "<int>")){  vt = t_int; fprintf(fout, "%sint_arg[%d]", pref, cur[vt]); }
  else if(TBmatch(a, "<real>")){ vt = t_real; fprintf(fout, "%sreal_arg[%d]", pref, cur[vt]); }
  else if(TBmatch(a, "<str>")){  vt = t_str; fprintf(fout, "%sstr_arg[%d]", pref, cur[vt]); }
  else if(TBmatch(a, "<bstr>")){ vt = t_bstr; fprintf(fout, "%sbstr_arg[%d], %sbstr_size[%d]",
			                                            pref, cur[vt], pref, cur[vt]);}
  else if(TBmatch(a, "<list>")){ vt = t_list; fprintf(fout, "%sterm_list_arg[%d]", pref, cur[vt]);}
  else { vt = t_term; fprintf(fout, "%sterm_arg[%d]", pref, cur[vt]);}
  cur[vt]++;
}

/* Generate a C function name, replacing `-' by `_'. */

void C_fun_name(char *fname, FILE *fout)
{
    while(*fname){
      fputc((*fname == '-') ? '_' : *fname, fout);
      fname++;
    }
}

/* Generate a complete C function prototype for term t.
 * The result type is rtype.
 */

void C_proto(char *rtype, term *t)
{
  char *fname;
  term_list *fargs;

  fout = handler;

  if(TBmatch(t, "%f(%l)", &fname, &fargs)){
    fprintf(fout, "%s ", rtype);
    C_fun_name(fname, fout);
    fputc('(', fout);
    if(oldstyle) {
      if(!fargs)
        fprintf(fout, "void");
      else
        C_visit_args(fargs, "", C_proto_arg);
    } else {
      fprintf(fout, "int cid");
      if(fargs) {
        fprintf(fout, ", ");
        C_visit_args(fargs, "", C_proto_arg);
      }
    }
    fprintf(fout, ");\n");
  } else
    err_fatal("panic C_proto: %t", t);
}

void C_test_in_sign(term *);

void C_test_eval_do(char *els, char *op, term *t, term *whole)
{
  term_list *fargs;
  char *fname;

  C_proto(streq(op, "rec-eval") ? "term *" : "void  ", t);
  fout = tmp1;

  if(TBmatch(t, "%f(%l)", &fname, &fargs)){
    fprintf(fout, "%sif(TBmatch(e, \"%s(%s(", els, op, fname);
    C_visit_args(fargs, "", C_format_arg);

    fprintf(fout, "))\"%s ", fargs ? "," : "");
    C_visit_args(fargs, "&", C_var_arg);
    fprintf(fout, ")){\n\t\t");
    if(streq(op, "rec-eval"))
      fprintf(fout, "return ");
    C_fun_name(fname, fout);
    if(oldstyle)
      fprintf(fout, "(");
    else
      if(fargs)
        fprintf(fout, "(cid, ");
      else 
        fprintf(fout, "(cid");
    C_visit_args(fargs, "", C_var_arg);
    fprintf(fout, ");\n\t");
    if(!streq(op, "rec-eval"))
      fprintf(fout, "return NULL;\n\t");
    fprintf(fout, "}");
	
  } else
    err_fatal("panic C_test_eval_do: %t", t);
  C_test_in_sign(whole);
}

void C_test_monitor(char *els, term *t, term *whole)
{
  term_list *fargs;
  char *fname;

  C_proto("term *", t);
  fout = tmp1;

  if(TBmatch(t, "%f(%l)", &fname, &fargs)){
    fprintf(fout, "%sif(TBmatch(e, \"%s(", els, fname);
    C_visit_args(fargs, "", C_format_arg);

    fprintf(fout, ")\"%s ", fargs ? "," : "");
    C_visit_args(fargs, "&", C_var_arg);
    fprintf(fout, ")){\n\t\t");
    fprintf(fout, "return ");
    C_fun_name(fname, fout);
    if(oldstyle)
      fprintf(fout, "(");
    else
      fprintf(fout, "(cid, ");
    C_visit_args(fargs, "", C_var_arg);
    fprintf(fout, ");\n\t");
    fprintf(fout, "}");
  } else 
    err_fatal("panic C_monitor: %t", t);
  C_test_in_sign(whole);
}

void C_test_other(char *els, term *t, term *whole)
{ term_list *fargs;
  char *fname;

  C_proto("void  ", t);
  fout = tmp1;

  if(TBmatch(t, "%f(%l)", &fname, &fargs)){
    fprintf(fout, "%sif(TBmatch(e, \"%s(", els, fname);
    C_visit_args(fargs, "", C_format_arg);

    fprintf(fout, ")\"%s ", fargs ? "," : "");
    C_visit_args(fargs, "&", C_var_arg);
    fprintf(fout, ")){\n\t\t");
    C_fun_name(fname, fout);
    if(oldstyle)
      fprintf(fout, "(");
    else
      fprintf(fout, "(cid, ");
    C_visit_args(fargs, "", C_var_arg);
    fprintf(fout, ");\n\t\treturn NULL;\n\t}");
  } else
    err_fatal("panic C_test_other: %t", t);
  C_test_in_sign(whole);
}

/* Generate a test for the test in signature code */

int n_in_sign_test = 0;

void C_test_in_sign(term *t)
{
  char term_buf[512], *p;
  
  strcpy(term_buf, TBsprintf("%t", t));
  fprintf(tmp2, "\tin_sign[%d] = \"", n_in_sign_test);
  n_in_sign_test++;

  for(p = term_buf; *p; p++){
    switch(*p)  
      {
      case '"': fprintf(tmp2, "\\\""); break;
      case '\n':fprintf(tmp2, "\\\n"); break;
      default:  fputc(*p, tmp2);
      }
  }
  fprintf(tmp2, "\";\n");
}

void copy_file(char *name, FILE *tofile)
{
  FILE *f;
  int c;

  f = fopen(name, "r");
  if(!f)
    err_sys_fatal("Cannot copy: %s", name);
  while((c = fgetc(f)) > 0)
    fputc(c, handler);
  fclose(f);
}

void gen_header(char *the_tool_name)
{ char *s =
"/* GENERATED AUTOMATICALLY, DO NOT MODIFY */\n\
/* Tool Interface File for tool: %s */\n\
\n\
#include \"TB.h\"\n\
\n\
/* Prototypes for functions used in event handler */\n";

fprintf(handler, s, the_tool_name);

}

/* Read the tool interfaces file and generate parts of the
 * tif code.
 */

void read_tifs(int tifs, char *the_tool_name)
{  char *els = "\t";
   int nelements = 0;
   char pat[128];
   term *t;
  
  /* construct match pattern, e.g. ``%f(<calc>,%l)'' */
  sprintf(pat, "%%f(<%s>, %%l)", the_tool_name);

  while((t = TBread(tifs)) && !TBmatch(t, "end-of-tifs")){
    char *atf;
    term_list *arg;
     
    if(TBmatch(t, pat, &atf, &arg)){
      /* TBprintf(stderr, "processing ... %t\n", t); */
	nelements++;
	if(streq(atf, "rec-do") || streq(atf, "rec-eval")) {
	  C_test_eval_do(els, atf, first(arg), t);
	  els = " else ";
	} else if(streq(atf, "rec-terminate") || streq(atf , "rec-ack-event")){
	  term *trm = mk_appl1(TBlookup(atf), first(arg));
	  C_test_other(els, trm, t);
	  els = " else ";
	} else if(streq(atf, "rec-monitor")) {
          term *trm = mk_appl1(TBlookup(atf), first(arg));
          C_test_monitor(els, trm, t);
          els = " else ";
	} else if(streq(atf, "snd-value") || streq(atf, "snd-event") ||
		  streq(atf, "snd-connect") || streq(atf, "snd-disconnect")){
	} else
	  TBprintf(stderr, "ignored: %t\n", t);
    } else if(TBmatch(t, "snd-connect(%l)", &arg)){
      
    } else        
      /* TBmsg("Can't match: %t\n", t); */;
  }
  if(nelements == 0)
    err_fatal("No matches found, probably wrong tool name `%s'", the_tool_name);

  fprintf(tmp1, " %s {\n\t\tTBprintf(stderr, \"Ignored: %%t\\n\", e);\n\t\treturn NULL;\n\t}", els);
  fprintf(tmp1, "\n}\n");
  fclose(tmp1);
  fclose(tmp2);
}

/* Generate the event handler:
 * - generate the function header
 * - generate variable declarations
 * - copy the body from file tmp
 */

void gen_handler(char *the_tool_name, char *tmp)
{
  fprintf(handler, "\n/* Event handler for tool: %s */\n\n", the_tool_name);
  fprintf(handler, "term *");
  C_fun_name(the_tool_name, handler);
  if(oldstyle)
    fprintf(handler, "_handler(term *e){\n");
  else
    fprintf(handler, "_handler(int cid, term *e){\n");
  gen_var_decls(handler);

  copy_file(tmp, handler);
  unlink(tmp); 
}

void gen_test_in_sign(char *the_tool_name, char *tmp)
{
  char *header = "\n\
/* Check input signature for tool: %s\n\
 * returns: NULL (requested input signature is subset of tool's input signature);\n\
 *          non-null term: first element not in tool's input signature.\n\
 * NOTE:    In the signature all terms have as first argument <%s>, but this\n\
 *          does NOT appear in the actual terms that will be sent to the tool.\n\
 */\n\n";

  char *for_loop = "\n\
\tfor( ; reqs; reqs = next(reqs)){\n\
\t\tfor(i = 0; i < %d; i++){\n\
\t\t\tif(TBmatch(first(reqs), in_sign[i])) goto found;\n\
\t\t}\n\
\t\treturn first(reqs);\n\
\t\tfound:;\n\t}\n\
\treturn NULL;\n}\n";

  fprintf(handler, header, the_tool_name, the_tool_name);

  /* generate the function header */
  fprintf(handler, "term *");
  C_fun_name(the_tool_name, handler);
  if(oldstyle)
    fprintf(handler, "_check_in_sign(term_list *reqs){\n");
  else
    fprintf(handler, "_check_in_sign(int cid, term_list *reqs){\n");
  fprintf(handler, "\tchar *in_sign[%d];\n\tint i;\n\n", n_in_sign_test);
  copy_file(tmp, handler);
  unlink(tmp);

  fprintf(handler, for_loop, n_in_sign_test);
}

/* ------------- usage and help functions --------------------------------*/

char * Usage = "ctif [-help] -tool ToolName -tifs ToolInterfaces";

void help(void)
{
 char * str =
"\n\
CTIF -- AUTOMATIC C GENERATOR FOR TOOLBUS INTERFACES\n\
====================================================\n\
ctif generates C interface code for connecting tools with the ToolBus\n\
Options are:\n\
-help                 prints this message\n\
-tool ToolName        name of the tool as used in the ToolBus script\n\
-tifs ToolInterfaces  interfaces files as generated by the ToolBus, e.g.\n\
                          toolbus -gentifs my_script.tb\n\
                      will generate the file my_script.tifs\n\
-newstyle             generate new style handlers (including cid arg.)\n\
\n\
The generated tool interface is always written to a file named ToolName.tif.c\n\
For example ``calc.tif.c'' when the tool name is ``calc''\n";

 fprintf(stderr, str);
}

/* ctif -- main program */

void main(int argc, char **argv)
{
  int tifs;
  char * search_tool_name = NULL, *tifs_name = NULL, 
  handler_name[_POSIX_PATH_MAX], *tmp_name1 = "**tmp1", *tmp_name2 = "**tmp2";
  int i = 0;

  init_terms();
  init_utils();

  tool_name = "ctif";
  if(argc == 1)
    err_fatal("Usage: %s", Usage);

  for(i = 1; i < argc; i++){
    if(streq(argv[i], "-tool")){
      i++;
      search_tool_name = argv[i];
    } else if(streq(argv[i], "-tifs")){
      i++;
      tifs_name = argv[i];
    } else if(streq(argv[i], "-newstyle")) {
      oldstyle = TBfalse;
    } else if(streq(argv[i], "-help")){
      help();
      exit(0);
    } else
      err_fatal("Usage: %s", Usage);
  }
  if(!search_tool_name)
    err_fatal("Missing tool name\nUsage: %s", Usage);

  if(!tifs_name)
    err_fatal("Missing tifs name\nUsage: %s", Usage);

  tifs = open(tifs_name, O_RDONLY);
  if(tifs < 0)
    err_sys_fatal("Can't open `%s'", tifs_name);
 
  sprintf(handler_name, "%s.tif.c", search_tool_name);
  handler = fopen(handler_name, "w");
  if(!handler)
    err_sys_fatal("Can't create `%s'", handler_name);

  tmp1 = fopen(tmp_name1, "w");
  if(!tmp1)
    err_sys_fatal("Can't create tmp file `%s'", tmp_name1);

  tmp2 = fopen(tmp_name2, "w");
  if(!tmp2)
    err_sys_fatal("Can't create tmp file `%s'", tmp_name2);

  gen_header(search_tool_name);
  
  read_tifs(tifs, search_tool_name);

  gen_handler(search_tool_name, tmp_name1);

  gen_test_in_sign(search_tool_name, tmp_name2);

  fclose(handler);
  close(tifs);
  exit(0);
} 




