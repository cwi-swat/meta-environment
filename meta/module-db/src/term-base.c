#include <aterm1.h>

#include "module-store.h"
#include "table.h"

int main(int argc, char *argv[])
{
  ATerm bottom;

  ATinit(argc,argv,&bottom);

  MS_initModuleStore();
  MS_destroyModuleStore(); 

  return 0;
}
