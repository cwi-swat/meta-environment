#include "module-table.h"
#include <assert.h>

#define DEFAULT_MODULE_HASH_TABLE_SIZE  1000
#define MODULE_HASH_TABLE_RESIZE_FACTOR 75

/*{{{  ModuleTable MT_createModuleTable() */

ModuleTable MT_createModuleTable()
{
  ATermTable table  = ATtableCreate(DEFAULT_MODULE_HASH_TABLE_SIZE, 
				    MODULE_HASH_TABLE_RESIZE_FACTOR);

  assert(table != NULL && "could not create hash table");

  return (ModuleTable) table;
}

/*}}}  */
/*{{{  void MT_destroyModuleTable(ModuleTable table) */

void MT_destroyModuleTable(ModuleTable table)
{
    ATtableDestroy(table);
} 

/*}}}  */

/*{{{  void MT_putModule(ModuleTable table, SDF_ModuleName moduleName, */

void MT_putModule(ModuleTable table, SDF_ModuleId id,
		  SDF_Start module)
{
  ATtablePut(table, (ATerm) id, (ATerm) module);
}

/*}}}  */
/*{{{  SDF_Module MT_getModule(ModuleTable table, SDF_ModuleName moduleName) */

SDF_Start MT_getModule(ModuleTable table, SDF_ModuleId id)
{
  return (SDF_Start) ATtableGet(table, (ATerm) id);
}

/*}}}  */

/*{{{  ATermList MT_allModules(ModuleTable table) */

ATermList MT_allModules(ModuleTable table)
{
  return ATtableKeys((ATermTable) table);
}

/*}}}  */
