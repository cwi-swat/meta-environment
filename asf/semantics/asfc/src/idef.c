#include <stdlib.h>
#include <stdio.h>
#include <aterm1.h>

#define BUFFER_SIZE 10240

extern ATbool run_verbose;

void make_idef_script(const char *prefix, const char *name)
{
  char file[BUFFER_SIZE];
  FILE *fp;

  sprintf(file, "%s.idef", prefix);

  fp = fopen(file,"wb");

  if (fp == NULL) {
    ATerror("Error: unable to open %s for writing\n", file);
  }
  else {
    fprintf(fp,
	    "process %s is\n"
	    "let\n"
	    "  %sTool : tool%s,\n"
	    "  Term       : term,\n"
	    "  Args       : list,\n"
	    "  Function   : str,\n"
	    "  Sort       : str\n"
	    "in\n"
	    "  (\n"
	    "    (\n"
	    "      rec-msg(rewrite(\"%s\", Term?)) .\n"
	    "      execute(tool%s, %sTool?) .\n"
	    "      snd-eval(%sTool, rewrite(Term))\n"
	    "    +\n"
	    "      rec-msg(apply-rewrite(\"%s\", Function?, Sort?, Args?)).\n"
	    "      execute(tool%s, %sTool?) .\n"
	    "      snd-eval(%sTool, apply-rewrite(Function,Sort,Args))\n"
	    "    ).\n"
	    "    rec-value(%sTool, normalform(Term?)) .\n"
            "    snd-terminate(%sTool,\"done\").\n"
            "    snd-msg(normalform(\"%s\", Term)).\n"
            "    Term := null\n"
            "  ) *\n"
            "  delta\n"
            "endlet\n\n" 
            "tool tool%s is { command = \"%s\" }\n"
	    "toolbus(%s)\n",
    name, name, name, name, name,
    name, name, name, name, name,
    name, name, name, name, name,
    name, name );

    fclose(fp);
  }
}

void idef2c(const char *prefix, const char *name) {
  char commandline[BUFFER_SIZE];
  char ideffilename[BUFFER_SIZE];
  char tifsfilename[BUFFER_SIZE];

  sprintf(ideffilename, "%s.idef", prefix);
  sprintf(commandline,"%s %s",IDEF2TIF, ideffilename);

  if (run_verbose) {
    ATwarning("%s\n",commandline);
  }
  system(commandline);

  sprintf(tifsfilename, "%s.tifs", prefix);
  sprintf(commandline,"%s -tool tool%s %s", TIFSTOC, name, tifsfilename);
  if (run_verbose) {
    ATwarning("%s\n",commandline);
  }
  system(commandline);
}
