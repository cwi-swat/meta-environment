#include <stdio.h>
#include <unistd.h>  

/*{{{ statistic operations */

#define PT_COND_STRING(s)   (s?s:"") 

extern ATbool statisticsMode;

#define IF_PGEN_STATISTICS(s)     if(statisticsMode) {s;}
double PT_Timer(void);

FILE *PT_OpenLog(char *program, char *fnam);
FILE *PT_log(void);
void  PTcloseLog(void);   

/*}}}  */  
