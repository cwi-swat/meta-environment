#ifndef RENAMING_IMPORTS_H
#define RENAMING_IMPORTS_H
#include <SDFME.h>
#include <MEPT.h>

SDF_ImportList renameParametersInImportList(SDF_ModuleName moduleName,
                                            SDF_Module sdfModule,
                                            SDF_ImportList importList);
SDF_Module rename_modulename_in_module(SDF_Module module,
                                       SDF_ModuleId oldModuleName,
                                       SDF_ModuleId newModuleName);
SDF_Module SO_deleteModuleNameFromModule(SDF_Module module,
                                         SDF_ModuleId oldModuleName);

SDF_ImportList replaceParametersInImportList(SDF_ImportList importList,
                                             SDF_Symbols formalParams,
                                             SDF_Symbols actualParams);
#endif
