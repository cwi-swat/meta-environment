#ifndef TABLE_STORE_H
#define TABLE_STORE_H

#include "table.h"

void  initTableStore();
void  addTable(char *name);
void  removeTable(char *name);
Table getTable(char *name);

#endif
