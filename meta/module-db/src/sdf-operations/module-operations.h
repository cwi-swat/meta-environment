#ifndef MODULE_OPERATIONS_H
#define MODULE_OPERATIONS_H
#include <SDFME.h>
#include <MEPT.h>

ATermList SO_transformImportsToImportIds(SDF_ImportList imports);
ATermList SO_getTransitiveImports(SDF_ImportList imports);
ATbool SO_checkModuleNameWithPath(const char *moduleName, const char *path);
SDF_Renamings SO_getModuleRenamings(SDF_Import import, SDF_Module module);

#endif
