/*

    SGLR - the Scannerless Generalized LR parser.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, The Netherlands.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/
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


#include <AsFix.h>
#include <aterm1.h>
#include <aterm2.h>


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

typedef ATerm language;

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

void  SGinitParser(ATbool toolbus_mode);
void  SGshowMode(void);

ATerm SGopenLanguageFromTerm(char *prgname, language L, ATerm tbl);
ATerm SGopenLanguage(char *prgname, language L, char *FN);
ATerm SGreOpenLanguage(char *prgname, language L, char *FN);
ATerm SGcloseLanguage(char *prgname, language L);
ATerm SGgetTopSymbols(language L);

ATerm SGparseString(language L, char *G, char *S);
ATerm SGparseStringAsAsFix2(language L, char *G, char *S);
ATerm SGparseStringAsAsFix1(language L, char *G, char *S);

ATerm SGparseFile(char *prgname, language L, char *G, char *FN);
ATerm SGtermToFile(char *prgname, ATerm t, char *FN);
ATerm SGparseFileUsingTable(char *prg, char *tbl, char *sort,
                            char *in, char *out);

ATbool SGisParseTree(ATerm t);
ATbool SGisParseError(ATerm t);


enum  SG_NrMode {SG_NR_ASK, SG_NR_ZERO, SG_NR_INC, SG_NR_DEC};
int   SGnrAmb(int Mode);

enum  SG_SORTOPS { SG_SET, SG_UNSET, SG_GET };
char *SGsort(int Mode, forest t);

FILE *SG_OpenFile(char *prgname, char *std_error, char *FN);
void  SG_CloseFile(FILE *fd);

void SG_PrintToken(FILE *out, token c);
FILE *SG_OpenLog(char *program, char *fnam);
FILE *SG_log(void);
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

extern int  _SG_Mode;

enum SGmodeFlags {
  SG_TOOLBUSFLAG, SG_ERRORFLAG, SG_VERBOSEFLAG, SG_DEBUGFLAG,
  SG_SHOWSTATFLAG, SG_OUTPUTFLAG, SG_ASFIX1FLAG, SG_BINARYFLAG,
  SG_DOTOUTFLAG, SG_NOLEXFLAG, SG_SHOWSTACKFLAG, SG_FILTERFLAG,
  SG_STARTSYMBOLFLAG, SG_GCFLAG, SG_CYCLEFLAG, SG_POSINFOFLAG
};

#define SG_BIT(i)            (1 << i)

#define SG_TOOLBUS           (_SG_Mode  &  SG_BIT(SG_TOOLBUSFLAG))
#define SG_TOOLBUS_ON()      (_SG_Mode |=  SG_BIT(SG_TOOLBUSFLAG))
#define SG_TOOLBUS_OFF()     (_SG_Mode &= ~SG_BIT(SG_TOOLBUSFLAG))
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
#define SG_ASFIX2            !(SG_ASFIX1)
#define SG_ASFIX2_ON()       SG_ASFIX1_OFF()
#define SG_ASFIX2_OFF()      SG_ASFIX1_ON()

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
       SG_Amb_Node_AFun, SG_Position_AFun, SG_Productions_AFun,
       SG_Amb_Error_AFun, SG_SndValue_AFun, SG_ParseTree_AFun,
       SG_Appl_AFun, SG_Term_AFun, SG_ParseTreeAF1_AFun,
       SG_ParseError_AFun, SG_Character_AFun, SG_Line_AFun, SG_Col_AFun,
       SG_Offset_AFun;

#endif  /* _SGLR_H_ */
