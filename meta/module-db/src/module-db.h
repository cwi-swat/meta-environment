#ifndef MODULE_DB_H
#define MODULE_DB_H

SDF_ImportList MDB_getImports(ATerm moduleName);
ATermList MDB_getImportIds(ATerm moduleName);
SDF_Symbols MDB_getFormalParams(ATerm moduleId);
ATermList MDB_unavailableImportedModules(ATerm moduleName);
ATerm MDB_retrieveImportGraph();
ATerm MDB_getSdfDefinition(ATerm moduleName);
ATermList MDB_getModulesWithoutEqs(ATerm moduleName);
void MDB_updateEqsTree(ATerm moduleName, ATerm tree);
ATerm MDB_getEqsTree(ATerm moduleName);
ATermList MDB_getDependingModules(ATerm moduleName);
void MDB_invalidateModule(ATerm module);
void MDB_invalidateModules(ATermList modules);
void MDB_deleteModuleFromImportsInModules(ATermList modules, ATerm moduleName);

#endif
