#ifndef MODULE_DB_H
#define MODULE_DB_H

SDF_ImportList MDB_getImports(ATerm moduleName);
ATermList MDB_getImportIds(ATerm moduleName);
SDF_Symbols MDB_getFormalParams(ATerm moduleId);
ATermList MDB_unavailableImportedModules(ATerm moduleName);
ATerm MDB_retrieveImportGraph();

#endif
