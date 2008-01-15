/*$Id$*/

/** \file
 * Implementation of the input string.
 */ 

#include "inputString-data.h"
#include "inputString-api.h"
#include <assert.h>
#include <MEPT.h>
#include <MEPT-utils.h>

/** 
 * This is the input string's struct.
 */
struct _InputString {
  const char *path;             /**< the path to the input string. */
  const unsigned char *buffer;  /**< the buffer containing the input string.*/
  int length;                   /**< the length of the input string excluding 
                                  the end-of-string symbol. */
  int index;                    /**< the current position in the input string.*/
  size_t linesRead;             /**< the number of lines read. */
  size_t columnsRead;           /**< the number of columns read. */
};

/** 
 * Creates an input string from the given buffer.
 * 
 * \param path the path to where the input string was read from
 * (data is copied to private area).
 * \param buf the buffer containing the input string
 * (pointer is taken from the caller, and released during
 * IS_destroyInputString()).
 * \param length the length of the input string, excluding the end-of-string 
 * symbol.
 * \sa IS_destroyInputString.
 * 
 * \return the newly created input string. 
 */
InputString IS_allocateString(const char *path, const unsigned char *buf, int length) {
  char *pathName = strdup(path);
  InputString tmp;

  if (buf == NULL) {
    ATerror("Cannot strdup() input string.");
    return NULL;
  }

  if (path == NULL) {
    ATerror("Cannot strdup() input string.path name");
    return NULL;
  }

  tmp = (InputString) malloc(sizeof(struct _InputString));
  if (tmp == NULL) {
    ATerror("Cannot allocate memory for InputString");
    return NULL;
  }

  tmp->path   = pathName;
  tmp->buffer = buf;
  tmp->length = length;
  tmp->index  = -1;
  tmp->linesRead = 1;
  tmp->columnsRead = 0;
  
  return tmp;
}

/** 
 * Deallocates the given input string.
 * 
 * \param inputString the input string to deallocate from memory.
 */
void IS_destroyInputString(InputString inputString) {
  free((char*)inputString->path);
  free((unsigned char*)inputString->buffer);
  free(inputString);
}

/** 
 * Returns the current token at the given position from the input string. The 
 * position must be a valid position within the input string.
 *  
 * \param inputString the input string.
 * \param index the position in the input string to get the token from.
 * 
 * \return the token at the specified position in the input string.
 */
static Token getToken(InputString inputString, int index) {
  assert(index != -1); 
  assert(index < inputString->length);

  return (Token) inputString->buffer[index];
}

/** 
 * Returns the current token in the input string. 
 * \todo Check that symbol returned is a real token.
 * 
 * \param inputString the input string.
 * 
 * \return the current token in the input string or the #EOS_TOKEN if at the
 * end of the input string.
 */
Token IS_getCurrentToken(InputString inputString) {
  if (IS_isEndOfString(inputString)) {
    return EOS_TOKEN;
  }

  return getToken(inputString, inputString->index);
}

/** 
 * Moves to the next token in the input string. 
 * \todo: Set tab stop size as option with default to 8.
 * 
 * \param inputString the input string.
 */
void IS_readNextToken(InputString inputString) {
  Token token;

  inputString->index++;
  if (!IS_isEndOfString(inputString)) {
    token = getToken(inputString,inputString->index);
  
     switch(token) {
  case '\n' : 
    inputString->linesRead++; 
    inputString->columnsRead = 0;
    break;
  case '\t' : 
    inputString->columnsRead = (inputString->columnsRead / 8+1)* 8;
    break;
  default   : 
    inputString->columnsRead++;                           
    break;
     }
  } 
}

/** 
 * Returns the number of tokens read.
 * 
 * \param inputString the input string.
 * 
 * \return the number of tokens read.
 */
int IS_getNumberOfTokensRead(InputString inputString) {
  return inputString->index == -1 ? 0 : inputString->index+1;
}

/** 
 * Returns the length of the input string excluding the end of string symbol.
 * 
 * \param inputString the input string.
 * 
 * \return the length of the input string.
 */
int IS_getLength(InputString inputString) {
  return inputString->length;
}

/** 
 * Determines if all the input string has been read.
 * 
 * \param inputString the input string.
 * 
 * \return \c true if all the input string has been read; \c false otherwise.
 */
ATbool IS_isEndOfString(InputString inputString) {
  return (inputString->length == inputString->index ||
          inputString->length == 0)  ? ATtrue : ATfalse;
}

/** 
 * Returns the number of lines read from the input string.
 * 
 * \param inputString the input string.
 * 
 * \return the number of newlines read from the input string.
 */
size_t IS_getLinesRead(InputString inputString) {
  return inputString->linesRead;
}

/** 
 * Returns the number of columns read from the current line in the input string.
 * 
 * \param inputString the input string.
 * 
 * \return the number of columns read.
 */
size_t IS_getColumnsRead(InputString inputString) {
  return inputString->columnsRead;
}

/** 
 * Returns the input string's path.
 * 
 * \param inputString the input string.
 * 
 * \return the path of the input string.
 */
const char *IS_getPath(InputString inputString) {
  assert(inputString != NULL);
  return inputString->path;
}

/** 
 * Determines whether the given follow restriction matches the remaining input 
 * string. It is used to determine if the associated reduction should be 
 * performed.
 * 
 * \param inputString the input string.
 * \param restrictions the follow restriction to compare against the input 
 * string.
 * 
 * \return \c true if the restriction does not match the input string; 
 * \c false otherwise.
 */
ATbool IS_checkLookahead(InputString inputString, PTBL_Restrictions restrictions) {
  PTBL_Restriction restriction;
  PT_Symbols charClasses;
  PT_Symbol cc;
  ATbool permitted = ATtrue;
  int index;
  
  for (; permitted && !PTBL_isRestrictionsEmpty(restrictions); restrictions = PTBL_getRestrictionsTail(restrictions)) {
    restriction = PTBL_getRestrictionsHead(restrictions);
    index = inputString->index;
    charClasses = (PT_Symbols)PTBL_getRestrictionCharClasses(restriction);

    while (!PT_isSymbolsEmpty(charClasses)) {
      cc = PT_getSymbolsHead(charClasses);
      charClasses = PT_getSymbolsTail(charClasses);
      index++;

      /* If at end of input no lookahead restrictions apply. */
      if (IS_getLength(inputString) == index) {
        break;
      }

      if (PT_elementOfCharClass(PT_makeTreeChar(getToken(inputString, index)), cc) && PT_isSymbolsEmpty(charClasses)) {
        permitted = ATfalse;
      }
    }
  }

  return permitted;
}

/** 
 * Returns the current positional information from the input string.
 * 
 * \param inputString the input string.
 * 
 * \return the current positional information from the input string.
 */
ERR_Location IS_currentPosInfo(InputString inputString) {
  ERR_Location location;
  ERR_Area area;
  
  area = ERR_makeAreaArea(IS_getLinesRead(inputString), 
			  IS_getColumnsRead(inputString), 
			  IS_getLinesRead(inputString),
			  IS_getColumnsRead(inputString), 
			  IS_getNumberOfTokensRead(inputString), 
			  0);

  if (IS_getPath(inputString) == NULL) {
    location = ERR_makeLocationArea(area);
  }
  else {
    location = ERR_makeLocationAreaInFile(IS_getPath(inputString), area);
  }

  return location;
}

/** 
 * Prints the input string to \c stderr or an error handler if one is installed.
 * 
 * \param inputString the input string.
 */
void IS_output(InputString inputString) {
  ATwarning("Input string: [%s]\n", inputString->buffer);
}
