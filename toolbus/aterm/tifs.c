/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>

#include <atb-tool.h>

#include "tifs.h"

/*}}}  */
/*{{{  defines */

#define strprefix(a,b)  (!strncmp((a),(b),strlen(b)))

/*}}}  */

/*{{{  ATermList read_tifs_from_fd(int fd) */

ATermList read_tifs_from_fd(int fd)
{
  ATerm tif;
  ATermList tifs = ATempty;
  ATermPlaceholder ph;
  char *primitive;

  do {
    tif = ATBreadTerm(fd);
    if (ATmatch(tif, "<appl(<placeholder>,<list>)>", &primitive, &ph, NULL)) {
	tifs = ATinsert(tifs, tif);
    }
  } while(!ATmatch(tif, "end-of-tifs"));

  return tifs;
}

/*}}}  */
/*{{{  ATermList read_tifs_from_named_file(const char *file) */

ATermList read_tifs_from_named_file(const char *file)
{
  int fd;
  ATermList tifs;

  fd = open(file, O_RDONLY);
  if (fd < 0) {
    ATerror("cannot open tifs file %s\n", file);
  }

  tifs = read_tifs_from_fd(fd);

  close(fd);

  return tifs;
}

/*}}}  */

/*{{{  void write_tifs_to_named_file(ATermList tifs, const char *file) */

void write_tifs_to_named_file(ATermList tifs, const char *file)
{
  FILE *f;
  int fd;

  f = fopen(file, "w");
  if (f == NULL) {
    perror(file);
    exit(1);
  }
  fd = fileno(f);

  while (!ATisEmpty(tifs)) {
    ATerm tif = ATgetFirst(tifs);
    ATBwriteTerm(fd, tif);
    tifs = ATgetNext(tifs);
  }

  ATBwriteTerm(fd, ATparse("end-of-tifs"));

  fclose(f);
}

/*}}}  */

/*{{{  ATermList extract_rec_from_tifs(ATermList tifs) */

ATermList extract_rec_from_tifs(ATermList tifs)
{
  ATermList result = ATempty;

  while (!ATisEmpty(tifs)) {
    ATerm tif = ATgetFirst(tifs);
    ATermPlaceholder ph;
    char *primitive;
    if (ATmatch(tif, "<appl(<placeholder>,<list>)>", &primitive, &ph, NULL)) {
      if (strprefix(primitive, "rec-")) {
	result = ATinsert(result, tif);
      }
    }

    tifs = ATgetNext(tifs);
  }

  return result;
}

/*}}}  */
/*{{{  ATermList extract_tool_from_tifs(ATermList tifs, const char *tool) */

ATermList extract_tool_from_tifs(ATermList tifs, const char *tool)
{
  ATermList result = ATempty;

  while (!ATisEmpty(tifs)) {
    ATerm tif = ATgetFirst(tifs);
    ATermPlaceholder ph;
    char *primitive;
    if (ATmatch(tif, "<appl(<placeholder>,<list>)>", &primitive, &ph, NULL)) {
      char *name;
      if (ATmatch((ATerm)ph, "<appl>", &name) && streq(name, tool)) {
	result = ATinsert(result, tif);
      }
    }

    tifs = ATgetNext(tifs);
  }

  return result;
}

/*}}}  */

/*{{{  ATermList generalize_tifs(ATermList tifs) */

ATermList generalize_tifs(ATermList tifs)
{
  ATermList result = ATempty;

  while (!ATisEmpty(tifs)) {
    int i;
    char *name;
    ATermList newargs = ATempty;
    ATerm tif = ATgetFirst(tifs), newtif, tool;
    ATermAppl appl;

    if (ATmatch(tif, "rec-terminate(<term>,<term>)", NULL, NULL)
	|| ATmatch(tif, "rec-ack-event(<term>,<term>)", NULL, NULL)) {
      result = ATinsert(result, tif);
    } else if(ATmatch(tif, "<appl(<term>,<term>)>", &name, &tool, &appl)) {
      Symbol sym = ATgetSymbol(appl);
      for (i=ATgetArity(sym)-1; i>=0; --i) {
	ATerm arg = ATgetArgument(appl, i);
	if (ATisEqual(arg, ATparse("<int>"))
	    || ATisEqual(arg, ATparse("<str>"))
	    || ATisEqual(arg, ATparse("<real>"))) {
	  newargs = ATinsert(newargs, arg);
	}
	else {
	  newargs = ATinsert(newargs, ATparse("<term>"));
	}
      }

      newtif = ATmake("<appl(<term>,<appl(<list>)>)>", 
		      name, tool, ATgetName(sym), newargs);
      result = ATinsert(result, newtif);
    }

    tifs = ATgetNext(tifs);
  }
  return result;
}

/*}}}  */

/*{{{  static ATermList add_once(ATermList tifs, ATerm tif) */

static ATermList add_once(ATermList tifs, ATerm tif)
{
  if (ATindexOf(tifs, tif, 0) == -1) {
    tifs = ATinsert(tifs, tif);
  }

  return tifs;
}

/*}}}  */
/*{{{  static ATermList unify_arguments(ATermList args1, ATermList args2) */

static ATermList unify_arguments(ATermList args1, ATermList args2)
{
  int i = ATgetLength(args1);
  ATermList result = ATempty;


  if(ATgetLength(args2) != i)
    return NULL;

  for(--i; i>=0; i--) {
    ATerm arg1 = ATelementAt(args1, i);
    ATerm arg2 = ATelementAt(args2, i);

    /* When arg1 and arg2 are both <str> or <int>, leave them alone,
       otherwise use <term> */
    if((ATisEqual(arg1, ATparse("<str>")) || 
	ATisEqual(arg1, ATparse("<int>"))) && ATisEqual(arg1, arg2)) {
      result = ATinsert(result, arg1);
    } else {
      result = ATinsert(result, ATparse("<term>"));
    }
  }
  return result;
} 

/*}}}  */
/*{{{  ATermList unify_tifs(ATermList tifs) */

ATermList unify_tifs(ATermList tifs)
{
  char *primitive;
  ATermList result = ATempty;
  ATerm tool;

  while (!ATisEmpty(tifs)) {
    ATermList rest;
    char *mgu_name, *cur_name;
    ATermList mgu_args, cur_args;
    ATerm mgu, tif = ATgetFirst(tifs);

    if (ATmatch(tif, "rec-terminate(<term>,<term>)", NULL, NULL)
       || ATmatch(tif, "rec-ack-event(<term>,<term>)", NULL, NULL)) {
      result = add_once(result, tif);
      tifs = ATgetNext(tifs);
      continue;
    }

    /* No built-in primitive, must be primitive rec-do or rec-eval */
    if(!ATmatch(tif, "<appl(<term>,<appl(<list>)>)>",
		&primitive, &tool, &mgu_name, &mgu_args))
      ATerror("illegal tif: %t\n", tif);

    rest = ATgetNext(tifs);
    tifs = ATempty;
    for( ; !ATisEmpty(rest); rest=ATgetNext(rest)) {
      char *cur_prim;
      ATerm cur_tool, cur = ATgetFirst(rest);

      if(!ATmatch(cur, "<appl(<term>,<appl(<list>)>)>", 
		  &cur_prim, &cur_tool, &cur_name, &cur_args) ||
	 !streq(cur_name, mgu_name)) {
	tifs = ATinsert(tifs, cur);
	continue;
      }

      assert(ATisEqual(cur_tool, tool));
      if(!streq(cur_prim, primitive))
	ATerror("primitives collide: %t vs. %t\n", tif, cur);

      mgu_args = unify_arguments(mgu_args, cur_args);
      if(!mgu_args)
	ATerror("arity mismatch: %t vs. %t\n", tif, cur);
    }

    mgu = ATmake("<appl(<list>)>", mgu_name, mgu_args);
    result = ATinsert(result, ATmake("<appl(<term>,<term>)>", 
				     primitive, tool, mgu));
  }

  return result;
}

/*}}}  */
