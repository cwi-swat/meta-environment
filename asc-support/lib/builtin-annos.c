#include <PTMEPT-utils.h>
#include "builtin-common.h"
#include <assert.h>
#include <MEPT-utils.h>

/* note that by using AsFix trees as keys the storing and retrieval
 * of ATerm annotations depends on whitespace!
 */

/*{{{  static ATerm unquoteAppl(ATerm appl)  */

static ATerm unquoteAppl(ATerm appl) 
{
  AFun fun;
  int arity;
  char *name = NULL;
  ATermList args = NULL;

  assert(ATgetType(appl) == AT_APPL);

  fun = ATgetAFun((ATermAppl) appl);
  arity = ATgetArity(fun);
  name = ATgetName(fun);
  args = ATgetArguments((ATermAppl) appl);
  fun = ATmakeAFun(name, arity, ATfalse);

  return (ATerm) ATmakeApplList(fun, args);
}

/*}}}  */
/*{{{  static PTPT_ATerm noAnno() */

static PT_Tree noAnno()
{
  static PTPT_ATerm trm = NULL;

  if (trm == NULL) {
    trm = PTPT_liftATerm(ATparse("annotation-unavailable"));
    ATprotect((ATerm*) ((void*) &trm));
  }

  return (PT_Tree) trm;
}

/*}}}  */

/*{{{  static PT_Tree set_anno(PT_Tree term, PT_Tree key, PT_Tree value) */

static PT_Tree set_anno(PT_Tree term, PT_Tree key, PT_Tree value)
{
  return PT_setTreeAnnotation(term,
			      PT_TreeToTerm(key),
			      PT_TreeToTerm(value));
}

/*}}}  */
/*{{{  PT_Tree ASFE_set_anno(PT_Tree input) */

PT_Tree ASFE_set_anno(PT_Symbol type, PT_Tree term, PT_Tree key, PT_Tree value)
{
  return set_anno(term, key, value);
}

/*}}}  */
/*{{{  PT_Tree ASC_set_anno(ATerm aterm, ATerm akey, ATerm avalue) */

PT_Tree ASC_set_anno(ATerm type, ATerm aterm, ATerm akey, ATerm avalue)
{
  PT_Tree term = muASFToTree(aterm);
  PT_Tree key = muASFToTree(akey);
  PT_Tree value = muASFToTree(avalue);

  return set_anno(term, key, value);
}

/*}}}  */

/*{{{  static PT_Tree get_anno(PT_Tree term, PT_Tree value) */

static PT_Tree get_anno(PT_Tree term, PT_Tree key)
{
  PT_Tree anno = PT_TreeFromTerm(PT_getTreeAnnotation(term, (ATerm) key));

  if (anno == NULL) {
    /* TODO: fix this type incorrect solution! */
    return noAnno();
  }

  return anno;
}

/*}}}  */
/*{{{  PT_Tree ASFE_get_anno(PT_Tree input) */

PT_Tree ASFE_get_anno(PT_Symbol type, PT_Tree term, PT_Tree key)
{
  return get_anno(term, key);
}

/*}}}  */
/*{{{  PT_Tree ASC_get_anno(PT_Tree aterm, PT_Tree akey) */

PT_Tree ASC_get_anno(ATerm type, ATerm aterm, ATerm akey)
{
  PT_Tree term = muASFToTree(aterm);
  PT_Tree key = muASFToTree(akey);

  return get_anno(term, key);
}

/*}}}  */

/*{{{  static PT_Tree get_term_anno(PT_Tree term, PT_Tree key) */

static PT_Tree get_term_anno(PT_Tree term, PT_Tree key)
{
  ATerm label;
  ATerm anno;

  label = unquoteAppl(ATparse(PT_yieldTreeToString(key, ATfalse)));

  if (label == NULL) {
    return NULL;
  }

  anno = PT_getTreeAnnotation(term, label);

  if (anno != NULL) {
    return (PT_Tree) PTPT_liftATerm(anno);
  }

  return noAnno();
}

/*}}}  */
/*{{{  PT_Tree ASFE_get_term_anno(PT_Tree input)  */

PT_Tree ASFE_get_term_anno(PT_Symbol type, PT_Tree term, PT_Tree key)
{
  PT_Tree value = NULL;

  value = get_term_anno(term, key);

  if (value != NULL) {
    return value;
  }

  return NULL;
}

/*}}}  */
/*{{{  PT_Tree ASC_get_term_anno(ATerm type, ATerm aterm, ATerm akey) */

PT_Tree ASC_get_term_anno(ATerm type, ATerm aterm, ATerm akey)
{
  PT_Tree term = muASFToTree(aterm);
  PT_Tree key = muASFToTree(akey);
  PT_Tree value = NULL;
  
  value = get_term_anno(term, key);
  
  if (value != NULL) {
    return value;
  }

  return PT_makeTreeLit("TODO: return a proper normal form");
}

/*}}}  */

/*{{{  static PT_Tree set_term_anno(PT_Tree term, PT_Tree key, PT_Tree anno) */

static PT_Tree set_term_anno(PT_Tree term, PT_Tree key, PT_Tree anno)
{
  ATerm label;
  ATerm loweredAnno = NULL;

  label = unquoteAppl(ATparse(PT_yieldTreeToString(key, ATfalse)));

  if (label == NULL) {
    return NULL;
  }

  loweredAnno = PTPT_lowerATerm((PTPT_ATerm) anno);

  if (loweredAnno != NULL) {
    return PT_setTreeAnnotation(term, label, loweredAnno);
  }

  return NULL;
}

/*}}}  */
/*{{{  PT_Tree ASFE_get_term_anno(PT_Tree input)  */

PT_Tree ASFE_set_term_anno(PT_Symbol type, PT_Tree term, PT_Tree key, PT_Tree anno)
{
  PT_Tree value = NULL;

  value = set_term_anno(term, key, anno);

  if (value != NULL) {
    return value;
  }

  return NULL;
}

/*}}}  */
/*{{{  PT_Tree ASC_set_term_anno(ATerm type, ATerm aTerm, ATerm aKey, ATerm aAnno) */

PT_Tree ASC_set_term_anno(ATerm type, ATerm aTerm, ATerm aKey, ATerm aAnno)
{
  PT_Tree term = muASFToTree(aTerm);
  PT_Tree key = muASFToTree(aKey);
  PT_Tree anno = muASFToTree(aAnno);
  PT_Tree value = NULL;
  
  value = set_term_anno(term, key, anno);
  
  if (value != NULL) {
    return value;
  }

  return term;
}

/*}}}  */
