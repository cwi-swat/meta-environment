/*{{{  includes */

#include <stdio.h>
#include <aterm2.h>
#include <ADT-utils.h>

/*}}}  */

/*{{{  variables */

static ATermTable substitutions = NULL;

/*}}}  */

/*{{{  addSubstitution(ATerm from, ATerm into) */

static void
addSubstitution(ATerm from, ATerm into)
{
  if (ATtableGet(substitutions, from) != NULL) {
    ATwarning("redefining substitution for %t\n", from);
  }

  ATtablePut(substitutions, from, into);
}

/*}}}  */

/*{{{  substituteAsfPatterns(ATerm pat) */

static ATerm
substituteAsfPatterns(ATerm pat)
{

  ATerm subst;
  
  subst = ATtableGet(substitutions, pat);
  if (subst != NULL) {
    ATwarning("%t\n====>\n%t\n\n", pat, subst);
    return subst;
  }

  /*ATwarning("s/%t/\n", pat);*/

  switch (ATgetType(pat)) {
    case AT_LIST:
      /*{{{  recursively handle list elements */

      {
	ATermList todo = (ATermList)pat;
	ATermList done = ATempty;
	while (!ATisEmpty(todo)) {
	  ATerm head = ATgetFirst(todo);
	  done = ATappend(done, substituteAsfPatterns(head));
	  todo = ATgetNext(todo);
	}

	return (ATerm)done;
      }

      /*}}}  */
      break;
    case AT_APPL:
      /*{{{  recursively handle arguments of function application */

      {
	ATermAppl appl = (ATermAppl)pat;
	int arity = ATgetArity(ATgetAFun(appl));
	int cur_arg_idx;
	for (cur_arg_idx=0; cur_arg_idx < arity; cur_arg_idx++) {
	  ATerm before = ATgetArgument(appl, cur_arg_idx);
	  ATerm after  = substituteAsfPatterns(before);
	  appl = ATsetArgument(appl, after, cur_arg_idx);
	}

	return (ATerm)appl;
      }

      /*}}}  */
      break;
    case AT_PLACEHOLDER:
      /*{{{  recursively handle the ``inside'' of a placeholder */

      {
	ATermPlaceholder ph = (ATermPlaceholder)pat;
	ATerm before = ATgetPlaceholder(ph);
	ATerm after  = substituteAsfPatterns(before);

	return (ATerm)ATmakePlaceholder(after);
      }

      /*}}}  */
      break;
    default:
      return pat;
      break;
  }
}

/*}}}  */

/*{{{  substituteEntry(ADTEntry entry, void *user_data) */

static ADTEntry
substituteEntry(ADTEntry entry, void *user_data)
{
  ADTPattern before;
  ADTPattern after;

  before = ADTgetEntryPat(entry);
  after  = substituteAsfPatterns(before);

  return ADTsetEntryPat(entry, after);
}

/*}}}  */

/*{{{  main(int argc, char *argv[]) */

int
main(int argc, char *argv[])
{
  ATerm      bottomOfStack;
  ATerm      contents;
  ADTEntry   lexicalConsEntry;
  ADTEntries beforeSubst;
  ADTEntries afterSubst;

  ATinit(argc, argv, &bottomOfStack);
  ADTinitADTApi();

  substitutions = ATtableCreate(100, 75);

  contents = ATreadFromNamedFile(argv[1]);
  if (contents == NULL) {
    perror(argv[1]);
    return 1;
  }

   addSubstitution(
    ATparse("prod(id(\"GEN-Equations\"),w(\"\"),[sort(\"Tree\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Tree\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Equation\"),w(\"\"),no-attrs)"),
    ATparse("prod(id(\"GEN-Equations\"),w(\"\"),[<lhs-symbol(Symbol)>,w(\"\"),ql(\"=\"),w(\"\"),<rhs-symbol(Symbol)>],w(\"\"),l(\"->\"),w(\"\"),sort(\"Equation\"),w(\"\"),no-attrs)"));

 addSubstitution(
    ATparse("prod(id(\"GEN-Equations\"),w(\"\"),[sort(\"Tree\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Tree\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Condition\"),w(\"\"),no-attrs)"),
    ATparse("prod(id(\"GEN-Equations\"),w(\"\"),[<lhs-symbol(Symbol)>,w(\"\"),ql(\"=\"),w(\"\"),<rhs-symbol(Symbol)>],w(\"\"),l(\"->\"),w(\"\"),sort(\"Condition\"),w(\"\"),no-attrs)"));

  addSubstitution(
    ATparse("prod(id(\"GEN-Equations\"),w(\"\"),[sort(\"Tree\"),w(\"\"),ql(\"!=\"),w(\"\"),sort(\"Tree\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Condition\"),w(\"\"),no-attrs)"),
    ATparse("prod(id(\"GEN-Equations\"),w(\"\"),[<lhs-symbol(Symbol)>,w(\"\"),ql(\"!=\"),w(\"\"),<rhs-symbol(Symbol)>],w(\"\"),l(\"->\"),w(\"\"),sort(\"Condition\"),w(\"\"),no-attrs)"));

  addSubstitution(
    ATparse("prod(id(\"GEN-LexConsFuncs\"),w(\"\"),[sort(\"Tree\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Tree\"),w(\"\"),no-attrs)"),
    ATparse("prod(id(\"GEN-LexConsFuncs\"),w(\"\"),[ql(<formal-name(str)>),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),<symbol(Symbol)>,w(\"\"),no-attrs)"));

  beforeSubst = ADTmakeEntriesFromTerm(contents);
  afterSubst  = ADTsubstitute(beforeSubst, substituteEntry, NULL);

  lexicalConsEntry = ADTmakeEntryDefault(
                       (ADTSort)ATparse("Production"),
                       (ADTAlternative)ATparse("lexical-constructor"),
                       (ADTPattern)ATparse("prod(id(\"GEN-LexConsFuncs\"),w(\"\"),[ql(<formal-name(str)>),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),<symbol(Symbol)>,w(\"\"),no-attrs)"));

  afterSubst = ADTmakeEntriesList(lexicalConsEntry, afterSubst);

  ATprintf("%t\n", ADTmakeTermFromEntries(afterSubst));

  return 0;
}

/*}}}  */
