#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "StructureEditor.h"

/**
 * Converts a string to an ATermList of integers (ASCII values). 
 * \param[in] str An ASCII string
 * \return An ATermList containing the ASCII values of #arg as ATermInts
 */
ATerm SE_stringToChars(const char *str) {
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

/**
 * Converts an ASCII char to an ATermInt. 
 * \param[in] ch an ASCII character
 * \return An ATerm representing the ASCII value of #arg
 */
ATerm SE_byteToChar(char ch) {
    return (ATerm) ATmakeInt(ch);
}

/**
 * Converts a list of integers (ASCII values) to a C string. 
 * \param[in] arg An ATermList with ATermInts, such as [32,32,10]
 * \return String containing the characters from #arg as characters
 */
char *SE_charsToString(ATerm arg) {
  ATermList list = (ATermList) arg;
  int len = ATgetLength(list);
  int i;
  char *str;

  str = (char *) malloc(len+1);
  if (str == NULL) {
      return NULL;
  }

  for (i = 0; !ATisEmpty(list); list = ATgetNext(list), i++) {
    str[i] = (char) ATgetInt((ATermInt) ATgetFirst(list));
  }
  str[i] = '\0';

  return str;
}

char SE_charToByte(ATerm arg) {
    return (char) ATgetInt((ATermInt) arg);
}


typedef struct ATerm _SE_Direction;
typedef struct ATerm _SE_StructureEditor;


/**
 * Initializes the full API. Forgetting to call this function before using the API will lead to strange behaviour. ATinit() needs to be called before this function.
 */
void _SE_initStructureEditorApi(void) {
  init_StructureEditor_dict();

}

/**
 * Protect a SE_Direction from the ATerm garbage collector. Every SE_Direction that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a SE_Direction
 */
void _SE_protectDirection(SE_Direction *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a SE_Direction from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a SE_Direction
 */
void _SE_unprotectDirection(SE_Direction *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a SE_StructureEditor from the ATerm garbage collector. Every SE_StructureEditor that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a SE_StructureEditor
 */
void _SE_protectStructureEditor(SE_StructureEditor *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a SE_StructureEditor from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a SE_StructureEditor
 */
void _SE_unprotectStructureEditor(SE_StructureEditor *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Transforms an ATerm to a SE_Direction. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return SE_Direction that was encoded by \arg
 */
SE_Direction _SE_DirectionFromTerm(ATerm t) {
  return (SE_Direction)t;
}

/**
 * Transforms a SE_Directionto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg SE_Direction to be converted
 * \return ATerm that represents the SE_Direction
 */
ATerm _SE_DirectionToTerm(SE_Direction arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a SE_StructureEditor. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return SE_StructureEditor that was encoded by \arg
 */
SE_StructureEditor _SE_StructureEditorFromTerm(ATerm t) {
  return (SE_StructureEditor)t;
}

/**
 * Transforms a SE_StructureEditorto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg SE_StructureEditor to be converted
 * \return ATerm that represents the SE_StructureEditor
 */
ATerm _SE_StructureEditorToTerm(SE_StructureEditor arg) {
  return (ATerm)arg;
}

/**
 * Constructs a up of type SE_Direction. Like all ATerm types, SE_Directions are maximally shared.
 * \return A pointer to a up, either newly constructed or shared
 */
SE_Direction SE_makeDirectionUp(void) {
  return (SE_Direction)(ATerm)ATmakeAppl0(SE_afun0);
}
/**
 * Constructs a left of type SE_Direction. Like all ATerm types, SE_Directions are maximally shared.
 * \return A pointer to a left, either newly constructed or shared
 */
SE_Direction SE_makeDirectionLeft(void) {
  return (SE_Direction)(ATerm)ATmakeAppl0(SE_afun1);
}
/**
 * Constructs a down of type SE_Direction. Like all ATerm types, SE_Directions are maximally shared.
 * \return A pointer to a down, either newly constructed or shared
 */
SE_Direction SE_makeDirectionDown(void) {
  return (SE_Direction)(ATerm)ATmakeAppl0(SE_afun2);
}
/**
 * Constructs a right of type SE_Direction. Like all ATerm types, SE_Directions are maximally shared.
 * \return A pointer to a right, either newly constructed or shared
 */
SE_Direction SE_makeDirectionRight(void) {
  return (SE_Direction)(ATerm)ATmakeAppl0(SE_afun3);
}
/**
 * Constructs a Default of type SE_StructureEditor. Like all ATerm types, SE_StructureEditors are maximally shared.
 * \param[in] parseTree a child of the new Default
 * \param[in] cursor a child of the new Default
 * \return A pointer to a Default, either newly constructed or shared
 */
SE_StructureEditor SE_makeStructureEditorDefault(SE_ParseTree parseTree, SE_Tree cursor) {
  return (SE_StructureEditor)(ATerm)ATmakeAppl2(SE_afun4, (ATerm) parseTree, (ATerm) cursor);
}
/**
 * Constructs a unedited of type SE_StructureEditor. Like all ATerm types, SE_StructureEditors are maximally shared.
 * \param[in] parseTree a child of the new unedited
 * \return A pointer to a unedited, either newly constructed or shared
 */
SE_StructureEditor SE_makeStructureEditorUnedited(SE_ParseTree parseTree) {
  return (SE_StructureEditor)(ATerm)ATmakeAppl1(SE_afun5, (ATerm) parseTree);
}

/**
 * Tests equality of two SE_Directions. A constant time operation.
 * \param[in] arg0 first SE_Direction to be compared
 * \param[in] arg1 second SE_Direction to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _SE_isEqualDirection(SE_Direction arg0, SE_Direction arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two SE_StructureEditors. A constant time operation.
 * \param[in] arg0 first SE_StructureEditor to be compared
 * \param[in] arg1 second SE_StructureEditor to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _SE_isEqualStructureEditor(SE_StructureEditor arg0, SE_StructureEditor arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Assert whether a SE_Direction is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input SE_Direction
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool SE_isValidDirection(SE_Direction arg) {
  if (SE_isDirectionUp(arg)) {
    return ATtrue;
  }
  else if (SE_isDirectionLeft(arg)) {
    return ATtrue;
  }
  else if (SE_isDirectionDown(arg)) {
    return ATtrue;
  }
  else if (SE_isDirectionRight(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a SE_Direction is a up by checking against the following ATerm pattern: up. May not be used to assert correctness of the SE_Direction
 * \param[in] arg input SE_Direction
 * \return ATtrue if #arg corresponds to the signature of a up, or ATfalse otherwise
 */
inline ATbool SE_isDirectionUp(SE_Direction arg){
  /* checking for: up */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == SE_afun0) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a SE_Direction is a left by checking against the following ATerm pattern: left. May not be used to assert correctness of the SE_Direction
 * \param[in] arg input SE_Direction
 * \return ATtrue if #arg corresponds to the signature of a left, or ATfalse otherwise
 */
inline ATbool SE_isDirectionLeft(SE_Direction arg){
  /* checking for: left */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == SE_afun1) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a SE_Direction is a down by checking against the following ATerm pattern: down. May not be used to assert correctness of the SE_Direction
 * \param[in] arg input SE_Direction
 * \return ATtrue if #arg corresponds to the signature of a down, or ATfalse otherwise
 */
inline ATbool SE_isDirectionDown(SE_Direction arg){
  /* checking for: down */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == SE_afun2) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a SE_Direction is a right by checking against the following ATerm pattern: right. May not be used to assert correctness of the SE_Direction
 * \param[in] arg input SE_Direction
 * \return ATtrue if #arg corresponds to the signature of a right, or ATfalse otherwise
 */
inline ATbool SE_isDirectionRight(SE_Direction arg){
  /* checking for: right */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == SE_afun3) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a SE_StructureEditor is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input SE_StructureEditor
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool SE_isValidStructureEditor(SE_StructureEditor arg) {
  if (SE_isStructureEditorDefault(arg)) {
    return ATtrue;
  }
  else if (SE_isStructureEditorUnedited(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a SE_StructureEditor is a Default by checking against the following ATerm pattern: Default(<"parse-tree"("ParseTree")>,<"cursor"("Tree")>). May not be used to assert correctness of the SE_StructureEditor
 * \param[in] arg input SE_StructureEditor
 * \return ATtrue if #arg corresponds to the signature of a Default, or ATfalse otherwise
 */
inline ATbool SE_isStructureEditorDefault(SE_StructureEditor arg){
  /* checking for: Default */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == SE_afun4) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a SE_StructureEditor is a unedited by checking against the following ATerm pattern: unedited(<"parse-tree"("ParseTree")>). May not be used to assert correctness of the SE_StructureEditor
 * \param[in] arg input SE_StructureEditor
 * \return ATtrue if #arg corresponds to the signature of a unedited, or ATfalse otherwise
 */
inline ATbool SE_isStructureEditorUnedited(SE_StructureEditor arg){
  /* checking for: unedited */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == SE_afun5) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a SE_StructureEditor has a parse-tree. 
 * \param[in] arg input SE_StructureEditor
 * \return ATtrue if the SE_StructureEditor had a parse-tree, or ATfalse otherwise
 */
ATbool SE_hasStructureEditorParseTree(SE_StructureEditor arg) {
  if (SE_isStructureEditorDefault(arg)) {
    return ATtrue;
  }
  else if (SE_isStructureEditorUnedited(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a SE_StructureEditor has a cursor. 
 * \param[in] arg input SE_StructureEditor
 * \return ATtrue if the SE_StructureEditor had a cursor, or ATfalse otherwise
 */
ATbool SE_hasStructureEditorCursor(SE_StructureEditor arg) {
  if (SE_isStructureEditorDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the parse-tree SE_ParseTree of a SE_StructureEditor. Note that the precondition is that this SE_StructureEditor actually has a parse-tree
 * \param[in] arg input SE_StructureEditor
 * \return the parse-tree of #arg, if it exist or an undefined value if it does not
 */
SE_ParseTree SE_getStructureEditorParseTree(SE_StructureEditor arg) {
  if (SE_isStructureEditorDefault(arg)) {
    return (SE_ParseTree)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (SE_ParseTree)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the cursor SE_Tree of a SE_StructureEditor. Note that the precondition is that this SE_StructureEditor actually has a cursor
 * \param[in] arg input SE_StructureEditor
 * \return the cursor of #arg, if it exist or an undefined value if it does not
 */
SE_Tree SE_getStructureEditorCursor(SE_StructureEditor arg) {
  
    return (SE_Tree)ATgetArgument((ATermAppl)arg, 1);
}

/**
 * Set the parse-tree of a SE_StructureEditor. The precondition being that this SE_StructureEditor actually has a parse-tree
 * \param[in] arg input SE_StructureEditor
 * \param[in] parseTree new SE_ParseTree to set in #arg
 * \return A new SE_StructureEditor with parseTree at the right place, or a core dump if #arg did not have a parseTree
 */
SE_StructureEditor SE_setStructureEditorParseTree(SE_StructureEditor arg, SE_ParseTree parseTree) {
  if (SE_isStructureEditorDefault(arg)) {
    return (SE_StructureEditor)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) parseTree), 0);
  }
  else if (SE_isStructureEditorUnedited(arg)) {
    return (SE_StructureEditor)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) parseTree), 0);
  }

  ATabort("StructureEditor has no ParseTree: %t\n", arg);
  return (SE_StructureEditor)NULL;
}

/**
 * Set the cursor of a SE_StructureEditor. The precondition being that this SE_StructureEditor actually has a cursor
 * \param[in] arg input SE_StructureEditor
 * \param[in] cursor new SE_Tree to set in #arg
 * \return A new SE_StructureEditor with cursor at the right place, or a core dump if #arg did not have a cursor
 */
SE_StructureEditor SE_setStructureEditorCursor(SE_StructureEditor arg, SE_Tree cursor) {
  if (SE_isStructureEditorDefault(arg)) {
    return (SE_StructureEditor)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) cursor), 1);
  }

  ATabort("StructureEditor has no Cursor: %t\n", arg);
  return (SE_StructureEditor)NULL;
}

/**
 * Apply functions to the children of a SE_Direction. 
 * \return A new SE_Direction with new children where the argument functions might have applied
 */
SE_Direction SE_visitDirection(SE_Direction arg) {
  if (SE_isDirectionUp(arg)) {
    return SE_makeDirectionUp();
  }
  if (SE_isDirectionLeft(arg)) {
    return SE_makeDirectionLeft();
  }
  if (SE_isDirectionDown(arg)) {
    return SE_makeDirectionDown();
  }
  if (SE_isDirectionRight(arg)) {
    return SE_makeDirectionRight();
  }
  ATabort("not a Direction: %t\n", arg);
  return (SE_Direction)NULL;
}
/**
 * Apply functions to the children of a SE_StructureEditor. 
 * \return A new SE_StructureEditor with new children where the argument functions might have applied
 */
SE_StructureEditor SE_visitStructureEditor(SE_StructureEditor arg, SE_ParseTree (*acceptParseTree)(SE_ParseTree), SE_Tree (*acceptCursor)(SE_Tree)) {
  if (SE_isStructureEditorDefault(arg)) {
    return SE_makeStructureEditorDefault(
        acceptParseTree ? acceptParseTree(SE_getStructureEditorParseTree(arg)) : SE_getStructureEditorParseTree(arg),
        acceptCursor ? acceptCursor(SE_getStructureEditorCursor(arg)) : SE_getStructureEditorCursor(arg));
  }
  if (SE_isStructureEditorUnedited(arg)) {
    return SE_makeStructureEditorUnedited(
        acceptParseTree ? acceptParseTree(SE_getStructureEditorParseTree(arg)) : SE_getStructureEditorParseTree(arg));
  }
  ATabort("not a StructureEditor: %t\n", arg);
  return (SE_StructureEditor)NULL;
}

