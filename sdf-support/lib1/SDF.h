#ifndef _SDF_H
#define _SDF_H

/*{{{  includes */

#include <aterm1.h>
#include "SDF_dict.h"

/*}}}  */

/*{{{  prologue */

typedef ATerm SDF_Layout;
typedef ATerm SDF_Separator;
typedef ATerm SDF_Lexical;

/*}}}  */
/*{{{  typedefs */

typedef struct _SDF_Symbol *SDF_Symbol;
typedef struct _SDF_Grammar *SDF_Grammar;
typedef struct _SDF_SDF *SDF_SDF;
typedef struct _SDF_Attributes *SDF_Attributes;
typedef struct _SDF_AttributeList *SDF_AttributeList;
typedef struct _SDF_Production *SDF_Production;
typedef struct _SDF_Productions *SDF_Productions;
typedef struct _SDF_ProductionList *SDF_ProductionList;
typedef struct _SDF_ModuleWord *SDF_ModuleWord;
typedef struct _SDF_ModuleId *SDF_ModuleId;
typedef struct _SDF_Definition *SDF_Definition;
typedef struct _SDF_ModuleList *SDF_ModuleList;
typedef struct _SDF_Module *SDF_Module;
typedef struct _SDF_ImpSectionList *SDF_ImpSectionList;
typedef struct _SDF_Section *SDF_Section;
typedef struct _SDF_Sections *SDF_Sections;
typedef struct _SDF_SectionList *SDF_SectionList;
typedef struct _SDF_ModuleName *SDF_ModuleName;
typedef struct _SDF_Attribute *SDF_Attribute;
typedef struct _SDF_ImpSection *SDF_ImpSection;
typedef struct _SDF_Imports *SDF_Imports;
typedef struct _SDF_ImportList *SDF_ImportList;
typedef struct _SDF_Import *SDF_Import;
typedef struct _SDF_SymbolTail *SDF_SymbolTail;
typedef struct _SDF_Associativity *SDF_Associativity;
typedef struct _SDF_Group *SDF_Group;
typedef struct _SDF_Priority *SDF_Priority;
typedef struct _SDF_GroupGroupp *SDF_GroupGroupp;
typedef struct _SDF_Priorities *SDF_Priorities;
typedef struct _SDF_PriorityList *SDF_PriorityList;
typedef struct _SDF_Sort *SDF_Sort;
typedef struct _SDF_UQLiteral *SDF_UQLiteral;
typedef struct _SDF_Literal *SDF_Literal;
typedef struct _SDF_SymbolArguments *SDF_SymbolArguments;
typedef struct _SDF_Lookahead *SDF_Lookahead;
typedef struct _SDF_Lookaheads *SDF_Lookaheads;
typedef struct _SDF_LookaheadList *SDF_LookaheadList;
typedef struct _SDF_Restriction *SDF_Restriction;
typedef struct _SDF_Restrictions *SDF_Restrictions;
typedef struct _SDF_RestrictionList *SDF_RestrictionList;
typedef struct _SDF_Alias *SDF_Alias;
typedef struct _SDF_Aliases *SDF_Aliases;
typedef struct _SDF_AliasList *SDF_AliasList;
typedef struct _SDF_Symbols *SDF_Symbols;
typedef struct _SDF_SymbolList *SDF_SymbolList;
typedef struct _SDF_Renamings *SDF_Renamings;
typedef struct _SDF_RenamingList *SDF_RenamingList;
typedef struct _SDF_Renaming *SDF_Renaming;
typedef struct _SDF_NatCon *SDF_NatCon;
typedef struct _SDF_IntCon *SDF_IntCon;
typedef struct _SDF_CharRange *SDF_CharRange;
typedef struct _SDF_CharRanges *SDF_CharRanges;
typedef struct _SDF_OptCharRanges *SDF_OptCharRanges;
typedef struct _SDF_CharClass *SDF_CharClass;
typedef struct _SDF_AlphaNumericalEscChar *SDF_AlphaNumericalEscChar;
typedef struct _SDF_DecimalEscChar *SDF_DecimalEscChar;
typedef struct _SDF_EscChar *SDF_EscChar;
typedef struct _SDF_LChar *SDF_LChar;
typedef struct _SDF_ATerms *SDF_ATerms;
typedef struct _SDF_ATermList *SDF_ATermList;
typedef struct _SDF_ACon *SDF_ACon;
typedef struct _SDF_AFun *SDF_AFun;
typedef struct _SDF_ATerm *SDF_ATerm;
typedef struct _SDF_Ann *SDF_Ann;
typedef struct _SDF_TagId *SDF_TagId;
typedef struct _SDF_NumChar *SDF_NumChar;
typedef struct _SDF_ShortChar *SDF_ShortChar;
typedef struct _SDF_Character *SDF_Character;
typedef struct _SDF_OptExp *SDF_OptExp;
typedef struct _SDF_RealCon *SDF_RealCon;

/*}}}  */

void SDF_initSDFApi(void);

SDF_Symbol SDF_makeSymbolFromTerm(ATerm t);
ATerm SDF_makeTermFromSymbol(SDF_Symbol arg);
SDF_Grammar SDF_makeGrammarFromTerm(ATerm t);
ATerm SDF_makeTermFromGrammar(SDF_Grammar arg);
SDF_SDF SDF_makeSDFFromTerm(ATerm t);
ATerm SDF_makeTermFromSDF(SDF_SDF arg);
SDF_Attributes SDF_makeAttributesFromTerm(ATerm t);
ATerm SDF_makeTermFromAttributes(SDF_Attributes arg);
SDF_AttributeList SDF_makeAttributeListFromTerm(ATerm t);
ATerm SDF_makeTermFromAttributeList(SDF_AttributeList arg);
SDF_Production SDF_makeProductionFromTerm(ATerm t);
ATerm SDF_makeTermFromProduction(SDF_Production arg);
SDF_Productions SDF_makeProductionsFromTerm(ATerm t);
ATerm SDF_makeTermFromProductions(SDF_Productions arg);
SDF_ProductionList SDF_makeProductionListFromTerm(ATerm t);
ATerm SDF_makeTermFromProductionList(SDF_ProductionList arg);
SDF_ModuleWord SDF_makeModuleWordFromTerm(ATerm t);
ATerm SDF_makeTermFromModuleWord(SDF_ModuleWord arg);
SDF_ModuleId SDF_makeModuleIdFromTerm(ATerm t);
ATerm SDF_makeTermFromModuleId(SDF_ModuleId arg);
SDF_Definition SDF_makeDefinitionFromTerm(ATerm t);
ATerm SDF_makeTermFromDefinition(SDF_Definition arg);
SDF_ModuleList SDF_makeModuleListFromTerm(ATerm t);
ATerm SDF_makeTermFromModuleList(SDF_ModuleList arg);
SDF_Module SDF_makeModuleFromTerm(ATerm t);
ATerm SDF_makeTermFromModule(SDF_Module arg);
SDF_ImpSectionList SDF_makeImpSectionListFromTerm(ATerm t);
ATerm SDF_makeTermFromImpSectionList(SDF_ImpSectionList arg);
SDF_Section SDF_makeSectionFromTerm(ATerm t);
ATerm SDF_makeTermFromSection(SDF_Section arg);
SDF_Sections SDF_makeSectionsFromTerm(ATerm t);
ATerm SDF_makeTermFromSections(SDF_Sections arg);
SDF_SectionList SDF_makeSectionListFromTerm(ATerm t);
ATerm SDF_makeTermFromSectionList(SDF_SectionList arg);
SDF_ModuleName SDF_makeModuleNameFromTerm(ATerm t);
ATerm SDF_makeTermFromModuleName(SDF_ModuleName arg);
SDF_Attribute SDF_makeAttributeFromTerm(ATerm t);
ATerm SDF_makeTermFromAttribute(SDF_Attribute arg);
SDF_ImpSection SDF_makeImpSectionFromTerm(ATerm t);
ATerm SDF_makeTermFromImpSection(SDF_ImpSection arg);
SDF_Imports SDF_makeImportsFromTerm(ATerm t);
ATerm SDF_makeTermFromImports(SDF_Imports arg);
SDF_ImportList SDF_makeImportListFromTerm(ATerm t);
ATerm SDF_makeTermFromImportList(SDF_ImportList arg);
SDF_Import SDF_makeImportFromTerm(ATerm t);
ATerm SDF_makeTermFromImport(SDF_Import arg);
SDF_SymbolTail SDF_makeSymbolTailFromTerm(ATerm t);
ATerm SDF_makeTermFromSymbolTail(SDF_SymbolTail arg);
SDF_Associativity SDF_makeAssociativityFromTerm(ATerm t);
ATerm SDF_makeTermFromAssociativity(SDF_Associativity arg);
SDF_Group SDF_makeGroupFromTerm(ATerm t);
ATerm SDF_makeTermFromGroup(SDF_Group arg);
SDF_Priority SDF_makePriorityFromTerm(ATerm t);
ATerm SDF_makeTermFromPriority(SDF_Priority arg);
SDF_GroupGroupp SDF_makeGroupGrouppFromTerm(ATerm t);
ATerm SDF_makeTermFromGroupGroupp(SDF_GroupGroupp arg);
SDF_Priorities SDF_makePrioritiesFromTerm(ATerm t);
ATerm SDF_makeTermFromPriorities(SDF_Priorities arg);
SDF_PriorityList SDF_makePriorityListFromTerm(ATerm t);
ATerm SDF_makeTermFromPriorityList(SDF_PriorityList arg);
SDF_Sort SDF_makeSortFromTerm(ATerm t);
ATerm SDF_makeTermFromSort(SDF_Sort arg);
SDF_UQLiteral SDF_makeUQLiteralFromTerm(ATerm t);
ATerm SDF_makeTermFromUQLiteral(SDF_UQLiteral arg);
SDF_Literal SDF_makeLiteralFromTerm(ATerm t);
ATerm SDF_makeTermFromLiteral(SDF_Literal arg);
SDF_SymbolArguments SDF_makeSymbolArgumentsFromTerm(ATerm t);
ATerm SDF_makeTermFromSymbolArguments(SDF_SymbolArguments arg);
SDF_Lookahead SDF_makeLookaheadFromTerm(ATerm t);
ATerm SDF_makeTermFromLookahead(SDF_Lookahead arg);
SDF_Lookaheads SDF_makeLookaheadsFromTerm(ATerm t);
ATerm SDF_makeTermFromLookaheads(SDF_Lookaheads arg);
SDF_LookaheadList SDF_makeLookaheadListFromTerm(ATerm t);
ATerm SDF_makeTermFromLookaheadList(SDF_LookaheadList arg);
SDF_Restriction SDF_makeRestrictionFromTerm(ATerm t);
ATerm SDF_makeTermFromRestriction(SDF_Restriction arg);
SDF_Restrictions SDF_makeRestrictionsFromTerm(ATerm t);
ATerm SDF_makeTermFromRestrictions(SDF_Restrictions arg);
SDF_RestrictionList SDF_makeRestrictionListFromTerm(ATerm t);
ATerm SDF_makeTermFromRestrictionList(SDF_RestrictionList arg);
SDF_Alias SDF_makeAliasFromTerm(ATerm t);
ATerm SDF_makeTermFromAlias(SDF_Alias arg);
SDF_Aliases SDF_makeAliasesFromTerm(ATerm t);
ATerm SDF_makeTermFromAliases(SDF_Aliases arg);
SDF_AliasList SDF_makeAliasListFromTerm(ATerm t);
ATerm SDF_makeTermFromAliasList(SDF_AliasList arg);
SDF_Symbols SDF_makeSymbolsFromTerm(ATerm t);
ATerm SDF_makeTermFromSymbols(SDF_Symbols arg);
SDF_SymbolList SDF_makeSymbolListFromTerm(ATerm t);
ATerm SDF_makeTermFromSymbolList(SDF_SymbolList arg);
SDF_Renamings SDF_makeRenamingsFromTerm(ATerm t);
ATerm SDF_makeTermFromRenamings(SDF_Renamings arg);
SDF_RenamingList SDF_makeRenamingListFromTerm(ATerm t);
ATerm SDF_makeTermFromRenamingList(SDF_RenamingList arg);
SDF_Renaming SDF_makeRenamingFromTerm(ATerm t);
ATerm SDF_makeTermFromRenaming(SDF_Renaming arg);
SDF_NatCon SDF_makeNatConFromTerm(ATerm t);
ATerm SDF_makeTermFromNatCon(SDF_NatCon arg);
SDF_IntCon SDF_makeIntConFromTerm(ATerm t);
ATerm SDF_makeTermFromIntCon(SDF_IntCon arg);
SDF_CharRange SDF_makeCharRangeFromTerm(ATerm t);
ATerm SDF_makeTermFromCharRange(SDF_CharRange arg);
SDF_CharRanges SDF_makeCharRangesFromTerm(ATerm t);
ATerm SDF_makeTermFromCharRanges(SDF_CharRanges arg);
SDF_OptCharRanges SDF_makeOptCharRangesFromTerm(ATerm t);
ATerm SDF_makeTermFromOptCharRanges(SDF_OptCharRanges arg);
SDF_CharClass SDF_makeCharClassFromTerm(ATerm t);
ATerm SDF_makeTermFromCharClass(SDF_CharClass arg);
SDF_AlphaNumericalEscChar SDF_makeAlphaNumericalEscCharFromTerm(ATerm t);
ATerm SDF_makeTermFromAlphaNumericalEscChar(SDF_AlphaNumericalEscChar arg);
SDF_DecimalEscChar SDF_makeDecimalEscCharFromTerm(ATerm t);
ATerm SDF_makeTermFromDecimalEscChar(SDF_DecimalEscChar arg);
SDF_EscChar SDF_makeEscCharFromTerm(ATerm t);
ATerm SDF_makeTermFromEscChar(SDF_EscChar arg);
SDF_LChar SDF_makeLCharFromTerm(ATerm t);
ATerm SDF_makeTermFromLChar(SDF_LChar arg);
SDF_ATerms SDF_makeATermsFromTerm(ATerm t);
ATerm SDF_makeTermFromATerms(SDF_ATerms arg);
SDF_ATermList SDF_makeATermListFromTerm(ATerm t);
ATerm SDF_makeTermFromATermList(SDF_ATermList arg);
SDF_ACon SDF_makeAConFromTerm(ATerm t);
ATerm SDF_makeTermFromACon(SDF_ACon arg);
SDF_AFun SDF_makeAFunFromTerm(ATerm t);
ATerm SDF_makeTermFromAFun(SDF_AFun arg);
SDF_ATerm SDF_makeATermFromTerm(ATerm t);
ATerm SDF_makeTermFromATerm(SDF_ATerm arg);
SDF_Ann SDF_makeAnnFromTerm(ATerm t);
ATerm SDF_makeTermFromAnn(SDF_Ann arg);
SDF_TagId SDF_makeTagIdFromTerm(ATerm t);
ATerm SDF_makeTermFromTagId(SDF_TagId arg);
SDF_NumChar SDF_makeNumCharFromTerm(ATerm t);
ATerm SDF_makeTermFromNumChar(SDF_NumChar arg);
SDF_ShortChar SDF_makeShortCharFromTerm(ATerm t);
ATerm SDF_makeTermFromShortChar(SDF_ShortChar arg);
SDF_Character SDF_makeCharacterFromTerm(ATerm t);
ATerm SDF_makeTermFromCharacter(SDF_Character arg);
SDF_OptExp SDF_makeOptExpFromTerm(ATerm t);
ATerm SDF_makeTermFromOptExp(SDF_OptExp arg);
SDF_RealCon SDF_makeRealConFromTerm(ATerm t);
ATerm SDF_makeTermFromRealCon(SDF_RealCon arg);

SDF_Symbol SDF_makeSymbolStart();
SDF_Symbol SDF_makeSymbolFileStart();
SDF_Symbol SDF_makeSymbolCf(SDF_Layout wsAfterLessThan, SDF_Symbol symbol, SDF_Layout wsAfterSymbol, SDF_Layout wsAfterCF);
SDF_Symbol SDF_makeSymbolLex(SDF_Layout wsAfterLessThan, SDF_Symbol symbol, SDF_Layout wsAfterSymbol, SDF_Layout wsAfterLEX);
SDF_Symbol SDF_makeSymbolVarsym(SDF_Layout wsAfterLessThan, SDF_Symbol symbol, SDF_Layout wsAfterSymbol, SDF_Layout wsAfterVAR);
SDF_Symbol SDF_makeSymbolLayout();
SDF_Symbol SDF_makeSymbolEmpty(SDF_Layout wsAfterParenOpen);
SDF_Symbol SDF_makeSymbolSeq(SDF_Layout wsAfterParenOpen, SDF_Symbol head, SDF_Layout wsAfterHead, SDF_SymbolTail tail, SDF_Layout wsAfterTail);
SDF_Symbol SDF_makeSymbolOpt(SDF_Symbol symbol, SDF_Layout wsAfterSymbol);
SDF_Symbol SDF_makeSymbolIter(SDF_Symbol symbol, SDF_Layout wsAfterSymbol);
SDF_Symbol SDF_makeSymbolIterStar(SDF_Symbol symbol, SDF_Layout wsAfterSymbol);
SDF_Symbol SDF_makeSymbolIterSep(SDF_Layout wsAfterBraceOpen, SDF_Symbol symbol, SDF_Layout wsAfterSymbol, SDF_Symbol sep, SDF_Layout wsAfterSep, SDF_Layout wsAfterBraceClose);
SDF_Symbol SDF_makeSymbolIterStarSep(SDF_Layout wsAfterBraceOpen, SDF_Symbol symbol, SDF_Layout wsAfterSymbol, SDF_Symbol sep, SDF_Layout wsAfterSep, SDF_Layout wsAfterBraceClose);
SDF_Symbol SDF_makeSymbolIterN(SDF_Symbol symbol, SDF_Layout wsAfterSymbol, SDF_NatCon n, SDF_Layout wsAfterN);
SDF_Symbol SDF_makeSymbolIterSepN(SDF_Layout wsAfterBraceOpen, SDF_Symbol symbol, SDF_Layout wsAfterSymbol, SDF_Symbol sep, SDF_Layout wsAfterSep, SDF_Layout wsAfterBraceClose, SDF_NatCon n, SDF_Layout wsAfterN);
SDF_Symbol SDF_makeSymbolSet(SDF_Layout wsAfterSet, SDF_Layout wsAfterBracketOpen, SDF_Symbol symbol, SDF_Layout wsAfterSymbol);
SDF_Symbol SDF_makeSymbolPair(SDF_Symbol left, SDF_Layout wsAfterLeft, SDF_Layout wsAfterHash, SDF_Symbol right);
SDF_Symbol SDF_makeSymbolFunc(SDF_Layout wsAfterParenOpen, SDF_Symbols arguments, SDF_Layout wsAfterArguments, SDF_Layout wsAfterEqualsGreaterThan, SDF_Symbol results, SDF_Layout wsAfterResults);
SDF_Symbol SDF_makeSymbolAlt(SDF_Symbol left, SDF_Layout wsAfterLeft, SDF_Layout wsAfterBar, SDF_Symbol right);
SDF_Symbol SDF_makeSymbolPerm(SDF_Layout wsAfterLessThanLessThan, SDF_Symbols symbols, SDF_Layout wsAfterSymbols);
SDF_Symbol SDF_makeSymbolCharClass(SDF_CharClass charClass);
SDF_Symbol SDF_makeSymbolSort(SDF_Sort sort);
SDF_Symbol SDF_makeSymbolLit(SDF_Literal literal);
SDF_Symbol SDF_makeSymbolLabel(SDF_Literal label, SDF_Layout wsAfterLabel, SDF_Layout wsAfterColon, SDF_Symbol symbol);
SDF_Symbol SDF_makeSymbolBracket(SDF_Layout wsAfterParenOpen, SDF_Symbol symbol, SDF_Layout wsAfterSymbol);
SDF_Grammar SDF_makeGrammarLexicalPriorities(SDF_Layout wsAfterLexical, SDF_Layout wsAfterPriorities, SDF_Priorities priorities);
SDF_Grammar SDF_makeGrammarContextFreePriorities(SDF_Layout wsAfterContextFree, SDF_Layout wsAfterPriorities, SDF_Priorities priorities);
SDF_Grammar SDF_makeGrammarLexicalRestrictions(SDF_Layout wsAfterLexical, SDF_Layout wsAfterRestrictions, SDF_Restrictions restrictions);
SDF_Grammar SDF_makeGrammarContextFreeRestrictions(SDF_Layout wsAfterContextFree, SDF_Layout wsAfterRestrictions, SDF_Restrictions restrictions);
SDF_Grammar SDF_makeGrammarSyntax(SDF_Layout wsAfterSyntax, SDF_Productions productions);
SDF_Grammar SDF_makeGrammarLexicalSyntax(SDF_Layout wsAfterLexical, SDF_Layout wsAfterSyntax, SDF_Productions productions);
SDF_Grammar SDF_makeGrammarContextFreeSyntax(SDF_Layout wsAfterContextFree, SDF_Layout wsAfterSyntax, SDF_Productions productions);
SDF_Grammar SDF_makeGrammarVariables(SDF_Layout wsAfterVariables, SDF_Productions productions);
SDF_Grammar SDF_makeGrammarLexicalVariables(SDF_Layout wsAfterLexical, SDF_Layout wsAfterVariables, SDF_Productions productions);
SDF_Grammar SDF_makeGrammarImpSection(SDF_ImpSection impSection);
SDF_Grammar SDF_makeGrammarPriorities(SDF_Layout wsAfterPriorities, SDF_Priorities priorities);
SDF_Grammar SDF_makeGrammarSorts(SDF_Layout wsAfterSorts, SDF_Symbols symbols);
SDF_Grammar SDF_makeGrammarRestrictions(SDF_Layout wsAfterRestrictions, SDF_Restrictions restrictions);
SDF_Grammar SDF_makeGrammarAliases(SDF_Layout wsAfterAliases, SDF_Aliases aliases);
SDF_Grammar SDF_makeGrammarEmptyGrammar();
SDF_Grammar SDF_makeGrammarConcGrammars(SDF_Grammar left, SDF_Layout wsAfterLeft, SDF_Grammar right);
SDF_Grammar SDF_makeGrammarBracket(SDF_Layout wsAfterParenOpen, SDF_Grammar grammar, SDF_Layout wsAfterGrammar);
SDF_SDF SDF_makeSDFDefinition(SDF_Layout wsAfterDefinition, SDF_Definition definition);
SDF_Attributes SDF_makeAttributesAttrs(SDF_Layout wsAfterBraceOpen, SDF_AttributeList list, SDF_Layout wsAfterList);
SDF_Attributes SDF_makeAttributesNoAttrs();
SDF_AttributeList SDF_makeAttributeListEmpty();
SDF_AttributeList SDF_makeAttributeListSingle(SDF_Attribute head);
SDF_AttributeList SDF_makeAttributeListMany(SDF_Attribute head, SDF_Layout wsAfterFirst, SDF_Separator sep, SDF_Layout wsAfterSep, SDF_AttributeList tail);
SDF_Production SDF_makeProductionProd(SDF_Symbols symbols, SDF_Layout wsAfterSymbols, SDF_Layout wsAfterGreaterThan, SDF_Symbol result, SDF_Layout wsAfterResult, SDF_Attributes attributes);
SDF_Production SDF_makeProductionProdFun(SDF_Literal functionSymbol, SDF_Layout wsAfterFunctionSymbol, SDF_Layout wsAfterParenOpen, SDF_SymbolArguments arguments, SDF_Layout wsAfterArguments, SDF_Layout wsAfterParenClose, SDF_Layout wsAfterGreaterThan, SDF_Symbol result, SDF_Layout wsAfterResult, SDF_Attributes attributes);
SDF_Productions SDF_makeProductionsDefault(SDF_ProductionList list);
SDF_ProductionList SDF_makeProductionListEmpty();
SDF_ProductionList SDF_makeProductionListSingle(SDF_Production head);
SDF_ProductionList SDF_makeProductionListMany(SDF_Production head, SDF_Layout wsAfterFirst, SDF_ProductionList tail);
SDF_ModuleWord SDF_makeModuleWordWord(SDF_Lexical lex);
SDF_ModuleId SDF_makeModuleIdWord(SDF_Lexical lex);
SDF_ModuleId SDF_makeModuleIdSlashWord(SDF_Lexical lex);
SDF_ModuleId SDF_makeModuleIdWordSlashWord(SDF_Lexical lex);
SDF_Definition SDF_makeDefinitionDefault(SDF_ModuleList list);
SDF_ModuleList SDF_makeModuleListEmpty();
SDF_ModuleList SDF_makeModuleListSingle(SDF_Module head);
SDF_ModuleList SDF_makeModuleListMany(SDF_Module head, SDF_Layout wsAfterFirst, SDF_ModuleList tail);
SDF_Module SDF_makeModuleModule(SDF_Layout wsAfterModule, SDF_ModuleName moduleName, SDF_Layout wsAfterModuleName, SDF_ImpSectionList list, SDF_Layout wsAfterList, SDF_Sections sections);
SDF_ImpSectionList SDF_makeImpSectionListEmpty();
SDF_ImpSectionList SDF_makeImpSectionListSingle(SDF_ImpSection head);
SDF_ImpSectionList SDF_makeImpSectionListMany(SDF_ImpSection head, SDF_Layout wsAfterFirst, SDF_ImpSectionList tail);
SDF_Section SDF_makeSectionExports(SDF_Layout wsAfterExports, SDF_Grammar grammar);
SDF_Section SDF_makeSectionHiddens(SDF_Layout wsAfterHiddens, SDF_Grammar grammar);
SDF_Sections SDF_makeSectionsDefault(SDF_SectionList list);
SDF_SectionList SDF_makeSectionListEmpty();
SDF_SectionList SDF_makeSectionListSingle(SDF_Section head);
SDF_SectionList SDF_makeSectionListMany(SDF_Section head, SDF_Layout wsAfterFirst, SDF_SectionList tail);
SDF_ModuleName SDF_makeModuleNameUnparameterized(SDF_ModuleId moduleId);
SDF_ModuleName SDF_makeModuleNameParameterized(SDF_ModuleId moduleId, SDF_Layout wsAfterModuleId, SDF_Layout wsAfterBracketOpen, SDF_Symbols params, SDF_Layout wsAfterParams);
SDF_Attribute SDF_makeAttributeId(SDF_Layout wsAfterId, SDF_Layout wsAfterParenOpen, SDF_ModuleName moduleName, SDF_Layout wsAfterModuleName);
SDF_Attribute SDF_makeAttributeBracket();
SDF_Attribute SDF_makeAttributeAtr(SDF_Associativity associativity);
SDF_Attribute SDF_makeAttributeCons(SDF_Layout wsAfterCons, SDF_Layout wsAfterParenOpen, SDF_ATerm aTerm, SDF_Layout wsAfterATerm);
SDF_Attribute SDF_makeAttributeConstructor();
SDF_Attribute SDF_makeAttributeMemo();
SDF_Attribute SDF_makeAttributeReject();
SDF_Attribute SDF_makeAttributePrefer();
SDF_Attribute SDF_makeAttributeAvoid();
SDF_ImpSection SDF_makeImpSectionImports(SDF_Layout wsAfterImports, SDF_Imports list);
SDF_Imports SDF_makeImportsDefault(SDF_ImportList list);
SDF_ImportList SDF_makeImportListEmpty();
SDF_ImportList SDF_makeImportListSingle(SDF_Import head);
SDF_ImportList SDF_makeImportListMany(SDF_Import head, SDF_Layout wsAfterFirst, SDF_ImportList tail);
SDF_Import SDF_makeImportModule(SDF_ModuleName moduleName);
SDF_Import SDF_makeImportRenamedModule(SDF_ModuleName moduleName, SDF_Layout wsAfterModuleName, SDF_Renamings renamings);
SDF_Import SDF_makeImportBracket(SDF_Layout wsAfterParenOpen, SDF_Import import, SDF_Layout wsAfterImport);
SDF_SymbolTail SDF_makeSymbolTailSingle(SDF_Symbol head);
SDF_SymbolTail SDF_makeSymbolTailMany(SDF_Symbol head, SDF_Layout wsAfterFirst, SDF_SymbolTail tail);
SDF_Associativity SDF_makeAssociativityLeft();
SDF_Associativity SDF_makeAssociativityRight();
SDF_Associativity SDF_makeAssociativityNonAssoc();
SDF_Associativity SDF_makeAssociativityAssoc();
SDF_Group SDF_makeGroupSimpleGroup(SDF_Production production);
SDF_Group SDF_makeGroupProdsGroup(SDF_Layout wsAfterBraceOpen, SDF_Productions productions, SDF_Layout wsAfterProductions);
SDF_Group SDF_makeGroupAssocGroup(SDF_Layout wsAfterBraceOpen, SDF_Associativity associativity, SDF_Layout wsAfterAssociativity, SDF_Layout wsAfterColon, SDF_Productions productions, SDF_Layout wsAfterProductions);
SDF_Priority SDF_makePriorityPriorityChain(SDF_GroupGroupp groupp);
SDF_Priority SDF_makePriorityPriorityAssoc(SDF_Group left, SDF_Layout wsAfterLeft, SDF_Associativity associativity, SDF_Layout wsAfterAssociativity, SDF_Group right);
SDF_GroupGroupp SDF_makeGroupGrouppSingle(SDF_Group head);
SDF_GroupGroupp SDF_makeGroupGrouppMany(SDF_Group head, SDF_Layout wsAfterFirst, SDF_Separator sep, SDF_Layout wsAfterSep, SDF_GroupGroupp tail);
SDF_Priorities SDF_makePrioritiesDefault(SDF_PriorityList list);
SDF_PriorityList SDF_makePriorityListEmpty();
SDF_PriorityList SDF_makePriorityListSingle(SDF_Priority head);
SDF_PriorityList SDF_makePriorityListMany(SDF_Priority head, SDF_Layout wsAfterFirst, SDF_Separator sep, SDF_Layout wsAfterSep, SDF_PriorityList tail);
SDF_Sort SDF_makeSortOneChar(SDF_Lexical lex);
SDF_Sort SDF_makeSortMoreChars(SDF_Lexical lex);
SDF_UQLiteral SDF_makeUQLiteralOneChar(SDF_Lexical lex);
SDF_UQLiteral SDF_makeUQLiteralMoreChars(SDF_Lexical lex);
SDF_Literal SDF_makeLiteralUqlit(SDF_UQLiteral uQLiteral);
SDF_Literal SDF_makeLiteralQuoted(SDF_Lexical lex);
SDF_SymbolArguments SDF_makeSymbolArgumentsEmpty();
SDF_SymbolArguments SDF_makeSymbolArgumentsSingle(SDF_Symbol head);
SDF_SymbolArguments SDF_makeSymbolArgumentsMany(SDF_Symbol head, SDF_Layout wsAfterFirst, SDF_Separator sep, SDF_Layout wsAfterSep, SDF_SymbolArguments tail);
SDF_Lookahead SDF_makeLookaheadCharClass(SDF_CharClass charClass);
SDF_Lookahead SDF_makeLookaheadSeq(SDF_CharClass head, SDF_Layout wsAfterHead, SDF_Layout wsAfterPeriod, SDF_Lookaheads tail);
SDF_Lookaheads SDF_makeLookaheadsSingle(SDF_Lookahead lookahead);
SDF_Lookaheads SDF_makeLookaheadsAlt(SDF_Lookaheads left, SDF_Layout wsAfterLeft, SDF_Layout wsAfterBar, SDF_Lookaheads right);
SDF_Lookaheads SDF_makeLookaheadsBracket(SDF_Layout wsAfterParenOpen, SDF_Lookaheads lookaheads, SDF_Layout wsAfterLookaheads);
SDF_Lookaheads SDF_makeLookaheadsList(SDF_Layout wsAfterBracketOpenBracketOpen, SDF_LookaheadList list, SDF_Layout wsAfterList);
SDF_LookaheadList SDF_makeLookaheadListEmpty();
SDF_LookaheadList SDF_makeLookaheadListSingle(SDF_Lookahead head);
SDF_LookaheadList SDF_makeLookaheadListMany(SDF_Lookahead head, SDF_Layout wsAfterFirst, SDF_Separator sep, SDF_Layout wsAfterSep, SDF_LookaheadList tail);
SDF_Restriction SDF_makeRestrictionFollow(SDF_Symbols symbols, SDF_Layout wsAfterSymbols, SDF_Layout wsAfterSlash, SDF_Lookaheads lookaheads);
SDF_Restrictions SDF_makeRestrictionsDefault(SDF_RestrictionList list);
SDF_RestrictionList SDF_makeRestrictionListEmpty();
SDF_RestrictionList SDF_makeRestrictionListSingle(SDF_Restriction head);
SDF_RestrictionList SDF_makeRestrictionListMany(SDF_Restriction head, SDF_Layout wsAfterFirst, SDF_RestrictionList tail);
SDF_Alias SDF_makeAliasAlias(SDF_Symbol symbol, SDF_Layout wsAfterSymbol, SDF_Layout wsAfterArrow, SDF_Symbol alias);
SDF_Aliases SDF_makeAliasesDefault(SDF_AliasList list);
SDF_AliasList SDF_makeAliasListEmpty();
SDF_AliasList SDF_makeAliasListSingle(SDF_Alias head);
SDF_AliasList SDF_makeAliasListMany(SDF_Alias head, SDF_Layout wsAfterFirst, SDF_AliasList tail);
SDF_Symbols SDF_makeSymbolsDefault(SDF_SymbolList list);
SDF_SymbolList SDF_makeSymbolListEmpty();
SDF_SymbolList SDF_makeSymbolListSingle(SDF_Symbol head);
SDF_SymbolList SDF_makeSymbolListMany(SDF_Symbol head, SDF_Layout wsAfterFirst, SDF_SymbolList tail);
SDF_Renamings SDF_makeRenamingsRenamings(SDF_Layout wsAfterBracketOpen, SDF_RenamingList list, SDF_Layout wsAfterList);
SDF_RenamingList SDF_makeRenamingListEmpty();
SDF_RenamingList SDF_makeRenamingListSingle(SDF_Renaming head);
SDF_RenamingList SDF_makeRenamingListMany(SDF_Renaming head, SDF_Layout wsAfterFirst, SDF_RenamingList tail);
SDF_Renaming SDF_makeRenamingSymbol(SDF_Symbol from, SDF_Layout wsAfterFrom, SDF_Layout wsAfterEqualsGreaterThan, SDF_Symbol to);
SDF_Renaming SDF_makeRenamingProduction(SDF_Symbol from, SDF_Layout wsAfterFrom, SDF_Layout wsAfterEqualsGreaterThan, SDF_Symbol to);
SDF_NatCon SDF_makeNatConDigits(SDF_Lexical lex);
SDF_IntCon SDF_makeIntConNatural(SDF_NatCon natCon);
SDF_IntCon SDF_makeIntConPositive(SDF_Layout wsAfterPos, SDF_NatCon natCon);
SDF_IntCon SDF_makeIntConNegative(SDF_Layout wsAfterNeg, SDF_NatCon natCon);
SDF_CharRange SDF_makeCharRangeDefault(SDF_Character character);
SDF_CharRange SDF_makeCharRangeRange(SDF_Character start, SDF_Layout wsAfterStart, SDF_Layout wsAfter, SDF_Character end);
SDF_CharRanges SDF_makeCharRangesDefault(SDF_CharRange charRange);
SDF_CharRanges SDF_makeCharRangesConc(SDF_CharRanges left, SDF_Layout wsAfterLeft, SDF_CharRanges right);
SDF_CharRanges SDF_makeCharRangesBracket(SDF_Layout wsAfterParenOpen, SDF_CharRanges charRanges, SDF_Layout wsAfterCharRanges);
SDF_OptCharRanges SDF_makeOptCharRangesAbsent();
SDF_OptCharRanges SDF_makeOptCharRangesPresent(SDF_CharRanges charRanges);
SDF_CharClass SDF_makeCharClassSimpleCharclass(SDF_Layout wsAfterBracketOpen, SDF_OptCharRanges optCharRanges, SDF_Layout wsAfterOptCharRanges);
SDF_CharClass SDF_makeCharClassComp(SDF_Layout wsAfterTilde, SDF_CharClass charClass);
SDF_CharClass SDF_makeCharClassDiff(SDF_CharClass left, SDF_Layout wsAfterLeft, SDF_Layout wsAfterSlash, SDF_CharClass right);
SDF_CharClass SDF_makeCharClassIsect(SDF_CharClass left, SDF_Layout wsAfterLeft, SDF_Layout wsAfterSlashBackslash, SDF_CharClass right);
SDF_CharClass SDF_makeCharClassUnion(SDF_CharClass left, SDF_Layout wsAfterLeft, SDF_Layout wsAfterBackslashSlash, SDF_CharClass right);
SDF_CharClass SDF_makeCharClassBracket(SDF_Layout wsAfterParenOpen, SDF_CharClass charClass, SDF_Layout wsAfterCharClass);
SDF_AlphaNumericalEscChar SDF_makeAlphaNumericalEscCharDefault(SDF_Lexical lex);
SDF_DecimalEscChar SDF_makeDecimalEscCharDec0_199(SDF_Lexical lex);
SDF_DecimalEscChar SDF_makeDecimalEscCharDec200_249(SDF_Lexical lex);
SDF_DecimalEscChar SDF_makeDecimalEscCharDec250_255(SDF_Lexical lex);
SDF_EscChar SDF_makeEscCharAlphaNumeric(SDF_Lexical lex);
SDF_EscChar SDF_makeEscCharDecimal(SDF_Lexical lex);
SDF_LChar SDF_makeLCharNormal(SDF_Lexical lex);
SDF_LChar SDF_makeLCharEscaped(SDF_Lexical lex);
SDF_ATerms SDF_makeATermsAterm(SDF_ATerm aTerm);
SDF_ATerms SDF_makeATermsCons(SDF_ATerm head, SDF_Layout wsAfterHead, SDF_Layout wsAfterComma, SDF_ATerms tail);
SDF_ATermList SDF_makeATermListEmpty(SDF_Layout wsAfterBracketOpen);
SDF_ATermList SDF_makeATermListNotEmpty(SDF_Layout wsAfterBracketOpen, SDF_ATerms aTerms, SDF_Layout wsAfterATerms);
SDF_ACon SDF_makeAConInt(SDF_IntCon intCon);
SDF_ACon SDF_makeAConReal(SDF_RealCon realCon);
SDF_AFun SDF_makeAFunDefault(SDF_Literal literal);
SDF_ATerm SDF_makeATermConstant(SDF_ACon aCon);
SDF_ATerm SDF_makeATermList(SDF_ATermList aTermList);
SDF_ATerm SDF_makeATermFun(SDF_AFun aFun);
SDF_ATerm SDF_makeATermAppl(SDF_AFun aFun, SDF_Layout wsAfterAFun, SDF_Layout wsAfterParenOpen, SDF_ATerms args, SDF_Layout wsAfterArgs);
SDF_ATerm SDF_makeATermAnnotatedConstant(SDF_ACon aCon, SDF_Layout wsAfterACon, SDF_Ann ann);
SDF_ATerm SDF_makeATermAnnotatedList(SDF_ATermList aTermList, SDF_Layout wsAfterATermList, SDF_Ann ann);
SDF_ATerm SDF_makeATermAnnotatedFun(SDF_AFun aFun, SDF_Layout wsAfterAFun, SDF_Ann ann);
SDF_ATerm SDF_makeATermAnnotatedAppl(SDF_AFun aFun, SDF_Layout wsAfterAFun, SDF_Layout wsAfterParenOpen, SDF_ATerms args, SDF_Layout wsAfterArgs, SDF_Layout wsAfterParenClose, SDF_Ann ann);
SDF_Ann SDF_makeAnnAnnotation(SDF_Layout wsAfterBraceOpen, SDF_ATerms aTerms, SDF_Layout wsAfterATerms);
SDF_TagId SDF_makeTagIdDefault(SDF_Lexical lex);
SDF_TagId SDF_makeTagIdEmpty();
SDF_NumChar SDF_makeNumCharDigits(SDF_Lexical lex);
SDF_ShortChar SDF_makeShortCharRegular(SDF_Lexical lex);
SDF_ShortChar SDF_makeShortCharEscaped(SDF_Lexical lex);
SDF_Character SDF_makeCharacterNumeric(SDF_NumChar numChar);
SDF_Character SDF_makeCharacterShort(SDF_ShortChar shortChar);
SDF_Character SDF_makeCharacterTop();
SDF_Character SDF_makeCharacterEof();
SDF_OptExp SDF_makeOptExpPresent(SDF_Layout wsAfterE, SDF_IntCon intCon);
SDF_OptExp SDF_makeOptExpAbsent();
SDF_RealCon SDF_makeRealConRealCon(SDF_IntCon intCon, SDF_Layout wsAfterIntCon, SDF_Layout wsAfterPeriod, SDF_NatCon natCon, SDF_Layout wsAfterNatCon, SDF_OptExp optExp);

/*{{{  equality functions */

ATbool SDF_isEqualSymbol(SDF_Symbol arg0, SDF_Symbol arg1);
ATbool SDF_isEqualGrammar(SDF_Grammar arg0, SDF_Grammar arg1);
ATbool SDF_isEqualSDF(SDF_SDF arg0, SDF_SDF arg1);
ATbool SDF_isEqualAttributes(SDF_Attributes arg0, SDF_Attributes arg1);
ATbool SDF_isEqualAttributeList(SDF_AttributeList arg0, SDF_AttributeList arg1);
ATbool SDF_isEqualProduction(SDF_Production arg0, SDF_Production arg1);
ATbool SDF_isEqualProductions(SDF_Productions arg0, SDF_Productions arg1);
ATbool SDF_isEqualProductionList(SDF_ProductionList arg0, SDF_ProductionList arg1);
ATbool SDF_isEqualModuleWord(SDF_ModuleWord arg0, SDF_ModuleWord arg1);
ATbool SDF_isEqualModuleId(SDF_ModuleId arg0, SDF_ModuleId arg1);
ATbool SDF_isEqualDefinition(SDF_Definition arg0, SDF_Definition arg1);
ATbool SDF_isEqualModuleList(SDF_ModuleList arg0, SDF_ModuleList arg1);
ATbool SDF_isEqualModule(SDF_Module arg0, SDF_Module arg1);
ATbool SDF_isEqualImpSectionList(SDF_ImpSectionList arg0, SDF_ImpSectionList arg1);
ATbool SDF_isEqualSection(SDF_Section arg0, SDF_Section arg1);
ATbool SDF_isEqualSections(SDF_Sections arg0, SDF_Sections arg1);
ATbool SDF_isEqualSectionList(SDF_SectionList arg0, SDF_SectionList arg1);
ATbool SDF_isEqualModuleName(SDF_ModuleName arg0, SDF_ModuleName arg1);
ATbool SDF_isEqualAttribute(SDF_Attribute arg0, SDF_Attribute arg1);
ATbool SDF_isEqualImpSection(SDF_ImpSection arg0, SDF_ImpSection arg1);
ATbool SDF_isEqualImports(SDF_Imports arg0, SDF_Imports arg1);
ATbool SDF_isEqualImportList(SDF_ImportList arg0, SDF_ImportList arg1);
ATbool SDF_isEqualImport(SDF_Import arg0, SDF_Import arg1);
ATbool SDF_isEqualSymbolTail(SDF_SymbolTail arg0, SDF_SymbolTail arg1);
ATbool SDF_isEqualAssociativity(SDF_Associativity arg0, SDF_Associativity arg1);
ATbool SDF_isEqualGroup(SDF_Group arg0, SDF_Group arg1);
ATbool SDF_isEqualPriority(SDF_Priority arg0, SDF_Priority arg1);
ATbool SDF_isEqualGroupGroupp(SDF_GroupGroupp arg0, SDF_GroupGroupp arg1);
ATbool SDF_isEqualPriorities(SDF_Priorities arg0, SDF_Priorities arg1);
ATbool SDF_isEqualPriorityList(SDF_PriorityList arg0, SDF_PriorityList arg1);
ATbool SDF_isEqualSort(SDF_Sort arg0, SDF_Sort arg1);
ATbool SDF_isEqualUQLiteral(SDF_UQLiteral arg0, SDF_UQLiteral arg1);
ATbool SDF_isEqualLiteral(SDF_Literal arg0, SDF_Literal arg1);
ATbool SDF_isEqualSymbolArguments(SDF_SymbolArguments arg0, SDF_SymbolArguments arg1);
ATbool SDF_isEqualLookahead(SDF_Lookahead arg0, SDF_Lookahead arg1);
ATbool SDF_isEqualLookaheads(SDF_Lookaheads arg0, SDF_Lookaheads arg1);
ATbool SDF_isEqualLookaheadList(SDF_LookaheadList arg0, SDF_LookaheadList arg1);
ATbool SDF_isEqualRestriction(SDF_Restriction arg0, SDF_Restriction arg1);
ATbool SDF_isEqualRestrictions(SDF_Restrictions arg0, SDF_Restrictions arg1);
ATbool SDF_isEqualRestrictionList(SDF_RestrictionList arg0, SDF_RestrictionList arg1);
ATbool SDF_isEqualAlias(SDF_Alias arg0, SDF_Alias arg1);
ATbool SDF_isEqualAliases(SDF_Aliases arg0, SDF_Aliases arg1);
ATbool SDF_isEqualAliasList(SDF_AliasList arg0, SDF_AliasList arg1);
ATbool SDF_isEqualSymbols(SDF_Symbols arg0, SDF_Symbols arg1);
ATbool SDF_isEqualSymbolList(SDF_SymbolList arg0, SDF_SymbolList arg1);
ATbool SDF_isEqualRenamings(SDF_Renamings arg0, SDF_Renamings arg1);
ATbool SDF_isEqualRenamingList(SDF_RenamingList arg0, SDF_RenamingList arg1);
ATbool SDF_isEqualRenaming(SDF_Renaming arg0, SDF_Renaming arg1);
ATbool SDF_isEqualNatCon(SDF_NatCon arg0, SDF_NatCon arg1);
ATbool SDF_isEqualIntCon(SDF_IntCon arg0, SDF_IntCon arg1);
ATbool SDF_isEqualCharRange(SDF_CharRange arg0, SDF_CharRange arg1);
ATbool SDF_isEqualCharRanges(SDF_CharRanges arg0, SDF_CharRanges arg1);
ATbool SDF_isEqualOptCharRanges(SDF_OptCharRanges arg0, SDF_OptCharRanges arg1);
ATbool SDF_isEqualCharClass(SDF_CharClass arg0, SDF_CharClass arg1);
ATbool SDF_isEqualAlphaNumericalEscChar(SDF_AlphaNumericalEscChar arg0, SDF_AlphaNumericalEscChar arg1);
ATbool SDF_isEqualDecimalEscChar(SDF_DecimalEscChar arg0, SDF_DecimalEscChar arg1);
ATbool SDF_isEqualEscChar(SDF_EscChar arg0, SDF_EscChar arg1);
ATbool SDF_isEqualLChar(SDF_LChar arg0, SDF_LChar arg1);
ATbool SDF_isEqualATerms(SDF_ATerms arg0, SDF_ATerms arg1);
ATbool SDF_isEqualATermList(SDF_ATermList arg0, SDF_ATermList arg1);
ATbool SDF_isEqualACon(SDF_ACon arg0, SDF_ACon arg1);
ATbool SDF_isEqualAFun(SDF_AFun arg0, SDF_AFun arg1);
ATbool SDF_isEqualATerm(SDF_ATerm arg0, SDF_ATerm arg1);
ATbool SDF_isEqualAnn(SDF_Ann arg0, SDF_Ann arg1);
ATbool SDF_isEqualTagId(SDF_TagId arg0, SDF_TagId arg1);
ATbool SDF_isEqualNumChar(SDF_NumChar arg0, SDF_NumChar arg1);
ATbool SDF_isEqualShortChar(SDF_ShortChar arg0, SDF_ShortChar arg1);
ATbool SDF_isEqualCharacter(SDF_Character arg0, SDF_Character arg1);
ATbool SDF_isEqualOptExp(SDF_OptExp arg0, SDF_OptExp arg1);
ATbool SDF_isEqualRealCon(SDF_RealCon arg0, SDF_RealCon arg1);

/*}}}  */
/*{{{  SDF_Symbol accessor prototypes */

ATbool SDF_isValidSymbol(SDF_Symbol arg);
ATbool SDF_isSymbolStart(SDF_Symbol arg);
ATbool SDF_isSymbolFileStart(SDF_Symbol arg);
ATbool SDF_isSymbolCf(SDF_Symbol arg);
ATbool SDF_isSymbolLex(SDF_Symbol arg);
ATbool SDF_isSymbolVarsym(SDF_Symbol arg);
ATbool SDF_isSymbolLayout(SDF_Symbol arg);
ATbool SDF_isSymbolEmpty(SDF_Symbol arg);
ATbool SDF_isSymbolSeq(SDF_Symbol arg);
ATbool SDF_isSymbolOpt(SDF_Symbol arg);
ATbool SDF_isSymbolIter(SDF_Symbol arg);
ATbool SDF_isSymbolIterStar(SDF_Symbol arg);
ATbool SDF_isSymbolIterSep(SDF_Symbol arg);
ATbool SDF_isSymbolIterStarSep(SDF_Symbol arg);
ATbool SDF_isSymbolIterN(SDF_Symbol arg);
ATbool SDF_isSymbolIterSepN(SDF_Symbol arg);
ATbool SDF_isSymbolSet(SDF_Symbol arg);
ATbool SDF_isSymbolPair(SDF_Symbol arg);
ATbool SDF_isSymbolFunc(SDF_Symbol arg);
ATbool SDF_isSymbolAlt(SDF_Symbol arg);
ATbool SDF_isSymbolPerm(SDF_Symbol arg);
ATbool SDF_isSymbolCharClass(SDF_Symbol arg);
ATbool SDF_isSymbolSort(SDF_Symbol arg);
ATbool SDF_isSymbolLit(SDF_Symbol arg);
ATbool SDF_isSymbolLabel(SDF_Symbol arg);
ATbool SDF_isSymbolBracket(SDF_Symbol arg);
ATbool SDF_hasSymbolWsAfterLessThanLessThan(SDF_Symbol arg);
SDF_Layout SDF_getSymbolWsAfterLessThanLessThan(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterLessThanLessThan(SDF_Symbol arg, SDF_Layout wsAfterLessThanLessThan);
ATbool SDF_hasSymbolRight(SDF_Symbol arg);
SDF_Symbol SDF_getSymbolRight(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolRight(SDF_Symbol arg, SDF_Symbol right);
ATbool SDF_hasSymbolWsAfterLeft(SDF_Symbol arg);
SDF_Layout SDF_getSymbolWsAfterLeft(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterLeft(SDF_Symbol arg, SDF_Layout wsAfterLeft);
ATbool SDF_hasSymbolWsAfterParenOpen(SDF_Symbol arg);
SDF_Layout SDF_getSymbolWsAfterParenOpen(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterParenOpen(SDF_Symbol arg, SDF_Layout wsAfterParenOpen);
ATbool SDF_hasSymbolWsAfterArguments(SDF_Symbol arg);
SDF_Layout SDF_getSymbolWsAfterArguments(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterArguments(SDF_Symbol arg, SDF_Layout wsAfterArguments);
ATbool SDF_hasSymbolWsAfterResults(SDF_Symbol arg);
SDF_Layout SDF_getSymbolWsAfterResults(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterResults(SDF_Symbol arg, SDF_Layout wsAfterResults);
ATbool SDF_hasSymbolWsAfterHash(SDF_Symbol arg);
SDF_Layout SDF_getSymbolWsAfterHash(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterHash(SDF_Symbol arg, SDF_Layout wsAfterHash);
ATbool SDF_hasSymbolWsAfterCF(SDF_Symbol arg);
SDF_Layout SDF_getSymbolWsAfterCF(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterCF(SDF_Symbol arg, SDF_Layout wsAfterCF);
ATbool SDF_hasSymbolSort(SDF_Symbol arg);
SDF_Sort SDF_getSymbolSort(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolSort(SDF_Symbol arg, SDF_Sort sort);
ATbool SDF_hasSymbolWsAfterBraceClose(SDF_Symbol arg);
SDF_Layout SDF_getSymbolWsAfterBraceClose(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterBraceClose(SDF_Symbol arg, SDF_Layout wsAfterBraceClose);
ATbool SDF_hasSymbolWsAfterBar(SDF_Symbol arg);
SDF_Layout SDF_getSymbolWsAfterBar(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterBar(SDF_Symbol arg, SDF_Layout wsAfterBar);
ATbool SDF_hasSymbolWsAfterBraceOpen(SDF_Symbol arg);
SDF_Layout SDF_getSymbolWsAfterBraceOpen(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterBraceOpen(SDF_Symbol arg, SDF_Layout wsAfterBraceOpen);
ATbool SDF_hasSymbolArguments(SDF_Symbol arg);
SDF_Symbols SDF_getSymbolArguments(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolArguments(SDF_Symbol arg, SDF_Symbols arguments);
ATbool SDF_hasSymbolWsAfterSymbols(SDF_Symbol arg);
SDF_Layout SDF_getSymbolWsAfterSymbols(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterSymbols(SDF_Symbol arg, SDF_Layout wsAfterSymbols);
ATbool SDF_hasSymbolWsAfterSep(SDF_Symbol arg);
SDF_Layout SDF_getSymbolWsAfterSep(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterSep(SDF_Symbol arg, SDF_Layout wsAfterSep);
ATbool SDF_hasSymbolTail(SDF_Symbol arg);
SDF_SymbolTail SDF_getSymbolTail(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolTail(SDF_Symbol arg, SDF_SymbolTail tail);
ATbool SDF_hasSymbolHead(SDF_Symbol arg);
SDF_Symbol SDF_getSymbolHead(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolHead(SDF_Symbol arg, SDF_Symbol head);
ATbool SDF_hasSymbolWsAfterSymbol(SDF_Symbol arg);
SDF_Layout SDF_getSymbolWsAfterSymbol(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterSymbol(SDF_Symbol arg, SDF_Layout wsAfterSymbol);
ATbool SDF_hasSymbolWsAfterN(SDF_Symbol arg);
SDF_Layout SDF_getSymbolWsAfterN(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterN(SDF_Symbol arg, SDF_Layout wsAfterN);
ATbool SDF_hasSymbolSymbol(SDF_Symbol arg);
SDF_Symbol SDF_getSymbolSymbol(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolSymbol(SDF_Symbol arg, SDF_Symbol symbol);
ATbool SDF_hasSymbolLiteral(SDF_Symbol arg);
SDF_Literal SDF_getSymbolLiteral(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolLiteral(SDF_Symbol arg, SDF_Literal literal);
ATbool SDF_hasSymbolResults(SDF_Symbol arg);
SDF_Symbol SDF_getSymbolResults(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolResults(SDF_Symbol arg, SDF_Symbol results);
ATbool SDF_hasSymbolCharClass(SDF_Symbol arg);
SDF_CharClass SDF_getSymbolCharClass(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolCharClass(SDF_Symbol arg, SDF_CharClass charClass);
ATbool SDF_hasSymbolWsAfterBracketOpen(SDF_Symbol arg);
SDF_Layout SDF_getSymbolWsAfterBracketOpen(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterBracketOpen(SDF_Symbol arg, SDF_Layout wsAfterBracketOpen);
ATbool SDF_hasSymbolWsAfterTail(SDF_Symbol arg);
SDF_Layout SDF_getSymbolWsAfterTail(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterTail(SDF_Symbol arg, SDF_Layout wsAfterTail);
ATbool SDF_hasSymbolWsAfterHead(SDF_Symbol arg);
SDF_Layout SDF_getSymbolWsAfterHead(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterHead(SDF_Symbol arg, SDF_Layout wsAfterHead);
ATbool SDF_hasSymbolWsAfterEqualsGreaterThan(SDF_Symbol arg);
SDF_Layout SDF_getSymbolWsAfterEqualsGreaterThan(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterEqualsGreaterThan(SDF_Symbol arg, SDF_Layout wsAfterEqualsGreaterThan);
ATbool SDF_hasSymbolSep(SDF_Symbol arg);
SDF_Symbol SDF_getSymbolSep(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolSep(SDF_Symbol arg, SDF_Symbol sep);
ATbool SDF_hasSymbolSymbols(SDF_Symbol arg);
SDF_Symbols SDF_getSymbolSymbols(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolSymbols(SDF_Symbol arg, SDF_Symbols symbols);
ATbool SDF_hasSymbolWsAfterSet(SDF_Symbol arg);
SDF_Layout SDF_getSymbolWsAfterSet(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterSet(SDF_Symbol arg, SDF_Layout wsAfterSet);
ATbool SDF_hasSymbolLeft(SDF_Symbol arg);
SDF_Symbol SDF_getSymbolLeft(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolLeft(SDF_Symbol arg, SDF_Symbol left);
ATbool SDF_hasSymbolWsAfterLEX(SDF_Symbol arg);
SDF_Layout SDF_getSymbolWsAfterLEX(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterLEX(SDF_Symbol arg, SDF_Layout wsAfterLEX);
ATbool SDF_hasSymbolLabel(SDF_Symbol arg);
SDF_Literal SDF_getSymbolLabel(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolLabel(SDF_Symbol arg, SDF_Literal label);
ATbool SDF_hasSymbolN(SDF_Symbol arg);
SDF_NatCon SDF_getSymbolN(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolN(SDF_Symbol arg, SDF_NatCon n);
ATbool SDF_hasSymbolWsAfterLessThan(SDF_Symbol arg);
SDF_Layout SDF_getSymbolWsAfterLessThan(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterLessThan(SDF_Symbol arg, SDF_Layout wsAfterLessThan);
ATbool SDF_hasSymbolWsAfterColon(SDF_Symbol arg);
SDF_Layout SDF_getSymbolWsAfterColon(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterColon(SDF_Symbol arg, SDF_Layout wsAfterColon);
ATbool SDF_hasSymbolWsAfterLabel(SDF_Symbol arg);
SDF_Layout SDF_getSymbolWsAfterLabel(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterLabel(SDF_Symbol arg, SDF_Layout wsAfterLabel);
ATbool SDF_hasSymbolWsAfterVAR(SDF_Symbol arg);
SDF_Layout SDF_getSymbolWsAfterVAR(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterVAR(SDF_Symbol arg, SDF_Layout wsAfterVAR);

/*}}}  */
/*{{{  SDF_Grammar accessor prototypes */

ATbool SDF_isValidGrammar(SDF_Grammar arg);
ATbool SDF_isGrammarLexicalPriorities(SDF_Grammar arg);
ATbool SDF_isGrammarContextFreePriorities(SDF_Grammar arg);
ATbool SDF_isGrammarLexicalRestrictions(SDF_Grammar arg);
ATbool SDF_isGrammarContextFreeRestrictions(SDF_Grammar arg);
ATbool SDF_isGrammarSyntax(SDF_Grammar arg);
ATbool SDF_isGrammarLexicalSyntax(SDF_Grammar arg);
ATbool SDF_isGrammarContextFreeSyntax(SDF_Grammar arg);
ATbool SDF_isGrammarVariables(SDF_Grammar arg);
ATbool SDF_isGrammarLexicalVariables(SDF_Grammar arg);
ATbool SDF_isGrammarImpSection(SDF_Grammar arg);
ATbool SDF_isGrammarPriorities(SDF_Grammar arg);
ATbool SDF_isGrammarSorts(SDF_Grammar arg);
ATbool SDF_isGrammarRestrictions(SDF_Grammar arg);
ATbool SDF_isGrammarAliases(SDF_Grammar arg);
ATbool SDF_isGrammarEmptyGrammar(SDF_Grammar arg);
ATbool SDF_isGrammarConcGrammars(SDF_Grammar arg);
ATbool SDF_isGrammarBracket(SDF_Grammar arg);
ATbool SDF_hasGrammarRight(SDF_Grammar arg);
SDF_Grammar SDF_getGrammarRight(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarRight(SDF_Grammar arg, SDF_Grammar right);
ATbool SDF_hasGrammarWsAfterLeft(SDF_Grammar arg);
SDF_Layout SDF_getGrammarWsAfterLeft(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterLeft(SDF_Grammar arg, SDF_Layout wsAfterLeft);
ATbool SDF_hasGrammarWsAfterParenOpen(SDF_Grammar arg);
SDF_Layout SDF_getGrammarWsAfterParenOpen(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterParenOpen(SDF_Grammar arg, SDF_Layout wsAfterParenOpen);
ATbool SDF_hasGrammarWsAfterSorts(SDF_Grammar arg);
SDF_Layout SDF_getGrammarWsAfterSorts(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterSorts(SDF_Grammar arg, SDF_Layout wsAfterSorts);
ATbool SDF_hasGrammarWsAfterPriorities(SDF_Grammar arg);
SDF_Layout SDF_getGrammarWsAfterPriorities(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterPriorities(SDF_Grammar arg, SDF_Layout wsAfterPriorities);
ATbool SDF_hasGrammarWsAfterGrammar(SDF_Grammar arg);
SDF_Layout SDF_getGrammarWsAfterGrammar(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterGrammar(SDF_Grammar arg, SDF_Layout wsAfterGrammar);
ATbool SDF_hasGrammarAliases(SDF_Grammar arg);
SDF_Aliases SDF_getGrammarAliases(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarAliases(SDF_Grammar arg, SDF_Aliases aliases);
ATbool SDF_hasGrammarWsAfterSyntax(SDF_Grammar arg);
SDF_Layout SDF_getGrammarWsAfterSyntax(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterSyntax(SDF_Grammar arg, SDF_Layout wsAfterSyntax);
ATbool SDF_hasGrammarPriorities(SDF_Grammar arg);
SDF_Priorities SDF_getGrammarPriorities(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarPriorities(SDF_Grammar arg, SDF_Priorities priorities);
ATbool SDF_hasGrammarRestrictions(SDF_Grammar arg);
SDF_Restrictions SDF_getGrammarRestrictions(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarRestrictions(SDF_Grammar arg, SDF_Restrictions restrictions);
ATbool SDF_hasGrammarWsAfterRestrictions(SDF_Grammar arg);
SDF_Layout SDF_getGrammarWsAfterRestrictions(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterRestrictions(SDF_Grammar arg, SDF_Layout wsAfterRestrictions);
ATbool SDF_hasGrammarImpSection(SDF_Grammar arg);
SDF_ImpSection SDF_getGrammarImpSection(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarImpSection(SDF_Grammar arg, SDF_ImpSection impSection);
ATbool SDF_hasGrammarWsAfterLexical(SDF_Grammar arg);
SDF_Layout SDF_getGrammarWsAfterLexical(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterLexical(SDF_Grammar arg, SDF_Layout wsAfterLexical);
ATbool SDF_hasGrammarGrammar(SDF_Grammar arg);
SDF_Grammar SDF_getGrammarGrammar(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarGrammar(SDF_Grammar arg, SDF_Grammar grammar);
ATbool SDF_hasGrammarSymbols(SDF_Grammar arg);
SDF_Symbols SDF_getGrammarSymbols(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarSymbols(SDF_Grammar arg, SDF_Symbols symbols);
ATbool SDF_hasGrammarWsAfterVariables(SDF_Grammar arg);
SDF_Layout SDF_getGrammarWsAfterVariables(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterVariables(SDF_Grammar arg, SDF_Layout wsAfterVariables);
ATbool SDF_hasGrammarLeft(SDF_Grammar arg);
SDF_Grammar SDF_getGrammarLeft(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarLeft(SDF_Grammar arg, SDF_Grammar left);
ATbool SDF_hasGrammarWsAfterAliases(SDF_Grammar arg);
SDF_Layout SDF_getGrammarWsAfterAliases(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterAliases(SDF_Grammar arg, SDF_Layout wsAfterAliases);
ATbool SDF_hasGrammarProductions(SDF_Grammar arg);
SDF_Productions SDF_getGrammarProductions(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarProductions(SDF_Grammar arg, SDF_Productions productions);
ATbool SDF_hasGrammarWsAfterContextFree(SDF_Grammar arg);
SDF_Layout SDF_getGrammarWsAfterContextFree(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterContextFree(SDF_Grammar arg, SDF_Layout wsAfterContextFree);

/*}}}  */
/*{{{  SDF_SDF accessor prototypes */

ATbool SDF_isValidSDF(SDF_SDF arg);
ATbool SDF_isSDFDefinition(SDF_SDF arg);
ATbool SDF_hasSDFDefinition(SDF_SDF arg);
SDF_Definition SDF_getSDFDefinition(SDF_SDF arg);
SDF_SDF SDF_setSDFDefinition(SDF_SDF arg, SDF_Definition definition);
ATbool SDF_hasSDFWsAfterDefinition(SDF_SDF arg);
SDF_Layout SDF_getSDFWsAfterDefinition(SDF_SDF arg);
SDF_SDF SDF_setSDFWsAfterDefinition(SDF_SDF arg, SDF_Layout wsAfterDefinition);

/*}}}  */
/*{{{  SDF_Attributes accessor prototypes */

ATbool SDF_isValidAttributes(SDF_Attributes arg);
ATbool SDF_isAttributesAttrs(SDF_Attributes arg);
ATbool SDF_isAttributesNoAttrs(SDF_Attributes arg);
ATbool SDF_hasAttributesWsAfterList(SDF_Attributes arg);
SDF_Layout SDF_getAttributesWsAfterList(SDF_Attributes arg);
SDF_Attributes SDF_setAttributesWsAfterList(SDF_Attributes arg, SDF_Layout wsAfterList);
ATbool SDF_hasAttributesWsAfterBraceOpen(SDF_Attributes arg);
SDF_Layout SDF_getAttributesWsAfterBraceOpen(SDF_Attributes arg);
SDF_Attributes SDF_setAttributesWsAfterBraceOpen(SDF_Attributes arg, SDF_Layout wsAfterBraceOpen);
ATbool SDF_hasAttributesList(SDF_Attributes arg);
SDF_AttributeList SDF_getAttributesList(SDF_Attributes arg);
SDF_Attributes SDF_setAttributesList(SDF_Attributes arg, SDF_AttributeList list);

/*}}}  */
/*{{{  SDF_AttributeList accessor prototypes */

ATbool SDF_isValidAttributeList(SDF_AttributeList arg);
ATbool SDF_isAttributeListEmpty(SDF_AttributeList arg);
ATbool SDF_isAttributeListSingle(SDF_AttributeList arg);
ATbool SDF_isAttributeListMany(SDF_AttributeList arg);
ATbool SDF_hasAttributeListWsAfterFirst(SDF_AttributeList arg);
SDF_Layout SDF_getAttributeListWsAfterFirst(SDF_AttributeList arg);
SDF_AttributeList SDF_setAttributeListWsAfterFirst(SDF_AttributeList arg, SDF_Layout wsAfterFirst);
ATbool SDF_hasAttributeListWsAfterSep(SDF_AttributeList arg);
SDF_Layout SDF_getAttributeListWsAfterSep(SDF_AttributeList arg);
SDF_AttributeList SDF_setAttributeListWsAfterSep(SDF_AttributeList arg, SDF_Layout wsAfterSep);
ATbool SDF_hasAttributeListTail(SDF_AttributeList arg);
SDF_AttributeList SDF_getAttributeListTail(SDF_AttributeList arg);
SDF_AttributeList SDF_setAttributeListTail(SDF_AttributeList arg, SDF_AttributeList tail);
ATbool SDF_hasAttributeListHead(SDF_AttributeList arg);
SDF_Attribute SDF_getAttributeListHead(SDF_AttributeList arg);
SDF_AttributeList SDF_setAttributeListHead(SDF_AttributeList arg, SDF_Attribute head);
ATbool SDF_hasAttributeListSep(SDF_AttributeList arg);
SDF_Separator SDF_getAttributeListSep(SDF_AttributeList arg);
SDF_AttributeList SDF_setAttributeListSep(SDF_AttributeList arg, SDF_Separator sep);

/*}}}  */
/*{{{  SDF_Production accessor prototypes */

ATbool SDF_isValidProduction(SDF_Production arg);
ATbool SDF_isProductionProd(SDF_Production arg);
ATbool SDF_isProductionProdFun(SDF_Production arg);
ATbool SDF_hasProductionWsAfterResult(SDF_Production arg);
SDF_Layout SDF_getProductionWsAfterResult(SDF_Production arg);
SDF_Production SDF_setProductionWsAfterResult(SDF_Production arg, SDF_Layout wsAfterResult);
ATbool SDF_hasProductionWsAfterParenClose(SDF_Production arg);
SDF_Layout SDF_getProductionWsAfterParenClose(SDF_Production arg);
SDF_Production SDF_setProductionWsAfterParenClose(SDF_Production arg, SDF_Layout wsAfterParenClose);
ATbool SDF_hasProductionWsAfterParenOpen(SDF_Production arg);
SDF_Layout SDF_getProductionWsAfterParenOpen(SDF_Production arg);
SDF_Production SDF_setProductionWsAfterParenOpen(SDF_Production arg, SDF_Layout wsAfterParenOpen);
ATbool SDF_hasProductionWsAfterArguments(SDF_Production arg);
SDF_Layout SDF_getProductionWsAfterArguments(SDF_Production arg);
SDF_Production SDF_setProductionWsAfterArguments(SDF_Production arg, SDF_Layout wsAfterArguments);
ATbool SDF_hasProductionResult(SDF_Production arg);
SDF_Symbol SDF_getProductionResult(SDF_Production arg);
SDF_Production SDF_setProductionResult(SDF_Production arg, SDF_Symbol result);
ATbool SDF_hasProductionArguments(SDF_Production arg);
SDF_SymbolArguments SDF_getProductionArguments(SDF_Production arg);
SDF_Production SDF_setProductionArguments(SDF_Production arg, SDF_SymbolArguments arguments);
ATbool SDF_hasProductionWsAfterSymbols(SDF_Production arg);
SDF_Layout SDF_getProductionWsAfterSymbols(SDF_Production arg);
SDF_Production SDF_setProductionWsAfterSymbols(SDF_Production arg, SDF_Layout wsAfterSymbols);
ATbool SDF_hasProductionFunctionSymbol(SDF_Production arg);
SDF_Literal SDF_getProductionFunctionSymbol(SDF_Production arg);
SDF_Production SDF_setProductionFunctionSymbol(SDF_Production arg, SDF_Literal functionSymbol);
ATbool SDF_hasProductionAttributes(SDF_Production arg);
SDF_Attributes SDF_getProductionAttributes(SDF_Production arg);
SDF_Production SDF_setProductionAttributes(SDF_Production arg, SDF_Attributes attributes);
ATbool SDF_hasProductionWsAfterGreaterThan(SDF_Production arg);
SDF_Layout SDF_getProductionWsAfterGreaterThan(SDF_Production arg);
SDF_Production SDF_setProductionWsAfterGreaterThan(SDF_Production arg, SDF_Layout wsAfterGreaterThan);
ATbool SDF_hasProductionSymbols(SDF_Production arg);
SDF_Symbols SDF_getProductionSymbols(SDF_Production arg);
SDF_Production SDF_setProductionSymbols(SDF_Production arg, SDF_Symbols symbols);
ATbool SDF_hasProductionWsAfterFunctionSymbol(SDF_Production arg);
SDF_Layout SDF_getProductionWsAfterFunctionSymbol(SDF_Production arg);
SDF_Production SDF_setProductionWsAfterFunctionSymbol(SDF_Production arg, SDF_Layout wsAfterFunctionSymbol);

/*}}}  */
/*{{{  SDF_Productions accessor prototypes */

ATbool SDF_isValidProductions(SDF_Productions arg);
ATbool SDF_isProductionsDefault(SDF_Productions arg);
ATbool SDF_hasProductionsList(SDF_Productions arg);
SDF_ProductionList SDF_getProductionsList(SDF_Productions arg);
SDF_Productions SDF_setProductionsList(SDF_Productions arg, SDF_ProductionList list);

/*}}}  */
/*{{{  SDF_ProductionList accessor prototypes */

ATbool SDF_isValidProductionList(SDF_ProductionList arg);
ATbool SDF_isProductionListEmpty(SDF_ProductionList arg);
ATbool SDF_isProductionListSingle(SDF_ProductionList arg);
ATbool SDF_isProductionListMany(SDF_ProductionList arg);
ATbool SDF_hasProductionListWsAfterFirst(SDF_ProductionList arg);
SDF_Layout SDF_getProductionListWsAfterFirst(SDF_ProductionList arg);
SDF_ProductionList SDF_setProductionListWsAfterFirst(SDF_ProductionList arg, SDF_Layout wsAfterFirst);
ATbool SDF_hasProductionListTail(SDF_ProductionList arg);
SDF_ProductionList SDF_getProductionListTail(SDF_ProductionList arg);
SDF_ProductionList SDF_setProductionListTail(SDF_ProductionList arg, SDF_ProductionList tail);
ATbool SDF_hasProductionListHead(SDF_ProductionList arg);
SDF_Production SDF_getProductionListHead(SDF_ProductionList arg);
SDF_ProductionList SDF_setProductionListHead(SDF_ProductionList arg, SDF_Production head);

/*}}}  */
/*{{{  SDF_ModuleWord accessor prototypes */

ATbool SDF_isValidModuleWord(SDF_ModuleWord arg);
ATbool SDF_isModuleWordWord(SDF_ModuleWord arg);
ATbool SDF_hasModuleWordLex(SDF_ModuleWord arg);
SDF_Lexical SDF_getModuleWordLex(SDF_ModuleWord arg);
SDF_ModuleWord SDF_setModuleWordLex(SDF_ModuleWord arg, SDF_Lexical lex);

/*}}}  */
/*{{{  SDF_ModuleId accessor prototypes */

ATbool SDF_isValidModuleId(SDF_ModuleId arg);
ATbool SDF_isModuleIdWord(SDF_ModuleId arg);
ATbool SDF_isModuleIdSlashWord(SDF_ModuleId arg);
ATbool SDF_isModuleIdWordSlashWord(SDF_ModuleId arg);
ATbool SDF_hasModuleIdLex(SDF_ModuleId arg);
SDF_Lexical SDF_getModuleIdLex(SDF_ModuleId arg);
SDF_ModuleId SDF_setModuleIdLex(SDF_ModuleId arg, SDF_Lexical lex);

/*}}}  */
/*{{{  SDF_Definition accessor prototypes */

ATbool SDF_isValidDefinition(SDF_Definition arg);
ATbool SDF_isDefinitionDefault(SDF_Definition arg);
ATbool SDF_hasDefinitionList(SDF_Definition arg);
SDF_ModuleList SDF_getDefinitionList(SDF_Definition arg);
SDF_Definition SDF_setDefinitionList(SDF_Definition arg, SDF_ModuleList list);

/*}}}  */
/*{{{  SDF_ModuleList accessor prototypes */

ATbool SDF_isValidModuleList(SDF_ModuleList arg);
ATbool SDF_isModuleListEmpty(SDF_ModuleList arg);
ATbool SDF_isModuleListSingle(SDF_ModuleList arg);
ATbool SDF_isModuleListMany(SDF_ModuleList arg);
ATbool SDF_hasModuleListWsAfterFirst(SDF_ModuleList arg);
SDF_Layout SDF_getModuleListWsAfterFirst(SDF_ModuleList arg);
SDF_ModuleList SDF_setModuleListWsAfterFirst(SDF_ModuleList arg, SDF_Layout wsAfterFirst);
ATbool SDF_hasModuleListTail(SDF_ModuleList arg);
SDF_ModuleList SDF_getModuleListTail(SDF_ModuleList arg);
SDF_ModuleList SDF_setModuleListTail(SDF_ModuleList arg, SDF_ModuleList tail);
ATbool SDF_hasModuleListHead(SDF_ModuleList arg);
SDF_Module SDF_getModuleListHead(SDF_ModuleList arg);
SDF_ModuleList SDF_setModuleListHead(SDF_ModuleList arg, SDF_Module head);

/*}}}  */
/*{{{  SDF_Module accessor prototypes */

ATbool SDF_isValidModule(SDF_Module arg);
ATbool SDF_isModuleModule(SDF_Module arg);
ATbool SDF_hasModuleWsAfterList(SDF_Module arg);
SDF_Layout SDF_getModuleWsAfterList(SDF_Module arg);
SDF_Module SDF_setModuleWsAfterList(SDF_Module arg, SDF_Layout wsAfterList);
ATbool SDF_hasModuleModuleName(SDF_Module arg);
SDF_ModuleName SDF_getModuleModuleName(SDF_Module arg);
SDF_Module SDF_setModuleModuleName(SDF_Module arg, SDF_ModuleName moduleName);
ATbool SDF_hasModuleWsAfterModule(SDF_Module arg);
SDF_Layout SDF_getModuleWsAfterModule(SDF_Module arg);
SDF_Module SDF_setModuleWsAfterModule(SDF_Module arg, SDF_Layout wsAfterModule);
ATbool SDF_hasModuleList(SDF_Module arg);
SDF_ImpSectionList SDF_getModuleList(SDF_Module arg);
SDF_Module SDF_setModuleList(SDF_Module arg, SDF_ImpSectionList list);
ATbool SDF_hasModuleWsAfterModuleName(SDF_Module arg);
SDF_Layout SDF_getModuleWsAfterModuleName(SDF_Module arg);
SDF_Module SDF_setModuleWsAfterModuleName(SDF_Module arg, SDF_Layout wsAfterModuleName);
ATbool SDF_hasModuleSections(SDF_Module arg);
SDF_Sections SDF_getModuleSections(SDF_Module arg);
SDF_Module SDF_setModuleSections(SDF_Module arg, SDF_Sections sections);

/*}}}  */
/*{{{  SDF_ImpSectionList accessor prototypes */

ATbool SDF_isValidImpSectionList(SDF_ImpSectionList arg);
ATbool SDF_isImpSectionListEmpty(SDF_ImpSectionList arg);
ATbool SDF_isImpSectionListSingle(SDF_ImpSectionList arg);
ATbool SDF_isImpSectionListMany(SDF_ImpSectionList arg);
ATbool SDF_hasImpSectionListWsAfterFirst(SDF_ImpSectionList arg);
SDF_Layout SDF_getImpSectionListWsAfterFirst(SDF_ImpSectionList arg);
SDF_ImpSectionList SDF_setImpSectionListWsAfterFirst(SDF_ImpSectionList arg, SDF_Layout wsAfterFirst);
ATbool SDF_hasImpSectionListTail(SDF_ImpSectionList arg);
SDF_ImpSectionList SDF_getImpSectionListTail(SDF_ImpSectionList arg);
SDF_ImpSectionList SDF_setImpSectionListTail(SDF_ImpSectionList arg, SDF_ImpSectionList tail);
ATbool SDF_hasImpSectionListHead(SDF_ImpSectionList arg);
SDF_ImpSection SDF_getImpSectionListHead(SDF_ImpSectionList arg);
SDF_ImpSectionList SDF_setImpSectionListHead(SDF_ImpSectionList arg, SDF_ImpSection head);

/*}}}  */
/*{{{  SDF_Section accessor prototypes */

ATbool SDF_isValidSection(SDF_Section arg);
ATbool SDF_isSectionExports(SDF_Section arg);
ATbool SDF_isSectionHiddens(SDF_Section arg);
ATbool SDF_hasSectionWsAfterExports(SDF_Section arg);
SDF_Layout SDF_getSectionWsAfterExports(SDF_Section arg);
SDF_Section SDF_setSectionWsAfterExports(SDF_Section arg, SDF_Layout wsAfterExports);
ATbool SDF_hasSectionGrammar(SDF_Section arg);
SDF_Grammar SDF_getSectionGrammar(SDF_Section arg);
SDF_Section SDF_setSectionGrammar(SDF_Section arg, SDF_Grammar grammar);
ATbool SDF_hasSectionWsAfterHiddens(SDF_Section arg);
SDF_Layout SDF_getSectionWsAfterHiddens(SDF_Section arg);
SDF_Section SDF_setSectionWsAfterHiddens(SDF_Section arg, SDF_Layout wsAfterHiddens);

/*}}}  */
/*{{{  SDF_Sections accessor prototypes */

ATbool SDF_isValidSections(SDF_Sections arg);
ATbool SDF_isSectionsDefault(SDF_Sections arg);
ATbool SDF_hasSectionsList(SDF_Sections arg);
SDF_SectionList SDF_getSectionsList(SDF_Sections arg);
SDF_Sections SDF_setSectionsList(SDF_Sections arg, SDF_SectionList list);

/*}}}  */
/*{{{  SDF_SectionList accessor prototypes */

ATbool SDF_isValidSectionList(SDF_SectionList arg);
ATbool SDF_isSectionListEmpty(SDF_SectionList arg);
ATbool SDF_isSectionListSingle(SDF_SectionList arg);
ATbool SDF_isSectionListMany(SDF_SectionList arg);
ATbool SDF_hasSectionListWsAfterFirst(SDF_SectionList arg);
SDF_Layout SDF_getSectionListWsAfterFirst(SDF_SectionList arg);
SDF_SectionList SDF_setSectionListWsAfterFirst(SDF_SectionList arg, SDF_Layout wsAfterFirst);
ATbool SDF_hasSectionListTail(SDF_SectionList arg);
SDF_SectionList SDF_getSectionListTail(SDF_SectionList arg);
SDF_SectionList SDF_setSectionListTail(SDF_SectionList arg, SDF_SectionList tail);
ATbool SDF_hasSectionListHead(SDF_SectionList arg);
SDF_Section SDF_getSectionListHead(SDF_SectionList arg);
SDF_SectionList SDF_setSectionListHead(SDF_SectionList arg, SDF_Section head);

/*}}}  */
/*{{{  SDF_ModuleName accessor prototypes */

ATbool SDF_isValidModuleName(SDF_ModuleName arg);
ATbool SDF_isModuleNameUnparameterized(SDF_ModuleName arg);
ATbool SDF_isModuleNameParameterized(SDF_ModuleName arg);
ATbool SDF_hasModuleNameParams(SDF_ModuleName arg);
SDF_Symbols SDF_getModuleNameParams(SDF_ModuleName arg);
SDF_ModuleName SDF_setModuleNameParams(SDF_ModuleName arg, SDF_Symbols params);
ATbool SDF_hasModuleNameWsAfterModuleId(SDF_ModuleName arg);
SDF_Layout SDF_getModuleNameWsAfterModuleId(SDF_ModuleName arg);
SDF_ModuleName SDF_setModuleNameWsAfterModuleId(SDF_ModuleName arg, SDF_Layout wsAfterModuleId);
ATbool SDF_hasModuleNameModuleId(SDF_ModuleName arg);
SDF_ModuleId SDF_getModuleNameModuleId(SDF_ModuleName arg);
SDF_ModuleName SDF_setModuleNameModuleId(SDF_ModuleName arg, SDF_ModuleId moduleId);
ATbool SDF_hasModuleNameWsAfterBracketOpen(SDF_ModuleName arg);
SDF_Layout SDF_getModuleNameWsAfterBracketOpen(SDF_ModuleName arg);
SDF_ModuleName SDF_setModuleNameWsAfterBracketOpen(SDF_ModuleName arg, SDF_Layout wsAfterBracketOpen);
ATbool SDF_hasModuleNameWsAfterParams(SDF_ModuleName arg);
SDF_Layout SDF_getModuleNameWsAfterParams(SDF_ModuleName arg);
SDF_ModuleName SDF_setModuleNameWsAfterParams(SDF_ModuleName arg, SDF_Layout wsAfterParams);

/*}}}  */
/*{{{  SDF_Attribute accessor prototypes */

ATbool SDF_isValidAttribute(SDF_Attribute arg);
ATbool SDF_isAttributeId(SDF_Attribute arg);
ATbool SDF_isAttributeBracket(SDF_Attribute arg);
ATbool SDF_isAttributeAtr(SDF_Attribute arg);
ATbool SDF_isAttributeCons(SDF_Attribute arg);
ATbool SDF_isAttributeConstructor(SDF_Attribute arg);
ATbool SDF_isAttributeMemo(SDF_Attribute arg);
ATbool SDF_isAttributeReject(SDF_Attribute arg);
ATbool SDF_isAttributePrefer(SDF_Attribute arg);
ATbool SDF_isAttributeAvoid(SDF_Attribute arg);
ATbool SDF_hasAttributeModuleName(SDF_Attribute arg);
SDF_ModuleName SDF_getAttributeModuleName(SDF_Attribute arg);
SDF_Attribute SDF_setAttributeModuleName(SDF_Attribute arg, SDF_ModuleName moduleName);
ATbool SDF_hasAttributeWsAfterParenOpen(SDF_Attribute arg);
SDF_Layout SDF_getAttributeWsAfterParenOpen(SDF_Attribute arg);
SDF_Attribute SDF_setAttributeWsAfterParenOpen(SDF_Attribute arg, SDF_Layout wsAfterParenOpen);
ATbool SDF_hasAttributeWsAfterCons(SDF_Attribute arg);
SDF_Layout SDF_getAttributeWsAfterCons(SDF_Attribute arg);
SDF_Attribute SDF_setAttributeWsAfterCons(SDF_Attribute arg, SDF_Layout wsAfterCons);
ATbool SDF_hasAttributeATerm(SDF_Attribute arg);
SDF_ATerm SDF_getAttributeATerm(SDF_Attribute arg);
SDF_Attribute SDF_setAttributeATerm(SDF_Attribute arg, SDF_ATerm aTerm);
ATbool SDF_hasAttributeWsAfterATerm(SDF_Attribute arg);
SDF_Layout SDF_getAttributeWsAfterATerm(SDF_Attribute arg);
SDF_Attribute SDF_setAttributeWsAfterATerm(SDF_Attribute arg, SDF_Layout wsAfterATerm);
ATbool SDF_hasAttributeAssociativity(SDF_Attribute arg);
SDF_Associativity SDF_getAttributeAssociativity(SDF_Attribute arg);
SDF_Attribute SDF_setAttributeAssociativity(SDF_Attribute arg, SDF_Associativity associativity);
ATbool SDF_hasAttributeWsAfterId(SDF_Attribute arg);
SDF_Layout SDF_getAttributeWsAfterId(SDF_Attribute arg);
SDF_Attribute SDF_setAttributeWsAfterId(SDF_Attribute arg, SDF_Layout wsAfterId);
ATbool SDF_hasAttributeWsAfterModuleName(SDF_Attribute arg);
SDF_Layout SDF_getAttributeWsAfterModuleName(SDF_Attribute arg);
SDF_Attribute SDF_setAttributeWsAfterModuleName(SDF_Attribute arg, SDF_Layout wsAfterModuleName);

/*}}}  */
/*{{{  SDF_ImpSection accessor prototypes */

ATbool SDF_isValidImpSection(SDF_ImpSection arg);
ATbool SDF_isImpSectionImports(SDF_ImpSection arg);
ATbool SDF_hasImpSectionWsAfterImports(SDF_ImpSection arg);
SDF_Layout SDF_getImpSectionWsAfterImports(SDF_ImpSection arg);
SDF_ImpSection SDF_setImpSectionWsAfterImports(SDF_ImpSection arg, SDF_Layout wsAfterImports);
ATbool SDF_hasImpSectionList(SDF_ImpSection arg);
SDF_Imports SDF_getImpSectionList(SDF_ImpSection arg);
SDF_ImpSection SDF_setImpSectionList(SDF_ImpSection arg, SDF_Imports list);

/*}}}  */
/*{{{  SDF_Imports accessor prototypes */

ATbool SDF_isValidImports(SDF_Imports arg);
ATbool SDF_isImportsDefault(SDF_Imports arg);
ATbool SDF_hasImportsList(SDF_Imports arg);
SDF_ImportList SDF_getImportsList(SDF_Imports arg);
SDF_Imports SDF_setImportsList(SDF_Imports arg, SDF_ImportList list);

/*}}}  */
/*{{{  SDF_ImportList accessor prototypes */

ATbool SDF_isValidImportList(SDF_ImportList arg);
ATbool SDF_isImportListEmpty(SDF_ImportList arg);
ATbool SDF_isImportListSingle(SDF_ImportList arg);
ATbool SDF_isImportListMany(SDF_ImportList arg);
ATbool SDF_hasImportListWsAfterFirst(SDF_ImportList arg);
SDF_Layout SDF_getImportListWsAfterFirst(SDF_ImportList arg);
SDF_ImportList SDF_setImportListWsAfterFirst(SDF_ImportList arg, SDF_Layout wsAfterFirst);
ATbool SDF_hasImportListTail(SDF_ImportList arg);
SDF_ImportList SDF_getImportListTail(SDF_ImportList arg);
SDF_ImportList SDF_setImportListTail(SDF_ImportList arg, SDF_ImportList tail);
ATbool SDF_hasImportListHead(SDF_ImportList arg);
SDF_Import SDF_getImportListHead(SDF_ImportList arg);
SDF_ImportList SDF_setImportListHead(SDF_ImportList arg, SDF_Import head);

/*}}}  */
/*{{{  SDF_Import accessor prototypes */

ATbool SDF_isValidImport(SDF_Import arg);
ATbool SDF_isImportModule(SDF_Import arg);
ATbool SDF_isImportRenamedModule(SDF_Import arg);
ATbool SDF_isImportBracket(SDF_Import arg);
ATbool SDF_hasImportModuleName(SDF_Import arg);
SDF_ModuleName SDF_getImportModuleName(SDF_Import arg);
SDF_Import SDF_setImportModuleName(SDF_Import arg, SDF_ModuleName moduleName);
ATbool SDF_hasImportWsAfterParenOpen(SDF_Import arg);
SDF_Layout SDF_getImportWsAfterParenOpen(SDF_Import arg);
SDF_Import SDF_setImportWsAfterParenOpen(SDF_Import arg, SDF_Layout wsAfterParenOpen);
ATbool SDF_hasImportRenamings(SDF_Import arg);
SDF_Renamings SDF_getImportRenamings(SDF_Import arg);
SDF_Import SDF_setImportRenamings(SDF_Import arg, SDF_Renamings renamings);
ATbool SDF_hasImportWsAfterImport(SDF_Import arg);
SDF_Layout SDF_getImportWsAfterImport(SDF_Import arg);
SDF_Import SDF_setImportWsAfterImport(SDF_Import arg, SDF_Layout wsAfterImport);
ATbool SDF_hasImportImport(SDF_Import arg);
SDF_Import SDF_getImportImport(SDF_Import arg);
SDF_Import SDF_setImportImport(SDF_Import arg, SDF_Import import);
ATbool SDF_hasImportWsAfterModuleName(SDF_Import arg);
SDF_Layout SDF_getImportWsAfterModuleName(SDF_Import arg);
SDF_Import SDF_setImportWsAfterModuleName(SDF_Import arg, SDF_Layout wsAfterModuleName);

/*}}}  */
/*{{{  SDF_SymbolTail accessor prototypes */

ATbool SDF_isValidSymbolTail(SDF_SymbolTail arg);
ATbool SDF_isSymbolTailSingle(SDF_SymbolTail arg);
ATbool SDF_isSymbolTailMany(SDF_SymbolTail arg);
ATbool SDF_hasSymbolTailWsAfterFirst(SDF_SymbolTail arg);
SDF_Layout SDF_getSymbolTailWsAfterFirst(SDF_SymbolTail arg);
SDF_SymbolTail SDF_setSymbolTailWsAfterFirst(SDF_SymbolTail arg, SDF_Layout wsAfterFirst);
ATbool SDF_hasSymbolTailTail(SDF_SymbolTail arg);
SDF_SymbolTail SDF_getSymbolTailTail(SDF_SymbolTail arg);
SDF_SymbolTail SDF_setSymbolTailTail(SDF_SymbolTail arg, SDF_SymbolTail tail);
ATbool SDF_hasSymbolTailHead(SDF_SymbolTail arg);
SDF_Symbol SDF_getSymbolTailHead(SDF_SymbolTail arg);
SDF_SymbolTail SDF_setSymbolTailHead(SDF_SymbolTail arg, SDF_Symbol head);

/*}}}  */
/*{{{  SDF_Associativity accessor prototypes */

ATbool SDF_isValidAssociativity(SDF_Associativity arg);
ATbool SDF_isAssociativityLeft(SDF_Associativity arg);
ATbool SDF_isAssociativityRight(SDF_Associativity arg);
ATbool SDF_isAssociativityNonAssoc(SDF_Associativity arg);
ATbool SDF_isAssociativityAssoc(SDF_Associativity arg);

/*}}}  */
/*{{{  SDF_Group accessor prototypes */

ATbool SDF_isValidGroup(SDF_Group arg);
ATbool SDF_isGroupSimpleGroup(SDF_Group arg);
ATbool SDF_isGroupProdsGroup(SDF_Group arg);
ATbool SDF_isGroupAssocGroup(SDF_Group arg);
ATbool SDF_hasGroupWsAfterAssociativity(SDF_Group arg);
SDF_Layout SDF_getGroupWsAfterAssociativity(SDF_Group arg);
SDF_Group SDF_setGroupWsAfterAssociativity(SDF_Group arg, SDF_Layout wsAfterAssociativity);
ATbool SDF_hasGroupWsAfterBraceOpen(SDF_Group arg);
SDF_Layout SDF_getGroupWsAfterBraceOpen(SDF_Group arg);
SDF_Group SDF_setGroupWsAfterBraceOpen(SDF_Group arg, SDF_Layout wsAfterBraceOpen);
ATbool SDF_hasGroupProduction(SDF_Group arg);
SDF_Production SDF_getGroupProduction(SDF_Group arg);
SDF_Group SDF_setGroupProduction(SDF_Group arg, SDF_Production production);
ATbool SDF_hasGroupAssociativity(SDF_Group arg);
SDF_Associativity SDF_getGroupAssociativity(SDF_Group arg);
SDF_Group SDF_setGroupAssociativity(SDF_Group arg, SDF_Associativity associativity);
ATbool SDF_hasGroupProductions(SDF_Group arg);
SDF_Productions SDF_getGroupProductions(SDF_Group arg);
SDF_Group SDF_setGroupProductions(SDF_Group arg, SDF_Productions productions);
ATbool SDF_hasGroupWsAfterProductions(SDF_Group arg);
SDF_Layout SDF_getGroupWsAfterProductions(SDF_Group arg);
SDF_Group SDF_setGroupWsAfterProductions(SDF_Group arg, SDF_Layout wsAfterProductions);
ATbool SDF_hasGroupWsAfterColon(SDF_Group arg);
SDF_Layout SDF_getGroupWsAfterColon(SDF_Group arg);
SDF_Group SDF_setGroupWsAfterColon(SDF_Group arg, SDF_Layout wsAfterColon);

/*}}}  */
/*{{{  SDF_Priority accessor prototypes */

ATbool SDF_isValidPriority(SDF_Priority arg);
ATbool SDF_isPriorityPriorityChain(SDF_Priority arg);
ATbool SDF_isPriorityPriorityAssoc(SDF_Priority arg);
ATbool SDF_hasPriorityRight(SDF_Priority arg);
SDF_Group SDF_getPriorityRight(SDF_Priority arg);
SDF_Priority SDF_setPriorityRight(SDF_Priority arg, SDF_Group right);
ATbool SDF_hasPriorityWsAfterAssociativity(SDF_Priority arg);
SDF_Layout SDF_getPriorityWsAfterAssociativity(SDF_Priority arg);
SDF_Priority SDF_setPriorityWsAfterAssociativity(SDF_Priority arg, SDF_Layout wsAfterAssociativity);
ATbool SDF_hasPriorityWsAfterLeft(SDF_Priority arg);
SDF_Layout SDF_getPriorityWsAfterLeft(SDF_Priority arg);
SDF_Priority SDF_setPriorityWsAfterLeft(SDF_Priority arg, SDF_Layout wsAfterLeft);
ATbool SDF_hasPriorityGroupp(SDF_Priority arg);
SDF_GroupGroupp SDF_getPriorityGroupp(SDF_Priority arg);
SDF_Priority SDF_setPriorityGroupp(SDF_Priority arg, SDF_GroupGroupp groupp);
ATbool SDF_hasPriorityAssociativity(SDF_Priority arg);
SDF_Associativity SDF_getPriorityAssociativity(SDF_Priority arg);
SDF_Priority SDF_setPriorityAssociativity(SDF_Priority arg, SDF_Associativity associativity);
ATbool SDF_hasPriorityLeft(SDF_Priority arg);
SDF_Group SDF_getPriorityLeft(SDF_Priority arg);
SDF_Priority SDF_setPriorityLeft(SDF_Priority arg, SDF_Group left);

/*}}}  */
/*{{{  SDF_GroupGroupp accessor prototypes */

ATbool SDF_isValidGroupGroupp(SDF_GroupGroupp arg);
ATbool SDF_isGroupGrouppSingle(SDF_GroupGroupp arg);
ATbool SDF_isGroupGrouppMany(SDF_GroupGroupp arg);
ATbool SDF_hasGroupGrouppWsAfterFirst(SDF_GroupGroupp arg);
SDF_Layout SDF_getGroupGrouppWsAfterFirst(SDF_GroupGroupp arg);
SDF_GroupGroupp SDF_setGroupGrouppWsAfterFirst(SDF_GroupGroupp arg, SDF_Layout wsAfterFirst);
ATbool SDF_hasGroupGrouppWsAfterSep(SDF_GroupGroupp arg);
SDF_Layout SDF_getGroupGrouppWsAfterSep(SDF_GroupGroupp arg);
SDF_GroupGroupp SDF_setGroupGrouppWsAfterSep(SDF_GroupGroupp arg, SDF_Layout wsAfterSep);
ATbool SDF_hasGroupGrouppTail(SDF_GroupGroupp arg);
SDF_GroupGroupp SDF_getGroupGrouppTail(SDF_GroupGroupp arg);
SDF_GroupGroupp SDF_setGroupGrouppTail(SDF_GroupGroupp arg, SDF_GroupGroupp tail);
ATbool SDF_hasGroupGrouppHead(SDF_GroupGroupp arg);
SDF_Group SDF_getGroupGrouppHead(SDF_GroupGroupp arg);
SDF_GroupGroupp SDF_setGroupGrouppHead(SDF_GroupGroupp arg, SDF_Group head);
ATbool SDF_hasGroupGrouppSep(SDF_GroupGroupp arg);
SDF_Separator SDF_getGroupGrouppSep(SDF_GroupGroupp arg);
SDF_GroupGroupp SDF_setGroupGrouppSep(SDF_GroupGroupp arg, SDF_Separator sep);

/*}}}  */
/*{{{  SDF_Priorities accessor prototypes */

ATbool SDF_isValidPriorities(SDF_Priorities arg);
ATbool SDF_isPrioritiesDefault(SDF_Priorities arg);
ATbool SDF_hasPrioritiesList(SDF_Priorities arg);
SDF_PriorityList SDF_getPrioritiesList(SDF_Priorities arg);
SDF_Priorities SDF_setPrioritiesList(SDF_Priorities arg, SDF_PriorityList list);

/*}}}  */
/*{{{  SDF_PriorityList accessor prototypes */

ATbool SDF_isValidPriorityList(SDF_PriorityList arg);
ATbool SDF_isPriorityListEmpty(SDF_PriorityList arg);
ATbool SDF_isPriorityListSingle(SDF_PriorityList arg);
ATbool SDF_isPriorityListMany(SDF_PriorityList arg);
ATbool SDF_hasPriorityListWsAfterFirst(SDF_PriorityList arg);
SDF_Layout SDF_getPriorityListWsAfterFirst(SDF_PriorityList arg);
SDF_PriorityList SDF_setPriorityListWsAfterFirst(SDF_PriorityList arg, SDF_Layout wsAfterFirst);
ATbool SDF_hasPriorityListWsAfterSep(SDF_PriorityList arg);
SDF_Layout SDF_getPriorityListWsAfterSep(SDF_PriorityList arg);
SDF_PriorityList SDF_setPriorityListWsAfterSep(SDF_PriorityList arg, SDF_Layout wsAfterSep);
ATbool SDF_hasPriorityListTail(SDF_PriorityList arg);
SDF_PriorityList SDF_getPriorityListTail(SDF_PriorityList arg);
SDF_PriorityList SDF_setPriorityListTail(SDF_PriorityList arg, SDF_PriorityList tail);
ATbool SDF_hasPriorityListHead(SDF_PriorityList arg);
SDF_Priority SDF_getPriorityListHead(SDF_PriorityList arg);
SDF_PriorityList SDF_setPriorityListHead(SDF_PriorityList arg, SDF_Priority head);
ATbool SDF_hasPriorityListSep(SDF_PriorityList arg);
SDF_Separator SDF_getPriorityListSep(SDF_PriorityList arg);
SDF_PriorityList SDF_setPriorityListSep(SDF_PriorityList arg, SDF_Separator sep);

/*}}}  */
/*{{{  SDF_Sort accessor prototypes */

ATbool SDF_isValidSort(SDF_Sort arg);
ATbool SDF_isSortOneChar(SDF_Sort arg);
ATbool SDF_isSortMoreChars(SDF_Sort arg);
ATbool SDF_hasSortLex(SDF_Sort arg);
SDF_Lexical SDF_getSortLex(SDF_Sort arg);
SDF_Sort SDF_setSortLex(SDF_Sort arg, SDF_Lexical lex);

/*}}}  */
/*{{{  SDF_UQLiteral accessor prototypes */

ATbool SDF_isValidUQLiteral(SDF_UQLiteral arg);
ATbool SDF_isUQLiteralOneChar(SDF_UQLiteral arg);
ATbool SDF_isUQLiteralMoreChars(SDF_UQLiteral arg);
ATbool SDF_hasUQLiteralLex(SDF_UQLiteral arg);
SDF_Lexical SDF_getUQLiteralLex(SDF_UQLiteral arg);
SDF_UQLiteral SDF_setUQLiteralLex(SDF_UQLiteral arg, SDF_Lexical lex);

/*}}}  */
/*{{{  SDF_Literal accessor prototypes */

ATbool SDF_isValidLiteral(SDF_Literal arg);
ATbool SDF_isLiteralUqlit(SDF_Literal arg);
ATbool SDF_isLiteralQuoted(SDF_Literal arg);
ATbool SDF_hasLiteralLex(SDF_Literal arg);
SDF_Lexical SDF_getLiteralLex(SDF_Literal arg);
SDF_Literal SDF_setLiteralLex(SDF_Literal arg, SDF_Lexical lex);
ATbool SDF_hasLiteralUQLiteral(SDF_Literal arg);
SDF_UQLiteral SDF_getLiteralUQLiteral(SDF_Literal arg);
SDF_Literal SDF_setLiteralUQLiteral(SDF_Literal arg, SDF_UQLiteral uQLiteral);

/*}}}  */
/*{{{  SDF_SymbolArguments accessor prototypes */

ATbool SDF_isValidSymbolArguments(SDF_SymbolArguments arg);
ATbool SDF_isSymbolArgumentsEmpty(SDF_SymbolArguments arg);
ATbool SDF_isSymbolArgumentsSingle(SDF_SymbolArguments arg);
ATbool SDF_isSymbolArgumentsMany(SDF_SymbolArguments arg);
ATbool SDF_hasSymbolArgumentsWsAfterFirst(SDF_SymbolArguments arg);
SDF_Layout SDF_getSymbolArgumentsWsAfterFirst(SDF_SymbolArguments arg);
SDF_SymbolArguments SDF_setSymbolArgumentsWsAfterFirst(SDF_SymbolArguments arg, SDF_Layout wsAfterFirst);
ATbool SDF_hasSymbolArgumentsWsAfterSep(SDF_SymbolArguments arg);
SDF_Layout SDF_getSymbolArgumentsWsAfterSep(SDF_SymbolArguments arg);
SDF_SymbolArguments SDF_setSymbolArgumentsWsAfterSep(SDF_SymbolArguments arg, SDF_Layout wsAfterSep);
ATbool SDF_hasSymbolArgumentsTail(SDF_SymbolArguments arg);
SDF_SymbolArguments SDF_getSymbolArgumentsTail(SDF_SymbolArguments arg);
SDF_SymbolArguments SDF_setSymbolArgumentsTail(SDF_SymbolArguments arg, SDF_SymbolArguments tail);
ATbool SDF_hasSymbolArgumentsHead(SDF_SymbolArguments arg);
SDF_Symbol SDF_getSymbolArgumentsHead(SDF_SymbolArguments arg);
SDF_SymbolArguments SDF_setSymbolArgumentsHead(SDF_SymbolArguments arg, SDF_Symbol head);
ATbool SDF_hasSymbolArgumentsSep(SDF_SymbolArguments arg);
SDF_Separator SDF_getSymbolArgumentsSep(SDF_SymbolArguments arg);
SDF_SymbolArguments SDF_setSymbolArgumentsSep(SDF_SymbolArguments arg, SDF_Separator sep);

/*}}}  */
/*{{{  SDF_Lookahead accessor prototypes */

ATbool SDF_isValidLookahead(SDF_Lookahead arg);
ATbool SDF_isLookaheadCharClass(SDF_Lookahead arg);
ATbool SDF_isLookaheadSeq(SDF_Lookahead arg);
ATbool SDF_hasLookaheadWsAfterPeriod(SDF_Lookahead arg);
SDF_Layout SDF_getLookaheadWsAfterPeriod(SDF_Lookahead arg);
SDF_Lookahead SDF_setLookaheadWsAfterPeriod(SDF_Lookahead arg, SDF_Layout wsAfterPeriod);
ATbool SDF_hasLookaheadTail(SDF_Lookahead arg);
SDF_Lookaheads SDF_getLookaheadTail(SDF_Lookahead arg);
SDF_Lookahead SDF_setLookaheadTail(SDF_Lookahead arg, SDF_Lookaheads tail);
ATbool SDF_hasLookaheadHead(SDF_Lookahead arg);
SDF_CharClass SDF_getLookaheadHead(SDF_Lookahead arg);
SDF_Lookahead SDF_setLookaheadHead(SDF_Lookahead arg, SDF_CharClass head);
ATbool SDF_hasLookaheadCharClass(SDF_Lookahead arg);
SDF_CharClass SDF_getLookaheadCharClass(SDF_Lookahead arg);
SDF_Lookahead SDF_setLookaheadCharClass(SDF_Lookahead arg, SDF_CharClass charClass);
ATbool SDF_hasLookaheadWsAfterHead(SDF_Lookahead arg);
SDF_Layout SDF_getLookaheadWsAfterHead(SDF_Lookahead arg);
SDF_Lookahead SDF_setLookaheadWsAfterHead(SDF_Lookahead arg, SDF_Layout wsAfterHead);

/*}}}  */
/*{{{  SDF_Lookaheads accessor prototypes */

ATbool SDF_isValidLookaheads(SDF_Lookaheads arg);
ATbool SDF_isLookaheadsSingle(SDF_Lookaheads arg);
ATbool SDF_isLookaheadsAlt(SDF_Lookaheads arg);
ATbool SDF_isLookaheadsBracket(SDF_Lookaheads arg);
ATbool SDF_isLookaheadsList(SDF_Lookaheads arg);
ATbool SDF_hasLookaheadsRight(SDF_Lookaheads arg);
SDF_Lookaheads SDF_getLookaheadsRight(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsRight(SDF_Lookaheads arg, SDF_Lookaheads right);
ATbool SDF_hasLookaheadsWsAfterList(SDF_Lookaheads arg);
SDF_Layout SDF_getLookaheadsWsAfterList(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsWsAfterList(SDF_Lookaheads arg, SDF_Layout wsAfterList);
ATbool SDF_hasLookaheadsLookaheads(SDF_Lookaheads arg);
SDF_Lookaheads SDF_getLookaheadsLookaheads(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsLookaheads(SDF_Lookaheads arg, SDF_Lookaheads lookaheads);
ATbool SDF_hasLookaheadsWsAfterLeft(SDF_Lookaheads arg);
SDF_Layout SDF_getLookaheadsWsAfterLeft(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsWsAfterLeft(SDF_Lookaheads arg, SDF_Layout wsAfterLeft);
ATbool SDF_hasLookaheadsWsAfterParenOpen(SDF_Lookaheads arg);
SDF_Layout SDF_getLookaheadsWsAfterParenOpen(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsWsAfterParenOpen(SDF_Lookaheads arg, SDF_Layout wsAfterParenOpen);
ATbool SDF_hasLookaheadsWsAfterBracketOpenBracketOpen(SDF_Lookaheads arg);
SDF_Layout SDF_getLookaheadsWsAfterBracketOpenBracketOpen(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsWsAfterBracketOpenBracketOpen(SDF_Lookaheads arg, SDF_Layout wsAfterBracketOpenBracketOpen);
ATbool SDF_hasLookaheadsLookahead(SDF_Lookaheads arg);
SDF_Lookahead SDF_getLookaheadsLookahead(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsLookahead(SDF_Lookaheads arg, SDF_Lookahead lookahead);
ATbool SDF_hasLookaheadsWsAfterBar(SDF_Lookaheads arg);
SDF_Layout SDF_getLookaheadsWsAfterBar(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsWsAfterBar(SDF_Lookaheads arg, SDF_Layout wsAfterBar);
ATbool SDF_hasLookaheadsList(SDF_Lookaheads arg);
SDF_LookaheadList SDF_getLookaheadsList(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsList(SDF_Lookaheads arg, SDF_LookaheadList list);
ATbool SDF_hasLookaheadsLeft(SDF_Lookaheads arg);
SDF_Lookaheads SDF_getLookaheadsLeft(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsLeft(SDF_Lookaheads arg, SDF_Lookaheads left);
ATbool SDF_hasLookaheadsWsAfterLookaheads(SDF_Lookaheads arg);
SDF_Layout SDF_getLookaheadsWsAfterLookaheads(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsWsAfterLookaheads(SDF_Lookaheads arg, SDF_Layout wsAfterLookaheads);

/*}}}  */
/*{{{  SDF_LookaheadList accessor prototypes */

ATbool SDF_isValidLookaheadList(SDF_LookaheadList arg);
ATbool SDF_isLookaheadListEmpty(SDF_LookaheadList arg);
ATbool SDF_isLookaheadListSingle(SDF_LookaheadList arg);
ATbool SDF_isLookaheadListMany(SDF_LookaheadList arg);
ATbool SDF_hasLookaheadListWsAfterFirst(SDF_LookaheadList arg);
SDF_Layout SDF_getLookaheadListWsAfterFirst(SDF_LookaheadList arg);
SDF_LookaheadList SDF_setLookaheadListWsAfterFirst(SDF_LookaheadList arg, SDF_Layout wsAfterFirst);
ATbool SDF_hasLookaheadListWsAfterSep(SDF_LookaheadList arg);
SDF_Layout SDF_getLookaheadListWsAfterSep(SDF_LookaheadList arg);
SDF_LookaheadList SDF_setLookaheadListWsAfterSep(SDF_LookaheadList arg, SDF_Layout wsAfterSep);
ATbool SDF_hasLookaheadListTail(SDF_LookaheadList arg);
SDF_LookaheadList SDF_getLookaheadListTail(SDF_LookaheadList arg);
SDF_LookaheadList SDF_setLookaheadListTail(SDF_LookaheadList arg, SDF_LookaheadList tail);
ATbool SDF_hasLookaheadListHead(SDF_LookaheadList arg);
SDF_Lookahead SDF_getLookaheadListHead(SDF_LookaheadList arg);
SDF_LookaheadList SDF_setLookaheadListHead(SDF_LookaheadList arg, SDF_Lookahead head);
ATbool SDF_hasLookaheadListSep(SDF_LookaheadList arg);
SDF_Separator SDF_getLookaheadListSep(SDF_LookaheadList arg);
SDF_LookaheadList SDF_setLookaheadListSep(SDF_LookaheadList arg, SDF_Separator sep);

/*}}}  */
/*{{{  SDF_Restriction accessor prototypes */

ATbool SDF_isValidRestriction(SDF_Restriction arg);
ATbool SDF_isRestrictionFollow(SDF_Restriction arg);
ATbool SDF_hasRestrictionLookaheads(SDF_Restriction arg);
SDF_Lookaheads SDF_getRestrictionLookaheads(SDF_Restriction arg);
SDF_Restriction SDF_setRestrictionLookaheads(SDF_Restriction arg, SDF_Lookaheads lookaheads);
ATbool SDF_hasRestrictionWsAfterSymbols(SDF_Restriction arg);
SDF_Layout SDF_getRestrictionWsAfterSymbols(SDF_Restriction arg);
SDF_Restriction SDF_setRestrictionWsAfterSymbols(SDF_Restriction arg, SDF_Layout wsAfterSymbols);
ATbool SDF_hasRestrictionWsAfterSlash(SDF_Restriction arg);
SDF_Layout SDF_getRestrictionWsAfterSlash(SDF_Restriction arg);
SDF_Restriction SDF_setRestrictionWsAfterSlash(SDF_Restriction arg, SDF_Layout wsAfterSlash);
ATbool SDF_hasRestrictionSymbols(SDF_Restriction arg);
SDF_Symbols SDF_getRestrictionSymbols(SDF_Restriction arg);
SDF_Restriction SDF_setRestrictionSymbols(SDF_Restriction arg, SDF_Symbols symbols);

/*}}}  */
/*{{{  SDF_Restrictions accessor prototypes */

ATbool SDF_isValidRestrictions(SDF_Restrictions arg);
ATbool SDF_isRestrictionsDefault(SDF_Restrictions arg);
ATbool SDF_hasRestrictionsList(SDF_Restrictions arg);
SDF_RestrictionList SDF_getRestrictionsList(SDF_Restrictions arg);
SDF_Restrictions SDF_setRestrictionsList(SDF_Restrictions arg, SDF_RestrictionList list);

/*}}}  */
/*{{{  SDF_RestrictionList accessor prototypes */

ATbool SDF_isValidRestrictionList(SDF_RestrictionList arg);
ATbool SDF_isRestrictionListEmpty(SDF_RestrictionList arg);
ATbool SDF_isRestrictionListSingle(SDF_RestrictionList arg);
ATbool SDF_isRestrictionListMany(SDF_RestrictionList arg);
ATbool SDF_hasRestrictionListWsAfterFirst(SDF_RestrictionList arg);
SDF_Layout SDF_getRestrictionListWsAfterFirst(SDF_RestrictionList arg);
SDF_RestrictionList SDF_setRestrictionListWsAfterFirst(SDF_RestrictionList arg, SDF_Layout wsAfterFirst);
ATbool SDF_hasRestrictionListTail(SDF_RestrictionList arg);
SDF_RestrictionList SDF_getRestrictionListTail(SDF_RestrictionList arg);
SDF_RestrictionList SDF_setRestrictionListTail(SDF_RestrictionList arg, SDF_RestrictionList tail);
ATbool SDF_hasRestrictionListHead(SDF_RestrictionList arg);
SDF_Restriction SDF_getRestrictionListHead(SDF_RestrictionList arg);
SDF_RestrictionList SDF_setRestrictionListHead(SDF_RestrictionList arg, SDF_Restriction head);

/*}}}  */
/*{{{  SDF_Alias accessor prototypes */

ATbool SDF_isValidAlias(SDF_Alias arg);
ATbool SDF_isAliasAlias(SDF_Alias arg);
ATbool SDF_hasAliasWsAfterSymbol(SDF_Alias arg);
SDF_Layout SDF_getAliasWsAfterSymbol(SDF_Alias arg);
SDF_Alias SDF_setAliasWsAfterSymbol(SDF_Alias arg, SDF_Layout wsAfterSymbol);
ATbool SDF_hasAliasAlias(SDF_Alias arg);
SDF_Symbol SDF_getAliasAlias(SDF_Alias arg);
SDF_Alias SDF_setAliasAlias(SDF_Alias arg, SDF_Symbol alias);
ATbool SDF_hasAliasSymbol(SDF_Alias arg);
SDF_Symbol SDF_getAliasSymbol(SDF_Alias arg);
SDF_Alias SDF_setAliasSymbol(SDF_Alias arg, SDF_Symbol symbol);
ATbool SDF_hasAliasWsAfterArrow(SDF_Alias arg);
SDF_Layout SDF_getAliasWsAfterArrow(SDF_Alias arg);
SDF_Alias SDF_setAliasWsAfterArrow(SDF_Alias arg, SDF_Layout wsAfterArrow);

/*}}}  */
/*{{{  SDF_Aliases accessor prototypes */

ATbool SDF_isValidAliases(SDF_Aliases arg);
ATbool SDF_isAliasesDefault(SDF_Aliases arg);
ATbool SDF_hasAliasesList(SDF_Aliases arg);
SDF_AliasList SDF_getAliasesList(SDF_Aliases arg);
SDF_Aliases SDF_setAliasesList(SDF_Aliases arg, SDF_AliasList list);

/*}}}  */
/*{{{  SDF_AliasList accessor prototypes */

ATbool SDF_isValidAliasList(SDF_AliasList arg);
ATbool SDF_isAliasListEmpty(SDF_AliasList arg);
ATbool SDF_isAliasListSingle(SDF_AliasList arg);
ATbool SDF_isAliasListMany(SDF_AliasList arg);
ATbool SDF_hasAliasListWsAfterFirst(SDF_AliasList arg);
SDF_Layout SDF_getAliasListWsAfterFirst(SDF_AliasList arg);
SDF_AliasList SDF_setAliasListWsAfterFirst(SDF_AliasList arg, SDF_Layout wsAfterFirst);
ATbool SDF_hasAliasListTail(SDF_AliasList arg);
SDF_AliasList SDF_getAliasListTail(SDF_AliasList arg);
SDF_AliasList SDF_setAliasListTail(SDF_AliasList arg, SDF_AliasList tail);
ATbool SDF_hasAliasListHead(SDF_AliasList arg);
SDF_Alias SDF_getAliasListHead(SDF_AliasList arg);
SDF_AliasList SDF_setAliasListHead(SDF_AliasList arg, SDF_Alias head);

/*}}}  */
/*{{{  SDF_Symbols accessor prototypes */

ATbool SDF_isValidSymbols(SDF_Symbols arg);
ATbool SDF_isSymbolsDefault(SDF_Symbols arg);
ATbool SDF_hasSymbolsList(SDF_Symbols arg);
SDF_SymbolList SDF_getSymbolsList(SDF_Symbols arg);
SDF_Symbols SDF_setSymbolsList(SDF_Symbols arg, SDF_SymbolList list);

/*}}}  */
/*{{{  SDF_SymbolList accessor prototypes */

ATbool SDF_isValidSymbolList(SDF_SymbolList arg);
ATbool SDF_isSymbolListEmpty(SDF_SymbolList arg);
ATbool SDF_isSymbolListSingle(SDF_SymbolList arg);
ATbool SDF_isSymbolListMany(SDF_SymbolList arg);
ATbool SDF_hasSymbolListWsAfterFirst(SDF_SymbolList arg);
SDF_Layout SDF_getSymbolListWsAfterFirst(SDF_SymbolList arg);
SDF_SymbolList SDF_setSymbolListWsAfterFirst(SDF_SymbolList arg, SDF_Layout wsAfterFirst);
ATbool SDF_hasSymbolListTail(SDF_SymbolList arg);
SDF_SymbolList SDF_getSymbolListTail(SDF_SymbolList arg);
SDF_SymbolList SDF_setSymbolListTail(SDF_SymbolList arg, SDF_SymbolList tail);
ATbool SDF_hasSymbolListHead(SDF_SymbolList arg);
SDF_Symbol SDF_getSymbolListHead(SDF_SymbolList arg);
SDF_SymbolList SDF_setSymbolListHead(SDF_SymbolList arg, SDF_Symbol head);

/*}}}  */
/*{{{  SDF_Renamings accessor prototypes */

ATbool SDF_isValidRenamings(SDF_Renamings arg);
ATbool SDF_isRenamingsRenamings(SDF_Renamings arg);
ATbool SDF_hasRenamingsWsAfterList(SDF_Renamings arg);
SDF_Layout SDF_getRenamingsWsAfterList(SDF_Renamings arg);
SDF_Renamings SDF_setRenamingsWsAfterList(SDF_Renamings arg, SDF_Layout wsAfterList);
ATbool SDF_hasRenamingsWsAfterBracketOpen(SDF_Renamings arg);
SDF_Layout SDF_getRenamingsWsAfterBracketOpen(SDF_Renamings arg);
SDF_Renamings SDF_setRenamingsWsAfterBracketOpen(SDF_Renamings arg, SDF_Layout wsAfterBracketOpen);
ATbool SDF_hasRenamingsList(SDF_Renamings arg);
SDF_RenamingList SDF_getRenamingsList(SDF_Renamings arg);
SDF_Renamings SDF_setRenamingsList(SDF_Renamings arg, SDF_RenamingList list);

/*}}}  */
/*{{{  SDF_RenamingList accessor prototypes */

ATbool SDF_isValidRenamingList(SDF_RenamingList arg);
ATbool SDF_isRenamingListEmpty(SDF_RenamingList arg);
ATbool SDF_isRenamingListSingle(SDF_RenamingList arg);
ATbool SDF_isRenamingListMany(SDF_RenamingList arg);
ATbool SDF_hasRenamingListWsAfterFirst(SDF_RenamingList arg);
SDF_Layout SDF_getRenamingListWsAfterFirst(SDF_RenamingList arg);
SDF_RenamingList SDF_setRenamingListWsAfterFirst(SDF_RenamingList arg, SDF_Layout wsAfterFirst);
ATbool SDF_hasRenamingListTail(SDF_RenamingList arg);
SDF_RenamingList SDF_getRenamingListTail(SDF_RenamingList arg);
SDF_RenamingList SDF_setRenamingListTail(SDF_RenamingList arg, SDF_RenamingList tail);
ATbool SDF_hasRenamingListHead(SDF_RenamingList arg);
SDF_Renaming SDF_getRenamingListHead(SDF_RenamingList arg);
SDF_RenamingList SDF_setRenamingListHead(SDF_RenamingList arg, SDF_Renaming head);

/*}}}  */
/*{{{  SDF_Renaming accessor prototypes */

ATbool SDF_isValidRenaming(SDF_Renaming arg);
ATbool SDF_isRenamingSymbol(SDF_Renaming arg);
ATbool SDF_isRenamingProduction(SDF_Renaming arg);
ATbool SDF_hasRenamingFrom(SDF_Renaming arg);
SDF_Symbol SDF_getRenamingFrom(SDF_Renaming arg);
SDF_Renaming SDF_setRenamingFrom(SDF_Renaming arg, SDF_Symbol from);
ATbool SDF_hasRenamingTo(SDF_Renaming arg);
SDF_Symbol SDF_getRenamingTo(SDF_Renaming arg);
SDF_Renaming SDF_setRenamingTo(SDF_Renaming arg, SDF_Symbol to);
ATbool SDF_hasRenamingWsAfterFrom(SDF_Renaming arg);
SDF_Layout SDF_getRenamingWsAfterFrom(SDF_Renaming arg);
SDF_Renaming SDF_setRenamingWsAfterFrom(SDF_Renaming arg, SDF_Layout wsAfterFrom);
ATbool SDF_hasRenamingWsAfterEqualsGreaterThan(SDF_Renaming arg);
SDF_Layout SDF_getRenamingWsAfterEqualsGreaterThan(SDF_Renaming arg);
SDF_Renaming SDF_setRenamingWsAfterEqualsGreaterThan(SDF_Renaming arg, SDF_Layout wsAfterEqualsGreaterThan);

/*}}}  */
/*{{{  SDF_NatCon accessor prototypes */

ATbool SDF_isValidNatCon(SDF_NatCon arg);
ATbool SDF_isNatConDigits(SDF_NatCon arg);
ATbool SDF_hasNatConLex(SDF_NatCon arg);
SDF_Lexical SDF_getNatConLex(SDF_NatCon arg);
SDF_NatCon SDF_setNatConLex(SDF_NatCon arg, SDF_Lexical lex);

/*}}}  */
/*{{{  SDF_IntCon accessor prototypes */

ATbool SDF_isValidIntCon(SDF_IntCon arg);
ATbool SDF_isIntConNatural(SDF_IntCon arg);
ATbool SDF_isIntConPositive(SDF_IntCon arg);
ATbool SDF_isIntConNegative(SDF_IntCon arg);
ATbool SDF_hasIntConWsAfterNeg(SDF_IntCon arg);
SDF_Layout SDF_getIntConWsAfterNeg(SDF_IntCon arg);
SDF_IntCon SDF_setIntConWsAfterNeg(SDF_IntCon arg, SDF_Layout wsAfterNeg);
ATbool SDF_hasIntConWsAfterPos(SDF_IntCon arg);
SDF_Layout SDF_getIntConWsAfterPos(SDF_IntCon arg);
SDF_IntCon SDF_setIntConWsAfterPos(SDF_IntCon arg, SDF_Layout wsAfterPos);
ATbool SDF_hasIntConNatCon(SDF_IntCon arg);
SDF_NatCon SDF_getIntConNatCon(SDF_IntCon arg);
SDF_IntCon SDF_setIntConNatCon(SDF_IntCon arg, SDF_NatCon natCon);

/*}}}  */
/*{{{  SDF_CharRange accessor prototypes */

ATbool SDF_isValidCharRange(SDF_CharRange arg);
ATbool SDF_isCharRangeDefault(SDF_CharRange arg);
ATbool SDF_isCharRangeRange(SDF_CharRange arg);
ATbool SDF_hasCharRangeWsAfter(SDF_CharRange arg);
SDF_Layout SDF_getCharRangeWsAfter(SDF_CharRange arg);
SDF_CharRange SDF_setCharRangeWsAfter(SDF_CharRange arg, SDF_Layout wsAfter);
ATbool SDF_hasCharRangeEnd(SDF_CharRange arg);
SDF_Character SDF_getCharRangeEnd(SDF_CharRange arg);
SDF_CharRange SDF_setCharRangeEnd(SDF_CharRange arg, SDF_Character end);
ATbool SDF_hasCharRangeCharacter(SDF_CharRange arg);
SDF_Character SDF_getCharRangeCharacter(SDF_CharRange arg);
SDF_CharRange SDF_setCharRangeCharacter(SDF_CharRange arg, SDF_Character character);
ATbool SDF_hasCharRangeStart(SDF_CharRange arg);
SDF_Character SDF_getCharRangeStart(SDF_CharRange arg);
SDF_CharRange SDF_setCharRangeStart(SDF_CharRange arg, SDF_Character start);
ATbool SDF_hasCharRangeWsAfterStart(SDF_CharRange arg);
SDF_Layout SDF_getCharRangeWsAfterStart(SDF_CharRange arg);
SDF_CharRange SDF_setCharRangeWsAfterStart(SDF_CharRange arg, SDF_Layout wsAfterStart);

/*}}}  */
/*{{{  SDF_CharRanges accessor prototypes */

ATbool SDF_isValidCharRanges(SDF_CharRanges arg);
ATbool SDF_isCharRangesDefault(SDF_CharRanges arg);
ATbool SDF_isCharRangesConc(SDF_CharRanges arg);
ATbool SDF_isCharRangesBracket(SDF_CharRanges arg);
ATbool SDF_hasCharRangesRight(SDF_CharRanges arg);
SDF_CharRanges SDF_getCharRangesRight(SDF_CharRanges arg);
SDF_CharRanges SDF_setCharRangesRight(SDF_CharRanges arg, SDF_CharRanges right);
ATbool SDF_hasCharRangesWsAfterLeft(SDF_CharRanges arg);
SDF_Layout SDF_getCharRangesWsAfterLeft(SDF_CharRanges arg);
SDF_CharRanges SDF_setCharRangesWsAfterLeft(SDF_CharRanges arg, SDF_Layout wsAfterLeft);
ATbool SDF_hasCharRangesWsAfterParenOpen(SDF_CharRanges arg);
SDF_Layout SDF_getCharRangesWsAfterParenOpen(SDF_CharRanges arg);
SDF_CharRanges SDF_setCharRangesWsAfterParenOpen(SDF_CharRanges arg, SDF_Layout wsAfterParenOpen);
ATbool SDF_hasCharRangesWsAfterCharRanges(SDF_CharRanges arg);
SDF_Layout SDF_getCharRangesWsAfterCharRanges(SDF_CharRanges arg);
SDF_CharRanges SDF_setCharRangesWsAfterCharRanges(SDF_CharRanges arg, SDF_Layout wsAfterCharRanges);
ATbool SDF_hasCharRangesCharRanges(SDF_CharRanges arg);
SDF_CharRanges SDF_getCharRangesCharRanges(SDF_CharRanges arg);
SDF_CharRanges SDF_setCharRangesCharRanges(SDF_CharRanges arg, SDF_CharRanges charRanges);
ATbool SDF_hasCharRangesCharRange(SDF_CharRanges arg);
SDF_CharRange SDF_getCharRangesCharRange(SDF_CharRanges arg);
SDF_CharRanges SDF_setCharRangesCharRange(SDF_CharRanges arg, SDF_CharRange charRange);
ATbool SDF_hasCharRangesLeft(SDF_CharRanges arg);
SDF_CharRanges SDF_getCharRangesLeft(SDF_CharRanges arg);
SDF_CharRanges SDF_setCharRangesLeft(SDF_CharRanges arg, SDF_CharRanges left);

/*}}}  */
/*{{{  SDF_OptCharRanges accessor prototypes */

ATbool SDF_isValidOptCharRanges(SDF_OptCharRanges arg);
ATbool SDF_isOptCharRangesAbsent(SDF_OptCharRanges arg);
ATbool SDF_isOptCharRangesPresent(SDF_OptCharRanges arg);
ATbool SDF_hasOptCharRangesCharRanges(SDF_OptCharRanges arg);
SDF_CharRanges SDF_getOptCharRangesCharRanges(SDF_OptCharRanges arg);
SDF_OptCharRanges SDF_setOptCharRangesCharRanges(SDF_OptCharRanges arg, SDF_CharRanges charRanges);

/*}}}  */
/*{{{  SDF_CharClass accessor prototypes */

ATbool SDF_isValidCharClass(SDF_CharClass arg);
ATbool SDF_isCharClassSimpleCharclass(SDF_CharClass arg);
ATbool SDF_isCharClassComp(SDF_CharClass arg);
ATbool SDF_isCharClassDiff(SDF_CharClass arg);
ATbool SDF_isCharClassIsect(SDF_CharClass arg);
ATbool SDF_isCharClassUnion(SDF_CharClass arg);
ATbool SDF_isCharClassBracket(SDF_CharClass arg);
ATbool SDF_hasCharClassRight(SDF_CharClass arg);
SDF_CharClass SDF_getCharClassRight(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassRight(SDF_CharClass arg, SDF_CharClass right);
ATbool SDF_hasCharClassWsAfterSlash(SDF_CharClass arg);
SDF_Layout SDF_getCharClassWsAfterSlash(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterSlash(SDF_CharClass arg, SDF_Layout wsAfterSlash);
ATbool SDF_hasCharClassOptCharRanges(SDF_CharClass arg);
SDF_OptCharRanges SDF_getCharClassOptCharRanges(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassOptCharRanges(SDF_CharClass arg, SDF_OptCharRanges optCharRanges);
ATbool SDF_hasCharClassWsAfterLeft(SDF_CharClass arg);
SDF_Layout SDF_getCharClassWsAfterLeft(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterLeft(SDF_CharClass arg, SDF_Layout wsAfterLeft);
ATbool SDF_hasCharClassWsAfterParenOpen(SDF_CharClass arg);
SDF_Layout SDF_getCharClassWsAfterParenOpen(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterParenOpen(SDF_CharClass arg, SDF_Layout wsAfterParenOpen);
ATbool SDF_hasCharClassWsAfterTilde(SDF_CharClass arg);
SDF_Layout SDF_getCharClassWsAfterTilde(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterTilde(SDF_CharClass arg, SDF_Layout wsAfterTilde);
ATbool SDF_hasCharClassWsAfterBackslashSlash(SDF_CharClass arg);
SDF_Layout SDF_getCharClassWsAfterBackslashSlash(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterBackslashSlash(SDF_CharClass arg, SDF_Layout wsAfterBackslashSlash);
ATbool SDF_hasCharClassWsAfterOptCharRanges(SDF_CharClass arg);
SDF_Layout SDF_getCharClassWsAfterOptCharRanges(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterOptCharRanges(SDF_CharClass arg, SDF_Layout wsAfterOptCharRanges);
ATbool SDF_hasCharClassCharClass(SDF_CharClass arg);
SDF_CharClass SDF_getCharClassCharClass(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassCharClass(SDF_CharClass arg, SDF_CharClass charClass);
ATbool SDF_hasCharClassWsAfterBracketOpen(SDF_CharClass arg);
SDF_Layout SDF_getCharClassWsAfterBracketOpen(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterBracketOpen(SDF_CharClass arg, SDF_Layout wsAfterBracketOpen);
ATbool SDF_hasCharClassWsAfterSlashBackslash(SDF_CharClass arg);
SDF_Layout SDF_getCharClassWsAfterSlashBackslash(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterSlashBackslash(SDF_CharClass arg, SDF_Layout wsAfterSlashBackslash);
ATbool SDF_hasCharClassWsAfterCharClass(SDF_CharClass arg);
SDF_Layout SDF_getCharClassWsAfterCharClass(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterCharClass(SDF_CharClass arg, SDF_Layout wsAfterCharClass);
ATbool SDF_hasCharClassLeft(SDF_CharClass arg);
SDF_CharClass SDF_getCharClassLeft(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassLeft(SDF_CharClass arg, SDF_CharClass left);

/*}}}  */
/*{{{  SDF_AlphaNumericalEscChar accessor prototypes */

ATbool SDF_isValidAlphaNumericalEscChar(SDF_AlphaNumericalEscChar arg);
ATbool SDF_isAlphaNumericalEscCharDefault(SDF_AlphaNumericalEscChar arg);
ATbool SDF_hasAlphaNumericalEscCharLex(SDF_AlphaNumericalEscChar arg);
SDF_Lexical SDF_getAlphaNumericalEscCharLex(SDF_AlphaNumericalEscChar arg);
SDF_AlphaNumericalEscChar SDF_setAlphaNumericalEscCharLex(SDF_AlphaNumericalEscChar arg, SDF_Lexical lex);

/*}}}  */
/*{{{  SDF_DecimalEscChar accessor prototypes */

ATbool SDF_isValidDecimalEscChar(SDF_DecimalEscChar arg);
ATbool SDF_isDecimalEscCharDec0_199(SDF_DecimalEscChar arg);
ATbool SDF_isDecimalEscCharDec200_249(SDF_DecimalEscChar arg);
ATbool SDF_isDecimalEscCharDec250_255(SDF_DecimalEscChar arg);
ATbool SDF_hasDecimalEscCharLex(SDF_DecimalEscChar arg);
SDF_Lexical SDF_getDecimalEscCharLex(SDF_DecimalEscChar arg);
SDF_DecimalEscChar SDF_setDecimalEscCharLex(SDF_DecimalEscChar arg, SDF_Lexical lex);

/*}}}  */
/*{{{  SDF_EscChar accessor prototypes */

ATbool SDF_isValidEscChar(SDF_EscChar arg);
ATbool SDF_isEscCharAlphaNumeric(SDF_EscChar arg);
ATbool SDF_isEscCharDecimal(SDF_EscChar arg);
ATbool SDF_hasEscCharLex(SDF_EscChar arg);
SDF_Lexical SDF_getEscCharLex(SDF_EscChar arg);
SDF_EscChar SDF_setEscCharLex(SDF_EscChar arg, SDF_Lexical lex);

/*}}}  */
/*{{{  SDF_LChar accessor prototypes */

ATbool SDF_isValidLChar(SDF_LChar arg);
ATbool SDF_isLCharNormal(SDF_LChar arg);
ATbool SDF_isLCharEscaped(SDF_LChar arg);
ATbool SDF_hasLCharLex(SDF_LChar arg);
SDF_Lexical SDF_getLCharLex(SDF_LChar arg);
SDF_LChar SDF_setLCharLex(SDF_LChar arg, SDF_Lexical lex);

/*}}}  */
/*{{{  SDF_ATerms accessor prototypes */

ATbool SDF_isValidATerms(SDF_ATerms arg);
ATbool SDF_isATermsAterm(SDF_ATerms arg);
ATbool SDF_isATermsCons(SDF_ATerms arg);
ATbool SDF_hasATermsWsAfterComma(SDF_ATerms arg);
SDF_Layout SDF_getATermsWsAfterComma(SDF_ATerms arg);
SDF_ATerms SDF_setATermsWsAfterComma(SDF_ATerms arg, SDF_Layout wsAfterComma);
ATbool SDF_hasATermsATerm(SDF_ATerms arg);
SDF_ATerm SDF_getATermsATerm(SDF_ATerms arg);
SDF_ATerms SDF_setATermsATerm(SDF_ATerms arg, SDF_ATerm aTerm);
ATbool SDF_hasATermsTail(SDF_ATerms arg);
SDF_ATerms SDF_getATermsTail(SDF_ATerms arg);
SDF_ATerms SDF_setATermsTail(SDF_ATerms arg, SDF_ATerms tail);
ATbool SDF_hasATermsHead(SDF_ATerms arg);
SDF_ATerm SDF_getATermsHead(SDF_ATerms arg);
SDF_ATerms SDF_setATermsHead(SDF_ATerms arg, SDF_ATerm head);
ATbool SDF_hasATermsWsAfterHead(SDF_ATerms arg);
SDF_Layout SDF_getATermsWsAfterHead(SDF_ATerms arg);
SDF_ATerms SDF_setATermsWsAfterHead(SDF_ATerms arg, SDF_Layout wsAfterHead);

/*}}}  */
/*{{{  SDF_ATermList accessor prototypes */

ATbool SDF_isValidATermList(SDF_ATermList arg);
ATbool SDF_isATermListEmpty(SDF_ATermList arg);
ATbool SDF_isATermListNotEmpty(SDF_ATermList arg);
ATbool SDF_hasATermListWsAfterBracketOpen(SDF_ATermList arg);
SDF_Layout SDF_getATermListWsAfterBracketOpen(SDF_ATermList arg);
SDF_ATermList SDF_setATermListWsAfterBracketOpen(SDF_ATermList arg, SDF_Layout wsAfterBracketOpen);
ATbool SDF_hasATermListWsAfterATerms(SDF_ATermList arg);
SDF_Layout SDF_getATermListWsAfterATerms(SDF_ATermList arg);
SDF_ATermList SDF_setATermListWsAfterATerms(SDF_ATermList arg, SDF_Layout wsAfterATerms);
ATbool SDF_hasATermListATerms(SDF_ATermList arg);
SDF_ATerms SDF_getATermListATerms(SDF_ATermList arg);
SDF_ATermList SDF_setATermListATerms(SDF_ATermList arg, SDF_ATerms aTerms);

/*}}}  */
/*{{{  SDF_ACon accessor prototypes */

ATbool SDF_isValidACon(SDF_ACon arg);
ATbool SDF_isAConInt(SDF_ACon arg);
ATbool SDF_isAConReal(SDF_ACon arg);
ATbool SDF_hasAConIntCon(SDF_ACon arg);
SDF_IntCon SDF_getAConIntCon(SDF_ACon arg);
SDF_ACon SDF_setAConIntCon(SDF_ACon arg, SDF_IntCon intCon);
ATbool SDF_hasAConRealCon(SDF_ACon arg);
SDF_RealCon SDF_getAConRealCon(SDF_ACon arg);
SDF_ACon SDF_setAConRealCon(SDF_ACon arg, SDF_RealCon realCon);

/*}}}  */
/*{{{  SDF_AFun accessor prototypes */

ATbool SDF_isValidAFun(SDF_AFun arg);
ATbool SDF_isAFunDefault(SDF_AFun arg);
ATbool SDF_hasAFunLiteral(SDF_AFun arg);
SDF_Literal SDF_getAFunLiteral(SDF_AFun arg);
SDF_AFun SDF_setAFunLiteral(SDF_AFun arg, SDF_Literal literal);

/*}}}  */
/*{{{  SDF_ATerm accessor prototypes */

ATbool SDF_isValidATerm(SDF_ATerm arg);
ATbool SDF_isATermConstant(SDF_ATerm arg);
ATbool SDF_isATermList(SDF_ATerm arg);
ATbool SDF_isATermFun(SDF_ATerm arg);
ATbool SDF_isATermAppl(SDF_ATerm arg);
ATbool SDF_isATermAnnotatedConstant(SDF_ATerm arg);
ATbool SDF_isATermAnnotatedList(SDF_ATerm arg);
ATbool SDF_isATermAnnotatedFun(SDF_ATerm arg);
ATbool SDF_isATermAnnotatedAppl(SDF_ATerm arg);
ATbool SDF_hasATermWsAfterAFun(SDF_ATerm arg);
SDF_Layout SDF_getATermWsAfterAFun(SDF_ATerm arg);
SDF_ATerm SDF_setATermWsAfterAFun(SDF_ATerm arg, SDF_Layout wsAfterAFun);
ATbool SDF_hasATermWsAfterParenClose(SDF_ATerm arg);
SDF_Layout SDF_getATermWsAfterParenClose(SDF_ATerm arg);
SDF_ATerm SDF_setATermWsAfterParenClose(SDF_ATerm arg, SDF_Layout wsAfterParenClose);
ATbool SDF_hasATermWsAfterParenOpen(SDF_ATerm arg);
SDF_Layout SDF_getATermWsAfterParenOpen(SDF_ATerm arg);
SDF_ATerm SDF_setATermWsAfterParenOpen(SDF_ATerm arg, SDF_Layout wsAfterParenOpen);
ATbool SDF_hasATermACon(SDF_ATerm arg);
SDF_ACon SDF_getATermACon(SDF_ATerm arg);
SDF_ATerm SDF_setATermACon(SDF_ATerm arg, SDF_ACon aCon);
ATbool SDF_hasATermAnn(SDF_ATerm arg);
SDF_Ann SDF_getATermAnn(SDF_ATerm arg);
SDF_ATerm SDF_setATermAnn(SDF_ATerm arg, SDF_Ann ann);
ATbool SDF_hasATermArgs(SDF_ATerm arg);
SDF_ATerms SDF_getATermArgs(SDF_ATerm arg);
SDF_ATerm SDF_setATermArgs(SDF_ATerm arg, SDF_ATerms args);
ATbool SDF_hasATermWsAfterACon(SDF_ATerm arg);
SDF_Layout SDF_getATermWsAfterACon(SDF_ATerm arg);
SDF_ATerm SDF_setATermWsAfterACon(SDF_ATerm arg, SDF_Layout wsAfterACon);
ATbool SDF_hasATermWsAfterArgs(SDF_ATerm arg);
SDF_Layout SDF_getATermWsAfterArgs(SDF_ATerm arg);
SDF_ATerm SDF_setATermWsAfterArgs(SDF_ATerm arg, SDF_Layout wsAfterArgs);
ATbool SDF_hasATermATermList(SDF_ATerm arg);
SDF_ATermList SDF_getATermATermList(SDF_ATerm arg);
SDF_ATerm SDF_setATermATermList(SDF_ATerm arg, SDF_ATermList aTermList);
ATbool SDF_hasATermAFun(SDF_ATerm arg);
SDF_AFun SDF_getATermAFun(SDF_ATerm arg);
SDF_ATerm SDF_setATermAFun(SDF_ATerm arg, SDF_AFun aFun);
ATbool SDF_hasATermWsAfterATermList(SDF_ATerm arg);
SDF_Layout SDF_getATermWsAfterATermList(SDF_ATerm arg);
SDF_ATerm SDF_setATermWsAfterATermList(SDF_ATerm arg, SDF_Layout wsAfterATermList);

/*}}}  */
/*{{{  SDF_Ann accessor prototypes */

ATbool SDF_isValidAnn(SDF_Ann arg);
ATbool SDF_isAnnAnnotation(SDF_Ann arg);
ATbool SDF_hasAnnWsAfterBraceOpen(SDF_Ann arg);
SDF_Layout SDF_getAnnWsAfterBraceOpen(SDF_Ann arg);
SDF_Ann SDF_setAnnWsAfterBraceOpen(SDF_Ann arg, SDF_Layout wsAfterBraceOpen);
ATbool SDF_hasAnnWsAfterATerms(SDF_Ann arg);
SDF_Layout SDF_getAnnWsAfterATerms(SDF_Ann arg);
SDF_Ann SDF_setAnnWsAfterATerms(SDF_Ann arg, SDF_Layout wsAfterATerms);
ATbool SDF_hasAnnATerms(SDF_Ann arg);
SDF_ATerms SDF_getAnnATerms(SDF_Ann arg);
SDF_Ann SDF_setAnnATerms(SDF_Ann arg, SDF_ATerms aTerms);

/*}}}  */
/*{{{  SDF_TagId accessor prototypes */

ATbool SDF_isValidTagId(SDF_TagId arg);
ATbool SDF_isTagIdDefault(SDF_TagId arg);
ATbool SDF_isTagIdEmpty(SDF_TagId arg);
ATbool SDF_hasTagIdLex(SDF_TagId arg);
SDF_Lexical SDF_getTagIdLex(SDF_TagId arg);
SDF_TagId SDF_setTagIdLex(SDF_TagId arg, SDF_Lexical lex);

/*}}}  */
/*{{{  SDF_NumChar accessor prototypes */

ATbool SDF_isValidNumChar(SDF_NumChar arg);
ATbool SDF_isNumCharDigits(SDF_NumChar arg);
ATbool SDF_hasNumCharLex(SDF_NumChar arg);
SDF_Lexical SDF_getNumCharLex(SDF_NumChar arg);
SDF_NumChar SDF_setNumCharLex(SDF_NumChar arg, SDF_Lexical lex);

/*}}}  */
/*{{{  SDF_ShortChar accessor prototypes */

ATbool SDF_isValidShortChar(SDF_ShortChar arg);
ATbool SDF_isShortCharRegular(SDF_ShortChar arg);
ATbool SDF_isShortCharEscaped(SDF_ShortChar arg);
ATbool SDF_hasShortCharLex(SDF_ShortChar arg);
SDF_Lexical SDF_getShortCharLex(SDF_ShortChar arg);
SDF_ShortChar SDF_setShortCharLex(SDF_ShortChar arg, SDF_Lexical lex);

/*}}}  */
/*{{{  SDF_Character accessor prototypes */

ATbool SDF_isValidCharacter(SDF_Character arg);
ATbool SDF_isCharacterNumeric(SDF_Character arg);
ATbool SDF_isCharacterShort(SDF_Character arg);
ATbool SDF_isCharacterTop(SDF_Character arg);
ATbool SDF_isCharacterEof(SDF_Character arg);
ATbool SDF_hasCharacterShortChar(SDF_Character arg);
SDF_ShortChar SDF_getCharacterShortChar(SDF_Character arg);
SDF_Character SDF_setCharacterShortChar(SDF_Character arg, SDF_ShortChar shortChar);
ATbool SDF_hasCharacterNumChar(SDF_Character arg);
SDF_NumChar SDF_getCharacterNumChar(SDF_Character arg);
SDF_Character SDF_setCharacterNumChar(SDF_Character arg, SDF_NumChar numChar);

/*}}}  */
/*{{{  SDF_OptExp accessor prototypes */

ATbool SDF_isValidOptExp(SDF_OptExp arg);
ATbool SDF_isOptExpPresent(SDF_OptExp arg);
ATbool SDF_isOptExpAbsent(SDF_OptExp arg);
ATbool SDF_hasOptExpWsAfterE(SDF_OptExp arg);
SDF_Layout SDF_getOptExpWsAfterE(SDF_OptExp arg);
SDF_OptExp SDF_setOptExpWsAfterE(SDF_OptExp arg, SDF_Layout wsAfterE);
ATbool SDF_hasOptExpIntCon(SDF_OptExp arg);
SDF_IntCon SDF_getOptExpIntCon(SDF_OptExp arg);
SDF_OptExp SDF_setOptExpIntCon(SDF_OptExp arg, SDF_IntCon intCon);

/*}}}  */
/*{{{  SDF_RealCon accessor prototypes */

ATbool SDF_isValidRealCon(SDF_RealCon arg);
ATbool SDF_isRealConRealCon(SDF_RealCon arg);
ATbool SDF_hasRealConWsAfterPeriod(SDF_RealCon arg);
SDF_Layout SDF_getRealConWsAfterPeriod(SDF_RealCon arg);
SDF_RealCon SDF_setRealConWsAfterPeriod(SDF_RealCon arg, SDF_Layout wsAfterPeriod);
ATbool SDF_hasRealConWsAfterIntCon(SDF_RealCon arg);
SDF_Layout SDF_getRealConWsAfterIntCon(SDF_RealCon arg);
SDF_RealCon SDF_setRealConWsAfterIntCon(SDF_RealCon arg, SDF_Layout wsAfterIntCon);
ATbool SDF_hasRealConOptExp(SDF_RealCon arg);
SDF_OptExp SDF_getRealConOptExp(SDF_RealCon arg);
SDF_RealCon SDF_setRealConOptExp(SDF_RealCon arg, SDF_OptExp optExp);
ATbool SDF_hasRealConIntCon(SDF_RealCon arg);
SDF_IntCon SDF_getRealConIntCon(SDF_RealCon arg);
SDF_RealCon SDF_setRealConIntCon(SDF_RealCon arg, SDF_IntCon intCon);
ATbool SDF_hasRealConWsAfterNatCon(SDF_RealCon arg);
SDF_Layout SDF_getRealConWsAfterNatCon(SDF_RealCon arg);
SDF_RealCon SDF_setRealConWsAfterNatCon(SDF_RealCon arg, SDF_Layout wsAfterNatCon);
ATbool SDF_hasRealConNatCon(SDF_RealCon arg);
SDF_NatCon SDF_getRealConNatCon(SDF_RealCon arg);
SDF_RealCon SDF_setRealConNatCon(SDF_RealCon arg, SDF_NatCon natCon);

/*}}}  */

#endif /* _SDF_H */
