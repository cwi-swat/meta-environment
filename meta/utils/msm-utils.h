/*  
 * $Id$
 * (C) 1999, Merijn de jonge (mdejonge@wins.uva.nl)
 * 
 * msm-paths: Locate files using search path defined in msm-paths file
 * 
 */
#ifndef _msm_paths_h
#define _msm_paths_h

/* Hard limit of number of entries allowed in msm_paths file */
#define MAX_MSM_PATHS_ENTRIES 100
 
/* structure to store information of msm-paths file.
 * msm_entries contain the paths defined in the msm-entries file
 * nr_entries corresponds to the number of non-empty paths defined in
 * the msm-entries file.
 */
typedef struct  {
   char* msm_entries[MAX_MSM_PATHS_ENTRIES];
   int   nr_entries;
} msm_paths;

/* function to open msm=paths file */
int   msmPathsOpen( msm_paths*, char* path );

/* close an msm-paths file */
void  msmPathsClose( msm_paths* );

/* locate a file relative to teh paths defined in a msm-paths file */
char* msmPathsLocate( msm_paths*, char* path );

#endif
