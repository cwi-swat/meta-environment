/* $Id$ */

/*
 * For static storage of errors during a computation.
 */

#include <Error.h>
#include <Error-manager.h>
#include <assert.h>

static ERR_Summary store = NULL;

void ERR_resetErrorManager()
{
  const char *producer = ERR_getSummaryProducer(store);
  const char *id = ERR_getSummaryId(store);
  store = ERR_makeSummarySummary(producer, id, ERR_makeErrorListEmpty());
}

void ERR_initErrorManager(const char *producer, const char *jobId)
{
  assert(store == NULL && "first cleanup before initializing again");
  ERR_protectSummary(&store);
  store = ERR_makeSummarySummary(producer, jobId, ERR_makeErrorListEmpty());
}

void ERR_cleanupErrorManager()
{
  store = NULL;
}

ERR_Summary ERR_getManagerSummary()
{
  assert(store != NULL);
  return store;
}

int ERR_getManagerCount()
{
  assert(store != NULL);
  return ERR_getErrorListLength(ERR_getSummaryList(store));
}

static void ERR_managerStoreAnyError(ERR_Error error)
{
  ERR_ErrorList list;

  assert(store != NULL);
  list = ERR_getSummaryList(store);
  list = ERR_makeErrorListMany(error, list);
  store = ERR_setSummaryList(store, list);
}

void ERR_managerStoreError(const char *description, ERR_SubjectList subjects)
{
  ERR_managerStoreAnyError(ERR_makeErrorError(description, subjects));
}

void ERR_managerStoreWarning(const char *description, ERR_SubjectList subjects)
{
  ERR_managerStoreAnyError(ERR_makeErrorWarning(description, subjects));
}

void ERR_managerStoreInfo(const char *description, ERR_SubjectList subjects)
{
  ERR_managerStoreAnyError(ERR_makeErrorInfo(description, subjects));
}

void ERR_managerStoreFatal(const char *description, ERR_SubjectList subjects)
{
  ERR_managerStoreAnyError(ERR_makeErrorFatal(description, subjects));
}

void ERR_managerStoreLocatedError(const char *description,
				const char *subjectDescription,
				const char *path,
				int startLine,
				int startColumn,
				int endLine,
				int endColumn,
				int offset,
				int length)
{
  ERR_Area area = ERR_makeAreaArea(startLine, startColumn, endLine, endColumn,
				   offset, length);
  ERR_Location loc = ERR_makeLocationAreaInFile(path, area);
  ERR_Subject subject = ERR_makeSubjectLocalized(subjectDescription, loc);
  ERR_managerStoreError(description, ERR_makeSubjectListSingle(subject));
}

void ERR_managerStoreLocatedWarning(const char *description,
				const char *subjectDescription,
				const char *path,
				int startLine,
				int startColumn,
				int endLine,
				int endColumn,
				int offset,
				int length)
{
  ERR_Area area = ERR_makeAreaArea(startLine, startColumn, endLine, endColumn,
				   offset, length);
  ERR_Location loc = ERR_makeLocationAreaInFile(path, area);
  ERR_Subject subject = ERR_makeSubjectLocalized(subjectDescription, loc);
  ERR_managerStoreWarning(description, ERR_makeSubjectListSingle(subject));
}

void ERR_managerStoreLocatedInfo(const char *description,
				const char *subjectDescription,
				const char *path,
				int startLine,
				int startColumn,
				int endLine,
				int endColumn,
				int offset,
				int length)
{
  ERR_Area area = ERR_makeAreaArea(startLine, startColumn, endLine, endColumn,
				   offset, length);
  ERR_Location loc = ERR_makeLocationAreaInFile(path, area);
  ERR_Subject subject = ERR_makeSubjectLocalized(subjectDescription, loc);
  ERR_managerStoreInfo(description, ERR_makeSubjectListSingle(subject));
}

void ERR_managerStoreLocatedFatal(const char *description,
				const char *subjectDescription,
				const char *path,
				int startLine,
				int startColumn,
				int endLine,
				int endColumn,
				int offset,
				int length)
{
  ERR_Area area = ERR_makeAreaArea(startLine, startColumn, endLine, endColumn,
				   offset, length);
  ERR_Location loc = ERR_makeLocationAreaInFile(path, area);
  ERR_Subject subject = ERR_makeSubjectLocalized(subjectDescription, loc);
  ERR_managerStoreFatal(description, ERR_makeSubjectListSingle(subject));
}
