#include "SDFME-utils.h"

/*{{{  SDF_Import SDF_makeImport(const char *moduleName) */

SDF_Import SDF_makeImport(const char *moduleName)
{
  return SDF_makeImportModule(
           SDF_makeModuleNameUnparameterized(
	     SDF_makeModuleId(moduleName)));
}

/*}}}  */
/*{{{  SDF_ImportList SDF_mergeImportList(SDF_ImportList l1, SDF_ImportList l2) */

SDF_ImportList SDF_mergeImportList(SDF_ImportList l1, SDF_ImportList l2)
{
  while (!SDF_isImportListEmpty(l1)) {
    SDF_Import import = SDF_getImportListHead(l1);

    if (!SDF_containsImportListImport(l2, import)) {
      l2 = SDF_insertImport(import, l2);
    }

    if (SDF_hasImportListTail(l1)) {
      l1 = SDF_getImportListTail(l1);
    }
    else {
      break;
    }
  }

  return l2;
}

/*}}}  */
/*{{{  SDF_ImportList SDF_insertImport(SDF_Import i, SDF_ImportList l) */

SDF_ImportList SDF_insertImport(SDF_Import i, SDF_ImportList l)
{
  if (SDF_isImportListEmpty(l)) {
    return SDF_makeImportListSingle(i);
  }
  else {
    return SDF_makeImportListMany(i, SDF_makeLayoutSpace(), l);
  }
}

/*}}}  */
/*{{{  ATbool SDF_containsImportListImport(SDF_ImportList list,  */

ATbool SDF_containsImportListImport(SDF_ImportList list, 
                                    SDF_Import  import)
{
  return (ATindexOf((ATermList) SDF_ImportListToTerm(list), 
                    SDF_ImportToTerm(import), 0) != -1);
}

/*}}}  */
/*{{{  SDF_Module SDF_addModuleImport(SDF_Module module, SDF_Import import) */

SDF_Module SDF_addModuleImport(SDF_Module module, SDF_Import import)
{
  SDF_OptLayout s = SDF_makeLayoutSpace();
  SDF_OptLayout nl = SDF_makeLayoutNewline();

  SDF_ImpSectionList list = SDF_getModuleList(module);
  SDF_ImportList ilist = SDF_makeImportListSingle(import);
  SDF_Imports imports = SDF_makeImportsDefault(ilist);
  SDF_ImpSection section = SDF_makeImpSectionImports(s, imports);
  
  list = SDF_makeImpSectionListMany(section, nl, list);

  return SDF_setModuleList(module, list);
}

/*}}}  */
static SDF_ImportList SDF_removeImportFromImportList(
			    SDF_ImportList orgImports,
			    SDF_ModuleId moduleId)
{
  if (!SDF_isImportListEmpty(orgImports)) {
    SDF_Import import = SDF_getImportListHead(orgImports);
    SDF_ModuleName moduleName = SDF_getImportModuleName(import);
    SDF_ModuleId localModuleId = SDF_getModuleNameModuleId(moduleName);
    if (SDF_hasImportListTail(orgImports)) {
      SDF_ImportList imports = SDF_getImportListTail(orgImports);
      SDF_ImportList newImports =
        SDF_removeImportFromImportList(imports, moduleId);
      if (!SDF_isEqualImportList(newImports, imports)) {
        orgImports = SDF_setImportListTail(orgImports, newImports);
      }
    }

    moduleId = SDF_ModuleIdFromTerm(
      ATremoveAllAnnotations(SDF_ModuleIdToTerm(moduleId)));
    localModuleId = SDF_ModuleIdFromTerm(
      ATremoveAllAnnotations(SDF_ModuleIdToTerm(localModuleId)));
    if (SDF_isEqualModuleId(localModuleId, moduleId)) {
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
static SDF_ImpSection SDF_removeImportFromImportSection(
			    SDF_ImpSection orgImpSection,
			    SDF_ModuleId moduleId)
{
  SDF_Imports    imports     = SDF_getImpSectionList(orgImpSection);
  SDF_ImportList importsList = SDF_getImportsList(imports);

  SDF_ImportList newImportsList =
    SDF_removeImportFromImportList(importsList, moduleId);
  SDF_Imports newImports;

  if (SDF_isImportListEmpty(newImportsList)) {
    return NULL;
  }

  newImports = SDF_setImportsList(imports, newImportsList);

  return SDF_setImpSectionList(orgImpSection, newImports);
}

static SDF_ImpSectionList SDF_removeImportFromImportSectionList(
			    SDF_ImpSectionList orgImpSections,
			    SDF_ModuleId moduleId)
{
  if (!SDF_isImpSectionListEmpty(orgImpSections)) {
    SDF_ImpSection impSection  = SDF_getImpSectionListHead(orgImpSections);
    SDF_ImpSection newImpSection =
      SDF_removeImportFromImportSection(impSection, moduleId);

    if (SDF_hasImpSectionListTail(orgImpSections)) {
      SDF_ImpSectionList impSections =
      SDF_getImpSectionListTail(orgImpSections);
      SDF_ImpSectionList newImpSections =
        SDF_removeImportFromImportSectionList(impSections, moduleId);
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
static SDF_Grammar SDF_removeImportFromGrammar(
                         SDF_Grammar orgGrammar,
                         SDF_ModuleId moduleId)
{    
  if (SDF_isGrammarImpSection(orgGrammar)) {
    SDF_ImpSection impSection = SDF_getGrammarImpSection(orgGrammar);
    SDF_ImpSection newImpSection =
      SDF_removeImportFromImportSection(impSection, moduleId);
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
      SDF_removeImportFromGrammar(leftGrammar, moduleId);
    SDF_Grammar newRightGrammar =
      SDF_removeImportFromGrammar(rightGrammar, moduleId);

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

static SDF_Section SDF_removeImportFromSection(
                         SDF_Section orgSection,
                         SDF_ModuleId moduleId)
{       
  if (SDF_hasSectionGrammar(orgSection)) {
    SDF_Grammar grammar  = SDF_getSectionGrammar(orgSection);
    SDF_Grammar newGrammar = 
      SDF_removeImportFromGrammar(grammar, moduleId);
  
    if (newGrammar != NULL) {
      orgSection = SDF_setSectionGrammar(orgSection, newGrammar);
    }   
    else {
      orgSection = NULL;
    } 
  }     
  return orgSection;
}

static SDF_SectionList SDF_removeImportFromSectionList(
                         SDF_SectionList orgSections,
                         SDF_ModuleId moduleId)
{       
  if (!SDF_isSectionListEmpty(orgSections)) {
    SDF_Section section  = SDF_getSectionListHead(orgSections);
    SDF_Section newSection = 
      SDF_removeImportFromSection(section, moduleId);

    if (SDF_hasSectionListTail(orgSections)) {
      SDF_SectionList sections =
        SDF_getSectionListTail(orgSections);
      SDF_SectionList newSections =
        SDF_removeImportFromSectionList(sections, moduleId);
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

/*{{{  SDF_Module SDF_removeModuleImport(SDF_Module module, SDF_Import import) */

SDF_Module SDF_removeModuleImport(SDF_Module module, SDF_Import import)
{
  SDF_Sections sections = SDF_getModuleSections(module);
  SDF_ImpSectionList impSections = SDF_getModuleList(module);
  SDF_ModuleName moduleName = SDF_getImportModuleName(import);
  SDF_ModuleId moduleId = SDF_getModuleNameModuleId(moduleName);
  SDF_ImpSectionList newImpSections =
    SDF_removeImportFromImportSectionList(impSections, moduleId);

  if (newImpSections == NULL) {
    newImpSections = SDF_makeImpSectionListEmpty();
  }

  module = SDF_setModuleList(module, newImpSections);

  if (SDF_hasSectionsList(sections)) {
    SDF_SectionList sectionList = SDF_getSectionsList(sections);
    SDF_SectionList newSectionList =
       SDF_removeImportFromSectionList(sectionList, moduleId);
    SDF_Sections newSections = SDF_setSectionsList(sections, newSectionList);
    module = SDF_setModuleSections(module, newSections);
  }

  return module;
}

/*}}}  */
