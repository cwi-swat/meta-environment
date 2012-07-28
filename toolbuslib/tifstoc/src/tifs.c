/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tifs.h"

/*}}}  */
/*{{{  defines */

#define strprefix(a, b) (!strncmp((a),(b),strlen(b)))

#define streq(a, b) (strlen(a) == strlen(b) && (strcmp(a, b) == 0))

/*}}}  */

/*{{{  ATermList read_tifs_from_named_file(const char *file, const char *tool) */

ATermList read_tifs_from_named_file(const char *file, const char *tool)
{
  int hasRecAckEvent = 0;
  
  ATermList allSignatures = (ATermList) ATreadFromNamedFile(file);
  while(allSignatures != ATempty){
    ATermAppl toolSignature = (ATermAppl) ATgetFirst(allSignatures);
    
    if(streq(ATgetName(ATgetAFun((ATermAppl) ATgetArgument(toolSignature, 0))), tool)){
      ATermList inputSignature = (ATermList) ATgetArgument(toolSignature, 1);
      ATermList outputSignature = (ATermList) ATgetArgument(toolSignature, 2);
      ATermList otherSignature = (ATermList) ATgetArgument(toolSignature, 3);
      
      ATermList tifs = ATempty;
      while(inputSignature != ATempty){
        tifs = ATinsert(tifs, ATgetFirst(inputSignature));
        inputSignature = ATgetNext(inputSignature);
      }
      
      while(outputSignature != ATempty){
        ATermAppl action = (ATermAppl) ATgetFirst(outputSignature);
        if(strcmp(ATgetName(ATgetAFun(action)), "rec-ack-event") == 0){
          hasRecAckEvent = 1;
        }
        outputSignature = ATgetNext(outputSignature);
      }
      
      if(hasRecAckEvent == 1){
        ATerm appl = (ATerm) ATmakePlaceholder((ATerm) ATmakeAppl(ATmakeAFun(tool, 0, ATfalse)));
        ATerm termPlaceholder = (ATerm) ATmakePlaceholder((ATerm) ATmakeAppl(ATmakeAFun("term", 0, ATfalse)));
        tifs = ATinsert(tifs, (ATerm) ATmakeAppl(ATmakeAFun("rec-ack-event", 2, ATfalse), appl, termPlaceholder));
      }
      
      while(otherSignature != ATempty){
        tifs = ATinsert(tifs, ATgetFirst(otherSignature));
        otherSignature = ATgetNext(otherSignature);
      }
      
      return tifs;
    }
     
    allSignatures = ATgetNext(allSignatures);
  }
  
  ATerror("No tifs found for tool %s.\n", tool);
  return NULL; // This never happens, but will make the compiler STFU.
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
  const char *name = NULL;

  while (!ATisEmpty(tifs)) {
    ATerm tif = ATgetFirst(tifs);
    ATermPlaceholder ph;
    char *primitive;
    if (ATmatch(tif, "<appl(<placeholder>,<list>)>", &primitive, &ph, NULL)) {
      if (ATmatch((ATerm)ph, "<appl>", &name) && ((tool == NULL) || streq(name, tool))) {
	result = ATinsert(result, tif);
      }
    }

    tifs = ATgetNext(tifs);
  }

  return result;
}

/*}}}  */
/*{{{  ATermList extract_tool_from_tifs(ATermList tifs, const char *tool) */

const char* extract_toolname(ATermList tifs)
{
  const char *name = NULL;

  while (!ATisEmpty(tifs)) {
    ATerm tif = ATgetFirst(tifs);
    ATermPlaceholder ph;
    char *primitive;
    if (ATmatch(tif, "<appl(<placeholder>,<list>)>", &primitive, &ph, NULL)) {
      if (ATmatch((ATerm)ph, "<appl>", &name)) {
	return name;
      }
    }

    tifs = ATgetNext(tifs);
  }

  return NULL;
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
    ATerm call;

    if (ATmatch(tif, "rec-terminate(<term>,<term>)", NULL, NULL)
	|| ATmatch(tif, "rec-ack-event(<term>,<term>)", NULL, NULL)) {
      result = ATinsert(result, tif);
    } else if(ATmatch(tif, "<appl(<term>,<term>)>", &name, &tool, &call)) {
      if (ATgetType(call) == AT_APPL) {
	Symbol sym = ATgetSymbol(call);
	for (i=ATgetArity(sym)-1; i>=0; --i) {
	  ATerm arg = ATgetArgument(call, i);
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
