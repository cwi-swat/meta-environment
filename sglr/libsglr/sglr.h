/*  $Id$  */

/*
 * The interface to the public SGLR functions
 */

#ifndef _SGLR_H_
#define _SGLR_H_  1

#if defined(DEBUG) && !defined(MEMSTAT)
  #define MEMSTATS
  void SG_Dump_ATtable(ATermTable t, char *s);
#endif

#include  <aterm1.h>


/*  Data structures: states, actions, character ranges and parse tables  */

typedef short            state;
typedef short            label;
typedef unsigned short   token;

typedef ATerm     action;
typedef ATermList lookahead;
typedef ATermList actions;
typedef ATermAppl production;

typedef ATermAppl tree;
typedef ATermAppl forest;

/*
    Needed all the time...
 */

#define SG_MAX(a,b)     (a>b?a:b)
/*
    When interfacing, some data type conversion may be necessary.
    Some macros implement the necessary abstraction.
 */

#define SG_GETSTATE(s)  (s)
#define SG_SETSTATE(s)  (s)
#define SG_GETTOKEN(t)  (t)
#define SG_MAKETOKEN(c) (c)
#define SG_GETLABEL(l)  (l)
#define SG_SETLABEL(l)  (l)

/*
    Char class max defines where PT production numbering starts,
    in other words, it reflects a reserved character range...
 */

#define SG_CHAR_CLASS_BOT 0                     /*  Lowest ordinary char  */
#define SG_CHAR_CLASS_TOP 255                   /*  Highest ordinary char */
#define SG_EOF            (SG_CHAR_CLASS_TOP+1) /*  The EOF char          */
#define SG_CHAR_CLASS_EOF (SG_CHAR_CLASS_TOP+1) /*  .. extended with EOF  */
#define SG_PROD_START     (SG_CHAR_CLASS_EOF+1) /*  Start of prods  */

/*
    Function prototypes
 */

ATerm SGparseFileUsingTable(char *prg, char *tbl, char *sort,
                            char *in, char *out);
ATerm SGopenLanguage(char *prgname, int conn, char *L, char *FN);
ATerm SGcloseLanguage(char *prgname, int conn, char *L);
ATerm SGreOpenLanguage(char *prgname, int conn, char *L, char *FN);

FILE *SGopenFile(char *prgname, char *std_error, char *FN);
void  SGcloseFile(FILE *fd);

ATerm SGparseFile(char *prgname, int conn, char *L, char *G, char *FN);
ATerm SGparseString(int conn, char *L, char *G, char *S);
ATerm SGparseStringAsAsFix2(int conn, char *L, char *G, char *S);
ATerm SGparseStringAsAsFix1(int conn, char *L, char *G, char *S);

ATbool SGisParseTree(ATerm t);
ATbool SGisParseError(ATerm t);

enum  SG_NrMode {SG_NR_ASK, SG_NR_ZERO, SG_NR_INC, SG_NR_DEC};
int   SGnrAmb(int Mode);

enum  SG_SORTOPS { SG_SET, SG_UNSET, SG_GET };
char *SGsort(int Mode, forest t);

ATerm SGtermToFile(char *prgname, ATerm t, char *FN);

void SG_PrintToken(FILE *out, token c);
FILE *SGopenLog(char *program, char *fnam);
FILE *SGlog(void);
void  SGcloseLog(void);

void SG_ReportErrLine(int line, int col);
int  SG_GetChar(void);
void SG_UnGetChar(void);
char *SG_StackDotOut(char *);

/*
    Controlling global behaviour: verbosity, debugging mode, dot
    output of parse forests/parse stacks, and so on.

    This is done by using access macro's on a global variable.
 */

void  SGinitParser(void);
extern int  _SG_Mode;

enum SGmodeFlags {
  SG_ERRORFLAG, SG_VERBOSEFLAG, SG_DEBUGFLAG, SG_SHOWSTATFLAG,
  SG_OUTPUTFLAG, SG_ASFIX1FLAG, SG_BINARYFLAG, SG_DOTOUTFLAG,
  SG_NOLEXFLAG, SG_SHOWSTACKFLAG, SG_FILTERFLAG, SG_STARTSYMBOLFLAG,
  SG_GCFLAG, SG_CYCLEFLAG, SG_POSINFOFLAG
};

#define SG_BIT(i)            (1 << i)

#define SG_ERROR             (_SG_Mode  &  SG_BIT(SG_ERRORFLAG))
#define SG_ERROR_ON()        (_SG_Mode |=  SG_BIT(SG_ERRORFLAG))
#define SG_ERROR_OFF()       (_SG_Mode &= ~SG_BIT(SG_ERRORFLAG))
#define SG_VERBOSE           (_SG_Mode  &  SG_BIT(SG_VERBOSEFLAG))
#define SG_VERBOSE_ON()      (_SG_Mode |=  SG_BIT(SG_VERBOSEFLAG))
#define SG_VERBOSE_OFF()     (_SG_Mode &= ~SG_BIT(SG_VERBOSEFLAG))
#define SG_DEBUG             (_SG_Mode  &  SG_BIT(SG_DEBUGFLAG))
#define SG_DEBUG_ON()        (_SG_Mode |=  SG_BIT(SG_DEBUGFLAG))
#define SG_DEBUG_OFF()       (_SG_Mode &= ~SG_BIT(SG_DEBUGFLAG))
#define SG_SHOWSTAT          (_SG_Mode  &  SG_BIT(SG_SHOWSTATFLAG))
#define SG_SHOWSTAT_ON()     (_SG_Mode |=  SG_BIT(SG_SHOWSTATFLAG))
#define SG_SHOWSTAT_OFF()    (_SG_Mode &= ~SG_BIT(SG_SHOWSTATFLAG))

#define SG_OUTPUT            (_SG_Mode  &  SG_BIT(SG_OUTPUTFLAG))
#define SG_OUTPUT_ON()       (_SG_Mode |=  SG_BIT(SG_OUTPUTFLAG))
#define SG_OUTPUT_OFF()      (_SG_Mode &= ~SG_BIT(SG_OUTPUTFLAG))
#define SG_ASFIX1            (_SG_Mode  &  SG_BIT(SG_ASFIX1FLAG))
#define SG_ASFIX1_ON()       (_SG_Mode |=  SG_BIT(SG_ASFIX1FLAG))
#define SG_ASFIX1_OFF()      (_SG_Mode &= ~SG_BIT(SG_ASFIX1FLAG))
#define SG_BINARY            (_SG_Mode  &  SG_BIT(SG_BINARYFLAG))
#define SG_BINARY_ON()       (_SG_Mode |=  SG_BIT(SG_BINARYFLAG))
#define SG_BINARY_OFF()      (_SG_Mode &= ~SG_BIT(SG_BINARYFLAG))

#define SG_DOTOUT            (_SG_Mode  &  SG_BIT(SG_DOTOUTFLAG))
#define SG_DOTOUT_ON()       (_SG_Mode |=  SG_BIT(SG_DOTOUTFLAG))
#define SG_DOTOUT_OFF()      (_SG_Mode &= ~SG_BIT(SG_DOTOUTFLAG))
#define SG_NOLEX             (_SG_Mode  &  SG_BIT(SG_NOLEXFLAG))
#define SG_NOLEX_ON()        (_SG_Mode |=  SG_BIT(SG_NOLEXFLAG))
#define SG_NOLEX_OFF()       (_SG_Mode &= ~SG_BIT(SG_NOLEXFLAG))
#define SG_SHOWSTACK         (_SG_Mode  &  SG_BIT(SG_SHOWSTACKFLAG))
#define SG_SHOWSTACK_ON()    (_SG_Mode |=  SG_BIT(SG_SHOWSTACKFLAG))
#define SG_SHOWSTACK_OFF()   (_SG_Mode &= ~SG_BIT(SG_SHOWSTACKFLAG))

#define SG_FILTER            (_SG_Mode  &  SG_BIT(SG_FILTERFLAG))
#define SG_FILTER_ON()       (_SG_Mode |=  SG_BIT(SG_FILTERFLAG))
#define SG_FILTER_OFF()      (_SG_Mode &= ~SG_BIT(SG_FILTERFLAG))

#define SG_STARTSYMBOL       (_SG_Mode  &  SG_BIT(SG_STARTSYMBOLFLAG))
#define SG_STARTSYMBOL_ON()  (_SG_Mode |=  SG_BIT(SG_STARTSYMBOLFLAG))
#define SG_STARTSYMBOL_OFF() (_SG_Mode &= ~SG_BIT(SG_STARTSYMBOLFLAG))

#define SG_CYCLE             (_SG_Mode  &  SG_BIT(SG_CYCLEFLAG))
#define SG_CYCLE_ON()        (_SG_Mode |=  SG_BIT(SG_CYCLEFLAG))
#define SG_CYCLE_OFF()       (_SG_Mode &= ~SG_BIT(SG_CYCLEFLAG))

#define SG_POSINFO           (_SG_Mode  &  SG_BIT(SG_POSINFOFLAG))
#define SG_POSINFO_ON()      (_SG_Mode |=  SG_BIT(SG_POSINFOFLAG))
#define SG_POSINFO_OFF()     (_SG_Mode &= ~SG_BIT(SG_POSINFOFLAG))

#if !defined(HAVE_BOEHMGC)
  #define SG_GC              (_SG_Mode  &  SG_BIT(SG_GCFLAG))
  #define SG_GC_ON()         (_SG_Mode |=  SG_BIT(SG_GCFLAG))
  #define SG_GC_OFF()        (_SG_Mode &= ~SG_BIT(SG_GCFLAG))
#endif


#define SG_STATISTICS        (SG_SHOWSTAT || SG_DEBUG)
#define SG_NEED_OUTPUT       (SG_OUTPUT || SG_DOTOUT)
#define SG_NEED_TOP          (SG_NEED_OUTPUT || SG_STARTSYMBOL)

#define IF_VERBOSE(s)        if(SG_VERBOSE) {s;}
#define IF_DEBUG(s)          if(SG_DEBUG) {s;}
#define IF_STATISTICS(s)     if(SG_STATISTICS) {s;}

/*  A few global AFuns, used by several routines  */
extern AFun SG_EOF_Error_AFun, SG_Plain_Error_AFun, SG_Cycle_Error_AFun,
            SG_Amb_Error_AFun, SG_SndValue_AFun, SG_ParseTree_AFun,
            SG_Appl_AFun, SG_Term_AFun, SG_ParseTreeAF1_AFun,
            SG_ParseError_AFun, SG_Character_AFun, SG_Line_AFun,
            SG_Col_AFun, SG_Offset_AFun;

#endif  /* _SGLR_H_ */
