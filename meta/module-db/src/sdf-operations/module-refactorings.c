#include "module-refactorings.h"
#include <SDFME-utils.h>

/*{{{  static SDF_ImportList rename_modulename_in_importlist( */

static SDF_ImportList rename_modulename_in_importlist(
                                       SDF_ImportList orgImports,
                                       SDF_ModuleId oldModuleName,
                                       SDF_ModuleId newModuleName)
{
  if (!SDF_isImportListEmpty(orgImports)) {
    SDF_Import import = SDF_getImportListHead(orgImports);
    SDF_ModuleName moduleName = SDF_getImportModuleName(import);
    SDF_ModuleId moduleId = SDF_getModuleNameModuleId(moduleName);
    
    if (SDF_hasImportListTail(orgImports)) {
      SDF_ImportList imports = SDF_getImportListTail(orgImports);
      SDF_ImportList newImports =
        rename_modulename_in_importlist(imports, oldModuleName, newModuleName);
      if (!SDF_isEqualImportList(newImports, imports)) {
        orgImports = SDF_setImportListTail(orgImports, newImports);
      }
    }

    moduleId = SDF_ModuleIdFromTerm(
		 ATremoveAllAnnotations(SDF_ModuleIdToTerm(moduleId)));
    if (SDF_isEqualModuleId(moduleId, oldModuleName)) {
      SDF_ModuleName tmpModuleName = 
        SDF_setModuleNameModuleId(moduleName, newModuleName);
      SDF_Import newImport = 
        SDF_setImportModuleName(import, tmpModuleName);
      orgImports = SDF_setImportListHead(orgImports, newImport);
    }
    
  }
  return orgImports;
}

/*}}}  */
/*{{{  static SDF_ImpSection rename_modulename_in_impsection( */

static SDF_ImpSection rename_modulename_in_impsection(
                                       SDF_ImpSection impSection,
                                       SDF_ModuleId oldModuleName,
                                       SDF_ModuleId newModuleName)
{
  SDF_Imports    imports     = SDF_getImpSectionList(impSection);
  SDF_ImportList importsList = SDF_getImportsList(imports);

  SDF_ImportList newImportsList = 
    rename_modulename_in_importlist(importsList, oldModuleName, newModuleName);
  
  SDF_Imports newImports = SDF_setImportsList(imports, newImportsList);
  
  return SDF_setImpSectionList(impSection, newImports);
}

/*}}}  */
/*{{{  static SDF_Grammar rename_modulename_in_grammar( */

static SDF_Grammar rename_modulename_in_grammar(
                                       SDF_Grammar orgGrammar,
                                       SDF_ModuleId oldModuleName,
                                       SDF_ModuleId newModuleName)
{
  if (SDF_isGrammarImpSection(orgGrammar)) {
    SDF_ImpSection impSection = SDF_getGrammarImpSection(orgGrammar);
    SDF_ImpSection newImpSection =
      rename_modulename_in_impsection(impSection,
                                      oldModuleName, newModuleName);
    orgGrammar = SDF_setGrammarImpSection(orgGrammar, newImpSection);
  }
  if (SDF_isGrammarConcGrammars(orgGrammar)) {
    SDF_Grammar leftGrammar = SDF_getGrammarLeft(orgGrammar);
    SDF_Grammar rightGrammar = SDF_getGrammarRight(orgGrammar);
    SDF_Grammar newLeftGrammar = 
      rename_modulename_in_grammar(leftGrammar, oldModuleName, newModuleName);
    SDF_Grammar newRightGrammar = 
      rename_modulename_in_grammar(rightGrammar, oldModuleName, newModuleName);
    orgGrammar = SDF_setGrammarLeft(orgGrammar, newLeftGrammar);
    orgGrammar = SDF_setGrammarRight(orgGrammar, newRightGrammar);
  }
  return orgGrammar;
}

/*}}}  */
/*{{{  static SDF_Section rename_modulename_in_section( */

static SDF_Section rename_modulename_in_section(
                                       SDF_Section orgSection,
                                       SDF_ModuleId oldModuleName,
                                       SDF_ModuleId newModuleName)
{
  if (SDF_hasSectionGrammar(orgSection)) {
    SDF_Grammar grammar  = SDF_getSectionGrammar(orgSection);

    SDF_Grammar newGrammar = 
      rename_modulename_in_grammar(grammar, oldModuleName, newModuleName);
    orgSection = SDF_setSectionGrammar(orgSection, newGrammar);   
  }
  return orgSection;
}

/*}}}  */
/*{{{  static SDF_SectionList rename_modulename_in_sectionlist( */

static SDF_SectionList rename_modulename_in_sectionlist(
                                       SDF_SectionList orgSections,
                                       SDF_ModuleId oldModuleName,
                                       SDF_ModuleId newModuleName)
{
  if (!SDF_isSectionListEmpty(orgSections)) {
    SDF_Section section  = SDF_getSectionListHead(orgSections);
    SDF_Section newSection = 
      rename_modulename_in_section(section, oldModuleName, newModuleName);
    if (SDF_hasSectionListTail(orgSections)) {
      SDF_SectionList sections = 
        SDF_getSectionListTail(orgSections);
      SDF_SectionList newSections = 
        rename_modulename_in_sectionlist(sections, 
                                         oldModuleName, newModuleName);
      if (!SDF_isEqualSectionList(newSections, sections)) {
        orgSections = SDF_setSectionListTail(orgSections, newSections);
      }
    }
    if (!SDF_isEqualSection(newSection, section)) {
      orgSections = SDF_setSectionListHead(orgSections, newSection);
    }
  }
  return orgSections;
}

/*}}}  */
/*{{{  static SDF_ImpSectionList rename_modulename_in_impsections( */

static SDF_ImpSectionList rename_modulename_in_impsections(
                                       SDF_ImpSectionList orgImpSections,
                                       SDF_ModuleId oldModuleName,
                                       SDF_ModuleId newModuleName)
{
  if (!SDF_isImpSectionListEmpty(orgImpSections)) {
    SDF_ImpSection impSection  = SDF_getImpSectionListHead(orgImpSections);
    SDF_ImpSection newImpSection = 
      rename_modulename_in_impsection(impSection, oldModuleName, newModuleName);
    if (SDF_hasImpSectionListTail(orgImpSections)) {
      SDF_ImpSectionList impSections = 
        SDF_getImpSectionListTail(orgImpSections);
      SDF_ImpSectionList newImpSections = 
        rename_modulename_in_impsections(impSections,
                                         oldModuleName,
                                         newModuleName);
      if (!SDF_isEqualImpSectionList(newImpSections, impSections)) {
        orgImpSections = SDF_setImpSectionListTail(orgImpSections, 
                                                   newImpSections);
      }
    }
    if (!SDF_isEqualImpSection(newImpSection, impSection)) {
      orgImpSections = SDF_setImpSectionListHead(orgImpSections, 
                                                 newImpSection);
    }
  }
  return orgImpSections;
}

/*}}}  */

/*{{{  static SDF_ImportList delete_modulename_from_importlist( */

static SDF_ImportList delete_modulename_from_importlist(
                                       SDF_ImportList orgImports,
                                       SDF_ModuleId oldModuleName)
{
  if (!SDF_isImportListEmpty(orgImports)) {
    SDF_Import import = SDF_getImportListHead(orgImports);
    SDF_ModuleName moduleName = SDF_getImportModuleName(import);
    SDF_ModuleId moduleId = SDF_getModuleNameModuleId(moduleName);
    
    if (SDF_hasImportListTail(orgImports)) {
      SDF_ImportList imports = SDF_getImportListTail(orgImports);
      SDF_ImportList newImports =
        delete_modulename_from_importlist(imports, oldModuleName);
      if (!SDF_isEqualImportList(newImports, imports)) {
        orgImports = SDF_setImportListTail(orgImports, newImports);
      }
    }

    moduleId = SDF_ModuleIdFromTerm(
		 ATremoveAllAnnotations(SDF_ModuleIdToTerm(moduleId)));
    if (SDF_isEqualModuleId(moduleId, oldModuleName)) {
      if (SDF_hasImportListTail(orgImports)) {
	orgImports = SDF_getImportListTail(orgImports);
      }
      else {
	orgImports = SDF_makeImportListEmpty();
      }
    }
    
  }
  return orgImports;
}

/*}}}  */
/*{{{  static SDF_ImpSection delete_modulename_from_impsection( */

static SDF_ImpSection delete_modulename_from_impsection(
                                       SDF_ImpSection impSection,
                                       SDF_ModuleId oldModuleName)
{
  SDF_Imports    imports     = SDF_getImpSectionList(impSection);
  SDF_ImportList importsList = SDF_getImportsList(imports);

  SDF_ImportList newImportsList = 
    delete_modulename_from_importlist(importsList, oldModuleName);
  SDF_Imports newImports;

  if (SDF_isImportListEmpty(newImportsList)) {
    return NULL;
  }

  newImports = SDF_setImportsList(imports, newImportsList);
  
  return SDF_setImpSectionList(impSection, newImports);
}

/*}}}  */
/*{{{  static SDF_Grammar delete_modulename_from_grammar( */

static SDF_Grammar delete_modulename_from_grammar(
                                       SDF_Grammar orgGrammar,
                                       SDF_ModuleId oldModuleName)
{
  if (SDF_isGrammarImpSection(orgGrammar)) {
    SDF_ImpSection impSection = SDF_getGrammarImpSection(orgGrammar);
    SDF_ImpSection newImpSection =
      delete_modulename_from_impsection(impSection, oldModuleName);

    if (newImpSection != NULL) {
      orgGrammar = SDF_setGrammarImpSection(orgGrammar, newImpSection);
    }
    else {
      return NULL;
    }
  }
  if (SDF_isGrammarConcGrammars(orgGrammar)) {
    SDF_Grammar leftGrammar = SDF_getGrammarLeft(orgGrammar);
    SDF_Grammar rightGrammar = SDF_getGrammarRight(orgGrammar);
    SDF_Grammar newLeftGrammar = 
      delete_modulename_from_grammar(leftGrammar, oldModuleName);
    SDF_Grammar newRightGrammar = 
      delete_modulename_from_grammar(rightGrammar, oldModuleName);

    if (newLeftGrammar == NULL && newRightGrammar == NULL) {
      orgGrammar = NULL;
    }
    else if (newLeftGrammar == NULL) {
      orgGrammar = newRightGrammar;
    }
    else if (newRightGrammar == NULL) {
      orgGrammar = newLeftGrammar;
    }
    else {
      orgGrammar = SDF_setGrammarLeft(orgGrammar, newLeftGrammar);
      orgGrammar = SDF_setGrammarRight(orgGrammar, newRightGrammar);
    }
  }
  return orgGrammar;
}

/*}}}  */
/*{{{  static SDF_Section delete_modulename_from_section( */

static SDF_Section delete_modulename_from_section(
                                       SDF_Section orgSection,
                                       SDF_ModuleId oldModuleName)
{
  if (SDF_hasSectionGrammar(orgSection)) {
    SDF_Grammar grammar  = SDF_getSectionGrammar(orgSection);

    SDF_Grammar newGrammar = 
      delete_modulename_from_grammar(grammar, oldModuleName);

    if (newGrammar != NULL) {
      orgSection = SDF_setSectionGrammar(orgSection, newGrammar);   
    }
    else {
      orgSection = NULL;
    }
  }
  return orgSection;
}

/*}}}  */
/*{{{  static SDF_SectionList delete_modulename_from_sectionlist( */

static SDF_SectionList delete_modulename_from_sectionlist(
                                       SDF_SectionList orgSections,
                                       SDF_ModuleId oldModuleName)
{
  if (!SDF_isSectionListEmpty(orgSections)) {
    SDF_Section section  = SDF_getSectionListHead(orgSections);
    SDF_Section newSection = 
      delete_modulename_from_section(section, oldModuleName);

    if (SDF_hasSectionListTail(orgSections)) {
      SDF_SectionList sections = 
        SDF_getSectionListTail(orgSections);
      SDF_SectionList newSections = 
        delete_modulename_from_sectionlist(sections, oldModuleName);
      if (!SDF_isEqualSectionList(newSections, sections)) {
        orgSections = SDF_setSectionListTail(orgSections, newSections);
      }
    }

    if (newSection == NULL) {
      if (SDF_hasSectionListTail(orgSections)) {
	orgSections = SDF_getSectionListTail(orgSections);
      }
      else {
	orgSections = SDF_makeSectionListEmpty();
      }
    }
    else if (!SDF_isEqualSection(newSection, section)) {
      orgSections = SDF_setSectionListHead(orgSections, newSection);
    }
  }
  return orgSections;
}

/*}}}  */
/*{{{  static SDF_ImpSectionList delete_modulename_from_impsections( */

static SDF_ImpSectionList delete_modulename_from_impsections(
                                       SDF_ImpSectionList orgImpSections,
                                       SDF_ModuleId oldModuleName)
{
  if (!SDF_isImpSectionListEmpty(orgImpSections)) {
    SDF_ImpSection impSection  = SDF_getImpSectionListHead(orgImpSections);
    SDF_ImpSection newImpSection = 
      delete_modulename_from_impsection(impSection, oldModuleName);

    if (SDF_hasImpSectionListTail(orgImpSections)) {
      SDF_ImpSectionList impSections = 
        SDF_getImpSectionListTail(orgImpSections);
      SDF_ImpSectionList newImpSections = 
        delete_modulename_from_impsections(impSections, oldModuleName);
      if (!SDF_isEqualImpSectionList(newImpSections, impSections)) {
        orgImpSections = SDF_setImpSectionListTail(orgImpSections, 
                                                   newImpSections);
      }
    }

    if (newImpSection == NULL) {
      if (SDF_hasImpSectionListTail(orgImpSections)) {
	orgImpSections = SDF_getImpSectionListTail(orgImpSections);
      }
      else {
	orgImpSections = SDF_makeImpSectionListEmpty();
      }
    }
    else if (!SDF_isEqualImpSection(newImpSection, impSection)) {
      orgImpSections = SDF_setImpSectionListHead(orgImpSections, 
                                                 newImpSection);
    }
  }
  return orgImpSections;
}

/*}}}  */

/*{{{  SDF_Module rename_modulename_in_module(SDF_Module module, */

SDF_Module rename_modulename_in_module(SDF_Module module,
                                       SDF_ModuleId oldModuleName,
                                       SDF_ModuleId newModuleName)
{
  SDF_Sections sections = SDF_getModuleSections(module);
  SDF_ImpSectionList impSections = SDF_getModuleList(module);
  SDF_ImpSectionList newImpSections =
    rename_modulename_in_impsections(impSections, oldModuleName, newModuleName);

  module = SDF_setModuleList(module, newImpSections);

  if (SDF_hasSectionsList(sections)) {
    SDF_SectionList sectionList = SDF_getSectionsList(sections);
    SDF_SectionList newSectionList =
      rename_modulename_in_sectionlist(sectionList, 
                                       oldModuleName, 
                                       newModuleName);
    SDF_Sections newSections = SDF_setSectionsList(sections, newSectionList);
    module = SDF_setModuleSections(module, newSections);
  }

  return module;
}

/*}}}  */
/*{{{  SDF_Symbol replaceParametersInParameter(SDF_Symbol localParam, */
 
static
SDF_Symbol replaceParametersInParameter(SDF_Symbol localParam,
                                        SDF_Symbols formalParams,
                                        SDF_Symbols actualParams)
{
  SDF_Symbol formalParam, actualParam;
  SDF_SymbolList formalParamList = SDF_getSymbolsList(formalParams);
  SDF_SymbolList actualParamList = SDF_getSymbolsList(actualParams);
 
  while (SDF_hasSymbolListHead(formalParamList)) {
    formalParam = SDF_getSymbolListHead(formalParamList);
    if (SDF_hasSymbolListHead(actualParamList)) {
      actualParam = SDF_getSymbolListHead(actualParamList);
    }
    else {
      break;
    }
 
    if (SDF_isEqualSymbol(localParam, formalParam)) {
      return actualParam;
    }
 
    if (SDF_hasSymbolListTail(formalParamList)) {
      formalParamList = SDF_getSymbolListTail(formalParamList);
      if (SDF_hasSymbolListTail(actualParamList)) {
        actualParamList = SDF_getSymbolListTail(actualParamList);
      }
      else {
        break;
      }
    }
    else {
      break;
    }
  }
  return localParam;
}
 
/*}}}  */
/*{{{  SDF_SymbolList replaceParametersInParameters(SDF_SymbolList localParamList, */
 
static
SDF_SymbolList replaceParametersInParameters(SDF_SymbolList localParamList,
                                             SDF_Symbols formalParams,
                                             SDF_Symbols actualParams)
{
  SDF_Symbol localParam;
  SDF_SymbolList paramListTail;
 
  if (!SDF_isSymbolListEmpty(localParamList)) {
    localParam = SDF_getSymbolListHead(localParamList);
    localParam = replaceParametersInParameter(localParam,
                                              formalParams,
                                              actualParams);
    localParamList = SDF_setSymbolListHead(localParamList, localParam);
 
    if (SDF_hasSymbolListTail(localParamList)) {
      paramListTail = SDF_getSymbolListTail(localParamList);
      paramListTail = replaceParametersInParameters(paramListTail,
                                                    formalParams,
                                                    actualParams);
      localParamList = SDF_setSymbolListTail(localParamList, paramListTail);
    }
  }
  return localParamList;
}
 
/*}}}  */
/*{{{  SDF_Import replaceParametersInImport(SDF_Import import, */
 
static
SDF_Import replaceParametersInImport(SDF_Import import,
                                     SDF_Symbols formalParams,
                                     SDF_Symbols actualParams)
{
  SDF_ModuleName moduleName = SDF_getImportModuleName(import);
 
  if (SDF_isModuleNameParameterized(moduleName)) {
    SDF_Symbols localParams = SDF_getModuleNameParams(moduleName);
 
    if (SDF_isEqualSymbols(localParams, formalParams)) {
      moduleName = SDF_setModuleNameParams(moduleName, actualParams);
    }
    else {
      SDF_SymbolList localParamList = SDF_getSymbolsList(localParams);
      localParamList = replaceParametersInParameters(localParamList,
                                                     formalParams,
                                                     actualParams);
      localParams = SDF_setSymbolsList(localParams, localParamList);
      moduleName = SDF_setModuleNameParams(moduleName, localParams);
    }
    import = SDF_setImportModuleName(import, moduleName);
  }
  return import;
}
 
/*}}}  */
/*{{{  SDF_ImportList replaceParametersInImportList(SDF_ImportList importList, */
 
SDF_ImportList replaceParametersInImportList(SDF_ImportList importList,
                                             SDF_Symbols formalParams,
                                             SDF_Symbols actualParams)
{
  SDF_Import head, newHead;
  SDF_ImportList tail, newTail;
 
  if (SDF_hasImportListHead(importList)) {
    head = SDF_getImportListHead(importList);
 
    newHead = replaceParametersInImport(head, formalParams, actualParams);
    importList = SDF_setImportListHead(importList, newHead);
 
    if (SDF_hasImportListTail(importList)) {
      tail = SDF_getImportListTail(importList);
 
      newTail = replaceParametersInImportList(tail, formalParams, actualParams);
      importList = SDF_setImportListTail(importList, newTail);
    }
  }
  return importList;
}
 
/*}}}  */
/*{{{  SDF_ImportList renameParametersInImportList(SDF_ModuleName moduleName,  */
 
SDF_ImportList renameParametersInImportList(SDF_ModuleName moduleName,
                                            SDF_Module sdfModule,
                                            SDF_ImportList importList)
{
  SDF_Symbols actualParams = SDF_getModuleNameParams(moduleName);
  SDF_Symbols formalParams = SDF_getModuleNameParams(
                               SDF_getModuleModuleName(sdfModule));
 
  return replaceParametersInImportList(importList, formalParams, actualParams);
}
 
/*}}}  */

/*{{{  SDF_Module delete_modulename_from_module(SDF_Module module, */

SDF_Module delete_modulename_from_module(SDF_Module module,
                                       SDF_ModuleId oldModuleName)
{
  SDF_Sections sections = SDF_getModuleSections(module);
  SDF_ImpSectionList impSections = SDF_getModuleList(module);
  SDF_ImpSectionList newImpSections =
    delete_modulename_from_impsections(impSections, oldModuleName);

  if (newImpSections == NULL) {
    newImpSections = SDF_makeImpSectionListEmpty();
  }

  module = SDF_setModuleList(module, newImpSections);

  if (SDF_hasSectionsList(sections)) {
    SDF_SectionList sectionList = SDF_getSectionsList(sections);
    SDF_SectionList newSectionList =
      delete_modulename_from_sectionlist(sectionList, oldModuleName); 
    SDF_Sections newSections = SDF_setSectionsList(sections, newSectionList);
    module = SDF_setModuleSections(module, newSections);
  }

  return module;
}

/*}}}  */
