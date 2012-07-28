#ifndef ERRORMANAGER_H
#define ERRORMANAGER_H

/* This file provides convenience error management functionality
 * for C tools that produces error messages.
 */
void ERR_initErrorManager(const char *producer, const char *jobId);
void ERR_cleanupErrorManager();
void ERR_resetErrorManager();
ERR_Summary ERR_getManagerSummary();
int ERR_getManagerCount();

/* Convenience methods for creating and storing errors in one call */
void ERR_managerStoreError(const char *description, ERR_SubjectList subjects);
void ERR_managerStoreWarning(const char *description, ERR_SubjectList subjects);
void ERR_managerStoreInfo(const char *description, ERR_SubjectList subjects);
void ERR_managerStoreFatal(const char *description, ERR_SubjectList subjects);
void ERR_managerStoreLocatedFatal(const char *description, const char *subject, const char *path, int startLine, int startColumn, int endLind, int endColumn, int offset, int length);
void ERR_managerStoreLocatedInfo(const char *description, const char *subject, const char *path, int startLine, int startColumn, int endLind, int endColumn, int offset, int length);
void ERR_managerStoreLocatedError(const char *description, const char *subject, const char *path, int startLine, int startColumn, int endLind, int endColumn, int offset, int length);
void ERR_managerStoreLocatedWarning(const char *description, const char *subject, const char *path, int startLine, int startColumn, int endLind, int endColumn, int offset, int length);

#endif
