#include "SDFME-utils.h"

/*{{{  SDFforeachGrammar(SDF_Grammar grammar, SDFGrammarFunc func, void *user_data) */

void
SDFforeachGrammar(SDF_Grammar grammar, SDFGrammarFunc func, void *user_data)
{
  if (SDF_isGrammarConcGrammars(grammar)) {
    SDFforeachGrammar(SDF_getGrammarLeft(grammar), func, user_data);
    SDFforeachGrammar(SDF_getGrammarRight(grammar), func, user_data);
  }
  else {
    func(grammar, user_data);
  }
}

/*}}}  */
/*{{{  SDFforeachGrammarInModule(SDF_Module module, SDFGrammarFunc func, void *user_data) */

void
SDFforeachGrammarInSections(SDF_Sections    sections,
			    SDFGrammarFunc  func,
			    void           *user_data)
{
  SDF_SectionList sectionList = SDF_getSectionsList(sections);

  while (!SDF_isSectionListEmpty(sectionList)) {
    SDF_Section section = SDF_getSectionListHead(sectionList);
    SDF_Grammar grammar = SDF_getSectionGrammar(section);

    SDFforeachGrammar(grammar, func, user_data);

    if (SDF_isSectionListSingle(sectionList)) {
      break;
    }
    sectionList = SDF_getSectionListTail(sectionList);
  }
}

/*}}}  */
/*{{{  SDFforeachGrammarInModule(SDF_Module module, SDFGrammarFunc func, void *user_data) */

void
SDFforeachGrammarInModule(SDF_Module      module,
			  SDFGrammarFunc  func,
			  void           *user_data)
{
  SDF_Sections sections = SDF_getModuleSections(module);

  SDFforeachGrammarInSections(sections, func, user_data);
}

/*}}}  */

/*{{{  collect_grammars(SDF_Grammar grammar, ATermList *grammars) */

static void
collect_grammars(SDF_Grammar grammar, ATermList *grammars)
{
  *grammars = ATinsert(*grammars, SDF_GrammarToTerm(grammar));
}

/*}}}  */
/*{{{  SDFgetGrammars(SDF_Module module) */

ATermList
SDFgetGrammars(SDF_Module module)
{
  ATermList grammars = ATempty;

  SDFforeachGrammarInModule(module,
			    (SDFGrammarFunc)collect_grammars,
			    &grammars);

  return grammars;
}

/*}}}  */
