/*

    Meta-Environment - An environment for language prototyping.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, The Netherlands. 

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/
/*
 * $Id$
 * (C) 1999, Merijn de jonge (mdejonge@wins.uva.nl)
 *
 */
#ifndef _module_utils_h
#define _module_utils_h

/* Flags which contral behavior of the function getImports */
typedef enum { 
   FailWhenNotFound = 0x01, /* stop as soon as a module could not be located */
   Recursive        = 0x02, /* construct a list of imported modules recursively */
   Graph            = 0x04  /* construct a graph representing the import sturcture 
                             * the top module*/
} ModuleOptions;

/*
 * construct a list of modules thet are directly (or indirectly
 * imported by topModule/
 */
ATermList getImports( char *msmPathsFile,
                      char *topModule, ModuleOptions options );

#endif /*  _module_utils_h */
