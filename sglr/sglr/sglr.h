/*
 * %% $Id$
 *
 * The interface to the public SGLR functions
 */

#include  <aterm1.h>

/*
    Externally available functions
 */

ATerm SGparseFileUsingTable(char *prg, char *tbl, char *in, char *out);

ATerm SGopenLanguage(char *prgname, int conn, char *L, char *FN);
FILE *SGopenFile(char *prgname, char *std_error, char *FN);

ATerm SGparseFile(char *prgname, int conn, char *L, char *FN);
ATerm SGparseString(int conn, char *L, char *S);

enum SG_NrAmbKind {SG_NRAMB_ASK, SG_NRAMB_ZERO, SG_NRAMB_INC};

int  SGnrAmb(int mode);

ATerm SGtermToFile(char *prgname, ATerm t, char *FN);
void  SGtreeToDotFile(char *prg, char *fnam, ATerm t);

FILE  *SGopenLog(char *program, char *fnam);
FILE  *SGlog(void);
void  SGcloseLog(void);
char  *SG_StackDotOut(char *);


/*
    Controlling global behaviour: verbosity, debugging mode, dot
    output of parse forests/parse stacks, and so on.

    This is done by using access macro's using a global variable.
 */

extern int  SG_Mode;

#define SG_VERBOSEFLAG    (                 1   )
#define SG_DEBUGFLAG      (SG_VERBOSEFLAG   << 1)
#define SG_SHOWSTATFLAG   (SG_DEBUGFLAG     << 1)

#define SG_OUTPUTFLAG     (SG_SHOWSTATFLAG  << 1)
#define SG_ASFIX1FLAG     (SG_OUTPUTFLAG    << 1)
#define SG_BINARYFLAG     (SG_ASFIX1FLAG    << 1)

#define SG_NOLEXFLAG      (SG_BINARYFLAG    << 1)
#define SG_SHOWSTACKFLAG  (SG_NOLEXFLAG     << 1)

#define SG_VERBOSE         (SG_Mode  &   SG_VERBOSEFLAG)
#define SG_VERBOSE_ON()    (SG_Mode |=   SG_VERBOSEFLAG)
#define SG_VERBOSE_OFF()   (SG_Mode &=  !SG_VERBOSEFLAG)
#define SG_DEBUG           (SG_Mode  &   SG_DEBUGFLAG)
#define SG_DEBUG_ON()      (SG_Mode |=   SG_DEBUGFLAG)
#define SG_DEBUG_OFF()     (SG_Mode &=  !SG_DEBUGFLAG)
#define SG_SHOWSTAT        (SG_Mode  &   SG_SHOWSTATFLAG)
#define SG_SHOWSTAT_ON()   (SG_Mode |=   SG_SHOWSTATFLAG)
#define SG_SHOWSTAT_OFF()  (SG_Mode &=  !SG_SHOWSTATFLAG)

#define SG_OUTPUT          (SG_Mode  &   SG_OUTPUTFLAG)
#define SG_OUTPUT_ON()     (SG_Mode |=   SG_OUTPUTFLAG)
#define SG_OUTPUT_OFF()    (SG_Mode &=  !SG_OUTPUTFLAG)
#define SG_ASFIX1          (SG_Mode  &   SG_ASFIX1FLAG)
#define SG_ASFIX1_ON()     (SG_Mode |=   SG_ASFIX1FLAG)
#define SG_ASFIX1_OFF()    (SG_Mode &=  !SG_ASFIX1FLAG)
#define SG_BINARY          (SG_Mode  &   SG_BINARYFLAG)
#define SG_BINARY_ON()     (SG_Mode |=   SG_BINARYFLAG)
#define SG_BINARY_OFF()    (SG_Mode &=  !SG_BINARYFLAG)

#define SG_NOLEX           (SG_Mode  &   SG_NOLEXFLAG)
#define SG_NOLEX_ON()      (SG_Mode |=   SG_NOLEXFLAG)
#define SG_NOLEX_OFF()     (SG_Mode &=  !SG_NOLEXFLAG)
#define SG_SHOWSTACK       (SG_Mode  &   SG_SHOWSTACKFLAG)
#define SG_SHOWSTACK_ON()  (SG_Mode |=   SG_SHOWSTACKFLAG)
#define SG_SHOWSTACK_OFF() (SG_Mode &=  !SG_SHOWSTACKFLAG)
