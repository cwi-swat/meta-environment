/*
 * $Id$
 * (C) 1999, Merijn de jonge (mdejonge@wins.uva.nl)
 *
 * meta-paths: Locate files using search path defined in meta.conf-paths file
 *
 * usage: meta-paths <meta.conf-paths-file> <file>
 *
 *    <meta.conf-paths-file> File which defines search path.
 *    <file>           Name of file to search for.
 *
 */
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "meta-utils.h"

#define USAGE_MSG \
   "\n"\
   "meta-paths: (C) 1999, Merijn de jonge (mdejonge@wins.uva.nl)\n"\
   "\n"\
   "   Locate files using search path defined in meta.conf-paths file\n"\
   "\n"\
   "usage:\n"\
   "   meta-paths <meta.conf-paths-file> <file>\n"\
   "\n"\
   "      <meta.conf-paths-file> File which defines search path. \n"\
   "      <file>           Name of file to search for.\n"\


#define FAIL1(x,y) fprintf(stderr,   \
	"%s(%d): %s(%s): %s\n", __FILE__, __LINE__, x, y, strerror( errno ) )

#define DB {fprintf(stderr,"%s-%d\n", __FILE__, __LINE__);}

static char myversion[] = "0.1";

static void usage()
{
  fprintf(stderr, USAGE_MSG);
  exit(0);
}

static void version(const char *prg)
{
    fprintf(stderr, "%s v%s\n", prg, myversion);
    exit(1);
}

int main(int argc, char* argv[])
{
   int i;
   char* p;
   char* meta_paths_file;
   char* file;
   meta_paths mp;

   for (i=1; i<argc; i++) {
       if (strcmp(argv[i], "-h") == 0 ||
	   strcmp(argv[i], "--help") == 0) {
	   usage();
       } else if (strcmp(argv[i], "-V") == 0 ||
	   strcmp(argv[i], "--version") == 0) {
	   version(argv[0]);
       }
   }

   if( argc != 3 )
   {
      usage();
      return 1;
   }

   meta_paths_file = argv[1];
   file           = argv[2];

   if( metaPathsOpen( &mp, meta_paths_file ) == - 1)
   {
      FAIL1( "metaPathsOpen", meta_paths_file );
      return 1;
   }

   p = metaPathsLocate( &mp, file );
   if( p == NULL )
   {
      FAIL1( "metaPathsLocate",  file );
      metaPathsClose( &mp );
      return 1;
   }

   /* File found, print full path */
   printf( "%s\n", p );

   /* Clean up allocated space */
   metaPathsClose( &mp );

   return 0;
}
