#include <aterm2.h>
#include <deprecated.h>
#include "SDF.h"

/*{{{  typedefs */

typedef struct ATerm _SDFSymbol;
typedef struct ATerm _SDFGrammar;
typedef struct ATerm _SDFSDF;
typedef struct ATerm _SDFAttributes;
typedef struct ATerm _SDFAttributeAttributes;
typedef struct ATerm _SDFProduction;
typedef struct ATerm _SDFProductions;
typedef struct ATerm _SDFProductionProductions;
typedef struct ATerm _SDFModuleWord;
typedef struct ATerm _SDFModuleId;
typedef struct ATerm _SDFDefinition;
typedef struct ATerm _SDFModuleModules;
typedef struct ATerm _SDFModule;
typedef struct ATerm _SDFImpSectionList;
typedef struct ATerm _SDFSection;
typedef struct ATerm _SDFSections;
typedef struct ATerm _SDFSectionList;
typedef struct ATerm _SDFModuleName;
typedef struct ATerm _SDFAttribute;
typedef struct ATerm _SDFImpSection;
typedef struct ATerm _SDFImports;
typedef struct ATerm _SDFImportList;
typedef struct ATerm _SDFImport;
typedef struct ATerm _SDFSymbolTail;
typedef struct ATerm _SDFAssociativity;
typedef struct ATerm _SDFGroup;
typedef struct ATerm _SDFPriority;
typedef struct ATerm _SDFGroupGroupp;
typedef struct ATerm _SDFPriorities;
typedef struct ATerm _SDFPriorityPrioritys;
typedef struct ATerm _SDFSort;
typedef struct ATerm _SDFUQLiteral;
typedef struct ATerm _SDFLiteral;
typedef struct ATerm _SDFSymbolArguments;
typedef struct ATerm _SDFLookahead;
typedef struct ATerm _SDFLookaheads;
typedef struct ATerm _SDFLookaheadLookaheads;
typedef struct ATerm _SDFRestriction;
typedef struct ATerm _SDFRestrictions;
typedef struct ATerm _SDFRestrictionRestrictions;
typedef struct ATerm _SDFAlias;
typedef struct ATerm _SDFAliases;
typedef struct ATerm _SDFAliasAliass;
typedef struct ATerm _SDFSymbols;
typedef struct ATerm _SDFSymbolSymbols;
typedef struct ATerm _SDFRenamings;
typedef struct ATerm _SDFRenamingRenamings;
typedef struct ATerm _SDFRenaming;
typedef struct ATerm _SDFNatCon;
typedef struct ATerm _SDFIntCon;
typedef struct ATerm _SDFCharRange;
typedef struct ATerm _SDFCharRanges;
typedef struct ATerm _SDFOptCharRanges;
typedef struct ATerm _SDFCharClass;
typedef struct ATerm _SDFAlphaNumericalEscChar;
typedef struct ATerm _SDFDecimalEscChar;
typedef struct ATerm _SDFEscChar;
typedef struct ATerm _SDFLChar;
typedef struct ATerm _SDFATerms;
typedef struct ATerm _SDFATermList;
typedef struct ATerm _SDFACon;
typedef struct ATerm _SDFAFun;
typedef struct ATerm _SDFATerm;
typedef struct ATerm _SDFAnn;
typedef struct ATerm _SDFTagId;
typedef struct ATerm _SDFNumChar;
typedef struct ATerm _SDFShortChar;
typedef struct ATerm _SDFCharacter;
typedef struct ATerm _SDFOptExp;
typedef struct ATerm _SDFRealCon;

/*}}}  */

/*{{{  void SDFinitSDFApi(void) */

void SDFinitSDFApi(void)
{
  init_SDF_dict();
}

/*}}}  */

/*{{{  SDFSymbol SDFmakeSymbolFromTerm(ATerm t) */

SDFSymbol SDFmakeSymbolFromTerm(ATerm t)
{
  return (SDFSymbol)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromSymbol(SDFSymbol arg) */

ATerm SDFmakeTermFromSymbol(SDFSymbol arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFGrammar SDFmakeGrammarFromTerm(ATerm t) */

SDFGrammar SDFmakeGrammarFromTerm(ATerm t)
{
  return (SDFGrammar)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromGrammar(SDFGrammar arg) */

ATerm SDFmakeTermFromGrammar(SDFGrammar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFSDF SDFmakeSDFFromTerm(ATerm t) */

SDFSDF SDFmakeSDFFromTerm(ATerm t)
{
  return (SDFSDF)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromSDF(SDFSDF arg) */

ATerm SDFmakeTermFromSDF(SDFSDF arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFAttributes SDFmakeAttributesFromTerm(ATerm t) */

SDFAttributes SDFmakeAttributesFromTerm(ATerm t)
{
  return (SDFAttributes)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromAttributes(SDFAttributes arg) */

ATerm SDFmakeTermFromAttributes(SDFAttributes arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFAttributeAttributes SDFmakeAttributeAttributesFromTerm(ATerm t) */

SDFAttributeAttributes SDFmakeAttributeAttributesFromTerm(ATerm t)
{
  return (SDFAttributeAttributes)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromAttributeAttributes(SDFAttributeAttributes arg) */

ATerm SDFmakeTermFromAttributeAttributes(SDFAttributeAttributes arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFProduction SDFmakeProductionFromTerm(ATerm t) */

SDFProduction SDFmakeProductionFromTerm(ATerm t)
{
  return (SDFProduction)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromProduction(SDFProduction arg) */

ATerm SDFmakeTermFromProduction(SDFProduction arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFProductions SDFmakeProductionsFromTerm(ATerm t) */

SDFProductions SDFmakeProductionsFromTerm(ATerm t)
{
  return (SDFProductions)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromProductions(SDFProductions arg) */

ATerm SDFmakeTermFromProductions(SDFProductions arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFProductionProductions SDFmakeProductionProductionsFromTerm(ATerm t) */

SDFProductionProductions SDFmakeProductionProductionsFromTerm(ATerm t)
{
  return (SDFProductionProductions)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromProductionProductions(SDFProductionProductions arg) */

ATerm SDFmakeTermFromProductionProductions(SDFProductionProductions arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFModuleWord SDFmakeModuleWordFromTerm(ATerm t) */

SDFModuleWord SDFmakeModuleWordFromTerm(ATerm t)
{
  return (SDFModuleWord)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromModuleWord(SDFModuleWord arg) */

ATerm SDFmakeTermFromModuleWord(SDFModuleWord arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFModuleId SDFmakeModuleIdFromTerm(ATerm t) */

SDFModuleId SDFmakeModuleIdFromTerm(ATerm t)
{
  return (SDFModuleId)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromModuleId(SDFModuleId arg) */

ATerm SDFmakeTermFromModuleId(SDFModuleId arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFDefinition SDFmakeDefinitionFromTerm(ATerm t) */

SDFDefinition SDFmakeDefinitionFromTerm(ATerm t)
{
  return (SDFDefinition)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromDefinition(SDFDefinition arg) */

ATerm SDFmakeTermFromDefinition(SDFDefinition arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFModuleModules SDFmakeModuleModulesFromTerm(ATerm t) */

SDFModuleModules SDFmakeModuleModulesFromTerm(ATerm t)
{
  return (SDFModuleModules)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromModuleModules(SDFModuleModules arg) */

ATerm SDFmakeTermFromModuleModules(SDFModuleModules arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFModule SDFmakeModuleFromTerm(ATerm t) */

SDFModule SDFmakeModuleFromTerm(ATerm t)
{
  return (SDFModule)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromModule(SDFModule arg) */

ATerm SDFmakeTermFromModule(SDFModule arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFImpSectionList SDFmakeImpSectionListFromTerm(ATerm t) */

SDFImpSectionList SDFmakeImpSectionListFromTerm(ATerm t)
{
  return (SDFImpSectionList)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromImpSectionList(SDFImpSectionList arg) */

ATerm SDFmakeTermFromImpSectionList(SDFImpSectionList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFSection SDFmakeSectionFromTerm(ATerm t) */

SDFSection SDFmakeSectionFromTerm(ATerm t)
{
  return (SDFSection)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromSection(SDFSection arg) */

ATerm SDFmakeTermFromSection(SDFSection arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFSections SDFmakeSectionsFromTerm(ATerm t) */

SDFSections SDFmakeSectionsFromTerm(ATerm t)
{
  return (SDFSections)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromSections(SDFSections arg) */

ATerm SDFmakeTermFromSections(SDFSections arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFSectionList SDFmakeSectionListFromTerm(ATerm t) */

SDFSectionList SDFmakeSectionListFromTerm(ATerm t)
{
  return (SDFSectionList)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromSectionList(SDFSectionList arg) */

ATerm SDFmakeTermFromSectionList(SDFSectionList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFModuleName SDFmakeModuleNameFromTerm(ATerm t) */

SDFModuleName SDFmakeModuleNameFromTerm(ATerm t)
{
  return (SDFModuleName)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromModuleName(SDFModuleName arg) */

ATerm SDFmakeTermFromModuleName(SDFModuleName arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFAttribute SDFmakeAttributeFromTerm(ATerm t) */

SDFAttribute SDFmakeAttributeFromTerm(ATerm t)
{
  return (SDFAttribute)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromAttribute(SDFAttribute arg) */

ATerm SDFmakeTermFromAttribute(SDFAttribute arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFImpSection SDFmakeImpSectionFromTerm(ATerm t) */

SDFImpSection SDFmakeImpSectionFromTerm(ATerm t)
{
  return (SDFImpSection)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromImpSection(SDFImpSection arg) */

ATerm SDFmakeTermFromImpSection(SDFImpSection arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFImports SDFmakeImportsFromTerm(ATerm t) */

SDFImports SDFmakeImportsFromTerm(ATerm t)
{
  return (SDFImports)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromImports(SDFImports arg) */

ATerm SDFmakeTermFromImports(SDFImports arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFImportList SDFmakeImportListFromTerm(ATerm t) */

SDFImportList SDFmakeImportListFromTerm(ATerm t)
{
  return (SDFImportList)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromImportList(SDFImportList arg) */

ATerm SDFmakeTermFromImportList(SDFImportList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFImport SDFmakeImportFromTerm(ATerm t) */

SDFImport SDFmakeImportFromTerm(ATerm t)
{
  return (SDFImport)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromImport(SDFImport arg) */

ATerm SDFmakeTermFromImport(SDFImport arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFSymbolTail SDFmakeSymbolTailFromTerm(ATerm t) */

SDFSymbolTail SDFmakeSymbolTailFromTerm(ATerm t)
{
  return (SDFSymbolTail)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromSymbolTail(SDFSymbolTail arg) */

ATerm SDFmakeTermFromSymbolTail(SDFSymbolTail arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFAssociativity SDFmakeAssociativityFromTerm(ATerm t) */

SDFAssociativity SDFmakeAssociativityFromTerm(ATerm t)
{
  return (SDFAssociativity)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromAssociativity(SDFAssociativity arg) */

ATerm SDFmakeTermFromAssociativity(SDFAssociativity arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFGroup SDFmakeGroupFromTerm(ATerm t) */

SDFGroup SDFmakeGroupFromTerm(ATerm t)
{
  return (SDFGroup)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromGroup(SDFGroup arg) */

ATerm SDFmakeTermFromGroup(SDFGroup arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFPriority SDFmakePriorityFromTerm(ATerm t) */

SDFPriority SDFmakePriorityFromTerm(ATerm t)
{
  return (SDFPriority)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromPriority(SDFPriority arg) */

ATerm SDFmakeTermFromPriority(SDFPriority arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFGroupGroupp SDFmakeGroupGrouppFromTerm(ATerm t) */

SDFGroupGroupp SDFmakeGroupGrouppFromTerm(ATerm t)
{
  return (SDFGroupGroupp)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromGroupGroupp(SDFGroupGroupp arg) */

ATerm SDFmakeTermFromGroupGroupp(SDFGroupGroupp arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFPriorities SDFmakePrioritiesFromTerm(ATerm t) */

SDFPriorities SDFmakePrioritiesFromTerm(ATerm t)
{
  return (SDFPriorities)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromPriorities(SDFPriorities arg) */

ATerm SDFmakeTermFromPriorities(SDFPriorities arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFPriorityPrioritys SDFmakePriorityPrioritysFromTerm(ATerm t) */

SDFPriorityPrioritys SDFmakePriorityPrioritysFromTerm(ATerm t)
{
  return (SDFPriorityPrioritys)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromPriorityPrioritys(SDFPriorityPrioritys arg) */

ATerm SDFmakeTermFromPriorityPrioritys(SDFPriorityPrioritys arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFSort SDFmakeSortFromTerm(ATerm t) */

SDFSort SDFmakeSortFromTerm(ATerm t)
{
  return (SDFSort)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromSort(SDFSort arg) */

ATerm SDFmakeTermFromSort(SDFSort arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFUQLiteral SDFmakeUQLiteralFromTerm(ATerm t) */

SDFUQLiteral SDFmakeUQLiteralFromTerm(ATerm t)
{
  return (SDFUQLiteral)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromUQLiteral(SDFUQLiteral arg) */

ATerm SDFmakeTermFromUQLiteral(SDFUQLiteral arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFLiteral SDFmakeLiteralFromTerm(ATerm t) */

SDFLiteral SDFmakeLiteralFromTerm(ATerm t)
{
  return (SDFLiteral)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromLiteral(SDFLiteral arg) */

ATerm SDFmakeTermFromLiteral(SDFLiteral arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFSymbolArguments SDFmakeSymbolArgumentsFromTerm(ATerm t) */

SDFSymbolArguments SDFmakeSymbolArgumentsFromTerm(ATerm t)
{
  return (SDFSymbolArguments)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromSymbolArguments(SDFSymbolArguments arg) */

ATerm SDFmakeTermFromSymbolArguments(SDFSymbolArguments arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFLookahead SDFmakeLookaheadFromTerm(ATerm t) */

SDFLookahead SDFmakeLookaheadFromTerm(ATerm t)
{
  return (SDFLookahead)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromLookahead(SDFLookahead arg) */

ATerm SDFmakeTermFromLookahead(SDFLookahead arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFLookaheads SDFmakeLookaheadsFromTerm(ATerm t) */

SDFLookaheads SDFmakeLookaheadsFromTerm(ATerm t)
{
  return (SDFLookaheads)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromLookaheads(SDFLookaheads arg) */

ATerm SDFmakeTermFromLookaheads(SDFLookaheads arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFLookaheadLookaheads SDFmakeLookaheadLookaheadsFromTerm(ATerm t) */

SDFLookaheadLookaheads SDFmakeLookaheadLookaheadsFromTerm(ATerm t)
{
  return (SDFLookaheadLookaheads)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromLookaheadLookaheads(SDFLookaheadLookaheads arg) */

ATerm SDFmakeTermFromLookaheadLookaheads(SDFLookaheadLookaheads arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFRestriction SDFmakeRestrictionFromTerm(ATerm t) */

SDFRestriction SDFmakeRestrictionFromTerm(ATerm t)
{
  return (SDFRestriction)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromRestriction(SDFRestriction arg) */

ATerm SDFmakeTermFromRestriction(SDFRestriction arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFRestrictions SDFmakeRestrictionsFromTerm(ATerm t) */

SDFRestrictions SDFmakeRestrictionsFromTerm(ATerm t)
{
  return (SDFRestrictions)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromRestrictions(SDFRestrictions arg) */

ATerm SDFmakeTermFromRestrictions(SDFRestrictions arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFRestrictionRestrictions SDFmakeRestrictionRestrictionsFromTerm(ATerm t) */

SDFRestrictionRestrictions SDFmakeRestrictionRestrictionsFromTerm(ATerm t)
{
  return (SDFRestrictionRestrictions)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromRestrictionRestrictions(SDFRestrictionRestrictions arg) */

ATerm SDFmakeTermFromRestrictionRestrictions(SDFRestrictionRestrictions arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFAlias SDFmakeAliasFromTerm(ATerm t) */

SDFAlias SDFmakeAliasFromTerm(ATerm t)
{
  return (SDFAlias)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromAlias(SDFAlias arg) */

ATerm SDFmakeTermFromAlias(SDFAlias arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFAliases SDFmakeAliasesFromTerm(ATerm t) */

SDFAliases SDFmakeAliasesFromTerm(ATerm t)
{
  return (SDFAliases)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromAliases(SDFAliases arg) */

ATerm SDFmakeTermFromAliases(SDFAliases arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFAliasAliass SDFmakeAliasAliassFromTerm(ATerm t) */

SDFAliasAliass SDFmakeAliasAliassFromTerm(ATerm t)
{
  return (SDFAliasAliass)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromAliasAliass(SDFAliasAliass arg) */

ATerm SDFmakeTermFromAliasAliass(SDFAliasAliass arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFSymbols SDFmakeSymbolsFromTerm(ATerm t) */

SDFSymbols SDFmakeSymbolsFromTerm(ATerm t)
{
  return (SDFSymbols)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromSymbols(SDFSymbols arg) */

ATerm SDFmakeTermFromSymbols(SDFSymbols arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFSymbolSymbols SDFmakeSymbolSymbolsFromTerm(ATerm t) */

SDFSymbolSymbols SDFmakeSymbolSymbolsFromTerm(ATerm t)
{
  return (SDFSymbolSymbols)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromSymbolSymbols(SDFSymbolSymbols arg) */

ATerm SDFmakeTermFromSymbolSymbols(SDFSymbolSymbols arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFRenamings SDFmakeRenamingsFromTerm(ATerm t) */

SDFRenamings SDFmakeRenamingsFromTerm(ATerm t)
{
  return (SDFRenamings)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromRenamings(SDFRenamings arg) */

ATerm SDFmakeTermFromRenamings(SDFRenamings arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFRenamingRenamings SDFmakeRenamingRenamingsFromTerm(ATerm t) */

SDFRenamingRenamings SDFmakeRenamingRenamingsFromTerm(ATerm t)
{
  return (SDFRenamingRenamings)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromRenamingRenamings(SDFRenamingRenamings arg) */

ATerm SDFmakeTermFromRenamingRenamings(SDFRenamingRenamings arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFRenaming SDFmakeRenamingFromTerm(ATerm t) */

SDFRenaming SDFmakeRenamingFromTerm(ATerm t)
{
  return (SDFRenaming)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromRenaming(SDFRenaming arg) */

ATerm SDFmakeTermFromRenaming(SDFRenaming arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFNatCon SDFmakeNatConFromTerm(ATerm t) */

SDFNatCon SDFmakeNatConFromTerm(ATerm t)
{
  return (SDFNatCon)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromNatCon(SDFNatCon arg) */

ATerm SDFmakeTermFromNatCon(SDFNatCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFIntCon SDFmakeIntConFromTerm(ATerm t) */

SDFIntCon SDFmakeIntConFromTerm(ATerm t)
{
  return (SDFIntCon)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromIntCon(SDFIntCon arg) */

ATerm SDFmakeTermFromIntCon(SDFIntCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFCharRange SDFmakeCharRangeFromTerm(ATerm t) */

SDFCharRange SDFmakeCharRangeFromTerm(ATerm t)
{
  return (SDFCharRange)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromCharRange(SDFCharRange arg) */

ATerm SDFmakeTermFromCharRange(SDFCharRange arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFCharRanges SDFmakeCharRangesFromTerm(ATerm t) */

SDFCharRanges SDFmakeCharRangesFromTerm(ATerm t)
{
  return (SDFCharRanges)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromCharRanges(SDFCharRanges arg) */

ATerm SDFmakeTermFromCharRanges(SDFCharRanges arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFOptCharRanges SDFmakeOptCharRangesFromTerm(ATerm t) */

SDFOptCharRanges SDFmakeOptCharRangesFromTerm(ATerm t)
{
  return (SDFOptCharRanges)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromOptCharRanges(SDFOptCharRanges arg) */

ATerm SDFmakeTermFromOptCharRanges(SDFOptCharRanges arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFCharClass SDFmakeCharClassFromTerm(ATerm t) */

SDFCharClass SDFmakeCharClassFromTerm(ATerm t)
{
  return (SDFCharClass)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromCharClass(SDFCharClass arg) */

ATerm SDFmakeTermFromCharClass(SDFCharClass arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFAlphaNumericalEscChar SDFmakeAlphaNumericalEscCharFromTerm(ATerm t) */

SDFAlphaNumericalEscChar SDFmakeAlphaNumericalEscCharFromTerm(ATerm t)
{
  return (SDFAlphaNumericalEscChar)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromAlphaNumericalEscChar(SDFAlphaNumericalEscChar arg) */

ATerm SDFmakeTermFromAlphaNumericalEscChar(SDFAlphaNumericalEscChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFDecimalEscChar SDFmakeDecimalEscCharFromTerm(ATerm t) */

SDFDecimalEscChar SDFmakeDecimalEscCharFromTerm(ATerm t)
{
  return (SDFDecimalEscChar)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromDecimalEscChar(SDFDecimalEscChar arg) */

ATerm SDFmakeTermFromDecimalEscChar(SDFDecimalEscChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFEscChar SDFmakeEscCharFromTerm(ATerm t) */

SDFEscChar SDFmakeEscCharFromTerm(ATerm t)
{
  return (SDFEscChar)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromEscChar(SDFEscChar arg) */

ATerm SDFmakeTermFromEscChar(SDFEscChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFLChar SDFmakeLCharFromTerm(ATerm t) */

SDFLChar SDFmakeLCharFromTerm(ATerm t)
{
  return (SDFLChar)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromLChar(SDFLChar arg) */

ATerm SDFmakeTermFromLChar(SDFLChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFATerms SDFmakeATermsFromTerm(ATerm t) */

SDFATerms SDFmakeATermsFromTerm(ATerm t)
{
  return (SDFATerms)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromATerms(SDFATerms arg) */

ATerm SDFmakeTermFromATerms(SDFATerms arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFATermList SDFmakeATermListFromTerm(ATerm t) */

SDFATermList SDFmakeATermListFromTerm(ATerm t)
{
  return (SDFATermList)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromATermList(SDFATermList arg) */

ATerm SDFmakeTermFromATermList(SDFATermList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFACon SDFmakeAConFromTerm(ATerm t) */

SDFACon SDFmakeAConFromTerm(ATerm t)
{
  return (SDFACon)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromACon(SDFACon arg) */

ATerm SDFmakeTermFromACon(SDFACon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFAFun SDFmakeAFunFromTerm(ATerm t) */

SDFAFun SDFmakeAFunFromTerm(ATerm t)
{
  return (SDFAFun)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromAFun(SDFAFun arg) */

ATerm SDFmakeTermFromAFun(SDFAFun arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFATerm SDFmakeATermFromTerm(ATerm t) */

SDFATerm SDFmakeATermFromTerm(ATerm t)
{
  return (SDFATerm)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromATerm(SDFATerm arg) */

ATerm SDFmakeTermFromATerm(SDFATerm arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFAnn SDFmakeAnnFromTerm(ATerm t) */

SDFAnn SDFmakeAnnFromTerm(ATerm t)
{
  return (SDFAnn)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromAnn(SDFAnn arg) */

ATerm SDFmakeTermFromAnn(SDFAnn arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFTagId SDFmakeTagIdFromTerm(ATerm t) */

SDFTagId SDFmakeTagIdFromTerm(ATerm t)
{
  return (SDFTagId)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromTagId(SDFTagId arg) */

ATerm SDFmakeTermFromTagId(SDFTagId arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFNumChar SDFmakeNumCharFromTerm(ATerm t) */

SDFNumChar SDFmakeNumCharFromTerm(ATerm t)
{
  return (SDFNumChar)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromNumChar(SDFNumChar arg) */

ATerm SDFmakeTermFromNumChar(SDFNumChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFShortChar SDFmakeShortCharFromTerm(ATerm t) */

SDFShortChar SDFmakeShortCharFromTerm(ATerm t)
{
  return (SDFShortChar)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromShortChar(SDFShortChar arg) */

ATerm SDFmakeTermFromShortChar(SDFShortChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFCharacter SDFmakeCharacterFromTerm(ATerm t) */

SDFCharacter SDFmakeCharacterFromTerm(ATerm t)
{
  return (SDFCharacter)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromCharacter(SDFCharacter arg) */

ATerm SDFmakeTermFromCharacter(SDFCharacter arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFOptExp SDFmakeOptExpFromTerm(ATerm t) */

SDFOptExp SDFmakeOptExpFromTerm(ATerm t)
{
  return (SDFOptExp)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromOptExp(SDFOptExp arg) */

ATerm SDFmakeTermFromOptExp(SDFOptExp arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDFRealCon SDFmakeRealConFromTerm(ATerm t) */

SDFRealCon SDFmakeRealConFromTerm(ATerm t)
{
  return (SDFRealCon)t;
}

/*}}}  */
/*{{{  ATerm SDFmakeTermFromRealCon(SDFRealCon arg) */

ATerm SDFmakeTermFromRealCon(SDFRealCon arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*{{{  SDFSymbol SDFmakeSymbolStart() */

SDFSymbol SDFmakeSymbolStart()
{
  return (SDFSymbol)ATmakeTerm(SDFpatternSymbolStart);
}

/*}}}  */
/*{{{  SDFSymbol SDFmakeSymbolFileStart() */

SDFSymbol SDFmakeSymbolFileStart()
{
  return (SDFSymbol)ATmakeTerm(SDFpatternSymbolFileStart);
}

/*}}}  */
/*{{{  SDFSymbol SDFmakeSymbolCf(SDFLayout wsAfterLessThan, SDFSymbol symbol, SDFLayout wsAfterSymbol, SDFLayout wsAfterCF) */

SDFSymbol SDFmakeSymbolCf(SDFLayout wsAfterLessThan, SDFSymbol symbol, SDFLayout wsAfterSymbol, SDFLayout wsAfterCF)
{
  return (SDFSymbol)ATmakeTerm(SDFpatternSymbolCf, wsAfterLessThan, symbol, wsAfterSymbol, wsAfterCF);
}

/*}}}  */
/*{{{  SDFSymbol SDFmakeSymbolLex(SDFLayout wsAfterLessThan, SDFSymbol symbol, SDFLayout wsAfterSymbol, SDFLayout wsAfterLEX) */

SDFSymbol SDFmakeSymbolLex(SDFLayout wsAfterLessThan, SDFSymbol symbol, SDFLayout wsAfterSymbol, SDFLayout wsAfterLEX)
{
  return (SDFSymbol)ATmakeTerm(SDFpatternSymbolLex, wsAfterLessThan, symbol, wsAfterSymbol, wsAfterLEX);
}

/*}}}  */
/*{{{  SDFSymbol SDFmakeSymbolVarsym(SDFLayout wsAfterLessThan, SDFSymbol symbol, SDFLayout wsAfterSymbol, SDFLayout wsAfterVAR) */

SDFSymbol SDFmakeSymbolVarsym(SDFLayout wsAfterLessThan, SDFSymbol symbol, SDFLayout wsAfterSymbol, SDFLayout wsAfterVAR)
{
  return (SDFSymbol)ATmakeTerm(SDFpatternSymbolVarsym, wsAfterLessThan, symbol, wsAfterSymbol, wsAfterVAR);
}

/*}}}  */
/*{{{  SDFSymbol SDFmakeSymbolLayout() */

SDFSymbol SDFmakeSymbolLayout()
{
  return (SDFSymbol)ATmakeTerm(SDFpatternSymbolLayout);
}

/*}}}  */
/*{{{  SDFSymbol SDFmakeSymbolEmpty(SDFLayout wsAfterParenOpen) */

SDFSymbol SDFmakeSymbolEmpty(SDFLayout wsAfterParenOpen)
{
  return (SDFSymbol)ATmakeTerm(SDFpatternSymbolEmpty, wsAfterParenOpen);
}

/*}}}  */
/*{{{  SDFSymbol SDFmakeSymbolSeq(SDFLayout wsAfterParenOpen, SDFSymbol head, SDFLayout wsAfterHead, SDFSymbolTail tail, SDFLayout wsAfterTail) */

SDFSymbol SDFmakeSymbolSeq(SDFLayout wsAfterParenOpen, SDFSymbol head, SDFLayout wsAfterHead, SDFSymbolTail tail, SDFLayout wsAfterTail)
{
  return (SDFSymbol)ATmakeTerm(SDFpatternSymbolSeq, wsAfterParenOpen, head, wsAfterHead, tail, wsAfterTail);
}

/*}}}  */
/*{{{  SDFSymbol SDFmakeSymbolOpt(SDFSymbol symbol, SDFLayout wsAfterSymbol) */

SDFSymbol SDFmakeSymbolOpt(SDFSymbol symbol, SDFLayout wsAfterSymbol)
{
  return (SDFSymbol)ATmakeTerm(SDFpatternSymbolOpt, symbol, wsAfterSymbol);
}

/*}}}  */
/*{{{  SDFSymbol SDFmakeSymbolIter(SDFSymbol symbol, SDFLayout wsAfterSymbol) */

SDFSymbol SDFmakeSymbolIter(SDFSymbol symbol, SDFLayout wsAfterSymbol)
{
  return (SDFSymbol)ATmakeTerm(SDFpatternSymbolIter, symbol, wsAfterSymbol);
}

/*}}}  */
/*{{{  SDFSymbol SDFmakeSymbolIterStar(SDFSymbol symbol, SDFLayout wsAfterSymbol) */

SDFSymbol SDFmakeSymbolIterStar(SDFSymbol symbol, SDFLayout wsAfterSymbol)
{
  return (SDFSymbol)ATmakeTerm(SDFpatternSymbolIterStar, symbol, wsAfterSymbol);
}

/*}}}  */
/*{{{  SDFSymbol SDFmakeSymbolIterSep(SDFLayout wsAfterBraceOpen, SDFSymbol symbol, SDFLayout wsAfterSymbol, SDFSymbol sep, SDFLayout wsAfterSep, SDFLayout wsAfterBraceClose) */

SDFSymbol SDFmakeSymbolIterSep(SDFLayout wsAfterBraceOpen, SDFSymbol symbol, SDFLayout wsAfterSymbol, SDFSymbol sep, SDFLayout wsAfterSep, SDFLayout wsAfterBraceClose)
{
  return (SDFSymbol)ATmakeTerm(SDFpatternSymbolIterSep, wsAfterBraceOpen, symbol, wsAfterSymbol, sep, wsAfterSep, wsAfterBraceClose);
}

/*}}}  */
/*{{{  SDFSymbol SDFmakeSymbolIterStarSep(SDFLayout wsAfterBraceOpen, SDFSymbol symbol, SDFLayout wsAfterSymbol, SDFSymbol sep, SDFLayout wsAfterSep, SDFLayout wsAfterBraceClose) */

SDFSymbol SDFmakeSymbolIterStarSep(SDFLayout wsAfterBraceOpen, SDFSymbol symbol, SDFLayout wsAfterSymbol, SDFSymbol sep, SDFLayout wsAfterSep, SDFLayout wsAfterBraceClose)
{
  return (SDFSymbol)ATmakeTerm(SDFpatternSymbolIterStarSep, wsAfterBraceOpen, symbol, wsAfterSymbol, sep, wsAfterSep, wsAfterBraceClose);
}

/*}}}  */
/*{{{  SDFSymbol SDFmakeSymbolIterN(SDFSymbol symbol, SDFLayout wsAfterSymbol, SDFNatCon n, SDFLayout wsAfterN) */

SDFSymbol SDFmakeSymbolIterN(SDFSymbol symbol, SDFLayout wsAfterSymbol, SDFNatCon n, SDFLayout wsAfterN)
{
  return (SDFSymbol)ATmakeTerm(SDFpatternSymbolIterN, symbol, wsAfterSymbol, n, wsAfterN);
}

/*}}}  */
/*{{{  SDFSymbol SDFmakeSymbolIterSepN(SDFLayout wsAfterBraceOpen, SDFSymbol symbol, SDFLayout wsAfterSymbol, SDFSymbol sep, SDFLayout wsAfterSep, SDFLayout wsAfterBraceClose, SDFNatCon n, SDFLayout wsAfterN) */

SDFSymbol SDFmakeSymbolIterSepN(SDFLayout wsAfterBraceOpen, SDFSymbol symbol, SDFLayout wsAfterSymbol, SDFSymbol sep, SDFLayout wsAfterSep, SDFLayout wsAfterBraceClose, SDFNatCon n, SDFLayout wsAfterN)
{
  return (SDFSymbol)ATmakeTerm(SDFpatternSymbolIterSepN, wsAfterBraceOpen, symbol, wsAfterSymbol, sep, wsAfterSep, wsAfterBraceClose, n, wsAfterN);
}

/*}}}  */
/*{{{  SDFSymbol SDFmakeSymbolSet(SDFLayout wsAfterSet, SDFLayout wsAfterBracketOpen, SDFSymbol symbol, SDFLayout wsAfterSymbol) */

SDFSymbol SDFmakeSymbolSet(SDFLayout wsAfterSet, SDFLayout wsAfterBracketOpen, SDFSymbol symbol, SDFLayout wsAfterSymbol)
{
  return (SDFSymbol)ATmakeTerm(SDFpatternSymbolSet, wsAfterSet, wsAfterBracketOpen, symbol, wsAfterSymbol);
}

/*}}}  */
/*{{{  SDFSymbol SDFmakeSymbolPair(SDFSymbol left, SDFLayout wsAfterLeft, SDFLayout wsAfterHash, SDFSymbol right) */

SDFSymbol SDFmakeSymbolPair(SDFSymbol left, SDFLayout wsAfterLeft, SDFLayout wsAfterHash, SDFSymbol right)
{
  return (SDFSymbol)ATmakeTerm(SDFpatternSymbolPair, left, wsAfterLeft, wsAfterHash, right);
}

/*}}}  */
/*{{{  SDFSymbol SDFmakeSymbolFunc(SDFLayout wsAfterParenOpen, SDFSymbols arguments, SDFLayout wsAfterArguments, SDFLayout wsAfterEqualsGreaterThan, SDFSymbol results, SDFLayout wsAfterResults) */

SDFSymbol SDFmakeSymbolFunc(SDFLayout wsAfterParenOpen, SDFSymbols arguments, SDFLayout wsAfterArguments, SDFLayout wsAfterEqualsGreaterThan, SDFSymbol results, SDFLayout wsAfterResults)
{
  return (SDFSymbol)ATmakeTerm(SDFpatternSymbolFunc, wsAfterParenOpen, arguments, wsAfterArguments, wsAfterEqualsGreaterThan, results, wsAfterResults);
}

/*}}}  */
/*{{{  SDFSymbol SDFmakeSymbolAlt(SDFSymbol left, SDFLayout wsAfterLeft, SDFLayout wsAfterBar, SDFSymbol right) */

SDFSymbol SDFmakeSymbolAlt(SDFSymbol left, SDFLayout wsAfterLeft, SDFLayout wsAfterBar, SDFSymbol right)
{
  return (SDFSymbol)ATmakeTerm(SDFpatternSymbolAlt, left, wsAfterLeft, wsAfterBar, right);
}

/*}}}  */
/*{{{  SDFSymbol SDFmakeSymbolPerm(SDFLayout wsAfterLessThanLessThan, SDFSymbols symbols, SDFLayout wsAfterSymbols) */

SDFSymbol SDFmakeSymbolPerm(SDFLayout wsAfterLessThanLessThan, SDFSymbols symbols, SDFLayout wsAfterSymbols)
{
  return (SDFSymbol)ATmakeTerm(SDFpatternSymbolPerm, wsAfterLessThanLessThan, symbols, wsAfterSymbols);
}

/*}}}  */
/*{{{  SDFSymbol SDFmakeSymbolCharClass(SDFCharClass charClass) */

SDFSymbol SDFmakeSymbolCharClass(SDFCharClass charClass)
{
  return (SDFSymbol)ATmakeTerm(SDFpatternSymbolCharClass, charClass);
}

/*}}}  */
/*{{{  SDFSymbol SDFmakeSymbolSort(SDFSort sort) */

SDFSymbol SDFmakeSymbolSort(SDFSort sort)
{
  return (SDFSymbol)ATmakeTerm(SDFpatternSymbolSort, sort);
}

/*}}}  */
/*{{{  SDFSymbol SDFmakeSymbolLit(SDFLiteral literal) */

SDFSymbol SDFmakeSymbolLit(SDFLiteral literal)
{
  return (SDFSymbol)ATmakeTerm(SDFpatternSymbolLit, literal);
}

/*}}}  */
/*{{{  SDFSymbol SDFmakeSymbolLabel(SDFLiteral label, SDFLayout wsAfterLabel, SDFLayout wsAfterColon, SDFSymbol symbol) */

SDFSymbol SDFmakeSymbolLabel(SDFLiteral label, SDFLayout wsAfterLabel, SDFLayout wsAfterColon, SDFSymbol symbol)
{
  return (SDFSymbol)ATmakeTerm(SDFpatternSymbolLabel, label, wsAfterLabel, wsAfterColon, symbol);
}

/*}}}  */
/*{{{  SDFSymbol SDFmakeSymbolBracket(SDFLayout wsAfterParenOpen, SDFSymbol symbol, SDFLayout wsAfterSymbol) */

SDFSymbol SDFmakeSymbolBracket(SDFLayout wsAfterParenOpen, SDFSymbol symbol, SDFLayout wsAfterSymbol)
{
  return (SDFSymbol)ATmakeTerm(SDFpatternSymbolBracket, wsAfterParenOpen, symbol, wsAfterSymbol);
}

/*}}}  */
/*{{{  SDFGrammar SDFmakeGrammarLexicalPriorities(SDFLayout wsAfterLexical, SDFLayout wsAfterPriorities, SDFPriorities priorities) */

SDFGrammar SDFmakeGrammarLexicalPriorities(SDFLayout wsAfterLexical, SDFLayout wsAfterPriorities, SDFPriorities priorities)
{
  return (SDFGrammar)ATmakeTerm(SDFpatternGrammarLexicalPriorities, wsAfterLexical, wsAfterPriorities, priorities);
}

/*}}}  */
/*{{{  SDFGrammar SDFmakeGrammarContextFreePriorities(SDFLayout wsAfterContextFree, SDFLayout wsAfterPriorities, SDFPriorities priorities) */

SDFGrammar SDFmakeGrammarContextFreePriorities(SDFLayout wsAfterContextFree, SDFLayout wsAfterPriorities, SDFPriorities priorities)
{
  return (SDFGrammar)ATmakeTerm(SDFpatternGrammarContextFreePriorities, wsAfterContextFree, wsAfterPriorities, priorities);
}

/*}}}  */
/*{{{  SDFGrammar SDFmakeGrammarLexicalRestrictions(SDFLayout wsAfterLexical, SDFLayout wsAfterRestrictions, SDFRestrictions restrictions) */

SDFGrammar SDFmakeGrammarLexicalRestrictions(SDFLayout wsAfterLexical, SDFLayout wsAfterRestrictions, SDFRestrictions restrictions)
{
  return (SDFGrammar)ATmakeTerm(SDFpatternGrammarLexicalRestrictions, wsAfterLexical, wsAfterRestrictions, restrictions);
}

/*}}}  */
/*{{{  SDFGrammar SDFmakeGrammarContextFreeRestrictions(SDFLayout wsAfterContextFree, SDFLayout wsAfterRestrictions, SDFRestrictions restrictions) */

SDFGrammar SDFmakeGrammarContextFreeRestrictions(SDFLayout wsAfterContextFree, SDFLayout wsAfterRestrictions, SDFRestrictions restrictions)
{
  return (SDFGrammar)ATmakeTerm(SDFpatternGrammarContextFreeRestrictions, wsAfterContextFree, wsAfterRestrictions, restrictions);
}

/*}}}  */
/*{{{  SDFGrammar SDFmakeGrammarSyntax(SDFLayout wsAfterSyntax, SDFProductions productions) */

SDFGrammar SDFmakeGrammarSyntax(SDFLayout wsAfterSyntax, SDFProductions productions)
{
  return (SDFGrammar)ATmakeTerm(SDFpatternGrammarSyntax, wsAfterSyntax, productions);
}

/*}}}  */
/*{{{  SDFGrammar SDFmakeGrammarLexicalSyntax(SDFLayout wsAfterLexical, SDFLayout wsAfterSyntax, SDFProductions productions) */

SDFGrammar SDFmakeGrammarLexicalSyntax(SDFLayout wsAfterLexical, SDFLayout wsAfterSyntax, SDFProductions productions)
{
  return (SDFGrammar)ATmakeTerm(SDFpatternGrammarLexicalSyntax, wsAfterLexical, wsAfterSyntax, productions);
}

/*}}}  */
/*{{{  SDFGrammar SDFmakeGrammarContextFreeSyntax(SDFLayout wsAfterContextFree, SDFLayout wsAfterSyntax, SDFProductions productions) */

SDFGrammar SDFmakeGrammarContextFreeSyntax(SDFLayout wsAfterContextFree, SDFLayout wsAfterSyntax, SDFProductions productions)
{
  return (SDFGrammar)ATmakeTerm(SDFpatternGrammarContextFreeSyntax, wsAfterContextFree, wsAfterSyntax, productions);
}

/*}}}  */
/*{{{  SDFGrammar SDFmakeGrammarVariables(SDFLayout wsAfterVariables, SDFProductions productions) */

SDFGrammar SDFmakeGrammarVariables(SDFLayout wsAfterVariables, SDFProductions productions)
{
  return (SDFGrammar)ATmakeTerm(SDFpatternGrammarVariables, wsAfterVariables, productions);
}

/*}}}  */
/*{{{  SDFGrammar SDFmakeGrammarLexicalVariables(SDFLayout wsAfterLexical, SDFLayout wsAfterVariables, SDFProductions productions) */

SDFGrammar SDFmakeGrammarLexicalVariables(SDFLayout wsAfterLexical, SDFLayout wsAfterVariables, SDFProductions productions)
{
  return (SDFGrammar)ATmakeTerm(SDFpatternGrammarLexicalVariables, wsAfterLexical, wsAfterVariables, productions);
}

/*}}}  */
/*{{{  SDFGrammar SDFmakeGrammarImpSection(SDFImpSection impSection) */

SDFGrammar SDFmakeGrammarImpSection(SDFImpSection impSection)
{
  return (SDFGrammar)ATmakeTerm(SDFpatternGrammarImpSection, impSection);
}

/*}}}  */
/*{{{  SDFGrammar SDFmakeGrammarPriorities(SDFLayout wsAfterPriorities, SDFPriorities priorities) */

SDFGrammar SDFmakeGrammarPriorities(SDFLayout wsAfterPriorities, SDFPriorities priorities)
{
  return (SDFGrammar)ATmakeTerm(SDFpatternGrammarPriorities, wsAfterPriorities, priorities);
}

/*}}}  */
/*{{{  SDFGrammar SDFmakeGrammarSorts(SDFLayout wsAfterSorts, SDFSymbols symbols) */

SDFGrammar SDFmakeGrammarSorts(SDFLayout wsAfterSorts, SDFSymbols symbols)
{
  return (SDFGrammar)ATmakeTerm(SDFpatternGrammarSorts, wsAfterSorts, symbols);
}

/*}}}  */
/*{{{  SDFGrammar SDFmakeGrammarRestrictions(SDFLayout wsAfterRestrictions, SDFRestrictions restrictions) */

SDFGrammar SDFmakeGrammarRestrictions(SDFLayout wsAfterRestrictions, SDFRestrictions restrictions)
{
  return (SDFGrammar)ATmakeTerm(SDFpatternGrammarRestrictions, wsAfterRestrictions, restrictions);
}

/*}}}  */
/*{{{  SDFGrammar SDFmakeGrammarAliases(SDFLayout wsAfterAliases, SDFAliases aliases) */

SDFGrammar SDFmakeGrammarAliases(SDFLayout wsAfterAliases, SDFAliases aliases)
{
  return (SDFGrammar)ATmakeTerm(SDFpatternGrammarAliases, wsAfterAliases, aliases);
}

/*}}}  */
/*{{{  SDFGrammar SDFmakeGrammarEmptyGrammar() */

SDFGrammar SDFmakeGrammarEmptyGrammar()
{
  return (SDFGrammar)ATmakeTerm(SDFpatternGrammarEmptyGrammar);
}

/*}}}  */
/*{{{  SDFGrammar SDFmakeGrammarConcGrammars(SDFGrammar left, SDFLayout wsAfterLeft, SDFGrammar right) */

SDFGrammar SDFmakeGrammarConcGrammars(SDFGrammar left, SDFLayout wsAfterLeft, SDFGrammar right)
{
  return (SDFGrammar)ATmakeTerm(SDFpatternGrammarConcGrammars, left, wsAfterLeft, right);
}

/*}}}  */
/*{{{  SDFGrammar SDFmakeGrammarBracket(SDFLayout wsAfterParenOpen, SDFGrammar grammar, SDFLayout wsAfterGrammar) */

SDFGrammar SDFmakeGrammarBracket(SDFLayout wsAfterParenOpen, SDFGrammar grammar, SDFLayout wsAfterGrammar)
{
  return (SDFGrammar)ATmakeTerm(SDFpatternGrammarBracket, wsAfterParenOpen, grammar, wsAfterGrammar);
}

/*}}}  */
/*{{{  SDFSDF SDFmakeSDFDefinition(SDFLayout wsAfterDefinition, SDFDefinition definition) */

SDFSDF SDFmakeSDFDefinition(SDFLayout wsAfterDefinition, SDFDefinition definition)
{
  return (SDFSDF)ATmakeTerm(SDFpatternSDFDefinition, wsAfterDefinition, definition);
}

/*}}}  */
/*{{{  SDFAttributes SDFmakeAttributesAttrs(SDFLayout wsAfterBraceOpen, SDFAttributeAttributes attributes, SDFLayout wsAfterAttributes) */

SDFAttributes SDFmakeAttributesAttrs(SDFLayout wsAfterBraceOpen, SDFAttributeAttributes attributes, SDFLayout wsAfterAttributes)
{
  return (SDFAttributes)ATmakeTerm(SDFpatternAttributesAttrs, wsAfterBraceOpen, attributes, wsAfterAttributes);
}

/*}}}  */
/*{{{  SDFAttributes SDFmakeAttributesNoAttrs() */

SDFAttributes SDFmakeAttributesNoAttrs()
{
  return (SDFAttributes)ATmakeTerm(SDFpatternAttributesNoAttrs);
}

/*}}}  */
/*{{{  SDFAttributeAttributes SDFmakeAttributeAttributesEmpty() */

SDFAttributeAttributes SDFmakeAttributeAttributesEmpty()
{
  return (SDFAttributeAttributes)ATmakeTerm(SDFpatternAttributeAttributesEmpty);
}

/*}}}  */
/*{{{  SDFAttributeAttributes SDFmakeAttributeAttributesSingle(SDFAttribute head) */

SDFAttributeAttributes SDFmakeAttributeAttributesSingle(SDFAttribute head)
{
  return (SDFAttributeAttributes)ATmakeTerm(SDFpatternAttributeAttributesSingle, head);
}

/*}}}  */
/*{{{  SDFAttributeAttributes SDFmakeAttributeAttributesMany(SDFAttribute head, SDFLayout wsAfterFirst, SDFSeparator sep, SDFLayout wsAfterSep, SDFAttributeAttributes tail) */

SDFAttributeAttributes SDFmakeAttributeAttributesMany(SDFAttribute head, SDFLayout wsAfterFirst, SDFSeparator sep, SDFLayout wsAfterSep, SDFAttributeAttributes tail)
{
  return (SDFAttributeAttributes)ATmakeTerm(SDFpatternAttributeAttributesMany, head, wsAfterFirst, sep, wsAfterSep, tail);
}

/*}}}  */
/*{{{  SDFProduction SDFmakeProductionProd(SDFSymbols symbols, SDFLayout wsAfterSymbols, SDFLayout wsAfterGreaterThan, SDFSymbol result, SDFLayout wsAfterResult, SDFAttributes attributes) */

SDFProduction SDFmakeProductionProd(SDFSymbols symbols, SDFLayout wsAfterSymbols, SDFLayout wsAfterGreaterThan, SDFSymbol result, SDFLayout wsAfterResult, SDFAttributes attributes)
{
  return (SDFProduction)ATmakeTerm(SDFpatternProductionProd, symbols, wsAfterSymbols, wsAfterGreaterThan, result, wsAfterResult, attributes);
}

/*}}}  */
/*{{{  SDFProduction SDFmakeProductionProdFun(SDFLiteral functionSymbol, SDFLayout wsAfterFunctionSymbol, SDFLayout wsAfterParenOpen, SDFSymbolArguments arguments, SDFLayout wsAfterArguments, SDFLayout wsAfterParenClose, SDFLayout wsAfterGreaterThan, SDFSymbol result, SDFLayout wsAfterResult, SDFAttributes attributes) */

SDFProduction SDFmakeProductionProdFun(SDFLiteral functionSymbol, SDFLayout wsAfterFunctionSymbol, SDFLayout wsAfterParenOpen, SDFSymbolArguments arguments, SDFLayout wsAfterArguments, SDFLayout wsAfterParenClose, SDFLayout wsAfterGreaterThan, SDFSymbol result, SDFLayout wsAfterResult, SDFAttributes attributes)
{
  return (SDFProduction)ATmakeTerm(SDFpatternProductionProdFun, functionSymbol, wsAfterFunctionSymbol, wsAfterParenOpen, arguments, wsAfterArguments, wsAfterParenClose, wsAfterGreaterThan, result, wsAfterResult, attributes);
}

/*}}}  */
/*{{{  SDFProductions SDFmakeProductionsDefault(SDFProductionProductions productions) */

SDFProductions SDFmakeProductionsDefault(SDFProductionProductions productions)
{
  return (SDFProductions)ATmakeTerm(SDFpatternProductionsDefault, productions);
}

/*}}}  */
/*{{{  SDFProductionProductions SDFmakeProductionProductionsEmpty() */

SDFProductionProductions SDFmakeProductionProductionsEmpty()
{
  return (SDFProductionProductions)ATmakeTerm(SDFpatternProductionProductionsEmpty);
}

/*}}}  */
/*{{{  SDFProductionProductions SDFmakeProductionProductionsSingle(SDFProduction head) */

SDFProductionProductions SDFmakeProductionProductionsSingle(SDFProduction head)
{
  return (SDFProductionProductions)ATmakeTerm(SDFpatternProductionProductionsSingle, head);
}

/*}}}  */
/*{{{  SDFProductionProductions SDFmakeProductionProductionsMany(SDFProduction head, SDFLayout wsAfterFirst, SDFProductionProductions tail) */

SDFProductionProductions SDFmakeProductionProductionsMany(SDFProduction head, SDFLayout wsAfterFirst, SDFProductionProductions tail)
{
  return (SDFProductionProductions)ATmakeTerm(SDFpatternProductionProductionsMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDFModuleWord SDFmakeModuleWordWord(SDFLexical lex) */

SDFModuleWord SDFmakeModuleWordWord(SDFLexical lex)
{
  return (SDFModuleWord)ATmakeTerm(SDFpatternModuleWordWord, lex);
}

/*}}}  */
/*{{{  SDFModuleId SDFmakeModuleIdWord(SDFLexical lex) */

SDFModuleId SDFmakeModuleIdWord(SDFLexical lex)
{
  return (SDFModuleId)ATmakeTerm(SDFpatternModuleIdWord, lex);
}

/*}}}  */
/*{{{  SDFModuleId SDFmakeModuleIdSlashWord(SDFLexical lex) */

SDFModuleId SDFmakeModuleIdSlashWord(SDFLexical lex)
{
  return (SDFModuleId)ATmakeTerm(SDFpatternModuleIdSlashWord, lex);
}

/*}}}  */
/*{{{  SDFModuleId SDFmakeModuleIdWordSlashWord(SDFLexical lex) */

SDFModuleId SDFmakeModuleIdWordSlashWord(SDFLexical lex)
{
  return (SDFModuleId)ATmakeTerm(SDFpatternModuleIdWordSlashWord, lex);
}

/*}}}  */
/*{{{  SDFDefinition SDFmakeDefinitionDefault(SDFModuleModules modules) */

SDFDefinition SDFmakeDefinitionDefault(SDFModuleModules modules)
{
  return (SDFDefinition)ATmakeTerm(SDFpatternDefinitionDefault, modules);
}

/*}}}  */
/*{{{  SDFModuleModules SDFmakeModuleModulesEmpty() */

SDFModuleModules SDFmakeModuleModulesEmpty()
{
  return (SDFModuleModules)ATmakeTerm(SDFpatternModuleModulesEmpty);
}

/*}}}  */
/*{{{  SDFModuleModules SDFmakeModuleModulesSingle(SDFModule head) */

SDFModuleModules SDFmakeModuleModulesSingle(SDFModule head)
{
  return (SDFModuleModules)ATmakeTerm(SDFpatternModuleModulesSingle, head);
}

/*}}}  */
/*{{{  SDFModuleModules SDFmakeModuleModulesMany(SDFModule head, SDFLayout wsAfterFirst, SDFModuleModules tail) */

SDFModuleModules SDFmakeModuleModulesMany(SDFModule head, SDFLayout wsAfterFirst, SDFModuleModules tail)
{
  return (SDFModuleModules)ATmakeTerm(SDFpatternModuleModulesMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDFModule SDFmakeModuleModule(SDFLayout wsAfterModule, SDFModuleName moduleName, SDFLayout wsAfterModuleName, SDFImpSectionList list, SDFLayout wsAfterList, SDFSections sections) */

SDFModule SDFmakeModuleModule(SDFLayout wsAfterModule, SDFModuleName moduleName, SDFLayout wsAfterModuleName, SDFImpSectionList list, SDFLayout wsAfterList, SDFSections sections)
{
  return (SDFModule)ATmakeTerm(SDFpatternModuleModule, wsAfterModule, moduleName, wsAfterModuleName, list, wsAfterList, sections);
}

/*}}}  */
/*{{{  SDFImpSectionList SDFmakeImpSectionListEmpty() */

SDFImpSectionList SDFmakeImpSectionListEmpty()
{
  return (SDFImpSectionList)ATmakeTerm(SDFpatternImpSectionListEmpty);
}

/*}}}  */
/*{{{  SDFImpSectionList SDFmakeImpSectionListSingle(SDFImpSection head) */

SDFImpSectionList SDFmakeImpSectionListSingle(SDFImpSection head)
{
  return (SDFImpSectionList)ATmakeTerm(SDFpatternImpSectionListSingle, head);
}

/*}}}  */
/*{{{  SDFImpSectionList SDFmakeImpSectionListMany(SDFImpSection head, SDFLayout wsAfterFirst, SDFImpSectionList tail) */

SDFImpSectionList SDFmakeImpSectionListMany(SDFImpSection head, SDFLayout wsAfterFirst, SDFImpSectionList tail)
{
  return (SDFImpSectionList)ATmakeTerm(SDFpatternImpSectionListMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDFSection SDFmakeSectionExports(SDFLayout wsAfterExports, SDFGrammar grammar) */

SDFSection SDFmakeSectionExports(SDFLayout wsAfterExports, SDFGrammar grammar)
{
  return (SDFSection)ATmakeTerm(SDFpatternSectionExports, wsAfterExports, grammar);
}

/*}}}  */
/*{{{  SDFSection SDFmakeSectionHiddens(SDFLayout wsAfterHiddens, SDFGrammar grammar) */

SDFSection SDFmakeSectionHiddens(SDFLayout wsAfterHiddens, SDFGrammar grammar)
{
  return (SDFSection)ATmakeTerm(SDFpatternSectionHiddens, wsAfterHiddens, grammar);
}

/*}}}  */
/*{{{  SDFSections SDFmakeSectionsDefault(SDFSectionList list) */

SDFSections SDFmakeSectionsDefault(SDFSectionList list)
{
  return (SDFSections)ATmakeTerm(SDFpatternSectionsDefault, list);
}

/*}}}  */
/*{{{  SDFSectionList SDFmakeSectionListEmpty() */

SDFSectionList SDFmakeSectionListEmpty()
{
  return (SDFSectionList)ATmakeTerm(SDFpatternSectionListEmpty);
}

/*}}}  */
/*{{{  SDFSectionList SDFmakeSectionListSingle(SDFSection head) */

SDFSectionList SDFmakeSectionListSingle(SDFSection head)
{
  return (SDFSectionList)ATmakeTerm(SDFpatternSectionListSingle, head);
}

/*}}}  */
/*{{{  SDFSectionList SDFmakeSectionListMany(SDFSection head, SDFLayout wsAfterFirst, SDFSectionList tail) */

SDFSectionList SDFmakeSectionListMany(SDFSection head, SDFLayout wsAfterFirst, SDFSectionList tail)
{
  return (SDFSectionList)ATmakeTerm(SDFpatternSectionListMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDFModuleName SDFmakeModuleNameUnparameterized(SDFModuleId moduleId) */

SDFModuleName SDFmakeModuleNameUnparameterized(SDFModuleId moduleId)
{
  return (SDFModuleName)ATmakeTerm(SDFpatternModuleNameUnparameterized, moduleId);
}

/*}}}  */
/*{{{  SDFModuleName SDFmakeModuleNameParameterized(SDFModuleId moduleId, SDFLayout wsAfterModuleId, SDFLayout wsAfterBracketOpen, SDFSymbols params, SDFLayout wsAfterParams) */

SDFModuleName SDFmakeModuleNameParameterized(SDFModuleId moduleId, SDFLayout wsAfterModuleId, SDFLayout wsAfterBracketOpen, SDFSymbols params, SDFLayout wsAfterParams)
{
  return (SDFModuleName)ATmakeTerm(SDFpatternModuleNameParameterized, moduleId, wsAfterModuleId, wsAfterBracketOpen, params, wsAfterParams);
}

/*}}}  */
/*{{{  SDFAttribute SDFmakeAttributeId(SDFLayout wsAfterId, SDFLayout wsAfterParenOpen, SDFModuleName moduleName, SDFLayout wsAfterModuleName) */

SDFAttribute SDFmakeAttributeId(SDFLayout wsAfterId, SDFLayout wsAfterParenOpen, SDFModuleName moduleName, SDFLayout wsAfterModuleName)
{
  return (SDFAttribute)ATmakeTerm(SDFpatternAttributeId, wsAfterId, wsAfterParenOpen, moduleName, wsAfterModuleName);
}

/*}}}  */
/*{{{  SDFAttribute SDFmakeAttributeBracket() */

SDFAttribute SDFmakeAttributeBracket()
{
  return (SDFAttribute)ATmakeTerm(SDFpatternAttributeBracket);
}

/*}}}  */
/*{{{  SDFAttribute SDFmakeAttributeAtr(SDFAssociativity associativity) */

SDFAttribute SDFmakeAttributeAtr(SDFAssociativity associativity)
{
  return (SDFAttribute)ATmakeTerm(SDFpatternAttributeAtr, associativity);
}

/*}}}  */
/*{{{  SDFAttribute SDFmakeAttributeCons(SDFLayout wsAfterCons, SDFLayout wsAfterParenOpen, SDFATerm aTerm, SDFLayout wsAfterATerm) */

SDFAttribute SDFmakeAttributeCons(SDFLayout wsAfterCons, SDFLayout wsAfterParenOpen, SDFATerm aTerm, SDFLayout wsAfterATerm)
{
  return (SDFAttribute)ATmakeTerm(SDFpatternAttributeCons, wsAfterCons, wsAfterParenOpen, aTerm, wsAfterATerm);
}

/*}}}  */
/*{{{  SDFAttribute SDFmakeAttributeConstructor() */

SDFAttribute SDFmakeAttributeConstructor()
{
  return (SDFAttribute)ATmakeTerm(SDFpatternAttributeConstructor);
}

/*}}}  */
/*{{{  SDFAttribute SDFmakeAttributeMemo() */

SDFAttribute SDFmakeAttributeMemo()
{
  return (SDFAttribute)ATmakeTerm(SDFpatternAttributeMemo);
}

/*}}}  */
/*{{{  SDFAttribute SDFmakeAttributeReject() */

SDFAttribute SDFmakeAttributeReject()
{
  return (SDFAttribute)ATmakeTerm(SDFpatternAttributeReject);
}

/*}}}  */
/*{{{  SDFAttribute SDFmakeAttributePrefer() */

SDFAttribute SDFmakeAttributePrefer()
{
  return (SDFAttribute)ATmakeTerm(SDFpatternAttributePrefer);
}

/*}}}  */
/*{{{  SDFAttribute SDFmakeAttributeAvoid() */

SDFAttribute SDFmakeAttributeAvoid()
{
  return (SDFAttribute)ATmakeTerm(SDFpatternAttributeAvoid);
}

/*}}}  */
/*{{{  SDFImpSection SDFmakeImpSectionImports(SDFLayout wsAfterImports, SDFImports list) */

SDFImpSection SDFmakeImpSectionImports(SDFLayout wsAfterImports, SDFImports list)
{
  return (SDFImpSection)ATmakeTerm(SDFpatternImpSectionImports, wsAfterImports, list);
}

/*}}}  */
/*{{{  SDFImports SDFmakeImportsDefault(SDFImportList list) */

SDFImports SDFmakeImportsDefault(SDFImportList list)
{
  return (SDFImports)ATmakeTerm(SDFpatternImportsDefault, list);
}

/*}}}  */
/*{{{  SDFImportList SDFmakeImportListEmpty() */

SDFImportList SDFmakeImportListEmpty()
{
  return (SDFImportList)ATmakeTerm(SDFpatternImportListEmpty);
}

/*}}}  */
/*{{{  SDFImportList SDFmakeImportListSingle(SDFImport head) */

SDFImportList SDFmakeImportListSingle(SDFImport head)
{
  return (SDFImportList)ATmakeTerm(SDFpatternImportListSingle, head);
}

/*}}}  */
/*{{{  SDFImportList SDFmakeImportListMany(SDFImport head, SDFLayout wsAfterFirst, SDFImportList tail) */

SDFImportList SDFmakeImportListMany(SDFImport head, SDFLayout wsAfterFirst, SDFImportList tail)
{
  return (SDFImportList)ATmakeTerm(SDFpatternImportListMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDFImport SDFmakeImportModule(SDFModuleName moduleName) */

SDFImport SDFmakeImportModule(SDFModuleName moduleName)
{
  return (SDFImport)ATmakeTerm(SDFpatternImportModule, moduleName);
}

/*}}}  */
/*{{{  SDFImport SDFmakeImportRenamedModule(SDFModuleName moduleName, SDFLayout wsAfterModuleName, SDFRenamings renamings) */

SDFImport SDFmakeImportRenamedModule(SDFModuleName moduleName, SDFLayout wsAfterModuleName, SDFRenamings renamings)
{
  return (SDFImport)ATmakeTerm(SDFpatternImportRenamedModule, moduleName, wsAfterModuleName, renamings);
}

/*}}}  */
/*{{{  SDFImport SDFmakeImportBracket(SDFLayout wsAfterParenOpen, SDFImport import, SDFLayout wsAfterImport) */

SDFImport SDFmakeImportBracket(SDFLayout wsAfterParenOpen, SDFImport import, SDFLayout wsAfterImport)
{
  return (SDFImport)ATmakeTerm(SDFpatternImportBracket, wsAfterParenOpen, import, wsAfterImport);
}

/*}}}  */
/*{{{  SDFSymbolTail SDFmakeSymbolTailSingle(SDFSymbol head) */

SDFSymbolTail SDFmakeSymbolTailSingle(SDFSymbol head)
{
  return (SDFSymbolTail)ATmakeTerm(SDFpatternSymbolTailSingle, head);
}

/*}}}  */
/*{{{  SDFSymbolTail SDFmakeSymbolTailMany(SDFSymbol head, SDFLayout wsAfterFirst, SDFSymbolTail tail) */

SDFSymbolTail SDFmakeSymbolTailMany(SDFSymbol head, SDFLayout wsAfterFirst, SDFSymbolTail tail)
{
  return (SDFSymbolTail)ATmakeTerm(SDFpatternSymbolTailMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDFAssociativity SDFmakeAssociativityLeft() */

SDFAssociativity SDFmakeAssociativityLeft()
{
  return (SDFAssociativity)ATmakeTerm(SDFpatternAssociativityLeft);
}

/*}}}  */
/*{{{  SDFAssociativity SDFmakeAssociativityRight() */

SDFAssociativity SDFmakeAssociativityRight()
{
  return (SDFAssociativity)ATmakeTerm(SDFpatternAssociativityRight);
}

/*}}}  */
/*{{{  SDFAssociativity SDFmakeAssociativityNonAssoc() */

SDFAssociativity SDFmakeAssociativityNonAssoc()
{
  return (SDFAssociativity)ATmakeTerm(SDFpatternAssociativityNonAssoc);
}

/*}}}  */
/*{{{  SDFAssociativity SDFmakeAssociativityAssoc() */

SDFAssociativity SDFmakeAssociativityAssoc()
{
  return (SDFAssociativity)ATmakeTerm(SDFpatternAssociativityAssoc);
}

/*}}}  */
/*{{{  SDFGroup SDFmakeGroupSimpleGroup(SDFProduction production) */

SDFGroup SDFmakeGroupSimpleGroup(SDFProduction production)
{
  return (SDFGroup)ATmakeTerm(SDFpatternGroupSimpleGroup, production);
}

/*}}}  */
/*{{{  SDFGroup SDFmakeGroupProdsGroup(SDFLayout wsAfterBraceOpen, SDFProductions productions, SDFLayout wsAfterProductions) */

SDFGroup SDFmakeGroupProdsGroup(SDFLayout wsAfterBraceOpen, SDFProductions productions, SDFLayout wsAfterProductions)
{
  return (SDFGroup)ATmakeTerm(SDFpatternGroupProdsGroup, wsAfterBraceOpen, productions, wsAfterProductions);
}

/*}}}  */
/*{{{  SDFGroup SDFmakeGroupAssocGroup(SDFLayout wsAfterBraceOpen, SDFAssociativity associativity, SDFLayout wsAfterAssociativity, SDFLayout wsAfterColon, SDFProductions productions, SDFLayout wsAfterProductions) */

SDFGroup SDFmakeGroupAssocGroup(SDFLayout wsAfterBraceOpen, SDFAssociativity associativity, SDFLayout wsAfterAssociativity, SDFLayout wsAfterColon, SDFProductions productions, SDFLayout wsAfterProductions)
{
  return (SDFGroup)ATmakeTerm(SDFpatternGroupAssocGroup, wsAfterBraceOpen, associativity, wsAfterAssociativity, wsAfterColon, productions, wsAfterProductions);
}

/*}}}  */
/*{{{  SDFPriority SDFmakePriorityPriorityChain(SDFGroupGroupp groupp) */

SDFPriority SDFmakePriorityPriorityChain(SDFGroupGroupp groupp)
{
  return (SDFPriority)ATmakeTerm(SDFpatternPriorityPriorityChain, groupp);
}

/*}}}  */
/*{{{  SDFPriority SDFmakePriorityPriorityAssoc(SDFGroup left, SDFLayout wsAfterLeft, SDFAssociativity associativity, SDFLayout wsAfterAssociativity, SDFGroup right) */

SDFPriority SDFmakePriorityPriorityAssoc(SDFGroup left, SDFLayout wsAfterLeft, SDFAssociativity associativity, SDFLayout wsAfterAssociativity, SDFGroup right)
{
  return (SDFPriority)ATmakeTerm(SDFpatternPriorityPriorityAssoc, left, wsAfterLeft, associativity, wsAfterAssociativity, right);
}

/*}}}  */
/*{{{  SDFGroupGroupp SDFmakeGroupGrouppSingle(SDFGroup head) */

SDFGroupGroupp SDFmakeGroupGrouppSingle(SDFGroup head)
{
  return (SDFGroupGroupp)ATmakeTerm(SDFpatternGroupGrouppSingle, head);
}

/*}}}  */
/*{{{  SDFGroupGroupp SDFmakeGroupGrouppMany(SDFGroup head, SDFLayout wsAfterFirst, SDFSeparator sep, SDFLayout wsAfterSep, SDFGroupGroupp tail) */

SDFGroupGroupp SDFmakeGroupGrouppMany(SDFGroup head, SDFLayout wsAfterFirst, SDFSeparator sep, SDFLayout wsAfterSep, SDFGroupGroupp tail)
{
  return (SDFGroupGroupp)ATmakeTerm(SDFpatternGroupGrouppMany, head, wsAfterFirst, sep, wsAfterSep, tail);
}

/*}}}  */
/*{{{  SDFPriorities SDFmakePrioritiesDefault(SDFPriorityPrioritys prioritys) */

SDFPriorities SDFmakePrioritiesDefault(SDFPriorityPrioritys prioritys)
{
  return (SDFPriorities)ATmakeTerm(SDFpatternPrioritiesDefault, prioritys);
}

/*}}}  */
/*{{{  SDFPriorityPrioritys SDFmakePriorityPrioritysEmpty() */

SDFPriorityPrioritys SDFmakePriorityPrioritysEmpty()
{
  return (SDFPriorityPrioritys)ATmakeTerm(SDFpatternPriorityPrioritysEmpty);
}

/*}}}  */
/*{{{  SDFPriorityPrioritys SDFmakePriorityPrioritysSingle(SDFPriority head) */

SDFPriorityPrioritys SDFmakePriorityPrioritysSingle(SDFPriority head)
{
  return (SDFPriorityPrioritys)ATmakeTerm(SDFpatternPriorityPrioritysSingle, head);
}

/*}}}  */
/*{{{  SDFPriorityPrioritys SDFmakePriorityPrioritysMany(SDFPriority head, SDFLayout wsAfterFirst, SDFSeparator sep, SDFLayout wsAfterSep, SDFPriorityPrioritys tail) */

SDFPriorityPrioritys SDFmakePriorityPrioritysMany(SDFPriority head, SDFLayout wsAfterFirst, SDFSeparator sep, SDFLayout wsAfterSep, SDFPriorityPrioritys tail)
{
  return (SDFPriorityPrioritys)ATmakeTerm(SDFpatternPriorityPrioritysMany, head, wsAfterFirst, sep, wsAfterSep, tail);
}

/*}}}  */
/*{{{  SDFSort SDFmakeSortOneChar(SDFLexical lex) */

SDFSort SDFmakeSortOneChar(SDFLexical lex)
{
  return (SDFSort)ATmakeTerm(SDFpatternSortOneChar, lex);
}

/*}}}  */
/*{{{  SDFSort SDFmakeSortMoreChars(SDFLexical lex) */

SDFSort SDFmakeSortMoreChars(SDFLexical lex)
{
  return (SDFSort)ATmakeTerm(SDFpatternSortMoreChars, lex);
}

/*}}}  */
/*{{{  SDFUQLiteral SDFmakeUQLiteralOneChar(SDFLexical lex) */

SDFUQLiteral SDFmakeUQLiteralOneChar(SDFLexical lex)
{
  return (SDFUQLiteral)ATmakeTerm(SDFpatternUQLiteralOneChar, lex);
}

/*}}}  */
/*{{{  SDFUQLiteral SDFmakeUQLiteralMoreChars(SDFLexical lex) */

SDFUQLiteral SDFmakeUQLiteralMoreChars(SDFLexical lex)
{
  return (SDFUQLiteral)ATmakeTerm(SDFpatternUQLiteralMoreChars, lex);
}

/*}}}  */
/*{{{  SDFLiteral SDFmakeLiteralUqlit(SDFUQLiteral uQLiteral) */

SDFLiteral SDFmakeLiteralUqlit(SDFUQLiteral uQLiteral)
{
  return (SDFLiteral)ATmakeTerm(SDFpatternLiteralUqlit, uQLiteral);
}

/*}}}  */
/*{{{  SDFLiteral SDFmakeLiteralQuoted(SDFLexical lex) */

SDFLiteral SDFmakeLiteralQuoted(SDFLexical lex)
{
  return (SDFLiteral)ATmakeTerm(SDFpatternLiteralQuoted, lex);
}

/*}}}  */
/*{{{  SDFSymbolArguments SDFmakeSymbolArgumentsEmpty() */

SDFSymbolArguments SDFmakeSymbolArgumentsEmpty()
{
  return (SDFSymbolArguments)ATmakeTerm(SDFpatternSymbolArgumentsEmpty);
}

/*}}}  */
/*{{{  SDFSymbolArguments SDFmakeSymbolArgumentsSingle(SDFSymbol head) */

SDFSymbolArguments SDFmakeSymbolArgumentsSingle(SDFSymbol head)
{
  return (SDFSymbolArguments)ATmakeTerm(SDFpatternSymbolArgumentsSingle, head);
}

/*}}}  */
/*{{{  SDFSymbolArguments SDFmakeSymbolArgumentsMany(SDFSymbol head, SDFLayout wsAfterFirst, SDFSeparator sep, SDFLayout wsAfterSep, SDFSymbolArguments tail) */

SDFSymbolArguments SDFmakeSymbolArgumentsMany(SDFSymbol head, SDFLayout wsAfterFirst, SDFSeparator sep, SDFLayout wsAfterSep, SDFSymbolArguments tail)
{
  return (SDFSymbolArguments)ATmakeTerm(SDFpatternSymbolArgumentsMany, head, wsAfterFirst, sep, wsAfterSep, tail);
}

/*}}}  */
/*{{{  SDFLookahead SDFmakeLookaheadCharClass(SDFCharClass charClass) */

SDFLookahead SDFmakeLookaheadCharClass(SDFCharClass charClass)
{
  return (SDFLookahead)ATmakeTerm(SDFpatternLookaheadCharClass, charClass);
}

/*}}}  */
/*{{{  SDFLookahead SDFmakeLookaheadSeq(SDFCharClass head, SDFLayout wsAfterHead, SDFLayout wsAfterPeriod, SDFLookaheads tail) */

SDFLookahead SDFmakeLookaheadSeq(SDFCharClass head, SDFLayout wsAfterHead, SDFLayout wsAfterPeriod, SDFLookaheads tail)
{
  return (SDFLookahead)ATmakeTerm(SDFpatternLookaheadSeq, head, wsAfterHead, wsAfterPeriod, tail);
}

/*}}}  */
/*{{{  SDFLookaheads SDFmakeLookaheadsSingle(SDFLookahead lookahead) */

SDFLookaheads SDFmakeLookaheadsSingle(SDFLookahead lookahead)
{
  return (SDFLookaheads)ATmakeTerm(SDFpatternLookaheadsSingle, lookahead);
}

/*}}}  */
/*{{{  SDFLookaheads SDFmakeLookaheadsAlt(SDFLookaheads left, SDFLayout wsAfterLeft, SDFLayout wsAfterBar, SDFLookaheads right) */

SDFLookaheads SDFmakeLookaheadsAlt(SDFLookaheads left, SDFLayout wsAfterLeft, SDFLayout wsAfterBar, SDFLookaheads right)
{
  return (SDFLookaheads)ATmakeTerm(SDFpatternLookaheadsAlt, left, wsAfterLeft, wsAfterBar, right);
}

/*}}}  */
/*{{{  SDFLookaheads SDFmakeLookaheadsBracket(SDFLayout wsAfterParenOpen, SDFLookaheads lookaheads, SDFLayout wsAfterLookaheads) */

SDFLookaheads SDFmakeLookaheadsBracket(SDFLayout wsAfterParenOpen, SDFLookaheads lookaheads, SDFLayout wsAfterLookaheads)
{
  return (SDFLookaheads)ATmakeTerm(SDFpatternLookaheadsBracket, wsAfterParenOpen, lookaheads, wsAfterLookaheads);
}

/*}}}  */
/*{{{  SDFLookaheads SDFmakeLookaheadsList(SDFLayout wsAfterBracketOpenBracketOpen, SDFLookaheads lookaheads, SDFLayout wsAfterLookaheads) */

SDFLookaheads SDFmakeLookaheadsList(SDFLayout wsAfterBracketOpenBracketOpen, SDFLookaheads lookaheads, SDFLayout wsAfterLookaheads)
{
  return (SDFLookaheads)ATmakeTerm(SDFpatternLookaheadsList, wsAfterBracketOpenBracketOpen, lookaheads, wsAfterLookaheads);
}

/*}}}  */
/*{{{  SDFLookaheadLookaheads SDFmakeLookaheadLookaheadsEmpty() */

SDFLookaheadLookaheads SDFmakeLookaheadLookaheadsEmpty()
{
  return (SDFLookaheadLookaheads)ATmakeTerm(SDFpatternLookaheadLookaheadsEmpty);
}

/*}}}  */
/*{{{  SDFLookaheadLookaheads SDFmakeLookaheadLookaheadsSingle(SDFLookahead head) */

SDFLookaheadLookaheads SDFmakeLookaheadLookaheadsSingle(SDFLookahead head)
{
  return (SDFLookaheadLookaheads)ATmakeTerm(SDFpatternLookaheadLookaheadsSingle, head);
}

/*}}}  */
/*{{{  SDFLookaheadLookaheads SDFmakeLookaheadLookaheadsMany(SDFLookahead head, SDFLayout wsAfterFirst, SDFSeparator sep, SDFLayout wsAfterSep, SDFLookaheadLookaheads tail) */

SDFLookaheadLookaheads SDFmakeLookaheadLookaheadsMany(SDFLookahead head, SDFLayout wsAfterFirst, SDFSeparator sep, SDFLayout wsAfterSep, SDFLookaheadLookaheads tail)
{
  return (SDFLookaheadLookaheads)ATmakeTerm(SDFpatternLookaheadLookaheadsMany, head, wsAfterFirst, sep, wsAfterSep, tail);
}

/*}}}  */
/*{{{  SDFRestriction SDFmakeRestrictionFollow(SDFSymbols symbols, SDFLayout wsAfterSymbols, SDFLayout wsAfterSlash, SDFLookaheads lookaheads) */

SDFRestriction SDFmakeRestrictionFollow(SDFSymbols symbols, SDFLayout wsAfterSymbols, SDFLayout wsAfterSlash, SDFLookaheads lookaheads)
{
  return (SDFRestriction)ATmakeTerm(SDFpatternRestrictionFollow, symbols, wsAfterSymbols, wsAfterSlash, lookaheads);
}

/*}}}  */
/*{{{  SDFRestrictions SDFmakeRestrictionsDefault(SDFRestrictionRestrictions restrictions) */

SDFRestrictions SDFmakeRestrictionsDefault(SDFRestrictionRestrictions restrictions)
{
  return (SDFRestrictions)ATmakeTerm(SDFpatternRestrictionsDefault, restrictions);
}

/*}}}  */
/*{{{  SDFRestrictionRestrictions SDFmakeRestrictionRestrictionsEmpty() */

SDFRestrictionRestrictions SDFmakeRestrictionRestrictionsEmpty()
{
  return (SDFRestrictionRestrictions)ATmakeTerm(SDFpatternRestrictionRestrictionsEmpty);
}

/*}}}  */
/*{{{  SDFRestrictionRestrictions SDFmakeRestrictionRestrictionsSingle(SDFRestriction head) */

SDFRestrictionRestrictions SDFmakeRestrictionRestrictionsSingle(SDFRestriction head)
{
  return (SDFRestrictionRestrictions)ATmakeTerm(SDFpatternRestrictionRestrictionsSingle, head);
}

/*}}}  */
/*{{{  SDFRestrictionRestrictions SDFmakeRestrictionRestrictionsMany(SDFRestriction head, SDFLayout wsAfterFirst, SDFRestrictionRestrictions tail) */

SDFRestrictionRestrictions SDFmakeRestrictionRestrictionsMany(SDFRestriction head, SDFLayout wsAfterFirst, SDFRestrictionRestrictions tail)
{
  return (SDFRestrictionRestrictions)ATmakeTerm(SDFpatternRestrictionRestrictionsMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDFAlias SDFmakeAliasAlias(SDFSymbol symbol, SDFLayout wsAfterSymbol, SDFLayout wsAfterArrow, SDFSymbol alias) */

SDFAlias SDFmakeAliasAlias(SDFSymbol symbol, SDFLayout wsAfterSymbol, SDFLayout wsAfterArrow, SDFSymbol alias)
{
  return (SDFAlias)ATmakeTerm(SDFpatternAliasAlias, symbol, wsAfterSymbol, wsAfterArrow, alias);
}

/*}}}  */
/*{{{  SDFAliases SDFmakeAliasesDefault(SDFAliasAliass aliass) */

SDFAliases SDFmakeAliasesDefault(SDFAliasAliass aliass)
{
  return (SDFAliases)ATmakeTerm(SDFpatternAliasesDefault, aliass);
}

/*}}}  */
/*{{{  SDFAliasAliass SDFmakeAliasAliassEmpty() */

SDFAliasAliass SDFmakeAliasAliassEmpty()
{
  return (SDFAliasAliass)ATmakeTerm(SDFpatternAliasAliassEmpty);
}

/*}}}  */
/*{{{  SDFAliasAliass SDFmakeAliasAliassSingle(SDFAlias head) */

SDFAliasAliass SDFmakeAliasAliassSingle(SDFAlias head)
{
  return (SDFAliasAliass)ATmakeTerm(SDFpatternAliasAliassSingle, head);
}

/*}}}  */
/*{{{  SDFAliasAliass SDFmakeAliasAliassMany(SDFAlias head, SDFLayout wsAfterFirst, SDFAliasAliass tail) */

SDFAliasAliass SDFmakeAliasAliassMany(SDFAlias head, SDFLayout wsAfterFirst, SDFAliasAliass tail)
{
  return (SDFAliasAliass)ATmakeTerm(SDFpatternAliasAliassMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDFSymbols SDFmakeSymbolsDefault(SDFSymbolSymbols symbols) */

SDFSymbols SDFmakeSymbolsDefault(SDFSymbolSymbols symbols)
{
  return (SDFSymbols)ATmakeTerm(SDFpatternSymbolsDefault, symbols);
}

/*}}}  */
/*{{{  SDFSymbolSymbols SDFmakeSymbolSymbolsEmpty() */

SDFSymbolSymbols SDFmakeSymbolSymbolsEmpty()
{
  return (SDFSymbolSymbols)ATmakeTerm(SDFpatternSymbolSymbolsEmpty);
}

/*}}}  */
/*{{{  SDFSymbolSymbols SDFmakeSymbolSymbolsSingle(SDFSymbol head) */

SDFSymbolSymbols SDFmakeSymbolSymbolsSingle(SDFSymbol head)
{
  return (SDFSymbolSymbols)ATmakeTerm(SDFpatternSymbolSymbolsSingle, head);
}

/*}}}  */
/*{{{  SDFSymbolSymbols SDFmakeSymbolSymbolsMany(SDFSymbol head, SDFLayout wsAfterFirst, SDFSymbolSymbols tail) */

SDFSymbolSymbols SDFmakeSymbolSymbolsMany(SDFSymbol head, SDFLayout wsAfterFirst, SDFSymbolSymbols tail)
{
  return (SDFSymbolSymbols)ATmakeTerm(SDFpatternSymbolSymbolsMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDFRenamings SDFmakeRenamingsRenamings(SDFLayout wsAfterBracketOpen, SDFRenamingRenamings renamings, SDFLayout wsAfterRenamings) */

SDFRenamings SDFmakeRenamingsRenamings(SDFLayout wsAfterBracketOpen, SDFRenamingRenamings renamings, SDFLayout wsAfterRenamings)
{
  return (SDFRenamings)ATmakeTerm(SDFpatternRenamingsRenamings, wsAfterBracketOpen, renamings, wsAfterRenamings);
}

/*}}}  */
/*{{{  SDFRenamingRenamings SDFmakeRenamingRenamingsEmpty() */

SDFRenamingRenamings SDFmakeRenamingRenamingsEmpty()
{
  return (SDFRenamingRenamings)ATmakeTerm(SDFpatternRenamingRenamingsEmpty);
}

/*}}}  */
/*{{{  SDFRenamingRenamings SDFmakeRenamingRenamingsSingle(SDFRenaming head) */

SDFRenamingRenamings SDFmakeRenamingRenamingsSingle(SDFRenaming head)
{
  return (SDFRenamingRenamings)ATmakeTerm(SDFpatternRenamingRenamingsSingle, head);
}

/*}}}  */
/*{{{  SDFRenamingRenamings SDFmakeRenamingRenamingsMany(SDFRenaming head, SDFLayout wsAfterFirst, SDFRenamingRenamings tail) */

SDFRenamingRenamings SDFmakeRenamingRenamingsMany(SDFRenaming head, SDFLayout wsAfterFirst, SDFRenamingRenamings tail)
{
  return (SDFRenamingRenamings)ATmakeTerm(SDFpatternRenamingRenamingsMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  SDFRenaming SDFmakeRenamingSymbol(SDFSymbol from, SDFLayout wsAfterFrom, SDFLayout wsAfterEqualsGreaterThan, SDFSymbol to) */

SDFRenaming SDFmakeRenamingSymbol(SDFSymbol from, SDFLayout wsAfterFrom, SDFLayout wsAfterEqualsGreaterThan, SDFSymbol to)
{
  return (SDFRenaming)ATmakeTerm(SDFpatternRenamingSymbol, from, wsAfterFrom, wsAfterEqualsGreaterThan, to);
}

/*}}}  */
/*{{{  SDFRenaming SDFmakeRenamingProduction(SDFSymbol from, SDFLayout wsAfterFrom, SDFLayout wsAfterEqualsGreaterThan, SDFSymbol to) */

SDFRenaming SDFmakeRenamingProduction(SDFSymbol from, SDFLayout wsAfterFrom, SDFLayout wsAfterEqualsGreaterThan, SDFSymbol to)
{
  return (SDFRenaming)ATmakeTerm(SDFpatternRenamingProduction, from, wsAfterFrom, wsAfterEqualsGreaterThan, to);
}

/*}}}  */
/*{{{  SDFNatCon SDFmakeNatConDigits(SDFLexical lex) */

SDFNatCon SDFmakeNatConDigits(SDFLexical lex)
{
  return (SDFNatCon)ATmakeTerm(SDFpatternNatConDigits, lex);
}

/*}}}  */
/*{{{  SDFIntCon SDFmakeIntConNatural(SDFNatCon natCon) */

SDFIntCon SDFmakeIntConNatural(SDFNatCon natCon)
{
  return (SDFIntCon)ATmakeTerm(SDFpatternIntConNatural, natCon);
}

/*}}}  */
/*{{{  SDFIntCon SDFmakeIntConPositive(SDFLayout wsAfterPos, SDFNatCon natCon) */

SDFIntCon SDFmakeIntConPositive(SDFLayout wsAfterPos, SDFNatCon natCon)
{
  return (SDFIntCon)ATmakeTerm(SDFpatternIntConPositive, wsAfterPos, natCon);
}

/*}}}  */
/*{{{  SDFIntCon SDFmakeIntConNegative(SDFLayout wsAfterNeg, SDFNatCon natCon) */

SDFIntCon SDFmakeIntConNegative(SDFLayout wsAfterNeg, SDFNatCon natCon)
{
  return (SDFIntCon)ATmakeTerm(SDFpatternIntConNegative, wsAfterNeg, natCon);
}

/*}}}  */
/*{{{  SDFCharRange SDFmakeCharRangeDefault(SDFCharacter character) */

SDFCharRange SDFmakeCharRangeDefault(SDFCharacter character)
{
  return (SDFCharRange)ATmakeTerm(SDFpatternCharRangeDefault, character);
}

/*}}}  */
/*{{{  SDFCharRange SDFmakeCharRangeRange(SDFCharacter start, SDFLayout wsAfterStart, SDFLayout wsAfter, SDFCharacter end) */

SDFCharRange SDFmakeCharRangeRange(SDFCharacter start, SDFLayout wsAfterStart, SDFLayout wsAfter, SDFCharacter end)
{
  return (SDFCharRange)ATmakeTerm(SDFpatternCharRangeRange, start, wsAfterStart, wsAfter, end);
}

/*}}}  */
/*{{{  SDFCharRanges SDFmakeCharRangesDefault(SDFCharRange charRange) */

SDFCharRanges SDFmakeCharRangesDefault(SDFCharRange charRange)
{
  return (SDFCharRanges)ATmakeTerm(SDFpatternCharRangesDefault, charRange);
}

/*}}}  */
/*{{{  SDFCharRanges SDFmakeCharRangesConc(SDFCharRanges left, SDFLayout wsAfterLeft, SDFCharRanges right) */

SDFCharRanges SDFmakeCharRangesConc(SDFCharRanges left, SDFLayout wsAfterLeft, SDFCharRanges right)
{
  return (SDFCharRanges)ATmakeTerm(SDFpatternCharRangesConc, left, wsAfterLeft, right);
}

/*}}}  */
/*{{{  SDFCharRanges SDFmakeCharRangesBracket(SDFLayout wsAfterParenOpen, SDFCharRanges charRanges, SDFLayout wsAfterCharRanges) */

SDFCharRanges SDFmakeCharRangesBracket(SDFLayout wsAfterParenOpen, SDFCharRanges charRanges, SDFLayout wsAfterCharRanges)
{
  return (SDFCharRanges)ATmakeTerm(SDFpatternCharRangesBracket, wsAfterParenOpen, charRanges, wsAfterCharRanges);
}

/*}}}  */
/*{{{  SDFOptCharRanges SDFmakeOptCharRangesAbsent() */

SDFOptCharRanges SDFmakeOptCharRangesAbsent()
{
  return (SDFOptCharRanges)ATmakeTerm(SDFpatternOptCharRangesAbsent);
}

/*}}}  */
/*{{{  SDFOptCharRanges SDFmakeOptCharRangesPresent(SDFCharRanges charRanges) */

SDFOptCharRanges SDFmakeOptCharRangesPresent(SDFCharRanges charRanges)
{
  return (SDFOptCharRanges)ATmakeTerm(SDFpatternOptCharRangesPresent, charRanges);
}

/*}}}  */
/*{{{  SDFCharClass SDFmakeCharClassSimpleCharclass(SDFLayout wsAfterBracketOpen, SDFOptCharRanges optCharRanges, SDFLayout wsAfterOptCharRanges) */

SDFCharClass SDFmakeCharClassSimpleCharclass(SDFLayout wsAfterBracketOpen, SDFOptCharRanges optCharRanges, SDFLayout wsAfterOptCharRanges)
{
  return (SDFCharClass)ATmakeTerm(SDFpatternCharClassSimpleCharclass, wsAfterBracketOpen, optCharRanges, wsAfterOptCharRanges);
}

/*}}}  */
/*{{{  SDFCharClass SDFmakeCharClassComp(SDFLayout wsAfterTilde, SDFCharClass charClass) */

SDFCharClass SDFmakeCharClassComp(SDFLayout wsAfterTilde, SDFCharClass charClass)
{
  return (SDFCharClass)ATmakeTerm(SDFpatternCharClassComp, wsAfterTilde, charClass);
}

/*}}}  */
/*{{{  SDFCharClass SDFmakeCharClassDiff(SDFCharClass left, SDFLayout wsAfterLeft, SDFLayout wsAfterSlash, SDFCharClass right) */

SDFCharClass SDFmakeCharClassDiff(SDFCharClass left, SDFLayout wsAfterLeft, SDFLayout wsAfterSlash, SDFCharClass right)
{
  return (SDFCharClass)ATmakeTerm(SDFpatternCharClassDiff, left, wsAfterLeft, wsAfterSlash, right);
}

/*}}}  */
/*{{{  SDFCharClass SDFmakeCharClassIsect(SDFCharClass left, SDFLayout wsAfterLeft, SDFLayout wsAfterSlashBackslash, SDFCharClass right) */

SDFCharClass SDFmakeCharClassIsect(SDFCharClass left, SDFLayout wsAfterLeft, SDFLayout wsAfterSlashBackslash, SDFCharClass right)
{
  return (SDFCharClass)ATmakeTerm(SDFpatternCharClassIsect, left, wsAfterLeft, wsAfterSlashBackslash, right);
}

/*}}}  */
/*{{{  SDFCharClass SDFmakeCharClassUnion(SDFCharClass left, SDFLayout wsAfterLeft, SDFLayout wsAfterBackslashSlash, SDFCharClass right) */

SDFCharClass SDFmakeCharClassUnion(SDFCharClass left, SDFLayout wsAfterLeft, SDFLayout wsAfterBackslashSlash, SDFCharClass right)
{
  return (SDFCharClass)ATmakeTerm(SDFpatternCharClassUnion, left, wsAfterLeft, wsAfterBackslashSlash, right);
}

/*}}}  */
/*{{{  SDFCharClass SDFmakeCharClassBracket(SDFLayout wsAfterParenOpen, SDFCharClass charClass, SDFLayout wsAfterCharClass) */

SDFCharClass SDFmakeCharClassBracket(SDFLayout wsAfterParenOpen, SDFCharClass charClass, SDFLayout wsAfterCharClass)
{
  return (SDFCharClass)ATmakeTerm(SDFpatternCharClassBracket, wsAfterParenOpen, charClass, wsAfterCharClass);
}

/*}}}  */
/*{{{  SDFAlphaNumericalEscChar SDFmakeAlphaNumericalEscCharDefault(SDFLexical lex) */

SDFAlphaNumericalEscChar SDFmakeAlphaNumericalEscCharDefault(SDFLexical lex)
{
  return (SDFAlphaNumericalEscChar)ATmakeTerm(SDFpatternAlphaNumericalEscCharDefault, lex);
}

/*}}}  */
/*{{{  SDFDecimalEscChar SDFmakeDecimalEscCharDec0_199(SDFLexical lex) */

SDFDecimalEscChar SDFmakeDecimalEscCharDec0_199(SDFLexical lex)
{
  return (SDFDecimalEscChar)ATmakeTerm(SDFpatternDecimalEscCharDec0_199, lex);
}

/*}}}  */
/*{{{  SDFDecimalEscChar SDFmakeDecimalEscCharDec200_249(SDFLexical lex) */

SDFDecimalEscChar SDFmakeDecimalEscCharDec200_249(SDFLexical lex)
{
  return (SDFDecimalEscChar)ATmakeTerm(SDFpatternDecimalEscCharDec200_249, lex);
}

/*}}}  */
/*{{{  SDFDecimalEscChar SDFmakeDecimalEscCharDec250_255(SDFLexical lex) */

SDFDecimalEscChar SDFmakeDecimalEscCharDec250_255(SDFLexical lex)
{
  return (SDFDecimalEscChar)ATmakeTerm(SDFpatternDecimalEscCharDec250_255, lex);
}

/*}}}  */
/*{{{  SDFEscChar SDFmakeEscCharAlphaNumeric(SDFLexical lex) */

SDFEscChar SDFmakeEscCharAlphaNumeric(SDFLexical lex)
{
  return (SDFEscChar)ATmakeTerm(SDFpatternEscCharAlphaNumeric, lex);
}

/*}}}  */
/*{{{  SDFEscChar SDFmakeEscCharDecimal(SDFLexical lex) */

SDFEscChar SDFmakeEscCharDecimal(SDFLexical lex)
{
  return (SDFEscChar)ATmakeTerm(SDFpatternEscCharDecimal, lex);
}

/*}}}  */
/*{{{  SDFLChar SDFmakeLCharNormal(SDFLexical lex) */

SDFLChar SDFmakeLCharNormal(SDFLexical lex)
{
  return (SDFLChar)ATmakeTerm(SDFpatternLCharNormal, lex);
}

/*}}}  */
/*{{{  SDFLChar SDFmakeLCharEscaped(SDFLexical lex) */

SDFLChar SDFmakeLCharEscaped(SDFLexical lex)
{
  return (SDFLChar)ATmakeTerm(SDFpatternLCharEscaped, lex);
}

/*}}}  */
/*{{{  SDFATerms SDFmakeATermsAterm(SDFATerm aTerm) */

SDFATerms SDFmakeATermsAterm(SDFATerm aTerm)
{
  return (SDFATerms)ATmakeTerm(SDFpatternATermsAterm, aTerm);
}

/*}}}  */
/*{{{  SDFATerms SDFmakeATermsCons(SDFATerm head, SDFLayout wsAfterHead, SDFLayout wsAfterComma, SDFATerms tail) */

SDFATerms SDFmakeATermsCons(SDFATerm head, SDFLayout wsAfterHead, SDFLayout wsAfterComma, SDFATerms tail)
{
  return (SDFATerms)ATmakeTerm(SDFpatternATermsCons, head, wsAfterHead, wsAfterComma, tail);
}

/*}}}  */
/*{{{  SDFATermList SDFmakeATermListEmpty(SDFLayout wsAfterBracketOpen) */

SDFATermList SDFmakeATermListEmpty(SDFLayout wsAfterBracketOpen)
{
  return (SDFATermList)ATmakeTerm(SDFpatternATermListEmpty, wsAfterBracketOpen);
}

/*}}}  */
/*{{{  SDFATermList SDFmakeATermListNotEmpty(SDFLayout wsAfterBracketOpen, SDFATerms aTerms, SDFLayout wsAfterATerms) */

SDFATermList SDFmakeATermListNotEmpty(SDFLayout wsAfterBracketOpen, SDFATerms aTerms, SDFLayout wsAfterATerms)
{
  return (SDFATermList)ATmakeTerm(SDFpatternATermListNotEmpty, wsAfterBracketOpen, aTerms, wsAfterATerms);
}

/*}}}  */
/*{{{  SDFACon SDFmakeAConInt(SDFIntCon intCon) */

SDFACon SDFmakeAConInt(SDFIntCon intCon)
{
  return (SDFACon)ATmakeTerm(SDFpatternAConInt, intCon);
}

/*}}}  */
/*{{{  SDFACon SDFmakeAConReal(SDFRealCon realCon) */

SDFACon SDFmakeAConReal(SDFRealCon realCon)
{
  return (SDFACon)ATmakeTerm(SDFpatternAConReal, realCon);
}

/*}}}  */
/*{{{  SDFAFun SDFmakeAFunDefault(SDFLiteral literal) */

SDFAFun SDFmakeAFunDefault(SDFLiteral literal)
{
  return (SDFAFun)ATmakeTerm(SDFpatternAFunDefault, literal);
}

/*}}}  */
/*{{{  SDFATerm SDFmakeATermConstant(SDFACon aCon) */

SDFATerm SDFmakeATermConstant(SDFACon aCon)
{
  return (SDFATerm)ATmakeTerm(SDFpatternATermConstant, aCon);
}

/*}}}  */
/*{{{  SDFATerm SDFmakeATermList(SDFATermList aTermList) */

SDFATerm SDFmakeATermList(SDFATermList aTermList)
{
  return (SDFATerm)ATmakeTerm(SDFpatternATermList, aTermList);
}

/*}}}  */
/*{{{  SDFATerm SDFmakeATermFun(SDFAFun aFun) */

SDFATerm SDFmakeATermFun(SDFAFun aFun)
{
  return (SDFATerm)ATmakeTerm(SDFpatternATermFun, aFun);
}

/*}}}  */
/*{{{  SDFATerm SDFmakeATermAppl(SDFAFun aFun, SDFLayout wsAfterAFun, SDFLayout wsAfterParenOpen, SDFATerms args, SDFLayout wsAfterArgs) */

SDFATerm SDFmakeATermAppl(SDFAFun aFun, SDFLayout wsAfterAFun, SDFLayout wsAfterParenOpen, SDFATerms args, SDFLayout wsAfterArgs)
{
  return (SDFATerm)ATmakeTerm(SDFpatternATermAppl, aFun, wsAfterAFun, wsAfterParenOpen, args, wsAfterArgs);
}

/*}}}  */
/*{{{  SDFATerm SDFmakeATermAnnotatedConstant(SDFACon aCon, SDFLayout wsAfterACon, SDFAnn ann) */

SDFATerm SDFmakeATermAnnotatedConstant(SDFACon aCon, SDFLayout wsAfterACon, SDFAnn ann)
{
  return (SDFATerm)ATmakeTerm(SDFpatternATermAnnotatedConstant, aCon, wsAfterACon, ann);
}

/*}}}  */
/*{{{  SDFATerm SDFmakeATermAnnotatedList(SDFATermList aTermList, SDFLayout wsAfterATermList, SDFAnn ann) */

SDFATerm SDFmakeATermAnnotatedList(SDFATermList aTermList, SDFLayout wsAfterATermList, SDFAnn ann)
{
  return (SDFATerm)ATmakeTerm(SDFpatternATermAnnotatedList, aTermList, wsAfterATermList, ann);
}

/*}}}  */
/*{{{  SDFATerm SDFmakeATermAnnotatedFun(SDFAFun aFun, SDFLayout wsAfterAFun, SDFAnn ann) */

SDFATerm SDFmakeATermAnnotatedFun(SDFAFun aFun, SDFLayout wsAfterAFun, SDFAnn ann)
{
  return (SDFATerm)ATmakeTerm(SDFpatternATermAnnotatedFun, aFun, wsAfterAFun, ann);
}

/*}}}  */
/*{{{  SDFATerm SDFmakeATermAnnotatedAppl(SDFAFun aFun, SDFLayout wsAfterAFun, SDFLayout wsAfterParenOpen, SDFATerms args, SDFLayout wsAfterArgs, SDFLayout wsAfterParenClose, SDFAnn ann) */

SDFATerm SDFmakeATermAnnotatedAppl(SDFAFun aFun, SDFLayout wsAfterAFun, SDFLayout wsAfterParenOpen, SDFATerms args, SDFLayout wsAfterArgs, SDFLayout wsAfterParenClose, SDFAnn ann)
{
  return (SDFATerm)ATmakeTerm(SDFpatternATermAnnotatedAppl, aFun, wsAfterAFun, wsAfterParenOpen, args, wsAfterArgs, wsAfterParenClose, ann);
}

/*}}}  */
/*{{{  SDFAnn SDFmakeAnnAnnotation(SDFLayout wsAfterBraceOpen, SDFATerms aTerms, SDFLayout wsAfterATerms) */

SDFAnn SDFmakeAnnAnnotation(SDFLayout wsAfterBraceOpen, SDFATerms aTerms, SDFLayout wsAfterATerms)
{
  return (SDFAnn)ATmakeTerm(SDFpatternAnnAnnotation, wsAfterBraceOpen, aTerms, wsAfterATerms);
}

/*}}}  */
/*{{{  SDFTagId SDFmakeTagIdDefault(SDFLexical lex) */

SDFTagId SDFmakeTagIdDefault(SDFLexical lex)
{
  return (SDFTagId)ATmakeTerm(SDFpatternTagIdDefault, lex);
}

/*}}}  */
/*{{{  SDFTagId SDFmakeTagIdEmpty() */

SDFTagId SDFmakeTagIdEmpty()
{
  return (SDFTagId)ATmakeTerm(SDFpatternTagIdEmpty);
}

/*}}}  */
/*{{{  SDFNumChar SDFmakeNumCharDigits(SDFLexical lex) */

SDFNumChar SDFmakeNumCharDigits(SDFLexical lex)
{
  return (SDFNumChar)ATmakeTerm(SDFpatternNumCharDigits, lex);
}

/*}}}  */
/*{{{  SDFShortChar SDFmakeShortCharRegular(SDFLexical lex) */

SDFShortChar SDFmakeShortCharRegular(SDFLexical lex)
{
  return (SDFShortChar)ATmakeTerm(SDFpatternShortCharRegular, lex);
}

/*}}}  */
/*{{{  SDFShortChar SDFmakeShortCharEscaped(SDFLexical lex) */

SDFShortChar SDFmakeShortCharEscaped(SDFLexical lex)
{
  return (SDFShortChar)ATmakeTerm(SDFpatternShortCharEscaped, lex);
}

/*}}}  */
/*{{{  SDFCharacter SDFmakeCharacterNumeric(SDFNumChar numChar) */

SDFCharacter SDFmakeCharacterNumeric(SDFNumChar numChar)
{
  return (SDFCharacter)ATmakeTerm(SDFpatternCharacterNumeric, numChar);
}

/*}}}  */
/*{{{  SDFCharacter SDFmakeCharacterShort(SDFShortChar shortChar) */

SDFCharacter SDFmakeCharacterShort(SDFShortChar shortChar)
{
  return (SDFCharacter)ATmakeTerm(SDFpatternCharacterShort, shortChar);
}

/*}}}  */
/*{{{  SDFCharacter SDFmakeCharacterTop() */

SDFCharacter SDFmakeCharacterTop()
{
  return (SDFCharacter)ATmakeTerm(SDFpatternCharacterTop);
}

/*}}}  */
/*{{{  SDFCharacter SDFmakeCharacterEof() */

SDFCharacter SDFmakeCharacterEof()
{
  return (SDFCharacter)ATmakeTerm(SDFpatternCharacterEof);
}

/*}}}  */
/*{{{  SDFOptExp SDFmakeOptExpPresent(SDFLayout wsAfterE, SDFIntCon intCon) */

SDFOptExp SDFmakeOptExpPresent(SDFLayout wsAfterE, SDFIntCon intCon)
{
  return (SDFOptExp)ATmakeTerm(SDFpatternOptExpPresent, wsAfterE, intCon);
}

/*}}}  */
/*{{{  SDFOptExp SDFmakeOptExpAbsent() */

SDFOptExp SDFmakeOptExpAbsent()
{
  return (SDFOptExp)ATmakeTerm(SDFpatternOptExpAbsent);
}

/*}}}  */
/*{{{  SDFRealCon SDFmakeRealConRealCon(SDFIntCon intCon, SDFLayout wsAfterIntCon, SDFLayout wsAfterPeriod, SDFNatCon natCon, SDFLayout wsAfterNatCon, SDFOptExp optExp) */

SDFRealCon SDFmakeRealConRealCon(SDFIntCon intCon, SDFLayout wsAfterIntCon, SDFLayout wsAfterPeriod, SDFNatCon natCon, SDFLayout wsAfterNatCon, SDFOptExp optExp)
{
  return (SDFRealCon)ATmakeTerm(SDFpatternRealConRealCon, intCon, wsAfterIntCon, wsAfterPeriod, natCon, wsAfterNatCon, optExp);
}

/*}}}  */

/*{{{  SDFSymbol accessor implementations */

/*{{{  ATbool SDFisValidSymbol(SDFSymbol arg) */

ATbool SDFisValidSymbol(SDFSymbol arg)
{
  if (SDFisSymbolStart(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolFileStart(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolCf(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolLex(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolVarsym(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolLayout(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolEmpty(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolSeq(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolOpt(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIter(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIterStar(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIterSep(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIterN(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIterSepN(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolSet(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolPair(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolFunc(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolAlt(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolPerm(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolCharClass(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolSort(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolLit(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolLabel(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisSymbolStart(SDFSymbol arg) */

ATbool SDFisSymbolStart(SDFSymbol arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolStart);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolFileStart(SDFSymbol arg) */

ATbool SDFisSymbolFileStart(SDFSymbol arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolFileStart);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolCf(SDFSymbol arg) */

ATbool SDFisSymbolCf(SDFSymbol arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolCf, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolLex(SDFSymbol arg) */

ATbool SDFisSymbolLex(SDFSymbol arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolLex, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolVarsym(SDFSymbol arg) */

ATbool SDFisSymbolVarsym(SDFSymbol arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolVarsym, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolLayout(SDFSymbol arg) */

ATbool SDFisSymbolLayout(SDFSymbol arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolLayout);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolEmpty(SDFSymbol arg) */

ATbool SDFisSymbolEmpty(SDFSymbol arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolEmpty, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolSeq(SDFSymbol arg) */

ATbool SDFisSymbolSeq(SDFSymbol arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolSeq, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolOpt(SDFSymbol arg) */

ATbool SDFisSymbolOpt(SDFSymbol arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolOpt, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolIter(SDFSymbol arg) */

ATbool SDFisSymbolIter(SDFSymbol arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolIter, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolIterStar(SDFSymbol arg) */

ATbool SDFisSymbolIterStar(SDFSymbol arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolIterStar, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolIterSep(SDFSymbol arg) */

ATbool SDFisSymbolIterSep(SDFSymbol arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolIterSep, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolIterStarSep(SDFSymbol arg) */

ATbool SDFisSymbolIterStarSep(SDFSymbol arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolIterStarSep, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolIterN(SDFSymbol arg) */

ATbool SDFisSymbolIterN(SDFSymbol arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolIterN, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolIterSepN(SDFSymbol arg) */

ATbool SDFisSymbolIterSepN(SDFSymbol arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolIterSepN, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolSet(SDFSymbol arg) */

ATbool SDFisSymbolSet(SDFSymbol arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolSet, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolPair(SDFSymbol arg) */

ATbool SDFisSymbolPair(SDFSymbol arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolPair, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolFunc(SDFSymbol arg) */

ATbool SDFisSymbolFunc(SDFSymbol arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolFunc, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolAlt(SDFSymbol arg) */

ATbool SDFisSymbolAlt(SDFSymbol arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolAlt, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolPerm(SDFSymbol arg) */

ATbool SDFisSymbolPerm(SDFSymbol arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolPerm, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolCharClass(SDFSymbol arg) */

ATbool SDFisSymbolCharClass(SDFSymbol arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolCharClass, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolSort(SDFSymbol arg) */

ATbool SDFisSymbolSort(SDFSymbol arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolSort, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolLit(SDFSymbol arg) */

ATbool SDFisSymbolLit(SDFSymbol arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolLit, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolLabel(SDFSymbol arg) */

ATbool SDFisSymbolLabel(SDFSymbol arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolLabel, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolBracket(SDFSymbol arg) */

ATbool SDFisSymbolBracket(SDFSymbol arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolBracket, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolWsAfterLessThanLessThan(SDFSymbol arg) */

ATbool SDFhasSymbolWsAfterLessThanLessThan(SDFSymbol arg)
{
  if (SDFisSymbolPerm(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolWsAfterLessThanLessThan(SDFSymbol arg) */

SDFLayout SDFgetSymbolWsAfterLessThanLessThan(SDFSymbol arg)
{
  if (SDFisSymbolPerm(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Symbol has no WsAfterLessThanLessThan: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolWsAfterLessThanLessThan(SDFSymbol arg, SDFLayout wsAfterLessThanLessThan) */

SDFSymbol SDFsetSymbolWsAfterLessThanLessThan(SDFSymbol arg, SDFLayout wsAfterLessThanLessThan)
{
  if (SDFisSymbolPerm(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLessThanLessThan, 0), 1), 2);
  }

  ATabort("Symbol has no WsAfterLessThanLessThan: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolRight(SDFSymbol arg) */

ATbool SDFhasSymbolRight(SDFSymbol arg)
{
  if (SDFisSymbolPair(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolAlt(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbol SDFgetSymbolRight(SDFSymbol arg) */

SDFSymbol SDFgetSymbolRight(SDFSymbol arg)
{
  if (SDFisSymbolPair(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDFisSymbolAlt(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Symbol has no Right: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolRight(SDFSymbol arg, SDFSymbol right) */

SDFSymbol SDFsetSymbolRight(SDFSymbol arg, SDFSymbol right)
{
  if (SDFisSymbolPair(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)right, 4), 2);
  }
  else if (SDFisSymbolAlt(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)right, 4), 2);
  }

  ATabort("Symbol has no Right: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolWsAfterLeft(SDFSymbol arg) */

ATbool SDFhasSymbolWsAfterLeft(SDFSymbol arg)
{
  if (SDFisSymbolPair(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolAlt(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolWsAfterLeft(SDFSymbol arg) */

SDFLayout SDFgetSymbolWsAfterLeft(SDFSymbol arg)
{
  if (SDFisSymbolPair(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisSymbolAlt(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Symbol has no WsAfterLeft: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolWsAfterLeft(SDFSymbol arg, SDFLayout wsAfterLeft) */

SDFSymbol SDFsetSymbolWsAfterLeft(SDFSymbol arg, SDFLayout wsAfterLeft)
{
  if (SDFisSymbolPair(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLeft, 0), 1), 2);
  }
  else if (SDFisSymbolAlt(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLeft, 0), 1), 2);
  }

  ATabort("Symbol has no WsAfterLeft: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolWsAfterParenOpen(SDFSymbol arg) */

ATbool SDFhasSymbolWsAfterParenOpen(SDFSymbol arg)
{
  if (SDFisSymbolEmpty(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolSeq(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolFunc(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolWsAfterParenOpen(SDFSymbol arg) */

SDFLayout SDFgetSymbolWsAfterParenOpen(SDFSymbol arg)
{
  if (SDFisSymbolEmpty(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisSymbolSeq(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisSymbolFunc(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisSymbolBracket(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Symbol has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolWsAfterParenOpen(SDFSymbol arg, SDFLayout wsAfterParenOpen) */

SDFSymbol SDFsetSymbolWsAfterParenOpen(SDFSymbol arg, SDFLayout wsAfterParenOpen)
{
  if (SDFisSymbolEmpty(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterParenOpen, 0), 1), 2);
  }
  else if (SDFisSymbolSeq(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterParenOpen, 0), 1), 2);
  }
  else if (SDFisSymbolFunc(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterParenOpen, 0), 1), 2);
  }
  else if (SDFisSymbolBracket(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterParenOpen, 0), 1), 2);
  }

  ATabort("Symbol has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolWsAfterArguments(SDFSymbol arg) */

ATbool SDFhasSymbolWsAfterArguments(SDFSymbol arg)
{
  if (SDFisSymbolFunc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolWsAfterArguments(SDFSymbol arg) */

SDFLayout SDFgetSymbolWsAfterArguments(SDFSymbol arg)
{
  if (SDFisSymbolFunc(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Symbol has no WsAfterArguments: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolWsAfterArguments(SDFSymbol arg, SDFLayout wsAfterArguments) */

SDFSymbol SDFsetSymbolWsAfterArguments(SDFSymbol arg, SDFLayout wsAfterArguments)
{
  if (SDFisSymbolFunc(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterArguments, 0), 3), 2);
  }

  ATabort("Symbol has no WsAfterArguments: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolWsAfterResults(SDFSymbol arg) */

ATbool SDFhasSymbolWsAfterResults(SDFSymbol arg)
{
  if (SDFisSymbolFunc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolWsAfterResults(SDFSymbol arg) */

SDFLayout SDFgetSymbolWsAfterResults(SDFSymbol arg)
{
  if (SDFisSymbolFunc(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), 0);
  }

  ATabort("Symbol has no WsAfterResults: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolWsAfterResults(SDFSymbol arg, SDFLayout wsAfterResults) */

SDFSymbol SDFsetSymbolWsAfterResults(SDFSymbol arg, SDFLayout wsAfterResults)
{
  if (SDFisSymbolFunc(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), (ATerm)wsAfterResults, 0), 7), 2);
  }

  ATabort("Symbol has no WsAfterResults: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolWsAfterHash(SDFSymbol arg) */

ATbool SDFhasSymbolWsAfterHash(SDFSymbol arg)
{
  if (SDFisSymbolPair(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolWsAfterHash(SDFSymbol arg) */

SDFLayout SDFgetSymbolWsAfterHash(SDFSymbol arg)
{
  if (SDFisSymbolPair(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Symbol has no WsAfterHash: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolWsAfterHash(SDFSymbol arg, SDFLayout wsAfterHash) */

SDFSymbol SDFsetSymbolWsAfterHash(SDFSymbol arg, SDFLayout wsAfterHash)
{
  if (SDFisSymbolPair(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterHash, 0), 3), 2);
  }

  ATabort("Symbol has no WsAfterHash: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolWsAfterCF(SDFSymbol arg) */

ATbool SDFhasSymbolWsAfterCF(SDFSymbol arg)
{
  if (SDFisSymbolCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolWsAfterCF(SDFSymbol arg) */

SDFLayout SDFgetSymbolWsAfterCF(SDFSymbol arg)
{
  if (SDFisSymbolCf(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("Symbol has no WsAfterCF: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolWsAfterCF(SDFSymbol arg, SDFLayout wsAfterCF) */

SDFSymbol SDFsetSymbolWsAfterCF(SDFSymbol arg, SDFLayout wsAfterCF)
{
  if (SDFisSymbolCf(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterCF, 0), 5), 2);
  }

  ATabort("Symbol has no WsAfterCF: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolSort(SDFSymbol arg) */

ATbool SDFhasSymbolSort(SDFSymbol arg)
{
  if (SDFisSymbolSort(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSort SDFgetSymbolSort(SDFSymbol arg) */

SDFSort SDFgetSymbolSort(SDFSymbol arg)
{
  if (SDFisSymbolSort(arg)) {
    return (SDFSort)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Symbol has no Sort: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolSort(SDFSymbol arg, SDFSort sort) */

SDFSymbol SDFsetSymbolSort(SDFSymbol arg, SDFSort sort)
{
  if (SDFisSymbolSort(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)sort, 0), 2);
  }

  ATabort("Symbol has no Sort: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolWsAfterBraceClose(SDFSymbol arg) */

ATbool SDFhasSymbolWsAfterBraceClose(SDFSymbol arg)
{
  if (SDFisSymbolIterSep(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIterSepN(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolWsAfterBraceClose(SDFSymbol arg) */

SDFLayout SDFgetSymbolWsAfterBraceClose(SDFSymbol arg)
{
  if (SDFisSymbolIterSep(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), 0);
  }
  else if (SDFisSymbolIterStarSep(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), 0);
  }
  else if (SDFisSymbolIterSepN(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), 0);
  }

  ATabort("Symbol has no WsAfterBraceClose: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolWsAfterBraceClose(SDFSymbol arg, SDFLayout wsAfterBraceClose) */

SDFSymbol SDFsetSymbolWsAfterBraceClose(SDFSymbol arg, SDFLayout wsAfterBraceClose)
{
  if (SDFisSymbolIterSep(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), (ATerm)wsAfterBraceClose, 0), 7), 2);
  }
  else if (SDFisSymbolIterStarSep(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), (ATerm)wsAfterBraceClose, 0), 7), 2);
  }
  else if (SDFisSymbolIterSepN(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), (ATerm)wsAfterBraceClose, 0), 7), 2);
  }

  ATabort("Symbol has no WsAfterBraceClose: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolWsAfterBar(SDFSymbol arg) */

ATbool SDFhasSymbolWsAfterBar(SDFSymbol arg)
{
  if (SDFisSymbolAlt(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolWsAfterBar(SDFSymbol arg) */

SDFLayout SDFgetSymbolWsAfterBar(SDFSymbol arg)
{
  if (SDFisSymbolAlt(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Symbol has no WsAfterBar: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolWsAfterBar(SDFSymbol arg, SDFLayout wsAfterBar) */

SDFSymbol SDFsetSymbolWsAfterBar(SDFSymbol arg, SDFLayout wsAfterBar)
{
  if (SDFisSymbolAlt(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterBar, 0), 3), 2);
  }

  ATabort("Symbol has no WsAfterBar: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolWsAfterBraceOpen(SDFSymbol arg) */

ATbool SDFhasSymbolWsAfterBraceOpen(SDFSymbol arg)
{
  if (SDFisSymbolIterSep(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIterSepN(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolWsAfterBraceOpen(SDFSymbol arg) */

SDFLayout SDFgetSymbolWsAfterBraceOpen(SDFSymbol arg)
{
  if (SDFisSymbolIterSep(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisSymbolIterStarSep(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisSymbolIterSepN(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Symbol has no WsAfterBraceOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolWsAfterBraceOpen(SDFSymbol arg, SDFLayout wsAfterBraceOpen) */

SDFSymbol SDFsetSymbolWsAfterBraceOpen(SDFSymbol arg, SDFLayout wsAfterBraceOpen)
{
  if (SDFisSymbolIterSep(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterBraceOpen, 0), 1), 2);
  }
  else if (SDFisSymbolIterStarSep(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterBraceOpen, 0), 1), 2);
  }
  else if (SDFisSymbolIterSepN(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterBraceOpen, 0), 1), 2);
  }

  ATabort("Symbol has no WsAfterBraceOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolArguments(SDFSymbol arg) */

ATbool SDFhasSymbolArguments(SDFSymbol arg)
{
  if (SDFisSymbolFunc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbols SDFgetSymbolArguments(SDFSymbol arg) */

SDFSymbols SDFgetSymbolArguments(SDFSymbol arg)
{
  if (SDFisSymbolFunc(arg)) {
    return (SDFSymbols)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Symbol has no Arguments: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolArguments(SDFSymbol arg, SDFSymbols arguments) */

SDFSymbol SDFsetSymbolArguments(SDFSymbol arg, SDFSymbols arguments)
{
  if (SDFisSymbolFunc(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)arguments, 2), 2);
  }

  ATabort("Symbol has no Arguments: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolWsAfterSymbols(SDFSymbol arg) */

ATbool SDFhasSymbolWsAfterSymbols(SDFSymbol arg)
{
  if (SDFisSymbolPerm(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolWsAfterSymbols(SDFSymbol arg) */

SDFLayout SDFgetSymbolWsAfterSymbols(SDFSymbol arg)
{
  if (SDFisSymbolPerm(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Symbol has no WsAfterSymbols: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolWsAfterSymbols(SDFSymbol arg, SDFLayout wsAfterSymbols) */

SDFSymbol SDFsetSymbolWsAfterSymbols(SDFSymbol arg, SDFLayout wsAfterSymbols)
{
  if (SDFisSymbolPerm(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSymbols, 0), 3), 2);
  }

  ATabort("Symbol has no WsAfterSymbols: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolWsAfterSep(SDFSymbol arg) */

ATbool SDFhasSymbolWsAfterSep(SDFSymbol arg)
{
  if (SDFisSymbolIterSep(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIterSepN(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolWsAfterSep(SDFSymbol arg) */

SDFLayout SDFgetSymbolWsAfterSep(SDFSymbol arg)
{
  if (SDFisSymbolIterSep(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }
  else if (SDFisSymbolIterStarSep(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }
  else if (SDFisSymbolIterSepN(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("Symbol has no WsAfterSep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolWsAfterSep(SDFSymbol arg, SDFLayout wsAfterSep) */

SDFSymbol SDFsetSymbolWsAfterSep(SDFSymbol arg, SDFLayout wsAfterSep)
{
  if (SDFisSymbolIterSep(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterSep, 0), 5), 2);
  }
  else if (SDFisSymbolIterStarSep(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterSep, 0), 5), 2);
  }
  else if (SDFisSymbolIterSepN(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterSep, 0), 5), 2);
  }

  ATabort("Symbol has no WsAfterSep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolTail(SDFSymbol arg) */

ATbool SDFhasSymbolTail(SDFSymbol arg)
{
  if (SDFisSymbolSeq(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbolTail SDFgetSymbolTail(SDFSymbol arg) */

SDFSymbolTail SDFgetSymbolTail(SDFSymbol arg)
{
  if (SDFisSymbolSeq(arg)) {
    return (SDFSymbolTail)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4), 2);
  }

  ATabort("Symbol has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolTail(SDFSymbol arg, SDFSymbolTail tail) */

SDFSymbol SDFsetSymbolTail(SDFSymbol arg, SDFSymbolTail tail)
{
  if (SDFisSymbolSeq(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4), (ATerm)tail, 2), 4), 2);
  }

  ATabort("Symbol has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolHead(SDFSymbol arg) */

ATbool SDFhasSymbolHead(SDFSymbol arg)
{
  if (SDFisSymbolSeq(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbol SDFgetSymbolHead(SDFSymbol arg) */

SDFSymbol SDFgetSymbolHead(SDFSymbol arg)
{
  if (SDFisSymbolSeq(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Symbol has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolHead(SDFSymbol arg, SDFSymbol head) */

SDFSymbol SDFsetSymbolHead(SDFSymbol arg, SDFSymbol head)
{
  if (SDFisSymbolSeq(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)head, 2), 2);
  }

  ATabort("Symbol has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolWsAfterSymbol(SDFSymbol arg) */

ATbool SDFhasSymbolWsAfterSymbol(SDFSymbol arg)
{
  if (SDFisSymbolCf(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolLex(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolVarsym(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolOpt(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIter(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIterStar(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIterSep(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIterN(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIterSepN(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolSet(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolWsAfterSymbol(SDFSymbol arg) */

SDFLayout SDFgetSymbolWsAfterSymbol(SDFSymbol arg)
{
  if (SDFisSymbolCf(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDFisSymbolLex(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDFisSymbolVarsym(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDFisSymbolOpt(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisSymbolIter(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisSymbolIterStar(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisSymbolIterSep(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDFisSymbolIterStarSep(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDFisSymbolIterN(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisSymbolIterSepN(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDFisSymbolSet(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }
  else if (SDFisSymbolBracket(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Symbol has no WsAfterSymbol: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolWsAfterSymbol(SDFSymbol arg, SDFLayout wsAfterSymbol) */

SDFSymbol SDFsetSymbolWsAfterSymbol(SDFSymbol arg, SDFLayout wsAfterSymbol)
{
  if (SDFisSymbolCf(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSymbol, 0), 3), 2);
  }
  else if (SDFisSymbolLex(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSymbol, 0), 3), 2);
  }
  else if (SDFisSymbolVarsym(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSymbol, 0), 3), 2);
  }
  else if (SDFisSymbolOpt(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterSymbol, 0), 1), 2);
  }
  else if (SDFisSymbolIter(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterSymbol, 0), 1), 2);
  }
  else if (SDFisSymbolIterStar(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterSymbol, 0), 1), 2);
  }
  else if (SDFisSymbolIterSep(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSymbol, 0), 3), 2);
  }
  else if (SDFisSymbolIterStarSep(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSymbol, 0), 3), 2);
  }
  else if (SDFisSymbolIterN(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterSymbol, 0), 1), 2);
  }
  else if (SDFisSymbolIterSepN(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSymbol, 0), 3), 2);
  }
  else if (SDFisSymbolSet(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterSymbol, 0), 5), 2);
  }
  else if (SDFisSymbolBracket(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSymbol, 0), 3), 2);
  }

  ATabort("Symbol has no WsAfterSymbol: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolWsAfterN(SDFSymbol arg) */

ATbool SDFhasSymbolWsAfterN(SDFSymbol arg)
{
  if (SDFisSymbolIterN(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIterSepN(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolWsAfterN(SDFSymbol arg) */

SDFLayout SDFgetSymbolWsAfterN(SDFSymbol arg)
{
  if (SDFisSymbolIterN(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDFisSymbolIterSepN(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 9), 0);
  }

  ATabort("Symbol has no WsAfterN: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolWsAfterN(SDFSymbol arg, SDFLayout wsAfterN) */

SDFSymbol SDFsetSymbolWsAfterN(SDFSymbol arg, SDFLayout wsAfterN)
{
  if (SDFisSymbolIterN(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterN, 0), 3), 2);
  }
  else if (SDFisSymbolIterSepN(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 9), (ATerm)wsAfterN, 0), 9), 2);
  }

  ATabort("Symbol has no WsAfterN: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolSymbol(SDFSymbol arg) */

ATbool SDFhasSymbolSymbol(SDFSymbol arg)
{
  if (SDFisSymbolCf(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolLex(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolVarsym(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolOpt(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIter(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIterStar(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIterSep(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIterN(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIterSepN(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolSet(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolLabel(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbol SDFgetSymbolSymbol(SDFSymbol arg) */

SDFSymbol SDFgetSymbolSymbol(SDFSymbol arg)
{
  if (SDFisSymbolCf(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDFisSymbolLex(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDFisSymbolVarsym(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDFisSymbolOpt(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDFisSymbolIter(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDFisSymbolIterStar(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDFisSymbolIterSep(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDFisSymbolIterStarSep(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDFisSymbolIterN(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDFisSymbolIterSepN(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDFisSymbolSet(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDFisSymbolLabel(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDFisSymbolBracket(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Symbol has no Symbol: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolSymbol(SDFSymbol arg, SDFSymbol symbol) */

SDFSymbol SDFsetSymbolSymbol(SDFSymbol arg, SDFSymbol symbol)
{
  if (SDFisSymbolCf(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 2), 2);
  }
  else if (SDFisSymbolLex(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 2), 2);
  }
  else if (SDFisSymbolVarsym(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 2), 2);
  }
  else if (SDFisSymbolOpt(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 0), 2);
  }
  else if (SDFisSymbolIter(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 0), 2);
  }
  else if (SDFisSymbolIterStar(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 0), 2);
  }
  else if (SDFisSymbolIterSep(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 2), 2);
  }
  else if (SDFisSymbolIterStarSep(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 2), 2);
  }
  else if (SDFisSymbolIterN(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 0), 2);
  }
  else if (SDFisSymbolIterSepN(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 2), 2);
  }
  else if (SDFisSymbolSet(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 4), 2);
  }
  else if (SDFisSymbolLabel(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 4), 2);
  }
  else if (SDFisSymbolBracket(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 2), 2);
  }

  ATabort("Symbol has no Symbol: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolLiteral(SDFSymbol arg) */

ATbool SDFhasSymbolLiteral(SDFSymbol arg)
{
  if (SDFisSymbolLit(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLiteral SDFgetSymbolLiteral(SDFSymbol arg) */

SDFLiteral SDFgetSymbolLiteral(SDFSymbol arg)
{
  if (SDFisSymbolLit(arg)) {
    return (SDFLiteral)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Symbol has no Literal: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolLiteral(SDFSymbol arg, SDFLiteral literal) */

SDFSymbol SDFsetSymbolLiteral(SDFSymbol arg, SDFLiteral literal)
{
  if (SDFisSymbolLit(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)literal, 0), 2);
  }

  ATabort("Symbol has no Literal: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolResults(SDFSymbol arg) */

ATbool SDFhasSymbolResults(SDFSymbol arg)
{
  if (SDFisSymbolFunc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbol SDFgetSymbolResults(SDFSymbol arg) */

SDFSymbol SDFgetSymbolResults(SDFSymbol arg)
{
  if (SDFisSymbolFunc(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 6);
  }

  ATabort("Symbol has no Results: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolResults(SDFSymbol arg, SDFSymbol results) */

SDFSymbol SDFsetSymbolResults(SDFSymbol arg, SDFSymbol results)
{
  if (SDFisSymbolFunc(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)results, 6), 2);
  }

  ATabort("Symbol has no Results: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolCharClass(SDFSymbol arg) */

ATbool SDFhasSymbolCharClass(SDFSymbol arg)
{
  if (SDFisSymbolCharClass(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFCharClass SDFgetSymbolCharClass(SDFSymbol arg) */

SDFCharClass SDFgetSymbolCharClass(SDFSymbol arg)
{
  if (SDFisSymbolCharClass(arg)) {
    return (SDFCharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Symbol has no CharClass: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolCharClass(SDFSymbol arg, SDFCharClass charClass) */

SDFSymbol SDFsetSymbolCharClass(SDFSymbol arg, SDFCharClass charClass)
{
  if (SDFisSymbolCharClass(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)charClass, 0), 2);
  }

  ATabort("Symbol has no CharClass: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolWsAfterBracketOpen(SDFSymbol arg) */

ATbool SDFhasSymbolWsAfterBracketOpen(SDFSymbol arg)
{
  if (SDFisSymbolSet(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolWsAfterBracketOpen(SDFSymbol arg) */

SDFLayout SDFgetSymbolWsAfterBracketOpen(SDFSymbol arg)
{
  if (SDFisSymbolSet(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Symbol has no WsAfterBracketOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolWsAfterBracketOpen(SDFSymbol arg, SDFLayout wsAfterBracketOpen) */

SDFSymbol SDFsetSymbolWsAfterBracketOpen(SDFSymbol arg, SDFLayout wsAfterBracketOpen)
{
  if (SDFisSymbolSet(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterBracketOpen, 0), 3), 2);
  }

  ATabort("Symbol has no WsAfterBracketOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolWsAfterTail(SDFSymbol arg) */

ATbool SDFhasSymbolWsAfterTail(SDFSymbol arg)
{
  if (SDFisSymbolSeq(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolWsAfterTail(SDFSymbol arg) */

SDFLayout SDFgetSymbolWsAfterTail(SDFSymbol arg)
{
  if (SDFisSymbolSeq(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("Symbol has no WsAfterTail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolWsAfterTail(SDFSymbol arg, SDFLayout wsAfterTail) */

SDFSymbol SDFsetSymbolWsAfterTail(SDFSymbol arg, SDFLayout wsAfterTail)
{
  if (SDFisSymbolSeq(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterTail, 0), 5), 2);
  }

  ATabort("Symbol has no WsAfterTail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolWsAfterHead(SDFSymbol arg) */

ATbool SDFhasSymbolWsAfterHead(SDFSymbol arg)
{
  if (SDFisSymbolSeq(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolWsAfterHead(SDFSymbol arg) */

SDFLayout SDFgetSymbolWsAfterHead(SDFSymbol arg)
{
  if (SDFisSymbolSeq(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Symbol has no WsAfterHead: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolWsAfterHead(SDFSymbol arg, SDFLayout wsAfterHead) */

SDFSymbol SDFsetSymbolWsAfterHead(SDFSymbol arg, SDFLayout wsAfterHead)
{
  if (SDFisSymbolSeq(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterHead, 0), 3), 2);
  }

  ATabort("Symbol has no WsAfterHead: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolWsAfterEqualsGreaterThan(SDFSymbol arg) */

ATbool SDFhasSymbolWsAfterEqualsGreaterThan(SDFSymbol arg)
{
  if (SDFisSymbolFunc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolWsAfterEqualsGreaterThan(SDFSymbol arg) */

SDFLayout SDFgetSymbolWsAfterEqualsGreaterThan(SDFSymbol arg)
{
  if (SDFisSymbolFunc(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("Symbol has no WsAfterEqualsGreaterThan: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolWsAfterEqualsGreaterThan(SDFSymbol arg, SDFLayout wsAfterEqualsGreaterThan) */

SDFSymbol SDFsetSymbolWsAfterEqualsGreaterThan(SDFSymbol arg, SDFLayout wsAfterEqualsGreaterThan)
{
  if (SDFisSymbolFunc(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterEqualsGreaterThan, 0), 5), 2);
  }

  ATabort("Symbol has no WsAfterEqualsGreaterThan: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolSep(SDFSymbol arg) */

ATbool SDFhasSymbolSep(SDFSymbol arg)
{
  if (SDFisSymbolIterSep(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIterSepN(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbol SDFgetSymbolSep(SDFSymbol arg) */

SDFSymbol SDFgetSymbolSep(SDFSymbol arg)
{
  if (SDFisSymbolIterSep(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDFisSymbolIterStarSep(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDFisSymbolIterSepN(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Symbol has no Sep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolSep(SDFSymbol arg, SDFSymbol sep) */

SDFSymbol SDFsetSymbolSep(SDFSymbol arg, SDFSymbol sep)
{
  if (SDFisSymbolIterSep(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)sep, 4), 2);
  }
  else if (SDFisSymbolIterStarSep(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)sep, 4), 2);
  }
  else if (SDFisSymbolIterSepN(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)sep, 4), 2);
  }

  ATabort("Symbol has no Sep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolSymbols(SDFSymbol arg) */

ATbool SDFhasSymbolSymbols(SDFSymbol arg)
{
  if (SDFisSymbolPerm(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbols SDFgetSymbolSymbols(SDFSymbol arg) */

SDFSymbols SDFgetSymbolSymbols(SDFSymbol arg)
{
  if (SDFisSymbolPerm(arg)) {
    return (SDFSymbols)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Symbol has no Symbols: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolSymbols(SDFSymbol arg, SDFSymbols symbols) */

SDFSymbol SDFsetSymbolSymbols(SDFSymbol arg, SDFSymbols symbols)
{
  if (SDFisSymbolPerm(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbols, 2), 2);
  }

  ATabort("Symbol has no Symbols: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolWsAfterSet(SDFSymbol arg) */

ATbool SDFhasSymbolWsAfterSet(SDFSymbol arg)
{
  if (SDFisSymbolSet(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolWsAfterSet(SDFSymbol arg) */

SDFLayout SDFgetSymbolWsAfterSet(SDFSymbol arg)
{
  if (SDFisSymbolSet(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Symbol has no WsAfterSet: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolWsAfterSet(SDFSymbol arg, SDFLayout wsAfterSet) */

SDFSymbol SDFsetSymbolWsAfterSet(SDFSymbol arg, SDFLayout wsAfterSet)
{
  if (SDFisSymbolSet(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterSet, 0), 1), 2);
  }

  ATabort("Symbol has no WsAfterSet: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolLeft(SDFSymbol arg) */

ATbool SDFhasSymbolLeft(SDFSymbol arg)
{
  if (SDFisSymbolPair(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolAlt(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbol SDFgetSymbolLeft(SDFSymbol arg) */

SDFSymbol SDFgetSymbolLeft(SDFSymbol arg)
{
  if (SDFisSymbolPair(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDFisSymbolAlt(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Symbol has no Left: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolLeft(SDFSymbol arg, SDFSymbol left) */

SDFSymbol SDFsetSymbolLeft(SDFSymbol arg, SDFSymbol left)
{
  if (SDFisSymbolPair(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)left, 0), 2);
  }
  else if (SDFisSymbolAlt(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)left, 0), 2);
  }

  ATabort("Symbol has no Left: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolWsAfterLEX(SDFSymbol arg) */

ATbool SDFhasSymbolWsAfterLEX(SDFSymbol arg)
{
  if (SDFisSymbolLex(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolWsAfterLEX(SDFSymbol arg) */

SDFLayout SDFgetSymbolWsAfterLEX(SDFSymbol arg)
{
  if (SDFisSymbolLex(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("Symbol has no WsAfterLEX: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolWsAfterLEX(SDFSymbol arg, SDFLayout wsAfterLEX) */

SDFSymbol SDFsetSymbolWsAfterLEX(SDFSymbol arg, SDFLayout wsAfterLEX)
{
  if (SDFisSymbolLex(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterLEX, 0), 5), 2);
  }

  ATabort("Symbol has no WsAfterLEX: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolLabel(SDFSymbol arg) */

ATbool SDFhasSymbolLabel(SDFSymbol arg)
{
  if (SDFisSymbolLabel(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLiteral SDFgetSymbolLabel(SDFSymbol arg) */

SDFLiteral SDFgetSymbolLabel(SDFSymbol arg)
{
  if (SDFisSymbolLabel(arg)) {
    return (SDFLiteral)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Symbol has no Label: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolLabel(SDFSymbol arg, SDFLiteral label) */

SDFSymbol SDFsetSymbolLabel(SDFSymbol arg, SDFLiteral label)
{
  if (SDFisSymbolLabel(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)label, 0), 2);
  }

  ATabort("Symbol has no Label: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolN(SDFSymbol arg) */

ATbool SDFhasSymbolN(SDFSymbol arg)
{
  if (SDFisSymbolIterN(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolIterSepN(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFNatCon SDFgetSymbolN(SDFSymbol arg) */

SDFNatCon SDFgetSymbolN(SDFSymbol arg)
{
  if (SDFisSymbolIterN(arg)) {
    return (SDFNatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDFisSymbolIterSepN(arg)) {
    return (SDFNatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 8);
  }

  ATabort("Symbol has no N: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolN(SDFSymbol arg, SDFNatCon n) */

SDFSymbol SDFsetSymbolN(SDFSymbol arg, SDFNatCon n)
{
  if (SDFisSymbolIterN(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)n, 2), 2);
  }
  else if (SDFisSymbolIterSepN(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)n, 8), 2);
  }

  ATabort("Symbol has no N: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolWsAfterLessThan(SDFSymbol arg) */

ATbool SDFhasSymbolWsAfterLessThan(SDFSymbol arg)
{
  if (SDFisSymbolCf(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolLex(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolVarsym(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolWsAfterLessThan(SDFSymbol arg) */

SDFLayout SDFgetSymbolWsAfterLessThan(SDFSymbol arg)
{
  if (SDFisSymbolCf(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisSymbolLex(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisSymbolVarsym(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Symbol has no WsAfterLessThan: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolWsAfterLessThan(SDFSymbol arg, SDFLayout wsAfterLessThan) */

SDFSymbol SDFsetSymbolWsAfterLessThan(SDFSymbol arg, SDFLayout wsAfterLessThan)
{
  if (SDFisSymbolCf(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLessThan, 0), 1), 2);
  }
  else if (SDFisSymbolLex(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLessThan, 0), 1), 2);
  }
  else if (SDFisSymbolVarsym(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLessThan, 0), 1), 2);
  }

  ATabort("Symbol has no WsAfterLessThan: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolWsAfterColon(SDFSymbol arg) */

ATbool SDFhasSymbolWsAfterColon(SDFSymbol arg)
{
  if (SDFisSymbolLabel(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolWsAfterColon(SDFSymbol arg) */

SDFLayout SDFgetSymbolWsAfterColon(SDFSymbol arg)
{
  if (SDFisSymbolLabel(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Symbol has no WsAfterColon: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolWsAfterColon(SDFSymbol arg, SDFLayout wsAfterColon) */

SDFSymbol SDFsetSymbolWsAfterColon(SDFSymbol arg, SDFLayout wsAfterColon)
{
  if (SDFisSymbolLabel(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterColon, 0), 3), 2);
  }

  ATabort("Symbol has no WsAfterColon: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolWsAfterLabel(SDFSymbol arg) */

ATbool SDFhasSymbolWsAfterLabel(SDFSymbol arg)
{
  if (SDFisSymbolLabel(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolWsAfterLabel(SDFSymbol arg) */

SDFLayout SDFgetSymbolWsAfterLabel(SDFSymbol arg)
{
  if (SDFisSymbolLabel(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Symbol has no WsAfterLabel: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolWsAfterLabel(SDFSymbol arg, SDFLayout wsAfterLabel) */

SDFSymbol SDFsetSymbolWsAfterLabel(SDFSymbol arg, SDFLayout wsAfterLabel)
{
  if (SDFisSymbolLabel(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLabel, 0), 1), 2);
  }

  ATabort("Symbol has no WsAfterLabel: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolWsAfterVAR(SDFSymbol arg) */

ATbool SDFhasSymbolWsAfterVAR(SDFSymbol arg)
{
  if (SDFisSymbolVarsym(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolWsAfterVAR(SDFSymbol arg) */

SDFLayout SDFgetSymbolWsAfterVAR(SDFSymbol arg)
{
  if (SDFisSymbolVarsym(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("Symbol has no WsAfterVAR: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbol SDFsetSymbolWsAfterVAR(SDFSymbol arg, SDFLayout wsAfterVAR) */

SDFSymbol SDFsetSymbolWsAfterVAR(SDFSymbol arg, SDFLayout wsAfterVAR)
{
  if (SDFisSymbolVarsym(arg)) {
    return (SDFSymbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterVAR, 0), 5), 2);
  }

  ATabort("Symbol has no WsAfterVAR: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFGrammar accessor implementations */

/*{{{  ATbool SDFisValidGrammar(SDFGrammar arg) */

ATbool SDFisValidGrammar(SDFGrammar arg)
{
  if (SDFisGrammarLexicalPriorities(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarContextFreePriorities(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarLexicalRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarContextFreeRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarSyntax(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarLexicalSyntax(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarContextFreeSyntax(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarVariables(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarLexicalVariables(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarImpSection(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarPriorities(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarSorts(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarAliases(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarEmptyGrammar(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarConcGrammars(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisGrammarLexicalPriorities(SDFGrammar arg) */

ATbool SDFisGrammarLexicalPriorities(SDFGrammar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternGrammarLexicalPriorities, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisGrammarContextFreePriorities(SDFGrammar arg) */

ATbool SDFisGrammarContextFreePriorities(SDFGrammar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternGrammarContextFreePriorities, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisGrammarLexicalRestrictions(SDFGrammar arg) */

ATbool SDFisGrammarLexicalRestrictions(SDFGrammar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternGrammarLexicalRestrictions, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisGrammarContextFreeRestrictions(SDFGrammar arg) */

ATbool SDFisGrammarContextFreeRestrictions(SDFGrammar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternGrammarContextFreeRestrictions, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisGrammarSyntax(SDFGrammar arg) */

ATbool SDFisGrammarSyntax(SDFGrammar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternGrammarSyntax, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisGrammarLexicalSyntax(SDFGrammar arg) */

ATbool SDFisGrammarLexicalSyntax(SDFGrammar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternGrammarLexicalSyntax, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisGrammarContextFreeSyntax(SDFGrammar arg) */

ATbool SDFisGrammarContextFreeSyntax(SDFGrammar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternGrammarContextFreeSyntax, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisGrammarVariables(SDFGrammar arg) */

ATbool SDFisGrammarVariables(SDFGrammar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternGrammarVariables, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisGrammarLexicalVariables(SDFGrammar arg) */

ATbool SDFisGrammarLexicalVariables(SDFGrammar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternGrammarLexicalVariables, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisGrammarImpSection(SDFGrammar arg) */

ATbool SDFisGrammarImpSection(SDFGrammar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternGrammarImpSection, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisGrammarPriorities(SDFGrammar arg) */

ATbool SDFisGrammarPriorities(SDFGrammar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternGrammarPriorities, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisGrammarSorts(SDFGrammar arg) */

ATbool SDFisGrammarSorts(SDFGrammar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternGrammarSorts, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisGrammarRestrictions(SDFGrammar arg) */

ATbool SDFisGrammarRestrictions(SDFGrammar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternGrammarRestrictions, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisGrammarAliases(SDFGrammar arg) */

ATbool SDFisGrammarAliases(SDFGrammar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternGrammarAliases, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisGrammarEmptyGrammar(SDFGrammar arg) */

ATbool SDFisGrammarEmptyGrammar(SDFGrammar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternGrammarEmptyGrammar);
}

/*}}}  */
/*{{{  ATbool SDFisGrammarConcGrammars(SDFGrammar arg) */

ATbool SDFisGrammarConcGrammars(SDFGrammar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternGrammarConcGrammars, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisGrammarBracket(SDFGrammar arg) */

ATbool SDFisGrammarBracket(SDFGrammar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternGrammarBracket, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasGrammarRight(SDFGrammar arg) */

ATbool SDFhasGrammarRight(SDFGrammar arg)
{
  if (SDFisGrammarConcGrammars(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFGrammar SDFgetGrammarRight(SDFGrammar arg) */

SDFGrammar SDFgetGrammarRight(SDFGrammar arg)
{
  if (SDFisGrammarConcGrammars(arg)) {
    return (SDFGrammar)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Grammar has no Right: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGrammar SDFsetGrammarRight(SDFGrammar arg, SDFGrammar right) */

SDFGrammar SDFsetGrammarRight(SDFGrammar arg, SDFGrammar right)
{
  if (SDFisGrammarConcGrammars(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)right, 2), 2);
  }

  ATabort("Grammar has no Right: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGrammarWsAfterLeft(SDFGrammar arg) */

ATbool SDFhasGrammarWsAfterLeft(SDFGrammar arg)
{
  if (SDFisGrammarConcGrammars(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetGrammarWsAfterLeft(SDFGrammar arg) */

SDFLayout SDFgetGrammarWsAfterLeft(SDFGrammar arg)
{
  if (SDFisGrammarConcGrammars(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Grammar has no WsAfterLeft: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGrammar SDFsetGrammarWsAfterLeft(SDFGrammar arg, SDFLayout wsAfterLeft) */

SDFGrammar SDFsetGrammarWsAfterLeft(SDFGrammar arg, SDFLayout wsAfterLeft)
{
  if (SDFisGrammarConcGrammars(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLeft, 0), 1), 2);
  }

  ATabort("Grammar has no WsAfterLeft: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGrammarWsAfterParenOpen(SDFGrammar arg) */

ATbool SDFhasGrammarWsAfterParenOpen(SDFGrammar arg)
{
  if (SDFisGrammarBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetGrammarWsAfterParenOpen(SDFGrammar arg) */

SDFLayout SDFgetGrammarWsAfterParenOpen(SDFGrammar arg)
{
  if (SDFisGrammarBracket(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Grammar has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGrammar SDFsetGrammarWsAfterParenOpen(SDFGrammar arg, SDFLayout wsAfterParenOpen) */

SDFGrammar SDFsetGrammarWsAfterParenOpen(SDFGrammar arg, SDFLayout wsAfterParenOpen)
{
  if (SDFisGrammarBracket(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterParenOpen, 0), 1), 2);
  }

  ATabort("Grammar has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGrammarWsAfterSorts(SDFGrammar arg) */

ATbool SDFhasGrammarWsAfterSorts(SDFGrammar arg)
{
  if (SDFisGrammarSorts(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetGrammarWsAfterSorts(SDFGrammar arg) */

SDFLayout SDFgetGrammarWsAfterSorts(SDFGrammar arg)
{
  if (SDFisGrammarSorts(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Grammar has no WsAfterSorts: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGrammar SDFsetGrammarWsAfterSorts(SDFGrammar arg, SDFLayout wsAfterSorts) */

SDFGrammar SDFsetGrammarWsAfterSorts(SDFGrammar arg, SDFLayout wsAfterSorts)
{
  if (SDFisGrammarSorts(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterSorts, 0), 1), 2);
  }

  ATabort("Grammar has no WsAfterSorts: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGrammarWsAfterPriorities(SDFGrammar arg) */

ATbool SDFhasGrammarWsAfterPriorities(SDFGrammar arg)
{
  if (SDFisGrammarLexicalPriorities(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarContextFreePriorities(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarPriorities(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetGrammarWsAfterPriorities(SDFGrammar arg) */

SDFLayout SDFgetGrammarWsAfterPriorities(SDFGrammar arg)
{
  if (SDFisGrammarLexicalPriorities(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDFisGrammarContextFreePriorities(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDFisGrammarPriorities(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Grammar has no WsAfterPriorities: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGrammar SDFsetGrammarWsAfterPriorities(SDFGrammar arg, SDFLayout wsAfterPriorities) */

SDFGrammar SDFsetGrammarWsAfterPriorities(SDFGrammar arg, SDFLayout wsAfterPriorities)
{
  if (SDFisGrammarLexicalPriorities(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterPriorities, 0), 3), 2);
  }
  else if (SDFisGrammarContextFreePriorities(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterPriorities, 0), 3), 2);
  }
  else if (SDFisGrammarPriorities(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterPriorities, 0), 1), 2);
  }

  ATabort("Grammar has no WsAfterPriorities: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGrammarWsAfterGrammar(SDFGrammar arg) */

ATbool SDFhasGrammarWsAfterGrammar(SDFGrammar arg)
{
  if (SDFisGrammarBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetGrammarWsAfterGrammar(SDFGrammar arg) */

SDFLayout SDFgetGrammarWsAfterGrammar(SDFGrammar arg)
{
  if (SDFisGrammarBracket(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Grammar has no WsAfterGrammar: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGrammar SDFsetGrammarWsAfterGrammar(SDFGrammar arg, SDFLayout wsAfterGrammar) */

SDFGrammar SDFsetGrammarWsAfterGrammar(SDFGrammar arg, SDFLayout wsAfterGrammar)
{
  if (SDFisGrammarBracket(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterGrammar, 0), 3), 2);
  }

  ATabort("Grammar has no WsAfterGrammar: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGrammarAliases(SDFGrammar arg) */

ATbool SDFhasGrammarAliases(SDFGrammar arg)
{
  if (SDFisGrammarAliases(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFAliases SDFgetGrammarAliases(SDFGrammar arg) */

SDFAliases SDFgetGrammarAliases(SDFGrammar arg)
{
  if (SDFisGrammarAliases(arg)) {
    return (SDFAliases)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Grammar has no Aliases: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGrammar SDFsetGrammarAliases(SDFGrammar arg, SDFAliases aliases) */

SDFGrammar SDFsetGrammarAliases(SDFGrammar arg, SDFAliases aliases)
{
  if (SDFisGrammarAliases(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aliases, 2), 2);
  }

  ATabort("Grammar has no Aliases: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGrammarWsAfterSyntax(SDFGrammar arg) */

ATbool SDFhasGrammarWsAfterSyntax(SDFGrammar arg)
{
  if (SDFisGrammarSyntax(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarLexicalSyntax(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarContextFreeSyntax(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetGrammarWsAfterSyntax(SDFGrammar arg) */

SDFLayout SDFgetGrammarWsAfterSyntax(SDFGrammar arg)
{
  if (SDFisGrammarSyntax(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisGrammarLexicalSyntax(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDFisGrammarContextFreeSyntax(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Grammar has no WsAfterSyntax: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGrammar SDFsetGrammarWsAfterSyntax(SDFGrammar arg, SDFLayout wsAfterSyntax) */

SDFGrammar SDFsetGrammarWsAfterSyntax(SDFGrammar arg, SDFLayout wsAfterSyntax)
{
  if (SDFisGrammarSyntax(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterSyntax, 0), 1), 2);
  }
  else if (SDFisGrammarLexicalSyntax(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSyntax, 0), 3), 2);
  }
  else if (SDFisGrammarContextFreeSyntax(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSyntax, 0), 3), 2);
  }

  ATabort("Grammar has no WsAfterSyntax: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGrammarPriorities(SDFGrammar arg) */

ATbool SDFhasGrammarPriorities(SDFGrammar arg)
{
  if (SDFisGrammarLexicalPriorities(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarContextFreePriorities(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarPriorities(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFPriorities SDFgetGrammarPriorities(SDFGrammar arg) */

SDFPriorities SDFgetGrammarPriorities(SDFGrammar arg)
{
  if (SDFisGrammarLexicalPriorities(arg)) {
    return (SDFPriorities)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDFisGrammarContextFreePriorities(arg)) {
    return (SDFPriorities)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDFisGrammarPriorities(arg)) {
    return (SDFPriorities)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Grammar has no Priorities: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGrammar SDFsetGrammarPriorities(SDFGrammar arg, SDFPriorities priorities) */

SDFGrammar SDFsetGrammarPriorities(SDFGrammar arg, SDFPriorities priorities)
{
  if (SDFisGrammarLexicalPriorities(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)priorities, 4), 2);
  }
  else if (SDFisGrammarContextFreePriorities(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)priorities, 4), 2);
  }
  else if (SDFisGrammarPriorities(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)priorities, 2), 2);
  }

  ATabort("Grammar has no Priorities: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGrammarRestrictions(SDFGrammar arg) */

ATbool SDFhasGrammarRestrictions(SDFGrammar arg)
{
  if (SDFisGrammarLexicalRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarContextFreeRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarRestrictions(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFRestrictions SDFgetGrammarRestrictions(SDFGrammar arg) */

SDFRestrictions SDFgetGrammarRestrictions(SDFGrammar arg)
{
  if (SDFisGrammarLexicalRestrictions(arg)) {
    return (SDFRestrictions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDFisGrammarContextFreeRestrictions(arg)) {
    return (SDFRestrictions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDFisGrammarRestrictions(arg)) {
    return (SDFRestrictions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Grammar has no Restrictions: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGrammar SDFsetGrammarRestrictions(SDFGrammar arg, SDFRestrictions restrictions) */

SDFGrammar SDFsetGrammarRestrictions(SDFGrammar arg, SDFRestrictions restrictions)
{
  if (SDFisGrammarLexicalRestrictions(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)restrictions, 4), 2);
  }
  else if (SDFisGrammarContextFreeRestrictions(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)restrictions, 4), 2);
  }
  else if (SDFisGrammarRestrictions(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)restrictions, 2), 2);
  }

  ATabort("Grammar has no Restrictions: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGrammarWsAfterRestrictions(SDFGrammar arg) */

ATbool SDFhasGrammarWsAfterRestrictions(SDFGrammar arg)
{
  if (SDFisGrammarLexicalRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarContextFreeRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarRestrictions(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetGrammarWsAfterRestrictions(SDFGrammar arg) */

SDFLayout SDFgetGrammarWsAfterRestrictions(SDFGrammar arg)
{
  if (SDFisGrammarLexicalRestrictions(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDFisGrammarContextFreeRestrictions(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDFisGrammarRestrictions(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Grammar has no WsAfterRestrictions: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGrammar SDFsetGrammarWsAfterRestrictions(SDFGrammar arg, SDFLayout wsAfterRestrictions) */

SDFGrammar SDFsetGrammarWsAfterRestrictions(SDFGrammar arg, SDFLayout wsAfterRestrictions)
{
  if (SDFisGrammarLexicalRestrictions(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterRestrictions, 0), 3), 2);
  }
  else if (SDFisGrammarContextFreeRestrictions(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterRestrictions, 0), 3), 2);
  }
  else if (SDFisGrammarRestrictions(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterRestrictions, 0), 1), 2);
  }

  ATabort("Grammar has no WsAfterRestrictions: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGrammarImpSection(SDFGrammar arg) */

ATbool SDFhasGrammarImpSection(SDFGrammar arg)
{
  if (SDFisGrammarImpSection(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFImpSection SDFgetGrammarImpSection(SDFGrammar arg) */

SDFImpSection SDFgetGrammarImpSection(SDFGrammar arg)
{
  if (SDFisGrammarImpSection(arg)) {
    return (SDFImpSection)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Grammar has no ImpSection: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGrammar SDFsetGrammarImpSection(SDFGrammar arg, SDFImpSection impSection) */

SDFGrammar SDFsetGrammarImpSection(SDFGrammar arg, SDFImpSection impSection)
{
  if (SDFisGrammarImpSection(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)impSection, 0), 2);
  }

  ATabort("Grammar has no ImpSection: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGrammarWsAfterLexical(SDFGrammar arg) */

ATbool SDFhasGrammarWsAfterLexical(SDFGrammar arg)
{
  if (SDFisGrammarLexicalPriorities(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarLexicalRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarLexicalSyntax(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarLexicalVariables(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetGrammarWsAfterLexical(SDFGrammar arg) */

SDFLayout SDFgetGrammarWsAfterLexical(SDFGrammar arg)
{
  if (SDFisGrammarLexicalPriorities(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisGrammarLexicalRestrictions(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisGrammarLexicalSyntax(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisGrammarLexicalVariables(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Grammar has no WsAfterLexical: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGrammar SDFsetGrammarWsAfterLexical(SDFGrammar arg, SDFLayout wsAfterLexical) */

SDFGrammar SDFsetGrammarWsAfterLexical(SDFGrammar arg, SDFLayout wsAfterLexical)
{
  if (SDFisGrammarLexicalPriorities(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLexical, 0), 1), 2);
  }
  else if (SDFisGrammarLexicalRestrictions(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLexical, 0), 1), 2);
  }
  else if (SDFisGrammarLexicalSyntax(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLexical, 0), 1), 2);
  }
  else if (SDFisGrammarLexicalVariables(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLexical, 0), 1), 2);
  }

  ATabort("Grammar has no WsAfterLexical: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGrammarGrammar(SDFGrammar arg) */

ATbool SDFhasGrammarGrammar(SDFGrammar arg)
{
  if (SDFisGrammarBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFGrammar SDFgetGrammarGrammar(SDFGrammar arg) */

SDFGrammar SDFgetGrammarGrammar(SDFGrammar arg)
{
  if (SDFisGrammarBracket(arg)) {
    return (SDFGrammar)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Grammar has no Grammar: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGrammar SDFsetGrammarGrammar(SDFGrammar arg, SDFGrammar grammar) */

SDFGrammar SDFsetGrammarGrammar(SDFGrammar arg, SDFGrammar grammar)
{
  if (SDFisGrammarBracket(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)grammar, 2), 2);
  }

  ATabort("Grammar has no Grammar: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGrammarSymbols(SDFGrammar arg) */

ATbool SDFhasGrammarSymbols(SDFGrammar arg)
{
  if (SDFisGrammarSorts(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbols SDFgetGrammarSymbols(SDFGrammar arg) */

SDFSymbols SDFgetGrammarSymbols(SDFGrammar arg)
{
  if (SDFisGrammarSorts(arg)) {
    return (SDFSymbols)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Grammar has no Symbols: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGrammar SDFsetGrammarSymbols(SDFGrammar arg, SDFSymbols symbols) */

SDFGrammar SDFsetGrammarSymbols(SDFGrammar arg, SDFSymbols symbols)
{
  if (SDFisGrammarSorts(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbols, 2), 2);
  }

  ATabort("Grammar has no Symbols: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGrammarWsAfterVariables(SDFGrammar arg) */

ATbool SDFhasGrammarWsAfterVariables(SDFGrammar arg)
{
  if (SDFisGrammarVariables(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarLexicalVariables(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetGrammarWsAfterVariables(SDFGrammar arg) */

SDFLayout SDFgetGrammarWsAfterVariables(SDFGrammar arg)
{
  if (SDFisGrammarVariables(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisGrammarLexicalVariables(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Grammar has no WsAfterVariables: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGrammar SDFsetGrammarWsAfterVariables(SDFGrammar arg, SDFLayout wsAfterVariables) */

SDFGrammar SDFsetGrammarWsAfterVariables(SDFGrammar arg, SDFLayout wsAfterVariables)
{
  if (SDFisGrammarVariables(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterVariables, 0), 1), 2);
  }
  else if (SDFisGrammarLexicalVariables(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterVariables, 0), 3), 2);
  }

  ATabort("Grammar has no WsAfterVariables: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGrammarLeft(SDFGrammar arg) */

ATbool SDFhasGrammarLeft(SDFGrammar arg)
{
  if (SDFisGrammarConcGrammars(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFGrammar SDFgetGrammarLeft(SDFGrammar arg) */

SDFGrammar SDFgetGrammarLeft(SDFGrammar arg)
{
  if (SDFisGrammarConcGrammars(arg)) {
    return (SDFGrammar)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Grammar has no Left: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGrammar SDFsetGrammarLeft(SDFGrammar arg, SDFGrammar left) */

SDFGrammar SDFsetGrammarLeft(SDFGrammar arg, SDFGrammar left)
{
  if (SDFisGrammarConcGrammars(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)left, 0), 2);
  }

  ATabort("Grammar has no Left: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGrammarWsAfterAliases(SDFGrammar arg) */

ATbool SDFhasGrammarWsAfterAliases(SDFGrammar arg)
{
  if (SDFisGrammarAliases(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetGrammarWsAfterAliases(SDFGrammar arg) */

SDFLayout SDFgetGrammarWsAfterAliases(SDFGrammar arg)
{
  if (SDFisGrammarAliases(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Grammar has no WsAfterAliases: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGrammar SDFsetGrammarWsAfterAliases(SDFGrammar arg, SDFLayout wsAfterAliases) */

SDFGrammar SDFsetGrammarWsAfterAliases(SDFGrammar arg, SDFLayout wsAfterAliases)
{
  if (SDFisGrammarAliases(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterAliases, 0), 1), 2);
  }

  ATabort("Grammar has no WsAfterAliases: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGrammarProductions(SDFGrammar arg) */

ATbool SDFhasGrammarProductions(SDFGrammar arg)
{
  if (SDFisGrammarSyntax(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarLexicalSyntax(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarContextFreeSyntax(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarVariables(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarLexicalVariables(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFProductions SDFgetGrammarProductions(SDFGrammar arg) */

SDFProductions SDFgetGrammarProductions(SDFGrammar arg)
{
  if (SDFisGrammarSyntax(arg)) {
    return (SDFProductions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDFisGrammarLexicalSyntax(arg)) {
    return (SDFProductions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDFisGrammarContextFreeSyntax(arg)) {
    return (SDFProductions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDFisGrammarVariables(arg)) {
    return (SDFProductions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDFisGrammarLexicalVariables(arg)) {
    return (SDFProductions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Grammar has no Productions: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGrammar SDFsetGrammarProductions(SDFGrammar arg, SDFProductions productions) */

SDFGrammar SDFsetGrammarProductions(SDFGrammar arg, SDFProductions productions)
{
  if (SDFisGrammarSyntax(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)productions, 2), 2);
  }
  else if (SDFisGrammarLexicalSyntax(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)productions, 4), 2);
  }
  else if (SDFisGrammarContextFreeSyntax(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)productions, 4), 2);
  }
  else if (SDFisGrammarVariables(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)productions, 2), 2);
  }
  else if (SDFisGrammarLexicalVariables(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)productions, 4), 2);
  }

  ATabort("Grammar has no Productions: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGrammarWsAfterContextFree(SDFGrammar arg) */

ATbool SDFhasGrammarWsAfterContextFree(SDFGrammar arg)
{
  if (SDFisGrammarContextFreePriorities(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarContextFreeRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDFisGrammarContextFreeSyntax(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetGrammarWsAfterContextFree(SDFGrammar arg) */

SDFLayout SDFgetGrammarWsAfterContextFree(SDFGrammar arg)
{
  if (SDFisGrammarContextFreePriorities(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisGrammarContextFreeRestrictions(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisGrammarContextFreeSyntax(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Grammar has no WsAfterContextFree: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGrammar SDFsetGrammarWsAfterContextFree(SDFGrammar arg, SDFLayout wsAfterContextFree) */

SDFGrammar SDFsetGrammarWsAfterContextFree(SDFGrammar arg, SDFLayout wsAfterContextFree)
{
  if (SDFisGrammarContextFreePriorities(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterContextFree, 0), 1), 2);
  }
  else if (SDFisGrammarContextFreeRestrictions(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterContextFree, 0), 1), 2);
  }
  else if (SDFisGrammarContextFreeSyntax(arg)) {
    return (SDFGrammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterContextFree, 0), 1), 2);
  }

  ATabort("Grammar has no WsAfterContextFree: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFSDF accessor implementations */

/*{{{  ATbool SDFisValidSDF(SDFSDF arg) */

ATbool SDFisValidSDF(SDFSDF arg)
{
  if (SDFisSDFDefinition(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisSDFDefinition(SDFSDF arg) */

ATbool SDFisSDFDefinition(SDFSDF arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSDFDefinition, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasSDFDefinition(SDFSDF arg) */

ATbool SDFhasSDFDefinition(SDFSDF arg)
{
  if (SDFisSDFDefinition(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFDefinition SDFgetSDFDefinition(SDFSDF arg) */

SDFDefinition SDFgetSDFDefinition(SDFSDF arg)
{
  if (SDFisSDFDefinition(arg)) {
    return (SDFDefinition)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("SDF has no Definition: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSDF SDFsetSDFDefinition(SDFSDF arg, SDFDefinition definition) */

SDFSDF SDFsetSDFDefinition(SDFSDF arg, SDFDefinition definition)
{
  if (SDFisSDFDefinition(arg)) {
    return (SDFSDF)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)definition, 2), 2);
  }

  ATabort("SDF has no Definition: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSDFWsAfterDefinition(SDFSDF arg) */

ATbool SDFhasSDFWsAfterDefinition(SDFSDF arg)
{
  if (SDFisSDFDefinition(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSDFWsAfterDefinition(SDFSDF arg) */

SDFLayout SDFgetSDFWsAfterDefinition(SDFSDF arg)
{
  if (SDFisSDFDefinition(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("SDF has no WsAfterDefinition: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSDF SDFsetSDFWsAfterDefinition(SDFSDF arg, SDFLayout wsAfterDefinition) */

SDFSDF SDFsetSDFWsAfterDefinition(SDFSDF arg, SDFLayout wsAfterDefinition)
{
  if (SDFisSDFDefinition(arg)) {
    return (SDFSDF)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterDefinition, 0), 1), 2);
  }

  ATabort("SDF has no WsAfterDefinition: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFAttributes accessor implementations */

/*{{{  ATbool SDFisValidAttributes(SDFAttributes arg) */

ATbool SDFisValidAttributes(SDFAttributes arg)
{
  if (SDFisAttributesAttrs(arg)) {
    return ATtrue;
  }
  else if (SDFisAttributesNoAttrs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisAttributesAttrs(SDFAttributes arg) */

ATbool SDFisAttributesAttrs(SDFAttributes arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAttributesAttrs, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisAttributesNoAttrs(SDFAttributes arg) */

ATbool SDFisAttributesNoAttrs(SDFAttributes arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAttributesNoAttrs);
}

/*}}}  */
/*{{{  ATbool SDFhasAttributesWsAfterBraceOpen(SDFAttributes arg) */

ATbool SDFhasAttributesWsAfterBraceOpen(SDFAttributes arg)
{
  if (SDFisAttributesAttrs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetAttributesWsAfterBraceOpen(SDFAttributes arg) */

SDFLayout SDFgetAttributesWsAfterBraceOpen(SDFAttributes arg)
{
  if (SDFisAttributesAttrs(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Attributes has no WsAfterBraceOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAttributes SDFsetAttributesWsAfterBraceOpen(SDFAttributes arg, SDFLayout wsAfterBraceOpen) */

SDFAttributes SDFsetAttributesWsAfterBraceOpen(SDFAttributes arg, SDFLayout wsAfterBraceOpen)
{
  if (SDFisAttributesAttrs(arg)) {
    return (SDFAttributes)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterBraceOpen, 0), 1), 2);
  }

  ATabort("Attributes has no WsAfterBraceOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasAttributesAttributes(SDFAttributes arg) */

ATbool SDFhasAttributesAttributes(SDFAttributes arg)
{
  if (SDFisAttributesAttrs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFAttributeAttributes SDFgetAttributesAttributes(SDFAttributes arg) */

SDFAttributeAttributes SDFgetAttributesAttributes(SDFAttributes arg)
{
  if (SDFisAttributesAttrs(arg)) {
    return (SDFAttributeAttributes)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2), 2);
  }

  ATabort("Attributes has no Attributes: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAttributes SDFsetAttributesAttributes(SDFAttributes arg, SDFAttributeAttributes attributes) */

SDFAttributes SDFsetAttributesAttributes(SDFAttributes arg, SDFAttributeAttributes attributes)
{
  if (SDFisAttributesAttrs(arg)) {
    return (SDFAttributes)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2), (ATerm)attributes, 2), 2), 2);
  }

  ATabort("Attributes has no Attributes: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasAttributesWsAfterAttributes(SDFAttributes arg) */

ATbool SDFhasAttributesWsAfterAttributes(SDFAttributes arg)
{
  if (SDFisAttributesAttrs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetAttributesWsAfterAttributes(SDFAttributes arg) */

SDFLayout SDFgetAttributesWsAfterAttributes(SDFAttributes arg)
{
  if (SDFisAttributesAttrs(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Attributes has no WsAfterAttributes: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAttributes SDFsetAttributesWsAfterAttributes(SDFAttributes arg, SDFLayout wsAfterAttributes) */

SDFAttributes SDFsetAttributesWsAfterAttributes(SDFAttributes arg, SDFLayout wsAfterAttributes)
{
  if (SDFisAttributesAttrs(arg)) {
    return (SDFAttributes)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterAttributes, 0), 3), 2);
  }

  ATabort("Attributes has no WsAfterAttributes: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFAttributeAttributes accessor implementations */

/*{{{  ATbool SDFisValidAttributeAttributes(SDFAttributeAttributes arg) */

ATbool SDFisValidAttributeAttributes(SDFAttributeAttributes arg)
{
  if (SDFisAttributeAttributesEmpty(arg)) {
    return ATtrue;
  }
  else if (SDFisAttributeAttributesSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisAttributeAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisAttributeAttributesEmpty(SDFAttributeAttributes arg) */

ATbool SDFisAttributeAttributesEmpty(SDFAttributeAttributes arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAttributeAttributesEmpty);
}

/*}}}  */
/*{{{  ATbool SDFisAttributeAttributesSingle(SDFAttributeAttributes arg) */

ATbool SDFisAttributeAttributesSingle(SDFAttributeAttributes arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAttributeAttributesSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisAttributeAttributesMany(SDFAttributeAttributes arg) */

ATbool SDFisAttributeAttributesMany(SDFAttributeAttributes arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAttributeAttributesMany, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasAttributeAttributesWsAfterFirst(SDFAttributeAttributes arg) */

ATbool SDFhasAttributeAttributesWsAfterFirst(SDFAttributeAttributes arg)
{
  if (SDFisAttributeAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetAttributeAttributesWsAfterFirst(SDFAttributeAttributes arg) */

SDFLayout SDFgetAttributeAttributesWsAfterFirst(SDFAttributeAttributes arg)
{
  if (SDFisAttributeAttributesMany(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("AttributeAttributes has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAttributeAttributes SDFsetAttributeAttributesWsAfterFirst(SDFAttributeAttributes arg, SDFLayout wsAfterFirst) */

SDFAttributeAttributes SDFsetAttributeAttributesWsAfterFirst(SDFAttributeAttributes arg, SDFLayout wsAfterFirst)
{
  if (SDFisAttributeAttributesMany(arg)) {
    return (SDFAttributeAttributes)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("AttributeAttributes has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasAttributeAttributesWsAfterSep(SDFAttributeAttributes arg) */

ATbool SDFhasAttributeAttributesWsAfterSep(SDFAttributeAttributes arg)
{
  if (SDFisAttributeAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetAttributeAttributesWsAfterSep(SDFAttributeAttributes arg) */

SDFLayout SDFgetAttributeAttributesWsAfterSep(SDFAttributeAttributes arg)
{
  if (SDFisAttributeAttributesMany(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), 0);
  }

  ATabort("AttributeAttributes has no WsAfterSep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAttributeAttributes SDFsetAttributeAttributesWsAfterSep(SDFAttributeAttributes arg, SDFLayout wsAfterSep) */

SDFAttributeAttributes SDFsetAttributeAttributesWsAfterSep(SDFAttributeAttributes arg, SDFLayout wsAfterSep)
{
  if (SDFisAttributeAttributesMany(arg)) {
    return (SDFAttributeAttributes)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), (ATerm)wsAfterSep, 0), 3);
  }

  ATabort("AttributeAttributes has no WsAfterSep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasAttributeAttributesTail(SDFAttributeAttributes arg) */

ATbool SDFhasAttributeAttributesTail(SDFAttributeAttributes arg)
{
  if (SDFisAttributeAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFAttributeAttributes SDFgetAttributeAttributesTail(SDFAttributeAttributes arg) */

SDFAttributeAttributes SDFgetAttributeAttributesTail(SDFAttributeAttributes arg)
{
  if (SDFisAttributeAttributesMany(arg)) {
    return (SDFAttributeAttributes)ATgetTail((ATermList)arg, 4);
  }

  ATabort("AttributeAttributes has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAttributeAttributes SDFsetAttributeAttributesTail(SDFAttributeAttributes arg, SDFAttributeAttributes tail) */

SDFAttributeAttributes SDFsetAttributeAttributesTail(SDFAttributeAttributes arg, SDFAttributeAttributes tail)
{
  if (SDFisAttributeAttributesMany(arg)) {
    return (SDFAttributeAttributes)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("AttributeAttributes has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasAttributeAttributesHead(SDFAttributeAttributes arg) */

ATbool SDFhasAttributeAttributesHead(SDFAttributeAttributes arg)
{
  if (SDFisAttributeAttributesSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisAttributeAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFAttribute SDFgetAttributeAttributesHead(SDFAttributeAttributes arg) */

SDFAttribute SDFgetAttributeAttributesHead(SDFAttributeAttributes arg)
{
  if (SDFisAttributeAttributesSingle(arg)) {
    return (SDFAttribute)ATelementAt((ATermList)arg, 0);
  }
  else if (SDFisAttributeAttributesMany(arg)) {
    return (SDFAttribute)ATelementAt((ATermList)arg, 0);
  }

  ATabort("AttributeAttributes has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAttributeAttributes SDFsetAttributeAttributesHead(SDFAttributeAttributes arg, SDFAttribute head) */

SDFAttributeAttributes SDFsetAttributeAttributesHead(SDFAttributeAttributes arg, SDFAttribute head)
{
  if (SDFisAttributeAttributesSingle(arg)) {
    return (SDFAttributeAttributes)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDFisAttributeAttributesMany(arg)) {
    return (SDFAttributeAttributes)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("AttributeAttributes has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasAttributeAttributesSep(SDFAttributeAttributes arg) */

ATbool SDFhasAttributeAttributesSep(SDFAttributeAttributes arg)
{
  if (SDFisAttributeAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSeparator SDFgetAttributeAttributesSep(SDFAttributeAttributes arg) */

SDFSeparator SDFgetAttributeAttributesSep(SDFAttributeAttributes arg)
{
  if (SDFisAttributeAttributesMany(arg)) {
    return (SDFSeparator)ATelementAt((ATermList)arg, 2);
  }

  ATabort("AttributeAttributes has no Sep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAttributeAttributes SDFsetAttributeAttributesSep(SDFAttributeAttributes arg, SDFSeparator sep) */

SDFAttributeAttributes SDFsetAttributeAttributesSep(SDFAttributeAttributes arg, SDFSeparator sep)
{
  if (SDFisAttributeAttributesMany(arg)) {
    return (SDFAttributeAttributes)ATreplace((ATermList)arg, (ATerm)sep, 2);
  }

  ATabort("AttributeAttributes has no Sep: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFProduction accessor implementations */

/*{{{  ATbool SDFisValidProduction(SDFProduction arg) */

ATbool SDFisValidProduction(SDFProduction arg)
{
  if (SDFisProductionProd(arg)) {
    return ATtrue;
  }
  else if (SDFisProductionProdFun(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisProductionProd(SDFProduction arg) */

ATbool SDFisProductionProd(SDFProduction arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternProductionProd, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisProductionProdFun(SDFProduction arg) */

ATbool SDFisProductionProdFun(SDFProduction arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternProductionProdFun, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasProductionWsAfterResult(SDFProduction arg) */

ATbool SDFhasProductionWsAfterResult(SDFProduction arg)
{
  if (SDFisProductionProd(arg)) {
    return ATtrue;
  }
  else if (SDFisProductionProdFun(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetProductionWsAfterResult(SDFProduction arg) */

SDFLayout SDFgetProductionWsAfterResult(SDFProduction arg)
{
  if (SDFisProductionProd(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }
  else if (SDFisProductionProdFun(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 11), 0);
  }

  ATabort("Production has no WsAfterResult: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFProduction SDFsetProductionWsAfterResult(SDFProduction arg, SDFLayout wsAfterResult) */

SDFProduction SDFsetProductionWsAfterResult(SDFProduction arg, SDFLayout wsAfterResult)
{
  if (SDFisProductionProd(arg)) {
    return (SDFProduction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterResult, 0), 5), 2);
  }
  else if (SDFisProductionProdFun(arg)) {
    return (SDFProduction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 11), (ATerm)wsAfterResult, 0), 11), 2);
  }

  ATabort("Production has no WsAfterResult: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasProductionWsAfterParenClose(SDFProduction arg) */

ATbool SDFhasProductionWsAfterParenClose(SDFProduction arg)
{
  if (SDFisProductionProdFun(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetProductionWsAfterParenClose(SDFProduction arg) */

SDFLayout SDFgetProductionWsAfterParenClose(SDFProduction arg)
{
  if (SDFisProductionProdFun(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), 0);
  }

  ATabort("Production has no WsAfterParenClose: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFProduction SDFsetProductionWsAfterParenClose(SDFProduction arg, SDFLayout wsAfterParenClose) */

SDFProduction SDFsetProductionWsAfterParenClose(SDFProduction arg, SDFLayout wsAfterParenClose)
{
  if (SDFisProductionProdFun(arg)) {
    return (SDFProduction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), (ATerm)wsAfterParenClose, 0), 7), 2);
  }

  ATabort("Production has no WsAfterParenClose: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasProductionWsAfterParenOpen(SDFProduction arg) */

ATbool SDFhasProductionWsAfterParenOpen(SDFProduction arg)
{
  if (SDFisProductionProdFun(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetProductionWsAfterParenOpen(SDFProduction arg) */

SDFLayout SDFgetProductionWsAfterParenOpen(SDFProduction arg)
{
  if (SDFisProductionProdFun(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Production has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFProduction SDFsetProductionWsAfterParenOpen(SDFProduction arg, SDFLayout wsAfterParenOpen) */

SDFProduction SDFsetProductionWsAfterParenOpen(SDFProduction arg, SDFLayout wsAfterParenOpen)
{
  if (SDFisProductionProdFun(arg)) {
    return (SDFProduction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterParenOpen, 0), 3), 2);
  }

  ATabort("Production has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasProductionWsAfterArguments(SDFProduction arg) */

ATbool SDFhasProductionWsAfterArguments(SDFProduction arg)
{
  if (SDFisProductionProdFun(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetProductionWsAfterArguments(SDFProduction arg) */

SDFLayout SDFgetProductionWsAfterArguments(SDFProduction arg)
{
  if (SDFisProductionProdFun(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("Production has no WsAfterArguments: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFProduction SDFsetProductionWsAfterArguments(SDFProduction arg, SDFLayout wsAfterArguments) */

SDFProduction SDFsetProductionWsAfterArguments(SDFProduction arg, SDFLayout wsAfterArguments)
{
  if (SDFisProductionProdFun(arg)) {
    return (SDFProduction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterArguments, 0), 5), 2);
  }

  ATabort("Production has no WsAfterArguments: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasProductionResult(SDFProduction arg) */

ATbool SDFhasProductionResult(SDFProduction arg)
{
  if (SDFisProductionProd(arg)) {
    return ATtrue;
  }
  else if (SDFisProductionProdFun(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbol SDFgetProductionResult(SDFProduction arg) */

SDFSymbol SDFgetProductionResult(SDFProduction arg)
{
  if (SDFisProductionProd(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDFisProductionProdFun(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 10);
  }

  ATabort("Production has no Result: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFProduction SDFsetProductionResult(SDFProduction arg, SDFSymbol result) */

SDFProduction SDFsetProductionResult(SDFProduction arg, SDFSymbol result)
{
  if (SDFisProductionProd(arg)) {
    return (SDFProduction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)result, 4), 2);
  }
  else if (SDFisProductionProdFun(arg)) {
    return (SDFProduction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)result, 10), 2);
  }

  ATabort("Production has no Result: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasProductionArguments(SDFProduction arg) */

ATbool SDFhasProductionArguments(SDFProduction arg)
{
  if (SDFisProductionProdFun(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbolArguments SDFgetProductionArguments(SDFProduction arg) */

SDFSymbolArguments SDFgetProductionArguments(SDFProduction arg)
{
  if (SDFisProductionProdFun(arg)) {
    return (SDFSymbolArguments)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4), 2);
  }

  ATabort("Production has no Arguments: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFProduction SDFsetProductionArguments(SDFProduction arg, SDFSymbolArguments arguments) */

SDFProduction SDFsetProductionArguments(SDFProduction arg, SDFSymbolArguments arguments)
{
  if (SDFisProductionProdFun(arg)) {
    return (SDFProduction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4), (ATerm)arguments, 2), 4), 2);
  }

  ATabort("Production has no Arguments: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasProductionWsAfterSymbols(SDFProduction arg) */

ATbool SDFhasProductionWsAfterSymbols(SDFProduction arg)
{
  if (SDFisProductionProd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetProductionWsAfterSymbols(SDFProduction arg) */

SDFLayout SDFgetProductionWsAfterSymbols(SDFProduction arg)
{
  if (SDFisProductionProd(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Production has no WsAfterSymbols: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFProduction SDFsetProductionWsAfterSymbols(SDFProduction arg, SDFLayout wsAfterSymbols) */

SDFProduction SDFsetProductionWsAfterSymbols(SDFProduction arg, SDFLayout wsAfterSymbols)
{
  if (SDFisProductionProd(arg)) {
    return (SDFProduction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterSymbols, 0), 1), 2);
  }

  ATabort("Production has no WsAfterSymbols: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasProductionFunctionSymbol(SDFProduction arg) */

ATbool SDFhasProductionFunctionSymbol(SDFProduction arg)
{
  if (SDFisProductionProdFun(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLiteral SDFgetProductionFunctionSymbol(SDFProduction arg) */

SDFLiteral SDFgetProductionFunctionSymbol(SDFProduction arg)
{
  if (SDFisProductionProdFun(arg)) {
    return (SDFLiteral)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Production has no FunctionSymbol: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFProduction SDFsetProductionFunctionSymbol(SDFProduction arg, SDFLiteral functionSymbol) */

SDFProduction SDFsetProductionFunctionSymbol(SDFProduction arg, SDFLiteral functionSymbol)
{
  if (SDFisProductionProdFun(arg)) {
    return (SDFProduction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)functionSymbol, 0), 2);
  }

  ATabort("Production has no FunctionSymbol: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasProductionAttributes(SDFProduction arg) */

ATbool SDFhasProductionAttributes(SDFProduction arg)
{
  if (SDFisProductionProd(arg)) {
    return ATtrue;
  }
  else if (SDFisProductionProdFun(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFAttributes SDFgetProductionAttributes(SDFProduction arg) */

SDFAttributes SDFgetProductionAttributes(SDFProduction arg)
{
  if (SDFisProductionProd(arg)) {
    return (SDFAttributes)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 6);
  }
  else if (SDFisProductionProdFun(arg)) {
    return (SDFAttributes)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 12);
  }

  ATabort("Production has no Attributes: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFProduction SDFsetProductionAttributes(SDFProduction arg, SDFAttributes attributes) */

SDFProduction SDFsetProductionAttributes(SDFProduction arg, SDFAttributes attributes)
{
  if (SDFisProductionProd(arg)) {
    return (SDFProduction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)attributes, 6), 2);
  }
  else if (SDFisProductionProdFun(arg)) {
    return (SDFProduction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)attributes, 12), 2);
  }

  ATabort("Production has no Attributes: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasProductionWsAfterGreaterThan(SDFProduction arg) */

ATbool SDFhasProductionWsAfterGreaterThan(SDFProduction arg)
{
  if (SDFisProductionProd(arg)) {
    return ATtrue;
  }
  else if (SDFisProductionProdFun(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetProductionWsAfterGreaterThan(SDFProduction arg) */

SDFLayout SDFgetProductionWsAfterGreaterThan(SDFProduction arg)
{
  if (SDFisProductionProd(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDFisProductionProdFun(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 9), 0);
  }

  ATabort("Production has no WsAfterGreaterThan: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFProduction SDFsetProductionWsAfterGreaterThan(SDFProduction arg, SDFLayout wsAfterGreaterThan) */

SDFProduction SDFsetProductionWsAfterGreaterThan(SDFProduction arg, SDFLayout wsAfterGreaterThan)
{
  if (SDFisProductionProd(arg)) {
    return (SDFProduction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterGreaterThan, 0), 3), 2);
  }
  else if (SDFisProductionProdFun(arg)) {
    return (SDFProduction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 9), (ATerm)wsAfterGreaterThan, 0), 9), 2);
  }

  ATabort("Production has no WsAfterGreaterThan: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasProductionSymbols(SDFProduction arg) */

ATbool SDFhasProductionSymbols(SDFProduction arg)
{
  if (SDFisProductionProd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbols SDFgetProductionSymbols(SDFProduction arg) */

SDFSymbols SDFgetProductionSymbols(SDFProduction arg)
{
  if (SDFisProductionProd(arg)) {
    return (SDFSymbols)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Production has no Symbols: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFProduction SDFsetProductionSymbols(SDFProduction arg, SDFSymbols symbols) */

SDFProduction SDFsetProductionSymbols(SDFProduction arg, SDFSymbols symbols)
{
  if (SDFisProductionProd(arg)) {
    return (SDFProduction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbols, 0), 2);
  }

  ATabort("Production has no Symbols: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasProductionWsAfterFunctionSymbol(SDFProduction arg) */

ATbool SDFhasProductionWsAfterFunctionSymbol(SDFProduction arg)
{
  if (SDFisProductionProdFun(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetProductionWsAfterFunctionSymbol(SDFProduction arg) */

SDFLayout SDFgetProductionWsAfterFunctionSymbol(SDFProduction arg)
{
  if (SDFisProductionProdFun(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Production has no WsAfterFunctionSymbol: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFProduction SDFsetProductionWsAfterFunctionSymbol(SDFProduction arg, SDFLayout wsAfterFunctionSymbol) */

SDFProduction SDFsetProductionWsAfterFunctionSymbol(SDFProduction arg, SDFLayout wsAfterFunctionSymbol)
{
  if (SDFisProductionProdFun(arg)) {
    return (SDFProduction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterFunctionSymbol, 0), 1), 2);
  }

  ATabort("Production has no WsAfterFunctionSymbol: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFProductions accessor implementations */

/*{{{  ATbool SDFisValidProductions(SDFProductions arg) */

ATbool SDFisValidProductions(SDFProductions arg)
{
  if (SDFisProductionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisProductionsDefault(SDFProductions arg) */

ATbool SDFisProductionsDefault(SDFProductions arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternProductionsDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasProductionsProductions(SDFProductions arg) */

ATbool SDFhasProductionsProductions(SDFProductions arg)
{
  if (SDFisProductionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFProductionProductions SDFgetProductionsProductions(SDFProductions arg) */

SDFProductionProductions SDFgetProductionsProductions(SDFProductions arg)
{
  if (SDFisProductionsDefault(arg)) {
    return (SDFProductionProductions)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 2);
  }

  ATabort("Productions has no Productions: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFProductions SDFsetProductionsProductions(SDFProductions arg, SDFProductionProductions productions) */

SDFProductions SDFsetProductionsProductions(SDFProductions arg, SDFProductionProductions productions)
{
  if (SDFisProductionsDefault(arg)) {
    return (SDFProductions)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)productions, 2), 0), 2);
  }

  ATabort("Productions has no Productions: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFProductionProductions accessor implementations */

/*{{{  ATbool SDFisValidProductionProductions(SDFProductionProductions arg) */

ATbool SDFisValidProductionProductions(SDFProductionProductions arg)
{
  if (SDFisProductionProductionsEmpty(arg)) {
    return ATtrue;
  }
  else if (SDFisProductionProductionsSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisProductionProductionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisProductionProductionsEmpty(SDFProductionProductions arg) */

ATbool SDFisProductionProductionsEmpty(SDFProductionProductions arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternProductionProductionsEmpty);
}

/*}}}  */
/*{{{  ATbool SDFisProductionProductionsSingle(SDFProductionProductions arg) */

ATbool SDFisProductionProductionsSingle(SDFProductionProductions arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternProductionProductionsSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisProductionProductionsMany(SDFProductionProductions arg) */

ATbool SDFisProductionProductionsMany(SDFProductionProductions arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternProductionProductionsMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasProductionProductionsWsAfterFirst(SDFProductionProductions arg) */

ATbool SDFhasProductionProductionsWsAfterFirst(SDFProductionProductions arg)
{
  if (SDFisProductionProductionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetProductionProductionsWsAfterFirst(SDFProductionProductions arg) */

SDFLayout SDFgetProductionProductionsWsAfterFirst(SDFProductionProductions arg)
{
  if (SDFisProductionProductionsMany(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("ProductionProductions has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFProductionProductions SDFsetProductionProductionsWsAfterFirst(SDFProductionProductions arg, SDFLayout wsAfterFirst) */

SDFProductionProductions SDFsetProductionProductionsWsAfterFirst(SDFProductionProductions arg, SDFLayout wsAfterFirst)
{
  if (SDFisProductionProductionsMany(arg)) {
    return (SDFProductionProductions)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("ProductionProductions has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasProductionProductionsTail(SDFProductionProductions arg) */

ATbool SDFhasProductionProductionsTail(SDFProductionProductions arg)
{
  if (SDFisProductionProductionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFProductionProductions SDFgetProductionProductionsTail(SDFProductionProductions arg) */

SDFProductionProductions SDFgetProductionProductionsTail(SDFProductionProductions arg)
{
  if (SDFisProductionProductionsMany(arg)) {
    return (SDFProductionProductions)ATgetTail((ATermList)arg, 2);
  }

  ATabort("ProductionProductions has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFProductionProductions SDFsetProductionProductionsTail(SDFProductionProductions arg, SDFProductionProductions tail) */

SDFProductionProductions SDFsetProductionProductionsTail(SDFProductionProductions arg, SDFProductionProductions tail)
{
  if (SDFisProductionProductionsMany(arg)) {
    return (SDFProductionProductions)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("ProductionProductions has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasProductionProductionsHead(SDFProductionProductions arg) */

ATbool SDFhasProductionProductionsHead(SDFProductionProductions arg)
{
  if (SDFisProductionProductionsSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisProductionProductionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFProduction SDFgetProductionProductionsHead(SDFProductionProductions arg) */

SDFProduction SDFgetProductionProductionsHead(SDFProductionProductions arg)
{
  if (SDFisProductionProductionsSingle(arg)) {
    return (SDFProduction)ATelementAt((ATermList)arg, 0);
  }
  else if (SDFisProductionProductionsMany(arg)) {
    return (SDFProduction)ATelementAt((ATermList)arg, 0);
  }

  ATabort("ProductionProductions has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFProductionProductions SDFsetProductionProductionsHead(SDFProductionProductions arg, SDFProduction head) */

SDFProductionProductions SDFsetProductionProductionsHead(SDFProductionProductions arg, SDFProduction head)
{
  if (SDFisProductionProductionsSingle(arg)) {
    return (SDFProductionProductions)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDFisProductionProductionsMany(arg)) {
    return (SDFProductionProductions)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("ProductionProductions has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFModuleWord accessor implementations */

/*{{{  ATbool SDFisValidModuleWord(SDFModuleWord arg) */

ATbool SDFisValidModuleWord(SDFModuleWord arg)
{
  if (SDFisModuleWordWord(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisModuleWordWord(SDFModuleWord arg) */

ATbool SDFisModuleWordWord(SDFModuleWord arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternModuleWordWord, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasModuleWordLex(SDFModuleWord arg) */

ATbool SDFhasModuleWordLex(SDFModuleWord arg)
{
  if (SDFisModuleWordWord(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLexical SDFgetModuleWordLex(SDFModuleWord arg) */

SDFLexical SDFgetModuleWordLex(SDFModuleWord arg)
{
  if (SDFisModuleWordWord(arg)) {
    return (SDFLexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("ModuleWord has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFModuleWord SDFsetModuleWordLex(SDFModuleWord arg, SDFLexical lex) */

SDFModuleWord SDFsetModuleWordLex(SDFModuleWord arg, SDFLexical lex)
{
  if (SDFisModuleWordWord(arg)) {
    return (SDFModuleWord)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("ModuleWord has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFModuleId accessor implementations */

/*{{{  ATbool SDFisValidModuleId(SDFModuleId arg) */

ATbool SDFisValidModuleId(SDFModuleId arg)
{
  if (SDFisModuleIdWord(arg)) {
    return ATtrue;
  }
  else if (SDFisModuleIdSlashWord(arg)) {
    return ATtrue;
  }
  else if (SDFisModuleIdWordSlashWord(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisModuleIdWord(SDFModuleId arg) */

ATbool SDFisModuleIdWord(SDFModuleId arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternModuleIdWord, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisModuleIdSlashWord(SDFModuleId arg) */

ATbool SDFisModuleIdSlashWord(SDFModuleId arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternModuleIdSlashWord, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisModuleIdWordSlashWord(SDFModuleId arg) */

ATbool SDFisModuleIdWordSlashWord(SDFModuleId arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternModuleIdWordSlashWord, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasModuleIdLex(SDFModuleId arg) */

ATbool SDFhasModuleIdLex(SDFModuleId arg)
{
  if (SDFisModuleIdWord(arg)) {
    return ATtrue;
  }
  else if (SDFisModuleIdSlashWord(arg)) {
    return ATtrue;
  }
  else if (SDFisModuleIdWordSlashWord(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLexical SDFgetModuleIdLex(SDFModuleId arg) */

SDFLexical SDFgetModuleIdLex(SDFModuleId arg)
{
  if (SDFisModuleIdWord(arg)) {
    return (SDFLexical)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (SDFisModuleIdSlashWord(arg)) {
    return (SDFLexical)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (SDFisModuleIdWordSlashWord(arg)) {
    return (SDFLexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("ModuleId has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFModuleId SDFsetModuleIdLex(SDFModuleId arg, SDFLexical lex) */

SDFModuleId SDFsetModuleIdLex(SDFModuleId arg, SDFLexical lex)
{
  if (SDFisModuleIdWord(arg)) {
    return (SDFModuleId)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }
  else if (SDFisModuleIdSlashWord(arg)) {
    return (SDFModuleId)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }
  else if (SDFisModuleIdWordSlashWord(arg)) {
    return (SDFModuleId)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("ModuleId has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFDefinition accessor implementations */

/*{{{  ATbool SDFisValidDefinition(SDFDefinition arg) */

ATbool SDFisValidDefinition(SDFDefinition arg)
{
  if (SDFisDefinitionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisDefinitionDefault(SDFDefinition arg) */

ATbool SDFisDefinitionDefault(SDFDefinition arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternDefinitionDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasDefinitionModules(SDFDefinition arg) */

ATbool SDFhasDefinitionModules(SDFDefinition arg)
{
  if (SDFisDefinitionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFModuleModules SDFgetDefinitionModules(SDFDefinition arg) */

SDFModuleModules SDFgetDefinitionModules(SDFDefinition arg)
{
  if (SDFisDefinitionDefault(arg)) {
    return (SDFModuleModules)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 2);
  }

  ATabort("Definition has no Modules: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFDefinition SDFsetDefinitionModules(SDFDefinition arg, SDFModuleModules modules) */

SDFDefinition SDFsetDefinitionModules(SDFDefinition arg, SDFModuleModules modules)
{
  if (SDFisDefinitionDefault(arg)) {
    return (SDFDefinition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)modules, 2), 0), 2);
  }

  ATabort("Definition has no Modules: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFModuleModules accessor implementations */

/*{{{  ATbool SDFisValidModuleModules(SDFModuleModules arg) */

ATbool SDFisValidModuleModules(SDFModuleModules arg)
{
  if (SDFisModuleModulesEmpty(arg)) {
    return ATtrue;
  }
  else if (SDFisModuleModulesSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisModuleModulesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisModuleModulesEmpty(SDFModuleModules arg) */

ATbool SDFisModuleModulesEmpty(SDFModuleModules arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternModuleModulesEmpty);
}

/*}}}  */
/*{{{  ATbool SDFisModuleModulesSingle(SDFModuleModules arg) */

ATbool SDFisModuleModulesSingle(SDFModuleModules arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternModuleModulesSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisModuleModulesMany(SDFModuleModules arg) */

ATbool SDFisModuleModulesMany(SDFModuleModules arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternModuleModulesMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasModuleModulesWsAfterFirst(SDFModuleModules arg) */

ATbool SDFhasModuleModulesWsAfterFirst(SDFModuleModules arg)
{
  if (SDFisModuleModulesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetModuleModulesWsAfterFirst(SDFModuleModules arg) */

SDFLayout SDFgetModuleModulesWsAfterFirst(SDFModuleModules arg)
{
  if (SDFisModuleModulesMany(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("ModuleModules has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFModuleModules SDFsetModuleModulesWsAfterFirst(SDFModuleModules arg, SDFLayout wsAfterFirst) */

SDFModuleModules SDFsetModuleModulesWsAfterFirst(SDFModuleModules arg, SDFLayout wsAfterFirst)
{
  if (SDFisModuleModulesMany(arg)) {
    return (SDFModuleModules)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("ModuleModules has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasModuleModulesTail(SDFModuleModules arg) */

ATbool SDFhasModuleModulesTail(SDFModuleModules arg)
{
  if (SDFisModuleModulesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFModuleModules SDFgetModuleModulesTail(SDFModuleModules arg) */

SDFModuleModules SDFgetModuleModulesTail(SDFModuleModules arg)
{
  if (SDFisModuleModulesMany(arg)) {
    return (SDFModuleModules)ATgetTail((ATermList)arg, 2);
  }

  ATabort("ModuleModules has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFModuleModules SDFsetModuleModulesTail(SDFModuleModules arg, SDFModuleModules tail) */

SDFModuleModules SDFsetModuleModulesTail(SDFModuleModules arg, SDFModuleModules tail)
{
  if (SDFisModuleModulesMany(arg)) {
    return (SDFModuleModules)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("ModuleModules has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasModuleModulesHead(SDFModuleModules arg) */

ATbool SDFhasModuleModulesHead(SDFModuleModules arg)
{
  if (SDFisModuleModulesSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisModuleModulesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFModule SDFgetModuleModulesHead(SDFModuleModules arg) */

SDFModule SDFgetModuleModulesHead(SDFModuleModules arg)
{
  if (SDFisModuleModulesSingle(arg)) {
    return (SDFModule)ATelementAt((ATermList)arg, 0);
  }
  else if (SDFisModuleModulesMany(arg)) {
    return (SDFModule)ATelementAt((ATermList)arg, 0);
  }

  ATabort("ModuleModules has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFModuleModules SDFsetModuleModulesHead(SDFModuleModules arg, SDFModule head) */

SDFModuleModules SDFsetModuleModulesHead(SDFModuleModules arg, SDFModule head)
{
  if (SDFisModuleModulesSingle(arg)) {
    return (SDFModuleModules)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDFisModuleModulesMany(arg)) {
    return (SDFModuleModules)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("ModuleModules has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFModule accessor implementations */

/*{{{  ATbool SDFisValidModule(SDFModule arg) */

ATbool SDFisValidModule(SDFModule arg)
{
  if (SDFisModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisModuleModule(SDFModule arg) */

ATbool SDFisModuleModule(SDFModule arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternModuleModule, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasModuleWsAfterList(SDFModule arg) */

ATbool SDFhasModuleWsAfterList(SDFModule arg)
{
  if (SDFisModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetModuleWsAfterList(SDFModule arg) */

SDFLayout SDFgetModuleWsAfterList(SDFModule arg)
{
  if (SDFisModuleModule(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("Module has no WsAfterList: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFModule SDFsetModuleWsAfterList(SDFModule arg, SDFLayout wsAfterList) */

SDFModule SDFsetModuleWsAfterList(SDFModule arg, SDFLayout wsAfterList)
{
  if (SDFisModuleModule(arg)) {
    return (SDFModule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterList, 0), 5), 2);
  }

  ATabort("Module has no WsAfterList: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasModuleModuleName(SDFModule arg) */

ATbool SDFhasModuleModuleName(SDFModule arg)
{
  if (SDFisModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFModuleName SDFgetModuleModuleName(SDFModule arg) */

SDFModuleName SDFgetModuleModuleName(SDFModule arg)
{
  if (SDFisModuleModule(arg)) {
    return (SDFModuleName)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Module has no ModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFModule SDFsetModuleModuleName(SDFModule arg, SDFModuleName moduleName) */

SDFModule SDFsetModuleModuleName(SDFModule arg, SDFModuleName moduleName)
{
  if (SDFisModuleModule(arg)) {
    return (SDFModule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)moduleName, 2), 2);
  }

  ATabort("Module has no ModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasModuleWsAfterModule(SDFModule arg) */

ATbool SDFhasModuleWsAfterModule(SDFModule arg)
{
  if (SDFisModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetModuleWsAfterModule(SDFModule arg) */

SDFLayout SDFgetModuleWsAfterModule(SDFModule arg)
{
  if (SDFisModuleModule(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Module has no WsAfterModule: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFModule SDFsetModuleWsAfterModule(SDFModule arg, SDFLayout wsAfterModule) */

SDFModule SDFsetModuleWsAfterModule(SDFModule arg, SDFLayout wsAfterModule)
{
  if (SDFisModuleModule(arg)) {
    return (SDFModule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterModule, 0), 1), 2);
  }

  ATabort("Module has no WsAfterModule: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasModuleList(SDFModule arg) */

ATbool SDFhasModuleList(SDFModule arg)
{
  if (SDFisModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFImpSectionList SDFgetModuleList(SDFModule arg) */

SDFImpSectionList SDFgetModuleList(SDFModule arg)
{
  if (SDFisModuleModule(arg)) {
    return (SDFImpSectionList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4), 2);
  }

  ATabort("Module has no List: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFModule SDFsetModuleList(SDFModule arg, SDFImpSectionList list) */

SDFModule SDFsetModuleList(SDFModule arg, SDFImpSectionList list)
{
  if (SDFisModuleModule(arg)) {
    return (SDFModule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4), (ATerm)list, 2), 4), 2);
  }

  ATabort("Module has no List: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasModuleWsAfterModuleName(SDFModule arg) */

ATbool SDFhasModuleWsAfterModuleName(SDFModule arg)
{
  if (SDFisModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetModuleWsAfterModuleName(SDFModule arg) */

SDFLayout SDFgetModuleWsAfterModuleName(SDFModule arg)
{
  if (SDFisModuleModule(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Module has no WsAfterModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFModule SDFsetModuleWsAfterModuleName(SDFModule arg, SDFLayout wsAfterModuleName) */

SDFModule SDFsetModuleWsAfterModuleName(SDFModule arg, SDFLayout wsAfterModuleName)
{
  if (SDFisModuleModule(arg)) {
    return (SDFModule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterModuleName, 0), 3), 2);
  }

  ATabort("Module has no WsAfterModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasModuleSections(SDFModule arg) */

ATbool SDFhasModuleSections(SDFModule arg)
{
  if (SDFisModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSections SDFgetModuleSections(SDFModule arg) */

SDFSections SDFgetModuleSections(SDFModule arg)
{
  if (SDFisModuleModule(arg)) {
    return (SDFSections)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 6);
  }

  ATabort("Module has no Sections: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFModule SDFsetModuleSections(SDFModule arg, SDFSections sections) */

SDFModule SDFsetModuleSections(SDFModule arg, SDFSections sections)
{
  if (SDFisModuleModule(arg)) {
    return (SDFModule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)sections, 6), 2);
  }

  ATabort("Module has no Sections: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFImpSectionList accessor implementations */

/*{{{  ATbool SDFisValidImpSectionList(SDFImpSectionList arg) */

ATbool SDFisValidImpSectionList(SDFImpSectionList arg)
{
  if (SDFisImpSectionListEmpty(arg)) {
    return ATtrue;
  }
  else if (SDFisImpSectionListSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisImpSectionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisImpSectionListEmpty(SDFImpSectionList arg) */

ATbool SDFisImpSectionListEmpty(SDFImpSectionList arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternImpSectionListEmpty);
}

/*}}}  */
/*{{{  ATbool SDFisImpSectionListSingle(SDFImpSectionList arg) */

ATbool SDFisImpSectionListSingle(SDFImpSectionList arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternImpSectionListSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisImpSectionListMany(SDFImpSectionList arg) */

ATbool SDFisImpSectionListMany(SDFImpSectionList arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternImpSectionListMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasImpSectionListWsAfterFirst(SDFImpSectionList arg) */

ATbool SDFhasImpSectionListWsAfterFirst(SDFImpSectionList arg)
{
  if (SDFisImpSectionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetImpSectionListWsAfterFirst(SDFImpSectionList arg) */

SDFLayout SDFgetImpSectionListWsAfterFirst(SDFImpSectionList arg)
{
  if (SDFisImpSectionListMany(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("ImpSectionList has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFImpSectionList SDFsetImpSectionListWsAfterFirst(SDFImpSectionList arg, SDFLayout wsAfterFirst) */

SDFImpSectionList SDFsetImpSectionListWsAfterFirst(SDFImpSectionList arg, SDFLayout wsAfterFirst)
{
  if (SDFisImpSectionListMany(arg)) {
    return (SDFImpSectionList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("ImpSectionList has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasImpSectionListTail(SDFImpSectionList arg) */

ATbool SDFhasImpSectionListTail(SDFImpSectionList arg)
{
  if (SDFisImpSectionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFImpSectionList SDFgetImpSectionListTail(SDFImpSectionList arg) */

SDFImpSectionList SDFgetImpSectionListTail(SDFImpSectionList arg)
{
  if (SDFisImpSectionListMany(arg)) {
    return (SDFImpSectionList)ATgetTail((ATermList)arg, 2);
  }

  ATabort("ImpSectionList has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFImpSectionList SDFsetImpSectionListTail(SDFImpSectionList arg, SDFImpSectionList tail) */

SDFImpSectionList SDFsetImpSectionListTail(SDFImpSectionList arg, SDFImpSectionList tail)
{
  if (SDFisImpSectionListMany(arg)) {
    return (SDFImpSectionList)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("ImpSectionList has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasImpSectionListHead(SDFImpSectionList arg) */

ATbool SDFhasImpSectionListHead(SDFImpSectionList arg)
{
  if (SDFisImpSectionListSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisImpSectionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFImpSection SDFgetImpSectionListHead(SDFImpSectionList arg) */

SDFImpSection SDFgetImpSectionListHead(SDFImpSectionList arg)
{
  if (SDFisImpSectionListSingle(arg)) {
    return (SDFImpSection)ATelementAt((ATermList)arg, 0);
  }
  else if (SDFisImpSectionListMany(arg)) {
    return (SDFImpSection)ATelementAt((ATermList)arg, 0);
  }

  ATabort("ImpSectionList has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFImpSectionList SDFsetImpSectionListHead(SDFImpSectionList arg, SDFImpSection head) */

SDFImpSectionList SDFsetImpSectionListHead(SDFImpSectionList arg, SDFImpSection head)
{
  if (SDFisImpSectionListSingle(arg)) {
    return (SDFImpSectionList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDFisImpSectionListMany(arg)) {
    return (SDFImpSectionList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("ImpSectionList has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFSection accessor implementations */

/*{{{  ATbool SDFisValidSection(SDFSection arg) */

ATbool SDFisValidSection(SDFSection arg)
{
  if (SDFisSectionExports(arg)) {
    return ATtrue;
  }
  else if (SDFisSectionHiddens(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisSectionExports(SDFSection arg) */

ATbool SDFisSectionExports(SDFSection arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSectionExports, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSectionHiddens(SDFSection arg) */

ATbool SDFisSectionHiddens(SDFSection arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSectionHiddens, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasSectionWsAfterExports(SDFSection arg) */

ATbool SDFhasSectionWsAfterExports(SDFSection arg)
{
  if (SDFisSectionExports(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSectionWsAfterExports(SDFSection arg) */

SDFLayout SDFgetSectionWsAfterExports(SDFSection arg)
{
  if (SDFisSectionExports(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Section has no WsAfterExports: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSection SDFsetSectionWsAfterExports(SDFSection arg, SDFLayout wsAfterExports) */

SDFSection SDFsetSectionWsAfterExports(SDFSection arg, SDFLayout wsAfterExports)
{
  if (SDFisSectionExports(arg)) {
    return (SDFSection)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterExports, 0), 1), 2);
  }

  ATabort("Section has no WsAfterExports: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSectionGrammar(SDFSection arg) */

ATbool SDFhasSectionGrammar(SDFSection arg)
{
  if (SDFisSectionExports(arg)) {
    return ATtrue;
  }
  else if (SDFisSectionHiddens(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFGrammar SDFgetSectionGrammar(SDFSection arg) */

SDFGrammar SDFgetSectionGrammar(SDFSection arg)
{
  if (SDFisSectionExports(arg)) {
    return (SDFGrammar)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDFisSectionHiddens(arg)) {
    return (SDFGrammar)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Section has no Grammar: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSection SDFsetSectionGrammar(SDFSection arg, SDFGrammar grammar) */

SDFSection SDFsetSectionGrammar(SDFSection arg, SDFGrammar grammar)
{
  if (SDFisSectionExports(arg)) {
    return (SDFSection)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)grammar, 2), 2);
  }
  else if (SDFisSectionHiddens(arg)) {
    return (SDFSection)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)grammar, 2), 2);
  }

  ATabort("Section has no Grammar: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSectionWsAfterHiddens(SDFSection arg) */

ATbool SDFhasSectionWsAfterHiddens(SDFSection arg)
{
  if (SDFisSectionHiddens(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSectionWsAfterHiddens(SDFSection arg) */

SDFLayout SDFgetSectionWsAfterHiddens(SDFSection arg)
{
  if (SDFisSectionHiddens(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Section has no WsAfterHiddens: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSection SDFsetSectionWsAfterHiddens(SDFSection arg, SDFLayout wsAfterHiddens) */

SDFSection SDFsetSectionWsAfterHiddens(SDFSection arg, SDFLayout wsAfterHiddens)
{
  if (SDFisSectionHiddens(arg)) {
    return (SDFSection)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterHiddens, 0), 1), 2);
  }

  ATabort("Section has no WsAfterHiddens: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFSections accessor implementations */

/*{{{  ATbool SDFisValidSections(SDFSections arg) */

ATbool SDFisValidSections(SDFSections arg)
{
  if (SDFisSectionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisSectionsDefault(SDFSections arg) */

ATbool SDFisSectionsDefault(SDFSections arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSectionsDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasSectionsList(SDFSections arg) */

ATbool SDFhasSectionsList(SDFSections arg)
{
  if (SDFisSectionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSectionList SDFgetSectionsList(SDFSections arg) */

SDFSectionList SDFgetSectionsList(SDFSections arg)
{
  if (SDFisSectionsDefault(arg)) {
    return (SDFSectionList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 2);
  }

  ATabort("Sections has no List: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSections SDFsetSectionsList(SDFSections arg, SDFSectionList list) */

SDFSections SDFsetSectionsList(SDFSections arg, SDFSectionList list)
{
  if (SDFisSectionsDefault(arg)) {
    return (SDFSections)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)list, 2), 0), 2);
  }

  ATabort("Sections has no List: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFSectionList accessor implementations */

/*{{{  ATbool SDFisValidSectionList(SDFSectionList arg) */

ATbool SDFisValidSectionList(SDFSectionList arg)
{
  if (SDFisSectionListEmpty(arg)) {
    return ATtrue;
  }
  else if (SDFisSectionListSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisSectionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisSectionListEmpty(SDFSectionList arg) */

ATbool SDFisSectionListEmpty(SDFSectionList arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSectionListEmpty);
}

/*}}}  */
/*{{{  ATbool SDFisSectionListSingle(SDFSectionList arg) */

ATbool SDFisSectionListSingle(SDFSectionList arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSectionListSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSectionListMany(SDFSectionList arg) */

ATbool SDFisSectionListMany(SDFSectionList arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSectionListMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasSectionListWsAfterFirst(SDFSectionList arg) */

ATbool SDFhasSectionListWsAfterFirst(SDFSectionList arg)
{
  if (SDFisSectionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSectionListWsAfterFirst(SDFSectionList arg) */

SDFLayout SDFgetSectionListWsAfterFirst(SDFSectionList arg)
{
  if (SDFisSectionListMany(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("SectionList has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSectionList SDFsetSectionListWsAfterFirst(SDFSectionList arg, SDFLayout wsAfterFirst) */

SDFSectionList SDFsetSectionListWsAfterFirst(SDFSectionList arg, SDFLayout wsAfterFirst)
{
  if (SDFisSectionListMany(arg)) {
    return (SDFSectionList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("SectionList has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSectionListTail(SDFSectionList arg) */

ATbool SDFhasSectionListTail(SDFSectionList arg)
{
  if (SDFisSectionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSectionList SDFgetSectionListTail(SDFSectionList arg) */

SDFSectionList SDFgetSectionListTail(SDFSectionList arg)
{
  if (SDFisSectionListMany(arg)) {
    return (SDFSectionList)ATgetTail((ATermList)arg, 2);
  }

  ATabort("SectionList has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSectionList SDFsetSectionListTail(SDFSectionList arg, SDFSectionList tail) */

SDFSectionList SDFsetSectionListTail(SDFSectionList arg, SDFSectionList tail)
{
  if (SDFisSectionListMany(arg)) {
    return (SDFSectionList)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("SectionList has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSectionListHead(SDFSectionList arg) */

ATbool SDFhasSectionListHead(SDFSectionList arg)
{
  if (SDFisSectionListSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisSectionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSection SDFgetSectionListHead(SDFSectionList arg) */

SDFSection SDFgetSectionListHead(SDFSectionList arg)
{
  if (SDFisSectionListSingle(arg)) {
    return (SDFSection)ATelementAt((ATermList)arg, 0);
  }
  else if (SDFisSectionListMany(arg)) {
    return (SDFSection)ATelementAt((ATermList)arg, 0);
  }

  ATabort("SectionList has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSectionList SDFsetSectionListHead(SDFSectionList arg, SDFSection head) */

SDFSectionList SDFsetSectionListHead(SDFSectionList arg, SDFSection head)
{
  if (SDFisSectionListSingle(arg)) {
    return (SDFSectionList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDFisSectionListMany(arg)) {
    return (SDFSectionList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("SectionList has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFModuleName accessor implementations */

/*{{{  ATbool SDFisValidModuleName(SDFModuleName arg) */

ATbool SDFisValidModuleName(SDFModuleName arg)
{
  if (SDFisModuleNameUnparameterized(arg)) {
    return ATtrue;
  }
  else if (SDFisModuleNameParameterized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisModuleNameUnparameterized(SDFModuleName arg) */

ATbool SDFisModuleNameUnparameterized(SDFModuleName arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternModuleNameUnparameterized, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisModuleNameParameterized(SDFModuleName arg) */

ATbool SDFisModuleNameParameterized(SDFModuleName arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternModuleNameParameterized, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasModuleNameParams(SDFModuleName arg) */

ATbool SDFhasModuleNameParams(SDFModuleName arg)
{
  if (SDFisModuleNameParameterized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbols SDFgetModuleNameParams(SDFModuleName arg) */

SDFSymbols SDFgetModuleNameParams(SDFModuleName arg)
{
  if (SDFisModuleNameParameterized(arg)) {
    return (SDFSymbols)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("ModuleName has no Params: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFModuleName SDFsetModuleNameParams(SDFModuleName arg, SDFSymbols params) */

SDFModuleName SDFsetModuleNameParams(SDFModuleName arg, SDFSymbols params)
{
  if (SDFisModuleNameParameterized(arg)) {
    return (SDFModuleName)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)params, 4), 2);
  }

  ATabort("ModuleName has no Params: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasModuleNameWsAfterModuleId(SDFModuleName arg) */

ATbool SDFhasModuleNameWsAfterModuleId(SDFModuleName arg)
{
  if (SDFisModuleNameParameterized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetModuleNameWsAfterModuleId(SDFModuleName arg) */

SDFLayout SDFgetModuleNameWsAfterModuleId(SDFModuleName arg)
{
  if (SDFisModuleNameParameterized(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("ModuleName has no WsAfterModuleId: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFModuleName SDFsetModuleNameWsAfterModuleId(SDFModuleName arg, SDFLayout wsAfterModuleId) */

SDFModuleName SDFsetModuleNameWsAfterModuleId(SDFModuleName arg, SDFLayout wsAfterModuleId)
{
  if (SDFisModuleNameParameterized(arg)) {
    return (SDFModuleName)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterModuleId, 0), 1), 2);
  }

  ATabort("ModuleName has no WsAfterModuleId: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasModuleNameModuleId(SDFModuleName arg) */

ATbool SDFhasModuleNameModuleId(SDFModuleName arg)
{
  if (SDFisModuleNameUnparameterized(arg)) {
    return ATtrue;
  }
  else if (SDFisModuleNameParameterized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFModuleId SDFgetModuleNameModuleId(SDFModuleName arg) */

SDFModuleId SDFgetModuleNameModuleId(SDFModuleName arg)
{
  if (SDFisModuleNameUnparameterized(arg)) {
    return (SDFModuleId)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDFisModuleNameParameterized(arg)) {
    return (SDFModuleId)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("ModuleName has no ModuleId: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFModuleName SDFsetModuleNameModuleId(SDFModuleName arg, SDFModuleId moduleId) */

SDFModuleName SDFsetModuleNameModuleId(SDFModuleName arg, SDFModuleId moduleId)
{
  if (SDFisModuleNameUnparameterized(arg)) {
    return (SDFModuleName)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)moduleId, 0), 2);
  }
  else if (SDFisModuleNameParameterized(arg)) {
    return (SDFModuleName)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)moduleId, 0), 2);
  }

  ATabort("ModuleName has no ModuleId: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasModuleNameWsAfterBracketOpen(SDFModuleName arg) */

ATbool SDFhasModuleNameWsAfterBracketOpen(SDFModuleName arg)
{
  if (SDFisModuleNameParameterized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetModuleNameWsAfterBracketOpen(SDFModuleName arg) */

SDFLayout SDFgetModuleNameWsAfterBracketOpen(SDFModuleName arg)
{
  if (SDFisModuleNameParameterized(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("ModuleName has no WsAfterBracketOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFModuleName SDFsetModuleNameWsAfterBracketOpen(SDFModuleName arg, SDFLayout wsAfterBracketOpen) */

SDFModuleName SDFsetModuleNameWsAfterBracketOpen(SDFModuleName arg, SDFLayout wsAfterBracketOpen)
{
  if (SDFisModuleNameParameterized(arg)) {
    return (SDFModuleName)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterBracketOpen, 0), 3), 2);
  }

  ATabort("ModuleName has no WsAfterBracketOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasModuleNameWsAfterParams(SDFModuleName arg) */

ATbool SDFhasModuleNameWsAfterParams(SDFModuleName arg)
{
  if (SDFisModuleNameParameterized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetModuleNameWsAfterParams(SDFModuleName arg) */

SDFLayout SDFgetModuleNameWsAfterParams(SDFModuleName arg)
{
  if (SDFisModuleNameParameterized(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("ModuleName has no WsAfterParams: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFModuleName SDFsetModuleNameWsAfterParams(SDFModuleName arg, SDFLayout wsAfterParams) */

SDFModuleName SDFsetModuleNameWsAfterParams(SDFModuleName arg, SDFLayout wsAfterParams)
{
  if (SDFisModuleNameParameterized(arg)) {
    return (SDFModuleName)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterParams, 0), 5), 2);
  }

  ATabort("ModuleName has no WsAfterParams: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFAttribute accessor implementations */

/*{{{  ATbool SDFisValidAttribute(SDFAttribute arg) */

ATbool SDFisValidAttribute(SDFAttribute arg)
{
  if (SDFisAttributeId(arg)) {
    return ATtrue;
  }
  else if (SDFisAttributeBracket(arg)) {
    return ATtrue;
  }
  else if (SDFisAttributeAtr(arg)) {
    return ATtrue;
  }
  else if (SDFisAttributeCons(arg)) {
    return ATtrue;
  }
  else if (SDFisAttributeConstructor(arg)) {
    return ATtrue;
  }
  else if (SDFisAttributeMemo(arg)) {
    return ATtrue;
  }
  else if (SDFisAttributeReject(arg)) {
    return ATtrue;
  }
  else if (SDFisAttributePrefer(arg)) {
    return ATtrue;
  }
  else if (SDFisAttributeAvoid(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisAttributeId(SDFAttribute arg) */

ATbool SDFisAttributeId(SDFAttribute arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAttributeId, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisAttributeBracket(SDFAttribute arg) */

ATbool SDFisAttributeBracket(SDFAttribute arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAttributeBracket);
}

/*}}}  */
/*{{{  ATbool SDFisAttributeAtr(SDFAttribute arg) */

ATbool SDFisAttributeAtr(SDFAttribute arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAttributeAtr, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisAttributeCons(SDFAttribute arg) */

ATbool SDFisAttributeCons(SDFAttribute arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAttributeCons, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisAttributeConstructor(SDFAttribute arg) */

ATbool SDFisAttributeConstructor(SDFAttribute arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAttributeConstructor);
}

/*}}}  */
/*{{{  ATbool SDFisAttributeMemo(SDFAttribute arg) */

ATbool SDFisAttributeMemo(SDFAttribute arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAttributeMemo);
}

/*}}}  */
/*{{{  ATbool SDFisAttributeReject(SDFAttribute arg) */

ATbool SDFisAttributeReject(SDFAttribute arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAttributeReject);
}

/*}}}  */
/*{{{  ATbool SDFisAttributePrefer(SDFAttribute arg) */

ATbool SDFisAttributePrefer(SDFAttribute arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAttributePrefer);
}

/*}}}  */
/*{{{  ATbool SDFisAttributeAvoid(SDFAttribute arg) */

ATbool SDFisAttributeAvoid(SDFAttribute arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAttributeAvoid);
}

/*}}}  */
/*{{{  ATbool SDFhasAttributeModuleName(SDFAttribute arg) */

ATbool SDFhasAttributeModuleName(SDFAttribute arg)
{
  if (SDFisAttributeId(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFModuleName SDFgetAttributeModuleName(SDFAttribute arg) */

SDFModuleName SDFgetAttributeModuleName(SDFAttribute arg)
{
  if (SDFisAttributeId(arg)) {
    return (SDFModuleName)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Attribute has no ModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAttribute SDFsetAttributeModuleName(SDFAttribute arg, SDFModuleName moduleName) */

SDFAttribute SDFsetAttributeModuleName(SDFAttribute arg, SDFModuleName moduleName)
{
  if (SDFisAttributeId(arg)) {
    return (SDFAttribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)moduleName, 4), 2);
  }

  ATabort("Attribute has no ModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasAttributeWsAfterParenOpen(SDFAttribute arg) */

ATbool SDFhasAttributeWsAfterParenOpen(SDFAttribute arg)
{
  if (SDFisAttributeId(arg)) {
    return ATtrue;
  }
  else if (SDFisAttributeCons(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetAttributeWsAfterParenOpen(SDFAttribute arg) */

SDFLayout SDFgetAttributeWsAfterParenOpen(SDFAttribute arg)
{
  if (SDFisAttributeId(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDFisAttributeCons(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Attribute has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAttribute SDFsetAttributeWsAfterParenOpen(SDFAttribute arg, SDFLayout wsAfterParenOpen) */

SDFAttribute SDFsetAttributeWsAfterParenOpen(SDFAttribute arg, SDFLayout wsAfterParenOpen)
{
  if (SDFisAttributeId(arg)) {
    return (SDFAttribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterParenOpen, 0), 3), 2);
  }
  else if (SDFisAttributeCons(arg)) {
    return (SDFAttribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterParenOpen, 0), 3), 2);
  }

  ATabort("Attribute has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasAttributeWsAfterCons(SDFAttribute arg) */

ATbool SDFhasAttributeWsAfterCons(SDFAttribute arg)
{
  if (SDFisAttributeCons(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetAttributeWsAfterCons(SDFAttribute arg) */

SDFLayout SDFgetAttributeWsAfterCons(SDFAttribute arg)
{
  if (SDFisAttributeCons(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Attribute has no WsAfterCons: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAttribute SDFsetAttributeWsAfterCons(SDFAttribute arg, SDFLayout wsAfterCons) */

SDFAttribute SDFsetAttributeWsAfterCons(SDFAttribute arg, SDFLayout wsAfterCons)
{
  if (SDFisAttributeCons(arg)) {
    return (SDFAttribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterCons, 0), 1), 2);
  }

  ATabort("Attribute has no WsAfterCons: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasAttributeATerm(SDFAttribute arg) */

ATbool SDFhasAttributeATerm(SDFAttribute arg)
{
  if (SDFisAttributeCons(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFATerm SDFgetAttributeATerm(SDFAttribute arg) */

SDFATerm SDFgetAttributeATerm(SDFAttribute arg)
{
  if (SDFisAttributeCons(arg)) {
    return (SDFATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Attribute has no ATerm: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAttribute SDFsetAttributeATerm(SDFAttribute arg, SDFATerm aTerm) */

SDFAttribute SDFsetAttributeATerm(SDFAttribute arg, SDFATerm aTerm)
{
  if (SDFisAttributeCons(arg)) {
    return (SDFAttribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aTerm, 4), 2);
  }

  ATabort("Attribute has no ATerm: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasAttributeWsAfterATerm(SDFAttribute arg) */

ATbool SDFhasAttributeWsAfterATerm(SDFAttribute arg)
{
  if (SDFisAttributeCons(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetAttributeWsAfterATerm(SDFAttribute arg) */

SDFLayout SDFgetAttributeWsAfterATerm(SDFAttribute arg)
{
  if (SDFisAttributeCons(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("Attribute has no WsAfterATerm: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAttribute SDFsetAttributeWsAfterATerm(SDFAttribute arg, SDFLayout wsAfterATerm) */

SDFAttribute SDFsetAttributeWsAfterATerm(SDFAttribute arg, SDFLayout wsAfterATerm)
{
  if (SDFisAttributeCons(arg)) {
    return (SDFAttribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterATerm, 0), 5), 2);
  }

  ATabort("Attribute has no WsAfterATerm: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasAttributeAssociativity(SDFAttribute arg) */

ATbool SDFhasAttributeAssociativity(SDFAttribute arg)
{
  if (SDFisAttributeAtr(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFAssociativity SDFgetAttributeAssociativity(SDFAttribute arg) */

SDFAssociativity SDFgetAttributeAssociativity(SDFAttribute arg)
{
  if (SDFisAttributeAtr(arg)) {
    return (SDFAssociativity)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Attribute has no Associativity: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAttribute SDFsetAttributeAssociativity(SDFAttribute arg, SDFAssociativity associativity) */

SDFAttribute SDFsetAttributeAssociativity(SDFAttribute arg, SDFAssociativity associativity)
{
  if (SDFisAttributeAtr(arg)) {
    return (SDFAttribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)associativity, 0), 2);
  }

  ATabort("Attribute has no Associativity: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasAttributeWsAfterId(SDFAttribute arg) */

ATbool SDFhasAttributeWsAfterId(SDFAttribute arg)
{
  if (SDFisAttributeId(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetAttributeWsAfterId(SDFAttribute arg) */

SDFLayout SDFgetAttributeWsAfterId(SDFAttribute arg)
{
  if (SDFisAttributeId(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Attribute has no WsAfterId: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAttribute SDFsetAttributeWsAfterId(SDFAttribute arg, SDFLayout wsAfterId) */

SDFAttribute SDFsetAttributeWsAfterId(SDFAttribute arg, SDFLayout wsAfterId)
{
  if (SDFisAttributeId(arg)) {
    return (SDFAttribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterId, 0), 1), 2);
  }

  ATabort("Attribute has no WsAfterId: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasAttributeWsAfterModuleName(SDFAttribute arg) */

ATbool SDFhasAttributeWsAfterModuleName(SDFAttribute arg)
{
  if (SDFisAttributeId(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetAttributeWsAfterModuleName(SDFAttribute arg) */

SDFLayout SDFgetAttributeWsAfterModuleName(SDFAttribute arg)
{
  if (SDFisAttributeId(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("Attribute has no WsAfterModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAttribute SDFsetAttributeWsAfterModuleName(SDFAttribute arg, SDFLayout wsAfterModuleName) */

SDFAttribute SDFsetAttributeWsAfterModuleName(SDFAttribute arg, SDFLayout wsAfterModuleName)
{
  if (SDFisAttributeId(arg)) {
    return (SDFAttribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterModuleName, 0), 5), 2);
  }

  ATabort("Attribute has no WsAfterModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFImpSection accessor implementations */

/*{{{  ATbool SDFisValidImpSection(SDFImpSection arg) */

ATbool SDFisValidImpSection(SDFImpSection arg)
{
  if (SDFisImpSectionImports(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisImpSectionImports(SDFImpSection arg) */

ATbool SDFisImpSectionImports(SDFImpSection arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternImpSectionImports, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasImpSectionWsAfterImports(SDFImpSection arg) */

ATbool SDFhasImpSectionWsAfterImports(SDFImpSection arg)
{
  if (SDFisImpSectionImports(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetImpSectionWsAfterImports(SDFImpSection arg) */

SDFLayout SDFgetImpSectionWsAfterImports(SDFImpSection arg)
{
  if (SDFisImpSectionImports(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("ImpSection has no WsAfterImports: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFImpSection SDFsetImpSectionWsAfterImports(SDFImpSection arg, SDFLayout wsAfterImports) */

SDFImpSection SDFsetImpSectionWsAfterImports(SDFImpSection arg, SDFLayout wsAfterImports)
{
  if (SDFisImpSectionImports(arg)) {
    return (SDFImpSection)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterImports, 0), 1), 2);
  }

  ATabort("ImpSection has no WsAfterImports: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasImpSectionList(SDFImpSection arg) */

ATbool SDFhasImpSectionList(SDFImpSection arg)
{
  if (SDFisImpSectionImports(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFImports SDFgetImpSectionList(SDFImpSection arg) */

SDFImports SDFgetImpSectionList(SDFImpSection arg)
{
  if (SDFisImpSectionImports(arg)) {
    return (SDFImports)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("ImpSection has no List: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFImpSection SDFsetImpSectionList(SDFImpSection arg, SDFImports list) */

SDFImpSection SDFsetImpSectionList(SDFImpSection arg, SDFImports list)
{
  if (SDFisImpSectionImports(arg)) {
    return (SDFImpSection)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)list, 2), 2);
  }

  ATabort("ImpSection has no List: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFImports accessor implementations */

/*{{{  ATbool SDFisValidImports(SDFImports arg) */

ATbool SDFisValidImports(SDFImports arg)
{
  if (SDFisImportsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisImportsDefault(SDFImports arg) */

ATbool SDFisImportsDefault(SDFImports arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternImportsDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasImportsList(SDFImports arg) */

ATbool SDFhasImportsList(SDFImports arg)
{
  if (SDFisImportsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFImportList SDFgetImportsList(SDFImports arg) */

SDFImportList SDFgetImportsList(SDFImports arg)
{
  if (SDFisImportsDefault(arg)) {
    return (SDFImportList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 2);
  }

  ATabort("Imports has no List: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFImports SDFsetImportsList(SDFImports arg, SDFImportList list) */

SDFImports SDFsetImportsList(SDFImports arg, SDFImportList list)
{
  if (SDFisImportsDefault(arg)) {
    return (SDFImports)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)list, 2), 0), 2);
  }

  ATabort("Imports has no List: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFImportList accessor implementations */

/*{{{  ATbool SDFisValidImportList(SDFImportList arg) */

ATbool SDFisValidImportList(SDFImportList arg)
{
  if (SDFisImportListEmpty(arg)) {
    return ATtrue;
  }
  else if (SDFisImportListSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisImportListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisImportListEmpty(SDFImportList arg) */

ATbool SDFisImportListEmpty(SDFImportList arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternImportListEmpty);
}

/*}}}  */
/*{{{  ATbool SDFisImportListSingle(SDFImportList arg) */

ATbool SDFisImportListSingle(SDFImportList arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternImportListSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisImportListMany(SDFImportList arg) */

ATbool SDFisImportListMany(SDFImportList arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternImportListMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasImportListWsAfterFirst(SDFImportList arg) */

ATbool SDFhasImportListWsAfterFirst(SDFImportList arg)
{
  if (SDFisImportListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetImportListWsAfterFirst(SDFImportList arg) */

SDFLayout SDFgetImportListWsAfterFirst(SDFImportList arg)
{
  if (SDFisImportListMany(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("ImportList has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFImportList SDFsetImportListWsAfterFirst(SDFImportList arg, SDFLayout wsAfterFirst) */

SDFImportList SDFsetImportListWsAfterFirst(SDFImportList arg, SDFLayout wsAfterFirst)
{
  if (SDFisImportListMany(arg)) {
    return (SDFImportList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("ImportList has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasImportListTail(SDFImportList arg) */

ATbool SDFhasImportListTail(SDFImportList arg)
{
  if (SDFisImportListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFImportList SDFgetImportListTail(SDFImportList arg) */

SDFImportList SDFgetImportListTail(SDFImportList arg)
{
  if (SDFisImportListMany(arg)) {
    return (SDFImportList)ATgetTail((ATermList)arg, 2);
  }

  ATabort("ImportList has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFImportList SDFsetImportListTail(SDFImportList arg, SDFImportList tail) */

SDFImportList SDFsetImportListTail(SDFImportList arg, SDFImportList tail)
{
  if (SDFisImportListMany(arg)) {
    return (SDFImportList)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("ImportList has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasImportListHead(SDFImportList arg) */

ATbool SDFhasImportListHead(SDFImportList arg)
{
  if (SDFisImportListSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisImportListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFImport SDFgetImportListHead(SDFImportList arg) */

SDFImport SDFgetImportListHead(SDFImportList arg)
{
  if (SDFisImportListSingle(arg)) {
    return (SDFImport)ATelementAt((ATermList)arg, 0);
  }
  else if (SDFisImportListMany(arg)) {
    return (SDFImport)ATelementAt((ATermList)arg, 0);
  }

  ATabort("ImportList has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFImportList SDFsetImportListHead(SDFImportList arg, SDFImport head) */

SDFImportList SDFsetImportListHead(SDFImportList arg, SDFImport head)
{
  if (SDFisImportListSingle(arg)) {
    return (SDFImportList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDFisImportListMany(arg)) {
    return (SDFImportList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("ImportList has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFImport accessor implementations */

/*{{{  ATbool SDFisValidImport(SDFImport arg) */

ATbool SDFisValidImport(SDFImport arg)
{
  if (SDFisImportModule(arg)) {
    return ATtrue;
  }
  else if (SDFisImportRenamedModule(arg)) {
    return ATtrue;
  }
  else if (SDFisImportBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisImportModule(SDFImport arg) */

ATbool SDFisImportModule(SDFImport arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternImportModule, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisImportRenamedModule(SDFImport arg) */

ATbool SDFisImportRenamedModule(SDFImport arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternImportRenamedModule, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisImportBracket(SDFImport arg) */

ATbool SDFisImportBracket(SDFImport arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternImportBracket, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasImportModuleName(SDFImport arg) */

ATbool SDFhasImportModuleName(SDFImport arg)
{
  if (SDFisImportModule(arg)) {
    return ATtrue;
  }
  else if (SDFisImportRenamedModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFModuleName SDFgetImportModuleName(SDFImport arg) */

SDFModuleName SDFgetImportModuleName(SDFImport arg)
{
  if (SDFisImportModule(arg)) {
    return (SDFModuleName)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDFisImportRenamedModule(arg)) {
    return (SDFModuleName)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Import has no ModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFImport SDFsetImportModuleName(SDFImport arg, SDFModuleName moduleName) */

SDFImport SDFsetImportModuleName(SDFImport arg, SDFModuleName moduleName)
{
  if (SDFisImportModule(arg)) {
    return (SDFImport)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)moduleName, 0), 2);
  }
  else if (SDFisImportRenamedModule(arg)) {
    return (SDFImport)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)moduleName, 0), 2);
  }

  ATabort("Import has no ModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasImportWsAfterParenOpen(SDFImport arg) */

ATbool SDFhasImportWsAfterParenOpen(SDFImport arg)
{
  if (SDFisImportBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetImportWsAfterParenOpen(SDFImport arg) */

SDFLayout SDFgetImportWsAfterParenOpen(SDFImport arg)
{
  if (SDFisImportBracket(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Import has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFImport SDFsetImportWsAfterParenOpen(SDFImport arg, SDFLayout wsAfterParenOpen) */

SDFImport SDFsetImportWsAfterParenOpen(SDFImport arg, SDFLayout wsAfterParenOpen)
{
  if (SDFisImportBracket(arg)) {
    return (SDFImport)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterParenOpen, 0), 1), 2);
  }

  ATabort("Import has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasImportRenamings(SDFImport arg) */

ATbool SDFhasImportRenamings(SDFImport arg)
{
  if (SDFisImportRenamedModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFRenamings SDFgetImportRenamings(SDFImport arg) */

SDFRenamings SDFgetImportRenamings(SDFImport arg)
{
  if (SDFisImportRenamedModule(arg)) {
    return (SDFRenamings)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Import has no Renamings: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFImport SDFsetImportRenamings(SDFImport arg, SDFRenamings renamings) */

SDFImport SDFsetImportRenamings(SDFImport arg, SDFRenamings renamings)
{
  if (SDFisImportRenamedModule(arg)) {
    return (SDFImport)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)renamings, 2), 2);
  }

  ATabort("Import has no Renamings: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasImportWsAfterImport(SDFImport arg) */

ATbool SDFhasImportWsAfterImport(SDFImport arg)
{
  if (SDFisImportBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetImportWsAfterImport(SDFImport arg) */

SDFLayout SDFgetImportWsAfterImport(SDFImport arg)
{
  if (SDFisImportBracket(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Import has no WsAfterImport: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFImport SDFsetImportWsAfterImport(SDFImport arg, SDFLayout wsAfterImport) */

SDFImport SDFsetImportWsAfterImport(SDFImport arg, SDFLayout wsAfterImport)
{
  if (SDFisImportBracket(arg)) {
    return (SDFImport)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterImport, 0), 3), 2);
  }

  ATabort("Import has no WsAfterImport: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasImportImport(SDFImport arg) */

ATbool SDFhasImportImport(SDFImport arg)
{
  if (SDFisImportBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFImport SDFgetImportImport(SDFImport arg) */

SDFImport SDFgetImportImport(SDFImport arg)
{
  if (SDFisImportBracket(arg)) {
    return (SDFImport)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Import has no Import: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFImport SDFsetImportImport(SDFImport arg, SDFImport import) */

SDFImport SDFsetImportImport(SDFImport arg, SDFImport import)
{
  if (SDFisImportBracket(arg)) {
    return (SDFImport)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)import, 2), 2);
  }

  ATabort("Import has no Import: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasImportWsAfterModuleName(SDFImport arg) */

ATbool SDFhasImportWsAfterModuleName(SDFImport arg)
{
  if (SDFisImportRenamedModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetImportWsAfterModuleName(SDFImport arg) */

SDFLayout SDFgetImportWsAfterModuleName(SDFImport arg)
{
  if (SDFisImportRenamedModule(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Import has no WsAfterModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFImport SDFsetImportWsAfterModuleName(SDFImport arg, SDFLayout wsAfterModuleName) */

SDFImport SDFsetImportWsAfterModuleName(SDFImport arg, SDFLayout wsAfterModuleName)
{
  if (SDFisImportRenamedModule(arg)) {
    return (SDFImport)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterModuleName, 0), 1), 2);
  }

  ATabort("Import has no WsAfterModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFSymbolTail accessor implementations */

/*{{{  ATbool SDFisValidSymbolTail(SDFSymbolTail arg) */

ATbool SDFisValidSymbolTail(SDFSymbolTail arg)
{
  if (SDFisSymbolTailSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolTailMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisSymbolTailSingle(SDFSymbolTail arg) */

ATbool SDFisSymbolTailSingle(SDFSymbolTail arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolTailSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolTailMany(SDFSymbolTail arg) */

ATbool SDFisSymbolTailMany(SDFSymbolTail arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolTailMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolTailWsAfterFirst(SDFSymbolTail arg) */

ATbool SDFhasSymbolTailWsAfterFirst(SDFSymbolTail arg)
{
  if (SDFisSymbolTailMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolTailWsAfterFirst(SDFSymbolTail arg) */

SDFLayout SDFgetSymbolTailWsAfterFirst(SDFSymbolTail arg)
{
  if (SDFisSymbolTailMany(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("SymbolTail has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbolTail SDFsetSymbolTailWsAfterFirst(SDFSymbolTail arg, SDFLayout wsAfterFirst) */

SDFSymbolTail SDFsetSymbolTailWsAfterFirst(SDFSymbolTail arg, SDFLayout wsAfterFirst)
{
  if (SDFisSymbolTailMany(arg)) {
    return (SDFSymbolTail)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("SymbolTail has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolTailTail(SDFSymbolTail arg) */

ATbool SDFhasSymbolTailTail(SDFSymbolTail arg)
{
  if (SDFisSymbolTailMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbolTail SDFgetSymbolTailTail(SDFSymbolTail arg) */

SDFSymbolTail SDFgetSymbolTailTail(SDFSymbolTail arg)
{
  if (SDFisSymbolTailMany(arg)) {
    return (SDFSymbolTail)ATgetTail((ATermList)arg, 2);
  }

  ATabort("SymbolTail has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbolTail SDFsetSymbolTailTail(SDFSymbolTail arg, SDFSymbolTail tail) */

SDFSymbolTail SDFsetSymbolTailTail(SDFSymbolTail arg, SDFSymbolTail tail)
{
  if (SDFisSymbolTailMany(arg)) {
    return (SDFSymbolTail)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("SymbolTail has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolTailHead(SDFSymbolTail arg) */

ATbool SDFhasSymbolTailHead(SDFSymbolTail arg)
{
  if (SDFisSymbolTailSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolTailMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbol SDFgetSymbolTailHead(SDFSymbolTail arg) */

SDFSymbol SDFgetSymbolTailHead(SDFSymbolTail arg)
{
  if (SDFisSymbolTailSingle(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)arg, 0);
  }
  else if (SDFisSymbolTailMany(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)arg, 0);
  }

  ATabort("SymbolTail has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbolTail SDFsetSymbolTailHead(SDFSymbolTail arg, SDFSymbol head) */

SDFSymbolTail SDFsetSymbolTailHead(SDFSymbolTail arg, SDFSymbol head)
{
  if (SDFisSymbolTailSingle(arg)) {
    return (SDFSymbolTail)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDFisSymbolTailMany(arg)) {
    return (SDFSymbolTail)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("SymbolTail has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFAssociativity accessor implementations */

/*{{{  ATbool SDFisValidAssociativity(SDFAssociativity arg) */

ATbool SDFisValidAssociativity(SDFAssociativity arg)
{
  if (SDFisAssociativityLeft(arg)) {
    return ATtrue;
  }
  else if (SDFisAssociativityRight(arg)) {
    return ATtrue;
  }
  else if (SDFisAssociativityNonAssoc(arg)) {
    return ATtrue;
  }
  else if (SDFisAssociativityAssoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisAssociativityLeft(SDFAssociativity arg) */

ATbool SDFisAssociativityLeft(SDFAssociativity arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAssociativityLeft);
}

/*}}}  */
/*{{{  ATbool SDFisAssociativityRight(SDFAssociativity arg) */

ATbool SDFisAssociativityRight(SDFAssociativity arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAssociativityRight);
}

/*}}}  */
/*{{{  ATbool SDFisAssociativityNonAssoc(SDFAssociativity arg) */

ATbool SDFisAssociativityNonAssoc(SDFAssociativity arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAssociativityNonAssoc);
}

/*}}}  */
/*{{{  ATbool SDFisAssociativityAssoc(SDFAssociativity arg) */

ATbool SDFisAssociativityAssoc(SDFAssociativity arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAssociativityAssoc);
}

/*}}}  */

/*}}}  */
/*{{{  SDFGroup accessor implementations */

/*{{{  ATbool SDFisValidGroup(SDFGroup arg) */

ATbool SDFisValidGroup(SDFGroup arg)
{
  if (SDFisGroupSimpleGroup(arg)) {
    return ATtrue;
  }
  else if (SDFisGroupProdsGroup(arg)) {
    return ATtrue;
  }
  else if (SDFisGroupAssocGroup(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisGroupSimpleGroup(SDFGroup arg) */

ATbool SDFisGroupSimpleGroup(SDFGroup arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternGroupSimpleGroup, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisGroupProdsGroup(SDFGroup arg) */

ATbool SDFisGroupProdsGroup(SDFGroup arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternGroupProdsGroup, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisGroupAssocGroup(SDFGroup arg) */

ATbool SDFisGroupAssocGroup(SDFGroup arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternGroupAssocGroup, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasGroupWsAfterAssociativity(SDFGroup arg) */

ATbool SDFhasGroupWsAfterAssociativity(SDFGroup arg)
{
  if (SDFisGroupAssocGroup(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetGroupWsAfterAssociativity(SDFGroup arg) */

SDFLayout SDFgetGroupWsAfterAssociativity(SDFGroup arg)
{
  if (SDFisGroupAssocGroup(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Group has no WsAfterAssociativity: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGroup SDFsetGroupWsAfterAssociativity(SDFGroup arg, SDFLayout wsAfterAssociativity) */

SDFGroup SDFsetGroupWsAfterAssociativity(SDFGroup arg, SDFLayout wsAfterAssociativity)
{
  if (SDFisGroupAssocGroup(arg)) {
    return (SDFGroup)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterAssociativity, 0), 3), 2);
  }

  ATabort("Group has no WsAfterAssociativity: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGroupWsAfterBraceOpen(SDFGroup arg) */

ATbool SDFhasGroupWsAfterBraceOpen(SDFGroup arg)
{
  if (SDFisGroupProdsGroup(arg)) {
    return ATtrue;
  }
  else if (SDFisGroupAssocGroup(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetGroupWsAfterBraceOpen(SDFGroup arg) */

SDFLayout SDFgetGroupWsAfterBraceOpen(SDFGroup arg)
{
  if (SDFisGroupProdsGroup(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisGroupAssocGroup(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Group has no WsAfterBraceOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGroup SDFsetGroupWsAfterBraceOpen(SDFGroup arg, SDFLayout wsAfterBraceOpen) */

SDFGroup SDFsetGroupWsAfterBraceOpen(SDFGroup arg, SDFLayout wsAfterBraceOpen)
{
  if (SDFisGroupProdsGroup(arg)) {
    return (SDFGroup)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterBraceOpen, 0), 1), 2);
  }
  else if (SDFisGroupAssocGroup(arg)) {
    return (SDFGroup)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterBraceOpen, 0), 1), 2);
  }

  ATabort("Group has no WsAfterBraceOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGroupProduction(SDFGroup arg) */

ATbool SDFhasGroupProduction(SDFGroup arg)
{
  if (SDFisGroupSimpleGroup(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFProduction SDFgetGroupProduction(SDFGroup arg) */

SDFProduction SDFgetGroupProduction(SDFGroup arg)
{
  if (SDFisGroupSimpleGroup(arg)) {
    return (SDFProduction)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Group has no Production: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGroup SDFsetGroupProduction(SDFGroup arg, SDFProduction production) */

SDFGroup SDFsetGroupProduction(SDFGroup arg, SDFProduction production)
{
  if (SDFisGroupSimpleGroup(arg)) {
    return (SDFGroup)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)production, 0), 2);
  }

  ATabort("Group has no Production: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGroupAssociativity(SDFGroup arg) */

ATbool SDFhasGroupAssociativity(SDFGroup arg)
{
  if (SDFisGroupAssocGroup(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFAssociativity SDFgetGroupAssociativity(SDFGroup arg) */

SDFAssociativity SDFgetGroupAssociativity(SDFGroup arg)
{
  if (SDFisGroupAssocGroup(arg)) {
    return (SDFAssociativity)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Group has no Associativity: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGroup SDFsetGroupAssociativity(SDFGroup arg, SDFAssociativity associativity) */

SDFGroup SDFsetGroupAssociativity(SDFGroup arg, SDFAssociativity associativity)
{
  if (SDFisGroupAssocGroup(arg)) {
    return (SDFGroup)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)associativity, 2), 2);
  }

  ATabort("Group has no Associativity: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGroupProductions(SDFGroup arg) */

ATbool SDFhasGroupProductions(SDFGroup arg)
{
  if (SDFisGroupProdsGroup(arg)) {
    return ATtrue;
  }
  else if (SDFisGroupAssocGroup(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFProductions SDFgetGroupProductions(SDFGroup arg) */

SDFProductions SDFgetGroupProductions(SDFGroup arg)
{
  if (SDFisGroupProdsGroup(arg)) {
    return (SDFProductions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDFisGroupAssocGroup(arg)) {
    return (SDFProductions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 6);
  }

  ATabort("Group has no Productions: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGroup SDFsetGroupProductions(SDFGroup arg, SDFProductions productions) */

SDFGroup SDFsetGroupProductions(SDFGroup arg, SDFProductions productions)
{
  if (SDFisGroupProdsGroup(arg)) {
    return (SDFGroup)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)productions, 2), 2);
  }
  else if (SDFisGroupAssocGroup(arg)) {
    return (SDFGroup)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)productions, 6), 2);
  }

  ATabort("Group has no Productions: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGroupWsAfterProductions(SDFGroup arg) */

ATbool SDFhasGroupWsAfterProductions(SDFGroup arg)
{
  if (SDFisGroupProdsGroup(arg)) {
    return ATtrue;
  }
  else if (SDFisGroupAssocGroup(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetGroupWsAfterProductions(SDFGroup arg) */

SDFLayout SDFgetGroupWsAfterProductions(SDFGroup arg)
{
  if (SDFisGroupProdsGroup(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDFisGroupAssocGroup(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), 0);
  }

  ATabort("Group has no WsAfterProductions: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGroup SDFsetGroupWsAfterProductions(SDFGroup arg, SDFLayout wsAfterProductions) */

SDFGroup SDFsetGroupWsAfterProductions(SDFGroup arg, SDFLayout wsAfterProductions)
{
  if (SDFisGroupProdsGroup(arg)) {
    return (SDFGroup)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterProductions, 0), 3), 2);
  }
  else if (SDFisGroupAssocGroup(arg)) {
    return (SDFGroup)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), (ATerm)wsAfterProductions, 0), 7), 2);
  }

  ATabort("Group has no WsAfterProductions: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGroupWsAfterColon(SDFGroup arg) */

ATbool SDFhasGroupWsAfterColon(SDFGroup arg)
{
  if (SDFisGroupAssocGroup(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetGroupWsAfterColon(SDFGroup arg) */

SDFLayout SDFgetGroupWsAfterColon(SDFGroup arg)
{
  if (SDFisGroupAssocGroup(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("Group has no WsAfterColon: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGroup SDFsetGroupWsAfterColon(SDFGroup arg, SDFLayout wsAfterColon) */

SDFGroup SDFsetGroupWsAfterColon(SDFGroup arg, SDFLayout wsAfterColon)
{
  if (SDFisGroupAssocGroup(arg)) {
    return (SDFGroup)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterColon, 0), 5), 2);
  }

  ATabort("Group has no WsAfterColon: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFPriority accessor implementations */

/*{{{  ATbool SDFisValidPriority(SDFPriority arg) */

ATbool SDFisValidPriority(SDFPriority arg)
{
  if (SDFisPriorityPriorityChain(arg)) {
    return ATtrue;
  }
  else if (SDFisPriorityPriorityAssoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisPriorityPriorityChain(SDFPriority arg) */

ATbool SDFisPriorityPriorityChain(SDFPriority arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternPriorityPriorityChain, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisPriorityPriorityAssoc(SDFPriority arg) */

ATbool SDFisPriorityPriorityAssoc(SDFPriority arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternPriorityPriorityAssoc, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasPriorityRight(SDFPriority arg) */

ATbool SDFhasPriorityRight(SDFPriority arg)
{
  if (SDFisPriorityPriorityAssoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFGroup SDFgetPriorityRight(SDFPriority arg) */

SDFGroup SDFgetPriorityRight(SDFPriority arg)
{
  if (SDFisPriorityPriorityAssoc(arg)) {
    return (SDFGroup)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Priority has no Right: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFPriority SDFsetPriorityRight(SDFPriority arg, SDFGroup right) */

SDFPriority SDFsetPriorityRight(SDFPriority arg, SDFGroup right)
{
  if (SDFisPriorityPriorityAssoc(arg)) {
    return (SDFPriority)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)right, 4), 2);
  }

  ATabort("Priority has no Right: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasPriorityWsAfterAssociativity(SDFPriority arg) */

ATbool SDFhasPriorityWsAfterAssociativity(SDFPriority arg)
{
  if (SDFisPriorityPriorityAssoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetPriorityWsAfterAssociativity(SDFPriority arg) */

SDFLayout SDFgetPriorityWsAfterAssociativity(SDFPriority arg)
{
  if (SDFisPriorityPriorityAssoc(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Priority has no WsAfterAssociativity: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFPriority SDFsetPriorityWsAfterAssociativity(SDFPriority arg, SDFLayout wsAfterAssociativity) */

SDFPriority SDFsetPriorityWsAfterAssociativity(SDFPriority arg, SDFLayout wsAfterAssociativity)
{
  if (SDFisPriorityPriorityAssoc(arg)) {
    return (SDFPriority)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterAssociativity, 0), 3), 2);
  }

  ATabort("Priority has no WsAfterAssociativity: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasPriorityWsAfterLeft(SDFPriority arg) */

ATbool SDFhasPriorityWsAfterLeft(SDFPriority arg)
{
  if (SDFisPriorityPriorityAssoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetPriorityWsAfterLeft(SDFPriority arg) */

SDFLayout SDFgetPriorityWsAfterLeft(SDFPriority arg)
{
  if (SDFisPriorityPriorityAssoc(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Priority has no WsAfterLeft: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFPriority SDFsetPriorityWsAfterLeft(SDFPriority arg, SDFLayout wsAfterLeft) */

SDFPriority SDFsetPriorityWsAfterLeft(SDFPriority arg, SDFLayout wsAfterLeft)
{
  if (SDFisPriorityPriorityAssoc(arg)) {
    return (SDFPriority)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLeft, 0), 1), 2);
  }

  ATabort("Priority has no WsAfterLeft: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasPriorityGroupp(SDFPriority arg) */

ATbool SDFhasPriorityGroupp(SDFPriority arg)
{
  if (SDFisPriorityPriorityChain(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFGroupGroupp SDFgetPriorityGroupp(SDFPriority arg) */

SDFGroupGroupp SDFgetPriorityGroupp(SDFPriority arg)
{
  if (SDFisPriorityPriorityChain(arg)) {
    return (SDFGroupGroupp)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 2);
  }

  ATabort("Priority has no Groupp: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFPriority SDFsetPriorityGroupp(SDFPriority arg, SDFGroupGroupp groupp) */

SDFPriority SDFsetPriorityGroupp(SDFPriority arg, SDFGroupGroupp groupp)
{
  if (SDFisPriorityPriorityChain(arg)) {
    return (SDFPriority)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)groupp, 2), 0), 2);
  }

  ATabort("Priority has no Groupp: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasPriorityAssociativity(SDFPriority arg) */

ATbool SDFhasPriorityAssociativity(SDFPriority arg)
{
  if (SDFisPriorityPriorityAssoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFAssociativity SDFgetPriorityAssociativity(SDFPriority arg) */

SDFAssociativity SDFgetPriorityAssociativity(SDFPriority arg)
{
  if (SDFisPriorityPriorityAssoc(arg)) {
    return (SDFAssociativity)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Priority has no Associativity: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFPriority SDFsetPriorityAssociativity(SDFPriority arg, SDFAssociativity associativity) */

SDFPriority SDFsetPriorityAssociativity(SDFPriority arg, SDFAssociativity associativity)
{
  if (SDFisPriorityPriorityAssoc(arg)) {
    return (SDFPriority)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)associativity, 2), 2);
  }

  ATabort("Priority has no Associativity: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasPriorityLeft(SDFPriority arg) */

ATbool SDFhasPriorityLeft(SDFPriority arg)
{
  if (SDFisPriorityPriorityAssoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFGroup SDFgetPriorityLeft(SDFPriority arg) */

SDFGroup SDFgetPriorityLeft(SDFPriority arg)
{
  if (SDFisPriorityPriorityAssoc(arg)) {
    return (SDFGroup)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Priority has no Left: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFPriority SDFsetPriorityLeft(SDFPriority arg, SDFGroup left) */

SDFPriority SDFsetPriorityLeft(SDFPriority arg, SDFGroup left)
{
  if (SDFisPriorityPriorityAssoc(arg)) {
    return (SDFPriority)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)left, 0), 2);
  }

  ATabort("Priority has no Left: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFGroupGroupp accessor implementations */

/*{{{  ATbool SDFisValidGroupGroupp(SDFGroupGroupp arg) */

ATbool SDFisValidGroupGroupp(SDFGroupGroupp arg)
{
  if (SDFisGroupGrouppSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisGroupGrouppMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisGroupGrouppSingle(SDFGroupGroupp arg) */

ATbool SDFisGroupGrouppSingle(SDFGroupGroupp arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternGroupGrouppSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisGroupGrouppMany(SDFGroupGroupp arg) */

ATbool SDFisGroupGrouppMany(SDFGroupGroupp arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternGroupGrouppMany, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasGroupGrouppWsAfterFirst(SDFGroupGroupp arg) */

ATbool SDFhasGroupGrouppWsAfterFirst(SDFGroupGroupp arg)
{
  if (SDFisGroupGrouppMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetGroupGrouppWsAfterFirst(SDFGroupGroupp arg) */

SDFLayout SDFgetGroupGrouppWsAfterFirst(SDFGroupGroupp arg)
{
  if (SDFisGroupGrouppMany(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("GroupGroupp has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGroupGroupp SDFsetGroupGrouppWsAfterFirst(SDFGroupGroupp arg, SDFLayout wsAfterFirst) */

SDFGroupGroupp SDFsetGroupGrouppWsAfterFirst(SDFGroupGroupp arg, SDFLayout wsAfterFirst)
{
  if (SDFisGroupGrouppMany(arg)) {
    return (SDFGroupGroupp)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("GroupGroupp has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGroupGrouppWsAfterSep(SDFGroupGroupp arg) */

ATbool SDFhasGroupGrouppWsAfterSep(SDFGroupGroupp arg)
{
  if (SDFisGroupGrouppMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetGroupGrouppWsAfterSep(SDFGroupGroupp arg) */

SDFLayout SDFgetGroupGrouppWsAfterSep(SDFGroupGroupp arg)
{
  if (SDFisGroupGrouppMany(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), 0);
  }

  ATabort("GroupGroupp has no WsAfterSep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGroupGroupp SDFsetGroupGrouppWsAfterSep(SDFGroupGroupp arg, SDFLayout wsAfterSep) */

SDFGroupGroupp SDFsetGroupGrouppWsAfterSep(SDFGroupGroupp arg, SDFLayout wsAfterSep)
{
  if (SDFisGroupGrouppMany(arg)) {
    return (SDFGroupGroupp)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), (ATerm)wsAfterSep, 0), 3);
  }

  ATabort("GroupGroupp has no WsAfterSep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGroupGrouppTail(SDFGroupGroupp arg) */

ATbool SDFhasGroupGrouppTail(SDFGroupGroupp arg)
{
  if (SDFisGroupGrouppMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFGroupGroupp SDFgetGroupGrouppTail(SDFGroupGroupp arg) */

SDFGroupGroupp SDFgetGroupGrouppTail(SDFGroupGroupp arg)
{
  if (SDFisGroupGrouppMany(arg)) {
    return (SDFGroupGroupp)ATgetTail((ATermList)arg, 4);
  }

  ATabort("GroupGroupp has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGroupGroupp SDFsetGroupGrouppTail(SDFGroupGroupp arg, SDFGroupGroupp tail) */

SDFGroupGroupp SDFsetGroupGrouppTail(SDFGroupGroupp arg, SDFGroupGroupp tail)
{
  if (SDFisGroupGrouppMany(arg)) {
    return (SDFGroupGroupp)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("GroupGroupp has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGroupGrouppHead(SDFGroupGroupp arg) */

ATbool SDFhasGroupGrouppHead(SDFGroupGroupp arg)
{
  if (SDFisGroupGrouppSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisGroupGrouppMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFGroup SDFgetGroupGrouppHead(SDFGroupGroupp arg) */

SDFGroup SDFgetGroupGrouppHead(SDFGroupGroupp arg)
{
  if (SDFisGroupGrouppSingle(arg)) {
    return (SDFGroup)ATelementAt((ATermList)arg, 0);
  }
  else if (SDFisGroupGrouppMany(arg)) {
    return (SDFGroup)ATelementAt((ATermList)arg, 0);
  }

  ATabort("GroupGroupp has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGroupGroupp SDFsetGroupGrouppHead(SDFGroupGroupp arg, SDFGroup head) */

SDFGroupGroupp SDFsetGroupGrouppHead(SDFGroupGroupp arg, SDFGroup head)
{
  if (SDFisGroupGrouppSingle(arg)) {
    return (SDFGroupGroupp)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDFisGroupGrouppMany(arg)) {
    return (SDFGroupGroupp)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("GroupGroupp has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasGroupGrouppSep(SDFGroupGroupp arg) */

ATbool SDFhasGroupGrouppSep(SDFGroupGroupp arg)
{
  if (SDFisGroupGrouppMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSeparator SDFgetGroupGrouppSep(SDFGroupGroupp arg) */

SDFSeparator SDFgetGroupGrouppSep(SDFGroupGroupp arg)
{
  if (SDFisGroupGrouppMany(arg)) {
    return (SDFSeparator)ATelementAt((ATermList)arg, 2);
  }

  ATabort("GroupGroupp has no Sep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFGroupGroupp SDFsetGroupGrouppSep(SDFGroupGroupp arg, SDFSeparator sep) */

SDFGroupGroupp SDFsetGroupGrouppSep(SDFGroupGroupp arg, SDFSeparator sep)
{
  if (SDFisGroupGrouppMany(arg)) {
    return (SDFGroupGroupp)ATreplace((ATermList)arg, (ATerm)sep, 2);
  }

  ATabort("GroupGroupp has no Sep: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFPriorities accessor implementations */

/*{{{  ATbool SDFisValidPriorities(SDFPriorities arg) */

ATbool SDFisValidPriorities(SDFPriorities arg)
{
  if (SDFisPrioritiesDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisPrioritiesDefault(SDFPriorities arg) */

ATbool SDFisPrioritiesDefault(SDFPriorities arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternPrioritiesDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasPrioritiesPrioritys(SDFPriorities arg) */

ATbool SDFhasPrioritiesPrioritys(SDFPriorities arg)
{
  if (SDFisPrioritiesDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFPriorityPrioritys SDFgetPrioritiesPrioritys(SDFPriorities arg) */

SDFPriorityPrioritys SDFgetPrioritiesPrioritys(SDFPriorities arg)
{
  if (SDFisPrioritiesDefault(arg)) {
    return (SDFPriorityPrioritys)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 2);
  }

  ATabort("Priorities has no Prioritys: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFPriorities SDFsetPrioritiesPrioritys(SDFPriorities arg, SDFPriorityPrioritys prioritys) */

SDFPriorities SDFsetPrioritiesPrioritys(SDFPriorities arg, SDFPriorityPrioritys prioritys)
{
  if (SDFisPrioritiesDefault(arg)) {
    return (SDFPriorities)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)prioritys, 2), 0), 2);
  }

  ATabort("Priorities has no Prioritys: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFPriorityPrioritys accessor implementations */

/*{{{  ATbool SDFisValidPriorityPrioritys(SDFPriorityPrioritys arg) */

ATbool SDFisValidPriorityPrioritys(SDFPriorityPrioritys arg)
{
  if (SDFisPriorityPrioritysEmpty(arg)) {
    return ATtrue;
  }
  else if (SDFisPriorityPrioritysSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisPriorityPrioritysMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisPriorityPrioritysEmpty(SDFPriorityPrioritys arg) */

ATbool SDFisPriorityPrioritysEmpty(SDFPriorityPrioritys arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternPriorityPrioritysEmpty);
}

/*}}}  */
/*{{{  ATbool SDFisPriorityPrioritysSingle(SDFPriorityPrioritys arg) */

ATbool SDFisPriorityPrioritysSingle(SDFPriorityPrioritys arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternPriorityPrioritysSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisPriorityPrioritysMany(SDFPriorityPrioritys arg) */

ATbool SDFisPriorityPrioritysMany(SDFPriorityPrioritys arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternPriorityPrioritysMany, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasPriorityPrioritysWsAfterFirst(SDFPriorityPrioritys arg) */

ATbool SDFhasPriorityPrioritysWsAfterFirst(SDFPriorityPrioritys arg)
{
  if (SDFisPriorityPrioritysMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetPriorityPrioritysWsAfterFirst(SDFPriorityPrioritys arg) */

SDFLayout SDFgetPriorityPrioritysWsAfterFirst(SDFPriorityPrioritys arg)
{
  if (SDFisPriorityPrioritysMany(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("PriorityPrioritys has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFPriorityPrioritys SDFsetPriorityPrioritysWsAfterFirst(SDFPriorityPrioritys arg, SDFLayout wsAfterFirst) */

SDFPriorityPrioritys SDFsetPriorityPrioritysWsAfterFirst(SDFPriorityPrioritys arg, SDFLayout wsAfterFirst)
{
  if (SDFisPriorityPrioritysMany(arg)) {
    return (SDFPriorityPrioritys)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("PriorityPrioritys has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasPriorityPrioritysWsAfterSep(SDFPriorityPrioritys arg) */

ATbool SDFhasPriorityPrioritysWsAfterSep(SDFPriorityPrioritys arg)
{
  if (SDFisPriorityPrioritysMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetPriorityPrioritysWsAfterSep(SDFPriorityPrioritys arg) */

SDFLayout SDFgetPriorityPrioritysWsAfterSep(SDFPriorityPrioritys arg)
{
  if (SDFisPriorityPrioritysMany(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), 0);
  }

  ATabort("PriorityPrioritys has no WsAfterSep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFPriorityPrioritys SDFsetPriorityPrioritysWsAfterSep(SDFPriorityPrioritys arg, SDFLayout wsAfterSep) */

SDFPriorityPrioritys SDFsetPriorityPrioritysWsAfterSep(SDFPriorityPrioritys arg, SDFLayout wsAfterSep)
{
  if (SDFisPriorityPrioritysMany(arg)) {
    return (SDFPriorityPrioritys)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), (ATerm)wsAfterSep, 0), 3);
  }

  ATabort("PriorityPrioritys has no WsAfterSep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasPriorityPrioritysTail(SDFPriorityPrioritys arg) */

ATbool SDFhasPriorityPrioritysTail(SDFPriorityPrioritys arg)
{
  if (SDFisPriorityPrioritysMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFPriorityPrioritys SDFgetPriorityPrioritysTail(SDFPriorityPrioritys arg) */

SDFPriorityPrioritys SDFgetPriorityPrioritysTail(SDFPriorityPrioritys arg)
{
  if (SDFisPriorityPrioritysMany(arg)) {
    return (SDFPriorityPrioritys)ATgetTail((ATermList)arg, 4);
  }

  ATabort("PriorityPrioritys has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFPriorityPrioritys SDFsetPriorityPrioritysTail(SDFPriorityPrioritys arg, SDFPriorityPrioritys tail) */

SDFPriorityPrioritys SDFsetPriorityPrioritysTail(SDFPriorityPrioritys arg, SDFPriorityPrioritys tail)
{
  if (SDFisPriorityPrioritysMany(arg)) {
    return (SDFPriorityPrioritys)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("PriorityPrioritys has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasPriorityPrioritysHead(SDFPriorityPrioritys arg) */

ATbool SDFhasPriorityPrioritysHead(SDFPriorityPrioritys arg)
{
  if (SDFisPriorityPrioritysSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisPriorityPrioritysMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFPriority SDFgetPriorityPrioritysHead(SDFPriorityPrioritys arg) */

SDFPriority SDFgetPriorityPrioritysHead(SDFPriorityPrioritys arg)
{
  if (SDFisPriorityPrioritysSingle(arg)) {
    return (SDFPriority)ATelementAt((ATermList)arg, 0);
  }
  else if (SDFisPriorityPrioritysMany(arg)) {
    return (SDFPriority)ATelementAt((ATermList)arg, 0);
  }

  ATabort("PriorityPrioritys has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFPriorityPrioritys SDFsetPriorityPrioritysHead(SDFPriorityPrioritys arg, SDFPriority head) */

SDFPriorityPrioritys SDFsetPriorityPrioritysHead(SDFPriorityPrioritys arg, SDFPriority head)
{
  if (SDFisPriorityPrioritysSingle(arg)) {
    return (SDFPriorityPrioritys)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDFisPriorityPrioritysMany(arg)) {
    return (SDFPriorityPrioritys)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("PriorityPrioritys has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasPriorityPrioritysSep(SDFPriorityPrioritys arg) */

ATbool SDFhasPriorityPrioritysSep(SDFPriorityPrioritys arg)
{
  if (SDFisPriorityPrioritysMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSeparator SDFgetPriorityPrioritysSep(SDFPriorityPrioritys arg) */

SDFSeparator SDFgetPriorityPrioritysSep(SDFPriorityPrioritys arg)
{
  if (SDFisPriorityPrioritysMany(arg)) {
    return (SDFSeparator)ATelementAt((ATermList)arg, 2);
  }

  ATabort("PriorityPrioritys has no Sep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFPriorityPrioritys SDFsetPriorityPrioritysSep(SDFPriorityPrioritys arg, SDFSeparator sep) */

SDFPriorityPrioritys SDFsetPriorityPrioritysSep(SDFPriorityPrioritys arg, SDFSeparator sep)
{
  if (SDFisPriorityPrioritysMany(arg)) {
    return (SDFPriorityPrioritys)ATreplace((ATermList)arg, (ATerm)sep, 2);
  }

  ATabort("PriorityPrioritys has no Sep: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFSort accessor implementations */

/*{{{  ATbool SDFisValidSort(SDFSort arg) */

ATbool SDFisValidSort(SDFSort arg)
{
  if (SDFisSortOneChar(arg)) {
    return ATtrue;
  }
  else if (SDFisSortMoreChars(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisSortOneChar(SDFSort arg) */

ATbool SDFisSortOneChar(SDFSort arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSortOneChar, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSortMoreChars(SDFSort arg) */

ATbool SDFisSortMoreChars(SDFSort arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSortMoreChars, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasSortLex(SDFSort arg) */

ATbool SDFhasSortLex(SDFSort arg)
{
  if (SDFisSortOneChar(arg)) {
    return ATtrue;
  }
  else if (SDFisSortMoreChars(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLexical SDFgetSortLex(SDFSort arg) */

SDFLexical SDFgetSortLex(SDFSort arg)
{
  if (SDFisSortOneChar(arg)) {
    return (SDFLexical)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (SDFisSortMoreChars(arg)) {
    return (SDFLexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("Sort has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSort SDFsetSortLex(SDFSort arg, SDFLexical lex) */

SDFSort SDFsetSortLex(SDFSort arg, SDFLexical lex)
{
  if (SDFisSortOneChar(arg)) {
    return (SDFSort)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }
  else if (SDFisSortMoreChars(arg)) {
    return (SDFSort)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("Sort has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFUQLiteral accessor implementations */

/*{{{  ATbool SDFisValidUQLiteral(SDFUQLiteral arg) */

ATbool SDFisValidUQLiteral(SDFUQLiteral arg)
{
  if (SDFisUQLiteralOneChar(arg)) {
    return ATtrue;
  }
  else if (SDFisUQLiteralMoreChars(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisUQLiteralOneChar(SDFUQLiteral arg) */

ATbool SDFisUQLiteralOneChar(SDFUQLiteral arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternUQLiteralOneChar, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisUQLiteralMoreChars(SDFUQLiteral arg) */

ATbool SDFisUQLiteralMoreChars(SDFUQLiteral arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternUQLiteralMoreChars, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasUQLiteralLex(SDFUQLiteral arg) */

ATbool SDFhasUQLiteralLex(SDFUQLiteral arg)
{
  if (SDFisUQLiteralOneChar(arg)) {
    return ATtrue;
  }
  else if (SDFisUQLiteralMoreChars(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLexical SDFgetUQLiteralLex(SDFUQLiteral arg) */

SDFLexical SDFgetUQLiteralLex(SDFUQLiteral arg)
{
  if (SDFisUQLiteralOneChar(arg)) {
    return (SDFLexical)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (SDFisUQLiteralMoreChars(arg)) {
    return (SDFLexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("UQLiteral has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFUQLiteral SDFsetUQLiteralLex(SDFUQLiteral arg, SDFLexical lex) */

SDFUQLiteral SDFsetUQLiteralLex(SDFUQLiteral arg, SDFLexical lex)
{
  if (SDFisUQLiteralOneChar(arg)) {
    return (SDFUQLiteral)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }
  else if (SDFisUQLiteralMoreChars(arg)) {
    return (SDFUQLiteral)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("UQLiteral has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFLiteral accessor implementations */

/*{{{  ATbool SDFisValidLiteral(SDFLiteral arg) */

ATbool SDFisValidLiteral(SDFLiteral arg)
{
  if (SDFisLiteralUqlit(arg)) {
    return ATtrue;
  }
  else if (SDFisLiteralQuoted(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisLiteralUqlit(SDFLiteral arg) */

ATbool SDFisLiteralUqlit(SDFLiteral arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternLiteralUqlit, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisLiteralQuoted(SDFLiteral arg) */

ATbool SDFisLiteralQuoted(SDFLiteral arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternLiteralQuoted, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasLiteralLex(SDFLiteral arg) */

ATbool SDFhasLiteralLex(SDFLiteral arg)
{
  if (SDFisLiteralQuoted(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLexical SDFgetLiteralLex(SDFLiteral arg) */

SDFLexical SDFgetLiteralLex(SDFLiteral arg)
{
  if (SDFisLiteralQuoted(arg)) {
    return (SDFLexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("Literal has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFLiteral SDFsetLiteralLex(SDFLiteral arg, SDFLexical lex) */

SDFLiteral SDFsetLiteralLex(SDFLiteral arg, SDFLexical lex)
{
  if (SDFisLiteralQuoted(arg)) {
    return (SDFLiteral)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("Literal has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasLiteralUQLiteral(SDFLiteral arg) */

ATbool SDFhasLiteralUQLiteral(SDFLiteral arg)
{
  if (SDFisLiteralUqlit(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFUQLiteral SDFgetLiteralUQLiteral(SDFLiteral arg) */

SDFUQLiteral SDFgetLiteralUQLiteral(SDFLiteral arg)
{
  if (SDFisLiteralUqlit(arg)) {
    return (SDFUQLiteral)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Literal has no UQLiteral: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFLiteral SDFsetLiteralUQLiteral(SDFLiteral arg, SDFUQLiteral uQLiteral) */

SDFLiteral SDFsetLiteralUQLiteral(SDFLiteral arg, SDFUQLiteral uQLiteral)
{
  if (SDFisLiteralUqlit(arg)) {
    return (SDFLiteral)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)uQLiteral, 0), 2);
  }

  ATabort("Literal has no UQLiteral: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFSymbolArguments accessor implementations */

/*{{{  ATbool SDFisValidSymbolArguments(SDFSymbolArguments arg) */

ATbool SDFisValidSymbolArguments(SDFSymbolArguments arg)
{
  if (SDFisSymbolArgumentsEmpty(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolArgumentsSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolArgumentsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisSymbolArgumentsEmpty(SDFSymbolArguments arg) */

ATbool SDFisSymbolArgumentsEmpty(SDFSymbolArguments arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolArgumentsEmpty);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolArgumentsSingle(SDFSymbolArguments arg) */

ATbool SDFisSymbolArgumentsSingle(SDFSymbolArguments arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolArgumentsSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolArgumentsMany(SDFSymbolArguments arg) */

ATbool SDFisSymbolArgumentsMany(SDFSymbolArguments arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolArgumentsMany, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolArgumentsWsAfterFirst(SDFSymbolArguments arg) */

ATbool SDFhasSymbolArgumentsWsAfterFirst(SDFSymbolArguments arg)
{
  if (SDFisSymbolArgumentsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolArgumentsWsAfterFirst(SDFSymbolArguments arg) */

SDFLayout SDFgetSymbolArgumentsWsAfterFirst(SDFSymbolArguments arg)
{
  if (SDFisSymbolArgumentsMany(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("SymbolArguments has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbolArguments SDFsetSymbolArgumentsWsAfterFirst(SDFSymbolArguments arg, SDFLayout wsAfterFirst) */

SDFSymbolArguments SDFsetSymbolArgumentsWsAfterFirst(SDFSymbolArguments arg, SDFLayout wsAfterFirst)
{
  if (SDFisSymbolArgumentsMany(arg)) {
    return (SDFSymbolArguments)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("SymbolArguments has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolArgumentsWsAfterSep(SDFSymbolArguments arg) */

ATbool SDFhasSymbolArgumentsWsAfterSep(SDFSymbolArguments arg)
{
  if (SDFisSymbolArgumentsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolArgumentsWsAfterSep(SDFSymbolArguments arg) */

SDFLayout SDFgetSymbolArgumentsWsAfterSep(SDFSymbolArguments arg)
{
  if (SDFisSymbolArgumentsMany(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), 0);
  }

  ATabort("SymbolArguments has no WsAfterSep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbolArguments SDFsetSymbolArgumentsWsAfterSep(SDFSymbolArguments arg, SDFLayout wsAfterSep) */

SDFSymbolArguments SDFsetSymbolArgumentsWsAfterSep(SDFSymbolArguments arg, SDFLayout wsAfterSep)
{
  if (SDFisSymbolArgumentsMany(arg)) {
    return (SDFSymbolArguments)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), (ATerm)wsAfterSep, 0), 3);
  }

  ATabort("SymbolArguments has no WsAfterSep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolArgumentsTail(SDFSymbolArguments arg) */

ATbool SDFhasSymbolArgumentsTail(SDFSymbolArguments arg)
{
  if (SDFisSymbolArgumentsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbolArguments SDFgetSymbolArgumentsTail(SDFSymbolArguments arg) */

SDFSymbolArguments SDFgetSymbolArgumentsTail(SDFSymbolArguments arg)
{
  if (SDFisSymbolArgumentsMany(arg)) {
    return (SDFSymbolArguments)ATgetTail((ATermList)arg, 4);
  }

  ATabort("SymbolArguments has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbolArguments SDFsetSymbolArgumentsTail(SDFSymbolArguments arg, SDFSymbolArguments tail) */

SDFSymbolArguments SDFsetSymbolArgumentsTail(SDFSymbolArguments arg, SDFSymbolArguments tail)
{
  if (SDFisSymbolArgumentsMany(arg)) {
    return (SDFSymbolArguments)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("SymbolArguments has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolArgumentsHead(SDFSymbolArguments arg) */

ATbool SDFhasSymbolArgumentsHead(SDFSymbolArguments arg)
{
  if (SDFisSymbolArgumentsSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolArgumentsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbol SDFgetSymbolArgumentsHead(SDFSymbolArguments arg) */

SDFSymbol SDFgetSymbolArgumentsHead(SDFSymbolArguments arg)
{
  if (SDFisSymbolArgumentsSingle(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)arg, 0);
  }
  else if (SDFisSymbolArgumentsMany(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)arg, 0);
  }

  ATabort("SymbolArguments has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbolArguments SDFsetSymbolArgumentsHead(SDFSymbolArguments arg, SDFSymbol head) */

SDFSymbolArguments SDFsetSymbolArgumentsHead(SDFSymbolArguments arg, SDFSymbol head)
{
  if (SDFisSymbolArgumentsSingle(arg)) {
    return (SDFSymbolArguments)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDFisSymbolArgumentsMany(arg)) {
    return (SDFSymbolArguments)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("SymbolArguments has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolArgumentsSep(SDFSymbolArguments arg) */

ATbool SDFhasSymbolArgumentsSep(SDFSymbolArguments arg)
{
  if (SDFisSymbolArgumentsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSeparator SDFgetSymbolArgumentsSep(SDFSymbolArguments arg) */

SDFSeparator SDFgetSymbolArgumentsSep(SDFSymbolArguments arg)
{
  if (SDFisSymbolArgumentsMany(arg)) {
    return (SDFSeparator)ATelementAt((ATermList)arg, 2);
  }

  ATabort("SymbolArguments has no Sep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbolArguments SDFsetSymbolArgumentsSep(SDFSymbolArguments arg, SDFSeparator sep) */

SDFSymbolArguments SDFsetSymbolArgumentsSep(SDFSymbolArguments arg, SDFSeparator sep)
{
  if (SDFisSymbolArgumentsMany(arg)) {
    return (SDFSymbolArguments)ATreplace((ATermList)arg, (ATerm)sep, 2);
  }

  ATabort("SymbolArguments has no Sep: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFLookahead accessor implementations */

/*{{{  ATbool SDFisValidLookahead(SDFLookahead arg) */

ATbool SDFisValidLookahead(SDFLookahead arg)
{
  if (SDFisLookaheadCharClass(arg)) {
    return ATtrue;
  }
  else if (SDFisLookaheadSeq(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisLookaheadCharClass(SDFLookahead arg) */

ATbool SDFisLookaheadCharClass(SDFLookahead arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternLookaheadCharClass, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisLookaheadSeq(SDFLookahead arg) */

ATbool SDFisLookaheadSeq(SDFLookahead arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternLookaheadSeq, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasLookaheadWsAfterPeriod(SDFLookahead arg) */

ATbool SDFhasLookaheadWsAfterPeriod(SDFLookahead arg)
{
  if (SDFisLookaheadSeq(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetLookaheadWsAfterPeriod(SDFLookahead arg) */

SDFLayout SDFgetLookaheadWsAfterPeriod(SDFLookahead arg)
{
  if (SDFisLookaheadSeq(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Lookahead has no WsAfterPeriod: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFLookahead SDFsetLookaheadWsAfterPeriod(SDFLookahead arg, SDFLayout wsAfterPeriod) */

SDFLookahead SDFsetLookaheadWsAfterPeriod(SDFLookahead arg, SDFLayout wsAfterPeriod)
{
  if (SDFisLookaheadSeq(arg)) {
    return (SDFLookahead)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterPeriod, 0), 3), 2);
  }

  ATabort("Lookahead has no WsAfterPeriod: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasLookaheadTail(SDFLookahead arg) */

ATbool SDFhasLookaheadTail(SDFLookahead arg)
{
  if (SDFisLookaheadSeq(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLookaheads SDFgetLookaheadTail(SDFLookahead arg) */

SDFLookaheads SDFgetLookaheadTail(SDFLookahead arg)
{
  if (SDFisLookaheadSeq(arg)) {
    return (SDFLookaheads)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Lookahead has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFLookahead SDFsetLookaheadTail(SDFLookahead arg, SDFLookaheads tail) */

SDFLookahead SDFsetLookaheadTail(SDFLookahead arg, SDFLookaheads tail)
{
  if (SDFisLookaheadSeq(arg)) {
    return (SDFLookahead)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)tail, 4), 2);
  }

  ATabort("Lookahead has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasLookaheadHead(SDFLookahead arg) */

ATbool SDFhasLookaheadHead(SDFLookahead arg)
{
  if (SDFisLookaheadSeq(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFCharClass SDFgetLookaheadHead(SDFLookahead arg) */

SDFCharClass SDFgetLookaheadHead(SDFLookahead arg)
{
  if (SDFisLookaheadSeq(arg)) {
    return (SDFCharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Lookahead has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFLookahead SDFsetLookaheadHead(SDFLookahead arg, SDFCharClass head) */

SDFLookahead SDFsetLookaheadHead(SDFLookahead arg, SDFCharClass head)
{
  if (SDFisLookaheadSeq(arg)) {
    return (SDFLookahead)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)head, 0), 2);
  }

  ATabort("Lookahead has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasLookaheadCharClass(SDFLookahead arg) */

ATbool SDFhasLookaheadCharClass(SDFLookahead arg)
{
  if (SDFisLookaheadCharClass(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFCharClass SDFgetLookaheadCharClass(SDFLookahead arg) */

SDFCharClass SDFgetLookaheadCharClass(SDFLookahead arg)
{
  if (SDFisLookaheadCharClass(arg)) {
    return (SDFCharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Lookahead has no CharClass: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFLookahead SDFsetLookaheadCharClass(SDFLookahead arg, SDFCharClass charClass) */

SDFLookahead SDFsetLookaheadCharClass(SDFLookahead arg, SDFCharClass charClass)
{
  if (SDFisLookaheadCharClass(arg)) {
    return (SDFLookahead)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)charClass, 0), 2);
  }

  ATabort("Lookahead has no CharClass: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasLookaheadWsAfterHead(SDFLookahead arg) */

ATbool SDFhasLookaheadWsAfterHead(SDFLookahead arg)
{
  if (SDFisLookaheadSeq(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetLookaheadWsAfterHead(SDFLookahead arg) */

SDFLayout SDFgetLookaheadWsAfterHead(SDFLookahead arg)
{
  if (SDFisLookaheadSeq(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Lookahead has no WsAfterHead: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFLookahead SDFsetLookaheadWsAfterHead(SDFLookahead arg, SDFLayout wsAfterHead) */

SDFLookahead SDFsetLookaheadWsAfterHead(SDFLookahead arg, SDFLayout wsAfterHead)
{
  if (SDFisLookaheadSeq(arg)) {
    return (SDFLookahead)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterHead, 0), 1), 2);
  }

  ATabort("Lookahead has no WsAfterHead: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFLookaheads accessor implementations */

/*{{{  ATbool SDFisValidLookaheads(SDFLookaheads arg) */

ATbool SDFisValidLookaheads(SDFLookaheads arg)
{
  if (SDFisLookaheadsSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisLookaheadsAlt(arg)) {
    return ATtrue;
  }
  else if (SDFisLookaheadsBracket(arg)) {
    return ATtrue;
  }
  else if (SDFisLookaheadsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisLookaheadsSingle(SDFLookaheads arg) */

ATbool SDFisLookaheadsSingle(SDFLookaheads arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternLookaheadsSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisLookaheadsAlt(SDFLookaheads arg) */

ATbool SDFisLookaheadsAlt(SDFLookaheads arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternLookaheadsAlt, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisLookaheadsBracket(SDFLookaheads arg) */

ATbool SDFisLookaheadsBracket(SDFLookaheads arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternLookaheadsBracket, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisLookaheadsList(SDFLookaheads arg) */

ATbool SDFisLookaheadsList(SDFLookaheads arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternLookaheadsList, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasLookaheadsRight(SDFLookaheads arg) */

ATbool SDFhasLookaheadsRight(SDFLookaheads arg)
{
  if (SDFisLookaheadsAlt(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLookaheads SDFgetLookaheadsRight(SDFLookaheads arg) */

SDFLookaheads SDFgetLookaheadsRight(SDFLookaheads arg)
{
  if (SDFisLookaheadsAlt(arg)) {
    return (SDFLookaheads)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Lookaheads has no Right: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFLookaheads SDFsetLookaheadsRight(SDFLookaheads arg, SDFLookaheads right) */

SDFLookaheads SDFsetLookaheadsRight(SDFLookaheads arg, SDFLookaheads right)
{
  if (SDFisLookaheadsAlt(arg)) {
    return (SDFLookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)right, 4), 2);
  }

  ATabort("Lookaheads has no Right: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasLookaheadsLookaheads(SDFLookaheads arg) */

ATbool SDFhasLookaheadsLookaheads(SDFLookaheads arg)
{
  if (SDFisLookaheadsBracket(arg)) {
    return ATtrue;
  }
  else if (SDFisLookaheadsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLookaheads SDFgetLookaheadsLookaheads(SDFLookaheads arg) */

SDFLookaheads SDFgetLookaheadsLookaheads(SDFLookaheads arg)
{
  if (SDFisLookaheadsBracket(arg)) {
    return (SDFLookaheads)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDFisLookaheadsList(arg)) {
    return (SDFLookaheads)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2), 2);
  }

  ATabort("Lookaheads has no Lookaheads: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFLookaheads SDFsetLookaheadsLookaheads(SDFLookaheads arg, SDFLookaheads lookaheads) */

SDFLookaheads SDFsetLookaheadsLookaheads(SDFLookaheads arg, SDFLookaheads lookaheads)
{
  if (SDFisLookaheadsBracket(arg)) {
    return (SDFLookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)lookaheads, 2), 2);
  }
  else if (SDFisLookaheadsList(arg)) {
    return (SDFLookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2), (ATerm)lookaheads, 2), 2), 2);
  }

  ATabort("Lookaheads has no Lookaheads: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasLookaheadsWsAfterLeft(SDFLookaheads arg) */

ATbool SDFhasLookaheadsWsAfterLeft(SDFLookaheads arg)
{
  if (SDFisLookaheadsAlt(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetLookaheadsWsAfterLeft(SDFLookaheads arg) */

SDFLayout SDFgetLookaheadsWsAfterLeft(SDFLookaheads arg)
{
  if (SDFisLookaheadsAlt(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Lookaheads has no WsAfterLeft: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFLookaheads SDFsetLookaheadsWsAfterLeft(SDFLookaheads arg, SDFLayout wsAfterLeft) */

SDFLookaheads SDFsetLookaheadsWsAfterLeft(SDFLookaheads arg, SDFLayout wsAfterLeft)
{
  if (SDFisLookaheadsAlt(arg)) {
    return (SDFLookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLeft, 0), 1), 2);
  }

  ATabort("Lookaheads has no WsAfterLeft: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasLookaheadsWsAfterParenOpen(SDFLookaheads arg) */

ATbool SDFhasLookaheadsWsAfterParenOpen(SDFLookaheads arg)
{
  if (SDFisLookaheadsBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetLookaheadsWsAfterParenOpen(SDFLookaheads arg) */

SDFLayout SDFgetLookaheadsWsAfterParenOpen(SDFLookaheads arg)
{
  if (SDFisLookaheadsBracket(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Lookaheads has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFLookaheads SDFsetLookaheadsWsAfterParenOpen(SDFLookaheads arg, SDFLayout wsAfterParenOpen) */

SDFLookaheads SDFsetLookaheadsWsAfterParenOpen(SDFLookaheads arg, SDFLayout wsAfterParenOpen)
{
  if (SDFisLookaheadsBracket(arg)) {
    return (SDFLookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterParenOpen, 0), 1), 2);
  }

  ATabort("Lookaheads has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasLookaheadsWsAfterBracketOpenBracketOpen(SDFLookaheads arg) */

ATbool SDFhasLookaheadsWsAfterBracketOpenBracketOpen(SDFLookaheads arg)
{
  if (SDFisLookaheadsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetLookaheadsWsAfterBracketOpenBracketOpen(SDFLookaheads arg) */

SDFLayout SDFgetLookaheadsWsAfterBracketOpenBracketOpen(SDFLookaheads arg)
{
  if (SDFisLookaheadsList(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Lookaheads has no WsAfterBracketOpenBracketOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFLookaheads SDFsetLookaheadsWsAfterBracketOpenBracketOpen(SDFLookaheads arg, SDFLayout wsAfterBracketOpenBracketOpen) */

SDFLookaheads SDFsetLookaheadsWsAfterBracketOpenBracketOpen(SDFLookaheads arg, SDFLayout wsAfterBracketOpenBracketOpen)
{
  if (SDFisLookaheadsList(arg)) {
    return (SDFLookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterBracketOpenBracketOpen, 0), 1), 2);
  }

  ATabort("Lookaheads has no WsAfterBracketOpenBracketOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasLookaheadsLookahead(SDFLookaheads arg) */

ATbool SDFhasLookaheadsLookahead(SDFLookaheads arg)
{
  if (SDFisLookaheadsSingle(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLookahead SDFgetLookaheadsLookahead(SDFLookaheads arg) */

SDFLookahead SDFgetLookaheadsLookahead(SDFLookaheads arg)
{
  if (SDFisLookaheadsSingle(arg)) {
    return (SDFLookahead)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Lookaheads has no Lookahead: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFLookaheads SDFsetLookaheadsLookahead(SDFLookaheads arg, SDFLookahead lookahead) */

SDFLookaheads SDFsetLookaheadsLookahead(SDFLookaheads arg, SDFLookahead lookahead)
{
  if (SDFisLookaheadsSingle(arg)) {
    return (SDFLookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)lookahead, 0), 2);
  }

  ATabort("Lookaheads has no Lookahead: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasLookaheadsWsAfterBar(SDFLookaheads arg) */

ATbool SDFhasLookaheadsWsAfterBar(SDFLookaheads arg)
{
  if (SDFisLookaheadsAlt(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetLookaheadsWsAfterBar(SDFLookaheads arg) */

SDFLayout SDFgetLookaheadsWsAfterBar(SDFLookaheads arg)
{
  if (SDFisLookaheadsAlt(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Lookaheads has no WsAfterBar: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFLookaheads SDFsetLookaheadsWsAfterBar(SDFLookaheads arg, SDFLayout wsAfterBar) */

SDFLookaheads SDFsetLookaheadsWsAfterBar(SDFLookaheads arg, SDFLayout wsAfterBar)
{
  if (SDFisLookaheadsAlt(arg)) {
    return (SDFLookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterBar, 0), 3), 2);
  }

  ATabort("Lookaheads has no WsAfterBar: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasLookaheadsLeft(SDFLookaheads arg) */

ATbool SDFhasLookaheadsLeft(SDFLookaheads arg)
{
  if (SDFisLookaheadsAlt(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLookaheads SDFgetLookaheadsLeft(SDFLookaheads arg) */

SDFLookaheads SDFgetLookaheadsLeft(SDFLookaheads arg)
{
  if (SDFisLookaheadsAlt(arg)) {
    return (SDFLookaheads)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Lookaheads has no Left: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFLookaheads SDFsetLookaheadsLeft(SDFLookaheads arg, SDFLookaheads left) */

SDFLookaheads SDFsetLookaheadsLeft(SDFLookaheads arg, SDFLookaheads left)
{
  if (SDFisLookaheadsAlt(arg)) {
    return (SDFLookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)left, 0), 2);
  }

  ATabort("Lookaheads has no Left: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasLookaheadsWsAfterLookaheads(SDFLookaheads arg) */

ATbool SDFhasLookaheadsWsAfterLookaheads(SDFLookaheads arg)
{
  if (SDFisLookaheadsBracket(arg)) {
    return ATtrue;
  }
  else if (SDFisLookaheadsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetLookaheadsWsAfterLookaheads(SDFLookaheads arg) */

SDFLayout SDFgetLookaheadsWsAfterLookaheads(SDFLookaheads arg)
{
  if (SDFisLookaheadsBracket(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDFisLookaheadsList(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Lookaheads has no WsAfterLookaheads: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFLookaheads SDFsetLookaheadsWsAfterLookaheads(SDFLookaheads arg, SDFLayout wsAfterLookaheads) */

SDFLookaheads SDFsetLookaheadsWsAfterLookaheads(SDFLookaheads arg, SDFLayout wsAfterLookaheads)
{
  if (SDFisLookaheadsBracket(arg)) {
    return (SDFLookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterLookaheads, 0), 3), 2);
  }
  else if (SDFisLookaheadsList(arg)) {
    return (SDFLookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterLookaheads, 0), 3), 2);
  }

  ATabort("Lookaheads has no WsAfterLookaheads: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFLookaheadLookaheads accessor implementations */

/*{{{  ATbool SDFisValidLookaheadLookaheads(SDFLookaheadLookaheads arg) */

ATbool SDFisValidLookaheadLookaheads(SDFLookaheadLookaheads arg)
{
  if (SDFisLookaheadLookaheadsEmpty(arg)) {
    return ATtrue;
  }
  else if (SDFisLookaheadLookaheadsSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisLookaheadLookaheadsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisLookaheadLookaheadsEmpty(SDFLookaheadLookaheads arg) */

ATbool SDFisLookaheadLookaheadsEmpty(SDFLookaheadLookaheads arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternLookaheadLookaheadsEmpty);
}

/*}}}  */
/*{{{  ATbool SDFisLookaheadLookaheadsSingle(SDFLookaheadLookaheads arg) */

ATbool SDFisLookaheadLookaheadsSingle(SDFLookaheadLookaheads arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternLookaheadLookaheadsSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisLookaheadLookaheadsMany(SDFLookaheadLookaheads arg) */

ATbool SDFisLookaheadLookaheadsMany(SDFLookaheadLookaheads arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternLookaheadLookaheadsMany, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasLookaheadLookaheadsWsAfterFirst(SDFLookaheadLookaheads arg) */

ATbool SDFhasLookaheadLookaheadsWsAfterFirst(SDFLookaheadLookaheads arg)
{
  if (SDFisLookaheadLookaheadsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetLookaheadLookaheadsWsAfterFirst(SDFLookaheadLookaheads arg) */

SDFLayout SDFgetLookaheadLookaheadsWsAfterFirst(SDFLookaheadLookaheads arg)
{
  if (SDFisLookaheadLookaheadsMany(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("LookaheadLookaheads has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFLookaheadLookaheads SDFsetLookaheadLookaheadsWsAfterFirst(SDFLookaheadLookaheads arg, SDFLayout wsAfterFirst) */

SDFLookaheadLookaheads SDFsetLookaheadLookaheadsWsAfterFirst(SDFLookaheadLookaheads arg, SDFLayout wsAfterFirst)
{
  if (SDFisLookaheadLookaheadsMany(arg)) {
    return (SDFLookaheadLookaheads)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("LookaheadLookaheads has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasLookaheadLookaheadsWsAfterSep(SDFLookaheadLookaheads arg) */

ATbool SDFhasLookaheadLookaheadsWsAfterSep(SDFLookaheadLookaheads arg)
{
  if (SDFisLookaheadLookaheadsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetLookaheadLookaheadsWsAfterSep(SDFLookaheadLookaheads arg) */

SDFLayout SDFgetLookaheadLookaheadsWsAfterSep(SDFLookaheadLookaheads arg)
{
  if (SDFisLookaheadLookaheadsMany(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), 0);
  }

  ATabort("LookaheadLookaheads has no WsAfterSep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFLookaheadLookaheads SDFsetLookaheadLookaheadsWsAfterSep(SDFLookaheadLookaheads arg, SDFLayout wsAfterSep) */

SDFLookaheadLookaheads SDFsetLookaheadLookaheadsWsAfterSep(SDFLookaheadLookaheads arg, SDFLayout wsAfterSep)
{
  if (SDFisLookaheadLookaheadsMany(arg)) {
    return (SDFLookaheadLookaheads)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), (ATerm)wsAfterSep, 0), 3);
  }

  ATabort("LookaheadLookaheads has no WsAfterSep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasLookaheadLookaheadsTail(SDFLookaheadLookaheads arg) */

ATbool SDFhasLookaheadLookaheadsTail(SDFLookaheadLookaheads arg)
{
  if (SDFisLookaheadLookaheadsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLookaheadLookaheads SDFgetLookaheadLookaheadsTail(SDFLookaheadLookaheads arg) */

SDFLookaheadLookaheads SDFgetLookaheadLookaheadsTail(SDFLookaheadLookaheads arg)
{
  if (SDFisLookaheadLookaheadsMany(arg)) {
    return (SDFLookaheadLookaheads)ATgetTail((ATermList)arg, 4);
  }

  ATabort("LookaheadLookaheads has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFLookaheadLookaheads SDFsetLookaheadLookaheadsTail(SDFLookaheadLookaheads arg, SDFLookaheadLookaheads tail) */

SDFLookaheadLookaheads SDFsetLookaheadLookaheadsTail(SDFLookaheadLookaheads arg, SDFLookaheadLookaheads tail)
{
  if (SDFisLookaheadLookaheadsMany(arg)) {
    return (SDFLookaheadLookaheads)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("LookaheadLookaheads has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasLookaheadLookaheadsHead(SDFLookaheadLookaheads arg) */

ATbool SDFhasLookaheadLookaheadsHead(SDFLookaheadLookaheads arg)
{
  if (SDFisLookaheadLookaheadsSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisLookaheadLookaheadsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLookahead SDFgetLookaheadLookaheadsHead(SDFLookaheadLookaheads arg) */

SDFLookahead SDFgetLookaheadLookaheadsHead(SDFLookaheadLookaheads arg)
{
  if (SDFisLookaheadLookaheadsSingle(arg)) {
    return (SDFLookahead)ATelementAt((ATermList)arg, 0);
  }
  else if (SDFisLookaheadLookaheadsMany(arg)) {
    return (SDFLookahead)ATelementAt((ATermList)arg, 0);
  }

  ATabort("LookaheadLookaheads has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFLookaheadLookaheads SDFsetLookaheadLookaheadsHead(SDFLookaheadLookaheads arg, SDFLookahead head) */

SDFLookaheadLookaheads SDFsetLookaheadLookaheadsHead(SDFLookaheadLookaheads arg, SDFLookahead head)
{
  if (SDFisLookaheadLookaheadsSingle(arg)) {
    return (SDFLookaheadLookaheads)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDFisLookaheadLookaheadsMany(arg)) {
    return (SDFLookaheadLookaheads)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("LookaheadLookaheads has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasLookaheadLookaheadsSep(SDFLookaheadLookaheads arg) */

ATbool SDFhasLookaheadLookaheadsSep(SDFLookaheadLookaheads arg)
{
  if (SDFisLookaheadLookaheadsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSeparator SDFgetLookaheadLookaheadsSep(SDFLookaheadLookaheads arg) */

SDFSeparator SDFgetLookaheadLookaheadsSep(SDFLookaheadLookaheads arg)
{
  if (SDFisLookaheadLookaheadsMany(arg)) {
    return (SDFSeparator)ATelementAt((ATermList)arg, 2);
  }

  ATabort("LookaheadLookaheads has no Sep: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFLookaheadLookaheads SDFsetLookaheadLookaheadsSep(SDFLookaheadLookaheads arg, SDFSeparator sep) */

SDFLookaheadLookaheads SDFsetLookaheadLookaheadsSep(SDFLookaheadLookaheads arg, SDFSeparator sep)
{
  if (SDFisLookaheadLookaheadsMany(arg)) {
    return (SDFLookaheadLookaheads)ATreplace((ATermList)arg, (ATerm)sep, 2);
  }

  ATabort("LookaheadLookaheads has no Sep: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFRestriction accessor implementations */

/*{{{  ATbool SDFisValidRestriction(SDFRestriction arg) */

ATbool SDFisValidRestriction(SDFRestriction arg)
{
  if (SDFisRestrictionFollow(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisRestrictionFollow(SDFRestriction arg) */

ATbool SDFisRestrictionFollow(SDFRestriction arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternRestrictionFollow, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasRestrictionLookaheads(SDFRestriction arg) */

ATbool SDFhasRestrictionLookaheads(SDFRestriction arg)
{
  if (SDFisRestrictionFollow(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLookaheads SDFgetRestrictionLookaheads(SDFRestriction arg) */

SDFLookaheads SDFgetRestrictionLookaheads(SDFRestriction arg)
{
  if (SDFisRestrictionFollow(arg)) {
    return (SDFLookaheads)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Restriction has no Lookaheads: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFRestriction SDFsetRestrictionLookaheads(SDFRestriction arg, SDFLookaheads lookaheads) */

SDFRestriction SDFsetRestrictionLookaheads(SDFRestriction arg, SDFLookaheads lookaheads)
{
  if (SDFisRestrictionFollow(arg)) {
    return (SDFRestriction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)lookaheads, 4), 2);
  }

  ATabort("Restriction has no Lookaheads: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasRestrictionWsAfterSymbols(SDFRestriction arg) */

ATbool SDFhasRestrictionWsAfterSymbols(SDFRestriction arg)
{
  if (SDFisRestrictionFollow(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetRestrictionWsAfterSymbols(SDFRestriction arg) */

SDFLayout SDFgetRestrictionWsAfterSymbols(SDFRestriction arg)
{
  if (SDFisRestrictionFollow(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Restriction has no WsAfterSymbols: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFRestriction SDFsetRestrictionWsAfterSymbols(SDFRestriction arg, SDFLayout wsAfterSymbols) */

SDFRestriction SDFsetRestrictionWsAfterSymbols(SDFRestriction arg, SDFLayout wsAfterSymbols)
{
  if (SDFisRestrictionFollow(arg)) {
    return (SDFRestriction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterSymbols, 0), 1), 2);
  }

  ATabort("Restriction has no WsAfterSymbols: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasRestrictionWsAfterSlash(SDFRestriction arg) */

ATbool SDFhasRestrictionWsAfterSlash(SDFRestriction arg)
{
  if (SDFisRestrictionFollow(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetRestrictionWsAfterSlash(SDFRestriction arg) */

SDFLayout SDFgetRestrictionWsAfterSlash(SDFRestriction arg)
{
  if (SDFisRestrictionFollow(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Restriction has no WsAfterSlash: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFRestriction SDFsetRestrictionWsAfterSlash(SDFRestriction arg, SDFLayout wsAfterSlash) */

SDFRestriction SDFsetRestrictionWsAfterSlash(SDFRestriction arg, SDFLayout wsAfterSlash)
{
  if (SDFisRestrictionFollow(arg)) {
    return (SDFRestriction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSlash, 0), 3), 2);
  }

  ATabort("Restriction has no WsAfterSlash: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasRestrictionSymbols(SDFRestriction arg) */

ATbool SDFhasRestrictionSymbols(SDFRestriction arg)
{
  if (SDFisRestrictionFollow(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbols SDFgetRestrictionSymbols(SDFRestriction arg) */

SDFSymbols SDFgetRestrictionSymbols(SDFRestriction arg)
{
  if (SDFisRestrictionFollow(arg)) {
    return (SDFSymbols)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Restriction has no Symbols: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFRestriction SDFsetRestrictionSymbols(SDFRestriction arg, SDFSymbols symbols) */

SDFRestriction SDFsetRestrictionSymbols(SDFRestriction arg, SDFSymbols symbols)
{
  if (SDFisRestrictionFollow(arg)) {
    return (SDFRestriction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbols, 0), 2);
  }

  ATabort("Restriction has no Symbols: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFRestrictions accessor implementations */

/*{{{  ATbool SDFisValidRestrictions(SDFRestrictions arg) */

ATbool SDFisValidRestrictions(SDFRestrictions arg)
{
  if (SDFisRestrictionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisRestrictionsDefault(SDFRestrictions arg) */

ATbool SDFisRestrictionsDefault(SDFRestrictions arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternRestrictionsDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasRestrictionsRestrictions(SDFRestrictions arg) */

ATbool SDFhasRestrictionsRestrictions(SDFRestrictions arg)
{
  if (SDFisRestrictionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFRestrictionRestrictions SDFgetRestrictionsRestrictions(SDFRestrictions arg) */

SDFRestrictionRestrictions SDFgetRestrictionsRestrictions(SDFRestrictions arg)
{
  if (SDFisRestrictionsDefault(arg)) {
    return (SDFRestrictionRestrictions)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 2);
  }

  ATabort("Restrictions has no Restrictions: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFRestrictions SDFsetRestrictionsRestrictions(SDFRestrictions arg, SDFRestrictionRestrictions restrictions) */

SDFRestrictions SDFsetRestrictionsRestrictions(SDFRestrictions arg, SDFRestrictionRestrictions restrictions)
{
  if (SDFisRestrictionsDefault(arg)) {
    return (SDFRestrictions)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)restrictions, 2), 0), 2);
  }

  ATabort("Restrictions has no Restrictions: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFRestrictionRestrictions accessor implementations */

/*{{{  ATbool SDFisValidRestrictionRestrictions(SDFRestrictionRestrictions arg) */

ATbool SDFisValidRestrictionRestrictions(SDFRestrictionRestrictions arg)
{
  if (SDFisRestrictionRestrictionsEmpty(arg)) {
    return ATtrue;
  }
  else if (SDFisRestrictionRestrictionsSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisRestrictionRestrictionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisRestrictionRestrictionsEmpty(SDFRestrictionRestrictions arg) */

ATbool SDFisRestrictionRestrictionsEmpty(SDFRestrictionRestrictions arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternRestrictionRestrictionsEmpty);
}

/*}}}  */
/*{{{  ATbool SDFisRestrictionRestrictionsSingle(SDFRestrictionRestrictions arg) */

ATbool SDFisRestrictionRestrictionsSingle(SDFRestrictionRestrictions arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternRestrictionRestrictionsSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisRestrictionRestrictionsMany(SDFRestrictionRestrictions arg) */

ATbool SDFisRestrictionRestrictionsMany(SDFRestrictionRestrictions arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternRestrictionRestrictionsMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasRestrictionRestrictionsWsAfterFirst(SDFRestrictionRestrictions arg) */

ATbool SDFhasRestrictionRestrictionsWsAfterFirst(SDFRestrictionRestrictions arg)
{
  if (SDFisRestrictionRestrictionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetRestrictionRestrictionsWsAfterFirst(SDFRestrictionRestrictions arg) */

SDFLayout SDFgetRestrictionRestrictionsWsAfterFirst(SDFRestrictionRestrictions arg)
{
  if (SDFisRestrictionRestrictionsMany(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("RestrictionRestrictions has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFRestrictionRestrictions SDFsetRestrictionRestrictionsWsAfterFirst(SDFRestrictionRestrictions arg, SDFLayout wsAfterFirst) */

SDFRestrictionRestrictions SDFsetRestrictionRestrictionsWsAfterFirst(SDFRestrictionRestrictions arg, SDFLayout wsAfterFirst)
{
  if (SDFisRestrictionRestrictionsMany(arg)) {
    return (SDFRestrictionRestrictions)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("RestrictionRestrictions has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasRestrictionRestrictionsTail(SDFRestrictionRestrictions arg) */

ATbool SDFhasRestrictionRestrictionsTail(SDFRestrictionRestrictions arg)
{
  if (SDFisRestrictionRestrictionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFRestrictionRestrictions SDFgetRestrictionRestrictionsTail(SDFRestrictionRestrictions arg) */

SDFRestrictionRestrictions SDFgetRestrictionRestrictionsTail(SDFRestrictionRestrictions arg)
{
  if (SDFisRestrictionRestrictionsMany(arg)) {
    return (SDFRestrictionRestrictions)ATgetTail((ATermList)arg, 2);
  }

  ATabort("RestrictionRestrictions has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFRestrictionRestrictions SDFsetRestrictionRestrictionsTail(SDFRestrictionRestrictions arg, SDFRestrictionRestrictions tail) */

SDFRestrictionRestrictions SDFsetRestrictionRestrictionsTail(SDFRestrictionRestrictions arg, SDFRestrictionRestrictions tail)
{
  if (SDFisRestrictionRestrictionsMany(arg)) {
    return (SDFRestrictionRestrictions)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("RestrictionRestrictions has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasRestrictionRestrictionsHead(SDFRestrictionRestrictions arg) */

ATbool SDFhasRestrictionRestrictionsHead(SDFRestrictionRestrictions arg)
{
  if (SDFisRestrictionRestrictionsSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisRestrictionRestrictionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFRestriction SDFgetRestrictionRestrictionsHead(SDFRestrictionRestrictions arg) */

SDFRestriction SDFgetRestrictionRestrictionsHead(SDFRestrictionRestrictions arg)
{
  if (SDFisRestrictionRestrictionsSingle(arg)) {
    return (SDFRestriction)ATelementAt((ATermList)arg, 0);
  }
  else if (SDFisRestrictionRestrictionsMany(arg)) {
    return (SDFRestriction)ATelementAt((ATermList)arg, 0);
  }

  ATabort("RestrictionRestrictions has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFRestrictionRestrictions SDFsetRestrictionRestrictionsHead(SDFRestrictionRestrictions arg, SDFRestriction head) */

SDFRestrictionRestrictions SDFsetRestrictionRestrictionsHead(SDFRestrictionRestrictions arg, SDFRestriction head)
{
  if (SDFisRestrictionRestrictionsSingle(arg)) {
    return (SDFRestrictionRestrictions)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDFisRestrictionRestrictionsMany(arg)) {
    return (SDFRestrictionRestrictions)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("RestrictionRestrictions has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFAlias accessor implementations */

/*{{{  ATbool SDFisValidAlias(SDFAlias arg) */

ATbool SDFisValidAlias(SDFAlias arg)
{
  if (SDFisAliasAlias(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisAliasAlias(SDFAlias arg) */

ATbool SDFisAliasAlias(SDFAlias arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAliasAlias, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasAliasWsAfterSymbol(SDFAlias arg) */

ATbool SDFhasAliasWsAfterSymbol(SDFAlias arg)
{
  if (SDFisAliasAlias(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetAliasWsAfterSymbol(SDFAlias arg) */

SDFLayout SDFgetAliasWsAfterSymbol(SDFAlias arg)
{
  if (SDFisAliasAlias(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Alias has no WsAfterSymbol: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAlias SDFsetAliasWsAfterSymbol(SDFAlias arg, SDFLayout wsAfterSymbol) */

SDFAlias SDFsetAliasWsAfterSymbol(SDFAlias arg, SDFLayout wsAfterSymbol)
{
  if (SDFisAliasAlias(arg)) {
    return (SDFAlias)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterSymbol, 0), 1), 2);
  }

  ATabort("Alias has no WsAfterSymbol: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasAliasAlias(SDFAlias arg) */

ATbool SDFhasAliasAlias(SDFAlias arg)
{
  if (SDFisAliasAlias(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbol SDFgetAliasAlias(SDFAlias arg) */

SDFSymbol SDFgetAliasAlias(SDFAlias arg)
{
  if (SDFisAliasAlias(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Alias has no Alias: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAlias SDFsetAliasAlias(SDFAlias arg, SDFSymbol alias) */

SDFAlias SDFsetAliasAlias(SDFAlias arg, SDFSymbol alias)
{
  if (SDFisAliasAlias(arg)) {
    return (SDFAlias)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)alias, 4), 2);
  }

  ATabort("Alias has no Alias: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasAliasSymbol(SDFAlias arg) */

ATbool SDFhasAliasSymbol(SDFAlias arg)
{
  if (SDFisAliasAlias(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbol SDFgetAliasSymbol(SDFAlias arg) */

SDFSymbol SDFgetAliasSymbol(SDFAlias arg)
{
  if (SDFisAliasAlias(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Alias has no Symbol: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAlias SDFsetAliasSymbol(SDFAlias arg, SDFSymbol symbol) */

SDFAlias SDFsetAliasSymbol(SDFAlias arg, SDFSymbol symbol)
{
  if (SDFisAliasAlias(arg)) {
    return (SDFAlias)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)symbol, 0), 2);
  }

  ATabort("Alias has no Symbol: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasAliasWsAfterArrow(SDFAlias arg) */

ATbool SDFhasAliasWsAfterArrow(SDFAlias arg)
{
  if (SDFisAliasAlias(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetAliasWsAfterArrow(SDFAlias arg) */

SDFLayout SDFgetAliasWsAfterArrow(SDFAlias arg)
{
  if (SDFisAliasAlias(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Alias has no WsAfterArrow: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAlias SDFsetAliasWsAfterArrow(SDFAlias arg, SDFLayout wsAfterArrow) */

SDFAlias SDFsetAliasWsAfterArrow(SDFAlias arg, SDFLayout wsAfterArrow)
{
  if (SDFisAliasAlias(arg)) {
    return (SDFAlias)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterArrow, 0), 3), 2);
  }

  ATabort("Alias has no WsAfterArrow: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFAliases accessor implementations */

/*{{{  ATbool SDFisValidAliases(SDFAliases arg) */

ATbool SDFisValidAliases(SDFAliases arg)
{
  if (SDFisAliasesDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisAliasesDefault(SDFAliases arg) */

ATbool SDFisAliasesDefault(SDFAliases arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAliasesDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasAliasesAliass(SDFAliases arg) */

ATbool SDFhasAliasesAliass(SDFAliases arg)
{
  if (SDFisAliasesDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFAliasAliass SDFgetAliasesAliass(SDFAliases arg) */

SDFAliasAliass SDFgetAliasesAliass(SDFAliases arg)
{
  if (SDFisAliasesDefault(arg)) {
    return (SDFAliasAliass)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 2);
  }

  ATabort("Aliases has no Aliass: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAliases SDFsetAliasesAliass(SDFAliases arg, SDFAliasAliass aliass) */

SDFAliases SDFsetAliasesAliass(SDFAliases arg, SDFAliasAliass aliass)
{
  if (SDFisAliasesDefault(arg)) {
    return (SDFAliases)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)aliass, 2), 0), 2);
  }

  ATabort("Aliases has no Aliass: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFAliasAliass accessor implementations */

/*{{{  ATbool SDFisValidAliasAliass(SDFAliasAliass arg) */

ATbool SDFisValidAliasAliass(SDFAliasAliass arg)
{
  if (SDFisAliasAliassEmpty(arg)) {
    return ATtrue;
  }
  else if (SDFisAliasAliassSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisAliasAliassMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisAliasAliassEmpty(SDFAliasAliass arg) */

ATbool SDFisAliasAliassEmpty(SDFAliasAliass arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAliasAliassEmpty);
}

/*}}}  */
/*{{{  ATbool SDFisAliasAliassSingle(SDFAliasAliass arg) */

ATbool SDFisAliasAliassSingle(SDFAliasAliass arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAliasAliassSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisAliasAliassMany(SDFAliasAliass arg) */

ATbool SDFisAliasAliassMany(SDFAliasAliass arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAliasAliassMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasAliasAliassWsAfterFirst(SDFAliasAliass arg) */

ATbool SDFhasAliasAliassWsAfterFirst(SDFAliasAliass arg)
{
  if (SDFisAliasAliassMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetAliasAliassWsAfterFirst(SDFAliasAliass arg) */

SDFLayout SDFgetAliasAliassWsAfterFirst(SDFAliasAliass arg)
{
  if (SDFisAliasAliassMany(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("AliasAliass has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAliasAliass SDFsetAliasAliassWsAfterFirst(SDFAliasAliass arg, SDFLayout wsAfterFirst) */

SDFAliasAliass SDFsetAliasAliassWsAfterFirst(SDFAliasAliass arg, SDFLayout wsAfterFirst)
{
  if (SDFisAliasAliassMany(arg)) {
    return (SDFAliasAliass)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("AliasAliass has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasAliasAliassTail(SDFAliasAliass arg) */

ATbool SDFhasAliasAliassTail(SDFAliasAliass arg)
{
  if (SDFisAliasAliassMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFAliasAliass SDFgetAliasAliassTail(SDFAliasAliass arg) */

SDFAliasAliass SDFgetAliasAliassTail(SDFAliasAliass arg)
{
  if (SDFisAliasAliassMany(arg)) {
    return (SDFAliasAliass)ATgetTail((ATermList)arg, 2);
  }

  ATabort("AliasAliass has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAliasAliass SDFsetAliasAliassTail(SDFAliasAliass arg, SDFAliasAliass tail) */

SDFAliasAliass SDFsetAliasAliassTail(SDFAliasAliass arg, SDFAliasAliass tail)
{
  if (SDFisAliasAliassMany(arg)) {
    return (SDFAliasAliass)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("AliasAliass has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasAliasAliassHead(SDFAliasAliass arg) */

ATbool SDFhasAliasAliassHead(SDFAliasAliass arg)
{
  if (SDFisAliasAliassSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisAliasAliassMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFAlias SDFgetAliasAliassHead(SDFAliasAliass arg) */

SDFAlias SDFgetAliasAliassHead(SDFAliasAliass arg)
{
  if (SDFisAliasAliassSingle(arg)) {
    return (SDFAlias)ATelementAt((ATermList)arg, 0);
  }
  else if (SDFisAliasAliassMany(arg)) {
    return (SDFAlias)ATelementAt((ATermList)arg, 0);
  }

  ATabort("AliasAliass has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAliasAliass SDFsetAliasAliassHead(SDFAliasAliass arg, SDFAlias head) */

SDFAliasAliass SDFsetAliasAliassHead(SDFAliasAliass arg, SDFAlias head)
{
  if (SDFisAliasAliassSingle(arg)) {
    return (SDFAliasAliass)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDFisAliasAliassMany(arg)) {
    return (SDFAliasAliass)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("AliasAliass has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFSymbols accessor implementations */

/*{{{  ATbool SDFisValidSymbols(SDFSymbols arg) */

ATbool SDFisValidSymbols(SDFSymbols arg)
{
  if (SDFisSymbolsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisSymbolsDefault(SDFSymbols arg) */

ATbool SDFisSymbolsDefault(SDFSymbols arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolsDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolsSymbols(SDFSymbols arg) */

ATbool SDFhasSymbolsSymbols(SDFSymbols arg)
{
  if (SDFisSymbolsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbolSymbols SDFgetSymbolsSymbols(SDFSymbols arg) */

SDFSymbolSymbols SDFgetSymbolsSymbols(SDFSymbols arg)
{
  if (SDFisSymbolsDefault(arg)) {
    return (SDFSymbolSymbols)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 2);
  }

  ATabort("Symbols has no Symbols: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbols SDFsetSymbolsSymbols(SDFSymbols arg, SDFSymbolSymbols symbols) */

SDFSymbols SDFsetSymbolsSymbols(SDFSymbols arg, SDFSymbolSymbols symbols)
{
  if (SDFisSymbolsDefault(arg)) {
    return (SDFSymbols)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)symbols, 2), 0), 2);
  }

  ATabort("Symbols has no Symbols: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFSymbolSymbols accessor implementations */

/*{{{  ATbool SDFisValidSymbolSymbols(SDFSymbolSymbols arg) */

ATbool SDFisValidSymbolSymbols(SDFSymbolSymbols arg)
{
  if (SDFisSymbolSymbolsEmpty(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolSymbolsSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolSymbolsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisSymbolSymbolsEmpty(SDFSymbolSymbols arg) */

ATbool SDFisSymbolSymbolsEmpty(SDFSymbolSymbols arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolSymbolsEmpty);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolSymbolsSingle(SDFSymbolSymbols arg) */

ATbool SDFisSymbolSymbolsSingle(SDFSymbolSymbols arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolSymbolsSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisSymbolSymbolsMany(SDFSymbolSymbols arg) */

ATbool SDFisSymbolSymbolsMany(SDFSymbolSymbols arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternSymbolSymbolsMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolSymbolsWsAfterFirst(SDFSymbolSymbols arg) */

ATbool SDFhasSymbolSymbolsWsAfterFirst(SDFSymbolSymbols arg)
{
  if (SDFisSymbolSymbolsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetSymbolSymbolsWsAfterFirst(SDFSymbolSymbols arg) */

SDFLayout SDFgetSymbolSymbolsWsAfterFirst(SDFSymbolSymbols arg)
{
  if (SDFisSymbolSymbolsMany(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("SymbolSymbols has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbolSymbols SDFsetSymbolSymbolsWsAfterFirst(SDFSymbolSymbols arg, SDFLayout wsAfterFirst) */

SDFSymbolSymbols SDFsetSymbolSymbolsWsAfterFirst(SDFSymbolSymbols arg, SDFLayout wsAfterFirst)
{
  if (SDFisSymbolSymbolsMany(arg)) {
    return (SDFSymbolSymbols)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("SymbolSymbols has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolSymbolsTail(SDFSymbolSymbols arg) */

ATbool SDFhasSymbolSymbolsTail(SDFSymbolSymbols arg)
{
  if (SDFisSymbolSymbolsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbolSymbols SDFgetSymbolSymbolsTail(SDFSymbolSymbols arg) */

SDFSymbolSymbols SDFgetSymbolSymbolsTail(SDFSymbolSymbols arg)
{
  if (SDFisSymbolSymbolsMany(arg)) {
    return (SDFSymbolSymbols)ATgetTail((ATermList)arg, 2);
  }

  ATabort("SymbolSymbols has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbolSymbols SDFsetSymbolSymbolsTail(SDFSymbolSymbols arg, SDFSymbolSymbols tail) */

SDFSymbolSymbols SDFsetSymbolSymbolsTail(SDFSymbolSymbols arg, SDFSymbolSymbols tail)
{
  if (SDFisSymbolSymbolsMany(arg)) {
    return (SDFSymbolSymbols)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("SymbolSymbols has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasSymbolSymbolsHead(SDFSymbolSymbols arg) */

ATbool SDFhasSymbolSymbolsHead(SDFSymbolSymbols arg)
{
  if (SDFisSymbolSymbolsSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisSymbolSymbolsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbol SDFgetSymbolSymbolsHead(SDFSymbolSymbols arg) */

SDFSymbol SDFgetSymbolSymbolsHead(SDFSymbolSymbols arg)
{
  if (SDFisSymbolSymbolsSingle(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)arg, 0);
  }
  else if (SDFisSymbolSymbolsMany(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)arg, 0);
  }

  ATabort("SymbolSymbols has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFSymbolSymbols SDFsetSymbolSymbolsHead(SDFSymbolSymbols arg, SDFSymbol head) */

SDFSymbolSymbols SDFsetSymbolSymbolsHead(SDFSymbolSymbols arg, SDFSymbol head)
{
  if (SDFisSymbolSymbolsSingle(arg)) {
    return (SDFSymbolSymbols)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDFisSymbolSymbolsMany(arg)) {
    return (SDFSymbolSymbols)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("SymbolSymbols has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFRenamings accessor implementations */

/*{{{  ATbool SDFisValidRenamings(SDFRenamings arg) */

ATbool SDFisValidRenamings(SDFRenamings arg)
{
  if (SDFisRenamingsRenamings(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisRenamingsRenamings(SDFRenamings arg) */

ATbool SDFisRenamingsRenamings(SDFRenamings arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternRenamingsRenamings, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasRenamingsRenamings(SDFRenamings arg) */

ATbool SDFhasRenamingsRenamings(SDFRenamings arg)
{
  if (SDFisRenamingsRenamings(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFRenamingRenamings SDFgetRenamingsRenamings(SDFRenamings arg) */

SDFRenamingRenamings SDFgetRenamingsRenamings(SDFRenamings arg)
{
  if (SDFisRenamingsRenamings(arg)) {
    return (SDFRenamingRenamings)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2), 2);
  }

  ATabort("Renamings has no Renamings: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFRenamings SDFsetRenamingsRenamings(SDFRenamings arg, SDFRenamingRenamings renamings) */

SDFRenamings SDFsetRenamingsRenamings(SDFRenamings arg, SDFRenamingRenamings renamings)
{
  if (SDFisRenamingsRenamings(arg)) {
    return (SDFRenamings)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2), (ATerm)renamings, 2), 2), 2);
  }

  ATabort("Renamings has no Renamings: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasRenamingsWsAfterRenamings(SDFRenamings arg) */

ATbool SDFhasRenamingsWsAfterRenamings(SDFRenamings arg)
{
  if (SDFisRenamingsRenamings(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetRenamingsWsAfterRenamings(SDFRenamings arg) */

SDFLayout SDFgetRenamingsWsAfterRenamings(SDFRenamings arg)
{
  if (SDFisRenamingsRenamings(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Renamings has no WsAfterRenamings: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFRenamings SDFsetRenamingsWsAfterRenamings(SDFRenamings arg, SDFLayout wsAfterRenamings) */

SDFRenamings SDFsetRenamingsWsAfterRenamings(SDFRenamings arg, SDFLayout wsAfterRenamings)
{
  if (SDFisRenamingsRenamings(arg)) {
    return (SDFRenamings)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterRenamings, 0), 3), 2);
  }

  ATabort("Renamings has no WsAfterRenamings: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasRenamingsWsAfterBracketOpen(SDFRenamings arg) */

ATbool SDFhasRenamingsWsAfterBracketOpen(SDFRenamings arg)
{
  if (SDFisRenamingsRenamings(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetRenamingsWsAfterBracketOpen(SDFRenamings arg) */

SDFLayout SDFgetRenamingsWsAfterBracketOpen(SDFRenamings arg)
{
  if (SDFisRenamingsRenamings(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Renamings has no WsAfterBracketOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFRenamings SDFsetRenamingsWsAfterBracketOpen(SDFRenamings arg, SDFLayout wsAfterBracketOpen) */

SDFRenamings SDFsetRenamingsWsAfterBracketOpen(SDFRenamings arg, SDFLayout wsAfterBracketOpen)
{
  if (SDFisRenamingsRenamings(arg)) {
    return (SDFRenamings)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterBracketOpen, 0), 1), 2);
  }

  ATabort("Renamings has no WsAfterBracketOpen: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFRenamingRenamings accessor implementations */

/*{{{  ATbool SDFisValidRenamingRenamings(SDFRenamingRenamings arg) */

ATbool SDFisValidRenamingRenamings(SDFRenamingRenamings arg)
{
  if (SDFisRenamingRenamingsEmpty(arg)) {
    return ATtrue;
  }
  else if (SDFisRenamingRenamingsSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisRenamingRenamingsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisRenamingRenamingsEmpty(SDFRenamingRenamings arg) */

ATbool SDFisRenamingRenamingsEmpty(SDFRenamingRenamings arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternRenamingRenamingsEmpty);
}

/*}}}  */
/*{{{  ATbool SDFisRenamingRenamingsSingle(SDFRenamingRenamings arg) */

ATbool SDFisRenamingRenamingsSingle(SDFRenamingRenamings arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternRenamingRenamingsSingle, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisRenamingRenamingsMany(SDFRenamingRenamings arg) */

ATbool SDFisRenamingRenamingsMany(SDFRenamingRenamings arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternRenamingRenamingsMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasRenamingRenamingsWsAfterFirst(SDFRenamingRenamings arg) */

ATbool SDFhasRenamingRenamingsWsAfterFirst(SDFRenamingRenamings arg)
{
  if (SDFisRenamingRenamingsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetRenamingRenamingsWsAfterFirst(SDFRenamingRenamings arg) */

SDFLayout SDFgetRenamingRenamingsWsAfterFirst(SDFRenamingRenamings arg)
{
  if (SDFisRenamingRenamingsMany(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("RenamingRenamings has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFRenamingRenamings SDFsetRenamingRenamingsWsAfterFirst(SDFRenamingRenamings arg, SDFLayout wsAfterFirst) */

SDFRenamingRenamings SDFsetRenamingRenamingsWsAfterFirst(SDFRenamingRenamings arg, SDFLayout wsAfterFirst)
{
  if (SDFisRenamingRenamingsMany(arg)) {
    return (SDFRenamingRenamings)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)wsAfterFirst, 0), 1);
  }

  ATabort("RenamingRenamings has no WsAfterFirst: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasRenamingRenamingsTail(SDFRenamingRenamings arg) */

ATbool SDFhasRenamingRenamingsTail(SDFRenamingRenamings arg)
{
  if (SDFisRenamingRenamingsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFRenamingRenamings SDFgetRenamingRenamingsTail(SDFRenamingRenamings arg) */

SDFRenamingRenamings SDFgetRenamingRenamingsTail(SDFRenamingRenamings arg)
{
  if (SDFisRenamingRenamingsMany(arg)) {
    return (SDFRenamingRenamings)ATgetTail((ATermList)arg, 2);
  }

  ATabort("RenamingRenamings has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFRenamingRenamings SDFsetRenamingRenamingsTail(SDFRenamingRenamings arg, SDFRenamingRenamings tail) */

SDFRenamingRenamings SDFsetRenamingRenamingsTail(SDFRenamingRenamings arg, SDFRenamingRenamings tail)
{
  if (SDFisRenamingRenamingsMany(arg)) {
    return (SDFRenamingRenamings)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("RenamingRenamings has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasRenamingRenamingsHead(SDFRenamingRenamings arg) */

ATbool SDFhasRenamingRenamingsHead(SDFRenamingRenamings arg)
{
  if (SDFisRenamingRenamingsSingle(arg)) {
    return ATtrue;
  }
  else if (SDFisRenamingRenamingsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFRenaming SDFgetRenamingRenamingsHead(SDFRenamingRenamings arg) */

SDFRenaming SDFgetRenamingRenamingsHead(SDFRenamingRenamings arg)
{
  if (SDFisRenamingRenamingsSingle(arg)) {
    return (SDFRenaming)ATelementAt((ATermList)arg, 0);
  }
  else if (SDFisRenamingRenamingsMany(arg)) {
    return (SDFRenaming)ATelementAt((ATermList)arg, 0);
  }

  ATabort("RenamingRenamings has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFRenamingRenamings SDFsetRenamingRenamingsHead(SDFRenamingRenamings arg, SDFRenaming head) */

SDFRenamingRenamings SDFsetRenamingRenamingsHead(SDFRenamingRenamings arg, SDFRenaming head)
{
  if (SDFisRenamingRenamingsSingle(arg)) {
    return (SDFRenamingRenamings)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDFisRenamingRenamingsMany(arg)) {
    return (SDFRenamingRenamings)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("RenamingRenamings has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFRenaming accessor implementations */

/*{{{  ATbool SDFisValidRenaming(SDFRenaming arg) */

ATbool SDFisValidRenaming(SDFRenaming arg)
{
  if (SDFisRenamingSymbol(arg)) {
    return ATtrue;
  }
  else if (SDFisRenamingProduction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisRenamingSymbol(SDFRenaming arg) */

ATbool SDFisRenamingSymbol(SDFRenaming arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternRenamingSymbol, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisRenamingProduction(SDFRenaming arg) */

ATbool SDFisRenamingProduction(SDFRenaming arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternRenamingProduction, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasRenamingFrom(SDFRenaming arg) */

ATbool SDFhasRenamingFrom(SDFRenaming arg)
{
  if (SDFisRenamingSymbol(arg)) {
    return ATtrue;
  }
  else if (SDFisRenamingProduction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbol SDFgetRenamingFrom(SDFRenaming arg) */

SDFSymbol SDFgetRenamingFrom(SDFRenaming arg)
{
  if (SDFisRenamingSymbol(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDFisRenamingProduction(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Renaming has no From: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFRenaming SDFsetRenamingFrom(SDFRenaming arg, SDFSymbol from) */

SDFRenaming SDFsetRenamingFrom(SDFRenaming arg, SDFSymbol from)
{
  if (SDFisRenamingSymbol(arg)) {
    return (SDFRenaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)from, 0), 2);
  }
  else if (SDFisRenamingProduction(arg)) {
    return (SDFRenaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)from, 0), 2);
  }

  ATabort("Renaming has no From: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasRenamingTo(SDFRenaming arg) */

ATbool SDFhasRenamingTo(SDFRenaming arg)
{
  if (SDFisRenamingSymbol(arg)) {
    return ATtrue;
  }
  else if (SDFisRenamingProduction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFSymbol SDFgetRenamingTo(SDFRenaming arg) */

SDFSymbol SDFgetRenamingTo(SDFRenaming arg)
{
  if (SDFisRenamingSymbol(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDFisRenamingProduction(arg)) {
    return (SDFSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Renaming has no To: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFRenaming SDFsetRenamingTo(SDFRenaming arg, SDFSymbol to) */

SDFRenaming SDFsetRenamingTo(SDFRenaming arg, SDFSymbol to)
{
  if (SDFisRenamingSymbol(arg)) {
    return (SDFRenaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)to, 4), 2);
  }
  else if (SDFisRenamingProduction(arg)) {
    return (SDFRenaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)to, 4), 2);
  }

  ATabort("Renaming has no To: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasRenamingWsAfterFrom(SDFRenaming arg) */

ATbool SDFhasRenamingWsAfterFrom(SDFRenaming arg)
{
  if (SDFisRenamingSymbol(arg)) {
    return ATtrue;
  }
  else if (SDFisRenamingProduction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetRenamingWsAfterFrom(SDFRenaming arg) */

SDFLayout SDFgetRenamingWsAfterFrom(SDFRenaming arg)
{
  if (SDFisRenamingSymbol(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisRenamingProduction(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Renaming has no WsAfterFrom: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFRenaming SDFsetRenamingWsAfterFrom(SDFRenaming arg, SDFLayout wsAfterFrom) */

SDFRenaming SDFsetRenamingWsAfterFrom(SDFRenaming arg, SDFLayout wsAfterFrom)
{
  if (SDFisRenamingSymbol(arg)) {
    return (SDFRenaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterFrom, 0), 1), 2);
  }
  else if (SDFisRenamingProduction(arg)) {
    return (SDFRenaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterFrom, 0), 1), 2);
  }

  ATabort("Renaming has no WsAfterFrom: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasRenamingWsAfterEqualsGreaterThan(SDFRenaming arg) */

ATbool SDFhasRenamingWsAfterEqualsGreaterThan(SDFRenaming arg)
{
  if (SDFisRenamingSymbol(arg)) {
    return ATtrue;
  }
  else if (SDFisRenamingProduction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetRenamingWsAfterEqualsGreaterThan(SDFRenaming arg) */

SDFLayout SDFgetRenamingWsAfterEqualsGreaterThan(SDFRenaming arg)
{
  if (SDFisRenamingSymbol(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDFisRenamingProduction(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Renaming has no WsAfterEqualsGreaterThan: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFRenaming SDFsetRenamingWsAfterEqualsGreaterThan(SDFRenaming arg, SDFLayout wsAfterEqualsGreaterThan) */

SDFRenaming SDFsetRenamingWsAfterEqualsGreaterThan(SDFRenaming arg, SDFLayout wsAfterEqualsGreaterThan)
{
  if (SDFisRenamingSymbol(arg)) {
    return (SDFRenaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterEqualsGreaterThan, 0), 3), 2);
  }
  else if (SDFisRenamingProduction(arg)) {
    return (SDFRenaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterEqualsGreaterThan, 0), 3), 2);
  }

  ATabort("Renaming has no WsAfterEqualsGreaterThan: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFNatCon accessor implementations */

/*{{{  ATbool SDFisValidNatCon(SDFNatCon arg) */

ATbool SDFisValidNatCon(SDFNatCon arg)
{
  if (SDFisNatConDigits(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisNatConDigits(SDFNatCon arg) */

ATbool SDFisNatConDigits(SDFNatCon arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternNatConDigits, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasNatConLex(SDFNatCon arg) */

ATbool SDFhasNatConLex(SDFNatCon arg)
{
  if (SDFisNatConDigits(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLexical SDFgetNatConLex(SDFNatCon arg) */

SDFLexical SDFgetNatConLex(SDFNatCon arg)
{
  if (SDFisNatConDigits(arg)) {
    return (SDFLexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("NatCon has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFNatCon SDFsetNatConLex(SDFNatCon arg, SDFLexical lex) */

SDFNatCon SDFsetNatConLex(SDFNatCon arg, SDFLexical lex)
{
  if (SDFisNatConDigits(arg)) {
    return (SDFNatCon)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("NatCon has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFIntCon accessor implementations */

/*{{{  ATbool SDFisValidIntCon(SDFIntCon arg) */

ATbool SDFisValidIntCon(SDFIntCon arg)
{
  if (SDFisIntConNatural(arg)) {
    return ATtrue;
  }
  else if (SDFisIntConPositive(arg)) {
    return ATtrue;
  }
  else if (SDFisIntConNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisIntConNatural(SDFIntCon arg) */

ATbool SDFisIntConNatural(SDFIntCon arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternIntConNatural, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisIntConPositive(SDFIntCon arg) */

ATbool SDFisIntConPositive(SDFIntCon arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternIntConPositive, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisIntConNegative(SDFIntCon arg) */

ATbool SDFisIntConNegative(SDFIntCon arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternIntConNegative, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasIntConWsAfterNeg(SDFIntCon arg) */

ATbool SDFhasIntConWsAfterNeg(SDFIntCon arg)
{
  if (SDFisIntConNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetIntConWsAfterNeg(SDFIntCon arg) */

SDFLayout SDFgetIntConWsAfterNeg(SDFIntCon arg)
{
  if (SDFisIntConNegative(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("IntCon has no WsAfterNeg: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFIntCon SDFsetIntConWsAfterNeg(SDFIntCon arg, SDFLayout wsAfterNeg) */

SDFIntCon SDFsetIntConWsAfterNeg(SDFIntCon arg, SDFLayout wsAfterNeg)
{
  if (SDFisIntConNegative(arg)) {
    return (SDFIntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterNeg, 0), 1), 2);
  }

  ATabort("IntCon has no WsAfterNeg: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasIntConWsAfterPos(SDFIntCon arg) */

ATbool SDFhasIntConWsAfterPos(SDFIntCon arg)
{
  if (SDFisIntConPositive(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetIntConWsAfterPos(SDFIntCon arg) */

SDFLayout SDFgetIntConWsAfterPos(SDFIntCon arg)
{
  if (SDFisIntConPositive(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("IntCon has no WsAfterPos: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFIntCon SDFsetIntConWsAfterPos(SDFIntCon arg, SDFLayout wsAfterPos) */

SDFIntCon SDFsetIntConWsAfterPos(SDFIntCon arg, SDFLayout wsAfterPos)
{
  if (SDFisIntConPositive(arg)) {
    return (SDFIntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterPos, 0), 1), 2);
  }

  ATabort("IntCon has no WsAfterPos: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasIntConNatCon(SDFIntCon arg) */

ATbool SDFhasIntConNatCon(SDFIntCon arg)
{
  if (SDFisIntConNatural(arg)) {
    return ATtrue;
  }
  else if (SDFisIntConPositive(arg)) {
    return ATtrue;
  }
  else if (SDFisIntConNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFNatCon SDFgetIntConNatCon(SDFIntCon arg) */

SDFNatCon SDFgetIntConNatCon(SDFIntCon arg)
{
  if (SDFisIntConNatural(arg)) {
    return (SDFNatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDFisIntConPositive(arg)) {
    return (SDFNatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDFisIntConNegative(arg)) {
    return (SDFNatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("IntCon has no NatCon: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFIntCon SDFsetIntConNatCon(SDFIntCon arg, SDFNatCon natCon) */

SDFIntCon SDFsetIntConNatCon(SDFIntCon arg, SDFNatCon natCon)
{
  if (SDFisIntConNatural(arg)) {
    return (SDFIntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)natCon, 0), 2);
  }
  else if (SDFisIntConPositive(arg)) {
    return (SDFIntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)natCon, 2), 2);
  }
  else if (SDFisIntConNegative(arg)) {
    return (SDFIntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)natCon, 2), 2);
  }

  ATabort("IntCon has no NatCon: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFCharRange accessor implementations */

/*{{{  ATbool SDFisValidCharRange(SDFCharRange arg) */

ATbool SDFisValidCharRange(SDFCharRange arg)
{
  if (SDFisCharRangeDefault(arg)) {
    return ATtrue;
  }
  else if (SDFisCharRangeRange(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisCharRangeDefault(SDFCharRange arg) */

ATbool SDFisCharRangeDefault(SDFCharRange arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternCharRangeDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisCharRangeRange(SDFCharRange arg) */

ATbool SDFisCharRangeRange(SDFCharRange arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternCharRangeRange, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasCharRangeWsAfter(SDFCharRange arg) */

ATbool SDFhasCharRangeWsAfter(SDFCharRange arg)
{
  if (SDFisCharRangeRange(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetCharRangeWsAfter(SDFCharRange arg) */

SDFLayout SDFgetCharRangeWsAfter(SDFCharRange arg)
{
  if (SDFisCharRangeRange(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("CharRange has no WsAfter: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharRange SDFsetCharRangeWsAfter(SDFCharRange arg, SDFLayout wsAfter) */

SDFCharRange SDFsetCharRangeWsAfter(SDFCharRange arg, SDFLayout wsAfter)
{
  if (SDFisCharRangeRange(arg)) {
    return (SDFCharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfter, 0), 3), 2);
  }

  ATabort("CharRange has no WsAfter: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasCharRangeEnd(SDFCharRange arg) */

ATbool SDFhasCharRangeEnd(SDFCharRange arg)
{
  if (SDFisCharRangeRange(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFCharacter SDFgetCharRangeEnd(SDFCharRange arg) */

SDFCharacter SDFgetCharRangeEnd(SDFCharRange arg)
{
  if (SDFisCharRangeRange(arg)) {
    return (SDFCharacter)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("CharRange has no End: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharRange SDFsetCharRangeEnd(SDFCharRange arg, SDFCharacter end) */

SDFCharRange SDFsetCharRangeEnd(SDFCharRange arg, SDFCharacter end)
{
  if (SDFisCharRangeRange(arg)) {
    return (SDFCharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)end, 4), 2);
  }

  ATabort("CharRange has no End: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasCharRangeCharacter(SDFCharRange arg) */

ATbool SDFhasCharRangeCharacter(SDFCharRange arg)
{
  if (SDFisCharRangeDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFCharacter SDFgetCharRangeCharacter(SDFCharRange arg) */

SDFCharacter SDFgetCharRangeCharacter(SDFCharRange arg)
{
  if (SDFisCharRangeDefault(arg)) {
    return (SDFCharacter)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("CharRange has no Character: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharRange SDFsetCharRangeCharacter(SDFCharRange arg, SDFCharacter character) */

SDFCharRange SDFsetCharRangeCharacter(SDFCharRange arg, SDFCharacter character)
{
  if (SDFisCharRangeDefault(arg)) {
    return (SDFCharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)character, 0), 2);
  }

  ATabort("CharRange has no Character: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasCharRangeStart(SDFCharRange arg) */

ATbool SDFhasCharRangeStart(SDFCharRange arg)
{
  if (SDFisCharRangeRange(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFCharacter SDFgetCharRangeStart(SDFCharRange arg) */

SDFCharacter SDFgetCharRangeStart(SDFCharRange arg)
{
  if (SDFisCharRangeRange(arg)) {
    return (SDFCharacter)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("CharRange has no Start: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharRange SDFsetCharRangeStart(SDFCharRange arg, SDFCharacter start) */

SDFCharRange SDFsetCharRangeStart(SDFCharRange arg, SDFCharacter start)
{
  if (SDFisCharRangeRange(arg)) {
    return (SDFCharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)start, 0), 2);
  }

  ATabort("CharRange has no Start: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasCharRangeWsAfterStart(SDFCharRange arg) */

ATbool SDFhasCharRangeWsAfterStart(SDFCharRange arg)
{
  if (SDFisCharRangeRange(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetCharRangeWsAfterStart(SDFCharRange arg) */

SDFLayout SDFgetCharRangeWsAfterStart(SDFCharRange arg)
{
  if (SDFisCharRangeRange(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("CharRange has no WsAfterStart: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharRange SDFsetCharRangeWsAfterStart(SDFCharRange arg, SDFLayout wsAfterStart) */

SDFCharRange SDFsetCharRangeWsAfterStart(SDFCharRange arg, SDFLayout wsAfterStart)
{
  if (SDFisCharRangeRange(arg)) {
    return (SDFCharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterStart, 0), 1), 2);
  }

  ATabort("CharRange has no WsAfterStart: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFCharRanges accessor implementations */

/*{{{  ATbool SDFisValidCharRanges(SDFCharRanges arg) */

ATbool SDFisValidCharRanges(SDFCharRanges arg)
{
  if (SDFisCharRangesDefault(arg)) {
    return ATtrue;
  }
  else if (SDFisCharRangesConc(arg)) {
    return ATtrue;
  }
  else if (SDFisCharRangesBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisCharRangesDefault(SDFCharRanges arg) */

ATbool SDFisCharRangesDefault(SDFCharRanges arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternCharRangesDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisCharRangesConc(SDFCharRanges arg) */

ATbool SDFisCharRangesConc(SDFCharRanges arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternCharRangesConc, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisCharRangesBracket(SDFCharRanges arg) */

ATbool SDFisCharRangesBracket(SDFCharRanges arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternCharRangesBracket, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasCharRangesRight(SDFCharRanges arg) */

ATbool SDFhasCharRangesRight(SDFCharRanges arg)
{
  if (SDFisCharRangesConc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFCharRanges SDFgetCharRangesRight(SDFCharRanges arg) */

SDFCharRanges SDFgetCharRangesRight(SDFCharRanges arg)
{
  if (SDFisCharRangesConc(arg)) {
    return (SDFCharRanges)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("CharRanges has no Right: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharRanges SDFsetCharRangesRight(SDFCharRanges arg, SDFCharRanges right) */

SDFCharRanges SDFsetCharRangesRight(SDFCharRanges arg, SDFCharRanges right)
{
  if (SDFisCharRangesConc(arg)) {
    return (SDFCharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)right, 2), 2);
  }

  ATabort("CharRanges has no Right: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasCharRangesWsAfterLeft(SDFCharRanges arg) */

ATbool SDFhasCharRangesWsAfterLeft(SDFCharRanges arg)
{
  if (SDFisCharRangesConc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetCharRangesWsAfterLeft(SDFCharRanges arg) */

SDFLayout SDFgetCharRangesWsAfterLeft(SDFCharRanges arg)
{
  if (SDFisCharRangesConc(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("CharRanges has no WsAfterLeft: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharRanges SDFsetCharRangesWsAfterLeft(SDFCharRanges arg, SDFLayout wsAfterLeft) */

SDFCharRanges SDFsetCharRangesWsAfterLeft(SDFCharRanges arg, SDFLayout wsAfterLeft)
{
  if (SDFisCharRangesConc(arg)) {
    return (SDFCharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLeft, 0), 1), 2);
  }

  ATabort("CharRanges has no WsAfterLeft: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasCharRangesWsAfterParenOpen(SDFCharRanges arg) */

ATbool SDFhasCharRangesWsAfterParenOpen(SDFCharRanges arg)
{
  if (SDFisCharRangesBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetCharRangesWsAfterParenOpen(SDFCharRanges arg) */

SDFLayout SDFgetCharRangesWsAfterParenOpen(SDFCharRanges arg)
{
  if (SDFisCharRangesBracket(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("CharRanges has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharRanges SDFsetCharRangesWsAfterParenOpen(SDFCharRanges arg, SDFLayout wsAfterParenOpen) */

SDFCharRanges SDFsetCharRangesWsAfterParenOpen(SDFCharRanges arg, SDFLayout wsAfterParenOpen)
{
  if (SDFisCharRangesBracket(arg)) {
    return (SDFCharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterParenOpen, 0), 1), 2);
  }

  ATabort("CharRanges has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasCharRangesWsAfterCharRanges(SDFCharRanges arg) */

ATbool SDFhasCharRangesWsAfterCharRanges(SDFCharRanges arg)
{
  if (SDFisCharRangesBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetCharRangesWsAfterCharRanges(SDFCharRanges arg) */

SDFLayout SDFgetCharRangesWsAfterCharRanges(SDFCharRanges arg)
{
  if (SDFisCharRangesBracket(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("CharRanges has no WsAfterCharRanges: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharRanges SDFsetCharRangesWsAfterCharRanges(SDFCharRanges arg, SDFLayout wsAfterCharRanges) */

SDFCharRanges SDFsetCharRangesWsAfterCharRanges(SDFCharRanges arg, SDFLayout wsAfterCharRanges)
{
  if (SDFisCharRangesBracket(arg)) {
    return (SDFCharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterCharRanges, 0), 3), 2);
  }

  ATabort("CharRanges has no WsAfterCharRanges: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasCharRangesCharRanges(SDFCharRanges arg) */

ATbool SDFhasCharRangesCharRanges(SDFCharRanges arg)
{
  if (SDFisCharRangesBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFCharRanges SDFgetCharRangesCharRanges(SDFCharRanges arg) */

SDFCharRanges SDFgetCharRangesCharRanges(SDFCharRanges arg)
{
  if (SDFisCharRangesBracket(arg)) {
    return (SDFCharRanges)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("CharRanges has no CharRanges: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharRanges SDFsetCharRangesCharRanges(SDFCharRanges arg, SDFCharRanges charRanges) */

SDFCharRanges SDFsetCharRangesCharRanges(SDFCharRanges arg, SDFCharRanges charRanges)
{
  if (SDFisCharRangesBracket(arg)) {
    return (SDFCharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)charRanges, 2), 2);
  }

  ATabort("CharRanges has no CharRanges: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasCharRangesCharRange(SDFCharRanges arg) */

ATbool SDFhasCharRangesCharRange(SDFCharRanges arg)
{
  if (SDFisCharRangesDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFCharRange SDFgetCharRangesCharRange(SDFCharRanges arg) */

SDFCharRange SDFgetCharRangesCharRange(SDFCharRanges arg)
{
  if (SDFisCharRangesDefault(arg)) {
    return (SDFCharRange)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("CharRanges has no CharRange: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharRanges SDFsetCharRangesCharRange(SDFCharRanges arg, SDFCharRange charRange) */

SDFCharRanges SDFsetCharRangesCharRange(SDFCharRanges arg, SDFCharRange charRange)
{
  if (SDFisCharRangesDefault(arg)) {
    return (SDFCharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)charRange, 0), 2);
  }

  ATabort("CharRanges has no CharRange: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasCharRangesLeft(SDFCharRanges arg) */

ATbool SDFhasCharRangesLeft(SDFCharRanges arg)
{
  if (SDFisCharRangesConc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFCharRanges SDFgetCharRangesLeft(SDFCharRanges arg) */

SDFCharRanges SDFgetCharRangesLeft(SDFCharRanges arg)
{
  if (SDFisCharRangesConc(arg)) {
    return (SDFCharRanges)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("CharRanges has no Left: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharRanges SDFsetCharRangesLeft(SDFCharRanges arg, SDFCharRanges left) */

SDFCharRanges SDFsetCharRangesLeft(SDFCharRanges arg, SDFCharRanges left)
{
  if (SDFisCharRangesConc(arg)) {
    return (SDFCharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)left, 0), 2);
  }

  ATabort("CharRanges has no Left: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFOptCharRanges accessor implementations */

/*{{{  ATbool SDFisValidOptCharRanges(SDFOptCharRanges arg) */

ATbool SDFisValidOptCharRanges(SDFOptCharRanges arg)
{
  if (SDFisOptCharRangesAbsent(arg)) {
    return ATtrue;
  }
  else if (SDFisOptCharRangesPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisOptCharRangesAbsent(SDFOptCharRanges arg) */

ATbool SDFisOptCharRangesAbsent(SDFOptCharRanges arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternOptCharRangesAbsent);
}

/*}}}  */
/*{{{  ATbool SDFisOptCharRangesPresent(SDFOptCharRanges arg) */

ATbool SDFisOptCharRangesPresent(SDFOptCharRanges arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternOptCharRangesPresent, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasOptCharRangesCharRanges(SDFOptCharRanges arg) */

ATbool SDFhasOptCharRangesCharRanges(SDFOptCharRanges arg)
{
  if (SDFisOptCharRangesPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFCharRanges SDFgetOptCharRangesCharRanges(SDFOptCharRanges arg) */

SDFCharRanges SDFgetOptCharRangesCharRanges(SDFOptCharRanges arg)
{
  if (SDFisOptCharRangesPresent(arg)) {
    return (SDFCharRanges)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("OptCharRanges has no CharRanges: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFOptCharRanges SDFsetOptCharRangesCharRanges(SDFOptCharRanges arg, SDFCharRanges charRanges) */

SDFOptCharRanges SDFsetOptCharRangesCharRanges(SDFOptCharRanges arg, SDFCharRanges charRanges)
{
  if (SDFisOptCharRangesPresent(arg)) {
    return (SDFOptCharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)charRanges, 0), 2);
  }

  ATabort("OptCharRanges has no CharRanges: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFCharClass accessor implementations */

/*{{{  ATbool SDFisValidCharClass(SDFCharClass arg) */

ATbool SDFisValidCharClass(SDFCharClass arg)
{
  if (SDFisCharClassSimpleCharclass(arg)) {
    return ATtrue;
  }
  else if (SDFisCharClassComp(arg)) {
    return ATtrue;
  }
  else if (SDFisCharClassDiff(arg)) {
    return ATtrue;
  }
  else if (SDFisCharClassIsect(arg)) {
    return ATtrue;
  }
  else if (SDFisCharClassUnion(arg)) {
    return ATtrue;
  }
  else if (SDFisCharClassBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisCharClassSimpleCharclass(SDFCharClass arg) */

ATbool SDFisCharClassSimpleCharclass(SDFCharClass arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternCharClassSimpleCharclass, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisCharClassComp(SDFCharClass arg) */

ATbool SDFisCharClassComp(SDFCharClass arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternCharClassComp, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisCharClassDiff(SDFCharClass arg) */

ATbool SDFisCharClassDiff(SDFCharClass arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternCharClassDiff, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisCharClassIsect(SDFCharClass arg) */

ATbool SDFisCharClassIsect(SDFCharClass arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternCharClassIsect, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisCharClassUnion(SDFCharClass arg) */

ATbool SDFisCharClassUnion(SDFCharClass arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternCharClassUnion, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisCharClassBracket(SDFCharClass arg) */

ATbool SDFisCharClassBracket(SDFCharClass arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternCharClassBracket, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasCharClassRight(SDFCharClass arg) */

ATbool SDFhasCharClassRight(SDFCharClass arg)
{
  if (SDFisCharClassDiff(arg)) {
    return ATtrue;
  }
  else if (SDFisCharClassIsect(arg)) {
    return ATtrue;
  }
  else if (SDFisCharClassUnion(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFCharClass SDFgetCharClassRight(SDFCharClass arg) */

SDFCharClass SDFgetCharClassRight(SDFCharClass arg)
{
  if (SDFisCharClassDiff(arg)) {
    return (SDFCharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDFisCharClassIsect(arg)) {
    return (SDFCharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDFisCharClassUnion(arg)) {
    return (SDFCharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("CharClass has no Right: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharClass SDFsetCharClassRight(SDFCharClass arg, SDFCharClass right) */

SDFCharClass SDFsetCharClassRight(SDFCharClass arg, SDFCharClass right)
{
  if (SDFisCharClassDiff(arg)) {
    return (SDFCharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)right, 4), 2);
  }
  else if (SDFisCharClassIsect(arg)) {
    return (SDFCharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)right, 4), 2);
  }
  else if (SDFisCharClassUnion(arg)) {
    return (SDFCharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)right, 4), 2);
  }

  ATabort("CharClass has no Right: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasCharClassWsAfterSlash(SDFCharClass arg) */

ATbool SDFhasCharClassWsAfterSlash(SDFCharClass arg)
{
  if (SDFisCharClassDiff(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetCharClassWsAfterSlash(SDFCharClass arg) */

SDFLayout SDFgetCharClassWsAfterSlash(SDFCharClass arg)
{
  if (SDFisCharClassDiff(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("CharClass has no WsAfterSlash: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharClass SDFsetCharClassWsAfterSlash(SDFCharClass arg, SDFLayout wsAfterSlash) */

SDFCharClass SDFsetCharClassWsAfterSlash(SDFCharClass arg, SDFLayout wsAfterSlash)
{
  if (SDFisCharClassDiff(arg)) {
    return (SDFCharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSlash, 0), 3), 2);
  }

  ATabort("CharClass has no WsAfterSlash: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasCharClassOptCharRanges(SDFCharClass arg) */

ATbool SDFhasCharClassOptCharRanges(SDFCharClass arg)
{
  if (SDFisCharClassSimpleCharclass(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFOptCharRanges SDFgetCharClassOptCharRanges(SDFCharClass arg) */

SDFOptCharRanges SDFgetCharClassOptCharRanges(SDFCharClass arg)
{
  if (SDFisCharClassSimpleCharclass(arg)) {
    return (SDFOptCharRanges)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("CharClass has no OptCharRanges: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharClass SDFsetCharClassOptCharRanges(SDFCharClass arg, SDFOptCharRanges optCharRanges) */

SDFCharClass SDFsetCharClassOptCharRanges(SDFCharClass arg, SDFOptCharRanges optCharRanges)
{
  if (SDFisCharClassSimpleCharclass(arg)) {
    return (SDFCharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)optCharRanges, 2), 2);
  }

  ATabort("CharClass has no OptCharRanges: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasCharClassWsAfterLeft(SDFCharClass arg) */

ATbool SDFhasCharClassWsAfterLeft(SDFCharClass arg)
{
  if (SDFisCharClassDiff(arg)) {
    return ATtrue;
  }
  else if (SDFisCharClassIsect(arg)) {
    return ATtrue;
  }
  else if (SDFisCharClassUnion(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetCharClassWsAfterLeft(SDFCharClass arg) */

SDFLayout SDFgetCharClassWsAfterLeft(SDFCharClass arg)
{
  if (SDFisCharClassDiff(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisCharClassIsect(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisCharClassUnion(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("CharClass has no WsAfterLeft: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharClass SDFsetCharClassWsAfterLeft(SDFCharClass arg, SDFLayout wsAfterLeft) */

SDFCharClass SDFsetCharClassWsAfterLeft(SDFCharClass arg, SDFLayout wsAfterLeft)
{
  if (SDFisCharClassDiff(arg)) {
    return (SDFCharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLeft, 0), 1), 2);
  }
  else if (SDFisCharClassIsect(arg)) {
    return (SDFCharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLeft, 0), 1), 2);
  }
  else if (SDFisCharClassUnion(arg)) {
    return (SDFCharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterLeft, 0), 1), 2);
  }

  ATabort("CharClass has no WsAfterLeft: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasCharClassWsAfterParenOpen(SDFCharClass arg) */

ATbool SDFhasCharClassWsAfterParenOpen(SDFCharClass arg)
{
  if (SDFisCharClassBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetCharClassWsAfterParenOpen(SDFCharClass arg) */

SDFLayout SDFgetCharClassWsAfterParenOpen(SDFCharClass arg)
{
  if (SDFisCharClassBracket(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("CharClass has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharClass SDFsetCharClassWsAfterParenOpen(SDFCharClass arg, SDFLayout wsAfterParenOpen) */

SDFCharClass SDFsetCharClassWsAfterParenOpen(SDFCharClass arg, SDFLayout wsAfterParenOpen)
{
  if (SDFisCharClassBracket(arg)) {
    return (SDFCharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterParenOpen, 0), 1), 2);
  }

  ATabort("CharClass has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasCharClassWsAfterTilde(SDFCharClass arg) */

ATbool SDFhasCharClassWsAfterTilde(SDFCharClass arg)
{
  if (SDFisCharClassComp(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetCharClassWsAfterTilde(SDFCharClass arg) */

SDFLayout SDFgetCharClassWsAfterTilde(SDFCharClass arg)
{
  if (SDFisCharClassComp(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("CharClass has no WsAfterTilde: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharClass SDFsetCharClassWsAfterTilde(SDFCharClass arg, SDFLayout wsAfterTilde) */

SDFCharClass SDFsetCharClassWsAfterTilde(SDFCharClass arg, SDFLayout wsAfterTilde)
{
  if (SDFisCharClassComp(arg)) {
    return (SDFCharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterTilde, 0), 1), 2);
  }

  ATabort("CharClass has no WsAfterTilde: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasCharClassWsAfterBackslashSlash(SDFCharClass arg) */

ATbool SDFhasCharClassWsAfterBackslashSlash(SDFCharClass arg)
{
  if (SDFisCharClassUnion(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetCharClassWsAfterBackslashSlash(SDFCharClass arg) */

SDFLayout SDFgetCharClassWsAfterBackslashSlash(SDFCharClass arg)
{
  if (SDFisCharClassUnion(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("CharClass has no WsAfterBackslashSlash: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharClass SDFsetCharClassWsAfterBackslashSlash(SDFCharClass arg, SDFLayout wsAfterBackslashSlash) */

SDFCharClass SDFsetCharClassWsAfterBackslashSlash(SDFCharClass arg, SDFLayout wsAfterBackslashSlash)
{
  if (SDFisCharClassUnion(arg)) {
    return (SDFCharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterBackslashSlash, 0), 3), 2);
  }

  ATabort("CharClass has no WsAfterBackslashSlash: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasCharClassWsAfterOptCharRanges(SDFCharClass arg) */

ATbool SDFhasCharClassWsAfterOptCharRanges(SDFCharClass arg)
{
  if (SDFisCharClassSimpleCharclass(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetCharClassWsAfterOptCharRanges(SDFCharClass arg) */

SDFLayout SDFgetCharClassWsAfterOptCharRanges(SDFCharClass arg)
{
  if (SDFisCharClassSimpleCharclass(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("CharClass has no WsAfterOptCharRanges: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharClass SDFsetCharClassWsAfterOptCharRanges(SDFCharClass arg, SDFLayout wsAfterOptCharRanges) */

SDFCharClass SDFsetCharClassWsAfterOptCharRanges(SDFCharClass arg, SDFLayout wsAfterOptCharRanges)
{
  if (SDFisCharClassSimpleCharclass(arg)) {
    return (SDFCharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterOptCharRanges, 0), 3), 2);
  }

  ATabort("CharClass has no WsAfterOptCharRanges: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasCharClassCharClass(SDFCharClass arg) */

ATbool SDFhasCharClassCharClass(SDFCharClass arg)
{
  if (SDFisCharClassComp(arg)) {
    return ATtrue;
  }
  else if (SDFisCharClassBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFCharClass SDFgetCharClassCharClass(SDFCharClass arg) */

SDFCharClass SDFgetCharClassCharClass(SDFCharClass arg)
{
  if (SDFisCharClassComp(arg)) {
    return (SDFCharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDFisCharClassBracket(arg)) {
    return (SDFCharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("CharClass has no CharClass: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharClass SDFsetCharClassCharClass(SDFCharClass arg, SDFCharClass charClass) */

SDFCharClass SDFsetCharClassCharClass(SDFCharClass arg, SDFCharClass charClass)
{
  if (SDFisCharClassComp(arg)) {
    return (SDFCharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)charClass, 2), 2);
  }
  else if (SDFisCharClassBracket(arg)) {
    return (SDFCharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)charClass, 2), 2);
  }

  ATabort("CharClass has no CharClass: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasCharClassWsAfterBracketOpen(SDFCharClass arg) */

ATbool SDFhasCharClassWsAfterBracketOpen(SDFCharClass arg)
{
  if (SDFisCharClassSimpleCharclass(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetCharClassWsAfterBracketOpen(SDFCharClass arg) */

SDFLayout SDFgetCharClassWsAfterBracketOpen(SDFCharClass arg)
{
  if (SDFisCharClassSimpleCharclass(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("CharClass has no WsAfterBracketOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharClass SDFsetCharClassWsAfterBracketOpen(SDFCharClass arg, SDFLayout wsAfterBracketOpen) */

SDFCharClass SDFsetCharClassWsAfterBracketOpen(SDFCharClass arg, SDFLayout wsAfterBracketOpen)
{
  if (SDFisCharClassSimpleCharclass(arg)) {
    return (SDFCharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterBracketOpen, 0), 1), 2);
  }

  ATabort("CharClass has no WsAfterBracketOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasCharClassWsAfterSlashBackslash(SDFCharClass arg) */

ATbool SDFhasCharClassWsAfterSlashBackslash(SDFCharClass arg)
{
  if (SDFisCharClassIsect(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetCharClassWsAfterSlashBackslash(SDFCharClass arg) */

SDFLayout SDFgetCharClassWsAfterSlashBackslash(SDFCharClass arg)
{
  if (SDFisCharClassIsect(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("CharClass has no WsAfterSlashBackslash: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharClass SDFsetCharClassWsAfterSlashBackslash(SDFCharClass arg, SDFLayout wsAfterSlashBackslash) */

SDFCharClass SDFsetCharClassWsAfterSlashBackslash(SDFCharClass arg, SDFLayout wsAfterSlashBackslash)
{
  if (SDFisCharClassIsect(arg)) {
    return (SDFCharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterSlashBackslash, 0), 3), 2);
  }

  ATabort("CharClass has no WsAfterSlashBackslash: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasCharClassWsAfterCharClass(SDFCharClass arg) */

ATbool SDFhasCharClassWsAfterCharClass(SDFCharClass arg)
{
  if (SDFisCharClassBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetCharClassWsAfterCharClass(SDFCharClass arg) */

SDFLayout SDFgetCharClassWsAfterCharClass(SDFCharClass arg)
{
  if (SDFisCharClassBracket(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("CharClass has no WsAfterCharClass: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharClass SDFsetCharClassWsAfterCharClass(SDFCharClass arg, SDFLayout wsAfterCharClass) */

SDFCharClass SDFsetCharClassWsAfterCharClass(SDFCharClass arg, SDFLayout wsAfterCharClass)
{
  if (SDFisCharClassBracket(arg)) {
    return (SDFCharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterCharClass, 0), 3), 2);
  }

  ATabort("CharClass has no WsAfterCharClass: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasCharClassLeft(SDFCharClass arg) */

ATbool SDFhasCharClassLeft(SDFCharClass arg)
{
  if (SDFisCharClassDiff(arg)) {
    return ATtrue;
  }
  else if (SDFisCharClassIsect(arg)) {
    return ATtrue;
  }
  else if (SDFisCharClassUnion(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFCharClass SDFgetCharClassLeft(SDFCharClass arg) */

SDFCharClass SDFgetCharClassLeft(SDFCharClass arg)
{
  if (SDFisCharClassDiff(arg)) {
    return (SDFCharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDFisCharClassIsect(arg)) {
    return (SDFCharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDFisCharClassUnion(arg)) {
    return (SDFCharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("CharClass has no Left: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharClass SDFsetCharClassLeft(SDFCharClass arg, SDFCharClass left) */

SDFCharClass SDFsetCharClassLeft(SDFCharClass arg, SDFCharClass left)
{
  if (SDFisCharClassDiff(arg)) {
    return (SDFCharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)left, 0), 2);
  }
  else if (SDFisCharClassIsect(arg)) {
    return (SDFCharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)left, 0), 2);
  }
  else if (SDFisCharClassUnion(arg)) {
    return (SDFCharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)left, 0), 2);
  }

  ATabort("CharClass has no Left: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFAlphaNumericalEscChar accessor implementations */

/*{{{  ATbool SDFisValidAlphaNumericalEscChar(SDFAlphaNumericalEscChar arg) */

ATbool SDFisValidAlphaNumericalEscChar(SDFAlphaNumericalEscChar arg)
{
  if (SDFisAlphaNumericalEscCharDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisAlphaNumericalEscCharDefault(SDFAlphaNumericalEscChar arg) */

ATbool SDFisAlphaNumericalEscCharDefault(SDFAlphaNumericalEscChar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAlphaNumericalEscCharDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasAlphaNumericalEscCharLex(SDFAlphaNumericalEscChar arg) */

ATbool SDFhasAlphaNumericalEscCharLex(SDFAlphaNumericalEscChar arg)
{
  if (SDFisAlphaNumericalEscCharDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLexical SDFgetAlphaNumericalEscCharLex(SDFAlphaNumericalEscChar arg) */

SDFLexical SDFgetAlphaNumericalEscCharLex(SDFAlphaNumericalEscChar arg)
{
  if (SDFisAlphaNumericalEscCharDefault(arg)) {
    return (SDFLexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("AlphaNumericalEscChar has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAlphaNumericalEscChar SDFsetAlphaNumericalEscCharLex(SDFAlphaNumericalEscChar arg, SDFLexical lex) */

SDFAlphaNumericalEscChar SDFsetAlphaNumericalEscCharLex(SDFAlphaNumericalEscChar arg, SDFLexical lex)
{
  if (SDFisAlphaNumericalEscCharDefault(arg)) {
    return (SDFAlphaNumericalEscChar)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("AlphaNumericalEscChar has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFDecimalEscChar accessor implementations */

/*{{{  ATbool SDFisValidDecimalEscChar(SDFDecimalEscChar arg) */

ATbool SDFisValidDecimalEscChar(SDFDecimalEscChar arg)
{
  if (SDFisDecimalEscCharDec0_199(arg)) {
    return ATtrue;
  }
  else if (SDFisDecimalEscCharDec200_249(arg)) {
    return ATtrue;
  }
  else if (SDFisDecimalEscCharDec250_255(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisDecimalEscCharDec0_199(SDFDecimalEscChar arg) */

ATbool SDFisDecimalEscCharDec0_199(SDFDecimalEscChar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternDecimalEscCharDec0_199, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisDecimalEscCharDec200_249(SDFDecimalEscChar arg) */

ATbool SDFisDecimalEscCharDec200_249(SDFDecimalEscChar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternDecimalEscCharDec200_249, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisDecimalEscCharDec250_255(SDFDecimalEscChar arg) */

ATbool SDFisDecimalEscCharDec250_255(SDFDecimalEscChar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternDecimalEscCharDec250_255, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasDecimalEscCharLex(SDFDecimalEscChar arg) */

ATbool SDFhasDecimalEscCharLex(SDFDecimalEscChar arg)
{
  if (SDFisDecimalEscCharDec0_199(arg)) {
    return ATtrue;
  }
  else if (SDFisDecimalEscCharDec200_249(arg)) {
    return ATtrue;
  }
  else if (SDFisDecimalEscCharDec250_255(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLexical SDFgetDecimalEscCharLex(SDFDecimalEscChar arg) */

SDFLexical SDFgetDecimalEscCharLex(SDFDecimalEscChar arg)
{
  if (SDFisDecimalEscCharDec0_199(arg)) {
    return (SDFLexical)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (SDFisDecimalEscCharDec200_249(arg)) {
    return (SDFLexical)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (SDFisDecimalEscCharDec250_255(arg)) {
    return (SDFLexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("DecimalEscChar has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFDecimalEscChar SDFsetDecimalEscCharLex(SDFDecimalEscChar arg, SDFLexical lex) */

SDFDecimalEscChar SDFsetDecimalEscCharLex(SDFDecimalEscChar arg, SDFLexical lex)
{
  if (SDFisDecimalEscCharDec0_199(arg)) {
    return (SDFDecimalEscChar)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }
  else if (SDFisDecimalEscCharDec200_249(arg)) {
    return (SDFDecimalEscChar)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }
  else if (SDFisDecimalEscCharDec250_255(arg)) {
    return (SDFDecimalEscChar)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("DecimalEscChar has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFEscChar accessor implementations */

/*{{{  ATbool SDFisValidEscChar(SDFEscChar arg) */

ATbool SDFisValidEscChar(SDFEscChar arg)
{
  if (SDFisEscCharAlphaNumeric(arg)) {
    return ATtrue;
  }
  else if (SDFisEscCharDecimal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisEscCharAlphaNumeric(SDFEscChar arg) */

ATbool SDFisEscCharAlphaNumeric(SDFEscChar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternEscCharAlphaNumeric, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisEscCharDecimal(SDFEscChar arg) */

ATbool SDFisEscCharDecimal(SDFEscChar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternEscCharDecimal, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasEscCharLex(SDFEscChar arg) */

ATbool SDFhasEscCharLex(SDFEscChar arg)
{
  if (SDFisEscCharAlphaNumeric(arg)) {
    return ATtrue;
  }
  else if (SDFisEscCharDecimal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLexical SDFgetEscCharLex(SDFEscChar arg) */

SDFLexical SDFgetEscCharLex(SDFEscChar arg)
{
  if (SDFisEscCharAlphaNumeric(arg)) {
    return (SDFLexical)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (SDFisEscCharDecimal(arg)) {
    return (SDFLexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("EscChar has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFEscChar SDFsetEscCharLex(SDFEscChar arg, SDFLexical lex) */

SDFEscChar SDFsetEscCharLex(SDFEscChar arg, SDFLexical lex)
{
  if (SDFisEscCharAlphaNumeric(arg)) {
    return (SDFEscChar)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }
  else if (SDFisEscCharDecimal(arg)) {
    return (SDFEscChar)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("EscChar has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFLChar accessor implementations */

/*{{{  ATbool SDFisValidLChar(SDFLChar arg) */

ATbool SDFisValidLChar(SDFLChar arg)
{
  if (SDFisLCharNormal(arg)) {
    return ATtrue;
  }
  else if (SDFisLCharEscaped(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisLCharNormal(SDFLChar arg) */

ATbool SDFisLCharNormal(SDFLChar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternLCharNormal, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisLCharEscaped(SDFLChar arg) */

ATbool SDFisLCharEscaped(SDFLChar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternLCharEscaped, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasLCharLex(SDFLChar arg) */

ATbool SDFhasLCharLex(SDFLChar arg)
{
  if (SDFisLCharNormal(arg)) {
    return ATtrue;
  }
  else if (SDFisLCharEscaped(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLexical SDFgetLCharLex(SDFLChar arg) */

SDFLexical SDFgetLCharLex(SDFLChar arg)
{
  if (SDFisLCharNormal(arg)) {
    return (SDFLexical)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (SDFisLCharEscaped(arg)) {
    return (SDFLexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("LChar has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFLChar SDFsetLCharLex(SDFLChar arg, SDFLexical lex) */

SDFLChar SDFsetLCharLex(SDFLChar arg, SDFLexical lex)
{
  if (SDFisLCharNormal(arg)) {
    return (SDFLChar)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }
  else if (SDFisLCharEscaped(arg)) {
    return (SDFLChar)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("LChar has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFATerms accessor implementations */

/*{{{  ATbool SDFisValidATerms(SDFATerms arg) */

ATbool SDFisValidATerms(SDFATerms arg)
{
  if (SDFisATermsAterm(arg)) {
    return ATtrue;
  }
  else if (SDFisATermsCons(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisATermsAterm(SDFATerms arg) */

ATbool SDFisATermsAterm(SDFATerms arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternATermsAterm, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisATermsCons(SDFATerms arg) */

ATbool SDFisATermsCons(SDFATerms arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternATermsCons, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasATermsWsAfterComma(SDFATerms arg) */

ATbool SDFhasATermsWsAfterComma(SDFATerms arg)
{
  if (SDFisATermsCons(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetATermsWsAfterComma(SDFATerms arg) */

SDFLayout SDFgetATermsWsAfterComma(SDFATerms arg)
{
  if (SDFisATermsCons(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("ATerms has no WsAfterComma: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFATerms SDFsetATermsWsAfterComma(SDFATerms arg, SDFLayout wsAfterComma) */

SDFATerms SDFsetATermsWsAfterComma(SDFATerms arg, SDFLayout wsAfterComma)
{
  if (SDFisATermsCons(arg)) {
    return (SDFATerms)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterComma, 0), 3), 2);
  }

  ATabort("ATerms has no WsAfterComma: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasATermsATerm(SDFATerms arg) */

ATbool SDFhasATermsATerm(SDFATerms arg)
{
  if (SDFisATermsAterm(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFATerm SDFgetATermsATerm(SDFATerms arg) */

SDFATerm SDFgetATermsATerm(SDFATerms arg)
{
  if (SDFisATermsAterm(arg)) {
    return (SDFATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("ATerms has no ATerm: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFATerms SDFsetATermsATerm(SDFATerms arg, SDFATerm aTerm) */

SDFATerms SDFsetATermsATerm(SDFATerms arg, SDFATerm aTerm)
{
  if (SDFisATermsAterm(arg)) {
    return (SDFATerms)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aTerm, 0), 2);
  }

  ATabort("ATerms has no ATerm: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasATermsTail(SDFATerms arg) */

ATbool SDFhasATermsTail(SDFATerms arg)
{
  if (SDFisATermsCons(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFATerms SDFgetATermsTail(SDFATerms arg) */

SDFATerms SDFgetATermsTail(SDFATerms arg)
{
  if (SDFisATermsCons(arg)) {
    return (SDFATerms)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("ATerms has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFATerms SDFsetATermsTail(SDFATerms arg, SDFATerms tail) */

SDFATerms SDFsetATermsTail(SDFATerms arg, SDFATerms tail)
{
  if (SDFisATermsCons(arg)) {
    return (SDFATerms)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)tail, 4), 2);
  }

  ATabort("ATerms has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasATermsHead(SDFATerms arg) */

ATbool SDFhasATermsHead(SDFATerms arg)
{
  if (SDFisATermsCons(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFATerm SDFgetATermsHead(SDFATerms arg) */

SDFATerm SDFgetATermsHead(SDFATerms arg)
{
  if (SDFisATermsCons(arg)) {
    return (SDFATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("ATerms has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFATerms SDFsetATermsHead(SDFATerms arg, SDFATerm head) */

SDFATerms SDFsetATermsHead(SDFATerms arg, SDFATerm head)
{
  if (SDFisATermsCons(arg)) {
    return (SDFATerms)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)head, 0), 2);
  }

  ATabort("ATerms has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasATermsWsAfterHead(SDFATerms arg) */

ATbool SDFhasATermsWsAfterHead(SDFATerms arg)
{
  if (SDFisATermsCons(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetATermsWsAfterHead(SDFATerms arg) */

SDFLayout SDFgetATermsWsAfterHead(SDFATerms arg)
{
  if (SDFisATermsCons(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("ATerms has no WsAfterHead: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFATerms SDFsetATermsWsAfterHead(SDFATerms arg, SDFLayout wsAfterHead) */

SDFATerms SDFsetATermsWsAfterHead(SDFATerms arg, SDFLayout wsAfterHead)
{
  if (SDFisATermsCons(arg)) {
    return (SDFATerms)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterHead, 0), 1), 2);
  }

  ATabort("ATerms has no WsAfterHead: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFATermList accessor implementations */

/*{{{  ATbool SDFisValidATermList(SDFATermList arg) */

ATbool SDFisValidATermList(SDFATermList arg)
{
  if (SDFisATermListEmpty(arg)) {
    return ATtrue;
  }
  else if (SDFisATermListNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisATermListEmpty(SDFATermList arg) */

ATbool SDFisATermListEmpty(SDFATermList arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternATermListEmpty, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisATermListNotEmpty(SDFATermList arg) */

ATbool SDFisATermListNotEmpty(SDFATermList arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternATermListNotEmpty, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasATermListWsAfterBracketOpen(SDFATermList arg) */

ATbool SDFhasATermListWsAfterBracketOpen(SDFATermList arg)
{
  if (SDFisATermListEmpty(arg)) {
    return ATtrue;
  }
  else if (SDFisATermListNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetATermListWsAfterBracketOpen(SDFATermList arg) */

SDFLayout SDFgetATermListWsAfterBracketOpen(SDFATermList arg)
{
  if (SDFisATermListEmpty(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisATermListNotEmpty(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("ATermList has no WsAfterBracketOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFATermList SDFsetATermListWsAfterBracketOpen(SDFATermList arg, SDFLayout wsAfterBracketOpen) */

SDFATermList SDFsetATermListWsAfterBracketOpen(SDFATermList arg, SDFLayout wsAfterBracketOpen)
{
  if (SDFisATermListEmpty(arg)) {
    return (SDFATermList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterBracketOpen, 0), 1), 2);
  }
  else if (SDFisATermListNotEmpty(arg)) {
    return (SDFATermList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterBracketOpen, 0), 1), 2);
  }

  ATabort("ATermList has no WsAfterBracketOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasATermListWsAfterATerms(SDFATermList arg) */

ATbool SDFhasATermListWsAfterATerms(SDFATermList arg)
{
  if (SDFisATermListNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetATermListWsAfterATerms(SDFATermList arg) */

SDFLayout SDFgetATermListWsAfterATerms(SDFATermList arg)
{
  if (SDFisATermListNotEmpty(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("ATermList has no WsAfterATerms: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFATermList SDFsetATermListWsAfterATerms(SDFATermList arg, SDFLayout wsAfterATerms) */

SDFATermList SDFsetATermListWsAfterATerms(SDFATermList arg, SDFLayout wsAfterATerms)
{
  if (SDFisATermListNotEmpty(arg)) {
    return (SDFATermList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterATerms, 0), 3), 2);
  }

  ATabort("ATermList has no WsAfterATerms: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasATermListATerms(SDFATermList arg) */

ATbool SDFhasATermListATerms(SDFATermList arg)
{
  if (SDFisATermListNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFATerms SDFgetATermListATerms(SDFATermList arg) */

SDFATerms SDFgetATermListATerms(SDFATermList arg)
{
  if (SDFisATermListNotEmpty(arg)) {
    return (SDFATerms)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("ATermList has no ATerms: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFATermList SDFsetATermListATerms(SDFATermList arg, SDFATerms aTerms) */

SDFATermList SDFsetATermListATerms(SDFATermList arg, SDFATerms aTerms)
{
  if (SDFisATermListNotEmpty(arg)) {
    return (SDFATermList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aTerms, 2), 2);
  }

  ATabort("ATermList has no ATerms: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFACon accessor implementations */

/*{{{  ATbool SDFisValidACon(SDFACon arg) */

ATbool SDFisValidACon(SDFACon arg)
{
  if (SDFisAConInt(arg)) {
    return ATtrue;
  }
  else if (SDFisAConReal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisAConInt(SDFACon arg) */

ATbool SDFisAConInt(SDFACon arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAConInt, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisAConReal(SDFACon arg) */

ATbool SDFisAConReal(SDFACon arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAConReal, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasAConIntCon(SDFACon arg) */

ATbool SDFhasAConIntCon(SDFACon arg)
{
  if (SDFisAConInt(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFIntCon SDFgetAConIntCon(SDFACon arg) */

SDFIntCon SDFgetAConIntCon(SDFACon arg)
{
  if (SDFisAConInt(arg)) {
    return (SDFIntCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("ACon has no IntCon: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFACon SDFsetAConIntCon(SDFACon arg, SDFIntCon intCon) */

SDFACon SDFsetAConIntCon(SDFACon arg, SDFIntCon intCon)
{
  if (SDFisAConInt(arg)) {
    return (SDFACon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)intCon, 0), 2);
  }

  ATabort("ACon has no IntCon: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasAConRealCon(SDFACon arg) */

ATbool SDFhasAConRealCon(SDFACon arg)
{
  if (SDFisAConReal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFRealCon SDFgetAConRealCon(SDFACon arg) */

SDFRealCon SDFgetAConRealCon(SDFACon arg)
{
  if (SDFisAConReal(arg)) {
    return (SDFRealCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("ACon has no RealCon: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFACon SDFsetAConRealCon(SDFACon arg, SDFRealCon realCon) */

SDFACon SDFsetAConRealCon(SDFACon arg, SDFRealCon realCon)
{
  if (SDFisAConReal(arg)) {
    return (SDFACon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)realCon, 0), 2);
  }

  ATabort("ACon has no RealCon: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFAFun accessor implementations */

/*{{{  ATbool SDFisValidAFun(SDFAFun arg) */

ATbool SDFisValidAFun(SDFAFun arg)
{
  if (SDFisAFunDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisAFunDefault(SDFAFun arg) */

ATbool SDFisAFunDefault(SDFAFun arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAFunDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasAFunLiteral(SDFAFun arg) */

ATbool SDFhasAFunLiteral(SDFAFun arg)
{
  if (SDFisAFunDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLiteral SDFgetAFunLiteral(SDFAFun arg) */

SDFLiteral SDFgetAFunLiteral(SDFAFun arg)
{
  if (SDFisAFunDefault(arg)) {
    return (SDFLiteral)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("AFun has no Literal: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAFun SDFsetAFunLiteral(SDFAFun arg, SDFLiteral literal) */

SDFAFun SDFsetAFunLiteral(SDFAFun arg, SDFLiteral literal)
{
  if (SDFisAFunDefault(arg)) {
    return (SDFAFun)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)literal, 0), 2);
  }

  ATabort("AFun has no Literal: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFATerm accessor implementations */

/*{{{  ATbool SDFisValidATerm(SDFATerm arg) */

ATbool SDFisValidATerm(SDFATerm arg)
{
  if (SDFisATermConstant(arg)) {
    return ATtrue;
  }
  else if (SDFisATermList(arg)) {
    return ATtrue;
  }
  else if (SDFisATermFun(arg)) {
    return ATtrue;
  }
  else if (SDFisATermAppl(arg)) {
    return ATtrue;
  }
  else if (SDFisATermAnnotatedConstant(arg)) {
    return ATtrue;
  }
  else if (SDFisATermAnnotatedList(arg)) {
    return ATtrue;
  }
  else if (SDFisATermAnnotatedFun(arg)) {
    return ATtrue;
  }
  else if (SDFisATermAnnotatedAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisATermConstant(SDFATerm arg) */

ATbool SDFisATermConstant(SDFATerm arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternATermConstant, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisATermList(SDFATerm arg) */

ATbool SDFisATermList(SDFATerm arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternATermList, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisATermFun(SDFATerm arg) */

ATbool SDFisATermFun(SDFATerm arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternATermFun, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisATermAppl(SDFATerm arg) */

ATbool SDFisATermAppl(SDFATerm arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternATermAppl, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisATermAnnotatedConstant(SDFATerm arg) */

ATbool SDFisATermAnnotatedConstant(SDFATerm arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternATermAnnotatedConstant, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisATermAnnotatedList(SDFATerm arg) */

ATbool SDFisATermAnnotatedList(SDFATerm arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternATermAnnotatedList, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisATermAnnotatedFun(SDFATerm arg) */

ATbool SDFisATermAnnotatedFun(SDFATerm arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternATermAnnotatedFun, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisATermAnnotatedAppl(SDFATerm arg) */

ATbool SDFisATermAnnotatedAppl(SDFATerm arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternATermAnnotatedAppl, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasATermWsAfterAFun(SDFATerm arg) */

ATbool SDFhasATermWsAfterAFun(SDFATerm arg)
{
  if (SDFisATermAppl(arg)) {
    return ATtrue;
  }
  else if (SDFisATermAnnotatedFun(arg)) {
    return ATtrue;
  }
  else if (SDFisATermAnnotatedAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetATermWsAfterAFun(SDFATerm arg) */

SDFLayout SDFgetATermWsAfterAFun(SDFATerm arg)
{
  if (SDFisATermAppl(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisATermAnnotatedFun(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }
  else if (SDFisATermAnnotatedAppl(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("ATerm has no WsAfterAFun: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFATerm SDFsetATermWsAfterAFun(SDFATerm arg, SDFLayout wsAfterAFun) */

SDFATerm SDFsetATermWsAfterAFun(SDFATerm arg, SDFLayout wsAfterAFun)
{
  if (SDFisATermAppl(arg)) {
    return (SDFATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterAFun, 0), 1), 2);
  }
  else if (SDFisATermAnnotatedFun(arg)) {
    return (SDFATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterAFun, 0), 1), 2);
  }
  else if (SDFisATermAnnotatedAppl(arg)) {
    return (SDFATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterAFun, 0), 1), 2);
  }

  ATabort("ATerm has no WsAfterAFun: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasATermWsAfterParenClose(SDFATerm arg) */

ATbool SDFhasATermWsAfterParenClose(SDFATerm arg)
{
  if (SDFisATermAnnotatedAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetATermWsAfterParenClose(SDFATerm arg) */

SDFLayout SDFgetATermWsAfterParenClose(SDFATerm arg)
{
  if (SDFisATermAnnotatedAppl(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), 0);
  }

  ATabort("ATerm has no WsAfterParenClose: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFATerm SDFsetATermWsAfterParenClose(SDFATerm arg, SDFLayout wsAfterParenClose) */

SDFATerm SDFsetATermWsAfterParenClose(SDFATerm arg, SDFLayout wsAfterParenClose)
{
  if (SDFisATermAnnotatedAppl(arg)) {
    return (SDFATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 7), (ATerm)wsAfterParenClose, 0), 7), 2);
  }

  ATabort("ATerm has no WsAfterParenClose: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasATermWsAfterParenOpen(SDFATerm arg) */

ATbool SDFhasATermWsAfterParenOpen(SDFATerm arg)
{
  if (SDFisATermAppl(arg)) {
    return ATtrue;
  }
  else if (SDFisATermAnnotatedAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetATermWsAfterParenOpen(SDFATerm arg) */

SDFLayout SDFgetATermWsAfterParenOpen(SDFATerm arg)
{
  if (SDFisATermAppl(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }
  else if (SDFisATermAnnotatedAppl(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("ATerm has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFATerm SDFsetATermWsAfterParenOpen(SDFATerm arg, SDFLayout wsAfterParenOpen) */

SDFATerm SDFsetATermWsAfterParenOpen(SDFATerm arg, SDFLayout wsAfterParenOpen)
{
  if (SDFisATermAppl(arg)) {
    return (SDFATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterParenOpen, 0), 3), 2);
  }
  else if (SDFisATermAnnotatedAppl(arg)) {
    return (SDFATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterParenOpen, 0), 3), 2);
  }

  ATabort("ATerm has no WsAfterParenOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasATermACon(SDFATerm arg) */

ATbool SDFhasATermACon(SDFATerm arg)
{
  if (SDFisATermConstant(arg)) {
    return ATtrue;
  }
  else if (SDFisATermAnnotatedConstant(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFACon SDFgetATermACon(SDFATerm arg) */

SDFACon SDFgetATermACon(SDFATerm arg)
{
  if (SDFisATermConstant(arg)) {
    return (SDFACon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDFisATermAnnotatedConstant(arg)) {
    return (SDFACon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("ATerm has no ACon: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFATerm SDFsetATermACon(SDFATerm arg, SDFACon aCon) */

SDFATerm SDFsetATermACon(SDFATerm arg, SDFACon aCon)
{
  if (SDFisATermConstant(arg)) {
    return (SDFATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aCon, 0), 2);
  }
  else if (SDFisATermAnnotatedConstant(arg)) {
    return (SDFATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aCon, 0), 2);
  }

  ATabort("ATerm has no ACon: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasATermAnn(SDFATerm arg) */

ATbool SDFhasATermAnn(SDFATerm arg)
{
  if (SDFisATermAnnotatedConstant(arg)) {
    return ATtrue;
  }
  else if (SDFisATermAnnotatedList(arg)) {
    return ATtrue;
  }
  else if (SDFisATermAnnotatedFun(arg)) {
    return ATtrue;
  }
  else if (SDFisATermAnnotatedAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFAnn SDFgetATermAnn(SDFATerm arg) */

SDFAnn SDFgetATermAnn(SDFATerm arg)
{
  if (SDFisATermAnnotatedConstant(arg)) {
    return (SDFAnn)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDFisATermAnnotatedList(arg)) {
    return (SDFAnn)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDFisATermAnnotatedFun(arg)) {
    return (SDFAnn)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (SDFisATermAnnotatedAppl(arg)) {
    return (SDFAnn)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 8);
  }

  ATabort("ATerm has no Ann: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFATerm SDFsetATermAnn(SDFATerm arg, SDFAnn ann) */

SDFATerm SDFsetATermAnn(SDFATerm arg, SDFAnn ann)
{
  if (SDFisATermAnnotatedConstant(arg)) {
    return (SDFATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ann, 2), 2);
  }
  else if (SDFisATermAnnotatedList(arg)) {
    return (SDFATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ann, 2), 2);
  }
  else if (SDFisATermAnnotatedFun(arg)) {
    return (SDFATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ann, 2), 2);
  }
  else if (SDFisATermAnnotatedAppl(arg)) {
    return (SDFATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ann, 8), 2);
  }

  ATabort("ATerm has no Ann: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasATermArgs(SDFATerm arg) */

ATbool SDFhasATermArgs(SDFATerm arg)
{
  if (SDFisATermAppl(arg)) {
    return ATtrue;
  }
  else if (SDFisATermAnnotatedAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFATerms SDFgetATermArgs(SDFATerm arg) */

SDFATerms SDFgetATermArgs(SDFATerm arg)
{
  if (SDFisATermAppl(arg)) {
    return (SDFATerms)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (SDFisATermAnnotatedAppl(arg)) {
    return (SDFATerms)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("ATerm has no Args: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFATerm SDFsetATermArgs(SDFATerm arg, SDFATerms args) */

SDFATerm SDFsetATermArgs(SDFATerm arg, SDFATerms args)
{
  if (SDFisATermAppl(arg)) {
    return (SDFATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)args, 4), 2);
  }
  else if (SDFisATermAnnotatedAppl(arg)) {
    return (SDFATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)args, 4), 2);
  }

  ATabort("ATerm has no Args: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasATermWsAfterACon(SDFATerm arg) */

ATbool SDFhasATermWsAfterACon(SDFATerm arg)
{
  if (SDFisATermAnnotatedConstant(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetATermWsAfterACon(SDFATerm arg) */

SDFLayout SDFgetATermWsAfterACon(SDFATerm arg)
{
  if (SDFisATermAnnotatedConstant(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("ATerm has no WsAfterACon: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFATerm SDFsetATermWsAfterACon(SDFATerm arg, SDFLayout wsAfterACon) */

SDFATerm SDFsetATermWsAfterACon(SDFATerm arg, SDFLayout wsAfterACon)
{
  if (SDFisATermAnnotatedConstant(arg)) {
    return (SDFATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterACon, 0), 1), 2);
  }

  ATabort("ATerm has no WsAfterACon: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasATermWsAfterArgs(SDFATerm arg) */

ATbool SDFhasATermWsAfterArgs(SDFATerm arg)
{
  if (SDFisATermAppl(arg)) {
    return ATtrue;
  }
  else if (SDFisATermAnnotatedAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetATermWsAfterArgs(SDFATerm arg) */

SDFLayout SDFgetATermWsAfterArgs(SDFATerm arg)
{
  if (SDFisATermAppl(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }
  else if (SDFisATermAnnotatedAppl(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("ATerm has no WsAfterArgs: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFATerm SDFsetATermWsAfterArgs(SDFATerm arg, SDFLayout wsAfterArgs) */

SDFATerm SDFsetATermWsAfterArgs(SDFATerm arg, SDFLayout wsAfterArgs)
{
  if (SDFisATermAppl(arg)) {
    return (SDFATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterArgs, 0), 5), 2);
  }
  else if (SDFisATermAnnotatedAppl(arg)) {
    return (SDFATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterArgs, 0), 5), 2);
  }

  ATabort("ATerm has no WsAfterArgs: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasATermATermList(SDFATerm arg) */

ATbool SDFhasATermATermList(SDFATerm arg)
{
  if (SDFisATermList(arg)) {
    return ATtrue;
  }
  else if (SDFisATermAnnotatedList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFATermList SDFgetATermATermList(SDFATerm arg) */

SDFATermList SDFgetATermATermList(SDFATerm arg)
{
  if (SDFisATermList(arg)) {
    return (SDFATermList)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDFisATermAnnotatedList(arg)) {
    return (SDFATermList)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("ATerm has no ATermList: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFATerm SDFsetATermATermList(SDFATerm arg, SDFATermList aTermList) */

SDFATerm SDFsetATermATermList(SDFATerm arg, SDFATermList aTermList)
{
  if (SDFisATermList(arg)) {
    return (SDFATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aTermList, 0), 2);
  }
  else if (SDFisATermAnnotatedList(arg)) {
    return (SDFATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aTermList, 0), 2);
  }

  ATabort("ATerm has no ATermList: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasATermAFun(SDFATerm arg) */

ATbool SDFhasATermAFun(SDFATerm arg)
{
  if (SDFisATermFun(arg)) {
    return ATtrue;
  }
  else if (SDFisATermAppl(arg)) {
    return ATtrue;
  }
  else if (SDFisATermAnnotatedFun(arg)) {
    return ATtrue;
  }
  else if (SDFisATermAnnotatedAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFAFun SDFgetATermAFun(SDFATerm arg) */

SDFAFun SDFgetATermAFun(SDFATerm arg)
{
  if (SDFisATermFun(arg)) {
    return (SDFAFun)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDFisATermAppl(arg)) {
    return (SDFAFun)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDFisATermAnnotatedFun(arg)) {
    return (SDFAFun)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (SDFisATermAnnotatedAppl(arg)) {
    return (SDFAFun)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("ATerm has no AFun: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFATerm SDFsetATermAFun(SDFATerm arg, SDFAFun aFun) */

SDFATerm SDFsetATermAFun(SDFATerm arg, SDFAFun aFun)
{
  if (SDFisATermFun(arg)) {
    return (SDFATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aFun, 0), 2);
  }
  else if (SDFisATermAppl(arg)) {
    return (SDFATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aFun, 0), 2);
  }
  else if (SDFisATermAnnotatedFun(arg)) {
    return (SDFATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aFun, 0), 2);
  }
  else if (SDFisATermAnnotatedAppl(arg)) {
    return (SDFATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aFun, 0), 2);
  }

  ATabort("ATerm has no AFun: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasATermWsAfterATermList(SDFATerm arg) */

ATbool SDFhasATermWsAfterATermList(SDFATerm arg)
{
  if (SDFisATermAnnotatedList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetATermWsAfterATermList(SDFATerm arg) */

SDFLayout SDFgetATermWsAfterATermList(SDFATerm arg)
{
  if (SDFisATermAnnotatedList(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("ATerm has no WsAfterATermList: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFATerm SDFsetATermWsAfterATermList(SDFATerm arg, SDFLayout wsAfterATermList) */

SDFATerm SDFsetATermWsAfterATermList(SDFATerm arg, SDFLayout wsAfterATermList)
{
  if (SDFisATermAnnotatedList(arg)) {
    return (SDFATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterATermList, 0), 1), 2);
  }

  ATabort("ATerm has no WsAfterATermList: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFAnn accessor implementations */

/*{{{  ATbool SDFisValidAnn(SDFAnn arg) */

ATbool SDFisValidAnn(SDFAnn arg)
{
  if (SDFisAnnAnnotation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisAnnAnnotation(SDFAnn arg) */

ATbool SDFisAnnAnnotation(SDFAnn arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternAnnAnnotation, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasAnnWsAfterBraceOpen(SDFAnn arg) */

ATbool SDFhasAnnWsAfterBraceOpen(SDFAnn arg)
{
  if (SDFisAnnAnnotation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetAnnWsAfterBraceOpen(SDFAnn arg) */

SDFLayout SDFgetAnnWsAfterBraceOpen(SDFAnn arg)
{
  if (SDFisAnnAnnotation(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("Ann has no WsAfterBraceOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAnn SDFsetAnnWsAfterBraceOpen(SDFAnn arg, SDFLayout wsAfterBraceOpen) */

SDFAnn SDFsetAnnWsAfterBraceOpen(SDFAnn arg, SDFLayout wsAfterBraceOpen)
{
  if (SDFisAnnAnnotation(arg)) {
    return (SDFAnn)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterBraceOpen, 0), 1), 2);
  }

  ATabort("Ann has no WsAfterBraceOpen: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasAnnWsAfterATerms(SDFAnn arg) */

ATbool SDFhasAnnWsAfterATerms(SDFAnn arg)
{
  if (SDFisAnnAnnotation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetAnnWsAfterATerms(SDFAnn arg) */

SDFLayout SDFgetAnnWsAfterATerms(SDFAnn arg)
{
  if (SDFisAnnAnnotation(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("Ann has no WsAfterATerms: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAnn SDFsetAnnWsAfterATerms(SDFAnn arg, SDFLayout wsAfterATerms) */

SDFAnn SDFsetAnnWsAfterATerms(SDFAnn arg, SDFLayout wsAfterATerms)
{
  if (SDFisAnnAnnotation(arg)) {
    return (SDFAnn)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterATerms, 0), 3), 2);
  }

  ATabort("Ann has no WsAfterATerms: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasAnnATerms(SDFAnn arg) */

ATbool SDFhasAnnATerms(SDFAnn arg)
{
  if (SDFisAnnAnnotation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFATerms SDFgetAnnATerms(SDFAnn arg) */

SDFATerms SDFgetAnnATerms(SDFAnn arg)
{
  if (SDFisAnnAnnotation(arg)) {
    return (SDFATerms)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Ann has no ATerms: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFAnn SDFsetAnnATerms(SDFAnn arg, SDFATerms aTerms) */

SDFAnn SDFsetAnnATerms(SDFAnn arg, SDFATerms aTerms)
{
  if (SDFisAnnAnnotation(arg)) {
    return (SDFAnn)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)aTerms, 2), 2);
  }

  ATabort("Ann has no ATerms: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFTagId accessor implementations */

/*{{{  ATbool SDFisValidTagId(SDFTagId arg) */

ATbool SDFisValidTagId(SDFTagId arg)
{
  if (SDFisTagIdDefault(arg)) {
    return ATtrue;
  }
  else if (SDFisTagIdEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisTagIdDefault(SDFTagId arg) */

ATbool SDFisTagIdDefault(SDFTagId arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternTagIdDefault, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisTagIdEmpty(SDFTagId arg) */

ATbool SDFisTagIdEmpty(SDFTagId arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternTagIdEmpty);
}

/*}}}  */
/*{{{  ATbool SDFhasTagIdLex(SDFTagId arg) */

ATbool SDFhasTagIdLex(SDFTagId arg)
{
  if (SDFisTagIdDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLexical SDFgetTagIdLex(SDFTagId arg) */

SDFLexical SDFgetTagIdLex(SDFTagId arg)
{
  if (SDFisTagIdDefault(arg)) {
    return (SDFLexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("TagId has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFTagId SDFsetTagIdLex(SDFTagId arg, SDFLexical lex) */

SDFTagId SDFsetTagIdLex(SDFTagId arg, SDFLexical lex)
{
  if (SDFisTagIdDefault(arg)) {
    return (SDFTagId)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("TagId has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFNumChar accessor implementations */

/*{{{  ATbool SDFisValidNumChar(SDFNumChar arg) */

ATbool SDFisValidNumChar(SDFNumChar arg)
{
  if (SDFisNumCharDigits(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisNumCharDigits(SDFNumChar arg) */

ATbool SDFisNumCharDigits(SDFNumChar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternNumCharDigits, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasNumCharLex(SDFNumChar arg) */

ATbool SDFhasNumCharLex(SDFNumChar arg)
{
  if (SDFisNumCharDigits(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLexical SDFgetNumCharLex(SDFNumChar arg) */

SDFLexical SDFgetNumCharLex(SDFNumChar arg)
{
  if (SDFisNumCharDigits(arg)) {
    return (SDFLexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("NumChar has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFNumChar SDFsetNumCharLex(SDFNumChar arg, SDFLexical lex) */

SDFNumChar SDFsetNumCharLex(SDFNumChar arg, SDFLexical lex)
{
  if (SDFisNumCharDigits(arg)) {
    return (SDFNumChar)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("NumChar has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFShortChar accessor implementations */

/*{{{  ATbool SDFisValidShortChar(SDFShortChar arg) */

ATbool SDFisValidShortChar(SDFShortChar arg)
{
  if (SDFisShortCharRegular(arg)) {
    return ATtrue;
  }
  else if (SDFisShortCharEscaped(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisShortCharRegular(SDFShortChar arg) */

ATbool SDFisShortCharRegular(SDFShortChar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternShortCharRegular, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisShortCharEscaped(SDFShortChar arg) */

ATbool SDFisShortCharEscaped(SDFShortChar arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternShortCharEscaped, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasShortCharLex(SDFShortChar arg) */

ATbool SDFhasShortCharLex(SDFShortChar arg)
{
  if (SDFisShortCharRegular(arg)) {
    return ATtrue;
  }
  else if (SDFisShortCharEscaped(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLexical SDFgetShortCharLex(SDFShortChar arg) */

SDFLexical SDFgetShortCharLex(SDFShortChar arg)
{
  if (SDFisShortCharRegular(arg)) {
    return (SDFLexical)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (SDFisShortCharEscaped(arg)) {
    return (SDFLexical)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("ShortChar has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFShortChar SDFsetShortCharLex(SDFShortChar arg, SDFLexical lex) */

SDFShortChar SDFsetShortCharLex(SDFShortChar arg, SDFLexical lex)
{
  if (SDFisShortCharRegular(arg)) {
    return (SDFShortChar)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }
  else if (SDFisShortCharEscaped(arg)) {
    return (SDFShortChar)ATsetArgument((ATermAppl)arg, (ATerm)lex, 0);
  }

  ATabort("ShortChar has no Lex: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFCharacter accessor implementations */

/*{{{  ATbool SDFisValidCharacter(SDFCharacter arg) */

ATbool SDFisValidCharacter(SDFCharacter arg)
{
  if (SDFisCharacterNumeric(arg)) {
    return ATtrue;
  }
  else if (SDFisCharacterShort(arg)) {
    return ATtrue;
  }
  else if (SDFisCharacterTop(arg)) {
    return ATtrue;
  }
  else if (SDFisCharacterEof(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisCharacterNumeric(SDFCharacter arg) */

ATbool SDFisCharacterNumeric(SDFCharacter arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternCharacterNumeric, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisCharacterShort(SDFCharacter arg) */

ATbool SDFisCharacterShort(SDFCharacter arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternCharacterShort, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisCharacterTop(SDFCharacter arg) */

ATbool SDFisCharacterTop(SDFCharacter arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternCharacterTop);
}

/*}}}  */
/*{{{  ATbool SDFisCharacterEof(SDFCharacter arg) */

ATbool SDFisCharacterEof(SDFCharacter arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternCharacterEof);
}

/*}}}  */
/*{{{  ATbool SDFhasCharacterShortChar(SDFCharacter arg) */

ATbool SDFhasCharacterShortChar(SDFCharacter arg)
{
  if (SDFisCharacterShort(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFShortChar SDFgetCharacterShortChar(SDFCharacter arg) */

SDFShortChar SDFgetCharacterShortChar(SDFCharacter arg)
{
  if (SDFisCharacterShort(arg)) {
    return (SDFShortChar)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Character has no ShortChar: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharacter SDFsetCharacterShortChar(SDFCharacter arg, SDFShortChar shortChar) */

SDFCharacter SDFsetCharacterShortChar(SDFCharacter arg, SDFShortChar shortChar)
{
  if (SDFisCharacterShort(arg)) {
    return (SDFCharacter)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)shortChar, 0), 2);
  }

  ATabort("Character has no ShortChar: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasCharacterNumChar(SDFCharacter arg) */

ATbool SDFhasCharacterNumChar(SDFCharacter arg)
{
  if (SDFisCharacterNumeric(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFNumChar SDFgetCharacterNumChar(SDFCharacter arg) */

SDFNumChar SDFgetCharacterNumChar(SDFCharacter arg)
{
  if (SDFisCharacterNumeric(arg)) {
    return (SDFNumChar)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Character has no NumChar: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFCharacter SDFsetCharacterNumChar(SDFCharacter arg, SDFNumChar numChar) */

SDFCharacter SDFsetCharacterNumChar(SDFCharacter arg, SDFNumChar numChar)
{
  if (SDFisCharacterNumeric(arg)) {
    return (SDFCharacter)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)numChar, 0), 2);
  }

  ATabort("Character has no NumChar: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFOptExp accessor implementations */

/*{{{  ATbool SDFisValidOptExp(SDFOptExp arg) */

ATbool SDFisValidOptExp(SDFOptExp arg)
{
  if (SDFisOptExpPresent(arg)) {
    return ATtrue;
  }
  else if (SDFisOptExpAbsent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisOptExpPresent(SDFOptExp arg) */

ATbool SDFisOptExpPresent(SDFOptExp arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternOptExpPresent, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFisOptExpAbsent(SDFOptExp arg) */

ATbool SDFisOptExpAbsent(SDFOptExp arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternOptExpAbsent);
}

/*}}}  */
/*{{{  ATbool SDFhasOptExpWsAfterE(SDFOptExp arg) */

ATbool SDFhasOptExpWsAfterE(SDFOptExp arg)
{
  if (SDFisOptExpPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetOptExpWsAfterE(SDFOptExp arg) */

SDFLayout SDFgetOptExpWsAfterE(SDFOptExp arg)
{
  if (SDFisOptExpPresent(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("OptExp has no WsAfterE: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFOptExp SDFsetOptExpWsAfterE(SDFOptExp arg, SDFLayout wsAfterE) */

SDFOptExp SDFsetOptExpWsAfterE(SDFOptExp arg, SDFLayout wsAfterE)
{
  if (SDFisOptExpPresent(arg)) {
    return (SDFOptExp)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterE, 0), 1), 2);
  }

  ATabort("OptExp has no WsAfterE: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasOptExpIntCon(SDFOptExp arg) */

ATbool SDFhasOptExpIntCon(SDFOptExp arg)
{
  if (SDFisOptExpPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFIntCon SDFgetOptExpIntCon(SDFOptExp arg) */

SDFIntCon SDFgetOptExpIntCon(SDFOptExp arg)
{
  if (SDFisOptExpPresent(arg)) {
    return (SDFIntCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("OptExp has no IntCon: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFOptExp SDFsetOptExpIntCon(SDFOptExp arg, SDFIntCon intCon) */

SDFOptExp SDFsetOptExpIntCon(SDFOptExp arg, SDFIntCon intCon)
{
  if (SDFisOptExpPresent(arg)) {
    return (SDFOptExp)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)intCon, 2), 2);
  }

  ATabort("OptExp has no IntCon: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDFRealCon accessor implementations */

/*{{{  ATbool SDFisValidRealCon(SDFRealCon arg) */

ATbool SDFisValidRealCon(SDFRealCon arg)
{
  if (SDFisRealConRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SDFisRealConRealCon(SDFRealCon arg) */

ATbool SDFisRealConRealCon(SDFRealCon arg)
{
  return ATmatchTerm((ATerm)arg, SDFpatternRealConRealCon, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SDFhasRealConWsAfterPeriod(SDFRealCon arg) */

ATbool SDFhasRealConWsAfterPeriod(SDFRealCon arg)
{
  if (SDFisRealConRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetRealConWsAfterPeriod(SDFRealCon arg) */

SDFLayout SDFgetRealConWsAfterPeriod(SDFRealCon arg)
{
  if (SDFisRealConRealCon(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0);
  }

  ATabort("RealCon has no WsAfterPeriod: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFRealCon SDFsetRealConWsAfterPeriod(SDFRealCon arg, SDFLayout wsAfterPeriod) */

SDFRealCon SDFsetRealConWsAfterPeriod(SDFRealCon arg, SDFLayout wsAfterPeriod)
{
  if (SDFisRealConRealCon(arg)) {
    return (SDFRealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)wsAfterPeriod, 0), 3), 2);
  }

  ATabort("RealCon has no WsAfterPeriod: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasRealConWsAfterIntCon(SDFRealCon arg) */

ATbool SDFhasRealConWsAfterIntCon(SDFRealCon arg)
{
  if (SDFisRealConRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetRealConWsAfterIntCon(SDFRealCon arg) */

SDFLayout SDFgetRealConWsAfterIntCon(SDFRealCon arg)
{
  if (SDFisRealConRealCon(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0);
  }

  ATabort("RealCon has no WsAfterIntCon: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFRealCon SDFsetRealConWsAfterIntCon(SDFRealCon arg, SDFLayout wsAfterIntCon) */

SDFRealCon SDFsetRealConWsAfterIntCon(SDFRealCon arg, SDFLayout wsAfterIntCon)
{
  if (SDFisRealConRealCon(arg)) {
    return (SDFRealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)wsAfterIntCon, 0), 1), 2);
  }

  ATabort("RealCon has no WsAfterIntCon: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasRealConOptExp(SDFRealCon arg) */

ATbool SDFhasRealConOptExp(SDFRealCon arg)
{
  if (SDFisRealConRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFOptExp SDFgetRealConOptExp(SDFRealCon arg) */

SDFOptExp SDFgetRealConOptExp(SDFRealCon arg)
{
  if (SDFisRealConRealCon(arg)) {
    return (SDFOptExp)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 6);
  }

  ATabort("RealCon has no OptExp: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFRealCon SDFsetRealConOptExp(SDFRealCon arg, SDFOptExp optExp) */

SDFRealCon SDFsetRealConOptExp(SDFRealCon arg, SDFOptExp optExp)
{
  if (SDFisRealConRealCon(arg)) {
    return (SDFRealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)optExp, 6), 2);
  }

  ATabort("RealCon has no OptExp: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasRealConIntCon(SDFRealCon arg) */

ATbool SDFhasRealConIntCon(SDFRealCon arg)
{
  if (SDFisRealConRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFIntCon SDFgetRealConIntCon(SDFRealCon arg) */

SDFIntCon SDFgetRealConIntCon(SDFRealCon arg)
{
  if (SDFisRealConRealCon(arg)) {
    return (SDFIntCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("RealCon has no IntCon: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFRealCon SDFsetRealConIntCon(SDFRealCon arg, SDFIntCon intCon) */

SDFRealCon SDFsetRealConIntCon(SDFRealCon arg, SDFIntCon intCon)
{
  if (SDFisRealConRealCon(arg)) {
    return (SDFRealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)intCon, 0), 2);
  }

  ATabort("RealCon has no IntCon: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasRealConWsAfterNatCon(SDFRealCon arg) */

ATbool SDFhasRealConWsAfterNatCon(SDFRealCon arg)
{
  if (SDFisRealConRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFLayout SDFgetRealConWsAfterNatCon(SDFRealCon arg) */

SDFLayout SDFgetRealConWsAfterNatCon(SDFRealCon arg)
{
  if (SDFisRealConRealCon(arg)) {
    return (SDFLayout)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0);
  }

  ATabort("RealCon has no WsAfterNatCon: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFRealCon SDFsetRealConWsAfterNatCon(SDFRealCon arg, SDFLayout wsAfterNatCon) */

SDFRealCon SDFsetRealConWsAfterNatCon(SDFRealCon arg, SDFLayout wsAfterNatCon)
{
  if (SDFisRealConRealCon(arg)) {
    return (SDFRealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)wsAfterNatCon, 0), 5), 2);
  }

  ATabort("RealCon has no WsAfterNatCon: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool SDFhasRealConNatCon(SDFRealCon arg) */

ATbool SDFhasRealConNatCon(SDFRealCon arg)
{
  if (SDFisRealConRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDFNatCon SDFgetRealConNatCon(SDFRealCon arg) */

SDFNatCon SDFgetRealConNatCon(SDFRealCon arg)
{
  if (SDFisRealConRealCon(arg)) {
    return (SDFNatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("RealCon has no NatCon: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  SDFRealCon SDFsetRealConNatCon(SDFRealCon arg, SDFNatCon natCon) */

SDFRealCon SDFsetRealConNatCon(SDFRealCon arg, SDFNatCon natCon)
{
  if (SDFisRealConRealCon(arg)) {
    return (SDFRealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)natCon, 4), 2);
  }

  ATabort("RealCon has no NatCon: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
