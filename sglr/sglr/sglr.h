/*
 * %% $Id$
 *
 * The interface to the public SGLR functions
 */

#ifndef _SGLR_H_
#define _SGLR_H_  1

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

enum SG_SORTOPS { SG_SET, SG_GET };
char *SGsort(int Mode, ATerm t);

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

enum SGmodeFlags {
  SG_VERBOSEFLAG, SG_ABBREVFLAG, SG_DEBUGFLAG, SG_SHOWSTATFLAG,
  SG_OUTPUTFLAG, SG_ASFIX1FLAG, SG_BINARYFLAG, SG_DOTOUTFLAG,
  SG_NOLEXFLAG, SG_SHOWSTACKFLAG, SG_FILTERFLAG, SG_STARTSYMBOLFLAG,
  SG_GCFLAG
};

#define SG_BIT(i)          (1 << i)

#define SG_VERBOSE         (SG_Mode  &  SG_BIT(SG_VERBOSEFLAG))
#define SG_VERBOSE_ON()    (SG_Mode |=  SG_BIT(SG_VERBOSEFLAG))
#define SG_VERBOSE_OFF()   (SG_Mode &= ~SG_BIT(SG_VERBOSEFLAG))
#define SG_ABBREV          (SG_Mode  &  SG_BIT(SG_ABBREVFLAG))
#define SG_ABBREV_ON()     (SG_Mode |=  SG_BIT(SG_ABBREVFLAG))
#define SG_ABBREV_OFF()    (SG_Mode &= ~SG_BIT(SG_ABBREVFLAG))
#define SG_DEBUG           (SG_Mode  &  SG_BIT(SG_DEBUGFLAG))
#define SG_DEBUG_ON()      (SG_Mode |=  SG_BIT(SG_DEBUGFLAG))
#define SG_DEBUG_OFF()     (SG_Mode &= ~SG_BIT(SG_DEBUGFLAG))
#define SG_SHOWSTAT        (SG_Mode  &  SG_BIT(SG_SHOWSTATFLAG))
#define SG_SHOWSTAT_ON()   (SG_Mode |=  SG_BIT(SG_SHOWSTATFLAG))
#define SG_SHOWSTAT_OFF()  (SG_Mode &= ~SG_BIT(SG_SHOWSTATFLAG))

#define SG_OUTPUT          (SG_Mode  &  SG_BIT(SG_OUTPUTFLAG))
#define SG_OUTPUT_ON()     (SG_Mode |=  SG_BIT(SG_OUTPUTFLAG))
#define SG_OUTPUT_OFF()    (SG_Mode &= ~SG_BIT(SG_OUTPUTFLAG))
#define SG_ASFIX1          (SG_Mode  &  SG_BIT(SG_ASFIX1FLAG))
#define SG_ASFIX1_ON()     (SG_Mode |=  SG_BIT(SG_ASFIX1FLAG))
#define SG_ASFIX1_OFF()    (SG_Mode &= ~SG_BIT(SG_ASFIX1FLAG))
#define SG_BINARY          (SG_Mode  &  SG_BIT(SG_BINARYFLAG))
#define SG_BINARY_ON()     (SG_Mode |=  SG_BIT(SG_BINARYFLAG))
#define SG_BINARY_OFF()    (SG_Mode &= ~SG_BIT(SG_BINARYFLAG))

#define SG_DOTOUT          (SG_Mode  &  SG_BIT(SG_DOTOUTFLAG))
#define SG_DOTOUT_ON()     (SG_Mode |=  SG_BIT(SG_DOTOUTFLAG))
#define SG_DOTOUT_OFF()    (SG_Mode &= ~SG_BIT(SG_DOTOUTFLAG))
#define SG_NOLEX           (SG_Mode  &  SG_BIT(SG_NOLEXFLAG))
#define SG_NOLEX_ON()      (SG_Mode |=  SG_BIT(SG_NOLEXFLAG))
#define SG_NOLEX_OFF()     (SG_Mode &= ~SG_BIT(SG_NOLEXFLAG))
#define SG_SHOWSTACK       (SG_Mode  &  SG_BIT(SG_SHOWSTACKFLAG))
#define SG_SHOWSTACK_ON()  (SG_Mode |=  SG_BIT(SG_SHOWSTACKFLAG))
#define SG_SHOWSTACK_OFF() (SG_Mode &= ~SG_BIT(SG_SHOWSTACKFLAG))

#define SG_FILTER          (SG_Mode  &  SG_BIT(SG_FILTERFLAG))
#define SG_FILTER_ON()     (SG_Mode |=  SG_BIT(SG_FILTERFLAG))
#define SG_FILTER_OFF()    (SG_Mode &= ~SG_BIT(SG_FILTERFLAG))

#define SG_STARTSYMBOL       (SG_Mode  &  SG_BIT(SG_STARTSYMBOLFLAG))
#define SG_STARTSYMBOL_ON()  (SG_Mode |=  SG_BIT(SG_STARTSYMBOLFLAG))
#define SG_STARTSYMBOL_OFF() (SG_Mode &= ~SG_BIT(SG_STARTSYMBOLFLAG))

#define SG_GC              (SG_Mode  &  SG_BIT(SG_GCFLAG))
#define SG_GC_ON()         (SG_Mode |=  SG_BIT(SG_GCFLAG))
#define SG_GC_OFF()        (SG_Mode &= ~SG_BIT(SG_GCFLAG))

#endif  /* _SGLR_H_ */
