/*

    SGLR - the Scannerless Generalized LR parser.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, 
                         The Netherlands.

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
/*
 * $Id$
 */

#include <stdio.h>
#include <aterm1.h>
#include <aterm2.h>
#include <stdlib.h>
#include <unistd.h>
#include <AsFix.h>
#include <AsFix-access.h>
#include <AsFix2src.h>
#include <deprecated.h>

static char myname[]    = "apply-function";
static char myversion[] = "1.1";
static char myarguments[] = "qf:s:m:bhi:o:tVd";
static ATbool debug = ATfalse;


#define asfix_get_prod_sort(p) AFgetProdSymbol(p)

ATerm ApplyFunction(ATerm term, char *function, char *module, char *sort, 
		    ATbool quoted)
{
   ATerm real;
   ATerm real_prod;
   ATerm real_sort;
   ATerm new_prod;
   ATerm new_module;
   ATermList new_prod_symbols; 
   ATerm ws, open, close, noattrs, arrow;
   ATerm openlit, closelit;
   ATerm new_function_symbol;
   ATerm new_function_term;
   ATermList new_appl_args;
   ATerm new_term;
   ATerm new_sort;
   ATerm new_appl;

   if(!quoted) {
      ATerror("%s: non quoted prefix functions not yet supported.\n",
              myname);
      return term;
   }

   /* destructing the input term */
   real = asfix_get_term(term);
   real_prod = asfix_get_appl_prod(real);
   real_sort = asfix_get_prod_sort(real_prod);
   
   /* standard terms */
   ws = ATparse("w(\"\")");
   open = ATparse("ql(\"(\")");
   openlit = ATparse("l(\"(\")");
   close = ATparse("ql(\")\")");
   closelit = ATparse("l(\")\")");
   noattrs = ATparse("no-attrs");
   arrow  = ATparse("l(\"->\")");

   /* creating the new outermost prod */
   new_module = ATmake("id(<str>)", module);
   new_sort   = ATmake("sort(<str>)", sort);
   new_function_symbol = ATmake("ql(<str>)", function);
   new_prod_symbols = ATmakeList(7, new_function_symbol, ws, open, ws,
                                    real_sort, ws, close);
   new_prod = ATmake("prod(<term>,<term>,[<list>],<term>,<term>,<term>,"
		     "<term>,<term>,<term>)", new_module, ws, new_prod_symbols,
		     ws, arrow, ws, new_sort, ws, noattrs); 
   
   /* creating the new outermost term */
   new_function_term = ATmake("l(<str>)", function);
   new_appl_args = ATmakeList(7, new_function_term, ws, openlit, ws, real, ws,
                                 closelit);
   new_appl = ATmake("appl(<term>, <term>, [<list>])", 
		     new_prod, ws, new_appl_args);

   /* put the new appl in the old term wrapper */
   new_term = asfix_put_term(term, new_appl);

   return new_term;
}

/*
    Usage: displays helpful usage information
 */
void usage(void)
{
    fprintf(stderr,
	"\nApply-function encapsulates AsFix1 terms with a quoted or unquoted prefix function.\n\n"
        "Usage: apply-function -qdbh -f <name> -s <sort> -m <modulename>\n"
        "                      -i <file> -o <file> -tV . . .\n"
        "Options:\n"
        "\t-q              unquoted prefix notation\n"
        "\t-b              binary output mode (default)\n"
        "\t-h              display help information (usage)\n"
	"\t-f name         name of prefix function\n"
	"\t-s sort         result sort of function\n"
	"\t-m module       module where function is defined\n"
        "\t-i filename     input from file (default stdin)\n"
        "\t-o filename     output to file (default stdout)\n"
        "\t-t              text output mode\n"
	"\t-d              debug mode\n"
        "\t-V              reveal program version (i.e. %s)\n",
        myversion);
}

int main (int argc, char **argv)
{
  int c; /* option character */
  ATerm bottomOfStack;
  ATerm t;
  ATbool txtout = ATfalse;
  char  *ATlibArgv[] = { "", "-silent"};
  char   *input_file_name  = "-";
  char   *output_file_name = "-";
  char *function = "";
  char *sort = "";
  char *module = "";
  ATbool quoted = ATtrue;
 
  if(argc == 1) { /* no arguments */
    usage();
    exit(1);
  }

  while ((c = getopt(argc, argv, myarguments)) != EOF)
    switch (c) {
    case 'q':  quoted = ATfalse;              break;    
    case 'h':  usage();                      exit(0);
    case 'i':  input_file_name  = optarg;    break;
    case 'o':  output_file_name = optarg;    break;
    case 'f':  function = optarg;            break;  
    case 's':  sort = optarg;                break;
    case 'm':  module = optarg;              break;
    case 'b':  txtout = ATfalse;             break;
    case 't':  txtout = ATtrue;              break;
    case 'd':  debug = ATtrue;               break;
    case 'V':  fprintf(stdout, "%s %s\n", myname, myversion);
      exit(0);
    default :  usage();                      exit(1);
    }
 
  ATinit(2, ATlibArgv, &bottomOfStack);    /* Initialize Aterm library */
  
  t = ATreadFromNamedFile(input_file_name);
  if(!t) {
    ATerror("%s: could not read term from input file %s\n", myname, input_file_name);
  }

  if(!function || !strcmp(function, "") || 
     !sort || !strcmp(sort,"") ||
     !module || !strcmp(module,"")) {
    usage();
    exit(1);
  } else {
    t = ApplyFunction(t, function, module, sort, quoted);
  }

  if(txtout) {
    ATwriteToNamedTextFile(t, output_file_name);
  } else {
    ATwriteToNamedBinaryFile(t, output_file_name);
  }

  return 0;
}
