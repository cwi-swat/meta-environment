#include <aterm2.h>
#include <deprecated.h>
#include "SDF.h"

/*{{{  typedefs */

typedef struct ATerm _SDF_Symbol;
typedef struct ATerm _SDF_Grammar;
typedef struct ATerm _SDF_SDF;
typedef struct ATerm _SDF_Attributes;
typedef struct ATerm _SDF_AttributeList;
typedef struct ATerm _SDF_Production;
typedef struct ATerm _SDF_Productions;
typedef struct ATerm _SDF_ProductionList;
typedef struct ATerm _SDF_ModuleWord;
typedef struct ATerm _SDF_ModuleId;
typedef struct ATerm _SDF_Definition;
typedef struct ATerm _SDF_ModuleList;
typedef struct ATerm _SDF_Module;
typedef struct ATerm _SDF_ImpSectionList;
typedef struct ATerm _SDF_Section;
typedef struct ATerm _SDF_Sections;
typedef struct ATerm _SDF_SectionList;
typedef struct ATerm _SDF_ModuleName;
typedef struct ATerm _SDF_Attribute;
typedef struct ATerm _SDF_ImpSection;
typedef struct ATerm _SDF_Imports;
typedef struct ATerm _SDF_ImportList;
typedef struct ATerm _SDF_Import;
typedef struct ATerm _SDF_SymbolTail;
typedef struct ATerm _SDF_Associativity;
typedef struct ATerm _SDF_Group;
typedef struct ATerm _SDF_Priority;
typedef struct ATerm _SDF_GroupList;
typedef struct ATerm _SDF_Priorities;
typedef struct ATerm _SDF_PriorityList;
typedef struct ATerm _SDF_Sort;
typedef struct ATerm _SDF_UQLiteral;
typedef struct ATerm _SDF_Literal;
typedef struct ATerm _SDF_SymbolArguments;
typedef struct ATerm _SDF_Lookahead;
typedef struct ATerm _SDF_Lookaheads;
typedef struct ATerm _SDF_LookaheadList;
typedef struct ATerm _SDF_Restriction;
typedef struct ATerm _SDF_Restrictions;
typedef struct ATerm _SDF_RestrictionList;
typedef struct ATerm _SDF_Alias;
typedef struct ATerm _SDF_Aliases;
typedef struct ATerm _SDF_AliasList;
typedef struct ATerm _SDF_Symbols;
typedef struct ATerm _SDF_SymbolList;
typedef struct ATerm _SDF_Renamings;
typedef struct ATerm _SDF_RenamingList;
typedef struct ATerm _SDF_Renaming;
typedef struct ATerm _SDF_NatCon;
typedef struct ATerm _SDF_IntCon;
typedef struct ATerm _SDF_CharRange;
typedef struct ATerm _SDF_CharRanges;
typedef struct ATerm _SDF_OptCharRanges;
typedef struct ATerm _SDF_CharClass;
typedef struct ATerm _SDF_AlphaNumericalEscChar;
typedef struct ATerm _SDF_DecimalEscChar;
typedef struct ATerm _SDF_EscChar;
typedef struct ATerm _SDF_LChar;
typedef struct ATerm _SDF_ATerms;
typedef struct ATerm _SDF_ATermList;
typedef struct ATerm _SDF_ACon;
typedef struct ATerm _SDF_AFun;
typedef struct ATerm _SDF_ATerm;
typedef struct ATerm _SDF_Ann;
typedef struct ATerm _SDF_TagId;
typedef struct ATerm _SDF_NumChar;
typedef struct ATerm _SDF_ShortChar;
typedef struct ATerm _SDF_Character;
typedef struct ATerm _SDF_OptExp;
typedef struct ATerm _SDF_RealCon;

/*}}}  */

/*{{{  void SDF_initSDFApi(void) */

void SDF_initSDFApi(void)
{
  init_SDF_dict();
}

/*}}}  */

/*{{{  term conversion functions */

/*{{{  SDF_Symbol SDF_makeSymbolFromTerm(ATerm t) */

SDF_Symbol SDF_makeSymbolFromTerm(ATerm t)
{
  return (SDF_Symbol)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromSymbol(SDF_Symbol arg) */

ATerm SDF_makeTermFromSymbol(SDF_Symbol arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarFromTerm(ATerm t) */

SDF_Grammar SDF_makeGrammarFromTerm(ATerm t)
{
  return (SDF_Grammar)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromGrammar(SDF_Grammar arg) */

ATerm SDF_makeTermFromGrammar(SDF_Grammar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_SDF SDF_makeSDFFromTerm(ATerm t) */

SDF_SDF SDF_makeSDFFromTerm(ATerm t)
{
  return (SDF_SDF)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromSDF(SDF_SDF arg) */

ATerm SDF_makeTermFromSDF(SDF_SDF arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Attributes SDF_makeAttributesFromTerm(ATerm t) */

SDF_Attributes SDF_makeAttributesFromTerm(ATerm t)
{
  return (SDF_Attributes)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromAttributes(SDF_Attributes arg) */

ATerm SDF_makeTermFromAttributes(SDF_Attributes arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_AttributeList SDF_makeAttributeListFromTerm(ATerm t) */

SDF_AttributeList SDF_makeAttributeListFromTerm(ATerm t)
{
  return (SDF_AttributeList)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromAttributeList(SDF_AttributeList arg) */

ATerm SDF_makeTermFromAttributeList(SDF_AttributeList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Production SDF_makeProductionFromTerm(ATerm t) */

SDF_Production SDF_makeProductionFromTerm(ATerm t)
{
  return (SDF_Production)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromProduction(SDF_Production arg) */

ATerm SDF_makeTermFromProduction(SDF_Production arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Productions SDF_makeProductionsFromTerm(ATerm t) */

SDF_Productions SDF_makeProductionsFromTerm(ATerm t)
{
  return (SDF_Productions)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromProductions(SDF_Productions arg) */

ATerm SDF_makeTermFromProductions(SDF_Productions arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ProductionList SDF_makeProductionListFromTerm(ATerm t) */

SDF_ProductionList SDF_makeProductionListFromTerm(ATerm t)
{
  return (SDF_ProductionList)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromProductionList(SDF_ProductionList arg) */

ATerm SDF_makeTermFromProductionList(SDF_ProductionList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ModuleWord SDF_makeModuleWordFromTerm(ATerm t) */

SDF_ModuleWord SDF_makeModuleWordFromTerm(ATerm t)
{
  return (SDF_ModuleWord)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromModuleWord(SDF_ModuleWord arg) */

ATerm SDF_makeTermFromModuleWord(SDF_ModuleWord arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ModuleId SDF_makeModuleIdFromTerm(ATerm t) */

SDF_ModuleId SDF_makeModuleIdFromTerm(ATerm t)
{
  return (SDF_ModuleId)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromModuleId(SDF_ModuleId arg) */

ATerm SDF_makeTermFromModuleId(SDF_ModuleId arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Definition SDF_makeDefinitionFromTerm(ATerm t) */

SDF_Definition SDF_makeDefinitionFromTerm(ATerm t)
{
  return (SDF_Definition)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromDefinition(SDF_Definition arg) */

ATerm SDF_makeTermFromDefinition(SDF_Definition arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ModuleList SDF_makeModuleListFromTerm(ATerm t) */

SDF_ModuleList SDF_makeModuleListFromTerm(ATerm t)
{
  return (SDF_ModuleList)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromModuleList(SDF_ModuleList arg) */

ATerm SDF_makeTermFromModuleList(SDF_ModuleList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Module SDF_makeModuleFromTerm(ATerm t) */

SDF_Module SDF_makeModuleFromTerm(ATerm t)
{
  return (SDF_Module)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromModule(SDF_Module arg) */

ATerm SDF_makeTermFromModule(SDF_Module arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ImpSectionList SDF_makeImpSectionListFromTerm(ATerm t) */

SDF_ImpSectionList SDF_makeImpSectionListFromTerm(ATerm t)
{
  return (SDF_ImpSectionList)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromImpSectionList(SDF_ImpSectionList arg) */

ATerm SDF_makeTermFromImpSectionList(SDF_ImpSectionList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Section SDF_makeSectionFromTerm(ATerm t) */

SDF_Section SDF_makeSectionFromTerm(ATerm t)
{
  return (SDF_Section)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromSection(SDF_Section arg) */

ATerm SDF_makeTermFromSection(SDF_Section arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Sections SDF_makeSectionsFromTerm(ATerm t) */

SDF_Sections SDF_makeSectionsFromTerm(ATerm t)
{
  return (SDF_Sections)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromSections(SDF_Sections arg) */

ATerm SDF_makeTermFromSections(SDF_Sections arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_SectionList SDF_makeSectionListFromTerm(ATerm t) */

SDF_SectionList SDF_makeSectionListFromTerm(ATerm t)
{
  return (SDF_SectionList)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromSectionList(SDF_SectionList arg) */

ATerm SDF_makeTermFromSectionList(SDF_SectionList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_makeModuleNameFromTerm(ATerm t) */

SDF_ModuleName SDF_makeModuleNameFromTerm(ATerm t)
{
  return (SDF_ModuleName)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromModuleName(SDF_ModuleName arg) */

ATerm SDF_makeTermFromModuleName(SDF_ModuleName arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Attribute SDF_makeAttributeFromTerm(ATerm t) */

SDF_Attribute SDF_makeAttributeFromTerm(ATerm t)
{
  return (SDF_Attribute)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromAttribute(SDF_Attribute arg) */

ATerm SDF_makeTermFromAttribute(SDF_Attribute arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ImpSection SDF_makeImpSectionFromTerm(ATerm t) */

SDF_ImpSection SDF_makeImpSectionFromTerm(ATerm t)
{
  return (SDF_ImpSection)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromImpSection(SDF_ImpSection arg) */

ATerm SDF_makeTermFromImpSection(SDF_ImpSection arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Imports SDF_makeImportsFromTerm(ATerm t) */

SDF_Imports SDF_makeImportsFromTerm(ATerm t)
{
  return (SDF_Imports)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromImports(SDF_Imports arg) */

ATerm SDF_makeTermFromImports(SDF_Imports arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ImportList SDF_makeImportListFromTerm(ATerm t) */

SDF_ImportList SDF_makeImportListFromTerm(ATerm t)
{
  return (SDF_ImportList)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromImportList(SDF_ImportList arg) */

ATerm SDF_makeTermFromImportList(SDF_ImportList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Import SDF_makeImportFromTerm(ATerm t) */

SDF_Import SDF_makeImportFromTerm(ATerm t)
{
  return (SDF_Import)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromImport(SDF_Import arg) */

ATerm SDF_makeTermFromImport(SDF_Import arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_SymbolTail SDF_makeSymbolTailFromTerm(ATerm t) */

SDF_SymbolTail SDF_makeSymbolTailFromTerm(ATerm t)
{
  return (SDF_SymbolTail)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromSymbolTail(SDF_SymbolTail arg) */

ATerm SDF_makeTermFromSymbolTail(SDF_SymbolTail arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Associativity SDF_makeAssociativityFromTerm(ATerm t) */

SDF_Associativity SDF_makeAssociativityFromTerm(ATerm t)
{
  return (SDF_Associativity)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromAssociativity(SDF_Associativity arg) */

ATerm SDF_makeTermFromAssociativity(SDF_Associativity arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Group SDF_makeGroupFromTerm(ATerm t) */

SDF_Group SDF_makeGroupFromTerm(ATerm t)
{
  return (SDF_Group)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromGroup(SDF_Group arg) */

ATerm SDF_makeTermFromGroup(SDF_Group arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Priority SDF_makePriorityFromTerm(ATerm t) */

SDF_Priority SDF_makePriorityFromTerm(ATerm t)
{
  return (SDF_Priority)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromPriority(SDF_Priority arg) */

ATerm SDF_makeTermFromPriority(SDF_Priority arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_GroupList SDF_makeGroupListFromTerm(ATerm t) */

SDF_GroupList SDF_makeGroupListFromTerm(ATerm t)
{
  return (SDF_GroupList)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromGroupList(SDF_GroupList arg) */

ATerm SDF_makeTermFromGroupList(SDF_GroupList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Priorities SDF_makePrioritiesFromTerm(ATerm t) */

SDF_Priorities SDF_makePrioritiesFromTerm(ATerm t)
{
  return (SDF_Priorities)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromPriorities(SDF_Priorities arg) */

ATerm SDF_makeTermFromPriorities(SDF_Priorities arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_PriorityList SDF_makePriorityListFromTerm(ATerm t) */

SDF_PriorityList SDF_makePriorityListFromTerm(ATerm t)
{
  return (SDF_PriorityList)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromPriorityList(SDF_PriorityList arg) */

ATerm SDF_makeTermFromPriorityList(SDF_PriorityList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Sort SDF_makeSortFromTerm(ATerm t) */

SDF_Sort SDF_makeSortFromTerm(ATerm t)
{
  return (SDF_Sort)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromSort(SDF_Sort arg) */

ATerm SDF_makeTermFromSort(SDF_Sort arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_UQLiteral SDF_makeUQLiteralFromTerm(ATerm t) */

SDF_UQLiteral SDF_makeUQLiteralFromTerm(ATerm t)
{
  return (SDF_UQLiteral)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromUQLiteral(SDF_UQLiteral arg) */

ATerm SDF_makeTermFromUQLiteral(SDF_UQLiteral arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Literal SDF_makeLiteralFromTerm(ATerm t) */

SDF_Literal SDF_makeLiteralFromTerm(ATerm t)
{
  return (SDF_Literal)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromLiteral(SDF_Literal arg) */

ATerm SDF_makeTermFromLiteral(SDF_Literal arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_SymbolArguments SDF_makeSymbolArgumentsFromTerm(ATerm t) */

SDF_SymbolArguments SDF_makeSymbolArgumentsFromTerm(ATerm t)
{
  return (SDF_SymbolArguments)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromSymbolArguments(SDF_SymbolArguments arg) */

ATerm SDF_makeTermFromSymbolArguments(SDF_SymbolArguments arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_makeLookaheadFromTerm(ATerm t) */

SDF_Lookahead SDF_makeLookaheadFromTerm(ATerm t)
{
  return (SDF_Lookahead)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromLookahead(SDF_Lookahead arg) */

ATerm SDF_makeTermFromLookahead(SDF_Lookahead arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_makeLookaheadsFromTerm(ATerm t) */

SDF_Lookaheads SDF_makeLookaheadsFromTerm(ATerm t)
{
  return (SDF_Lookaheads)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromLookaheads(SDF_Lookaheads arg) */

ATerm SDF_makeTermFromLookaheads(SDF_Lookaheads arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_LookaheadList SDF_makeLookaheadListFromTerm(ATerm t) */

SDF_LookaheadList SDF_makeLookaheadListFromTerm(ATerm t)
{
  return (SDF_LookaheadList)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromLookaheadList(SDF_LookaheadList arg) */

ATerm SDF_makeTermFromLookaheadList(SDF_LookaheadList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Restriction SDF_makeRestrictionFromTerm(ATerm t) */

SDF_Restriction SDF_makeRestrictionFromTerm(ATerm t)
{
  return (SDF_Restriction)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromRestriction(SDF_Restriction arg) */

ATerm SDF_makeTermFromRestriction(SDF_Restriction arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Restrictions SDF_makeRestrictionsFromTerm(ATerm t) */

SDF_Restrictions SDF_makeRestrictionsFromTerm(ATerm t)
{
  return (SDF_Restrictions)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromRestrictions(SDF_Restrictions arg) */

ATerm SDF_makeTermFromRestrictions(SDF_Restrictions arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_RestrictionList SDF_makeRestrictionListFromTerm(ATerm t) */

SDF_RestrictionList SDF_makeRestrictionListFromTerm(ATerm t)
{
  return (SDF_RestrictionList)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromRestrictionList(SDF_RestrictionList arg) */

ATerm SDF_makeTermFromRestrictionList(SDF_RestrictionList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Alias SDF_makeAliasFromTerm(ATerm t) */

SDF_Alias SDF_makeAliasFromTerm(ATerm t)
{
  return (SDF_Alias)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromAlias(SDF_Alias arg) */

ATerm SDF_makeTermFromAlias(SDF_Alias arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Aliases SDF_makeAliasesFromTerm(ATerm t) */

SDF_Aliases SDF_makeAliasesFromTerm(ATerm t)
{
  return (SDF_Aliases)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromAliases(SDF_Aliases arg) */

ATerm SDF_makeTermFromAliases(SDF_Aliases arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_AliasList SDF_makeAliasListFromTerm(ATerm t) */

SDF_AliasList SDF_makeAliasListFromTerm(ATerm t)
{
  return (SDF_AliasList)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromAliasList(SDF_AliasList arg) */

ATerm SDF_makeTermFromAliasList(SDF_AliasList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Symbols SDF_makeSymbolsFromTerm(ATerm t) */

SDF_Symbols SDF_makeSymbolsFromTerm(ATerm t)
{
  return (SDF_Symbols)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromSymbols(SDF_Symbols arg) */

ATerm SDF_makeTermFromSymbols(SDF_Symbols arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_SymbolList SDF_makeSymbolListFromTerm(ATerm t) */

SDF_SymbolList SDF_makeSymbolListFromTerm(ATerm t)
{
  return (SDF_SymbolList)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromSymbolList(SDF_SymbolList arg) */

ATerm SDF_makeTermFromSymbolList(SDF_SymbolList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Renamings SDF_makeRenamingsFromTerm(ATerm t) */

SDF_Renamings SDF_makeRenamingsFromTerm(ATerm t)
{
  return (SDF_Renamings)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromRenamings(SDF_Renamings arg) */

ATerm SDF_makeTermFromRenamings(SDF_Renamings arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_RenamingList SDF_makeRenamingListFromTerm(ATerm t) */

SDF_RenamingList SDF_makeRenamingListFromTerm(ATerm t)
{
  return (SDF_RenamingList)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromRenamingList(SDF_RenamingList arg) */

ATerm SDF_makeTermFromRenamingList(SDF_RenamingList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Renaming SDF_makeRenamingFromTerm(ATerm t) */

SDF_Renaming SDF_makeRenamingFromTerm(ATerm t)
{
  return (SDF_Renaming)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromRenaming(SDF_Renaming arg) */

ATerm SDF_makeTermFromRenaming(SDF_Renaming arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_NatCon SDF_makeNatConFromTerm(ATerm t) */

SDF_NatCon SDF_makeNatConFromTerm(ATerm t)
{
  return (SDF_NatCon)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromNatCon(SDF_NatCon arg) */

ATerm SDF_makeTermFromNatCon(SDF_NatCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_IntCon SDF_makeIntConFromTerm(ATerm t) */

SDF_IntCon SDF_makeIntConFromTerm(ATerm t)
{
  return (SDF_IntCon)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromIntCon(SDF_IntCon arg) */

ATerm SDF_makeTermFromIntCon(SDF_IntCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_CharRange SDF_makeCharRangeFromTerm(ATerm t) */

SDF_CharRange SDF_makeCharRangeFromTerm(ATerm t)
{
  return (SDF_CharRange)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromCharRange(SDF_CharRange arg) */

ATerm SDF_makeTermFromCharRange(SDF_CharRange arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_makeCharRangesFromTerm(ATerm t) */

SDF_CharRanges SDF_makeCharRangesFromTerm(ATerm t)
{
  return (SDF_CharRanges)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromCharRanges(SDF_CharRanges arg) */

ATerm SDF_makeTermFromCharRanges(SDF_CharRanges arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_OptCharRanges SDF_makeOptCharRangesFromTerm(ATerm t) */

SDF_OptCharRanges SDF_makeOptCharRangesFromTerm(ATerm t)
{
  return (SDF_OptCharRanges)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromOptCharRanges(SDF_OptCharRanges arg) */

ATerm SDF_makeTermFromOptCharRanges(SDF_OptCharRanges arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_makeCharClassFromTerm(ATerm t) */

SDF_CharClass SDF_makeCharClassFromTerm(ATerm t)
{
  return (SDF_CharClass)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromCharClass(SDF_CharClass arg) */

ATerm SDF_makeTermFromCharClass(SDF_CharClass arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_AlphaNumericalEscChar SDF_makeAlphaNumericalEscCharFromTerm(ATerm t) */

SDF_AlphaNumericalEscChar SDF_makeAlphaNumericalEscCharFromTerm(ATerm t)
{
  return (SDF_AlphaNumericalEscChar)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromAlphaNumericalEscChar(SDF_AlphaNumericalEscChar arg) */

ATerm SDF_makeTermFromAlphaNumericalEscChar(SDF_AlphaNumericalEscChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_DecimalEscChar SDF_makeDecimalEscCharFromTerm(ATerm t) */

SDF_DecimalEscChar SDF_makeDecimalEscCharFromTerm(ATerm t)
{
  return (SDF_DecimalEscChar)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromDecimalEscChar(SDF_DecimalEscChar arg) */

ATerm SDF_makeTermFromDecimalEscChar(SDF_DecimalEscChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_EscChar SDF_makeEscCharFromTerm(ATerm t) */

SDF_EscChar SDF_makeEscCharFromTerm(ATerm t)
{
  return (SDF_EscChar)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromEscChar(SDF_EscChar arg) */

ATerm SDF_makeTermFromEscChar(SDF_EscChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_LChar SDF_makeLCharFromTerm(ATerm t) */

SDF_LChar SDF_makeLCharFromTerm(ATerm t)
{
  return (SDF_LChar)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromLChar(SDF_LChar arg) */

ATerm SDF_makeTermFromLChar(SDF_LChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ATerms SDF_makeATermsFromTerm(ATerm t) */

SDF_ATerms SDF_makeATermsFromTerm(ATerm t)
{
  return (SDF_ATerms)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromATerms(SDF_ATerms arg) */

ATerm SDF_makeTermFromATerms(SDF_ATerms arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ATermList SDF_makeATermListFromTerm(ATerm t) */

SDF_ATermList SDF_makeATermListFromTerm(ATerm t)
{
  return (SDF_ATermList)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromATermList(SDF_ATermList arg) */

ATerm SDF_makeTermFromATermList(SDF_ATermList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ACon SDF_makeAConFromTerm(ATerm t) */

SDF_ACon SDF_makeAConFromTerm(ATerm t)
{
  return (SDF_ACon)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromACon(SDF_ACon arg) */

ATerm SDF_makeTermFromACon(SDF_ACon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_AFun SDF_makeAFunFromTerm(ATerm t) */

SDF_AFun SDF_makeAFunFromTerm(ATerm t)
{
  return (SDF_AFun)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromAFun(SDF_AFun arg) */

ATerm SDF_makeTermFromAFun(SDF_AFun arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_makeATermFromTerm(ATerm t) */

SDF_ATerm SDF_makeATermFromTerm(ATerm t)
{
  return (SDF_ATerm)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromATerm(SDF_ATerm arg) */

ATerm SDF_makeTermFromATerm(SDF_ATerm arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Ann SDF_makeAnnFromTerm(ATerm t) */

SDF_Ann SDF_makeAnnFromTerm(ATerm t)
{
  return (SDF_Ann)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromAnn(SDF_Ann arg) */

ATerm SDF_makeTermFromAnn(SDF_Ann arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_TagId SDF_makeTagIdFromTerm(ATerm t) */

SDF_TagId SDF_makeTagIdFromTerm(ATerm t)
{
  return (SDF_TagId)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromTagId(SDF_TagId arg) */

ATerm SDF_makeTermFromTagId(SDF_TagId arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_NumChar SDF_makeNumCharFromTerm(ATerm t) */

SDF_NumChar SDF_makeNumCharFromTerm(ATerm t)
{
  return (SDF_NumChar)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromNumChar(SDF_NumChar arg) */

ATerm SDF_makeTermFromNumChar(SDF_NumChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ShortChar SDF_makeShortCharFromTerm(ATerm t) */

SDF_ShortChar SDF_makeShortCharFromTerm(ATerm t)
{
  return (SDF_ShortChar)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromShortChar(SDF_ShortChar arg) */

ATerm SDF_makeTermFromShortChar(SDF_ShortChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Character SDF_makeCharacterFromTerm(ATerm t) */

SDF_Character SDF_makeCharacterFromTerm(ATerm t)
{
  return (SDF_Character)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromCharacter(SDF_Character arg) */

ATerm SDF_makeTermFromCharacter(SDF_Character arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_OptExp SDF_makeOptExpFromTerm(ATerm t) */

SDF_OptExp SDF_makeOptExpFromTerm(ATerm t)
{
  return (SDF_OptExp)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromOptExp(SDF_OptExp arg) */

ATerm SDF_makeTermFromOptExp(SDF_OptExp arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_RealCon SDF_makeRealConFromTerm(ATerm t) */

SDF_RealCon SDF_makeRealConFromTerm(ATerm t)
{
  return (SDF_RealCon)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromRealCon(SDF_RealCon arg) */

ATerm SDF_makeTermFromRealCon(SDF_RealCon arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  constructors */

/*{{{  SDF_Symbol SDF_makeSymbolStart() */

SDF_Symbol SDF_makeSymbolStart()
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolStart);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolFileStart() */

SDF_Symbol SDF_makeSymbolFileStart()
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolFileStart);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolCf(char * wsAfterLessThan, SDF_Symbol Symbol, char * wsAfterSymbol, char * wsAfterCF) */

SDF_Symbol SDF_makeSymbolCf(char * wsAfterLessThan, SDF_Symbol Symbol, char * wsAfterSymbol, char * wsAfterCF)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolCf, wsAfterLessThan, Symbol, wsAfterSymbol, wsAfterCF);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolLex(char * wsAfterLessThan, SDF_Symbol Symbol, char * wsAfterSymbol, char * wsAfterLEX) */

SDF_Symbol SDF_makeSymbolLex(char * wsAfterLessThan, SDF_Symbol Symbol, char * wsAfterSymbol, char * wsAfterLEX)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolLex, wsAfterLessThan, Symbol, wsAfterSymbol, wsAfterLEX);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolVarsym(char * wsAfterLessThan, SDF_Symbol Symbol, char * wsAfterSymbol, char * wsAfterVAR) */

SDF_Symbol SDF_makeSymbolVarsym(char * wsAfterLessThan, SDF_Symbol Symbol, char * wsAfterSymbol, char * wsAfterVAR)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolVarsym, wsAfterLessThan, Symbol, wsAfterSymbol, wsAfterVAR);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolLayout() */

SDF_Symbol SDF_makeSymbolLayout()
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolLayout);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolEmpty(char * wsAfterParenOpen) */

SDF_Symbol SDF_makeSymbolEmpty(char * wsAfterParenOpen)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolEmpty, wsAfterParenOpen);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolSeq(char * wsAfterParenOpen, SDF_Symbol head, char * wsAfterHead, SDF_SymbolTail tail, char * wsAfterTail) */

SDF_Symbol SDF_makeSymbolSeq(char * wsAfterParenOpen, SDF_Symbol head, char * wsAfterHead, SDF_SymbolTail tail, char * wsAfterTail)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolSeq, wsAfterParenOpen, head, wsAfterHead, tail, wsAfterTail);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolOpt(SDF_Symbol Symbol, char * wsAfterSymbol) */

SDF_Symbol SDF_makeSymbolOpt(SDF_Symbol Symbol, char * wsAfterSymbol)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolOpt, Symbol, wsAfterSymbol);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolIter(SDF_Symbol Symbol, char * wsAfterSymbol) */

SDF_Symbol SDF_makeSymbolIter(SDF_Symbol Symbol, char * wsAfterSymbol)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolIter, Symbol, wsAfterSymbol);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolIterStar(SDF_Symbol Symbol, char * wsAfterSymbol) */

SDF_Symbol SDF_makeSymbolIterStar(SDF_Symbol Symbol, char * wsAfterSymbol)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolIterStar, Symbol, wsAfterSymbol);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolIterSep(char * wsAfterBraceOpen, SDF_Symbol Symbol, char * wsAfterSymbol, SDF_Symbol sep, char * wsAfterSep, char * wsAfterBraceClose) */

SDF_Symbol SDF_makeSymbolIterSep(char * wsAfterBraceOpen, SDF_Symbol Symbol, char * wsAfterSymbol, SDF_Symbol sep, char * wsAfterSep, char * wsAfterBraceClose)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolIterSep, wsAfterBraceOpen, Symbol, wsAfterSymbol, sep, wsAfterSep, wsAfterBraceClose);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolIterStarSep(char * wsAfterBraceOpen, SDF_Symbol Symbol, char * wsAfterSymbol, SDF_Symbol sep, char * wsAfterSep, char * wsAfterBraceClose) */

SDF_Symbol SDF_makeSymbolIterStarSep(char * wsAfterBraceOpen, SDF_Symbol Symbol, char * wsAfterSymbol, SDF_Symbol sep, char * wsAfterSep, char * wsAfterBraceClose)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolIterStarSep, wsAfterBraceOpen, Symbol, wsAfterSymbol, sep, wsAfterSep, wsAfterBraceClose);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolIterN(SDF_Symbol Symbol, char * wsAfterSymbol, SDF_NatCon n, char * wsAfterN) */

SDF_Symbol SDF_makeSymbolIterN(SDF_Symbol Symbol, char * wsAfterSymbol, SDF_NatCon n, char * wsAfterN)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolIterN, Symbol, wsAfterSymbol, n, wsAfterN);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolIterSepN(char * wsAfterBraceOpen, SDF_Symbol Symbol, char * wsAfterSymbol, SDF_Symbol sep, char * wsAfterSep, char * wsAfterBraceClose, SDF_NatCon n, char * wsAfterN) */

SDF_Symbol SDF_makeSymbolIterSepN(char * wsAfterBraceOpen, SDF_Symbol Symbol, char * wsAfterSymbol, SDF_Symbol sep, char * wsAfterSep, char * wsAfterBraceClose, SDF_NatCon n, char * wsAfterN)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolIterSepN, wsAfterBraceOpen, Symbol, wsAfterSymbol, sep, wsAfterSep, wsAfterBraceClose, n, wsAfterN);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolSet(char * wsAfterSet, char * wsAfterBracketOpen, SDF_Symbol Symbol, char * wsAfterSymbol) */

SDF_Symbol SDF_makeSymbolSet(char * wsAfterSet, char * wsAfterBracketOpen, SDF_Symbol Symbol, char * wsAfterSymbol)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolSet, wsAfterSet, wsAfterBracketOpen, Symbol, wsAfterSymbol);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolPair(SDF_Symbol left, char * wsAfterLeft, char * wsAfterHash, SDF_Symbol right) */

SDF_Symbol SDF_makeSymbolPair(SDF_Symbol left, char * wsAfterLeft, char * wsAfterHash, SDF_Symbol right)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolPair, left, wsAfterLeft, wsAfterHash, right);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolFunc(char * wsAfterParenOpen, SDF_Symbols arguments, char * wsAfterArguments, char * wsAfterEqualsGreaterThan, SDF_Symbol results, char * wsAfterResults) */

SDF_Symbol SDF_makeSymbolFunc(char * wsAfterParenOpen, SDF_Symbols arguments, char * wsAfterArguments, char * wsAfterEqualsGreaterThan, SDF_Symbol results, char * wsAfterResults)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolFunc, wsAfterParenOpen, arguments, wsAfterArguments, wsAfterEqualsGreaterThan, results, wsAfterResults);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolAlt(SDF_Symbol left, char * wsAfterLeft, char * wsAfterBar, SDF_Symbol right) */

SDF_Symbol SDF_makeSymbolAlt(SDF_Symbol left, char * wsAfterLeft, char * wsAfterBar, SDF_Symbol right)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolAlt, left, wsAfterLeft, wsAfterBar, right);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolPerm(char * wsAfterLessThanLessThan, SDF_Symbols Symbols, char * wsAfterSymbols) */

SDF_Symbol SDF_makeSymbolPerm(char * wsAfterLessThanLessThan, SDF_Symbols Symbols, char * wsAfterSymbols)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolPerm, wsAfterLessThanLessThan, Symbols, wsAfterSymbols);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolCharClass(SDF_CharClass CharClass) */

SDF_Symbol SDF_makeSymbolCharClass(SDF_CharClass CharClass)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolCharClass, CharClass);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolSort(SDF_Sort Sort) */

SDF_Symbol SDF_makeSymbolSort(SDF_Sort Sort)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolSort, Sort);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolLit(SDF_Literal Literal) */

SDF_Symbol SDF_makeSymbolLit(SDF_Literal Literal)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolLit, Literal);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolLabel(SDF_Literal label, char * wsAfterLabel, char * wsAfterColon, SDF_Symbol Symbol) */

SDF_Symbol SDF_makeSymbolLabel(SDF_Literal label, char * wsAfterLabel, char * wsAfterColon, SDF_Symbol Symbol)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolLabel, label, wsAfterLabel, wsAfterColon, Symbol);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolBracket(char * wsAfterParenOpen, SDF_Symbol Symbol, char * wsAfterSymbol) */

SDF_Symbol SDF_makeSymbolBracket(char * wsAfterParenOpen, SDF_Symbol Symbol, char * wsAfterSymbol)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolBracket, wsAfterParenOpen, Symbol, wsAfterSymbol);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarLexicalPriorities(char * wsAfterLexical, char * wsAfterPriorities, SDF_Priorities Priorities) */

SDF_Grammar SDF_makeGrammarLexicalPriorities(char * wsAfterLexical, char * wsAfterPriorities, SDF_Priorities Priorities)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarLexicalPriorities, wsAfterLexical, wsAfterPriorities, Priorities);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarContextFreePriorities(char * wsAfterContextFree, char * wsAfterPriorities, SDF_Priorities Priorities) */

SDF_Grammar SDF_makeGrammarContextFreePriorities(char * wsAfterContextFree, char * wsAfterPriorities, SDF_Priorities Priorities)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarContextFreePriorities, wsAfterContextFree, wsAfterPriorities, Priorities);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarLexicalRestrictions(char * wsAfterLexical, char * wsAfterRestrictions, SDF_Restrictions Restrictions) */

SDF_Grammar SDF_makeGrammarLexicalRestrictions(char * wsAfterLexical, char * wsAfterRestrictions, SDF_Restrictions Restrictions)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarLexicalRestrictions, wsAfterLexical, wsAfterRestrictions, Restrictions);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarContextFreeRestrictions(char * wsAfterContextFree, char * wsAfterRestrictions, SDF_Restrictions Restrictions) */

SDF_Grammar SDF_makeGrammarContextFreeRestrictions(char * wsAfterContextFree, char * wsAfterRestrictions, SDF_Restrictions Restrictions)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarContextFreeRestrictions, wsAfterContextFree, wsAfterRestrictions, Restrictions);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarSyntax(char * wsAfterSyntax, SDF_Productions Productions) */

SDF_Grammar SDF_makeGrammarSyntax(char * wsAfterSyntax, SDF_Productions Productions)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarSyntax, wsAfterSyntax, Productions);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarLexicalSyntax(char * wsAfterLexical, char * wsAfterSyntax, SDF_Productions Productions) */

SDF_Grammar SDF_makeGrammarLexicalSyntax(char * wsAfterLexical, char * wsAfterSyntax, SDF_Productions Productions)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarLexicalSyntax, wsAfterLexical, wsAfterSyntax, Productions);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarContextFreeSyntax(char * wsAfterContextFree, char * wsAfterSyntax, SDF_Productions Productions) */

SDF_Grammar SDF_makeGrammarContextFreeSyntax(char * wsAfterContextFree, char * wsAfterSyntax, SDF_Productions Productions)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarContextFreeSyntax, wsAfterContextFree, wsAfterSyntax, Productions);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarVariables(char * wsAfterVariables, SDF_Productions Productions) */

SDF_Grammar SDF_makeGrammarVariables(char * wsAfterVariables, SDF_Productions Productions)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarVariables, wsAfterVariables, Productions);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarLexicalVariables(char * wsAfterLexical, char * wsAfterVariables, SDF_Productions Productions) */

SDF_Grammar SDF_makeGrammarLexicalVariables(char * wsAfterLexical, char * wsAfterVariables, SDF_Productions Productions)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarLexicalVariables, wsAfterLexical, wsAfterVariables, Productions);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarImpSection(SDF_ImpSection ImpSection) */

SDF_Grammar SDF_makeGrammarImpSection(SDF_ImpSection ImpSection)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarImpSection, ImpSection);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarPriorities(char * wsAfterPriorities, SDF_Priorities Priorities) */

SDF_Grammar SDF_makeGrammarPriorities(char * wsAfterPriorities, SDF_Priorities Priorities)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarPriorities, wsAfterPriorities, Priorities);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarSorts(char * wsAfterSorts, SDF_Symbols Symbols) */

SDF_Grammar SDF_makeGrammarSorts(char * wsAfterSorts, SDF_Symbols Symbols)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarSorts, wsAfterSorts, Symbols);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarRestrictions(char * wsAfterRestrictions, SDF_Restrictions Restrictions) */

SDF_Grammar SDF_makeGrammarRestrictions(char * wsAfterRestrictions, SDF_Restrictions Restrictions)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarRestrictions, wsAfterRestrictions, Restrictions);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarAliases(char * wsAfterAliases, SDF_Aliases Aliases) */

SDF_Grammar SDF_makeGrammarAliases(char * wsAfterAliases, SDF_Aliases Aliases)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarAliases, wsAfterAliases, Aliases);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarEmptyGrammar() */

SDF_Grammar SDF_makeGrammarEmptyGrammar()
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarEmptyGrammar);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarConcGrammars(SDF_Grammar left, char * wsAfterLeft, SDF_Grammar right) */

SDF_Grammar SDF_makeGrammarConcGrammars(SDF_Grammar left, char * wsAfterLeft, SDF_Grammar right)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarConcGrammars, left, wsAfterLeft, right);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarBracket(char * wsAfterParenOpen, SDF_Grammar Grammar, char * wsAfterGrammar) */

SDF_Grammar SDF_makeGrammarBracket(char * wsAfterParenOpen, SDF_Grammar Grammar, char * wsAfterGrammar)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarBracket, wsAfterParenOpen, Grammar, wsAfterGrammar);
}

/*}}}  */
/*{{{  SDF_SDF SDF_makeSDFDefinition(char * wsAfterDefinition, SDF_Definition Definition) */

SDF_SDF SDF_makeSDFDefinition(char * wsAfterDefinition, SDF_Definition Definition)
{
  return (SDF_SDF)ATmakeTerm(SDF_patternSDFDefinition, wsAfterDefinition, Definition);
}

/*}}}  */
/*{{{  SDF_Attributes SDF_makeAttributesAttrs(char * wsAfterBraceOpen, SDF_AttributeList list, char * wsAfterList) */

SDF_Attributes SDF_makeAttributesAttrs(char * wsAfterBraceOpen, SDF_AttributeList list, char * wsAfterList)
{
  return (SDF_Attributes)ATmakeTerm(SDF_patternAttributesAttrs, wsAfterBraceOpen, list, wsAfterList);
}

/*}}}  */
/*{{{  SDF_Attributes SDF_makeAttributesNoAttrs() */

SDF_Attributes SDF_makeAttributesNoAttrs()
{
  return (SDF_Attributes)ATmakeTerm(SDF_patternAttributesNoAttrs);
}

/*}}}  */
/*{{{  SDF_AttributeList SDF_makeAttributeListEmpty() */

SDF_AttributeList SDF_makeAttributeListEmpty()
{
  return (SDF_AttributeList)ATmakeTerm(SDF_patternAttributeListEmpty);
}

/*}}}  */
/*{{{  SDF_AttributeList SDF_makeAttributeListSingle(SDF_Attribute head) */

SDF_AttributeList SDF_makeAttributeListSingle(SDF_Attribute head)
{
  return (SDF_AttributeList)ATmakeTerm(SDF_patternAttributeListSingle, head);
}

/*}}}  */
/*{{{  SDF_AttributeList SDF_makeAttributeListMany(SDF_Attribute head, char * wsAfterFirst, char * sep, char * wsAfterSep, SDF_AttributeList tail) */

SDF_AttributeList SDF_makeAttributeListMany(SDF_Attribute head, char * wsAfterFirst, char * sep, char * wsAfterSep, SDF_AttributeList tail)
{
  return (SDF_AttributeList)ATmakeTerm(SDF_patternAttributeListMany, head, wsAfterFirst, sep, wsAfterSep, tail);
}

/*}}}  */
/*{{{  SDF_Production SDF_makeProductionProd(SDF_Symbols Symbols, char * wsAfterSymbols, char * wsAfterGreaterThan, SDF_Symbol result, char * wsAfterResult, SDF_Attributes Attributes) */

SDF_Production SDF_makeProductionProd(SDF_Symbols Symbols, char * wsAfterSymbols, char * wsAfterGreaterThan, SDF_Symbol result, char * wsAfterResult, SDF_Attributes Attributes)
{
  return (SDF_Production)ATmakeTerm(SDF_patternProductionProd, Symbols, wsAfterSymbols, wsAfterGreaterThan, result, wsAfterResult, Attributes);
}

/*}}}  */
/*{{{  SDF_Production SDF_makeProductionProdFun(SDF_Literal functionSymbol, char * wsAfterFunctionSymbol, char * wsAfterParenOpen, SDF_SymbolArguments arguments, char * wsAfterArguments, char * wsAfterParenClose, char * wsAfterGreaterThan, SDF_Symbol result, char * wsAfterResult, SDF_Attributes Attributes) */

SDF_Production SDF_makeProductionProdFun(SDF_Literal functionSymbol, char * wsAfterFunctionSymbol, char * wsAfterParenOpen, SDF_SymbolArguments arguments, char * wsAfterArguments, char * wsAfterParenClose, char * wsAfterGreaterThan, SDF_Symbol result, char * wsAfterResult, SDF_Attributes Attributes)
{
  return (SDF_Production)ATmakeTerm(SDF_patternProductionProdFun, functionSymbol, wsAfterFunctionSymbol, wsAfterParenOpen, arguments, wsAfterArguments, wsAfterParenClose, wsAfterGreaterThan, result, wsAfterResult, Attributes);
}

/*}}}  */
/*{{{  SDF_Productions SDF_makeProductionsDefault(SDF_ProductionList list) */

SDF_Productions SDF_makeProductionsDefault(SDF_ProductionList list)
{
  return (SDF_Productions)ATmakeTerm(SDF_patternProductionsDefault, list);
}

/*}}}  */
/*{{{  SDF_ProductionList SDF_makeProductionListEmpty() */

SDF_ProductionList SDF_makeProductionListEmpty()
{
  return (SDF_ProductionList)ATmakeTerm(SDF_patternProductionListEmpty);
}

/*}}}  */
/*{{{  SDF_ProductionList SDF_makeProductionListSingle(SDF_Production head) */

SDF_ProductionList SDF_makeProductionListSingle(SDF_Production head)
{
  return (SDF_ProductionList)ATmakeTerm(SDF_patternProductionListSingle, head);
}

/*}}}  */
/*{{{  SDF_ProductionList SDF_makeProductionListMany(SDF_Production head, char * wsAfterFirst, SDF_ProductionList tail) */

SDF_ProductionList SDF_makeProductionListMany(SDF_Production head, char * wsAfterFirst, SDF_ProductionList tail)
{
  return (SDF_ProductionList)ATmakeTerm(SDF_patternProductionListMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDF_ModuleWord SDF_makeModuleWordWord(char * lex) */

SDF_ModuleWord SDF_makeModuleWordWord(char * lex)
{
  return (SDF_ModuleWord)ATmakeTerm(SDF_patternModuleWordWord, lex);
}

/*}}}  */
/*{{{  SDF_ModuleId SDF_makeModuleIdWord(char * lex) */

SDF_ModuleId SDF_makeModuleIdWord(char * lex)
{
  return (SDF_ModuleId)ATmakeTerm(SDF_patternModuleIdWord, lex);
}

/*}}}  */
/*{{{  SDF_ModuleId SDF_makeModuleIdSlashWord(char * lex) */

SDF_ModuleId SDF_makeModuleIdSlashWord(char * lex)
{
  return (SDF_ModuleId)ATmakeTerm(SDF_patternModuleIdSlashWord, lex);
}

/*}}}  */
/*{{{  SDF_ModuleId SDF_makeModuleIdWordSlashWord(char * lex) */

SDF_ModuleId SDF_makeModuleIdWordSlashWord(char * lex)
{
  return (SDF_ModuleId)ATmakeTerm(SDF_patternModuleIdWordSlashWord, lex);
}

/*}}}  */
/*{{{  SDF_Definition SDF_makeDefinitionDefault(SDF_ModuleList list) */

SDF_Definition SDF_makeDefinitionDefault(SDF_ModuleList list)
{
  return (SDF_Definition)ATmakeTerm(SDF_patternDefinitionDefault, list);
}

/*}}}  */
/*{{{  SDF_ModuleList SDF_makeModuleListEmpty() */

SDF_ModuleList SDF_makeModuleListEmpty()
{
  return (SDF_ModuleList)ATmakeTerm(SDF_patternModuleListEmpty);
}

/*}}}  */
/*{{{  SDF_ModuleList SDF_makeModuleListSingle(SDF_Module head) */

SDF_ModuleList SDF_makeModuleListSingle(SDF_Module head)
{
  return (SDF_ModuleList)ATmakeTerm(SDF_patternModuleListSingle, head);
}

/*}}}  */
/*{{{  SDF_ModuleList SDF_makeModuleListMany(SDF_Module head, char * wsAfterFirst, SDF_ModuleList tail) */

SDF_ModuleList SDF_makeModuleListMany(SDF_Module head, char * wsAfterFirst, SDF_ModuleList tail)
{
  return (SDF_ModuleList)ATmakeTerm(SDF_patternModuleListMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDF_Module SDF_makeModuleModule(char * wsAfterModule, SDF_ModuleName ModuleName, char * wsAfterModuleName, SDF_ImpSectionList list, char * wsAfterList, SDF_Sections Sections) */

SDF_Module SDF_makeModuleModule(char * wsAfterModule, SDF_ModuleName ModuleName, char * wsAfterModuleName, SDF_ImpSectionList list, char * wsAfterList, SDF_Sections Sections)
{
  return (SDF_Module)ATmakeTerm(SDF_patternModuleModule, wsAfterModule, ModuleName, wsAfterModuleName, list, wsAfterList, Sections);
}

/*}}}  */
/*{{{  SDF_ImpSectionList SDF_makeImpSectionListEmpty() */

SDF_ImpSectionList SDF_makeImpSectionListEmpty()
{
  return (SDF_ImpSectionList)ATmakeTerm(SDF_patternImpSectionListEmpty);
}

/*}}}  */
/*{{{  SDF_ImpSectionList SDF_makeImpSectionListSingle(SDF_ImpSection head) */

SDF_ImpSectionList SDF_makeImpSectionListSingle(SDF_ImpSection head)
{
  return (SDF_ImpSectionList)ATmakeTerm(SDF_patternImpSectionListSingle, head);
}

/*}}}  */
/*{{{  SDF_ImpSectionList SDF_makeImpSectionListMany(SDF_ImpSection head, char * wsAfterFirst, SDF_ImpSectionList tail) */

SDF_ImpSectionList SDF_makeImpSectionListMany(SDF_ImpSection head, char * wsAfterFirst, SDF_ImpSectionList tail)
{
  return (SDF_ImpSectionList)ATmakeTerm(SDF_patternImpSectionListMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDF_Section SDF_makeSectionExports(char * wsAfterExports, SDF_Grammar Grammar) */

SDF_Section SDF_makeSectionExports(char * wsAfterExports, SDF_Grammar Grammar)
{
  return (SDF_Section)ATmakeTerm(SDF_patternSectionExports, wsAfterExports, Grammar);
}

/*}}}  */
/*{{{  SDF_Section SDF_makeSectionHiddens(char * wsAfterHiddens, SDF_Grammar Grammar) */

SDF_Section SDF_makeSectionHiddens(char * wsAfterHiddens, SDF_Grammar Grammar)
{
  return (SDF_Section)ATmakeTerm(SDF_patternSectionHiddens, wsAfterHiddens, Grammar);
}

/*}}}  */
/*{{{  SDF_Sections SDF_makeSectionsDefault(SDF_SectionList list) */

SDF_Sections SDF_makeSectionsDefault(SDF_SectionList list)
{
  return (SDF_Sections)ATmakeTerm(SDF_patternSectionsDefault, list);
}

/*}}}  */
/*{{{  SDF_SectionList SDF_makeSectionListEmpty() */

SDF_SectionList SDF_makeSectionListEmpty()
{
  return (SDF_SectionList)ATmakeTerm(SDF_patternSectionListEmpty);
}

/*}}}  */
/*{{{  SDF_SectionList SDF_makeSectionListSingle(SDF_Section head) */

SDF_SectionList SDF_makeSectionListSingle(SDF_Section head)
{
  return (SDF_SectionList)ATmakeTerm(SDF_patternSectionListSingle, head);
}

/*}}}  */
/*{{{  SDF_SectionList SDF_makeSectionListMany(SDF_Section head, char * wsAfterFirst, SDF_SectionList tail) */

SDF_SectionList SDF_makeSectionListMany(SDF_Section head, char * wsAfterFirst, SDF_SectionList tail)
{
  return (SDF_SectionList)ATmakeTerm(SDF_patternSectionListMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_makeModuleNameUnparameterized(SDF_ModuleId ModuleId) */

SDF_ModuleName SDF_makeModuleNameUnparameterized(SDF_ModuleId ModuleId)
{
  return (SDF_ModuleName)ATmakeTerm(SDF_patternModuleNameUnparameterized, ModuleId);
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_makeModuleNameParameterized(SDF_ModuleId ModuleId, char * wsAfterModuleId, char * wsAfterBracketOpen, SDF_Symbols params, char * wsAfterParams) */

SDF_ModuleName SDF_makeModuleNameParameterized(SDF_ModuleId ModuleId, char * wsAfterModuleId, char * wsAfterBracketOpen, SDF_Symbols params, char * wsAfterParams)
{
  return (SDF_ModuleName)ATmakeTerm(SDF_patternModuleNameParameterized, ModuleId, wsAfterModuleId, wsAfterBracketOpen, params, wsAfterParams);
}

/*}}}  */
/*{{{  SDF_Attribute SDF_makeAttributeId(char * wsAfterId, char * wsAfterParenOpen, SDF_ModuleName ModuleName, char * wsAfterModuleName) */

SDF_Attribute SDF_makeAttributeId(char * wsAfterId, char * wsAfterParenOpen, SDF_ModuleName ModuleName, char * wsAfterModuleName)
{
  return (SDF_Attribute)ATmakeTerm(SDF_patternAttributeId, wsAfterId, wsAfterParenOpen, ModuleName, wsAfterModuleName);
}

/*}}}  */
/*{{{  SDF_Attribute SDF_makeAttributeBracket() */

SDF_Attribute SDF_makeAttributeBracket()
{
  return (SDF_Attribute)ATmakeTerm(SDF_patternAttributeBracket);
}

/*}}}  */
/*{{{  SDF_Attribute SDF_makeAttributeAtr(SDF_Associativity Associativity) */

SDF_Attribute SDF_makeAttributeAtr(SDF_Associativity Associativity)
{
  return (SDF_Attribute)ATmakeTerm(SDF_patternAttributeAtr, Associativity);
}

/*}}}  */
/*{{{  SDF_Attribute SDF_makeAttributeCons(char * wsAfterCons, char * wsAfterParenOpen, SDF_ATerm term, char * wsAfterTerm) */

SDF_Attribute SDF_makeAttributeCons(char * wsAfterCons, char * wsAfterParenOpen, SDF_ATerm term, char * wsAfterTerm)
{
  return (SDF_Attribute)ATmakeTerm(SDF_patternAttributeCons, wsAfterCons, wsAfterParenOpen, term, wsAfterTerm);
}

/*}}}  */
/*{{{  SDF_Attribute SDF_makeAttributeConstructor() */

SDF_Attribute SDF_makeAttributeConstructor()
{
  return (SDF_Attribute)ATmakeTerm(SDF_patternAttributeConstructor);
}

/*}}}  */
/*{{{  SDF_Attribute SDF_makeAttributeMemo() */

SDF_Attribute SDF_makeAttributeMemo()
{
  return (SDF_Attribute)ATmakeTerm(SDF_patternAttributeMemo);
}

/*}}}  */
/*{{{  SDF_Attribute SDF_makeAttributeTraverse() */

SDF_Attribute SDF_makeAttributeTraverse()
{
  return (SDF_Attribute)ATmakeTerm(SDF_patternAttributeTraverse);
}

/*}}}  */
/*{{{  SDF_Attribute SDF_makeAttributeReject() */

SDF_Attribute SDF_makeAttributeReject()
{
  return (SDF_Attribute)ATmakeTerm(SDF_patternAttributeReject);
}

/*}}}  */
/*{{{  SDF_Attribute SDF_makeAttributePrefer() */

SDF_Attribute SDF_makeAttributePrefer()
{
  return (SDF_Attribute)ATmakeTerm(SDF_patternAttributePrefer);
}

/*}}}  */
/*{{{  SDF_Attribute SDF_makeAttributeAvoid() */

SDF_Attribute SDF_makeAttributeAvoid()
{
  return (SDF_Attribute)ATmakeTerm(SDF_patternAttributeAvoid);
}

/*}}}  */
/*{{{  SDF_ImpSection SDF_makeImpSectionImports(char * wsAfterImports, SDF_Imports list) */

SDF_ImpSection SDF_makeImpSectionImports(char * wsAfterImports, SDF_Imports list)
{
  return (SDF_ImpSection)ATmakeTerm(SDF_patternImpSectionImports, wsAfterImports, list);
}

/*}}}  */
/*{{{  SDF_Imports SDF_makeImportsDefault(SDF_ImportList list) */

SDF_Imports SDF_makeImportsDefault(SDF_ImportList list)
{
  return (SDF_Imports)ATmakeTerm(SDF_patternImportsDefault, list);
}

/*}}}  */
/*{{{  SDF_ImportList SDF_makeImportListEmpty() */

SDF_ImportList SDF_makeImportListEmpty()
{
  return (SDF_ImportList)ATmakeTerm(SDF_patternImportListEmpty);
}

/*}}}  */
/*{{{  SDF_ImportList SDF_makeImportListSingle(SDF_Import head) */

SDF_ImportList SDF_makeImportListSingle(SDF_Import head)
{
  return (SDF_ImportList)ATmakeTerm(SDF_patternImportListSingle, head);
}

/*}}}  */
/*{{{  SDF_ImportList SDF_makeImportListMany(SDF_Import head, char * wsAfterFirst, SDF_ImportList tail) */

SDF_ImportList SDF_makeImportListMany(SDF_Import head, char * wsAfterFirst, SDF_ImportList tail)
{
  return (SDF_ImportList)ATmakeTerm(SDF_patternImportListMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDF_Import SDF_makeImportModule(SDF_ModuleName ModuleName) */

SDF_Import SDF_makeImportModule(SDF_ModuleName ModuleName)
{
  return (SDF_Import)ATmakeTerm(SDF_patternImportModule, ModuleName);
}

/*}}}  */
/*{{{  SDF_Import SDF_makeImportRenamedModule(SDF_ModuleName ModuleName, char * wsAfterModuleName, SDF_Renamings Renamings) */

SDF_Import SDF_makeImportRenamedModule(SDF_ModuleName ModuleName, char * wsAfterModuleName, SDF_Renamings Renamings)
{
  return (SDF_Import)ATmakeTerm(SDF_patternImportRenamedModule, ModuleName, wsAfterModuleName, Renamings);
}

/*}}}  */
/*{{{  SDF_Import SDF_makeImportBracket(char * wsAfterParenOpen, SDF_Import Import, char * wsAfterImport) */

SDF_Import SDF_makeImportBracket(char * wsAfterParenOpen, SDF_Import Import, char * wsAfterImport)
{
  return (SDF_Import)ATmakeTerm(SDF_patternImportBracket, wsAfterParenOpen, Import, wsAfterImport);
}

/*}}}  */
/*{{{  SDF_SymbolTail SDF_makeSymbolTailSingle(SDF_Symbol head) */

SDF_SymbolTail SDF_makeSymbolTailSingle(SDF_Symbol head)
{
  return (SDF_SymbolTail)ATmakeTerm(SDF_patternSymbolTailSingle, head);
}

/*}}}  */
/*{{{  SDF_SymbolTail SDF_makeSymbolTailMany(SDF_Symbol head, char * wsAfterFirst, SDF_SymbolTail tail) */

SDF_SymbolTail SDF_makeSymbolTailMany(SDF_Symbol head, char * wsAfterFirst, SDF_SymbolTail tail)
{
  return (SDF_SymbolTail)ATmakeTerm(SDF_patternSymbolTailMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDF_Associativity SDF_makeAssociativityLeft() */

SDF_Associativity SDF_makeAssociativityLeft()
{
  return (SDF_Associativity)ATmakeTerm(SDF_patternAssociativityLeft);
}

/*}}}  */
/*{{{  SDF_Associativity SDF_makeAssociativityRight() */

SDF_Associativity SDF_makeAssociativityRight()
{
  return (SDF_Associativity)ATmakeTerm(SDF_patternAssociativityRight);
}

/*}}}  */
/*{{{  SDF_Associativity SDF_makeAssociativityNonAssoc() */

SDF_Associativity SDF_makeAssociativityNonAssoc()
{
  return (SDF_Associativity)ATmakeTerm(SDF_patternAssociativityNonAssoc);
}

/*}}}  */
/*{{{  SDF_Associativity SDF_makeAssociativityAssoc() */

SDF_Associativity SDF_makeAssociativityAssoc()
{
  return (SDF_Associativity)ATmakeTerm(SDF_patternAssociativityAssoc);
}

/*}}}  */
/*{{{  SDF_Group SDF_makeGroupSimpleGroup(SDF_Production Production) */

SDF_Group SDF_makeGroupSimpleGroup(SDF_Production Production)
{
  return (SDF_Group)ATmakeTerm(SDF_patternGroupSimpleGroup, Production);
}

/*}}}  */
/*{{{  SDF_Group SDF_makeGroupProdsGroup(char * wsAfterBraceOpen, SDF_Productions Productions, char * wsAfterProductions) */

SDF_Group SDF_makeGroupProdsGroup(char * wsAfterBraceOpen, SDF_Productions Productions, char * wsAfterProductions)
{
  return (SDF_Group)ATmakeTerm(SDF_patternGroupProdsGroup, wsAfterBraceOpen, Productions, wsAfterProductions);
}

/*}}}  */
/*{{{  SDF_Group SDF_makeGroupAssocGroup(char * wsAfterBraceOpen, SDF_Associativity Associativity, char * wsAfterAssociativity, char * wsAfterColon, SDF_Productions Productions, char * wsAfterProductions) */

SDF_Group SDF_makeGroupAssocGroup(char * wsAfterBraceOpen, SDF_Associativity Associativity, char * wsAfterAssociativity, char * wsAfterColon, SDF_Productions Productions, char * wsAfterProductions)
{
  return (SDF_Group)ATmakeTerm(SDF_patternGroupAssocGroup, wsAfterBraceOpen, Associativity, wsAfterAssociativity, wsAfterColon, Productions, wsAfterProductions);
}

/*}}}  */
/*{{{  SDF_Priority SDF_makePriorityChain(SDF_GroupList list) */

SDF_Priority SDF_makePriorityChain(SDF_GroupList list)
{
  return (SDF_Priority)ATmakeTerm(SDF_patternPriorityChain, list);
}

/*}}}  */
/*{{{  SDF_Priority SDF_makePriorityAssoc(SDF_Group left, char * wsAfterLeft, SDF_Associativity Associativity, char * wsAfterAssociativity, SDF_Group right) */

SDF_Priority SDF_makePriorityAssoc(SDF_Group left, char * wsAfterLeft, SDF_Associativity Associativity, char * wsAfterAssociativity, SDF_Group right)
{
  return (SDF_Priority)ATmakeTerm(SDF_patternPriorityAssoc, left, wsAfterLeft, Associativity, wsAfterAssociativity, right);
}

/*}}}  */
/*{{{  SDF_GroupList SDF_makeGroupListSingle(SDF_Group head) */

SDF_GroupList SDF_makeGroupListSingle(SDF_Group head)
{
  return (SDF_GroupList)ATmakeTerm(SDF_patternGroupListSingle, head);
}

/*}}}  */
/*{{{  SDF_GroupList SDF_makeGroupListMany(SDF_Group head, char * wsAfterFirst, char * sep, char * wsAfterSep, SDF_GroupList tail) */

SDF_GroupList SDF_makeGroupListMany(SDF_Group head, char * wsAfterFirst, char * sep, char * wsAfterSep, SDF_GroupList tail)
{
  return (SDF_GroupList)ATmakeTerm(SDF_patternGroupListMany, head, wsAfterFirst, sep, wsAfterSep, tail);
}

/*}}}  */
/*{{{  SDF_Priorities SDF_makePrioritiesDefault(SDF_PriorityList list) */

SDF_Priorities SDF_makePrioritiesDefault(SDF_PriorityList list)
{
  return (SDF_Priorities)ATmakeTerm(SDF_patternPrioritiesDefault, list);
}

/*}}}  */
/*{{{  SDF_PriorityList SDF_makePriorityListEmpty() */

SDF_PriorityList SDF_makePriorityListEmpty()
{
  return (SDF_PriorityList)ATmakeTerm(SDF_patternPriorityListEmpty);
}

/*}}}  */
/*{{{  SDF_PriorityList SDF_makePriorityListSingle(SDF_Priority head) */

SDF_PriorityList SDF_makePriorityListSingle(SDF_Priority head)
{
  return (SDF_PriorityList)ATmakeTerm(SDF_patternPriorityListSingle, head);
}

/*}}}  */
/*{{{  SDF_PriorityList SDF_makePriorityListMany(SDF_Priority head, char * wsAfterFirst, char * sep, char * wsAfterSep, SDF_PriorityList tail) */

SDF_PriorityList SDF_makePriorityListMany(SDF_Priority head, char * wsAfterFirst, char * sep, char * wsAfterSep, SDF_PriorityList tail)
{
  return (SDF_PriorityList)ATmakeTerm(SDF_patternPriorityListMany, head, wsAfterFirst, sep, wsAfterSep, tail);
}

/*}}}  */
/*{{{  SDF_Sort SDF_makeSortOneChar(char * lex) */

SDF_Sort SDF_makeSortOneChar(char * lex)
{
  return (SDF_Sort)ATmakeTerm(SDF_patternSortOneChar, lex);
}

/*}}}  */
/*{{{  SDF_Sort SDF_makeSortMoreChars(char * lex) */

SDF_Sort SDF_makeSortMoreChars(char * lex)
{
  return (SDF_Sort)ATmakeTerm(SDF_patternSortMoreChars, lex);
}

/*}}}  */
/*{{{  SDF_UQLiteral SDF_makeUQLiteralOneChar(char * lex) */

SDF_UQLiteral SDF_makeUQLiteralOneChar(char * lex)
{
  return (SDF_UQLiteral)ATmakeTerm(SDF_patternUQLiteralOneChar, lex);
}

/*}}}  */
/*{{{  SDF_UQLiteral SDF_makeUQLiteralMoreChars(char * lex) */

SDF_UQLiteral SDF_makeUQLiteralMoreChars(char * lex)
{
  return (SDF_UQLiteral)ATmakeTerm(SDF_patternUQLiteralMoreChars, lex);
}

/*}}}  */
/*{{{  SDF_Literal SDF_makeLiteralUqlit(SDF_UQLiteral UQLiteral) */

SDF_Literal SDF_makeLiteralUqlit(SDF_UQLiteral UQLiteral)
{
  return (SDF_Literal)ATmakeTerm(SDF_patternLiteralUqlit, UQLiteral);
}

/*}}}  */
/*{{{  SDF_Literal SDF_makeLiteralQuoted(char * lex) */

SDF_Literal SDF_makeLiteralQuoted(char * lex)
{
  return (SDF_Literal)ATmakeTerm(SDF_patternLiteralQuoted, lex);
}

/*}}}  */
/*{{{  SDF_SymbolArguments SDF_makeSymbolArgumentsEmpty() */

SDF_SymbolArguments SDF_makeSymbolArgumentsEmpty()
{
  return (SDF_SymbolArguments)ATmakeTerm(SDF_patternSymbolArgumentsEmpty);
}

/*}}}  */
/*{{{  SDF_SymbolArguments SDF_makeSymbolArgumentsSingle(SDF_Symbol head) */

SDF_SymbolArguments SDF_makeSymbolArgumentsSingle(SDF_Symbol head)
{
  return (SDF_SymbolArguments)ATmakeTerm(SDF_patternSymbolArgumentsSingle, head);
}

/*}}}  */
/*{{{  SDF_SymbolArguments SDF_makeSymbolArgumentsMany(SDF_Symbol head, char * wsAfterFirst, char * sep, char * wsAfterSep, SDF_SymbolArguments tail) */

SDF_SymbolArguments SDF_makeSymbolArgumentsMany(SDF_Symbol head, char * wsAfterFirst, char * sep, char * wsAfterSep, SDF_SymbolArguments tail)
{
  return (SDF_SymbolArguments)ATmakeTerm(SDF_patternSymbolArgumentsMany, head, wsAfterFirst, sep, wsAfterSep, tail);
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_makeLookaheadCharClass(SDF_CharClass CharClass) */

SDF_Lookahead SDF_makeLookaheadCharClass(SDF_CharClass CharClass)
{
  return (SDF_Lookahead)ATmakeTerm(SDF_patternLookaheadCharClass, CharClass);
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_makeLookaheadSeq(SDF_CharClass head, char * wsAfterHead, char * wsAfterPeriod, SDF_Lookaheads tail) */

SDF_Lookahead SDF_makeLookaheadSeq(SDF_CharClass head, char * wsAfterHead, char * wsAfterPeriod, SDF_Lookaheads tail)
{
  return (SDF_Lookahead)ATmakeTerm(SDF_patternLookaheadSeq, head, wsAfterHead, wsAfterPeriod, tail);
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_makeLookaheadsSingle(SDF_Lookahead Lookahead) */

SDF_Lookaheads SDF_makeLookaheadsSingle(SDF_Lookahead Lookahead)
{
  return (SDF_Lookaheads)ATmakeTerm(SDF_patternLookaheadsSingle, Lookahead);
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_makeLookaheadsAlt(SDF_Lookaheads left, char * wsAfterLeft, char * wsAfterBar, SDF_Lookaheads right) */

SDF_Lookaheads SDF_makeLookaheadsAlt(SDF_Lookaheads left, char * wsAfterLeft, char * wsAfterBar, SDF_Lookaheads right)
{
  return (SDF_Lookaheads)ATmakeTerm(SDF_patternLookaheadsAlt, left, wsAfterLeft, wsAfterBar, right);
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_makeLookaheadsBracket(char * wsAfterParenOpen, SDF_Lookaheads Lookaheads, char * wsAfterLookaheads) */

SDF_Lookaheads SDF_makeLookaheadsBracket(char * wsAfterParenOpen, SDF_Lookaheads Lookaheads, char * wsAfterLookaheads)
{
  return (SDF_Lookaheads)ATmakeTerm(SDF_patternLookaheadsBracket, wsAfterParenOpen, Lookaheads, wsAfterLookaheads);
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_makeLookaheadsList(char * wsAfterBracketOpenBracketOpen, SDF_LookaheadList list, char * wsAfterList) */

SDF_Lookaheads SDF_makeLookaheadsList(char * wsAfterBracketOpenBracketOpen, SDF_LookaheadList list, char * wsAfterList)
{
  return (SDF_Lookaheads)ATmakeTerm(SDF_patternLookaheadsList, wsAfterBracketOpenBracketOpen, list, wsAfterList);
}

/*}}}  */
/*{{{  SDF_LookaheadList SDF_makeLookaheadListEmpty() */

SDF_LookaheadList SDF_makeLookaheadListEmpty()
{
  return (SDF_LookaheadList)ATmakeTerm(SDF_patternLookaheadListEmpty);
}

/*}}}  */
/*{{{  SDF_LookaheadList SDF_makeLookaheadListSingle(SDF_Lookahead head) */

SDF_LookaheadList SDF_makeLookaheadListSingle(SDF_Lookahead head)
{
  return (SDF_LookaheadList)ATmakeTerm(SDF_patternLookaheadListSingle, head);
}

/*}}}  */
/*{{{  SDF_LookaheadList SDF_makeLookaheadListMany(SDF_Lookahead head, char * wsAfterFirst, char * sep, char * wsAfterSep, SDF_LookaheadList tail) */

SDF_LookaheadList SDF_makeLookaheadListMany(SDF_Lookahead head, char * wsAfterFirst, char * sep, char * wsAfterSep, SDF_LookaheadList tail)
{
  return (SDF_LookaheadList)ATmakeTerm(SDF_patternLookaheadListMany, head, wsAfterFirst, sep, wsAfterSep, tail);
}

/*}}}  */
/*{{{  SDF_Restriction SDF_makeRestrictionFollow(SDF_Symbols Symbols, char * wsAfterSymbols, char * wsAfterSlash, SDF_Lookaheads Lookaheads) */

SDF_Restriction SDF_makeRestrictionFollow(SDF_Symbols Symbols, char * wsAfterSymbols, char * wsAfterSlash, SDF_Lookaheads Lookaheads)
{
  return (SDF_Restriction)ATmakeTerm(SDF_patternRestrictionFollow, Symbols, wsAfterSymbols, wsAfterSlash, Lookaheads);
}

/*}}}  */
/*{{{  SDF_Restrictions SDF_makeRestrictionsDefault(SDF_RestrictionList list) */

SDF_Restrictions SDF_makeRestrictionsDefault(SDF_RestrictionList list)
{
  return (SDF_Restrictions)ATmakeTerm(SDF_patternRestrictionsDefault, list);
}

/*}}}  */
/*{{{  SDF_RestrictionList SDF_makeRestrictionListEmpty() */

SDF_RestrictionList SDF_makeRestrictionListEmpty()
{
  return (SDF_RestrictionList)ATmakeTerm(SDF_patternRestrictionListEmpty);
}

/*}}}  */
/*{{{  SDF_RestrictionList SDF_makeRestrictionListSingle(SDF_Restriction head) */

SDF_RestrictionList SDF_makeRestrictionListSingle(SDF_Restriction head)
{
  return (SDF_RestrictionList)ATmakeTerm(SDF_patternRestrictionListSingle, head);
}

/*}}}  */
/*{{{  SDF_RestrictionList SDF_makeRestrictionListMany(SDF_Restriction head, char * wsAfterFirst, SDF_RestrictionList tail) */

SDF_RestrictionList SDF_makeRestrictionListMany(SDF_Restriction head, char * wsAfterFirst, SDF_RestrictionList tail)
{
  return (SDF_RestrictionList)ATmakeTerm(SDF_patternRestrictionListMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDF_Alias SDF_makeAliasAlias(SDF_Symbol Symbol, char * wsAfterSymbol, char * wsAfterArrow, SDF_Symbol alias) */

SDF_Alias SDF_makeAliasAlias(SDF_Symbol Symbol, char * wsAfterSymbol, char * wsAfterArrow, SDF_Symbol alias)
{
  return (SDF_Alias)ATmakeTerm(SDF_patternAliasAlias, Symbol, wsAfterSymbol, wsAfterArrow, alias);
}

/*}}}  */
/*{{{  SDF_Aliases SDF_makeAliasesDefault(SDF_AliasList list) */

SDF_Aliases SDF_makeAliasesDefault(SDF_AliasList list)
{
  return (SDF_Aliases)ATmakeTerm(SDF_patternAliasesDefault, list);
}

/*}}}  */
/*{{{  SDF_AliasList SDF_makeAliasListEmpty() */

SDF_AliasList SDF_makeAliasListEmpty()
{
  return (SDF_AliasList)ATmakeTerm(SDF_patternAliasListEmpty);
}

/*}}}  */
/*{{{  SDF_AliasList SDF_makeAliasListSingle(SDF_Alias head) */

SDF_AliasList SDF_makeAliasListSingle(SDF_Alias head)
{
  return (SDF_AliasList)ATmakeTerm(SDF_patternAliasListSingle, head);
}

/*}}}  */
/*{{{  SDF_AliasList SDF_makeAliasListMany(SDF_Alias head, char * wsAfterFirst, SDF_AliasList tail) */

SDF_AliasList SDF_makeAliasListMany(SDF_Alias head, char * wsAfterFirst, SDF_AliasList tail)
{
  return (SDF_AliasList)ATmakeTerm(SDF_patternAliasListMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDF_Symbols SDF_makeSymbolsDefault(SDF_SymbolList list) */

SDF_Symbols SDF_makeSymbolsDefault(SDF_SymbolList list)
{
  return (SDF_Symbols)ATmakeTerm(SDF_patternSymbolsDefault, list);
}

/*}}}  */
/*{{{  SDF_SymbolList SDF_makeSymbolListEmpty() */

SDF_SymbolList SDF_makeSymbolListEmpty()
{
  return (SDF_SymbolList)ATmakeTerm(SDF_patternSymbolListEmpty);
}

/*}}}  */
/*{{{  SDF_SymbolList SDF_makeSymbolListSingle(SDF_Symbol head) */

SDF_SymbolList SDF_makeSymbolListSingle(SDF_Symbol head)
{
  return (SDF_SymbolList)ATmakeTerm(SDF_patternSymbolListSingle, head);
}

/*}}}  */
/*{{{  SDF_SymbolList SDF_makeSymbolListMany(SDF_Symbol head, char * wsAfterFirst, SDF_SymbolList tail) */

SDF_SymbolList SDF_makeSymbolListMany(SDF_Symbol head, char * wsAfterFirst, SDF_SymbolList tail)
{
  return (SDF_SymbolList)ATmakeTerm(SDF_patternSymbolListMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDF_Renamings SDF_makeRenamingsRenamings(char * wsAfterBracketOpen, SDF_RenamingList list, char * wsAfterList) */

SDF_Renamings SDF_makeRenamingsRenamings(char * wsAfterBracketOpen, SDF_RenamingList list, char * wsAfterList)
{
  return (SDF_Renamings)ATmakeTerm(SDF_patternRenamingsRenamings, wsAfterBracketOpen, list, wsAfterList);
}

/*}}}  */
/*{{{  SDF_RenamingList SDF_makeRenamingListEmpty() */

SDF_RenamingList SDF_makeRenamingListEmpty()
{
  return (SDF_RenamingList)ATmakeTerm(SDF_patternRenamingListEmpty);
}

/*}}}  */
/*{{{  SDF_RenamingList SDF_makeRenamingListSingle(SDF_Renaming head) */

SDF_RenamingList SDF_makeRenamingListSingle(SDF_Renaming head)
{
  return (SDF_RenamingList)ATmakeTerm(SDF_patternRenamingListSingle, head);
}

/*}}}  */
/*{{{  SDF_RenamingList SDF_makeRenamingListMany(SDF_Renaming head, char * wsAfterFirst, SDF_RenamingList tail) */

SDF_RenamingList SDF_makeRenamingListMany(SDF_Renaming head, char * wsAfterFirst, SDF_RenamingList tail)
{
  return (SDF_RenamingList)ATmakeTerm(SDF_patternRenamingListMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDF_Renaming SDF_makeRenamingSymbol(SDF_Symbol from, char * wsAfterFrom, char * wsAfterEqualsGreaterThan, SDF_Symbol to) */

SDF_Renaming SDF_makeRenamingSymbol(SDF_Symbol from, char * wsAfterFrom, char * wsAfterEqualsGreaterThan, SDF_Symbol to)
{
  return (SDF_Renaming)ATmakeTerm(SDF_patternRenamingSymbol, from, wsAfterFrom, wsAfterEqualsGreaterThan, to);
}

/*}}}  */
/*{{{  SDF_Renaming SDF_makeRenamingProduction(SDF_Symbol from, char * wsAfterFrom, char * wsAfterEqualsGreaterThan, SDF_Symbol to) */

SDF_Renaming SDF_makeRenamingProduction(SDF_Symbol from, char * wsAfterFrom, char * wsAfterEqualsGreaterThan, SDF_Symbol to)
{
  return (SDF_Renaming)ATmakeTerm(SDF_patternRenamingProduction, from, wsAfterFrom, wsAfterEqualsGreaterThan, to);
}

/*}}}  */
/*{{{  SDF_NatCon SDF_makeNatConDigits(char * lex) */

SDF_NatCon SDF_makeNatConDigits(char * lex)
{
  return (SDF_NatCon)ATmakeTerm(SDF_patternNatConDigits, lex);
}

/*}}}  */
/*{{{  SDF_IntCon SDF_makeIntConNatural(SDF_NatCon NatCon) */

SDF_IntCon SDF_makeIntConNatural(SDF_NatCon NatCon)
{
  return (SDF_IntCon)ATmakeTerm(SDF_patternIntConNatural, NatCon);
}

/*}}}  */
/*{{{  SDF_IntCon SDF_makeIntConPositive(char * wsAfterPos, SDF_NatCon NatCon) */

SDF_IntCon SDF_makeIntConPositive(char * wsAfterPos, SDF_NatCon NatCon)
{
  return (SDF_IntCon)ATmakeTerm(SDF_patternIntConPositive, wsAfterPos, NatCon);
}

/*}}}  */
/*{{{  SDF_IntCon SDF_makeIntConNegative(char * wsAfterNeg, SDF_NatCon NatCon) */

SDF_IntCon SDF_makeIntConNegative(char * wsAfterNeg, SDF_NatCon NatCon)
{
  return (SDF_IntCon)ATmakeTerm(SDF_patternIntConNegative, wsAfterNeg, NatCon);
}

/*}}}  */
/*{{{  SDF_CharRange SDF_makeCharRangeDefault(SDF_Character Character) */

SDF_CharRange SDF_makeCharRangeDefault(SDF_Character Character)
{
  return (SDF_CharRange)ATmakeTerm(SDF_patternCharRangeDefault, Character);
}

/*}}}  */
/*{{{  SDF_CharRange SDF_makeCharRangeRange(SDF_Character start, char * wsAfterStart, char * wsAfter, SDF_Character end) */

SDF_CharRange SDF_makeCharRangeRange(SDF_Character start, char * wsAfterStart, char * wsAfter, SDF_Character end)
{
  return (SDF_CharRange)ATmakeTerm(SDF_patternCharRangeRange, start, wsAfterStart, wsAfter, end);
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_makeCharRangesDefault(SDF_CharRange CharRange) */

SDF_CharRanges SDF_makeCharRangesDefault(SDF_CharRange CharRange)
{
  return (SDF_CharRanges)ATmakeTerm(SDF_patternCharRangesDefault, CharRange);
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_makeCharRangesConc(SDF_CharRanges left, char * wsAfterLeft, SDF_CharRanges right) */

SDF_CharRanges SDF_makeCharRangesConc(SDF_CharRanges left, char * wsAfterLeft, SDF_CharRanges right)
{
  return (SDF_CharRanges)ATmakeTerm(SDF_patternCharRangesConc, left, wsAfterLeft, right);
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_makeCharRangesBracket(char * wsAfterParenOpen, SDF_CharRanges CharRanges, char * wsAfterCharRanges) */

SDF_CharRanges SDF_makeCharRangesBracket(char * wsAfterParenOpen, SDF_CharRanges CharRanges, char * wsAfterCharRanges)
{
  return (SDF_CharRanges)ATmakeTerm(SDF_patternCharRangesBracket, wsAfterParenOpen, CharRanges, wsAfterCharRanges);
}

/*}}}  */
/*{{{  SDF_OptCharRanges SDF_makeOptCharRangesAbsent() */

SDF_OptCharRanges SDF_makeOptCharRangesAbsent()
{
  return (SDF_OptCharRanges)ATmakeTerm(SDF_patternOptCharRangesAbsent);
}

/*}}}  */
/*{{{  SDF_OptCharRanges SDF_makeOptCharRangesPresent(SDF_CharRanges CharRanges) */

SDF_OptCharRanges SDF_makeOptCharRangesPresent(SDF_CharRanges CharRanges)
{
  return (SDF_OptCharRanges)ATmakeTerm(SDF_patternOptCharRangesPresent, CharRanges);
}

/*}}}  */
/*{{{  SDF_CharClass SDF_makeCharClassSimpleCharclass(char * wsAfterBracketOpen, SDF_OptCharRanges OptCharRanges, char * wsAfterOptCharRanges) */

SDF_CharClass SDF_makeCharClassSimpleCharclass(char * wsAfterBracketOpen, SDF_OptCharRanges OptCharRanges, char * wsAfterOptCharRanges)
{
  return (SDF_CharClass)ATmakeTerm(SDF_patternCharClassSimpleCharclass, wsAfterBracketOpen, OptCharRanges, wsAfterOptCharRanges);
}

/*}}}  */
/*{{{  SDF_CharClass SDF_makeCharClassComp(char * wsAfterTilde, SDF_CharClass CharClass) */

SDF_CharClass SDF_makeCharClassComp(char * wsAfterTilde, SDF_CharClass CharClass)
{
  return (SDF_CharClass)ATmakeTerm(SDF_patternCharClassComp, wsAfterTilde, CharClass);
}

/*}}}  */
/*{{{  SDF_CharClass SDF_makeCharClassDiff(SDF_CharClass left, char * wsAfterLeft, char * wsAfterSlash, SDF_CharClass right) */

SDF_CharClass SDF_makeCharClassDiff(SDF_CharClass left, char * wsAfterLeft, char * wsAfterSlash, SDF_CharClass right)
{
  return (SDF_CharClass)ATmakeTerm(SDF_patternCharClassDiff, left, wsAfterLeft, wsAfterSlash, right);
}

/*}}}  */
/*{{{  SDF_CharClass SDF_makeCharClassIsect(SDF_CharClass left, char * wsAfterLeft, char * wsAfterSlashBackslash, SDF_CharClass right) */

SDF_CharClass SDF_makeCharClassIsect(SDF_CharClass left, char * wsAfterLeft, char * wsAfterSlashBackslash, SDF_CharClass right)
{
  return (SDF_CharClass)ATmakeTerm(SDF_patternCharClassIsect, left, wsAfterLeft, wsAfterSlashBackslash, right);
}

/*}}}  */
/*{{{  SDF_CharClass SDF_makeCharClassUnion(SDF_CharClass left, char * wsAfterLeft, char * wsAfterBackslashSlash, SDF_CharClass right) */

SDF_CharClass SDF_makeCharClassUnion(SDF_CharClass left, char * wsAfterLeft, char * wsAfterBackslashSlash, SDF_CharClass right)
{
  return (SDF_CharClass)ATmakeTerm(SDF_patternCharClassUnion, left, wsAfterLeft, wsAfterBackslashSlash, right);
}

/*}}}  */
/*{{{  SDF_CharClass SDF_makeCharClassBracket(char * wsAfterParenOpen, SDF_CharClass CharClass, char * wsAfterCharClass) */

SDF_CharClass SDF_makeCharClassBracket(char * wsAfterParenOpen, SDF_CharClass CharClass, char * wsAfterCharClass)
{
  return (SDF_CharClass)ATmakeTerm(SDF_patternCharClassBracket, wsAfterParenOpen, CharClass, wsAfterCharClass);
}

/*}}}  */
/*{{{  SDF_AlphaNumericalEscChar SDF_makeAlphaNumericalEscCharDefault(char * lex) */

SDF_AlphaNumericalEscChar SDF_makeAlphaNumericalEscCharDefault(char * lex)
{
  return (SDF_AlphaNumericalEscChar)ATmakeTerm(SDF_patternAlphaNumericalEscCharDefault, lex);
}

/*}}}  */
/*{{{  SDF_DecimalEscChar SDF_makeDecimalEscCharDec0_199(char * lex) */

SDF_DecimalEscChar SDF_makeDecimalEscCharDec0_199(char * lex)
{
  return (SDF_DecimalEscChar)ATmakeTerm(SDF_patternDecimalEscCharDec0_199, lex);
}

/*}}}  */
/*{{{  SDF_DecimalEscChar SDF_makeDecimalEscCharDec200_249(char * lex) */

SDF_DecimalEscChar SDF_makeDecimalEscCharDec200_249(char * lex)
{
  return (SDF_DecimalEscChar)ATmakeTerm(SDF_patternDecimalEscCharDec200_249, lex);
}

/*}}}  */
/*{{{  SDF_DecimalEscChar SDF_makeDecimalEscCharDec250_255(char * lex) */

SDF_DecimalEscChar SDF_makeDecimalEscCharDec250_255(char * lex)
{
  return (SDF_DecimalEscChar)ATmakeTerm(SDF_patternDecimalEscCharDec250_255, lex);
}

/*}}}  */
/*{{{  SDF_EscChar SDF_makeEscCharAlphaNumeric(char * lex) */

SDF_EscChar SDF_makeEscCharAlphaNumeric(char * lex)
{
  return (SDF_EscChar)ATmakeTerm(SDF_patternEscCharAlphaNumeric, lex);
}

/*}}}  */
/*{{{  SDF_EscChar SDF_makeEscCharDecimal(char * lex) */

SDF_EscChar SDF_makeEscCharDecimal(char * lex)
{
  return (SDF_EscChar)ATmakeTerm(SDF_patternEscCharDecimal, lex);
}

/*}}}  */
/*{{{  SDF_LChar SDF_makeLCharNormal(char * lex) */

SDF_LChar SDF_makeLCharNormal(char * lex)
{
  return (SDF_LChar)ATmakeTerm(SDF_patternLCharNormal, lex);
}

/*}}}  */
/*{{{  SDF_LChar SDF_makeLCharEscaped(char * lex) */

SDF_LChar SDF_makeLCharEscaped(char * lex)
{
  return (SDF_LChar)ATmakeTerm(SDF_patternLCharEscaped, lex);
}

/*}}}  */
/*{{{  SDF_ATerms SDF_makeATermsAterm(SDF_ATerm term) */

SDF_ATerms SDF_makeATermsAterm(SDF_ATerm term)
{
  return (SDF_ATerms)ATmakeTerm(SDF_patternATermsAterm, term);
}

/*}}}  */
/*{{{  SDF_ATerms SDF_makeATermsCons(SDF_ATerm head, char * wsAfterHead, char * wsAfterComma, SDF_ATerms tail) */

SDF_ATerms SDF_makeATermsCons(SDF_ATerm head, char * wsAfterHead, char * wsAfterComma, SDF_ATerms tail)
{
  return (SDF_ATerms)ATmakeTerm(SDF_patternATermsCons, head, wsAfterHead, wsAfterComma, tail);
}

/*}}}  */
/*{{{  SDF_ATermList SDF_makeATermListEmpty(char * wsAfterBracketOpen) */

SDF_ATermList SDF_makeATermListEmpty(char * wsAfterBracketOpen)
{
  return (SDF_ATermList)ATmakeTerm(SDF_patternATermListEmpty, wsAfterBracketOpen);
}

/*}}}  */
/*{{{  SDF_ATermList SDF_makeATermListNotEmpty(char * wsAfterBracketOpen, SDF_ATerms ATerms, char * wsAfterATerms) */

SDF_ATermList SDF_makeATermListNotEmpty(char * wsAfterBracketOpen, SDF_ATerms ATerms, char * wsAfterATerms)
{
  return (SDF_ATermList)ATmakeTerm(SDF_patternATermListNotEmpty, wsAfterBracketOpen, ATerms, wsAfterATerms);
}

/*}}}  */
/*{{{  SDF_ACon SDF_makeAConInt(SDF_IntCon IntCon) */

SDF_ACon SDF_makeAConInt(SDF_IntCon IntCon)
{
  return (SDF_ACon)ATmakeTerm(SDF_patternAConInt, IntCon);
}

/*}}}  */
/*{{{  SDF_ACon SDF_makeAConReal(SDF_RealCon RealCon) */

SDF_ACon SDF_makeAConReal(SDF_RealCon RealCon)
{
  return (SDF_ACon)ATmakeTerm(SDF_patternAConReal, RealCon);
}

/*}}}  */
/*{{{  SDF_AFun SDF_makeAFunDefault(SDF_Literal Literal) */

SDF_AFun SDF_makeAFunDefault(SDF_Literal Literal)
{
  return (SDF_AFun)ATmakeTerm(SDF_patternAFunDefault, Literal);
}

/*}}}  */
/*{{{  SDF_ATerm SDF_makeATermConstant(SDF_ACon ACon) */

SDF_ATerm SDF_makeATermConstant(SDF_ACon ACon)
{
  return (SDF_ATerm)ATmakeTerm(SDF_patternATermConstant, ACon);
}

/*}}}  */
/*{{{  SDF_ATerm SDF_makeATermList(SDF_ATermList list) */

SDF_ATerm SDF_makeATermList(SDF_ATermList list)
{
  return (SDF_ATerm)ATmakeTerm(SDF_patternATermList, list);
}

/*}}}  */
/*{{{  SDF_ATerm SDF_makeATermFun(SDF_AFun fun) */

SDF_ATerm SDF_makeATermFun(SDF_AFun fun)
{
  return (SDF_ATerm)ATmakeTerm(SDF_patternATermFun, fun);
}

/*}}}  */
/*{{{  SDF_ATerm SDF_makeATermAppl(SDF_AFun fun, char * wsAfterFun, char * wsAfterParenOpen, SDF_ATerms args, char * wsAfterArgs) */

SDF_ATerm SDF_makeATermAppl(SDF_AFun fun, char * wsAfterFun, char * wsAfterParenOpen, SDF_ATerms args, char * wsAfterArgs)
{
  return (SDF_ATerm)ATmakeTerm(SDF_patternATermAppl, fun, wsAfterFun, wsAfterParenOpen, args, wsAfterArgs);
}

/*}}}  */
/*{{{  SDF_ATerm SDF_makeATermAnnotatedConstant(SDF_ACon ACon, char * wsAfterACon, SDF_Ann Ann) */

SDF_ATerm SDF_makeATermAnnotatedConstant(SDF_ACon ACon, char * wsAfterACon, SDF_Ann Ann)
{
  return (SDF_ATerm)ATmakeTerm(SDF_patternATermAnnotatedConstant, ACon, wsAfterACon, Ann);
}

/*}}}  */
/*{{{  SDF_ATerm SDF_makeATermAnnotatedList(SDF_ATermList list, char * wsAfterList, SDF_Ann Ann) */

SDF_ATerm SDF_makeATermAnnotatedList(SDF_ATermList list, char * wsAfterList, SDF_Ann Ann)
{
  return (SDF_ATerm)ATmakeTerm(SDF_patternATermAnnotatedList, list, wsAfterList, Ann);
}

/*}}}  */
/*{{{  SDF_ATerm SDF_makeATermAnnotatedFun(SDF_AFun fun, char * wsAfterFun, SDF_Ann Ann) */

SDF_ATerm SDF_makeATermAnnotatedFun(SDF_AFun fun, char * wsAfterFun, SDF_Ann Ann)
{
  return (SDF_ATerm)ATmakeTerm(SDF_patternATermAnnotatedFun, fun, wsAfterFun, Ann);
}

/*}}}  */
/*{{{  SDF_ATerm SDF_makeATermAnnotatedAppl(SDF_AFun fun, char * wsAfterFun, char * wsAfterParenOpen, SDF_ATerms args, char * wsAfterArgs, char * wsAfterParenClose, SDF_Ann Ann) */

SDF_ATerm SDF_makeATermAnnotatedAppl(SDF_AFun fun, char * wsAfterFun, char * wsAfterParenOpen, SDF_ATerms args, char * wsAfterArgs, char * wsAfterParenClose, SDF_Ann Ann)
{
  return (SDF_ATerm)ATmakeTerm(SDF_patternATermAnnotatedAppl, fun, wsAfterFun, wsAfterParenOpen, args, wsAfterArgs, wsAfterParenClose, Ann);
}

/*}}}  */
/*{{{  SDF_Ann SDF_makeAnnAnnotation(char * wsAfterBraceOpen, SDF_ATerms ATerms, char * wsAfterATerms) */

SDF_Ann SDF_makeAnnAnnotation(char * wsAfterBraceOpen, SDF_ATerms ATerms, char * wsAfterATerms)
{
  return (SDF_Ann)ATmakeTerm(SDF_patternAnnAnnotation, wsAfterBraceOpen, ATerms, wsAfterATerms);
}

/*}}}  */
/*{{{  SDF_TagId SDF_makeTagIdDefault(char * lex) */

SDF_TagId SDF_makeTagIdDefault(char * lex)
{
  return (SDF_TagId)ATmakeTerm(SDF_patternTagIdDefault, lex);
}

/*}}}  */
/*{{{  SDF_TagId SDF_makeTagIdEmpty() */

SDF_TagId SDF_makeTagIdEmpty()
{
  return (SDF_TagId)ATmakeTerm(SDF_patternTagIdEmpty);
}

/*}}}  */
/*{{{  SDF_NumChar SDF_makeNumCharDigits(char * lex) */

SDF_NumChar SDF_makeNumCharDigits(char * lex)
{
  return (SDF_NumChar)ATmakeTerm(SDF_patternNumCharDigits, lex);
}

/*}}}  */
/*{{{  SDF_ShortChar SDF_makeShortCharRegular(char * lex) */

SDF_ShortChar SDF_makeShortCharRegular(char * lex)
{
  return (SDF_ShortChar)ATmakeTerm(SDF_patternShortCharRegular, lex);
}

/*}}}  */
/*{{{  SDF_ShortChar SDF_makeShortCharEscaped(char * lex) */

SDF_ShortChar SDF_makeShortCharEscaped(char * lex)
{
  return (SDF_ShortChar)ATmakeTerm(SDF_patternShortCharEscaped, lex);
}

/*}}}  */
/*{{{  SDF_Character SDF_makeCharacterNumeric(SDF_NumChar NumChar) */

SDF_Character SDF_makeCharacterNumeric(SDF_NumChar NumChar)
{
  return (SDF_Character)ATmakeTerm(SDF_patternCharacterNumeric, NumChar);
}

/*}}}  */
/*{{{  SDF_Character SDF_makeCharacterShort(SDF_ShortChar ShortChar) */

SDF_Character SDF_makeCharacterShort(SDF_ShortChar ShortChar)
{
  return (SDF_Character)ATmakeTerm(SDF_patternCharacterShort, ShortChar);
}

/*}}}  */
/*{{{  SDF_Character SDF_makeCharacterTop() */

SDF_Character SDF_makeCharacterTop()
{
  return (SDF_Character)ATmakeTerm(SDF_patternCharacterTop);
}

/*}}}  */
/*{{{  SDF_Character SDF_makeCharacterEof() */

SDF_Character SDF_makeCharacterEof()
{
  return (SDF_Character)ATmakeTerm(SDF_patternCharacterEof);
}

/*}}}  */
/*{{{  SDF_OptExp SDF_makeOptExpPresent(char * wsAfterE, SDF_IntCon IntCon) */

SDF_OptExp SDF_makeOptExpPresent(char * wsAfterE, SDF_IntCon IntCon)
{
  return (SDF_OptExp)ATmakeTerm(SDF_patternOptExpPresent, wsAfterE, IntCon);
}

/*}}}  */
/*{{{  SDF_OptExp SDF_makeOptExpAbsent() */

SDF_OptExp SDF_makeOptExpAbsent()
{
  return (SDF_OptExp)ATmakeTerm(SDF_patternOptExpAbsent);
}

/*}}}  */
/*{{{  SDF_RealCon SDF_makeRealConRealCon(SDF_IntCon IntCon, char * wsAfterIntCon, char * wsAfterPeriod, SDF_NatCon NatCon, char * wsAfterNatCon, SDF_OptExp OptExp) */

SDF_RealCon SDF_makeRealConRealCon(SDF_IntCon IntCon, char * wsAfterIntCon, char * wsAfterPeriod, SDF_NatCon NatCon, char * wsAfterNatCon, SDF_OptExp OptExp)
{
  return (SDF_RealCon)ATmakeTerm(SDF_patternRealConRealCon, IntCon, wsAfterIntCon, wsAfterPeriod, NatCon, wsAfterNatCon, OptExp);
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool SDF_isEqualSymbol(SDF_Symbol arg0, SDF_Symbol arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualGrammar(SDF_Grammar arg0, SDF_Grammar arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualSDF(SDF_SDF arg0, SDF_SDF arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualAttributes(SDF_Attributes arg0, SDF_Attributes arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualAttributeList(SDF_AttributeList arg0, SDF_AttributeList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualProduction(SDF_Production arg0, SDF_Production arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualProductions(SDF_Productions arg0, SDF_Productions arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualProductionList(SDF_ProductionList arg0, SDF_ProductionList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualModuleWord(SDF_ModuleWord arg0, SDF_ModuleWord arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualModuleId(SDF_ModuleId arg0, SDF_ModuleId arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualDefinition(SDF_Definition arg0, SDF_Definition arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualModuleList(SDF_ModuleList arg0, SDF_ModuleList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualModule(SDF_Module arg0, SDF_Module arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualImpSectionList(SDF_ImpSectionList arg0, SDF_ImpSectionList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualSection(SDF_Section arg0, SDF_Section arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualSections(SDF_Sections arg0, SDF_Sections arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualSectionList(SDF_SectionList arg0, SDF_SectionList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualModuleName(SDF_ModuleName arg0, SDF_ModuleName arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualAttribute(SDF_Attribute arg0, SDF_Attribute arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualImpSection(SDF_ImpSection arg0, SDF_ImpSection arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualImports(SDF_Imports arg0, SDF_Imports arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualImportList(SDF_ImportList arg0, SDF_ImportList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualImport(SDF_Import arg0, SDF_Import arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualSymbolTail(SDF_SymbolTail arg0, SDF_SymbolTail arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualAssociativity(SDF_Associativity arg0, SDF_Associativity arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualGroup(SDF_Group arg0, SDF_Group arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualPriority(SDF_Priority arg0, SDF_Priority arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualGroupList(SDF_GroupList arg0, SDF_GroupList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualPriorities(SDF_Priorities arg0, SDF_Priorities arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualPriorityList(SDF_PriorityList arg0, SDF_PriorityList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualSort(SDF_Sort arg0, SDF_Sort arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualUQLiteral(SDF_UQLiteral arg0, SDF_UQLiteral arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualLiteral(SDF_Literal arg0, SDF_Literal arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualSymbolArguments(SDF_SymbolArguments arg0, SDF_SymbolArguments arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualLookahead(SDF_Lookahead arg0, SDF_Lookahead arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualLookaheads(SDF_Lookaheads arg0, SDF_Lookaheads arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualLookaheadList(SDF_LookaheadList arg0, SDF_LookaheadList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualRestriction(SDF_Restriction arg0, SDF_Restriction arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualRestrictions(SDF_Restrictions arg0, SDF_Restrictions arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualRestrictionList(SDF_RestrictionList arg0, SDF_RestrictionList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualAlias(SDF_Alias arg0, SDF_Alias arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualAliases(SDF_Aliases arg0, SDF_Aliases arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualAliasList(SDF_AliasList arg0, SDF_AliasList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualSymbols(SDF_Symbols arg0, SDF_Symbols arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualSymbolList(SDF_SymbolList arg0, SDF_SymbolList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualRenamings(SDF_Renamings arg0, SDF_Renamings arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualRenamingList(SDF_RenamingList arg0, SDF_RenamingList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualRenaming(SDF_Renaming arg0, SDF_Renaming arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualNatCon(SDF_NatCon arg0, SDF_NatCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualIntCon(SDF_IntCon arg0, SDF_IntCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualCharRange(SDF_CharRange arg0, SDF_CharRange arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualCharRanges(SDF_CharRanges arg0, SDF_CharRanges arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualOptCharRanges(SDF_OptCharRanges arg0, SDF_OptCharRanges arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualCharClass(SDF_CharClass arg0, SDF_CharClass arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualAlphaNumericalEscChar(SDF_AlphaNumericalEscChar arg0, SDF_AlphaNumericalEscChar arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualDecimalEscChar(SDF_DecimalEscChar arg0, SDF_DecimalEscChar arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualEscChar(SDF_EscChar arg0, SDF_EscChar arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualLChar(SDF_LChar arg0, SDF_LChar arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualATerms(SDF_ATerms arg0, SDF_ATerms arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualATermList(SDF_ATermList arg0, SDF_ATermList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualACon(SDF_ACon arg0, SDF_ACon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualAFun(SDF_AFun arg0, SDF_AFun arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualATerm(SDF_ATerm arg0, SDF_ATerm arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualAnn(SDF_Ann arg0, SDF_Ann arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualTagId(SDF_TagId arg0, SDF_TagId arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualNumChar(SDF_NumChar arg0, SDF_NumChar arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualShortChar(SDF_ShortChar arg0, SDF_ShortChar arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualCharacter(SDF_Character arg0, SDF_Character arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualOptExp(SDF_OptExp arg0, SDF_OptExp arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualRealCon(SDF_RealCon arg0, SDF_RealCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  SDF_Symbol accessors */

/*{{{  ATbool SDF_isValidSymbol(SDF_Symbol arg) */

ATbool SDF_isValidSymbol(SDF_Symbol arg)
{
  if (SDF_isSymbolStart(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolFileStart(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolCf(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolLex(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolVarsym(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolLayout(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolSeq(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolOpt(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIter(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIterStar(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIterSep(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIterN(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolSet(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolPair(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolFunc(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolAlt(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolPerm(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolCharClass(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolSort(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolLit(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolLabel(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolStart(SDF_Symbol arg) */

ATbool SDF_isSymbolStart(SDF_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolStart);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolFileStart(SDF_Symbol arg) */

ATbool SDF_isSymbolFileStart(SDF_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolFileStart);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolCf(SDF_Symbol arg) */

ATbool SDF_isSymbolCf(SDF_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolCf, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolLex(SDF_Symbol arg) */

ATbool SDF_isSymbolLex(SDF_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolLex, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolVarsym(SDF_Symbol arg) */

ATbool SDF_isSymbolVarsym(SDF_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolVarsym, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolLayout(SDF_Symbol arg) */

ATbool SDF_isSymbolLayout(SDF_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolLayout);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolEmpty(SDF_Symbol arg) */

ATbool SDF_isSymbolEmpty(SDF_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolEmpty, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolSeq(SDF_Symbol arg) */

ATbool SDF_isSymbolSeq(SDF_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolSeq, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolOpt(SDF_Symbol arg) */

ATbool SDF_isSymbolOpt(SDF_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolOpt, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolIter(SDF_Symbol arg) */

ATbool SDF_isSymbolIter(SDF_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolIter, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolIterStar(SDF_Symbol arg) */

ATbool SDF_isSymbolIterStar(SDF_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolIterStar, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolIterSep(SDF_Symbol arg) */

ATbool SDF_isSymbolIterSep(SDF_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolIterSep, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolIterStarSep(SDF_Symbol arg) */

ATbool SDF_isSymbolIterStarSep(SDF_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolIterStarSep, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolIterN(SDF_Symbol arg) */

ATbool SDF_isSymbolIterN(SDF_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolIterN, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolIterSepN(SDF_Symbol arg) */

ATbool SDF_isSymbolIterSepN(SDF_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolIterSepN, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolSet(SDF_Symbol arg) */

ATbool SDF_isSymbolSet(SDF_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolSet, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolPair(SDF_Symbol arg) */

ATbool SDF_isSymbolPair(SDF_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolPair, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolFunc(SDF_Symbol arg) */

ATbool SDF_isSymbolFunc(SDF_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolFunc, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolAlt(SDF_Symbol arg) */

ATbool SDF_isSymbolAlt(SDF_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolAlt, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolPerm(SDF_Symbol arg) */

ATbool SDF_isSymbolPerm(SDF_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolPerm, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolCharClass(SDF_Symbol arg) */

ATbool SDF_isSymbolCharClass(SDF_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolCharClass, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolSort(SDF_Symbol arg) */

ATbool SDF_isSymbolSort(SDF_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolSort, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolLit(SDF_Symbol arg) */

ATbool SDF_isSymbolLit(SDF_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolLit, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolLabel(SDF_Symbol arg) */

ATbool SDF_isSymbolLabel(SDF_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolLabel, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolBracket(SDF_Symbol arg) */

ATbool SDF_isSymbolBracket(SDF_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolBracket, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterLessThan(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterLessThan(SDF_Symbol arg)
{
  if (SDF_isSymbolCf(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolLex(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolVarsym(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolWsAfterLessThan(SDF_Symbol arg) */

char * SDF_getSymbolWsAfterLessThan(SDF_Symbol arg)
{
  if (SDF_isSymbolCf(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isSymbolLex(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isSymbolVarsym(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Symbol has no WsAfterLessThan: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterLessThan(SDF_Symbol arg, char * wsAfterLessThan) */

SDF_Symbol SDF_setSymbolWsAfterLessThan(SDF_Symbol arg, char * wsAfterLessThan)
{
  if (SDF_isSymbolCf(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterLessThan, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isSymbolLex(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterLessThan, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isSymbolVarsym(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterLessThan, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Symbol has no WsAfterLessThan: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolSymbol(SDF_Symbol arg) */

ATbool SDF_hasSymbolSymbol(SDF_Symbol arg)
{
  if (SDF_isSymbolCf(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolLex(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolVarsym(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolOpt(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIter(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIterStar(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIterSep(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIterN(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolSet(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolLabel(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_getSymbolSymbol(SDF_Symbol arg) */

SDF_Symbol SDF_getSymbolSymbol(SDF_Symbol arg)
{
  if (SDF_isSymbolCf(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDF_isSymbolLex(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDF_isSymbolVarsym(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDF_isSymbolOpt(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDF_isSymbolIter(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDF_isSymbolIterStar(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDF_isSymbolIterSep(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDF_isSymbolIterN(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDF_isSymbolSet(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDF_isSymbolLabel(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDF_isSymbolBracket(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Symbol has no Symbol: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolSymbol(SDF_Symbol arg, SDF_Symbol Symbol) */

SDF_Symbol SDF_setSymbolSymbol(SDF_Symbol arg, SDF_Symbol Symbol)
{
  if (SDF_isSymbolCf(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Symbol, 2), 2);
  }
  else if (SDF_isSymbolLex(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Symbol, 2), 2);
  }
  else if (SDF_isSymbolVarsym(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Symbol, 2), 2);
  }
  else if (SDF_isSymbolOpt(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Symbol, 0), 2);
  }
  else if (SDF_isSymbolIter(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Symbol, 0), 2);
  }
  else if (SDF_isSymbolIterStar(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Symbol, 0), 2);
  }
  else if (SDF_isSymbolIterSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Symbol, 2), 2);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Symbol, 2), 2);
  }
  else if (SDF_isSymbolIterN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Symbol, 0), 2);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Symbol, 2), 2);
  }
  else if (SDF_isSymbolSet(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Symbol, 4), 2);
  }
  else if (SDF_isSymbolLabel(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Symbol, 4), 2);
  }
  else if (SDF_isSymbolBracket(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Symbol, 2), 2);
  }

  ATabort("Symbol has no Symbol: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterSymbol(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterSymbol(SDF_Symbol arg)
{
  if (SDF_isSymbolCf(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolLex(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolVarsym(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolOpt(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIter(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIterStar(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIterSep(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIterN(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolSet(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolWsAfterSymbol(SDF_Symbol arg) */

char * SDF_getSymbolWsAfterSymbol(SDF_Symbol arg)
{
  if (SDF_isSymbolCf(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }
  else if (SDF_isSymbolLex(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }
  else if (SDF_isSymbolVarsym(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }
  else if (SDF_isSymbolOpt(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isSymbolIter(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isSymbolIterStar(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isSymbolIterSep(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }
  else if (SDF_isSymbolIterN(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }
  else if (SDF_isSymbolSet(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0)));
  }
  else if (SDF_isSymbolBracket(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Symbol has no WsAfterSymbol: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterSymbol(SDF_Symbol arg, char * wsAfterSymbol) */

SDF_Symbol SDF_setSymbolWsAfterSymbol(SDF_Symbol arg, char * wsAfterSymbol)
{
  if (SDF_isSymbolCf(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSymbol, 0, ATtrue)), 0), 3), 2);
  }
  else if (SDF_isSymbolLex(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSymbol, 0, ATtrue)), 0), 3), 2);
  }
  else if (SDF_isSymbolVarsym(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSymbol, 0, ATtrue)), 0), 3), 2);
  }
  else if (SDF_isSymbolOpt(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSymbol, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isSymbolIter(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSymbol, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isSymbolIterStar(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSymbol, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isSymbolIterSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSymbol, 0, ATtrue)), 0), 3), 2);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSymbol, 0, ATtrue)), 0), 3), 2);
  }
  else if (SDF_isSymbolIterN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSymbol, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSymbol, 0, ATtrue)), 0), 3), 2);
  }
  else if (SDF_isSymbolSet(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSymbol, 0, ATtrue)), 0), 5), 2);
  }
  else if (SDF_isSymbolBracket(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSymbol, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Symbol has no WsAfterSymbol: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterCF(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterCF(SDF_Symbol arg)
{
  if (SDF_isSymbolCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolWsAfterCF(SDF_Symbol arg) */

char * SDF_getSymbolWsAfterCF(SDF_Symbol arg)
{
  if (SDF_isSymbolCf(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0)));
  }

  ATabort("Symbol has no WsAfterCF: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterCF(SDF_Symbol arg, char * wsAfterCF) */

SDF_Symbol SDF_setSymbolWsAfterCF(SDF_Symbol arg, char * wsAfterCF)
{
  if (SDF_isSymbolCf(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterCF, 0, ATtrue)), 0), 5), 2);
  }

  ATabort("Symbol has no WsAfterCF: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterLEX(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterLEX(SDF_Symbol arg)
{
  if (SDF_isSymbolLex(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolWsAfterLEX(SDF_Symbol arg) */

char * SDF_getSymbolWsAfterLEX(SDF_Symbol arg)
{
  if (SDF_isSymbolLex(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0)));
  }

  ATabort("Symbol has no WsAfterLEX: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterLEX(SDF_Symbol arg, char * wsAfterLEX) */

SDF_Symbol SDF_setSymbolWsAfterLEX(SDF_Symbol arg, char * wsAfterLEX)
{
  if (SDF_isSymbolLex(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterLEX, 0, ATtrue)), 0), 5), 2);
  }

  ATabort("Symbol has no WsAfterLEX: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterVAR(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterVAR(SDF_Symbol arg)
{
  if (SDF_isSymbolVarsym(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolWsAfterVAR(SDF_Symbol arg) */

char * SDF_getSymbolWsAfterVAR(SDF_Symbol arg)
{
  if (SDF_isSymbolVarsym(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0)));
  }

  ATabort("Symbol has no WsAfterVAR: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterVAR(SDF_Symbol arg, char * wsAfterVAR) */

SDF_Symbol SDF_setSymbolWsAfterVAR(SDF_Symbol arg, char * wsAfterVAR)
{
  if (SDF_isSymbolVarsym(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterVAR, 0, ATtrue)), 0), 5), 2);
  }

  ATabort("Symbol has no WsAfterVAR: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterParenOpen(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterParenOpen(SDF_Symbol arg)
{
  if (SDF_isSymbolEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolSeq(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolFunc(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolWsAfterParenOpen(SDF_Symbol arg) */

char * SDF_getSymbolWsAfterParenOpen(SDF_Symbol arg)
{
  if (SDF_isSymbolEmpty(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isSymbolSeq(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isSymbolFunc(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isSymbolBracket(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Symbol has no WsAfterParenOpen: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterParenOpen(SDF_Symbol arg, char * wsAfterParenOpen) */

SDF_Symbol SDF_setSymbolWsAfterParenOpen(SDF_Symbol arg, char * wsAfterParenOpen)
{
  if (SDF_isSymbolEmpty(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterParenOpen, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isSymbolSeq(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterParenOpen, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isSymbolFunc(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterParenOpen, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isSymbolBracket(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterParenOpen, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Symbol has no WsAfterParenOpen: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolHead(SDF_Symbol arg) */

ATbool SDF_hasSymbolHead(SDF_Symbol arg)
{
  if (SDF_isSymbolSeq(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_getSymbolHead(SDF_Symbol arg) */

SDF_Symbol SDF_getSymbolHead(SDF_Symbol arg)
{
  if (SDF_isSymbolSeq(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Symbol has no Head: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolHead(SDF_Symbol arg, SDF_Symbol head) */

SDF_Symbol SDF_setSymbolHead(SDF_Symbol arg, SDF_Symbol head)
{
  if (SDF_isSymbolSeq(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)head, 2), 2);
  }

  ATabort("Symbol has no Head: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterHead(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterHead(SDF_Symbol arg)
{
  if (SDF_isSymbolSeq(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolWsAfterHead(SDF_Symbol arg) */

char * SDF_getSymbolWsAfterHead(SDF_Symbol arg)
{
  if (SDF_isSymbolSeq(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Symbol has no WsAfterHead: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterHead(SDF_Symbol arg, char * wsAfterHead) */

SDF_Symbol SDF_setSymbolWsAfterHead(SDF_Symbol arg, char * wsAfterHead)
{
  if (SDF_isSymbolSeq(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterHead, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Symbol has no WsAfterHead: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolTail(SDF_Symbol arg) */

ATbool SDF_hasSymbolTail(SDF_Symbol arg)
{
  if (SDF_isSymbolSeq(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_SymbolTail SDF_getSymbolTail(SDF_Symbol arg) */

SDF_SymbolTail SDF_getSymbolTail(SDF_Symbol arg)
{
  if (SDF_isSymbolSeq(arg)) {
    return (SDF_SymbolTail)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4), 2);
  }

  ATabort("Symbol has no Tail: %t\n", arg);
  return (SDF_SymbolTail)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolTail(SDF_Symbol arg, SDF_SymbolTail tail) */

SDF_Symbol SDF_setSymbolTail(SDF_Symbol arg, SDF_SymbolTail tail)
{
  if (SDF_isSymbolSeq(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4), (ATerm)tail, 2), 4), 2);
  }

  ATabort("Symbol has no Tail: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterTail(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterTail(SDF_Symbol arg)
{
  if (SDF_isSymbolSeq(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolWsAfterTail(SDF_Symbol arg) */

char * SDF_getSymbolWsAfterTail(SDF_Symbol arg)
{
  if (SDF_isSymbolSeq(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0)));
  }

  ATabort("Symbol has no WsAfterTail: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterTail(SDF_Symbol arg, char * wsAfterTail) */

SDF_Symbol SDF_setSymbolWsAfterTail(SDF_Symbol arg, char * wsAfterTail)
{
  if (SDF_isSymbolSeq(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterTail, 0, ATtrue)), 0), 5), 2);
  }

  ATabort("Symbol has no WsAfterTail: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterBraceOpen(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterBraceOpen(SDF_Symbol arg)
{
  if (SDF_isSymbolIterSep(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolWsAfterBraceOpen(SDF_Symbol arg) */

char * SDF_getSymbolWsAfterBraceOpen(SDF_Symbol arg)
{
  if (SDF_isSymbolIterSep(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Symbol has no WsAfterBraceOpen: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterBraceOpen(SDF_Symbol arg, char * wsAfterBraceOpen) */

SDF_Symbol SDF_setSymbolWsAfterBraceOpen(SDF_Symbol arg, char * wsAfterBraceOpen)
{
  if (SDF_isSymbolIterSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterBraceOpen, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterBraceOpen, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterBraceOpen, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Symbol has no WsAfterBraceOpen: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolSep(SDF_Symbol arg) */

ATbool SDF_hasSymbolSep(SDF_Symbol arg)
{
  if (SDF_isSymbolIterSep(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_getSymbolSep(SDF_Symbol arg) */

SDF_Symbol SDF_getSymbolSep(SDF_Symbol arg)
{
  if (SDF_isSymbolIterSep(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Symbol has no Sep: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolSep(SDF_Symbol arg, SDF_Symbol sep) */

SDF_Symbol SDF_setSymbolSep(SDF_Symbol arg, SDF_Symbol sep)
{
  if (SDF_isSymbolIterSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)sep, 4), 2);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)sep, 4), 2);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)sep, 4), 2);
  }

  ATabort("Symbol has no Sep: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterSep(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterSep(SDF_Symbol arg)
{
  if (SDF_isSymbolIterSep(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolWsAfterSep(SDF_Symbol arg) */

char * SDF_getSymbolWsAfterSep(SDF_Symbol arg)
{
  if (SDF_isSymbolIterSep(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0)));
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0)));
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0)));
  }

  ATabort("Symbol has no WsAfterSep: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterSep(SDF_Symbol arg, char * wsAfterSep) */

SDF_Symbol SDF_setSymbolWsAfterSep(SDF_Symbol arg, char * wsAfterSep)
{
  if (SDF_isSymbolIterSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSep, 0, ATtrue)), 0), 5), 2);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSep, 0, ATtrue)), 0), 5), 2);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSep, 0, ATtrue)), 0), 5), 2);
  }

  ATabort("Symbol has no WsAfterSep: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterBraceClose(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterBraceClose(SDF_Symbol arg)
{
  if (SDF_isSymbolIterSep(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolWsAfterBraceClose(SDF_Symbol arg) */

char * SDF_getSymbolWsAfterBraceClose(SDF_Symbol arg)
{
  if (SDF_isSymbolIterSep(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), 0)));
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), 0)));
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), 0)));
  }

  ATabort("Symbol has no WsAfterBraceClose: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterBraceClose(SDF_Symbol arg, char * wsAfterBraceClose) */

SDF_Symbol SDF_setSymbolWsAfterBraceClose(SDF_Symbol arg, char * wsAfterBraceClose)
{
  if (SDF_isSymbolIterSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterBraceClose, 0, ATtrue)), 0), 7), 2);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterBraceClose, 0, ATtrue)), 0), 7), 2);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterBraceClose, 0, ATtrue)), 0), 7), 2);
  }

  ATabort("Symbol has no WsAfterBraceClose: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolN(SDF_Symbol arg) */

ATbool SDF_hasSymbolN(SDF_Symbol arg)
{
  if (SDF_isSymbolIterN(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_NatCon SDF_getSymbolN(SDF_Symbol arg) */

SDF_NatCon SDF_getSymbolN(SDF_Symbol arg)
{
  if (SDF_isSymbolIterN(arg)) {
    return (SDF_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 8);
  }

  ATabort("Symbol has no N: %t\n", arg);
  return (SDF_NatCon)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolN(SDF_Symbol arg, SDF_NatCon n) */

SDF_Symbol SDF_setSymbolN(SDF_Symbol arg, SDF_NatCon n)
{
  if (SDF_isSymbolIterN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)n, 2), 2);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)n, 8), 2);
  }

  ATabort("Symbol has no N: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterN(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterN(SDF_Symbol arg)
{
  if (SDF_isSymbolIterN(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolWsAfterN(SDF_Symbol arg) */

char * SDF_getSymbolWsAfterN(SDF_Symbol arg)
{
  if (SDF_isSymbolIterN(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 9), 0)));
  }

  ATabort("Symbol has no WsAfterN: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterN(SDF_Symbol arg, char * wsAfterN) */

SDF_Symbol SDF_setSymbolWsAfterN(SDF_Symbol arg, char * wsAfterN)
{
  if (SDF_isSymbolIterN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterN, 0, ATtrue)), 0), 3), 2);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 9), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterN, 0, ATtrue)), 0), 9), 2);
  }

  ATabort("Symbol has no WsAfterN: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterSet(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterSet(SDF_Symbol arg)
{
  if (SDF_isSymbolSet(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolWsAfterSet(SDF_Symbol arg) */

char * SDF_getSymbolWsAfterSet(SDF_Symbol arg)
{
  if (SDF_isSymbolSet(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Symbol has no WsAfterSet: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterSet(SDF_Symbol arg, char * wsAfterSet) */

SDF_Symbol SDF_setSymbolWsAfterSet(SDF_Symbol arg, char * wsAfterSet)
{
  if (SDF_isSymbolSet(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSet, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Symbol has no WsAfterSet: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterBracketOpen(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterBracketOpen(SDF_Symbol arg)
{
  if (SDF_isSymbolSet(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolWsAfterBracketOpen(SDF_Symbol arg) */

char * SDF_getSymbolWsAfterBracketOpen(SDF_Symbol arg)
{
  if (SDF_isSymbolSet(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Symbol has no WsAfterBracketOpen: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterBracketOpen(SDF_Symbol arg, char * wsAfterBracketOpen) */

SDF_Symbol SDF_setSymbolWsAfterBracketOpen(SDF_Symbol arg, char * wsAfterBracketOpen)
{
  if (SDF_isSymbolSet(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterBracketOpen, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Symbol has no WsAfterBracketOpen: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolLeft(SDF_Symbol arg) */

ATbool SDF_hasSymbolLeft(SDF_Symbol arg)
{
  if (SDF_isSymbolPair(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolAlt(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_getSymbolLeft(SDF_Symbol arg) */

SDF_Symbol SDF_getSymbolLeft(SDF_Symbol arg)
{
  if (SDF_isSymbolPair(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDF_isSymbolAlt(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Symbol has no Left: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolLeft(SDF_Symbol arg, SDF_Symbol left) */

SDF_Symbol SDF_setSymbolLeft(SDF_Symbol arg, SDF_Symbol left)
{
  if (SDF_isSymbolPair(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)left, 0), 2);
  }
  else if (SDF_isSymbolAlt(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)left, 0), 2);
  }

  ATabort("Symbol has no Left: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterLeft(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterLeft(SDF_Symbol arg)
{
  if (SDF_isSymbolPair(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolAlt(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolWsAfterLeft(SDF_Symbol arg) */

char * SDF_getSymbolWsAfterLeft(SDF_Symbol arg)
{
  if (SDF_isSymbolPair(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isSymbolAlt(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Symbol has no WsAfterLeft: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterLeft(SDF_Symbol arg, char * wsAfterLeft) */

SDF_Symbol SDF_setSymbolWsAfterLeft(SDF_Symbol arg, char * wsAfterLeft)
{
  if (SDF_isSymbolPair(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterLeft, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isSymbolAlt(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterLeft, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Symbol has no WsAfterLeft: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterHash(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterHash(SDF_Symbol arg)
{
  if (SDF_isSymbolPair(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolWsAfterHash(SDF_Symbol arg) */

char * SDF_getSymbolWsAfterHash(SDF_Symbol arg)
{
  if (SDF_isSymbolPair(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Symbol has no WsAfterHash: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterHash(SDF_Symbol arg, char * wsAfterHash) */

SDF_Symbol SDF_setSymbolWsAfterHash(SDF_Symbol arg, char * wsAfterHash)
{
  if (SDF_isSymbolPair(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterHash, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Symbol has no WsAfterHash: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolRight(SDF_Symbol arg) */

ATbool SDF_hasSymbolRight(SDF_Symbol arg)
{
  if (SDF_isSymbolPair(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolAlt(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_getSymbolRight(SDF_Symbol arg) */

SDF_Symbol SDF_getSymbolRight(SDF_Symbol arg)
{
  if (SDF_isSymbolPair(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDF_isSymbolAlt(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Symbol has no Right: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolRight(SDF_Symbol arg, SDF_Symbol right) */

SDF_Symbol SDF_setSymbolRight(SDF_Symbol arg, SDF_Symbol right)
{
  if (SDF_isSymbolPair(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)right, 4), 2);
  }
  else if (SDF_isSymbolAlt(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)right, 4), 2);
  }

  ATabort("Symbol has no Right: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolArguments(SDF_Symbol arg) */

ATbool SDF_hasSymbolArguments(SDF_Symbol arg)
{
  if (SDF_isSymbolFunc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbols SDF_getSymbolArguments(SDF_Symbol arg) */

SDF_Symbols SDF_getSymbolArguments(SDF_Symbol arg)
{
  if (SDF_isSymbolFunc(arg)) {
    return (SDF_Symbols)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Symbol has no Arguments: %t\n", arg);
  return (SDF_Symbols)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolArguments(SDF_Symbol arg, SDF_Symbols arguments) */

SDF_Symbol SDF_setSymbolArguments(SDF_Symbol arg, SDF_Symbols arguments)
{
  if (SDF_isSymbolFunc(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)arguments, 2), 2);
  }

  ATabort("Symbol has no Arguments: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterArguments(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterArguments(SDF_Symbol arg)
{
  if (SDF_isSymbolFunc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolWsAfterArguments(SDF_Symbol arg) */

char * SDF_getSymbolWsAfterArguments(SDF_Symbol arg)
{
  if (SDF_isSymbolFunc(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Symbol has no WsAfterArguments: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterArguments(SDF_Symbol arg, char * wsAfterArguments) */

SDF_Symbol SDF_setSymbolWsAfterArguments(SDF_Symbol arg, char * wsAfterArguments)
{
  if (SDF_isSymbolFunc(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterArguments, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Symbol has no WsAfterArguments: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterEqualsGreaterThan(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterEqualsGreaterThan(SDF_Symbol arg)
{
  if (SDF_isSymbolFunc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolWsAfterEqualsGreaterThan(SDF_Symbol arg) */

char * SDF_getSymbolWsAfterEqualsGreaterThan(SDF_Symbol arg)
{
  if (SDF_isSymbolFunc(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0)));
  }

  ATabort("Symbol has no WsAfterEqualsGreaterThan: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterEqualsGreaterThan(SDF_Symbol arg, char * wsAfterEqualsGreaterThan) */

SDF_Symbol SDF_setSymbolWsAfterEqualsGreaterThan(SDF_Symbol arg, char * wsAfterEqualsGreaterThan)
{
  if (SDF_isSymbolFunc(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterEqualsGreaterThan, 0, ATtrue)), 0), 5), 2);
  }

  ATabort("Symbol has no WsAfterEqualsGreaterThan: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolResults(SDF_Symbol arg) */

ATbool SDF_hasSymbolResults(SDF_Symbol arg)
{
  if (SDF_isSymbolFunc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_getSymbolResults(SDF_Symbol arg) */

SDF_Symbol SDF_getSymbolResults(SDF_Symbol arg)
{
  if (SDF_isSymbolFunc(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 6);
  }

  ATabort("Symbol has no Results: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolResults(SDF_Symbol arg, SDF_Symbol results) */

SDF_Symbol SDF_setSymbolResults(SDF_Symbol arg, SDF_Symbol results)
{
  if (SDF_isSymbolFunc(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)results, 6), 2);
  }

  ATabort("Symbol has no Results: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterResults(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterResults(SDF_Symbol arg)
{
  if (SDF_isSymbolFunc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolWsAfterResults(SDF_Symbol arg) */

char * SDF_getSymbolWsAfterResults(SDF_Symbol arg)
{
  if (SDF_isSymbolFunc(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), 0)));
  }

  ATabort("Symbol has no WsAfterResults: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterResults(SDF_Symbol arg, char * wsAfterResults) */

SDF_Symbol SDF_setSymbolWsAfterResults(SDF_Symbol arg, char * wsAfterResults)
{
  if (SDF_isSymbolFunc(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterResults, 0, ATtrue)), 0), 7), 2);
  }

  ATabort("Symbol has no WsAfterResults: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterBar(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterBar(SDF_Symbol arg)
{
  if (SDF_isSymbolAlt(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolWsAfterBar(SDF_Symbol arg) */

char * SDF_getSymbolWsAfterBar(SDF_Symbol arg)
{
  if (SDF_isSymbolAlt(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Symbol has no WsAfterBar: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterBar(SDF_Symbol arg, char * wsAfterBar) */

SDF_Symbol SDF_setSymbolWsAfterBar(SDF_Symbol arg, char * wsAfterBar)
{
  if (SDF_isSymbolAlt(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterBar, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Symbol has no WsAfterBar: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterLessThanLessThan(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterLessThanLessThan(SDF_Symbol arg)
{
  if (SDF_isSymbolPerm(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolWsAfterLessThanLessThan(SDF_Symbol arg) */

char * SDF_getSymbolWsAfterLessThanLessThan(SDF_Symbol arg)
{
  if (SDF_isSymbolPerm(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Symbol has no WsAfterLessThanLessThan: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterLessThanLessThan(SDF_Symbol arg, char * wsAfterLessThanLessThan) */

SDF_Symbol SDF_setSymbolWsAfterLessThanLessThan(SDF_Symbol arg, char * wsAfterLessThanLessThan)
{
  if (SDF_isSymbolPerm(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterLessThanLessThan, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Symbol has no WsAfterLessThanLessThan: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolSymbols(SDF_Symbol arg) */

ATbool SDF_hasSymbolSymbols(SDF_Symbol arg)
{
  if (SDF_isSymbolPerm(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbols SDF_getSymbolSymbols(SDF_Symbol arg) */

SDF_Symbols SDF_getSymbolSymbols(SDF_Symbol arg)
{
  if (SDF_isSymbolPerm(arg)) {
    return (SDF_Symbols)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Symbol has no Symbols: %t\n", arg);
  return (SDF_Symbols)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolSymbols(SDF_Symbol arg, SDF_Symbols Symbols) */

SDF_Symbol SDF_setSymbolSymbols(SDF_Symbol arg, SDF_Symbols Symbols)
{
  if (SDF_isSymbolPerm(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Symbols, 2), 2);
  }

  ATabort("Symbol has no Symbols: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterSymbols(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterSymbols(SDF_Symbol arg)
{
  if (SDF_isSymbolPerm(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolWsAfterSymbols(SDF_Symbol arg) */

char * SDF_getSymbolWsAfterSymbols(SDF_Symbol arg)
{
  if (SDF_isSymbolPerm(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Symbol has no WsAfterSymbols: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterSymbols(SDF_Symbol arg, char * wsAfterSymbols) */

SDF_Symbol SDF_setSymbolWsAfterSymbols(SDF_Symbol arg, char * wsAfterSymbols)
{
  if (SDF_isSymbolPerm(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSymbols, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Symbol has no WsAfterSymbols: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolCharClass(SDF_Symbol arg) */

ATbool SDF_hasSymbolCharClass(SDF_Symbol arg)
{
  if (SDF_isSymbolCharClass(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_getSymbolCharClass(SDF_Symbol arg) */

SDF_CharClass SDF_getSymbolCharClass(SDF_Symbol arg)
{
  if (SDF_isSymbolCharClass(arg)) {
    return (SDF_CharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Symbol has no CharClass: %t\n", arg);
  return (SDF_CharClass)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolCharClass(SDF_Symbol arg, SDF_CharClass CharClass) */

SDF_Symbol SDF_setSymbolCharClass(SDF_Symbol arg, SDF_CharClass CharClass)
{
  if (SDF_isSymbolCharClass(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)CharClass, 0), 2);
  }

  ATabort("Symbol has no CharClass: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolSort(SDF_Symbol arg) */

ATbool SDF_hasSymbolSort(SDF_Symbol arg)
{
  if (SDF_isSymbolSort(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Sort SDF_getSymbolSort(SDF_Symbol arg) */

SDF_Sort SDF_getSymbolSort(SDF_Symbol arg)
{
  if (SDF_isSymbolSort(arg)) {
    return (SDF_Sort)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Symbol has no Sort: %t\n", arg);
  return (SDF_Sort)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolSort(SDF_Symbol arg, SDF_Sort Sort) */

SDF_Symbol SDF_setSymbolSort(SDF_Symbol arg, SDF_Sort Sort)
{
  if (SDF_isSymbolSort(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Sort, 0), 2);
  }

  ATabort("Symbol has no Sort: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolLiteral(SDF_Symbol arg) */

ATbool SDF_hasSymbolLiteral(SDF_Symbol arg)
{
  if (SDF_isSymbolLit(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Literal SDF_getSymbolLiteral(SDF_Symbol arg) */

SDF_Literal SDF_getSymbolLiteral(SDF_Symbol arg)
{
  if (SDF_isSymbolLit(arg)) {
    return (SDF_Literal)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Symbol has no Literal: %t\n", arg);
  return (SDF_Literal)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolLiteral(SDF_Symbol arg, SDF_Literal Literal) */

SDF_Symbol SDF_setSymbolLiteral(SDF_Symbol arg, SDF_Literal Literal)
{
  if (SDF_isSymbolLit(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Literal, 0), 2);
  }

  ATabort("Symbol has no Literal: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolLabel(SDF_Symbol arg) */

ATbool SDF_hasSymbolLabel(SDF_Symbol arg)
{
  if (SDF_isSymbolLabel(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Literal SDF_getSymbolLabel(SDF_Symbol arg) */

SDF_Literal SDF_getSymbolLabel(SDF_Symbol arg)
{
  if (SDF_isSymbolLabel(arg)) {
    return (SDF_Literal)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Symbol has no Label: %t\n", arg);
  return (SDF_Literal)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolLabel(SDF_Symbol arg, SDF_Literal label) */

SDF_Symbol SDF_setSymbolLabel(SDF_Symbol arg, SDF_Literal label)
{
  if (SDF_isSymbolLabel(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)label, 0), 2);
  }

  ATabort("Symbol has no Label: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterLabel(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterLabel(SDF_Symbol arg)
{
  if (SDF_isSymbolLabel(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolWsAfterLabel(SDF_Symbol arg) */

char * SDF_getSymbolWsAfterLabel(SDF_Symbol arg)
{
  if (SDF_isSymbolLabel(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Symbol has no WsAfterLabel: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterLabel(SDF_Symbol arg, char * wsAfterLabel) */

SDF_Symbol SDF_setSymbolWsAfterLabel(SDF_Symbol arg, char * wsAfterLabel)
{
  if (SDF_isSymbolLabel(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterLabel, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Symbol has no WsAfterLabel: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterColon(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterColon(SDF_Symbol arg)
{
  if (SDF_isSymbolLabel(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolWsAfterColon(SDF_Symbol arg) */

char * SDF_getSymbolWsAfterColon(SDF_Symbol arg)
{
  if (SDF_isSymbolLabel(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Symbol has no WsAfterColon: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterColon(SDF_Symbol arg, char * wsAfterColon) */

SDF_Symbol SDF_setSymbolWsAfterColon(SDF_Symbol arg, char * wsAfterColon)
{
  if (SDF_isSymbolLabel(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterColon, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Symbol has no WsAfterColon: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Grammar accessors */

/*{{{  ATbool SDF_isValidGrammar(SDF_Grammar arg) */

ATbool SDF_isValidGrammar(SDF_Grammar arg)
{
  if (SDF_isGrammarLexicalPriorities(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarContextFreePriorities(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarLexicalRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarContextFreeRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarSyntax(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarLexicalSyntax(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarContextFreeSyntax(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarVariables(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarLexicalVariables(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarImpSection(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarPriorities(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarSorts(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarAliases(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarEmptyGrammar(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarConcGrammars(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isGrammarLexicalPriorities(SDF_Grammar arg) */

ATbool SDF_isGrammarLexicalPriorities(SDF_Grammar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternGrammarLexicalPriorities, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isGrammarContextFreePriorities(SDF_Grammar arg) */

ATbool SDF_isGrammarContextFreePriorities(SDF_Grammar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternGrammarContextFreePriorities, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isGrammarLexicalRestrictions(SDF_Grammar arg) */

ATbool SDF_isGrammarLexicalRestrictions(SDF_Grammar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternGrammarLexicalRestrictions, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isGrammarContextFreeRestrictions(SDF_Grammar arg) */

ATbool SDF_isGrammarContextFreeRestrictions(SDF_Grammar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternGrammarContextFreeRestrictions, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isGrammarSyntax(SDF_Grammar arg) */

ATbool SDF_isGrammarSyntax(SDF_Grammar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternGrammarSyntax, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isGrammarLexicalSyntax(SDF_Grammar arg) */

ATbool SDF_isGrammarLexicalSyntax(SDF_Grammar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternGrammarLexicalSyntax, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isGrammarContextFreeSyntax(SDF_Grammar arg) */

ATbool SDF_isGrammarContextFreeSyntax(SDF_Grammar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternGrammarContextFreeSyntax, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isGrammarVariables(SDF_Grammar arg) */

ATbool SDF_isGrammarVariables(SDF_Grammar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternGrammarVariables, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isGrammarLexicalVariables(SDF_Grammar arg) */

ATbool SDF_isGrammarLexicalVariables(SDF_Grammar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternGrammarLexicalVariables, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isGrammarImpSection(SDF_Grammar arg) */

ATbool SDF_isGrammarImpSection(SDF_Grammar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternGrammarImpSection, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isGrammarPriorities(SDF_Grammar arg) */

ATbool SDF_isGrammarPriorities(SDF_Grammar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternGrammarPriorities, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isGrammarSorts(SDF_Grammar arg) */

ATbool SDF_isGrammarSorts(SDF_Grammar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternGrammarSorts, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isGrammarRestrictions(SDF_Grammar arg) */

ATbool SDF_isGrammarRestrictions(SDF_Grammar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternGrammarRestrictions, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isGrammarAliases(SDF_Grammar arg) */

ATbool SDF_isGrammarAliases(SDF_Grammar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternGrammarAliases, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isGrammarEmptyGrammar(SDF_Grammar arg) */

ATbool SDF_isGrammarEmptyGrammar(SDF_Grammar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternGrammarEmptyGrammar);
}

/*}}}  */
/*{{{  ATbool SDF_isGrammarConcGrammars(SDF_Grammar arg) */

ATbool SDF_isGrammarConcGrammars(SDF_Grammar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternGrammarConcGrammars, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isGrammarBracket(SDF_Grammar arg) */

ATbool SDF_isGrammarBracket(SDF_Grammar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternGrammarBracket, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarWsAfterLexical(SDF_Grammar arg) */

ATbool SDF_hasGrammarWsAfterLexical(SDF_Grammar arg)
{
  if (SDF_isGrammarLexicalPriorities(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarLexicalRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarLexicalSyntax(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarLexicalVariables(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getGrammarWsAfterLexical(SDF_Grammar arg) */

char * SDF_getGrammarWsAfterLexical(SDF_Grammar arg)
{
  if (SDF_isGrammarLexicalPriorities(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isGrammarLexicalRestrictions(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isGrammarLexicalSyntax(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isGrammarLexicalVariables(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Grammar has no WsAfterLexical: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterLexical(SDF_Grammar arg, char * wsAfterLexical) */

SDF_Grammar SDF_setGrammarWsAfterLexical(SDF_Grammar arg, char * wsAfterLexical)
{
  if (SDF_isGrammarLexicalPriorities(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterLexical, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isGrammarLexicalRestrictions(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterLexical, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isGrammarLexicalSyntax(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterLexical, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isGrammarLexicalVariables(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterLexical, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Grammar has no WsAfterLexical: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarWsAfterPriorities(SDF_Grammar arg) */

ATbool SDF_hasGrammarWsAfterPriorities(SDF_Grammar arg)
{
  if (SDF_isGrammarLexicalPriorities(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarContextFreePriorities(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarPriorities(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getGrammarWsAfterPriorities(SDF_Grammar arg) */

char * SDF_getGrammarWsAfterPriorities(SDF_Grammar arg)
{
  if (SDF_isGrammarLexicalPriorities(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }
  else if (SDF_isGrammarContextFreePriorities(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }
  else if (SDF_isGrammarPriorities(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Grammar has no WsAfterPriorities: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterPriorities(SDF_Grammar arg, char * wsAfterPriorities) */

SDF_Grammar SDF_setGrammarWsAfterPriorities(SDF_Grammar arg, char * wsAfterPriorities)
{
  if (SDF_isGrammarLexicalPriorities(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterPriorities, 0, ATtrue)), 0), 3), 2);
  }
  else if (SDF_isGrammarContextFreePriorities(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterPriorities, 0, ATtrue)), 0), 3), 2);
  }
  else if (SDF_isGrammarPriorities(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterPriorities, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Grammar has no WsAfterPriorities: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarPriorities(SDF_Grammar arg) */

ATbool SDF_hasGrammarPriorities(SDF_Grammar arg)
{
  if (SDF_isGrammarLexicalPriorities(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarContextFreePriorities(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarPriorities(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Priorities SDF_getGrammarPriorities(SDF_Grammar arg) */

SDF_Priorities SDF_getGrammarPriorities(SDF_Grammar arg)
{
  if (SDF_isGrammarLexicalPriorities(arg)) {
    return (SDF_Priorities)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDF_isGrammarContextFreePriorities(arg)) {
    return (SDF_Priorities)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDF_isGrammarPriorities(arg)) {
    return (SDF_Priorities)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Grammar has no Priorities: %t\n", arg);
  return (SDF_Priorities)NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarPriorities(SDF_Grammar arg, SDF_Priorities Priorities) */

SDF_Grammar SDF_setGrammarPriorities(SDF_Grammar arg, SDF_Priorities Priorities)
{
  if (SDF_isGrammarLexicalPriorities(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Priorities, 4), 2);
  }
  else if (SDF_isGrammarContextFreePriorities(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Priorities, 4), 2);
  }
  else if (SDF_isGrammarPriorities(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Priorities, 2), 2);
  }

  ATabort("Grammar has no Priorities: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarWsAfterContextFree(SDF_Grammar arg) */

ATbool SDF_hasGrammarWsAfterContextFree(SDF_Grammar arg)
{
  if (SDF_isGrammarContextFreePriorities(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarContextFreeRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarContextFreeSyntax(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getGrammarWsAfterContextFree(SDF_Grammar arg) */

char * SDF_getGrammarWsAfterContextFree(SDF_Grammar arg)
{
  if (SDF_isGrammarContextFreePriorities(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isGrammarContextFreeRestrictions(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isGrammarContextFreeSyntax(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Grammar has no WsAfterContextFree: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterContextFree(SDF_Grammar arg, char * wsAfterContextFree) */

SDF_Grammar SDF_setGrammarWsAfterContextFree(SDF_Grammar arg, char * wsAfterContextFree)
{
  if (SDF_isGrammarContextFreePriorities(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterContextFree, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isGrammarContextFreeRestrictions(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterContextFree, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isGrammarContextFreeSyntax(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterContextFree, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Grammar has no WsAfterContextFree: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarWsAfterRestrictions(SDF_Grammar arg) */

ATbool SDF_hasGrammarWsAfterRestrictions(SDF_Grammar arg)
{
  if (SDF_isGrammarLexicalRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarContextFreeRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarRestrictions(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getGrammarWsAfterRestrictions(SDF_Grammar arg) */

char * SDF_getGrammarWsAfterRestrictions(SDF_Grammar arg)
{
  if (SDF_isGrammarLexicalRestrictions(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }
  else if (SDF_isGrammarContextFreeRestrictions(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }
  else if (SDF_isGrammarRestrictions(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Grammar has no WsAfterRestrictions: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterRestrictions(SDF_Grammar arg, char * wsAfterRestrictions) */

SDF_Grammar SDF_setGrammarWsAfterRestrictions(SDF_Grammar arg, char * wsAfterRestrictions)
{
  if (SDF_isGrammarLexicalRestrictions(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterRestrictions, 0, ATtrue)), 0), 3), 2);
  }
  else if (SDF_isGrammarContextFreeRestrictions(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterRestrictions, 0, ATtrue)), 0), 3), 2);
  }
  else if (SDF_isGrammarRestrictions(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterRestrictions, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Grammar has no WsAfterRestrictions: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarRestrictions(SDF_Grammar arg) */

ATbool SDF_hasGrammarRestrictions(SDF_Grammar arg)
{
  if (SDF_isGrammarLexicalRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarContextFreeRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarRestrictions(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Restrictions SDF_getGrammarRestrictions(SDF_Grammar arg) */

SDF_Restrictions SDF_getGrammarRestrictions(SDF_Grammar arg)
{
  if (SDF_isGrammarLexicalRestrictions(arg)) {
    return (SDF_Restrictions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDF_isGrammarContextFreeRestrictions(arg)) {
    return (SDF_Restrictions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDF_isGrammarRestrictions(arg)) {
    return (SDF_Restrictions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Grammar has no Restrictions: %t\n", arg);
  return (SDF_Restrictions)NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarRestrictions(SDF_Grammar arg, SDF_Restrictions Restrictions) */

SDF_Grammar SDF_setGrammarRestrictions(SDF_Grammar arg, SDF_Restrictions Restrictions)
{
  if (SDF_isGrammarLexicalRestrictions(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Restrictions, 4), 2);
  }
  else if (SDF_isGrammarContextFreeRestrictions(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Restrictions, 4), 2);
  }
  else if (SDF_isGrammarRestrictions(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Restrictions, 2), 2);
  }

  ATabort("Grammar has no Restrictions: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarWsAfterSyntax(SDF_Grammar arg) */

ATbool SDF_hasGrammarWsAfterSyntax(SDF_Grammar arg)
{
  if (SDF_isGrammarSyntax(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarLexicalSyntax(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarContextFreeSyntax(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getGrammarWsAfterSyntax(SDF_Grammar arg) */

char * SDF_getGrammarWsAfterSyntax(SDF_Grammar arg)
{
  if (SDF_isGrammarSyntax(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isGrammarLexicalSyntax(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }
  else if (SDF_isGrammarContextFreeSyntax(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Grammar has no WsAfterSyntax: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterSyntax(SDF_Grammar arg, char * wsAfterSyntax) */

SDF_Grammar SDF_setGrammarWsAfterSyntax(SDF_Grammar arg, char * wsAfterSyntax)
{
  if (SDF_isGrammarSyntax(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSyntax, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isGrammarLexicalSyntax(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSyntax, 0, ATtrue)), 0), 3), 2);
  }
  else if (SDF_isGrammarContextFreeSyntax(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSyntax, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Grammar has no WsAfterSyntax: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarProductions(SDF_Grammar arg) */

ATbool SDF_hasGrammarProductions(SDF_Grammar arg)
{
  if (SDF_isGrammarSyntax(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarLexicalSyntax(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarContextFreeSyntax(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarVariables(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarLexicalVariables(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Productions SDF_getGrammarProductions(SDF_Grammar arg) */

SDF_Productions SDF_getGrammarProductions(SDF_Grammar arg)
{
  if (SDF_isGrammarSyntax(arg)) {
    return (SDF_Productions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDF_isGrammarLexicalSyntax(arg)) {
    return (SDF_Productions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDF_isGrammarContextFreeSyntax(arg)) {
    return (SDF_Productions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDF_isGrammarVariables(arg)) {
    return (SDF_Productions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDF_isGrammarLexicalVariables(arg)) {
    return (SDF_Productions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Grammar has no Productions: %t\n", arg);
  return (SDF_Productions)NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarProductions(SDF_Grammar arg, SDF_Productions Productions) */

SDF_Grammar SDF_setGrammarProductions(SDF_Grammar arg, SDF_Productions Productions)
{
  if (SDF_isGrammarSyntax(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Productions, 2), 2);
  }
  else if (SDF_isGrammarLexicalSyntax(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Productions, 4), 2);
  }
  else if (SDF_isGrammarContextFreeSyntax(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Productions, 4), 2);
  }
  else if (SDF_isGrammarVariables(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Productions, 2), 2);
  }
  else if (SDF_isGrammarLexicalVariables(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Productions, 4), 2);
  }

  ATabort("Grammar has no Productions: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarWsAfterVariables(SDF_Grammar arg) */

ATbool SDF_hasGrammarWsAfterVariables(SDF_Grammar arg)
{
  if (SDF_isGrammarVariables(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarLexicalVariables(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getGrammarWsAfterVariables(SDF_Grammar arg) */

char * SDF_getGrammarWsAfterVariables(SDF_Grammar arg)
{
  if (SDF_isGrammarVariables(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isGrammarLexicalVariables(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Grammar has no WsAfterVariables: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterVariables(SDF_Grammar arg, char * wsAfterVariables) */

SDF_Grammar SDF_setGrammarWsAfterVariables(SDF_Grammar arg, char * wsAfterVariables)
{
  if (SDF_isGrammarVariables(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterVariables, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isGrammarLexicalVariables(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterVariables, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Grammar has no WsAfterVariables: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarImpSection(SDF_Grammar arg) */

ATbool SDF_hasGrammarImpSection(SDF_Grammar arg)
{
  if (SDF_isGrammarImpSection(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ImpSection SDF_getGrammarImpSection(SDF_Grammar arg) */

SDF_ImpSection SDF_getGrammarImpSection(SDF_Grammar arg)
{
  if (SDF_isGrammarImpSection(arg)) {
    return (SDF_ImpSection)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Grammar has no ImpSection: %t\n", arg);
  return (SDF_ImpSection)NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarImpSection(SDF_Grammar arg, SDF_ImpSection ImpSection) */

SDF_Grammar SDF_setGrammarImpSection(SDF_Grammar arg, SDF_ImpSection ImpSection)
{
  if (SDF_isGrammarImpSection(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ImpSection, 0), 2);
  }

  ATabort("Grammar has no ImpSection: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarWsAfterSorts(SDF_Grammar arg) */

ATbool SDF_hasGrammarWsAfterSorts(SDF_Grammar arg)
{
  if (SDF_isGrammarSorts(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getGrammarWsAfterSorts(SDF_Grammar arg) */

char * SDF_getGrammarWsAfterSorts(SDF_Grammar arg)
{
  if (SDF_isGrammarSorts(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Grammar has no WsAfterSorts: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterSorts(SDF_Grammar arg, char * wsAfterSorts) */

SDF_Grammar SDF_setGrammarWsAfterSorts(SDF_Grammar arg, char * wsAfterSorts)
{
  if (SDF_isGrammarSorts(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSorts, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Grammar has no WsAfterSorts: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarSymbols(SDF_Grammar arg) */

ATbool SDF_hasGrammarSymbols(SDF_Grammar arg)
{
  if (SDF_isGrammarSorts(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbols SDF_getGrammarSymbols(SDF_Grammar arg) */

SDF_Symbols SDF_getGrammarSymbols(SDF_Grammar arg)
{
  if (SDF_isGrammarSorts(arg)) {
    return (SDF_Symbols)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Grammar has no Symbols: %t\n", arg);
  return (SDF_Symbols)NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarSymbols(SDF_Grammar arg, SDF_Symbols Symbols) */

SDF_Grammar SDF_setGrammarSymbols(SDF_Grammar arg, SDF_Symbols Symbols)
{
  if (SDF_isGrammarSorts(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Symbols, 2), 2);
  }

  ATabort("Grammar has no Symbols: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarWsAfterAliases(SDF_Grammar arg) */

ATbool SDF_hasGrammarWsAfterAliases(SDF_Grammar arg)
{
  if (SDF_isGrammarAliases(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getGrammarWsAfterAliases(SDF_Grammar arg) */

char * SDF_getGrammarWsAfterAliases(SDF_Grammar arg)
{
  if (SDF_isGrammarAliases(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Grammar has no WsAfterAliases: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterAliases(SDF_Grammar arg, char * wsAfterAliases) */

SDF_Grammar SDF_setGrammarWsAfterAliases(SDF_Grammar arg, char * wsAfterAliases)
{
  if (SDF_isGrammarAliases(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterAliases, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Grammar has no WsAfterAliases: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarAliases(SDF_Grammar arg) */

ATbool SDF_hasGrammarAliases(SDF_Grammar arg)
{
  if (SDF_isGrammarAliases(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Aliases SDF_getGrammarAliases(SDF_Grammar arg) */

SDF_Aliases SDF_getGrammarAliases(SDF_Grammar arg)
{
  if (SDF_isGrammarAliases(arg)) {
    return (SDF_Aliases)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Grammar has no Aliases: %t\n", arg);
  return (SDF_Aliases)NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarAliases(SDF_Grammar arg, SDF_Aliases Aliases) */

SDF_Grammar SDF_setGrammarAliases(SDF_Grammar arg, SDF_Aliases Aliases)
{
  if (SDF_isGrammarAliases(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Aliases, 2), 2);
  }

  ATabort("Grammar has no Aliases: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarLeft(SDF_Grammar arg) */

ATbool SDF_hasGrammarLeft(SDF_Grammar arg)
{
  if (SDF_isGrammarConcGrammars(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_getGrammarLeft(SDF_Grammar arg) */

SDF_Grammar SDF_getGrammarLeft(SDF_Grammar arg)
{
  if (SDF_isGrammarConcGrammars(arg)) {
    return (SDF_Grammar)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Grammar has no Left: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarLeft(SDF_Grammar arg, SDF_Grammar left) */

SDF_Grammar SDF_setGrammarLeft(SDF_Grammar arg, SDF_Grammar left)
{
  if (SDF_isGrammarConcGrammars(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)left, 0), 2);
  }

  ATabort("Grammar has no Left: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarWsAfterLeft(SDF_Grammar arg) */

ATbool SDF_hasGrammarWsAfterLeft(SDF_Grammar arg)
{
  if (SDF_isGrammarConcGrammars(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getGrammarWsAfterLeft(SDF_Grammar arg) */

char * SDF_getGrammarWsAfterLeft(SDF_Grammar arg)
{
  if (SDF_isGrammarConcGrammars(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Grammar has no WsAfterLeft: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterLeft(SDF_Grammar arg, char * wsAfterLeft) */

SDF_Grammar SDF_setGrammarWsAfterLeft(SDF_Grammar arg, char * wsAfterLeft)
{
  if (SDF_isGrammarConcGrammars(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterLeft, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Grammar has no WsAfterLeft: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarRight(SDF_Grammar arg) */

ATbool SDF_hasGrammarRight(SDF_Grammar arg)
{
  if (SDF_isGrammarConcGrammars(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_getGrammarRight(SDF_Grammar arg) */

SDF_Grammar SDF_getGrammarRight(SDF_Grammar arg)
{
  if (SDF_isGrammarConcGrammars(arg)) {
    return (SDF_Grammar)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Grammar has no Right: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarRight(SDF_Grammar arg, SDF_Grammar right) */

SDF_Grammar SDF_setGrammarRight(SDF_Grammar arg, SDF_Grammar right)
{
  if (SDF_isGrammarConcGrammars(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)right, 2), 2);
  }

  ATabort("Grammar has no Right: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarWsAfterParenOpen(SDF_Grammar arg) */

ATbool SDF_hasGrammarWsAfterParenOpen(SDF_Grammar arg)
{
  if (SDF_isGrammarBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getGrammarWsAfterParenOpen(SDF_Grammar arg) */

char * SDF_getGrammarWsAfterParenOpen(SDF_Grammar arg)
{
  if (SDF_isGrammarBracket(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Grammar has no WsAfterParenOpen: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterParenOpen(SDF_Grammar arg, char * wsAfterParenOpen) */

SDF_Grammar SDF_setGrammarWsAfterParenOpen(SDF_Grammar arg, char * wsAfterParenOpen)
{
  if (SDF_isGrammarBracket(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterParenOpen, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Grammar has no WsAfterParenOpen: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarGrammar(SDF_Grammar arg) */

ATbool SDF_hasGrammarGrammar(SDF_Grammar arg)
{
  if (SDF_isGrammarBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_getGrammarGrammar(SDF_Grammar arg) */

SDF_Grammar SDF_getGrammarGrammar(SDF_Grammar arg)
{
  if (SDF_isGrammarBracket(arg)) {
    return (SDF_Grammar)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Grammar has no Grammar: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarGrammar(SDF_Grammar arg, SDF_Grammar Grammar) */

SDF_Grammar SDF_setGrammarGrammar(SDF_Grammar arg, SDF_Grammar Grammar)
{
  if (SDF_isGrammarBracket(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Grammar, 2), 2);
  }

  ATabort("Grammar has no Grammar: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarWsAfterGrammar(SDF_Grammar arg) */

ATbool SDF_hasGrammarWsAfterGrammar(SDF_Grammar arg)
{
  if (SDF_isGrammarBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getGrammarWsAfterGrammar(SDF_Grammar arg) */

char * SDF_getGrammarWsAfterGrammar(SDF_Grammar arg)
{
  if (SDF_isGrammarBracket(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Grammar has no WsAfterGrammar: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterGrammar(SDF_Grammar arg, char * wsAfterGrammar) */

SDF_Grammar SDF_setGrammarWsAfterGrammar(SDF_Grammar arg, char * wsAfterGrammar)
{
  if (SDF_isGrammarBracket(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterGrammar, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Grammar has no WsAfterGrammar: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_SDF accessors */

/*{{{  ATbool SDF_isValidSDF(SDF_SDF arg) */

ATbool SDF_isValidSDF(SDF_SDF arg)
{
  if (SDF_isSDFDefinition(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isSDFDefinition(SDF_SDF arg) */

ATbool SDF_isSDFDefinition(SDF_SDF arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSDFDefinition, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasSDFWsAfterDefinition(SDF_SDF arg) */

ATbool SDF_hasSDFWsAfterDefinition(SDF_SDF arg)
{
  if (SDF_isSDFDefinition(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSDFWsAfterDefinition(SDF_SDF arg) */

char * SDF_getSDFWsAfterDefinition(SDF_SDF arg)
{
  if (SDF_isSDFDefinition(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("SDF has no WsAfterDefinition: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_SDF SDF_setSDFWsAfterDefinition(SDF_SDF arg, char * wsAfterDefinition) */

SDF_SDF SDF_setSDFWsAfterDefinition(SDF_SDF arg, char * wsAfterDefinition)
{
  if (SDF_isSDFDefinition(arg)) {
    return (SDF_SDF)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterDefinition, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("SDF has no WsAfterDefinition: %t\n", arg);
  return (SDF_SDF)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSDFDefinition(SDF_SDF arg) */

ATbool SDF_hasSDFDefinition(SDF_SDF arg)
{
  if (SDF_isSDFDefinition(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Definition SDF_getSDFDefinition(SDF_SDF arg) */

SDF_Definition SDF_getSDFDefinition(SDF_SDF arg)
{
  if (SDF_isSDFDefinition(arg)) {
    return (SDF_Definition)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("SDF has no Definition: %t\n", arg);
  return (SDF_Definition)NULL;
}

/*}}}  */
/*{{{  SDF_SDF SDF_setSDFDefinition(SDF_SDF arg, SDF_Definition Definition) */

SDF_SDF SDF_setSDFDefinition(SDF_SDF arg, SDF_Definition Definition)
{
  if (SDF_isSDFDefinition(arg)) {
    return (SDF_SDF)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Definition, 2), 2);
  }

  ATabort("SDF has no Definition: %t\n", arg);
  return (SDF_SDF)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Attributes accessors */

/*{{{  ATbool SDF_isValidAttributes(SDF_Attributes arg) */

ATbool SDF_isValidAttributes(SDF_Attributes arg)
{
  if (SDF_isAttributesAttrs(arg)) {
    return ATtrue;
  }
  else if (SDF_isAttributesNoAttrs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isAttributesAttrs(SDF_Attributes arg) */

ATbool SDF_isAttributesAttrs(SDF_Attributes arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAttributesAttrs, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isAttributesNoAttrs(SDF_Attributes arg) */

ATbool SDF_isAttributesNoAttrs(SDF_Attributes arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAttributesNoAttrs);
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributesWsAfterBraceOpen(SDF_Attributes arg) */

ATbool SDF_hasAttributesWsAfterBraceOpen(SDF_Attributes arg)
{
  if (SDF_isAttributesAttrs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getAttributesWsAfterBraceOpen(SDF_Attributes arg) */

char * SDF_getAttributesWsAfterBraceOpen(SDF_Attributes arg)
{
  if (SDF_isAttributesAttrs(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Attributes has no WsAfterBraceOpen: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Attributes SDF_setAttributesWsAfterBraceOpen(SDF_Attributes arg, char * wsAfterBraceOpen) */

SDF_Attributes SDF_setAttributesWsAfterBraceOpen(SDF_Attributes arg, char * wsAfterBraceOpen)
{
  if (SDF_isAttributesAttrs(arg)) {
    return (SDF_Attributes)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterBraceOpen, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Attributes has no WsAfterBraceOpen: %t\n", arg);
  return (SDF_Attributes)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributesList(SDF_Attributes arg) */

ATbool SDF_hasAttributesList(SDF_Attributes arg)
{
  if (SDF_isAttributesAttrs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_AttributeList SDF_getAttributesList(SDF_Attributes arg) */

SDF_AttributeList SDF_getAttributesList(SDF_Attributes arg)
{
  if (SDF_isAttributesAttrs(arg)) {
    return (SDF_AttributeList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2), 2);
  }

  ATabort("Attributes has no List: %t\n", arg);
  return (SDF_AttributeList)NULL;
}

/*}}}  */
/*{{{  SDF_Attributes SDF_setAttributesList(SDF_Attributes arg, SDF_AttributeList list) */

SDF_Attributes SDF_setAttributesList(SDF_Attributes arg, SDF_AttributeList list)
{
  if (SDF_isAttributesAttrs(arg)) {
    return (SDF_Attributes)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2), (ATerm)list, 2), 2), 2);
  }

  ATabort("Attributes has no List: %t\n", arg);
  return (SDF_Attributes)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributesWsAfterList(SDF_Attributes arg) */

ATbool SDF_hasAttributesWsAfterList(SDF_Attributes arg)
{
  if (SDF_isAttributesAttrs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getAttributesWsAfterList(SDF_Attributes arg) */

char * SDF_getAttributesWsAfterList(SDF_Attributes arg)
{
  if (SDF_isAttributesAttrs(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Attributes has no WsAfterList: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Attributes SDF_setAttributesWsAfterList(SDF_Attributes arg, char * wsAfterList) */

SDF_Attributes SDF_setAttributesWsAfterList(SDF_Attributes arg, char * wsAfterList)
{
  if (SDF_isAttributesAttrs(arg)) {
    return (SDF_Attributes)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterList, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Attributes has no WsAfterList: %t\n", arg);
  return (SDF_Attributes)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_AttributeList accessors */

/*{{{  ATbool SDF_isValidAttributeList(SDF_AttributeList arg) */

ATbool SDF_isValidAttributeList(SDF_AttributeList arg)
{
  if (SDF_isAttributeListEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isAttributeListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isAttributeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isAttributeListEmpty(SDF_AttributeList arg) */

ATbool SDF_isAttributeListEmpty(SDF_AttributeList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAttributeListEmpty);
}

/*}}}  */
/*{{{  ATbool SDF_isAttributeListSingle(SDF_AttributeList arg) */

ATbool SDF_isAttributeListSingle(SDF_AttributeList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAttributeListSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isAttributeListMany(SDF_AttributeList arg) */

ATbool SDF_isAttributeListMany(SDF_AttributeList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAttributeListMany, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributeListHead(SDF_AttributeList arg) */

ATbool SDF_hasAttributeListHead(SDF_AttributeList arg)
{
  if (SDF_isAttributeListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isAttributeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Attribute SDF_getAttributeListHead(SDF_AttributeList arg) */

SDF_Attribute SDF_getAttributeListHead(SDF_AttributeList arg)
{
  if (SDF_isAttributeListSingle(arg)) {
    return (SDF_Attribute)ATelementAt((ATermList)arg, 0);
  }
  else if (SDF_isAttributeListMany(arg)) {
    return (SDF_Attribute)ATelementAt((ATermList)arg, 0);
  }

  ATabort("AttributeList has no Head: %t\n", arg);
  return (SDF_Attribute)NULL;
}

/*}}}  */
/*{{{  SDF_AttributeList SDF_setAttributeListHead(SDF_AttributeList arg, SDF_Attribute head) */

SDF_AttributeList SDF_setAttributeListHead(SDF_AttributeList arg, SDF_Attribute head)
{
  if (SDF_isAttributeListSingle(arg)) {
    return (SDF_AttributeList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isAttributeListMany(arg)) {
    return (SDF_AttributeList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("AttributeList has no Head: %t\n", arg);
  return (SDF_AttributeList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributeListWsAfterFirst(SDF_AttributeList arg) */

ATbool SDF_hasAttributeListWsAfterFirst(SDF_AttributeList arg)
{
  if (SDF_isAttributeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getAttributeListWsAfterFirst(SDF_AttributeList arg) */

char * SDF_getAttributeListWsAfterFirst(SDF_AttributeList arg)
{
  if (SDF_isAttributeListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0)));
  }

  ATabort("AttributeList has no WsAfterFirst: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_AttributeList SDF_setAttributeListWsAfterFirst(SDF_AttributeList arg, char * wsAfterFirst) */

SDF_AttributeList SDF_setAttributeListWsAfterFirst(SDF_AttributeList arg, char * wsAfterFirst)
{
  if (SDF_isAttributeListMany(arg)) {
    return (SDF_AttributeList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterFirst, 0, ATtrue)), 0), 1);
  }

  ATabort("AttributeList has no WsAfterFirst: %t\n", arg);
  return (SDF_AttributeList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributeListSep(SDF_AttributeList arg) */

ATbool SDF_hasAttributeListSep(SDF_AttributeList arg)
{
  if (SDF_isAttributeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getAttributeListSep(SDF_AttributeList arg) */

char * SDF_getAttributeListSep(SDF_AttributeList arg)
{
  if (SDF_isAttributeListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
  }

  ATabort("AttributeList has no Sep: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_AttributeList SDF_setAttributeListSep(SDF_AttributeList arg, char * sep) */

SDF_AttributeList SDF_setAttributeListSep(SDF_AttributeList arg, char * sep)
{
  if (SDF_isAttributeListMany(arg)) {
    return (SDF_AttributeList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("AttributeList has no Sep: %t\n", arg);
  return (SDF_AttributeList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributeListWsAfterSep(SDF_AttributeList arg) */

ATbool SDF_hasAttributeListWsAfterSep(SDF_AttributeList arg)
{
  if (SDF_isAttributeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getAttributeListWsAfterSep(SDF_AttributeList arg) */

char * SDF_getAttributeListWsAfterSep(SDF_AttributeList arg)
{
  if (SDF_isAttributeListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), 0)));
  }

  ATabort("AttributeList has no WsAfterSep: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_AttributeList SDF_setAttributeListWsAfterSep(SDF_AttributeList arg, char * wsAfterSep) */

SDF_AttributeList SDF_setAttributeListWsAfterSep(SDF_AttributeList arg, char * wsAfterSep)
{
  if (SDF_isAttributeListMany(arg)) {
    return (SDF_AttributeList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSep, 0, ATtrue)), 0), 3);
  }

  ATabort("AttributeList has no WsAfterSep: %t\n", arg);
  return (SDF_AttributeList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributeListTail(SDF_AttributeList arg) */

ATbool SDF_hasAttributeListTail(SDF_AttributeList arg)
{
  if (SDF_isAttributeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_AttributeList SDF_getAttributeListTail(SDF_AttributeList arg) */

SDF_AttributeList SDF_getAttributeListTail(SDF_AttributeList arg)
{
  if (SDF_isAttributeListMany(arg)) {
    return (SDF_AttributeList)ATgetTail((ATermList)arg, 4);
  }

  ATabort("AttributeList has no Tail: %t\n", arg);
  return (SDF_AttributeList)NULL;
}

/*}}}  */
/*{{{  SDF_AttributeList SDF_setAttributeListTail(SDF_AttributeList arg, SDF_AttributeList tail) */

SDF_AttributeList SDF_setAttributeListTail(SDF_AttributeList arg, SDF_AttributeList tail)
{
  if (SDF_isAttributeListMany(arg)) {
    return (SDF_AttributeList)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("AttributeList has no Tail: %t\n", arg);
  return (SDF_AttributeList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Production accessors */

/*{{{  ATbool SDF_isValidProduction(SDF_Production arg) */

ATbool SDF_isValidProduction(SDF_Production arg)
{
  if (SDF_isProductionProd(arg)) {
    return ATtrue;
  }
  else if (SDF_isProductionProdFun(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isProductionProd(SDF_Production arg) */

ATbool SDF_isProductionProd(SDF_Production arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternProductionProd, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isProductionProdFun(SDF_Production arg) */

ATbool SDF_isProductionProdFun(SDF_Production arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternProductionProdFun, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasProductionSymbols(SDF_Production arg) */

ATbool SDF_hasProductionSymbols(SDF_Production arg)
{
  if (SDF_isProductionProd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbols SDF_getProductionSymbols(SDF_Production arg) */

SDF_Symbols SDF_getProductionSymbols(SDF_Production arg)
{
  if (SDF_isProductionProd(arg)) {
    return (SDF_Symbols)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Production has no Symbols: %t\n", arg);
  return (SDF_Symbols)NULL;
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionSymbols(SDF_Production arg, SDF_Symbols Symbols) */

SDF_Production SDF_setProductionSymbols(SDF_Production arg, SDF_Symbols Symbols)
{
  if (SDF_isProductionProd(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Symbols, 0), 2);
  }

  ATabort("Production has no Symbols: %t\n", arg);
  return (SDF_Production)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasProductionWsAfterSymbols(SDF_Production arg) */

ATbool SDF_hasProductionWsAfterSymbols(SDF_Production arg)
{
  if (SDF_isProductionProd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getProductionWsAfterSymbols(SDF_Production arg) */

char * SDF_getProductionWsAfterSymbols(SDF_Production arg)
{
  if (SDF_isProductionProd(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Production has no WsAfterSymbols: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionWsAfterSymbols(SDF_Production arg, char * wsAfterSymbols) */

SDF_Production SDF_setProductionWsAfterSymbols(SDF_Production arg, char * wsAfterSymbols)
{
  if (SDF_isProductionProd(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSymbols, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Production has no WsAfterSymbols: %t\n", arg);
  return (SDF_Production)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasProductionWsAfterGreaterThan(SDF_Production arg) */

ATbool SDF_hasProductionWsAfterGreaterThan(SDF_Production arg)
{
  if (SDF_isProductionProd(arg)) {
    return ATtrue;
  }
  else if (SDF_isProductionProdFun(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getProductionWsAfterGreaterThan(SDF_Production arg) */

char * SDF_getProductionWsAfterGreaterThan(SDF_Production arg)
{
  if (SDF_isProductionProd(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }
  else if (SDF_isProductionProdFun(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 9), 0)));
  }

  ATabort("Production has no WsAfterGreaterThan: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionWsAfterGreaterThan(SDF_Production arg, char * wsAfterGreaterThan) */

SDF_Production SDF_setProductionWsAfterGreaterThan(SDF_Production arg, char * wsAfterGreaterThan)
{
  if (SDF_isProductionProd(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterGreaterThan, 0, ATtrue)), 0), 3), 2);
  }
  else if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 9), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterGreaterThan, 0, ATtrue)), 0), 9), 2);
  }

  ATabort("Production has no WsAfterGreaterThan: %t\n", arg);
  return (SDF_Production)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasProductionResult(SDF_Production arg) */

ATbool SDF_hasProductionResult(SDF_Production arg)
{
  if (SDF_isProductionProd(arg)) {
    return ATtrue;
  }
  else if (SDF_isProductionProdFun(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_getProductionResult(SDF_Production arg) */

SDF_Symbol SDF_getProductionResult(SDF_Production arg)
{
  if (SDF_isProductionProd(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDF_isProductionProdFun(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 10);
  }

  ATabort("Production has no Result: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionResult(SDF_Production arg, SDF_Symbol result) */

SDF_Production SDF_setProductionResult(SDF_Production arg, SDF_Symbol result)
{
  if (SDF_isProductionProd(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)result, 4), 2);
  }
  else if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)result, 10), 2);
  }

  ATabort("Production has no Result: %t\n", arg);
  return (SDF_Production)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasProductionWsAfterResult(SDF_Production arg) */

ATbool SDF_hasProductionWsAfterResult(SDF_Production arg)
{
  if (SDF_isProductionProd(arg)) {
    return ATtrue;
  }
  else if (SDF_isProductionProdFun(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getProductionWsAfterResult(SDF_Production arg) */

char * SDF_getProductionWsAfterResult(SDF_Production arg)
{
  if (SDF_isProductionProd(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0)));
  }
  else if (SDF_isProductionProdFun(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 11), 0)));
  }

  ATabort("Production has no WsAfterResult: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionWsAfterResult(SDF_Production arg, char * wsAfterResult) */

SDF_Production SDF_setProductionWsAfterResult(SDF_Production arg, char * wsAfterResult)
{
  if (SDF_isProductionProd(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterResult, 0, ATtrue)), 0), 5), 2);
  }
  else if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 11), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterResult, 0, ATtrue)), 0), 11), 2);
  }

  ATabort("Production has no WsAfterResult: %t\n", arg);
  return (SDF_Production)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasProductionAttributes(SDF_Production arg) */

ATbool SDF_hasProductionAttributes(SDF_Production arg)
{
  if (SDF_isProductionProd(arg)) {
    return ATtrue;
  }
  else if (SDF_isProductionProdFun(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Attributes SDF_getProductionAttributes(SDF_Production arg) */

SDF_Attributes SDF_getProductionAttributes(SDF_Production arg)
{
  if (SDF_isProductionProd(arg)) {
    return (SDF_Attributes)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 6);
  }
  else if (SDF_isProductionProdFun(arg)) {
    return (SDF_Attributes)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 12);
  }

  ATabort("Production has no Attributes: %t\n", arg);
  return (SDF_Attributes)NULL;
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionAttributes(SDF_Production arg, SDF_Attributes Attributes) */

SDF_Production SDF_setProductionAttributes(SDF_Production arg, SDF_Attributes Attributes)
{
  if (SDF_isProductionProd(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Attributes, 6), 2);
  }
  else if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Attributes, 12), 2);
  }

  ATabort("Production has no Attributes: %t\n", arg);
  return (SDF_Production)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasProductionFunctionSymbol(SDF_Production arg) */

ATbool SDF_hasProductionFunctionSymbol(SDF_Production arg)
{
  if (SDF_isProductionProdFun(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Literal SDF_getProductionFunctionSymbol(SDF_Production arg) */

SDF_Literal SDF_getProductionFunctionSymbol(SDF_Production arg)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Literal)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Production has no FunctionSymbol: %t\n", arg);
  return (SDF_Literal)NULL;
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionFunctionSymbol(SDF_Production arg, SDF_Literal functionSymbol) */

SDF_Production SDF_setProductionFunctionSymbol(SDF_Production arg, SDF_Literal functionSymbol)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)functionSymbol, 0), 2);
  }

  ATabort("Production has no FunctionSymbol: %t\n", arg);
  return (SDF_Production)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasProductionWsAfterFunctionSymbol(SDF_Production arg) */

ATbool SDF_hasProductionWsAfterFunctionSymbol(SDF_Production arg)
{
  if (SDF_isProductionProdFun(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getProductionWsAfterFunctionSymbol(SDF_Production arg) */

char * SDF_getProductionWsAfterFunctionSymbol(SDF_Production arg)
{
  if (SDF_isProductionProdFun(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Production has no WsAfterFunctionSymbol: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionWsAfterFunctionSymbol(SDF_Production arg, char * wsAfterFunctionSymbol) */

SDF_Production SDF_setProductionWsAfterFunctionSymbol(SDF_Production arg, char * wsAfterFunctionSymbol)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterFunctionSymbol, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Production has no WsAfterFunctionSymbol: %t\n", arg);
  return (SDF_Production)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasProductionWsAfterParenOpen(SDF_Production arg) */

ATbool SDF_hasProductionWsAfterParenOpen(SDF_Production arg)
{
  if (SDF_isProductionProdFun(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getProductionWsAfterParenOpen(SDF_Production arg) */

char * SDF_getProductionWsAfterParenOpen(SDF_Production arg)
{
  if (SDF_isProductionProdFun(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Production has no WsAfterParenOpen: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionWsAfterParenOpen(SDF_Production arg, char * wsAfterParenOpen) */

SDF_Production SDF_setProductionWsAfterParenOpen(SDF_Production arg, char * wsAfterParenOpen)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterParenOpen, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Production has no WsAfterParenOpen: %t\n", arg);
  return (SDF_Production)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasProductionArguments(SDF_Production arg) */

ATbool SDF_hasProductionArguments(SDF_Production arg)
{
  if (SDF_isProductionProdFun(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_SymbolArguments SDF_getProductionArguments(SDF_Production arg) */

SDF_SymbolArguments SDF_getProductionArguments(SDF_Production arg)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_SymbolArguments)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4), 2);
  }

  ATabort("Production has no Arguments: %t\n", arg);
  return (SDF_SymbolArguments)NULL;
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionArguments(SDF_Production arg, SDF_SymbolArguments arguments) */

SDF_Production SDF_setProductionArguments(SDF_Production arg, SDF_SymbolArguments arguments)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4), (ATerm)arguments, 2), 4), 2);
  }

  ATabort("Production has no Arguments: %t\n", arg);
  return (SDF_Production)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasProductionWsAfterArguments(SDF_Production arg) */

ATbool SDF_hasProductionWsAfterArguments(SDF_Production arg)
{
  if (SDF_isProductionProdFun(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getProductionWsAfterArguments(SDF_Production arg) */

char * SDF_getProductionWsAfterArguments(SDF_Production arg)
{
  if (SDF_isProductionProdFun(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0)));
  }

  ATabort("Production has no WsAfterArguments: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionWsAfterArguments(SDF_Production arg, char * wsAfterArguments) */

SDF_Production SDF_setProductionWsAfterArguments(SDF_Production arg, char * wsAfterArguments)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterArguments, 0, ATtrue)), 0), 5), 2);
  }

  ATabort("Production has no WsAfterArguments: %t\n", arg);
  return (SDF_Production)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasProductionWsAfterParenClose(SDF_Production arg) */

ATbool SDF_hasProductionWsAfterParenClose(SDF_Production arg)
{
  if (SDF_isProductionProdFun(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getProductionWsAfterParenClose(SDF_Production arg) */

char * SDF_getProductionWsAfterParenClose(SDF_Production arg)
{
  if (SDF_isProductionProdFun(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), 0)));
  }

  ATabort("Production has no WsAfterParenClose: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionWsAfterParenClose(SDF_Production arg, char * wsAfterParenClose) */

SDF_Production SDF_setProductionWsAfterParenClose(SDF_Production arg, char * wsAfterParenClose)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterParenClose, 0, ATtrue)), 0), 7), 2);
  }

  ATabort("Production has no WsAfterParenClose: %t\n", arg);
  return (SDF_Production)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Productions accessors */

/*{{{  ATbool SDF_isValidProductions(SDF_Productions arg) */

ATbool SDF_isValidProductions(SDF_Productions arg)
{
  if (SDF_isProductionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isProductionsDefault(SDF_Productions arg) */

ATbool SDF_isProductionsDefault(SDF_Productions arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternProductionsDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasProductionsList(SDF_Productions arg) */

ATbool SDF_hasProductionsList(SDF_Productions arg)
{
  if (SDF_isProductionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ProductionList SDF_getProductionsList(SDF_Productions arg) */

SDF_ProductionList SDF_getProductionsList(SDF_Productions arg)
{
  if (SDF_isProductionsDefault(arg)) {
    return (SDF_ProductionList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 2);
  }

  ATabort("Productions has no List: %t\n", arg);
  return (SDF_ProductionList)NULL;
}

/*}}}  */
/*{{{  SDF_Productions SDF_setProductionsList(SDF_Productions arg, SDF_ProductionList list) */

SDF_Productions SDF_setProductionsList(SDF_Productions arg, SDF_ProductionList list)
{
  if (SDF_isProductionsDefault(arg)) {
    return (SDF_Productions)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)list, 2), 0), 2);
  }

  ATabort("Productions has no List: %t\n", arg);
  return (SDF_Productions)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ProductionList accessors */

/*{{{  ATbool SDF_isValidProductionList(SDF_ProductionList arg) */

ATbool SDF_isValidProductionList(SDF_ProductionList arg)
{
  if (SDF_isProductionListEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isProductionListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isProductionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isProductionListEmpty(SDF_ProductionList arg) */

ATbool SDF_isProductionListEmpty(SDF_ProductionList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternProductionListEmpty);
}

/*}}}  */
/*{{{  ATbool SDF_isProductionListSingle(SDF_ProductionList arg) */

ATbool SDF_isProductionListSingle(SDF_ProductionList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternProductionListSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isProductionListMany(SDF_ProductionList arg) */

ATbool SDF_isProductionListMany(SDF_ProductionList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternProductionListMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasProductionListHead(SDF_ProductionList arg) */

ATbool SDF_hasProductionListHead(SDF_ProductionList arg)
{
  if (SDF_isProductionListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isProductionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Production SDF_getProductionListHead(SDF_ProductionList arg) */

SDF_Production SDF_getProductionListHead(SDF_ProductionList arg)
{
  if (SDF_isProductionListSingle(arg)) {
    return (SDF_Production)ATelementAt((ATermList)arg, 0);
  }
  else if (SDF_isProductionListMany(arg)) {
    return (SDF_Production)ATelementAt((ATermList)arg, 0);
  }

  ATabort("ProductionList has no Head: %t\n", arg);
  return (SDF_Production)NULL;
}

/*}}}  */
/*{{{  SDF_ProductionList SDF_setProductionListHead(SDF_ProductionList arg, SDF_Production head) */

SDF_ProductionList SDF_setProductionListHead(SDF_ProductionList arg, SDF_Production head)
{
  if (SDF_isProductionListSingle(arg)) {
    return (SDF_ProductionList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isProductionListMany(arg)) {
    return (SDF_ProductionList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("ProductionList has no Head: %t\n", arg);
  return (SDF_ProductionList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasProductionListWsAfterFirst(SDF_ProductionList arg) */

ATbool SDF_hasProductionListWsAfterFirst(SDF_ProductionList arg)
{
  if (SDF_isProductionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getProductionListWsAfterFirst(SDF_ProductionList arg) */

char * SDF_getProductionListWsAfterFirst(SDF_ProductionList arg)
{
  if (SDF_isProductionListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0)));
  }

  ATabort("ProductionList has no WsAfterFirst: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_ProductionList SDF_setProductionListWsAfterFirst(SDF_ProductionList arg, char * wsAfterFirst) */

SDF_ProductionList SDF_setProductionListWsAfterFirst(SDF_ProductionList arg, char * wsAfterFirst)
{
  if (SDF_isProductionListMany(arg)) {
    return (SDF_ProductionList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterFirst, 0, ATtrue)), 0), 1);
  }

  ATabort("ProductionList has no WsAfterFirst: %t\n", arg);
  return (SDF_ProductionList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasProductionListTail(SDF_ProductionList arg) */

ATbool SDF_hasProductionListTail(SDF_ProductionList arg)
{
  if (SDF_isProductionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ProductionList SDF_getProductionListTail(SDF_ProductionList arg) */

SDF_ProductionList SDF_getProductionListTail(SDF_ProductionList arg)
{
  if (SDF_isProductionListMany(arg)) {
    return (SDF_ProductionList)ATgetTail((ATermList)arg, 2);
  }

  ATabort("ProductionList has no Tail: %t\n", arg);
  return (SDF_ProductionList)NULL;
}

/*}}}  */
/*{{{  SDF_ProductionList SDF_setProductionListTail(SDF_ProductionList arg, SDF_ProductionList tail) */

SDF_ProductionList SDF_setProductionListTail(SDF_ProductionList arg, SDF_ProductionList tail)
{
  if (SDF_isProductionListMany(arg)) {
    return (SDF_ProductionList)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("ProductionList has no Tail: %t\n", arg);
  return (SDF_ProductionList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ModuleWord accessors */

/*{{{  ATbool SDF_isValidModuleWord(SDF_ModuleWord arg) */

ATbool SDF_isValidModuleWord(SDF_ModuleWord arg)
{
  if (SDF_isModuleWordWord(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isModuleWordWord(SDF_ModuleWord arg) */

ATbool SDF_isModuleWordWord(SDF_ModuleWord arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternModuleWordWord, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasModuleWordLex(SDF_ModuleWord arg) */

ATbool SDF_hasModuleWordLex(SDF_ModuleWord arg)
{
  if (SDF_isModuleWordWord(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getModuleWordLex(SDF_ModuleWord arg) */

char * SDF_getModuleWordLex(SDF_ModuleWord arg)
{
  if (SDF_isModuleWordWord(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }

  ATabort("ModuleWord has no Lex: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_ModuleWord SDF_setModuleWordLex(SDF_ModuleWord arg, char * lex) */

SDF_ModuleWord SDF_setModuleWordLex(SDF_ModuleWord arg, char * lex)
{
  if (SDF_isModuleWordWord(arg)) {
    return (SDF_ModuleWord)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }

  ATabort("ModuleWord has no Lex: %t\n", arg);
  return (SDF_ModuleWord)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ModuleId accessors */

/*{{{  ATbool SDF_isValidModuleId(SDF_ModuleId arg) */

ATbool SDF_isValidModuleId(SDF_ModuleId arg)
{
  if (SDF_isModuleIdWord(arg)) {
    return ATtrue;
  }
  else if (SDF_isModuleIdSlashWord(arg)) {
    return ATtrue;
  }
  else if (SDF_isModuleIdWordSlashWord(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isModuleIdWord(SDF_ModuleId arg) */

ATbool SDF_isModuleIdWord(SDF_ModuleId arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternModuleIdWord, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isModuleIdSlashWord(SDF_ModuleId arg) */

ATbool SDF_isModuleIdSlashWord(SDF_ModuleId arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternModuleIdSlashWord, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isModuleIdWordSlashWord(SDF_ModuleId arg) */

ATbool SDF_isModuleIdWordSlashWord(SDF_ModuleId arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternModuleIdWordSlashWord, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasModuleIdLex(SDF_ModuleId arg) */

ATbool SDF_hasModuleIdLex(SDF_ModuleId arg)
{
  if (SDF_isModuleIdWord(arg)) {
    return ATtrue;
  }
  else if (SDF_isModuleIdSlashWord(arg)) {
    return ATtrue;
  }
  else if (SDF_isModuleIdWordSlashWord(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getModuleIdLex(SDF_ModuleId arg) */

char * SDF_getModuleIdLex(SDF_ModuleId arg)
{
  if (SDF_isModuleIdWord(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (SDF_isModuleIdSlashWord(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (SDF_isModuleIdWordSlashWord(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }

  ATabort("ModuleId has no Lex: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_ModuleId SDF_setModuleIdLex(SDF_ModuleId arg, char * lex) */

SDF_ModuleId SDF_setModuleIdLex(SDF_ModuleId arg, char * lex)
{
  if (SDF_isModuleIdWord(arg)) {
    return (SDF_ModuleId)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }
  else if (SDF_isModuleIdSlashWord(arg)) {
    return (SDF_ModuleId)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }
  else if (SDF_isModuleIdWordSlashWord(arg)) {
    return (SDF_ModuleId)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }

  ATabort("ModuleId has no Lex: %t\n", arg);
  return (SDF_ModuleId)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Definition accessors */

/*{{{  ATbool SDF_isValidDefinition(SDF_Definition arg) */

ATbool SDF_isValidDefinition(SDF_Definition arg)
{
  if (SDF_isDefinitionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isDefinitionDefault(SDF_Definition arg) */

ATbool SDF_isDefinitionDefault(SDF_Definition arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternDefinitionDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasDefinitionList(SDF_Definition arg) */

ATbool SDF_hasDefinitionList(SDF_Definition arg)
{
  if (SDF_isDefinitionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ModuleList SDF_getDefinitionList(SDF_Definition arg) */

SDF_ModuleList SDF_getDefinitionList(SDF_Definition arg)
{
  if (SDF_isDefinitionDefault(arg)) {
    return (SDF_ModuleList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 2);
  }

  ATabort("Definition has no List: %t\n", arg);
  return (SDF_ModuleList)NULL;
}

/*}}}  */
/*{{{  SDF_Definition SDF_setDefinitionList(SDF_Definition arg, SDF_ModuleList list) */

SDF_Definition SDF_setDefinitionList(SDF_Definition arg, SDF_ModuleList list)
{
  if (SDF_isDefinitionDefault(arg)) {
    return (SDF_Definition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)list, 2), 0), 2);
  }

  ATabort("Definition has no List: %t\n", arg);
  return (SDF_Definition)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ModuleList accessors */

/*{{{  ATbool SDF_isValidModuleList(SDF_ModuleList arg) */

ATbool SDF_isValidModuleList(SDF_ModuleList arg)
{
  if (SDF_isModuleListEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isModuleListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isModuleListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isModuleListEmpty(SDF_ModuleList arg) */

ATbool SDF_isModuleListEmpty(SDF_ModuleList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternModuleListEmpty);
}

/*}}}  */
/*{{{  ATbool SDF_isModuleListSingle(SDF_ModuleList arg) */

ATbool SDF_isModuleListSingle(SDF_ModuleList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternModuleListSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isModuleListMany(SDF_ModuleList arg) */

ATbool SDF_isModuleListMany(SDF_ModuleList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternModuleListMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasModuleListHead(SDF_ModuleList arg) */

ATbool SDF_hasModuleListHead(SDF_ModuleList arg)
{
  if (SDF_isModuleListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isModuleListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Module SDF_getModuleListHead(SDF_ModuleList arg) */

SDF_Module SDF_getModuleListHead(SDF_ModuleList arg)
{
  if (SDF_isModuleListSingle(arg)) {
    return (SDF_Module)ATelementAt((ATermList)arg, 0);
  }
  else if (SDF_isModuleListMany(arg)) {
    return (SDF_Module)ATelementAt((ATermList)arg, 0);
  }

  ATabort("ModuleList has no Head: %t\n", arg);
  return (SDF_Module)NULL;
}

/*}}}  */
/*{{{  SDF_ModuleList SDF_setModuleListHead(SDF_ModuleList arg, SDF_Module head) */

SDF_ModuleList SDF_setModuleListHead(SDF_ModuleList arg, SDF_Module head)
{
  if (SDF_isModuleListSingle(arg)) {
    return (SDF_ModuleList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isModuleListMany(arg)) {
    return (SDF_ModuleList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("ModuleList has no Head: %t\n", arg);
  return (SDF_ModuleList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasModuleListWsAfterFirst(SDF_ModuleList arg) */

ATbool SDF_hasModuleListWsAfterFirst(SDF_ModuleList arg)
{
  if (SDF_isModuleListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getModuleListWsAfterFirst(SDF_ModuleList arg) */

char * SDF_getModuleListWsAfterFirst(SDF_ModuleList arg)
{
  if (SDF_isModuleListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0)));
  }

  ATabort("ModuleList has no WsAfterFirst: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_ModuleList SDF_setModuleListWsAfterFirst(SDF_ModuleList arg, char * wsAfterFirst) */

SDF_ModuleList SDF_setModuleListWsAfterFirst(SDF_ModuleList arg, char * wsAfterFirst)
{
  if (SDF_isModuleListMany(arg)) {
    return (SDF_ModuleList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterFirst, 0, ATtrue)), 0), 1);
  }

  ATabort("ModuleList has no WsAfterFirst: %t\n", arg);
  return (SDF_ModuleList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasModuleListTail(SDF_ModuleList arg) */

ATbool SDF_hasModuleListTail(SDF_ModuleList arg)
{
  if (SDF_isModuleListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ModuleList SDF_getModuleListTail(SDF_ModuleList arg) */

SDF_ModuleList SDF_getModuleListTail(SDF_ModuleList arg)
{
  if (SDF_isModuleListMany(arg)) {
    return (SDF_ModuleList)ATgetTail((ATermList)arg, 2);
  }

  ATabort("ModuleList has no Tail: %t\n", arg);
  return (SDF_ModuleList)NULL;
}

/*}}}  */
/*{{{  SDF_ModuleList SDF_setModuleListTail(SDF_ModuleList arg, SDF_ModuleList tail) */

SDF_ModuleList SDF_setModuleListTail(SDF_ModuleList arg, SDF_ModuleList tail)
{
  if (SDF_isModuleListMany(arg)) {
    return (SDF_ModuleList)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("ModuleList has no Tail: %t\n", arg);
  return (SDF_ModuleList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Module accessors */

/*{{{  ATbool SDF_isValidModule(SDF_Module arg) */

ATbool SDF_isValidModule(SDF_Module arg)
{
  if (SDF_isModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isModuleModule(SDF_Module arg) */

ATbool SDF_isModuleModule(SDF_Module arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternModuleModule, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasModuleWsAfterModule(SDF_Module arg) */

ATbool SDF_hasModuleWsAfterModule(SDF_Module arg)
{
  if (SDF_isModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getModuleWsAfterModule(SDF_Module arg) */

char * SDF_getModuleWsAfterModule(SDF_Module arg)
{
  if (SDF_isModuleModule(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Module has no WsAfterModule: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Module SDF_setModuleWsAfterModule(SDF_Module arg, char * wsAfterModule) */

SDF_Module SDF_setModuleWsAfterModule(SDF_Module arg, char * wsAfterModule)
{
  if (SDF_isModuleModule(arg)) {
    return (SDF_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterModule, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Module has no WsAfterModule: %t\n", arg);
  return (SDF_Module)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasModuleModuleName(SDF_Module arg) */

ATbool SDF_hasModuleModuleName(SDF_Module arg)
{
  if (SDF_isModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_getModuleModuleName(SDF_Module arg) */

SDF_ModuleName SDF_getModuleModuleName(SDF_Module arg)
{
  if (SDF_isModuleModule(arg)) {
    return (SDF_ModuleName)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Module has no ModuleName: %t\n", arg);
  return (SDF_ModuleName)NULL;
}

/*}}}  */
/*{{{  SDF_Module SDF_setModuleModuleName(SDF_Module arg, SDF_ModuleName ModuleName) */

SDF_Module SDF_setModuleModuleName(SDF_Module arg, SDF_ModuleName ModuleName)
{
  if (SDF_isModuleModule(arg)) {
    return (SDF_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ModuleName, 2), 2);
  }

  ATabort("Module has no ModuleName: %t\n", arg);
  return (SDF_Module)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasModuleWsAfterModuleName(SDF_Module arg) */

ATbool SDF_hasModuleWsAfterModuleName(SDF_Module arg)
{
  if (SDF_isModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getModuleWsAfterModuleName(SDF_Module arg) */

char * SDF_getModuleWsAfterModuleName(SDF_Module arg)
{
  if (SDF_isModuleModule(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Module has no WsAfterModuleName: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Module SDF_setModuleWsAfterModuleName(SDF_Module arg, char * wsAfterModuleName) */

SDF_Module SDF_setModuleWsAfterModuleName(SDF_Module arg, char * wsAfterModuleName)
{
  if (SDF_isModuleModule(arg)) {
    return (SDF_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterModuleName, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Module has no WsAfterModuleName: %t\n", arg);
  return (SDF_Module)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasModuleList(SDF_Module arg) */

ATbool SDF_hasModuleList(SDF_Module arg)
{
  if (SDF_isModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ImpSectionList SDF_getModuleList(SDF_Module arg) */

SDF_ImpSectionList SDF_getModuleList(SDF_Module arg)
{
  if (SDF_isModuleModule(arg)) {
    return (SDF_ImpSectionList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4), 2);
  }

  ATabort("Module has no List: %t\n", arg);
  return (SDF_ImpSectionList)NULL;
}

/*}}}  */
/*{{{  SDF_Module SDF_setModuleList(SDF_Module arg, SDF_ImpSectionList list) */

SDF_Module SDF_setModuleList(SDF_Module arg, SDF_ImpSectionList list)
{
  if (SDF_isModuleModule(arg)) {
    return (SDF_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4), (ATerm)list, 2), 4), 2);
  }

  ATabort("Module has no List: %t\n", arg);
  return (SDF_Module)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasModuleWsAfterList(SDF_Module arg) */

ATbool SDF_hasModuleWsAfterList(SDF_Module arg)
{
  if (SDF_isModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getModuleWsAfterList(SDF_Module arg) */

char * SDF_getModuleWsAfterList(SDF_Module arg)
{
  if (SDF_isModuleModule(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0)));
  }

  ATabort("Module has no WsAfterList: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Module SDF_setModuleWsAfterList(SDF_Module arg, char * wsAfterList) */

SDF_Module SDF_setModuleWsAfterList(SDF_Module arg, char * wsAfterList)
{
  if (SDF_isModuleModule(arg)) {
    return (SDF_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterList, 0, ATtrue)), 0), 5), 2);
  }

  ATabort("Module has no WsAfterList: %t\n", arg);
  return (SDF_Module)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasModuleSections(SDF_Module arg) */

ATbool SDF_hasModuleSections(SDF_Module arg)
{
  if (SDF_isModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Sections SDF_getModuleSections(SDF_Module arg) */

SDF_Sections SDF_getModuleSections(SDF_Module arg)
{
  if (SDF_isModuleModule(arg)) {
    return (SDF_Sections)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 6);
  }

  ATabort("Module has no Sections: %t\n", arg);
  return (SDF_Sections)NULL;
}

/*}}}  */
/*{{{  SDF_Module SDF_setModuleSections(SDF_Module arg, SDF_Sections Sections) */

SDF_Module SDF_setModuleSections(SDF_Module arg, SDF_Sections Sections)
{
  if (SDF_isModuleModule(arg)) {
    return (SDF_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Sections, 6), 2);
  }

  ATabort("Module has no Sections: %t\n", arg);
  return (SDF_Module)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ImpSectionList accessors */

/*{{{  ATbool SDF_isValidImpSectionList(SDF_ImpSectionList arg) */

ATbool SDF_isValidImpSectionList(SDF_ImpSectionList arg)
{
  if (SDF_isImpSectionListEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isImpSectionListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isImpSectionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isImpSectionListEmpty(SDF_ImpSectionList arg) */

ATbool SDF_isImpSectionListEmpty(SDF_ImpSectionList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternImpSectionListEmpty);
}

/*}}}  */
/*{{{  ATbool SDF_isImpSectionListSingle(SDF_ImpSectionList arg) */

ATbool SDF_isImpSectionListSingle(SDF_ImpSectionList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternImpSectionListSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isImpSectionListMany(SDF_ImpSectionList arg) */

ATbool SDF_isImpSectionListMany(SDF_ImpSectionList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternImpSectionListMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasImpSectionListHead(SDF_ImpSectionList arg) */

ATbool SDF_hasImpSectionListHead(SDF_ImpSectionList arg)
{
  if (SDF_isImpSectionListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isImpSectionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ImpSection SDF_getImpSectionListHead(SDF_ImpSectionList arg) */

SDF_ImpSection SDF_getImpSectionListHead(SDF_ImpSectionList arg)
{
  if (SDF_isImpSectionListSingle(arg)) {
    return (SDF_ImpSection)ATelementAt((ATermList)arg, 0);
  }
  else if (SDF_isImpSectionListMany(arg)) {
    return (SDF_ImpSection)ATelementAt((ATermList)arg, 0);
  }

  ATabort("ImpSectionList has no Head: %t\n", arg);
  return (SDF_ImpSection)NULL;
}

/*}}}  */
/*{{{  SDF_ImpSectionList SDF_setImpSectionListHead(SDF_ImpSectionList arg, SDF_ImpSection head) */

SDF_ImpSectionList SDF_setImpSectionListHead(SDF_ImpSectionList arg, SDF_ImpSection head)
{
  if (SDF_isImpSectionListSingle(arg)) {
    return (SDF_ImpSectionList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isImpSectionListMany(arg)) {
    return (SDF_ImpSectionList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("ImpSectionList has no Head: %t\n", arg);
  return (SDF_ImpSectionList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasImpSectionListWsAfterFirst(SDF_ImpSectionList arg) */

ATbool SDF_hasImpSectionListWsAfterFirst(SDF_ImpSectionList arg)
{
  if (SDF_isImpSectionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getImpSectionListWsAfterFirst(SDF_ImpSectionList arg) */

char * SDF_getImpSectionListWsAfterFirst(SDF_ImpSectionList arg)
{
  if (SDF_isImpSectionListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0)));
  }

  ATabort("ImpSectionList has no WsAfterFirst: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_ImpSectionList SDF_setImpSectionListWsAfterFirst(SDF_ImpSectionList arg, char * wsAfterFirst) */

SDF_ImpSectionList SDF_setImpSectionListWsAfterFirst(SDF_ImpSectionList arg, char * wsAfterFirst)
{
  if (SDF_isImpSectionListMany(arg)) {
    return (SDF_ImpSectionList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterFirst, 0, ATtrue)), 0), 1);
  }

  ATabort("ImpSectionList has no WsAfterFirst: %t\n", arg);
  return (SDF_ImpSectionList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasImpSectionListTail(SDF_ImpSectionList arg) */

ATbool SDF_hasImpSectionListTail(SDF_ImpSectionList arg)
{
  if (SDF_isImpSectionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ImpSectionList SDF_getImpSectionListTail(SDF_ImpSectionList arg) */

SDF_ImpSectionList SDF_getImpSectionListTail(SDF_ImpSectionList arg)
{
  if (SDF_isImpSectionListMany(arg)) {
    return (SDF_ImpSectionList)ATgetTail((ATermList)arg, 2);
  }

  ATabort("ImpSectionList has no Tail: %t\n", arg);
  return (SDF_ImpSectionList)NULL;
}

/*}}}  */
/*{{{  SDF_ImpSectionList SDF_setImpSectionListTail(SDF_ImpSectionList arg, SDF_ImpSectionList tail) */

SDF_ImpSectionList SDF_setImpSectionListTail(SDF_ImpSectionList arg, SDF_ImpSectionList tail)
{
  if (SDF_isImpSectionListMany(arg)) {
    return (SDF_ImpSectionList)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("ImpSectionList has no Tail: %t\n", arg);
  return (SDF_ImpSectionList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Section accessors */

/*{{{  ATbool SDF_isValidSection(SDF_Section arg) */

ATbool SDF_isValidSection(SDF_Section arg)
{
  if (SDF_isSectionExports(arg)) {
    return ATtrue;
  }
  else if (SDF_isSectionHiddens(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isSectionExports(SDF_Section arg) */

ATbool SDF_isSectionExports(SDF_Section arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSectionExports, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSectionHiddens(SDF_Section arg) */

ATbool SDF_isSectionHiddens(SDF_Section arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSectionHiddens, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasSectionWsAfterExports(SDF_Section arg) */

ATbool SDF_hasSectionWsAfterExports(SDF_Section arg)
{
  if (SDF_isSectionExports(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSectionWsAfterExports(SDF_Section arg) */

char * SDF_getSectionWsAfterExports(SDF_Section arg)
{
  if (SDF_isSectionExports(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Section has no WsAfterExports: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Section SDF_setSectionWsAfterExports(SDF_Section arg, char * wsAfterExports) */

SDF_Section SDF_setSectionWsAfterExports(SDF_Section arg, char * wsAfterExports)
{
  if (SDF_isSectionExports(arg)) {
    return (SDF_Section)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterExports, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Section has no WsAfterExports: %t\n", arg);
  return (SDF_Section)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSectionGrammar(SDF_Section arg) */

ATbool SDF_hasSectionGrammar(SDF_Section arg)
{
  if (SDF_isSectionExports(arg)) {
    return ATtrue;
  }
  else if (SDF_isSectionHiddens(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_getSectionGrammar(SDF_Section arg) */

SDF_Grammar SDF_getSectionGrammar(SDF_Section arg)
{
  if (SDF_isSectionExports(arg)) {
    return (SDF_Grammar)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDF_isSectionHiddens(arg)) {
    return (SDF_Grammar)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Section has no Grammar: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  SDF_Section SDF_setSectionGrammar(SDF_Section arg, SDF_Grammar Grammar) */

SDF_Section SDF_setSectionGrammar(SDF_Section arg, SDF_Grammar Grammar)
{
  if (SDF_isSectionExports(arg)) {
    return (SDF_Section)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Grammar, 2), 2);
  }
  else if (SDF_isSectionHiddens(arg)) {
    return (SDF_Section)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Grammar, 2), 2);
  }

  ATabort("Section has no Grammar: %t\n", arg);
  return (SDF_Section)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSectionWsAfterHiddens(SDF_Section arg) */

ATbool SDF_hasSectionWsAfterHiddens(SDF_Section arg)
{
  if (SDF_isSectionHiddens(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSectionWsAfterHiddens(SDF_Section arg) */

char * SDF_getSectionWsAfterHiddens(SDF_Section arg)
{
  if (SDF_isSectionHiddens(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Section has no WsAfterHiddens: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Section SDF_setSectionWsAfterHiddens(SDF_Section arg, char * wsAfterHiddens) */

SDF_Section SDF_setSectionWsAfterHiddens(SDF_Section arg, char * wsAfterHiddens)
{
  if (SDF_isSectionHiddens(arg)) {
    return (SDF_Section)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterHiddens, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Section has no WsAfterHiddens: %t\n", arg);
  return (SDF_Section)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Sections accessors */

/*{{{  ATbool SDF_isValidSections(SDF_Sections arg) */

ATbool SDF_isValidSections(SDF_Sections arg)
{
  if (SDF_isSectionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isSectionsDefault(SDF_Sections arg) */

ATbool SDF_isSectionsDefault(SDF_Sections arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSectionsDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasSectionsList(SDF_Sections arg) */

ATbool SDF_hasSectionsList(SDF_Sections arg)
{
  if (SDF_isSectionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_SectionList SDF_getSectionsList(SDF_Sections arg) */

SDF_SectionList SDF_getSectionsList(SDF_Sections arg)
{
  if (SDF_isSectionsDefault(arg)) {
    return (SDF_SectionList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 2);
  }

  ATabort("Sections has no List: %t\n", arg);
  return (SDF_SectionList)NULL;
}

/*}}}  */
/*{{{  SDF_Sections SDF_setSectionsList(SDF_Sections arg, SDF_SectionList list) */

SDF_Sections SDF_setSectionsList(SDF_Sections arg, SDF_SectionList list)
{
  if (SDF_isSectionsDefault(arg)) {
    return (SDF_Sections)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)list, 2), 0), 2);
  }

  ATabort("Sections has no List: %t\n", arg);
  return (SDF_Sections)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_SectionList accessors */

/*{{{  ATbool SDF_isValidSectionList(SDF_SectionList arg) */

ATbool SDF_isValidSectionList(SDF_SectionList arg)
{
  if (SDF_isSectionListEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isSectionListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isSectionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isSectionListEmpty(SDF_SectionList arg) */

ATbool SDF_isSectionListEmpty(SDF_SectionList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSectionListEmpty);
}

/*}}}  */
/*{{{  ATbool SDF_isSectionListSingle(SDF_SectionList arg) */

ATbool SDF_isSectionListSingle(SDF_SectionList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSectionListSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSectionListMany(SDF_SectionList arg) */

ATbool SDF_isSectionListMany(SDF_SectionList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSectionListMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasSectionListHead(SDF_SectionList arg) */

ATbool SDF_hasSectionListHead(SDF_SectionList arg)
{
  if (SDF_isSectionListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isSectionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Section SDF_getSectionListHead(SDF_SectionList arg) */

SDF_Section SDF_getSectionListHead(SDF_SectionList arg)
{
  if (SDF_isSectionListSingle(arg)) {
    return (SDF_Section)ATelementAt((ATermList)arg, 0);
  }
  else if (SDF_isSectionListMany(arg)) {
    return (SDF_Section)ATelementAt((ATermList)arg, 0);
  }

  ATabort("SectionList has no Head: %t\n", arg);
  return (SDF_Section)NULL;
}

/*}}}  */
/*{{{  SDF_SectionList SDF_setSectionListHead(SDF_SectionList arg, SDF_Section head) */

SDF_SectionList SDF_setSectionListHead(SDF_SectionList arg, SDF_Section head)
{
  if (SDF_isSectionListSingle(arg)) {
    return (SDF_SectionList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isSectionListMany(arg)) {
    return (SDF_SectionList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("SectionList has no Head: %t\n", arg);
  return (SDF_SectionList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSectionListWsAfterFirst(SDF_SectionList arg) */

ATbool SDF_hasSectionListWsAfterFirst(SDF_SectionList arg)
{
  if (SDF_isSectionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSectionListWsAfterFirst(SDF_SectionList arg) */

char * SDF_getSectionListWsAfterFirst(SDF_SectionList arg)
{
  if (SDF_isSectionListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0)));
  }

  ATabort("SectionList has no WsAfterFirst: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_SectionList SDF_setSectionListWsAfterFirst(SDF_SectionList arg, char * wsAfterFirst) */

SDF_SectionList SDF_setSectionListWsAfterFirst(SDF_SectionList arg, char * wsAfterFirst)
{
  if (SDF_isSectionListMany(arg)) {
    return (SDF_SectionList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterFirst, 0, ATtrue)), 0), 1);
  }

  ATabort("SectionList has no WsAfterFirst: %t\n", arg);
  return (SDF_SectionList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSectionListTail(SDF_SectionList arg) */

ATbool SDF_hasSectionListTail(SDF_SectionList arg)
{
  if (SDF_isSectionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_SectionList SDF_getSectionListTail(SDF_SectionList arg) */

SDF_SectionList SDF_getSectionListTail(SDF_SectionList arg)
{
  if (SDF_isSectionListMany(arg)) {
    return (SDF_SectionList)ATgetTail((ATermList)arg, 2);
  }

  ATabort("SectionList has no Tail: %t\n", arg);
  return (SDF_SectionList)NULL;
}

/*}}}  */
/*{{{  SDF_SectionList SDF_setSectionListTail(SDF_SectionList arg, SDF_SectionList tail) */

SDF_SectionList SDF_setSectionListTail(SDF_SectionList arg, SDF_SectionList tail)
{
  if (SDF_isSectionListMany(arg)) {
    return (SDF_SectionList)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("SectionList has no Tail: %t\n", arg);
  return (SDF_SectionList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ModuleName accessors */

/*{{{  ATbool SDF_isValidModuleName(SDF_ModuleName arg) */

ATbool SDF_isValidModuleName(SDF_ModuleName arg)
{
  if (SDF_isModuleNameUnparameterized(arg)) {
    return ATtrue;
  }
  else if (SDF_isModuleNameParameterized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isModuleNameUnparameterized(SDF_ModuleName arg) */

ATbool SDF_isModuleNameUnparameterized(SDF_ModuleName arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternModuleNameUnparameterized, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isModuleNameParameterized(SDF_ModuleName arg) */

ATbool SDF_isModuleNameParameterized(SDF_ModuleName arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternModuleNameParameterized, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasModuleNameModuleId(SDF_ModuleName arg) */

ATbool SDF_hasModuleNameModuleId(SDF_ModuleName arg)
{
  if (SDF_isModuleNameUnparameterized(arg)) {
    return ATtrue;
  }
  else if (SDF_isModuleNameParameterized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ModuleId SDF_getModuleNameModuleId(SDF_ModuleName arg) */

SDF_ModuleId SDF_getModuleNameModuleId(SDF_ModuleName arg)
{
  if (SDF_isModuleNameUnparameterized(arg)) {
    return (SDF_ModuleId)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDF_isModuleNameParameterized(arg)) {
    return (SDF_ModuleId)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("ModuleName has no ModuleId: %t\n", arg);
  return (SDF_ModuleId)NULL;
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_setModuleNameModuleId(SDF_ModuleName arg, SDF_ModuleId ModuleId) */

SDF_ModuleName SDF_setModuleNameModuleId(SDF_ModuleName arg, SDF_ModuleId ModuleId)
{
  if (SDF_isModuleNameUnparameterized(arg)) {
    return (SDF_ModuleName)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ModuleId, 0), 2);
  }
  else if (SDF_isModuleNameParameterized(arg)) {
    return (SDF_ModuleName)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ModuleId, 0), 2);
  }

  ATabort("ModuleName has no ModuleId: %t\n", arg);
  return (SDF_ModuleName)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasModuleNameWsAfterModuleId(SDF_ModuleName arg) */

ATbool SDF_hasModuleNameWsAfterModuleId(SDF_ModuleName arg)
{
  if (SDF_isModuleNameParameterized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getModuleNameWsAfterModuleId(SDF_ModuleName arg) */

char * SDF_getModuleNameWsAfterModuleId(SDF_ModuleName arg)
{
  if (SDF_isModuleNameParameterized(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("ModuleName has no WsAfterModuleId: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_setModuleNameWsAfterModuleId(SDF_ModuleName arg, char * wsAfterModuleId) */

SDF_ModuleName SDF_setModuleNameWsAfterModuleId(SDF_ModuleName arg, char * wsAfterModuleId)
{
  if (SDF_isModuleNameParameterized(arg)) {
    return (SDF_ModuleName)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterModuleId, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("ModuleName has no WsAfterModuleId: %t\n", arg);
  return (SDF_ModuleName)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasModuleNameWsAfterBracketOpen(SDF_ModuleName arg) */

ATbool SDF_hasModuleNameWsAfterBracketOpen(SDF_ModuleName arg)
{
  if (SDF_isModuleNameParameterized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getModuleNameWsAfterBracketOpen(SDF_ModuleName arg) */

char * SDF_getModuleNameWsAfterBracketOpen(SDF_ModuleName arg)
{
  if (SDF_isModuleNameParameterized(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("ModuleName has no WsAfterBracketOpen: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_setModuleNameWsAfterBracketOpen(SDF_ModuleName arg, char * wsAfterBracketOpen) */

SDF_ModuleName SDF_setModuleNameWsAfterBracketOpen(SDF_ModuleName arg, char * wsAfterBracketOpen)
{
  if (SDF_isModuleNameParameterized(arg)) {
    return (SDF_ModuleName)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterBracketOpen, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("ModuleName has no WsAfterBracketOpen: %t\n", arg);
  return (SDF_ModuleName)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasModuleNameParams(SDF_ModuleName arg) */

ATbool SDF_hasModuleNameParams(SDF_ModuleName arg)
{
  if (SDF_isModuleNameParameterized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbols SDF_getModuleNameParams(SDF_ModuleName arg) */

SDF_Symbols SDF_getModuleNameParams(SDF_ModuleName arg)
{
  if (SDF_isModuleNameParameterized(arg)) {
    return (SDF_Symbols)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("ModuleName has no Params: %t\n", arg);
  return (SDF_Symbols)NULL;
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_setModuleNameParams(SDF_ModuleName arg, SDF_Symbols params) */

SDF_ModuleName SDF_setModuleNameParams(SDF_ModuleName arg, SDF_Symbols params)
{
  if (SDF_isModuleNameParameterized(arg)) {
    return (SDF_ModuleName)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)params, 4), 2);
  }

  ATabort("ModuleName has no Params: %t\n", arg);
  return (SDF_ModuleName)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasModuleNameWsAfterParams(SDF_ModuleName arg) */

ATbool SDF_hasModuleNameWsAfterParams(SDF_ModuleName arg)
{
  if (SDF_isModuleNameParameterized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getModuleNameWsAfterParams(SDF_ModuleName arg) */

char * SDF_getModuleNameWsAfterParams(SDF_ModuleName arg)
{
  if (SDF_isModuleNameParameterized(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0)));
  }

  ATabort("ModuleName has no WsAfterParams: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_setModuleNameWsAfterParams(SDF_ModuleName arg, char * wsAfterParams) */

SDF_ModuleName SDF_setModuleNameWsAfterParams(SDF_ModuleName arg, char * wsAfterParams)
{
  if (SDF_isModuleNameParameterized(arg)) {
    return (SDF_ModuleName)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterParams, 0, ATtrue)), 0), 5), 2);
  }

  ATabort("ModuleName has no WsAfterParams: %t\n", arg);
  return (SDF_ModuleName)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Attribute accessors */

/*{{{  ATbool SDF_isValidAttribute(SDF_Attribute arg) */

ATbool SDF_isValidAttribute(SDF_Attribute arg)
{
  if (SDF_isAttributeId(arg)) {
    return ATtrue;
  }
  else if (SDF_isAttributeBracket(arg)) {
    return ATtrue;
  }
  else if (SDF_isAttributeAtr(arg)) {
    return ATtrue;
  }
  else if (SDF_isAttributeCons(arg)) {
    return ATtrue;
  }
  else if (SDF_isAttributeConstructor(arg)) {
    return ATtrue;
  }
  else if (SDF_isAttributeMemo(arg)) {
    return ATtrue;
  }
  else if (SDF_isAttributeTraverse(arg)) {
    return ATtrue;
  }
  else if (SDF_isAttributeReject(arg)) {
    return ATtrue;
  }
  else if (SDF_isAttributePrefer(arg)) {
    return ATtrue;
  }
  else if (SDF_isAttributeAvoid(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isAttributeId(SDF_Attribute arg) */

ATbool SDF_isAttributeId(SDF_Attribute arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAttributeId, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isAttributeBracket(SDF_Attribute arg) */

ATbool SDF_isAttributeBracket(SDF_Attribute arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAttributeBracket);
}

/*}}}  */
/*{{{  ATbool SDF_isAttributeAtr(SDF_Attribute arg) */

ATbool SDF_isAttributeAtr(SDF_Attribute arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAttributeAtr, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isAttributeCons(SDF_Attribute arg) */

ATbool SDF_isAttributeCons(SDF_Attribute arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAttributeCons, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isAttributeConstructor(SDF_Attribute arg) */

ATbool SDF_isAttributeConstructor(SDF_Attribute arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAttributeConstructor);
}

/*}}}  */
/*{{{  ATbool SDF_isAttributeMemo(SDF_Attribute arg) */

ATbool SDF_isAttributeMemo(SDF_Attribute arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAttributeMemo);
}

/*}}}  */
/*{{{  ATbool SDF_isAttributeTraverse(SDF_Attribute arg) */

ATbool SDF_isAttributeTraverse(SDF_Attribute arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAttributeTraverse);
}

/*}}}  */
/*{{{  ATbool SDF_isAttributeReject(SDF_Attribute arg) */

ATbool SDF_isAttributeReject(SDF_Attribute arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAttributeReject);
}

/*}}}  */
/*{{{  ATbool SDF_isAttributePrefer(SDF_Attribute arg) */

ATbool SDF_isAttributePrefer(SDF_Attribute arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAttributePrefer);
}

/*}}}  */
/*{{{  ATbool SDF_isAttributeAvoid(SDF_Attribute arg) */

ATbool SDF_isAttributeAvoid(SDF_Attribute arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAttributeAvoid);
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributeWsAfterId(SDF_Attribute arg) */

ATbool SDF_hasAttributeWsAfterId(SDF_Attribute arg)
{
  if (SDF_isAttributeId(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getAttributeWsAfterId(SDF_Attribute arg) */

char * SDF_getAttributeWsAfterId(SDF_Attribute arg)
{
  if (SDF_isAttributeId(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Attribute has no WsAfterId: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Attribute SDF_setAttributeWsAfterId(SDF_Attribute arg, char * wsAfterId) */

SDF_Attribute SDF_setAttributeWsAfterId(SDF_Attribute arg, char * wsAfterId)
{
  if (SDF_isAttributeId(arg)) {
    return (SDF_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterId, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Attribute has no WsAfterId: %t\n", arg);
  return (SDF_Attribute)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributeWsAfterParenOpen(SDF_Attribute arg) */

ATbool SDF_hasAttributeWsAfterParenOpen(SDF_Attribute arg)
{
  if (SDF_isAttributeId(arg)) {
    return ATtrue;
  }
  else if (SDF_isAttributeCons(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getAttributeWsAfterParenOpen(SDF_Attribute arg) */

char * SDF_getAttributeWsAfterParenOpen(SDF_Attribute arg)
{
  if (SDF_isAttributeId(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }
  else if (SDF_isAttributeCons(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Attribute has no WsAfterParenOpen: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Attribute SDF_setAttributeWsAfterParenOpen(SDF_Attribute arg, char * wsAfterParenOpen) */

SDF_Attribute SDF_setAttributeWsAfterParenOpen(SDF_Attribute arg, char * wsAfterParenOpen)
{
  if (SDF_isAttributeId(arg)) {
    return (SDF_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterParenOpen, 0, ATtrue)), 0), 3), 2);
  }
  else if (SDF_isAttributeCons(arg)) {
    return (SDF_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterParenOpen, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Attribute has no WsAfterParenOpen: %t\n", arg);
  return (SDF_Attribute)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributeModuleName(SDF_Attribute arg) */

ATbool SDF_hasAttributeModuleName(SDF_Attribute arg)
{
  if (SDF_isAttributeId(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_getAttributeModuleName(SDF_Attribute arg) */

SDF_ModuleName SDF_getAttributeModuleName(SDF_Attribute arg)
{
  if (SDF_isAttributeId(arg)) {
    return (SDF_ModuleName)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Attribute has no ModuleName: %t\n", arg);
  return (SDF_ModuleName)NULL;
}

/*}}}  */
/*{{{  SDF_Attribute SDF_setAttributeModuleName(SDF_Attribute arg, SDF_ModuleName ModuleName) */

SDF_Attribute SDF_setAttributeModuleName(SDF_Attribute arg, SDF_ModuleName ModuleName)
{
  if (SDF_isAttributeId(arg)) {
    return (SDF_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ModuleName, 4), 2);
  }

  ATabort("Attribute has no ModuleName: %t\n", arg);
  return (SDF_Attribute)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributeWsAfterModuleName(SDF_Attribute arg) */

ATbool SDF_hasAttributeWsAfterModuleName(SDF_Attribute arg)
{
  if (SDF_isAttributeId(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getAttributeWsAfterModuleName(SDF_Attribute arg) */

char * SDF_getAttributeWsAfterModuleName(SDF_Attribute arg)
{
  if (SDF_isAttributeId(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0)));
  }

  ATabort("Attribute has no WsAfterModuleName: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Attribute SDF_setAttributeWsAfterModuleName(SDF_Attribute arg, char * wsAfterModuleName) */

SDF_Attribute SDF_setAttributeWsAfterModuleName(SDF_Attribute arg, char * wsAfterModuleName)
{
  if (SDF_isAttributeId(arg)) {
    return (SDF_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterModuleName, 0, ATtrue)), 0), 5), 2);
  }

  ATabort("Attribute has no WsAfterModuleName: %t\n", arg);
  return (SDF_Attribute)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributeAssociativity(SDF_Attribute arg) */

ATbool SDF_hasAttributeAssociativity(SDF_Attribute arg)
{
  if (SDF_isAttributeAtr(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Associativity SDF_getAttributeAssociativity(SDF_Attribute arg) */

SDF_Associativity SDF_getAttributeAssociativity(SDF_Attribute arg)
{
  if (SDF_isAttributeAtr(arg)) {
    return (SDF_Associativity)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Attribute has no Associativity: %t\n", arg);
  return (SDF_Associativity)NULL;
}

/*}}}  */
/*{{{  SDF_Attribute SDF_setAttributeAssociativity(SDF_Attribute arg, SDF_Associativity Associativity) */

SDF_Attribute SDF_setAttributeAssociativity(SDF_Attribute arg, SDF_Associativity Associativity)
{
  if (SDF_isAttributeAtr(arg)) {
    return (SDF_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Associativity, 0), 2);
  }

  ATabort("Attribute has no Associativity: %t\n", arg);
  return (SDF_Attribute)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributeWsAfterCons(SDF_Attribute arg) */

ATbool SDF_hasAttributeWsAfterCons(SDF_Attribute arg)
{
  if (SDF_isAttributeCons(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getAttributeWsAfterCons(SDF_Attribute arg) */

char * SDF_getAttributeWsAfterCons(SDF_Attribute arg)
{
  if (SDF_isAttributeCons(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Attribute has no WsAfterCons: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Attribute SDF_setAttributeWsAfterCons(SDF_Attribute arg, char * wsAfterCons) */

SDF_Attribute SDF_setAttributeWsAfterCons(SDF_Attribute arg, char * wsAfterCons)
{
  if (SDF_isAttributeCons(arg)) {
    return (SDF_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterCons, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Attribute has no WsAfterCons: %t\n", arg);
  return (SDF_Attribute)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributeTerm(SDF_Attribute arg) */

ATbool SDF_hasAttributeTerm(SDF_Attribute arg)
{
  if (SDF_isAttributeCons(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_getAttributeTerm(SDF_Attribute arg) */

SDF_ATerm SDF_getAttributeTerm(SDF_Attribute arg)
{
  if (SDF_isAttributeCons(arg)) {
    return (SDF_ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Attribute has no Term: %t\n", arg);
  return (SDF_ATerm)NULL;
}

/*}}}  */
/*{{{  SDF_Attribute SDF_setAttributeTerm(SDF_Attribute arg, SDF_ATerm term) */

SDF_Attribute SDF_setAttributeTerm(SDF_Attribute arg, SDF_ATerm term)
{
  if (SDF_isAttributeCons(arg)) {
    return (SDF_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)term, 4), 2);
  }

  ATabort("Attribute has no Term: %t\n", arg);
  return (SDF_Attribute)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributeWsAfterTerm(SDF_Attribute arg) */

ATbool SDF_hasAttributeWsAfterTerm(SDF_Attribute arg)
{
  if (SDF_isAttributeCons(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getAttributeWsAfterTerm(SDF_Attribute arg) */

char * SDF_getAttributeWsAfterTerm(SDF_Attribute arg)
{
  if (SDF_isAttributeCons(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0)));
  }

  ATabort("Attribute has no WsAfterTerm: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Attribute SDF_setAttributeWsAfterTerm(SDF_Attribute arg, char * wsAfterTerm) */

SDF_Attribute SDF_setAttributeWsAfterTerm(SDF_Attribute arg, char * wsAfterTerm)
{
  if (SDF_isAttributeCons(arg)) {
    return (SDF_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterTerm, 0, ATtrue)), 0), 5), 2);
  }

  ATabort("Attribute has no WsAfterTerm: %t\n", arg);
  return (SDF_Attribute)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ImpSection accessors */

/*{{{  ATbool SDF_isValidImpSection(SDF_ImpSection arg) */

ATbool SDF_isValidImpSection(SDF_ImpSection arg)
{
  if (SDF_isImpSectionImports(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isImpSectionImports(SDF_ImpSection arg) */

ATbool SDF_isImpSectionImports(SDF_ImpSection arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternImpSectionImports, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasImpSectionWsAfterImports(SDF_ImpSection arg) */

ATbool SDF_hasImpSectionWsAfterImports(SDF_ImpSection arg)
{
  if (SDF_isImpSectionImports(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getImpSectionWsAfterImports(SDF_ImpSection arg) */

char * SDF_getImpSectionWsAfterImports(SDF_ImpSection arg)
{
  if (SDF_isImpSectionImports(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("ImpSection has no WsAfterImports: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_ImpSection SDF_setImpSectionWsAfterImports(SDF_ImpSection arg, char * wsAfterImports) */

SDF_ImpSection SDF_setImpSectionWsAfterImports(SDF_ImpSection arg, char * wsAfterImports)
{
  if (SDF_isImpSectionImports(arg)) {
    return (SDF_ImpSection)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterImports, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("ImpSection has no WsAfterImports: %t\n", arg);
  return (SDF_ImpSection)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasImpSectionList(SDF_ImpSection arg) */

ATbool SDF_hasImpSectionList(SDF_ImpSection arg)
{
  if (SDF_isImpSectionImports(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Imports SDF_getImpSectionList(SDF_ImpSection arg) */

SDF_Imports SDF_getImpSectionList(SDF_ImpSection arg)
{
  if (SDF_isImpSectionImports(arg)) {
    return (SDF_Imports)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("ImpSection has no List: %t\n", arg);
  return (SDF_Imports)NULL;
}

/*}}}  */
/*{{{  SDF_ImpSection SDF_setImpSectionList(SDF_ImpSection arg, SDF_Imports list) */

SDF_ImpSection SDF_setImpSectionList(SDF_ImpSection arg, SDF_Imports list)
{
  if (SDF_isImpSectionImports(arg)) {
    return (SDF_ImpSection)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)list, 2), 2);
  }

  ATabort("ImpSection has no List: %t\n", arg);
  return (SDF_ImpSection)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Imports accessors */

/*{{{  ATbool SDF_isValidImports(SDF_Imports arg) */

ATbool SDF_isValidImports(SDF_Imports arg)
{
  if (SDF_isImportsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isImportsDefault(SDF_Imports arg) */

ATbool SDF_isImportsDefault(SDF_Imports arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternImportsDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasImportsList(SDF_Imports arg) */

ATbool SDF_hasImportsList(SDF_Imports arg)
{
  if (SDF_isImportsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ImportList SDF_getImportsList(SDF_Imports arg) */

SDF_ImportList SDF_getImportsList(SDF_Imports arg)
{
  if (SDF_isImportsDefault(arg)) {
    return (SDF_ImportList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 2);
  }

  ATabort("Imports has no List: %t\n", arg);
  return (SDF_ImportList)NULL;
}

/*}}}  */
/*{{{  SDF_Imports SDF_setImportsList(SDF_Imports arg, SDF_ImportList list) */

SDF_Imports SDF_setImportsList(SDF_Imports arg, SDF_ImportList list)
{
  if (SDF_isImportsDefault(arg)) {
    return (SDF_Imports)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)list, 2), 0), 2);
  }

  ATabort("Imports has no List: %t\n", arg);
  return (SDF_Imports)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ImportList accessors */

/*{{{  ATbool SDF_isValidImportList(SDF_ImportList arg) */

ATbool SDF_isValidImportList(SDF_ImportList arg)
{
  if (SDF_isImportListEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isImportListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isImportListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isImportListEmpty(SDF_ImportList arg) */

ATbool SDF_isImportListEmpty(SDF_ImportList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternImportListEmpty);
}

/*}}}  */
/*{{{  ATbool SDF_isImportListSingle(SDF_ImportList arg) */

ATbool SDF_isImportListSingle(SDF_ImportList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternImportListSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isImportListMany(SDF_ImportList arg) */

ATbool SDF_isImportListMany(SDF_ImportList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternImportListMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasImportListHead(SDF_ImportList arg) */

ATbool SDF_hasImportListHead(SDF_ImportList arg)
{
  if (SDF_isImportListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isImportListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Import SDF_getImportListHead(SDF_ImportList arg) */

SDF_Import SDF_getImportListHead(SDF_ImportList arg)
{
  if (SDF_isImportListSingle(arg)) {
    return (SDF_Import)ATelementAt((ATermList)arg, 0);
  }
  else if (SDF_isImportListMany(arg)) {
    return (SDF_Import)ATelementAt((ATermList)arg, 0);
  }

  ATabort("ImportList has no Head: %t\n", arg);
  return (SDF_Import)NULL;
}

/*}}}  */
/*{{{  SDF_ImportList SDF_setImportListHead(SDF_ImportList arg, SDF_Import head) */

SDF_ImportList SDF_setImportListHead(SDF_ImportList arg, SDF_Import head)
{
  if (SDF_isImportListSingle(arg)) {
    return (SDF_ImportList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isImportListMany(arg)) {
    return (SDF_ImportList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("ImportList has no Head: %t\n", arg);
  return (SDF_ImportList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasImportListWsAfterFirst(SDF_ImportList arg) */

ATbool SDF_hasImportListWsAfterFirst(SDF_ImportList arg)
{
  if (SDF_isImportListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getImportListWsAfterFirst(SDF_ImportList arg) */

char * SDF_getImportListWsAfterFirst(SDF_ImportList arg)
{
  if (SDF_isImportListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0)));
  }

  ATabort("ImportList has no WsAfterFirst: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_ImportList SDF_setImportListWsAfterFirst(SDF_ImportList arg, char * wsAfterFirst) */

SDF_ImportList SDF_setImportListWsAfterFirst(SDF_ImportList arg, char * wsAfterFirst)
{
  if (SDF_isImportListMany(arg)) {
    return (SDF_ImportList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterFirst, 0, ATtrue)), 0), 1);
  }

  ATabort("ImportList has no WsAfterFirst: %t\n", arg);
  return (SDF_ImportList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasImportListTail(SDF_ImportList arg) */

ATbool SDF_hasImportListTail(SDF_ImportList arg)
{
  if (SDF_isImportListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ImportList SDF_getImportListTail(SDF_ImportList arg) */

SDF_ImportList SDF_getImportListTail(SDF_ImportList arg)
{
  if (SDF_isImportListMany(arg)) {
    return (SDF_ImportList)ATgetTail((ATermList)arg, 2);
  }

  ATabort("ImportList has no Tail: %t\n", arg);
  return (SDF_ImportList)NULL;
}

/*}}}  */
/*{{{  SDF_ImportList SDF_setImportListTail(SDF_ImportList arg, SDF_ImportList tail) */

SDF_ImportList SDF_setImportListTail(SDF_ImportList arg, SDF_ImportList tail)
{
  if (SDF_isImportListMany(arg)) {
    return (SDF_ImportList)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("ImportList has no Tail: %t\n", arg);
  return (SDF_ImportList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Import accessors */

/*{{{  ATbool SDF_isValidImport(SDF_Import arg) */

ATbool SDF_isValidImport(SDF_Import arg)
{
  if (SDF_isImportModule(arg)) {
    return ATtrue;
  }
  else if (SDF_isImportRenamedModule(arg)) {
    return ATtrue;
  }
  else if (SDF_isImportBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isImportModule(SDF_Import arg) */

ATbool SDF_isImportModule(SDF_Import arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternImportModule, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isImportRenamedModule(SDF_Import arg) */

ATbool SDF_isImportRenamedModule(SDF_Import arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternImportRenamedModule, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isImportBracket(SDF_Import arg) */

ATbool SDF_isImportBracket(SDF_Import arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternImportBracket, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasImportModuleName(SDF_Import arg) */

ATbool SDF_hasImportModuleName(SDF_Import arg)
{
  if (SDF_isImportModule(arg)) {
    return ATtrue;
  }
  else if (SDF_isImportRenamedModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_getImportModuleName(SDF_Import arg) */

SDF_ModuleName SDF_getImportModuleName(SDF_Import arg)
{
  if (SDF_isImportModule(arg)) {
    return (SDF_ModuleName)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDF_isImportRenamedModule(arg)) {
    return (SDF_ModuleName)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Import has no ModuleName: %t\n", arg);
  return (SDF_ModuleName)NULL;
}

/*}}}  */
/*{{{  SDF_Import SDF_setImportModuleName(SDF_Import arg, SDF_ModuleName ModuleName) */

SDF_Import SDF_setImportModuleName(SDF_Import arg, SDF_ModuleName ModuleName)
{
  if (SDF_isImportModule(arg)) {
    return (SDF_Import)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ModuleName, 0), 2);
  }
  else if (SDF_isImportRenamedModule(arg)) {
    return (SDF_Import)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ModuleName, 0), 2);
  }

  ATabort("Import has no ModuleName: %t\n", arg);
  return (SDF_Import)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasImportWsAfterModuleName(SDF_Import arg) */

ATbool SDF_hasImportWsAfterModuleName(SDF_Import arg)
{
  if (SDF_isImportRenamedModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getImportWsAfterModuleName(SDF_Import arg) */

char * SDF_getImportWsAfterModuleName(SDF_Import arg)
{
  if (SDF_isImportRenamedModule(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Import has no WsAfterModuleName: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Import SDF_setImportWsAfterModuleName(SDF_Import arg, char * wsAfterModuleName) */

SDF_Import SDF_setImportWsAfterModuleName(SDF_Import arg, char * wsAfterModuleName)
{
  if (SDF_isImportRenamedModule(arg)) {
    return (SDF_Import)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterModuleName, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Import has no WsAfterModuleName: %t\n", arg);
  return (SDF_Import)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasImportRenamings(SDF_Import arg) */

ATbool SDF_hasImportRenamings(SDF_Import arg)
{
  if (SDF_isImportRenamedModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Renamings SDF_getImportRenamings(SDF_Import arg) */

SDF_Renamings SDF_getImportRenamings(SDF_Import arg)
{
  if (SDF_isImportRenamedModule(arg)) {
    return (SDF_Renamings)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Import has no Renamings: %t\n", arg);
  return (SDF_Renamings)NULL;
}

/*}}}  */
/*{{{  SDF_Import SDF_setImportRenamings(SDF_Import arg, SDF_Renamings Renamings) */

SDF_Import SDF_setImportRenamings(SDF_Import arg, SDF_Renamings Renamings)
{
  if (SDF_isImportRenamedModule(arg)) {
    return (SDF_Import)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Renamings, 2), 2);
  }

  ATabort("Import has no Renamings: %t\n", arg);
  return (SDF_Import)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasImportWsAfterParenOpen(SDF_Import arg) */

ATbool SDF_hasImportWsAfterParenOpen(SDF_Import arg)
{
  if (SDF_isImportBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getImportWsAfterParenOpen(SDF_Import arg) */

char * SDF_getImportWsAfterParenOpen(SDF_Import arg)
{
  if (SDF_isImportBracket(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Import has no WsAfterParenOpen: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Import SDF_setImportWsAfterParenOpen(SDF_Import arg, char * wsAfterParenOpen) */

SDF_Import SDF_setImportWsAfterParenOpen(SDF_Import arg, char * wsAfterParenOpen)
{
  if (SDF_isImportBracket(arg)) {
    return (SDF_Import)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterParenOpen, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Import has no WsAfterParenOpen: %t\n", arg);
  return (SDF_Import)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasImportImport(SDF_Import arg) */

ATbool SDF_hasImportImport(SDF_Import arg)
{
  if (SDF_isImportBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Import SDF_getImportImport(SDF_Import arg) */

SDF_Import SDF_getImportImport(SDF_Import arg)
{
  if (SDF_isImportBracket(arg)) {
    return (SDF_Import)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Import has no Import: %t\n", arg);
  return (SDF_Import)NULL;
}

/*}}}  */
/*{{{  SDF_Import SDF_setImportImport(SDF_Import arg, SDF_Import Import) */

SDF_Import SDF_setImportImport(SDF_Import arg, SDF_Import Import)
{
  if (SDF_isImportBracket(arg)) {
    return (SDF_Import)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Import, 2), 2);
  }

  ATabort("Import has no Import: %t\n", arg);
  return (SDF_Import)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasImportWsAfterImport(SDF_Import arg) */

ATbool SDF_hasImportWsAfterImport(SDF_Import arg)
{
  if (SDF_isImportBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getImportWsAfterImport(SDF_Import arg) */

char * SDF_getImportWsAfterImport(SDF_Import arg)
{
  if (SDF_isImportBracket(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Import has no WsAfterImport: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Import SDF_setImportWsAfterImport(SDF_Import arg, char * wsAfterImport) */

SDF_Import SDF_setImportWsAfterImport(SDF_Import arg, char * wsAfterImport)
{
  if (SDF_isImportBracket(arg)) {
    return (SDF_Import)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterImport, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Import has no WsAfterImport: %t\n", arg);
  return (SDF_Import)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_SymbolTail accessors */

/*{{{  ATbool SDF_isValidSymbolTail(SDF_SymbolTail arg) */

ATbool SDF_isValidSymbolTail(SDF_SymbolTail arg)
{
  if (SDF_isSymbolTailSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolTailMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolTailSingle(SDF_SymbolTail arg) */

ATbool SDF_isSymbolTailSingle(SDF_SymbolTail arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolTailSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolTailMany(SDF_SymbolTail arg) */

ATbool SDF_isSymbolTailMany(SDF_SymbolTail arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolTailMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolTailHead(SDF_SymbolTail arg) */

ATbool SDF_hasSymbolTailHead(SDF_SymbolTail arg)
{
  if (SDF_isSymbolTailSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolTailMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_getSymbolTailHead(SDF_SymbolTail arg) */

SDF_Symbol SDF_getSymbolTailHead(SDF_SymbolTail arg)
{
  if (SDF_isSymbolTailSingle(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)arg, 0);
  }
  else if (SDF_isSymbolTailMany(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)arg, 0);
  }

  ATabort("SymbolTail has no Head: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  SDF_SymbolTail SDF_setSymbolTailHead(SDF_SymbolTail arg, SDF_Symbol head) */

SDF_SymbolTail SDF_setSymbolTailHead(SDF_SymbolTail arg, SDF_Symbol head)
{
  if (SDF_isSymbolTailSingle(arg)) {
    return (SDF_SymbolTail)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isSymbolTailMany(arg)) {
    return (SDF_SymbolTail)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("SymbolTail has no Head: %t\n", arg);
  return (SDF_SymbolTail)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolTailWsAfterFirst(SDF_SymbolTail arg) */

ATbool SDF_hasSymbolTailWsAfterFirst(SDF_SymbolTail arg)
{
  if (SDF_isSymbolTailMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolTailWsAfterFirst(SDF_SymbolTail arg) */

char * SDF_getSymbolTailWsAfterFirst(SDF_SymbolTail arg)
{
  if (SDF_isSymbolTailMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0)));
  }

  ATabort("SymbolTail has no WsAfterFirst: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_SymbolTail SDF_setSymbolTailWsAfterFirst(SDF_SymbolTail arg, char * wsAfterFirst) */

SDF_SymbolTail SDF_setSymbolTailWsAfterFirst(SDF_SymbolTail arg, char * wsAfterFirst)
{
  if (SDF_isSymbolTailMany(arg)) {
    return (SDF_SymbolTail)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterFirst, 0, ATtrue)), 0), 1);
  }

  ATabort("SymbolTail has no WsAfterFirst: %t\n", arg);
  return (SDF_SymbolTail)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolTailTail(SDF_SymbolTail arg) */

ATbool SDF_hasSymbolTailTail(SDF_SymbolTail arg)
{
  if (SDF_isSymbolTailMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_SymbolTail SDF_getSymbolTailTail(SDF_SymbolTail arg) */

SDF_SymbolTail SDF_getSymbolTailTail(SDF_SymbolTail arg)
{
  if (SDF_isSymbolTailMany(arg)) {
    return (SDF_SymbolTail)ATgetTail((ATermList)arg, 2);
  }

  ATabort("SymbolTail has no Tail: %t\n", arg);
  return (SDF_SymbolTail)NULL;
}

/*}}}  */
/*{{{  SDF_SymbolTail SDF_setSymbolTailTail(SDF_SymbolTail arg, SDF_SymbolTail tail) */

SDF_SymbolTail SDF_setSymbolTailTail(SDF_SymbolTail arg, SDF_SymbolTail tail)
{
  if (SDF_isSymbolTailMany(arg)) {
    return (SDF_SymbolTail)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("SymbolTail has no Tail: %t\n", arg);
  return (SDF_SymbolTail)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Associativity accessors */

/*{{{  ATbool SDF_isValidAssociativity(SDF_Associativity arg) */

ATbool SDF_isValidAssociativity(SDF_Associativity arg)
{
  if (SDF_isAssociativityLeft(arg)) {
    return ATtrue;
  }
  else if (SDF_isAssociativityRight(arg)) {
    return ATtrue;
  }
  else if (SDF_isAssociativityNonAssoc(arg)) {
    return ATtrue;
  }
  else if (SDF_isAssociativityAssoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isAssociativityLeft(SDF_Associativity arg) */

ATbool SDF_isAssociativityLeft(SDF_Associativity arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAssociativityLeft);
}

/*}}}  */
/*{{{  ATbool SDF_isAssociativityRight(SDF_Associativity arg) */

ATbool SDF_isAssociativityRight(SDF_Associativity arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAssociativityRight);
}

/*}}}  */
/*{{{  ATbool SDF_isAssociativityNonAssoc(SDF_Associativity arg) */

ATbool SDF_isAssociativityNonAssoc(SDF_Associativity arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAssociativityNonAssoc);
}

/*}}}  */
/*{{{  ATbool SDF_isAssociativityAssoc(SDF_Associativity arg) */

ATbool SDF_isAssociativityAssoc(SDF_Associativity arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAssociativityAssoc);
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Group accessors */

/*{{{  ATbool SDF_isValidGroup(SDF_Group arg) */

ATbool SDF_isValidGroup(SDF_Group arg)
{
  if (SDF_isGroupSimpleGroup(arg)) {
    return ATtrue;
  }
  else if (SDF_isGroupProdsGroup(arg)) {
    return ATtrue;
  }
  else if (SDF_isGroupAssocGroup(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isGroupSimpleGroup(SDF_Group arg) */

ATbool SDF_isGroupSimpleGroup(SDF_Group arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternGroupSimpleGroup, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isGroupProdsGroup(SDF_Group arg) */

ATbool SDF_isGroupProdsGroup(SDF_Group arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternGroupProdsGroup, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isGroupAssocGroup(SDF_Group arg) */

ATbool SDF_isGroupAssocGroup(SDF_Group arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternGroupAssocGroup, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasGroupProduction(SDF_Group arg) */

ATbool SDF_hasGroupProduction(SDF_Group arg)
{
  if (SDF_isGroupSimpleGroup(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Production SDF_getGroupProduction(SDF_Group arg) */

SDF_Production SDF_getGroupProduction(SDF_Group arg)
{
  if (SDF_isGroupSimpleGroup(arg)) {
    return (SDF_Production)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Group has no Production: %t\n", arg);
  return (SDF_Production)NULL;
}

/*}}}  */
/*{{{  SDF_Group SDF_setGroupProduction(SDF_Group arg, SDF_Production Production) */

SDF_Group SDF_setGroupProduction(SDF_Group arg, SDF_Production Production)
{
  if (SDF_isGroupSimpleGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Production, 0), 2);
  }

  ATabort("Group has no Production: %t\n", arg);
  return (SDF_Group)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGroupWsAfterBraceOpen(SDF_Group arg) */

ATbool SDF_hasGroupWsAfterBraceOpen(SDF_Group arg)
{
  if (SDF_isGroupProdsGroup(arg)) {
    return ATtrue;
  }
  else if (SDF_isGroupAssocGroup(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getGroupWsAfterBraceOpen(SDF_Group arg) */

char * SDF_getGroupWsAfterBraceOpen(SDF_Group arg)
{
  if (SDF_isGroupProdsGroup(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isGroupAssocGroup(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Group has no WsAfterBraceOpen: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Group SDF_setGroupWsAfterBraceOpen(SDF_Group arg, char * wsAfterBraceOpen) */

SDF_Group SDF_setGroupWsAfterBraceOpen(SDF_Group arg, char * wsAfterBraceOpen)
{
  if (SDF_isGroupProdsGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterBraceOpen, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isGroupAssocGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterBraceOpen, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Group has no WsAfterBraceOpen: %t\n", arg);
  return (SDF_Group)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGroupProductions(SDF_Group arg) */

ATbool SDF_hasGroupProductions(SDF_Group arg)
{
  if (SDF_isGroupProdsGroup(arg)) {
    return ATtrue;
  }
  else if (SDF_isGroupAssocGroup(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Productions SDF_getGroupProductions(SDF_Group arg) */

SDF_Productions SDF_getGroupProductions(SDF_Group arg)
{
  if (SDF_isGroupProdsGroup(arg)) {
    return (SDF_Productions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDF_isGroupAssocGroup(arg)) {
    return (SDF_Productions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 6);
  }

  ATabort("Group has no Productions: %t\n", arg);
  return (SDF_Productions)NULL;
}

/*}}}  */
/*{{{  SDF_Group SDF_setGroupProductions(SDF_Group arg, SDF_Productions Productions) */

SDF_Group SDF_setGroupProductions(SDF_Group arg, SDF_Productions Productions)
{
  if (SDF_isGroupProdsGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Productions, 2), 2);
  }
  else if (SDF_isGroupAssocGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Productions, 6), 2);
  }

  ATabort("Group has no Productions: %t\n", arg);
  return (SDF_Group)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGroupWsAfterProductions(SDF_Group arg) */

ATbool SDF_hasGroupWsAfterProductions(SDF_Group arg)
{
  if (SDF_isGroupProdsGroup(arg)) {
    return ATtrue;
  }
  else if (SDF_isGroupAssocGroup(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getGroupWsAfterProductions(SDF_Group arg) */

char * SDF_getGroupWsAfterProductions(SDF_Group arg)
{
  if (SDF_isGroupProdsGroup(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }
  else if (SDF_isGroupAssocGroup(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), 0)));
  }

  ATabort("Group has no WsAfterProductions: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Group SDF_setGroupWsAfterProductions(SDF_Group arg, char * wsAfterProductions) */

SDF_Group SDF_setGroupWsAfterProductions(SDF_Group arg, char * wsAfterProductions)
{
  if (SDF_isGroupProdsGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterProductions, 0, ATtrue)), 0), 3), 2);
  }
  else if (SDF_isGroupAssocGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterProductions, 0, ATtrue)), 0), 7), 2);
  }

  ATabort("Group has no WsAfterProductions: %t\n", arg);
  return (SDF_Group)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGroupAssociativity(SDF_Group arg) */

ATbool SDF_hasGroupAssociativity(SDF_Group arg)
{
  if (SDF_isGroupAssocGroup(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Associativity SDF_getGroupAssociativity(SDF_Group arg) */

SDF_Associativity SDF_getGroupAssociativity(SDF_Group arg)
{
  if (SDF_isGroupAssocGroup(arg)) {
    return (SDF_Associativity)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Group has no Associativity: %t\n", arg);
  return (SDF_Associativity)NULL;
}

/*}}}  */
/*{{{  SDF_Group SDF_setGroupAssociativity(SDF_Group arg, SDF_Associativity Associativity) */

SDF_Group SDF_setGroupAssociativity(SDF_Group arg, SDF_Associativity Associativity)
{
  if (SDF_isGroupAssocGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Associativity, 2), 2);
  }

  ATabort("Group has no Associativity: %t\n", arg);
  return (SDF_Group)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGroupWsAfterAssociativity(SDF_Group arg) */

ATbool SDF_hasGroupWsAfterAssociativity(SDF_Group arg)
{
  if (SDF_isGroupAssocGroup(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getGroupWsAfterAssociativity(SDF_Group arg) */

char * SDF_getGroupWsAfterAssociativity(SDF_Group arg)
{
  if (SDF_isGroupAssocGroup(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Group has no WsAfterAssociativity: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Group SDF_setGroupWsAfterAssociativity(SDF_Group arg, char * wsAfterAssociativity) */

SDF_Group SDF_setGroupWsAfterAssociativity(SDF_Group arg, char * wsAfterAssociativity)
{
  if (SDF_isGroupAssocGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterAssociativity, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Group has no WsAfterAssociativity: %t\n", arg);
  return (SDF_Group)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGroupWsAfterColon(SDF_Group arg) */

ATbool SDF_hasGroupWsAfterColon(SDF_Group arg)
{
  if (SDF_isGroupAssocGroup(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getGroupWsAfterColon(SDF_Group arg) */

char * SDF_getGroupWsAfterColon(SDF_Group arg)
{
  if (SDF_isGroupAssocGroup(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0)));
  }

  ATabort("Group has no WsAfterColon: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Group SDF_setGroupWsAfterColon(SDF_Group arg, char * wsAfterColon) */

SDF_Group SDF_setGroupWsAfterColon(SDF_Group arg, char * wsAfterColon)
{
  if (SDF_isGroupAssocGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterColon, 0, ATtrue)), 0), 5), 2);
  }

  ATabort("Group has no WsAfterColon: %t\n", arg);
  return (SDF_Group)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Priority accessors */

/*{{{  ATbool SDF_isValidPriority(SDF_Priority arg) */

ATbool SDF_isValidPriority(SDF_Priority arg)
{
  if (SDF_isPriorityChain(arg)) {
    return ATtrue;
  }
  else if (SDF_isPriorityAssoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isPriorityChain(SDF_Priority arg) */

ATbool SDF_isPriorityChain(SDF_Priority arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternPriorityChain, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isPriorityAssoc(SDF_Priority arg) */

ATbool SDF_isPriorityAssoc(SDF_Priority arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternPriorityAssoc, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasPriorityList(SDF_Priority arg) */

ATbool SDF_hasPriorityList(SDF_Priority arg)
{
  if (SDF_isPriorityChain(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_GroupList SDF_getPriorityList(SDF_Priority arg) */

SDF_GroupList SDF_getPriorityList(SDF_Priority arg)
{
  if (SDF_isPriorityChain(arg)) {
    return (SDF_GroupList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 2);
  }

  ATabort("Priority has no List: %t\n", arg);
  return (SDF_GroupList)NULL;
}

/*}}}  */
/*{{{  SDF_Priority SDF_setPriorityList(SDF_Priority arg, SDF_GroupList list) */

SDF_Priority SDF_setPriorityList(SDF_Priority arg, SDF_GroupList list)
{
  if (SDF_isPriorityChain(arg)) {
    return (SDF_Priority)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)list, 2), 0), 2);
  }

  ATabort("Priority has no List: %t\n", arg);
  return (SDF_Priority)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasPriorityLeft(SDF_Priority arg) */

ATbool SDF_hasPriorityLeft(SDF_Priority arg)
{
  if (SDF_isPriorityAssoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Group SDF_getPriorityLeft(SDF_Priority arg) */

SDF_Group SDF_getPriorityLeft(SDF_Priority arg)
{
  if (SDF_isPriorityAssoc(arg)) {
    return (SDF_Group)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Priority has no Left: %t\n", arg);
  return (SDF_Group)NULL;
}

/*}}}  */
/*{{{  SDF_Priority SDF_setPriorityLeft(SDF_Priority arg, SDF_Group left) */

SDF_Priority SDF_setPriorityLeft(SDF_Priority arg, SDF_Group left)
{
  if (SDF_isPriorityAssoc(arg)) {
    return (SDF_Priority)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)left, 0), 2);
  }

  ATabort("Priority has no Left: %t\n", arg);
  return (SDF_Priority)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasPriorityWsAfterLeft(SDF_Priority arg) */

ATbool SDF_hasPriorityWsAfterLeft(SDF_Priority arg)
{
  if (SDF_isPriorityAssoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getPriorityWsAfterLeft(SDF_Priority arg) */

char * SDF_getPriorityWsAfterLeft(SDF_Priority arg)
{
  if (SDF_isPriorityAssoc(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Priority has no WsAfterLeft: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Priority SDF_setPriorityWsAfterLeft(SDF_Priority arg, char * wsAfterLeft) */

SDF_Priority SDF_setPriorityWsAfterLeft(SDF_Priority arg, char * wsAfterLeft)
{
  if (SDF_isPriorityAssoc(arg)) {
    return (SDF_Priority)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterLeft, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Priority has no WsAfterLeft: %t\n", arg);
  return (SDF_Priority)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasPriorityAssociativity(SDF_Priority arg) */

ATbool SDF_hasPriorityAssociativity(SDF_Priority arg)
{
  if (SDF_isPriorityAssoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Associativity SDF_getPriorityAssociativity(SDF_Priority arg) */

SDF_Associativity SDF_getPriorityAssociativity(SDF_Priority arg)
{
  if (SDF_isPriorityAssoc(arg)) {
    return (SDF_Associativity)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Priority has no Associativity: %t\n", arg);
  return (SDF_Associativity)NULL;
}

/*}}}  */
/*{{{  SDF_Priority SDF_setPriorityAssociativity(SDF_Priority arg, SDF_Associativity Associativity) */

SDF_Priority SDF_setPriorityAssociativity(SDF_Priority arg, SDF_Associativity Associativity)
{
  if (SDF_isPriorityAssoc(arg)) {
    return (SDF_Priority)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Associativity, 2), 2);
  }

  ATabort("Priority has no Associativity: %t\n", arg);
  return (SDF_Priority)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasPriorityWsAfterAssociativity(SDF_Priority arg) */

ATbool SDF_hasPriorityWsAfterAssociativity(SDF_Priority arg)
{
  if (SDF_isPriorityAssoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getPriorityWsAfterAssociativity(SDF_Priority arg) */

char * SDF_getPriorityWsAfterAssociativity(SDF_Priority arg)
{
  if (SDF_isPriorityAssoc(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Priority has no WsAfterAssociativity: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Priority SDF_setPriorityWsAfterAssociativity(SDF_Priority arg, char * wsAfterAssociativity) */

SDF_Priority SDF_setPriorityWsAfterAssociativity(SDF_Priority arg, char * wsAfterAssociativity)
{
  if (SDF_isPriorityAssoc(arg)) {
    return (SDF_Priority)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterAssociativity, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Priority has no WsAfterAssociativity: %t\n", arg);
  return (SDF_Priority)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasPriorityRight(SDF_Priority arg) */

ATbool SDF_hasPriorityRight(SDF_Priority arg)
{
  if (SDF_isPriorityAssoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Group SDF_getPriorityRight(SDF_Priority arg) */

SDF_Group SDF_getPriorityRight(SDF_Priority arg)
{
  if (SDF_isPriorityAssoc(arg)) {
    return (SDF_Group)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Priority has no Right: %t\n", arg);
  return (SDF_Group)NULL;
}

/*}}}  */
/*{{{  SDF_Priority SDF_setPriorityRight(SDF_Priority arg, SDF_Group right) */

SDF_Priority SDF_setPriorityRight(SDF_Priority arg, SDF_Group right)
{
  if (SDF_isPriorityAssoc(arg)) {
    return (SDF_Priority)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)right, 4), 2);
  }

  ATabort("Priority has no Right: %t\n", arg);
  return (SDF_Priority)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_GroupList accessors */

/*{{{  ATbool SDF_isValidGroupList(SDF_GroupList arg) */

ATbool SDF_isValidGroupList(SDF_GroupList arg)
{
  if (SDF_isGroupListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isGroupListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isGroupListSingle(SDF_GroupList arg) */

ATbool SDF_isGroupListSingle(SDF_GroupList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternGroupListSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isGroupListMany(SDF_GroupList arg) */

ATbool SDF_isGroupListMany(SDF_GroupList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternGroupListMany, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasGroupListHead(SDF_GroupList arg) */

ATbool SDF_hasGroupListHead(SDF_GroupList arg)
{
  if (SDF_isGroupListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isGroupListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Group SDF_getGroupListHead(SDF_GroupList arg) */

SDF_Group SDF_getGroupListHead(SDF_GroupList arg)
{
  if (SDF_isGroupListSingle(arg)) {
    return (SDF_Group)ATelementAt((ATermList)arg, 0);
  }
  else if (SDF_isGroupListMany(arg)) {
    return (SDF_Group)ATelementAt((ATermList)arg, 0);
  }

  ATabort("GroupList has no Head: %t\n", arg);
  return (SDF_Group)NULL;
}

/*}}}  */
/*{{{  SDF_GroupList SDF_setGroupListHead(SDF_GroupList arg, SDF_Group head) */

SDF_GroupList SDF_setGroupListHead(SDF_GroupList arg, SDF_Group head)
{
  if (SDF_isGroupListSingle(arg)) {
    return (SDF_GroupList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isGroupListMany(arg)) {
    return (SDF_GroupList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("GroupList has no Head: %t\n", arg);
  return (SDF_GroupList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGroupListWsAfterFirst(SDF_GroupList arg) */

ATbool SDF_hasGroupListWsAfterFirst(SDF_GroupList arg)
{
  if (SDF_isGroupListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getGroupListWsAfterFirst(SDF_GroupList arg) */

char * SDF_getGroupListWsAfterFirst(SDF_GroupList arg)
{
  if (SDF_isGroupListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0)));
  }

  ATabort("GroupList has no WsAfterFirst: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_GroupList SDF_setGroupListWsAfterFirst(SDF_GroupList arg, char * wsAfterFirst) */

SDF_GroupList SDF_setGroupListWsAfterFirst(SDF_GroupList arg, char * wsAfterFirst)
{
  if (SDF_isGroupListMany(arg)) {
    return (SDF_GroupList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterFirst, 0, ATtrue)), 0), 1);
  }

  ATabort("GroupList has no WsAfterFirst: %t\n", arg);
  return (SDF_GroupList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGroupListSep(SDF_GroupList arg) */

ATbool SDF_hasGroupListSep(SDF_GroupList arg)
{
  if (SDF_isGroupListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getGroupListSep(SDF_GroupList arg) */

char * SDF_getGroupListSep(SDF_GroupList arg)
{
  if (SDF_isGroupListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
  }

  ATabort("GroupList has no Sep: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_GroupList SDF_setGroupListSep(SDF_GroupList arg, char * sep) */

SDF_GroupList SDF_setGroupListSep(SDF_GroupList arg, char * sep)
{
  if (SDF_isGroupListMany(arg)) {
    return (SDF_GroupList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("GroupList has no Sep: %t\n", arg);
  return (SDF_GroupList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGroupListWsAfterSep(SDF_GroupList arg) */

ATbool SDF_hasGroupListWsAfterSep(SDF_GroupList arg)
{
  if (SDF_isGroupListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getGroupListWsAfterSep(SDF_GroupList arg) */

char * SDF_getGroupListWsAfterSep(SDF_GroupList arg)
{
  if (SDF_isGroupListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), 0)));
  }

  ATabort("GroupList has no WsAfterSep: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_GroupList SDF_setGroupListWsAfterSep(SDF_GroupList arg, char * wsAfterSep) */

SDF_GroupList SDF_setGroupListWsAfterSep(SDF_GroupList arg, char * wsAfterSep)
{
  if (SDF_isGroupListMany(arg)) {
    return (SDF_GroupList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSep, 0, ATtrue)), 0), 3);
  }

  ATabort("GroupList has no WsAfterSep: %t\n", arg);
  return (SDF_GroupList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGroupListTail(SDF_GroupList arg) */

ATbool SDF_hasGroupListTail(SDF_GroupList arg)
{
  if (SDF_isGroupListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_GroupList SDF_getGroupListTail(SDF_GroupList arg) */

SDF_GroupList SDF_getGroupListTail(SDF_GroupList arg)
{
  if (SDF_isGroupListMany(arg)) {
    return (SDF_GroupList)ATgetTail((ATermList)arg, 4);
  }

  ATabort("GroupList has no Tail: %t\n", arg);
  return (SDF_GroupList)NULL;
}

/*}}}  */
/*{{{  SDF_GroupList SDF_setGroupListTail(SDF_GroupList arg, SDF_GroupList tail) */

SDF_GroupList SDF_setGroupListTail(SDF_GroupList arg, SDF_GroupList tail)
{
  if (SDF_isGroupListMany(arg)) {
    return (SDF_GroupList)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("GroupList has no Tail: %t\n", arg);
  return (SDF_GroupList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Priorities accessors */

/*{{{  ATbool SDF_isValidPriorities(SDF_Priorities arg) */

ATbool SDF_isValidPriorities(SDF_Priorities arg)
{
  if (SDF_isPrioritiesDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isPrioritiesDefault(SDF_Priorities arg) */

ATbool SDF_isPrioritiesDefault(SDF_Priorities arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternPrioritiesDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasPrioritiesList(SDF_Priorities arg) */

ATbool SDF_hasPrioritiesList(SDF_Priorities arg)
{
  if (SDF_isPrioritiesDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_PriorityList SDF_getPrioritiesList(SDF_Priorities arg) */

SDF_PriorityList SDF_getPrioritiesList(SDF_Priorities arg)
{
  if (SDF_isPrioritiesDefault(arg)) {
    return (SDF_PriorityList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 2);
  }

  ATabort("Priorities has no List: %t\n", arg);
  return (SDF_PriorityList)NULL;
}

/*}}}  */
/*{{{  SDF_Priorities SDF_setPrioritiesList(SDF_Priorities arg, SDF_PriorityList list) */

SDF_Priorities SDF_setPrioritiesList(SDF_Priorities arg, SDF_PriorityList list)
{
  if (SDF_isPrioritiesDefault(arg)) {
    return (SDF_Priorities)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)list, 2), 0), 2);
  }

  ATabort("Priorities has no List: %t\n", arg);
  return (SDF_Priorities)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_PriorityList accessors */

/*{{{  ATbool SDF_isValidPriorityList(SDF_PriorityList arg) */

ATbool SDF_isValidPriorityList(SDF_PriorityList arg)
{
  if (SDF_isPriorityListEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isPriorityListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isPriorityListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isPriorityListEmpty(SDF_PriorityList arg) */

ATbool SDF_isPriorityListEmpty(SDF_PriorityList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternPriorityListEmpty);
}

/*}}}  */
/*{{{  ATbool SDF_isPriorityListSingle(SDF_PriorityList arg) */

ATbool SDF_isPriorityListSingle(SDF_PriorityList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternPriorityListSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isPriorityListMany(SDF_PriorityList arg) */

ATbool SDF_isPriorityListMany(SDF_PriorityList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternPriorityListMany, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasPriorityListHead(SDF_PriorityList arg) */

ATbool SDF_hasPriorityListHead(SDF_PriorityList arg)
{
  if (SDF_isPriorityListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isPriorityListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Priority SDF_getPriorityListHead(SDF_PriorityList arg) */

SDF_Priority SDF_getPriorityListHead(SDF_PriorityList arg)
{
  if (SDF_isPriorityListSingle(arg)) {
    return (SDF_Priority)ATelementAt((ATermList)arg, 0);
  }
  else if (SDF_isPriorityListMany(arg)) {
    return (SDF_Priority)ATelementAt((ATermList)arg, 0);
  }

  ATabort("PriorityList has no Head: %t\n", arg);
  return (SDF_Priority)NULL;
}

/*}}}  */
/*{{{  SDF_PriorityList SDF_setPriorityListHead(SDF_PriorityList arg, SDF_Priority head) */

SDF_PriorityList SDF_setPriorityListHead(SDF_PriorityList arg, SDF_Priority head)
{
  if (SDF_isPriorityListSingle(arg)) {
    return (SDF_PriorityList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isPriorityListMany(arg)) {
    return (SDF_PriorityList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("PriorityList has no Head: %t\n", arg);
  return (SDF_PriorityList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasPriorityListWsAfterFirst(SDF_PriorityList arg) */

ATbool SDF_hasPriorityListWsAfterFirst(SDF_PriorityList arg)
{
  if (SDF_isPriorityListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getPriorityListWsAfterFirst(SDF_PriorityList arg) */

char * SDF_getPriorityListWsAfterFirst(SDF_PriorityList arg)
{
  if (SDF_isPriorityListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0)));
  }

  ATabort("PriorityList has no WsAfterFirst: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_PriorityList SDF_setPriorityListWsAfterFirst(SDF_PriorityList arg, char * wsAfterFirst) */

SDF_PriorityList SDF_setPriorityListWsAfterFirst(SDF_PriorityList arg, char * wsAfterFirst)
{
  if (SDF_isPriorityListMany(arg)) {
    return (SDF_PriorityList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterFirst, 0, ATtrue)), 0), 1);
  }

  ATabort("PriorityList has no WsAfterFirst: %t\n", arg);
  return (SDF_PriorityList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasPriorityListSep(SDF_PriorityList arg) */

ATbool SDF_hasPriorityListSep(SDF_PriorityList arg)
{
  if (SDF_isPriorityListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getPriorityListSep(SDF_PriorityList arg) */

char * SDF_getPriorityListSep(SDF_PriorityList arg)
{
  if (SDF_isPriorityListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
  }

  ATabort("PriorityList has no Sep: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_PriorityList SDF_setPriorityListSep(SDF_PriorityList arg, char * sep) */

SDF_PriorityList SDF_setPriorityListSep(SDF_PriorityList arg, char * sep)
{
  if (SDF_isPriorityListMany(arg)) {
    return (SDF_PriorityList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("PriorityList has no Sep: %t\n", arg);
  return (SDF_PriorityList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasPriorityListWsAfterSep(SDF_PriorityList arg) */

ATbool SDF_hasPriorityListWsAfterSep(SDF_PriorityList arg)
{
  if (SDF_isPriorityListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getPriorityListWsAfterSep(SDF_PriorityList arg) */

char * SDF_getPriorityListWsAfterSep(SDF_PriorityList arg)
{
  if (SDF_isPriorityListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), 0)));
  }

  ATabort("PriorityList has no WsAfterSep: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_PriorityList SDF_setPriorityListWsAfterSep(SDF_PriorityList arg, char * wsAfterSep) */

SDF_PriorityList SDF_setPriorityListWsAfterSep(SDF_PriorityList arg, char * wsAfterSep)
{
  if (SDF_isPriorityListMany(arg)) {
    return (SDF_PriorityList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSep, 0, ATtrue)), 0), 3);
  }

  ATabort("PriorityList has no WsAfterSep: %t\n", arg);
  return (SDF_PriorityList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasPriorityListTail(SDF_PriorityList arg) */

ATbool SDF_hasPriorityListTail(SDF_PriorityList arg)
{
  if (SDF_isPriorityListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_PriorityList SDF_getPriorityListTail(SDF_PriorityList arg) */

SDF_PriorityList SDF_getPriorityListTail(SDF_PriorityList arg)
{
  if (SDF_isPriorityListMany(arg)) {
    return (SDF_PriorityList)ATgetTail((ATermList)arg, 4);
  }

  ATabort("PriorityList has no Tail: %t\n", arg);
  return (SDF_PriorityList)NULL;
}

/*}}}  */
/*{{{  SDF_PriorityList SDF_setPriorityListTail(SDF_PriorityList arg, SDF_PriorityList tail) */

SDF_PriorityList SDF_setPriorityListTail(SDF_PriorityList arg, SDF_PriorityList tail)
{
  if (SDF_isPriorityListMany(arg)) {
    return (SDF_PriorityList)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("PriorityList has no Tail: %t\n", arg);
  return (SDF_PriorityList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Sort accessors */

/*{{{  ATbool SDF_isValidSort(SDF_Sort arg) */

ATbool SDF_isValidSort(SDF_Sort arg)
{
  if (SDF_isSortOneChar(arg)) {
    return ATtrue;
  }
  else if (SDF_isSortMoreChars(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isSortOneChar(SDF_Sort arg) */

ATbool SDF_isSortOneChar(SDF_Sort arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSortOneChar, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSortMoreChars(SDF_Sort arg) */

ATbool SDF_isSortMoreChars(SDF_Sort arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSortMoreChars, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasSortLex(SDF_Sort arg) */

ATbool SDF_hasSortLex(SDF_Sort arg)
{
  if (SDF_isSortOneChar(arg)) {
    return ATtrue;
  }
  else if (SDF_isSortMoreChars(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSortLex(SDF_Sort arg) */

char * SDF_getSortLex(SDF_Sort arg)
{
  if (SDF_isSortOneChar(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (SDF_isSortMoreChars(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }

  ATabort("Sort has no Lex: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Sort SDF_setSortLex(SDF_Sort arg, char * lex) */

SDF_Sort SDF_setSortLex(SDF_Sort arg, char * lex)
{
  if (SDF_isSortOneChar(arg)) {
    return (SDF_Sort)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }
  else if (SDF_isSortMoreChars(arg)) {
    return (SDF_Sort)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }

  ATabort("Sort has no Lex: %t\n", arg);
  return (SDF_Sort)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_UQLiteral accessors */

/*{{{  ATbool SDF_isValidUQLiteral(SDF_UQLiteral arg) */

ATbool SDF_isValidUQLiteral(SDF_UQLiteral arg)
{
  if (SDF_isUQLiteralOneChar(arg)) {
    return ATtrue;
  }
  else if (SDF_isUQLiteralMoreChars(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isUQLiteralOneChar(SDF_UQLiteral arg) */

ATbool SDF_isUQLiteralOneChar(SDF_UQLiteral arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternUQLiteralOneChar, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isUQLiteralMoreChars(SDF_UQLiteral arg) */

ATbool SDF_isUQLiteralMoreChars(SDF_UQLiteral arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternUQLiteralMoreChars, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasUQLiteralLex(SDF_UQLiteral arg) */

ATbool SDF_hasUQLiteralLex(SDF_UQLiteral arg)
{
  if (SDF_isUQLiteralOneChar(arg)) {
    return ATtrue;
  }
  else if (SDF_isUQLiteralMoreChars(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getUQLiteralLex(SDF_UQLiteral arg) */

char * SDF_getUQLiteralLex(SDF_UQLiteral arg)
{
  if (SDF_isUQLiteralOneChar(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (SDF_isUQLiteralMoreChars(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }

  ATabort("UQLiteral has no Lex: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_UQLiteral SDF_setUQLiteralLex(SDF_UQLiteral arg, char * lex) */

SDF_UQLiteral SDF_setUQLiteralLex(SDF_UQLiteral arg, char * lex)
{
  if (SDF_isUQLiteralOneChar(arg)) {
    return (SDF_UQLiteral)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }
  else if (SDF_isUQLiteralMoreChars(arg)) {
    return (SDF_UQLiteral)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }

  ATabort("UQLiteral has no Lex: %t\n", arg);
  return (SDF_UQLiteral)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Literal accessors */

/*{{{  ATbool SDF_isValidLiteral(SDF_Literal arg) */

ATbool SDF_isValidLiteral(SDF_Literal arg)
{
  if (SDF_isLiteralUqlit(arg)) {
    return ATtrue;
  }
  else if (SDF_isLiteralQuoted(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isLiteralUqlit(SDF_Literal arg) */

ATbool SDF_isLiteralUqlit(SDF_Literal arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternLiteralUqlit, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isLiteralQuoted(SDF_Literal arg) */

ATbool SDF_isLiteralQuoted(SDF_Literal arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternLiteralQuoted, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasLiteralUQLiteral(SDF_Literal arg) */

ATbool SDF_hasLiteralUQLiteral(SDF_Literal arg)
{
  if (SDF_isLiteralUqlit(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_UQLiteral SDF_getLiteralUQLiteral(SDF_Literal arg) */

SDF_UQLiteral SDF_getLiteralUQLiteral(SDF_Literal arg)
{
  if (SDF_isLiteralUqlit(arg)) {
    return (SDF_UQLiteral)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Literal has no UQLiteral: %t\n", arg);
  return (SDF_UQLiteral)NULL;
}

/*}}}  */
/*{{{  SDF_Literal SDF_setLiteralUQLiteral(SDF_Literal arg, SDF_UQLiteral UQLiteral) */

SDF_Literal SDF_setLiteralUQLiteral(SDF_Literal arg, SDF_UQLiteral UQLiteral)
{
  if (SDF_isLiteralUqlit(arg)) {
    return (SDF_Literal)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)UQLiteral, 0), 2);
  }

  ATabort("Literal has no UQLiteral: %t\n", arg);
  return (SDF_Literal)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasLiteralLex(SDF_Literal arg) */

ATbool SDF_hasLiteralLex(SDF_Literal arg)
{
  if (SDF_isLiteralQuoted(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getLiteralLex(SDF_Literal arg) */

char * SDF_getLiteralLex(SDF_Literal arg)
{
  if (SDF_isLiteralQuoted(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }

  ATabort("Literal has no Lex: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Literal SDF_setLiteralLex(SDF_Literal arg, char * lex) */

SDF_Literal SDF_setLiteralLex(SDF_Literal arg, char * lex)
{
  if (SDF_isLiteralQuoted(arg)) {
    return (SDF_Literal)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }

  ATabort("Literal has no Lex: %t\n", arg);
  return (SDF_Literal)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_SymbolArguments accessors */

/*{{{  ATbool SDF_isValidSymbolArguments(SDF_SymbolArguments arg) */

ATbool SDF_isValidSymbolArguments(SDF_SymbolArguments arg)
{
  if (SDF_isSymbolArgumentsEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolArgumentsSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolArgumentsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolArgumentsEmpty(SDF_SymbolArguments arg) */

ATbool SDF_isSymbolArgumentsEmpty(SDF_SymbolArguments arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolArgumentsEmpty);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolArgumentsSingle(SDF_SymbolArguments arg) */

ATbool SDF_isSymbolArgumentsSingle(SDF_SymbolArguments arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolArgumentsSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolArgumentsMany(SDF_SymbolArguments arg) */

ATbool SDF_isSymbolArgumentsMany(SDF_SymbolArguments arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolArgumentsMany, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolArgumentsHead(SDF_SymbolArguments arg) */

ATbool SDF_hasSymbolArgumentsHead(SDF_SymbolArguments arg)
{
  if (SDF_isSymbolArgumentsSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolArgumentsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_getSymbolArgumentsHead(SDF_SymbolArguments arg) */

SDF_Symbol SDF_getSymbolArgumentsHead(SDF_SymbolArguments arg)
{
  if (SDF_isSymbolArgumentsSingle(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)arg, 0);
  }
  else if (SDF_isSymbolArgumentsMany(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)arg, 0);
  }

  ATabort("SymbolArguments has no Head: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  SDF_SymbolArguments SDF_setSymbolArgumentsHead(SDF_SymbolArguments arg, SDF_Symbol head) */

SDF_SymbolArguments SDF_setSymbolArgumentsHead(SDF_SymbolArguments arg, SDF_Symbol head)
{
  if (SDF_isSymbolArgumentsSingle(arg)) {
    return (SDF_SymbolArguments)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isSymbolArgumentsMany(arg)) {
    return (SDF_SymbolArguments)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("SymbolArguments has no Head: %t\n", arg);
  return (SDF_SymbolArguments)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolArgumentsWsAfterFirst(SDF_SymbolArguments arg) */

ATbool SDF_hasSymbolArgumentsWsAfterFirst(SDF_SymbolArguments arg)
{
  if (SDF_isSymbolArgumentsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolArgumentsWsAfterFirst(SDF_SymbolArguments arg) */

char * SDF_getSymbolArgumentsWsAfterFirst(SDF_SymbolArguments arg)
{
  if (SDF_isSymbolArgumentsMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0)));
  }

  ATabort("SymbolArguments has no WsAfterFirst: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_SymbolArguments SDF_setSymbolArgumentsWsAfterFirst(SDF_SymbolArguments arg, char * wsAfterFirst) */

SDF_SymbolArguments SDF_setSymbolArgumentsWsAfterFirst(SDF_SymbolArguments arg, char * wsAfterFirst)
{
  if (SDF_isSymbolArgumentsMany(arg)) {
    return (SDF_SymbolArguments)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterFirst, 0, ATtrue)), 0), 1);
  }

  ATabort("SymbolArguments has no WsAfterFirst: %t\n", arg);
  return (SDF_SymbolArguments)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolArgumentsSep(SDF_SymbolArguments arg) */

ATbool SDF_hasSymbolArgumentsSep(SDF_SymbolArguments arg)
{
  if (SDF_isSymbolArgumentsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolArgumentsSep(SDF_SymbolArguments arg) */

char * SDF_getSymbolArgumentsSep(SDF_SymbolArguments arg)
{
  if (SDF_isSymbolArgumentsMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
  }

  ATabort("SymbolArguments has no Sep: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_SymbolArguments SDF_setSymbolArgumentsSep(SDF_SymbolArguments arg, char * sep) */

SDF_SymbolArguments SDF_setSymbolArgumentsSep(SDF_SymbolArguments arg, char * sep)
{
  if (SDF_isSymbolArgumentsMany(arg)) {
    return (SDF_SymbolArguments)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("SymbolArguments has no Sep: %t\n", arg);
  return (SDF_SymbolArguments)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolArgumentsWsAfterSep(SDF_SymbolArguments arg) */

ATbool SDF_hasSymbolArgumentsWsAfterSep(SDF_SymbolArguments arg)
{
  if (SDF_isSymbolArgumentsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolArgumentsWsAfterSep(SDF_SymbolArguments arg) */

char * SDF_getSymbolArgumentsWsAfterSep(SDF_SymbolArguments arg)
{
  if (SDF_isSymbolArgumentsMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), 0)));
  }

  ATabort("SymbolArguments has no WsAfterSep: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_SymbolArguments SDF_setSymbolArgumentsWsAfterSep(SDF_SymbolArguments arg, char * wsAfterSep) */

SDF_SymbolArguments SDF_setSymbolArgumentsWsAfterSep(SDF_SymbolArguments arg, char * wsAfterSep)
{
  if (SDF_isSymbolArgumentsMany(arg)) {
    return (SDF_SymbolArguments)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSep, 0, ATtrue)), 0), 3);
  }

  ATabort("SymbolArguments has no WsAfterSep: %t\n", arg);
  return (SDF_SymbolArguments)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolArgumentsTail(SDF_SymbolArguments arg) */

ATbool SDF_hasSymbolArgumentsTail(SDF_SymbolArguments arg)
{
  if (SDF_isSymbolArgumentsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_SymbolArguments SDF_getSymbolArgumentsTail(SDF_SymbolArguments arg) */

SDF_SymbolArguments SDF_getSymbolArgumentsTail(SDF_SymbolArguments arg)
{
  if (SDF_isSymbolArgumentsMany(arg)) {
    return (SDF_SymbolArguments)ATgetTail((ATermList)arg, 4);
  }

  ATabort("SymbolArguments has no Tail: %t\n", arg);
  return (SDF_SymbolArguments)NULL;
}

/*}}}  */
/*{{{  SDF_SymbolArguments SDF_setSymbolArgumentsTail(SDF_SymbolArguments arg, SDF_SymbolArguments tail) */

SDF_SymbolArguments SDF_setSymbolArgumentsTail(SDF_SymbolArguments arg, SDF_SymbolArguments tail)
{
  if (SDF_isSymbolArgumentsMany(arg)) {
    return (SDF_SymbolArguments)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("SymbolArguments has no Tail: %t\n", arg);
  return (SDF_SymbolArguments)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Lookahead accessors */

/*{{{  ATbool SDF_isValidLookahead(SDF_Lookahead arg) */

ATbool SDF_isValidLookahead(SDF_Lookahead arg)
{
  if (SDF_isLookaheadCharClass(arg)) {
    return ATtrue;
  }
  else if (SDF_isLookaheadSeq(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isLookaheadCharClass(SDF_Lookahead arg) */

ATbool SDF_isLookaheadCharClass(SDF_Lookahead arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternLookaheadCharClass, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isLookaheadSeq(SDF_Lookahead arg) */

ATbool SDF_isLookaheadSeq(SDF_Lookahead arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternLookaheadSeq, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadCharClass(SDF_Lookahead arg) */

ATbool SDF_hasLookaheadCharClass(SDF_Lookahead arg)
{
  if (SDF_isLookaheadCharClass(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_getLookaheadCharClass(SDF_Lookahead arg) */

SDF_CharClass SDF_getLookaheadCharClass(SDF_Lookahead arg)
{
  if (SDF_isLookaheadCharClass(arg)) {
    return (SDF_CharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Lookahead has no CharClass: %t\n", arg);
  return (SDF_CharClass)NULL;
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_setLookaheadCharClass(SDF_Lookahead arg, SDF_CharClass CharClass) */

SDF_Lookahead SDF_setLookaheadCharClass(SDF_Lookahead arg, SDF_CharClass CharClass)
{
  if (SDF_isLookaheadCharClass(arg)) {
    return (SDF_Lookahead)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)CharClass, 0), 2);
  }

  ATabort("Lookahead has no CharClass: %t\n", arg);
  return (SDF_Lookahead)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadHead(SDF_Lookahead arg) */

ATbool SDF_hasLookaheadHead(SDF_Lookahead arg)
{
  if (SDF_isLookaheadSeq(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_getLookaheadHead(SDF_Lookahead arg) */

SDF_CharClass SDF_getLookaheadHead(SDF_Lookahead arg)
{
  if (SDF_isLookaheadSeq(arg)) {
    return (SDF_CharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Lookahead has no Head: %t\n", arg);
  return (SDF_CharClass)NULL;
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_setLookaheadHead(SDF_Lookahead arg, SDF_CharClass head) */

SDF_Lookahead SDF_setLookaheadHead(SDF_Lookahead arg, SDF_CharClass head)
{
  if (SDF_isLookaheadSeq(arg)) {
    return (SDF_Lookahead)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)head, 0), 2);
  }

  ATabort("Lookahead has no Head: %t\n", arg);
  return (SDF_Lookahead)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadWsAfterHead(SDF_Lookahead arg) */

ATbool SDF_hasLookaheadWsAfterHead(SDF_Lookahead arg)
{
  if (SDF_isLookaheadSeq(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getLookaheadWsAfterHead(SDF_Lookahead arg) */

char * SDF_getLookaheadWsAfterHead(SDF_Lookahead arg)
{
  if (SDF_isLookaheadSeq(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Lookahead has no WsAfterHead: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_setLookaheadWsAfterHead(SDF_Lookahead arg, char * wsAfterHead) */

SDF_Lookahead SDF_setLookaheadWsAfterHead(SDF_Lookahead arg, char * wsAfterHead)
{
  if (SDF_isLookaheadSeq(arg)) {
    return (SDF_Lookahead)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterHead, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Lookahead has no WsAfterHead: %t\n", arg);
  return (SDF_Lookahead)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadWsAfterPeriod(SDF_Lookahead arg) */

ATbool SDF_hasLookaheadWsAfterPeriod(SDF_Lookahead arg)
{
  if (SDF_isLookaheadSeq(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getLookaheadWsAfterPeriod(SDF_Lookahead arg) */

char * SDF_getLookaheadWsAfterPeriod(SDF_Lookahead arg)
{
  if (SDF_isLookaheadSeq(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Lookahead has no WsAfterPeriod: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_setLookaheadWsAfterPeriod(SDF_Lookahead arg, char * wsAfterPeriod) */

SDF_Lookahead SDF_setLookaheadWsAfterPeriod(SDF_Lookahead arg, char * wsAfterPeriod)
{
  if (SDF_isLookaheadSeq(arg)) {
    return (SDF_Lookahead)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterPeriod, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Lookahead has no WsAfterPeriod: %t\n", arg);
  return (SDF_Lookahead)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadTail(SDF_Lookahead arg) */

ATbool SDF_hasLookaheadTail(SDF_Lookahead arg)
{
  if (SDF_isLookaheadSeq(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_getLookaheadTail(SDF_Lookahead arg) */

SDF_Lookaheads SDF_getLookaheadTail(SDF_Lookahead arg)
{
  if (SDF_isLookaheadSeq(arg)) {
    return (SDF_Lookaheads)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Lookahead has no Tail: %t\n", arg);
  return (SDF_Lookaheads)NULL;
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_setLookaheadTail(SDF_Lookahead arg, SDF_Lookaheads tail) */

SDF_Lookahead SDF_setLookaheadTail(SDF_Lookahead arg, SDF_Lookaheads tail)
{
  if (SDF_isLookaheadSeq(arg)) {
    return (SDF_Lookahead)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)tail, 4), 2);
  }

  ATabort("Lookahead has no Tail: %t\n", arg);
  return (SDF_Lookahead)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Lookaheads accessors */

/*{{{  ATbool SDF_isValidLookaheads(SDF_Lookaheads arg) */

ATbool SDF_isValidLookaheads(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isLookaheadsAlt(arg)) {
    return ATtrue;
  }
  else if (SDF_isLookaheadsBracket(arg)) {
    return ATtrue;
  }
  else if (SDF_isLookaheadsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isLookaheadsSingle(SDF_Lookaheads arg) */

ATbool SDF_isLookaheadsSingle(SDF_Lookaheads arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternLookaheadsSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isLookaheadsAlt(SDF_Lookaheads arg) */

ATbool SDF_isLookaheadsAlt(SDF_Lookaheads arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternLookaheadsAlt, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isLookaheadsBracket(SDF_Lookaheads arg) */

ATbool SDF_isLookaheadsBracket(SDF_Lookaheads arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternLookaheadsBracket, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isLookaheadsList(SDF_Lookaheads arg) */

ATbool SDF_isLookaheadsList(SDF_Lookaheads arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternLookaheadsList, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadsLookahead(SDF_Lookaheads arg) */

ATbool SDF_hasLookaheadsLookahead(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsSingle(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_getLookaheadsLookahead(SDF_Lookaheads arg) */

SDF_Lookahead SDF_getLookaheadsLookahead(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsSingle(arg)) {
    return (SDF_Lookahead)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Lookaheads has no Lookahead: %t\n", arg);
  return (SDF_Lookahead)NULL;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsLookahead(SDF_Lookaheads arg, SDF_Lookahead Lookahead) */

SDF_Lookaheads SDF_setLookaheadsLookahead(SDF_Lookaheads arg, SDF_Lookahead Lookahead)
{
  if (SDF_isLookaheadsSingle(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Lookahead, 0), 2);
  }

  ATabort("Lookaheads has no Lookahead: %t\n", arg);
  return (SDF_Lookaheads)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadsLeft(SDF_Lookaheads arg) */

ATbool SDF_hasLookaheadsLeft(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsAlt(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_getLookaheadsLeft(SDF_Lookaheads arg) */

SDF_Lookaheads SDF_getLookaheadsLeft(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsAlt(arg)) {
    return (SDF_Lookaheads)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Lookaheads has no Left: %t\n", arg);
  return (SDF_Lookaheads)NULL;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsLeft(SDF_Lookaheads arg, SDF_Lookaheads left) */

SDF_Lookaheads SDF_setLookaheadsLeft(SDF_Lookaheads arg, SDF_Lookaheads left)
{
  if (SDF_isLookaheadsAlt(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)left, 0), 2);
  }

  ATabort("Lookaheads has no Left: %t\n", arg);
  return (SDF_Lookaheads)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadsWsAfterLeft(SDF_Lookaheads arg) */

ATbool SDF_hasLookaheadsWsAfterLeft(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsAlt(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getLookaheadsWsAfterLeft(SDF_Lookaheads arg) */

char * SDF_getLookaheadsWsAfterLeft(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsAlt(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Lookaheads has no WsAfterLeft: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsWsAfterLeft(SDF_Lookaheads arg, char * wsAfterLeft) */

SDF_Lookaheads SDF_setLookaheadsWsAfterLeft(SDF_Lookaheads arg, char * wsAfterLeft)
{
  if (SDF_isLookaheadsAlt(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterLeft, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Lookaheads has no WsAfterLeft: %t\n", arg);
  return (SDF_Lookaheads)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadsWsAfterBar(SDF_Lookaheads arg) */

ATbool SDF_hasLookaheadsWsAfterBar(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsAlt(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getLookaheadsWsAfterBar(SDF_Lookaheads arg) */

char * SDF_getLookaheadsWsAfterBar(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsAlt(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Lookaheads has no WsAfterBar: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsWsAfterBar(SDF_Lookaheads arg, char * wsAfterBar) */

SDF_Lookaheads SDF_setLookaheadsWsAfterBar(SDF_Lookaheads arg, char * wsAfterBar)
{
  if (SDF_isLookaheadsAlt(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterBar, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Lookaheads has no WsAfterBar: %t\n", arg);
  return (SDF_Lookaheads)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadsRight(SDF_Lookaheads arg) */

ATbool SDF_hasLookaheadsRight(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsAlt(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_getLookaheadsRight(SDF_Lookaheads arg) */

SDF_Lookaheads SDF_getLookaheadsRight(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsAlt(arg)) {
    return (SDF_Lookaheads)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Lookaheads has no Right: %t\n", arg);
  return (SDF_Lookaheads)NULL;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsRight(SDF_Lookaheads arg, SDF_Lookaheads right) */

SDF_Lookaheads SDF_setLookaheadsRight(SDF_Lookaheads arg, SDF_Lookaheads right)
{
  if (SDF_isLookaheadsAlt(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)right, 4), 2);
  }

  ATabort("Lookaheads has no Right: %t\n", arg);
  return (SDF_Lookaheads)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadsWsAfterParenOpen(SDF_Lookaheads arg) */

ATbool SDF_hasLookaheadsWsAfterParenOpen(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getLookaheadsWsAfterParenOpen(SDF_Lookaheads arg) */

char * SDF_getLookaheadsWsAfterParenOpen(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsBracket(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Lookaheads has no WsAfterParenOpen: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsWsAfterParenOpen(SDF_Lookaheads arg, char * wsAfterParenOpen) */

SDF_Lookaheads SDF_setLookaheadsWsAfterParenOpen(SDF_Lookaheads arg, char * wsAfterParenOpen)
{
  if (SDF_isLookaheadsBracket(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterParenOpen, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Lookaheads has no WsAfterParenOpen: %t\n", arg);
  return (SDF_Lookaheads)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadsLookaheads(SDF_Lookaheads arg) */

ATbool SDF_hasLookaheadsLookaheads(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_getLookaheadsLookaheads(SDF_Lookaheads arg) */

SDF_Lookaheads SDF_getLookaheadsLookaheads(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsBracket(arg)) {
    return (SDF_Lookaheads)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Lookaheads has no Lookaheads: %t\n", arg);
  return (SDF_Lookaheads)NULL;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsLookaheads(SDF_Lookaheads arg, SDF_Lookaheads Lookaheads) */

SDF_Lookaheads SDF_setLookaheadsLookaheads(SDF_Lookaheads arg, SDF_Lookaheads Lookaheads)
{
  if (SDF_isLookaheadsBracket(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Lookaheads, 2), 2);
  }

  ATabort("Lookaheads has no Lookaheads: %t\n", arg);
  return (SDF_Lookaheads)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadsWsAfterLookaheads(SDF_Lookaheads arg) */

ATbool SDF_hasLookaheadsWsAfterLookaheads(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getLookaheadsWsAfterLookaheads(SDF_Lookaheads arg) */

char * SDF_getLookaheadsWsAfterLookaheads(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsBracket(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Lookaheads has no WsAfterLookaheads: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsWsAfterLookaheads(SDF_Lookaheads arg, char * wsAfterLookaheads) */

SDF_Lookaheads SDF_setLookaheadsWsAfterLookaheads(SDF_Lookaheads arg, char * wsAfterLookaheads)
{
  if (SDF_isLookaheadsBracket(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterLookaheads, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Lookaheads has no WsAfterLookaheads: %t\n", arg);
  return (SDF_Lookaheads)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadsWsAfterBracketOpenBracketOpen(SDF_Lookaheads arg) */

ATbool SDF_hasLookaheadsWsAfterBracketOpenBracketOpen(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getLookaheadsWsAfterBracketOpenBracketOpen(SDF_Lookaheads arg) */

char * SDF_getLookaheadsWsAfterBracketOpenBracketOpen(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsList(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Lookaheads has no WsAfterBracketOpenBracketOpen: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsWsAfterBracketOpenBracketOpen(SDF_Lookaheads arg, char * wsAfterBracketOpenBracketOpen) */

SDF_Lookaheads SDF_setLookaheadsWsAfterBracketOpenBracketOpen(SDF_Lookaheads arg, char * wsAfterBracketOpenBracketOpen)
{
  if (SDF_isLookaheadsList(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterBracketOpenBracketOpen, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Lookaheads has no WsAfterBracketOpenBracketOpen: %t\n", arg);
  return (SDF_Lookaheads)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadsList(SDF_Lookaheads arg) */

ATbool SDF_hasLookaheadsList(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_LookaheadList SDF_getLookaheadsList(SDF_Lookaheads arg) */

SDF_LookaheadList SDF_getLookaheadsList(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsList(arg)) {
    return (SDF_LookaheadList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2), 2);
  }

  ATabort("Lookaheads has no List: %t\n", arg);
  return (SDF_LookaheadList)NULL;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsList(SDF_Lookaheads arg, SDF_LookaheadList list) */

SDF_Lookaheads SDF_setLookaheadsList(SDF_Lookaheads arg, SDF_LookaheadList list)
{
  if (SDF_isLookaheadsList(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2), (ATerm)list, 2), 2), 2);
  }

  ATabort("Lookaheads has no List: %t\n", arg);
  return (SDF_Lookaheads)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadsWsAfterList(SDF_Lookaheads arg) */

ATbool SDF_hasLookaheadsWsAfterList(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getLookaheadsWsAfterList(SDF_Lookaheads arg) */

char * SDF_getLookaheadsWsAfterList(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsList(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Lookaheads has no WsAfterList: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsWsAfterList(SDF_Lookaheads arg, char * wsAfterList) */

SDF_Lookaheads SDF_setLookaheadsWsAfterList(SDF_Lookaheads arg, char * wsAfterList)
{
  if (SDF_isLookaheadsList(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterList, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Lookaheads has no WsAfterList: %t\n", arg);
  return (SDF_Lookaheads)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_LookaheadList accessors */

/*{{{  ATbool SDF_isValidLookaheadList(SDF_LookaheadList arg) */

ATbool SDF_isValidLookaheadList(SDF_LookaheadList arg)
{
  if (SDF_isLookaheadListEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isLookaheadListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isLookaheadListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isLookaheadListEmpty(SDF_LookaheadList arg) */

ATbool SDF_isLookaheadListEmpty(SDF_LookaheadList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternLookaheadListEmpty);
}

/*}}}  */
/*{{{  ATbool SDF_isLookaheadListSingle(SDF_LookaheadList arg) */

ATbool SDF_isLookaheadListSingle(SDF_LookaheadList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternLookaheadListSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isLookaheadListMany(SDF_LookaheadList arg) */

ATbool SDF_isLookaheadListMany(SDF_LookaheadList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternLookaheadListMany, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadListHead(SDF_LookaheadList arg) */

ATbool SDF_hasLookaheadListHead(SDF_LookaheadList arg)
{
  if (SDF_isLookaheadListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isLookaheadListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_getLookaheadListHead(SDF_LookaheadList arg) */

SDF_Lookahead SDF_getLookaheadListHead(SDF_LookaheadList arg)
{
  if (SDF_isLookaheadListSingle(arg)) {
    return (SDF_Lookahead)ATelementAt((ATermList)arg, 0);
  }
  else if (SDF_isLookaheadListMany(arg)) {
    return (SDF_Lookahead)ATelementAt((ATermList)arg, 0);
  }

  ATabort("LookaheadList has no Head: %t\n", arg);
  return (SDF_Lookahead)NULL;
}

/*}}}  */
/*{{{  SDF_LookaheadList SDF_setLookaheadListHead(SDF_LookaheadList arg, SDF_Lookahead head) */

SDF_LookaheadList SDF_setLookaheadListHead(SDF_LookaheadList arg, SDF_Lookahead head)
{
  if (SDF_isLookaheadListSingle(arg)) {
    return (SDF_LookaheadList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isLookaheadListMany(arg)) {
    return (SDF_LookaheadList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("LookaheadList has no Head: %t\n", arg);
  return (SDF_LookaheadList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadListWsAfterFirst(SDF_LookaheadList arg) */

ATbool SDF_hasLookaheadListWsAfterFirst(SDF_LookaheadList arg)
{
  if (SDF_isLookaheadListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getLookaheadListWsAfterFirst(SDF_LookaheadList arg) */

char * SDF_getLookaheadListWsAfterFirst(SDF_LookaheadList arg)
{
  if (SDF_isLookaheadListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0)));
  }

  ATabort("LookaheadList has no WsAfterFirst: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_LookaheadList SDF_setLookaheadListWsAfterFirst(SDF_LookaheadList arg, char * wsAfterFirst) */

SDF_LookaheadList SDF_setLookaheadListWsAfterFirst(SDF_LookaheadList arg, char * wsAfterFirst)
{
  if (SDF_isLookaheadListMany(arg)) {
    return (SDF_LookaheadList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterFirst, 0, ATtrue)), 0), 1);
  }

  ATabort("LookaheadList has no WsAfterFirst: %t\n", arg);
  return (SDF_LookaheadList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadListSep(SDF_LookaheadList arg) */

ATbool SDF_hasLookaheadListSep(SDF_LookaheadList arg)
{
  if (SDF_isLookaheadListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getLookaheadListSep(SDF_LookaheadList arg) */

char * SDF_getLookaheadListSep(SDF_LookaheadList arg)
{
  if (SDF_isLookaheadListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
  }

  ATabort("LookaheadList has no Sep: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_LookaheadList SDF_setLookaheadListSep(SDF_LookaheadList arg, char * sep) */

SDF_LookaheadList SDF_setLookaheadListSep(SDF_LookaheadList arg, char * sep)
{
  if (SDF_isLookaheadListMany(arg)) {
    return (SDF_LookaheadList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("LookaheadList has no Sep: %t\n", arg);
  return (SDF_LookaheadList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadListWsAfterSep(SDF_LookaheadList arg) */

ATbool SDF_hasLookaheadListWsAfterSep(SDF_LookaheadList arg)
{
  if (SDF_isLookaheadListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getLookaheadListWsAfterSep(SDF_LookaheadList arg) */

char * SDF_getLookaheadListWsAfterSep(SDF_LookaheadList arg)
{
  if (SDF_isLookaheadListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), 0)));
  }

  ATabort("LookaheadList has no WsAfterSep: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_LookaheadList SDF_setLookaheadListWsAfterSep(SDF_LookaheadList arg, char * wsAfterSep) */

SDF_LookaheadList SDF_setLookaheadListWsAfterSep(SDF_LookaheadList arg, char * wsAfterSep)
{
  if (SDF_isLookaheadListMany(arg)) {
    return (SDF_LookaheadList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSep, 0, ATtrue)), 0), 3);
  }

  ATabort("LookaheadList has no WsAfterSep: %t\n", arg);
  return (SDF_LookaheadList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadListTail(SDF_LookaheadList arg) */

ATbool SDF_hasLookaheadListTail(SDF_LookaheadList arg)
{
  if (SDF_isLookaheadListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_LookaheadList SDF_getLookaheadListTail(SDF_LookaheadList arg) */

SDF_LookaheadList SDF_getLookaheadListTail(SDF_LookaheadList arg)
{
  if (SDF_isLookaheadListMany(arg)) {
    return (SDF_LookaheadList)ATgetTail((ATermList)arg, 4);
  }

  ATabort("LookaheadList has no Tail: %t\n", arg);
  return (SDF_LookaheadList)NULL;
}

/*}}}  */
/*{{{  SDF_LookaheadList SDF_setLookaheadListTail(SDF_LookaheadList arg, SDF_LookaheadList tail) */

SDF_LookaheadList SDF_setLookaheadListTail(SDF_LookaheadList arg, SDF_LookaheadList tail)
{
  if (SDF_isLookaheadListMany(arg)) {
    return (SDF_LookaheadList)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("LookaheadList has no Tail: %t\n", arg);
  return (SDF_LookaheadList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Restriction accessors */

/*{{{  ATbool SDF_isValidRestriction(SDF_Restriction arg) */

ATbool SDF_isValidRestriction(SDF_Restriction arg)
{
  if (SDF_isRestrictionFollow(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isRestrictionFollow(SDF_Restriction arg) */

ATbool SDF_isRestrictionFollow(SDF_Restriction arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternRestrictionFollow, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasRestrictionSymbols(SDF_Restriction arg) */

ATbool SDF_hasRestrictionSymbols(SDF_Restriction arg)
{
  if (SDF_isRestrictionFollow(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbols SDF_getRestrictionSymbols(SDF_Restriction arg) */

SDF_Symbols SDF_getRestrictionSymbols(SDF_Restriction arg)
{
  if (SDF_isRestrictionFollow(arg)) {
    return (SDF_Symbols)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Restriction has no Symbols: %t\n", arg);
  return (SDF_Symbols)NULL;
}

/*}}}  */
/*{{{  SDF_Restriction SDF_setRestrictionSymbols(SDF_Restriction arg, SDF_Symbols Symbols) */

SDF_Restriction SDF_setRestrictionSymbols(SDF_Restriction arg, SDF_Symbols Symbols)
{
  if (SDF_isRestrictionFollow(arg)) {
    return (SDF_Restriction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Symbols, 0), 2);
  }

  ATabort("Restriction has no Symbols: %t\n", arg);
  return (SDF_Restriction)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasRestrictionWsAfterSymbols(SDF_Restriction arg) */

ATbool SDF_hasRestrictionWsAfterSymbols(SDF_Restriction arg)
{
  if (SDF_isRestrictionFollow(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getRestrictionWsAfterSymbols(SDF_Restriction arg) */

char * SDF_getRestrictionWsAfterSymbols(SDF_Restriction arg)
{
  if (SDF_isRestrictionFollow(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Restriction has no WsAfterSymbols: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Restriction SDF_setRestrictionWsAfterSymbols(SDF_Restriction arg, char * wsAfterSymbols) */

SDF_Restriction SDF_setRestrictionWsAfterSymbols(SDF_Restriction arg, char * wsAfterSymbols)
{
  if (SDF_isRestrictionFollow(arg)) {
    return (SDF_Restriction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSymbols, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Restriction has no WsAfterSymbols: %t\n", arg);
  return (SDF_Restriction)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasRestrictionWsAfterSlash(SDF_Restriction arg) */

ATbool SDF_hasRestrictionWsAfterSlash(SDF_Restriction arg)
{
  if (SDF_isRestrictionFollow(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getRestrictionWsAfterSlash(SDF_Restriction arg) */

char * SDF_getRestrictionWsAfterSlash(SDF_Restriction arg)
{
  if (SDF_isRestrictionFollow(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Restriction has no WsAfterSlash: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Restriction SDF_setRestrictionWsAfterSlash(SDF_Restriction arg, char * wsAfterSlash) */

SDF_Restriction SDF_setRestrictionWsAfterSlash(SDF_Restriction arg, char * wsAfterSlash)
{
  if (SDF_isRestrictionFollow(arg)) {
    return (SDF_Restriction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSlash, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Restriction has no WsAfterSlash: %t\n", arg);
  return (SDF_Restriction)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasRestrictionLookaheads(SDF_Restriction arg) */

ATbool SDF_hasRestrictionLookaheads(SDF_Restriction arg)
{
  if (SDF_isRestrictionFollow(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_getRestrictionLookaheads(SDF_Restriction arg) */

SDF_Lookaheads SDF_getRestrictionLookaheads(SDF_Restriction arg)
{
  if (SDF_isRestrictionFollow(arg)) {
    return (SDF_Lookaheads)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Restriction has no Lookaheads: %t\n", arg);
  return (SDF_Lookaheads)NULL;
}

/*}}}  */
/*{{{  SDF_Restriction SDF_setRestrictionLookaheads(SDF_Restriction arg, SDF_Lookaheads Lookaheads) */

SDF_Restriction SDF_setRestrictionLookaheads(SDF_Restriction arg, SDF_Lookaheads Lookaheads)
{
  if (SDF_isRestrictionFollow(arg)) {
    return (SDF_Restriction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Lookaheads, 4), 2);
  }

  ATabort("Restriction has no Lookaheads: %t\n", arg);
  return (SDF_Restriction)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Restrictions accessors */

/*{{{  ATbool SDF_isValidRestrictions(SDF_Restrictions arg) */

ATbool SDF_isValidRestrictions(SDF_Restrictions arg)
{
  if (SDF_isRestrictionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isRestrictionsDefault(SDF_Restrictions arg) */

ATbool SDF_isRestrictionsDefault(SDF_Restrictions arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternRestrictionsDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasRestrictionsList(SDF_Restrictions arg) */

ATbool SDF_hasRestrictionsList(SDF_Restrictions arg)
{
  if (SDF_isRestrictionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_RestrictionList SDF_getRestrictionsList(SDF_Restrictions arg) */

SDF_RestrictionList SDF_getRestrictionsList(SDF_Restrictions arg)
{
  if (SDF_isRestrictionsDefault(arg)) {
    return (SDF_RestrictionList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 2);
  }

  ATabort("Restrictions has no List: %t\n", arg);
  return (SDF_RestrictionList)NULL;
}

/*}}}  */
/*{{{  SDF_Restrictions SDF_setRestrictionsList(SDF_Restrictions arg, SDF_RestrictionList list) */

SDF_Restrictions SDF_setRestrictionsList(SDF_Restrictions arg, SDF_RestrictionList list)
{
  if (SDF_isRestrictionsDefault(arg)) {
    return (SDF_Restrictions)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)list, 2), 0), 2);
  }

  ATabort("Restrictions has no List: %t\n", arg);
  return (SDF_Restrictions)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_RestrictionList accessors */

/*{{{  ATbool SDF_isValidRestrictionList(SDF_RestrictionList arg) */

ATbool SDF_isValidRestrictionList(SDF_RestrictionList arg)
{
  if (SDF_isRestrictionListEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isRestrictionListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isRestrictionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isRestrictionListEmpty(SDF_RestrictionList arg) */

ATbool SDF_isRestrictionListEmpty(SDF_RestrictionList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternRestrictionListEmpty);
}

/*}}}  */
/*{{{  ATbool SDF_isRestrictionListSingle(SDF_RestrictionList arg) */

ATbool SDF_isRestrictionListSingle(SDF_RestrictionList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternRestrictionListSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isRestrictionListMany(SDF_RestrictionList arg) */

ATbool SDF_isRestrictionListMany(SDF_RestrictionList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternRestrictionListMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasRestrictionListHead(SDF_RestrictionList arg) */

ATbool SDF_hasRestrictionListHead(SDF_RestrictionList arg)
{
  if (SDF_isRestrictionListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isRestrictionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Restriction SDF_getRestrictionListHead(SDF_RestrictionList arg) */

SDF_Restriction SDF_getRestrictionListHead(SDF_RestrictionList arg)
{
  if (SDF_isRestrictionListSingle(arg)) {
    return (SDF_Restriction)ATelementAt((ATermList)arg, 0);
  }
  else if (SDF_isRestrictionListMany(arg)) {
    return (SDF_Restriction)ATelementAt((ATermList)arg, 0);
  }

  ATabort("RestrictionList has no Head: %t\n", arg);
  return (SDF_Restriction)NULL;
}

/*}}}  */
/*{{{  SDF_RestrictionList SDF_setRestrictionListHead(SDF_RestrictionList arg, SDF_Restriction head) */

SDF_RestrictionList SDF_setRestrictionListHead(SDF_RestrictionList arg, SDF_Restriction head)
{
  if (SDF_isRestrictionListSingle(arg)) {
    return (SDF_RestrictionList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isRestrictionListMany(arg)) {
    return (SDF_RestrictionList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("RestrictionList has no Head: %t\n", arg);
  return (SDF_RestrictionList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasRestrictionListWsAfterFirst(SDF_RestrictionList arg) */

ATbool SDF_hasRestrictionListWsAfterFirst(SDF_RestrictionList arg)
{
  if (SDF_isRestrictionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getRestrictionListWsAfterFirst(SDF_RestrictionList arg) */

char * SDF_getRestrictionListWsAfterFirst(SDF_RestrictionList arg)
{
  if (SDF_isRestrictionListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0)));
  }

  ATabort("RestrictionList has no WsAfterFirst: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_RestrictionList SDF_setRestrictionListWsAfterFirst(SDF_RestrictionList arg, char * wsAfterFirst) */

SDF_RestrictionList SDF_setRestrictionListWsAfterFirst(SDF_RestrictionList arg, char * wsAfterFirst)
{
  if (SDF_isRestrictionListMany(arg)) {
    return (SDF_RestrictionList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterFirst, 0, ATtrue)), 0), 1);
  }

  ATabort("RestrictionList has no WsAfterFirst: %t\n", arg);
  return (SDF_RestrictionList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasRestrictionListTail(SDF_RestrictionList arg) */

ATbool SDF_hasRestrictionListTail(SDF_RestrictionList arg)
{
  if (SDF_isRestrictionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_RestrictionList SDF_getRestrictionListTail(SDF_RestrictionList arg) */

SDF_RestrictionList SDF_getRestrictionListTail(SDF_RestrictionList arg)
{
  if (SDF_isRestrictionListMany(arg)) {
    return (SDF_RestrictionList)ATgetTail((ATermList)arg, 2);
  }

  ATabort("RestrictionList has no Tail: %t\n", arg);
  return (SDF_RestrictionList)NULL;
}

/*}}}  */
/*{{{  SDF_RestrictionList SDF_setRestrictionListTail(SDF_RestrictionList arg, SDF_RestrictionList tail) */

SDF_RestrictionList SDF_setRestrictionListTail(SDF_RestrictionList arg, SDF_RestrictionList tail)
{
  if (SDF_isRestrictionListMany(arg)) {
    return (SDF_RestrictionList)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("RestrictionList has no Tail: %t\n", arg);
  return (SDF_RestrictionList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Alias accessors */

/*{{{  ATbool SDF_isValidAlias(SDF_Alias arg) */

ATbool SDF_isValidAlias(SDF_Alias arg)
{
  if (SDF_isAliasAlias(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isAliasAlias(SDF_Alias arg) */

ATbool SDF_isAliasAlias(SDF_Alias arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAliasAlias, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasAliasSymbol(SDF_Alias arg) */

ATbool SDF_hasAliasSymbol(SDF_Alias arg)
{
  if (SDF_isAliasAlias(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_getAliasSymbol(SDF_Alias arg) */

SDF_Symbol SDF_getAliasSymbol(SDF_Alias arg)
{
  if (SDF_isAliasAlias(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Alias has no Symbol: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  SDF_Alias SDF_setAliasSymbol(SDF_Alias arg, SDF_Symbol Symbol) */

SDF_Alias SDF_setAliasSymbol(SDF_Alias arg, SDF_Symbol Symbol)
{
  if (SDF_isAliasAlias(arg)) {
    return (SDF_Alias)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Symbol, 0), 2);
  }

  ATabort("Alias has no Symbol: %t\n", arg);
  return (SDF_Alias)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAliasWsAfterSymbol(SDF_Alias arg) */

ATbool SDF_hasAliasWsAfterSymbol(SDF_Alias arg)
{
  if (SDF_isAliasAlias(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getAliasWsAfterSymbol(SDF_Alias arg) */

char * SDF_getAliasWsAfterSymbol(SDF_Alias arg)
{
  if (SDF_isAliasAlias(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Alias has no WsAfterSymbol: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Alias SDF_setAliasWsAfterSymbol(SDF_Alias arg, char * wsAfterSymbol) */

SDF_Alias SDF_setAliasWsAfterSymbol(SDF_Alias arg, char * wsAfterSymbol)
{
  if (SDF_isAliasAlias(arg)) {
    return (SDF_Alias)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSymbol, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Alias has no WsAfterSymbol: %t\n", arg);
  return (SDF_Alias)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAliasWsAfterArrow(SDF_Alias arg) */

ATbool SDF_hasAliasWsAfterArrow(SDF_Alias arg)
{
  if (SDF_isAliasAlias(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getAliasWsAfterArrow(SDF_Alias arg) */

char * SDF_getAliasWsAfterArrow(SDF_Alias arg)
{
  if (SDF_isAliasAlias(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Alias has no WsAfterArrow: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Alias SDF_setAliasWsAfterArrow(SDF_Alias arg, char * wsAfterArrow) */

SDF_Alias SDF_setAliasWsAfterArrow(SDF_Alias arg, char * wsAfterArrow)
{
  if (SDF_isAliasAlias(arg)) {
    return (SDF_Alias)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterArrow, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Alias has no WsAfterArrow: %t\n", arg);
  return (SDF_Alias)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAliasAlias(SDF_Alias arg) */

ATbool SDF_hasAliasAlias(SDF_Alias arg)
{
  if (SDF_isAliasAlias(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_getAliasAlias(SDF_Alias arg) */

SDF_Symbol SDF_getAliasAlias(SDF_Alias arg)
{
  if (SDF_isAliasAlias(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Alias has no Alias: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  SDF_Alias SDF_setAliasAlias(SDF_Alias arg, SDF_Symbol alias) */

SDF_Alias SDF_setAliasAlias(SDF_Alias arg, SDF_Symbol alias)
{
  if (SDF_isAliasAlias(arg)) {
    return (SDF_Alias)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)alias, 4), 2);
  }

  ATabort("Alias has no Alias: %t\n", arg);
  return (SDF_Alias)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Aliases accessors */

/*{{{  ATbool SDF_isValidAliases(SDF_Aliases arg) */

ATbool SDF_isValidAliases(SDF_Aliases arg)
{
  if (SDF_isAliasesDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isAliasesDefault(SDF_Aliases arg) */

ATbool SDF_isAliasesDefault(SDF_Aliases arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAliasesDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasAliasesList(SDF_Aliases arg) */

ATbool SDF_hasAliasesList(SDF_Aliases arg)
{
  if (SDF_isAliasesDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_AliasList SDF_getAliasesList(SDF_Aliases arg) */

SDF_AliasList SDF_getAliasesList(SDF_Aliases arg)
{
  if (SDF_isAliasesDefault(arg)) {
    return (SDF_AliasList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 2);
  }

  ATabort("Aliases has no List: %t\n", arg);
  return (SDF_AliasList)NULL;
}

/*}}}  */
/*{{{  SDF_Aliases SDF_setAliasesList(SDF_Aliases arg, SDF_AliasList list) */

SDF_Aliases SDF_setAliasesList(SDF_Aliases arg, SDF_AliasList list)
{
  if (SDF_isAliasesDefault(arg)) {
    return (SDF_Aliases)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)list, 2), 0), 2);
  }

  ATabort("Aliases has no List: %t\n", arg);
  return (SDF_Aliases)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_AliasList accessors */

/*{{{  ATbool SDF_isValidAliasList(SDF_AliasList arg) */

ATbool SDF_isValidAliasList(SDF_AliasList arg)
{
  if (SDF_isAliasListEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isAliasListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isAliasListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isAliasListEmpty(SDF_AliasList arg) */

ATbool SDF_isAliasListEmpty(SDF_AliasList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAliasListEmpty);
}

/*}}}  */
/*{{{  ATbool SDF_isAliasListSingle(SDF_AliasList arg) */

ATbool SDF_isAliasListSingle(SDF_AliasList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAliasListSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isAliasListMany(SDF_AliasList arg) */

ATbool SDF_isAliasListMany(SDF_AliasList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAliasListMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasAliasListHead(SDF_AliasList arg) */

ATbool SDF_hasAliasListHead(SDF_AliasList arg)
{
  if (SDF_isAliasListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isAliasListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Alias SDF_getAliasListHead(SDF_AliasList arg) */

SDF_Alias SDF_getAliasListHead(SDF_AliasList arg)
{
  if (SDF_isAliasListSingle(arg)) {
    return (SDF_Alias)ATelementAt((ATermList)arg, 0);
  }
  else if (SDF_isAliasListMany(arg)) {
    return (SDF_Alias)ATelementAt((ATermList)arg, 0);
  }

  ATabort("AliasList has no Head: %t\n", arg);
  return (SDF_Alias)NULL;
}

/*}}}  */
/*{{{  SDF_AliasList SDF_setAliasListHead(SDF_AliasList arg, SDF_Alias head) */

SDF_AliasList SDF_setAliasListHead(SDF_AliasList arg, SDF_Alias head)
{
  if (SDF_isAliasListSingle(arg)) {
    return (SDF_AliasList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isAliasListMany(arg)) {
    return (SDF_AliasList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("AliasList has no Head: %t\n", arg);
  return (SDF_AliasList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAliasListWsAfterFirst(SDF_AliasList arg) */

ATbool SDF_hasAliasListWsAfterFirst(SDF_AliasList arg)
{
  if (SDF_isAliasListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getAliasListWsAfterFirst(SDF_AliasList arg) */

char * SDF_getAliasListWsAfterFirst(SDF_AliasList arg)
{
  if (SDF_isAliasListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0)));
  }

  ATabort("AliasList has no WsAfterFirst: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_AliasList SDF_setAliasListWsAfterFirst(SDF_AliasList arg, char * wsAfterFirst) */

SDF_AliasList SDF_setAliasListWsAfterFirst(SDF_AliasList arg, char * wsAfterFirst)
{
  if (SDF_isAliasListMany(arg)) {
    return (SDF_AliasList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterFirst, 0, ATtrue)), 0), 1);
  }

  ATabort("AliasList has no WsAfterFirst: %t\n", arg);
  return (SDF_AliasList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAliasListTail(SDF_AliasList arg) */

ATbool SDF_hasAliasListTail(SDF_AliasList arg)
{
  if (SDF_isAliasListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_AliasList SDF_getAliasListTail(SDF_AliasList arg) */

SDF_AliasList SDF_getAliasListTail(SDF_AliasList arg)
{
  if (SDF_isAliasListMany(arg)) {
    return (SDF_AliasList)ATgetTail((ATermList)arg, 2);
  }

  ATabort("AliasList has no Tail: %t\n", arg);
  return (SDF_AliasList)NULL;
}

/*}}}  */
/*{{{  SDF_AliasList SDF_setAliasListTail(SDF_AliasList arg, SDF_AliasList tail) */

SDF_AliasList SDF_setAliasListTail(SDF_AliasList arg, SDF_AliasList tail)
{
  if (SDF_isAliasListMany(arg)) {
    return (SDF_AliasList)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("AliasList has no Tail: %t\n", arg);
  return (SDF_AliasList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Symbols accessors */

/*{{{  ATbool SDF_isValidSymbols(SDF_Symbols arg) */

ATbool SDF_isValidSymbols(SDF_Symbols arg)
{
  if (SDF_isSymbolsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolsDefault(SDF_Symbols arg) */

ATbool SDF_isSymbolsDefault(SDF_Symbols arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolsDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolsList(SDF_Symbols arg) */

ATbool SDF_hasSymbolsList(SDF_Symbols arg)
{
  if (SDF_isSymbolsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_SymbolList SDF_getSymbolsList(SDF_Symbols arg) */

SDF_SymbolList SDF_getSymbolsList(SDF_Symbols arg)
{
  if (SDF_isSymbolsDefault(arg)) {
    return (SDF_SymbolList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 2);
  }

  ATabort("Symbols has no List: %t\n", arg);
  return (SDF_SymbolList)NULL;
}

/*}}}  */
/*{{{  SDF_Symbols SDF_setSymbolsList(SDF_Symbols arg, SDF_SymbolList list) */

SDF_Symbols SDF_setSymbolsList(SDF_Symbols arg, SDF_SymbolList list)
{
  if (SDF_isSymbolsDefault(arg)) {
    return (SDF_Symbols)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)list, 2), 0), 2);
  }

  ATabort("Symbols has no List: %t\n", arg);
  return (SDF_Symbols)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_SymbolList accessors */

/*{{{  ATbool SDF_isValidSymbolList(SDF_SymbolList arg) */

ATbool SDF_isValidSymbolList(SDF_SymbolList arg)
{
  if (SDF_isSymbolListEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolListEmpty(SDF_SymbolList arg) */

ATbool SDF_isSymbolListEmpty(SDF_SymbolList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolListEmpty);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolListSingle(SDF_SymbolList arg) */

ATbool SDF_isSymbolListSingle(SDF_SymbolList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolListSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolListMany(SDF_SymbolList arg) */

ATbool SDF_isSymbolListMany(SDF_SymbolList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolListMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolListHead(SDF_SymbolList arg) */

ATbool SDF_hasSymbolListHead(SDF_SymbolList arg)
{
  if (SDF_isSymbolListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_getSymbolListHead(SDF_SymbolList arg) */

SDF_Symbol SDF_getSymbolListHead(SDF_SymbolList arg)
{
  if (SDF_isSymbolListSingle(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)arg, 0);
  }
  else if (SDF_isSymbolListMany(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)arg, 0);
  }

  ATabort("SymbolList has no Head: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  SDF_SymbolList SDF_setSymbolListHead(SDF_SymbolList arg, SDF_Symbol head) */

SDF_SymbolList SDF_setSymbolListHead(SDF_SymbolList arg, SDF_Symbol head)
{
  if (SDF_isSymbolListSingle(arg)) {
    return (SDF_SymbolList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isSymbolListMany(arg)) {
    return (SDF_SymbolList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("SymbolList has no Head: %t\n", arg);
  return (SDF_SymbolList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolListWsAfterFirst(SDF_SymbolList arg) */

ATbool SDF_hasSymbolListWsAfterFirst(SDF_SymbolList arg)
{
  if (SDF_isSymbolListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolListWsAfterFirst(SDF_SymbolList arg) */

char * SDF_getSymbolListWsAfterFirst(SDF_SymbolList arg)
{
  if (SDF_isSymbolListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0)));
  }

  ATabort("SymbolList has no WsAfterFirst: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_SymbolList SDF_setSymbolListWsAfterFirst(SDF_SymbolList arg, char * wsAfterFirst) */

SDF_SymbolList SDF_setSymbolListWsAfterFirst(SDF_SymbolList arg, char * wsAfterFirst)
{
  if (SDF_isSymbolListMany(arg)) {
    return (SDF_SymbolList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterFirst, 0, ATtrue)), 0), 1);
  }

  ATabort("SymbolList has no WsAfterFirst: %t\n", arg);
  return (SDF_SymbolList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolListTail(SDF_SymbolList arg) */

ATbool SDF_hasSymbolListTail(SDF_SymbolList arg)
{
  if (SDF_isSymbolListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_SymbolList SDF_getSymbolListTail(SDF_SymbolList arg) */

SDF_SymbolList SDF_getSymbolListTail(SDF_SymbolList arg)
{
  if (SDF_isSymbolListMany(arg)) {
    return (SDF_SymbolList)ATgetTail((ATermList)arg, 2);
  }

  ATabort("SymbolList has no Tail: %t\n", arg);
  return (SDF_SymbolList)NULL;
}

/*}}}  */
/*{{{  SDF_SymbolList SDF_setSymbolListTail(SDF_SymbolList arg, SDF_SymbolList tail) */

SDF_SymbolList SDF_setSymbolListTail(SDF_SymbolList arg, SDF_SymbolList tail)
{
  if (SDF_isSymbolListMany(arg)) {
    return (SDF_SymbolList)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("SymbolList has no Tail: %t\n", arg);
  return (SDF_SymbolList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Renamings accessors */

/*{{{  ATbool SDF_isValidRenamings(SDF_Renamings arg) */

ATbool SDF_isValidRenamings(SDF_Renamings arg)
{
  if (SDF_isRenamingsRenamings(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isRenamingsRenamings(SDF_Renamings arg) */

ATbool SDF_isRenamingsRenamings(SDF_Renamings arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternRenamingsRenamings, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasRenamingsWsAfterBracketOpen(SDF_Renamings arg) */

ATbool SDF_hasRenamingsWsAfterBracketOpen(SDF_Renamings arg)
{
  if (SDF_isRenamingsRenamings(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getRenamingsWsAfterBracketOpen(SDF_Renamings arg) */

char * SDF_getRenamingsWsAfterBracketOpen(SDF_Renamings arg)
{
  if (SDF_isRenamingsRenamings(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Renamings has no WsAfterBracketOpen: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Renamings SDF_setRenamingsWsAfterBracketOpen(SDF_Renamings arg, char * wsAfterBracketOpen) */

SDF_Renamings SDF_setRenamingsWsAfterBracketOpen(SDF_Renamings arg, char * wsAfterBracketOpen)
{
  if (SDF_isRenamingsRenamings(arg)) {
    return (SDF_Renamings)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterBracketOpen, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Renamings has no WsAfterBracketOpen: %t\n", arg);
  return (SDF_Renamings)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasRenamingsList(SDF_Renamings arg) */

ATbool SDF_hasRenamingsList(SDF_Renamings arg)
{
  if (SDF_isRenamingsRenamings(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_RenamingList SDF_getRenamingsList(SDF_Renamings arg) */

SDF_RenamingList SDF_getRenamingsList(SDF_Renamings arg)
{
  if (SDF_isRenamingsRenamings(arg)) {
    return (SDF_RenamingList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2), 2);
  }

  ATabort("Renamings has no List: %t\n", arg);
  return (SDF_RenamingList)NULL;
}

/*}}}  */
/*{{{  SDF_Renamings SDF_setRenamingsList(SDF_Renamings arg, SDF_RenamingList list) */

SDF_Renamings SDF_setRenamingsList(SDF_Renamings arg, SDF_RenamingList list)
{
  if (SDF_isRenamingsRenamings(arg)) {
    return (SDF_Renamings)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2), (ATerm)list, 2), 2), 2);
  }

  ATabort("Renamings has no List: %t\n", arg);
  return (SDF_Renamings)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasRenamingsWsAfterList(SDF_Renamings arg) */

ATbool SDF_hasRenamingsWsAfterList(SDF_Renamings arg)
{
  if (SDF_isRenamingsRenamings(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getRenamingsWsAfterList(SDF_Renamings arg) */

char * SDF_getRenamingsWsAfterList(SDF_Renamings arg)
{
  if (SDF_isRenamingsRenamings(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Renamings has no WsAfterList: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Renamings SDF_setRenamingsWsAfterList(SDF_Renamings arg, char * wsAfterList) */

SDF_Renamings SDF_setRenamingsWsAfterList(SDF_Renamings arg, char * wsAfterList)
{
  if (SDF_isRenamingsRenamings(arg)) {
    return (SDF_Renamings)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterList, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Renamings has no WsAfterList: %t\n", arg);
  return (SDF_Renamings)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_RenamingList accessors */

/*{{{  ATbool SDF_isValidRenamingList(SDF_RenamingList arg) */

ATbool SDF_isValidRenamingList(SDF_RenamingList arg)
{
  if (SDF_isRenamingListEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isRenamingListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isRenamingListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isRenamingListEmpty(SDF_RenamingList arg) */

ATbool SDF_isRenamingListEmpty(SDF_RenamingList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternRenamingListEmpty);
}

/*}}}  */
/*{{{  ATbool SDF_isRenamingListSingle(SDF_RenamingList arg) */

ATbool SDF_isRenamingListSingle(SDF_RenamingList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternRenamingListSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isRenamingListMany(SDF_RenamingList arg) */

ATbool SDF_isRenamingListMany(SDF_RenamingList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternRenamingListMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasRenamingListHead(SDF_RenamingList arg) */

ATbool SDF_hasRenamingListHead(SDF_RenamingList arg)
{
  if (SDF_isRenamingListSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isRenamingListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Renaming SDF_getRenamingListHead(SDF_RenamingList arg) */

SDF_Renaming SDF_getRenamingListHead(SDF_RenamingList arg)
{
  if (SDF_isRenamingListSingle(arg)) {
    return (SDF_Renaming)ATelementAt((ATermList)arg, 0);
  }
  else if (SDF_isRenamingListMany(arg)) {
    return (SDF_Renaming)ATelementAt((ATermList)arg, 0);
  }

  ATabort("RenamingList has no Head: %t\n", arg);
  return (SDF_Renaming)NULL;
}

/*}}}  */
/*{{{  SDF_RenamingList SDF_setRenamingListHead(SDF_RenamingList arg, SDF_Renaming head) */

SDF_RenamingList SDF_setRenamingListHead(SDF_RenamingList arg, SDF_Renaming head)
{
  if (SDF_isRenamingListSingle(arg)) {
    return (SDF_RenamingList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isRenamingListMany(arg)) {
    return (SDF_RenamingList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("RenamingList has no Head: %t\n", arg);
  return (SDF_RenamingList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasRenamingListWsAfterFirst(SDF_RenamingList arg) */

ATbool SDF_hasRenamingListWsAfterFirst(SDF_RenamingList arg)
{
  if (SDF_isRenamingListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getRenamingListWsAfterFirst(SDF_RenamingList arg) */

char * SDF_getRenamingListWsAfterFirst(SDF_RenamingList arg)
{
  if (SDF_isRenamingListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0)));
  }

  ATabort("RenamingList has no WsAfterFirst: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_RenamingList SDF_setRenamingListWsAfterFirst(SDF_RenamingList arg, char * wsAfterFirst) */

SDF_RenamingList SDF_setRenamingListWsAfterFirst(SDF_RenamingList arg, char * wsAfterFirst)
{
  if (SDF_isRenamingListMany(arg)) {
    return (SDF_RenamingList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterFirst, 0, ATtrue)), 0), 1);
  }

  ATabort("RenamingList has no WsAfterFirst: %t\n", arg);
  return (SDF_RenamingList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasRenamingListTail(SDF_RenamingList arg) */

ATbool SDF_hasRenamingListTail(SDF_RenamingList arg)
{
  if (SDF_isRenamingListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_RenamingList SDF_getRenamingListTail(SDF_RenamingList arg) */

SDF_RenamingList SDF_getRenamingListTail(SDF_RenamingList arg)
{
  if (SDF_isRenamingListMany(arg)) {
    return (SDF_RenamingList)ATgetTail((ATermList)arg, 2);
  }

  ATabort("RenamingList has no Tail: %t\n", arg);
  return (SDF_RenamingList)NULL;
}

/*}}}  */
/*{{{  SDF_RenamingList SDF_setRenamingListTail(SDF_RenamingList arg, SDF_RenamingList tail) */

SDF_RenamingList SDF_setRenamingListTail(SDF_RenamingList arg, SDF_RenamingList tail)
{
  if (SDF_isRenamingListMany(arg)) {
    return (SDF_RenamingList)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("RenamingList has no Tail: %t\n", arg);
  return (SDF_RenamingList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Renaming accessors */

/*{{{  ATbool SDF_isValidRenaming(SDF_Renaming arg) */

ATbool SDF_isValidRenaming(SDF_Renaming arg)
{
  if (SDF_isRenamingSymbol(arg)) {
    return ATtrue;
  }
  else if (SDF_isRenamingProduction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isRenamingSymbol(SDF_Renaming arg) */

ATbool SDF_isRenamingSymbol(SDF_Renaming arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternRenamingSymbol, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isRenamingProduction(SDF_Renaming arg) */

ATbool SDF_isRenamingProduction(SDF_Renaming arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternRenamingProduction, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasRenamingFrom(SDF_Renaming arg) */

ATbool SDF_hasRenamingFrom(SDF_Renaming arg)
{
  if (SDF_isRenamingSymbol(arg)) {
    return ATtrue;
  }
  else if (SDF_isRenamingProduction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_getRenamingFrom(SDF_Renaming arg) */

SDF_Symbol SDF_getRenamingFrom(SDF_Renaming arg)
{
  if (SDF_isRenamingSymbol(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDF_isRenamingProduction(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Renaming has no From: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  SDF_Renaming SDF_setRenamingFrom(SDF_Renaming arg, SDF_Symbol from) */

SDF_Renaming SDF_setRenamingFrom(SDF_Renaming arg, SDF_Symbol from)
{
  if (SDF_isRenamingSymbol(arg)) {
    return (SDF_Renaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)from, 0), 2);
  }
  else if (SDF_isRenamingProduction(arg)) {
    return (SDF_Renaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)from, 0), 2);
  }

  ATabort("Renaming has no From: %t\n", arg);
  return (SDF_Renaming)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasRenamingWsAfterFrom(SDF_Renaming arg) */

ATbool SDF_hasRenamingWsAfterFrom(SDF_Renaming arg)
{
  if (SDF_isRenamingSymbol(arg)) {
    return ATtrue;
  }
  else if (SDF_isRenamingProduction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getRenamingWsAfterFrom(SDF_Renaming arg) */

char * SDF_getRenamingWsAfterFrom(SDF_Renaming arg)
{
  if (SDF_isRenamingSymbol(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isRenamingProduction(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Renaming has no WsAfterFrom: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Renaming SDF_setRenamingWsAfterFrom(SDF_Renaming arg, char * wsAfterFrom) */

SDF_Renaming SDF_setRenamingWsAfterFrom(SDF_Renaming arg, char * wsAfterFrom)
{
  if (SDF_isRenamingSymbol(arg)) {
    return (SDF_Renaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterFrom, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isRenamingProduction(arg)) {
    return (SDF_Renaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterFrom, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Renaming has no WsAfterFrom: %t\n", arg);
  return (SDF_Renaming)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasRenamingWsAfterEqualsGreaterThan(SDF_Renaming arg) */

ATbool SDF_hasRenamingWsAfterEqualsGreaterThan(SDF_Renaming arg)
{
  if (SDF_isRenamingSymbol(arg)) {
    return ATtrue;
  }
  else if (SDF_isRenamingProduction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getRenamingWsAfterEqualsGreaterThan(SDF_Renaming arg) */

char * SDF_getRenamingWsAfterEqualsGreaterThan(SDF_Renaming arg)
{
  if (SDF_isRenamingSymbol(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }
  else if (SDF_isRenamingProduction(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Renaming has no WsAfterEqualsGreaterThan: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Renaming SDF_setRenamingWsAfterEqualsGreaterThan(SDF_Renaming arg, char * wsAfterEqualsGreaterThan) */

SDF_Renaming SDF_setRenamingWsAfterEqualsGreaterThan(SDF_Renaming arg, char * wsAfterEqualsGreaterThan)
{
  if (SDF_isRenamingSymbol(arg)) {
    return (SDF_Renaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterEqualsGreaterThan, 0, ATtrue)), 0), 3), 2);
  }
  else if (SDF_isRenamingProduction(arg)) {
    return (SDF_Renaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterEqualsGreaterThan, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Renaming has no WsAfterEqualsGreaterThan: %t\n", arg);
  return (SDF_Renaming)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasRenamingTo(SDF_Renaming arg) */

ATbool SDF_hasRenamingTo(SDF_Renaming arg)
{
  if (SDF_isRenamingSymbol(arg)) {
    return ATtrue;
  }
  else if (SDF_isRenamingProduction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_getRenamingTo(SDF_Renaming arg) */

SDF_Symbol SDF_getRenamingTo(SDF_Renaming arg)
{
  if (SDF_isRenamingSymbol(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDF_isRenamingProduction(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Renaming has no To: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  SDF_Renaming SDF_setRenamingTo(SDF_Renaming arg, SDF_Symbol to) */

SDF_Renaming SDF_setRenamingTo(SDF_Renaming arg, SDF_Symbol to)
{
  if (SDF_isRenamingSymbol(arg)) {
    return (SDF_Renaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)to, 4), 2);
  }
  else if (SDF_isRenamingProduction(arg)) {
    return (SDF_Renaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)to, 4), 2);
  }

  ATabort("Renaming has no To: %t\n", arg);
  return (SDF_Renaming)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_NatCon accessors */

/*{{{  ATbool SDF_isValidNatCon(SDF_NatCon arg) */

ATbool SDF_isValidNatCon(SDF_NatCon arg)
{
  if (SDF_isNatConDigits(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isNatConDigits(SDF_NatCon arg) */

ATbool SDF_isNatConDigits(SDF_NatCon arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternNatConDigits, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasNatConLex(SDF_NatCon arg) */

ATbool SDF_hasNatConLex(SDF_NatCon arg)
{
  if (SDF_isNatConDigits(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getNatConLex(SDF_NatCon arg) */

char * SDF_getNatConLex(SDF_NatCon arg)
{
  if (SDF_isNatConDigits(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }

  ATabort("NatCon has no Lex: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_NatCon SDF_setNatConLex(SDF_NatCon arg, char * lex) */

SDF_NatCon SDF_setNatConLex(SDF_NatCon arg, char * lex)
{
  if (SDF_isNatConDigits(arg)) {
    return (SDF_NatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }

  ATabort("NatCon has no Lex: %t\n", arg);
  return (SDF_NatCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_IntCon accessors */

/*{{{  ATbool SDF_isValidIntCon(SDF_IntCon arg) */

ATbool SDF_isValidIntCon(SDF_IntCon arg)
{
  if (SDF_isIntConNatural(arg)) {
    return ATtrue;
  }
  else if (SDF_isIntConPositive(arg)) {
    return ATtrue;
  }
  else if (SDF_isIntConNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isIntConNatural(SDF_IntCon arg) */

ATbool SDF_isIntConNatural(SDF_IntCon arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternIntConNatural, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isIntConPositive(SDF_IntCon arg) */

ATbool SDF_isIntConPositive(SDF_IntCon arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternIntConPositive, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isIntConNegative(SDF_IntCon arg) */

ATbool SDF_isIntConNegative(SDF_IntCon arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternIntConNegative, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasIntConNatCon(SDF_IntCon arg) */

ATbool SDF_hasIntConNatCon(SDF_IntCon arg)
{
  if (SDF_isIntConNatural(arg)) {
    return ATtrue;
  }
  else if (SDF_isIntConPositive(arg)) {
    return ATtrue;
  }
  else if (SDF_isIntConNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_NatCon SDF_getIntConNatCon(SDF_IntCon arg) */

SDF_NatCon SDF_getIntConNatCon(SDF_IntCon arg)
{
  if (SDF_isIntConNatural(arg)) {
    return (SDF_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDF_isIntConPositive(arg)) {
    return (SDF_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDF_isIntConNegative(arg)) {
    return (SDF_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("IntCon has no NatCon: %t\n", arg);
  return (SDF_NatCon)NULL;
}

/*}}}  */
/*{{{  SDF_IntCon SDF_setIntConNatCon(SDF_IntCon arg, SDF_NatCon NatCon) */

SDF_IntCon SDF_setIntConNatCon(SDF_IntCon arg, SDF_NatCon NatCon)
{
  if (SDF_isIntConNatural(arg)) {
    return (SDF_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)NatCon, 0), 2);
  }
  else if (SDF_isIntConPositive(arg)) {
    return (SDF_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)NatCon, 2), 2);
  }
  else if (SDF_isIntConNegative(arg)) {
    return (SDF_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)NatCon, 2), 2);
  }

  ATabort("IntCon has no NatCon: %t\n", arg);
  return (SDF_IntCon)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasIntConWsAfterPos(SDF_IntCon arg) */

ATbool SDF_hasIntConWsAfterPos(SDF_IntCon arg)
{
  if (SDF_isIntConPositive(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getIntConWsAfterPos(SDF_IntCon arg) */

char * SDF_getIntConWsAfterPos(SDF_IntCon arg)
{
  if (SDF_isIntConPositive(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("IntCon has no WsAfterPos: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_IntCon SDF_setIntConWsAfterPos(SDF_IntCon arg, char * wsAfterPos) */

SDF_IntCon SDF_setIntConWsAfterPos(SDF_IntCon arg, char * wsAfterPos)
{
  if (SDF_isIntConPositive(arg)) {
    return (SDF_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterPos, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("IntCon has no WsAfterPos: %t\n", arg);
  return (SDF_IntCon)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasIntConWsAfterNeg(SDF_IntCon arg) */

ATbool SDF_hasIntConWsAfterNeg(SDF_IntCon arg)
{
  if (SDF_isIntConNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getIntConWsAfterNeg(SDF_IntCon arg) */

char * SDF_getIntConWsAfterNeg(SDF_IntCon arg)
{
  if (SDF_isIntConNegative(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("IntCon has no WsAfterNeg: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_IntCon SDF_setIntConWsAfterNeg(SDF_IntCon arg, char * wsAfterNeg) */

SDF_IntCon SDF_setIntConWsAfterNeg(SDF_IntCon arg, char * wsAfterNeg)
{
  if (SDF_isIntConNegative(arg)) {
    return (SDF_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterNeg, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("IntCon has no WsAfterNeg: %t\n", arg);
  return (SDF_IntCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_CharRange accessors */

/*{{{  ATbool SDF_isValidCharRange(SDF_CharRange arg) */

ATbool SDF_isValidCharRange(SDF_CharRange arg)
{
  if (SDF_isCharRangeDefault(arg)) {
    return ATtrue;
  }
  else if (SDF_isCharRangeRange(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isCharRangeDefault(SDF_CharRange arg) */

ATbool SDF_isCharRangeDefault(SDF_CharRange arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternCharRangeDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isCharRangeRange(SDF_CharRange arg) */

ATbool SDF_isCharRangeRange(SDF_CharRange arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternCharRangeRange, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasCharRangeCharacter(SDF_CharRange arg) */

ATbool SDF_hasCharRangeCharacter(SDF_CharRange arg)
{
  if (SDF_isCharRangeDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Character SDF_getCharRangeCharacter(SDF_CharRange arg) */

SDF_Character SDF_getCharRangeCharacter(SDF_CharRange arg)
{
  if (SDF_isCharRangeDefault(arg)) {
    return (SDF_Character)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("CharRange has no Character: %t\n", arg);
  return (SDF_Character)NULL;
}

/*}}}  */
/*{{{  SDF_CharRange SDF_setCharRangeCharacter(SDF_CharRange arg, SDF_Character Character) */

SDF_CharRange SDF_setCharRangeCharacter(SDF_CharRange arg, SDF_Character Character)
{
  if (SDF_isCharRangeDefault(arg)) {
    return (SDF_CharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Character, 0), 2);
  }

  ATabort("CharRange has no Character: %t\n", arg);
  return (SDF_CharRange)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasCharRangeStart(SDF_CharRange arg) */

ATbool SDF_hasCharRangeStart(SDF_CharRange arg)
{
  if (SDF_isCharRangeRange(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Character SDF_getCharRangeStart(SDF_CharRange arg) */

SDF_Character SDF_getCharRangeStart(SDF_CharRange arg)
{
  if (SDF_isCharRangeRange(arg)) {
    return (SDF_Character)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("CharRange has no Start: %t\n", arg);
  return (SDF_Character)NULL;
}

/*}}}  */
/*{{{  SDF_CharRange SDF_setCharRangeStart(SDF_CharRange arg, SDF_Character start) */

SDF_CharRange SDF_setCharRangeStart(SDF_CharRange arg, SDF_Character start)
{
  if (SDF_isCharRangeRange(arg)) {
    return (SDF_CharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)start, 0), 2);
  }

  ATabort("CharRange has no Start: %t\n", arg);
  return (SDF_CharRange)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasCharRangeWsAfterStart(SDF_CharRange arg) */

ATbool SDF_hasCharRangeWsAfterStart(SDF_CharRange arg)
{
  if (SDF_isCharRangeRange(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getCharRangeWsAfterStart(SDF_CharRange arg) */

char * SDF_getCharRangeWsAfterStart(SDF_CharRange arg)
{
  if (SDF_isCharRangeRange(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("CharRange has no WsAfterStart: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_CharRange SDF_setCharRangeWsAfterStart(SDF_CharRange arg, char * wsAfterStart) */

SDF_CharRange SDF_setCharRangeWsAfterStart(SDF_CharRange arg, char * wsAfterStart)
{
  if (SDF_isCharRangeRange(arg)) {
    return (SDF_CharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterStart, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("CharRange has no WsAfterStart: %t\n", arg);
  return (SDF_CharRange)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasCharRangeWsAfter(SDF_CharRange arg) */

ATbool SDF_hasCharRangeWsAfter(SDF_CharRange arg)
{
  if (SDF_isCharRangeRange(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getCharRangeWsAfter(SDF_CharRange arg) */

char * SDF_getCharRangeWsAfter(SDF_CharRange arg)
{
  if (SDF_isCharRangeRange(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("CharRange has no WsAfter: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_CharRange SDF_setCharRangeWsAfter(SDF_CharRange arg, char * wsAfter) */

SDF_CharRange SDF_setCharRangeWsAfter(SDF_CharRange arg, char * wsAfter)
{
  if (SDF_isCharRangeRange(arg)) {
    return (SDF_CharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfter, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("CharRange has no WsAfter: %t\n", arg);
  return (SDF_CharRange)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasCharRangeEnd(SDF_CharRange arg) */

ATbool SDF_hasCharRangeEnd(SDF_CharRange arg)
{
  if (SDF_isCharRangeRange(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Character SDF_getCharRangeEnd(SDF_CharRange arg) */

SDF_Character SDF_getCharRangeEnd(SDF_CharRange arg)
{
  if (SDF_isCharRangeRange(arg)) {
    return (SDF_Character)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("CharRange has no End: %t\n", arg);
  return (SDF_Character)NULL;
}

/*}}}  */
/*{{{  SDF_CharRange SDF_setCharRangeEnd(SDF_CharRange arg, SDF_Character end) */

SDF_CharRange SDF_setCharRangeEnd(SDF_CharRange arg, SDF_Character end)
{
  if (SDF_isCharRangeRange(arg)) {
    return (SDF_CharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)end, 4), 2);
  }

  ATabort("CharRange has no End: %t\n", arg);
  return (SDF_CharRange)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_CharRanges accessors */

/*{{{  ATbool SDF_isValidCharRanges(SDF_CharRanges arg) */

ATbool SDF_isValidCharRanges(SDF_CharRanges arg)
{
  if (SDF_isCharRangesDefault(arg)) {
    return ATtrue;
  }
  else if (SDF_isCharRangesConc(arg)) {
    return ATtrue;
  }
  else if (SDF_isCharRangesBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isCharRangesDefault(SDF_CharRanges arg) */

ATbool SDF_isCharRangesDefault(SDF_CharRanges arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternCharRangesDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isCharRangesConc(SDF_CharRanges arg) */

ATbool SDF_isCharRangesConc(SDF_CharRanges arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternCharRangesConc, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isCharRangesBracket(SDF_CharRanges arg) */

ATbool SDF_isCharRangesBracket(SDF_CharRanges arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternCharRangesBracket, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasCharRangesCharRange(SDF_CharRanges arg) */

ATbool SDF_hasCharRangesCharRange(SDF_CharRanges arg)
{
  if (SDF_isCharRangesDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_CharRange SDF_getCharRangesCharRange(SDF_CharRanges arg) */

SDF_CharRange SDF_getCharRangesCharRange(SDF_CharRanges arg)
{
  if (SDF_isCharRangesDefault(arg)) {
    return (SDF_CharRange)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("CharRanges has no CharRange: %t\n", arg);
  return (SDF_CharRange)NULL;
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_setCharRangesCharRange(SDF_CharRanges arg, SDF_CharRange CharRange) */

SDF_CharRanges SDF_setCharRangesCharRange(SDF_CharRanges arg, SDF_CharRange CharRange)
{
  if (SDF_isCharRangesDefault(arg)) {
    return (SDF_CharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)CharRange, 0), 2);
  }

  ATabort("CharRanges has no CharRange: %t\n", arg);
  return (SDF_CharRanges)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasCharRangesLeft(SDF_CharRanges arg) */

ATbool SDF_hasCharRangesLeft(SDF_CharRanges arg)
{
  if (SDF_isCharRangesConc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_getCharRangesLeft(SDF_CharRanges arg) */

SDF_CharRanges SDF_getCharRangesLeft(SDF_CharRanges arg)
{
  if (SDF_isCharRangesConc(arg)) {
    return (SDF_CharRanges)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("CharRanges has no Left: %t\n", arg);
  return (SDF_CharRanges)NULL;
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_setCharRangesLeft(SDF_CharRanges arg, SDF_CharRanges left) */

SDF_CharRanges SDF_setCharRangesLeft(SDF_CharRanges arg, SDF_CharRanges left)
{
  if (SDF_isCharRangesConc(arg)) {
    return (SDF_CharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)left, 0), 2);
  }

  ATabort("CharRanges has no Left: %t\n", arg);
  return (SDF_CharRanges)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasCharRangesWsAfterLeft(SDF_CharRanges arg) */

ATbool SDF_hasCharRangesWsAfterLeft(SDF_CharRanges arg)
{
  if (SDF_isCharRangesConc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getCharRangesWsAfterLeft(SDF_CharRanges arg) */

char * SDF_getCharRangesWsAfterLeft(SDF_CharRanges arg)
{
  if (SDF_isCharRangesConc(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("CharRanges has no WsAfterLeft: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_setCharRangesWsAfterLeft(SDF_CharRanges arg, char * wsAfterLeft) */

SDF_CharRanges SDF_setCharRangesWsAfterLeft(SDF_CharRanges arg, char * wsAfterLeft)
{
  if (SDF_isCharRangesConc(arg)) {
    return (SDF_CharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterLeft, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("CharRanges has no WsAfterLeft: %t\n", arg);
  return (SDF_CharRanges)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasCharRangesRight(SDF_CharRanges arg) */

ATbool SDF_hasCharRangesRight(SDF_CharRanges arg)
{
  if (SDF_isCharRangesConc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_getCharRangesRight(SDF_CharRanges arg) */

SDF_CharRanges SDF_getCharRangesRight(SDF_CharRanges arg)
{
  if (SDF_isCharRangesConc(arg)) {
    return (SDF_CharRanges)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("CharRanges has no Right: %t\n", arg);
  return (SDF_CharRanges)NULL;
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_setCharRangesRight(SDF_CharRanges arg, SDF_CharRanges right) */

SDF_CharRanges SDF_setCharRangesRight(SDF_CharRanges arg, SDF_CharRanges right)
{
  if (SDF_isCharRangesConc(arg)) {
    return (SDF_CharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)right, 2), 2);
  }

  ATabort("CharRanges has no Right: %t\n", arg);
  return (SDF_CharRanges)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasCharRangesWsAfterParenOpen(SDF_CharRanges arg) */

ATbool SDF_hasCharRangesWsAfterParenOpen(SDF_CharRanges arg)
{
  if (SDF_isCharRangesBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getCharRangesWsAfterParenOpen(SDF_CharRanges arg) */

char * SDF_getCharRangesWsAfterParenOpen(SDF_CharRanges arg)
{
  if (SDF_isCharRangesBracket(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("CharRanges has no WsAfterParenOpen: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_setCharRangesWsAfterParenOpen(SDF_CharRanges arg, char * wsAfterParenOpen) */

SDF_CharRanges SDF_setCharRangesWsAfterParenOpen(SDF_CharRanges arg, char * wsAfterParenOpen)
{
  if (SDF_isCharRangesBracket(arg)) {
    return (SDF_CharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterParenOpen, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("CharRanges has no WsAfterParenOpen: %t\n", arg);
  return (SDF_CharRanges)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasCharRangesCharRanges(SDF_CharRanges arg) */

ATbool SDF_hasCharRangesCharRanges(SDF_CharRanges arg)
{
  if (SDF_isCharRangesBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_getCharRangesCharRanges(SDF_CharRanges arg) */

SDF_CharRanges SDF_getCharRangesCharRanges(SDF_CharRanges arg)
{
  if (SDF_isCharRangesBracket(arg)) {
    return (SDF_CharRanges)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("CharRanges has no CharRanges: %t\n", arg);
  return (SDF_CharRanges)NULL;
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_setCharRangesCharRanges(SDF_CharRanges arg, SDF_CharRanges CharRanges) */

SDF_CharRanges SDF_setCharRangesCharRanges(SDF_CharRanges arg, SDF_CharRanges CharRanges)
{
  if (SDF_isCharRangesBracket(arg)) {
    return (SDF_CharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)CharRanges, 2), 2);
  }

  ATabort("CharRanges has no CharRanges: %t\n", arg);
  return (SDF_CharRanges)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasCharRangesWsAfterCharRanges(SDF_CharRanges arg) */

ATbool SDF_hasCharRangesWsAfterCharRanges(SDF_CharRanges arg)
{
  if (SDF_isCharRangesBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getCharRangesWsAfterCharRanges(SDF_CharRanges arg) */

char * SDF_getCharRangesWsAfterCharRanges(SDF_CharRanges arg)
{
  if (SDF_isCharRangesBracket(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("CharRanges has no WsAfterCharRanges: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_setCharRangesWsAfterCharRanges(SDF_CharRanges arg, char * wsAfterCharRanges) */

SDF_CharRanges SDF_setCharRangesWsAfterCharRanges(SDF_CharRanges arg, char * wsAfterCharRanges)
{
  if (SDF_isCharRangesBracket(arg)) {
    return (SDF_CharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterCharRanges, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("CharRanges has no WsAfterCharRanges: %t\n", arg);
  return (SDF_CharRanges)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_OptCharRanges accessors */

/*{{{  ATbool SDF_isValidOptCharRanges(SDF_OptCharRanges arg) */

ATbool SDF_isValidOptCharRanges(SDF_OptCharRanges arg)
{
  if (SDF_isOptCharRangesAbsent(arg)) {
    return ATtrue;
  }
  else if (SDF_isOptCharRangesPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isOptCharRangesAbsent(SDF_OptCharRanges arg) */

ATbool SDF_isOptCharRangesAbsent(SDF_OptCharRanges arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternOptCharRangesAbsent);
}

/*}}}  */
/*{{{  ATbool SDF_isOptCharRangesPresent(SDF_OptCharRanges arg) */

ATbool SDF_isOptCharRangesPresent(SDF_OptCharRanges arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternOptCharRangesPresent, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasOptCharRangesCharRanges(SDF_OptCharRanges arg) */

ATbool SDF_hasOptCharRangesCharRanges(SDF_OptCharRanges arg)
{
  if (SDF_isOptCharRangesPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_getOptCharRangesCharRanges(SDF_OptCharRanges arg) */

SDF_CharRanges SDF_getOptCharRangesCharRanges(SDF_OptCharRanges arg)
{
  if (SDF_isOptCharRangesPresent(arg)) {
    return (SDF_CharRanges)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("OptCharRanges has no CharRanges: %t\n", arg);
  return (SDF_CharRanges)NULL;
}

/*}}}  */
/*{{{  SDF_OptCharRanges SDF_setOptCharRangesCharRanges(SDF_OptCharRanges arg, SDF_CharRanges CharRanges) */

SDF_OptCharRanges SDF_setOptCharRangesCharRanges(SDF_OptCharRanges arg, SDF_CharRanges CharRanges)
{
  if (SDF_isOptCharRangesPresent(arg)) {
    return (SDF_OptCharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)CharRanges, 0), 2);
  }

  ATabort("OptCharRanges has no CharRanges: %t\n", arg);
  return (SDF_OptCharRanges)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_CharClass accessors */

/*{{{  ATbool SDF_isValidCharClass(SDF_CharClass arg) */

ATbool SDF_isValidCharClass(SDF_CharClass arg)
{
  if (SDF_isCharClassSimpleCharclass(arg)) {
    return ATtrue;
  }
  else if (SDF_isCharClassComp(arg)) {
    return ATtrue;
  }
  else if (SDF_isCharClassDiff(arg)) {
    return ATtrue;
  }
  else if (SDF_isCharClassIsect(arg)) {
    return ATtrue;
  }
  else if (SDF_isCharClassUnion(arg)) {
    return ATtrue;
  }
  else if (SDF_isCharClassBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isCharClassSimpleCharclass(SDF_CharClass arg) */

ATbool SDF_isCharClassSimpleCharclass(SDF_CharClass arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternCharClassSimpleCharclass, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isCharClassComp(SDF_CharClass arg) */

ATbool SDF_isCharClassComp(SDF_CharClass arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternCharClassComp, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isCharClassDiff(SDF_CharClass arg) */

ATbool SDF_isCharClassDiff(SDF_CharClass arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternCharClassDiff, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isCharClassIsect(SDF_CharClass arg) */

ATbool SDF_isCharClassIsect(SDF_CharClass arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternCharClassIsect, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isCharClassUnion(SDF_CharClass arg) */

ATbool SDF_isCharClassUnion(SDF_CharClass arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternCharClassUnion, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isCharClassBracket(SDF_CharClass arg) */

ATbool SDF_isCharClassBracket(SDF_CharClass arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternCharClassBracket, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasCharClassWsAfterBracketOpen(SDF_CharClass arg) */

ATbool SDF_hasCharClassWsAfterBracketOpen(SDF_CharClass arg)
{
  if (SDF_isCharClassSimpleCharclass(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getCharClassWsAfterBracketOpen(SDF_CharClass arg) */

char * SDF_getCharClassWsAfterBracketOpen(SDF_CharClass arg)
{
  if (SDF_isCharClassSimpleCharclass(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("CharClass has no WsAfterBracketOpen: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterBracketOpen(SDF_CharClass arg, char * wsAfterBracketOpen) */

SDF_CharClass SDF_setCharClassWsAfterBracketOpen(SDF_CharClass arg, char * wsAfterBracketOpen)
{
  if (SDF_isCharClassSimpleCharclass(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterBracketOpen, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("CharClass has no WsAfterBracketOpen: %t\n", arg);
  return (SDF_CharClass)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasCharClassOptCharRanges(SDF_CharClass arg) */

ATbool SDF_hasCharClassOptCharRanges(SDF_CharClass arg)
{
  if (SDF_isCharClassSimpleCharclass(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptCharRanges SDF_getCharClassOptCharRanges(SDF_CharClass arg) */

SDF_OptCharRanges SDF_getCharClassOptCharRanges(SDF_CharClass arg)
{
  if (SDF_isCharClassSimpleCharclass(arg)) {
    return (SDF_OptCharRanges)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("CharClass has no OptCharRanges: %t\n", arg);
  return (SDF_OptCharRanges)NULL;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassOptCharRanges(SDF_CharClass arg, SDF_OptCharRanges OptCharRanges) */

SDF_CharClass SDF_setCharClassOptCharRanges(SDF_CharClass arg, SDF_OptCharRanges OptCharRanges)
{
  if (SDF_isCharClassSimpleCharclass(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)OptCharRanges, 2), 2);
  }

  ATabort("CharClass has no OptCharRanges: %t\n", arg);
  return (SDF_CharClass)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasCharClassWsAfterOptCharRanges(SDF_CharClass arg) */

ATbool SDF_hasCharClassWsAfterOptCharRanges(SDF_CharClass arg)
{
  if (SDF_isCharClassSimpleCharclass(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getCharClassWsAfterOptCharRanges(SDF_CharClass arg) */

char * SDF_getCharClassWsAfterOptCharRanges(SDF_CharClass arg)
{
  if (SDF_isCharClassSimpleCharclass(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("CharClass has no WsAfterOptCharRanges: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterOptCharRanges(SDF_CharClass arg, char * wsAfterOptCharRanges) */

SDF_CharClass SDF_setCharClassWsAfterOptCharRanges(SDF_CharClass arg, char * wsAfterOptCharRanges)
{
  if (SDF_isCharClassSimpleCharclass(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterOptCharRanges, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("CharClass has no WsAfterOptCharRanges: %t\n", arg);
  return (SDF_CharClass)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasCharClassWsAfterTilde(SDF_CharClass arg) */

ATbool SDF_hasCharClassWsAfterTilde(SDF_CharClass arg)
{
  if (SDF_isCharClassComp(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getCharClassWsAfterTilde(SDF_CharClass arg) */

char * SDF_getCharClassWsAfterTilde(SDF_CharClass arg)
{
  if (SDF_isCharClassComp(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("CharClass has no WsAfterTilde: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterTilde(SDF_CharClass arg, char * wsAfterTilde) */

SDF_CharClass SDF_setCharClassWsAfterTilde(SDF_CharClass arg, char * wsAfterTilde)
{
  if (SDF_isCharClassComp(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterTilde, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("CharClass has no WsAfterTilde: %t\n", arg);
  return (SDF_CharClass)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasCharClassCharClass(SDF_CharClass arg) */

ATbool SDF_hasCharClassCharClass(SDF_CharClass arg)
{
  if (SDF_isCharClassComp(arg)) {
    return ATtrue;
  }
  else if (SDF_isCharClassBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_getCharClassCharClass(SDF_CharClass arg) */

SDF_CharClass SDF_getCharClassCharClass(SDF_CharClass arg)
{
  if (SDF_isCharClassComp(arg)) {
    return (SDF_CharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDF_isCharClassBracket(arg)) {
    return (SDF_CharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("CharClass has no CharClass: %t\n", arg);
  return (SDF_CharClass)NULL;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassCharClass(SDF_CharClass arg, SDF_CharClass CharClass) */

SDF_CharClass SDF_setCharClassCharClass(SDF_CharClass arg, SDF_CharClass CharClass)
{
  if (SDF_isCharClassComp(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)CharClass, 2), 2);
  }
  else if (SDF_isCharClassBracket(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)CharClass, 2), 2);
  }

  ATabort("CharClass has no CharClass: %t\n", arg);
  return (SDF_CharClass)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasCharClassLeft(SDF_CharClass arg) */

ATbool SDF_hasCharClassLeft(SDF_CharClass arg)
{
  if (SDF_isCharClassDiff(arg)) {
    return ATtrue;
  }
  else if (SDF_isCharClassIsect(arg)) {
    return ATtrue;
  }
  else if (SDF_isCharClassUnion(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_getCharClassLeft(SDF_CharClass arg) */

SDF_CharClass SDF_getCharClassLeft(SDF_CharClass arg)
{
  if (SDF_isCharClassDiff(arg)) {
    return (SDF_CharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDF_isCharClassIsect(arg)) {
    return (SDF_CharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDF_isCharClassUnion(arg)) {
    return (SDF_CharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("CharClass has no Left: %t\n", arg);
  return (SDF_CharClass)NULL;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassLeft(SDF_CharClass arg, SDF_CharClass left) */

SDF_CharClass SDF_setCharClassLeft(SDF_CharClass arg, SDF_CharClass left)
{
  if (SDF_isCharClassDiff(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)left, 0), 2);
  }
  else if (SDF_isCharClassIsect(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)left, 0), 2);
  }
  else if (SDF_isCharClassUnion(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)left, 0), 2);
  }

  ATabort("CharClass has no Left: %t\n", arg);
  return (SDF_CharClass)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasCharClassWsAfterLeft(SDF_CharClass arg) */

ATbool SDF_hasCharClassWsAfterLeft(SDF_CharClass arg)
{
  if (SDF_isCharClassDiff(arg)) {
    return ATtrue;
  }
  else if (SDF_isCharClassIsect(arg)) {
    return ATtrue;
  }
  else if (SDF_isCharClassUnion(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getCharClassWsAfterLeft(SDF_CharClass arg) */

char * SDF_getCharClassWsAfterLeft(SDF_CharClass arg)
{
  if (SDF_isCharClassDiff(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isCharClassIsect(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isCharClassUnion(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("CharClass has no WsAfterLeft: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterLeft(SDF_CharClass arg, char * wsAfterLeft) */

SDF_CharClass SDF_setCharClassWsAfterLeft(SDF_CharClass arg, char * wsAfterLeft)
{
  if (SDF_isCharClassDiff(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterLeft, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isCharClassIsect(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterLeft, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isCharClassUnion(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterLeft, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("CharClass has no WsAfterLeft: %t\n", arg);
  return (SDF_CharClass)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasCharClassWsAfterSlash(SDF_CharClass arg) */

ATbool SDF_hasCharClassWsAfterSlash(SDF_CharClass arg)
{
  if (SDF_isCharClassDiff(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getCharClassWsAfterSlash(SDF_CharClass arg) */

char * SDF_getCharClassWsAfterSlash(SDF_CharClass arg)
{
  if (SDF_isCharClassDiff(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("CharClass has no WsAfterSlash: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterSlash(SDF_CharClass arg, char * wsAfterSlash) */

SDF_CharClass SDF_setCharClassWsAfterSlash(SDF_CharClass arg, char * wsAfterSlash)
{
  if (SDF_isCharClassDiff(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSlash, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("CharClass has no WsAfterSlash: %t\n", arg);
  return (SDF_CharClass)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasCharClassRight(SDF_CharClass arg) */

ATbool SDF_hasCharClassRight(SDF_CharClass arg)
{
  if (SDF_isCharClassDiff(arg)) {
    return ATtrue;
  }
  else if (SDF_isCharClassIsect(arg)) {
    return ATtrue;
  }
  else if (SDF_isCharClassUnion(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_getCharClassRight(SDF_CharClass arg) */

SDF_CharClass SDF_getCharClassRight(SDF_CharClass arg)
{
  if (SDF_isCharClassDiff(arg)) {
    return (SDF_CharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDF_isCharClassIsect(arg)) {
    return (SDF_CharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDF_isCharClassUnion(arg)) {
    return (SDF_CharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("CharClass has no Right: %t\n", arg);
  return (SDF_CharClass)NULL;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassRight(SDF_CharClass arg, SDF_CharClass right) */

SDF_CharClass SDF_setCharClassRight(SDF_CharClass arg, SDF_CharClass right)
{
  if (SDF_isCharClassDiff(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)right, 4), 2);
  }
  else if (SDF_isCharClassIsect(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)right, 4), 2);
  }
  else if (SDF_isCharClassUnion(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)right, 4), 2);
  }

  ATabort("CharClass has no Right: %t\n", arg);
  return (SDF_CharClass)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasCharClassWsAfterSlashBackslash(SDF_CharClass arg) */

ATbool SDF_hasCharClassWsAfterSlashBackslash(SDF_CharClass arg)
{
  if (SDF_isCharClassIsect(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getCharClassWsAfterSlashBackslash(SDF_CharClass arg) */

char * SDF_getCharClassWsAfterSlashBackslash(SDF_CharClass arg)
{
  if (SDF_isCharClassIsect(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("CharClass has no WsAfterSlashBackslash: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterSlashBackslash(SDF_CharClass arg, char * wsAfterSlashBackslash) */

SDF_CharClass SDF_setCharClassWsAfterSlashBackslash(SDF_CharClass arg, char * wsAfterSlashBackslash)
{
  if (SDF_isCharClassIsect(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSlashBackslash, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("CharClass has no WsAfterSlashBackslash: %t\n", arg);
  return (SDF_CharClass)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasCharClassWsAfterBackslashSlash(SDF_CharClass arg) */

ATbool SDF_hasCharClassWsAfterBackslashSlash(SDF_CharClass arg)
{
  if (SDF_isCharClassUnion(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getCharClassWsAfterBackslashSlash(SDF_CharClass arg) */

char * SDF_getCharClassWsAfterBackslashSlash(SDF_CharClass arg)
{
  if (SDF_isCharClassUnion(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("CharClass has no WsAfterBackslashSlash: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterBackslashSlash(SDF_CharClass arg, char * wsAfterBackslashSlash) */

SDF_CharClass SDF_setCharClassWsAfterBackslashSlash(SDF_CharClass arg, char * wsAfterBackslashSlash)
{
  if (SDF_isCharClassUnion(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterBackslashSlash, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("CharClass has no WsAfterBackslashSlash: %t\n", arg);
  return (SDF_CharClass)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasCharClassWsAfterParenOpen(SDF_CharClass arg) */

ATbool SDF_hasCharClassWsAfterParenOpen(SDF_CharClass arg)
{
  if (SDF_isCharClassBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getCharClassWsAfterParenOpen(SDF_CharClass arg) */

char * SDF_getCharClassWsAfterParenOpen(SDF_CharClass arg)
{
  if (SDF_isCharClassBracket(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("CharClass has no WsAfterParenOpen: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterParenOpen(SDF_CharClass arg, char * wsAfterParenOpen) */

SDF_CharClass SDF_setCharClassWsAfterParenOpen(SDF_CharClass arg, char * wsAfterParenOpen)
{
  if (SDF_isCharClassBracket(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterParenOpen, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("CharClass has no WsAfterParenOpen: %t\n", arg);
  return (SDF_CharClass)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasCharClassWsAfterCharClass(SDF_CharClass arg) */

ATbool SDF_hasCharClassWsAfterCharClass(SDF_CharClass arg)
{
  if (SDF_isCharClassBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getCharClassWsAfterCharClass(SDF_CharClass arg) */

char * SDF_getCharClassWsAfterCharClass(SDF_CharClass arg)
{
  if (SDF_isCharClassBracket(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("CharClass has no WsAfterCharClass: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterCharClass(SDF_CharClass arg, char * wsAfterCharClass) */

SDF_CharClass SDF_setCharClassWsAfterCharClass(SDF_CharClass arg, char * wsAfterCharClass)
{
  if (SDF_isCharClassBracket(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterCharClass, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("CharClass has no WsAfterCharClass: %t\n", arg);
  return (SDF_CharClass)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_AlphaNumericalEscChar accessors */

/*{{{  ATbool SDF_isValidAlphaNumericalEscChar(SDF_AlphaNumericalEscChar arg) */

ATbool SDF_isValidAlphaNumericalEscChar(SDF_AlphaNumericalEscChar arg)
{
  if (SDF_isAlphaNumericalEscCharDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isAlphaNumericalEscCharDefault(SDF_AlphaNumericalEscChar arg) */

ATbool SDF_isAlphaNumericalEscCharDefault(SDF_AlphaNumericalEscChar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAlphaNumericalEscCharDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasAlphaNumericalEscCharLex(SDF_AlphaNumericalEscChar arg) */

ATbool SDF_hasAlphaNumericalEscCharLex(SDF_AlphaNumericalEscChar arg)
{
  if (SDF_isAlphaNumericalEscCharDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getAlphaNumericalEscCharLex(SDF_AlphaNumericalEscChar arg) */

char * SDF_getAlphaNumericalEscCharLex(SDF_AlphaNumericalEscChar arg)
{
  if (SDF_isAlphaNumericalEscCharDefault(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }

  ATabort("AlphaNumericalEscChar has no Lex: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_AlphaNumericalEscChar SDF_setAlphaNumericalEscCharLex(SDF_AlphaNumericalEscChar arg, char * lex) */

SDF_AlphaNumericalEscChar SDF_setAlphaNumericalEscCharLex(SDF_AlphaNumericalEscChar arg, char * lex)
{
  if (SDF_isAlphaNumericalEscCharDefault(arg)) {
    return (SDF_AlphaNumericalEscChar)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }

  ATabort("AlphaNumericalEscChar has no Lex: %t\n", arg);
  return (SDF_AlphaNumericalEscChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_DecimalEscChar accessors */

/*{{{  ATbool SDF_isValidDecimalEscChar(SDF_DecimalEscChar arg) */

ATbool SDF_isValidDecimalEscChar(SDF_DecimalEscChar arg)
{
  if (SDF_isDecimalEscCharDec0_199(arg)) {
    return ATtrue;
  }
  else if (SDF_isDecimalEscCharDec200_249(arg)) {
    return ATtrue;
  }
  else if (SDF_isDecimalEscCharDec250_255(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isDecimalEscCharDec0_199(SDF_DecimalEscChar arg) */

ATbool SDF_isDecimalEscCharDec0_199(SDF_DecimalEscChar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternDecimalEscCharDec0_199, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isDecimalEscCharDec200_249(SDF_DecimalEscChar arg) */

ATbool SDF_isDecimalEscCharDec200_249(SDF_DecimalEscChar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternDecimalEscCharDec200_249, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isDecimalEscCharDec250_255(SDF_DecimalEscChar arg) */

ATbool SDF_isDecimalEscCharDec250_255(SDF_DecimalEscChar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternDecimalEscCharDec250_255, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasDecimalEscCharLex(SDF_DecimalEscChar arg) */

ATbool SDF_hasDecimalEscCharLex(SDF_DecimalEscChar arg)
{
  if (SDF_isDecimalEscCharDec0_199(arg)) {
    return ATtrue;
  }
  else if (SDF_isDecimalEscCharDec200_249(arg)) {
    return ATtrue;
  }
  else if (SDF_isDecimalEscCharDec250_255(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getDecimalEscCharLex(SDF_DecimalEscChar arg) */

char * SDF_getDecimalEscCharLex(SDF_DecimalEscChar arg)
{
  if (SDF_isDecimalEscCharDec0_199(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (SDF_isDecimalEscCharDec200_249(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (SDF_isDecimalEscCharDec250_255(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }

  ATabort("DecimalEscChar has no Lex: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_DecimalEscChar SDF_setDecimalEscCharLex(SDF_DecimalEscChar arg, char * lex) */

SDF_DecimalEscChar SDF_setDecimalEscCharLex(SDF_DecimalEscChar arg, char * lex)
{
  if (SDF_isDecimalEscCharDec0_199(arg)) {
    return (SDF_DecimalEscChar)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }
  else if (SDF_isDecimalEscCharDec200_249(arg)) {
    return (SDF_DecimalEscChar)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }
  else if (SDF_isDecimalEscCharDec250_255(arg)) {
    return (SDF_DecimalEscChar)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }

  ATabort("DecimalEscChar has no Lex: %t\n", arg);
  return (SDF_DecimalEscChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_EscChar accessors */

/*{{{  ATbool SDF_isValidEscChar(SDF_EscChar arg) */

ATbool SDF_isValidEscChar(SDF_EscChar arg)
{
  if (SDF_isEscCharAlphaNumeric(arg)) {
    return ATtrue;
  }
  else if (SDF_isEscCharDecimal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isEscCharAlphaNumeric(SDF_EscChar arg) */

ATbool SDF_isEscCharAlphaNumeric(SDF_EscChar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternEscCharAlphaNumeric, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isEscCharDecimal(SDF_EscChar arg) */

ATbool SDF_isEscCharDecimal(SDF_EscChar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternEscCharDecimal, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasEscCharLex(SDF_EscChar arg) */

ATbool SDF_hasEscCharLex(SDF_EscChar arg)
{
  if (SDF_isEscCharAlphaNumeric(arg)) {
    return ATtrue;
  }
  else if (SDF_isEscCharDecimal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getEscCharLex(SDF_EscChar arg) */

char * SDF_getEscCharLex(SDF_EscChar arg)
{
  if (SDF_isEscCharAlphaNumeric(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (SDF_isEscCharDecimal(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }

  ATabort("EscChar has no Lex: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_EscChar SDF_setEscCharLex(SDF_EscChar arg, char * lex) */

SDF_EscChar SDF_setEscCharLex(SDF_EscChar arg, char * lex)
{
  if (SDF_isEscCharAlphaNumeric(arg)) {
    return (SDF_EscChar)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }
  else if (SDF_isEscCharDecimal(arg)) {
    return (SDF_EscChar)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }

  ATabort("EscChar has no Lex: %t\n", arg);
  return (SDF_EscChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_LChar accessors */

/*{{{  ATbool SDF_isValidLChar(SDF_LChar arg) */

ATbool SDF_isValidLChar(SDF_LChar arg)
{
  if (SDF_isLCharNormal(arg)) {
    return ATtrue;
  }
  else if (SDF_isLCharEscaped(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isLCharNormal(SDF_LChar arg) */

ATbool SDF_isLCharNormal(SDF_LChar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternLCharNormal, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isLCharEscaped(SDF_LChar arg) */

ATbool SDF_isLCharEscaped(SDF_LChar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternLCharEscaped, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasLCharLex(SDF_LChar arg) */

ATbool SDF_hasLCharLex(SDF_LChar arg)
{
  if (SDF_isLCharNormal(arg)) {
    return ATtrue;
  }
  else if (SDF_isLCharEscaped(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getLCharLex(SDF_LChar arg) */

char * SDF_getLCharLex(SDF_LChar arg)
{
  if (SDF_isLCharNormal(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (SDF_isLCharEscaped(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }

  ATabort("LChar has no Lex: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_LChar SDF_setLCharLex(SDF_LChar arg, char * lex) */

SDF_LChar SDF_setLCharLex(SDF_LChar arg, char * lex)
{
  if (SDF_isLCharNormal(arg)) {
    return (SDF_LChar)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }
  else if (SDF_isLCharEscaped(arg)) {
    return (SDF_LChar)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }

  ATabort("LChar has no Lex: %t\n", arg);
  return (SDF_LChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ATerms accessors */

/*{{{  ATbool SDF_isValidATerms(SDF_ATerms arg) */

ATbool SDF_isValidATerms(SDF_ATerms arg)
{
  if (SDF_isATermsAterm(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermsCons(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isATermsAterm(SDF_ATerms arg) */

ATbool SDF_isATermsAterm(SDF_ATerms arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternATermsAterm, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isATermsCons(SDF_ATerms arg) */

ATbool SDF_isATermsCons(SDF_ATerms arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternATermsCons, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasATermsTerm(SDF_ATerms arg) */

ATbool SDF_hasATermsTerm(SDF_ATerms arg)
{
  if (SDF_isATermsAterm(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_getATermsTerm(SDF_ATerms arg) */

SDF_ATerm SDF_getATermsTerm(SDF_ATerms arg)
{
  if (SDF_isATermsAterm(arg)) {
    return (SDF_ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("ATerms has no Term: %t\n", arg);
  return (SDF_ATerm)NULL;
}

/*}}}  */
/*{{{  SDF_ATerms SDF_setATermsTerm(SDF_ATerms arg, SDF_ATerm term) */

SDF_ATerms SDF_setATermsTerm(SDF_ATerms arg, SDF_ATerm term)
{
  if (SDF_isATermsAterm(arg)) {
    return (SDF_ATerms)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)term, 0), 2);
  }

  ATabort("ATerms has no Term: %t\n", arg);
  return (SDF_ATerms)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermsHead(SDF_ATerms arg) */

ATbool SDF_hasATermsHead(SDF_ATerms arg)
{
  if (SDF_isATermsCons(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_getATermsHead(SDF_ATerms arg) */

SDF_ATerm SDF_getATermsHead(SDF_ATerms arg)
{
  if (SDF_isATermsCons(arg)) {
    return (SDF_ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("ATerms has no Head: %t\n", arg);
  return (SDF_ATerm)NULL;
}

/*}}}  */
/*{{{  SDF_ATerms SDF_setATermsHead(SDF_ATerms arg, SDF_ATerm head) */

SDF_ATerms SDF_setATermsHead(SDF_ATerms arg, SDF_ATerm head)
{
  if (SDF_isATermsCons(arg)) {
    return (SDF_ATerms)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)head, 0), 2);
  }

  ATabort("ATerms has no Head: %t\n", arg);
  return (SDF_ATerms)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermsWsAfterHead(SDF_ATerms arg) */

ATbool SDF_hasATermsWsAfterHead(SDF_ATerms arg)
{
  if (SDF_isATermsCons(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getATermsWsAfterHead(SDF_ATerms arg) */

char * SDF_getATermsWsAfterHead(SDF_ATerms arg)
{
  if (SDF_isATermsCons(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("ATerms has no WsAfterHead: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_ATerms SDF_setATermsWsAfterHead(SDF_ATerms arg, char * wsAfterHead) */

SDF_ATerms SDF_setATermsWsAfterHead(SDF_ATerms arg, char * wsAfterHead)
{
  if (SDF_isATermsCons(arg)) {
    return (SDF_ATerms)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterHead, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("ATerms has no WsAfterHead: %t\n", arg);
  return (SDF_ATerms)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermsWsAfterComma(SDF_ATerms arg) */

ATbool SDF_hasATermsWsAfterComma(SDF_ATerms arg)
{
  if (SDF_isATermsCons(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getATermsWsAfterComma(SDF_ATerms arg) */

char * SDF_getATermsWsAfterComma(SDF_ATerms arg)
{
  if (SDF_isATermsCons(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("ATerms has no WsAfterComma: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_ATerms SDF_setATermsWsAfterComma(SDF_ATerms arg, char * wsAfterComma) */

SDF_ATerms SDF_setATermsWsAfterComma(SDF_ATerms arg, char * wsAfterComma)
{
  if (SDF_isATermsCons(arg)) {
    return (SDF_ATerms)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterComma, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("ATerms has no WsAfterComma: %t\n", arg);
  return (SDF_ATerms)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermsTail(SDF_ATerms arg) */

ATbool SDF_hasATermsTail(SDF_ATerms arg)
{
  if (SDF_isATermsCons(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ATerms SDF_getATermsTail(SDF_ATerms arg) */

SDF_ATerms SDF_getATermsTail(SDF_ATerms arg)
{
  if (SDF_isATermsCons(arg)) {
    return (SDF_ATerms)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("ATerms has no Tail: %t\n", arg);
  return (SDF_ATerms)NULL;
}

/*}}}  */
/*{{{  SDF_ATerms SDF_setATermsTail(SDF_ATerms arg, SDF_ATerms tail) */

SDF_ATerms SDF_setATermsTail(SDF_ATerms arg, SDF_ATerms tail)
{
  if (SDF_isATermsCons(arg)) {
    return (SDF_ATerms)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)tail, 4), 2);
  }

  ATabort("ATerms has no Tail: %t\n", arg);
  return (SDF_ATerms)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ATermList accessors */

/*{{{  ATbool SDF_isValidATermList(SDF_ATermList arg) */

ATbool SDF_isValidATermList(SDF_ATermList arg)
{
  if (SDF_isATermListEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermListNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isATermListEmpty(SDF_ATermList arg) */

ATbool SDF_isATermListEmpty(SDF_ATermList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternATermListEmpty, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isATermListNotEmpty(SDF_ATermList arg) */

ATbool SDF_isATermListNotEmpty(SDF_ATermList arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternATermListNotEmpty, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasATermListWsAfterBracketOpen(SDF_ATermList arg) */

ATbool SDF_hasATermListWsAfterBracketOpen(SDF_ATermList arg)
{
  if (SDF_isATermListEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermListNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getATermListWsAfterBracketOpen(SDF_ATermList arg) */

char * SDF_getATermListWsAfterBracketOpen(SDF_ATermList arg)
{
  if (SDF_isATermListEmpty(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isATermListNotEmpty(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("ATermList has no WsAfterBracketOpen: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_ATermList SDF_setATermListWsAfterBracketOpen(SDF_ATermList arg, char * wsAfterBracketOpen) */

SDF_ATermList SDF_setATermListWsAfterBracketOpen(SDF_ATermList arg, char * wsAfterBracketOpen)
{
  if (SDF_isATermListEmpty(arg)) {
    return (SDF_ATermList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterBracketOpen, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isATermListNotEmpty(arg)) {
    return (SDF_ATermList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterBracketOpen, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("ATermList has no WsAfterBracketOpen: %t\n", arg);
  return (SDF_ATermList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermListATerms(SDF_ATermList arg) */

ATbool SDF_hasATermListATerms(SDF_ATermList arg)
{
  if (SDF_isATermListNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ATerms SDF_getATermListATerms(SDF_ATermList arg) */

SDF_ATerms SDF_getATermListATerms(SDF_ATermList arg)
{
  if (SDF_isATermListNotEmpty(arg)) {
    return (SDF_ATerms)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("ATermList has no ATerms: %t\n", arg);
  return (SDF_ATerms)NULL;
}

/*}}}  */
/*{{{  SDF_ATermList SDF_setATermListATerms(SDF_ATermList arg, SDF_ATerms ATerms) */

SDF_ATermList SDF_setATermListATerms(SDF_ATermList arg, SDF_ATerms ATerms)
{
  if (SDF_isATermListNotEmpty(arg)) {
    return (SDF_ATermList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATerms, 2), 2);
  }

  ATabort("ATermList has no ATerms: %t\n", arg);
  return (SDF_ATermList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermListWsAfterATerms(SDF_ATermList arg) */

ATbool SDF_hasATermListWsAfterATerms(SDF_ATermList arg)
{
  if (SDF_isATermListNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getATermListWsAfterATerms(SDF_ATermList arg) */

char * SDF_getATermListWsAfterATerms(SDF_ATermList arg)
{
  if (SDF_isATermListNotEmpty(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("ATermList has no WsAfterATerms: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_ATermList SDF_setATermListWsAfterATerms(SDF_ATermList arg, char * wsAfterATerms) */

SDF_ATermList SDF_setATermListWsAfterATerms(SDF_ATermList arg, char * wsAfterATerms)
{
  if (SDF_isATermListNotEmpty(arg)) {
    return (SDF_ATermList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterATerms, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("ATermList has no WsAfterATerms: %t\n", arg);
  return (SDF_ATermList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ACon accessors */

/*{{{  ATbool SDF_isValidACon(SDF_ACon arg) */

ATbool SDF_isValidACon(SDF_ACon arg)
{
  if (SDF_isAConInt(arg)) {
    return ATtrue;
  }
  else if (SDF_isAConReal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isAConInt(SDF_ACon arg) */

ATbool SDF_isAConInt(SDF_ACon arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAConInt, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isAConReal(SDF_ACon arg) */

ATbool SDF_isAConReal(SDF_ACon arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAConReal, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasAConIntCon(SDF_ACon arg) */

ATbool SDF_hasAConIntCon(SDF_ACon arg)
{
  if (SDF_isAConInt(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_IntCon SDF_getAConIntCon(SDF_ACon arg) */

SDF_IntCon SDF_getAConIntCon(SDF_ACon arg)
{
  if (SDF_isAConInt(arg)) {
    return (SDF_IntCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("ACon has no IntCon: %t\n", arg);
  return (SDF_IntCon)NULL;
}

/*}}}  */
/*{{{  SDF_ACon SDF_setAConIntCon(SDF_ACon arg, SDF_IntCon IntCon) */

SDF_ACon SDF_setAConIntCon(SDF_ACon arg, SDF_IntCon IntCon)
{
  if (SDF_isAConInt(arg)) {
    return (SDF_ACon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)IntCon, 0), 2);
  }

  ATabort("ACon has no IntCon: %t\n", arg);
  return (SDF_ACon)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAConRealCon(SDF_ACon arg) */

ATbool SDF_hasAConRealCon(SDF_ACon arg)
{
  if (SDF_isAConReal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_RealCon SDF_getAConRealCon(SDF_ACon arg) */

SDF_RealCon SDF_getAConRealCon(SDF_ACon arg)
{
  if (SDF_isAConReal(arg)) {
    return (SDF_RealCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("ACon has no RealCon: %t\n", arg);
  return (SDF_RealCon)NULL;
}

/*}}}  */
/*{{{  SDF_ACon SDF_setAConRealCon(SDF_ACon arg, SDF_RealCon RealCon) */

SDF_ACon SDF_setAConRealCon(SDF_ACon arg, SDF_RealCon RealCon)
{
  if (SDF_isAConReal(arg)) {
    return (SDF_ACon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)RealCon, 0), 2);
  }

  ATabort("ACon has no RealCon: %t\n", arg);
  return (SDF_ACon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_AFun accessors */

/*{{{  ATbool SDF_isValidAFun(SDF_AFun arg) */

ATbool SDF_isValidAFun(SDF_AFun arg)
{
  if (SDF_isAFunDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isAFunDefault(SDF_AFun arg) */

ATbool SDF_isAFunDefault(SDF_AFun arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAFunDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasAFunLiteral(SDF_AFun arg) */

ATbool SDF_hasAFunLiteral(SDF_AFun arg)
{
  if (SDF_isAFunDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Literal SDF_getAFunLiteral(SDF_AFun arg) */

SDF_Literal SDF_getAFunLiteral(SDF_AFun arg)
{
  if (SDF_isAFunDefault(arg)) {
    return (SDF_Literal)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("AFun has no Literal: %t\n", arg);
  return (SDF_Literal)NULL;
}

/*}}}  */
/*{{{  SDF_AFun SDF_setAFunLiteral(SDF_AFun arg, SDF_Literal Literal) */

SDF_AFun SDF_setAFunLiteral(SDF_AFun arg, SDF_Literal Literal)
{
  if (SDF_isAFunDefault(arg)) {
    return (SDF_AFun)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Literal, 0), 2);
  }

  ATabort("AFun has no Literal: %t\n", arg);
  return (SDF_AFun)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ATerm accessors */

/*{{{  ATbool SDF_isValidATerm(SDF_ATerm arg) */

ATbool SDF_isValidATerm(SDF_ATerm arg)
{
  if (SDF_isATermConstant(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermList(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermFun(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermAppl(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermAnnotatedConstant(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermAnnotatedList(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermAnnotatedFun(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isATermConstant(SDF_ATerm arg) */

ATbool SDF_isATermConstant(SDF_ATerm arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternATermConstant, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isATermList(SDF_ATerm arg) */

ATbool SDF_isATermList(SDF_ATerm arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternATermList, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isATermFun(SDF_ATerm arg) */

ATbool SDF_isATermFun(SDF_ATerm arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternATermFun, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isATermAppl(SDF_ATerm arg) */

ATbool SDF_isATermAppl(SDF_ATerm arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternATermAppl, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isATermAnnotatedConstant(SDF_ATerm arg) */

ATbool SDF_isATermAnnotatedConstant(SDF_ATerm arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternATermAnnotatedConstant, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isATermAnnotatedList(SDF_ATerm arg) */

ATbool SDF_isATermAnnotatedList(SDF_ATerm arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternATermAnnotatedList, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isATermAnnotatedFun(SDF_ATerm arg) */

ATbool SDF_isATermAnnotatedFun(SDF_ATerm arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternATermAnnotatedFun, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isATermAnnotatedAppl(SDF_ATerm arg) */

ATbool SDF_isATermAnnotatedAppl(SDF_ATerm arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternATermAnnotatedAppl, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasATermACon(SDF_ATerm arg) */

ATbool SDF_hasATermACon(SDF_ATerm arg)
{
  if (SDF_isATermConstant(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermAnnotatedConstant(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ACon SDF_getATermACon(SDF_ATerm arg) */

SDF_ACon SDF_getATermACon(SDF_ATerm arg)
{
  if (SDF_isATermConstant(arg)) {
    return (SDF_ACon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDF_isATermAnnotatedConstant(arg)) {
    return (SDF_ACon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("ATerm has no ACon: %t\n", arg);
  return (SDF_ACon)NULL;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermACon(SDF_ATerm arg, SDF_ACon ACon) */

SDF_ATerm SDF_setATermACon(SDF_ATerm arg, SDF_ACon ACon)
{
  if (SDF_isATermConstant(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ACon, 0), 2);
  }
  else if (SDF_isATermAnnotatedConstant(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ACon, 0), 2);
  }

  ATabort("ATerm has no ACon: %t\n", arg);
  return (SDF_ATerm)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermList(SDF_ATerm arg) */

ATbool SDF_hasATermList(SDF_ATerm arg)
{
  if (SDF_isATermList(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermAnnotatedList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ATermList SDF_getATermList(SDF_ATerm arg) */

SDF_ATermList SDF_getATermList(SDF_ATerm arg)
{
  if (SDF_isATermList(arg)) {
    return (SDF_ATermList)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDF_isATermAnnotatedList(arg)) {
    return (SDF_ATermList)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("ATerm has no List: %t\n", arg);
  return (SDF_ATermList)NULL;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermList(SDF_ATerm arg, SDF_ATermList list) */

SDF_ATerm SDF_setATermList(SDF_ATerm arg, SDF_ATermList list)
{
  if (SDF_isATermList(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)list, 0), 2);
  }
  else if (SDF_isATermAnnotatedList(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)list, 0), 2);
  }

  ATabort("ATerm has no List: %t\n", arg);
  return (SDF_ATerm)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermFun(SDF_ATerm arg) */

ATbool SDF_hasATermFun(SDF_ATerm arg)
{
  if (SDF_isATermFun(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermAppl(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermAnnotatedFun(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_AFun SDF_getATermFun(SDF_ATerm arg) */

SDF_AFun SDF_getATermFun(SDF_ATerm arg)
{
  if (SDF_isATermFun(arg)) {
    return (SDF_AFun)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDF_isATermAppl(arg)) {
    return (SDF_AFun)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDF_isATermAnnotatedFun(arg)) {
    return (SDF_AFun)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_AFun)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("ATerm has no Fun: %t\n", arg);
  return (SDF_AFun)NULL;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermFun(SDF_ATerm arg, SDF_AFun fun) */

SDF_ATerm SDF_setATermFun(SDF_ATerm arg, SDF_AFun fun)
{
  if (SDF_isATermFun(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)fun, 0), 2);
  }
  else if (SDF_isATermAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)fun, 0), 2);
  }
  else if (SDF_isATermAnnotatedFun(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)fun, 0), 2);
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)fun, 0), 2);
  }

  ATabort("ATerm has no Fun: %t\n", arg);
  return (SDF_ATerm)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermWsAfterFun(SDF_ATerm arg) */

ATbool SDF_hasATermWsAfterFun(SDF_ATerm arg)
{
  if (SDF_isATermAppl(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermAnnotatedFun(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getATermWsAfterFun(SDF_ATerm arg) */

char * SDF_getATermWsAfterFun(SDF_ATerm arg)
{
  if (SDF_isATermAppl(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isATermAnnotatedFun(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("ATerm has no WsAfterFun: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermWsAfterFun(SDF_ATerm arg, char * wsAfterFun) */

SDF_ATerm SDF_setATermWsAfterFun(SDF_ATerm arg, char * wsAfterFun)
{
  if (SDF_isATermAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterFun, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isATermAnnotatedFun(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterFun, 0, ATtrue)), 0), 1), 2);
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterFun, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("ATerm has no WsAfterFun: %t\n", arg);
  return (SDF_ATerm)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermWsAfterParenOpen(SDF_ATerm arg) */

ATbool SDF_hasATermWsAfterParenOpen(SDF_ATerm arg)
{
  if (SDF_isATermAppl(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getATermWsAfterParenOpen(SDF_ATerm arg) */

char * SDF_getATermWsAfterParenOpen(SDF_ATerm arg)
{
  if (SDF_isATermAppl(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("ATerm has no WsAfterParenOpen: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermWsAfterParenOpen(SDF_ATerm arg, char * wsAfterParenOpen) */

SDF_ATerm SDF_setATermWsAfterParenOpen(SDF_ATerm arg, char * wsAfterParenOpen)
{
  if (SDF_isATermAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterParenOpen, 0, ATtrue)), 0), 3), 2);
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterParenOpen, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("ATerm has no WsAfterParenOpen: %t\n", arg);
  return (SDF_ATerm)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermArgs(SDF_ATerm arg) */

ATbool SDF_hasATermArgs(SDF_ATerm arg)
{
  if (SDF_isATermAppl(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ATerms SDF_getATermArgs(SDF_ATerm arg) */

SDF_ATerms SDF_getATermArgs(SDF_ATerm arg)
{
  if (SDF_isATermAppl(arg)) {
    return (SDF_ATerms)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_ATerms)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("ATerm has no Args: %t\n", arg);
  return (SDF_ATerms)NULL;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermArgs(SDF_ATerm arg, SDF_ATerms args) */

SDF_ATerm SDF_setATermArgs(SDF_ATerm arg, SDF_ATerms args)
{
  if (SDF_isATermAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)args, 4), 2);
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)args, 4), 2);
  }

  ATabort("ATerm has no Args: %t\n", arg);
  return (SDF_ATerm)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermWsAfterArgs(SDF_ATerm arg) */

ATbool SDF_hasATermWsAfterArgs(SDF_ATerm arg)
{
  if (SDF_isATermAppl(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getATermWsAfterArgs(SDF_ATerm arg) */

char * SDF_getATermWsAfterArgs(SDF_ATerm arg)
{
  if (SDF_isATermAppl(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0)));
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0)));
  }

  ATabort("ATerm has no WsAfterArgs: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermWsAfterArgs(SDF_ATerm arg, char * wsAfterArgs) */

SDF_ATerm SDF_setATermWsAfterArgs(SDF_ATerm arg, char * wsAfterArgs)
{
  if (SDF_isATermAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterArgs, 0, ATtrue)), 0), 5), 2);
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterArgs, 0, ATtrue)), 0), 5), 2);
  }

  ATabort("ATerm has no WsAfterArgs: %t\n", arg);
  return (SDF_ATerm)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermWsAfterACon(SDF_ATerm arg) */

ATbool SDF_hasATermWsAfterACon(SDF_ATerm arg)
{
  if (SDF_isATermAnnotatedConstant(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getATermWsAfterACon(SDF_ATerm arg) */

char * SDF_getATermWsAfterACon(SDF_ATerm arg)
{
  if (SDF_isATermAnnotatedConstant(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("ATerm has no WsAfterACon: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermWsAfterACon(SDF_ATerm arg, char * wsAfterACon) */

SDF_ATerm SDF_setATermWsAfterACon(SDF_ATerm arg, char * wsAfterACon)
{
  if (SDF_isATermAnnotatedConstant(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterACon, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("ATerm has no WsAfterACon: %t\n", arg);
  return (SDF_ATerm)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermAnn(SDF_ATerm arg) */

ATbool SDF_hasATermAnn(SDF_ATerm arg)
{
  if (SDF_isATermAnnotatedConstant(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermAnnotatedList(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermAnnotatedFun(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Ann SDF_getATermAnn(SDF_ATerm arg) */

SDF_Ann SDF_getATermAnn(SDF_ATerm arg)
{
  if (SDF_isATermAnnotatedConstant(arg)) {
    return (SDF_Ann)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDF_isATermAnnotatedList(arg)) {
    return (SDF_Ann)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDF_isATermAnnotatedFun(arg)) {
    return (SDF_Ann)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_Ann)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 8);
  }

  ATabort("ATerm has no Ann: %t\n", arg);
  return (SDF_Ann)NULL;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermAnn(SDF_ATerm arg, SDF_Ann Ann) */

SDF_ATerm SDF_setATermAnn(SDF_ATerm arg, SDF_Ann Ann)
{
  if (SDF_isATermAnnotatedConstant(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Ann, 2), 2);
  }
  else if (SDF_isATermAnnotatedList(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Ann, 2), 2);
  }
  else if (SDF_isATermAnnotatedFun(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Ann, 2), 2);
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Ann, 8), 2);
  }

  ATabort("ATerm has no Ann: %t\n", arg);
  return (SDF_ATerm)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermWsAfterList(SDF_ATerm arg) */

ATbool SDF_hasATermWsAfterList(SDF_ATerm arg)
{
  if (SDF_isATermAnnotatedList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getATermWsAfterList(SDF_ATerm arg) */

char * SDF_getATermWsAfterList(SDF_ATerm arg)
{
  if (SDF_isATermAnnotatedList(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("ATerm has no WsAfterList: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermWsAfterList(SDF_ATerm arg, char * wsAfterList) */

SDF_ATerm SDF_setATermWsAfterList(SDF_ATerm arg, char * wsAfterList)
{
  if (SDF_isATermAnnotatedList(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterList, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("ATerm has no WsAfterList: %t\n", arg);
  return (SDF_ATerm)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermWsAfterParenClose(SDF_ATerm arg) */

ATbool SDF_hasATermWsAfterParenClose(SDF_ATerm arg)
{
  if (SDF_isATermAnnotatedAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getATermWsAfterParenClose(SDF_ATerm arg) */

char * SDF_getATermWsAfterParenClose(SDF_ATerm arg)
{
  if (SDF_isATermAnnotatedAppl(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), 0)));
  }

  ATabort("ATerm has no WsAfterParenClose: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermWsAfterParenClose(SDF_ATerm arg, char * wsAfterParenClose) */

SDF_ATerm SDF_setATermWsAfterParenClose(SDF_ATerm arg, char * wsAfterParenClose)
{
  if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterParenClose, 0, ATtrue)), 0), 7), 2);
  }

  ATabort("ATerm has no WsAfterParenClose: %t\n", arg);
  return (SDF_ATerm)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Ann accessors */

/*{{{  ATbool SDF_isValidAnn(SDF_Ann arg) */

ATbool SDF_isValidAnn(SDF_Ann arg)
{
  if (SDF_isAnnAnnotation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isAnnAnnotation(SDF_Ann arg) */

ATbool SDF_isAnnAnnotation(SDF_Ann arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAnnAnnotation, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasAnnWsAfterBraceOpen(SDF_Ann arg) */

ATbool SDF_hasAnnWsAfterBraceOpen(SDF_Ann arg)
{
  if (SDF_isAnnAnnotation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getAnnWsAfterBraceOpen(SDF_Ann arg) */

char * SDF_getAnnWsAfterBraceOpen(SDF_Ann arg)
{
  if (SDF_isAnnAnnotation(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Ann has no WsAfterBraceOpen: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Ann SDF_setAnnWsAfterBraceOpen(SDF_Ann arg, char * wsAfterBraceOpen) */

SDF_Ann SDF_setAnnWsAfterBraceOpen(SDF_Ann arg, char * wsAfterBraceOpen)
{
  if (SDF_isAnnAnnotation(arg)) {
    return (SDF_Ann)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterBraceOpen, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Ann has no WsAfterBraceOpen: %t\n", arg);
  return (SDF_Ann)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAnnATerms(SDF_Ann arg) */

ATbool SDF_hasAnnATerms(SDF_Ann arg)
{
  if (SDF_isAnnAnnotation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ATerms SDF_getAnnATerms(SDF_Ann arg) */

SDF_ATerms SDF_getAnnATerms(SDF_Ann arg)
{
  if (SDF_isAnnAnnotation(arg)) {
    return (SDF_ATerms)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Ann has no ATerms: %t\n", arg);
  return (SDF_ATerms)NULL;
}

/*}}}  */
/*{{{  SDF_Ann SDF_setAnnATerms(SDF_Ann arg, SDF_ATerms ATerms) */

SDF_Ann SDF_setAnnATerms(SDF_Ann arg, SDF_ATerms ATerms)
{
  if (SDF_isAnnAnnotation(arg)) {
    return (SDF_Ann)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATerms, 2), 2);
  }

  ATabort("Ann has no ATerms: %t\n", arg);
  return (SDF_Ann)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAnnWsAfterATerms(SDF_Ann arg) */

ATbool SDF_hasAnnWsAfterATerms(SDF_Ann arg)
{
  if (SDF_isAnnAnnotation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getAnnWsAfterATerms(SDF_Ann arg) */

char * SDF_getAnnWsAfterATerms(SDF_Ann arg)
{
  if (SDF_isAnnAnnotation(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Ann has no WsAfterATerms: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_Ann SDF_setAnnWsAfterATerms(SDF_Ann arg, char * wsAfterATerms) */

SDF_Ann SDF_setAnnWsAfterATerms(SDF_Ann arg, char * wsAfterATerms)
{
  if (SDF_isAnnAnnotation(arg)) {
    return (SDF_Ann)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterATerms, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Ann has no WsAfterATerms: %t\n", arg);
  return (SDF_Ann)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_TagId accessors */

/*{{{  ATbool SDF_isValidTagId(SDF_TagId arg) */

ATbool SDF_isValidTagId(SDF_TagId arg)
{
  if (SDF_isTagIdDefault(arg)) {
    return ATtrue;
  }
  else if (SDF_isTagIdEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isTagIdDefault(SDF_TagId arg) */

ATbool SDF_isTagIdDefault(SDF_TagId arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternTagIdDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isTagIdEmpty(SDF_TagId arg) */

ATbool SDF_isTagIdEmpty(SDF_TagId arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternTagIdEmpty);
}

/*}}}  */
/*{{{  ATbool SDF_hasTagIdLex(SDF_TagId arg) */

ATbool SDF_hasTagIdLex(SDF_TagId arg)
{
  if (SDF_isTagIdDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getTagIdLex(SDF_TagId arg) */

char * SDF_getTagIdLex(SDF_TagId arg)
{
  if (SDF_isTagIdDefault(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }

  ATabort("TagId has no Lex: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_TagId SDF_setTagIdLex(SDF_TagId arg, char * lex) */

SDF_TagId SDF_setTagIdLex(SDF_TagId arg, char * lex)
{
  if (SDF_isTagIdDefault(arg)) {
    return (SDF_TagId)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }

  ATabort("TagId has no Lex: %t\n", arg);
  return (SDF_TagId)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_NumChar accessors */

/*{{{  ATbool SDF_isValidNumChar(SDF_NumChar arg) */

ATbool SDF_isValidNumChar(SDF_NumChar arg)
{
  if (SDF_isNumCharDigits(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isNumCharDigits(SDF_NumChar arg) */

ATbool SDF_isNumCharDigits(SDF_NumChar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternNumCharDigits, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasNumCharLex(SDF_NumChar arg) */

ATbool SDF_hasNumCharLex(SDF_NumChar arg)
{
  if (SDF_isNumCharDigits(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getNumCharLex(SDF_NumChar arg) */

char * SDF_getNumCharLex(SDF_NumChar arg)
{
  if (SDF_isNumCharDigits(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }

  ATabort("NumChar has no Lex: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_NumChar SDF_setNumCharLex(SDF_NumChar arg, char * lex) */

SDF_NumChar SDF_setNumCharLex(SDF_NumChar arg, char * lex)
{
  if (SDF_isNumCharDigits(arg)) {
    return (SDF_NumChar)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }

  ATabort("NumChar has no Lex: %t\n", arg);
  return (SDF_NumChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ShortChar accessors */

/*{{{  ATbool SDF_isValidShortChar(SDF_ShortChar arg) */

ATbool SDF_isValidShortChar(SDF_ShortChar arg)
{
  if (SDF_isShortCharRegular(arg)) {
    return ATtrue;
  }
  else if (SDF_isShortCharEscaped(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isShortCharRegular(SDF_ShortChar arg) */

ATbool SDF_isShortCharRegular(SDF_ShortChar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternShortCharRegular, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isShortCharEscaped(SDF_ShortChar arg) */

ATbool SDF_isShortCharEscaped(SDF_ShortChar arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternShortCharEscaped, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasShortCharLex(SDF_ShortChar arg) */

ATbool SDF_hasShortCharLex(SDF_ShortChar arg)
{
  if (SDF_isShortCharRegular(arg)) {
    return ATtrue;
  }
  else if (SDF_isShortCharEscaped(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getShortCharLex(SDF_ShortChar arg) */

char * SDF_getShortCharLex(SDF_ShortChar arg)
{
  if (SDF_isShortCharRegular(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (SDF_isShortCharEscaped(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }

  ATabort("ShortChar has no Lex: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_ShortChar SDF_setShortCharLex(SDF_ShortChar arg, char * lex) */

SDF_ShortChar SDF_setShortCharLex(SDF_ShortChar arg, char * lex)
{
  if (SDF_isShortCharRegular(arg)) {
    return (SDF_ShortChar)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }
  else if (SDF_isShortCharEscaped(arg)) {
    return (SDF_ShortChar)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }

  ATabort("ShortChar has no Lex: %t\n", arg);
  return (SDF_ShortChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Character accessors */

/*{{{  ATbool SDF_isValidCharacter(SDF_Character arg) */

ATbool SDF_isValidCharacter(SDF_Character arg)
{
  if (SDF_isCharacterNumeric(arg)) {
    return ATtrue;
  }
  else if (SDF_isCharacterShort(arg)) {
    return ATtrue;
  }
  else if (SDF_isCharacterTop(arg)) {
    return ATtrue;
  }
  else if (SDF_isCharacterEof(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isCharacterNumeric(SDF_Character arg) */

ATbool SDF_isCharacterNumeric(SDF_Character arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternCharacterNumeric, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isCharacterShort(SDF_Character arg) */

ATbool SDF_isCharacterShort(SDF_Character arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternCharacterShort, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isCharacterTop(SDF_Character arg) */

ATbool SDF_isCharacterTop(SDF_Character arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternCharacterTop);
}

/*}}}  */
/*{{{  ATbool SDF_isCharacterEof(SDF_Character arg) */

ATbool SDF_isCharacterEof(SDF_Character arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternCharacterEof);
}

/*}}}  */
/*{{{  ATbool SDF_hasCharacterNumChar(SDF_Character arg) */

ATbool SDF_hasCharacterNumChar(SDF_Character arg)
{
  if (SDF_isCharacterNumeric(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_NumChar SDF_getCharacterNumChar(SDF_Character arg) */

SDF_NumChar SDF_getCharacterNumChar(SDF_Character arg)
{
  if (SDF_isCharacterNumeric(arg)) {
    return (SDF_NumChar)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Character has no NumChar: %t\n", arg);
  return (SDF_NumChar)NULL;
}

/*}}}  */
/*{{{  SDF_Character SDF_setCharacterNumChar(SDF_Character arg, SDF_NumChar NumChar) */

SDF_Character SDF_setCharacterNumChar(SDF_Character arg, SDF_NumChar NumChar)
{
  if (SDF_isCharacterNumeric(arg)) {
    return (SDF_Character)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)NumChar, 0), 2);
  }

  ATabort("Character has no NumChar: %t\n", arg);
  return (SDF_Character)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasCharacterShortChar(SDF_Character arg) */

ATbool SDF_hasCharacterShortChar(SDF_Character arg)
{
  if (SDF_isCharacterShort(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ShortChar SDF_getCharacterShortChar(SDF_Character arg) */

SDF_ShortChar SDF_getCharacterShortChar(SDF_Character arg)
{
  if (SDF_isCharacterShort(arg)) {
    return (SDF_ShortChar)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Character has no ShortChar: %t\n", arg);
  return (SDF_ShortChar)NULL;
}

/*}}}  */
/*{{{  SDF_Character SDF_setCharacterShortChar(SDF_Character arg, SDF_ShortChar ShortChar) */

SDF_Character SDF_setCharacterShortChar(SDF_Character arg, SDF_ShortChar ShortChar)
{
  if (SDF_isCharacterShort(arg)) {
    return (SDF_Character)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ShortChar, 0), 2);
  }

  ATabort("Character has no ShortChar: %t\n", arg);
  return (SDF_Character)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_OptExp accessors */

/*{{{  ATbool SDF_isValidOptExp(SDF_OptExp arg) */

ATbool SDF_isValidOptExp(SDF_OptExp arg)
{
  if (SDF_isOptExpPresent(arg)) {
    return ATtrue;
  }
  else if (SDF_isOptExpAbsent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isOptExpPresent(SDF_OptExp arg) */

ATbool SDF_isOptExpPresent(SDF_OptExp arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternOptExpPresent, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isOptExpAbsent(SDF_OptExp arg) */

ATbool SDF_isOptExpAbsent(SDF_OptExp arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternOptExpAbsent);
}

/*}}}  */
/*{{{  ATbool SDF_hasOptExpWsAfterE(SDF_OptExp arg) */

ATbool SDF_hasOptExpWsAfterE(SDF_OptExp arg)
{
  if (SDF_isOptExpPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getOptExpWsAfterE(SDF_OptExp arg) */

char * SDF_getOptExpWsAfterE(SDF_OptExp arg)
{
  if (SDF_isOptExpPresent(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("OptExp has no WsAfterE: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_OptExp SDF_setOptExpWsAfterE(SDF_OptExp arg, char * wsAfterE) */

SDF_OptExp SDF_setOptExpWsAfterE(SDF_OptExp arg, char * wsAfterE)
{
  if (SDF_isOptExpPresent(arg)) {
    return (SDF_OptExp)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterE, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("OptExp has no WsAfterE: %t\n", arg);
  return (SDF_OptExp)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasOptExpIntCon(SDF_OptExp arg) */

ATbool SDF_hasOptExpIntCon(SDF_OptExp arg)
{
  if (SDF_isOptExpPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_IntCon SDF_getOptExpIntCon(SDF_OptExp arg) */

SDF_IntCon SDF_getOptExpIntCon(SDF_OptExp arg)
{
  if (SDF_isOptExpPresent(arg)) {
    return (SDF_IntCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("OptExp has no IntCon: %t\n", arg);
  return (SDF_IntCon)NULL;
}

/*}}}  */
/*{{{  SDF_OptExp SDF_setOptExpIntCon(SDF_OptExp arg, SDF_IntCon IntCon) */

SDF_OptExp SDF_setOptExpIntCon(SDF_OptExp arg, SDF_IntCon IntCon)
{
  if (SDF_isOptExpPresent(arg)) {
    return (SDF_OptExp)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)IntCon, 2), 2);
  }

  ATabort("OptExp has no IntCon: %t\n", arg);
  return (SDF_OptExp)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_RealCon accessors */

/*{{{  ATbool SDF_isValidRealCon(SDF_RealCon arg) */

ATbool SDF_isValidRealCon(SDF_RealCon arg)
{
  if (SDF_isRealConRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isRealConRealCon(SDF_RealCon arg) */

ATbool SDF_isRealConRealCon(SDF_RealCon arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternRealConRealCon, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasRealConIntCon(SDF_RealCon arg) */

ATbool SDF_hasRealConIntCon(SDF_RealCon arg)
{
  if (SDF_isRealConRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_IntCon SDF_getRealConIntCon(SDF_RealCon arg) */

SDF_IntCon SDF_getRealConIntCon(SDF_RealCon arg)
{
  if (SDF_isRealConRealCon(arg)) {
    return (SDF_IntCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("RealCon has no IntCon: %t\n", arg);
  return (SDF_IntCon)NULL;
}

/*}}}  */
/*{{{  SDF_RealCon SDF_setRealConIntCon(SDF_RealCon arg, SDF_IntCon IntCon) */

SDF_RealCon SDF_setRealConIntCon(SDF_RealCon arg, SDF_IntCon IntCon)
{
  if (SDF_isRealConRealCon(arg)) {
    return (SDF_RealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)IntCon, 0), 2);
  }

  ATabort("RealCon has no IntCon: %t\n", arg);
  return (SDF_RealCon)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasRealConWsAfterIntCon(SDF_RealCon arg) */

ATbool SDF_hasRealConWsAfterIntCon(SDF_RealCon arg)
{
  if (SDF_isRealConRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getRealConWsAfterIntCon(SDF_RealCon arg) */

char * SDF_getRealConWsAfterIntCon(SDF_RealCon arg)
{
  if (SDF_isRealConRealCon(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("RealCon has no WsAfterIntCon: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_RealCon SDF_setRealConWsAfterIntCon(SDF_RealCon arg, char * wsAfterIntCon) */

SDF_RealCon SDF_setRealConWsAfterIntCon(SDF_RealCon arg, char * wsAfterIntCon)
{
  if (SDF_isRealConRealCon(arg)) {
    return (SDF_RealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterIntCon, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("RealCon has no WsAfterIntCon: %t\n", arg);
  return (SDF_RealCon)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasRealConWsAfterPeriod(SDF_RealCon arg) */

ATbool SDF_hasRealConWsAfterPeriod(SDF_RealCon arg)
{
  if (SDF_isRealConRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getRealConWsAfterPeriod(SDF_RealCon arg) */

char * SDF_getRealConWsAfterPeriod(SDF_RealCon arg)
{
  if (SDF_isRealConRealCon(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("RealCon has no WsAfterPeriod: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_RealCon SDF_setRealConWsAfterPeriod(SDF_RealCon arg, char * wsAfterPeriod) */

SDF_RealCon SDF_setRealConWsAfterPeriod(SDF_RealCon arg, char * wsAfterPeriod)
{
  if (SDF_isRealConRealCon(arg)) {
    return (SDF_RealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterPeriod, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("RealCon has no WsAfterPeriod: %t\n", arg);
  return (SDF_RealCon)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasRealConNatCon(SDF_RealCon arg) */

ATbool SDF_hasRealConNatCon(SDF_RealCon arg)
{
  if (SDF_isRealConRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_NatCon SDF_getRealConNatCon(SDF_RealCon arg) */

SDF_NatCon SDF_getRealConNatCon(SDF_RealCon arg)
{
  if (SDF_isRealConRealCon(arg)) {
    return (SDF_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("RealCon has no NatCon: %t\n", arg);
  return (SDF_NatCon)NULL;
}

/*}}}  */
/*{{{  SDF_RealCon SDF_setRealConNatCon(SDF_RealCon arg, SDF_NatCon NatCon) */

SDF_RealCon SDF_setRealConNatCon(SDF_RealCon arg, SDF_NatCon NatCon)
{
  if (SDF_isRealConRealCon(arg)) {
    return (SDF_RealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)NatCon, 4), 2);
  }

  ATabort("RealCon has no NatCon: %t\n", arg);
  return (SDF_RealCon)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasRealConWsAfterNatCon(SDF_RealCon arg) */

ATbool SDF_hasRealConWsAfterNatCon(SDF_RealCon arg)
{
  if (SDF_isRealConRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getRealConWsAfterNatCon(SDF_RealCon arg) */

char * SDF_getRealConWsAfterNatCon(SDF_RealCon arg)
{
  if (SDF_isRealConRealCon(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0)));
  }

  ATabort("RealCon has no WsAfterNatCon: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SDF_RealCon SDF_setRealConWsAfterNatCon(SDF_RealCon arg, char * wsAfterNatCon) */

SDF_RealCon SDF_setRealConWsAfterNatCon(SDF_RealCon arg, char * wsAfterNatCon)
{
  if (SDF_isRealConRealCon(arg)) {
    return (SDF_RealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterNatCon, 0, ATtrue)), 0), 5), 2);
  }

  ATabort("RealCon has no WsAfterNatCon: %t\n", arg);
  return (SDF_RealCon)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasRealConOptExp(SDF_RealCon arg) */

ATbool SDF_hasRealConOptExp(SDF_RealCon arg)
{
  if (SDF_isRealConRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptExp SDF_getRealConOptExp(SDF_RealCon arg) */

SDF_OptExp SDF_getRealConOptExp(SDF_RealCon arg)
{
  if (SDF_isRealConRealCon(arg)) {
    return (SDF_OptExp)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 6);
  }

  ATabort("RealCon has no OptExp: %t\n", arg);
  return (SDF_OptExp)NULL;
}

/*}}}  */
/*{{{  SDF_RealCon SDF_setRealConOptExp(SDF_RealCon arg, SDF_OptExp OptExp) */

SDF_RealCon SDF_setRealConOptExp(SDF_RealCon arg, SDF_OptExp OptExp)
{
  if (SDF_isRealConRealCon(arg)) {
    return (SDF_RealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)OptExp, 6), 2);
  }

  ATabort("RealCon has no OptExp: %t\n", arg);
  return (SDF_RealCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  SDF_Symbol SDF_visitSymbol(SDF_Symbol arg, char * (*acceptWsAfterLessThan)(char *), char * (*acceptWsAfterSymbol)(char *), char * (*acceptWsAfterCF)(char *), char * (*acceptWsAfterLEX)(char *), char * (*acceptWsAfterVAR)(char *), char * (*acceptWsAfterParenOpen)(char *), char * (*acceptWsAfterHead)(char *), SDF_SymbolTail (*acceptTail)(SDF_SymbolTail), char * (*acceptWsAfterTail)(char *), char * (*acceptWsAfterBraceOpen)(char *), char * (*acceptWsAfterSep)(char *), char * (*acceptWsAfterBraceClose)(char *), SDF_NatCon (*acceptN)(SDF_NatCon), char * (*acceptWsAfterN)(char *), char * (*acceptWsAfterSet)(char *), char * (*acceptWsAfterBracketOpen)(char *), char * (*acceptWsAfterLeft)(char *), char * (*acceptWsAfterHash)(char *), SDF_Symbols (*acceptArguments)(SDF_Symbols), char * (*acceptWsAfterArguments)(char *), char * (*acceptWsAfterEqualsGreaterThan)(char *), char * (*acceptWsAfterResults)(char *), char * (*acceptWsAfterBar)(char *), char * (*acceptWsAfterLessThanLessThan)(char *), SDF_Symbols (*acceptSymbols)(SDF_Symbols), char * (*acceptWsAfterSymbols)(char *), SDF_CharClass (*acceptCharClass)(SDF_CharClass), SDF_Sort (*acceptSort)(SDF_Sort), SDF_Literal (*acceptLiteral)(SDF_Literal), SDF_Literal (*acceptLabel)(SDF_Literal), char * (*acceptWsAfterLabel)(char *), char * (*acceptWsAfterColon)(char *)) */

SDF_Symbol SDF_visitSymbol(SDF_Symbol arg, char * (*acceptWsAfterLessThan)(char *), char * (*acceptWsAfterSymbol)(char *), char * (*acceptWsAfterCF)(char *), char * (*acceptWsAfterLEX)(char *), char * (*acceptWsAfterVAR)(char *), char * (*acceptWsAfterParenOpen)(char *), char * (*acceptWsAfterHead)(char *), SDF_SymbolTail (*acceptTail)(SDF_SymbolTail), char * (*acceptWsAfterTail)(char *), char * (*acceptWsAfterBraceOpen)(char *), char * (*acceptWsAfterSep)(char *), char * (*acceptWsAfterBraceClose)(char *), SDF_NatCon (*acceptN)(SDF_NatCon), char * (*acceptWsAfterN)(char *), char * (*acceptWsAfterSet)(char *), char * (*acceptWsAfterBracketOpen)(char *), char * (*acceptWsAfterLeft)(char *), char * (*acceptWsAfterHash)(char *), SDF_Symbols (*acceptArguments)(SDF_Symbols), char * (*acceptWsAfterArguments)(char *), char * (*acceptWsAfterEqualsGreaterThan)(char *), char * (*acceptWsAfterResults)(char *), char * (*acceptWsAfterBar)(char *), char * (*acceptWsAfterLessThanLessThan)(char *), SDF_Symbols (*acceptSymbols)(SDF_Symbols), char * (*acceptWsAfterSymbols)(char *), SDF_CharClass (*acceptCharClass)(SDF_CharClass), SDF_Sort (*acceptSort)(SDF_Sort), SDF_Literal (*acceptLiteral)(SDF_Literal), SDF_Literal (*acceptLabel)(SDF_Literal), char * (*acceptWsAfterLabel)(char *), char * (*acceptWsAfterColon)(char *))
{
  if (SDF_isSymbolStart(arg)) {
    return SDF_makeSymbolStart();
  }
  if (SDF_isSymbolFileStart(arg)) {
    return SDF_makeSymbolFileStart();
  }
  if (SDF_isSymbolCf(arg)) {
    return SDF_makeSymbolCf(
        acceptWsAfterLessThan ? acceptWsAfterLessThan(SDF_getSymbolWsAfterLessThan(arg)) : SDF_getSymbolWsAfterLessThan(arg),
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptWsAfterLessThan, acceptWsAfterSymbol, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterSet, acceptWsAfterBracketOpen, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterLessThanLessThan, acceptSymbols, acceptWsAfterSymbols, acceptCharClass, acceptSort, acceptLiteral, acceptLabel, acceptWsAfterLabel, acceptWsAfterColon),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(SDF_getSymbolWsAfterSymbol(arg)) : SDF_getSymbolWsAfterSymbol(arg),
        acceptWsAfterCF ? acceptWsAfterCF(SDF_getSymbolWsAfterCF(arg)) : SDF_getSymbolWsAfterCF(arg));
  }
  if (SDF_isSymbolLex(arg)) {
    return SDF_makeSymbolLex(
        acceptWsAfterLessThan ? acceptWsAfterLessThan(SDF_getSymbolWsAfterLessThan(arg)) : SDF_getSymbolWsAfterLessThan(arg),
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptWsAfterLessThan, acceptWsAfterSymbol, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterSet, acceptWsAfterBracketOpen, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterLessThanLessThan, acceptSymbols, acceptWsAfterSymbols, acceptCharClass, acceptSort, acceptLiteral, acceptLabel, acceptWsAfterLabel, acceptWsAfterColon),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(SDF_getSymbolWsAfterSymbol(arg)) : SDF_getSymbolWsAfterSymbol(arg),
        acceptWsAfterLEX ? acceptWsAfterLEX(SDF_getSymbolWsAfterLEX(arg)) : SDF_getSymbolWsAfterLEX(arg));
  }
  if (SDF_isSymbolVarsym(arg)) {
    return SDF_makeSymbolVarsym(
        acceptWsAfterLessThan ? acceptWsAfterLessThan(SDF_getSymbolWsAfterLessThan(arg)) : SDF_getSymbolWsAfterLessThan(arg),
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptWsAfterLessThan, acceptWsAfterSymbol, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterSet, acceptWsAfterBracketOpen, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterLessThanLessThan, acceptSymbols, acceptWsAfterSymbols, acceptCharClass, acceptSort, acceptLiteral, acceptLabel, acceptWsAfterLabel, acceptWsAfterColon),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(SDF_getSymbolWsAfterSymbol(arg)) : SDF_getSymbolWsAfterSymbol(arg),
        acceptWsAfterVAR ? acceptWsAfterVAR(SDF_getSymbolWsAfterVAR(arg)) : SDF_getSymbolWsAfterVAR(arg));
  }
  if (SDF_isSymbolLayout(arg)) {
    return SDF_makeSymbolLayout();
  }
  if (SDF_isSymbolEmpty(arg)) {
    return SDF_makeSymbolEmpty(
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(SDF_getSymbolWsAfterParenOpen(arg)) : SDF_getSymbolWsAfterParenOpen(arg));
  }
  if (SDF_isSymbolSeq(arg)) {
    return SDF_makeSymbolSeq(
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(SDF_getSymbolWsAfterParenOpen(arg)) : SDF_getSymbolWsAfterParenOpen(arg),
        SDF_visitSymbol(SDF_getSymbolHead(arg), acceptWsAfterLessThan, acceptWsAfterSymbol, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterSet, acceptWsAfterBracketOpen, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterLessThanLessThan, acceptSymbols, acceptWsAfterSymbols, acceptCharClass, acceptSort, acceptLiteral, acceptLabel, acceptWsAfterLabel, acceptWsAfterColon),
        acceptWsAfterHead ? acceptWsAfterHead(SDF_getSymbolWsAfterHead(arg)) : SDF_getSymbolWsAfterHead(arg),
        acceptTail ? acceptTail(SDF_getSymbolTail(arg)) : SDF_getSymbolTail(arg),
        acceptWsAfterTail ? acceptWsAfterTail(SDF_getSymbolWsAfterTail(arg)) : SDF_getSymbolWsAfterTail(arg));
  }
  if (SDF_isSymbolOpt(arg)) {
    return SDF_makeSymbolOpt(
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptWsAfterLessThan, acceptWsAfterSymbol, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterSet, acceptWsAfterBracketOpen, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterLessThanLessThan, acceptSymbols, acceptWsAfterSymbols, acceptCharClass, acceptSort, acceptLiteral, acceptLabel, acceptWsAfterLabel, acceptWsAfterColon),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(SDF_getSymbolWsAfterSymbol(arg)) : SDF_getSymbolWsAfterSymbol(arg));
  }
  if (SDF_isSymbolIter(arg)) {
    return SDF_makeSymbolIter(
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptWsAfterLessThan, acceptWsAfterSymbol, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterSet, acceptWsAfterBracketOpen, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterLessThanLessThan, acceptSymbols, acceptWsAfterSymbols, acceptCharClass, acceptSort, acceptLiteral, acceptLabel, acceptWsAfterLabel, acceptWsAfterColon),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(SDF_getSymbolWsAfterSymbol(arg)) : SDF_getSymbolWsAfterSymbol(arg));
  }
  if (SDF_isSymbolIterStar(arg)) {
    return SDF_makeSymbolIterStar(
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptWsAfterLessThan, acceptWsAfterSymbol, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterSet, acceptWsAfterBracketOpen, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterLessThanLessThan, acceptSymbols, acceptWsAfterSymbols, acceptCharClass, acceptSort, acceptLiteral, acceptLabel, acceptWsAfterLabel, acceptWsAfterColon),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(SDF_getSymbolWsAfterSymbol(arg)) : SDF_getSymbolWsAfterSymbol(arg));
  }
  if (SDF_isSymbolIterSep(arg)) {
    return SDF_makeSymbolIterSep(
        acceptWsAfterBraceOpen ? acceptWsAfterBraceOpen(SDF_getSymbolWsAfterBraceOpen(arg)) : SDF_getSymbolWsAfterBraceOpen(arg),
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptWsAfterLessThan, acceptWsAfterSymbol, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterSet, acceptWsAfterBracketOpen, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterLessThanLessThan, acceptSymbols, acceptWsAfterSymbols, acceptCharClass, acceptSort, acceptLiteral, acceptLabel, acceptWsAfterLabel, acceptWsAfterColon),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(SDF_getSymbolWsAfterSymbol(arg)) : SDF_getSymbolWsAfterSymbol(arg),
        SDF_visitSymbol(SDF_getSymbolSep(arg), acceptWsAfterLessThan, acceptWsAfterSymbol, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterSet, acceptWsAfterBracketOpen, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterLessThanLessThan, acceptSymbols, acceptWsAfterSymbols, acceptCharClass, acceptSort, acceptLiteral, acceptLabel, acceptWsAfterLabel, acceptWsAfterColon),
        acceptWsAfterSep ? acceptWsAfterSep(SDF_getSymbolWsAfterSep(arg)) : SDF_getSymbolWsAfterSep(arg),
        acceptWsAfterBraceClose ? acceptWsAfterBraceClose(SDF_getSymbolWsAfterBraceClose(arg)) : SDF_getSymbolWsAfterBraceClose(arg));
  }
  if (SDF_isSymbolIterStarSep(arg)) {
    return SDF_makeSymbolIterStarSep(
        acceptWsAfterBraceOpen ? acceptWsAfterBraceOpen(SDF_getSymbolWsAfterBraceOpen(arg)) : SDF_getSymbolWsAfterBraceOpen(arg),
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptWsAfterLessThan, acceptWsAfterSymbol, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterSet, acceptWsAfterBracketOpen, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterLessThanLessThan, acceptSymbols, acceptWsAfterSymbols, acceptCharClass, acceptSort, acceptLiteral, acceptLabel, acceptWsAfterLabel, acceptWsAfterColon),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(SDF_getSymbolWsAfterSymbol(arg)) : SDF_getSymbolWsAfterSymbol(arg),
        SDF_visitSymbol(SDF_getSymbolSep(arg), acceptWsAfterLessThan, acceptWsAfterSymbol, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterSet, acceptWsAfterBracketOpen, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterLessThanLessThan, acceptSymbols, acceptWsAfterSymbols, acceptCharClass, acceptSort, acceptLiteral, acceptLabel, acceptWsAfterLabel, acceptWsAfterColon),
        acceptWsAfterSep ? acceptWsAfterSep(SDF_getSymbolWsAfterSep(arg)) : SDF_getSymbolWsAfterSep(arg),
        acceptWsAfterBraceClose ? acceptWsAfterBraceClose(SDF_getSymbolWsAfterBraceClose(arg)) : SDF_getSymbolWsAfterBraceClose(arg));
  }
  if (SDF_isSymbolIterN(arg)) {
    return SDF_makeSymbolIterN(
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptWsAfterLessThan, acceptWsAfterSymbol, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterSet, acceptWsAfterBracketOpen, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterLessThanLessThan, acceptSymbols, acceptWsAfterSymbols, acceptCharClass, acceptSort, acceptLiteral, acceptLabel, acceptWsAfterLabel, acceptWsAfterColon),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(SDF_getSymbolWsAfterSymbol(arg)) : SDF_getSymbolWsAfterSymbol(arg),
        acceptN ? acceptN(SDF_getSymbolN(arg)) : SDF_getSymbolN(arg),
        acceptWsAfterN ? acceptWsAfterN(SDF_getSymbolWsAfterN(arg)) : SDF_getSymbolWsAfterN(arg));
  }
  if (SDF_isSymbolIterSepN(arg)) {
    return SDF_makeSymbolIterSepN(
        acceptWsAfterBraceOpen ? acceptWsAfterBraceOpen(SDF_getSymbolWsAfterBraceOpen(arg)) : SDF_getSymbolWsAfterBraceOpen(arg),
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptWsAfterLessThan, acceptWsAfterSymbol, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterSet, acceptWsAfterBracketOpen, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterLessThanLessThan, acceptSymbols, acceptWsAfterSymbols, acceptCharClass, acceptSort, acceptLiteral, acceptLabel, acceptWsAfterLabel, acceptWsAfterColon),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(SDF_getSymbolWsAfterSymbol(arg)) : SDF_getSymbolWsAfterSymbol(arg),
        SDF_visitSymbol(SDF_getSymbolSep(arg), acceptWsAfterLessThan, acceptWsAfterSymbol, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterSet, acceptWsAfterBracketOpen, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterLessThanLessThan, acceptSymbols, acceptWsAfterSymbols, acceptCharClass, acceptSort, acceptLiteral, acceptLabel, acceptWsAfterLabel, acceptWsAfterColon),
        acceptWsAfterSep ? acceptWsAfterSep(SDF_getSymbolWsAfterSep(arg)) : SDF_getSymbolWsAfterSep(arg),
        acceptWsAfterBraceClose ? acceptWsAfterBraceClose(SDF_getSymbolWsAfterBraceClose(arg)) : SDF_getSymbolWsAfterBraceClose(arg),
        acceptN ? acceptN(SDF_getSymbolN(arg)) : SDF_getSymbolN(arg),
        acceptWsAfterN ? acceptWsAfterN(SDF_getSymbolWsAfterN(arg)) : SDF_getSymbolWsAfterN(arg));
  }
  if (SDF_isSymbolSet(arg)) {
    return SDF_makeSymbolSet(
        acceptWsAfterSet ? acceptWsAfterSet(SDF_getSymbolWsAfterSet(arg)) : SDF_getSymbolWsAfterSet(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(SDF_getSymbolWsAfterBracketOpen(arg)) : SDF_getSymbolWsAfterBracketOpen(arg),
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptWsAfterLessThan, acceptWsAfterSymbol, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterSet, acceptWsAfterBracketOpen, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterLessThanLessThan, acceptSymbols, acceptWsAfterSymbols, acceptCharClass, acceptSort, acceptLiteral, acceptLabel, acceptWsAfterLabel, acceptWsAfterColon),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(SDF_getSymbolWsAfterSymbol(arg)) : SDF_getSymbolWsAfterSymbol(arg));
  }
  if (SDF_isSymbolPair(arg)) {
    return SDF_makeSymbolPair(
        SDF_visitSymbol(SDF_getSymbolLeft(arg), acceptWsAfterLessThan, acceptWsAfterSymbol, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterSet, acceptWsAfterBracketOpen, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterLessThanLessThan, acceptSymbols, acceptWsAfterSymbols, acceptCharClass, acceptSort, acceptLiteral, acceptLabel, acceptWsAfterLabel, acceptWsAfterColon),
        acceptWsAfterLeft ? acceptWsAfterLeft(SDF_getSymbolWsAfterLeft(arg)) : SDF_getSymbolWsAfterLeft(arg),
        acceptWsAfterHash ? acceptWsAfterHash(SDF_getSymbolWsAfterHash(arg)) : SDF_getSymbolWsAfterHash(arg),
        SDF_visitSymbol(SDF_getSymbolRight(arg), acceptWsAfterLessThan, acceptWsAfterSymbol, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterSet, acceptWsAfterBracketOpen, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterLessThanLessThan, acceptSymbols, acceptWsAfterSymbols, acceptCharClass, acceptSort, acceptLiteral, acceptLabel, acceptWsAfterLabel, acceptWsAfterColon));
  }
  if (SDF_isSymbolFunc(arg)) {
    return SDF_makeSymbolFunc(
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(SDF_getSymbolWsAfterParenOpen(arg)) : SDF_getSymbolWsAfterParenOpen(arg),
        acceptArguments ? acceptArguments(SDF_getSymbolArguments(arg)) : SDF_getSymbolArguments(arg),
        acceptWsAfterArguments ? acceptWsAfterArguments(SDF_getSymbolWsAfterArguments(arg)) : SDF_getSymbolWsAfterArguments(arg),
        acceptWsAfterEqualsGreaterThan ? acceptWsAfterEqualsGreaterThan(SDF_getSymbolWsAfterEqualsGreaterThan(arg)) : SDF_getSymbolWsAfterEqualsGreaterThan(arg),
        SDF_visitSymbol(SDF_getSymbolResults(arg), acceptWsAfterLessThan, acceptWsAfterSymbol, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterSet, acceptWsAfterBracketOpen, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterLessThanLessThan, acceptSymbols, acceptWsAfterSymbols, acceptCharClass, acceptSort, acceptLiteral, acceptLabel, acceptWsAfterLabel, acceptWsAfterColon),
        acceptWsAfterResults ? acceptWsAfterResults(SDF_getSymbolWsAfterResults(arg)) : SDF_getSymbolWsAfterResults(arg));
  }
  if (SDF_isSymbolAlt(arg)) {
    return SDF_makeSymbolAlt(
        SDF_visitSymbol(SDF_getSymbolLeft(arg), acceptWsAfterLessThan, acceptWsAfterSymbol, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterSet, acceptWsAfterBracketOpen, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterLessThanLessThan, acceptSymbols, acceptWsAfterSymbols, acceptCharClass, acceptSort, acceptLiteral, acceptLabel, acceptWsAfterLabel, acceptWsAfterColon),
        acceptWsAfterLeft ? acceptWsAfterLeft(SDF_getSymbolWsAfterLeft(arg)) : SDF_getSymbolWsAfterLeft(arg),
        acceptWsAfterBar ? acceptWsAfterBar(SDF_getSymbolWsAfterBar(arg)) : SDF_getSymbolWsAfterBar(arg),
        SDF_visitSymbol(SDF_getSymbolRight(arg), acceptWsAfterLessThan, acceptWsAfterSymbol, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterSet, acceptWsAfterBracketOpen, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterLessThanLessThan, acceptSymbols, acceptWsAfterSymbols, acceptCharClass, acceptSort, acceptLiteral, acceptLabel, acceptWsAfterLabel, acceptWsAfterColon));
  }
  if (SDF_isSymbolPerm(arg)) {
    return SDF_makeSymbolPerm(
        acceptWsAfterLessThanLessThan ? acceptWsAfterLessThanLessThan(SDF_getSymbolWsAfterLessThanLessThan(arg)) : SDF_getSymbolWsAfterLessThanLessThan(arg),
        acceptSymbols ? acceptSymbols(SDF_getSymbolSymbols(arg)) : SDF_getSymbolSymbols(arg),
        acceptWsAfterSymbols ? acceptWsAfterSymbols(SDF_getSymbolWsAfterSymbols(arg)) : SDF_getSymbolWsAfterSymbols(arg));
  }
  if (SDF_isSymbolCharClass(arg)) {
    return SDF_makeSymbolCharClass(
        acceptCharClass ? acceptCharClass(SDF_getSymbolCharClass(arg)) : SDF_getSymbolCharClass(arg));
  }
  if (SDF_isSymbolSort(arg)) {
    return SDF_makeSymbolSort(
        acceptSort ? acceptSort(SDF_getSymbolSort(arg)) : SDF_getSymbolSort(arg));
  }
  if (SDF_isSymbolLit(arg)) {
    return SDF_makeSymbolLit(
        acceptLiteral ? acceptLiteral(SDF_getSymbolLiteral(arg)) : SDF_getSymbolLiteral(arg));
  }
  if (SDF_isSymbolLabel(arg)) {
    return SDF_makeSymbolLabel(
        acceptLabel ? acceptLabel(SDF_getSymbolLabel(arg)) : SDF_getSymbolLabel(arg),
        acceptWsAfterLabel ? acceptWsAfterLabel(SDF_getSymbolWsAfterLabel(arg)) : SDF_getSymbolWsAfterLabel(arg),
        acceptWsAfterColon ? acceptWsAfterColon(SDF_getSymbolWsAfterColon(arg)) : SDF_getSymbolWsAfterColon(arg),
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptWsAfterLessThan, acceptWsAfterSymbol, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterSet, acceptWsAfterBracketOpen, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterLessThanLessThan, acceptSymbols, acceptWsAfterSymbols, acceptCharClass, acceptSort, acceptLiteral, acceptLabel, acceptWsAfterLabel, acceptWsAfterColon));
  }
  if (SDF_isSymbolBracket(arg)) {
    return SDF_makeSymbolBracket(
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(SDF_getSymbolWsAfterParenOpen(arg)) : SDF_getSymbolWsAfterParenOpen(arg),
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptWsAfterLessThan, acceptWsAfterSymbol, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterSet, acceptWsAfterBracketOpen, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterLessThanLessThan, acceptSymbols, acceptWsAfterSymbols, acceptCharClass, acceptSort, acceptLiteral, acceptLabel, acceptWsAfterLabel, acceptWsAfterColon),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(SDF_getSymbolWsAfterSymbol(arg)) : SDF_getSymbolWsAfterSymbol(arg));
  }
  ATabort("not a Symbol: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_visitGrammar(SDF_Grammar arg, char * (*acceptWsAfterLexical)(char *), char * (*acceptWsAfterPriorities)(char *), SDF_Priorities (*acceptPriorities)(SDF_Priorities), char * (*acceptWsAfterContextFree)(char *), char * (*acceptWsAfterRestrictions)(char *), SDF_Restrictions (*acceptRestrictions)(SDF_Restrictions), char * (*acceptWsAfterSyntax)(char *), SDF_Productions (*acceptProductions)(SDF_Productions), char * (*acceptWsAfterVariables)(char *), SDF_ImpSection (*acceptImpSection)(SDF_ImpSection), char * (*acceptWsAfterSorts)(char *), SDF_Symbols (*acceptSymbols)(SDF_Symbols), char * (*acceptWsAfterAliases)(char *), SDF_Aliases (*acceptAliases)(SDF_Aliases), char * (*acceptWsAfterLeft)(char *), char * (*acceptWsAfterParenOpen)(char *), char * (*acceptWsAfterGrammar)(char *)) */

SDF_Grammar SDF_visitGrammar(SDF_Grammar arg, char * (*acceptWsAfterLexical)(char *), char * (*acceptWsAfterPriorities)(char *), SDF_Priorities (*acceptPriorities)(SDF_Priorities), char * (*acceptWsAfterContextFree)(char *), char * (*acceptWsAfterRestrictions)(char *), SDF_Restrictions (*acceptRestrictions)(SDF_Restrictions), char * (*acceptWsAfterSyntax)(char *), SDF_Productions (*acceptProductions)(SDF_Productions), char * (*acceptWsAfterVariables)(char *), SDF_ImpSection (*acceptImpSection)(SDF_ImpSection), char * (*acceptWsAfterSorts)(char *), SDF_Symbols (*acceptSymbols)(SDF_Symbols), char * (*acceptWsAfterAliases)(char *), SDF_Aliases (*acceptAliases)(SDF_Aliases), char * (*acceptWsAfterLeft)(char *), char * (*acceptWsAfterParenOpen)(char *), char * (*acceptWsAfterGrammar)(char *))
{
  if (SDF_isGrammarLexicalPriorities(arg)) {
    return SDF_makeGrammarLexicalPriorities(
        acceptWsAfterLexical ? acceptWsAfterLexical(SDF_getGrammarWsAfterLexical(arg)) : SDF_getGrammarWsAfterLexical(arg),
        acceptWsAfterPriorities ? acceptWsAfterPriorities(SDF_getGrammarWsAfterPriorities(arg)) : SDF_getGrammarWsAfterPriorities(arg),
        acceptPriorities ? acceptPriorities(SDF_getGrammarPriorities(arg)) : SDF_getGrammarPriorities(arg));
  }
  if (SDF_isGrammarContextFreePriorities(arg)) {
    return SDF_makeGrammarContextFreePriorities(
        acceptWsAfterContextFree ? acceptWsAfterContextFree(SDF_getGrammarWsAfterContextFree(arg)) : SDF_getGrammarWsAfterContextFree(arg),
        acceptWsAfterPriorities ? acceptWsAfterPriorities(SDF_getGrammarWsAfterPriorities(arg)) : SDF_getGrammarWsAfterPriorities(arg),
        acceptPriorities ? acceptPriorities(SDF_getGrammarPriorities(arg)) : SDF_getGrammarPriorities(arg));
  }
  if (SDF_isGrammarLexicalRestrictions(arg)) {
    return SDF_makeGrammarLexicalRestrictions(
        acceptWsAfterLexical ? acceptWsAfterLexical(SDF_getGrammarWsAfterLexical(arg)) : SDF_getGrammarWsAfterLexical(arg),
        acceptWsAfterRestrictions ? acceptWsAfterRestrictions(SDF_getGrammarWsAfterRestrictions(arg)) : SDF_getGrammarWsAfterRestrictions(arg),
        acceptRestrictions ? acceptRestrictions(SDF_getGrammarRestrictions(arg)) : SDF_getGrammarRestrictions(arg));
  }
  if (SDF_isGrammarContextFreeRestrictions(arg)) {
    return SDF_makeGrammarContextFreeRestrictions(
        acceptWsAfterContextFree ? acceptWsAfterContextFree(SDF_getGrammarWsAfterContextFree(arg)) : SDF_getGrammarWsAfterContextFree(arg),
        acceptWsAfterRestrictions ? acceptWsAfterRestrictions(SDF_getGrammarWsAfterRestrictions(arg)) : SDF_getGrammarWsAfterRestrictions(arg),
        acceptRestrictions ? acceptRestrictions(SDF_getGrammarRestrictions(arg)) : SDF_getGrammarRestrictions(arg));
  }
  if (SDF_isGrammarSyntax(arg)) {
    return SDF_makeGrammarSyntax(
        acceptWsAfterSyntax ? acceptWsAfterSyntax(SDF_getGrammarWsAfterSyntax(arg)) : SDF_getGrammarWsAfterSyntax(arg),
        acceptProductions ? acceptProductions(SDF_getGrammarProductions(arg)) : SDF_getGrammarProductions(arg));
  }
  if (SDF_isGrammarLexicalSyntax(arg)) {
    return SDF_makeGrammarLexicalSyntax(
        acceptWsAfterLexical ? acceptWsAfterLexical(SDF_getGrammarWsAfterLexical(arg)) : SDF_getGrammarWsAfterLexical(arg),
        acceptWsAfterSyntax ? acceptWsAfterSyntax(SDF_getGrammarWsAfterSyntax(arg)) : SDF_getGrammarWsAfterSyntax(arg),
        acceptProductions ? acceptProductions(SDF_getGrammarProductions(arg)) : SDF_getGrammarProductions(arg));
  }
  if (SDF_isGrammarContextFreeSyntax(arg)) {
    return SDF_makeGrammarContextFreeSyntax(
        acceptWsAfterContextFree ? acceptWsAfterContextFree(SDF_getGrammarWsAfterContextFree(arg)) : SDF_getGrammarWsAfterContextFree(arg),
        acceptWsAfterSyntax ? acceptWsAfterSyntax(SDF_getGrammarWsAfterSyntax(arg)) : SDF_getGrammarWsAfterSyntax(arg),
        acceptProductions ? acceptProductions(SDF_getGrammarProductions(arg)) : SDF_getGrammarProductions(arg));
  }
  if (SDF_isGrammarVariables(arg)) {
    return SDF_makeGrammarVariables(
        acceptWsAfterVariables ? acceptWsAfterVariables(SDF_getGrammarWsAfterVariables(arg)) : SDF_getGrammarWsAfterVariables(arg),
        acceptProductions ? acceptProductions(SDF_getGrammarProductions(arg)) : SDF_getGrammarProductions(arg));
  }
  if (SDF_isGrammarLexicalVariables(arg)) {
    return SDF_makeGrammarLexicalVariables(
        acceptWsAfterLexical ? acceptWsAfterLexical(SDF_getGrammarWsAfterLexical(arg)) : SDF_getGrammarWsAfterLexical(arg),
        acceptWsAfterVariables ? acceptWsAfterVariables(SDF_getGrammarWsAfterVariables(arg)) : SDF_getGrammarWsAfterVariables(arg),
        acceptProductions ? acceptProductions(SDF_getGrammarProductions(arg)) : SDF_getGrammarProductions(arg));
  }
  if (SDF_isGrammarImpSection(arg)) {
    return SDF_makeGrammarImpSection(
        acceptImpSection ? acceptImpSection(SDF_getGrammarImpSection(arg)) : SDF_getGrammarImpSection(arg));
  }
  if (SDF_isGrammarPriorities(arg)) {
    return SDF_makeGrammarPriorities(
        acceptWsAfterPriorities ? acceptWsAfterPriorities(SDF_getGrammarWsAfterPriorities(arg)) : SDF_getGrammarWsAfterPriorities(arg),
        acceptPriorities ? acceptPriorities(SDF_getGrammarPriorities(arg)) : SDF_getGrammarPriorities(arg));
  }
  if (SDF_isGrammarSorts(arg)) {
    return SDF_makeGrammarSorts(
        acceptWsAfterSorts ? acceptWsAfterSorts(SDF_getGrammarWsAfterSorts(arg)) : SDF_getGrammarWsAfterSorts(arg),
        acceptSymbols ? acceptSymbols(SDF_getGrammarSymbols(arg)) : SDF_getGrammarSymbols(arg));
  }
  if (SDF_isGrammarRestrictions(arg)) {
    return SDF_makeGrammarRestrictions(
        acceptWsAfterRestrictions ? acceptWsAfterRestrictions(SDF_getGrammarWsAfterRestrictions(arg)) : SDF_getGrammarWsAfterRestrictions(arg),
        acceptRestrictions ? acceptRestrictions(SDF_getGrammarRestrictions(arg)) : SDF_getGrammarRestrictions(arg));
  }
  if (SDF_isGrammarAliases(arg)) {
    return SDF_makeGrammarAliases(
        acceptWsAfterAliases ? acceptWsAfterAliases(SDF_getGrammarWsAfterAliases(arg)) : SDF_getGrammarWsAfterAliases(arg),
        acceptAliases ? acceptAliases(SDF_getGrammarAliases(arg)) : SDF_getGrammarAliases(arg));
  }
  if (SDF_isGrammarEmptyGrammar(arg)) {
    return SDF_makeGrammarEmptyGrammar();
  }
  if (SDF_isGrammarConcGrammars(arg)) {
    return SDF_makeGrammarConcGrammars(
        SDF_visitGrammar(SDF_getGrammarLeft(arg), acceptWsAfterLexical, acceptWsAfterPriorities, acceptPriorities, acceptWsAfterContextFree, acceptWsAfterRestrictions, acceptRestrictions, acceptWsAfterSyntax, acceptProductions, acceptWsAfterVariables, acceptImpSection, acceptWsAfterSorts, acceptSymbols, acceptWsAfterAliases, acceptAliases, acceptWsAfterLeft, acceptWsAfterParenOpen, acceptWsAfterGrammar),
        acceptWsAfterLeft ? acceptWsAfterLeft(SDF_getGrammarWsAfterLeft(arg)) : SDF_getGrammarWsAfterLeft(arg),
        SDF_visitGrammar(SDF_getGrammarRight(arg), acceptWsAfterLexical, acceptWsAfterPriorities, acceptPriorities, acceptWsAfterContextFree, acceptWsAfterRestrictions, acceptRestrictions, acceptWsAfterSyntax, acceptProductions, acceptWsAfterVariables, acceptImpSection, acceptWsAfterSorts, acceptSymbols, acceptWsAfterAliases, acceptAliases, acceptWsAfterLeft, acceptWsAfterParenOpen, acceptWsAfterGrammar));
  }
  if (SDF_isGrammarBracket(arg)) {
    return SDF_makeGrammarBracket(
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(SDF_getGrammarWsAfterParenOpen(arg)) : SDF_getGrammarWsAfterParenOpen(arg),
        SDF_visitGrammar(SDF_getGrammarGrammar(arg), acceptWsAfterLexical, acceptWsAfterPriorities, acceptPriorities, acceptWsAfterContextFree, acceptWsAfterRestrictions, acceptRestrictions, acceptWsAfterSyntax, acceptProductions, acceptWsAfterVariables, acceptImpSection, acceptWsAfterSorts, acceptSymbols, acceptWsAfterAliases, acceptAliases, acceptWsAfterLeft, acceptWsAfterParenOpen, acceptWsAfterGrammar),
        acceptWsAfterGrammar ? acceptWsAfterGrammar(SDF_getGrammarWsAfterGrammar(arg)) : SDF_getGrammarWsAfterGrammar(arg));
  }
  ATabort("not a Grammar: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  SDF_SDF SDF_visitSDF(SDF_SDF arg, char * (*acceptWsAfterDefinition)(char *), SDF_Definition (*acceptDefinition)(SDF_Definition)) */

SDF_SDF SDF_visitSDF(SDF_SDF arg, char * (*acceptWsAfterDefinition)(char *), SDF_Definition (*acceptDefinition)(SDF_Definition))
{
  if (SDF_isSDFDefinition(arg)) {
    return SDF_makeSDFDefinition(
        acceptWsAfterDefinition ? acceptWsAfterDefinition(SDF_getSDFWsAfterDefinition(arg)) : SDF_getSDFWsAfterDefinition(arg),
        acceptDefinition ? acceptDefinition(SDF_getSDFDefinition(arg)) : SDF_getSDFDefinition(arg));
  }
  ATabort("not a SDF: %t\n", arg);
  return (SDF_SDF)NULL;
}

/*}}}  */
/*{{{  SDF_Attributes SDF_visitAttributes(SDF_Attributes arg, char * (*acceptWsAfterBraceOpen)(char *), SDF_AttributeList (*acceptList)(SDF_AttributeList), char * (*acceptWsAfterList)(char *)) */

SDF_Attributes SDF_visitAttributes(SDF_Attributes arg, char * (*acceptWsAfterBraceOpen)(char *), SDF_AttributeList (*acceptList)(SDF_AttributeList), char * (*acceptWsAfterList)(char *))
{
  if (SDF_isAttributesAttrs(arg)) {
    return SDF_makeAttributesAttrs(
        acceptWsAfterBraceOpen ? acceptWsAfterBraceOpen(SDF_getAttributesWsAfterBraceOpen(arg)) : SDF_getAttributesWsAfterBraceOpen(arg),
        acceptList ? acceptList(SDF_getAttributesList(arg)) : SDF_getAttributesList(arg),
        acceptWsAfterList ? acceptWsAfterList(SDF_getAttributesWsAfterList(arg)) : SDF_getAttributesWsAfterList(arg));
  }
  if (SDF_isAttributesNoAttrs(arg)) {
    return SDF_makeAttributesNoAttrs();
  }
  ATabort("not a Attributes: %t\n", arg);
  return (SDF_Attributes)NULL;
}

/*}}}  */
/*{{{  SDF_AttributeList SDF_visitAttributeList(SDF_AttributeList arg, SDF_Attribute (*acceptHead)(SDF_Attribute), char * (*acceptWsAfterFirst)(char *), char * (*acceptSep)(char *), char * (*acceptWsAfterSep)(char *)) */

SDF_AttributeList SDF_visitAttributeList(SDF_AttributeList arg, SDF_Attribute (*acceptHead)(SDF_Attribute), char * (*acceptWsAfterFirst)(char *), char * (*acceptSep)(char *), char * (*acceptWsAfterSep)(char *))
{
  if (SDF_isAttributeListEmpty(arg)) {
    return SDF_makeAttributeListEmpty();
  }
  if (SDF_isAttributeListSingle(arg)) {
    return SDF_makeAttributeListSingle(
        acceptHead ? acceptHead(SDF_getAttributeListHead(arg)) : SDF_getAttributeListHead(arg));
  }
  if (SDF_isAttributeListMany(arg)) {
    return SDF_makeAttributeListMany(
        acceptHead ? acceptHead(SDF_getAttributeListHead(arg)) : SDF_getAttributeListHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(SDF_getAttributeListWsAfterFirst(arg)) : SDF_getAttributeListWsAfterFirst(arg),
        acceptSep ? acceptSep(SDF_getAttributeListSep(arg)) : SDF_getAttributeListSep(arg),
        acceptWsAfterSep ? acceptWsAfterSep(SDF_getAttributeListWsAfterSep(arg)) : SDF_getAttributeListWsAfterSep(arg),
        SDF_visitAttributeList(SDF_getAttributeListTail(arg), acceptHead, acceptWsAfterFirst, acceptSep, acceptWsAfterSep));
  }
  ATabort("not a AttributeList: %t\n", arg);
  return (SDF_AttributeList)NULL;
}

/*}}}  */
/*{{{  SDF_Production SDF_visitProduction(SDF_Production arg, SDF_Symbols (*acceptSymbols)(SDF_Symbols), char * (*acceptWsAfterSymbols)(char *), char * (*acceptWsAfterGreaterThan)(char *), SDF_Symbol (*acceptResult)(SDF_Symbol), char * (*acceptWsAfterResult)(char *), SDF_Attributes (*acceptAttributes)(SDF_Attributes), SDF_Literal (*acceptFunctionSymbol)(SDF_Literal), char * (*acceptWsAfterFunctionSymbol)(char *), char * (*acceptWsAfterParenOpen)(char *), SDF_SymbolArguments (*acceptArguments)(SDF_SymbolArguments), char * (*acceptWsAfterArguments)(char *), char * (*acceptWsAfterParenClose)(char *)) */

SDF_Production SDF_visitProduction(SDF_Production arg, SDF_Symbols (*acceptSymbols)(SDF_Symbols), char * (*acceptWsAfterSymbols)(char *), char * (*acceptWsAfterGreaterThan)(char *), SDF_Symbol (*acceptResult)(SDF_Symbol), char * (*acceptWsAfterResult)(char *), SDF_Attributes (*acceptAttributes)(SDF_Attributes), SDF_Literal (*acceptFunctionSymbol)(SDF_Literal), char * (*acceptWsAfterFunctionSymbol)(char *), char * (*acceptWsAfterParenOpen)(char *), SDF_SymbolArguments (*acceptArguments)(SDF_SymbolArguments), char * (*acceptWsAfterArguments)(char *), char * (*acceptWsAfterParenClose)(char *))
{
  if (SDF_isProductionProd(arg)) {
    return SDF_makeProductionProd(
        acceptSymbols ? acceptSymbols(SDF_getProductionSymbols(arg)) : SDF_getProductionSymbols(arg),
        acceptWsAfterSymbols ? acceptWsAfterSymbols(SDF_getProductionWsAfterSymbols(arg)) : SDF_getProductionWsAfterSymbols(arg),
        acceptWsAfterGreaterThan ? acceptWsAfterGreaterThan(SDF_getProductionWsAfterGreaterThan(arg)) : SDF_getProductionWsAfterGreaterThan(arg),
        acceptResult ? acceptResult(SDF_getProductionResult(arg)) : SDF_getProductionResult(arg),
        acceptWsAfterResult ? acceptWsAfterResult(SDF_getProductionWsAfterResult(arg)) : SDF_getProductionWsAfterResult(arg),
        acceptAttributes ? acceptAttributes(SDF_getProductionAttributes(arg)) : SDF_getProductionAttributes(arg));
  }
  if (SDF_isProductionProdFun(arg)) {
    return SDF_makeProductionProdFun(
        acceptFunctionSymbol ? acceptFunctionSymbol(SDF_getProductionFunctionSymbol(arg)) : SDF_getProductionFunctionSymbol(arg),
        acceptWsAfterFunctionSymbol ? acceptWsAfterFunctionSymbol(SDF_getProductionWsAfterFunctionSymbol(arg)) : SDF_getProductionWsAfterFunctionSymbol(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(SDF_getProductionWsAfterParenOpen(arg)) : SDF_getProductionWsAfterParenOpen(arg),
        acceptArguments ? acceptArguments(SDF_getProductionArguments(arg)) : SDF_getProductionArguments(arg),
        acceptWsAfterArguments ? acceptWsAfterArguments(SDF_getProductionWsAfterArguments(arg)) : SDF_getProductionWsAfterArguments(arg),
        acceptWsAfterParenClose ? acceptWsAfterParenClose(SDF_getProductionWsAfterParenClose(arg)) : SDF_getProductionWsAfterParenClose(arg),
        acceptWsAfterGreaterThan ? acceptWsAfterGreaterThan(SDF_getProductionWsAfterGreaterThan(arg)) : SDF_getProductionWsAfterGreaterThan(arg),
        acceptResult ? acceptResult(SDF_getProductionResult(arg)) : SDF_getProductionResult(arg),
        acceptWsAfterResult ? acceptWsAfterResult(SDF_getProductionWsAfterResult(arg)) : SDF_getProductionWsAfterResult(arg),
        acceptAttributes ? acceptAttributes(SDF_getProductionAttributes(arg)) : SDF_getProductionAttributes(arg));
  }
  ATabort("not a Production: %t\n", arg);
  return (SDF_Production)NULL;
}

/*}}}  */
/*{{{  SDF_Productions SDF_visitProductions(SDF_Productions arg, SDF_ProductionList (*acceptList)(SDF_ProductionList)) */

SDF_Productions SDF_visitProductions(SDF_Productions arg, SDF_ProductionList (*acceptList)(SDF_ProductionList))
{
  if (SDF_isProductionsDefault(arg)) {
    return SDF_makeProductionsDefault(
        acceptList ? acceptList(SDF_getProductionsList(arg)) : SDF_getProductionsList(arg));
  }
  ATabort("not a Productions: %t\n", arg);
  return (SDF_Productions)NULL;
}

/*}}}  */
/*{{{  SDF_ProductionList SDF_visitProductionList(SDF_ProductionList arg, SDF_Production (*acceptHead)(SDF_Production), char * (*acceptWsAfterFirst)(char *)) */

SDF_ProductionList SDF_visitProductionList(SDF_ProductionList arg, SDF_Production (*acceptHead)(SDF_Production), char * (*acceptWsAfterFirst)(char *))
{
  if (SDF_isProductionListEmpty(arg)) {
    return SDF_makeProductionListEmpty();
  }
  if (SDF_isProductionListSingle(arg)) {
    return SDF_makeProductionListSingle(
        acceptHead ? acceptHead(SDF_getProductionListHead(arg)) : SDF_getProductionListHead(arg));
  }
  if (SDF_isProductionListMany(arg)) {
    return SDF_makeProductionListMany(
        acceptHead ? acceptHead(SDF_getProductionListHead(arg)) : SDF_getProductionListHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(SDF_getProductionListWsAfterFirst(arg)) : SDF_getProductionListWsAfterFirst(arg),
        SDF_visitProductionList(SDF_getProductionListTail(arg), acceptHead, acceptWsAfterFirst));
  }
  ATabort("not a ProductionList: %t\n", arg);
  return (SDF_ProductionList)NULL;
}

/*}}}  */
/*{{{  SDF_ModuleWord SDF_visitModuleWord(SDF_ModuleWord arg, char * (*acceptLex)(char *)) */

SDF_ModuleWord SDF_visitModuleWord(SDF_ModuleWord arg, char * (*acceptLex)(char *))
{
  if (SDF_isModuleWordWord(arg)) {
    return SDF_makeModuleWordWord(
        acceptLex ? acceptLex(SDF_getModuleWordLex(arg)) : SDF_getModuleWordLex(arg));
  }
  ATabort("not a ModuleWord: %t\n", arg);
  return (SDF_ModuleWord)NULL;
}

/*}}}  */
/*{{{  SDF_ModuleId SDF_visitModuleId(SDF_ModuleId arg, char * (*acceptLex)(char *)) */

SDF_ModuleId SDF_visitModuleId(SDF_ModuleId arg, char * (*acceptLex)(char *))
{
  if (SDF_isModuleIdWord(arg)) {
    return SDF_makeModuleIdWord(
        acceptLex ? acceptLex(SDF_getModuleIdLex(arg)) : SDF_getModuleIdLex(arg));
  }
  if (SDF_isModuleIdSlashWord(arg)) {
    return SDF_makeModuleIdSlashWord(
        acceptLex ? acceptLex(SDF_getModuleIdLex(arg)) : SDF_getModuleIdLex(arg));
  }
  if (SDF_isModuleIdWordSlashWord(arg)) {
    return SDF_makeModuleIdWordSlashWord(
        acceptLex ? acceptLex(SDF_getModuleIdLex(arg)) : SDF_getModuleIdLex(arg));
  }
  ATabort("not a ModuleId: %t\n", arg);
  return (SDF_ModuleId)NULL;
}

/*}}}  */
/*{{{  SDF_Definition SDF_visitDefinition(SDF_Definition arg, SDF_ModuleList (*acceptList)(SDF_ModuleList)) */

SDF_Definition SDF_visitDefinition(SDF_Definition arg, SDF_ModuleList (*acceptList)(SDF_ModuleList))
{
  if (SDF_isDefinitionDefault(arg)) {
    return SDF_makeDefinitionDefault(
        acceptList ? acceptList(SDF_getDefinitionList(arg)) : SDF_getDefinitionList(arg));
  }
  ATabort("not a Definition: %t\n", arg);
  return (SDF_Definition)NULL;
}

/*}}}  */
/*{{{  SDF_ModuleList SDF_visitModuleList(SDF_ModuleList arg, SDF_Module (*acceptHead)(SDF_Module), char * (*acceptWsAfterFirst)(char *)) */

SDF_ModuleList SDF_visitModuleList(SDF_ModuleList arg, SDF_Module (*acceptHead)(SDF_Module), char * (*acceptWsAfterFirst)(char *))
{
  if (SDF_isModuleListEmpty(arg)) {
    return SDF_makeModuleListEmpty();
  }
  if (SDF_isModuleListSingle(arg)) {
    return SDF_makeModuleListSingle(
        acceptHead ? acceptHead(SDF_getModuleListHead(arg)) : SDF_getModuleListHead(arg));
  }
  if (SDF_isModuleListMany(arg)) {
    return SDF_makeModuleListMany(
        acceptHead ? acceptHead(SDF_getModuleListHead(arg)) : SDF_getModuleListHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(SDF_getModuleListWsAfterFirst(arg)) : SDF_getModuleListWsAfterFirst(arg),
        SDF_visitModuleList(SDF_getModuleListTail(arg), acceptHead, acceptWsAfterFirst));
  }
  ATabort("not a ModuleList: %t\n", arg);
  return (SDF_ModuleList)NULL;
}

/*}}}  */
/*{{{  SDF_Module SDF_visitModule(SDF_Module arg, char * (*acceptWsAfterModule)(char *), SDF_ModuleName (*acceptModuleName)(SDF_ModuleName), char * (*acceptWsAfterModuleName)(char *), SDF_ImpSectionList (*acceptList)(SDF_ImpSectionList), char * (*acceptWsAfterList)(char *), SDF_Sections (*acceptSections)(SDF_Sections)) */

SDF_Module SDF_visitModule(SDF_Module arg, char * (*acceptWsAfterModule)(char *), SDF_ModuleName (*acceptModuleName)(SDF_ModuleName), char * (*acceptWsAfterModuleName)(char *), SDF_ImpSectionList (*acceptList)(SDF_ImpSectionList), char * (*acceptWsAfterList)(char *), SDF_Sections (*acceptSections)(SDF_Sections))
{
  if (SDF_isModuleModule(arg)) {
    return SDF_makeModuleModule(
        acceptWsAfterModule ? acceptWsAfterModule(SDF_getModuleWsAfterModule(arg)) : SDF_getModuleWsAfterModule(arg),
        acceptModuleName ? acceptModuleName(SDF_getModuleModuleName(arg)) : SDF_getModuleModuleName(arg),
        acceptWsAfterModuleName ? acceptWsAfterModuleName(SDF_getModuleWsAfterModuleName(arg)) : SDF_getModuleWsAfterModuleName(arg),
        acceptList ? acceptList(SDF_getModuleList(arg)) : SDF_getModuleList(arg),
        acceptWsAfterList ? acceptWsAfterList(SDF_getModuleWsAfterList(arg)) : SDF_getModuleWsAfterList(arg),
        acceptSections ? acceptSections(SDF_getModuleSections(arg)) : SDF_getModuleSections(arg));
  }
  ATabort("not a Module: %t\n", arg);
  return (SDF_Module)NULL;
}

/*}}}  */
/*{{{  SDF_ImpSectionList SDF_visitImpSectionList(SDF_ImpSectionList arg, SDF_ImpSection (*acceptHead)(SDF_ImpSection), char * (*acceptWsAfterFirst)(char *)) */

SDF_ImpSectionList SDF_visitImpSectionList(SDF_ImpSectionList arg, SDF_ImpSection (*acceptHead)(SDF_ImpSection), char * (*acceptWsAfterFirst)(char *))
{
  if (SDF_isImpSectionListEmpty(arg)) {
    return SDF_makeImpSectionListEmpty();
  }
  if (SDF_isImpSectionListSingle(arg)) {
    return SDF_makeImpSectionListSingle(
        acceptHead ? acceptHead(SDF_getImpSectionListHead(arg)) : SDF_getImpSectionListHead(arg));
  }
  if (SDF_isImpSectionListMany(arg)) {
    return SDF_makeImpSectionListMany(
        acceptHead ? acceptHead(SDF_getImpSectionListHead(arg)) : SDF_getImpSectionListHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(SDF_getImpSectionListWsAfterFirst(arg)) : SDF_getImpSectionListWsAfterFirst(arg),
        SDF_visitImpSectionList(SDF_getImpSectionListTail(arg), acceptHead, acceptWsAfterFirst));
  }
  ATabort("not a ImpSectionList: %t\n", arg);
  return (SDF_ImpSectionList)NULL;
}

/*}}}  */
/*{{{  SDF_Section SDF_visitSection(SDF_Section arg, char * (*acceptWsAfterExports)(char *), SDF_Grammar (*acceptGrammar)(SDF_Grammar), char * (*acceptWsAfterHiddens)(char *)) */

SDF_Section SDF_visitSection(SDF_Section arg, char * (*acceptWsAfterExports)(char *), SDF_Grammar (*acceptGrammar)(SDF_Grammar), char * (*acceptWsAfterHiddens)(char *))
{
  if (SDF_isSectionExports(arg)) {
    return SDF_makeSectionExports(
        acceptWsAfterExports ? acceptWsAfterExports(SDF_getSectionWsAfterExports(arg)) : SDF_getSectionWsAfterExports(arg),
        acceptGrammar ? acceptGrammar(SDF_getSectionGrammar(arg)) : SDF_getSectionGrammar(arg));
  }
  if (SDF_isSectionHiddens(arg)) {
    return SDF_makeSectionHiddens(
        acceptWsAfterHiddens ? acceptWsAfterHiddens(SDF_getSectionWsAfterHiddens(arg)) : SDF_getSectionWsAfterHiddens(arg),
        acceptGrammar ? acceptGrammar(SDF_getSectionGrammar(arg)) : SDF_getSectionGrammar(arg));
  }
  ATabort("not a Section: %t\n", arg);
  return (SDF_Section)NULL;
}

/*}}}  */
/*{{{  SDF_Sections SDF_visitSections(SDF_Sections arg, SDF_SectionList (*acceptList)(SDF_SectionList)) */

SDF_Sections SDF_visitSections(SDF_Sections arg, SDF_SectionList (*acceptList)(SDF_SectionList))
{
  if (SDF_isSectionsDefault(arg)) {
    return SDF_makeSectionsDefault(
        acceptList ? acceptList(SDF_getSectionsList(arg)) : SDF_getSectionsList(arg));
  }
  ATabort("not a Sections: %t\n", arg);
  return (SDF_Sections)NULL;
}

/*}}}  */
/*{{{  SDF_SectionList SDF_visitSectionList(SDF_SectionList arg, SDF_Section (*acceptHead)(SDF_Section), char * (*acceptWsAfterFirst)(char *)) */

SDF_SectionList SDF_visitSectionList(SDF_SectionList arg, SDF_Section (*acceptHead)(SDF_Section), char * (*acceptWsAfterFirst)(char *))
{
  if (SDF_isSectionListEmpty(arg)) {
    return SDF_makeSectionListEmpty();
  }
  if (SDF_isSectionListSingle(arg)) {
    return SDF_makeSectionListSingle(
        acceptHead ? acceptHead(SDF_getSectionListHead(arg)) : SDF_getSectionListHead(arg));
  }
  if (SDF_isSectionListMany(arg)) {
    return SDF_makeSectionListMany(
        acceptHead ? acceptHead(SDF_getSectionListHead(arg)) : SDF_getSectionListHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(SDF_getSectionListWsAfterFirst(arg)) : SDF_getSectionListWsAfterFirst(arg),
        SDF_visitSectionList(SDF_getSectionListTail(arg), acceptHead, acceptWsAfterFirst));
  }
  ATabort("not a SectionList: %t\n", arg);
  return (SDF_SectionList)NULL;
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_visitModuleName(SDF_ModuleName arg, SDF_ModuleId (*acceptModuleId)(SDF_ModuleId), char * (*acceptWsAfterModuleId)(char *), char * (*acceptWsAfterBracketOpen)(char *), SDF_Symbols (*acceptParams)(SDF_Symbols), char * (*acceptWsAfterParams)(char *)) */

SDF_ModuleName SDF_visitModuleName(SDF_ModuleName arg, SDF_ModuleId (*acceptModuleId)(SDF_ModuleId), char * (*acceptWsAfterModuleId)(char *), char * (*acceptWsAfterBracketOpen)(char *), SDF_Symbols (*acceptParams)(SDF_Symbols), char * (*acceptWsAfterParams)(char *))
{
  if (SDF_isModuleNameUnparameterized(arg)) {
    return SDF_makeModuleNameUnparameterized(
        acceptModuleId ? acceptModuleId(SDF_getModuleNameModuleId(arg)) : SDF_getModuleNameModuleId(arg));
  }
  if (SDF_isModuleNameParameterized(arg)) {
    return SDF_makeModuleNameParameterized(
        acceptModuleId ? acceptModuleId(SDF_getModuleNameModuleId(arg)) : SDF_getModuleNameModuleId(arg),
        acceptWsAfterModuleId ? acceptWsAfterModuleId(SDF_getModuleNameWsAfterModuleId(arg)) : SDF_getModuleNameWsAfterModuleId(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(SDF_getModuleNameWsAfterBracketOpen(arg)) : SDF_getModuleNameWsAfterBracketOpen(arg),
        acceptParams ? acceptParams(SDF_getModuleNameParams(arg)) : SDF_getModuleNameParams(arg),
        acceptWsAfterParams ? acceptWsAfterParams(SDF_getModuleNameWsAfterParams(arg)) : SDF_getModuleNameWsAfterParams(arg));
  }
  ATabort("not a ModuleName: %t\n", arg);
  return (SDF_ModuleName)NULL;
}

/*}}}  */
/*{{{  SDF_Attribute SDF_visitAttribute(SDF_Attribute arg, char * (*acceptWsAfterId)(char *), char * (*acceptWsAfterParenOpen)(char *), SDF_ModuleName (*acceptModuleName)(SDF_ModuleName), char * (*acceptWsAfterModuleName)(char *), SDF_Associativity (*acceptAssociativity)(SDF_Associativity), char * (*acceptWsAfterCons)(char *), SDF_ATerm (*acceptTerm)(SDF_ATerm), char * (*acceptWsAfterTerm)(char *)) */

SDF_Attribute SDF_visitAttribute(SDF_Attribute arg, char * (*acceptWsAfterId)(char *), char * (*acceptWsAfterParenOpen)(char *), SDF_ModuleName (*acceptModuleName)(SDF_ModuleName), char * (*acceptWsAfterModuleName)(char *), SDF_Associativity (*acceptAssociativity)(SDF_Associativity), char * (*acceptWsAfterCons)(char *), SDF_ATerm (*acceptTerm)(SDF_ATerm), char * (*acceptWsAfterTerm)(char *))
{
  if (SDF_isAttributeId(arg)) {
    return SDF_makeAttributeId(
        acceptWsAfterId ? acceptWsAfterId(SDF_getAttributeWsAfterId(arg)) : SDF_getAttributeWsAfterId(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(SDF_getAttributeWsAfterParenOpen(arg)) : SDF_getAttributeWsAfterParenOpen(arg),
        acceptModuleName ? acceptModuleName(SDF_getAttributeModuleName(arg)) : SDF_getAttributeModuleName(arg),
        acceptWsAfterModuleName ? acceptWsAfterModuleName(SDF_getAttributeWsAfterModuleName(arg)) : SDF_getAttributeWsAfterModuleName(arg));
  }
  if (SDF_isAttributeBracket(arg)) {
    return SDF_makeAttributeBracket();
  }
  if (SDF_isAttributeAtr(arg)) {
    return SDF_makeAttributeAtr(
        acceptAssociativity ? acceptAssociativity(SDF_getAttributeAssociativity(arg)) : SDF_getAttributeAssociativity(arg));
  }
  if (SDF_isAttributeCons(arg)) {
    return SDF_makeAttributeCons(
        acceptWsAfterCons ? acceptWsAfterCons(SDF_getAttributeWsAfterCons(arg)) : SDF_getAttributeWsAfterCons(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(SDF_getAttributeWsAfterParenOpen(arg)) : SDF_getAttributeWsAfterParenOpen(arg),
        acceptTerm ? acceptTerm(SDF_getAttributeTerm(arg)) : SDF_getAttributeTerm(arg),
        acceptWsAfterTerm ? acceptWsAfterTerm(SDF_getAttributeWsAfterTerm(arg)) : SDF_getAttributeWsAfterTerm(arg));
  }
  if (SDF_isAttributeConstructor(arg)) {
    return SDF_makeAttributeConstructor();
  }
  if (SDF_isAttributeMemo(arg)) {
    return SDF_makeAttributeMemo();
  }
  if (SDF_isAttributeTraverse(arg)) {
    return SDF_makeAttributeTraverse();
  }
  if (SDF_isAttributeReject(arg)) {
    return SDF_makeAttributeReject();
  }
  if (SDF_isAttributePrefer(arg)) {
    return SDF_makeAttributePrefer();
  }
  if (SDF_isAttributeAvoid(arg)) {
    return SDF_makeAttributeAvoid();
  }
  ATabort("not a Attribute: %t\n", arg);
  return (SDF_Attribute)NULL;
}

/*}}}  */
/*{{{  SDF_ImpSection SDF_visitImpSection(SDF_ImpSection arg, char * (*acceptWsAfterImports)(char *), SDF_Imports (*acceptList)(SDF_Imports)) */

SDF_ImpSection SDF_visitImpSection(SDF_ImpSection arg, char * (*acceptWsAfterImports)(char *), SDF_Imports (*acceptList)(SDF_Imports))
{
  if (SDF_isImpSectionImports(arg)) {
    return SDF_makeImpSectionImports(
        acceptWsAfterImports ? acceptWsAfterImports(SDF_getImpSectionWsAfterImports(arg)) : SDF_getImpSectionWsAfterImports(arg),
        acceptList ? acceptList(SDF_getImpSectionList(arg)) : SDF_getImpSectionList(arg));
  }
  ATabort("not a ImpSection: %t\n", arg);
  return (SDF_ImpSection)NULL;
}

/*}}}  */
/*{{{  SDF_Imports SDF_visitImports(SDF_Imports arg, SDF_ImportList (*acceptList)(SDF_ImportList)) */

SDF_Imports SDF_visitImports(SDF_Imports arg, SDF_ImportList (*acceptList)(SDF_ImportList))
{
  if (SDF_isImportsDefault(arg)) {
    return SDF_makeImportsDefault(
        acceptList ? acceptList(SDF_getImportsList(arg)) : SDF_getImportsList(arg));
  }
  ATabort("not a Imports: %t\n", arg);
  return (SDF_Imports)NULL;
}

/*}}}  */
/*{{{  SDF_ImportList SDF_visitImportList(SDF_ImportList arg, SDF_Import (*acceptHead)(SDF_Import), char * (*acceptWsAfterFirst)(char *)) */

SDF_ImportList SDF_visitImportList(SDF_ImportList arg, SDF_Import (*acceptHead)(SDF_Import), char * (*acceptWsAfterFirst)(char *))
{
  if (SDF_isImportListEmpty(arg)) {
    return SDF_makeImportListEmpty();
  }
  if (SDF_isImportListSingle(arg)) {
    return SDF_makeImportListSingle(
        acceptHead ? acceptHead(SDF_getImportListHead(arg)) : SDF_getImportListHead(arg));
  }
  if (SDF_isImportListMany(arg)) {
    return SDF_makeImportListMany(
        acceptHead ? acceptHead(SDF_getImportListHead(arg)) : SDF_getImportListHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(SDF_getImportListWsAfterFirst(arg)) : SDF_getImportListWsAfterFirst(arg),
        SDF_visitImportList(SDF_getImportListTail(arg), acceptHead, acceptWsAfterFirst));
  }
  ATabort("not a ImportList: %t\n", arg);
  return (SDF_ImportList)NULL;
}

/*}}}  */
/*{{{  SDF_Import SDF_visitImport(SDF_Import arg, SDF_ModuleName (*acceptModuleName)(SDF_ModuleName), char * (*acceptWsAfterModuleName)(char *), SDF_Renamings (*acceptRenamings)(SDF_Renamings), char * (*acceptWsAfterParenOpen)(char *), char * (*acceptWsAfterImport)(char *)) */

SDF_Import SDF_visitImport(SDF_Import arg, SDF_ModuleName (*acceptModuleName)(SDF_ModuleName), char * (*acceptWsAfterModuleName)(char *), SDF_Renamings (*acceptRenamings)(SDF_Renamings), char * (*acceptWsAfterParenOpen)(char *), char * (*acceptWsAfterImport)(char *))
{
  if (SDF_isImportModule(arg)) {
    return SDF_makeImportModule(
        acceptModuleName ? acceptModuleName(SDF_getImportModuleName(arg)) : SDF_getImportModuleName(arg));
  }
  if (SDF_isImportRenamedModule(arg)) {
    return SDF_makeImportRenamedModule(
        acceptModuleName ? acceptModuleName(SDF_getImportModuleName(arg)) : SDF_getImportModuleName(arg),
        acceptWsAfterModuleName ? acceptWsAfterModuleName(SDF_getImportWsAfterModuleName(arg)) : SDF_getImportWsAfterModuleName(arg),
        acceptRenamings ? acceptRenamings(SDF_getImportRenamings(arg)) : SDF_getImportRenamings(arg));
  }
  if (SDF_isImportBracket(arg)) {
    return SDF_makeImportBracket(
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(SDF_getImportWsAfterParenOpen(arg)) : SDF_getImportWsAfterParenOpen(arg),
        SDF_visitImport(SDF_getImportImport(arg), acceptModuleName, acceptWsAfterModuleName, acceptRenamings, acceptWsAfterParenOpen, acceptWsAfterImport),
        acceptWsAfterImport ? acceptWsAfterImport(SDF_getImportWsAfterImport(arg)) : SDF_getImportWsAfterImport(arg));
  }
  ATabort("not a Import: %t\n", arg);
  return (SDF_Import)NULL;
}

/*}}}  */
/*{{{  SDF_SymbolTail SDF_visitSymbolTail(SDF_SymbolTail arg, SDF_Symbol (*acceptHead)(SDF_Symbol), char * (*acceptWsAfterFirst)(char *)) */

SDF_SymbolTail SDF_visitSymbolTail(SDF_SymbolTail arg, SDF_Symbol (*acceptHead)(SDF_Symbol), char * (*acceptWsAfterFirst)(char *))
{
  if (SDF_isSymbolTailSingle(arg)) {
    return SDF_makeSymbolTailSingle(
        acceptHead ? acceptHead(SDF_getSymbolTailHead(arg)) : SDF_getSymbolTailHead(arg));
  }
  if (SDF_isSymbolTailMany(arg)) {
    return SDF_makeSymbolTailMany(
        acceptHead ? acceptHead(SDF_getSymbolTailHead(arg)) : SDF_getSymbolTailHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(SDF_getSymbolTailWsAfterFirst(arg)) : SDF_getSymbolTailWsAfterFirst(arg),
        SDF_visitSymbolTail(SDF_getSymbolTailTail(arg), acceptHead, acceptWsAfterFirst));
  }
  ATabort("not a SymbolTail: %t\n", arg);
  return (SDF_SymbolTail)NULL;
}

/*}}}  */
/*{{{  SDF_Associativity SDF_visitAssociativity(SDF_Associativity arg) */

SDF_Associativity SDF_visitAssociativity(SDF_Associativity arg)
{
  if (SDF_isAssociativityLeft(arg)) {
    return SDF_makeAssociativityLeft();
  }
  if (SDF_isAssociativityRight(arg)) {
    return SDF_makeAssociativityRight();
  }
  if (SDF_isAssociativityNonAssoc(arg)) {
    return SDF_makeAssociativityNonAssoc();
  }
  if (SDF_isAssociativityAssoc(arg)) {
    return SDF_makeAssociativityAssoc();
  }
  ATabort("not a Associativity: %t\n", arg);
  return (SDF_Associativity)NULL;
}

/*}}}  */
/*{{{  SDF_Group SDF_visitGroup(SDF_Group arg, SDF_Production (*acceptProduction)(SDF_Production), char * (*acceptWsAfterBraceOpen)(char *), SDF_Productions (*acceptProductions)(SDF_Productions), char * (*acceptWsAfterProductions)(char *), SDF_Associativity (*acceptAssociativity)(SDF_Associativity), char * (*acceptWsAfterAssociativity)(char *), char * (*acceptWsAfterColon)(char *)) */

SDF_Group SDF_visitGroup(SDF_Group arg, SDF_Production (*acceptProduction)(SDF_Production), char * (*acceptWsAfterBraceOpen)(char *), SDF_Productions (*acceptProductions)(SDF_Productions), char * (*acceptWsAfterProductions)(char *), SDF_Associativity (*acceptAssociativity)(SDF_Associativity), char * (*acceptWsAfterAssociativity)(char *), char * (*acceptWsAfterColon)(char *))
{
  if (SDF_isGroupSimpleGroup(arg)) {
    return SDF_makeGroupSimpleGroup(
        acceptProduction ? acceptProduction(SDF_getGroupProduction(arg)) : SDF_getGroupProduction(arg));
  }
  if (SDF_isGroupProdsGroup(arg)) {
    return SDF_makeGroupProdsGroup(
        acceptWsAfterBraceOpen ? acceptWsAfterBraceOpen(SDF_getGroupWsAfterBraceOpen(arg)) : SDF_getGroupWsAfterBraceOpen(arg),
        acceptProductions ? acceptProductions(SDF_getGroupProductions(arg)) : SDF_getGroupProductions(arg),
        acceptWsAfterProductions ? acceptWsAfterProductions(SDF_getGroupWsAfterProductions(arg)) : SDF_getGroupWsAfterProductions(arg));
  }
  if (SDF_isGroupAssocGroup(arg)) {
    return SDF_makeGroupAssocGroup(
        acceptWsAfterBraceOpen ? acceptWsAfterBraceOpen(SDF_getGroupWsAfterBraceOpen(arg)) : SDF_getGroupWsAfterBraceOpen(arg),
        acceptAssociativity ? acceptAssociativity(SDF_getGroupAssociativity(arg)) : SDF_getGroupAssociativity(arg),
        acceptWsAfterAssociativity ? acceptWsAfterAssociativity(SDF_getGroupWsAfterAssociativity(arg)) : SDF_getGroupWsAfterAssociativity(arg),
        acceptWsAfterColon ? acceptWsAfterColon(SDF_getGroupWsAfterColon(arg)) : SDF_getGroupWsAfterColon(arg),
        acceptProductions ? acceptProductions(SDF_getGroupProductions(arg)) : SDF_getGroupProductions(arg),
        acceptWsAfterProductions ? acceptWsAfterProductions(SDF_getGroupWsAfterProductions(arg)) : SDF_getGroupWsAfterProductions(arg));
  }
  ATabort("not a Group: %t\n", arg);
  return (SDF_Group)NULL;
}

/*}}}  */
/*{{{  SDF_Priority SDF_visitPriority(SDF_Priority arg, SDF_GroupList (*acceptList)(SDF_GroupList), SDF_Group (*acceptLeft)(SDF_Group), char * (*acceptWsAfterLeft)(char *), SDF_Associativity (*acceptAssociativity)(SDF_Associativity), char * (*acceptWsAfterAssociativity)(char *), SDF_Group (*acceptRight)(SDF_Group)) */

SDF_Priority SDF_visitPriority(SDF_Priority arg, SDF_GroupList (*acceptList)(SDF_GroupList), SDF_Group (*acceptLeft)(SDF_Group), char * (*acceptWsAfterLeft)(char *), SDF_Associativity (*acceptAssociativity)(SDF_Associativity), char * (*acceptWsAfterAssociativity)(char *), SDF_Group (*acceptRight)(SDF_Group))
{
  if (SDF_isPriorityChain(arg)) {
    return SDF_makePriorityChain(
        acceptList ? acceptList(SDF_getPriorityList(arg)) : SDF_getPriorityList(arg));
  }
  if (SDF_isPriorityAssoc(arg)) {
    return SDF_makePriorityAssoc(
        acceptLeft ? acceptLeft(SDF_getPriorityLeft(arg)) : SDF_getPriorityLeft(arg),
        acceptWsAfterLeft ? acceptWsAfterLeft(SDF_getPriorityWsAfterLeft(arg)) : SDF_getPriorityWsAfterLeft(arg),
        acceptAssociativity ? acceptAssociativity(SDF_getPriorityAssociativity(arg)) : SDF_getPriorityAssociativity(arg),
        acceptWsAfterAssociativity ? acceptWsAfterAssociativity(SDF_getPriorityWsAfterAssociativity(arg)) : SDF_getPriorityWsAfterAssociativity(arg),
        acceptRight ? acceptRight(SDF_getPriorityRight(arg)) : SDF_getPriorityRight(arg));
  }
  ATabort("not a Priority: %t\n", arg);
  return (SDF_Priority)NULL;
}

/*}}}  */
/*{{{  SDF_GroupList SDF_visitGroupList(SDF_GroupList arg, SDF_Group (*acceptHead)(SDF_Group), char * (*acceptWsAfterFirst)(char *), char * (*acceptSep)(char *), char * (*acceptWsAfterSep)(char *)) */

SDF_GroupList SDF_visitGroupList(SDF_GroupList arg, SDF_Group (*acceptHead)(SDF_Group), char * (*acceptWsAfterFirst)(char *), char * (*acceptSep)(char *), char * (*acceptWsAfterSep)(char *))
{
  if (SDF_isGroupListSingle(arg)) {
    return SDF_makeGroupListSingle(
        acceptHead ? acceptHead(SDF_getGroupListHead(arg)) : SDF_getGroupListHead(arg));
  }
  if (SDF_isGroupListMany(arg)) {
    return SDF_makeGroupListMany(
        acceptHead ? acceptHead(SDF_getGroupListHead(arg)) : SDF_getGroupListHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(SDF_getGroupListWsAfterFirst(arg)) : SDF_getGroupListWsAfterFirst(arg),
        acceptSep ? acceptSep(SDF_getGroupListSep(arg)) : SDF_getGroupListSep(arg),
        acceptWsAfterSep ? acceptWsAfterSep(SDF_getGroupListWsAfterSep(arg)) : SDF_getGroupListWsAfterSep(arg),
        SDF_visitGroupList(SDF_getGroupListTail(arg), acceptHead, acceptWsAfterFirst, acceptSep, acceptWsAfterSep));
  }
  ATabort("not a GroupList: %t\n", arg);
  return (SDF_GroupList)NULL;
}

/*}}}  */
/*{{{  SDF_Priorities SDF_visitPriorities(SDF_Priorities arg, SDF_PriorityList (*acceptList)(SDF_PriorityList)) */

SDF_Priorities SDF_visitPriorities(SDF_Priorities arg, SDF_PriorityList (*acceptList)(SDF_PriorityList))
{
  if (SDF_isPrioritiesDefault(arg)) {
    return SDF_makePrioritiesDefault(
        acceptList ? acceptList(SDF_getPrioritiesList(arg)) : SDF_getPrioritiesList(arg));
  }
  ATabort("not a Priorities: %t\n", arg);
  return (SDF_Priorities)NULL;
}

/*}}}  */
/*{{{  SDF_PriorityList SDF_visitPriorityList(SDF_PriorityList arg, SDF_Priority (*acceptHead)(SDF_Priority), char * (*acceptWsAfterFirst)(char *), char * (*acceptSep)(char *), char * (*acceptWsAfterSep)(char *)) */

SDF_PriorityList SDF_visitPriorityList(SDF_PriorityList arg, SDF_Priority (*acceptHead)(SDF_Priority), char * (*acceptWsAfterFirst)(char *), char * (*acceptSep)(char *), char * (*acceptWsAfterSep)(char *))
{
  if (SDF_isPriorityListEmpty(arg)) {
    return SDF_makePriorityListEmpty();
  }
  if (SDF_isPriorityListSingle(arg)) {
    return SDF_makePriorityListSingle(
        acceptHead ? acceptHead(SDF_getPriorityListHead(arg)) : SDF_getPriorityListHead(arg));
  }
  if (SDF_isPriorityListMany(arg)) {
    return SDF_makePriorityListMany(
        acceptHead ? acceptHead(SDF_getPriorityListHead(arg)) : SDF_getPriorityListHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(SDF_getPriorityListWsAfterFirst(arg)) : SDF_getPriorityListWsAfterFirst(arg),
        acceptSep ? acceptSep(SDF_getPriorityListSep(arg)) : SDF_getPriorityListSep(arg),
        acceptWsAfterSep ? acceptWsAfterSep(SDF_getPriorityListWsAfterSep(arg)) : SDF_getPriorityListWsAfterSep(arg),
        SDF_visitPriorityList(SDF_getPriorityListTail(arg), acceptHead, acceptWsAfterFirst, acceptSep, acceptWsAfterSep));
  }
  ATabort("not a PriorityList: %t\n", arg);
  return (SDF_PriorityList)NULL;
}

/*}}}  */
/*{{{  SDF_Sort SDF_visitSort(SDF_Sort arg, char * (*acceptLex)(char *)) */

SDF_Sort SDF_visitSort(SDF_Sort arg, char * (*acceptLex)(char *))
{
  if (SDF_isSortOneChar(arg)) {
    return SDF_makeSortOneChar(
        acceptLex ? acceptLex(SDF_getSortLex(arg)) : SDF_getSortLex(arg));
  }
  if (SDF_isSortMoreChars(arg)) {
    return SDF_makeSortMoreChars(
        acceptLex ? acceptLex(SDF_getSortLex(arg)) : SDF_getSortLex(arg));
  }
  ATabort("not a Sort: %t\n", arg);
  return (SDF_Sort)NULL;
}

/*}}}  */
/*{{{  SDF_UQLiteral SDF_visitUQLiteral(SDF_UQLiteral arg, char * (*acceptLex)(char *)) */

SDF_UQLiteral SDF_visitUQLiteral(SDF_UQLiteral arg, char * (*acceptLex)(char *))
{
  if (SDF_isUQLiteralOneChar(arg)) {
    return SDF_makeUQLiteralOneChar(
        acceptLex ? acceptLex(SDF_getUQLiteralLex(arg)) : SDF_getUQLiteralLex(arg));
  }
  if (SDF_isUQLiteralMoreChars(arg)) {
    return SDF_makeUQLiteralMoreChars(
        acceptLex ? acceptLex(SDF_getUQLiteralLex(arg)) : SDF_getUQLiteralLex(arg));
  }
  ATabort("not a UQLiteral: %t\n", arg);
  return (SDF_UQLiteral)NULL;
}

/*}}}  */
/*{{{  SDF_Literal SDF_visitLiteral(SDF_Literal arg, SDF_UQLiteral (*acceptUQLiteral)(SDF_UQLiteral), char * (*acceptLex)(char *)) */

SDF_Literal SDF_visitLiteral(SDF_Literal arg, SDF_UQLiteral (*acceptUQLiteral)(SDF_UQLiteral), char * (*acceptLex)(char *))
{
  if (SDF_isLiteralUqlit(arg)) {
    return SDF_makeLiteralUqlit(
        acceptUQLiteral ? acceptUQLiteral(SDF_getLiteralUQLiteral(arg)) : SDF_getLiteralUQLiteral(arg));
  }
  if (SDF_isLiteralQuoted(arg)) {
    return SDF_makeLiteralQuoted(
        acceptLex ? acceptLex(SDF_getLiteralLex(arg)) : SDF_getLiteralLex(arg));
  }
  ATabort("not a Literal: %t\n", arg);
  return (SDF_Literal)NULL;
}

/*}}}  */
/*{{{  SDF_SymbolArguments SDF_visitSymbolArguments(SDF_SymbolArguments arg, SDF_Symbol (*acceptHead)(SDF_Symbol), char * (*acceptWsAfterFirst)(char *), char * (*acceptSep)(char *), char * (*acceptWsAfterSep)(char *)) */

SDF_SymbolArguments SDF_visitSymbolArguments(SDF_SymbolArguments arg, SDF_Symbol (*acceptHead)(SDF_Symbol), char * (*acceptWsAfterFirst)(char *), char * (*acceptSep)(char *), char * (*acceptWsAfterSep)(char *))
{
  if (SDF_isSymbolArgumentsEmpty(arg)) {
    return SDF_makeSymbolArgumentsEmpty();
  }
  if (SDF_isSymbolArgumentsSingle(arg)) {
    return SDF_makeSymbolArgumentsSingle(
        acceptHead ? acceptHead(SDF_getSymbolArgumentsHead(arg)) : SDF_getSymbolArgumentsHead(arg));
  }
  if (SDF_isSymbolArgumentsMany(arg)) {
    return SDF_makeSymbolArgumentsMany(
        acceptHead ? acceptHead(SDF_getSymbolArgumentsHead(arg)) : SDF_getSymbolArgumentsHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(SDF_getSymbolArgumentsWsAfterFirst(arg)) : SDF_getSymbolArgumentsWsAfterFirst(arg),
        acceptSep ? acceptSep(SDF_getSymbolArgumentsSep(arg)) : SDF_getSymbolArgumentsSep(arg),
        acceptWsAfterSep ? acceptWsAfterSep(SDF_getSymbolArgumentsWsAfterSep(arg)) : SDF_getSymbolArgumentsWsAfterSep(arg),
        SDF_visitSymbolArguments(SDF_getSymbolArgumentsTail(arg), acceptHead, acceptWsAfterFirst, acceptSep, acceptWsAfterSep));
  }
  ATabort("not a SymbolArguments: %t\n", arg);
  return (SDF_SymbolArguments)NULL;
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_visitLookahead(SDF_Lookahead arg, SDF_CharClass (*acceptCharClass)(SDF_CharClass), SDF_CharClass (*acceptHead)(SDF_CharClass), char * (*acceptWsAfterHead)(char *), char * (*acceptWsAfterPeriod)(char *), SDF_Lookaheads (*acceptTail)(SDF_Lookaheads)) */

SDF_Lookahead SDF_visitLookahead(SDF_Lookahead arg, SDF_CharClass (*acceptCharClass)(SDF_CharClass), SDF_CharClass (*acceptHead)(SDF_CharClass), char * (*acceptWsAfterHead)(char *), char * (*acceptWsAfterPeriod)(char *), SDF_Lookaheads (*acceptTail)(SDF_Lookaheads))
{
  if (SDF_isLookaheadCharClass(arg)) {
    return SDF_makeLookaheadCharClass(
        acceptCharClass ? acceptCharClass(SDF_getLookaheadCharClass(arg)) : SDF_getLookaheadCharClass(arg));
  }
  if (SDF_isLookaheadSeq(arg)) {
    return SDF_makeLookaheadSeq(
        acceptHead ? acceptHead(SDF_getLookaheadHead(arg)) : SDF_getLookaheadHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(SDF_getLookaheadWsAfterHead(arg)) : SDF_getLookaheadWsAfterHead(arg),
        acceptWsAfterPeriod ? acceptWsAfterPeriod(SDF_getLookaheadWsAfterPeriod(arg)) : SDF_getLookaheadWsAfterPeriod(arg),
        acceptTail ? acceptTail(SDF_getLookaheadTail(arg)) : SDF_getLookaheadTail(arg));
  }
  ATabort("not a Lookahead: %t\n", arg);
  return (SDF_Lookahead)NULL;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_visitLookaheads(SDF_Lookaheads arg, SDF_Lookahead (*acceptLookahead)(SDF_Lookahead), char * (*acceptWsAfterLeft)(char *), char * (*acceptWsAfterBar)(char *), char * (*acceptWsAfterParenOpen)(char *), char * (*acceptWsAfterLookaheads)(char *), char * (*acceptWsAfterBracketOpenBracketOpen)(char *), SDF_LookaheadList (*acceptList)(SDF_LookaheadList), char * (*acceptWsAfterList)(char *)) */

SDF_Lookaheads SDF_visitLookaheads(SDF_Lookaheads arg, SDF_Lookahead (*acceptLookahead)(SDF_Lookahead), char * (*acceptWsAfterLeft)(char *), char * (*acceptWsAfterBar)(char *), char * (*acceptWsAfterParenOpen)(char *), char * (*acceptWsAfterLookaheads)(char *), char * (*acceptWsAfterBracketOpenBracketOpen)(char *), SDF_LookaheadList (*acceptList)(SDF_LookaheadList), char * (*acceptWsAfterList)(char *))
{
  if (SDF_isLookaheadsSingle(arg)) {
    return SDF_makeLookaheadsSingle(
        acceptLookahead ? acceptLookahead(SDF_getLookaheadsLookahead(arg)) : SDF_getLookaheadsLookahead(arg));
  }
  if (SDF_isLookaheadsAlt(arg)) {
    return SDF_makeLookaheadsAlt(
        SDF_visitLookaheads(SDF_getLookaheadsLeft(arg), acceptLookahead, acceptWsAfterLeft, acceptWsAfterBar, acceptWsAfterParenOpen, acceptWsAfterLookaheads, acceptWsAfterBracketOpenBracketOpen, acceptList, acceptWsAfterList),
        acceptWsAfterLeft ? acceptWsAfterLeft(SDF_getLookaheadsWsAfterLeft(arg)) : SDF_getLookaheadsWsAfterLeft(arg),
        acceptWsAfterBar ? acceptWsAfterBar(SDF_getLookaheadsWsAfterBar(arg)) : SDF_getLookaheadsWsAfterBar(arg),
        SDF_visitLookaheads(SDF_getLookaheadsRight(arg), acceptLookahead, acceptWsAfterLeft, acceptWsAfterBar, acceptWsAfterParenOpen, acceptWsAfterLookaheads, acceptWsAfterBracketOpenBracketOpen, acceptList, acceptWsAfterList));
  }
  if (SDF_isLookaheadsBracket(arg)) {
    return SDF_makeLookaheadsBracket(
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(SDF_getLookaheadsWsAfterParenOpen(arg)) : SDF_getLookaheadsWsAfterParenOpen(arg),
        SDF_visitLookaheads(SDF_getLookaheadsLookaheads(arg), acceptLookahead, acceptWsAfterLeft, acceptWsAfterBar, acceptWsAfterParenOpen, acceptWsAfterLookaheads, acceptWsAfterBracketOpenBracketOpen, acceptList, acceptWsAfterList),
        acceptWsAfterLookaheads ? acceptWsAfterLookaheads(SDF_getLookaheadsWsAfterLookaheads(arg)) : SDF_getLookaheadsWsAfterLookaheads(arg));
  }
  if (SDF_isLookaheadsList(arg)) {
    return SDF_makeLookaheadsList(
        acceptWsAfterBracketOpenBracketOpen ? acceptWsAfterBracketOpenBracketOpen(SDF_getLookaheadsWsAfterBracketOpenBracketOpen(arg)) : SDF_getLookaheadsWsAfterBracketOpenBracketOpen(arg),
        acceptList ? acceptList(SDF_getLookaheadsList(arg)) : SDF_getLookaheadsList(arg),
        acceptWsAfterList ? acceptWsAfterList(SDF_getLookaheadsWsAfterList(arg)) : SDF_getLookaheadsWsAfterList(arg));
  }
  ATabort("not a Lookaheads: %t\n", arg);
  return (SDF_Lookaheads)NULL;
}

/*}}}  */
/*{{{  SDF_LookaheadList SDF_visitLookaheadList(SDF_LookaheadList arg, SDF_Lookahead (*acceptHead)(SDF_Lookahead), char * (*acceptWsAfterFirst)(char *), char * (*acceptSep)(char *), char * (*acceptWsAfterSep)(char *)) */

SDF_LookaheadList SDF_visitLookaheadList(SDF_LookaheadList arg, SDF_Lookahead (*acceptHead)(SDF_Lookahead), char * (*acceptWsAfterFirst)(char *), char * (*acceptSep)(char *), char * (*acceptWsAfterSep)(char *))
{
  if (SDF_isLookaheadListEmpty(arg)) {
    return SDF_makeLookaheadListEmpty();
  }
  if (SDF_isLookaheadListSingle(arg)) {
    return SDF_makeLookaheadListSingle(
        acceptHead ? acceptHead(SDF_getLookaheadListHead(arg)) : SDF_getLookaheadListHead(arg));
  }
  if (SDF_isLookaheadListMany(arg)) {
    return SDF_makeLookaheadListMany(
        acceptHead ? acceptHead(SDF_getLookaheadListHead(arg)) : SDF_getLookaheadListHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(SDF_getLookaheadListWsAfterFirst(arg)) : SDF_getLookaheadListWsAfterFirst(arg),
        acceptSep ? acceptSep(SDF_getLookaheadListSep(arg)) : SDF_getLookaheadListSep(arg),
        acceptWsAfterSep ? acceptWsAfterSep(SDF_getLookaheadListWsAfterSep(arg)) : SDF_getLookaheadListWsAfterSep(arg),
        SDF_visitLookaheadList(SDF_getLookaheadListTail(arg), acceptHead, acceptWsAfterFirst, acceptSep, acceptWsAfterSep));
  }
  ATabort("not a LookaheadList: %t\n", arg);
  return (SDF_LookaheadList)NULL;
}

/*}}}  */
/*{{{  SDF_Restriction SDF_visitRestriction(SDF_Restriction arg, SDF_Symbols (*acceptSymbols)(SDF_Symbols), char * (*acceptWsAfterSymbols)(char *), char * (*acceptWsAfterSlash)(char *), SDF_Lookaheads (*acceptLookaheads)(SDF_Lookaheads)) */

SDF_Restriction SDF_visitRestriction(SDF_Restriction arg, SDF_Symbols (*acceptSymbols)(SDF_Symbols), char * (*acceptWsAfterSymbols)(char *), char * (*acceptWsAfterSlash)(char *), SDF_Lookaheads (*acceptLookaheads)(SDF_Lookaheads))
{
  if (SDF_isRestrictionFollow(arg)) {
    return SDF_makeRestrictionFollow(
        acceptSymbols ? acceptSymbols(SDF_getRestrictionSymbols(arg)) : SDF_getRestrictionSymbols(arg),
        acceptWsAfterSymbols ? acceptWsAfterSymbols(SDF_getRestrictionWsAfterSymbols(arg)) : SDF_getRestrictionWsAfterSymbols(arg),
        acceptWsAfterSlash ? acceptWsAfterSlash(SDF_getRestrictionWsAfterSlash(arg)) : SDF_getRestrictionWsAfterSlash(arg),
        acceptLookaheads ? acceptLookaheads(SDF_getRestrictionLookaheads(arg)) : SDF_getRestrictionLookaheads(arg));
  }
  ATabort("not a Restriction: %t\n", arg);
  return (SDF_Restriction)NULL;
}

/*}}}  */
/*{{{  SDF_Restrictions SDF_visitRestrictions(SDF_Restrictions arg, SDF_RestrictionList (*acceptList)(SDF_RestrictionList)) */

SDF_Restrictions SDF_visitRestrictions(SDF_Restrictions arg, SDF_RestrictionList (*acceptList)(SDF_RestrictionList))
{
  if (SDF_isRestrictionsDefault(arg)) {
    return SDF_makeRestrictionsDefault(
        acceptList ? acceptList(SDF_getRestrictionsList(arg)) : SDF_getRestrictionsList(arg));
  }
  ATabort("not a Restrictions: %t\n", arg);
  return (SDF_Restrictions)NULL;
}

/*}}}  */
/*{{{  SDF_RestrictionList SDF_visitRestrictionList(SDF_RestrictionList arg, SDF_Restriction (*acceptHead)(SDF_Restriction), char * (*acceptWsAfterFirst)(char *)) */

SDF_RestrictionList SDF_visitRestrictionList(SDF_RestrictionList arg, SDF_Restriction (*acceptHead)(SDF_Restriction), char * (*acceptWsAfterFirst)(char *))
{
  if (SDF_isRestrictionListEmpty(arg)) {
    return SDF_makeRestrictionListEmpty();
  }
  if (SDF_isRestrictionListSingle(arg)) {
    return SDF_makeRestrictionListSingle(
        acceptHead ? acceptHead(SDF_getRestrictionListHead(arg)) : SDF_getRestrictionListHead(arg));
  }
  if (SDF_isRestrictionListMany(arg)) {
    return SDF_makeRestrictionListMany(
        acceptHead ? acceptHead(SDF_getRestrictionListHead(arg)) : SDF_getRestrictionListHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(SDF_getRestrictionListWsAfterFirst(arg)) : SDF_getRestrictionListWsAfterFirst(arg),
        SDF_visitRestrictionList(SDF_getRestrictionListTail(arg), acceptHead, acceptWsAfterFirst));
  }
  ATabort("not a RestrictionList: %t\n", arg);
  return (SDF_RestrictionList)NULL;
}

/*}}}  */
/*{{{  SDF_Alias SDF_visitAlias(SDF_Alias arg, SDF_Symbol (*acceptSymbol)(SDF_Symbol), char * (*acceptWsAfterSymbol)(char *), char * (*acceptWsAfterArrow)(char *), SDF_Symbol (*acceptAlias)(SDF_Symbol)) */

SDF_Alias SDF_visitAlias(SDF_Alias arg, SDF_Symbol (*acceptSymbol)(SDF_Symbol), char * (*acceptWsAfterSymbol)(char *), char * (*acceptWsAfterArrow)(char *), SDF_Symbol (*acceptAlias)(SDF_Symbol))
{
  if (SDF_isAliasAlias(arg)) {
    return SDF_makeAliasAlias(
        acceptSymbol ? acceptSymbol(SDF_getAliasSymbol(arg)) : SDF_getAliasSymbol(arg),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(SDF_getAliasWsAfterSymbol(arg)) : SDF_getAliasWsAfterSymbol(arg),
        acceptWsAfterArrow ? acceptWsAfterArrow(SDF_getAliasWsAfterArrow(arg)) : SDF_getAliasWsAfterArrow(arg),
        acceptAlias ? acceptAlias(SDF_getAliasAlias(arg)) : SDF_getAliasAlias(arg));
  }
  ATabort("not a Alias: %t\n", arg);
  return (SDF_Alias)NULL;
}

/*}}}  */
/*{{{  SDF_Aliases SDF_visitAliases(SDF_Aliases arg, SDF_AliasList (*acceptList)(SDF_AliasList)) */

SDF_Aliases SDF_visitAliases(SDF_Aliases arg, SDF_AliasList (*acceptList)(SDF_AliasList))
{
  if (SDF_isAliasesDefault(arg)) {
    return SDF_makeAliasesDefault(
        acceptList ? acceptList(SDF_getAliasesList(arg)) : SDF_getAliasesList(arg));
  }
  ATabort("not a Aliases: %t\n", arg);
  return (SDF_Aliases)NULL;
}

/*}}}  */
/*{{{  SDF_AliasList SDF_visitAliasList(SDF_AliasList arg, SDF_Alias (*acceptHead)(SDF_Alias), char * (*acceptWsAfterFirst)(char *)) */

SDF_AliasList SDF_visitAliasList(SDF_AliasList arg, SDF_Alias (*acceptHead)(SDF_Alias), char * (*acceptWsAfterFirst)(char *))
{
  if (SDF_isAliasListEmpty(arg)) {
    return SDF_makeAliasListEmpty();
  }
  if (SDF_isAliasListSingle(arg)) {
    return SDF_makeAliasListSingle(
        acceptHead ? acceptHead(SDF_getAliasListHead(arg)) : SDF_getAliasListHead(arg));
  }
  if (SDF_isAliasListMany(arg)) {
    return SDF_makeAliasListMany(
        acceptHead ? acceptHead(SDF_getAliasListHead(arg)) : SDF_getAliasListHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(SDF_getAliasListWsAfterFirst(arg)) : SDF_getAliasListWsAfterFirst(arg),
        SDF_visitAliasList(SDF_getAliasListTail(arg), acceptHead, acceptWsAfterFirst));
  }
  ATabort("not a AliasList: %t\n", arg);
  return (SDF_AliasList)NULL;
}

/*}}}  */
/*{{{  SDF_Symbols SDF_visitSymbols(SDF_Symbols arg, SDF_SymbolList (*acceptList)(SDF_SymbolList)) */

SDF_Symbols SDF_visitSymbols(SDF_Symbols arg, SDF_SymbolList (*acceptList)(SDF_SymbolList))
{
  if (SDF_isSymbolsDefault(arg)) {
    return SDF_makeSymbolsDefault(
        acceptList ? acceptList(SDF_getSymbolsList(arg)) : SDF_getSymbolsList(arg));
  }
  ATabort("not a Symbols: %t\n", arg);
  return (SDF_Symbols)NULL;
}

/*}}}  */
/*{{{  SDF_SymbolList SDF_visitSymbolList(SDF_SymbolList arg, SDF_Symbol (*acceptHead)(SDF_Symbol), char * (*acceptWsAfterFirst)(char *)) */

SDF_SymbolList SDF_visitSymbolList(SDF_SymbolList arg, SDF_Symbol (*acceptHead)(SDF_Symbol), char * (*acceptWsAfterFirst)(char *))
{
  if (SDF_isSymbolListEmpty(arg)) {
    return SDF_makeSymbolListEmpty();
  }
  if (SDF_isSymbolListSingle(arg)) {
    return SDF_makeSymbolListSingle(
        acceptHead ? acceptHead(SDF_getSymbolListHead(arg)) : SDF_getSymbolListHead(arg));
  }
  if (SDF_isSymbolListMany(arg)) {
    return SDF_makeSymbolListMany(
        acceptHead ? acceptHead(SDF_getSymbolListHead(arg)) : SDF_getSymbolListHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(SDF_getSymbolListWsAfterFirst(arg)) : SDF_getSymbolListWsAfterFirst(arg),
        SDF_visitSymbolList(SDF_getSymbolListTail(arg), acceptHead, acceptWsAfterFirst));
  }
  ATabort("not a SymbolList: %t\n", arg);
  return (SDF_SymbolList)NULL;
}

/*}}}  */
/*{{{  SDF_Renamings SDF_visitRenamings(SDF_Renamings arg, char * (*acceptWsAfterBracketOpen)(char *), SDF_RenamingList (*acceptList)(SDF_RenamingList), char * (*acceptWsAfterList)(char *)) */

SDF_Renamings SDF_visitRenamings(SDF_Renamings arg, char * (*acceptWsAfterBracketOpen)(char *), SDF_RenamingList (*acceptList)(SDF_RenamingList), char * (*acceptWsAfterList)(char *))
{
  if (SDF_isRenamingsRenamings(arg)) {
    return SDF_makeRenamingsRenamings(
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(SDF_getRenamingsWsAfterBracketOpen(arg)) : SDF_getRenamingsWsAfterBracketOpen(arg),
        acceptList ? acceptList(SDF_getRenamingsList(arg)) : SDF_getRenamingsList(arg),
        acceptWsAfterList ? acceptWsAfterList(SDF_getRenamingsWsAfterList(arg)) : SDF_getRenamingsWsAfterList(arg));
  }
  ATabort("not a Renamings: %t\n", arg);
  return (SDF_Renamings)NULL;
}

/*}}}  */
/*{{{  SDF_RenamingList SDF_visitRenamingList(SDF_RenamingList arg, SDF_Renaming (*acceptHead)(SDF_Renaming), char * (*acceptWsAfterFirst)(char *)) */

SDF_RenamingList SDF_visitRenamingList(SDF_RenamingList arg, SDF_Renaming (*acceptHead)(SDF_Renaming), char * (*acceptWsAfterFirst)(char *))
{
  if (SDF_isRenamingListEmpty(arg)) {
    return SDF_makeRenamingListEmpty();
  }
  if (SDF_isRenamingListSingle(arg)) {
    return SDF_makeRenamingListSingle(
        acceptHead ? acceptHead(SDF_getRenamingListHead(arg)) : SDF_getRenamingListHead(arg));
  }
  if (SDF_isRenamingListMany(arg)) {
    return SDF_makeRenamingListMany(
        acceptHead ? acceptHead(SDF_getRenamingListHead(arg)) : SDF_getRenamingListHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(SDF_getRenamingListWsAfterFirst(arg)) : SDF_getRenamingListWsAfterFirst(arg),
        SDF_visitRenamingList(SDF_getRenamingListTail(arg), acceptHead, acceptWsAfterFirst));
  }
  ATabort("not a RenamingList: %t\n", arg);
  return (SDF_RenamingList)NULL;
}

/*}}}  */
/*{{{  SDF_Renaming SDF_visitRenaming(SDF_Renaming arg, SDF_Symbol (*acceptFrom)(SDF_Symbol), char * (*acceptWsAfterFrom)(char *), char * (*acceptWsAfterEqualsGreaterThan)(char *), SDF_Symbol (*acceptTo)(SDF_Symbol)) */

SDF_Renaming SDF_visitRenaming(SDF_Renaming arg, SDF_Symbol (*acceptFrom)(SDF_Symbol), char * (*acceptWsAfterFrom)(char *), char * (*acceptWsAfterEqualsGreaterThan)(char *), SDF_Symbol (*acceptTo)(SDF_Symbol))
{
  if (SDF_isRenamingSymbol(arg)) {
    return SDF_makeRenamingSymbol(
        acceptFrom ? acceptFrom(SDF_getRenamingFrom(arg)) : SDF_getRenamingFrom(arg),
        acceptWsAfterFrom ? acceptWsAfterFrom(SDF_getRenamingWsAfterFrom(arg)) : SDF_getRenamingWsAfterFrom(arg),
        acceptWsAfterEqualsGreaterThan ? acceptWsAfterEqualsGreaterThan(SDF_getRenamingWsAfterEqualsGreaterThan(arg)) : SDF_getRenamingWsAfterEqualsGreaterThan(arg),
        acceptTo ? acceptTo(SDF_getRenamingTo(arg)) : SDF_getRenamingTo(arg));
  }
  if (SDF_isRenamingProduction(arg)) {
    return SDF_makeRenamingProduction(
        acceptFrom ? acceptFrom(SDF_getRenamingFrom(arg)) : SDF_getRenamingFrom(arg),
        acceptWsAfterFrom ? acceptWsAfterFrom(SDF_getRenamingWsAfterFrom(arg)) : SDF_getRenamingWsAfterFrom(arg),
        acceptWsAfterEqualsGreaterThan ? acceptWsAfterEqualsGreaterThan(SDF_getRenamingWsAfterEqualsGreaterThan(arg)) : SDF_getRenamingWsAfterEqualsGreaterThan(arg),
        acceptTo ? acceptTo(SDF_getRenamingTo(arg)) : SDF_getRenamingTo(arg));
  }
  ATabort("not a Renaming: %t\n", arg);
  return (SDF_Renaming)NULL;
}

/*}}}  */
/*{{{  SDF_NatCon SDF_visitNatCon(SDF_NatCon arg, char * (*acceptLex)(char *)) */

SDF_NatCon SDF_visitNatCon(SDF_NatCon arg, char * (*acceptLex)(char *))
{
  if (SDF_isNatConDigits(arg)) {
    return SDF_makeNatConDigits(
        acceptLex ? acceptLex(SDF_getNatConLex(arg)) : SDF_getNatConLex(arg));
  }
  ATabort("not a NatCon: %t\n", arg);
  return (SDF_NatCon)NULL;
}

/*}}}  */
/*{{{  SDF_IntCon SDF_visitIntCon(SDF_IntCon arg, SDF_NatCon (*acceptNatCon)(SDF_NatCon), char * (*acceptWsAfterPos)(char *), char * (*acceptWsAfterNeg)(char *)) */

SDF_IntCon SDF_visitIntCon(SDF_IntCon arg, SDF_NatCon (*acceptNatCon)(SDF_NatCon), char * (*acceptWsAfterPos)(char *), char * (*acceptWsAfterNeg)(char *))
{
  if (SDF_isIntConNatural(arg)) {
    return SDF_makeIntConNatural(
        acceptNatCon ? acceptNatCon(SDF_getIntConNatCon(arg)) : SDF_getIntConNatCon(arg));
  }
  if (SDF_isIntConPositive(arg)) {
    return SDF_makeIntConPositive(
        acceptWsAfterPos ? acceptWsAfterPos(SDF_getIntConWsAfterPos(arg)) : SDF_getIntConWsAfterPos(arg),
        acceptNatCon ? acceptNatCon(SDF_getIntConNatCon(arg)) : SDF_getIntConNatCon(arg));
  }
  if (SDF_isIntConNegative(arg)) {
    return SDF_makeIntConNegative(
        acceptWsAfterNeg ? acceptWsAfterNeg(SDF_getIntConWsAfterNeg(arg)) : SDF_getIntConWsAfterNeg(arg),
        acceptNatCon ? acceptNatCon(SDF_getIntConNatCon(arg)) : SDF_getIntConNatCon(arg));
  }
  ATabort("not a IntCon: %t\n", arg);
  return (SDF_IntCon)NULL;
}

/*}}}  */
/*{{{  SDF_CharRange SDF_visitCharRange(SDF_CharRange arg, SDF_Character (*acceptCharacter)(SDF_Character), SDF_Character (*acceptStart)(SDF_Character), char * (*acceptWsAfterStart)(char *), char * (*acceptWsAfter)(char *), SDF_Character (*acceptEnd)(SDF_Character)) */

SDF_CharRange SDF_visitCharRange(SDF_CharRange arg, SDF_Character (*acceptCharacter)(SDF_Character), SDF_Character (*acceptStart)(SDF_Character), char * (*acceptWsAfterStart)(char *), char * (*acceptWsAfter)(char *), SDF_Character (*acceptEnd)(SDF_Character))
{
  if (SDF_isCharRangeDefault(arg)) {
    return SDF_makeCharRangeDefault(
        acceptCharacter ? acceptCharacter(SDF_getCharRangeCharacter(arg)) : SDF_getCharRangeCharacter(arg));
  }
  if (SDF_isCharRangeRange(arg)) {
    return SDF_makeCharRangeRange(
        acceptStart ? acceptStart(SDF_getCharRangeStart(arg)) : SDF_getCharRangeStart(arg),
        acceptWsAfterStart ? acceptWsAfterStart(SDF_getCharRangeWsAfterStart(arg)) : SDF_getCharRangeWsAfterStart(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getCharRangeWsAfter(arg)) : SDF_getCharRangeWsAfter(arg),
        acceptEnd ? acceptEnd(SDF_getCharRangeEnd(arg)) : SDF_getCharRangeEnd(arg));
  }
  ATabort("not a CharRange: %t\n", arg);
  return (SDF_CharRange)NULL;
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_visitCharRanges(SDF_CharRanges arg, SDF_CharRange (*acceptCharRange)(SDF_CharRange), char * (*acceptWsAfterLeft)(char *), char * (*acceptWsAfterParenOpen)(char *), char * (*acceptWsAfterCharRanges)(char *)) */

SDF_CharRanges SDF_visitCharRanges(SDF_CharRanges arg, SDF_CharRange (*acceptCharRange)(SDF_CharRange), char * (*acceptWsAfterLeft)(char *), char * (*acceptWsAfterParenOpen)(char *), char * (*acceptWsAfterCharRanges)(char *))
{
  if (SDF_isCharRangesDefault(arg)) {
    return SDF_makeCharRangesDefault(
        acceptCharRange ? acceptCharRange(SDF_getCharRangesCharRange(arg)) : SDF_getCharRangesCharRange(arg));
  }
  if (SDF_isCharRangesConc(arg)) {
    return SDF_makeCharRangesConc(
        SDF_visitCharRanges(SDF_getCharRangesLeft(arg), acceptCharRange, acceptWsAfterLeft, acceptWsAfterParenOpen, acceptWsAfterCharRanges),
        acceptWsAfterLeft ? acceptWsAfterLeft(SDF_getCharRangesWsAfterLeft(arg)) : SDF_getCharRangesWsAfterLeft(arg),
        SDF_visitCharRanges(SDF_getCharRangesRight(arg), acceptCharRange, acceptWsAfterLeft, acceptWsAfterParenOpen, acceptWsAfterCharRanges));
  }
  if (SDF_isCharRangesBracket(arg)) {
    return SDF_makeCharRangesBracket(
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(SDF_getCharRangesWsAfterParenOpen(arg)) : SDF_getCharRangesWsAfterParenOpen(arg),
        SDF_visitCharRanges(SDF_getCharRangesCharRanges(arg), acceptCharRange, acceptWsAfterLeft, acceptWsAfterParenOpen, acceptWsAfterCharRanges),
        acceptWsAfterCharRanges ? acceptWsAfterCharRanges(SDF_getCharRangesWsAfterCharRanges(arg)) : SDF_getCharRangesWsAfterCharRanges(arg));
  }
  ATabort("not a CharRanges: %t\n", arg);
  return (SDF_CharRanges)NULL;
}

/*}}}  */
/*{{{  SDF_OptCharRanges SDF_visitOptCharRanges(SDF_OptCharRanges arg, SDF_CharRanges (*acceptCharRanges)(SDF_CharRanges)) */

SDF_OptCharRanges SDF_visitOptCharRanges(SDF_OptCharRanges arg, SDF_CharRanges (*acceptCharRanges)(SDF_CharRanges))
{
  if (SDF_isOptCharRangesAbsent(arg)) {
    return SDF_makeOptCharRangesAbsent();
  }
  if (SDF_isOptCharRangesPresent(arg)) {
    return SDF_makeOptCharRangesPresent(
        acceptCharRanges ? acceptCharRanges(SDF_getOptCharRangesCharRanges(arg)) : SDF_getOptCharRangesCharRanges(arg));
  }
  ATabort("not a OptCharRanges: %t\n", arg);
  return (SDF_OptCharRanges)NULL;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_visitCharClass(SDF_CharClass arg, char * (*acceptWsAfterBracketOpen)(char *), SDF_OptCharRanges (*acceptOptCharRanges)(SDF_OptCharRanges), char * (*acceptWsAfterOptCharRanges)(char *), char * (*acceptWsAfterTilde)(char *), char * (*acceptWsAfterLeft)(char *), char * (*acceptWsAfterSlash)(char *), char * (*acceptWsAfterSlashBackslash)(char *), char * (*acceptWsAfterBackslashSlash)(char *), char * (*acceptWsAfterParenOpen)(char *), char * (*acceptWsAfterCharClass)(char *)) */

SDF_CharClass SDF_visitCharClass(SDF_CharClass arg, char * (*acceptWsAfterBracketOpen)(char *), SDF_OptCharRanges (*acceptOptCharRanges)(SDF_OptCharRanges), char * (*acceptWsAfterOptCharRanges)(char *), char * (*acceptWsAfterTilde)(char *), char * (*acceptWsAfterLeft)(char *), char * (*acceptWsAfterSlash)(char *), char * (*acceptWsAfterSlashBackslash)(char *), char * (*acceptWsAfterBackslashSlash)(char *), char * (*acceptWsAfterParenOpen)(char *), char * (*acceptWsAfterCharClass)(char *))
{
  if (SDF_isCharClassSimpleCharclass(arg)) {
    return SDF_makeCharClassSimpleCharclass(
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(SDF_getCharClassWsAfterBracketOpen(arg)) : SDF_getCharClassWsAfterBracketOpen(arg),
        acceptOptCharRanges ? acceptOptCharRanges(SDF_getCharClassOptCharRanges(arg)) : SDF_getCharClassOptCharRanges(arg),
        acceptWsAfterOptCharRanges ? acceptWsAfterOptCharRanges(SDF_getCharClassWsAfterOptCharRanges(arg)) : SDF_getCharClassWsAfterOptCharRanges(arg));
  }
  if (SDF_isCharClassComp(arg)) {
    return SDF_makeCharClassComp(
        acceptWsAfterTilde ? acceptWsAfterTilde(SDF_getCharClassWsAfterTilde(arg)) : SDF_getCharClassWsAfterTilde(arg),
        SDF_visitCharClass(SDF_getCharClassCharClass(arg), acceptWsAfterBracketOpen, acceptOptCharRanges, acceptWsAfterOptCharRanges, acceptWsAfterTilde, acceptWsAfterLeft, acceptWsAfterSlash, acceptWsAfterSlashBackslash, acceptWsAfterBackslashSlash, acceptWsAfterParenOpen, acceptWsAfterCharClass));
  }
  if (SDF_isCharClassDiff(arg)) {
    return SDF_makeCharClassDiff(
        SDF_visitCharClass(SDF_getCharClassLeft(arg), acceptWsAfterBracketOpen, acceptOptCharRanges, acceptWsAfterOptCharRanges, acceptWsAfterTilde, acceptWsAfterLeft, acceptWsAfterSlash, acceptWsAfterSlashBackslash, acceptWsAfterBackslashSlash, acceptWsAfterParenOpen, acceptWsAfterCharClass),
        acceptWsAfterLeft ? acceptWsAfterLeft(SDF_getCharClassWsAfterLeft(arg)) : SDF_getCharClassWsAfterLeft(arg),
        acceptWsAfterSlash ? acceptWsAfterSlash(SDF_getCharClassWsAfterSlash(arg)) : SDF_getCharClassWsAfterSlash(arg),
        SDF_visitCharClass(SDF_getCharClassRight(arg), acceptWsAfterBracketOpen, acceptOptCharRanges, acceptWsAfterOptCharRanges, acceptWsAfterTilde, acceptWsAfterLeft, acceptWsAfterSlash, acceptWsAfterSlashBackslash, acceptWsAfterBackslashSlash, acceptWsAfterParenOpen, acceptWsAfterCharClass));
  }
  if (SDF_isCharClassIsect(arg)) {
    return SDF_makeCharClassIsect(
        SDF_visitCharClass(SDF_getCharClassLeft(arg), acceptWsAfterBracketOpen, acceptOptCharRanges, acceptWsAfterOptCharRanges, acceptWsAfterTilde, acceptWsAfterLeft, acceptWsAfterSlash, acceptWsAfterSlashBackslash, acceptWsAfterBackslashSlash, acceptWsAfterParenOpen, acceptWsAfterCharClass),
        acceptWsAfterLeft ? acceptWsAfterLeft(SDF_getCharClassWsAfterLeft(arg)) : SDF_getCharClassWsAfterLeft(arg),
        acceptWsAfterSlashBackslash ? acceptWsAfterSlashBackslash(SDF_getCharClassWsAfterSlashBackslash(arg)) : SDF_getCharClassWsAfterSlashBackslash(arg),
        SDF_visitCharClass(SDF_getCharClassRight(arg), acceptWsAfterBracketOpen, acceptOptCharRanges, acceptWsAfterOptCharRanges, acceptWsAfterTilde, acceptWsAfterLeft, acceptWsAfterSlash, acceptWsAfterSlashBackslash, acceptWsAfterBackslashSlash, acceptWsAfterParenOpen, acceptWsAfterCharClass));
  }
  if (SDF_isCharClassUnion(arg)) {
    return SDF_makeCharClassUnion(
        SDF_visitCharClass(SDF_getCharClassLeft(arg), acceptWsAfterBracketOpen, acceptOptCharRanges, acceptWsAfterOptCharRanges, acceptWsAfterTilde, acceptWsAfterLeft, acceptWsAfterSlash, acceptWsAfterSlashBackslash, acceptWsAfterBackslashSlash, acceptWsAfterParenOpen, acceptWsAfterCharClass),
        acceptWsAfterLeft ? acceptWsAfterLeft(SDF_getCharClassWsAfterLeft(arg)) : SDF_getCharClassWsAfterLeft(arg),
        acceptWsAfterBackslashSlash ? acceptWsAfterBackslashSlash(SDF_getCharClassWsAfterBackslashSlash(arg)) : SDF_getCharClassWsAfterBackslashSlash(arg),
        SDF_visitCharClass(SDF_getCharClassRight(arg), acceptWsAfterBracketOpen, acceptOptCharRanges, acceptWsAfterOptCharRanges, acceptWsAfterTilde, acceptWsAfterLeft, acceptWsAfterSlash, acceptWsAfterSlashBackslash, acceptWsAfterBackslashSlash, acceptWsAfterParenOpen, acceptWsAfterCharClass));
  }
  if (SDF_isCharClassBracket(arg)) {
    return SDF_makeCharClassBracket(
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(SDF_getCharClassWsAfterParenOpen(arg)) : SDF_getCharClassWsAfterParenOpen(arg),
        SDF_visitCharClass(SDF_getCharClassCharClass(arg), acceptWsAfterBracketOpen, acceptOptCharRanges, acceptWsAfterOptCharRanges, acceptWsAfterTilde, acceptWsAfterLeft, acceptWsAfterSlash, acceptWsAfterSlashBackslash, acceptWsAfterBackslashSlash, acceptWsAfterParenOpen, acceptWsAfterCharClass),
        acceptWsAfterCharClass ? acceptWsAfterCharClass(SDF_getCharClassWsAfterCharClass(arg)) : SDF_getCharClassWsAfterCharClass(arg));
  }
  ATabort("not a CharClass: %t\n", arg);
  return (SDF_CharClass)NULL;
}

/*}}}  */
/*{{{  SDF_AlphaNumericalEscChar SDF_visitAlphaNumericalEscChar(SDF_AlphaNumericalEscChar arg, char * (*acceptLex)(char *)) */

SDF_AlphaNumericalEscChar SDF_visitAlphaNumericalEscChar(SDF_AlphaNumericalEscChar arg, char * (*acceptLex)(char *))
{
  if (SDF_isAlphaNumericalEscCharDefault(arg)) {
    return SDF_makeAlphaNumericalEscCharDefault(
        acceptLex ? acceptLex(SDF_getAlphaNumericalEscCharLex(arg)) : SDF_getAlphaNumericalEscCharLex(arg));
  }
  ATabort("not a AlphaNumericalEscChar: %t\n", arg);
  return (SDF_AlphaNumericalEscChar)NULL;
}

/*}}}  */
/*{{{  SDF_DecimalEscChar SDF_visitDecimalEscChar(SDF_DecimalEscChar arg, char * (*acceptLex)(char *)) */

SDF_DecimalEscChar SDF_visitDecimalEscChar(SDF_DecimalEscChar arg, char * (*acceptLex)(char *))
{
  if (SDF_isDecimalEscCharDec0_199(arg)) {
    return SDF_makeDecimalEscCharDec0_199(
        acceptLex ? acceptLex(SDF_getDecimalEscCharLex(arg)) : SDF_getDecimalEscCharLex(arg));
  }
  if (SDF_isDecimalEscCharDec200_249(arg)) {
    return SDF_makeDecimalEscCharDec200_249(
        acceptLex ? acceptLex(SDF_getDecimalEscCharLex(arg)) : SDF_getDecimalEscCharLex(arg));
  }
  if (SDF_isDecimalEscCharDec250_255(arg)) {
    return SDF_makeDecimalEscCharDec250_255(
        acceptLex ? acceptLex(SDF_getDecimalEscCharLex(arg)) : SDF_getDecimalEscCharLex(arg));
  }
  ATabort("not a DecimalEscChar: %t\n", arg);
  return (SDF_DecimalEscChar)NULL;
}

/*}}}  */
/*{{{  SDF_EscChar SDF_visitEscChar(SDF_EscChar arg, char * (*acceptLex)(char *)) */

SDF_EscChar SDF_visitEscChar(SDF_EscChar arg, char * (*acceptLex)(char *))
{
  if (SDF_isEscCharAlphaNumeric(arg)) {
    return SDF_makeEscCharAlphaNumeric(
        acceptLex ? acceptLex(SDF_getEscCharLex(arg)) : SDF_getEscCharLex(arg));
  }
  if (SDF_isEscCharDecimal(arg)) {
    return SDF_makeEscCharDecimal(
        acceptLex ? acceptLex(SDF_getEscCharLex(arg)) : SDF_getEscCharLex(arg));
  }
  ATabort("not a EscChar: %t\n", arg);
  return (SDF_EscChar)NULL;
}

/*}}}  */
/*{{{  SDF_LChar SDF_visitLChar(SDF_LChar arg, char * (*acceptLex)(char *)) */

SDF_LChar SDF_visitLChar(SDF_LChar arg, char * (*acceptLex)(char *))
{
  if (SDF_isLCharNormal(arg)) {
    return SDF_makeLCharNormal(
        acceptLex ? acceptLex(SDF_getLCharLex(arg)) : SDF_getLCharLex(arg));
  }
  if (SDF_isLCharEscaped(arg)) {
    return SDF_makeLCharEscaped(
        acceptLex ? acceptLex(SDF_getLCharLex(arg)) : SDF_getLCharLex(arg));
  }
  ATabort("not a LChar: %t\n", arg);
  return (SDF_LChar)NULL;
}

/*}}}  */
/*{{{  SDF_ATerms SDF_visitATerms(SDF_ATerms arg, SDF_ATerm (*acceptTerm)(SDF_ATerm), SDF_ATerm (*acceptHead)(SDF_ATerm), char * (*acceptWsAfterHead)(char *), char * (*acceptWsAfterComma)(char *)) */

SDF_ATerms SDF_visitATerms(SDF_ATerms arg, SDF_ATerm (*acceptTerm)(SDF_ATerm), SDF_ATerm (*acceptHead)(SDF_ATerm), char * (*acceptWsAfterHead)(char *), char * (*acceptWsAfterComma)(char *))
{
  if (SDF_isATermsAterm(arg)) {
    return SDF_makeATermsAterm(
        acceptTerm ? acceptTerm(SDF_getATermsTerm(arg)) : SDF_getATermsTerm(arg));
  }
  if (SDF_isATermsCons(arg)) {
    return SDF_makeATermsCons(
        acceptHead ? acceptHead(SDF_getATermsHead(arg)) : SDF_getATermsHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(SDF_getATermsWsAfterHead(arg)) : SDF_getATermsWsAfterHead(arg),
        acceptWsAfterComma ? acceptWsAfterComma(SDF_getATermsWsAfterComma(arg)) : SDF_getATermsWsAfterComma(arg),
        SDF_visitATerms(SDF_getATermsTail(arg), acceptTerm, acceptHead, acceptWsAfterHead, acceptWsAfterComma));
  }
  ATabort("not a ATerms: %t\n", arg);
  return (SDF_ATerms)NULL;
}

/*}}}  */
/*{{{  SDF_ATermList SDF_visitATermList(SDF_ATermList arg, char * (*acceptWsAfterBracketOpen)(char *), SDF_ATerms (*acceptATerms)(SDF_ATerms), char * (*acceptWsAfterATerms)(char *)) */

SDF_ATermList SDF_visitATermList(SDF_ATermList arg, char * (*acceptWsAfterBracketOpen)(char *), SDF_ATerms (*acceptATerms)(SDF_ATerms), char * (*acceptWsAfterATerms)(char *))
{
  if (SDF_isATermListEmpty(arg)) {
    return SDF_makeATermListEmpty(
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(SDF_getATermListWsAfterBracketOpen(arg)) : SDF_getATermListWsAfterBracketOpen(arg));
  }
  if (SDF_isATermListNotEmpty(arg)) {
    return SDF_makeATermListNotEmpty(
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(SDF_getATermListWsAfterBracketOpen(arg)) : SDF_getATermListWsAfterBracketOpen(arg),
        acceptATerms ? acceptATerms(SDF_getATermListATerms(arg)) : SDF_getATermListATerms(arg),
        acceptWsAfterATerms ? acceptWsAfterATerms(SDF_getATermListWsAfterATerms(arg)) : SDF_getATermListWsAfterATerms(arg));
  }
  ATabort("not a ATermList: %t\n", arg);
  return (SDF_ATermList)NULL;
}

/*}}}  */
/*{{{  SDF_ACon SDF_visitACon(SDF_ACon arg, SDF_IntCon (*acceptIntCon)(SDF_IntCon), SDF_RealCon (*acceptRealCon)(SDF_RealCon)) */

SDF_ACon SDF_visitACon(SDF_ACon arg, SDF_IntCon (*acceptIntCon)(SDF_IntCon), SDF_RealCon (*acceptRealCon)(SDF_RealCon))
{
  if (SDF_isAConInt(arg)) {
    return SDF_makeAConInt(
        acceptIntCon ? acceptIntCon(SDF_getAConIntCon(arg)) : SDF_getAConIntCon(arg));
  }
  if (SDF_isAConReal(arg)) {
    return SDF_makeAConReal(
        acceptRealCon ? acceptRealCon(SDF_getAConRealCon(arg)) : SDF_getAConRealCon(arg));
  }
  ATabort("not a ACon: %t\n", arg);
  return (SDF_ACon)NULL;
}

/*}}}  */
/*{{{  SDF_AFun SDF_visitAFun(SDF_AFun arg, SDF_Literal (*acceptLiteral)(SDF_Literal)) */

SDF_AFun SDF_visitAFun(SDF_AFun arg, SDF_Literal (*acceptLiteral)(SDF_Literal))
{
  if (SDF_isAFunDefault(arg)) {
    return SDF_makeAFunDefault(
        acceptLiteral ? acceptLiteral(SDF_getAFunLiteral(arg)) : SDF_getAFunLiteral(arg));
  }
  ATabort("not a AFun: %t\n", arg);
  return (SDF_AFun)NULL;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_visitATerm(SDF_ATerm arg, SDF_ACon (*acceptACon)(SDF_ACon), SDF_ATermList (*acceptList)(SDF_ATermList), SDF_AFun (*acceptFun)(SDF_AFun), char * (*acceptWsAfterFun)(char *), char * (*acceptWsAfterParenOpen)(char *), SDF_ATerms (*acceptArgs)(SDF_ATerms), char * (*acceptWsAfterArgs)(char *), char * (*acceptWsAfterACon)(char *), SDF_Ann (*acceptAnn)(SDF_Ann), char * (*acceptWsAfterList)(char *), char * (*acceptWsAfterParenClose)(char *)) */

SDF_ATerm SDF_visitATerm(SDF_ATerm arg, SDF_ACon (*acceptACon)(SDF_ACon), SDF_ATermList (*acceptList)(SDF_ATermList), SDF_AFun (*acceptFun)(SDF_AFun), char * (*acceptWsAfterFun)(char *), char * (*acceptWsAfterParenOpen)(char *), SDF_ATerms (*acceptArgs)(SDF_ATerms), char * (*acceptWsAfterArgs)(char *), char * (*acceptWsAfterACon)(char *), SDF_Ann (*acceptAnn)(SDF_Ann), char * (*acceptWsAfterList)(char *), char * (*acceptWsAfterParenClose)(char *))
{
  if (SDF_isATermConstant(arg)) {
    return SDF_makeATermConstant(
        acceptACon ? acceptACon(SDF_getATermACon(arg)) : SDF_getATermACon(arg));
  }
  if (SDF_isATermList(arg)) {
    return SDF_makeATermList(
        acceptList ? acceptList(SDF_getATermList(arg)) : SDF_getATermList(arg));
  }
  if (SDF_isATermFun(arg)) {
    return SDF_makeATermFun(
        acceptFun ? acceptFun(SDF_getATermFun(arg)) : SDF_getATermFun(arg));
  }
  if (SDF_isATermAppl(arg)) {
    return SDF_makeATermAppl(
        acceptFun ? acceptFun(SDF_getATermFun(arg)) : SDF_getATermFun(arg),
        acceptWsAfterFun ? acceptWsAfterFun(SDF_getATermWsAfterFun(arg)) : SDF_getATermWsAfterFun(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(SDF_getATermWsAfterParenOpen(arg)) : SDF_getATermWsAfterParenOpen(arg),
        acceptArgs ? acceptArgs(SDF_getATermArgs(arg)) : SDF_getATermArgs(arg),
        acceptWsAfterArgs ? acceptWsAfterArgs(SDF_getATermWsAfterArgs(arg)) : SDF_getATermWsAfterArgs(arg));
  }
  if (SDF_isATermAnnotatedConstant(arg)) {
    return SDF_makeATermAnnotatedConstant(
        acceptACon ? acceptACon(SDF_getATermACon(arg)) : SDF_getATermACon(arg),
        acceptWsAfterACon ? acceptWsAfterACon(SDF_getATermWsAfterACon(arg)) : SDF_getATermWsAfterACon(arg),
        acceptAnn ? acceptAnn(SDF_getATermAnn(arg)) : SDF_getATermAnn(arg));
  }
  if (SDF_isATermAnnotatedList(arg)) {
    return SDF_makeATermAnnotatedList(
        acceptList ? acceptList(SDF_getATermList(arg)) : SDF_getATermList(arg),
        acceptWsAfterList ? acceptWsAfterList(SDF_getATermWsAfterList(arg)) : SDF_getATermWsAfterList(arg),
        acceptAnn ? acceptAnn(SDF_getATermAnn(arg)) : SDF_getATermAnn(arg));
  }
  if (SDF_isATermAnnotatedFun(arg)) {
    return SDF_makeATermAnnotatedFun(
        acceptFun ? acceptFun(SDF_getATermFun(arg)) : SDF_getATermFun(arg),
        acceptWsAfterFun ? acceptWsAfterFun(SDF_getATermWsAfterFun(arg)) : SDF_getATermWsAfterFun(arg),
        acceptAnn ? acceptAnn(SDF_getATermAnn(arg)) : SDF_getATermAnn(arg));
  }
  if (SDF_isATermAnnotatedAppl(arg)) {
    return SDF_makeATermAnnotatedAppl(
        acceptFun ? acceptFun(SDF_getATermFun(arg)) : SDF_getATermFun(arg),
        acceptWsAfterFun ? acceptWsAfterFun(SDF_getATermWsAfterFun(arg)) : SDF_getATermWsAfterFun(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(SDF_getATermWsAfterParenOpen(arg)) : SDF_getATermWsAfterParenOpen(arg),
        acceptArgs ? acceptArgs(SDF_getATermArgs(arg)) : SDF_getATermArgs(arg),
        acceptWsAfterArgs ? acceptWsAfterArgs(SDF_getATermWsAfterArgs(arg)) : SDF_getATermWsAfterArgs(arg),
        acceptWsAfterParenClose ? acceptWsAfterParenClose(SDF_getATermWsAfterParenClose(arg)) : SDF_getATermWsAfterParenClose(arg),
        acceptAnn ? acceptAnn(SDF_getATermAnn(arg)) : SDF_getATermAnn(arg));
  }
  ATabort("not a ATerm: %t\n", arg);
  return (SDF_ATerm)NULL;
}

/*}}}  */
/*{{{  SDF_Ann SDF_visitAnn(SDF_Ann arg, char * (*acceptWsAfterBraceOpen)(char *), SDF_ATerms (*acceptATerms)(SDF_ATerms), char * (*acceptWsAfterATerms)(char *)) */

SDF_Ann SDF_visitAnn(SDF_Ann arg, char * (*acceptWsAfterBraceOpen)(char *), SDF_ATerms (*acceptATerms)(SDF_ATerms), char * (*acceptWsAfterATerms)(char *))
{
  if (SDF_isAnnAnnotation(arg)) {
    return SDF_makeAnnAnnotation(
        acceptWsAfterBraceOpen ? acceptWsAfterBraceOpen(SDF_getAnnWsAfterBraceOpen(arg)) : SDF_getAnnWsAfterBraceOpen(arg),
        acceptATerms ? acceptATerms(SDF_getAnnATerms(arg)) : SDF_getAnnATerms(arg),
        acceptWsAfterATerms ? acceptWsAfterATerms(SDF_getAnnWsAfterATerms(arg)) : SDF_getAnnWsAfterATerms(arg));
  }
  ATabort("not a Ann: %t\n", arg);
  return (SDF_Ann)NULL;
}

/*}}}  */
/*{{{  SDF_TagId SDF_visitTagId(SDF_TagId arg, char * (*acceptLex)(char *)) */

SDF_TagId SDF_visitTagId(SDF_TagId arg, char * (*acceptLex)(char *))
{
  if (SDF_isTagIdDefault(arg)) {
    return SDF_makeTagIdDefault(
        acceptLex ? acceptLex(SDF_getTagIdLex(arg)) : SDF_getTagIdLex(arg));
  }
  if (SDF_isTagIdEmpty(arg)) {
    return SDF_makeTagIdEmpty();
  }
  ATabort("not a TagId: %t\n", arg);
  return (SDF_TagId)NULL;
}

/*}}}  */
/*{{{  SDF_NumChar SDF_visitNumChar(SDF_NumChar arg, char * (*acceptLex)(char *)) */

SDF_NumChar SDF_visitNumChar(SDF_NumChar arg, char * (*acceptLex)(char *))
{
  if (SDF_isNumCharDigits(arg)) {
    return SDF_makeNumCharDigits(
        acceptLex ? acceptLex(SDF_getNumCharLex(arg)) : SDF_getNumCharLex(arg));
  }
  ATabort("not a NumChar: %t\n", arg);
  return (SDF_NumChar)NULL;
}

/*}}}  */
/*{{{  SDF_ShortChar SDF_visitShortChar(SDF_ShortChar arg, char * (*acceptLex)(char *)) */

SDF_ShortChar SDF_visitShortChar(SDF_ShortChar arg, char * (*acceptLex)(char *))
{
  if (SDF_isShortCharRegular(arg)) {
    return SDF_makeShortCharRegular(
        acceptLex ? acceptLex(SDF_getShortCharLex(arg)) : SDF_getShortCharLex(arg));
  }
  if (SDF_isShortCharEscaped(arg)) {
    return SDF_makeShortCharEscaped(
        acceptLex ? acceptLex(SDF_getShortCharLex(arg)) : SDF_getShortCharLex(arg));
  }
  ATabort("not a ShortChar: %t\n", arg);
  return (SDF_ShortChar)NULL;
}

/*}}}  */
/*{{{  SDF_Character SDF_visitCharacter(SDF_Character arg, SDF_NumChar (*acceptNumChar)(SDF_NumChar), SDF_ShortChar (*acceptShortChar)(SDF_ShortChar)) */

SDF_Character SDF_visitCharacter(SDF_Character arg, SDF_NumChar (*acceptNumChar)(SDF_NumChar), SDF_ShortChar (*acceptShortChar)(SDF_ShortChar))
{
  if (SDF_isCharacterNumeric(arg)) {
    return SDF_makeCharacterNumeric(
        acceptNumChar ? acceptNumChar(SDF_getCharacterNumChar(arg)) : SDF_getCharacterNumChar(arg));
  }
  if (SDF_isCharacterShort(arg)) {
    return SDF_makeCharacterShort(
        acceptShortChar ? acceptShortChar(SDF_getCharacterShortChar(arg)) : SDF_getCharacterShortChar(arg));
  }
  if (SDF_isCharacterTop(arg)) {
    return SDF_makeCharacterTop();
  }
  if (SDF_isCharacterEof(arg)) {
    return SDF_makeCharacterEof();
  }
  ATabort("not a Character: %t\n", arg);
  return (SDF_Character)NULL;
}

/*}}}  */
/*{{{  SDF_OptExp SDF_visitOptExp(SDF_OptExp arg, char * (*acceptWsAfterE)(char *), SDF_IntCon (*acceptIntCon)(SDF_IntCon)) */

SDF_OptExp SDF_visitOptExp(SDF_OptExp arg, char * (*acceptWsAfterE)(char *), SDF_IntCon (*acceptIntCon)(SDF_IntCon))
{
  if (SDF_isOptExpPresent(arg)) {
    return SDF_makeOptExpPresent(
        acceptWsAfterE ? acceptWsAfterE(SDF_getOptExpWsAfterE(arg)) : SDF_getOptExpWsAfterE(arg),
        acceptIntCon ? acceptIntCon(SDF_getOptExpIntCon(arg)) : SDF_getOptExpIntCon(arg));
  }
  if (SDF_isOptExpAbsent(arg)) {
    return SDF_makeOptExpAbsent();
  }
  ATabort("not a OptExp: %t\n", arg);
  return (SDF_OptExp)NULL;
}

/*}}}  */
/*{{{  SDF_RealCon SDF_visitRealCon(SDF_RealCon arg, SDF_IntCon (*acceptIntCon)(SDF_IntCon), char * (*acceptWsAfterIntCon)(char *), char * (*acceptWsAfterPeriod)(char *), SDF_NatCon (*acceptNatCon)(SDF_NatCon), char * (*acceptWsAfterNatCon)(char *), SDF_OptExp (*acceptOptExp)(SDF_OptExp)) */

SDF_RealCon SDF_visitRealCon(SDF_RealCon arg, SDF_IntCon (*acceptIntCon)(SDF_IntCon), char * (*acceptWsAfterIntCon)(char *), char * (*acceptWsAfterPeriod)(char *), SDF_NatCon (*acceptNatCon)(SDF_NatCon), char * (*acceptWsAfterNatCon)(char *), SDF_OptExp (*acceptOptExp)(SDF_OptExp))
{
  if (SDF_isRealConRealCon(arg)) {
    return SDF_makeRealConRealCon(
        acceptIntCon ? acceptIntCon(SDF_getRealConIntCon(arg)) : SDF_getRealConIntCon(arg),
        acceptWsAfterIntCon ? acceptWsAfterIntCon(SDF_getRealConWsAfterIntCon(arg)) : SDF_getRealConWsAfterIntCon(arg),
        acceptWsAfterPeriod ? acceptWsAfterPeriod(SDF_getRealConWsAfterPeriod(arg)) : SDF_getRealConWsAfterPeriod(arg),
        acceptNatCon ? acceptNatCon(SDF_getRealConNatCon(arg)) : SDF_getRealConNatCon(arg),
        acceptWsAfterNatCon ? acceptWsAfterNatCon(SDF_getRealConWsAfterNatCon(arg)) : SDF_getRealConWsAfterNatCon(arg),
        acceptOptExp ? acceptOptExp(SDF_getRealConOptExp(arg)) : SDF_getRealConOptExp(arg));
  }
  ATabort("not a RealCon: %t\n", arg);
  return (SDF_RealCon)NULL;
}

/*}}}  */

/*}}}  */
