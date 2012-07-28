/** 
 * \file
 * Deals with the length annotation, a length annotation for a tree
 * contains the exact number of characters that a node would yield.
 */
#include <MEPT-length.h>
#include <MEPT-annotations.h>
#include <assert.h>
#define ANNO_LENGTH "length"  

 
static PT_Tree annotateTreeWithLength(PT_Tree tree, int *length);

static PT_Args annotateAmbArgsWithLength(PT_Args args, int *length)
{
  PT_Tree head;
  PT_Args tail;
  int head_length, tail_length;
 
  if (PT_isArgsEmpty(args)) {
    *length = 0;
    return args;
  }
 
  head = PT_getArgsHead(args);
  tail = PT_getArgsTail(args);
 
  head = annotateTreeWithLength(head, &head_length);
  tail = annotateAmbArgsWithLength(tail, &tail_length);

  *length = head_length;

  return PT_makeArgsMany(head, tail);
}


static PT_Args annotateArgsWithLength(PT_Args args, int *length)
{
  PT_Tree head;
  PT_Args tail;
  int head_length, tail_length;

  if (PT_isArgsEmpty(args)) {
    *length = 0;
    return args;
  }

  head = PT_getArgsHead(args);
  tail = PT_getArgsTail(args);

  head = annotateTreeWithLength(head, &head_length);
  tail = annotateArgsWithLength(tail, &tail_length);

  *length = head_length + tail_length;

  return PT_makeArgsMany(head, tail);
}


static PT_Tree annotateTreeWithLength(PT_Tree tree, int *length)
{
  if (PT_isTreeChar(tree)) {
    *length = 1;
  }
  else if (PT_isTreeAmb(tree)) {
    PT_Args args = PT_getTreeArgs(tree);
    args = annotateAmbArgsWithLength(args, length);
    tree = PT_setTreeArgs(tree, args);
    tree = PT_setTreeAnnotation(tree, ATparse(ANNO_LENGTH),
                                ATmake("<int>", *length));
  }
  else if (PT_hasTreeArgs(tree)) {
    PT_Args args = PT_getTreeArgs(tree);
    args = annotateArgsWithLength(args, length);
    tree = PT_setTreeArgs(tree, args);
    tree = PT_setTreeAnnotation(tree, ATparse(ANNO_LENGTH),
                                ATmake("<int>", *length));
  }
  else {
    ATabort("annotateTreeWithLength: unknown tree type: %t\n", 
            PT_TreeToTerm(tree));
  }
  return tree;
}


PT_Tree PT_annotateTreeWithLength(PT_Tree tree)
{
  int length;

  return annotateTreeWithLength(tree, &length);
}

/**
 * Adds an annotation to each sub-tree of a derivation, indicating
 * the total amount of characters that each tree would yield. This
 * functionality is nice in structure editors.
 */
PT_ParseTree PT_annotateParseTreeWithLength(PT_ParseTree parse_tree)
{
  int length;

  PT_Tree tree = PT_getParseTreeTop(parse_tree);
  tree = PT_annotateTreeWithLength(tree);
  parse_tree = PT_setParseTreeTop(parse_tree, tree);

  length = PT_getTreeLengthAnno(tree);

  parse_tree = PT_setParseTreeLengthAnno(parse_tree, length);

  return parse_tree;
}


int PT_getParseTreeLengthAnno(PT_ParseTree parse_tree)
{
  ATerm anno = PT_getParseTreeAnnotation(parse_tree, ATparse(ANNO_LENGTH));

  assert(anno && ATgetType(anno) == AT_INT);

  return ATgetInt((ATermInt)anno);
}


PT_ParseTree PT_setParseTreeLengthAnno(PT_ParseTree parse_tree, int length)
{
  return PT_setParseTreeAnnotation(parse_tree, ATparse(ANNO_LENGTH),
                                   (ATerm)ATmakeInt(length));
}


int PT_getTreeLengthAnno(PT_Tree tree)
{
  if (PT_isTreeChar(tree)) {
    return 1;
  } 
  else {
    ATerm anno = PT_getTreeAnnotation(tree, ATparse(ANNO_LENGTH));
    assert(anno);
    return ATgetInt((ATermInt)anno);
  }
}


PT_Tree PT_setTreeLengthAnno(PT_Tree tree, int length)
{
  return PT_setTreeAnnotation(tree, ATparse(ANNO_LENGTH),
                             (ATerm)ATmakeInt(length));
}

