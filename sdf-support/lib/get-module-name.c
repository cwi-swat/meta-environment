#include "SDFME-utils.h"

/*{{{  char *SDF_getModuleName(SDF_Module sdfModule) */

char *SDF_getModuleName(SDF_Module sdfModule)
{
  SDF_ModuleName moduleName;
  SDF_ModuleId   moduleId;

  moduleName = SDF_getModuleModuleName(sdfModule);
  moduleId   = SDF_getModuleNameModuleId(moduleName);

  return SDF_getModuleIdString(moduleId);
}

/*}}}  */
/*{{{  SDF_ModuleId SDF_makeModuleId(const char *moduleStr)    */

SDF_ModuleId SDF_makeModuleId(const char *moduleStr)   
{
  return SDF_makeModuleIdWord(moduleStr);
}

/*}}}  */
/*{{{  SDF_ModuleName SDF_makeModuleName(const char *moduleStr)    */

SDF_ModuleName SDF_makeModuleName(const char *moduleStr)   
{
  return SDF_makeModuleNameUnparameterized(SDF_makeModuleId(moduleStr));
}

/*}}}  */
/*{{{  SDF_Module SDF_setModuleName(SDF_Module sdfModule, const char *newName) */

SDF_Module SDF_setModuleName(SDF_Module sdfModule, const char *newName)
{
  SDF_ModuleName oldModuleName, newModuleName;
  SDF_ModuleId   moduleId = SDF_makeModuleId(newName);

  oldModuleName = SDF_getModuleModuleName(sdfModule);

  newModuleName = SDF_setModuleNameModuleId(oldModuleName, moduleId);

  return SDF_setModuleModuleName(sdfModule, newModuleName);
}

/*}}}  */
