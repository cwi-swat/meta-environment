/*
 * $Id$
 * (C) 1999, Merijn de jonge (mdejonge@wins.uva.nl)
 *
 */
#ifndef _module_utils_h
#define _module_utils_h

/* Flags which contral behavior of the function getImports */
#define FailWhenNotFound 0x01 /* stop as soon as a module
                                 could not be located */
#define Recursive        0x02 /* construct a list of
                                 imported modules recursively */

/*
 * construct a list of modules thet are directly (or indirectly
 * imported by topModule/
 */
ATermList getImports( char *msmPathsFile,
                      char *topModule, unsigned int options );

#endif /*  _module_utils_h */
