#ifndef EDITOR_H
#define EDITOR_H

#include <MEPT.h>

#include "EditorData.h"

#define SORT_UNKNOWN  "<unknown>"
#define SORT_UNPARSED "<unparsed>"
#define SORT_TERM     "term"

SE_Editor insertChars(SE_Editor editor, int location, int nr_chars);
SE_Editor deleteChars(SE_Editor editor, int location, int nr_chars);

SE_Editor replaceEditorTreeAtFocus(SE_Editor editor, SE_Focus focus, 
                                   PT_Tree tree,
				   PT_Args left_layout, PT_Args right_layout);
SE_Editor moveFocus(SE_Editor editor, SE_Move move);
SE_Editor moveFocusToTop(SE_Editor editor);
SE_Focus getFocusAt(SE_Editor editor, PT_ParseTree parse_tree, int location);

SE_Editor newEditorGivenTree(PT_ParseTree parse_tree, char *sort, ATbool dirty);
SE_Editor newEditorGivenText(char *text);
SE_Editor newEditorGivenLength(int length);

PT_Tree getFocussedTree(SE_Editor editor, SE_Focus focus);

#endif /* EDITOR_H */
