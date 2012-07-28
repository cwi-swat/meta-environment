#include "SDFME-utils.h"
#include <string.h>

/*{{{  SDF_ModuleId SDF_getModuleName(SDF_Module sdfModule) */

SDF_ModuleId SDF_getModuleName(SDF_Module sdfModule)
{
  SDF_ModuleName moduleName;
  SDF_ModuleId   moduleId;

  moduleName = SDF_getModuleModuleName(sdfModule);
  moduleId   = SDF_getModuleNameModuleId(moduleName);

  return moduleId;
}

/*}}}  */
/*{{{  SDF_ModuleId SDF_makeModuleId(const char *moduleStr)    */

SDF_ModuleId SDF_makeModuleId(const char *moduleStr)   
{
  const char *sep = "/";
  char *token = NULL;
  char *tmp = strdup(moduleStr);
  SDF_LexModuleId id = NULL;
  ATermList words = ATempty;

  token = strtok(tmp, sep);

  do {
    words = ATinsert(words, ATmake("<str>", token));
  } while ((token = strtok(NULL, sep)) != NULL);

  for ( ; !ATisEmpty(words); words = ATgetNext(words)) {
    char *str = ATgetName(ATgetAFun(ATgetFirst(words)));
    SDF_LexModuleWord word = SDF_makeLexModuleWordWord(str);

      
    if (id == NULL) {
      id = SDF_makeLexModuleIdLeaf(word);
    }
    else {
      if (strlen(str) == 0 && ATgetLength(words) == 1) {
	id = SDF_makeLexModuleIdRoot(id);
      }
      else if (strlen(str) != 0) {
	id = SDF_makeLexModuleIdPath(word, id);
      }
    }
  }

  free(tmp);

  return SDF_makeModuleIdLexToCf(id);
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
