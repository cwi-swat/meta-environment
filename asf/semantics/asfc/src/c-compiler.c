#include <stdlib.h>
#include <stdio.h>
#include <aterm1.h>

extern ATbool run_verbose;
extern ATbool make_toolbus_tool;

void call_c_compiler(const char* binary, const char* name, const char* source)
{
  char commandline[1024];
  char sourcefiles[1024];

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
	 "  -I" ASF_SUPPORT "/include \\\n"
	 "  -I" PT_SUPPORT "/include \\\n"
	 "  -I" ATERM "/include \\\n"
	 "  -I" ERROR_SUPPORT "/include \\\n"
	 "  -L" ASC_SUPPORT "/lib" " -l%sasc-support-me \\\n"
	 "  -L" SGLR "/lib" " -lsglr \\\n"
	 "  -L" ASF_SUPPORT "/lib" " -lASFME \\\n"
	 "  -L" PT_SUPPORT "/lib" " -lmept -lPTMEPT \\\n"
	 "  -L" ERROR_SUPPORT "/lib" " -lErrorAPI \\\n"
	 "  -L" ATERM "/lib" " -lATerm \\\n"
	 "  %s"
	 "  -DASF_MAIN"
	 "  %s\n",
	 run_verbose ? "" : "-Wno-unused",
	 binary, 
	 sourcefiles,
	 make_toolbus_tool ? "tb-" : "",
	 make_toolbus_tool ? "-L" TOOLBUSLIB "/lib -lATB \\\n": "",
	 make_toolbus_tool ? "  -DTOOLBUS " : ""
	 );

  if (run_verbose) {
    ATwarning("%s\n",commandline);
  }
  
  system(commandline);
}
