/* begin barm.c */
#if defined(SUN4OS4) | defined(IRIS4d) | defined(SOLARIS)
#define FASTMEM
#endif

#ifdef FASTMEM
#include <sys/types.h>
#endif

#include "stdio.h"
#include <string.h>

#ifdef FASTMEM
#include <sys/stat.h>
#include <sys/mman.h>
#endif

#include <errno.h>

#ifdef FASTMEM
#include <signal.h>
#include <malloc.h>
#include <fcntl.h>
#endif

#include <unistd.h>
#include <stdlib.h>

#define SDIST    4        /* distance between function symbols */
#define TOKENIZE 2     /* fsym + TOKENIZE = token(fsym)       */
#define NCHARS   256  /* number of characters                      */
#define FSYMBASE 1    /* make all fsyms n*SDIST+1               */

void error(char *s)
{ fprintf(stderr,s); fprintf(stderr,"\n"); exit(1); }

/* for C++ compilers, fix error in .h files         */
/* getpagesize() is not available on all systems    */
/* if it is not available, define as a macro, e.g.  */
/* #define getpagesize() 4096                       */
#if defined(SUN4OS4) | defined(IRIS4D)
int getpagesize();
#endif
#if defined(SOLARIS)
int getpagesize(){
	return 4096;
}
#endif

/* tables */
struct arity {
  unsigned code;
  char *arity;
};

struct entry {
  char     c;
  union {
    struct arity *arty;
    struct entry *this;
  } value;
  struct entry *other;
};

struct entry *tp = NULL;
struct entry *te;

#define BLOCKSIZE 1024
int gel_line =0;      /* number of lines read */

struct entry *newentry()
{ if (tp && tp < te) return tp++;
  if (tp = (struct entry *)calloc(BLOCKSIZE,sizeof(struct entry))) 
     {te = tp+BLOCKSIZE;return(tp++);};
  error("malloc failed");
}
  
struct arity *lookup(char *s,struct entry *e)
{ if (*s == e->c)
    {if (*s == '\0') 
       {return(e->value.arty);}
     else
       {return(lookup(s+1,e->value.this));};}
  else
    {if (e->other)
       {return(lookup(s,e->other));}
     else
       {fprintf(stderr,"line %ld: ",gel_line);
        error("unknown function or abbreviation");
        return(NULL); /* unreachable statement */
       };};
}

struct entry *insert(char *s,struct entry *e, struct arity *thecode)
{ struct entry *tmp;

  if (e) 
    { if (*s == e->c)
        {if (*s)
           {e->value.this = insert(s+1,e->value.this,thecode);}
         else
           {e->value.arty = thecode;}
        }
      else
        {e->other = insert(s,e->other,thecode);};
      return(e); 
    }
  else
    {tmp = newentry();
     tmp->c = *s;
     if (*s)
       {tmp->value.this = insert(s+1,NULL,thecode);
      }
     else
       {tmp->value.arty = thecode;};
     return(tmp);
   };
}
/* end tables */

#define xTP() TP
#define xMAKExLABEL(n) l##n

typedef unsigned long fsym;
typedef unsigned long *ptr;
struct hdr {
  fsym fsym;
  ptr *sadr;
  long num;
};

ptr *save_MP, *save_AP, *save_HP;
struct hdr *save_HDRS;

#ifdef FASTMEM
#define HP_CHK
#define MP_CHK
#define AP_CHK
#define HDRS_CHK
#else
#define HP_CHK if (!(HP < heap+HEAPSIZE)) error("heap overflow");
#define MP_CHK if (!(MP < mstack+SIZExSTACKS)) error("control stack overflow");
#define AP_CHK if (!(AP > astack)) error("argument stack overflow");
#define HDRS_CHK if (!(HDRS > hdrs)) error("headers overflow");
#endif

#ifdef DEBUG

#define xPUTxHEAP(a) {*(HP++) = (ptr) (a); if (save_HP<HP) save_HP=HP; HP_CHK}
#define xEXPRxPUTxHEAP(a)  {*(HP++) = (ptr) (a); if (save_HP<HP) save_HP=HP; HP_CHK}
#define xFNSHxNODE()  {HDRS->num = HP-(HDRS->sadr);xPUSHA(HDRS--); if (save_HDRS>HDRS) save_HDRS=HDRS; HDRS_CHK}
#define xPUSHM(a)  {*(MP++) = (ptr) (a); if (save_MP<MP) save_MP=MP; MP_CHK}
#define xPUSHA(a)  {*AP = (ptr) (a) ; AP--; if (save_AP>AP) save_AP=AP; AP_CHK}

#else /* DEBUG */

#define xPUTxHEAP(a) {*(HP++) = (ptr) (a); HP_CHK}
#define xEXPRxPUTxHEAP(a)  {*(HP++) = (ptr) (a); HP_CHK}
#define xFNSHxNODE()  {HDRS->num = HP-(HDRS->sadr);xPUSHA(HDRS--); HDRS_CHK} 
#define xPUSHM(a)  {*(MP++) = (ptr) (a); MP_CHK}
#define xPUSHA(a)  {*AP = (ptr) (a) ; AP--; AP_CHK} 

#endif

#define xSTRTxNODE(f) {HDRS->fsym = f; HDRS->sadr = (ptr *) HP;} 
#define xPOPA() ((ptr) *(++AP))
#define xDROPA(n) AP += n;
#define xARG(n) ((ptr) *(AP+n))
#define xSADR(l) (((struct hdr *)l)->sadr)
#define xEADR(l) (xSADR(l) + ((struct hdr *)l)->num)
#define xDTR(s,n) (ptr) *(xSADR(s)+n-1)
#define xGETxHEAP(n) HP-n
#define xPOPM() ((ptr) *(--MP))
#define xISCHAR(c) ((((unsigned long) (c)) < (SDIST*NCHARS)) && ((int)c & FSYMBASE))
#define xAFSYM(a) (((int)a & FSYMBASE) \
                  ? ((fsym) (a)) : (((struct hdr *)a)->fsym))
#define xPTRxEQ(p,q) (p == q)
#define xPTRxNEQ(p,q) (p != q)

/* for lists */
#define xMINUS(a,b) a-b
#define xLSTxLEN(l) (((struct hdr *)l)->num)
/* n is the position on the stack ! */
#define xINITxITEM(n,l) *(AP+n) = (ptr)(((long)(xARG(n+1))) + l);
#define xALLOCxINITxITEM(l) xPUSHA(((long)(xARG(1)))+l);
#define xSAVExTERM(t) (TP = ((ptr *) (t)))
#define xADVANCABLE(n,l)  ((((long)(xARG(n-1))) - ((long)(xARG(n)))) > l)
#define xADVANCE(n) (*(((long *)(AP+n))) += 1);
#define xCODEDxLSTxELM(s,l,n) (ptr) *(xSADR(xARG(s))+((long)(xARG(l)))+n-1)
#define xPUSHxLST(l,b) HDRS->fsym = xLST();         \
                       HDRS->sadr =xSADR(l)+b-1; \
                       HDRS->num = xEADR(l)-HDRS->sadr;     \
                       xPUSHM(HDRS--); HDRS_CHK  
#define xPUSHxELMS(l,b) for (TP=xSADR(l)+b-1; TP<xEADR(l); TP++) xPUSHM(*TP);
#define xPUSHxCODEDxLST(s,a,b) HDRS->fsym = xLST();     \
                             HDRS->sadr = xSADR(xARG(s))+((long)(xARG(a)))+b-1; \
                             HDRS->num = ((long)(xARG(a-1)))-((long)(xARG(a)))-b+1;   \
                             xPUSHM(HDRS--); HDRS_CHK
#define xPUSHxCODEDxELMS(s,a,b) for (TP=(ptr *) (xSADR(xARG(s))+((long)(xARG(a)))+b-1);\
                             TP< ((ptr *) (xSADR(xARG(s))+((long)(xARG(a-1)))));       \
                             TP++)                              \
                        xPUSHM(*TP);                             

#define xSWITCH(csource,stat1,stat2) switch(csource){stat1}stat2
#define xCASE(cval,stat) case cval: stat
#define xCONTINUE() continue;
#define xBREAK() break;
#define xLABEL(l) l:
#define xGOTO(l) goto l;
#define xIF(e,s1,s2) if(e){s1} s2
#define xIFE(e,s1,s2) if(e){s1} else {s2}
#define xISIS(v1,v2) v1 == v2
#define xGTEQ(v1,v2) v1 >= v2

#define xC2I(c) (SDIST*(c)+FSYMBASE)
#define xREALFSYM(i) ((i-FSYMBASE)/SDIST)

/* if this changes, also change base in Arm2C */
#define FIRST_SPECIAL_FUN NCHARS*SDIST+FSYMBASE
#define SPECIAL_SYMS 99
#define FIRST_PUBLIC_FUN FIRST_SPECIAL_FUN + (SPECIAL_SYMS*SDIST)  

/* fixed codes for following function symbols, several classes:
- TOKENS used by arm. These are improper symbols, of the
  form xNAME()
- Functions with a special definition, that can be used from
  an RN2 specification. Comes in two varieties:

  (RN2)   (c id)
  $_.     xi_.    means that no outer case is generated
  $._     xi._    means that no #define id number is generated

  note that the $ means that it is not meant for ordinary use,
  and currently also that no scanning/printing is generated for
  these functions
*/
/* if C compiler can be trusted, put here FIRST_SPECIAL_FUN+n*SDIST */
#define xSTOP()  1025
#define xSLST()  1029
#define xELST()  1033
#define xEQ()    1037
#define xASGN()  1041
#define xBM()    1045
#define xi__conv        1053
#define xi__gel_write   1057
#define xi__gel_read    1061
#define xic_gel_gcons   1065
#define xic_gel_dup     1069
#define xic_gel_del     1073

#define xic_b0          1081
#define xic_b1          1085
#define xic_bin         1089
#define xic_ap          1093
#define xic_gel_mkd     1097
#define xic_gel_mk      1103
#define xic_gel_nil     1107
#define xi__o           1111
#define xi__cl          1115
#define xi__isc         1119
#define xi__ctoa        1123
#define xi__atoc        1127
#define xic_i           1131
#define xi__constr      1135

/* list is first public function symbol */
#define xLST() FIRST_PUBLIC_FUN

#define LOW_SENTINEL 0
#define HIGH_SENTINEL 1

struct hdr *hdrs;
ptr *heap, *astack, *mstack;

unsigned long HEAPSIZE = 500000;
unsigned long HDRSIZE = 500000;
unsigned long SIZExSTACKS = 20000;
unsigned long OPTVAL;
unsigned long WRITEGEL=0;
unsigned long READGEL=0;

#ifdef FASTMEM
void allochandler(int sig)
{ if (sig) error("memory allocation failed");
};
void memhandler(int sig)
{
#ifdef DEBUG
    fprintf(stderr,"ASTACK used: %ld\n",(astack+SIZExSTACKS-save_AP));
    fprintf(stderr,"MSTACK used: %ld\n",(save_MP-mstack));
    fprintf(stderr,"HEAP used: %ld\n",(save_HP-heap));
    fprintf(stderr,"HDRS used: %ld\n",(hdrs+HDRSIZE-save_HDRS));
#endif
  if (*(int *)hdrs || *((int *)hdrs+1)) 
  /* a num field could be zero, but never fsym */
     error("headers overflow, increase -i option\n");
  if (*(heap+HEAPSIZE-1)) /* fsyms and pointers are never zero */
     error("heap overflow, increase -h option\n");
  if (*astack) /* arguments are pointers or fsyms, never zero */
     error("argument stack overflow, increase -s option\n");
  if (*(mstack+SIZExSTACKS-1) || *(mstack+SIZExSTACKS-2) 
      || *(mstack+SIZExSTACKS-3) || *(mstack+SIZExSTACKS-4)) 
     /* control stack may overflow (arbitrarily many) zeros */
     error("control stack overflow, increase -s option\n");
  error("memory fault, possibly control stack overflow\n");

}
#endif

char *allocblock(int number, size_t size, char *s, int sent)
{ int memfd;
  char *block;
  int realsize;

#ifdef FASTMEM
  memfd = open("/dev/zero",O_RDWR);

  /* round up to whole number of pages, and add 1 for the sentinel */
  realsize = ((number*size)/getpagesize()+2)*getpagesize();

  block = (char *)mmap(0,realsize,PROT_READ|PROT_WRITE,MAP_SHARED,memfd,0);
  if ((int)block == -1) error(strcat("not enough space for ",s));

  switch(sent)
    { case LOW_SENTINEL:
        mmap(block,getpagesize(),PROT_READ,MAP_FIXED|MAP_SHARED,memfd,0);
        block += getpagesize();
        break;
      case HIGH_SENTINEL:
        mmap(block+realsize-getpagesize(),getpagesize(),
             PROT_READ,MAP_FIXED|MAP_SHARED,memfd,0);break;
      }

  close(memfd);
#else
  if (!(block= (char *)malloc(size*number))) 
     error(strcat("not enough space for ",s));
#endif
  return(block);
}

void set_mem_handler()
{
#ifdef FASTMEM
    signal(SIGSEGV,memhandler);
    signal(SIGBUS,memhandler);
#endif
}

void set_alloc_handler()
{
#ifdef FASTMEM
    signal(SIGSEGV,allochandler); 
    signal(SIGBUS,allochandler);
#endif
}

/* xBOUTER is the beginning of the outer loop */
#define xBOUTER() main(int argc, char *argv[])               \
  {                                                \
    register struct hdr *HDRS;                              \
    register ptr *MP, *AP, *HP, *TP, D1, D2;           \
    int c;                                         \
    char OPT[2];                                   \
                                                   \
   while (--argc > 0)                             \
      {  if (sscanf(*++argv,"-%1s%lu",OPT,&OPTVAL) == 2)         \
           {       \
         switch (OPT[0]){                                          \
         case 's': SIZExSTACKS = OPTVAL;       \
                   break;                                          \
         case 'h': HEAPSIZE = OPTVAL;          \
                   break;                      \
         case 'i': HDRSIZE = OPTVAL;           \
                   break;                      \
         case 'w': WRITEGEL = OPTVAL;          \
                   break;                      \
         case 'r': READGEL = OPTVAL;           \
                   break;                      \
         };}                                                         \
         else error("wrong command-line option\n");                  \
       };                                                          \
    set_alloc_handler;                         \
    astack = (ptr *)allocblock(SIZExSTACKS,sizeof(ptr),        \
                               "argument stack",LOW_SENTINEL);       \
    AP=astack+SIZExSTACKS - 1;                                   \
    save_AP=AP;\
          \
    mstack = (ptr *)allocblock(SIZExSTACKS,sizeof(ptr),        \
                               "message stack",HIGH_SENTINEL);       \
    MP=mstack;                                                        \
    save_MP=MP;                            \
    heap = (ptr *)allocblock(HEAPSIZE,sizeof(ptr),"heap",HIGH_SENTINEL);      \
    HP=heap;       \
    save_HP=HP;    \
    hdrs = (struct hdr *)allocblock(HDRSIZE,sizeof(struct hdr),        \
                                    "headers",LOW_SENTINEL);       \
    HDRS=hdrs+HDRSIZE - 1;      \
    save_HDRS=HDRS;             \
    set_mem_handler;            \
                                                       \
    xPUSHM(xSTOP());                               \
    if (WRITEGEL)                                  \
      {xPUSHM(xi__gel_write); initgel();}            \
    else                                           \
      {xPUSHM(xipretty); if (!WRITEGEL) initgel();};                        \
    if (READGEL)                                   \
      {xPUSHM(xi__gel_read);                       \
       MP=read_gel(MP);    }                       \
    else                                           \
      {xPUSHM(xic_i);                                \
       xSTRTxNODE(xLST());                            \
       while ((c = getchar()) != EOF) {xEXPRxPUTxHEAP(xC2I(c));}        \
       xFNSHxNODE();                                  \
       };                                          \
                                                   \
    for(;;) {                                      \
    switch ((fsym)(D1 = xPOPM())) {                          \



/* better if this uses ARM stacks */
ptr termxequal(struct hdr *term1,struct hdr *term2)
{ ptr *E1,*T1,*T2;
  if (term1 == term2) return((ptr)1);
  if (xAFSYM(term1)==xAFSYM(term2))
    { if (xLSTxLEN(term1) == xLSTxLEN(term2))
      { E1 = (ptr *)xEADR(term1);
        T1 = xSADR(term1);
        T2 = xSADR(term2);
        while(xPTRxNEQ(E1,T1)) 
          if (!termxequal((struct hdr *)*T1++,(struct hdr *)*T2++)) return(0);
        return((ptr)1);
      };      
   };
   return((ptr)0);
}

#ifndef NOGC
#define xGCHP() xPUSHM(HDRS); xPUSHM(HP);
#define xCOMPARExSWITCH(stat)                                   \
  HP = (ptr *)(xPOPM()); /* reset heap */                       \
  HDRS = (struct hdr *)(xPOPM()); /* reset hdrs */              \
  D1 = termxequal((struct hdr *)xARG(1),(struct hdr *)xARG(2)); \
  xDROPA(2);                                                    \
  switch ((unsigned long) xPOPM()){stat};
#define xASSIGNxSWITCH(stat)                                               \
  HP = (ptr *)xPOPM();                         /* reset heap */            \
  HDRS = (struct hdr *)(xPOPM());              /* reset hdrs */            \
  D2 = (ptr)xPOPA();                           /* term to be copied */     \
  xPUSHA(xSTOP());                             /* marker */                \
  xPUSHM(xSTOP());                             /* another marker */        \
  xPUSHA(D2);                                  /* start with this term */  \
  while ((fsym)(D2=(ptr)xPOPA()) != xSTOP())                               \
  { if (!((fsym)D2 & 1))                       /* a pointer */             \
    {if ((struct hdr *)D2 <= HDRS)     /* needs to be saved */             \
      {if (((struct hdr*)D2)->sadr >= HP)                                  \
        { xPUSHM((fsym)(((struct hdr *)D2)->num));                         \
          xPUSHM((fsym)(((struct hdr *)D2)->fsym));                        \
          xPUSHM(xi__constr);                                              \
          for (c=(((struct hdr *)D2)->num);c>=1;c--)                       \
            xPUSHA(xDTR(D2,c));                                            \
	    }                                                              \
       else                                                              \
	 { xPUSHM((fsym)(((struct hdr *)D2)->sadr));                     \
           xPUSHM((fsym)(((struct hdr *)D2)->num));                      \
           xPUSHM((fsym)(((struct hdr *)D2)->fsym));                     \
           xPUSHM(xi__conv); /* misuse this fsym */                      \
	   };                                                            \
      } else xPUSHM((fsym)D2);                                           \
    } else xPUSHM((fsym)D2);};                                           \
  while ((fsym)(D2=(ptr)xPOPM()) != xSTOP())                             \
  { if ((fsym)D2==xi__constr)                                            \
    { xSTRTxNODE((fsym)xPOPM());                                         \
      for (c=(int)xPOPM();c>=1;c--) {xPUTxHEAP(xPOPA());};               \
      xFNSHxNODE();                                                      \
      } else if ((fsym)D2==xi__conv)                                     \
         {HDRS->fsym=(fsym)xPOPM();HDRS->num=(fsym)xPOPM();              \
          HDRS->sadr=(ptr *)xPOPM();xPUSHA(HDRS--);}                     \
           else xPUSHA(D2);};                                            \
  switch((unsigned long)xPOPM()) {stat};
#else
#define xGCHP()
#define xCOMPARExSWITCH(stat)                   \
  D1 = termxequal((struct hdr *)xARG(1),(struct hdr *)xARG(2)); \
  xDROPA(2);                        \
  switch ((unsigned long) xPOPM()){stat};
#define xASSIGNxSWITCH(stat) switch((unsigned long) xPOPM()) {stat};
#endif

#define xD1() (unsigned long) D1
#define xTEQ(stat1,stat2) if (xD1()) {stat1} ; stat2
#define xTNEQ(stat1,stat2) if (!xD1()) {stat1} ; stat2

/* gel writer preliminaries */
char *fnames[];       /* array of function names, generated by SMtoRN1 */
char **abb=NULL;      /* pointers to abbreviations */
char *text=NULL;      /* abbreviations themselves  */
char *endtext=NULL;   /* end of current text space */
#define TEXTBLOCK 10000

char *newtext()
{ if (text && ((text+20)<endtext))
      { return((text+=10));
      }
      else
      { text = (char *)malloc(TEXTBLOCK*sizeof(char));
        endtext = text+TEXTBLOCK;
        return(text);
      };
}

int nfsyms; /* initialize with table of function names */
void initgel() {  abb = (char **)calloc(nfsyms,sizeof(char *));}

void gel_print_bin(ptr p)
  { switch(xAFSYM(p))
      { case xic_b0:  putchar('0'); return;
        case xic_b1:  putchar('1'); return;
        case xic_bin: gel_print_bin(xDTR(p,1));
                              gel_print_bin(xDTR(p,2));
                              return;
      };
  }

void gel_print_abbrline(int realf,ptr p)
{ int count,rrealf;
  char *thistext;

  thistext=newtext();

  if (realf > 255)
  { rrealf=realf-(NCHARS+SPECIAL_SYMS);
    if (!abb[rrealf]) 
       {count = (int)sprintf(thistext,"a%ld",rrealf); 
        abb[rrealf]=thistext; 
        printf("!%s:",abb[rrealf]);
        if (rrealf)
	  { gel_print_bin(p);}
        else { printf("*");};
        printf("=%s\n",fnames[rrealf]);
       };};
}

void gel_print_token(fsym f)
{ 
  int realf = xREALFSYM((f-TOKENIZE));

  if (realf <= 255) 
    {putchar('\'');putchar(realf);}
  else
    {printf("%s",abb[realf-(NCHARS+SPECIAL_SYMS)]);};
}

void write_gel(ptr term,ptr *MP)
{ ptr D1;
  int realf;

  xPUSHM(xSTOP())
  while (!(xAFSYM(term) == xic_gel_nil))
  { realf = xREALFSYM((((fsym)xDTR(xDTR(term,1),1))-TOKENIZE));
    gel_print_abbrline(realf,xDTR(xDTR(term,1),2));
    gel_print_token((fsym)xDTR(xDTR(term,1),1));
    if ((realf-(NCHARS+SPECIAL_SYMS))) 
       {printf("\n");}
    else {printf(" ");gel_print_bin(xDTR(xDTR(term,1),2));printf("\n");};
    term = xDTR(term,2);
  };
}

/* gel reader */
ptr *read_gel(ptr *MP)
{ int c,i;
  char longname[1024];
  char shortname[8];
  char strarity[32];
  char *l, *s, *ar, *chars;
  struct arity *a;

  struct entry *e=NULL;

    /* enter character functions in dictionary */
    chars = (char *)malloc(768*sizeof(char));
    for (i=0;i<=255;i++) {chars[3*i]='\'';chars[3*i+1]=i;chars[3*i+2]='\0';};
    for (i=0;i<=255;i++) 
      {a=(struct arity *)malloc(sizeof(struct arity));
       a->code = i*SDIST+FSYMBASE;
       a->arity = "0";
       e=insert(chars+3*i,e,a);};

  /* enter other functions in dictionary */
  for (i=0; i<nfsyms; i++) 
    {a=(struct arity *)malloc(sizeof(struct arity));
     a->code = FIRST_PUBLIC_FUN+SDIST*i;
     a->arity = NULL;
     e=insert(fnames[i],e,a);};

  while ((c = getchar()) != EOF)
    { gel_line++;
      switch(c)
      {
        case '!':
           l=longname;
           s=shortname;
           ar=strarity;
           while ((*s++ = getchar()) != ':') {};
           *(s-1)='\0';
           while ((*ar++ = getchar()) != '=') {};
           *(ar-1)='\0';
           while ((*l++ = getchar()) != '\n') {};
           *(l-1)='\0';
           a=lookup(longname,e);
           if (a->arity == NULL) 
             {a->arity=(char *)malloc(32);
              strcpy(a->arity,strarity);
	    };
           e=insert(shortname,e,a);
           break;
	case '*':
           s=shortname;
           while ((c = (*s++ = getchar())) != '\n' && c != ' ') {};
           *(s-1)= '\0';
           xPUSHM(xic_gel_gcons);
           xPUSHM(xic_gel_del);
           for (s=shortname;*(s+1)!='\0';s++) {xPUSHM(xic_bin);};
           for (s=shortname;*s!='\0';s++)
             {if (*s=='0')
                {xPUSHM(xic_b0);}
              else
                {xPUSHM(xic_b1);};};
           break;
        case '#':
           s=shortname;
           while ((c = (*s++ = getchar())) != '\n' && c != ' ') {};
           *(s-1)= '\0';
           xPUSHM(xic_gel_gcons);
           xPUSHM(xic_gel_dup);
           for (s=shortname;*(s+1)!='\0';s++) {xPUSHM(xic_bin);};
           for (s=shortname;*s!='\0';s++)
             {if (*s=='0')
                {xPUSHM(xic_b0);}
              else
                {xPUSHM(xic_b1);};};
           break;
        case '\n': break;
        case '\'':
           xPUSHM(xic_gel_gcons);
           xPUSHM(xic_gel_mk);
           c=getchar();
           if (c=='\n') {gel_line++;};
           xPUSHM((c*SDIST+FSYMBASE+TOKENIZE));
           getchar();
           xPUSHM(xic_b0);
           break;
        default:
           shortname[0]=c;
           s=shortname+1;
           while ((c = (*s++ = getchar())) != '\n' && c != ' ') {};
           *(s-1)='\0';
           xPUSHM(xic_gel_gcons);
           xPUSHM(xic_gel_mk);
           a=lookup(shortname,e);
           xPUSHM((a->code)+TOKENIZE);
           if (c == '\n')
	     {for (s=a->arity;*(s+1)!='\0';s++) {xPUSHM(xic_bin);};
                   for (s=a->arity;*s!='\0';s++)
                   {if (*s=='0')
                      {xPUSHM(xic_b0);}
                    else
                      {xPUSHM(xic_b1);};};}
           else
             {s=shortname;
              while ((c = (*s++ = getchar())) != '\n' && c != ' ') {};
              *(s-1)='\0';
              switch(shortname[0])
                {case '0':
                 case '1':
                   /* first push bins */
                   for (s=shortname;*(s+1)!='\0';s++) {xPUSHM(xic_bin);};
                   for (s=shortname;*s!='\0';s++)
                   {if (*s=='0')
                      {xPUSHM(xic_b0);}
                    else
                      {xPUSHM(xic_b1);};};
                   break;
               };};};};
  xPUSHM(xic_gel_nil);
  return(MP);} 

#define xTSTxHEAP(n)
/* end of barm.c */
int nfsyms=7;char *fnames[]={"|","listtype",
"Counters: init -> NAT",
"Counters: \"0\" -> NAT",
"Counters: succ ( NAT ) -> NAT",
"Counters: inc ( NAT ) -> NAT",
"NAT"};

#define xflisttype 1425

#define xfCountersxmxWinitxWxjxqxWNAT 1429

#define xfCountersxmxWxY0xYxWxjxqxWNAT 1433

#define xfCountersxmxWsuccxWxexWNATxWxfxWxjxqxWNAT 1437

#define xfCountersxmxWincxWxexWNATxWxfxWxjxqxWNAT 1441

#define xfNAT 1445

#define xinl 1449

#define xiuscan 1453

#define xiscan 1457

#define xiscal 1461

#define xiwh 1465

#define xirwh 1469

#define xisres 1473

#define xilist 1477

#define xipretty 1481

#define xiplst 1485

#define xipelms 1489

#define xicons 1493

#define xinil 1497

#define xianil 1501

#define xiacons 1505

#define xibplus 1509

#define xibpred 1513

#define xigel_write2 1517

#define xigel_write_args 1521

#define xigel_read2 1525

#define xigel_read_args 1529

#define xigel_drop 1533

#define xigel_len 1537

#define xigel_get 1541

#define xftesta 1545

#define xftestb 1549

#define xftestc 1553

#define xftestd 1557


xBOUTER()
xCASE(xflisttype,)
xTSTxHEAP(5)
xSTRTxNODE(xflisttype)
xPUTxHEAP(xPOPA())
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xfCountersxmxWinitxWxjxqxWNAT,xPUSHM(xfCountersxmxWxY0xYxWxjxqxWNAT)

xDROPA(0)
xCONTINUE())
xPUSHA(xfCountersxmxWinitxWxjxqxWNAT)
xCONTINUE()
xCASE(xfCountersxmxWxY0xYxWxjxqxWNAT,)
xPUSHA(xfCountersxmxWxY0xYxWxjxqxWNAT)
xCONTINUE()
xCASE(xfCountersxmxWsuccxWxexWNATxWxfxWxjxqxWNAT,)
xTSTxHEAP(4)
xSTRTxNODE(xfCountersxmxWsuccxWxexWNATxWxfxWxjxqxWNAT)
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xfCountersxmxWincxWxexWNATxWxfxWxjxqxWNAT,xPUSHM(xfCountersxmxWsuccxWxexWNATxWxfxWxjxqxWNAT)
xPUSHM(xARG(1))

xDROPA(1)
xCONTINUE())
xTSTxHEAP(4)
xSTRTxNODE(xfCountersxmxWincxWxexWNATxWxfxWxjxqxWNAT)
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xfNAT,)
xTSTxHEAP(4)
xSTRTxNODE(xfNAT)
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xic_i,xIF(xGTEQ(xLSTxLEN(xSAVExTERM(xARG(1))),1),xPUSHA(0)

xPUSHA(xLSTxLEN(xTP()))
xPUSHA(xTP())
xPUSHA(1)
xPUSHA(xBM())
xLABEL(xMAKExLABEL(2))
xPUSHM(0)
xGCHP()
xPUSHM(xASGN())
xPUSHM(xiuscan)
xPUSHM(xCODEDxLSTxELM(3,5,1))
xPUSHxCODEDxLST(3,5,2)

xCONTINUE()
xLABEL(xMAKExLABEL(0))
xIF(xISIS(xAFSYM(xARG(1)),xisres),xIF(xGTEQ(xLSTxLEN(xSAVExTERM(xDTR(xARG(1),2))),0),xPUSHA(0)

xPUSHA(xLSTxLEN(xTP()))
xPUSHA(xTP())
xPUSHA(1)
xPUSHA(xBM())
xLABEL(xMAKExLABEL(1))
xPUSHM(xDTR(xARG(6),1))
xDROPA(12)
xCONTINUE()

xDROPA(5),),)

xDROPA(1)

xDROPA(5),))
xTSTxHEAP(4)
xSTRTxNODE(xic_i)
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()

xCASE(xinl,xPUSHM(xi__o)
xPUSHM(xSLST())
xPUSHM(xC2I(10))


xPUSHM(xELST())

xDROPA(0)
xCONTINUE())
xPUSHA(xinl)
xCONTINUE()
xCASE(xiuscan,xPUSHM(xiscan)
xPUSHM(xARG(1))
xPUSHM(xARG(2))

xDROPA(2)
xCONTINUE())
xTSTxHEAP(5)
xSTRTxNODE(xiuscan)
xPUTxHEAP(xPOPA())
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xiscan,xSWITCH(xAFSYM(xARG(1)),xCASE(xC2I(95),xIF(xGTEQ(xLSTxLEN(xSAVExTERM(xARG(2))),3),xPUSHA(0)

xPUSHA(xLSTxLEN(xTP()))
xPUSHA(xTP())
xPUSHA(1)
xPUSHA(xBM())
xLABEL(xMAKExLABEL(3))
xPUSHM(xisres)
xPUSHM(xi__atoc)
xPUSHM(xCODEDxLSTxELM(3,5,1))
xPUSHM(xCODEDxLSTxELM(3,5,2))
xPUSHM(xCODEDxLSTxELM(3,5,3))

xPUSHxCODEDxLST(3,5,4)

xDROPA(7)
xCONTINUE()

xDROPA(5),)
xBREAK())
xCASE(xC2I(91),xIF(xGTEQ(xLSTxLEN(xSAVExTERM(xARG(2))),1),xPUSHA(0)

xPUSHA(xLSTxLEN(xTP()))
xPUSHA(xTP())
xPUSHA(1)
xPUSHA(xBM())
xLABEL(xMAKExLABEL(6))
xPUSHM(4)
xGCHP()
xPUSHM(xASGN())
xPUSHM(xiscal)
xPUSHM(xCODEDxLSTxELM(3,5,1))
xPUSHxCODEDxLST(3,5,2)

xCONTINUE()
xLABEL(xMAKExLABEL(4))
xIF(xISIS(xAFSYM(xARG(1)),xisres),xIF(xGTEQ(xLSTxLEN(xSAVExTERM(xDTR(xARG(1),2))),0),xPUSHA(0)

xPUSHA(xLSTxLEN(xTP()))
xPUSHA(xTP())
xPUSHA(1)
xPUSHA(xBM())
xLABEL(xMAKExLABEL(5))
xPUSHM(xisres)
xPUSHM(xi__cl)
xPUSHM(xDTR(xARG(6),1))

xPUSHxCODEDxLST(3,5,1)

xDROPA(13)
xCONTINUE()

xDROPA(5),),)

xDROPA(1)

xDROPA(5),)
xBREAK())
,xIF(xGTEQ(xLSTxLEN(xSAVExTERM(xARG(2))),1),xPUSHA(0)

xPUSHA(xLSTxLEN(xTP()))
xPUSHA(xTP())
xPUSHA(1)
xPUSHA(xBM())
xLABEL(xMAKExLABEL(8))
xPUSHM(7)
xGCHP()
xPUSHM(xEQ())
xPUSHM(xiwh)
xPUSHM(xARG(6))

xPUSHM(xC2I(116))

xCONTINUE()
xLABEL(xMAKExLABEL(7))
xTEQ(xPUSHM(xiuscan)
xPUSHM(xCODEDxLSTxELM(3,5,1))
xPUSHxCODEDxLST(3,5,2)

xDROPA(7)
xCONTINUE(),)

xDROPA(5),)))
xTSTxHEAP(5)
xSTRTxNODE(xiscan)
xPUTxHEAP(xPOPA())
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xiscal,xSWITCH(xAFSYM(xARG(1)),xCASE(xC2I(93),xIF(xGTEQ(xLSTxLEN(xSAVExTERM(xARG(2))),0),xPUSHA(0)

xPUSHA(xLSTxLEN(xTP()))
xPUSHA(xTP())
xPUSHA(1)
xPUSHA(xBM())
xLABEL(xMAKExLABEL(9))
xPUSHM(xisres)
xPUSHM(xinil)

xPUSHxCODEDxLST(3,5,1)

xDROPA(7)
xCONTINUE()

xDROPA(5),)
xBREAK())
,xIF(xGTEQ(xLSTxLEN(xSAVExTERM(xARG(2))),1),xPUSHA(0)

xPUSHA(xLSTxLEN(xTP()))
xPUSHA(xTP())
xPUSHA(1)
xPUSHA(xBM())
xLABEL(xMAKExLABEL(18))
xPUSHM(17)
xGCHP()
xPUSHM(xEQ())
xPUSHM(xiwh)
xPUSHM(xARG(6))

xPUSHM(xC2I(116))

xCONTINUE()
xLABEL(xMAKExLABEL(17))
xTEQ(xPUSHM(xiscal)
xPUSHM(xCODEDxLSTxELM(3,5,1))
xPUSHxCODEDxLST(3,5,2)

xDROPA(7)
xCONTINUE(),)

xDROPA(5),xIF(xGTEQ(xLSTxLEN(xSAVExTERM(xARG(2))),0),xPUSHA(0)

xPUSHA(xLSTxLEN(xTP()))
xPUSHA(xTP())
xPUSHA(1)
xPUSHA(xBM())
xLABEL(xMAKExLABEL(16))
xPUSHM(10)
xGCHP()
xPUSHM(xEQ())
xPUSHM(xiwh)
xPUSHM(xARG(6))

xPUSHM(xC2I(116))

xCONTINUE()
xLABEL(xMAKExLABEL(10))
xTNEQ(xPUSHM(11)
xGCHP()
xPUSHM(xEQ())
xPUSHM(xARG(6))
xPUSHM(xC2I(93))

xCONTINUE()
xLABEL(xMAKExLABEL(11))
xTNEQ(xPUSHM(12)
xGCHP()
xPUSHM(xASGN())
xPUSHM(xiuscan)
xPUSHM(xARG(6))
xPUSHxCODEDxLST(3,5,1)

xCONTINUE()
xLABEL(xMAKExLABEL(12))
xIF(xISIS(xAFSYM(xARG(1)),xisres),xIF(xGTEQ(xLSTxLEN(xSAVExTERM(xDTR(xARG(1),2))),1),xPUSHA(0)

xPUSHA(xLSTxLEN(xTP()))
xPUSHA(xTP())
xPUSHA(1)
xPUSHA(xBM())
xLABEL(xMAKExLABEL(15))
xPUSHM(13)
xGCHP()
xPUSHM(xASGN())
xPUSHM(xiscal)
xPUSHM(xCODEDxLSTxELM(3,5,1))
xPUSHxCODEDxLST(3,5,2)

xCONTINUE()
xLABEL(xMAKExLABEL(13))
xIF(xISIS(xAFSYM(xARG(1)),xisres),xIF(xGTEQ(xLSTxLEN(xSAVExTERM(xDTR(xARG(1),2))),0),xPUSHA(0)

xPUSHA(xLSTxLEN(xTP()))
xPUSHA(xTP())
xPUSHA(1)
xPUSHA(xBM())
xLABEL(xMAKExLABEL(14))
xPUSHM(xisres)
xPUSHM(xicons)
xPUSHM(xDTR(xARG(12),1))
xPUSHM(xDTR(xARG(6),1))

xPUSHxCODEDxLST(3,5,1)

xDROPA(19)
xCONTINUE()

xDROPA(5),),)

xDROPA(1)

xDROPA(5),),)

xDROPA(1),),)

xDROPA(5),))))
xTSTxHEAP(5)
xSTRTxNODE(xiscal)
xPUTxHEAP(xPOPA())
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xiwh,xSWITCH(xAFSYM(xARG(1)),xCASE(xC2I(9),xPUSHM(xC2I(116))

xDROPA(1)
xCONTINUE()
xBREAK())
xCASE(xC2I(10),xPUSHM(xC2I(116))

xDROPA(1)
xCONTINUE()
xBREAK())
xCASE(xC2I(13),xPUSHM(xC2I(116))

xDROPA(1)
xCONTINUE()
xBREAK())
xCASE(xC2I(32),xPUSHM(xC2I(116))

xDROPA(1)
xCONTINUE()
xBREAK())
xCASE(xC2I(44),xPUSHM(xC2I(116))

xDROPA(1)
xCONTINUE()
xBREAK())
xCASE(xC2I(40),xPUSHM(xC2I(116))

xDROPA(1)
xCONTINUE()
xBREAK())
xCASE(xC2I(41),xPUSHM(xC2I(116))

xDROPA(1)
xCONTINUE()
xBREAK())
,))
xTSTxHEAP(4)
xSTRTxNODE(xiwh)
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xirwh,xSWITCH(xAFSYM(xARG(1)),xCASE(xC2I(9),xPUSHM(xC2I(116))

xDROPA(1)
xCONTINUE()
xBREAK())
xCASE(xC2I(10),xPUSHM(xC2I(116))

xDROPA(1)
xCONTINUE()
xBREAK())
xCASE(xC2I(13),xPUSHM(xC2I(116))

xDROPA(1)
xCONTINUE()
xBREAK())
xCASE(xC2I(32),xPUSHM(xC2I(116))

xDROPA(1)
xCONTINUE()
xBREAK())
,))
xTSTxHEAP(4)
xSTRTxNODE(xirwh)
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xisres,)
xTSTxHEAP(5)
xSTRTxNODE(xisres)
xPUTxHEAP(xPOPA())
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xilist,)
xTSTxHEAP(4)
xSTRTxNODE(xilist)
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xipretty,xPUSHM(19)
xGCHP()
xPUSHM(xEQ())
xPUSHM(xC2I(116))

xPUSHM(xi__isc)
xPUSHM(xARG(1))

xCONTINUE()
xLABEL(xMAKExLABEL(19))
xTEQ(xPUSHM(20)
xGCHP()
xPUSHM(xASGN())
xPUSHM(xi__ctoa)
xPUSHM(xARG(1))

xCONTINUE()
xLABEL(xMAKExLABEL(20))
xIF(xISIS(xAFSYM(xARG(1)),xilist),xIF(xGTEQ(xLSTxLEN(xSAVExTERM(xDTR(xARG(1),1))),0),xPUSHA(0)

xPUSHA(xLSTxLEN(xTP()))
xPUSHA(xTP())
xPUSHA(1)
xPUSHA(xBM())
xLABEL(xMAKExLABEL(21))
xPUSHM(xi__o)
xPUSHM(xSLST())
xPUSHM(xC2I(95))

xPUSHxCODEDxELMS(3,5,1)
xPUSHM(xC2I(40))

xPUSHM(xC2I(41))


xPUSHM(xELST())

xDROPA(7)
xCONTINUE()

xDROPA(5),),)

xDROPA(1),))
xTSTxHEAP(4)
xSTRTxNODE(xipretty)
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xiplst,xIF(xGTEQ(xLSTxLEN(xSAVExTERM(xARG(1))),0),xPUSHA(0)

xPUSHA(xLSTxLEN(xTP()))
xPUSHA(xTP())
xPUSHA(1)
xPUSHA(xBM())
xLABEL(xMAKExLABEL(24))
xPUSHM(22)
xGCHP()
xPUSHM(xEQ())
xPUSHM(xC2I(116))

xPUSHM(xi__o)
xPUSHM(xSLST())
xPUSHM(xC2I(91))


xPUSHM(xELST())

xCONTINUE()
xLABEL(xMAKExLABEL(22))
xTEQ(xPUSHM(23)
xGCHP()
xPUSHM(xEQ())
xPUSHM(xC2I(116))

xPUSHM(xipelms)
xPUSHxCODEDxLST(3,5,1)

xCONTINUE()
xLABEL(xMAKExLABEL(23))
xTEQ(xPUSHM(xi__o)
xPUSHM(xSLST())
xPUSHM(xC2I(93))


xPUSHM(xELST())

xDROPA(6)
xCONTINUE(),),)

xDROPA(5),))
xTSTxHEAP(4)
xSTRTxNODE(xiplst)
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xipelms,xIF(xGTEQ(xLSTxLEN(xSAVExTERM(xARG(1))),2),xPUSHA(0)

xPUSHA(xLSTxLEN(xTP()))
xPUSHA(xTP())
xPUSHA(1)
xPUSHA(xBM())
xLABEL(xMAKExLABEL(29))
xPUSHM(27)
xGCHP()
xPUSHM(xEQ())
xPUSHM(xC2I(116))

xPUSHM(xipretty)
xPUSHM(xCODEDxLSTxELM(3,5,1))

xCONTINUE()
xLABEL(xMAKExLABEL(27))
xTEQ(xPUSHM(28)
xGCHP()
xPUSHM(xEQ())
xPUSHM(xC2I(116))

xPUSHM(xi__o)
xPUSHM(xSLST())
xPUSHM(xC2I(44))


xPUSHM(xELST())

xCONTINUE()
xLABEL(xMAKExLABEL(28))
xTEQ(xPUSHM(xipelms)
xPUSHxCODEDxLST(3,5,2)

xDROPA(6)
xCONTINUE(),),)

xDROPA(5),xIF(xISIS(xLSTxLEN(xSAVExTERM(xARG(1))),1),xPUSHA(0)
xPUSHA(xLSTxLEN(xTP()))
xPUSHA(xTP())
xPUSHA(3)
xPUSHA(xBM())
xLABEL(xMAKExLABEL(26))
xPUSHM(xipretty)
xPUSHM(xCODEDxLSTxELM(3,5,1))

xDROPA(6)
xCONTINUE()

xDROPA(5),xPUSHM(25)
xGCHP()
xPUSHM(xEQ())
xPUSHM(xARG(1))
xPUSHM(xSLST())

xPUSHM(xELST())
xCONTINUE()
xLABEL(xMAKExLABEL(25))
xTEQ(xPUSHM(xC2I(116))

xDROPA(1)
xCONTINUE(),))))
xTSTxHEAP(4)
xSTRTxNODE(xipelms)
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xicons,)
xTSTxHEAP(5)
xSTRTxNODE(xicons)
xPUTxHEAP(xPOPA())
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xinil,)
xPUSHA(xinil)
xCONTINUE()




xCASE(xianil,)
xPUSHA(xianil)
xCONTINUE()
xCASE(xiacons,)
xTSTxHEAP(5)
xSTRTxNODE(xiacons)
xPUTxHEAP(xPOPA())
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()

xCASE(xic_ap,)
xTSTxHEAP(5)
xSTRTxNODE(xic_ap)
xPUTxHEAP(xPOPA())
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xic_gel_del,)
xTSTxHEAP(4)
xSTRTxNODE(xic_gel_del)
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xic_gel_dup,)
xTSTxHEAP(4)
xSTRTxNODE(xic_gel_dup)
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xic_gel_mk,)
xTSTxHEAP(5)
xSTRTxNODE(xic_gel_mk)
xPUTxHEAP(xPOPA())
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xic_gel_nil,)
xPUSHA(xic_gel_nil)
xCONTINUE()
xCASE(xic_gel_gcons,)
xTSTxHEAP(5)
xSTRTxNODE(xic_gel_gcons)
xPUTxHEAP(xPOPA())
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xic_b1,)
xPUSHA(xic_b1)
xCONTINUE()
xCASE(xic_b0,)
xPUSHA(xic_b0)
xCONTINUE()
xCASE(xic_bin,xSWITCH(xAFSYM(xARG(1)),xCASE(xic_b0,xPUSHM(xARG(2))
xDROPA(2)
xCONTINUE()
xBREAK())
,xSWITCH(xAFSYM(xARG(2)),xCASE(xic_bin,xPUSHM(xic_bin)
xPUSHM(xibplus)
xPUSHM(xARG(1))
xPUSHM(xDTR(xARG(2),1))

xPUSHM(xDTR(xARG(2),2))

xDROPA(2)
xCONTINUE()
xBREAK())
,)))
xTSTxHEAP(5)
xSTRTxNODE(xic_bin)
xPUTxHEAP(xPOPA())
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xibplus,xSWITCH(xAFSYM(xARG(1)),xCASE(xic_b0,xPUSHM(xARG(2))
xDROPA(2)
xCONTINUE()
xBREAK())
xCASE(xic_b1,xSWITCH(xAFSYM(xARG(2)),xCASE(xic_b0,xPUSHM(xic_b1)

xDROPA(2)
xCONTINUE()
xBREAK())
xCASE(xic_b1,xPUSHM(xic_bin)
xPUSHM(xic_b1)

xPUSHM(xic_b0)


xDROPA(2)
xCONTINUE()
xBREAK())
xCASE(xic_bin,xPUSHM(xic_bin)
xPUSHM(xDTR(xARG(2),1))
xPUSHM(xibplus)
xPUSHM(xic_b1)

xPUSHM(xDTR(xARG(2),2))


xDROPA(2)
xCONTINUE()
xBREAK())
,)
xBREAK())
xCASE(xic_bin,xPUSHM(xic_bin)
xPUSHM(xDTR(xARG(1),1))
xPUSHM(xibplus)
xPUSHM(xDTR(xARG(1),2))
xPUSHM(xARG(2))


xDROPA(2)
xCONTINUE()
xBREAK())
,))
xTSTxHEAP(5)
xSTRTxNODE(xibplus)
xPUTxHEAP(xPOPA())
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xibpred,xSWITCH(xAFSYM(xARG(1)),xCASE(xic_b1,xPUSHM(xic_b0)

xDROPA(1)
xCONTINUE()
xBREAK())
xCASE(xic_bin,xSWITCH(xAFSYM(xDTR(xARG(1),2)),xCASE(xic_b0,xPUSHM(xic_bin)
xPUSHM(xibpred)
xPUSHM(xDTR(xARG(1),1))

xPUSHM(xic_b1)


xDROPA(1)
xCONTINUE()
xBREAK())
xCASE(xic_b1,xPUSHM(xic_bin)
xPUSHM(xDTR(xARG(1),1))
xPUSHM(xic_b0)


xDROPA(1)
xCONTINUE()
xBREAK())
,)
xBREAK())
,))
xTSTxHEAP(4)
xSTRTxNODE(xibpred)
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xi__gel_write,xPUSHM(xigel_write2)
xPUSHM(xARG(1))
xPUSHM(xic_gel_nil)


xDROPA(1)
xCONTINUE())
xTSTxHEAP(4)
xSTRTxNODE(xi__gel_write)
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xigel_write2,xPUSHM(30)
xGCHP()
xPUSHM(xASGN())
xPUSHM(xi__conv)
xPUSHM(xARG(1))

xCONTINUE()
xLABEL(xMAKExLABEL(30))
xIF(xISIS(xAFSYM(xARG(1)),xic_ap),xIF(xGTEQ(xLSTxLEN(xSAVExTERM(xDTR(xARG(1),2))),0),xPUSHA(0)

xPUSHA(xLSTxLEN(xTP()))
xPUSHA(xTP())
xPUSHA(1)
xPUSHA(xBM())
xLABEL(xMAKExLABEL(31))
xPUSHM(xigel_write_args)
xPUSHxCODEDxLST(3,5,1)
xPUSHM(xic_gel_gcons)
xPUSHM(xic_gel_mk)
xPUSHM(xDTR(xARG(6),1))
xPUSHM(xigel_len)
xPUSHxCODEDxLST(3,5,1)


xPUSHM(xARG(8))


xDROPA(8)
xCONTINUE()

xDROPA(5),),)

xDROPA(1))
xTSTxHEAP(5)
xSTRTxNODE(xigel_write2)
xPUTxHEAP(xPOPA())
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xigel_write_args,xPUSHM(32)
xGCHP()
xPUSHM(xEQ())
xPUSHM(xARG(1))
xPUSHM(xSLST())

xPUSHM(xELST())
xCONTINUE()
xLABEL(xMAKExLABEL(32))
xTEQ(xPUSHM(xARG(2))
xDROPA(2)
xCONTINUE(),xIF(xGTEQ(xLSTxLEN(xSAVExTERM(xARG(1))),1),xPUSHA(0)

xPUSHA(xLSTxLEN(xTP()))
xPUSHA(xTP())
xPUSHA(1)
xPUSHA(xBM())
xLABEL(xMAKExLABEL(33))
xPUSHM(xigel_write2)
xPUSHM(xCODEDxLSTxELM(3,5,1))
xPUSHM(xigel_write_args)
xPUSHxCODEDxLST(3,5,2)
xPUSHM(xARG(7))


xDROPA(7)
xCONTINUE()

xDROPA(5),)))
xTSTxHEAP(5)
xSTRTxNODE(xigel_write_args)
xPUTxHEAP(xPOPA())
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xi__gel_read,xPUSHM(xigel_read2)
xPUSHM(xARG(1))
xPUSHM(xianil)


xDROPA(1)
xCONTINUE())
xTSTxHEAP(4)
xSTRTxNODE(xi__gel_read)
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xigel_read2,xSWITCH(xAFSYM(xARG(1)),xCASE(xic_gel_nil,xSWITCH(xAFSYM(xARG(2)),xCASE(xiacons,xPUSHM(xDTR(xARG(2),1))
xDROPA(2)
xCONTINUE()
xBREAK())
,)
xBREAK())
xCASE(xic_gel_gcons,xSWITCH(xAFSYM(xDTR(xARG(1),1)),xCASE(xic_gel_mk,xPUSHM(34)
xGCHP()
xPUSHM(xASGN())
xPUSHM(xi__cl)
xPUSHM(xigel_read_args)
xPUSHM(xDTR(xDTR(xARG(1),1),2))
xPUSHM(xARG(2))
xPUSHM(xinil)



xCONTINUE()
xLABEL(xMAKExLABEL(34))
xIF(xISIS(xAFSYM(xARG(1)),xilist),xIF(xGTEQ(xLSTxLEN(xSAVExTERM(xDTR(xARG(1),1))),0),xPUSHA(0)

xPUSHA(xLSTxLEN(xTP()))
xPUSHA(xTP())
xPUSHA(1)
xPUSHA(xBM())
xLABEL(xMAKExLABEL(36))
xPUSHM(35)
xGCHP()
xPUSHM(xASGN())
xPUSHM(xi__conv)
xPUSHM(xic_ap)
xPUSHM(xDTR(xDTR(xARG(7),1),1))
xPUSHxCODEDxLST(3,5,1)


xCONTINUE()
xLABEL(xMAKExLABEL(35))
xPUSHM(xigel_read2)
xPUSHM(xDTR(xARG(8),2))
xPUSHM(xiacons)
xPUSHM(xARG(1))
xPUSHM(xigel_drop)
xPUSHM(xDTR(xDTR(xARG(8),1),2))
xPUSHM(xARG(9))



xDROPA(9)
xCONTINUE()

xDROPA(1)

xDROPA(5),),)

xDROPA(1)
xBREAK())
xCASE(xic_gel_dup,xPUSHM(xigel_read2)
xPUSHM(xDTR(xARG(1),2))
xPUSHM(xiacons)
xPUSHM(xigel_get)
xPUSHM(xDTR(xDTR(xARG(1),1),1))
xPUSHM(xARG(2))

xPUSHM(xARG(2))


xDROPA(2)
xCONTINUE()
xBREAK())
xCASE(xic_gel_del,xSWITCH(xAFSYM(xARG(2)),xCASE(xiacons,xPUSHM(xigel_read2)
xPUSHM(xDTR(xARG(1),2))
xPUSHM(xiacons)
xPUSHM(xDTR(xARG(2),1))
xPUSHM(xigel_drop)
xPUSHM(xDTR(xDTR(xARG(1),1),1))
xPUSHM(xDTR(xARG(2),2))



xDROPA(2)
xCONTINUE()
xBREAK())
,)
xBREAK())
,)
xBREAK())
,))
xTSTxHEAP(5)
xSTRTxNODE(xigel_read2)
xPUTxHEAP(xPOPA())
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xigel_read_args,xSWITCH(xAFSYM(xARG(1)),xCASE(xic_b0,xPUSHM(xARG(3))
xDROPA(3)
xCONTINUE()
xBREAK())
,xSWITCH(xAFSYM(xARG(2)),xCASE(xiacons,xPUSHM(37)
xGCHP()
xPUSHM(xEQ())
xPUSHM(xARG(1))
xPUSHM(xic_b0)

xCONTINUE()
xLABEL(xMAKExLABEL(37))
xTNEQ(xPUSHM(xigel_read_args)
xPUSHM(xibpred)
xPUSHM(xARG(1))

xPUSHM(xDTR(xARG(2),2))
xPUSHM(xicons)
xPUSHM(xDTR(xARG(2),1))
xPUSHM(xARG(3))


xDROPA(3)
xCONTINUE(),)
xBREAK())
,)))
xTSTxHEAP(6)
xSTRTxNODE(xigel_read_args)
xPUTxHEAP(xPOPA())
xPUTxHEAP(xPOPA())
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xigel_drop,xSWITCH(xAFSYM(xARG(1)),xCASE(xic_b0,xPUSHM(xARG(2))
xDROPA(2)
xCONTINUE()
xBREAK())
,xSWITCH(xAFSYM(xARG(2)),xCASE(xiacons,xPUSHM(38)
xGCHP()
xPUSHM(xEQ())
xPUSHM(xARG(1))
xPUSHM(xic_b0)

xCONTINUE()
xLABEL(xMAKExLABEL(38))
xTNEQ(xPUSHM(xigel_drop)
xPUSHM(xibpred)
xPUSHM(xARG(1))

xPUSHM(xDTR(xARG(2),2))

xDROPA(2)
xCONTINUE(),)
xBREAK())
,)))
xTSTxHEAP(5)
xSTRTxNODE(xigel_drop)
xPUTxHEAP(xPOPA())
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xigel_len,xPUSHM(39)
xGCHP()
xPUSHM(xEQ())
xPUSHM(xARG(1))
xPUSHM(xSLST())

xPUSHM(xELST())
xCONTINUE()
xLABEL(xMAKExLABEL(39))
xTEQ(xPUSHM(xic_b0)

xDROPA(1)
xCONTINUE(),xIF(xGTEQ(xLSTxLEN(xSAVExTERM(xARG(1))),1),xPUSHA(0)

xPUSHA(xLSTxLEN(xTP()))
xPUSHA(xTP())
xPUSHA(1)
xPUSHA(xBM())
xLABEL(xMAKExLABEL(40))
xPUSHM(xibplus)
xPUSHM(xic_b1)

xPUSHM(xigel_len)
xPUSHxCODEDxLST(3,5,2)


xDROPA(6)
xCONTINUE()

xDROPA(5),)))
xTSTxHEAP(4)
xSTRTxNODE(xigel_len)
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xigel_get,xSWITCH(xAFSYM(xARG(1)),xCASE(xic_b0,xSWITCH(xAFSYM(xARG(2)),xCASE(xiacons,xPUSHM(xDTR(xARG(2),1))
xDROPA(2)
xCONTINUE()
xBREAK())
,)
xBREAK())
,xSWITCH(xAFSYM(xARG(2)),xCASE(xiacons,xPUSHM(41)
xGCHP()
xPUSHM(xEQ())
xPUSHM(xARG(1))
xPUSHM(xic_b0)

xCONTINUE()
xLABEL(xMAKExLABEL(41))
xTNEQ(xPUSHM(xigel_get)
xPUSHM(xibpred)
xPUSHM(xARG(1))

xPUSHM(xDTR(xARG(2),2))

xDROPA(2)
xCONTINUE(),)
xBREAK())
,)))
xTSTxHEAP(5)
xSTRTxNODE(xigel_get)
xPUTxHEAP(xPOPA())
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xftesta,)
xPUSHA(xftesta)
xCONTINUE()
xCASE(xftestb,)
xTSTxHEAP(4)
xSTRTxNODE(xftestb)
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xftestc,)
xTSTxHEAP(4)
xSTRTxNODE(xftestc)
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()
xCASE(xftestd,)
xTSTxHEAP(5)
xSTRTxNODE(xftestd)
xPUTxHEAP(xPOPA())
xPUTxHEAP(xPOPA())

xFNSHxNODE()
xCONTINUE()

xCASE(xEQ(),xCOMPARExSWITCH(xCASE(0,xGOTO(xMAKExLABEL(0)))
xCASE(1,xGOTO(xMAKExLABEL(1)))
xCASE(2,xGOTO(xMAKExLABEL(2)))
xCASE(3,xGOTO(xMAKExLABEL(3)))
xCASE(4,xGOTO(xMAKExLABEL(4)))
xCASE(5,xGOTO(xMAKExLABEL(5)))
xCASE(6,xGOTO(xMAKExLABEL(6)))
xCASE(7,xGOTO(xMAKExLABEL(7)))
xCASE(8,xGOTO(xMAKExLABEL(8)))
xCASE(9,xGOTO(xMAKExLABEL(9)))
xCASE(10,xGOTO(xMAKExLABEL(10)))
xCASE(11,xGOTO(xMAKExLABEL(11)))
xCASE(12,xGOTO(xMAKExLABEL(12)))
xCASE(13,xGOTO(xMAKExLABEL(13)))
xCASE(14,xGOTO(xMAKExLABEL(14)))
xCASE(15,xGOTO(xMAKExLABEL(15)))
xCASE(16,xGOTO(xMAKExLABEL(16)))
xCASE(17,xGOTO(xMAKExLABEL(17)))
xCASE(18,xGOTO(xMAKExLABEL(18)))
xCASE(19,xGOTO(xMAKExLABEL(19)))
xCASE(20,xGOTO(xMAKExLABEL(20)))
xCASE(21,xGOTO(xMAKExLABEL(21)))
xCASE(22,xGOTO(xMAKExLABEL(22)))
xCASE(23,xGOTO(xMAKExLABEL(23)))
xCASE(24,xGOTO(xMAKExLABEL(24)))
xCASE(25,xGOTO(xMAKExLABEL(25)))
xCASE(26,xGOTO(xMAKExLABEL(26)))
xCASE(27,xGOTO(xMAKExLABEL(27)))
xCASE(28,xGOTO(xMAKExLABEL(28)))
xCASE(29,xGOTO(xMAKExLABEL(29)))
xCASE(30,xGOTO(xMAKExLABEL(30)))
xCASE(31,xGOTO(xMAKExLABEL(31)))
xCASE(32,xGOTO(xMAKExLABEL(32)))
xCASE(33,xGOTO(xMAKExLABEL(33)))
xCASE(34,xGOTO(xMAKExLABEL(34)))
xCASE(35,xGOTO(xMAKExLABEL(35)))
xCASE(36,xGOTO(xMAKExLABEL(36)))
xCASE(37,xGOTO(xMAKExLABEL(37)))
xCASE(38,xGOTO(xMAKExLABEL(38)))
xCASE(39,xGOTO(xMAKExLABEL(39)))
xCASE(40,xGOTO(xMAKExLABEL(40)))
xCASE(41,xGOTO(xMAKExLABEL(41)))
))
xCASE(xASGN(),xASSIGNxSWITCH(xCASE(0,xGOTO(xMAKExLABEL(0)))
xCASE(1,xGOTO(xMAKExLABEL(1)))
xCASE(2,xGOTO(xMAKExLABEL(2)))
xCASE(3,xGOTO(xMAKExLABEL(3)))
xCASE(4,xGOTO(xMAKExLABEL(4)))
xCASE(5,xGOTO(xMAKExLABEL(5)))
xCASE(6,xGOTO(xMAKExLABEL(6)))
xCASE(7,xGOTO(xMAKExLABEL(7)))
xCASE(8,xGOTO(xMAKExLABEL(8)))
xCASE(9,xGOTO(xMAKExLABEL(9)))
xCASE(10,xGOTO(xMAKExLABEL(10)))
xCASE(11,xGOTO(xMAKExLABEL(11)))
xCASE(12,xGOTO(xMAKExLABEL(12)))
xCASE(13,xGOTO(xMAKExLABEL(13)))
xCASE(14,xGOTO(xMAKExLABEL(14)))
xCASE(15,xGOTO(xMAKExLABEL(15)))
xCASE(16,xGOTO(xMAKExLABEL(16)))
xCASE(17,xGOTO(xMAKExLABEL(17)))
xCASE(18,xGOTO(xMAKExLABEL(18)))
xCASE(19,xGOTO(xMAKExLABEL(19)))
xCASE(20,xGOTO(xMAKExLABEL(20)))
xCASE(21,xGOTO(xMAKExLABEL(21)))
xCASE(22,xGOTO(xMAKExLABEL(22)))
xCASE(23,xGOTO(xMAKExLABEL(23)))
xCASE(24,xGOTO(xMAKExLABEL(24)))
xCASE(25,xGOTO(xMAKExLABEL(25)))
xCASE(26,xGOTO(xMAKExLABEL(26)))
xCASE(27,xGOTO(xMAKExLABEL(27)))
xCASE(28,xGOTO(xMAKExLABEL(28)))
xCASE(29,xGOTO(xMAKExLABEL(29)))
xCASE(30,xGOTO(xMAKExLABEL(30)))
xCASE(31,xGOTO(xMAKExLABEL(31)))
xCASE(32,xGOTO(xMAKExLABEL(32)))
xCASE(33,xGOTO(xMAKExLABEL(33)))
xCASE(34,xGOTO(xMAKExLABEL(34)))
xCASE(35,xGOTO(xMAKExLABEL(35)))
xCASE(36,xGOTO(xMAKExLABEL(36)))
xCASE(37,xGOTO(xMAKExLABEL(37)))
xCASE(38,xGOTO(xMAKExLABEL(38)))
xCASE(39,xGOTO(xMAKExLABEL(39)))
xCASE(40,xGOTO(xMAKExLABEL(40)))
xCASE(41,xGOTO(xMAKExLABEL(41)))
))
/* below earm.c */ 
    case xi__conv: D1 = xPOPA();                                 
                  if (xAFSYM(D1) != xic_ap)                      
                  /* decompose a term */                         
                  {xPUSHM(xic_ap);                               
                   if ((fsym)D1 & FSYMBASE)                             
                     {xPUSHM((fsym)D1+TOKENIZE);                        
                      xPUSHM(xSLST());                           
                      xPUSHM(xELST());}                          
                   else                                          
                     {xPUSHM(xAFSYM(D1)+TOKENIZE);                      
                      xPUSHxLST(D1,1);};}                        
                  else                                           
                  /* compose a term */                           
                  {if (((fsym)xDTR(D1,1)-TOKENIZE) != xLST())
                     {xPUSHM((fsym)xDTR(D1,1)-TOKENIZE);                   
                      xPUSHxELMS(xDTR(D1,2),1);                     
                     }
                   else
                     {xPUSHM(xSLST());
                      xPUSHxELMS(xDTR(D1,2),1);
                      xPUSHM(xELST());
		    };};                                            
                  continue;                                      
    /* three character digits into single character */           
    case xi__atoc: 
                 xPUSHM((xC2I(100*(xREALFSYM((int)xARG(1)) - '0') +  
                               10*(xREALFSYM((int)xARG(2)) -'0') +     
                                1*(xREALFSYM((int)xARG(3)) - '0')
                                         )));        
                 xDROPA(3);                     
                 continue;                      
    /* single character into a list of three character digits */ 
    case xi__ctoa: 
                 xSTRTxNODE(xLST());            
                 c = xREALFSYM((int)xPOPA());              
                 xPUTxHEAP((xC2I(c/100+'0')));   
                 xPUTxHEAP((xC2I(((c % 100) / 10)+'0')));  
                 xPUTxHEAP((xC2I((c % 10)+'0')));    
                 xFNSHxNODE();                  
                 xPUSHM(xilist);                
                 continue;                      
    /* testing for a character */               
    case xi__isc: 
                  if (xISCHAR(xARG(1)))           
                  {xPUSHM(xC2I('t'));       
                  }                             
                else                            
                  {xPUSHM(xC2I('f'));       
                  };                            
                xDROPA(1);                      
                continue;                       
    /* collapsing a cons list */                
    case xi__cl:                     
                xSTRTxNODE(xLST());              
                for (D1=xPOPA(); xAFSYM(D1) != xinil; D1 = xDTR(D1,2))    
                  xPUTxHEAP(xDTR(D1,1))                                    
                xFNSHxNODE();                                             
                xPUSHM(xilist);                                           
                continue;                                                 
    case xi__o:                                                  
                xPUSHM(xSTOP());
                xPUSHM(xPOPA());
                while (((fsym)(D1 = xPOPM())) != xSTOP())
                { if (xISCHAR(D1)) {putchar(xREALFSYM(((fsym)D1)));}
                  else {if (!((unsigned long)D1 & 1)) 
                        for (c=(((struct hdr *)D1)->num); c>=1; c--) 
                          xPUSHM(xDTR(D1,c));};};
                xPUSHM(xC2I('t'));
                continue;                       
    case xSTOP(): if (WRITEGEL) {write_gel(xARG(1),MP);};break;       
    case xSLST(): xSTRTxNODE(xLST());              
                while (!((unsigned long) (D1 = xPOPA()) == xELST())) { 
                  xPUTxHEAP(D1);}             
                xFNSHxNODE();                 
                continue;                     
    default:  
                xPUSHA(D1);                   
                continue;                     
    };   /* switch */                         
    break;                        
    };    /* for */                                    
    if (!WRITEGEL) putchar('\n');                            
    exit(0);                                  
    stackxerror: error("stack overflow\n");   
    heapxerror: error("heap overflow\n");    
  }                                         

/*end earm.c*/
