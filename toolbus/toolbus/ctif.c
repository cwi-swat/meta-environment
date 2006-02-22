/*{{{  header */

/*

   ToolBus -- The ToolBus Application Architecture
   Copyright (C) 1998-2000  Stichting Mathematisch Centrum, Amsterdam, 
   The  Netherlands.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/

/*}}}  */

/*{{{  includes */

#include "TB.h"
#include <fcntl.h>
#include <limits.h>
#include "terms.h"

/*}}}  */

/*{{{  variables */

FILE *c_handler;           /* Output file for handler c code */
FILE *h_handler;           /* Output file for handler declarations of c code */
FILE *tmp1;                /* Temp file for TBmatch code */
FILE *tmp2;                /* Temp file for signature testing code */
FILE *fout;                /* Output destination (c_handler or tmp) */

int tot[N_TERM_KINDS];     /* max number of vars per type */

int cur[N_TERM_KINDS];    /* number of vars per type in current call */

TBbool multitools = TBfalse;	/* old style handlers */
TBbool backdoor = TBfalse;	/* Leave the back door open */
TBbool placeholders = TBfalse;	/* Use placeholder matching style */
TBbool split_output = TBfalse;  /* Create only a C-file (i.e., not a 
				   corresponding .h file by default */
char *termptr = "term *";	/* Wat does a term pointer look like? */
char *Tmatch   = "TBmatch";	/* How to match terms */
char *TmatchSimple = "TBmatch"; /* How to match terms without patterns */
char *is_empty = NULL;	        /* What is the `is_empty' predicate? */
char *Tprintf = "TBprintf";	/* How to print terms */
char *firstel  = "list_first";	/* How to get the first element of a list */
char *nextel   = "list_next";	/* How to get the tail of a list */
char *header_file = "TB.h";	/* Header file */

/*}}}  */

/*{{{  void reset_arg_counters(void) */

void reset_arg_counters(void)
{
  int i;

  for(i = 0; i < N_TERM_KINDS; i++){
    if(cur[i] > tot[i])
      tot[i] = cur[i];
    cur[i] = 0;
  }
}

/*}}}  */

/* Generate variable declarations for all types of variables that
 * occur in tests. For each type an array is generated reflecting
 * the maximal, simultaneous, use of that variable in a single
 * test, e.g.
*    int int_arg[3];
*/

/*{{{  void gen_var_decls(FILE *fout) */

void gen_var_decls(FILE *fout)
{
  int i;
  for(i = 0; i < N_TERM_KINDS; i++) {
    if(tot[i] > 0) {
      switch(i) {
	case t_bool:    fprintf(fout, "\t%sbool_arg[%d];\n", termptr, tot[i]);
			break;
	case t_int:     fprintf(fout, "\tint int_arg[%d];\n", tot[i]);
			break;
	case t_real:    fprintf(fout, "\tdouble real_arg[%d];\n", tot[i]); 
			break;
	case t_str:	fprintf(fout, "\tchar *str_arg[%d];\n", tot[i]); 
			break;
	case t_bstr:	fprintf(fout, "\tchar *bstr_arg[%d]; " \
				"int bstr_size[%d];\n", tot[i], tot[i]); 
			break;
	case t_list:	fprintf(fout, "\t%sterm_list_arg[%d];\n",
				termptr, tot[i]);
			break;
	case t_term:	fprintf(fout, "\t%sterm_arg[%d];\n",termptr,tot[i]);
			break;  
      }
    }
  }
  fprintf(fout, "\n");
}

/*}}}  */

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

/*{{{  void C_visit_args(term_list *args, char *pref, void (*f)(term *, char *, int)) */

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

/*}}}  */

/* Handle one argument position and generate corresponding code
 * for a C function prototype. Arguments pref and n are unused.
 */

/*{{{  void C_proto_arg(term *a, char *pref, int n) */

void C_proto_arg(term *a, char *pref, int n)
{
  if(TBmatch(a, "<bool>")) fprintf(fout, "%s", termptr);
  else if(TBmatch(a, "<int>"))  fprintf(fout, "int");
  else if(TBmatch(a, "<real>")) fprintf(fout, "double");
  else if(TBmatch(a, "<str>"))  fprintf(fout, "char *");
  else if(TBmatch(a, "<bstr>")) fprintf(fout, "char *, int");
  else if(TBmatch(a, "<list>")) fprintf(fout, "%s", termptr);
  else 
    fprintf(fout, "%s", termptr);
}

/*}}}  */

/* Handle one argument position and generate corresponding code
 * for a TBmatch format string. Arguments pref and n are unused.
 */

/*{{{  void C_format_arg(term *a, char *pref, int n) */

void C_format_arg(term *a, char *pref, int n)
{
  if(placeholders) {
    if(TBmatch(a, "<bool>")) fprintf(fout, "<term>");
    else if(TBmatch(a, "<int>"))  fprintf(fout, "<int>");
    else if(TBmatch(a, "<real>")) fprintf(fout, "<real>");
    else if(TBmatch(a, "<str>"))  fprintf(fout, "<str>");
    else if(TBmatch(a, "<bstr>")) fprintf(fout, "<bstr>");
    else if(TBmatch(a, "<list>")) fprintf(fout, "<list>");
    else 
      fprintf(fout, "<term>");
  } else {
    if(TBmatch(a, "<bool>")) fprintf(fout, "%%t");
    else if(TBmatch(a, "<int>"))  fprintf(fout, "%%d");
    else if(TBmatch(a, "<real>")) fprintf(fout, "%%r");
    else if(TBmatch(a, "<str>"))  fprintf(fout, "%%s");
    else if(TBmatch(a, "<bstr>")) fprintf(fout, "%%b");
    else if(TBmatch(a, "<list>")) fprintf(fout, "[%%l]");
    else 
      fprintf(fout, "%%t");
  }
}

/*}}}  */

/* Handle one argument position and generate corresponding code
 * for a variable address in a TBmatch' argument list.
 */

/*{{{  void C_var_arg(term *a, char *pref, int n) */

void C_var_arg(term *a, char *pref, int n)
{
  tkind vt = t_bool;

  if(TBmatch(a, "<bool>")){      vt = t_bool; fprintf(fout, "%sbool_arg[%d]", pref, cur[vt]); }
  else if(TBmatch(a, "<int>")){  vt = t_int; fprintf(fout, "%sint_arg[%d]", pref, cur[vt]); }
  else if(TBmatch(a, "<real>")){ vt = t_real; fprintf(fout, "%sreal_arg[%d]", pref, cur[vt]); }
  else if(TBmatch(a, "<str>")){  vt = t_str; fprintf(fout, "%sstr_arg[%d]", pref, cur[vt]); }
  else if(TBmatch(a, "<bstr>")){ vt = t_bstr; fprintf(fout, "%sbstr_arg[%d], %sbstr_size[%d]",
						      pref, cur[vt], pref, cur[vt]);}
  else if(TBmatch(a, "<list>")){ vt = t_list; fprintf(fout, "%sterm_list_arg[%d]", pref, cur[vt]);}
  else { vt = t_term; fprintf(fout, "%sterm_arg[%d]", pref, cur[vt]);}
  cur[vt]++;
}

/*}}}  */

/* Generate a C function name, replacing `-' by `_'. */

/*{{{  void C_fun_name(char *fname, FILE *fout) */

void C_fun_name(char *fname, FILE *fout)
{
  while(*fname){
    fputc((*fname == '-') ? '_' : *fname, fout);
    fname++;
  }
}

/*}}}  */

/* Generate a complete C function prototype for term t.
 * The result type is rtype.
 */

/*{{{  void C_proto(char *rtype, term *t) */

void C_proto(char *rtype, term *t)
{
  char *fname;
  term_list *fargs;

  if( split_output == TBtrue )
    fout = h_handler;
  else
    fout = c_handler;

  if(TBmatch(t, "%f(%l)", &fname, &fargs)){
    fprintf(fout, "%s ", rtype);
    C_fun_name(fname, fout);
    fputc('(', fout);
    if(!multitools) {
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

/*}}}  */

void C_test_in_sign(term *);

/*{{{  void C_test_eval_do(char *els, char *op, term *t, term *whole) */

void C_test_eval_do(char *els, char *op, term *t, term *whole)
{
  term_list *fargs;
  char *fname;

  C_proto(streq(op, "rec-eval") ? termptr : "void  ", t);
  fout = tmp1;

  if(TBmatch(t, "%f(%l)", &fname, &fargs)){
    fprintf(fout, "%sif(%s(e, \"%s(%s(", els, Tmatch, op, fname);
    C_visit_args(fargs, "", C_format_arg);

    fprintf(fout, "))\"%s ", fargs ? "," : "");
    C_visit_args(fargs, "&", C_var_arg);
    fprintf(fout, ")){\n\t\t");
    if(streq(op, "rec-eval"))
      fprintf(fout, "return ");
    C_fun_name(fname, fout);
    if(!multitools)
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

/*}}}  */
/*{{{  void C_test_monitor(char *els, term *t, term *whole) */

void C_test_monitor(char *els, term *t, term *whole)
{
  term_list *fargs;
  char *fname;

  C_proto(termptr, t);
  fout = tmp1;

  if(TBmatch(t, "%f(%l)", &fname, &fargs)){
    fprintf(fout, "%sif(%s(e, \"%s(", els, Tmatch, fname);
    C_visit_args(fargs, "", C_format_arg);

    fprintf(fout, ")\"%s ", fargs ? "," : "");
    C_visit_args(fargs, "&", C_var_arg);
    fprintf(fout, ")){\n\t\t");
    fprintf(fout, "return ");
    C_fun_name(fname, fout);
    if(!multitools)
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

/*}}}  */
/*{{{  void C_test_other(char *els, term *t, term *whole) */

void C_test_other(char *els, term *t, term *whole)
{
  term_list *fargs;
  char *fname;

  C_proto("void  ", t);
  fout = tmp1;

  if(TBmatch(t, "%f(%l)", &fname, &fargs)){
    fprintf(fout, "%sif(%s(e, \"%s(", els, Tmatch, fname);
    C_visit_args(fargs, "", C_format_arg);

    fprintf(fout, ")\"%s ", fargs ? "," : "");
    C_visit_args(fargs, "&", C_var_arg);
    fprintf(fout, ")){\n\t\t");
    C_fun_name(fname, fout);
    if(!multitools)
      fprintf(fout, "(");
    else
      fprintf(fout, "(cid, ");
    C_visit_args(fargs, "", C_var_arg);
    fprintf(fout, ");\n\t\treturn NULL;\n\t}");
  } else
    err_fatal("panic C_test_other: %t", t);
  C_test_in_sign(whole);
}

/*}}}  */

/* Generate a test for the test in signature code */

int n_in_sign_test = 0;

/*{{{  void C_test_in_sign(term *t) */

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

/*}}}  */

/*{{{  void copy_file(char *name, FILE *tofile) */

void copy_file(char *name, FILE *tofile)
{
  FILE *f;
  int c;

  f = fopen(name, "rb");
  if(!f)
    err_sys_fatal("Cannot copy: %s", name);
  while((c = fgetc(f)) > 0)
    fputc(c, c_handler);
  fclose(f);
}

/*}}}  */

/*{{{  void gen_header(char *the_tool_name) */

void gen_header(char *the_tool_name)
{ 
  FILE* handler;
  if( split_output == TBtrue )
    handler = h_handler;
  else
    handler = c_handler;

  /* Only generate a .h file when the -split option was specified */
  if( split_output == TBtrue )
  {
    fprintf(h_handler, "/* GENERATED AUTOMATICALLY, DO NOT MODIFY */\n" \
	    "/* Tool Interface include File for tool: %s */\n\n",the_tool_name);

    fprintf(h_handler, "#ifndef _%s_tif_h_\n", the_tool_name );
    fprintf(h_handler, "#define _%s_tif_h_\n", the_tool_name );
  }
  fprintf(c_handler, "/* GENERATED AUTOMATICALLY, DO NOT MODIFY */\n" \
	  "/* Tool Interface File for tool: %s */\n\n",the_tool_name);

  if(header_file)
    fprintf(handler, "#include \"%s\"\n\n", header_file);

  if( split_output == TBtrue )
  {
    fprintf(c_handler, "#include \"%s.tif.h\"\n", the_tool_name );
  }
  fprintf(handler, "/* Prototypes for functions used in event handler */\n");

  if(backdoor) {
    if(!multitools) {
      fprintf(handler, "%s%s_backdoor_handler(%s);\n",
	      termptr, the_tool_name, termptr);
      fprintf(handler, "%s%s_backdoor_check_in_sign(%s);\n", 
	      termptr, the_tool_name, termptr);
    } else {
      fprintf(handler, "%s%s_backdoor_handler(int cid, %s);\n", 
	      termptr, the_tool_name, termptr);
      fprintf(handler, "%s%s_backdoor_check_in_sign(int cid, %s);\n", 
	      termptr, the_tool_name, termptr);
    }
  }
}

/*}}}  */

/* Read the tool interfaces file and generate parts of the
 * tif code.
 */

/*{{{  void read_tifs(int tifs, char *the_tool_name) */

void read_tifs(int tifs, char *the_tool_name)
{
  char *els = "\t";
  int nelements = 0;
  char pat[128];
  term *t;

  /* construct match pattern, e.g. ``%f(<calc>,%l)'' */
  sprintf(pat, "%%f(<%s>, %%l)", the_tool_name);

  while((t = TBread(tifs, TBtrue)) && !TBmatch(t, "end-of-tifs")){
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

  if(backdoor) {
    if(!multitools)
      fprintf(tmp1, " %s {\n\t\treturn %s_backdoor_handler(e);\n\t}", 
	      els, the_tool_name);
    else
      fprintf(tmp1, " %s {\n\t\treturn %s_backdoor_handler(cid, e);\n\t}", 
	      els, the_tool_name);
  } else {
    fprintf(tmp1, " %s {\n\t\t%s(stderr, \"Ignored: %%t\\n\", " \
	    "e);\n\t\treturn NULL;\n\t}", els, Tprintf);
  }
  fprintf(tmp1, "\n}\n");
  fclose(tmp1);
  fclose(tmp2);
}

/*}}}  */

/* Generate the event handler:
 * - generate the function header
 * - generate variable declarations
 * - copy the body from file tmp
 */

/*{{{  void gen_handler(char *the_tool_name, char *tmp) */

void gen_handler(char *the_tool_name, char *tmp)
{
  fprintf(c_handler, "\n/* Event handler for tool: %s */\n\n", the_tool_name);
  fprintf(c_handler, termptr);
  C_fun_name(the_tool_name, c_handler);

  if( split_output == TBtrue )
  {
    fprintf(h_handler, "\n/* Event handler for tool: %s */\n\n", the_tool_name);
    fprintf(h_handler, termptr);
    C_fun_name(the_tool_name, h_handler);
  }

  if(!multitools)
  {
    fprintf(c_handler, "_handler(%se){\n", termptr);
    if( split_output == TBtrue )
      fprintf(h_handler, "_handler(%se);\n", termptr);
  }
  else
  {
    fprintf(c_handler, "_handler(int cid, %se){\n", termptr);
    if( split_output == TBtrue )
      fprintf(h_handler, "_handler(int cid, %se);\n", termptr);
  }
  gen_var_decls(c_handler);

  copy_file(tmp, c_handler);
  unlink(tmp); 
}

/*}}}  */

/*{{{  void gen_test_in_sign(char *the_tool_name, char *tmp) */

void gen_test_in_sign(char *the_tool_name, char *tmp)
{
  char *header = "\n\
    /* Check input signature for tool: %s\n\
     * returns: NULL (requested input signature is subset of tool's input signature);\n\
    *          non-null term: first element not in tool's input signature.\n\
     * NOTE:    In the signature all terms have as first argument <%s>, but this\n\
    *          does NOT appear in the actual terms that will be sent to the tool.\n\
    */\n\n";

    fprintf(c_handler, header, the_tool_name, the_tool_name);

  /* generate the function header */
  fprintf(c_handler, termptr);
  C_fun_name(the_tool_name, c_handler);

  /* Idem. but now for optional .h file */
  if( split_output == TBtrue )
  {
    fprintf(h_handler, header, the_tool_name, the_tool_name);
    fprintf(h_handler, termptr );
    C_fun_name(the_tool_name, h_handler);
  }

  if(!multitools)
  {
    fprintf(c_handler, "_check_in_sign(%sreqs){\n", termptr);
    if( split_output == TBtrue )
      fprintf(h_handler, "_check_in_sign(%sreqs);\n", termptr);
  }
  else
  {
    fprintf(c_handler, "_check_in_sign(int cid, %sreqs){\n", termptr);
    if( split_output == TBtrue )
      fprintf(h_handler, "_check_in_sign(int cid, %sreqs);\n", termptr);
  }
  fprintf(c_handler, "\tchar *in_sign[%d];\n\tint i;\n\n", n_in_sign_test);
  copy_file(tmp, c_handler);
  unlink(tmp);

  /* generate the for loop */
  if(!is_empty)
    fprintf(c_handler, "\n\tfor( ; reqs; reqs=%s(reqs)) {\n", nextel);
  else
    fprintf(c_handler, "\n\tfor( ; %s(reqs); reqs=%s(reqs)) {\n", is_empty, nextel);
  fprintf(c_handler, "\t  for(i=0; i<%d; i++) {\n", n_in_sign_test);
  fprintf(c_handler, "\t    if(%s(%s(reqs), in_sign[i])) goto found;\n", TmatchSimple, firstel);
  fprintf(c_handler, "\t  }\n");
  fprintf(c_handler, "\t  return %s(reqs);\n", firstel);
  fprintf(c_handler, "\t  found:;\n");
  if(backdoor) {
    if(multitools) {
      fprintf(c_handler, "\t  return %s_backdoor_check_in_sign(cid, %s(reqs));\n", the_tool_name, firstel);
    } else {
      fprintf(c_handler, "\t  return %s_backdoor_check_in_sign(%s(reqs));\n", the_tool_name, firstel);
    }
  }
  fprintf(c_handler, "\t}\n");
  fprintf(c_handler, "\treturn NULL;\n");
  fprintf(c_handler, "}\n");
}

/*}}}  */

/* ------------- usage and help functions --------------------------------*/

char * Usage = "ctif [-h][elp] -tool ToolName -tifs ToolInterfaces";

/*{{{  void help(void) */

void help(void)
{
  char * str =
    "\n\
    CTIF -- AUTOMATIC C GENERATOR FOR TOOLBUS INTERFACES\n\
    ====================================================\n\
    ctif generates C interface code for connecting tools with the ToolBus\n\
    Options are:\n\
    -h/-help              prints this message\n\
    -tool ToolName        name of the tool as used in the ToolBus script\n\
    -tifs ToolInterfaces  interfaces files as generated by the ToolBus, e.g.\n\
    toolbus -gentifs my_script.tb\n\
    will generate the file my_script.tifs\n\
    -multi                generate multi-tool ready C code including cid refs.\n\
    -newstyle             generate new style handlers, i.e. aterm * and Tmatch\n\
    -backdoor             generate a backdoor in situations where not all\n\
    functions are known\n\
    -split                write function declarations to .h and function \n\
    definitions to .c file\n\
    \n\
    The generated tool interface is always written to a file named ToolName.tif.c\n\
    For example ``calc.tif.c'' when the tool name is ``calc''. When the -split\n\
    command line option is specified function declarations and functions definitions\n\
    are separated in ToolName.tif.h and ToolName.tif.c\n";

  fprintf(stderr, str);
}

/*}}}  */

/* ctif -- main program */

/*{{{  int main(int argc, char **argv) */

int main(int argc, char **argv)
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
    } else if(streq(argv[i], "-multi")) {
      multitools = TBtrue;
    } else if(streq(argv[i], "-backdoor")) {
      backdoor = TBtrue;
    } else if(streq(argv[i], "-newstyle")) {
      termptr = "aterm *";
      Tmatch   = "Tmatch";
      TmatchSimple = "TmatchSimple";
      Tprintf = "Tprintf";
      firstel   = "t_list_first";
      nextel    = "t_list_next";
      header_file  = "aterm.h";
      placeholders = TBtrue;
      is_empty = "t_is_empty";
      multitools = TBtrue;
    } else if(streq(argv[i], "-header")) {
      header_file = argv[++i];
      if(streq(header_file, "-"))
	header_file = NULL;
    } else if(streq(argv[i], "-help") || streq(argv[i], "-h")) {
      help();
      exit(0);
    } else if(streq(argv[i], "-split")){
      split_output = TBtrue;
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
  c_handler = fopen(handler_name, "wb");
  if(!c_handler)
    err_sys_fatal("Can't create `%s'", handler_name);

  if( split_output == TBtrue )
  {
    sprintf(handler_name, "%s.tif.h", search_tool_name);
    h_handler = fopen(handler_name, "wb");
    if(!h_handler)
      err_sys_fatal("Can't create `%s'", handler_name);
  }

  tmp1 = fopen(tmp_name1, "wb");
  if(!tmp1)
    err_sys_fatal("Can't create tmp file `%s'", tmp_name1);

  tmp2 = fopen(tmp_name2, "wb");
  if(!tmp2)
    err_sys_fatal("Can't create tmp file `%s'", tmp_name2);

  gen_header(search_tool_name);

  read_tifs(tifs, search_tool_name);

  gen_handler(search_tool_name, tmp_name1);

  gen_test_in_sign(search_tool_name, tmp_name2);

  fclose(c_handler);
  close(tifs);

  if( split_output == TBtrue )
  {
    fprintf( h_handler, "#endif\n" );
    fclose(h_handler);
  }
  return 0;
} 

/*}}}  */
