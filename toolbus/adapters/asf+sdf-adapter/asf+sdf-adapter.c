#line 2 "asf+sdf-adapter.c.nw"
/* 
 * asf+sdf-adapter -- Adapter for the connection ToolBus <-> compiled Asf+Sdf specification
 *
 * Synopsis: asf+sdf-adapter [-TB_TOOL_NAME N] [-ascii-gel] [-result R] 
 *                           [-details D] [-cmd CMD1 ...]
 *
 * where
 * N    is the toolname to be used (only used by TBmsg).
 * R    is the desired format of the resulting ToolBus term. The possible values for R are:
 *          gel (default)
 *          term
 * CMD1 ...  is the command to be invoked (with its arguments).
 * D    is a string giving details of the mapping between ToolBus terms and Gel (see below).
 *
 * Author:        Paul Klint, September/December, 1994.
 * Last Revision: March 1995.
 *
 * March 24 1995, Pieter Olivier:
 * - Added %b directive in details section
 * March 29 1995, Pieter Olivier:
 * - Added %l directive in details section
 * - Added %s directive in details section
 * March 31 1995, Pieter Olivier:
 * - Added expandable buffer code.
 * - Added variable store mechanism (@var)
 * Mon May  8 11:32:35 MET DST 1995, Pieter Olivier:
 * - Added removal of whitespace after SDF definition
 *   (I was bitten twice by a space at the end of a SDF definition, resulting
 *    in an 'unknown function or abbreviation' error from the compiled spec.)
 * Wed May 17 13:12:05 MDT 1995: paulk
 * - Added -help
 * Thu May 18 23:04:50 MDT 1995: paulk
 * - repaired rec-terminate case in handle_input_from_toolbus
 *
 * Purpose: Adapter for executing compiled Asf+Sdf specifications.
 * Incoming messages:
 *    rec-terminate(%t)
 *    snd-eval(input(gel(%b)))
 *    snd-eval(input(%t))
 *    snd-do(store(gel(%b)), %s))
 *    snd-do(store(input(%t), %s))
 *    snd-eval(get-variable(%s))
 *    snd-do(set-variable(%s,%t))
 *
 * Replies:
 *    snd-value(gel(%s)), when asf+sdf-adapter was called with ``-result gel''
 *    snd-value(term(%t)), when  asf+sdf-adapter was called with ``-result term''
 *    snd-value(variable(%s,%t)), result of get-variable
 *
 * [Note: i/o redirection is currently done using files]
 *
 * Architecture:
 *
 *         ================== ToolBus
 *           |           ^
 *           v           |    (sockets)
 *         +------------------+
 *         |  asf+sdf-adapter |
 *         +------------------+
 *           |           ^
 *           |           |
 *           |  +------+ |
 *           +->| Spec |-+    (standard input/output)
 *              +------+
 *
 * with Spec a compiled ASF+SDF specification
 *
 */

#include "TB.h"
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>

#include "gel.h"

#define GDEBUG(s) {}

int cmd_pid;                /* process ID of cmd process */
char *tmp_in  ="tmp_in";    /* temp file name for cmd input */
char *tmp_out = "tmp_out";  /* temp file name for cmd output */

char **cmd_text;           /* string array denoting the actual coomand */

enum format {GEL, TERM, TEXT};
enum format result_format = GEL; /* desired result format */

#define ABBREV_LIST 11 /* Abbreviation number of list constructor */
#define ABBREV_CHAR 12 /* Base abbreviation for characters */
#define ABBREV_BASE ABBREV_CHAR+256 /* Base abbreviation for functions */

TBbool ascii_gel = TBfalse;
TBbool debug_on  = TBtrue;
TBbool list_defined = TBfalse;  /* l0 not defined yet */
TBbool char_defined[256] =  /* Which characters already have an abbreviation? */
{TBfalse};
/* ANSI standard states that this array will now be filled with 0's (=TBfalse) */

/* ------------- expandable buffer declarations ----------------- */

/* The expandable buffers can be very simple, because we only add
   to them. This means we can do with a singly linked list of blocks.
*/

#define BLOCK_SIZE 2048

typedef struct block
{
  struct block *next;
  char *data;
} block;

typedef struct
{
  int block_size;
  block *first;
  block *cur_block;
  int cur_index;
} buffer;

buffer *buffer_init(int BlockSize);
int buffer_add(buffer *Buf, char *Data, int Bytes);
int buffer_add_one(buffer *Buf, char c);
int buffer_add_string(buffer *Buf, char *s);
int buffer_add_bc_nat(buffer *Buf, int Nat);
int buffer_add_ac_nat(buffer *Buf, int Nat);
int buffer_add_bstr(buffer *Buf, term *t);
term *buffer_to_bstr(buffer *Buf);
int buffer_size(buffer *Buf);
int buffer_write(buffer *Buf, int File);
void buffer_destroy(buffer *Buf);

/* --------------- Variable handling declarations ---------------- */

#define MAX_VARS 256

int vars_insert(char *Name, term *Val);
term *vars_get_value(char *Name);

/********************* tb <-> gel conversion ****************************/

static void error(char *msg)
{ fprintf(stderr,"%s\n",msg);
  exit(1);
}

/* ---------------  Function mapping ---------------------*/

#define MAXFUN 128

enum dir {  in=1,    /* in input signature */
	    out=2,   /* in output signature */
	    inout=3  /* in both signatures */
	  };

struct fun_map {
  enum dir  d;      /* direction */
  char *tb_form;    /* ToolBus form of the term */
  sym_idx func;     /* Toplevel function name */
  char *sdf_form;   /* SDF form of the term */
  TBbool isdef;     /* Is this SDF form defined already? */
} tb2sdf [MAXFUN+1];

/* Example fun_map:
 {
  inout  true         Booleans: true -> BOOL
  inout  false        Booleans: false -> BOOL
  in     and(%t,%t)   Booleans: and(BOOL, BOOL) -> BOOL
 };
*/

int nfun;          /* # of functions in map */

/* declare a table for correspondence between types and names */
gel_table bool_types;

/* Since gel_types must be non-zero, gel_type N will correspond with
   entry N-1 in tb2sdf */

bool is_in(gel_type n)    /* is n in input signature? */
{
  return tb2sdf[n-1].d & in;
}

bool is_out(gel_type n)   /* is n in output signature? */
{
  return tb2sdf[n-1].d & out;
}

static char *get_tb_form(gel_type n)
{
  return tb2sdf[n-1].tb_form;
}

static enum dir get_dir(gel_type n) { return tb2sdf[n-1].d; }

static char *get_sdf_form(gel_type n)
{
  char *str = tb2sdf[n-1].sdf_form;
  GDEBUG(TBmsg("get_sdf_form(%d) = %s\n", n, str);)
  return str;
}

static sym_idx get_func(int n)
{
  return tb2sdf[n-1].func;
}

static TBbool is_defined(int n)
{
  return tb2sdf[n-1].isdef;
}

static int get_arity(gel_type n)
{
  char *fmt = get_tb_form(n);
  int ar = 0;

  while(*fmt)
    if(*fmt++ == '%')
      ar++;
  return ar;
}

void print_fun_map(gel_type n)
{
  fprintf(stderr, "%d; %s; %s\n", get_dir(n), get_tb_form(n), get_sdf_form(n));
}

/* read the function map and initalize tb2sdf */
/* !! improve syntax check of table */

void read_details(char *details)
{
  char *ptr, *line = details, dir_str[32], tb_form[128], sdf_form[128];
  enum dir dir;
  int i;

  nfun = 0;
  while(line){ 
    while(isspace(*line))
      line++;
    if(! *line)
      break;
    if(sscanf(line, "%[^ \t] %[^ \t] %[^\n]", dir_str, tb_form, sdf_form) != 3)
      err_fatal("error in tb_form/sdf_form: %s", line);

    if(streq(dir_str, "in"))
      dir = in;
    else if(streq(dir_str, "out"))
      dir = out;
    else if(streq(dir_str, "inout"))
      dir = in | out;
    else
     err_fatal("error in details, dir = %s\n", dir_str);
    
    tb2sdf[nfun].d = dir;
    tb2sdf[nfun].tb_form = strdup(tb_form);
    tb2sdf[nfun].sdf_form = strdup(sdf_form);

    /* Remove trailing whitespace from sdf_form */
    for(ptr=tb2sdf[nfun].sdf_form; *ptr; ptr++);
    for(ptr--; isspace(*ptr); ptr--);
    *(++ptr) = '\0';

    tb2sdf[nfun].isdef = TBfalse;

    ptr = strchr(tb_form, '(');
    if(ptr)
      *ptr = '\0';
    tb2sdf[nfun].func = TBlookup(tb_form);
    if(ptr)
      *ptr = '(';

    nfun++;
    line = strpbrk(line, "\n");    
  }

  /* initialize table */
  for(i = 1; i <= nfun; i++){
    gel_table_insert(&bool_types, get_sdf_form(i), i);
    GDEBUG(print_fun_map(i);)
  }
}

gel_type define(int ar, int tsize, char* type)
{  gel_type t;

   
   GDEBUG(fprintf(stderr, "define -- %s %d %d\n", type, tsize, strlen(type));)
   if (t= gel_table_get(&bool_types,type)) return t;
   else error("unknown type");
}

gel_node build(gel_type t, int ar,
               gel_node child[])
{ 
  if(t > nfun)
     error("unknown type");
  if(ar != get_arity(t))
            error("build: wrong arity");
  if(!is_out(t))
    fprintf(stderr, "%s not in out signature\n", get_sdf_form(t));
  return (gel_node) TBmake(get_tb_form(t),
			       child[0], child[1], child[2],
			       child[3], child[4], child[5]);
}

static struct _gel_rcfg RC = {
  define, build, NULL, error
};

void here(char *msg)
{ fprintf(stderr, "%s\n", msg);
}

static gel_type gtype(gel_node n)
{
  int i;
  term *trm = n, *t1, *t2, *t3, *t4, *t5;

  GDEBUG(TBmsg("gtype(%t) ", trm);)
  for(i = 1; i <= nfun; i++){
    if(TBmatch(trm, get_tb_form(i), &t1, &t2, &t3, &t4, &t5)){
      if(!is_in(i))
	fprintf(stderr, "%s not in input signature\n", get_sdf_form(i));
      GDEBUG(TBmsg(" ... %d\n", i);)
      return i;
    }
  }
  TBmsg("gtype; wrong node");
}

static int tsize(gel_type t)
{ int i = strlen(get_sdf_form(t));
  GDEBUG(TBmsg("tsize(%d) = %d\n", t, i);)
  return i;
}

static int size(gel_node n)
{
  int i =  get_arity(gtype(n));
  term *trm = n;

  GDEBUG(TBmsg("size(%t) = %d\n", trm, i);)
  return i;
}

static gel_node child(gel_node n, int c)
{
  term *ch[6];
  int t = gtype(n);
  term *trm = n;

  GDEBUG(TBmsg("child(%t,%d)\n", trm, c);)
  if(c >= get_arity(t))
    error("wrong child index");

  if(!TBmatch((term *)n, get_tb_form(t),
	      &ch[0], &ch[1], &ch[2], &ch[3], &ch[4], &ch[5]))
     error("child: TBmatch fails");
  return ch[c];
}

static struct _gel_wcfg WC = {
  gtype, get_arity, tsize, get_sdf_form, size,
  child, error, NULL, NULL
};

/********************* handle_input_from_toolbus ***********************/

void exec_cmd(buffer *);

/*
static unsigned char output[10000];
*/
buffer *input, *output;
char Tmp[128];

void strrev(char *s)
{
  int c,i,j;

  for (i=0,j=strlen(s)-1; i < j; i++,j--)
    {
      c = s[i];
      s[i] = s[j];
      s[j] = c;
    }
}

/* Print a number in binary ASCII, contributed
   by Mark v.d. Brand.
*/
void itob(int i, char *Buf)
{
  int j;

  j = 0;
  if (i == 0) {
    Buf[j++] = '0';
  };
  while (i > 0) {
    Buf[j++] = (i%2 == 0) ? '0' : '1';
    i = i / 2;
  };
  Buf[j] = '\0';
  strrev(Buf);
}

void invalidate_isdefs()
{
  int i;

  for(i=0; i<nfun; i++)
    tb2sdf[i].isdef = TBfalse;

  for(i=0; i<256; i++)
    char_defined[i] = TBfalse;

  list_defined = TBfalse;
}

/* We encountered a ToolBus node that is already in
   gel format. Just write the gel representation. */
void write_gel_term(buffer *Buf, term *Term)
{
  char *bstr;
  int Len;

  if(!(TBmatch(Term, "gel(%b)", &bstr, &Len)))
    {
      TBprintf(stderr, "Gel term should be of the form 'gel(%b)', and not %t\n",
	       Term);
      return;
    }
  buffer_add(Buf, bstr, Len);
  if (ascii_gel)
    buffer_add_one(Buf, '\0');
}

void write_gel(buffer *Buf, term *T);

/* Define a generic list node (only if not already defined) */
void define_list_node(buffer *Buf)
{
  if(!list_defined)
    {
      if(ascii_gel)
	{
	  buffer_add_string(Buf, "!l0:*=|\n");
	  list_defined = TBtrue;
	}
      else
	{
	  /* Binary gel */
	  buffer_add_one(Buf, 1);
	  buffer_add_bc_nat(Buf, ABBREV_LIST);
	  buffer_add_one(Buf, 1);
	  buffer_add_one(Buf, '|');
          list_defined = TBtrue;
	}
    }
}

/* Write a gel list by first writing al elements of
   the list and then writing a 'variadic arity' gel node. */
buffer *write_list_term(buffer *Buf, term *Term)
{
  term *Cur = Term;

  /* First, write all nodes */
  while(Cur)
    {
      write_gel(Buf, first(Cur));
      Cur = next(Cur);
    }

  /* Next, write the list node */
  define_list_node(Buf);
  if(ascii_gel)
    {
      buffer_add_string(Buf, "l0 ");
      buffer_add_ac_nat(Buf, length_list(Term));
      buffer_add_string(Buf, "\n");
    }
  else
    {
      /* Binary gel */
      buffer_add_bc_nat(Buf, ABBREV_LIST);
      buffer_add_bc_nat(Buf, length_list(Term));
    }
}

/* Write a lexical element */
void write_lexical(buffer *Buf, term *T)
{
  char *s, bin[65];
  int len;

  switch(tkind(T))
    {
    case t_str:
      s = str_val(T);
      break;

    case t_appl:
      if(!fun_args(T))
	s = get_txt(fun_sym(T));
      else
	{
	  TBprintf(stderr, 
		   "Only constant functions can act as a lexical element!\n");
	  return;
	}
      
    default:
      TBprintf(stderr, 
	       "Only strings and constant functions can form a lexical element!\n");
      return;
    }
  len = strlen(s);
  define_list_node(Buf);
  /* A strange quirk in gel: ASCII gel is actually more efficient
     for lexical constructs!!! */
  if(ascii_gel)
    {
      for(; *s; s++)
	{
	  buffer_add_one(Buf, '\'');
	  buffer_add_one(Buf, *s);
	  buffer_add_one(Buf, '\n');
	}
      buffer_add_string(Buf, "!l0:*=|\nl0 ");
      buffer_add_ac_nat(Buf, len);      
      buffer_add_string(Buf, "\n");
    }
  else
    {
      /* Binary gel */
      for(; *s; s++)
	{
	  if(!char_defined[*s])
	    {
	      /* Build character abbreviation */
	      buffer_add_one(Buf, 0); /* Introduce abbreviation */
	      buffer_add_bc_nat(Buf, ABBREV_CHAR+*s);
	      buffer_add_one(Buf, 0); /* Arity of constant = 0 */
	      buffer_add_one(Buf, 2);    /* constant size = 2 */
	      buffer_add_one(Buf, '\'');
	      buffer_add_one(Buf, *s);
	      char_defined[*s] = TBtrue;
	    }
	  buffer_add_bc_nat(Buf, ABBREV_CHAR+*s);
	}
      buffer_add_one(Buf, ABBREV_LIST);
      buffer_add_one(Buf, len);
    }
}

term *arg_from_toolbus(buffer *Buf, char *Fmt, term *Args)
{
  if(!Args)
    {
      TBprintf(stderr, "asf+sdf-adapter -- error: ran out of arguments at " \
	       "format specifier %s\n", Fmt);
    }

  switch(*Fmt)
    {
    case 't':
      write_gel(Buf, first(Args));
      break;
      
    case 'b':
    case 'g':
      write_gel_term(Buf, first(Args));
      break;
      
    case 'l':
      if(tkind(first(Args)) != t_list)
	TBmsg("error: %l directive needs list (%t)\n",
	      first(Args));
      write_list_term(Buf, first(Args));
      Args = NULL;
      break;
      
    case 's':
      write_lexical(Buf, first(Args));
      break;
      
    default:
      fprintf(stderr, "Illegal format specifier in details: %c\n",
	      *Fmt);
      exit(1);
      break;
    }
  if(Args)
    Args = next(Args);
  
  return Args;
}

#define MAX_VAR_LENGTH 64

void arg_from_store(buffer *Buf, char *Fmt)
{
  char Name[MAX_VAR_LENGTH+1], *ptr;
  int Size;
  term *Val;

  assert(Fmt[1] = '@');
  ptr = &Fmt[2];
  if(!isalpha(*ptr))
    {
      TBmsg("Store variable should start with a letter: %s\n", Fmt);
      exit(1);
    }
  Size = 0;
  while(Size < MAX_VAR_LENGTH && isalpha(*ptr) || isdigit(*ptr) 
	|| *ptr == '_' || *ptr == '-')
    Name[Size++] = *ptr++;
  Name[Size] = '\0';

  Val = vars_get_value(Name);  
  
  switch(*Fmt)
    {
    case 't':
      write_gel(Buf, Val);
      break;
      
    case 'b':
    case 'g':
      /*TBprintf(stderr, "xxx: %t\n", Val);*/
      if(tkind(first(fun_args(Val))) != t_bstr)
	{
	  TBmsg("error: \%\b directive needs gel(<bstr>) (%t)\n", Val);
	  exit(1);
	}
      write_gel_term(Buf, Val);
      break;
      
    case 'l':
      if(!is_list(Val))
	{
	  TBmsg("error: %%l directive needs list (%t)\n", Val);
	  exit(1);
	}
      write_list_term(Buf, Val);
      break;
      
    case 's':
      write_lexical(Buf, Val);
      break;
      
    default:
      fprintf(stderr, "Illegal format specifier in details: %c\n",
	      *Fmt);
      exit(1);
      break;
    }
}


/* Translate a ToolBus term into gel */
void write_gel(buffer *Buf, term *T)
{
  char *Fmt, *bstr;
  char Bin[64+1]; /* Ready to take on 64 bit gel! (only if int==64 bits) */
  term *Args;
  int i, Len, Arity;
  char *ptr;
  TBbool is_list = TBfalse;

  if(tkind(T) != t_appl)
    TBprintf(stderr,"Only applications allowed in term->gel translation (%t)\n",
	    T);
  /*TBprintf(stderr, "write_gel %t\n", T);*/

  for(i=1; i<=nfun; i++)
    {
      /* Find the table entry connected with the current function */
      if(fun_sym(T) == get_func(i))
      {
	/* We found the right table entry */
	/*TBprintf(stderr, "Function %d (%d) = %s (%s)\n", 
		 fun_sym(T), i, get_txt(fun_sym(T)), get_tb_form(i));*/
	Args = fun_args(T);
	Arity = 0;
	/* First, visit children */
	for(Fmt = get_tb_form(i); *Fmt; Fmt++)
	  {
	    if(*Fmt == '%')
	      {
		Arity++;
		Fmt++;
		if(Fmt[1] == '@')
		  arg_from_store(Buf, Fmt);
		else
		  Args = arg_from_toolbus(Buf, Fmt, Args);
	      }
	  }
	/* Now, dump node itself */
	if(!is_defined(i))
	  if(ascii_gel)
	    {
	      itob(Arity, Bin);
	      sprintf(Tmp, "!a%d:%s=", i, Bin);
	      buffer_add_string(Buf, Tmp);
	      buffer_add_string(Buf, get_sdf_form(i));
	      buffer_add_string(Buf, "\n");
	      tb2sdf[i-1].isdef = TBtrue;
	      GDEBUG(fprintf(stderr, "define %d\n", i);)
	    }
	  else
	    {
	      GDEBUG(fprintf(stderr, "Abbreviation: %d=%s\n", i, get_sdf_form(i));)
	      buffer_add_one(Buf, 0);  /* Introduce abbreviation */
	      buffer_add_bc_nat(Buf, i+ABBREV_BASE);
	      buffer_add_bc_nat(Buf, Arity);
	      buffer_add_bc_nat(Buf, strlen(get_sdf_form(i)));
	      buffer_add(Buf, get_sdf_form(i), strlen(get_sdf_form(i)));
	      tb2sdf[i-1].isdef = TBtrue;
	    }
	GDEBUG(else
	  fprintf(stderr, "%d is defined\n", i);)
	
	if(ascii_gel)
	  {
	    sprintf(Tmp, "a%d\n", i);
	    buffer_add_string(Buf, Tmp);
	  }
	else
	  buffer_add_bc_nat(Buf, i+ABBREV_BASE);
     
	if(debug_on) {
	  int File = open("test.out", O_RDWR|O_CREAT|O_TRUNC);
	  if(File < 0)
	    perror("File open: ");
	  buffer_write(Buf, File);
	  close(File);
	}
	
	return;
      }
    }
  TBmsg("Sorry, can't find a match for function %s\n", get_txt(fun_sym(T)));
}


term *handle_input_from_toolbus(term *e)
{
  unsigned char *txt;
  char *cname, msg[512];
  int r, status, c;
  FILE *from_cmd;
  term *in_trm, *out_trm, *arg, *Result;
  char *var;
  term *value;
  int inp_len, i;
  char *store_var = NULL;

  input  = buffer_init(BLOCK_SIZE);
  output = buffer_init(BLOCK_SIZE);

  if(TBmatch(e, "rec-terminate(%t))", &arg)){
    unlink(tmp_in);
    unlink(tmp_out); 
    exit(0);
  } else if(TBmatch(e, "rec-eval(get-variable(%s))", &var)){
    value = vars_get_value(var);
    return TBmake("snd-value(variable(%s,%t))", var, value);
  } else if(TBmatch(e, "rec-do(set-variable(%s,%t))", &var, &value)){
    vars_insert(var, value);
    return NULL;
  } else if(TBmatch(e, "rec-eval(input(gel(%t)))", &in_trm)){
    buffer_add_bstr(input, in_trm);
    goto exec_cmd;
  } else if(TBmatch(e, "rec-do(store(input(gel(%t)),%s))", &in_trm, &var)){
    store_var = var;
    buffer_add_bstr(input, in_trm);
    goto exec_cmd;
  } else if(TBmatch(e, "rec-eval(input(%t))", &in_trm)){
    invalidate_isdefs();
    write_gel(input, in_trm);
    goto exec_cmd;
  } else if(TBmatch(e, "rec-do(store(input(%t), %s))", &in_trm, &var)){
    store_var = var;
    invalidate_isdefs();
    write_gel(input, in_trm);
    
  exec_cmd:
    exec_cmd(input);
    buffer_destroy(input);
    
  while ((r = wait(&status)) != cmd_pid && r != -1)
    fprintf(stderr, "wait = %d\n", r);  
    
  if((from_cmd = fopen(tmp_out, "r")) == NULL)
    err_sys_fatal("opening tmp output file");
    
    memset((void *)msg, 0, sizeof((void *) msg));
    
  if(result_format == GEL){
    GDEBUG(fprintf(stderr, "asf+sdf-adapter: GEL OUTPUT\n");)
      while((c = fgetc(from_cmd)) != EOF){
	buffer_add_one(output, c);
      }
    fclose(from_cmd);
    if(store_var)
      {
	term *Gel, *BStr;
	Result = NULL; /* snd-do */
        BStr = buffer_to_bstr(output);
	Gel = TBmake("gel(%t)", BStr);
	/*fprintf(stderr, "Gel=%p, len=%d (=%d)\n", Gel, BStr->u.bstr.bstr_len,
		Gel->u.appl.args->u.list.first->u.bstr.bstr_len);*/
	vars_insert(store_var, Gel);
      }
    else
      Result = TBmake("snd-value(output(gel(%t)))", buffer_to_bstr(output));
  } else {
    GDEBUG(fprintf(stderr, "asf+sdf-adapter: TERM OUTPUT\n"););
    out_trm = gel_read(from_cmd, &RC);
    /*out_trm = read_gel(from_cmd);*/
    fclose(from_cmd);
    if(store_var)
      {
	Result = NULL;
	vars_insert(store_var, out_trm);
      }
    else
      Result = TBmake("snd-value(output(%t))", out_trm);
  }
  } else { 
    TBmsg("Ignore: %t\n", e);
    Result = NULL;
  }
  buffer_destroy(output);
  
  return Result;
}
 
#define READ 0
#define WRITE 1
void exec_cmd(buffer *inp)
{
  int old_stdin, old_stdout, fd_to_cmd, i;

  old_stdin = dup(0);
  old_stdout = dup(1);

  if((fd_to_cmd = creat(tmp_in, 0777)) < 0)
    err_sys_fatal("creating tmp input file");

  if(buffer_write(inp, fd_to_cmd) < 0)
    err_sys_fatal("write to tmp input file");

/*  GDEBUG(TBmsg("written to cmd %d bytes\n", inp_len);
	 for(i = 0; i < inp_len; i++)
	 fprintf(stderr, "%c (%d) ", inp[i], inp[i]);
	 fprintf(stderr, "\n");)
*/

  if(close(fd_to_cmd) < 0)
    err_sys_fatal("close tmp input file");
  
  close(0); close(1);

  if(open(tmp_in, O_RDONLY) < 0)
    err_sys_fatal("opening tmp input file");

  if(creat(tmp_out, 0777) < 0)
    err_sys_fatal("creating tmp output file");

  if((cmd_pid = fork())){
    /* adapter: the parent */
    if(cmd_pid < 0)
      err_sys_fatal("Can't fork");
    close(0); close(1);
    dup(old_stdin);
    dup(old_stdout);
    close(old_stdin);
    close(old_stdout); 
  } else {
    /* cmd: the child */
    if(execvp(cmd_text[0], cmd_text) < 0)
      err_sys_fatal("Can't execute %s", cmd_text[0]);
  }
}

/* -------------------- Buffer management ------------------------*/

int buffer_expand(buffer *Buf);

/* Initialize an expandable buffer.
   Return NULL when out of memory */
buffer *buffer_init(int BlockSize)
{
  buffer *New;
  block *First;
  char *Space;

  New   = malloc(sizeof(buffer));

  if(!New)
     {
       /* Out of memory */
       #ifndef NDEBUG
       fprintf(stderr, "Out of memory in buffer_init (block size = %d bytes)\n", BlockSize);
       #endif
       return NULL;
     }
  New->block_size = BlockSize;
  New->first      = NULL;
  New->cur_block  = NULL;

  /* Allocate first block */
  buffer_expand(New);

  return New;
}

/* Add bytes to a buffer, expand when necessary.
   Return -1 when out of memory. */
int buffer_add(buffer *Buf, char *Data, int Bytes)
{
  int i;
  block *Cur = Buf->cur_block;
  GDEBUG(fprintf(stderr, "buffer_add: %d, %s\n", Bytes, Data);)
  for(i=0; i<Bytes; i++)
    {
      if(Buf->cur_index == Buf->block_size)
	{
	  if(buffer_expand(Buf) < 0)
	    return -1; /* Out of memory */
	}
      Buf->cur_block->data[Buf->cur_index++] = Data[i];
    }
  return 0;
}

int buffer_add_one(buffer *Buf, char c)
{
  /*fprintf(stderr, "buffer_add_one: %c\n", c);*/
  if(Buf->cur_index == Buf->block_size)
    {
      if(buffer_expand(Buf) < 0)
	return -1; /* Out of memory */
    }
  Buf->cur_block->data[Buf->cur_index++] = c;
  return 0;
}

int buffer_add_string(buffer *Buf, char *s)
{
  return buffer_add(Buf, s, strlen(s));
}

int buffer_add_bc_nat(buffer *Buf, int Nat)
{
  char Binary[65];
  char *Ptr = gel_bc_snat(Nat, Binary);
  return buffer_add(Buf, Binary, Ptr-Binary);
}

int buffer_add_ac_nat(buffer *Buf, int Nat)
{
  char Binary[65];
  itob(Nat, Binary);
  return buffer_add_string(Buf, Binary);
}

int buffer_add_bstr(buffer *Buf, term *t)
{
  assert(tkind(t) == t_bstr);

  return buffer_add(Buf, bstr_val(t), bstr_len(t));
} 

term *buffer_to_bstr(buffer *Buf)
{
  /* Yucc! we're out of luck here. we have to try and
     secure a block of memory big enough to hold the whole buffer
     contents.
  */
  int Size = buffer_size(Buf);
  char *Data = malloc(Size);
  int Index = 0;
  block *Cur;

  if(!Data)
    {
      TBmsg("Out of memory!\n");
      exit(1);
    }
  /* Copy the contents of Buf to the newly allocated memory */
  Cur = Buf->first;

  while(Cur != Buf->cur_block)
    {
      assert(Cur);
      memcpy(&Data[Index], Cur->data, Buf->block_size);
      Index += Buf->block_size;
      Cur = Cur->next;
    }
  memcpy(&Data[Index], Cur->data, Buf->cur_index);
  Index += Buf->cur_index;

  /* Now we need to build a bstr term */
  return mk_bstr(Data, Index);
}

int buffer_size(buffer *Buf)
{
  block *Cur = Buf->first;
  int Size = 0;

  while(Cur != Buf->cur_block)
    {
      assert(Cur);
      Size += Buf->block_size;
      Cur = Cur->next;
    }
  Size += Buf->cur_index;

  return Size;
}

/* Expand the expandable buffer. The last block has to be full! */
int buffer_expand(buffer *Buf)
{
  /* Allocate a new block */
  block *New = malloc(sizeof(block));
  char *Data = malloc(Buf->block_size);

  /* Check that the last block is full ! */
  assert(!Buf->first || Buf->cur_index == Buf->block_size);
  /*fprintf(stderr, "buffer_expand\n");*/
  if(!(Data && New))
    {
      /* Out of memory */
      #ifndef NDEBUG
      fprintf(stderr, "Out of memory in buffer_extend (block size = %d)\n", Buf->block_size);
      #endif
      return -1;
    }
  New->next  = NULL;
  New->data  = Data;

  if(Buf->cur_block)
    Buf->cur_block->next = New; /* Not the first block */
  else
    Buf->first = New;           /* The first block */

  Buf->cur_block = New;
  Buf->cur_index = 0;

  return NULL;
}

/* Write the contents of an expandable buffer to file */
int buffer_write(buffer *Buf, int File)
{
  block *Cur = Buf->first;
  while(Cur != Buf->cur_block)
    {
      assert(Cur);
      if(write(File, Cur->data, Buf->block_size) < 0)
	return -1;
      Cur = Cur->next;
    }
  
  if(Buf->cur_index)
    return write(File, Cur->data, Buf->cur_index);

  return 0;
}

/* Destroy an expandable buffer */
void buffer_destroy(buffer *Buf)
{
  block *Prev, *Cur = Buf->first;

  while(Cur)
    {
      free(Cur->data);
      Prev = Cur;
      Cur = Cur->next;
      free(Prev);
    }
  free(Buf);
}

/* ---------------------- Variable handling --------------------- */

typedef struct
{
  char *name;
  term **value;
} variable;

variable Store[MAX_VARS];
int NrVars = 0;

int vars_insert(char *Name, term *T)
{
  int i;

  for(i=0; i<NrVars; i++)
    if(strcmp(Name, Store[i].name) == 0)
      break;

  if(i<NrVars)
    {
      TBunprotect(Store[i].value);
      (*Store[i].value) = T;
    }
  else
    {
      if(NrVars == MAX_VARS)
	return -1;
      Store[i].name = strdup(Name);
      Store[i].value = malloc(sizeof(term *));
      (*Store[i].value) = T;
      NrVars++;
    }
  TBprotect(Store[i].value);
  return 0;
}

term *vars_get_value(char *Name)
{
  int i;

  for(i=0; i<NrVars; i++)
    if(strcmp(Name, Store[i].name) == 0)
      break;

  if(i<NrVars)
    {
      /*TBprintf(stderr, "get_value %s = %t\n", Name, Store[i].value);*/
      return *Store[i].value;
    }

  /*TBprintf(stderr, "get_value %s = NULL\n", Name);*/
  return NULL;
}

#include <signal.h>

void interrupt_handler(int sig){
  unlink(tmp_in);
  unlink(tmp_out);
  kill(0, SIGKILL);  /* is this drastic?? */
/*  kill(cmd_pid, SIGKILL); */
/*  kill(cmd_pid+1, SIGKILL); */
  exit(-1);
}

void help(void)
{
  char * str =
"\n\
Synopsis: asf+sdf-adapter [options]\n\
\n\
Options are:\n\
-help                 print this message\n\
-ascii-gel            read/write ascii gel (default: binary gel)\n\
-debug-on             temporary debugging flag\n\
-result gel|term      format of resulting normal form: gel or ToolBus term\n\
-details S            details describing the ToolBus <-> SDF mapping\n\
-cmd C1 ...           execute C1 ... to reduce a term\n";
  fprintf(stderr, str);
}

void main(int argc, char *argv[])
{
  int i = 0;
  char *name = "asf+sdf-adapter";
  char *details = "";         /* string repr of function mapping */

  while(i < argc){
    if(streq(argv[i], "-help")){
      help();  
    } else if(streq(argv[i], "-ascii-gel")) {
      ascii_gel = TBtrue;
    } else if(streq(argv[i], "-debug-on")) {
      debug_on = TBtrue;
      fprintf(stderr, "Debugging output is written to test.out\n");
    } else if(streq(argv[i], "-result")){
      if(streq(argv[i+1], "gel")){
	result_format = GEL;
      } else if(streq(argv[i+1], "term")){
	result_format = TERM;
      } else
	fprintf(stderr, "%s: -result %s illegal \n", argv[0], argv[i+1]);
      i++;
    } else if(streq(argv[i], "-details")){
      details = argv[i+1]; i++;
    } else if(streq(argv[i], "-cmd")){
      cmd_text = &argv[i+1];
      break;
    }
    i++;
  } 

  TBinit(name, argc, argv, handle_input_from_toolbus, NULL);

  if(!cmd_text)
    err_fatal("-cmd argument missing");

  signal(SIGINT, interrupt_handler);
  signal(SIGKILL, interrupt_handler);
  signal(SIGTERM, interrupt_handler);
  tmp_in = tempnam(NULL, name); 
  tmp_out = tempnam(NULL, name);

  read_details(details);
  TBeventloop();
}
