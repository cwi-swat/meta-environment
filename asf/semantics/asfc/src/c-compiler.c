#include <stdlib.h>
#include <stdio.h>
#include <aterm1.h>

#define COMPILER "gcc"
#define OPTIMIZE_FLAGS "-O4"

extern ATbool run_verbose;

void call_c_compiler(const char* binary, const char* name, const char* source)
{
  char commandline[1024];

  sprintf(commandline,
         COMPILER " " OPTIMIZE_FLAGS " "
	 " %s "
	 "-o %s "
	 "%s \\\n"
	 "  -I" ASC_SUPPORT "/include \\\n"
	 "  -I" PT_SUPPORT "/include \\\n"
	 "  -I" ATERM "/include \\\n"
	 "  -L" ASC_SUPPORT "/lib" " -lasc-support-me \\\n"
	 "  -L" PT_SUPPORT "/lib" " -lmept \\\n"
	 "  -L" ATERM "/lib" " -lATerm \\\n"
	 "  -DMAIN_%s"
	 "%s\n",
	 run_verbose ? "-Wall" : "",
	 binary, 
	 source,
	 name,
	 run_verbose ? "" : ">& /dev/null" 
	 );

  if (run_verbose) {
    ATwarning("%s\n",commandline);
  }
  
  system(commandline);
}
