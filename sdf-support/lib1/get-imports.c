#include "SDF-utils.h"

/*{{{  getImpsectionImports(SDF_ImpSection impsection) */

static ATermList
getImpsectionImports(SDF_ImpSection impsection)
{
  ATermList      modules     = ATempty;
  SDF_Imports    imports     = SDF_getImpSectionList(impsection);
  SDF_ImportList importslist = SDF_getImportsList(imports);

  while (!SDF_isImportListEmpty(importslist)) {
    SDF_Import     import  = SDF_getImportListHead(importslist);
    SDF_ModuleName modname = SDF_getImportModuleName(import);
    SDF_ModuleId   modid   = SDF_getModuleNameModuleId(modname);
    char          *lex     = SDF_getModuleIdLex(modid);

    modules = ATinsert(modules, ATmake("<str>", lex));

    if (SDF_isImportListSingle(importslist)) {
      break;
    }
    importslist = SDF_getImportListTail(importslist);
  }

  return modules;
}

/*}}}  */
/*{{{  collect_imports(SDF_Grammar grammar, ATermList *imports) */

static void
collect_imports(SDF_Grammar grammar, ATermList *imports)
{
  if (SDF_hasGrammarImpSection(grammar)) {
    SDF_ImpSection impsection = SDF_getGrammarImpSection(grammar);
    *imports = ATconcat(*imports, getImpsectionImports(impsection));
  }
}

/*}}}  */
/*{{{  SDFgetImports(SDF_Module module) */

ATermList
SDF_getImports(SDF_Module module)
{
  SDF_ImpSectionList imps;
  SDF_Sections       sections;
  ATermList          modules = ATempty;

  imps = SDF_getModuleList(module);
  while (!SDF_isImpSectionListEmpty(imps)) {
    SDF_ImpSection impsection = SDF_getImpSectionListHead(imps);
    modules = ATconcat(getImpsectionImports(impsection), modules);

    if (SDF_isImpSectionListSingle(imps)) {
      break;
    }
    imps = SDF_getImpSectionListTail(imps);
  }

  sections = SDF_getModuleSections(module);
  SDFforeachGrammarInSections(sections,
			      (SDFGrammarFunc)collect_imports,
			      &modules);

  return modules;
}

/*}}}  */
