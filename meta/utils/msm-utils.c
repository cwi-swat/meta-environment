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
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
     
#include "msm-utils.h"

#define FAIL1(x,y) fprintf(stderr,   \
	"%s(%d): %s(%s): %s\n", __FILE__, __LINE__, x, y, strerror( errno ) )

#define DB {fprintf(stderr,"%s-%d\n", __FILE__, __LINE__);}

static char  buffer[_POSIX_PATH_MAX];

static void msmPathsPrint( msm_paths* mp );

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
 * Open and read msm_paths file "path". Structure mp holds
 * entries of "path" on funtion return.
 * -1 is returned on error
 *  0 is returned on success
 */
int msmPathsOpen( msm_paths* mp, char* path )
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

   /* read and parse msm-paths file. */
   while( 1 )
   {
      /* read a line of input */
      if( fgets( buffer, _POSIX_PATH_MAX, f ) == NULL )
         break;
      ptr1 = buffer;

      /* skip initial layout */
      while( isspace( *ptr1 ) )
	         ptr1++;
      ptr2 = buffer + strlen( buffer ) - 1;

      /* skip trailing layout */
      while( isspace( *ptr2 ) && ptr2 > ptr1 )
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
            mp->msm_entries[mp->nr_entries++] = strdup( tmp );
         }
         else
         if( strncmp( ptr1, "../", 3 ) == 0 )
         {
            sprintf( tmp, "%s%s", dn, ptr1 );
            mp->msm_entries[mp->nr_entries++] = strdup( tmp );
         }
         else
         {
            mp->msm_entries[mp->nr_entries++] = strdup( ptr1 );
         }
      }
   }
   
   fclose( f );
   return 0;
}

/*
 * Free allocated memory used to store entries of msm_paths file 
 */
void msmPathsClose( msm_paths* mp )
{
   int i;
   for( i = 0; i < mp->nr_entries; i++ )
      free( mp->msm_entries[i] );
   mp->nr_entries = 0;
}

/*
 * Print entries in msm_paths. For debugging purposes only
 */
static void msmPathsPrint( msm_paths* mp )
{
   int i;
   for( i=0;i< mp->nr_entries ; i++ )
   {
      printf( "%d \"%s\"\n", i, mp->msm_entries[i] );
   }   
}

/*
 * Locate a file/dir using entries in msm_paths file
 * NULL is returned when file/dir could not be located
 * otherwise the full path is returned
 */
char* msmPathsLocate( msm_paths* mp, char* path )
{
   int i;
   struct stat stat_buf;
   
   for( i = 0; i < mp->nr_entries; i++ )
   {
      /* note that mp->msm_entries[i] already contaisn '/' as last
       * character.  Hence, there is no need to use '/' here to separate
       * mp->msm_entries[i] and path.
       */
      sprintf( buffer, "%s%s", mp->msm_entries[i], path );
      if( stat( buffer, &stat_buf ) == 0 )
         return buffer;
   }
   return NULL;
}

