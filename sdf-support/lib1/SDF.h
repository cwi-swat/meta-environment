#ifndef _SDF_H
#define _SDF_H

/*{{{  includes */

#include <aterm1.h>
#include "SDF_dict.h"

/*}}}  */

/*{{{  prologue */

typedef ATerm SDFLayout;
typedef ATerm SDFSeparator;
typedef ATerm SDFLexical;

/*}}}  */
/*{{{  typedefs */

typedef struct _SDFSymbol *SDFSymbol;
typedef struct _SDFGrammar *SDFGrammar;
typedef struct _SDFSDF *SDFSDF;
typedef struct _SDFAttributes *SDFAttributes;
typedef struct _SDFAttributeAttributes *SDFAttributeAttributes;
typedef struct _SDFProduction *SDFProduction;
typedef struct _SDFProductions *SDFProductions;
typedef struct _SDFProductionProductions *SDFProductionProductions;
typedef struct _SDFModuleWord *SDFModuleWord;
typedef struct _SDFModuleId *SDFModuleId;
typedef struct _SDFDefinition *SDFDefinition;
typedef struct _SDFModuleModules *SDFModuleModules;
typedef struct _SDFModule *SDFModule;
typedef struct _SDFImpSectionList *SDFImpSectionList;
typedef struct _SDFSection *SDFSection;
typedef struct _SDFSections *SDFSections;
typedef struct _SDFSectionList *SDFSectionList;
typedef struct _SDFModuleName *SDFModuleName;
typedef struct _SDFAttribute *SDFAttribute;
typedef struct _SDFImpSection *SDFImpSection;
typedef struct _SDFImports *SDFImports;
typedef struct _SDFImportList *SDFImportList;
typedef struct _SDFImport *SDFImport;
typedef struct _SDFSymbolTail *SDFSymbolTail;
typedef struct _SDFAssociativity *SDFAssociativity;
typedef struct _SDFGroup *SDFGroup;
typedef struct _SDFPriority *SDFPriority;
typedef struct _SDFGroupGroupp *SDFGroupGroupp;
typedef struct _SDFPriorities *SDFPriorities;
typedef struct _SDFPriorityPrioritys *SDFPriorityPrioritys;
typedef struct _SDFSort *SDFSort;
typedef struct _SDFUQLiteral *SDFUQLiteral;
typedef struct _SDFLiteral *SDFLiteral;
typedef struct _SDFSymbolArguments *SDFSymbolArguments;
typedef struct _SDFLookahead *SDFLookahead;
typedef struct _SDFLookaheads *SDFLookaheads;
typedef struct _SDFLookaheadLookaheads *SDFLookaheadLookaheads;
typedef struct _SDFRestriction *SDFRestriction;
typedef struct _SDFRestrictions *SDFRestrictions;
typedef struct _SDFRestrictionRestrictions *SDFRestrictionRestrictions;
typedef struct _SDFAlias *SDFAlias;
typedef struct _SDFAliases *SDFAliases;
typedef struct _SDFAliasAliass *SDFAliasAliass;
typedef struct _SDFSymbols *SDFSymbols;
typedef struct _SDFSymbolSymbols *SDFSymbolSymbols;
typedef struct _SDFRenamings *SDFRenamings;
typedef struct _SDFRenamingRenamings *SDFRenamingRenamings;
typedef struct _SDFRenaming *SDFRenaming;
typedef struct _SDFNatCon *SDFNatCon;
typedef struct _SDFIntCon *SDFIntCon;
typedef struct _SDFCharRange *SDFCharRange;
typedef struct _SDFCharRanges *SDFCharRanges;
typedef struct _SDFOptCharRanges *SDFOptCharRanges;
typedef struct _SDFCharClass *SDFCharClass;
typedef struct _SDFAlphaNumericalEscChar *SDFAlphaNumericalEscChar;
typedef struct _SDFDecimalEscChar *SDFDecimalEscChar;
typedef struct _SDFEscChar *SDFEscChar;
typedef struct _SDFLChar *SDFLChar;
typedef struct _SDFATerms *SDFATerms;
typedef struct _SDFATermList *SDFATermList;
typedef struct _SDFACon *SDFACon;
typedef struct _SDFAFun *SDFAFun;
typedef struct _SDFATerm *SDFATerm;
typedef struct _SDFAnn *SDFAnn;
typedef struct _SDFTagId *SDFTagId;
typedef struct _SDFNumChar *SDFNumChar;
typedef struct _SDFShortChar *SDFShortChar;
typedef struct _SDFCharacter *SDFCharacter;
typedef struct _SDFOptExp *SDFOptExp;
typedef struct _SDFRealCon *SDFRealCon;

/*}}}  */

void SDFinitSDFApi(void);

SDFSymbol SDFmakeSymbolFromTerm(ATerm t);
ATerm SDFmakeTermFromSymbol(SDFSymbol arg);
SDFGrammar SDFmakeGrammarFromTerm(ATerm t);
ATerm SDFmakeTermFromGrammar(SDFGrammar arg);
SDFSDF SDFmakeSDFFromTerm(ATerm t);
ATerm SDFmakeTermFromSDF(SDFSDF arg);
SDFAttributes SDFmakeAttributesFromTerm(ATerm t);
ATerm SDFmakeTermFromAttributes(SDFAttributes arg);
SDFAttributeAttributes SDFmakeAttributeAttributesFromTerm(ATerm t);
ATerm SDFmakeTermFromAttributeAttributes(SDFAttributeAttributes arg);
SDFProduction SDFmakeProductionFromTerm(ATerm t);
ATerm SDFmakeTermFromProduction(SDFProduction arg);
SDFProductions SDFmakeProductionsFromTerm(ATerm t);
ATerm SDFmakeTermFromProductions(SDFProductions arg);
SDFProductionProductions SDFmakeProductionProductionsFromTerm(ATerm t);
ATerm SDFmakeTermFromProductionProductions(SDFProductionProductions arg);
SDFModuleWord SDFmakeModuleWordFromTerm(ATerm t);
ATerm SDFmakeTermFromModuleWord(SDFModuleWord arg);
SDFModuleId SDFmakeModuleIdFromTerm(ATerm t);
ATerm SDFmakeTermFromModuleId(SDFModuleId arg);
SDFDefinition SDFmakeDefinitionFromTerm(ATerm t);
ATerm SDFmakeTermFromDefinition(SDFDefinition arg);
SDFModuleModules SDFmakeModuleModulesFromTerm(ATerm t);
ATerm SDFmakeTermFromModuleModules(SDFModuleModules arg);
SDFModule SDFmakeModuleFromTerm(ATerm t);
ATerm SDFmakeTermFromModule(SDFModule arg);
SDFImpSectionList SDFmakeImpSectionListFromTerm(ATerm t);
ATerm SDFmakeTermFromImpSectionList(SDFImpSectionList arg);
SDFSection SDFmakeSectionFromTerm(ATerm t);
ATerm SDFmakeTermFromSection(SDFSection arg);
SDFSections SDFmakeSectionsFromTerm(ATerm t);
ATerm SDFmakeTermFromSections(SDFSections arg);
SDFSectionList SDFmakeSectionListFromTerm(ATerm t);
ATerm SDFmakeTermFromSectionList(SDFSectionList arg);
SDFModuleName SDFmakeModuleNameFromTerm(ATerm t);
ATerm SDFmakeTermFromModuleName(SDFModuleName arg);
SDFAttribute SDFmakeAttributeFromTerm(ATerm t);
ATerm SDFmakeTermFromAttribute(SDFAttribute arg);
SDFImpSection SDFmakeImpSectionFromTerm(ATerm t);
ATerm SDFmakeTermFromImpSection(SDFImpSection arg);
SDFImports SDFmakeImportsFromTerm(ATerm t);
ATerm SDFmakeTermFromImports(SDFImports arg);
SDFImportList SDFmakeImportListFromTerm(ATerm t);
ATerm SDFmakeTermFromImportList(SDFImportList arg);
SDFImport SDFmakeImportFromTerm(ATerm t);
ATerm SDFmakeTermFromImport(SDFImport arg);
SDFSymbolTail SDFmakeSymbolTailFromTerm(ATerm t);
ATerm SDFmakeTermFromSymbolTail(SDFSymbolTail arg);
SDFAssociativity SDFmakeAssociativityFromTerm(ATerm t);
ATerm SDFmakeTermFromAssociativity(SDFAssociativity arg);
SDFGroup SDFmakeGroupFromTerm(ATerm t);
ATerm SDFmakeTermFromGroup(SDFGroup arg);
SDFPriority SDFmakePriorityFromTerm(ATerm t);
ATerm SDFmakeTermFromPriority(SDFPriority arg);
SDFGroupGroupp SDFmakeGroupGrouppFromTerm(ATerm t);
ATerm SDFmakeTermFromGroupGroupp(SDFGroupGroupp arg);
SDFPriorities SDFmakePrioritiesFromTerm(ATerm t);
ATerm SDFmakeTermFromPriorities(SDFPriorities arg);
SDFPriorityPrioritys SDFmakePriorityPrioritysFromTerm(ATerm t);
ATerm SDFmakeTermFromPriorityPrioritys(SDFPriorityPrioritys arg);
SDFSort SDFmakeSortFromTerm(ATerm t);
ATerm SDFmakeTermFromSort(SDFSort arg);
SDFUQLiteral SDFmakeUQLiteralFromTerm(ATerm t);
ATerm SDFmakeTermFromUQLiteral(SDFUQLiteral arg);
SDFLiteral SDFmakeLiteralFromTerm(ATerm t);
ATerm SDFmakeTermFromLiteral(SDFLiteral arg);
SDFSymbolArguments SDFmakeSymbolArgumentsFromTerm(ATerm t);
ATerm SDFmakeTermFromSymbolArguments(SDFSymbolArguments arg);
SDFLookahead SDFmakeLookaheadFromTerm(ATerm t);
ATerm SDFmakeTermFromLookahead(SDFLookahead arg);
SDFLookaheads SDFmakeLookaheadsFromTerm(ATerm t);
ATerm SDFmakeTermFromLookaheads(SDFLookaheads arg);
SDFLookaheadLookaheads SDFmakeLookaheadLookaheadsFromTerm(ATerm t);
ATerm SDFmakeTermFromLookaheadLookaheads(SDFLookaheadLookaheads arg);
SDFRestriction SDFmakeRestrictionFromTerm(ATerm t);
ATerm SDFmakeTermFromRestriction(SDFRestriction arg);
SDFRestrictions SDFmakeRestrictionsFromTerm(ATerm t);
ATerm SDFmakeTermFromRestrictions(SDFRestrictions arg);
SDFRestrictionRestrictions SDFmakeRestrictionRestrictionsFromTerm(ATerm t);
ATerm SDFmakeTermFromRestrictionRestrictions(SDFRestrictionRestrictions arg);
SDFAlias SDFmakeAliasFromTerm(ATerm t);
ATerm SDFmakeTermFromAlias(SDFAlias arg);
SDFAliases SDFmakeAliasesFromTerm(ATerm t);
ATerm SDFmakeTermFromAliases(SDFAliases arg);
SDFAliasAliass SDFmakeAliasAliassFromTerm(ATerm t);
ATerm SDFmakeTermFromAliasAliass(SDFAliasAliass arg);
SDFSymbols SDFmakeSymbolsFromTerm(ATerm t);
ATerm SDFmakeTermFromSymbols(SDFSymbols arg);
SDFSymbolSymbols SDFmakeSymbolSymbolsFromTerm(ATerm t);
ATerm SDFmakeTermFromSymbolSymbols(SDFSymbolSymbols arg);
SDFRenamings SDFmakeRenamingsFromTerm(ATerm t);
ATerm SDFmakeTermFromRenamings(SDFRenamings arg);
SDFRenamingRenamings SDFmakeRenamingRenamingsFromTerm(ATerm t);
ATerm SDFmakeTermFromRenamingRenamings(SDFRenamingRenamings arg);
SDFRenaming SDFmakeRenamingFromTerm(ATerm t);
ATerm SDFmakeTermFromRenaming(SDFRenaming arg);
SDFNatCon SDFmakeNatConFromTerm(ATerm t);
ATerm SDFmakeTermFromNatCon(SDFNatCon arg);
SDFIntCon SDFmakeIntConFromTerm(ATerm t);
ATerm SDFmakeTermFromIntCon(SDFIntCon arg);
SDFCharRange SDFmakeCharRangeFromTerm(ATerm t);
ATerm SDFmakeTermFromCharRange(SDFCharRange arg);
SDFCharRanges SDFmakeCharRangesFromTerm(ATerm t);
ATerm SDFmakeTermFromCharRanges(SDFCharRanges arg);
SDFOptCharRanges SDFmakeOptCharRangesFromTerm(ATerm t);
ATerm SDFmakeTermFromOptCharRanges(SDFOptCharRanges arg);
SDFCharClass SDFmakeCharClassFromTerm(ATerm t);
ATerm SDFmakeTermFromCharClass(SDFCharClass arg);
SDFAlphaNumericalEscChar SDFmakeAlphaNumericalEscCharFromTerm(ATerm t);
ATerm SDFmakeTermFromAlphaNumericalEscChar(SDFAlphaNumericalEscChar arg);
SDFDecimalEscChar SDFmakeDecimalEscCharFromTerm(ATerm t);
ATerm SDFmakeTermFromDecimalEscChar(SDFDecimalEscChar arg);
SDFEscChar SDFmakeEscCharFromTerm(ATerm t);
ATerm SDFmakeTermFromEscChar(SDFEscChar arg);
SDFLChar SDFmakeLCharFromTerm(ATerm t);
ATerm SDFmakeTermFromLChar(SDFLChar arg);
SDFATerms SDFmakeATermsFromTerm(ATerm t);
ATerm SDFmakeTermFromATerms(SDFATerms arg);
SDFATermList SDFmakeATermListFromTerm(ATerm t);
ATerm SDFmakeTermFromATermList(SDFATermList arg);
SDFACon SDFmakeAConFromTerm(ATerm t);
ATerm SDFmakeTermFromACon(SDFACon arg);
SDFAFun SDFmakeAFunFromTerm(ATerm t);
ATerm SDFmakeTermFromAFun(SDFAFun arg);
SDFATerm SDFmakeATermFromTerm(ATerm t);
ATerm SDFmakeTermFromATerm(SDFATerm arg);
SDFAnn SDFmakeAnnFromTerm(ATerm t);
ATerm SDFmakeTermFromAnn(SDFAnn arg);
SDFTagId SDFmakeTagIdFromTerm(ATerm t);
ATerm SDFmakeTermFromTagId(SDFTagId arg);
SDFNumChar SDFmakeNumCharFromTerm(ATerm t);
ATerm SDFmakeTermFromNumChar(SDFNumChar arg);
SDFShortChar SDFmakeShortCharFromTerm(ATerm t);
ATerm SDFmakeTermFromShortChar(SDFShortChar arg);
SDFCharacter SDFmakeCharacterFromTerm(ATerm t);
ATerm SDFmakeTermFromCharacter(SDFCharacter arg);
SDFOptExp SDFmakeOptExpFromTerm(ATerm t);
ATerm SDFmakeTermFromOptExp(SDFOptExp arg);
SDFRealCon SDFmakeRealConFromTerm(ATerm t);
ATerm SDFmakeTermFromRealCon(SDFRealCon arg);

SDFSymbol SDFmakeSymbolStart();
SDFSymbol SDFmakeSymbolFileStart();
SDFSymbol SDFmakeSymbolCf(SDFLayout wsAfterLessThan, SDFSymbol symbol, SDFLayout wsAfterSymbol, SDFLayout wsAfterCF);
SDFSymbol SDFmakeSymbolLex(SDFLayout wsAfterLessThan, SDFSymbol symbol, SDFLayout wsAfterSymbol, SDFLayout wsAfterLEX);
SDFSymbol SDFmakeSymbolVarsym(SDFLayout wsAfterLessThan, SDFSymbol symbol, SDFLayout wsAfterSymbol, SDFLayout wsAfterVAR);
SDFSymbol SDFmakeSymbolLayout();
SDFSymbol SDFmakeSymbolEmpty(SDFLayout wsAfterParenOpen);
SDFSymbol SDFmakeSymbolSeq(SDFLayout wsAfterParenOpen, SDFSymbol head, SDFLayout wsAfterHead, SDFSymbolTail tail, SDFLayout wsAfterTail);
SDFSymbol SDFmakeSymbolOpt(SDFSymbol symbol, SDFLayout wsAfterSymbol);
SDFSymbol SDFmakeSymbolIter(SDFSymbol symbol, SDFLayout wsAfterSymbol);
SDFSymbol SDFmakeSymbolIterStar(SDFSymbol symbol, SDFLayout wsAfterSymbol);
SDFSymbol SDFmakeSymbolIterSep(SDFLayout wsAfterBraceOpen, SDFSymbol symbol, SDFLayout wsAfterSymbol, SDFSymbol sep, SDFLayout wsAfterSep, SDFLayout wsAfterBraceClose);
SDFSymbol SDFmakeSymbolIterStarSep(SDFLayout wsAfterBraceOpen, SDFSymbol symbol, SDFLayout wsAfterSymbol, SDFSymbol sep, SDFLayout wsAfterSep, SDFLayout wsAfterBraceClose);
SDFSymbol SDFmakeSymbolIterN(SDFSymbol symbol, SDFLayout wsAfterSymbol, SDFNatCon n, SDFLayout wsAfterN);
SDFSymbol SDFmakeSymbolIterSepN(SDFLayout wsAfterBraceOpen, SDFSymbol symbol, SDFLayout wsAfterSymbol, SDFSymbol sep, SDFLayout wsAfterSep, SDFLayout wsAfterBraceClose, SDFNatCon n, SDFLayout wsAfterN);
SDFSymbol SDFmakeSymbolSet(SDFLayout wsAfterSet, SDFLayout wsAfterBracketOpen, SDFSymbol symbol, SDFLayout wsAfterSymbol);
SDFSymbol SDFmakeSymbolPair(SDFSymbol left, SDFLayout wsAfterLeft, SDFLayout wsAfterHash, SDFSymbol right);
SDFSymbol SDFmakeSymbolFunc(SDFLayout wsAfterParenOpen, SDFSymbols arguments, SDFLayout wsAfterArguments, SDFLayout wsAfterEqualsGreaterThan, SDFSymbol results, SDFLayout wsAfterResults);
SDFSymbol SDFmakeSymbolAlt(SDFSymbol left, SDFLayout wsAfterLeft, SDFLayout wsAfterBar, SDFSymbol right);
SDFSymbol SDFmakeSymbolPerm(SDFLayout wsAfterLessThanLessThan, SDFSymbols symbols, SDFLayout wsAfterSymbols);
SDFSymbol SDFmakeSymbolCharClass(SDFCharClass charClass);
SDFSymbol SDFmakeSymbolSort(SDFSort sort);
SDFSymbol SDFmakeSymbolLit(SDFLiteral literal);
SDFSymbol SDFmakeSymbolLabel(SDFLiteral label, SDFLayout wsAfterLabel, SDFLayout wsAfterColon, SDFSymbol symbol);
SDFSymbol SDFmakeSymbolBracket(SDFLayout wsAfterParenOpen, SDFSymbol symbol, SDFLayout wsAfterSymbol);
SDFGrammar SDFmakeGrammarLexicalPriorities(SDFLayout wsAfterLexical, SDFLayout wsAfterPriorities, SDFPriorities priorities);
SDFGrammar SDFmakeGrammarContextFreePriorities(SDFLayout wsAfterContextFree, SDFLayout wsAfterPriorities, SDFPriorities priorities);
SDFGrammar SDFmakeGrammarLexicalRestrictions(SDFLayout wsAfterLexical, SDFLayout wsAfterRestrictions, SDFRestrictions restrictions);
SDFGrammar SDFmakeGrammarContextFreeRestrictions(SDFLayout wsAfterContextFree, SDFLayout wsAfterRestrictions, SDFRestrictions restrictions);
SDFGrammar SDFmakeGrammarSyntax(SDFLayout wsAfterSyntax, SDFProductions productions);
SDFGrammar SDFmakeGrammarLexicalSyntax(SDFLayout wsAfterLexical, SDFLayout wsAfterSyntax, SDFProductions productions);
SDFGrammar SDFmakeGrammarContextFreeSyntax(SDFLayout wsAfterContextFree, SDFLayout wsAfterSyntax, SDFProductions productions);
SDFGrammar SDFmakeGrammarVariables(SDFLayout wsAfterVariables, SDFProductions productions);
SDFGrammar SDFmakeGrammarLexicalVariables(SDFLayout wsAfterLexical, SDFLayout wsAfterVariables, SDFProductions productions);
SDFGrammar SDFmakeGrammarImpSection(SDFImpSection impSection);
SDFGrammar SDFmakeGrammarPriorities(SDFLayout wsAfterPriorities, SDFPriorities priorities);
SDFGrammar SDFmakeGrammarSorts(SDFLayout wsAfterSorts, SDFSymbols symbols);
SDFGrammar SDFmakeGrammarRestrictions(SDFLayout wsAfterRestrictions, SDFRestrictions restrictions);
SDFGrammar SDFmakeGrammarAliases(SDFLayout wsAfterAliases, SDFAliases aliases);
SDFGrammar SDFmakeGrammarEmptyGrammar();
SDFGrammar SDFmakeGrammarConcGrammars(SDFGrammar left, SDFLayout wsAfterLeft, SDFGrammar right);
SDFGrammar SDFmakeGrammarBracket(SDFLayout wsAfterParenOpen, SDFGrammar grammar, SDFLayout wsAfterGrammar);
SDFSDF SDFmakeSDFDefinition(SDFLayout wsAfterDefinition, SDFDefinition definition);
SDFAttributes SDFmakeAttributesAttrs(SDFLayout wsAfterBraceOpen, SDFAttributeAttributes attributes, SDFLayout wsAfterAttributes);
SDFAttributes SDFmakeAttributesNoAttrs();
SDFAttributeAttributes SDFmakeAttributeAttributesEmpty();
SDFAttributeAttributes SDFmakeAttributeAttributesSingle(SDFAttribute head);
SDFAttributeAttributes SDFmakeAttributeAttributesMany(SDFAttribute head, SDFLayout wsAfterFirst, SDFSeparator sep, SDFLayout wsAfterSep, SDFAttributeAttributes tail);
SDFProduction SDFmakeProductionProd(SDFSymbols symbols, SDFLayout wsAfterSymbols, SDFLayout wsAfterGreaterThan, SDFSymbol result, SDFLayout wsAfterResult, SDFAttributes attributes);
SDFProduction SDFmakeProductionProdFun(SDFLiteral functionSymbol, SDFLayout wsAfterFunctionSymbol, SDFLayout wsAfterParenOpen, SDFSymbolArguments arguments, SDFLayout wsAfterArguments, SDFLayout wsAfterParenClose, SDFLayout wsAfterGreaterThan, SDFSymbol result, SDFLayout wsAfterResult, SDFAttributes attributes);
SDFProductions SDFmakeProductionsDefault(SDFProductionProductions productions);
SDFProductionProductions SDFmakeProductionProductionsEmpty();
SDFProductionProductions SDFmakeProductionProductionsSingle(SDFProduction head);
SDFProductionProductions SDFmakeProductionProductionsMany(SDFProduction head, SDFLayout wsAfterFirst, SDFProductionProductions tail);
SDFModuleWord SDFmakeModuleWordWord(SDFLexical lex);
SDFModuleId SDFmakeModuleIdWord(SDFLexical lex);
SDFModuleId SDFmakeModuleIdSlashWord(SDFLexical lex);
SDFModuleId SDFmakeModuleIdWordSlashWord(SDFLexical lex);
SDFDefinition SDFmakeDefinitionDefault(SDFModuleModules modules);
SDFModuleModules SDFmakeModuleModulesEmpty();
SDFModuleModules SDFmakeModuleModulesSingle(SDFModule head);
SDFModuleModules SDFmakeModuleModulesMany(SDFModule head, SDFLayout wsAfterFirst, SDFModuleModules tail);
SDFModule SDFmakeModuleModule(SDFLayout wsAfterModule, SDFModuleName moduleName, SDFLayout wsAfterModuleName, SDFImpSectionList list, SDFLayout wsAfterList, SDFSections sections);
SDFImpSectionList SDFmakeImpSectionListEmpty();
SDFImpSectionList SDFmakeImpSectionListSingle(SDFImpSection head);
SDFImpSectionList SDFmakeImpSectionListMany(SDFImpSection head, SDFLayout wsAfterFirst, SDFImpSectionList tail);
SDFSection SDFmakeSectionExports(SDFLayout wsAfterExports, SDFGrammar grammar);
SDFSection SDFmakeSectionHiddens(SDFLayout wsAfterHiddens, SDFGrammar grammar);
SDFSections SDFmakeSectionsDefault(SDFSectionList list);
SDFSectionList SDFmakeSectionListEmpty();
SDFSectionList SDFmakeSectionListSingle(SDFSection head);
SDFSectionList SDFmakeSectionListMany(SDFSection head, SDFLayout wsAfterFirst, SDFSectionList tail);
SDFModuleName SDFmakeModuleNameUnparameterized(SDFModuleId moduleId);
SDFModuleName SDFmakeModuleNameParameterized(SDFModuleId moduleId, SDFLayout wsAfterModuleId, SDFLayout wsAfterBracketOpen, SDFSymbols params, SDFLayout wsAfterParams);
SDFAttribute SDFmakeAttributeId(SDFLayout wsAfterId, SDFLayout wsAfterParenOpen, SDFModuleName moduleName, SDFLayout wsAfterModuleName);
SDFAttribute SDFmakeAttributeBracket();
SDFAttribute SDFmakeAttributeAtr(SDFAssociativity associativity);
SDFAttribute SDFmakeAttributeCons(SDFLayout wsAfterCons, SDFLayout wsAfterParenOpen, SDFATerm aTerm, SDFLayout wsAfterATerm);
SDFAttribute SDFmakeAttributeConstructor();
SDFAttribute SDFmakeAttributeMemo();
SDFAttribute SDFmakeAttributeReject();
SDFAttribute SDFmakeAttributePrefer();
SDFAttribute SDFmakeAttributeAvoid();
SDFImpSection SDFmakeImpSectionImports(SDFLayout wsAfterImports, SDFImports list);
SDFImports SDFmakeImportsDefault(SDFImportList list);
SDFImportList SDFmakeImportListEmpty();
SDFImportList SDFmakeImportListSingle(SDFImport head);
SDFImportList SDFmakeImportListMany(SDFImport head, SDFLayout wsAfterFirst, SDFImportList tail);
SDFImport SDFmakeImportModule(SDFModuleName moduleName);
SDFImport SDFmakeImportRenamedModule(SDFModuleName moduleName, SDFLayout wsAfterModuleName, SDFRenamings renamings);
SDFImport SDFmakeImportBracket(SDFLayout wsAfterParenOpen, SDFImport import, SDFLayout wsAfterImport);
SDFSymbolTail SDFmakeSymbolTailSingle(SDFSymbol head);
SDFSymbolTail SDFmakeSymbolTailMany(SDFSymbol head, SDFLayout wsAfterFirst, SDFSymbolTail tail);
SDFAssociativity SDFmakeAssociativityLeft();
SDFAssociativity SDFmakeAssociativityRight();
SDFAssociativity SDFmakeAssociativityNonAssoc();
SDFAssociativity SDFmakeAssociativityAssoc();
SDFGroup SDFmakeGroupSimpleGroup(SDFProduction production);
SDFGroup SDFmakeGroupProdsGroup(SDFLayout wsAfterBraceOpen, SDFProductions productions, SDFLayout wsAfterProductions);
SDFGroup SDFmakeGroupAssocGroup(SDFLayout wsAfterBraceOpen, SDFAssociativity associativity, SDFLayout wsAfterAssociativity, SDFLayout wsAfterColon, SDFProductions productions, SDFLayout wsAfterProductions);
SDFPriority SDFmakePriorityPriorityChain(SDFGroupGroupp groupp);
SDFPriority SDFmakePriorityPriorityAssoc(SDFGroup left, SDFLayout wsAfterLeft, SDFAssociativity associativity, SDFLayout wsAfterAssociativity, SDFGroup right);
SDFGroupGroupp SDFmakeGroupGrouppSingle(SDFGroup head);
SDFGroupGroupp SDFmakeGroupGrouppMany(SDFGroup head, SDFLayout wsAfterFirst, SDFSeparator sep, SDFLayout wsAfterSep, SDFGroupGroupp tail);
SDFPriorities SDFmakePrioritiesDefault(SDFPriorityPrioritys prioritys);
SDFPriorityPrioritys SDFmakePriorityPrioritysEmpty();
SDFPriorityPrioritys SDFmakePriorityPrioritysSingle(SDFPriority head);
SDFPriorityPrioritys SDFmakePriorityPrioritysMany(SDFPriority head, SDFLayout wsAfterFirst, SDFSeparator sep, SDFLayout wsAfterSep, SDFPriorityPrioritys tail);
SDFSort SDFmakeSortOneChar(SDFLexical lex);
SDFSort SDFmakeSortMoreChars(SDFLexical lex);
SDFUQLiteral SDFmakeUQLiteralOneChar(SDFLexical lex);
SDFUQLiteral SDFmakeUQLiteralMoreChars(SDFLexical lex);
SDFLiteral SDFmakeLiteralUqlit(SDFUQLiteral uQLiteral);
SDFLiteral SDFmakeLiteralQuoted(SDFLexical lex);
SDFSymbolArguments SDFmakeSymbolArgumentsEmpty();
SDFSymbolArguments SDFmakeSymbolArgumentsSingle(SDFSymbol head);
SDFSymbolArguments SDFmakeSymbolArgumentsMany(SDFSymbol head, SDFLayout wsAfterFirst, SDFSeparator sep, SDFLayout wsAfterSep, SDFSymbolArguments tail);
SDFLookahead SDFmakeLookaheadCharClass(SDFCharClass charClass);
SDFLookahead SDFmakeLookaheadSeq(SDFCharClass head, SDFLayout wsAfterHead, SDFLayout wsAfterPeriod, SDFLookaheads tail);
SDFLookaheads SDFmakeLookaheadsSingle(SDFLookahead lookahead);
SDFLookaheads SDFmakeLookaheadsAlt(SDFLookaheads left, SDFLayout wsAfterLeft, SDFLayout wsAfterBar, SDFLookaheads right);
SDFLookaheads SDFmakeLookaheadsBracket(SDFLayout wsAfterParenOpen, SDFLookaheads lookaheads, SDFLayout wsAfterLookaheads);
SDFLookaheads SDFmakeLookaheadsList(SDFLayout wsAfterBracketOpenBracketOpen, SDFLookaheads lookaheads, SDFLayout wsAfterLookaheads);
SDFLookaheadLookaheads SDFmakeLookaheadLookaheadsEmpty();
SDFLookaheadLookaheads SDFmakeLookaheadLookaheadsSingle(SDFLookahead head);
SDFLookaheadLookaheads SDFmakeLookaheadLookaheadsMany(SDFLookahead head, SDFLayout wsAfterFirst, SDFSeparator sep, SDFLayout wsAfterSep, SDFLookaheadLookaheads tail);
SDFRestriction SDFmakeRestrictionFollow(SDFSymbols symbols, SDFLayout wsAfterSymbols, SDFLayout wsAfterSlash, SDFLookaheads lookaheads);
SDFRestrictions SDFmakeRestrictionsDefault(SDFRestrictionRestrictions restrictions);
SDFRestrictionRestrictions SDFmakeRestrictionRestrictionsEmpty();
SDFRestrictionRestrictions SDFmakeRestrictionRestrictionsSingle(SDFRestriction head);
SDFRestrictionRestrictions SDFmakeRestrictionRestrictionsMany(SDFRestriction head, SDFLayout wsAfterFirst, SDFRestrictionRestrictions tail);
SDFAlias SDFmakeAliasAlias(SDFSymbol symbol, SDFLayout wsAfterSymbol, SDFLayout wsAfterArrow, SDFSymbol alias);
SDFAliases SDFmakeAliasesDefault(SDFAliasAliass aliass);
SDFAliasAliass SDFmakeAliasAliassEmpty();
SDFAliasAliass SDFmakeAliasAliassSingle(SDFAlias head);
SDFAliasAliass SDFmakeAliasAliassMany(SDFAlias head, SDFLayout wsAfterFirst, SDFAliasAliass tail);
SDFSymbols SDFmakeSymbolsDefault(SDFSymbolSymbols symbols);
SDFSymbolSymbols SDFmakeSymbolSymbolsEmpty();
SDFSymbolSymbols SDFmakeSymbolSymbolsSingle(SDFSymbol head);
SDFSymbolSymbols SDFmakeSymbolSymbolsMany(SDFSymbol head, SDFLayout wsAfterFirst, SDFSymbolSymbols tail);
SDFRenamings SDFmakeRenamingsRenamings(SDFLayout wsAfterBracketOpen, SDFRenamingRenamings renamings, SDFLayout wsAfterRenamings);
SDFRenamingRenamings SDFmakeRenamingRenamingsEmpty();
SDFRenamingRenamings SDFmakeRenamingRenamingsSingle(SDFRenaming head);
SDFRenamingRenamings SDFmakeRenamingRenamingsMany(SDFRenaming head, SDFLayout wsAfterFirst, SDFRenamingRenamings tail);
SDFRenaming SDFmakeRenamingSymbol(SDFSymbol from, SDFLayout wsAfterFrom, SDFLayout wsAfterEqualsGreaterThan, SDFSymbol to);
SDFRenaming SDFmakeRenamingProduction(SDFSymbol from, SDFLayout wsAfterFrom, SDFLayout wsAfterEqualsGreaterThan, SDFSymbol to);
SDFNatCon SDFmakeNatConDigits(SDFLexical lex);
SDFIntCon SDFmakeIntConNatural(SDFNatCon natCon);
SDFIntCon SDFmakeIntConPositive(SDFLayout wsAfterPos, SDFNatCon natCon);
SDFIntCon SDFmakeIntConNegative(SDFLayout wsAfterNeg, SDFNatCon natCon);
SDFCharRange SDFmakeCharRangeDefault(SDFCharacter character);
SDFCharRange SDFmakeCharRangeRange(SDFCharacter start, SDFLayout wsAfterStart, SDFLayout wsAfter, SDFCharacter end);
SDFCharRanges SDFmakeCharRangesDefault(SDFCharRange charRange);
SDFCharRanges SDFmakeCharRangesConc(SDFCharRanges left, SDFLayout wsAfterLeft, SDFCharRanges right);
SDFCharRanges SDFmakeCharRangesBracket(SDFLayout wsAfterParenOpen, SDFCharRanges charRanges, SDFLayout wsAfterCharRanges);
SDFOptCharRanges SDFmakeOptCharRangesAbsent();
SDFOptCharRanges SDFmakeOptCharRangesPresent(SDFCharRanges charRanges);
SDFCharClass SDFmakeCharClassSimpleCharclass(SDFLayout wsAfterBracketOpen, SDFOptCharRanges optCharRanges, SDFLayout wsAfterOptCharRanges);
SDFCharClass SDFmakeCharClassComp(SDFLayout wsAfterTilde, SDFCharClass charClass);
SDFCharClass SDFmakeCharClassDiff(SDFCharClass left, SDFLayout wsAfterLeft, SDFLayout wsAfterSlash, SDFCharClass right);
SDFCharClass SDFmakeCharClassIsect(SDFCharClass left, SDFLayout wsAfterLeft, SDFLayout wsAfterSlashBackslash, SDFCharClass right);
SDFCharClass SDFmakeCharClassUnion(SDFCharClass left, SDFLayout wsAfterLeft, SDFLayout wsAfterBackslashSlash, SDFCharClass right);
SDFCharClass SDFmakeCharClassBracket(SDFLayout wsAfterParenOpen, SDFCharClass charClass, SDFLayout wsAfterCharClass);
SDFAlphaNumericalEscChar SDFmakeAlphaNumericalEscCharDefault(SDFLexical lex);
SDFDecimalEscChar SDFmakeDecimalEscCharDec0_199(SDFLexical lex);
SDFDecimalEscChar SDFmakeDecimalEscCharDec200_249(SDFLexical lex);
SDFDecimalEscChar SDFmakeDecimalEscCharDec250_255(SDFLexical lex);
SDFEscChar SDFmakeEscCharAlphaNumeric(SDFLexical lex);
SDFEscChar SDFmakeEscCharDecimal(SDFLexical lex);
SDFLChar SDFmakeLCharNormal(SDFLexical lex);
SDFLChar SDFmakeLCharEscaped(SDFLexical lex);
SDFATerms SDFmakeATermsAterm(SDFATerm aTerm);
SDFATerms SDFmakeATermsCons(SDFATerm head, SDFLayout wsAfterHead, SDFLayout wsAfterComma, SDFATerms tail);
SDFATermList SDFmakeATermListEmpty(SDFLayout wsAfterBracketOpen);
SDFATermList SDFmakeATermListNotEmpty(SDFLayout wsAfterBracketOpen, SDFATerms aTerms, SDFLayout wsAfterATerms);
SDFACon SDFmakeAConInt(SDFIntCon intCon);
SDFACon SDFmakeAConReal(SDFRealCon realCon);
SDFAFun SDFmakeAFunDefault(SDFLiteral literal);
SDFATerm SDFmakeATermConstant(SDFACon aCon);
SDFATerm SDFmakeATermList(SDFATermList aTermList);
SDFATerm SDFmakeATermFun(SDFAFun aFun);
SDFATerm SDFmakeATermAppl(SDFAFun aFun, SDFLayout wsAfterAFun, SDFLayout wsAfterParenOpen, SDFATerms args, SDFLayout wsAfterArgs);
SDFATerm SDFmakeATermAnnotatedConstant(SDFACon aCon, SDFLayout wsAfterACon, SDFAnn ann);
SDFATerm SDFmakeATermAnnotatedList(SDFATermList aTermList, SDFLayout wsAfterATermList, SDFAnn ann);
SDFATerm SDFmakeATermAnnotatedFun(SDFAFun aFun, SDFLayout wsAfterAFun, SDFAnn ann);
SDFATerm SDFmakeATermAnnotatedAppl(SDFAFun aFun, SDFLayout wsAfterAFun, SDFLayout wsAfterParenOpen, SDFATerms args, SDFLayout wsAfterArgs, SDFLayout wsAfterParenClose, SDFAnn ann);
SDFAnn SDFmakeAnnAnnotation(SDFLayout wsAfterBraceOpen, SDFATerms aTerms, SDFLayout wsAfterATerms);
SDFTagId SDFmakeTagIdDefault(SDFLexical lex);
SDFTagId SDFmakeTagIdEmpty();
SDFNumChar SDFmakeNumCharDigits(SDFLexical lex);
SDFShortChar SDFmakeShortCharRegular(SDFLexical lex);
SDFShortChar SDFmakeShortCharEscaped(SDFLexical lex);
SDFCharacter SDFmakeCharacterNumeric(SDFNumChar numChar);
SDFCharacter SDFmakeCharacterShort(SDFShortChar shortChar);
SDFCharacter SDFmakeCharacterTop();
SDFCharacter SDFmakeCharacterEof();
SDFOptExp SDFmakeOptExpPresent(SDFLayout wsAfterE, SDFIntCon intCon);
SDFOptExp SDFmakeOptExpAbsent();
SDFRealCon SDFmakeRealConRealCon(SDFIntCon intCon, SDFLayout wsAfterIntCon, SDFLayout wsAfterPeriod, SDFNatCon natCon, SDFLayout wsAfterNatCon, SDFOptExp optExp);

/*{{{  SDFSymbol accessor prototypes */

ATbool SDFisValidSymbol(SDFSymbol arg);
ATbool SDFisSymbolStart(SDFSymbol arg);
ATbool SDFisSymbolFileStart(SDFSymbol arg);
ATbool SDFisSymbolCf(SDFSymbol arg);
ATbool SDFisSymbolLex(SDFSymbol arg);
ATbool SDFisSymbolVarsym(SDFSymbol arg);
ATbool SDFisSymbolLayout(SDFSymbol arg);
ATbool SDFisSymbolEmpty(SDFSymbol arg);
ATbool SDFisSymbolSeq(SDFSymbol arg);
ATbool SDFisSymbolOpt(SDFSymbol arg);
ATbool SDFisSymbolIter(SDFSymbol arg);
ATbool SDFisSymbolIterStar(SDFSymbol arg);
ATbool SDFisSymbolIterSep(SDFSymbol arg);
ATbool SDFisSymbolIterStarSep(SDFSymbol arg);
ATbool SDFisSymbolIterN(SDFSymbol arg);
ATbool SDFisSymbolIterSepN(SDFSymbol arg);
ATbool SDFisSymbolSet(SDFSymbol arg);
ATbool SDFisSymbolPair(SDFSymbol arg);
ATbool SDFisSymbolFunc(SDFSymbol arg);
ATbool SDFisSymbolAlt(SDFSymbol arg);
ATbool SDFisSymbolPerm(SDFSymbol arg);
ATbool SDFisSymbolCharClass(SDFSymbol arg);
ATbool SDFisSymbolSort(SDFSymbol arg);
ATbool SDFisSymbolLit(SDFSymbol arg);
ATbool SDFisSymbolLabel(SDFSymbol arg);
ATbool SDFisSymbolBracket(SDFSymbol arg);
ATbool SDFhasSymbolWsAfterLessThanLessThan(SDFSymbol arg);
SDFLayout SDFgetSymbolWsAfterLessThanLessThan(SDFSymbol arg);
SDFSymbol SDFsetSymbolWsAfterLessThanLessThan(SDFSymbol arg, SDFLayout wsAfterLessThanLessThan);
ATbool SDFhasSymbolRight(SDFSymbol arg);
SDFSymbol SDFgetSymbolRight(SDFSymbol arg);
SDFSymbol SDFsetSymbolRight(SDFSymbol arg, SDFSymbol right);
ATbool SDFhasSymbolWsAfterLeft(SDFSymbol arg);
SDFLayout SDFgetSymbolWsAfterLeft(SDFSymbol arg);
SDFSymbol SDFsetSymbolWsAfterLeft(SDFSymbol arg, SDFLayout wsAfterLeft);
ATbool SDFhasSymbolWsAfterParenOpen(SDFSymbol arg);
SDFLayout SDFgetSymbolWsAfterParenOpen(SDFSymbol arg);
SDFSymbol SDFsetSymbolWsAfterParenOpen(SDFSymbol arg, SDFLayout wsAfterParenOpen);
ATbool SDFhasSymbolWsAfterArguments(SDFSymbol arg);
SDFLayout SDFgetSymbolWsAfterArguments(SDFSymbol arg);
SDFSymbol SDFsetSymbolWsAfterArguments(SDFSymbol arg, SDFLayout wsAfterArguments);
ATbool SDFhasSymbolWsAfterResults(SDFSymbol arg);
SDFLayout SDFgetSymbolWsAfterResults(SDFSymbol arg);
SDFSymbol SDFsetSymbolWsAfterResults(SDFSymbol arg, SDFLayout wsAfterResults);
ATbool SDFhasSymbolWsAfterHash(SDFSymbol arg);
SDFLayout SDFgetSymbolWsAfterHash(SDFSymbol arg);
SDFSymbol SDFsetSymbolWsAfterHash(SDFSymbol arg, SDFLayout wsAfterHash);
ATbool SDFhasSymbolWsAfterCF(SDFSymbol arg);
SDFLayout SDFgetSymbolWsAfterCF(SDFSymbol arg);
SDFSymbol SDFsetSymbolWsAfterCF(SDFSymbol arg, SDFLayout wsAfterCF);
ATbool SDFhasSymbolSort(SDFSymbol arg);
SDFSort SDFgetSymbolSort(SDFSymbol arg);
SDFSymbol SDFsetSymbolSort(SDFSymbol arg, SDFSort sort);
ATbool SDFhasSymbolWsAfterBraceClose(SDFSymbol arg);
SDFLayout SDFgetSymbolWsAfterBraceClose(SDFSymbol arg);
SDFSymbol SDFsetSymbolWsAfterBraceClose(SDFSymbol arg, SDFLayout wsAfterBraceClose);
ATbool SDFhasSymbolWsAfterBar(SDFSymbol arg);
SDFLayout SDFgetSymbolWsAfterBar(SDFSymbol arg);
SDFSymbol SDFsetSymbolWsAfterBar(SDFSymbol arg, SDFLayout wsAfterBar);
ATbool SDFhasSymbolWsAfterBraceOpen(SDFSymbol arg);
SDFLayout SDFgetSymbolWsAfterBraceOpen(SDFSymbol arg);
SDFSymbol SDFsetSymbolWsAfterBraceOpen(SDFSymbol arg, SDFLayout wsAfterBraceOpen);
ATbool SDFhasSymbolArguments(SDFSymbol arg);
SDFSymbols SDFgetSymbolArguments(SDFSymbol arg);
SDFSymbol SDFsetSymbolArguments(SDFSymbol arg, SDFSymbols arguments);
ATbool SDFhasSymbolWsAfterSymbols(SDFSymbol arg);
SDFLayout SDFgetSymbolWsAfterSymbols(SDFSymbol arg);
SDFSymbol SDFsetSymbolWsAfterSymbols(SDFSymbol arg, SDFLayout wsAfterSymbols);
ATbool SDFhasSymbolWsAfterSep(SDFSymbol arg);
SDFLayout SDFgetSymbolWsAfterSep(SDFSymbol arg);
SDFSymbol SDFsetSymbolWsAfterSep(SDFSymbol arg, SDFLayout wsAfterSep);
ATbool SDFhasSymbolTail(SDFSymbol arg);
SDFSymbolTail SDFgetSymbolTail(SDFSymbol arg);
SDFSymbol SDFsetSymbolTail(SDFSymbol arg, SDFSymbolTail tail);
ATbool SDFhasSymbolHead(SDFSymbol arg);
SDFSymbol SDFgetSymbolHead(SDFSymbol arg);
SDFSymbol SDFsetSymbolHead(SDFSymbol arg, SDFSymbol head);
ATbool SDFhasSymbolWsAfterSymbol(SDFSymbol arg);
SDFLayout SDFgetSymbolWsAfterSymbol(SDFSymbol arg);
SDFSymbol SDFsetSymbolWsAfterSymbol(SDFSymbol arg, SDFLayout wsAfterSymbol);
ATbool SDFhasSymbolWsAfterN(SDFSymbol arg);
SDFLayout SDFgetSymbolWsAfterN(SDFSymbol arg);
SDFSymbol SDFsetSymbolWsAfterN(SDFSymbol arg, SDFLayout wsAfterN);
ATbool SDFhasSymbolSymbol(SDFSymbol arg);
SDFSymbol SDFgetSymbolSymbol(SDFSymbol arg);
SDFSymbol SDFsetSymbolSymbol(SDFSymbol arg, SDFSymbol symbol);
ATbool SDFhasSymbolLiteral(SDFSymbol arg);
SDFLiteral SDFgetSymbolLiteral(SDFSymbol arg);
SDFSymbol SDFsetSymbolLiteral(SDFSymbol arg, SDFLiteral literal);
ATbool SDFhasSymbolResults(SDFSymbol arg);
SDFSymbol SDFgetSymbolResults(SDFSymbol arg);
SDFSymbol SDFsetSymbolResults(SDFSymbol arg, SDFSymbol results);
ATbool SDFhasSymbolCharClass(SDFSymbol arg);
SDFCharClass SDFgetSymbolCharClass(SDFSymbol arg);
SDFSymbol SDFsetSymbolCharClass(SDFSymbol arg, SDFCharClass charClass);
ATbool SDFhasSymbolWsAfterBracketOpen(SDFSymbol arg);
SDFLayout SDFgetSymbolWsAfterBracketOpen(SDFSymbol arg);
SDFSymbol SDFsetSymbolWsAfterBracketOpen(SDFSymbol arg, SDFLayout wsAfterBracketOpen);
ATbool SDFhasSymbolWsAfterTail(SDFSymbol arg);
SDFLayout SDFgetSymbolWsAfterTail(SDFSymbol arg);
SDFSymbol SDFsetSymbolWsAfterTail(SDFSymbol arg, SDFLayout wsAfterTail);
ATbool SDFhasSymbolWsAfterHead(SDFSymbol arg);
SDFLayout SDFgetSymbolWsAfterHead(SDFSymbol arg);
SDFSymbol SDFsetSymbolWsAfterHead(SDFSymbol arg, SDFLayout wsAfterHead);
ATbool SDFhasSymbolWsAfterEqualsGreaterThan(SDFSymbol arg);
SDFLayout SDFgetSymbolWsAfterEqualsGreaterThan(SDFSymbol arg);
SDFSymbol SDFsetSymbolWsAfterEqualsGreaterThan(SDFSymbol arg, SDFLayout wsAfterEqualsGreaterThan);
ATbool SDFhasSymbolSep(SDFSymbol arg);
SDFSymbol SDFgetSymbolSep(SDFSymbol arg);
SDFSymbol SDFsetSymbolSep(SDFSymbol arg, SDFSymbol sep);
ATbool SDFhasSymbolSymbols(SDFSymbol arg);
SDFSymbols SDFgetSymbolSymbols(SDFSymbol arg);
SDFSymbol SDFsetSymbolSymbols(SDFSymbol arg, SDFSymbols symbols);
ATbool SDFhasSymbolWsAfterSet(SDFSymbol arg);
SDFLayout SDFgetSymbolWsAfterSet(SDFSymbol arg);
SDFSymbol SDFsetSymbolWsAfterSet(SDFSymbol arg, SDFLayout wsAfterSet);
ATbool SDFhasSymbolLeft(SDFSymbol arg);
SDFSymbol SDFgetSymbolLeft(SDFSymbol arg);
SDFSymbol SDFsetSymbolLeft(SDFSymbol arg, SDFSymbol left);
ATbool SDFhasSymbolWsAfterLEX(SDFSymbol arg);
SDFLayout SDFgetSymbolWsAfterLEX(SDFSymbol arg);
SDFSymbol SDFsetSymbolWsAfterLEX(SDFSymbol arg, SDFLayout wsAfterLEX);
ATbool SDFhasSymbolLabel(SDFSymbol arg);
SDFLiteral SDFgetSymbolLabel(SDFSymbol arg);
SDFSymbol SDFsetSymbolLabel(SDFSymbol arg, SDFLiteral label);
ATbool SDFhasSymbolN(SDFSymbol arg);
SDFNatCon SDFgetSymbolN(SDFSymbol arg);
SDFSymbol SDFsetSymbolN(SDFSymbol arg, SDFNatCon n);
ATbool SDFhasSymbolWsAfterLessThan(SDFSymbol arg);
SDFLayout SDFgetSymbolWsAfterLessThan(SDFSymbol arg);
SDFSymbol SDFsetSymbolWsAfterLessThan(SDFSymbol arg, SDFLayout wsAfterLessThan);
ATbool SDFhasSymbolWsAfterColon(SDFSymbol arg);
SDFLayout SDFgetSymbolWsAfterColon(SDFSymbol arg);
SDFSymbol SDFsetSymbolWsAfterColon(SDFSymbol arg, SDFLayout wsAfterColon);
ATbool SDFhasSymbolWsAfterLabel(SDFSymbol arg);
SDFLayout SDFgetSymbolWsAfterLabel(SDFSymbol arg);
SDFSymbol SDFsetSymbolWsAfterLabel(SDFSymbol arg, SDFLayout wsAfterLabel);
ATbool SDFhasSymbolWsAfterVAR(SDFSymbol arg);
SDFLayout SDFgetSymbolWsAfterVAR(SDFSymbol arg);
SDFSymbol SDFsetSymbolWsAfterVAR(SDFSymbol arg, SDFLayout wsAfterVAR);

/*}}}  */
/*{{{  SDFGrammar accessor prototypes */

ATbool SDFisValidGrammar(SDFGrammar arg);
ATbool SDFisGrammarLexicalPriorities(SDFGrammar arg);
ATbool SDFisGrammarContextFreePriorities(SDFGrammar arg);
ATbool SDFisGrammarLexicalRestrictions(SDFGrammar arg);
ATbool SDFisGrammarContextFreeRestrictions(SDFGrammar arg);
ATbool SDFisGrammarSyntax(SDFGrammar arg);
ATbool SDFisGrammarLexicalSyntax(SDFGrammar arg);
ATbool SDFisGrammarContextFreeSyntax(SDFGrammar arg);
ATbool SDFisGrammarVariables(SDFGrammar arg);
ATbool SDFisGrammarLexicalVariables(SDFGrammar arg);
ATbool SDFisGrammarImpSection(SDFGrammar arg);
ATbool SDFisGrammarPriorities(SDFGrammar arg);
ATbool SDFisGrammarSorts(SDFGrammar arg);
ATbool SDFisGrammarRestrictions(SDFGrammar arg);
ATbool SDFisGrammarAliases(SDFGrammar arg);
ATbool SDFisGrammarEmptyGrammar(SDFGrammar arg);
ATbool SDFisGrammarConcGrammars(SDFGrammar arg);
ATbool SDFisGrammarBracket(SDFGrammar arg);
ATbool SDFhasGrammarRight(SDFGrammar arg);
SDFGrammar SDFgetGrammarRight(SDFGrammar arg);
SDFGrammar SDFsetGrammarRight(SDFGrammar arg, SDFGrammar right);
ATbool SDFhasGrammarWsAfterLeft(SDFGrammar arg);
SDFLayout SDFgetGrammarWsAfterLeft(SDFGrammar arg);
SDFGrammar SDFsetGrammarWsAfterLeft(SDFGrammar arg, SDFLayout wsAfterLeft);
ATbool SDFhasGrammarWsAfterParenOpen(SDFGrammar arg);
SDFLayout SDFgetGrammarWsAfterParenOpen(SDFGrammar arg);
SDFGrammar SDFsetGrammarWsAfterParenOpen(SDFGrammar arg, SDFLayout wsAfterParenOpen);
ATbool SDFhasGrammarWsAfterSorts(SDFGrammar arg);
SDFLayout SDFgetGrammarWsAfterSorts(SDFGrammar arg);
SDFGrammar SDFsetGrammarWsAfterSorts(SDFGrammar arg, SDFLayout wsAfterSorts);
ATbool SDFhasGrammarWsAfterPriorities(SDFGrammar arg);
SDFLayout SDFgetGrammarWsAfterPriorities(SDFGrammar arg);
SDFGrammar SDFsetGrammarWsAfterPriorities(SDFGrammar arg, SDFLayout wsAfterPriorities);
ATbool SDFhasGrammarWsAfterGrammar(SDFGrammar arg);
SDFLayout SDFgetGrammarWsAfterGrammar(SDFGrammar arg);
SDFGrammar SDFsetGrammarWsAfterGrammar(SDFGrammar arg, SDFLayout wsAfterGrammar);
ATbool SDFhasGrammarAliases(SDFGrammar arg);
SDFAliases SDFgetGrammarAliases(SDFGrammar arg);
SDFGrammar SDFsetGrammarAliases(SDFGrammar arg, SDFAliases aliases);
ATbool SDFhasGrammarWsAfterSyntax(SDFGrammar arg);
SDFLayout SDFgetGrammarWsAfterSyntax(SDFGrammar arg);
SDFGrammar SDFsetGrammarWsAfterSyntax(SDFGrammar arg, SDFLayout wsAfterSyntax);
ATbool SDFhasGrammarPriorities(SDFGrammar arg);
SDFPriorities SDFgetGrammarPriorities(SDFGrammar arg);
SDFGrammar SDFsetGrammarPriorities(SDFGrammar arg, SDFPriorities priorities);
ATbool SDFhasGrammarRestrictions(SDFGrammar arg);
SDFRestrictions SDFgetGrammarRestrictions(SDFGrammar arg);
SDFGrammar SDFsetGrammarRestrictions(SDFGrammar arg, SDFRestrictions restrictions);
ATbool SDFhasGrammarWsAfterRestrictions(SDFGrammar arg);
SDFLayout SDFgetGrammarWsAfterRestrictions(SDFGrammar arg);
SDFGrammar SDFsetGrammarWsAfterRestrictions(SDFGrammar arg, SDFLayout wsAfterRestrictions);
ATbool SDFhasGrammarImpSection(SDFGrammar arg);
SDFImpSection SDFgetGrammarImpSection(SDFGrammar arg);
SDFGrammar SDFsetGrammarImpSection(SDFGrammar arg, SDFImpSection impSection);
ATbool SDFhasGrammarWsAfterLexical(SDFGrammar arg);
SDFLayout SDFgetGrammarWsAfterLexical(SDFGrammar arg);
SDFGrammar SDFsetGrammarWsAfterLexical(SDFGrammar arg, SDFLayout wsAfterLexical);
ATbool SDFhasGrammarGrammar(SDFGrammar arg);
SDFGrammar SDFgetGrammarGrammar(SDFGrammar arg);
SDFGrammar SDFsetGrammarGrammar(SDFGrammar arg, SDFGrammar grammar);
ATbool SDFhasGrammarSymbols(SDFGrammar arg);
SDFSymbols SDFgetGrammarSymbols(SDFGrammar arg);
SDFGrammar SDFsetGrammarSymbols(SDFGrammar arg, SDFSymbols symbols);
ATbool SDFhasGrammarWsAfterVariables(SDFGrammar arg);
SDFLayout SDFgetGrammarWsAfterVariables(SDFGrammar arg);
SDFGrammar SDFsetGrammarWsAfterVariables(SDFGrammar arg, SDFLayout wsAfterVariables);
ATbool SDFhasGrammarLeft(SDFGrammar arg);
SDFGrammar SDFgetGrammarLeft(SDFGrammar arg);
SDFGrammar SDFsetGrammarLeft(SDFGrammar arg, SDFGrammar left);
ATbool SDFhasGrammarWsAfterAliases(SDFGrammar arg);
SDFLayout SDFgetGrammarWsAfterAliases(SDFGrammar arg);
SDFGrammar SDFsetGrammarWsAfterAliases(SDFGrammar arg, SDFLayout wsAfterAliases);
ATbool SDFhasGrammarProductions(SDFGrammar arg);
SDFProductions SDFgetGrammarProductions(SDFGrammar arg);
SDFGrammar SDFsetGrammarProductions(SDFGrammar arg, SDFProductions productions);
ATbool SDFhasGrammarWsAfterContextFree(SDFGrammar arg);
SDFLayout SDFgetGrammarWsAfterContextFree(SDFGrammar arg);
SDFGrammar SDFsetGrammarWsAfterContextFree(SDFGrammar arg, SDFLayout wsAfterContextFree);

/*}}}  */
/*{{{  SDFSDF accessor prototypes */

ATbool SDFisValidSDF(SDFSDF arg);
ATbool SDFisSDFDefinition(SDFSDF arg);
ATbool SDFhasSDFDefinition(SDFSDF arg);
SDFDefinition SDFgetSDFDefinition(SDFSDF arg);
SDFSDF SDFsetSDFDefinition(SDFSDF arg, SDFDefinition definition);
ATbool SDFhasSDFWsAfterDefinition(SDFSDF arg);
SDFLayout SDFgetSDFWsAfterDefinition(SDFSDF arg);
SDFSDF SDFsetSDFWsAfterDefinition(SDFSDF arg, SDFLayout wsAfterDefinition);

/*}}}  */
/*{{{  SDFAttributes accessor prototypes */

ATbool SDFisValidAttributes(SDFAttributes arg);
ATbool SDFisAttributesAttrs(SDFAttributes arg);
ATbool SDFisAttributesNoAttrs(SDFAttributes arg);
ATbool SDFhasAttributesWsAfterBraceOpen(SDFAttributes arg);
SDFLayout SDFgetAttributesWsAfterBraceOpen(SDFAttributes arg);
SDFAttributes SDFsetAttributesWsAfterBraceOpen(SDFAttributes arg, SDFLayout wsAfterBraceOpen);
ATbool SDFhasAttributesAttributes(SDFAttributes arg);
SDFAttributeAttributes SDFgetAttributesAttributes(SDFAttributes arg);
SDFAttributes SDFsetAttributesAttributes(SDFAttributes arg, SDFAttributeAttributes attributes);
ATbool SDFhasAttributesWsAfterAttributes(SDFAttributes arg);
SDFLayout SDFgetAttributesWsAfterAttributes(SDFAttributes arg);
SDFAttributes SDFsetAttributesWsAfterAttributes(SDFAttributes arg, SDFLayout wsAfterAttributes);

/*}}}  */
/*{{{  SDFAttributeAttributes accessor prototypes */

ATbool SDFisValidAttributeAttributes(SDFAttributeAttributes arg);
ATbool SDFisAttributeAttributesEmpty(SDFAttributeAttributes arg);
ATbool SDFisAttributeAttributesSingle(SDFAttributeAttributes arg);
ATbool SDFisAttributeAttributesMany(SDFAttributeAttributes arg);
ATbool SDFhasAttributeAttributesWsAfterFirst(SDFAttributeAttributes arg);
SDFLayout SDFgetAttributeAttributesWsAfterFirst(SDFAttributeAttributes arg);
SDFAttributeAttributes SDFsetAttributeAttributesWsAfterFirst(SDFAttributeAttributes arg, SDFLayout wsAfterFirst);
ATbool SDFhasAttributeAttributesWsAfterSep(SDFAttributeAttributes arg);
SDFLayout SDFgetAttributeAttributesWsAfterSep(SDFAttributeAttributes arg);
SDFAttributeAttributes SDFsetAttributeAttributesWsAfterSep(SDFAttributeAttributes arg, SDFLayout wsAfterSep);
ATbool SDFhasAttributeAttributesTail(SDFAttributeAttributes arg);
SDFAttributeAttributes SDFgetAttributeAttributesTail(SDFAttributeAttributes arg);
SDFAttributeAttributes SDFsetAttributeAttributesTail(SDFAttributeAttributes arg, SDFAttributeAttributes tail);
ATbool SDFhasAttributeAttributesHead(SDFAttributeAttributes arg);
SDFAttribute SDFgetAttributeAttributesHead(SDFAttributeAttributes arg);
SDFAttributeAttributes SDFsetAttributeAttributesHead(SDFAttributeAttributes arg, SDFAttribute head);
ATbool SDFhasAttributeAttributesSep(SDFAttributeAttributes arg);
SDFSeparator SDFgetAttributeAttributesSep(SDFAttributeAttributes arg);
SDFAttributeAttributes SDFsetAttributeAttributesSep(SDFAttributeAttributes arg, SDFSeparator sep);

/*}}}  */
/*{{{  SDFProduction accessor prototypes */

ATbool SDFisValidProduction(SDFProduction arg);
ATbool SDFisProductionProd(SDFProduction arg);
ATbool SDFisProductionProdFun(SDFProduction arg);
ATbool SDFhasProductionWsAfterResult(SDFProduction arg);
SDFLayout SDFgetProductionWsAfterResult(SDFProduction arg);
SDFProduction SDFsetProductionWsAfterResult(SDFProduction arg, SDFLayout wsAfterResult);
ATbool SDFhasProductionWsAfterParenClose(SDFProduction arg);
SDFLayout SDFgetProductionWsAfterParenClose(SDFProduction arg);
SDFProduction SDFsetProductionWsAfterParenClose(SDFProduction arg, SDFLayout wsAfterParenClose);
ATbool SDFhasProductionWsAfterParenOpen(SDFProduction arg);
SDFLayout SDFgetProductionWsAfterParenOpen(SDFProduction arg);
SDFProduction SDFsetProductionWsAfterParenOpen(SDFProduction arg, SDFLayout wsAfterParenOpen);
ATbool SDFhasProductionWsAfterArguments(SDFProduction arg);
SDFLayout SDFgetProductionWsAfterArguments(SDFProduction arg);
SDFProduction SDFsetProductionWsAfterArguments(SDFProduction arg, SDFLayout wsAfterArguments);
ATbool SDFhasProductionResult(SDFProduction arg);
SDFSymbol SDFgetProductionResult(SDFProduction arg);
SDFProduction SDFsetProductionResult(SDFProduction arg, SDFSymbol result);
ATbool SDFhasProductionArguments(SDFProduction arg);
SDFSymbolArguments SDFgetProductionArguments(SDFProduction arg);
SDFProduction SDFsetProductionArguments(SDFProduction arg, SDFSymbolArguments arguments);
ATbool SDFhasProductionWsAfterSymbols(SDFProduction arg);
SDFLayout SDFgetProductionWsAfterSymbols(SDFProduction arg);
SDFProduction SDFsetProductionWsAfterSymbols(SDFProduction arg, SDFLayout wsAfterSymbols);
ATbool SDFhasProductionFunctionSymbol(SDFProduction arg);
SDFLiteral SDFgetProductionFunctionSymbol(SDFProduction arg);
SDFProduction SDFsetProductionFunctionSymbol(SDFProduction arg, SDFLiteral functionSymbol);
ATbool SDFhasProductionAttributes(SDFProduction arg);
SDFAttributes SDFgetProductionAttributes(SDFProduction arg);
SDFProduction SDFsetProductionAttributes(SDFProduction arg, SDFAttributes attributes);
ATbool SDFhasProductionWsAfterGreaterThan(SDFProduction arg);
SDFLayout SDFgetProductionWsAfterGreaterThan(SDFProduction arg);
SDFProduction SDFsetProductionWsAfterGreaterThan(SDFProduction arg, SDFLayout wsAfterGreaterThan);
ATbool SDFhasProductionSymbols(SDFProduction arg);
SDFSymbols SDFgetProductionSymbols(SDFProduction arg);
SDFProduction SDFsetProductionSymbols(SDFProduction arg, SDFSymbols symbols);
ATbool SDFhasProductionWsAfterFunctionSymbol(SDFProduction arg);
SDFLayout SDFgetProductionWsAfterFunctionSymbol(SDFProduction arg);
SDFProduction SDFsetProductionWsAfterFunctionSymbol(SDFProduction arg, SDFLayout wsAfterFunctionSymbol);

/*}}}  */
/*{{{  SDFProductions accessor prototypes */

ATbool SDFisValidProductions(SDFProductions arg);
ATbool SDFisProductionsDefault(SDFProductions arg);
ATbool SDFhasProductionsProductions(SDFProductions arg);
SDFProductionProductions SDFgetProductionsProductions(SDFProductions arg);
SDFProductions SDFsetProductionsProductions(SDFProductions arg, SDFProductionProductions productions);

/*}}}  */
/*{{{  SDFProductionProductions accessor prototypes */

ATbool SDFisValidProductionProductions(SDFProductionProductions arg);
ATbool SDFisProductionProductionsEmpty(SDFProductionProductions arg);
ATbool SDFisProductionProductionsSingle(SDFProductionProductions arg);
ATbool SDFisProductionProductionsMany(SDFProductionProductions arg);
ATbool SDFhasProductionProductionsWsAfterFirst(SDFProductionProductions arg);
SDFLayout SDFgetProductionProductionsWsAfterFirst(SDFProductionProductions arg);
SDFProductionProductions SDFsetProductionProductionsWsAfterFirst(SDFProductionProductions arg, SDFLayout wsAfterFirst);
ATbool SDFhasProductionProductionsTail(SDFProductionProductions arg);
SDFProductionProductions SDFgetProductionProductionsTail(SDFProductionProductions arg);
SDFProductionProductions SDFsetProductionProductionsTail(SDFProductionProductions arg, SDFProductionProductions tail);
ATbool SDFhasProductionProductionsHead(SDFProductionProductions arg);
SDFProduction SDFgetProductionProductionsHead(SDFProductionProductions arg);
SDFProductionProductions SDFsetProductionProductionsHead(SDFProductionProductions arg, SDFProduction head);

/*}}}  */
/*{{{  SDFModuleWord accessor prototypes */

ATbool SDFisValidModuleWord(SDFModuleWord arg);
ATbool SDFisModuleWordWord(SDFModuleWord arg);
ATbool SDFhasModuleWordLex(SDFModuleWord arg);
SDFLexical SDFgetModuleWordLex(SDFModuleWord arg);
SDFModuleWord SDFsetModuleWordLex(SDFModuleWord arg, SDFLexical lex);

/*}}}  */
/*{{{  SDFModuleId accessor prototypes */

ATbool SDFisValidModuleId(SDFModuleId arg);
ATbool SDFisModuleIdWord(SDFModuleId arg);
ATbool SDFisModuleIdSlashWord(SDFModuleId arg);
ATbool SDFisModuleIdWordSlashWord(SDFModuleId arg);
ATbool SDFhasModuleIdLex(SDFModuleId arg);
SDFLexical SDFgetModuleIdLex(SDFModuleId arg);
SDFModuleId SDFsetModuleIdLex(SDFModuleId arg, SDFLexical lex);

/*}}}  */
/*{{{  SDFDefinition accessor prototypes */

ATbool SDFisValidDefinition(SDFDefinition arg);
ATbool SDFisDefinitionDefault(SDFDefinition arg);
ATbool SDFhasDefinitionModules(SDFDefinition arg);
SDFModuleModules SDFgetDefinitionModules(SDFDefinition arg);
SDFDefinition SDFsetDefinitionModules(SDFDefinition arg, SDFModuleModules modules);

/*}}}  */
/*{{{  SDFModuleModules accessor prototypes */

ATbool SDFisValidModuleModules(SDFModuleModules arg);
ATbool SDFisModuleModulesEmpty(SDFModuleModules arg);
ATbool SDFisModuleModulesSingle(SDFModuleModules arg);
ATbool SDFisModuleModulesMany(SDFModuleModules arg);
ATbool SDFhasModuleModulesWsAfterFirst(SDFModuleModules arg);
SDFLayout SDFgetModuleModulesWsAfterFirst(SDFModuleModules arg);
SDFModuleModules SDFsetModuleModulesWsAfterFirst(SDFModuleModules arg, SDFLayout wsAfterFirst);
ATbool SDFhasModuleModulesTail(SDFModuleModules arg);
SDFModuleModules SDFgetModuleModulesTail(SDFModuleModules arg);
SDFModuleModules SDFsetModuleModulesTail(SDFModuleModules arg, SDFModuleModules tail);
ATbool SDFhasModuleModulesHead(SDFModuleModules arg);
SDFModule SDFgetModuleModulesHead(SDFModuleModules arg);
SDFModuleModules SDFsetModuleModulesHead(SDFModuleModules arg, SDFModule head);

/*}}}  */
/*{{{  SDFModule accessor prototypes */

ATbool SDFisValidModule(SDFModule arg);
ATbool SDFisModuleModule(SDFModule arg);
ATbool SDFhasModuleWsAfterList(SDFModule arg);
SDFLayout SDFgetModuleWsAfterList(SDFModule arg);
SDFModule SDFsetModuleWsAfterList(SDFModule arg, SDFLayout wsAfterList);
ATbool SDFhasModuleModuleName(SDFModule arg);
SDFModuleName SDFgetModuleModuleName(SDFModule arg);
SDFModule SDFsetModuleModuleName(SDFModule arg, SDFModuleName moduleName);
ATbool SDFhasModuleWsAfterModule(SDFModule arg);
SDFLayout SDFgetModuleWsAfterModule(SDFModule arg);
SDFModule SDFsetModuleWsAfterModule(SDFModule arg, SDFLayout wsAfterModule);
ATbool SDFhasModuleList(SDFModule arg);
SDFImpSectionList SDFgetModuleList(SDFModule arg);
SDFModule SDFsetModuleList(SDFModule arg, SDFImpSectionList list);
ATbool SDFhasModuleWsAfterModuleName(SDFModule arg);
SDFLayout SDFgetModuleWsAfterModuleName(SDFModule arg);
SDFModule SDFsetModuleWsAfterModuleName(SDFModule arg, SDFLayout wsAfterModuleName);
ATbool SDFhasModuleSections(SDFModule arg);
SDFSections SDFgetModuleSections(SDFModule arg);
SDFModule SDFsetModuleSections(SDFModule arg, SDFSections sections);

/*}}}  */
/*{{{  SDFImpSectionList accessor prototypes */

ATbool SDFisValidImpSectionList(SDFImpSectionList arg);
ATbool SDFisImpSectionListEmpty(SDFImpSectionList arg);
ATbool SDFisImpSectionListSingle(SDFImpSectionList arg);
ATbool SDFisImpSectionListMany(SDFImpSectionList arg);
ATbool SDFhasImpSectionListWsAfterFirst(SDFImpSectionList arg);
SDFLayout SDFgetImpSectionListWsAfterFirst(SDFImpSectionList arg);
SDFImpSectionList SDFsetImpSectionListWsAfterFirst(SDFImpSectionList arg, SDFLayout wsAfterFirst);
ATbool SDFhasImpSectionListTail(SDFImpSectionList arg);
SDFImpSectionList SDFgetImpSectionListTail(SDFImpSectionList arg);
SDFImpSectionList SDFsetImpSectionListTail(SDFImpSectionList arg, SDFImpSectionList tail);
ATbool SDFhasImpSectionListHead(SDFImpSectionList arg);
SDFImpSection SDFgetImpSectionListHead(SDFImpSectionList arg);
SDFImpSectionList SDFsetImpSectionListHead(SDFImpSectionList arg, SDFImpSection head);

/*}}}  */
/*{{{  SDFSection accessor prototypes */

ATbool SDFisValidSection(SDFSection arg);
ATbool SDFisSectionExports(SDFSection arg);
ATbool SDFisSectionHiddens(SDFSection arg);
ATbool SDFhasSectionWsAfterExports(SDFSection arg);
SDFLayout SDFgetSectionWsAfterExports(SDFSection arg);
SDFSection SDFsetSectionWsAfterExports(SDFSection arg, SDFLayout wsAfterExports);
ATbool SDFhasSectionGrammar(SDFSection arg);
SDFGrammar SDFgetSectionGrammar(SDFSection arg);
SDFSection SDFsetSectionGrammar(SDFSection arg, SDFGrammar grammar);
ATbool SDFhasSectionWsAfterHiddens(SDFSection arg);
SDFLayout SDFgetSectionWsAfterHiddens(SDFSection arg);
SDFSection SDFsetSectionWsAfterHiddens(SDFSection arg, SDFLayout wsAfterHiddens);

/*}}}  */
/*{{{  SDFSections accessor prototypes */

ATbool SDFisValidSections(SDFSections arg);
ATbool SDFisSectionsDefault(SDFSections arg);
ATbool SDFhasSectionsList(SDFSections arg);
SDFSectionList SDFgetSectionsList(SDFSections arg);
SDFSections SDFsetSectionsList(SDFSections arg, SDFSectionList list);

/*}}}  */
/*{{{  SDFSectionList accessor prototypes */

ATbool SDFisValidSectionList(SDFSectionList arg);
ATbool SDFisSectionListEmpty(SDFSectionList arg);
ATbool SDFisSectionListSingle(SDFSectionList arg);
ATbool SDFisSectionListMany(SDFSectionList arg);
ATbool SDFhasSectionListWsAfterFirst(SDFSectionList arg);
SDFLayout SDFgetSectionListWsAfterFirst(SDFSectionList arg);
SDFSectionList SDFsetSectionListWsAfterFirst(SDFSectionList arg, SDFLayout wsAfterFirst);
ATbool SDFhasSectionListTail(SDFSectionList arg);
SDFSectionList SDFgetSectionListTail(SDFSectionList arg);
SDFSectionList SDFsetSectionListTail(SDFSectionList arg, SDFSectionList tail);
ATbool SDFhasSectionListHead(SDFSectionList arg);
SDFSection SDFgetSectionListHead(SDFSectionList arg);
SDFSectionList SDFsetSectionListHead(SDFSectionList arg, SDFSection head);

/*}}}  */
/*{{{  SDFModuleName accessor prototypes */

ATbool SDFisValidModuleName(SDFModuleName arg);
ATbool SDFisModuleNameUnparameterized(SDFModuleName arg);
ATbool SDFisModuleNameParameterized(SDFModuleName arg);
ATbool SDFhasModuleNameParams(SDFModuleName arg);
SDFSymbols SDFgetModuleNameParams(SDFModuleName arg);
SDFModuleName SDFsetModuleNameParams(SDFModuleName arg, SDFSymbols params);
ATbool SDFhasModuleNameWsAfterModuleId(SDFModuleName arg);
SDFLayout SDFgetModuleNameWsAfterModuleId(SDFModuleName arg);
SDFModuleName SDFsetModuleNameWsAfterModuleId(SDFModuleName arg, SDFLayout wsAfterModuleId);
ATbool SDFhasModuleNameModuleId(SDFModuleName arg);
SDFModuleId SDFgetModuleNameModuleId(SDFModuleName arg);
SDFModuleName SDFsetModuleNameModuleId(SDFModuleName arg, SDFModuleId moduleId);
ATbool SDFhasModuleNameWsAfterBracketOpen(SDFModuleName arg);
SDFLayout SDFgetModuleNameWsAfterBracketOpen(SDFModuleName arg);
SDFModuleName SDFsetModuleNameWsAfterBracketOpen(SDFModuleName arg, SDFLayout wsAfterBracketOpen);
ATbool SDFhasModuleNameWsAfterParams(SDFModuleName arg);
SDFLayout SDFgetModuleNameWsAfterParams(SDFModuleName arg);
SDFModuleName SDFsetModuleNameWsAfterParams(SDFModuleName arg, SDFLayout wsAfterParams);

/*}}}  */
/*{{{  SDFAttribute accessor prototypes */

ATbool SDFisValidAttribute(SDFAttribute arg);
ATbool SDFisAttributeId(SDFAttribute arg);
ATbool SDFisAttributeBracket(SDFAttribute arg);
ATbool SDFisAttributeAtr(SDFAttribute arg);
ATbool SDFisAttributeCons(SDFAttribute arg);
ATbool SDFisAttributeConstructor(SDFAttribute arg);
ATbool SDFisAttributeMemo(SDFAttribute arg);
ATbool SDFisAttributeReject(SDFAttribute arg);
ATbool SDFisAttributePrefer(SDFAttribute arg);
ATbool SDFisAttributeAvoid(SDFAttribute arg);
ATbool SDFhasAttributeModuleName(SDFAttribute arg);
SDFModuleName SDFgetAttributeModuleName(SDFAttribute arg);
SDFAttribute SDFsetAttributeModuleName(SDFAttribute arg, SDFModuleName moduleName);
ATbool SDFhasAttributeWsAfterParenOpen(SDFAttribute arg);
SDFLayout SDFgetAttributeWsAfterParenOpen(SDFAttribute arg);
SDFAttribute SDFsetAttributeWsAfterParenOpen(SDFAttribute arg, SDFLayout wsAfterParenOpen);
ATbool SDFhasAttributeWsAfterCons(SDFAttribute arg);
SDFLayout SDFgetAttributeWsAfterCons(SDFAttribute arg);
SDFAttribute SDFsetAttributeWsAfterCons(SDFAttribute arg, SDFLayout wsAfterCons);
ATbool SDFhasAttributeATerm(SDFAttribute arg);
SDFATerm SDFgetAttributeATerm(SDFAttribute arg);
SDFAttribute SDFsetAttributeATerm(SDFAttribute arg, SDFATerm aTerm);
ATbool SDFhasAttributeWsAfterATerm(SDFAttribute arg);
SDFLayout SDFgetAttributeWsAfterATerm(SDFAttribute arg);
SDFAttribute SDFsetAttributeWsAfterATerm(SDFAttribute arg, SDFLayout wsAfterATerm);
ATbool SDFhasAttributeAssociativity(SDFAttribute arg);
SDFAssociativity SDFgetAttributeAssociativity(SDFAttribute arg);
SDFAttribute SDFsetAttributeAssociativity(SDFAttribute arg, SDFAssociativity associativity);
ATbool SDFhasAttributeWsAfterId(SDFAttribute arg);
SDFLayout SDFgetAttributeWsAfterId(SDFAttribute arg);
SDFAttribute SDFsetAttributeWsAfterId(SDFAttribute arg, SDFLayout wsAfterId);
ATbool SDFhasAttributeWsAfterModuleName(SDFAttribute arg);
SDFLayout SDFgetAttributeWsAfterModuleName(SDFAttribute arg);
SDFAttribute SDFsetAttributeWsAfterModuleName(SDFAttribute arg, SDFLayout wsAfterModuleName);

/*}}}  */
/*{{{  SDFImpSection accessor prototypes */

ATbool SDFisValidImpSection(SDFImpSection arg);
ATbool SDFisImpSectionImports(SDFImpSection arg);
ATbool SDFhasImpSectionWsAfterImports(SDFImpSection arg);
SDFLayout SDFgetImpSectionWsAfterImports(SDFImpSection arg);
SDFImpSection SDFsetImpSectionWsAfterImports(SDFImpSection arg, SDFLayout wsAfterImports);
ATbool SDFhasImpSectionList(SDFImpSection arg);
SDFImports SDFgetImpSectionList(SDFImpSection arg);
SDFImpSection SDFsetImpSectionList(SDFImpSection arg, SDFImports list);

/*}}}  */
/*{{{  SDFImports accessor prototypes */

ATbool SDFisValidImports(SDFImports arg);
ATbool SDFisImportsDefault(SDFImports arg);
ATbool SDFhasImportsList(SDFImports arg);
SDFImportList SDFgetImportsList(SDFImports arg);
SDFImports SDFsetImportsList(SDFImports arg, SDFImportList list);

/*}}}  */
/*{{{  SDFImportList accessor prototypes */

ATbool SDFisValidImportList(SDFImportList arg);
ATbool SDFisImportListEmpty(SDFImportList arg);
ATbool SDFisImportListSingle(SDFImportList arg);
ATbool SDFisImportListMany(SDFImportList arg);
ATbool SDFhasImportListWsAfterFirst(SDFImportList arg);
SDFLayout SDFgetImportListWsAfterFirst(SDFImportList arg);
SDFImportList SDFsetImportListWsAfterFirst(SDFImportList arg, SDFLayout wsAfterFirst);
ATbool SDFhasImportListTail(SDFImportList arg);
SDFImportList SDFgetImportListTail(SDFImportList arg);
SDFImportList SDFsetImportListTail(SDFImportList arg, SDFImportList tail);
ATbool SDFhasImportListHead(SDFImportList arg);
SDFImport SDFgetImportListHead(SDFImportList arg);
SDFImportList SDFsetImportListHead(SDFImportList arg, SDFImport head);

/*}}}  */
/*{{{  SDFImport accessor prototypes */

ATbool SDFisValidImport(SDFImport arg);
ATbool SDFisImportModule(SDFImport arg);
ATbool SDFisImportRenamedModule(SDFImport arg);
ATbool SDFisImportBracket(SDFImport arg);
ATbool SDFhasImportModuleName(SDFImport arg);
SDFModuleName SDFgetImportModuleName(SDFImport arg);
SDFImport SDFsetImportModuleName(SDFImport arg, SDFModuleName moduleName);
ATbool SDFhasImportWsAfterParenOpen(SDFImport arg);
SDFLayout SDFgetImportWsAfterParenOpen(SDFImport arg);
SDFImport SDFsetImportWsAfterParenOpen(SDFImport arg, SDFLayout wsAfterParenOpen);
ATbool SDFhasImportRenamings(SDFImport arg);
SDFRenamings SDFgetImportRenamings(SDFImport arg);
SDFImport SDFsetImportRenamings(SDFImport arg, SDFRenamings renamings);
ATbool SDFhasImportWsAfterImport(SDFImport arg);
SDFLayout SDFgetImportWsAfterImport(SDFImport arg);
SDFImport SDFsetImportWsAfterImport(SDFImport arg, SDFLayout wsAfterImport);
ATbool SDFhasImportImport(SDFImport arg);
SDFImport SDFgetImportImport(SDFImport arg);
SDFImport SDFsetImportImport(SDFImport arg, SDFImport import);
ATbool SDFhasImportWsAfterModuleName(SDFImport arg);
SDFLayout SDFgetImportWsAfterModuleName(SDFImport arg);
SDFImport SDFsetImportWsAfterModuleName(SDFImport arg, SDFLayout wsAfterModuleName);

/*}}}  */
/*{{{  SDFSymbolTail accessor prototypes */

ATbool SDFisValidSymbolTail(SDFSymbolTail arg);
ATbool SDFisSymbolTailSingle(SDFSymbolTail arg);
ATbool SDFisSymbolTailMany(SDFSymbolTail arg);
ATbool SDFhasSymbolTailWsAfterFirst(SDFSymbolTail arg);
SDFLayout SDFgetSymbolTailWsAfterFirst(SDFSymbolTail arg);
SDFSymbolTail SDFsetSymbolTailWsAfterFirst(SDFSymbolTail arg, SDFLayout wsAfterFirst);
ATbool SDFhasSymbolTailTail(SDFSymbolTail arg);
SDFSymbolTail SDFgetSymbolTailTail(SDFSymbolTail arg);
SDFSymbolTail SDFsetSymbolTailTail(SDFSymbolTail arg, SDFSymbolTail tail);
ATbool SDFhasSymbolTailHead(SDFSymbolTail arg);
SDFSymbol SDFgetSymbolTailHead(SDFSymbolTail arg);
SDFSymbolTail SDFsetSymbolTailHead(SDFSymbolTail arg, SDFSymbol head);

/*}}}  */
/*{{{  SDFAssociativity accessor prototypes */

ATbool SDFisValidAssociativity(SDFAssociativity arg);
ATbool SDFisAssociativityLeft(SDFAssociativity arg);
ATbool SDFisAssociativityRight(SDFAssociativity arg);
ATbool SDFisAssociativityNonAssoc(SDFAssociativity arg);
ATbool SDFisAssociativityAssoc(SDFAssociativity arg);

/*}}}  */
/*{{{  SDFGroup accessor prototypes */

ATbool SDFisValidGroup(SDFGroup arg);
ATbool SDFisGroupSimpleGroup(SDFGroup arg);
ATbool SDFisGroupProdsGroup(SDFGroup arg);
ATbool SDFisGroupAssocGroup(SDFGroup arg);
ATbool SDFhasGroupWsAfterAssociativity(SDFGroup arg);
SDFLayout SDFgetGroupWsAfterAssociativity(SDFGroup arg);
SDFGroup SDFsetGroupWsAfterAssociativity(SDFGroup arg, SDFLayout wsAfterAssociativity);
ATbool SDFhasGroupWsAfterBraceOpen(SDFGroup arg);
SDFLayout SDFgetGroupWsAfterBraceOpen(SDFGroup arg);
SDFGroup SDFsetGroupWsAfterBraceOpen(SDFGroup arg, SDFLayout wsAfterBraceOpen);
ATbool SDFhasGroupProduction(SDFGroup arg);
SDFProduction SDFgetGroupProduction(SDFGroup arg);
SDFGroup SDFsetGroupProduction(SDFGroup arg, SDFProduction production);
ATbool SDFhasGroupAssociativity(SDFGroup arg);
SDFAssociativity SDFgetGroupAssociativity(SDFGroup arg);
SDFGroup SDFsetGroupAssociativity(SDFGroup arg, SDFAssociativity associativity);
ATbool SDFhasGroupProductions(SDFGroup arg);
SDFProductions SDFgetGroupProductions(SDFGroup arg);
SDFGroup SDFsetGroupProductions(SDFGroup arg, SDFProductions productions);
ATbool SDFhasGroupWsAfterProductions(SDFGroup arg);
SDFLayout SDFgetGroupWsAfterProductions(SDFGroup arg);
SDFGroup SDFsetGroupWsAfterProductions(SDFGroup arg, SDFLayout wsAfterProductions);
ATbool SDFhasGroupWsAfterColon(SDFGroup arg);
SDFLayout SDFgetGroupWsAfterColon(SDFGroup arg);
SDFGroup SDFsetGroupWsAfterColon(SDFGroup arg, SDFLayout wsAfterColon);

/*}}}  */
/*{{{  SDFPriority accessor prototypes */

ATbool SDFisValidPriority(SDFPriority arg);
ATbool SDFisPriorityPriorityChain(SDFPriority arg);
ATbool SDFisPriorityPriorityAssoc(SDFPriority arg);
ATbool SDFhasPriorityRight(SDFPriority arg);
SDFGroup SDFgetPriorityRight(SDFPriority arg);
SDFPriority SDFsetPriorityRight(SDFPriority arg, SDFGroup right);
ATbool SDFhasPriorityWsAfterAssociativity(SDFPriority arg);
SDFLayout SDFgetPriorityWsAfterAssociativity(SDFPriority arg);
SDFPriority SDFsetPriorityWsAfterAssociativity(SDFPriority arg, SDFLayout wsAfterAssociativity);
ATbool SDFhasPriorityWsAfterLeft(SDFPriority arg);
SDFLayout SDFgetPriorityWsAfterLeft(SDFPriority arg);
SDFPriority SDFsetPriorityWsAfterLeft(SDFPriority arg, SDFLayout wsAfterLeft);
ATbool SDFhasPriorityGroupp(SDFPriority arg);
SDFGroupGroupp SDFgetPriorityGroupp(SDFPriority arg);
SDFPriority SDFsetPriorityGroupp(SDFPriority arg, SDFGroupGroupp groupp);
ATbool SDFhasPriorityAssociativity(SDFPriority arg);
SDFAssociativity SDFgetPriorityAssociativity(SDFPriority arg);
SDFPriority SDFsetPriorityAssociativity(SDFPriority arg, SDFAssociativity associativity);
ATbool SDFhasPriorityLeft(SDFPriority arg);
SDFGroup SDFgetPriorityLeft(SDFPriority arg);
SDFPriority SDFsetPriorityLeft(SDFPriority arg, SDFGroup left);

/*}}}  */
/*{{{  SDFGroupGroupp accessor prototypes */

ATbool SDFisValidGroupGroupp(SDFGroupGroupp arg);
ATbool SDFisGroupGrouppSingle(SDFGroupGroupp arg);
ATbool SDFisGroupGrouppMany(SDFGroupGroupp arg);
ATbool SDFhasGroupGrouppWsAfterFirst(SDFGroupGroupp arg);
SDFLayout SDFgetGroupGrouppWsAfterFirst(SDFGroupGroupp arg);
SDFGroupGroupp SDFsetGroupGrouppWsAfterFirst(SDFGroupGroupp arg, SDFLayout wsAfterFirst);
ATbool SDFhasGroupGrouppWsAfterSep(SDFGroupGroupp arg);
SDFLayout SDFgetGroupGrouppWsAfterSep(SDFGroupGroupp arg);
SDFGroupGroupp SDFsetGroupGrouppWsAfterSep(SDFGroupGroupp arg, SDFLayout wsAfterSep);
ATbool SDFhasGroupGrouppTail(SDFGroupGroupp arg);
SDFGroupGroupp SDFgetGroupGrouppTail(SDFGroupGroupp arg);
SDFGroupGroupp SDFsetGroupGrouppTail(SDFGroupGroupp arg, SDFGroupGroupp tail);
ATbool SDFhasGroupGrouppHead(SDFGroupGroupp arg);
SDFGroup SDFgetGroupGrouppHead(SDFGroupGroupp arg);
SDFGroupGroupp SDFsetGroupGrouppHead(SDFGroupGroupp arg, SDFGroup head);
ATbool SDFhasGroupGrouppSep(SDFGroupGroupp arg);
SDFSeparator SDFgetGroupGrouppSep(SDFGroupGroupp arg);
SDFGroupGroupp SDFsetGroupGrouppSep(SDFGroupGroupp arg, SDFSeparator sep);

/*}}}  */
/*{{{  SDFPriorities accessor prototypes */

ATbool SDFisValidPriorities(SDFPriorities arg);
ATbool SDFisPrioritiesDefault(SDFPriorities arg);
ATbool SDFhasPrioritiesPrioritys(SDFPriorities arg);
SDFPriorityPrioritys SDFgetPrioritiesPrioritys(SDFPriorities arg);
SDFPriorities SDFsetPrioritiesPrioritys(SDFPriorities arg, SDFPriorityPrioritys prioritys);

/*}}}  */
/*{{{  SDFPriorityPrioritys accessor prototypes */

ATbool SDFisValidPriorityPrioritys(SDFPriorityPrioritys arg);
ATbool SDFisPriorityPrioritysEmpty(SDFPriorityPrioritys arg);
ATbool SDFisPriorityPrioritysSingle(SDFPriorityPrioritys arg);
ATbool SDFisPriorityPrioritysMany(SDFPriorityPrioritys arg);
ATbool SDFhasPriorityPrioritysWsAfterFirst(SDFPriorityPrioritys arg);
SDFLayout SDFgetPriorityPrioritysWsAfterFirst(SDFPriorityPrioritys arg);
SDFPriorityPrioritys SDFsetPriorityPrioritysWsAfterFirst(SDFPriorityPrioritys arg, SDFLayout wsAfterFirst);
ATbool SDFhasPriorityPrioritysWsAfterSep(SDFPriorityPrioritys arg);
SDFLayout SDFgetPriorityPrioritysWsAfterSep(SDFPriorityPrioritys arg);
SDFPriorityPrioritys SDFsetPriorityPrioritysWsAfterSep(SDFPriorityPrioritys arg, SDFLayout wsAfterSep);
ATbool SDFhasPriorityPrioritysTail(SDFPriorityPrioritys arg);
SDFPriorityPrioritys SDFgetPriorityPrioritysTail(SDFPriorityPrioritys arg);
SDFPriorityPrioritys SDFsetPriorityPrioritysTail(SDFPriorityPrioritys arg, SDFPriorityPrioritys tail);
ATbool SDFhasPriorityPrioritysHead(SDFPriorityPrioritys arg);
SDFPriority SDFgetPriorityPrioritysHead(SDFPriorityPrioritys arg);
SDFPriorityPrioritys SDFsetPriorityPrioritysHead(SDFPriorityPrioritys arg, SDFPriority head);
ATbool SDFhasPriorityPrioritysSep(SDFPriorityPrioritys arg);
SDFSeparator SDFgetPriorityPrioritysSep(SDFPriorityPrioritys arg);
SDFPriorityPrioritys SDFsetPriorityPrioritysSep(SDFPriorityPrioritys arg, SDFSeparator sep);

/*}}}  */
/*{{{  SDFSort accessor prototypes */

ATbool SDFisValidSort(SDFSort arg);
ATbool SDFisSortOneChar(SDFSort arg);
ATbool SDFisSortMoreChars(SDFSort arg);
ATbool SDFhasSortLex(SDFSort arg);
SDFLexical SDFgetSortLex(SDFSort arg);
SDFSort SDFsetSortLex(SDFSort arg, SDFLexical lex);

/*}}}  */
/*{{{  SDFUQLiteral accessor prototypes */

ATbool SDFisValidUQLiteral(SDFUQLiteral arg);
ATbool SDFisUQLiteralOneChar(SDFUQLiteral arg);
ATbool SDFisUQLiteralMoreChars(SDFUQLiteral arg);
ATbool SDFhasUQLiteralLex(SDFUQLiteral arg);
SDFLexical SDFgetUQLiteralLex(SDFUQLiteral arg);
SDFUQLiteral SDFsetUQLiteralLex(SDFUQLiteral arg, SDFLexical lex);

/*}}}  */
/*{{{  SDFLiteral accessor prototypes */

ATbool SDFisValidLiteral(SDFLiteral arg);
ATbool SDFisLiteralUqlit(SDFLiteral arg);
ATbool SDFisLiteralQuoted(SDFLiteral arg);
ATbool SDFhasLiteralLex(SDFLiteral arg);
SDFLexical SDFgetLiteralLex(SDFLiteral arg);
SDFLiteral SDFsetLiteralLex(SDFLiteral arg, SDFLexical lex);
ATbool SDFhasLiteralUQLiteral(SDFLiteral arg);
SDFUQLiteral SDFgetLiteralUQLiteral(SDFLiteral arg);
SDFLiteral SDFsetLiteralUQLiteral(SDFLiteral arg, SDFUQLiteral uQLiteral);

/*}}}  */
/*{{{  SDFSymbolArguments accessor prototypes */

ATbool SDFisValidSymbolArguments(SDFSymbolArguments arg);
ATbool SDFisSymbolArgumentsEmpty(SDFSymbolArguments arg);
ATbool SDFisSymbolArgumentsSingle(SDFSymbolArguments arg);
ATbool SDFisSymbolArgumentsMany(SDFSymbolArguments arg);
ATbool SDFhasSymbolArgumentsWsAfterFirst(SDFSymbolArguments arg);
SDFLayout SDFgetSymbolArgumentsWsAfterFirst(SDFSymbolArguments arg);
SDFSymbolArguments SDFsetSymbolArgumentsWsAfterFirst(SDFSymbolArguments arg, SDFLayout wsAfterFirst);
ATbool SDFhasSymbolArgumentsWsAfterSep(SDFSymbolArguments arg);
SDFLayout SDFgetSymbolArgumentsWsAfterSep(SDFSymbolArguments arg);
SDFSymbolArguments SDFsetSymbolArgumentsWsAfterSep(SDFSymbolArguments arg, SDFLayout wsAfterSep);
ATbool SDFhasSymbolArgumentsTail(SDFSymbolArguments arg);
SDFSymbolArguments SDFgetSymbolArgumentsTail(SDFSymbolArguments arg);
SDFSymbolArguments SDFsetSymbolArgumentsTail(SDFSymbolArguments arg, SDFSymbolArguments tail);
ATbool SDFhasSymbolArgumentsHead(SDFSymbolArguments arg);
SDFSymbol SDFgetSymbolArgumentsHead(SDFSymbolArguments arg);
SDFSymbolArguments SDFsetSymbolArgumentsHead(SDFSymbolArguments arg, SDFSymbol head);
ATbool SDFhasSymbolArgumentsSep(SDFSymbolArguments arg);
SDFSeparator SDFgetSymbolArgumentsSep(SDFSymbolArguments arg);
SDFSymbolArguments SDFsetSymbolArgumentsSep(SDFSymbolArguments arg, SDFSeparator sep);

/*}}}  */
/*{{{  SDFLookahead accessor prototypes */

ATbool SDFisValidLookahead(SDFLookahead arg);
ATbool SDFisLookaheadCharClass(SDFLookahead arg);
ATbool SDFisLookaheadSeq(SDFLookahead arg);
ATbool SDFhasLookaheadWsAfterPeriod(SDFLookahead arg);
SDFLayout SDFgetLookaheadWsAfterPeriod(SDFLookahead arg);
SDFLookahead SDFsetLookaheadWsAfterPeriod(SDFLookahead arg, SDFLayout wsAfterPeriod);
ATbool SDFhasLookaheadTail(SDFLookahead arg);
SDFLookaheads SDFgetLookaheadTail(SDFLookahead arg);
SDFLookahead SDFsetLookaheadTail(SDFLookahead arg, SDFLookaheads tail);
ATbool SDFhasLookaheadHead(SDFLookahead arg);
SDFCharClass SDFgetLookaheadHead(SDFLookahead arg);
SDFLookahead SDFsetLookaheadHead(SDFLookahead arg, SDFCharClass head);
ATbool SDFhasLookaheadCharClass(SDFLookahead arg);
SDFCharClass SDFgetLookaheadCharClass(SDFLookahead arg);
SDFLookahead SDFsetLookaheadCharClass(SDFLookahead arg, SDFCharClass charClass);
ATbool SDFhasLookaheadWsAfterHead(SDFLookahead arg);
SDFLayout SDFgetLookaheadWsAfterHead(SDFLookahead arg);
SDFLookahead SDFsetLookaheadWsAfterHead(SDFLookahead arg, SDFLayout wsAfterHead);

/*}}}  */
/*{{{  SDFLookaheads accessor prototypes */

ATbool SDFisValidLookaheads(SDFLookaheads arg);
ATbool SDFisLookaheadsSingle(SDFLookaheads arg);
ATbool SDFisLookaheadsAlt(SDFLookaheads arg);
ATbool SDFisLookaheadsBracket(SDFLookaheads arg);
ATbool SDFisLookaheadsList(SDFLookaheads arg);
ATbool SDFhasLookaheadsRight(SDFLookaheads arg);
SDFLookaheads SDFgetLookaheadsRight(SDFLookaheads arg);
SDFLookaheads SDFsetLookaheadsRight(SDFLookaheads arg, SDFLookaheads right);
ATbool SDFhasLookaheadsLookaheads(SDFLookaheads arg);
SDFLookaheads SDFgetLookaheadsLookaheads(SDFLookaheads arg);
SDFLookaheads SDFsetLookaheadsLookaheads(SDFLookaheads arg, SDFLookaheads lookaheads);
ATbool SDFhasLookaheadsWsAfterLeft(SDFLookaheads arg);
SDFLayout SDFgetLookaheadsWsAfterLeft(SDFLookaheads arg);
SDFLookaheads SDFsetLookaheadsWsAfterLeft(SDFLookaheads arg, SDFLayout wsAfterLeft);
ATbool SDFhasLookaheadsWsAfterParenOpen(SDFLookaheads arg);
SDFLayout SDFgetLookaheadsWsAfterParenOpen(SDFLookaheads arg);
SDFLookaheads SDFsetLookaheadsWsAfterParenOpen(SDFLookaheads arg, SDFLayout wsAfterParenOpen);
ATbool SDFhasLookaheadsWsAfterBracketOpenBracketOpen(SDFLookaheads arg);
SDFLayout SDFgetLookaheadsWsAfterBracketOpenBracketOpen(SDFLookaheads arg);
SDFLookaheads SDFsetLookaheadsWsAfterBracketOpenBracketOpen(SDFLookaheads arg, SDFLayout wsAfterBracketOpenBracketOpen);
ATbool SDFhasLookaheadsLookahead(SDFLookaheads arg);
SDFLookahead SDFgetLookaheadsLookahead(SDFLookaheads arg);
SDFLookaheads SDFsetLookaheadsLookahead(SDFLookaheads arg, SDFLookahead lookahead);
ATbool SDFhasLookaheadsWsAfterBar(SDFLookaheads arg);
SDFLayout SDFgetLookaheadsWsAfterBar(SDFLookaheads arg);
SDFLookaheads SDFsetLookaheadsWsAfterBar(SDFLookaheads arg, SDFLayout wsAfterBar);
ATbool SDFhasLookaheadsLeft(SDFLookaheads arg);
SDFLookaheads SDFgetLookaheadsLeft(SDFLookaheads arg);
SDFLookaheads SDFsetLookaheadsLeft(SDFLookaheads arg, SDFLookaheads left);
ATbool SDFhasLookaheadsWsAfterLookaheads(SDFLookaheads arg);
SDFLayout SDFgetLookaheadsWsAfterLookaheads(SDFLookaheads arg);
SDFLookaheads SDFsetLookaheadsWsAfterLookaheads(SDFLookaheads arg, SDFLayout wsAfterLookaheads);

/*}}}  */
/*{{{  SDFLookaheadLookaheads accessor prototypes */

ATbool SDFisValidLookaheadLookaheads(SDFLookaheadLookaheads arg);
ATbool SDFisLookaheadLookaheadsEmpty(SDFLookaheadLookaheads arg);
ATbool SDFisLookaheadLookaheadsSingle(SDFLookaheadLookaheads arg);
ATbool SDFisLookaheadLookaheadsMany(SDFLookaheadLookaheads arg);
ATbool SDFhasLookaheadLookaheadsWsAfterFirst(SDFLookaheadLookaheads arg);
SDFLayout SDFgetLookaheadLookaheadsWsAfterFirst(SDFLookaheadLookaheads arg);
SDFLookaheadLookaheads SDFsetLookaheadLookaheadsWsAfterFirst(SDFLookaheadLookaheads arg, SDFLayout wsAfterFirst);
ATbool SDFhasLookaheadLookaheadsWsAfterSep(SDFLookaheadLookaheads arg);
SDFLayout SDFgetLookaheadLookaheadsWsAfterSep(SDFLookaheadLookaheads arg);
SDFLookaheadLookaheads SDFsetLookaheadLookaheadsWsAfterSep(SDFLookaheadLookaheads arg, SDFLayout wsAfterSep);
ATbool SDFhasLookaheadLookaheadsTail(SDFLookaheadLookaheads arg);
SDFLookaheadLookaheads SDFgetLookaheadLookaheadsTail(SDFLookaheadLookaheads arg);
SDFLookaheadLookaheads SDFsetLookaheadLookaheadsTail(SDFLookaheadLookaheads arg, SDFLookaheadLookaheads tail);
ATbool SDFhasLookaheadLookaheadsHead(SDFLookaheadLookaheads arg);
SDFLookahead SDFgetLookaheadLookaheadsHead(SDFLookaheadLookaheads arg);
SDFLookaheadLookaheads SDFsetLookaheadLookaheadsHead(SDFLookaheadLookaheads arg, SDFLookahead head);
ATbool SDFhasLookaheadLookaheadsSep(SDFLookaheadLookaheads arg);
SDFSeparator SDFgetLookaheadLookaheadsSep(SDFLookaheadLookaheads arg);
SDFLookaheadLookaheads SDFsetLookaheadLookaheadsSep(SDFLookaheadLookaheads arg, SDFSeparator sep);

/*}}}  */
/*{{{  SDFRestriction accessor prototypes */

ATbool SDFisValidRestriction(SDFRestriction arg);
ATbool SDFisRestrictionFollow(SDFRestriction arg);
ATbool SDFhasRestrictionLookaheads(SDFRestriction arg);
SDFLookaheads SDFgetRestrictionLookaheads(SDFRestriction arg);
SDFRestriction SDFsetRestrictionLookaheads(SDFRestriction arg, SDFLookaheads lookaheads);
ATbool SDFhasRestrictionWsAfterSymbols(SDFRestriction arg);
SDFLayout SDFgetRestrictionWsAfterSymbols(SDFRestriction arg);
SDFRestriction SDFsetRestrictionWsAfterSymbols(SDFRestriction arg, SDFLayout wsAfterSymbols);
ATbool SDFhasRestrictionWsAfterSlash(SDFRestriction arg);
SDFLayout SDFgetRestrictionWsAfterSlash(SDFRestriction arg);
SDFRestriction SDFsetRestrictionWsAfterSlash(SDFRestriction arg, SDFLayout wsAfterSlash);
ATbool SDFhasRestrictionSymbols(SDFRestriction arg);
SDFSymbols SDFgetRestrictionSymbols(SDFRestriction arg);
SDFRestriction SDFsetRestrictionSymbols(SDFRestriction arg, SDFSymbols symbols);

/*}}}  */
/*{{{  SDFRestrictions accessor prototypes */

ATbool SDFisValidRestrictions(SDFRestrictions arg);
ATbool SDFisRestrictionsDefault(SDFRestrictions arg);
ATbool SDFhasRestrictionsRestrictions(SDFRestrictions arg);
SDFRestrictionRestrictions SDFgetRestrictionsRestrictions(SDFRestrictions arg);
SDFRestrictions SDFsetRestrictionsRestrictions(SDFRestrictions arg, SDFRestrictionRestrictions restrictions);

/*}}}  */
/*{{{  SDFRestrictionRestrictions accessor prototypes */

ATbool SDFisValidRestrictionRestrictions(SDFRestrictionRestrictions arg);
ATbool SDFisRestrictionRestrictionsEmpty(SDFRestrictionRestrictions arg);
ATbool SDFisRestrictionRestrictionsSingle(SDFRestrictionRestrictions arg);
ATbool SDFisRestrictionRestrictionsMany(SDFRestrictionRestrictions arg);
ATbool SDFhasRestrictionRestrictionsWsAfterFirst(SDFRestrictionRestrictions arg);
SDFLayout SDFgetRestrictionRestrictionsWsAfterFirst(SDFRestrictionRestrictions arg);
SDFRestrictionRestrictions SDFsetRestrictionRestrictionsWsAfterFirst(SDFRestrictionRestrictions arg, SDFLayout wsAfterFirst);
ATbool SDFhasRestrictionRestrictionsTail(SDFRestrictionRestrictions arg);
SDFRestrictionRestrictions SDFgetRestrictionRestrictionsTail(SDFRestrictionRestrictions arg);
SDFRestrictionRestrictions SDFsetRestrictionRestrictionsTail(SDFRestrictionRestrictions arg, SDFRestrictionRestrictions tail);
ATbool SDFhasRestrictionRestrictionsHead(SDFRestrictionRestrictions arg);
SDFRestriction SDFgetRestrictionRestrictionsHead(SDFRestrictionRestrictions arg);
SDFRestrictionRestrictions SDFsetRestrictionRestrictionsHead(SDFRestrictionRestrictions arg, SDFRestriction head);

/*}}}  */
/*{{{  SDFAlias accessor prototypes */

ATbool SDFisValidAlias(SDFAlias arg);
ATbool SDFisAliasAlias(SDFAlias arg);
ATbool SDFhasAliasWsAfterSymbol(SDFAlias arg);
SDFLayout SDFgetAliasWsAfterSymbol(SDFAlias arg);
SDFAlias SDFsetAliasWsAfterSymbol(SDFAlias arg, SDFLayout wsAfterSymbol);
ATbool SDFhasAliasAlias(SDFAlias arg);
SDFSymbol SDFgetAliasAlias(SDFAlias arg);
SDFAlias SDFsetAliasAlias(SDFAlias arg, SDFSymbol alias);
ATbool SDFhasAliasSymbol(SDFAlias arg);
SDFSymbol SDFgetAliasSymbol(SDFAlias arg);
SDFAlias SDFsetAliasSymbol(SDFAlias arg, SDFSymbol symbol);
ATbool SDFhasAliasWsAfterArrow(SDFAlias arg);
SDFLayout SDFgetAliasWsAfterArrow(SDFAlias arg);
SDFAlias SDFsetAliasWsAfterArrow(SDFAlias arg, SDFLayout wsAfterArrow);

/*}}}  */
/*{{{  SDFAliases accessor prototypes */

ATbool SDFisValidAliases(SDFAliases arg);
ATbool SDFisAliasesDefault(SDFAliases arg);
ATbool SDFhasAliasesAliass(SDFAliases arg);
SDFAliasAliass SDFgetAliasesAliass(SDFAliases arg);
SDFAliases SDFsetAliasesAliass(SDFAliases arg, SDFAliasAliass aliass);

/*}}}  */
/*{{{  SDFAliasAliass accessor prototypes */

ATbool SDFisValidAliasAliass(SDFAliasAliass arg);
ATbool SDFisAliasAliassEmpty(SDFAliasAliass arg);
ATbool SDFisAliasAliassSingle(SDFAliasAliass arg);
ATbool SDFisAliasAliassMany(SDFAliasAliass arg);
ATbool SDFhasAliasAliassWsAfterFirst(SDFAliasAliass arg);
SDFLayout SDFgetAliasAliassWsAfterFirst(SDFAliasAliass arg);
SDFAliasAliass SDFsetAliasAliassWsAfterFirst(SDFAliasAliass arg, SDFLayout wsAfterFirst);
ATbool SDFhasAliasAliassTail(SDFAliasAliass arg);
SDFAliasAliass SDFgetAliasAliassTail(SDFAliasAliass arg);
SDFAliasAliass SDFsetAliasAliassTail(SDFAliasAliass arg, SDFAliasAliass tail);
ATbool SDFhasAliasAliassHead(SDFAliasAliass arg);
SDFAlias SDFgetAliasAliassHead(SDFAliasAliass arg);
SDFAliasAliass SDFsetAliasAliassHead(SDFAliasAliass arg, SDFAlias head);

/*}}}  */
/*{{{  SDFSymbols accessor prototypes */

ATbool SDFisValidSymbols(SDFSymbols arg);
ATbool SDFisSymbolsDefault(SDFSymbols arg);
ATbool SDFhasSymbolsSymbols(SDFSymbols arg);
SDFSymbolSymbols SDFgetSymbolsSymbols(SDFSymbols arg);
SDFSymbols SDFsetSymbolsSymbols(SDFSymbols arg, SDFSymbolSymbols symbols);

/*}}}  */
/*{{{  SDFSymbolSymbols accessor prototypes */

ATbool SDFisValidSymbolSymbols(SDFSymbolSymbols arg);
ATbool SDFisSymbolSymbolsEmpty(SDFSymbolSymbols arg);
ATbool SDFisSymbolSymbolsSingle(SDFSymbolSymbols arg);
ATbool SDFisSymbolSymbolsMany(SDFSymbolSymbols arg);
ATbool SDFhasSymbolSymbolsWsAfterFirst(SDFSymbolSymbols arg);
SDFLayout SDFgetSymbolSymbolsWsAfterFirst(SDFSymbolSymbols arg);
SDFSymbolSymbols SDFsetSymbolSymbolsWsAfterFirst(SDFSymbolSymbols arg, SDFLayout wsAfterFirst);
ATbool SDFhasSymbolSymbolsTail(SDFSymbolSymbols arg);
SDFSymbolSymbols SDFgetSymbolSymbolsTail(SDFSymbolSymbols arg);
SDFSymbolSymbols SDFsetSymbolSymbolsTail(SDFSymbolSymbols arg, SDFSymbolSymbols tail);
ATbool SDFhasSymbolSymbolsHead(SDFSymbolSymbols arg);
SDFSymbol SDFgetSymbolSymbolsHead(SDFSymbolSymbols arg);
SDFSymbolSymbols SDFsetSymbolSymbolsHead(SDFSymbolSymbols arg, SDFSymbol head);

/*}}}  */
/*{{{  SDFRenamings accessor prototypes */

ATbool SDFisValidRenamings(SDFRenamings arg);
ATbool SDFisRenamingsRenamings(SDFRenamings arg);
ATbool SDFhasRenamingsRenamings(SDFRenamings arg);
SDFRenamingRenamings SDFgetRenamingsRenamings(SDFRenamings arg);
SDFRenamings SDFsetRenamingsRenamings(SDFRenamings arg, SDFRenamingRenamings renamings);
ATbool SDFhasRenamingsWsAfterRenamings(SDFRenamings arg);
SDFLayout SDFgetRenamingsWsAfterRenamings(SDFRenamings arg);
SDFRenamings SDFsetRenamingsWsAfterRenamings(SDFRenamings arg, SDFLayout wsAfterRenamings);
ATbool SDFhasRenamingsWsAfterBracketOpen(SDFRenamings arg);
SDFLayout SDFgetRenamingsWsAfterBracketOpen(SDFRenamings arg);
SDFRenamings SDFsetRenamingsWsAfterBracketOpen(SDFRenamings arg, SDFLayout wsAfterBracketOpen);

/*}}}  */
/*{{{  SDFRenamingRenamings accessor prototypes */

ATbool SDFisValidRenamingRenamings(SDFRenamingRenamings arg);
ATbool SDFisRenamingRenamingsEmpty(SDFRenamingRenamings arg);
ATbool SDFisRenamingRenamingsSingle(SDFRenamingRenamings arg);
ATbool SDFisRenamingRenamingsMany(SDFRenamingRenamings arg);
ATbool SDFhasRenamingRenamingsWsAfterFirst(SDFRenamingRenamings arg);
SDFLayout SDFgetRenamingRenamingsWsAfterFirst(SDFRenamingRenamings arg);
SDFRenamingRenamings SDFsetRenamingRenamingsWsAfterFirst(SDFRenamingRenamings arg, SDFLayout wsAfterFirst);
ATbool SDFhasRenamingRenamingsTail(SDFRenamingRenamings arg);
SDFRenamingRenamings SDFgetRenamingRenamingsTail(SDFRenamingRenamings arg);
SDFRenamingRenamings SDFsetRenamingRenamingsTail(SDFRenamingRenamings arg, SDFRenamingRenamings tail);
ATbool SDFhasRenamingRenamingsHead(SDFRenamingRenamings arg);
SDFRenaming SDFgetRenamingRenamingsHead(SDFRenamingRenamings arg);
SDFRenamingRenamings SDFsetRenamingRenamingsHead(SDFRenamingRenamings arg, SDFRenaming head);

/*}}}  */
/*{{{  SDFRenaming accessor prototypes */

ATbool SDFisValidRenaming(SDFRenaming arg);
ATbool SDFisRenamingSymbol(SDFRenaming arg);
ATbool SDFisRenamingProduction(SDFRenaming arg);
ATbool SDFhasRenamingFrom(SDFRenaming arg);
SDFSymbol SDFgetRenamingFrom(SDFRenaming arg);
SDFRenaming SDFsetRenamingFrom(SDFRenaming arg, SDFSymbol from);
ATbool SDFhasRenamingTo(SDFRenaming arg);
SDFSymbol SDFgetRenamingTo(SDFRenaming arg);
SDFRenaming SDFsetRenamingTo(SDFRenaming arg, SDFSymbol to);
ATbool SDFhasRenamingWsAfterFrom(SDFRenaming arg);
SDFLayout SDFgetRenamingWsAfterFrom(SDFRenaming arg);
SDFRenaming SDFsetRenamingWsAfterFrom(SDFRenaming arg, SDFLayout wsAfterFrom);
ATbool SDFhasRenamingWsAfterEqualsGreaterThan(SDFRenaming arg);
SDFLayout SDFgetRenamingWsAfterEqualsGreaterThan(SDFRenaming arg);
SDFRenaming SDFsetRenamingWsAfterEqualsGreaterThan(SDFRenaming arg, SDFLayout wsAfterEqualsGreaterThan);

/*}}}  */
/*{{{  SDFNatCon accessor prototypes */

ATbool SDFisValidNatCon(SDFNatCon arg);
ATbool SDFisNatConDigits(SDFNatCon arg);
ATbool SDFhasNatConLex(SDFNatCon arg);
SDFLexical SDFgetNatConLex(SDFNatCon arg);
SDFNatCon SDFsetNatConLex(SDFNatCon arg, SDFLexical lex);

/*}}}  */
/*{{{  SDFIntCon accessor prototypes */

ATbool SDFisValidIntCon(SDFIntCon arg);
ATbool SDFisIntConNatural(SDFIntCon arg);
ATbool SDFisIntConPositive(SDFIntCon arg);
ATbool SDFisIntConNegative(SDFIntCon arg);
ATbool SDFhasIntConWsAfterNeg(SDFIntCon arg);
SDFLayout SDFgetIntConWsAfterNeg(SDFIntCon arg);
SDFIntCon SDFsetIntConWsAfterNeg(SDFIntCon arg, SDFLayout wsAfterNeg);
ATbool SDFhasIntConWsAfterPos(SDFIntCon arg);
SDFLayout SDFgetIntConWsAfterPos(SDFIntCon arg);
SDFIntCon SDFsetIntConWsAfterPos(SDFIntCon arg, SDFLayout wsAfterPos);
ATbool SDFhasIntConNatCon(SDFIntCon arg);
SDFNatCon SDFgetIntConNatCon(SDFIntCon arg);
SDFIntCon SDFsetIntConNatCon(SDFIntCon arg, SDFNatCon natCon);

/*}}}  */
/*{{{  SDFCharRange accessor prototypes */

ATbool SDFisValidCharRange(SDFCharRange arg);
ATbool SDFisCharRangeDefault(SDFCharRange arg);
ATbool SDFisCharRangeRange(SDFCharRange arg);
ATbool SDFhasCharRangeWsAfter(SDFCharRange arg);
SDFLayout SDFgetCharRangeWsAfter(SDFCharRange arg);
SDFCharRange SDFsetCharRangeWsAfter(SDFCharRange arg, SDFLayout wsAfter);
ATbool SDFhasCharRangeEnd(SDFCharRange arg);
SDFCharacter SDFgetCharRangeEnd(SDFCharRange arg);
SDFCharRange SDFsetCharRangeEnd(SDFCharRange arg, SDFCharacter end);
ATbool SDFhasCharRangeCharacter(SDFCharRange arg);
SDFCharacter SDFgetCharRangeCharacter(SDFCharRange arg);
SDFCharRange SDFsetCharRangeCharacter(SDFCharRange arg, SDFCharacter character);
ATbool SDFhasCharRangeStart(SDFCharRange arg);
SDFCharacter SDFgetCharRangeStart(SDFCharRange arg);
SDFCharRange SDFsetCharRangeStart(SDFCharRange arg, SDFCharacter start);
ATbool SDFhasCharRangeWsAfterStart(SDFCharRange arg);
SDFLayout SDFgetCharRangeWsAfterStart(SDFCharRange arg);
SDFCharRange SDFsetCharRangeWsAfterStart(SDFCharRange arg, SDFLayout wsAfterStart);

/*}}}  */
/*{{{  SDFCharRanges accessor prototypes */

ATbool SDFisValidCharRanges(SDFCharRanges arg);
ATbool SDFisCharRangesDefault(SDFCharRanges arg);
ATbool SDFisCharRangesConc(SDFCharRanges arg);
ATbool SDFisCharRangesBracket(SDFCharRanges arg);
ATbool SDFhasCharRangesRight(SDFCharRanges arg);
SDFCharRanges SDFgetCharRangesRight(SDFCharRanges arg);
SDFCharRanges SDFsetCharRangesRight(SDFCharRanges arg, SDFCharRanges right);
ATbool SDFhasCharRangesWsAfterLeft(SDFCharRanges arg);
SDFLayout SDFgetCharRangesWsAfterLeft(SDFCharRanges arg);
SDFCharRanges SDFsetCharRangesWsAfterLeft(SDFCharRanges arg, SDFLayout wsAfterLeft);
ATbool SDFhasCharRangesWsAfterParenOpen(SDFCharRanges arg);
SDFLayout SDFgetCharRangesWsAfterParenOpen(SDFCharRanges arg);
SDFCharRanges SDFsetCharRangesWsAfterParenOpen(SDFCharRanges arg, SDFLayout wsAfterParenOpen);
ATbool SDFhasCharRangesWsAfterCharRanges(SDFCharRanges arg);
SDFLayout SDFgetCharRangesWsAfterCharRanges(SDFCharRanges arg);
SDFCharRanges SDFsetCharRangesWsAfterCharRanges(SDFCharRanges arg, SDFLayout wsAfterCharRanges);
ATbool SDFhasCharRangesCharRanges(SDFCharRanges arg);
SDFCharRanges SDFgetCharRangesCharRanges(SDFCharRanges arg);
SDFCharRanges SDFsetCharRangesCharRanges(SDFCharRanges arg, SDFCharRanges charRanges);
ATbool SDFhasCharRangesCharRange(SDFCharRanges arg);
SDFCharRange SDFgetCharRangesCharRange(SDFCharRanges arg);
SDFCharRanges SDFsetCharRangesCharRange(SDFCharRanges arg, SDFCharRange charRange);
ATbool SDFhasCharRangesLeft(SDFCharRanges arg);
SDFCharRanges SDFgetCharRangesLeft(SDFCharRanges arg);
SDFCharRanges SDFsetCharRangesLeft(SDFCharRanges arg, SDFCharRanges left);

/*}}}  */
/*{{{  SDFOptCharRanges accessor prototypes */

ATbool SDFisValidOptCharRanges(SDFOptCharRanges arg);
ATbool SDFisOptCharRangesAbsent(SDFOptCharRanges arg);
ATbool SDFisOptCharRangesPresent(SDFOptCharRanges arg);
ATbool SDFhasOptCharRangesCharRanges(SDFOptCharRanges arg);
SDFCharRanges SDFgetOptCharRangesCharRanges(SDFOptCharRanges arg);
SDFOptCharRanges SDFsetOptCharRangesCharRanges(SDFOptCharRanges arg, SDFCharRanges charRanges);

/*}}}  */
/*{{{  SDFCharClass accessor prototypes */

ATbool SDFisValidCharClass(SDFCharClass arg);
ATbool SDFisCharClassSimpleCharclass(SDFCharClass arg);
ATbool SDFisCharClassComp(SDFCharClass arg);
ATbool SDFisCharClassDiff(SDFCharClass arg);
ATbool SDFisCharClassIsect(SDFCharClass arg);
ATbool SDFisCharClassUnion(SDFCharClass arg);
ATbool SDFisCharClassBracket(SDFCharClass arg);
ATbool SDFhasCharClassRight(SDFCharClass arg);
SDFCharClass SDFgetCharClassRight(SDFCharClass arg);
SDFCharClass SDFsetCharClassRight(SDFCharClass arg, SDFCharClass right);
ATbool SDFhasCharClassWsAfterSlash(SDFCharClass arg);
SDFLayout SDFgetCharClassWsAfterSlash(SDFCharClass arg);
SDFCharClass SDFsetCharClassWsAfterSlash(SDFCharClass arg, SDFLayout wsAfterSlash);
ATbool SDFhasCharClassOptCharRanges(SDFCharClass arg);
SDFOptCharRanges SDFgetCharClassOptCharRanges(SDFCharClass arg);
SDFCharClass SDFsetCharClassOptCharRanges(SDFCharClass arg, SDFOptCharRanges optCharRanges);
ATbool SDFhasCharClassWsAfterLeft(SDFCharClass arg);
SDFLayout SDFgetCharClassWsAfterLeft(SDFCharClass arg);
SDFCharClass SDFsetCharClassWsAfterLeft(SDFCharClass arg, SDFLayout wsAfterLeft);
ATbool SDFhasCharClassWsAfterParenOpen(SDFCharClass arg);
SDFLayout SDFgetCharClassWsAfterParenOpen(SDFCharClass arg);
SDFCharClass SDFsetCharClassWsAfterParenOpen(SDFCharClass arg, SDFLayout wsAfterParenOpen);
ATbool SDFhasCharClassWsAfterTilde(SDFCharClass arg);
SDFLayout SDFgetCharClassWsAfterTilde(SDFCharClass arg);
SDFCharClass SDFsetCharClassWsAfterTilde(SDFCharClass arg, SDFLayout wsAfterTilde);
ATbool SDFhasCharClassWsAfterBackslashSlash(SDFCharClass arg);
SDFLayout SDFgetCharClassWsAfterBackslashSlash(SDFCharClass arg);
SDFCharClass SDFsetCharClassWsAfterBackslashSlash(SDFCharClass arg, SDFLayout wsAfterBackslashSlash);
ATbool SDFhasCharClassWsAfterOptCharRanges(SDFCharClass arg);
SDFLayout SDFgetCharClassWsAfterOptCharRanges(SDFCharClass arg);
SDFCharClass SDFsetCharClassWsAfterOptCharRanges(SDFCharClass arg, SDFLayout wsAfterOptCharRanges);
ATbool SDFhasCharClassCharClass(SDFCharClass arg);
SDFCharClass SDFgetCharClassCharClass(SDFCharClass arg);
SDFCharClass SDFsetCharClassCharClass(SDFCharClass arg, SDFCharClass charClass);
ATbool SDFhasCharClassWsAfterBracketOpen(SDFCharClass arg);
SDFLayout SDFgetCharClassWsAfterBracketOpen(SDFCharClass arg);
SDFCharClass SDFsetCharClassWsAfterBracketOpen(SDFCharClass arg, SDFLayout wsAfterBracketOpen);
ATbool SDFhasCharClassWsAfterSlashBackslash(SDFCharClass arg);
SDFLayout SDFgetCharClassWsAfterSlashBackslash(SDFCharClass arg);
SDFCharClass SDFsetCharClassWsAfterSlashBackslash(SDFCharClass arg, SDFLayout wsAfterSlashBackslash);
ATbool SDFhasCharClassWsAfterCharClass(SDFCharClass arg);
SDFLayout SDFgetCharClassWsAfterCharClass(SDFCharClass arg);
SDFCharClass SDFsetCharClassWsAfterCharClass(SDFCharClass arg, SDFLayout wsAfterCharClass);
ATbool SDFhasCharClassLeft(SDFCharClass arg);
SDFCharClass SDFgetCharClassLeft(SDFCharClass arg);
SDFCharClass SDFsetCharClassLeft(SDFCharClass arg, SDFCharClass left);

/*}}}  */
/*{{{  SDFAlphaNumericalEscChar accessor prototypes */

ATbool SDFisValidAlphaNumericalEscChar(SDFAlphaNumericalEscChar arg);
ATbool SDFisAlphaNumericalEscCharDefault(SDFAlphaNumericalEscChar arg);
ATbool SDFhasAlphaNumericalEscCharLex(SDFAlphaNumericalEscChar arg);
SDFLexical SDFgetAlphaNumericalEscCharLex(SDFAlphaNumericalEscChar arg);
SDFAlphaNumericalEscChar SDFsetAlphaNumericalEscCharLex(SDFAlphaNumericalEscChar arg, SDFLexical lex);

/*}}}  */
/*{{{  SDFDecimalEscChar accessor prototypes */

ATbool SDFisValidDecimalEscChar(SDFDecimalEscChar arg);
ATbool SDFisDecimalEscCharDec0_199(SDFDecimalEscChar arg);
ATbool SDFisDecimalEscCharDec200_249(SDFDecimalEscChar arg);
ATbool SDFisDecimalEscCharDec250_255(SDFDecimalEscChar arg);
ATbool SDFhasDecimalEscCharLex(SDFDecimalEscChar arg);
SDFLexical SDFgetDecimalEscCharLex(SDFDecimalEscChar arg);
SDFDecimalEscChar SDFsetDecimalEscCharLex(SDFDecimalEscChar arg, SDFLexical lex);

/*}}}  */
/*{{{  SDFEscChar accessor prototypes */

ATbool SDFisValidEscChar(SDFEscChar arg);
ATbool SDFisEscCharAlphaNumeric(SDFEscChar arg);
ATbool SDFisEscCharDecimal(SDFEscChar arg);
ATbool SDFhasEscCharLex(SDFEscChar arg);
SDFLexical SDFgetEscCharLex(SDFEscChar arg);
SDFEscChar SDFsetEscCharLex(SDFEscChar arg, SDFLexical lex);

/*}}}  */
/*{{{  SDFLChar accessor prototypes */

ATbool SDFisValidLChar(SDFLChar arg);
ATbool SDFisLCharNormal(SDFLChar arg);
ATbool SDFisLCharEscaped(SDFLChar arg);
ATbool SDFhasLCharLex(SDFLChar arg);
SDFLexical SDFgetLCharLex(SDFLChar arg);
SDFLChar SDFsetLCharLex(SDFLChar arg, SDFLexical lex);

/*}}}  */
/*{{{  SDFATerms accessor prototypes */

ATbool SDFisValidATerms(SDFATerms arg);
ATbool SDFisATermsAterm(SDFATerms arg);
ATbool SDFisATermsCons(SDFATerms arg);
ATbool SDFhasATermsWsAfterComma(SDFATerms arg);
SDFLayout SDFgetATermsWsAfterComma(SDFATerms arg);
SDFATerms SDFsetATermsWsAfterComma(SDFATerms arg, SDFLayout wsAfterComma);
ATbool SDFhasATermsATerm(SDFATerms arg);
SDFATerm SDFgetATermsATerm(SDFATerms arg);
SDFATerms SDFsetATermsATerm(SDFATerms arg, SDFATerm aTerm);
ATbool SDFhasATermsTail(SDFATerms arg);
SDFATerms SDFgetATermsTail(SDFATerms arg);
SDFATerms SDFsetATermsTail(SDFATerms arg, SDFATerms tail);
ATbool SDFhasATermsHead(SDFATerms arg);
SDFATerm SDFgetATermsHead(SDFATerms arg);
SDFATerms SDFsetATermsHead(SDFATerms arg, SDFATerm head);
ATbool SDFhasATermsWsAfterHead(SDFATerms arg);
SDFLayout SDFgetATermsWsAfterHead(SDFATerms arg);
SDFATerms SDFsetATermsWsAfterHead(SDFATerms arg, SDFLayout wsAfterHead);

/*}}}  */
/*{{{  SDFATermList accessor prototypes */

ATbool SDFisValidATermList(SDFATermList arg);
ATbool SDFisATermListEmpty(SDFATermList arg);
ATbool SDFisATermListNotEmpty(SDFATermList arg);
ATbool SDFhasATermListWsAfterBracketOpen(SDFATermList arg);
SDFLayout SDFgetATermListWsAfterBracketOpen(SDFATermList arg);
SDFATermList SDFsetATermListWsAfterBracketOpen(SDFATermList arg, SDFLayout wsAfterBracketOpen);
ATbool SDFhasATermListWsAfterATerms(SDFATermList arg);
SDFLayout SDFgetATermListWsAfterATerms(SDFATermList arg);
SDFATermList SDFsetATermListWsAfterATerms(SDFATermList arg, SDFLayout wsAfterATerms);
ATbool SDFhasATermListATerms(SDFATermList arg);
SDFATerms SDFgetATermListATerms(SDFATermList arg);
SDFATermList SDFsetATermListATerms(SDFATermList arg, SDFATerms aTerms);

/*}}}  */
/*{{{  SDFACon accessor prototypes */

ATbool SDFisValidACon(SDFACon arg);
ATbool SDFisAConInt(SDFACon arg);
ATbool SDFisAConReal(SDFACon arg);
ATbool SDFhasAConIntCon(SDFACon arg);
SDFIntCon SDFgetAConIntCon(SDFACon arg);
SDFACon SDFsetAConIntCon(SDFACon arg, SDFIntCon intCon);
ATbool SDFhasAConRealCon(SDFACon arg);
SDFRealCon SDFgetAConRealCon(SDFACon arg);
SDFACon SDFsetAConRealCon(SDFACon arg, SDFRealCon realCon);

/*}}}  */
/*{{{  SDFAFun accessor prototypes */

ATbool SDFisValidAFun(SDFAFun arg);
ATbool SDFisAFunDefault(SDFAFun arg);
ATbool SDFhasAFunLiteral(SDFAFun arg);
SDFLiteral SDFgetAFunLiteral(SDFAFun arg);
SDFAFun SDFsetAFunLiteral(SDFAFun arg, SDFLiteral literal);

/*}}}  */
/*{{{  SDFATerm accessor prototypes */

ATbool SDFisValidATerm(SDFATerm arg);
ATbool SDFisATermConstant(SDFATerm arg);
ATbool SDFisATermList(SDFATerm arg);
ATbool SDFisATermFun(SDFATerm arg);
ATbool SDFisATermAppl(SDFATerm arg);
ATbool SDFisATermAnnotatedConstant(SDFATerm arg);
ATbool SDFisATermAnnotatedList(SDFATerm arg);
ATbool SDFisATermAnnotatedFun(SDFATerm arg);
ATbool SDFisATermAnnotatedAppl(SDFATerm arg);
ATbool SDFhasATermWsAfterAFun(SDFATerm arg);
SDFLayout SDFgetATermWsAfterAFun(SDFATerm arg);
SDFATerm SDFsetATermWsAfterAFun(SDFATerm arg, SDFLayout wsAfterAFun);
ATbool SDFhasATermWsAfterParenClose(SDFATerm arg);
SDFLayout SDFgetATermWsAfterParenClose(SDFATerm arg);
SDFATerm SDFsetATermWsAfterParenClose(SDFATerm arg, SDFLayout wsAfterParenClose);
ATbool SDFhasATermWsAfterParenOpen(SDFATerm arg);
SDFLayout SDFgetATermWsAfterParenOpen(SDFATerm arg);
SDFATerm SDFsetATermWsAfterParenOpen(SDFATerm arg, SDFLayout wsAfterParenOpen);
ATbool SDFhasATermACon(SDFATerm arg);
SDFACon SDFgetATermACon(SDFATerm arg);
SDFATerm SDFsetATermACon(SDFATerm arg, SDFACon aCon);
ATbool SDFhasATermAnn(SDFATerm arg);
SDFAnn SDFgetATermAnn(SDFATerm arg);
SDFATerm SDFsetATermAnn(SDFATerm arg, SDFAnn ann);
ATbool SDFhasATermArgs(SDFATerm arg);
SDFATerms SDFgetATermArgs(SDFATerm arg);
SDFATerm SDFsetATermArgs(SDFATerm arg, SDFATerms args);
ATbool SDFhasATermWsAfterACon(SDFATerm arg);
SDFLayout SDFgetATermWsAfterACon(SDFATerm arg);
SDFATerm SDFsetATermWsAfterACon(SDFATerm arg, SDFLayout wsAfterACon);
ATbool SDFhasATermWsAfterArgs(SDFATerm arg);
SDFLayout SDFgetATermWsAfterArgs(SDFATerm arg);
SDFATerm SDFsetATermWsAfterArgs(SDFATerm arg, SDFLayout wsAfterArgs);
ATbool SDFhasATermATermList(SDFATerm arg);
SDFATermList SDFgetATermATermList(SDFATerm arg);
SDFATerm SDFsetATermATermList(SDFATerm arg, SDFATermList aTermList);
ATbool SDFhasATermAFun(SDFATerm arg);
SDFAFun SDFgetATermAFun(SDFATerm arg);
SDFATerm SDFsetATermAFun(SDFATerm arg, SDFAFun aFun);
ATbool SDFhasATermWsAfterATermList(SDFATerm arg);
SDFLayout SDFgetATermWsAfterATermList(SDFATerm arg);
SDFATerm SDFsetATermWsAfterATermList(SDFATerm arg, SDFLayout wsAfterATermList);

/*}}}  */
/*{{{  SDFAnn accessor prototypes */

ATbool SDFisValidAnn(SDFAnn arg);
ATbool SDFisAnnAnnotation(SDFAnn arg);
ATbool SDFhasAnnWsAfterBraceOpen(SDFAnn arg);
SDFLayout SDFgetAnnWsAfterBraceOpen(SDFAnn arg);
SDFAnn SDFsetAnnWsAfterBraceOpen(SDFAnn arg, SDFLayout wsAfterBraceOpen);
ATbool SDFhasAnnWsAfterATerms(SDFAnn arg);
SDFLayout SDFgetAnnWsAfterATerms(SDFAnn arg);
SDFAnn SDFsetAnnWsAfterATerms(SDFAnn arg, SDFLayout wsAfterATerms);
ATbool SDFhasAnnATerms(SDFAnn arg);
SDFATerms SDFgetAnnATerms(SDFAnn arg);
SDFAnn SDFsetAnnATerms(SDFAnn arg, SDFATerms aTerms);

/*}}}  */
/*{{{  SDFTagId accessor prototypes */

ATbool SDFisValidTagId(SDFTagId arg);
ATbool SDFisTagIdDefault(SDFTagId arg);
ATbool SDFisTagIdEmpty(SDFTagId arg);
ATbool SDFhasTagIdLex(SDFTagId arg);
SDFLexical SDFgetTagIdLex(SDFTagId arg);
SDFTagId SDFsetTagIdLex(SDFTagId arg, SDFLexical lex);

/*}}}  */
/*{{{  SDFNumChar accessor prototypes */

ATbool SDFisValidNumChar(SDFNumChar arg);
ATbool SDFisNumCharDigits(SDFNumChar arg);
ATbool SDFhasNumCharLex(SDFNumChar arg);
SDFLexical SDFgetNumCharLex(SDFNumChar arg);
SDFNumChar SDFsetNumCharLex(SDFNumChar arg, SDFLexical lex);

/*}}}  */
/*{{{  SDFShortChar accessor prototypes */

ATbool SDFisValidShortChar(SDFShortChar arg);
ATbool SDFisShortCharRegular(SDFShortChar arg);
ATbool SDFisShortCharEscaped(SDFShortChar arg);
ATbool SDFhasShortCharLex(SDFShortChar arg);
SDFLexical SDFgetShortCharLex(SDFShortChar arg);
SDFShortChar SDFsetShortCharLex(SDFShortChar arg, SDFLexical lex);

/*}}}  */
/*{{{  SDFCharacter accessor prototypes */

ATbool SDFisValidCharacter(SDFCharacter arg);
ATbool SDFisCharacterNumeric(SDFCharacter arg);
ATbool SDFisCharacterShort(SDFCharacter arg);
ATbool SDFisCharacterTop(SDFCharacter arg);
ATbool SDFisCharacterEof(SDFCharacter arg);
ATbool SDFhasCharacterShortChar(SDFCharacter arg);
SDFShortChar SDFgetCharacterShortChar(SDFCharacter arg);
SDFCharacter SDFsetCharacterShortChar(SDFCharacter arg, SDFShortChar shortChar);
ATbool SDFhasCharacterNumChar(SDFCharacter arg);
SDFNumChar SDFgetCharacterNumChar(SDFCharacter arg);
SDFCharacter SDFsetCharacterNumChar(SDFCharacter arg, SDFNumChar numChar);

/*}}}  */
/*{{{  SDFOptExp accessor prototypes */

ATbool SDFisValidOptExp(SDFOptExp arg);
ATbool SDFisOptExpPresent(SDFOptExp arg);
ATbool SDFisOptExpAbsent(SDFOptExp arg);
ATbool SDFhasOptExpWsAfterE(SDFOptExp arg);
SDFLayout SDFgetOptExpWsAfterE(SDFOptExp arg);
SDFOptExp SDFsetOptExpWsAfterE(SDFOptExp arg, SDFLayout wsAfterE);
ATbool SDFhasOptExpIntCon(SDFOptExp arg);
SDFIntCon SDFgetOptExpIntCon(SDFOptExp arg);
SDFOptExp SDFsetOptExpIntCon(SDFOptExp arg, SDFIntCon intCon);

/*}}}  */
/*{{{  SDFRealCon accessor prototypes */

ATbool SDFisValidRealCon(SDFRealCon arg);
ATbool SDFisRealConRealCon(SDFRealCon arg);
ATbool SDFhasRealConWsAfterPeriod(SDFRealCon arg);
SDFLayout SDFgetRealConWsAfterPeriod(SDFRealCon arg);
SDFRealCon SDFsetRealConWsAfterPeriod(SDFRealCon arg, SDFLayout wsAfterPeriod);
ATbool SDFhasRealConWsAfterIntCon(SDFRealCon arg);
SDFLayout SDFgetRealConWsAfterIntCon(SDFRealCon arg);
SDFRealCon SDFsetRealConWsAfterIntCon(SDFRealCon arg, SDFLayout wsAfterIntCon);
ATbool SDFhasRealConOptExp(SDFRealCon arg);
SDFOptExp SDFgetRealConOptExp(SDFRealCon arg);
SDFRealCon SDFsetRealConOptExp(SDFRealCon arg, SDFOptExp optExp);
ATbool SDFhasRealConIntCon(SDFRealCon arg);
SDFIntCon SDFgetRealConIntCon(SDFRealCon arg);
SDFRealCon SDFsetRealConIntCon(SDFRealCon arg, SDFIntCon intCon);
ATbool SDFhasRealConWsAfterNatCon(SDFRealCon arg);
SDFLayout SDFgetRealConWsAfterNatCon(SDFRealCon arg);
SDFRealCon SDFsetRealConWsAfterNatCon(SDFRealCon arg, SDFLayout wsAfterNatCon);
ATbool SDFhasRealConNatCon(SDFRealCon arg);
SDFNatCon SDFgetRealConNatCon(SDFRealCon arg);
SDFRealCon SDFsetRealConNatCon(SDFRealCon arg, SDFNatCon natCon);

/*}}}  */

#endif /* _SDF_H */
