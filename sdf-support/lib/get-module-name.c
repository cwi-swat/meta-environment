#include "SDFME-utils.h"

/*{{{  char *SDF_getModuleName(SDF_Module sdfModule) */

char *SDF_getModuleName(SDF_Module sdfModule)
{
  SDF_ModuleName moduleName;
  SDF_ModuleId   moduleId;

  moduleName = SDF_getModuleModuleName(sdfModule);
  moduleId   = SDF_getModuleNameModuleId(moduleName);

  return SDF_getCHARLISTString(SDF_getModuleIdChars(moduleId));
}

/*}}}  */
/*{{{  SDF_ModuleId SDFmakeModuleId(char *moduleName) */

SDF_ModuleId SDF_makeModuleId(char *moduleStr)   
{
  return SDF_makeModuleIdWord(SDF_makeCHARLISTString(moduleStr));
}
/*}}}  */
/*{{{  SDF_Module SDFmakeModuleName(char *moduleName) */

SDF_ModuleName SDF_makeModuleName(char *moduleStr)   
{
  return SDF_makeModuleNameUnparameterized(
           SDF_makeModuleId(moduleStr));
}
/*}}}  */
/*{{{  SDF_Module SDFsetModuleName(SDF_Module sdfModule, char *moduleName) */

SDF_Module SDF_setModuleName(SDF_Module sdfModule, char *newName)
{
  SDF_ModuleName oldModuleName, newModuleName;
  SDF_ModuleId   moduleId = SDF_makeModuleId(newName);

  oldModuleName = SDF_getModuleModuleName(sdfModule);

  newModuleName = SDF_setModuleNameModuleId(oldModuleName, moduleId);

  return SDF_setModuleModuleName(sdfModule, newModuleName);
}

/*}}}  */
