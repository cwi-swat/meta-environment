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
#ifndef ASFIX_ACCESS_H
#define ASFIX_ACCESS_H

ATermList AFTgetEqs(ATerm mod);
ATerm AFTgetEquLhs(ATerm equation);
ATermList AFTgetSections(ATerm mod);
ATermList AFTgetSorts(ATerm mod);
ATermList AFTgetGrammarList(ATerm mod);
ATermList AFTmakeGrammarList(ATerm mod);
ATermList AFTgetLexFunctions(ATerm mod);
ATermList AFTgetCFFunctions(ATerm mod);
ATerm AFTgetProdRhs(ATerm prod);
ATerm AFTmakeCallerProd(ATerm prod);
ATerm AFTmakeEmptyAttrs();
ATerm AFTflattenSdf2Prod(ATerm modname, ATerm prod);

/* Some sanity checking macros */
#define AFTcheckAppl(t,prod) (asfix_is_appl(t) && \
			      AFTcheck(ATgetArgument((ATermAppl)t, 0), prod))
#define AFTcheck(t,prod)  (ATisEqual(t,prod))
#define AFgetApplArg(t,nr) (AFTarg(t,nr))
#define AFTarg(t,nr)      (ATelementAt((ATermList)ATgetArgument((ATermAppl)t, 2), nr))

/* Checking macros */
#define AFTisWS(ws)              (ATgetAFun((ATermAppl)ws) == symbol_w)
#define AFTisSep(sep)            (ATgetAFun((ATermAppl)sep) == symbol_sep)
#define AFTisEmptyEquSection(section) (AFTcheckAppl(section, af_prod_empty_equ_section))
#define AFTisEquSection(section) (AFTcheckAppl(section, af_prod_equ_section))
#define AFTisSimpleCondEqu(equ)	 (AFTcheckAppl(equ, af_prod_simple_cond_equ))
#define AFTisImpliesCondEqu(equ) (AFTcheckAppl(equ, af_prod_implies_cond_equ))
#define AFTisWhenCondEqu(equ)    (AFTcheckAppl(equ, af_prod_when_cond_equ))
#define AFTisModule(module)	 (AFTcheckAppl(module, af_prod_module))
#define AFTisModuleAttr(attr)	 (AFTcheckAppl(attr, af_prod_module_attr))
#define AFTisRejectAttr(attr)	 (AFTcheckAppl(attr, af_prod_reject_attr))
#define AFTisPreferAttr(attr)	 (AFTcheckAppl(attr, af_prod_prefer_attr))
#define AFTisUneagerAttr(attr)	 (AFTcheckAppl(attr, af_prod_uneager_attr))
#define AFTisConsAttr(attr)	 (AFTcheckAppl(attr, af_prod_cons_attr))
#define AFTisSimpleModuleId(module) (AFTcheckAppl(module, af_prod_simple_module_id))
#define AFTisComplexModuleId(module) (AFTcheckAppl(module, af_prod_complex_module_id))
#define AFTisSections(sections)	 (AFTcheckAppl(sections, af_prod_sections))
#define AFTisExportsSection(section)	(AFTcheckAppl(section, af_prod_exports_section))
#define AFTisHiddensSection(section)	(AFTcheckAppl(section, af_prod_hiddens_section))
#define AFTisGrammars(grammar)      (AFTcheckAppl(grammar, af_prod_grammars))
#define AFTisSortsGrammar(grammar)  (AFTcheckAppl(grammar, af_prod_sorts_grammar))
#define AFTisSymbols(symbol)        (AFTcheckAppl(symbol, af_prod_symbols))
#define AFTisLookAheads(symbol)     (AFTcheckAppl(symbol, af_prod_lookaheads))
#define AFTisLexicalFuncsGrammar(grammar) (AFTcheckAppl(grammar, \
                                           af_prod_lexfuncs_grammar))
#define AFTisContextFreeFuncsGrammar(grammar) (AFTcheckAppl(grammar, \
                                               af_prod_cffuncs_grammar))
#define AFTisNumChar(grammar) (AFTcheckAppl(grammar, \
                               af_prod_numchar))
#define AFTisSingleCharacter(grammar) (AFTcheckAppl(grammar, \
                                       af_prod_single_character))
#define AFTisCharacterRange(grammar) (AFTcheckAppl(grammar, \
                                      af_prod_character_range))
#define AFTisSingleCharRange(grammar) (AFTcheckAppl(grammar, \
                                  af_prod_single_charrange))
#define AFTisCharRangeList(grammar) (AFTcheckAppl(grammar, \
                                  af_prod_charrange_list))
#define AFTisCharRanges(grammar) (AFTcheckAppl(grammar, \
                                  af_prod_charranges_optcharranges))
#define AFTisOptCharRanges(grammar) (AFTcheckAppl(grammar, \
                                     af_prod_optcharranges))
#define AFTisCharClassSymbol(grammar) (AFTcheckAppl(grammar, \
                                       af_prod_charclass_symbol))
#define AFTisVarSymbol(grammar) (AFTcheckAppl(grammar, \
                                       af_prod_var_symbol))
#define AFTisRegularOptSymbol(grammar) (AFTcheckAppl(grammar, \
                                        af_prod_opt_symbol))
#define AFTisRegularAltSymbol(grammar) (AFTcheckAppl(grammar, \
                                        af_prod_alt_symbol))
#define AFTisRegularTupleSymbol(grammar) (AFTcheckAppl(grammar, \
                                          af_prod_tuple_symbol))
#define AFTisRegularFuncSymbol(grammar) (AFTcheckAppl(grammar, \
                                         af_prod_func_symbol))
#define AFTisRegularPermSymbol(grammar) (AFTcheckAppl(grammar, \
                                         af_prod_perm_symbol))
#define AFTisRegularSetSymbol(grammar) (AFTcheckAppl(grammar, \
                                        af_prod_set_symbol))
#define AFTisRegularNonEmptySeqSymbol(grammar) (AFTcheckAppl(grammar, \
                                        af_prod_nonemptyseq_symbol))
#define AFTisRegularEmptySeqSymbol(grammar) (AFTcheckAppl(grammar, \
                                             af_prod_empty_seq_symbol))
#define AFTisBasicLAYOUTSymbol(grammar) (AFTcheckAppl(grammar, \
                                         af_prod_LAYOUT_symbol))
#define AFTisSTARTSymbol(grammar) (AFTcheckAppl(grammar, \
                                   af_prod_START_symbol))
#define AFTisStartSymbol(grammar) (AFTcheckAppl(grammar, \
                                   af_prod_Start_symbol))
#define AFTisBasicLEXSymbol(grammar) (AFTcheckAppl(grammar, \
                                      af_prod_LEX_symbol))
#define AFTisBasicCFSymbol(grammar) (AFTcheckAppl(grammar, \
                                     af_prod_CF_symbol))
#define AFTisKernelSyntaxGrammar(grammar) (AFTcheckAppl(grammar, \
                                           af_prod_kernel_syntax_grammar))
#define AFTisRestrictionGrammar(grammar) (AFTcheckAppl(grammar, \
                                           af_prod_restriction_grammar))
#define AFTisPrioritiesGrammar(grammar) (AFTcheckAppl(grammar, \
                                       af_priorities_grammar))
#define AFTisPriorityRule(grammar) (AFTcheckAppl(grammar, \
                                    af_priority_rule))
#define AFTisRestrictionRule(grammar) (AFTcheckAppl(grammar, \
                                       af_restrictions_rule))
#define AFTisGroupPriority(grammar) (AFTcheckAppl(grammar, \
                                     af_group_priority))
#define AFTisPrioritiesList(grammar) (AFTcheckAppl(grammar, \
                                      af_priorities_list))
#define AFTisPriorityGroupList(grammar) (AFTcheckAppl(grammar, \
                                         af_prio_group_list))
#define AFTisPrios(prod)    	       (AFTcheckAppl(prod, af_prod_prios))
#define AFTisProds(prod)    	       (AFTcheckAppl(prod, af_prod_prods))
#define AFTisRestricts(prod)           (AFTcheckAppl(prod, af_prod_restricts))
#define AFTisProd(prod)    	       (AFTcheckAppl(prod, af_prod_prod))
#define AFTisLookAhead(prod)           (AFTcheckAppl(prod, af_prod_lookahead))
#define AFTisComplexLookAhead(prod)    (AFTcheckAppl(prod, \
                                        af_prod_complexlookahead))
#define AFTisPrefixProd(prod)          (AFTcheckAppl(prod, \
                                        af_prefix_prod_prod))
#define AFTisSortSymbol(symbol)        (AFTcheckAppl(symbol, \
                                        af_prod_sort_symbol))
#define AFTisLiteralSymbol(symbol)     (AFTcheckAppl(symbol, \
                                        af_prod_literal_symbol))
#define AFTisUQLiteralSymbol(symbol)     (AFTcheckAppl(symbol, \
                                          af_prod_uqliteral_symbol))
#define AFTisStarListSymbol(symbol)    (AFTcheckAppl(symbol, \
                                        af_prod_star_list_symbol))
#define AFTisStarSepListSymbol(symbol) (AFTcheckAppl(symbol, \
                                        af_prod_star_sep_list_symbol))
#define AFTisPlusListSymbol(symbol)    (AFTcheckAppl(symbol, \
                                        af_prod_plus_list_symbol))
#define AFTisListNumberSymbol(symbol)    (AFTcheckAppl(symbol, \
                                        af_prod_list_number_symbol))
#define AFTisListSepNumberSymbol(symbol)    (AFTcheckAppl(symbol, \
                                             af_prod_list_sep_number_symbol))
#define AFTisPlusSepListSymbol(symbol) (AFTcheckAppl(symbol, \
                                        af_prod_plus_sep_list_symbol))
#define AFTisEmptyAttrs(attr)       (AFTcheckAppl(attr, af_prod_empty_attrs))
#define AFTisAttrs(attr)            (AFTcheckAppl(attr, af_prod_attrs))
#define AFTisAssocAttr(attr)        (AFTcheckAppl(attr, af_prod_assoc_attr))
#define AFTisLeftAssoc(attr)        (AFTcheckAppl(attr, af_prod_left_assoc))
#define AFTisRightAssoc(attr)       (AFTcheckAppl(attr, af_prod_right_assoc))
#define AFTisAssocAssoc(attr)       (AFTcheckAppl(attr, af_prod_assoc_assoc))
#define AFTisNonAssocAssoc(attr)    (AFTcheckAppl(attr, \
                                                  af_prod_nonassoc_assoc))
#define AFTisBracketAssoc(attr)     (AFTcheckAppl(attr, \
                                                  af_prod_bracket_assoc))
#define AFTisConstructorAssoc(attr) (AFTcheckAppl(attr, \
                                                  af_prod_constructor_assoc)) 
#define AFTisMemoAssoc(attr)        (AFTcheckAppl(attr, af_prod_memo_assoc)) 

#define AFTisList(list)		(ATgetAFun((ATermAppl)list) == af_symbol_list)

#define AFTisSimpleEqu(equ)	(asfix_is_appl(equ))
#define AFTisCond(cond)	        (asfix_is_appl(cond))
#define AFTisEqualityCond(cond) (ATisEqual(AFTarg((cond),2), \
                                 pattern_asfix_equal_symbol))
#define AFTisConds(conds)       (AFTcheckAppl((conds), (af_prod_conds)))

#define AFTisLexConstructor(t) (asfix_is_appl(t) && \
                                ATmatchTerm(ATgetArgument((ATermAppl)(t),0), \
                                pattern_asfix_lex_cons, NULL, NULL))

/* The macro to deal with plain aterms */

#define AFTisAFun2ATerm(a)   (AFTcheckAppl(a, af_prod_afun2aterm)) 
#define AFTisLiteral2AFun(a) (AFTcheckAppl(a, af_prod_literal2afun)) 

extern ATbool AFTisDefaultTag(ATerm tag);

/* Access functions */
extern ATerm AFTgetEquLhs(ATerm equ);

/* Access macros */
#define AFTgetEquSectionLit(s)        (AFTarg((s), 0))
#define AFTgetEquSectionWS(s)	      (AFTarg((s), 1))
#define AFTgetEquSectionEqList(s)     (AFTarg((s), 2))

#define AFTgetSimpleCondEquTag(equ)		(AFTarg((equ), 0))
#define AFTgetSimpleCondEquWS(equ)		(AFTarg((equ), 1))
#define AFTgetSimpleCondEquEqu(equ)		(AFTarg((equ), 2))

#define AFTgetImpliesCondEquTag(equ)	(AFTarg((equ), 0))
#define AFTgetImpliesCondEquWS0(equ)	(AFTarg((equ), 1))
#define AFTgetImpliesCondEquConds(equ)	(AFTarg((equ), 2))
#define AFTgetImpliesCondEquWS1(equ)	(AFTarg((equ), 3))
#define AFTgetImpliesCondEquBarLex(equ)	(AFTarg((equ), 4))
#define AFTgetImpliesCondEquWS2(equ)	(AFTarg((equ), 5))
#define AFTgetImpliesCondEquEqu(equ)	(AFTarg((equ), 6))

#define AFTgetWhenCondEquTag(equ)		(AFTarg((equ), 0))
#define AFTgetWhenCondEquWS0(equ)		(AFTarg((equ), 1))
#define AFTgetWhenCondEquEqu(equ)		(AFTarg((equ), 2))
#define AFTgetWhenCondEquWS1(equ)		(AFTarg((equ), 3))
#define AFTgetWhenCondEquLit(equ)		(AFTarg((equ), 4))
#define AFTgetWhenCondEquWS2(equ)		(AFTarg((equ), 5))
#define AFTgetWhenCondEquConds(equ)		(AFTarg((equ), 6))

#define AFTgetSimpleEquProd(equ)    (ATgetArgument((equ), 0))
#define AFTgetSimpleEquLHS(equ)	    (AFTarg((equ), 0))
#define AFTgetSimpleEquWS0(equ)	    (AFTarg((equ), 1))
#define AFTgetSimpleEquLit(equ)	    (AFTarg((equ), 2))
#define AFTgetSimpleEquWS1(equ)	    (AFTarg((equ), 3))
#define AFTgetSimpleEquRHS(equ)	    (AFTarg((equ), 4))

#define AFTgetListIter(l)	 (ATgetArgument((l), 0))
#define AFTgetListWS(l)		 (ATgetArgument((l), 1))
#define AFTgetListElements(l)	 ((ATermList)ATgetArgument((l), 2))

#define AFTgetCondsCondList(conds)  (AFTarg((conds), 0))

#define AFTgetCondProd(cond)      (ATgetArgument((cond), 0))
#define AFTgetCondLHS(cond)	  (AFTarg((cond), 0))
#define AFTgetCondWS0(cond)	  (AFTarg((cond), 1))
#define AFTgetCondLit(cond)	  (AFTarg((cond), 2))
#define AFTgetCondWS1(cond)	  (AFTarg((cond), 3))
#define AFTgetCondRHS(cond)	  (AFTarg((cond), 4))

#define AFTgetModuleLit(m)        (AFTarg((m), 0))
#define AFTgetModuleWS0(m)	  (AFTarg((m), 1))
#define AFTgetModuleName(m)       (AFTarg((m), 2))
#define AFTgetModuleWS1(m)	  (AFTarg((m), 3))
#define AFTgetModuleImportList(m) (AFTarg((m), 4))
#define AFTgetModuleWS2(m)	  (AFTarg((m), 5))
#define AFTgetModuleSections(m)   (AFTarg((m), 6))

#define AFTgetModuleAttrId(m)     (AFTarg((m), 4))

#define AFTgetSimpleModuleIdName(m) (AFTarg((m), 0))

#define AFTgetComplexModuleIdName(m)    (AFTarg((m), 0))
#define AFTgetComplexModuleIdWS0(m)     (AFTarg((m), 1))
#define AFTgetComplexModuleIdLit0(m)    (AFTarg((m), 2))
#define AFTgetComplexModuleIdWS1(m)     (AFTarg((m), 3))
#define AFTgetComplexModuleIdSymbols(m) (AFTarg((m), 4))
#define AFTgetComplexModuleIdWS2(m)     (AFTarg((m), 5))
#define AFTgetComplexModuleIdLit1(m)    (AFTarg((m), 6))

#define AFTgetConsArg(a)     (AFTarg((a), 4))

#define AFTgetSectionsList(s)     (AFTarg((s), 0))

#define AFTgetSectionLit(s)     (AFTarg((s), 0))
#define AFTgetSectionWS(s)      (AFTarg((s), 1))
#define AFTgetSectionGrammar(s) (AFTarg((s), 2))

#define AFTgetGrammarSection1(g)  (AFTarg((g), 0))
#define AFTgetGrammarWS(g)        (AFTarg((g), 1))
#define AFTgetGrammarSection2(g)  (AFTarg((g), 2))

#define AFTgetSymbolsList(s)     (AFTarg((s), 0))

#define AFTgetLookAheadsList(s)  (AFTarg((s), 2))

#define AFTgetSortsLit(s)     (AFTarg((s), 0))
#define AFTgetSortsWS(s)      (AFTarg((s), 1))
#define AFTgetSortsSymbols(s) (AFTarg((s), 2))

#define AFTgetProdsList(s)     (AFTarg((s), 0))

#define AFTgetPriosList(s)     (AFTarg((s), 0))

#define AFTgetRestrictsList(s)     (AFTarg((s), 0))

#define AFTgetLexicalFuncsLit0(s)     (AFTarg((s), 0))
#define AFTgetLexicalFuncsWS0(s)      (AFTarg((s), 1))
#define AFTgetLexicalFuncsLit1(s)     (AFTarg((s), 2))
#define AFTgetLexicalFuncsWS1(s)      (AFTarg((s), 3))
#define AFTgetLexicalFuncsProds(s)    (AFTarg((s), 4))

#define AFTgetContextFreeFuncsLit0(s)     (AFTarg((s), 0))
#define AFTgetContextFreeFuncsWS0(s)      (AFTarg((s), 1))
#define AFTgetContextFreeFuncsLit1(s)     (AFTarg((s), 2))
#define AFTgetContextFreeFuncsWS1(s)      (AFTarg((s), 3))
#define AFTgetContextFreeFuncsProds(s)    (AFTarg((s), 4))

#define AFTgetKernelSyntaxLit0(s)     (AFTarg((s), 0))
#define AFTgetKernelSyntaxWS0(s)      (AFTarg((s), 1))
#define AFTgetKernelSyntaxProds(s)    (AFTarg((s), 2))

#define AFTgetRestrictionLit0(s)     (AFTarg((s), 0))
#define AFTgetRestrictionWS0(s)      (AFTarg((s), 1))
#define AFTgetRestrictionProds(s)    (AFTarg((s), 2))

#define AFTgetPrioritiesGrammarLit0(s)  (AFTarg((s), 0))
#define AFTgetPrioritiesGrammarWS0(s)   (AFTarg((s), 1))
#define AFTgetPrioritiesGrammarPrios(s) (AFTarg((s), 2))

#define AFTgetPriorityRuleLeft(p)   (AFTarg((p), 0))
#define AFTgetPriorityRuleWS0(p)    (AFTarg((p), 1))
#define AFTgetPriorityRuleAssoc(p)  (AFTarg((p), 2))
#define AFTgetPriorityRuleWS1(p)    (AFTarg((p), 3))
#define AFTgetPriorityRuleRight(p)  (AFTarg((p), 4))

#define AFTgetRestrictionSymbols(p)   (AFTarg((p), 0))
#define AFTgetRestrictionLit(p)  (AFTarg((p), 2))
#define AFTgetRestrictionWS1(p)    (AFTarg((p), 3))
#define AFTgetRestrictionLookaheads(p)  (AFTarg((p), 4))

#define AFTgetGroupPriorityProd(p) (AFTarg((p), 0))

#define AFTgetPriorityGroupListList(p) (AFTarg((p), 0))

#define AFTgetProdSymbols(p) (AFTarg((p), 0))
#define AFTgetProdWS0(p)     (AFTarg((p), 1))
#define AFTgetProdLit(p)     (AFTarg((p), 2))
#define AFTgetProdWS1(p)     (AFTarg((p), 3))
#define AFTgetProdSymbol(p)  (AFTarg((p), 4))
#define AFTgetProdWS2(p)     (AFTarg((p), 5))
#define AFTgetProdAttrs(p)   (AFTarg((p), 6))

#define AFTgetLookAheadCharClass(p) (AFTarg((p), 0))

#define AFTgetComplexLookAheadCharClass(p) (AFTarg((p), 0))
#define AFTgetComplexLookAheadWS0(p) (AFTarg((p), 1))
#define AFTgetComplexLookAheadLit0(p) (AFTarg((p), 2))
#define AFTgetComplexLookAheadWS1(p) (AFTarg((p), 3))
#define AFTgetComplexLookAheadLookAheads(p) (AFTarg((p), 4))

#define AFTgetPrefixProdLiteral(p) (AFTarg((p), 0))
#define AFTgetPrefixProdWS0(p)     (AFTarg((p), 1))
#define AFTgetPrefixProdLit0(p)    (AFTarg((p), 2))
#define AFTgetPrefixProdWS1(p)     (AFTarg((p), 3))
#define AFTgetPrefixProdSymbols(p) (AFTarg((p), 4))
#define AFTgetPrefixProdWS2(p)     (AFTarg((p), 5))
#define AFTgetPrefixProdLit1(p)    (AFTarg((p), 6))
#define AFTgetPrefixProdWS3(p)     (AFTarg((p), 7))
#define AFTgetPrefixProdLit2(p)    (AFTarg((p), 8))
#define AFTgetPrefixProdWS4(p)     (AFTarg((p), 9))
#define AFTgetPrefixProdSymbol(p)  (AFTarg((p), 10))
#define AFTgetPrefixProdWS5(p)     (AFTarg((p), 11))
#define AFTgetPrefixProdAttrs(p)   (AFTarg((p), 12))

#define AFTgetAttrsLit0(p) (AFTarg((p), 0))
#define AFTgetAttrsWS0(p)  (AFTarg((p), 1))
#define AFTgetAttrsList(p) (AFTarg((p), 2))
#define AFTgetAttrsWS1(p)  (AFTarg((p), 3))
#define AFTgetAttrsLit1(p) (AFTarg((p), 4))

#define AFTgetAssocAttr(a) (AFTarg((a), 0))
#define AFTgetArgAssoc(a) (AFTarg((a), 0))

#define AFTgetNumChar(p) (AFTarg((p), 0))
#define AFTgetSingleCharacter(p) (AFTarg((p), 0))
#define AFTgetLeftCharacter(p) (AFTarg((p), 0))
#define AFTgetRightCharacter(p) (AFTarg((p), 4))
#define AFTgetLeftCharRanges(p) (AFTarg((p), 0))
#define AFTgetRightCharRanges(p) (AFTarg((p), 2))
#define AFTgetSingleCharRange(p) (AFTarg((p), 0))
#define AFTgetCharRanges(p) (AFTarg((p), 0))
#define AFTgetOptCharRanges(p) (AFTarg((p), 2))
#define AFTgetCharClassSymbol(p) (AFTarg((p), 0))
#define AFTgetVarSymbol(p) (AFTarg((p), 2))
#define AFTgetRegularOptSymbol(p) (AFTarg((p), 0))
#define AFTgetBasicLEXSymbol(p) (AFTarg((p), 2))
#define AFTgetBasicCFSymbol(p) (AFTarg((p), 2))

#define AFTgetRegularAltSymbol0(p) (AFTarg((p), 0))
#define AFTgetRegularAltWS0(p)     (AFTarg((p), 1))
#define AFTgetRegularAltLit(p)     (AFTarg((p), 2))
#define AFTgetRegularAltWS1(p)     (AFTarg((p), 3))
#define AFTgetRegularAltSymbol1(p) (AFTarg((p), 4))

#define AFTgetRegularTupleSymbol0(p) (AFTarg((p), 0))
#define AFTgetRegularTupleWS0(p)     (AFTarg((p), 1))
#define AFTgetRegularTupleLit(p)     (AFTarg((p), 2))
#define AFTgetRegularTupleWS1(p)     (AFTarg((p), 3))
#define AFTgetRegularTupleSymbol1(p) (AFTarg((p), 4))

#define AFTgetRegularFuncLit0(p)    (AFTarg((p), 0))
#define AFTgetRegularFuncWS0(p)     (AFTarg((p), 1))
#define AFTgetRegularFuncSymbols(p) (AFTarg((p), 2))
#define AFTgetRegularFuncWS1(p)     (AFTarg((p), 3))
#define AFTgetRegularFuncLit1(p)    (AFTarg((p), 4))
#define AFTgetRegularFuncWS2(p)     (AFTarg((p), 5))
#define AFTgetRegularFuncSymbol(p)  (AFTarg((p), 6))
#define AFTgetRegularFuncWS3(p)     (AFTarg((p), 7))
#define AFTgetRegularFuncLit3(p)    (AFTarg((p), 8))

#define AFTgetRegularPermLit0(p)    (AFTarg((p), 0))
#define AFTgetRegularPermWS0(p)     (AFTarg((p), 1))
#define AFTgetRegularPermSymbols(p) (AFTarg((p), 2))
#define AFTgetRegularPermWS1(p)     (AFTarg((p), 3))
#define AFTgetRegularPermLit1(p)    (AFTarg((p), 4))

#define AFTgetRegularSetLit0(p)   (AFTarg((p), 0))
#define AFTgetRegularSetWS0(p)    (AFTarg((p), 1))
#define AFTgetRegularSetLit1(p)   (AFTarg((p), 2))
#define AFTgetRegularSetWS1(p)    (AFTarg((p), 3))
#define AFTgetRegularSetSymbol(p) (AFTarg((p), 4))
#define AFTgetRegularSetWS2(p)    (AFTarg((p), 5))
#define AFTgetRegularSetLit2(p)   (AFTarg((p), 6))

#define AFTgetRegularNonEmptySeqLit0(p) (AFTarg((p), 0))
#define AFTgetRegularNonEmptySeqWS0(p) (AFTarg((p), 1))
#define AFTgetRegularNonEmptySeqSymbol0(p) (AFTarg((p), 2))
#define AFTgetRegularNonEmptySeqWS1(p) (AFTarg((p), 3))
#define AFTgetRegularNonEmptySeqSymbol1(p) (AFTarg((p), 4))
#define AFTgetRegularNonEmptySeqWS2(p) (AFTarg((p), 5))
#define AFTgetRegularNonEmptySeqLit1(p) (AFTarg((p), 6))

#define AFTgetSortSymbol(p) (AFTarg((p), 0))
#define AFTgetLiteralSymbol(p) (AFTarg((p), 0))
#define AFTgetUQLiteralLiteral(p) (AFTarg((p), 0))
 
#define AFTgetStarListSort(s) (AFTarg((s), 0))
#define AFTgetStarListWS0(s)  (AFTarg((s), 1)) 
#define AFTgetStarListStar(s) (AFTarg((s), 2))

#define AFTgetStarSepListLit0(s) (AFTarg((s), 0))
#define AFTgetStarSepListWS0(s)  (AFTarg((s), 1))
#define AFTgetStarSepListSort(s) (AFTarg((s), 2))
#define AFTgetStarSepListWS1(s)  (AFTarg((s), 3))
#define AFTgetStarSepListSep(s)  (AFTarg((s), 4))
#define AFTgetStarSepListWS2(s)  (AFTarg((s), 5))
#define AFTgetStarSepListLit1(s) (AFTarg((s), 6))
#define AFTgetStarSepListWS3(s)  (AFTarg((s), 7))
#define AFTgetStarSepListStar(s) (AFTarg((s), 8))
 
#define AFTgetPlusListSort(s) (AFTarg((s), 0))
#define AFTgetPlusListWS0(s)  (AFTarg((s), 1)) 
#define AFTgetPlusListStar(s) (AFTarg((s), 2))

#define AFTgetPlusSepListLit0(s) (AFTarg((s), 0))
#define AFTgetPlusSepListWS0(s)  (AFTarg((s), 1))
#define AFTgetPlusSepListSort(s) (AFTarg((s), 2))
#define AFTgetPlusSepListWS1(s)  (AFTarg((s), 3))
#define AFTgetPlusSepListSep(s)  (AFTarg((s), 4))
#define AFTgetPlusSepListWS2(s)  (AFTarg((s), 5))
#define AFTgetPlusSepListLit1(s) (AFTarg((s), 6))
#define AFTgetPlusSepListWS3(s)  (AFTarg((s), 7))
#define AFTgetPlusSepListPlus(s) (AFTarg((s), 8))

#define AFTgetListNumberLit0(s)   (AFTarg((s), 0))  
#define AFTgetListNumberWS0(s)    (AFTarg((s), 1))  
#define AFTgetListNumberSort(s)   (AFTarg((s), 2))  
#define AFTgetListNumberWS1(s)    (AFTarg((s), 3))  
#define AFTgetListNumberLit1(s)   (AFTarg((s), 4))  
#define AFTgetListNumberWS2(s)    (AFTarg((s), 5))  
#define AFTgetListNumberNumber(s) (AFTarg((s), 6))  
#define AFTgetListNumberWS3(s)    (AFTarg((s), 7))  
#define AFTgetListNumberPlus(s)   (AFTarg((s), 8))  

#define AFTgetListSepNumberLit0(s)   (AFTarg((s), 0))  
#define AFTgetListSepNumberWS0(s)    (AFTarg((s), 1))  
#define AFTgetListSepNumberSort(s)   (AFTarg((s), 2))  
#define AFTgetListSepNumberWS1(s)    (AFTarg((s), 3))  
#define AFTgetListSepNumberSep(s)    (AFTarg((s), 4))  
#define AFTgetListSepNumberWS2(s)    (AFTarg((s), 5))  
#define AFTgetListSepNumberLit1(s)   (AFTarg((s), 6))  
#define AFTgetListSepNumberWS3(s)    (AFTarg((s), 7))  
#define AFTgetListSepNumberNumber(s) (AFTarg((s), 8))  
#define AFTgetListSepNumberWS4(s)    (AFTarg((s), 9))  
#define AFTgetListSepNumberPlus(s)   (AFTarg((s), 10))  

/* Access macro's for plain aterm patterns */

#define AFTgetAFunATerm(a) (AFTarg((a), 0))
#define AFTgetLiteralAFun(a) (AFTarg((a), 0))


/* Construction macro's */
#define AFTbuildEquSection(lit,ws,equlist) \
	(AFmakeAppl(af_prod_equ_section, ATmakeList3((lit), (ws), (equlist))))
#define AFTbuildList(iter,ws,elems) \
	((ATerm)ATmakeAppl3(af_symbol_list, (iter), (ws), (ATerm)(elems)))

#define AFTbuildSimpleCondEqu(tag,w,equ) \
	(AFmakeAppl(af_prod_simple_cond_equ,ATmakeList3((tag), (w), (equ))))
#define AFTbuildImpliesCondEqu(tag,w0,conds,w1,lit,w2,equ) \
	(AFmakeAppl(af_prod_implies_cond_equ, \
		ATmakeList(7,(tag),(w0),(conds),(w1),(lit),(w2),(equ))))
#define AFTbuildWhenCondEqu(tag,w0,equ,w1,lit,w2,conds) \
	(AFmakeAppl(af_prod_when_cond_equ, \
		ATmakeList(7,(tag),(w0),(equ),(w1),(lit),(w2),(conds))))
#define AFTbuildSimpleEqu(prod,lhs,w0,lit,w1,rhs) \
	(AFmakeAppl((prod), ATmakeList5((lhs),(w0),(lit),(w1),(rhs))))
#define AFTbuildConds(condlist) \
  (AFmakeAppl(af_prod_conds, ATmakeList1((condlist))))
#define AFTbuildCond(prod,lhs,w0,lit,w1,rhs) \
	(AFmakeAppl(prod, ATmakeList5((lhs),(w0),(lit),(w1),(rhs))))

/* Well-known symbols */
extern AFun af_symbol_list;

/* Well-known prods */
extern ATerm pattern_asfix_sort;
extern ATerm pattern_asfix_iter_star;
extern ATerm pattern_asfix_iter_plus;
extern ATerm pattern_asfix_itersep_star;
extern ATerm pattern_asfix_itersep_plus;
extern ATerm pattern_asfix_l;
extern ATerm pattern_asfix_ql;
extern ATerm pattern_asfix_lexcaller;
extern ATerm pattern_asfix_appl;
extern ATerm pattern_asfix_lex_cons;
extern ATerm pattern_asfix_term;
extern ATerm pattern_asfix_lex;

extern ATerm af_prod_equ_section;
extern ATerm af_prod_empty_equ_section;
extern ATerm af_prod_simple_cond_equ;
extern ATerm af_prod_implies_cond_equ;
extern ATerm af_prod_when_cond_equ;
extern ATerm af_prod_conds;
extern ATerm af_prod_tag;
extern ATerm af_prod_module;
extern ATerm af_prod_module_attr;
extern ATerm af_prod_reject_attr;
extern ATerm af_prod_prefer_attr;
extern ATerm af_prod_uneager_attr;
extern ATerm af_prod_cons_attr;
extern ATerm af_prod_simple_module_id;
extern ATerm af_prod_complex_module_id;
extern ATerm af_prod_sections;
extern ATerm af_prod_exports_section;
extern ATerm af_prod_hiddens_section;
extern ATerm af_prod_grammars;
extern ATerm af_prod_sorts_grammar;
extern ATerm af_prod_symbols;
extern ATerm af_prod_lookaheads;
extern ATerm af_prod_lexfuncs_grammar;
extern ATerm af_prod_cffuncs_grammar;
extern ATerm af_prod_numchar;
extern ATerm af_prod_single_character;
extern ATerm af_prod_character_range;
extern ATerm af_prod_single_charrange;
extern ATerm af_prod_charrange_list;
extern ATerm af_prod_charranges_optcharranges;
extern ATerm af_prod_optcharranges;
extern ATerm af_prod_charclass_symbol;
extern ATerm af_prod_var_symbol;
extern ATerm af_prod_opt_symbol;
extern ATerm af_prod_alt_symbol;
extern ATerm af_prod_tuple_symbol;
extern ATerm af_prod_func_symbol;
extern ATerm af_prod_perm_symbol;
extern ATerm af_prod_set_symbol;
extern ATerm af_prod_nonemptyseq_symbol;
extern ATerm af_prod_empty_seq_symbol;
extern ATerm af_prod_LAYOUT_symbol;
extern ATerm af_prod_START_symbol;
extern ATerm af_prod_Start_symbol;
extern ATerm af_prod_LEX_symbol;
extern ATerm af_prod_CF_symbol;
extern ATerm af_prod_kernel_syntax_grammar;
extern ATerm af_prod_restriction_grammar;
extern ATerm af_prod_prios;
extern ATerm af_prod_prods;
extern ATerm af_prod_restricts;
extern ATerm af_prod_prod;
extern ATerm af_prod_lookahead;
extern ATerm af_prod_complexlookahead;
extern ATerm af_prefix_prod_prod;
extern ATerm af_prod_sort_symbol;
extern ATerm af_prod_literal_symbol;
extern ATerm af_prod_uqliteral_symbol;
extern ATerm af_prod_star_list_symbol;
extern ATerm af_prod_star_sep_list_symbol;
extern ATerm af_prod_plus_list_symbol;
extern ATerm af_prod_list_number_symbol;
extern ATerm af_prod_list_sep_number_symbol;
extern ATerm af_prod_plus_sep_list_symbol;
extern ATerm af_prod_empty_attrs;
extern ATerm af_prod_attrs;
extern ATerm af_priorities_grammar;
extern ATerm af_priority_rule;
extern ATerm af_restrictions_rule;
extern ATerm af_priorities_list;
extern ATerm af_prio_group_list;
extern ATerm af_group_priority;
extern ATerm af_prod_assoc_attr;
extern ATerm af_prod_left_assoc;
extern ATerm af_prod_right_assoc;
extern ATerm af_prod_assoc_assoc;
extern ATerm af_prod_nonassoc_assoc;
extern ATerm af_prod_bracket_assoc;
extern ATerm af_prod_constructor_assoc;
extern ATerm af_prod_memo_assoc;

extern ATerm af_prod_afun2aterm;
extern ATerm af_prod_literal2afun;

/* Some other useful terms */
extern ATerm af_iter_eqlist;
extern ATerm pattern_asfix_equal_symbol;

#endif
