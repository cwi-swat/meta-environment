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
%{                              /* -*-C-*- mode */
#include "TB.h"
#include "script.h"
#include "y.tab.h"

char *last_lex;      /* last lexical token read */
void ll_inc_pos(int);
void ll_coords(int,int);

void switch_source(char *name, int n);
%}

layout        [ \t\r]
comment       "%%".*
linedir       "#".*\n
ws            {layout}|{comment}
id            [a-z][A-Za-z0-9\-]*
name          [A-Z_][A-Za-z0-9\-]*
int           -?[0-9]+
real          -?[0-9]+"."[0-9]+([eE][-+]?[0-9]+)?
%%
\n            { lino++; pos = 0;}
{ws}          { ll_inc_pos(strlen(yytext)); }
{linedir}     { int n; char name[512];
                if(sscanf(yytext, "# %d \"%[^\"]\"", &n, name) < 1){
		  if(TBverbose)
		    TBmsg("Skipping line directive: %s\n", yytext);
		  /* yyerror("Unrecognized line directive"); */
		 } else
		   switch_source(strdup(name), n);
              }
snd-msg       { ll_inc_pos(7); return(SND_MSG); }   
rec-msg       { ll_inc_pos(7); return(REC_MSG); }   
snd-note      { ll_inc_pos(8); return(SND_NOTE); }  
rec-note      { ll_inc_pos(8); return(REC_NOTE); }  
no-note       { ll_inc_pos(7); return(NO_NOTE); }
subscribe     { ll_inc_pos(9); return(SUBSCRIBE); }  
unsubscribe   { ll_inc_pos(11);return(UNSUBSCRIBE); }  
printf        { ll_inc_pos(6); return(PRINTF); }  
read          { ll_inc_pos(4); return(READ); }  
rec-event     { ll_inc_pos(9); return(REC_EVENT); } 
snd-ack-event { ll_inc_pos(13);return(SND_ACK_EVENT); } 
snd-eval      { ll_inc_pos(8); return(SND_EVAL); }
snd-cancel    { ll_inc_pos(10);return(SND_CANCEL); }
snd-do        { ll_inc_pos(6); return(SND_DO); }    
rec-value     { ll_inc_pos(9); return(REC_VALUE); } 
toolbus       { ll_inc_pos(7); return(TOOLBUS); }   
process       { ll_inc_pos(7); return(PROCESS); }
is            { ll_inc_pos(2); return(IS); }
delta         { ll_inc_pos(5); return(DELTA); }     
tau           { ll_inc_pos(3); return(TAU); }     
tool          { ll_inc_pos(4); return(TOOL); }   
host          { ll_inc_pos(4); return(HOST); }   
command       { ll_inc_pos(7); return(COMMAND); } 
details       { ll_inc_pos(7); return(DETAILS); } 
create        { ll_inc_pos(6); return(CREATE); }
rec-connect   { ll_inc_pos(11);return(REC_CONNECT); }
rec-disconnect { ll_inc_pos(14);return(REC_DISCONNECT); }
execute       { ll_inc_pos(7); return(EXECUTE); }
snd-terminate { ll_inc_pos(13);return(SND_TERMINATE); }
shutdown      { ll_inc_pos(8); return(SHUTDOWN); }
if            { ll_inc_pos(2); return(IF); }
then          { ll_inc_pos(4); return(THEN); }
else          { ll_inc_pos(4); return(ELSE); }
fi            { ll_inc_pos(2); return(FI); }
:=            { ll_inc_pos(2); return(ASSIGN); }
\|\|          { ll_inc_pos(2); return(FMERGE); }
delay         { ll_inc_pos(5); return(REL_DELAY); }
abs-delay     { ll_inc_pos(9); return(ABS_DELAY); }
timeout       { ll_inc_pos(7); return(REL_TIMEOUT); }
abs-timeout   { ll_inc_pos(11);return(ABS_TIMEOUT); }
let           { ll_inc_pos(3);return(LET); }
in            { ll_inc_pos(2);return(IN); }
endlet        { ll_inc_pos(6);return(ENDLET); }
"\""          { char strbuf[512], *ptr = strbuf;
		int c, blino = lino, bpos = pos;

		pos++; /* initial quote */
		while((c = input()) != '"'){
		  if(c <= 0)
		    yyerror("String constant not terminated at eof");
		  if(ptr == &strbuf[512]){
		    yyerror("String constant too long");
		  }
		  if(c == '\\'){
		    pos += 2;
		    switch(c = input()){
	
/*		    case 'a': *ptr++ = '\a'; continue; */
		    case 'b': *ptr++ = '\b'; continue;
		    case 'f': *ptr++ = '\f'; continue;
		    case 'n': *ptr++ = '\n'; continue;
		    case 'r': *ptr++ = '\r'; continue;
		    case 't': *ptr++ = '\t'; continue;
		    case 'v': *ptr++ = '\v'; continue;
		    case '\\': *ptr++ = '\\'; continue;
		    case '"': *ptr++ = '"'; continue;
		    case '\n': lino++; pos = 0; continue;
		    default:
		      *ptr++ = c;
		      continue;  
		    }
		  } else {
		    *ptr++ = c;		   
		    if(c == '\n'){
		      lino++; pos = 0;
		    } else
		      pos++;
		  }
		}
		pos++; /* final quote */
		*ptr++ = '\0';
                yylval.u.string = strdup(strbuf);
		ll_coords(blino, bpos);
		/* fprintf(stderr, "string = \"%s\"\n", yylval.u.string); */
                return(STRING);
              }

"<<"          { char strbuf[5*1024], *ptr = strbuf;
		int c, c2,blino = lino, bpos = pos;

		while((c = input())){
		  if(c <= 0)
		    yyerror("Details not terminated at eof");
		  if(ptr == &strbuf[5*1024]){
		    yyerror("Details too long");
		  }
		  *ptr++ = c;
		  if(c == '\n'){
		    lino++;
		    while((c = input()) && isspace(c))
			  ;
		    if(c == '>'){
		      if((c2 = input()) && (c2 == '>'))
			break;
		      else {
			unput(c2); unput(c);
		      }
		    } else
		      unput(c);
		    continue;  
		  }
		}	
		*ptr++ = '\0';
                yylval.u.string = strdup(strbuf);
		ll_coords(blino, bpos);
                return(DETAILS_STRING);
	      }
{real}        { 
		ll_inc_pos(strlen(yytext));
               yylval.u.string = strdup(yytext);
               return(REAL);
              }
{int}         { 
		ll_inc_pos(strlen(yytext));
               yylval.u.string = strdup(yytext);
               return(INT);
              }
{id}          { 
               ll_inc_pos(strlen(yytext));
               yylval.u.string = strdup(yytext);
               return(IDENT);
              }
{name}        { 
	       ll_inc_pos(strlen(yytext));
               yylval.u.string = strdup(yytext);
               return(NAME);
              }
.             { ll_inc_pos(1); return(yytext[0]);}
%%
char msg[100];

void ll_inc_pos(int n)
{
  last_lex = yytext;
  /*  fprintf(stderr, "ll_inc_pos: %s\n", yytext); */
  yylval.lino = yylval.elino = lino;
  yylval.pos = pos;
  pos += n;
  yylval.epos = pos;
}

void ll_coords(int blino, int bpos)
{
  yylval.lino = blino; yylval.pos = bpos;
  yylval.elino = lino; yylval.epos = pos;
}

char *get_token(int tk)
{
  switch(tk){
  case IDENT:
    sprintf(msg, "id \"%s\"", last_lex);
    return msg;
  case NAME:
    sprintf(msg, "name \"%s\"", last_lex);
    return msg;
  case INT:
    sprintf(msg, "int \"%s\"", last_lex);
    return msg;
  case STRING:
    sprintf(msg, "string \"%s\"", last_lex);
    return msg;
  case SND_MSG: case REC_MSG:
  case SND_NOTE: case REC_NOTE: case NO_NOTE:
  case REC_EVENT: case SND_ACK_EVENT:
  case SND_EVAL: case SND_CANCEL: case SND_DO: case REC_VALUE:
  case TOOLBUS: case PROCESS: case IS: case DELTA: case TAU:
  case TOOL: case HOST: case COMMAND: case CREATE:
  case REC_CONNECT: case REC_DISCONNECT: case EXECUTE:
  case SND_TERMINATE: case SHUTDOWN:
  case IF: case THEN: case ELSE: case FI: case ASSIGN:
  case REL_DELAY: case ABS_DELAY: case REL_TIMEOUT: case ABS_TIMEOUT:
  case LET: case IN: case ENDLET:
  case SUBSCRIBE: case UNSUBSCRIBE: case PRINTF:
    sprintf(msg, "keyword: \"%s\"", last_lex);
    return msg;
  default:
    sprintf(msg, "character: \"%c\"",
            last_lex[0]);
    return msg;
  }
}
