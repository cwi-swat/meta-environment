/*
 * Generated at Tue Mar 13 15:00:25 2001
 */

#ifndef __SDF_dict_H
#define __SDF_dict_H

#include <aterm2.h>


extern ATerm SDF_patternRealConRealCon;
extern ATerm SDF_patternOptExpAbsent;
extern ATerm SDF_patternOptExpPresent;
extern ATerm SDF_patternCharacterEof;
extern ATerm SDF_patternCharacterTop;
extern ATerm SDF_patternCharacterShort;
extern ATerm SDF_patternCharacterNumeric;
extern ATerm SDF_patternShortCharEscaped;
extern ATerm SDF_patternShortCharRegular;
extern ATerm SDF_patternNumCharDigits;
extern ATerm SDF_patternTagIdEmpty;
extern ATerm SDF_patternTagIdDefault;
extern ATerm SDF_patternAnnAnnotation;
extern ATerm SDF_patternATermAnnotatedAppl;
extern ATerm SDF_patternATermAnnotatedFun;
extern ATerm SDF_patternATermAnnotatedList;
extern ATerm SDF_patternATermAnnotatedConstant;
extern ATerm SDF_patternATermAppl;
extern ATerm SDF_patternATermFun;
extern ATerm SDF_patternATermList;
extern ATerm SDF_patternATermConstant;
extern ATerm SDF_patternAFunDefault;
extern ATerm SDF_patternAConReal;
extern ATerm SDF_patternAConInt;
extern ATerm SDF_patternATermListNotEmpty;
extern ATerm SDF_patternATermListEmpty;
extern ATerm SDF_patternATermsCons;
extern ATerm SDF_patternATermsAterm;
extern ATerm SDF_patternLCharEscaped;
extern ATerm SDF_patternLCharNormal;
extern ATerm SDF_patternEscCharDecimal;
extern ATerm SDF_patternEscCharAlphaNumeric;
extern ATerm SDF_patternDecimalEscCharDec250_255;
extern ATerm SDF_patternDecimalEscCharDec200_249;
extern ATerm SDF_patternDecimalEscCharDec0_199;
extern ATerm SDF_patternAlphaNumericalEscCharDefault;
extern ATerm SDF_patternCharClassBracket;
extern ATerm SDF_patternCharClassUnion;
extern ATerm SDF_patternCharClassIsect;
extern ATerm SDF_patternCharClassDiff;
extern ATerm SDF_patternCharClassComp;
extern ATerm SDF_patternCharClassSimpleCharclass;
extern ATerm SDF_patternOptCharRangesPresent;
extern ATerm SDF_patternOptCharRangesAbsent;
extern ATerm SDF_patternCharRangesBracket;
extern ATerm SDF_patternCharRangesConc;
extern ATerm SDF_patternCharRangesDefault;
extern ATerm SDF_patternCharRangeRange;
extern ATerm SDF_patternCharRangeDefault;
extern ATerm SDF_patternIntConNegative;
extern ATerm SDF_patternIntConPositive;
extern ATerm SDF_patternIntConNatural;
extern ATerm SDF_patternNatConDigits;
extern ATerm SDF_patternRenamingProduction;
extern ATerm SDF_patternRenamingSymbol;
extern ATerm SDF_patternRenamingListMany;
extern ATerm SDF_patternRenamingListSingle;
extern ATerm SDF_patternRenamingListEmpty;
extern ATerm SDF_patternRenamingsRenamings;
extern ATerm SDF_patternSymbolListMany;
extern ATerm SDF_patternSymbolListSingle;
extern ATerm SDF_patternSymbolListEmpty;
extern ATerm SDF_patternSymbolsDefault;
extern ATerm SDF_patternAliasListMany;
extern ATerm SDF_patternAliasListSingle;
extern ATerm SDF_patternAliasListEmpty;
extern ATerm SDF_patternAliasesDefault;
extern ATerm SDF_patternAliasAlias;
extern ATerm SDF_patternRestrictionListMany;
extern ATerm SDF_patternRestrictionListSingle;
extern ATerm SDF_patternRestrictionListEmpty;
extern ATerm SDF_patternRestrictionsDefault;
extern ATerm SDF_patternRestrictionFollow;
extern ATerm SDF_patternLookaheadListMany;
extern ATerm SDF_patternLookaheadListSingle;
extern ATerm SDF_patternLookaheadListEmpty;
extern ATerm SDF_patternLookaheadsList;
extern ATerm SDF_patternLookaheadsBracket;
extern ATerm SDF_patternLookaheadsAlt;
extern ATerm SDF_patternLookaheadsSingle;
extern ATerm SDF_patternLookaheadSeq;
extern ATerm SDF_patternLookaheadCharClass;
extern ATerm SDF_patternSymbolArgumentsMany;
extern ATerm SDF_patternSymbolArgumentsSingle;
extern ATerm SDF_patternSymbolArgumentsEmpty;
extern ATerm SDF_patternLiteralQuoted;
extern ATerm SDF_patternLiteralUqlit;
extern ATerm SDF_patternUQLiteralMoreChars;
extern ATerm SDF_patternUQLiteralOneChar;
extern ATerm SDF_patternSortMoreChars;
extern ATerm SDF_patternSortOneChar;
extern ATerm SDF_patternPriorityListMany;
extern ATerm SDF_patternPriorityListSingle;
extern ATerm SDF_patternPriorityListEmpty;
extern ATerm SDF_patternPrioritiesDefault;
extern ATerm SDF_patternGroupListMany;
extern ATerm SDF_patternGroupListSingle;
extern ATerm SDF_patternPriorityAssoc;
extern ATerm SDF_patternPriorityChain;
extern ATerm SDF_patternGroupAssocGroup;
extern ATerm SDF_patternGroupProdsGroup;
extern ATerm SDF_patternGroupSimpleGroup;
extern ATerm SDF_patternAssociativityAssoc;
extern ATerm SDF_patternAssociativityNonAssoc;
extern ATerm SDF_patternAssociativityRight;
extern ATerm SDF_patternAssociativityLeft;
extern ATerm SDF_patternSymbolTailMany;
extern ATerm SDF_patternSymbolTailSingle;
extern ATerm SDF_patternImportBracket;
extern ATerm SDF_patternImportRenamedModule;
extern ATerm SDF_patternImportModule;
extern ATerm SDF_patternImportListMany;
extern ATerm SDF_patternImportListSingle;
extern ATerm SDF_patternImportListEmpty;
extern ATerm SDF_patternImportsDefault;
extern ATerm SDF_patternImpSectionImports;
extern ATerm SDF_patternAttributeAvoid;
extern ATerm SDF_patternAttributePrefer;
extern ATerm SDF_patternAttributeReject;
extern ATerm SDF_patternAttributeTraverse;
extern ATerm SDF_patternAttributeMemo;
extern ATerm SDF_patternAttributeConstructor;
extern ATerm SDF_patternAttributeCons;
extern ATerm SDF_patternAttributeAtr;
extern ATerm SDF_patternAttributeBracket;
extern ATerm SDF_patternAttributeId;
extern ATerm SDF_patternModuleNameParameterized;
extern ATerm SDF_patternModuleNameUnparameterized;
extern ATerm SDF_patternSectionListMany;
extern ATerm SDF_patternSectionListSingle;
extern ATerm SDF_patternSectionListEmpty;
extern ATerm SDF_patternSectionsDefault;
extern ATerm SDF_patternSectionHiddens;
extern ATerm SDF_patternSectionExports;
extern ATerm SDF_patternImpSectionListMany;
extern ATerm SDF_patternImpSectionListSingle;
extern ATerm SDF_patternImpSectionListEmpty;
extern ATerm SDF_patternModuleModule;
extern ATerm SDF_patternModuleListMany;
extern ATerm SDF_patternModuleListSingle;
extern ATerm SDF_patternModuleListEmpty;
extern ATerm SDF_patternDefinitionDefault;
extern ATerm SDF_patternModuleIdWordSlashWord;
extern ATerm SDF_patternModuleIdSlashWord;
extern ATerm SDF_patternModuleIdWord;
extern ATerm SDF_patternModuleWordWord;
extern ATerm SDF_patternProductionListMany;
extern ATerm SDF_patternProductionListSingle;
extern ATerm SDF_patternProductionListEmpty;
extern ATerm SDF_patternProductionsDefault;
extern ATerm SDF_patternProductionProdFun;
extern ATerm SDF_patternProductionProd;
extern ATerm SDF_patternAttributeListMany;
extern ATerm SDF_patternAttributeListSingle;
extern ATerm SDF_patternAttributeListEmpty;
extern ATerm SDF_patternAttributesNoAttrs;
extern ATerm SDF_patternAttributesAttrs;
extern ATerm SDF_patternSDFDefinition;
extern ATerm SDF_patternGrammarBracket;
extern ATerm SDF_patternGrammarConcGrammars;
extern ATerm SDF_patternGrammarEmptyGrammar;
extern ATerm SDF_patternGrammarAliases;
extern ATerm SDF_patternGrammarRestrictions;
extern ATerm SDF_patternGrammarSorts;
extern ATerm SDF_patternGrammarPriorities;
extern ATerm SDF_patternGrammarImpSection;
extern ATerm SDF_patternGrammarLexicalVariables;
extern ATerm SDF_patternGrammarVariables;
extern ATerm SDF_patternGrammarContextFreeSyntax;
extern ATerm SDF_patternGrammarLexicalSyntax;
extern ATerm SDF_patternGrammarSyntax;
extern ATerm SDF_patternGrammarContextFreeRestrictions;
extern ATerm SDF_patternGrammarLexicalRestrictions;
extern ATerm SDF_patternGrammarContextFreePriorities;
extern ATerm SDF_patternGrammarLexicalPriorities;
extern ATerm SDF_patternSymbolBracket;
extern ATerm SDF_patternSymbolLabel;
extern ATerm SDF_patternSymbolLit;
extern ATerm SDF_patternSymbolSort;
extern ATerm SDF_patternSymbolCharClass;
extern ATerm SDF_patternSymbolPerm;
extern ATerm SDF_patternSymbolAlt;
extern ATerm SDF_patternSymbolFunc;
extern ATerm SDF_patternSymbolPair;
extern ATerm SDF_patternSymbolSet;
extern ATerm SDF_patternSymbolIterSepN;
extern ATerm SDF_patternSymbolIterN;
extern ATerm SDF_patternSymbolIterStarSep;
extern ATerm SDF_patternSymbolIterSep;
extern ATerm SDF_patternSymbolIterStar;
extern ATerm SDF_patternSymbolIter;
extern ATerm SDF_patternSymbolOpt;
extern ATerm SDF_patternSymbolSeq;
extern ATerm SDF_patternSymbolEmpty;
extern ATerm SDF_patternSymbolLayout;
extern ATerm SDF_patternSymbolVarsym;
extern ATerm SDF_patternSymbolLex;
extern ATerm SDF_patternSymbolCf;
extern ATerm SDF_patternSymbolFileStart;
extern ATerm SDF_patternSymbolStart;

extern void init_SDF_dict();

#endif /* __SDF_dict_H */
