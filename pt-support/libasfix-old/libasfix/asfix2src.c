/*

    AsFix -- The AsFix (ASF+SDF Prefix) library
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

   $Id$
*/
#include "AsFix.h"
#include "AsFix2src.h"
#include "aterm-macs.h"
#include "AsFix-fun.h"

/*
Calculate the length of the source represented by an asfix term.
*/

int calc_size(char *fname, int pos, ATerm t);

int AFsourceSize(ATerm asfix)
{
  int pos, size = 0;
  ATerm arg;

  if(t_is_appl(asfix)) {
    ATermAppl appl = (ATermAppl)asfix;
    Symbol sym = ATgetSymbol(appl);
    int arity = ATgetArity(sym);
    char *fname = ATgetName(sym);
		switch(arity) {
			case 0:      return strlen(fname);
			case 1:
				/* Singe argument might be a quoted string */
				arg = ATgetArgument(appl, 0);
				if(t_is_appl(arg)) {
					Symbol argsym = ATgetSymbol((ATermAppl) arg);
					if(ATgetArity(argsym) == 0 && ATisQuoted(argsym)) {
						if(asfix_str_eq(fname, "ql"))
							return 2+strlen(ATgetName(argsym));
						else
							return strlen(ATgetName(argsym));
					}
				}
    }
		/* More than one argument, or argument is not a quoted string */
		for(pos=0; pos<arity; pos++)
      size += calc_size(fname, pos, ATgetArgument(appl, pos));
  } else if(t_is_asfix_list(asfix)) {
    while(!ATisEmpty((ATermList) asfix)) {
      size += AFsourceSize(ATgetFirst((ATermList) asfix));
      asfix = (ATerm) ATgetNext((ATermList) asfix);
    }    
  } else if(t_is_asfix_int(asfix)) {
    size = 1;
  } else ATerror("illegal asfix: %t", asfix);
  return size;
}

/*
Calculate the length of an application.
*/

int calc_size(char *fname, int pos, ATerm t)
{
  switch(fname[0]) {
    case 'a': if(asfix_str_eq(fname, "appl") && pos == p_appl_prod)
		return 0;
	      break;

    case 'c': if((asfix_str_eq(fname, "ceq-equ")  && pos == p_ceq_equ_module_name) ||
                 (asfix_str_eq(fname, "ceq-when") && pos == p_ceq_when_module_name) ||
                 (asfix_str_eq(fname, "ceq-impl") && pos == p_ceq_when_module_name))
		return 0;
	      break;

    case 'l': if((asfix_str_eq(fname, "lex") && pos == p_lex_sym) ||
	         (asfix_str_eq(fname, "list")     && pos == p_list_sym))
	        return 0;
	      break;

    case 'p': if((asfix_str_eq(fname, "prod") && (pos == p_prod_module_name ||
                 (pos == p_prod_attrs && ATmatch(t, "no-attrs")))) ||
                 (asfix_str_eq(fname, "prod-skel")&& pos == p_prod_skel_prod) ||
                 (asfix_str_eq(fname, "parsetree") && 
                  pos == p_parsetree_amb_cnt))
	        return 0;
	      break;

    case 'm': if((asfix_str_eq(fname, "meta-var") && pos == p_meta_var_sym) ||
     		 (asfix_str_eq(fname, "module")   && (pos == p_module_abbrevs ||
                 (pos = p_module_equations && ATmatch(t, "no-equations")))))
	        return 0;
	      break;

    case 't': if((asfix_str_eq(fname, "term") && (pos == p_term_abbrevs ||
		  pos == p_term_w1 || pos == p_term_w2 || 
		  pos == p_term_name || pos == p_term_filename ||
		  pos == p_term_id )))
		return 0;
	      break;

    case 'v': if((asfix_str_eq(fname, "var") && pos == p_var_sym))
	        return 0;
	      break;
  }
  return AFsourceSize(t);
}

/*
Build the source text represented by an asfix term/module.
*/

static char *build_source(ATerm asfix, char *buf);

int AFsource(ATerm asfix, char *buf)
{
  char *result = build_source(asfix, buf);
  *result++ = '\0';
  return result-buf-1;
}

/*
Generate source representation in a newly allocated buffer.
*/

char *AFsourceToBuf(ATerm asfix)
{
  int size2, size = AFsourceSize(asfix);
  char *buf = (char *)malloc(size+1);
  if(!buf)
    ATerror("out of memory in AFsourceToBuf");
  size2 = AFsource(asfix, buf);
  if(size2 != size)
    ATerror("sizes don't match: %d != %d in AFsourceToBuf", size, size2);
  return buf;
}

void AFsourceToFile(ATerm asfix, FILE *file)
{
  static char *buf = NULL;
  static int bufsize = -1;

  int size2, size = AFsourceSize(asfix);

  if(size > bufsize) {
    if(buf)
      free(buf);
    buf = (char *)malloc(size+1);
    if(!buf)
      ATerror("out of memory in AFsourceToBuf");
    bufsize = size;
  }
  size2 = AFsource(asfix, buf);
  if(size2 != size)
    ATerror("sizes don't match: %d != %d in AFsourceToFile", size, size2);

  fwrite(buf, 1, size, file);
}

char *treat_appl_arg(char *fname, int pos, ATerm t, char *buf);

static char *build_source(ATerm asfix, char *buf)
{
  int pos;
	ATerm arg;

  if(t_is_appl(asfix)) {
    ATermAppl appl = (ATermAppl)asfix;
    Symbol sym = ATgetSymbol((ATermAppl) asfix);
    int arity = ATgetArity(sym);
    char *fname = ATgetName(sym);
    switch(arity) {
    	case 0:
    		strcpy(buf, fname);
    		buf += strlen(buf);
    		return buf;
    	case 1:
    		arg = ATgetArgument(appl, 0);
    	if(t_is_appl(arg)) {
    			Symbol argsym = ATgetSymbol((ATermAppl) arg);
					if(ATgetArity(argsym) == 0 && ATisQuoted(argsym)) {
						if(asfix_str_eq(fname, "ql")) {
							*buf++ = '"';
							strcpy(buf, ATgetName(argsym));
							buf += strlen(buf);
							*buf++ = '"';
							return buf;
						} else {
							strcpy(buf, ATgetName(argsym));
							buf += strlen(buf);
							return buf;
						}
					}
				}
    }
		/* More than one argument, or single argument was not a quoted string */
		for(pos=0; pos<arity; pos++) 
			buf = treat_appl_arg(fname, pos, ATgetArgument(appl, pos), buf);
  } else if(t_is_asfix_list(asfix)) {
    while(!ATisEmpty((ATermList) asfix)) {
      buf = build_source(ATgetFirst((ATermList) asfix), buf);
      asfix = (ATerm) ATgetNext((ATermList) asfix);
    }
  } else if(t_is_asfix_int(asfix)) {
    *buf++ = ATgetInt((ATermInt) asfix);
  } else ATerror("illegal asfix: %t", asfix);
  return buf;
}

/*
Treat an argument of an application depending on the position it takes in the
original asfix application.
*/

char *treat_appl_arg(char *fname, int pos, ATerm t, char *buf)
{
  switch(fname[0]) {
    case 'a': if(asfix_str_eq(fname, "appl") && pos == p_appl_prod)
		return buf;
	      break;

    case 'c': if((asfix_str_eq(fname, "ceq-equ")  && pos == p_ceq_equ_module_name) ||
                 (asfix_str_eq(fname, "ceq-when") && pos == p_ceq_when_module_name) ||
                 (asfix_str_eq(fname, "ceq-impl") && pos == p_ceq_when_module_name))
		return buf;
	      break;

    case 'l': if((asfix_str_eq(fname, "lex") && pos == p_lex_sym) ||
	         (asfix_str_eq(fname, "list")     && pos == p_list_sym))
	        return buf;
	      break;

    case 'p': if((asfix_str_eq(fname, "prod") && (pos == p_prod_module_name ||
                 (pos == p_prod_attrs && ATmatch(t, "no-attrs")))) ||
                 (asfix_str_eq(fname, "prod-skel") && 
                  pos == p_prod_skel_prod) ||
                 (asfix_str_eq(fname, "parsetree") && 
                  pos == p_parsetree_amb_cnt))
	        return buf;
	      break;

    case 'm': if((asfix_str_eq(fname, "meta-var") && pos == p_meta_var_sym) ||
     		 (asfix_str_eq(fname, "module")   && (pos == p_module_abbrevs ||
                 (pos = p_module_equations && ATmatch(t, "no-equations")))))
	        return buf;
	      break;

    case 't': if((asfix_str_eq(fname, "term") && (pos == p_term_abbrevs ||
		  pos == p_term_w1 || pos == p_term_w2 || 
		  pos == p_term_name || pos == p_term_filename ||
		  pos == p_term_id )))
		return buf;
	      break;

    case 'v': if((asfix_str_eq(fname, "var") && pos == p_var_sym))
	        return buf;
	      break;
  }
  return build_source(t, buf);
}
