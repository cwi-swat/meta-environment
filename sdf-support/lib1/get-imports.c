#include "SDF-utils.h"

static ATermList
getImpsectionImports(SDF_ImpSection impsection)
{
  ATermList     modules     = ATempty;
  SDF_Imports    imports     = SDF_getImpSectionList(impsection);
  SDF_ImportList importslist = SDF_getImportsList(imports);

  while (!SDF_isImportListEmpty(importslist)) {
    SDF_Import     import  = SDF_getImportListHead(importslist);
    SDF_ModuleName modname = SDF_getImportModuleName(import);
    SDF_ModuleId   modid   = SDF_getModuleNameModuleId(modname);
    SDF_Lexical    lex     = SDF_getModuleIdLex(modid);

    modules = ATinsert(modules, lex);

    if (SDF_isImportListSingle(importslist)) {
      break;
    }
    importslist = SDF_getImportListTail(importslist);
  }

  return modules;
}

static ATermList
getGrammarImports(SDF_Grammar grammar)
{
  if (SDF_hasGrammarImpSection(grammar)) {
    SDF_ImpSection impsection = SDF_getGrammarImpSection(grammar);
    return getImpsectionImports(impsection);
  }
  else if (SDF_isGrammarConcGrammars(grammar)) {
    ATermList leftImports = getGrammarImports(SDF_getGrammarLeft(grammar));
    ATermList rightImports = getGrammarImports(SDF_getGrammarRight(grammar));
    return ATconcat(rightImports, leftImports);
  }

  return ATempty;
}

ATermList
SDFgetImports(SDF_Module module)
{
  SDF_ImpSectionList imps;
  SDF_SectionList    sectlist;
  ATermList         modules = ATempty;

  imps = SDF_getModuleList(module);
  while (!SDF_isImpSectionListEmpty(imps)) {
    SDF_ImpSection impsection = SDF_getImpSectionListHead(imps);
    modules = ATconcat(getImpsectionImports(impsection), modules);

    if (SDF_isImpSectionListSingle(imps)) {
      break;
    }
    imps = SDF_getImpSectionListTail(imps);
  }

  sectlist = SDF_getSectionsList(SDF_getModuleSections(module));
  while (!SDF_isSectionListEmpty(sectlist)) {
    SDF_Section sect = SDF_getSectionListHead(sectlist);
    SDF_Grammar grammar = SDF_getSectionGrammar(sect);
    modules = ATconcat(getGrammarImports(grammar), modules);

    if (SDF_isSectionListSingle(sectlist)) {
      break;
    }
    sectlist = SDF_getSectionListTail(sectlist);
  }

  return ATreverse(modules);
}
