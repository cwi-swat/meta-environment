#ifndef RENAMING_IMPORTS_H
#define RENAMING_IMPORTS_H

SDF_ImportList renameParametersInImportList(SDF_ModuleName moduleName,
                                            PT_Tree sdfTree,
                                            SDF_ImportList importList);
SDF_Module rename_modulename_in_module(SDF_Module module,
                                       SDF_ModuleId oldModuleName,
                                       SDF_ModuleId newModuleName);
#endif
