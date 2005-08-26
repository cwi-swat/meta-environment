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
	 "\t-I.\\\n"
	 "\t-I" ASC_SUPPORT "/include \\\n"
	 "\t-I" SGLR "/include \\\n"
	 "\t-I" TIDE_SUPPORT "/include \\\n"
	 "\t-I" ASF_SUPPORT "/include \\\n"
	 "\t-I" PT_SUPPORT "/include \\\n"
	 "\t-I" ATERM "/include \\\n"
	 "\t-I" TOOLBUSLIB "/include \\\n"
	 "\t-I" ERROR_SUPPORT "/include \\\n"
	 "\t" ASC_SUPPORT "/lib/libasc-support-me.a \\\n"
	 "\t" SGLR "/lib/libsglr.a \\\n"
	 "\t" TIDE_SUPPORT "/lib/libtide-adapter.a \\\n"
	 "\t" ASF_SUPPORT "/lib/libASFME.a \\\n"
	 "\t" PT_SUPPORT "/lib/libmept.a \\\n"
	 "\t" PT_SUPPORT "/lib/libPTMEPT.a \\\n"
	 "\t" ERROR_SUPPORT "/lib/libErrorAPI.a \\\n"
	 "\t" TOOLBUSLIB "/lib/libATB.a \\\n"
	 "\t" ATERM "/lib/libATerm.a \\\n"
	 "\t" SOCKLIBS "\\\n"
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
