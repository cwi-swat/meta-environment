/*$Id$*/

/** \file
 * This is the implementation of the reading in of the input string from file or
 * directly from memory. 
 * 
 * \todo Deal correctly with the path.
 */

#include "inputStringBuilder.h"
#include "inputString-api.h"
#include <aterm1.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <rsrc-usage.h>
#include <Error-manager.h>


/** We got this number by calculating the average number of characters in all 
 * c, java, asf, sdf, tb and idef files in the asfsdf-meta, rscript-meta, 
 * apigen and sdf-apigen packages and their dependencies. */
static const int BUFCHUNK = 10000;
static double timeTakenToReadInput = 0.0;

/** 
 * Creates an input string from the given string. When creating an input string 
 * from a string (as is done for the toolbus invocation of SGLR) there is no 
 * path. As a result \c _noPath_ is passed in.
 * 
 * \todo Make toolbus handle \c _noPath_.
 * 
 * \param string the input string.
 * 
 * \return the newly created input string.
 */
InputString IS_createInputStringFromString(const unsigned char *string) {
  unsigned char *buf = (unsigned char*)strdup((const char *)string);
  int   len = (int)strlen((const char *)string);
 
  return IS_allocateString("_noPath_", buf, len);
}

/** 
 * Creates an input string object from the given string.
 * 
 * \param path the path to the input string.
 * \param string the input string.
 * \param length the length of the input string.
 * 
 * \return the newly created input string.
 */
InputString IS_createInputStringFromBytes(const char *path, const unsigned char *string, const int length) {
  unsigned char *buf = malloc(length * sizeof(char)); 
  memcpy(buf, string, length);
 
  return IS_allocateString(path, buf, length);
}

/** 
 * Reads the input string from a file with the given path and creates an input 
 * string object.
 * 
 * \param path the path to the input string.
 * 
 * \return the newly created input string.
 */
InputString IS_createInputStringFromFile(const char *path) {
  InputString retval;
  unsigned char *buf = NULL;
  size_t curbufsize = 0;
  size_t bytesRead = BUFCHUNK;
  FILE *in; 
  int length = 0;
  ATbool readFromStdin = ATfalse;

  STATS_Timer();
  if (path == NULL || strcmp(path,"") == 0 || strcmp(path,"-") == 0) {
    in = stdin;
    readFromStdin = ATtrue;
  }
  else {
    in = fopen(path, "rb");
  }

  if (in == NULL) {
    ERR_managerStoreError("Can not open file", ERR_makeSubjectListSingle(ERR_makeSubjectSubject(path)));
    /** \todo Return a proper error (using strerror)! */
    return NULL;
  }
  
  while(bytesRead == BUFCHUNK) {
    curbufsize += BUFCHUNK;    
    buf = realloc(buf, sizeof(unsigned char) * curbufsize);
    if (buf == NULL) {
      ATerror("Cannot allocate memory for input string.");
    }
    bytesRead = fread(buf+(curbufsize-BUFCHUNK), sizeof(unsigned char), BUFCHUNK, in);
  }  

  assert(bytesRead != BUFCHUNK &&  "Not enough memory for end of string.");
  length = (curbufsize-BUFCHUNK)+bytesRead;
  
  if (!readFromStdin) {
    fclose(in);
  }

  retval = IS_allocateString(path, buf, length);
  timeTakenToReadInput = STATS_Timer();

  return retval;
}

double IS_getTimeTakenToReadInput(void) {
  return timeTakenToReadInput;
}
