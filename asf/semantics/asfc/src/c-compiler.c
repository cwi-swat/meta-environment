#include <stdlib.h>
#include <stdio.h>
#include <aterm1.h>

#define BUFFER_SIZE 10240

extern ATbool run_verbose;
extern ATbool make_toolbus_tool;

void call_c_compiler(ATbool keep_annos,
		     const char* binary, const char* name, const char* source)
{
  char commandline[BUFFER_SIZE];
  char sourcefiles[BUFFER_SIZE];

  if (make_toolbus_tool) {
    sprintf(sourcefiles, "%s tool%s.tif.c", source, name);
  }
  else {
    sprintf(sourcefiles, "%s", source);
  }

  sprintf(commandline,
         COMPILER " " COMPILERFLAGS 
	 " -o %s "
	 "%s \\\n"
	 "\t" ASC_INCLUDES "\\\n"
	 "\t" ASC_LD_FLAGS "\\\n"
	 "\t-DASF_MAIN %s\n",
	 binary, 
	 sourcefiles,
	 keep_annos ? "-DASF_WITH_ANNOS" : ""
	 );

  if (run_verbose) {
    ATwarning("%s\n",commandline);
  }
  
  system(commandline);
}
