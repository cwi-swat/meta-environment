#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "SDFME.h"

/*{{{  typedefs */

typedef struct ATerm _SDF_Grammar;
typedef struct ATerm _SDF_Alias;
typedef struct ATerm _SDF_Aliases;
typedef struct ATerm _SDF_AliasList;
typedef struct ATerm _SDF_Lookahead;
typedef struct ATerm _SDF_Lookaheads;
typedef struct ATerm _SDF_LookaheadList;
typedef struct ATerm _SDF_Restriction;
typedef struct ATerm _SDF_Restrictions;
typedef struct ATerm _SDF_RestrictionList;
typedef struct ATerm _SDF_Attribute;
typedef struct ATerm _SDF_Symbol;
typedef struct ATerm _SDF_Production;
typedef struct ATerm _SDF_SymbolArguments;
typedef struct ATerm _SDF_Sort;
typedef struct ATerm _SDF_SymbolParameters;
typedef struct ATerm _SDF_NumChar;
typedef struct ATerm _SDF_ShortChar;
typedef struct ATerm _SDF_Character;
typedef struct ATerm _SDF_CharRange;
typedef struct ATerm _SDF_CharRanges;
typedef struct ATerm _SDF_OptCharRanges;
typedef struct ATerm _SDF_CharClass;
typedef struct ATerm _SDF_Associativity;
typedef struct ATerm _SDF_Group;
typedef struct ATerm _SDF_Priority;
typedef struct ATerm _SDF_GroupList;
typedef struct ATerm _SDF_Priorities;
typedef struct ATerm _SDF_PriorityList;
typedef struct ATerm _SDF_SymbolTail;
typedef struct ATerm _SDF_SymbolRest;
typedef struct ATerm _SDF_Renamings;
typedef struct ATerm _SDF_RenamingList;
typedef struct ATerm _SDF_Renaming;
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
typedef struct ATerm _SDF_ImpSection;
typedef struct ATerm _SDF_Imports;
typedef struct ATerm _SDF_ImportList;
typedef struct ATerm _SDF_Import;
typedef struct ATerm _SDF_Symbols;
typedef struct ATerm _SDF_SymbolList;
typedef struct ATerm _SDF_OptExp;
typedef struct ATerm _SDF_RealCon;
typedef struct ATerm _SDF_NatCon;
typedef struct ATerm _SDF_IntCon;
typedef struct ATerm _SDF_AlphaNumericalEscChar;
typedef struct ATerm _SDF_DecimalEscChar;
typedef struct ATerm _SDF_EscChar;
typedef struct ATerm _SDF_LChar;
typedef struct ATerm _SDF_QLiteral;
typedef struct ATerm _SDF_UQLiteral;
typedef struct ATerm _SDF_Literal;
typedef struct ATerm _SDF_ATermList;
typedef struct ATerm _SDF_ATermElems;
typedef struct ATerm _SDF_ACon;
typedef struct ATerm _SDF_AFun;
typedef struct ATerm _SDF_ATerm;
typedef struct ATerm _SDF_ATermArgs;
typedef struct ATerm _SDF_Ann;
typedef struct ATerm _SDF_ATermAnnos;
typedef struct ATerm _SDF_Attributes;
typedef struct ATerm _SDF_AttributeList;
typedef struct ATerm _SDF_Productions;
typedef struct ATerm _SDF_ProductionList;
typedef struct ATerm _SDF_SDF;
typedef struct ATerm _SDF_OptLayout;
typedef struct ATerm _SDF_Start;

/*}}}  */

/*{{{  void SDF_initSDFMEApi(void) */

void SDF_initSDFMEApi(void)
{
  init_SDFME_dict();
}

/*}}}  */

/*{{{  term conversion functions */

/*{{{  SDF_Grammar SDF_GrammarFromTerm(ATerm t) */

SDF_Grammar SDF_GrammarFromTerm(ATerm t)
{
  return (SDF_Grammar)t;
}

/*}}}  */
/*{{{  ATerm SDF_GrammarToTerm(SDF_Grammar arg) */

ATerm SDF_GrammarToTerm(SDF_Grammar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Alias SDF_AliasFromTerm(ATerm t) */

SDF_Alias SDF_AliasFromTerm(ATerm t)
{
  return (SDF_Alias)t;
}

/*}}}  */
/*{{{  ATerm SDF_AliasToTerm(SDF_Alias arg) */

ATerm SDF_AliasToTerm(SDF_Alias arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Aliases SDF_AliasesFromTerm(ATerm t) */

SDF_Aliases SDF_AliasesFromTerm(ATerm t)
{
  return (SDF_Aliases)t;
}

/*}}}  */
/*{{{  ATerm SDF_AliasesToTerm(SDF_Aliases arg) */

ATerm SDF_AliasesToTerm(SDF_Aliases arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_AliasList SDF_AliasListFromTerm(ATerm t) */

SDF_AliasList SDF_AliasListFromTerm(ATerm t)
{
  return (SDF_AliasList)t;
}

/*}}}  */
/*{{{  ATerm SDF_AliasListToTerm(SDF_AliasList arg) */

ATerm SDF_AliasListToTerm(SDF_AliasList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_LookaheadFromTerm(ATerm t) */

SDF_Lookahead SDF_LookaheadFromTerm(ATerm t)
{
  return (SDF_Lookahead)t;
}

/*}}}  */
/*{{{  ATerm SDF_LookaheadToTerm(SDF_Lookahead arg) */

ATerm SDF_LookaheadToTerm(SDF_Lookahead arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_LookaheadsFromTerm(ATerm t) */

SDF_Lookaheads SDF_LookaheadsFromTerm(ATerm t)
{
  return (SDF_Lookaheads)t;
}

/*}}}  */
/*{{{  ATerm SDF_LookaheadsToTerm(SDF_Lookaheads arg) */

ATerm SDF_LookaheadsToTerm(SDF_Lookaheads arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_LookaheadList SDF_LookaheadListFromTerm(ATerm t) */

SDF_LookaheadList SDF_LookaheadListFromTerm(ATerm t)
{
  return (SDF_LookaheadList)t;
}

/*}}}  */
/*{{{  ATerm SDF_LookaheadListToTerm(SDF_LookaheadList arg) */

ATerm SDF_LookaheadListToTerm(SDF_LookaheadList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Restriction SDF_RestrictionFromTerm(ATerm t) */

SDF_Restriction SDF_RestrictionFromTerm(ATerm t)
{
  return (SDF_Restriction)t;
}

/*}}}  */
/*{{{  ATerm SDF_RestrictionToTerm(SDF_Restriction arg) */

ATerm SDF_RestrictionToTerm(SDF_Restriction arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Restrictions SDF_RestrictionsFromTerm(ATerm t) */

SDF_Restrictions SDF_RestrictionsFromTerm(ATerm t)
{
  return (SDF_Restrictions)t;
}

/*}}}  */
/*{{{  ATerm SDF_RestrictionsToTerm(SDF_Restrictions arg) */

ATerm SDF_RestrictionsToTerm(SDF_Restrictions arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_RestrictionList SDF_RestrictionListFromTerm(ATerm t) */

SDF_RestrictionList SDF_RestrictionListFromTerm(ATerm t)
{
  return (SDF_RestrictionList)t;
}

/*}}}  */
/*{{{  ATerm SDF_RestrictionListToTerm(SDF_RestrictionList arg) */

ATerm SDF_RestrictionListToTerm(SDF_RestrictionList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Attribute SDF_AttributeFromTerm(ATerm t) */

SDF_Attribute SDF_AttributeFromTerm(ATerm t)
{
  return (SDF_Attribute)t;
}

/*}}}  */
/*{{{  ATerm SDF_AttributeToTerm(SDF_Attribute arg) */

ATerm SDF_AttributeToTerm(SDF_Attribute arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_SymbolFromTerm(ATerm t) */

SDF_Symbol SDF_SymbolFromTerm(ATerm t)
{
  return (SDF_Symbol)t;
}

/*}}}  */
/*{{{  ATerm SDF_SymbolToTerm(SDF_Symbol arg) */

ATerm SDF_SymbolToTerm(SDF_Symbol arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Production SDF_ProductionFromTerm(ATerm t) */

SDF_Production SDF_ProductionFromTerm(ATerm t)
{
  return (SDF_Production)t;
}

/*}}}  */
/*{{{  ATerm SDF_ProductionToTerm(SDF_Production arg) */

ATerm SDF_ProductionToTerm(SDF_Production arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_SymbolArguments SDF_SymbolArgumentsFromTerm(ATerm t) */

SDF_SymbolArguments SDF_SymbolArgumentsFromTerm(ATerm t)
{
  return (SDF_SymbolArguments)t;
}

/*}}}  */
/*{{{  ATerm SDF_SymbolArgumentsToTerm(SDF_SymbolArguments arg) */

ATerm SDF_SymbolArgumentsToTerm(SDF_SymbolArguments arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Sort SDF_SortFromTerm(ATerm t) */

SDF_Sort SDF_SortFromTerm(ATerm t)
{
  return (SDF_Sort)t;
}

/*}}}  */
/*{{{  ATerm SDF_SortToTerm(SDF_Sort arg) */

ATerm SDF_SortToTerm(SDF_Sort arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_SymbolParameters SDF_SymbolParametersFromTerm(ATerm t) */

SDF_SymbolParameters SDF_SymbolParametersFromTerm(ATerm t)
{
  return (SDF_SymbolParameters)t;
}

/*}}}  */
/*{{{  ATerm SDF_SymbolParametersToTerm(SDF_SymbolParameters arg) */

ATerm SDF_SymbolParametersToTerm(SDF_SymbolParameters arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_NumChar SDF_NumCharFromTerm(ATerm t) */

SDF_NumChar SDF_NumCharFromTerm(ATerm t)
{
  return (SDF_NumChar)t;
}

/*}}}  */
/*{{{  ATerm SDF_NumCharToTerm(SDF_NumChar arg) */

ATerm SDF_NumCharToTerm(SDF_NumChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ShortChar SDF_ShortCharFromTerm(ATerm t) */

SDF_ShortChar SDF_ShortCharFromTerm(ATerm t)
{
  return (SDF_ShortChar)t;
}

/*}}}  */
/*{{{  ATerm SDF_ShortCharToTerm(SDF_ShortChar arg) */

ATerm SDF_ShortCharToTerm(SDF_ShortChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Character SDF_CharacterFromTerm(ATerm t) */

SDF_Character SDF_CharacterFromTerm(ATerm t)
{
  return (SDF_Character)t;
}

/*}}}  */
/*{{{  ATerm SDF_CharacterToTerm(SDF_Character arg) */

ATerm SDF_CharacterToTerm(SDF_Character arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_CharRange SDF_CharRangeFromTerm(ATerm t) */

SDF_CharRange SDF_CharRangeFromTerm(ATerm t)
{
  return (SDF_CharRange)t;
}

/*}}}  */
/*{{{  ATerm SDF_CharRangeToTerm(SDF_CharRange arg) */

ATerm SDF_CharRangeToTerm(SDF_CharRange arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_CharRangesFromTerm(ATerm t) */

SDF_CharRanges SDF_CharRangesFromTerm(ATerm t)
{
  return (SDF_CharRanges)t;
}

/*}}}  */
/*{{{  ATerm SDF_CharRangesToTerm(SDF_CharRanges arg) */

ATerm SDF_CharRangesToTerm(SDF_CharRanges arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_OptCharRanges SDF_OptCharRangesFromTerm(ATerm t) */

SDF_OptCharRanges SDF_OptCharRangesFromTerm(ATerm t)
{
  return (SDF_OptCharRanges)t;
}

/*}}}  */
/*{{{  ATerm SDF_OptCharRangesToTerm(SDF_OptCharRanges arg) */

ATerm SDF_OptCharRangesToTerm(SDF_OptCharRanges arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_CharClassFromTerm(ATerm t) */

SDF_CharClass SDF_CharClassFromTerm(ATerm t)
{
  return (SDF_CharClass)t;
}

/*}}}  */
/*{{{  ATerm SDF_CharClassToTerm(SDF_CharClass arg) */

ATerm SDF_CharClassToTerm(SDF_CharClass arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Associativity SDF_AssociativityFromTerm(ATerm t) */

SDF_Associativity SDF_AssociativityFromTerm(ATerm t)
{
  return (SDF_Associativity)t;
}

/*}}}  */
/*{{{  ATerm SDF_AssociativityToTerm(SDF_Associativity arg) */

ATerm SDF_AssociativityToTerm(SDF_Associativity arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Group SDF_GroupFromTerm(ATerm t) */

SDF_Group SDF_GroupFromTerm(ATerm t)
{
  return (SDF_Group)t;
}

/*}}}  */
/*{{{  ATerm SDF_GroupToTerm(SDF_Group arg) */

ATerm SDF_GroupToTerm(SDF_Group arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Priority SDF_PriorityFromTerm(ATerm t) */

SDF_Priority SDF_PriorityFromTerm(ATerm t)
{
  return (SDF_Priority)t;
}

/*}}}  */
/*{{{  ATerm SDF_PriorityToTerm(SDF_Priority arg) */

ATerm SDF_PriorityToTerm(SDF_Priority arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_GroupList SDF_GroupListFromTerm(ATerm t) */

SDF_GroupList SDF_GroupListFromTerm(ATerm t)
{
  return (SDF_GroupList)t;
}

/*}}}  */
/*{{{  ATerm SDF_GroupListToTerm(SDF_GroupList arg) */

ATerm SDF_GroupListToTerm(SDF_GroupList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Priorities SDF_PrioritiesFromTerm(ATerm t) */

SDF_Priorities SDF_PrioritiesFromTerm(ATerm t)
{
  return (SDF_Priorities)t;
}

/*}}}  */
/*{{{  ATerm SDF_PrioritiesToTerm(SDF_Priorities arg) */

ATerm SDF_PrioritiesToTerm(SDF_Priorities arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_PriorityList SDF_PriorityListFromTerm(ATerm t) */

SDF_PriorityList SDF_PriorityListFromTerm(ATerm t)
{
  return (SDF_PriorityList)t;
}

/*}}}  */
/*{{{  ATerm SDF_PriorityListToTerm(SDF_PriorityList arg) */

ATerm SDF_PriorityListToTerm(SDF_PriorityList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_SymbolTail SDF_SymbolTailFromTerm(ATerm t) */

SDF_SymbolTail SDF_SymbolTailFromTerm(ATerm t)
{
  return (SDF_SymbolTail)t;
}

/*}}}  */
/*{{{  ATerm SDF_SymbolTailToTerm(SDF_SymbolTail arg) */

ATerm SDF_SymbolTailToTerm(SDF_SymbolTail arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_SymbolRest SDF_SymbolRestFromTerm(ATerm t) */

SDF_SymbolRest SDF_SymbolRestFromTerm(ATerm t)
{
  return (SDF_SymbolRest)t;
}

/*}}}  */
/*{{{  ATerm SDF_SymbolRestToTerm(SDF_SymbolRest arg) */

ATerm SDF_SymbolRestToTerm(SDF_SymbolRest arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Renamings SDF_RenamingsFromTerm(ATerm t) */

SDF_Renamings SDF_RenamingsFromTerm(ATerm t)
{
  return (SDF_Renamings)t;
}

/*}}}  */
/*{{{  ATerm SDF_RenamingsToTerm(SDF_Renamings arg) */

ATerm SDF_RenamingsToTerm(SDF_Renamings arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_RenamingList SDF_RenamingListFromTerm(ATerm t) */

SDF_RenamingList SDF_RenamingListFromTerm(ATerm t)
{
  return (SDF_RenamingList)t;
}

/*}}}  */
/*{{{  ATerm SDF_RenamingListToTerm(SDF_RenamingList arg) */

ATerm SDF_RenamingListToTerm(SDF_RenamingList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Renaming SDF_RenamingFromTerm(ATerm t) */

SDF_Renaming SDF_RenamingFromTerm(ATerm t)
{
  return (SDF_Renaming)t;
}

/*}}}  */
/*{{{  ATerm SDF_RenamingToTerm(SDF_Renaming arg) */

ATerm SDF_RenamingToTerm(SDF_Renaming arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ModuleWord SDF_ModuleWordFromTerm(ATerm t) */

SDF_ModuleWord SDF_ModuleWordFromTerm(ATerm t)
{
  return (SDF_ModuleWord)t;
}

/*}}}  */
/*{{{  ATerm SDF_ModuleWordToTerm(SDF_ModuleWord arg) */

ATerm SDF_ModuleWordToTerm(SDF_ModuleWord arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ModuleId SDF_ModuleIdFromTerm(ATerm t) */

SDF_ModuleId SDF_ModuleIdFromTerm(ATerm t)
{
  return (SDF_ModuleId)t;
}

/*}}}  */
/*{{{  ATerm SDF_ModuleIdToTerm(SDF_ModuleId arg) */

ATerm SDF_ModuleIdToTerm(SDF_ModuleId arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Definition SDF_DefinitionFromTerm(ATerm t) */

SDF_Definition SDF_DefinitionFromTerm(ATerm t)
{
  return (SDF_Definition)t;
}

/*}}}  */
/*{{{  ATerm SDF_DefinitionToTerm(SDF_Definition arg) */

ATerm SDF_DefinitionToTerm(SDF_Definition arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ModuleList SDF_ModuleListFromTerm(ATerm t) */

SDF_ModuleList SDF_ModuleListFromTerm(ATerm t)
{
  return (SDF_ModuleList)t;
}

/*}}}  */
/*{{{  ATerm SDF_ModuleListToTerm(SDF_ModuleList arg) */

ATerm SDF_ModuleListToTerm(SDF_ModuleList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Module SDF_ModuleFromTerm(ATerm t) */

SDF_Module SDF_ModuleFromTerm(ATerm t)
{
  return (SDF_Module)t;
}

/*}}}  */
/*{{{  ATerm SDF_ModuleToTerm(SDF_Module arg) */

ATerm SDF_ModuleToTerm(SDF_Module arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ImpSectionList SDF_ImpSectionListFromTerm(ATerm t) */

SDF_ImpSectionList SDF_ImpSectionListFromTerm(ATerm t)
{
  return (SDF_ImpSectionList)t;
}

/*}}}  */
/*{{{  ATerm SDF_ImpSectionListToTerm(SDF_ImpSectionList arg) */

ATerm SDF_ImpSectionListToTerm(SDF_ImpSectionList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Section SDF_SectionFromTerm(ATerm t) */

SDF_Section SDF_SectionFromTerm(ATerm t)
{
  return (SDF_Section)t;
}

/*}}}  */
/*{{{  ATerm SDF_SectionToTerm(SDF_Section arg) */

ATerm SDF_SectionToTerm(SDF_Section arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Sections SDF_SectionsFromTerm(ATerm t) */

SDF_Sections SDF_SectionsFromTerm(ATerm t)
{
  return (SDF_Sections)t;
}

/*}}}  */
/*{{{  ATerm SDF_SectionsToTerm(SDF_Sections arg) */

ATerm SDF_SectionsToTerm(SDF_Sections arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_SectionList SDF_SectionListFromTerm(ATerm t) */

SDF_SectionList SDF_SectionListFromTerm(ATerm t)
{
  return (SDF_SectionList)t;
}

/*}}}  */
/*{{{  ATerm SDF_SectionListToTerm(SDF_SectionList arg) */

ATerm SDF_SectionListToTerm(SDF_SectionList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_ModuleNameFromTerm(ATerm t) */

SDF_ModuleName SDF_ModuleNameFromTerm(ATerm t)
{
  return (SDF_ModuleName)t;
}

/*}}}  */
/*{{{  ATerm SDF_ModuleNameToTerm(SDF_ModuleName arg) */

ATerm SDF_ModuleNameToTerm(SDF_ModuleName arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ImpSection SDF_ImpSectionFromTerm(ATerm t) */

SDF_ImpSection SDF_ImpSectionFromTerm(ATerm t)
{
  return (SDF_ImpSection)t;
}

/*}}}  */
/*{{{  ATerm SDF_ImpSectionToTerm(SDF_ImpSection arg) */

ATerm SDF_ImpSectionToTerm(SDF_ImpSection arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Imports SDF_ImportsFromTerm(ATerm t) */

SDF_Imports SDF_ImportsFromTerm(ATerm t)
{
  return (SDF_Imports)t;
}

/*}}}  */
/*{{{  ATerm SDF_ImportsToTerm(SDF_Imports arg) */

ATerm SDF_ImportsToTerm(SDF_Imports arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ImportList SDF_ImportListFromTerm(ATerm t) */

SDF_ImportList SDF_ImportListFromTerm(ATerm t)
{
  return (SDF_ImportList)t;
}

/*}}}  */
/*{{{  ATerm SDF_ImportListToTerm(SDF_ImportList arg) */

ATerm SDF_ImportListToTerm(SDF_ImportList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Import SDF_ImportFromTerm(ATerm t) */

SDF_Import SDF_ImportFromTerm(ATerm t)
{
  return (SDF_Import)t;
}

/*}}}  */
/*{{{  ATerm SDF_ImportToTerm(SDF_Import arg) */

ATerm SDF_ImportToTerm(SDF_Import arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Symbols SDF_SymbolsFromTerm(ATerm t) */

SDF_Symbols SDF_SymbolsFromTerm(ATerm t)
{
  return (SDF_Symbols)t;
}

/*}}}  */
/*{{{  ATerm SDF_SymbolsToTerm(SDF_Symbols arg) */

ATerm SDF_SymbolsToTerm(SDF_Symbols arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_SymbolList SDF_SymbolListFromTerm(ATerm t) */

SDF_SymbolList SDF_SymbolListFromTerm(ATerm t)
{
  return (SDF_SymbolList)t;
}

/*}}}  */
/*{{{  ATerm SDF_SymbolListToTerm(SDF_SymbolList arg) */

ATerm SDF_SymbolListToTerm(SDF_SymbolList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_OptExp SDF_OptExpFromTerm(ATerm t) */

SDF_OptExp SDF_OptExpFromTerm(ATerm t)
{
  return (SDF_OptExp)t;
}

/*}}}  */
/*{{{  ATerm SDF_OptExpToTerm(SDF_OptExp arg) */

ATerm SDF_OptExpToTerm(SDF_OptExp arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_RealCon SDF_RealConFromTerm(ATerm t) */

SDF_RealCon SDF_RealConFromTerm(ATerm t)
{
  return (SDF_RealCon)t;
}

/*}}}  */
/*{{{  ATerm SDF_RealConToTerm(SDF_RealCon arg) */

ATerm SDF_RealConToTerm(SDF_RealCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_NatCon SDF_NatConFromTerm(ATerm t) */

SDF_NatCon SDF_NatConFromTerm(ATerm t)
{
  return (SDF_NatCon)t;
}

/*}}}  */
/*{{{  ATerm SDF_NatConToTerm(SDF_NatCon arg) */

ATerm SDF_NatConToTerm(SDF_NatCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_IntCon SDF_IntConFromTerm(ATerm t) */

SDF_IntCon SDF_IntConFromTerm(ATerm t)
{
  return (SDF_IntCon)t;
}

/*}}}  */
/*{{{  ATerm SDF_IntConToTerm(SDF_IntCon arg) */

ATerm SDF_IntConToTerm(SDF_IntCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_AlphaNumericalEscChar SDF_AlphaNumericalEscCharFromTerm(ATerm t) */

SDF_AlphaNumericalEscChar SDF_AlphaNumericalEscCharFromTerm(ATerm t)
{
  return (SDF_AlphaNumericalEscChar)t;
}

/*}}}  */
/*{{{  ATerm SDF_AlphaNumericalEscCharToTerm(SDF_AlphaNumericalEscChar arg) */

ATerm SDF_AlphaNumericalEscCharToTerm(SDF_AlphaNumericalEscChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_DecimalEscChar SDF_DecimalEscCharFromTerm(ATerm t) */

SDF_DecimalEscChar SDF_DecimalEscCharFromTerm(ATerm t)
{
  return (SDF_DecimalEscChar)t;
}

/*}}}  */
/*{{{  ATerm SDF_DecimalEscCharToTerm(SDF_DecimalEscChar arg) */

ATerm SDF_DecimalEscCharToTerm(SDF_DecimalEscChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_EscChar SDF_EscCharFromTerm(ATerm t) */

SDF_EscChar SDF_EscCharFromTerm(ATerm t)
{
  return (SDF_EscChar)t;
}

/*}}}  */
/*{{{  ATerm SDF_EscCharToTerm(SDF_EscChar arg) */

ATerm SDF_EscCharToTerm(SDF_EscChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_LChar SDF_LCharFromTerm(ATerm t) */

SDF_LChar SDF_LCharFromTerm(ATerm t)
{
  return (SDF_LChar)t;
}

/*}}}  */
/*{{{  ATerm SDF_LCharToTerm(SDF_LChar arg) */

ATerm SDF_LCharToTerm(SDF_LChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_QLiteral SDF_QLiteralFromTerm(ATerm t) */

SDF_QLiteral SDF_QLiteralFromTerm(ATerm t)
{
  return (SDF_QLiteral)t;
}

/*}}}  */
/*{{{  ATerm SDF_QLiteralToTerm(SDF_QLiteral arg) */

ATerm SDF_QLiteralToTerm(SDF_QLiteral arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_UQLiteral SDF_UQLiteralFromTerm(ATerm t) */

SDF_UQLiteral SDF_UQLiteralFromTerm(ATerm t)
{
  return (SDF_UQLiteral)t;
}

/*}}}  */
/*{{{  ATerm SDF_UQLiteralToTerm(SDF_UQLiteral arg) */

ATerm SDF_UQLiteralToTerm(SDF_UQLiteral arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Literal SDF_LiteralFromTerm(ATerm t) */

SDF_Literal SDF_LiteralFromTerm(ATerm t)
{
  return (SDF_Literal)t;
}

/*}}}  */
/*{{{  ATerm SDF_LiteralToTerm(SDF_Literal arg) */

ATerm SDF_LiteralToTerm(SDF_Literal arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ATermList SDF_ATermListFromTerm(ATerm t) */

SDF_ATermList SDF_ATermListFromTerm(ATerm t)
{
  return (SDF_ATermList)t;
}

/*}}}  */
/*{{{  ATerm SDF_ATermListToTerm(SDF_ATermList arg) */

ATerm SDF_ATermListToTerm(SDF_ATermList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ATermElems SDF_ATermElemsFromTerm(ATerm t) */

SDF_ATermElems SDF_ATermElemsFromTerm(ATerm t)
{
  return (SDF_ATermElems)t;
}

/*}}}  */
/*{{{  ATerm SDF_ATermElemsToTerm(SDF_ATermElems arg) */

ATerm SDF_ATermElemsToTerm(SDF_ATermElems arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ACon SDF_AConFromTerm(ATerm t) */

SDF_ACon SDF_AConFromTerm(ATerm t)
{
  return (SDF_ACon)t;
}

/*}}}  */
/*{{{  ATerm SDF_AConToTerm(SDF_ACon arg) */

ATerm SDF_AConToTerm(SDF_ACon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_AFun SDF_AFunFromTerm(ATerm t) */

SDF_AFun SDF_AFunFromTerm(ATerm t)
{
  return (SDF_AFun)t;
}

/*}}}  */
/*{{{  ATerm SDF_AFunToTerm(SDF_AFun arg) */

ATerm SDF_AFunToTerm(SDF_AFun arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_ATermFromTerm(ATerm t) */

SDF_ATerm SDF_ATermFromTerm(ATerm t)
{
  return (SDF_ATerm)t;
}

/*}}}  */
/*{{{  ATerm SDF_ATermToTerm(SDF_ATerm arg) */

ATerm SDF_ATermToTerm(SDF_ATerm arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ATermArgs SDF_ATermArgsFromTerm(ATerm t) */

SDF_ATermArgs SDF_ATermArgsFromTerm(ATerm t)
{
  return (SDF_ATermArgs)t;
}

/*}}}  */
/*{{{  ATerm SDF_ATermArgsToTerm(SDF_ATermArgs arg) */

ATerm SDF_ATermArgsToTerm(SDF_ATermArgs arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Ann SDF_AnnFromTerm(ATerm t) */

SDF_Ann SDF_AnnFromTerm(ATerm t)
{
  return (SDF_Ann)t;
}

/*}}}  */
/*{{{  ATerm SDF_AnnToTerm(SDF_Ann arg) */

ATerm SDF_AnnToTerm(SDF_Ann arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ATermAnnos SDF_ATermAnnosFromTerm(ATerm t) */

SDF_ATermAnnos SDF_ATermAnnosFromTerm(ATerm t)
{
  return (SDF_ATermAnnos)t;
}

/*}}}  */
/*{{{  ATerm SDF_ATermAnnosToTerm(SDF_ATermAnnos arg) */

ATerm SDF_ATermAnnosToTerm(SDF_ATermAnnos arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Attributes SDF_AttributesFromTerm(ATerm t) */

SDF_Attributes SDF_AttributesFromTerm(ATerm t)
{
  return (SDF_Attributes)t;
}

/*}}}  */
/*{{{  ATerm SDF_AttributesToTerm(SDF_Attributes arg) */

ATerm SDF_AttributesToTerm(SDF_Attributes arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_AttributeList SDF_AttributeListFromTerm(ATerm t) */

SDF_AttributeList SDF_AttributeListFromTerm(ATerm t)
{
  return (SDF_AttributeList)t;
}

/*}}}  */
/*{{{  ATerm SDF_AttributeListToTerm(SDF_AttributeList arg) */

ATerm SDF_AttributeListToTerm(SDF_AttributeList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Productions SDF_ProductionsFromTerm(ATerm t) */

SDF_Productions SDF_ProductionsFromTerm(ATerm t)
{
  return (SDF_Productions)t;
}

/*}}}  */
/*{{{  ATerm SDF_ProductionsToTerm(SDF_Productions arg) */

ATerm SDF_ProductionsToTerm(SDF_Productions arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_ProductionList SDF_ProductionListFromTerm(ATerm t) */

SDF_ProductionList SDF_ProductionListFromTerm(ATerm t)
{
  return (SDF_ProductionList)t;
}

/*}}}  */
/*{{{  ATerm SDF_ProductionListToTerm(SDF_ProductionList arg) */

ATerm SDF_ProductionListToTerm(SDF_ProductionList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_SDF SDF_SDFFromTerm(ATerm t) */

SDF_SDF SDF_SDFFromTerm(ATerm t)
{
  return (SDF_SDF)t;
}

/*}}}  */
/*{{{  ATerm SDF_SDFToTerm(SDF_SDF arg) */

ATerm SDF_SDFToTerm(SDF_SDF arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_OptLayoutFromTerm(ATerm t) */

SDF_OptLayout SDF_OptLayoutFromTerm(ATerm t)
{
  return (SDF_OptLayout)t;
}

/*}}}  */
/*{{{  ATerm SDF_OptLayoutToTerm(SDF_OptLayout arg) */

ATerm SDF_OptLayoutToTerm(SDF_OptLayout arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SDF_Start SDF_StartFromTerm(ATerm t) */

SDF_Start SDF_StartFromTerm(ATerm t)
{
  return (SDF_Start)t;
}

/*}}}  */
/*{{{  ATerm SDF_StartToTerm(SDF_Start arg) */

ATerm SDF_StartToTerm(SDF_Start arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  constructors */

/*{{{  SDF_Grammar SDF_makeGrammarAliases(SDF_OptLayout wsAfterAliases, SDF_Aliases Aliases) */

SDF_Grammar SDF_makeGrammarAliases(SDF_OptLayout wsAfterAliases, SDF_Aliases Aliases)
{
  return (SDF_Grammar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun4)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun8))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun9))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun8)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)Aliases), (ATerm)wsAfterAliases), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun8))));
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarRestrictions(SDF_OptLayout wsAfterRestrictions, SDF_Restrictions Restrictions) */

SDF_Grammar SDF_makeGrammarRestrictions(SDF_OptLayout wsAfterRestrictions, SDF_Restrictions Restrictions)
{
  return (SDF_Grammar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun13)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun14))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun9))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun14)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)Restrictions), (ATerm)wsAfterRestrictions), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun14))));
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarSorts(SDF_OptLayout wsAfterSorts, SDF_Symbols Symbols) */

SDF_Grammar SDF_makeGrammarSorts(SDF_OptLayout wsAfterSorts, SDF_Symbols Symbols)
{
  return (SDF_Grammar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun15)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun16))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun9))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun16)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)Symbols), (ATerm)wsAfterSorts), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun16))));
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarPriorities(SDF_OptLayout wsAfterPriorities, SDF_Priorities Priorities) */

SDF_Grammar SDF_makeGrammarPriorities(SDF_OptLayout wsAfterPriorities, SDF_Priorities Priorities)
{
  return (SDF_Grammar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun17)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun18))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun9))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun18)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)Priorities), (ATerm)wsAfterPriorities), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun18))));
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarImpSection(SDF_ImpSection ImpSection) */

SDF_Grammar SDF_makeGrammarImpSection(SDF_ImpSection ImpSection)
{
  return (SDF_Grammar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun19)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun9))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun20)))))), (ATerm)ATmakeList1((ATerm)ImpSection));
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarLexicalSyntax(SDF_OptLayout wsAfterLexical, SDF_OptLayout wsAfterSyntax, SDF_Productions Productions) */

SDF_Grammar SDF_makeGrammarLexicalSyntax(SDF_OptLayout wsAfterLexical, SDF_OptLayout wsAfterSyntax, SDF_Productions Productions)
{
  return (SDF_Grammar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun21)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun22))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun23))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun9))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun24)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)Productions), (ATerm)wsAfterSyntax), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun22))), (ATerm)wsAfterLexical), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun23))));
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarContextFreeSyntax(SDF_OptLayout wsAfterContextFree, SDF_OptLayout wsAfterSyntax, SDF_Productions Productions) */

SDF_Grammar SDF_makeGrammarContextFreeSyntax(SDF_OptLayout wsAfterContextFree, SDF_OptLayout wsAfterSyntax, SDF_Productions Productions)
{
  return (SDF_Grammar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun21)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun22))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun25))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun9))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun26)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)Productions), (ATerm)wsAfterSyntax), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun22))), (ATerm)wsAfterContextFree), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun25))));
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarVariables(SDF_OptLayout wsAfterVariables, SDF_Productions Productions) */

SDF_Grammar SDF_makeGrammarVariables(SDF_OptLayout wsAfterVariables, SDF_Productions Productions)
{
  return (SDF_Grammar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun21)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun27))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun9))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun27)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)Productions), (ATerm)wsAfterVariables), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun27))));
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarLexicalVariables(SDF_OptLayout wsAfterLexical, SDF_OptLayout wsAfterVariables, SDF_Productions Productions) */

SDF_Grammar SDF_makeGrammarLexicalVariables(SDF_OptLayout wsAfterLexical, SDF_OptLayout wsAfterVariables, SDF_Productions Productions)
{
  return (SDF_Grammar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun21)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun27))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun23))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun9))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun28)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)Productions), (ATerm)wsAfterVariables), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun27))), (ATerm)wsAfterLexical), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun23))));
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarEmptyGrammar() */

SDF_Grammar SDF_makeGrammarEmptyGrammar()
{
  return (SDF_Grammar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun29))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun9))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun30)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun29))));
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarConcGrammars(SDF_Grammar left, SDF_OptLayout wsAfterLeft, SDF_Grammar right) */

SDF_Grammar SDF_makeGrammarConcGrammars(SDF_Grammar left, SDF_OptLayout wsAfterLeft, SDF_Grammar right)
{
  return (SDF_Grammar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun9)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun9)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun9))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun31)))), (ATerm)ATmakeAppl1(SDF_afun32, (ATerm)ATmakeAppl0(SDF_afun33))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)right), (ATerm)wsAfterLeft), (ATerm)left));
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarBracket(SDF_OptLayout wsAfterParenOpen, SDF_Grammar Grammar, SDF_OptLayout wsAfterGrammar) */

SDF_Grammar SDF_makeGrammarBracket(SDF_OptLayout wsAfterParenOpen, SDF_Grammar Grammar, SDF_OptLayout wsAfterGrammar)
{
  return (SDF_Grammar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun9)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun9))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl0(SDF_afun36)))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)wsAfterGrammar), (ATerm)Grammar), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))));
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarSyntax(SDF_OptLayout wsAfterSyntax, SDF_Productions Productions) */

SDF_Grammar SDF_makeGrammarSyntax(SDF_OptLayout wsAfterSyntax, SDF_Productions Productions)
{
  return (SDF_Grammar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun21)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun22))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun9))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun22)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)Productions), (ATerm)wsAfterSyntax), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun22))));
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarLexicalPriorities(SDF_OptLayout wsAfterLexical, SDF_OptLayout wsAfterPriorities, SDF_Priorities Priorities) */

SDF_Grammar SDF_makeGrammarLexicalPriorities(SDF_OptLayout wsAfterLexical, SDF_OptLayout wsAfterPriorities, SDF_Priorities Priorities)
{
  return (SDF_Grammar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun17)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun18))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun23))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun9))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun37)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)Priorities), (ATerm)wsAfterPriorities), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun18))), (ATerm)wsAfterLexical), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun23))));
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarContextFreePriorities(SDF_OptLayout wsAfterContextFree, SDF_OptLayout wsAfterPriorities, SDF_Priorities Priorities) */

SDF_Grammar SDF_makeGrammarContextFreePriorities(SDF_OptLayout wsAfterContextFree, SDF_OptLayout wsAfterPriorities, SDF_Priorities Priorities)
{
  return (SDF_Grammar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun17)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun18))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun25))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun9))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun38)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)Priorities), (ATerm)wsAfterPriorities), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun18))), (ATerm)wsAfterContextFree), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun25))));
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarLexicalRestrictions(SDF_OptLayout wsAfterLexical, SDF_OptLayout wsAfterRestrictions, SDF_Restrictions Restrictions) */

SDF_Grammar SDF_makeGrammarLexicalRestrictions(SDF_OptLayout wsAfterLexical, SDF_OptLayout wsAfterRestrictions, SDF_Restrictions Restrictions)
{
  return (SDF_Grammar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun13)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun14))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun23))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun9))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun39)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)Restrictions), (ATerm)wsAfterRestrictions), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun14))), (ATerm)wsAfterLexical), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun23))));
}

/*}}}  */
/*{{{  SDF_Grammar SDF_makeGrammarContextFreeRestrictions(SDF_OptLayout wsAfterContextFree, SDF_OptLayout wsAfterRestrictions, SDF_Restrictions Restrictions) */

SDF_Grammar SDF_makeGrammarContextFreeRestrictions(SDF_OptLayout wsAfterContextFree, SDF_OptLayout wsAfterRestrictions, SDF_Restrictions Restrictions)
{
  return (SDF_Grammar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun13)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun14))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun25))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun9))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun40)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)Restrictions), (ATerm)wsAfterRestrictions), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun14))), (ATerm)wsAfterContextFree), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun25))));
}

/*}}}  */
/*{{{  SDF_Alias SDF_makeAliasAlias(SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol, SDF_OptLayout wsAfterArrow, SDF_Symbol alias) */

SDF_Alias SDF_makeAliasAlias(SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol, SDF_OptLayout wsAfterArrow, SDF_Symbol alias)
{
  return (SDF_Alias)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun42))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun43))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun44)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)alias), (ATerm)wsAfterArrow), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun42))), (ATerm)wsAfterSymbol), (ATerm)Symbol));
}

/*}}}  */
/*{{{  SDF_Aliases SDF_makeAliasesDefault(SDF_AliasList list) */

SDF_Aliases SDF_makeAliasesDefault(SDF_AliasList list)
{
  return (SDF_Aliases)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun43))))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun4))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun43))))), (ATerm)list)));
}

/*}}}  */
/*{{{  SDF_AliasList SDF_makeAliasListEmpty() */

SDF_AliasList SDF_makeAliasListEmpty()
{
  return (SDF_AliasList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  SDF_AliasList SDF_makeAliasListSingle(SDF_Alias head) */

SDF_AliasList SDF_makeAliasListSingle(SDF_Alias head)
{
  return (SDF_AliasList)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  SDF_AliasList SDF_makeAliasListMany(SDF_Alias head, SDF_OptLayout wsAfterFirst, SDF_AliasList tail) */

SDF_AliasList SDF_makeAliasListMany(SDF_Alias head, SDF_OptLayout wsAfterFirst, SDF_AliasList tail)
{
  return (SDF_AliasList)(ATerm)ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_makeLookaheadCharClass(SDF_CharClass CharClass) */

SDF_Lookahead SDF_makeLookaheadCharClass(SDF_CharClass CharClass)
{
  return (SDF_Lookahead)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun48)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun49))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun50)))))), (ATerm)ATmakeList1((ATerm)CharClass));
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_makeLookaheadSeq(SDF_CharClass head, SDF_OptLayout wsAfterHead, SDF_OptLayout wsAfterPeriod, SDF_Lookaheads tail) */

SDF_Lookahead SDF_makeLookaheadSeq(SDF_CharClass head, SDF_OptLayout wsAfterHead, SDF_OptLayout wsAfterPeriod, SDF_Lookaheads tail)
{
  return (SDF_Lookahead)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun51)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun52))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun48)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun49))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun53)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)tail), (ATerm)wsAfterPeriod), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun52))), (ATerm)wsAfterHead), (ATerm)head));
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_makeLookaheadsSingle(SDF_Lookahead Lookahead) */

SDF_Lookaheads SDF_makeLookaheadsSingle(SDF_Lookahead Lookahead)
{
  return (SDF_Lookaheads)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun49)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun51))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun54)))))), (ATerm)ATmakeList1((ATerm)Lookahead));
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_makeLookaheadsAlt(SDF_Lookaheads left, SDF_OptLayout wsAfterLeft, SDF_OptLayout wsAfterBar, SDF_Lookaheads right) */

SDF_Lookaheads SDF_makeLookaheadsAlt(SDF_Lookaheads left, SDF_OptLayout wsAfterLeft, SDF_OptLayout wsAfterBar, SDF_Lookaheads right)
{
  return (SDF_Lookaheads)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun51)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun55))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun51)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun51))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun32, (ATerm)ATmakeAppl0(SDF_afun56))), (ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun57)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)right), (ATerm)wsAfterBar), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun55))), (ATerm)wsAfterLeft), (ATerm)left));
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_makeLookaheadsBracket(SDF_OptLayout wsAfterParenOpen, SDF_Lookaheads Lookaheads, SDF_OptLayout wsAfterLookaheads) */

SDF_Lookaheads SDF_makeLookaheadsBracket(SDF_OptLayout wsAfterParenOpen, SDF_Lookaheads Lookaheads, SDF_OptLayout wsAfterLookaheads)
{
  return (SDF_Lookaheads)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun51)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun51))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl0(SDF_afun36)))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)wsAfterLookaheads), (ATerm)Lookaheads), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))));
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_makeLookaheadsList(SDF_OptLayout wsAfterBracketOpenBracketOpen, SDF_LookaheadList list, SDF_OptLayout wsAfterList) */

SDF_Lookaheads SDF_makeLookaheadsList(SDF_OptLayout wsAfterBracketOpenBracketOpen, SDF_LookaheadList list, SDF_OptLayout wsAfterList)
{
  return (SDF_Lookaheads)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun58))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl2(SDF_afun59, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun49)), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun60))))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun61))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun51))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun62)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun58))), (ATerm)wsAfterList), (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl2(SDF_afun59, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun49)), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun60))))), (ATerm)list)), (ATerm)wsAfterBracketOpenBracketOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun61))));
}

/*}}}  */
/*{{{  SDF_LookaheadList SDF_makeLookaheadListEmpty() */

SDF_LookaheadList SDF_makeLookaheadListEmpty()
{
  return (SDF_LookaheadList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  SDF_LookaheadList SDF_makeLookaheadListSingle(SDF_Lookahead head) */

SDF_LookaheadList SDF_makeLookaheadListSingle(SDF_Lookahead head)
{
  return (SDF_LookaheadList)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  SDF_LookaheadList SDF_makeLookaheadListMany(SDF_Lookahead head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_LookaheadList tail) */

SDF_LookaheadList SDF_makeLookaheadListMany(SDF_Lookahead head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_LookaheadList tail)
{
  return (SDF_LookaheadList)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterSep), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  SDF_Restriction SDF_makeRestrictionFollow(SDF_Symbols Symbols, SDF_OptLayout wsAfterSymbols, SDF_OptLayout wsAfterSlash, SDF_Lookaheads Lookaheads) */

SDF_Restriction SDF_makeRestrictionFollow(SDF_Symbols Symbols, SDF_OptLayout wsAfterSymbols, SDF_OptLayout wsAfterSlash, SDF_Lookaheads Lookaheads)
{
  return (SDF_Restriction)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun51)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun63))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun15)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun64))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun65)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)Lookaheads), (ATerm)wsAfterSlash), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun63))), (ATerm)wsAfterSymbols), (ATerm)Symbols));
}

/*}}}  */
/*{{{  SDF_Restrictions SDF_makeRestrictionsDefault(SDF_RestrictionList list) */

SDF_Restrictions SDF_makeRestrictionsDefault(SDF_RestrictionList list)
{
  return (SDF_Restrictions)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun64))))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun13))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun64))))), (ATerm)list)));
}

/*}}}  */
/*{{{  SDF_RestrictionList SDF_makeRestrictionListEmpty() */

SDF_RestrictionList SDF_makeRestrictionListEmpty()
{
  return (SDF_RestrictionList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  SDF_RestrictionList SDF_makeRestrictionListSingle(SDF_Restriction head) */

SDF_RestrictionList SDF_makeRestrictionListSingle(SDF_Restriction head)
{
  return (SDF_RestrictionList)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  SDF_RestrictionList SDF_makeRestrictionListMany(SDF_Restriction head, SDF_OptLayout wsAfterFirst, SDF_RestrictionList tail) */

SDF_RestrictionList SDF_makeRestrictionListMany(SDF_Restriction head, SDF_OptLayout wsAfterFirst, SDF_RestrictionList tail)
{
  return (SDF_RestrictionList)(ATerm)ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  SDF_Attribute SDF_makeAttributeReject() */

SDF_Attribute SDF_makeAttributeReject()
{
  return (SDF_Attribute)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun66))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun67))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun66)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun66))));
}

/*}}}  */
/*{{{  SDF_Attribute SDF_makeAttributePrefer() */

SDF_Attribute SDF_makeAttributePrefer()
{
  return (SDF_Attribute)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun68))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun67))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun68)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun68))));
}

/*}}}  */
/*{{{  SDF_Attribute SDF_makeAttributeAvoid() */

SDF_Attribute SDF_makeAttributeAvoid()
{
  return (SDF_Attribute)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun69))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun67))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun69)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun69))));
}

/*}}}  */
/*{{{  SDF_Attribute SDF_makeAttributeBracket() */

SDF_Attribute SDF_makeAttributeBracket()
{
  return (SDF_Attribute)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun70))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun67))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun70)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun70))));
}

/*}}}  */
/*{{{  SDF_Attribute SDF_makeAttributeAssoc(SDF_Associativity Associativity) */

SDF_Attribute SDF_makeAttributeAssoc(SDF_Associativity Associativity)
{
  return (SDF_Attribute)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun71)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun67))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun72)))))), (ATerm)ATmakeList1((ATerm)Associativity));
}

/*}}}  */
/*{{{  SDF_Attribute SDF_makeAttributeId(SDF_OptLayout wsAfterId, SDF_OptLayout wsAfterParenOpen, SDF_ModuleName ModuleName, SDF_OptLayout wsAfterModuleName) */

SDF_Attribute SDF_makeAttributeId(SDF_OptLayout wsAfterId, SDF_OptLayout wsAfterParenOpen, SDF_ModuleName ModuleName, SDF_OptLayout wsAfterModuleName)
{
  return (SDF_Attribute)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun73)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun74))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun67))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun74)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)wsAfterModuleName), (ATerm)ModuleName), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))), (ATerm)wsAfterId), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun74))));
}

/*}}}  */
/*{{{  SDF_Attribute SDF_makeAttributeTerm(SDF_ATerm aterm) */

SDF_Attribute SDF_makeAttributeTerm(SDF_ATerm aterm)
{
  return (SDF_Attribute)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun75)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun67))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl0(SDF_afun76)), (ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun77)))))), (ATerm)ATmakeList1((ATerm)aterm));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolLabel(SDF_Literal label, SDF_OptLayout wsAfterLabel, SDF_OptLayout wsAfterColon, SDF_Symbol Symbol) */

SDF_Symbol SDF_makeSymbolLabel(SDF_Literal label, SDF_OptLayout wsAfterLabel, SDF_OptLayout wsAfterColon, SDF_Symbol Symbol)
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun78))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun79)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun80)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)Symbol), (ATerm)wsAfterColon), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun78))), (ATerm)wsAfterLabel), (ATerm)label));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolLit(SDF_Literal Literal) */

SDF_Symbol SDF_makeSymbolLit(SDF_Literal Literal)
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun79)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun81)))))), (ATerm)ATmakeList1((ATerm)Literal));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolSort(SDF_Sort Sort) */

SDF_Symbol SDF_makeSymbolSort(SDF_Sort Sort)
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun82)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun83)))))), (ATerm)ATmakeList1((ATerm)Sort));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolParameterizedSort(SDF_Sort Sort, SDF_OptLayout wsAfterSort, SDF_OptLayout wsAfterBracketOpenBracketOpen, SDF_SymbolParameters parameters, SDF_OptLayout wsAfterParameters) */

SDF_Symbol SDF_makeSymbolParameterizedSort(SDF_Sort Sort, SDF_OptLayout wsAfterSort, SDF_OptLayout wsAfterBracketOpenBracketOpen, SDF_SymbolParameters parameters, SDF_OptLayout wsAfterParameters)
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun58))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl2(SDF_afun84, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun60))))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun61))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun82)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun85)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun58))), (ATerm)wsAfterParameters), (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl2(SDF_afun84, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun60))))), (ATerm)parameters)), (ATerm)wsAfterBracketOpenBracketOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun61))), (ATerm)wsAfterSort), (ATerm)Sort));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolCharClass(SDF_CharClass CharClass) */

SDF_Symbol SDF_makeSymbolCharClass(SDF_CharClass CharClass)
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun48)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun50)))))), (ATerm)ATmakeList1((ATerm)CharClass));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolLifting(SDF_OptLayout wsAfterLeftQuote, SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol) */

SDF_Symbol SDF_makeSymbolLifting(SDF_OptLayout wsAfterLeftQuote, SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol)
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun86))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun86))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun87)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun86))), (ATerm)wsAfterSymbol), (ATerm)Symbol), (ATerm)wsAfterLeftQuote), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun86))));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolEmpty(SDF_OptLayout wsAfterParenOpen) */

SDF_Symbol SDF_makeSymbolEmpty(SDF_OptLayout wsAfterParenOpen)
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun88)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolSeq(SDF_OptLayout wsAfterParenOpen, SDF_Symbol head, SDF_OptLayout wsAfterHead, SDF_SymbolTail tail, SDF_OptLayout wsAfterTail) */

SDF_Symbol SDF_makeSymbolSeq(SDF_OptLayout wsAfterParenOpen, SDF_Symbol head, SDF_OptLayout wsAfterHead, SDF_SymbolTail tail, SDF_OptLayout wsAfterTail)
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun89, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun53)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)wsAfterTail), (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun89, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))))), (ATerm)tail)), (ATerm)wsAfterHead), (ATerm)head), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolOpt(SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol) */

SDF_Symbol SDF_makeSymbolOpt(SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol)
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun90))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun91)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun90))), (ATerm)wsAfterSymbol), (ATerm)Symbol));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolIter(SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol) */

SDF_Symbol SDF_makeSymbolIter(SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol)
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun92))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun93)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun92))), (ATerm)wsAfterSymbol), (ATerm)Symbol));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolIterStar(SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol) */

SDF_Symbol SDF_makeSymbolIterStar(SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol)
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun94))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun95)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun94))), (ATerm)wsAfterSymbol), (ATerm)Symbol));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolIterSep(SDF_OptLayout wsAfterBraceOpen, SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol, SDF_Symbol sep, SDF_OptLayout wsAfterSep, SDF_OptLayout wsAfterBraceClose) */

SDF_Symbol SDF_makeSymbolIterSep(SDF_OptLayout wsAfterBraceOpen, SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol, SDF_Symbol sep, SDF_OptLayout wsAfterSep, SDF_OptLayout wsAfterBraceClose)
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun92))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun96))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun97))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun98)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun92))), (ATerm)wsAfterBraceClose), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun96))), (ATerm)wsAfterSep), (ATerm)sep), (ATerm)wsAfterSymbol), (ATerm)Symbol), (ATerm)wsAfterBraceOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun97))));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolIterStarSep(SDF_OptLayout wsAfterBraceOpen, SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol, SDF_Symbol sep, SDF_OptLayout wsAfterSep, SDF_OptLayout wsAfterBraceClose) */

SDF_Symbol SDF_makeSymbolIterStarSep(SDF_OptLayout wsAfterBraceOpen, SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol, SDF_Symbol sep, SDF_OptLayout wsAfterSep, SDF_OptLayout wsAfterBraceClose)
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun94))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun96))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun97))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun99)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun94))), (ATerm)wsAfterBraceClose), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun96))), (ATerm)wsAfterSep), (ATerm)sep), (ATerm)wsAfterSymbol), (ATerm)Symbol), (ATerm)wsAfterBraceOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun97))));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolIterN(SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol, SDF_NatCon n, SDF_OptLayout wsAfterN) */

SDF_Symbol SDF_makeSymbolIterN(SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol, SDF_NatCon n, SDF_OptLayout wsAfterN)
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun92))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun100)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun101)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun92))), (ATerm)wsAfterN), (ATerm)n), (ATerm)wsAfterSymbol), (ATerm)Symbol));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolIterSepN(SDF_OptLayout wsAfterBraceOpen, SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol, SDF_Symbol sep, SDF_OptLayout wsAfterSep, SDF_OptLayout wsAfterBraceClose, SDF_NatCon n, SDF_OptLayout wsAfterN) */

SDF_Symbol SDF_makeSymbolIterSepN(SDF_OptLayout wsAfterBraceOpen, SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol, SDF_Symbol sep, SDF_OptLayout wsAfterSep, SDF_OptLayout wsAfterBraceClose, SDF_NatCon n, SDF_OptLayout wsAfterN)
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun92))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun100)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun96))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun97))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun102)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun92))), (ATerm)wsAfterN), (ATerm)n), (ATerm)wsAfterBraceClose), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun96))), (ATerm)wsAfterSep), (ATerm)sep), (ATerm)wsAfterSymbol), (ATerm)Symbol), (ATerm)wsAfterBraceOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun97))));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolTuple(SDF_OptLayout wsAfterLessThan, SDF_Symbol head, SDF_OptLayout wsAfterHead, SDF_OptLayout wsAfterComma, SDF_SymbolRest rest, SDF_OptLayout wsAfterRest) */

SDF_Symbol SDF_makeSymbolTuple(SDF_OptLayout wsAfterLessThan, SDF_Symbol head, SDF_OptLayout wsAfterHead, SDF_OptLayout wsAfterComma, SDF_SymbolRest rest, SDF_OptLayout wsAfterRest)
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun103))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl2(SDF_afun84, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun60))))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun60))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun104))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun105)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun103))), (ATerm)wsAfterRest), (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl2(SDF_afun84, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun60))))), (ATerm)rest)), (ATerm)wsAfterComma), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun60))), (ATerm)wsAfterHead), (ATerm)head), (ATerm)wsAfterLessThan), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun104))));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolPair(SDF_Symbol left, SDF_OptLayout wsAfterLeft, SDF_OptLayout wsAfterHash, SDF_Symbol right) */

SDF_Symbol SDF_makeSymbolPair(SDF_Symbol left, SDF_OptLayout wsAfterLeft, SDF_OptLayout wsAfterHash, SDF_Symbol right)
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun106))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun107)))), (ATerm)ATmakeAppl1(SDF_afun32, (ATerm)ATmakeAppl0(SDF_afun56))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)right), (ATerm)wsAfterHash), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun106))), (ATerm)wsAfterLeft), (ATerm)left));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolFunc(SDF_OptLayout wsAfterParenOpen, SDF_Symbols arguments, SDF_OptLayout wsAfterArguments, SDF_OptLayout wsAfterEqualsGreaterThan, SDF_Symbol results, SDF_OptLayout wsAfterResults) */

SDF_Symbol SDF_makeSymbolFunc(SDF_OptLayout wsAfterParenOpen, SDF_Symbols arguments, SDF_OptLayout wsAfterArguments, SDF_OptLayout wsAfterEqualsGreaterThan, SDF_Symbol results, SDF_OptLayout wsAfterResults)
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun108))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun15)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun109)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)wsAfterResults), (ATerm)results), (ATerm)wsAfterEqualsGreaterThan), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun108))), (ATerm)wsAfterArguments), (ATerm)arguments), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolAlt(SDF_Symbol left, SDF_OptLayout wsAfterLeft, SDF_OptLayout wsAfterBar, SDF_Symbol right) */

SDF_Symbol SDF_makeSymbolAlt(SDF_Symbol left, SDF_OptLayout wsAfterLeft, SDF_OptLayout wsAfterBar, SDF_Symbol right)
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun55))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun57)))), (ATerm)ATmakeAppl1(SDF_afun32, (ATerm)ATmakeAppl0(SDF_afun56))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)right), (ATerm)wsAfterBar), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun55))), (ATerm)wsAfterLeft), (ATerm)left));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolStrategy(SDF_OptLayout wsAfterParenOpen, SDF_Symbol left, SDF_OptLayout wsAfterLeft, SDF_OptLayout wsAfterGreaterThan, SDF_Symbol right, SDF_OptLayout wsAfterRight) */

SDF_Symbol SDF_makeSymbolStrategy(SDF_OptLayout wsAfterParenOpen, SDF_Symbol left, SDF_OptLayout wsAfterLeft, SDF_OptLayout wsAfterGreaterThan, SDF_Symbol right, SDF_OptLayout wsAfterRight)
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun42))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun110)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)wsAfterRight), (ATerm)right), (ATerm)wsAfterGreaterThan), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun42))), (ATerm)wsAfterLeft), (ATerm)left), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolCf(SDF_OptLayout wsAfterLessThan, SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol, SDF_OptLayout wsAfterCF) */

SDF_Symbol SDF_makeSymbolCf(SDF_OptLayout wsAfterLessThan, SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol, SDF_OptLayout wsAfterCF)
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun103))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun111))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun104))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun112)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun103))), (ATerm)wsAfterCF), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun111))), (ATerm)wsAfterSymbol), (ATerm)Symbol), (ATerm)wsAfterLessThan), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun104))));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolLex(SDF_OptLayout wsAfterLessThan, SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol, SDF_OptLayout wsAfterLEX) */

SDF_Symbol SDF_makeSymbolLex(SDF_OptLayout wsAfterLessThan, SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol, SDF_OptLayout wsAfterLEX)
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun103))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun113))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun104))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun114)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun103))), (ATerm)wsAfterLEX), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun113))), (ATerm)wsAfterSymbol), (ATerm)Symbol), (ATerm)wsAfterLessThan), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun104))));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolVarsym(SDF_OptLayout wsAfterLessThan, SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol, SDF_OptLayout wsAfterVAR) */

SDF_Symbol SDF_makeSymbolVarsym(SDF_OptLayout wsAfterLessThan, SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol, SDF_OptLayout wsAfterVAR)
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun103))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun115))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun104))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun116)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun103))), (ATerm)wsAfterVAR), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun115))), (ATerm)wsAfterSymbol), (ATerm)Symbol), (ATerm)wsAfterLessThan), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun104))));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolLayout() */

SDF_Symbol SDF_makeSymbolLayout()
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun117))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun118)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun117))));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolBracket(SDF_OptLayout wsAfterParenOpen, SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol) */

SDF_Symbol SDF_makeSymbolBracket(SDF_OptLayout wsAfterParenOpen, SDF_Symbol Symbol, SDF_OptLayout wsAfterSymbol)
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl0(SDF_afun36)))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)wsAfterSymbol), (ATerm)Symbol), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolStart() */

SDF_Symbol SDF_makeSymbolStart()
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun119))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun120)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun119))));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_makeSymbolFileStart() */

SDF_Symbol SDF_makeSymbolFileStart()
{
  return (SDF_Symbol)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun121))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun122)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun121))));
}

/*}}}  */
/*{{{  SDF_Production SDF_makeProductionProdFun(SDF_Literal functionSymbol, SDF_OptLayout wsAfterFunctionSymbol, SDF_OptLayout wsAfterParenOpen, SDF_SymbolArguments arguments, SDF_OptLayout wsAfterArguments, SDF_OptLayout wsAfterParenClose, SDF_OptLayout wsAfterGreaterThan, SDF_Symbol result, SDF_OptLayout wsAfterResult, SDF_Attributes Attributes) */

SDF_Production SDF_makeProductionProdFun(SDF_Literal functionSymbol, SDF_OptLayout wsAfterFunctionSymbol, SDF_OptLayout wsAfterParenOpen, SDF_SymbolArguments arguments, SDF_OptLayout wsAfterArguments, SDF_OptLayout wsAfterParenClose, SDF_OptLayout wsAfterGreaterThan, SDF_Symbol result, SDF_OptLayout wsAfterResult, SDF_Attributes Attributes)
{
  return (SDF_Production)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun123)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun42))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl2(SDF_afun59, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun60))))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun79)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun124))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun125)))), (ATerm)ATmakeAppl0(SDF_afun76)))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)Attributes), (ATerm)wsAfterResult), (ATerm)result), (ATerm)wsAfterGreaterThan), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun42))), (ATerm)wsAfterParenClose), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)wsAfterArguments), (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl2(SDF_afun59, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun60))))), (ATerm)arguments)), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))), (ATerm)wsAfterFunctionSymbol), (ATerm)functionSymbol));
}

/*}}}  */
/*{{{  SDF_Production SDF_makeProductionProd(SDF_Symbols Symbols, SDF_OptLayout wsAfterSymbols, SDF_OptLayout wsAfterGreaterThan, SDF_Symbol result, SDF_OptLayout wsAfterResult, SDF_Attributes Attributes) */

SDF_Production SDF_makeProductionProd(SDF_Symbols Symbols, SDF_OptLayout wsAfterSymbols, SDF_OptLayout wsAfterGreaterThan, SDF_Symbol result, SDF_OptLayout wsAfterResult, SDF_Attributes Attributes)
{
  return (SDF_Production)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun123)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun42))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun15)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun124))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun126)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)Attributes), (ATerm)wsAfterResult), (ATerm)result), (ATerm)wsAfterGreaterThan), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun42))), (ATerm)wsAfterSymbols), (ATerm)Symbols));
}

/*}}}  */
/*{{{  SDF_SymbolArguments SDF_makeSymbolArgumentsEmpty() */

SDF_SymbolArguments SDF_makeSymbolArgumentsEmpty()
{
  return (SDF_SymbolArguments)(ATerm)ATempty;
}

/*}}}  */
/*{{{  SDF_SymbolArguments SDF_makeSymbolArgumentsSingle(SDF_Symbol head) */

SDF_SymbolArguments SDF_makeSymbolArgumentsSingle(SDF_Symbol head)
{
  return (SDF_SymbolArguments)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  SDF_SymbolArguments SDF_makeSymbolArgumentsMany(SDF_Symbol head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_SymbolArguments tail) */

SDF_SymbolArguments SDF_makeSymbolArgumentsMany(SDF_Symbol head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_SymbolArguments tail)
{
  return (SDF_SymbolArguments)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterSep), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  SDF_Sort SDF_makeSortOneChar(SDF_CHARLIST chars) */

SDF_Sort SDF_makeSortOneChar(SDF_CHARLIST chars)
{
  return (SDF_Sort)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun127, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun82)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun82))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun128, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun129, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm)chars)));
}

/*}}}  */
/*{{{  SDF_Sort SDF_makeSortMoreChars(SDF_CHARLIST chars) */

SDF_Sort SDF_makeSortMoreChars(SDF_CHARLIST chars)
{
  return (SDF_Sort)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun127, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun82)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun82))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun128, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun129, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm)chars)));
}

/*}}}  */
/*{{{  SDF_SymbolParameters SDF_makeSymbolParametersSingle(SDF_Symbol head) */

SDF_SymbolParameters SDF_makeSymbolParametersSingle(SDF_Symbol head)
{
  return (SDF_SymbolParameters)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  SDF_SymbolParameters SDF_makeSymbolParametersMany(SDF_Symbol head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_SymbolParameters tail) */

SDF_SymbolParameters SDF_makeSymbolParametersMany(SDF_Symbol head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_SymbolParameters tail)
{
  return (SDF_SymbolParameters)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterSep), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  SDF_NumChar SDF_makeNumCharDigits(SDF_CHARLIST chars) */

SDF_NumChar SDF_makeNumCharDigits(SDF_CHARLIST chars)
{
  return (SDF_NumChar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun127, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun130)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun130))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun128, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun129, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm)chars)));
}

/*}}}  */
/*{{{  SDF_ShortChar SDF_makeShortCharRegular(SDF_CHARLIST chars) */

SDF_ShortChar SDF_makeShortCharRegular(SDF_CHARLIST chars)
{
  return (SDF_ShortChar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun127, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun131)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun131))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun128, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun129, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm)chars)));
}

/*}}}  */
/*{{{  SDF_ShortChar SDF_makeShortCharEscaped(SDF_CHARLIST chars) */

SDF_ShortChar SDF_makeShortCharEscaped(SDF_CHARLIST chars)
{
  return (SDF_ShortChar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun127, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun131)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun131))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun128, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun129, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm)chars)));
}

/*}}}  */
/*{{{  SDF_Character SDF_makeCharacterNumeric(SDF_NumChar NumChar) */

SDF_Character SDF_makeCharacterNumeric(SDF_NumChar NumChar)
{
  return (SDF_Character)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun130)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun132))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun133)))))), (ATerm)ATmakeList1((ATerm)NumChar));
}

/*}}}  */
/*{{{  SDF_Character SDF_makeCharacterShort(SDF_ShortChar ShortChar) */

SDF_Character SDF_makeCharacterShort(SDF_ShortChar ShortChar)
{
  return (SDF_Character)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun131)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun132))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun134)))))), (ATerm)ATmakeList1((ATerm)ShortChar));
}

/*}}}  */
/*{{{  SDF_Character SDF_makeCharacterTop() */

SDF_Character SDF_makeCharacterTop()
{
  return (SDF_Character)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun135))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun132))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun136)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun135))));
}

/*}}}  */
/*{{{  SDF_Character SDF_makeCharacterEof() */

SDF_Character SDF_makeCharacterEof()
{
  return (SDF_Character)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun137))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun132))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun138)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun137))));
}

/*}}}  */
/*{{{  SDF_Character SDF_makeCharacterBot() */

SDF_Character SDF_makeCharacterBot()
{
  return (SDF_Character)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun139))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun132))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun140)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun139))));
}

/*}}}  */
/*{{{  SDF_Character SDF_makeCharacterLabelUnderscoreStart() */

SDF_Character SDF_makeCharacterLabelUnderscoreStart()
{
  return (SDF_Character)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun141))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun132))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun142)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun141))));
}

/*}}}  */
/*{{{  SDF_CharRange SDF_makeCharRangeDefault(SDF_Character Character) */

SDF_CharRange SDF_makeCharRangeDefault(SDF_Character Character)
{
  return (SDF_CharRange)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun132)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun143))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)Character));
}

/*}}}  */
/*{{{  SDF_CharRange SDF_makeCharRangeRange(SDF_Character start, SDF_OptLayout wsAfterStart, SDF_OptLayout wsAfter, SDF_Character end) */

SDF_CharRange SDF_makeCharRangeRange(SDF_Character start, SDF_OptLayout wsAfterStart, SDF_OptLayout wsAfter, SDF_Character end)
{
  return (SDF_CharRange)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun132)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun144))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun132)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun143))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun145)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)end), (ATerm)wsAfter), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun144))), (ATerm)wsAfterStart), (ATerm)start));
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_makeCharRangesDefault(SDF_CharRange CharRange) */

SDF_CharRanges SDF_makeCharRangesDefault(SDF_CharRange CharRange)
{
  return (SDF_CharRanges)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun143)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun146))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)CharRange));
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_makeCharRangesConc(SDF_CharRanges left, SDF_OptLayout wsAfterLeft, SDF_CharRanges right) */

SDF_CharRanges SDF_makeCharRangesConc(SDF_CharRanges left, SDF_OptLayout wsAfterLeft, SDF_CharRanges right)
{
  return (SDF_CharRanges)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun146)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun146)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun146))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl0(SDF_afun147))), (ATerm)ATmakeAppl1(SDF_afun32, (ATerm)ATmakeAppl0(SDF_afun56))), (ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun148)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)right), (ATerm)wsAfterLeft), (ATerm)left));
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_makeCharRangesBracket(SDF_OptLayout wsAfterParenOpen, SDF_CharRanges CharRanges, SDF_OptLayout wsAfterCharRanges) */

SDF_CharRanges SDF_makeCharRangesBracket(SDF_OptLayout wsAfterParenOpen, SDF_CharRanges CharRanges, SDF_OptLayout wsAfterCharRanges)
{
  return (SDF_CharRanges)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun146)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun146))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl0(SDF_afun36)))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)wsAfterCharRanges), (ATerm)CharRanges), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))));
}

/*}}}  */
/*{{{  SDF_OptCharRanges SDF_makeOptCharRangesAbsent() */

SDF_OptCharRanges SDF_makeOptCharRangesAbsent()
{
  return (SDF_OptCharRanges)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun149))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun150)))))), (ATerm)ATempty);
}

/*}}}  */
/*{{{  SDF_OptCharRanges SDF_makeOptCharRangesPresent(SDF_CharRanges CharRanges) */

SDF_OptCharRanges SDF_makeOptCharRangesPresent(SDF_CharRanges CharRanges)
{
  return (SDF_OptCharRanges)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun146)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun149))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun151)))))), (ATerm)ATmakeList1((ATerm)CharRanges));
}

/*}}}  */
/*{{{  SDF_CharClass SDF_makeCharClassSimpleCharclass(SDF_OptLayout wsAfterBracketOpen, SDF_OptCharRanges OptCharRanges, SDF_OptLayout wsAfterOptCharRanges) */

SDF_CharClass SDF_makeCharClassSimpleCharclass(SDF_OptLayout wsAfterBracketOpen, SDF_OptCharRanges OptCharRanges, SDF_OptLayout wsAfterOptCharRanges)
{
  return (SDF_CharClass)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun152))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun149)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun153))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun48))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun154)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun152))), (ATerm)wsAfterOptCharRanges), (ATerm)OptCharRanges), (ATerm)wsAfterBracketOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun153))));
}

/*}}}  */
/*{{{  SDF_CharClass SDF_makeCharClassComp(SDF_OptLayout wsAfterTilde, SDF_CharClass CharClass) */

SDF_CharClass SDF_makeCharClassComp(SDF_OptLayout wsAfterTilde, SDF_CharClass CharClass)
{
  return (SDF_CharClass)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun48)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun155))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun48))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun156)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)CharClass), (ATerm)wsAfterTilde), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun155))));
}

/*}}}  */
/*{{{  SDF_CharClass SDF_makeCharClassDiff(SDF_CharClass left, SDF_OptLayout wsAfterLeft, SDF_OptLayout wsAfterSlash, SDF_CharClass right) */

SDF_CharClass SDF_makeCharClassDiff(SDF_CharClass left, SDF_OptLayout wsAfterLeft, SDF_OptLayout wsAfterSlash, SDF_CharClass right)
{
  return (SDF_CharClass)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun48)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun157))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun48)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun48))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl0(SDF_afun147))), (ATerm)ATmakeAppl1(SDF_afun32, (ATerm)ATmakeAppl0(SDF_afun158))), (ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun159)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)right), (ATerm)wsAfterSlash), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun157))), (ATerm)wsAfterLeft), (ATerm)left));
}

/*}}}  */
/*{{{  SDF_CharClass SDF_makeCharClassIsect(SDF_CharClass left, SDF_OptLayout wsAfterLeft, SDF_OptLayout wsAfterSlashBackslash, SDF_CharClass right) */

SDF_CharClass SDF_makeCharClassIsect(SDF_CharClass left, SDF_OptLayout wsAfterLeft, SDF_OptLayout wsAfterSlashBackslash, SDF_CharClass right)
{
  return (SDF_CharClass)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun48)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun160))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun48)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun48))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl0(SDF_afun147))), (ATerm)ATmakeAppl1(SDF_afun32, (ATerm)ATmakeAppl0(SDF_afun158))), (ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun161)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)right), (ATerm)wsAfterSlashBackslash), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun160))), (ATerm)wsAfterLeft), (ATerm)left));
}

/*}}}  */
/*{{{  SDF_CharClass SDF_makeCharClassUnion(SDF_CharClass left, SDF_OptLayout wsAfterLeft, SDF_OptLayout wsAfterBackslashSlash, SDF_CharClass right) */

SDF_CharClass SDF_makeCharClassUnion(SDF_CharClass left, SDF_OptLayout wsAfterLeft, SDF_OptLayout wsAfterBackslashSlash, SDF_CharClass right)
{
  return (SDF_CharClass)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun48)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun162))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun48)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun48))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun32, (ATerm)ATmakeAppl0(SDF_afun158))), (ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun163)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)right), (ATerm)wsAfterBackslashSlash), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun162))), (ATerm)wsAfterLeft), (ATerm)left));
}

/*}}}  */
/*{{{  SDF_CharClass SDF_makeCharClassDefault(SDF_OptLayout wsAfterParenOpen, SDF_CharClass CharClass, SDF_OptLayout wsAfterCharClass) */

SDF_CharClass SDF_makeCharClassDefault(SDF_OptLayout wsAfterParenOpen, SDF_CharClass CharClass, SDF_OptLayout wsAfterCharClass)
{
  return (SDF_CharClass)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun48)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun48))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl0(SDF_afun76)), (ATerm)ATmakeAppl0(SDF_afun36)))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)wsAfterCharClass), (ATerm)CharClass), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))));
}

/*}}}  */
/*{{{  SDF_Associativity SDF_makeAssociativityLeft() */

SDF_Associativity SDF_makeAssociativityLeft()
{
  return (SDF_Associativity)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun164))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun71))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun164)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun164))));
}

/*}}}  */
/*{{{  SDF_Associativity SDF_makeAssociativityRight() */

SDF_Associativity SDF_makeAssociativityRight()
{
  return (SDF_Associativity)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun165))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun71))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun165)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun165))));
}

/*}}}  */
/*{{{  SDF_Associativity SDF_makeAssociativityNonAssoc() */

SDF_Associativity SDF_makeAssociativityNonAssoc()
{
  return (SDF_Associativity)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun166))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun71))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun166)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun166))));
}

/*}}}  */
/*{{{  SDF_Associativity SDF_makeAssociativityAssoc() */

SDF_Associativity SDF_makeAssociativityAssoc()
{
  return (SDF_Associativity)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun72))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun71))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun72)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun72))));
}

/*}}}  */
/*{{{  SDF_Group SDF_makeGroupSimpleGroup(SDF_Production Production) */

SDF_Group SDF_makeGroupSimpleGroup(SDF_Production Production)
{
  return (SDF_Group)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun124)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun167))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun168)))))), (ATerm)ATmakeList1((ATerm)Production));
}

/*}}}  */
/*{{{  SDF_Group SDF_makeGroupProdsGroup(SDF_OptLayout wsAfterBraceOpen, SDF_Productions Productions, SDF_OptLayout wsAfterProductions) */

SDF_Group SDF_makeGroupProdsGroup(SDF_OptLayout wsAfterBraceOpen, SDF_Productions Productions, SDF_OptLayout wsAfterProductions)
{
  return (SDF_Group)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun96))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun21)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun97))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun167))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun169)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun96))), (ATerm)wsAfterProductions), (ATerm)Productions), (ATerm)wsAfterBraceOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun97))));
}

/*}}}  */
/*{{{  SDF_Group SDF_makeGroupAssocGroup(SDF_OptLayout wsAfterBraceOpen, SDF_Associativity Associativity, SDF_OptLayout wsAfterAssociativity, SDF_OptLayout wsAfterColon, SDF_Productions Productions, SDF_OptLayout wsAfterProductions) */

SDF_Group SDF_makeGroupAssocGroup(SDF_OptLayout wsAfterBraceOpen, SDF_Associativity Associativity, SDF_OptLayout wsAfterAssociativity, SDF_OptLayout wsAfterColon, SDF_Productions Productions, SDF_OptLayout wsAfterProductions)
{
  return (SDF_Group)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun96))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun21)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun78))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun71)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun97))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun167))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun170)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun96))), (ATerm)wsAfterProductions), (ATerm)Productions), (ATerm)wsAfterColon), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun78))), (ATerm)wsAfterAssociativity), (ATerm)Associativity), (ATerm)wsAfterBraceOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun97))));
}

/*}}}  */
/*{{{  SDF_Priority SDF_makePriorityChain(SDF_GroupList list) */

SDF_Priority SDF_makePriorityChain(SDF_GroupList list)
{
  return (SDF_Priority)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl2(SDF_afun84, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun167)), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun103))))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun171))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun172)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl2(SDF_afun84, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun167)), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun103))))), (ATerm)list)));
}

/*}}}  */
/*{{{  SDF_Priority SDF_makePriorityAssoc(SDF_Group left, SDF_OptLayout wsAfterLeft, SDF_Associativity Associativity, SDF_OptLayout wsAfterAssociativity, SDF_Group right) */

SDF_Priority SDF_makePriorityAssoc(SDF_Group left, SDF_OptLayout wsAfterLeft, SDF_Associativity Associativity, SDF_OptLayout wsAfterAssociativity, SDF_Group right)
{
  return (SDF_Priority)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun167)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun71)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun167)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun171))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun72)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)right), (ATerm)wsAfterAssociativity), (ATerm)Associativity), (ATerm)wsAfterLeft), (ATerm)left));
}

/*}}}  */
/*{{{  SDF_GroupList SDF_makeGroupListSingle(SDF_Group head) */

SDF_GroupList SDF_makeGroupListSingle(SDF_Group head)
{
  return (SDF_GroupList)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  SDF_GroupList SDF_makeGroupListMany(SDF_Group head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_GroupList tail) */

SDF_GroupList SDF_makeGroupListMany(SDF_Group head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_GroupList tail)
{
  return (SDF_GroupList)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterSep), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  SDF_Priorities SDF_makePrioritiesDefault(SDF_PriorityList list) */

SDF_Priorities SDF_makePrioritiesDefault(SDF_PriorityList list)
{
  return (SDF_Priorities)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl2(SDF_afun59, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun171)), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun60))))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun17))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl2(SDF_afun59, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun171)), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun60))))), (ATerm)list)));
}

/*}}}  */
/*{{{  SDF_PriorityList SDF_makePriorityListEmpty() */

SDF_PriorityList SDF_makePriorityListEmpty()
{
  return (SDF_PriorityList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  SDF_PriorityList SDF_makePriorityListSingle(SDF_Priority head) */

SDF_PriorityList SDF_makePriorityListSingle(SDF_Priority head)
{
  return (SDF_PriorityList)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  SDF_PriorityList SDF_makePriorityListMany(SDF_Priority head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_PriorityList tail) */

SDF_PriorityList SDF_makePriorityListMany(SDF_Priority head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_PriorityList tail)
{
  return (SDF_PriorityList)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterSep), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  SDF_SymbolTail SDF_makeSymbolTailSingle(SDF_Symbol head) */

SDF_SymbolTail SDF_makeSymbolTailSingle(SDF_Symbol head)
{
  return (SDF_SymbolTail)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  SDF_SymbolTail SDF_makeSymbolTailMany(SDF_Symbol head, SDF_OptLayout wsAfterFirst, SDF_SymbolTail tail) */

SDF_SymbolTail SDF_makeSymbolTailMany(SDF_Symbol head, SDF_OptLayout wsAfterFirst, SDF_SymbolTail tail)
{
  return (SDF_SymbolTail)(ATerm)ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  SDF_SymbolRest SDF_makeSymbolRestSingle(SDF_Symbol head) */

SDF_SymbolRest SDF_makeSymbolRestSingle(SDF_Symbol head)
{
  return (SDF_SymbolRest)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  SDF_SymbolRest SDF_makeSymbolRestMany(SDF_Symbol head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_SymbolRest tail) */

SDF_SymbolRest SDF_makeSymbolRestMany(SDF_Symbol head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_SymbolRest tail)
{
  return (SDF_SymbolRest)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterSep), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  SDF_Renamings SDF_makeRenamingsRenamings(SDF_OptLayout wsAfterBracketOpen, SDF_RenamingList list, SDF_OptLayout wsAfterList) */

SDF_Renamings SDF_makeRenamingsRenamings(SDF_OptLayout wsAfterBracketOpen, SDF_RenamingList list, SDF_OptLayout wsAfterList)
{
  return (SDF_Renamings)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun152))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun173))))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun153))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun174))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun175)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun152))), (ATerm)wsAfterList), (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun173))))), (ATerm)list)), (ATerm)wsAfterBracketOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun153))));
}

/*}}}  */
/*{{{  SDF_RenamingList SDF_makeRenamingListEmpty() */

SDF_RenamingList SDF_makeRenamingListEmpty()
{
  return (SDF_RenamingList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  SDF_RenamingList SDF_makeRenamingListSingle(SDF_Renaming head) */

SDF_RenamingList SDF_makeRenamingListSingle(SDF_Renaming head)
{
  return (SDF_RenamingList)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  SDF_RenamingList SDF_makeRenamingListMany(SDF_Renaming head, SDF_OptLayout wsAfterFirst, SDF_RenamingList tail) */

SDF_RenamingList SDF_makeRenamingListMany(SDF_Renaming head, SDF_OptLayout wsAfterFirst, SDF_RenamingList tail)
{
  return (SDF_RenamingList)(ATerm)ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  SDF_Renaming SDF_makeRenamingSymbol(SDF_Symbol from, SDF_OptLayout wsAfterFrom, SDF_OptLayout wsAfterEqualsGreaterThan, SDF_Symbol to) */

SDF_Renaming SDF_makeRenamingSymbol(SDF_Symbol from, SDF_OptLayout wsAfterFrom, SDF_OptLayout wsAfterEqualsGreaterThan, SDF_Symbol to)
{
  return (SDF_Renaming)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun108))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun173))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun176)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)to), (ATerm)wsAfterEqualsGreaterThan), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun108))), (ATerm)wsAfterFrom), (ATerm)from));
}

/*}}}  */
/*{{{  SDF_Renaming SDF_makeRenamingProduction(SDF_Production fromProd, SDF_OptLayout wsAfterFromProd, SDF_OptLayout wsAfterEqualsGreaterThan, SDF_Production toProd) */

SDF_Renaming SDF_makeRenamingProduction(SDF_Production fromProd, SDF_OptLayout wsAfterFromProd, SDF_OptLayout wsAfterEqualsGreaterThan, SDF_Production toProd)
{
  return (SDF_Renaming)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun124)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun108))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun124)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun173))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun177)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)toProd), (ATerm)wsAfterEqualsGreaterThan), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun108))), (ATerm)wsAfterFromProd), (ATerm)fromProd));
}

/*}}}  */
/*{{{  SDF_ModuleWord SDF_makeModuleWordWord(SDF_CHARLIST chars) */

SDF_ModuleWord SDF_makeModuleWordWord(SDF_CHARLIST chars)
{
  return (SDF_ModuleWord)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun127, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun178)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun178))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun128, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun129, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm)chars)));
}

/*}}}  */
/*{{{  SDF_ModuleId SDF_makeModuleIdWord(SDF_CHARLIST chars) */

SDF_ModuleId SDF_makeModuleIdWord(SDF_CHARLIST chars)
{
  return (SDF_ModuleId)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun127, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun179)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun179))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun128, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun129, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm)chars)));
}

/*}}}  */
/*{{{  SDF_ModuleId SDF_makeModuleIdSlashWord(SDF_CHARLIST chars) */

SDF_ModuleId SDF_makeModuleIdSlashWord(SDF_CHARLIST chars)
{
  return (SDF_ModuleId)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun127, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun179)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun179))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun128, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun129, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm)chars)));
}

/*}}}  */
/*{{{  SDF_ModuleId SDF_makeModuleIdWordSlashWord(SDF_CHARLIST chars) */

SDF_ModuleId SDF_makeModuleIdWordSlashWord(SDF_CHARLIST chars)
{
  return (SDF_ModuleId)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun127, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun179)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun179))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun128, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun129, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm)chars)));
}

/*}}}  */
/*{{{  SDF_Definition SDF_makeDefinitionDefault(SDF_ModuleList list) */

SDF_Definition SDF_makeDefinitionDefault(SDF_ModuleList list)
{
  return (SDF_Definition)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun180))))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun181))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun180))))), (ATerm)list)));
}

/*}}}  */
/*{{{  SDF_ModuleList SDF_makeModuleListEmpty() */

SDF_ModuleList SDF_makeModuleListEmpty()
{
  return (SDF_ModuleList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  SDF_ModuleList SDF_makeModuleListSingle(SDF_Module head) */

SDF_ModuleList SDF_makeModuleListSingle(SDF_Module head)
{
  return (SDF_ModuleList)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  SDF_ModuleList SDF_makeModuleListMany(SDF_Module head, SDF_OptLayout wsAfterFirst, SDF_ModuleList tail) */

SDF_ModuleList SDF_makeModuleListMany(SDF_Module head, SDF_OptLayout wsAfterFirst, SDF_ModuleList tail)
{
  return (SDF_ModuleList)(ATerm)ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  SDF_Module SDF_makeModuleModule(SDF_OptLayout wsAfterModule, SDF_ModuleName ModuleName, SDF_OptLayout wsAfterModuleName, SDF_ImpSectionList list, SDF_OptLayout wsAfterList, SDF_Sections Sections) */

SDF_Module SDF_makeModuleModule(SDF_OptLayout wsAfterModule, SDF_ModuleName ModuleName, SDF_OptLayout wsAfterModuleName, SDF_ImpSectionList list, SDF_OptLayout wsAfterList, SDF_Sections Sections)
{
  return (SDF_Module)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun182)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun19))))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun73)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun183))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun180))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun183)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)Sections), (ATerm)wsAfterList), (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun19))))), (ATerm)list)), (ATerm)wsAfterModuleName), (ATerm)ModuleName), (ATerm)wsAfterModule), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun183))));
}

/*}}}  */
/*{{{  SDF_ImpSectionList SDF_makeImpSectionListEmpty() */

SDF_ImpSectionList SDF_makeImpSectionListEmpty()
{
  return (SDF_ImpSectionList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  SDF_ImpSectionList SDF_makeImpSectionListSingle(SDF_ImpSection head) */

SDF_ImpSectionList SDF_makeImpSectionListSingle(SDF_ImpSection head)
{
  return (SDF_ImpSectionList)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  SDF_ImpSectionList SDF_makeImpSectionListMany(SDF_ImpSection head, SDF_OptLayout wsAfterFirst, SDF_ImpSectionList tail) */

SDF_ImpSectionList SDF_makeImpSectionListMany(SDF_ImpSection head, SDF_OptLayout wsAfterFirst, SDF_ImpSectionList tail)
{
  return (SDF_ImpSectionList)(ATerm)ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  SDF_Section SDF_makeSectionExports(SDF_OptLayout wsAfterExports, SDF_Grammar Grammar) */

SDF_Section SDF_makeSectionExports(SDF_OptLayout wsAfterExports, SDF_Grammar Grammar)
{
  return (SDF_Section)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun9)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun184))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun185))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun184)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)Grammar), (ATerm)wsAfterExports), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun184))));
}

/*}}}  */
/*{{{  SDF_Section SDF_makeSectionHiddens(SDF_OptLayout wsAfterHiddens, SDF_Grammar Grammar) */

SDF_Section SDF_makeSectionHiddens(SDF_OptLayout wsAfterHiddens, SDF_Grammar Grammar)
{
  return (SDF_Section)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun9)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun186))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun185))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun186)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)Grammar), (ATerm)wsAfterHiddens), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun186))));
}

/*}}}  */
/*{{{  SDF_Sections SDF_makeSectionsDefault(SDF_SectionList list) */

SDF_Sections SDF_makeSectionsDefault(SDF_SectionList list)
{
  return (SDF_Sections)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun185))))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun182))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun185))))), (ATerm)list)));
}

/*}}}  */
/*{{{  SDF_SectionList SDF_makeSectionListEmpty() */

SDF_SectionList SDF_makeSectionListEmpty()
{
  return (SDF_SectionList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  SDF_SectionList SDF_makeSectionListSingle(SDF_Section head) */

SDF_SectionList SDF_makeSectionListSingle(SDF_Section head)
{
  return (SDF_SectionList)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  SDF_SectionList SDF_makeSectionListMany(SDF_Section head, SDF_OptLayout wsAfterFirst, SDF_SectionList tail) */

SDF_SectionList SDF_makeSectionListMany(SDF_Section head, SDF_OptLayout wsAfterFirst, SDF_SectionList tail)
{
  return (SDF_SectionList)(ATerm)ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_makeModuleNameUnparameterized(SDF_ModuleId ModuleId) */

SDF_ModuleName SDF_makeModuleNameUnparameterized(SDF_ModuleId ModuleId)
{
  return (SDF_ModuleName)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun179)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun73))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun187)))))), (ATerm)ATmakeList1((ATerm)ModuleId));
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_makeModuleNameParameterized(SDF_ModuleId ModuleId, SDF_OptLayout wsAfterModuleId, SDF_OptLayout wsAfterBracketOpen, SDF_Symbols params, SDF_OptLayout wsAfterParams) */

SDF_ModuleName SDF_makeModuleNameParameterized(SDF_ModuleId ModuleId, SDF_OptLayout wsAfterModuleId, SDF_OptLayout wsAfterBracketOpen, SDF_Symbols params, SDF_OptLayout wsAfterParams)
{
  return (SDF_ModuleName)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun152))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun15)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun153))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun179)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun73))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun188)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun152))), (ATerm)wsAfterParams), (ATerm)params), (ATerm)wsAfterBracketOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun153))), (ATerm)wsAfterModuleId), (ATerm)ModuleId));
}

/*}}}  */
/*{{{  SDF_ImpSection SDF_makeImpSectionImports(SDF_OptLayout wsAfterImports, SDF_Imports list) */

SDF_ImpSection SDF_makeImpSectionImports(SDF_OptLayout wsAfterImports, SDF_Imports list)
{
  return (SDF_ImpSection)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun189)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun190))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun19))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun190)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)list), (ATerm)wsAfterImports), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun190))));
}

/*}}}  */
/*{{{  SDF_Imports SDF_makeImportsDefault(SDF_ImportList list) */

SDF_Imports SDF_makeImportsDefault(SDF_ImportList list)
{
  return (SDF_Imports)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun191))))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun189))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun191))))), (ATerm)list)));
}

/*}}}  */
/*{{{  SDF_ImportList SDF_makeImportListEmpty() */

SDF_ImportList SDF_makeImportListEmpty()
{
  return (SDF_ImportList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  SDF_ImportList SDF_makeImportListSingle(SDF_Import head) */

SDF_ImportList SDF_makeImportListSingle(SDF_Import head)
{
  return (SDF_ImportList)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  SDF_ImportList SDF_makeImportListMany(SDF_Import head, SDF_OptLayout wsAfterFirst, SDF_ImportList tail) */

SDF_ImportList SDF_makeImportListMany(SDF_Import head, SDF_OptLayout wsAfterFirst, SDF_ImportList tail)
{
  return (SDF_ImportList)(ATerm)ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  SDF_Import SDF_makeImportModule(SDF_ModuleName ModuleName) */

SDF_Import SDF_makeImportModule(SDF_ModuleName ModuleName)
{
  return (SDF_Import)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun73)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun191))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun183)))))), (ATerm)ATmakeList1((ATerm)ModuleName));
}

/*}}}  */
/*{{{  SDF_Import SDF_makeImportRenamedModule(SDF_ModuleName ModuleName, SDF_OptLayout wsAfterModuleName, SDF_Renamings Renamings) */

SDF_Import SDF_makeImportRenamedModule(SDF_ModuleName ModuleName, SDF_OptLayout wsAfterModuleName, SDF_Renamings Renamings)
{
  return (SDF_Import)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun174)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun73)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun191))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun192)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)Renamings), (ATerm)wsAfterModuleName), (ATerm)ModuleName));
}

/*}}}  */
/*{{{  SDF_Import SDF_makeImportBracket(SDF_OptLayout wsAfterParenOpen, SDF_Import Import, SDF_OptLayout wsAfterImport) */

SDF_Import SDF_makeImportBracket(SDF_OptLayout wsAfterParenOpen, SDF_Import Import, SDF_OptLayout wsAfterImport)
{
  return (SDF_Import)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun191)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun191))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl0(SDF_afun36)))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)wsAfterImport), (ATerm)Import), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))));
}

/*}}}  */
/*{{{  SDF_Symbols SDF_makeSymbolsDefault(SDF_SymbolList list) */

SDF_Symbols SDF_makeSymbolsDefault(SDF_SymbolList list)
{
  return (SDF_Symbols)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun15))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41))))), (ATerm)list)));
}

/*}}}  */
/*{{{  SDF_SymbolList SDF_makeSymbolListEmpty() */

SDF_SymbolList SDF_makeSymbolListEmpty()
{
  return (SDF_SymbolList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  SDF_SymbolList SDF_makeSymbolListSingle(SDF_Symbol head) */

SDF_SymbolList SDF_makeSymbolListSingle(SDF_Symbol head)
{
  return (SDF_SymbolList)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  SDF_SymbolList SDF_makeSymbolListMany(SDF_Symbol head, SDF_OptLayout wsAfterFirst, SDF_SymbolList tail) */

SDF_SymbolList SDF_makeSymbolListMany(SDF_Symbol head, SDF_OptLayout wsAfterFirst, SDF_SymbolList tail)
{
  return (SDF_SymbolList)(ATerm)ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  SDF_OptExp SDF_makeOptExpPresent(SDF_OptLayout wsAfterE, SDF_IntCon IntCon) */

SDF_OptExp SDF_makeOptExpPresent(SDF_OptLayout wsAfterE, SDF_IntCon IntCon)
{
  return (SDF_OptExp)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun193)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun194))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun195))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun151)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)IntCon), (ATerm)wsAfterE), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun194))));
}

/*}}}  */
/*{{{  SDF_OptExp SDF_makeOptExpAbsent() */

SDF_OptExp SDF_makeOptExpAbsent()
{
  return (SDF_OptExp)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun195))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun150)))))), (ATerm)ATempty);
}

/*}}}  */
/*{{{  SDF_RealCon SDF_makeRealConRealCon(SDF_IntCon IntCon, SDF_OptLayout wsAfterIntCon, SDF_OptLayout wsAfterPeriod, SDF_NatCon NatCon, SDF_OptLayout wsAfterNatCon, SDF_OptExp OptExp) */

SDF_RealCon SDF_makeRealConRealCon(SDF_IntCon IntCon, SDF_OptLayout wsAfterIntCon, SDF_OptLayout wsAfterPeriod, SDF_NatCon NatCon, SDF_OptLayout wsAfterNatCon, SDF_OptExp OptExp)
{
  return (SDF_RealCon)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun195)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun100)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun52))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun193)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun196))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun197)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)OptExp), (ATerm)wsAfterNatCon), (ATerm)NatCon), (ATerm)wsAfterPeriod), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun52))), (ATerm)wsAfterIntCon), (ATerm)IntCon));
}

/*}}}  */
/*{{{  SDF_NatCon SDF_makeNatConDigits(SDF_CHARLIST chars) */

SDF_NatCon SDF_makeNatConDigits(SDF_CHARLIST chars)
{
  return (SDF_NatCon)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun127, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun100)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun100))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun128, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun129, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm)chars)));
}

/*}}}  */
/*{{{  SDF_IntCon SDF_makeIntConNatural(SDF_NatCon NatCon) */

SDF_IntCon SDF_makeIntConNatural(SDF_NatCon NatCon)
{
  return (SDF_IntCon)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun100)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun193))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun198)))))), (ATerm)ATmakeList1((ATerm)NatCon));
}

/*}}}  */
/*{{{  SDF_IntCon SDF_makeIntConPositive(SDF_OptLayout wsAfterPos, SDF_NatCon NatCon) */

SDF_IntCon SDF_makeIntConPositive(SDF_OptLayout wsAfterPos, SDF_NatCon NatCon)
{
  return (SDF_IntCon)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun100)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun92))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun193))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun199)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)NatCon), (ATerm)wsAfterPos), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun92))));
}

/*}}}  */
/*{{{  SDF_IntCon SDF_makeIntConNegative(SDF_OptLayout wsAfterNeg, SDF_NatCon NatCon) */

SDF_IntCon SDF_makeIntConNegative(SDF_OptLayout wsAfterNeg, SDF_NatCon NatCon)
{
  return (SDF_IntCon)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun100)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun144))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun193))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun200)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)NatCon), (ATerm)wsAfterNeg), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun144))));
}

/*}}}  */
/*{{{  SDF_AlphaNumericalEscChar SDF_makeAlphaNumericalEscCharDefault(SDF_CHARLIST chars) */

SDF_AlphaNumericalEscChar SDF_makeAlphaNumericalEscCharDefault(SDF_CHARLIST chars)
{
  return (SDF_AlphaNumericalEscChar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun127, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun201)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun201))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun128, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun129, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm)chars)));
}

/*}}}  */
/*{{{  SDF_DecimalEscChar SDF_makeDecimalEscCharDec0Underscore199(SDF_CHARLIST chars) */

SDF_DecimalEscChar SDF_makeDecimalEscCharDec0Underscore199(SDF_CHARLIST chars)
{
  return (SDF_DecimalEscChar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun127, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun202)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun202))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun128, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun129, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm)chars)));
}

/*}}}  */
/*{{{  SDF_DecimalEscChar SDF_makeDecimalEscCharDec200Underscore249(SDF_CHARLIST chars) */

SDF_DecimalEscChar SDF_makeDecimalEscCharDec200Underscore249(SDF_CHARLIST chars)
{
  return (SDF_DecimalEscChar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun127, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun202)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun202))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun128, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun129, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm)chars)));
}

/*}}}  */
/*{{{  SDF_DecimalEscChar SDF_makeDecimalEscCharDec250Underscore255(SDF_CHARLIST chars) */

SDF_DecimalEscChar SDF_makeDecimalEscCharDec250Underscore255(SDF_CHARLIST chars)
{
  return (SDF_DecimalEscChar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun127, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun202)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun202))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun128, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun129, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm)chars)));
}

/*}}}  */
/*{{{  SDF_EscChar SDF_makeEscCharAlphaNumeric(SDF_CHARLIST chars) */

SDF_EscChar SDF_makeEscCharAlphaNumeric(SDF_CHARLIST chars)
{
  return (SDF_EscChar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun127, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun203)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun203))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun128, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun129, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm)chars)));
}

/*}}}  */
/*{{{  SDF_EscChar SDF_makeEscCharDecimal(SDF_CHARLIST chars) */

SDF_EscChar SDF_makeEscCharDecimal(SDF_CHARLIST chars)
{
  return (SDF_EscChar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun127, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun203)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun203))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun128, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun129, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm)chars)));
}

/*}}}  */
/*{{{  SDF_LChar SDF_makeLCharNormal(SDF_CHARLIST chars) */

SDF_LChar SDF_makeLCharNormal(SDF_CHARLIST chars)
{
  return (SDF_LChar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun127, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun204)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun204))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun128, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun129, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm)chars)));
}

/*}}}  */
/*{{{  SDF_LChar SDF_makeLCharEscaped(SDF_CHARLIST chars) */

SDF_LChar SDF_makeLCharEscaped(SDF_CHARLIST chars)
{
  return (SDF_LChar)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun127, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun204)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun204))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun128, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun129, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm)chars)));
}

/*}}}  */
/*{{{  SDF_QLiteral SDF_makeQLiteralQuoted(SDF_CHARLIST chars) */

SDF_QLiteral SDF_makeQLiteralQuoted(SDF_CHARLIST chars)
{
  return (SDF_QLiteral)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun127, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun205)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun205))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun128, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun129, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm)chars)));
}

/*}}}  */
/*{{{  SDF_UQLiteral SDF_makeUQLiteralOneChar(SDF_CHARLIST chars) */

SDF_UQLiteral SDF_makeUQLiteralOneChar(SDF_CHARLIST chars)
{
  return (SDF_UQLiteral)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun127, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun206)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun206))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun128, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun129, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm)chars)));
}

/*}}}  */
/*{{{  SDF_UQLiteral SDF_makeUQLiteralMoreChars(SDF_CHARLIST chars) */

SDF_UQLiteral SDF_makeUQLiteralMoreChars(SDF_CHARLIST chars)
{
  return (SDF_UQLiteral)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun127, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun206)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun206))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun128, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun129, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm)chars)));
}

/*}}}  */
/*{{{  SDF_Literal SDF_makeLiteralQlit(SDF_QLiteral QLiteral) */

SDF_Literal SDF_makeLiteralQlit(SDF_QLiteral QLiteral)
{
  return (SDF_Literal)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun205)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun79))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun207)))))), (ATerm)ATmakeList1((ATerm)QLiteral));
}

/*}}}  */
/*{{{  SDF_Literal SDF_makeLiteralUqlit(SDF_UQLiteral UQLiteral) */

SDF_Literal SDF_makeLiteralUqlit(SDF_UQLiteral UQLiteral)
{
  return (SDF_Literal)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun206)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun79))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun208)))))), (ATerm)ATmakeList1((ATerm)UQLiteral));
}

/*}}}  */
/*{{{  SDF_ATermList SDF_makeATermListNotEmpty(SDF_OptLayout wsAfterBracketOpen, SDF_ATermElems elems, SDF_OptLayout wsAfterElems) */

SDF_ATermList SDF_makeATermListNotEmpty(SDF_OptLayout wsAfterBracketOpen, SDF_ATermElems elems, SDF_OptLayout wsAfterElems)
{
  return (SDF_ATermList)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun152))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl2(SDF_afun59, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun75)), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun60))))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun153))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun209))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun210)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun152))), (ATerm)wsAfterElems), (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl2(SDF_afun59, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun75)), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun60))))), (ATerm)elems)), (ATerm)wsAfterBracketOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun153))));
}

/*}}}  */
/*{{{  SDF_ATermElems SDF_makeATermElemsEmpty() */

SDF_ATermElems SDF_makeATermElemsEmpty()
{
  return (SDF_ATermElems)(ATerm)ATempty;
}

/*}}}  */
/*{{{  SDF_ATermElems SDF_makeATermElemsSingle(SDF_ATerm head) */

SDF_ATermElems SDF_makeATermElemsSingle(SDF_ATerm head)
{
  return (SDF_ATermElems)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  SDF_ATermElems SDF_makeATermElemsMany(SDF_ATerm head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_ATermElems tail) */

SDF_ATermElems SDF_makeATermElemsMany(SDF_ATerm head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_ATermElems tail)
{
  return (SDF_ATermElems)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterSep), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  SDF_ACon SDF_makeAConInt(SDF_IntCon IntCon) */

SDF_ACon SDF_makeAConInt(SDF_IntCon IntCon)
{
  return (SDF_ACon)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun193)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun211))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun212)))))), (ATerm)ATmakeList1((ATerm)IntCon));
}

/*}}}  */
/*{{{  SDF_ACon SDF_makeAConReal(SDF_RealCon RealCon) */

SDF_ACon SDF_makeAConReal(SDF_RealCon RealCon)
{
  return (SDF_ACon)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun196)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun211))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun213)))))), (ATerm)ATmakeList1((ATerm)RealCon));
}

/*}}}  */
/*{{{  SDF_AFun SDF_makeAFunDefault(SDF_Literal Literal) */

SDF_AFun SDF_makeAFunDefault(SDF_Literal Literal)
{
  return (SDF_AFun)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun79)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun214))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)Literal));
}

/*}}}  */
/*{{{  SDF_ATerm SDF_makeATermConstant(SDF_ACon ACon) */

SDF_ATerm SDF_makeATermConstant(SDF_ACon ACon)
{
  return (SDF_ATerm)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun211)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun75))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun215)))))), (ATerm)ATmakeList1((ATerm)ACon));
}

/*}}}  */
/*{{{  SDF_ATerm SDF_makeATermList(SDF_ATermList list) */

SDF_ATerm SDF_makeATermList(SDF_ATermList list)
{
  return (SDF_ATerm)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun209)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun75))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun62)))))), (ATerm)ATmakeList1((ATerm)list));
}

/*}}}  */
/*{{{  SDF_ATerm SDF_makeATermFun(SDF_AFun fun) */

SDF_ATerm SDF_makeATermFun(SDF_AFun fun)
{
  return (SDF_ATerm)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun214)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun75))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun216)))))), (ATerm)ATmakeList1((ATerm)fun));
}

/*}}}  */
/*{{{  SDF_ATerm SDF_makeATermAppl(SDF_AFun fun, SDF_OptLayout wsAfterFun, SDF_OptLayout wsAfterParenOpen, SDF_ATermArgs args, SDF_OptLayout wsAfterArgs) */

SDF_ATerm SDF_makeATermAppl(SDF_AFun fun, SDF_OptLayout wsAfterFun, SDF_OptLayout wsAfterParenOpen, SDF_ATermArgs args, SDF_OptLayout wsAfterArgs)
{
  return (SDF_ATerm)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl2(SDF_afun84, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun75)), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun60))))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun214)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun75))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun217)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)wsAfterArgs), (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl2(SDF_afun84, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun75)), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun60))))), (ATerm)args)), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))), (ATerm)wsAfterFun), (ATerm)fun));
}

/*}}}  */
/*{{{  SDF_ATerm SDF_makeATermAnnotatedConstant(SDF_ACon ACon, SDF_OptLayout wsAfterACon, SDF_Ann Ann) */

SDF_ATerm SDF_makeATermAnnotatedConstant(SDF_ACon ACon, SDF_OptLayout wsAfterACon, SDF_Ann Ann)
{
  return (SDF_ATerm)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun218)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun211)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun75))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun219)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)Ann), (ATerm)wsAfterACon), (ATerm)ACon));
}

/*}}}  */
/*{{{  SDF_ATerm SDF_makeATermAnnotatedList(SDF_ATermList list, SDF_OptLayout wsAfterList, SDF_Ann Ann) */

SDF_ATerm SDF_makeATermAnnotatedList(SDF_ATermList list, SDF_OptLayout wsAfterList, SDF_Ann Ann)
{
  return (SDF_ATerm)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun218)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun209)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun75))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun220)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)Ann), (ATerm)wsAfterList), (ATerm)list));
}

/*}}}  */
/*{{{  SDF_ATerm SDF_makeATermAnnotatedFun(SDF_AFun fun, SDF_OptLayout wsAfterFun, SDF_Ann Ann) */

SDF_ATerm SDF_makeATermAnnotatedFun(SDF_AFun fun, SDF_OptLayout wsAfterFun, SDF_Ann Ann)
{
  return (SDF_ATerm)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun218)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun214)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun75))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun221)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)Ann), (ATerm)wsAfterFun), (ATerm)fun));
}

/*}}}  */
/*{{{  SDF_ATerm SDF_makeATermAnnotatedAppl(SDF_AFun fun, SDF_OptLayout wsAfterFun, SDF_OptLayout wsAfterParenOpen, SDF_ATermArgs args, SDF_OptLayout wsAfterArgs, SDF_OptLayout wsAfterParenClose, SDF_Ann Ann) */

SDF_ATerm SDF_makeATermAnnotatedAppl(SDF_AFun fun, SDF_OptLayout wsAfterFun, SDF_OptLayout wsAfterParenOpen, SDF_ATermArgs args, SDF_OptLayout wsAfterArgs, SDF_OptLayout wsAfterParenClose, SDF_Ann Ann)
{
  return (SDF_ATerm)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun218)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl2(SDF_afun84, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun75)), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun60))))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun214)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun75))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun222)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)Ann), (ATerm)wsAfterParenClose), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun34))), (ATerm)wsAfterArgs), (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl2(SDF_afun84, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun75)), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun60))))), (ATerm)args)), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun35))), (ATerm)wsAfterFun), (ATerm)fun));
}

/*}}}  */
/*{{{  SDF_ATermArgs SDF_makeATermArgsSingle(SDF_ATerm head) */

SDF_ATermArgs SDF_makeATermArgsSingle(SDF_ATerm head)
{
  return (SDF_ATermArgs)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  SDF_ATermArgs SDF_makeATermArgsMany(SDF_ATerm head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_ATermArgs tail) */

SDF_ATermArgs SDF_makeATermArgsMany(SDF_ATerm head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_ATermArgs tail)
{
  return (SDF_ATermArgs)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterSep), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  SDF_Ann SDF_makeAnnAnnotation(SDF_OptLayout wsAfterBraceOpen, SDF_ATermAnnos annos, SDF_OptLayout wsAfterAnnos) */

SDF_Ann SDF_makeAnnAnnotation(SDF_OptLayout wsAfterBraceOpen, SDF_ATermAnnos annos, SDF_OptLayout wsAfterAnnos)
{
  return (SDF_Ann)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun96))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl2(SDF_afun84, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun75)), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun60))))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun97))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun218))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun223)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun96))), (ATerm)wsAfterAnnos), (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl2(SDF_afun84, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun75)), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun60))))), (ATerm)annos)), (ATerm)wsAfterBraceOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun97))));
}

/*}}}  */
/*{{{  SDF_ATermAnnos SDF_makeATermAnnosSingle(SDF_ATerm head) */

SDF_ATermAnnos SDF_makeATermAnnosSingle(SDF_ATerm head)
{
  return (SDF_ATermAnnos)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  SDF_ATermAnnos SDF_makeATermAnnosMany(SDF_ATerm head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_ATermAnnos tail) */

SDF_ATermAnnos SDF_makeATermAnnosMany(SDF_ATerm head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_ATermAnnos tail)
{
  return (SDF_ATermAnnos)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterSep), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  SDF_Attributes SDF_makeAttributesAttrs(SDF_OptLayout wsAfterBraceOpen, SDF_AttributeList list, SDF_OptLayout wsAfterList) */

SDF_Attributes SDF_makeAttributesAttrs(SDF_OptLayout wsAfterBraceOpen, SDF_AttributeList list, SDF_OptLayout wsAfterList)
{
  return (SDF_Attributes)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun96))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl2(SDF_afun59, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun67)), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun60))))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun97))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun123))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun224)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun96))), (ATerm)wsAfterList), (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl2(SDF_afun59, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun67)), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun60))))), (ATerm)list)), (ATerm)wsAfterBraceOpen), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun97))));
}

/*}}}  */
/*{{{  SDF_Attributes SDF_makeAttributesNoAttrs() */

SDF_Attributes SDF_makeAttributesNoAttrs()
{
  return (SDF_Attributes)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun123))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun225)))))), (ATerm)ATempty);
}

/*}}}  */
/*{{{  SDF_AttributeList SDF_makeAttributeListEmpty() */

SDF_AttributeList SDF_makeAttributeListEmpty()
{
  return (SDF_AttributeList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  SDF_AttributeList SDF_makeAttributeListSingle(SDF_Attribute head) */

SDF_AttributeList SDF_makeAttributeListSingle(SDF_Attribute head)
{
  return (SDF_AttributeList)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  SDF_AttributeList SDF_makeAttributeListMany(SDF_Attribute head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_AttributeList tail) */

SDF_AttributeList SDF_makeAttributeListMany(SDF_Attribute head, SDF_OptLayout wsAfterFirst, char * sep, SDF_OptLayout wsAfterSep, SDF_AttributeList tail)
{
  return (SDF_AttributeList)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterSep), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  SDF_Productions SDF_makeProductionsDefault(SDF_ProductionList list) */

SDF_Productions SDF_makeProductionsDefault(SDF_ProductionList list)
{
  return (SDF_Productions)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun124))))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun21))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl1(SDF_afun47, (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun45, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun124))))), (ATerm)list)));
}

/*}}}  */
/*{{{  SDF_ProductionList SDF_makeProductionListEmpty() */

SDF_ProductionList SDF_makeProductionListEmpty()
{
  return (SDF_ProductionList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  SDF_ProductionList SDF_makeProductionListSingle(SDF_Production head) */

SDF_ProductionList SDF_makeProductionListSingle(SDF_Production head)
{
  return (SDF_ProductionList)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  SDF_ProductionList SDF_makeProductionListMany(SDF_Production head, SDF_OptLayout wsAfterFirst, SDF_ProductionList tail) */

SDF_ProductionList SDF_makeProductionListMany(SDF_Production head, SDF_OptLayout wsAfterFirst, SDF_ProductionList tail)
{
  return (SDF_ProductionList)(ATerm)ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  SDF_SDF SDF_makeSDFDefinition(SDF_OptLayout wsAfterDefinition, SDF_Definition Definition) */

SDF_SDF SDF_makeSDFDefinition(SDF_OptLayout wsAfterDefinition, SDF_Definition Definition)
{
  return (SDF_SDF)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun181)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun226))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun227))), (ATerm)ATmakeAppl1(SDF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun11, (ATerm)ATmakeAppl1(SDF_afun12, (ATerm)ATmakeAppl0(SDF_afun226)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)Definition), (ATerm)wsAfterDefinition), (ATerm)ATmakeAppl1(SDF_afun7, (ATerm)ATmakeAppl0(SDF_afun226))));
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_makeOptLayoutAbsent() */

SDF_OptLayout SDF_makeOptLayoutAbsent()
{
  return (SDF_OptLayout)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATempty);
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_makeOptLayoutPresent(SDF_CHARLIST chars) */

SDF_OptLayout SDF_makeOptLayoutPresent(SDF_CHARLIST chars)
{
  return (SDF_OptLayout)(ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl0(SDF_afun6))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6))), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)chars);
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartSDF(SDF_OptLayout wsBefore, SDF_SDF topSDF, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartSDF(SDF_OptLayout wsBefore, SDF_SDF topSDF, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun227)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topSDF), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartProductions(SDF_OptLayout wsBefore, SDF_Productions topProductions, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartProductions(SDF_OptLayout wsBefore, SDF_Productions topProductions, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun21)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topProductions), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartProduction(SDF_OptLayout wsBefore, SDF_Production topProduction, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartProduction(SDF_OptLayout wsBefore, SDF_Production topProduction, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun124)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topProduction), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartAttributes(SDF_OptLayout wsBefore, SDF_Attributes topAttributes, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartAttributes(SDF_OptLayout wsBefore, SDF_Attributes topAttributes, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun123)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topAttributes), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartAttribute(SDF_OptLayout wsBefore, SDF_Attribute topAttribute, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartAttribute(SDF_OptLayout wsBefore, SDF_Attribute topAttribute, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun67)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topAttribute), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartAnn(SDF_OptLayout wsBefore, SDF_Ann topAnn, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartAnn(SDF_OptLayout wsBefore, SDF_Ann topAnn, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun218)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topAnn), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartATerm(SDF_OptLayout wsBefore, SDF_ATerm topATerm, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartATerm(SDF_OptLayout wsBefore, SDF_ATerm topATerm, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun75)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topATerm), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartAFun(SDF_OptLayout wsBefore, SDF_AFun topAFun, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartAFun(SDF_OptLayout wsBefore, SDF_AFun topAFun, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun214)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topAFun), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartACon(SDF_OptLayout wsBefore, SDF_ACon topACon, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartACon(SDF_OptLayout wsBefore, SDF_ACon topACon, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun211)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topACon), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartATermList(SDF_OptLayout wsBefore, SDF_ATermList topATermList, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartATermList(SDF_OptLayout wsBefore, SDF_ATermList topATermList, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun209)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topATermList), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartQLiteral(SDF_OptLayout wsBefore, SDF_QLiteral topQLiteral, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartQLiteral(SDF_OptLayout wsBefore, SDF_QLiteral topQLiteral, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun205)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topQLiteral), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartUQLiteral(SDF_OptLayout wsBefore, SDF_UQLiteral topUQLiteral, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartUQLiteral(SDF_OptLayout wsBefore, SDF_UQLiteral topUQLiteral, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun206)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topUQLiteral), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartLiteral(SDF_OptLayout wsBefore, SDF_Literal topLiteral, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartLiteral(SDF_OptLayout wsBefore, SDF_Literal topLiteral, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun79)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topLiteral), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartIntCon(SDF_OptLayout wsBefore, SDF_IntCon topIntCon, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartIntCon(SDF_OptLayout wsBefore, SDF_IntCon topIntCon, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun193)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topIntCon), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartNatCon(SDF_OptLayout wsBefore, SDF_NatCon topNatCon, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartNatCon(SDF_OptLayout wsBefore, SDF_NatCon topNatCon, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun100)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topNatCon), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartRealCon(SDF_OptLayout wsBefore, SDF_RealCon topRealCon, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartRealCon(SDF_OptLayout wsBefore, SDF_RealCon topRealCon, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun196)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topRealCon), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartOptExp(SDF_OptLayout wsBefore, SDF_OptExp topOptExp, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartOptExp(SDF_OptLayout wsBefore, SDF_OptExp topOptExp, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun195)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topOptExp), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartSymbols(SDF_OptLayout wsBefore, SDF_Symbols topSymbols, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartSymbols(SDF_OptLayout wsBefore, SDF_Symbols topSymbols, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun15)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topSymbols), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartSymbol(SDF_OptLayout wsBefore, SDF_Symbol topSymbol, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartSymbol(SDF_OptLayout wsBefore, SDF_Symbol topSymbol, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun41)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topSymbol), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartGrammar(SDF_OptLayout wsBefore, SDF_Grammar topGrammar, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartGrammar(SDF_OptLayout wsBefore, SDF_Grammar topGrammar, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun9)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topGrammar), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartImpSection(SDF_OptLayout wsBefore, SDF_ImpSection topImpSection, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartImpSection(SDF_OptLayout wsBefore, SDF_ImpSection topImpSection, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun19)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topImpSection), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartDefinition(SDF_OptLayout wsBefore, SDF_Definition topDefinition, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartDefinition(SDF_OptLayout wsBefore, SDF_Definition topDefinition, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun181)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topDefinition), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartModule(SDF_OptLayout wsBefore, SDF_Module topModule, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartModule(SDF_OptLayout wsBefore, SDF_Module topModule, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun180)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topModule), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartSections(SDF_OptLayout wsBefore, SDF_Sections topSections, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartSections(SDF_OptLayout wsBefore, SDF_Sections topSections, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun182)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topSections), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartSection(SDF_OptLayout wsBefore, SDF_Section topSection, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartSection(SDF_OptLayout wsBefore, SDF_Section topSection, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun185)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topSection), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartImports(SDF_OptLayout wsBefore, SDF_Imports topImports, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartImports(SDF_OptLayout wsBefore, SDF_Imports topImports, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun189)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topImports), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartImport(SDF_OptLayout wsBefore, SDF_Import topImport, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartImport(SDF_OptLayout wsBefore, SDF_Import topImport, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun191)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topImport), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartModuleName(SDF_OptLayout wsBefore, SDF_ModuleName topModuleName, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartModuleName(SDF_OptLayout wsBefore, SDF_ModuleName topModuleName, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun73)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topModuleName), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartModuleId(SDF_OptLayout wsBefore, SDF_ModuleId topModuleId, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartModuleId(SDF_OptLayout wsBefore, SDF_ModuleId topModuleId, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun179)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topModuleId), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartRenamings(SDF_OptLayout wsBefore, SDF_Renamings topRenamings, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartRenamings(SDF_OptLayout wsBefore, SDF_Renamings topRenamings, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun174)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topRenamings), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartRenaming(SDF_OptLayout wsBefore, SDF_Renaming topRenaming, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartRenaming(SDF_OptLayout wsBefore, SDF_Renaming topRenaming, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun173)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topRenaming), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartPriorities(SDF_OptLayout wsBefore, SDF_Priorities topPriorities, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartPriorities(SDF_OptLayout wsBefore, SDF_Priorities topPriorities, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun17)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topPriorities), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartPriority(SDF_OptLayout wsBefore, SDF_Priority topPriority, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartPriority(SDF_OptLayout wsBefore, SDF_Priority topPriority, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun171)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topPriority), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartGroup(SDF_OptLayout wsBefore, SDF_Group topGroup, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartGroup(SDF_OptLayout wsBefore, SDF_Group topGroup, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun167)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topGroup), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartAssociativity(SDF_OptLayout wsBefore, SDF_Associativity topAssociativity, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartAssociativity(SDF_OptLayout wsBefore, SDF_Associativity topAssociativity, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun71)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topAssociativity), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartCharClass(SDF_OptLayout wsBefore, SDF_CharClass topCharClass, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartCharClass(SDF_OptLayout wsBefore, SDF_CharClass topCharClass, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun48)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topCharClass), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartShortChar(SDF_OptLayout wsBefore, SDF_ShortChar topShortChar, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartShortChar(SDF_OptLayout wsBefore, SDF_ShortChar topShortChar, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun131)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topShortChar), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartNumChar(SDF_OptLayout wsBefore, SDF_NumChar topNumChar, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartNumChar(SDF_OptLayout wsBefore, SDF_NumChar topNumChar, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun130)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topNumChar), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartCharacter(SDF_OptLayout wsBefore, SDF_Character topCharacter, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartCharacter(SDF_OptLayout wsBefore, SDF_Character topCharacter, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun132)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topCharacter), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartSort(SDF_OptLayout wsBefore, SDF_Sort topSort, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartSort(SDF_OptLayout wsBefore, SDF_Sort topSort, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun82)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topSort), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartRestrictions(SDF_OptLayout wsBefore, SDF_Restrictions topRestrictions, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartRestrictions(SDF_OptLayout wsBefore, SDF_Restrictions topRestrictions, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun13)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topRestrictions), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartRestriction(SDF_OptLayout wsBefore, SDF_Restriction topRestriction, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartRestriction(SDF_OptLayout wsBefore, SDF_Restriction topRestriction, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun64)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topRestriction), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartLookaheads(SDF_OptLayout wsBefore, SDF_Lookaheads topLookaheads, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartLookaheads(SDF_OptLayout wsBefore, SDF_Lookaheads topLookaheads, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun51)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topLookaheads), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartLookahead(SDF_OptLayout wsBefore, SDF_Lookahead topLookahead, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartLookahead(SDF_OptLayout wsBefore, SDF_Lookahead topLookahead, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun49)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topLookahead), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartAliases(SDF_OptLayout wsBefore, SDF_Aliases topAliases, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartAliases(SDF_OptLayout wsBefore, SDF_Aliases topAliases, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun4)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topAliases), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  SDF_Start SDF_makeStartAlias(SDF_OptLayout wsBefore, SDF_Alias topAlias, SDF_OptLayout wsAfter, int ambCnt) */

SDF_Start SDF_makeStartAlias(SDF_OptLayout wsBefore, SDF_Alias topAlias, SDF_OptLayout wsAfter, int ambCnt)
{
  return (SDF_Start)(ATerm)ATmakeAppl2(SDF_afun228, (ATerm)ATmakeAppl2(SDF_afun0, (ATerm)ATmakeAppl3(SDF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun43)))), (ATerm)ATmakeAppl1(SDF_afun2, (ATerm)ATmakeAppl1(SDF_afun5, (ATerm)ATmakeAppl0(SDF_afun6)))), (ATerm)ATmakeAppl1(SDF_afun3, (ATerm)ATmakeAppl0(SDF_afun119)), (ATerm)ATmakeAppl0(SDF_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topAlias), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool SDF_isEqualGrammar(SDF_Grammar arg0, SDF_Grammar arg1)
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

ATbool SDF_isEqualAttribute(SDF_Attribute arg0, SDF_Attribute arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualSymbol(SDF_Symbol arg0, SDF_Symbol arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualProduction(SDF_Production arg0, SDF_Production arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualSymbolArguments(SDF_SymbolArguments arg0, SDF_SymbolArguments arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualSort(SDF_Sort arg0, SDF_Sort arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualSymbolParameters(SDF_SymbolParameters arg0, SDF_SymbolParameters arg1)
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

ATbool SDF_isEqualSymbolTail(SDF_SymbolTail arg0, SDF_SymbolTail arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualSymbolRest(SDF_SymbolRest arg0, SDF_SymbolRest arg1)
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

ATbool SDF_isEqualSymbols(SDF_Symbols arg0, SDF_Symbols arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualSymbolList(SDF_SymbolList arg0, SDF_SymbolList arg1)
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

ATbool SDF_isEqualNatCon(SDF_NatCon arg0, SDF_NatCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualIntCon(SDF_IntCon arg0, SDF_IntCon arg1)
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

ATbool SDF_isEqualQLiteral(SDF_QLiteral arg0, SDF_QLiteral arg1)
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

ATbool SDF_isEqualATermList(SDF_ATermList arg0, SDF_ATermList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualATermElems(SDF_ATermElems arg0, SDF_ATermElems arg1)
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

ATbool SDF_isEqualATermArgs(SDF_ATermArgs arg0, SDF_ATermArgs arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualAnn(SDF_Ann arg0, SDF_Ann arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualATermAnnos(SDF_ATermAnnos arg0, SDF_ATermAnnos arg1)
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

ATbool SDF_isEqualProductions(SDF_Productions arg0, SDF_Productions arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualProductionList(SDF_ProductionList arg0, SDF_ProductionList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualSDF(SDF_SDF arg0, SDF_SDF arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualOptLayout(SDF_OptLayout arg0, SDF_OptLayout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SDF_isEqualStart(SDF_Start arg0, SDF_Start arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  SDF_Grammar accessors */

/*{{{  ATbool SDF_isValidGrammar(SDF_Grammar arg) */

ATbool SDF_isValidGrammar(SDF_Grammar arg)
{
  if (SDF_isGrammarAliases(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarSorts(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarPriorities(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarImpSection(arg)) {
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
  else if (SDF_isGrammarEmptyGrammar(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarConcGrammars(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarBracket(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarSyntax(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarLexicalPriorities(arg)) {
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
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SDF_isGrammarAliases(SDF_Grammar arg) */

inline ATbool SDF_isGrammarAliases(SDF_Grammar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternGrammarAliases, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isGrammarRestrictions(SDF_Grammar arg) */

inline ATbool SDF_isGrammarRestrictions(SDF_Grammar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternGrammarRestrictions, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isGrammarSorts(SDF_Grammar arg) */

inline ATbool SDF_isGrammarSorts(SDF_Grammar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternGrammarSorts, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isGrammarPriorities(SDF_Grammar arg) */

inline ATbool SDF_isGrammarPriorities(SDF_Grammar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternGrammarPriorities, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isGrammarImpSection(SDF_Grammar arg) */

inline ATbool SDF_isGrammarImpSection(SDF_Grammar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternGrammarImpSection, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isGrammarLexicalSyntax(SDF_Grammar arg) */

inline ATbool SDF_isGrammarLexicalSyntax(SDF_Grammar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternGrammarLexicalSyntax, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isGrammarContextFreeSyntax(SDF_Grammar arg) */

inline ATbool SDF_isGrammarContextFreeSyntax(SDF_Grammar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternGrammarContextFreeSyntax, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isGrammarVariables(SDF_Grammar arg) */

inline ATbool SDF_isGrammarVariables(SDF_Grammar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternGrammarVariables, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isGrammarLexicalVariables(SDF_Grammar arg) */

inline ATbool SDF_isGrammarLexicalVariables(SDF_Grammar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternGrammarLexicalVariables, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isGrammarEmptyGrammar(SDF_Grammar arg) */

inline ATbool SDF_isGrammarEmptyGrammar(SDF_Grammar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternGrammarEmptyGrammar);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isGrammarConcGrammars(SDF_Grammar arg) */

inline ATbool SDF_isGrammarConcGrammars(SDF_Grammar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternGrammarConcGrammars, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isGrammarBracket(SDF_Grammar arg) */

inline ATbool SDF_isGrammarBracket(SDF_Grammar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternGrammarBracket, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isGrammarSyntax(SDF_Grammar arg) */

inline ATbool SDF_isGrammarSyntax(SDF_Grammar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternGrammarSyntax, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isGrammarLexicalPriorities(SDF_Grammar arg) */

inline ATbool SDF_isGrammarLexicalPriorities(SDF_Grammar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternGrammarLexicalPriorities, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isGrammarContextFreePriorities(SDF_Grammar arg) */

inline ATbool SDF_isGrammarContextFreePriorities(SDF_Grammar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternGrammarContextFreePriorities, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isGrammarLexicalRestrictions(SDF_Grammar arg) */

inline ATbool SDF_isGrammarLexicalRestrictions(SDF_Grammar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternGrammarLexicalRestrictions, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isGrammarContextFreeRestrictions(SDF_Grammar arg) */

inline ATbool SDF_isGrammarContextFreeRestrictions(SDF_Grammar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternGrammarContextFreeRestrictions, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
/*{{{  SDF_OptLayout SDF_getGrammarWsAfterAliases(SDF_Grammar arg) */

SDF_OptLayout SDF_getGrammarWsAfterAliases(SDF_Grammar arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterAliases(SDF_Grammar arg, SDF_OptLayout wsAfterAliases) */

SDF_Grammar SDF_setGrammarWsAfterAliases(SDF_Grammar arg, SDF_OptLayout wsAfterAliases)
{
  if (SDF_isGrammarAliases(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterAliases, 1), 1);
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
  
    return (SDF_Aliases)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarAliases(SDF_Grammar arg, SDF_Aliases Aliases) */

SDF_Grammar SDF_setGrammarAliases(SDF_Grammar arg, SDF_Aliases Aliases)
{
  if (SDF_isGrammarAliases(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Aliases, 2), 1);
  }

  ATabort("Grammar has no Aliases: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarWsAfterRestrictions(SDF_Grammar arg) */

ATbool SDF_hasGrammarWsAfterRestrictions(SDF_Grammar arg)
{
  if (SDF_isGrammarRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarLexicalRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarContextFreeRestrictions(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getGrammarWsAfterRestrictions(SDF_Grammar arg) */

SDF_OptLayout SDF_getGrammarWsAfterRestrictions(SDF_Grammar arg)
{
  if (SDF_isGrammarRestrictions(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (SDF_isGrammarLexicalRestrictions(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterRestrictions(SDF_Grammar arg, SDF_OptLayout wsAfterRestrictions) */

SDF_Grammar SDF_setGrammarWsAfterRestrictions(SDF_Grammar arg, SDF_OptLayout wsAfterRestrictions)
{
  if (SDF_isGrammarRestrictions(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterRestrictions, 1), 1);
  }
  else if (SDF_isGrammarLexicalRestrictions(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterRestrictions, 3), 1);
  }
  else if (SDF_isGrammarContextFreeRestrictions(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterRestrictions, 3), 1);
  }

  ATabort("Grammar has no WsAfterRestrictions: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarRestrictions(SDF_Grammar arg) */

ATbool SDF_hasGrammarRestrictions(SDF_Grammar arg)
{
  if (SDF_isGrammarRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarLexicalRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarContextFreeRestrictions(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Restrictions SDF_getGrammarRestrictions(SDF_Grammar arg) */

SDF_Restrictions SDF_getGrammarRestrictions(SDF_Grammar arg)
{
  if (SDF_isGrammarRestrictions(arg)) {
    return (SDF_Restrictions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else if (SDF_isGrammarLexicalRestrictions(arg)) {
    return (SDF_Restrictions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (SDF_Restrictions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarRestrictions(SDF_Grammar arg, SDF_Restrictions Restrictions) */

SDF_Grammar SDF_setGrammarRestrictions(SDF_Grammar arg, SDF_Restrictions Restrictions)
{
  if (SDF_isGrammarRestrictions(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Restrictions, 2), 1);
  }
  else if (SDF_isGrammarLexicalRestrictions(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Restrictions, 4), 1);
  }
  else if (SDF_isGrammarContextFreeRestrictions(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Restrictions, 4), 1);
  }

  ATabort("Grammar has no Restrictions: %t\n", arg);
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
/*{{{  SDF_OptLayout SDF_getGrammarWsAfterSorts(SDF_Grammar arg) */

SDF_OptLayout SDF_getGrammarWsAfterSorts(SDF_Grammar arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterSorts(SDF_Grammar arg, SDF_OptLayout wsAfterSorts) */

SDF_Grammar SDF_setGrammarWsAfterSorts(SDF_Grammar arg, SDF_OptLayout wsAfterSorts)
{
  if (SDF_isGrammarSorts(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSorts, 1), 1);
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
  
    return (SDF_Symbols)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarSymbols(SDF_Grammar arg, SDF_Symbols Symbols) */

SDF_Grammar SDF_setGrammarSymbols(SDF_Grammar arg, SDF_Symbols Symbols)
{
  if (SDF_isGrammarSorts(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Symbols, 2), 1);
  }

  ATabort("Grammar has no Symbols: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarWsAfterPriorities(SDF_Grammar arg) */

ATbool SDF_hasGrammarWsAfterPriorities(SDF_Grammar arg)
{
  if (SDF_isGrammarPriorities(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarLexicalPriorities(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarContextFreePriorities(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getGrammarWsAfterPriorities(SDF_Grammar arg) */

SDF_OptLayout SDF_getGrammarWsAfterPriorities(SDF_Grammar arg)
{
  if (SDF_isGrammarPriorities(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (SDF_isGrammarLexicalPriorities(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterPriorities(SDF_Grammar arg, SDF_OptLayout wsAfterPriorities) */

SDF_Grammar SDF_setGrammarWsAfterPriorities(SDF_Grammar arg, SDF_OptLayout wsAfterPriorities)
{
  if (SDF_isGrammarPriorities(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterPriorities, 1), 1);
  }
  else if (SDF_isGrammarLexicalPriorities(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterPriorities, 3), 1);
  }
  else if (SDF_isGrammarContextFreePriorities(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterPriorities, 3), 1);
  }

  ATabort("Grammar has no WsAfterPriorities: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarPriorities(SDF_Grammar arg) */

ATbool SDF_hasGrammarPriorities(SDF_Grammar arg)
{
  if (SDF_isGrammarPriorities(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarLexicalPriorities(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarContextFreePriorities(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Priorities SDF_getGrammarPriorities(SDF_Grammar arg) */

SDF_Priorities SDF_getGrammarPriorities(SDF_Grammar arg)
{
  if (SDF_isGrammarPriorities(arg)) {
    return (SDF_Priorities)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else if (SDF_isGrammarLexicalPriorities(arg)) {
    return (SDF_Priorities)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (SDF_Priorities)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarPriorities(SDF_Grammar arg, SDF_Priorities Priorities) */

SDF_Grammar SDF_setGrammarPriorities(SDF_Grammar arg, SDF_Priorities Priorities)
{
  if (SDF_isGrammarPriorities(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Priorities, 2), 1);
  }
  else if (SDF_isGrammarLexicalPriorities(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Priorities, 4), 1);
  }
  else if (SDF_isGrammarContextFreePriorities(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Priorities, 4), 1);
  }

  ATabort("Grammar has no Priorities: %t\n", arg);
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
  
    return (SDF_ImpSection)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarImpSection(SDF_Grammar arg, SDF_ImpSection ImpSection) */

SDF_Grammar SDF_setGrammarImpSection(SDF_Grammar arg, SDF_ImpSection ImpSection)
{
  if (SDF_isGrammarImpSection(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ImpSection, 0), 1);
  }

  ATabort("Grammar has no ImpSection: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarWsAfterLexical(SDF_Grammar arg) */

ATbool SDF_hasGrammarWsAfterLexical(SDF_Grammar arg)
{
  if (SDF_isGrammarLexicalSyntax(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarLexicalVariables(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarLexicalPriorities(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarLexicalRestrictions(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getGrammarWsAfterLexical(SDF_Grammar arg) */

SDF_OptLayout SDF_getGrammarWsAfterLexical(SDF_Grammar arg)
{
  if (SDF_isGrammarLexicalSyntax(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (SDF_isGrammarLexicalVariables(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (SDF_isGrammarLexicalPriorities(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterLexical(SDF_Grammar arg, SDF_OptLayout wsAfterLexical) */

SDF_Grammar SDF_setGrammarWsAfterLexical(SDF_Grammar arg, SDF_OptLayout wsAfterLexical)
{
  if (SDF_isGrammarLexicalSyntax(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLexical, 1), 1);
  }
  else if (SDF_isGrammarLexicalVariables(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLexical, 1), 1);
  }
  else if (SDF_isGrammarLexicalPriorities(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLexical, 1), 1);
  }
  else if (SDF_isGrammarLexicalRestrictions(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLexical, 1), 1);
  }

  ATabort("Grammar has no WsAfterLexical: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarWsAfterSyntax(SDF_Grammar arg) */

ATbool SDF_hasGrammarWsAfterSyntax(SDF_Grammar arg)
{
  if (SDF_isGrammarLexicalSyntax(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarContextFreeSyntax(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarSyntax(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getGrammarWsAfterSyntax(SDF_Grammar arg) */

SDF_OptLayout SDF_getGrammarWsAfterSyntax(SDF_Grammar arg)
{
  if (SDF_isGrammarLexicalSyntax(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (SDF_isGrammarContextFreeSyntax(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterSyntax(SDF_Grammar arg, SDF_OptLayout wsAfterSyntax) */

SDF_Grammar SDF_setGrammarWsAfterSyntax(SDF_Grammar arg, SDF_OptLayout wsAfterSyntax)
{
  if (SDF_isGrammarLexicalSyntax(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSyntax, 3), 1);
  }
  else if (SDF_isGrammarContextFreeSyntax(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSyntax, 3), 1);
  }
  else if (SDF_isGrammarSyntax(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSyntax, 1), 1);
  }

  ATabort("Grammar has no WsAfterSyntax: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarProductions(SDF_Grammar arg) */

ATbool SDF_hasGrammarProductions(SDF_Grammar arg)
{
  if (SDF_isGrammarLexicalSyntax(arg)) {
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
  else if (SDF_isGrammarSyntax(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Productions SDF_getGrammarProductions(SDF_Grammar arg) */

SDF_Productions SDF_getGrammarProductions(SDF_Grammar arg)
{
  if (SDF_isGrammarLexicalSyntax(arg)) {
    return (SDF_Productions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (SDF_isGrammarContextFreeSyntax(arg)) {
    return (SDF_Productions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (SDF_isGrammarVariables(arg)) {
    return (SDF_Productions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else if (SDF_isGrammarLexicalVariables(arg)) {
    return (SDF_Productions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (SDF_Productions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarProductions(SDF_Grammar arg, SDF_Productions Productions) */

SDF_Grammar SDF_setGrammarProductions(SDF_Grammar arg, SDF_Productions Productions)
{
  if (SDF_isGrammarLexicalSyntax(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Productions, 4), 1);
  }
  else if (SDF_isGrammarContextFreeSyntax(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Productions, 4), 1);
  }
  else if (SDF_isGrammarVariables(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Productions, 2), 1);
  }
  else if (SDF_isGrammarLexicalVariables(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Productions, 4), 1);
  }
  else if (SDF_isGrammarSyntax(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Productions, 2), 1);
  }

  ATabort("Grammar has no Productions: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasGrammarWsAfterContextFree(SDF_Grammar arg) */

ATbool SDF_hasGrammarWsAfterContextFree(SDF_Grammar arg)
{
  if (SDF_isGrammarContextFreeSyntax(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarContextFreePriorities(arg)) {
    return ATtrue;
  }
  else if (SDF_isGrammarContextFreeRestrictions(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getGrammarWsAfterContextFree(SDF_Grammar arg) */

SDF_OptLayout SDF_getGrammarWsAfterContextFree(SDF_Grammar arg)
{
  if (SDF_isGrammarContextFreeSyntax(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (SDF_isGrammarContextFreePriorities(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterContextFree(SDF_Grammar arg, SDF_OptLayout wsAfterContextFree) */

SDF_Grammar SDF_setGrammarWsAfterContextFree(SDF_Grammar arg, SDF_OptLayout wsAfterContextFree)
{
  if (SDF_isGrammarContextFreeSyntax(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterContextFree, 1), 1);
  }
  else if (SDF_isGrammarContextFreePriorities(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterContextFree, 1), 1);
  }
  else if (SDF_isGrammarContextFreeRestrictions(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterContextFree, 1), 1);
  }

  ATabort("Grammar has no WsAfterContextFree: %t\n", arg);
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
/*{{{  SDF_OptLayout SDF_getGrammarWsAfterVariables(SDF_Grammar arg) */

SDF_OptLayout SDF_getGrammarWsAfterVariables(SDF_Grammar arg)
{
  if (SDF_isGrammarVariables(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterVariables(SDF_Grammar arg, SDF_OptLayout wsAfterVariables) */

SDF_Grammar SDF_setGrammarWsAfterVariables(SDF_Grammar arg, SDF_OptLayout wsAfterVariables)
{
  if (SDF_isGrammarVariables(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterVariables, 1), 1);
  }
  else if (SDF_isGrammarLexicalVariables(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterVariables, 3), 1);
  }

  ATabort("Grammar has no WsAfterVariables: %t\n", arg);
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
  
    return (SDF_Grammar)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarLeft(SDF_Grammar arg, SDF_Grammar left) */

SDF_Grammar SDF_setGrammarLeft(SDF_Grammar arg, SDF_Grammar left)
{
  if (SDF_isGrammarConcGrammars(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)left, 0), 1);
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
/*{{{  SDF_OptLayout SDF_getGrammarWsAfterLeft(SDF_Grammar arg) */

SDF_OptLayout SDF_getGrammarWsAfterLeft(SDF_Grammar arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterLeft(SDF_Grammar arg, SDF_OptLayout wsAfterLeft) */

SDF_Grammar SDF_setGrammarWsAfterLeft(SDF_Grammar arg, SDF_OptLayout wsAfterLeft)
{
  if (SDF_isGrammarConcGrammars(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLeft, 1), 1);
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
  
    return (SDF_Grammar)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarRight(SDF_Grammar arg, SDF_Grammar right) */

SDF_Grammar SDF_setGrammarRight(SDF_Grammar arg, SDF_Grammar right)
{
  if (SDF_isGrammarConcGrammars(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)right, 2), 1);
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
/*{{{  SDF_OptLayout SDF_getGrammarWsAfterParenOpen(SDF_Grammar arg) */

SDF_OptLayout SDF_getGrammarWsAfterParenOpen(SDF_Grammar arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterParenOpen(SDF_Grammar arg, SDF_OptLayout wsAfterParenOpen) */

SDF_Grammar SDF_setGrammarWsAfterParenOpen(SDF_Grammar arg, SDF_OptLayout wsAfterParenOpen)
{
  if (SDF_isGrammarBracket(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 1), 1);
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
  
    return (SDF_Grammar)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarGrammar(SDF_Grammar arg, SDF_Grammar Grammar) */

SDF_Grammar SDF_setGrammarGrammar(SDF_Grammar arg, SDF_Grammar Grammar)
{
  if (SDF_isGrammarBracket(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Grammar, 2), 1);
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
/*{{{  SDF_OptLayout SDF_getGrammarWsAfterGrammar(SDF_Grammar arg) */

SDF_OptLayout SDF_getGrammarWsAfterGrammar(SDF_Grammar arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Grammar SDF_setGrammarWsAfterGrammar(SDF_Grammar arg, SDF_OptLayout wsAfterGrammar) */

SDF_Grammar SDF_setGrammarWsAfterGrammar(SDF_Grammar arg, SDF_OptLayout wsAfterGrammar)
{
  if (SDF_isGrammarBracket(arg)) {
    return (SDF_Grammar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterGrammar, 3), 1);
  }

  ATabort("Grammar has no WsAfterGrammar: %t\n", arg);
  return (SDF_Grammar)NULL;
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
/*{{{  inline ATbool SDF_isAliasAlias(SDF_Alias arg) */

inline ATbool SDF_isAliasAlias(SDF_Alias arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternAliasAlias, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
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
  
    return (SDF_Symbol)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Alias SDF_setAliasSymbol(SDF_Alias arg, SDF_Symbol Symbol) */

SDF_Alias SDF_setAliasSymbol(SDF_Alias arg, SDF_Symbol Symbol)
{
  if (SDF_isAliasAlias(arg)) {
    return (SDF_Alias)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Symbol, 0), 1);
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
/*{{{  SDF_OptLayout SDF_getAliasWsAfterSymbol(SDF_Alias arg) */

SDF_OptLayout SDF_getAliasWsAfterSymbol(SDF_Alias arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Alias SDF_setAliasWsAfterSymbol(SDF_Alias arg, SDF_OptLayout wsAfterSymbol) */

SDF_Alias SDF_setAliasWsAfterSymbol(SDF_Alias arg, SDF_OptLayout wsAfterSymbol)
{
  if (SDF_isAliasAlias(arg)) {
    return (SDF_Alias)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSymbol, 1), 1);
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
/*{{{  SDF_OptLayout SDF_getAliasWsAfterArrow(SDF_Alias arg) */

SDF_OptLayout SDF_getAliasWsAfterArrow(SDF_Alias arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Alias SDF_setAliasWsAfterArrow(SDF_Alias arg, SDF_OptLayout wsAfterArrow) */

SDF_Alias SDF_setAliasWsAfterArrow(SDF_Alias arg, SDF_OptLayout wsAfterArrow)
{
  if (SDF_isAliasAlias(arg)) {
    return (SDF_Alias)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterArrow, 3), 1);
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
  
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  SDF_Alias SDF_setAliasAlias(SDF_Alias arg, SDF_Symbol alias) */

SDF_Alias SDF_setAliasAlias(SDF_Alias arg, SDF_Symbol alias)
{
  if (SDF_isAliasAlias(arg)) {
    return (SDF_Alias)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)alias, 4), 1);
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
/*{{{  inline ATbool SDF_isAliasesDefault(SDF_Aliases arg) */

inline ATbool SDF_isAliasesDefault(SDF_Aliases arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternAliasesDefault, NULL));
#endif
  return ATtrue;
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
  
    return (SDF_AliasList)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  SDF_Aliases SDF_setAliasesList(SDF_Aliases arg, SDF_AliasList list) */

SDF_Aliases SDF_setAliasesList(SDF_Aliases arg, SDF_AliasList list)
{
  if (SDF_isAliasesDefault(arg)) {
    return (SDF_Aliases)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)list, 1), 0), 1);
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
/*{{{  inline ATbool SDF_isAliasListEmpty(SDF_AliasList arg) */

inline ATbool SDF_isAliasListEmpty(SDF_AliasList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternAliasListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool SDF_isAliasListSingle(SDF_AliasList arg) */

inline ATbool SDF_isAliasListSingle(SDF_AliasList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternAliasListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isAliasListMany(SDF_AliasList arg) */

inline ATbool SDF_isAliasListMany(SDF_AliasList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternAliasListMany, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
    return (SDF_Alias)ATgetFirst((ATermList)arg);
  }
  else 
    return (SDF_Alias)ATgetFirst((ATermList)arg);
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
/*{{{  SDF_OptLayout SDF_getAliasListWsAfterFirst(SDF_AliasList arg) */

SDF_OptLayout SDF_getAliasListWsAfterFirst(SDF_AliasList arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  SDF_AliasList SDF_setAliasListWsAfterFirst(SDF_AliasList arg, SDF_OptLayout wsAfterFirst) */

SDF_AliasList SDF_setAliasListWsAfterFirst(SDF_AliasList arg, SDF_OptLayout wsAfterFirst)
{
  if (SDF_isAliasListMany(arg)) {
    return (SDF_AliasList)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
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
  
    return (SDF_AliasList)ATgetTail((ATermList)arg, 2);
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
/*{{{  inline ATbool SDF_isLookaheadCharClass(SDF_Lookahead arg) */

inline ATbool SDF_isLookaheadCharClass(SDF_Lookahead arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternLookaheadCharClass, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isLookaheadSeq(SDF_Lookahead arg) */

inline ATbool SDF_isLookaheadSeq(SDF_Lookahead arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternLookaheadSeq, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
  
    return (SDF_CharClass)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_setLookaheadCharClass(SDF_Lookahead arg, SDF_CharClass CharClass) */

SDF_Lookahead SDF_setLookaheadCharClass(SDF_Lookahead arg, SDF_CharClass CharClass)
{
  if (SDF_isLookaheadCharClass(arg)) {
    return (SDF_Lookahead)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)CharClass, 0), 1);
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
  
    return (SDF_CharClass)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_setLookaheadHead(SDF_Lookahead arg, SDF_CharClass head) */

SDF_Lookahead SDF_setLookaheadHead(SDF_Lookahead arg, SDF_CharClass head)
{
  if (SDF_isLookaheadSeq(arg)) {
    return (SDF_Lookahead)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)head, 0), 1);
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
/*{{{  SDF_OptLayout SDF_getLookaheadWsAfterHead(SDF_Lookahead arg) */

SDF_OptLayout SDF_getLookaheadWsAfterHead(SDF_Lookahead arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_setLookaheadWsAfterHead(SDF_Lookahead arg, SDF_OptLayout wsAfterHead) */

SDF_Lookahead SDF_setLookaheadWsAfterHead(SDF_Lookahead arg, SDF_OptLayout wsAfterHead)
{
  if (SDF_isLookaheadSeq(arg)) {
    return (SDF_Lookahead)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterHead, 1), 1);
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
/*{{{  SDF_OptLayout SDF_getLookaheadWsAfterPeriod(SDF_Lookahead arg) */

SDF_OptLayout SDF_getLookaheadWsAfterPeriod(SDF_Lookahead arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_setLookaheadWsAfterPeriod(SDF_Lookahead arg, SDF_OptLayout wsAfterPeriod) */

SDF_Lookahead SDF_setLookaheadWsAfterPeriod(SDF_Lookahead arg, SDF_OptLayout wsAfterPeriod)
{
  if (SDF_isLookaheadSeq(arg)) {
    return (SDF_Lookahead)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterPeriod, 3), 1);
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
  
    return (SDF_Lookaheads)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_setLookaheadTail(SDF_Lookahead arg, SDF_Lookaheads tail) */

SDF_Lookahead SDF_setLookaheadTail(SDF_Lookahead arg, SDF_Lookaheads tail)
{
  if (SDF_isLookaheadSeq(arg)) {
    return (SDF_Lookahead)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)tail, 4), 1);
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
/*{{{  inline ATbool SDF_isLookaheadsSingle(SDF_Lookaheads arg) */

inline ATbool SDF_isLookaheadsSingle(SDF_Lookaheads arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternLookaheadsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isLookaheadsAlt(SDF_Lookaheads arg) */

inline ATbool SDF_isLookaheadsAlt(SDF_Lookaheads arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternLookaheadsAlt, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isLookaheadsBracket(SDF_Lookaheads arg) */

inline ATbool SDF_isLookaheadsBracket(SDF_Lookaheads arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternLookaheadsBracket, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isLookaheadsList(SDF_Lookaheads arg) */

inline ATbool SDF_isLookaheadsList(SDF_Lookaheads arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternLookaheadsList, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
  
    return (SDF_Lookahead)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsLookahead(SDF_Lookaheads arg, SDF_Lookahead Lookahead) */

SDF_Lookaheads SDF_setLookaheadsLookahead(SDF_Lookaheads arg, SDF_Lookahead Lookahead)
{
  if (SDF_isLookaheadsSingle(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Lookahead, 0), 1);
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
  
    return (SDF_Lookaheads)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsLeft(SDF_Lookaheads arg, SDF_Lookaheads left) */

SDF_Lookaheads SDF_setLookaheadsLeft(SDF_Lookaheads arg, SDF_Lookaheads left)
{
  if (SDF_isLookaheadsAlt(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)left, 0), 1);
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
/*{{{  SDF_OptLayout SDF_getLookaheadsWsAfterLeft(SDF_Lookaheads arg) */

SDF_OptLayout SDF_getLookaheadsWsAfterLeft(SDF_Lookaheads arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsWsAfterLeft(SDF_Lookaheads arg, SDF_OptLayout wsAfterLeft) */

SDF_Lookaheads SDF_setLookaheadsWsAfterLeft(SDF_Lookaheads arg, SDF_OptLayout wsAfterLeft)
{
  if (SDF_isLookaheadsAlt(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLeft, 1), 1);
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
/*{{{  SDF_OptLayout SDF_getLookaheadsWsAfterBar(SDF_Lookaheads arg) */

SDF_OptLayout SDF_getLookaheadsWsAfterBar(SDF_Lookaheads arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsWsAfterBar(SDF_Lookaheads arg, SDF_OptLayout wsAfterBar) */

SDF_Lookaheads SDF_setLookaheadsWsAfterBar(SDF_Lookaheads arg, SDF_OptLayout wsAfterBar)
{
  if (SDF_isLookaheadsAlt(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBar, 3), 1);
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
  
    return (SDF_Lookaheads)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsRight(SDF_Lookaheads arg, SDF_Lookaheads right) */

SDF_Lookaheads SDF_setLookaheadsRight(SDF_Lookaheads arg, SDF_Lookaheads right)
{
  if (SDF_isLookaheadsAlt(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)right, 4), 1);
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
/*{{{  SDF_OptLayout SDF_getLookaheadsWsAfterParenOpen(SDF_Lookaheads arg) */

SDF_OptLayout SDF_getLookaheadsWsAfterParenOpen(SDF_Lookaheads arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsWsAfterParenOpen(SDF_Lookaheads arg, SDF_OptLayout wsAfterParenOpen) */

SDF_Lookaheads SDF_setLookaheadsWsAfterParenOpen(SDF_Lookaheads arg, SDF_OptLayout wsAfterParenOpen)
{
  if (SDF_isLookaheadsBracket(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 1), 1);
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
  
    return (SDF_Lookaheads)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsLookaheads(SDF_Lookaheads arg, SDF_Lookaheads Lookaheads) */

SDF_Lookaheads SDF_setLookaheadsLookaheads(SDF_Lookaheads arg, SDF_Lookaheads Lookaheads)
{
  if (SDF_isLookaheadsBracket(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Lookaheads, 2), 1);
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
/*{{{  SDF_OptLayout SDF_getLookaheadsWsAfterLookaheads(SDF_Lookaheads arg) */

SDF_OptLayout SDF_getLookaheadsWsAfterLookaheads(SDF_Lookaheads arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsWsAfterLookaheads(SDF_Lookaheads arg, SDF_OptLayout wsAfterLookaheads) */

SDF_Lookaheads SDF_setLookaheadsWsAfterLookaheads(SDF_Lookaheads arg, SDF_OptLayout wsAfterLookaheads)
{
  if (SDF_isLookaheadsBracket(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLookaheads, 3), 1);
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
/*{{{  SDF_OptLayout SDF_getLookaheadsWsAfterBracketOpenBracketOpen(SDF_Lookaheads arg) */

SDF_OptLayout SDF_getLookaheadsWsAfterBracketOpenBracketOpen(SDF_Lookaheads arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsWsAfterBracketOpenBracketOpen(SDF_Lookaheads arg, SDF_OptLayout wsAfterBracketOpenBracketOpen) */

SDF_Lookaheads SDF_setLookaheadsWsAfterBracketOpenBracketOpen(SDF_Lookaheads arg, SDF_OptLayout wsAfterBracketOpenBracketOpen)
{
  if (SDF_isLookaheadsList(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBracketOpenBracketOpen, 1), 1);
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
  
    return (SDF_LookaheadList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsList(SDF_Lookaheads arg, SDF_LookaheadList list) */

SDF_Lookaheads SDF_setLookaheadsList(SDF_Lookaheads arg, SDF_LookaheadList list)
{
  if (SDF_isLookaheadsList(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)list, 1), 2), 1);
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
/*{{{  SDF_OptLayout SDF_getLookaheadsWsAfterList(SDF_Lookaheads arg) */

SDF_OptLayout SDF_getLookaheadsWsAfterList(SDF_Lookaheads arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_setLookaheadsWsAfterList(SDF_Lookaheads arg, SDF_OptLayout wsAfterList) */

SDF_Lookaheads SDF_setLookaheadsWsAfterList(SDF_Lookaheads arg, SDF_OptLayout wsAfterList)
{
  if (SDF_isLookaheadsList(arg)) {
    return (SDF_Lookaheads)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterList, 3), 1);
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
/*{{{  inline ATbool SDF_isLookaheadListEmpty(SDF_LookaheadList arg) */

inline ATbool SDF_isLookaheadListEmpty(SDF_LookaheadList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternLookaheadListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool SDF_isLookaheadListSingle(SDF_LookaheadList arg) */

inline ATbool SDF_isLookaheadListSingle(SDF_LookaheadList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternLookaheadListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isLookaheadListMany(SDF_LookaheadList arg) */

inline ATbool SDF_isLookaheadListMany(SDF_LookaheadList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternLookaheadListMany, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
    return (SDF_Lookahead)ATgetFirst((ATermList)arg);
  }
  else 
    return (SDF_Lookahead)ATgetFirst((ATermList)arg);
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
/*{{{  SDF_OptLayout SDF_getLookaheadListWsAfterFirst(SDF_LookaheadList arg) */

SDF_OptLayout SDF_getLookaheadListWsAfterFirst(SDF_LookaheadList arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  SDF_LookaheadList SDF_setLookaheadListWsAfterFirst(SDF_LookaheadList arg, SDF_OptLayout wsAfterFirst) */

SDF_LookaheadList SDF_setLookaheadListWsAfterFirst(SDF_LookaheadList arg, SDF_OptLayout wsAfterFirst)
{
  if (SDF_isLookaheadListMany(arg)) {
    return (SDF_LookaheadList)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
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
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
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
/*{{{  SDF_OptLayout SDF_getLookaheadListWsAfterSep(SDF_LookaheadList arg) */

SDF_OptLayout SDF_getLookaheadListWsAfterSep(SDF_LookaheadList arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  SDF_LookaheadList SDF_setLookaheadListWsAfterSep(SDF_LookaheadList arg, SDF_OptLayout wsAfterSep) */

SDF_LookaheadList SDF_setLookaheadListWsAfterSep(SDF_LookaheadList arg, SDF_OptLayout wsAfterSep)
{
  if (SDF_isLookaheadListMany(arg)) {
    return (SDF_LookaheadList)ATreplace((ATermList)arg, (ATerm)wsAfterSep, 3);
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
  
    return (SDF_LookaheadList)ATgetTail((ATermList)arg, 4);
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
/*{{{  inline ATbool SDF_isRestrictionFollow(SDF_Restriction arg) */

inline ATbool SDF_isRestrictionFollow(SDF_Restriction arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternRestrictionFollow, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
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
  
    return (SDF_Symbols)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Restriction SDF_setRestrictionSymbols(SDF_Restriction arg, SDF_Symbols Symbols) */

SDF_Restriction SDF_setRestrictionSymbols(SDF_Restriction arg, SDF_Symbols Symbols)
{
  if (SDF_isRestrictionFollow(arg)) {
    return (SDF_Restriction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Symbols, 0), 1);
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
/*{{{  SDF_OptLayout SDF_getRestrictionWsAfterSymbols(SDF_Restriction arg) */

SDF_OptLayout SDF_getRestrictionWsAfterSymbols(SDF_Restriction arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Restriction SDF_setRestrictionWsAfterSymbols(SDF_Restriction arg, SDF_OptLayout wsAfterSymbols) */

SDF_Restriction SDF_setRestrictionWsAfterSymbols(SDF_Restriction arg, SDF_OptLayout wsAfterSymbols)
{
  if (SDF_isRestrictionFollow(arg)) {
    return (SDF_Restriction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSymbols, 1), 1);
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
/*{{{  SDF_OptLayout SDF_getRestrictionWsAfterSlash(SDF_Restriction arg) */

SDF_OptLayout SDF_getRestrictionWsAfterSlash(SDF_Restriction arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Restriction SDF_setRestrictionWsAfterSlash(SDF_Restriction arg, SDF_OptLayout wsAfterSlash) */

SDF_Restriction SDF_setRestrictionWsAfterSlash(SDF_Restriction arg, SDF_OptLayout wsAfterSlash)
{
  if (SDF_isRestrictionFollow(arg)) {
    return (SDF_Restriction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSlash, 3), 1);
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
  
    return (SDF_Lookaheads)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  SDF_Restriction SDF_setRestrictionLookaheads(SDF_Restriction arg, SDF_Lookaheads Lookaheads) */

SDF_Restriction SDF_setRestrictionLookaheads(SDF_Restriction arg, SDF_Lookaheads Lookaheads)
{
  if (SDF_isRestrictionFollow(arg)) {
    return (SDF_Restriction)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Lookaheads, 4), 1);
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
/*{{{  inline ATbool SDF_isRestrictionsDefault(SDF_Restrictions arg) */

inline ATbool SDF_isRestrictionsDefault(SDF_Restrictions arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternRestrictionsDefault, NULL));
#endif
  return ATtrue;
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
  
    return (SDF_RestrictionList)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  SDF_Restrictions SDF_setRestrictionsList(SDF_Restrictions arg, SDF_RestrictionList list) */

SDF_Restrictions SDF_setRestrictionsList(SDF_Restrictions arg, SDF_RestrictionList list)
{
  if (SDF_isRestrictionsDefault(arg)) {
    return (SDF_Restrictions)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)list, 1), 0), 1);
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
/*{{{  inline ATbool SDF_isRestrictionListEmpty(SDF_RestrictionList arg) */

inline ATbool SDF_isRestrictionListEmpty(SDF_RestrictionList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternRestrictionListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool SDF_isRestrictionListSingle(SDF_RestrictionList arg) */

inline ATbool SDF_isRestrictionListSingle(SDF_RestrictionList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternRestrictionListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isRestrictionListMany(SDF_RestrictionList arg) */

inline ATbool SDF_isRestrictionListMany(SDF_RestrictionList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternRestrictionListMany, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
    return (SDF_Restriction)ATgetFirst((ATermList)arg);
  }
  else 
    return (SDF_Restriction)ATgetFirst((ATermList)arg);
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
/*{{{  SDF_OptLayout SDF_getRestrictionListWsAfterFirst(SDF_RestrictionList arg) */

SDF_OptLayout SDF_getRestrictionListWsAfterFirst(SDF_RestrictionList arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  SDF_RestrictionList SDF_setRestrictionListWsAfterFirst(SDF_RestrictionList arg, SDF_OptLayout wsAfterFirst) */

SDF_RestrictionList SDF_setRestrictionListWsAfterFirst(SDF_RestrictionList arg, SDF_OptLayout wsAfterFirst)
{
  if (SDF_isRestrictionListMany(arg)) {
    return (SDF_RestrictionList)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
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
  
    return (SDF_RestrictionList)ATgetTail((ATermList)arg, 2);
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
/*{{{  SDF_Attribute accessors */

/*{{{  ATbool SDF_isValidAttribute(SDF_Attribute arg) */

ATbool SDF_isValidAttribute(SDF_Attribute arg)
{
  if (SDF_isAttributeReject(arg)) {
    return ATtrue;
  }
  else if (SDF_isAttributePrefer(arg)) {
    return ATtrue;
  }
  else if (SDF_isAttributeAvoid(arg)) {
    return ATtrue;
  }
  else if (SDF_isAttributeBracket(arg)) {
    return ATtrue;
  }
  else if (SDF_isAttributeAssoc(arg)) {
    return ATtrue;
  }
  else if (SDF_isAttributeId(arg)) {
    return ATtrue;
  }
  else if (SDF_isAttributeTerm(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SDF_isAttributeReject(SDF_Attribute arg) */

inline ATbool SDF_isAttributeReject(SDF_Attribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternAttributeReject);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isAttributePrefer(SDF_Attribute arg) */

inline ATbool SDF_isAttributePrefer(SDF_Attribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternAttributePrefer);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isAttributeAvoid(SDF_Attribute arg) */

inline ATbool SDF_isAttributeAvoid(SDF_Attribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternAttributeAvoid);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isAttributeBracket(SDF_Attribute arg) */

inline ATbool SDF_isAttributeBracket(SDF_Attribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternAttributeBracket);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isAttributeAssoc(SDF_Attribute arg) */

inline ATbool SDF_isAttributeAssoc(SDF_Attribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternAttributeAssoc, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isAttributeId(SDF_Attribute arg) */

inline ATbool SDF_isAttributeId(SDF_Attribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternAttributeId, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isAttributeTerm(SDF_Attribute arg) */

inline ATbool SDF_isAttributeTerm(SDF_Attribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternAttributeTerm, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributeAssociativity(SDF_Attribute arg) */

ATbool SDF_hasAttributeAssociativity(SDF_Attribute arg)
{
  if (SDF_isAttributeAssoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Associativity SDF_getAttributeAssociativity(SDF_Attribute arg) */

SDF_Associativity SDF_getAttributeAssociativity(SDF_Attribute arg)
{
  
    return (SDF_Associativity)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Attribute SDF_setAttributeAssociativity(SDF_Attribute arg, SDF_Associativity Associativity) */

SDF_Attribute SDF_setAttributeAssociativity(SDF_Attribute arg, SDF_Associativity Associativity)
{
  if (SDF_isAttributeAssoc(arg)) {
    return (SDF_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Associativity, 0), 1);
  }

  ATabort("Attribute has no Associativity: %t\n", arg);
  return (SDF_Attribute)NULL;
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
/*{{{  SDF_OptLayout SDF_getAttributeWsAfterId(SDF_Attribute arg) */

SDF_OptLayout SDF_getAttributeWsAfterId(SDF_Attribute arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Attribute SDF_setAttributeWsAfterId(SDF_Attribute arg, SDF_OptLayout wsAfterId) */

SDF_Attribute SDF_setAttributeWsAfterId(SDF_Attribute arg, SDF_OptLayout wsAfterId)
{
  if (SDF_isAttributeId(arg)) {
    return (SDF_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterId, 1), 1);
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
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getAttributeWsAfterParenOpen(SDF_Attribute arg) */

SDF_OptLayout SDF_getAttributeWsAfterParenOpen(SDF_Attribute arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Attribute SDF_setAttributeWsAfterParenOpen(SDF_Attribute arg, SDF_OptLayout wsAfterParenOpen) */

SDF_Attribute SDF_setAttributeWsAfterParenOpen(SDF_Attribute arg, SDF_OptLayout wsAfterParenOpen)
{
  if (SDF_isAttributeId(arg)) {
    return (SDF_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
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
  
    return (SDF_ModuleName)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  SDF_Attribute SDF_setAttributeModuleName(SDF_Attribute arg, SDF_ModuleName ModuleName) */

SDF_Attribute SDF_setAttributeModuleName(SDF_Attribute arg, SDF_ModuleName ModuleName)
{
  if (SDF_isAttributeId(arg)) {
    return (SDF_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ModuleName, 4), 1);
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
/*{{{  SDF_OptLayout SDF_getAttributeWsAfterModuleName(SDF_Attribute arg) */

SDF_OptLayout SDF_getAttributeWsAfterModuleName(SDF_Attribute arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  SDF_Attribute SDF_setAttributeWsAfterModuleName(SDF_Attribute arg, SDF_OptLayout wsAfterModuleName) */

SDF_Attribute SDF_setAttributeWsAfterModuleName(SDF_Attribute arg, SDF_OptLayout wsAfterModuleName)
{
  if (SDF_isAttributeId(arg)) {
    return (SDF_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterModuleName, 5), 1);
  }

  ATabort("Attribute has no WsAfterModuleName: %t\n", arg);
  return (SDF_Attribute)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAttributeAterm(SDF_Attribute arg) */

ATbool SDF_hasAttributeAterm(SDF_Attribute arg)
{
  if (SDF_isAttributeTerm(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_getAttributeAterm(SDF_Attribute arg) */

SDF_ATerm SDF_getAttributeAterm(SDF_Attribute arg)
{
  
    return (SDF_ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Attribute SDF_setAttributeAterm(SDF_Attribute arg, SDF_ATerm aterm) */

SDF_Attribute SDF_setAttributeAterm(SDF_Attribute arg, SDF_ATerm aterm)
{
  if (SDF_isAttributeTerm(arg)) {
    return (SDF_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)aterm, 0), 1);
  }

  ATabort("Attribute has no Aterm: %t\n", arg);
  return (SDF_Attribute)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Symbol accessors */

/*{{{  ATbool SDF_isValidSymbol(SDF_Symbol arg) */

ATbool SDF_isValidSymbol(SDF_Symbol arg)
{
  if (SDF_isSymbolLabel(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolLit(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolSort(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolParameterizedSort(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolCharClass(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolLifting(arg)) {
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
  else if (SDF_isSymbolTuple(arg)) {
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
  else if (SDF_isSymbolStrategy(arg)) {
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
  else if (SDF_isSymbolBracket(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolStart(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolFileStart(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolLabel(SDF_Symbol arg) */

inline ATbool SDF_isSymbolLabel(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolLabel, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolLit(SDF_Symbol arg) */

inline ATbool SDF_isSymbolLit(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolLit, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolSort(SDF_Symbol arg) */

inline ATbool SDF_isSymbolSort(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolSort, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolParameterizedSort(SDF_Symbol arg) */

inline ATbool SDF_isSymbolParameterizedSort(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolParameterizedSort, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolCharClass(SDF_Symbol arg) */

inline ATbool SDF_isSymbolCharClass(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolCharClass, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolLifting(SDF_Symbol arg) */

inline ATbool SDF_isSymbolLifting(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolLifting, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolEmpty(SDF_Symbol arg) */

inline ATbool SDF_isSymbolEmpty(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolEmpty, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolSeq(SDF_Symbol arg) */

inline ATbool SDF_isSymbolSeq(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolSeq, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolOpt(SDF_Symbol arg) */

inline ATbool SDF_isSymbolOpt(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolOpt, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolIter(SDF_Symbol arg) */

inline ATbool SDF_isSymbolIter(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolIter, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolIterStar(SDF_Symbol arg) */

inline ATbool SDF_isSymbolIterStar(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolIterStar, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolIterSep(SDF_Symbol arg) */

inline ATbool SDF_isSymbolIterSep(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolIterSep, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolIterStarSep(SDF_Symbol arg) */

inline ATbool SDF_isSymbolIterStarSep(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolIterStarSep, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolIterN(SDF_Symbol arg) */

inline ATbool SDF_isSymbolIterN(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolIterN, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolIterSepN(SDF_Symbol arg) */

inline ATbool SDF_isSymbolIterSepN(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolIterSepN, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolTuple(SDF_Symbol arg) */

inline ATbool SDF_isSymbolTuple(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolTuple, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolPair(SDF_Symbol arg) */

inline ATbool SDF_isSymbolPair(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolPair, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolFunc(SDF_Symbol arg) */

inline ATbool SDF_isSymbolFunc(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolFunc, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolAlt(SDF_Symbol arg) */

inline ATbool SDF_isSymbolAlt(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolAlt, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolStrategy(SDF_Symbol arg) */

inline ATbool SDF_isSymbolStrategy(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolStrategy, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolCf(SDF_Symbol arg) */

inline ATbool SDF_isSymbolCf(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolCf, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolLex(SDF_Symbol arg) */

inline ATbool SDF_isSymbolLex(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolLex, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolVarsym(SDF_Symbol arg) */

inline ATbool SDF_isSymbolVarsym(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolVarsym, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolLayout(SDF_Symbol arg) */

inline ATbool SDF_isSymbolLayout(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolLayout);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolBracket(SDF_Symbol arg) */

inline ATbool SDF_isSymbolBracket(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolBracket, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolStart(SDF_Symbol arg) */

inline ATbool SDF_isSymbolStart(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolStart);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolFileStart(SDF_Symbol arg) */

inline ATbool SDF_isSymbolFileStart(SDF_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolFileStart);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
  
    return (SDF_Literal)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolLabel(SDF_Symbol arg, SDF_Literal label) */

SDF_Symbol SDF_setSymbolLabel(SDF_Symbol arg, SDF_Literal label)
{
  if (SDF_isSymbolLabel(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)label, 0), 1);
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
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterLabel(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterLabel(SDF_Symbol arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterLabel(SDF_Symbol arg, SDF_OptLayout wsAfterLabel) */

SDF_Symbol SDF_setSymbolWsAfterLabel(SDF_Symbol arg, SDF_OptLayout wsAfterLabel)
{
  if (SDF_isSymbolLabel(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLabel, 1), 1);
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
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterColon(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterColon(SDF_Symbol arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterColon(SDF_Symbol arg, SDF_OptLayout wsAfterColon) */

SDF_Symbol SDF_setSymbolWsAfterColon(SDF_Symbol arg, SDF_OptLayout wsAfterColon)
{
  if (SDF_isSymbolLabel(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterColon, 3), 1);
  }

  ATabort("Symbol has no WsAfterColon: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolSymbol(SDF_Symbol arg) */

ATbool SDF_hasSymbolSymbol(SDF_Symbol arg)
{
  if (SDF_isSymbolLabel(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolLifting(arg)) {
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
  else if (SDF_isSymbolCf(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolLex(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolVarsym(arg)) {
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
  if (SDF_isSymbolLabel(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (SDF_isSymbolLifting(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else if (SDF_isSymbolOpt(arg)) {
    return (SDF_Symbol)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isSymbolIter(arg)) {
    return (SDF_Symbol)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isSymbolIterStar(arg)) {
    return (SDF_Symbol)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isSymbolIterSep(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else if (SDF_isSymbolIterN(arg)) {
    return (SDF_Symbol)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else if (SDF_isSymbolCf(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else if (SDF_isSymbolLex(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else if (SDF_isSymbolVarsym(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else 
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolSymbol(SDF_Symbol arg, SDF_Symbol Symbol) */

SDF_Symbol SDF_setSymbolSymbol(SDF_Symbol arg, SDF_Symbol Symbol)
{
  if (SDF_isSymbolLabel(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Symbol, 4), 1);
  }
  else if (SDF_isSymbolLifting(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Symbol, 2), 1);
  }
  else if (SDF_isSymbolOpt(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Symbol, 0), 1);
  }
  else if (SDF_isSymbolIter(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Symbol, 0), 1);
  }
  else if (SDF_isSymbolIterStar(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Symbol, 0), 1);
  }
  else if (SDF_isSymbolIterSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Symbol, 2), 1);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Symbol, 2), 1);
  }
  else if (SDF_isSymbolIterN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Symbol, 0), 1);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Symbol, 2), 1);
  }
  else if (SDF_isSymbolCf(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Symbol, 2), 1);
  }
  else if (SDF_isSymbolLex(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Symbol, 2), 1);
  }
  else if (SDF_isSymbolVarsym(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Symbol, 2), 1);
  }
  else if (SDF_isSymbolBracket(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Symbol, 2), 1);
  }

  ATabort("Symbol has no Symbol: %t\n", arg);
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
  
    return (SDF_Literal)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolLiteral(SDF_Symbol arg, SDF_Literal Literal) */

SDF_Symbol SDF_setSymbolLiteral(SDF_Symbol arg, SDF_Literal Literal)
{
  if (SDF_isSymbolLit(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Literal, 0), 1);
  }

  ATabort("Symbol has no Literal: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolSort(SDF_Symbol arg) */

ATbool SDF_hasSymbolSort(SDF_Symbol arg)
{
  if (SDF_isSymbolSort(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolParameterizedSort(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Sort SDF_getSymbolSort(SDF_Symbol arg) */

SDF_Sort SDF_getSymbolSort(SDF_Symbol arg)
{
  if (SDF_isSymbolSort(arg)) {
    return (SDF_Sort)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (SDF_Sort)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolSort(SDF_Symbol arg, SDF_Sort Sort) */

SDF_Symbol SDF_setSymbolSort(SDF_Symbol arg, SDF_Sort Sort)
{
  if (SDF_isSymbolSort(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Sort, 0), 1);
  }
  else if (SDF_isSymbolParameterizedSort(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Sort, 0), 1);
  }

  ATabort("Symbol has no Sort: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterSort(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterSort(SDF_Symbol arg)
{
  if (SDF_isSymbolParameterizedSort(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterSort(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterSort(SDF_Symbol arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterSort(SDF_Symbol arg, SDF_OptLayout wsAfterSort) */

SDF_Symbol SDF_setSymbolWsAfterSort(SDF_Symbol arg, SDF_OptLayout wsAfterSort)
{
  if (SDF_isSymbolParameterizedSort(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSort, 1), 1);
  }

  ATabort("Symbol has no WsAfterSort: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterBracketOpenBracketOpen(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterBracketOpenBracketOpen(SDF_Symbol arg)
{
  if (SDF_isSymbolParameterizedSort(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterBracketOpenBracketOpen(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterBracketOpenBracketOpen(SDF_Symbol arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterBracketOpenBracketOpen(SDF_Symbol arg, SDF_OptLayout wsAfterBracketOpenBracketOpen) */

SDF_Symbol SDF_setSymbolWsAfterBracketOpenBracketOpen(SDF_Symbol arg, SDF_OptLayout wsAfterBracketOpenBracketOpen)
{
  if (SDF_isSymbolParameterizedSort(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBracketOpenBracketOpen, 3), 1);
  }

  ATabort("Symbol has no WsAfterBracketOpenBracketOpen: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolParameters(SDF_Symbol arg) */

ATbool SDF_hasSymbolParameters(SDF_Symbol arg)
{
  if (SDF_isSymbolParameterizedSort(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_SymbolParameters SDF_getSymbolParameters(SDF_Symbol arg) */

SDF_SymbolParameters SDF_getSymbolParameters(SDF_Symbol arg)
{
  
    return (SDF_SymbolParameters)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 1);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolParameters(SDF_Symbol arg, SDF_SymbolParameters parameters) */

SDF_Symbol SDF_setSymbolParameters(SDF_Symbol arg, SDF_SymbolParameters parameters)
{
  if (SDF_isSymbolParameterizedSort(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)parameters, 1), 4), 1);
  }

  ATabort("Symbol has no Parameters: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterParameters(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterParameters(SDF_Symbol arg)
{
  if (SDF_isSymbolParameterizedSort(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterParameters(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterParameters(SDF_Symbol arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterParameters(SDF_Symbol arg, SDF_OptLayout wsAfterParameters) */

SDF_Symbol SDF_setSymbolWsAfterParameters(SDF_Symbol arg, SDF_OptLayout wsAfterParameters)
{
  if (SDF_isSymbolParameterizedSort(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParameters, 5), 1);
  }

  ATabort("Symbol has no WsAfterParameters: %t\n", arg);
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
  
    return (SDF_CharClass)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolCharClass(SDF_Symbol arg, SDF_CharClass CharClass) */

SDF_Symbol SDF_setSymbolCharClass(SDF_Symbol arg, SDF_CharClass CharClass)
{
  if (SDF_isSymbolCharClass(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)CharClass, 0), 1);
  }

  ATabort("Symbol has no CharClass: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterLeftQuote(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterLeftQuote(SDF_Symbol arg)
{
  if (SDF_isSymbolLifting(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterLeftQuote(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterLeftQuote(SDF_Symbol arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterLeftQuote(SDF_Symbol arg, SDF_OptLayout wsAfterLeftQuote) */

SDF_Symbol SDF_setSymbolWsAfterLeftQuote(SDF_Symbol arg, SDF_OptLayout wsAfterLeftQuote)
{
  if (SDF_isSymbolLifting(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLeftQuote, 1), 1);
  }

  ATabort("Symbol has no WsAfterLeftQuote: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterSymbol(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterSymbol(SDF_Symbol arg)
{
  if (SDF_isSymbolLifting(arg)) {
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
  else if (SDF_isSymbolCf(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolLex(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolVarsym(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterSymbol(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterSymbol(SDF_Symbol arg)
{
  if (SDF_isSymbolLifting(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (SDF_isSymbolOpt(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (SDF_isSymbolIter(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (SDF_isSymbolIterStar(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (SDF_isSymbolIterSep(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (SDF_isSymbolIterN(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (SDF_isSymbolCf(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (SDF_isSymbolLex(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (SDF_isSymbolVarsym(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterSymbol(SDF_Symbol arg, SDF_OptLayout wsAfterSymbol) */

SDF_Symbol SDF_setSymbolWsAfterSymbol(SDF_Symbol arg, SDF_OptLayout wsAfterSymbol)
{
  if (SDF_isSymbolLifting(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSymbol, 3), 1);
  }
  else if (SDF_isSymbolOpt(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSymbol, 1), 1);
  }
  else if (SDF_isSymbolIter(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSymbol, 1), 1);
  }
  else if (SDF_isSymbolIterStar(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSymbol, 1), 1);
  }
  else if (SDF_isSymbolIterSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSymbol, 3), 1);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSymbol, 3), 1);
  }
  else if (SDF_isSymbolIterN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSymbol, 1), 1);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSymbol, 3), 1);
  }
  else if (SDF_isSymbolCf(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSymbol, 3), 1);
  }
  else if (SDF_isSymbolLex(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSymbol, 3), 1);
  }
  else if (SDF_isSymbolVarsym(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSymbol, 3), 1);
  }
  else if (SDF_isSymbolBracket(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSymbol, 3), 1);
  }

  ATabort("Symbol has no WsAfterSymbol: %t\n", arg);
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
  else if (SDF_isSymbolStrategy(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterParenOpen(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterParenOpen(SDF_Symbol arg)
{
  if (SDF_isSymbolEmpty(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (SDF_isSymbolSeq(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (SDF_isSymbolFunc(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (SDF_isSymbolStrategy(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterParenOpen(SDF_Symbol arg, SDF_OptLayout wsAfterParenOpen) */

SDF_Symbol SDF_setSymbolWsAfterParenOpen(SDF_Symbol arg, SDF_OptLayout wsAfterParenOpen)
{
  if (SDF_isSymbolEmpty(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 1), 1);
  }
  else if (SDF_isSymbolSeq(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 1), 1);
  }
  else if (SDF_isSymbolFunc(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 1), 1);
  }
  else if (SDF_isSymbolStrategy(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 1), 1);
  }
  else if (SDF_isSymbolBracket(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 1), 1);
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
  else if (SDF_isSymbolTuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_getSymbolHead(SDF_Symbol arg) */

SDF_Symbol SDF_getSymbolHead(SDF_Symbol arg)
{
  if (SDF_isSymbolSeq(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else 
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolHead(SDF_Symbol arg, SDF_Symbol head) */

SDF_Symbol SDF_setSymbolHead(SDF_Symbol arg, SDF_Symbol head)
{
  if (SDF_isSymbolSeq(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)head, 2), 1);
  }
  else if (SDF_isSymbolTuple(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)head, 2), 1);
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
  else if (SDF_isSymbolTuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterHead(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterHead(SDF_Symbol arg)
{
  if (SDF_isSymbolSeq(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterHead(SDF_Symbol arg, SDF_OptLayout wsAfterHead) */

SDF_Symbol SDF_setSymbolWsAfterHead(SDF_Symbol arg, SDF_OptLayout wsAfterHead)
{
  if (SDF_isSymbolSeq(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterHead, 3), 1);
  }
  else if (SDF_isSymbolTuple(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterHead, 3), 1);
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
  
    return (SDF_SymbolTail)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 1);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolTail(SDF_Symbol arg, SDF_SymbolTail tail) */

SDF_Symbol SDF_setSymbolTail(SDF_Symbol arg, SDF_SymbolTail tail)
{
  if (SDF_isSymbolSeq(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)tail, 1), 4), 1);
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
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterTail(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterTail(SDF_Symbol arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterTail(SDF_Symbol arg, SDF_OptLayout wsAfterTail) */

SDF_Symbol SDF_setSymbolWsAfterTail(SDF_Symbol arg, SDF_OptLayout wsAfterTail)
{
  if (SDF_isSymbolSeq(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterTail, 5), 1);
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
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterBraceOpen(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterBraceOpen(SDF_Symbol arg)
{
  if (SDF_isSymbolIterSep(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterBraceOpen(SDF_Symbol arg, SDF_OptLayout wsAfterBraceOpen) */

SDF_Symbol SDF_setSymbolWsAfterBraceOpen(SDF_Symbol arg, SDF_OptLayout wsAfterBraceOpen)
{
  if (SDF_isSymbolIterSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBraceOpen, 1), 1);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBraceOpen, 1), 1);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBraceOpen, 1), 1);
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
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolSep(SDF_Symbol arg, SDF_Symbol sep) */

SDF_Symbol SDF_setSymbolSep(SDF_Symbol arg, SDF_Symbol sep)
{
  if (SDF_isSymbolIterSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)sep, 4), 1);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)sep, 4), 1);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)sep, 4), 1);
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
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterSep(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterSep(SDF_Symbol arg)
{
  if (SDF_isSymbolIterSep(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterSep(SDF_Symbol arg, SDF_OptLayout wsAfterSep) */

SDF_Symbol SDF_setSymbolWsAfterSep(SDF_Symbol arg, SDF_OptLayout wsAfterSep)
{
  if (SDF_isSymbolIterSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSep, 5), 1);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSep, 5), 1);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSep, 5), 1);
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
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterBraceClose(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterBraceClose(SDF_Symbol arg)
{
  if (SDF_isSymbolIterSep(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else 
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterBraceClose(SDF_Symbol arg, SDF_OptLayout wsAfterBraceClose) */

SDF_Symbol SDF_setSymbolWsAfterBraceClose(SDF_Symbol arg, SDF_OptLayout wsAfterBraceClose)
{
  if (SDF_isSymbolIterSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBraceClose, 7), 1);
  }
  else if (SDF_isSymbolIterStarSep(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBraceClose, 7), 1);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBraceClose, 7), 1);
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
    return (SDF_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else 
    return (SDF_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolN(SDF_Symbol arg, SDF_NatCon n) */

SDF_Symbol SDF_setSymbolN(SDF_Symbol arg, SDF_NatCon n)
{
  if (SDF_isSymbolIterN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)n, 2), 1);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)n, 8), 1);
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
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterN(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterN(SDF_Symbol arg)
{
  if (SDF_isSymbolIterN(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterN(SDF_Symbol arg, SDF_OptLayout wsAfterN) */

SDF_Symbol SDF_setSymbolWsAfterN(SDF_Symbol arg, SDF_OptLayout wsAfterN)
{
  if (SDF_isSymbolIterN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterN, 3), 1);
  }
  else if (SDF_isSymbolIterSepN(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterN, 9), 1);
  }

  ATabort("Symbol has no WsAfterN: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterLessThan(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterLessThan(SDF_Symbol arg)
{
  if (SDF_isSymbolTuple(arg)) {
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
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterLessThan(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterLessThan(SDF_Symbol arg)
{
  if (SDF_isSymbolTuple(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (SDF_isSymbolCf(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (SDF_isSymbolLex(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterLessThan(SDF_Symbol arg, SDF_OptLayout wsAfterLessThan) */

SDF_Symbol SDF_setSymbolWsAfterLessThan(SDF_Symbol arg, SDF_OptLayout wsAfterLessThan)
{
  if (SDF_isSymbolTuple(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLessThan, 1), 1);
  }
  else if (SDF_isSymbolCf(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLessThan, 1), 1);
  }
  else if (SDF_isSymbolLex(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLessThan, 1), 1);
  }
  else if (SDF_isSymbolVarsym(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLessThan, 1), 1);
  }

  ATabort("Symbol has no WsAfterLessThan: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterComma(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterComma(SDF_Symbol arg)
{
  if (SDF_isSymbolTuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterComma(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterComma(SDF_Symbol arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterComma(SDF_Symbol arg, SDF_OptLayout wsAfterComma) */

SDF_Symbol SDF_setSymbolWsAfterComma(SDF_Symbol arg, SDF_OptLayout wsAfterComma)
{
  if (SDF_isSymbolTuple(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterComma, 5), 1);
  }

  ATabort("Symbol has no WsAfterComma: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolRest(SDF_Symbol arg) */

ATbool SDF_hasSymbolRest(SDF_Symbol arg)
{
  if (SDF_isSymbolTuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_SymbolRest SDF_getSymbolRest(SDF_Symbol arg) */

SDF_SymbolRest SDF_getSymbolRest(SDF_Symbol arg)
{
  
    return (SDF_SymbolRest)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), 1);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolRest(SDF_Symbol arg, SDF_SymbolRest rest) */

SDF_Symbol SDF_setSymbolRest(SDF_Symbol arg, SDF_SymbolRest rest)
{
  if (SDF_isSymbolTuple(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), (ATerm)rest, 1), 6), 1);
  }

  ATabort("Symbol has no Rest: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterRest(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterRest(SDF_Symbol arg)
{
  if (SDF_isSymbolTuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterRest(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterRest(SDF_Symbol arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterRest(SDF_Symbol arg, SDF_OptLayout wsAfterRest) */

SDF_Symbol SDF_setSymbolWsAfterRest(SDF_Symbol arg, SDF_OptLayout wsAfterRest)
{
  if (SDF_isSymbolTuple(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterRest, 7), 1);
  }

  ATabort("Symbol has no WsAfterRest: %t\n", arg);
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
  else if (SDF_isSymbolStrategy(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_getSymbolLeft(SDF_Symbol arg) */

SDF_Symbol SDF_getSymbolLeft(SDF_Symbol arg)
{
  if (SDF_isSymbolPair(arg)) {
    return (SDF_Symbol)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isSymbolAlt(arg)) {
    return (SDF_Symbol)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolLeft(SDF_Symbol arg, SDF_Symbol left) */

SDF_Symbol SDF_setSymbolLeft(SDF_Symbol arg, SDF_Symbol left)
{
  if (SDF_isSymbolPair(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)left, 0), 1);
  }
  else if (SDF_isSymbolAlt(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)left, 0), 1);
  }
  else if (SDF_isSymbolStrategy(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)left, 2), 1);
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
  else if (SDF_isSymbolStrategy(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterLeft(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterLeft(SDF_Symbol arg)
{
  if (SDF_isSymbolPair(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (SDF_isSymbolAlt(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterLeft(SDF_Symbol arg, SDF_OptLayout wsAfterLeft) */

SDF_Symbol SDF_setSymbolWsAfterLeft(SDF_Symbol arg, SDF_OptLayout wsAfterLeft)
{
  if (SDF_isSymbolPair(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLeft, 1), 1);
  }
  else if (SDF_isSymbolAlt(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLeft, 1), 1);
  }
  else if (SDF_isSymbolStrategy(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLeft, 3), 1);
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
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterHash(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterHash(SDF_Symbol arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterHash(SDF_Symbol arg, SDF_OptLayout wsAfterHash) */

SDF_Symbol SDF_setSymbolWsAfterHash(SDF_Symbol arg, SDF_OptLayout wsAfterHash)
{
  if (SDF_isSymbolPair(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterHash, 3), 1);
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
  else if (SDF_isSymbolStrategy(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_getSymbolRight(SDF_Symbol arg) */

SDF_Symbol SDF_getSymbolRight(SDF_Symbol arg)
{
  if (SDF_isSymbolPair(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (SDF_isSymbolAlt(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolRight(SDF_Symbol arg, SDF_Symbol right) */

SDF_Symbol SDF_setSymbolRight(SDF_Symbol arg, SDF_Symbol right)
{
  if (SDF_isSymbolPair(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)right, 4), 1);
  }
  else if (SDF_isSymbolAlt(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)right, 4), 1);
  }
  else if (SDF_isSymbolStrategy(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)right, 6), 1);
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
  
    return (SDF_Symbols)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolArguments(SDF_Symbol arg, SDF_Symbols arguments) */

SDF_Symbol SDF_setSymbolArguments(SDF_Symbol arg, SDF_Symbols arguments)
{
  if (SDF_isSymbolFunc(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)arguments, 2), 1);
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
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterArguments(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterArguments(SDF_Symbol arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterArguments(SDF_Symbol arg, SDF_OptLayout wsAfterArguments) */

SDF_Symbol SDF_setSymbolWsAfterArguments(SDF_Symbol arg, SDF_OptLayout wsAfterArguments)
{
  if (SDF_isSymbolFunc(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterArguments, 3), 1);
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
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterEqualsGreaterThan(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterEqualsGreaterThan(SDF_Symbol arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterEqualsGreaterThan(SDF_Symbol arg, SDF_OptLayout wsAfterEqualsGreaterThan) */

SDF_Symbol SDF_setSymbolWsAfterEqualsGreaterThan(SDF_Symbol arg, SDF_OptLayout wsAfterEqualsGreaterThan)
{
  if (SDF_isSymbolFunc(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterEqualsGreaterThan, 5), 1);
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
  
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolResults(SDF_Symbol arg, SDF_Symbol results) */

SDF_Symbol SDF_setSymbolResults(SDF_Symbol arg, SDF_Symbol results)
{
  if (SDF_isSymbolFunc(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)results, 6), 1);
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
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterResults(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterResults(SDF_Symbol arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterResults(SDF_Symbol arg, SDF_OptLayout wsAfterResults) */

SDF_Symbol SDF_setSymbolWsAfterResults(SDF_Symbol arg, SDF_OptLayout wsAfterResults)
{
  if (SDF_isSymbolFunc(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterResults, 7), 1);
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
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterBar(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterBar(SDF_Symbol arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterBar(SDF_Symbol arg, SDF_OptLayout wsAfterBar) */

SDF_Symbol SDF_setSymbolWsAfterBar(SDF_Symbol arg, SDF_OptLayout wsAfterBar)
{
  if (SDF_isSymbolAlt(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBar, 3), 1);
  }

  ATabort("Symbol has no WsAfterBar: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterGreaterThan(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterGreaterThan(SDF_Symbol arg)
{
  if (SDF_isSymbolStrategy(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterGreaterThan(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterGreaterThan(SDF_Symbol arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterGreaterThan(SDF_Symbol arg, SDF_OptLayout wsAfterGreaterThan) */

SDF_Symbol SDF_setSymbolWsAfterGreaterThan(SDF_Symbol arg, SDF_OptLayout wsAfterGreaterThan)
{
  if (SDF_isSymbolStrategy(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterGreaterThan, 5), 1);
  }

  ATabort("Symbol has no WsAfterGreaterThan: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolWsAfterRight(SDF_Symbol arg) */

ATbool SDF_hasSymbolWsAfterRight(SDF_Symbol arg)
{
  if (SDF_isSymbolStrategy(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterRight(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterRight(SDF_Symbol arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterRight(SDF_Symbol arg, SDF_OptLayout wsAfterRight) */

SDF_Symbol SDF_setSymbolWsAfterRight(SDF_Symbol arg, SDF_OptLayout wsAfterRight)
{
  if (SDF_isSymbolStrategy(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterRight, 7), 1);
  }

  ATabort("Symbol has no WsAfterRight: %t\n", arg);
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
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterCF(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterCF(SDF_Symbol arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterCF(SDF_Symbol arg, SDF_OptLayout wsAfterCF) */

SDF_Symbol SDF_setSymbolWsAfterCF(SDF_Symbol arg, SDF_OptLayout wsAfterCF)
{
  if (SDF_isSymbolCf(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterCF, 5), 1);
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
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterLEX(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterLEX(SDF_Symbol arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterLEX(SDF_Symbol arg, SDF_OptLayout wsAfterLEX) */

SDF_Symbol SDF_setSymbolWsAfterLEX(SDF_Symbol arg, SDF_OptLayout wsAfterLEX)
{
  if (SDF_isSymbolLex(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLEX, 5), 1);
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
/*{{{  SDF_OptLayout SDF_getSymbolWsAfterVAR(SDF_Symbol arg) */

SDF_OptLayout SDF_getSymbolWsAfterVAR(SDF_Symbol arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  SDF_Symbol SDF_setSymbolWsAfterVAR(SDF_Symbol arg, SDF_OptLayout wsAfterVAR) */

SDF_Symbol SDF_setSymbolWsAfterVAR(SDF_Symbol arg, SDF_OptLayout wsAfterVAR)
{
  if (SDF_isSymbolVarsym(arg)) {
    return (SDF_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterVAR, 5), 1);
  }

  ATabort("Symbol has no WsAfterVAR: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Production accessors */

/*{{{  ATbool SDF_isValidProduction(SDF_Production arg) */

ATbool SDF_isValidProduction(SDF_Production arg)
{
  if (SDF_isProductionProdFun(arg)) {
    return ATtrue;
  }
  else if (SDF_isProductionProd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SDF_isProductionProdFun(SDF_Production arg) */

inline ATbool SDF_isProductionProdFun(SDF_Production arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternProductionProdFun, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isProductionProd(SDF_Production arg) */

inline ATbool SDF_isProductionProd(SDF_Production arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternProductionProd, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
  
    return (SDF_Literal)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionFunctionSymbol(SDF_Production arg, SDF_Literal functionSymbol) */

SDF_Production SDF_setProductionFunctionSymbol(SDF_Production arg, SDF_Literal functionSymbol)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)functionSymbol, 0), 1);
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
/*{{{  SDF_OptLayout SDF_getProductionWsAfterFunctionSymbol(SDF_Production arg) */

SDF_OptLayout SDF_getProductionWsAfterFunctionSymbol(SDF_Production arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionWsAfterFunctionSymbol(SDF_Production arg, SDF_OptLayout wsAfterFunctionSymbol) */

SDF_Production SDF_setProductionWsAfterFunctionSymbol(SDF_Production arg, SDF_OptLayout wsAfterFunctionSymbol)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterFunctionSymbol, 1), 1);
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
/*{{{  SDF_OptLayout SDF_getProductionWsAfterParenOpen(SDF_Production arg) */

SDF_OptLayout SDF_getProductionWsAfterParenOpen(SDF_Production arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionWsAfterParenOpen(SDF_Production arg, SDF_OptLayout wsAfterParenOpen) */

SDF_Production SDF_setProductionWsAfterParenOpen(SDF_Production arg, SDF_OptLayout wsAfterParenOpen)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
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
  
    return (SDF_SymbolArguments)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 1);
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionArguments(SDF_Production arg, SDF_SymbolArguments arguments) */

SDF_Production SDF_setProductionArguments(SDF_Production arg, SDF_SymbolArguments arguments)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)arguments, 1), 4), 1);
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
/*{{{  SDF_OptLayout SDF_getProductionWsAfterArguments(SDF_Production arg) */

SDF_OptLayout SDF_getProductionWsAfterArguments(SDF_Production arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionWsAfterArguments(SDF_Production arg, SDF_OptLayout wsAfterArguments) */

SDF_Production SDF_setProductionWsAfterArguments(SDF_Production arg, SDF_OptLayout wsAfterArguments)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterArguments, 5), 1);
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
/*{{{  SDF_OptLayout SDF_getProductionWsAfterParenClose(SDF_Production arg) */

SDF_OptLayout SDF_getProductionWsAfterParenClose(SDF_Production arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionWsAfterParenClose(SDF_Production arg, SDF_OptLayout wsAfterParenClose) */

SDF_Production SDF_setProductionWsAfterParenClose(SDF_Production arg, SDF_OptLayout wsAfterParenClose)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenClose, 7), 1);
  }

  ATabort("Production has no WsAfterParenClose: %t\n", arg);
  return (SDF_Production)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasProductionWsAfterGreaterThan(SDF_Production arg) */

ATbool SDF_hasProductionWsAfterGreaterThan(SDF_Production arg)
{
  if (SDF_isProductionProdFun(arg)) {
    return ATtrue;
  }
  else if (SDF_isProductionProd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getProductionWsAfterGreaterThan(SDF_Production arg) */

SDF_OptLayout SDF_getProductionWsAfterGreaterThan(SDF_Production arg)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else 
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionWsAfterGreaterThan(SDF_Production arg, SDF_OptLayout wsAfterGreaterThan) */

SDF_Production SDF_setProductionWsAfterGreaterThan(SDF_Production arg, SDF_OptLayout wsAfterGreaterThan)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterGreaterThan, 9), 1);
  }
  else if (SDF_isProductionProd(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterGreaterThan, 3), 1);
  }

  ATabort("Production has no WsAfterGreaterThan: %t\n", arg);
  return (SDF_Production)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasProductionResult(SDF_Production arg) */

ATbool SDF_hasProductionResult(SDF_Production arg)
{
  if (SDF_isProductionProdFun(arg)) {
    return ATtrue;
  }
  else if (SDF_isProductionProd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_getProductionResult(SDF_Production arg) */

SDF_Symbol SDF_getProductionResult(SDF_Production arg)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 10);
  }
  else 
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionResult(SDF_Production arg, SDF_Symbol result) */

SDF_Production SDF_setProductionResult(SDF_Production arg, SDF_Symbol result)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)result, 10), 1);
  }
  else if (SDF_isProductionProd(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)result, 4), 1);
  }

  ATabort("Production has no Result: %t\n", arg);
  return (SDF_Production)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasProductionWsAfterResult(SDF_Production arg) */

ATbool SDF_hasProductionWsAfterResult(SDF_Production arg)
{
  if (SDF_isProductionProdFun(arg)) {
    return ATtrue;
  }
  else if (SDF_isProductionProd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getProductionWsAfterResult(SDF_Production arg) */

SDF_OptLayout SDF_getProductionWsAfterResult(SDF_Production arg)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
  }
  else 
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionWsAfterResult(SDF_Production arg, SDF_OptLayout wsAfterResult) */

SDF_Production SDF_setProductionWsAfterResult(SDF_Production arg, SDF_OptLayout wsAfterResult)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterResult, 11), 1);
  }
  else if (SDF_isProductionProd(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterResult, 5), 1);
  }

  ATabort("Production has no WsAfterResult: %t\n", arg);
  return (SDF_Production)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasProductionAttributes(SDF_Production arg) */

ATbool SDF_hasProductionAttributes(SDF_Production arg)
{
  if (SDF_isProductionProdFun(arg)) {
    return ATtrue;
  }
  else if (SDF_isProductionProd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Attributes SDF_getProductionAttributes(SDF_Production arg) */

SDF_Attributes SDF_getProductionAttributes(SDF_Production arg)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Attributes)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
  }
  else 
    return (SDF_Attributes)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionAttributes(SDF_Production arg, SDF_Attributes Attributes) */

SDF_Production SDF_setProductionAttributes(SDF_Production arg, SDF_Attributes Attributes)
{
  if (SDF_isProductionProdFun(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Attributes, 12), 1);
  }
  else if (SDF_isProductionProd(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Attributes, 6), 1);
  }

  ATabort("Production has no Attributes: %t\n", arg);
  return (SDF_Production)NULL;
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
  
    return (SDF_Symbols)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionSymbols(SDF_Production arg, SDF_Symbols Symbols) */

SDF_Production SDF_setProductionSymbols(SDF_Production arg, SDF_Symbols Symbols)
{
  if (SDF_isProductionProd(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Symbols, 0), 1);
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
/*{{{  SDF_OptLayout SDF_getProductionWsAfterSymbols(SDF_Production arg) */

SDF_OptLayout SDF_getProductionWsAfterSymbols(SDF_Production arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Production SDF_setProductionWsAfterSymbols(SDF_Production arg, SDF_OptLayout wsAfterSymbols) */

SDF_Production SDF_setProductionWsAfterSymbols(SDF_Production arg, SDF_OptLayout wsAfterSymbols)
{
  if (SDF_isProductionProd(arg)) {
    return (SDF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSymbols, 1), 1);
  }

  ATabort("Production has no WsAfterSymbols: %t\n", arg);
  return (SDF_Production)NULL;
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
/*{{{  inline ATbool SDF_isSymbolArgumentsEmpty(SDF_SymbolArguments arg) */

inline ATbool SDF_isSymbolArgumentsEmpty(SDF_SymbolArguments arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternSymbolArgumentsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolArgumentsSingle(SDF_SymbolArguments arg) */

inline ATbool SDF_isSymbolArgumentsSingle(SDF_SymbolArguments arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolArgumentsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolArgumentsMany(SDF_SymbolArguments arg) */

inline ATbool SDF_isSymbolArgumentsMany(SDF_SymbolArguments arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolArgumentsMany, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
    return (SDF_Symbol)ATgetFirst((ATermList)arg);
  }
  else 
    return (SDF_Symbol)ATgetFirst((ATermList)arg);
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
/*{{{  SDF_OptLayout SDF_getSymbolArgumentsWsAfterFirst(SDF_SymbolArguments arg) */

SDF_OptLayout SDF_getSymbolArgumentsWsAfterFirst(SDF_SymbolArguments arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  SDF_SymbolArguments SDF_setSymbolArgumentsWsAfterFirst(SDF_SymbolArguments arg, SDF_OptLayout wsAfterFirst) */

SDF_SymbolArguments SDF_setSymbolArgumentsWsAfterFirst(SDF_SymbolArguments arg, SDF_OptLayout wsAfterFirst)
{
  if (SDF_isSymbolArgumentsMany(arg)) {
    return (SDF_SymbolArguments)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
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
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
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
/*{{{  SDF_OptLayout SDF_getSymbolArgumentsWsAfterSep(SDF_SymbolArguments arg) */

SDF_OptLayout SDF_getSymbolArgumentsWsAfterSep(SDF_SymbolArguments arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  SDF_SymbolArguments SDF_setSymbolArgumentsWsAfterSep(SDF_SymbolArguments arg, SDF_OptLayout wsAfterSep) */

SDF_SymbolArguments SDF_setSymbolArgumentsWsAfterSep(SDF_SymbolArguments arg, SDF_OptLayout wsAfterSep)
{
  if (SDF_isSymbolArgumentsMany(arg)) {
    return (SDF_SymbolArguments)ATreplace((ATermList)arg, (ATerm)wsAfterSep, 3);
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
  
    return (SDF_SymbolArguments)ATgetTail((ATermList)arg, 4);
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
/*{{{  inline ATbool SDF_isSortOneChar(SDF_Sort arg) */

inline ATbool SDF_isSortOneChar(SDF_Sort arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSortOneChar, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSortMoreChars(SDF_Sort arg) */

inline ATbool SDF_isSortMoreChars(SDF_Sort arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSortMoreChars, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool SDF_hasSortChars(SDF_Sort arg) */

ATbool SDF_hasSortChars(SDF_Sort arg)
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
/*{{{  SDF_CHARLIST SDF_getSortChars(SDF_Sort arg) */

SDF_CHARLIST SDF_getSortChars(SDF_Sort arg)
{
  if (SDF_isSortOneChar(arg)) {
    return (SDF_CHARLIST)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
  }
  else 
    return (SDF_CHARLIST)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  SDF_Sort SDF_setSortChars(SDF_Sort arg, SDF_CHARLIST chars) */

SDF_Sort SDF_setSortChars(SDF_Sort arg, SDF_CHARLIST chars)
{
  if (SDF_isSortOneChar(arg)) {
    return (SDF_Sort)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)chars, 1), 0), 1);
  }
  else if (SDF_isSortMoreChars(arg)) {
    return (SDF_Sort)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)chars, 1), 0), 1);
  }

  ATabort("Sort has no Chars: %t\n", arg);
  return (SDF_Sort)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_SymbolParameters accessors */

/*{{{  ATbool SDF_isValidSymbolParameters(SDF_SymbolParameters arg) */

ATbool SDF_isValidSymbolParameters(SDF_SymbolParameters arg)
{
  if (SDF_isSymbolParametersSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolParametersMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolParametersSingle(SDF_SymbolParameters arg) */

inline ATbool SDF_isSymbolParametersSingle(SDF_SymbolParameters arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolParametersSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolParametersMany(SDF_SymbolParameters arg) */

inline ATbool SDF_isSymbolParametersMany(SDF_SymbolParameters arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolParametersMany, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolParametersHead(SDF_SymbolParameters arg) */

ATbool SDF_hasSymbolParametersHead(SDF_SymbolParameters arg)
{
  if (SDF_isSymbolParametersSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolParametersMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_getSymbolParametersHead(SDF_SymbolParameters arg) */

SDF_Symbol SDF_getSymbolParametersHead(SDF_SymbolParameters arg)
{
  if (SDF_isSymbolParametersSingle(arg)) {
    return (SDF_Symbol)ATgetFirst((ATermList)arg);
  }
  else 
    return (SDF_Symbol)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  SDF_SymbolParameters SDF_setSymbolParametersHead(SDF_SymbolParameters arg, SDF_Symbol head) */

SDF_SymbolParameters SDF_setSymbolParametersHead(SDF_SymbolParameters arg, SDF_Symbol head)
{
  if (SDF_isSymbolParametersSingle(arg)) {
    return (SDF_SymbolParameters)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isSymbolParametersMany(arg)) {
    return (SDF_SymbolParameters)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("SymbolParameters has no Head: %t\n", arg);
  return (SDF_SymbolParameters)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolParametersWsAfterFirst(SDF_SymbolParameters arg) */

ATbool SDF_hasSymbolParametersWsAfterFirst(SDF_SymbolParameters arg)
{
  if (SDF_isSymbolParametersMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getSymbolParametersWsAfterFirst(SDF_SymbolParameters arg) */

SDF_OptLayout SDF_getSymbolParametersWsAfterFirst(SDF_SymbolParameters arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  SDF_SymbolParameters SDF_setSymbolParametersWsAfterFirst(SDF_SymbolParameters arg, SDF_OptLayout wsAfterFirst) */

SDF_SymbolParameters SDF_setSymbolParametersWsAfterFirst(SDF_SymbolParameters arg, SDF_OptLayout wsAfterFirst)
{
  if (SDF_isSymbolParametersMany(arg)) {
    return (SDF_SymbolParameters)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
  }

  ATabort("SymbolParameters has no WsAfterFirst: %t\n", arg);
  return (SDF_SymbolParameters)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolParametersSep(SDF_SymbolParameters arg) */

ATbool SDF_hasSymbolParametersSep(SDF_SymbolParameters arg)
{
  if (SDF_isSymbolParametersMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolParametersSep(SDF_SymbolParameters arg) */

char * SDF_getSymbolParametersSep(SDF_SymbolParameters arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
}

/*}}}  */
/*{{{  SDF_SymbolParameters SDF_setSymbolParametersSep(SDF_SymbolParameters arg, char * sep) */

SDF_SymbolParameters SDF_setSymbolParametersSep(SDF_SymbolParameters arg, char * sep)
{
  if (SDF_isSymbolParametersMany(arg)) {
    return (SDF_SymbolParameters)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("SymbolParameters has no Sep: %t\n", arg);
  return (SDF_SymbolParameters)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolParametersWsAfterSep(SDF_SymbolParameters arg) */

ATbool SDF_hasSymbolParametersWsAfterSep(SDF_SymbolParameters arg)
{
  if (SDF_isSymbolParametersMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getSymbolParametersWsAfterSep(SDF_SymbolParameters arg) */

SDF_OptLayout SDF_getSymbolParametersWsAfterSep(SDF_SymbolParameters arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  SDF_SymbolParameters SDF_setSymbolParametersWsAfterSep(SDF_SymbolParameters arg, SDF_OptLayout wsAfterSep) */

SDF_SymbolParameters SDF_setSymbolParametersWsAfterSep(SDF_SymbolParameters arg, SDF_OptLayout wsAfterSep)
{
  if (SDF_isSymbolParametersMany(arg)) {
    return (SDF_SymbolParameters)ATreplace((ATermList)arg, (ATerm)wsAfterSep, 3);
  }

  ATabort("SymbolParameters has no WsAfterSep: %t\n", arg);
  return (SDF_SymbolParameters)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolParametersTail(SDF_SymbolParameters arg) */

ATbool SDF_hasSymbolParametersTail(SDF_SymbolParameters arg)
{
  if (SDF_isSymbolParametersMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_SymbolParameters SDF_getSymbolParametersTail(SDF_SymbolParameters arg) */

SDF_SymbolParameters SDF_getSymbolParametersTail(SDF_SymbolParameters arg)
{
  
    return (SDF_SymbolParameters)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  SDF_SymbolParameters SDF_setSymbolParametersTail(SDF_SymbolParameters arg, SDF_SymbolParameters tail) */

SDF_SymbolParameters SDF_setSymbolParametersTail(SDF_SymbolParameters arg, SDF_SymbolParameters tail)
{
  if (SDF_isSymbolParametersMany(arg)) {
    return (SDF_SymbolParameters)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("SymbolParameters has no Tail: %t\n", arg);
  return (SDF_SymbolParameters)NULL;
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
/*{{{  inline ATbool SDF_isNumCharDigits(SDF_NumChar arg) */

inline ATbool SDF_isNumCharDigits(SDF_NumChar arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternNumCharDigits, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool SDF_hasNumCharChars(SDF_NumChar arg) */

ATbool SDF_hasNumCharChars(SDF_NumChar arg)
{
  if (SDF_isNumCharDigits(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_CHARLIST SDF_getNumCharChars(SDF_NumChar arg) */

SDF_CHARLIST SDF_getNumCharChars(SDF_NumChar arg)
{
  
    return (SDF_CHARLIST)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  SDF_NumChar SDF_setNumCharChars(SDF_NumChar arg, SDF_CHARLIST chars) */

SDF_NumChar SDF_setNumCharChars(SDF_NumChar arg, SDF_CHARLIST chars)
{
  if (SDF_isNumCharDigits(arg)) {
    return (SDF_NumChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)chars, 1), 0), 1);
  }

  ATabort("NumChar has no Chars: %t\n", arg);
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
/*{{{  inline ATbool SDF_isShortCharRegular(SDF_ShortChar arg) */

inline ATbool SDF_isShortCharRegular(SDF_ShortChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternShortCharRegular, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isShortCharEscaped(SDF_ShortChar arg) */

inline ATbool SDF_isShortCharEscaped(SDF_ShortChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternShortCharEscaped, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool SDF_hasShortCharChars(SDF_ShortChar arg) */

ATbool SDF_hasShortCharChars(SDF_ShortChar arg)
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
/*{{{  SDF_CHARLIST SDF_getShortCharChars(SDF_ShortChar arg) */

SDF_CHARLIST SDF_getShortCharChars(SDF_ShortChar arg)
{
  if (SDF_isShortCharRegular(arg)) {
    return (SDF_CHARLIST)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
  }
  else 
    return (SDF_CHARLIST)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  SDF_ShortChar SDF_setShortCharChars(SDF_ShortChar arg, SDF_CHARLIST chars) */

SDF_ShortChar SDF_setShortCharChars(SDF_ShortChar arg, SDF_CHARLIST chars)
{
  if (SDF_isShortCharRegular(arg)) {
    return (SDF_ShortChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)chars, 1), 0), 1);
  }
  else if (SDF_isShortCharEscaped(arg)) {
    return (SDF_ShortChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)chars, 1), 0), 1);
  }

  ATabort("ShortChar has no Chars: %t\n", arg);
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
  else if (SDF_isCharacterBot(arg)) {
    return ATtrue;
  }
  else if (SDF_isCharacterLabelUnderscoreStart(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SDF_isCharacterNumeric(SDF_Character arg) */

inline ATbool SDF_isCharacterNumeric(SDF_Character arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternCharacterNumeric, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isCharacterShort(SDF_Character arg) */

inline ATbool SDF_isCharacterShort(SDF_Character arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternCharacterShort, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isCharacterTop(SDF_Character arg) */

inline ATbool SDF_isCharacterTop(SDF_Character arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternCharacterTop);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isCharacterEof(SDF_Character arg) */

inline ATbool SDF_isCharacterEof(SDF_Character arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternCharacterEof);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isCharacterBot(SDF_Character arg) */

inline ATbool SDF_isCharacterBot(SDF_Character arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternCharacterBot);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isCharacterLabelUnderscoreStart(SDF_Character arg) */

inline ATbool SDF_isCharacterLabelUnderscoreStart(SDF_Character arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternCharacterLabelUnderscoreStart);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
  
    return (SDF_NumChar)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Character SDF_setCharacterNumChar(SDF_Character arg, SDF_NumChar NumChar) */

SDF_Character SDF_setCharacterNumChar(SDF_Character arg, SDF_NumChar NumChar)
{
  if (SDF_isCharacterNumeric(arg)) {
    return (SDF_Character)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)NumChar, 0), 1);
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
  
    return (SDF_ShortChar)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Character SDF_setCharacterShortChar(SDF_Character arg, SDF_ShortChar ShortChar) */

SDF_Character SDF_setCharacterShortChar(SDF_Character arg, SDF_ShortChar ShortChar)
{
  if (SDF_isCharacterShort(arg)) {
    return (SDF_Character)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ShortChar, 0), 1);
  }

  ATabort("Character has no ShortChar: %t\n", arg);
  return (SDF_Character)NULL;
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
/*{{{  inline ATbool SDF_isCharRangeDefault(SDF_CharRange arg) */

inline ATbool SDF_isCharRangeDefault(SDF_CharRange arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternCharRangeDefault, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isCharRangeRange(SDF_CharRange arg) */

inline ATbool SDF_isCharRangeRange(SDF_CharRange arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternCharRangeRange, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
  
    return (SDF_Character)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_CharRange SDF_setCharRangeCharacter(SDF_CharRange arg, SDF_Character Character) */

SDF_CharRange SDF_setCharRangeCharacter(SDF_CharRange arg, SDF_Character Character)
{
  if (SDF_isCharRangeDefault(arg)) {
    return (SDF_CharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Character, 0), 1);
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
  
    return (SDF_Character)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_CharRange SDF_setCharRangeStart(SDF_CharRange arg, SDF_Character start) */

SDF_CharRange SDF_setCharRangeStart(SDF_CharRange arg, SDF_Character start)
{
  if (SDF_isCharRangeRange(arg)) {
    return (SDF_CharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)start, 0), 1);
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
/*{{{  SDF_OptLayout SDF_getCharRangeWsAfterStart(SDF_CharRange arg) */

SDF_OptLayout SDF_getCharRangeWsAfterStart(SDF_CharRange arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_CharRange SDF_setCharRangeWsAfterStart(SDF_CharRange arg, SDF_OptLayout wsAfterStart) */

SDF_CharRange SDF_setCharRangeWsAfterStart(SDF_CharRange arg, SDF_OptLayout wsAfterStart)
{
  if (SDF_isCharRangeRange(arg)) {
    return (SDF_CharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterStart, 1), 1);
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
/*{{{  SDF_OptLayout SDF_getCharRangeWsAfter(SDF_CharRange arg) */

SDF_OptLayout SDF_getCharRangeWsAfter(SDF_CharRange arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_CharRange SDF_setCharRangeWsAfter(SDF_CharRange arg, SDF_OptLayout wsAfter) */

SDF_CharRange SDF_setCharRangeWsAfter(SDF_CharRange arg, SDF_OptLayout wsAfter)
{
  if (SDF_isCharRangeRange(arg)) {
    return (SDF_CharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfter, 3), 1);
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
  
    return (SDF_Character)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  SDF_CharRange SDF_setCharRangeEnd(SDF_CharRange arg, SDF_Character end) */

SDF_CharRange SDF_setCharRangeEnd(SDF_CharRange arg, SDF_Character end)
{
  if (SDF_isCharRangeRange(arg)) {
    return (SDF_CharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)end, 4), 1);
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
/*{{{  inline ATbool SDF_isCharRangesDefault(SDF_CharRanges arg) */

inline ATbool SDF_isCharRangesDefault(SDF_CharRanges arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternCharRangesDefault, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isCharRangesConc(SDF_CharRanges arg) */

inline ATbool SDF_isCharRangesConc(SDF_CharRanges arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternCharRangesConc, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isCharRangesBracket(SDF_CharRanges arg) */

inline ATbool SDF_isCharRangesBracket(SDF_CharRanges arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternCharRangesBracket, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
  
    return (SDF_CharRange)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_setCharRangesCharRange(SDF_CharRanges arg, SDF_CharRange CharRange) */

SDF_CharRanges SDF_setCharRangesCharRange(SDF_CharRanges arg, SDF_CharRange CharRange)
{
  if (SDF_isCharRangesDefault(arg)) {
    return (SDF_CharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)CharRange, 0), 1);
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
  
    return (SDF_CharRanges)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_setCharRangesLeft(SDF_CharRanges arg, SDF_CharRanges left) */

SDF_CharRanges SDF_setCharRangesLeft(SDF_CharRanges arg, SDF_CharRanges left)
{
  if (SDF_isCharRangesConc(arg)) {
    return (SDF_CharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)left, 0), 1);
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
/*{{{  SDF_OptLayout SDF_getCharRangesWsAfterLeft(SDF_CharRanges arg) */

SDF_OptLayout SDF_getCharRangesWsAfterLeft(SDF_CharRanges arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_setCharRangesWsAfterLeft(SDF_CharRanges arg, SDF_OptLayout wsAfterLeft) */

SDF_CharRanges SDF_setCharRangesWsAfterLeft(SDF_CharRanges arg, SDF_OptLayout wsAfterLeft)
{
  if (SDF_isCharRangesConc(arg)) {
    return (SDF_CharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLeft, 1), 1);
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
  
    return (SDF_CharRanges)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_setCharRangesRight(SDF_CharRanges arg, SDF_CharRanges right) */

SDF_CharRanges SDF_setCharRangesRight(SDF_CharRanges arg, SDF_CharRanges right)
{
  if (SDF_isCharRangesConc(arg)) {
    return (SDF_CharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)right, 2), 1);
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
/*{{{  SDF_OptLayout SDF_getCharRangesWsAfterParenOpen(SDF_CharRanges arg) */

SDF_OptLayout SDF_getCharRangesWsAfterParenOpen(SDF_CharRanges arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_setCharRangesWsAfterParenOpen(SDF_CharRanges arg, SDF_OptLayout wsAfterParenOpen) */

SDF_CharRanges SDF_setCharRangesWsAfterParenOpen(SDF_CharRanges arg, SDF_OptLayout wsAfterParenOpen)
{
  if (SDF_isCharRangesBracket(arg)) {
    return (SDF_CharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 1), 1);
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
  
    return (SDF_CharRanges)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_setCharRangesCharRanges(SDF_CharRanges arg, SDF_CharRanges CharRanges) */

SDF_CharRanges SDF_setCharRangesCharRanges(SDF_CharRanges arg, SDF_CharRanges CharRanges)
{
  if (SDF_isCharRangesBracket(arg)) {
    return (SDF_CharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)CharRanges, 2), 1);
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
/*{{{  SDF_OptLayout SDF_getCharRangesWsAfterCharRanges(SDF_CharRanges arg) */

SDF_OptLayout SDF_getCharRangesWsAfterCharRanges(SDF_CharRanges arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_CharRanges SDF_setCharRangesWsAfterCharRanges(SDF_CharRanges arg, SDF_OptLayout wsAfterCharRanges) */

SDF_CharRanges SDF_setCharRangesWsAfterCharRanges(SDF_CharRanges arg, SDF_OptLayout wsAfterCharRanges)
{
  if (SDF_isCharRangesBracket(arg)) {
    return (SDF_CharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterCharRanges, 3), 1);
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
/*{{{  inline ATbool SDF_isOptCharRangesAbsent(SDF_OptCharRanges arg) */

inline ATbool SDF_isOptCharRangesAbsent(SDF_OptCharRanges arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternOptCharRangesAbsent);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isOptCharRangesPresent(SDF_OptCharRanges arg) */

inline ATbool SDF_isOptCharRangesPresent(SDF_OptCharRanges arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternOptCharRangesPresent, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
  
    return (SDF_CharRanges)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_OptCharRanges SDF_setOptCharRangesCharRanges(SDF_OptCharRanges arg, SDF_CharRanges CharRanges) */

SDF_OptCharRanges SDF_setOptCharRangesCharRanges(SDF_OptCharRanges arg, SDF_CharRanges CharRanges)
{
  if (SDF_isOptCharRangesPresent(arg)) {
    return (SDF_OptCharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)CharRanges, 0), 1);
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
  else if (SDF_isCharClassDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SDF_isCharClassSimpleCharclass(SDF_CharClass arg) */

inline ATbool SDF_isCharClassSimpleCharclass(SDF_CharClass arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternCharClassSimpleCharclass, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isCharClassComp(SDF_CharClass arg) */

inline ATbool SDF_isCharClassComp(SDF_CharClass arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternCharClassComp, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isCharClassDiff(SDF_CharClass arg) */

inline ATbool SDF_isCharClassDiff(SDF_CharClass arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternCharClassDiff, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isCharClassIsect(SDF_CharClass arg) */

inline ATbool SDF_isCharClassIsect(SDF_CharClass arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternCharClassIsect, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isCharClassUnion(SDF_CharClass arg) */

inline ATbool SDF_isCharClassUnion(SDF_CharClass arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternCharClassUnion, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isCharClassDefault(SDF_CharClass arg) */

inline ATbool SDF_isCharClassDefault(SDF_CharClass arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternCharClassDefault, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
/*{{{  SDF_OptLayout SDF_getCharClassWsAfterBracketOpen(SDF_CharClass arg) */

SDF_OptLayout SDF_getCharClassWsAfterBracketOpen(SDF_CharClass arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterBracketOpen(SDF_CharClass arg, SDF_OptLayout wsAfterBracketOpen) */

SDF_CharClass SDF_setCharClassWsAfterBracketOpen(SDF_CharClass arg, SDF_OptLayout wsAfterBracketOpen)
{
  if (SDF_isCharClassSimpleCharclass(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBracketOpen, 1), 1);
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
  
    return (SDF_OptCharRanges)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassOptCharRanges(SDF_CharClass arg, SDF_OptCharRanges OptCharRanges) */

SDF_CharClass SDF_setCharClassOptCharRanges(SDF_CharClass arg, SDF_OptCharRanges OptCharRanges)
{
  if (SDF_isCharClassSimpleCharclass(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)OptCharRanges, 2), 1);
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
/*{{{  SDF_OptLayout SDF_getCharClassWsAfterOptCharRanges(SDF_CharClass arg) */

SDF_OptLayout SDF_getCharClassWsAfterOptCharRanges(SDF_CharClass arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterOptCharRanges(SDF_CharClass arg, SDF_OptLayout wsAfterOptCharRanges) */

SDF_CharClass SDF_setCharClassWsAfterOptCharRanges(SDF_CharClass arg, SDF_OptLayout wsAfterOptCharRanges)
{
  if (SDF_isCharClassSimpleCharclass(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterOptCharRanges, 3), 1);
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
/*{{{  SDF_OptLayout SDF_getCharClassWsAfterTilde(SDF_CharClass arg) */

SDF_OptLayout SDF_getCharClassWsAfterTilde(SDF_CharClass arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterTilde(SDF_CharClass arg, SDF_OptLayout wsAfterTilde) */

SDF_CharClass SDF_setCharClassWsAfterTilde(SDF_CharClass arg, SDF_OptLayout wsAfterTilde)
{
  if (SDF_isCharClassComp(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterTilde, 1), 1);
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
  else if (SDF_isCharClassDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_getCharClassCharClass(SDF_CharClass arg) */

SDF_CharClass SDF_getCharClassCharClass(SDF_CharClass arg)
{
  if (SDF_isCharClassComp(arg)) {
    return (SDF_CharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else 
    return (SDF_CharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassCharClass(SDF_CharClass arg, SDF_CharClass CharClass) */

SDF_CharClass SDF_setCharClassCharClass(SDF_CharClass arg, SDF_CharClass CharClass)
{
  if (SDF_isCharClassComp(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)CharClass, 2), 1);
  }
  else if (SDF_isCharClassDefault(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)CharClass, 2), 1);
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
    return (SDF_CharClass)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isCharClassIsect(arg)) {
    return (SDF_CharClass)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (SDF_CharClass)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassLeft(SDF_CharClass arg, SDF_CharClass left) */

SDF_CharClass SDF_setCharClassLeft(SDF_CharClass arg, SDF_CharClass left)
{
  if (SDF_isCharClassDiff(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)left, 0), 1);
  }
  else if (SDF_isCharClassIsect(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)left, 0), 1);
  }
  else if (SDF_isCharClassUnion(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)left, 0), 1);
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
/*{{{  SDF_OptLayout SDF_getCharClassWsAfterLeft(SDF_CharClass arg) */

SDF_OptLayout SDF_getCharClassWsAfterLeft(SDF_CharClass arg)
{
  if (SDF_isCharClassDiff(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (SDF_isCharClassIsect(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterLeft(SDF_CharClass arg, SDF_OptLayout wsAfterLeft) */

SDF_CharClass SDF_setCharClassWsAfterLeft(SDF_CharClass arg, SDF_OptLayout wsAfterLeft)
{
  if (SDF_isCharClassDiff(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLeft, 1), 1);
  }
  else if (SDF_isCharClassIsect(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLeft, 1), 1);
  }
  else if (SDF_isCharClassUnion(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLeft, 1), 1);
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
/*{{{  SDF_OptLayout SDF_getCharClassWsAfterSlash(SDF_CharClass arg) */

SDF_OptLayout SDF_getCharClassWsAfterSlash(SDF_CharClass arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterSlash(SDF_CharClass arg, SDF_OptLayout wsAfterSlash) */

SDF_CharClass SDF_setCharClassWsAfterSlash(SDF_CharClass arg, SDF_OptLayout wsAfterSlash)
{
  if (SDF_isCharClassDiff(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSlash, 3), 1);
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
    return (SDF_CharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (SDF_isCharClassIsect(arg)) {
    return (SDF_CharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (SDF_CharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassRight(SDF_CharClass arg, SDF_CharClass right) */

SDF_CharClass SDF_setCharClassRight(SDF_CharClass arg, SDF_CharClass right)
{
  if (SDF_isCharClassDiff(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)right, 4), 1);
  }
  else if (SDF_isCharClassIsect(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)right, 4), 1);
  }
  else if (SDF_isCharClassUnion(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)right, 4), 1);
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
/*{{{  SDF_OptLayout SDF_getCharClassWsAfterSlashBackslash(SDF_CharClass arg) */

SDF_OptLayout SDF_getCharClassWsAfterSlashBackslash(SDF_CharClass arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterSlashBackslash(SDF_CharClass arg, SDF_OptLayout wsAfterSlashBackslash) */

SDF_CharClass SDF_setCharClassWsAfterSlashBackslash(SDF_CharClass arg, SDF_OptLayout wsAfterSlashBackslash)
{
  if (SDF_isCharClassIsect(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSlashBackslash, 3), 1);
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
/*{{{  SDF_OptLayout SDF_getCharClassWsAfterBackslashSlash(SDF_CharClass arg) */

SDF_OptLayout SDF_getCharClassWsAfterBackslashSlash(SDF_CharClass arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterBackslashSlash(SDF_CharClass arg, SDF_OptLayout wsAfterBackslashSlash) */

SDF_CharClass SDF_setCharClassWsAfterBackslashSlash(SDF_CharClass arg, SDF_OptLayout wsAfterBackslashSlash)
{
  if (SDF_isCharClassUnion(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBackslashSlash, 3), 1);
  }

  ATabort("CharClass has no WsAfterBackslashSlash: %t\n", arg);
  return (SDF_CharClass)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasCharClassWsAfterParenOpen(SDF_CharClass arg) */

ATbool SDF_hasCharClassWsAfterParenOpen(SDF_CharClass arg)
{
  if (SDF_isCharClassDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getCharClassWsAfterParenOpen(SDF_CharClass arg) */

SDF_OptLayout SDF_getCharClassWsAfterParenOpen(SDF_CharClass arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterParenOpen(SDF_CharClass arg, SDF_OptLayout wsAfterParenOpen) */

SDF_CharClass SDF_setCharClassWsAfterParenOpen(SDF_CharClass arg, SDF_OptLayout wsAfterParenOpen)
{
  if (SDF_isCharClassDefault(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 1), 1);
  }

  ATabort("CharClass has no WsAfterParenOpen: %t\n", arg);
  return (SDF_CharClass)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasCharClassWsAfterCharClass(SDF_CharClass arg) */

ATbool SDF_hasCharClassWsAfterCharClass(SDF_CharClass arg)
{
  if (SDF_isCharClassDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getCharClassWsAfterCharClass(SDF_CharClass arg) */

SDF_OptLayout SDF_getCharClassWsAfterCharClass(SDF_CharClass arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_CharClass SDF_setCharClassWsAfterCharClass(SDF_CharClass arg, SDF_OptLayout wsAfterCharClass) */

SDF_CharClass SDF_setCharClassWsAfterCharClass(SDF_CharClass arg, SDF_OptLayout wsAfterCharClass)
{
  if (SDF_isCharClassDefault(arg)) {
    return (SDF_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterCharClass, 3), 1);
  }

  ATabort("CharClass has no WsAfterCharClass: %t\n", arg);
  return (SDF_CharClass)NULL;
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
/*{{{  inline ATbool SDF_isAssociativityLeft(SDF_Associativity arg) */

inline ATbool SDF_isAssociativityLeft(SDF_Associativity arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternAssociativityLeft);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isAssociativityRight(SDF_Associativity arg) */

inline ATbool SDF_isAssociativityRight(SDF_Associativity arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternAssociativityRight);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isAssociativityNonAssoc(SDF_Associativity arg) */

inline ATbool SDF_isAssociativityNonAssoc(SDF_Associativity arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternAssociativityNonAssoc);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isAssociativityAssoc(SDF_Associativity arg) */

inline ATbool SDF_isAssociativityAssoc(SDF_Associativity arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternAssociativityAssoc);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
/*{{{  inline ATbool SDF_isGroupSimpleGroup(SDF_Group arg) */

inline ATbool SDF_isGroupSimpleGroup(SDF_Group arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternGroupSimpleGroup, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isGroupProdsGroup(SDF_Group arg) */

inline ATbool SDF_isGroupProdsGroup(SDF_Group arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternGroupProdsGroup, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isGroupAssocGroup(SDF_Group arg) */

inline ATbool SDF_isGroupAssocGroup(SDF_Group arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternGroupAssocGroup, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
  
    return (SDF_Production)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Group SDF_setGroupProduction(SDF_Group arg, SDF_Production Production) */

SDF_Group SDF_setGroupProduction(SDF_Group arg, SDF_Production Production)
{
  if (SDF_isGroupSimpleGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Production, 0), 1);
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
/*{{{  SDF_OptLayout SDF_getGroupWsAfterBraceOpen(SDF_Group arg) */

SDF_OptLayout SDF_getGroupWsAfterBraceOpen(SDF_Group arg)
{
  if (SDF_isGroupProdsGroup(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Group SDF_setGroupWsAfterBraceOpen(SDF_Group arg, SDF_OptLayout wsAfterBraceOpen) */

SDF_Group SDF_setGroupWsAfterBraceOpen(SDF_Group arg, SDF_OptLayout wsAfterBraceOpen)
{
  if (SDF_isGroupProdsGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBraceOpen, 1), 1);
  }
  else if (SDF_isGroupAssocGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBraceOpen, 1), 1);
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
    return (SDF_Productions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else 
    return (SDF_Productions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
}

/*}}}  */
/*{{{  SDF_Group SDF_setGroupProductions(SDF_Group arg, SDF_Productions Productions) */

SDF_Group SDF_setGroupProductions(SDF_Group arg, SDF_Productions Productions)
{
  if (SDF_isGroupProdsGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Productions, 2), 1);
  }
  else if (SDF_isGroupAssocGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Productions, 6), 1);
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
/*{{{  SDF_OptLayout SDF_getGroupWsAfterProductions(SDF_Group arg) */

SDF_OptLayout SDF_getGroupWsAfterProductions(SDF_Group arg)
{
  if (SDF_isGroupProdsGroup(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  SDF_Group SDF_setGroupWsAfterProductions(SDF_Group arg, SDF_OptLayout wsAfterProductions) */

SDF_Group SDF_setGroupWsAfterProductions(SDF_Group arg, SDF_OptLayout wsAfterProductions)
{
  if (SDF_isGroupProdsGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterProductions, 3), 1);
  }
  else if (SDF_isGroupAssocGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterProductions, 7), 1);
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
  
    return (SDF_Associativity)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  SDF_Group SDF_setGroupAssociativity(SDF_Group arg, SDF_Associativity Associativity) */

SDF_Group SDF_setGroupAssociativity(SDF_Group arg, SDF_Associativity Associativity)
{
  if (SDF_isGroupAssocGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Associativity, 2), 1);
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
/*{{{  SDF_OptLayout SDF_getGroupWsAfterAssociativity(SDF_Group arg) */

SDF_OptLayout SDF_getGroupWsAfterAssociativity(SDF_Group arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Group SDF_setGroupWsAfterAssociativity(SDF_Group arg, SDF_OptLayout wsAfterAssociativity) */

SDF_Group SDF_setGroupWsAfterAssociativity(SDF_Group arg, SDF_OptLayout wsAfterAssociativity)
{
  if (SDF_isGroupAssocGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterAssociativity, 3), 1);
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
/*{{{  SDF_OptLayout SDF_getGroupWsAfterColon(SDF_Group arg) */

SDF_OptLayout SDF_getGroupWsAfterColon(SDF_Group arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  SDF_Group SDF_setGroupWsAfterColon(SDF_Group arg, SDF_OptLayout wsAfterColon) */

SDF_Group SDF_setGroupWsAfterColon(SDF_Group arg, SDF_OptLayout wsAfterColon)
{
  if (SDF_isGroupAssocGroup(arg)) {
    return (SDF_Group)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterColon, 5), 1);
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
/*{{{  inline ATbool SDF_isPriorityChain(SDF_Priority arg) */

inline ATbool SDF_isPriorityChain(SDF_Priority arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternPriorityChain, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isPriorityAssoc(SDF_Priority arg) */

inline ATbool SDF_isPriorityAssoc(SDF_Priority arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternPriorityAssoc, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
  
    return (SDF_GroupList)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  SDF_Priority SDF_setPriorityList(SDF_Priority arg, SDF_GroupList list) */

SDF_Priority SDF_setPriorityList(SDF_Priority arg, SDF_GroupList list)
{
  if (SDF_isPriorityChain(arg)) {
    return (SDF_Priority)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)list, 1), 0), 1);
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
  
    return (SDF_Group)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Priority SDF_setPriorityLeft(SDF_Priority arg, SDF_Group left) */

SDF_Priority SDF_setPriorityLeft(SDF_Priority arg, SDF_Group left)
{
  if (SDF_isPriorityAssoc(arg)) {
    return (SDF_Priority)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)left, 0), 1);
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
/*{{{  SDF_OptLayout SDF_getPriorityWsAfterLeft(SDF_Priority arg) */

SDF_OptLayout SDF_getPriorityWsAfterLeft(SDF_Priority arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Priority SDF_setPriorityWsAfterLeft(SDF_Priority arg, SDF_OptLayout wsAfterLeft) */

SDF_Priority SDF_setPriorityWsAfterLeft(SDF_Priority arg, SDF_OptLayout wsAfterLeft)
{
  if (SDF_isPriorityAssoc(arg)) {
    return (SDF_Priority)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLeft, 1), 1);
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
  
    return (SDF_Associativity)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  SDF_Priority SDF_setPriorityAssociativity(SDF_Priority arg, SDF_Associativity Associativity) */

SDF_Priority SDF_setPriorityAssociativity(SDF_Priority arg, SDF_Associativity Associativity)
{
  if (SDF_isPriorityAssoc(arg)) {
    return (SDF_Priority)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Associativity, 2), 1);
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
/*{{{  SDF_OptLayout SDF_getPriorityWsAfterAssociativity(SDF_Priority arg) */

SDF_OptLayout SDF_getPriorityWsAfterAssociativity(SDF_Priority arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Priority SDF_setPriorityWsAfterAssociativity(SDF_Priority arg, SDF_OptLayout wsAfterAssociativity) */

SDF_Priority SDF_setPriorityWsAfterAssociativity(SDF_Priority arg, SDF_OptLayout wsAfterAssociativity)
{
  if (SDF_isPriorityAssoc(arg)) {
    return (SDF_Priority)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterAssociativity, 3), 1);
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
  
    return (SDF_Group)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  SDF_Priority SDF_setPriorityRight(SDF_Priority arg, SDF_Group right) */

SDF_Priority SDF_setPriorityRight(SDF_Priority arg, SDF_Group right)
{
  if (SDF_isPriorityAssoc(arg)) {
    return (SDF_Priority)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)right, 4), 1);
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
/*{{{  inline ATbool SDF_isGroupListSingle(SDF_GroupList arg) */

inline ATbool SDF_isGroupListSingle(SDF_GroupList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternGroupListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isGroupListMany(SDF_GroupList arg) */

inline ATbool SDF_isGroupListMany(SDF_GroupList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternGroupListMany, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
    return (SDF_Group)ATgetFirst((ATermList)arg);
  }
  else 
    return (SDF_Group)ATgetFirst((ATermList)arg);
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
/*{{{  SDF_OptLayout SDF_getGroupListWsAfterFirst(SDF_GroupList arg) */

SDF_OptLayout SDF_getGroupListWsAfterFirst(SDF_GroupList arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  SDF_GroupList SDF_setGroupListWsAfterFirst(SDF_GroupList arg, SDF_OptLayout wsAfterFirst) */

SDF_GroupList SDF_setGroupListWsAfterFirst(SDF_GroupList arg, SDF_OptLayout wsAfterFirst)
{
  if (SDF_isGroupListMany(arg)) {
    return (SDF_GroupList)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
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
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
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
/*{{{  SDF_OptLayout SDF_getGroupListWsAfterSep(SDF_GroupList arg) */

SDF_OptLayout SDF_getGroupListWsAfterSep(SDF_GroupList arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  SDF_GroupList SDF_setGroupListWsAfterSep(SDF_GroupList arg, SDF_OptLayout wsAfterSep) */

SDF_GroupList SDF_setGroupListWsAfterSep(SDF_GroupList arg, SDF_OptLayout wsAfterSep)
{
  if (SDF_isGroupListMany(arg)) {
    return (SDF_GroupList)ATreplace((ATermList)arg, (ATerm)wsAfterSep, 3);
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
  
    return (SDF_GroupList)ATgetTail((ATermList)arg, 4);
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
/*{{{  inline ATbool SDF_isPrioritiesDefault(SDF_Priorities arg) */

inline ATbool SDF_isPrioritiesDefault(SDF_Priorities arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternPrioritiesDefault, NULL));
#endif
  return ATtrue;
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
  
    return (SDF_PriorityList)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  SDF_Priorities SDF_setPrioritiesList(SDF_Priorities arg, SDF_PriorityList list) */

SDF_Priorities SDF_setPrioritiesList(SDF_Priorities arg, SDF_PriorityList list)
{
  if (SDF_isPrioritiesDefault(arg)) {
    return (SDF_Priorities)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)list, 1), 0), 1);
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
/*{{{  inline ATbool SDF_isPriorityListEmpty(SDF_PriorityList arg) */

inline ATbool SDF_isPriorityListEmpty(SDF_PriorityList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternPriorityListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool SDF_isPriorityListSingle(SDF_PriorityList arg) */

inline ATbool SDF_isPriorityListSingle(SDF_PriorityList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternPriorityListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isPriorityListMany(SDF_PriorityList arg) */

inline ATbool SDF_isPriorityListMany(SDF_PriorityList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternPriorityListMany, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
    return (SDF_Priority)ATgetFirst((ATermList)arg);
  }
  else 
    return (SDF_Priority)ATgetFirst((ATermList)arg);
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
/*{{{  SDF_OptLayout SDF_getPriorityListWsAfterFirst(SDF_PriorityList arg) */

SDF_OptLayout SDF_getPriorityListWsAfterFirst(SDF_PriorityList arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  SDF_PriorityList SDF_setPriorityListWsAfterFirst(SDF_PriorityList arg, SDF_OptLayout wsAfterFirst) */

SDF_PriorityList SDF_setPriorityListWsAfterFirst(SDF_PriorityList arg, SDF_OptLayout wsAfterFirst)
{
  if (SDF_isPriorityListMany(arg)) {
    return (SDF_PriorityList)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
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
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
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
/*{{{  SDF_OptLayout SDF_getPriorityListWsAfterSep(SDF_PriorityList arg) */

SDF_OptLayout SDF_getPriorityListWsAfterSep(SDF_PriorityList arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  SDF_PriorityList SDF_setPriorityListWsAfterSep(SDF_PriorityList arg, SDF_OptLayout wsAfterSep) */

SDF_PriorityList SDF_setPriorityListWsAfterSep(SDF_PriorityList arg, SDF_OptLayout wsAfterSep)
{
  if (SDF_isPriorityListMany(arg)) {
    return (SDF_PriorityList)ATreplace((ATermList)arg, (ATerm)wsAfterSep, 3);
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
  
    return (SDF_PriorityList)ATgetTail((ATermList)arg, 4);
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
/*{{{  inline ATbool SDF_isSymbolTailSingle(SDF_SymbolTail arg) */

inline ATbool SDF_isSymbolTailSingle(SDF_SymbolTail arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolTailSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolTailMany(SDF_SymbolTail arg) */

inline ATbool SDF_isSymbolTailMany(SDF_SymbolTail arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolTailMany, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
    return (SDF_Symbol)ATgetFirst((ATermList)arg);
  }
  else 
    return (SDF_Symbol)ATgetFirst((ATermList)arg);
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
/*{{{  SDF_OptLayout SDF_getSymbolTailWsAfterFirst(SDF_SymbolTail arg) */

SDF_OptLayout SDF_getSymbolTailWsAfterFirst(SDF_SymbolTail arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  SDF_SymbolTail SDF_setSymbolTailWsAfterFirst(SDF_SymbolTail arg, SDF_OptLayout wsAfterFirst) */

SDF_SymbolTail SDF_setSymbolTailWsAfterFirst(SDF_SymbolTail arg, SDF_OptLayout wsAfterFirst)
{
  if (SDF_isSymbolTailMany(arg)) {
    return (SDF_SymbolTail)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
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
  
    return (SDF_SymbolTail)ATgetTail((ATermList)arg, 2);
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
/*{{{  SDF_SymbolRest accessors */

/*{{{  ATbool SDF_isValidSymbolRest(SDF_SymbolRest arg) */

ATbool SDF_isValidSymbolRest(SDF_SymbolRest arg)
{
  if (SDF_isSymbolRestSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolRestMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolRestSingle(SDF_SymbolRest arg) */

inline ATbool SDF_isSymbolRestSingle(SDF_SymbolRest arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolRestSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolRestMany(SDF_SymbolRest arg) */

inline ATbool SDF_isSymbolRestMany(SDF_SymbolRest arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolRestMany, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolRestHead(SDF_SymbolRest arg) */

ATbool SDF_hasSymbolRestHead(SDF_SymbolRest arg)
{
  if (SDF_isSymbolRestSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isSymbolRestMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_getSymbolRestHead(SDF_SymbolRest arg) */

SDF_Symbol SDF_getSymbolRestHead(SDF_SymbolRest arg)
{
  if (SDF_isSymbolRestSingle(arg)) {
    return (SDF_Symbol)ATgetFirst((ATermList)arg);
  }
  else 
    return (SDF_Symbol)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  SDF_SymbolRest SDF_setSymbolRestHead(SDF_SymbolRest arg, SDF_Symbol head) */

SDF_SymbolRest SDF_setSymbolRestHead(SDF_SymbolRest arg, SDF_Symbol head)
{
  if (SDF_isSymbolRestSingle(arg)) {
    return (SDF_SymbolRest)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isSymbolRestMany(arg)) {
    return (SDF_SymbolRest)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("SymbolRest has no Head: %t\n", arg);
  return (SDF_SymbolRest)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolRestWsAfterFirst(SDF_SymbolRest arg) */

ATbool SDF_hasSymbolRestWsAfterFirst(SDF_SymbolRest arg)
{
  if (SDF_isSymbolRestMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getSymbolRestWsAfterFirst(SDF_SymbolRest arg) */

SDF_OptLayout SDF_getSymbolRestWsAfterFirst(SDF_SymbolRest arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  SDF_SymbolRest SDF_setSymbolRestWsAfterFirst(SDF_SymbolRest arg, SDF_OptLayout wsAfterFirst) */

SDF_SymbolRest SDF_setSymbolRestWsAfterFirst(SDF_SymbolRest arg, SDF_OptLayout wsAfterFirst)
{
  if (SDF_isSymbolRestMany(arg)) {
    return (SDF_SymbolRest)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
  }

  ATabort("SymbolRest has no WsAfterFirst: %t\n", arg);
  return (SDF_SymbolRest)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolRestSep(SDF_SymbolRest arg) */

ATbool SDF_hasSymbolRestSep(SDF_SymbolRest arg)
{
  if (SDF_isSymbolRestMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getSymbolRestSep(SDF_SymbolRest arg) */

char * SDF_getSymbolRestSep(SDF_SymbolRest arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
}

/*}}}  */
/*{{{  SDF_SymbolRest SDF_setSymbolRestSep(SDF_SymbolRest arg, char * sep) */

SDF_SymbolRest SDF_setSymbolRestSep(SDF_SymbolRest arg, char * sep)
{
  if (SDF_isSymbolRestMany(arg)) {
    return (SDF_SymbolRest)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("SymbolRest has no Sep: %t\n", arg);
  return (SDF_SymbolRest)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolRestWsAfterSep(SDF_SymbolRest arg) */

ATbool SDF_hasSymbolRestWsAfterSep(SDF_SymbolRest arg)
{
  if (SDF_isSymbolRestMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getSymbolRestWsAfterSep(SDF_SymbolRest arg) */

SDF_OptLayout SDF_getSymbolRestWsAfterSep(SDF_SymbolRest arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  SDF_SymbolRest SDF_setSymbolRestWsAfterSep(SDF_SymbolRest arg, SDF_OptLayout wsAfterSep) */

SDF_SymbolRest SDF_setSymbolRestWsAfterSep(SDF_SymbolRest arg, SDF_OptLayout wsAfterSep)
{
  if (SDF_isSymbolRestMany(arg)) {
    return (SDF_SymbolRest)ATreplace((ATermList)arg, (ATerm)wsAfterSep, 3);
  }

  ATabort("SymbolRest has no WsAfterSep: %t\n", arg);
  return (SDF_SymbolRest)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasSymbolRestTail(SDF_SymbolRest arg) */

ATbool SDF_hasSymbolRestTail(SDF_SymbolRest arg)
{
  if (SDF_isSymbolRestMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_SymbolRest SDF_getSymbolRestTail(SDF_SymbolRest arg) */

SDF_SymbolRest SDF_getSymbolRestTail(SDF_SymbolRest arg)
{
  
    return (SDF_SymbolRest)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  SDF_SymbolRest SDF_setSymbolRestTail(SDF_SymbolRest arg, SDF_SymbolRest tail) */

SDF_SymbolRest SDF_setSymbolRestTail(SDF_SymbolRest arg, SDF_SymbolRest tail)
{
  if (SDF_isSymbolRestMany(arg)) {
    return (SDF_SymbolRest)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("SymbolRest has no Tail: %t\n", arg);
  return (SDF_SymbolRest)NULL;
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
/*{{{  inline ATbool SDF_isRenamingsRenamings(SDF_Renamings arg) */

inline ATbool SDF_isRenamingsRenamings(SDF_Renamings arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternRenamingsRenamings, NULL, NULL, NULL));
#endif
  return ATtrue;
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
/*{{{  SDF_OptLayout SDF_getRenamingsWsAfterBracketOpen(SDF_Renamings arg) */

SDF_OptLayout SDF_getRenamingsWsAfterBracketOpen(SDF_Renamings arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Renamings SDF_setRenamingsWsAfterBracketOpen(SDF_Renamings arg, SDF_OptLayout wsAfterBracketOpen) */

SDF_Renamings SDF_setRenamingsWsAfterBracketOpen(SDF_Renamings arg, SDF_OptLayout wsAfterBracketOpen)
{
  if (SDF_isRenamingsRenamings(arg)) {
    return (SDF_Renamings)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBracketOpen, 1), 1);
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
  
    return (SDF_RenamingList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
}

/*}}}  */
/*{{{  SDF_Renamings SDF_setRenamingsList(SDF_Renamings arg, SDF_RenamingList list) */

SDF_Renamings SDF_setRenamingsList(SDF_Renamings arg, SDF_RenamingList list)
{
  if (SDF_isRenamingsRenamings(arg)) {
    return (SDF_Renamings)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)list, 1), 2), 1);
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
/*{{{  SDF_OptLayout SDF_getRenamingsWsAfterList(SDF_Renamings arg) */

SDF_OptLayout SDF_getRenamingsWsAfterList(SDF_Renamings arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Renamings SDF_setRenamingsWsAfterList(SDF_Renamings arg, SDF_OptLayout wsAfterList) */

SDF_Renamings SDF_setRenamingsWsAfterList(SDF_Renamings arg, SDF_OptLayout wsAfterList)
{
  if (SDF_isRenamingsRenamings(arg)) {
    return (SDF_Renamings)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterList, 3), 1);
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
/*{{{  inline ATbool SDF_isRenamingListEmpty(SDF_RenamingList arg) */

inline ATbool SDF_isRenamingListEmpty(SDF_RenamingList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternRenamingListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool SDF_isRenamingListSingle(SDF_RenamingList arg) */

inline ATbool SDF_isRenamingListSingle(SDF_RenamingList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternRenamingListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isRenamingListMany(SDF_RenamingList arg) */

inline ATbool SDF_isRenamingListMany(SDF_RenamingList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternRenamingListMany, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
    return (SDF_Renaming)ATgetFirst((ATermList)arg);
  }
  else 
    return (SDF_Renaming)ATgetFirst((ATermList)arg);
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
/*{{{  SDF_OptLayout SDF_getRenamingListWsAfterFirst(SDF_RenamingList arg) */

SDF_OptLayout SDF_getRenamingListWsAfterFirst(SDF_RenamingList arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  SDF_RenamingList SDF_setRenamingListWsAfterFirst(SDF_RenamingList arg, SDF_OptLayout wsAfterFirst) */

SDF_RenamingList SDF_setRenamingListWsAfterFirst(SDF_RenamingList arg, SDF_OptLayout wsAfterFirst)
{
  if (SDF_isRenamingListMany(arg)) {
    return (SDF_RenamingList)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
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
  
    return (SDF_RenamingList)ATgetTail((ATermList)arg, 2);
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
/*{{{  inline ATbool SDF_isRenamingSymbol(SDF_Renaming arg) */

inline ATbool SDF_isRenamingSymbol(SDF_Renaming arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternRenamingSymbol, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isRenamingProduction(SDF_Renaming arg) */

inline ATbool SDF_isRenamingProduction(SDF_Renaming arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternRenamingProduction, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool SDF_hasRenamingFrom(SDF_Renaming arg) */

ATbool SDF_hasRenamingFrom(SDF_Renaming arg)
{
  if (SDF_isRenamingSymbol(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_getRenamingFrom(SDF_Renaming arg) */

SDF_Symbol SDF_getRenamingFrom(SDF_Renaming arg)
{
  
    return (SDF_Symbol)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Renaming SDF_setRenamingFrom(SDF_Renaming arg, SDF_Symbol from) */

SDF_Renaming SDF_setRenamingFrom(SDF_Renaming arg, SDF_Symbol from)
{
  if (SDF_isRenamingSymbol(arg)) {
    return (SDF_Renaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)from, 0), 1);
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
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getRenamingWsAfterFrom(SDF_Renaming arg) */

SDF_OptLayout SDF_getRenamingWsAfterFrom(SDF_Renaming arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Renaming SDF_setRenamingWsAfterFrom(SDF_Renaming arg, SDF_OptLayout wsAfterFrom) */

SDF_Renaming SDF_setRenamingWsAfterFrom(SDF_Renaming arg, SDF_OptLayout wsAfterFrom)
{
  if (SDF_isRenamingSymbol(arg)) {
    return (SDF_Renaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterFrom, 1), 1);
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
/*{{{  SDF_OptLayout SDF_getRenamingWsAfterEqualsGreaterThan(SDF_Renaming arg) */

SDF_OptLayout SDF_getRenamingWsAfterEqualsGreaterThan(SDF_Renaming arg)
{
  if (SDF_isRenamingSymbol(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Renaming SDF_setRenamingWsAfterEqualsGreaterThan(SDF_Renaming arg, SDF_OptLayout wsAfterEqualsGreaterThan) */

SDF_Renaming SDF_setRenamingWsAfterEqualsGreaterThan(SDF_Renaming arg, SDF_OptLayout wsAfterEqualsGreaterThan)
{
  if (SDF_isRenamingSymbol(arg)) {
    return (SDF_Renaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterEqualsGreaterThan, 3), 1);
  }
  else if (SDF_isRenamingProduction(arg)) {
    return (SDF_Renaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterEqualsGreaterThan, 3), 1);
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
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_getRenamingTo(SDF_Renaming arg) */

SDF_Symbol SDF_getRenamingTo(SDF_Renaming arg)
{
  
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  SDF_Renaming SDF_setRenamingTo(SDF_Renaming arg, SDF_Symbol to) */

SDF_Renaming SDF_setRenamingTo(SDF_Renaming arg, SDF_Symbol to)
{
  if (SDF_isRenamingSymbol(arg)) {
    return (SDF_Renaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)to, 4), 1);
  }

  ATabort("Renaming has no To: %t\n", arg);
  return (SDF_Renaming)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasRenamingFromProd(SDF_Renaming arg) */

ATbool SDF_hasRenamingFromProd(SDF_Renaming arg)
{
  if (SDF_isRenamingProduction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Production SDF_getRenamingFromProd(SDF_Renaming arg) */

SDF_Production SDF_getRenamingFromProd(SDF_Renaming arg)
{
  
    return (SDF_Production)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Renaming SDF_setRenamingFromProd(SDF_Renaming arg, SDF_Production fromProd) */

SDF_Renaming SDF_setRenamingFromProd(SDF_Renaming arg, SDF_Production fromProd)
{
  if (SDF_isRenamingProduction(arg)) {
    return (SDF_Renaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)fromProd, 0), 1);
  }

  ATabort("Renaming has no FromProd: %t\n", arg);
  return (SDF_Renaming)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasRenamingWsAfterFromProd(SDF_Renaming arg) */

ATbool SDF_hasRenamingWsAfterFromProd(SDF_Renaming arg)
{
  if (SDF_isRenamingProduction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getRenamingWsAfterFromProd(SDF_Renaming arg) */

SDF_OptLayout SDF_getRenamingWsAfterFromProd(SDF_Renaming arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Renaming SDF_setRenamingWsAfterFromProd(SDF_Renaming arg, SDF_OptLayout wsAfterFromProd) */

SDF_Renaming SDF_setRenamingWsAfterFromProd(SDF_Renaming arg, SDF_OptLayout wsAfterFromProd)
{
  if (SDF_isRenamingProduction(arg)) {
    return (SDF_Renaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterFromProd, 1), 1);
  }

  ATabort("Renaming has no WsAfterFromProd: %t\n", arg);
  return (SDF_Renaming)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasRenamingToProd(SDF_Renaming arg) */

ATbool SDF_hasRenamingToProd(SDF_Renaming arg)
{
  if (SDF_isRenamingProduction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Production SDF_getRenamingToProd(SDF_Renaming arg) */

SDF_Production SDF_getRenamingToProd(SDF_Renaming arg)
{
  
    return (SDF_Production)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  SDF_Renaming SDF_setRenamingToProd(SDF_Renaming arg, SDF_Production toProd) */

SDF_Renaming SDF_setRenamingToProd(SDF_Renaming arg, SDF_Production toProd)
{
  if (SDF_isRenamingProduction(arg)) {
    return (SDF_Renaming)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)toProd, 4), 1);
  }

  ATabort("Renaming has no ToProd: %t\n", arg);
  return (SDF_Renaming)NULL;
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
/*{{{  inline ATbool SDF_isModuleWordWord(SDF_ModuleWord arg) */

inline ATbool SDF_isModuleWordWord(SDF_ModuleWord arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternModuleWordWord, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool SDF_hasModuleWordChars(SDF_ModuleWord arg) */

ATbool SDF_hasModuleWordChars(SDF_ModuleWord arg)
{
  if (SDF_isModuleWordWord(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_CHARLIST SDF_getModuleWordChars(SDF_ModuleWord arg) */

SDF_CHARLIST SDF_getModuleWordChars(SDF_ModuleWord arg)
{
  
    return (SDF_CHARLIST)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  SDF_ModuleWord SDF_setModuleWordChars(SDF_ModuleWord arg, SDF_CHARLIST chars) */

SDF_ModuleWord SDF_setModuleWordChars(SDF_ModuleWord arg, SDF_CHARLIST chars)
{
  if (SDF_isModuleWordWord(arg)) {
    return (SDF_ModuleWord)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)chars, 1), 0), 1);
  }

  ATabort("ModuleWord has no Chars: %t\n", arg);
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
/*{{{  inline ATbool SDF_isModuleIdWord(SDF_ModuleId arg) */

inline ATbool SDF_isModuleIdWord(SDF_ModuleId arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternModuleIdWord, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isModuleIdSlashWord(SDF_ModuleId arg) */

inline ATbool SDF_isModuleIdSlashWord(SDF_ModuleId arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternModuleIdSlashWord, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isModuleIdWordSlashWord(SDF_ModuleId arg) */

inline ATbool SDF_isModuleIdWordSlashWord(SDF_ModuleId arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternModuleIdWordSlashWord, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool SDF_hasModuleIdChars(SDF_ModuleId arg) */

ATbool SDF_hasModuleIdChars(SDF_ModuleId arg)
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
/*{{{  SDF_CHARLIST SDF_getModuleIdChars(SDF_ModuleId arg) */

SDF_CHARLIST SDF_getModuleIdChars(SDF_ModuleId arg)
{
  if (SDF_isModuleIdWord(arg)) {
    return (SDF_CHARLIST)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
  }
  else if (SDF_isModuleIdSlashWord(arg)) {
    return (SDF_CHARLIST)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
  }
  else 
    return (SDF_CHARLIST)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  SDF_ModuleId SDF_setModuleIdChars(SDF_ModuleId arg, SDF_CHARLIST chars) */

SDF_ModuleId SDF_setModuleIdChars(SDF_ModuleId arg, SDF_CHARLIST chars)
{
  if (SDF_isModuleIdWord(arg)) {
    return (SDF_ModuleId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)chars, 1), 0), 1);
  }
  else if (SDF_isModuleIdSlashWord(arg)) {
    return (SDF_ModuleId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)chars, 1), 0), 1);
  }
  else if (SDF_isModuleIdWordSlashWord(arg)) {
    return (SDF_ModuleId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)chars, 1), 0), 1);
  }

  ATabort("ModuleId has no Chars: %t\n", arg);
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
/*{{{  inline ATbool SDF_isDefinitionDefault(SDF_Definition arg) */

inline ATbool SDF_isDefinitionDefault(SDF_Definition arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternDefinitionDefault, NULL));
#endif
  return ATtrue;
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
  
    return (SDF_ModuleList)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  SDF_Definition SDF_setDefinitionList(SDF_Definition arg, SDF_ModuleList list) */

SDF_Definition SDF_setDefinitionList(SDF_Definition arg, SDF_ModuleList list)
{
  if (SDF_isDefinitionDefault(arg)) {
    return (SDF_Definition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)list, 1), 0), 1);
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
/*{{{  inline ATbool SDF_isModuleListEmpty(SDF_ModuleList arg) */

inline ATbool SDF_isModuleListEmpty(SDF_ModuleList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternModuleListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool SDF_isModuleListSingle(SDF_ModuleList arg) */

inline ATbool SDF_isModuleListSingle(SDF_ModuleList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternModuleListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isModuleListMany(SDF_ModuleList arg) */

inline ATbool SDF_isModuleListMany(SDF_ModuleList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternModuleListMany, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
    return (SDF_Module)ATgetFirst((ATermList)arg);
  }
  else 
    return (SDF_Module)ATgetFirst((ATermList)arg);
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
/*{{{  SDF_OptLayout SDF_getModuleListWsAfterFirst(SDF_ModuleList arg) */

SDF_OptLayout SDF_getModuleListWsAfterFirst(SDF_ModuleList arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  SDF_ModuleList SDF_setModuleListWsAfterFirst(SDF_ModuleList arg, SDF_OptLayout wsAfterFirst) */

SDF_ModuleList SDF_setModuleListWsAfterFirst(SDF_ModuleList arg, SDF_OptLayout wsAfterFirst)
{
  if (SDF_isModuleListMany(arg)) {
    return (SDF_ModuleList)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
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
  
    return (SDF_ModuleList)ATgetTail((ATermList)arg, 2);
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
/*{{{  inline ATbool SDF_isModuleModule(SDF_Module arg) */

inline ATbool SDF_isModuleModule(SDF_Module arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternModuleModule, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
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
/*{{{  SDF_OptLayout SDF_getModuleWsAfterModule(SDF_Module arg) */

SDF_OptLayout SDF_getModuleWsAfterModule(SDF_Module arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Module SDF_setModuleWsAfterModule(SDF_Module arg, SDF_OptLayout wsAfterModule) */

SDF_Module SDF_setModuleWsAfterModule(SDF_Module arg, SDF_OptLayout wsAfterModule)
{
  if (SDF_isModuleModule(arg)) {
    return (SDF_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterModule, 1), 1);
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
  
    return (SDF_ModuleName)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  SDF_Module SDF_setModuleModuleName(SDF_Module arg, SDF_ModuleName ModuleName) */

SDF_Module SDF_setModuleModuleName(SDF_Module arg, SDF_ModuleName ModuleName)
{
  if (SDF_isModuleModule(arg)) {
    return (SDF_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ModuleName, 2), 1);
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
/*{{{  SDF_OptLayout SDF_getModuleWsAfterModuleName(SDF_Module arg) */

SDF_OptLayout SDF_getModuleWsAfterModuleName(SDF_Module arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Module SDF_setModuleWsAfterModuleName(SDF_Module arg, SDF_OptLayout wsAfterModuleName) */

SDF_Module SDF_setModuleWsAfterModuleName(SDF_Module arg, SDF_OptLayout wsAfterModuleName)
{
  if (SDF_isModuleModule(arg)) {
    return (SDF_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterModuleName, 3), 1);
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
  
    return (SDF_ImpSectionList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 1);
}

/*}}}  */
/*{{{  SDF_Module SDF_setModuleList(SDF_Module arg, SDF_ImpSectionList list) */

SDF_Module SDF_setModuleList(SDF_Module arg, SDF_ImpSectionList list)
{
  if (SDF_isModuleModule(arg)) {
    return (SDF_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)list, 1), 4), 1);
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
/*{{{  SDF_OptLayout SDF_getModuleWsAfterList(SDF_Module arg) */

SDF_OptLayout SDF_getModuleWsAfterList(SDF_Module arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  SDF_Module SDF_setModuleWsAfterList(SDF_Module arg, SDF_OptLayout wsAfterList) */

SDF_Module SDF_setModuleWsAfterList(SDF_Module arg, SDF_OptLayout wsAfterList)
{
  if (SDF_isModuleModule(arg)) {
    return (SDF_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterList, 5), 1);
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
  
    return (SDF_Sections)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
}

/*}}}  */
/*{{{  SDF_Module SDF_setModuleSections(SDF_Module arg, SDF_Sections Sections) */

SDF_Module SDF_setModuleSections(SDF_Module arg, SDF_Sections Sections)
{
  if (SDF_isModuleModule(arg)) {
    return (SDF_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Sections, 6), 1);
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
/*{{{  inline ATbool SDF_isImpSectionListEmpty(SDF_ImpSectionList arg) */

inline ATbool SDF_isImpSectionListEmpty(SDF_ImpSectionList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternImpSectionListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool SDF_isImpSectionListSingle(SDF_ImpSectionList arg) */

inline ATbool SDF_isImpSectionListSingle(SDF_ImpSectionList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternImpSectionListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isImpSectionListMany(SDF_ImpSectionList arg) */

inline ATbool SDF_isImpSectionListMany(SDF_ImpSectionList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternImpSectionListMany, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
    return (SDF_ImpSection)ATgetFirst((ATermList)arg);
  }
  else 
    return (SDF_ImpSection)ATgetFirst((ATermList)arg);
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
/*{{{  SDF_OptLayout SDF_getImpSectionListWsAfterFirst(SDF_ImpSectionList arg) */

SDF_OptLayout SDF_getImpSectionListWsAfterFirst(SDF_ImpSectionList arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  SDF_ImpSectionList SDF_setImpSectionListWsAfterFirst(SDF_ImpSectionList arg, SDF_OptLayout wsAfterFirst) */

SDF_ImpSectionList SDF_setImpSectionListWsAfterFirst(SDF_ImpSectionList arg, SDF_OptLayout wsAfterFirst)
{
  if (SDF_isImpSectionListMany(arg)) {
    return (SDF_ImpSectionList)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
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
  
    return (SDF_ImpSectionList)ATgetTail((ATermList)arg, 2);
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
/*{{{  inline ATbool SDF_isSectionExports(SDF_Section arg) */

inline ATbool SDF_isSectionExports(SDF_Section arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSectionExports, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSectionHiddens(SDF_Section arg) */

inline ATbool SDF_isSectionHiddens(SDF_Section arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSectionHiddens, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
/*{{{  SDF_OptLayout SDF_getSectionWsAfterExports(SDF_Section arg) */

SDF_OptLayout SDF_getSectionWsAfterExports(SDF_Section arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Section SDF_setSectionWsAfterExports(SDF_Section arg, SDF_OptLayout wsAfterExports) */

SDF_Section SDF_setSectionWsAfterExports(SDF_Section arg, SDF_OptLayout wsAfterExports)
{
  if (SDF_isSectionExports(arg)) {
    return (SDF_Section)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterExports, 1), 1);
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
    return (SDF_Grammar)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else 
    return (SDF_Grammar)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  SDF_Section SDF_setSectionGrammar(SDF_Section arg, SDF_Grammar Grammar) */

SDF_Section SDF_setSectionGrammar(SDF_Section arg, SDF_Grammar Grammar)
{
  if (SDF_isSectionExports(arg)) {
    return (SDF_Section)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Grammar, 2), 1);
  }
  else if (SDF_isSectionHiddens(arg)) {
    return (SDF_Section)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Grammar, 2), 1);
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
/*{{{  SDF_OptLayout SDF_getSectionWsAfterHiddens(SDF_Section arg) */

SDF_OptLayout SDF_getSectionWsAfterHiddens(SDF_Section arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Section SDF_setSectionWsAfterHiddens(SDF_Section arg, SDF_OptLayout wsAfterHiddens) */

SDF_Section SDF_setSectionWsAfterHiddens(SDF_Section arg, SDF_OptLayout wsAfterHiddens)
{
  if (SDF_isSectionHiddens(arg)) {
    return (SDF_Section)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterHiddens, 1), 1);
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
/*{{{  inline ATbool SDF_isSectionsDefault(SDF_Sections arg) */

inline ATbool SDF_isSectionsDefault(SDF_Sections arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternSectionsDefault, NULL));
#endif
  return ATtrue;
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
  
    return (SDF_SectionList)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  SDF_Sections SDF_setSectionsList(SDF_Sections arg, SDF_SectionList list) */

SDF_Sections SDF_setSectionsList(SDF_Sections arg, SDF_SectionList list)
{
  if (SDF_isSectionsDefault(arg)) {
    return (SDF_Sections)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)list, 1), 0), 1);
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
/*{{{  inline ATbool SDF_isSectionListEmpty(SDF_SectionList arg) */

inline ATbool SDF_isSectionListEmpty(SDF_SectionList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternSectionListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool SDF_isSectionListSingle(SDF_SectionList arg) */

inline ATbool SDF_isSectionListSingle(SDF_SectionList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSectionListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSectionListMany(SDF_SectionList arg) */

inline ATbool SDF_isSectionListMany(SDF_SectionList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSectionListMany, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
    return (SDF_Section)ATgetFirst((ATermList)arg);
  }
  else 
    return (SDF_Section)ATgetFirst((ATermList)arg);
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
/*{{{  SDF_OptLayout SDF_getSectionListWsAfterFirst(SDF_SectionList arg) */

SDF_OptLayout SDF_getSectionListWsAfterFirst(SDF_SectionList arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  SDF_SectionList SDF_setSectionListWsAfterFirst(SDF_SectionList arg, SDF_OptLayout wsAfterFirst) */

SDF_SectionList SDF_setSectionListWsAfterFirst(SDF_SectionList arg, SDF_OptLayout wsAfterFirst)
{
  if (SDF_isSectionListMany(arg)) {
    return (SDF_SectionList)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
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
  
    return (SDF_SectionList)ATgetTail((ATermList)arg, 2);
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
/*{{{  inline ATbool SDF_isModuleNameUnparameterized(SDF_ModuleName arg) */

inline ATbool SDF_isModuleNameUnparameterized(SDF_ModuleName arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternModuleNameUnparameterized, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isModuleNameParameterized(SDF_ModuleName arg) */

inline ATbool SDF_isModuleNameParameterized(SDF_ModuleName arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternModuleNameParameterized, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
    return (SDF_ModuleId)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (SDF_ModuleId)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_setModuleNameModuleId(SDF_ModuleName arg, SDF_ModuleId ModuleId) */

SDF_ModuleName SDF_setModuleNameModuleId(SDF_ModuleName arg, SDF_ModuleId ModuleId)
{
  if (SDF_isModuleNameUnparameterized(arg)) {
    return (SDF_ModuleName)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ModuleId, 0), 1);
  }
  else if (SDF_isModuleNameParameterized(arg)) {
    return (SDF_ModuleName)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ModuleId, 0), 1);
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
/*{{{  SDF_OptLayout SDF_getModuleNameWsAfterModuleId(SDF_ModuleName arg) */

SDF_OptLayout SDF_getModuleNameWsAfterModuleId(SDF_ModuleName arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_setModuleNameWsAfterModuleId(SDF_ModuleName arg, SDF_OptLayout wsAfterModuleId) */

SDF_ModuleName SDF_setModuleNameWsAfterModuleId(SDF_ModuleName arg, SDF_OptLayout wsAfterModuleId)
{
  if (SDF_isModuleNameParameterized(arg)) {
    return (SDF_ModuleName)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterModuleId, 1), 1);
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
/*{{{  SDF_OptLayout SDF_getModuleNameWsAfterBracketOpen(SDF_ModuleName arg) */

SDF_OptLayout SDF_getModuleNameWsAfterBracketOpen(SDF_ModuleName arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_setModuleNameWsAfterBracketOpen(SDF_ModuleName arg, SDF_OptLayout wsAfterBracketOpen) */

SDF_ModuleName SDF_setModuleNameWsAfterBracketOpen(SDF_ModuleName arg, SDF_OptLayout wsAfterBracketOpen)
{
  if (SDF_isModuleNameParameterized(arg)) {
    return (SDF_ModuleName)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBracketOpen, 3), 1);
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
  
    return (SDF_Symbols)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_setModuleNameParams(SDF_ModuleName arg, SDF_Symbols params) */

SDF_ModuleName SDF_setModuleNameParams(SDF_ModuleName arg, SDF_Symbols params)
{
  if (SDF_isModuleNameParameterized(arg)) {
    return (SDF_ModuleName)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)params, 4), 1);
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
/*{{{  SDF_OptLayout SDF_getModuleNameWsAfterParams(SDF_ModuleName arg) */

SDF_OptLayout SDF_getModuleNameWsAfterParams(SDF_ModuleName arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_setModuleNameWsAfterParams(SDF_ModuleName arg, SDF_OptLayout wsAfterParams) */

SDF_ModuleName SDF_setModuleNameWsAfterParams(SDF_ModuleName arg, SDF_OptLayout wsAfterParams)
{
  if (SDF_isModuleNameParameterized(arg)) {
    return (SDF_ModuleName)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParams, 5), 1);
  }

  ATabort("ModuleName has no WsAfterParams: %t\n", arg);
  return (SDF_ModuleName)NULL;
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
/*{{{  inline ATbool SDF_isImpSectionImports(SDF_ImpSection arg) */

inline ATbool SDF_isImpSectionImports(SDF_ImpSection arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternImpSectionImports, NULL, NULL));
#endif
  return ATtrue;
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
/*{{{  SDF_OptLayout SDF_getImpSectionWsAfterImports(SDF_ImpSection arg) */

SDF_OptLayout SDF_getImpSectionWsAfterImports(SDF_ImpSection arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_ImpSection SDF_setImpSectionWsAfterImports(SDF_ImpSection arg, SDF_OptLayout wsAfterImports) */

SDF_ImpSection SDF_setImpSectionWsAfterImports(SDF_ImpSection arg, SDF_OptLayout wsAfterImports)
{
  if (SDF_isImpSectionImports(arg)) {
    return (SDF_ImpSection)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterImports, 1), 1);
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
  
    return (SDF_Imports)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  SDF_ImpSection SDF_setImpSectionList(SDF_ImpSection arg, SDF_Imports list) */

SDF_ImpSection SDF_setImpSectionList(SDF_ImpSection arg, SDF_Imports list)
{
  if (SDF_isImpSectionImports(arg)) {
    return (SDF_ImpSection)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)list, 2), 1);
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
/*{{{  inline ATbool SDF_isImportsDefault(SDF_Imports arg) */

inline ATbool SDF_isImportsDefault(SDF_Imports arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternImportsDefault, NULL));
#endif
  return ATtrue;
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
  
    return (SDF_ImportList)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  SDF_Imports SDF_setImportsList(SDF_Imports arg, SDF_ImportList list) */

SDF_Imports SDF_setImportsList(SDF_Imports arg, SDF_ImportList list)
{
  if (SDF_isImportsDefault(arg)) {
    return (SDF_Imports)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)list, 1), 0), 1);
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
/*{{{  inline ATbool SDF_isImportListEmpty(SDF_ImportList arg) */

inline ATbool SDF_isImportListEmpty(SDF_ImportList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternImportListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool SDF_isImportListSingle(SDF_ImportList arg) */

inline ATbool SDF_isImportListSingle(SDF_ImportList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternImportListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isImportListMany(SDF_ImportList arg) */

inline ATbool SDF_isImportListMany(SDF_ImportList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternImportListMany, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
    return (SDF_Import)ATgetFirst((ATermList)arg);
  }
  else 
    return (SDF_Import)ATgetFirst((ATermList)arg);
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
/*{{{  SDF_OptLayout SDF_getImportListWsAfterFirst(SDF_ImportList arg) */

SDF_OptLayout SDF_getImportListWsAfterFirst(SDF_ImportList arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  SDF_ImportList SDF_setImportListWsAfterFirst(SDF_ImportList arg, SDF_OptLayout wsAfterFirst) */

SDF_ImportList SDF_setImportListWsAfterFirst(SDF_ImportList arg, SDF_OptLayout wsAfterFirst)
{
  if (SDF_isImportListMany(arg)) {
    return (SDF_ImportList)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
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
  
    return (SDF_ImportList)ATgetTail((ATermList)arg, 2);
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
/*{{{  inline ATbool SDF_isImportModule(SDF_Import arg) */

inline ATbool SDF_isImportModule(SDF_Import arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternImportModule, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isImportRenamedModule(SDF_Import arg) */

inline ATbool SDF_isImportRenamedModule(SDF_Import arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternImportRenamedModule, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isImportBracket(SDF_Import arg) */

inline ATbool SDF_isImportBracket(SDF_Import arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternImportBracket, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
    return (SDF_ModuleName)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (SDF_ModuleName)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Import SDF_setImportModuleName(SDF_Import arg, SDF_ModuleName ModuleName) */

SDF_Import SDF_setImportModuleName(SDF_Import arg, SDF_ModuleName ModuleName)
{
  if (SDF_isImportModule(arg)) {
    return (SDF_Import)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ModuleName, 0), 1);
  }
  else if (SDF_isImportRenamedModule(arg)) {
    return (SDF_Import)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ModuleName, 0), 1);
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
/*{{{  SDF_OptLayout SDF_getImportWsAfterModuleName(SDF_Import arg) */

SDF_OptLayout SDF_getImportWsAfterModuleName(SDF_Import arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Import SDF_setImportWsAfterModuleName(SDF_Import arg, SDF_OptLayout wsAfterModuleName) */

SDF_Import SDF_setImportWsAfterModuleName(SDF_Import arg, SDF_OptLayout wsAfterModuleName)
{
  if (SDF_isImportRenamedModule(arg)) {
    return (SDF_Import)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterModuleName, 1), 1);
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
  
    return (SDF_Renamings)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  SDF_Import SDF_setImportRenamings(SDF_Import arg, SDF_Renamings Renamings) */

SDF_Import SDF_setImportRenamings(SDF_Import arg, SDF_Renamings Renamings)
{
  if (SDF_isImportRenamedModule(arg)) {
    return (SDF_Import)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Renamings, 2), 1);
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
/*{{{  SDF_OptLayout SDF_getImportWsAfterParenOpen(SDF_Import arg) */

SDF_OptLayout SDF_getImportWsAfterParenOpen(SDF_Import arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Import SDF_setImportWsAfterParenOpen(SDF_Import arg, SDF_OptLayout wsAfterParenOpen) */

SDF_Import SDF_setImportWsAfterParenOpen(SDF_Import arg, SDF_OptLayout wsAfterParenOpen)
{
  if (SDF_isImportBracket(arg)) {
    return (SDF_Import)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 1), 1);
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
  
    return (SDF_Import)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  SDF_Import SDF_setImportImport(SDF_Import arg, SDF_Import Import) */

SDF_Import SDF_setImportImport(SDF_Import arg, SDF_Import Import)
{
  if (SDF_isImportBracket(arg)) {
    return (SDF_Import)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Import, 2), 1);
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
/*{{{  SDF_OptLayout SDF_getImportWsAfterImport(SDF_Import arg) */

SDF_OptLayout SDF_getImportWsAfterImport(SDF_Import arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Import SDF_setImportWsAfterImport(SDF_Import arg, SDF_OptLayout wsAfterImport) */

SDF_Import SDF_setImportWsAfterImport(SDF_Import arg, SDF_OptLayout wsAfterImport)
{
  if (SDF_isImportBracket(arg)) {
    return (SDF_Import)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterImport, 3), 1);
  }

  ATabort("Import has no WsAfterImport: %t\n", arg);
  return (SDF_Import)NULL;
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
/*{{{  inline ATbool SDF_isSymbolsDefault(SDF_Symbols arg) */

inline ATbool SDF_isSymbolsDefault(SDF_Symbols arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternSymbolsDefault, NULL));
#endif
  return ATtrue;
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
  
    return (SDF_SymbolList)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  SDF_Symbols SDF_setSymbolsList(SDF_Symbols arg, SDF_SymbolList list) */

SDF_Symbols SDF_setSymbolsList(SDF_Symbols arg, SDF_SymbolList list)
{
  if (SDF_isSymbolsDefault(arg)) {
    return (SDF_Symbols)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)list, 1), 0), 1);
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
/*{{{  inline ATbool SDF_isSymbolListEmpty(SDF_SymbolList arg) */

inline ATbool SDF_isSymbolListEmpty(SDF_SymbolList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternSymbolListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolListSingle(SDF_SymbolList arg) */

inline ATbool SDF_isSymbolListSingle(SDF_SymbolList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isSymbolListMany(SDF_SymbolList arg) */

inline ATbool SDF_isSymbolListMany(SDF_SymbolList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternSymbolListMany, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
    return (SDF_Symbol)ATgetFirst((ATermList)arg);
  }
  else 
    return (SDF_Symbol)ATgetFirst((ATermList)arg);
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
/*{{{  SDF_OptLayout SDF_getSymbolListWsAfterFirst(SDF_SymbolList arg) */

SDF_OptLayout SDF_getSymbolListWsAfterFirst(SDF_SymbolList arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  SDF_SymbolList SDF_setSymbolListWsAfterFirst(SDF_SymbolList arg, SDF_OptLayout wsAfterFirst) */

SDF_SymbolList SDF_setSymbolListWsAfterFirst(SDF_SymbolList arg, SDF_OptLayout wsAfterFirst)
{
  if (SDF_isSymbolListMany(arg)) {
    return (SDF_SymbolList)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
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
  
    return (SDF_SymbolList)ATgetTail((ATermList)arg, 2);
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
/*{{{  inline ATbool SDF_isOptExpPresent(SDF_OptExp arg) */

inline ATbool SDF_isOptExpPresent(SDF_OptExp arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternOptExpPresent, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isOptExpAbsent(SDF_OptExp arg) */

inline ATbool SDF_isOptExpAbsent(SDF_OptExp arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternOptExpAbsent);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
/*{{{  SDF_OptLayout SDF_getOptExpWsAfterE(SDF_OptExp arg) */

SDF_OptLayout SDF_getOptExpWsAfterE(SDF_OptExp arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_OptExp SDF_setOptExpWsAfterE(SDF_OptExp arg, SDF_OptLayout wsAfterE) */

SDF_OptExp SDF_setOptExpWsAfterE(SDF_OptExp arg, SDF_OptLayout wsAfterE)
{
  if (SDF_isOptExpPresent(arg)) {
    return (SDF_OptExp)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterE, 1), 1);
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
  
    return (SDF_IntCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  SDF_OptExp SDF_setOptExpIntCon(SDF_OptExp arg, SDF_IntCon IntCon) */

SDF_OptExp SDF_setOptExpIntCon(SDF_OptExp arg, SDF_IntCon IntCon)
{
  if (SDF_isOptExpPresent(arg)) {
    return (SDF_OptExp)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)IntCon, 2), 1);
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
/*{{{  inline ATbool SDF_isRealConRealCon(SDF_RealCon arg) */

inline ATbool SDF_isRealConRealCon(SDF_RealCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternRealConRealCon, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
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
  
    return (SDF_IntCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_RealCon SDF_setRealConIntCon(SDF_RealCon arg, SDF_IntCon IntCon) */

SDF_RealCon SDF_setRealConIntCon(SDF_RealCon arg, SDF_IntCon IntCon)
{
  if (SDF_isRealConRealCon(arg)) {
    return (SDF_RealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)IntCon, 0), 1);
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
/*{{{  SDF_OptLayout SDF_getRealConWsAfterIntCon(SDF_RealCon arg) */

SDF_OptLayout SDF_getRealConWsAfterIntCon(SDF_RealCon arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_RealCon SDF_setRealConWsAfterIntCon(SDF_RealCon arg, SDF_OptLayout wsAfterIntCon) */

SDF_RealCon SDF_setRealConWsAfterIntCon(SDF_RealCon arg, SDF_OptLayout wsAfterIntCon)
{
  if (SDF_isRealConRealCon(arg)) {
    return (SDF_RealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterIntCon, 1), 1);
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
/*{{{  SDF_OptLayout SDF_getRealConWsAfterPeriod(SDF_RealCon arg) */

SDF_OptLayout SDF_getRealConWsAfterPeriod(SDF_RealCon arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_RealCon SDF_setRealConWsAfterPeriod(SDF_RealCon arg, SDF_OptLayout wsAfterPeriod) */

SDF_RealCon SDF_setRealConWsAfterPeriod(SDF_RealCon arg, SDF_OptLayout wsAfterPeriod)
{
  if (SDF_isRealConRealCon(arg)) {
    return (SDF_RealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterPeriod, 3), 1);
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
  
    return (SDF_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  SDF_RealCon SDF_setRealConNatCon(SDF_RealCon arg, SDF_NatCon NatCon) */

SDF_RealCon SDF_setRealConNatCon(SDF_RealCon arg, SDF_NatCon NatCon)
{
  if (SDF_isRealConRealCon(arg)) {
    return (SDF_RealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)NatCon, 4), 1);
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
/*{{{  SDF_OptLayout SDF_getRealConWsAfterNatCon(SDF_RealCon arg) */

SDF_OptLayout SDF_getRealConWsAfterNatCon(SDF_RealCon arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  SDF_RealCon SDF_setRealConWsAfterNatCon(SDF_RealCon arg, SDF_OptLayout wsAfterNatCon) */

SDF_RealCon SDF_setRealConWsAfterNatCon(SDF_RealCon arg, SDF_OptLayout wsAfterNatCon)
{
  if (SDF_isRealConRealCon(arg)) {
    return (SDF_RealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterNatCon, 5), 1);
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
  
    return (SDF_OptExp)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
}

/*}}}  */
/*{{{  SDF_RealCon SDF_setRealConOptExp(SDF_RealCon arg, SDF_OptExp OptExp) */

SDF_RealCon SDF_setRealConOptExp(SDF_RealCon arg, SDF_OptExp OptExp)
{
  if (SDF_isRealConRealCon(arg)) {
    return (SDF_RealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)OptExp, 6), 1);
  }

  ATabort("RealCon has no OptExp: %t\n", arg);
  return (SDF_RealCon)NULL;
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
/*{{{  inline ATbool SDF_isNatConDigits(SDF_NatCon arg) */

inline ATbool SDF_isNatConDigits(SDF_NatCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternNatConDigits, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool SDF_hasNatConChars(SDF_NatCon arg) */

ATbool SDF_hasNatConChars(SDF_NatCon arg)
{
  if (SDF_isNatConDigits(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_CHARLIST SDF_getNatConChars(SDF_NatCon arg) */

SDF_CHARLIST SDF_getNatConChars(SDF_NatCon arg)
{
  
    return (SDF_CHARLIST)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  SDF_NatCon SDF_setNatConChars(SDF_NatCon arg, SDF_CHARLIST chars) */

SDF_NatCon SDF_setNatConChars(SDF_NatCon arg, SDF_CHARLIST chars)
{
  if (SDF_isNatConDigits(arg)) {
    return (SDF_NatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)chars, 1), 0), 1);
  }

  ATabort("NatCon has no Chars: %t\n", arg);
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
/*{{{  inline ATbool SDF_isIntConNatural(SDF_IntCon arg) */

inline ATbool SDF_isIntConNatural(SDF_IntCon arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternIntConNatural, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isIntConPositive(SDF_IntCon arg) */

inline ATbool SDF_isIntConPositive(SDF_IntCon arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternIntConPositive, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isIntConNegative(SDF_IntCon arg) */

inline ATbool SDF_isIntConNegative(SDF_IntCon arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternIntConNegative, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
    return (SDF_NatCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isIntConPositive(arg)) {
    return (SDF_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else 
    return (SDF_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  SDF_IntCon SDF_setIntConNatCon(SDF_IntCon arg, SDF_NatCon NatCon) */

SDF_IntCon SDF_setIntConNatCon(SDF_IntCon arg, SDF_NatCon NatCon)
{
  if (SDF_isIntConNatural(arg)) {
    return (SDF_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)NatCon, 0), 1);
  }
  else if (SDF_isIntConPositive(arg)) {
    return (SDF_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)NatCon, 2), 1);
  }
  else if (SDF_isIntConNegative(arg)) {
    return (SDF_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)NatCon, 2), 1);
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
/*{{{  SDF_OptLayout SDF_getIntConWsAfterPos(SDF_IntCon arg) */

SDF_OptLayout SDF_getIntConWsAfterPos(SDF_IntCon arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_IntCon SDF_setIntConWsAfterPos(SDF_IntCon arg, SDF_OptLayout wsAfterPos) */

SDF_IntCon SDF_setIntConWsAfterPos(SDF_IntCon arg, SDF_OptLayout wsAfterPos)
{
  if (SDF_isIntConPositive(arg)) {
    return (SDF_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterPos, 1), 1);
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
/*{{{  SDF_OptLayout SDF_getIntConWsAfterNeg(SDF_IntCon arg) */

SDF_OptLayout SDF_getIntConWsAfterNeg(SDF_IntCon arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_IntCon SDF_setIntConWsAfterNeg(SDF_IntCon arg, SDF_OptLayout wsAfterNeg) */

SDF_IntCon SDF_setIntConWsAfterNeg(SDF_IntCon arg, SDF_OptLayout wsAfterNeg)
{
  if (SDF_isIntConNegative(arg)) {
    return (SDF_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterNeg, 1), 1);
  }

  ATabort("IntCon has no WsAfterNeg: %t\n", arg);
  return (SDF_IntCon)NULL;
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
/*{{{  inline ATbool SDF_isAlphaNumericalEscCharDefault(SDF_AlphaNumericalEscChar arg) */

inline ATbool SDF_isAlphaNumericalEscCharDefault(SDF_AlphaNumericalEscChar arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternAlphaNumericalEscCharDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool SDF_hasAlphaNumericalEscCharChars(SDF_AlphaNumericalEscChar arg) */

ATbool SDF_hasAlphaNumericalEscCharChars(SDF_AlphaNumericalEscChar arg)
{
  if (SDF_isAlphaNumericalEscCharDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_CHARLIST SDF_getAlphaNumericalEscCharChars(SDF_AlphaNumericalEscChar arg) */

SDF_CHARLIST SDF_getAlphaNumericalEscCharChars(SDF_AlphaNumericalEscChar arg)
{
  
    return (SDF_CHARLIST)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  SDF_AlphaNumericalEscChar SDF_setAlphaNumericalEscCharChars(SDF_AlphaNumericalEscChar arg, SDF_CHARLIST chars) */

SDF_AlphaNumericalEscChar SDF_setAlphaNumericalEscCharChars(SDF_AlphaNumericalEscChar arg, SDF_CHARLIST chars)
{
  if (SDF_isAlphaNumericalEscCharDefault(arg)) {
    return (SDF_AlphaNumericalEscChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)chars, 1), 0), 1);
  }

  ATabort("AlphaNumericalEscChar has no Chars: %t\n", arg);
  return (SDF_AlphaNumericalEscChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_DecimalEscChar accessors */

/*{{{  ATbool SDF_isValidDecimalEscChar(SDF_DecimalEscChar arg) */

ATbool SDF_isValidDecimalEscChar(SDF_DecimalEscChar arg)
{
  if (SDF_isDecimalEscCharDec0Underscore199(arg)) {
    return ATtrue;
  }
  else if (SDF_isDecimalEscCharDec200Underscore249(arg)) {
    return ATtrue;
  }
  else if (SDF_isDecimalEscCharDec250Underscore255(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SDF_isDecimalEscCharDec0Underscore199(SDF_DecimalEscChar arg) */

inline ATbool SDF_isDecimalEscCharDec0Underscore199(SDF_DecimalEscChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternDecimalEscCharDec0Underscore199, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isDecimalEscCharDec200Underscore249(SDF_DecimalEscChar arg) */

inline ATbool SDF_isDecimalEscCharDec200Underscore249(SDF_DecimalEscChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternDecimalEscCharDec200Underscore249, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isDecimalEscCharDec250Underscore255(SDF_DecimalEscChar arg) */

inline ATbool SDF_isDecimalEscCharDec250Underscore255(SDF_DecimalEscChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternDecimalEscCharDec250Underscore255, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool SDF_hasDecimalEscCharChars(SDF_DecimalEscChar arg) */

ATbool SDF_hasDecimalEscCharChars(SDF_DecimalEscChar arg)
{
  if (SDF_isDecimalEscCharDec0Underscore199(arg)) {
    return ATtrue;
  }
  else if (SDF_isDecimalEscCharDec200Underscore249(arg)) {
    return ATtrue;
  }
  else if (SDF_isDecimalEscCharDec250Underscore255(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_CHARLIST SDF_getDecimalEscCharChars(SDF_DecimalEscChar arg) */

SDF_CHARLIST SDF_getDecimalEscCharChars(SDF_DecimalEscChar arg)
{
  if (SDF_isDecimalEscCharDec0Underscore199(arg)) {
    return (SDF_CHARLIST)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
  }
  else if (SDF_isDecimalEscCharDec200Underscore249(arg)) {
    return (SDF_CHARLIST)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
  }
  else 
    return (SDF_CHARLIST)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  SDF_DecimalEscChar SDF_setDecimalEscCharChars(SDF_DecimalEscChar arg, SDF_CHARLIST chars) */

SDF_DecimalEscChar SDF_setDecimalEscCharChars(SDF_DecimalEscChar arg, SDF_CHARLIST chars)
{
  if (SDF_isDecimalEscCharDec0Underscore199(arg)) {
    return (SDF_DecimalEscChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)chars, 1), 0), 1);
  }
  else if (SDF_isDecimalEscCharDec200Underscore249(arg)) {
    return (SDF_DecimalEscChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)chars, 1), 0), 1);
  }
  else if (SDF_isDecimalEscCharDec250Underscore255(arg)) {
    return (SDF_DecimalEscChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)chars, 1), 0), 1);
  }

  ATabort("DecimalEscChar has no Chars: %t\n", arg);
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
/*{{{  inline ATbool SDF_isEscCharAlphaNumeric(SDF_EscChar arg) */

inline ATbool SDF_isEscCharAlphaNumeric(SDF_EscChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternEscCharAlphaNumeric, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isEscCharDecimal(SDF_EscChar arg) */

inline ATbool SDF_isEscCharDecimal(SDF_EscChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternEscCharDecimal, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool SDF_hasEscCharChars(SDF_EscChar arg) */

ATbool SDF_hasEscCharChars(SDF_EscChar arg)
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
/*{{{  SDF_CHARLIST SDF_getEscCharChars(SDF_EscChar arg) */

SDF_CHARLIST SDF_getEscCharChars(SDF_EscChar arg)
{
  if (SDF_isEscCharAlphaNumeric(arg)) {
    return (SDF_CHARLIST)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
  }
  else 
    return (SDF_CHARLIST)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  SDF_EscChar SDF_setEscCharChars(SDF_EscChar arg, SDF_CHARLIST chars) */

SDF_EscChar SDF_setEscCharChars(SDF_EscChar arg, SDF_CHARLIST chars)
{
  if (SDF_isEscCharAlphaNumeric(arg)) {
    return (SDF_EscChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)chars, 1), 0), 1);
  }
  else if (SDF_isEscCharDecimal(arg)) {
    return (SDF_EscChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)chars, 1), 0), 1);
  }

  ATabort("EscChar has no Chars: %t\n", arg);
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
/*{{{  inline ATbool SDF_isLCharNormal(SDF_LChar arg) */

inline ATbool SDF_isLCharNormal(SDF_LChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternLCharNormal, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isLCharEscaped(SDF_LChar arg) */

inline ATbool SDF_isLCharEscaped(SDF_LChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternLCharEscaped, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool SDF_hasLCharChars(SDF_LChar arg) */

ATbool SDF_hasLCharChars(SDF_LChar arg)
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
/*{{{  SDF_CHARLIST SDF_getLCharChars(SDF_LChar arg) */

SDF_CHARLIST SDF_getLCharChars(SDF_LChar arg)
{
  if (SDF_isLCharNormal(arg)) {
    return (SDF_CHARLIST)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
  }
  else 
    return (SDF_CHARLIST)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  SDF_LChar SDF_setLCharChars(SDF_LChar arg, SDF_CHARLIST chars) */

SDF_LChar SDF_setLCharChars(SDF_LChar arg, SDF_CHARLIST chars)
{
  if (SDF_isLCharNormal(arg)) {
    return (SDF_LChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)chars, 1), 0), 1);
  }
  else if (SDF_isLCharEscaped(arg)) {
    return (SDF_LChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)chars, 1), 0), 1);
  }

  ATabort("LChar has no Chars: %t\n", arg);
  return (SDF_LChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_QLiteral accessors */

/*{{{  ATbool SDF_isValidQLiteral(SDF_QLiteral arg) */

ATbool SDF_isValidQLiteral(SDF_QLiteral arg)
{
  if (SDF_isQLiteralQuoted(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SDF_isQLiteralQuoted(SDF_QLiteral arg) */

inline ATbool SDF_isQLiteralQuoted(SDF_QLiteral arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternQLiteralQuoted, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool SDF_hasQLiteralChars(SDF_QLiteral arg) */

ATbool SDF_hasQLiteralChars(SDF_QLiteral arg)
{
  if (SDF_isQLiteralQuoted(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_CHARLIST SDF_getQLiteralChars(SDF_QLiteral arg) */

SDF_CHARLIST SDF_getQLiteralChars(SDF_QLiteral arg)
{
  
    return (SDF_CHARLIST)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  SDF_QLiteral SDF_setQLiteralChars(SDF_QLiteral arg, SDF_CHARLIST chars) */

SDF_QLiteral SDF_setQLiteralChars(SDF_QLiteral arg, SDF_CHARLIST chars)
{
  if (SDF_isQLiteralQuoted(arg)) {
    return (SDF_QLiteral)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)chars, 1), 0), 1);
  }

  ATabort("QLiteral has no Chars: %t\n", arg);
  return (SDF_QLiteral)NULL;
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
/*{{{  inline ATbool SDF_isUQLiteralOneChar(SDF_UQLiteral arg) */

inline ATbool SDF_isUQLiteralOneChar(SDF_UQLiteral arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternUQLiteralOneChar, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isUQLiteralMoreChars(SDF_UQLiteral arg) */

inline ATbool SDF_isUQLiteralMoreChars(SDF_UQLiteral arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternUQLiteralMoreChars, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool SDF_hasUQLiteralChars(SDF_UQLiteral arg) */

ATbool SDF_hasUQLiteralChars(SDF_UQLiteral arg)
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
/*{{{  SDF_CHARLIST SDF_getUQLiteralChars(SDF_UQLiteral arg) */

SDF_CHARLIST SDF_getUQLiteralChars(SDF_UQLiteral arg)
{
  if (SDF_isUQLiteralOneChar(arg)) {
    return (SDF_CHARLIST)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
  }
  else 
    return (SDF_CHARLIST)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  SDF_UQLiteral SDF_setUQLiteralChars(SDF_UQLiteral arg, SDF_CHARLIST chars) */

SDF_UQLiteral SDF_setUQLiteralChars(SDF_UQLiteral arg, SDF_CHARLIST chars)
{
  if (SDF_isUQLiteralOneChar(arg)) {
    return (SDF_UQLiteral)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)chars, 1), 0), 1);
  }
  else if (SDF_isUQLiteralMoreChars(arg)) {
    return (SDF_UQLiteral)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)chars, 1), 0), 1);
  }

  ATabort("UQLiteral has no Chars: %t\n", arg);
  return (SDF_UQLiteral)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Literal accessors */

/*{{{  ATbool SDF_isValidLiteral(SDF_Literal arg) */

ATbool SDF_isValidLiteral(SDF_Literal arg)
{
  if (SDF_isLiteralQlit(arg)) {
    return ATtrue;
  }
  else if (SDF_isLiteralUqlit(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SDF_isLiteralQlit(SDF_Literal arg) */

inline ATbool SDF_isLiteralQlit(SDF_Literal arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternLiteralQlit, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isLiteralUqlit(SDF_Literal arg) */

inline ATbool SDF_isLiteralUqlit(SDF_Literal arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternLiteralUqlit, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool SDF_hasLiteralQLiteral(SDF_Literal arg) */

ATbool SDF_hasLiteralQLiteral(SDF_Literal arg)
{
  if (SDF_isLiteralQlit(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_QLiteral SDF_getLiteralQLiteral(SDF_Literal arg) */

SDF_QLiteral SDF_getLiteralQLiteral(SDF_Literal arg)
{
  
    return (SDF_QLiteral)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Literal SDF_setLiteralQLiteral(SDF_Literal arg, SDF_QLiteral QLiteral) */

SDF_Literal SDF_setLiteralQLiteral(SDF_Literal arg, SDF_QLiteral QLiteral)
{
  if (SDF_isLiteralQlit(arg)) {
    return (SDF_Literal)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)QLiteral, 0), 1);
  }

  ATabort("Literal has no QLiteral: %t\n", arg);
  return (SDF_Literal)NULL;
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
  
    return (SDF_UQLiteral)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Literal SDF_setLiteralUQLiteral(SDF_Literal arg, SDF_UQLiteral UQLiteral) */

SDF_Literal SDF_setLiteralUQLiteral(SDF_Literal arg, SDF_UQLiteral UQLiteral)
{
  if (SDF_isLiteralUqlit(arg)) {
    return (SDF_Literal)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)UQLiteral, 0), 1);
  }

  ATabort("Literal has no UQLiteral: %t\n", arg);
  return (SDF_Literal)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ATermList accessors */

/*{{{  ATbool SDF_isValidATermList(SDF_ATermList arg) */

ATbool SDF_isValidATermList(SDF_ATermList arg)
{
  if (SDF_isATermListNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SDF_isATermListNotEmpty(SDF_ATermList arg) */

inline ATbool SDF_isATermListNotEmpty(SDF_ATermList arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternATermListNotEmpty, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermListWsAfterBracketOpen(SDF_ATermList arg) */

ATbool SDF_hasATermListWsAfterBracketOpen(SDF_ATermList arg)
{
  if (SDF_isATermListNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getATermListWsAfterBracketOpen(SDF_ATermList arg) */

SDF_OptLayout SDF_getATermListWsAfterBracketOpen(SDF_ATermList arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_ATermList SDF_setATermListWsAfterBracketOpen(SDF_ATermList arg, SDF_OptLayout wsAfterBracketOpen) */

SDF_ATermList SDF_setATermListWsAfterBracketOpen(SDF_ATermList arg, SDF_OptLayout wsAfterBracketOpen)
{
  if (SDF_isATermListNotEmpty(arg)) {
    return (SDF_ATermList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBracketOpen, 1), 1);
  }

  ATabort("ATermList has no WsAfterBracketOpen: %t\n", arg);
  return (SDF_ATermList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermListElems(SDF_ATermList arg) */

ATbool SDF_hasATermListElems(SDF_ATermList arg)
{
  if (SDF_isATermListNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ATermElems SDF_getATermListElems(SDF_ATermList arg) */

SDF_ATermElems SDF_getATermListElems(SDF_ATermList arg)
{
  
    return (SDF_ATermElems)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
}

/*}}}  */
/*{{{  SDF_ATermList SDF_setATermListElems(SDF_ATermList arg, SDF_ATermElems elems) */

SDF_ATermList SDF_setATermListElems(SDF_ATermList arg, SDF_ATermElems elems)
{
  if (SDF_isATermListNotEmpty(arg)) {
    return (SDF_ATermList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)elems, 1), 2), 1);
  }

  ATabort("ATermList has no Elems: %t\n", arg);
  return (SDF_ATermList)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermListWsAfterElems(SDF_ATermList arg) */

ATbool SDF_hasATermListWsAfterElems(SDF_ATermList arg)
{
  if (SDF_isATermListNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getATermListWsAfterElems(SDF_ATermList arg) */

SDF_OptLayout SDF_getATermListWsAfterElems(SDF_ATermList arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_ATermList SDF_setATermListWsAfterElems(SDF_ATermList arg, SDF_OptLayout wsAfterElems) */

SDF_ATermList SDF_setATermListWsAfterElems(SDF_ATermList arg, SDF_OptLayout wsAfterElems)
{
  if (SDF_isATermListNotEmpty(arg)) {
    return (SDF_ATermList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterElems, 3), 1);
  }

  ATabort("ATermList has no WsAfterElems: %t\n", arg);
  return (SDF_ATermList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ATermElems accessors */

/*{{{  ATbool SDF_isValidATermElems(SDF_ATermElems arg) */

ATbool SDF_isValidATermElems(SDF_ATermElems arg)
{
  if (SDF_isATermElemsEmpty(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermElemsSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SDF_isATermElemsEmpty(SDF_ATermElems arg) */

inline ATbool SDF_isATermElemsEmpty(SDF_ATermElems arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternATermElemsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool SDF_isATermElemsSingle(SDF_ATermElems arg) */

inline ATbool SDF_isATermElemsSingle(SDF_ATermElems arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternATermElemsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isATermElemsMany(SDF_ATermElems arg) */

inline ATbool SDF_isATermElemsMany(SDF_ATermElems arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternATermElemsMany, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool SDF_hasATermElemsHead(SDF_ATermElems arg) */

ATbool SDF_hasATermElemsHead(SDF_ATermElems arg)
{
  if (SDF_isATermElemsSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_getATermElemsHead(SDF_ATermElems arg) */

SDF_ATerm SDF_getATermElemsHead(SDF_ATermElems arg)
{
  if (SDF_isATermElemsSingle(arg)) {
    return (SDF_ATerm)ATgetFirst((ATermList)arg);
  }
  else 
    return (SDF_ATerm)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  SDF_ATermElems SDF_setATermElemsHead(SDF_ATermElems arg, SDF_ATerm head) */

SDF_ATermElems SDF_setATermElemsHead(SDF_ATermElems arg, SDF_ATerm head)
{
  if (SDF_isATermElemsSingle(arg)) {
    return (SDF_ATermElems)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isATermElemsMany(arg)) {
    return (SDF_ATermElems)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("ATermElems has no Head: %t\n", arg);
  return (SDF_ATermElems)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermElemsWsAfterFirst(SDF_ATermElems arg) */

ATbool SDF_hasATermElemsWsAfterFirst(SDF_ATermElems arg)
{
  if (SDF_isATermElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getATermElemsWsAfterFirst(SDF_ATermElems arg) */

SDF_OptLayout SDF_getATermElemsWsAfterFirst(SDF_ATermElems arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  SDF_ATermElems SDF_setATermElemsWsAfterFirst(SDF_ATermElems arg, SDF_OptLayout wsAfterFirst) */

SDF_ATermElems SDF_setATermElemsWsAfterFirst(SDF_ATermElems arg, SDF_OptLayout wsAfterFirst)
{
  if (SDF_isATermElemsMany(arg)) {
    return (SDF_ATermElems)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
  }

  ATabort("ATermElems has no WsAfterFirst: %t\n", arg);
  return (SDF_ATermElems)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermElemsSep(SDF_ATermElems arg) */

ATbool SDF_hasATermElemsSep(SDF_ATermElems arg)
{
  if (SDF_isATermElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getATermElemsSep(SDF_ATermElems arg) */

char * SDF_getATermElemsSep(SDF_ATermElems arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
}

/*}}}  */
/*{{{  SDF_ATermElems SDF_setATermElemsSep(SDF_ATermElems arg, char * sep) */

SDF_ATermElems SDF_setATermElemsSep(SDF_ATermElems arg, char * sep)
{
  if (SDF_isATermElemsMany(arg)) {
    return (SDF_ATermElems)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("ATermElems has no Sep: %t\n", arg);
  return (SDF_ATermElems)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermElemsWsAfterSep(SDF_ATermElems arg) */

ATbool SDF_hasATermElemsWsAfterSep(SDF_ATermElems arg)
{
  if (SDF_isATermElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getATermElemsWsAfterSep(SDF_ATermElems arg) */

SDF_OptLayout SDF_getATermElemsWsAfterSep(SDF_ATermElems arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  SDF_ATermElems SDF_setATermElemsWsAfterSep(SDF_ATermElems arg, SDF_OptLayout wsAfterSep) */

SDF_ATermElems SDF_setATermElemsWsAfterSep(SDF_ATermElems arg, SDF_OptLayout wsAfterSep)
{
  if (SDF_isATermElemsMany(arg)) {
    return (SDF_ATermElems)ATreplace((ATermList)arg, (ATerm)wsAfterSep, 3);
  }

  ATabort("ATermElems has no WsAfterSep: %t\n", arg);
  return (SDF_ATermElems)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermElemsTail(SDF_ATermElems arg) */

ATbool SDF_hasATermElemsTail(SDF_ATermElems arg)
{
  if (SDF_isATermElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ATermElems SDF_getATermElemsTail(SDF_ATermElems arg) */

SDF_ATermElems SDF_getATermElemsTail(SDF_ATermElems arg)
{
  
    return (SDF_ATermElems)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  SDF_ATermElems SDF_setATermElemsTail(SDF_ATermElems arg, SDF_ATermElems tail) */

SDF_ATermElems SDF_setATermElemsTail(SDF_ATermElems arg, SDF_ATermElems tail)
{
  if (SDF_isATermElemsMany(arg)) {
    return (SDF_ATermElems)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("ATermElems has no Tail: %t\n", arg);
  return (SDF_ATermElems)NULL;
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
/*{{{  inline ATbool SDF_isAConInt(SDF_ACon arg) */

inline ATbool SDF_isAConInt(SDF_ACon arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternAConInt, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isAConReal(SDF_ACon arg) */

inline ATbool SDF_isAConReal(SDF_ACon arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternAConReal, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
  
    return (SDF_IntCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_ACon SDF_setAConIntCon(SDF_ACon arg, SDF_IntCon IntCon) */

SDF_ACon SDF_setAConIntCon(SDF_ACon arg, SDF_IntCon IntCon)
{
  if (SDF_isAConInt(arg)) {
    return (SDF_ACon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)IntCon, 0), 1);
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
  
    return (SDF_RealCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_ACon SDF_setAConRealCon(SDF_ACon arg, SDF_RealCon RealCon) */

SDF_ACon SDF_setAConRealCon(SDF_ACon arg, SDF_RealCon RealCon)
{
  if (SDF_isAConReal(arg)) {
    return (SDF_ACon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)RealCon, 0), 1);
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
/*{{{  inline ATbool SDF_isAFunDefault(SDF_AFun arg) */

inline ATbool SDF_isAFunDefault(SDF_AFun arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternAFunDefault, NULL));
#endif
  return ATtrue;
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
  
    return (SDF_Literal)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_AFun SDF_setAFunLiteral(SDF_AFun arg, SDF_Literal Literal) */

SDF_AFun SDF_setAFunLiteral(SDF_AFun arg, SDF_Literal Literal)
{
  if (SDF_isAFunDefault(arg)) {
    return (SDF_AFun)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Literal, 0), 1);
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
/*{{{  inline ATbool SDF_isATermConstant(SDF_ATerm arg) */

inline ATbool SDF_isATermConstant(SDF_ATerm arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternATermConstant, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isATermList(SDF_ATerm arg) */

inline ATbool SDF_isATermList(SDF_ATerm arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternATermList, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isATermFun(SDF_ATerm arg) */

inline ATbool SDF_isATermFun(SDF_ATerm arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternATermFun, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isATermAppl(SDF_ATerm arg) */

inline ATbool SDF_isATermAppl(SDF_ATerm arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternATermAppl, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isATermAnnotatedConstant(SDF_ATerm arg) */

inline ATbool SDF_isATermAnnotatedConstant(SDF_ATerm arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternATermAnnotatedConstant, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isATermAnnotatedList(SDF_ATerm arg) */

inline ATbool SDF_isATermAnnotatedList(SDF_ATerm arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternATermAnnotatedList, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isATermAnnotatedFun(SDF_ATerm arg) */

inline ATbool SDF_isATermAnnotatedFun(SDF_ATerm arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternATermAnnotatedFun, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isATermAnnotatedAppl(SDF_ATerm arg) */

inline ATbool SDF_isATermAnnotatedAppl(SDF_ATerm arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternATermAnnotatedAppl, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
    return (SDF_ACon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (SDF_ACon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermACon(SDF_ATerm arg, SDF_ACon ACon) */

SDF_ATerm SDF_setATermACon(SDF_ATerm arg, SDF_ACon ACon)
{
  if (SDF_isATermConstant(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ACon, 0), 1);
  }
  else if (SDF_isATermAnnotatedConstant(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ACon, 0), 1);
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
    return (SDF_ATermList)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (SDF_ATermList)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermList(SDF_ATerm arg, SDF_ATermList list) */

SDF_ATerm SDF_setATermList(SDF_ATerm arg, SDF_ATermList list)
{
  if (SDF_isATermList(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)list, 0), 1);
  }
  else if (SDF_isATermAnnotatedList(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)list, 0), 1);
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
    return (SDF_AFun)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isATermAppl(arg)) {
    return (SDF_AFun)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isATermAnnotatedFun(arg)) {
    return (SDF_AFun)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (SDF_AFun)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermFun(SDF_ATerm arg, SDF_AFun fun) */

SDF_ATerm SDF_setATermFun(SDF_ATerm arg, SDF_AFun fun)
{
  if (SDF_isATermFun(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)fun, 0), 1);
  }
  else if (SDF_isATermAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)fun, 0), 1);
  }
  else if (SDF_isATermAnnotatedFun(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)fun, 0), 1);
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)fun, 0), 1);
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
/*{{{  SDF_OptLayout SDF_getATermWsAfterFun(SDF_ATerm arg) */

SDF_OptLayout SDF_getATermWsAfterFun(SDF_ATerm arg)
{
  if (SDF_isATermAppl(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (SDF_isATermAnnotatedFun(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermWsAfterFun(SDF_ATerm arg, SDF_OptLayout wsAfterFun) */

SDF_ATerm SDF_setATermWsAfterFun(SDF_ATerm arg, SDF_OptLayout wsAfterFun)
{
  if (SDF_isATermAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterFun, 1), 1);
  }
  else if (SDF_isATermAnnotatedFun(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterFun, 1), 1);
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterFun, 1), 1);
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
/*{{{  SDF_OptLayout SDF_getATermWsAfterParenOpen(SDF_ATerm arg) */

SDF_OptLayout SDF_getATermWsAfterParenOpen(SDF_ATerm arg)
{
  if (SDF_isATermAppl(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermWsAfterParenOpen(SDF_ATerm arg, SDF_OptLayout wsAfterParenOpen) */

SDF_ATerm SDF_setATermWsAfterParenOpen(SDF_ATerm arg, SDF_OptLayout wsAfterParenOpen)
{
  if (SDF_isATermAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
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
/*{{{  SDF_ATermArgs SDF_getATermArgs(SDF_ATerm arg) */

SDF_ATermArgs SDF_getATermArgs(SDF_ATerm arg)
{
  if (SDF_isATermAppl(arg)) {
    return (SDF_ATermArgs)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 1);
  }
  else 
    return (SDF_ATermArgs)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 1);
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermArgs(SDF_ATerm arg, SDF_ATermArgs args) */

SDF_ATerm SDF_setATermArgs(SDF_ATerm arg, SDF_ATermArgs args)
{
  if (SDF_isATermAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)args, 1), 4), 1);
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)args, 1), 4), 1);
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
/*{{{  SDF_OptLayout SDF_getATermWsAfterArgs(SDF_ATerm arg) */

SDF_OptLayout SDF_getATermWsAfterArgs(SDF_ATerm arg)
{
  if (SDF_isATermAppl(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermWsAfterArgs(SDF_ATerm arg, SDF_OptLayout wsAfterArgs) */

SDF_ATerm SDF_setATermWsAfterArgs(SDF_ATerm arg, SDF_OptLayout wsAfterArgs)
{
  if (SDF_isATermAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterArgs, 5), 1);
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterArgs, 5), 1);
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
/*{{{  SDF_OptLayout SDF_getATermWsAfterACon(SDF_ATerm arg) */

SDF_OptLayout SDF_getATermWsAfterACon(SDF_ATerm arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermWsAfterACon(SDF_ATerm arg, SDF_OptLayout wsAfterACon) */

SDF_ATerm SDF_setATermWsAfterACon(SDF_ATerm arg, SDF_OptLayout wsAfterACon)
{
  if (SDF_isATermAnnotatedConstant(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterACon, 1), 1);
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
    return (SDF_Ann)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else if (SDF_isATermAnnotatedList(arg)) {
    return (SDF_Ann)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else if (SDF_isATermAnnotatedFun(arg)) {
    return (SDF_Ann)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else 
    return (SDF_Ann)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermAnn(SDF_ATerm arg, SDF_Ann Ann) */

SDF_ATerm SDF_setATermAnn(SDF_ATerm arg, SDF_Ann Ann)
{
  if (SDF_isATermAnnotatedConstant(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Ann, 2), 1);
  }
  else if (SDF_isATermAnnotatedList(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Ann, 2), 1);
  }
  else if (SDF_isATermAnnotatedFun(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Ann, 2), 1);
  }
  else if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Ann, 8), 1);
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
/*{{{  SDF_OptLayout SDF_getATermWsAfterList(SDF_ATerm arg) */

SDF_OptLayout SDF_getATermWsAfterList(SDF_ATerm arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermWsAfterList(SDF_ATerm arg, SDF_OptLayout wsAfterList) */

SDF_ATerm SDF_setATermWsAfterList(SDF_ATerm arg, SDF_OptLayout wsAfterList)
{
  if (SDF_isATermAnnotatedList(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterList, 1), 1);
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
/*{{{  SDF_OptLayout SDF_getATermWsAfterParenClose(SDF_ATerm arg) */

SDF_OptLayout SDF_getATermWsAfterParenClose(SDF_ATerm arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  SDF_ATerm SDF_setATermWsAfterParenClose(SDF_ATerm arg, SDF_OptLayout wsAfterParenClose) */

SDF_ATerm SDF_setATermWsAfterParenClose(SDF_ATerm arg, SDF_OptLayout wsAfterParenClose)
{
  if (SDF_isATermAnnotatedAppl(arg)) {
    return (SDF_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenClose, 7), 1);
  }

  ATabort("ATerm has no WsAfterParenClose: %t\n", arg);
  return (SDF_ATerm)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ATermArgs accessors */

/*{{{  ATbool SDF_isValidATermArgs(SDF_ATermArgs arg) */

ATbool SDF_isValidATermArgs(SDF_ATermArgs arg)
{
  if (SDF_isATermArgsSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SDF_isATermArgsSingle(SDF_ATermArgs arg) */

inline ATbool SDF_isATermArgsSingle(SDF_ATermArgs arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternATermArgsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isATermArgsMany(SDF_ATermArgs arg) */

inline ATbool SDF_isATermArgsMany(SDF_ATermArgs arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternATermArgsMany, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool SDF_hasATermArgsHead(SDF_ATermArgs arg) */

ATbool SDF_hasATermArgsHead(SDF_ATermArgs arg)
{
  if (SDF_isATermArgsSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_getATermArgsHead(SDF_ATermArgs arg) */

SDF_ATerm SDF_getATermArgsHead(SDF_ATermArgs arg)
{
  if (SDF_isATermArgsSingle(arg)) {
    return (SDF_ATerm)ATgetFirst((ATermList)arg);
  }
  else 
    return (SDF_ATerm)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  SDF_ATermArgs SDF_setATermArgsHead(SDF_ATermArgs arg, SDF_ATerm head) */

SDF_ATermArgs SDF_setATermArgsHead(SDF_ATermArgs arg, SDF_ATerm head)
{
  if (SDF_isATermArgsSingle(arg)) {
    return (SDF_ATermArgs)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isATermArgsMany(arg)) {
    return (SDF_ATermArgs)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("ATermArgs has no Head: %t\n", arg);
  return (SDF_ATermArgs)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermArgsWsAfterFirst(SDF_ATermArgs arg) */

ATbool SDF_hasATermArgsWsAfterFirst(SDF_ATermArgs arg)
{
  if (SDF_isATermArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getATermArgsWsAfterFirst(SDF_ATermArgs arg) */

SDF_OptLayout SDF_getATermArgsWsAfterFirst(SDF_ATermArgs arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  SDF_ATermArgs SDF_setATermArgsWsAfterFirst(SDF_ATermArgs arg, SDF_OptLayout wsAfterFirst) */

SDF_ATermArgs SDF_setATermArgsWsAfterFirst(SDF_ATermArgs arg, SDF_OptLayout wsAfterFirst)
{
  if (SDF_isATermArgsMany(arg)) {
    return (SDF_ATermArgs)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
  }

  ATabort("ATermArgs has no WsAfterFirst: %t\n", arg);
  return (SDF_ATermArgs)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermArgsSep(SDF_ATermArgs arg) */

ATbool SDF_hasATermArgsSep(SDF_ATermArgs arg)
{
  if (SDF_isATermArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getATermArgsSep(SDF_ATermArgs arg) */

char * SDF_getATermArgsSep(SDF_ATermArgs arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
}

/*}}}  */
/*{{{  SDF_ATermArgs SDF_setATermArgsSep(SDF_ATermArgs arg, char * sep) */

SDF_ATermArgs SDF_setATermArgsSep(SDF_ATermArgs arg, char * sep)
{
  if (SDF_isATermArgsMany(arg)) {
    return (SDF_ATermArgs)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("ATermArgs has no Sep: %t\n", arg);
  return (SDF_ATermArgs)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermArgsWsAfterSep(SDF_ATermArgs arg) */

ATbool SDF_hasATermArgsWsAfterSep(SDF_ATermArgs arg)
{
  if (SDF_isATermArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getATermArgsWsAfterSep(SDF_ATermArgs arg) */

SDF_OptLayout SDF_getATermArgsWsAfterSep(SDF_ATermArgs arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  SDF_ATermArgs SDF_setATermArgsWsAfterSep(SDF_ATermArgs arg, SDF_OptLayout wsAfterSep) */

SDF_ATermArgs SDF_setATermArgsWsAfterSep(SDF_ATermArgs arg, SDF_OptLayout wsAfterSep)
{
  if (SDF_isATermArgsMany(arg)) {
    return (SDF_ATermArgs)ATreplace((ATermList)arg, (ATerm)wsAfterSep, 3);
  }

  ATabort("ATermArgs has no WsAfterSep: %t\n", arg);
  return (SDF_ATermArgs)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermArgsTail(SDF_ATermArgs arg) */

ATbool SDF_hasATermArgsTail(SDF_ATermArgs arg)
{
  if (SDF_isATermArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ATermArgs SDF_getATermArgsTail(SDF_ATermArgs arg) */

SDF_ATermArgs SDF_getATermArgsTail(SDF_ATermArgs arg)
{
  
    return (SDF_ATermArgs)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  SDF_ATermArgs SDF_setATermArgsTail(SDF_ATermArgs arg, SDF_ATermArgs tail) */

SDF_ATermArgs SDF_setATermArgsTail(SDF_ATermArgs arg, SDF_ATermArgs tail)
{
  if (SDF_isATermArgsMany(arg)) {
    return (SDF_ATermArgs)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("ATermArgs has no Tail: %t\n", arg);
  return (SDF_ATermArgs)NULL;
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
/*{{{  inline ATbool SDF_isAnnAnnotation(SDF_Ann arg) */

inline ATbool SDF_isAnnAnnotation(SDF_Ann arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternAnnAnnotation, NULL, NULL, NULL));
#endif
  return ATtrue;
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
/*{{{  SDF_OptLayout SDF_getAnnWsAfterBraceOpen(SDF_Ann arg) */

SDF_OptLayout SDF_getAnnWsAfterBraceOpen(SDF_Ann arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Ann SDF_setAnnWsAfterBraceOpen(SDF_Ann arg, SDF_OptLayout wsAfterBraceOpen) */

SDF_Ann SDF_setAnnWsAfterBraceOpen(SDF_Ann arg, SDF_OptLayout wsAfterBraceOpen)
{
  if (SDF_isAnnAnnotation(arg)) {
    return (SDF_Ann)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBraceOpen, 1), 1);
  }

  ATabort("Ann has no WsAfterBraceOpen: %t\n", arg);
  return (SDF_Ann)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAnnAnnos(SDF_Ann arg) */

ATbool SDF_hasAnnAnnos(SDF_Ann arg)
{
  if (SDF_isAnnAnnotation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ATermAnnos SDF_getAnnAnnos(SDF_Ann arg) */

SDF_ATermAnnos SDF_getAnnAnnos(SDF_Ann arg)
{
  
    return (SDF_ATermAnnos)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
}

/*}}}  */
/*{{{  SDF_Ann SDF_setAnnAnnos(SDF_Ann arg, SDF_ATermAnnos annos) */

SDF_Ann SDF_setAnnAnnos(SDF_Ann arg, SDF_ATermAnnos annos)
{
  if (SDF_isAnnAnnotation(arg)) {
    return (SDF_Ann)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)annos, 1), 2), 1);
  }

  ATabort("Ann has no Annos: %t\n", arg);
  return (SDF_Ann)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasAnnWsAfterAnnos(SDF_Ann arg) */

ATbool SDF_hasAnnWsAfterAnnos(SDF_Ann arg)
{
  if (SDF_isAnnAnnotation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getAnnWsAfterAnnos(SDF_Ann arg) */

SDF_OptLayout SDF_getAnnWsAfterAnnos(SDF_Ann arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Ann SDF_setAnnWsAfterAnnos(SDF_Ann arg, SDF_OptLayout wsAfterAnnos) */

SDF_Ann SDF_setAnnWsAfterAnnos(SDF_Ann arg, SDF_OptLayout wsAfterAnnos)
{
  if (SDF_isAnnAnnotation(arg)) {
    return (SDF_Ann)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterAnnos, 3), 1);
  }

  ATabort("Ann has no WsAfterAnnos: %t\n", arg);
  return (SDF_Ann)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_ATermAnnos accessors */

/*{{{  ATbool SDF_isValidATermAnnos(SDF_ATermAnnos arg) */

ATbool SDF_isValidATermAnnos(SDF_ATermAnnos arg)
{
  if (SDF_isATermAnnosSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermAnnosMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SDF_isATermAnnosSingle(SDF_ATermAnnos arg) */

inline ATbool SDF_isATermAnnosSingle(SDF_ATermAnnos arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternATermAnnosSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isATermAnnosMany(SDF_ATermAnnos arg) */

inline ATbool SDF_isATermAnnosMany(SDF_ATermAnnos arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternATermAnnosMany, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool SDF_hasATermAnnosHead(SDF_ATermAnnos arg) */

ATbool SDF_hasATermAnnosHead(SDF_ATermAnnos arg)
{
  if (SDF_isATermAnnosSingle(arg)) {
    return ATtrue;
  }
  else if (SDF_isATermAnnosMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_getATermAnnosHead(SDF_ATermAnnos arg) */

SDF_ATerm SDF_getATermAnnosHead(SDF_ATermAnnos arg)
{
  if (SDF_isATermAnnosSingle(arg)) {
    return (SDF_ATerm)ATgetFirst((ATermList)arg);
  }
  else 
    return (SDF_ATerm)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  SDF_ATermAnnos SDF_setATermAnnosHead(SDF_ATermAnnos arg, SDF_ATerm head) */

SDF_ATermAnnos SDF_setATermAnnosHead(SDF_ATermAnnos arg, SDF_ATerm head)
{
  if (SDF_isATermAnnosSingle(arg)) {
    return (SDF_ATermAnnos)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (SDF_isATermAnnosMany(arg)) {
    return (SDF_ATermAnnos)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("ATermAnnos has no Head: %t\n", arg);
  return (SDF_ATermAnnos)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermAnnosWsAfterFirst(SDF_ATermAnnos arg) */

ATbool SDF_hasATermAnnosWsAfterFirst(SDF_ATermAnnos arg)
{
  if (SDF_isATermAnnosMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getATermAnnosWsAfterFirst(SDF_ATermAnnos arg) */

SDF_OptLayout SDF_getATermAnnosWsAfterFirst(SDF_ATermAnnos arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  SDF_ATermAnnos SDF_setATermAnnosWsAfterFirst(SDF_ATermAnnos arg, SDF_OptLayout wsAfterFirst) */

SDF_ATermAnnos SDF_setATermAnnosWsAfterFirst(SDF_ATermAnnos arg, SDF_OptLayout wsAfterFirst)
{
  if (SDF_isATermAnnosMany(arg)) {
    return (SDF_ATermAnnos)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
  }

  ATabort("ATermAnnos has no WsAfterFirst: %t\n", arg);
  return (SDF_ATermAnnos)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermAnnosSep(SDF_ATermAnnos arg) */

ATbool SDF_hasATermAnnosSep(SDF_ATermAnnos arg)
{
  if (SDF_isATermAnnosMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SDF_getATermAnnosSep(SDF_ATermAnnos arg) */

char * SDF_getATermAnnosSep(SDF_ATermAnnos arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
}

/*}}}  */
/*{{{  SDF_ATermAnnos SDF_setATermAnnosSep(SDF_ATermAnnos arg, char * sep) */

SDF_ATermAnnos SDF_setATermAnnosSep(SDF_ATermAnnos arg, char * sep)
{
  if (SDF_isATermAnnosMany(arg)) {
    return (SDF_ATermAnnos)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("ATermAnnos has no Sep: %t\n", arg);
  return (SDF_ATermAnnos)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermAnnosWsAfterSep(SDF_ATermAnnos arg) */

ATbool SDF_hasATermAnnosWsAfterSep(SDF_ATermAnnos arg)
{
  if (SDF_isATermAnnosMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getATermAnnosWsAfterSep(SDF_ATermAnnos arg) */

SDF_OptLayout SDF_getATermAnnosWsAfterSep(SDF_ATermAnnos arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  SDF_ATermAnnos SDF_setATermAnnosWsAfterSep(SDF_ATermAnnos arg, SDF_OptLayout wsAfterSep) */

SDF_ATermAnnos SDF_setATermAnnosWsAfterSep(SDF_ATermAnnos arg, SDF_OptLayout wsAfterSep)
{
  if (SDF_isATermAnnosMany(arg)) {
    return (SDF_ATermAnnos)ATreplace((ATermList)arg, (ATerm)wsAfterSep, 3);
  }

  ATabort("ATermAnnos has no WsAfterSep: %t\n", arg);
  return (SDF_ATermAnnos)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasATermAnnosTail(SDF_ATermAnnos arg) */

ATbool SDF_hasATermAnnosTail(SDF_ATermAnnos arg)
{
  if (SDF_isATermAnnosMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ATermAnnos SDF_getATermAnnosTail(SDF_ATermAnnos arg) */

SDF_ATermAnnos SDF_getATermAnnosTail(SDF_ATermAnnos arg)
{
  
    return (SDF_ATermAnnos)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  SDF_ATermAnnos SDF_setATermAnnosTail(SDF_ATermAnnos arg, SDF_ATermAnnos tail) */

SDF_ATermAnnos SDF_setATermAnnosTail(SDF_ATermAnnos arg, SDF_ATermAnnos tail)
{
  if (SDF_isATermAnnosMany(arg)) {
    return (SDF_ATermAnnos)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("ATermAnnos has no Tail: %t\n", arg);
  return (SDF_ATermAnnos)NULL;
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
/*{{{  inline ATbool SDF_isAttributesAttrs(SDF_Attributes arg) */

inline ATbool SDF_isAttributesAttrs(SDF_Attributes arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternAttributesAttrs, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isAttributesNoAttrs(SDF_Attributes arg) */

inline ATbool SDF_isAttributesNoAttrs(SDF_Attributes arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternAttributesNoAttrs);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
/*{{{  SDF_OptLayout SDF_getAttributesWsAfterBraceOpen(SDF_Attributes arg) */

SDF_OptLayout SDF_getAttributesWsAfterBraceOpen(SDF_Attributes arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_Attributes SDF_setAttributesWsAfterBraceOpen(SDF_Attributes arg, SDF_OptLayout wsAfterBraceOpen) */

SDF_Attributes SDF_setAttributesWsAfterBraceOpen(SDF_Attributes arg, SDF_OptLayout wsAfterBraceOpen)
{
  if (SDF_isAttributesAttrs(arg)) {
    return (SDF_Attributes)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBraceOpen, 1), 1);
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
  
    return (SDF_AttributeList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
}

/*}}}  */
/*{{{  SDF_Attributes SDF_setAttributesList(SDF_Attributes arg, SDF_AttributeList list) */

SDF_Attributes SDF_setAttributesList(SDF_Attributes arg, SDF_AttributeList list)
{
  if (SDF_isAttributesAttrs(arg)) {
    return (SDF_Attributes)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)list, 1), 2), 1);
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
/*{{{  SDF_OptLayout SDF_getAttributesWsAfterList(SDF_Attributes arg) */

SDF_OptLayout SDF_getAttributesWsAfterList(SDF_Attributes arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  SDF_Attributes SDF_setAttributesWsAfterList(SDF_Attributes arg, SDF_OptLayout wsAfterList) */

SDF_Attributes SDF_setAttributesWsAfterList(SDF_Attributes arg, SDF_OptLayout wsAfterList)
{
  if (SDF_isAttributesAttrs(arg)) {
    return (SDF_Attributes)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterList, 3), 1);
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
/*{{{  inline ATbool SDF_isAttributeListEmpty(SDF_AttributeList arg) */

inline ATbool SDF_isAttributeListEmpty(SDF_AttributeList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternAttributeListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool SDF_isAttributeListSingle(SDF_AttributeList arg) */

inline ATbool SDF_isAttributeListSingle(SDF_AttributeList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternAttributeListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isAttributeListMany(SDF_AttributeList arg) */

inline ATbool SDF_isAttributeListMany(SDF_AttributeList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternAttributeListMany, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
    return (SDF_Attribute)ATgetFirst((ATermList)arg);
  }
  else 
    return (SDF_Attribute)ATgetFirst((ATermList)arg);
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
/*{{{  SDF_OptLayout SDF_getAttributeListWsAfterFirst(SDF_AttributeList arg) */

SDF_OptLayout SDF_getAttributeListWsAfterFirst(SDF_AttributeList arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  SDF_AttributeList SDF_setAttributeListWsAfterFirst(SDF_AttributeList arg, SDF_OptLayout wsAfterFirst) */

SDF_AttributeList SDF_setAttributeListWsAfterFirst(SDF_AttributeList arg, SDF_OptLayout wsAfterFirst)
{
  if (SDF_isAttributeListMany(arg)) {
    return (SDF_AttributeList)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
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
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
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
/*{{{  SDF_OptLayout SDF_getAttributeListWsAfterSep(SDF_AttributeList arg) */

SDF_OptLayout SDF_getAttributeListWsAfterSep(SDF_AttributeList arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  SDF_AttributeList SDF_setAttributeListWsAfterSep(SDF_AttributeList arg, SDF_OptLayout wsAfterSep) */

SDF_AttributeList SDF_setAttributeListWsAfterSep(SDF_AttributeList arg, SDF_OptLayout wsAfterSep)
{
  if (SDF_isAttributeListMany(arg)) {
    return (SDF_AttributeList)ATreplace((ATermList)arg, (ATerm)wsAfterSep, 3);
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
  
    return (SDF_AttributeList)ATgetTail((ATermList)arg, 4);
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
/*{{{  inline ATbool SDF_isProductionsDefault(SDF_Productions arg) */

inline ATbool SDF_isProductionsDefault(SDF_Productions arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternProductionsDefault, NULL));
#endif
  return ATtrue;
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
  
    return (SDF_ProductionList)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  SDF_Productions SDF_setProductionsList(SDF_Productions arg, SDF_ProductionList list) */

SDF_Productions SDF_setProductionsList(SDF_Productions arg, SDF_ProductionList list)
{
  if (SDF_isProductionsDefault(arg)) {
    return (SDF_Productions)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)list, 1), 0), 1);
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
/*{{{  inline ATbool SDF_isProductionListEmpty(SDF_ProductionList arg) */

inline ATbool SDF_isProductionListEmpty(SDF_ProductionList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternProductionListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool SDF_isProductionListSingle(SDF_ProductionList arg) */

inline ATbool SDF_isProductionListSingle(SDF_ProductionList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternProductionListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isProductionListMany(SDF_ProductionList arg) */

inline ATbool SDF_isProductionListMany(SDF_ProductionList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternProductionListMany, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
    return (SDF_Production)ATgetFirst((ATermList)arg);
  }
  else 
    return (SDF_Production)ATgetFirst((ATermList)arg);
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
/*{{{  SDF_OptLayout SDF_getProductionListWsAfterFirst(SDF_ProductionList arg) */

SDF_OptLayout SDF_getProductionListWsAfterFirst(SDF_ProductionList arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  SDF_ProductionList SDF_setProductionListWsAfterFirst(SDF_ProductionList arg, SDF_OptLayout wsAfterFirst) */

SDF_ProductionList SDF_setProductionListWsAfterFirst(SDF_ProductionList arg, SDF_OptLayout wsAfterFirst)
{
  if (SDF_isProductionListMany(arg)) {
    return (SDF_ProductionList)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
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
  
    return (SDF_ProductionList)ATgetTail((ATermList)arg, 2);
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
/*{{{  inline ATbool SDF_isSDFDefinition(SDF_SDF arg) */

inline ATbool SDF_isSDFDefinition(SDF_SDF arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SDF_patternSDFDefinition, NULL, NULL));
#endif
  return ATtrue;
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
/*{{{  SDF_OptLayout SDF_getSDFWsAfterDefinition(SDF_SDF arg) */

SDF_OptLayout SDF_getSDFWsAfterDefinition(SDF_SDF arg)
{
  
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  SDF_SDF SDF_setSDFWsAfterDefinition(SDF_SDF arg, SDF_OptLayout wsAfterDefinition) */

SDF_SDF SDF_setSDFWsAfterDefinition(SDF_SDF arg, SDF_OptLayout wsAfterDefinition)
{
  if (SDF_isSDFDefinition(arg)) {
    return (SDF_SDF)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterDefinition, 1), 1);
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
  
    return (SDF_Definition)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  SDF_SDF SDF_setSDFDefinition(SDF_SDF arg, SDF_Definition Definition) */

SDF_SDF SDF_setSDFDefinition(SDF_SDF arg, SDF_Definition Definition)
{
  if (SDF_isSDFDefinition(arg)) {
    return (SDF_SDF)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Definition, 2), 1);
  }

  ATabort("SDF has no Definition: %t\n", arg);
  return (SDF_SDF)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_OptLayout accessors */

/*{{{  ATbool SDF_isValidOptLayout(SDF_OptLayout arg) */

ATbool SDF_isValidOptLayout(SDF_OptLayout arg)
{
  if (SDF_isOptLayoutAbsent(arg)) {
    return ATtrue;
  }
  else if (SDF_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SDF_isOptLayoutAbsent(SDF_OptLayout arg) */

inline ATbool SDF_isOptLayoutAbsent(SDF_OptLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternOptLayoutAbsent);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isOptLayoutPresent(SDF_OptLayout arg) */

inline ATbool SDF_isOptLayoutPresent(SDF_OptLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternOptLayoutPresent, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool SDF_hasOptLayoutChars(SDF_OptLayout arg) */

ATbool SDF_hasOptLayoutChars(SDF_OptLayout arg)
{
  if (SDF_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_CHARLIST SDF_getOptLayoutChars(SDF_OptLayout arg) */

SDF_CHARLIST SDF_getOptLayoutChars(SDF_OptLayout arg)
{
  
    return (SDF_CHARLIST)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_setOptLayoutChars(SDF_OptLayout arg, SDF_CHARLIST chars) */

SDF_OptLayout SDF_setOptLayoutChars(SDF_OptLayout arg, SDF_CHARLIST chars)
{
  if (SDF_isOptLayoutPresent(arg)) {
    return (SDF_OptLayout)ATsetArgument((ATermAppl)arg, (ATerm)chars, 1);
  }

  ATabort("OptLayout has no Chars: %t\n", arg);
  return (SDF_OptLayout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SDF_Start accessors */

/*{{{  ATbool SDF_isValidStart(SDF_Start arg) */

ATbool SDF_isValidStart(SDF_Start arg)
{
  if (SDF_isStartSDF(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartProductions(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartProduction(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAttributes(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAttribute(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAnn(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartATerm(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAFun(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartACon(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartATermList(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartQLiteral(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartUQLiteral(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartLiteral(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartIntCon(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartNatCon(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartRealCon(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartOptExp(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartSymbols(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartSymbol(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartGrammar(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartImpSection(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartDefinition(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartModule(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartSections(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartSection(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartImports(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartImport(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartModuleName(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartModuleId(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartRenamings(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartRenaming(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartPriorities(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartPriority(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartGroup(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAssociativity(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartCharClass(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartShortChar(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartNumChar(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartCharacter(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartSort(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartRestriction(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartLookaheads(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartLookahead(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAliases(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAlias(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartSDF(SDF_Start arg) */

inline ATbool SDF_isStartSDF(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartSDF, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartProductions(SDF_Start arg) */

inline ATbool SDF_isStartProductions(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartProductions, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartProduction(SDF_Start arg) */

inline ATbool SDF_isStartProduction(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartProduction, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartAttributes(SDF_Start arg) */

inline ATbool SDF_isStartAttributes(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartAttributes, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartAttribute(SDF_Start arg) */

inline ATbool SDF_isStartAttribute(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartAttribute, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartAnn(SDF_Start arg) */

inline ATbool SDF_isStartAnn(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartAnn, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartATerm(SDF_Start arg) */

inline ATbool SDF_isStartATerm(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartATerm, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartAFun(SDF_Start arg) */

inline ATbool SDF_isStartAFun(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartAFun, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartACon(SDF_Start arg) */

inline ATbool SDF_isStartACon(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartACon, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartATermList(SDF_Start arg) */

inline ATbool SDF_isStartATermList(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartATermList, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartQLiteral(SDF_Start arg) */

inline ATbool SDF_isStartQLiteral(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartQLiteral, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartUQLiteral(SDF_Start arg) */

inline ATbool SDF_isStartUQLiteral(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartUQLiteral, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartLiteral(SDF_Start arg) */

inline ATbool SDF_isStartLiteral(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartLiteral, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartIntCon(SDF_Start arg) */

inline ATbool SDF_isStartIntCon(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartIntCon, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartNatCon(SDF_Start arg) */

inline ATbool SDF_isStartNatCon(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartNatCon, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartRealCon(SDF_Start arg) */

inline ATbool SDF_isStartRealCon(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartRealCon, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartOptExp(SDF_Start arg) */

inline ATbool SDF_isStartOptExp(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartOptExp, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartSymbols(SDF_Start arg) */

inline ATbool SDF_isStartSymbols(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartSymbols, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartSymbol(SDF_Start arg) */

inline ATbool SDF_isStartSymbol(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartSymbol, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartGrammar(SDF_Start arg) */

inline ATbool SDF_isStartGrammar(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartGrammar, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartImpSection(SDF_Start arg) */

inline ATbool SDF_isStartImpSection(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartImpSection, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartDefinition(SDF_Start arg) */

inline ATbool SDF_isStartDefinition(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartDefinition, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartModule(SDF_Start arg) */

inline ATbool SDF_isStartModule(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartModule, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartSections(SDF_Start arg) */

inline ATbool SDF_isStartSections(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartSections, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartSection(SDF_Start arg) */

inline ATbool SDF_isStartSection(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartSection, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartImports(SDF_Start arg) */

inline ATbool SDF_isStartImports(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartImports, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartImport(SDF_Start arg) */

inline ATbool SDF_isStartImport(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartImport, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartModuleName(SDF_Start arg) */

inline ATbool SDF_isStartModuleName(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartModuleName, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartModuleId(SDF_Start arg) */

inline ATbool SDF_isStartModuleId(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartModuleId, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartRenamings(SDF_Start arg) */

inline ATbool SDF_isStartRenamings(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartRenamings, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartRenaming(SDF_Start arg) */

inline ATbool SDF_isStartRenaming(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartRenaming, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartPriorities(SDF_Start arg) */

inline ATbool SDF_isStartPriorities(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartPriorities, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartPriority(SDF_Start arg) */

inline ATbool SDF_isStartPriority(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartPriority, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartGroup(SDF_Start arg) */

inline ATbool SDF_isStartGroup(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartGroup, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartAssociativity(SDF_Start arg) */

inline ATbool SDF_isStartAssociativity(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartAssociativity, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartCharClass(SDF_Start arg) */

inline ATbool SDF_isStartCharClass(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartCharClass, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartShortChar(SDF_Start arg) */

inline ATbool SDF_isStartShortChar(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartShortChar, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartNumChar(SDF_Start arg) */

inline ATbool SDF_isStartNumChar(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartNumChar, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartCharacter(SDF_Start arg) */

inline ATbool SDF_isStartCharacter(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartCharacter, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartSort(SDF_Start arg) */

inline ATbool SDF_isStartSort(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartSort, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartRestrictions(SDF_Start arg) */

inline ATbool SDF_isStartRestrictions(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartRestrictions, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartRestriction(SDF_Start arg) */

inline ATbool SDF_isStartRestriction(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartRestriction, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartLookaheads(SDF_Start arg) */

inline ATbool SDF_isStartLookaheads(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartLookaheads, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartLookahead(SDF_Start arg) */

inline ATbool SDF_isStartLookahead(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartLookahead, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartAliases(SDF_Start arg) */

inline ATbool SDF_isStartAliases(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartAliases, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SDF_isStartAlias(SDF_Start arg) */

inline ATbool SDF_isStartAlias(SDF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SDF_patternStartAlias, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool SDF_hasStartWsBefore(SDF_Start arg) */

ATbool SDF_hasStartWsBefore(SDF_Start arg)
{
  if (SDF_isStartSDF(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartProductions(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartProduction(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAttributes(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAttribute(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAnn(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartATerm(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAFun(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartACon(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartATermList(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartQLiteral(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartUQLiteral(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartLiteral(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartIntCon(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartNatCon(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartRealCon(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartOptExp(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartSymbols(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartSymbol(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartGrammar(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartImpSection(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartDefinition(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartModule(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartSections(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartSection(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartImports(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartImport(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartModuleName(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartModuleId(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartRenamings(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartRenaming(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartPriorities(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartPriority(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartGroup(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAssociativity(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartCharClass(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartShortChar(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartNumChar(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartCharacter(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartSort(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartRestriction(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartLookaheads(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartLookahead(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAliases(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAlias(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getStartWsBefore(SDF_Start arg) */

SDF_OptLayout SDF_getStartWsBefore(SDF_Start arg)
{
  if (SDF_isStartSDF(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartProductions(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartProduction(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartAttributes(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartAttribute(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartAnn(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartATerm(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartAFun(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartACon(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartATermList(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartQLiteral(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartUQLiteral(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartLiteral(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartIntCon(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartNatCon(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartRealCon(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartOptExp(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartSymbols(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartSymbol(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartGrammar(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartImpSection(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartDefinition(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartModule(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartSections(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartSection(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartImports(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartImport(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartModuleName(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartModuleId(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartRenamings(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartRenaming(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartPriorities(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartPriority(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartGroup(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartAssociativity(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartCharClass(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartShortChar(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartNumChar(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartCharacter(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartSort(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartRestrictions(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartRestriction(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartLookaheads(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartLookahead(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (SDF_isStartAliases(arg)) {
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else 
    return (SDF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartWsBefore(SDF_Start arg, SDF_OptLayout wsBefore) */

SDF_Start SDF_setStartWsBefore(SDF_Start arg, SDF_OptLayout wsBefore)
{
  if (SDF_isStartSDF(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartProductions(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartProduction(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartAttributes(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartAttribute(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartAnn(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartATerm(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartAFun(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartACon(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartATermList(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartQLiteral(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartUQLiteral(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartLiteral(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartIntCon(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartNatCon(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartRealCon(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartOptExp(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartSymbols(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartSymbol(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartGrammar(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartImpSection(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartDefinition(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartModule(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartSections(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartSection(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartImports(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartImport(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartModuleName(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartModuleId(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartRenamings(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartRenaming(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartPriorities(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartPriority(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartGroup(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartAssociativity(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartCharClass(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartShortChar(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartNumChar(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartCharacter(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartSort(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartRestrictions(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartRestriction(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartLookaheads(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartLookahead(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartAliases(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (SDF_isStartAlias(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }

  ATabort("Start has no WsBefore: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopSDF(SDF_Start arg) */

ATbool SDF_hasStartTopSDF(SDF_Start arg)
{
  if (SDF_isStartSDF(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_SDF SDF_getStartTopSDF(SDF_Start arg) */

SDF_SDF SDF_getStartTopSDF(SDF_Start arg)
{
  
    return (SDF_SDF)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopSDF(SDF_Start arg, SDF_SDF topSDF) */

SDF_Start SDF_setStartTopSDF(SDF_Start arg, SDF_SDF topSDF)
{
  if (SDF_isStartSDF(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topSDF, 1), 1), 0);
  }

  ATabort("Start has no TopSDF: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartWsAfter(SDF_Start arg) */

ATbool SDF_hasStartWsAfter(SDF_Start arg)
{
  if (SDF_isStartSDF(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartProductions(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartProduction(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAttributes(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAttribute(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAnn(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartATerm(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAFun(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartACon(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartATermList(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartQLiteral(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartUQLiteral(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartLiteral(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartIntCon(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartNatCon(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartRealCon(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartOptExp(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartSymbols(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartSymbol(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartGrammar(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartImpSection(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartDefinition(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartModule(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartSections(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartSection(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartImports(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartImport(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartModuleName(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartModuleId(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartRenamings(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartRenaming(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartPriorities(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartPriority(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartGroup(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAssociativity(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartCharClass(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartShortChar(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartNumChar(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartCharacter(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartSort(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartRestriction(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartLookaheads(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartLookahead(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAliases(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAlias(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_getStartWsAfter(SDF_Start arg) */

SDF_OptLayout SDF_getStartWsAfter(SDF_Start arg)
{
  if (SDF_isStartSDF(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartProductions(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartProduction(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartAttributes(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartAttribute(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartAnn(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartATerm(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartAFun(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartACon(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartATermList(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartQLiteral(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartUQLiteral(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartLiteral(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartIntCon(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartNatCon(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartRealCon(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartOptExp(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartSymbols(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartSymbol(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartGrammar(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartImpSection(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartDefinition(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartModule(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartSections(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartSection(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartImports(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartImport(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartModuleName(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartModuleId(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartRenamings(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartRenaming(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartPriorities(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartPriority(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartGroup(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartAssociativity(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartCharClass(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartShortChar(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartNumChar(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartCharacter(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartSort(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartRestrictions(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartRestriction(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartLookaheads(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartLookahead(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (SDF_isStartAliases(arg)) {
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else 
    return (SDF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartWsAfter(SDF_Start arg, SDF_OptLayout wsAfter) */

SDF_Start SDF_setStartWsAfter(SDF_Start arg, SDF_OptLayout wsAfter)
{
  if (SDF_isStartSDF(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartProductions(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartProduction(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartAttributes(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartAttribute(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartAnn(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartATerm(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartAFun(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartACon(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartATermList(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartQLiteral(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartUQLiteral(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartLiteral(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartIntCon(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartNatCon(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartRealCon(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartOptExp(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartSymbols(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartSymbol(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartGrammar(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartImpSection(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartDefinition(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartModule(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartSections(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartSection(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartImports(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartImport(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartModuleName(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartModuleId(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartRenamings(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartRenaming(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartPriorities(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartPriority(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartGroup(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartAssociativity(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartCharClass(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartShortChar(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartNumChar(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartCharacter(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartSort(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartRestrictions(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartRestriction(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartLookaheads(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartLookahead(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartAliases(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (SDF_isStartAlias(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }

  ATabort("Start has no WsAfter: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartAmbCnt(SDF_Start arg) */

ATbool SDF_hasStartAmbCnt(SDF_Start arg)
{
  if (SDF_isStartSDF(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartProductions(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartProduction(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAttributes(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAttribute(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAnn(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartATerm(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAFun(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartACon(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartATermList(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartQLiteral(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartUQLiteral(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartLiteral(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartIntCon(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartNatCon(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartRealCon(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartOptExp(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartSymbols(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartSymbol(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartGrammar(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartImpSection(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartDefinition(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartModule(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartSections(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartSection(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartImports(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartImport(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartModuleName(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartModuleId(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartRenamings(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartRenaming(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartPriorities(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartPriority(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartGroup(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAssociativity(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartCharClass(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartShortChar(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartNumChar(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartCharacter(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartSort(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartRestrictions(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartRestriction(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartLookaheads(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartLookahead(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAliases(arg)) {
    return ATtrue;
  }
  else if (SDF_isStartAlias(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int SDF_getStartAmbCnt(SDF_Start arg) */

int SDF_getStartAmbCnt(SDF_Start arg)
{
  if (SDF_isStartSDF(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartProductions(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartProduction(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartAttributes(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartAttribute(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartAnn(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartATerm(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartAFun(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartACon(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartATermList(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartQLiteral(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartUQLiteral(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartLiteral(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartIntCon(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartNatCon(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartRealCon(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartOptExp(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartSymbols(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartSymbol(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartGrammar(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartImpSection(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartDefinition(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartModule(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartSections(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartSection(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartImports(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartImport(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartModuleName(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartModuleId(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartRenamings(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartRenaming(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartPriorities(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartPriority(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartGroup(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartAssociativity(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartCharClass(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartShortChar(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartNumChar(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartCharacter(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartSort(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartRestrictions(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartRestriction(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartLookaheads(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartLookahead(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (SDF_isStartAliases(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartAmbCnt(SDF_Start arg, int ambCnt) */

SDF_Start SDF_setStartAmbCnt(SDF_Start arg, int ambCnt)
{
  if (SDF_isStartSDF(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartProductions(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartProduction(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartAttributes(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartAttribute(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartAnn(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartATerm(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartAFun(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartACon(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartATermList(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartQLiteral(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartUQLiteral(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartLiteral(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartIntCon(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartNatCon(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartRealCon(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartOptExp(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartSymbols(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartSymbol(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartGrammar(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartImpSection(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartDefinition(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartModule(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartSections(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartSection(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartImports(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartImport(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartModuleName(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartModuleId(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartRenamings(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartRenaming(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartPriorities(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartPriority(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartGroup(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartAssociativity(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartCharClass(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartShortChar(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartNumChar(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartCharacter(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartSort(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartRestrictions(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartRestriction(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartLookaheads(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartLookahead(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartAliases(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (SDF_isStartAlias(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }

  ATabort("Start has no AmbCnt: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopProductions(SDF_Start arg) */

ATbool SDF_hasStartTopProductions(SDF_Start arg)
{
  if (SDF_isStartProductions(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Productions SDF_getStartTopProductions(SDF_Start arg) */

SDF_Productions SDF_getStartTopProductions(SDF_Start arg)
{
  
    return (SDF_Productions)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopProductions(SDF_Start arg, SDF_Productions topProductions) */

SDF_Start SDF_setStartTopProductions(SDF_Start arg, SDF_Productions topProductions)
{
  if (SDF_isStartProductions(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topProductions, 1), 1), 0);
  }

  ATabort("Start has no TopProductions: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopProduction(SDF_Start arg) */

ATbool SDF_hasStartTopProduction(SDF_Start arg)
{
  if (SDF_isStartProduction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Production SDF_getStartTopProduction(SDF_Start arg) */

SDF_Production SDF_getStartTopProduction(SDF_Start arg)
{
  
    return (SDF_Production)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopProduction(SDF_Start arg, SDF_Production topProduction) */

SDF_Start SDF_setStartTopProduction(SDF_Start arg, SDF_Production topProduction)
{
  if (SDF_isStartProduction(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topProduction, 1), 1), 0);
  }

  ATabort("Start has no TopProduction: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopAttributes(SDF_Start arg) */

ATbool SDF_hasStartTopAttributes(SDF_Start arg)
{
  if (SDF_isStartAttributes(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Attributes SDF_getStartTopAttributes(SDF_Start arg) */

SDF_Attributes SDF_getStartTopAttributes(SDF_Start arg)
{
  
    return (SDF_Attributes)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopAttributes(SDF_Start arg, SDF_Attributes topAttributes) */

SDF_Start SDF_setStartTopAttributes(SDF_Start arg, SDF_Attributes topAttributes)
{
  if (SDF_isStartAttributes(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topAttributes, 1), 1), 0);
  }

  ATabort("Start has no TopAttributes: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopAttribute(SDF_Start arg) */

ATbool SDF_hasStartTopAttribute(SDF_Start arg)
{
  if (SDF_isStartAttribute(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Attribute SDF_getStartTopAttribute(SDF_Start arg) */

SDF_Attribute SDF_getStartTopAttribute(SDF_Start arg)
{
  
    return (SDF_Attribute)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopAttribute(SDF_Start arg, SDF_Attribute topAttribute) */

SDF_Start SDF_setStartTopAttribute(SDF_Start arg, SDF_Attribute topAttribute)
{
  if (SDF_isStartAttribute(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topAttribute, 1), 1), 0);
  }

  ATabort("Start has no TopAttribute: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopAnn(SDF_Start arg) */

ATbool SDF_hasStartTopAnn(SDF_Start arg)
{
  if (SDF_isStartAnn(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Ann SDF_getStartTopAnn(SDF_Start arg) */

SDF_Ann SDF_getStartTopAnn(SDF_Start arg)
{
  
    return (SDF_Ann)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopAnn(SDF_Start arg, SDF_Ann topAnn) */

SDF_Start SDF_setStartTopAnn(SDF_Start arg, SDF_Ann topAnn)
{
  if (SDF_isStartAnn(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topAnn, 1), 1), 0);
  }

  ATabort("Start has no TopAnn: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopATerm(SDF_Start arg) */

ATbool SDF_hasStartTopATerm(SDF_Start arg)
{
  if (SDF_isStartATerm(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ATerm SDF_getStartTopATerm(SDF_Start arg) */

SDF_ATerm SDF_getStartTopATerm(SDF_Start arg)
{
  
    return (SDF_ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopATerm(SDF_Start arg, SDF_ATerm topATerm) */

SDF_Start SDF_setStartTopATerm(SDF_Start arg, SDF_ATerm topATerm)
{
  if (SDF_isStartATerm(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topATerm, 1), 1), 0);
  }

  ATabort("Start has no TopATerm: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopAFun(SDF_Start arg) */

ATbool SDF_hasStartTopAFun(SDF_Start arg)
{
  if (SDF_isStartAFun(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_AFun SDF_getStartTopAFun(SDF_Start arg) */

SDF_AFun SDF_getStartTopAFun(SDF_Start arg)
{
  
    return (SDF_AFun)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopAFun(SDF_Start arg, SDF_AFun topAFun) */

SDF_Start SDF_setStartTopAFun(SDF_Start arg, SDF_AFun topAFun)
{
  if (SDF_isStartAFun(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topAFun, 1), 1), 0);
  }

  ATabort("Start has no TopAFun: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopACon(SDF_Start arg) */

ATbool SDF_hasStartTopACon(SDF_Start arg)
{
  if (SDF_isStartACon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ACon SDF_getStartTopACon(SDF_Start arg) */

SDF_ACon SDF_getStartTopACon(SDF_Start arg)
{
  
    return (SDF_ACon)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopACon(SDF_Start arg, SDF_ACon topACon) */

SDF_Start SDF_setStartTopACon(SDF_Start arg, SDF_ACon topACon)
{
  if (SDF_isStartACon(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topACon, 1), 1), 0);
  }

  ATabort("Start has no TopACon: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopATermList(SDF_Start arg) */

ATbool SDF_hasStartTopATermList(SDF_Start arg)
{
  if (SDF_isStartATermList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ATermList SDF_getStartTopATermList(SDF_Start arg) */

SDF_ATermList SDF_getStartTopATermList(SDF_Start arg)
{
  
    return (SDF_ATermList)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopATermList(SDF_Start arg, SDF_ATermList topATermList) */

SDF_Start SDF_setStartTopATermList(SDF_Start arg, SDF_ATermList topATermList)
{
  if (SDF_isStartATermList(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topATermList, 1), 1), 0);
  }

  ATabort("Start has no TopATermList: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopQLiteral(SDF_Start arg) */

ATbool SDF_hasStartTopQLiteral(SDF_Start arg)
{
  if (SDF_isStartQLiteral(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_QLiteral SDF_getStartTopQLiteral(SDF_Start arg) */

SDF_QLiteral SDF_getStartTopQLiteral(SDF_Start arg)
{
  
    return (SDF_QLiteral)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopQLiteral(SDF_Start arg, SDF_QLiteral topQLiteral) */

SDF_Start SDF_setStartTopQLiteral(SDF_Start arg, SDF_QLiteral topQLiteral)
{
  if (SDF_isStartQLiteral(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topQLiteral, 1), 1), 0);
  }

  ATabort("Start has no TopQLiteral: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopUQLiteral(SDF_Start arg) */

ATbool SDF_hasStartTopUQLiteral(SDF_Start arg)
{
  if (SDF_isStartUQLiteral(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_UQLiteral SDF_getStartTopUQLiteral(SDF_Start arg) */

SDF_UQLiteral SDF_getStartTopUQLiteral(SDF_Start arg)
{
  
    return (SDF_UQLiteral)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopUQLiteral(SDF_Start arg, SDF_UQLiteral topUQLiteral) */

SDF_Start SDF_setStartTopUQLiteral(SDF_Start arg, SDF_UQLiteral topUQLiteral)
{
  if (SDF_isStartUQLiteral(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topUQLiteral, 1), 1), 0);
  }

  ATabort("Start has no TopUQLiteral: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopLiteral(SDF_Start arg) */

ATbool SDF_hasStartTopLiteral(SDF_Start arg)
{
  if (SDF_isStartLiteral(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Literal SDF_getStartTopLiteral(SDF_Start arg) */

SDF_Literal SDF_getStartTopLiteral(SDF_Start arg)
{
  
    return (SDF_Literal)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopLiteral(SDF_Start arg, SDF_Literal topLiteral) */

SDF_Start SDF_setStartTopLiteral(SDF_Start arg, SDF_Literal topLiteral)
{
  if (SDF_isStartLiteral(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topLiteral, 1), 1), 0);
  }

  ATabort("Start has no TopLiteral: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopIntCon(SDF_Start arg) */

ATbool SDF_hasStartTopIntCon(SDF_Start arg)
{
  if (SDF_isStartIntCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_IntCon SDF_getStartTopIntCon(SDF_Start arg) */

SDF_IntCon SDF_getStartTopIntCon(SDF_Start arg)
{
  
    return (SDF_IntCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopIntCon(SDF_Start arg, SDF_IntCon topIntCon) */

SDF_Start SDF_setStartTopIntCon(SDF_Start arg, SDF_IntCon topIntCon)
{
  if (SDF_isStartIntCon(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topIntCon, 1), 1), 0);
  }

  ATabort("Start has no TopIntCon: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopNatCon(SDF_Start arg) */

ATbool SDF_hasStartTopNatCon(SDF_Start arg)
{
  if (SDF_isStartNatCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_NatCon SDF_getStartTopNatCon(SDF_Start arg) */

SDF_NatCon SDF_getStartTopNatCon(SDF_Start arg)
{
  
    return (SDF_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopNatCon(SDF_Start arg, SDF_NatCon topNatCon) */

SDF_Start SDF_setStartTopNatCon(SDF_Start arg, SDF_NatCon topNatCon)
{
  if (SDF_isStartNatCon(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topNatCon, 1), 1), 0);
  }

  ATabort("Start has no TopNatCon: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopRealCon(SDF_Start arg) */

ATbool SDF_hasStartTopRealCon(SDF_Start arg)
{
  if (SDF_isStartRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_RealCon SDF_getStartTopRealCon(SDF_Start arg) */

SDF_RealCon SDF_getStartTopRealCon(SDF_Start arg)
{
  
    return (SDF_RealCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopRealCon(SDF_Start arg, SDF_RealCon topRealCon) */

SDF_Start SDF_setStartTopRealCon(SDF_Start arg, SDF_RealCon topRealCon)
{
  if (SDF_isStartRealCon(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topRealCon, 1), 1), 0);
  }

  ATabort("Start has no TopRealCon: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopOptExp(SDF_Start arg) */

ATbool SDF_hasStartTopOptExp(SDF_Start arg)
{
  if (SDF_isStartOptExp(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_OptExp SDF_getStartTopOptExp(SDF_Start arg) */

SDF_OptExp SDF_getStartTopOptExp(SDF_Start arg)
{
  
    return (SDF_OptExp)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopOptExp(SDF_Start arg, SDF_OptExp topOptExp) */

SDF_Start SDF_setStartTopOptExp(SDF_Start arg, SDF_OptExp topOptExp)
{
  if (SDF_isStartOptExp(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topOptExp, 1), 1), 0);
  }

  ATabort("Start has no TopOptExp: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopSymbols(SDF_Start arg) */

ATbool SDF_hasStartTopSymbols(SDF_Start arg)
{
  if (SDF_isStartSymbols(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbols SDF_getStartTopSymbols(SDF_Start arg) */

SDF_Symbols SDF_getStartTopSymbols(SDF_Start arg)
{
  
    return (SDF_Symbols)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopSymbols(SDF_Start arg, SDF_Symbols topSymbols) */

SDF_Start SDF_setStartTopSymbols(SDF_Start arg, SDF_Symbols topSymbols)
{
  if (SDF_isStartSymbols(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topSymbols, 1), 1), 0);
  }

  ATabort("Start has no TopSymbols: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopSymbol(SDF_Start arg) */

ATbool SDF_hasStartTopSymbol(SDF_Start arg)
{
  if (SDF_isStartSymbol(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_getStartTopSymbol(SDF_Start arg) */

SDF_Symbol SDF_getStartTopSymbol(SDF_Start arg)
{
  
    return (SDF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopSymbol(SDF_Start arg, SDF_Symbol topSymbol) */

SDF_Start SDF_setStartTopSymbol(SDF_Start arg, SDF_Symbol topSymbol)
{
  if (SDF_isStartSymbol(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topSymbol, 1), 1), 0);
  }

  ATabort("Start has no TopSymbol: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopGrammar(SDF_Start arg) */

ATbool SDF_hasStartTopGrammar(SDF_Start arg)
{
  if (SDF_isStartGrammar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Grammar SDF_getStartTopGrammar(SDF_Start arg) */

SDF_Grammar SDF_getStartTopGrammar(SDF_Start arg)
{
  
    return (SDF_Grammar)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopGrammar(SDF_Start arg, SDF_Grammar topGrammar) */

SDF_Start SDF_setStartTopGrammar(SDF_Start arg, SDF_Grammar topGrammar)
{
  if (SDF_isStartGrammar(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topGrammar, 1), 1), 0);
  }

  ATabort("Start has no TopGrammar: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopImpSection(SDF_Start arg) */

ATbool SDF_hasStartTopImpSection(SDF_Start arg)
{
  if (SDF_isStartImpSection(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ImpSection SDF_getStartTopImpSection(SDF_Start arg) */

SDF_ImpSection SDF_getStartTopImpSection(SDF_Start arg)
{
  
    return (SDF_ImpSection)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopImpSection(SDF_Start arg, SDF_ImpSection topImpSection) */

SDF_Start SDF_setStartTopImpSection(SDF_Start arg, SDF_ImpSection topImpSection)
{
  if (SDF_isStartImpSection(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topImpSection, 1), 1), 0);
  }

  ATabort("Start has no TopImpSection: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopDefinition(SDF_Start arg) */

ATbool SDF_hasStartTopDefinition(SDF_Start arg)
{
  if (SDF_isStartDefinition(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Definition SDF_getStartTopDefinition(SDF_Start arg) */

SDF_Definition SDF_getStartTopDefinition(SDF_Start arg)
{
  
    return (SDF_Definition)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopDefinition(SDF_Start arg, SDF_Definition topDefinition) */

SDF_Start SDF_setStartTopDefinition(SDF_Start arg, SDF_Definition topDefinition)
{
  if (SDF_isStartDefinition(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topDefinition, 1), 1), 0);
  }

  ATabort("Start has no TopDefinition: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopModule(SDF_Start arg) */

ATbool SDF_hasStartTopModule(SDF_Start arg)
{
  if (SDF_isStartModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Module SDF_getStartTopModule(SDF_Start arg) */

SDF_Module SDF_getStartTopModule(SDF_Start arg)
{
  
    return (SDF_Module)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopModule(SDF_Start arg, SDF_Module topModule) */

SDF_Start SDF_setStartTopModule(SDF_Start arg, SDF_Module topModule)
{
  if (SDF_isStartModule(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topModule, 1), 1), 0);
  }

  ATabort("Start has no TopModule: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopSections(SDF_Start arg) */

ATbool SDF_hasStartTopSections(SDF_Start arg)
{
  if (SDF_isStartSections(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Sections SDF_getStartTopSections(SDF_Start arg) */

SDF_Sections SDF_getStartTopSections(SDF_Start arg)
{
  
    return (SDF_Sections)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopSections(SDF_Start arg, SDF_Sections topSections) */

SDF_Start SDF_setStartTopSections(SDF_Start arg, SDF_Sections topSections)
{
  if (SDF_isStartSections(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topSections, 1), 1), 0);
  }

  ATabort("Start has no TopSections: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopSection(SDF_Start arg) */

ATbool SDF_hasStartTopSection(SDF_Start arg)
{
  if (SDF_isStartSection(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Section SDF_getStartTopSection(SDF_Start arg) */

SDF_Section SDF_getStartTopSection(SDF_Start arg)
{
  
    return (SDF_Section)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopSection(SDF_Start arg, SDF_Section topSection) */

SDF_Start SDF_setStartTopSection(SDF_Start arg, SDF_Section topSection)
{
  if (SDF_isStartSection(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topSection, 1), 1), 0);
  }

  ATabort("Start has no TopSection: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopImports(SDF_Start arg) */

ATbool SDF_hasStartTopImports(SDF_Start arg)
{
  if (SDF_isStartImports(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Imports SDF_getStartTopImports(SDF_Start arg) */

SDF_Imports SDF_getStartTopImports(SDF_Start arg)
{
  
    return (SDF_Imports)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopImports(SDF_Start arg, SDF_Imports topImports) */

SDF_Start SDF_setStartTopImports(SDF_Start arg, SDF_Imports topImports)
{
  if (SDF_isStartImports(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topImports, 1), 1), 0);
  }

  ATabort("Start has no TopImports: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopImport(SDF_Start arg) */

ATbool SDF_hasStartTopImport(SDF_Start arg)
{
  if (SDF_isStartImport(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Import SDF_getStartTopImport(SDF_Start arg) */

SDF_Import SDF_getStartTopImport(SDF_Start arg)
{
  
    return (SDF_Import)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopImport(SDF_Start arg, SDF_Import topImport) */

SDF_Start SDF_setStartTopImport(SDF_Start arg, SDF_Import topImport)
{
  if (SDF_isStartImport(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topImport, 1), 1), 0);
  }

  ATabort("Start has no TopImport: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopModuleName(SDF_Start arg) */

ATbool SDF_hasStartTopModuleName(SDF_Start arg)
{
  if (SDF_isStartModuleName(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_getStartTopModuleName(SDF_Start arg) */

SDF_ModuleName SDF_getStartTopModuleName(SDF_Start arg)
{
  
    return (SDF_ModuleName)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopModuleName(SDF_Start arg, SDF_ModuleName topModuleName) */

SDF_Start SDF_setStartTopModuleName(SDF_Start arg, SDF_ModuleName topModuleName)
{
  if (SDF_isStartModuleName(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topModuleName, 1), 1), 0);
  }

  ATabort("Start has no TopModuleName: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopModuleId(SDF_Start arg) */

ATbool SDF_hasStartTopModuleId(SDF_Start arg)
{
  if (SDF_isStartModuleId(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ModuleId SDF_getStartTopModuleId(SDF_Start arg) */

SDF_ModuleId SDF_getStartTopModuleId(SDF_Start arg)
{
  
    return (SDF_ModuleId)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopModuleId(SDF_Start arg, SDF_ModuleId topModuleId) */

SDF_Start SDF_setStartTopModuleId(SDF_Start arg, SDF_ModuleId topModuleId)
{
  if (SDF_isStartModuleId(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topModuleId, 1), 1), 0);
  }

  ATabort("Start has no TopModuleId: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopRenamings(SDF_Start arg) */

ATbool SDF_hasStartTopRenamings(SDF_Start arg)
{
  if (SDF_isStartRenamings(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Renamings SDF_getStartTopRenamings(SDF_Start arg) */

SDF_Renamings SDF_getStartTopRenamings(SDF_Start arg)
{
  
    return (SDF_Renamings)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopRenamings(SDF_Start arg, SDF_Renamings topRenamings) */

SDF_Start SDF_setStartTopRenamings(SDF_Start arg, SDF_Renamings topRenamings)
{
  if (SDF_isStartRenamings(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topRenamings, 1), 1), 0);
  }

  ATabort("Start has no TopRenamings: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopRenaming(SDF_Start arg) */

ATbool SDF_hasStartTopRenaming(SDF_Start arg)
{
  if (SDF_isStartRenaming(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Renaming SDF_getStartTopRenaming(SDF_Start arg) */

SDF_Renaming SDF_getStartTopRenaming(SDF_Start arg)
{
  
    return (SDF_Renaming)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopRenaming(SDF_Start arg, SDF_Renaming topRenaming) */

SDF_Start SDF_setStartTopRenaming(SDF_Start arg, SDF_Renaming topRenaming)
{
  if (SDF_isStartRenaming(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topRenaming, 1), 1), 0);
  }

  ATabort("Start has no TopRenaming: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopPriorities(SDF_Start arg) */

ATbool SDF_hasStartTopPriorities(SDF_Start arg)
{
  if (SDF_isStartPriorities(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Priorities SDF_getStartTopPriorities(SDF_Start arg) */

SDF_Priorities SDF_getStartTopPriorities(SDF_Start arg)
{
  
    return (SDF_Priorities)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopPriorities(SDF_Start arg, SDF_Priorities topPriorities) */

SDF_Start SDF_setStartTopPriorities(SDF_Start arg, SDF_Priorities topPriorities)
{
  if (SDF_isStartPriorities(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topPriorities, 1), 1), 0);
  }

  ATabort("Start has no TopPriorities: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopPriority(SDF_Start arg) */

ATbool SDF_hasStartTopPriority(SDF_Start arg)
{
  if (SDF_isStartPriority(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Priority SDF_getStartTopPriority(SDF_Start arg) */

SDF_Priority SDF_getStartTopPriority(SDF_Start arg)
{
  
    return (SDF_Priority)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopPriority(SDF_Start arg, SDF_Priority topPriority) */

SDF_Start SDF_setStartTopPriority(SDF_Start arg, SDF_Priority topPriority)
{
  if (SDF_isStartPriority(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topPriority, 1), 1), 0);
  }

  ATabort("Start has no TopPriority: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopGroup(SDF_Start arg) */

ATbool SDF_hasStartTopGroup(SDF_Start arg)
{
  if (SDF_isStartGroup(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Group SDF_getStartTopGroup(SDF_Start arg) */

SDF_Group SDF_getStartTopGroup(SDF_Start arg)
{
  
    return (SDF_Group)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopGroup(SDF_Start arg, SDF_Group topGroup) */

SDF_Start SDF_setStartTopGroup(SDF_Start arg, SDF_Group topGroup)
{
  if (SDF_isStartGroup(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topGroup, 1), 1), 0);
  }

  ATabort("Start has no TopGroup: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopAssociativity(SDF_Start arg) */

ATbool SDF_hasStartTopAssociativity(SDF_Start arg)
{
  if (SDF_isStartAssociativity(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Associativity SDF_getStartTopAssociativity(SDF_Start arg) */

SDF_Associativity SDF_getStartTopAssociativity(SDF_Start arg)
{
  
    return (SDF_Associativity)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopAssociativity(SDF_Start arg, SDF_Associativity topAssociativity) */

SDF_Start SDF_setStartTopAssociativity(SDF_Start arg, SDF_Associativity topAssociativity)
{
  if (SDF_isStartAssociativity(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topAssociativity, 1), 1), 0);
  }

  ATabort("Start has no TopAssociativity: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopCharClass(SDF_Start arg) */

ATbool SDF_hasStartTopCharClass(SDF_Start arg)
{
  if (SDF_isStartCharClass(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_CharClass SDF_getStartTopCharClass(SDF_Start arg) */

SDF_CharClass SDF_getStartTopCharClass(SDF_Start arg)
{
  
    return (SDF_CharClass)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopCharClass(SDF_Start arg, SDF_CharClass topCharClass) */

SDF_Start SDF_setStartTopCharClass(SDF_Start arg, SDF_CharClass topCharClass)
{
  if (SDF_isStartCharClass(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topCharClass, 1), 1), 0);
  }

  ATabort("Start has no TopCharClass: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopShortChar(SDF_Start arg) */

ATbool SDF_hasStartTopShortChar(SDF_Start arg)
{
  if (SDF_isStartShortChar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_ShortChar SDF_getStartTopShortChar(SDF_Start arg) */

SDF_ShortChar SDF_getStartTopShortChar(SDF_Start arg)
{
  
    return (SDF_ShortChar)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopShortChar(SDF_Start arg, SDF_ShortChar topShortChar) */

SDF_Start SDF_setStartTopShortChar(SDF_Start arg, SDF_ShortChar topShortChar)
{
  if (SDF_isStartShortChar(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topShortChar, 1), 1), 0);
  }

  ATabort("Start has no TopShortChar: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopNumChar(SDF_Start arg) */

ATbool SDF_hasStartTopNumChar(SDF_Start arg)
{
  if (SDF_isStartNumChar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_NumChar SDF_getStartTopNumChar(SDF_Start arg) */

SDF_NumChar SDF_getStartTopNumChar(SDF_Start arg)
{
  
    return (SDF_NumChar)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopNumChar(SDF_Start arg, SDF_NumChar topNumChar) */

SDF_Start SDF_setStartTopNumChar(SDF_Start arg, SDF_NumChar topNumChar)
{
  if (SDF_isStartNumChar(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topNumChar, 1), 1), 0);
  }

  ATabort("Start has no TopNumChar: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopCharacter(SDF_Start arg) */

ATbool SDF_hasStartTopCharacter(SDF_Start arg)
{
  if (SDF_isStartCharacter(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Character SDF_getStartTopCharacter(SDF_Start arg) */

SDF_Character SDF_getStartTopCharacter(SDF_Start arg)
{
  
    return (SDF_Character)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopCharacter(SDF_Start arg, SDF_Character topCharacter) */

SDF_Start SDF_setStartTopCharacter(SDF_Start arg, SDF_Character topCharacter)
{
  if (SDF_isStartCharacter(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topCharacter, 1), 1), 0);
  }

  ATabort("Start has no TopCharacter: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopSort(SDF_Start arg) */

ATbool SDF_hasStartTopSort(SDF_Start arg)
{
  if (SDF_isStartSort(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Sort SDF_getStartTopSort(SDF_Start arg) */

SDF_Sort SDF_getStartTopSort(SDF_Start arg)
{
  
    return (SDF_Sort)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopSort(SDF_Start arg, SDF_Sort topSort) */

SDF_Start SDF_setStartTopSort(SDF_Start arg, SDF_Sort topSort)
{
  if (SDF_isStartSort(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topSort, 1), 1), 0);
  }

  ATabort("Start has no TopSort: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopRestrictions(SDF_Start arg) */

ATbool SDF_hasStartTopRestrictions(SDF_Start arg)
{
  if (SDF_isStartRestrictions(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Restrictions SDF_getStartTopRestrictions(SDF_Start arg) */

SDF_Restrictions SDF_getStartTopRestrictions(SDF_Start arg)
{
  
    return (SDF_Restrictions)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopRestrictions(SDF_Start arg, SDF_Restrictions topRestrictions) */

SDF_Start SDF_setStartTopRestrictions(SDF_Start arg, SDF_Restrictions topRestrictions)
{
  if (SDF_isStartRestrictions(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topRestrictions, 1), 1), 0);
  }

  ATabort("Start has no TopRestrictions: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopRestriction(SDF_Start arg) */

ATbool SDF_hasStartTopRestriction(SDF_Start arg)
{
  if (SDF_isStartRestriction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Restriction SDF_getStartTopRestriction(SDF_Start arg) */

SDF_Restriction SDF_getStartTopRestriction(SDF_Start arg)
{
  
    return (SDF_Restriction)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopRestriction(SDF_Start arg, SDF_Restriction topRestriction) */

SDF_Start SDF_setStartTopRestriction(SDF_Start arg, SDF_Restriction topRestriction)
{
  if (SDF_isStartRestriction(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topRestriction, 1), 1), 0);
  }

  ATabort("Start has no TopRestriction: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopLookaheads(SDF_Start arg) */

ATbool SDF_hasStartTopLookaheads(SDF_Start arg)
{
  if (SDF_isStartLookaheads(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Lookaheads SDF_getStartTopLookaheads(SDF_Start arg) */

SDF_Lookaheads SDF_getStartTopLookaheads(SDF_Start arg)
{
  
    return (SDF_Lookaheads)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopLookaheads(SDF_Start arg, SDF_Lookaheads topLookaheads) */

SDF_Start SDF_setStartTopLookaheads(SDF_Start arg, SDF_Lookaheads topLookaheads)
{
  if (SDF_isStartLookaheads(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topLookaheads, 1), 1), 0);
  }

  ATabort("Start has no TopLookaheads: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopLookahead(SDF_Start arg) */

ATbool SDF_hasStartTopLookahead(SDF_Start arg)
{
  if (SDF_isStartLookahead(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Lookahead SDF_getStartTopLookahead(SDF_Start arg) */

SDF_Lookahead SDF_getStartTopLookahead(SDF_Start arg)
{
  
    return (SDF_Lookahead)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopLookahead(SDF_Start arg, SDF_Lookahead topLookahead) */

SDF_Start SDF_setStartTopLookahead(SDF_Start arg, SDF_Lookahead topLookahead)
{
  if (SDF_isStartLookahead(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topLookahead, 1), 1), 0);
  }

  ATabort("Start has no TopLookahead: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopAliases(SDF_Start arg) */

ATbool SDF_hasStartTopAliases(SDF_Start arg)
{
  if (SDF_isStartAliases(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Aliases SDF_getStartTopAliases(SDF_Start arg) */

SDF_Aliases SDF_getStartTopAliases(SDF_Start arg)
{
  
    return (SDF_Aliases)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopAliases(SDF_Start arg, SDF_Aliases topAliases) */

SDF_Start SDF_setStartTopAliases(SDF_Start arg, SDF_Aliases topAliases)
{
  if (SDF_isStartAliases(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topAliases, 1), 1), 0);
  }

  ATabort("Start has no TopAliases: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool SDF_hasStartTopAlias(SDF_Start arg) */

ATbool SDF_hasStartTopAlias(SDF_Start arg)
{
  if (SDF_isStartAlias(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SDF_Alias SDF_getStartTopAlias(SDF_Start arg) */

SDF_Alias SDF_getStartTopAlias(SDF_Start arg)
{
  
    return (SDF_Alias)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  SDF_Start SDF_setStartTopAlias(SDF_Start arg, SDF_Alias topAlias) */

SDF_Start SDF_setStartTopAlias(SDF_Start arg, SDF_Alias topAlias)
{
  if (SDF_isStartAlias(arg)) {
    return (SDF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topAlias, 1), 1), 0);
  }

  ATabort("Start has no TopAlias: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  SDF_Grammar SDF_visitGrammar(SDF_Grammar arg, SDF_OptLayout (*acceptWsAfterAliases)(SDF_OptLayout), SDF_Aliases (*acceptAliases)(SDF_Aliases), SDF_OptLayout (*acceptWsAfterRestrictions)(SDF_OptLayout), SDF_Restrictions (*acceptRestrictions)(SDF_Restrictions), SDF_OptLayout (*acceptWsAfterSorts)(SDF_OptLayout), SDF_Symbols (*acceptSymbols)(SDF_Symbols), SDF_OptLayout (*acceptWsAfterPriorities)(SDF_OptLayout), SDF_Priorities (*acceptPriorities)(SDF_Priorities), SDF_ImpSection (*acceptImpSection)(SDF_ImpSection), SDF_OptLayout (*acceptWsAfterLexical)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterSyntax)(SDF_OptLayout), SDF_Productions (*acceptProductions)(SDF_Productions), SDF_OptLayout (*acceptWsAfterContextFree)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterVariables)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterLeft)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterGrammar)(SDF_OptLayout)) */

SDF_Grammar SDF_visitGrammar(SDF_Grammar arg, SDF_OptLayout (*acceptWsAfterAliases)(SDF_OptLayout), SDF_Aliases (*acceptAliases)(SDF_Aliases), SDF_OptLayout (*acceptWsAfterRestrictions)(SDF_OptLayout), SDF_Restrictions (*acceptRestrictions)(SDF_Restrictions), SDF_OptLayout (*acceptWsAfterSorts)(SDF_OptLayout), SDF_Symbols (*acceptSymbols)(SDF_Symbols), SDF_OptLayout (*acceptWsAfterPriorities)(SDF_OptLayout), SDF_Priorities (*acceptPriorities)(SDF_Priorities), SDF_ImpSection (*acceptImpSection)(SDF_ImpSection), SDF_OptLayout (*acceptWsAfterLexical)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterSyntax)(SDF_OptLayout), SDF_Productions (*acceptProductions)(SDF_Productions), SDF_OptLayout (*acceptWsAfterContextFree)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterVariables)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterLeft)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterGrammar)(SDF_OptLayout))
{
  if (SDF_isGrammarAliases(arg)) {
    return SDF_makeGrammarAliases(
        acceptWsAfterAliases ? acceptWsAfterAliases(SDF_getGrammarWsAfterAliases(arg)) : SDF_getGrammarWsAfterAliases(arg),
        acceptAliases ? acceptAliases(SDF_getGrammarAliases(arg)) : SDF_getGrammarAliases(arg));
  }
  if (SDF_isGrammarRestrictions(arg)) {
    return SDF_makeGrammarRestrictions(
        acceptWsAfterRestrictions ? acceptWsAfterRestrictions(SDF_getGrammarWsAfterRestrictions(arg)) : SDF_getGrammarWsAfterRestrictions(arg),
        acceptRestrictions ? acceptRestrictions(SDF_getGrammarRestrictions(arg)) : SDF_getGrammarRestrictions(arg));
  }
  if (SDF_isGrammarSorts(arg)) {
    return SDF_makeGrammarSorts(
        acceptWsAfterSorts ? acceptWsAfterSorts(SDF_getGrammarWsAfterSorts(arg)) : SDF_getGrammarWsAfterSorts(arg),
        acceptSymbols ? acceptSymbols(SDF_getGrammarSymbols(arg)) : SDF_getGrammarSymbols(arg));
  }
  if (SDF_isGrammarPriorities(arg)) {
    return SDF_makeGrammarPriorities(
        acceptWsAfterPriorities ? acceptWsAfterPriorities(SDF_getGrammarWsAfterPriorities(arg)) : SDF_getGrammarWsAfterPriorities(arg),
        acceptPriorities ? acceptPriorities(SDF_getGrammarPriorities(arg)) : SDF_getGrammarPriorities(arg));
  }
  if (SDF_isGrammarImpSection(arg)) {
    return SDF_makeGrammarImpSection(
        acceptImpSection ? acceptImpSection(SDF_getGrammarImpSection(arg)) : SDF_getGrammarImpSection(arg));
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
  if (SDF_isGrammarEmptyGrammar(arg)) {
    return SDF_makeGrammarEmptyGrammar();
  }
  if (SDF_isGrammarConcGrammars(arg)) {
    return SDF_makeGrammarConcGrammars(
        SDF_visitGrammar(SDF_getGrammarLeft(arg), acceptWsAfterAliases, acceptAliases, acceptWsAfterRestrictions, acceptRestrictions, acceptWsAfterSorts, acceptSymbols, acceptWsAfterPriorities, acceptPriorities, acceptImpSection, acceptWsAfterLexical, acceptWsAfterSyntax, acceptProductions, acceptWsAfterContextFree, acceptWsAfterVariables, acceptWsAfterLeft, acceptWsAfterParenOpen, acceptWsAfterGrammar),
        acceptWsAfterLeft ? acceptWsAfterLeft(SDF_getGrammarWsAfterLeft(arg)) : SDF_getGrammarWsAfterLeft(arg),
        SDF_visitGrammar(SDF_getGrammarRight(arg), acceptWsAfterAliases, acceptAliases, acceptWsAfterRestrictions, acceptRestrictions, acceptWsAfterSorts, acceptSymbols, acceptWsAfterPriorities, acceptPriorities, acceptImpSection, acceptWsAfterLexical, acceptWsAfterSyntax, acceptProductions, acceptWsAfterContextFree, acceptWsAfterVariables, acceptWsAfterLeft, acceptWsAfterParenOpen, acceptWsAfterGrammar));
  }
  if (SDF_isGrammarBracket(arg)) {
    return SDF_makeGrammarBracket(
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(SDF_getGrammarWsAfterParenOpen(arg)) : SDF_getGrammarWsAfterParenOpen(arg),
        SDF_visitGrammar(SDF_getGrammarGrammar(arg), acceptWsAfterAliases, acceptAliases, acceptWsAfterRestrictions, acceptRestrictions, acceptWsAfterSorts, acceptSymbols, acceptWsAfterPriorities, acceptPriorities, acceptImpSection, acceptWsAfterLexical, acceptWsAfterSyntax, acceptProductions, acceptWsAfterContextFree, acceptWsAfterVariables, acceptWsAfterLeft, acceptWsAfterParenOpen, acceptWsAfterGrammar),
        acceptWsAfterGrammar ? acceptWsAfterGrammar(SDF_getGrammarWsAfterGrammar(arg)) : SDF_getGrammarWsAfterGrammar(arg));
  }
  if (SDF_isGrammarSyntax(arg)) {
    return SDF_makeGrammarSyntax(
        acceptWsAfterSyntax ? acceptWsAfterSyntax(SDF_getGrammarWsAfterSyntax(arg)) : SDF_getGrammarWsAfterSyntax(arg),
        acceptProductions ? acceptProductions(SDF_getGrammarProductions(arg)) : SDF_getGrammarProductions(arg));
  }
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
  ATabort("not a Grammar: %t\n", arg);
  return (SDF_Grammar)NULL;
}

/*}}}  */
/*{{{  SDF_Alias SDF_visitAlias(SDF_Alias arg, SDF_Symbol (*acceptSymbol)(SDF_Symbol), SDF_OptLayout (*acceptWsAfterSymbol)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterArrow)(SDF_OptLayout), SDF_Symbol (*acceptAlias)(SDF_Symbol)) */

SDF_Alias SDF_visitAlias(SDF_Alias arg, SDF_Symbol (*acceptSymbol)(SDF_Symbol), SDF_OptLayout (*acceptWsAfterSymbol)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterArrow)(SDF_OptLayout), SDF_Symbol (*acceptAlias)(SDF_Symbol))
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
/*{{{  SDF_AliasList SDF_visitAliasList(SDF_AliasList arg, SDF_Alias (*acceptHead)(SDF_Alias), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout)) */

SDF_AliasList SDF_visitAliasList(SDF_AliasList arg, SDF_Alias (*acceptHead)(SDF_Alias), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout))
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
/*{{{  SDF_Lookahead SDF_visitLookahead(SDF_Lookahead arg, SDF_CharClass (*acceptCharClass)(SDF_CharClass), SDF_CharClass (*acceptHead)(SDF_CharClass), SDF_OptLayout (*acceptWsAfterHead)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterPeriod)(SDF_OptLayout), SDF_Lookaheads (*acceptTail)(SDF_Lookaheads)) */

SDF_Lookahead SDF_visitLookahead(SDF_Lookahead arg, SDF_CharClass (*acceptCharClass)(SDF_CharClass), SDF_CharClass (*acceptHead)(SDF_CharClass), SDF_OptLayout (*acceptWsAfterHead)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterPeriod)(SDF_OptLayout), SDF_Lookaheads (*acceptTail)(SDF_Lookaheads))
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
/*{{{  SDF_Lookaheads SDF_visitLookaheads(SDF_Lookaheads arg, SDF_Lookahead (*acceptLookahead)(SDF_Lookahead), SDF_OptLayout (*acceptWsAfterLeft)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterBar)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterLookaheads)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterBracketOpenBracketOpen)(SDF_OptLayout), SDF_LookaheadList (*acceptList)(SDF_LookaheadList), SDF_OptLayout (*acceptWsAfterList)(SDF_OptLayout)) */

SDF_Lookaheads SDF_visitLookaheads(SDF_Lookaheads arg, SDF_Lookahead (*acceptLookahead)(SDF_Lookahead), SDF_OptLayout (*acceptWsAfterLeft)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterBar)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterLookaheads)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterBracketOpenBracketOpen)(SDF_OptLayout), SDF_LookaheadList (*acceptList)(SDF_LookaheadList), SDF_OptLayout (*acceptWsAfterList)(SDF_OptLayout))
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
/*{{{  SDF_LookaheadList SDF_visitLookaheadList(SDF_LookaheadList arg, SDF_Lookahead (*acceptHead)(SDF_Lookahead), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout)) */

SDF_LookaheadList SDF_visitLookaheadList(SDF_LookaheadList arg, SDF_Lookahead (*acceptHead)(SDF_Lookahead), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout))
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
/*{{{  SDF_Restriction SDF_visitRestriction(SDF_Restriction arg, SDF_Symbols (*acceptSymbols)(SDF_Symbols), SDF_OptLayout (*acceptWsAfterSymbols)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterSlash)(SDF_OptLayout), SDF_Lookaheads (*acceptLookaheads)(SDF_Lookaheads)) */

SDF_Restriction SDF_visitRestriction(SDF_Restriction arg, SDF_Symbols (*acceptSymbols)(SDF_Symbols), SDF_OptLayout (*acceptWsAfterSymbols)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterSlash)(SDF_OptLayout), SDF_Lookaheads (*acceptLookaheads)(SDF_Lookaheads))
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
/*{{{  SDF_RestrictionList SDF_visitRestrictionList(SDF_RestrictionList arg, SDF_Restriction (*acceptHead)(SDF_Restriction), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout)) */

SDF_RestrictionList SDF_visitRestrictionList(SDF_RestrictionList arg, SDF_Restriction (*acceptHead)(SDF_Restriction), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout))
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
/*{{{  SDF_Attribute SDF_visitAttribute(SDF_Attribute arg, SDF_Associativity (*acceptAssociativity)(SDF_Associativity), SDF_OptLayout (*acceptWsAfterId)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_ModuleName (*acceptModuleName)(SDF_ModuleName), SDF_OptLayout (*acceptWsAfterModuleName)(SDF_OptLayout), SDF_ATerm (*acceptAterm)(SDF_ATerm)) */

SDF_Attribute SDF_visitAttribute(SDF_Attribute arg, SDF_Associativity (*acceptAssociativity)(SDF_Associativity), SDF_OptLayout (*acceptWsAfterId)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_ModuleName (*acceptModuleName)(SDF_ModuleName), SDF_OptLayout (*acceptWsAfterModuleName)(SDF_OptLayout), SDF_ATerm (*acceptAterm)(SDF_ATerm))
{
  if (SDF_isAttributeReject(arg)) {
    return SDF_makeAttributeReject();
  }
  if (SDF_isAttributePrefer(arg)) {
    return SDF_makeAttributePrefer();
  }
  if (SDF_isAttributeAvoid(arg)) {
    return SDF_makeAttributeAvoid();
  }
  if (SDF_isAttributeBracket(arg)) {
    return SDF_makeAttributeBracket();
  }
  if (SDF_isAttributeAssoc(arg)) {
    return SDF_makeAttributeAssoc(
        acceptAssociativity ? acceptAssociativity(SDF_getAttributeAssociativity(arg)) : SDF_getAttributeAssociativity(arg));
  }
  if (SDF_isAttributeId(arg)) {
    return SDF_makeAttributeId(
        acceptWsAfterId ? acceptWsAfterId(SDF_getAttributeWsAfterId(arg)) : SDF_getAttributeWsAfterId(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(SDF_getAttributeWsAfterParenOpen(arg)) : SDF_getAttributeWsAfterParenOpen(arg),
        acceptModuleName ? acceptModuleName(SDF_getAttributeModuleName(arg)) : SDF_getAttributeModuleName(arg),
        acceptWsAfterModuleName ? acceptWsAfterModuleName(SDF_getAttributeWsAfterModuleName(arg)) : SDF_getAttributeWsAfterModuleName(arg));
  }
  if (SDF_isAttributeTerm(arg)) {
    return SDF_makeAttributeTerm(
        acceptAterm ? acceptAterm(SDF_getAttributeAterm(arg)) : SDF_getAttributeAterm(arg));
  }
  ATabort("not a Attribute: %t\n", arg);
  return (SDF_Attribute)NULL;
}

/*}}}  */
/*{{{  SDF_Symbol SDF_visitSymbol(SDF_Symbol arg, SDF_Literal (*acceptLabel)(SDF_Literal), SDF_OptLayout (*acceptWsAfterLabel)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterColon)(SDF_OptLayout), SDF_Literal (*acceptLiteral)(SDF_Literal), SDF_Sort (*acceptSort)(SDF_Sort), SDF_OptLayout (*acceptWsAfterSort)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterBracketOpenBracketOpen)(SDF_OptLayout), SDF_SymbolParameters (*acceptParameters)(SDF_SymbolParameters), SDF_OptLayout (*acceptWsAfterParameters)(SDF_OptLayout), SDF_CharClass (*acceptCharClass)(SDF_CharClass), SDF_OptLayout (*acceptWsAfterLeftQuote)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterSymbol)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterHead)(SDF_OptLayout), SDF_SymbolTail (*acceptTail)(SDF_SymbolTail), SDF_OptLayout (*acceptWsAfterTail)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterBraceOpen)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterBraceClose)(SDF_OptLayout), SDF_NatCon (*acceptN)(SDF_NatCon), SDF_OptLayout (*acceptWsAfterN)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterLessThan)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterComma)(SDF_OptLayout), SDF_SymbolRest (*acceptRest)(SDF_SymbolRest), SDF_OptLayout (*acceptWsAfterRest)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterLeft)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterHash)(SDF_OptLayout), SDF_Symbols (*acceptArguments)(SDF_Symbols), SDF_OptLayout (*acceptWsAfterArguments)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterEqualsGreaterThan)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterResults)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterBar)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterGreaterThan)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterRight)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterCF)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterLEX)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterVAR)(SDF_OptLayout)) */

SDF_Symbol SDF_visitSymbol(SDF_Symbol arg, SDF_Literal (*acceptLabel)(SDF_Literal), SDF_OptLayout (*acceptWsAfterLabel)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterColon)(SDF_OptLayout), SDF_Literal (*acceptLiteral)(SDF_Literal), SDF_Sort (*acceptSort)(SDF_Sort), SDF_OptLayout (*acceptWsAfterSort)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterBracketOpenBracketOpen)(SDF_OptLayout), SDF_SymbolParameters (*acceptParameters)(SDF_SymbolParameters), SDF_OptLayout (*acceptWsAfterParameters)(SDF_OptLayout), SDF_CharClass (*acceptCharClass)(SDF_CharClass), SDF_OptLayout (*acceptWsAfterLeftQuote)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterSymbol)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterHead)(SDF_OptLayout), SDF_SymbolTail (*acceptTail)(SDF_SymbolTail), SDF_OptLayout (*acceptWsAfterTail)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterBraceOpen)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterBraceClose)(SDF_OptLayout), SDF_NatCon (*acceptN)(SDF_NatCon), SDF_OptLayout (*acceptWsAfterN)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterLessThan)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterComma)(SDF_OptLayout), SDF_SymbolRest (*acceptRest)(SDF_SymbolRest), SDF_OptLayout (*acceptWsAfterRest)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterLeft)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterHash)(SDF_OptLayout), SDF_Symbols (*acceptArguments)(SDF_Symbols), SDF_OptLayout (*acceptWsAfterArguments)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterEqualsGreaterThan)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterResults)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterBar)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterGreaterThan)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterRight)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterCF)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterLEX)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterVAR)(SDF_OptLayout))
{
  if (SDF_isSymbolLabel(arg)) {
    return SDF_makeSymbolLabel(
        acceptLabel ? acceptLabel(SDF_getSymbolLabel(arg)) : SDF_getSymbolLabel(arg),
        acceptWsAfterLabel ? acceptWsAfterLabel(SDF_getSymbolWsAfterLabel(arg)) : SDF_getSymbolWsAfterLabel(arg),
        acceptWsAfterColon ? acceptWsAfterColon(SDF_getSymbolWsAfterColon(arg)) : SDF_getSymbolWsAfterColon(arg),
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptLabel, acceptWsAfterLabel, acceptWsAfterColon, acceptLiteral, acceptSort, acceptWsAfterSort, acceptWsAfterBracketOpenBracketOpen, acceptParameters, acceptWsAfterParameters, acceptCharClass, acceptWsAfterLeftQuote, acceptWsAfterSymbol, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterLessThan, acceptWsAfterComma, acceptRest, acceptWsAfterRest, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterGreaterThan, acceptWsAfterRight, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR));
  }
  if (SDF_isSymbolLit(arg)) {
    return SDF_makeSymbolLit(
        acceptLiteral ? acceptLiteral(SDF_getSymbolLiteral(arg)) : SDF_getSymbolLiteral(arg));
  }
  if (SDF_isSymbolSort(arg)) {
    return SDF_makeSymbolSort(
        acceptSort ? acceptSort(SDF_getSymbolSort(arg)) : SDF_getSymbolSort(arg));
  }
  if (SDF_isSymbolParameterizedSort(arg)) {
    return SDF_makeSymbolParameterizedSort(
        acceptSort ? acceptSort(SDF_getSymbolSort(arg)) : SDF_getSymbolSort(arg),
        acceptWsAfterSort ? acceptWsAfterSort(SDF_getSymbolWsAfterSort(arg)) : SDF_getSymbolWsAfterSort(arg),
        acceptWsAfterBracketOpenBracketOpen ? acceptWsAfterBracketOpenBracketOpen(SDF_getSymbolWsAfterBracketOpenBracketOpen(arg)) : SDF_getSymbolWsAfterBracketOpenBracketOpen(arg),
        acceptParameters ? acceptParameters(SDF_getSymbolParameters(arg)) : SDF_getSymbolParameters(arg),
        acceptWsAfterParameters ? acceptWsAfterParameters(SDF_getSymbolWsAfterParameters(arg)) : SDF_getSymbolWsAfterParameters(arg));
  }
  if (SDF_isSymbolCharClass(arg)) {
    return SDF_makeSymbolCharClass(
        acceptCharClass ? acceptCharClass(SDF_getSymbolCharClass(arg)) : SDF_getSymbolCharClass(arg));
  }
  if (SDF_isSymbolLifting(arg)) {
    return SDF_makeSymbolLifting(
        acceptWsAfterLeftQuote ? acceptWsAfterLeftQuote(SDF_getSymbolWsAfterLeftQuote(arg)) : SDF_getSymbolWsAfterLeftQuote(arg),
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptLabel, acceptWsAfterLabel, acceptWsAfterColon, acceptLiteral, acceptSort, acceptWsAfterSort, acceptWsAfterBracketOpenBracketOpen, acceptParameters, acceptWsAfterParameters, acceptCharClass, acceptWsAfterLeftQuote, acceptWsAfterSymbol, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterLessThan, acceptWsAfterComma, acceptRest, acceptWsAfterRest, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterGreaterThan, acceptWsAfterRight, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(SDF_getSymbolWsAfterSymbol(arg)) : SDF_getSymbolWsAfterSymbol(arg));
  }
  if (SDF_isSymbolEmpty(arg)) {
    return SDF_makeSymbolEmpty(
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(SDF_getSymbolWsAfterParenOpen(arg)) : SDF_getSymbolWsAfterParenOpen(arg));
  }
  if (SDF_isSymbolSeq(arg)) {
    return SDF_makeSymbolSeq(
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(SDF_getSymbolWsAfterParenOpen(arg)) : SDF_getSymbolWsAfterParenOpen(arg),
        SDF_visitSymbol(SDF_getSymbolHead(arg), acceptLabel, acceptWsAfterLabel, acceptWsAfterColon, acceptLiteral, acceptSort, acceptWsAfterSort, acceptWsAfterBracketOpenBracketOpen, acceptParameters, acceptWsAfterParameters, acceptCharClass, acceptWsAfterLeftQuote, acceptWsAfterSymbol, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterLessThan, acceptWsAfterComma, acceptRest, acceptWsAfterRest, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterGreaterThan, acceptWsAfterRight, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR),
        acceptWsAfterHead ? acceptWsAfterHead(SDF_getSymbolWsAfterHead(arg)) : SDF_getSymbolWsAfterHead(arg),
        acceptTail ? acceptTail(SDF_getSymbolTail(arg)) : SDF_getSymbolTail(arg),
        acceptWsAfterTail ? acceptWsAfterTail(SDF_getSymbolWsAfterTail(arg)) : SDF_getSymbolWsAfterTail(arg));
  }
  if (SDF_isSymbolOpt(arg)) {
    return SDF_makeSymbolOpt(
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptLabel, acceptWsAfterLabel, acceptWsAfterColon, acceptLiteral, acceptSort, acceptWsAfterSort, acceptWsAfterBracketOpenBracketOpen, acceptParameters, acceptWsAfterParameters, acceptCharClass, acceptWsAfterLeftQuote, acceptWsAfterSymbol, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterLessThan, acceptWsAfterComma, acceptRest, acceptWsAfterRest, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterGreaterThan, acceptWsAfterRight, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(SDF_getSymbolWsAfterSymbol(arg)) : SDF_getSymbolWsAfterSymbol(arg));
  }
  if (SDF_isSymbolIter(arg)) {
    return SDF_makeSymbolIter(
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptLabel, acceptWsAfterLabel, acceptWsAfterColon, acceptLiteral, acceptSort, acceptWsAfterSort, acceptWsAfterBracketOpenBracketOpen, acceptParameters, acceptWsAfterParameters, acceptCharClass, acceptWsAfterLeftQuote, acceptWsAfterSymbol, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterLessThan, acceptWsAfterComma, acceptRest, acceptWsAfterRest, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterGreaterThan, acceptWsAfterRight, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(SDF_getSymbolWsAfterSymbol(arg)) : SDF_getSymbolWsAfterSymbol(arg));
  }
  if (SDF_isSymbolIterStar(arg)) {
    return SDF_makeSymbolIterStar(
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptLabel, acceptWsAfterLabel, acceptWsAfterColon, acceptLiteral, acceptSort, acceptWsAfterSort, acceptWsAfterBracketOpenBracketOpen, acceptParameters, acceptWsAfterParameters, acceptCharClass, acceptWsAfterLeftQuote, acceptWsAfterSymbol, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterLessThan, acceptWsAfterComma, acceptRest, acceptWsAfterRest, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterGreaterThan, acceptWsAfterRight, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(SDF_getSymbolWsAfterSymbol(arg)) : SDF_getSymbolWsAfterSymbol(arg));
  }
  if (SDF_isSymbolIterSep(arg)) {
    return SDF_makeSymbolIterSep(
        acceptWsAfterBraceOpen ? acceptWsAfterBraceOpen(SDF_getSymbolWsAfterBraceOpen(arg)) : SDF_getSymbolWsAfterBraceOpen(arg),
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptLabel, acceptWsAfterLabel, acceptWsAfterColon, acceptLiteral, acceptSort, acceptWsAfterSort, acceptWsAfterBracketOpenBracketOpen, acceptParameters, acceptWsAfterParameters, acceptCharClass, acceptWsAfterLeftQuote, acceptWsAfterSymbol, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterLessThan, acceptWsAfterComma, acceptRest, acceptWsAfterRest, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterGreaterThan, acceptWsAfterRight, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(SDF_getSymbolWsAfterSymbol(arg)) : SDF_getSymbolWsAfterSymbol(arg),
        SDF_visitSymbol(SDF_getSymbolSep(arg), acceptLabel, acceptWsAfterLabel, acceptWsAfterColon, acceptLiteral, acceptSort, acceptWsAfterSort, acceptWsAfterBracketOpenBracketOpen, acceptParameters, acceptWsAfterParameters, acceptCharClass, acceptWsAfterLeftQuote, acceptWsAfterSymbol, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterLessThan, acceptWsAfterComma, acceptRest, acceptWsAfterRest, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterGreaterThan, acceptWsAfterRight, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR),
        acceptWsAfterSep ? acceptWsAfterSep(SDF_getSymbolWsAfterSep(arg)) : SDF_getSymbolWsAfterSep(arg),
        acceptWsAfterBraceClose ? acceptWsAfterBraceClose(SDF_getSymbolWsAfterBraceClose(arg)) : SDF_getSymbolWsAfterBraceClose(arg));
  }
  if (SDF_isSymbolIterStarSep(arg)) {
    return SDF_makeSymbolIterStarSep(
        acceptWsAfterBraceOpen ? acceptWsAfterBraceOpen(SDF_getSymbolWsAfterBraceOpen(arg)) : SDF_getSymbolWsAfterBraceOpen(arg),
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptLabel, acceptWsAfterLabel, acceptWsAfterColon, acceptLiteral, acceptSort, acceptWsAfterSort, acceptWsAfterBracketOpenBracketOpen, acceptParameters, acceptWsAfterParameters, acceptCharClass, acceptWsAfterLeftQuote, acceptWsAfterSymbol, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterLessThan, acceptWsAfterComma, acceptRest, acceptWsAfterRest, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterGreaterThan, acceptWsAfterRight, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(SDF_getSymbolWsAfterSymbol(arg)) : SDF_getSymbolWsAfterSymbol(arg),
        SDF_visitSymbol(SDF_getSymbolSep(arg), acceptLabel, acceptWsAfterLabel, acceptWsAfterColon, acceptLiteral, acceptSort, acceptWsAfterSort, acceptWsAfterBracketOpenBracketOpen, acceptParameters, acceptWsAfterParameters, acceptCharClass, acceptWsAfterLeftQuote, acceptWsAfterSymbol, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterLessThan, acceptWsAfterComma, acceptRest, acceptWsAfterRest, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterGreaterThan, acceptWsAfterRight, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR),
        acceptWsAfterSep ? acceptWsAfterSep(SDF_getSymbolWsAfterSep(arg)) : SDF_getSymbolWsAfterSep(arg),
        acceptWsAfterBraceClose ? acceptWsAfterBraceClose(SDF_getSymbolWsAfterBraceClose(arg)) : SDF_getSymbolWsAfterBraceClose(arg));
  }
  if (SDF_isSymbolIterN(arg)) {
    return SDF_makeSymbolIterN(
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptLabel, acceptWsAfterLabel, acceptWsAfterColon, acceptLiteral, acceptSort, acceptWsAfterSort, acceptWsAfterBracketOpenBracketOpen, acceptParameters, acceptWsAfterParameters, acceptCharClass, acceptWsAfterLeftQuote, acceptWsAfterSymbol, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterLessThan, acceptWsAfterComma, acceptRest, acceptWsAfterRest, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterGreaterThan, acceptWsAfterRight, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(SDF_getSymbolWsAfterSymbol(arg)) : SDF_getSymbolWsAfterSymbol(arg),
        acceptN ? acceptN(SDF_getSymbolN(arg)) : SDF_getSymbolN(arg),
        acceptWsAfterN ? acceptWsAfterN(SDF_getSymbolWsAfterN(arg)) : SDF_getSymbolWsAfterN(arg));
  }
  if (SDF_isSymbolIterSepN(arg)) {
    return SDF_makeSymbolIterSepN(
        acceptWsAfterBraceOpen ? acceptWsAfterBraceOpen(SDF_getSymbolWsAfterBraceOpen(arg)) : SDF_getSymbolWsAfterBraceOpen(arg),
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptLabel, acceptWsAfterLabel, acceptWsAfterColon, acceptLiteral, acceptSort, acceptWsAfterSort, acceptWsAfterBracketOpenBracketOpen, acceptParameters, acceptWsAfterParameters, acceptCharClass, acceptWsAfterLeftQuote, acceptWsAfterSymbol, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterLessThan, acceptWsAfterComma, acceptRest, acceptWsAfterRest, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterGreaterThan, acceptWsAfterRight, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(SDF_getSymbolWsAfterSymbol(arg)) : SDF_getSymbolWsAfterSymbol(arg),
        SDF_visitSymbol(SDF_getSymbolSep(arg), acceptLabel, acceptWsAfterLabel, acceptWsAfterColon, acceptLiteral, acceptSort, acceptWsAfterSort, acceptWsAfterBracketOpenBracketOpen, acceptParameters, acceptWsAfterParameters, acceptCharClass, acceptWsAfterLeftQuote, acceptWsAfterSymbol, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterLessThan, acceptWsAfterComma, acceptRest, acceptWsAfterRest, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterGreaterThan, acceptWsAfterRight, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR),
        acceptWsAfterSep ? acceptWsAfterSep(SDF_getSymbolWsAfterSep(arg)) : SDF_getSymbolWsAfterSep(arg),
        acceptWsAfterBraceClose ? acceptWsAfterBraceClose(SDF_getSymbolWsAfterBraceClose(arg)) : SDF_getSymbolWsAfterBraceClose(arg),
        acceptN ? acceptN(SDF_getSymbolN(arg)) : SDF_getSymbolN(arg),
        acceptWsAfterN ? acceptWsAfterN(SDF_getSymbolWsAfterN(arg)) : SDF_getSymbolWsAfterN(arg));
  }
  if (SDF_isSymbolTuple(arg)) {
    return SDF_makeSymbolTuple(
        acceptWsAfterLessThan ? acceptWsAfterLessThan(SDF_getSymbolWsAfterLessThan(arg)) : SDF_getSymbolWsAfterLessThan(arg),
        SDF_visitSymbol(SDF_getSymbolHead(arg), acceptLabel, acceptWsAfterLabel, acceptWsAfterColon, acceptLiteral, acceptSort, acceptWsAfterSort, acceptWsAfterBracketOpenBracketOpen, acceptParameters, acceptWsAfterParameters, acceptCharClass, acceptWsAfterLeftQuote, acceptWsAfterSymbol, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterLessThan, acceptWsAfterComma, acceptRest, acceptWsAfterRest, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterGreaterThan, acceptWsAfterRight, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR),
        acceptWsAfterHead ? acceptWsAfterHead(SDF_getSymbolWsAfterHead(arg)) : SDF_getSymbolWsAfterHead(arg),
        acceptWsAfterComma ? acceptWsAfterComma(SDF_getSymbolWsAfterComma(arg)) : SDF_getSymbolWsAfterComma(arg),
        acceptRest ? acceptRest(SDF_getSymbolRest(arg)) : SDF_getSymbolRest(arg),
        acceptWsAfterRest ? acceptWsAfterRest(SDF_getSymbolWsAfterRest(arg)) : SDF_getSymbolWsAfterRest(arg));
  }
  if (SDF_isSymbolPair(arg)) {
    return SDF_makeSymbolPair(
        SDF_visitSymbol(SDF_getSymbolLeft(arg), acceptLabel, acceptWsAfterLabel, acceptWsAfterColon, acceptLiteral, acceptSort, acceptWsAfterSort, acceptWsAfterBracketOpenBracketOpen, acceptParameters, acceptWsAfterParameters, acceptCharClass, acceptWsAfterLeftQuote, acceptWsAfterSymbol, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterLessThan, acceptWsAfterComma, acceptRest, acceptWsAfterRest, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterGreaterThan, acceptWsAfterRight, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR),
        acceptWsAfterLeft ? acceptWsAfterLeft(SDF_getSymbolWsAfterLeft(arg)) : SDF_getSymbolWsAfterLeft(arg),
        acceptWsAfterHash ? acceptWsAfterHash(SDF_getSymbolWsAfterHash(arg)) : SDF_getSymbolWsAfterHash(arg),
        SDF_visitSymbol(SDF_getSymbolRight(arg), acceptLabel, acceptWsAfterLabel, acceptWsAfterColon, acceptLiteral, acceptSort, acceptWsAfterSort, acceptWsAfterBracketOpenBracketOpen, acceptParameters, acceptWsAfterParameters, acceptCharClass, acceptWsAfterLeftQuote, acceptWsAfterSymbol, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterLessThan, acceptWsAfterComma, acceptRest, acceptWsAfterRest, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterGreaterThan, acceptWsAfterRight, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR));
  }
  if (SDF_isSymbolFunc(arg)) {
    return SDF_makeSymbolFunc(
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(SDF_getSymbolWsAfterParenOpen(arg)) : SDF_getSymbolWsAfterParenOpen(arg),
        acceptArguments ? acceptArguments(SDF_getSymbolArguments(arg)) : SDF_getSymbolArguments(arg),
        acceptWsAfterArguments ? acceptWsAfterArguments(SDF_getSymbolWsAfterArguments(arg)) : SDF_getSymbolWsAfterArguments(arg),
        acceptWsAfterEqualsGreaterThan ? acceptWsAfterEqualsGreaterThan(SDF_getSymbolWsAfterEqualsGreaterThan(arg)) : SDF_getSymbolWsAfterEqualsGreaterThan(arg),
        SDF_visitSymbol(SDF_getSymbolResults(arg), acceptLabel, acceptWsAfterLabel, acceptWsAfterColon, acceptLiteral, acceptSort, acceptWsAfterSort, acceptWsAfterBracketOpenBracketOpen, acceptParameters, acceptWsAfterParameters, acceptCharClass, acceptWsAfterLeftQuote, acceptWsAfterSymbol, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterLessThan, acceptWsAfterComma, acceptRest, acceptWsAfterRest, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterGreaterThan, acceptWsAfterRight, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR),
        acceptWsAfterResults ? acceptWsAfterResults(SDF_getSymbolWsAfterResults(arg)) : SDF_getSymbolWsAfterResults(arg));
  }
  if (SDF_isSymbolAlt(arg)) {
    return SDF_makeSymbolAlt(
        SDF_visitSymbol(SDF_getSymbolLeft(arg), acceptLabel, acceptWsAfterLabel, acceptWsAfterColon, acceptLiteral, acceptSort, acceptWsAfterSort, acceptWsAfterBracketOpenBracketOpen, acceptParameters, acceptWsAfterParameters, acceptCharClass, acceptWsAfterLeftQuote, acceptWsAfterSymbol, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterLessThan, acceptWsAfterComma, acceptRest, acceptWsAfterRest, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterGreaterThan, acceptWsAfterRight, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR),
        acceptWsAfterLeft ? acceptWsAfterLeft(SDF_getSymbolWsAfterLeft(arg)) : SDF_getSymbolWsAfterLeft(arg),
        acceptWsAfterBar ? acceptWsAfterBar(SDF_getSymbolWsAfterBar(arg)) : SDF_getSymbolWsAfterBar(arg),
        SDF_visitSymbol(SDF_getSymbolRight(arg), acceptLabel, acceptWsAfterLabel, acceptWsAfterColon, acceptLiteral, acceptSort, acceptWsAfterSort, acceptWsAfterBracketOpenBracketOpen, acceptParameters, acceptWsAfterParameters, acceptCharClass, acceptWsAfterLeftQuote, acceptWsAfterSymbol, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterLessThan, acceptWsAfterComma, acceptRest, acceptWsAfterRest, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterGreaterThan, acceptWsAfterRight, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR));
  }
  if (SDF_isSymbolStrategy(arg)) {
    return SDF_makeSymbolStrategy(
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(SDF_getSymbolWsAfterParenOpen(arg)) : SDF_getSymbolWsAfterParenOpen(arg),
        SDF_visitSymbol(SDF_getSymbolLeft(arg), acceptLabel, acceptWsAfterLabel, acceptWsAfterColon, acceptLiteral, acceptSort, acceptWsAfterSort, acceptWsAfterBracketOpenBracketOpen, acceptParameters, acceptWsAfterParameters, acceptCharClass, acceptWsAfterLeftQuote, acceptWsAfterSymbol, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterLessThan, acceptWsAfterComma, acceptRest, acceptWsAfterRest, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterGreaterThan, acceptWsAfterRight, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR),
        acceptWsAfterLeft ? acceptWsAfterLeft(SDF_getSymbolWsAfterLeft(arg)) : SDF_getSymbolWsAfterLeft(arg),
        acceptWsAfterGreaterThan ? acceptWsAfterGreaterThan(SDF_getSymbolWsAfterGreaterThan(arg)) : SDF_getSymbolWsAfterGreaterThan(arg),
        SDF_visitSymbol(SDF_getSymbolRight(arg), acceptLabel, acceptWsAfterLabel, acceptWsAfterColon, acceptLiteral, acceptSort, acceptWsAfterSort, acceptWsAfterBracketOpenBracketOpen, acceptParameters, acceptWsAfterParameters, acceptCharClass, acceptWsAfterLeftQuote, acceptWsAfterSymbol, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterLessThan, acceptWsAfterComma, acceptRest, acceptWsAfterRest, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterGreaterThan, acceptWsAfterRight, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR),
        acceptWsAfterRight ? acceptWsAfterRight(SDF_getSymbolWsAfterRight(arg)) : SDF_getSymbolWsAfterRight(arg));
  }
  if (SDF_isSymbolCf(arg)) {
    return SDF_makeSymbolCf(
        acceptWsAfterLessThan ? acceptWsAfterLessThan(SDF_getSymbolWsAfterLessThan(arg)) : SDF_getSymbolWsAfterLessThan(arg),
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptLabel, acceptWsAfterLabel, acceptWsAfterColon, acceptLiteral, acceptSort, acceptWsAfterSort, acceptWsAfterBracketOpenBracketOpen, acceptParameters, acceptWsAfterParameters, acceptCharClass, acceptWsAfterLeftQuote, acceptWsAfterSymbol, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterLessThan, acceptWsAfterComma, acceptRest, acceptWsAfterRest, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterGreaterThan, acceptWsAfterRight, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(SDF_getSymbolWsAfterSymbol(arg)) : SDF_getSymbolWsAfterSymbol(arg),
        acceptWsAfterCF ? acceptWsAfterCF(SDF_getSymbolWsAfterCF(arg)) : SDF_getSymbolWsAfterCF(arg));
  }
  if (SDF_isSymbolLex(arg)) {
    return SDF_makeSymbolLex(
        acceptWsAfterLessThan ? acceptWsAfterLessThan(SDF_getSymbolWsAfterLessThan(arg)) : SDF_getSymbolWsAfterLessThan(arg),
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptLabel, acceptWsAfterLabel, acceptWsAfterColon, acceptLiteral, acceptSort, acceptWsAfterSort, acceptWsAfterBracketOpenBracketOpen, acceptParameters, acceptWsAfterParameters, acceptCharClass, acceptWsAfterLeftQuote, acceptWsAfterSymbol, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterLessThan, acceptWsAfterComma, acceptRest, acceptWsAfterRest, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterGreaterThan, acceptWsAfterRight, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(SDF_getSymbolWsAfterSymbol(arg)) : SDF_getSymbolWsAfterSymbol(arg),
        acceptWsAfterLEX ? acceptWsAfterLEX(SDF_getSymbolWsAfterLEX(arg)) : SDF_getSymbolWsAfterLEX(arg));
  }
  if (SDF_isSymbolVarsym(arg)) {
    return SDF_makeSymbolVarsym(
        acceptWsAfterLessThan ? acceptWsAfterLessThan(SDF_getSymbolWsAfterLessThan(arg)) : SDF_getSymbolWsAfterLessThan(arg),
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptLabel, acceptWsAfterLabel, acceptWsAfterColon, acceptLiteral, acceptSort, acceptWsAfterSort, acceptWsAfterBracketOpenBracketOpen, acceptParameters, acceptWsAfterParameters, acceptCharClass, acceptWsAfterLeftQuote, acceptWsAfterSymbol, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterLessThan, acceptWsAfterComma, acceptRest, acceptWsAfterRest, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterGreaterThan, acceptWsAfterRight, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(SDF_getSymbolWsAfterSymbol(arg)) : SDF_getSymbolWsAfterSymbol(arg),
        acceptWsAfterVAR ? acceptWsAfterVAR(SDF_getSymbolWsAfterVAR(arg)) : SDF_getSymbolWsAfterVAR(arg));
  }
  if (SDF_isSymbolLayout(arg)) {
    return SDF_makeSymbolLayout();
  }
  if (SDF_isSymbolBracket(arg)) {
    return SDF_makeSymbolBracket(
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(SDF_getSymbolWsAfterParenOpen(arg)) : SDF_getSymbolWsAfterParenOpen(arg),
        SDF_visitSymbol(SDF_getSymbolSymbol(arg), acceptLabel, acceptWsAfterLabel, acceptWsAfterColon, acceptLiteral, acceptSort, acceptWsAfterSort, acceptWsAfterBracketOpenBracketOpen, acceptParameters, acceptWsAfterParameters, acceptCharClass, acceptWsAfterLeftQuote, acceptWsAfterSymbol, acceptWsAfterParenOpen, acceptWsAfterHead, acceptTail, acceptWsAfterTail, acceptWsAfterBraceOpen, acceptWsAfterSep, acceptWsAfterBraceClose, acceptN, acceptWsAfterN, acceptWsAfterLessThan, acceptWsAfterComma, acceptRest, acceptWsAfterRest, acceptWsAfterLeft, acceptWsAfterHash, acceptArguments, acceptWsAfterArguments, acceptWsAfterEqualsGreaterThan, acceptWsAfterResults, acceptWsAfterBar, acceptWsAfterGreaterThan, acceptWsAfterRight, acceptWsAfterCF, acceptWsAfterLEX, acceptWsAfterVAR),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(SDF_getSymbolWsAfterSymbol(arg)) : SDF_getSymbolWsAfterSymbol(arg));
  }
  if (SDF_isSymbolStart(arg)) {
    return SDF_makeSymbolStart();
  }
  if (SDF_isSymbolFileStart(arg)) {
    return SDF_makeSymbolFileStart();
  }
  ATabort("not a Symbol: %t\n", arg);
  return (SDF_Symbol)NULL;
}

/*}}}  */
/*{{{  SDF_Production SDF_visitProduction(SDF_Production arg, SDF_Literal (*acceptFunctionSymbol)(SDF_Literal), SDF_OptLayout (*acceptWsAfterFunctionSymbol)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_SymbolArguments (*acceptArguments)(SDF_SymbolArguments), SDF_OptLayout (*acceptWsAfterArguments)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenClose)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterGreaterThan)(SDF_OptLayout), SDF_Symbol (*acceptResult)(SDF_Symbol), SDF_OptLayout (*acceptWsAfterResult)(SDF_OptLayout), SDF_Attributes (*acceptAttributes)(SDF_Attributes), SDF_Symbols (*acceptSymbols)(SDF_Symbols), SDF_OptLayout (*acceptWsAfterSymbols)(SDF_OptLayout)) */

SDF_Production SDF_visitProduction(SDF_Production arg, SDF_Literal (*acceptFunctionSymbol)(SDF_Literal), SDF_OptLayout (*acceptWsAfterFunctionSymbol)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_SymbolArguments (*acceptArguments)(SDF_SymbolArguments), SDF_OptLayout (*acceptWsAfterArguments)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenClose)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterGreaterThan)(SDF_OptLayout), SDF_Symbol (*acceptResult)(SDF_Symbol), SDF_OptLayout (*acceptWsAfterResult)(SDF_OptLayout), SDF_Attributes (*acceptAttributes)(SDF_Attributes), SDF_Symbols (*acceptSymbols)(SDF_Symbols), SDF_OptLayout (*acceptWsAfterSymbols)(SDF_OptLayout))
{
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
  if (SDF_isProductionProd(arg)) {
    return SDF_makeProductionProd(
        acceptSymbols ? acceptSymbols(SDF_getProductionSymbols(arg)) : SDF_getProductionSymbols(arg),
        acceptWsAfterSymbols ? acceptWsAfterSymbols(SDF_getProductionWsAfterSymbols(arg)) : SDF_getProductionWsAfterSymbols(arg),
        acceptWsAfterGreaterThan ? acceptWsAfterGreaterThan(SDF_getProductionWsAfterGreaterThan(arg)) : SDF_getProductionWsAfterGreaterThan(arg),
        acceptResult ? acceptResult(SDF_getProductionResult(arg)) : SDF_getProductionResult(arg),
        acceptWsAfterResult ? acceptWsAfterResult(SDF_getProductionWsAfterResult(arg)) : SDF_getProductionWsAfterResult(arg),
        acceptAttributes ? acceptAttributes(SDF_getProductionAttributes(arg)) : SDF_getProductionAttributes(arg));
  }
  ATabort("not a Production: %t\n", arg);
  return (SDF_Production)NULL;
}

/*}}}  */
/*{{{  SDF_SymbolArguments SDF_visitSymbolArguments(SDF_SymbolArguments arg, SDF_Symbol (*acceptHead)(SDF_Symbol), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout)) */

SDF_SymbolArguments SDF_visitSymbolArguments(SDF_SymbolArguments arg, SDF_Symbol (*acceptHead)(SDF_Symbol), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout))
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
/*{{{  SDF_Sort SDF_visitSort(SDF_Sort arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST)) */

SDF_Sort SDF_visitSort(SDF_Sort arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST))
{
  if (SDF_isSortOneChar(arg)) {
    return SDF_makeSortOneChar(
        acceptChars ? acceptChars(SDF_getSortChars(arg)) : SDF_getSortChars(arg));
  }
  if (SDF_isSortMoreChars(arg)) {
    return SDF_makeSortMoreChars(
        acceptChars ? acceptChars(SDF_getSortChars(arg)) : SDF_getSortChars(arg));
  }
  ATabort("not a Sort: %t\n", arg);
  return (SDF_Sort)NULL;
}

/*}}}  */
/*{{{  SDF_SymbolParameters SDF_visitSymbolParameters(SDF_SymbolParameters arg, SDF_Symbol (*acceptHead)(SDF_Symbol), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout)) */

SDF_SymbolParameters SDF_visitSymbolParameters(SDF_SymbolParameters arg, SDF_Symbol (*acceptHead)(SDF_Symbol), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout))
{
  if (SDF_isSymbolParametersSingle(arg)) {
    return SDF_makeSymbolParametersSingle(
        acceptHead ? acceptHead(SDF_getSymbolParametersHead(arg)) : SDF_getSymbolParametersHead(arg));
  }
  if (SDF_isSymbolParametersMany(arg)) {
    return SDF_makeSymbolParametersMany(
        acceptHead ? acceptHead(SDF_getSymbolParametersHead(arg)) : SDF_getSymbolParametersHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(SDF_getSymbolParametersWsAfterFirst(arg)) : SDF_getSymbolParametersWsAfterFirst(arg),
        acceptSep ? acceptSep(SDF_getSymbolParametersSep(arg)) : SDF_getSymbolParametersSep(arg),
        acceptWsAfterSep ? acceptWsAfterSep(SDF_getSymbolParametersWsAfterSep(arg)) : SDF_getSymbolParametersWsAfterSep(arg),
        SDF_visitSymbolParameters(SDF_getSymbolParametersTail(arg), acceptHead, acceptWsAfterFirst, acceptSep, acceptWsAfterSep));
  }
  ATabort("not a SymbolParameters: %t\n", arg);
  return (SDF_SymbolParameters)NULL;
}

/*}}}  */
/*{{{  SDF_NumChar SDF_visitNumChar(SDF_NumChar arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST)) */

SDF_NumChar SDF_visitNumChar(SDF_NumChar arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST))
{
  if (SDF_isNumCharDigits(arg)) {
    return SDF_makeNumCharDigits(
        acceptChars ? acceptChars(SDF_getNumCharChars(arg)) : SDF_getNumCharChars(arg));
  }
  ATabort("not a NumChar: %t\n", arg);
  return (SDF_NumChar)NULL;
}

/*}}}  */
/*{{{  SDF_ShortChar SDF_visitShortChar(SDF_ShortChar arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST)) */

SDF_ShortChar SDF_visitShortChar(SDF_ShortChar arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST))
{
  if (SDF_isShortCharRegular(arg)) {
    return SDF_makeShortCharRegular(
        acceptChars ? acceptChars(SDF_getShortCharChars(arg)) : SDF_getShortCharChars(arg));
  }
  if (SDF_isShortCharEscaped(arg)) {
    return SDF_makeShortCharEscaped(
        acceptChars ? acceptChars(SDF_getShortCharChars(arg)) : SDF_getShortCharChars(arg));
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
  if (SDF_isCharacterBot(arg)) {
    return SDF_makeCharacterBot();
  }
  if (SDF_isCharacterLabelUnderscoreStart(arg)) {
    return SDF_makeCharacterLabelUnderscoreStart();
  }
  ATabort("not a Character: %t\n", arg);
  return (SDF_Character)NULL;
}

/*}}}  */
/*{{{  SDF_CharRange SDF_visitCharRange(SDF_CharRange arg, SDF_Character (*acceptCharacter)(SDF_Character), SDF_Character (*acceptStart)(SDF_Character), SDF_OptLayout (*acceptWsAfterStart)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfter)(SDF_OptLayout), SDF_Character (*acceptEnd)(SDF_Character)) */

SDF_CharRange SDF_visitCharRange(SDF_CharRange arg, SDF_Character (*acceptCharacter)(SDF_Character), SDF_Character (*acceptStart)(SDF_Character), SDF_OptLayout (*acceptWsAfterStart)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfter)(SDF_OptLayout), SDF_Character (*acceptEnd)(SDF_Character))
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
/*{{{  SDF_CharRanges SDF_visitCharRanges(SDF_CharRanges arg, SDF_CharRange (*acceptCharRange)(SDF_CharRange), SDF_OptLayout (*acceptWsAfterLeft)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterCharRanges)(SDF_OptLayout)) */

SDF_CharRanges SDF_visitCharRanges(SDF_CharRanges arg, SDF_CharRange (*acceptCharRange)(SDF_CharRange), SDF_OptLayout (*acceptWsAfterLeft)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterCharRanges)(SDF_OptLayout))
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
/*{{{  SDF_CharClass SDF_visitCharClass(SDF_CharClass arg, SDF_OptLayout (*acceptWsAfterBracketOpen)(SDF_OptLayout), SDF_OptCharRanges (*acceptOptCharRanges)(SDF_OptCharRanges), SDF_OptLayout (*acceptWsAfterOptCharRanges)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterTilde)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterLeft)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterSlash)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterSlashBackslash)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterBackslashSlash)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterCharClass)(SDF_OptLayout)) */

SDF_CharClass SDF_visitCharClass(SDF_CharClass arg, SDF_OptLayout (*acceptWsAfterBracketOpen)(SDF_OptLayout), SDF_OptCharRanges (*acceptOptCharRanges)(SDF_OptCharRanges), SDF_OptLayout (*acceptWsAfterOptCharRanges)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterTilde)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterLeft)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterSlash)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterSlashBackslash)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterBackslashSlash)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterCharClass)(SDF_OptLayout))
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
  if (SDF_isCharClassDefault(arg)) {
    return SDF_makeCharClassDefault(
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(SDF_getCharClassWsAfterParenOpen(arg)) : SDF_getCharClassWsAfterParenOpen(arg),
        SDF_visitCharClass(SDF_getCharClassCharClass(arg), acceptWsAfterBracketOpen, acceptOptCharRanges, acceptWsAfterOptCharRanges, acceptWsAfterTilde, acceptWsAfterLeft, acceptWsAfterSlash, acceptWsAfterSlashBackslash, acceptWsAfterBackslashSlash, acceptWsAfterParenOpen, acceptWsAfterCharClass),
        acceptWsAfterCharClass ? acceptWsAfterCharClass(SDF_getCharClassWsAfterCharClass(arg)) : SDF_getCharClassWsAfterCharClass(arg));
  }
  ATabort("not a CharClass: %t\n", arg);
  return (SDF_CharClass)NULL;
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
/*{{{  SDF_Group SDF_visitGroup(SDF_Group arg, SDF_Production (*acceptProduction)(SDF_Production), SDF_OptLayout (*acceptWsAfterBraceOpen)(SDF_OptLayout), SDF_Productions (*acceptProductions)(SDF_Productions), SDF_OptLayout (*acceptWsAfterProductions)(SDF_OptLayout), SDF_Associativity (*acceptAssociativity)(SDF_Associativity), SDF_OptLayout (*acceptWsAfterAssociativity)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterColon)(SDF_OptLayout)) */

SDF_Group SDF_visitGroup(SDF_Group arg, SDF_Production (*acceptProduction)(SDF_Production), SDF_OptLayout (*acceptWsAfterBraceOpen)(SDF_OptLayout), SDF_Productions (*acceptProductions)(SDF_Productions), SDF_OptLayout (*acceptWsAfterProductions)(SDF_OptLayout), SDF_Associativity (*acceptAssociativity)(SDF_Associativity), SDF_OptLayout (*acceptWsAfterAssociativity)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterColon)(SDF_OptLayout))
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
/*{{{  SDF_Priority SDF_visitPriority(SDF_Priority arg, SDF_GroupList (*acceptList)(SDF_GroupList), SDF_Group (*acceptLeft)(SDF_Group), SDF_OptLayout (*acceptWsAfterLeft)(SDF_OptLayout), SDF_Associativity (*acceptAssociativity)(SDF_Associativity), SDF_OptLayout (*acceptWsAfterAssociativity)(SDF_OptLayout), SDF_Group (*acceptRight)(SDF_Group)) */

SDF_Priority SDF_visitPriority(SDF_Priority arg, SDF_GroupList (*acceptList)(SDF_GroupList), SDF_Group (*acceptLeft)(SDF_Group), SDF_OptLayout (*acceptWsAfterLeft)(SDF_OptLayout), SDF_Associativity (*acceptAssociativity)(SDF_Associativity), SDF_OptLayout (*acceptWsAfterAssociativity)(SDF_OptLayout), SDF_Group (*acceptRight)(SDF_Group))
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
/*{{{  SDF_GroupList SDF_visitGroupList(SDF_GroupList arg, SDF_Group (*acceptHead)(SDF_Group), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout)) */

SDF_GroupList SDF_visitGroupList(SDF_GroupList arg, SDF_Group (*acceptHead)(SDF_Group), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout))
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
/*{{{  SDF_PriorityList SDF_visitPriorityList(SDF_PriorityList arg, SDF_Priority (*acceptHead)(SDF_Priority), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout)) */

SDF_PriorityList SDF_visitPriorityList(SDF_PriorityList arg, SDF_Priority (*acceptHead)(SDF_Priority), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout))
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
/*{{{  SDF_SymbolTail SDF_visitSymbolTail(SDF_SymbolTail arg, SDF_Symbol (*acceptHead)(SDF_Symbol), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout)) */

SDF_SymbolTail SDF_visitSymbolTail(SDF_SymbolTail arg, SDF_Symbol (*acceptHead)(SDF_Symbol), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout))
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
/*{{{  SDF_SymbolRest SDF_visitSymbolRest(SDF_SymbolRest arg, SDF_Symbol (*acceptHead)(SDF_Symbol), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout)) */

SDF_SymbolRest SDF_visitSymbolRest(SDF_SymbolRest arg, SDF_Symbol (*acceptHead)(SDF_Symbol), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout))
{
  if (SDF_isSymbolRestSingle(arg)) {
    return SDF_makeSymbolRestSingle(
        acceptHead ? acceptHead(SDF_getSymbolRestHead(arg)) : SDF_getSymbolRestHead(arg));
  }
  if (SDF_isSymbolRestMany(arg)) {
    return SDF_makeSymbolRestMany(
        acceptHead ? acceptHead(SDF_getSymbolRestHead(arg)) : SDF_getSymbolRestHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(SDF_getSymbolRestWsAfterFirst(arg)) : SDF_getSymbolRestWsAfterFirst(arg),
        acceptSep ? acceptSep(SDF_getSymbolRestSep(arg)) : SDF_getSymbolRestSep(arg),
        acceptWsAfterSep ? acceptWsAfterSep(SDF_getSymbolRestWsAfterSep(arg)) : SDF_getSymbolRestWsAfterSep(arg),
        SDF_visitSymbolRest(SDF_getSymbolRestTail(arg), acceptHead, acceptWsAfterFirst, acceptSep, acceptWsAfterSep));
  }
  ATabort("not a SymbolRest: %t\n", arg);
  return (SDF_SymbolRest)NULL;
}

/*}}}  */
/*{{{  SDF_Renamings SDF_visitRenamings(SDF_Renamings arg, SDF_OptLayout (*acceptWsAfterBracketOpen)(SDF_OptLayout), SDF_RenamingList (*acceptList)(SDF_RenamingList), SDF_OptLayout (*acceptWsAfterList)(SDF_OptLayout)) */

SDF_Renamings SDF_visitRenamings(SDF_Renamings arg, SDF_OptLayout (*acceptWsAfterBracketOpen)(SDF_OptLayout), SDF_RenamingList (*acceptList)(SDF_RenamingList), SDF_OptLayout (*acceptWsAfterList)(SDF_OptLayout))
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
/*{{{  SDF_RenamingList SDF_visitRenamingList(SDF_RenamingList arg, SDF_Renaming (*acceptHead)(SDF_Renaming), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout)) */

SDF_RenamingList SDF_visitRenamingList(SDF_RenamingList arg, SDF_Renaming (*acceptHead)(SDF_Renaming), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout))
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
/*{{{  SDF_Renaming SDF_visitRenaming(SDF_Renaming arg, SDF_Symbol (*acceptFrom)(SDF_Symbol), SDF_OptLayout (*acceptWsAfterFrom)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterEqualsGreaterThan)(SDF_OptLayout), SDF_Symbol (*acceptTo)(SDF_Symbol), SDF_Production (*acceptFromProd)(SDF_Production), SDF_OptLayout (*acceptWsAfterFromProd)(SDF_OptLayout), SDF_Production (*acceptToProd)(SDF_Production)) */

SDF_Renaming SDF_visitRenaming(SDF_Renaming arg, SDF_Symbol (*acceptFrom)(SDF_Symbol), SDF_OptLayout (*acceptWsAfterFrom)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterEqualsGreaterThan)(SDF_OptLayout), SDF_Symbol (*acceptTo)(SDF_Symbol), SDF_Production (*acceptFromProd)(SDF_Production), SDF_OptLayout (*acceptWsAfterFromProd)(SDF_OptLayout), SDF_Production (*acceptToProd)(SDF_Production))
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
        acceptFromProd ? acceptFromProd(SDF_getRenamingFromProd(arg)) : SDF_getRenamingFromProd(arg),
        acceptWsAfterFromProd ? acceptWsAfterFromProd(SDF_getRenamingWsAfterFromProd(arg)) : SDF_getRenamingWsAfterFromProd(arg),
        acceptWsAfterEqualsGreaterThan ? acceptWsAfterEqualsGreaterThan(SDF_getRenamingWsAfterEqualsGreaterThan(arg)) : SDF_getRenamingWsAfterEqualsGreaterThan(arg),
        acceptToProd ? acceptToProd(SDF_getRenamingToProd(arg)) : SDF_getRenamingToProd(arg));
  }
  ATabort("not a Renaming: %t\n", arg);
  return (SDF_Renaming)NULL;
}

/*}}}  */
/*{{{  SDF_ModuleWord SDF_visitModuleWord(SDF_ModuleWord arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST)) */

SDF_ModuleWord SDF_visitModuleWord(SDF_ModuleWord arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST))
{
  if (SDF_isModuleWordWord(arg)) {
    return SDF_makeModuleWordWord(
        acceptChars ? acceptChars(SDF_getModuleWordChars(arg)) : SDF_getModuleWordChars(arg));
  }
  ATabort("not a ModuleWord: %t\n", arg);
  return (SDF_ModuleWord)NULL;
}

/*}}}  */
/*{{{  SDF_ModuleId SDF_visitModuleId(SDF_ModuleId arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST)) */

SDF_ModuleId SDF_visitModuleId(SDF_ModuleId arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST))
{
  if (SDF_isModuleIdWord(arg)) {
    return SDF_makeModuleIdWord(
        acceptChars ? acceptChars(SDF_getModuleIdChars(arg)) : SDF_getModuleIdChars(arg));
  }
  if (SDF_isModuleIdSlashWord(arg)) {
    return SDF_makeModuleIdSlashWord(
        acceptChars ? acceptChars(SDF_getModuleIdChars(arg)) : SDF_getModuleIdChars(arg));
  }
  if (SDF_isModuleIdWordSlashWord(arg)) {
    return SDF_makeModuleIdWordSlashWord(
        acceptChars ? acceptChars(SDF_getModuleIdChars(arg)) : SDF_getModuleIdChars(arg));
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
/*{{{  SDF_ModuleList SDF_visitModuleList(SDF_ModuleList arg, SDF_Module (*acceptHead)(SDF_Module), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout)) */

SDF_ModuleList SDF_visitModuleList(SDF_ModuleList arg, SDF_Module (*acceptHead)(SDF_Module), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout))
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
/*{{{  SDF_Module SDF_visitModule(SDF_Module arg, SDF_OptLayout (*acceptWsAfterModule)(SDF_OptLayout), SDF_ModuleName (*acceptModuleName)(SDF_ModuleName), SDF_OptLayout (*acceptWsAfterModuleName)(SDF_OptLayout), SDF_ImpSectionList (*acceptList)(SDF_ImpSectionList), SDF_OptLayout (*acceptWsAfterList)(SDF_OptLayout), SDF_Sections (*acceptSections)(SDF_Sections)) */

SDF_Module SDF_visitModule(SDF_Module arg, SDF_OptLayout (*acceptWsAfterModule)(SDF_OptLayout), SDF_ModuleName (*acceptModuleName)(SDF_ModuleName), SDF_OptLayout (*acceptWsAfterModuleName)(SDF_OptLayout), SDF_ImpSectionList (*acceptList)(SDF_ImpSectionList), SDF_OptLayout (*acceptWsAfterList)(SDF_OptLayout), SDF_Sections (*acceptSections)(SDF_Sections))
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
/*{{{  SDF_ImpSectionList SDF_visitImpSectionList(SDF_ImpSectionList arg, SDF_ImpSection (*acceptHead)(SDF_ImpSection), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout)) */

SDF_ImpSectionList SDF_visitImpSectionList(SDF_ImpSectionList arg, SDF_ImpSection (*acceptHead)(SDF_ImpSection), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout))
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
/*{{{  SDF_Section SDF_visitSection(SDF_Section arg, SDF_OptLayout (*acceptWsAfterExports)(SDF_OptLayout), SDF_Grammar (*acceptGrammar)(SDF_Grammar), SDF_OptLayout (*acceptWsAfterHiddens)(SDF_OptLayout)) */

SDF_Section SDF_visitSection(SDF_Section arg, SDF_OptLayout (*acceptWsAfterExports)(SDF_OptLayout), SDF_Grammar (*acceptGrammar)(SDF_Grammar), SDF_OptLayout (*acceptWsAfterHiddens)(SDF_OptLayout))
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
/*{{{  SDF_SectionList SDF_visitSectionList(SDF_SectionList arg, SDF_Section (*acceptHead)(SDF_Section), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout)) */

SDF_SectionList SDF_visitSectionList(SDF_SectionList arg, SDF_Section (*acceptHead)(SDF_Section), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout))
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
/*{{{  SDF_ModuleName SDF_visitModuleName(SDF_ModuleName arg, SDF_ModuleId (*acceptModuleId)(SDF_ModuleId), SDF_OptLayout (*acceptWsAfterModuleId)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterBracketOpen)(SDF_OptLayout), SDF_Symbols (*acceptParams)(SDF_Symbols), SDF_OptLayout (*acceptWsAfterParams)(SDF_OptLayout)) */

SDF_ModuleName SDF_visitModuleName(SDF_ModuleName arg, SDF_ModuleId (*acceptModuleId)(SDF_ModuleId), SDF_OptLayout (*acceptWsAfterModuleId)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterBracketOpen)(SDF_OptLayout), SDF_Symbols (*acceptParams)(SDF_Symbols), SDF_OptLayout (*acceptWsAfterParams)(SDF_OptLayout))
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
/*{{{  SDF_ImpSection SDF_visitImpSection(SDF_ImpSection arg, SDF_OptLayout (*acceptWsAfterImports)(SDF_OptLayout), SDF_Imports (*acceptList)(SDF_Imports)) */

SDF_ImpSection SDF_visitImpSection(SDF_ImpSection arg, SDF_OptLayout (*acceptWsAfterImports)(SDF_OptLayout), SDF_Imports (*acceptList)(SDF_Imports))
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
/*{{{  SDF_ImportList SDF_visitImportList(SDF_ImportList arg, SDF_Import (*acceptHead)(SDF_Import), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout)) */

SDF_ImportList SDF_visitImportList(SDF_ImportList arg, SDF_Import (*acceptHead)(SDF_Import), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout))
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
/*{{{  SDF_Import SDF_visitImport(SDF_Import arg, SDF_ModuleName (*acceptModuleName)(SDF_ModuleName), SDF_OptLayout (*acceptWsAfterModuleName)(SDF_OptLayout), SDF_Renamings (*acceptRenamings)(SDF_Renamings), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterImport)(SDF_OptLayout)) */

SDF_Import SDF_visitImport(SDF_Import arg, SDF_ModuleName (*acceptModuleName)(SDF_ModuleName), SDF_OptLayout (*acceptWsAfterModuleName)(SDF_OptLayout), SDF_Renamings (*acceptRenamings)(SDF_Renamings), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterImport)(SDF_OptLayout))
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
/*{{{  SDF_SymbolList SDF_visitSymbolList(SDF_SymbolList arg, SDF_Symbol (*acceptHead)(SDF_Symbol), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout)) */

SDF_SymbolList SDF_visitSymbolList(SDF_SymbolList arg, SDF_Symbol (*acceptHead)(SDF_Symbol), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout))
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
/*{{{  SDF_OptExp SDF_visitOptExp(SDF_OptExp arg, SDF_OptLayout (*acceptWsAfterE)(SDF_OptLayout), SDF_IntCon (*acceptIntCon)(SDF_IntCon)) */

SDF_OptExp SDF_visitOptExp(SDF_OptExp arg, SDF_OptLayout (*acceptWsAfterE)(SDF_OptLayout), SDF_IntCon (*acceptIntCon)(SDF_IntCon))
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
/*{{{  SDF_RealCon SDF_visitRealCon(SDF_RealCon arg, SDF_IntCon (*acceptIntCon)(SDF_IntCon), SDF_OptLayout (*acceptWsAfterIntCon)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterPeriod)(SDF_OptLayout), SDF_NatCon (*acceptNatCon)(SDF_NatCon), SDF_OptLayout (*acceptWsAfterNatCon)(SDF_OptLayout), SDF_OptExp (*acceptOptExp)(SDF_OptExp)) */

SDF_RealCon SDF_visitRealCon(SDF_RealCon arg, SDF_IntCon (*acceptIntCon)(SDF_IntCon), SDF_OptLayout (*acceptWsAfterIntCon)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterPeriod)(SDF_OptLayout), SDF_NatCon (*acceptNatCon)(SDF_NatCon), SDF_OptLayout (*acceptWsAfterNatCon)(SDF_OptLayout), SDF_OptExp (*acceptOptExp)(SDF_OptExp))
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
/*{{{  SDF_NatCon SDF_visitNatCon(SDF_NatCon arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST)) */

SDF_NatCon SDF_visitNatCon(SDF_NatCon arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST))
{
  if (SDF_isNatConDigits(arg)) {
    return SDF_makeNatConDigits(
        acceptChars ? acceptChars(SDF_getNatConChars(arg)) : SDF_getNatConChars(arg));
  }
  ATabort("not a NatCon: %t\n", arg);
  return (SDF_NatCon)NULL;
}

/*}}}  */
/*{{{  SDF_IntCon SDF_visitIntCon(SDF_IntCon arg, SDF_NatCon (*acceptNatCon)(SDF_NatCon), SDF_OptLayout (*acceptWsAfterPos)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterNeg)(SDF_OptLayout)) */

SDF_IntCon SDF_visitIntCon(SDF_IntCon arg, SDF_NatCon (*acceptNatCon)(SDF_NatCon), SDF_OptLayout (*acceptWsAfterPos)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterNeg)(SDF_OptLayout))
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
/*{{{  SDF_AlphaNumericalEscChar SDF_visitAlphaNumericalEscChar(SDF_AlphaNumericalEscChar arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST)) */

SDF_AlphaNumericalEscChar SDF_visitAlphaNumericalEscChar(SDF_AlphaNumericalEscChar arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST))
{
  if (SDF_isAlphaNumericalEscCharDefault(arg)) {
    return SDF_makeAlphaNumericalEscCharDefault(
        acceptChars ? acceptChars(SDF_getAlphaNumericalEscCharChars(arg)) : SDF_getAlphaNumericalEscCharChars(arg));
  }
  ATabort("not a AlphaNumericalEscChar: %t\n", arg);
  return (SDF_AlphaNumericalEscChar)NULL;
}

/*}}}  */
/*{{{  SDF_DecimalEscChar SDF_visitDecimalEscChar(SDF_DecimalEscChar arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST)) */

SDF_DecimalEscChar SDF_visitDecimalEscChar(SDF_DecimalEscChar arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST))
{
  if (SDF_isDecimalEscCharDec0Underscore199(arg)) {
    return SDF_makeDecimalEscCharDec0Underscore199(
        acceptChars ? acceptChars(SDF_getDecimalEscCharChars(arg)) : SDF_getDecimalEscCharChars(arg));
  }
  if (SDF_isDecimalEscCharDec200Underscore249(arg)) {
    return SDF_makeDecimalEscCharDec200Underscore249(
        acceptChars ? acceptChars(SDF_getDecimalEscCharChars(arg)) : SDF_getDecimalEscCharChars(arg));
  }
  if (SDF_isDecimalEscCharDec250Underscore255(arg)) {
    return SDF_makeDecimalEscCharDec250Underscore255(
        acceptChars ? acceptChars(SDF_getDecimalEscCharChars(arg)) : SDF_getDecimalEscCharChars(arg));
  }
  ATabort("not a DecimalEscChar: %t\n", arg);
  return (SDF_DecimalEscChar)NULL;
}

/*}}}  */
/*{{{  SDF_EscChar SDF_visitEscChar(SDF_EscChar arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST)) */

SDF_EscChar SDF_visitEscChar(SDF_EscChar arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST))
{
  if (SDF_isEscCharAlphaNumeric(arg)) {
    return SDF_makeEscCharAlphaNumeric(
        acceptChars ? acceptChars(SDF_getEscCharChars(arg)) : SDF_getEscCharChars(arg));
  }
  if (SDF_isEscCharDecimal(arg)) {
    return SDF_makeEscCharDecimal(
        acceptChars ? acceptChars(SDF_getEscCharChars(arg)) : SDF_getEscCharChars(arg));
  }
  ATabort("not a EscChar: %t\n", arg);
  return (SDF_EscChar)NULL;
}

/*}}}  */
/*{{{  SDF_LChar SDF_visitLChar(SDF_LChar arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST)) */

SDF_LChar SDF_visitLChar(SDF_LChar arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST))
{
  if (SDF_isLCharNormal(arg)) {
    return SDF_makeLCharNormal(
        acceptChars ? acceptChars(SDF_getLCharChars(arg)) : SDF_getLCharChars(arg));
  }
  if (SDF_isLCharEscaped(arg)) {
    return SDF_makeLCharEscaped(
        acceptChars ? acceptChars(SDF_getLCharChars(arg)) : SDF_getLCharChars(arg));
  }
  ATabort("not a LChar: %t\n", arg);
  return (SDF_LChar)NULL;
}

/*}}}  */
/*{{{  SDF_QLiteral SDF_visitQLiteral(SDF_QLiteral arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST)) */

SDF_QLiteral SDF_visitQLiteral(SDF_QLiteral arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST))
{
  if (SDF_isQLiteralQuoted(arg)) {
    return SDF_makeQLiteralQuoted(
        acceptChars ? acceptChars(SDF_getQLiteralChars(arg)) : SDF_getQLiteralChars(arg));
  }
  ATabort("not a QLiteral: %t\n", arg);
  return (SDF_QLiteral)NULL;
}

/*}}}  */
/*{{{  SDF_UQLiteral SDF_visitUQLiteral(SDF_UQLiteral arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST)) */

SDF_UQLiteral SDF_visitUQLiteral(SDF_UQLiteral arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST))
{
  if (SDF_isUQLiteralOneChar(arg)) {
    return SDF_makeUQLiteralOneChar(
        acceptChars ? acceptChars(SDF_getUQLiteralChars(arg)) : SDF_getUQLiteralChars(arg));
  }
  if (SDF_isUQLiteralMoreChars(arg)) {
    return SDF_makeUQLiteralMoreChars(
        acceptChars ? acceptChars(SDF_getUQLiteralChars(arg)) : SDF_getUQLiteralChars(arg));
  }
  ATabort("not a UQLiteral: %t\n", arg);
  return (SDF_UQLiteral)NULL;
}

/*}}}  */
/*{{{  SDF_Literal SDF_visitLiteral(SDF_Literal arg, SDF_QLiteral (*acceptQLiteral)(SDF_QLiteral), SDF_UQLiteral (*acceptUQLiteral)(SDF_UQLiteral)) */

SDF_Literal SDF_visitLiteral(SDF_Literal arg, SDF_QLiteral (*acceptQLiteral)(SDF_QLiteral), SDF_UQLiteral (*acceptUQLiteral)(SDF_UQLiteral))
{
  if (SDF_isLiteralQlit(arg)) {
    return SDF_makeLiteralQlit(
        acceptQLiteral ? acceptQLiteral(SDF_getLiteralQLiteral(arg)) : SDF_getLiteralQLiteral(arg));
  }
  if (SDF_isLiteralUqlit(arg)) {
    return SDF_makeLiteralUqlit(
        acceptUQLiteral ? acceptUQLiteral(SDF_getLiteralUQLiteral(arg)) : SDF_getLiteralUQLiteral(arg));
  }
  ATabort("not a Literal: %t\n", arg);
  return (SDF_Literal)NULL;
}

/*}}}  */
/*{{{  SDF_ATermList SDF_visitATermList(SDF_ATermList arg, SDF_OptLayout (*acceptWsAfterBracketOpen)(SDF_OptLayout), SDF_ATermElems (*acceptElems)(SDF_ATermElems), SDF_OptLayout (*acceptWsAfterElems)(SDF_OptLayout)) */

SDF_ATermList SDF_visitATermList(SDF_ATermList arg, SDF_OptLayout (*acceptWsAfterBracketOpen)(SDF_OptLayout), SDF_ATermElems (*acceptElems)(SDF_ATermElems), SDF_OptLayout (*acceptWsAfterElems)(SDF_OptLayout))
{
  if (SDF_isATermListNotEmpty(arg)) {
    return SDF_makeATermListNotEmpty(
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(SDF_getATermListWsAfterBracketOpen(arg)) : SDF_getATermListWsAfterBracketOpen(arg),
        acceptElems ? acceptElems(SDF_getATermListElems(arg)) : SDF_getATermListElems(arg),
        acceptWsAfterElems ? acceptWsAfterElems(SDF_getATermListWsAfterElems(arg)) : SDF_getATermListWsAfterElems(arg));
  }
  ATabort("not a ATermList: %t\n", arg);
  return (SDF_ATermList)NULL;
}

/*}}}  */
/*{{{  SDF_ATermElems SDF_visitATermElems(SDF_ATermElems arg, SDF_ATerm (*acceptHead)(SDF_ATerm), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout)) */

SDF_ATermElems SDF_visitATermElems(SDF_ATermElems arg, SDF_ATerm (*acceptHead)(SDF_ATerm), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout))
{
  if (SDF_isATermElemsEmpty(arg)) {
    return SDF_makeATermElemsEmpty();
  }
  if (SDF_isATermElemsSingle(arg)) {
    return SDF_makeATermElemsSingle(
        acceptHead ? acceptHead(SDF_getATermElemsHead(arg)) : SDF_getATermElemsHead(arg));
  }
  if (SDF_isATermElemsMany(arg)) {
    return SDF_makeATermElemsMany(
        acceptHead ? acceptHead(SDF_getATermElemsHead(arg)) : SDF_getATermElemsHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(SDF_getATermElemsWsAfterFirst(arg)) : SDF_getATermElemsWsAfterFirst(arg),
        acceptSep ? acceptSep(SDF_getATermElemsSep(arg)) : SDF_getATermElemsSep(arg),
        acceptWsAfterSep ? acceptWsAfterSep(SDF_getATermElemsWsAfterSep(arg)) : SDF_getATermElemsWsAfterSep(arg),
        SDF_visitATermElems(SDF_getATermElemsTail(arg), acceptHead, acceptWsAfterFirst, acceptSep, acceptWsAfterSep));
  }
  ATabort("not a ATermElems: %t\n", arg);
  return (SDF_ATermElems)NULL;
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
/*{{{  SDF_ATerm SDF_visitATerm(SDF_ATerm arg, SDF_ACon (*acceptACon)(SDF_ACon), SDF_ATermList (*acceptList)(SDF_ATermList), SDF_AFun (*acceptFun)(SDF_AFun), SDF_OptLayout (*acceptWsAfterFun)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_ATermArgs (*acceptArgs)(SDF_ATermArgs), SDF_OptLayout (*acceptWsAfterArgs)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterACon)(SDF_OptLayout), SDF_Ann (*acceptAnn)(SDF_Ann), SDF_OptLayout (*acceptWsAfterList)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenClose)(SDF_OptLayout)) */

SDF_ATerm SDF_visitATerm(SDF_ATerm arg, SDF_ACon (*acceptACon)(SDF_ACon), SDF_ATermList (*acceptList)(SDF_ATermList), SDF_AFun (*acceptFun)(SDF_AFun), SDF_OptLayout (*acceptWsAfterFun)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenOpen)(SDF_OptLayout), SDF_ATermArgs (*acceptArgs)(SDF_ATermArgs), SDF_OptLayout (*acceptWsAfterArgs)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterACon)(SDF_OptLayout), SDF_Ann (*acceptAnn)(SDF_Ann), SDF_OptLayout (*acceptWsAfterList)(SDF_OptLayout), SDF_OptLayout (*acceptWsAfterParenClose)(SDF_OptLayout))
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
/*{{{  SDF_ATermArgs SDF_visitATermArgs(SDF_ATermArgs arg, SDF_ATerm (*acceptHead)(SDF_ATerm), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout)) */

SDF_ATermArgs SDF_visitATermArgs(SDF_ATermArgs arg, SDF_ATerm (*acceptHead)(SDF_ATerm), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout))
{
  if (SDF_isATermArgsSingle(arg)) {
    return SDF_makeATermArgsSingle(
        acceptHead ? acceptHead(SDF_getATermArgsHead(arg)) : SDF_getATermArgsHead(arg));
  }
  if (SDF_isATermArgsMany(arg)) {
    return SDF_makeATermArgsMany(
        acceptHead ? acceptHead(SDF_getATermArgsHead(arg)) : SDF_getATermArgsHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(SDF_getATermArgsWsAfterFirst(arg)) : SDF_getATermArgsWsAfterFirst(arg),
        acceptSep ? acceptSep(SDF_getATermArgsSep(arg)) : SDF_getATermArgsSep(arg),
        acceptWsAfterSep ? acceptWsAfterSep(SDF_getATermArgsWsAfterSep(arg)) : SDF_getATermArgsWsAfterSep(arg),
        SDF_visitATermArgs(SDF_getATermArgsTail(arg), acceptHead, acceptWsAfterFirst, acceptSep, acceptWsAfterSep));
  }
  ATabort("not a ATermArgs: %t\n", arg);
  return (SDF_ATermArgs)NULL;
}

/*}}}  */
/*{{{  SDF_Ann SDF_visitAnn(SDF_Ann arg, SDF_OptLayout (*acceptWsAfterBraceOpen)(SDF_OptLayout), SDF_ATermAnnos (*acceptAnnos)(SDF_ATermAnnos), SDF_OptLayout (*acceptWsAfterAnnos)(SDF_OptLayout)) */

SDF_Ann SDF_visitAnn(SDF_Ann arg, SDF_OptLayout (*acceptWsAfterBraceOpen)(SDF_OptLayout), SDF_ATermAnnos (*acceptAnnos)(SDF_ATermAnnos), SDF_OptLayout (*acceptWsAfterAnnos)(SDF_OptLayout))
{
  if (SDF_isAnnAnnotation(arg)) {
    return SDF_makeAnnAnnotation(
        acceptWsAfterBraceOpen ? acceptWsAfterBraceOpen(SDF_getAnnWsAfterBraceOpen(arg)) : SDF_getAnnWsAfterBraceOpen(arg),
        acceptAnnos ? acceptAnnos(SDF_getAnnAnnos(arg)) : SDF_getAnnAnnos(arg),
        acceptWsAfterAnnos ? acceptWsAfterAnnos(SDF_getAnnWsAfterAnnos(arg)) : SDF_getAnnWsAfterAnnos(arg));
  }
  ATabort("not a Ann: %t\n", arg);
  return (SDF_Ann)NULL;
}

/*}}}  */
/*{{{  SDF_ATermAnnos SDF_visitATermAnnos(SDF_ATermAnnos arg, SDF_ATerm (*acceptHead)(SDF_ATerm), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout)) */

SDF_ATermAnnos SDF_visitATermAnnos(SDF_ATermAnnos arg, SDF_ATerm (*acceptHead)(SDF_ATerm), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout))
{
  if (SDF_isATermAnnosSingle(arg)) {
    return SDF_makeATermAnnosSingle(
        acceptHead ? acceptHead(SDF_getATermAnnosHead(arg)) : SDF_getATermAnnosHead(arg));
  }
  if (SDF_isATermAnnosMany(arg)) {
    return SDF_makeATermAnnosMany(
        acceptHead ? acceptHead(SDF_getATermAnnosHead(arg)) : SDF_getATermAnnosHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(SDF_getATermAnnosWsAfterFirst(arg)) : SDF_getATermAnnosWsAfterFirst(arg),
        acceptSep ? acceptSep(SDF_getATermAnnosSep(arg)) : SDF_getATermAnnosSep(arg),
        acceptWsAfterSep ? acceptWsAfterSep(SDF_getATermAnnosWsAfterSep(arg)) : SDF_getATermAnnosWsAfterSep(arg),
        SDF_visitATermAnnos(SDF_getATermAnnosTail(arg), acceptHead, acceptWsAfterFirst, acceptSep, acceptWsAfterSep));
  }
  ATabort("not a ATermAnnos: %t\n", arg);
  return (SDF_ATermAnnos)NULL;
}

/*}}}  */
/*{{{  SDF_Attributes SDF_visitAttributes(SDF_Attributes arg, SDF_OptLayout (*acceptWsAfterBraceOpen)(SDF_OptLayout), SDF_AttributeList (*acceptList)(SDF_AttributeList), SDF_OptLayout (*acceptWsAfterList)(SDF_OptLayout)) */

SDF_Attributes SDF_visitAttributes(SDF_Attributes arg, SDF_OptLayout (*acceptWsAfterBraceOpen)(SDF_OptLayout), SDF_AttributeList (*acceptList)(SDF_AttributeList), SDF_OptLayout (*acceptWsAfterList)(SDF_OptLayout))
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
/*{{{  SDF_AttributeList SDF_visitAttributeList(SDF_AttributeList arg, SDF_Attribute (*acceptHead)(SDF_Attribute), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout)) */

SDF_AttributeList SDF_visitAttributeList(SDF_AttributeList arg, SDF_Attribute (*acceptHead)(SDF_Attribute), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout), char * (*acceptSep)(char *), SDF_OptLayout (*acceptWsAfterSep)(SDF_OptLayout))
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
/*{{{  SDF_ProductionList SDF_visitProductionList(SDF_ProductionList arg, SDF_Production (*acceptHead)(SDF_Production), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout)) */

SDF_ProductionList SDF_visitProductionList(SDF_ProductionList arg, SDF_Production (*acceptHead)(SDF_Production), SDF_OptLayout (*acceptWsAfterFirst)(SDF_OptLayout))
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
/*{{{  SDF_SDF SDF_visitSDF(SDF_SDF arg, SDF_OptLayout (*acceptWsAfterDefinition)(SDF_OptLayout), SDF_Definition (*acceptDefinition)(SDF_Definition)) */

SDF_SDF SDF_visitSDF(SDF_SDF arg, SDF_OptLayout (*acceptWsAfterDefinition)(SDF_OptLayout), SDF_Definition (*acceptDefinition)(SDF_Definition))
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
/*{{{  SDF_OptLayout SDF_visitOptLayout(SDF_OptLayout arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST)) */

SDF_OptLayout SDF_visitOptLayout(SDF_OptLayout arg, SDF_CHARLIST (*acceptChars)(SDF_CHARLIST))
{
  if (SDF_isOptLayoutAbsent(arg)) {
    return SDF_makeOptLayoutAbsent();
  }
  if (SDF_isOptLayoutPresent(arg)) {
    return SDF_makeOptLayoutPresent(
        acceptChars ? acceptChars(SDF_getOptLayoutChars(arg)) : SDF_getOptLayoutChars(arg));
  }
  ATabort("not a OptLayout: %t\n", arg);
  return (SDF_OptLayout)NULL;
}

/*}}}  */
/*{{{  SDF_Start SDF_visitStart(SDF_Start arg, SDF_OptLayout (*acceptWsBefore)(SDF_OptLayout), SDF_SDF (*acceptTopSDF)(SDF_SDF), SDF_OptLayout (*acceptWsAfter)(SDF_OptLayout), int (*acceptAmbCnt)(int), SDF_Productions (*acceptTopProductions)(SDF_Productions), SDF_Production (*acceptTopProduction)(SDF_Production), SDF_Attributes (*acceptTopAttributes)(SDF_Attributes), SDF_Attribute (*acceptTopAttribute)(SDF_Attribute), SDF_Ann (*acceptTopAnn)(SDF_Ann), SDF_ATerm (*acceptTopATerm)(SDF_ATerm), SDF_AFun (*acceptTopAFun)(SDF_AFun), SDF_ACon (*acceptTopACon)(SDF_ACon), SDF_ATermList (*acceptTopATermList)(SDF_ATermList), SDF_QLiteral (*acceptTopQLiteral)(SDF_QLiteral), SDF_UQLiteral (*acceptTopUQLiteral)(SDF_UQLiteral), SDF_Literal (*acceptTopLiteral)(SDF_Literal), SDF_IntCon (*acceptTopIntCon)(SDF_IntCon), SDF_NatCon (*acceptTopNatCon)(SDF_NatCon), SDF_RealCon (*acceptTopRealCon)(SDF_RealCon), SDF_OptExp (*acceptTopOptExp)(SDF_OptExp), SDF_Symbols (*acceptTopSymbols)(SDF_Symbols), SDF_Symbol (*acceptTopSymbol)(SDF_Symbol), SDF_Grammar (*acceptTopGrammar)(SDF_Grammar), SDF_ImpSection (*acceptTopImpSection)(SDF_ImpSection), SDF_Definition (*acceptTopDefinition)(SDF_Definition), SDF_Module (*acceptTopModule)(SDF_Module), SDF_Sections (*acceptTopSections)(SDF_Sections), SDF_Section (*acceptTopSection)(SDF_Section), SDF_Imports (*acceptTopImports)(SDF_Imports), SDF_Import (*acceptTopImport)(SDF_Import), SDF_ModuleName (*acceptTopModuleName)(SDF_ModuleName), SDF_ModuleId (*acceptTopModuleId)(SDF_ModuleId), SDF_Renamings (*acceptTopRenamings)(SDF_Renamings), SDF_Renaming (*acceptTopRenaming)(SDF_Renaming), SDF_Priorities (*acceptTopPriorities)(SDF_Priorities), SDF_Priority (*acceptTopPriority)(SDF_Priority), SDF_Group (*acceptTopGroup)(SDF_Group), SDF_Associativity (*acceptTopAssociativity)(SDF_Associativity), SDF_CharClass (*acceptTopCharClass)(SDF_CharClass), SDF_ShortChar (*acceptTopShortChar)(SDF_ShortChar), SDF_NumChar (*acceptTopNumChar)(SDF_NumChar), SDF_Character (*acceptTopCharacter)(SDF_Character), SDF_Sort (*acceptTopSort)(SDF_Sort), SDF_Restrictions (*acceptTopRestrictions)(SDF_Restrictions), SDF_Restriction (*acceptTopRestriction)(SDF_Restriction), SDF_Lookaheads (*acceptTopLookaheads)(SDF_Lookaheads), SDF_Lookahead (*acceptTopLookahead)(SDF_Lookahead), SDF_Aliases (*acceptTopAliases)(SDF_Aliases), SDF_Alias (*acceptTopAlias)(SDF_Alias)) */

SDF_Start SDF_visitStart(SDF_Start arg, SDF_OptLayout (*acceptWsBefore)(SDF_OptLayout), SDF_SDF (*acceptTopSDF)(SDF_SDF), SDF_OptLayout (*acceptWsAfter)(SDF_OptLayout), int (*acceptAmbCnt)(int), SDF_Productions (*acceptTopProductions)(SDF_Productions), SDF_Production (*acceptTopProduction)(SDF_Production), SDF_Attributes (*acceptTopAttributes)(SDF_Attributes), SDF_Attribute (*acceptTopAttribute)(SDF_Attribute), SDF_Ann (*acceptTopAnn)(SDF_Ann), SDF_ATerm (*acceptTopATerm)(SDF_ATerm), SDF_AFun (*acceptTopAFun)(SDF_AFun), SDF_ACon (*acceptTopACon)(SDF_ACon), SDF_ATermList (*acceptTopATermList)(SDF_ATermList), SDF_QLiteral (*acceptTopQLiteral)(SDF_QLiteral), SDF_UQLiteral (*acceptTopUQLiteral)(SDF_UQLiteral), SDF_Literal (*acceptTopLiteral)(SDF_Literal), SDF_IntCon (*acceptTopIntCon)(SDF_IntCon), SDF_NatCon (*acceptTopNatCon)(SDF_NatCon), SDF_RealCon (*acceptTopRealCon)(SDF_RealCon), SDF_OptExp (*acceptTopOptExp)(SDF_OptExp), SDF_Symbols (*acceptTopSymbols)(SDF_Symbols), SDF_Symbol (*acceptTopSymbol)(SDF_Symbol), SDF_Grammar (*acceptTopGrammar)(SDF_Grammar), SDF_ImpSection (*acceptTopImpSection)(SDF_ImpSection), SDF_Definition (*acceptTopDefinition)(SDF_Definition), SDF_Module (*acceptTopModule)(SDF_Module), SDF_Sections (*acceptTopSections)(SDF_Sections), SDF_Section (*acceptTopSection)(SDF_Section), SDF_Imports (*acceptTopImports)(SDF_Imports), SDF_Import (*acceptTopImport)(SDF_Import), SDF_ModuleName (*acceptTopModuleName)(SDF_ModuleName), SDF_ModuleId (*acceptTopModuleId)(SDF_ModuleId), SDF_Renamings (*acceptTopRenamings)(SDF_Renamings), SDF_Renaming (*acceptTopRenaming)(SDF_Renaming), SDF_Priorities (*acceptTopPriorities)(SDF_Priorities), SDF_Priority (*acceptTopPriority)(SDF_Priority), SDF_Group (*acceptTopGroup)(SDF_Group), SDF_Associativity (*acceptTopAssociativity)(SDF_Associativity), SDF_CharClass (*acceptTopCharClass)(SDF_CharClass), SDF_ShortChar (*acceptTopShortChar)(SDF_ShortChar), SDF_NumChar (*acceptTopNumChar)(SDF_NumChar), SDF_Character (*acceptTopCharacter)(SDF_Character), SDF_Sort (*acceptTopSort)(SDF_Sort), SDF_Restrictions (*acceptTopRestrictions)(SDF_Restrictions), SDF_Restriction (*acceptTopRestriction)(SDF_Restriction), SDF_Lookaheads (*acceptTopLookaheads)(SDF_Lookaheads), SDF_Lookahead (*acceptTopLookahead)(SDF_Lookahead), SDF_Aliases (*acceptTopAliases)(SDF_Aliases), SDF_Alias (*acceptTopAlias)(SDF_Alias))
{
  if (SDF_isStartSDF(arg)) {
    return SDF_makeStartSDF(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopSDF ? acceptTopSDF(SDF_getStartTopSDF(arg)) : SDF_getStartTopSDF(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartProductions(arg)) {
    return SDF_makeStartProductions(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopProductions ? acceptTopProductions(SDF_getStartTopProductions(arg)) : SDF_getStartTopProductions(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartProduction(arg)) {
    return SDF_makeStartProduction(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopProduction ? acceptTopProduction(SDF_getStartTopProduction(arg)) : SDF_getStartTopProduction(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartAttributes(arg)) {
    return SDF_makeStartAttributes(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopAttributes ? acceptTopAttributes(SDF_getStartTopAttributes(arg)) : SDF_getStartTopAttributes(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartAttribute(arg)) {
    return SDF_makeStartAttribute(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopAttribute ? acceptTopAttribute(SDF_getStartTopAttribute(arg)) : SDF_getStartTopAttribute(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartAnn(arg)) {
    return SDF_makeStartAnn(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopAnn ? acceptTopAnn(SDF_getStartTopAnn(arg)) : SDF_getStartTopAnn(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartATerm(arg)) {
    return SDF_makeStartATerm(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopATerm ? acceptTopATerm(SDF_getStartTopATerm(arg)) : SDF_getStartTopATerm(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartAFun(arg)) {
    return SDF_makeStartAFun(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopAFun ? acceptTopAFun(SDF_getStartTopAFun(arg)) : SDF_getStartTopAFun(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartACon(arg)) {
    return SDF_makeStartACon(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopACon ? acceptTopACon(SDF_getStartTopACon(arg)) : SDF_getStartTopACon(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartATermList(arg)) {
    return SDF_makeStartATermList(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopATermList ? acceptTopATermList(SDF_getStartTopATermList(arg)) : SDF_getStartTopATermList(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartQLiteral(arg)) {
    return SDF_makeStartQLiteral(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopQLiteral ? acceptTopQLiteral(SDF_getStartTopQLiteral(arg)) : SDF_getStartTopQLiteral(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartUQLiteral(arg)) {
    return SDF_makeStartUQLiteral(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopUQLiteral ? acceptTopUQLiteral(SDF_getStartTopUQLiteral(arg)) : SDF_getStartTopUQLiteral(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartLiteral(arg)) {
    return SDF_makeStartLiteral(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopLiteral ? acceptTopLiteral(SDF_getStartTopLiteral(arg)) : SDF_getStartTopLiteral(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartIntCon(arg)) {
    return SDF_makeStartIntCon(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopIntCon ? acceptTopIntCon(SDF_getStartTopIntCon(arg)) : SDF_getStartTopIntCon(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartNatCon(arg)) {
    return SDF_makeStartNatCon(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopNatCon ? acceptTopNatCon(SDF_getStartTopNatCon(arg)) : SDF_getStartTopNatCon(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartRealCon(arg)) {
    return SDF_makeStartRealCon(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopRealCon ? acceptTopRealCon(SDF_getStartTopRealCon(arg)) : SDF_getStartTopRealCon(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartOptExp(arg)) {
    return SDF_makeStartOptExp(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopOptExp ? acceptTopOptExp(SDF_getStartTopOptExp(arg)) : SDF_getStartTopOptExp(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartSymbols(arg)) {
    return SDF_makeStartSymbols(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopSymbols ? acceptTopSymbols(SDF_getStartTopSymbols(arg)) : SDF_getStartTopSymbols(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartSymbol(arg)) {
    return SDF_makeStartSymbol(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopSymbol ? acceptTopSymbol(SDF_getStartTopSymbol(arg)) : SDF_getStartTopSymbol(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartGrammar(arg)) {
    return SDF_makeStartGrammar(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopGrammar ? acceptTopGrammar(SDF_getStartTopGrammar(arg)) : SDF_getStartTopGrammar(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartImpSection(arg)) {
    return SDF_makeStartImpSection(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopImpSection ? acceptTopImpSection(SDF_getStartTopImpSection(arg)) : SDF_getStartTopImpSection(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartDefinition(arg)) {
    return SDF_makeStartDefinition(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopDefinition ? acceptTopDefinition(SDF_getStartTopDefinition(arg)) : SDF_getStartTopDefinition(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartModule(arg)) {
    return SDF_makeStartModule(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopModule ? acceptTopModule(SDF_getStartTopModule(arg)) : SDF_getStartTopModule(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartSections(arg)) {
    return SDF_makeStartSections(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopSections ? acceptTopSections(SDF_getStartTopSections(arg)) : SDF_getStartTopSections(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartSection(arg)) {
    return SDF_makeStartSection(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopSection ? acceptTopSection(SDF_getStartTopSection(arg)) : SDF_getStartTopSection(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartImports(arg)) {
    return SDF_makeStartImports(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopImports ? acceptTopImports(SDF_getStartTopImports(arg)) : SDF_getStartTopImports(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartImport(arg)) {
    return SDF_makeStartImport(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopImport ? acceptTopImport(SDF_getStartTopImport(arg)) : SDF_getStartTopImport(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartModuleName(arg)) {
    return SDF_makeStartModuleName(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopModuleName ? acceptTopModuleName(SDF_getStartTopModuleName(arg)) : SDF_getStartTopModuleName(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartModuleId(arg)) {
    return SDF_makeStartModuleId(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopModuleId ? acceptTopModuleId(SDF_getStartTopModuleId(arg)) : SDF_getStartTopModuleId(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartRenamings(arg)) {
    return SDF_makeStartRenamings(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopRenamings ? acceptTopRenamings(SDF_getStartTopRenamings(arg)) : SDF_getStartTopRenamings(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartRenaming(arg)) {
    return SDF_makeStartRenaming(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopRenaming ? acceptTopRenaming(SDF_getStartTopRenaming(arg)) : SDF_getStartTopRenaming(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartPriorities(arg)) {
    return SDF_makeStartPriorities(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopPriorities ? acceptTopPriorities(SDF_getStartTopPriorities(arg)) : SDF_getStartTopPriorities(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartPriority(arg)) {
    return SDF_makeStartPriority(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopPriority ? acceptTopPriority(SDF_getStartTopPriority(arg)) : SDF_getStartTopPriority(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartGroup(arg)) {
    return SDF_makeStartGroup(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopGroup ? acceptTopGroup(SDF_getStartTopGroup(arg)) : SDF_getStartTopGroup(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartAssociativity(arg)) {
    return SDF_makeStartAssociativity(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopAssociativity ? acceptTopAssociativity(SDF_getStartTopAssociativity(arg)) : SDF_getStartTopAssociativity(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartCharClass(arg)) {
    return SDF_makeStartCharClass(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopCharClass ? acceptTopCharClass(SDF_getStartTopCharClass(arg)) : SDF_getStartTopCharClass(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartShortChar(arg)) {
    return SDF_makeStartShortChar(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopShortChar ? acceptTopShortChar(SDF_getStartTopShortChar(arg)) : SDF_getStartTopShortChar(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartNumChar(arg)) {
    return SDF_makeStartNumChar(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopNumChar ? acceptTopNumChar(SDF_getStartTopNumChar(arg)) : SDF_getStartTopNumChar(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartCharacter(arg)) {
    return SDF_makeStartCharacter(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopCharacter ? acceptTopCharacter(SDF_getStartTopCharacter(arg)) : SDF_getStartTopCharacter(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartSort(arg)) {
    return SDF_makeStartSort(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopSort ? acceptTopSort(SDF_getStartTopSort(arg)) : SDF_getStartTopSort(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartRestrictions(arg)) {
    return SDF_makeStartRestrictions(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopRestrictions ? acceptTopRestrictions(SDF_getStartTopRestrictions(arg)) : SDF_getStartTopRestrictions(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartRestriction(arg)) {
    return SDF_makeStartRestriction(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopRestriction ? acceptTopRestriction(SDF_getStartTopRestriction(arg)) : SDF_getStartTopRestriction(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartLookaheads(arg)) {
    return SDF_makeStartLookaheads(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopLookaheads ? acceptTopLookaheads(SDF_getStartTopLookaheads(arg)) : SDF_getStartTopLookaheads(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartLookahead(arg)) {
    return SDF_makeStartLookahead(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopLookahead ? acceptTopLookahead(SDF_getStartTopLookahead(arg)) : SDF_getStartTopLookahead(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartAliases(arg)) {
    return SDF_makeStartAliases(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopAliases ? acceptTopAliases(SDF_getStartTopAliases(arg)) : SDF_getStartTopAliases(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  if (SDF_isStartAlias(arg)) {
    return SDF_makeStartAlias(
        acceptWsBefore ? acceptWsBefore(SDF_getStartWsBefore(arg)) : SDF_getStartWsBefore(arg),
        acceptTopAlias ? acceptTopAlias(SDF_getStartTopAlias(arg)) : SDF_getStartTopAlias(arg),
        acceptWsAfter ? acceptWsAfter(SDF_getStartWsAfter(arg)) : SDF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(SDF_getStartAmbCnt(arg)) : SDF_getStartAmbCnt(arg));
  }
  ATabort("not a Start: %t\n", arg);
  return (SDF_Start)NULL;
}

/*}}}  */

/*}}}  */
