#include <aterm1.h>

#include "module-store.h"
#include "table.h"

int main(int argc, char *argv[])
{
  ATerm bottom;
  Table table;

  ATinit(argc,argv,&bottom);

  initModuleStore();
  destroyModuleStore(); 

  return 0;
}
