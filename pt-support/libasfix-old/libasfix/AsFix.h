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
#ifndef _ASFIX_H
#define _ASFIX_H

/* 
\section{asfix library}

On top of the basic ATerm library, we have build the asfix
library. 
*/

#include "aterm1.h"
#include "aterm2.h"
#include "AsFix-abbrevs.h"

/* function proto types */

/* Initialize the asfix library. Memorize some symbols and patterns. */
void AFinitialize(int argc, char *argv[]);
void AFinit(int argc, char *argv[], ATerm *bottomOfStack);

/* Test for a layout term. */
ATbool AFisLayout(ATerm t);
ATbool AFnotLayout(ATerm t);

/* Check if t is a literal */
ATbool AFisLiteral(ATerm t);

/* Check if tag is a default tag. */
ATbool AFisDefaultTag(ATerm tag);

/* Check if an equation is a default equation. */
ATbool AFisDefaultEquation(ATerm equation);

/* Check if an AsFix term contains variables. */
ATbool AFcontainsVars(ATermList l);

/*Check if a context-free function is a bracket function. */
ATbool AFisBracketCfFunc(ATerm prod);

/* Check whether the function of an AsFix application is a bracket function. */
ATbool AFisBracketAppl(ATerm appl);

/* Some access macros need some help, otherwise they get to long. */

/* return LHS of equ */
ATerm AFgetEquLhs(ATerm equ);

/* return RHS of equ */
ATerm AFgetEquRhs(ATerm equ);

ATerm AFgetEquConds(ATerm equ);
ATerm AFputEquConds(ATerm equ, ATermList conds);
ATerm AFgetModuleEqs(ATerm mod);
ATerm AFputModuleEqs(ATerm mod, ATermList eqs);
ATermList AFgetModuleSections(ATerm mod);
ATerm AFputModuleSections(ATerm mod, ATermList sections);
ATerm AFgetModuleName(ATerm mod);
ATerm AFputModuleName(ATerm mod, ATerm mname);
ATermList AFgetModuleCFfuncs(ATerm mod);
ATermList AFgetModuleSorts(ATerm mod);
ATermList AFgetModuleLexfuncs(ATerm mod);
ATerm AFputSectionArgs(ATerm section, ATermList secargs);
ATerm AFinitModule();
ATerm AFinitExportSection();
ATerm AFinitContextFreeSyntaxSection();
ATerm AFinitLexicalSyntaxSection();
ATerm AFgetProdSort(ATerm prod);
ATerm AFmakeProd(ATerm mname, ATermList args, ATerm sort, ATerm attrs);
ATerm AFmakeAppl(ATerm prod,ATermList args);
ATerm AFmakeLex(char *sym, ATerm sort);
ATerm make_caller_prod(ATerm sort);
ATerm make_term_caller_prod(ATerm sort);

void init_expansion_terms();
int is_sep(ATerm sep);

ATerm make_literal_to_afun_appl(ATerm arg);
ATerm make_afun_to_aterm_appl(ATerm arg);
ATerm make_aterm_to_aterms_appl(ATerm arg);
ATerm make_afun_aterms_to_aterm_appl(ATerm fun,ATerm arg);
ATerm make_aterm_aterms_to_aterms_appl(ATerm term, ATerm terms);
ATerm make_atermlist_to_aterm_appl(ATerm arg);
ATerm make_aterms_to_atermlist_appl(ATerm args);
ATerm make_empty_abbreviations();
ATerm expand_asfix_ws(ATerm ws);
ATerm expand_asfix_literal(ATerm l);
ATerm expand_asfix_qliteral(ATerm ql);
ATerm expand_asfix_sep(ATerm s);
ATerm expand_asfix_iter(ATerm iter);
ATerm expand_asfix_itersep(ATerm itersep);
ATerm expand_asfix_neg(ATerm neg);
ATerm expand_asfix_charclass(ATerm cc);
ATerm expand_asfix_id(ATerm id);
ATerm expand_asfix_ids(ATermList ids);
ATerm expand_asfix_idlist(ATerm idlist);
ATerm expand_asfix_attrs(ATermList attrs);
ATerm expand_asfix_attributes(ATerm attrlist);
ATerm expand_asfix_appl(ATerm appl);
ATerm expand_asfix_list(ATerm list);
ATerm expand_asfix_var(ATerm var);
ATerm expand_asfix_lex(ATerm lex);
ATerm expand_asfix_term(ATerm term);
ATerm expand_asfix_args(ATermList args);
ATerm expand_asfix_argslist(ATerm arglist);
ATerm expand_asfix_prodskel(ATerm prodskel);
ATerm expand_asfix_prodskels(ATermList prodskels);
ATerm expand_asfix_prodskellist(ATerm prodskellist);
ATerm expand_asfix_chain(ATerm chain);
ATerm expand_asfix_chains(ATermList chains);
ATerm expand_asfix_chainlist(ATerm chainlist);
ATerm expand_asfix_prio(ATerm prio);
ATerm expand_asfix_prios(ATermList prios);
ATerm expand_asfix_prioslist(ATerm priolist);
ATerm expand_asfix_sort(ATerm sort);
ATerm expand_asfix_sorts(ATermList sorts);
ATerm expand_asfix_sortlist(ATerm sortlist);
ATerm expand_asfix_prod(ATerm prod);
ATerm expand_asfix_prods(ATermList prods);
ATerm expand_asfix_prodlist(ATerm prodlist);
ATerm expand_asfix_subsection(ATerm subsection);
ATerm expand_asfix_subsections(ATermList subsections);
ATerm expand_asfix_subsectionlist(ATerm subsectionlist);
ATerm expand_asfix_section(ATerm section);
ATerm expand_asfix_sections(ATermList sections);
ATerm expand_asfix_sectionlist(ATerm sectionlist);
ATerm expand_asfix_cond(ATerm cond);
ATerm expand_asfix_conds(ATermList conds);
ATerm expand_asfix_condslist(ATerm condslist);
ATerm expand_asfix_equation(ATerm equation);
ATerm expand_asfix_equations(ATermList equations);
ATerm expand_asfix_equationlist(ATerm equationlist);
ATerm expand_asfix_equationssection(ATerm equations);
ATerm expand_asfix_module(ATerm mod);
ATerm make_term(char *name, char* module_name, ATerm mod);


int AFsourceSize(ATerm asfix);
int calc_size(char *fname, int pos, ATerm t);

/* Generate source representation in a newly allocated buffer. */
char *AFsourceToBuf(ATerm asfix);
void AFsourceToFile(ATerm asfix, FILE *file);

/* Annotate AsFix module with positional information */
ATerm AFaddPosInfoToModule(char *path, ATerm module);

/* Treat an argument of an application depending on the position it takes in
 * the original asfix application. 
 */ 
char *treat_appl_arg(char *fname, int pos, ATerm t, char *buf);

ATerm expand_generic(ATerm t, ATermList abbrevs);
ATermList expand_generic_list(ATermList l, ATermList abbrevs);
ATermList expand_args(ATermList args, ATermList abbrevs);
ATermList expand_elems(ATerm sym, ATermList elems, ATermList abbrevs);
ATerm expand_appl(ATerm appl, ATermList abbrevs);
ATermList expand_conds(ATermList conds, ATermList abbrevs);
ATerm expand_equation(ATerm equ, ATermList abbrevs);
ATerm AFexpandEqs(ATerm equations, ATermList abbrevs);
ATermList AFexpandSyntax(ATermList sections, ATermList abbrevs);
ATerm AFexpandModule(ATerm module);
ATerm AFexpandTerm(ATerm term);
ATerm lookup_aprod(ATerm prod, ATermList *abbrevs);
ATerm collapse_generic(ATerm t, ATermList *abbrevs);
ATermList collapse_generic_list(ATermList l, ATermList *abbrevs);
ATermList collapse_args(ATermList args, ATermList *abbrevs);
ATermList collapse_elems(ATerm sym, ATermList elems, ATermList *abbrevs);
ATerm collapse_appl(ATerm appl, ATermList *abbrevs);
ATermList collapse_conds(ATermList conds, ATermList *abbrevs);
ATerm collapse_equation(ATerm equ, ATermList *abbrevs);
ATerm AFcollapseEqs(ATerm equations, ATermList *abbrevs);
ATermList AFcollapseSyntax(ATermList sections, ATermList *abbrevs);
ATerm AFcollapseModule(ATerm module);
ATerm AFcollapseTerm(ATerm term);




/* Some often used symbols are exported to avoid multiple lookups. */

extern Symbol symbol_w;
extern Symbol symbol_l;
extern Symbol symbol_ceq_equ;
extern Symbol symbol_ceq_when;
extern Symbol symbol_ceq_impl;
extern Symbol symbol_term;
extern Symbol symbol_asfix_appl;
extern Symbol symbol_asfix_term;
extern Symbol symbol_prod;
extern Symbol symbol_appl;
extern Symbol symbol_term;
extern Symbol symbol_lex;
extern Symbol symbol_asfix_list;
extern Symbol symbol_iter_sep;
extern Symbol symbol_iter;
extern Symbol symbol_asfix_var;
extern Symbol symbol_sep;

/* Store some often used term patterns. */

extern ATerm pattern_appl;
extern ATerm pattern_prod;
extern ATerm pattern_aprod;
extern ATerm pattern_attrs;
extern ATerm pattern_attr;
extern ATerm pattern_lex;
extern ATerm pattern_list;
extern ATerm pattern_list_w;
extern ATerm pattern_itersep;
extern ATerm pattern_iter;
extern ATerm pattern_var;
extern ATerm pattern_whitespace;
extern ATerm pattern_empty_ws;
extern ATerm pattern_literal;
extern ATerm pattern_sep;
extern ATerm pattern_ceq_equ;
extern ATerm pattern_ceq_impl;
extern ATerm pattern_ceq_when;
extern ATerm pattern_iter_plus;
extern ATerm pattern_itersep_plus;
extern ATerm pattern_iter_star;
extern ATerm pattern_itersep_star;
extern ATerm pattern_lex_constructor;
extern ATerm pattern_equality_cond;
extern ATerm pattern_cond;
extern ATerm pattern_ceq_equ;
extern ATerm pattern_ceq_impl;
extern ATerm pattern_ceq_when;
extern ATerm pattern_fun_str;
extern ATerm pattern_asfix_lex_cons;

/* 
\subsection{Initialization}

\Function{AFinit}{void }{}{Initialize the AsFix library.}

This function should be called \emph{after} calling {\tt Tinit}.
*/

void AFinit();

/*
\subsection{AsFix predicates}

\Macro{asfix\_is\_layout}{ATbool }{ATerm }{Check if an AsFix term is layout.}
*/

#define asfix_is_layout(t)	(AFisLayout(t))

#if 0
Please notify Mark or Pieter if you still use these defines!
#define asfix_is_default_tag(t)	(AFisDefaultTag(t))
#define asfix_is_default_equ(t)	(AFisDefaultEquation(t))
#endif

/*
\Macro{asfix\_is\_appl}{ATbool }{ATerm }{Check if an AsFix term is an
application.}
*/

#define asfix_is_appl(t)	(ATgetSymbol((ATermAppl) t) == symbol_asfix_appl)

#define asfix_is_term(t)	(ATgetSymbol((ATermAppl) t) == symbol_term)
/*
\Macro{asfix\_is\_lex}{ATbool }{ATerm }{Check if an AsFix term is 
a lexical.}
*/

#define asfix_is_lex(t)		(ATgetSymbol((ATermAppl) t) == symbol_lex)
#define asfix_is_literal(t)	(ATgetSymbol((ATermAppl) t) == symbol_l)


/*
\Macro{asfix\_is\_list}{ATbool }{ATerm }{Check if an AsFix term is a list.}
*/

#define asfix_is_list(t)	(ATgetSymbol((ATermAppl) t) == symbol_asfix_list)
#define asfix_is_sep(t)	(ATgetSymbol((ATermAppl) t) == symbol_sep)

/*
\Macro{asfix\_is\_itersep}{ATbool }{ATerm }{Check if an AsFix term is an
seperated iterator.}
*/

#define asfix_is_itersep(t)	(ATgetSymbol((ATermAppl) t) == symbol_iter_sep)

/*
\Macro{asfix\_is\_iter}{ATbool }{ATerm }{Check if an AsFix term is a
non-separated iterator.}
*/

#define asfix_is_iter(t)	(ATgetSymbol((ATermAppl) t) == symbol_iter)

/*
\Macro{asfix\_is\_var}{ATbool }{ATerm }{Check if an AsFix term is a variable.}
*/

#define asfix_is_var(t)		(ATgetSymbol((ATermAppl) t) == symbol_asfix_var)

/*
\Macro{asfix\_is\_plus\_var}{ATbool }{ATerm }{Check if an AsFix term is 
a plus variable.}
*/

#define asfix_is_plus_var(t)	(asfix_is_var(t) && \
	asfix_is_plus_list(ATgetArgument((ATermAppl)t, 1)))

/*
\Macro{asfix\_is\_star\_var}{ATbool }{ATerm }{Check if an AsFix term is 
a star variable.}
*/

#define asfix_is_star_var(t)	(asfix_is_var(t) && \
	asfix_is_star_list(ATgetArgument((ATermAppl)t, 1)))

/*
\Macro{asfix\_is\_list\_var}{ATbool }{ATerm }{Check if an AsFix term is 
a list variable.}
*/

#define asfix_is_list_var(t)	(asfix_is_var(t) && \
	(asfix_is_itersep(ATgetArgument((ATermAppl)t, 1)) || \
	 asfix_is_iter(ATgetArgument((ATermAppl)t, 1))))

/*
\Macro{asfix\_is\_whitespace}{ATbool }{ATerm }{Check if an AsFix term 
represents whitespace.}
*/

#define asfix_is_whitespace(t)	(ATgetSymbol((ATermAppl) t) == symbol_w)

/*
\Macro{asfix\_is\_literal}{ATbool }{ATerm }{Check if an AsFix term 
represents whitespace.}
*/

#define asfix_is_literal(t)	(ATgetSymbol((ATermAppl) t) == symbol_l)

/*
\Macro{asfix\_is\_list\_sep}{ATbool }{ATerm }{Check if an AsFix term is 
a list separator.}
*/

#define asfix_is_list_sep(t)	(ATgetSymbol((ATermAppl) t) == symbol_sep)

#define asfix_is_sep(t)		(ATgetSymbol((ATermAppl) t) == symbol_sep)

/*
\Macro{asfix\_is\_ceq\_equ}{ATbool }{ATerm }{Check if an AsFix term
is a non-conditional equation.}
*/

#define asfix_is_ceq_equ(t)	(ATgetType(t) == AT_APPL && ATgetSymbol((ATermAppl) t)==symbol_ceq_equ)

/*
\Macro{asfix\_is\_ceq\_impl}{ATbool }{ATerm }{Check if an AsFix term is 
a 'implies' condition equation.}
*/

#define asfix_is_ceq_impl(t)	(ATgetType(t) == AT_APPL && ATgetSymbol((ATermAppl) t)==symbol_ceq_impl)

/*
\Macro{asfix\_is\_ceq\_when}{ATbool }{ATerm }{Check if an AsFix term is
a 'when' conditional equation.}
*/

#define asfix_is_ceq_when(t)	(ATgetType(t) == AT_APPL && ATgetSymbol((ATermAppl) t)==symbol_ceq_when)

/*
\Macro{asfix\_is\_equation}{ATbool }{ATerm }{Check if an AsFix term is
an equation.}
*/

#define asfix_is_equation(t)	(asfix_is_ceq_equ(t) || asfix_is_ceq_impl(t)\
					|| asfix_is_ceq_when(t))

/*
\Macro{asfix\_is\_plus\_list}{ATbool }{ATerm }{Check if an AsFix term is 
a plus list.}
*/

#define asfix_is_plus_list(t)	(ATmatchTerm(t, pattern_iter_plus,NULL,NULL) || \
                                 ATmatchTerm(t, pattern_itersep_plus, NULL, \
								NULL,NULL,NULL,NULL,NULL,NULL,NULL))

/*
\Macro{asfix\_is\_star\_list}{ATbool }{ATerm }{Check if an AsFix term is 
a star list.}
*/

#define asfix_is_star_list(t)	(ATmatchTerm(t, pattern_iter_star,NULL,NULL) || \
                                 ATmatchTerm(t, pattern_itersep_star,NULL,\
								 NULL,NULL,NULL,NULL,NULL,NULL,NULL))

/*
\Macro{asfix\_is\_closed\_appl}{ATbool }{ATerm }{Check if an AsFix term is 
a closed application.}
*/

#define asfix_is_closed_appl(t)	\
	(asfix_is_appl(t) ? AFcontainsVars(AFgetArgs(t)) : Tfalse)

/*
\Macro{asfix\_is\_lex\_constructor}{ATbool }{ATerm }{Check if an AsFix term 
is a lexical constructor.}
*/

#define asfix_is_lex_constructor(t) (ATmatchTerm(t, pattern_lex_constructor, NULL, NULL, NULL))

/*
\Macro{asfix\_is\_equality\_cond}{ATbool }{ATerm }{Check if an AsFix term
is an equality condition.}
*/

#define asfix_is_equality_cond(t) (ATmatchTerm(t, pattern_equality_cond, NULL, NULL, NULL, NULL))

/*
\Macro{asfix\_is\_bracket\_func}{ATbool }{ATerm }{Check if an AsFix term
is a bracket function.}
*/

#define asfix_is_bracket_func(t) (AFisBracketAppl(t))

/*
\Function{AFisLayout}{ATbool }{ATerm t}{Check if {\tt t} is of the
form {\tt w(<str>)}.}
*/

ATbool AFisLayout(ATerm t);

/*
\Function{AFnotLayout}{ATbool }{ATerm t}{Check if {\tt t} is not of the
form {\tt w(<str>)}.}
*/

ATbool AFnotLayout(ATerm t);

/*
\Function{AFisLiteral}{ATbool }{ATerm t}{Check if {\tt t} is of the
form {\tt l(<str>)}.}
*/

ATbool AFisLiteral(ATerm t);

/*
\Function{AFisDefaultTag}{ATbool }{ATerm tag}{Check if {\tt tag} is a
default tag.}
To be a default tag, the tag must have the form: {\tt l("[default-...]")}.
*/

ATbool AFisDefaultTag(ATerm tag);

/*
\Function{AFisDefaultEquation}{ATbool }{ATerm equation}{Check if 
{\tt equations} is a default equation.}
To be a default equation, {\tt equation} must have a tag 
of the following form: {\tt l("[default-...]")}.
*/

ATbool AFisDefaultEquation(ATerm equation);

/*
\Function{AFcontainsVars}{ATbool }{ATermList l}{Check if an AsFix term 
contains variables.}
*/

ATbool AFcontainsVars(ATermList l);

/*
\Function{AFisBracketCfFunc}{ATbool }{ATerm prod}{Check if {\tt prod} is a
bracket function.}
To be a bracket function, {\tt prod} must have {\tt l("bracket")}
in its attributes.
*/

ATbool AFisBracketCfFunc(ATerm prod);

/*
\Function{AFisBracketAppl}{ATbool }{ATerm appl}{Check if {\tt appl} contains a
bracket function.}
To be a bracket function, {\tt appl} must contain {\tt l("bracket")}
in its attributes.
*/

ATbool AFisBracketAppl(ATerm appl);

/*
\subsection{AsFix accessor macros and functions.}
\Macro{asfix\_get\_equ\_tag}{ATerm }{ATerm t}{Get the tag of an AsFix
equation.}
*/

#define asfix_get_equ_tag(t)	(ATgetArgument((ATermAppl)t, 2))

/*
\Macro{asfix\_get\_equ\_lhs}{ATerm }{ATerm t}{Get the left-hand-side of
an AsFix equation.}
*/

#define asfix_get_equ_lhs(t)	(AFgetEquLhs(t))

/*
\Macro{asfix\_get\_equ\_rhs}{ATerm }{ATerm t}{Get the righ-hand-side of an
AsFix equation.}
*/

#define asfix_get_equ_rhs(t)	(AFgetEquRhs(t))

/*
\Macro{asfix\_get\_equ\_conds}{ATerm }{ATerm t}{Get the conditions of an
AsFix equation.}
*/

#define asfix_get_equ_conds(t)	(AFgetEquConds(t))

/*
\Macro{asfix\_get\_lex\_sort}{ATerm }{ATerm t}{Get the sort of an AsFix
lexical.}
*/

#define asfix_get_lex_sort(t)	(ATgetArgument((ATermAppl)t, 1))

/*
\Macro{asfix\_get\_lex\_str}{ATerm }{ATerm t}{Get the string part of an 
AsFix lexical.}
*/

#define asfix_get_lex_str(t)	(ATgetArgument((ATermAppl)t, 0))

/*
\Macro{asfix\_get\_list\_elems}{ATerm }{ATerm t}{Get the elements part
of an AsFix list.}
*/

#define asfix_get_list_elems(t)	((ATermList)ATgetArgument((ATermAppl) t,2))

/*
\Macro{asfix\_get\_list\_sym}{ATerm }{ATerm t}{Get the symbol part
of an AsFix list.}
*/

#define asfix_get_list_sym(t)	(ATgetArgument((ATermAppl) t,0))
#define asfix_get_iter_sort(t) (ATgetArgument((ATermAppl)t, 0))
#define asfix_get_itersep_sort(t) (ATgetArgument((ATermAppl)t, 2))
#define asfix_get_itersep_sep(t)  (ATgetArgument((ATermAppl)t, 4))

/*
\Macro{asfix\_get\_appl\_ofs}{ATerm }{ATerm t}{Get the outermost function
symbol of an AsFix appl.}
*/

#define asfix_get_appl_ofs(t)	(ATgetArgument((ATermAppl)t, 0))

/*
\Macro{asfix\_get\_appl\_prod}{ATerm }{ATerm t}{Get the prod part of
an AsFix appl.}
*/

#define asfix_get_appl_prod(t)	(ATgetArgument((ATermAppl) t,0))

/*
\Macro{asfix\_get\_appl\_args}{ATerm }{ATerm t}{Get the arguments of an
AsFix appl.}
*/

#define asfix_get_appl_args(t)	((ATermList)(ATgetArgument((ATermAppl) t, 2)))

/*
\Macro{asfix\_get\_cond\_lhs}{ATerm }{ATerm cond}{Get the left-hand-side
of a condition.}
*/

#define asfix_get_cond_lhs(t)	(ATgetArgument((ATermAppl)t, 0))

/*
\Macro{asfix\_get\_cond\_rhs}{ATerm }{ATerm cond}{Get the right-hand-side
of a condition.}
*/

#define asfix_get_cond_rhs(t)	(ATgetArgument((ATermAppl)t, 4))

/*
\Macro{asfix\_get\_separator}{ATerm }{ATerm t}{Get the separator of an
AsFix iter-sep.}
*/

#define asfix_get_separator(t)	(assert(asfix_is_itersep(t)), \
															ATgetArgument((ATermAppl)t, 4))

/*
\Macro{asfix\_get\_term}{ATerm }{ATerm t}{Get the term part of an
AsFix term.}
*/

#define asfix_get_term(t) (ATgetArgument((ATermAppl)t, 6))

/*
\Macro{asfix\_get\_module\_eqs}{ATerm }{ATerm mod}{Get the list of 
equations of a module.}
*/

#define asfix_get_module_eqs(t) (AFgetModuleEqs(t))

/*
These four support functions are used to implement some of the
macros defined above.
*/

/*
\Function{AFgetEquLhs}{ATerm }{ATerm equ}{Retrieve the left-hand-side
of an equation.}
*/

ATerm AFgetEquLhs(ATerm equ);

/*
\Function{AFgetEquRhs}{ATerm }{ATerm equ}{Retrieve the right-hand-side
of an equation.}
*/

ATerm AFgetEquRhs(ATerm equ);

/*
\Function{AFgetEquConds}{ATerm }{ATerm equ}{Retrieve the conditions
of an equation.}
*/

ATerm AFgetEquConds(ATerm equ);

/*
\Function{AFputEquConds}{ATerm }{ATerm equ, ATermList eqs}{Put
the list of conditions of an equation.}
*/

ATerm AFputEquConds(ATerm equ, ATermList eqs);

/*
\Function{AFgetModuleEqs}{ATerm ATerm mod}{Get the list of equations
of an AsFix module.}
*/

ATerm AFgetModuleEqs(ATerm mod);

/*
\Function{AFputModuleEqs}{ATerm ATerm mod, ATermList eqs}{Put
the list of equations of an AsFix module.}
*/

ATerm AFputModuleEqs(ATerm mod, ATermList eqs);

/*
\Function{AFgetModuleSections}{ATerm ATerm mod}{Get 
the list of sections of an AsFix module.}
*/

ATermList AFgetModuleSections(ATerm mod);

/*
\Function{AFputModuleSections}{ATerm ATerm mod, ATermList sections}{Puts the list of sections
of an AsFix module.}
*/

ATerm AFputModuleSections(ATerm mod, ATermList sections);

/*
\Function{AFgetModuleName}{ATerm ATerm mod}{Get
the name of an AsFix module.}
*/

ATerm AFgetModuleName(ATerm mod);

/*
\Function{AFputModuleName}{ATerm ATerm mod, ATerm mname}{Put
the name of an AsFix module.}
*/

ATerm AFputModuleName(ATerm mod, ATerm mname);

/*
\Function{AFgetModuleCFfuncs}{ATerm ATerm mod}{Get the list of context-free
functions of an AsFix module.}
*/

ATermList AFgetModuleCFfuncs(ATerm mod);

/*
\Function{AFgetModuleSorts}{ATerm ATerm mod}{Get the list of 
sorts of an AsFix module.}
*/

ATermList AFgetModuleSorts(ATerm mod);

/*
\Function{AFgetModuleLexfuncs}{ATerm ATerm mod}{Get the list of 
lexical functions of an AsFix module.}
*/

ATermList AFgetModuleLexfuncs(ATerm mod);

/*
\Function{AFgetProdSort}{ATerm ATerm prod}{Get the result sort
of a production rule.}
*/

ATerm AFgetProdSort(ATerm prod);

/*
\Function{AFputSectionArgs}{ATerm }{ATerm section, ATermList secargs}{Put a list in a section.}
*/

ATerm AFputSectionArgs(ATerm section, ATermList secargs);

/*
\Function{AFinitModule}{ATerm }{Create an empty module.}
*/

ATerm AFinitModule();

/*
\Function{AFinitExportSection}{ATerm }{}{Create an empty
export section.}
*/

ATerm AFinitExportSection();

/*
\Function{AFinitContextFreeSyntaxSection}{ATerm }{}{Create an empty
context-free syntax section.}
*/

ATerm AFinitContextFreeSyntaxSection();

/*
\Function{AFinitLexicalSyntaxSection}{ATerm }{}{Create an empty
lexical syntax section.}
*/

ATerm AFinitLexicalSyntaxSection();

/*
\Function{AFmakeProd}{ATerm }{ATerm mn,ATermList args,ATerm sort,ATerm attrs}{Create a production rule.}
*/

ATerm AFmakeProd(ATerm mn,ATermList args,ATerm sort,ATerm attrs);

/*
\Function{AFmakeAppl}{ATerm }{ATerm prod,ATermList args}{Create a application.}
*/

ATerm AFmakeAppl(ATerm prod,ATermList args);

/*
\Function{AFmakeLex}{ATerm }{char *sym,ATerm sort}{Create a
lexical.}
*/

ATerm AFmakeLex(char *sym,ATerm sort);


/*
\Macro{asfix\_put\_term}{ATerm }{ATerm t, ATerm el}{Change
the term part of an AsFix term.} 
*/

#define asfix_put_term(t,el)		((ATerm) ATmakeApplList(ATgetSymbol((ATermAppl) t), \
		(ATreplace(ATgetArguments((ATermAppl) t),el,6))))

/*
\Macro{asfix\_put\_appl\_args}{ATerm }{ATerm appl, ATerm args}{
Change the arguments part 
of an AsFix application.}
*/

#define asfix_put_appl_args(appl,args) ((ATerm)ATmakeApplList(ATgetSymbol((ATermAppl) appl), \
		(ATreplace(ATgetArguments((ATermAppl) appl),((ATerm) args),2))))

/*
\Macro{asfix\_put\_list\_elems}{ATerm }{ATerm l, ATerm els}{
Change the elements part of an AsFix list.}
*/

#define asfix_put_list_elems(l,els)	((ATerm)ATmakeApplList(ATgetSymbol((ATermAppl) l), \
		(ATreplace(ATgetArguments((ATermAppl) (l)),((ATerm) els),2))))

/*
\Macro{asfix\_put\_module\_eqs}{ATerm }{ATerm mod, ATermList eqs}{
Change the equations of an AsFix module}
*/

#define asfix_put_module_eqs(mod,eqs) (AFputModuleEqs(mod,eqs))

/*
\Macro{asfix\_make\_list}{ATerm }{ATerm s, ATermList els}{Make
an asfix list.}
*/

#define asfix_make_list(s,els) \
    ((ATerm)ATmakeAppl3(symbol_asfix_list, s, pattern_empty_ws, (ATerm)els))


/*
\subsection{AsFix utilities}

\Macro{asfix\_filter\_layout}{ATermList }{ATermList l}{Filter
all layout terms from {\tt l}.}
*/

#define asfix_filter_layout(l) (ATfilter(l, AFnotLayout))

#endif
