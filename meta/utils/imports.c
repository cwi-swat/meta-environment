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
 
#include <aterm2.h>
#include <AsFix-fun.h>
#include <AsFix-expand.h>
#include <AsFix-init-patterns.h>
#include <AsFix.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

#ifdef HAVE_GETOPT_H
#include <getopt.h>
#else
#include <unistd.h>
#endif
extern char* optarg;

#include "module-utils.h"

#define USAGE_MSG \
   "\n"\
   "imports: (C) 1999, Merijn de Jonge (mdejonge@wins.uva.nl)\n"\
   "\n"\
   "   generates list of the names on standard output of all modules \n"\
   "   that are imported by an ASF+SDF module.\n"\
   "\n"\
   "usage:\n"\
   "   imports [-option] msm-paths-file module\n"\
   "\n"\
   "      msm-paths-file file containing search paths\n"\
   "      module         AsFix representation of ASF+SDF module\n"\
   "\n"\
   "      options:\n"\
   "         -h  displays this message\n"\
   "         -l  print full paths names of modules\n"\
   "         -r  construct a list of modules recursively\n"\
   "         -s  stop when a module cannotbe found\n"\
   "\n"

/* Command line options used by imports */ 
static char* opt_string = "hlrs";


extern ATbool silent;

#define FAIL(x) fprintf(stderr, "%s(%d): %s: %s\n", \
   __FILE__, __LINE__, x, strerror( errno ) );

#define FAIL1(x,y) fprintf(stderr, "%s(%d): %s(%s): %s\n", \
        __FILE__, __LINE__, x, y, strerror( errno ) );


#define DB {fprintf(stderr, "%s-%d\n", __FILE__, __LINE__ );}

static void usage()
{
   fprintf( stderr, USAGE_MSG );
}

int main( int argc, char* argv[] )
{
   ATerm     bs;
   ATermList imports;
   ATbool    long_listing;
   char*     s;
   char      buffer[_POSIX_PATH_MAX];
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
   AFinit(argc, argv, &bs );

   /* Obtain list of imported modules */
   imports = getImports( argv[optind], argv[optind + 1], options );
   
   /* traverse list of modules. Depending on value of long_listing we have
    * to remove location and extension from file names */
   while( ATisEmpty( imports ) == ATfalse )
   {
      ATmatch( ATgetFirst( imports ), "<str>", &s );

      /* long_listing: print full path name */
      if( long_listing == ATtrue )
         printf( "%s\n", s );
      else
      { /* short listing: remove directory and extension from file name */
         strcpy( buffer, s );
         s = strchr( buffer, '/' );
         if( strrchr( s, '/' ) != NULL )
            strcpy( buffer, s + 1 );
         s = strrchr( buffer, '.' );
         if( s != NULL )
            *s = '\0';
         printf( "%s\n", buffer );
      }
      imports = ATgetNext( imports );
   }

   /* ... and termiate */
   exit( 0 );
}
