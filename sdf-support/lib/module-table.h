#ifndef MODULE_TABLE_H
#define MODULE_TABLE_H

#include <aterm2.h>

typedef ATermTable ModuleTable;

ModuleTable MT_createModuleTable();
void MT_destroyModuleTable(ModuleTable table);
void MT_addModule(ModuleTable table, SDF_ModuleId moduleName,
		  SDF_Module module);
void MT_getModule(ModuleTable table, SDF_ModuleId moduleName);

#endif
