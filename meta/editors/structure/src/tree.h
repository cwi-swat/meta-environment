#ifndef TREE_H
#define TREE_H

#include "EditorData.h"

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
			     PT_Args left_layout, PT_Args right_layout);

PT_ParseTree flattenParseTreeTreeAt(PT_ParseTree parse_tree, SE_Path path);
PT_ParseTree setParseTreeTreeAt(PT_ParseTree parse_tree, PT_Tree tree, SE_Path path);

#endif /* TREE_H */
