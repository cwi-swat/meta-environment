#include <aterm1.h>

#include "table-store.h"
#include "table.h"

int main(int argc, char *argv[])
{
  ATerm bottom;
  Table table;

  ATinit(argc,argv,&bottom);

  initTableStore();

  addTable("aap");
  addTable("aap");
  removeTable("aap");
  addTable("aap");
  removeTable("monkey");

  table = getTable("aap");

  putValue(table,ATparse("hallo"), (ATermList) ATparse("[hoi]"));

  ATwarning("val: %t\n", getValue(table,ATparse("hallo")));
  return 0;
}
