#include <aterm2.h>
#include <deprecated.h>
#include "SDF.h"

/*{{{  typedefs */

typedef struct ATerm _SDF_Symbol;
typedef struct ATerm _SDF_Grammar;
typedef struct ATerm _SDF_SDF;
typedef struct ATerm _SDF_Attributes;
typedef struct ATerm _SDF_AttributeAttributes;
typedef struct ATerm _SDF_Production;
typedef struct ATerm _SDF_Productions;
typedef struct ATerm _SDF_ProductionProductions;
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
typedef struct ATerm _SDF_GroupGroupp;
typedef struct ATerm _SDF_Priorities;
typedef struct ATerm _SDF_PriorityPrioritys;
typedef struct ATerm _SDF_Sort;
typedef struct ATerm _SDF_UQLiteral;
typedef struct ATerm _SDF_Literal;
typedef struct ATerm _SDF_SymbolArguments;
typedef struct ATerm _SDF_Lookahead;
typedef struct ATerm _SDF_Lookaheads;
typedef struct ATerm _SDF_LookaheadLookaheads;
typedef struct ATerm _SDF_Restriction;
typedef struct ATerm _SDF_Restrictions;
typedef struct ATerm _SDF_RestrictionRestrictions;
typedef struct ATerm _SDF_Alias;
typedef struct ATerm _SDF_Aliases;
typedef struct ATerm _SDF_AliasAliass;
typedef struct ATerm _SDF_Symbols;
typedef struct ATerm _SDF_SymbolSymbols;
typedef struct ATerm _SDF_Renamings;
typedef struct ATerm _SDF_RenamingRenamings;
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
/*{{{  SDF_AttributeAttributes SDF_makeAttributeAttributesFromTerm(ATerm t) */

SDF_AttributeAttributes SDF_makeAttributeAttributesFromTerm(ATerm t)
{
  return (SDF_AttributeAttributes)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromAttributeAttributes(SDF_AttributeAttributes arg) */

ATerm SDF_makeTermFromAttributeAttributes(SDF_AttributeAttributes arg)
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
/*{{{  SDF_ProductionProductions SDF_makeProductionProductionsFromTerm(ATerm t) */

SDF_ProductionProductions SDF_makeProductionProductionsFromTerm(ATerm t)
{
  return (SDF_ProductionProductions)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromProductionProductions(SDF_ProductionProductions arg) */

ATerm SDF_makeTermFromProductionProductions(SDF_ProductionProductions arg)
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
/*{{{  SDF_GroupGroupp SDF_makeGroupGrouppFromTerm(ATerm t) */

SDF_GroupGroupp SDF_makeGroupGrouppFromTerm(ATerm t)
{
  return (SDF_GroupGroupp)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromGroupGroupp(SDF_GroupGroupp arg) */

ATerm SDF_makeTermFromGroupGroupp(SDF_GroupGroupp arg)
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
/*{{{  SDF_PriorityPrioritys SDF_makePriorityPrioritysFromTerm(ATerm t) */

SDF_PriorityPrioritys SDF_makePriorityPrioritysFromTerm(ATerm t)
{
  return (SDF_PriorityPrioritys)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromPriorityPrioritys(SDF_PriorityPrioritys arg) */

ATerm SDF_makeTermFromPriorityPrioritys(SDF_PriorityPrioritys arg)
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
/*{{{  SDF_LookaheadLookaheads SDF_makeLookaheadLookaheadsFromTerm(ATerm t) */

SDF_LookaheadLookaheads SDF_makeLookaheadLookaheadsFromTerm(ATerm t)
{
  return (SDF_LookaheadLookaheads)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromLookaheadLookaheads(SDF_LookaheadLookaheads arg) */

ATerm SDF_makeTermFromLookaheadLookaheads(SDF_LookaheadLookaheads arg)
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
/*{{{  SDF_RestrictionRestrictions SDF_makeRestrictionRestrictionsFromTerm(ATerm t) */

SDF_RestrictionRestrictions SDF_makeRestrictionRestrictionsFromTerm(ATerm t)
{
  return (SDF_RestrictionRestrictions)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromRestrictionRestrictions(SDF_RestrictionRestrictions arg) */

ATerm SDF_makeTermFromRestrictionRestrictions(SDF_RestrictionRestrictions arg)
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
/*{{{  SDF_AliasAliass SDF_makeAliasAliassFromTerm(ATerm t) */

SDF_AliasAliass SDF_makeAliasAliassFromTerm(ATerm t)
{
  return (SDF_AliasAliass)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromAliasAliass(SDF_AliasAliass arg) */

ATerm SDF_makeTermFromAliasAliass(SDF_AliasAliass arg)
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
/*{{{  SDF_SymbolSymbols SDF_makeSymbolSymbolsFromTerm(ATerm t) */

SDF_SymbolSymbols SDF_makeSymbolSymbolsFromTerm(ATerm t)
{
  return (SDF_SymbolSymbols)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromSymbolSymbols(SDF_SymbolSymbols arg) */

ATerm SDF_makeTermFromSymbolSymbols(SDF_SymbolSymbols arg)
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
/*{{{  SDF_RenamingRenamings SDF_makeRenamingRenamingsFromTerm(ATerm t) */

SDF_RenamingRenamings SDF_makeRenamingRenamingsFromTerm(ATerm t)
{
  return (SDF_RenamingRenamings)t;
}

/*}}}  */
/*{{{  ATerm SDF_makeTermFromRenamingRenamings(SDF_RenamingRenamings arg) */

ATerm SDF_makeTermFromRenamingRenamings(SDF_RenamingRenamings arg)
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
/*{{{  SDF_Symbol SDF_makeSymbolCf(SDF_Layout wsAfterLessThan, SDF_Symbol symbol, SDF_Layout wsAfterSymbol, SDF_Layout wsAfterCF) */

SDF_Symbol SDF_makeSymbolCf(SDF_Layout wsAfterLessThan, SDF_Symbol symbol, SDF_Layout wsAfterSymbol, SDF_Layout wsAfterCF)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolCf, wsAfterLessThan, symbol, wsAfterSymbol, wsAfterCF);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolLex(SDF_Layout wsAfterLessThan, SDF_Symbol symbol, SDF_Layout wsAfterSymbol, SDF_Layout wsAfterLEX) */

SDF_Symbol SDF_makeSymbolLex(SDF_Layout wsAfterLessThan, SDF_Symbol symbol, SDF_Layout wsAfterSymbol, SDF_Layout wsAfterLEX)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolLex, wsAfterLessThan, symbol, wsAfterSymbol, wsAfterLEX);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolVarsym(SDF_Layout wsAfterLessThan, SDF_Symbol symbol, SDF_Layout wsAfterSymbol, SDF_Layout wsAfterVAR) */

SDF_Symbol SDF_makeSymbolVarsym(SDF_Layout wsAfterLessThan, SDF_Symbol symbol, SDF_Layout wsAfterSymbol, SDF_Layout wsAfterVAR)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolVarsym, wsAfterLessThan, symbol, wsAfterSymbol, wsAfterVAR);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolLayout() */

SDF_Symbol SDF_makeSymbolLayout()
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolLayout);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolEmpty(SDF_Layout wsAfterParenOpen) */

SDF_Symbol SDF_makeSymbolEmpty(SDF_Layout wsAfterParenOpen)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolEmpty, wsAfterParenOpen);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolSeq(SDF_Layout wsAfterParenOpen, SDF_Symbol head, SDF_Layout wsAfterHead, SDF_SymbolTail tail, SDF_Layout wsAfterTail) */

SDF_Symbol SDF_makeSymbolSeq(SDF_Layout wsAfterParenOpen, SDF_Symbol head, SDF_Layout wsAfterHead, SDF_SymbolTail tail, SDF_Layout wsAfterTail)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolSeq, wsAfterParenOpen, head, wsAfterHead, tail, wsAfterTail);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolOpt(SDF_Symbol symbol, SDF_Layout wsAfterSymbol) */

SDF_Symbol SDF_makeSymbolOpt(SDF_Symbol symbol, SDF_Layout wsAfterSymbol)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolOpt, symbol, wsAfterSymbol);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolIter(SDF_Symbol symbol, SDF_Layout wsAfterSymbol) */

SDF_Symbol SDF_makeSymbolIter(SDF_Symbol symbol, SDF_Layout wsAfterSymbol)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolIter, symbol, wsAfterSymbol);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolIterStar(SDF_Symbol symbol, SDF_Layout wsAfterSymbol) */

SDF_Symbol SDF_makeSymbolIterStar(SDF_Symbol symbol, SDF_Layout wsAfterSymbol)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolIterStar, symbol, wsAfterSymbol);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolIterSep(SDF_Layout wsAfterBraceOpen, SDF_Symbol symbol, SDF_Layout wsAfterSymbol, SDF_Symbol sep, SDF_Layout wsAfterSep, SDF_Layout wsAfterBraceClose) */

SDF_Symbol SDF_makeSymbolIterSep(SDF_Layout wsAfterBraceOpen, SDF_Symbol symbol, SDF_Layout wsAfterSymbol, SDF_Symbol sep, SDF_Layout wsAfterSep, SDF_Layout wsAfterBraceClose)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolIterSep, wsAfterBraceOpen, symbol, wsAfterSymbol, sep, wsAfterSep, wsAfterBraceClose);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolIterStarSep(SDF_Layout wsAfterBraceOpen, SDF_Symbol symbol, SDF_Layout wsAfterSymbol, SDF_Symbol sep, SDF_Layout wsAfterSep, SDF_Layout wsAfterBraceClose) */

SDF_Symbol SDF_makeSymbolIterStarSep(SDF_Layout wsAfterBraceOpen, SDF_Symbol symbol, SDF_Layout wsAfterSymbol, SDF_Symbol sep, SDF_Layout wsAfterSep, SDF_Layout wsAfterBraceClose)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolIterStarSep, wsAfterBraceOpen, symbol, wsAfterSymbol, sep, wsAfterSep, wsAfterBraceClose);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolIterN(SDF_Symbol symbol, SDF_Layout wsAfterSymbol, SDF_NatCon n, SDF_Layout wsAfterN) */

SDF_Symbol SDF_makeSymbolIterN(SDF_Symbol symbol, SDF_Layout wsAfterSymbol, SDF_NatCon n, SDF_Layout wsAfterN)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolIterN, symbol, wsAfterSymbol, n, wsAfterN);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolIterSepN(SDF_Layout wsAfterBraceOpen, SDF_Symbol symbol, SDF_Layout wsAfterSymbol, SDF_Symbol sep, SDF_Layout wsAfterSep, SDF_Layout wsAfterBraceClose, SDF_NatCon n, SDF_Layout wsAfterN) */

SDF_Symbol SDF_makeSymbolIterSepN(SDF_Layout wsAfterBraceOpen, SDF_Symbol symbol, SDF_Layout wsAfterSymbol, SDF_Symbol sep, SDF_Layout wsAfterSep, SDF_Layout wsAfterBraceClose, SDF_NatCon n, SDF_Layout wsAfterN)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolIterSepN, wsAfterBraceOpen, symbol, wsAfterSymbol, sep, wsAfterSep, wsAfterBraceClose, n, wsAfterN);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolSet(SDF_Layout wsAfterSet, SDF_Layout wsAfterBracketOpen, SDF_Symbol symbol, SDF_Layout wsAfterSymbol) */

SDF_Symbol SDF_makeSymbolSet(SDF_Layout wsAfterSet, SDF_Layout wsAfterBracketOpen, SDF_Symbol symbol, SDF_Layout wsAfterSymbol)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolSet, wsAfterSet, wsAfterBracketOpen, symbol, wsAfterSymbol);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolPair(SDF_Symbol left, SDF_Layout wsAfterLeft, SDF_Layout wsAfterHash, SDF_Symbol right) */

SDF_Symbol SDF_makeSymbolPair(SDF_Symbol left, SDF_Layout wsAfterLeft, SDF_Layout wsAfterHash, SDF_Symbol right)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolPair, left, wsAfterLeft, wsAfterHash, right);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolFunc(SDF_Layout wsAfterParenOpen, SDF_Symbols arguments, SDF_Layout wsAfterArguments, SDF_Layout wsAfterEqualsGreaterThan, SDF_Symbol results, SDF_Layout wsAfterResults) */

SDF_Symbol SDF_makeSymbolFunc(SDF_Layout wsAfterParenOpen, SDF_Symbols arguments, SDF_Layout wsAfterArguments, SDF_Layout wsAfterEqualsGreaterThan, SDF_Symbol results, SDF_Layout wsAfterResults)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolFunc, wsAfterParenOpen, arguments, wsAfterArguments, wsAfterEqualsGreaterThan, results, wsAfterResults);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolAlt(SDF_Symbol left, SDF_Layout wsAfterLeft, SDF_Layout wsAfterBar, SDF_Symbol right) */

SDF_Symbol SDF_makeSymbolAlt(SDF_Symbol left, SDF_Layout wsAfterLeft, SDF_Layout wsAfterBar, SDF_Symbol right)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolAlt, left, wsAfterLeft, wsAfterBar, right);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolPerm(SDF_Layout wsAfterLessThanLessThan, SDF_Symbols symbols, SDF_Layout wsAfterSymbols) */

SDF_Symbol SDF_makeSymbolPerm(SDF_Layout wsAfterLessThanLessThan, SDF_Symbols symbols, SDF_Layout wsAfterSymbols)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolPerm, wsAfterLessThanLessThan, symbols, wsAfterSymbols);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolCharClass(SDF_CharClass charClass) */

SDF_Symbol SDF_makeSymbolCharClass(SDF_CharClass charClass)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolCharClass, charClass);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolSort(SDF_Sort sort) */

SDF_Symbol SDF_makeSymbolSort(SDF_Sort sort)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolSort, sort);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolLit(SDF_Literal literal) */

SDF_Symbol SDF_makeSymbolLit(SDF_Literal literal)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolLit, literal);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolLabel(SDF_Literal label, SDF_Layout wsAfterLabel, SDF_Layout wsAfterColon, SDF_Symbol symbol) */

SDF_Symbol SDF_makeSymbolLabel(SDF_Literal label, SDF_Layout wsAfterLabel, SDF_Layout wsAfterColon, SDF_Symbol symbol)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolLabel, label, wsAfterLabel, wsAfterColon, symbol);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolBracket(SDF_Layout wsAfterParenOpen, SDF_Symbol symbol, SDF_Layout wsAfterSymbol) */

SDF_Symbol SDF_makeSymbolBracket(SDF_Layout wsAfterParenOpen, SDF_Symbol symbol, SDF_Layout wsAfterSymbol)
{
  return (SDF_Symbol)ATmakeTerm(SDF_patternSymbolBracket, wsAfterParenOpen, symbol, wsAfterSymbol);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarLexicalPriorities(SDF_Layout wsAfterLexical, SDF_Layout wsAfterPriorities, SDF_Priorities priorities) */

SDF_Grammar SDF_makeGrammarLexicalPriorities(SDF_Layout wsAfterLexical, SDF_Layout wsAfterPriorities, SDF_Priorities priorities)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarLexicalPriorities, wsAfterLexical, wsAfterPriorities, priorities);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarContextFreePriorities(SDF_Layout wsAfterContextFree, SDF_Layout wsAfterPriorities, SDF_Priorities priorities) */

SDF_Grammar SDF_makeGrammarContextFreePriorities(SDF_Layout wsAfterContextFree, SDF_Layout wsAfterPriorities, SDF_Priorities priorities)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarContextFreePriorities, wsAfterContextFree, wsAfterPriorities, priorities);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarLexicalRestrictions(SDF_Layout wsAfterLexical, SDF_Layout wsAfterRestrictions, SDF_Restrictions restrictions) */

SDF_Grammar SDF_makeGrammarLexicalRestrictions(SDF_Layout wsAfterLexical, SDF_Layout wsAfterRestrictions, SDF_Restrictions restrictions)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarLexicalRestrictions, wsAfterLexical, wsAfterRestrictions, restrictions);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarContextFreeRestrictions(SDF_Layout wsAfterContextFree, SDF_Layout wsAfterRestrictions, SDF_Restrictions restrictions) */

SDF_Grammar SDF_makeGrammarContextFreeRestrictions(SDF_Layout wsAfterContextFree, SDF_Layout wsAfterRestrictions, SDF_Restrictions restrictions)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarContextFreeRestrictions, wsAfterContextFree, wsAfterRestrictions, restrictions);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarSyntax(SDF_Layout wsAfterSyntax, SDF_Productions productions) */

SDF_Grammar SDF_makeGrammarSyntax(SDF_Layout wsAfterSyntax, SDF_Productions productions)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarSyntax, wsAfterSyntax, productions);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarLexicalSyntax(SDF_Layout wsAfterLexical, SDF_Layout wsAfterSyntax, SDF_Productions productions) */

SDF_Grammar SDF_makeGrammarLexicalSyntax(SDF_Layout wsAfterLexical, SDF_Layout wsAfterSyntax, SDF_Productions productions)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarLexicalSyntax, wsAfterLexical, wsAfterSyntax, productions);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarContextFreeSyntax(SDF_Layout wsAfterContextFree, SDF_Layout wsAfterSyntax, SDF_Productions productions) */

SDF_Grammar SDF_makeGrammarContextFreeSyntax(SDF_Layout wsAfterContextFree, SDF_Layout wsAfterSyntax, SDF_Productions productions)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarContextFreeSyntax, wsAfterContextFree, wsAfterSyntax, productions);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarVariables(SDF_Layout wsAfterVariables, SDF_Productions productions) */

SDF_Grammar SDF_makeGrammarVariables(SDF_Layout wsAfterVariables, SDF_Productions productions)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarVariables, wsAfterVariables, productions);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarLexicalVariables(SDF_Layout wsAfterLexical, SDF_Layout wsAfterVariables, SDF_Productions productions) */

SDF_Grammar SDF_makeGrammarLexicalVariables(SDF_Layout wsAfterLexical, SDF_Layout wsAfterVariables, SDF_Productions productions)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarLexicalVariables, wsAfterLexical, wsAfterVariables, productions);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarImpSection(SDF_ImpSection impSection) */

SDF_Grammar SDF_makeGrammarImpSection(SDF_ImpSection impSection)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarImpSection, impSection);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarPriorities(SDF_Layout wsAfterPriorities, SDF_Priorities priorities) */

SDF_Grammar SDF_makeGrammarPriorities(SDF_Layout wsAfterPriorities, SDF_Priorities priorities)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarPriorities, wsAfterPriorities, priorities);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarSorts(SDF_Layout wsAfterSorts, SDF_Symbols symbols) */

SDF_Grammar SDF_makeGrammarSorts(SDF_Layout wsAfterSorts, SDF_Symbols symbols)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarSorts, wsAfterSorts, symbols);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarRestrictions(SDF_Layout wsAfterRestrictions, SDF_Restrictions restrictions) */

SDF_Grammar SDF_makeGrammarRestrictions(SDF_Layout wsAfterRestrictions, SDF_Restrictions restrictions)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarRestrictions, wsAfterRestrictions, restrictions);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarAliases(SDF_Layout wsAfterAliases, SDF_Aliases aliases) */

SDF_Grammar SDF_makeGrammarAliases(SDF_Layout wsAfterAliases, SDF_Aliases aliases)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarAliases, wsAfterAliases, aliases);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarEmptyGrammar() */

SDF_Grammar SDF_makeGrammarEmptyGrammar()
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarEmptyGrammar);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarConcGrammars(SDF_Grammar left, SDF_Layout wsAfterLeft, SDF_Grammar right) */

SDF_Grammar SDF_makeGrammarConcGrammars(SDF_Grammar left, SDF_Layout wsAfterLeft, SDF_Grammar right)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarConcGrammars, left, wsAfterLeft, right);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarBracket(SDF_Layout wsAfterParenOpen, SDF_Grammar grammar, SDF_Layout wsAfterGrammar) */

SDF_Grammar SDF_makeGrammarBracket(SDF_Layout wsAfterParenOpen, SDF_Grammar grammar, SDF_Layout wsAfterGrammar)
{
  return (SDF_Grammar)ATmakeTerm(SDF_patternGrammarBracket, wsAfterParenOpen, grammar, wsAfterGrammar);
}

/*}}}  */
/*{{{  SDF_SDF SDF_makeSDFDefinition(SDF_Layout wsAfterDefinition, SDF_Definition definition) */

SDF_SDF SDF_makeSDFDefinition(SDF_Layout wsAfterDefinition, SDF_Definition definition)
{
  return (SDF_SDF)ATmakeTerm(SDF_patternSDFDefinition, wsAfterDefinition, definition);
}

/*}}}  */
/*{{{  SDF_Attributes SDF_makeAttributesAttrs(SDF_Layout wsAfterBraceOpen, SDF_AttributeAttributes attributes, SDF_Layout wsAfterAttributes) */

SDF_Attributes SDF_makeAttributesAttrs(SDF_Layout wsAfterBraceOpen, SDF_AttributeAttributes attributes, SDF_Layout wsAfterAttributes)
{
  return (SDF_Attributes)ATmakeTerm(SDF_patternAttributesAttrs, wsAfterBraceOpen, attributes, wsAfterAttributes);
}

/*}}}  */
/*{{{  SDF_Attributes SDF_makeAttributesNoAttrs() */

SDF_Attributes SDF_makeAttributesNoAttrs()
{
  return (SDF_Attributes)ATmakeTerm(SDF_patternAttributesNoAttrs);
}

/*}}}  */
/*{{{  SDF_AttributeAttributes SDF_makeAttributeAttributesEmpty() */

SDF_AttributeAttributes SDF_makeAttributeAttributesEmpty()
{
  return (SDF_AttributeAttributes)ATmakeTerm(SDF_patternAttributeAttributesEmpty);
}

/*}}}  */
/*{{{  SDF_AttributeAttributes SDF_makeAttributeAttributesSingle(SDF_Attribute head) */

SDF_AttributeAttributes SDF_makeAttributeAttributesSingle(SDF_Attribute head)
{
  return (SDF_AttributeAttributes)ATmakeTerm(SDF_patternAttributeAttributesSingle, head);
}

/*}}}  */
/*{{{  SDF_AttributeAttributes SDF_makeAttributeAttributesMany(SDF_Attribute head, SDF_Layout wsAfterFirst, SDF_Separator sep, SDF_Layout wsAfterSep, SDF_AttributeAttributes tail) */

SDF_AttributeAttributes SDF_makeAttributeAttributesMany(SDF_Attribute head, SDF_Layout wsAfterFirst, SDF_Separator sep, SDF_Layout wsAfterSep, SDF_AttributeAttributes tail)
{
  return (SDF_AttributeAttributes)ATmakeTerm(SDF_patternAttributeAttributesMany, head, wsAfterFirst, sep, wsAfterSep, tail);
}

/*}}}  */
/*{{{  SDF_Production SDF_makeProductionProd(SDF_Symbols symbols, SDF_Layout wsAfterSymbols, SDF_Layout wsAfterGreaterThan, SDF_Symbol result, SDF_Layout wsAfterResult, SDF_Attributes attributes) */

SDF_Production SDF_makeProductionProd(SDF_Symbols symbols, SDF_Layout wsAfterSymbols, SDF_Layout wsAfterGreaterThan, SDF_Symbol result, SDF_Layout wsAfterResult, SDF_Attributes attributes)
{
  return (SDF_Production)ATmakeTerm(SDF_patternProductionProd, symbols, wsAfterSymbols, wsAfterGreaterThan, result, wsAfterResult, attributes);
}

/*}}}  */
/*{{{  SDF_Production SDF_makeProductionProdFun(SDF_Literal functionSymbol, SDF_Layout wsAfterFunctionSymbol, SDF_Layout wsAfterParenOpen, SDF_SymbolArguments arguments, SDF_Layout wsAfterArguments, SDF_Layout wsAfterParenClose, SDF_Layout wsAfterGreaterThan, SDF_Symbol result, SDF_Layout wsAfterResult, SDF_Attributes attributes) */

SDF_Production SDF_makeProductionProdFun(SDF_Literal functionSymbol, SDF_Layout wsAfterFunctionSymbol, SDF_Layout wsAfterParenOpen, SDF_SymbolArguments arguments, SDF_Layout wsAfterArguments, SDF_Layout wsAfterParenClose, SDF_Layout wsAfterGreaterThan, SDF_Symbol result, SDF_Layout wsAfterResult, SDF_Attributes attributes)
{
  return (SDF_Production)ATmakeTerm(SDF_patternProductionProdFun, functionSymbol, wsAfterFunctionSymbol, wsAfterParenOpen, arguments, wsAfterArguments, wsAfterParenClose, wsAfterGreaterThan, result, wsAfterResult, attributes);
}

/*}}}  */
/*{{{  SDF_Productions SDF_makeProductionsDefault(SDF_ProductionProductions productions) */

SDF_Productions SDF_makeProductionsDefault(SDF_ProductionProductions productions)
{
  return (SDF_Productions)ATmakeTerm(SDF_patternProductionsDefault, productions);
}

/*}}}  */
/*{{{  SDF_ProductionProductions SDF_makeProductionProductionsEmpty() */

SDF_ProductionProductions SDF_makeProductionProductionsEmpty()
{
  return (SDF_ProductionProductions)ATmakeTerm(SDF_patternProductionProductionsEmpty);
}

/*}}}  */
/*{{{  SDF_ProductionProductions SDF_makeProductionProductionsSingle(SDF_Production head) */

SDF_ProductionProductions SDF_makeProductionProductionsSingle(SDF_Production head)
{
  return (SDF_ProductionProductions)ATmakeTerm(SDF_patternProductionProductionsSingle, head);
}

/*}}}  */
/*{{{  SDF_ProductionProductions SDF_makeProductionProductionsMany(SDF_Production head, SDF_Layout wsAfterFirst, SDF_ProductionProductions tail) */

SDF_ProductionProductions SDF_makeProductionProductionsMany(SDF_Production head, SDF_Layout wsAfterFirst, SDF_ProductionProductions tail)
{
  return (SDF_ProductionProductions)ATmakeTerm(SDF_patternProductionProductionsMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDF_ModuleWord SDF_makeModuleWordWord(SDF_Lexical lex) */

SDF_ModuleWord SDF_makeModuleWordWord(SDF_Lexical lex)
{
  return (SDF_ModuleWord)ATmakeTerm(SDF_patternModuleWordWord, lex);
}

/*}}}  */
/*{{{  SDF_ModuleId SDF_makeModuleIdWord(SDF_Lexical lex) */

SDF_ModuleId SDF_makeModuleIdWord(SDF_Lexical lex)
{
  return (SDF_ModuleId)ATmakeTerm(SDF_patternModuleIdWord, lex);
}

/*}}}  */
/*{{{  SDF_ModuleId SDF_makeModuleIdSlashWord(SDF_Lexical lex) */

SDF_ModuleId SDF_makeModuleIdSlashWord(SDF_Lexical lex)
{
  return (SDF_ModuleId)ATmakeTerm(SDF_patternModuleIdSlashWord, lex);
}

/*}}}  */
/*{{{  SDF_ModuleId SDF_makeModuleIdWordSlashWord(SDF_Lexical lex) */

SDF_ModuleId SDF_makeModuleIdWordSlashWord(SDF_Lexical lex)
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
/*{{{  SDF_ModuleList SDF_makeModuleListMany(SDF_Module head, SDF_Layout wsAfterFirst, SDF_ModuleList tail) */

SDF_ModuleList SDF_makeModuleListMany(SDF_Module head, SDF_Layout wsAfterFirst, SDF_ModuleList tail)
{
  return (SDF_ModuleList)ATmakeTerm(SDF_patternModuleListMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDF_Module SDF_makeModuleModule(SDF_Layout wsAfterModule, SDF_ModuleName moduleName, SDF_Layout wsAfterModuleName, SDF_ImpSectionList list, SDF_Layout wsAfterList, SDF_Sections sections) */

SDF_Module SDF_makeModuleModule(SDF_Layout wsAfterModule, SDF_ModuleName moduleName, SDF_Layout wsAfterModuleName, SDF_ImpSectionList list, SDF_Layout wsAfterList, SDF_Sections sections)
{
  return (SDF_Module)ATmakeTerm(SDF_patternModuleModule, wsAfterModule, moduleName, wsAfterModuleName, list, wsAfterList, sections);
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
/*{{{  SDF_ImpSectionList SDF_makeImpSectionListMany(SDF_ImpSection head, SDF_Layout wsAfterFirst, SDF_ImpSectionList tail) */

SDF_ImpSectionList SDF_makeImpSectionListMany(SDF_ImpSection head, SDF_Layout wsAfterFirst, SDF_ImpSectionList tail)
{
  return (SDF_ImpSectionList)ATmakeTerm(SDF_patternImpSectionListMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDF_Section SDF_makeSectionExports(SDF_Layout wsAfterExports, SDF_Grammar grammar) */

SDF_Section SDF_makeSectionExports(SDF_Layout wsAfterExports, SDF_Grammar grammar)
{
  return (SDF_Section)ATmakeTerm(SDF_patternSectionExports, wsAfterExports, grammar);
}

/*}}}  */
/*{{{  SDF_Section SDF_makeSectionHiddens(SDF_Layout wsAfterHiddens, SDF_Grammar grammar) */

SDF_Section SDF_makeSectionHiddens(SDF_Layout wsAfterHiddens, SDF_Grammar grammar)
{
  return (SDF_Section)ATmakeTerm(SDF_patternSectionHiddens, wsAfterHiddens, grammar);
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
/*{{{  SDF_SectionList SDF_makeSectionListMany(SDF_Section head, SDF_Layout wsAfterFirst, SDF_SectionList tail) */

SDF_SectionList SDF_makeSectionListMany(SDF_Section head, SDF_Layout wsAfterFirst, SDF_SectionList tail)
{
  return (SDF_SectionList)ATmakeTerm(SDF_patternSectionListMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_makeModuleNameUnparameterized(SDF_ModuleId moduleId) */

SDF_ModuleName SDF_makeModuleNameUnparameterized(SDF_ModuleId moduleId)
{
  return (SDF_ModuleName)ATmakeTerm(SDF_patternModuleNameUnparameterized, moduleId);
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_makeModuleNameParameterized(SDF_ModuleId moduleId, SDF_Layout wsAfterModuleId, SDF_Layout wsAfterBracketOpen, SDF_Symbols params, SDF_Layout wsAfterParams) */

SDF_ModuleName SDF_makeModuleNameParameterized(SDF_ModuleId moduleId, SDF_Layout wsAfterModuleId, SDF_Layout wsAfterBracketOpen, SDF_Symbols params, SDF_Layout wsAfterParams)
{
  return (SDF_ModuleName)ATmakeTerm(SDF_patternModuleNameParameterized, moduleId, wsAfterModuleId, wsAfterBracketOpen, params, wsAfterParams);
}

/*}}}  */
/*{{{  SDF_Attribute SDF_makeAttributeId(SDF_Layout wsAfterId, SDF_Layout wsAfterParenOpen, SDF_ModuleName moduleName, SDF_Layout wsAfterModuleName) */

SDF_Attribute SDF_makeAttributeId(SDF_Layout wsAfterId, SDF_Layout wsAfterParenOpen, SDF_ModuleName moduleName, SDF_Layout wsAfterModuleName)
{
  return (SDF_Attribute)ATmakeTerm(SDF_patternAttributeId, wsAfterId, wsAfterParenOpen, moduleName, wsAfterModuleName);
}

/*}}}  */
/*{{{  SDF_Attribute SDF_makeAttributeBracket() */

SDF_Attribute SDF_makeAttributeBracket()
{
  return (SDF_Attribute)ATmakeTerm(SDF_patternAttributeBracket);
}

/*}}}  */
/*{{{  SDF_Attribute SDF_makeAttributeAtr(SDF_Associativity associativity) */

SDF_Attribute SDF_makeAttributeAtr(SDF_Associativity associativity)
{
  return (SDF_Attribute)ATmakeTerm(SDF_patternAttributeAtr, associativity);
}

/*}}}  */
/*{{{  SDF_Attribute SDF_makeAttributeCons(SDF_Layout wsAfterCons, SDF_Layout wsAfterParenOpen, SDF_ATerm aTerm, SDF_Layout wsAfterATerm) */

SDF_Attribute SDF_makeAttributeCons(SDF_Layout wsAfterCons, SDF_Layout wsAfterParenOpen, SDF_ATerm aTerm, SDF_Layout wsAfterATerm)
{
  return (SDF_Attribute)ATmakeTerm(SDF_patternAttributeCons, wsAfterCons, wsAfterParenOpen, aTerm, wsAfterATerm);
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
/*{{{  SDF_ImpSection SDF_makeImpSectionImports(SDF_Layout wsAfterImports, SDF_Imports list) */

SDF_ImpSection SDF_makeImpSectionImports(SDF_Layout wsAfterImports, SDF_Imports list)
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
/*{{{  SDF_ImportList SDF_makeImportListMany(SDF_Import head, SDF_Layout wsAfterFirst, SDF_ImportList tail) */

SDF_ImportList SDF_makeImportListMany(SDF_Import head, SDF_Layout wsAfterFirst, SDF_ImportList tail)
{
  return (SDF_ImportList)ATmakeTerm(SDF_patternImportListMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDF_Import SDF_makeImportModule(SDF_ModuleName moduleName) */

SDF_Import SDF_makeImportModule(SDF_ModuleName moduleName)
{
  return (SDF_Import)ATmakeTerm(SDF_patternImportModule, moduleName);
}

/*}}}  */
/*{{{  SDF_Import SDF_makeImportRenamedModule(SDF_ModuleName moduleName, SDF_Layout wsAfterModuleName, SDF_Renamings renamings) */

SDF_Import SDF_makeImportRenamedModule(SDF_ModuleName moduleName, SDF_Layout wsAfterModuleName, SDF_Renamings renamings)
{
  return (SDF_Import)ATmakeTerm(SDF_patternImportRenamedModule, moduleName, wsAfterModuleName, renamings);
}

/*}}}  */
/*{{{  SDF_Import SDF_makeImportBracket(SDF_Layout wsAfterParenOpen, SDF_Import import, SDF_Layout wsAfterImport) */

SDF_Import SDF_makeImportBracket(SDF_Layout wsAfterParenOpen, SDF_Import import, SDF_Layout wsAfterImport)
{
  return (SDF_Import)ATmakeTerm(SDF_patternImportBracket, wsAfterParenOpen, import, wsAfterImport);
}

/*}}}  */
/*{{{  SDF_SymbolTail SDF_makeSymbolTailSingle(SDF_Symbol head) */

SDF_SymbolTail SDF_makeSymbolTailSingle(SDF_Symbol head)
{
  return (SDF_SymbolTail)ATmakeTerm(SDF_patternSymbolTailSingle, head);
}

/*}}}  */
/*{{{  SDF_SymbolTail SDF_makeSymbolTailMany(SDF_Symbol head, SDF_Layout wsAfterFirst, SDF_SymbolTail tail) */

SDF_SymbolTail SDF_makeSymbolTailMany(SDF_Symbol head, SDF_Layout wsAfterFirst, SDF_SymbolTail tail)
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
/*{{{  SDF_Group SDF_makeGroupSimpleGroup(SDF_Production production) */

SDF_Group SDF_makeGroupSimpleGroup(SDF_Production production)
{
  return (SDF_Group)ATmakeTerm(SDF_patternGroupSimpleGroup, production);
}

/*}}}  */
/*{{{  SDF_Group SDF_makeGroupProdsGroup(SDF_Layout wsAfterBraceOpen, SDF_Productions productions, SDF_Layout wsAfterProductions) */

SDF_Group SDF_makeGroupProdsGroup(SDF_Layout wsAfterBraceOpen, SDF_Productions productions, SDF_Layout wsAfterProductions)
{
  return (SDF_Group)ATmakeTerm(SDF_patternGroupProdsGroup, wsAfterBraceOpen, productions, wsAfterProductions);
}

/*}}}  */
/*{{{  SDF_Group SDF_makeGroupAssocGroup(SDF_Layout wsAfterBraceOpen, SDF_Associativity associativity, SDF_Layout wsAfterAssociativity, SDF_Layout wsAfterColon, SDF_Productions productions, SDF_Layout wsAfterProductions) */

SDF_Group SDF_makeGroupAssocGroup(SDF_Layout wsAfterBraceOpen, SDF_Associativity associativity, SDF_Layout wsAfterAssociativity, SDF_Layout wsAfterColon, SDF_Productions productions, SDF_Layout wsAfterProductions)
{
  return (SDF_Group)ATmakeTerm(SDF_patternGroupAssocGroup, wsAfterBraceOpen, associativity, wsAfterAssociativity, wsAfterColon, productions, wsAfterProductions);
}

/*}}}  */
/*{{{  SDF_Priority SDF_makePriorityPriorityChain(SDF_GroupGroupp groupp) */

SDF_Priority SDF_makePriorityPriorityChain(SDF_GroupGroupp groupp)
{
  return (SDF_Priority)ATmakeTerm(SDF_patternPriorityPriorityChain, groupp);
}

/*}}}  */
/*{{{  SDF_Priority SDF_makePriorityPriorityAssoc(SDF_Group left, SDF_Layout wsAfterLeft, SDF_Associativity associativity, SDF_Layout wsAfterAssociativity, SDF_Group right) */

SDF_Priority SDF_makePriorityPriorityAssoc(SDF_Group left, SDF_Layout wsAfterLeft, SDF_Associativity associativity, SDF_Layout wsAfterAssociativity, SDF_Group right)
{
  return (SDF_Priority)ATmakeTerm(SDF_patternPriorityPriorityAssoc, left, wsAfterLeft, associativity, wsAfterAssociativity, right);
}

/*}}}  */
/*{{{  SDF_GroupGroupp SDF_makeGroupGrouppSingle(SDF_Group head) */

SDF_GroupGroupp SDF_makeGroupGrouppSingle(SDF_Group head)
{
  return (SDF_GroupGroupp)ATmakeTerm(SDF_patternGroupGrouppSingle, head);
}

/*}}}  */
/*{{{  SDF_GroupGroupp SDF_makeGroupGrouppMany(SDF_Group head, SDF_Layout wsAfterFirst, SDF_Separator sep, SDF_Layout wsAfterSep, SDF_GroupGroupp tail) */

SDF_GroupGroupp SDF_makeGroupGrouppMany(SDF_Group head, SDF_Layout wsAfterFirst, SDF_Separator sep, SDF_Layout wsAfterSep, SDF_GroupGroupp tail)
{
  return (SDF_GroupGroupp)ATmakeTerm(SDF_patternGroupGrouppMany, head, wsAfterFirst, sep, wsAfterSep, tail);
}

/*}}}  */
/*{{{  SDF_Priorities SDF_makePrioritiesDefault(SDF_PriorityPrioritys prioritys) */

SDF_Priorities SDF_makePrioritiesDefault(SDF_PriorityPrioritys prioritys)
{
  return (SDF_Priorities)ATmakeTerm(SDF_patternPrioritiesDefault, prioritys);
}

/*}}}  */
/*{{{  SDF_PriorityPrioritys SDF_makePriorityPrioritysEmpty() */

SDF_PriorityPrioritys SDF_makePriorityPrioritysEmpty()
{
  return (SDF_PriorityPrioritys)ATmakeTerm(SDF_patternPriorityPrioritysEmpty);
}

/*}}}  */
/*{{{  SDF_PriorityPrioritys SDF_makePriorityPrioritysSingle(SDF_Priority head) */

SDF_PriorityPrioritys SDF_makePriorityPrioritysSingle(SDF_Priority head)
{
  return (SDF_PriorityPrioritys)ATmakeTerm(SDF_patternPriorityPrioritysSingle, head);
}

/*}}}  */
/*{{{  SDF_PriorityPrioritys SDF_makePriorityPrioritysMany(SDF_Priority head, SDF_Layout wsAfterFirst, SDF_Separator sep, SDF_Layout wsAfterSep, SDF_PriorityPrioritys tail) */

SDF_PriorityPrioritys SDF_makePriorityPrioritysMany(SDF_Priority head, SDF_Layout wsAfterFirst, SDF_Separator sep, SDF_Layout wsAfterSep, SDF_PriorityPrioritys tail)
{
  return (SDF_PriorityPrioritys)ATmakeTerm(SDF_patternPriorityPrioritysMany, head, wsAfterFirst, sep, wsAfterSep, tail);
}

/*}}}  */
/*{{{  SDF_Sort SDF_makeSortOneChar(SDF_Lexical lex) */

SDF_Sort SDF_makeSortOneChar(SDF_Lexical lex)
{
  return (SDF_Sort)ATmakeTerm(SDF_patternSortOneChar, lex);
}

/*}}}  */
/*{{{  SDF_Sort SDF_makeSortMoreChars(SDF_Lexical lex) */

SDF_Sort SDF_makeSortMoreChars(SDF_Lexical lex)
{
  return (SDF_Sort)ATmakeTerm(SDF_patternSortMoreChars, lex);
}

/*}}}  */
/*{{{  SDF_UQLiteral SDF_makeUQLiteralOneChar(SDF_Lexical lex) */

SDF_UQLiteral SDF_makeUQLiteralOneChar(SDF_Lexical lex)
{
  return (SDF_UQLiteral)ATmakeTerm(SDF_patternUQLiteralOneChar, lex);
}

/*}}}  */
/*{{{  SDF_UQLiteral SDF_makeUQLiteralMoreChars(SDF_Lexical lex) */

SDF_UQLiteral SDF_makeUQLiteralMoreChars(SDF_Lexical lex)
{
  return (SDF_UQLiteral)ATmakeTerm(SDF_patternUQLiteralMoreChars, lex);
}

/*}}}  */
/*{{{  SDF_Literal SDF_makeLiteralUqlit(SDF_UQLiteral uQLiteral) */

SDF_Literal SDF_makeLiteralUqlit(SDF_UQLiteral uQLiteral)
{
  return (SDF_Literal)ATmakeTerm(SDF_patternLiteralUqlit, uQLiteral);
}

/*}}}  */
/*{{{  SDF_Literal SDF_makeLiteralQuoted(SDF_Lexical lex) */

SDF_Literal SDF_makeLiteralQuoted(SDF_Lexical lex)
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
/*{{{  SDF_SymbolArguments SDF_makeSymbolArgumentsMany(SDF_Symbol head, SDF_Layout wsAfterFirst, SDF_Separator sep, SDF_Layout wsAfterSep, SDF_SymbolArguments tail) */

SDF_SymbolArguments SDF_makeSymbolArgumentsMany(SDF_Symbol head, SDF_Layout wsAfterFirst, SDF_Separator sep, SDF_Layout wsAfterSep, SDF_SymbolArguments tail)
{
  return (SDF_SymbolArguments)ATmakeTerm(SDF_patternSymbolArgumentsMany, head, wsAfterFirst, sep, wsAfterSep, tail);
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_makeLookaheadCharClass(SDF_CharClass charClass) */

SDF_Lookahead SDF_makeLookaheadCharClass(SDF_CharClass charClass)
{
  return (SDF_Lookahead)ATmakeTerm(SDF_patternLookaheadCharClass, charClass);
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_makeLookaheadSeq(SDF_CharClass head, SDF_Layout wsAfterHead, SDF_Layout wsAfterPeriod, SDF_Lookaheads tail) */

SDF_Lookahead SDF_makeLookaheadSeq(SDF_CharClass head, SDF_Layout wsAfterHead, SDF_Layout wsAfterPeriod, SDF_Lookaheads tail)
{
  return (SDF_Lookahead)ATmakeTerm(SDF_patternLookaheadSeq, head, wsAfterHead, wsAfterPeriod, tail);
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_makeLookaheadsSingle(SDF_Lookahead lookahead) */

SDF_Lookaheads SDF_makeLookaheadsSingle(SDF_Lookahead lookahead)
{
  return (SDF_Lookaheads)ATmakeTerm(SDF_patternLookaheadsSingle, lookahead);
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_makeLookaheadsAlt(SDF_Lookaheads left, SDF_Layout wsAfterLeft, SDF_Layout wsAfterBar, SDF_Lookaheads right) */

SDF_Lookaheads SDF_makeLookaheadsAlt(SDF_Lookaheads left, SDF_Layout wsAfterLeft, SDF_Layout wsAfterBar, SDF_Lookaheads right)
{
  return (SDF_Lookaheads)ATmakeTerm(SDF_patternLookaheadsAlt, left, wsAfterLeft, wsAfterBar, right);
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_makeLookaheadsBracket(SDF_Layout wsAfterParenOpen, SDF_Lookaheads lookaheads, SDF_Layout wsAfterLookaheads) */

SDF_Lookaheads SDF_makeLookaheadsBracket(SDF_Layout wsAfterParenOpen, SDF_Lookaheads lookaheads, SDF_Layout wsAfterLookaheads)
{
  return (SDF_Lookaheads)ATmakeTerm(SDF_patternLookaheadsBracket, wsAfterParenOpen, lookaheads, wsAfterLookaheads);
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_makeLookaheadsList(SDF_Layout wsAfterBracketOpenBracketOpen, SDF_Lookaheads lookaheads, SDF_Layout wsAfterLookaheads) */

SDF_Lookaheads SDF_makeLookaheadsList(SDF_Layout wsAfterBracketOpenBracketOpen, SDF_Lookaheads lookaheads, SDF_Layout wsAfterLookaheads)
{
  return (SDF_Lookaheads)ATmakeTerm(SDF_patternLookaheadsList, wsAfterBracketOpenBracketOpen, lookaheads, wsAfterLookaheads);
}

/*}}}  */
/*{{{  SDF_LookaheadLookaheads SDF_makeLookaheadLookaheadsEmpty() */

SDF_LookaheadLookaheads SDF_makeLookaheadLookaheadsEmpty()
{
  return (SDF_LookaheadLookaheads)ATmakeTerm(SDF_patternLookaheadLookaheadsEmpty);
}

/*}}}  */
/*{{{  SDF_LookaheadLookaheads SDF_makeLookaheadLookaheadsSingle(SDF_Lookahead head) */

SDF_LookaheadLookaheads SDF_makeLookaheadLookaheadsSingle(SDF_Lookahead head)
{
  return (SDF_LookaheadLookaheads)ATmakeTerm(SDF_patternLookaheadLookaheadsSingle, head);
}

/*}}}  */
/*{{{  SDF_LookaheadLookaheads SDF_makeLookaheadLookaheadsMany(SDF_Lookahead head, SDF_Layout wsAfterFirst, SDF_Separator sep, SDF_Layout wsAfterSep, SDF_LookaheadLookaheads tail) */

SDF_LookaheadLookaheads SDF_makeLookaheadLookaheadsMany(SDF_Lookahead head, SDF_Layout wsAfterFirst, SDF_Separator sep, SDF_Layout wsAfterSep, SDF_LookaheadLookaheads tail)
{
  return (SDF_LookaheadLookaheads)ATmakeTerm(SDF_patternLookaheadLookaheadsMany, head, wsAfterFirst, sep, wsAfterSep, tail);
}

/*}}}  */
/*{{{  SDF_Restriction SDF_makeRestrictionFollow(SDF_Symbols symbols, SDF_Layout wsAfterSymbols, SDF_Layout wsAfterSlash, SDF_Lookaheads lookaheads) */

SDF_Restriction SDF_makeRestrictionFollow(SDF_Symbols symbols, SDF_Layout wsAfterSymbols, SDF_Layout wsAfterSlash, SDF_Lookaheads lookaheads)
{
  return (SDF_Restriction)ATmakeTerm(SDF_patternRestrictionFollow, symbols, wsAfterSymbols, wsAfterSlash, lookaheads);
}

/*}}}  */
/*{{{  SDF_Restrictions SDF_makeRestrictionsDefault(SDF_RestrictionRestrictions restrictions) */

SDF_Restrictions SDF_makeRestrictionsDefault(SDF_RestrictionRestrictions restrictions)
{
  return (SDF_Restrictions)ATmakeTerm(SDF_patternRestrictionsDefault, restrictions);
}

/*}}}  */
/*{{{  SDF_RestrictionRestrictions SDF_makeRestrictionRestrictionsEmpty() */

SDF_RestrictionRestrictions SDF_makeRestrictionRestrictionsEmpty()
{
  return (SDF_RestrictionRestrictions)ATmakeTerm(SDF_patternRestrictionRestrictionsEmpty);
}

/*}}}  */
/*{{{  SDF_RestrictionRestrictions SDF_makeRestrictionRestrictionsSingle(SDF_Restriction head) */

SDF_RestrictionRestrictions SDF_makeRestrictionRestrictionsSingle(SDF_Restriction head)
{
  return (SDF_RestrictionRestrictions)ATmakeTerm(SDF_patternRestrictionRestrictionsSingle, head);
}

/*}}}  */
/*{{{  SDF_RestrictionRestrictions SDF_makeRestrictionRestrictionsMany(SDF_Restriction head, SDF_Layout wsAfterFirst, SDF_RestrictionRestrictions tail) */

SDF_RestrictionRestrictions SDF_makeRestrictionRestrictionsMany(SDF_Restriction head, SDF_Layout wsAfterFirst, SDF_RestrictionRestrictions tail)
{
  return (SDF_RestrictionRestrictions)ATmakeTerm(SDF_patternRestrictionRestrictionsMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDF_Alias SDF_makeAliasAlias(SDF_Symbol symbol, SDF_Layout wsAfterSymbol, SDF_Layout wsAfterArrow, SDF_Symbol alias) */

SDF_Alias SDF_makeAliasAlias(SDF_Symbol symbol, SDF_Layout wsAfterSymbol, SDF_Layout wsAfterArrow, SDF_Symbol alias)
{
  return (SDF_Alias)ATmakeTerm(SDF_patternAliasAlias, symbol, wsAfterSymbol, wsAfterArrow, alias);
}

/*}}}  */
/*{{{  SDF_Aliases SDF_makeAliasesDefault(SDF_AliasAliass aliass) */

SDF_Aliases SDF_makeAliasesDefault(SDF_AliasAliass aliass)
{
  return (SDF_Aliases)ATmakeTerm(SDF_patternAliasesDefault, aliass);
}

/*}}}  */
/*{{{  SDF_AliasAliass SDF_makeAliasAliassEmpty() */

SDF_AliasAliass SDF_makeAliasAliassEmpty()
{
  return (SDF_AliasAliass)ATmakeTerm(SDF_patternAliasAliassEmpty);
}

/*}}}  */
/*{{{  SDF_AliasAliass SDF_makeAliasAliassSingle(SDF_Alias head) */

SDF_AliasAliass SDF_makeAliasAliassSingle(SDF_Alias head)
{
  return (SDF_AliasAliass)ATmakeTerm(SDF_patternAliasAliassSingle, head);
}

/*}}}  */
/*{{{  SDF_AliasAliass SDF_makeAliasAliassMany(SDF_Alias head, SDF_Layout wsAfterFirst, SDF_AliasAliass tail) */

SDF_AliasAliass SDF_makeAliasAliassMany(SDF_Alias head, SDF_Layout wsAfterFirst, SDF_AliasAliass tail)
{
  return (SDF_AliasAliass)ATmakeTerm(SDF_patternAliasAliassMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDF_Symbols SDF_makeSymbolsDefault(SDF_SymbolSymbols symbols) */

SDF_Symbols SDF_makeSymbolsDefault(SDF_SymbolSymbols symbols)
{
  return (SDF_Symbols)ATmakeTerm(SDF_patternSymbolsDefault, symbols);
}

/*}}}  */
/*{{{  SDF_SymbolSymbols SDF_makeSymbolSymbolsEmpty() */

SDF_SymbolSymbols SDF_makeSymbolSymbolsEmpty()
{
  return (SDF_SymbolSymbols)ATmakeTerm(SDF_patternSymbolSymbolsEmpty);
}

/*}}}  */
/*{{{  SDF_SymbolSymbols SDF_makeSymbolSymbolsSingle(SDF_Symbol head) */

SDF_SymbolSymbols SDF_makeSymbolSymbolsSingle(SDF_Symbol head)
{
  return (SDF_SymbolSymbols)ATmakeTerm(SDF_patternSymbolSymbolsSingle, head);
}

/*}}}  */
/*{{{  SDF_SymbolSymbols SDF_makeSymbolSymbolsMany(SDF_Symbol head, SDF_Layout wsAfterFirst, SDF_SymbolSymbols tail) */

SDF_SymbolSymbols SDF_makeSymbolSymbolsMany(SDF_Symbol head, SDF_Layout wsAfterFirst, SDF_SymbolSymbols tail)
{
  return (SDF_SymbolSymbols)ATmakeTerm(SDF_patternSymbolSymbolsMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDF_Renamings SDF_makeRenamingsRenamings(SDF_Layout wsAfterBracketOpen, SDF_RenamingRenamings renamings, SDF_Layout wsAfterRenamings) */

SDF_Renamings SDF_makeRenamingsRenamings(SDF_Layout wsAfterBracketOpen, SDF_RenamingRenamings renamings, SDF_Layout wsAfterRenamings)
{
  return (SDF_Renamings)ATmakeTerm(SDF_patternRenamingsRenamings, wsAfterBracketOpen, renamings, wsAfterRenamings);
}

/*}}}  */
/*{{{  SDF_RenamingRenamings SDF_makeRenamingRenamingsEmpty() */

SDF_RenamingRenamings SDF_makeRenamingRenamingsEmpty()
{
  return (SDF_RenamingRenamings)ATmakeTerm(SDF_patternRenamingRenamingsEmpty);
}

/*}}}  */
/*{{{  SDF_RenamingRenamings SDF_makeRenamingRenamingsSingle(SDF_Renaming head) */

SDF_RenamingRenamings SDF_makeRenamingRenamingsSingle(SDF_Renaming head)
{
  return (SDF_RenamingRenamings)ATmakeTerm(SDF_patternRenamingRenamingsSingle, head);
}

/*}}}  */
/*{{{  SDF_RenamingRenamings SDF_makeRenamingRenamingsMany(SDF_Renaming head, SDF_Layout wsAfterFirst, SDF_RenamingRenamings tail) */

SDF_RenamingRenamings SDF_makeRenamingRenamingsMany(SDF_Renaming head, SDF_Layout wsAfterFirst, SDF_RenamingRenamings tail)
{
  return (SDF_RenamingRenamings)ATmakeTerm(SDF_patternRenamingRenamingsMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDF_Renaming SDF_makeRenamingSymbol(SDF_Symbol from, SDF_Layout wsAfterFrom, SDF_Layout wsAfterEqualsGreaterThan, SDF_Symbol to) */

SDF_Renaming SDF_makeRenamingSymbol(SDF_Symbol from, SDF_Layout wsAfterFrom, SDF_Layout wsAfterEqualsGreaterThan, SDF_Symbol to)
{
  return (SDF_Renaming)ATmakeTerm(SDF_patternRenamingSymbol, from, wsAfterFrom, wsAfterEqualsGreaterThan, to);
}

/*}}}  */
/*{{{  SDF_Renaming SDF_makeRenamingProduction(SDF_Symbol from, SDF_Layout wsAfterFrom, SDF_Layout wsAfterEqualsGreaterThan, SDF_Symbol to) */

SDF_Renaming SDF_makeRenamingProduction(SDF_Symbol from, SDF_Layout wsAfterFrom, SDF_Layout wsAfterEqualsGreaterThan, SDF_Symbol to)
{
  return (SDF_Renaming)ATmakeTerm(SDF_patternRenamingProduction, from, wsAfterFrom, wsAfterEqualsGreaterThan, to);
}

/*}}}  */
/*{{{  SDF_NatCon SDF_makeNatConDigits(SDF_Lexical lex) */

SDF_NatCon SDF_makeNatConDigits(SDF_Lexical lex)
{
  return (SDF_NatCon)ATmakeTerm(SDF_patternNatConDigits, lex);
}

/*}}}  */
/*{{{  SDF_IntCon SDF_makeIntConNatural(SDF_NatCon natCon) */

SDF_IntCon SDF_makeIntConNatural(SDF_NatCon natCon)
{
  return (SDF_IntCon)ATmakeTerm(SDF_patternIntConNatural, natCon);
}

/*}}}  */
/*{{{  SDF_IntCon SDF_makeIntConPositive(SDF_Layout wsAfterPos, SDF_NatCon natCon) */

SDF_IntCon SDF_makeIntConPositive(SDF_Layout wsAfterPos, SDF_NatCon natCon)
{
  return (SDF_IntCon)ATmakeTerm(SDF_patternIntConPositive, wsAfterPos, natCon);
}

/*}}}  */
/*{{{  SDF_IntCon SDF_makeIntConNegative(SDF_Layout wsAfterNeg, SDF_NatCon natCon) */

SDF_IntCon SDF_makeIntConNegative(SDF_Layout wsAfterNeg, SDF_NatCon natCon)
{
  return (SDF_IntCon)ATmakeTerm(SDF_patternIntConNegative, wsAfterNeg, natCon);
}

/*}}}  */
/*{{{  SDF_CharRange SDF_makeCharRangeDefault(SDF_Character character) */

SDF_CharRange SDF_makeCharRangeDefault(SDF_Character character)
{
  return (SDF_CharRange)ATmakeTerm(SDF_patternCharRangeDefault, character);
}

/*}}}  */
/*{{{  SDF_CharRange SDF_makeCharRangeRange(SDF_Character start, SDF_Layout wsAfterStart, SDF_Layout wsAfter, SDF_Character end) */

SDF_CharRange SDF_makeCharRangeRange(SDF_Character start, SDF_Layout wsAfterStart, SDF_Layout wsAfter, SDF_Character end)
{
  return (SDF_CharRange)ATmakeTerm(SDF_patternCharRangeRange, start, wsAfterStart, wsAfter, end);
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_makeCharRangesDefault(SDF_CharRange charRange) */

SDF_CharRanges SDF_makeCharRangesDefault(SDF_CharRange charRange)
{
  return (SDF_CharRanges)ATmakeTerm(SDF_patternCharRangesDefault, charRange);
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_makeCharRangesConc(SDF_CharRanges left, SDF_Layout wsAfterLeft, SDF_CharRanges right) */

SDF_CharRanges SDF_makeCharRangesConc(SDF_CharRanges left, SDF_Layout wsAfterLeft, SDF_CharRanges right)
{
  return (SDF_CharRanges)ATmakeTerm(SDF_patternCharRangesConc, left, wsAfterLeft, right);
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_makeCharRangesBracket(SDF_Layout wsAfterParenOpen, SDF_CharRanges charRanges, SDF_Layout wsAfterCharRanges) */

SDF_CharRanges SDF_makeCharRangesBracket(SDF_Layout wsAfterParenOpen, SDF_CharRanges charRanges, SDF_Layout wsAfterCharRanges)
{
  return (SDF_CharRanges)ATmakeTerm(SDF_patternCharRangesBracket, wsAfterParenOpen, charRanges, wsAfterCharRanges);
}

/*}}}  */
/*{{{  SDF_OptCharRanges SDF_makeOptCharRangesAbsent() */

SDF_OptCharRanges SDF_makeOptCharRangesAbsent()
{
  return (SDF_OptCharRanges)ATmakeTerm(SDF_patternOptCharRangesAbsent);
}

/*}}}  */
/*{{{  SDF_OptCharRanges SDF_makeOptCharRangesPresent(SDF_CharRanges charRanges) */

SDF_OptCharRanges SDF_makeOptCharRangesPresent(SDF_CharRanges charRanges)
{
  return (SDF_OptCharRanges)ATmakeTerm(SDF_patternOptCharRangesPresent, charRanges);
}

/*}}}  */
/*{{{  SDF_CharClass SDF_makeCharClassSimpleCharclass(SDF_Layout wsAfterBracketOpen, SDF_OptCharRanges optCharRanges, SDF_Layout wsAfterOptCharRanges) */

SDF_CharClass SDF_makeCharClassSimpleCharclass(SDF_Layout wsAfterBracketOpen, SDF_OptCharRanges optCharRanges, SDF_Layout wsAfterOptCharRanges)
{
  return (SDF_CharClass)ATmakeTerm(SDF_patternCharClassSimpleCharclass, wsAfterBracketOpen, optCharRanges, wsAfterOptCharRanges);
}

/*}}}  */
/*{{{  SDF_CharClass SDF_makeCharClassComp(SDF_Layout wsAfterTilde, SDF_CharClass charClass) */

SDF_CharClass SDF_makeCharClassComp(SDF_Layout wsAfterTilde, SDF_CharClass charClass)
{
  return (SDF_CharClass)ATmakeTerm(SDF_patternCharClassComp, wsAfterTilde, charClass);
}

/*}}}  */
/*{{{  SDF_CharClass SDF_makeCharClassDiff(SDF_CharClass left, SDF_Layout wsAfterLeft, SDF_Layout wsAfterSlash, SDF_CharClass right) */

SDF_CharClass SDF_makeCharClassDiff(SDF_CharClass left, SDF_Layout wsAfterLeft, SDF_Layout wsAfterSlash, SDF_CharClass right)
{
  return (SDF_CharClass)ATmakeTerm(SDF_patternCharClassDiff, left, wsAfterLeft, wsAfterSlash, right);
}

/*}}}  */
/*{{{  SDF_CharClass SDF_makeCharClassIsect(SDF_CharClass left, SDF_Layout wsAfterLeft, SDF_Layout wsAfterSlashBackslash, SDF_CharClass right) */

SDF_CharClass SDF_makeCharClassIsect(SDF_CharClass left, SDF_Layout wsAfterLeft, SDF_Layout wsAfterSlashBackslash, SDF_CharClass right)
{
  return (SDF_CharClass)ATmakeTerm(SDF_patternCharClassIsect, left, wsAfterLeft, wsAfterSlashBackslash, right);
}

/*}}}  */
/*{{{  SDF_CharClass SDF_makeCharClassUnion(SDF_CharClass left, SDF_Layout wsAfterLeft, SDF_Layout wsAfterBackslashSlash, SDF_CharClass right) */

SDF_CharClass SDF_makeCharClassUnion(SDF_CharClass left, SDF_Layout wsAfterLeft, SDF_Layout wsAfterBackslashSlash, SDF_CharClass right)
{
  return (SDF_CharClass)ATmakeTerm(SDF_patternCharClassUnion, left, wsAfterLeft, wsAfterBackslashSlash, right);
}

/*}}}  */
/*{{{  SDF_CharClass SDF_makeCharClassBracket(SDF_Layout wsAfterParenOpen, SDF_CharClass charClass, SDF_Layout wsAfterCharClass) */

SDF_CharClass SDF_makeCharClassBracket(SDF_Layout wsAfterParenOpen, SDF_CharClass charClass, SDF_Layout wsAfterCharClass)
{
  return (SDF_CharClass)ATmakeTerm(SDF_patternCharClassBracket, wsAfterParenOpen, charClass, wsAfterCharClass);
}

/*}}}  */
/*{{{  SDF_AlphaNumericalEscChar SDF_makeAlphaNumericalEscCharDefault(SDF_Lexical lex) */

SDF_AlphaNumericalEscChar SDF_makeAlphaNumericalEscCharDefault(SDF_Lexical lex)
{
  return (SDF_AlphaNumericalEscChar)ATmakeTerm(SDF_patternAlphaNumericalEscCharDefault, lex);
}

/*}}}  */
/*{{{  SDF_DecimalEscChar SDF_makeDecimalEscCharDec0_199(SDF_Lexical lex) */

SDF_DecimalEscChar SDF_makeDecimalEscCharDec0_199(SDF_Lexical lex)
{
  return (SDF_DecimalEscChar)ATmakeTerm(SDF_patternDecimalEscCharDec0_199, lex);
}

/*}}}  */
/*{{{  SDF_DecimalEscChar SDF_makeDecimalEscCharDec200_249(SDF_Lexical lex) */

SDF_DecimalEscChar SDF_makeDecimalEscCharDec200_249(SDF_Lexical lex)
{
  return (SDF_DecimalEscChar)ATmakeTerm(SDF_patternDecimalEscCharDec200_249, lex);
}

/*}}}  */
/*{{{  SDF_DecimalEscChar SDF_makeDecimalEscCharDec250_255(SDF_Lexical lex) */

SDF_DecimalEscChar SDF_makeDecimalEscCharDec250_255(SDF_Lexical lex)
{
  return (SDF_DecimalEscChar)ATmakeTerm(SDF_patternDecimalEscCharDec250_255, lex);
}

/*}}}  */
/*{{{  SDF_EscChar SDF_makeEscCharAlphaNumeric(SDF_Lexical lex) */

SDF_EscChar SDF_makeEscCharAlphaNumeric(SDF_Lexical lex)
{
  return (SDF_EscChar)ATmakeTerm(SDF_patternEscCharAlphaNumeric, lex);
}

/*}}}  */
/*{{{  SDF_EscChar SDF_makeEscCharDecimal(SDF_Lexical lex) */

SDF_EscChar SDF_makeEscCharDecimal(SDF_Lexical lex)
{
  return (SDF_EscChar)ATmakeTerm(SDF_patternEscCharDecimal, lex);
}

/*}}}  */
/*{{{  SDF_LChar SDF_makeLCharNormal(SDF_Lexical lex) */

SDF_LChar SDF_makeLCharNormal(SDF_Lexical lex)
{
  return (SDF_LChar)ATmakeTerm(SDF_patternLCharNormal, lex);
}

/*}}}  */
/*{{{  SDF_LChar SDF_makeLCharEscaped(SDF_Lexical lex) */

SDF_LChar SDF_makeLCharEscaped(SDF_Lexical lex)
{
  return (SDF_LChar)ATmakeTerm(SDF_patternLCharEscaped, lex);
}

/*}}}  */
/*{{{  SDF_ATerms SDF_makeATermsAterm(SDF_ATerm aTerm) */

SDF_ATerms SDF_makeATermsAterm(SDF_ATerm aTerm)
{
  return (SDF_ATerms)ATmakeTerm(SDF_patternATermsAterm, aTerm);
}

/*}}}  */
/*{{{  SDF_ATerms SDF_makeATermsCons(SDF_ATerm head, SDF_Layout wsAfterHead, SDF_Layout wsAfterComma, SDF_ATerms tail) */

SDF_ATerms SDF_makeATermsCons(SDF_ATerm head, SDF_Layout wsAfterHead, SDF_Layout wsAfterComma, SDF_ATerms tail)
{
  return (SDF_ATerms)ATmakeTerm(SDF_patternATermsCons, head, wsAfterHead, wsAfterComma, tail);
}

/*}}}  */
/*{{{  SDF_ATermList SDF_makeATermListEmpty(SDF_Layout wsAfterBracketOpen) */

SDF_ATermList SDF_makeATermListEmpty(SDF_Layout wsAfterBracketOpen)
{
  return (SDF_ATermList)ATmakeTerm(SDF_patternATermListEmpty, wsAfterBracketOpen);
}

/*}}}  */
/*{{{  SDF_ATermList SDF_makeATermListNotEmpty(SDF_Layout wsAfterBracketOpen, SDF_ATerms aTerms, SDF_Layout wsAfterATerms) */

SDF_ATermList SDF_makeATermListNotEmpty(SDF_Layout wsAfterBracketOpen, SDF_ATerms aTerms, SDF_Layout wsAfterATerms)
{
  return (SDF_ATermList)ATmakeTerm(SDF_patternATermListNotEmpty, wsAfterBracketOpen, aTerms, wsAfterATerms);
}

/*}}}  */
/*{{{  SDF_ACon SDF_makeAConInt(SDF_IntCon intCon) */

SDF_ACon SDF_makeAConInt(SDF_IntCon intCon)
{
  return (SDF_ACon)ATmakeTerm(SDF_patternAConInt, intCon);
}

/*}}}  */
/*{{{  SDF_ACon SDF_makeAConReal(SDF_RealCon realCon) */

SDF_ACon SDF_makeAConReal(SDF_RealCon realCon)
{
  return (SDF_ACon)ATmakeTerm(SDF_patternAConReal, realCon);
}

/*}}}  */
/*{{{  SDF_AFun SDF_makeAFunDefault(SDF_Literal literal) */

SDF_AFun SDF_makeAFunDefault(SDF_Literal literal)
{
  return (SDF_AFun)ATmakeTerm(SDF_patternAFunDefault, literal);
}

/*}}}  */
/*{{{  SDF_ATerm SDF_makeATermConstant(SDF_ACon aCon) */

SDF_ATerm SDF_makeATermConstant(SDF_ACon aCon)
{
  return (SDF_ATerm)ATmakeTerm(SDF_patternATermConstant, aCon);
}

/*}}}  */
/*{{{  SDF_ATerm SDF_makeATermList(SDF_ATermList aTermList) */

SDF_ATerm SDF_makeATermList(SDF_ATermList aTermList)
{
  return (SDF_ATerm)ATmakeTerm(SDF_patternATermList, aTermList);
}

/*}}}  */
/*{{{  SDF_ATerm SDF_makeATermFun(SDF_AFun aFun) */

SDF_ATerm SDF_makeATermFun(SDF_AFun aFun)
{
  return (SDF_ATerm)ATmakeTerm(SDF_patternATermFun, aFun);
}

/*}}}  */
/*{{{  SDF_ATerm SDF_makeATermAppl(SDF_AFun aFun, SDF_Layout wsAfterAFun, SDF_Layout wsAfterParenOpen, SDF_ATerms args, SDF_Layout wsAfterArgs) */

SDF_ATerm SDF_makeATermAppl(SDF_AFun aFun, SDF_Layout wsAfterAFun, SDF_Layout wsAfterParenOpen, SDF_ATerms args, SDF_Layout wsAfterArgs)
{
  return (SDF_ATerm)ATmakeTerm(SDF_patternATermAppl, aFun, wsAfterAFun, wsAfterParenOpen, args, wsAfterArgs);
}

/*}}}  */
/*{{{  SDF_ATerm SDF_makeATermAnnotatedConstant(SDF_ACon aCon, SDF_Layout wsAfterACon, SDF_Ann ann) */

SDF_ATerm SDF_makeATermAnnotatedConstant(SDF_ACon aCon, SDF_Layout wsAfterACon, SDF_Ann ann)
{
  return (SDF_ATerm)ATmakeTerm(SDF_patternATermAnnotatedConstant, aCon, wsAfterACon, ann);
}

/*}}}  */
/*{{{  SDF_ATerm SDF_makeATermAnnotatedList(SDF_ATermList aTermList, SDF_Layout wsAfterATermList, SDF_Ann ann) */

SDF_ATerm SDF_makeATermAnnotatedList(SDF_ATermList aTermList, SDF_Layout wsAfterATermList, SDF_Ann ann)
{
  return (SDF_ATerm)ATmakeTerm(SDF_patternATermAnnotatedList, aTermList, wsAfterATermList, ann);
}

/*}}}  */
/*{{{  SDF_ATerm SDF_makeATermAnnotatedFun(SDF_AFun aFun, SDF_Layout wsAfterAFun, SDF_Ann ann) */

SDF_ATerm SDF_makeATermAnnotatedFun(SDF_AFun aFun, SDF_Layout wsAfterAFun, SDF_Ann ann)
{
  return (SDF_ATerm)ATmakeTerm(SDF_patternATermAnnotatedFun, aFun, wsAfterAFun, ann);
}

/*}}}  */
/*{{{  SDF_ATerm SDF_makeATermAnnotatedAppl(SDF_AFun aFun, SDF_Layout wsAfterAFun, SDF_Layout wsAfterParenOpen, SDF_ATerms args, SDF_Layout wsAfterArgs, SDF_Layout wsAfterParenClose, SDF_Ann ann) */

SDF_ATerm SDF_makeATermAnnotatedAppl(SDF_AFun aFun, SDF_Layout wsAfterAFun, SDF_Layout wsAfterParenOpen, SDF_ATerms args, SDF_Layout wsAfterArgs, SDF_Layout wsAfterParenClose, SDF_Ann ann)
{
  return (SDF_ATerm)ATmakeTerm(SDF_patternATermAnnotatedAppl, aFun, wsAfterAFun, wsAfterParenOpen, args, wsAfterArgs, wsAfterParenClose, ann);
}

/*}}}  */
/*{{{  SDF_Ann SDF_makeAnnAnnotation(SDF_Layout wsAfterBraceOpen, SDF_ATerms aTerms, SDF_Layout wsAfterATerms) */

SDF_Ann SDF_makeAnnAnnotation(SDF_Layout wsAfterBraceOpen, SDF_ATerms aTerms, SDF_Layout wsAfterATerms)
{
  return (SDF_Ann)ATmakeTerm(SDF_patternAnnAnnotation, wsAfterBraceOpen, aTerms, wsAfterATerms);
}

/*}}}  */
/*{{{  SDF_TagId SDF_makeTagIdDefault(SDF_Lexical lex) */

SDF_TagId SDF_makeTagIdDefault(SDF_Lexical lex)
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
/*{{{  SDF_NumChar SDF_makeNumCharDigits(SDF_Lexical lex) */

SDF_NumChar SDF_makeNumCharDigits(SDF_Lexical lex)
{
  return (SDF_NumChar)ATmakeTerm(SDF_patternNumCharDigits, lex);
}

/*}}}  */
/*{{{  SDF_ShortChar SDF_makeShortCharRegular(SDF_Lexical lex) */

SDF_ShortChar SDF_makeShortCharRegular(SDF_Lexical lex)
{
  return (SDF_ShortChar)ATmakeTerm(SDF_patternShortCharRegular, lex);
}

/*}}}  */
/*{{{  SDF_ShortChar SDF_makeShortCharEscaped(SDF_Lexical lex) */

SDF_ShortChar SDF_makeShortCharEscaped(SDF_Lexical lex)
{
  return (SDF_ShortChar)ATmakeTerm(SDF_patternShortCharEscaped, lex);
}

/*}}}  */
/*{{{  SDF_Character SDF_makeCharacterNumeric(SDF_NumChar numChar) */

SDF_Character SDF_makeCharacterNumeric(SDF_NumChar numChar)
{
  return (SDF_Character)ATmakeTerm(SDF_patternCharacterNumeric, numChar);
}

/*}}}  */
/*{{{  SDF_Character SDF_makeCharacterShort(SDF_ShortChar shortChar) */

SDF_Character SDF_makeCharacterShort(SDF_ShortChar shortChar)
{
  return (SDF_Character)ATmakeTerm(SDF_patternCharacterShort, shortChar);
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
/*{{{  SDF_OptExp SDF_makeOptExpPresent(SDF_Layout wsAfterE, SDF_IntCon intCon) */

SDF_OptExp SDF_makeOptExpPresent(SDF_Layout wsAfterE, SDF_IntCon intCon)
{
  return (SDF_OptExp)ATmakeTerm(SDF_patternOptExpPresent, wsAfterE, intCon);
}

/*}}}  */
/*{{{  SDF_OptExp SDF_makeOptExpAbsent() */

SDF_OptExp SDF_makeOptExpAbsent()
{
  return (SDF_OptExp)ATmakeTerm(SDF_patternOptExpAbsent);
}

/*}}}  */
/*{{{  SDF_RealCon SDF_makeRealConRealCon(SDF_IntCon intCon, SDF_Layout wsAfterIntCon, SDF_Layout wsAfterPeriod, SDF_NatCon natCon, SDF_Layout wsAfterNatCon, SDF_OptExp optExp) */

SDF_RealCon SDF_makeRealConRealCon(SDF_IntCon intCon, SDF_Layout wsAfterIntCon, SDF_Layout wsAfterPeriod, SDF_NatCon natCon, SDF_Layout wsAfterNatCon, SDF_OptExp optExp)
{
  return (SDF_RealCon)ATmakeTerm(SDF_patternRealConRealCon, intCon, wsAfterIntCon, wsAfterPeriod, natCon, wsAfterNatCon, optExp);
}

/*}}}  */

/*{{{  SDF_Symbol accessor implementations */

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
/*{{{  ATbool SDF_hasSymbolWsAfterLessThanLessThan(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterLessThanLessThan(SDF_Symbol arg)
{
  if (SDF_isSymbolPerm(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getSymbolWsAfterLessThanLessThan(SDF_Symbol arg) */

SDF_Layout SDF_getSymbolWsAfterLessThanLessThan(SDF_Symbol arg)
{
  if (SDF_isSymbolPerm(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Symbol has no WsAfterLessThanLessThan: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterLessThanLessThan(SDF_Symbol arg, SDF_Layout wsAfterLessThanLessThan) */

SDF_Symbol SDF_setSymbolWsAfterLessThanLessThan(SDF_Symbol arg, SDF_Layout wsAfterLessThanLessThan)
{
  if (SDF_isSymbolPerm(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLessThanLessThan, 0), 1), 2);
  }

  ATabort("Symbol has no WsAfterLessThanLessThan: %t\n", arg);
  return NULL;
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
  return NULL;
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
  return NULL;
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
/*{{{  SDF_Layout SDF_getSymbolWsAfterLeft(SDF_Symbol arg) */

SDF_Layout SDF_getSymbolWsAfterLeft(SDF_Symbol arg)
{
  if (SDF_isSymbolPair(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isSymbolAlt(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Symbol has no WsAfterLeft: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterLeft(SDF_Symbol arg, SDF_Layout wsAfterLeft) */

SDF_Symbol SDF_setSymbolWsAfterLeft(SDF_Symbol arg, SDF_Layout wsAfterLeft)
{
  if (SDF_isSymbolPair(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLeft, 0), 1), 2);
  }
  else if (SDF_isSymbolAlt(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLeft, 0), 1), 2);
  }

  ATabort("Symbol has no WsAfterLeft: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getSymbolWsAfterParenOpen(SDF_Symbol arg) */

SDF_Layout SDF_getSymbolWsAfterParenOpen(SDF_Symbol arg)
{
  if (SDF_isSymbolEmpty(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isSymbolSeq(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isSymbolFunc(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isSymbolBracket(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Symbol has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterParenOpen(SDF_Symbol arg, SDF_Layout wsAfterParenOpen) */

SDF_Symbol SDF_setSymbolWsAfterParenOpen(SDF_Symbol arg, SDF_Layout wsAfterParenOpen)
{
  if (SDF_isSymbolEmpty(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterParenOpen, 0), 1), 2);
  }
  else if (SDF_isSymbolSeq(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterParenOpen, 0), 1), 2);
  }
  else if (SDF_isSymbolFunc(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterParenOpen, 0), 1), 2);
  }
  else if (SDF_isSymbolBracket(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterParenOpen, 0), 1), 2);
  }

  ATabort("Symbol has no WsAfterParenOpen: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getSymbolWsAfterArguments(SDF_Symbol arg) */

SDF_Layout SDF_getSymbolWsAfterArguments(SDF_Symbol arg)
{
  if (SDF_isSymbolFunc(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Symbol has no WsAfterArguments: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterArguments(SDF_Symbol arg, SDF_Layout wsAfterArguments) */

SDF_Symbol SDF_setSymbolWsAfterArguments(SDF_Symbol arg, SDF_Layout wsAfterArguments)
{
  if (SDF_isSymbolFunc(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterArguments, 0), 3), 2);
  }

  ATabort("Symbol has no WsAfterArguments: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getSymbolWsAfterResults(SDF_Symbol arg) */

SDF_Layout SDF_getSymbolWsAfterResults(SDF_Symbol arg)
{
  if (SDF_isSymbolFunc(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), 0);
  }

  ATabort("Symbol has no WsAfterResults: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterResults(SDF_Symbol arg, SDF_Layout wsAfterResults) */

SDF_Symbol SDF_setSymbolWsAfterResults(SDF_Symbol arg, SDF_Layout wsAfterResults)
{
  if (SDF_isSymbolFunc(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), (ATerm)wsAfterResults, 0), 7), 2);
  }

  ATabort("Symbol has no WsAfterResults: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getSymbolWsAfterHash(SDF_Symbol arg) */

SDF_Layout SDF_getSymbolWsAfterHash(SDF_Symbol arg)
{
  if (SDF_isSymbolPair(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Symbol has no WsAfterHash: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterHash(SDF_Symbol arg, SDF_Layout wsAfterHash) */

SDF_Symbol SDF_setSymbolWsAfterHash(SDF_Symbol arg, SDF_Layout wsAfterHash)
{
  if (SDF_isSymbolPair(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterHash, 0), 3), 2);
  }

  ATabort("Symbol has no WsAfterHash: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getSymbolWsAfterCF(SDF_Symbol arg) */

SDF_Layout SDF_getSymbolWsAfterCF(SDF_Symbol arg)
{
  if (SDF_isSymbolCf(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("Symbol has no WsAfterCF: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterCF(SDF_Symbol arg, SDF_Layout wsAfterCF) */

SDF_Symbol SDF_setSymbolWsAfterCF(SDF_Symbol arg, SDF_Layout wsAfterCF)
{
  if (SDF_isSymbolCf(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterCF, 0), 5), 2);
  }

  ATabort("Symbol has no WsAfterCF: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolSort(SDF_Symbol arg, SDF_Sort sort) */

SDF_Symbol SDF_setSymbolSort(SDF_Symbol arg, SDF_Sort sort)
{
  if (SDF_isSymbolSort(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)sort, 0), 2);
  }

  ATabort("Symbol has no Sort: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getSymbolWsAfterBraceClose(SDF_Symbol arg) */

SDF_Layout SDF_getSymbolWsAfterBraceClose(SDF_Symbol arg)
{
  if (SDF_isSymbolIterSep(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), 0);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), 0);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), 0);
  }

  ATabort("Symbol has no WsAfterBraceClose: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterBraceClose(SDF_Symbol arg, SDF_Layout wsAfterBraceClose) */

SDF_Symbol SDF_setSymbolWsAfterBraceClose(SDF_Symbol arg, SDF_Layout wsAfterBraceClose)
{
  if (SDF_isSymbolIterSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), (ATerm)wsAfterBraceClose, 0), 7), 2);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), (ATerm)wsAfterBraceClose, 0), 7), 2);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), (ATerm)wsAfterBraceClose, 0), 7), 2);
  }

  ATabort("Symbol has no WsAfterBraceClose: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getSymbolWsAfterBar(SDF_Symbol arg) */

SDF_Layout SDF_getSymbolWsAfterBar(SDF_Symbol arg)
{
  if (SDF_isSymbolAlt(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Symbol has no WsAfterBar: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterBar(SDF_Symbol arg, SDF_Layout wsAfterBar) */

SDF_Symbol SDF_setSymbolWsAfterBar(SDF_Symbol arg, SDF_Layout wsAfterBar)
{
  if (SDF_isSymbolAlt(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterBar, 0), 3), 2);
  }

  ATabort("Symbol has no WsAfterBar: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getSymbolWsAfterBraceOpen(SDF_Symbol arg) */

SDF_Layout SDF_getSymbolWsAfterBraceOpen(SDF_Symbol arg)
{
  if (SDF_isSymbolIterSep(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Symbol has no WsAfterBraceOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterBraceOpen(SDF_Symbol arg, SDF_Layout wsAfterBraceOpen) */

SDF_Symbol SDF_setSymbolWsAfterBraceOpen(SDF_Symbol arg, SDF_Layout wsAfterBraceOpen)
{
  if (SDF_isSymbolIterSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterBraceOpen, 0), 1), 2);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterBraceOpen, 0), 1), 2);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterBraceOpen, 0), 1), 2);
  }

  ATabort("Symbol has no WsAfterBraceOpen: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolArguments(SDF_Symbol arg, SDF_Symbols arguments) */

SDF_Symbol SDF_setSymbolArguments(SDF_Symbol arg, SDF_Symbols arguments)
{
  if (SDF_isSymbolFunc(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)arguments, 2), 2);
  }

  ATabort("Symbol has no Arguments: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getSymbolWsAfterSymbols(SDF_Symbol arg) */

SDF_Layout SDF_getSymbolWsAfterSymbols(SDF_Symbol arg)
{
  if (SDF_isSymbolPerm(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Symbol has no WsAfterSymbols: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterSymbols(SDF_Symbol arg, SDF_Layout wsAfterSymbols) */

SDF_Symbol SDF_setSymbolWsAfterSymbols(SDF_Symbol arg, SDF_Layout wsAfterSymbols)
{
  if (SDF_isSymbolPerm(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSymbols, 0), 3), 2);
  }

  ATabort("Symbol has no WsAfterSymbols: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getSymbolWsAfterSep(SDF_Symbol arg) */

SDF_Layout SDF_getSymbolWsAfterSep(SDF_Symbol arg)
{
  if (SDF_isSymbolIterSep(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("Symbol has no WsAfterSep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterSep(SDF_Symbol arg, SDF_Layout wsAfterSep) */

SDF_Symbol SDF_setSymbolWsAfterSep(SDF_Symbol arg, SDF_Layout wsAfterSep)
{
  if (SDF_isSymbolIterSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterSep, 0), 5), 2);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterSep, 0), 5), 2);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterSep, 0), 5), 2);
  }

  ATabort("Symbol has no WsAfterSep: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolTail(SDF_Symbol arg, SDF_SymbolTail tail) */

SDF_Symbol SDF_setSymbolTail(SDF_Symbol arg, SDF_SymbolTail tail)
{
  if (SDF_isSymbolSeq(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4), (ATerm)tail, 2), 4), 2);
  }

  ATabort("Symbol has no Tail: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolHead(SDF_Symbol arg, SDF_Symbol head) */

SDF_Symbol SDF_setSymbolHead(SDF_Symbol arg, SDF_Symbol head)
{
  if (SDF_isSymbolSeq(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)head, 2), 2);
  }

  ATabort("Symbol has no Head: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getSymbolWsAfterSymbol(SDF_Symbol arg) */

SDF_Layout SDF_getSymbolWsAfterSymbol(SDF_Symbol arg)
{
  if (SDF_isSymbolCf(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDF_isSymbolLex(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDF_isSymbolVarsym(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDF_isSymbolOpt(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isSymbolIter(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isSymbolIterStar(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isSymbolIterSep(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDF_isSymbolIterN(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDF_isSymbolSet(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }
  else if (SDF_isSymbolBracket(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Symbol has no WsAfterSymbol: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterSymbol(SDF_Symbol arg, SDF_Layout wsAfterSymbol) */

SDF_Symbol SDF_setSymbolWsAfterSymbol(SDF_Symbol arg, SDF_Layout wsAfterSymbol)
{
  if (SDF_isSymbolCf(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSymbol, 0), 3), 2);
  }
  else if (SDF_isSymbolLex(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSymbol, 0), 3), 2);
  }
  else if (SDF_isSymbolVarsym(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSymbol, 0), 3), 2);
  }
  else if (SDF_isSymbolOpt(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterSymbol, 0), 1), 2);
  }
  else if (SDF_isSymbolIter(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterSymbol, 0), 1), 2);
  }
  else if (SDF_isSymbolIterStar(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterSymbol, 0), 1), 2);
  }
  else if (SDF_isSymbolIterSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSymbol, 0), 3), 2);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSymbol, 0), 3), 2);
  }
  else if (SDF_isSymbolIterN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterSymbol, 0), 1), 2);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSymbol, 0), 3), 2);
  }
  else if (SDF_isSymbolSet(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterSymbol, 0), 5), 2);
  }
  else if (SDF_isSymbolBracket(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSymbol, 0), 3), 2);
  }

  ATabort("Symbol has no WsAfterSymbol: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getSymbolWsAfterN(SDF_Symbol arg) */

SDF_Layout SDF_getSymbolWsAfterN(SDF_Symbol arg)
{
  if (SDF_isSymbolIterN(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 9), 0);
  }

  ATabort("Symbol has no WsAfterN: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterN(SDF_Symbol arg, SDF_Layout wsAfterN) */

SDF_Symbol SDF_setSymbolWsAfterN(SDF_Symbol arg, SDF_Layout wsAfterN)
{
  if (SDF_isSymbolIterN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterN, 0), 3), 2);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 9), (ATerm)wsAfterN, 0), 9), 2);
  }

  ATabort("Symbol has no WsAfterN: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolSymbol(SDF_Symbol arg, SDF_Symbol symbol) */

SDF_Symbol SDF_setSymbolSymbol(SDF_Symbol arg, SDF_Symbol symbol)
{
  if (SDF_isSymbolCf(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 2), 2);
  }
  else if (SDF_isSymbolLex(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 2), 2);
  }
  else if (SDF_isSymbolVarsym(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 2), 2);
  }
  else if (SDF_isSymbolOpt(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 0), 2);
  }
  else if (SDF_isSymbolIter(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 0), 2);
  }
  else if (SDF_isSymbolIterStar(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 0), 2);
  }
  else if (SDF_isSymbolIterSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 2), 2);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 2), 2);
  }
  else if (SDF_isSymbolIterN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 0), 2);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 2), 2);
  }
  else if (SDF_isSymbolSet(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 4), 2);
  }
  else if (SDF_isSymbolLabel(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 4), 2);
  }
  else if (SDF_isSymbolBracket(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 2), 2);
  }

  ATabort("Symbol has no Symbol: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolLiteral(SDF_Symbol arg, SDF_Literal literal) */

SDF_Symbol SDF_setSymbolLiteral(SDF_Symbol arg, SDF_Literal literal)
{
  if (SDF_isSymbolLit(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)literal, 0), 2);
  }

  ATabort("Symbol has no Literal: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolResults(SDF_Symbol arg, SDF_Symbol results) */

SDF_Symbol SDF_setSymbolResults(SDF_Symbol arg, SDF_Symbol results)
{
  if (SDF_isSymbolFunc(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)results, 6), 2);
  }

  ATabort("Symbol has no Results: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolCharClass(SDF_Symbol arg, SDF_CharClass charClass) */

SDF_Symbol SDF_setSymbolCharClass(SDF_Symbol arg, SDF_CharClass charClass)
{
  if (SDF_isSymbolCharClass(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)charClass, 0), 2);
  }

  ATabort("Symbol has no CharClass: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getSymbolWsAfterBracketOpen(SDF_Symbol arg) */

SDF_Layout SDF_getSymbolWsAfterBracketOpen(SDF_Symbol arg)
{
  if (SDF_isSymbolSet(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Symbol has no WsAfterBracketOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterBracketOpen(SDF_Symbol arg, SDF_Layout wsAfterBracketOpen) */

SDF_Symbol SDF_setSymbolWsAfterBracketOpen(SDF_Symbol arg, SDF_Layout wsAfterBracketOpen)
{
  if (SDF_isSymbolSet(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterBracketOpen, 0), 3), 2);
  }

  ATabort("Symbol has no WsAfterBracketOpen: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getSymbolWsAfterTail(SDF_Symbol arg) */

SDF_Layout SDF_getSymbolWsAfterTail(SDF_Symbol arg)
{
  if (SDF_isSymbolSeq(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("Symbol has no WsAfterTail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterTail(SDF_Symbol arg, SDF_Layout wsAfterTail) */

SDF_Symbol SDF_setSymbolWsAfterTail(SDF_Symbol arg, SDF_Layout wsAfterTail)
{
  if (SDF_isSymbolSeq(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterTail, 0), 5), 2);
  }

  ATabort("Symbol has no WsAfterTail: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getSymbolWsAfterHead(SDF_Symbol arg) */

SDF_Layout SDF_getSymbolWsAfterHead(SDF_Symbol arg)
{
  if (SDF_isSymbolSeq(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Symbol has no WsAfterHead: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterHead(SDF_Symbol arg, SDF_Layout wsAfterHead) */

SDF_Symbol SDF_setSymbolWsAfterHead(SDF_Symbol arg, SDF_Layout wsAfterHead)
{
  if (SDF_isSymbolSeq(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterHead, 0), 3), 2);
  }

  ATabort("Symbol has no WsAfterHead: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getSymbolWsAfterEqualsGreaterThan(SDF_Symbol arg) */

SDF_Layout SDF_getSymbolWsAfterEqualsGreaterThan(SDF_Symbol arg)
{
  if (SDF_isSymbolFunc(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("Symbol has no WsAfterEqualsGreaterThan: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterEqualsGreaterThan(SDF_Symbol arg, SDF_Layout wsAfterEqualsGreaterThan) */

SDF_Symbol SDF_setSymbolWsAfterEqualsGreaterThan(SDF_Symbol arg, SDF_Layout wsAfterEqualsGreaterThan)
{
  if (SDF_isSymbolFunc(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterEqualsGreaterThan, 0), 5), 2);
  }

  ATabort("Symbol has no WsAfterEqualsGreaterThan: %t\n", arg);
  return NULL;
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
  return NULL;
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
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolSymbols(SDF_Symbol arg, SDF_Symbols symbols) */

SDF_Symbol SDF_setSymbolSymbols(SDF_Symbol arg, SDF_Symbols symbols)
{
  if (SDF_isSymbolPerm(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbols, 2), 2);
  }

  ATabort("Symbol has no Symbols: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getSymbolWsAfterSet(SDF_Symbol arg) */

SDF_Layout SDF_getSymbolWsAfterSet(SDF_Symbol arg)
{
  if (SDF_isSymbolSet(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Symbol has no WsAfterSet: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterSet(SDF_Symbol arg, SDF_Layout wsAfterSet) */

SDF_Symbol SDF_setSymbolWsAfterSet(SDF_Symbol arg, SDF_Layout wsAfterSet)
{
  if (SDF_isSymbolSet(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterSet, 0), 1), 2);
  }

  ATabort("Symbol has no WsAfterSet: %t\n", arg);
  return NULL;
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
  return NULL;
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
  return NULL;
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
/*{{{  SDF_Layout SDF_getSymbolWsAfterLEX(SDF_Symbol arg) */

SDF_Layout SDF_getSymbolWsAfterLEX(SDF_Symbol arg)
{
  if (SDF_isSymbolLex(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("Symbol has no WsAfterLEX: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterLEX(SDF_Symbol arg, SDF_Layout wsAfterLEX) */

SDF_Symbol SDF_setSymbolWsAfterLEX(SDF_Symbol arg, SDF_Layout wsAfterLEX)
{
  if (SDF_isSymbolLex(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterLEX, 0), 5), 2);
  }

  ATabort("Symbol has no WsAfterLEX: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolLabel(SDF_Symbol arg, SDF_Literal label) */

SDF_Symbol SDF_setSymbolLabel(SDF_Symbol arg, SDF_Literal label)
{
  if (SDF_isSymbolLabel(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)label, 0), 2);
  }

  ATabort("Symbol has no Label: %t\n", arg);
  return NULL;
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
  return NULL;
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
  return NULL;
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
/*{{{  SDF_Layout SDF_getSymbolWsAfterLessThan(SDF_Symbol arg) */

SDF_Layout SDF_getSymbolWsAfterLessThan(SDF_Symbol arg)
{
  if (SDF_isSymbolCf(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isSymbolLex(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isSymbolVarsym(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Symbol has no WsAfterLessThan: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterLessThan(SDF_Symbol arg, SDF_Layout wsAfterLessThan) */

SDF_Symbol SDF_setSymbolWsAfterLessThan(SDF_Symbol arg, SDF_Layout wsAfterLessThan)
{
  if (SDF_isSymbolCf(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLessThan, 0), 1), 2);
  }
  else if (SDF_isSymbolLex(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLessThan, 0), 1), 2);
  }
  else if (SDF_isSymbolVarsym(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLessThan, 0), 1), 2);
  }

  ATabort("Symbol has no WsAfterLessThan: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getSymbolWsAfterColon(SDF_Symbol arg) */

SDF_Layout SDF_getSymbolWsAfterColon(SDF_Symbol arg)
{
  if (SDF_isSymbolLabel(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Symbol has no WsAfterColon: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterColon(SDF_Symbol arg, SDF_Layout wsAfterColon) */

SDF_Symbol SDF_setSymbolWsAfterColon(SDF_Symbol arg, SDF_Layout wsAfterColon)
{
  if (SDF_isSymbolLabel(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterColon, 0), 3), 2);
  }

  ATabort("Symbol has no WsAfterColon: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getSymbolWsAfterLabel(SDF_Symbol arg) */

SDF_Layout SDF_getSymbolWsAfterLabel(SDF_Symbol arg)
{
  if (SDF_isSymbolLabel(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Symbol has no WsAfterLabel: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterLabel(SDF_Symbol arg, SDF_Layout wsAfterLabel) */

SDF_Symbol SDF_setSymbolWsAfterLabel(SDF_Symbol arg, SDF_Layout wsAfterLabel)
{
  if (SDF_isSymbolLabel(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLabel, 0), 1), 2);
  }

  ATabort("Symbol has no WsAfterLabel: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getSymbolWsAfterVAR(SDF_Symbol arg) */

SDF_Layout SDF_getSymbolWsAfterVAR(SDF_Symbol arg)
{
  if (SDF_isSymbolVarsym(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("Symbol has no WsAfterVAR: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterVAR(SDF_Symbol arg, SDF_Layout wsAfterVAR) */

SDF_Symbol SDF_setSymbolWsAfterVAR(SDF_Symbol arg, SDF_Layout wsAfterVAR)
{
  if (SDF_isSymbolVarsym(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterVAR, 0), 5), 2);
  }

  ATabort("Symbol has no WsAfterVAR: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Grammar accessor implementations */

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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarRight(SDF_Grammar arg, SDF_Grammar right) */

SDF_Grammar SDF_setGrammarRight(SDF_Grammar arg, SDF_Grammar right)
{
  if (SDF_isGrammarConcGrammars(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)right, 2), 2);
  }

  ATabort("Grammar has no Right: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getGrammarWsAfterLeft(SDF_Grammar arg) */

SDF_Layout SDF_getGrammarWsAfterLeft(SDF_Grammar arg)
{
  if (SDF_isGrammarConcGrammars(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Grammar has no WsAfterLeft: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterLeft(SDF_Grammar arg, SDF_Layout wsAfterLeft) */

SDF_Grammar SDF_setGrammarWsAfterLeft(SDF_Grammar arg, SDF_Layout wsAfterLeft)
{
  if (SDF_isGrammarConcGrammars(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLeft, 0), 1), 2);
  }

  ATabort("Grammar has no WsAfterLeft: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getGrammarWsAfterParenOpen(SDF_Grammar arg) */

SDF_Layout SDF_getGrammarWsAfterParenOpen(SDF_Grammar arg)
{
  if (SDF_isGrammarBracket(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Grammar has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterParenOpen(SDF_Grammar arg, SDF_Layout wsAfterParenOpen) */

SDF_Grammar SDF_setGrammarWsAfterParenOpen(SDF_Grammar arg, SDF_Layout wsAfterParenOpen)
{
  if (SDF_isGrammarBracket(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterParenOpen, 0), 1), 2);
  }

  ATabort("Grammar has no WsAfterParenOpen: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getGrammarWsAfterSorts(SDF_Grammar arg) */

SDF_Layout SDF_getGrammarWsAfterSorts(SDF_Grammar arg)
{
  if (SDF_isGrammarSorts(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Grammar has no WsAfterSorts: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterSorts(SDF_Grammar arg, SDF_Layout wsAfterSorts) */

SDF_Grammar SDF_setGrammarWsAfterSorts(SDF_Grammar arg, SDF_Layout wsAfterSorts)
{
  if (SDF_isGrammarSorts(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterSorts, 0), 1), 2);
  }

  ATabort("Grammar has no WsAfterSorts: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getGrammarWsAfterPriorities(SDF_Grammar arg) */

SDF_Layout SDF_getGrammarWsAfterPriorities(SDF_Grammar arg)
{
  if (SDF_isGrammarLexicalPriorities(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDF_isGrammarContextFreePriorities(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDF_isGrammarPriorities(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Grammar has no WsAfterPriorities: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterPriorities(SDF_Grammar arg, SDF_Layout wsAfterPriorities) */

SDF_Grammar SDF_setGrammarWsAfterPriorities(SDF_Grammar arg, SDF_Layout wsAfterPriorities)
{
  if (SDF_isGrammarLexicalPriorities(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterPriorities, 0), 3), 2);
  }
  else if (SDF_isGrammarContextFreePriorities(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterPriorities, 0), 3), 2);
  }
  else if (SDF_isGrammarPriorities(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterPriorities, 0), 1), 2);
  }

  ATabort("Grammar has no WsAfterPriorities: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getGrammarWsAfterGrammar(SDF_Grammar arg) */

SDF_Layout SDF_getGrammarWsAfterGrammar(SDF_Grammar arg)
{
  if (SDF_isGrammarBracket(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Grammar has no WsAfterGrammar: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterGrammar(SDF_Grammar arg, SDF_Layout wsAfterGrammar) */

SDF_Grammar SDF_setGrammarWsAfterGrammar(SDF_Grammar arg, SDF_Layout wsAfterGrammar)
{
  if (SDF_isGrammarBracket(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterGrammar, 0), 3), 2);
  }

  ATabort("Grammar has no WsAfterGrammar: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarAliases(SDF_Grammar arg, SDF_Aliases aliases) */

SDF_Grammar SDF_setGrammarAliases(SDF_Grammar arg, SDF_Aliases aliases)
{
  if (SDF_isGrammarAliases(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aliases, 2), 2);
  }

  ATabort("Grammar has no Aliases: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getGrammarWsAfterSyntax(SDF_Grammar arg) */

SDF_Layout SDF_getGrammarWsAfterSyntax(SDF_Grammar arg)
{
  if (SDF_isGrammarSyntax(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isGrammarLexicalSyntax(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDF_isGrammarContextFreeSyntax(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Grammar has no WsAfterSyntax: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterSyntax(SDF_Grammar arg, SDF_Layout wsAfterSyntax) */

SDF_Grammar SDF_setGrammarWsAfterSyntax(SDF_Grammar arg, SDF_Layout wsAfterSyntax)
{
  if (SDF_isGrammarSyntax(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterSyntax, 0), 1), 2);
  }
  else if (SDF_isGrammarLexicalSyntax(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSyntax, 0), 3), 2);
  }
  else if (SDF_isGrammarContextFreeSyntax(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSyntax, 0), 3), 2);
  }

  ATabort("Grammar has no WsAfterSyntax: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarPriorities(SDF_Grammar arg, SDF_Priorities priorities) */

SDF_Grammar SDF_setGrammarPriorities(SDF_Grammar arg, SDF_Priorities priorities)
{
  if (SDF_isGrammarLexicalPriorities(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)priorities, 4), 2);
  }
  else if (SDF_isGrammarContextFreePriorities(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)priorities, 4), 2);
  }
  else if (SDF_isGrammarPriorities(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)priorities, 2), 2);
  }

  ATabort("Grammar has no Priorities: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarRestrictions(SDF_Grammar arg, SDF_Restrictions restrictions) */

SDF_Grammar SDF_setGrammarRestrictions(SDF_Grammar arg, SDF_Restrictions restrictions)
{
  if (SDF_isGrammarLexicalRestrictions(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)restrictions, 4), 2);
  }
  else if (SDF_isGrammarContextFreeRestrictions(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)restrictions, 4), 2);
  }
  else if (SDF_isGrammarRestrictions(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)restrictions, 2), 2);
  }

  ATabort("Grammar has no Restrictions: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getGrammarWsAfterRestrictions(SDF_Grammar arg) */

SDF_Layout SDF_getGrammarWsAfterRestrictions(SDF_Grammar arg)
{
  if (SDF_isGrammarLexicalRestrictions(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDF_isGrammarContextFreeRestrictions(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDF_isGrammarRestrictions(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Grammar has no WsAfterRestrictions: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterRestrictions(SDF_Grammar arg, SDF_Layout wsAfterRestrictions) */

SDF_Grammar SDF_setGrammarWsAfterRestrictions(SDF_Grammar arg, SDF_Layout wsAfterRestrictions)
{
  if (SDF_isGrammarLexicalRestrictions(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterRestrictions, 0), 3), 2);
  }
  else if (SDF_isGrammarContextFreeRestrictions(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterRestrictions, 0), 3), 2);
  }
  else if (SDF_isGrammarRestrictions(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterRestrictions, 0), 1), 2);
  }

  ATabort("Grammar has no WsAfterRestrictions: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarImpSection(SDF_Grammar arg, SDF_ImpSection impSection) */

SDF_Grammar SDF_setGrammarImpSection(SDF_Grammar arg, SDF_ImpSection impSection)
{
  if (SDF_isGrammarImpSection(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)impSection, 0), 2);
  }

  ATabort("Grammar has no ImpSection: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getGrammarWsAfterLexical(SDF_Grammar arg) */

SDF_Layout SDF_getGrammarWsAfterLexical(SDF_Grammar arg)
{
  if (SDF_isGrammarLexicalPriorities(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isGrammarLexicalRestrictions(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isGrammarLexicalSyntax(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isGrammarLexicalVariables(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Grammar has no WsAfterLexical: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterLexical(SDF_Grammar arg, SDF_Layout wsAfterLexical) */

SDF_Grammar SDF_setGrammarWsAfterLexical(SDF_Grammar arg, SDF_Layout wsAfterLexical)
{
  if (SDF_isGrammarLexicalPriorities(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLexical, 0), 1), 2);
  }
  else if (SDF_isGrammarLexicalRestrictions(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLexical, 0), 1), 2);
  }
  else if (SDF_isGrammarLexicalSyntax(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLexical, 0), 1), 2);
  }
  else if (SDF_isGrammarLexicalVariables(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLexical, 0), 1), 2);
  }

  ATabort("Grammar has no WsAfterLexical: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarGrammar(SDF_Grammar arg, SDF_Grammar grammar) */

SDF_Grammar SDF_setGrammarGrammar(SDF_Grammar arg, SDF_Grammar grammar)
{
  if (SDF_isGrammarBracket(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)grammar, 2), 2);
  }

  ATabort("Grammar has no Grammar: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarSymbols(SDF_Grammar arg, SDF_Symbols symbols) */

SDF_Grammar SDF_setGrammarSymbols(SDF_Grammar arg, SDF_Symbols symbols)
{
  if (SDF_isGrammarSorts(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbols, 2), 2);
  }

  ATabort("Grammar has no Symbols: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getGrammarWsAfterVariables(SDF_Grammar arg) */

SDF_Layout SDF_getGrammarWsAfterVariables(SDF_Grammar arg)
{
  if (SDF_isGrammarVariables(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isGrammarLexicalVariables(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Grammar has no WsAfterVariables: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterVariables(SDF_Grammar arg, SDF_Layout wsAfterVariables) */

SDF_Grammar SDF_setGrammarWsAfterVariables(SDF_Grammar arg, SDF_Layout wsAfterVariables)
{
  if (SDF_isGrammarVariables(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterVariables, 0), 1), 2);
  }
  else if (SDF_isGrammarLexicalVariables(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterVariables, 0), 3), 2);
  }

  ATabort("Grammar has no WsAfterVariables: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarLeft(SDF_Grammar arg, SDF_Grammar left) */

SDF_Grammar SDF_setGrammarLeft(SDF_Grammar arg, SDF_Grammar left)
{
  if (SDF_isGrammarConcGrammars(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)left, 0), 2);
  }

  ATabort("Grammar has no Left: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getGrammarWsAfterAliases(SDF_Grammar arg) */

SDF_Layout SDF_getGrammarWsAfterAliases(SDF_Grammar arg)
{
  if (SDF_isGrammarAliases(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Grammar has no WsAfterAliases: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterAliases(SDF_Grammar arg, SDF_Layout wsAfterAliases) */

SDF_Grammar SDF_setGrammarWsAfterAliases(SDF_Grammar arg, SDF_Layout wsAfterAliases)
{
  if (SDF_isGrammarAliases(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterAliases, 0), 1), 2);
  }

  ATabort("Grammar has no WsAfterAliases: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarProductions(SDF_Grammar arg, SDF_Productions productions) */

SDF_Grammar SDF_setGrammarProductions(SDF_Grammar arg, SDF_Productions productions)
{
  if (SDF_isGrammarSyntax(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)productions, 2), 2);
  }
  else if (SDF_isGrammarLexicalSyntax(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)productions, 4), 2);
  }
  else if (SDF_isGrammarContextFreeSyntax(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)productions, 4), 2);
  }
  else if (SDF_isGrammarVariables(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)productions, 2), 2);
  }
  else if (SDF_isGrammarLexicalVariables(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)productions, 4), 2);
  }

  ATabort("Grammar has no Productions: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getGrammarWsAfterContextFree(SDF_Grammar arg) */

SDF_Layout SDF_getGrammarWsAfterContextFree(SDF_Grammar arg)
{
  if (SDF_isGrammarContextFreePriorities(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isGrammarContextFreeRestrictions(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isGrammarContextFreeSyntax(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Grammar has no WsAfterContextFree: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterContextFree(SDF_Grammar arg, SDF_Layout wsAfterContextFree) */

SDF_Grammar SDF_setGrammarWsAfterContextFree(SDF_Grammar arg, SDF_Layout wsAfterContextFree)
{
  if (SDF_isGrammarContextFreePriorities(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterContextFree, 0), 1), 2);
  }
  else if (SDF_isGrammarContextFreeRestrictions(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterContextFree, 0), 1), 2);
  }
  else if (SDF_isGrammarContextFreeSyntax(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterContextFree, 0), 1), 2);
  }

  ATabort("Grammar has no WsAfterContextFree: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_SDF accessor implementations */

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
  return NULL;
}

/*}}}  */
/*{{{  SDF_SDF SDF_setSDFDefinition(SDF_SDF arg, SDF_Definition definition) */

SDF_SDF SDF_setSDFDefinition(SDF_SDF arg, SDF_Definition definition)
{
  if (SDF_isSDFDefinition(arg)) {
    return (SDF_SDF)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)definition, 2), 2);
  }

  ATabort("SDF has no Definition: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getSDFWsAfterDefinition(SDF_SDF arg) */

SDF_Layout SDF_getSDFWsAfterDefinition(SDF_SDF arg)
{
  if (SDF_isSDFDefinition(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("SDF has no WsAfterDefinition: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_SDF SDF_setSDFWsAfterDefinition(SDF_SDF arg, SDF_Layout wsAfterDefinition) */

SDF_SDF SDF_setSDFWsAfterDefinition(SDF_SDF arg, SDF_Layout wsAfterDefinition)
{
  if (SDF_isSDFDefinition(arg)) {
    return (SDF_SDF)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterDefinition, 0), 1), 2);
  }

  ATabort("SDF has no WsAfterDefinition: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Attributes accessor implementations */

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
/*{{{  SDF_Layout SDF_getAttributesWsAfterBraceOpen(SDF_Attributes arg) */

SDF_Layout SDF_getAttributesWsAfterBraceOpen(SDF_Attributes arg)
{
  if (SDF_isAttributesAttrs(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Attributes has no WsAfterBraceOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Attributes SDF_setAttributesWsAfterBraceOpen(SDF_Attributes arg, SDF_Layout wsAfterBraceOpen) */

SDF_Attributes SDF_setAttributesWsAfterBraceOpen(SDF_Attributes arg, SDF_Layout wsAfterBraceOpen)
{
  if (SDF_isAttributesAttrs(arg)) {
    return (SDF_Attributes)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterBraceOpen, 0), 1), 2);
  }

  ATabort("Attributes has no WsAfterBraceOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributesAttributes(SDF_Attributes arg) */

ATbool SDF_hasAttributesAttributes(SDF_Attributes arg)
{
  if (SDF_isAttributesAttrs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_AttributeAttributes SDF_getAttributesAttributes(SDF_Attributes arg) */

SDF_AttributeAttributes SDF_getAttributesAttributes(SDF_Attributes arg)
{
  if (SDF_isAttributesAttrs(arg)) {
    return (SDF_AttributeAttributes)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2), 2);
  }

  ATabort("Attributes has no Attributes: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Attributes SDF_setAttributesAttributes(SDF_Attributes arg, SDF_AttributeAttributes attributes) */

SDF_Attributes SDF_setAttributesAttributes(SDF_Attributes arg, SDF_AttributeAttributes attributes)
{
  if (SDF_isAttributesAttrs(arg)) {
    return (SDF_Attributes)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2), (ATerm)attributes, 2), 2), 2);
  }

  ATabort("Attributes has no Attributes: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributesWsAfterAttributes(SDF_Attributes arg) */

ATbool SDF_hasAttributesWsAfterAttributes(SDF_Attributes arg)
{
  if (SDF_isAttributesAttrs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getAttributesWsAfterAttributes(SDF_Attributes arg) */

SDF_Layout SDF_getAttributesWsAfterAttributes(SDF_Attributes arg)
{
  if (SDF_isAttributesAttrs(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Attributes has no WsAfterAttributes: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Attributes SDF_setAttributesWsAfterAttributes(SDF_Attributes arg, SDF_Layout wsAfterAttributes) */

SDF_Attributes SDF_setAttributesWsAfterAttributes(SDF_Attributes arg, SDF_Layout wsAfterAttributes)
{
  if (SDF_isAttributesAttrs(arg)) {
    return (SDF_Attributes)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterAttributes, 0), 3), 2);
  }

  ATabort("Attributes has no WsAfterAttributes: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_AttributeAttributes accessor implementations */

/*{{{  ATbool SDF_isValidAttributeAttributes(SDF_AttributeAttributes arg) */

ATbool SDF_isValidAttributeAttributes(SDF_AttributeAttributes arg)
{
  if (SDF_isAttributeAttributesEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isAttributeAttributesSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isAttributeAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isAttributeAttributesEmpty(SDF_AttributeAttributes arg) */

ATbool SDF_isAttributeAttributesEmpty(SDF_AttributeAttributes arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAttributeAttributesEmpty);
}

/*}}}  */
/*{{{  ATbool SDF_isAttributeAttributesSingle(SDF_AttributeAttributes arg) */

ATbool SDF_isAttributeAttributesSingle(SDF_AttributeAttributes arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAttributeAttributesSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isAttributeAttributesMany(SDF_AttributeAttributes arg) */

ATbool SDF_isAttributeAttributesMany(SDF_AttributeAttributes arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAttributeAttributesMany, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributeAttributesWsAfterFirst(SDF_AttributeAttributes arg) */

ATbool SDF_hasAttributeAttributesWsAfterFirst(SDF_AttributeAttributes arg)
{
  if (SDF_isAttributeAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getAttributeAttributesWsAfterFirst(SDF_AttributeAttributes arg) */

SDF_Layout SDF_getAttributeAttributesWsAfterFirst(SDF_AttributeAttributes arg)
{
  if (SDF_isAttributeAttributesMany(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("AttributeAttributes has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_AttributeAttributes SDF_setAttributeAttributesWsAfterFirst(SDF_AttributeAttributes arg, SDF_Layout wsAfterFirst) */

SDF_AttributeAttributes SDF_setAttributeAttributesWsAfterFirst(SDF_AttributeAttributes arg, SDF_Layout wsAfterFirst)
{
  if (SDF_isAttributeAttributesMany(arg)) {
    return (SDF_AttributeAttributes)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("AttributeAttributes has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributeAttributesWsAfterSep(SDF_AttributeAttributes arg) */

ATbool SDF_hasAttributeAttributesWsAfterSep(SDF_AttributeAttributes arg)
{
  if (SDF_isAttributeAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getAttributeAttributesWsAfterSep(SDF_AttributeAttributes arg) */

SDF_Layout SDF_getAttributeAttributesWsAfterSep(SDF_AttributeAttributes arg)
{
  if (SDF_isAttributeAttributesMany(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), 0);
  }

  ATabort("AttributeAttributes has no WsAfterSep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_AttributeAttributes SDF_setAttributeAttributesWsAfterSep(SDF_AttributeAttributes arg, SDF_Layout wsAfterSep) */

SDF_AttributeAttributes SDF_setAttributeAttributesWsAfterSep(SDF_AttributeAttributes arg, SDF_Layout wsAfterSep)
{
  if (SDF_isAttributeAttributesMany(arg)) {
    return (SDF_AttributeAttributes)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), (ATerm)wsAfterSep, 0), 3);
  }

  ATabort("AttributeAttributes has no WsAfterSep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributeAttributesTail(SDF_AttributeAttributes arg) */

ATbool SDF_hasAttributeAttributesTail(SDF_AttributeAttributes arg)
{
  if (SDF_isAttributeAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_AttributeAttributes SDF_getAttributeAttributesTail(SDF_AttributeAttributes arg) */

SDF_AttributeAttributes SDF_getAttributeAttributesTail(SDF_AttributeAttributes arg)
{
  if (SDF_isAttributeAttributesMany(arg)) {
    return (SDF_AttributeAttributes)ATgetTail((ATermList)arg, 4);
  }

  ATabort("AttributeAttributes has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_AttributeAttributes SDF_setAttributeAttributesTail(SDF_AttributeAttributes arg, SDF_AttributeAttributes tail) */

SDF_AttributeAttributes SDF_setAttributeAttributesTail(SDF_AttributeAttributes arg, SDF_AttributeAttributes tail)
{
  if (SDF_isAttributeAttributesMany(arg)) {
    return (SDF_AttributeAttributes)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("AttributeAttributes has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributeAttributesHead(SDF_AttributeAttributes arg) */

ATbool SDF_hasAttributeAttributesHead(SDF_AttributeAttributes arg)
{
  if (SDF_isAttributeAttributesSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isAttributeAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Attribute SDF_getAttributeAttributesHead(SDF_AttributeAttributes arg) */

SDF_Attribute SDF_getAttributeAttributesHead(SDF_AttributeAttributes arg)
{
  if (SDF_isAttributeAttributesSingle(arg)) {
    return (SDF_Attribute)ATelementAt((ATermList)arg, 0);
  }
  else if (SDF_isAttributeAttributesMany(arg)) {
    return (SDF_Attribute)ATelementAt((ATermList)arg, 0);
  }

  ATabort("AttributeAttributes has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_AttributeAttributes SDF_setAttributeAttributesHead(SDF_AttributeAttributes arg, SDF_Attribute head) */

SDF_AttributeAttributes SDF_setAttributeAttributesHead(SDF_AttributeAttributes arg, SDF_Attribute head)
{
  if (SDF_isAttributeAttributesSingle(arg)) {
    return (SDF_AttributeAttributes)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isAttributeAttributesMany(arg)) {
    return (SDF_AttributeAttributes)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("AttributeAttributes has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributeAttributesSep(SDF_AttributeAttributes arg) */

ATbool SDF_hasAttributeAttributesSep(SDF_AttributeAttributes arg)
{
  if (SDF_isAttributeAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Separator SDF_getAttributeAttributesSep(SDF_AttributeAttributes arg) */

SDF_Separator SDF_getAttributeAttributesSep(SDF_AttributeAttributes arg)
{
  if (SDF_isAttributeAttributesMany(arg)) {
    return (SDF_Separator)ATelementAt((ATermList)arg, 2);
  }

  ATabort("AttributeAttributes has no Sep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_AttributeAttributes SDF_setAttributeAttributesSep(SDF_AttributeAttributes arg, SDF_Separator sep) */

SDF_AttributeAttributes SDF_setAttributeAttributesSep(SDF_AttributeAttributes arg, SDF_Separator sep)
{
  if (SDF_isAttributeAttributesMany(arg)) {
    return (SDF_AttributeAttributes)ATreplace((ATermList)arg, (ATerm)sep, 2);
  }

  ATabort("AttributeAttributes has no Sep: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Production accessor implementations */

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
/*{{{  SDF_Layout SDF_getProductionWsAfterResult(SDF_Production arg) */

SDF_Layout SDF_getProductionWsAfterResult(SDF_Production arg)
{
  if (SDF_isProductionProd(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }
  else if (SDF_isProductionProdFun(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 11), 0);
  }

  ATabort("Production has no WsAfterResult: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionWsAfterResult(SDF_Production arg, SDF_Layout wsAfterResult) */

SDF_Production SDF_setProductionWsAfterResult(SDF_Production arg, SDF_Layout wsAfterResult)
{
  if (SDF_isProductionProd(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterResult, 0), 5), 2);
  }
  else if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 11), (ATerm)wsAfterResult, 0), 11), 2);
  }

  ATabort("Production has no WsAfterResult: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getProductionWsAfterParenClose(SDF_Production arg) */

SDF_Layout SDF_getProductionWsAfterParenClose(SDF_Production arg)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), 0);
  }

  ATabort("Production has no WsAfterParenClose: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionWsAfterParenClose(SDF_Production arg, SDF_Layout wsAfterParenClose) */

SDF_Production SDF_setProductionWsAfterParenClose(SDF_Production arg, SDF_Layout wsAfterParenClose)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), (ATerm)wsAfterParenClose, 0), 7), 2);
  }

  ATabort("Production has no WsAfterParenClose: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getProductionWsAfterParenOpen(SDF_Production arg) */

SDF_Layout SDF_getProductionWsAfterParenOpen(SDF_Production arg)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Production has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionWsAfterParenOpen(SDF_Production arg, SDF_Layout wsAfterParenOpen) */

SDF_Production SDF_setProductionWsAfterParenOpen(SDF_Production arg, SDF_Layout wsAfterParenOpen)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterParenOpen, 0), 3), 2);
  }

  ATabort("Production has no WsAfterParenOpen: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getProductionWsAfterArguments(SDF_Production arg) */

SDF_Layout SDF_getProductionWsAfterArguments(SDF_Production arg)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("Production has no WsAfterArguments: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionWsAfterArguments(SDF_Production arg, SDF_Layout wsAfterArguments) */

SDF_Production SDF_setProductionWsAfterArguments(SDF_Production arg, SDF_Layout wsAfterArguments)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterArguments, 0), 5), 2);
  }

  ATabort("Production has no WsAfterArguments: %t\n", arg);
  return NULL;
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
  return NULL;
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
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionArguments(SDF_Production arg, SDF_SymbolArguments arguments) */

SDF_Production SDF_setProductionArguments(SDF_Production arg, SDF_SymbolArguments arguments)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4), (ATerm)arguments, 2), 4), 2);
  }

  ATabort("Production has no Arguments: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getProductionWsAfterSymbols(SDF_Production arg) */

SDF_Layout SDF_getProductionWsAfterSymbols(SDF_Production arg)
{
  if (SDF_isProductionProd(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Production has no WsAfterSymbols: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionWsAfterSymbols(SDF_Production arg, SDF_Layout wsAfterSymbols) */

SDF_Production SDF_setProductionWsAfterSymbols(SDF_Production arg, SDF_Layout wsAfterSymbols)
{
  if (SDF_isProductionProd(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterSymbols, 0), 1), 2);
  }

  ATabort("Production has no WsAfterSymbols: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionFunctionSymbol(SDF_Production arg, SDF_Literal functionSymbol) */

SDF_Production SDF_setProductionFunctionSymbol(SDF_Production arg, SDF_Literal functionSymbol)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)functionSymbol, 0), 2);
  }

  ATabort("Production has no FunctionSymbol: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionAttributes(SDF_Production arg, SDF_Attributes attributes) */

SDF_Production SDF_setProductionAttributes(SDF_Production arg, SDF_Attributes attributes)
{
  if (SDF_isProductionProd(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)attributes, 6), 2);
  }
  else if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)attributes, 12), 2);
  }

  ATabort("Production has no Attributes: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getProductionWsAfterGreaterThan(SDF_Production arg) */

SDF_Layout SDF_getProductionWsAfterGreaterThan(SDF_Production arg)
{
  if (SDF_isProductionProd(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDF_isProductionProdFun(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 9), 0);
  }

  ATabort("Production has no WsAfterGreaterThan: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionWsAfterGreaterThan(SDF_Production arg, SDF_Layout wsAfterGreaterThan) */

SDF_Production SDF_setProductionWsAfterGreaterThan(SDF_Production arg, SDF_Layout wsAfterGreaterThan)
{
  if (SDF_isProductionProd(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterGreaterThan, 0), 3), 2);
  }
  else if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 9), (ATerm)wsAfterGreaterThan, 0), 9), 2);
  }

  ATabort("Production has no WsAfterGreaterThan: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionSymbols(SDF_Production arg, SDF_Symbols symbols) */

SDF_Production SDF_setProductionSymbols(SDF_Production arg, SDF_Symbols symbols)
{
  if (SDF_isProductionProd(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbols, 0), 2);
  }

  ATabort("Production has no Symbols: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getProductionWsAfterFunctionSymbol(SDF_Production arg) */

SDF_Layout SDF_getProductionWsAfterFunctionSymbol(SDF_Production arg)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Production has no WsAfterFunctionSymbol: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionWsAfterFunctionSymbol(SDF_Production arg, SDF_Layout wsAfterFunctionSymbol) */

SDF_Production SDF_setProductionWsAfterFunctionSymbol(SDF_Production arg, SDF_Layout wsAfterFunctionSymbol)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterFunctionSymbol, 0), 1), 2);
  }

  ATabort("Production has no WsAfterFunctionSymbol: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Productions accessor implementations */

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
/*{{{  ATbool SDF_hasProductionsProductions(SDF_Productions arg) */

ATbool SDF_hasProductionsProductions(SDF_Productions arg)
{
  if (SDF_isProductionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ProductionProductions SDF_getProductionsProductions(SDF_Productions arg) */

SDF_ProductionProductions SDF_getProductionsProductions(SDF_Productions arg)
{
  if (SDF_isProductionsDefault(arg)) {
    return (SDF_ProductionProductions)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 2);
  }

  ATabort("Productions has no Productions: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Productions SDF_setProductionsProductions(SDF_Productions arg, SDF_ProductionProductions productions) */

SDF_Productions SDF_setProductionsProductions(SDF_Productions arg, SDF_ProductionProductions productions)
{
  if (SDF_isProductionsDefault(arg)) {
    return (SDF_Productions)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)productions, 2), 0), 2);
  }

  ATabort("Productions has no Productions: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ProductionProductions accessor implementations */

/*{{{  ATbool SDF_isValidProductionProductions(SDF_ProductionProductions arg) */

ATbool SDF_isValidProductionProductions(SDF_ProductionProductions arg)
{
  if (SDF_isProductionProductionsEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isProductionProductionsSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isProductionProductionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isProductionProductionsEmpty(SDF_ProductionProductions arg) */

ATbool SDF_isProductionProductionsEmpty(SDF_ProductionProductions arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternProductionProductionsEmpty);
}

/*}}}  */
/*{{{  ATbool SDF_isProductionProductionsSingle(SDF_ProductionProductions arg) */

ATbool SDF_isProductionProductionsSingle(SDF_ProductionProductions arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternProductionProductionsSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isProductionProductionsMany(SDF_ProductionProductions arg) */

ATbool SDF_isProductionProductionsMany(SDF_ProductionProductions arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternProductionProductionsMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasProductionProductionsWsAfterFirst(SDF_ProductionProductions arg) */

ATbool SDF_hasProductionProductionsWsAfterFirst(SDF_ProductionProductions arg)
{
  if (SDF_isProductionProductionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getProductionProductionsWsAfterFirst(SDF_ProductionProductions arg) */

SDF_Layout SDF_getProductionProductionsWsAfterFirst(SDF_ProductionProductions arg)
{
  if (SDF_isProductionProductionsMany(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("ProductionProductions has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ProductionProductions SDF_setProductionProductionsWsAfterFirst(SDF_ProductionProductions arg, SDF_Layout wsAfterFirst) */

SDF_ProductionProductions SDF_setProductionProductionsWsAfterFirst(SDF_ProductionProductions arg, SDF_Layout wsAfterFirst)
{
  if (SDF_isProductionProductionsMany(arg)) {
    return (SDF_ProductionProductions)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("ProductionProductions has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasProductionProductionsTail(SDF_ProductionProductions arg) */

ATbool SDF_hasProductionProductionsTail(SDF_ProductionProductions arg)
{
  if (SDF_isProductionProductionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ProductionProductions SDF_getProductionProductionsTail(SDF_ProductionProductions arg) */

SDF_ProductionProductions SDF_getProductionProductionsTail(SDF_ProductionProductions arg)
{
  if (SDF_isProductionProductionsMany(arg)) {
    return (SDF_ProductionProductions)ATgetTail((ATermList)arg, 2);
  }

  ATabort("ProductionProductions has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ProductionProductions SDF_setProductionProductionsTail(SDF_ProductionProductions arg, SDF_ProductionProductions tail) */

SDF_ProductionProductions SDF_setProductionProductionsTail(SDF_ProductionProductions arg, SDF_ProductionProductions tail)
{
  if (SDF_isProductionProductionsMany(arg)) {
    return (SDF_ProductionProductions)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("ProductionProductions has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasProductionProductionsHead(SDF_ProductionProductions arg) */

ATbool SDF_hasProductionProductionsHead(SDF_ProductionProductions arg)
{
  if (SDF_isProductionProductionsSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isProductionProductionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Production SDF_getProductionProductionsHead(SDF_ProductionProductions arg) */

SDF_Production SDF_getProductionProductionsHead(SDF_ProductionProductions arg)
{
  if (SDF_isProductionProductionsSingle(arg)) {
    return (SDF_Production)ATelementAt((ATermList)arg, 0);
  }
  else if (SDF_isProductionProductionsMany(arg)) {
    return (SDF_Production)ATelementAt((ATermList)arg, 0);
  }

  ATabort("ProductionProductions has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ProductionProductions SDF_setProductionProductionsHead(SDF_ProductionProductions arg, SDF_Production head) */

SDF_ProductionProductions SDF_setProductionProductionsHead(SDF_ProductionProductions arg, SDF_Production head)
{
  if (SDF_isProductionProductionsSingle(arg)) {
    return (SDF_ProductionProductions)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isProductionProductionsMany(arg)) {
    return (SDF_ProductionProductions)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("ProductionProductions has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ModuleWord accessor implementations */

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
/*{{{  SDF_Lexical SDF_getModuleWordLex(SDF_ModuleWord arg) */

SDF_Lexical SDF_getModuleWordLex(SDF_ModuleWord arg)
{
  if (SDF_isModuleWordWord(arg)) {
    return (SDF_Lexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("ModuleWord has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ModuleWord SDF_setModuleWordLex(SDF_ModuleWord arg, SDF_Lexical lex) */

SDF_ModuleWord SDF_setModuleWordLex(SDF_ModuleWord arg, SDF_Lexical lex)
{
  if (SDF_isModuleWordWord(arg)) {
    return (SDF_ModuleWord)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("ModuleWord has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ModuleId accessor implementations */

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
/*{{{  SDF_Lexical SDF_getModuleIdLex(SDF_ModuleId arg) */

SDF_Lexical SDF_getModuleIdLex(SDF_ModuleId arg)
{
  if (SDF_isModuleIdWord(arg)) {
    return (SDF_Lexical)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (SDF_isModuleIdSlashWord(arg)) {
    return (SDF_Lexical)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (SDF_isModuleIdWordSlashWord(arg)) {
    return (SDF_Lexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("ModuleId has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ModuleId SDF_setModuleIdLex(SDF_ModuleId arg, SDF_Lexical lex) */

SDF_ModuleId SDF_setModuleIdLex(SDF_ModuleId arg, SDF_Lexical lex)
{
  if (SDF_isModuleIdWord(arg)) {
    return (SDF_ModuleId)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }
  else if (SDF_isModuleIdSlashWord(arg)) {
    return (SDF_ModuleId)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }
  else if (SDF_isModuleIdWordSlashWord(arg)) {
    return (SDF_ModuleId)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("ModuleId has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Definition accessor implementations */

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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Definition SDF_setDefinitionList(SDF_Definition arg, SDF_ModuleList list) */

SDF_Definition SDF_setDefinitionList(SDF_Definition arg, SDF_ModuleList list)
{
  if (SDF_isDefinitionDefault(arg)) {
    return (SDF_Definition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)list, 2), 0), 2);
  }

  ATabort("Definition has no List: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ModuleList accessor implementations */

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
/*{{{  ATbool SDF_hasModuleListWsAfterFirst(SDF_ModuleList arg) */

ATbool SDF_hasModuleListWsAfterFirst(SDF_ModuleList arg)
{
  if (SDF_isModuleListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getModuleListWsAfterFirst(SDF_ModuleList arg) */

SDF_Layout SDF_getModuleListWsAfterFirst(SDF_ModuleList arg)
{
  if (SDF_isModuleListMany(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("ModuleList has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ModuleList SDF_setModuleListWsAfterFirst(SDF_ModuleList arg, SDF_Layout wsAfterFirst) */

SDF_ModuleList SDF_setModuleListWsAfterFirst(SDF_ModuleList arg, SDF_Layout wsAfterFirst)
{
  if (SDF_isModuleListMany(arg)) {
    return (SDF_ModuleList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("ModuleList has no WsAfterFirst: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_ModuleList SDF_setModuleListTail(SDF_ModuleList arg, SDF_ModuleList tail) */

SDF_ModuleList SDF_setModuleListTail(SDF_ModuleList arg, SDF_ModuleList tail)
{
  if (SDF_isModuleListMany(arg)) {
    return (SDF_ModuleList)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("ModuleList has no Tail: %t\n", arg);
  return NULL;
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
  return NULL;
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
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Module accessor implementations */

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
/*{{{  ATbool SDF_hasModuleWsAfterList(SDF_Module arg) */

ATbool SDF_hasModuleWsAfterList(SDF_Module arg)
{
  if (SDF_isModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getModuleWsAfterList(SDF_Module arg) */

SDF_Layout SDF_getModuleWsAfterList(SDF_Module arg)
{
  if (SDF_isModuleModule(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("Module has no WsAfterList: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Module SDF_setModuleWsAfterList(SDF_Module arg, SDF_Layout wsAfterList) */

SDF_Module SDF_setModuleWsAfterList(SDF_Module arg, SDF_Layout wsAfterList)
{
  if (SDF_isModuleModule(arg)) {
    return (SDF_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterList, 0), 5), 2);
  }

  ATabort("Module has no WsAfterList: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Module SDF_setModuleModuleName(SDF_Module arg, SDF_ModuleName moduleName) */

SDF_Module SDF_setModuleModuleName(SDF_Module arg, SDF_ModuleName moduleName)
{
  if (SDF_isModuleModule(arg)) {
    return (SDF_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)moduleName, 2), 2);
  }

  ATabort("Module has no ModuleName: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getModuleWsAfterModule(SDF_Module arg) */

SDF_Layout SDF_getModuleWsAfterModule(SDF_Module arg)
{
  if (SDF_isModuleModule(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Module has no WsAfterModule: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Module SDF_setModuleWsAfterModule(SDF_Module arg, SDF_Layout wsAfterModule) */

SDF_Module SDF_setModuleWsAfterModule(SDF_Module arg, SDF_Layout wsAfterModule)
{
  if (SDF_isModuleModule(arg)) {
    return (SDF_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterModule, 0), 1), 2);
  }

  ATabort("Module has no WsAfterModule: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Module SDF_setModuleList(SDF_Module arg, SDF_ImpSectionList list) */

SDF_Module SDF_setModuleList(SDF_Module arg, SDF_ImpSectionList list)
{
  if (SDF_isModuleModule(arg)) {
    return (SDF_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4), (ATerm)list, 2), 4), 2);
  }

  ATabort("Module has no List: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getModuleWsAfterModuleName(SDF_Module arg) */

SDF_Layout SDF_getModuleWsAfterModuleName(SDF_Module arg)
{
  if (SDF_isModuleModule(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Module has no WsAfterModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Module SDF_setModuleWsAfterModuleName(SDF_Module arg, SDF_Layout wsAfterModuleName) */

SDF_Module SDF_setModuleWsAfterModuleName(SDF_Module arg, SDF_Layout wsAfterModuleName)
{
  if (SDF_isModuleModule(arg)) {
    return (SDF_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterModuleName, 0), 3), 2);
  }

  ATabort("Module has no WsAfterModuleName: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Module SDF_setModuleSections(SDF_Module arg, SDF_Sections sections) */

SDF_Module SDF_setModuleSections(SDF_Module arg, SDF_Sections sections)
{
  if (SDF_isModuleModule(arg)) {
    return (SDF_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)sections, 6), 2);
  }

  ATabort("Module has no Sections: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ImpSectionList accessor implementations */

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
/*{{{  ATbool SDF_hasImpSectionListWsAfterFirst(SDF_ImpSectionList arg) */

ATbool SDF_hasImpSectionListWsAfterFirst(SDF_ImpSectionList arg)
{
  if (SDF_isImpSectionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getImpSectionListWsAfterFirst(SDF_ImpSectionList arg) */

SDF_Layout SDF_getImpSectionListWsAfterFirst(SDF_ImpSectionList arg)
{
  if (SDF_isImpSectionListMany(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("ImpSectionList has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ImpSectionList SDF_setImpSectionListWsAfterFirst(SDF_ImpSectionList arg, SDF_Layout wsAfterFirst) */

SDF_ImpSectionList SDF_setImpSectionListWsAfterFirst(SDF_ImpSectionList arg, SDF_Layout wsAfterFirst)
{
  if (SDF_isImpSectionListMany(arg)) {
    return (SDF_ImpSectionList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("ImpSectionList has no WsAfterFirst: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_ImpSectionList SDF_setImpSectionListTail(SDF_ImpSectionList arg, SDF_ImpSectionList tail) */

SDF_ImpSectionList SDF_setImpSectionListTail(SDF_ImpSectionList arg, SDF_ImpSectionList tail)
{
  if (SDF_isImpSectionListMany(arg)) {
    return (SDF_ImpSectionList)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("ImpSectionList has no Tail: %t\n", arg);
  return NULL;
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
  return NULL;
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
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Section accessor implementations */

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
/*{{{  SDF_Layout SDF_getSectionWsAfterExports(SDF_Section arg) */

SDF_Layout SDF_getSectionWsAfterExports(SDF_Section arg)
{
  if (SDF_isSectionExports(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Section has no WsAfterExports: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Section SDF_setSectionWsAfterExports(SDF_Section arg, SDF_Layout wsAfterExports) */

SDF_Section SDF_setSectionWsAfterExports(SDF_Section arg, SDF_Layout wsAfterExports)
{
  if (SDF_isSectionExports(arg)) {
    return (SDF_Section)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterExports, 0), 1), 2);
  }

  ATabort("Section has no WsAfterExports: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Section SDF_setSectionGrammar(SDF_Section arg, SDF_Grammar grammar) */

SDF_Section SDF_setSectionGrammar(SDF_Section arg, SDF_Grammar grammar)
{
  if (SDF_isSectionExports(arg)) {
    return (SDF_Section)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)grammar, 2), 2);
  }
  else if (SDF_isSectionHiddens(arg)) {
    return (SDF_Section)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)grammar, 2), 2);
  }

  ATabort("Section has no Grammar: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getSectionWsAfterHiddens(SDF_Section arg) */

SDF_Layout SDF_getSectionWsAfterHiddens(SDF_Section arg)
{
  if (SDF_isSectionHiddens(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Section has no WsAfterHiddens: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Section SDF_setSectionWsAfterHiddens(SDF_Section arg, SDF_Layout wsAfterHiddens) */

SDF_Section SDF_setSectionWsAfterHiddens(SDF_Section arg, SDF_Layout wsAfterHiddens)
{
  if (SDF_isSectionHiddens(arg)) {
    return (SDF_Section)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterHiddens, 0), 1), 2);
  }

  ATabort("Section has no WsAfterHiddens: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Sections accessor implementations */

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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Sections SDF_setSectionsList(SDF_Sections arg, SDF_SectionList list) */

SDF_Sections SDF_setSectionsList(SDF_Sections arg, SDF_SectionList list)
{
  if (SDF_isSectionsDefault(arg)) {
    return (SDF_Sections)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)list, 2), 0), 2);
  }

  ATabort("Sections has no List: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_SectionList accessor implementations */

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
/*{{{  ATbool SDF_hasSectionListWsAfterFirst(SDF_SectionList arg) */

ATbool SDF_hasSectionListWsAfterFirst(SDF_SectionList arg)
{
  if (SDF_isSectionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getSectionListWsAfterFirst(SDF_SectionList arg) */

SDF_Layout SDF_getSectionListWsAfterFirst(SDF_SectionList arg)
{
  if (SDF_isSectionListMany(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("SectionList has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_SectionList SDF_setSectionListWsAfterFirst(SDF_SectionList arg, SDF_Layout wsAfterFirst) */

SDF_SectionList SDF_setSectionListWsAfterFirst(SDF_SectionList arg, SDF_Layout wsAfterFirst)
{
  if (SDF_isSectionListMany(arg)) {
    return (SDF_SectionList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("SectionList has no WsAfterFirst: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_SectionList SDF_setSectionListTail(SDF_SectionList arg, SDF_SectionList tail) */

SDF_SectionList SDF_setSectionListTail(SDF_SectionList arg, SDF_SectionList tail)
{
  if (SDF_isSectionListMany(arg)) {
    return (SDF_SectionList)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("SectionList has no Tail: %t\n", arg);
  return NULL;
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
  return NULL;
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
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ModuleName accessor implementations */

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
  return NULL;
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_setModuleNameParams(SDF_ModuleName arg, SDF_Symbols params) */

SDF_ModuleName SDF_setModuleNameParams(SDF_ModuleName arg, SDF_Symbols params)
{
  if (SDF_isModuleNameParameterized(arg)) {
    return (SDF_ModuleName)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)params, 4), 2);
  }

  ATabort("ModuleName has no Params: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getModuleNameWsAfterModuleId(SDF_ModuleName arg) */

SDF_Layout SDF_getModuleNameWsAfterModuleId(SDF_ModuleName arg)
{
  if (SDF_isModuleNameParameterized(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("ModuleName has no WsAfterModuleId: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_setModuleNameWsAfterModuleId(SDF_ModuleName arg, SDF_Layout wsAfterModuleId) */

SDF_ModuleName SDF_setModuleNameWsAfterModuleId(SDF_ModuleName arg, SDF_Layout wsAfterModuleId)
{
  if (SDF_isModuleNameParameterized(arg)) {
    return (SDF_ModuleName)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterModuleId, 0), 1), 2);
  }

  ATabort("ModuleName has no WsAfterModuleId: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_setModuleNameModuleId(SDF_ModuleName arg, SDF_ModuleId moduleId) */

SDF_ModuleName SDF_setModuleNameModuleId(SDF_ModuleName arg, SDF_ModuleId moduleId)
{
  if (SDF_isModuleNameUnparameterized(arg)) {
    return (SDF_ModuleName)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)moduleId, 0), 2);
  }
  else if (SDF_isModuleNameParameterized(arg)) {
    return (SDF_ModuleName)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)moduleId, 0), 2);
  }

  ATabort("ModuleName has no ModuleId: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getModuleNameWsAfterBracketOpen(SDF_ModuleName arg) */

SDF_Layout SDF_getModuleNameWsAfterBracketOpen(SDF_ModuleName arg)
{
  if (SDF_isModuleNameParameterized(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("ModuleName has no WsAfterBracketOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_setModuleNameWsAfterBracketOpen(SDF_ModuleName arg, SDF_Layout wsAfterBracketOpen) */

SDF_ModuleName SDF_setModuleNameWsAfterBracketOpen(SDF_ModuleName arg, SDF_Layout wsAfterBracketOpen)
{
  if (SDF_isModuleNameParameterized(arg)) {
    return (SDF_ModuleName)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterBracketOpen, 0), 3), 2);
  }

  ATabort("ModuleName has no WsAfterBracketOpen: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getModuleNameWsAfterParams(SDF_ModuleName arg) */

SDF_Layout SDF_getModuleNameWsAfterParams(SDF_ModuleName arg)
{
  if (SDF_isModuleNameParameterized(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("ModuleName has no WsAfterParams: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_setModuleNameWsAfterParams(SDF_ModuleName arg, SDF_Layout wsAfterParams) */

SDF_ModuleName SDF_setModuleNameWsAfterParams(SDF_ModuleName arg, SDF_Layout wsAfterParams)
{
  if (SDF_isModuleNameParameterized(arg)) {
    return (SDF_ModuleName)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterParams, 0), 5), 2);
  }

  ATabort("ModuleName has no WsAfterParams: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Attribute accessor implementations */

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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Attribute SDF_setAttributeModuleName(SDF_Attribute arg, SDF_ModuleName moduleName) */

SDF_Attribute SDF_setAttributeModuleName(SDF_Attribute arg, SDF_ModuleName moduleName)
{
  if (SDF_isAttributeId(arg)) {
    return (SDF_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)moduleName, 4), 2);
  }

  ATabort("Attribute has no ModuleName: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getAttributeWsAfterParenOpen(SDF_Attribute arg) */

SDF_Layout SDF_getAttributeWsAfterParenOpen(SDF_Attribute arg)
{
  if (SDF_isAttributeId(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDF_isAttributeCons(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Attribute has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Attribute SDF_setAttributeWsAfterParenOpen(SDF_Attribute arg, SDF_Layout wsAfterParenOpen) */

SDF_Attribute SDF_setAttributeWsAfterParenOpen(SDF_Attribute arg, SDF_Layout wsAfterParenOpen)
{
  if (SDF_isAttributeId(arg)) {
    return (SDF_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterParenOpen, 0), 3), 2);
  }
  else if (SDF_isAttributeCons(arg)) {
    return (SDF_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterParenOpen, 0), 3), 2);
  }

  ATabort("Attribute has no WsAfterParenOpen: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getAttributeWsAfterCons(SDF_Attribute arg) */

SDF_Layout SDF_getAttributeWsAfterCons(SDF_Attribute arg)
{
  if (SDF_isAttributeCons(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Attribute has no WsAfterCons: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Attribute SDF_setAttributeWsAfterCons(SDF_Attribute arg, SDF_Layout wsAfterCons) */

SDF_Attribute SDF_setAttributeWsAfterCons(SDF_Attribute arg, SDF_Layout wsAfterCons)
{
  if (SDF_isAttributeCons(arg)) {
    return (SDF_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterCons, 0), 1), 2);
  }

  ATabort("Attribute has no WsAfterCons: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributeATerm(SDF_Attribute arg) */

ATbool SDF_hasAttributeATerm(SDF_Attribute arg)
{
  if (SDF_isAttributeCons(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_getAttributeATerm(SDF_Attribute arg) */

SDF_ATerm SDF_getAttributeATerm(SDF_Attribute arg)
{
  if (SDF_isAttributeCons(arg)) {
    return (SDF_ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Attribute has no ATerm: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Attribute SDF_setAttributeATerm(SDF_Attribute arg, SDF_ATerm aTerm) */

SDF_Attribute SDF_setAttributeATerm(SDF_Attribute arg, SDF_ATerm aTerm)
{
  if (SDF_isAttributeCons(arg)) {
    return (SDF_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aTerm, 4), 2);
  }

  ATabort("Attribute has no ATerm: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributeWsAfterATerm(SDF_Attribute arg) */

ATbool SDF_hasAttributeWsAfterATerm(SDF_Attribute arg)
{
  if (SDF_isAttributeCons(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getAttributeWsAfterATerm(SDF_Attribute arg) */

SDF_Layout SDF_getAttributeWsAfterATerm(SDF_Attribute arg)
{
  if (SDF_isAttributeCons(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("Attribute has no WsAfterATerm: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Attribute SDF_setAttributeWsAfterATerm(SDF_Attribute arg, SDF_Layout wsAfterATerm) */

SDF_Attribute SDF_setAttributeWsAfterATerm(SDF_Attribute arg, SDF_Layout wsAfterATerm)
{
  if (SDF_isAttributeCons(arg)) {
    return (SDF_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterATerm, 0), 5), 2);
  }

  ATabort("Attribute has no WsAfterATerm: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Attribute SDF_setAttributeAssociativity(SDF_Attribute arg, SDF_Associativity associativity) */

SDF_Attribute SDF_setAttributeAssociativity(SDF_Attribute arg, SDF_Associativity associativity)
{
  if (SDF_isAttributeAtr(arg)) {
    return (SDF_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)associativity, 0), 2);
  }

  ATabort("Attribute has no Associativity: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getAttributeWsAfterId(SDF_Attribute arg) */

SDF_Layout SDF_getAttributeWsAfterId(SDF_Attribute arg)
{
  if (SDF_isAttributeId(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Attribute has no WsAfterId: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Attribute SDF_setAttributeWsAfterId(SDF_Attribute arg, SDF_Layout wsAfterId) */

SDF_Attribute SDF_setAttributeWsAfterId(SDF_Attribute arg, SDF_Layout wsAfterId)
{
  if (SDF_isAttributeId(arg)) {
    return (SDF_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterId, 0), 1), 2);
  }

  ATabort("Attribute has no WsAfterId: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getAttributeWsAfterModuleName(SDF_Attribute arg) */

SDF_Layout SDF_getAttributeWsAfterModuleName(SDF_Attribute arg)
{
  if (SDF_isAttributeId(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("Attribute has no WsAfterModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Attribute SDF_setAttributeWsAfterModuleName(SDF_Attribute arg, SDF_Layout wsAfterModuleName) */

SDF_Attribute SDF_setAttributeWsAfterModuleName(SDF_Attribute arg, SDF_Layout wsAfterModuleName)
{
  if (SDF_isAttributeId(arg)) {
    return (SDF_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterModuleName, 0), 5), 2);
  }

  ATabort("Attribute has no WsAfterModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ImpSection accessor implementations */

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
/*{{{  SDF_Layout SDF_getImpSectionWsAfterImports(SDF_ImpSection arg) */

SDF_Layout SDF_getImpSectionWsAfterImports(SDF_ImpSection arg)
{
  if (SDF_isImpSectionImports(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("ImpSection has no WsAfterImports: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ImpSection SDF_setImpSectionWsAfterImports(SDF_ImpSection arg, SDF_Layout wsAfterImports) */

SDF_ImpSection SDF_setImpSectionWsAfterImports(SDF_ImpSection arg, SDF_Layout wsAfterImports)
{
  if (SDF_isImpSectionImports(arg)) {
    return (SDF_ImpSection)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterImports, 0), 1), 2);
  }

  ATabort("ImpSection has no WsAfterImports: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_ImpSection SDF_setImpSectionList(SDF_ImpSection arg, SDF_Imports list) */

SDF_ImpSection SDF_setImpSectionList(SDF_ImpSection arg, SDF_Imports list)
{
  if (SDF_isImpSectionImports(arg)) {
    return (SDF_ImpSection)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)list, 2), 2);
  }

  ATabort("ImpSection has no List: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Imports accessor implementations */

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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Imports SDF_setImportsList(SDF_Imports arg, SDF_ImportList list) */

SDF_Imports SDF_setImportsList(SDF_Imports arg, SDF_ImportList list)
{
  if (SDF_isImportsDefault(arg)) {
    return (SDF_Imports)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)list, 2), 0), 2);
  }

  ATabort("Imports has no List: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ImportList accessor implementations */

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
/*{{{  ATbool SDF_hasImportListWsAfterFirst(SDF_ImportList arg) */

ATbool SDF_hasImportListWsAfterFirst(SDF_ImportList arg)
{
  if (SDF_isImportListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getImportListWsAfterFirst(SDF_ImportList arg) */

SDF_Layout SDF_getImportListWsAfterFirst(SDF_ImportList arg)
{
  if (SDF_isImportListMany(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("ImportList has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ImportList SDF_setImportListWsAfterFirst(SDF_ImportList arg, SDF_Layout wsAfterFirst) */

SDF_ImportList SDF_setImportListWsAfterFirst(SDF_ImportList arg, SDF_Layout wsAfterFirst)
{
  if (SDF_isImportListMany(arg)) {
    return (SDF_ImportList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("ImportList has no WsAfterFirst: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_ImportList SDF_setImportListTail(SDF_ImportList arg, SDF_ImportList tail) */

SDF_ImportList SDF_setImportListTail(SDF_ImportList arg, SDF_ImportList tail)
{
  if (SDF_isImportListMany(arg)) {
    return (SDF_ImportList)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("ImportList has no Tail: %t\n", arg);
  return NULL;
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
  return NULL;
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
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Import accessor implementations */

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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Import SDF_setImportModuleName(SDF_Import arg, SDF_ModuleName moduleName) */

SDF_Import SDF_setImportModuleName(SDF_Import arg, SDF_ModuleName moduleName)
{
  if (SDF_isImportModule(arg)) {
    return (SDF_Import)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)moduleName, 0), 2);
  }
  else if (SDF_isImportRenamedModule(arg)) {
    return (SDF_Import)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)moduleName, 0), 2);
  }

  ATabort("Import has no ModuleName: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getImportWsAfterParenOpen(SDF_Import arg) */

SDF_Layout SDF_getImportWsAfterParenOpen(SDF_Import arg)
{
  if (SDF_isImportBracket(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Import has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Import SDF_setImportWsAfterParenOpen(SDF_Import arg, SDF_Layout wsAfterParenOpen) */

SDF_Import SDF_setImportWsAfterParenOpen(SDF_Import arg, SDF_Layout wsAfterParenOpen)
{
  if (SDF_isImportBracket(arg)) {
    return (SDF_Import)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterParenOpen, 0), 1), 2);
  }

  ATabort("Import has no WsAfterParenOpen: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Import SDF_setImportRenamings(SDF_Import arg, SDF_Renamings renamings) */

SDF_Import SDF_setImportRenamings(SDF_Import arg, SDF_Renamings renamings)
{
  if (SDF_isImportRenamedModule(arg)) {
    return (SDF_Import)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)renamings, 2), 2);
  }

  ATabort("Import has no Renamings: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getImportWsAfterImport(SDF_Import arg) */

SDF_Layout SDF_getImportWsAfterImport(SDF_Import arg)
{
  if (SDF_isImportBracket(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Import has no WsAfterImport: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Import SDF_setImportWsAfterImport(SDF_Import arg, SDF_Layout wsAfterImport) */

SDF_Import SDF_setImportWsAfterImport(SDF_Import arg, SDF_Layout wsAfterImport)
{
  if (SDF_isImportBracket(arg)) {
    return (SDF_Import)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterImport, 0), 3), 2);
  }

  ATabort("Import has no WsAfterImport: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Import SDF_setImportImport(SDF_Import arg, SDF_Import import) */

SDF_Import SDF_setImportImport(SDF_Import arg, SDF_Import import)
{
  if (SDF_isImportBracket(arg)) {
    return (SDF_Import)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)import, 2), 2);
  }

  ATabort("Import has no Import: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getImportWsAfterModuleName(SDF_Import arg) */

SDF_Layout SDF_getImportWsAfterModuleName(SDF_Import arg)
{
  if (SDF_isImportRenamedModule(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Import has no WsAfterModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Import SDF_setImportWsAfterModuleName(SDF_Import arg, SDF_Layout wsAfterModuleName) */

SDF_Import SDF_setImportWsAfterModuleName(SDF_Import arg, SDF_Layout wsAfterModuleName)
{
  if (SDF_isImportRenamedModule(arg)) {
    return (SDF_Import)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterModuleName, 0), 1), 2);
  }

  ATabort("Import has no WsAfterModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_SymbolTail accessor implementations */

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
/*{{{  ATbool SDF_hasSymbolTailWsAfterFirst(SDF_SymbolTail arg) */

ATbool SDF_hasSymbolTailWsAfterFirst(SDF_SymbolTail arg)
{
  if (SDF_isSymbolTailMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getSymbolTailWsAfterFirst(SDF_SymbolTail arg) */

SDF_Layout SDF_getSymbolTailWsAfterFirst(SDF_SymbolTail arg)
{
  if (SDF_isSymbolTailMany(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("SymbolTail has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_SymbolTail SDF_setSymbolTailWsAfterFirst(SDF_SymbolTail arg, SDF_Layout wsAfterFirst) */

SDF_SymbolTail SDF_setSymbolTailWsAfterFirst(SDF_SymbolTail arg, SDF_Layout wsAfterFirst)
{
  if (SDF_isSymbolTailMany(arg)) {
    return (SDF_SymbolTail)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("SymbolTail has no WsAfterFirst: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_SymbolTail SDF_setSymbolTailTail(SDF_SymbolTail arg, SDF_SymbolTail tail) */

SDF_SymbolTail SDF_setSymbolTailTail(SDF_SymbolTail arg, SDF_SymbolTail tail)
{
  if (SDF_isSymbolTailMany(arg)) {
    return (SDF_SymbolTail)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("SymbolTail has no Tail: %t\n", arg);
  return NULL;
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
  return NULL;
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
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Associativity accessor implementations */

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
/*{{{  SDF_Group accessor implementations */

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
/*{{{  ATbool SDF_hasGroupWsAfterAssociativity(SDF_Group arg) */

ATbool SDF_hasGroupWsAfterAssociativity(SDF_Group arg)
{
  if (SDF_isGroupAssocGroup(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getGroupWsAfterAssociativity(SDF_Group arg) */

SDF_Layout SDF_getGroupWsAfterAssociativity(SDF_Group arg)
{
  if (SDF_isGroupAssocGroup(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Group has no WsAfterAssociativity: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Group SDF_setGroupWsAfterAssociativity(SDF_Group arg, SDF_Layout wsAfterAssociativity) */

SDF_Group SDF_setGroupWsAfterAssociativity(SDF_Group arg, SDF_Layout wsAfterAssociativity)
{
  if (SDF_isGroupAssocGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterAssociativity, 0), 3), 2);
  }

  ATabort("Group has no WsAfterAssociativity: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getGroupWsAfterBraceOpen(SDF_Group arg) */

SDF_Layout SDF_getGroupWsAfterBraceOpen(SDF_Group arg)
{
  if (SDF_isGroupProdsGroup(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isGroupAssocGroup(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Group has no WsAfterBraceOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Group SDF_setGroupWsAfterBraceOpen(SDF_Group arg, SDF_Layout wsAfterBraceOpen) */

SDF_Group SDF_setGroupWsAfterBraceOpen(SDF_Group arg, SDF_Layout wsAfterBraceOpen)
{
  if (SDF_isGroupProdsGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterBraceOpen, 0), 1), 2);
  }
  else if (SDF_isGroupAssocGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterBraceOpen, 0), 1), 2);
  }

  ATabort("Group has no WsAfterBraceOpen: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Group SDF_setGroupProduction(SDF_Group arg, SDF_Production production) */

SDF_Group SDF_setGroupProduction(SDF_Group arg, SDF_Production production)
{
  if (SDF_isGroupSimpleGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)production, 0), 2);
  }

  ATabort("Group has no Production: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Group SDF_setGroupAssociativity(SDF_Group arg, SDF_Associativity associativity) */

SDF_Group SDF_setGroupAssociativity(SDF_Group arg, SDF_Associativity associativity)
{
  if (SDF_isGroupAssocGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)associativity, 2), 2);
  }

  ATabort("Group has no Associativity: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Group SDF_setGroupProductions(SDF_Group arg, SDF_Productions productions) */

SDF_Group SDF_setGroupProductions(SDF_Group arg, SDF_Productions productions)
{
  if (SDF_isGroupProdsGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)productions, 2), 2);
  }
  else if (SDF_isGroupAssocGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)productions, 6), 2);
  }

  ATabort("Group has no Productions: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getGroupWsAfterProductions(SDF_Group arg) */

SDF_Layout SDF_getGroupWsAfterProductions(SDF_Group arg)
{
  if (SDF_isGroupProdsGroup(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDF_isGroupAssocGroup(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), 0);
  }

  ATabort("Group has no WsAfterProductions: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Group SDF_setGroupWsAfterProductions(SDF_Group arg, SDF_Layout wsAfterProductions) */

SDF_Group SDF_setGroupWsAfterProductions(SDF_Group arg, SDF_Layout wsAfterProductions)
{
  if (SDF_isGroupProdsGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterProductions, 0), 3), 2);
  }
  else if (SDF_isGroupAssocGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), (ATerm)wsAfterProductions, 0), 7), 2);
  }

  ATabort("Group has no WsAfterProductions: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getGroupWsAfterColon(SDF_Group arg) */

SDF_Layout SDF_getGroupWsAfterColon(SDF_Group arg)
{
  if (SDF_isGroupAssocGroup(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("Group has no WsAfterColon: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Group SDF_setGroupWsAfterColon(SDF_Group arg, SDF_Layout wsAfterColon) */

SDF_Group SDF_setGroupWsAfterColon(SDF_Group arg, SDF_Layout wsAfterColon)
{
  if (SDF_isGroupAssocGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterColon, 0), 5), 2);
  }

  ATabort("Group has no WsAfterColon: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Priority accessor implementations */

/*{{{  ATbool SDF_isValidPriority(SDF_Priority arg) */

ATbool SDF_isValidPriority(SDF_Priority arg)
{
  if (SDF_isPriorityPriorityChain(arg)) {
    return ATtrue;
  }
  else if (SDF_isPriorityPriorityAssoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isPriorityPriorityChain(SDF_Priority arg) */

ATbool SDF_isPriorityPriorityChain(SDF_Priority arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternPriorityPriorityChain, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isPriorityPriorityAssoc(SDF_Priority arg) */

ATbool SDF_isPriorityPriorityAssoc(SDF_Priority arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternPriorityPriorityAssoc, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasPriorityRight(SDF_Priority arg) */

ATbool SDF_hasPriorityRight(SDF_Priority arg)
{
  if (SDF_isPriorityPriorityAssoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Group SDF_getPriorityRight(SDF_Priority arg) */

SDF_Group SDF_getPriorityRight(SDF_Priority arg)
{
  if (SDF_isPriorityPriorityAssoc(arg)) {
    return (SDF_Group)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Priority has no Right: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Priority SDF_setPriorityRight(SDF_Priority arg, SDF_Group right) */

SDF_Priority SDF_setPriorityRight(SDF_Priority arg, SDF_Group right)
{
  if (SDF_isPriorityPriorityAssoc(arg)) {
    return (SDF_Priority)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)right, 4), 2);
  }

  ATabort("Priority has no Right: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasPriorityWsAfterAssociativity(SDF_Priority arg) */

ATbool SDF_hasPriorityWsAfterAssociativity(SDF_Priority arg)
{
  if (SDF_isPriorityPriorityAssoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getPriorityWsAfterAssociativity(SDF_Priority arg) */

SDF_Layout SDF_getPriorityWsAfterAssociativity(SDF_Priority arg)
{
  if (SDF_isPriorityPriorityAssoc(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Priority has no WsAfterAssociativity: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Priority SDF_setPriorityWsAfterAssociativity(SDF_Priority arg, SDF_Layout wsAfterAssociativity) */

SDF_Priority SDF_setPriorityWsAfterAssociativity(SDF_Priority arg, SDF_Layout wsAfterAssociativity)
{
  if (SDF_isPriorityPriorityAssoc(arg)) {
    return (SDF_Priority)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterAssociativity, 0), 3), 2);
  }

  ATabort("Priority has no WsAfterAssociativity: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasPriorityWsAfterLeft(SDF_Priority arg) */

ATbool SDF_hasPriorityWsAfterLeft(SDF_Priority arg)
{
  if (SDF_isPriorityPriorityAssoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getPriorityWsAfterLeft(SDF_Priority arg) */

SDF_Layout SDF_getPriorityWsAfterLeft(SDF_Priority arg)
{
  if (SDF_isPriorityPriorityAssoc(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Priority has no WsAfterLeft: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Priority SDF_setPriorityWsAfterLeft(SDF_Priority arg, SDF_Layout wsAfterLeft) */

SDF_Priority SDF_setPriorityWsAfterLeft(SDF_Priority arg, SDF_Layout wsAfterLeft)
{
  if (SDF_isPriorityPriorityAssoc(arg)) {
    return (SDF_Priority)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLeft, 0), 1), 2);
  }

  ATabort("Priority has no WsAfterLeft: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasPriorityGroupp(SDF_Priority arg) */

ATbool SDF_hasPriorityGroupp(SDF_Priority arg)
{
  if (SDF_isPriorityPriorityChain(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_GroupGroupp SDF_getPriorityGroupp(SDF_Priority arg) */

SDF_GroupGroupp SDF_getPriorityGroupp(SDF_Priority arg)
{
  if (SDF_isPriorityPriorityChain(arg)) {
    return (SDF_GroupGroupp)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 2);
  }

  ATabort("Priority has no Groupp: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Priority SDF_setPriorityGroupp(SDF_Priority arg, SDF_GroupGroupp groupp) */

SDF_Priority SDF_setPriorityGroupp(SDF_Priority arg, SDF_GroupGroupp groupp)
{
  if (SDF_isPriorityPriorityChain(arg)) {
    return (SDF_Priority)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)groupp, 2), 0), 2);
  }

  ATabort("Priority has no Groupp: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasPriorityAssociativity(SDF_Priority arg) */

ATbool SDF_hasPriorityAssociativity(SDF_Priority arg)
{
  if (SDF_isPriorityPriorityAssoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Associativity SDF_getPriorityAssociativity(SDF_Priority arg) */

SDF_Associativity SDF_getPriorityAssociativity(SDF_Priority arg)
{
  if (SDF_isPriorityPriorityAssoc(arg)) {
    return (SDF_Associativity)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Priority has no Associativity: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Priority SDF_setPriorityAssociativity(SDF_Priority arg, SDF_Associativity associativity) */

SDF_Priority SDF_setPriorityAssociativity(SDF_Priority arg, SDF_Associativity associativity)
{
  if (SDF_isPriorityPriorityAssoc(arg)) {
    return (SDF_Priority)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)associativity, 2), 2);
  }

  ATabort("Priority has no Associativity: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasPriorityLeft(SDF_Priority arg) */

ATbool SDF_hasPriorityLeft(SDF_Priority arg)
{
  if (SDF_isPriorityPriorityAssoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Group SDF_getPriorityLeft(SDF_Priority arg) */

SDF_Group SDF_getPriorityLeft(SDF_Priority arg)
{
  if (SDF_isPriorityPriorityAssoc(arg)) {
    return (SDF_Group)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Priority has no Left: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Priority SDF_setPriorityLeft(SDF_Priority arg, SDF_Group left) */

SDF_Priority SDF_setPriorityLeft(SDF_Priority arg, SDF_Group left)
{
  if (SDF_isPriorityPriorityAssoc(arg)) {
    return (SDF_Priority)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)left, 0), 2);
  }

  ATabort("Priority has no Left: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_GroupGroupp accessor implementations */

/*{{{  ATbool SDF_isValidGroupGroupp(SDF_GroupGroupp arg) */

ATbool SDF_isValidGroupGroupp(SDF_GroupGroupp arg)
{
  if (SDF_isGroupGrouppSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isGroupGrouppMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isGroupGrouppSingle(SDF_GroupGroupp arg) */

ATbool SDF_isGroupGrouppSingle(SDF_GroupGroupp arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternGroupGrouppSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isGroupGrouppMany(SDF_GroupGroupp arg) */

ATbool SDF_isGroupGrouppMany(SDF_GroupGroupp arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternGroupGrouppMany, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasGroupGrouppWsAfterFirst(SDF_GroupGroupp arg) */

ATbool SDF_hasGroupGrouppWsAfterFirst(SDF_GroupGroupp arg)
{
  if (SDF_isGroupGrouppMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getGroupGrouppWsAfterFirst(SDF_GroupGroupp arg) */

SDF_Layout SDF_getGroupGrouppWsAfterFirst(SDF_GroupGroupp arg)
{
  if (SDF_isGroupGrouppMany(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("GroupGroupp has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_GroupGroupp SDF_setGroupGrouppWsAfterFirst(SDF_GroupGroupp arg, SDF_Layout wsAfterFirst) */

SDF_GroupGroupp SDF_setGroupGrouppWsAfterFirst(SDF_GroupGroupp arg, SDF_Layout wsAfterFirst)
{
  if (SDF_isGroupGrouppMany(arg)) {
    return (SDF_GroupGroupp)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("GroupGroupp has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGroupGrouppWsAfterSep(SDF_GroupGroupp arg) */

ATbool SDF_hasGroupGrouppWsAfterSep(SDF_GroupGroupp arg)
{
  if (SDF_isGroupGrouppMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getGroupGrouppWsAfterSep(SDF_GroupGroupp arg) */

SDF_Layout SDF_getGroupGrouppWsAfterSep(SDF_GroupGroupp arg)
{
  if (SDF_isGroupGrouppMany(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), 0);
  }

  ATabort("GroupGroupp has no WsAfterSep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_GroupGroupp SDF_setGroupGrouppWsAfterSep(SDF_GroupGroupp arg, SDF_Layout wsAfterSep) */

SDF_GroupGroupp SDF_setGroupGrouppWsAfterSep(SDF_GroupGroupp arg, SDF_Layout wsAfterSep)
{
  if (SDF_isGroupGrouppMany(arg)) {
    return (SDF_GroupGroupp)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), (ATerm)wsAfterSep, 0), 3);
  }

  ATabort("GroupGroupp has no WsAfterSep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGroupGrouppTail(SDF_GroupGroupp arg) */

ATbool SDF_hasGroupGrouppTail(SDF_GroupGroupp arg)
{
  if (SDF_isGroupGrouppMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_GroupGroupp SDF_getGroupGrouppTail(SDF_GroupGroupp arg) */

SDF_GroupGroupp SDF_getGroupGrouppTail(SDF_GroupGroupp arg)
{
  if (SDF_isGroupGrouppMany(arg)) {
    return (SDF_GroupGroupp)ATgetTail((ATermList)arg, 4);
  }

  ATabort("GroupGroupp has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_GroupGroupp SDF_setGroupGrouppTail(SDF_GroupGroupp arg, SDF_GroupGroupp tail) */

SDF_GroupGroupp SDF_setGroupGrouppTail(SDF_GroupGroupp arg, SDF_GroupGroupp tail)
{
  if (SDF_isGroupGrouppMany(arg)) {
    return (SDF_GroupGroupp)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("GroupGroupp has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGroupGrouppHead(SDF_GroupGroupp arg) */

ATbool SDF_hasGroupGrouppHead(SDF_GroupGroupp arg)
{
  if (SDF_isGroupGrouppSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isGroupGrouppMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Group SDF_getGroupGrouppHead(SDF_GroupGroupp arg) */

SDF_Group SDF_getGroupGrouppHead(SDF_GroupGroupp arg)
{
  if (SDF_isGroupGrouppSingle(arg)) {
    return (SDF_Group)ATelementAt((ATermList)arg, 0);
  }
  else if (SDF_isGroupGrouppMany(arg)) {
    return (SDF_Group)ATelementAt((ATermList)arg, 0);
  }

  ATabort("GroupGroupp has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_GroupGroupp SDF_setGroupGrouppHead(SDF_GroupGroupp arg, SDF_Group head) */

SDF_GroupGroupp SDF_setGroupGrouppHead(SDF_GroupGroupp arg, SDF_Group head)
{
  if (SDF_isGroupGrouppSingle(arg)) {
    return (SDF_GroupGroupp)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isGroupGrouppMany(arg)) {
    return (SDF_GroupGroupp)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("GroupGroupp has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGroupGrouppSep(SDF_GroupGroupp arg) */

ATbool SDF_hasGroupGrouppSep(SDF_GroupGroupp arg)
{
  if (SDF_isGroupGrouppMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Separator SDF_getGroupGrouppSep(SDF_GroupGroupp arg) */

SDF_Separator SDF_getGroupGrouppSep(SDF_GroupGroupp arg)
{
  if (SDF_isGroupGrouppMany(arg)) {
    return (SDF_Separator)ATelementAt((ATermList)arg, 2);
  }

  ATabort("GroupGroupp has no Sep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_GroupGroupp SDF_setGroupGrouppSep(SDF_GroupGroupp arg, SDF_Separator sep) */

SDF_GroupGroupp SDF_setGroupGrouppSep(SDF_GroupGroupp arg, SDF_Separator sep)
{
  if (SDF_isGroupGrouppMany(arg)) {
    return (SDF_GroupGroupp)ATreplace((ATermList)arg, (ATerm)sep, 2);
  }

  ATabort("GroupGroupp has no Sep: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Priorities accessor implementations */

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
/*{{{  ATbool SDF_hasPrioritiesPrioritys(SDF_Priorities arg) */

ATbool SDF_hasPrioritiesPrioritys(SDF_Priorities arg)
{
  if (SDF_isPrioritiesDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_PriorityPrioritys SDF_getPrioritiesPrioritys(SDF_Priorities arg) */

SDF_PriorityPrioritys SDF_getPrioritiesPrioritys(SDF_Priorities arg)
{
  if (SDF_isPrioritiesDefault(arg)) {
    return (SDF_PriorityPrioritys)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 2);
  }

  ATabort("Priorities has no Prioritys: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Priorities SDF_setPrioritiesPrioritys(SDF_Priorities arg, SDF_PriorityPrioritys prioritys) */

SDF_Priorities SDF_setPrioritiesPrioritys(SDF_Priorities arg, SDF_PriorityPrioritys prioritys)
{
  if (SDF_isPrioritiesDefault(arg)) {
    return (SDF_Priorities)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)prioritys, 2), 0), 2);
  }

  ATabort("Priorities has no Prioritys: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_PriorityPrioritys accessor implementations */

/*{{{  ATbool SDF_isValidPriorityPrioritys(SDF_PriorityPrioritys arg) */

ATbool SDF_isValidPriorityPrioritys(SDF_PriorityPrioritys arg)
{
  if (SDF_isPriorityPrioritysEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isPriorityPrioritysSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isPriorityPrioritysMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isPriorityPrioritysEmpty(SDF_PriorityPrioritys arg) */

ATbool SDF_isPriorityPrioritysEmpty(SDF_PriorityPrioritys arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternPriorityPrioritysEmpty);
}

/*}}}  */
/*{{{  ATbool SDF_isPriorityPrioritysSingle(SDF_PriorityPrioritys arg) */

ATbool SDF_isPriorityPrioritysSingle(SDF_PriorityPrioritys arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternPriorityPrioritysSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isPriorityPrioritysMany(SDF_PriorityPrioritys arg) */

ATbool SDF_isPriorityPrioritysMany(SDF_PriorityPrioritys arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternPriorityPrioritysMany, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasPriorityPrioritysWsAfterFirst(SDF_PriorityPrioritys arg) */

ATbool SDF_hasPriorityPrioritysWsAfterFirst(SDF_PriorityPrioritys arg)
{
  if (SDF_isPriorityPrioritysMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getPriorityPrioritysWsAfterFirst(SDF_PriorityPrioritys arg) */

SDF_Layout SDF_getPriorityPrioritysWsAfterFirst(SDF_PriorityPrioritys arg)
{
  if (SDF_isPriorityPrioritysMany(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("PriorityPrioritys has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_PriorityPrioritys SDF_setPriorityPrioritysWsAfterFirst(SDF_PriorityPrioritys arg, SDF_Layout wsAfterFirst) */

SDF_PriorityPrioritys SDF_setPriorityPrioritysWsAfterFirst(SDF_PriorityPrioritys arg, SDF_Layout wsAfterFirst)
{
  if (SDF_isPriorityPrioritysMany(arg)) {
    return (SDF_PriorityPrioritys)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("PriorityPrioritys has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasPriorityPrioritysWsAfterSep(SDF_PriorityPrioritys arg) */

ATbool SDF_hasPriorityPrioritysWsAfterSep(SDF_PriorityPrioritys arg)
{
  if (SDF_isPriorityPrioritysMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getPriorityPrioritysWsAfterSep(SDF_PriorityPrioritys arg) */

SDF_Layout SDF_getPriorityPrioritysWsAfterSep(SDF_PriorityPrioritys arg)
{
  if (SDF_isPriorityPrioritysMany(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), 0);
  }

  ATabort("PriorityPrioritys has no WsAfterSep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_PriorityPrioritys SDF_setPriorityPrioritysWsAfterSep(SDF_PriorityPrioritys arg, SDF_Layout wsAfterSep) */

SDF_PriorityPrioritys SDF_setPriorityPrioritysWsAfterSep(SDF_PriorityPrioritys arg, SDF_Layout wsAfterSep)
{
  if (SDF_isPriorityPrioritysMany(arg)) {
    return (SDF_PriorityPrioritys)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), (ATerm)wsAfterSep, 0), 3);
  }

  ATabort("PriorityPrioritys has no WsAfterSep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasPriorityPrioritysTail(SDF_PriorityPrioritys arg) */

ATbool SDF_hasPriorityPrioritysTail(SDF_PriorityPrioritys arg)
{
  if (SDF_isPriorityPrioritysMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_PriorityPrioritys SDF_getPriorityPrioritysTail(SDF_PriorityPrioritys arg) */

SDF_PriorityPrioritys SDF_getPriorityPrioritysTail(SDF_PriorityPrioritys arg)
{
  if (SDF_isPriorityPrioritysMany(arg)) {
    return (SDF_PriorityPrioritys)ATgetTail((ATermList)arg, 4);
  }

  ATabort("PriorityPrioritys has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_PriorityPrioritys SDF_setPriorityPrioritysTail(SDF_PriorityPrioritys arg, SDF_PriorityPrioritys tail) */

SDF_PriorityPrioritys SDF_setPriorityPrioritysTail(SDF_PriorityPrioritys arg, SDF_PriorityPrioritys tail)
{
  if (SDF_isPriorityPrioritysMany(arg)) {
    return (SDF_PriorityPrioritys)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("PriorityPrioritys has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasPriorityPrioritysHead(SDF_PriorityPrioritys arg) */

ATbool SDF_hasPriorityPrioritysHead(SDF_PriorityPrioritys arg)
{
  if (SDF_isPriorityPrioritysSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isPriorityPrioritysMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Priority SDF_getPriorityPrioritysHead(SDF_PriorityPrioritys arg) */

SDF_Priority SDF_getPriorityPrioritysHead(SDF_PriorityPrioritys arg)
{
  if (SDF_isPriorityPrioritysSingle(arg)) {
    return (SDF_Priority)ATelementAt((ATermList)arg, 0);
  }
  else if (SDF_isPriorityPrioritysMany(arg)) {
    return (SDF_Priority)ATelementAt((ATermList)arg, 0);
  }

  ATabort("PriorityPrioritys has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_PriorityPrioritys SDF_setPriorityPrioritysHead(SDF_PriorityPrioritys arg, SDF_Priority head) */

SDF_PriorityPrioritys SDF_setPriorityPrioritysHead(SDF_PriorityPrioritys arg, SDF_Priority head)
{
  if (SDF_isPriorityPrioritysSingle(arg)) {
    return (SDF_PriorityPrioritys)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isPriorityPrioritysMany(arg)) {
    return (SDF_PriorityPrioritys)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("PriorityPrioritys has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasPriorityPrioritysSep(SDF_PriorityPrioritys arg) */

ATbool SDF_hasPriorityPrioritysSep(SDF_PriorityPrioritys arg)
{
  if (SDF_isPriorityPrioritysMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Separator SDF_getPriorityPrioritysSep(SDF_PriorityPrioritys arg) */

SDF_Separator SDF_getPriorityPrioritysSep(SDF_PriorityPrioritys arg)
{
  if (SDF_isPriorityPrioritysMany(arg)) {
    return (SDF_Separator)ATelementAt((ATermList)arg, 2);
  }

  ATabort("PriorityPrioritys has no Sep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_PriorityPrioritys SDF_setPriorityPrioritysSep(SDF_PriorityPrioritys arg, SDF_Separator sep) */

SDF_PriorityPrioritys SDF_setPriorityPrioritysSep(SDF_PriorityPrioritys arg, SDF_Separator sep)
{
  if (SDF_isPriorityPrioritysMany(arg)) {
    return (SDF_PriorityPrioritys)ATreplace((ATermList)arg, (ATerm)sep, 2);
  }

  ATabort("PriorityPrioritys has no Sep: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Sort accessor implementations */

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
/*{{{  SDF_Lexical SDF_getSortLex(SDF_Sort arg) */

SDF_Lexical SDF_getSortLex(SDF_Sort arg)
{
  if (SDF_isSortOneChar(arg)) {
    return (SDF_Lexical)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (SDF_isSortMoreChars(arg)) {
    return (SDF_Lexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("Sort has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Sort SDF_setSortLex(SDF_Sort arg, SDF_Lexical lex) */

SDF_Sort SDF_setSortLex(SDF_Sort arg, SDF_Lexical lex)
{
  if (SDF_isSortOneChar(arg)) {
    return (SDF_Sort)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }
  else if (SDF_isSortMoreChars(arg)) {
    return (SDF_Sort)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("Sort has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_UQLiteral accessor implementations */

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
/*{{{  SDF_Lexical SDF_getUQLiteralLex(SDF_UQLiteral arg) */

SDF_Lexical SDF_getUQLiteralLex(SDF_UQLiteral arg)
{
  if (SDF_isUQLiteralOneChar(arg)) {
    return (SDF_Lexical)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (SDF_isUQLiteralMoreChars(arg)) {
    return (SDF_Lexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("UQLiteral has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_UQLiteral SDF_setUQLiteralLex(SDF_UQLiteral arg, SDF_Lexical lex) */

SDF_UQLiteral SDF_setUQLiteralLex(SDF_UQLiteral arg, SDF_Lexical lex)
{
  if (SDF_isUQLiteralOneChar(arg)) {
    return (SDF_UQLiteral)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }
  else if (SDF_isUQLiteralMoreChars(arg)) {
    return (SDF_UQLiteral)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("UQLiteral has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Literal accessor implementations */

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
/*{{{  ATbool SDF_hasLiteralLex(SDF_Literal arg) */

ATbool SDF_hasLiteralLex(SDF_Literal arg)
{
  if (SDF_isLiteralQuoted(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Lexical SDF_getLiteralLex(SDF_Literal arg) */

SDF_Lexical SDF_getLiteralLex(SDF_Literal arg)
{
  if (SDF_isLiteralQuoted(arg)) {
    return (SDF_Lexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("Literal has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Literal SDF_setLiteralLex(SDF_Literal arg, SDF_Lexical lex) */

SDF_Literal SDF_setLiteralLex(SDF_Literal arg, SDF_Lexical lex)
{
  if (SDF_isLiteralQuoted(arg)) {
    return (SDF_Literal)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("Literal has no Lex: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Literal SDF_setLiteralUQLiteral(SDF_Literal arg, SDF_UQLiteral uQLiteral) */

SDF_Literal SDF_setLiteralUQLiteral(SDF_Literal arg, SDF_UQLiteral uQLiteral)
{
  if (SDF_isLiteralUqlit(arg)) {
    return (SDF_Literal)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)uQLiteral, 0), 2);
  }

  ATabort("Literal has no UQLiteral: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_SymbolArguments accessor implementations */

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
/*{{{  ATbool SDF_hasSymbolArgumentsWsAfterFirst(SDF_SymbolArguments arg) */

ATbool SDF_hasSymbolArgumentsWsAfterFirst(SDF_SymbolArguments arg)
{
  if (SDF_isSymbolArgumentsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getSymbolArgumentsWsAfterFirst(SDF_SymbolArguments arg) */

SDF_Layout SDF_getSymbolArgumentsWsAfterFirst(SDF_SymbolArguments arg)
{
  if (SDF_isSymbolArgumentsMany(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("SymbolArguments has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_SymbolArguments SDF_setSymbolArgumentsWsAfterFirst(SDF_SymbolArguments arg, SDF_Layout wsAfterFirst) */

SDF_SymbolArguments SDF_setSymbolArgumentsWsAfterFirst(SDF_SymbolArguments arg, SDF_Layout wsAfterFirst)
{
  if (SDF_isSymbolArgumentsMany(arg)) {
    return (SDF_SymbolArguments)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("SymbolArguments has no WsAfterFirst: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getSymbolArgumentsWsAfterSep(SDF_SymbolArguments arg) */

SDF_Layout SDF_getSymbolArgumentsWsAfterSep(SDF_SymbolArguments arg)
{
  if (SDF_isSymbolArgumentsMany(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), 0);
  }

  ATabort("SymbolArguments has no WsAfterSep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_SymbolArguments SDF_setSymbolArgumentsWsAfterSep(SDF_SymbolArguments arg, SDF_Layout wsAfterSep) */

SDF_SymbolArguments SDF_setSymbolArgumentsWsAfterSep(SDF_SymbolArguments arg, SDF_Layout wsAfterSep)
{
  if (SDF_isSymbolArgumentsMany(arg)) {
    return (SDF_SymbolArguments)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), (ATerm)wsAfterSep, 0), 3);
  }

  ATabort("SymbolArguments has no WsAfterSep: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_SymbolArguments SDF_setSymbolArgumentsTail(SDF_SymbolArguments arg, SDF_SymbolArguments tail) */

SDF_SymbolArguments SDF_setSymbolArgumentsTail(SDF_SymbolArguments arg, SDF_SymbolArguments tail)
{
  if (SDF_isSymbolArgumentsMany(arg)) {
    return (SDF_SymbolArguments)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("SymbolArguments has no Tail: %t\n", arg);
  return NULL;
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
  return NULL;
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
  return NULL;
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
/*{{{  SDF_Separator SDF_getSymbolArgumentsSep(SDF_SymbolArguments arg) */

SDF_Separator SDF_getSymbolArgumentsSep(SDF_SymbolArguments arg)
{
  if (SDF_isSymbolArgumentsMany(arg)) {
    return (SDF_Separator)ATelementAt((ATermList)arg, 2);
  }

  ATabort("SymbolArguments has no Sep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_SymbolArguments SDF_setSymbolArgumentsSep(SDF_SymbolArguments arg, SDF_Separator sep) */

SDF_SymbolArguments SDF_setSymbolArgumentsSep(SDF_SymbolArguments arg, SDF_Separator sep)
{
  if (SDF_isSymbolArgumentsMany(arg)) {
    return (SDF_SymbolArguments)ATreplace((ATermList)arg, (ATerm)sep, 2);
  }

  ATabort("SymbolArguments has no Sep: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Lookahead accessor implementations */

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
/*{{{  ATbool SDF_hasLookaheadWsAfterPeriod(SDF_Lookahead arg) */

ATbool SDF_hasLookaheadWsAfterPeriod(SDF_Lookahead arg)
{
  if (SDF_isLookaheadSeq(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getLookaheadWsAfterPeriod(SDF_Lookahead arg) */

SDF_Layout SDF_getLookaheadWsAfterPeriod(SDF_Lookahead arg)
{
  if (SDF_isLookaheadSeq(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Lookahead has no WsAfterPeriod: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_setLookaheadWsAfterPeriod(SDF_Lookahead arg, SDF_Layout wsAfterPeriod) */

SDF_Lookahead SDF_setLookaheadWsAfterPeriod(SDF_Lookahead arg, SDF_Layout wsAfterPeriod)
{
  if (SDF_isLookaheadSeq(arg)) {
    return (SDF_Lookahead)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterPeriod, 0), 3), 2);
  }

  ATabort("Lookahead has no WsAfterPeriod: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_setLookaheadTail(SDF_Lookahead arg, SDF_Lookaheads tail) */

SDF_Lookahead SDF_setLookaheadTail(SDF_Lookahead arg, SDF_Lookaheads tail)
{
  if (SDF_isLookaheadSeq(arg)) {
    return (SDF_Lookahead)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)tail, 4), 2);
  }

  ATabort("Lookahead has no Tail: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_setLookaheadHead(SDF_Lookahead arg, SDF_CharClass head) */

SDF_Lookahead SDF_setLookaheadHead(SDF_Lookahead arg, SDF_CharClass head)
{
  if (SDF_isLookaheadSeq(arg)) {
    return (SDF_Lookahead)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)head, 0), 2);
  }

  ATabort("Lookahead has no Head: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_setLookaheadCharClass(SDF_Lookahead arg, SDF_CharClass charClass) */

SDF_Lookahead SDF_setLookaheadCharClass(SDF_Lookahead arg, SDF_CharClass charClass)
{
  if (SDF_isLookaheadCharClass(arg)) {
    return (SDF_Lookahead)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)charClass, 0), 2);
  }

  ATabort("Lookahead has no CharClass: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getLookaheadWsAfterHead(SDF_Lookahead arg) */

SDF_Layout SDF_getLookaheadWsAfterHead(SDF_Lookahead arg)
{
  if (SDF_isLookaheadSeq(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Lookahead has no WsAfterHead: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_setLookaheadWsAfterHead(SDF_Lookahead arg, SDF_Layout wsAfterHead) */

SDF_Lookahead SDF_setLookaheadWsAfterHead(SDF_Lookahead arg, SDF_Layout wsAfterHead)
{
  if (SDF_isLookaheadSeq(arg)) {
    return (SDF_Lookahead)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterHead, 0), 1), 2);
  }

  ATabort("Lookahead has no WsAfterHead: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Lookaheads accessor implementations */

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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsRight(SDF_Lookaheads arg, SDF_Lookaheads right) */

SDF_Lookaheads SDF_setLookaheadsRight(SDF_Lookaheads arg, SDF_Lookaheads right)
{
  if (SDF_isLookaheadsAlt(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)right, 4), 2);
  }

  ATabort("Lookaheads has no Right: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadsLookaheads(SDF_Lookaheads arg) */

ATbool SDF_hasLookaheadsLookaheads(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsBracket(arg)) {
    return ATtrue;
  }
  else if (SDF_isLookaheadsList(arg)) {
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
  else if (SDF_isLookaheadsList(arg)) {
    return (SDF_Lookaheads)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2), 2);
  }

  ATabort("Lookaheads has no Lookaheads: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsLookaheads(SDF_Lookaheads arg, SDF_Lookaheads lookaheads) */

SDF_Lookaheads SDF_setLookaheadsLookaheads(SDF_Lookaheads arg, SDF_Lookaheads lookaheads)
{
  if (SDF_isLookaheadsBracket(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)lookaheads, 2), 2);
  }
  else if (SDF_isLookaheadsList(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2), (ATerm)lookaheads, 2), 2), 2);
  }

  ATabort("Lookaheads has no Lookaheads: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getLookaheadsWsAfterLeft(SDF_Lookaheads arg) */

SDF_Layout SDF_getLookaheadsWsAfterLeft(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsAlt(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Lookaheads has no WsAfterLeft: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsWsAfterLeft(SDF_Lookaheads arg, SDF_Layout wsAfterLeft) */

SDF_Lookaheads SDF_setLookaheadsWsAfterLeft(SDF_Lookaheads arg, SDF_Layout wsAfterLeft)
{
  if (SDF_isLookaheadsAlt(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLeft, 0), 1), 2);
  }

  ATabort("Lookaheads has no WsAfterLeft: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getLookaheadsWsAfterParenOpen(SDF_Lookaheads arg) */

SDF_Layout SDF_getLookaheadsWsAfterParenOpen(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsBracket(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Lookaheads has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsWsAfterParenOpen(SDF_Lookaheads arg, SDF_Layout wsAfterParenOpen) */

SDF_Lookaheads SDF_setLookaheadsWsAfterParenOpen(SDF_Lookaheads arg, SDF_Layout wsAfterParenOpen)
{
  if (SDF_isLookaheadsBracket(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterParenOpen, 0), 1), 2);
  }

  ATabort("Lookaheads has no WsAfterParenOpen: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getLookaheadsWsAfterBracketOpenBracketOpen(SDF_Lookaheads arg) */

SDF_Layout SDF_getLookaheadsWsAfterBracketOpenBracketOpen(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsList(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Lookaheads has no WsAfterBracketOpenBracketOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsWsAfterBracketOpenBracketOpen(SDF_Lookaheads arg, SDF_Layout wsAfterBracketOpenBracketOpen) */

SDF_Lookaheads SDF_setLookaheadsWsAfterBracketOpenBracketOpen(SDF_Lookaheads arg, SDF_Layout wsAfterBracketOpenBracketOpen)
{
  if (SDF_isLookaheadsList(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterBracketOpenBracketOpen, 0), 1), 2);
  }

  ATabort("Lookaheads has no WsAfterBracketOpenBracketOpen: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsLookahead(SDF_Lookaheads arg, SDF_Lookahead lookahead) */

SDF_Lookaheads SDF_setLookaheadsLookahead(SDF_Lookaheads arg, SDF_Lookahead lookahead)
{
  if (SDF_isLookaheadsSingle(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)lookahead, 0), 2);
  }

  ATabort("Lookaheads has no Lookahead: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getLookaheadsWsAfterBar(SDF_Lookaheads arg) */

SDF_Layout SDF_getLookaheadsWsAfterBar(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsAlt(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Lookaheads has no WsAfterBar: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsWsAfterBar(SDF_Lookaheads arg, SDF_Layout wsAfterBar) */

SDF_Lookaheads SDF_setLookaheadsWsAfterBar(SDF_Lookaheads arg, SDF_Layout wsAfterBar)
{
  if (SDF_isLookaheadsAlt(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterBar, 0), 3), 2);
  }

  ATabort("Lookaheads has no WsAfterBar: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsLeft(SDF_Lookaheads arg, SDF_Lookaheads left) */

SDF_Lookaheads SDF_setLookaheadsLeft(SDF_Lookaheads arg, SDF_Lookaheads left)
{
  if (SDF_isLookaheadsAlt(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)left, 0), 2);
  }

  ATabort("Lookaheads has no Left: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadsWsAfterLookaheads(SDF_Lookaheads arg) */

ATbool SDF_hasLookaheadsWsAfterLookaheads(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsBracket(arg)) {
    return ATtrue;
  }
  else if (SDF_isLookaheadsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getLookaheadsWsAfterLookaheads(SDF_Lookaheads arg) */

SDF_Layout SDF_getLookaheadsWsAfterLookaheads(SDF_Lookaheads arg)
{
  if (SDF_isLookaheadsBracket(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDF_isLookaheadsList(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Lookaheads has no WsAfterLookaheads: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsWsAfterLookaheads(SDF_Lookaheads arg, SDF_Layout wsAfterLookaheads) */

SDF_Lookaheads SDF_setLookaheadsWsAfterLookaheads(SDF_Lookaheads arg, SDF_Layout wsAfterLookaheads)
{
  if (SDF_isLookaheadsBracket(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterLookaheads, 0), 3), 2);
  }
  else if (SDF_isLookaheadsList(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterLookaheads, 0), 3), 2);
  }

  ATabort("Lookaheads has no WsAfterLookaheads: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_LookaheadLookaheads accessor implementations */

/*{{{  ATbool SDF_isValidLookaheadLookaheads(SDF_LookaheadLookaheads arg) */

ATbool SDF_isValidLookaheadLookaheads(SDF_LookaheadLookaheads arg)
{
  if (SDF_isLookaheadLookaheadsEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isLookaheadLookaheadsSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isLookaheadLookaheadsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isLookaheadLookaheadsEmpty(SDF_LookaheadLookaheads arg) */

ATbool SDF_isLookaheadLookaheadsEmpty(SDF_LookaheadLookaheads arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternLookaheadLookaheadsEmpty);
}

/*}}}  */
/*{{{  ATbool SDF_isLookaheadLookaheadsSingle(SDF_LookaheadLookaheads arg) */

ATbool SDF_isLookaheadLookaheadsSingle(SDF_LookaheadLookaheads arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternLookaheadLookaheadsSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isLookaheadLookaheadsMany(SDF_LookaheadLookaheads arg) */

ATbool SDF_isLookaheadLookaheadsMany(SDF_LookaheadLookaheads arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternLookaheadLookaheadsMany, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadLookaheadsWsAfterFirst(SDF_LookaheadLookaheads arg) */

ATbool SDF_hasLookaheadLookaheadsWsAfterFirst(SDF_LookaheadLookaheads arg)
{
  if (SDF_isLookaheadLookaheadsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getLookaheadLookaheadsWsAfterFirst(SDF_LookaheadLookaheads arg) */

SDF_Layout SDF_getLookaheadLookaheadsWsAfterFirst(SDF_LookaheadLookaheads arg)
{
  if (SDF_isLookaheadLookaheadsMany(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("LookaheadLookaheads has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_LookaheadLookaheads SDF_setLookaheadLookaheadsWsAfterFirst(SDF_LookaheadLookaheads arg, SDF_Layout wsAfterFirst) */

SDF_LookaheadLookaheads SDF_setLookaheadLookaheadsWsAfterFirst(SDF_LookaheadLookaheads arg, SDF_Layout wsAfterFirst)
{
  if (SDF_isLookaheadLookaheadsMany(arg)) {
    return (SDF_LookaheadLookaheads)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("LookaheadLookaheads has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadLookaheadsWsAfterSep(SDF_LookaheadLookaheads arg) */

ATbool SDF_hasLookaheadLookaheadsWsAfterSep(SDF_LookaheadLookaheads arg)
{
  if (SDF_isLookaheadLookaheadsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getLookaheadLookaheadsWsAfterSep(SDF_LookaheadLookaheads arg) */

SDF_Layout SDF_getLookaheadLookaheadsWsAfterSep(SDF_LookaheadLookaheads arg)
{
  if (SDF_isLookaheadLookaheadsMany(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), 0);
  }

  ATabort("LookaheadLookaheads has no WsAfterSep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_LookaheadLookaheads SDF_setLookaheadLookaheadsWsAfterSep(SDF_LookaheadLookaheads arg, SDF_Layout wsAfterSep) */

SDF_LookaheadLookaheads SDF_setLookaheadLookaheadsWsAfterSep(SDF_LookaheadLookaheads arg, SDF_Layout wsAfterSep)
{
  if (SDF_isLookaheadLookaheadsMany(arg)) {
    return (SDF_LookaheadLookaheads)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), (ATerm)wsAfterSep, 0), 3);
  }

  ATabort("LookaheadLookaheads has no WsAfterSep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadLookaheadsTail(SDF_LookaheadLookaheads arg) */

ATbool SDF_hasLookaheadLookaheadsTail(SDF_LookaheadLookaheads arg)
{
  if (SDF_isLookaheadLookaheadsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_LookaheadLookaheads SDF_getLookaheadLookaheadsTail(SDF_LookaheadLookaheads arg) */

SDF_LookaheadLookaheads SDF_getLookaheadLookaheadsTail(SDF_LookaheadLookaheads arg)
{
  if (SDF_isLookaheadLookaheadsMany(arg)) {
    return (SDF_LookaheadLookaheads)ATgetTail((ATermList)arg, 4);
  }

  ATabort("LookaheadLookaheads has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_LookaheadLookaheads SDF_setLookaheadLookaheadsTail(SDF_LookaheadLookaheads arg, SDF_LookaheadLookaheads tail) */

SDF_LookaheadLookaheads SDF_setLookaheadLookaheadsTail(SDF_LookaheadLookaheads arg, SDF_LookaheadLookaheads tail)
{
  if (SDF_isLookaheadLookaheadsMany(arg)) {
    return (SDF_LookaheadLookaheads)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("LookaheadLookaheads has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadLookaheadsHead(SDF_LookaheadLookaheads arg) */

ATbool SDF_hasLookaheadLookaheadsHead(SDF_LookaheadLookaheads arg)
{
  if (SDF_isLookaheadLookaheadsSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isLookaheadLookaheadsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_getLookaheadLookaheadsHead(SDF_LookaheadLookaheads arg) */

SDF_Lookahead SDF_getLookaheadLookaheadsHead(SDF_LookaheadLookaheads arg)
{
  if (SDF_isLookaheadLookaheadsSingle(arg)) {
    return (SDF_Lookahead)ATelementAt((ATermList)arg, 0);
  }
  else if (SDF_isLookaheadLookaheadsMany(arg)) {
    return (SDF_Lookahead)ATelementAt((ATermList)arg, 0);
  }

  ATabort("LookaheadLookaheads has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_LookaheadLookaheads SDF_setLookaheadLookaheadsHead(SDF_LookaheadLookaheads arg, SDF_Lookahead head) */

SDF_LookaheadLookaheads SDF_setLookaheadLookaheadsHead(SDF_LookaheadLookaheads arg, SDF_Lookahead head)
{
  if (SDF_isLookaheadLookaheadsSingle(arg)) {
    return (SDF_LookaheadLookaheads)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isLookaheadLookaheadsMany(arg)) {
    return (SDF_LookaheadLookaheads)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("LookaheadLookaheads has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasLookaheadLookaheadsSep(SDF_LookaheadLookaheads arg) */

ATbool SDF_hasLookaheadLookaheadsSep(SDF_LookaheadLookaheads arg)
{
  if (SDF_isLookaheadLookaheadsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Separator SDF_getLookaheadLookaheadsSep(SDF_LookaheadLookaheads arg) */

SDF_Separator SDF_getLookaheadLookaheadsSep(SDF_LookaheadLookaheads arg)
{
  if (SDF_isLookaheadLookaheadsMany(arg)) {
    return (SDF_Separator)ATelementAt((ATermList)arg, 2);
  }

  ATabort("LookaheadLookaheads has no Sep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_LookaheadLookaheads SDF_setLookaheadLookaheadsSep(SDF_LookaheadLookaheads arg, SDF_Separator sep) */

SDF_LookaheadLookaheads SDF_setLookaheadLookaheadsSep(SDF_LookaheadLookaheads arg, SDF_Separator sep)
{
  if (SDF_isLookaheadLookaheadsMany(arg)) {
    return (SDF_LookaheadLookaheads)ATreplace((ATermList)arg, (ATerm)sep, 2);
  }

  ATabort("LookaheadLookaheads has no Sep: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Restriction accessor implementations */

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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Restriction SDF_setRestrictionLookaheads(SDF_Restriction arg, SDF_Lookaheads lookaheads) */

SDF_Restriction SDF_setRestrictionLookaheads(SDF_Restriction arg, SDF_Lookaheads lookaheads)
{
  if (SDF_isRestrictionFollow(arg)) {
    return (SDF_Restriction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)lookaheads, 4), 2);
  }

  ATabort("Restriction has no Lookaheads: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getRestrictionWsAfterSymbols(SDF_Restriction arg) */

SDF_Layout SDF_getRestrictionWsAfterSymbols(SDF_Restriction arg)
{
  if (SDF_isRestrictionFollow(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Restriction has no WsAfterSymbols: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Restriction SDF_setRestrictionWsAfterSymbols(SDF_Restriction arg, SDF_Layout wsAfterSymbols) */

SDF_Restriction SDF_setRestrictionWsAfterSymbols(SDF_Restriction arg, SDF_Layout wsAfterSymbols)
{
  if (SDF_isRestrictionFollow(arg)) {
    return (SDF_Restriction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterSymbols, 0), 1), 2);
  }

  ATabort("Restriction has no WsAfterSymbols: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getRestrictionWsAfterSlash(SDF_Restriction arg) */

SDF_Layout SDF_getRestrictionWsAfterSlash(SDF_Restriction arg)
{
  if (SDF_isRestrictionFollow(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Restriction has no WsAfterSlash: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Restriction SDF_setRestrictionWsAfterSlash(SDF_Restriction arg, SDF_Layout wsAfterSlash) */

SDF_Restriction SDF_setRestrictionWsAfterSlash(SDF_Restriction arg, SDF_Layout wsAfterSlash)
{
  if (SDF_isRestrictionFollow(arg)) {
    return (SDF_Restriction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSlash, 0), 3), 2);
  }

  ATabort("Restriction has no WsAfterSlash: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Restriction SDF_setRestrictionSymbols(SDF_Restriction arg, SDF_Symbols symbols) */

SDF_Restriction SDF_setRestrictionSymbols(SDF_Restriction arg, SDF_Symbols symbols)
{
  if (SDF_isRestrictionFollow(arg)) {
    return (SDF_Restriction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbols, 0), 2);
  }

  ATabort("Restriction has no Symbols: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Restrictions accessor implementations */

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
/*{{{  ATbool SDF_hasRestrictionsRestrictions(SDF_Restrictions arg) */

ATbool SDF_hasRestrictionsRestrictions(SDF_Restrictions arg)
{
  if (SDF_isRestrictionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_RestrictionRestrictions SDF_getRestrictionsRestrictions(SDF_Restrictions arg) */

SDF_RestrictionRestrictions SDF_getRestrictionsRestrictions(SDF_Restrictions arg)
{
  if (SDF_isRestrictionsDefault(arg)) {
    return (SDF_RestrictionRestrictions)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 2);
  }

  ATabort("Restrictions has no Restrictions: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Restrictions SDF_setRestrictionsRestrictions(SDF_Restrictions arg, SDF_RestrictionRestrictions restrictions) */

SDF_Restrictions SDF_setRestrictionsRestrictions(SDF_Restrictions arg, SDF_RestrictionRestrictions restrictions)
{
  if (SDF_isRestrictionsDefault(arg)) {
    return (SDF_Restrictions)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)restrictions, 2), 0), 2);
  }

  ATabort("Restrictions has no Restrictions: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_RestrictionRestrictions accessor implementations */

/*{{{  ATbool SDF_isValidRestrictionRestrictions(SDF_RestrictionRestrictions arg) */

ATbool SDF_isValidRestrictionRestrictions(SDF_RestrictionRestrictions arg)
{
  if (SDF_isRestrictionRestrictionsEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isRestrictionRestrictionsSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isRestrictionRestrictionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isRestrictionRestrictionsEmpty(SDF_RestrictionRestrictions arg) */

ATbool SDF_isRestrictionRestrictionsEmpty(SDF_RestrictionRestrictions arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternRestrictionRestrictionsEmpty);
}

/*}}}  */
/*{{{  ATbool SDF_isRestrictionRestrictionsSingle(SDF_RestrictionRestrictions arg) */

ATbool SDF_isRestrictionRestrictionsSingle(SDF_RestrictionRestrictions arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternRestrictionRestrictionsSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isRestrictionRestrictionsMany(SDF_RestrictionRestrictions arg) */

ATbool SDF_isRestrictionRestrictionsMany(SDF_RestrictionRestrictions arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternRestrictionRestrictionsMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasRestrictionRestrictionsWsAfterFirst(SDF_RestrictionRestrictions arg) */

ATbool SDF_hasRestrictionRestrictionsWsAfterFirst(SDF_RestrictionRestrictions arg)
{
  if (SDF_isRestrictionRestrictionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getRestrictionRestrictionsWsAfterFirst(SDF_RestrictionRestrictions arg) */

SDF_Layout SDF_getRestrictionRestrictionsWsAfterFirst(SDF_RestrictionRestrictions arg)
{
  if (SDF_isRestrictionRestrictionsMany(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("RestrictionRestrictions has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_RestrictionRestrictions SDF_setRestrictionRestrictionsWsAfterFirst(SDF_RestrictionRestrictions arg, SDF_Layout wsAfterFirst) */

SDF_RestrictionRestrictions SDF_setRestrictionRestrictionsWsAfterFirst(SDF_RestrictionRestrictions arg, SDF_Layout wsAfterFirst)
{
  if (SDF_isRestrictionRestrictionsMany(arg)) {
    return (SDF_RestrictionRestrictions)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("RestrictionRestrictions has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasRestrictionRestrictionsTail(SDF_RestrictionRestrictions arg) */

ATbool SDF_hasRestrictionRestrictionsTail(SDF_RestrictionRestrictions arg)
{
  if (SDF_isRestrictionRestrictionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_RestrictionRestrictions SDF_getRestrictionRestrictionsTail(SDF_RestrictionRestrictions arg) */

SDF_RestrictionRestrictions SDF_getRestrictionRestrictionsTail(SDF_RestrictionRestrictions arg)
{
  if (SDF_isRestrictionRestrictionsMany(arg)) {
    return (SDF_RestrictionRestrictions)ATgetTail((ATermList)arg, 2);
  }

  ATabort("RestrictionRestrictions has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_RestrictionRestrictions SDF_setRestrictionRestrictionsTail(SDF_RestrictionRestrictions arg, SDF_RestrictionRestrictions tail) */

SDF_RestrictionRestrictions SDF_setRestrictionRestrictionsTail(SDF_RestrictionRestrictions arg, SDF_RestrictionRestrictions tail)
{
  if (SDF_isRestrictionRestrictionsMany(arg)) {
    return (SDF_RestrictionRestrictions)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("RestrictionRestrictions has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasRestrictionRestrictionsHead(SDF_RestrictionRestrictions arg) */

ATbool SDF_hasRestrictionRestrictionsHead(SDF_RestrictionRestrictions arg)
{
  if (SDF_isRestrictionRestrictionsSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isRestrictionRestrictionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Restriction SDF_getRestrictionRestrictionsHead(SDF_RestrictionRestrictions arg) */

SDF_Restriction SDF_getRestrictionRestrictionsHead(SDF_RestrictionRestrictions arg)
{
  if (SDF_isRestrictionRestrictionsSingle(arg)) {
    return (SDF_Restriction)ATelementAt((ATermList)arg, 0);
  }
  else if (SDF_isRestrictionRestrictionsMany(arg)) {
    return (SDF_Restriction)ATelementAt((ATermList)arg, 0);
  }

  ATabort("RestrictionRestrictions has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_RestrictionRestrictions SDF_setRestrictionRestrictionsHead(SDF_RestrictionRestrictions arg, SDF_Restriction head) */

SDF_RestrictionRestrictions SDF_setRestrictionRestrictionsHead(SDF_RestrictionRestrictions arg, SDF_Restriction head)
{
  if (SDF_isRestrictionRestrictionsSingle(arg)) {
    return (SDF_RestrictionRestrictions)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isRestrictionRestrictionsMany(arg)) {
    return (SDF_RestrictionRestrictions)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("RestrictionRestrictions has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Alias accessor implementations */

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
/*{{{  ATbool SDF_hasAliasWsAfterSymbol(SDF_Alias arg) */

ATbool SDF_hasAliasWsAfterSymbol(SDF_Alias arg)
{
  if (SDF_isAliasAlias(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getAliasWsAfterSymbol(SDF_Alias arg) */

SDF_Layout SDF_getAliasWsAfterSymbol(SDF_Alias arg)
{
  if (SDF_isAliasAlias(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Alias has no WsAfterSymbol: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Alias SDF_setAliasWsAfterSymbol(SDF_Alias arg, SDF_Layout wsAfterSymbol) */

SDF_Alias SDF_setAliasWsAfterSymbol(SDF_Alias arg, SDF_Layout wsAfterSymbol)
{
  if (SDF_isAliasAlias(arg)) {
    return (SDF_Alias)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterSymbol, 0), 1), 2);
  }

  ATabort("Alias has no WsAfterSymbol: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Alias SDF_setAliasAlias(SDF_Alias arg, SDF_Symbol alias) */

SDF_Alias SDF_setAliasAlias(SDF_Alias arg, SDF_Symbol alias)
{
  if (SDF_isAliasAlias(arg)) {
    return (SDF_Alias)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)alias, 4), 2);
  }

  ATabort("Alias has no Alias: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Alias SDF_setAliasSymbol(SDF_Alias arg, SDF_Symbol symbol) */

SDF_Alias SDF_setAliasSymbol(SDF_Alias arg, SDF_Symbol symbol)
{
  if (SDF_isAliasAlias(arg)) {
    return (SDF_Alias)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 0), 2);
  }

  ATabort("Alias has no Symbol: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getAliasWsAfterArrow(SDF_Alias arg) */

SDF_Layout SDF_getAliasWsAfterArrow(SDF_Alias arg)
{
  if (SDF_isAliasAlias(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Alias has no WsAfterArrow: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Alias SDF_setAliasWsAfterArrow(SDF_Alias arg, SDF_Layout wsAfterArrow) */

SDF_Alias SDF_setAliasWsAfterArrow(SDF_Alias arg, SDF_Layout wsAfterArrow)
{
  if (SDF_isAliasAlias(arg)) {
    return (SDF_Alias)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterArrow, 0), 3), 2);
  }

  ATabort("Alias has no WsAfterArrow: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Aliases accessor implementations */

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
/*{{{  ATbool SDF_hasAliasesAliass(SDF_Aliases arg) */

ATbool SDF_hasAliasesAliass(SDF_Aliases arg)
{
  if (SDF_isAliasesDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_AliasAliass SDF_getAliasesAliass(SDF_Aliases arg) */

SDF_AliasAliass SDF_getAliasesAliass(SDF_Aliases arg)
{
  if (SDF_isAliasesDefault(arg)) {
    return (SDF_AliasAliass)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 2);
  }

  ATabort("Aliases has no Aliass: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Aliases SDF_setAliasesAliass(SDF_Aliases arg, SDF_AliasAliass aliass) */

SDF_Aliases SDF_setAliasesAliass(SDF_Aliases arg, SDF_AliasAliass aliass)
{
  if (SDF_isAliasesDefault(arg)) {
    return (SDF_Aliases)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)aliass, 2), 0), 2);
  }

  ATabort("Aliases has no Aliass: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_AliasAliass accessor implementations */

/*{{{  ATbool SDF_isValidAliasAliass(SDF_AliasAliass arg) */

ATbool SDF_isValidAliasAliass(SDF_AliasAliass arg)
{
  if (SDF_isAliasAliassEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isAliasAliassSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isAliasAliassMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isAliasAliassEmpty(SDF_AliasAliass arg) */

ATbool SDF_isAliasAliassEmpty(SDF_AliasAliass arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAliasAliassEmpty);
}

/*}}}  */
/*{{{  ATbool SDF_isAliasAliassSingle(SDF_AliasAliass arg) */

ATbool SDF_isAliasAliassSingle(SDF_AliasAliass arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAliasAliassSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isAliasAliassMany(SDF_AliasAliass arg) */

ATbool SDF_isAliasAliassMany(SDF_AliasAliass arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternAliasAliassMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasAliasAliassWsAfterFirst(SDF_AliasAliass arg) */

ATbool SDF_hasAliasAliassWsAfterFirst(SDF_AliasAliass arg)
{
  if (SDF_isAliasAliassMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getAliasAliassWsAfterFirst(SDF_AliasAliass arg) */

SDF_Layout SDF_getAliasAliassWsAfterFirst(SDF_AliasAliass arg)
{
  if (SDF_isAliasAliassMany(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("AliasAliass has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_AliasAliass SDF_setAliasAliassWsAfterFirst(SDF_AliasAliass arg, SDF_Layout wsAfterFirst) */

SDF_AliasAliass SDF_setAliasAliassWsAfterFirst(SDF_AliasAliass arg, SDF_Layout wsAfterFirst)
{
  if (SDF_isAliasAliassMany(arg)) {
    return (SDF_AliasAliass)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("AliasAliass has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAliasAliassTail(SDF_AliasAliass arg) */

ATbool SDF_hasAliasAliassTail(SDF_AliasAliass arg)
{
  if (SDF_isAliasAliassMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_AliasAliass SDF_getAliasAliassTail(SDF_AliasAliass arg) */

SDF_AliasAliass SDF_getAliasAliassTail(SDF_AliasAliass arg)
{
  if (SDF_isAliasAliassMany(arg)) {
    return (SDF_AliasAliass)ATgetTail((ATermList)arg, 2);
  }

  ATabort("AliasAliass has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_AliasAliass SDF_setAliasAliassTail(SDF_AliasAliass arg, SDF_AliasAliass tail) */

SDF_AliasAliass SDF_setAliasAliassTail(SDF_AliasAliass arg, SDF_AliasAliass tail)
{
  if (SDF_isAliasAliassMany(arg)) {
    return (SDF_AliasAliass)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("AliasAliass has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAliasAliassHead(SDF_AliasAliass arg) */

ATbool SDF_hasAliasAliassHead(SDF_AliasAliass arg)
{
  if (SDF_isAliasAliassSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isAliasAliassMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Alias SDF_getAliasAliassHead(SDF_AliasAliass arg) */

SDF_Alias SDF_getAliasAliassHead(SDF_AliasAliass arg)
{
  if (SDF_isAliasAliassSingle(arg)) {
    return (SDF_Alias)ATelementAt((ATermList)arg, 0);
  }
  else if (SDF_isAliasAliassMany(arg)) {
    return (SDF_Alias)ATelementAt((ATermList)arg, 0);
  }

  ATabort("AliasAliass has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_AliasAliass SDF_setAliasAliassHead(SDF_AliasAliass arg, SDF_Alias head) */

SDF_AliasAliass SDF_setAliasAliassHead(SDF_AliasAliass arg, SDF_Alias head)
{
  if (SDF_isAliasAliassSingle(arg)) {
    return (SDF_AliasAliass)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isAliasAliassMany(arg)) {
    return (SDF_AliasAliass)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("AliasAliass has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Symbols accessor implementations */

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
/*{{{  ATbool SDF_hasSymbolsSymbols(SDF_Symbols arg) */

ATbool SDF_hasSymbolsSymbols(SDF_Symbols arg)
{
  if (SDF_isSymbolsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_SymbolSymbols SDF_getSymbolsSymbols(SDF_Symbols arg) */

SDF_SymbolSymbols SDF_getSymbolsSymbols(SDF_Symbols arg)
{
  if (SDF_isSymbolsDefault(arg)) {
    return (SDF_SymbolSymbols)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 2);
  }

  ATabort("Symbols has no Symbols: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Symbols SDF_setSymbolsSymbols(SDF_Symbols arg, SDF_SymbolSymbols symbols) */

SDF_Symbols SDF_setSymbolsSymbols(SDF_Symbols arg, SDF_SymbolSymbols symbols)
{
  if (SDF_isSymbolsDefault(arg)) {
    return (SDF_Symbols)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)symbols, 2), 0), 2);
  }

  ATabort("Symbols has no Symbols: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_SymbolSymbols accessor implementations */

/*{{{  ATbool SDF_isValidSymbolSymbols(SDF_SymbolSymbols arg) */

ATbool SDF_isValidSymbolSymbols(SDF_SymbolSymbols arg)
{
  if (SDF_isSymbolSymbolsEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolSymbolsSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolSymbolsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolSymbolsEmpty(SDF_SymbolSymbols arg) */

ATbool SDF_isSymbolSymbolsEmpty(SDF_SymbolSymbols arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolSymbolsEmpty);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolSymbolsSingle(SDF_SymbolSymbols arg) */

ATbool SDF_isSymbolSymbolsSingle(SDF_SymbolSymbols arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolSymbolsSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isSymbolSymbolsMany(SDF_SymbolSymbols arg) */

ATbool SDF_isSymbolSymbolsMany(SDF_SymbolSymbols arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternSymbolSymbolsMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolSymbolsWsAfterFirst(SDF_SymbolSymbols arg) */

ATbool SDF_hasSymbolSymbolsWsAfterFirst(SDF_SymbolSymbols arg)
{
  if (SDF_isSymbolSymbolsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getSymbolSymbolsWsAfterFirst(SDF_SymbolSymbols arg) */

SDF_Layout SDF_getSymbolSymbolsWsAfterFirst(SDF_SymbolSymbols arg)
{
  if (SDF_isSymbolSymbolsMany(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("SymbolSymbols has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_SymbolSymbols SDF_setSymbolSymbolsWsAfterFirst(SDF_SymbolSymbols arg, SDF_Layout wsAfterFirst) */

SDF_SymbolSymbols SDF_setSymbolSymbolsWsAfterFirst(SDF_SymbolSymbols arg, SDF_Layout wsAfterFirst)
{
  if (SDF_isSymbolSymbolsMany(arg)) {
    return (SDF_SymbolSymbols)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("SymbolSymbols has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolSymbolsTail(SDF_SymbolSymbols arg) */

ATbool SDF_hasSymbolSymbolsTail(SDF_SymbolSymbols arg)
{
  if (SDF_isSymbolSymbolsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_SymbolSymbols SDF_getSymbolSymbolsTail(SDF_SymbolSymbols arg) */

SDF_SymbolSymbols SDF_getSymbolSymbolsTail(SDF_SymbolSymbols arg)
{
  if (SDF_isSymbolSymbolsMany(arg)) {
    return (SDF_SymbolSymbols)ATgetTail((ATermList)arg, 2);
  }

  ATabort("SymbolSymbols has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_SymbolSymbols SDF_setSymbolSymbolsTail(SDF_SymbolSymbols arg, SDF_SymbolSymbols tail) */

SDF_SymbolSymbols SDF_setSymbolSymbolsTail(SDF_SymbolSymbols arg, SDF_SymbolSymbols tail)
{
  if (SDF_isSymbolSymbolsMany(arg)) {
    return (SDF_SymbolSymbols)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("SymbolSymbols has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolSymbolsHead(SDF_SymbolSymbols arg) */

ATbool SDF_hasSymbolSymbolsHead(SDF_SymbolSymbols arg)
{
  if (SDF_isSymbolSymbolsSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolSymbolsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_getSymbolSymbolsHead(SDF_SymbolSymbols arg) */

SDF_Symbol SDF_getSymbolSymbolsHead(SDF_SymbolSymbols arg)
{
  if (SDF_isSymbolSymbolsSingle(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)arg, 0);
  }
  else if (SDF_isSymbolSymbolsMany(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)arg, 0);
  }

  ATabort("SymbolSymbols has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_SymbolSymbols SDF_setSymbolSymbolsHead(SDF_SymbolSymbols arg, SDF_Symbol head) */

SDF_SymbolSymbols SDF_setSymbolSymbolsHead(SDF_SymbolSymbols arg, SDF_Symbol head)
{
  if (SDF_isSymbolSymbolsSingle(arg)) {
    return (SDF_SymbolSymbols)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isSymbolSymbolsMany(arg)) {
    return (SDF_SymbolSymbols)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("SymbolSymbols has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Renamings accessor implementations */

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
/*{{{  ATbool SDF_hasRenamingsRenamings(SDF_Renamings arg) */

ATbool SDF_hasRenamingsRenamings(SDF_Renamings arg)
{
  if (SDF_isRenamingsRenamings(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_RenamingRenamings SDF_getRenamingsRenamings(SDF_Renamings arg) */

SDF_RenamingRenamings SDF_getRenamingsRenamings(SDF_Renamings arg)
{
  if (SDF_isRenamingsRenamings(arg)) {
    return (SDF_RenamingRenamings)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2), 2);
  }

  ATabort("Renamings has no Renamings: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Renamings SDF_setRenamingsRenamings(SDF_Renamings arg, SDF_RenamingRenamings renamings) */

SDF_Renamings SDF_setRenamingsRenamings(SDF_Renamings arg, SDF_RenamingRenamings renamings)
{
  if (SDF_isRenamingsRenamings(arg)) {
    return (SDF_Renamings)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2), (ATerm)renamings, 2), 2), 2);
  }

  ATabort("Renamings has no Renamings: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasRenamingsWsAfterRenamings(SDF_Renamings arg) */

ATbool SDF_hasRenamingsWsAfterRenamings(SDF_Renamings arg)
{
  if (SDF_isRenamingsRenamings(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getRenamingsWsAfterRenamings(SDF_Renamings arg) */

SDF_Layout SDF_getRenamingsWsAfterRenamings(SDF_Renamings arg)
{
  if (SDF_isRenamingsRenamings(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Renamings has no WsAfterRenamings: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Renamings SDF_setRenamingsWsAfterRenamings(SDF_Renamings arg, SDF_Layout wsAfterRenamings) */

SDF_Renamings SDF_setRenamingsWsAfterRenamings(SDF_Renamings arg, SDF_Layout wsAfterRenamings)
{
  if (SDF_isRenamingsRenamings(arg)) {
    return (SDF_Renamings)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterRenamings, 0), 3), 2);
  }

  ATabort("Renamings has no WsAfterRenamings: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getRenamingsWsAfterBracketOpen(SDF_Renamings arg) */

SDF_Layout SDF_getRenamingsWsAfterBracketOpen(SDF_Renamings arg)
{
  if (SDF_isRenamingsRenamings(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Renamings has no WsAfterBracketOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Renamings SDF_setRenamingsWsAfterBracketOpen(SDF_Renamings arg, SDF_Layout wsAfterBracketOpen) */

SDF_Renamings SDF_setRenamingsWsAfterBracketOpen(SDF_Renamings arg, SDF_Layout wsAfterBracketOpen)
{
  if (SDF_isRenamingsRenamings(arg)) {
    return (SDF_Renamings)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterBracketOpen, 0), 1), 2);
  }

  ATabort("Renamings has no WsAfterBracketOpen: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_RenamingRenamings accessor implementations */

/*{{{  ATbool SDF_isValidRenamingRenamings(SDF_RenamingRenamings arg) */

ATbool SDF_isValidRenamingRenamings(SDF_RenamingRenamings arg)
{
  if (SDF_isRenamingRenamingsEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isRenamingRenamingsSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isRenamingRenamingsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDF_isRenamingRenamingsEmpty(SDF_RenamingRenamings arg) */

ATbool SDF_isRenamingRenamingsEmpty(SDF_RenamingRenamings arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternRenamingRenamingsEmpty);
}

/*}}}  */
/*{{{  ATbool SDF_isRenamingRenamingsSingle(SDF_RenamingRenamings arg) */

ATbool SDF_isRenamingRenamingsSingle(SDF_RenamingRenamings arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternRenamingRenamingsSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_isRenamingRenamingsMany(SDF_RenamingRenamings arg) */

ATbool SDF_isRenamingRenamingsMany(SDF_RenamingRenamings arg)
{
  return ATmatchTerm((ATerm)arg, SDF_patternRenamingRenamingsMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDF_hasRenamingRenamingsWsAfterFirst(SDF_RenamingRenamings arg) */

ATbool SDF_hasRenamingRenamingsWsAfterFirst(SDF_RenamingRenamings arg)
{
  if (SDF_isRenamingRenamingsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getRenamingRenamingsWsAfterFirst(SDF_RenamingRenamings arg) */

SDF_Layout SDF_getRenamingRenamingsWsAfterFirst(SDF_RenamingRenamings arg)
{
  if (SDF_isRenamingRenamingsMany(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("RenamingRenamings has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_RenamingRenamings SDF_setRenamingRenamingsWsAfterFirst(SDF_RenamingRenamings arg, SDF_Layout wsAfterFirst) */

SDF_RenamingRenamings SDF_setRenamingRenamingsWsAfterFirst(SDF_RenamingRenamings arg, SDF_Layout wsAfterFirst)
{
  if (SDF_isRenamingRenamingsMany(arg)) {
    return (SDF_RenamingRenamings)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("RenamingRenamings has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasRenamingRenamingsTail(SDF_RenamingRenamings arg) */

ATbool SDF_hasRenamingRenamingsTail(SDF_RenamingRenamings arg)
{
  if (SDF_isRenamingRenamingsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_RenamingRenamings SDF_getRenamingRenamingsTail(SDF_RenamingRenamings arg) */

SDF_RenamingRenamings SDF_getRenamingRenamingsTail(SDF_RenamingRenamings arg)
{
  if (SDF_isRenamingRenamingsMany(arg)) {
    return (SDF_RenamingRenamings)ATgetTail((ATermList)arg, 2);
  }

  ATabort("RenamingRenamings has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_RenamingRenamings SDF_setRenamingRenamingsTail(SDF_RenamingRenamings arg, SDF_RenamingRenamings tail) */

SDF_RenamingRenamings SDF_setRenamingRenamingsTail(SDF_RenamingRenamings arg, SDF_RenamingRenamings tail)
{
  if (SDF_isRenamingRenamingsMany(arg)) {
    return (SDF_RenamingRenamings)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("RenamingRenamings has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasRenamingRenamingsHead(SDF_RenamingRenamings arg) */

ATbool SDF_hasRenamingRenamingsHead(SDF_RenamingRenamings arg)
{
  if (SDF_isRenamingRenamingsSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isRenamingRenamingsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Renaming SDF_getRenamingRenamingsHead(SDF_RenamingRenamings arg) */

SDF_Renaming SDF_getRenamingRenamingsHead(SDF_RenamingRenamings arg)
{
  if (SDF_isRenamingRenamingsSingle(arg)) {
    return (SDF_Renaming)ATelementAt((ATermList)arg, 0);
  }
  else if (SDF_isRenamingRenamingsMany(arg)) {
    return (SDF_Renaming)ATelementAt((ATermList)arg, 0);
  }

  ATabort("RenamingRenamings has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_RenamingRenamings SDF_setRenamingRenamingsHead(SDF_RenamingRenamings arg, SDF_Renaming head) */

SDF_RenamingRenamings SDF_setRenamingRenamingsHead(SDF_RenamingRenamings arg, SDF_Renaming head)
{
  if (SDF_isRenamingRenamingsSingle(arg)) {
    return (SDF_RenamingRenamings)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isRenamingRenamingsMany(arg)) {
    return (SDF_RenamingRenamings)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("RenamingRenamings has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Renaming accessor implementations */

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
  return NULL;
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
  return NULL;
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
  return NULL;
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
  return NULL;
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
/*{{{  SDF_Layout SDF_getRenamingWsAfterFrom(SDF_Renaming arg) */

SDF_Layout SDF_getRenamingWsAfterFrom(SDF_Renaming arg)
{
  if (SDF_isRenamingSymbol(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isRenamingProduction(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Renaming has no WsAfterFrom: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Renaming SDF_setRenamingWsAfterFrom(SDF_Renaming arg, SDF_Layout wsAfterFrom) */

SDF_Renaming SDF_setRenamingWsAfterFrom(SDF_Renaming arg, SDF_Layout wsAfterFrom)
{
  if (SDF_isRenamingSymbol(arg)) {
    return (SDF_Renaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterFrom, 0), 1), 2);
  }
  else if (SDF_isRenamingProduction(arg)) {
    return (SDF_Renaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterFrom, 0), 1), 2);
  }

  ATabort("Renaming has no WsAfterFrom: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getRenamingWsAfterEqualsGreaterThan(SDF_Renaming arg) */

SDF_Layout SDF_getRenamingWsAfterEqualsGreaterThan(SDF_Renaming arg)
{
  if (SDF_isRenamingSymbol(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDF_isRenamingProduction(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Renaming has no WsAfterEqualsGreaterThan: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Renaming SDF_setRenamingWsAfterEqualsGreaterThan(SDF_Renaming arg, SDF_Layout wsAfterEqualsGreaterThan) */

SDF_Renaming SDF_setRenamingWsAfterEqualsGreaterThan(SDF_Renaming arg, SDF_Layout wsAfterEqualsGreaterThan)
{
  if (SDF_isRenamingSymbol(arg)) {
    return (SDF_Renaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterEqualsGreaterThan, 0), 3), 2);
  }
  else if (SDF_isRenamingProduction(arg)) {
    return (SDF_Renaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterEqualsGreaterThan, 0), 3), 2);
  }

  ATabort("Renaming has no WsAfterEqualsGreaterThan: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_NatCon accessor implementations */

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
/*{{{  SDF_Lexical SDF_getNatConLex(SDF_NatCon arg) */

SDF_Lexical SDF_getNatConLex(SDF_NatCon arg)
{
  if (SDF_isNatConDigits(arg)) {
    return (SDF_Lexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("NatCon has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_NatCon SDF_setNatConLex(SDF_NatCon arg, SDF_Lexical lex) */

SDF_NatCon SDF_setNatConLex(SDF_NatCon arg, SDF_Lexical lex)
{
  if (SDF_isNatConDigits(arg)) {
    return (SDF_NatCon)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("NatCon has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_IntCon accessor implementations */

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
/*{{{  ATbool SDF_hasIntConWsAfterNeg(SDF_IntCon arg) */

ATbool SDF_hasIntConWsAfterNeg(SDF_IntCon arg)
{
  if (SDF_isIntConNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getIntConWsAfterNeg(SDF_IntCon arg) */

SDF_Layout SDF_getIntConWsAfterNeg(SDF_IntCon arg)
{
  if (SDF_isIntConNegative(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("IntCon has no WsAfterNeg: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_IntCon SDF_setIntConWsAfterNeg(SDF_IntCon arg, SDF_Layout wsAfterNeg) */

SDF_IntCon SDF_setIntConWsAfterNeg(SDF_IntCon arg, SDF_Layout wsAfterNeg)
{
  if (SDF_isIntConNegative(arg)) {
    return (SDF_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterNeg, 0), 1), 2);
  }

  ATabort("IntCon has no WsAfterNeg: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getIntConWsAfterPos(SDF_IntCon arg) */

SDF_Layout SDF_getIntConWsAfterPos(SDF_IntCon arg)
{
  if (SDF_isIntConPositive(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("IntCon has no WsAfterPos: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_IntCon SDF_setIntConWsAfterPos(SDF_IntCon arg, SDF_Layout wsAfterPos) */

SDF_IntCon SDF_setIntConWsAfterPos(SDF_IntCon arg, SDF_Layout wsAfterPos)
{
  if (SDF_isIntConPositive(arg)) {
    return (SDF_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterPos, 0), 1), 2);
  }

  ATabort("IntCon has no WsAfterPos: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_IntCon SDF_setIntConNatCon(SDF_IntCon arg, SDF_NatCon natCon) */

SDF_IntCon SDF_setIntConNatCon(SDF_IntCon arg, SDF_NatCon natCon)
{
  if (SDF_isIntConNatural(arg)) {
    return (SDF_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)natCon, 0), 2);
  }
  else if (SDF_isIntConPositive(arg)) {
    return (SDF_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)natCon, 2), 2);
  }
  else if (SDF_isIntConNegative(arg)) {
    return (SDF_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)natCon, 2), 2);
  }

  ATabort("IntCon has no NatCon: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_CharRange accessor implementations */

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
/*{{{  ATbool SDF_hasCharRangeWsAfter(SDF_CharRange arg) */

ATbool SDF_hasCharRangeWsAfter(SDF_CharRange arg)
{
  if (SDF_isCharRangeRange(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getCharRangeWsAfter(SDF_CharRange arg) */

SDF_Layout SDF_getCharRangeWsAfter(SDF_CharRange arg)
{
  if (SDF_isCharRangeRange(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("CharRange has no WsAfter: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_CharRange SDF_setCharRangeWsAfter(SDF_CharRange arg, SDF_Layout wsAfter) */

SDF_CharRange SDF_setCharRangeWsAfter(SDF_CharRange arg, SDF_Layout wsAfter)
{
  if (SDF_isCharRangeRange(arg)) {
    return (SDF_CharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfter, 0), 3), 2);
  }

  ATabort("CharRange has no WsAfter: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_CharRange SDF_setCharRangeEnd(SDF_CharRange arg, SDF_Character end) */

SDF_CharRange SDF_setCharRangeEnd(SDF_CharRange arg, SDF_Character end)
{
  if (SDF_isCharRangeRange(arg)) {
    return (SDF_CharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)end, 4), 2);
  }

  ATabort("CharRange has no End: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_CharRange SDF_setCharRangeCharacter(SDF_CharRange arg, SDF_Character character) */

SDF_CharRange SDF_setCharRangeCharacter(SDF_CharRange arg, SDF_Character character)
{
  if (SDF_isCharRangeDefault(arg)) {
    return (SDF_CharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)character, 0), 2);
  }

  ATabort("CharRange has no Character: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_CharRange SDF_setCharRangeStart(SDF_CharRange arg, SDF_Character start) */

SDF_CharRange SDF_setCharRangeStart(SDF_CharRange arg, SDF_Character start)
{
  if (SDF_isCharRangeRange(arg)) {
    return (SDF_CharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)start, 0), 2);
  }

  ATabort("CharRange has no Start: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getCharRangeWsAfterStart(SDF_CharRange arg) */

SDF_Layout SDF_getCharRangeWsAfterStart(SDF_CharRange arg)
{
  if (SDF_isCharRangeRange(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("CharRange has no WsAfterStart: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_CharRange SDF_setCharRangeWsAfterStart(SDF_CharRange arg, SDF_Layout wsAfterStart) */

SDF_CharRange SDF_setCharRangeWsAfterStart(SDF_CharRange arg, SDF_Layout wsAfterStart)
{
  if (SDF_isCharRangeRange(arg)) {
    return (SDF_CharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterStart, 0), 1), 2);
  }

  ATabort("CharRange has no WsAfterStart: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_CharRanges accessor implementations */

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
  return NULL;
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_setCharRangesRight(SDF_CharRanges arg, SDF_CharRanges right) */

SDF_CharRanges SDF_setCharRangesRight(SDF_CharRanges arg, SDF_CharRanges right)
{
  if (SDF_isCharRangesConc(arg)) {
    return (SDF_CharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)right, 2), 2);
  }

  ATabort("CharRanges has no Right: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getCharRangesWsAfterLeft(SDF_CharRanges arg) */

SDF_Layout SDF_getCharRangesWsAfterLeft(SDF_CharRanges arg)
{
  if (SDF_isCharRangesConc(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("CharRanges has no WsAfterLeft: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_setCharRangesWsAfterLeft(SDF_CharRanges arg, SDF_Layout wsAfterLeft) */

SDF_CharRanges SDF_setCharRangesWsAfterLeft(SDF_CharRanges arg, SDF_Layout wsAfterLeft)
{
  if (SDF_isCharRangesConc(arg)) {
    return (SDF_CharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLeft, 0), 1), 2);
  }

  ATabort("CharRanges has no WsAfterLeft: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getCharRangesWsAfterParenOpen(SDF_CharRanges arg) */

SDF_Layout SDF_getCharRangesWsAfterParenOpen(SDF_CharRanges arg)
{
  if (SDF_isCharRangesBracket(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("CharRanges has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_setCharRangesWsAfterParenOpen(SDF_CharRanges arg, SDF_Layout wsAfterParenOpen) */

SDF_CharRanges SDF_setCharRangesWsAfterParenOpen(SDF_CharRanges arg, SDF_Layout wsAfterParenOpen)
{
  if (SDF_isCharRangesBracket(arg)) {
    return (SDF_CharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterParenOpen, 0), 1), 2);
  }

  ATabort("CharRanges has no WsAfterParenOpen: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getCharRangesWsAfterCharRanges(SDF_CharRanges arg) */

SDF_Layout SDF_getCharRangesWsAfterCharRanges(SDF_CharRanges arg)
{
  if (SDF_isCharRangesBracket(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("CharRanges has no WsAfterCharRanges: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_setCharRangesWsAfterCharRanges(SDF_CharRanges arg, SDF_Layout wsAfterCharRanges) */

SDF_CharRanges SDF_setCharRangesWsAfterCharRanges(SDF_CharRanges arg, SDF_Layout wsAfterCharRanges)
{
  if (SDF_isCharRangesBracket(arg)) {
    return (SDF_CharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterCharRanges, 0), 3), 2);
  }

  ATabort("CharRanges has no WsAfterCharRanges: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_setCharRangesCharRanges(SDF_CharRanges arg, SDF_CharRanges charRanges) */

SDF_CharRanges SDF_setCharRangesCharRanges(SDF_CharRanges arg, SDF_CharRanges charRanges)
{
  if (SDF_isCharRangesBracket(arg)) {
    return (SDF_CharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)charRanges, 2), 2);
  }

  ATabort("CharRanges has no CharRanges: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_setCharRangesCharRange(SDF_CharRanges arg, SDF_CharRange charRange) */

SDF_CharRanges SDF_setCharRangesCharRange(SDF_CharRanges arg, SDF_CharRange charRange)
{
  if (SDF_isCharRangesDefault(arg)) {
    return (SDF_CharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)charRange, 0), 2);
  }

  ATabort("CharRanges has no CharRange: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_setCharRangesLeft(SDF_CharRanges arg, SDF_CharRanges left) */

SDF_CharRanges SDF_setCharRangesLeft(SDF_CharRanges arg, SDF_CharRanges left)
{
  if (SDF_isCharRangesConc(arg)) {
    return (SDF_CharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)left, 0), 2);
  }

  ATabort("CharRanges has no Left: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_OptCharRanges accessor implementations */

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
  return NULL;
}

/*}}}  */
/*{{{  SDF_OptCharRanges SDF_setOptCharRangesCharRanges(SDF_OptCharRanges arg, SDF_CharRanges charRanges) */

SDF_OptCharRanges SDF_setOptCharRangesCharRanges(SDF_OptCharRanges arg, SDF_CharRanges charRanges)
{
  if (SDF_isOptCharRangesPresent(arg)) {
    return (SDF_OptCharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)charRanges, 0), 2);
  }

  ATabort("OptCharRanges has no CharRanges: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_CharClass accessor implementations */

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
  return NULL;
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
  return NULL;
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
/*{{{  SDF_Layout SDF_getCharClassWsAfterSlash(SDF_CharClass arg) */

SDF_Layout SDF_getCharClassWsAfterSlash(SDF_CharClass arg)
{
  if (SDF_isCharClassDiff(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("CharClass has no WsAfterSlash: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterSlash(SDF_CharClass arg, SDF_Layout wsAfterSlash) */

SDF_CharClass SDF_setCharClassWsAfterSlash(SDF_CharClass arg, SDF_Layout wsAfterSlash)
{
  if (SDF_isCharClassDiff(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSlash, 0), 3), 2);
  }

  ATabort("CharClass has no WsAfterSlash: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassOptCharRanges(SDF_CharClass arg, SDF_OptCharRanges optCharRanges) */

SDF_CharClass SDF_setCharClassOptCharRanges(SDF_CharClass arg, SDF_OptCharRanges optCharRanges)
{
  if (SDF_isCharClassSimpleCharclass(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)optCharRanges, 2), 2);
  }

  ATabort("CharClass has no OptCharRanges: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getCharClassWsAfterLeft(SDF_CharClass arg) */

SDF_Layout SDF_getCharClassWsAfterLeft(SDF_CharClass arg)
{
  if (SDF_isCharClassDiff(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isCharClassIsect(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isCharClassUnion(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("CharClass has no WsAfterLeft: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterLeft(SDF_CharClass arg, SDF_Layout wsAfterLeft) */

SDF_CharClass SDF_setCharClassWsAfterLeft(SDF_CharClass arg, SDF_Layout wsAfterLeft)
{
  if (SDF_isCharClassDiff(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLeft, 0), 1), 2);
  }
  else if (SDF_isCharClassIsect(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLeft, 0), 1), 2);
  }
  else if (SDF_isCharClassUnion(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLeft, 0), 1), 2);
  }

  ATabort("CharClass has no WsAfterLeft: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getCharClassWsAfterParenOpen(SDF_CharClass arg) */

SDF_Layout SDF_getCharClassWsAfterParenOpen(SDF_CharClass arg)
{
  if (SDF_isCharClassBracket(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("CharClass has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterParenOpen(SDF_CharClass arg, SDF_Layout wsAfterParenOpen) */

SDF_CharClass SDF_setCharClassWsAfterParenOpen(SDF_CharClass arg, SDF_Layout wsAfterParenOpen)
{
  if (SDF_isCharClassBracket(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterParenOpen, 0), 1), 2);
  }

  ATabort("CharClass has no WsAfterParenOpen: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getCharClassWsAfterTilde(SDF_CharClass arg) */

SDF_Layout SDF_getCharClassWsAfterTilde(SDF_CharClass arg)
{
  if (SDF_isCharClassComp(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("CharClass has no WsAfterTilde: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterTilde(SDF_CharClass arg, SDF_Layout wsAfterTilde) */

SDF_CharClass SDF_setCharClassWsAfterTilde(SDF_CharClass arg, SDF_Layout wsAfterTilde)
{
  if (SDF_isCharClassComp(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterTilde, 0), 1), 2);
  }

  ATabort("CharClass has no WsAfterTilde: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getCharClassWsAfterBackslashSlash(SDF_CharClass arg) */

SDF_Layout SDF_getCharClassWsAfterBackslashSlash(SDF_CharClass arg)
{
  if (SDF_isCharClassUnion(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("CharClass has no WsAfterBackslashSlash: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterBackslashSlash(SDF_CharClass arg, SDF_Layout wsAfterBackslashSlash) */

SDF_CharClass SDF_setCharClassWsAfterBackslashSlash(SDF_CharClass arg, SDF_Layout wsAfterBackslashSlash)
{
  if (SDF_isCharClassUnion(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterBackslashSlash, 0), 3), 2);
  }

  ATabort("CharClass has no WsAfterBackslashSlash: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getCharClassWsAfterOptCharRanges(SDF_CharClass arg) */

SDF_Layout SDF_getCharClassWsAfterOptCharRanges(SDF_CharClass arg)
{
  if (SDF_isCharClassSimpleCharclass(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("CharClass has no WsAfterOptCharRanges: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterOptCharRanges(SDF_CharClass arg, SDF_Layout wsAfterOptCharRanges) */

SDF_CharClass SDF_setCharClassWsAfterOptCharRanges(SDF_CharClass arg, SDF_Layout wsAfterOptCharRanges)
{
  if (SDF_isCharClassSimpleCharclass(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterOptCharRanges, 0), 3), 2);
  }

  ATabort("CharClass has no WsAfterOptCharRanges: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassCharClass(SDF_CharClass arg, SDF_CharClass charClass) */

SDF_CharClass SDF_setCharClassCharClass(SDF_CharClass arg, SDF_CharClass charClass)
{
  if (SDF_isCharClassComp(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)charClass, 2), 2);
  }
  else if (SDF_isCharClassBracket(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)charClass, 2), 2);
  }

  ATabort("CharClass has no CharClass: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getCharClassWsAfterBracketOpen(SDF_CharClass arg) */

SDF_Layout SDF_getCharClassWsAfterBracketOpen(SDF_CharClass arg)
{
  if (SDF_isCharClassSimpleCharclass(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("CharClass has no WsAfterBracketOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterBracketOpen(SDF_CharClass arg, SDF_Layout wsAfterBracketOpen) */

SDF_CharClass SDF_setCharClassWsAfterBracketOpen(SDF_CharClass arg, SDF_Layout wsAfterBracketOpen)
{
  if (SDF_isCharClassSimpleCharclass(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterBracketOpen, 0), 1), 2);
  }

  ATabort("CharClass has no WsAfterBracketOpen: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getCharClassWsAfterSlashBackslash(SDF_CharClass arg) */

SDF_Layout SDF_getCharClassWsAfterSlashBackslash(SDF_CharClass arg)
{
  if (SDF_isCharClassIsect(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("CharClass has no WsAfterSlashBackslash: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterSlashBackslash(SDF_CharClass arg, SDF_Layout wsAfterSlashBackslash) */

SDF_CharClass SDF_setCharClassWsAfterSlashBackslash(SDF_CharClass arg, SDF_Layout wsAfterSlashBackslash)
{
  if (SDF_isCharClassIsect(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSlashBackslash, 0), 3), 2);
  }

  ATabort("CharClass has no WsAfterSlashBackslash: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getCharClassWsAfterCharClass(SDF_CharClass arg) */

SDF_Layout SDF_getCharClassWsAfterCharClass(SDF_CharClass arg)
{
  if (SDF_isCharClassBracket(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("CharClass has no WsAfterCharClass: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterCharClass(SDF_CharClass arg, SDF_Layout wsAfterCharClass) */

SDF_CharClass SDF_setCharClassWsAfterCharClass(SDF_CharClass arg, SDF_Layout wsAfterCharClass)
{
  if (SDF_isCharClassBracket(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterCharClass, 0), 3), 2);
  }

  ATabort("CharClass has no WsAfterCharClass: %t\n", arg);
  return NULL;
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
  return NULL;
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
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_AlphaNumericalEscChar accessor implementations */

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
/*{{{  SDF_Lexical SDF_getAlphaNumericalEscCharLex(SDF_AlphaNumericalEscChar arg) */

SDF_Lexical SDF_getAlphaNumericalEscCharLex(SDF_AlphaNumericalEscChar arg)
{
  if (SDF_isAlphaNumericalEscCharDefault(arg)) {
    return (SDF_Lexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("AlphaNumericalEscChar has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_AlphaNumericalEscChar SDF_setAlphaNumericalEscCharLex(SDF_AlphaNumericalEscChar arg, SDF_Lexical lex) */

SDF_AlphaNumericalEscChar SDF_setAlphaNumericalEscCharLex(SDF_AlphaNumericalEscChar arg, SDF_Lexical lex)
{
  if (SDF_isAlphaNumericalEscCharDefault(arg)) {
    return (SDF_AlphaNumericalEscChar)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("AlphaNumericalEscChar has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_DecimalEscChar accessor implementations */

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
/*{{{  SDF_Lexical SDF_getDecimalEscCharLex(SDF_DecimalEscChar arg) */

SDF_Lexical SDF_getDecimalEscCharLex(SDF_DecimalEscChar arg)
{
  if (SDF_isDecimalEscCharDec0_199(arg)) {
    return (SDF_Lexical)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (SDF_isDecimalEscCharDec200_249(arg)) {
    return (SDF_Lexical)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (SDF_isDecimalEscCharDec250_255(arg)) {
    return (SDF_Lexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("DecimalEscChar has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_DecimalEscChar SDF_setDecimalEscCharLex(SDF_DecimalEscChar arg, SDF_Lexical lex) */

SDF_DecimalEscChar SDF_setDecimalEscCharLex(SDF_DecimalEscChar arg, SDF_Lexical lex)
{
  if (SDF_isDecimalEscCharDec0_199(arg)) {
    return (SDF_DecimalEscChar)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }
  else if (SDF_isDecimalEscCharDec200_249(arg)) {
    return (SDF_DecimalEscChar)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }
  else if (SDF_isDecimalEscCharDec250_255(arg)) {
    return (SDF_DecimalEscChar)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("DecimalEscChar has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_EscChar accessor implementations */

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
/*{{{  SDF_Lexical SDF_getEscCharLex(SDF_EscChar arg) */

SDF_Lexical SDF_getEscCharLex(SDF_EscChar arg)
{
  if (SDF_isEscCharAlphaNumeric(arg)) {
    return (SDF_Lexical)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (SDF_isEscCharDecimal(arg)) {
    return (SDF_Lexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("EscChar has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_EscChar SDF_setEscCharLex(SDF_EscChar arg, SDF_Lexical lex) */

SDF_EscChar SDF_setEscCharLex(SDF_EscChar arg, SDF_Lexical lex)
{
  if (SDF_isEscCharAlphaNumeric(arg)) {
    return (SDF_EscChar)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }
  else if (SDF_isEscCharDecimal(arg)) {
    return (SDF_EscChar)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("EscChar has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_LChar accessor implementations */

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
/*{{{  SDF_Lexical SDF_getLCharLex(SDF_LChar arg) */

SDF_Lexical SDF_getLCharLex(SDF_LChar arg)
{
  if (SDF_isLCharNormal(arg)) {
    return (SDF_Lexical)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (SDF_isLCharEscaped(arg)) {
    return (SDF_Lexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("LChar has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_LChar SDF_setLCharLex(SDF_LChar arg, SDF_Lexical lex) */

SDF_LChar SDF_setLCharLex(SDF_LChar arg, SDF_Lexical lex)
{
  if (SDF_isLCharNormal(arg)) {
    return (SDF_LChar)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }
  else if (SDF_isLCharEscaped(arg)) {
    return (SDF_LChar)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("LChar has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ATerms accessor implementations */

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
/*{{{  ATbool SDF_hasATermsWsAfterComma(SDF_ATerms arg) */

ATbool SDF_hasATermsWsAfterComma(SDF_ATerms arg)
{
  if (SDF_isATermsCons(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getATermsWsAfterComma(SDF_ATerms arg) */

SDF_Layout SDF_getATermsWsAfterComma(SDF_ATerms arg)
{
  if (SDF_isATermsCons(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("ATerms has no WsAfterComma: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ATerms SDF_setATermsWsAfterComma(SDF_ATerms arg, SDF_Layout wsAfterComma) */

SDF_ATerms SDF_setATermsWsAfterComma(SDF_ATerms arg, SDF_Layout wsAfterComma)
{
  if (SDF_isATermsCons(arg)) {
    return (SDF_ATerms)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterComma, 0), 3), 2);
  }

  ATabort("ATerms has no WsAfterComma: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermsATerm(SDF_ATerms arg) */

ATbool SDF_hasATermsATerm(SDF_ATerms arg)
{
  if (SDF_isATermsAterm(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_getATermsATerm(SDF_ATerms arg) */

SDF_ATerm SDF_getATermsATerm(SDF_ATerms arg)
{
  if (SDF_isATermsAterm(arg)) {
    return (SDF_ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("ATerms has no ATerm: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ATerms SDF_setATermsATerm(SDF_ATerms arg, SDF_ATerm aTerm) */

SDF_ATerms SDF_setATermsATerm(SDF_ATerms arg, SDF_ATerm aTerm)
{
  if (SDF_isATermsAterm(arg)) {
    return (SDF_ATerms)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aTerm, 0), 2);
  }

  ATabort("ATerms has no ATerm: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_ATerms SDF_setATermsTail(SDF_ATerms arg, SDF_ATerms tail) */

SDF_ATerms SDF_setATermsTail(SDF_ATerms arg, SDF_ATerms tail)
{
  if (SDF_isATermsCons(arg)) {
    return (SDF_ATerms)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)tail, 4), 2);
  }

  ATabort("ATerms has no Tail: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_ATerms SDF_setATermsHead(SDF_ATerms arg, SDF_ATerm head) */

SDF_ATerms SDF_setATermsHead(SDF_ATerms arg, SDF_ATerm head)
{
  if (SDF_isATermsCons(arg)) {
    return (SDF_ATerms)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)head, 0), 2);
  }

  ATabort("ATerms has no Head: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getATermsWsAfterHead(SDF_ATerms arg) */

SDF_Layout SDF_getATermsWsAfterHead(SDF_ATerms arg)
{
  if (SDF_isATermsCons(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("ATerms has no WsAfterHead: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ATerms SDF_setATermsWsAfterHead(SDF_ATerms arg, SDF_Layout wsAfterHead) */

SDF_ATerms SDF_setATermsWsAfterHead(SDF_ATerms arg, SDF_Layout wsAfterHead)
{
  if (SDF_isATermsCons(arg)) {
    return (SDF_ATerms)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterHead, 0), 1), 2);
  }

  ATabort("ATerms has no WsAfterHead: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ATermList accessor implementations */

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
/*{{{  SDF_Layout SDF_getATermListWsAfterBracketOpen(SDF_ATermList arg) */

SDF_Layout SDF_getATermListWsAfterBracketOpen(SDF_ATermList arg)
{
  if (SDF_isATermListEmpty(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isATermListNotEmpty(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("ATermList has no WsAfterBracketOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ATermList SDF_setATermListWsAfterBracketOpen(SDF_ATermList arg, SDF_Layout wsAfterBracketOpen) */

SDF_ATermList SDF_setATermListWsAfterBracketOpen(SDF_ATermList arg, SDF_Layout wsAfterBracketOpen)
{
  if (SDF_isATermListEmpty(arg)) {
    return (SDF_ATermList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterBracketOpen, 0), 1), 2);
  }
  else if (SDF_isATermListNotEmpty(arg)) {
    return (SDF_ATermList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterBracketOpen, 0), 1), 2);
  }

  ATabort("ATermList has no WsAfterBracketOpen: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getATermListWsAfterATerms(SDF_ATermList arg) */

SDF_Layout SDF_getATermListWsAfterATerms(SDF_ATermList arg)
{
  if (SDF_isATermListNotEmpty(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("ATermList has no WsAfterATerms: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ATermList SDF_setATermListWsAfterATerms(SDF_ATermList arg, SDF_Layout wsAfterATerms) */

SDF_ATermList SDF_setATermListWsAfterATerms(SDF_ATermList arg, SDF_Layout wsAfterATerms)
{
  if (SDF_isATermListNotEmpty(arg)) {
    return (SDF_ATermList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterATerms, 0), 3), 2);
  }

  ATabort("ATermList has no WsAfterATerms: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_ATermList SDF_setATermListATerms(SDF_ATermList arg, SDF_ATerms aTerms) */

SDF_ATermList SDF_setATermListATerms(SDF_ATermList arg, SDF_ATerms aTerms)
{
  if (SDF_isATermListNotEmpty(arg)) {
    return (SDF_ATermList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aTerms, 2), 2);
  }

  ATabort("ATermList has no ATerms: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ACon accessor implementations */

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
  return NULL;
}

/*}}}  */
/*{{{  SDF_ACon SDF_setAConIntCon(SDF_ACon arg, SDF_IntCon intCon) */

SDF_ACon SDF_setAConIntCon(SDF_ACon arg, SDF_IntCon intCon)
{
  if (SDF_isAConInt(arg)) {
    return (SDF_ACon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)intCon, 0), 2);
  }

  ATabort("ACon has no IntCon: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_ACon SDF_setAConRealCon(SDF_ACon arg, SDF_RealCon realCon) */

SDF_ACon SDF_setAConRealCon(SDF_ACon arg, SDF_RealCon realCon)
{
  if (SDF_isAConReal(arg)) {
    return (SDF_ACon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)realCon, 0), 2);
  }

  ATabort("ACon has no RealCon: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_AFun accessor implementations */

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
  return NULL;
}

/*}}}  */
/*{{{  SDF_AFun SDF_setAFunLiteral(SDF_AFun arg, SDF_Literal literal) */

SDF_AFun SDF_setAFunLiteral(SDF_AFun arg, SDF_Literal literal)
{
  if (SDF_isAFunDefault(arg)) {
    return (SDF_AFun)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)literal, 0), 2);
  }

  ATabort("AFun has no Literal: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ATerm accessor implementations */

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
/*{{{  ATbool SDF_hasATermWsAfterAFun(SDF_ATerm arg) */

ATbool SDF_hasATermWsAfterAFun(SDF_ATerm arg)
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
/*{{{  SDF_Layout SDF_getATermWsAfterAFun(SDF_ATerm arg) */

SDF_Layout SDF_getATermWsAfterAFun(SDF_ATerm arg)
{
  if (SDF_isATermAppl(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isATermAnnotatedFun(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("ATerm has no WsAfterAFun: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermWsAfterAFun(SDF_ATerm arg, SDF_Layout wsAfterAFun) */

SDF_ATerm SDF_setATermWsAfterAFun(SDF_ATerm arg, SDF_Layout wsAfterAFun)
{
  if (SDF_isATermAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterAFun, 0), 1), 2);
  }
  else if (SDF_isATermAnnotatedFun(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterAFun, 0), 1), 2);
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterAFun, 0), 1), 2);
  }

  ATabort("ATerm has no WsAfterAFun: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getATermWsAfterParenClose(SDF_ATerm arg) */

SDF_Layout SDF_getATermWsAfterParenClose(SDF_ATerm arg)
{
  if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), 0);
  }

  ATabort("ATerm has no WsAfterParenClose: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermWsAfterParenClose(SDF_ATerm arg, SDF_Layout wsAfterParenClose) */

SDF_ATerm SDF_setATermWsAfterParenClose(SDF_ATerm arg, SDF_Layout wsAfterParenClose)
{
  if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), (ATerm)wsAfterParenClose, 0), 7), 2);
  }

  ATabort("ATerm has no WsAfterParenClose: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getATermWsAfterParenOpen(SDF_ATerm arg) */

SDF_Layout SDF_getATermWsAfterParenOpen(SDF_ATerm arg)
{
  if (SDF_isATermAppl(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("ATerm has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermWsAfterParenOpen(SDF_ATerm arg, SDF_Layout wsAfterParenOpen) */

SDF_ATerm SDF_setATermWsAfterParenOpen(SDF_ATerm arg, SDF_Layout wsAfterParenOpen)
{
  if (SDF_isATermAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterParenOpen, 0), 3), 2);
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterParenOpen, 0), 3), 2);
  }

  ATabort("ATerm has no WsAfterParenOpen: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermACon(SDF_ATerm arg, SDF_ACon aCon) */

SDF_ATerm SDF_setATermACon(SDF_ATerm arg, SDF_ACon aCon)
{
  if (SDF_isATermConstant(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aCon, 0), 2);
  }
  else if (SDF_isATermAnnotatedConstant(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aCon, 0), 2);
  }

  ATabort("ATerm has no ACon: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermAnn(SDF_ATerm arg, SDF_Ann ann) */

SDF_ATerm SDF_setATermAnn(SDF_ATerm arg, SDF_Ann ann)
{
  if (SDF_isATermAnnotatedConstant(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ann, 2), 2);
  }
  else if (SDF_isATermAnnotatedList(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ann, 2), 2);
  }
  else if (SDF_isATermAnnotatedFun(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ann, 2), 2);
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ann, 8), 2);
  }

  ATabort("ATerm has no Ann: %t\n", arg);
  return NULL;
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
  return NULL;
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
  return NULL;
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
/*{{{  SDF_Layout SDF_getATermWsAfterACon(SDF_ATerm arg) */

SDF_Layout SDF_getATermWsAfterACon(SDF_ATerm arg)
{
  if (SDF_isATermAnnotatedConstant(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("ATerm has no WsAfterACon: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermWsAfterACon(SDF_ATerm arg, SDF_Layout wsAfterACon) */

SDF_ATerm SDF_setATermWsAfterACon(SDF_ATerm arg, SDF_Layout wsAfterACon)
{
  if (SDF_isATermAnnotatedConstant(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterACon, 0), 1), 2);
  }

  ATabort("ATerm has no WsAfterACon: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getATermWsAfterArgs(SDF_ATerm arg) */

SDF_Layout SDF_getATermWsAfterArgs(SDF_ATerm arg)
{
  if (SDF_isATermAppl(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("ATerm has no WsAfterArgs: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermWsAfterArgs(SDF_ATerm arg, SDF_Layout wsAfterArgs) */

SDF_ATerm SDF_setATermWsAfterArgs(SDF_ATerm arg, SDF_Layout wsAfterArgs)
{
  if (SDF_isATermAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterArgs, 0), 5), 2);
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterArgs, 0), 5), 2);
  }

  ATabort("ATerm has no WsAfterArgs: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermATermList(SDF_ATerm arg) */

ATbool SDF_hasATermATermList(SDF_ATerm arg)
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
/*{{{  SDF_ATermList SDF_getATermATermList(SDF_ATerm arg) */

SDF_ATermList SDF_getATermATermList(SDF_ATerm arg)
{
  if (SDF_isATermList(arg)) {
    return (SDF_ATermList)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDF_isATermAnnotatedList(arg)) {
    return (SDF_ATermList)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("ATerm has no ATermList: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermATermList(SDF_ATerm arg, SDF_ATermList aTermList) */

SDF_ATerm SDF_setATermATermList(SDF_ATerm arg, SDF_ATermList aTermList)
{
  if (SDF_isATermList(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aTermList, 0), 2);
  }
  else if (SDF_isATermAnnotatedList(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aTermList, 0), 2);
  }

  ATabort("ATerm has no ATermList: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermAFun(SDF_ATerm arg) */

ATbool SDF_hasATermAFun(SDF_ATerm arg)
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
/*{{{  SDF_AFun SDF_getATermAFun(SDF_ATerm arg) */

SDF_AFun SDF_getATermAFun(SDF_ATerm arg)
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

  ATabort("ATerm has no AFun: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermAFun(SDF_ATerm arg, SDF_AFun aFun) */

SDF_ATerm SDF_setATermAFun(SDF_ATerm arg, SDF_AFun aFun)
{
  if (SDF_isATermFun(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aFun, 0), 2);
  }
  else if (SDF_isATermAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aFun, 0), 2);
  }
  else if (SDF_isATermAnnotatedFun(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aFun, 0), 2);
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aFun, 0), 2);
  }

  ATabort("ATerm has no AFun: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermWsAfterATermList(SDF_ATerm arg) */

ATbool SDF_hasATermWsAfterATermList(SDF_ATerm arg)
{
  if (SDF_isATermAnnotatedList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getATermWsAfterATermList(SDF_ATerm arg) */

SDF_Layout SDF_getATermWsAfterATermList(SDF_ATerm arg)
{
  if (SDF_isATermAnnotatedList(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("ATerm has no WsAfterATermList: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermWsAfterATermList(SDF_ATerm arg, SDF_Layout wsAfterATermList) */

SDF_ATerm SDF_setATermWsAfterATermList(SDF_ATerm arg, SDF_Layout wsAfterATermList)
{
  if (SDF_isATermAnnotatedList(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterATermList, 0), 1), 2);
  }

  ATabort("ATerm has no WsAfterATermList: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Ann accessor implementations */

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
/*{{{  SDF_Layout SDF_getAnnWsAfterBraceOpen(SDF_Ann arg) */

SDF_Layout SDF_getAnnWsAfterBraceOpen(SDF_Ann arg)
{
  if (SDF_isAnnAnnotation(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Ann has no WsAfterBraceOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Ann SDF_setAnnWsAfterBraceOpen(SDF_Ann arg, SDF_Layout wsAfterBraceOpen) */

SDF_Ann SDF_setAnnWsAfterBraceOpen(SDF_Ann arg, SDF_Layout wsAfterBraceOpen)
{
  if (SDF_isAnnAnnotation(arg)) {
    return (SDF_Ann)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterBraceOpen, 0), 1), 2);
  }

  ATabort("Ann has no WsAfterBraceOpen: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getAnnWsAfterATerms(SDF_Ann arg) */

SDF_Layout SDF_getAnnWsAfterATerms(SDF_Ann arg)
{
  if (SDF_isAnnAnnotation(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Ann has no WsAfterATerms: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_Ann SDF_setAnnWsAfterATerms(SDF_Ann arg, SDF_Layout wsAfterATerms) */

SDF_Ann SDF_setAnnWsAfterATerms(SDF_Ann arg, SDF_Layout wsAfterATerms)
{
  if (SDF_isAnnAnnotation(arg)) {
    return (SDF_Ann)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterATerms, 0), 3), 2);
  }

  ATabort("Ann has no WsAfterATerms: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Ann SDF_setAnnATerms(SDF_Ann arg, SDF_ATerms aTerms) */

SDF_Ann SDF_setAnnATerms(SDF_Ann arg, SDF_ATerms aTerms)
{
  if (SDF_isAnnAnnotation(arg)) {
    return (SDF_Ann)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aTerms, 2), 2);
  }

  ATabort("Ann has no ATerms: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_TagId accessor implementations */

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
/*{{{  SDF_Lexical SDF_getTagIdLex(SDF_TagId arg) */

SDF_Lexical SDF_getTagIdLex(SDF_TagId arg)
{
  if (SDF_isTagIdDefault(arg)) {
    return (SDF_Lexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("TagId has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_TagId SDF_setTagIdLex(SDF_TagId arg, SDF_Lexical lex) */

SDF_TagId SDF_setTagIdLex(SDF_TagId arg, SDF_Lexical lex)
{
  if (SDF_isTagIdDefault(arg)) {
    return (SDF_TagId)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("TagId has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_NumChar accessor implementations */

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
/*{{{  SDF_Lexical SDF_getNumCharLex(SDF_NumChar arg) */

SDF_Lexical SDF_getNumCharLex(SDF_NumChar arg)
{
  if (SDF_isNumCharDigits(arg)) {
    return (SDF_Lexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("NumChar has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_NumChar SDF_setNumCharLex(SDF_NumChar arg, SDF_Lexical lex) */

SDF_NumChar SDF_setNumCharLex(SDF_NumChar arg, SDF_Lexical lex)
{
  if (SDF_isNumCharDigits(arg)) {
    return (SDF_NumChar)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("NumChar has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ShortChar accessor implementations */

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
/*{{{  SDF_Lexical SDF_getShortCharLex(SDF_ShortChar arg) */

SDF_Lexical SDF_getShortCharLex(SDF_ShortChar arg)
{
  if (SDF_isShortCharRegular(arg)) {
    return (SDF_Lexical)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (SDF_isShortCharEscaped(arg)) {
    return (SDF_Lexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("ShortChar has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_ShortChar SDF_setShortCharLex(SDF_ShortChar arg, SDF_Lexical lex) */

SDF_ShortChar SDF_setShortCharLex(SDF_ShortChar arg, SDF_Lexical lex)
{
  if (SDF_isShortCharRegular(arg)) {
    return (SDF_ShortChar)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }
  else if (SDF_isShortCharEscaped(arg)) {
    return (SDF_ShortChar)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("ShortChar has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Character accessor implementations */

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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Character SDF_setCharacterShortChar(SDF_Character arg, SDF_ShortChar shortChar) */

SDF_Character SDF_setCharacterShortChar(SDF_Character arg, SDF_ShortChar shortChar)
{
  if (SDF_isCharacterShort(arg)) {
    return (SDF_Character)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)shortChar, 0), 2);
  }

  ATabort("Character has no ShortChar: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_Character SDF_setCharacterNumChar(SDF_Character arg, SDF_NumChar numChar) */

SDF_Character SDF_setCharacterNumChar(SDF_Character arg, SDF_NumChar numChar)
{
  if (SDF_isCharacterNumeric(arg)) {
    return (SDF_Character)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)numChar, 0), 2);
  }

  ATabort("Character has no NumChar: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_OptExp accessor implementations */

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
/*{{{  SDF_Layout SDF_getOptExpWsAfterE(SDF_OptExp arg) */

SDF_Layout SDF_getOptExpWsAfterE(SDF_OptExp arg)
{
  if (SDF_isOptExpPresent(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("OptExp has no WsAfterE: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_OptExp SDF_setOptExpWsAfterE(SDF_OptExp arg, SDF_Layout wsAfterE) */

SDF_OptExp SDF_setOptExpWsAfterE(SDF_OptExp arg, SDF_Layout wsAfterE)
{
  if (SDF_isOptExpPresent(arg)) {
    return (SDF_OptExp)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterE, 0), 1), 2);
  }

  ATabort("OptExp has no WsAfterE: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_OptExp SDF_setOptExpIntCon(SDF_OptExp arg, SDF_IntCon intCon) */

SDF_OptExp SDF_setOptExpIntCon(SDF_OptExp arg, SDF_IntCon intCon)
{
  if (SDF_isOptExpPresent(arg)) {
    return (SDF_OptExp)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)intCon, 2), 2);
  }

  ATabort("OptExp has no IntCon: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_RealCon accessor implementations */

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
/*{{{  ATbool SDF_hasRealConWsAfterPeriod(SDF_RealCon arg) */

ATbool SDF_hasRealConWsAfterPeriod(SDF_RealCon arg)
{
  if (SDF_isRealConRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Layout SDF_getRealConWsAfterPeriod(SDF_RealCon arg) */

SDF_Layout SDF_getRealConWsAfterPeriod(SDF_RealCon arg)
{
  if (SDF_isRealConRealCon(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("RealCon has no WsAfterPeriod: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_RealCon SDF_setRealConWsAfterPeriod(SDF_RealCon arg, SDF_Layout wsAfterPeriod) */

SDF_RealCon SDF_setRealConWsAfterPeriod(SDF_RealCon arg, SDF_Layout wsAfterPeriod)
{
  if (SDF_isRealConRealCon(arg)) {
    return (SDF_RealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterPeriod, 0), 3), 2);
  }

  ATabort("RealCon has no WsAfterPeriod: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getRealConWsAfterIntCon(SDF_RealCon arg) */

SDF_Layout SDF_getRealConWsAfterIntCon(SDF_RealCon arg)
{
  if (SDF_isRealConRealCon(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("RealCon has no WsAfterIntCon: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_RealCon SDF_setRealConWsAfterIntCon(SDF_RealCon arg, SDF_Layout wsAfterIntCon) */

SDF_RealCon SDF_setRealConWsAfterIntCon(SDF_RealCon arg, SDF_Layout wsAfterIntCon)
{
  if (SDF_isRealConRealCon(arg)) {
    return (SDF_RealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterIntCon, 0), 1), 2);
  }

  ATabort("RealCon has no WsAfterIntCon: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_RealCon SDF_setRealConOptExp(SDF_RealCon arg, SDF_OptExp optExp) */

SDF_RealCon SDF_setRealConOptExp(SDF_RealCon arg, SDF_OptExp optExp)
{
  if (SDF_isRealConRealCon(arg)) {
    return (SDF_RealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)optExp, 6), 2);
  }

  ATabort("RealCon has no OptExp: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_RealCon SDF_setRealConIntCon(SDF_RealCon arg, SDF_IntCon intCon) */

SDF_RealCon SDF_setRealConIntCon(SDF_RealCon arg, SDF_IntCon intCon)
{
  if (SDF_isRealConRealCon(arg)) {
    return (SDF_RealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)intCon, 0), 2);
  }

  ATabort("RealCon has no IntCon: %t\n", arg);
  return NULL;
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
/*{{{  SDF_Layout SDF_getRealConWsAfterNatCon(SDF_RealCon arg) */

SDF_Layout SDF_getRealConWsAfterNatCon(SDF_RealCon arg)
{
  if (SDF_isRealConRealCon(arg)) {
    return (SDF_Layout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("RealCon has no WsAfterNatCon: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDF_RealCon SDF_setRealConWsAfterNatCon(SDF_RealCon arg, SDF_Layout wsAfterNatCon) */

SDF_RealCon SDF_setRealConWsAfterNatCon(SDF_RealCon arg, SDF_Layout wsAfterNatCon)
{
  if (SDF_isRealConRealCon(arg)) {
    return (SDF_RealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterNatCon, 0), 5), 2);
  }

  ATabort("RealCon has no WsAfterNatCon: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  SDF_RealCon SDF_setRealConNatCon(SDF_RealCon arg, SDF_NatCon natCon) */

SDF_RealCon SDF_setRealConNatCon(SDF_RealCon arg, SDF_NatCon natCon)
{
  if (SDF_isRealConRealCon(arg)) {
    return (SDF_RealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)natCon, 4), 2);
  }

  ATabort("RealCon has no NatCon: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
