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
         COMPILER " " COMPILERFLAGS " %s "
	 "-o %s "
	 "%s \\\n"
	 "  -I.\\\n"
	 "  -I" ASC_SUPPORT "/include \\\n"
	 "  -I" SGLR "/include \\\n"
	 "  -I" TIDE "/include \\\n"
	 "  -I" ASF_SUPPORT "/include \\\n"
	 "  -I" PT_SUPPORT "/include \\\n"
	 "  -I" ATERM "/include \\\n"
	 "  -I" TOOLBUSLIB "/include \\\n"
	 "  -I" ERROR_SUPPORT "/include \\\n"
	 "  -L" ASC_SUPPORT "/lib" " -lasc-support-me \\\n"
	 "  -L" SGLR "/lib" " -lsglr \\\n"
	 "  -L" TIDE "/lib" " -ltide-adapter \\\n"
	 "  -L" ASF_SUPPORT "/lib" " -lASFME \\\n"
	 "  -L" PT_SUPPORT "/lib" " -lmept -lPTMEPT \\\n"
	 "  -L" ERROR_SUPPORT "/lib" " -lErrorAPI \\\n"
	 "  -L" ATERM "/lib" " -lATerm \\\n"
	 "  -L" TOOLBUSLIB "/lib -lATB \\\n"
	 "  " SOCKLIBS "\\\n"
	 "  -DASF_MAIN %s\n",
	 run_verbose ? "" : "-Wno-unused",
	 binary, 
	 sourcefiles,
	 keep_annos ? "-DASF_WITH_ANNOS" : ""
	 );

  if (run_verbose) {
    ATwarning("%s\n",commandline);
  }
  
  system(commandline);
}
