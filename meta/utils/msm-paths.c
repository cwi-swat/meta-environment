/*
 * $Id$
 * (C) 1999, Merijn de jonge (mdejonge@wins.uva.nl)
 * 
 * msm-paths: Locate files using search path defined in msm-paths file
 * 
 * usage: msm-paths <msm-paths-file> <file>
 * 
 *    <msm-paths-file> File which defines search path. 
 *    <file>           Name of file to search for.
 *
 */    
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
     
#include "msm-utils.h"

#define USAGE_MSG \
   "\n"\
   "msm-paths: (C) 1999, Merijn de jonge (mdejonge@wins.uva.nl)\n"\
   "\n"\
   "   Locate files using search path defined in msm-paths file\n"\
   "\n"\
   "usage:\n"\
   "   msm-paths <msm-paths-file> <file>\n"\
   "\n"\
   "      <msm-paths-file> File which defines search path. \n"\
   "      <file>           Name of file to search for.\n"\


#define FAIL1(x,y) fprintf(stderr,   \
	"%s(%d): %s(%s): %s\n", __FILE__, __LINE__, x, y, strerror( errno ) )

#define DB {fprintf(stderr,"%s-%d\n", __FILE__, __LINE__);}

static void usage()
{
   fprintf( stderr, USAGE_MSG );
}

void main( int argc, char*argv[])
{
   char* p;
   char* msm_paths_file;
   char* file;
   msm_paths mp;
 
   /* Check command line arguments */
   if( argc == 2 && 
       (strcmp( argv[1], "-h" ) == 0 ||
        strcmp( argv[1], "-help" ) == 0 ) )
   {
      usage();
      exit( 0 );
   }

   if( argc != 3 )
   {
      usage();     
      exit( 1 );
   }
 
   msm_paths_file = argv[1];
   file           = argv[2];
  
   if( msmPathsOpen( &mp, msm_paths_file ) == - 1)
   {
      FAIL1( "msmPathsOpen", msm_paths_file );
      exit( 1 );
   }

   p = msmPathsLocate( &mp, file );
   if( p == NULL )
   {
      fprintf( stderr, "%s not found.\n", file );
      msmPathsClose( &mp );
      exit( 1 );
   }

   /* File found, print full path */
   printf( "%s\n", p );

   /* Clean up allocated space */
   msmPathsClose( &mp );
 
   /* terminate */
   exit( 0 );
}

