/*

   ToolBus -- The ToolBus Application Architecture
   Copyright (C) 1998-2000  Stichting Mathematisch Centrum, Amsterdam, 
   The  Netherlands.

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
#include "toolbus.h"
#include "terms.h"
#include "tools.h"
#include "utils.h"
#include <netdb.h>
#include <errno.h>
#include <math.h>     /* needed for strtod (on SunOs) */

/* --------i/o buffer --------------------------------------------------

   There is one universal, extensible, buffer for input, output and
   formatting.   Its format is as follows:

   ===================================================
   ^             ^                   ^                ^
   | < LENSPEC > |                   |                |
   |
   buffer        &buffer[LENSPEC]    buf_ptr          &buffer[buf_size]

   Initially, buffer is allocated dynamically with initial size
   TB_INIT_BUFFER. Later on it may be extended (extend_buffer) dynamically.

   The first LENSPEC bytes hold the length of each incoming or outgoing
   message. The first actual data byte starts at &buffer[LENSPEC].

   buf_ptr always points at the first available byte in the buffer.

NOTE: buf_ptr has two different uses in the routines below:
(a) as pointer in buffer as just described.
(b) as pointer in format strings for TBmatch.

Rationale:
(i) the low level character reading routine (get_char) can be
the same for parsing and matching.
(ii) it is possible to parse directly from a format string (needed
to parse placeholders).

---------------------------------------------------------------------*/

char *buffer;                /* i/o buffer       */
static char *buf_ptr;               /* read and write ptr in buffer    */
/* AND in format string, see above */
static char *start_buf_ptr;         /* start value of buf_ptr, for error messages */
int buf_size = TB_INIT_BUFFER;      /* also used in sockets.c */

#define BEGIN_OF_DATA               &buffer[LENSPEC]

char this_host[MAXHOSTNAMELEN];
char single_prompt [] = "Enter term (followed by ; character):\n";

TBbool ToolBus = TBtrue;
TBbool TBverbose = TBfalse;     /* no verbose logging */
TBbool stand_alone = TBfalse; /* not running alone  */
char *tool_name = "ToolBus";

/*--- parse_term/TBmake --------------------*/

static int  lastc;               /* last char read during parse */
static char *parse_error_msg;

/*{{{  static int get_char(void) */

static int get_char(void)
{
  /* fprintf(stderr, "get_char: %c (%d)\n", *buf_ptr, *buf_ptr); fflush(stderr); */
  return lastc = *buf_ptr++;
}

/*}}}  */
/*{{{  static int unget_char(void) */

static int unget_char(void)
{
  buf_ptr -= 2;
  return lastc = *buf_ptr++;
}

/*}}}  */
/*{{{  static void skip_layout(void) */

static void skip_layout(void)
{
  while(lastc && isspace(lastc))
    get_char();
}

/*}}}  */
/*{{{  static void parse_error(char *s) */

static void parse_error(char *s)
{
#define ERR_W 25     /* "window" surrounding the error location */
  if(!parse_error_msg) {
    char msg[6+2*ERR_W+2], *msgp = msg;
    int i, imin;
    int epos = buf_ptr - start_buf_ptr - 1;

    imin = (epos < ERR_W) ? 0 : epos - ERR_W;

    buf_ptr--;
    if(imin > 0){
      msg[0] = msg[1] = msg[2] = '.';
      msgp = &msg[3];
    }
    for(i = imin; i < epos + ERR_W && start_buf_ptr[i]; i++){
      if(i == epos)
	*msgp++ = '!';
      *msgp++ = start_buf_ptr[i];
    }      
    if(i == epos)
      *msgp++ = '!';
    if(start_buf_ptr[i]){
      msgp[0] = msgp[1] = msgp[2] = '.';
      msgp += 3;
    }
    *msgp++ = '\0';
    parse_error_msg = s;
    err_warn("%s in `%s' near ! marker", s, msg);   
  }
}

/*}}}  */

va_list mk_term_args;

static term *parse_term0(void);
static term *parse_anno(term *t);

/*{{{  static TBbool is_std_fsym(char *s) */

static TBbool is_std_fsym(char *s)
{
  int c;

  c = *s++;
  if(!isalpha(c))
    return TBfalse;
  for( ; *s; c = *s++){
    if(isalnum(c) || (c == '-') || (c == '_'))
      continue;
    else
      return TBfalse;
  }
  return TBtrue;
}

/*}}}  */
/*{{{  static type *parse_type(void) */

static type *parse_type(void)
{
  skip_layout();
  if(lastc != ':')
    return mk_appl(TBlookup("term"), NULL);
  else {
    get_char();
    skip_layout();
    return parse_term0();
  }
}

/*}}}  */

/* This function should really be rolled into parse_term0. An annotation
   is an integral part of a term, parse_term0 should return exactly one parsed
   term, including an (optional) annotation. However, since parse_term0 has 27 
   return statements, I thought it a bit dangerous to mess around there. 
   parse_term0 needs probably to be rewritten completely for this to be included.
   Since parse_term0 is only called \emph{nine} times, I thought it easiest to
   add to every call to parse_term0 a call to parse_anno.
   So instead of calling 
   return parse_term0();
   you should now call 
   return parse_anno(parse_term0());
   --Tobias
   */

/*{{{  static term *parse_anno(term *t) */

static term *parse_anno(term *t)
{
  term_list args;
  term *arg;
  term *anno,*t2,*res;
  char close_char;

  if(lastc && lastc == '{') {
    /* Take a deep breath... */
    /* This is the actual annotation (which can or cannot itself be annotated).
       As in term{anno{anno'}}, since an annotation is a term. */
    /* anno = parse_anno(parse_term0()); */
    close_char = '}';
    next(&args) = NULL;
    get_char(); skip_layout();

    while(lastc != close_char){
      if(lastc == '%') {
	if(get_char() == 'l'){
	  next(&args) = 
	    list_concat(next(&args),
			va_arg(mk_term_args, term_list *));
	  get_char(); skip_layout();
	  goto list_args_seen_anno;
	} else {
	  unget_char();
	}
      }
      arg = parse_anno(parse_term0());

      next(&args) = list_concat_term(next(&args), arg);
      skip_layout();
      if(lastc == ','){
	get_char(); skip_layout(); continue;
      } else
	break;
    }
list_args_seen_anno:
    if(lastc != close_char){
      parse_error("Missing }");
      return NULL;
    } 
    get_char(); skip_layout();
    anno = next(&args);
    t2 = mk_anno(anno,t);
    /* Now, we can have _another_ annotation:
       term{anno}{anno'} */
    res = parse_anno(t2);
  } else {
    res = t;
  }
  return res;
}

/*}}}  */
/*{{{  static term *parse_term0(void) */

static term *parse_term0(void)
{
  char *begin;
  int close_char;
  sym_idx id_sym;
  type *tp;
  TBbool is_str_sym = TBfalse;

  skip_layout();
  begin = buf_ptr - 1;

  /*fprintf(stderr, "parse_term0: %s\n", buf_ptr); */
  if(isupper(lastc) || (lastc == '_')){     /* variable or formal */

    get_char();
    while(isalnum(lastc) || (lastc == '-') || (lastc == '$')) {
      get_char();
    }
    id_sym = lookupn(begin, buf_ptr-1);
    skip_layout();
    tp = parse_type();
    if(lastc == '?'){
      get_char();
      return mk_result_var_idx(id_sym, tp);
    } else if(lastc == '('){
      close_char = ')';
      goto make_list;
    } else {
      return mk_var_idx(id_sym, tp);
    }
  } else
    if(isdigit(lastc) || (lastc == '-')){ /* integer */
      int nr_digits = 0;
      int sign = 1, n = 0;
      if(lastc == '-'){
	get_char();
	sign = -1;
      }
      while(isdigit(lastc)) {
	nr_digits++;
	n = n * 10 + (lastc - '0');
	get_char();
      }
      if(lastc == '.'){
	char *endp;
	double d;
	/* Backup to start of number */
	while (nr_digits > 0) {
	  unget_char();
	  nr_digits--;
	}
	d = strtod(buf_ptr-1, &endp);
	if(endp == buf_ptr){
	  parse_error("Malformed real constant");
	  return NULL;
	}
	buf_ptr = endp;
	get_char();
	return mk_real(sign * d);
      } else
	return mk_int(sign * n);
    } else
      if(lastc == '\'' || lastc == '\\'){ /* integer as char */
	if(lastc == '\\') {
	  int c, i;
	  get_char();
	  c = lastc;
	  get_char();
	  switch(c) {
	    case 'n': return mk_int('\n');
	    case 'r': return mk_int('\r');
	    case 't': return mk_int('\t');
	    case '\\': return mk_int('\\');
	    case '0': assert(isdigit(lastc));
		      c = lastc;
		      get_char();
		      assert(isdigit(c) && isdigit(lastc));
		      i = 10*c+lastc;
		      get_char();
		      return mk_int(i);
	    default:  parse_error("illegal character constant");
	  }
	} else {
	  int i;
	  get_char();
	  i = lastc;
	  get_char();
	  return mk_int(i);
	}
      } else
	if(lastc == '"'){                   /* string */

	  get_char();
	  if(lastc == STRING_MARK){
	    int len = 0;
	    term * res;

	    /* a binary string of the form:                */
	    /* " STRING_MARK DDDDDD STRING_MARK CCCCCCCC " */
	    /*                 ^                    ^      */
	    /*                 |                    |      */
	    /*               length               chars    */

	    get_char();
	    while(isdigit(lastc)){
	      len = len * 10 + (lastc - '0');
	      get_char();
	    }
	    if(lastc != STRING_MARK)
	      parse_error("Wrong length field in binary string");
	    if(buf_ptr + len >= &buffer[buf_size]){
	      parse_error("String length exceeds buffer size");
	      return NULL;
	    }
	    /*
	       { int i;
	       fprintf(stderr, "parse-term: len =%d\n", len);
	       for(i = 0; i <= len; i++)
	       fprintf(stderr, "*(buf_ptr + %d) = %c\n", i, *(buf_ptr + i));
	       }
	       */


	    if(*(buf_ptr + len) != '"'){
	      parse_error("Binary string does not end with double quote");
	      return NULL;
	    }
	    res = mk_bstr(buf_ptr, len);
	    buf_ptr += len + 1;      /* past last " */
	    get_char();
	    return res;
	  } else {                    /* ordinary string, " already read */
	    char *str_buf, *pbuf;
	    char tmp_buf[1024];
	    int max;

	    /* IF we are reading from buffer THEN we can use it
	       as temp storage for the string to be constructed.
	       Otherwise use tmp_buf.
	       */
	    if((buf_ptr >= buffer) && (buf_ptr < &buffer[buf_size])){
	      str_buf = pbuf = buf_ptr - 1;
	      max = &buffer[buf_size] - pbuf;
	    } else {
	      str_buf = pbuf = tmp_buf;
	      max = 1024;
	    }

	    while(lastc && lastc != '"'){
	      if(pbuf - str_buf >= max){
		err_fatal("String constant too large");
	      }
	      switch(lastc)
	      {
		case '\\':
		  get_char();
		  switch(lastc)
		  {                   
		    case 'b': *pbuf++ = '\b'; break;
		    case 'f': *pbuf++ = '\f'; break;
		    case 'n': *pbuf++ = '\n'; break;
		    case 'r': *pbuf++ = '\r'; break;
		    case 't': *pbuf++ = '\t'; break;
		    case 'v': *pbuf++ = '\v'; break;		
		    case '\\': *pbuf++ = '\\'; break;
		    case '"': *pbuf++ = '"'; break;
		    case '\n': break;
		    default: *pbuf++ = lastc; break;
		  }
		  break;
		default:	    
		  *pbuf++ = lastc;
	      }
	      get_char();
	    }
	    *pbuf++ = '\0';
	    get_char();
	    skip_layout();
	    if(lastc != '(')
	      return mk_str(str_buf);          /* string constant */
	    else {                             /* string as function symbol: */
	      close_char = ')';
	      id_sym = TBlookup(str_buf);
	      is_str_sym = TBtrue;
	      goto make_list;
	    }
	  }
	} else
	  if(lastc == '['){                      /* list */
	    term_list args;
	    term *arg;

	    close_char = ']';
	    id_sym = -1; /* pedantic */
make_list:
	    next(&args) = NULL;
	    get_char(); skip_layout();

	    while(lastc != close_char){
	      if(lastc == '%') {
		if(get_char() == 'l'){
		  next(&args) = 
		    list_concat(next(&args),
				va_arg(mk_term_args, term_list *));
		  get_char(); skip_layout();
		  goto list_args_seen;
		} else {
		  unget_char();
		}
	      }
	      arg = parse_anno(parse_term0());

	      next(&args) = list_concat_term(next(&args), arg);
	      skip_layout();
	      if(lastc == ','){
		get_char(); skip_layout(); continue;
	      } else
		break;
	    }
list_args_seen:
	    if(lastc != close_char){
	      parse_error("Missing , or ] or )");
	      return NULL;
	    } else
	      get_char(); skip_layout();
	    if(close_char == ']')
	      return next(&args);
	    else {
	      term *t = mk_appl(id_sym, next(&args));
	      fun_str_sym(t) = is_str_sym;
	      return t;
	    }
	  } else
	    if(islower(lastc)){            /* application */

	      get_char();
	      while(isalnum(lastc) || (lastc == '-')) {
		get_char();
	      }
	      id_sym = lookupn(begin, buf_ptr-1);
make_args:
	      skip_layout();
	      if(lastc == '('){
		close_char = ')';
		goto make_list;
	      } else {
		term *t = mk_appl(id_sym, NULL);
		fun_str_sym(t) = is_str_sym;
		return t;
	      }
	    } else
	      if(lastc == '%'){   /* insert term from
				     TBmake's arguments */
		int c, n;
		char * str;

		c = get_char();
		get_char(); skip_layout();
		switch(c){
		  case 'B':
		    return mk_int(va_arg(mk_term_args, TBbool));
		  case 'd':               
		    return mk_int(va_arg(mk_term_args, int));
		  case 'r':
		    return mk_real(va_arg(mk_term_args, double));
		  case 's':
		    return mk_str(va_arg(mk_term_args, char *));
		  case 'b':
		    str = va_arg(mk_term_args, char *);
		    n = va_arg(mk_term_args, int);
		    return mk_bstr(str, n);
		  case 't':
		    return va_arg(mk_term_args, term *);
		  case 'f':
		    str = va_arg(mk_term_args, char *);
		    id_sym = TBlookup(str);
		    is_str_sym = !is_std_fsym(str);
		    goto make_args;
		  case 'l':
		    return va_arg(mk_term_args, term_list *);	
		  default:
		    parse_error("Illegal character follows percent character");
		    return NULL;
		} 
	      } else if(lastc == '<'){
		type *tp;
		get_char();
		tp = parse_anno(parse_term0());
		if(!tp)
		  return NULL;
		skip_layout();
		if(lastc == '>'){
		  get_char();
		  return mk_placeholder(tp);
		} else{
		  parse_error("Placeholder does not end with `>'");
		  return NULL;
		}
	      } else {
		parse_error("Unexpected character");
		return NULL;
	      }
	    return NULL;
}

/*}}}  */
/*{{{  term *parse_term(void) */

term *parse_term(void)
{
  term *res;

  parse_error_msg = NULL;
  get_char();
  res = parse_anno(parse_term0());
  skip_layout();
  /* return res; */
  if(lastc){
    parse_error("Syntax error");
    return NULL;
  } else {
    return res;
  }
}

/*}}}  */

static void extend_buffer();

/*{{{  term *TBmake(char * fmt, ...) */

term *TBmake(char * fmt, ...)
{
  term * res;
  int n;

  va_start(mk_term_args, fmt);

  n = strlen(fmt);

  if(n >= buf_size)
    extend_buffer(0, n);

  memcpy(buffer, fmt, n+1);
  start_buf_ptr = buf_ptr = buffer;

  /* fprintf(stderr, "TBmake %s\n", fmt); */
  parse_error_msg = NULL;
  get_char();
  res = parse_anno(parse_term0());
  va_end(mk_term_args);
  skip_layout();
  /* return res; */
  if(lastc) {
    parse_error("Syntax error");
    return NULL; 
  } else
    return res;
}

/*}}}  */

/*{{{  term *TBread(int fd) */

term *TBread(int fd)
{
  term *trm;
  if(multi_read(fd) <= 0)
    return NULL;
  if((trm = parse_buffer()))
    return trm;
  else
    return NULL;
}

/*}}}  */
/*{{{  term *TBreadTerm(FILE *f) */

term *TBreadTerm(FILE *f)
{
  register int c;
  register char *ptr;
  term *trm;

  ptr = &buffer[LENSPEC];
  while ((c = fgetc(f)) != EOF){
    if(ptr + 2 > &buffer[buf_size]){
      int fill = ptr - buffer;
      extend_buffer(fill, fill + TB_BUF_INCR);
      ptr = &buffer[fill];
    }
    *ptr++ = c;
  }
  *ptr++ = '\0';  /* ptr + 2, above, ensures there is room for this \0 */
  if(ptr - &buffer[LENSPEC] > 0){
    trm = parse_buffer();
    if(trm)
      return trm;
  }
  return NULL;
}

/*}}}  */

/*{{{  int read_from_stdin() */

int read_from_stdin()
{
  int c;
  char *ptr;

  ptr = &buffer[LENSPEC];

  /* This call to clearerr solves a problem on NETBSD. It's a hack,
   * because we don't know why it solves the problem
   */ 
  clearerr(stdin); 

  while((c = fgetc(stdin)) != '\n' ){
    if(c > 0){
      *ptr++ = c;
    } 
  }
  *ptr++ = '\0';

  return (ptr - &buffer[LENSPEC]) - 1;
}

/*}}}  */

/*{{{  term *read_and_parse_from_stdin(term *prompt, term *pat) */

term *read_and_parse_from_stdin(term *prompt, term *pat)
{ int n; 
  term *trm;

  while(TBtrue){
    TBprintf(stderr, "%t %t: ", prompt, pat); 
    /*
       pr_term_unquoted(prompt);
       printn(" ", 1);
       pr_term_unquoted(pat);
       printn(": ", 2);
       */
    n = read_from_stdin();
    if(n > 0){
      trm = parse_buffer();
      if(trm)
	return trm;
    }
  }
  return NULL; /* <PO> lcc complained about 'missing return value' */
}

/*}}}  */

/*{{{  term *parse_buffer(void) */

term *parse_buffer(void)
{
  term * trm;

  start_buf_ptr = buf_ptr = BEGIN_OF_DATA;

  skip_layout();

  if((trm = parse_term())){
    if(TBverbose)
      TBmsg("receive: %t\n", trm);
    return trm;
  }
  fprintf(stderr, "term ignored: \"%s\"\n", BEGIN_OF_DATA); 
  return NULL;
}

/*}}}  */

/*{{{  static void extend_buffer(int fill, int needed) */

static void extend_buffer(int fill, int needed)
{
  char *newbuffer;

  /* fprintf(stderr, "extend_buffer: %d, %d, %d\n", fill, buf_size, needed); */

  assert((fill <= buf_size) && (needed > 0) && (needed > buf_size));

  while(buf_size < needed)
    buf_size += TB_BUF_INCR;
  newbuffer = (char *) malloc(buf_size);
  if(!newbuffer)
    err_sys_fatal("extend_buffer: can't malloc");
  memcpy(newbuffer, buffer, fill); 
  free(buffer);
  buffer = newbuffer;
  /* fprintf(stderr, "extend_buffer: done\n"); */
}

/*}}}  */

/*{{{  int multi_read(int fd)  */

int multi_read(int fd) 
{
  int len, cnt;

  /*TBmsg("multi_read: try to read %d bytes from port %d\n", MIN_MSG_SIZE, fd);*/
  cnt = mread(fd, buffer, MIN_MSG_SIZE); /* was buf_size, LENSPEC+1 */

  /* TBmsg("multi_read: cnt = %d\n", cnt); */
  if(cnt <= 0){
    if(cnt != 0) {
      fprintf(stderr, "cnt = %d\n", cnt);
      err_sys_warn("multi_read, cannot read");
    }
    return cnt;
  }
  if(cnt <= LENSPEC)
    return -1;

  if(sscanf(buffer, "%d:", &len) != 1){
    int i;
    TBmsg("Ignore message (no length indication): %s\n", buffer);
    TBmsg("cnt = %d\n", cnt);
    for(i = 0; i < cnt; i++)
      fprintf(stderr, "buffer[%d] = %c\n", i, buffer[i]);
    return -1;
  }
  /* TBmsg("len = %d\n", len); */

  if(len > buf_size)
    extend_buffer(cnt, len);

  if(len <= cnt){
    buf_ptr = &buffer[len];
    *buf_ptr = '\0';
    goto ret;
    /* return len; */
  }

  buf_ptr = &buffer[cnt];
  cnt = mread(fd, buf_ptr, &buffer[len] - buf_ptr); /* was: buf_size */
  if(cnt <= 0)
    return -1;
  buf_ptr += cnt;
  *buf_ptr = '\0'; /* CHECK */
ret:
  /*
     { int i;
     fprintf(stderr, "<<<");
     for(i = 0; i < len; i++)
     fprintf(stderr, "%c", buffer[i]);
     fprintf(stderr, ">>>\n");
     fprintf(stderr, "buf_ptr - buffer = %d, len = %d\n",
     buf_ptr-buffer, len);
     }
     */
  return len;
}

/*}}}  */
/*{{{  int mread(int fd, char *buf, int len) */

int mread(int fd, char *buf, int len)
{
  int cnt = 0, n;
  /* TBmsg("mread(%d, %d)\n", fd, len); */

  while(cnt < len){
    if((n = read(fd, &buf[cnt], len - cnt)) <= 0) {
      if(errno != EINTR)
	return n;
    } else
      cnt += n;
    /* TBmsg("mread: cnt := %d\n", cnt); */
  }

  assert(cnt == len);
  return cnt;
}

/*}}}  */
/*{{{  int mwrite(int fd, char *buf, int len) */

int mwrite(int fd, char *buf, int len)
{
  int cnt = 0, n;

  while(cnt < len) {
    if((n = write(fd, &buf[cnt], len-cnt)) <= 0) {
      if(errno != EINTR)
	return n;
    } else
      cnt += n;
  }
  assert(cnt == len);
  return cnt;
}

/*}}}  */


/*--- TBwrite ------------------------------*/

/* Writing to the buffer or directly to file ? */
static TBbool toBuffer = TBfalse;

/* Current output file */
static FILE *toFile = NULL;

/*{{{  void TBwrite(int out, term *t) */

void TBwrite(int out, term *t)
{
  if(t) {
    int len;

    buf_ptr = BEGIN_OF_DATA;
    toBuffer = TBtrue;
    memset(buf_ptr, ' ', MIN_MSG_SIZE);
    pr_term(t);
    *buf_ptr = '\0';

    toBuffer = TBfalse;
    len = buf_ptr - buffer;

    if(len <= 0){
      TBmsg("zero or negative len in write_buffer\n");
    }
    sprintf(buffer, "%-.*d", LENSPEC-1, len);
    buffer[LENSPEC-1] = ':';
    len = (len < MIN_MSG_SIZE) ? MIN_MSG_SIZE : len;
    /* TBmsg("TBwrite: %d -- %s\n", len, buffer); */
    if(mwrite(out, buffer, len) < 0)
      err_sys_warn("TBwrite: write failed");
  }
}

/*}}}  */

/*{{{  void printn(const char *s, int n) */

void printn(const char *s, int n)
{
  if(toBuffer){
    assert((buf_ptr > buffer) && (buf_ptr <= &buffer[buf_size]));
    if(buf_ptr + n > &buffer[buf_size]){   
      int fill = buf_ptr - buffer;
      extend_buffer(fill, fill + n);
      buf_ptr = &buffer[fill];
    }
    memcpy(buf_ptr, s, n);
    buf_ptr += n;
  } else {
    while(n){
      fputc(*s++, toFile ? toFile : stderr);
      n--;
    }
  }    
}

/*}}}  */

/*--- TBprintf/TBmsg----------------------------*/

/*{{{  void gen_printf(const char *fmt, va_list args) */

void gen_printf(const char *fmt, va_list args)
{
  const char *p, *sval;
  int ival;
  double rval;
  char ibuf[16];
  term *trm;
  term_list *tl;

  for(p = fmt; *p; p++){
    if(*p != '%'){
      printn(p, 1);
      continue;
    }
    switch(*++p){
      case 'd':
	ival = va_arg(args, int);
	sprintf(ibuf, "%d", ival);
	printn(ibuf, strlen(ibuf));
	break;
      case 'r':
	rval = va_arg(args, double);
	sprintf(ibuf, "%f", rval);
	printn(ibuf, strlen(ibuf));
	break;     
      case 's':
      case 'f':
	sval = va_arg(args, char *);
	if(!sval)
	  printn("(null)", 6);
	else
	  printn(sval, strlen(sval));
	break;
      case 'b':
	sval = va_arg(args, char *);
	ival = va_arg(args, int);
	print_bstr(sval, ival);
	break;
      case 't':
	trm = va_arg(args, term *);
	if(!trm)
	  printn("[]", 2);
	else
	  pr_term_unquoted(trm);
	/* pr_term(trm); */
	break;
      case 'l':
	tl = va_arg(args, term_list *);
	pr_term_list(tl);
	break;
      default:
	printn(p, 1);
	break;
    }
  }
}

/*}}}  */

/*--- tbgen_printf -----------------------------*/

/* Implements the ``printf'' atom in scripts,
   Contributed by Pieter Olivier
   */

/* <P>: It's a pity tkind and pkind aren't synchronized,
   because then we could have used 'get_text' instead of this
   special function to get the string representation of a type.
   */
/*{{{  char *type_string(tkind kind) */

char *type_string(tkind kind)
{
  static char *types[] =
  { "term", "bool", "int", "real", "str", "bstr", "var",
    "placeholder", "appl", "env", "list"
  };

  if(kind >= t_term && kind <= t_list)
    return types[kind];

  return "unknown";
}

/*}}}  */

/*{{{  void tbgen_printf(const char *fmt, term_list *args) */

void tbgen_printf(const char *fmt, term_list *args)
{
  const char *p, *sval;
  int ival;
  double rval;
  char ibuf[16];
  term *trm, *arg;
  term_list *tl;
#define NXT_ARG \
  if(!args) \
  { \
    err_warn("Too few in arguments in printf: `%s'\n", fmt); \
      return; \
  } \
  arg = first(args); args = next(args); 

#define NEXT_ARG(f,t) \
  NXT_ARG \
    if(!f(arg)) \
    { \
      err_warn("Illegal type in printf `%s', expected %s, got %s\n", \
	       fmt, t, type_string(arg->trm_kind)); \
	return; \
    }

  for(p = fmt; *p; p++){
    if(*p != '%'){
      printn(p, 1);
      continue;
    }
    switch(*++p){
      case 'd':
	NEXT_ARG(is_int,"int")
	  ival = int_val(arg);
	sprintf(ibuf, "%d", ival);
	printn(ibuf, strlen(ibuf));
	break;
      case 'r':
	NEXT_ARG(is_real,"real");
	rval = real_val(arg);
	sprintf(ibuf, "%f", rval);
	printn(ibuf, strlen(ibuf));
	break;     
      case 's':
      case 'f':
	NEXT_ARG(is_str,"str");
	sval = str_val(arg);
	if(!sval)
	  printn("(null)", 6);
	else
	  printn(sval, strlen(sval));
	break;
      case 'b':
	/* <P> We might want "bstr" here? */
	NEXT_ARG(is_str,"str");
	sval = str_val(arg);
	NEXT_ARG(is_int,"int");
	ival = int_val(arg);
	print_bstr(sval, ival);
	break;
      case 't':
	NXT_ARG;
	trm = arg;
	if(!trm)
	  printn("[]", 2);
	else
	  pr_term_unquoted(trm);
	break;
      case 'l':
	NEXT_ARG(is_list,"list");
	tl = arg;
	pr_term_list(tl);
	break;
      default:
	printn(p, 1);
	break;
    }
  }
  if(args)
    err_warn("Warning: too many arguments in printf %s\n", fmt);
}

/*}}}  */

/*--- TBprintf ---------------------------------*/

/*{{{  void TBprintf(FILE *f, char *fmt, ...) */

void TBprintf(FILE *f, char *fmt, ...)
{
  va_list args;

  toBuffer = TBfalse;
  toFile = f;
  va_start(args, fmt);
  gen_printf(fmt, args);
  va_end(args);
  toFile = stderr;
  fflush(f);
}

/*}}}  */
/*{{{  void TBvprintf(FILE *f, char *fmt, va_list args) */

void TBvprintf(FILE *f, char *fmt, va_list args)
{
  toFile = f;
  gen_printf(fmt, args);
  toFile = stderr;
  fflush(f);
}

/*}}}  */
/*{{{  char *TBvsprintf(char *fmt, va_list args) */

char *TBvsprintf(char *fmt, va_list args)
{
  start_buf_ptr = buf_ptr = BEGIN_OF_DATA;
  toBuffer = TBtrue;
  gen_printf(fmt, args);
  *buf_ptr++ = '\0';
  return BEGIN_OF_DATA;
}

/*}}}  */
/*{{{  char *TBsprintf(char *fmt, ...) */

char *TBsprintf(char *fmt, ...)
{
  va_list args;

  start_buf_ptr = buf_ptr = BEGIN_OF_DATA;
  toBuffer = TBtrue;
  va_start(args, fmt);
  gen_printf(fmt, args);
  va_end(args);
  *buf_ptr++ = '\0';
  return BEGIN_OF_DATA;

}

/*}}}  */

/*--- TBmsg ------------------------------------*/

/*{{{  void TBmsg(char *fmt, ...) */

void TBmsg(char *fmt, ...)
{
  va_list args;

  toBuffer = TBfalse;
  toFile = stderr;
  va_start(args, fmt);
  fprintf(stderr, "%12s -- ", tool_name);
  gen_printf(fmt, args);
  va_end(args);
  fflush(stderr);
}

/*}}}  */

/*--- TBmatch ----------------------------------*/

va_list match_args;
term *anno=NULL;

TBbool TBmatch1(term *);

/* match_anno(term *) matches 0 or more annotations to a term. It should be called after TBmatch1, usually in the form: 
   result = TBmatch1(t) && match_anno(t)

   The structure of match_anno() is very similar to that of parse_anno().

   --Tobias */

/*{{{  TBbool match_anno(term *t) */

TBbool match_anno(term *t)
{
  TBbool res;
  term_list *tl;
  char close_char;
  term_list **ptl;

  skip_layout();
  if (lastc && is_anno(t) ) {
    /* We might have a nested annotation */
    res = match_anno(anno_term(t));
    if (res == TBfalse) {
      return TBfalse;
    }
    /* Proceed with the actual annotation (a term). The annotation could
       also be annotated */
    if (lastc=='{') {
      if(!is_list(anno_val(t))){
	return TBfalse;
      }
      tl = anno_val(t);
      close_char = '}';
      get_char();
      do {
	skip_layout();
	if(lastc == '%' && buf_ptr[0] == 'l'){
	  ptl = va_arg(match_args, term_list **);
	  *ptl = tl;
	  get_char(); get_char();
	  break;
	}
	if(tl){
	  if(!(TBmatch1(first(tl))&& match_anno(first(tl))))
	    return TBfalse;
	  else {
	    skip_layout();
	    if(lastc == ',')
	      get_char();
	    else {
	      if(next(tl))
		return TBfalse;	      
	    }
	    tl = next(tl);	  
	  }
	} else
	  break;
      } while (TBtrue);

      { TBbool res;
	skip_layout();
	res = (lastc == close_char) ? TBtrue : TBfalse;
	get_char();
	return res;
      } 
    } else return TBtrue;
  } else return TBtrue;
}

/*}}}  */
/*{{{  TBbool TBmatch(term *t, char *fmt, ...) */

TBbool TBmatch(term *t, char *fmt, ...)
{
  TBbool res;

  va_start(match_args, fmt);
  start_buf_ptr = buf_ptr = fmt;
  get_char();
  res = TBmatch1(t) && match_anno(t);
  skip_layout();
  if(lastc){
    /* TBmsg("TBmatch: unread chars ``%s''\n", buf_ptr-1); */
    res = TBfalse;
  }
  va_end(match_args);


  /* TBmsg("TBmatch(%t,\"%s\",...) returns %s\n", t, fmt, (res) ? "true" : "false"); */

  return res;
}

/*}}}  */

/*{{{  TBbool TBmatch1(term *t) */

TBbool TBmatch1(term *t)
{
  char **ps, *q;
  int *pi;
  TBbool *pb;
  double *pr;
  term **pt;
  term_list *tl;
  term_list **ptl;
  int close_char;

  skip_layout();

  while (is_anno(t) ) {
    t = anno_term(t);
  }

  switch(lastc){
    case '%':
      get_char();
      switch(lastc){
	case 's':             /* string */
	  if(!is_str(t))
	    return TBfalse;
	  else {
	    ps = va_arg(match_args, char **);
	    *ps = str_val(t);
	    get_char();
	    return TBtrue;
	  }

	case 'b':              /* binary string */
	  if(!is_bstr(t))
	    return TBfalse;
	  else {         
	    ps = va_arg(match_args, char **);
	    *ps = bstr_val(t);
	    pi = va_arg(match_args, int *);
	    *pi = bstr_len(t);
	    get_char();
	    return TBtrue;
	  }
	case 'd': 
	  if(tkind(t) != t_int)
	    return TBfalse;
	  else {
	    pi = va_arg(match_args, int *);
	    *pi = int_val(t);
	    get_char();
	    return TBtrue;
	  }
	case 'B':
	  if(tkind(t) != t_bool)
	    return TBfalse;
	  else {
	    pb = va_arg(match_args, TBbool *);
	    *pb = bool_val(t);
	    get_char();
	    return TBtrue;
	  }
	case 'r': 
	  if(tkind(t) != t_real)
	    return TBfalse;
	  else {
	    pr = va_arg(match_args, double *);
	    *pr = real_val(t);
	    get_char();
	    return TBtrue;
	  }
	case 't':
	  pt = va_arg(match_args, term **);
	  *pt = t;
	  get_char();
	  return TBtrue;
	case 'f':
	  if(!is_appl(t))
	    return TBfalse;
	  ps = va_arg(match_args, char **);
	  *ps = get_txt(fun_sym(t));
	  skip_layout();
	  get_char();
	  goto match_args;
	default:
	  { char msg[2];
	    msg[0] = lastc; msg[1] = '\0';
	    err_fatal("TBmatch -- illegal format %%%s", msg);
	  }
      }
    case '"':
      /* -- must be a (binary) string -- */
      { char *sval;
	int i, n;

	if(is_str(t)){
	  sval = str_val(t);
	  n = strlen(sval);
	} else if(is_bstr(t)){
	  sval = bstr_val(t);
	  n = bstr_len(t);
	} else if(is_appl(t)){
	  sval = get_txt(fun_sym(t));
	  n = strlen(sval);
	} else
	  return(TBfalse);
	for(i = 0; i < n; i++){

fetch_next:
	  get_char();

	  if(lastc == '\\'){
	    get_char();
	    switch(lastc)
	    {	      
	      case 'b': lastc = '\b'; break;
	      case 'f': lastc = '\f'; break;
	      case 'n': lastc = '\n'; break;
	      case 'r': lastc = '\r'; break;
	      case 't': lastc = '\t'; break;
	      case 'v': lastc = '\v'; break;		
	      case '\\': lastc = '\\'; break;
	      case '"': lastc = '"'; break;
	      case '\n': goto fetch_next;
	      default: break;
	    }
	  }
	  if(sval[i] != lastc)
	    return TBfalse;
	}
	get_char();
	if(lastc == '"'){
	  get_char();
	  skip_layout();
	  if(is_appl(t)){
	    if(lastc != '(')
	      return fun_args(t) ? TBfalse : TBtrue;
	    close_char = ')';
	    tl = fun_args(t);
	    goto match_list;
	  } else
	    return TBtrue;
	} else
	  return TBfalse;
      }
    case '0': case '1': case '2': case '3':
    case '4': case '5': case '6': case '7':
    case '8': case '9': case '-':
      /* -- must be an integer -- */
      { int sign = 1, n = 0;
	if(!is_int(t))
	  return(TBfalse);
	if(lastc == '-'){
	  sign = -1;
	  get_char();
	}	  
	while(isdigit(lastc)){
	  n = n * 10 + (lastc - '0');
	  get_char();
	}
	return (sign * n == int_val(t)) ? TBtrue : TBfalse;
      }
    case '<':
      {
	type *rt;

	get_char();
	skip_layout();
	rt = parse_anno(parse_term0());
	if(lastc != '>' || !rt)
	  return TBfalse;
	get_char();
	return require_type(rt, t) ? TBtrue : TBfalse;
      }

    case '[':
      if(!is_list(t))
	return TBfalse;
      close_char = ']';
      tl = t;

match_list:

      get_char();
      do {
	skip_layout();
	if(lastc == '%' && buf_ptr[0] == 'l'){
	  ptl = va_arg(match_args, term_list **);
	  *ptl = tl;
	  get_char(); get_char();
	  break;
	}
	if(tl){
	  if(!(TBmatch1(first(tl))&& match_anno(first(tl))))
	    return TBfalse;
	  else {
	    skip_layout();
	    if(lastc == ',')
	      get_char();
	    else {
	      if(next(tl))
		return TBfalse;	      
	    }
	    tl = next(tl);	  
	  }
	} else
	  break;
      } while (TBtrue);

      { TBbool res;
	skip_layout();
	res = (lastc == close_char) ? TBtrue : TBfalse;
	get_char();
	return res;
      }

    default:
      if(isupper(lastc) || (lastc == '_')){  /* variable or formal */
	if(!(is_var(t)))
	  goto match_appl;
	else {
	  for(q = get_txt(var_sym(t)); *q; q++){
	    if(*q != lastc){
	      return TBfalse;
	    } else
	      get_char();
	  }
	  skip_layout();
	  if(lastc != ':'){
	    return term_equal(var_type(t), Term) ? TBtrue : TBfalse;
	  } else {
	    char type_name[20], *tn = type_name;
	    type *rt;

	    get_char();
	    skip_layout();
	    while(islower(lastc)){
	      *tn++ = lastc;
	      get_char();
	    }
	    *tn++ = '\0';
	    if(streq(type_name, "bool"))
	      rt = Bool;
	    else if(streq(type_name, "int"))
	      rt = Int;
	    else if(streq(type_name, "str"))
	      rt = Str;
	    else if(streq(type_name, "bstr"))
	      rt = Bstr;
	    else if(streq(type_name, "list"))
	      rt = List;
	    else if(streq(type_name, "term"))
	      rt = Term;
	    else {
	      err_warn("TBmatch: wrong type definition following variable");
	      return TBfalse;
	    }
	    return term_equal(var_type(t), rt) ? TBtrue : TBfalse;
	  }
	}
      } else if(isalpha(lastc)){
	/* -- must be function symbol -- */
	/* -- but permit symbols starting with uppercase */
match_appl:
	if(!is_appl(t))
	  return TBfalse;
	for(q = get_txt(fun_sym(t)); *q; q++){
	  if(*q != lastc){
	    return TBfalse;
	  } else
	    get_char();
	}

match_args:
	skip_layout();
	if(lastc != '(')
	  return fun_args(t) ? TBfalse : TBtrue;
	close_char = ')';
	tl = fun_args(t);
	goto match_list;
      } else
	return TBfalse;
  }
  return TBfalse;
}

/*}}}  */
/*{{{  int TBsize(term *t) */

int TBsize(term *t)
{
  int size = sizeof(*t);
  /*int size = 1;*/

  if(!t)
    return 0;

  switch(tkind(t)) {
    case t_bool:
    case t_int:
    case t_real:
      break;

    case t_str:
      size += strlen(str_val(t))+1;
      break;

    case t_bstr:
      size += bstr_len(t);
      break;

    case t_appl:
      /* <PO> symbol size */
      size += TBsize(fun_args(t));
      break;

    case t_list:
      size += TBsize(first(t));
      size += TBsize(next(t));
      break;

    case t_var:
      /* <PO>: symbol size? */
      size += TBsize(var_type(t));
      break;

    case t_placeholder:
      size += TBsize(placeholder_type(t));
      break;

    case t_anno:
      size += TBsize(anno_val(t));
      size += TBsize(anno_term(t));
      break;

    case t_env:
      /* <PO>: symbol size? */
      size += TBsize(env_var(t));
      size += TBsize(env_val(t));
      size += TBsize(env_next(t));
      break;

  }
  return size;
}

/*}}}  */

#ifndef HAVE_STRERROR
/*{{{  char *strerror(int n) */

char *strerror(int n)
{
  extern char *sys_errlist[];

  return sys_errlist[n];
}

/*}}}  */
#endif

static void err_doit(int, const char *, va_list);

/* Non-fatal error related to a system call.
 * Print a message and return.
 */
/*{{{  void err_sys_warn(const char *fmt, ...) */

void err_sys_warn(const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  err_doit(1, fmt, ap);
  va_end(ap);
}

/*}}}  */

/* Fatal error related to a system call.
 * Print a message and exit.
 */
/*{{{  void err_sys_fatal(const char *fmt, ...) */

void err_sys_fatal(const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  err_doit(1, fmt, ap);
  va_end(ap);
  TBexit(1);
}

/*}}}  */

/* Non-fatal error unrelated to a system call.
 * Print a message and return.
 */
/*{{{  void err_warn(const char *fmt, ...) */

void err_warn(const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  err_doit(0, fmt, ap);
  va_end(ap);
  return;
  /*
     if(ToolBus)
     return;
     else
     TBexit(1);
     */
}

/*}}}  */

/* Fatal error unrelated to a system call.
 * Print a message and exit.
 */
/*{{{  void err_fatal(const char *fmt, ...) */

void err_fatal(const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  err_doit(0, fmt, ap);
  va_end(ap);
  /* abort(); */
  TBexit(1);
}

/*}}}  */

/*{{{  static void err_doit(int errnoflag, const char *fmt, va_list ap) */

static void err_doit(int errnoflag, const char *fmt, va_list ap)
{
  int errno_save = errno; /* save errno to be printed */
  char buf[1024];

  toBuffer = TBtrue;
  buf_ptr = BEGIN_OF_DATA;
  gen_printf(fmt, ap);
  *buf_ptr++ = '\0';
  strcpy(buf, BEGIN_OF_DATA);

  if(errnoflag)
    sprintf(buf+strlen(buf), " (%s)", strerror(errno_save));
  strcat(buf, "\n");

  fflush(stdout); /* in case stdout and stderr are the same */
  fprintf(stderr, "%s: ", tool_name);
  fputs(buf, stderr);

  fflush(stderr);
  /*  fflush(NULL);   flushes all stdio output streams */
  return;
}

/*}}}  */

/* exit/atexit replacements */

#define MAX_EXIT_ENTRIES 32

static void (*exit_table[32])(void);
static unsigned exit_entries = 0;

/*{{{  void TBexit(int val) */

void TBexit(int val)
{
  int i;

  /* Call registered exit functions. */
  for(i=exit_entries-1; i>=0; i--)
    (*exit_table[i])();

  /* Call the `original' exit function */
  exit(val);
}

/*}}}  */
/*{{{  int  TBatexit(void (*f)(void)) */

int TBatexit(void (*f)(void))
{
  if(exit_entries >= MAX_EXIT_ENTRIES)
    return -1;

  exit_table[exit_entries++] = f;
  return 0;
}

/*}}}  */
/*{{{  void init_utils() */

void init_utils()
{
  buffer = (char *) malloc(buf_size);
  if(!buffer)
    err_sys_fatal("init_utils -- can't malloc");
}

/*}}}  */

