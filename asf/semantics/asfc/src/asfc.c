/* A first version of the COMPILER in ToolBus C. 
   This program is written by Mark van den Brand and
   improved by Pieter Olivier.

   The following functions are available:
   void rec_terminate(ATerm t)
   ATerm generate_code(ATerm modname, ATerm module)
*/

#include <assert.h>
#include <atb-tool.h>
#include <string.h>
#include <ctype.h>
#include <AsFix.h>
#include "aterm2.h"
#include "deprecated.h"

#include <sys/times.h>
#include <stdlib.h>
#include <limits.h>
#include "compiler.tif.h"
#include "support/support.h"
/* For cpu time calculation */
#include <time.h>

extern ATerm pattern_asfix_id;
extern ATerm pattern_asfix_term;

extern void resolve_all();
extern void register_all();
extern void init_all();

ATerm expand_to_asfix(ATerm mod, char *name);
void AFinitExpansionTerms();
void AFinitAsFixPatterns();

ATerm innermost(ATerm t);
ATerm toasfix(ATerm t, ATerm f, ATerm n);
void init_patterns();

void rec_terminate(int cid, ATerm t) 
{
  clock_t cputime;
  float cpusecs;

 /* read the cpu time up till now*/
  cputime = clock();
  cpusecs = (float) ((float) cputime / (float) CLOCKS_PER_SEC);
  ATfprintf(stderr, "Compiler used %f seconds cpu time\n", cpusecs);
  exit(0);
}

ATerm generate_code(int cid, ATerm modname, ATerm module)
{
  char *text, *fname;
  ATerm expmod, reduct, cmod;
  ATerm aname, idname, file, mname, trm;
  int len;
  FILE *output;

  /* Temporary solution to obtain path where generated C files should be
   * stored. We now use the environment variable "COMPILER_OUTPUT" to obtain
   * the directory. When this variable is not defined we use the original
   * value (so the compiler does not depend on this change).
   *
   * Merijn.
   */
  
  char *path = ".";
  if( getenv( "COMPILER_OUTPUT" ) != NULL )
     path = getenv( "COMPILER_OUTPUT" );

ATfprintf(stderr,"generating code for %t\n", modname);
  assert(ATmatchTerm(modname,pattern_asfix_id,&text));
  len = strlen(path) + 1 + strlen(text) + strlen(".asfix");
  fname = malloc(len + 1);
  if(!fname)
    ATerror("Not enough memory\n");
  sprintf(fname, "%s/%s.asfix", path, text);

  expmod = expand_to_asfix(module,fname);
  assert(ATmatchTerm(expmod, pattern_asfix_term, NULL, NULL,
                     &file, NULL, &mname, NULL, &trm, NULL, NULL));
       
ATfprintf(stderr,"Reducing ...\n");
  reduct = innermost(trm);
ATfprintf(stderr,"Reducing finished.\n");

  aname  = ATmake("l(<str>)",fname);
  idname = ATreadFromString("id(\"AsFix2C\")");
  cmod = toasfix(reduct, aname, idname);
  free(fname);
  len = strlen(path) + 1 + strlen(text) + strlen(".c");
  fname = malloc(len + 1);
  if(!fname)
    ATerror("Not enough memory\n");
  sprintf(fname, "%s/%s.c", path, text );

  output = fopen(fname,"w");
  if(!output) 
    ATfprintf(stderr,"Cannot open file %s\n", fname);
  else {
/* ATfprintf(stderr, "asfixfile is %t\n", cmod); */
    ToC_code(cmod,output);
    ATfprintf(output, "\n");
    fclose(output);
  }
  ATfprintf(stderr,"Writing: %s\n", fname);
  free(fname);
  return ATmake("snd-value(c-code-ready)");
}

int main(int argc, char **argv)
{
  int cid;
  ATerm bottomOfStack;
  clock_t cputime;
 
  /* See how much CPU time we use */
  /* Set the clock to zero */
  cputime = clock();

  ATBinit(argc, argv, &bottomOfStack);
  AFinit(argc, argv, &bottomOfStack);

  cid = ATBconnect(NULL, NULL, -1, compiler_handler);

  AFinitExpansionTerms();
  AFinitAsFixPatterns();
  init_patterns();

  c_rehash(INITIAL_TABLE_SIZE);
  register_all();
  resolve_all();
  init_all();

  ATBeventloop();

  return 0;
}
