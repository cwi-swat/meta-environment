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
typedef struct _SDF_GroupList *SDF_GroupList;
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

/*{{{  term conversion functions */

#define SDF_makeSymbolFromTerm(t) (SDF_SymbolFromTerm(t))
SDF_Symbol SDF_SymbolFromTerm(ATerm t);
#define SDF_makeTermFromSymbol(t) (SDF_SymbolToTerm(t))
ATerm SDF_SymbolToTerm(SDF_Symbol arg);
#define SDF_makeGrammarFromTerm(t) (SDF_GrammarFromTerm(t))
SDF_Grammar SDF_GrammarFromTerm(ATerm t);
#define SDF_makeTermFromGrammar(t) (SDF_GrammarToTerm(t))
ATerm SDF_GrammarToTerm(SDF_Grammar arg);
#define SDF_makeSDFFromTerm(t) (SDF_SDFFromTerm(t))
SDF_SDF SDF_SDFFromTerm(ATerm t);
#define SDF_makeTermFromSDF(t) (SDF_SDFToTerm(t))
ATerm SDF_SDFToTerm(SDF_SDF arg);
#define SDF_makeAttributesFromTerm(t) (SDF_AttributesFromTerm(t))
SDF_Attributes SDF_AttributesFromTerm(ATerm t);
#define SDF_makeTermFromAttributes(t) (SDF_AttributesToTerm(t))
ATerm SDF_AttributesToTerm(SDF_Attributes arg);
#define SDF_makeAttributeListFromTerm(t) (SDF_AttributeListFromTerm(t))
SDF_AttributeList SDF_AttributeListFromTerm(ATerm t);
#define SDF_makeTermFromAttributeList(t) (SDF_AttributeListToTerm(t))
ATerm SDF_AttributeListToTerm(SDF_AttributeList arg);
#define SDF_makeProductionFromTerm(t) (SDF_ProductionFromTerm(t))
SDF_Production SDF_ProductionFromTerm(ATerm t);
#define SDF_makeTermFromProduction(t) (SDF_ProductionToTerm(t))
ATerm SDF_ProductionToTerm(SDF_Production arg);
#define SDF_makeProductionsFromTerm(t) (SDF_ProductionsFromTerm(t))
SDF_Productions SDF_ProductionsFromTerm(ATerm t);
#define SDF_makeTermFromProductions(t) (SDF_ProductionsToTerm(t))
ATerm SDF_ProductionsToTerm(SDF_Productions arg);
#define SDF_makeProductionListFromTerm(t) (SDF_ProductionListFromTerm(t))
SDF_ProductionList SDF_ProductionListFromTerm(ATerm t);
#define SDF_makeTermFromProductionList(t) (SDF_ProductionListToTerm(t))
ATerm SDF_ProductionListToTerm(SDF_ProductionList arg);
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
#define SDF_makeAttributeFromTerm(t) (SDF_AttributeFromTerm(t))
SDF_Attribute SDF_AttributeFromTerm(ATerm t);
#define SDF_makeTermFromAttribute(t) (SDF_AttributeToTerm(t))
ATerm SDF_AttributeToTerm(SDF_Attribute arg);
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
#define SDF_makeSymbolTailFromTerm(t) (SDF_SymbolTailFromTerm(t))
SDF_SymbolTail SDF_SymbolTailFromTerm(ATerm t);
#define SDF_makeTermFromSymbolTail(t) (SDF_SymbolTailToTerm(t))
ATerm SDF_SymbolTailToTerm(SDF_SymbolTail arg);
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
#define SDF_makeSortFromTerm(t) (SDF_SortFromTerm(t))
SDF_Sort SDF_SortFromTerm(ATerm t);
#define SDF_makeTermFromSort(t) (SDF_SortToTerm(t))
ATerm SDF_SortToTerm(SDF_Sort arg);
#define SDF_makeUQLiteralFromTerm(t) (SDF_UQLiteralFromTerm(t))
SDF_UQLiteral SDF_UQLiteralFromTerm(ATerm t);
#define SDF_makeTermFromUQLiteral(t) (SDF_UQLiteralToTerm(t))
ATerm SDF_UQLiteralToTerm(SDF_UQLiteral arg);
#define SDF_makeLiteralFromTerm(t) (SDF_LiteralFromTerm(t))
SDF_Literal SDF_LiteralFromTerm(ATerm t);
#define SDF_makeTermFromLiteral(t) (SDF_LiteralToTerm(t))
ATerm SDF_LiteralToTerm(SDF_Literal arg);
#define SDF_makeSymbolArgumentsFromTerm(t) (SDF_SymbolArgumentsFromTerm(t))
SDF_SymbolArguments SDF_SymbolArgumentsFromTerm(ATerm t);
#define SDF_makeTermFromSymbolArguments(t) (SDF_SymbolArgumentsToTerm(t))
ATerm SDF_SymbolArgumentsToTerm(SDF_SymbolArguments arg);
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
#define SDF_makeSymbolsFromTerm(t) (SDF_SymbolsFromTerm(t))
SDF_Symbols SDF_SymbolsFromTerm(ATerm t);
#define SDF_makeTermFromSymbols(t) (SDF_SymbolsToTerm(t))
ATerm SDF_SymbolsToTerm(SDF_Symbols arg);
#define SDF_makeSymbolListFromTerm(t) (SDF_SymbolListFromTerm(t))
SDF_SymbolList SDF_SymbolListFromTerm(ATerm t);
#define SDF_makeTermFromSymbolList(t) (SDF_SymbolListToTerm(t))
ATerm SDF_SymbolListToTerm(SDF_SymbolList arg);
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
#define SDF_makeNatConFromTerm(t) (SDF_NatConFromTerm(t))
SDF_NatCon SDF_NatConFromTerm(ATerm t);
#define SDF_makeTermFromNatCon(t) (SDF_NatConToTerm(t))
ATerm SDF_NatConToTerm(SDF_NatCon arg);
#define SDF_makeIntConFromTerm(t) (SDF_IntConFromTerm(t))
SDF_IntCon SDF_IntConFromTerm(ATerm t);
#define SDF_makeTermFromIntCon(t) (SDF_IntConToTerm(t))
ATerm SDF_IntConToTerm(SDF_IntCon arg);
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
#define SDF_makeATermsFromTerm(t) (SDF_ATermsFromTerm(t))
SDF_ATerms SDF_ATermsFromTerm(ATerm t);
#define SDF_makeTermFromATerms(t) (SDF_ATermsToTerm(t))
ATerm SDF_ATermsToTerm(SDF_ATerms arg);
#define SDF_makeATermListFromTerm(t) (SDF_ATermListFromTerm(t))
SDF_ATermList SDF_ATermListFromTerm(ATerm t);
#define SDF_makeTermFromATermList(t) (SDF_ATermListToTerm(t))
ATerm SDF_ATermListToTerm(SDF_ATermList arg);
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
#define SDF_makeAnnFromTerm(t) (SDF_AnnFromTerm(t))
SDF_Ann SDF_AnnFromTerm(ATerm t);
#define SDF_makeTermFromAnn(t) (SDF_AnnToTerm(t))
ATerm SDF_AnnToTerm(SDF_Ann arg);
#define SDF_makeTagIdFromTerm(t) (SDF_TagIdFromTerm(t))
SDF_TagId SDF_TagIdFromTerm(ATerm t);
#define SDF_makeTermFromTagId(t) (SDF_TagIdToTerm(t))
ATerm SDF_TagIdToTerm(SDF_TagId arg);
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
#define SDF_makeOptExpFromTerm(t) (SDF_OptExpFromTerm(t))
SDF_OptExp SDF_OptExpFromTerm(ATerm t);
#define SDF_makeTermFromOptExp(t) (SDF_OptExpToTerm(t))
ATerm SDF_OptExpToTerm(SDF_OptExp arg);
#define SDF_makeRealConFromTerm(t) (SDF_RealConFromTerm(t))
SDF_RealCon SDF_RealConFromTerm(ATerm t);
#define SDF_makeTermFromRealCon(t) (SDF_RealConToTerm(t))
ATerm SDF_RealConToTerm(SDF_RealCon arg);

/*}}}  */
/*{{{  constructors */

SDF_Symbol SDF_makeSymbolStart();
SDF_Symbol SDF_makeSymbolFileStart();
SDF_Symbol SDF_makeSymbolCf(char * wsAfterLessThan, SDF_Symbol Symbol, char * wsAfterSymbol, char * wsAfterCF);
SDF_Symbol SDF_makeSymbolLex(char * wsAfterLessThan, SDF_Symbol Symbol, char * wsAfterSymbol, char * wsAfterLEX);
SDF_Symbol SDF_makeSymbolVarsym(char * wsAfterLessThan, SDF_Symbol Symbol, char * wsAfterSymbol, char * wsAfterVAR);
SDF_Symbol SDF_makeSymbolLayout();
SDF_Symbol SDF_makeSymbolEmpty(char * wsAfterParenOpen);
SDF_Symbol SDF_makeSymbolSeq(char * wsAfterParenOpen, SDF_Symbol head, char * wsAfterHead, SDF_SymbolTail tail, char * wsAfterTail);
SDF_Symbol SDF_makeSymbolOpt(SDF_Symbol Symbol, char * wsAfterSymbol);
SDF_Symbol SDF_makeSymbolIter(SDF_Symbol Symbol, char * wsAfterSymbol);
SDF_Symbol SDF_makeSymbolIterStar(SDF_Symbol Symbol, char * wsAfterSymbol);
SDF_Symbol SDF_makeSymbolIterSep(char * wsAfterBraceOpen, SDF_Symbol Symbol, char * wsAfterSymbol, SDF_Symbol sep, char * wsAfterSep, char * wsAfterBraceClose);
SDF_Symbol SDF_makeSymbolIterStarSep(char * wsAfterBraceOpen, SDF_Symbol Symbol, char * wsAfterSymbol, SDF_Symbol sep, char * wsAfterSep, char * wsAfterBraceClose);
SDF_Symbol SDF_makeSymbolIterN(SDF_Symbol Symbol, char * wsAfterSymbol, SDF_NatCon n, char * wsAfterN);
SDF_Symbol SDF_makeSymbolIterSepN(char * wsAfterBraceOpen, SDF_Symbol Symbol, char * wsAfterSymbol, SDF_Symbol sep, char * wsAfterSep, char * wsAfterBraceClose, SDF_NatCon n, char * wsAfterN);
SDF_Symbol SDF_makeSymbolSet(char * wsAfterSet, char * wsAfterBracketOpen, SDF_Symbol Symbol, char * wsAfterSymbol);
SDF_Symbol SDF_makeSymbolPair(SDF_Symbol left, char * wsAfterLeft, char * wsAfterHash, SDF_Symbol right);
SDF_Symbol SDF_makeSymbolFunc(char * wsAfterParenOpen, SDF_Symbols arguments, char * wsAfterArguments, char * wsAfterEqualsGreaterThan, SDF_Symbol results, char * wsAfterResults);
SDF_Symbol SDF_makeSymbolAlt(SDF_Symbol left, char * wsAfterLeft, char * wsAfterBar, SDF_Symbol right);
SDF_Symbol SDF_makeSymbolPerm(char * wsAfterLessThanLessThan, SDF_Symbols Symbols, char * wsAfterSymbols);
SDF_Symbol SDF_makeSymbolCharClass(SDF_CharClass CharClass);
SDF_Symbol SDF_makeSymbolSort(SDF_Sort Sort);
SDF_Symbol SDF_makeSymbolLit(SDF_Literal Literal);
SDF_Symbol SDF_makeSymbolLabel(SDF_Literal label, char * wsAfterLabel, char * wsAfterColon, SDF_Symbol Symbol);
SDF_Symbol SDF_makeSymbolBracket(char * wsAfterParenOpen, SDF_Symbol Symbol, char * wsAfterSymbol);
SDF_Grammar SDF_makeGrammarLexicalPriorities(char * wsAfterLexical, char * wsAfterPriorities, SDF_Priorities Priorities);
SDF_Grammar SDF_makeGrammarContextFreePriorities(char * wsAfterContextFree, char * wsAfterPriorities, SDF_Priorities Priorities);
SDF_Grammar SDF_makeGrammarLexicalRestrictions(char * wsAfterLexical, char * wsAfterRestrictions, SDF_Restrictions Restrictions);
SDF_Grammar SDF_makeGrammarContextFreeRestrictions(char * wsAfterContextFree, char * wsAfterRestrictions, SDF_Restrictions Restrictions);
SDF_Grammar SDF_makeGrammarSyntax(char * wsAfterSyntax, SDF_Productions Productions);
SDF_Grammar SDF_makeGrammarLexicalSyntax(char * wsAfterLexical, char * wsAfterSyntax, SDF_Productions Productions);
SDF_Grammar SDF_makeGrammarContextFreeSyntax(char * wsAfterContextFree, char * wsAfterSyntax, SDF_Productions Productions);
SDF_Grammar SDF_makeGrammarVariables(char * wsAfterVariables, SDF_Productions Productions);
SDF_Grammar SDF_makeGrammarLexicalVariables(char * wsAfterLexical, char * wsAfterVariables, SDF_Productions Productions);
SDF_Grammar SDF_makeGrammarImpSection(SDF_ImpSection ImpSection);
SDF_Grammar SDF_makeGrammarPriorities(char * wsAfterPriorities, SDF_Priorities Priorities);
SDF_Grammar SDF_makeGrammarSorts(char * wsAfterSorts, SDF_Symbols Symbols);
SDF_Grammar SDF_makeGrammarRestrictions(char * wsAfterRestrictions, SDF_Restrictions Restrictions);
SDF_Grammar SDF_makeGrammarAliases(char * wsAfterAliases, SDF_Aliases Aliases);
SDF_Grammar SDF_makeGrammarEmptyGrammar();
SDF_Grammar SDF_makeGrammarConcGrammars(SDF_Grammar left, char * wsAfterLeft, SDF_Grammar right);
SDF_Grammar SDF_makeGrammarBracket(char * wsAfterParenOpen, SDF_Grammar Grammar, char * wsAfterGrammar);
SDF_SDF SDF_makeSDFDefinition(char * wsAfterDefinition, SDF_Definition Definition);
SDF_Attributes SDF_makeAttributesAttrs(char * wsAfterBraceOpen, SDF_AttributeList list, char * wsAfterList);
SDF_Attributes SDF_makeAttributesNoAttrs();
SDF_AttributeList SDF_makeAttributeListEmpty();
SDF_AttributeList SDF_makeAttributeListSingle(SDF_Attribute head);
SDF_AttributeList SDF_makeAttributeListMany(SDF_Attribute head, char * wsAfterFirst, char * sep, char * wsAfterSep, SDF_AttributeList tail);
SDF_Production SDF_makeProductionProd(SDF_Symbols Symbols, char * wsAfterSymbols, char * wsAfterGreaterThan, SDF_Symbol result, char * wsAfterResult, SDF_Attributes Attributes);
SDF_Production SDF_makeProductionProdFun(SDF_Literal functionSymbol, char * wsAfterFunctionSymbol, char * wsAfterParenOpen, SDF_SymbolArguments arguments, char * wsAfterArguments, char * wsAfterParenClose, char * wsAfterGreaterThan, SDF_Symbol result, char * wsAfterResult, SDF_Attributes Attributes);
SDF_Productions SDF_makeProductionsDefault(SDF_ProductionList list);
SDF_ProductionList SDF_makeProductionListEmpty();
SDF_ProductionList SDF_makeProductionListSingle(SDF_Production head);
SDF_ProductionList SDF_makeProductionListMany(SDF_Production head, char * wsAfterFirst, SDF_ProductionList tail);
SDF_ModuleWord SDF_makeModuleWordWord(char * lex);
SDF_ModuleId SDF_makeModuleIdWord(char * lex);
SDF_ModuleId SDF_makeModuleIdSlashWord(char * lex);
SDF_ModuleId SDF_makeModuleIdWordSlashWord(char * lex);
SDF_Definition SDF_makeDefinitionDefault(SDF_ModuleList list);
SDF_ModuleList SDF_makeModuleListEmpty();
SDF_ModuleList SDF_makeModuleListSingle(SDF_Module head);
SDF_ModuleList SDF_makeModuleListMany(SDF_Module head, char * wsAfterFirst, SDF_ModuleList tail);
SDF_Module SDF_makeModuleModule(char * wsAfterModule, SDF_ModuleName ModuleName, char * wsAfterModuleName, SDF_ImpSectionList list, char * wsAfterList, SDF_Sections Sections);
SDF_ImpSectionList SDF_makeImpSectionListEmpty();
SDF_ImpSectionList SDF_makeImpSectionListSingle(SDF_ImpSection head);
SDF_ImpSectionList SDF_makeImpSectionListMany(SDF_ImpSection head, char * wsAfterFirst, SDF_ImpSectionList tail);
SDF_Section SDF_makeSectionExports(char * wsAfterExports, SDF_Grammar Grammar);
SDF_Section SDF_makeSectionHiddens(char * wsAfterHiddens, SDF_Grammar Grammar);
SDF_Sections SDF_makeSectionsDefault(SDF_SectionList list);
SDF_SectionList SDF_makeSectionListEmpty();
SDF_SectionList SDF_makeSectionListSingle(SDF_Section head);
SDF_SectionList SDF_makeSectionListMany(SDF_Section head, char * wsAfterFirst, SDF_SectionList tail);
SDF_ModuleName SDF_makeModuleNameUnparameterized(SDF_ModuleId ModuleId);
SDF_ModuleName SDF_makeModuleNameParameterized(SDF_ModuleId ModuleId, char * wsAfterModuleId, char * wsAfterBracketOpen, SDF_Symbols params, char * wsAfterParams);
SDF_Attribute SDF_makeAttributeId(char * wsAfterId, char * wsAfterParenOpen, SDF_ModuleName ModuleName, char * wsAfterModuleName);
SDF_Attribute SDF_makeAttributeBracket();
SDF_Attribute SDF_makeAttributeAtr(SDF_Associativity Associativity);
SDF_Attribute SDF_makeAttributeCons(char * wsAfterCons, char * wsAfterParenOpen, SDF_ATerm term, char * wsAfterTerm);
SDF_Attribute SDF_makeAttributeConstructor();
SDF_Attribute SDF_makeAttributeMemo();
SDF_Attribute SDF_makeAttributeTraverse();
SDF_Attribute SDF_makeAttributeReject();
SDF_Attribute SDF_makeAttributePrefer();
SDF_Attribute SDF_makeAttributeAvoid();
SDF_ImpSection SDF_makeImpSectionImports(char * wsAfterImports, SDF_Imports list);
SDF_Imports SDF_makeImportsDefault(SDF_ImportList list);
SDF_ImportList SDF_makeImportListEmpty();
SDF_ImportList SDF_makeImportListSingle(SDF_Import head);
SDF_ImportList SDF_makeImportListMany(SDF_Import head, char * wsAfterFirst, SDF_ImportList tail);
SDF_Import SDF_makeImportModule(SDF_ModuleName ModuleName);
SDF_Import SDF_makeImportRenamedModule(SDF_ModuleName ModuleName, char * wsAfterModuleName, SDF_Renamings Renamings);
SDF_Import SDF_makeImportBracket(char * wsAfterParenOpen, SDF_Import Import, char * wsAfterImport);
SDF_SymbolTail SDF_makeSymbolTailSingle(SDF_Symbol head);
SDF_SymbolTail SDF_makeSymbolTailMany(SDF_Symbol head, char * wsAfterFirst, SDF_SymbolTail tail);
SDF_Associativity SDF_makeAssociativityLeft();
SDF_Associativity SDF_makeAssociativityRight();
SDF_Associativity SDF_makeAssociativityNonAssoc();
SDF_Associativity SDF_makeAssociativityAssoc();
SDF_Group SDF_makeGroupSimpleGroup(SDF_Production Production);
SDF_Group SDF_makeGroupProdsGroup(char * wsAfterBraceOpen, SDF_Productions Productions, char * wsAfterProductions);
SDF_Group SDF_makeGroupAssocGroup(char * wsAfterBraceOpen, SDF_Associativity Associativity, char * wsAfterAssociativity, char * wsAfterColon, SDF_Productions Productions, char * wsAfterProductions);
SDF_Priority SDF_makePriorityChain(SDF_GroupList list);
SDF_Priority SDF_makePriorityAssoc(SDF_Group left, char * wsAfterLeft, SDF_Associativity Associativity, char * wsAfterAssociativity, SDF_Group right);
SDF_GroupList SDF_makeGroupListSingle(SDF_Group head);
SDF_GroupList SDF_makeGroupListMany(SDF_Group head, char * wsAfterFirst, char * sep, char * wsAfterSep, SDF_GroupList tail);
SDF_Priorities SDF_makePrioritiesDefault(SDF_PriorityList list);
SDF_PriorityList SDF_makePriorityListEmpty();
SDF_PriorityList SDF_makePriorityListSingle(SDF_Priority head);
SDF_PriorityList SDF_makePriorityListMany(SDF_Priority head, char * wsAfterFirst, char * sep, char * wsAfterSep, SDF_PriorityList tail);
SDF_Sort SDF_makeSortOneChar(char * lex);
SDF_Sort SDF_makeSortMoreChars(char * lex);
SDF_UQLiteral SDF_makeUQLiteralOneChar(char * lex);
SDF_UQLiteral SDF_makeUQLiteralMoreChars(char * lex);
SDF_Literal SDF_makeLiteralUqlit(SDF_UQLiteral UQLiteral);
SDF_Literal SDF_makeLiteralQuoted(char * lex);
SDF_SymbolArguments SDF_makeSymbolArgumentsEmpty();
SDF_SymbolArguments SDF_makeSymbolArgumentsSingle(SDF_Symbol head);
SDF_SymbolArguments SDF_makeSymbolArgumentsMany(SDF_Symbol head, char * wsAfterFirst, char * sep, char * wsAfterSep, SDF_SymbolArguments tail);
SDF_Lookahead SDF_makeLookaheadCharClass(SDF_CharClass CharClass);
SDF_Lookahead SDF_makeLookaheadSeq(SDF_CharClass head, char * wsAfterHead, char * wsAfterPeriod, SDF_Lookaheads tail);
SDF_Lookaheads SDF_makeLookaheadsSingle(SDF_Lookahead Lookahead);
SDF_Lookaheads SDF_makeLookaheadsAlt(SDF_Lookaheads left, char * wsAfterLeft, char * wsAfterBar, SDF_Lookaheads right);
SDF_Lookaheads SDF_makeLookaheadsBracket(char * wsAfterParenOpen, SDF_Lookaheads Lookaheads, char * wsAfterLookaheads);
SDF_Lookaheads SDF_makeLookaheadsList(char * wsAfterBracketOpenBracketOpen, SDF_LookaheadList list, char * wsAfterList);
SDF_LookaheadList SDF_makeLookaheadListEmpty();
SDF_LookaheadList SDF_makeLookaheadListSingle(SDF_Lookahead head);
SDF_LookaheadList SDF_makeLookaheadListMany(SDF_Lookahead head, char * wsAfterFirst, char * sep, char * wsAfterSep, SDF_LookaheadList tail);
SDF_Restriction SDF_makeRestrictionFollow(SDF_Symbols Symbols, char * wsAfterSymbols, char * wsAfterSlash, SDF_Lookaheads Lookaheads);
SDF_Restrictions SDF_makeRestrictionsDefault(SDF_RestrictionList list);
SDF_RestrictionList SDF_makeRestrictionListEmpty();
SDF_RestrictionList SDF_makeRestrictionListSingle(SDF_Restriction head);
SDF_RestrictionList SDF_makeRestrictionListMany(SDF_Restriction head, char * wsAfterFirst, SDF_RestrictionList tail);
SDF_Alias SDF_makeAliasAlias(SDF_Symbol Symbol, char * wsAfterSymbol, char * wsAfterArrow, SDF_Symbol alias);
SDF_Aliases SDF_makeAliasesDefault(SDF_AliasList list);
SDF_AliasList SDF_makeAliasListEmpty();
SDF_AliasList SDF_makeAliasListSingle(SDF_Alias head);
SDF_AliasList SDF_makeAliasListMany(SDF_Alias head, char * wsAfterFirst, SDF_AliasList tail);
SDF_Symbols SDF_makeSymbolsDefault(SDF_SymbolList list);
SDF_SymbolList SDF_makeSymbolListEmpty();
SDF_SymbolList SDF_makeSymbolListSingle(SDF_Symbol head);
SDF_SymbolList SDF_makeSymbolListMany(SDF_Symbol head, char * wsAfterFirst, SDF_SymbolList tail);
SDF_Renamings SDF_makeRenamingsRenamings(char * wsAfterBracketOpen, SDF_RenamingList list, char * wsAfterList);
SDF_RenamingList SDF_makeRenamingListEmpty();
SDF_RenamingList SDF_makeRenamingListSingle(SDF_Renaming head);
SDF_RenamingList SDF_makeRenamingListMany(SDF_Renaming head, char * wsAfterFirst, SDF_RenamingList tail);
SDF_Renaming SDF_makeRenamingSymbol(SDF_Symbol from, char * wsAfterFrom, char * wsAfterEqualsGreaterThan, SDF_Symbol to);
SDF_Renaming SDF_makeRenamingProduction(SDF_Symbol from, char * wsAfterFrom, char * wsAfterEqualsGreaterThan, SDF_Symbol to);
SDF_NatCon SDF_makeNatConDigits(char * lex);
SDF_IntCon SDF_makeIntConNatural(SDF_NatCon NatCon);
SDF_IntCon SDF_makeIntConPositive(char * wsAfterPos, SDF_NatCon NatCon);
SDF_IntCon SDF_makeIntConNegative(char * wsAfterNeg, SDF_NatCon NatCon);
SDF_CharRange SDF_makeCharRangeDefault(SDF_Character Character);
SDF_CharRange SDF_makeCharRangeRange(SDF_Character start, char * wsAfterStart, char * wsAfter, SDF_Character end);
SDF_CharRanges SDF_makeCharRangesDefault(SDF_CharRange CharRange);
SDF_CharRanges SDF_makeCharRangesConc(SDF_CharRanges left, char * wsAfterLeft, SDF_CharRanges right);
SDF_CharRanges SDF_makeCharRangesBracket(char * wsAfterParenOpen, SDF_CharRanges CharRanges, char * wsAfterCharRanges);
SDF_OptCharRanges SDF_makeOptCharRangesAbsent();
SDF_OptCharRanges SDF_makeOptCharRangesPresent(SDF_CharRanges CharRanges);
SDF_CharClass SDF_makeCharClassSimpleCharclass(char * wsAfterBracketOpen, SDF_OptCharRanges OptCharRanges, char * wsAfterOptCharRanges);
SDF_CharClass SDF_makeCharClassComp(char * wsAfterTilde, SDF_CharClass CharClass);
SDF_CharClass SDF_makeCharClassDiff(SDF_CharClass left, char * wsAfterLeft, char * wsAfterSlash, SDF_CharClass right);
SDF_CharClass SDF_makeCharClassIsect(SDF_CharClass left, char * wsAfterLeft, char * wsAfterSlashBackslash, SDF_CharClass right);
SDF_CharClass SDF_makeCharClassUnion(SDF_CharClass left, char * wsAfterLeft, char * wsAfterBackslashSlash, SDF_CharClass right);
SDF_CharClass SDF_makeCharClassBracket(char * wsAfterParenOpen, SDF_CharClass CharClass, char * wsAfterCharClass);
SDF_AlphaNumericalEscChar SDF_makeAlphaNumericalEscCharDefault(char * lex);
SDF_DecimalEscChar SDF_makeDecimalEscCharDec0Underscore199(char * lex);
SDF_DecimalEscChar SDF_makeDecimalEscCharDec200Underscore249(char * lex);
SDF_DecimalEscChar SDF_makeDecimalEscCharDec250Underscore255(char * lex);
SDF_EscChar SDF_makeEscCharAlphaNumeric(char * lex);
SDF_EscChar SDF_makeEscCharDecimal(char * lex);
SDF_LChar SDF_makeLCharNormal(char * lex);
SDF_LChar SDF_makeLCharEscaped(char * lex);
SDF_ATerms SDF_makeATermsAterm(SDF_ATerm term);
SDF_ATerms SDF_makeATermsCons(SDF_ATerm head, char * wsAfterHead, char * wsAfterComma, SDF_ATerms tail);
SDF_ATermList SDF_makeATermListEmpty(char * wsAfterBracketOpen);
SDF_ATermList SDF_makeATermListNotEmpty(char * wsAfterBracketOpen, SDF_ATerms ATerms, char * wsAfterATerms);
SDF_ACon SDF_makeAConInt(SDF_IntCon IntCon);
SDF_ACon SDF_makeAConReal(SDF_RealCon RealCon);
SDF_AFun SDF_makeAFunDefault(SDF_Literal Literal);
SDF_ATerm SDF_makeATermConstant(SDF_ACon ACon);
SDF_ATerm SDF_makeATermList(SDF_ATermList list);
SDF_ATerm SDF_makeATermFun(SDF_AFun fun);
SDF_ATerm SDF_makeATermAppl(SDF_AFun fun, char * wsAfterFun, char * wsAfterParenOpen, SDF_ATerms args, char * wsAfterArgs);
SDF_ATerm SDF_makeATermAnnotatedConstant(SDF_ACon ACon, char * wsAfterACon, SDF_Ann Ann);
SDF_ATerm SDF_makeATermAnnotatedList(SDF_ATermList list, char * wsAfterList, SDF_Ann Ann);
SDF_ATerm SDF_makeATermAnnotatedFun(SDF_AFun fun, char * wsAfterFun, SDF_Ann Ann);
SDF_ATerm SDF_makeATermAnnotatedAppl(SDF_AFun fun, char * wsAfterFun, char * wsAfterParenOpen, SDF_ATerms args, char * wsAfterArgs, char * wsAfterParenClose, SDF_Ann Ann);
SDF_Ann SDF_makeAnnAnnotation(char * wsAfterBraceOpen, SDF_ATerms ATerms, char * wsAfterATerms);
SDF_TagId SDF_makeTagIdDefault(char * lex);
SDF_TagId SDF_makeTagIdEmpty();
SDF_NumChar SDF_makeNumCharDigits(char * lex);
SDF_ShortChar SDF_makeShortCharRegular(char * lex);
SDF_ShortChar SDF_makeShortCharEscaped(char * lex);
SDF_Character SDF_makeCharacterNumeric(SDF_NumChar NumChar);
SDF_Character SDF_makeCharacterShort(SDF_ShortChar ShortChar);
SDF_Character SDF_makeCharacterTop();
SDF_Character SDF_makeCharacterEof();
SDF_OptExp SDF_makeOptExpPresent(char * wsAfterE, SDF_IntCon IntCon);
SDF_OptExp SDF_makeOptExpAbsent();
SDF_RealCon SDF_makeRealConRealCon(SDF_IntCon IntCon, char * wsAfterIntCon, char * wsAfterPeriod, SDF_NatCon NatCon, char * wsAfterNatCon, SDF_OptExp OptExp);

/*}}}  */
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
ATbool SDF_isEqualGroupList(SDF_GroupList arg0, SDF_GroupList arg1);
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
/*{{{  SDF_Symbol accessors */

ATbool SDF_isValidSymbol(SDF_Symbol arg);
inline ATbool SDF_isSymbolStart(SDF_Symbol arg);
inline ATbool SDF_isSymbolFileStart(SDF_Symbol arg);
inline ATbool SDF_isSymbolCf(SDF_Symbol arg);
inline ATbool SDF_isSymbolLex(SDF_Symbol arg);
inline ATbool SDF_isSymbolVarsym(SDF_Symbol arg);
inline ATbool SDF_isSymbolLayout(SDF_Symbol arg);
inline ATbool SDF_isSymbolEmpty(SDF_Symbol arg);
inline ATbool SDF_isSymbolSeq(SDF_Symbol arg);
inline ATbool SDF_isSymbolOpt(SDF_Symbol arg);
inline ATbool SDF_isSymbolIter(SDF_Symbol arg);
inline ATbool SDF_isSymbolIterStar(SDF_Symbol arg);
inline ATbool SDF_isSymbolIterSep(SDF_Symbol arg);
inline ATbool SDF_isSymbolIterStarSep(SDF_Symbol arg);
inline ATbool SDF_isSymbolIterN(SDF_Symbol arg);
inline ATbool SDF_isSymbolIterSepN(SDF_Symbol arg);
inline ATbool SDF_isSymbolSet(SDF_Symbol arg);
inline ATbool SDF_isSymbolPair(SDF_Symbol arg);
inline ATbool SDF_isSymbolFunc(SDF_Symbol arg);
inline ATbool SDF_isSymbolAlt(SDF_Symbol arg);
inline ATbool SDF_isSymbolPerm(SDF_Symbol arg);
inline ATbool SDF_isSymbolCharClass(SDF_Symbol arg);
inline ATbool SDF_isSymbolSort(SDF_Symbol arg);
inline ATbool SDF_isSymbolLit(SDF_Symbol arg);
inline ATbool SDF_isSymbolLabel(SDF_Symbol arg);
inline ATbool SDF_isSymbolBracket(SDF_Symbol arg);
ATbool SDF_hasSymbolWsAfterLessThan(SDF_Symbol arg);
char * SDF_getSymbolWsAfterLessThan(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterLessThan(SDF_Symbol arg, char * wsAfterLessThan);
ATbool SDF_hasSymbolSymbol(SDF_Symbol arg);
SDF_Symbol SDF_getSymbolSymbol(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolSymbol(SDF_Symbol arg, SDF_Symbol Symbol);
ATbool SDF_hasSymbolWsAfterSymbol(SDF_Symbol arg);
char * SDF_getSymbolWsAfterSymbol(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterSymbol(SDF_Symbol arg, char * wsAfterSymbol);
ATbool SDF_hasSymbolWsAfterCF(SDF_Symbol arg);
char * SDF_getSymbolWsAfterCF(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterCF(SDF_Symbol arg, char * wsAfterCF);
ATbool SDF_hasSymbolWsAfterLEX(SDF_Symbol arg);
char * SDF_getSymbolWsAfterLEX(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterLEX(SDF_Symbol arg, char * wsAfterLEX);
ATbool SDF_hasSymbolWsAfterVAR(SDF_Symbol arg);
char * SDF_getSymbolWsAfterVAR(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterVAR(SDF_Symbol arg, char * wsAfterVAR);
ATbool SDF_hasSymbolWsAfterParenOpen(SDF_Symbol arg);
char * SDF_getSymbolWsAfterParenOpen(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterParenOpen(SDF_Symbol arg, char * wsAfterParenOpen);
ATbool SDF_hasSymbolHead(SDF_Symbol arg);
SDF_Symbol SDF_getSymbolHead(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolHead(SDF_Symbol arg, SDF_Symbol head);
ATbool SDF_hasSymbolWsAfterHead(SDF_Symbol arg);
char * SDF_getSymbolWsAfterHead(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterHead(SDF_Symbol arg, char * wsAfterHead);
ATbool SDF_hasSymbolTail(SDF_Symbol arg);
SDF_SymbolTail SDF_getSymbolTail(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolTail(SDF_Symbol arg, SDF_SymbolTail tail);
ATbool SDF_hasSymbolWsAfterTail(SDF_Symbol arg);
char * SDF_getSymbolWsAfterTail(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterTail(SDF_Symbol arg, char * wsAfterTail);
ATbool SDF_hasSymbolWsAfterBraceOpen(SDF_Symbol arg);
char * SDF_getSymbolWsAfterBraceOpen(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterBraceOpen(SDF_Symbol arg, char * wsAfterBraceOpen);
ATbool SDF_hasSymbolSep(SDF_Symbol arg);
SDF_Symbol SDF_getSymbolSep(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolSep(SDF_Symbol arg, SDF_Symbol sep);
ATbool SDF_hasSymbolWsAfterSep(SDF_Symbol arg);
char * SDF_getSymbolWsAfterSep(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterSep(SDF_Symbol arg, char * wsAfterSep);
ATbool SDF_hasSymbolWsAfterBraceClose(SDF_Symbol arg);
char * SDF_getSymbolWsAfterBraceClose(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterBraceClose(SDF_Symbol arg, char * wsAfterBraceClose);
ATbool SDF_hasSymbolN(SDF_Symbol arg);
SDF_NatCon SDF_getSymbolN(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolN(SDF_Symbol arg, SDF_NatCon n);
ATbool SDF_hasSymbolWsAfterN(SDF_Symbol arg);
char * SDF_getSymbolWsAfterN(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterN(SDF_Symbol arg, char * wsAfterN);
ATbool SDF_hasSymbolWsAfterSet(SDF_Symbol arg);
char * SDF_getSymbolWsAfterSet(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterSet(SDF_Symbol arg, char * wsAfterSet);
ATbool SDF_hasSymbolWsAfterBracketOpen(SDF_Symbol arg);
char * SDF_getSymbolWsAfterBracketOpen(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterBracketOpen(SDF_Symbol arg, char * wsAfterBracketOpen);
ATbool SDF_hasSymbolLeft(SDF_Symbol arg);
SDF_Symbol SDF_getSymbolLeft(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolLeft(SDF_Symbol arg, SDF_Symbol left);
ATbool SDF_hasSymbolWsAfterLeft(SDF_Symbol arg);
char * SDF_getSymbolWsAfterLeft(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterLeft(SDF_Symbol arg, char * wsAfterLeft);
ATbool SDF_hasSymbolWsAfterHash(SDF_Symbol arg);
char * SDF_getSymbolWsAfterHash(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterHash(SDF_Symbol arg, char * wsAfterHash);
ATbool SDF_hasSymbolRight(SDF_Symbol arg);
SDF_Symbol SDF_getSymbolRight(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolRight(SDF_Symbol arg, SDF_Symbol right);
ATbool SDF_hasSymbolArguments(SDF_Symbol arg);
SDF_Symbols SDF_getSymbolArguments(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolArguments(SDF_Symbol arg, SDF_Symbols arguments);
ATbool SDF_hasSymbolWsAfterArguments(SDF_Symbol arg);
char * SDF_getSymbolWsAfterArguments(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterArguments(SDF_Symbol arg, char * wsAfterArguments);
ATbool SDF_hasSymbolWsAfterEqualsGreaterThan(SDF_Symbol arg);
char * SDF_getSymbolWsAfterEqualsGreaterThan(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterEqualsGreaterThan(SDF_Symbol arg, char * wsAfterEqualsGreaterThan);
ATbool SDF_hasSymbolResults(SDF_Symbol arg);
SDF_Symbol SDF_getSymbolResults(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolResults(SDF_Symbol arg, SDF_Symbol results);
ATbool SDF_hasSymbolWsAfterResults(SDF_Symbol arg);
char * SDF_getSymbolWsAfterResults(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterResults(SDF_Symbol arg, char * wsAfterResults);
ATbool SDF_hasSymbolWsAfterBar(SDF_Symbol arg);
char * SDF_getSymbolWsAfterBar(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterBar(SDF_Symbol arg, char * wsAfterBar);
ATbool SDF_hasSymbolWsAfterLessThanLessThan(SDF_Symbol arg);
char * SDF_getSymbolWsAfterLessThanLessThan(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterLessThanLessThan(SDF_Symbol arg, char * wsAfterLessThanLessThan);
ATbool SDF_hasSymbolSymbols(SDF_Symbol arg);
SDF_Symbols SDF_getSymbolSymbols(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolSymbols(SDF_Symbol arg, SDF_Symbols Symbols);
ATbool SDF_hasSymbolWsAfterSymbols(SDF_Symbol arg);
char * SDF_getSymbolWsAfterSymbols(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterSymbols(SDF_Symbol arg, char * wsAfterSymbols);
ATbool SDF_hasSymbolCharClass(SDF_Symbol arg);
SDF_CharClass SDF_getSymbolCharClass(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolCharClass(SDF_Symbol arg, SDF_CharClass CharClass);
ATbool SDF_hasSymbolSort(SDF_Symbol arg);
SDF_Sort SDF_getSymbolSort(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolSort(SDF_Symbol arg, SDF_Sort Sort);
ATbool SDF_hasSymbolLiteral(SDF_Symbol arg);
SDF_Literal SDF_getSymbolLiteral(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolLiteral(SDF_Symbol arg, SDF_Literal Literal);
ATbool SDF_hasSymbolLabel(SDF_Symbol arg);
SDF_Literal SDF_getSymbolLabel(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolLabel(SDF_Symbol arg, SDF_Literal label);
ATbool SDF_hasSymbolWsAfterLabel(SDF_Symbol arg);
char * SDF_getSymbolWsAfterLabel(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterLabel(SDF_Symbol arg, char * wsAfterLabel);
ATbool SDF_hasSymbolWsAfterColon(SDF_Symbol arg);
char * SDF_getSymbolWsAfterColon(SDF_Symbol arg);
SDF_Symbol SDF_setSymbolWsAfterColon(SDF_Symbol arg, char * wsAfterColon);

/*}}}  */
/*{{{  SDF_Grammar accessors */

ATbool SDF_isValidGrammar(SDF_Grammar arg);
inline ATbool SDF_isGrammarLexicalPriorities(SDF_Grammar arg);
inline ATbool SDF_isGrammarContextFreePriorities(SDF_Grammar arg);
inline ATbool SDF_isGrammarLexicalRestrictions(SDF_Grammar arg);
inline ATbool SDF_isGrammarContextFreeRestrictions(SDF_Grammar arg);
inline ATbool SDF_isGrammarSyntax(SDF_Grammar arg);
inline ATbool SDF_isGrammarLexicalSyntax(SDF_Grammar arg);
inline ATbool SDF_isGrammarContextFreeSyntax(SDF_Grammar arg);
inline ATbool SDF_isGrammarVariables(SDF_Grammar arg);
inline ATbool SDF_isGrammarLexicalVariables(SDF_Grammar arg);
inline ATbool SDF_isGrammarImpSection(SDF_Grammar arg);
inline ATbool SDF_isGrammarPriorities(SDF_Grammar arg);
inline ATbool SDF_isGrammarSorts(SDF_Grammar arg);
inline ATbool SDF_isGrammarRestrictions(SDF_Grammar arg);
inline ATbool SDF_isGrammarAliases(SDF_Grammar arg);
inline ATbool SDF_isGrammarEmptyGrammar(SDF_Grammar arg);
inline ATbool SDF_isGrammarConcGrammars(SDF_Grammar arg);
inline ATbool SDF_isGrammarBracket(SDF_Grammar arg);
ATbool SDF_hasGrammarWsAfterLexical(SDF_Grammar arg);
char * SDF_getGrammarWsAfterLexical(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterLexical(SDF_Grammar arg, char * wsAfterLexical);
ATbool SDF_hasGrammarWsAfterPriorities(SDF_Grammar arg);
char * SDF_getGrammarWsAfterPriorities(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterPriorities(SDF_Grammar arg, char * wsAfterPriorities);
ATbool SDF_hasGrammarPriorities(SDF_Grammar arg);
SDF_Priorities SDF_getGrammarPriorities(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarPriorities(SDF_Grammar arg, SDF_Priorities Priorities);
ATbool SDF_hasGrammarWsAfterContextFree(SDF_Grammar arg);
char * SDF_getGrammarWsAfterContextFree(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterContextFree(SDF_Grammar arg, char * wsAfterContextFree);
ATbool SDF_hasGrammarWsAfterRestrictions(SDF_Grammar arg);
char * SDF_getGrammarWsAfterRestrictions(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterRestrictions(SDF_Grammar arg, char * wsAfterRestrictions);
ATbool SDF_hasGrammarRestrictions(SDF_Grammar arg);
SDF_Restrictions SDF_getGrammarRestrictions(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarRestrictions(SDF_Grammar arg, SDF_Restrictions Restrictions);
ATbool SDF_hasGrammarWsAfterSyntax(SDF_Grammar arg);
char * SDF_getGrammarWsAfterSyntax(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterSyntax(SDF_Grammar arg, char * wsAfterSyntax);
ATbool SDF_hasGrammarProductions(SDF_Grammar arg);
SDF_Productions SDF_getGrammarProductions(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarProductions(SDF_Grammar arg, SDF_Productions Productions);
ATbool SDF_hasGrammarWsAfterVariables(SDF_Grammar arg);
char * SDF_getGrammarWsAfterVariables(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterVariables(SDF_Grammar arg, char * wsAfterVariables);
ATbool SDF_hasGrammarImpSection(SDF_Grammar arg);
SDF_ImpSection SDF_getGrammarImpSection(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarImpSection(SDF_Grammar arg, SDF_ImpSection ImpSection);
ATbool SDF_hasGrammarWsAfterSorts(SDF_Grammar arg);
char * SDF_getGrammarWsAfterSorts(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterSorts(SDF_Grammar arg, char * wsAfterSorts);
ATbool SDF_hasGrammarSymbols(SDF_Grammar arg);
SDF_Symbols SDF_getGrammarSymbols(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarSymbols(SDF_Grammar arg, SDF_Symbols Symbols);
ATbool SDF_hasGrammarWsAfterAliases(SDF_Grammar arg);
char * SDF_getGrammarWsAfterAliases(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterAliases(SDF_Grammar arg, char * wsAfterAliases);
ATbool SDF_hasGrammarAliases(SDF_Grammar arg);
SDF_Aliases SDF_getGrammarAliases(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarAliases(SDF_Grammar arg, SDF_Aliases Aliases);
ATbool SDF_hasGrammarLeft(SDF_Grammar arg);
SDF_Grammar SDF_getGrammarLeft(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarLeft(SDF_Grammar arg, SDF_Grammar left);
ATbool SDF_hasGrammarWsAfterLeft(SDF_Grammar arg);
char * SDF_getGrammarWsAfterLeft(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterLeft(SDF_Grammar arg, char * wsAfterLeft);
ATbool SDF_hasGrammarRight(SDF_Grammar arg);
SDF_Grammar SDF_getGrammarRight(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarRight(SDF_Grammar arg, SDF_Grammar right);
ATbool SDF_hasGrammarWsAfterParenOpen(SDF_Grammar arg);
char * SDF_getGrammarWsAfterParenOpen(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterParenOpen(SDF_Grammar arg, char * wsAfterParenOpen);
ATbool SDF_hasGrammarGrammar(SDF_Grammar arg);
SDF_Grammar SDF_getGrammarGrammar(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarGrammar(SDF_Grammar arg, SDF_Grammar Grammar);
ATbool SDF_hasGrammarWsAfterGrammar(SDF_Grammar arg);
char * SDF_getGrammarWsAfterGrammar(SDF_Grammar arg);
SDF_Grammar SDF_setGrammarWsAfterGrammar(SDF_Grammar arg, char * wsAfterGrammar);

/*}}}  */
/*{{{  SDF_SDF accessors */

ATbool SDF_isValidSDF(SDF_SDF arg);
inline ATbool SDF_isSDFDefinition(SDF_SDF arg);
ATbool SDF_hasSDFWsAfterDefinition(SDF_SDF arg);
char * SDF_getSDFWsAfterDefinition(SDF_SDF arg);
SDF_SDF SDF_setSDFWsAfterDefinition(SDF_SDF arg, char * wsAfterDefinition);
ATbool SDF_hasSDFDefinition(SDF_SDF arg);
SDF_Definition SDF_getSDFDefinition(SDF_SDF arg);
SDF_SDF SDF_setSDFDefinition(SDF_SDF arg, SDF_Definition Definition);

/*}}}  */
/*{{{  SDF_Attributes accessors */

ATbool SDF_isValidAttributes(SDF_Attributes arg);
inline ATbool SDF_isAttributesAttrs(SDF_Attributes arg);
inline ATbool SDF_isAttributesNoAttrs(SDF_Attributes arg);
ATbool SDF_hasAttributesWsAfterBraceOpen(SDF_Attributes arg);
char * SDF_getAttributesWsAfterBraceOpen(SDF_Attributes arg);
SDF_Attributes SDF_setAttributesWsAfterBraceOpen(SDF_Attributes arg, char * wsAfterBraceOpen);
ATbool SDF_hasAttributesList(SDF_Attributes arg);
SDF_AttributeList SDF_getAttributesList(SDF_Attributes arg);
SDF_Attributes SDF_setAttributesList(SDF_Attributes arg, SDF_AttributeList list);
ATbool SDF_hasAttributesWsAfterList(SDF_Attributes arg);
char * SDF_getAttributesWsAfterList(SDF_Attributes arg);
SDF_Attributes SDF_setAttributesWsAfterList(SDF_Attributes arg, char * wsAfterList);

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
char * SDF_getAttributeListWsAfterFirst(SDF_AttributeList arg);
SDF_AttributeList SDF_setAttributeListWsAfterFirst(SDF_AttributeList arg, char * wsAfterFirst);
ATbool SDF_hasAttributeListSep(SDF_AttributeList arg);
char * SDF_getAttributeListSep(SDF_AttributeList arg);
SDF_AttributeList SDF_setAttributeListSep(SDF_AttributeList arg, char * sep);
ATbool SDF_hasAttributeListWsAfterSep(SDF_AttributeList arg);
char * SDF_getAttributeListWsAfterSep(SDF_AttributeList arg);
SDF_AttributeList SDF_setAttributeListWsAfterSep(SDF_AttributeList arg, char * wsAfterSep);
ATbool SDF_hasAttributeListTail(SDF_AttributeList arg);
SDF_AttributeList SDF_getAttributeListTail(SDF_AttributeList arg);
SDF_AttributeList SDF_setAttributeListTail(SDF_AttributeList arg, SDF_AttributeList tail);

/*}}}  */
/*{{{  SDF_Production accessors */

ATbool SDF_isValidProduction(SDF_Production arg);
inline ATbool SDF_isProductionProd(SDF_Production arg);
inline ATbool SDF_isProductionProdFun(SDF_Production arg);
ATbool SDF_hasProductionSymbols(SDF_Production arg);
SDF_Symbols SDF_getProductionSymbols(SDF_Production arg);
SDF_Production SDF_setProductionSymbols(SDF_Production arg, SDF_Symbols Symbols);
ATbool SDF_hasProductionWsAfterSymbols(SDF_Production arg);
char * SDF_getProductionWsAfterSymbols(SDF_Production arg);
SDF_Production SDF_setProductionWsAfterSymbols(SDF_Production arg, char * wsAfterSymbols);
ATbool SDF_hasProductionWsAfterGreaterThan(SDF_Production arg);
char * SDF_getProductionWsAfterGreaterThan(SDF_Production arg);
SDF_Production SDF_setProductionWsAfterGreaterThan(SDF_Production arg, char * wsAfterGreaterThan);
ATbool SDF_hasProductionResult(SDF_Production arg);
SDF_Symbol SDF_getProductionResult(SDF_Production arg);
SDF_Production SDF_setProductionResult(SDF_Production arg, SDF_Symbol result);
ATbool SDF_hasProductionWsAfterResult(SDF_Production arg);
char * SDF_getProductionWsAfterResult(SDF_Production arg);
SDF_Production SDF_setProductionWsAfterResult(SDF_Production arg, char * wsAfterResult);
ATbool SDF_hasProductionAttributes(SDF_Production arg);
SDF_Attributes SDF_getProductionAttributes(SDF_Production arg);
SDF_Production SDF_setProductionAttributes(SDF_Production arg, SDF_Attributes Attributes);
ATbool SDF_hasProductionFunctionSymbol(SDF_Production arg);
SDF_Literal SDF_getProductionFunctionSymbol(SDF_Production arg);
SDF_Production SDF_setProductionFunctionSymbol(SDF_Production arg, SDF_Literal functionSymbol);
ATbool SDF_hasProductionWsAfterFunctionSymbol(SDF_Production arg);
char * SDF_getProductionWsAfterFunctionSymbol(SDF_Production arg);
SDF_Production SDF_setProductionWsAfterFunctionSymbol(SDF_Production arg, char * wsAfterFunctionSymbol);
ATbool SDF_hasProductionWsAfterParenOpen(SDF_Production arg);
char * SDF_getProductionWsAfterParenOpen(SDF_Production arg);
SDF_Production SDF_setProductionWsAfterParenOpen(SDF_Production arg, char * wsAfterParenOpen);
ATbool SDF_hasProductionArguments(SDF_Production arg);
SDF_SymbolArguments SDF_getProductionArguments(SDF_Production arg);
SDF_Production SDF_setProductionArguments(SDF_Production arg, SDF_SymbolArguments arguments);
ATbool SDF_hasProductionWsAfterArguments(SDF_Production arg);
char * SDF_getProductionWsAfterArguments(SDF_Production arg);
SDF_Production SDF_setProductionWsAfterArguments(SDF_Production arg, char * wsAfterArguments);
ATbool SDF_hasProductionWsAfterParenClose(SDF_Production arg);
char * SDF_getProductionWsAfterParenClose(SDF_Production arg);
SDF_Production SDF_setProductionWsAfterParenClose(SDF_Production arg, char * wsAfterParenClose);

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
char * SDF_getProductionListWsAfterFirst(SDF_ProductionList arg);
SDF_ProductionList SDF_setProductionListWsAfterFirst(SDF_ProductionList arg, char * wsAfterFirst);
ATbool SDF_hasProductionListTail(SDF_ProductionList arg);
SDF_ProductionList SDF_getProductionListTail(SDF_ProductionList arg);
SDF_ProductionList SDF_setProductionListTail(SDF_ProductionList arg, SDF_ProductionList tail);

/*}}}  */
/*{{{  SDF_ModuleWord accessors */

ATbool SDF_isValidModuleWord(SDF_ModuleWord arg);
inline ATbool SDF_isModuleWordWord(SDF_ModuleWord arg);
ATbool SDF_hasModuleWordLex(SDF_ModuleWord arg);
char * SDF_getModuleWordLex(SDF_ModuleWord arg);
SDF_ModuleWord SDF_setModuleWordLex(SDF_ModuleWord arg, char * lex);

/*}}}  */
/*{{{  SDF_ModuleId accessors */

ATbool SDF_isValidModuleId(SDF_ModuleId arg);
inline ATbool SDF_isModuleIdWord(SDF_ModuleId arg);
inline ATbool SDF_isModuleIdSlashWord(SDF_ModuleId arg);
inline ATbool SDF_isModuleIdWordSlashWord(SDF_ModuleId arg);
ATbool SDF_hasModuleIdLex(SDF_ModuleId arg);
char * SDF_getModuleIdLex(SDF_ModuleId arg);
SDF_ModuleId SDF_setModuleIdLex(SDF_ModuleId arg, char * lex);

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
char * SDF_getModuleListWsAfterFirst(SDF_ModuleList arg);
SDF_ModuleList SDF_setModuleListWsAfterFirst(SDF_ModuleList arg, char * wsAfterFirst);
ATbool SDF_hasModuleListTail(SDF_ModuleList arg);
SDF_ModuleList SDF_getModuleListTail(SDF_ModuleList arg);
SDF_ModuleList SDF_setModuleListTail(SDF_ModuleList arg, SDF_ModuleList tail);

/*}}}  */
/*{{{  SDF_Module accessors */

ATbool SDF_isValidModule(SDF_Module arg);
inline ATbool SDF_isModuleModule(SDF_Module arg);
ATbool SDF_hasModuleWsAfterModule(SDF_Module arg);
char * SDF_getModuleWsAfterModule(SDF_Module arg);
SDF_Module SDF_setModuleWsAfterModule(SDF_Module arg, char * wsAfterModule);
ATbool SDF_hasModuleModuleName(SDF_Module arg);
SDF_ModuleName SDF_getModuleModuleName(SDF_Module arg);
SDF_Module SDF_setModuleModuleName(SDF_Module arg, SDF_ModuleName ModuleName);
ATbool SDF_hasModuleWsAfterModuleName(SDF_Module arg);
char * SDF_getModuleWsAfterModuleName(SDF_Module arg);
SDF_Module SDF_setModuleWsAfterModuleName(SDF_Module arg, char * wsAfterModuleName);
ATbool SDF_hasModuleList(SDF_Module arg);
SDF_ImpSectionList SDF_getModuleList(SDF_Module arg);
SDF_Module SDF_setModuleList(SDF_Module arg, SDF_ImpSectionList list);
ATbool SDF_hasModuleWsAfterList(SDF_Module arg);
char * SDF_getModuleWsAfterList(SDF_Module arg);
SDF_Module SDF_setModuleWsAfterList(SDF_Module arg, char * wsAfterList);
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
char * SDF_getImpSectionListWsAfterFirst(SDF_ImpSectionList arg);
SDF_ImpSectionList SDF_setImpSectionListWsAfterFirst(SDF_ImpSectionList arg, char * wsAfterFirst);
ATbool SDF_hasImpSectionListTail(SDF_ImpSectionList arg);
SDF_ImpSectionList SDF_getImpSectionListTail(SDF_ImpSectionList arg);
SDF_ImpSectionList SDF_setImpSectionListTail(SDF_ImpSectionList arg, SDF_ImpSectionList tail);

/*}}}  */
/*{{{  SDF_Section accessors */

ATbool SDF_isValidSection(SDF_Section arg);
inline ATbool SDF_isSectionExports(SDF_Section arg);
inline ATbool SDF_isSectionHiddens(SDF_Section arg);
ATbool SDF_hasSectionWsAfterExports(SDF_Section arg);
char * SDF_getSectionWsAfterExports(SDF_Section arg);
SDF_Section SDF_setSectionWsAfterExports(SDF_Section arg, char * wsAfterExports);
ATbool SDF_hasSectionGrammar(SDF_Section arg);
SDF_Grammar SDF_getSectionGrammar(SDF_Section arg);
SDF_Section SDF_setSectionGrammar(SDF_Section arg, SDF_Grammar Grammar);
ATbool SDF_hasSectionWsAfterHiddens(SDF_Section arg);
char * SDF_getSectionWsAfterHiddens(SDF_Section arg);
SDF_Section SDF_setSectionWsAfterHiddens(SDF_Section arg, char * wsAfterHiddens);

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
char * SDF_getSectionListWsAfterFirst(SDF_SectionList arg);
SDF_SectionList SDF_setSectionListWsAfterFirst(SDF_SectionList arg, char * wsAfterFirst);
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
char * SDF_getModuleNameWsAfterModuleId(SDF_ModuleName arg);
SDF_ModuleName SDF_setModuleNameWsAfterModuleId(SDF_ModuleName arg, char * wsAfterModuleId);
ATbool SDF_hasModuleNameWsAfterBracketOpen(SDF_ModuleName arg);
char * SDF_getModuleNameWsAfterBracketOpen(SDF_ModuleName arg);
SDF_ModuleName SDF_setModuleNameWsAfterBracketOpen(SDF_ModuleName arg, char * wsAfterBracketOpen);
ATbool SDF_hasModuleNameParams(SDF_ModuleName arg);
SDF_Symbols SDF_getModuleNameParams(SDF_ModuleName arg);
SDF_ModuleName SDF_setModuleNameParams(SDF_ModuleName arg, SDF_Symbols params);
ATbool SDF_hasModuleNameWsAfterParams(SDF_ModuleName arg);
char * SDF_getModuleNameWsAfterParams(SDF_ModuleName arg);
SDF_ModuleName SDF_setModuleNameWsAfterParams(SDF_ModuleName arg, char * wsAfterParams);

/*}}}  */
/*{{{  SDF_Attribute accessors */

ATbool SDF_isValidAttribute(SDF_Attribute arg);
inline ATbool SDF_isAttributeId(SDF_Attribute arg);
inline ATbool SDF_isAttributeBracket(SDF_Attribute arg);
inline ATbool SDF_isAttributeAtr(SDF_Attribute arg);
inline ATbool SDF_isAttributeCons(SDF_Attribute arg);
inline ATbool SDF_isAttributeConstructor(SDF_Attribute arg);
inline ATbool SDF_isAttributeMemo(SDF_Attribute arg);
inline ATbool SDF_isAttributeTraverse(SDF_Attribute arg);
inline ATbool SDF_isAttributeReject(SDF_Attribute arg);
inline ATbool SDF_isAttributePrefer(SDF_Attribute arg);
inline ATbool SDF_isAttributeAvoid(SDF_Attribute arg);
ATbool SDF_hasAttributeWsAfterId(SDF_Attribute arg);
char * SDF_getAttributeWsAfterId(SDF_Attribute arg);
SDF_Attribute SDF_setAttributeWsAfterId(SDF_Attribute arg, char * wsAfterId);
ATbool SDF_hasAttributeWsAfterParenOpen(SDF_Attribute arg);
char * SDF_getAttributeWsAfterParenOpen(SDF_Attribute arg);
SDF_Attribute SDF_setAttributeWsAfterParenOpen(SDF_Attribute arg, char * wsAfterParenOpen);
ATbool SDF_hasAttributeModuleName(SDF_Attribute arg);
SDF_ModuleName SDF_getAttributeModuleName(SDF_Attribute arg);
SDF_Attribute SDF_setAttributeModuleName(SDF_Attribute arg, SDF_ModuleName ModuleName);
ATbool SDF_hasAttributeWsAfterModuleName(SDF_Attribute arg);
char * SDF_getAttributeWsAfterModuleName(SDF_Attribute arg);
SDF_Attribute SDF_setAttributeWsAfterModuleName(SDF_Attribute arg, char * wsAfterModuleName);
ATbool SDF_hasAttributeAssociativity(SDF_Attribute arg);
SDF_Associativity SDF_getAttributeAssociativity(SDF_Attribute arg);
SDF_Attribute SDF_setAttributeAssociativity(SDF_Attribute arg, SDF_Associativity Associativity);
ATbool SDF_hasAttributeWsAfterCons(SDF_Attribute arg);
char * SDF_getAttributeWsAfterCons(SDF_Attribute arg);
SDF_Attribute SDF_setAttributeWsAfterCons(SDF_Attribute arg, char * wsAfterCons);
ATbool SDF_hasAttributeTerm(SDF_Attribute arg);
SDF_ATerm SDF_getAttributeTerm(SDF_Attribute arg);
SDF_Attribute SDF_setAttributeTerm(SDF_Attribute arg, SDF_ATerm term);
ATbool SDF_hasAttributeWsAfterTerm(SDF_Attribute arg);
char * SDF_getAttributeWsAfterTerm(SDF_Attribute arg);
SDF_Attribute SDF_setAttributeWsAfterTerm(SDF_Attribute arg, char * wsAfterTerm);

/*}}}  */
/*{{{  SDF_ImpSection accessors */

ATbool SDF_isValidImpSection(SDF_ImpSection arg);
inline ATbool SDF_isImpSectionImports(SDF_ImpSection arg);
ATbool SDF_hasImpSectionWsAfterImports(SDF_ImpSection arg);
char * SDF_getImpSectionWsAfterImports(SDF_ImpSection arg);
SDF_ImpSection SDF_setImpSectionWsAfterImports(SDF_ImpSection arg, char * wsAfterImports);
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
char * SDF_getImportListWsAfterFirst(SDF_ImportList arg);
SDF_ImportList SDF_setImportListWsAfterFirst(SDF_ImportList arg, char * wsAfterFirst);
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
char * SDF_getImportWsAfterModuleName(SDF_Import arg);
SDF_Import SDF_setImportWsAfterModuleName(SDF_Import arg, char * wsAfterModuleName);
ATbool SDF_hasImportRenamings(SDF_Import arg);
SDF_Renamings SDF_getImportRenamings(SDF_Import arg);
SDF_Import SDF_setImportRenamings(SDF_Import arg, SDF_Renamings Renamings);
ATbool SDF_hasImportWsAfterParenOpen(SDF_Import arg);
char * SDF_getImportWsAfterParenOpen(SDF_Import arg);
SDF_Import SDF_setImportWsAfterParenOpen(SDF_Import arg, char * wsAfterParenOpen);
ATbool SDF_hasImportImport(SDF_Import arg);
SDF_Import SDF_getImportImport(SDF_Import arg);
SDF_Import SDF_setImportImport(SDF_Import arg, SDF_Import Import);
ATbool SDF_hasImportWsAfterImport(SDF_Import arg);
char * SDF_getImportWsAfterImport(SDF_Import arg);
SDF_Import SDF_setImportWsAfterImport(SDF_Import arg, char * wsAfterImport);

/*}}}  */
/*{{{  SDF_SymbolTail accessors */

ATbool SDF_isValidSymbolTail(SDF_SymbolTail arg);
inline ATbool SDF_isSymbolTailSingle(SDF_SymbolTail arg);
inline ATbool SDF_isSymbolTailMany(SDF_SymbolTail arg);
ATbool SDF_hasSymbolTailHead(SDF_SymbolTail arg);
SDF_Symbol SDF_getSymbolTailHead(SDF_SymbolTail arg);
SDF_SymbolTail SDF_setSymbolTailHead(SDF_SymbolTail arg, SDF_Symbol head);
ATbool SDF_hasSymbolTailWsAfterFirst(SDF_SymbolTail arg);
char * SDF_getSymbolTailWsAfterFirst(SDF_SymbolTail arg);
SDF_SymbolTail SDF_setSymbolTailWsAfterFirst(SDF_SymbolTail arg, char * wsAfterFirst);
ATbool SDF_hasSymbolTailTail(SDF_SymbolTail arg);
SDF_SymbolTail SDF_getSymbolTailTail(SDF_SymbolTail arg);
SDF_SymbolTail SDF_setSymbolTailTail(SDF_SymbolTail arg, SDF_SymbolTail tail);

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
char * SDF_getGroupWsAfterBraceOpen(SDF_Group arg);
SDF_Group SDF_setGroupWsAfterBraceOpen(SDF_Group arg, char * wsAfterBraceOpen);
ATbool SDF_hasGroupProductions(SDF_Group arg);
SDF_Productions SDF_getGroupProductions(SDF_Group arg);
SDF_Group SDF_setGroupProductions(SDF_Group arg, SDF_Productions Productions);
ATbool SDF_hasGroupWsAfterProductions(SDF_Group arg);
char * SDF_getGroupWsAfterProductions(SDF_Group arg);
SDF_Group SDF_setGroupWsAfterProductions(SDF_Group arg, char * wsAfterProductions);
ATbool SDF_hasGroupAssociativity(SDF_Group arg);
SDF_Associativity SDF_getGroupAssociativity(SDF_Group arg);
SDF_Group SDF_setGroupAssociativity(SDF_Group arg, SDF_Associativity Associativity);
ATbool SDF_hasGroupWsAfterAssociativity(SDF_Group arg);
char * SDF_getGroupWsAfterAssociativity(SDF_Group arg);
SDF_Group SDF_setGroupWsAfterAssociativity(SDF_Group arg, char * wsAfterAssociativity);
ATbool SDF_hasGroupWsAfterColon(SDF_Group arg);
char * SDF_getGroupWsAfterColon(SDF_Group arg);
SDF_Group SDF_setGroupWsAfterColon(SDF_Group arg, char * wsAfterColon);

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
char * SDF_getPriorityWsAfterLeft(SDF_Priority arg);
SDF_Priority SDF_setPriorityWsAfterLeft(SDF_Priority arg, char * wsAfterLeft);
ATbool SDF_hasPriorityAssociativity(SDF_Priority arg);
SDF_Associativity SDF_getPriorityAssociativity(SDF_Priority arg);
SDF_Priority SDF_setPriorityAssociativity(SDF_Priority arg, SDF_Associativity Associativity);
ATbool SDF_hasPriorityWsAfterAssociativity(SDF_Priority arg);
char * SDF_getPriorityWsAfterAssociativity(SDF_Priority arg);
SDF_Priority SDF_setPriorityWsAfterAssociativity(SDF_Priority arg, char * wsAfterAssociativity);
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
char * SDF_getGroupListWsAfterFirst(SDF_GroupList arg);
SDF_GroupList SDF_setGroupListWsAfterFirst(SDF_GroupList arg, char * wsAfterFirst);
ATbool SDF_hasGroupListSep(SDF_GroupList arg);
char * SDF_getGroupListSep(SDF_GroupList arg);
SDF_GroupList SDF_setGroupListSep(SDF_GroupList arg, char * sep);
ATbool SDF_hasGroupListWsAfterSep(SDF_GroupList arg);
char * SDF_getGroupListWsAfterSep(SDF_GroupList arg);
SDF_GroupList SDF_setGroupListWsAfterSep(SDF_GroupList arg, char * wsAfterSep);
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
char * SDF_getPriorityListWsAfterFirst(SDF_PriorityList arg);
SDF_PriorityList SDF_setPriorityListWsAfterFirst(SDF_PriorityList arg, char * wsAfterFirst);
ATbool SDF_hasPriorityListSep(SDF_PriorityList arg);
char * SDF_getPriorityListSep(SDF_PriorityList arg);
SDF_PriorityList SDF_setPriorityListSep(SDF_PriorityList arg, char * sep);
ATbool SDF_hasPriorityListWsAfterSep(SDF_PriorityList arg);
char * SDF_getPriorityListWsAfterSep(SDF_PriorityList arg);
SDF_PriorityList SDF_setPriorityListWsAfterSep(SDF_PriorityList arg, char * wsAfterSep);
ATbool SDF_hasPriorityListTail(SDF_PriorityList arg);
SDF_PriorityList SDF_getPriorityListTail(SDF_PriorityList arg);
SDF_PriorityList SDF_setPriorityListTail(SDF_PriorityList arg, SDF_PriorityList tail);

/*}}}  */
/*{{{  SDF_Sort accessors */

ATbool SDF_isValidSort(SDF_Sort arg);
inline ATbool SDF_isSortOneChar(SDF_Sort arg);
inline ATbool SDF_isSortMoreChars(SDF_Sort arg);
ATbool SDF_hasSortLex(SDF_Sort arg);
char * SDF_getSortLex(SDF_Sort arg);
SDF_Sort SDF_setSortLex(SDF_Sort arg, char * lex);

/*}}}  */
/*{{{  SDF_UQLiteral accessors */

ATbool SDF_isValidUQLiteral(SDF_UQLiteral arg);
inline ATbool SDF_isUQLiteralOneChar(SDF_UQLiteral arg);
inline ATbool SDF_isUQLiteralMoreChars(SDF_UQLiteral arg);
ATbool SDF_hasUQLiteralLex(SDF_UQLiteral arg);
char * SDF_getUQLiteralLex(SDF_UQLiteral arg);
SDF_UQLiteral SDF_setUQLiteralLex(SDF_UQLiteral arg, char * lex);

/*}}}  */
/*{{{  SDF_Literal accessors */

ATbool SDF_isValidLiteral(SDF_Literal arg);
inline ATbool SDF_isLiteralUqlit(SDF_Literal arg);
inline ATbool SDF_isLiteralQuoted(SDF_Literal arg);
ATbool SDF_hasLiteralUQLiteral(SDF_Literal arg);
SDF_UQLiteral SDF_getLiteralUQLiteral(SDF_Literal arg);
SDF_Literal SDF_setLiteralUQLiteral(SDF_Literal arg, SDF_UQLiteral UQLiteral);
ATbool SDF_hasLiteralLex(SDF_Literal arg);
char * SDF_getLiteralLex(SDF_Literal arg);
SDF_Literal SDF_setLiteralLex(SDF_Literal arg, char * lex);

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
char * SDF_getSymbolArgumentsWsAfterFirst(SDF_SymbolArguments arg);
SDF_SymbolArguments SDF_setSymbolArgumentsWsAfterFirst(SDF_SymbolArguments arg, char * wsAfterFirst);
ATbool SDF_hasSymbolArgumentsSep(SDF_SymbolArguments arg);
char * SDF_getSymbolArgumentsSep(SDF_SymbolArguments arg);
SDF_SymbolArguments SDF_setSymbolArgumentsSep(SDF_SymbolArguments arg, char * sep);
ATbool SDF_hasSymbolArgumentsWsAfterSep(SDF_SymbolArguments arg);
char * SDF_getSymbolArgumentsWsAfterSep(SDF_SymbolArguments arg);
SDF_SymbolArguments SDF_setSymbolArgumentsWsAfterSep(SDF_SymbolArguments arg, char * wsAfterSep);
ATbool SDF_hasSymbolArgumentsTail(SDF_SymbolArguments arg);
SDF_SymbolArguments SDF_getSymbolArgumentsTail(SDF_SymbolArguments arg);
SDF_SymbolArguments SDF_setSymbolArgumentsTail(SDF_SymbolArguments arg, SDF_SymbolArguments tail);

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
char * SDF_getLookaheadWsAfterHead(SDF_Lookahead arg);
SDF_Lookahead SDF_setLookaheadWsAfterHead(SDF_Lookahead arg, char * wsAfterHead);
ATbool SDF_hasLookaheadWsAfterPeriod(SDF_Lookahead arg);
char * SDF_getLookaheadWsAfterPeriod(SDF_Lookahead arg);
SDF_Lookahead SDF_setLookaheadWsAfterPeriod(SDF_Lookahead arg, char * wsAfterPeriod);
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
char * SDF_getLookaheadsWsAfterLeft(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsWsAfterLeft(SDF_Lookaheads arg, char * wsAfterLeft);
ATbool SDF_hasLookaheadsWsAfterBar(SDF_Lookaheads arg);
char * SDF_getLookaheadsWsAfterBar(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsWsAfterBar(SDF_Lookaheads arg, char * wsAfterBar);
ATbool SDF_hasLookaheadsRight(SDF_Lookaheads arg);
SDF_Lookaheads SDF_getLookaheadsRight(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsRight(SDF_Lookaheads arg, SDF_Lookaheads right);
ATbool SDF_hasLookaheadsWsAfterParenOpen(SDF_Lookaheads arg);
char * SDF_getLookaheadsWsAfterParenOpen(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsWsAfterParenOpen(SDF_Lookaheads arg, char * wsAfterParenOpen);
ATbool SDF_hasLookaheadsLookaheads(SDF_Lookaheads arg);
SDF_Lookaheads SDF_getLookaheadsLookaheads(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsLookaheads(SDF_Lookaheads arg, SDF_Lookaheads Lookaheads);
ATbool SDF_hasLookaheadsWsAfterLookaheads(SDF_Lookaheads arg);
char * SDF_getLookaheadsWsAfterLookaheads(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsWsAfterLookaheads(SDF_Lookaheads arg, char * wsAfterLookaheads);
ATbool SDF_hasLookaheadsWsAfterBracketOpenBracketOpen(SDF_Lookaheads arg);
char * SDF_getLookaheadsWsAfterBracketOpenBracketOpen(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsWsAfterBracketOpenBracketOpen(SDF_Lookaheads arg, char * wsAfterBracketOpenBracketOpen);
ATbool SDF_hasLookaheadsList(SDF_Lookaheads arg);
SDF_LookaheadList SDF_getLookaheadsList(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsList(SDF_Lookaheads arg, SDF_LookaheadList list);
ATbool SDF_hasLookaheadsWsAfterList(SDF_Lookaheads arg);
char * SDF_getLookaheadsWsAfterList(SDF_Lookaheads arg);
SDF_Lookaheads SDF_setLookaheadsWsAfterList(SDF_Lookaheads arg, char * wsAfterList);

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
char * SDF_getLookaheadListWsAfterFirst(SDF_LookaheadList arg);
SDF_LookaheadList SDF_setLookaheadListWsAfterFirst(SDF_LookaheadList arg, char * wsAfterFirst);
ATbool SDF_hasLookaheadListSep(SDF_LookaheadList arg);
char * SDF_getLookaheadListSep(SDF_LookaheadList arg);
SDF_LookaheadList SDF_setLookaheadListSep(SDF_LookaheadList arg, char * sep);
ATbool SDF_hasLookaheadListWsAfterSep(SDF_LookaheadList arg);
char * SDF_getLookaheadListWsAfterSep(SDF_LookaheadList arg);
SDF_LookaheadList SDF_setLookaheadListWsAfterSep(SDF_LookaheadList arg, char * wsAfterSep);
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
char * SDF_getRestrictionWsAfterSymbols(SDF_Restriction arg);
SDF_Restriction SDF_setRestrictionWsAfterSymbols(SDF_Restriction arg, char * wsAfterSymbols);
ATbool SDF_hasRestrictionWsAfterSlash(SDF_Restriction arg);
char * SDF_getRestrictionWsAfterSlash(SDF_Restriction arg);
SDF_Restriction SDF_setRestrictionWsAfterSlash(SDF_Restriction arg, char * wsAfterSlash);
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
char * SDF_getRestrictionListWsAfterFirst(SDF_RestrictionList arg);
SDF_RestrictionList SDF_setRestrictionListWsAfterFirst(SDF_RestrictionList arg, char * wsAfterFirst);
ATbool SDF_hasRestrictionListTail(SDF_RestrictionList arg);
SDF_RestrictionList SDF_getRestrictionListTail(SDF_RestrictionList arg);
SDF_RestrictionList SDF_setRestrictionListTail(SDF_RestrictionList arg, SDF_RestrictionList tail);

/*}}}  */
/*{{{  SDF_Alias accessors */

ATbool SDF_isValidAlias(SDF_Alias arg);
inline ATbool SDF_isAliasAlias(SDF_Alias arg);
ATbool SDF_hasAliasSymbol(SDF_Alias arg);
SDF_Symbol SDF_getAliasSymbol(SDF_Alias arg);
SDF_Alias SDF_setAliasSymbol(SDF_Alias arg, SDF_Symbol Symbol);
ATbool SDF_hasAliasWsAfterSymbol(SDF_Alias arg);
char * SDF_getAliasWsAfterSymbol(SDF_Alias arg);
SDF_Alias SDF_setAliasWsAfterSymbol(SDF_Alias arg, char * wsAfterSymbol);
ATbool SDF_hasAliasWsAfterArrow(SDF_Alias arg);
char * SDF_getAliasWsAfterArrow(SDF_Alias arg);
SDF_Alias SDF_setAliasWsAfterArrow(SDF_Alias arg, char * wsAfterArrow);
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
char * SDF_getAliasListWsAfterFirst(SDF_AliasList arg);
SDF_AliasList SDF_setAliasListWsAfterFirst(SDF_AliasList arg, char * wsAfterFirst);
ATbool SDF_hasAliasListTail(SDF_AliasList arg);
SDF_AliasList SDF_getAliasListTail(SDF_AliasList arg);
SDF_AliasList SDF_setAliasListTail(SDF_AliasList arg, SDF_AliasList tail);

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
char * SDF_getSymbolListWsAfterFirst(SDF_SymbolList arg);
SDF_SymbolList SDF_setSymbolListWsAfterFirst(SDF_SymbolList arg, char * wsAfterFirst);
ATbool SDF_hasSymbolListTail(SDF_SymbolList arg);
SDF_SymbolList SDF_getSymbolListTail(SDF_SymbolList arg);
SDF_SymbolList SDF_setSymbolListTail(SDF_SymbolList arg, SDF_SymbolList tail);

/*}}}  */
/*{{{  SDF_Renamings accessors */

ATbool SDF_isValidRenamings(SDF_Renamings arg);
inline ATbool SDF_isRenamingsRenamings(SDF_Renamings arg);
ATbool SDF_hasRenamingsWsAfterBracketOpen(SDF_Renamings arg);
char * SDF_getRenamingsWsAfterBracketOpen(SDF_Renamings arg);
SDF_Renamings SDF_setRenamingsWsAfterBracketOpen(SDF_Renamings arg, char * wsAfterBracketOpen);
ATbool SDF_hasRenamingsList(SDF_Renamings arg);
SDF_RenamingList SDF_getRenamingsList(SDF_Renamings arg);
SDF_Renamings SDF_setRenamingsList(SDF_Renamings arg, SDF_RenamingList list);
ATbool SDF_hasRenamingsWsAfterList(SDF_Renamings arg);
char * SDF_getRenamingsWsAfterList(SDF_Renamings arg);
SDF_Renamings SDF_setRenamingsWsAfterList(SDF_Renamings arg, char * wsAfterList);

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
char * SDF_getRenamingListWsAfterFirst(SDF_RenamingList arg);
SDF_RenamingList SDF_setRenamingListWsAfterFirst(SDF_RenamingList arg, char * wsAfterFirst);
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
char * SDF_getRenamingWsAfterFrom(SDF_Renaming arg);
SDF_Renaming SDF_setRenamingWsAfterFrom(SDF_Renaming arg, char * wsAfterFrom);
ATbool SDF_hasRenamingWsAfterEqualsGreaterThan(SDF_Renaming arg);
char * SDF_getRenamingWsAfterEqualsGreaterThan(SDF_Renaming arg);
SDF_Renaming SDF_setRenamingWsAfterEqualsGreaterThan(SDF_Renaming arg, char * wsAfterEqualsGreaterThan);
ATbool SDF_hasRenamingTo(SDF_Renaming arg);
SDF_Symbol SDF_getRenamingTo(SDF_Renaming arg);
SDF_Renaming SDF_setRenamingTo(SDF_Renaming arg, SDF_Symbol to);

/*}}}  */
/*{{{  SDF_NatCon accessors */

ATbool SDF_isValidNatCon(SDF_NatCon arg);
inline ATbool SDF_isNatConDigits(SDF_NatCon arg);
ATbool SDF_hasNatConLex(SDF_NatCon arg);
char * SDF_getNatConLex(SDF_NatCon arg);
SDF_NatCon SDF_setNatConLex(SDF_NatCon arg, char * lex);

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
char * SDF_getIntConWsAfterPos(SDF_IntCon arg);
SDF_IntCon SDF_setIntConWsAfterPos(SDF_IntCon arg, char * wsAfterPos);
ATbool SDF_hasIntConWsAfterNeg(SDF_IntCon arg);
char * SDF_getIntConWsAfterNeg(SDF_IntCon arg);
SDF_IntCon SDF_setIntConWsAfterNeg(SDF_IntCon arg, char * wsAfterNeg);

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
char * SDF_getCharRangeWsAfterStart(SDF_CharRange arg);
SDF_CharRange SDF_setCharRangeWsAfterStart(SDF_CharRange arg, char * wsAfterStart);
ATbool SDF_hasCharRangeWsAfter(SDF_CharRange arg);
char * SDF_getCharRangeWsAfter(SDF_CharRange arg);
SDF_CharRange SDF_setCharRangeWsAfter(SDF_CharRange arg, char * wsAfter);
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
char * SDF_getCharRangesWsAfterLeft(SDF_CharRanges arg);
SDF_CharRanges SDF_setCharRangesWsAfterLeft(SDF_CharRanges arg, char * wsAfterLeft);
ATbool SDF_hasCharRangesRight(SDF_CharRanges arg);
SDF_CharRanges SDF_getCharRangesRight(SDF_CharRanges arg);
SDF_CharRanges SDF_setCharRangesRight(SDF_CharRanges arg, SDF_CharRanges right);
ATbool SDF_hasCharRangesWsAfterParenOpen(SDF_CharRanges arg);
char * SDF_getCharRangesWsAfterParenOpen(SDF_CharRanges arg);
SDF_CharRanges SDF_setCharRangesWsAfterParenOpen(SDF_CharRanges arg, char * wsAfterParenOpen);
ATbool SDF_hasCharRangesCharRanges(SDF_CharRanges arg);
SDF_CharRanges SDF_getCharRangesCharRanges(SDF_CharRanges arg);
SDF_CharRanges SDF_setCharRangesCharRanges(SDF_CharRanges arg, SDF_CharRanges CharRanges);
ATbool SDF_hasCharRangesWsAfterCharRanges(SDF_CharRanges arg);
char * SDF_getCharRangesWsAfterCharRanges(SDF_CharRanges arg);
SDF_CharRanges SDF_setCharRangesWsAfterCharRanges(SDF_CharRanges arg, char * wsAfterCharRanges);

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
inline ATbool SDF_isCharClassBracket(SDF_CharClass arg);
ATbool SDF_hasCharClassWsAfterBracketOpen(SDF_CharClass arg);
char * SDF_getCharClassWsAfterBracketOpen(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterBracketOpen(SDF_CharClass arg, char * wsAfterBracketOpen);
ATbool SDF_hasCharClassOptCharRanges(SDF_CharClass arg);
SDF_OptCharRanges SDF_getCharClassOptCharRanges(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassOptCharRanges(SDF_CharClass arg, SDF_OptCharRanges OptCharRanges);
ATbool SDF_hasCharClassWsAfterOptCharRanges(SDF_CharClass arg);
char * SDF_getCharClassWsAfterOptCharRanges(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterOptCharRanges(SDF_CharClass arg, char * wsAfterOptCharRanges);
ATbool SDF_hasCharClassWsAfterTilde(SDF_CharClass arg);
char * SDF_getCharClassWsAfterTilde(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterTilde(SDF_CharClass arg, char * wsAfterTilde);
ATbool SDF_hasCharClassCharClass(SDF_CharClass arg);
SDF_CharClass SDF_getCharClassCharClass(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassCharClass(SDF_CharClass arg, SDF_CharClass CharClass);
ATbool SDF_hasCharClassLeft(SDF_CharClass arg);
SDF_CharClass SDF_getCharClassLeft(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassLeft(SDF_CharClass arg, SDF_CharClass left);
ATbool SDF_hasCharClassWsAfterLeft(SDF_CharClass arg);
char * SDF_getCharClassWsAfterLeft(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterLeft(SDF_CharClass arg, char * wsAfterLeft);
ATbool SDF_hasCharClassWsAfterSlash(SDF_CharClass arg);
char * SDF_getCharClassWsAfterSlash(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterSlash(SDF_CharClass arg, char * wsAfterSlash);
ATbool SDF_hasCharClassRight(SDF_CharClass arg);
SDF_CharClass SDF_getCharClassRight(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassRight(SDF_CharClass arg, SDF_CharClass right);
ATbool SDF_hasCharClassWsAfterSlashBackslash(SDF_CharClass arg);
char * SDF_getCharClassWsAfterSlashBackslash(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterSlashBackslash(SDF_CharClass arg, char * wsAfterSlashBackslash);
ATbool SDF_hasCharClassWsAfterBackslashSlash(SDF_CharClass arg);
char * SDF_getCharClassWsAfterBackslashSlash(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterBackslashSlash(SDF_CharClass arg, char * wsAfterBackslashSlash);
ATbool SDF_hasCharClassWsAfterParenOpen(SDF_CharClass arg);
char * SDF_getCharClassWsAfterParenOpen(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterParenOpen(SDF_CharClass arg, char * wsAfterParenOpen);
ATbool SDF_hasCharClassWsAfterCharClass(SDF_CharClass arg);
char * SDF_getCharClassWsAfterCharClass(SDF_CharClass arg);
SDF_CharClass SDF_setCharClassWsAfterCharClass(SDF_CharClass arg, char * wsAfterCharClass);

/*}}}  */
/*{{{  SDF_AlphaNumericalEscChar accessors */

ATbool SDF_isValidAlphaNumericalEscChar(SDF_AlphaNumericalEscChar arg);
inline ATbool SDF_isAlphaNumericalEscCharDefault(SDF_AlphaNumericalEscChar arg);
ATbool SDF_hasAlphaNumericalEscCharLex(SDF_AlphaNumericalEscChar arg);
char * SDF_getAlphaNumericalEscCharLex(SDF_AlphaNumericalEscChar arg);
SDF_AlphaNumericalEscChar SDF_setAlphaNumericalEscCharLex(SDF_AlphaNumericalEscChar arg, char * lex);

/*}}}  */
/*{{{  SDF_DecimalEscChar accessors */

ATbool SDF_isValidDecimalEscChar(SDF_DecimalEscChar arg);
inline ATbool SDF_isDecimalEscCharDec0Underscore199(SDF_DecimalEscChar arg);
inline ATbool SDF_isDecimalEscCharDec200Underscore249(SDF_DecimalEscChar arg);
inline ATbool SDF_isDecimalEscCharDec250Underscore255(SDF_DecimalEscChar arg);
ATbool SDF_hasDecimalEscCharLex(SDF_DecimalEscChar arg);
char * SDF_getDecimalEscCharLex(SDF_DecimalEscChar arg);
SDF_DecimalEscChar SDF_setDecimalEscCharLex(SDF_DecimalEscChar arg, char * lex);

/*}}}  */
/*{{{  SDF_EscChar accessors */

ATbool SDF_isValidEscChar(SDF_EscChar arg);
inline ATbool SDF_isEscCharAlphaNumeric(SDF_EscChar arg);
inline ATbool SDF_isEscCharDecimal(SDF_EscChar arg);
ATbool SDF_hasEscCharLex(SDF_EscChar arg);
char * SDF_getEscCharLex(SDF_EscChar arg);
SDF_EscChar SDF_setEscCharLex(SDF_EscChar arg, char * lex);

/*}}}  */
/*{{{  SDF_LChar accessors */

ATbool SDF_isValidLChar(SDF_LChar arg);
inline ATbool SDF_isLCharNormal(SDF_LChar arg);
inline ATbool SDF_isLCharEscaped(SDF_LChar arg);
ATbool SDF_hasLCharLex(SDF_LChar arg);
char * SDF_getLCharLex(SDF_LChar arg);
SDF_LChar SDF_setLCharLex(SDF_LChar arg, char * lex);

/*}}}  */
/*{{{  SDF_ATerms accessors */

ATbool SDF_isValidATerms(SDF_ATerms arg);
inline ATbool SDF_isATermsAterm(SDF_ATerms arg);
inline ATbool SDF_isATermsCons(SDF_ATerms arg);
ATbool SDF_hasATermsTerm(SDF_ATerms arg);
SDF_ATerm SDF_getATermsTerm(SDF_ATerms arg);
SDF_ATerms SDF_setATermsTerm(SDF_ATerms arg, SDF_ATerm term);
ATbool SDF_hasATermsHead(SDF_ATerms arg);
SDF_ATerm SDF_getATermsHead(SDF_ATerms arg);
SDF_ATerms SDF_setATermsHead(SDF_ATerms arg, SDF_ATerm head);
ATbool SDF_hasATermsWsAfterHead(SDF_ATerms arg);
char * SDF_getATermsWsAfterHead(SDF_ATerms arg);
SDF_ATerms SDF_setATermsWsAfterHead(SDF_ATerms arg, char * wsAfterHead);
ATbool SDF_hasATermsWsAfterComma(SDF_ATerms arg);
char * SDF_getATermsWsAfterComma(SDF_ATerms arg);
SDF_ATerms SDF_setATermsWsAfterComma(SDF_ATerms arg, char * wsAfterComma);
ATbool SDF_hasATermsTail(SDF_ATerms arg);
SDF_ATerms SDF_getATermsTail(SDF_ATerms arg);
SDF_ATerms SDF_setATermsTail(SDF_ATerms arg, SDF_ATerms tail);

/*}}}  */
/*{{{  SDF_ATermList accessors */

ATbool SDF_isValidATermList(SDF_ATermList arg);
inline ATbool SDF_isATermListEmpty(SDF_ATermList arg);
inline ATbool SDF_isATermListNotEmpty(SDF_ATermList arg);
ATbool SDF_hasATermListWsAfterBracketOpen(SDF_ATermList arg);
char * SDF_getATermListWsAfterBracketOpen(SDF_ATermList arg);
SDF_ATermList SDF_setATermListWsAfterBracketOpen(SDF_ATermList arg, char * wsAfterBracketOpen);
ATbool SDF_hasATermListATerms(SDF_ATermList arg);
SDF_ATerms SDF_getATermListATerms(SDF_ATermList arg);
SDF_ATermList SDF_setATermListATerms(SDF_ATermList arg, SDF_ATerms ATerms);
ATbool SDF_hasATermListWsAfterATerms(SDF_ATermList arg);
char * SDF_getATermListWsAfterATerms(SDF_ATermList arg);
SDF_ATermList SDF_setATermListWsAfterATerms(SDF_ATermList arg, char * wsAfterATerms);

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
char * SDF_getATermWsAfterFun(SDF_ATerm arg);
SDF_ATerm SDF_setATermWsAfterFun(SDF_ATerm arg, char * wsAfterFun);
ATbool SDF_hasATermWsAfterParenOpen(SDF_ATerm arg);
char * SDF_getATermWsAfterParenOpen(SDF_ATerm arg);
SDF_ATerm SDF_setATermWsAfterParenOpen(SDF_ATerm arg, char * wsAfterParenOpen);
ATbool SDF_hasATermArgs(SDF_ATerm arg);
SDF_ATerms SDF_getATermArgs(SDF_ATerm arg);
SDF_ATerm SDF_setATermArgs(SDF_ATerm arg, SDF_ATerms args);
ATbool SDF_hasATermWsAfterArgs(SDF_ATerm arg);
char * SDF_getATermWsAfterArgs(SDF_ATerm arg);
SDF_ATerm SDF_setATermWsAfterArgs(SDF_ATerm arg, char * wsAfterArgs);
ATbool SDF_hasATermWsAfterACon(SDF_ATerm arg);
char * SDF_getATermWsAfterACon(SDF_ATerm arg);
SDF_ATerm SDF_setATermWsAfterACon(SDF_ATerm arg, char * wsAfterACon);
ATbool SDF_hasATermAnn(SDF_ATerm arg);
SDF_Ann SDF_getATermAnn(SDF_ATerm arg);
SDF_ATerm SDF_setATermAnn(SDF_ATerm arg, SDF_Ann Ann);
ATbool SDF_hasATermWsAfterList(SDF_ATerm arg);
char * SDF_getATermWsAfterList(SDF_ATerm arg);
SDF_ATerm SDF_setATermWsAfterList(SDF_ATerm arg, char * wsAfterList);
ATbool SDF_hasATermWsAfterParenClose(SDF_ATerm arg);
char * SDF_getATermWsAfterParenClose(SDF_ATerm arg);
SDF_ATerm SDF_setATermWsAfterParenClose(SDF_ATerm arg, char * wsAfterParenClose);

/*}}}  */
/*{{{  SDF_Ann accessors */

ATbool SDF_isValidAnn(SDF_Ann arg);
inline ATbool SDF_isAnnAnnotation(SDF_Ann arg);
ATbool SDF_hasAnnWsAfterBraceOpen(SDF_Ann arg);
char * SDF_getAnnWsAfterBraceOpen(SDF_Ann arg);
SDF_Ann SDF_setAnnWsAfterBraceOpen(SDF_Ann arg, char * wsAfterBraceOpen);
ATbool SDF_hasAnnATerms(SDF_Ann arg);
SDF_ATerms SDF_getAnnATerms(SDF_Ann arg);
SDF_Ann SDF_setAnnATerms(SDF_Ann arg, SDF_ATerms ATerms);
ATbool SDF_hasAnnWsAfterATerms(SDF_Ann arg);
char * SDF_getAnnWsAfterATerms(SDF_Ann arg);
SDF_Ann SDF_setAnnWsAfterATerms(SDF_Ann arg, char * wsAfterATerms);

/*}}}  */
/*{{{  SDF_TagId accessors */

ATbool SDF_isValidTagId(SDF_TagId arg);
inline ATbool SDF_isTagIdDefault(SDF_TagId arg);
inline ATbool SDF_isTagIdEmpty(SDF_TagId arg);
ATbool SDF_hasTagIdLex(SDF_TagId arg);
char * SDF_getTagIdLex(SDF_TagId arg);
SDF_TagId SDF_setTagIdLex(SDF_TagId arg, char * lex);

/*}}}  */
/*{{{  SDF_NumChar accessors */

ATbool SDF_isValidNumChar(SDF_NumChar arg);
inline ATbool SDF_isNumCharDigits(SDF_NumChar arg);
ATbool SDF_hasNumCharLex(SDF_NumChar arg);
char * SDF_getNumCharLex(SDF_NumChar arg);
SDF_NumChar SDF_setNumCharLex(SDF_NumChar arg, char * lex);

/*}}}  */
/*{{{  SDF_ShortChar accessors */

ATbool SDF_isValidShortChar(SDF_ShortChar arg);
inline ATbool SDF_isShortCharRegular(SDF_ShortChar arg);
inline ATbool SDF_isShortCharEscaped(SDF_ShortChar arg);
ATbool SDF_hasShortCharLex(SDF_ShortChar arg);
char * SDF_getShortCharLex(SDF_ShortChar arg);
SDF_ShortChar SDF_setShortCharLex(SDF_ShortChar arg, char * lex);

/*}}}  */
/*{{{  SDF_Character accessors */

ATbool SDF_isValidCharacter(SDF_Character arg);
inline ATbool SDF_isCharacterNumeric(SDF_Character arg);
inline ATbool SDF_isCharacterShort(SDF_Character arg);
inline ATbool SDF_isCharacterTop(SDF_Character arg);
inline ATbool SDF_isCharacterEof(SDF_Character arg);
ATbool SDF_hasCharacterNumChar(SDF_Character arg);
SDF_NumChar SDF_getCharacterNumChar(SDF_Character arg);
SDF_Character SDF_setCharacterNumChar(SDF_Character arg, SDF_NumChar NumChar);
ATbool SDF_hasCharacterShortChar(SDF_Character arg);
SDF_ShortChar SDF_getCharacterShortChar(SDF_Character arg);
SDF_Character SDF_setCharacterShortChar(SDF_Character arg, SDF_ShortChar ShortChar);

/*}}}  */
/*{{{  SDF_OptExp accessors */

ATbool SDF_isValidOptExp(SDF_OptExp arg);
inline ATbool SDF_isOptExpPresent(SDF_OptExp arg);
inline ATbool SDF_isOptExpAbsent(SDF_OptExp arg);
ATbool SDF_hasOptExpWsAfterE(SDF_OptExp arg);
char * SDF_getOptExpWsAfterE(SDF_OptExp arg);
SDF_OptExp SDF_setOptExpWsAfterE(SDF_OptExp arg, char * wsAfterE);
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
char * SDF_getRealConWsAfterIntCon(SDF_RealCon arg);
SDF_RealCon SDF_setRealConWsAfterIntCon(SDF_RealCon arg, char * wsAfterIntCon);
ATbool SDF_hasRealConWsAfterPeriod(SDF_RealCon arg);
char * SDF_getRealConWsAfterPeriod(SDF_RealCon arg);
SDF_RealCon SDF_setRealConWsAfterPeriod(SDF_RealCon arg, char * wsAfterPeriod);
ATbool SDF_hasRealConNatCon(SDF_RealCon arg);
SDF_NatCon SDF_getRealConNatCon(SDF_RealCon arg);
SDF_RealCon SDF_setRealConNatCon(SDF_RealCon arg, SDF_NatCon NatCon);
ATbool SDF_hasRealConWsAfterNatCon(SDF_RealCon arg);
char * SDF_getRealConWsAfterNatCon(SDF_RealCon arg);
SDF_RealCon SDF_setRealConWsAfterNatCon(SDF_RealCon arg, char * wsAfterNatCon);
ATbool SDF_hasRealConOptExp(SDF_RealCon arg);
SDF_OptExp SDF_getRealConOptExp(SDF_RealCon arg);
SDF_RealCon SDF_setRealConOptExp(SDF_RealCon arg, SDF_OptExp OptExp);

/*}}}  */
/*{{{  sort visitors */

SDF_Symbol SDF_visitSymbol(SDF_Symbol arg, char * (*acceptWsAfterLessThan)(char *), char * (*acceptWsAfterSymbol)(char *), char * (*acceptWsAfterCF)(char *), char * (*acceptWsAfterLEX)(char *), char * (*acceptWsAfterVAR)(char *), char * (*acceptWsAfterParenOpen)(char *), char * (*acceptWsAfterHead)(char *), SDF_SymbolTail (*acceptTail)(SDF_SymbolTail), char * (*acceptWsAfterTail)(char *), char * (*acceptWsAfterBraceOpen)(char *), char * (*acceptWsAfterSep)(char *), char * (*acceptWsAfterBraceClose)(char *), SDF_NatCon (*acceptN)(SDF_NatCon), char * (*acceptWsAfterN)(char *), char * (*acceptWsAfterSet)(char *), char * (*acceptWsAfterBracketOpen)(char *), char * (*acceptWsAfterLeft)(char *), char * (*acceptWsAfterHash)(char *), SDF_Symbols (*acceptArguments)(SDF_Symbols), char * (*acceptWsAfterArguments)(char *), char * (*acceptWsAfterEqualsGreaterThan)(char *), char * (*acceptWsAfterResults)(char *), char * (*acceptWsAfterBar)(char *), char * (*acceptWsAfterLessThanLessThan)(char *), SDF_Symbols (*acceptSymbols)(SDF_Symbols), char * (*acceptWsAfterSymbols)(char *), SDF_CharClass (*acceptCharClass)(SDF_CharClass), SDF_Sort (*acceptSort)(SDF_Sort), SDF_Literal (*acceptLiteral)(SDF_Literal), SDF_Literal (*acceptLabel)(SDF_Literal), char * (*acceptWsAfterLabel)(char *), char * (*acceptWsAfterColon)(char *));
SDF_Grammar SDF_visitGrammar(SDF_Grammar arg, char * (*acceptWsAfterLexical)(char *), char * (*acceptWsAfterPriorities)(char *), SDF_Priorities (*acceptPriorities)(SDF_Priorities), char * (*acceptWsAfterContextFree)(char *), char * (*acceptWsAfterRestrictions)(char *), SDF_Restrictions (*acceptRestrictions)(SDF_Restrictions), char * (*acceptWsAfterSyntax)(char *), SDF_Productions (*acceptProductions)(SDF_Productions), char * (*acceptWsAfterVariables)(char *), SDF_ImpSection (*acceptImpSection)(SDF_ImpSection), char * (*acceptWsAfterSorts)(char *), SDF_Symbols (*acceptSymbols)(SDF_Symbols), char * (*acceptWsAfterAliases)(char *), SDF_Aliases (*acceptAliases)(SDF_Aliases), char * (*acceptWsAfterLeft)(char *), char * (*acceptWsAfterParenOpen)(char *), char * (*acceptWsAfterGrammar)(char *));
SDF_SDF SDF_visitSDF(SDF_SDF arg, char * (*acceptWsAfterDefinition)(char *), SDF_Definition (*acceptDefinition)(SDF_Definition));
SDF_Attributes SDF_visitAttributes(SDF_Attributes arg, char * (*acceptWsAfterBraceOpen)(char *), SDF_AttributeList (*acceptList)(SDF_AttributeList), char * (*acceptWsAfterList)(char *));
SDF_AttributeList SDF_visitAttributeList(SDF_AttributeList arg, SDF_Attribute (*acceptHead)(SDF_Attribute), char * (*acceptWsAfterFirst)(char *), char * (*acceptSep)(char *), char * (*acceptWsAfterSep)(char *));
SDF_Production SDF_visitProduction(SDF_Production arg, SDF_Symbols (*acceptSymbols)(SDF_Symbols), char * (*acceptWsAfterSymbols)(char *), char * (*acceptWsAfterGreaterThan)(char *), SDF_Symbol (*acceptResult)(SDF_Symbol), char * (*acceptWsAfterResult)(char *), SDF_Attributes (*acceptAttributes)(SDF_Attributes), SDF_Literal (*acceptFunctionSymbol)(SDF_Literal), char * (*acceptWsAfterFunctionSymbol)(char *), char * (*acceptWsAfterParenOpen)(char *), SDF_SymbolArguments (*acceptArguments)(SDF_SymbolArguments), char * (*acceptWsAfterArguments)(char *), char * (*acceptWsAfterParenClose)(char *));
SDF_Productions SDF_visitProductions(SDF_Productions arg, SDF_ProductionList (*acceptList)(SDF_ProductionList));
SDF_ProductionList SDF_visitProductionList(SDF_ProductionList arg, SDF_Production (*acceptHead)(SDF_Production), char * (*acceptWsAfterFirst)(char *));
SDF_ModuleWord SDF_visitModuleWord(SDF_ModuleWord arg, char * (*acceptLex)(char *));
SDF_ModuleId SDF_visitModuleId(SDF_ModuleId arg, char * (*acceptLex)(char *));
SDF_Definition SDF_visitDefinition(SDF_Definition arg, SDF_ModuleList (*acceptList)(SDF_ModuleList));
SDF_ModuleList SDF_visitModuleList(SDF_ModuleList arg, SDF_Module (*acceptHead)(SDF_Module), char * (*acceptWsAfterFirst)(char *));
SDF_Module SDF_visitModule(SDF_Module arg, char * (*acceptWsAfterModule)(char *), SDF_ModuleName (*acceptModuleName)(SDF_ModuleName), char * (*acceptWsAfterModuleName)(char *), SDF_ImpSectionList (*acceptList)(SDF_ImpSectionList), char * (*acceptWsAfterList)(char *), SDF_Sections (*acceptSections)(SDF_Sections));
SDF_ImpSectionList SDF_visitImpSectionList(SDF_ImpSectionList arg, SDF_ImpSection (*acceptHead)(SDF_ImpSection), char * (*acceptWsAfterFirst)(char *));
SDF_Section SDF_visitSection(SDF_Section arg, char * (*acceptWsAfterExports)(char *), SDF_Grammar (*acceptGrammar)(SDF_Grammar), char * (*acceptWsAfterHiddens)(char *));
SDF_Sections SDF_visitSections(SDF_Sections arg, SDF_SectionList (*acceptList)(SDF_SectionList));
SDF_SectionList SDF_visitSectionList(SDF_SectionList arg, SDF_Section (*acceptHead)(SDF_Section), char * (*acceptWsAfterFirst)(char *));
SDF_ModuleName SDF_visitModuleName(SDF_ModuleName arg, SDF_ModuleId (*acceptModuleId)(SDF_ModuleId), char * (*acceptWsAfterModuleId)(char *), char * (*acceptWsAfterBracketOpen)(char *), SDF_Symbols (*acceptParams)(SDF_Symbols), char * (*acceptWsAfterParams)(char *));
SDF_Attribute SDF_visitAttribute(SDF_Attribute arg, char * (*acceptWsAfterId)(char *), char * (*acceptWsAfterParenOpen)(char *), SDF_ModuleName (*acceptModuleName)(SDF_ModuleName), char * (*acceptWsAfterModuleName)(char *), SDF_Associativity (*acceptAssociativity)(SDF_Associativity), char * (*acceptWsAfterCons)(char *), SDF_ATerm (*acceptTerm)(SDF_ATerm), char * (*acceptWsAfterTerm)(char *));
SDF_ImpSection SDF_visitImpSection(SDF_ImpSection arg, char * (*acceptWsAfterImports)(char *), SDF_Imports (*acceptList)(SDF_Imports));
SDF_Imports SDF_visitImports(SDF_Imports arg, SDF_ImportList (*acceptList)(SDF_ImportList));
SDF_ImportList SDF_visitImportList(SDF_ImportList arg, SDF_Import (*acceptHead)(SDF_Import), char * (*acceptWsAfterFirst)(char *));
SDF_Import SDF_visitImport(SDF_Import arg, SDF_ModuleName (*acceptModuleName)(SDF_ModuleName), char * (*acceptWsAfterModuleName)(char *), SDF_Renamings (*acceptRenamings)(SDF_Renamings), char * (*acceptWsAfterParenOpen)(char *), char * (*acceptWsAfterImport)(char *));
SDF_SymbolTail SDF_visitSymbolTail(SDF_SymbolTail arg, SDF_Symbol (*acceptHead)(SDF_Symbol), char * (*acceptWsAfterFirst)(char *));
SDF_Associativity SDF_visitAssociativity(SDF_Associativity arg);
SDF_Group SDF_visitGroup(SDF_Group arg, SDF_Production (*acceptProduction)(SDF_Production), char * (*acceptWsAfterBraceOpen)(char *), SDF_Productions (*acceptProductions)(SDF_Productions), char * (*acceptWsAfterProductions)(char *), SDF_Associativity (*acceptAssociativity)(SDF_Associativity), char * (*acceptWsAfterAssociativity)(char *), char * (*acceptWsAfterColon)(char *));
SDF_Priority SDF_visitPriority(SDF_Priority arg, SDF_GroupList (*acceptList)(SDF_GroupList), SDF_Group (*acceptLeft)(SDF_Group), char * (*acceptWsAfterLeft)(char *), SDF_Associativity (*acceptAssociativity)(SDF_Associativity), char * (*acceptWsAfterAssociativity)(char *), SDF_Group (*acceptRight)(SDF_Group));
SDF_GroupList SDF_visitGroupList(SDF_GroupList arg, SDF_Group (*acceptHead)(SDF_Group), char * (*acceptWsAfterFirst)(char *), char * (*acceptSep)(char *), char * (*acceptWsAfterSep)(char *));
SDF_Priorities SDF_visitPriorities(SDF_Priorities arg, SDF_PriorityList (*acceptList)(SDF_PriorityList));
SDF_PriorityList SDF_visitPriorityList(SDF_PriorityList arg, SDF_Priority (*acceptHead)(SDF_Priority), char * (*acceptWsAfterFirst)(char *), char * (*acceptSep)(char *), char * (*acceptWsAfterSep)(char *));
SDF_Sort SDF_visitSort(SDF_Sort arg, char * (*acceptLex)(char *));
SDF_UQLiteral SDF_visitUQLiteral(SDF_UQLiteral arg, char * (*acceptLex)(char *));
SDF_Literal SDF_visitLiteral(SDF_Literal arg, SDF_UQLiteral (*acceptUQLiteral)(SDF_UQLiteral), char * (*acceptLex)(char *));
SDF_SymbolArguments SDF_visitSymbolArguments(SDF_SymbolArguments arg, SDF_Symbol (*acceptHead)(SDF_Symbol), char * (*acceptWsAfterFirst)(char *), char * (*acceptSep)(char *), char * (*acceptWsAfterSep)(char *));
SDF_Lookahead SDF_visitLookahead(SDF_Lookahead arg, SDF_CharClass (*acceptCharClass)(SDF_CharClass), SDF_CharClass (*acceptHead)(SDF_CharClass), char * (*acceptWsAfterHead)(char *), char * (*acceptWsAfterPeriod)(char *), SDF_Lookaheads (*acceptTail)(SDF_Lookaheads));
SDF_Lookaheads SDF_visitLookaheads(SDF_Lookaheads arg, SDF_Lookahead (*acceptLookahead)(SDF_Lookahead), char * (*acceptWsAfterLeft)(char *), char * (*acceptWsAfterBar)(char *), char * (*acceptWsAfterParenOpen)(char *), char * (*acceptWsAfterLookaheads)(char *), char * (*acceptWsAfterBracketOpenBracketOpen)(char *), SDF_LookaheadList (*acceptList)(SDF_LookaheadList), char * (*acceptWsAfterList)(char *));
SDF_LookaheadList SDF_visitLookaheadList(SDF_LookaheadList arg, SDF_Lookahead (*acceptHead)(SDF_Lookahead), char * (*acceptWsAfterFirst)(char *), char * (*acceptSep)(char *), char * (*acceptWsAfterSep)(char *));
SDF_Restriction SDF_visitRestriction(SDF_Restriction arg, SDF_Symbols (*acceptSymbols)(SDF_Symbols), char * (*acceptWsAfterSymbols)(char *), char * (*acceptWsAfterSlash)(char *), SDF_Lookaheads (*acceptLookaheads)(SDF_Lookaheads));
SDF_Restrictions SDF_visitRestrictions(SDF_Restrictions arg, SDF_RestrictionList (*acceptList)(SDF_RestrictionList));
SDF_RestrictionList SDF_visitRestrictionList(SDF_RestrictionList arg, SDF_Restriction (*acceptHead)(SDF_Restriction), char * (*acceptWsAfterFirst)(char *));
SDF_Alias SDF_visitAlias(SDF_Alias arg, SDF_Symbol (*acceptSymbol)(SDF_Symbol), char * (*acceptWsAfterSymbol)(char *), char * (*acceptWsAfterArrow)(char *), SDF_Symbol (*acceptAlias)(SDF_Symbol));
SDF_Aliases SDF_visitAliases(SDF_Aliases arg, SDF_AliasList (*acceptList)(SDF_AliasList));
SDF_AliasList SDF_visitAliasList(SDF_AliasList arg, SDF_Alias (*acceptHead)(SDF_Alias), char * (*acceptWsAfterFirst)(char *));
SDF_Symbols SDF_visitSymbols(SDF_Symbols arg, SDF_SymbolList (*acceptList)(SDF_SymbolList));
SDF_SymbolList SDF_visitSymbolList(SDF_SymbolList arg, SDF_Symbol (*acceptHead)(SDF_Symbol), char * (*acceptWsAfterFirst)(char *));
SDF_Renamings SDF_visitRenamings(SDF_Renamings arg, char * (*acceptWsAfterBracketOpen)(char *), SDF_RenamingList (*acceptList)(SDF_RenamingList), char * (*acceptWsAfterList)(char *));
SDF_RenamingList SDF_visitRenamingList(SDF_RenamingList arg, SDF_Renaming (*acceptHead)(SDF_Renaming), char * (*acceptWsAfterFirst)(char *));
SDF_Renaming SDF_visitRenaming(SDF_Renaming arg, SDF_Symbol (*acceptFrom)(SDF_Symbol), char * (*acceptWsAfterFrom)(char *), char * (*acceptWsAfterEqualsGreaterThan)(char *), SDF_Symbol (*acceptTo)(SDF_Symbol));
SDF_NatCon SDF_visitNatCon(SDF_NatCon arg, char * (*acceptLex)(char *));
SDF_IntCon SDF_visitIntCon(SDF_IntCon arg, SDF_NatCon (*acceptNatCon)(SDF_NatCon), char * (*acceptWsAfterPos)(char *), char * (*acceptWsAfterNeg)(char *));
SDF_CharRange SDF_visitCharRange(SDF_CharRange arg, SDF_Character (*acceptCharacter)(SDF_Character), SDF_Character (*acceptStart)(SDF_Character), char * (*acceptWsAfterStart)(char *), char * (*acceptWsAfter)(char *), SDF_Character (*acceptEnd)(SDF_Character));
SDF_CharRanges SDF_visitCharRanges(SDF_CharRanges arg, SDF_CharRange (*acceptCharRange)(SDF_CharRange), char * (*acceptWsAfterLeft)(char *), char * (*acceptWsAfterParenOpen)(char *), char * (*acceptWsAfterCharRanges)(char *));
SDF_OptCharRanges SDF_visitOptCharRanges(SDF_OptCharRanges arg, SDF_CharRanges (*acceptCharRanges)(SDF_CharRanges));
SDF_CharClass SDF_visitCharClass(SDF_CharClass arg, char * (*acceptWsAfterBracketOpen)(char *), SDF_OptCharRanges (*acceptOptCharRanges)(SDF_OptCharRanges), char * (*acceptWsAfterOptCharRanges)(char *), char * (*acceptWsAfterTilde)(char *), char * (*acceptWsAfterLeft)(char *), char * (*acceptWsAfterSlash)(char *), char * (*acceptWsAfterSlashBackslash)(char *), char * (*acceptWsAfterBackslashSlash)(char *), char * (*acceptWsAfterParenOpen)(char *), char * (*acceptWsAfterCharClass)(char *));
SDF_AlphaNumericalEscChar SDF_visitAlphaNumericalEscChar(SDF_AlphaNumericalEscChar arg, char * (*acceptLex)(char *));
SDF_DecimalEscChar SDF_visitDecimalEscChar(SDF_DecimalEscChar arg, char * (*acceptLex)(char *));
SDF_EscChar SDF_visitEscChar(SDF_EscChar arg, char * (*acceptLex)(char *));
SDF_LChar SDF_visitLChar(SDF_LChar arg, char * (*acceptLex)(char *));
SDF_ATerms SDF_visitATerms(SDF_ATerms arg, SDF_ATerm (*acceptTerm)(SDF_ATerm), SDF_ATerm (*acceptHead)(SDF_ATerm), char * (*acceptWsAfterHead)(char *), char * (*acceptWsAfterComma)(char *));
SDF_ATermList SDF_visitATermList(SDF_ATermList arg, char * (*acceptWsAfterBracketOpen)(char *), SDF_ATerms (*acceptATerms)(SDF_ATerms), char * (*acceptWsAfterATerms)(char *));
SDF_ACon SDF_visitACon(SDF_ACon arg, SDF_IntCon (*acceptIntCon)(SDF_IntCon), SDF_RealCon (*acceptRealCon)(SDF_RealCon));
SDF_AFun SDF_visitAFun(SDF_AFun arg, SDF_Literal (*acceptLiteral)(SDF_Literal));
SDF_ATerm SDF_visitATerm(SDF_ATerm arg, SDF_ACon (*acceptACon)(SDF_ACon), SDF_ATermList (*acceptList)(SDF_ATermList), SDF_AFun (*acceptFun)(SDF_AFun), char * (*acceptWsAfterFun)(char *), char * (*acceptWsAfterParenOpen)(char *), SDF_ATerms (*acceptArgs)(SDF_ATerms), char * (*acceptWsAfterArgs)(char *), char * (*acceptWsAfterACon)(char *), SDF_Ann (*acceptAnn)(SDF_Ann), char * (*acceptWsAfterList)(char *), char * (*acceptWsAfterParenClose)(char *));
SDF_Ann SDF_visitAnn(SDF_Ann arg, char * (*acceptWsAfterBraceOpen)(char *), SDF_ATerms (*acceptATerms)(SDF_ATerms), char * (*acceptWsAfterATerms)(char *));
SDF_TagId SDF_visitTagId(SDF_TagId arg, char * (*acceptLex)(char *));
SDF_NumChar SDF_visitNumChar(SDF_NumChar arg, char * (*acceptLex)(char *));
SDF_ShortChar SDF_visitShortChar(SDF_ShortChar arg, char * (*acceptLex)(char *));
SDF_Character SDF_visitCharacter(SDF_Character arg, SDF_NumChar (*acceptNumChar)(SDF_NumChar), SDF_ShortChar (*acceptShortChar)(SDF_ShortChar));
SDF_OptExp SDF_visitOptExp(SDF_OptExp arg, char * (*acceptWsAfterE)(char *), SDF_IntCon (*acceptIntCon)(SDF_IntCon));
SDF_RealCon SDF_visitRealCon(SDF_RealCon arg, SDF_IntCon (*acceptIntCon)(SDF_IntCon), char * (*acceptWsAfterIntCon)(char *), char * (*acceptWsAfterPeriod)(char *), SDF_NatCon (*acceptNatCon)(SDF_NatCon), char * (*acceptWsAfterNatCon)(char *), SDF_OptExp (*acceptOptExp)(SDF_OptExp));

/*}}}  */

#endif /* _SDF_H */
