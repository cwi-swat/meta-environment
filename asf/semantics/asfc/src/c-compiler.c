#include <stdlib.h>
#include <stdio.h>
#include <aterm1.h>

#define BUFFER_SIZE 10240

extern ATbool run_verbose;

void call_c_compiler(ATbool keep_annos,
		     const char* binary, 
		     const char* name, 
		     const char *stem,
		     const char* output)
{
  char commandline[BUFFER_SIZE];
  char sourcefiles[BUFFER_SIZE];
  char objectfiles[BUFFER_SIZE];

  sprintf(sourcefiles, "%s", output);
  sprintf(objectfiles, "%s.o", stem);

  sprintf(commandline,
         COMPILE " " 
	 "-c %s \\\n"
	 "\t" ASC_SUPPORT_CFLAGS "\\\n"
	 "\t-DASF_MAIN %s\n",
	 sourcefiles,
	 keep_annos ? "-DASF_WITH_ANNOS" : ""
	 );

  if (run_verbose) {
    ATwarning("%s\n",commandline);
  }
  
  system(commandline);

  sprintf(commandline,
         LINK " " 
	 " -o %s "
	 "%s \\\n"
	 "\t" ASC_SUPPORT_LIBS "\\\n"
	 "\t-DASF_MAIN %s\n",
	 binary, 
	 objectfiles,
	 keep_annos ? "-DASF_WITH_ANNOS" : ""
	 );

  if (run_verbose) {
    ATwarning("%s\n",commandline);
  }
  
  system(commandline);
}
