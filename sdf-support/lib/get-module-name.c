#include "SDFME-utils.h"
#include "MEPT-utils.h"

/*{{{  char *SDFgetModuleName(SDF_Module sdfModule) */

char *SDFgetModuleName(SDF_Module sdfModule)
{
  SDF_ModuleName moduleName;
  SDF_ModuleId   moduleId;

  moduleName = SDF_getModuleModuleName(sdfModule);
  moduleId   = SDF_getModuleNameModuleId(moduleName);

  return SDF_getCHARLISTString(SDF_getModuleIdChars(moduleId));
}

/*}}}  */
/*{{{  SDF_ModuleId SDFmakeModuleId(char *moduleName) */

SDF_ModuleId SDFmakeModuleId(char *moduleStr)   
{
  return SDF_makeModuleIdWord(SDF_makeCHARLISTString(moduleStr));
}
/*}}}  */
/*{{{  SDF_Module SDFmakeModuleName(char *moduleName) */

SDF_ModuleName SDFmakeModuleName(char *moduleStr)   
{
  return SDF_makeModuleNameUnparameterized(
           SDFmakeModuleId(moduleStr));
}
/*}}}  */
/*{{{  SDF_Module SDFsetModuleName(SDF_Module sdfModule, char *moduleName) */

SDF_Module SDFsetModuleName(SDF_Module sdfModule, char *newName)
{
  SDF_ModuleName oldModuleName, newModuleName;
  SDF_ModuleId   moduleId = SDFmakeModuleId(newName);

  oldModuleName = SDF_getModuleModuleName(sdfModule);

  newModuleName = SDF_setModuleNameModuleId(oldModuleName, moduleId);

  return SDF_setModuleModuleName(sdfModule, newModuleName);
}

/*}}}  */
