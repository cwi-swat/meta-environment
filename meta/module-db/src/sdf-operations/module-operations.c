#include <SDFME-utils.h>
#include <string.h>
#include <ctype.h>

#include "module-refactorings.h"
#include "module-operations.h"
#include "../module-db.h"

ATermList SO_transformImportsToImportIds(SDF_ImportList imports)
{
  ATermList ids = ATempty;

  while(!SDF_isImportListEmpty(imports)) {
    SDF_Import import = SDF_getImportListHead(imports);
    SDF_ModuleName moduleName = SDF_getImportModuleName(import);
    ATerm atModuleName = SDF_getModuleNamePlain(moduleName);

    ids = ATinsert(ids, atModuleName);

    if (SDF_hasImportListTail(imports)) {
      imports = SDF_getImportListTail(imports);
    }
    else {
      break;
    }
  }

  return ids; 
}

static ATermList stripImportList(SDF_ImportList imports)
{
  ATermList result = ATempty;

  while (SDF_hasImportListHead(imports)) {
    SDF_Import import = SDF_getImportListHead(imports);

    result = ATinsert(result, SDF_ImportToTerm(import));
   
    if (SDF_hasImportListTail(imports)) {
      imports = SDF_getImportListTail(imports);
    }
    else {
      break;
    }
  }

  return result;
}

ATermList SO_getTransitiveImports(SDF_ImportList todo)
{
  SDF_ImportList result = SDF_makeImportListEmpty();

  while (SDF_hasImportListHead(todo)) {
    SDF_Import     import     = SDF_getImportListHead(todo);
    SDF_ModuleName moduleName = SDF_getImportModuleName(import);
    ATerm          moduleId   = SDF_getModuleNamePlain(moduleName);

    if (!SDF_containsImportListImport(result, import)) {
      SDF_ImportList imports = MDB_getImports(moduleId);

      if (SDF_hasModuleNameParams(moduleName)) {
        SDF_Symbols formals = MDB_getFormalParams(moduleId);
        SDF_Symbols actuals = SDF_getModuleNameParams(moduleName);

        imports = replaceParametersInImportList(imports, formals,
                                                actuals);
      }

      todo = SDF_concatImportList(todo, imports);
      
      if (SDF_isImportListEmpty(result)) {
        result = SDF_makeImportListSingle(import);
      }
      else {
        result = SDF_makeImportListMany(import, 
                                        SDF_makeOptLayoutAbsent(), 
                                        result);
      }
    }

    if (SDF_hasImportListTail(todo)) {
      todo = SDF_getImportListTail(todo);
    }
    else {
      break;
    }
  }
  return stripImportList(result);
}

ATbool SO_checkModuleNameWithPath(const char *moduleName, 
                                  const char *path)
{
  int i,j;
  int pathlen = strlen(path);
  int namelen = strlen(moduleName);
 
  /* first skip extension (may not use knowledge of which extension it is) */
  for(i=pathlen - 1; i >= 0 && path[i] != '.'; i --);
 
  for(j=namelen - 1, --i; i >= 0 && j >= 0; i--, j--) {
    if (moduleName[j] != path[i]) {
      return ATfalse;
    }
    if (!isalnum((int)moduleName[j])
        && moduleName[j] != '-'
        && moduleName[j] != '_'
        && moduleName[j] != '/') {
      return ATfalse;
    }
  }
 
  return ATtrue;
}

SDF_Renamings SO_getModuleRenamings(SDF_Import import, SDF_Module module) 
{
  if (SDF_isImportRenamedModule(import)) {
    return SDF_getImportRenamings(import);
  }
  else {
    SDF_ModuleName actualModuleName = SDF_getImportModuleName(import);

    if (SDF_isModuleNameParameterized(actualModuleName)) {
      SDF_ModuleName formalModuleName = SDF_getModuleModuleName(module);

      return SDF_makeRenamingsFromModuleNames(formalModuleName, 
					      actualModuleName);
    }
    else {
      return (SDF_Renamings)NULL;
    }
  }
}

