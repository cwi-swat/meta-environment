#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "TA.h"

/**
 * Converts a string to an ATermList of integers (ASCII values). 
 * \param[in] str An ASCII string
 * \return An ATermList containing the ASCII values of #arg as ATermInts
 */
ATerm TA_stringToChars(const char *str) {
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
ATerm TA_byteToChar(char ch) {
    return (ATerm) ATmakeInt(ch);
}

/**
 * Converts a list of integers (ASCII values) to a C string. 
 * \param[in] arg An ATermList with ATermInts, such as [32,32,10]
 * \return String containing the characters from #arg as characters
 */
char *TA_charsToString(ATerm arg) {
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

char TA_charToByte(ATerm arg) {
    return (char) ATgetInt((ATermInt) arg);
}


typedef struct ATerm _TA_Location;
typedef struct ATerm _TA_Port;


/**
 * Initializes the full API. Forgetting to call this function before using the API will lead to strange behaviour. ATinit() needs to be called before this function.
 */
void _TA_initTAApi(void) {
  init_TA_dict();

}

/**
 * Protect a TA_Location from the ATerm garbage collector. Every TA_Location that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a TA_Location
 */
void _TA_protectLocation(TA_Location *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a TA_Location from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a TA_Location
 */
void _TA_unprotectLocation(TA_Location *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a TA_Port from the ATerm garbage collector. Every TA_Port that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a TA_Port
 */
void _TA_protectPort(TA_Port *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a TA_Port from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a TA_Port
 */
void _TA_unprotectPort(TA_Port *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Transforms an ATerm to a TA_Location. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return TA_Location that was encoded by \arg
 */
TA_Location _TA_LocationFromTerm(ATerm t) {
  return (TA_Location)t;
}

/**
 * Transforms a TA_Locationto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg TA_Location to be converted
 * \return ATerm that represents the TA_Location
 */
ATerm _TA_LocationToTerm(TA_Location arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a TA_Port. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return TA_Port that was encoded by \arg
 */
TA_Port _TA_PortFromTerm(ATerm t) {
  return (TA_Port)t;
}

/**
 * Transforms a TA_Portto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg TA_Port to be converted
 * \return ATerm that represents the TA_Port
 */
ATerm _TA_PortToTerm(TA_Port arg) {
  return (ATerm)arg;
}

/**
 * Constructs a line of type TA_Location. Like all ATerm types, TA_Locations are maximally shared.
 * \param[in] file a child of the new line
 * \param[in] line a child of the new line
 * \return A pointer to a line, either newly constructed or shared
 */
TA_Location TA_makeLocationLine(const char* file, int line) {
  return (TA_Location)(ATerm)ATmakeAppl2(TA_afun0, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(file, 0, ATtrue)), (ATerm) (ATerm) ATmakeInt(line));
}
/**
 * Constructs a area of type TA_Location. Like all ATerm types, TA_Locations are maximally shared.
 * \param[in] file a child of the new area
 * \param[in] startLine a child of the new area
 * \param[in] startCol a child of the new area
 * \param[in] endLine a child of the new area
 * \param[in] endCol a child of the new area
 * \param[in] offset a child of the new area
 * \param[in] length a child of the new area
 * \return A pointer to a area, either newly constructed or shared
 */
TA_Location TA_makeLocationArea(const char* file, int startLine, int startCol, int endLine, int endCol, int offset, int length) {
  return (TA_Location)(ATerm)ATmakeAppl2(TA_afun1, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(file, 0, ATtrue)), (ATerm)ATmakeAppl6(TA_afun2, (ATerm) (ATerm) ATmakeInt(startLine), (ATerm) (ATerm) ATmakeInt(startCol), (ATerm) (ATerm) ATmakeInt(endLine), (ATerm) (ATerm) ATmakeInt(endCol), (ATerm) (ATerm) ATmakeInt(offset), (ATerm) (ATerm) ATmakeInt(length)));
}
/**
 * Constructs a line-col of type TA_Location. Like all ATerm types, TA_Locations are maximally shared.
 * \param[in] file a child of the new line-col
 * \param[in] line a child of the new line-col
 * \param[in] col a child of the new line-col
 * \return A pointer to a line-col, either newly constructed or shared
 */
TA_Location TA_makeLocationLineCol(const char* file, int line, int col) {
  return (TA_Location)(ATerm)ATmakeAppl3(TA_afun3, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(file, 0, ATtrue)), (ATerm) (ATerm) ATmakeInt(line), (ATerm) (ATerm) ATmakeInt(col));
}
/**
 * Constructs a unknown of type TA_Location. Like all ATerm types, TA_Locations are maximally shared.
 * \return A pointer to a unknown, either newly constructed or shared
 */
TA_Location TA_makeLocationUnknown(void) {
  return (TA_Location)(ATerm)ATmakeAppl0(TA_afun4);
}
/**
 * Constructs a step of type TA_Port. Like all ATerm types, TA_Ports are maximally shared.
 * \return A pointer to a step, either newly constructed or shared
 */
TA_Port TA_makePortStep(void) {
  return (TA_Port)(ATerm)ATmakeAppl0(TA_afun5);
}
/**
 * Constructs a stopped of type TA_Port. Like all ATerm types, TA_Ports are maximally shared.
 * \return A pointer to a stopped, either newly constructed or shared
 */
TA_Port TA_makePortStopped(void) {
  return (TA_Port)(ATerm)ATmakeAppl0(TA_afun6);
}
/**
 * Constructs a started of type TA_Port. Like all ATerm types, TA_Ports are maximally shared.
 * \return A pointer to a started, either newly constructed or shared
 */
TA_Port TA_makePortStarted(void) {
  return (TA_Port)(ATerm)ATmakeAppl0(TA_afun7);
}

/**
 * Tests equality of two TA_Locations. A constant time operation.
 * \param[in] arg0 first TA_Location to be compared
 * \param[in] arg1 second TA_Location to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _TA_isEqualLocation(TA_Location arg0, TA_Location arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two TA_Ports. A constant time operation.
 * \param[in] arg0 first TA_Port to be compared
 * \param[in] arg1 second TA_Port to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _TA_isEqualPort(TA_Port arg0, TA_Port arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Assert whether a TA_Location is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input TA_Location
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool TA_isValidLocation(TA_Location arg) {
  if (TA_isLocationLine(arg)) {
    return ATtrue;
  }
  else if (TA_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (TA_isLocationLineCol(arg)) {
    return ATtrue;
  }
  else if (TA_isLocationUnknown(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a TA_Location is a line by checking against the following ATerm pattern: line(<file(str)>,<line(int)>). May not be used to assert correctness of the TA_Location
 * \param[in] arg input TA_Location
 * \return ATtrue if #arg corresponds to the signature of a line, or ATfalse otherwise
 */
inline ATbool TA_isLocationLine(TA_Location arg){
  /* checking for: line */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == TA_afun0) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      ATerm arg_arg1 = ATgetArgument(arg, 1);
      if (ATgetType((ATerm)arg_arg1) == AT_INT) {
        return ATtrue;
      }
    }
  }
  return ATfalse;
}

/**
 * Assert whether a TA_Location is a area by checking against the following ATerm pattern: area-in-file(<file(str)>,area(<start-line(int)>,<start-col(int)>,<end-line(int)>,<end-col(int)>,<offset(int)>,<length(int)>)). May not be used to assert correctness of the TA_Location
 * \param[in] arg input TA_Location
 * \return ATtrue if #arg corresponds to the signature of a area, or ATfalse otherwise
 */
inline ATbool TA_isLocationArea(TA_Location arg){
  /* checking for: area-in-file */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == TA_afun1) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      ATerm arg_arg1 = ATgetArgument(arg, 1);
      /* checking for: area */
      if (ATgetType((ATerm)arg_arg1) == AT_APPL && ATgetAFun((ATermAppl)arg_arg1) == TA_afun2) {
        ATerm arg_arg1_arg0 = ATgetArgument(arg_arg1, 0);
        if (ATgetType((ATerm)arg_arg1_arg0) == AT_INT) {
          ATerm arg_arg1_arg1 = ATgetArgument(arg_arg1, 1);
          if (ATgetType((ATerm)arg_arg1_arg1) == AT_INT) {
            ATerm arg_arg1_arg2 = ATgetArgument(arg_arg1, 2);
            if (ATgetType((ATerm)arg_arg1_arg2) == AT_INT) {
              ATerm arg_arg1_arg3 = ATgetArgument(arg_arg1, 3);
              if (ATgetType((ATerm)arg_arg1_arg3) == AT_INT) {
                ATerm arg_arg1_arg4 = ATgetArgument(arg_arg1, 4);
                if (ATgetType((ATerm)arg_arg1_arg4) == AT_INT) {
                  ATerm arg_arg1_arg5 = ATgetArgument(arg_arg1, 5);
                  if (ATgetType((ATerm)arg_arg1_arg5) == AT_INT) {
                    return ATtrue;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return ATfalse;
}

/**
 * Assert whether a TA_Location is a line-col by checking against the following ATerm pattern: lc(<file(str)>,<line(int)>,<col(int)>). May not be used to assert correctness of the TA_Location
 * \param[in] arg input TA_Location
 * \return ATtrue if #arg corresponds to the signature of a line-col, or ATfalse otherwise
 */
inline ATbool TA_isLocationLineCol(TA_Location arg){
  /* checking for: lc */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == TA_afun3) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      ATerm arg_arg1 = ATgetArgument(arg, 1);
      if (ATgetType((ATerm)arg_arg1) == AT_INT) {
        ATerm arg_arg2 = ATgetArgument(arg, 2);
        if (ATgetType((ATerm)arg_arg2) == AT_INT) {
          return ATtrue;
        }
      }
    }
  }
  return ATfalse;
}

/**
 * Assert whether a TA_Location is a unknown by checking against the following ATerm pattern: unknown. May not be used to assert correctness of the TA_Location
 * \param[in] arg input TA_Location
 * \return ATtrue if #arg corresponds to the signature of a unknown, or ATfalse otherwise
 */
inline ATbool TA_isLocationUnknown(TA_Location arg){
  /* checking for: unknown */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == TA_afun4) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a TA_Location has a file. 
 * \param[in] arg input TA_Location
 * \return ATtrue if the TA_Location had a file, or ATfalse otherwise
 */
ATbool TA_hasLocationFile(TA_Location arg) {
  if (TA_isLocationLine(arg)) {
    return ATtrue;
  }
  else if (TA_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (TA_isLocationLineCol(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a TA_Location has a line. 
 * \param[in] arg input TA_Location
 * \return ATtrue if the TA_Location had a line, or ATfalse otherwise
 */
ATbool TA_hasLocationLine(TA_Location arg) {
  if (TA_isLocationLine(arg)) {
    return ATtrue;
  }
  else if (TA_isLocationLineCol(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a TA_Location has a start-line. 
 * \param[in] arg input TA_Location
 * \return ATtrue if the TA_Location had a start-line, or ATfalse otherwise
 */
ATbool TA_hasLocationStartLine(TA_Location arg) {
  if (TA_isLocationArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a TA_Location has a start-col. 
 * \param[in] arg input TA_Location
 * \return ATtrue if the TA_Location had a start-col, or ATfalse otherwise
 */
ATbool TA_hasLocationStartCol(TA_Location arg) {
  if (TA_isLocationArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a TA_Location has a end-line. 
 * \param[in] arg input TA_Location
 * \return ATtrue if the TA_Location had a end-line, or ATfalse otherwise
 */
ATbool TA_hasLocationEndLine(TA_Location arg) {
  if (TA_isLocationArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a TA_Location has a end-col. 
 * \param[in] arg input TA_Location
 * \return ATtrue if the TA_Location had a end-col, or ATfalse otherwise
 */
ATbool TA_hasLocationEndCol(TA_Location arg) {
  if (TA_isLocationArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a TA_Location has a offset. 
 * \param[in] arg input TA_Location
 * \return ATtrue if the TA_Location had a offset, or ATfalse otherwise
 */
ATbool TA_hasLocationOffset(TA_Location arg) {
  if (TA_isLocationArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a TA_Location has a length. 
 * \param[in] arg input TA_Location
 * \return ATtrue if the TA_Location had a length, or ATfalse otherwise
 */
ATbool TA_hasLocationLength(TA_Location arg) {
  if (TA_isLocationArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a TA_Location has a col. 
 * \param[in] arg input TA_Location
 * \return ATtrue if the TA_Location had a col, or ATfalse otherwise
 */
ATbool TA_hasLocationCol(TA_Location arg) {
  if (TA_isLocationLineCol(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the file char* of a TA_Location. Note that the precondition is that this TA_Location actually has a file
 * \param[in] arg input TA_Location
 * \return the file of #arg, if it exist or an undefined value if it does not
 */
char* TA_getLocationFile(TA_Location arg) {
  if (TA_isLocationLine(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (TA_isLocationArea(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/**
 * Get the line int of a TA_Location. Note that the precondition is that this TA_Location actually has a line
 * \param[in] arg input TA_Location
 * \return the line of #arg, if it exist or an undefined value if it does not
 */
int TA_getLocationLine(TA_Location arg) {
  if (TA_isLocationLine(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Get the start-line int of a TA_Location. Note that the precondition is that this TA_Location actually has a start-line
 * \param[in] arg input TA_Location
 * \return the start-line of #arg, if it exist or an undefined value if it does not
 */
int TA_getLocationStartLine(TA_Location arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 1), 0));
}

/**
 * Get the start-col int of a TA_Location. Note that the precondition is that this TA_Location actually has a start-col
 * \param[in] arg input TA_Location
 * \return the start-col of #arg, if it exist or an undefined value if it does not
 */
int TA_getLocationStartCol(TA_Location arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 1), 1));
}

/**
 * Get the end-line int of a TA_Location. Note that the precondition is that this TA_Location actually has a end-line
 * \param[in] arg input TA_Location
 * \return the end-line of #arg, if it exist or an undefined value if it does not
 */
int TA_getLocationEndLine(TA_Location arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 1), 2));
}

/**
 * Get the end-col int of a TA_Location. Note that the precondition is that this TA_Location actually has a end-col
 * \param[in] arg input TA_Location
 * \return the end-col of #arg, if it exist or an undefined value if it does not
 */
int TA_getLocationEndCol(TA_Location arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 1), 3));
}

/**
 * Get the offset int of a TA_Location. Note that the precondition is that this TA_Location actually has a offset
 * \param[in] arg input TA_Location
 * \return the offset of #arg, if it exist or an undefined value if it does not
 */
int TA_getLocationOffset(TA_Location arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 1), 4));
}

/**
 * Get the length int of a TA_Location. Note that the precondition is that this TA_Location actually has a length
 * \param[in] arg input TA_Location
 * \return the length of #arg, if it exist or an undefined value if it does not
 */
int TA_getLocationLength(TA_Location arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 1), 5));
}

/**
 * Get the col int of a TA_Location. Note that the precondition is that this TA_Location actually has a col
 * \param[in] arg input TA_Location
 * \return the col of #arg, if it exist or an undefined value if it does not
 */
int TA_getLocationCol(TA_Location arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 2));
}

/**
 * Set the file of a TA_Location. The precondition being that this TA_Location actually has a file
 * \param[in] arg input TA_Location
 * \param[in] file new const char* to set in #arg
 * \return A new TA_Location with file at the right place, or a core dump if #arg did not have a file
 */
TA_Location TA_setLocationFile(TA_Location arg, const char* file) {
  if (TA_isLocationLine(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(file, 0, ATtrue))), 0);
  }
  else if (TA_isLocationArea(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(file, 0, ATtrue))), 0);
  }
  else if (TA_isLocationLineCol(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(file, 0, ATtrue))), 0);
  }

  ATabort("Location has no File: %t\n", arg);
  return (TA_Location)NULL;
}

/**
 * Set the line of a TA_Location. The precondition being that this TA_Location actually has a line
 * \param[in] arg input TA_Location
 * \param[in] line new int to set in #arg
 * \return A new TA_Location with line at the right place, or a core dump if #arg did not have a line
 */
TA_Location TA_setLocationLine(TA_Location arg, int line) {
  if (TA_isLocationLine(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(line)), 1);
  }
  else if (TA_isLocationLineCol(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(line)), 1);
  }

  ATabort("Location has no Line: %t\n", arg);
  return (TA_Location)NULL;
}

/**
 * Set the start-line of a TA_Location. The precondition being that this TA_Location actually has a start-line
 * \param[in] arg input TA_Location
 * \param[in] startLine new int to set in #arg
 * \return A new TA_Location with startLine at the right place, or a core dump if #arg did not have a startLine
 */
TA_Location TA_setLocationStartLine(TA_Location arg, int startLine) {
  if (TA_isLocationArea(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) (ATerm) ATmakeInt(startLine)), 0), 1);
  }

  ATabort("Location has no StartLine: %t\n", arg);
  return (TA_Location)NULL;
}

/**
 * Set the start-col of a TA_Location. The precondition being that this TA_Location actually has a start-col
 * \param[in] arg input TA_Location
 * \param[in] startCol new int to set in #arg
 * \return A new TA_Location with startCol at the right place, or a core dump if #arg did not have a startCol
 */
TA_Location TA_setLocationStartCol(TA_Location arg, int startCol) {
  if (TA_isLocationArea(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) (ATerm) ATmakeInt(startCol)), 1), 1);
  }

  ATabort("Location has no StartCol: %t\n", arg);
  return (TA_Location)NULL;
}

/**
 * Set the end-line of a TA_Location. The precondition being that this TA_Location actually has a end-line
 * \param[in] arg input TA_Location
 * \param[in] endLine new int to set in #arg
 * \return A new TA_Location with endLine at the right place, or a core dump if #arg did not have a endLine
 */
TA_Location TA_setLocationEndLine(TA_Location arg, int endLine) {
  if (TA_isLocationArea(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) (ATerm) ATmakeInt(endLine)), 2), 1);
  }

  ATabort("Location has no EndLine: %t\n", arg);
  return (TA_Location)NULL;
}

/**
 * Set the end-col of a TA_Location. The precondition being that this TA_Location actually has a end-col
 * \param[in] arg input TA_Location
 * \param[in] endCol new int to set in #arg
 * \return A new TA_Location with endCol at the right place, or a core dump if #arg did not have a endCol
 */
TA_Location TA_setLocationEndCol(TA_Location arg, int endCol) {
  if (TA_isLocationArea(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) (ATerm) ATmakeInt(endCol)), 3), 1);
  }

  ATabort("Location has no EndCol: %t\n", arg);
  return (TA_Location)NULL;
}

/**
 * Set the offset of a TA_Location. The precondition being that this TA_Location actually has a offset
 * \param[in] arg input TA_Location
 * \param[in] offset new int to set in #arg
 * \return A new TA_Location with offset at the right place, or a core dump if #arg did not have a offset
 */
TA_Location TA_setLocationOffset(TA_Location arg, int offset) {
  if (TA_isLocationArea(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) (ATerm) ATmakeInt(offset)), 4), 1);
  }

  ATabort("Location has no Offset: %t\n", arg);
  return (TA_Location)NULL;
}

/**
 * Set the length of a TA_Location. The precondition being that this TA_Location actually has a length
 * \param[in] arg input TA_Location
 * \param[in] length new int to set in #arg
 * \return A new TA_Location with length at the right place, or a core dump if #arg did not have a length
 */
TA_Location TA_setLocationLength(TA_Location arg, int length) {
  if (TA_isLocationArea(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) (ATerm) ATmakeInt(length)), 5), 1);
  }

  ATabort("Location has no Length: %t\n", arg);
  return (TA_Location)NULL;
}

/**
 * Set the col of a TA_Location. The precondition being that this TA_Location actually has a col
 * \param[in] arg input TA_Location
 * \param[in] col new int to set in #arg
 * \return A new TA_Location with col at the right place, or a core dump if #arg did not have a col
 */
TA_Location TA_setLocationCol(TA_Location arg, int col) {
  if (TA_isLocationLineCol(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(col)), 2);
  }

  ATabort("Location has no Col: %t\n", arg);
  return (TA_Location)NULL;
}

/**
 * Assert whether a TA_Port is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input TA_Port
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool TA_isValidPort(TA_Port arg) {
  if (TA_isPortStep(arg)) {
    return ATtrue;
  }
  else if (TA_isPortStopped(arg)) {
    return ATtrue;
  }
  else if (TA_isPortStarted(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a TA_Port is a step by checking against the following ATerm pattern: step. May not be used to assert correctness of the TA_Port
 * \param[in] arg input TA_Port
 * \return ATtrue if #arg corresponds to the signature of a step, or ATfalse otherwise
 */
inline ATbool TA_isPortStep(TA_Port arg){
  /* checking for: step */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == TA_afun5) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a TA_Port is a stopped by checking against the following ATerm pattern: stopped. May not be used to assert correctness of the TA_Port
 * \param[in] arg input TA_Port
 * \return ATtrue if #arg corresponds to the signature of a stopped, or ATfalse otherwise
 */
inline ATbool TA_isPortStopped(TA_Port arg){
  /* checking for: stopped */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == TA_afun6) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a TA_Port is a started by checking against the following ATerm pattern: started. May not be used to assert correctness of the TA_Port
 * \param[in] arg input TA_Port
 * \return ATtrue if #arg corresponds to the signature of a started, or ATfalse otherwise
 */
inline ATbool TA_isPortStarted(TA_Port arg){
  /* checking for: started */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == TA_afun7) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Apply functions to the children of a TA_Location. 
 * \return A new TA_Location with new children where the argument functions might have applied
 */
TA_Location TA_visitLocation(TA_Location arg, char* (*acceptFile)(char*), int (*acceptLine)(int), int (*acceptStartLine)(int), int (*acceptStartCol)(int), int (*acceptEndLine)(int), int (*acceptEndCol)(int), int (*acceptOffset)(int), int (*acceptLength)(int), int (*acceptCol)(int)) {
  if (TA_isLocationLine(arg)) {
    return TA_makeLocationLine(
        acceptFile ? acceptFile(TA_getLocationFile(arg)) : TA_getLocationFile(arg),
        acceptLine ? acceptLine(TA_getLocationLine(arg)) : TA_getLocationLine(arg));
  }
  if (TA_isLocationArea(arg)) {
    return TA_makeLocationArea(
        acceptFile ? acceptFile(TA_getLocationFile(arg)) : TA_getLocationFile(arg),
        acceptStartLine ? acceptStartLine(TA_getLocationStartLine(arg)) : TA_getLocationStartLine(arg),
        acceptStartCol ? acceptStartCol(TA_getLocationStartCol(arg)) : TA_getLocationStartCol(arg),
        acceptEndLine ? acceptEndLine(TA_getLocationEndLine(arg)) : TA_getLocationEndLine(arg),
        acceptEndCol ? acceptEndCol(TA_getLocationEndCol(arg)) : TA_getLocationEndCol(arg),
        acceptOffset ? acceptOffset(TA_getLocationOffset(arg)) : TA_getLocationOffset(arg),
        acceptLength ? acceptLength(TA_getLocationLength(arg)) : TA_getLocationLength(arg));
  }
  if (TA_isLocationLineCol(arg)) {
    return TA_makeLocationLineCol(
        acceptFile ? acceptFile(TA_getLocationFile(arg)) : TA_getLocationFile(arg),
        acceptLine ? acceptLine(TA_getLocationLine(arg)) : TA_getLocationLine(arg),
        acceptCol ? acceptCol(TA_getLocationCol(arg)) : TA_getLocationCol(arg));
  }
  if (TA_isLocationUnknown(arg)) {
    return TA_makeLocationUnknown();
  }
  ATabort("not a Location: %t\n", arg);
  return (TA_Location)NULL;
}
/**
 * Apply functions to the children of a TA_Port. 
 * \return A new TA_Port with new children where the argument functions might have applied
 */
TA_Port TA_visitPort(TA_Port arg) {
  if (TA_isPortStep(arg)) {
    return TA_makePortStep();
  }
  if (TA_isPortStopped(arg)) {
    return TA_makePortStopped();
  }
  if (TA_isPortStarted(arg)) {
    return TA_makePortStarted();
  }
  ATabort("not a Port: %t\n", arg);
  return (TA_Port)NULL;
}

