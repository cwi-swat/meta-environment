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
 *      <module> AsFix representation of ASF+SDF module
 *
 */

#include "aterm2.h"
#include "AsFix-fun.h"
#include "AsFix-expand.h"
#include "AsFix-init-patterns.h"
#include "AsFix.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

#include "meta-utils.h"
#include "module-utils.h"

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
   FILE *f;
   ATermList imports;
   ATermList sections;
   ATerm t;
   ATerm module;
   int n;
   char* s;

   /* initialize list of imported modules */
   imports = ATmakeList0();

   /* open module located at path */
   f = fopen( path, "r" );
   if( f == NULL )
   {
      FAIL1( "fopen", path );
      exit( 1 );
   }

   /* Read module */
   module = ATreadFromFile( f );

   if( module == NULL )
   {
      FAIL( "readFromFile" );
      exit( 1 );
   }
   fclose( f );

   /* Test whether asfix term represents a module */
   if( strcmp( ATgetName( ATgetSymbol( module ) ), "module" ) != 0 )
   {
      fprintf( stderr,
         "AsFix term %s does not represent an ASF+SDF module.\n",
         path );
      exit( 1 );
   }

   /* Obtain list of sections from module */
   sections = (ATermList)ATgetArgument( module, p_module_sections );

   /* Traverse elements in list */
   while( !ATisEmpty( sections ) )
   {

      t = ATgetFirst( sections );
      sections = ATgetNext( sections );

      /* When we see an imports section, we add all id's to the
       * list of imported modules.
       */
      if( strcmp( ATgetName( ATgetSymbol( t ) ), "imports" ) == 0 )
      {
         imports =
            ATconcat( imports, (ATermList)ATgetArgument( t, p_imports_ids ) );
      }

   }

   /* The list imports contains layout nodes and nodes with function
    * symbol "id". We traverse the list and remove all ws elements
    * and change elements which match the pattern id(<str>) by <str>.
    */
   n = ATgetLength( imports );
   while( n > 0 )
   {
      t = ATgetFirst( imports );
      imports = ATgetNext( imports );
      if( ATmatch( t, "id(<str>)", &s ) )
      {
         t = ATmake( "<str>", s );
         imports = ATappend( imports, t );
      }
      n--;
   }
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
   AFinitExpansionTerms();
   AFinitAsFixPatterns();

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
    * ".asfix" to it
    */
   strcpy( module, topModule );
   if( strstr( module, ".asfix" ) == NULL )
      strcat( module, ".asfix" );

   /* locate the top module... */
   path = metaPathsLocate( &mp, module );
   if( path == NULL )
   {
      FAIL( "getImports" );
      exit( 1 );
   }

   /* ... and append it to the list of imported modules */
   t = ATmake( "<str>", path );
   imports = ATappend( imports, t );

   /* Append the node to the list of nodes when it not already
    * occurs in the list
    */
   if( options & Graph )
      nodes = ATappend( nodes, t );


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
         sprintf( module, "%s.asfix", path1 );
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
