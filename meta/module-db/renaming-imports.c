#include "module-db.h"
#include "renaming-imports.h"

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

