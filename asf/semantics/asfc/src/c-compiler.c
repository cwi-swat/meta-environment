#include <stdlib.h>
#include <stdio.h>
#include <aterm1.h>

#define COMPILER "gcc"
#define OPTIMIZE_FLAGS "-O4"

extern ATbool run_verbose;

void call_c_compiler(const char* name, const char* source)
{
  char commandline[1024];

  sprintf(commandline,
         COMPILER " " OPTIMIZE_FLAGS " "
	 " %s "
	 "-o %s "
	 "%s "
	 "-I" ASC_SUPPORT "/include "
	 "-I" PT_SUPPORT "/include "
	 "-I" ATERM "/include "
	 "-L" ASC_SUPPORT "/lib" " -lasc-support-me "
	 "-L" PT_SUPPORT "/lib" " -lmept "
	 "-L" ATERM "/lib" " -lATerm "
	 "-DMAIN_%s"
	 "%s",
	 run_verbose ? "-Wall" : "",
	 name, 
	 source,
	 name,
	 run_verbose ? "" : ">& /dev/null" 
	 );

  if (run_verbose) {
    ATwarning("calling " COMPILER ":\n%s\n",commandline);
  }
  
  system(commandline);
}
