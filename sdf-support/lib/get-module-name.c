#include "SDFME-utils.h"
#include "MEPT-utils.h"

/*{{{  char *SDFgetModuleName(SDF_Module sdfModule) */

char *SDFgetModuleName(SDF_Module sdfModule)
{
  SDF_ModuleName moduleName;
  SDF_ModuleId   moduleId;

  moduleName = SDF_getModuleModuleName(sdfModule);
  moduleId   = SDF_getModuleNameModuleId(moduleName);

  return PT_yieldTree(SDF_getModuleIdLex(moduleId));
}

/*}}}  */
/*{{{  SDF_Module SDFmakeModuleName(char *moduleName) */

SDF_ModuleName SDFmakeModuleName(char *moduleStr)   
{
  return SDF_makeModuleNameUnparameterized(
           SDF_makeModuleIdLexToCf(
             (SDF_Lexical)PT_makeTreeFlatLexicalFromString(moduleStr)));
}
/*}}}  */
/*{{{  SDF_Module SDFsetModuleName(SDF_Module sdfModule, char *moduleName) */

SDF_Module SDFsetModuleName(SDF_Module sdfModule, char *newName)
{
  SDF_ModuleName oldModuleName, newModuleName;
  SDF_ModuleId   moduleId;

  oldModuleName = SDF_getModuleModuleName(sdfModule);

  moduleId   = SDF_makeModuleIdLexToCf(
                 (SDF_Lexical)PT_makeTreeFlatLexicalFromString(newName));
  newModuleName = SDF_setModuleNameModuleId(oldModuleName, moduleId);

  return SDF_setModuleModuleName(sdfModule, newModuleName);
}

/*}}}  */
