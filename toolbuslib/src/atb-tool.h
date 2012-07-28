#ifndef ATB_TOOL_H
#define ATB_TOOL_H

#include <string.h>
#include <aterm1.h>

/* ToolBus callback functions */
typedef ATerm (*ATBhandler)(int file_desc, ATerm input_term);

/* ToolBus tool functions */
int    ATBinitialize(int argc, char *argv[]);
int    ATBinit(int argc, char *argv[], ATerm *stack_bottom);
int    ATBconnect(char *toolname, char *host, int port, ATBhandler h);
void   ATBdisconnect(int file_desc);
int    ATBeventloop(void);

ATerm  ATBpack(ATerm t);
ATerm  ATBunpack(ATerm t);

typedef struct _OperationTermPair
{
	int operation;
	ATerm term;
} *OperationTermPair;

void   ATBpostEvent(int file_desc, ATerm event);
ATerm  ATBpostRequest(int file_desc, ATerm request);

ATbool ATBpeekOne(int file_desc);
int    ATBpeekAny(void);
int    ATBhandleOne(int file_desc);
int    ATBhandleAny(void);

ATbool ATBisValidConnection(int cid);
int    ATBgetPort(int cid);
char  *ATBgetHost(int cid);

/* Generic signature checker */
ATerm ATBcheckSignature(ATerm signature, char *sigs[], int nrsigs);

#ifndef streq
#  define streq(s,t)	(!(strcmp(s,t)))
#endif

#endif /* ATB_TOOL_H */
