/*  
 * $Id$
 * (C) 1999, Merijn de jonge (mdejonge@wins.uva.nl)
 * 
 */
#ifndef _meta_utils_h
#define _meta_utils_h

/* Hard limit of number of entries allowed in meta.conf_paths file */
#define MAX_META_PATHS_ENTRIES 100
 
/* structure to store information of meta.conf-paths file.
 * meta_entries contain the paths defined in the meta-entries file
 * nr_entries corresponds to the number of non-empty paths defined in
 * the meta-entries file.
 */
typedef struct  {
   char* meta_entries[MAX_META_PATHS_ENTRIES];
   int   nr_entries;
} meta_paths;

/* function to open meta.conf-paths file */
int   metaPathsOpen( meta_paths*, char* path );

/* close an meta.conf-paths file */
void  metaPathsClose( meta_paths* );

/* locate a file relative to the paths defined in a meta.conf-paths file */
char* metaPathsLocate( meta_paths*, char* path );

#endif
