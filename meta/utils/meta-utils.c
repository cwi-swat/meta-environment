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
 * meta-paths: Locate files using search path defined in meta-paths file
 *
 * usage: meta-paths <meta.conf-file> <file>
 *
 *    <meta.conf-file> File which defines search path.
 *    <file>           Name of file to search for.
 *
 */
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "meta-utils.h"

#define FAIL1(x,y) fprintf(stderr,   \
	"%s(%d): %s(%s): %s\n", __FILE__, __LINE__, x, y, strerror( errno ) )

#define DB {fprintf(stderr,"%s-%d\n", __FILE__, __LINE__);}

static char  buffer[_POSIX_PATH_MAX];

static void metaPathsPrint( meta_paths* mp );

/*
 * basename = ~[/]*
 * dirname = path - basename
 */
static char* dirname( char* path )
{
   static char dirname_buf[_POSIX_PATH_MAX];
   char* ptr;

   strcpy( dirname_buf, path );

   /* locate last occurence of '/' in strign */
   ptr = strrchr( dirname_buf, '/' );

   /* not found :-> return empty string */
   if( ptr == NULL )
      strcpy( dirname_buf, "" );
   /* otherwise, break strigng after '/' and return strign up
    * to and including '/'
    */
   else
      *(ptr+1) = '\0';
   return dirname_buf;
}

/*
 * Open and read meta.conf_paths file "path". Structure mp holds
 * entries of "path" on funtion return.
 * -1 is returned on error
 *  0 is returned on success
 */
int metaPathsOpen( meta_paths* mp, char* path )
{
   FILE* f;
   char* ptr1;
   char* ptr2;
   char* dn;
   char tmp[_POSIX_PATH_MAX];
   int length;

   /* "." and ".." entries are resolved using basename path */
   dn = dirname( path );

   f = fopen( path, "r");
   if( f == NULL )
   {
      return -1;
   }

   mp->nr_entries = 0;

   /* read and parse meta.conf-paths file. */
   while( 1 )
   {
      /* read a line of input */
      if( fgets( buffer, _POSIX_PATH_MAX, f ) == NULL )
         break;
      ptr1 = buffer;

      /* skip initial layout */
      while( isspace((int) *ptr1 ) )
	         ptr1++;
      ptr2 = buffer + strlen( buffer ) - 1;

      /* skip trailing layout */
      while( isspace((int) *ptr2 ) && ptr2 > ptr1 )
         ptr2--;
      ptr2++;
      *ptr2 = '\0';
      length = strlen( ptr1 );
      if( length > 0 )
      {
         /* make sure last character is '/' */
         if( ptr1[length - 1] != '/' )
            strcat( ptr1, "/" );

         /* "." and ".." entries are resolved using basename path as follows:
          * (note: bn is either empty or its last caharacter is '/')
          *
          * when ptr1 equals ./path, then we construct the path
          *   bn++path
          * when ptr1 equals ../path, then we construct the path
          *   bn++../path
          * otherwise we construct the path
          *   ptr1
          */
         if( strncmp( ptr1, "./", 2 ) == 0 )
         {
            sprintf( tmp, "%s%s", dn, ptr1 + 2 );
            mp->meta_entries[mp->nr_entries++] = strdup( tmp );
         }
         else
         if( strncmp( ptr1, "../", 3 ) == 0 )
         {
            sprintf( tmp, "%s%s", dn, ptr1 );
            mp->meta_entries[mp->nr_entries++] = strdup( tmp );
         }
         else
         {
            mp->meta_entries[mp->nr_entries++] = strdup( ptr1 );
         }
      }
   }

   fclose( f );
   return 0;
}

/*
 * Free allocated memory used to store entries of meta.conf_paths file
 */
void metaPathsClose( meta_paths* mp )
{
   int i;
   for( i = 0; i < mp->nr_entries; i++ )
      free( mp->meta_entries[i] );
   mp->nr_entries = 0;
}

/*
 * Print entries in meta.conf_paths. For debugging purposes only
 */
static void metaPathsPrint( meta_paths* mp )
{
   int i;
   for( i=0;i< mp->nr_entries ; i++ )
   {
      printf( "%d \"%s\"\n", i, mp->meta_entries[i] );
   }
}

/*
 * Locate a file/dir using entries in meta.conf_paths file
 * NULL is returned when file/dir could not be located
 * otherwise the full path is returned
 */
char* metaPathsLocate( meta_paths* mp, char* path )
{
   int i;
   struct stat stat_buf;

   for( i = 0; i < mp->nr_entries; i++ )
   {
      /* note that mp->meta_entries[i] already contaisn '/' as last
       * character.  Hence, there is no need to use '/' here to separate
       * mp->meta_entries[i] and path.
       */
      sprintf( buffer, "%s%s", mp->meta_entries[i], path );
      if( stat( buffer, &stat_buf ) == 0 )
         return buffer;
   }
   return NULL;
}

