
/*{{{  includes */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <ctype.h>

#include <aterm2.h>

#include <MEPT-utils.h>
#include "jitty.h"
#include "jite.tif.h"

/*}}}  */
/*{{{  variables */

static char myarguments[] = "br:s:hi:o:vV";
static char myname[] = "jite";
static char myversion[] = "0.1beta";


/*}}}  */

/*{{{  void usage(char *prg, ATbool is_err) */

/*     Usage: displays helpful usage information
 */

void usage(char *prg, ATbool is_err)
{
  ATwarning("Usage: %s [options]\n"
	    "Options:\n"
	    "\t-h              display help information (usage)\n"
	    "\t-r file         use the rules in |file|\n"
	    "\t-i filename     input from file (default stdin)\n"
	    "\t-o filename     output to file (default stdout)\n"
	    "\t-v              verbose mode\n"
	    "\t-V              reveal program version (i.e. %s)\n",
	    prg, 
	    myversion);
  exit(is_err ? 1 : 0);
}

/*}}}  */
/*{{{  void version(char *prg) */

void version(char *prg)
{
  ATwarning("%s v%s\n", prg, myversion);
  exit(1);
}

/*}}}  */

/* ToolBus interfacing */
/*{{{  void rec_terminate(int cid, ATerm t) */

void rec_terminate(int cid, ATerm t)
{
  exit(0);
}

/*}}}  */

#define implode(t) PT_implodeParseTree((PT_ParseTree) t, ATtrue, ATtrue, ATtrue, ATtrue, ATtrue, ATtrue, ATtrue, ATtrue, ATtrue, ATtrue, ATtrue)

/*{{{  ATerm unquote(ATerm trm)  */

ATerm unquote(ATerm trm) 
{
  ATerm result;

  if (ATgetType(trm) == AT_LIST) {
    ATermList l = (ATermList) trm;
    ATermList n = ATempty;
    
    for (;!ATisEmpty(l); l = ATgetNext(l)) {
      n = ATinsert(n, unquote(ATgetFirst(l)));
    }

    result = (ATerm) ATreverse(n);
  }
  else if (ATgetType(trm) == AT_APPL) {
    ATermList args = ATgetArguments((ATermAppl) trm);
    AFun fun = ATgetAFun((ATermAppl) trm);
    char *name = ATgetName(fun);
    int arity = ATgetArity(fun);

    if (arity == 0 && isdigit(name[0])) {
      int num = atoi(name);
      result = (ATerm) ATmakeInt(num);
    }
    else {
      AFun nfun = ATmakeAFun(name, arity, ATfalse);
      result = (ATerm) ATmakeApplList(nfun, (ATermList) unquote((ATerm) args));
    }
  }
  else {
    result = trm;
  }

  return result;
}

/*}}}  */
/*{{{  ATermList applyToPrefix(ATermList rules, int arity) */

/* converts a list of [a,b,c] tuples to a list of a(b,c) if arity is 2 */

ATermList applyToPrefix(ATermList rules, int arity)
{
  ATermList new = ATempty;

  for(; !ATisEmpty(rules); rules = ATgetNext(rules)) {
    ATermList args = ATgetArguments((ATermAppl)ATgetFirst(rules));
    ATerm name = ATgetFirst(args);
    AFun fun = ATmakeAFun(ATgetName(ATgetAFun(name)),arity,ATfalse);
    args = ATgetNext(args);
    new = ATinsert(new, (ATerm) ATmakeApplList(fun, args));
  }

  return new;
}

/*}}}  */
/*{{{  ATerm jite(char *modname, ATerm eqs, ATerm trm) */

ATerm jite(char *modname, ATerm eqs, ATerm trm)
{
  ATermList signature;
  ATermList modules;
  ATermList rules = ATempty;
  ATermList strategies = ATempty;
  ATerm term;

  /* The signature is a parsed ATerm (came from Sdf2Sig) */
  signature = (ATermList) unquote(ATparse(PT_yieldParseTree(
		(PT_ParseTree) ATgetFirst((ATermList) eqs))));

  /* The jty modules are parse trees over Jitty and concrete syntax */
  modules = (ATermList) ATgetFirst(ATgetNext((ATermList) eqs));

  /* The term is a parse tree over concrete syntax */
  term = implode(trm);

  /* Collect the imploded rules and strategies for every module */
  for(;!ATisEmpty(modules); modules = ATgetNext(modules)) {
    ATerm module = implode(ATgetFirst(modules));
    ATermList modRules;
    ATerm modDefStrat;
    ATermList modStrats;

    if (ATmatch(module, "module([<list>],<term>,[<list>])", 
		&modRules, &modDefStrat, &modStrats)) {
      rules = ATconcat(modRules, rules);
      strategies = ATconcat(modStrats, strategies);
    }
  }

  rules = (ATermList) unquote((ATerm) applyToPrefix(rules,3));
  strategies = (ATermList) unquote((ATerm) applyToPrefix(strategies,1));

 
  ATwarning("signature: %t\n", signature);
  ATwarning("rules: %t\n", rules); 
  ATwarning("strats: %t\n", strategies); 
  JIT_init(signature, rules, strategies, 1, 0);  

  return (ATerm) PT_makeParseTreeTop(PT_makeTreeLit(ATwriteToString(JIT_normalize(term))),0);

}

/*}}}  */

/*{{{  ATerm interpret(int cid, char *modname, ATerm eqs, ATerm trm) */

ATerm interpret(int cid, char *modname, ATerm eqs, ATerm trm)
{
  ATerm result;

  result = jite(modname, eqs, trm);

  return ATmake("snd-value(rewrite-result(<term>))", ATBpack(result));
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;

  FILE *iofile;
#ifdef PROFILING
  struct tms start, rewriting;
  clock_t user, system;
#endif
  int cid;
  int c, toolbus_mode = 0;
  char *input = "-";
  char *output = "-";
  char *rulesfile = "-";
  char *name = "jite";
  int returncode = 0;
  ATbool bafmode = 0;
  ATbool runVerbose = 0;
  ATerm eqs, term, result;

  /*  Check whether we're a ToolBus process  */
  for (c = 1; !toolbus_mode && c < argc; c++) {
    toolbus_mode = !strcmp(argv[c], "-TB_TOOL_NAME");
  }

  ATinit(argc, argv, &bottomOfStack);
  PT_initMEPTApi();

  if (toolbus_mode) {
#ifndef WIN32			/* Code with Toolbus calls, non Windows */
    ATBinit(argc, argv, &bottomOfStack);
    cid = ATBconnect(NULL, NULL, -1, jite_handler);
    ATBeventloop();
#else
    ATwarning("jite: Toolbus cannot be used in Windows.\n");
#endif
  }
  else {
    while ((c = getopt(argc, argv, myarguments)) != -1) {
      switch (c) {
	case 'b': bafmode = !bafmode;              break;
	case 'v': runVerbose = ATtrue;             break;
	case 'r': rulesfile = optarg;              break;
	case 'i': input = optarg;                  break;
	case 'o': output = optarg;                 break;
	case 'V': version(argv[0]);                break;
	case 'h': usage(argv[0], ATfalse);         break;
	default: usage(argv[0], ATtrue);           break;
      }
    }

    /* Get the rules from file */
    if (!(iofile = fopen(rulesfile, "rb"))) {
      ATerror("%s: cannot open %s\n", myname, rulesfile);
    }

    eqs = ATreadFromFile(iofile);
    fclose(iofile);

    /* Get the term from file */
    if (!strcmp(input, "") || !strcmp(input, "-")) {
      iofile = stdin;
    } else if (!(iofile = fopen(input, "rb"))) {
      ATerror("%s: cannot open %s\n", myname, input);
    }

    term = ATreadFromFile(iofile);
    fclose(iofile);

    /* Rewrite the term */
    result = jite(name, eqs, term);

    /* Communicate the reduct out of here */
    if (!strcmp(output, "") || !strcmp(output, "-")) {
      iofile = stdout;
    }
    else if (!(iofile = fopen(output, "wb"))) {
      ATerror("%s: cannot open %s\n", myname, output);
    }

    if (bafmode) {
      ATwriteToBinaryFile(result, iofile);
    }
    else {
      ATwriteToTextFile(result, iofile);
    }

    fclose(iofile);
  }

  return returncode;
}

/*}}}  */
