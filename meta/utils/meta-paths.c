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
	   exit( 0 );
       } else if (strcmp(argv[i], "-V") == 0 ||
	   strcmp(argv[i], "--version") == 0) {
	   version(argv[0]);
	   exit( 0 );
       }
   }

   if( argc != 3 )
   {
      usage();
      exit( 1 );
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
