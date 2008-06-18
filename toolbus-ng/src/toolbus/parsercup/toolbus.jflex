package toolbus.parsercup;


/* Lexical syntax for ToolBus scripts */
import java_cup.runtime.Symbol;
import toolbus.parsercup.SyntaxErrorException;

%%

%class Lexer
%unicode
%cup
%public
%char
%line
%column

%{
  StringBuilder string = new StringBuilder();

  private Symbol symbol(int type){
    return new Symbol(type, yyline, yycolumn);
  }
  
  private Symbol symbol(int type, Object value){
    return new Symbol(type, yyline, yycolumn, value);
  }
  
  public int getPosition(){
	  return yychar;
  }
%}

LineTerminator = \r|\n|\r\n
InputCharacter = [^\r\n]
WhiteSpace     = {LineTerminator} | [ \t\f]

/* comments */
Comment = {TraditionalComment} | {EndOfLineComment} | {EndOfLineComment2} |{DocumentationComment}

TraditionalComment   = "/*" [^*] ~"*/" | "/*" "*"+ "/"
EndOfLineComment     = "//" {InputCharacter}* {LineTerminator}
EndOfLineComment2    = "%%" {InputCharacter}* {LineTerminator}
DocumentationComment = "/**" {CommentContent} "*"+ "/"
CommentContent       = ( [^*] | \*+ [^/*] )*

Identifier = [a-z][A-Za-z0-9\-]*
Name = [A-Z_][A-Za-z0-9\-_]*

Int   = -?0 | -?[1-9][0-9]*
Real  = -?[0-9]+"."[0-9]+([eE][-+]?[0-9]+)?

%state STRING, INCLUDE

%%

/* keywords */
<YYINITIAL> {
  "snd-msg"                      { return symbol(sym.SND_MSG); }
  "rec-msg"                      { return symbol(sym.REC_MSG); }
  "snd-note"                     { return symbol(sym.SND_NOTE); }
  "rec-note"                     { return symbol(sym.REC_NOTE); }
  "no-note"                      { return symbol(sym.NO_NOTE); }
  "subscribe"                    { return symbol(sym.SUBSCRIBE); }
  "unsubscribe"                  { return symbol(sym.UNSUBSCRIBE); }
  "printf"                       { return symbol(sym.PRINTF); }
  "read"                         { return symbol(sym.READ); }
  "rec-event"                    { return symbol(sym.REC_EVENT); }
  "snd-ack-event"                { return symbol(sym.SND_ACK_EVENT); }
  "rec-request"                  { return symbol(sym.REC_REQUEST); }
  "snd-response"                 { return symbol(sym.SND_RESPONSE); }
  "snd-eval"                     { return symbol(sym.SND_EVAL); }
  "snd-cancel"                   { return symbol(sym.SND_CANCEL); }
  "snd-do"                       { return symbol(sym.SND_DO); }
  "rec-value"                    { return symbol(sym.REC_VALUE); }
  "toolbus"                      { return symbol(sym.TOOLBUS); }
  "process"                      { return symbol(sym.PROCESS); }
  "is"                           { return symbol(sym.IS); }
  "delta"                        { return symbol(sym.DELTA); }
  "tau"                          { return symbol(sym.TAU); }
  "tool"                         { return symbol(sym.TOOL); }
  "kind"                         { return symbol(sym.KIND); }
  "host"                         { return symbol(sym.HOST); }
  "command"                      { return symbol(sym.COMMAND); }
  "class"                        { return symbol(sym.CLASS); }
  "create"                       { return symbol(sym.CREATE); }
  "rec-connect"                  { return symbol(sym.REC_CONNECT); }
  "rec-disconnect"               { return symbol(sym.REC_DISCONNECT); }
  "execute"                      { return symbol(sym.EXECUTE); }
  "snd-terminate"                { return symbol(sym.SND_TERMINATE); }
  "snd-kill"                     { return symbol(sym.SND_KILL); }
  "shutdown"                     { return symbol(sym.SHUTDOWN); }
  "get-perf-stats"               { return symbol(sym.GET_PERF_STATS); }
  "rec-perf-stats"               { return symbol(sym.REC_PERF_STATS); }
  "if"                           { return symbol(sym.IF); }
  "then"                         { return symbol(sym.THEN); }
  "else"                         { return symbol(sym.ELSE); }
  "fi"                           { return symbol(sym.FI); }
  "delay"                        { return symbol(sym.REL_DELAY); }
  "abs-delay"                    { return symbol(sym.ABS_DELAY); }
  "timeout"                      { return symbol(sym.REL_TIMEOUT); }
  "abs-timeout"                  { return symbol(sym.ABS_TIMEOUT); }
  "let"                          { return symbol(sym.LET); }
  "in"                           { return symbol(sym.IN); }
  "endlet"	   	                 { return symbol(sym.ENDLET); }

  "true"                         { return symbol(sym.TRUE); }
  "false"                        { return symbol(sym.FALSE); }
  "undefined"                    { return symbol(sym.UNDEFINED); }

  "#define"                      { return symbol(sym.DEFINE); }
  "#include"                     { yybegin(INCLUDE); return symbol(sym.INCLUDE); }
  "#ifdef"                       { return symbol(sym.IFDEF); }
  "#ifndef"                      { return symbol(sym.IFNDEF); }
  "#endif"                       { return symbol(sym.ENDIF); }
}
 
<INCLUDE> {
  "<"                            { string.setLength(0); }
  [^\n\r\"\\<>]+                 { string.append( yytext() ); }
  ">"                            { yybegin(YYINITIAL); return symbol(sym.FILENAME, string.toString()); }
}
   
   

<YYINITIAL> {
  /* identifiers */ 
  {Identifier}                   { return symbol(sym.IDENT, yytext()); }
  {Name}                         { return symbol(sym.NAME, yytext()); }
 
  /* literals */
  {Int}                          { return symbol(sym.INT, Integer.parseInt(yytext())); }
  {Real}                         { return symbol(sym.REAL, yytext()); }
  \"                             { string.setLength(0); yybegin(STRING); }

 /* punctuation */
  "("                            { return symbol(sym.LPAR); }
  ")"                            { return symbol(sym.RPAR); }
  ","                            { return symbol(sym.COMMA); }
  "{"                            { return symbol(sym.LBRACE); }
  "}"                            { return symbol(sym.RBRACE); }
  "<"                            { return symbol(sym.LANGLE); }
  ">"                            { return symbol(sym.RANGLE); }
  "["                            { return symbol(sym.LSQUARE); }
  "]"                            { return symbol(sym.RSQUARE); }
  ":"                            { return symbol(sym.COLON); }
  
  /* operators */

  ":="                           { return symbol(sym.ASSIGN); }
  "||"                           { return symbol(sym.FMERGE); }
  "+"                            { return symbol(sym.CHOICE); }
  "+>"                           { return symbol(sym.RIGHTCHOICE); }
  "<+"                           { return symbol(sym.LEFTCHOICE); }
  ">>"                           { return symbol(sym.DISRUPT); }
  "?"                            { return symbol(sym.QUESTION); }
  "."                            { return symbol(sym.SEQ); }
  "*"                            { return symbol(sym.ITER); }
  "="                            { return symbol(sym.EQUALS); }
  

  /* comments */
  {Comment}                      { /* ignore */ }
 
  /* whitespace */
  {WhiteSpace}                   { /* ignore */ }
}

<STRING> {
  \"                             { yybegin(YYINITIAL); return symbol(sym.STRING, string.toString()); }
  [^\n\r\"\\]+                   { string.append( yytext() ); }
  \\t                            { string.append('\t'); }
  \\n                            { string.append('\n'); }

  \\r                            { string.append('\r'); }
  \\\"                           { string.append('\"'); }
  \\                             { string.append('\\'); }
}

/* error fallback */
.|\n                             { throw new SyntaxErrorException(yyline, yycolumn, yychar, yy_action); }

