#include "table-store.h"
#include "table.h"

void ES_initExtensionStore()
{
  TS_initTableStore();
  TS_addTable("extensions");
}

void ES_destroyExtensionStore()
{
  TS_removeTable("extensions");
}

void ES_addExtension(char *type, char *extension)
{
  TS_putValue("extensions", makeKey(type), 
              makeValue(makeString(extension)));
}

char *ES_getExtension(char *type)
{
  return getString(getValue(TS_getValue("extensions", 
                                        makeKey(type))));
}
