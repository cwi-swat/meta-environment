/*
 * %% $Id$
 *
 * The interface to the public SGLR functions
 */

#include  <aterm1.h>

/*
    Externally available functions
 */

ATerm SGparseFileUsingTable(char *prg, char *tbl, char *sort, char *in, char *out);

ATerm SGopenLanguage(char *prgname, int conn, char *L, char *FN);
FILE *SGopenFile(char *prgname, char *std_error, char *FN);
void  SGcloseFile(FILE *fd);

ATerm SGparseFile(char *prgname, int conn, char *L, char *G, char *FN);
ATerm SGparseString(int conn, char *L, char *G, char *S);

enum SG_NrAmbKind {SG_NRAMB_ASK, SG_NRAMB_ZERO, SG_NRAMB_INC, SG_NRAMB_DEC};

int  SGnrAmb(int mode);

ATerm SGtermToFile(char *prgname, ATerm t, char *FN);
void  SGtreeToDotFile(char *prg, char *fnam, ATerm t, ATbool suppress);

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
/*
#define SG_VERBOSEFLAG    (                 1   )
#define SG_DEBUGFLAG      (SG_VERBOSEFLAG   << 1)
#define SG_SHOWSTATFLAG   (SG_DEBUGFLAG     << 1)

#define SG_OUTPUTFLAG     (SG_SHOWSTATFLAG  << 1)
#define SG_ASFIX1FLAG     (SG_OUTPUTFLAG    << 1)
#define SG_BINARYFLAG     (SG_ASFIX1FLAG    << 1)

#define SG_DOTOUTFLAG     (SG_BINARYFLAG    << 1)
#define SG_NOLEXFLAG      (SG_DOTOUTFLAG    << 1)
#define SG_SHOWSTACKFLAG  (SG_NOLEXFLAG     << 1)
*/

enum SGmodeFlags {
  SG_VERBOSEFLAG, SG_DEBUGFLAG, SG_SHOWSTATFLAG, SG_OUTPUTFLAG,
  SG_ASFIX1FLAG, SG_BINARYFLAG, SG_DOTOUTFLAG, SG_NOLEXFLAG,
  SG_SHOWSTACKFLAG, SG_GCFLAG
};

#define SG_VERBOSE         (SG_Mode  &   (1 << SG_VERBOSEFLAG))
#define SG_VERBOSE_ON()    (SG_Mode |=   (1 << SG_VERBOSEFLAG))
#define SG_VERBOSE_OFF()   (SG_Mode &=  ~(1 << SG_VERBOSEFLAG))
#define SG_DEBUG           (SG_Mode  &   (1 << SG_DEBUGFLAG))
#define SG_DEBUG_ON()      (SG_Mode |=   (1 << SG_DEBUGFLAG))
#define SG_DEBUG_OFF()     (SG_Mode &=  ~(1 << SG_DEBUGFLAG))
#define SG_SHOWSTAT        (SG_Mode  &   (1 << SG_SHOWSTATFLAG))
#define SG_SHOWSTAT_ON()   (SG_Mode |=   (1 << SG_SHOWSTATFLAG))
#define SG_SHOWSTAT_OFF()  (SG_Mode &=  ~(1 << SG_SHOWSTATFLAG))

#define SG_OUTPUT          (SG_Mode  &   (1 << SG_OUTPUTFLAG))
#define SG_OUTPUT_ON()     (SG_Mode |=   (1 << SG_OUTPUTFLAG))
#define SG_OUTPUT_OFF()    (SG_Mode &=  ~(1 << SG_OUTPUTFLAG))
#define SG_ASFIX1          (SG_Mode  &   (1 << SG_ASFIX1FLAG))
#define SG_ASFIX1_ON()     (SG_Mode |=   (1 << SG_ASFIX1FLAG))
#define SG_ASFIX1_OFF()    (SG_Mode &=  ~(1 << SG_ASFIX1FLAG))
#define SG_BINARY          (SG_Mode  &   (1 << SG_BINARYFLAG))
#define SG_BINARY_ON()     (SG_Mode |=   (1 << SG_BINARYFLAG))
#define SG_BINARY_OFF()    (SG_Mode &=  ~(1 << SG_BINARYFLAG))

#define SG_DOTOUT          (SG_Mode  &   (1 << SG_DOTOUTFLAG))
#define SG_DOTOUT_ON()     (SG_Mode |=   (1 << SG_DOTOUTFLAG))
#define SG_DOTOUT_OFF()    (SG_Mode &=  ~(1 << SG_DOTOUTFLAG))
#define SG_NOLEX           (SG_Mode  &   (1 << SG_NOLEXFLAG))
#define SG_NOLEX_ON()      (SG_Mode |=   (1 << SG_NOLEXFLAG))
#define SG_NOLEX_OFF()     (SG_Mode &=  ~(1 << SG_NOLEXFLAG))
#define SG_SHOWSTACK       (SG_Mode  &   (1 << SG_SHOWSTACKFLAG))
#define SG_SHOWSTACK_ON()  (SG_Mode |=   (1 << SG_SHOWSTACKFLAG))
#define SG_SHOWSTACK_OFF() (SG_Mode &=  ~(1 << SG_SHOWSTACKFLAG))

#define SG_GC              (SG_Mode  &   (1 << SG_GCFLAG))
#define SG_GC_ON()         (SG_Mode |=   (1 << SG_GCFLAG))
#define SG_GC_OFF()        (SG_Mode &=  ~(1 << SG_GCFLAG))
