#ifndef FOCUS_H
#define FOCUS_H

#include <MEPT.h>

#include "EditorData.h"

#define FOCUS_PARSED 0
#define FOCUS_UNPARSED 1
#define EDITOR_UNMODIFIED 0
#define EDITOR_MODIFIED 1

SE_Focus createFocus(PT_ParseTree parse_tree, SE_Path path, int focus_status);
SE_Focus createRootFocus(PT_ParseTree parse_tree, int focus_status);

SE_Focus expandFocusToStartSymbol(SE_Editor editor, SE_Focus focus);
SE_Focus updateFocus(SE_Focus focus, int location, int length);
SE_Focus adaptFocusLength(SE_Focus focus, int length);

SE_Editor joinFoci(SE_Editor editor);
SE_Editor joinUnparsedFoci(SE_Editor editor);

ATbool isFocusInUnparsedFoci(SE_Editor editor, SE_Focus focus);

SE_FocusList removeFocus(SE_FocusList foci, SE_Focus focus);

ATbool SE_isFocusRoot(SE_Focus focus);

#endif
