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
 *
 * (C) 1999, Merijn de Jonge (mdejonge@wins.uva.nl)
 *
 * imports: generates list of the names on standard output of all modules
 *          that are imported by an ASF+SDF module.
 *
 * usage:
 *   imports <module>
 *      <module> parsetree representation of SDF module
 *
 */

#include "aterm2.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

#include "meta-utils.h"
#include "module-utils.h"
#include <SDF-utils.h>
#include <PT-utils.h>

/* Macros for displaying error messages */
#define FAIL(x) fprintf(stderr, "%s(%d): %s: %s\n", \
   __FILE__, __LINE__, x, strerror( errno ) );

#define FAIL1(x,y) fprintf(stderr, "%s(%d): %s(%s): %s\n", \
        __FILE__, __LINE__, x, y, strerror( errno ) );


/* for debugging purposes */
#define DB {fprintf(stderr, "%s-%d\n", __FILE__, __LINE__ );}

/* Checks whether  t1 occurs in l1 */
ATbool contains( const ATermList l1, const ATerm t1)
{
   if( ATindexOf( l1, t1, 0 ) == -1 )
      return ATfalse;
   return ATtrue;
}


/*
 * Return list of names of modules that are imported by the module
 * located at path. Note that a list of module names is returned, not
 * a list of module path names.
 */
ATermList _getImports( char* path )
{
   ATerm module;
   PT_ParseTree parseTree;
   SDF_Module sdfModule;
   ATermList imports;
   
   /* Read module */
   module = ATreadFromNamedFile( path );
  
   if( module == NULL )
   {
      FAIL1( "readFromFile", path );
      exit( 1 );
   }
  
   parseTree = PT_makeParseTreeFromTerm(module);
   sdfModule = SDF_makeModuleFromTerm(
               PT_makeTermFromTree(
                 PT_getParseTreeTree(parseTree)));
 
   if (!SDF_isValidModule(sdfModule))
   {
      ATwarning("Not a valid sdf module: %t\n", sdfModule);
      exit( 1 );
   }

   imports = SDF_getImports(sdfModule);
ATwarning("imports = %t\n", imports);
   return imports;
}

/*
 * Return a list of modules that are imported by the module
 * topModule. The behavior of getImports is controlled by options:
 *
 * FailWhenNotFound: we stop collecting modules names as soon as
 *                   a module could not be located.
 * Recursive:        a list of modules is constructing by traversing the
 *                   modules recursively.
 * Graph:            a a graph structure is constructed representing the
 *                   import structure of an ASF+SDF module. The structure
 *                   holds a lists of nodes and a list of edges.
 *
 * These options can be 'or-ed' together.
 *
 * location of modules is performed relatively to the directories
 * specified in the meta.conf-paths file metaPathFile.
 *
 */
ATermList getImports( char* metaPathsFile, char* topModule, ModuleOptions options )
{
   meta_paths mp;
   char*  path;
   char*  path1;
   char   module[_POSIX_PATH_MAX];

   ATermList imports;
   ATermList modules;
   ATermList nodes;
   ATermList edges;
   ATerm t;
   int   index;

   /* Initialize AsFix routines */

   /* Create empty imports list */
   imports = ATmakeList0();

   /* Initialize empty nodes and edges list */
   nodes = ATmakeList0();
   edges = ATmakeList0();

   /* open meta.conf-paths file */
   if( metaPathsOpen( &mp, metaPathsFile ) == -1 )
   {
      FAIL1( "metaPathsOpen", metaPathsFile );
      exit( 1 );
   }

   /*
    * construct file name from topModule name by appending the extension
    * ".baf" to it
    */
   strcpy( module, topModule );
   if( strstr( module, ".baf" ) == NULL )
      strcat( module, ".baf" );
   
   /* locate the top module... */
   path = metaPathsLocate( &mp, module );
   if( path == NULL )
   {
      FAIL1( "getImports", module );
      exit( 1 );
   }
   /* ... and append it to the list of imported modules */
   t = ATmake( "<str>", path );
   imports = ATappend( imports, t );
   
   /* Append the node to the list of nodes when it not already
    * occurs in the list
    */
   if( options & Graph ) {
      nodes = ATappend( nodes, t );
   }

   /* We now traverse all elements in the list and collect all module
    * names that are imported by each of these modules. When
    * Recursive option was not specified, we terminate the loop after
    * one pass.
    */
   index = 0;
   while( index < ATgetLength( imports ) )
   {
      t = ATelementAt( imports, index );
      index++;

      /* obtain sting from term t */
      ATmatch( t, "<str>", &path );
      /* collect names of modules that are imported by the module
       * located at path
       */
      modules = _getImports( path );
    while( ATisEmpty( modules ) == ATfalse )
      {
        /* from the list thus obtained, we remove entries that are
         * already contained in imports. Furthermore, we construct
         * full path names from the module names, by locating their location.
         * relative to the path names defined in metaPathsFile
         */
         t = ATgetFirst( modules );
         modules = ATgetNext( modules );

         ATmatch( t, "<str>", &path1 );
         sprintf( module, "%s.sdf.baf", path1 );
         path1 = metaPathsLocate( &mp, module );
         if( path1 == NULL )
         {
            /* module could not be located. FailWhenNotFound option
             * was specified so we quit and return the list of
             * modules obtained thus far
             */
            if( options & FailWhenNotFound )
            {
               /* Construct list from nodes and edges */
               if( options & Graph )
                  return (ATermList)ATmake( "[<term>,<term>]", nodes, edges );
               else
                  return imports;
            }
         }
         else
         {
            t = ATmake( "<str>", path1 );
            if( contains( imports, t ) == ATfalse )
            {
               imports = ATappend( imports, t );
               if( options & Graph )
                  if( contains( nodes, t ) == ATfalse )
                     nodes = ATappend( nodes, t );

            }
            if( options & Graph )
            {
               /* Add new edge to list of edges when it does not
                *  already occur in the list.
                */
               t = ATmake( "[<str>,<str>]", path, path1 );
               if( contains( edges, t ) == ATfalse )
                  edges = ATappend( edges, t );
            }
         }
      }
      /* When the option Recursive was not specified, we terminate
       * the loop and return the list of modules obtained thus far
       * after removing the first element (was is the top module).
       */
      if( !(options & Recursive ) )
      {
         /* Construct list from nodes and edges */
         if( options & Graph )
            return (ATermList)ATmake( "[<term>,<term>]", nodes, edges );
         else
            return ATgetNext( imports );
      }
   }

   /* we are done. Return the list of modules or list of nodes and edges. */
   if( options & Graph )
      return (ATermList)ATmake( "[<term>,<term>]", nodes, edges );
   else
      return imports;
}
