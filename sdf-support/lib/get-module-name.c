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
