/*
 * $Id$
 *
 * imports: generates list of the names on standard output of all modules
 *          that are imported by an ASF+SDF module.
 *
 * usage:
 *    imports [-option] meta.conf-file module
 *  
 *    meta.conf-file file containing search paths
 *    module         AsFix representation of ASF+SDF module
 *  
 *    options:
 *       -g  output graph corresponding to import graph
 *       -h  displays this message
 *       -l  print full paths names of modules
 *       -r  construct a list of modules recursively
 *       -s  stop when a module cannot be found
 *  
 *
 */

#include <aterm2.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

#if defined(MEPT)
#include <SDFME-utils.h>
#include <MEPT.h>
#elif defined(ASFIX1)
#include <SDF-utils.h>
#include <PT.h>
#else
#error "MEPT or ASFIX1 need to be defined!"
#endif

#ifdef HAVE_GETOPT_H
#include <getopt.h>
#else
#include <unistd.h>
#endif
extern char* optarg;

#include "module-utils.h"

#define USAGE_MSG \
   "   generates list of the names on standard output of all modules \n"\
   "   that are imported by an SDF module.\n"\
   "\n"\
   "usage:\n"\
   "   imports [-option] meta.conf-file module\n"\
   "\n"\
   "      meta.conf-file file containing search paths\n"\
   "      module         AsFix representation of ASF+SDF module\n"\
   "\n"\
   "      options:\n"\
   "         -g  output graph corresponding to import graph\n"\
   "         -h  displays this message\n"\
   "         -l  print full paths names of modules\n"\
   "         -r  construct a list of modules recursively\n"\
   "         -s  stop when a module cannot be found\n"\
   "         -V  show version\n"\
   "\n"

/* Command line options used by imports */
static char* opt_string = "ghlrsV";

/* Version */
static char myversion[] = "0.1";

extern ATbool silent;

#define FAIL(x) fprintf(stderr, "%s(%d): %s: %s\n", \
   __FILE__, __LINE__, x, strerror( errno ) );

#define FAIL1(x,y) fprintf(stderr, "%s(%d): %s(%s): %s\n", \
        __FILE__, __LINE__, x, y, strerror( errno ) );


#define DB {fprintf(stderr, "%s-%d\n", __FILE__, __LINE__ );}

static void usage()
{
  ATwarning(USAGE_MSG);
}

static char* basename( const char* s )
{ 
   static char buffer[_POSIX_PATH_MAX];
   char* ptr;
   
   /* short listing: remove directory and extension from file name */
   strcpy( buffer, s );
   ptr = strrchr( buffer, '/' );
   if( ptr != NULL )
      strcpy( buffer, ptr + 1 );
   ptr = strrchr( buffer, '.' );
   if( ptr != NULL )
      *ptr = '\0';
   return buffer;
}

static void version(const char *prg)
{
    ATwarning("%s v%s\n", prg, myversion);
}

int main( int argc, char* argv[] )
{
   ATerm bottomOfStack;
   ATermList imports;
   ATbool    long_listing;
   char*     s;
   int       options;
   int      c;

   /* initialize variables */
   options = 0;
   long_listing = ATfalse;

   /* parse command line options. */
   while(1 )
   {
      c = getopt( argc, argv, opt_string );
      if( c == -1 )
         break;
      switch( c )
      {
         case 'g':
            options |= Graph;
            break;
         case 'h':
            usage();
            exit( 0 );
         case 'l':
            long_listing = ATtrue;
            break;
         case 'r':
            options |= Recursive;
            break;
         case 's':
            options |= FailWhenNotFound;
            break;
         case 'V':
	    version(argv[0]);
	    exit( 0 );
	    break;
         default:
            usage();
            exit( 1 );
       }
    }

    /* make sure, there are still two file arguments available */
    if( argc - optind != 2 )
    {
       usage();
       exit( 1 );
    }
   /* Initialize AsFix routines */
   silent = ATtrue;
   ATinit(argc, argv, &bottomOfStack);

#if defined(MEPT)
   SDF_initSDFMEApi();
   PT_initMEPTApi();
#elif defined(ASFIX1)
   SDF_initSDFApi();
   PT_initPTApi();
#else
   #error "MEPT or ASFIX1 need to be defined!"
#endif

   /* Obtain list of imported modules */
   imports = getImports( argv[optind], argv[optind + 1], options );
   if( imports == NULL )
      return 1;

   /* Convert to graph format:
    *    graph(nodes([id("node_1"),...,id("node_n")]),
    *          edges([ [id("node_i"), id("node_j")], ... ]) )
    */
   if( options & Graph )
   {
      ATermList nodes;
      ATermList edges;
      int i;
      ATerm t;
      char* s;
      char* s1;
      char* s2;
      
      /* Obtain list of nodes and edges as returned by getImport */
      ATmatch( (ATerm)imports, "[<term>,<term>]", &nodes, &edges );
      
      /* Traverse all nodes */
      for( i = 0; i < ATgetLength( nodes ); i++ )
      {
         t = ATelementAt( nodes, i );
         ATmatch( t, "<str>", &s );

         /* if the '-l' option was not specified, we strip of the path and
          * extension of the file name 
          */
         if( long_listing == ATfalse )
            s = basename ( basename(s) );
         
         /* Finally, we create a term with function symbol "id" */
         nodes = ATreplace( nodes, ATmake( "id(<str>)", s ), i);
      }

      /* Traverse all edges */
      for( i = 0; i < ATgetLength( edges ); i++ )
      {
         t = ATelementAt( edges, i );
         ATmatch( t, "[<str>,<str>]", &s1, &s2 );

         /* if the '-l' option was not specified, we strip of the path and
          * extension of both file names of the edge, and we create a new
          * node [id(p1), id(p2)].
          */  
         if( long_listing == ATfalse )
            edges = ATreplace( edges, 
               ATmake( "[<term>,<term>]", ATmake( "id(<str>)", basename(basename( s1 ) )),
                                         ATmake( "id(<str>)", basename(basename( s2 ) ) ) ), i );
         else
         /* Otherwise (In case the '-l' option was specified, we just create
          * a new node [id(p1), id(p2)].
          */
            edges = ATreplace( edges, 
               ATmake( "[id(<str>),id(<str>)]", s1, s2 ), i );
         
      }
      
      /* Then we create the final graph term and write it to standard output */
      ATfprintf( stdout, "%t\n", 
         ATmake( "graph(nodes(<term>),edges(<term>))", nodes, edges ) );
   } 
   else /* options & Graph */
   {
      /* traverse list of modules. Depending on value of long_listing we have
       * to remove location and extension from file names */
      while( ATisEmpty( imports ) == ATfalse )
      {
         ATmatch( ATgetFirst( imports ), "<str>", &s );

         /* long_listing: print full path name */
         if( long_listing == ATtrue )
            printf( "%s\n", s );
         else
            printf( "%s\n", basename(basename( s )) );
         imports = ATgetNext( imports );
      }
   }
   /* ... and terminate */
   exit( 0 );
}
