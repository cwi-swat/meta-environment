
#ifndef TREE_H
#define TREE_H

#include "Editor.h"

PT_Symbol getParseTreeSort(PT_ParseTree tree);
PT_Tree getParseTreeTreeAt(PT_ParseTree parse_tree, SE_Path path);

PT_Symbol getTreeSort(PT_Tree tree);
PT_Tree getTreeAt(PT_Tree tree, SE_Steps steps);
PT_Tree setTreeAt(PT_Tree tree, PT_Tree sub_tree, SE_Steps steps);
int calcParseTreeStart(PT_ParseTree parse_tree, SE_Path path);
int calcTreeStart(PT_Tree tree, SE_Steps steps);

ATbool isBasicLeafNode(PT_Tree tree);
PT_Tree updateTreeTerm(PT_Tree tree, SE_Steps steps, PT_Tree sub_tree);
PT_ParseTree updateParseTree(PT_ParseTree tree, SE_Path path, PT_Tree sub_tree,
			     char *left_layout, char *right_layout);

#endif /* TREE_H */
