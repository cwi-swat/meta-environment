#include "SDF-utils.h"

/*{{{  char *SDFgetModuleName(SDF_Module sdfModule) */

char *SDFgetModuleName(SDF_Module sdfModule)
{
  SDF_ModuleName moduleName;
  SDF_ModuleId   moduleId;
  SDF_Lexical    lexical;

  moduleName = SDF_getModuleModuleName(sdfModule);
  moduleId   = SDF_getModuleNameModuleId(moduleName);
  lexical    = SDF_getModuleIdLex(moduleId);

  return ATgetName(ATgetAFun((ATermAppl)lexical));
}

/*}}}  */
