#include "module-table.h"

#define DEFAULT_MODULE_HASH_TABLE_SIZE  1000
#define MODULE_HASH_TABLE_RESIZE_FACTOR 75

/*{{{  ModuleTable MT_createModuleTable() */

ModuleTable MT_createModuleTable()
{
  ATermTable table  = ATtableCreate(DEFAULT_MODULE_HASH_TABLE_SIZE, 
				    MODULE_HASH_TABLE_RESIZE_FACTOR);

  assert(definition != NULL && "could not create hash table");

  return table;
}

/*}}}  */
/*{{{  void MT_destroyModuleTable(ModuleTable table) */

void MT_destroyModuleTable(ModuleTable table)
{
    ATtableDestroy(table);
} 

/*}}}  */

/*{{{  void MT_putModule(ModuleTable table, SDF_ModuleName moduleName, */

void MT_putModule(ModuleTable table, SDF_ModuleName moduleName,
		  SDF_Module module)
{
  ATtablePut(table, (ATerm) moduleName, (ATerm) module);
}

/*}}}  */
/*{{{  void MT_getModule(ModuleTable table, SDF_ModuleName moduleName) */

void MT_getModule(ModuleTable table, SDF_ModuleName moduleName)
{
  (SDF_Module) ATtableGet(table, (ATerm) moduleName);
}

/*}}}  */
