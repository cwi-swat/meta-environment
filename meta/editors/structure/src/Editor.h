#ifndef _EDITOR_H
#define _EDITOR_H

/*{{{  includes */

#include <aterm1.h>
#include "Editor_dict.h"

/*}}}  */

/*{{{  prologue */


#include <MEPT.h>

typedef PT_ParseTree SE_ParseTree;


/*}}}  */
/*{{{  typedefs */

typedef struct _SE_Editor *SE_Editor;
typedef struct _SE_Focus *SE_Focus;
typedef struct _SE_Area *SE_Area;
typedef struct _SE_FocusList *SE_FocusList;
typedef struct _SE_SymbolList *SE_SymbolList;
typedef struct _SE_Path *SE_Path;
typedef struct _SE_Steps *SE_Steps;
typedef struct _SE_Move *SE_Move;

/*}}}  */

void SE_initEditorApi(void);

/*{{{  term conversion functions */

SE_Editor SE_makeEditorFromTerm(ATerm t);
ATerm SE_makeTermFromEditor(SE_Editor arg);
SE_Focus SE_makeFocusFromTerm(ATerm t);
ATerm SE_makeTermFromFocus(SE_Focus arg);
SE_Area SE_makeAreaFromTerm(ATerm t);
ATerm SE_makeTermFromArea(SE_Area arg);
SE_FocusList SE_makeFocusListFromTerm(ATerm t);
ATerm SE_makeTermFromFocusList(SE_FocusList arg);
SE_SymbolList SE_makeSymbolListFromTerm(ATerm t);
ATerm SE_makeTermFromSymbolList(SE_SymbolList arg);
SE_Path SE_makePathFromTerm(ATerm t);
ATerm SE_makeTermFromPath(SE_Path arg);
SE_Steps SE_makeStepsFromTerm(ATerm t);
ATerm SE_makeTermFromSteps(SE_Steps arg);
SE_Move SE_makeMoveFromTerm(ATerm t);
ATerm SE_makeTermFromMove(SE_Move arg);

/*}}}  */
/*{{{  constructors */

SE_Editor SE_makeEditorDefault(SE_ParseTree parseTree, SE_Focus focus, SE_FocusList unparsedFoci, int modified, SE_SymbolList startSymbols);
SE_Focus SE_makeFocusEmpty();
SE_Focus SE_makeFocusNotEmpty(SE_Path path, char * sort, SE_Area area, int unparsed);
SE_Area SE_makeAreaDefault(int start, int length);
SE_FocusList SE_makeFocusListEmpty();
SE_FocusList SE_makeFocusListMulti(SE_Focus head, SE_FocusList tail);
SE_SymbolList SE_makeSymbolListEmpty();
SE_SymbolList SE_makeSymbolListMulti(char * head, SE_SymbolList tail);
SE_Path SE_makePathRoot();
SE_Path SE_makePathLeftLayout();
SE_Path SE_makePathTerm(SE_Steps steps);
SE_Path SE_makePathRightLayout();
SE_Steps SE_makeStepsEmpty();
SE_Steps SE_makeStepsMulti(int head, SE_Steps tail);
SE_Move SE_makeMoveLeft();
SE_Move SE_makeMoveRight();
SE_Move SE_makeMoveUp();
SE_Move SE_makeMoveDown();

/*}}}  */
/*{{{  equality functions */

ATbool SE_isEqualEditor(SE_Editor arg0, SE_Editor arg1);
ATbool SE_isEqualFocus(SE_Focus arg0, SE_Focus arg1);
ATbool SE_isEqualArea(SE_Area arg0, SE_Area arg1);
ATbool SE_isEqualFocusList(SE_FocusList arg0, SE_FocusList arg1);
ATbool SE_isEqualSymbolList(SE_SymbolList arg0, SE_SymbolList arg1);
ATbool SE_isEqualPath(SE_Path arg0, SE_Path arg1);
ATbool SE_isEqualSteps(SE_Steps arg0, SE_Steps arg1);
ATbool SE_isEqualMove(SE_Move arg0, SE_Move arg1);

/*}}}  */
/*{{{  SE_Editor accessors */

ATbool SE_isValidEditor(SE_Editor arg);
ATbool SE_isEditorDefault(SE_Editor arg);
ATbool SE_hasEditorParseTree(SE_Editor arg);
SE_ParseTree SE_getEditorParseTree(SE_Editor arg);
SE_Editor SE_setEditorParseTree(SE_Editor arg, SE_ParseTree parseTree);
ATbool SE_hasEditorFocus(SE_Editor arg);
SE_Focus SE_getEditorFocus(SE_Editor arg);
SE_Editor SE_setEditorFocus(SE_Editor arg, SE_Focus focus);
ATbool SE_hasEditorUnparsedFoci(SE_Editor arg);
SE_FocusList SE_getEditorUnparsedFoci(SE_Editor arg);
SE_Editor SE_setEditorUnparsedFoci(SE_Editor arg, SE_FocusList unparsedFoci);
ATbool SE_hasEditorModified(SE_Editor arg);
int SE_getEditorModified(SE_Editor arg);
SE_Editor SE_setEditorModified(SE_Editor arg, int modified);
ATbool SE_hasEditorStartSymbols(SE_Editor arg);
SE_SymbolList SE_getEditorStartSymbols(SE_Editor arg);
SE_Editor SE_setEditorStartSymbols(SE_Editor arg, SE_SymbolList startSymbols);

/*}}}  */
/*{{{  SE_Focus accessors */

ATbool SE_isValidFocus(SE_Focus arg);
ATbool SE_isFocusEmpty(SE_Focus arg);
ATbool SE_isFocusNotEmpty(SE_Focus arg);
ATbool SE_hasFocusPath(SE_Focus arg);
SE_Path SE_getFocusPath(SE_Focus arg);
SE_Focus SE_setFocusPath(SE_Focus arg, SE_Path path);
ATbool SE_hasFocusSort(SE_Focus arg);
char * SE_getFocusSort(SE_Focus arg);
SE_Focus SE_setFocusSort(SE_Focus arg, char * sort);
ATbool SE_hasFocusArea(SE_Focus arg);
SE_Area SE_getFocusArea(SE_Focus arg);
SE_Focus SE_setFocusArea(SE_Focus arg, SE_Area area);
ATbool SE_hasFocusUnparsed(SE_Focus arg);
int SE_getFocusUnparsed(SE_Focus arg);
SE_Focus SE_setFocusUnparsed(SE_Focus arg, int unparsed);

/*}}}  */
/*{{{  SE_Area accessors */

ATbool SE_isValidArea(SE_Area arg);
ATbool SE_isAreaDefault(SE_Area arg);
ATbool SE_hasAreaStart(SE_Area arg);
int SE_getAreaStart(SE_Area arg);
SE_Area SE_setAreaStart(SE_Area arg, int start);
ATbool SE_hasAreaLength(SE_Area arg);
int SE_getAreaLength(SE_Area arg);
SE_Area SE_setAreaLength(SE_Area arg, int length);

/*}}}  */
/*{{{  SE_FocusList accessors */

ATbool SE_isValidFocusList(SE_FocusList arg);
ATbool SE_isFocusListEmpty(SE_FocusList arg);
ATbool SE_isFocusListMulti(SE_FocusList arg);
ATbool SE_hasFocusListHead(SE_FocusList arg);
SE_Focus SE_getFocusListHead(SE_FocusList arg);
SE_FocusList SE_setFocusListHead(SE_FocusList arg, SE_Focus head);
ATbool SE_hasFocusListTail(SE_FocusList arg);
SE_FocusList SE_getFocusListTail(SE_FocusList arg);
SE_FocusList SE_setFocusListTail(SE_FocusList arg, SE_FocusList tail);

/*}}}  */
/*{{{  SE_SymbolList accessors */

ATbool SE_isValidSymbolList(SE_SymbolList arg);
ATbool SE_isSymbolListEmpty(SE_SymbolList arg);
ATbool SE_isSymbolListMulti(SE_SymbolList arg);
ATbool SE_hasSymbolListHead(SE_SymbolList arg);
char * SE_getSymbolListHead(SE_SymbolList arg);
SE_SymbolList SE_setSymbolListHead(SE_SymbolList arg, char * head);
ATbool SE_hasSymbolListTail(SE_SymbolList arg);
SE_SymbolList SE_getSymbolListTail(SE_SymbolList arg);
SE_SymbolList SE_setSymbolListTail(SE_SymbolList arg, SE_SymbolList tail);

/*}}}  */
/*{{{  SE_Path accessors */

ATbool SE_isValidPath(SE_Path arg);
ATbool SE_isPathRoot(SE_Path arg);
ATbool SE_isPathLeftLayout(SE_Path arg);
ATbool SE_isPathTerm(SE_Path arg);
ATbool SE_isPathRightLayout(SE_Path arg);
ATbool SE_hasPathSteps(SE_Path arg);
SE_Steps SE_getPathSteps(SE_Path arg);
SE_Path SE_setPathSteps(SE_Path arg, SE_Steps steps);

/*}}}  */
/*{{{  SE_Steps accessors */

ATbool SE_isValidSteps(SE_Steps arg);
ATbool SE_isStepsEmpty(SE_Steps arg);
ATbool SE_isStepsMulti(SE_Steps arg);
ATbool SE_hasStepsHead(SE_Steps arg);
int SE_getStepsHead(SE_Steps arg);
SE_Steps SE_setStepsHead(SE_Steps arg, int head);
ATbool SE_hasStepsTail(SE_Steps arg);
SE_Steps SE_getStepsTail(SE_Steps arg);
SE_Steps SE_setStepsTail(SE_Steps arg, SE_Steps tail);

/*}}}  */
/*{{{  SE_Move accessors */

ATbool SE_isValidMove(SE_Move arg);
ATbool SE_isMoveLeft(SE_Move arg);
ATbool SE_isMoveRight(SE_Move arg);
ATbool SE_isMoveUp(SE_Move arg);
ATbool SE_isMoveDown(SE_Move arg);

/*}}}  */
/*{{{  sort visitors */

SE_Editor SE_visitEditor(SE_Editor arg, SE_ParseTree (*acceptParseTree)(SE_ParseTree), SE_Focus (*acceptFocus)(SE_Focus), SE_FocusList (*acceptUnparsedFoci)(SE_FocusList), int (*acceptModified)(int), SE_SymbolList (*acceptStartSymbols)(SE_SymbolList));
SE_Focus SE_visitFocus(SE_Focus arg, SE_Path (*acceptPath)(SE_Path), char * (*acceptSort)(char *), SE_Area (*acceptArea)(SE_Area), int (*acceptUnparsed)(int));
SE_Area SE_visitArea(SE_Area arg, int (*acceptStart)(int), int (*acceptLength)(int));
SE_FocusList SE_visitFocusList(SE_FocusList arg, SE_Focus (*acceptHead)(SE_Focus));
SE_SymbolList SE_visitSymbolList(SE_SymbolList arg, char * (*acceptHead)(char *));
SE_Path SE_visitPath(SE_Path arg, SE_Steps (*acceptSteps)(SE_Steps));
SE_Steps SE_visitSteps(SE_Steps arg, int (*acceptHead)(int));
SE_Move SE_visitMove(SE_Move arg);

/*}}}  */

#endif /* _EDITOR_H */
