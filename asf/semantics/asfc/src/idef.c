#include <stdlib.h>
#include <stdio.h>
#include <aterm1.h>

extern ATbool run_verbose;

void make_idef_script(char *name)
{
  char file[1024];
  FILE *fp;

  sprintf(file, "%s.idef", name);

  fp = fopen(file,"wb");

  if (fp == NULL) {
    ATerror("Error: unable to open %s for writing\n", file);
  }
  else {
    fprintf(fp,
	    "process %s is\n"
	    "let\n"
	    "%sTool : tool%s,\n"
	    "Term       : term,\n"
	    "Args       : list,\n"
	    "Id         : term,\n"
	    " Function   : str,\n"
	    " Sort       : str\n"

	    "in\n"
	    "  Id := process-id .\n"
	    "  (\n"
	    "    (\n"
	    "      rec-msg(rewrite(\"%s\", Term?)) .\n"
	    "      execute(tool%s, %sTool?) .\n"
	    "      snd-eval(%sTool, rewrite(Term))\n"
	    "    +\n"
	    "      rec-msg(apply-rewrite(\"%s\", Function?, Sort?, Args?)).\n"
	    "      execute(tool%s, %sTool?) .\n"
	    "      snd-eval(%sTool, apply(Function,Sort,Args))\n"
	    "    ).\n"
	    "    rec-value(%sTool, normalform(Term?)) .\n"
            "    snd-terminate(%sTool,\"done\").\n"
            "    snd-msg(normalform(\"%s\", Term)).\n"
            "    Term := null\n"
            "  ) *\n"
            "  delta\n"
            "endlet\n\n" 
            "tool tool%s is { command = \"%s\" }\n",
    name, name, name, name, name,
    name, name, name, name, name,
    name, name, name, name, name,
    name );

    fclose(fp);
  }
}

void idef2c(char *name) {
  char commandline[1024];

  sprintf(commandline,IDEF2TIF " %s.idef", name);
  if (run_verbose) {
    ATwarning("%s\n",commandline);
  }
  system(commandline);
  sprintf(commandline,TIFSTOC " -tool %s %s.tifs", name, name);
  if (run_verbose) {
    ATwarning("%s\n",commandline);
  }
  system(commandline);
}
