#ifndef _SDFME_H
#define _SDFME_H

/*{{{  includes */

#include <aterm1.h>
#include "SDFME_dict.h"

/*}}}  */

/*{{{  prologue */

typedef struct _SDF_CHARLIST *SDF_CHARLIST;

ATbool SDF_isValidCHARLIST(SDF_CHARLIST arg);
ATbool SDF_isCHARLISTString(SDF_CHARLIST arg);
char*  SDF_getCHARLISTString(SDF_CHARLIST arg);
SDF_CHARLIST  SDF_setCHARLISTString(SDF_CHARLIST arg, char *str);
ATerm  SDF_CHARLISTToTerm(SDF_CHARLIST arg);
SDF_CHARLIST SDF_CHARLISTFromTerm(ATerm trm);
SDF_CHARLIST SDF_makeCHARLISTString(char *str);

/*}}}  */
/*{{{  typedefs */

typedef struct _SDF_Grammar *SDF_Grammar;
typedef struct _SDF_Alias *SDF_Alias;
typedef struct _SDF_Aliases *SDF_Aliases;
typedef struct _SDF_AliasList *SDF_AliasList;
typedef struct _SDF_Lookahead *SDF_Lookahead;
typedef struct _SDF_Lookaheads *SDF_Lookaheads;
typedef struct _SDF_LookaheadList *SDF_LookaheadList;
typedef struct _SDF_Restriction *SDF_Restriction;
typedef struct _SDF_Restrictions *SDF_Restrictions;
typedef struct _SDF_RestrictionList *SDF_RestrictionList;
typedef struct _SDF_Attribute *SDF_Attribute;
typedef struct _SDF_Symbol *SDF_Symbol;
typedef struct _SDF_Production *SDF_Production;
typedef struct _SDF_SymbolArguments *SDF_SymbolArguments;
typedef struct _SDF_Sort *SDF_Sort;
typedef struct _SDF_SymbolParameters *SDF_SymbolParameters;
typedef struct _SDF_NumChar *SDF_NumChar;
typedef struct _SDF_ShortChar *SDF_ShortChar;
typedef struct _SDF_Character *SDF_Character;
typedef struct _SDF_CharRange *SDF_CharRange;
typedef struct _SDF_CharRanges *SDF_CharRanges;
typedef struct _SDF_OptCharRanges *SDF_OptCharRanges;
typedef struct _SDF_CharClass *SDF_CharClass;
typedef struct _SDF_Associativity *SDF_Associativity;
typedef struct _SDF_Group *SDF_Group;
typedef struct _SDF_Priority *SDF_Priority;
typedef struct _SDF_GroupList *SDF_GroupList;
typedef struct _SDF_Priorities *SDF_Priorities;
typedef struct _SDF_PriorityList *SDF_PriorityList;
typedef struct _SDF_SymbolTail *SDF_SymbolTail;
typedef struct _SDF_SymbolRest *SDF_SymbolRest;
typedef struct _SDF_Renamings *SDF_Renamings;
typedef struct _SDF_RenamingList *SDF_RenamingList;
typedef struct _SDF_Renaming *SDF_Renaming;
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
typedef struct _SDF_ImpSection *SDF_ImpSection;
typedef struct _SDF_Imports *SDF_Imports;
typedef struct _SDF_ImportList *SDF_ImportList;
typedef struct _SDF_Import *SDF_Import;
typedef struct _SDF_Symbols *SDF_Symbols;
typedef struct _SDF_SymbolList *SDF_SymbolList;
typedef struct _SDF_OptExp *SDF_OptExp;
typedef struct _SDF_RealCon *SDF_RealCon;
typedef struct _SDF_NatCon *SDF_NatCon;
typedef struct _SDF_IntCon *SDF_IntCon;
typedef struct _SDF_AlphaNumericalEscChar *SDF_AlphaNumericalEscChar;
typedef struct _SDF_DecimalEscChar *SDF_DecimalEscChar;
typedef struct _SDF_EscChar *SDF_EscChar;
typedef struct _SDF_LChar *SDF_LChar;
typedef struct _SDF_QLiteral *SDF_QLiteral;
typedef struct _SDF_UQLiteral *SDF_UQLiteral;
typedef struct _SDF_Literal *SDF_Literal;
typedef struct _SDF_ATermList *SDF_ATermList;
typedef struct _SDF_ATermElems *SDF_ATermElems;
typedef struct _SDF_ACon *SDF_ACon;
typedef struct _SDF_AFun *SDF_AFun;
typedef struct _SDF_ATerm *SDF_ATerm;
typedef struct _SDF_ATermArgs *SDF_ATermArgs;
typedef struct _SDF_Ann *SDF_Ann;
typedef struct _SDF_ATermAnnos *SDF_ATermAnnos;
typedef struct _SDF_Attributes *SDF_Attributes;
typedef struct _SDF_AttributeList *SDF_AttributeList;
typedef struct _SDF_Productions *SDF_Productions;
typedef struct _SDF_ProductionList *SDF_ProductionList;
typedef struct _SDF_SDF *SDF_SDF;
typedef struct _SDF_OptLayout *SDF_OptLayout;
typedef struct _SDF_Start *SDF_Start;

/*}}}  */

void SDF_initSDFMEApi(void);

/*{{{  term conversion functions */

#define SDF_makeGrammarFromTerm(t) (SDF_GrammarFromTerm(t))
SDF_Grammar SDF_GrammarFromTerm(ATerm t);
#define SDF_makeTermFromGrammar(t) (SDF_GrammarToTerm(t))
ATerm SDF_GrammarToTerm(SDF_Grammar arg);
#define SDF_makeAliasFromTerm(t) (SDF_AliasFromTerm(t))
SDF_Alias SDF_AliasFromTerm(ATerm t);
#define SDF_makeTermFromAlias(t) (SDF_AliasToTerm(t))
ATerm SDF_AliasToTerm(SDF_Alias arg);
#define SDF_makeAliasesFromTerm(t) (SDF_AliasesFromTerm(t))
SDF_Aliases SDF_AliasesFromTerm(ATerm t);
#define SDF_makeTermFromAliases(t) (SDF_AliasesToTerm(t))
ATerm SDF_AliasesToTerm(SDF_Aliases arg);
#define SDF_makeAliasListFromTerm(t) (SDF_AliasListFromTerm(t))
SDF_AliasList SDF_AliasListFromTerm(ATerm t);
#define SDF_makeTermFromAliasList(t) (SDF_AliasListToTerm(t))
ATerm SDF_AliasListToTerm(SDF_AliasList arg);
#define SDF_makeLookaheadFromTerm(t) (SDF_LookaheadFromTerm(t))
SDF_Lookahead SDF_LookaheadFromTerm(ATerm t);
#define SDF_makeTermFromLookahead(t) (SDF_LookaheadToTerm(t))
ATerm SDF_LookaheadToTerm(SDF_Lookahead arg);
#define SDF_makeLookaheadsFromTerm(t) (SDF_LookaheadsFromTerm(t))
SDF_Lookaheads SDF_LookaheadsFromTerm(ATerm t);
#define SDF_makeTermFromLookaheads(t) (SDF_LookaheadsToTerm(t))
ATerm SDF_LookaheadsToTerm(SDF_Lookaheads arg);
#define SDF_makeLookaheadListFromTerm(t) (SDF_LookaheadListFromTerm(t))
SDF_LookaheadList SDF_LookaheadListFromTerm(ATerm t);
#define SDF_makeTermFromLookaheadList(t) (SDF_LookaheadListToTerm(t))
ATerm SDF_LookaheadListToTerm(SDF_LookaheadList arg);
#define SDF_makeRestrictionFromTerm(t) (SDF_RestrictionFromTerm(t))
SDF_Restriction SDF_RestrictionFromTerm(ATerm t);
#define SDF_makeTermFromRestriction(t) (SDF_RestrictionToTerm(t))
ATerm SDF_RestrictionToTerm(SDF_Restriction arg);
#define SDF_makeRestrictionsFromTerm(t) (SDF_RestrictionsFromTerm(t))
SDF_Restrictions SDF_RestrictionsFromTerm(ATerm t);
#define SDF_makeTermFromRestrictions(t) (SDF_RestrictionsToTerm(t))
ATerm SDF_RestrictionsToTerm(SDF_Restrictions arg);
#define SDF_makeRestrictionListFromTerm(t) (SDF_RestrictionListFromTerm(t))
SDF_RestrictionList SDF_RestrictionListFromTerm(ATerm t);
#define SDF_makeTermFromRestrictionList(t) (SDF_RestrictionListToTerm(t))
ATerm SDF_RestrictionListToTerm(SDF_RestrictionList arg);
#define SDF_makeAttributeFromTerm(t) (SDF_AttributeFromTerm(t))
SDF_Attribute SDF_AttributeFromTerm(ATerm t);
#define SDF_makeTermFromAttribute(t) (SDF_AttributeToTerm(t))
ATerm SDF_AttributeToTerm(SDF_Attribute arg);
#define SDF_makeSymbolFromTerm(t) (SDF_SymbolFromTerm(t))
SDF_Symbol SDF_SymbolFromTerm(ATerm t);
#define SDF_makeTermFromSymbol(t) (SDF_SymbolToTerm(t))
ATerm SDF_SymbolToTerm(SDF_Symbol arg);
#define SDF_makeProductionFromTerm(t) (SDF_ProductionFromTerm(t))
SDF_Production SDF_ProductionFromTerm(ATerm t);
#define SDF_makeTermFromProduction(t) (SDF_ProductionToTerm(t))
ATerm SDF_ProductionToTerm(SDF_Production arg);
#define SDF_makeSymbolArgumentsFromTerm(t) (SDF_SymbolArgumentsFromTerm(t))
SDF_SymbolArguments SDF_SymbolArgumentsFromTerm(ATerm t);
#define SDF_makeTermFromSymbolArguments(t) (SDF_SymbolArgumentsToTerm(t))
ATerm SDF_SymbolArgumentsToTerm(SDF_SymbolArguments arg);
#define SDF_makeSortFromTerm(t) (SDF_SortFromTerm(t))
SDF_Sort SDF_SortFromTerm(ATerm t);
#define SDF_makeTermFromSort(t) (SDF_SortToTerm(t))
ATerm SDF_SortToTerm(SDF_Sort arg);
#define SDF_makeSymbolParametersFromTerm(t) (SDF_SymbolParametersFromTerm(t))
SDF_SymbolParameters SDF_SymbolParametersFromTerm(ATerm t);
#define SDF_makeTermFromSymbolParameters(t) (SDF_SymbolParametersToTerm(t))
ATerm SDF_SymbolParametersToTerm(SDF_SymbolParameters arg);
#define SDF_makeNumCharFromTerm(t) (SDF_NumCharFromTerm(t))
SDF_NumChar SDF_NumCharFromTerm(ATerm t);
#define SDF_makeTermFromNumChar(t) (SDF_NumCharToTerm(t))
ATerm SDF_NumCharToTerm(SDF_NumChar arg);
#define SDF_makeShortCharFromTerm(t) (SDF_ShortCharFromTerm(t))
SDF_ShortChar SDF_ShortCharFromTerm(ATerm t);
#define SDF_makeTermFromShortChar(t) (SDF_ShortCharToTerm(t))
ATerm SDF_ShortCharToTerm(SDF_ShortChar arg);
#define SDF_makeCharacterFromTerm(t) (SDF_CharacterFromTerm(t))
SDF_Character SDF_CharacterFromTerm(ATerm t);
#define SDF_makeTermFromCharacter(t) (SDF_CharacterToTerm(t))
ATerm SDF_CharacterToTerm(SDF_Character arg);
#define SDF_makeCharRangeFromTerm(t) (SDF_CharRangeFromTerm(t))
SDF_CharRange SDF_CharRangeFromTerm(ATerm t);
#define SDF_makeTermFromCharRange(t) (SDF_CharRangeToTerm(t))
ATerm SDF_CharRangeToTerm(SDF_CharRange arg);
#define SDF_makeCharRangesFromTerm(t) (SDF_CharRangesFromTerm(t))
SDF_CharRanges SDF_CharRangesFromTerm(ATerm t);
#define SDF_makeTermFromCharRanges(t) (SDF_CharRangesToTerm(t))
ATerm SDF_CharRangesToTerm(SDF_CharRanges arg);
#define SDF_makeOptCharRangesFromTerm(t) (SDF_OptCharRangesFromTerm(t))
SDF_OptCharRanges SDF_OptCharRangesFromTerm(ATerm t);
#define SDF_makeTermFromOptCharRanges(t) (SDF_OptCharRangesToTerm(t))
ATerm SDF_OptCharRangesToTerm(SDF_OptCharRanges arg);
#define SDF_makeCharClassFromTerm(t) (SDF_CharClassFromTerm(t))
SDF_CharClass SDF_CharClassFromTerm(ATerm t);
#define SDF_makeTermFromCharClass(t) (SDF_CharClassToTerm(t))
ATerm SDF_CharClassToTerm(SDF_CharClass arg);
#define SDF_makeAssociativityFromTerm(t) (SDF_AssociativityFromTerm(t))
SDF_Associativity SDF_AssociativityFromTerm(ATerm t);
#define SDF_makeTermFromAssociativity(t) (SDF_AssociativityToTerm(t))
ATerm SDF_AssociativityToTerm(SDF_Associativity arg);
#define SDF_makeGroupFromTerm(t) (SDF_GroupFromTerm(t))
SDF_Group SDF_GroupFromTerm(ATerm t);
#define SDF_makeTermFromGroup(t) (SDF_GroupToTerm(t))
ATerm SDF_GroupToTerm(SDF_Group arg);
#define SDF_makePriorityFromTerm(t) (SDF_PriorityFromTerm(t))
SDF_Priority SDF_PriorityFromTerm(ATerm t);
#define SDF_makeTermFromPriority(t) (SDF_PriorityToTerm(t))
ATerm SDF_PriorityToTerm(SDF_Priority arg);
#define SDF_makeGroupListFromTerm(t) (SDF_GroupListFromTerm(t))
SDF_GroupList SDF_GroupListFromTerm(ATerm t);
#define SDF_makeTermFromGroupList(t) (SDF_GroupListToTerm(t))
ATerm SDF_GroupListToTerm(SDF_GroupList arg);
#define SDF_makePrioritiesFromTerm(t) (SDF_PrioritiesFromTerm(t))
SDF_Priorities SDF_PrioritiesFromTerm(ATerm t);
#define SDF_makeTermFromPriorities(t) (SDF_PrioritiesToTerm(t))
ATerm SDF_PrioritiesToTerm(SDF_Priorities arg);
#define SDF_makePriorityListFromTerm(t) (SDF_PriorityListFromTerm(t))
SDF_PriorityList SDF_PriorityListFromTerm(ATerm t);
#define SDF_makeTermFromPriorityList(t) (SDF_PriorityListToTerm(t))
ATerm SDF_PriorityListToTerm(SDF_PriorityList arg);
#define SDF_makeSymbolTailFromTerm(t) (SDF_SymbolTailFromTerm(t))
SDF_SymbolTail SDF_SymbolTailFromTerm(ATerm t);
#define SDF_makeTermFromSymbolTail(t) (SDF_SymbolTailToTerm(t))
ATerm SDF_SymbolTailToTerm(SDF_SymbolTail arg);
#define SDF_makeSymbolRestFromTerm(t) (SDF_SymbolRestFromTerm(t))
SDF_SymbolRest SDF_SymbolRestFromTerm(ATerm t);
#define SDF_makeTermFromSymbolRest(t) (SDF_SymbolRestToTerm(t))
ATerm SDF_SymbolRestToTerm(SDF_SymbolRest arg);
#define SDF_makeRenamingsFromTerm(t) (SDF_RenamingsFromTerm(t))
SDF_Renamings SDF_RenamingsFromTerm(ATerm t);
#define SDF_makeTermFromRenamings(t) (SDF_RenamingsToTerm(t))
ATerm SDF_RenamingsToTerm(SDF_Renamings arg);
#define SDF_makeRenamingListFromTerm(t) (SDF_RenamingListFromTerm(t))
SDF_RenamingList SDF_RenamingListFromTerm(ATerm t);
#define SDF_makeTermFromRenamingList(t) (SDF_RenamingListToTerm(t))
ATerm SDF_RenamingListToTerm(SDF_RenamingList arg);
#define SDF_makeRenamingFromTerm(t) (SDF_RenamingFromTerm(t))
SDF_Renaming SDF_RenamingFromTerm(ATerm t);
#define SDF_makeTermFromRenaming(t) (SDF_RenamingToTerm(t))
ATerm SDF_RenamingToTerm(SDF_Renaming arg);
#define SDF_makeModuleWordFromTerm(t) (SDF_ModuleWordFromTerm(t))
SDF_ModuleWord SDF_ModuleWordFromTerm(ATerm t);
#define SDF_makeTermFromModuleWord(t) (SDF_ModuleWordToTerm(t))
ATerm SDF_ModuleWordToTerm(SDF_ModuleWord arg);
#define SDF_makeModuleIdFromTerm(t) (SDF_ModuleIdFromTerm(t))
SDF_ModuleId SDF_ModuleIdFromTerm(ATerm t);
#define SDF_makeTermFromModuleId(t) (SDF_ModuleIdToTerm(t))
ATerm SDF_ModuleIdToTerm(SDF_ModuleId arg);
#define SDF_makeDefinitionFromTerm(t) (SDF_DefinitionFromTerm(t))
SDF_Definition SDF_DefinitionFromTerm(ATerm t);
#define SDF_makeTermFromDefinition(t) (SDF_DefinitionToTerm(t))
ATerm SDF_DefinitionToTerm(SDF_Definition arg);
#define SDF_makeModuleListFromTerm(t) (SDF_ModuleListFromTerm(t))
SDF_ModuleList SDF_ModuleListFromTerm(ATerm t);
#define SDF_makeTermFromModuleList(t) (SDF_ModuleListToTerm(t))
ATerm SDF_ModuleListToTerm(SDF_ModuleList arg);
#define SDF_makeModuleFromTerm(t) (SDF_ModuleFromTerm(t))
SDF_Module SDF_ModuleFromTerm(ATerm t);
#define SDF_makeTermFromModule(t) (SDF_ModuleToTerm(t))
ATerm SDF_ModuleToTerm(SDF_Module arg);
#define SDF_makeImpSectionListFromTerm(t) (SDF_ImpSectionListFromTerm(t))
SDF_ImpSectionList SDF_ImpSectionListFromTerm(ATerm t);
#define SDF_makeTermFromImpSectionList(t) (SDF_ImpSectionListToTerm(t))
ATerm SDF_ImpSectionListToTerm(SDF_ImpSectionList arg);
#define SDF_makeSectionFromTerm(t) (SDF_SectionFromTerm(t))
SDF_Section SDF_SectionFromTerm(ATerm t);
#define SDF_makeTermFromSection(t) (SDF_SectionToTerm(t))
ATerm SDF_SectionToTerm(SDF_Section arg);
#define SDF_makeSectionsFromTerm(t) (SDF_SectionsFromTerm(t))
SDF_Sections SDF_SectionsFromTerm(ATerm t);
#define SDF_makeTermFromSections(t) (SDF_SectionsToTerm(t))
ATerm SDF_SectionsToTerm(SDF_Sections arg);
#define SDF_makeSectionListFromTerm(t) (SDF_SectionListFromTerm(t))
SDF_SectionList SDF_SectionListFromTerm(ATerm t);
#define SDF_makeTermFromSectionList(t) (SDF_SectionListToTerm(t))
ATerm SDF_SectionListToTerm(SDF_SectionList arg);
#define SDF_makeModuleNameFromTerm(t) (SDF_ModuleNameFromTerm(t))
SDF_ModuleName SDF_ModuleNameFromTerm(ATerm t);
#define SDF_makeTermFromModuleName(t) (SDF_ModuleNameToTerm(t))
ATerm SDF_ModuleNameToTerm(SDF_ModuleName arg);
#define SDF_makeImpSectionFromTerm(t) (SDF_ImpSectionFromTerm(t))
SDF_ImpSection SDF_ImpSectionFromTerm(ATerm t);
#define SDF_makeTermFromImpSection(t) (SDF_ImpSectionToTerm(t))
ATerm SDF_ImpSectionToTerm(SDF_ImpSection arg);
#define SDF_makeImportsFromTerm(t) (SDF_ImportsFromTerm(t))
SDF_Imports SDF_ImportsFromTerm(ATerm t);
#define SDF_makeTermFromImports(t) (SDF_ImportsToTerm(t))
ATerm SDF_ImportsToTerm(SDF_Imports arg);
#define SDF_makeImportListFromTerm(t) (SDF_ImportListFromTerm(t))
SDF_ImportList SDF_ImportListFromTerm(ATerm t);
#define SDF_makeTermFromImportList(t) (SDF_ImportListToTerm(t))
ATerm SDF_ImportListToTerm(SDF_ImportList arg);
#define SDF_makeImportFromTerm(t) (SDF_ImportFromTerm(t))
SDF_Import SDF_ImportFromTerm(ATerm t);
#define SDF_makeTermFromImport(t) (SDF_ImportToTerm(t))
ATerm SDF_ImportToTerm(SDF_Import arg);
#define SDF_makeSymbolsFromTerm(t) (SDF_SymbolsFromTerm(t))
SDF_Symbols SDF_SymbolsFromTerm(ATerm t);
#define SDF_makeTermFromSymbols(t) (SDF_SymbolsToTerm(t))
ATerm SDF_SymbolsToTerm(SDF_Symbols arg);
#define SDF_makeSymbolListFromTerm(t) (SDF_SymbolListFromTerm(t))
SDF_SymbolList SDF_SymbolListFromTerm(ATerm t);
#define SDF_makeTermFromSymbolList(t) (SDF_SymbolListToTerm(t))
ATerm SDF_SymbolListToTerm(SDF_SymbolList arg);
#define SDF_makeOptExpFromTerm(t) (SDF_OptExpFromTerm(t))
SDF_OptExp SDF_OptExpFromTerm(ATerm t);
#define SDF_makeTermFromOptExp(t) (SDF_OptExpToTerm(t))
ATerm SDF_OptExpToTerm(SDF_OptExp arg);
#define SDF_makeRealConFromTerm(t) (SDF_RealConFromTerm(t))
SDF_RealCon SDF_RealConFromTerm(ATerm t);
#define SDF_makeTermFromRealCon(t) (SDF_RealConToTerm(t))
ATerm SDF_RealConToTerm(SDF_RealCon arg);
#define SDF_makeNatConFromTerm(t) (SDF_NatConFromTerm(t))
SDF_NatCon SDF_NatConFromTerm(ATerm t);
#define SDF_makeTermFromNatCon(t) (SDF_NatConToTerm(t))
ATerm SDF_NatConToTerm(SDF_NatCon arg);
#define SDF_makeIntConFromTerm(t) (SDF_IntConFromTerm(t))
SDF_IntCon SDF_IntConFromTerm(ATerm t);
#define SDF_makeTermFromIntCon(t) (SDF_IntConToTerm(t))
ATerm SDF_IntConToTerm(SDF_IntCon arg);
#define SDF_makeAlphaNumericalEscCharFromTerm(t) (SDF_AlphaNumericalEscCharFromTerm(t))
SDF_AlphaNumericalEscChar SDF_AlphaNumericalEscCharFromTerm(ATerm t);
#define SDF_makeTermFromAlphaNumericalEscChar(t) (SDF_AlphaNumericalEscCharToTerm(t))
ATerm SDF_AlphaNumericalEscCharToTerm(SDF_AlphaNumericalEscChar arg);
#define SDF_makeDecimalEscCharFromTerm(t) (SDF_DecimalEscCharFromTerm(t))
SDF_DecimalEscChar SDF_DecimalEscCharFromTerm(ATerm t);
#define SDF_makeTermFromDecimalEscChar(t) (SDF_DecimalEscCharToTerm(t))
ATerm SDF_DecimalEscCharToTerm(SDF_DecimalEscChar arg);
#define SDF_makeEscCharFromTerm(t) (SDF_EscCharFromTerm(t))
SDF_EscChar SDF_EscCharFromTerm(ATerm t);
#define SDF_makeTermFromEscChar(t) (SDF_EscCharToTerm(t))
ATerm SDF_EscCharToTerm(SDF_EscChar arg);
#define SDF_makeLCharFromTerm(t) (SDF_LCharFromTerm(t))
SDF_LChar SDF_LCharFromTerm(ATerm t);
#define SDF_makeTermFromLChar(t) (SDF_LCharToTerm(t))
ATerm SDF_LCharToTerm(SDF_LChar arg);
#define SDF_makeQLiteralFromTerm(t) (SDF_QLiteralFromTerm(t))
SDF_QLiteral SDF_QLiteralFromTerm(ATerm t);
#define SDF_makeTermFromQLiteral(t) (SDF_QLiteralToTerm(t))
ATerm SDF_QLiteralToTerm(SDF_QLiteral arg);
#define SDF_makeUQLiteralFromTerm(t) (SDF_UQLiteralFromTerm(t))
SDF_UQLiteral SDF_UQLiteralFromTerm(ATerm t);
#define SDF_makeTermFromUQLiteral(t) (SDF_UQLiteralToTerm(t))
ATerm SDF_UQLiteralToTerm(SDF_UQLiteral arg);
#define SDF_makeLiteralFromTerm(t) (SDF_LiteralFromTerm(t))
SDF_Literal SDF_LiteralFromTerm(ATerm t);
#define SDF_makeTermFromLiteral(t) (SDF_LiteralToTerm(t))
ATerm SDF_LiteralToTerm(SDF_Literal arg);
#define SDF_makeATermListFromTerm(t) (SDF_ATermListFromTerm(t))
SDF_ATermList SDF_ATermListFromTerm(ATerm t);
#define SDF_makeTermFromATermList(t) (SDF_ATermListToTerm(t))
ATerm SDF_ATermListToTerm(SDF_ATermList arg);
#define SDF_makeATermElemsFromTerm(t) (SDF_ATermElemsFromTerm(t))
SDF_ATermElems SDF_ATermElemsFromTerm(ATerm t);
#define SDF_makeTermFromATermElems(t) (SDF_ATermElemsToTerm(t))
ATerm SDF_ATermElemsToTerm(SDF_ATermElems arg);
#define SDF_makeAConFromTerm(t) (SDF_AConFromTerm(t))
SDF_ACon SDF_AConFromTerm(ATerm t);
#define SDF_makeTermFromACon(t) (SDF_AConToTerm(t))
ATerm SDF_AConToTerm(SDF_ACon arg);
#define SDF_makeAFunFromTerm(t) (SDF_AFunFromTerm(t))
SDF_AFun SDF_AFunFromTerm(ATerm t);
#define SDF_makeTermFromAFun(t) (SDF_AFunToTerm(t))
ATerm SDF_AFunToTerm(SDF_AFun arg);
#define SDF_makeATermFromTerm(t) (SDF_ATermFromTerm(t))
SDF_ATerm SDF_ATermFromTerm(ATerm t);
#define SDF_makeTermFromATerm(t) (SDF_ATermToTerm(t))
ATerm SDF_ATermToTerm(SDF_ATerm arg);
#define SDF_makeATermArgsFromTerm(t) (SDF_ATermArgsFromTerm(t))
SDF_ATermArgs SDF_ATermArgsFromTerm(ATerm t);
#define SDF_makeTermFromATermArgs(t) (SDF_ATermArgsToTerm(t))
ATerm SDF_ATermArgsToTerm(SDF_ATermArgs arg);
#define SDF_makeAnnFromTerm(t) (SDF_AnnFromTerm(t))
SDF_Ann SDF_AnnFromTerm(ATerm t);
#define SDF_makeTermFromAnn(t) (SDF_AnnToTerm(t))
ATerm SDF_AnnToTerm(SDF_Ann arg);
#define SDF_makeATermAnnosFromTerm(t) (SDF_ATermAnnosFromTerm(t))
SDF_ATermAnnos SDF_ATermAnnosFromTerm(ATerm t);
#define SDF_makeTermFromATermAnnos(t) (SDF_ATermAnnosToTerm(t))
ATerm SDF_ATermAnnosToTerm(SDF_ATermAnnos arg);
#define SDF_makeAttributesFromTerm(t) (SDF_AttributesFromTerm(t))
SDF_Attributes SDF_AttributesFromTerm(ATerm t);
#define SDF_makeTermFromAttributes(t) (SDF_AttributesToTerm(t))
ATerm SDF_AttributesToTerm(SDF_Attributes arg);
#define SDF_makeAttributeListFromTerm(t) (SDF_AttributeListFromTerm(t))
SDF_AttributeList SDF_AttributeListFromTerm(ATerm t);
#define SDF_makeTermFromAttributeList(t) (SDF_AttributeListToTerm(t))
ATerm SDF_AttributeListToTerm(SDF_AttributeList arg);
#define SDF_makeProductionsFromTerm(t) (SDF_ProductionsFromTerm(t))
SDF_Productions SDF_ProductionsFromTerm(ATerm t);
#define SDF_makeTermFromProductions(t) (SDF_ProductionsToTerm(t))
ATerm SDF_ProductionsToTerm(SDF_Productions arg);
#define SDF_makeProductionListFromTerm(t) (SDF_ProductionListFromTerm(t))
SDF_ProductionList SDF_ProductionListFromTerm(ATerm t);
#define SDF_makeTermFromProductionList(t) (SDF_ProductionListToTerm(t))
ATerm SDF_ProductionListToTerm(SDF_ProductionList arg);
#define SDF_makeSDFFromTerm(t) (SDF_SDFFromTerm(t))
SDF_SDF SDF_SDFFromTerm(ATerm t);
#define SDF_makeTermFromSDF(t) (SDF_SDFToTerm(t))
ATerm SDF_SDFToTerm(SDF_SDF arg);
#define SDF_makeOptLayoutFromTerm(t) (SDF_OptLayoutFromTerm(t))
SDF_OptLayout SDF_OptLayoutFromTerm(ATerm t);
#define SDF_makeTermFromOptLayout(t) (SDF_OptLayoutToTerm(t))
ATerm SDF_OptLayoutToTerm(SDF_OptLayout arg);
#define SDF_makeStartFromTerm(t) (SDF_StartFromTerm(t))
SDF_Start SDF_StartFromTerm(ATerm t);
#define SDF_makeTermFromStart(t) (SDF_StartToTerm(t))
ATerm SDF_StartToTerm(SDF_Start arg);

/*}}}  */
/*{{{  constructors */

SDF_Grammar SDF_makeGrammarAliases(SDF_OptLayout wsAfterAliases, SDF_Aliases Aliases);
SDF_Grammar SDF_makeGrammarRestrictions(SDF_OptLayout wsAfterRestrictions, SDF_Restrictions Restrictions);
SDF_Grammar SDF_makeGrammarKernelStartSymbols(SDF_OptLayout wsAfterStartSymbols, SDF_Symbols Symbols);
SDF_Grammar SDF_makeGrammarLexicalStartSymbols(SDF_OptLayout wsAfterLexical, SDF_OptLayout wsAfterStartSymbols, SDF_Symbols Symbols);
SDF_Grammar SDF_makeGrammarContextFreeStartSymbols(SDF_OptLayout wsAfterContextFree, SDF_OptLayout wsAfterStartSymbols, SDF_Symbols Symbols);
SDF_Grammar SDF_makeGrammarSorts(SDF_OptLayout wsAfterSorts, SDF_Symbols Symbols);
SDF_Grammar SDF_makeGrammarPriorities(SDF_OptLayout wsAfterPriorities, SDF_Priorities Priorities);
SDF_Grammar SDF_makeGrammarImpSection(SDF_ImpSection ImpSection);
SDF_Grammar SDF_makeGrammarLexicalSyntax(SDF_OptLayout wsAfterLexical, SDF_OptLayout wsAfterSyntax, SDF_Productions Productions);
SDF_Grammar SDF_makeGrammarContextFreeSyntax(SDF_OptLayout wsAfterContextFree, SDF_OptLayout wsAfterSyntax, SDF_Productions Productions);
SDF_Grammar SDF_makeGrammarVariables(SDF_OptLayout wsAfterVariables, SDF_Productions Productions);
SDF_Grammar SDF_makeGrammarLexicalVariables(SDF_OptLayout wsAfterLexical, SDF_OptLayout wsAfterVariables, SDF_Productions Productions);
SDF_Grammar SDF_makeGrammarEmptyGrammar();
SDF_Grammar SDF_makeGrammarConcGrammars(SDF_Grammar left, SDF_OptLayout wsAfterLeft, SDF_Grammar right);
SDF_Grammar SDF_makeGrammarBracket(SDF_OptLayout wsAfterParenOpen, SDF_Grammar Grammar, SDF_OptLayout wsAfterGrammar);
SDF_Grammar SDF_makeGrammarSyntax(SDF_OptLayout wsAfterSyntax, SDF_Productions Productions);
SDF_Grammar SDF_makeGrammarLexicalPriorities(SDF_OptLayout wsAfterLexical, SDF_OptLayout wsAfterPriorities, SDF_Priorities Priorities);
SDF_Grammar SDF_makeGrammarContextFreePriorities(SDF_OptLayout wsAfterContextFree, SDF_OptLayout wsAfterPriorities, SDF_Priorities Priorities);
SDF_Grammar SDF_makeGrammarLexicalRestrictions(SDF_OptLayout wsAfterLexical, SDF_OptLayout wsAfterRestrictions, SDF_Restrictions Restrictions);
SDF_Grammar SDF_makeGrammarContextFreeRestrictions(SDF_OptLayout wsAfterContextFree, SDF_OptLayout wsAfterRestrictions, SDF_Restrictions Restrictions);
SDF_Alias SDF_makeAliasAlias(SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol, SDF_OptLayout wsAfterArrow, SDF_Symbol alias);
SDF_Aliases SDF_makeAliasesDefault(SDF_AliasList list);
SDF_AliasList SDF_makeAliasListEmpty();
SDF_AliasList SDF_makeAliasListSingle(SDF_Alias head);
SDF_AliasList SDF_makeAliasListMany(SDF_Alias head, SDF_OptLayout wsAfterFirst, SDF_AliasList tail);
SDF_Lookahead SDF_makeLookaheadCharClass(SDF_CharClass CharClass);
SDF_Lookahead SDF_makeLookaheadSeq(SDF_CharClass head, SDF_OptLayout wsAfterHead, SDF_OptLayout wsAfterPeriod, SDF_Lookaheads tail);
SDF_Lookaheads SDF_makeLookaheadsSingle(SDF_Lookahead Lookahead);
SDF_Lookaheads SDF_makeLookaheadsAlt(SDF_Lookaheads left, SDF_OptLayout wsAfterLeft, SDF_OptLayout wsAfterBar, SDF_Lookaheads right);
SDF_Lookaheads SDF_makeLookaheadsBracket(SDF_OptLayout wsAfterParenOpen, SDF_Lookaheads Lookaheads, SDF_OptLayout wsAfterLookaheads);
SDF_Lookaheads SDF_makeLookaheadsList(SDF_OptLayout wsAfterBracketOpenBracketOpen, SDF_LookaheadList list, SDF_OptLayout wsAfterList);
SDF_LookaheadList SDF_makeLookaheadListEmpty();
SDF_LookaheadList SDF_makeLookaheadListSingle(SDF_Lookahead head);
SDF_LookaheadList SDF_makeLookaheadListMany(SDF_Lookahead head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_LookaheadList tail);
SDF_Restriction SDF_makeRestrictionFollow(SDF_Symbols Symbols, SDF_OptLayout wsAfterSymbols, SDF_OptLayout wsAfterSlash, SDF_Lookaheads Lookaheads);
SDF_Restrictions SDF_makeRestrictionsDefault(SDF_RestrictionList list);
SDF_RestrictionList SDF_makeRestrictionListEmpty();
SDF_RestrictionList SDF_makeRestrictionListSingle(SDF_Restriction head);
SDF_RestrictionList SDF_makeRestrictionListMany(SDF_Restriction head, SDF_OptLayout wsAfterFirst, SDF_RestrictionList tail);
SDF_Attribute SDF_makeAttributeReject();
SDF_Attribute SDF_makeAttributePrefer();
SDF_Attribute SDF_makeAttributeAvoid();
SDF_Attribute SDF_makeAttributeBracket();
SDF_Attribute SDF_makeAttributeAssoc(SDF_Associativity Associativity);
SDF_Attribute SDF_makeAttributeId(SDF_OptLayout wsAfterId, SDF_OptLayout wsAfterParenOpen, SDF_ModuleName ModuleName, SDF_OptLayout wsAfterModuleName);
SDF_Attribute SDF_makeAttributeTerm(SDF_ATerm aterm);
SDF_Symbol SDF_makeSymbolLabel(SDF_Literal label, SDF_OptLayout wsAfterLabel, SDF_OptLayout wsAfterColon, SDF_Symbol Symbol);
SDF_Symbol SDF_makeSymbolLit(SDF_Literal Literal);
SDF_Symbol SDF_makeSymbolSort(SDF_Sort Sort);
SDF_Symbol SDF_makeSymbolParameterizedSort(SDF_Sort Sort, SDF_OptLayout wsAfterSort, SDF_OptLayout wsAfterBracketOpenBracketOpen, SDF_SymbolParameters parameters, SDF_OptLayout wsAfterParameters);
SDF_Symbol SDF_makeSymbolCharClass(SDF_CharClass CharClass);
SDF_Symbol SDF_makeSymbolLifting(SDF_OptLayout wsAfterLeftQuote, SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol);
SDF_Symbol SDF_makeSymbolEmpty(SDF_OptLayout wsAfterParenOpen);
SDF_Symbol SDF_makeSymbolSeq(SDF_OptLayout wsAfterParenOpen, SDF_Symbol head, SDF_OptLayout wsAfterHead, SDF_SymbolTail tail, SDF_OptLayout wsAfterTail);
SDF_Symbol SDF_makeSymbolOpt(SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol);
SDF_Symbol SDF_makeSymbolIter(SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol);
SDF_Symbol SDF_makeSymbolIterStar(SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol);
SDF_Symbol SDF_makeSymbolIterSep(SDF_OptLayout wsAfterBraceOpen, SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol, SDF_Symbol sep, SDF_OptLayout wsAfterSep, SDF_OptLayout wsAfterBraceClose);
SDF_Symbol SDF_makeSymbolIterStarSep(SDF_OptLayout wsAfterBraceOpen, SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol, SDF_Symbol sep, SDF_OptLayout wsAfterSep, SDF_OptLayout wsAfterBraceClose);
SDF_Symbol SDF_makeSymbolIterN(SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol, SDF_NatCon n, SDF_OptLayout wsAfterN);
SDF_Symbol SDF_makeSymbolIterSepN(SDF_OptLayout wsAfterBraceOpen, SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol, SDF_Symbol sep, SDF_OptLayout wsAfterSep, SDF_OptLayout wsAfterBraceClose, SDF_NatCon n, SDF_OptLayout wsAfterN);
SDF_Symbol SDF_makeSymbolTuple(SDF_OptLayout wsAfterLessThan, SDF_Symbol head, SDF_OptLayout wsAfterHead, SDF_OptLayout wsAfterComma, SDF_SymbolRest rest, SDF_OptLayout wsAfterRest);
SDF_Symbol SDF_makeSymbolPair(SDF_Symbol left, SDF_OptLayout wsAfterLeft, SDF_OptLayout wsAfterHash, SDF_Symbol right);
SDF_Symbol SDF_makeSymbolFunc(SDF_OptLayout wsAfterParenOpen, SDF_Symbols arguments, SDF_OptLayout wsAfterArguments, SDF_OptLayout wsAfterEqualsGreaterThan, SDF_Symbol results, SDF_OptLayout wsAfterResults);
SDF_Symbol SDF_makeSymbolAlt(SDF_Symbol left, SDF_OptLayout wsAfterLeft, SDF_OptLayout wsAfterBar, SDF_Symbol right);
SDF_Symbol SDF_makeSymbolStrategy(SDF_OptLayout wsAfterParenOpen, SDF_Symbol left, SDF_OptLayout wsAfterLeft, SDF_OptLayout wsAfterGreaterThan, SDF_Symbol right, SDF_OptLayout wsAfterRight);
SDF_Symbol SDF_makeSymbolCf(SDF_OptLayout wsAfterLessThan, SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol, SDF_OptLayout wsAfterCF);
SDF_Symbol SDF_makeSymbolLex(SDF_OptLayout wsAfterLessThan, SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol, SDF_OptLayout wsAfterLEX);
SDF_Symbol SDF_makeSymbolVarsym(SDF_OptLayout wsAfterLessThan, SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol, SDF_OptLayout wsAfterVAR);
SDF_Symbol SDF_makeSymbolLayout();
SDF_Symbol SDF_makeSymbolBracket(SDF_OptLayout wsAfterParenOpen, SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol);
SDF_Symbol SDF_makeSymbolStart();
SDF_Symbol SDF_makeSymbolFileStart();
SDF_Production SDF_makeProductionProdFun(SDF_Literal functionSymbol, SDF_OptLayout wsAfterFunctionSymbol, SDF_OptLayout wsAfterParenOpen, SDF_SymbolArguments arguments, SDF_OptLayout wsAfterArguments, SDF_OptLayout wsAfterParenClose, SDF_OptLayout wsAfterGreaterThan, SDF_Symbol result, SDF_OptLayout wsAfterResult, SDF_Attributes Attributes);
SDF_Production SDF_makeProductionProd(SDF_Symbols Symbols, SDF_OptLayout wsAfterSymbols, SDF_OptLayout wsAfterGreaterThan, SDF_Symbol result, SDF_OptLayout wsAfterResult, SDF_Attributes Attributes);
SDF_SymbolArguments SDF_makeSymbolArgumentsEmpty();
SDF_SymbolArguments SDF_makeSymbolArgumentsSingle(SDF_Symbol head);
SDF_SymbolArguments SDF_makeSymbolArgumentsMany(SDF_Symbol head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_SymbolArguments tail);
SDF_Sort SDF_makeSortOneChar(SDF_CHARLIST chars);
SDF_Sort SDF_makeSortMoreChars(SDF_CHARLIST chars);
SDF_SymbolParameters SDF_makeSymbolParametersSingle(SDF_Symbol head);
SDF_SymbolParameters SDF_makeSymbolParametersMany(SDF_Symbol head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_SymbolParameters tail);
SDF_NumChar SDF_makeNumCharDigits(SDF_CHARLIST chars);
SDF_ShortChar SDF_makeShortCharRegular(SDF_CHARLIST chars);
SDF_ShortChar SDF_makeShortCharEscaped(SDF_CHARLIST chars);
SDF_Character SDF_makeCharacterNumeric(SDF_NumChar NumChar);
SDF_Character SDF_makeCharacterShort(SDF_ShortChar ShortChar);
SDF_Character SDF_makeCharacterTop();
SDF_Character SDF_makeCharacterEof();
SDF_Character SDF_makeCharacterBot();
SDF_Character SDF_makeCharacterLabelUnderscoreStart();
SDF_CharRange SDF_makeCharRangeDefault(SDF_Character Character);
SDF_CharRange SDF_makeCharRangeRange(SDF_Character start, SDF_OptLayout wsAfterStart, SDF_OptLayout wsAfter, SDF_Character end);
SDF_CharRanges SDF_makeCharRangesDefault(SDF_CharRange CharRange);
SDF_CharRanges SDF_makeCharRangesConc(SDF_CharRanges left, SDF_OptLayout wsAfterLeft, SDF_CharRanges right);
SDF_CharRanges SDF_makeCharRangesBracket(SDF_OptLayout wsAfterParenOpen, SDF_CharRanges CharRanges, SDF_OptLayout wsAfterCharRanges);
SDF_OptCharRanges SDF_makeOptCharRangesAbsent();
SDF_OptCharRanges SDF_makeOptCharRangesPresent(SDF_CharRanges CharRanges);
SDF_CharClass SDF_makeCharClassSimpleCharclass(SDF_OptLayout wsAfterBracketOpen, SDF_OptCharRanges OptCharRanges, SDF_OptLayout wsAfterOptCharRanges);
SDF_CharClass SDF_makeCharClassComp(SDF_OptLayout wsAfterTilde, SDF_CharClass CharClass);
SDF_CharClass SDF_makeCharClassDiff(SDF_CharClass left, SDF_OptLayout wsAfterLeft, SDF_OptLayout wsAfterSlash, SDF_CharClass right);
SDF_CharClass SDF_makeCharClassIsect(SDF_CharClass left, SDF_OptLayout wsAfterLeft, SDF_OptLayout wsAfterSlashBackslash, SDF_CharClass right);
SDF_CharClass SDF_makeCharClassUnion(SDF_CharClass left, SDF_OptLayout wsAfterLeft, SDF_OptLayout wsAfterBackslashSlash, SDF_CharClass right);
SDF_CharClass SDF_makeCharClassDefault(SDF_OptLayout wsAfterParenOpen, SDF_CharClass CharClass, SDF_OptLayout wsAfterCharClass);
SDF_Associativity SDF_makeAssociativityLeft();
SDF_Associativity SDF_makeAssociativityRight();
SDF_Associativity SDF_makeAssociativityNonAssoc();
SDF_Associativity SDF_makeAssociativityAssoc();
SDF_Group SDF_makeGroupSimpleGroup(SDF_Production Production);
SDF_Group SDF_makeGroupProdsGroup(SDF_OptLayout wsAfterBraceOpen, SDF_Productions Productions, SDF_OptLayout wsAfterProductions);
SDF_Group SDF_makeGroupAssocGroup(SDF_OptLayout wsAfterBraceOpen, SDF_Associativity Associativity, SDF_OptLayout wsAfterAssociativity, SDF_OptLayout wsAfterColon, SDF_Productions Productions, SDF_OptLayout wsAfterProductions);
SDF_Priority SDF_makePriorityChain(SDF_GroupList list);
SDF_Priority SDF_makePriorityAssoc(SDF_Group left, SDF_OptLayout wsAfterLeft, SDF_Associativity Associativity, SDF_OptLayout wsAfterAssociativity, SDF_Group right);
SDF_GroupList SDF_makeGroupListSingle(SDF_Group head);
SDF_GroupList SDF_makeGroupListMany(SDF_Group head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_GroupList tail);
SDF_Priorities SDF_makePrioritiesDefault(SDF_PriorityList list);
SDF_PriorityList SDF_makePriorityListEmpty();
SDF_PriorityList SDF_makePriorityListSingle(SDF_Priority head);
SDF_PriorityList SDF_makePriorityListMany(SDF_Priority head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_PriorityList tail);
SDF_SymbolTail SDF_makeSymbolTailSingle(SDF_Symbol head);
SDF_SymbolTail SDF_makeSymbolTailMany(SDF_Symbol head, SDF_OptLayout wsAfterFirst, SDF_SymbolTail tail);
SDF_SymbolRest SDF_makeSymbolRestSingle(SDF_Symbol head);
SDF_SymbolRest SDF_makeSymbolRestMany(SDF_Symbol head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_SymbolRest tail);
SDF_Renamings SDF_makeRenamingsRenamings(SDF_OptLayout wsAfterBracketOpen, SDF_RenamingList list, SDF_OptLayout wsAfterList);
SDF_RenamingList SDF_makeRenamingListEmpty();
SDF_RenamingList SDF_makeRenamingListSingle(SDF_Renaming head);
SDF_RenamingList SDF_makeRenamingListMany(SDF_Renaming head, SDF_OptLayout wsAfterFirst, SDF_RenamingList tail);
SDF_Renaming SDF_makeRenamingSymbol(SDF_Symbol from, SDF_OptLayout wsAfterFrom, SDF_OptLayout wsAfterEqualsGreaterThan, SDF_Symbol to);
SDF_Renaming SDF_makeRenamingProduction(SDF_Production fromProd, SDF_OptLayout wsAfterFromProd, SDF_OptLayout wsAfterEqualsGreaterThan, SDF_Production toProd);
SDF_ModuleWord SDF_makeModuleWordWord(SDF_CHARLIST chars);
SDF_ModuleId SDF_makeModuleIdWord(SDF_CHARLIST chars);
SDF_ModuleId SDF_makeModuleIdSlashWord(SDF_CHARLIST chars);
SDF_ModuleId SDF_makeModuleIdWordSlashWord(SDF_CHARLIST chars);
SDF_Definition SDF_makeDefinitionDefault(SDF_ModuleList list);
SDF_ModuleList SDF_makeModuleListEmpty();
SDF_ModuleList SDF_makeModuleListSingle(SDF_Module head);
SDF_ModuleList SDF_makeModuleListMany(SDF_Module head, SDF_OptLayout wsAfterFirst, SDF_ModuleList tail);
SDF_Module SDF_makeModuleModule(SDF_OptLayout wsAfterModule, SDF_ModuleName ModuleName, SDF_OptLayout wsAfterModuleName, SDF_ImpSectionList list, SDF_OptLayout wsAfterList, SDF_Sections Sections);
SDF_ImpSectionList SDF_makeImpSectionListEmpty();
SDF_ImpSectionList SDF_makeImpSectionListSingle(SDF_ImpSection head);
SDF_ImpSectionList SDF_makeImpSectionListMany(SDF_ImpSection head, SDF_OptLayout wsAfterFirst, SDF_ImpSectionList tail);
SDF_Section SDF_makeSectionExports(SDF_OptLayout wsAfterExports, SDF_Grammar Grammar);
SDF_Section SDF_makeSectionHiddens(SDF_OptLayout wsAfterHiddens, SDF_Grammar Grammar);
SDF_Sections SDF_makeSectionsDefault(SDF_SectionList list);
SDF_SectionList SDF_makeSectionListEmpty();
SDF_SectionList SDF_makeSectionListSingle(SDF_Section head);
SDF_SectionList SDF_makeSectionListMany(SDF_Section head, SDF_OptLayout wsAfterFirst, SDF_SectionList tail);
SDF_ModuleName SDF_makeModuleNameUnparameterized(SDF_ModuleId ModuleId);
SDF_ModuleName SDF_makeModuleNameParameterized(SDF_ModuleId ModuleId, SDF_OptLayout wsAfterModuleId, SDF_OptLayout wsAfterBracketOpen, SDF_Symbols params, SDF_OptLayout wsAfterParams);
SDF_ImpSection SDF_makeImpSectionImports(SDF_OptLayout wsAfterImports, SDF_Imports list);
SDF_Imports SDF_makeImportsDefault(SDF_ImportList list);
SDF_ImportList SDF_makeImportListEmpty();
SDF_ImportList SDF_makeImportListSingle(SDF_Import head);
SDF_ImportList SDF_makeImportListMany(SDF_Import head, SDF_OptLayout wsAfterFirst, SDF_ImportList tail);
SDF_Import SDF_makeImportModule(SDF_ModuleName ModuleName);
SDF_Import SDF_makeImportRenamedModule(SDF_ModuleName ModuleName, SDF_OptLayout wsAfterModuleName, SDF_Renamings Renamings);
SDF_Import SDF_makeImportBracket(SDF_OptLayout wsAfterParenOpen, SDF_Import Import, SDF_OptLayout wsAfterImport);
SDF_Symbols SDF_makeSymbolsDefault(SDF_SymbolList list);
SDF_SymbolList SDF_makeSymbolListEmpty();
SDF_SymbolList SDF_makeSymbolListSingle(SDF_Symbol head);
SDF_SymbolList SDF_makeSymbolListMany(SDF_Symbol head, SDF_OptLayout wsAfterFirst, SDF_SymbolList tail);
SDF_OptExp SDF_makeOptExpPresent(SDF_OptLayout wsAfterE, SDF_IntCon IntCon);
SDF_OptExp SDF_makeOptExpAbsent();
SDF_RealCon SDF_makeRealConRealCon(SDF_IntCon IntCon, SDF_OptLayout wsAfterIntCon, SDF_OptLayout wsAfterPeriod, SDF_NatCon NatCon, SDF_OptLayout wsAfterNatCon, SDF_OptExp OptExp);
SDF_NatCon SDF_makeNatConDigits(SDF_CHARLIST chars);
SDF_IntCon SDF_makeIntConNatural(SDF_NatCon NatCon);
SDF_IntCon SDF_makeIntConPositive(SDF_OptLayout wsAfterPos, SDF_NatCon NatCon);
SDF_IntCon SDF_makeIntConNegative(SDF_OptLayout wsAfterNeg, SDF_NatCon NatCon);
SDF_AlphaNumericalEscChar SDF_makeAlphaNumericalEscCharDefault(SDF_CHARLIST chars);
SDF_DecimalEscChar SDF_makeDecimalEscCharDec0Underscore199(SDF_CHARLIST chars);
SDF_DecimalEscChar SDF_makeDecimalEscCharDec200Underscore249(SDF_CHARLIST chars);
SDF_DecimalEscChar SDF_makeDecimalEscCharDec250Underscore255(SDF_CHARLIST chars);
SDF_EscChar SDF_makeEscCharAlphaNumeric(SDF_CHARLIST chars);
SDF_EscChar SDF_makeEscCharDecimal(SDF_CHARLIST chars);
SDF_LChar SDF_makeLCharNormal(SDF_CHARLIST chars);
SDF_LChar SDF_makeLCharEscaped(SDF_CHARLIST chars);
SDF_QLiteral SDF_makeQLiteralQuoted(SDF_CHARLIST chars);
SDF_UQLiteral SDF_makeUQLiteralOneChar(SDF_CHARLIST chars);
SDF_UQLiteral SDF_makeUQLiteralMoreChars(SDF_CHARLIST chars);
SDF_Literal SDF_makeLiteralQlit(SDF_QLiteral QLiteral);
SDF_Literal SDF_makeLiteralUqlit(SDF_UQLiteral UQLiteral);
SDF_ATermList SDF_makeATermListNotEmpty(SDF_OptLayout wsAfterBracketOpen, SDF_ATermElems elems, SDF_OptLayout wsAfterElems);
SDF_ATermElems SDF_makeATermElemsEmpty();
SDF_ATermElems SDF_makeATermElemsSingle(SDF_ATerm head);
SDF_ATermElems SDF_makeATermElemsMany(SDF_ATerm head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_ATermElems tail);
SDF_ACon SDF_makeAConInt(SDF_IntCon IntCon);
SDF_ACon SDF_makeAConReal(SDF_RealCon RealCon);
SDF_AFun SDF_makeAFunDefault(SDF_Literal Literal);
SDF_ATerm SDF_makeATermConstant(SDF_ACon ACon);
SDF_ATerm SDF_makeATermList(SDF_ATermList list);
SDF_ATerm SDF_makeATermFun(SDF_AFun fun);
SDF_ATerm SDF_makeATermAppl(SDF_AFun fun, SDF_OptLayout wsAfterFun, SDF_OptLayout wsAfterParenOpen, SDF_ATermArgs args, SDF_OptLayout wsAfterArgs);
SDF_ATerm SDF_makeATermAnnotatedConstant(SDF_ACon ACon, SDF_OptLayout wsAfterACon, SDF_Ann Ann);
SDF_ATerm SDF_makeATermAnnotatedList(SDF_ATermList list, SDF_OptLayout wsAfterList, SDF_Ann Ann);
SDF_ATerm SDF_makeATermAnnotatedFun(SDF_AFun fun, SDF_OptLayout wsAfterFun, SDF_Ann Ann);
SDF_ATerm SDF_makeATermAnnotatedAppl(SDF_AFun fun, SDF_OptLayout wsAfterFun, SDF_OptLayout wsAfterParenOpen, SDF_ATermArgs args, SDF_OptLayout wsAfterArgs, SDF_OptLayout wsAfterParenClose, SDF_Ann Ann);
SDF_ATermArgs SDF_makeATermArgsSingle(SDF_ATerm head);
SDF_ATermArgs SDF_makeATermArgsMany(SDF_ATerm head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_ATermArgs tail);
SDF_Ann SDF_makeAnnAnnotation(SDF_OptLayout wsAfterBraceOpen, SDF_ATermAnnos annos, SDF_OptLayout wsAfterAnnos);
SDF_ATermAnnos SDF_makeATermAnnosSingle(SDF_ATerm head);
SDF_ATermAnnos SDF_makeATermAnnosMany(SDF_ATerm head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_ATermAnnos tail);
SDF_Attributes SDF_makeAttributesAttrs(SDF_OptLayout wsAfterBraceOpen, SDF_AttributeList list, SDF_OptLayout wsAfterList);
SDF_Attributes SDF_makeAttributesNoAttrs();
SDF_AttributeList SDF_makeAttributeListEmpty();
SDF_AttributeList SDF_makeAttributeListSingle(SDF_Attribute head);
SDF_AttributeList SDF_makeAttributeListMany(SDF_Attribute head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_AttributeList tail);
SDF_Productions SDF_makeProductionsDefault(SDF_ProductionList list);
SDF_ProductionList SDF_makeProductionListEmpty();
SDF_ProductionList SDF_makeProductionListSingle(SDF_Production head);
SDF_ProductionList SDF_makeProductionListMany(SDF_Production head, SDF_OptLayout wsAfterFirst, SDF_ProductionList tail);
SDF_SDF SDF_makeSDFDefinition(SDF_OptLayout wsAfterDefinition, SDF_Definition Definition);
SDF_OptLayout SDF_makeOptLayoutAbsent();
SDF_OptLayout SDF_makeOptLayoutPresent(SDF_CHARLIST chars);
SDF_Start SDF_makeStartSDF(SDF_OptLayout wsBefore, SDF_SDF topSDF, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartProductions(SDF_OptLayout wsBefore, SDF_Productions topProductions, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartProduction(SDF_OptLayout wsBefore, SDF_Production topProduction, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartAttributes(SDF_OptLayout wsBefore, SDF_Attributes topAttributes, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartAttribute(SDF_OptLayout wsBefore, SDF_Attribute topAttribute, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartAnn(SDF_OptLayout wsBefore, SDF_Ann topAnn, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartATerm(SDF_OptLayout wsBefore, SDF_ATerm topATerm, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartAFun(SDF_OptLayout wsBefore, SDF_AFun topAFun, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartACon(SDF_OptLayout wsBefore, SDF_ACon topACon, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartATermList(SDF_OptLayout wsBefore, SDF_ATermList topATermList, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartQLiteral(SDF_OptLayout wsBefore, SDF_QLiteral topQLiteral, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartUQLiteral(SDF_OptLayout wsBefore, SDF_UQLiteral topUQLiteral, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartLiteral(SDF_OptLayout wsBefore, SDF_Literal topLiteral, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartIntCon(SDF_OptLayout wsBefore, SDF_IntCon topIntCon, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartNatCon(SDF_OptLayout wsBefore, SDF_NatCon topNatCon, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartRealCon(SDF_OptLayout wsBefore, SDF_RealCon topRealCon, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartOptExp(SDF_OptLayout wsBefore, SDF_OptExp topOptExp, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartSymbols(SDF_OptLayout wsBefore, SDF_Symbols topSymbols, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartSymbol(SDF_OptLayout wsBefore, SDF_Symbol topSymbol, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartGrammar(SDF_OptLayout wsBefore, SDF_Grammar topGrammar, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartImpSection(SDF_OptLayout wsBefore, SDF_ImpSection topImpSection, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartDefinition(SDF_OptLayout wsBefore, SDF_Definition topDefinition, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartModule(SDF_OptLayout wsBefore, SDF_Module topModule, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartSections(SDF_OptLayout wsBefore, SDF_Sections topSections, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartSection(SDF_OptLayout wsBefore, SDF_Section topSection, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartImports(SDF_OptLayout wsBefore, SDF_Imports topImports, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartImport(SDF_OptLayout wsBefore, SDF_Import topImport, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartModuleName(SDF_OptLayout wsBefore, SDF_ModuleName topModuleName, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartModuleId(SDF_OptLayout wsBefore, SDF_ModuleId topModuleId, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartRenamings(SDF_OptLayout wsBefore, SDF_Renamings topRenamings, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartRenaming(SDF_OptLayout wsBefore, SDF_Renaming topRenaming, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartPriorities(SDF_OptLayout wsBefore, SDF_Priorities topPriorities, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartPriority(SDF_OptLayout wsBefore, SDF_Priority topPriority, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartGroup(SDF_OptLayout wsBefore, SDF_Group topGroup, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartAssociativity(SDF_OptLayout wsBefore, SDF_Associativity topAssociativity, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartCharClass(SDF_OptLayout wsBefore, SDF_CharClass topCharClass, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartShortChar(SDF_OptLayout wsBefore, SDF_ShortChar topShortChar, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartNumChar(SDF_OptLayout wsBefore, SDF_NumChar topNumChar, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartCharacter(SDF_OptLayout wsBefore, SDF_Character topCharacter, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartSort(SDF_OptLayout wsBefore, SDF_Sort topSort, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartRestrictions(SDF_OptLayout wsBefore, SDF_Restrictions topRestrictions, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartRestriction(SDF_OptLayout wsBefore, SDF_Restriction topRestriction, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartLookaheads(SDF_OptLayout wsBefore, SDF_Lookaheads topLookaheads, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartLookahead(SDF_OptLayout wsBefore, SDF_Lookahead topLookahead, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartAliases(SDF_OptLayout wsBefore, SDF_Aliases topAliases, SDF_OptLayout wsAfter, int ambCnt);
SDF_Start SDF_makeStartAlias(SDF_OptLayout wsBefore, SDF_Alias topAlias, SDF_OptLayout wsAfter, int ambCnt);

/*}}}  */
/*{{{  equality functions */

ATbool SDF_isEqualGrammar(SDF_Grammar arg0, SDF_Grammar arg1);
ATbool SDF_isEqualAlias(SDF_Alias arg0, SDF_Alias arg1);
ATbool SDF_isEqualAliases(SDF_Aliases arg0, SDF_Aliases arg1);
ATbool SDF_isEqualAliasList(SDF_AliasList arg0, SDF_AliasList arg1);
ATbool SDF_isEqualLookahead(SDF_Lookahead arg0, SDF_Lookahead arg1);
ATbool SDF_isEqualLookaheads(SDF_Lookaheads arg0, SDF_Lookaheads arg1);
ATbool SDF_isEqualLookaheadList(SDF_LookaheadList arg0, SDF_LookaheadList arg1);
ATbool SDF_isEqualRestriction(SDF_Restriction arg0, SDF_Restriction arg1);
ATbool SDF_isEqualRestrictions(SDF_Restrictions arg0, SDF_Restrictions arg1);
ATbool SDF_isEqualRestrictionList(SDF_RestrictionList arg0, SDF_RestrictionList arg1);
ATbool SDF_isEqualAttribute(SDF_Attribute arg0, SDF_Attribute arg1);
ATbool SDF_isEqualSymbol(SDF_Symbol arg0, SDF_Symbol arg1);
ATbool SDF_isEqualProduction(SDF_Production arg0, SDF_Production arg1);
ATbool SDF_isEqualSymbolArguments(SDF_SymbolArguments arg0, SDF_SymbolArguments arg1);
ATbool SDF_isEqualSort(SDF_Sort arg0, SDF_Sort arg1);
ATbool SDF_isEqualSymbolParameters(SDF_SymbolParameters arg0, SDF_SymbolParameters arg1);
ATbool SDF_isEqualNumChar(SDF_NumChar arg0, SDF_NumChar arg1);
ATbool SDF_isEqualShortChar(SDF_ShortChar arg0, SDF_ShortChar arg1);
ATbool SDF_isEqualCharacter(SDF_Character arg0, SDF_Character arg1);
ATbool SDF_isEqualCharRange(SDF_CharRange arg0, SDF_CharRange arg1);
ATbool SDF_isEqualCharRanges(SDF_CharRanges arg0, SDF_CharRanges arg1);
ATbool SDF_isEqualOptCharRanges(SDF_OptCharRanges arg0, SDF_OptCharRanges arg1);
ATbool SDF_isEqualCharClass(SDF_CharClass arg0, SDF_CharClass arg1);
ATbool SDF_isEqualAssociativity(SDF_Associativity arg0, SDF_Associativity arg1);
ATbool SDF_isEqualGroup(SDF_Group arg0, SDF_Group arg1);
ATbool SDF_isEqualPriority(SDF_Priority arg0, SDF_Priority arg1);
ATbool SDF_isEqualGroupList(SDF_GroupList arg0, SDF_GroupList arg1);
ATbool SDF_isEqualPriorities(SDF_Priorities arg0, SDF_Priorities arg1);
ATbool SDF_isEqualPriorityList(SDF_PriorityList arg0, SDF_PriorityList arg1);
ATbool SDF_isEqualSymbolTail(SDF_SymbolTail arg0, SDF_SymbolTail arg1);
ATbool SDF_isEqualSymbolRest(SDF_SymbolRest arg0, SDF_SymbolRest arg1);
ATbool SDF_isEqualRenamings(SDF_Renamings arg0, SDF_Renamings arg1);
ATbool SDF_isEqualRenamingList(SDF_RenamingList arg0, SDF_RenamingList arg1);
ATbool SDF_isEqualRenaming(SDF_Renaming arg0, SDF_Renaming arg1);
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
ATbool SDF_isEqualImpSection(SDF_ImpSection arg0, SDF_ImpSection arg1);
ATbool SDF_isEqualImports(SDF_Imports arg0, SDF_Imports arg1);
ATbool SDF_isEqualImportList(SDF_ImportList arg0, SDF_ImportList arg1);
ATbool SDF_isEqualImport(SDF_Import arg0, SDF_Import arg1);
ATbool SDF_isEqualSymbols(SDF_Symbols arg0, SDF_Symbols arg1);
ATbool SDF_isEqualSymbolList(SDF_SymbolList arg0, SDF_SymbolList arg1);
ATbool SDF_isEqualOptExp(SDF_OptExp arg0, SDF_OptExp arg1);
ATbool SDF_isEqualRealCon(SDF_RealCon arg0, SDF_RealCon arg1);
ATbool SDF_isEqualNatCon(SDF_NatCon arg0, SDF_NatCon arg1);
ATbool SDF_isEqualIntCon(SDF_IntCon arg0, SDF_IntCon arg1);
ATbool SDF_isEqualAlphaNumericalEscChar(SDF_AlphaNumericalEscChar arg0, SDF_AlphaNumericalEscChar arg1);
ATbool SDF_isEqualDecimalEscChar(SDF_DecimalEscChar arg0, SDF_DecimalEscChar arg1);
ATbool SDF_isEqualEscChar(SDF_EscChar arg0, SDF_EscChar arg1);
ATbool SDF_isEqualLChar(SDF_LChar arg0, SDF_LChar arg1);
ATbool SDF_isEqualQLiteral(SDF_QLiteral arg0, SDF_QLiteral arg1);
ATbool SDF_isEqualUQLiteral(SDF_UQLiteral arg0, SDF_UQLiteral arg1);
ATbool SDF_isEqualLiteral(SDF_Literal arg0, SDF_Literal arg1);
ATbool SDF_isEqualATermList(SDF_ATermList arg0, SDF_ATermList arg1);
ATbool SDF_isEqualATermElems(SDF_ATermElems arg0, SDF_ATermElems arg1);
ATbool SDF_isEqualACon(SDF_ACon arg0, SDF_ACon arg1);
ATbool SDF_isEqualAFun(SDF_AFun arg0, SDF_AFun arg1);
ATbool SDF_isEqualATerm(SDF_ATerm arg0, SDF_ATerm arg1);
ATbool SDF_isEqualATermArgs(SDF_ATermArgs arg0, SDF_ATermArgs arg1);
ATbool SDF_isEqualAnn(SDF_Ann arg0, SDF_Ann arg1);
ATbool SDF_isEqualATermAnnos(SDF_ATermAnnos arg0, SDF_ATermAnnos arg1);
ATbool SDF_isEqualAttributes(SDF_Attributes arg0, SDF_Attributes arg1);
ATbool SDF_isEqualAttributeList(SDF_AttributeList arg0, SDF_AttributeList arg1);
ATbool SDF_isEqualProductions(SDF_Productions arg0, SDF_Productions arg1);
ATbool SDF_isEqualProductionList(SDF_ProductionList arg0, SDF_ProductionList arg1);
ATbool SDF_isEqualSDF(SDF_SDF arg0, SDF_SDF arg1);
ATbool SDF_isEqualOptLayout(SDF_OptLayout arg0, SDF_OptLayout arg1);
ATbool SDF_isEqualStart(SDF_Start arg0, SDF_Start arg1);

/*}}}  */
/*{{{  SDF_Grammar accessors */

ATbool SDF_isValidGrammar(SDF_Grammar arg);
inline ATbool SDF_isGrammarAliases(SDF_Grammar arg);
inline ATbool SDF_isGrammarRestrictions(SDF_Grammar arg);
inline ATbool SDF_isGrammarKernelStartSymbols(SDF_Grammar arg);
inline ATbool SDF_isGrammarLexicalStartSymbols(SDF_Grammar arg);
inline ATbool SDF_isGrammarContextFreeStartSymbols(SDF_Grammar arg);
inline ATbool SDF_isGrammarSorts(SDF_Grammar arg);
inline ATbool SDF_isGrammarPriorities(SDF_Grammar arg);
inline ATbool SDF_isGrammarImpSection(SDF_Grammar arg);
inline ATbool SDF_isGrammarLexicalSyntax(SDF_Grammar arg);
inline ATbool SDF_isGrammarContextFreeSyntax(SDF_Grammar arg);
inline ATbool SDF_isGrammarVariables(SDF_Grammar arg);
inline ATbool SDF_isGrammarLexicalVariables(SDF_Grammar arg);
inline ATbool SDF_isGrammarEmptyGrammar(SDF_Grammar arg);
inline ATbool SDF_isGrammarConcGrammars(SDF_Grammar arg);
inline ATbool SDF_isGrammarBracket(SDF_Grammar arg);
inline ATbool SDF_isGrammarSyntax(SDF_Grammar arg);
inline ATbool SDF_isGrammarLexicalPriorities(SDF_Grammar arg);
inline ATbool SDF_isGrammarContextFreePriorities(SDF_Grammar arg);
inline ATbool SDF_isGrammarLexicalRestrictions(SDF_Grammar arg);
inline ATbool SDF_isGrammarContextFreeRestrictions(SDF_Grammar arg);
ATbool SDF_hasGrammarWsAfterAliases(SDF_Grammar arg);
SDF_OptLayout SDF_getGrammarWsAfterAliases(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterAliases(SDF_Grammar arg, SDF_OptLayout wsAfterAliases);
ATbool SDF_hasGrammarAliases(SDF_Grammar arg);
SDF_Aliases SDF_getGrammarAliases(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarAliases(SDF_Grammar arg, SDF_Aliases Aliases);
ATbool SDF_hasGrammarWsAfterRestrictions(SDF_Grammar arg);
SDF_OptLayout SDF_getGrammarWsAfterRestrictions(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterRestrictions(SDF_Grammar arg, SDF_OptLayout wsAfterRestrictions);
ATbool SDF_hasGrammarRestrictions(SDF_Grammar arg);
SDF_Restrictions SDF_getGrammarRestrictions(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarRestrictions(SDF_Grammar arg, SDF_Restrictions Restrictions);
ATbool SDF_hasGrammarWsAfterStartSymbols(SDF_Grammar arg);
SDF_OptLayout SDF_getGrammarWsAfterStartSymbols(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterStartSymbols(SDF_Grammar arg, SDF_OptLayout wsAfterStartSymbols);
ATbool SDF_hasGrammarSymbols(SDF_Grammar arg);
SDF_Symbols SDF_getGrammarSymbols(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarSymbols(SDF_Grammar arg, SDF_Symbols Symbols);
ATbool SDF_hasGrammarWsAfterLexical(SDF_Grammar arg);
SDF_OptLayout SDF_getGrammarWsAfterLexical(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterLexical(SDF_Grammar arg, SDF_OptLayout wsAfterLexical);
ATbool SDF_hasGrammarWsAfterContextFree(SDF_Grammar arg);
SDF_OptLayout SDF_getGrammarWsAfterContextFree(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterContextFree(SDF_Grammar arg, SDF_OptLayout wsAfterContextFree);
ATbool SDF_hasGrammarWsAfterSorts(SDF_Grammar arg);
SDF_OptLayout SDF_getGrammarWsAfterSorts(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterSorts(SDF_Grammar arg, SDF_OptLayout wsAfterSorts);
ATbool SDF_hasGrammarWsAfterPriorities(SDF_Grammar arg);
SDF_OptLayout SDF_getGrammarWsAfterPriorities(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterPriorities(SDF_Grammar arg, SDF_OptLayout wsAfterPriorities);
ATbool SDF_hasGrammarPriorities(SDF_Grammar arg);
SDF_Priorities SDF_getGrammarPriorities(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarPriorities(SDF_Grammar arg, SDF_Priorities Priorities);
ATbool SDF_hasGrammarImpSection(SDF_Grammar arg);
SDF_ImpSection SDF_getGrammarImpSection(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarImpSection(SDF_Grammar arg, SDF_ImpSection ImpSection);
ATbool SDF_hasGrammarWsAfterSyntax(SDF_Grammar arg);
SDF_OptLayout SDF_getGrammarWsAfterSyntax(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterSyntax(SDF_Grammar arg, SDF_OptLayout wsAfterSyntax);
ATbool SDF_hasGrammarProductions(SDF_Grammar arg);
SDF_Productions SDF_getGrammarProductions(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarProductions(SDF_Grammar arg, SDF_Productions Productions);
ATbool SDF_hasGrammarWsAfterVariables(SDF_Grammar arg);
SDF_OptLayout SDF_getGrammarWsAfterVariables(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterVariables(SDF_Grammar arg, SDF_OptLayout wsAfterVariables);
ATbool SDF_hasGrammarLeft(SDF_Grammar arg);
SDF_Grammar SDF_getGrammarLeft(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarLeft(SDF_Grammar arg, SDF_Grammar left);
ATbool SDF_hasGrammarWsAfterLeft(SDF_Grammar arg);
SDF_OptLayout SDF_getGrammarWsAfterLeft(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterLeft(SDF_Grammar arg, SDF_OptLayout wsAfterLeft);
ATbool SDF_hasGrammarRight(SDF_Grammar arg);
SDF_Grammar SDF_getGrammarRight(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarRight(SDF_Grammar arg, SDF_Grammar right);
ATbool SDF_hasGrammarWsAfterParenOpen(SDF_Grammar arg);
SDF_OptLayout SDF_getGrammarWsAfterParenOpen(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterParenOpen(SDF_Grammar arg, SDF_OptLayout wsAfterParenOpen);
ATbool SDF_hasGrammarGrammar(SDF_Grammar arg);
SDF_Grammar SDF_getGrammarGrammar(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarGrammar(SDF_Grammar arg, SDF_Grammar Grammar);
ATbool SDF_hasGrammarWsAfterGrammar(SDF_Grammar arg);
SDF_OptLayout SDF_getGrammarWsAfterGrammar(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterGrammar(SDF_Grammar arg, SDF_OptLayout wsAfterGrammar);

/*}}}  */
/*{{{  SDF_Alias accessors */

ATbool SDF_isValidAlias(SDF_Alias arg);
inline ATbool SDF_isAliasAlias(SDF_Alias arg);
ATbool SDF_hasAliasSymbol(SDF_Alias arg);
SDF_Symbol SDF_getAliasSymbol(SDF_Alias arg);
SDF_Alias SDF_setAliasSymbol(SDF_Alias arg, SDF_Symbol Symbol);
ATbool SDF_hasAliasWsAfterSymbol(SDF_Alias arg);
SDF_OptLayout SDF_getAliasWsAfterSymbol(SDF_Alias arg);
SDF_Alias SDF_setAliasWsAfterSymbol(SDF_Alias arg, SDF_OptLayout wsAfterSymbol);
ATbool SDF_hasAliasWsAfterArrow(SDF_Alias arg);
SDF_OptLayout SDF_getAliasWsAfterArrow(SDF_Alias arg);
SDF_Alias SDF_setAliasWsAfterArrow(SDF_Alias arg, SDF_OptLayout wsAfterArrow);
ATbool SDF_hasAliasAlias(SDF_Alias arg);
SDF_Symbol SDF_getAliasAlias(SDF_Alias arg);
SDF_Alias SDF_setAliasAlias(SDF_Alias arg, SDF_Symbol alias);

/*}}}  */
/*{{{  SDF_Aliases accessors */

ATbool SDF_isValidAliases(SDF_Aliases arg);
inline ATbool SDF_isAliasesDefault(SDF_Aliases arg);
ATbool SDF_hasAliasesList(SDF_Aliases arg);
SDF_AliasList SDF_getAliasesList(SDF_Aliases arg);
SDF_Aliases SDF_setAliasesList(SDF_Aliases arg, SDF_AliasList list);

/*}}}  */
/*{{{  SDF_AliasList accessors */

ATbool SDF_isValidAliasList(SDF_AliasList arg);
inline ATbool SDF_isAliasListEmpty(SDF_AliasList arg);
inline ATbool SDF_isAliasListSingle(SDF_AliasList arg);
inline ATbool SDF_isAliasListMany(SDF_AliasList arg);
ATbool SDF_hasAliasListHead(SDF_AliasList arg);
SDF_Alias SDF_getAliasListHead(SDF_AliasList arg);
SDF_AliasList SDF_setAliasListHead(SDF_AliasList arg, SDF_Alias head);
ATbool SDF_hasAliasListWsAfterFirst(SDF_AliasList arg);
SDF_OptLayout SDF_getAliasListWsAfterFirst(SDF_AliasList arg);
SDF_AliasList SDF_setAliasListWsAfterFirst(SDF_AliasList arg, SDF_OptLayout wsAfterFirst);
ATbool SDF_hasAliasListTail(SDF_AliasList arg);
SDF_AliasList SDF_getAliasListTail(SDF_AliasList arg);
SDF_AliasList SDF_setAliasListTail(SDF_AliasList arg, SDF_AliasList tail);

/*}}}  */
/*{{{  SDF_Lookahead accessors */

ATbool SDF_isValidLookahead(SDF_Lookahead arg);
inline ATbool SDF_isLookaheadCharClass(SDF_Lookahead arg);
inline ATbool SDF_isLookaheadSeq(SDF_Lookahead arg);
ATbool SDF_hasLookaheadCharClass(SDF_Lookahead arg);
SDF_CharClass SDF_getLookaheadCharClass(SDF_Lookahead arg);
SDF_Lookahead SDF_setLookaheadCharClass(SDF_Lookahead arg, SDF_CharClass CharClass);
ATbool SDF_hasLookaheadHead(SDF_Lookahead arg);
SDF_CharClass SDF_getLookaheadHead(SDF_Lookahead arg);
SDF_Lookahead SDF_setLookaheadHead(SDF_Lookahead arg, SDF_CharClass head);
ATbool SDF_hasLookaheadWsAfterHead(SDF_Lookahead arg);
SDF_OptLayout SDF_getLookaheadWsAfterHead(SDF_Lookahead arg);
SDF_Lookahead SDF_setLookaheadWsAfterHead(SDF_Lookahead arg, SDF_OptLayout wsAfterHead);
ATbool SDF_hasLookaheadWsAfterPeriod(SDF_Lookahead arg);
SDF_OptLayout SDF_getLookaheadWsAfterPeriod(SDF_Lookahead arg);
SDF_Lookahead SDF_setLookaheadWsAfterPeriod(SDF_Lookahead arg, SDF_OptLayout wsAfterPeriod);
ATbool SDF_hasLookaheadTail(SDF_Lookahead arg);
SDF_Lookaheads SDF_getLookaheadTail(SDF_Lookahead arg);
SDF_Lookahead SDF_setLookaheadTail(SDF_Lookahead arg, SDF_Lookaheads tail);

/*}}}  */
/*{{{  SDF_Lookaheads accessors */

ATbool SDF_isValidLookaheads(SDF_Lookaheads arg);
inline ATbool SDF_isLookaheadsSingle(SDF_Lookaheads arg);
inline ATbool SDF_isLookaheadsAlt(SDF_Lookaheads arg);
inline ATbool SDF_isLookaheadsBracket(SDF_Lookaheads arg);
inline ATbool SDF_isLookaheadsList(SDF_Lookaheads arg);
ATbool SDF_hasLookaheadsLookahead(SDF_Lookaheads arg);
SDF_Lookahead SDF_getLookaheadsLookahead(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsLookahead(SDF_Lookaheads arg, SDF_Lookahead Lookahead);
ATbool SDF_hasLookaheadsLeft(SDF_Lookaheads arg);
SDF_Lookaheads SDF_getLookaheadsLeft(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsLeft(SDF_Lookaheads arg, SDF_Lookaheads left);
ATbool SDF_hasLookaheadsWsAfterLeft(SDF_Lookaheads arg);
SDF_OptLayout SDF_getLookaheadsWsAfterLeft(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsWsAfterLeft(SDF_Lookaheads arg, SDF_OptLayout wsAfterLeft);
ATbool SDF_hasLookaheadsWsAfterBar(SDF_Lookaheads arg);
SDF_OptLayout SDF_getLookaheadsWsAfterBar(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsWsAfterBar(SDF_Lookaheads arg, SDF_OptLayout wsAfterBar);
ATbool SDF_hasLookaheadsRight(SDF_Lookaheads arg);
SDF_Lookaheads SDF_getLookaheadsRight(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsRight(SDF_Lookaheads arg, SDF_Lookaheads right);
ATbool SDF_hasLookaheadsWsAfterParenOpen(SDF_Lookaheads arg);
SDF_OptLayout SDF_getLookaheadsWsAfterParenOpen(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsWsAfterParenOpen(SDF_Lookaheads arg, SDF_OptLayout wsAfterParenOpen);
ATbool SDF_hasLookaheadsLookaheads(SDF_Lookaheads arg);
SDF_Lookaheads SDF_getLookaheadsLookaheads(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsLookaheads(SDF_Lookaheads arg, SDF_Lookaheads Lookaheads);
ATbool SDF_hasLookaheadsWsAfterLookaheads(SDF_Lookaheads arg);
SDF_OptLayout SDF_getLookaheadsWsAfterLookaheads(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsWsAfterLookaheads(SDF_Lookaheads arg, SDF_OptLayout wsAfterLookaheads);
ATbool SDF_hasLookaheadsWsAfterBracketOpenBracketOpen(SDF_Lookaheads arg);
SDF_OptLayout SDF_getLookaheadsWsAfterBracketOpenBracketOpen(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsWsAfterBracketOpenBracketOpen(SDF_Lookaheads arg, SDF_OptLayout wsAfterBracketOpenBracketOpen);
ATbool SDF_hasLookaheadsList(SDF_Lookaheads arg);
SDF_LookaheadList SDF_getLookaheadsList(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsList(SDF_Lookaheads arg, SDF_LookaheadList list);
ATbool SDF_hasLookaheadsWsAfterList(SDF_Lookaheads arg);
SDF_OptLayout SDF_getLookaheadsWsAfterList(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsWsAfterList(SDF_Lookaheads arg, SDF_OptLayout wsAfterList);

/*}}}  */
/*{{{  SDF_LookaheadList accessors */

ATbool SDF_isValidLookaheadList(SDF_LookaheadList arg);
inline ATbool SDF_isLookaheadListEmpty(SDF_LookaheadList arg);
inline ATbool SDF_isLookaheadListSingle(SDF_LookaheadList arg);
inline ATbool SDF_isLookaheadListMany(SDF_LookaheadList arg);
ATbool SDF_hasLookaheadListHead(SDF_LookaheadList arg);
SDF_Lookahead SDF_getLookaheadListHead(SDF_LookaheadList arg);
SDF_LookaheadList SDF_setLookaheadListHead(SDF_LookaheadList arg, SDF_Lookahead head);
ATbool SDF_hasLookaheadListWsAfterFirst(SDF_LookaheadList arg);
SDF_OptLayout SDF_getLookaheadListWsAfterFirst(SDF_LookaheadList arg);
SDF_LookaheadList SDF_setLookaheadListWsAfterFirst(SDF_LookaheadList arg, SDF_OptLayout wsAfterFirst);
ATbool SDF_hasLookaheadListSep(SDF_LookaheadList arg);
char * SDF_getLookaheadListSep(SDF_LookaheadList arg);
SDF_LookaheadList SDF_setLookaheadListSep(SDF_LookaheadList arg, char * sep);
ATbool SDF_hasLookaheadListWsAfterSep(SDF_LookaheadList arg);
SDF_OptLayout SDF_getLookaheadListWsAfterSep(SDF_LookaheadList arg);
SDF_LookaheadList SDF_setLookaheadListWsAfterSep(SDF_LookaheadList arg, SDF_OptLayout wsAfterSep);
ATbool SDF_hasLookaheadListTail(SDF_LookaheadList arg);
SDF_LookaheadList SDF_getLookaheadListTail(SDF_LookaheadList arg);
SDF_LookaheadList SDF_setLookaheadListTail(SDF_LookaheadList arg, SDF_LookaheadList tail);

/*}}}  */
/*{{{  SDF_Restriction accessors */

ATbool SDF_isValidRestriction(SDF_Restriction arg);
inline ATbool SDF_isRestrictionFollow(SDF_Restriction arg);
ATbool SDF_hasRestrictionSymbols(SDF_Restriction arg);
SDF_Symbols SDF_getRestrictionSymbols(SDF_Restriction arg);
SDF_Restriction SDF_setRestrictionSymbols(SDF_Restriction arg, SDF_Symbols Symbols);
ATbool SDF_hasRestrictionWsAfterSymbols(SDF_Restriction arg);
SDF_OptLayout SDF_getRestrictionWsAfterSymbols(SDF_Restriction arg);
SDF_Restriction SDF_setRestrictionWsAfterSymbols(SDF_Restriction arg, SDF_OptLayout wsAfterSymbols);
ATbool SDF_hasRestrictionWsAfterSlash(SDF_Restriction arg);
SDF_OptLayout SDF_getRestrictionWsAfterSlash(SDF_Restriction arg);
SDF_Restriction SDF_setRestrictionWsAfterSlash(SDF_Restriction arg, SDF_OptLayout wsAfterSlash);
ATbool SDF_hasRestrictionLookaheads(SDF_Restriction arg);
SDF_Lookaheads SDF_getRestrictionLookaheads(SDF_Restriction arg);
SDF_Restriction SDF_setRestrictionLookaheads(SDF_Restriction arg, SDF_Lookaheads Lookaheads);

/*}}}  */
/*{{{  SDF_Restrictions accessors */

ATbool SDF_isValidRestrictions(SDF_Restrictions arg);
inline ATbool SDF_isRestrictionsDefault(SDF_Restrictions arg);
ATbool SDF_hasRestrictionsList(SDF_Restrictions arg);
SDF_RestrictionList SDF_getRestrictionsList(SDF_Restrictions arg);
SDF_Restrictions SDF_setRestrictionsList(SDF_Restrictions arg, SDF_RestrictionList list);

/*}}}  */
/*{{{  SDF_RestrictionList accessors */

ATbool SDF_isValidRestrictionList(SDF_RestrictionList arg);
inline ATbool SDF_isRestrictionListEmpty(SDF_RestrictionList arg);
inline ATbool SDF_isRestrictionListSingle(SDF_RestrictionList arg);
inline ATbool SDF_isRestrictionListMany(SDF_RestrictionList arg);
ATbool SDF_hasRestrictionListHead(SDF_RestrictionList arg);
SDF_Restriction SDF_getRestrictionListHead(SDF_RestrictionList arg);
SDF_RestrictionList SDF_setRestrictionListHead(SDF_RestrictionList arg, SDF_Restriction head);
ATbool SDF_hasRestrictionListWsAfterFirst(SDF_RestrictionList arg);
SDF_OptLayout SDF_getRestrictionListWsAfterFirst(SDF_RestrictionList arg);
SDF_RestrictionList SDF_setRestrictionListWsAfterFirst(SDF_RestrictionList arg, SDF_OptLayout wsAfterFirst);
ATbool SDF_hasRestrictionListTail(SDF_RestrictionList arg);
SDF_RestrictionList SDF_getRestrictionListTail(SDF_RestrictionList arg);
SDF_RestrictionList SDF_setRestrictionListTail(SDF_RestrictionList arg, SDF_RestrictionList tail);

/*}}}  */
/*{{{  SDF_Attribute accessors */

ATbool SDF_isValidAttribute(SDF_Attribute arg);
inline ATbool SDF_isAttributeReject(SDF_Attribute arg);
inline ATbool SDF_isAttributePrefer(SDF_Attribute arg);
inline ATbool SDF_isAttributeAvoid(SDF_Attribute arg);
inline ATbool SDF_isAttributeBracket(SDF_Attribute arg);
inline ATbool SDF_isAttributeAssoc(SDF_Attribute arg);
inline ATbool SDF_isAttributeId(SDF_Attribute arg);
inline ATbool SDF_isAttributeTerm(SDF_Attribute arg);
ATbool SDF_hasAttributeAssociativity(SDF_Attribute arg);
SDF_Associativity SDF_getAttributeAssociativity(SDF_Attribute arg);
SDF_Attribute SDF_setAttributeAssociativity(SDF_Attribute arg, SDF_Associativity Associativity);
ATbool SDF_hasAttributeWsAfterId(SDF_Attribute arg);
SDF_OptLayout SDF_getAttributeWsAfterId(SDF_Attribute arg);
SDF_Attribute SDF_setAttributeWsAfterId(SDF_Attribute arg, SDF_OptLayout wsAfterId);
ATbool SDF_hasAttributeWsAfterParenOpen(SDF_Attribute arg);
SDF_OptLayout SDF_getAttributeWsAfterParenOpen(SDF_Attribute arg);
SDF_Attribute SDF_setAttributeWsAfterParenOpen(SDF_Attribute arg, SDF_OptLayout wsAfterParenOpen);
ATbool SDF_hasAttributeModuleName(SDF_Attribute arg);
SDF_ModuleName SDF_getAttributeModuleName(SDF_Attribute arg);
SDF_Attribute SDF_setAttributeModuleName(SDF_Attribute arg, SDF_ModuleName ModuleName);
ATbool SDF_hasAttributeWsAfterModuleName(SDF_Attribute arg);
SDF_OptLayout SDF_getAttributeWsAfterModuleName(SDF_Attribute arg);
SDF_Attribute SDF_setAttributeWsAfterModuleName(SDF_Attribute arg, SDF_OptLayout wsAfterModuleName);
ATbool SDF_hasAttributeAterm(SDF_Attribute arg);
SDF_ATerm SDF_getAttributeAterm(SDF_Attribute arg);
SDF_Attribute SDF_setAttributeAterm(SDF_Attribute arg, SDF_ATerm aterm);

/*}}}  */
/*{{{  SDF_Symbol accessors */

ATbool SDF_isValidSymbol(SDF_Symbol arg);
inline ATbool SDF_isSymbolLabel(SDF_Symbol arg);
inline ATbool SDF_isSymbolLit(SDF_Symbol arg);
inline ATbool SDF_isSymbolSort(SDF_Symbol arg);
inline ATbool SDF_isSymbolParameterizedSort(SDF_Symbol arg);
inline ATbool SDF_isSymbolCharClass(SDF_Symbol arg);
inline ATbool SDF_isSymbolLifting(SDF_Symbol arg);
inline ATbool SDF_isSymbolEmpty(SDF_Symbol arg);
inline ATbool SDF_isSymbolSeq(SDF_Symbol arg);
inline ATbool SDF_isSymbolOpt(SDF_Symbol arg);
inline ATbool SDF_isSymbolIter(SDF_Symbol arg);
inline ATbool SDF_isSymbolIterStar(SDF_Symbol arg);
inline ATbool SDF_isSymbolIterSep(SDF_Symbol arg);
inline ATbool SDF_isSymbolIterStarSep(SDF_Symbol arg);
inline ATbool SDF_isSymbolIterN(SDF_Symbol arg);
inline ATbool SDF_isSymbolIterSepN(SDF_Symbol arg);
inline ATbool SDF_isSymbolTuple(SDF_Symbol arg);
inline ATbool SDF_isSymbolPair(SDF_Symbol arg);
inline ATbool SDF_isSymbolFunc(SDF_Symbol arg);
inline ATbool SDF_isSymbolAlt(SDF_Symbol arg);
inline ATbool SDF_isSymbolStrategy(SDF_Symbol arg);
inline ATbool SDF_isSymbolCf(SDF_Symbol arg);
inline ATbool SDF_isSymbolLex(SDF_Symbol arg);
inline ATbool SDF_isSymbolVarsym(SDF_Symbol arg);
inline ATbool SDF_isSymbolLayout(SDF_Symbol arg);
inline ATbool SDF_isSymbolBracket(SDF_Symbol arg);
inline ATbool SDF_isSymbolStart(SDF_Symbol arg);
inline ATbool SDF_isSymbolFileStart(SDF_Symbol arg);
ATbool SDF_hasSymbolLabel(SDF_Symbol arg);
SDF_Literal SDF_getSymbolLabel(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolLabel(SDF_Symbol arg, SDF_Literal label);
ATbool SDF_hasSymbolWsAfterLabel(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterLabel(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterLabel(SDF_Symbol arg, SDF_OptLayout wsAfterLabel);
ATbool SDF_hasSymbolWsAfterColon(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterColon(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterColon(SDF_Symbol arg, SDF_OptLayout wsAfterColon);
ATbool SDF_hasSymbolSymbol(SDF_Symbol arg);
SDF_Symbol SDF_getSymbolSymbol(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolSymbol(SDF_Symbol arg, SDF_Symbol Symbol);
ATbool SDF_hasSymbolLiteral(SDF_Symbol arg);
SDF_Literal SDF_getSymbolLiteral(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolLiteral(SDF_Symbol arg, SDF_Literal Literal);
ATbool SDF_hasSymbolSort(SDF_Symbol arg);
SDF_Sort SDF_getSymbolSort(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolSort(SDF_Symbol arg, SDF_Sort Sort);
ATbool SDF_hasSymbolWsAfterSort(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterSort(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterSort(SDF_Symbol arg, SDF_OptLayout wsAfterSort);
ATbool SDF_hasSymbolWsAfterBracketOpenBracketOpen(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterBracketOpenBracketOpen(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterBracketOpenBracketOpen(SDF_Symbol arg, SDF_OptLayout wsAfterBracketOpenBracketOpen);
ATbool SDF_hasSymbolParameters(SDF_Symbol arg);
SDF_SymbolParameters SDF_getSymbolParameters(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolParameters(SDF_Symbol arg, SDF_SymbolParameters parameters);
ATbool SDF_hasSymbolWsAfterParameters(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterParameters(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterParameters(SDF_Symbol arg, SDF_OptLayout wsAfterParameters);
ATbool SDF_hasSymbolCharClass(SDF_Symbol arg);
SDF_CharClass SDF_getSymbolCharClass(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolCharClass(SDF_Symbol arg, SDF_CharClass CharClass);
ATbool SDF_hasSymbolWsAfterLeftQuote(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterLeftQuote(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterLeftQuote(SDF_Symbol arg, SDF_OptLayout wsAfterLeftQuote);
ATbool SDF_hasSymbolWsAfterSymbol(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterSymbol(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterSymbol(SDF_Symbol arg, SDF_OptLayout wsAfterSymbol);
ATbool SDF_hasSymbolWsAfterParenOpen(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterParenOpen(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterParenOpen(SDF_Symbol arg, SDF_OptLayout wsAfterParenOpen);
ATbool SDF_hasSymbolHead(SDF_Symbol arg);
SDF_Symbol SDF_getSymbolHead(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolHead(SDF_Symbol arg, SDF_Symbol head);
ATbool SDF_hasSymbolWsAfterHead(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterHead(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterHead(SDF_Symbol arg, SDF_OptLayout wsAfterHead);
ATbool SDF_hasSymbolTail(SDF_Symbol arg);
SDF_SymbolTail SDF_getSymbolTail(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolTail(SDF_Symbol arg, SDF_SymbolTail tail);
ATbool SDF_hasSymbolWsAfterTail(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterTail(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterTail(SDF_Symbol arg, SDF_OptLayout wsAfterTail);
ATbool SDF_hasSymbolWsAfterBraceOpen(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterBraceOpen(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterBraceOpen(SDF_Symbol arg, SDF_OptLayout wsAfterBraceOpen);
ATbool SDF_hasSymbolSep(SDF_Symbol arg);
SDF_Symbol SDF_getSymbolSep(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolSep(SDF_Symbol arg, SDF_Symbol sep);
ATbool SDF_hasSymbolWsAfterSep(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterSep(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterSep(SDF_Symbol arg, SDF_OptLayout wsAfterSep);
ATbool SDF_hasSymbolWsAfterBraceClose(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterBraceClose(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterBraceClose(SDF_Symbol arg, SDF_OptLayout wsAfterBraceClose);
ATbool SDF_hasSymbolN(SDF_Symbol arg);
SDF_NatCon SDF_getSymbolN(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolN(SDF_Symbol arg, SDF_NatCon n);
ATbool SDF_hasSymbolWsAfterN(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterN(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterN(SDF_Symbol arg, SDF_OptLayout wsAfterN);
ATbool SDF_hasSymbolWsAfterLessThan(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterLessThan(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterLessThan(SDF_Symbol arg, SDF_OptLayout wsAfterLessThan);
ATbool SDF_hasSymbolWsAfterComma(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterComma(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterComma(SDF_Symbol arg, SDF_OptLayout wsAfterComma);
ATbool SDF_hasSymbolRest(SDF_Symbol arg);
SDF_SymbolRest SDF_getSymbolRest(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolRest(SDF_Symbol arg, SDF_SymbolRest rest);
ATbool SDF_hasSymbolWsAfterRest(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterRest(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterRest(SDF_Symbol arg, SDF_OptLayout wsAfterRest);
ATbool SDF_hasSymbolLeft(SDF_Symbol arg);
SDF_Symbol SDF_getSymbolLeft(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolLeft(SDF_Symbol arg, SDF_Symbol left);
ATbool SDF_hasSymbolWsAfterLeft(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterLeft(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterLeft(SDF_Symbol arg, SDF_OptLayout wsAfterLeft);
ATbool SDF_hasSymbolWsAfterHash(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterHash(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterHash(SDF_Symbol arg, SDF_OptLayout wsAfterHash);
ATbool SDF_hasSymbolRight(SDF_Symbol arg);
SDF_Symbol SDF_getSymbolRight(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolRight(SDF_Symbol arg, SDF_Symbol right);
ATbool SDF_hasSymbolArguments(SDF_Symbol arg);
SDF_Symbols SDF_getSymbolArguments(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolArguments(SDF_Symbol arg, SDF_Symbols arguments);
ATbool SDF_hasSymbolWsAfterArguments(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterArguments(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterArguments(SDF_Symbol arg, SDF_OptLayout wsAfterArguments);
ATbool SDF_hasSymbolWsAfterEqualsGreaterThan(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterEqualsGreaterThan(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterEqualsGreaterThan(SDF_Symbol arg, SDF_OptLayout wsAfterEqualsGreaterThan);
ATbool SDF_hasSymbolResults(SDF_Symbol arg);
SDF_Symbol SDF_getSymbolResults(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolResults(SDF_Symbol arg, SDF_Symbol results);
ATbool SDF_hasSymbolWsAfterResults(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterResults(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterResults(SDF_Symbol arg, SDF_OptLayout wsAfterResults);
ATbool SDF_hasSymbolWsAfterBar(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterBar(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterBar(SDF_Symbol arg, SDF_OptLayout wsAfterBar);
ATbool SDF_hasSymbolWsAfterGreaterThan(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterGreaterThan(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterGreaterThan(SDF_Symbol arg, SDF_OptLayout wsAfterGreaterThan);
ATbool SDF_hasSymbolWsAfterRight(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterRight(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterRight(SDF_Symbol arg, SDF_OptLayout wsAfterRight);
ATbool SDF_hasSymbolWsAfterCF(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterCF(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterCF(SDF_Symbol arg, SDF_OptLayout wsAfterCF);
ATbool SDF_hasSymbolWsAfterLEX(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterLEX(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterLEX(SDF_Symbol arg, SDF_OptLayout wsAfterLEX);
ATbool SDF_hasSymbolWsAfterVAR(SDF_Symbol arg);
SDF_OptLayout SDF_getSymbolWsAfterVAR(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterVAR(SDF_Symbol arg, SDF_OptLayout wsAfterVAR);

/*}}}  */
/*{{{  SDF_Production accessors */

ATbool SDF_isValidProduction(SDF_Production arg);
inline ATbool SDF_isProductionProdFun(SDF_Production arg);
inline ATbool SDF_isProductionProd(SDF_Production arg);
ATbool SDF_hasProductionFunctionSymbol(SDF_Production arg);
SDF_Literal SDF_getProductionFunctionSymbol(SDF_Production arg);
SDF_Production SDF_setProductionFunctionSymbol(SDF_Production arg, SDF_Literal functionSymbol);
ATbool SDF_hasProductionWsAfterFunctionSymbol(SDF_Production arg);
SDF_OptLayout SDF_getProductionWsAfterFunctionSymbol(SDF_Production arg);
SDF_Production SDF_setProductionWsAfterFunctionSymbol(SDF_Production arg, SDF_OptLayout wsAfterFunctionSymbol);
ATbool SDF_hasProductionWsAfterParenOpen(SDF_Production arg);
SDF_OptLayout SDF_getProductionWsAfterParenOpen(SDF_Production arg);
SDF_Production SDF_setProductionWsAfterParenOpen(SDF_Production arg, SDF_OptLayout wsAfterParenOpen);
ATbool SDF_hasProductionArguments(SDF_Production arg);
SDF_SymbolArguments SDF_getProductionArguments(SDF_Production arg);
SDF_Production SDF_setProductionArguments(SDF_Production arg, SDF_SymbolArguments arguments);
ATbool SDF_hasProductionWsAfterArguments(SDF_Production arg);
SDF_OptLayout SDF_getProductionWsAfterArguments(SDF_Production arg);
SDF_Production SDF_setProductionWsAfterArguments(SDF_Production arg, SDF_OptLayout wsAfterArguments);
ATbool SDF_hasProductionWsAfterParenClose(SDF_Production arg);
SDF_OptLayout SDF_getProductionWsAfterParenClose(SDF_Production arg);
SDF_Production SDF_setProductionWsAfterParenClose(SDF_Production arg, SDF_OptLayout wsAfterParenClose);
ATbool SDF_hasProductionWsAfterGreaterThan(SDF_Production arg);
SDF_OptLayout SDF_getProductionWsAfterGreaterThan(SDF_Production arg);
SDF_Production SDF_setProductionWsAfterGreaterThan(SDF_Production arg, SDF_OptLayout wsAfterGreaterThan);
ATbool SDF_hasProductionResult(SDF_Production arg);
SDF_Symbol SDF_getProductionResult(SDF_Production arg);
SDF_Production SDF_setProductionResult(SDF_Production arg, SDF_Symbol result);
ATbool SDF_hasProductionWsAfterResult(SDF_Production arg);
SDF_OptLayout SDF_getProductionWsAfterResult(SDF_Production arg);
SDF_Production SDF_setProductionWsAfterResult(SDF_Production arg, SDF_OptLayout wsAfterResult);
ATbool SDF_hasProductionAttributes(SDF_Production arg);
SDF_Attributes SDF_getProductionAttributes(SDF_Production arg);
SDF_Production SDF_setProductionAttributes(SDF_Production arg, SDF_Attributes Attributes);
ATbool SDF_hasProductionSymbols(SDF_Production arg);
SDF_Symbols SDF_getProductionSymbols(SDF_Production arg);
SDF_Production SDF_setProductionSymbols(SDF_Production arg, SDF_Symbols Symbols);
ATbool SDF_hasProductionWsAfterSymbols(SDF_Production arg);
SDF_OptLayout SDF_getProductionWsAfterSymbols(SDF_Production arg);
SDF_Production SDF_setProductionWsAfterSymbols(SDF_Production arg, SDF_OptLayout wsAfterSymbols);

/*}}}  */
/*{{{  SDF_SymbolArguments accessors */

ATbool SDF_isValidSymbolArguments(SDF_SymbolArguments arg);
inline ATbool SDF_isSymbolArgumentsEmpty(SDF_SymbolArguments arg);
inline ATbool SDF_isSymbolArgumentsSingle(SDF_SymbolArguments arg);
inline ATbool SDF_isSymbolArgumentsMany(SDF_SymbolArguments arg);
ATbool SDF_hasSymbolArgumentsHead(SDF_SymbolArguments arg);
SDF_Symbol SDF_getSymbolArgumentsHead(SDF_SymbolArguments arg);
SDF_SymbolArguments SDF_setSymbolArgumentsHead(SDF_SymbolArguments arg, SDF_Symbol head);
ATbool SDF_hasSymbolArgumentsWsAfterFirst(SDF_SymbolArguments arg);
SDF_OptLayout SDF_getSymbolArgumentsWsAfterFirst(SDF_SymbolArguments arg);
SDF_SymbolArguments SDF_setSymbolArgumentsWsAfterFirst(SDF_SymbolArguments arg, SDF_OptLayout wsAfterFirst);
ATbool SDF_hasSymbolArgumentsSep(SDF_SymbolArguments arg);
char * SDF_getSymbolArgumentsSep(SDF_SymbolArguments arg);
SDF_SymbolArguments SDF_setSymbolArgumentsSep(SDF_SymbolArguments arg, char * sep);
ATbool SDF_hasSymbolArgumentsWsAfterSep(SDF_SymbolArguments arg);
SDF_OptLayout SDF_getSymbolArgumentsWsAfterSep(SDF_SymbolArguments arg);
SDF_SymbolArguments SDF_setSymbolArgumentsWsAfterSep(SDF_SymbolArguments arg, SDF_OptLayout wsAfterSep);
ATbool SDF_hasSymbolArgumentsTail(SDF_SymbolArguments arg);
SDF_SymbolArguments SDF_getSymbolArgumentsTail(SDF_SymbolArguments arg);
SDF_SymbolArguments SDF_setSymbolArgumentsTail(SDF_SymbolArguments arg, SDF_SymbolArguments tail);

/*}}}  */
/*{{{  SDF_Sort accessors */

ATbool SDF_isValidSort(SDF_Sort arg);
inline ATbool SDF_isSortOneChar(SDF_Sort arg);
inline ATbool SDF_isSortMoreChars(SDF_Sort arg);
ATbool SDF_hasSortChars(SDF_Sort arg);
SDF_CHARLIST SDF_getSortChars(SDF_Sort arg);
SDF_Sort SDF_setSortChars(SDF_Sort arg, SDF_CHARLIST chars);

/*}}}  */
/*{{{  SDF_SymbolParameters accessors */

ATbool SDF_isValidSymbolParameters(SDF_SymbolParameters arg);
inline ATbool SDF_isSymbolParametersSingle(SDF_SymbolParameters arg);
inline ATbool SDF_isSymbolParametersMany(SDF_SymbolParameters arg);
ATbool SDF_hasSymbolParametersHead(SDF_SymbolParameters arg);
SDF_Symbol SDF_getSymbolParametersHead(SDF_SymbolParameters arg);
SDF_SymbolParameters SDF_setSymbolParametersHead(SDF_SymbolParameters arg, SDF_Symbol head);
ATbool SDF_hasSymbolParametersWsAfterFirst(SDF_SymbolParameters arg);
SDF_OptLayout SDF_getSymbolParametersWsAfterFirst(SDF_SymbolParameters arg);
SDF_SymbolParameters SDF_setSymbolParametersWsAfterFirst(SDF_SymbolParameters arg, SDF_OptLayout wsAfterFirst);
ATbool SDF_hasSymbolParametersSep(SDF_SymbolParameters arg);
char * SDF_getSymbolParametersSep(SDF_SymbolParameters arg);
SDF_SymbolParameters SDF_setSymbolParametersSep(SDF_SymbolParameters arg, char * sep);
ATbool SDF_hasSymbolParametersWsAfterSep(SDF_SymbolParameters arg);
SDF_OptLayout SDF_getSymbolParametersWsAfterSep(SDF_SymbolParameters arg);
SDF_SymbolParameters SDF_setSymbolParametersWsAfterSep(SDF_SymbolParameters arg, SDF_OptLayout wsAfterSep);
ATbool SDF_hasSymbolParametersTail(SDF_SymbolParameters arg);
SDF_SymbolParameters SDF_getSymbolParametersTail(SDF_SymbolParameters arg);
SDF_SymbolParameters SDF_setSymbolParametersTail(SDF_SymbolParameters arg, SDF_SymbolParameters tail);

/*}}}  */
/*{{{  SDF_NumChar accessors */

ATbool SDF_isValidNumChar(SDF_NumChar arg);
inline ATbool SDF_isNumCharDigits(SDF_NumChar arg);
ATbool SDF_hasNumCharChars(SDF_NumChar arg);
SDF_CHARLIST SDF_getNumCharChars(SDF_NumChar arg);
SDF_NumChar SDF_setNumCharChars(SDF_NumChar arg, SDF_CHARLIST chars);

/*}}}  */
/*{{{  SDF_ShortChar accessors */

ATbool SDF_isValidShortChar(SDF_ShortChar arg);
inline ATbool SDF_isShortCharRegular(SDF_ShortChar arg);
inline ATbool SDF_isShortCharEscaped(SDF_ShortChar arg);
ATbool SDF_hasShortCharChars(SDF_ShortChar arg);
SDF_CHARLIST SDF_getShortCharChars(SDF_ShortChar arg);
SDF_ShortChar SDF_setShortCharChars(SDF_ShortChar arg, SDF_CHARLIST chars);

/*}}}  */
/*{{{  SDF_Character accessors */

ATbool SDF_isValidCharacter(SDF_Character arg);
inline ATbool SDF_isCharacterNumeric(SDF_Character arg);
inline ATbool SDF_isCharacterShort(SDF_Character arg);
inline ATbool SDF_isCharacterTop(SDF_Character arg);
inline ATbool SDF_isCharacterEof(SDF_Character arg);
inline ATbool SDF_isCharacterBot(SDF_Character arg);
inline ATbool SDF_isCharacterLabelUnderscoreStart(SDF_Character arg);
ATbool SDF_hasCharacterNumChar(SDF_Character arg);
SDF_NumChar SDF_getCharacterNumChar(SDF_Character arg);
SDF_Character SDF_setCharacterNumChar(SDF_Character arg, SDF_NumChar NumChar);
ATbool SDF_hasCharacterShortChar(SDF_Character arg);
SDF_ShortChar SDF_getCharacterShortChar(SDF_Character arg);
SDF_Character SDF_setCharacterShortChar(SDF_Character arg, SDF_ShortChar ShortChar);

/*}}}  */
/*{{{  SDF_CharRange accessors */

ATbool SDF_isValidCharRange(SDF_CharRange arg);
inline ATbool SDF_isCharRangeDefault(SDF_CharRange arg);
inline ATbool SDF_isCharRangeRange(SDF_CharRange arg);
ATbool SDF_hasCharRangeCharacter(SDF_CharRange arg);
SDF_Character SDF_getCharRangeCharacter(SDF_CharRange arg);
SDF_CharRange SDF_setCharRangeCharacter(SDF_CharRange arg, SDF_Character Character);
ATbool SDF_hasCharRangeStart(SDF_CharRange arg);
SDF_Character SDF_getCharRangeStart(SDF_CharRange arg);
SDF_CharRange SDF_setCharRangeStart(SDF_CharRange arg, SDF_Character start);
ATbool SDF_hasCharRangeWsAfterStart(SDF_CharRange arg);
SDF_OptLayout SDF_getCharRangeWsAfterStart(SDF_CharRange arg);
SDF_CharRange SDF_setCharRangeWsAfterStart(SDF_CharRange arg, SDF_OptLayout wsAfterStart);
ATbool SDF_hasCharRangeWsAfter(SDF_CharRange arg);
SDF_OptLayout SDF_getCharRangeWsAfter(SDF_CharRange arg);
SDF_CharRange SDF_setCharRangeWsAfter(SDF_CharRange arg, SDF_OptLayout wsAfter);
ATbool SDF_hasCharRangeEnd(SDF_CharRange arg);
SDF_Character SDF_getCharRangeEnd(SDF_CharRange arg);
SDF_CharRange SDF_setCharRangeEnd(SDF_CharRange arg, SDF_Character end);

/*}}}  */
/*{{{  SDF_CharRanges accessors */

ATbool SDF_isValidCharRanges(SDF_CharRanges arg);
inline ATbool SDF_isCharRangesDefault(SDF_CharRanges arg);
inline ATbool SDF_isCharRangesConc(SDF_CharRanges arg);
inline ATbool SDF_isCharRangesBracket(SDF_CharRanges arg);
ATbool SDF_hasCharRangesCharRange(SDF_CharRanges arg);
SDF_CharRange SDF_getCharRangesCharRange(SDF_CharRanges arg);
SDF_CharRanges SDF_setCharRangesCharRange(SDF_CharRanges arg, SDF_CharRange CharRange);
ATbool SDF_hasCharRangesLeft(SDF_CharRanges arg);
SDF_CharRanges SDF_getCharRangesLeft(SDF_CharRanges arg);
SDF_CharRanges SDF_setCharRangesLeft(SDF_CharRanges arg, SDF_CharRanges left);
ATbool SDF_hasCharRangesWsAfterLeft(SDF_CharRanges arg);
SDF_OptLayout SDF_getCharRangesWsAfterLeft(SDF_CharRanges arg);
SDF_CharRanges SDF_setCharRangesWsAfterLeft(SDF_CharRanges arg, SDF_OptLayout wsAfterLeft);
ATbool SDF_hasCharRangesRight(SDF_CharRanges arg);
SDF_CharRanges SDF_getCharRangesRight(SDF_CharRanges arg);
SDF_CharRanges SDF_setCharRangesRight(SDF_CharRanges arg, SDF_CharRanges right);
ATbool SDF_hasCharRangesWsAfterParenOpen(SDF_CharRanges arg);
SDF_OptLayout SDF_getCharRangesWsAfterParenOpen(SDF_CharRanges arg);
SDF_CharRanges SDF_setCharRangesWsAfterParenOpen(SDF_CharRanges arg, SDF_OptLayout wsAfterParenOpen);
ATbool SDF_hasCharRangesCharRanges(SDF_CharRanges arg);
SDF_CharRanges SDF_getCharRangesCharRanges(SDF_CharRanges arg);
SDF_CharRanges SDF_setCharRangesCharRanges(SDF_CharRanges arg, SDF_CharRanges CharRanges);
ATbool SDF_hasCharRangesWsAfterCharRanges(SDF_CharRanges arg);
SDF_OptLayout SDF_getCharRangesWsAfterCharRanges(SDF_CharRanges arg);
SDF_CharRanges SDF_setCharRangesWsAfterCharRanges(SDF_CharRanges arg, SDF_OptLayout wsAfterCharRanges);

/*}}}  */
/*{{{  SDF_OptCharRanges accessors */

ATbool SDF_isValidOptCharRanges(SDF_OptCharRanges arg);
inline ATbool SDF_isOptCharRangesAbsent(SDF_OptCharRanges arg);
inline ATbool SDF_isOptCharRangesPresent(SDF_OptCharRanges arg);
ATbool SDF_hasOptCharRangesCharRanges(SDF_OptCharRanges arg);
SDF_CharRanges SDF_getOptCharRangesCharRanges(SDF_OptCharRanges arg);
SDF_OptCharRanges SDF_setOptCharRangesCharRanges(SDF_OptCharRanges arg, SDF_CharRanges CharRanges);

/*}}}  */
/*{{{  SDF_CharClass accessors */

ATbool SDF_isValidCharClass(SDF_CharClass arg);
inline ATbool SDF_isCharClassSimpleCharclass(SDF_CharClass arg);
inline ATbool SDF_isCharClassComp(SDF_CharClass arg);
inline ATbool SDF_isCharClassDiff(SDF_CharClass arg);
inline ATbool SDF_isCharClassIsect(SDF_CharClass arg);
inline ATbool SDF_isCharClassUnion(SDF_CharClass arg);
inline ATbool SDF_isCharClassDefault(SDF_CharClass arg);
ATbool SDF_hasCharClassWsAfterBracketOpen(SDF_CharClass arg);
SDF_OptLayout SDF_getCharClassWsAfterBracketOpen(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterBracketOpen(SDF_CharClass arg, SDF_OptLayout wsAfterBracketOpen);
ATbool SDF_hasCharClassOptCharRanges(SDF_CharClass arg);
SDF_OptCharRanges SDF_getCharClassOptCharRanges(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassOptCharRanges(SDF_CharClass arg, SDF_OptCharRanges OptCharRanges);
ATbool SDF_hasCharClassWsAfterOptCharRanges(SDF_CharClass arg);
SDF_OptLayout SDF_getCharClassWsAfterOptCharRanges(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterOptCharRanges(SDF_CharClass arg, SDF_OptLayout wsAfterOptCharRanges);
ATbool SDF_hasCharClassWsAfterTilde(SDF_CharClass arg);
SDF_OptLayout SDF_getCharClassWsAfterTilde(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterTilde(SDF_CharClass arg, SDF_OptLayout wsAfterTilde);
ATbool SDF_hasCharClassCharClass(SDF_CharClass arg);
SDF_CharClass SDF_getCharClassCharClass(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassCharClass(SDF_CharClass arg, SDF_CharClass CharClass);
ATbool SDF_hasCharClassLeft(SDF_CharClass arg);
SDF_CharClass SDF_getCharClassLeft(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassLeft(SDF_CharClass arg, SDF_CharClass left);
ATbool SDF_hasCharClassWsAfterLeft(SDF_CharClass arg);
SDF_OptLayout SDF_getCharClassWsAfterLeft(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterLeft(SDF_CharClass arg, SDF_OptLayout wsAfterLeft);
ATbool SDF_hasCharClassWsAfterSlash(SDF_CharClass arg);
SDF_OptLayout SDF_getCharClassWsAfterSlash(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterSlash(SDF_CharClass arg, SDF_OptLayout wsAfterSlash);
ATbool SDF_hasCharClassRight(SDF_CharClass arg);
SDF_CharClass SDF_getCharClassRight(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassRight(SDF_CharClass arg, SDF_CharClass right);
ATbool SDF_hasCharClassWsAfterSlashBackslash(SDF_CharClass arg);
SDF_OptLayout SDF_getCharClassWsAfterSlashBackslash(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterSlashBackslash(SDF_CharClass arg, SDF_OptLayout wsAfterSlashBackslash);
ATbool SDF_hasCharClassWsAfterBackslashSlash(SDF_CharClass arg);
SDF_OptLayout SDF_getCharClassWsAfterBackslashSlash(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterBackslashSlash(SDF_CharClass arg, SDF_OptLayout wsAfterBackslashSlash);
ATbool SDF_hasCharClassWsAfterParenOpen(SDF_CharClass arg);
SDF_OptLayout SDF_getCharClassWsAfterParenOpen(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterParenOpen(SDF_CharClass arg, SDF_OptLayout wsAfterParenOpen);
ATbool SDF_hasCharClassWsAfterCharClass(SDF_CharClass arg);
SDF_OptLayout SDF_getCharClassWsAfterCharClass(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterCharClass(SDF_CharClass arg, SDF_OptLayout wsAfterCharClass);

/*}}}  */
/*{{{  SDF_Associativity accessors */

ATbool SDF_isValidAssociativity(SDF_Associativity arg);
inline ATbool SDF_isAssociativityLeft(SDF_Associativity arg);
inline ATbool SDF_isAssociativityRight(SDF_Associativity arg);
inline ATbool SDF_isAssociativityNonAssoc(SDF_Associativity arg);
inline ATbool SDF_isAssociativityAssoc(SDF_Associativity arg);

/*}}}  */
/*{{{  SDF_Group accessors */

ATbool SDF_isValidGroup(SDF_Group arg);
inline ATbool SDF_isGroupSimpleGroup(SDF_Group arg);
inline ATbool SDF_isGroupProdsGroup(SDF_Group arg);
inline ATbool SDF_isGroupAssocGroup(SDF_Group arg);
ATbool SDF_hasGroupProduction(SDF_Group arg);
SDF_Production SDF_getGroupProduction(SDF_Group arg);
SDF_Group SDF_setGroupProduction(SDF_Group arg, SDF_Production Production);
ATbool SDF_hasGroupWsAfterBraceOpen(SDF_Group arg);
SDF_OptLayout SDF_getGroupWsAfterBraceOpen(SDF_Group arg);
SDF_Group SDF_setGroupWsAfterBraceOpen(SDF_Group arg, SDF_OptLayout wsAfterBraceOpen);
ATbool SDF_hasGroupProductions(SDF_Group arg);
SDF_Productions SDF_getGroupProductions(SDF_Group arg);
SDF_Group SDF_setGroupProductions(SDF_Group arg, SDF_Productions Productions);
ATbool SDF_hasGroupWsAfterProductions(SDF_Group arg);
SDF_OptLayout SDF_getGroupWsAfterProductions(SDF_Group arg);
SDF_Group SDF_setGroupWsAfterProductions(SDF_Group arg, SDF_OptLayout wsAfterProductions);
ATbool SDF_hasGroupAssociativity(SDF_Group arg);
SDF_Associativity SDF_getGroupAssociativity(SDF_Group arg);
SDF_Group SDF_setGroupAssociativity(SDF_Group arg, SDF_Associativity Associativity);
ATbool SDF_hasGroupWsAfterAssociativity(SDF_Group arg);
SDF_OptLayout SDF_getGroupWsAfterAssociativity(SDF_Group arg);
SDF_Group SDF_setGroupWsAfterAssociativity(SDF_Group arg, SDF_OptLayout wsAfterAssociativity);
ATbool SDF_hasGroupWsAfterColon(SDF_Group arg);
SDF_OptLayout SDF_getGroupWsAfterColon(SDF_Group arg);
SDF_Group SDF_setGroupWsAfterColon(SDF_Group arg, SDF_OptLayout wsAfterColon);

/*}}}  */
/*{{{  SDF_Priority accessors */

ATbool SDF_isValidPriority(SDF_Priority arg);
inline ATbool SDF_isPriorityChain(SDF_Priority arg);
inline ATbool SDF_isPriorityAssoc(SDF_Priority arg);
ATbool SDF_hasPriorityList(SDF_Priority arg);
SDF_GroupList SDF_getPriorityList(SDF_Priority arg);
SDF_Priority SDF_setPriorityList(SDF_Priority arg, SDF_GroupList list);
ATbool SDF_hasPriorityLeft(SDF_Priority arg);
SDF_Group SDF_getPriorityLeft(SDF_Priority arg);
SDF_Priority SDF_setPriorityLeft(SDF_Priority arg, SDF_Group left);
ATbool SDF_hasPriorityWsAfterLeft(SDF_Priority arg);
SDF_OptLayout SDF_getPriorityWsAfterLeft(SDF_Priority arg);
SDF_Priority SDF_setPriorityWsAfterLeft(SDF_Priority arg, SDF_OptLayout wsAfterLeft);
ATbool SDF_hasPriorityAssociativity(SDF_Priority arg);
SDF_Associativity SDF_getPriorityAssociativity(SDF_Priority arg);
SDF_Priority SDF_setPriorityAssociativity(SDF_Priority arg, SDF_Associativity Associativity);
ATbool SDF_hasPriorityWsAfterAssociativity(SDF_Priority arg);
SDF_OptLayout SDF_getPriorityWsAfterAssociativity(SDF_Priority arg);
SDF_Priority SDF_setPriorityWsAfterAssociativity(SDF_Priority arg, SDF_OptLayout wsAfterAssociativity);
ATbool SDF_hasPriorityRight(SDF_Priority arg);
SDF_Group SDF_getPriorityRight(SDF_Priority arg);
SDF_Priority SDF_setPriorityRight(SDF_Priority arg, SDF_Group right);

/*}}}  */
/*{{{  SDF_GroupList accessors */

ATbool SDF_isValidGroupList(SDF_GroupList arg);
inline ATbool SDF_isGroupListSingle(SDF_GroupList arg);
inline ATbool SDF_isGroupListMany(SDF_GroupList arg);
ATbool SDF_hasGroupListHead(SDF_GroupList arg);
SDF_Group SDF_getGroupListHead(SDF_GroupList arg);
SDF_GroupList SDF_setGroupListHead(SDF_GroupList arg, SDF_Group head);
ATbool SDF_hasGroupListWsAfterFirst(SDF_GroupList arg);
SDF_OptLayout SDF_getGroupListWsAfterFirst(SDF_GroupList arg);
SDF_GroupList SDF_setGroupListWsAfterFirst(SDF_GroupList arg, SDF_OptLayout wsAfterFirst);
ATbool SDF_hasGroupListSep(SDF_GroupList arg);
char * SDF_getGroupListSep(SDF_GroupList arg);
SDF_GroupList SDF_setGroupListSep(SDF_GroupList arg, char * sep);
ATbool SDF_hasGroupListWsAfterSep(SDF_GroupList arg);
SDF_OptLayout SDF_getGroupListWsAfterSep(SDF_GroupList arg);
SDF_GroupList SDF_setGroupListWsAfterSep(SDF_GroupList arg, SDF_OptLayout wsAfterSep);
ATbool SDF_hasGroupListTail(SDF_GroupList arg);
SDF_GroupList SDF_getGroupListTail(SDF_GroupList arg);
SDF_GroupList SDF_setGroupListTail(SDF_GroupList arg, SDF_GroupList tail);

/*}}}  */
/*{{{  SDF_Priorities accessors */

ATbool SDF_isValidPriorities(SDF_Priorities arg);
inline ATbool SDF_isPrioritiesDefault(SDF_Priorities arg);
ATbool SDF_hasPrioritiesList(SDF_Priorities arg);
SDF_PriorityList SDF_getPrioritiesList(SDF_Priorities arg);
SDF_Priorities SDF_setPrioritiesList(SDF_Priorities arg, SDF_PriorityList list);

/*}}}  */
/*{{{  SDF_PriorityList accessors */

ATbool SDF_isValidPriorityList(SDF_PriorityList arg);
inline ATbool SDF_isPriorityListEmpty(SDF_PriorityList arg);
inline ATbool SDF_isPriorityListSingle(SDF_PriorityList arg);
inline ATbool SDF_isPriorityListMany(SDF_PriorityList arg);
ATbool SDF_hasPriorityListHead(SDF_PriorityList arg);
SDF_Priority SDF_getPriorityListHead(SDF_PriorityList arg);
SDF_PriorityList SDF_setPriorityListHead(SDF_PriorityList arg, SDF_Priority head);
ATbool SDF_hasPriorityListWsAfterFirst(SDF_PriorityList arg);
SDF_OptLayout SDF_getPriorityListWsAfterFirst(SDF_PriorityList arg);
SDF_PriorityList SDF_setPriorityListWsAfterFirst(SDF_PriorityList arg, SDF_OptLayout wsAfterFirst);
ATbool SDF_hasPriorityListSep(SDF_PriorityList arg);
char * SDF_getPriorityListSep(SDF_PriorityList arg);
SDF_PriorityList SDF_setPriorityListSep(SDF_PriorityList arg, char * sep);
ATbool SDF_hasPriorityListWsAfterSep(SDF_PriorityList arg);
SDF_OptLayout SDF_getPriorityListWsAfterSep(SDF_PriorityList arg);
SDF_PriorityList SDF_setPriorityListWsAfterSep(SDF_PriorityList arg, SDF_OptLayout wsAfterSep);
ATbool SDF_hasPriorityListTail(SDF_PriorityList arg);
SDF_PriorityList SDF_getPriorityListTail(SDF_PriorityList arg);
SDF_PriorityList SDF_setPriorityListTail(SDF_PriorityList arg, SDF_PriorityList tail);

/*}}}  */
/*{{{  SDF_SymbolTail accessors */

ATbool SDF_isValidSymbolTail(SDF_SymbolTail arg);
inline ATbool SDF_isSymbolTailSingle(SDF_SymbolTail arg);
inline ATbool SDF_isSymbolTailMany(SDF_SymbolTail arg);
ATbool SDF_hasSymbolTailHead(SDF_SymbolTail arg);
SDF_Symbol SDF_getSymbolTailHead(SDF_SymbolTail arg);
SDF_SymbolTail SDF_setSymbolTailHead(SDF_SymbolTail arg, SDF_Symbol head);
ATbool SDF_hasSymbolTailWsAfterFirst(SDF_SymbolTail arg);
SDF_OptLayout SDF_getSymbolTailWsAfterFirst(SDF_SymbolTail arg);
SDF_SymbolTail SDF_setSymbolTailWsAfterFirst(SDF_SymbolTail arg, SDF_OptLayout wsAfterFirst);
ATbool SDF_hasSymbolTailTail(SDF_SymbolTail arg);
SDF_SymbolTail SDF_getSymbolTailTail(SDF_SymbolTail arg);
SDF_SymbolTail SDF_setSymbolTailTail(SDF_SymbolTail arg, SDF_SymbolTail tail);

/*}}}  */
/*{{{  SDF_SymbolRest accessors */

ATbool SDF_isValidSymbolRest(SDF_SymbolRest arg);
inline ATbool SDF_isSymbolRestSingle(SDF_SymbolRest arg);
inline ATbool SDF_isSymbolRestMany(SDF_SymbolRest arg);
ATbool SDF_hasSymbolRestHead(SDF_SymbolRest arg);
SDF_Symbol SDF_getSymbolRestHead(SDF_SymbolRest arg);
SDF_SymbolRest SDF_setSymbolRestHead(SDF_SymbolRest arg, SDF_Symbol head);
ATbool SDF_hasSymbolRestWsAfterFirst(SDF_SymbolRest arg);
SDF_OptLayout SDF_getSymbolRestWsAfterFirst(SDF_SymbolRest arg);
SDF_SymbolRest SDF_setSymbolRestWsAfterFirst(SDF_SymbolRest arg, SDF_OptLayout wsAfterFirst);
ATbool SDF_hasSymbolRestSep(SDF_SymbolRest arg);
char * SDF_getSymbolRestSep(SDF_SymbolRest arg);
SDF_SymbolRest SDF_setSymbolRestSep(SDF_SymbolRest arg, char * sep);
ATbool SDF_hasSymbolRestWsAfterSep(SDF_SymbolRest arg);
SDF_OptLayout SDF_getSymbolRestWsAfterSep(SDF_SymbolRest arg);
SDF_SymbolRest SDF_setSymbolRestWsAfterSep(SDF_SymbolRest arg, SDF_OptLayout wsAfterSep);
ATbool SDF_hasSymbolRestTail(SDF_SymbolRest arg);
SDF_SymbolRest SDF_getSymbolRestTail(SDF_SymbolRest arg);
SDF_SymbolRest SDF_setSymbolRestTail(SDF_SymbolRest arg, SDF_SymbolRest tail);

/*}}}  */
/*{{{  SDF_Renamings accessors */

ATbool SDF_isValidRenamings(SDF_Renamings arg);
inline ATbool SDF_isRenamingsRenamings(SDF_Renamings arg);
ATbool SDF_hasRenamingsWsAfterBracketOpen(SDF_Renamings arg);
SDF_OptLayout SDF_getRenamingsWsAfterBracketOpen(SDF_Renamings arg);
SDF_Renamings SDF_setRenamingsWsAfterBracketOpen(SDF_Renamings arg, SDF_OptLayout wsAfterBracketOpen);
ATbool SDF_hasRenamingsList(SDF_Renamings arg);
SDF_RenamingList SDF_getRenamingsList(SDF_Renamings arg);
SDF_Renamings SDF_setRenamingsList(SDF_Renamings arg, SDF_RenamingList list);
ATbool SDF_hasRenamingsWsAfterList(SDF_Renamings arg);
SDF_OptLayout SDF_getRenamingsWsAfterList(SDF_Renamings arg);
SDF_Renamings SDF_setRenamingsWsAfterList(SDF_Renamings arg, SDF_OptLayout wsAfterList);

/*}}}  */
/*{{{  SDF_RenamingList accessors */

ATbool SDF_isValidRenamingList(SDF_RenamingList arg);
inline ATbool SDF_isRenamingListEmpty(SDF_RenamingList arg);
inline ATbool SDF_isRenamingListSingle(SDF_RenamingList arg);
inline ATbool SDF_isRenamingListMany(SDF_RenamingList arg);
ATbool SDF_hasRenamingListHead(SDF_RenamingList arg);
SDF_Renaming SDF_getRenamingListHead(SDF_RenamingList arg);
SDF_RenamingList SDF_setRenamingListHead(SDF_RenamingList arg, SDF_Renaming head);
ATbool SDF_hasRenamingListWsAfterFirst(SDF_RenamingList arg);
SDF_OptLayout SDF_getRenamingListWsAfterFirst(SDF_RenamingList arg);
SDF_RenamingList SDF_setRenamingListWsAfterFirst(SDF_RenamingList arg, SDF_OptLayout wsAfterFirst);
ATbool SDF_hasRenamingListTail(SDF_RenamingList arg);
SDF_RenamingList SDF_getRenamingListTail(SDF_RenamingList arg);
SDF_RenamingList SDF_setRenamingListTail(SDF_RenamingList arg, SDF_RenamingList tail);

/*}}}  */
/*{{{  SDF_Renaming accessors */

ATbool SDF_isValidRenaming(SDF_Renaming arg);
inline ATbool SDF_isRenamingSymbol(SDF_Renaming arg);
inline ATbool SDF_isRenamingProduction(SDF_Renaming arg);
ATbool SDF_hasRenamingFrom(SDF_Renaming arg);
SDF_Symbol SDF_getRenamingFrom(SDF_Renaming arg);
SDF_Renaming SDF_setRenamingFrom(SDF_Renaming arg, SDF_Symbol from);
ATbool SDF_hasRenamingWsAfterFrom(SDF_Renaming arg);
SDF_OptLayout SDF_getRenamingWsAfterFrom(SDF_Renaming arg);
SDF_Renaming SDF_setRenamingWsAfterFrom(SDF_Renaming arg, SDF_OptLayout wsAfterFrom);
ATbool SDF_hasRenamingWsAfterEqualsGreaterThan(SDF_Renaming arg);
SDF_OptLayout SDF_getRenamingWsAfterEqualsGreaterThan(SDF_Renaming arg);
SDF_Renaming SDF_setRenamingWsAfterEqualsGreaterThan(SDF_Renaming arg, SDF_OptLayout wsAfterEqualsGreaterThan);
ATbool SDF_hasRenamingTo(SDF_Renaming arg);
SDF_Symbol SDF_getRenamingTo(SDF_Renaming arg);
SDF_Renaming SDF_setRenamingTo(SDF_Renaming arg, SDF_Symbol to);
ATbool SDF_hasRenamingFromProd(SDF_Renaming arg);
SDF_Production SDF_getRenamingFromProd(SDF_Renaming arg);
SDF_Renaming SDF_setRenamingFromProd(SDF_Renaming arg, SDF_Production fromProd);
ATbool SDF_hasRenamingWsAfterFromProd(SDF_Renaming arg);
SDF_OptLayout SDF_getRenamingWsAfterFromProd(SDF_Renaming arg);
SDF_Renaming SDF_setRenamingWsAfterFromProd(SDF_Renaming arg, SDF_OptLayout wsAfterFromProd);
ATbool SDF_hasRenamingToProd(SDF_Renaming arg);
SDF_Production SDF_getRenamingToProd(SDF_Renaming arg);
SDF_Renaming SDF_setRenamingToProd(SDF_Renaming arg, SDF_Production toProd);

/*}}}  */
/*{{{  SDF_ModuleWord accessors */

ATbool SDF_isValidModuleWord(SDF_ModuleWord arg);
inline ATbool SDF_isModuleWordWord(SDF_ModuleWord arg);
ATbool SDF_hasModuleWordChars(SDF_ModuleWord arg);
SDF_CHARLIST SDF_getModuleWordChars(SDF_ModuleWord arg);
SDF_ModuleWord SDF_setModuleWordChars(SDF_ModuleWord arg, SDF_CHARLIST chars);

/*}}}  */
/*{{{  SDF_ModuleId accessors */

ATbool SDF_isValidModuleId(SDF_ModuleId arg);
inline ATbool SDF_isModuleIdWord(SDF_ModuleId arg);
inline ATbool SDF_isModuleIdSlashWord(SDF_ModuleId arg);
inline ATbool SDF_isModuleIdWordSlashWord(SDF_ModuleId arg);
ATbool SDF_hasModuleIdChars(SDF_ModuleId arg);
SDF_CHARLIST SDF_getModuleIdChars(SDF_ModuleId arg);
SDF_ModuleId SDF_setModuleIdChars(SDF_ModuleId arg, SDF_CHARLIST chars);

/*}}}  */
/*{{{  SDF_Definition accessors */

ATbool SDF_isValidDefinition(SDF_Definition arg);
inline ATbool SDF_isDefinitionDefault(SDF_Definition arg);
ATbool SDF_hasDefinitionList(SDF_Definition arg);
SDF_ModuleList SDF_getDefinitionList(SDF_Definition arg);
SDF_Definition SDF_setDefinitionList(SDF_Definition arg, SDF_ModuleList list);

/*}}}  */
/*{{{  SDF_ModuleList accessors */

ATbool SDF_isValidModuleList(SDF_ModuleList arg);
inline ATbool SDF_isModuleListEmpty(SDF_ModuleList arg);
inline ATbool SDF_isModuleListSingle(SDF_ModuleList arg);
inline ATbool SDF_isModuleListMany(SDF_ModuleList arg);
ATbool SDF_hasModuleListHead(SDF_ModuleList arg);
SDF_Module SDF_getModuleListHead(SDF_ModuleList arg);
SDF_ModuleList SDF_setModuleListHead(SDF_ModuleList arg, SDF_Module head);
ATbool SDF_hasModuleListWsAfterFirst(SDF_ModuleList arg);
SDF_OptLayout SDF_getModuleListWsAfterFirst(SDF_ModuleList arg);
SDF_ModuleList SDF_setModuleListWsAfterFirst(SDF_ModuleList arg, SDF_OptLayout wsAfterFirst);
ATbool SDF_hasModuleListTail(SDF_ModuleList arg);
SDF_ModuleList SDF_getModuleListTail(SDF_ModuleList arg);
SDF_ModuleList SDF_setModuleListTail(SDF_ModuleList arg, SDF_ModuleList tail);

/*}}}  */
/*{{{  SDF_Module accessors */

ATbool SDF_isValidModule(SDF_Module arg);
inline ATbool SDF_isModuleModule(SDF_Module arg);
ATbool SDF_hasModuleWsAfterModule(SDF_Module arg);
SDF_OptLayout SDF_getModuleWsAfterModule(SDF_Module arg);
SDF_Module SDF_setModuleWsAfterModule(SDF_Module arg, SDF_OptLayout wsAfterModule);
ATbool SDF_hasModuleModuleName(SDF_Module arg);
SDF_ModuleName SDF_getModuleModuleName(SDF_Module arg);
SDF_Module SDF_setModuleModuleName(SDF_Module arg, SDF_ModuleName ModuleName);
ATbool SDF_hasModuleWsAfterModuleName(SDF_Module arg);
SDF_OptLayout SDF_getModuleWsAfterModuleName(SDF_Module arg);
SDF_Module SDF_setModuleWsAfterModuleName(SDF_Module arg, SDF_OptLayout wsAfterModuleName);
ATbool SDF_hasModuleList(SDF_Module arg);
SDF_ImpSectionList SDF_getModuleList(SDF_Module arg);
SDF_Module SDF_setModuleList(SDF_Module arg, SDF_ImpSectionList list);
ATbool SDF_hasModuleWsAfterList(SDF_Module arg);
SDF_OptLayout SDF_getModuleWsAfterList(SDF_Module arg);
SDF_Module SDF_setModuleWsAfterList(SDF_Module arg, SDF_OptLayout wsAfterList);
ATbool SDF_hasModuleSections(SDF_Module arg);
SDF_Sections SDF_getModuleSections(SDF_Module arg);
SDF_Module SDF_setModuleSections(SDF_Module arg, SDF_Sections Sections);

/*}}}  */
/*{{{  SDF_ImpSectionList accessors */

ATbool SDF_isValidImpSectionList(SDF_ImpSectionList arg);
inline ATbool SDF_isImpSectionListEmpty(SDF_ImpSectionList arg);
inline ATbool SDF_isImpSectionListSingle(SDF_ImpSectionList arg);
inline ATbool SDF_isImpSectionListMany(SDF_ImpSectionList arg);
ATbool SDF_hasImpSectionListHead(SDF_ImpSectionList arg);
SDF_ImpSection SDF_getImpSectionListHead(SDF_ImpSectionList arg);
SDF_ImpSectionList SDF_setImpSectionListHead(SDF_ImpSectionList arg, SDF_ImpSection head);
ATbool SDF_hasImpSectionListWsAfterFirst(SDF_ImpSectionList arg);
SDF_OptLayout SDF_getImpSectionListWsAfterFirst(SDF_ImpSectionList arg);
SDF_ImpSectionList SDF_setImpSectionListWsAfterFirst(SDF_ImpSectionList arg, SDF_OptLayout wsAfterFirst);
ATbool SDF_hasImpSectionListTail(SDF_ImpSectionList arg);
SDF_ImpSectionList SDF_getImpSectionListTail(SDF_ImpSectionList arg);
SDF_ImpSectionList SDF_setImpSectionListTail(SDF_ImpSectionList arg, SDF_ImpSectionList tail);

/*}}}  */
/*{{{  SDF_Section accessors */

ATbool SDF_isValidSection(SDF_Section arg);
inline ATbool SDF_isSectionExports(SDF_Section arg);
inline ATbool SDF_isSectionHiddens(SDF_Section arg);
ATbool SDF_hasSectionWsAfterExports(SDF_Section arg);
SDF_OptLayout SDF_getSectionWsAfterExports(SDF_Section arg);
SDF_Section SDF_setSectionWsAfterExports(SDF_Section arg, SDF_OptLayout wsAfterExports);
ATbool SDF_hasSectionGrammar(SDF_Section arg);
SDF_Grammar SDF_getSectionGrammar(SDF_Section arg);
SDF_Section SDF_setSectionGrammar(SDF_Section arg, SDF_Grammar Grammar);
ATbool SDF_hasSectionWsAfterHiddens(SDF_Section arg);
SDF_OptLayout SDF_getSectionWsAfterHiddens(SDF_Section arg);
SDF_Section SDF_setSectionWsAfterHiddens(SDF_Section arg, SDF_OptLayout wsAfterHiddens);

/*}}}  */
/*{{{  SDF_Sections accessors */

ATbool SDF_isValidSections(SDF_Sections arg);
inline ATbool SDF_isSectionsDefault(SDF_Sections arg);
ATbool SDF_hasSectionsList(SDF_Sections arg);
SDF_SectionList SDF_getSectionsList(SDF_Sections arg);
SDF_Sections SDF_setSectionsList(SDF_Sections arg, SDF_SectionList list);

/*}}}  */
/*{{{  SDF_SectionList accessors */

ATbool SDF_isValidSectionList(SDF_SectionList arg);
inline ATbool SDF_isSectionListEmpty(SDF_SectionList arg);
inline ATbool SDF_isSectionListSingle(SDF_SectionList arg);
inline ATbool SDF_isSectionListMany(SDF_SectionList arg);
ATbool SDF_hasSectionListHead(SDF_SectionList arg);
SDF_Section SDF_getSectionListHead(SDF_SectionList arg);
SDF_SectionList SDF_setSectionListHead(SDF_SectionList arg, SDF_Section head);
ATbool SDF_hasSectionListWsAfterFirst(SDF_SectionList arg);
SDF_OptLayout SDF_getSectionListWsAfterFirst(SDF_SectionList arg);
SDF_SectionList SDF_setSectionListWsAfterFirst(SDF_SectionList arg, SDF_OptLayout wsAfterFirst);
ATbool SDF_hasSectionListTail(SDF_SectionList arg);
SDF_SectionList SDF_getSectionListTail(SDF_SectionList arg);
SDF_SectionList SDF_setSectionListTail(SDF_SectionList arg, SDF_SectionList tail);

/*}}}  */
/*{{{  SDF_ModuleName accessors */

ATbool SDF_isValidModuleName(SDF_ModuleName arg);
inline ATbool SDF_isModuleNameUnparameterized(SDF_ModuleName arg);
inline ATbool SDF_isModuleNameParameterized(SDF_ModuleName arg);
ATbool SDF_hasModuleNameModuleId(SDF_ModuleName arg);
SDF_ModuleId SDF_getModuleNameModuleId(SDF_ModuleName arg);
SDF_ModuleName SDF_setModuleNameModuleId(SDF_ModuleName arg, SDF_ModuleId ModuleId);
ATbool SDF_hasModuleNameWsAfterModuleId(SDF_ModuleName arg);
SDF_OptLayout SDF_getModuleNameWsAfterModuleId(SDF_ModuleName arg);
SDF_ModuleName SDF_setModuleNameWsAfterModuleId(SDF_ModuleName arg, SDF_OptLayout wsAfterModuleId);
ATbool SDF_hasModuleNameWsAfterBracketOpen(SDF_ModuleName arg);
SDF_OptLayout SDF_getModuleNameWsAfterBracketOpen(SDF_ModuleName arg);
SDF_ModuleName SDF_setModuleNameWsAfterBracketOpen(SDF_ModuleName arg, SDF_OptLayout wsAfterBracketOpen);
ATbool SDF_hasModuleNameParams(SDF_ModuleName arg);
SDF_Symbols SDF_getModuleNameParams(SDF_ModuleName arg);
SDF_ModuleName SDF_setModuleNameParams(SDF_ModuleName arg, SDF_Symbols params);
ATbool SDF_hasModuleNameWsAfterParams(SDF_ModuleName arg);
SDF_OptLayout SDF_getModuleNameWsAfterParams(SDF_ModuleName arg);
SDF_ModuleName SDF_setModuleNameWsAfterParams(SDF_ModuleName arg, SDF_OptLayout wsAfterParams);

/*}}}  */
/*{{{  SDF_ImpSection accessors */

ATbool SDF_isValidImpSection(SDF_ImpSection arg);
inline ATbool SDF_isImpSectionImports(SDF_ImpSection arg);
ATbool SDF_hasImpSectionWsAfterImports(SDF_ImpSection arg);
SDF_OptLayout SDF_getImpSectionWsAfterImports(SDF_ImpSection arg);
SDF_ImpSection SDF_setImpSectionWsAfterImports(SDF_ImpSection arg, SDF_OptLayout wsAfterImports);
ATbool SDF_hasImpSectionList(SDF_ImpSection arg);
SDF_Imports SDF_getImpSectionList(SDF_ImpSection arg);
SDF_ImpSection SDF_setImpSectionList(SDF_ImpSection arg, SDF_Imports list);

/*}}}  */
/*{{{  SDF_Imports accessors */

ATbool SDF_isValidImports(SDF_Imports arg);
inline ATbool SDF_isImportsDefault(SDF_Imports arg);
ATbool SDF_hasImportsList(SDF_Imports arg);
SDF_ImportList SDF_getImportsList(SDF_Imports arg);
SDF_Imports SDF_setImportsList(SDF_Imports arg, SDF_ImportList list);

/*}}}  */
/*{{{  SDF_ImportList accessors */

ATbool SDF_isValidImportList(SDF_ImportList arg);
inline ATbool SDF_isImportListEmpty(SDF_ImportList arg);
inline ATbool SDF_isImportListSingle(SDF_ImportList arg);
inline ATbool SDF_isImportListMany(SDF_ImportList arg);
ATbool SDF_hasImportListHead(SDF_ImportList arg);
SDF_Import SDF_getImportListHead(SDF_ImportList arg);
SDF_ImportList SDF_setImportListHead(SDF_ImportList arg, SDF_Import head);
ATbool SDF_hasImportListWsAfterFirst(SDF_ImportList arg);
SDF_OptLayout SDF_getImportListWsAfterFirst(SDF_ImportList arg);
SDF_ImportList SDF_setImportListWsAfterFirst(SDF_ImportList arg, SDF_OptLayout wsAfterFirst);
ATbool SDF_hasImportListTail(SDF_ImportList arg);
SDF_ImportList SDF_getImportListTail(SDF_ImportList arg);
SDF_ImportList SDF_setImportListTail(SDF_ImportList arg, SDF_ImportList tail);

/*}}}  */
/*{{{  SDF_Import accessors */

ATbool SDF_isValidImport(SDF_Import arg);
inline ATbool SDF_isImportModule(SDF_Import arg);
inline ATbool SDF_isImportRenamedModule(SDF_Import arg);
inline ATbool SDF_isImportBracket(SDF_Import arg);
ATbool SDF_hasImportModuleName(SDF_Import arg);
SDF_ModuleName SDF_getImportModuleName(SDF_Import arg);
SDF_Import SDF_setImportModuleName(SDF_Import arg, SDF_ModuleName ModuleName);
ATbool SDF_hasImportWsAfterModuleName(SDF_Import arg);
SDF_OptLayout SDF_getImportWsAfterModuleName(SDF_Import arg);
SDF_Import SDF_setImportWsAfterModuleName(SDF_Import arg, SDF_OptLayout wsAfterModuleName);
ATbool SDF_hasImportRenamings(SDF_Import arg);
SDF_Renamings SDF_getImportRenamings(SDF_Import arg);
SDF_Import SDF_setImportRenamings(SDF_Import arg, SDF_Renamings Renamings);
ATbool SDF_hasImportWsAfterParenOpen(SDF_Import arg);
SDF_OptLayout SDF_getImportWsAfterParenOpen(SDF_Import arg);
SDF_Import SDF_setImportWsAfterParenOpen(SDF_Import arg, SDF_OptLayout wsAfterParenOpen);
ATbool SDF_hasImportImport(SDF_Import arg);
SDF_Import SDF_getImportImport(SDF_Import arg);
SDF_Import SDF_setImportImport(SDF_Import arg, SDF_Import Import);
ATbool SDF_hasImportWsAfterImport(SDF_Import arg);
SDF_OptLayout SDF_getImportWsAfterImport(SDF_Import arg);
SDF_Import SDF_setImportWsAfterImport(SDF_Import arg, SDF_OptLayout wsAfterImport);

/*}}}  */
/*{{{  SDF_Symbols accessors */

ATbool SDF_isValidSymbols(SDF_Symbols arg);
inline ATbool SDF_isSymbolsDefault(SDF_Symbols arg);
ATbool SDF_hasSymbolsList(SDF_Symbols arg);
SDF_SymbolList SDF_getSymbolsList(SDF_Symbols arg);
SDF_Symbols SDF_setSymbolsList(SDF_Symbols arg, SDF_SymbolList list);

/*}}}  */
/*{{{  SDF_SymbolList accessors */

ATbool SDF_isValidSymbolList(SDF_SymbolList arg);
inline ATbool SDF_isSymbolListEmpty(SDF_SymbolList arg);
inline ATbool SDF_isSymbolListSingle(SDF_SymbolList arg);
inline ATbool SDF_isSymbolListMany(SDF_SymbolList arg);
ATbool SDF_hasSymbolListHead(SDF_SymbolList arg);
SDF_Symbol SDF_getSymbolListHead(SDF_SymbolList arg);
SDF_SymbolList SDF_setSymbolListHead(SDF_SymbolList arg, SDF_Symbol head);
ATbool SDF_hasSymbolListWsAfterFirst(SDF_SymbolList arg);
SDF_OptLayout SDF_getSymbolListWsAfterFirst(SDF_SymbolList arg);
SDF_SymbolList SDF_setSymbolListWsAfterFirst(SDF_SymbolList arg, SDF_OptLayout wsAfterFirst);
ATbool SDF_hasSymbolListTail(SDF_SymbolList arg);
SDF_SymbolList SDF_getSymbolListTail(SDF_SymbolList arg);
SDF_SymbolList SDF_setSymbolListTail(SDF_SymbolList arg, SDF_SymbolList tail);

/*}}}  */
/*{{{  SDF_OptExp accessors */

ATbool SDF_isValidOptExp(SDF_OptExp arg);
inline ATbool SDF_isOptExpPresent(SDF_OptExp arg);
inline ATbool SDF_isOptExpAbsent(SDF_OptExp arg);
ATbool SDF_hasOptExpWsAfterE(SDF_OptExp arg);
SDF_OptLayout SDF_getOptExpWsAfterE(SDF_OptExp arg);
SDF_OptExp SDF_setOptExpWsAfterE(SDF_OptExp arg, SDF_OptLayout wsAfterE);
ATbool SDF_hasOptExpIntCon(SDF_OptExp arg);
SDF_IntCon SDF_getOptExpIntCon(SDF_OptExp arg);
SDF_OptExp SDF_setOptExpIntCon(SDF_OptExp arg, SDF_IntCon IntCon);

/*}}}  */
/*{{{  SDF_RealCon accessors */

ATbool SDF_isValidRealCon(SDF_RealCon arg);
inline ATbool SDF_isRealConRealCon(SDF_RealCon arg);
ATbool SDF_hasRealConIntCon(SDF_RealCon arg);
SDF_IntCon SDF_getRealConIntCon(SDF_RealCon arg);
SDF_RealCon SDF_setRealConIntCon(SDF_RealCon arg, SDF_IntCon IntCon);
ATbool SDF_hasRealConWsAfterIntCon(SDF_RealCon arg);
SDF_OptLayout SDF_getRealConWsAfterIntCon(SDF_RealCon arg);
SDF_RealCon SDF_setRealConWsAfterIntCon(SDF_RealCon arg, SDF_OptLayout wsAfterIntCon);
ATbool SDF_hasRealConWsAfterPeriod(SDF_RealCon arg);
SDF_OptLayout SDF_getRealConWsAfterPeriod(SDF_RealCon arg);
SDF_RealCon SDF_setRealConWsAfterPeriod(SDF_RealCon arg, SDF_OptLayout wsAfterPeriod);
ATbool SDF_hasRealConNatCon(SDF_RealCon arg);
SDF_NatCon SDF_getRealConNatCon(SDF_RealCon arg);
SDF_RealCon SDF_setRealConNatCon(SDF_RealCon arg, SDF_NatCon NatCon);
ATbool SDF_hasRealConWsAfterNatCon(SDF_RealCon arg);
SDF_OptLayout SDF_getRealConWsAfterNatCon(SDF_RealCon arg);
SDF_RealCon SDF_setRealConWsAfterNatCon(SDF_RealCon arg, SDF_OptLayout wsAfterNatCon);
ATbool SDF_hasRealConOptExp(SDF_RealCon arg);
SDF_OptExp SDF_getRealConOptExp(SDF_RealCon arg);
SDF_RealCon SDF_setRealConOptExp(SDF_RealCon arg, SDF_OptExp OptExp);

/*}}}  */
/*{{{  SDF_NatCon accessors */

ATbool SDF_isValidNatCon(SDF_NatCon arg);
inline ATbool SDF_isNatConDigits(SDF_NatCon arg);
ATbool SDF_hasNatConChars(SDF_NatCon arg);
SDF_CHARLIST SDF_getNatConChars(SDF_NatCon arg);
SDF_NatCon SDF_setNatConChars(SDF_NatCon arg, SDF_CHARLIST chars);

/*}}}  */
/*{{{  SDF_IntCon accessors */

ATbool SDF_isValidIntCon(SDF_IntCon arg);
inline ATbool SDF_isIntConNatural(SDF_IntCon arg);
inline ATbool SDF_isIntConPositive(SDF_IntCon arg);
inline ATbool SDF_isIntConNegative(SDF_IntCon arg);
ATbool SDF_hasIntConNatCon(SDF_IntCon arg);
SDF_NatCon SDF_getIntConNatCon(SDF_IntCon arg);
SDF_IntCon SDF_setIntConNatCon(SDF_IntCon arg, SDF_NatCon NatCon);
ATbool SDF_hasIntConWsAfterPos(SDF_IntCon arg);
SDF_OptLayout SDF_getIntConWsAfterPos(SDF_IntCon arg);
SDF_IntCon SDF_setIntConWsAfterPos(SDF_IntCon arg, SDF_OptLayout wsAfterPos);
ATbool SDF_hasIntConWsAfterNeg(SDF_IntCon arg);
SDF_OptLayout SDF_getIntConWsAfterNeg(SDF_IntCon arg);
SDF_IntCon SDF_setIntConWsAfterNeg(SDF_IntCon arg, SDF_OptLayout wsAfterNeg);

/*}}}  */
/*{{{  SDF_AlphaNumericalEscChar accessors */

ATbool SDF_isValidAlphaNumericalEscChar(SDF_AlphaNumericalEscChar arg);
inline ATbool SDF_isAlphaNumericalEscCharDefault(SDF_AlphaNumericalEscChar arg);
ATbool SDF_hasAlphaNumericalEscCharChars(SDF_AlphaNumericalEscChar arg);
SDF_CHARLIST SDF_getAlphaNumericalEscCharChars(SDF_AlphaNumericalEscChar arg);
SDF_AlphaNumericalEscChar SDF_setAlphaNumericalEscCharChars(SDF_AlphaNumericalEscChar arg, SDF_CHARLIST chars);

/*}}}  */
/*{{{  SDF_DecimalEscChar accessors */

ATbool SDF_isValidDecimalEscChar(SDF_DecimalEscChar arg);
inline ATbool SDF_isDecimalEscCharDec0Underscore199(SDF_DecimalEscChar arg);
inline ATbool SDF_isDecimalEscCharDec200Underscore249(SDF_DecimalEscChar arg);
inline ATbool SDF_isDecimalEscCharDec250Underscore255(SDF_DecimalEscChar arg);
ATbool SDF_hasDecimalEscCharChars(SDF_DecimalEscChar arg);
SDF_CHARLIST SDF_getDecimalEscCharChars(SDF_DecimalEscChar arg);
SDF_DecimalEscChar SDF_setDecimalEscCharChars(SDF_DecimalEscChar arg, SDF_CHARLIST chars);

/*}}}  */
/*{{{  SDF_EscChar accessors */

ATbool SDF_isValidEscChar(SDF_EscChar arg);
inline ATbool SDF_isEscCharAlphaNumeric(SDF_EscChar arg);
inline ATbool SDF_isEscCharDecimal(SDF_EscChar arg);
ATbool SDF_hasEscCharChars(SDF_EscChar arg);
SDF_CHARLIST SDF_getEscCharChars(SDF_EscChar arg);
SDF_EscChar SDF_setEscCharChars(SDF_EscChar arg, SDF_CHARLIST chars);

/*}}}  */
/*{{{  SDF_LChar accessors */

ATbool SDF_isValidLChar(SDF_LChar arg);
inline ATbool SDF_isLCharNormal(SDF_LChar arg);
inline ATbool SDF_isLCharEscaped(SDF_LChar arg);
ATbool SDF_hasLCharChars(SDF_LChar arg);
SDF_CHARLIST SDF_getLCharChars(SDF_LChar arg);
SDF_LChar SDF_setLCharChars(SDF_LChar arg, SDF_CHARLIST chars);

/*}}}  */
/*{{{  SDF_QLiteral accessors */

ATbool SDF_isValidQLiteral(SDF_QLiteral arg);
inline ATbool SDF_isQLiteralQuoted(SDF_QLiteral arg);
ATbool SDF_hasQLiteralChars(SDF_QLiteral arg);
SDF_CHARLIST SDF_getQLiteralChars(SDF_QLiteral arg);
SDF_QLiteral SDF_setQLiteralChars(SDF_QLiteral arg, SDF_CHARLIST chars);

/*}}}  */
/*{{{  SDF_UQLiteral accessors */

ATbool SDF_isValidUQLiteral(SDF_UQLiteral arg);
inline ATbool SDF_isUQLiteralOneChar(SDF_UQLiteral arg);
inline ATbool SDF_isUQLiteralMoreChars(SDF_UQLiteral arg);
ATbool SDF_hasUQLiteralChars(SDF_UQLiteral arg);
SDF_CHARLIST SDF_getUQLiteralChars(SDF_UQLiteral arg);
SDF_UQLiteral SDF_setUQLiteralChars(SDF_UQLiteral arg, SDF_CHARLIST chars);

/*}}}  */
/*{{{  SDF_Literal accessors */

ATbool SDF_isValidLiteral(SDF_Literal arg);
inline ATbool SDF_isLiteralQlit(SDF_Literal arg);
inline ATbool SDF_isLiteralUqlit(SDF_Literal arg);
ATbool SDF_hasLiteralQLiteral(SDF_Literal arg);
SDF_QLiteral SDF_getLiteralQLiteral(SDF_Literal arg);
SDF_Literal SDF_setLiteralQLiteral(SDF_Literal arg, SDF_QLiteral QLiteral);
ATbool SDF_hasLiteralUQLiteral(SDF_Literal arg);
SDF_UQLiteral SDF_getLiteralUQLiteral(SDF_Literal arg);
SDF_Literal SDF_setLiteralUQLiteral(SDF_Literal arg, SDF_UQLiteral UQLiteral);

/*}}}  */
/*{{{  SDF_ATermList accessors */

ATbool SDF_isValidATermList(SDF_ATermList arg);
inline ATbool SDF_isATermListNotEmpty(SDF_ATermList arg);
ATbool SDF_hasATermListWsAfterBracketOpen(SDF_ATermList arg);
SDF_OptLayout SDF_getATermListWsAfterBracketOpen(SDF_ATermList arg);
SDF_ATermList SDF_setATermListWsAfterBracketOpen(SDF_ATermList arg, SDF_OptLayout wsAfterBracketOpen);
ATbool SDF_hasATermListElems(SDF_ATermList arg);
SDF_ATermElems SDF_getATermListElems(SDF_ATermList arg);
SDF_ATermList SDF_setATermListElems(SDF_ATermList arg, SDF_ATermElems elems);
ATbool SDF_hasATermListWsAfterElems(SDF_ATermList arg);
SDF_OptLayout SDF_getATermListWsAfterElems(SDF_ATermList arg);
SDF_ATermList SDF_setATermListWsAfterElems(SDF_ATermList arg, SDF_OptLayout wsAfterElems);

/*}}}  */
/*{{{  SDF_ATermElems accessors */

ATbool SDF_isValidATermElems(SDF_ATermElems arg);
inline ATbool SDF_isATermElemsEmpty(SDF_ATermElems arg);
inline ATbool SDF_isATermElemsSingle(SDF_ATermElems arg);
inline ATbool SDF_isATermElemsMany(SDF_ATermElems arg);
ATbool SDF_hasATermElemsHead(SDF_ATermElems arg);
SDF_ATerm SDF_getATermElemsHead(SDF_ATermElems arg);
SDF_ATermElems SDF_setATermElemsHead(SDF_ATermElems arg, SDF_ATerm head);
ATbool SDF_hasATermElemsWsAfterFirst(SDF_ATermElems arg);
SDF_OptLayout SDF_getATermElemsWsAfterFirst(SDF_ATermElems arg);
SDF_ATermElems SDF_setATermElemsWsAfterFirst(SDF_ATermElems arg, SDF_OptLayout wsAfterFirst);
ATbool SDF_hasATermElemsSep(SDF_ATermElems arg);
char * SDF_getATermElemsSep(SDF_ATermElems arg);
SDF_ATermElems SDF_setATermElemsSep(SDF_ATermElems arg, char * sep);
ATbool SDF_hasATermElemsWsAfterSep(SDF_ATermElems arg);
SDF_OptLayout SDF_getATermElemsWsAfterSep(SDF_ATermElems arg);
SDF_ATermElems SDF_setATermElemsWsAfterSep(SDF_ATermElems arg, SDF_OptLayout wsAfterSep);
ATbool SDF_hasATermElemsTail(SDF_ATermElems arg);
SDF_ATermElems SDF_getATermElemsTail(SDF_ATermElems arg);
SDF_ATermElems SDF_setATermElemsTail(SDF_ATermElems arg, SDF_ATermElems tail);

/*}}}  */
/*{{{  SDF_ACon accessors */

ATbool SDF_isValidACon(SDF_ACon arg);
inline ATbool SDF_isAConInt(SDF_ACon arg);
inline ATbool SDF_isAConReal(SDF_ACon arg);
ATbool SDF_hasAConIntCon(SDF_ACon arg);
SDF_IntCon SDF_getAConIntCon(SDF_ACon arg);
SDF_ACon SDF_setAConIntCon(SDF_ACon arg, SDF_IntCon IntCon);
ATbool SDF_hasAConRealCon(SDF_ACon arg);
SDF_RealCon SDF_getAConRealCon(SDF_ACon arg);
SDF_ACon SDF_setAConRealCon(SDF_ACon arg, SDF_RealCon RealCon);

/*}}}  */
/*{{{  SDF_AFun accessors */

ATbool SDF_isValidAFun(SDF_AFun arg);
inline ATbool SDF_isAFunDefault(SDF_AFun arg);
ATbool SDF_hasAFunLiteral(SDF_AFun arg);
SDF_Literal SDF_getAFunLiteral(SDF_AFun arg);
SDF_AFun SDF_setAFunLiteral(SDF_AFun arg, SDF_Literal Literal);

/*}}}  */
/*{{{  SDF_ATerm accessors */

ATbool SDF_isValidATerm(SDF_ATerm arg);
inline ATbool SDF_isATermConstant(SDF_ATerm arg);
inline ATbool SDF_isATermList(SDF_ATerm arg);
inline ATbool SDF_isATermFun(SDF_ATerm arg);
inline ATbool SDF_isATermAppl(SDF_ATerm arg);
inline ATbool SDF_isATermAnnotatedConstant(SDF_ATerm arg);
inline ATbool SDF_isATermAnnotatedList(SDF_ATerm arg);
inline ATbool SDF_isATermAnnotatedFun(SDF_ATerm arg);
inline ATbool SDF_isATermAnnotatedAppl(SDF_ATerm arg);
ATbool SDF_hasATermACon(SDF_ATerm arg);
SDF_ACon SDF_getATermACon(SDF_ATerm arg);
SDF_ATerm SDF_setATermACon(SDF_ATerm arg, SDF_ACon ACon);
ATbool SDF_hasATermList(SDF_ATerm arg);
SDF_ATermList SDF_getATermList(SDF_ATerm arg);
SDF_ATerm SDF_setATermList(SDF_ATerm arg, SDF_ATermList list);
ATbool SDF_hasATermFun(SDF_ATerm arg);
SDF_AFun SDF_getATermFun(SDF_ATerm arg);
SDF_ATerm SDF_setATermFun(SDF_ATerm arg, SDF_AFun fun);
ATbool SDF_hasATermWsAfterFun(SDF_ATerm arg);
SDF_OptLayout SDF_getATermWsAfterFun(SDF_ATerm arg);
SDF_ATerm SDF_setATermWsAfterFun(SDF_ATerm arg, SDF_OptLayout wsAfterFun);
ATbool SDF_hasATermWsAfterParenOpen(SDF_ATerm arg);
SDF_OptLayout SDF_getATermWsAfterParenOpen(SDF_ATerm arg);
SDF_ATerm SDF_setATermWsAfterParenOpen(SDF_ATerm arg, SDF_OptLayout wsAfterParenOpen);
ATbool SDF_hasATermArgs(SDF_ATerm arg);
SDF_ATermArgs SDF_getATermArgs(SDF_ATerm arg);
SDF_ATerm SDF_setATermArgs(SDF_ATerm arg, SDF_ATermArgs args);
ATbool SDF_hasATermWsAfterArgs(SDF_ATerm arg);
SDF_OptLayout SDF_getATermWsAfterArgs(SDF_ATerm arg);
SDF_ATerm SDF_setATermWsAfterArgs(SDF_ATerm arg, SDF_OptLayout wsAfterArgs);
ATbool SDF_hasATermWsAfterACon(SDF_ATerm arg);
SDF_OptLayout SDF_getATermWsAfterACon(SDF_ATerm arg);
SDF_ATerm SDF_setATermWsAfterACon(SDF_ATerm arg, SDF_OptLayout wsAfterACon);
ATbool SDF_hasATermAnn(SDF_ATerm arg);
SDF_Ann SDF_getATermAnn(SDF_ATerm arg);
SDF_ATerm SDF_setATermAnn(SDF_ATerm arg, SDF_Ann Ann);
ATbool SDF_hasATermWsAfterList(SDF_ATerm arg);
SDF_OptLayout SDF_getATermWsAfterList(SDF_ATerm arg);
SDF_ATerm SDF_setATermWsAfterList(SDF_ATerm arg, SDF_OptLayout wsAfterList);
ATbool SDF_hasATermWsAfterParenClose(SDF_ATerm arg);
SDF_OptLayout SDF_getATermWsAfterParenClose(SDF_ATerm arg);
SDF_ATerm SDF_setATermWsAfterParenClose(SDF_ATerm arg, SDF_OptLayout wsAfterParenClose);

/*}}}  */
/*{{{  SDF_ATermArgs accessors */

ATbool SDF_isValidATermArgs(SDF_ATermArgs arg);
inline ATbool SDF_isATermArgsSingle(SDF_ATermArgs arg);
inline ATbool SDF_isATermArgsMany(SDF_ATermArgs arg);
ATbool SDF_hasATermArgsHead(SDF_ATermArgs arg);
SDF_ATerm SDF_getATermArgsHead(SDF_ATermArgs arg);
SDF_ATermArgs SDF_setATermArgsHead(SDF_ATermArgs arg, SDF_ATerm head);
ATbool SDF_hasATermArgsWsAfterFirst(SDF_ATermArgs arg);
SDF_OptLayout SDF_getATermArgsWsAfterFirst(SDF_ATermArgs arg);
SDF_ATermArgs SDF_setATermArgsWsAfterFirst(SDF_ATermArgs arg, SDF_OptLayout wsAfterFirst);
ATbool SDF_hasATermArgsSep(SDF_ATermArgs arg);
char * SDF_getATermArgsSep(SDF_ATermArgs arg);
SDF_ATermArgs SDF_setATermArgsSep(SDF_ATermArgs arg, char * sep);
ATbool SDF_hasATermArgsWsAfterSep(SDF_ATermArgs arg);
SDF_OptLayout SDF_getATermArgsWsAfterSep(SDF_ATermArgs arg);
SDF_ATermArgs SDF_setATermArgsWsAfterSep(SDF_ATermArgs arg, SDF_OptLayout wsAfterSep);
ATbool SDF_hasATermArgsTail(SDF_ATermArgs arg);
SDF_ATermArgs SDF_getATermArgsTail(SDF_ATermArgs arg);
SDF_ATermArgs SDF_setATermArgsTail(SDF_ATermArgs arg, SDF_ATermArgs tail);

/*}}}  */
/*{{{  SDF_Ann accessors */

ATbool SDF_isValidAnn(SDF_Ann arg);
inline ATbool SDF_isAnnAnnotation(SDF_Ann arg);
ATbool SDF_hasAnnWsAfterBraceOpen(SDF_Ann arg);
SDF_OptLayout SDF_getAnnWsAfterBraceOpen(SDF_Ann arg);
SDF_Ann SDF_setAnnWsAfterBraceOpen(SDF_Ann arg, SDF_OptLayout wsAfterBraceOpen);
ATbool SDF_hasAnnAnnos(SDF_Ann arg);
SDF_ATermAnnos SDF_getAnnAnnos(SDF_Ann arg);
SDF_Ann SDF_setAnnAnnos(SDF_Ann arg, SDF_ATermAnnos annos);
ATbool SDF_hasAnnWsAfterAnnos(SDF_Ann arg);
SDF_OptLayout SDF_getAnnWsAfterAnnos(SDF_Ann arg);
SDF_Ann SDF_setAnnWsAfterAnnos(SDF_Ann arg, SDF_OptLayout wsAfterAnnos);

/*}}}  */
/*{{{  SDF_ATermAnnos accessors */

ATbool SDF_isValidATermAnnos(SDF_ATermAnnos arg);
inline ATbool SDF_isATermAnnosSingle(SDF_ATermAnnos arg);
inline ATbool SDF_isATermAnnosMany(SDF_ATermAnnos arg);
ATbool SDF_hasATermAnnosHead(SDF_ATermAnnos arg);
SDF_ATerm SDF_getATermAnnosHead(SDF_ATermAnnos arg);
SDF_ATermAnnos SDF_setATermAnnosHead(SDF_ATermAnnos arg, SDF_ATerm head);
ATbool SDF_hasATermAnnosWsAfterFirst(SDF_ATermAnnos arg);
SDF_OptLayout SDF_getATermAnnosWsAfterFirst(SDF_ATermAnnos arg);
SDF_ATermAnnos SDF_setATermAnnosWsAfterFirst(SDF_ATermAnnos arg, SDF_OptLayout wsAfterFirst);
ATbool SDF_hasATermAnnosSep(SDF_ATermAnnos arg);
char * SDF_getATermAnnosSep(SDF_ATermAnnos arg);
SDF_ATermAnnos SDF_setATermAnnosSep(SDF_ATermAnnos arg, char * sep);
ATbool SDF_hasATermAnnosWsAfterSep(SDF_ATermAnnos arg);
SDF_OptLayout SDF_getATermAnnosWsAfterSep(SDF_ATermAnnos arg);
SDF_ATermAnnos SDF_setATermAnnosWsAfterSep(SDF_ATermAnnos arg, SDF_OptLayout wsAfterSep);
ATbool SDF_hasATermAnnosTail(SDF_ATermAnnos arg);
SDF_ATermAnnos SDF_getATermAnnosTail(SDF_ATermAnnos arg);
SDF_ATermAnnos SDF_setATermAnnosTail(SDF_ATermAnnos arg, SDF_ATermAnnos tail);

/*}}}  */
/*{{{  SDF_Attributes accessors */

ATbool SDF_isValidAttributes(SDF_Attributes arg);
inline ATbool SDF_isAttributesAttrs(SDF_Attributes arg);
inline ATbool SDF_isAttributesNoAttrs(SDF_Attributes arg);
ATbool SDF_hasAttributesWsAfterBraceOpen(SDF_Attributes arg);
SDF_OptLayout SDF_getAttributesWsAfterBraceOpen(SDF_Attributes arg);
SDF_Attributes SDF_setAttributesWsAfterBraceOpen(SDF_Attributes arg, SDF_OptLayout wsAfterBraceOpen);
ATbool SDF_hasAttributesList(SDF_Attributes arg);
SDF_AttributeList SDF_getAttributesList(SDF_Attributes arg);
SDF_Attributes SDF_setAttributesList(SDF_Attributes arg, SDF_AttributeList list);
ATbool SDF_hasAttributesWsAfterList(SDF_Attributes arg);
SDF_OptLayout SDF_getAttributesWsAfterList(SDF_Attributes arg);
SDF_Attributes SDF_setAttributesWsAfterList(SDF_Attributes arg, SDF_OptLayout wsAfterList);

/*}}}  */
/*{{{  SDF_AttributeList accessors */

ATbool SDF_isValidAttributeList(SDF_AttributeList arg);
inline ATbool SDF_isAttributeListEmpty(SDF_AttributeList arg);
inline ATbool SDF_isAttributeListSingle(SDF_AttributeList arg);
inline ATbool SDF_isAttributeListMany(SDF_AttributeList arg);
ATbool SDF_hasAttributeListHead(SDF_AttributeList arg);
SDF_Attribute SDF_getAttributeListHead(SDF_AttributeList arg);
SDF_AttributeList SDF_setAttributeListHead(SDF_AttributeList arg, SDF_Attribute head);
ATbool SDF_hasAttributeListWsAfterFirst(SDF_AttributeList arg);
SDF_OptLayout SDF_getAttributeListWsAfterFirst(SDF_AttributeList arg);
SDF_AttributeList SDF_setAttributeListWsAfterFirst(SDF_AttributeList arg, SDF_OptLayout wsAfterFirst);
ATbool SDF_hasAttributeListSep(SDF_AttributeList arg);
char * SDF_getAttributeListSep(SDF_AttributeList arg);
SDF_AttributeList SDF_setAttributeListSep(SDF_AttributeList arg, char * sep);
ATbool SDF_hasAttributeListWsAfterSep(SDF_AttributeList arg);
SDF_OptLayout SDF_getAttributeListWsAfterSep(SDF_AttributeList arg);
SDF_AttributeList SDF_setAttributeListWsAfterSep(SDF_AttributeList arg, SDF_OptLayout wsAfterSep);
ATbool SDF_hasAttributeListTail(SDF_AttributeList arg);
SDF_AttributeList SDF_getAttributeListTail(SDF_AttributeList arg);
SDF_AttributeList SDF_setAttributeListTail(SDF_AttributeList arg, SDF_AttributeList tail);

/*}}}  */
/*{{{  SDF_Productions accessors */

ATbool SDF_isValidProductions(SDF_Productions arg);
inline ATbool SDF_isProductionsDefault(SDF_Productions arg);
ATbool SDF_hasProductionsList(SDF_Productions arg);
SDF_ProductionList SDF_getProductionsList(SDF_Productions arg);
SDF_Productions SDF_setProductionsList(SDF_Productions arg, SDF_ProductionList list);

/*}}}  */
/*{{{  SDF_ProductionList accessors */

ATbool SDF_isValidProductionList(SDF_ProductionList arg);
inline ATbool SDF_isProductionListEmpty(SDF_ProductionList arg);
inline ATbool SDF_isProductionListSingle(SDF_ProductionList arg);
inline ATbool SDF_isProductionListMany(SDF_ProductionList arg);
ATbool SDF_hasProductionListHead(SDF_ProductionList arg);
SDF_Production SDF_getProductionListHead(SDF_ProductionList arg);
SDF_ProductionList SDF_setProductionListHead(SDF_ProductionList arg, SDF_Production head);
ATbool SDF_hasProductionListWsAfterFirst(SDF_ProductionList arg);
SDF_OptLayout SDF_getProductionListWsAfterFirst(SDF_ProductionList arg);
SDF_ProductionList SDF_setProductionListWsAfterFirst(SDF_ProductionList arg, SDF_OptLayout wsAfterFirst);
ATbool SDF_hasProductionListTail(SDF_ProductionList arg);
SDF_ProductionList SDF_getProductionListTail(SDF_ProductionList arg);
SDF_ProductionList SDF_setProductionListTail(SDF_ProductionList arg, SDF_ProductionList tail);

/*}}}  */
/*{{{  SDF_SDF accessors */

ATbool SDF_isValidSDF(SDF_SDF arg);
inline ATbool SDF_isSDFDefinition(SDF_SDF arg);
ATbool SDF_hasSDFWsAfterDefinition(SDF_SDF arg);
SDF_OptLayout SDF_getSDFWsAfterDefinition(SDF_SDF arg);
SDF_SDF SDF_setSDFWsAfterDefinition(SDF_SDF arg, SDF_OptLayout wsAfterDefinition);
ATbool SDF_hasSDFDefinition(SDF_SDF arg);
SDF_Definition SDF_getSDFDefinition(SDF_SDF arg);
SDF_SDF SDF_setSDFDefinition(SDF_SDF arg, SDF_Definition Definition);

/*}}}  */
/*{{{  SDF_OptLayout accessors */

ATbool SDF_isValidOptLayout(SDF_OptLayout arg);
inline ATbool SDF_isOptLayoutAbsent(SDF_OptLayout arg);
inline ATbool SDF_isOptLayoutPresent(SDF_OptLayout arg);
ATbool SDF_hasOptLayoutChars(SDF_OptLayout arg);
SDF_CHARLIST SDF_getOptLayoutChars(SDF_OptLayout arg);
SDF_OptLayout SDF_setOptLayoutChars(SDF_OptLayout arg, SDF_CHARLIST chars);

/*}}}  */
/*{{{  SDF_Start accessors */

ATbool SDF_isValidStart(SDF_Start arg);
inline ATbool SDF_isStartSDF(SDF_Start arg);
inline ATbool SDF_isStartProductions(SDF_Start arg);
inline ATbool SDF_isStartProduction(SDF_Start arg);
inline ATbool SDF_isStartAttributes(SDF_Start arg);
inline ATbool SDF_isStartAttribute(SDF_Start arg);
inline ATbool SDF_isStartAnn(SDF_Start arg);
inline ATbool SDF_isStartATerm(SDF_Start arg);
inline ATbool SDF_isStartAFun(SDF_Start arg);
inline ATbool SDF_isStartACon(SDF_Start arg);
inline ATbool SDF_isStartATermList(SDF_Start arg);
inline ATbool SDF_isStartQLiteral(SDF_Start arg);
inline ATbool SDF_isStartUQLiteral(SDF_Start arg);
inline ATbool SDF_isStartLiteral(SDF_Start arg);
inline ATbool SDF_isStartIntCon(SDF_Start arg);
inline ATbool SDF_isStartNatCon(SDF_Start arg);
inline ATbool SDF_isStartRealCon(SDF_Start arg);
inline ATbool SDF_isStartOptExp(SDF_Start arg);
inline ATbool SDF_isStartSymbols(SDF_Start arg);
inline ATbool SDF_isStartSymbol(SDF_Start arg);
inline ATbool SDF_isStartGrammar(SDF_Start arg);
inline ATbool SDF_isStartImpSection(SDF_Start arg);
inline ATbool SDF_isStartDefinition(SDF_Start arg);
inline ATbool SDF_isStartModule(SDF_Start arg);
inline ATbool SDF_isStartSections(SDF_Start arg);
inline ATbool SDF_isStartSection(SDF_Start arg);
inline ATbool SDF_isStartImports(SDF_Start arg);
inline ATbool SDF_isStartImport(SDF_Start arg);
inline ATbool SDF_isStartModuleName(SDF_Start arg);
inline ATbool SDF_isStartModuleId(SDF_Start arg);
inline ATbool SDF_isStartRenamings(SDF_Start arg);
inline ATbool SDF_isStartRenaming(SDF_Start arg);
inline ATbool SDF_isStartPriorities(SDF_Start arg);
inline ATbool SDF_isStartPriority(SDF_Start arg);
inline ATbool SDF_isStartGroup(SDF_Start arg);
inline ATbool SDF_isStartAssociativity(SDF_Start arg);
inline ATbool SDF_isStartCharClass(SDF_Start arg);
inline ATbool SDF_isStartShortChar(SDF_Start arg);
inline ATbool SDF_isStartNumChar(SDF_Start arg);
inline ATbool SDF_isStartCharacter(SDF_Start arg);
inline ATbool SDF_isStartSort(SDF_Start arg);
inline ATbool SDF_isStartRestrictions(SDF_Start arg);
inline ATbool SDF_isStartRestriction(SDF_Start arg);
inline ATbool SDF_isStartLookaheads(SDF_Start arg);
inline ATbool SDF_isStartLookahead(SDF_Start arg);
inline ATbool SDF_isStartAliases(SDF_Start arg);
inline ATbool SDF_isStartAlias(SDF_Start arg);
ATbool SDF_hasStartWsBefore(SDF_Start arg);
SDF_OptLayout SDF_getStartWsBefore(SDF_Start arg);
SDF_Start SDF_setStartWsBefore(SDF_Start arg, SDF_OptLayout wsBefore);
ATbool SDF_hasStartTopSDF(SDF_Start arg);
SDF_SDF SDF_getStartTopSDF(SDF_Start arg);
SDF_Start SDF_setStartTopSDF(SDF_Start arg, SDF_SDF topSDF);
ATbool SDF_hasStartWsAfter(SDF_Start arg);
SDF_OptLayout SDF_getStartWsAfter(SDF_Start arg);
SDF_Start SDF_setStartWsAfter(SDF_Start arg, SDF_OptLayout wsAfter);
ATbool SDF_hasStartAmbCnt(SDF_Start arg);
int SDF_getStartAmbCnt(SDF_Start arg);
SDF_Start SDF_setStartAmbCnt(SDF_Start arg, int ambCnt);
ATbool SDF_hasStartTopProductions(SDF_Start arg);
SDF_Productions SDF_getStartTopProductions(SDF_Start arg);
SDF_Start SDF_setStartTopProductions(SDF_Start arg, SDF_Productions topProductions);
ATbool SDF_hasStartTopProduction(SDF_Start arg);
SDF_Production SDF_getStartTopProduction(SDF_Start arg);
SDF_Start SDF_setStartTopProduction(SDF_Start arg, SDF_Production topProduction);
ATbool SDF_hasStartTopAttributes(SDF_Start arg);
SDF_Attributes SDF_getStartTopAttributes(SDF_Start arg);
SDF_Start SDF_setStartTopAttributes(SDF_Start arg, SDF_Attributes topAttributes);
ATbool SDF_hasStartTopAttribute(SDF_Start arg);
SDF_Attribute SDF_getStartTopAttribute(SDF_Start arg);
SDF_Start SDF_setStartTopAttribute(SDF_Start arg, SDF_Attribute topAttribute);
ATbool SDF_hasStartTopAnn(SDF_Start arg);
SDF_Ann SDF_getStartTopAnn(SDF_Start arg);
SDF_Start SDF_setStartTopAnn(SDF_Start arg, SDF_Ann topAnn);
ATbool SDF_hasStartTopATerm(SDF_Start arg);
SDF_ATerm SDF_getStartTopATerm(SDF_Start arg);
SDF_Start SDF_setStartTopATerm(SDF_Start arg, SDF_ATerm topATerm);
ATbool SDF_hasStartTopAFun(SDF_Start arg);
SDF_AFun SDF_getStartTopAFun(SDF_Start arg);
SDF_Start SDF_setStartTopAFun(SDF_Start arg, SDF_AFun topAFun);
ATbool SDF_hasStartTopACon(SDF_Start arg);
SDF_ACon SDF_getStartTopACon(SDF_Start arg);
SDF_Start SDF_setStartTopACon(SDF_Start arg, SDF_ACon topACon);
ATbool SDF_hasStartTopATermList(SDF_Start arg);
SDF_ATermList SDF_getStartTopATermList(SDF_Start arg);
SDF_Start SDF_setStartTopATermList(SDF_Start arg, SDF_ATermList topATermList);
ATbool SDF_hasStartTopQLiteral(SDF_Start arg);
SDF_QLiteral SDF_getStartTopQLiteral(SDF_Start arg);
SDF_Start SDF_setStartTopQLiteral(SDF_Start arg, SDF_QLiteral topQLiteral);
ATbool SDF_hasStartTopUQLiteral(SDF_Start arg);
SDF_UQLiteral SDF_getStartTopUQLiteral(SDF_Start arg);
SDF_Start SDF_setStartTopUQLiteral(SDF_Start arg, SDF_UQLiteral topUQLiteral);
ATbool SDF_hasStartTopLiteral(SDF_Start arg);
SDF_Literal SDF_getStartTopLiteral(SDF_Start arg);
SDF_Start SDF_setStartTopLiteral(SDF_Start arg, SDF_Literal topLiteral);
ATbool SDF_hasStartTopIntCon(SDF_Start arg);
SDF_IntCon SDF_getStartTopIntCon(SDF_Start arg);
SDF_Start SDF_setStartTopIntCon(SDF_Start arg, SDF_IntCon topIntCon);
ATbool SDF_hasStartTopNatCon(SDF_Start arg);
SDF_NatCon SDF_getStartTopNatCon(SDF_Start arg);
SDF_Start SDF_setStartTopNatCon(SDF_Start arg, SDF_NatCon topNatCon);
ATbool SDF_hasStartTopRealCon(SDF_Start arg);
SDF_RealCon SDF_getStartTopRealCon(SDF_Start arg);
SDF_Start SDF_setStartTopRealCon(SDF_Start arg, SDF_RealCon topRealCon);
ATbool SDF_hasStartTopOptExp(SDF_Start arg);
SDF_OptExp SDF_getStartTopOptExp(SDF_Start arg);
SDF_Start SDF_setStartTopOptExp(SDF_Start arg, SDF_OptExp topOptExp);
ATbool SDF_hasStartTopSymbols(SDF_Start arg);
SDF_Symbols SDF_getStartTopSymbols(SDF_Start arg);
SDF_Start SDF_setStartTopSymbols(SDF_Start arg, SDF_Symbols topSymbols);
ATbool SDF_hasStartTopSymbol(SDF_Start arg);
SDF_Symbol SDF_getStartTopSymbol(SDF_Start arg);
SDF_Start SDF_setStartTopSymbol(SDF_Start arg, SDF_Symbol topSymbol);
ATbool SDF_hasStartTopGrammar(SDF_Start arg);
SDF_Grammar SDF_getStartTopGrammar(SDF_Start arg);
SDF_Start SDF_setStartTopGrammar(SDF_Start arg, SDF_Grammar topGrammar);
ATbool SDF_hasStartTopImpSection(SDF_Start arg);
SDF_ImpSection SDF_getStartTopImpSection(SDF_Start arg);
SDF_Start SDF_setStartTopImpSection(SDF_Start arg, SDF_ImpSection topImpSection);
ATbool SDF_hasStartTopDefinition(SDF_Start arg);
SDF_Definition SDF_getStartTopDefinition(SDF_Start arg);
SDF_Start SDF_setStartTopDefinition(SDF_Start arg, SDF_Definition topDefinition);
ATbool SDF_hasStartTopModule(SDF_Start arg);
SDF_Module SDF_getStartTopModule(SDF_Start arg);
SDF_Start SDF_setStartTopModule(SDF_Start arg, SDF_Module topModule);
ATbool SDF_hasStartTopSections(SDF_Start arg);
SDF_Sections SDF_getStartTopSections(SDF_Start arg);
SDF_Start SDF_setStartTopSections(SDF_Start arg, SDF_Sections topSections);
ATbool SDF_hasStartTopSection(SDF_Start arg);
SDF_Section SDF_getStartTopSection(SDF_Start arg);
SDF_Start SDF_setStartTopSection(SDF_Start arg, SDF_Section topSection);
ATbool SDF_hasStartTopImports(SDF_Start arg);
SDF_Imports SDF_getStartTopImports(SDF_Start arg);
SDF_Start SDF_setStartTopImports(SDF_Start arg, SDF_Imports topImports);
ATbool SDF_hasStartTopImport(SDF_Start arg);
SDF_Import SDF_getStartTopImport(SDF_Start arg);
SDF_Start SDF_setStartTopImport(SDF_Start arg, SDF_Import topImport);
ATbool SDF_hasStartTopModuleName(SDF_Start arg);
SDF_ModuleName SDF_getStartTopModuleName(SDF_Start arg);
SDF_Start SDF_setStartTopModuleName(SDF_Start arg, SDF_ModuleName topModuleName);
ATbool SDF_hasStartTopModuleId(SDF_Start arg);
SDF_ModuleId SDF_getStartTopModuleId(SDF_Start arg);
SDF_Start SDF_setStartTopModuleId(SDF_Start arg, SDF_ModuleId topModuleId);
ATbool SDF_hasStartTopRenamings(SDF_Start arg);
SDF_Renamings SDF_getStartTopRenamings(SDF_Start arg);
SDF_Start SDF_setStartTopRenamings(SDF_Start arg, SDF_Renamings topRenamings);
ATbool SDF_hasStartTopRenaming(SDF_Start arg);
SDF_Renaming SDF_getStartTopRenaming(SDF_Start arg);
SDF_Start SDF_setStartTopRenaming(SDF_Start arg, SDF_Renaming topRenaming);
ATbool SDF_hasStartTopPriorities(SDF_Start arg);
SDF_Priorities SDF_getStartTopPriorities(SDF_Start arg);
SDF_Start SDF_setStartTopPriorities(SDF_Start arg, SDF_Priorities topPriorities);
ATbool SDF_hasStartTopPriority(SDF_Start arg);
SDF_Priority SDF_getStartTopPriority(SDF_Start arg);
SDF_Start SDF_setStartTopPriority(SDF_Start arg, SDF_Priority topPriority);
ATbool SDF_hasStartTopGroup(SDF_Start arg);
SDF_Group SDF_getStartTopGroup(SDF_Start arg);
SDF_Start SDF_setStartTopGroup(SDF_Start arg, SDF_Group topGroup);
ATbool SDF_hasStartTopAssociativity(SDF_Start arg);
SDF_Associativity SDF_getStartTopAssociativity(SDF_Start arg);
SDF_Start SDF_setStartTopAssociativity(SDF_Start arg, SDF_Associativity topAssociativity);
ATbool SDF_hasStartTopCharClass(SDF_Start arg);
SDF_CharClass SDF_getStartTopCharClass(SDF_Start arg);
SDF_Start SDF_setStartTopCharClass(SDF_Start arg, SDF_CharClass topCharClass);
ATbool SDF_hasStartTopShortChar(SDF_Start arg);
SDF_ShortChar SDF_getStartTopShortChar(SDF_Start arg);
SDF_Start SDF_setStartTopShortChar(SDF_Start arg, SDF_ShortChar topShortChar);
ATbool SDF_hasStartTopNumChar(SDF_Start arg);
SDF_NumChar SDF_getStartTopNumChar(SDF_Start arg);
SDF_Start SDF_setStartTopNumChar(SDF_Start arg, SDF_NumChar topNumChar);
ATbool SDF_hasStartTopCharacter(SDF_Start arg);
SDF_Character SDF_getStartTopCharacter(SDF_Start arg);
SDF_Start SDF_setStartTopCharacter(SDF_Start arg, SDF_Character topCharacter);
ATbool SDF_hasStartTopSort(SDF_Start arg);
SDF_Sort SDF_getStartTopSort(SDF_Start arg);
SDF_Start SDF_setStartTopSort(SDF_Start arg, SDF_Sort topSort);
ATbool SDF_hasStartTopRestrictions(SDF_Start arg);
SDF_Restrictions SDF_getStartTopRestrictions(SDF_Start arg);
SDF_Start SDF_setStartTopRestrictions(SDF_Start arg, SDF_Restrictions topRestrictions);
ATbool SDF_hasStartTopRestriction(SDF_Start arg);
SDF_Restriction SDF_getStartTopRestriction(SDF_Start arg);
SDF_Start SDF_setStartTopRestriction(SDF_Start arg, SDF_Restriction topRestriction);
ATbool SDF_hasStartTopLookaheads(SDF_Start arg);
SDF_Lookaheads SDF_getStartTopLookaheads(SDF_Start arg);
SDF_Start SDF_setStartTopLookaheads(SDF_Start arg, SDF_Lookaheads topLookaheads);
ATbool SDF_hasStartTopLookahead(SDF_Start arg);
SDF_Lookahead SDF_getStartTopLookahead(SDF_Start arg);
SDF_Start SDF_setStartTopLookahead(SDF_Start arg, SDF_Lookahead topLookahead);
ATbool SDF_hasStartTopAliases(SDF_Start arg);
SDF_Aliases SDF_getStartTopAliases(SDF_Start arg);
SDF_Start SDF_setStartTopAliases(SDF_Start arg, SDF_Aliases topAliases);
ATbool SDF_hasStartTopAlias(SDF_Start arg);
SDF_Alias SDF_getStartTopAlias(SDF_Start arg);
SDF_Start SDF_setStartTopAlias(SDF_Start arg, SDF_Alias topAlias);

/*}}}  */
/*{{{  sort visitors */

SDF_Grammar SDF_visitGrammar(SDF_Grammar arg, SDF_OptLayout (*acceptWsAfterAliases)(SDF_OptLayout), SDF_Aliases (*acceptAliases)(SDF_Aliases), SDF_OptLayout (*acceptWsAfterRestrictions)(SDF_OptLayout), SDF_Restrictions (*acceptRestrictions)(SDF_Restrictions), SDF_OptLayout (*acceptWsAfterStartSymbols)(SDF_OptLayout), SDF_Symbols (*acceptSymbols)(SDF_Symbols), SDF_OptLayout (*acceptWsAfterLexical)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterContextFree)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterSorts)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterPriorities)(SDF_OptLayout), SDF_Priorities (*acceptPriorities)(SDF_Priorities), SDF_ImpSection (*acceptImpSection)(SDF_ImpSection), SDF_OptLayout (*acceptWsAfterSyntax)(SDF_OptLayout), SDF_Productions (*acceptProductions)(SDF_Productions), SDF_OptLayout (*acceptWsAfterVariables)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterLeft)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterGrammar)(SDF_OptLayout));
SDF_Alias SDF_visitAlias(SDF_Alias arg, SDF_Symbol (*acceptSymbol)(SDF_Symbol), SDF_OptLayout (*acceptWsAfterSymbol)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterArrow)(SDF_OptLayout), SDF_Symbol (*acceptAlias)(SDF_Symbol));
SDF_Aliases SDF_visitAliases(SDF_Aliases arg, SDF_AliasList (*acceptList)(SDF_AliasList));
SDF_AliasList SDF_visitAliasList(SDF_AliasList arg, SDF_Alias (*acceptHead)(SDF_Alias), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout));
SDF_Lookahead SDF_visitLookahead(SDF_Lookahead arg, SDF_CharClass (*acceptCharClass)(SDF_CharClass), SDF_CharClass (*acceptHead)(SDF_CharClass), SDF_OptLayout (*acceptWsAfterHead)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterPeriod)(SDF_OptLayout), SDF_Lookaheads (*acceptTail)(SDF_Lookaheads));
SDF_Lookaheads SDF_visitLookaheads(SDF_Lookaheads arg, SDF_Lookahead (*acceptLookahead)(SDF_Lookahead), SDF_OptLayout (*acceptWsAfterLeft)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterBar)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterLookaheads)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterBracketOpenBracketOpen)(SDF_OptLayout), SDF_LookaheadList (*acceptList)(SDF_LookaheadList), SDF_OptLayout (*acceptWsAfterList)(SDF_OptLayout));
SDF_LookaheadList SDF_visitLookaheadList(SDF_LookaheadList arg, SDF_Lookahead (*acceptHead)(SDF_Lookahead), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout));
SDF_Restriction SDF_visitRestriction(SDF_Restriction arg, SDF_Symbols (*acceptSymbols)(SDF_Symbols), SDF_OptLayout (*acceptWsAfterSymbols)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterSlash)(SDF_OptLayout), SDF_Lookaheads (*acceptLookaheads)(SDF_Lookaheads));
SDF_Restrictions SDF_visitRestrictions(SDF_Restrictions arg, SDF_RestrictionList (*acceptList)(SDF_RestrictionList));
SDF_RestrictionList SDF_visitRestrictionList(SDF_RestrictionList arg, SDF_Restriction (*acceptHead)(SDF_Restriction), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout));
SDF_Attribute SDF_visitAttribute(SDF_Attribute arg, SDF_Associativity (*acceptAssociativity)(SDF_Associativity), SDF_OptLayout (*acceptWsAfterId)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_ModuleName (*acceptModuleName)(SDF_ModuleName), SDF_OptLayout (*acceptWsAfterModuleName)(SDF_OptLayout), SDF_ATerm (*acceptAterm)(SDF_ATerm));
SDF_Symbol SDF_visitSymbol(SDF_Symbol arg, SDF_Literal (*acceptLabel)(SDF_Literal), SDF_OptLayout (*acceptWsAfterLabel)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterColon)(SDF_OptLayout), SDF_Literal (*acceptLiteral)(SDF_Literal), SDF_Sort (*acceptSort)(SDF_Sort), SDF_OptLayout (*acceptWsAfterSort)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterBracketOpenBracketOpen)(SDF_OptLayout), SDF_SymbolParameters (*acceptParameters)(SDF_SymbolParameters), SDF_OptLayout (*acceptWsAfterParameters)(SDF_OptLayout), SDF_CharClass (*acceptCharClass)(SDF_CharClass), SDF_OptLayout (*acceptWsAfterLeftQuote)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterSymbol)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterHead)(SDF_OptLayout), SDF_SymbolTail (*acceptTail)(SDF_SymbolTail), SDF_OptLayout (*acceptWsAfterTail)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterBraceOpen)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterBraceClose)(SDF_OptLayout), SDF_NatCon (*acceptN)(SDF_NatCon), SDF_OptLayout (*acceptWsAfterN)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterLessThan)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterComma)(SDF_OptLayout), SDF_SymbolRest (*acceptRest)(SDF_SymbolRest), SDF_OptLayout (*acceptWsAfterRest)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterLeft)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterHash)(SDF_OptLayout), SDF_Symbols (*acceptArguments)(SDF_Symbols), SDF_OptLayout (*acceptWsAfterArguments)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterEqualsGreaterThan)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterResults)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterBar)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterGreaterThan)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterRight)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterCF)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterLEX)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterVAR)(SDF_OptLayout));
SDF_Production SDF_visitProduction(SDF_Production arg, SDF_Literal (*acceptFunctionSymbol)(SDF_Literal), SDF_OptLayout (*acceptWsAfterFunctionSymbol)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_SymbolArguments (*acceptArguments)(SDF_SymbolArguments), SDF_OptLayout (*acceptWsAfterArguments)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenClose)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterGreaterThan)(SDF_OptLayout), SDF_Symbol (*acceptResult)(SDF_Symbol), SDF_OptLayout (*acceptWsAfterResult)(SDF_OptLayout), SDF_Attributes (*acceptAttributes)(SDF_Attributes), SDF_Symbols (*acceptSymbols)(SDF_Symbols), SDF_OptLayout (*acceptWsAfterSymbols)(SDF_OptLayout));
SDF_SymbolArguments SDF_visitSymbolArguments(SDF_SymbolArguments arg, SDF_Symbol (*acceptHead)(SDF_Symbol), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout));
SDF_Sort SDF_visitSort(SDF_Sort arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST));
SDF_SymbolParameters SDF_visitSymbolParameters(SDF_SymbolParameters arg, SDF_Symbol (*acceptHead)(SDF_Symbol), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout));
SDF_NumChar SDF_visitNumChar(SDF_NumChar arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST));
SDF_ShortChar SDF_visitShortChar(SDF_ShortChar arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST));
SDF_Character SDF_visitCharacter(SDF_Character arg, SDF_NumChar (*acceptNumChar)(SDF_NumChar), SDF_ShortChar (*acceptShortChar)(SDF_ShortChar));
SDF_CharRange SDF_visitCharRange(SDF_CharRange arg, SDF_Character (*acceptCharacter)(SDF_Character), SDF_Character (*acceptStart)(SDF_Character), SDF_OptLayout (*acceptWsAfterStart)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfter)(SDF_OptLayout), SDF_Character (*acceptEnd)(SDF_Character));
SDF_CharRanges SDF_visitCharRanges(SDF_CharRanges arg, SDF_CharRange (*acceptCharRange)(SDF_CharRange), SDF_OptLayout (*acceptWsAfterLeft)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterCharRanges)(SDF_OptLayout));
SDF_OptCharRanges SDF_visitOptCharRanges(SDF_OptCharRanges arg, SDF_CharRanges (*acceptCharRanges)(SDF_CharRanges));
SDF_CharClass SDF_visitCharClass(SDF_CharClass arg, SDF_OptLayout (*acceptWsAfterBracketOpen)(SDF_OptLayout), SDF_OptCharRanges (*acceptOptCharRanges)(SDF_OptCharRanges), SDF_OptLayout (*acceptWsAfterOptCharRanges)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterTilde)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterLeft)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterSlash)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterSlashBackslash)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterBackslashSlash)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterCharClass)(SDF_OptLayout));
SDF_Associativity SDF_visitAssociativity(SDF_Associativity arg);
SDF_Group SDF_visitGroup(SDF_Group arg, SDF_Production (*acceptProduction)(SDF_Production), SDF_OptLayout (*acceptWsAfterBraceOpen)(SDF_OptLayout), SDF_Productions (*acceptProductions)(SDF_Productions), SDF_OptLayout (*acceptWsAfterProductions)(SDF_OptLayout), SDF_Associativity (*acceptAssociativity)(SDF_Associativity), SDF_OptLayout (*acceptWsAfterAssociativity)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterColon)(SDF_OptLayout));
SDF_Priority SDF_visitPriority(SDF_Priority arg, SDF_GroupList (*acceptList)(SDF_GroupList), SDF_Group (*acceptLeft)(SDF_Group), SDF_OptLayout (*acceptWsAfterLeft)(SDF_OptLayout), SDF_Associativity (*acceptAssociativity)(SDF_Associativity), SDF_OptLayout (*acceptWsAfterAssociativity)(SDF_OptLayout), SDF_Group (*acceptRight)(SDF_Group));
SDF_GroupList SDF_visitGroupList(SDF_GroupList arg, SDF_Group (*acceptHead)(SDF_Group), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout));
SDF_Priorities SDF_visitPriorities(SDF_Priorities arg, SDF_PriorityList (*acceptList)(SDF_PriorityList));
SDF_PriorityList SDF_visitPriorityList(SDF_PriorityList arg, SDF_Priority (*acceptHead)(SDF_Priority), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout));
SDF_SymbolTail SDF_visitSymbolTail(SDF_SymbolTail arg, SDF_Symbol (*acceptHead)(SDF_Symbol), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout));
SDF_SymbolRest SDF_visitSymbolRest(SDF_SymbolRest arg, SDF_Symbol (*acceptHead)(SDF_Symbol), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout));
SDF_Renamings SDF_visitRenamings(SDF_Renamings arg, SDF_OptLayout (*acceptWsAfterBracketOpen)(SDF_OptLayout), SDF_RenamingList (*acceptList)(SDF_RenamingList), SDF_OptLayout (*acceptWsAfterList)(SDF_OptLayout));
SDF_RenamingList SDF_visitRenamingList(SDF_RenamingList arg, SDF_Renaming (*acceptHead)(SDF_Renaming), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout));
SDF_Renaming SDF_visitRenaming(SDF_Renaming arg, SDF_Symbol (*acceptFrom)(SDF_Symbol), SDF_OptLayout (*acceptWsAfterFrom)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterEqualsGreaterThan)(SDF_OptLayout), SDF_Symbol (*acceptTo)(SDF_Symbol), SDF_Production (*acceptFromProd)(SDF_Production), SDF_OptLayout (*acceptWsAfterFromProd)(SDF_OptLayout), SDF_Production (*acceptToProd)(SDF_Production));
SDF_ModuleWord SDF_visitModuleWord(SDF_ModuleWord arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST));
SDF_ModuleId SDF_visitModuleId(SDF_ModuleId arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST));
SDF_Definition SDF_visitDefinition(SDF_Definition arg, SDF_ModuleList (*acceptList)(SDF_ModuleList));
SDF_ModuleList SDF_visitModuleList(SDF_ModuleList arg, SDF_Module (*acceptHead)(SDF_Module), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout));
SDF_Module SDF_visitModule(SDF_Module arg, SDF_OptLayout (*acceptWsAfterModule)(SDF_OptLayout), SDF_ModuleName (*acceptModuleName)(SDF_ModuleName), SDF_OptLayout (*acceptWsAfterModuleName)(SDF_OptLayout), SDF_ImpSectionList (*acceptList)(SDF_ImpSectionList), SDF_OptLayout (*acceptWsAfterList)(SDF_OptLayout), SDF_Sections (*acceptSections)(SDF_Sections));
SDF_ImpSectionList SDF_visitImpSectionList(SDF_ImpSectionList arg, SDF_ImpSection (*acceptHead)(SDF_ImpSection), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout));
SDF_Section SDF_visitSection(SDF_Section arg, SDF_OptLayout (*acceptWsAfterExports)(SDF_OptLayout), SDF_Grammar (*acceptGrammar)(SDF_Grammar), SDF_OptLayout (*acceptWsAfterHiddens)(SDF_OptLayout));
SDF_Sections SDF_visitSections(SDF_Sections arg, SDF_SectionList (*acceptList)(SDF_SectionList));
SDF_SectionList SDF_visitSectionList(SDF_SectionList arg, SDF_Section (*acceptHead)(SDF_Section), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout));
SDF_ModuleName SDF_visitModuleName(SDF_ModuleName arg, SDF_ModuleId (*acceptModuleId)(SDF_ModuleId), SDF_OptLayout (*acceptWsAfterModuleId)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterBracketOpen)(SDF_OptLayout), SDF_Symbols (*acceptParams)(SDF_Symbols), SDF_OptLayout (*acceptWsAfterParams)(SDF_OptLayout));
SDF_ImpSection SDF_visitImpSection(SDF_ImpSection arg, SDF_OptLayout (*acceptWsAfterImports)(SDF_OptLayout), SDF_Imports (*acceptList)(SDF_Imports));
SDF_Imports SDF_visitImports(SDF_Imports arg, SDF_ImportList (*acceptList)(SDF_ImportList));
SDF_ImportList SDF_visitImportList(SDF_ImportList arg, SDF_Import (*acceptHead)(SDF_Import), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout));
SDF_Import SDF_visitImport(SDF_Import arg, SDF_ModuleName (*acceptModuleName)(SDF_ModuleName), SDF_OptLayout (*acceptWsAfterModuleName)(SDF_OptLayout), SDF_Renamings (*acceptRenamings)(SDF_Renamings), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterImport)(SDF_OptLayout));
SDF_Symbols SDF_visitSymbols(SDF_Symbols arg, SDF_SymbolList (*acceptList)(SDF_SymbolList));
SDF_SymbolList SDF_visitSymbolList(SDF_SymbolList arg, SDF_Symbol (*acceptHead)(SDF_Symbol), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout));
SDF_OptExp SDF_visitOptExp(SDF_OptExp arg, SDF_OptLayout (*acceptWsAfterE)(SDF_OptLayout), SDF_IntCon (*acceptIntCon)(SDF_IntCon));
SDF_RealCon SDF_visitRealCon(SDF_RealCon arg, SDF_IntCon (*acceptIntCon)(SDF_IntCon), SDF_OptLayout (*acceptWsAfterIntCon)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterPeriod)(SDF_OptLayout), SDF_NatCon (*acceptNatCon)(SDF_NatCon), SDF_OptLayout (*acceptWsAfterNatCon)(SDF_OptLayout), SDF_OptExp (*acceptOptExp)(SDF_OptExp));
SDF_NatCon SDF_visitNatCon(SDF_NatCon arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST));
SDF_IntCon SDF_visitIntCon(SDF_IntCon arg, SDF_NatCon (*acceptNatCon)(SDF_NatCon), SDF_OptLayout (*acceptWsAfterPos)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterNeg)(SDF_OptLayout));
SDF_AlphaNumericalEscChar SDF_visitAlphaNumericalEscChar(SDF_AlphaNumericalEscChar arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST));
SDF_DecimalEscChar SDF_visitDecimalEscChar(SDF_DecimalEscChar arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST));
SDF_EscChar SDF_visitEscChar(SDF_EscChar arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST));
SDF_LChar SDF_visitLChar(SDF_LChar arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST));
SDF_QLiteral SDF_visitQLiteral(SDF_QLiteral arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST));
SDF_UQLiteral SDF_visitUQLiteral(SDF_UQLiteral arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST));
SDF_Literal SDF_visitLiteral(SDF_Literal arg, SDF_QLiteral (*acceptQLiteral)(SDF_QLiteral), SDF_UQLiteral (*acceptUQLiteral)(SDF_UQLiteral));
SDF_ATermList SDF_visitATermList(SDF_ATermList arg, SDF_OptLayout (*acceptWsAfterBracketOpen)(SDF_OptLayout), SDF_ATermElems (*acceptElems)(SDF_ATermElems), SDF_OptLayout (*acceptWsAfterElems)(SDF_OptLayout));
SDF_ATermElems SDF_visitATermElems(SDF_ATermElems arg, SDF_ATerm (*acceptHead)(SDF_ATerm), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout));
SDF_ACon SDF_visitACon(SDF_ACon arg, SDF_IntCon (*acceptIntCon)(SDF_IntCon), SDF_RealCon (*acceptRealCon)(SDF_RealCon));
SDF_AFun SDF_visitAFun(SDF_AFun arg, SDF_Literal (*acceptLiteral)(SDF_Literal));
SDF_ATerm SDF_visitATerm(SDF_ATerm arg, SDF_ACon (*acceptACon)(SDF_ACon), SDF_ATermList (*acceptList)(SDF_ATermList), SDF_AFun (*acceptFun)(SDF_AFun), SDF_OptLayout (*acceptWsAfterFun)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_ATermArgs (*acceptArgs)(SDF_ATermArgs), SDF_OptLayout (*acceptWsAfterArgs)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterACon)(SDF_OptLayout), SDF_Ann (*acceptAnn)(SDF_Ann), SDF_OptLayout (*acceptWsAfterList)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenClose)(SDF_OptLayout));
SDF_ATermArgs SDF_visitATermArgs(SDF_ATermArgs arg, SDF_ATerm (*acceptHead)(SDF_ATerm), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout));
SDF_Ann SDF_visitAnn(SDF_Ann arg, SDF_OptLayout (*acceptWsAfterBraceOpen)(SDF_OptLayout), SDF_ATermAnnos (*acceptAnnos)(SDF_ATermAnnos), SDF_OptLayout (*acceptWsAfterAnnos)(SDF_OptLayout));
SDF_ATermAnnos SDF_visitATermAnnos(SDF_ATermAnnos arg, SDF_ATerm (*acceptHead)(SDF_ATerm), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout));
SDF_Attributes SDF_visitAttributes(SDF_Attributes arg, SDF_OptLayout (*acceptWsAfterBraceOpen)(SDF_OptLayout), SDF_AttributeList (*acceptList)(SDF_AttributeList), SDF_OptLayout (*acceptWsAfterList)(SDF_OptLayout));
SDF_AttributeList SDF_visitAttributeList(SDF_AttributeList arg, SDF_Attribute (*acceptHead)(SDF_Attribute), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout));
SDF_Productions SDF_visitProductions(SDF_Productions arg, SDF_ProductionList (*acceptList)(SDF_ProductionList));
SDF_ProductionList SDF_visitProductionList(SDF_ProductionList arg, SDF_Production (*acceptHead)(SDF_Production), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout));
SDF_SDF SDF_visitSDF(SDF_SDF arg, SDF_OptLayout (*acceptWsAfterDefinition)(SDF_OptLayout), SDF_Definition (*acceptDefinition)(SDF_Definition));
SDF_OptLayout SDF_visitOptLayout(SDF_OptLayout arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST));
SDF_Start SDF_visitStart(SDF_Start arg, SDF_OptLayout (*acceptWsBefore)(SDF_OptLayout), SDF_SDF (*acceptTopSDF)(SDF_SDF), SDF_OptLayout (*acceptWsAfter)(SDF_OptLayout), int (*acceptAmbCnt)(int), SDF_Productions (*acceptTopProductions)(SDF_Productions), SDF_Production (*acceptTopProduction)(SDF_Production), SDF_Attributes (*acceptTopAttributes)(SDF_Attributes), SDF_Attribute (*acceptTopAttribute)(SDF_Attribute), SDF_Ann (*acceptTopAnn)(SDF_Ann), SDF_ATerm (*acceptTopATerm)(SDF_ATerm), SDF_AFun (*acceptTopAFun)(SDF_AFun), SDF_ACon (*acceptTopACon)(SDF_ACon), SDF_ATermList (*acceptTopATermList)(SDF_ATermList), SDF_QLiteral (*acceptTopQLiteral)(SDF_QLiteral), SDF_UQLiteral (*acceptTopUQLiteral)(SDF_UQLiteral), SDF_Literal (*acceptTopLiteral)(SDF_Literal), SDF_IntCon (*acceptTopIntCon)(SDF_IntCon), SDF_NatCon (*acceptTopNatCon)(SDF_NatCon), SDF_RealCon (*acceptTopRealCon)(SDF_RealCon), SDF_OptExp (*acceptTopOptExp)(SDF_OptExp), SDF_Symbols (*acceptTopSymbols)(SDF_Symbols), SDF_Symbol (*acceptTopSymbol)(SDF_Symbol), SDF_Grammar (*acceptTopGrammar)(SDF_Grammar), SDF_ImpSection (*acceptTopImpSection)(SDF_ImpSection), SDF_Definition (*acceptTopDefinition)(SDF_Definition), SDF_Module (*acceptTopModule)(SDF_Module), SDF_Sections (*acceptTopSections)(SDF_Sections), SDF_Section (*acceptTopSection)(SDF_Section), SDF_Imports (*acceptTopImports)(SDF_Imports), SDF_Import (*acceptTopImport)(SDF_Import), SDF_ModuleName (*acceptTopModuleName)(SDF_ModuleName), SDF_ModuleId (*acceptTopModuleId)(SDF_ModuleId), SDF_Renamings (*acceptTopRenamings)(SDF_Renamings), SDF_Renaming (*acceptTopRenaming)(SDF_Renaming), SDF_Priorities (*acceptTopPriorities)(SDF_Priorities), SDF_Priority (*acceptTopPriority)(SDF_Priority), SDF_Group (*acceptTopGroup)(SDF_Group), SDF_Associativity (*acceptTopAssociativity)(SDF_Associativity), SDF_CharClass (*acceptTopCharClass)(SDF_CharClass), SDF_ShortChar (*acceptTopShortChar)(SDF_ShortChar), SDF_NumChar (*acceptTopNumChar)(SDF_NumChar), SDF_Character (*acceptTopCharacter)(SDF_Character), SDF_Sort (*acceptTopSort)(SDF_Sort), SDF_Restrictions (*acceptTopRestrictions)(SDF_Restrictions), SDF_Restriction (*acceptTopRestriction)(SDF_Restriction), SDF_Lookaheads (*acceptTopLookaheads)(SDF_Lookaheads), SDF_Lookahead (*acceptTopLookahead)(SDF_Lookahead), SDF_Aliases (*acceptTopAliases)(SDF_Aliases), SDF_Alias (*acceptTopAlias)(SDF_Alias));

/*}}}  */

#endif /* _SDFME_H */
