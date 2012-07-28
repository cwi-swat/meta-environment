/* $Id$ */

#ifndef SGLR_FILES_H
#define SGLR_FILES_H

#include <stdio.h>

FILE  *LOG_OpenLog(const char *prg, const char *fnam);
void LOG_CloseFile(FILE *fd);
char *LOG_ReadFile(const char *prg, 
			 const char *err, 
			 const char *fnam, 
			 size_t *fsize);
FILE *LOG_OpenFile(const char *std_error, const char *FN);
size_t LOG_FileSize(const char *FN);
FILE *LOG_log();

#endif
