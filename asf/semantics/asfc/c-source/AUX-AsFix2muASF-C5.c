#include "support.h"
static asymbol * lf_AUX_AsFix2muASF_C5_1sym;
static aterm * lf_AUX_AsFix2muASF_C5_1( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef16sym;
static funcptr ef16;
static asymbol * ef17sym;
static funcptr ef17;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef23sym;
static funcptr ef23;
static asymbol * ef24sym;
static funcptr ef24;
static asymbol * ef25sym;
static funcptr ef25;
static asymbol * ef27sym;
static funcptr ef27;
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * ef28sym;
static funcptr ef28;
static asymbol * ef21sym;
static funcptr ef21;
static asymbol * ef22sym;
static funcptr ef22;
static asymbol * ef40sym;
static funcptr ef40;
static asymbol * ef32sym;
static funcptr ef32;
static asymbol * ef41sym;
static funcptr ef41;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef33sym;
static funcptr ef33;
static asymbol * ef34sym;
static funcptr ef34;
static asymbol * ef35sym;
static funcptr ef35;
static asymbol * ef38sym;
static funcptr ef38;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef39sym;
static funcptr ef39;
static asymbol * ef36sym;
static funcptr ef36;
static asymbol * ef37sym;
static funcptr ef37;
static asymbol * ef26sym;
static funcptr ef26;
static asymbol * ef29sym;
static funcptr ef29;
static asymbol * ef42sym;
static funcptr ef42;
static asymbol * ef18sym;
static funcptr ef18;
static asymbol * ef19sym;
static funcptr ef19;
static asymbol * ef20sym;
static funcptr ef20;
static asymbol * ef30sym;
static funcptr ef30;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * ef31sym;
static funcptr ef31;
static asymbol * ef43sym;
static funcptr ef43;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
void register_AUX_AsFix2muASF_C5( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_AsFix2muASF_C5_1sym= TmkSymbol( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"aterm2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"aterm2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)") , lf_AUX_AsFix2muASF_C5_1 , lf_AUX_AsFix2muASF_C5_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf2 , lf2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf3 , lf3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf4 , lf4sym);
}
void resolve_AUX_AsFix2muASF_C5( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"avar2muvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"avar2muvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"sym\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"sym\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"appl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"appl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"args2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"args2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"prod\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"prod\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"is-bracket-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"is-bracket-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"args\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"args\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef17= lookup_func( TmakeSimple( & local , "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"cffunc2id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"cffunc2id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef18= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"nt-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"nt-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)"));
ef19= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)"));
ef19sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)"));
ef20= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"make-external-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef20sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"make-external-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef21= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++_ss\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef21sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++_ss\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef22= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef22sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef23= lookup_func( TmakeSimple( & local , "prod(id(\"ATypes\"),w(\"\"),[l(\"list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef23sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATypes\"),w(\"\"),[l(\"list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef24= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-list-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef24sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-list-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef25= lookup_func( TmakeSimple( & local , "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"iter2id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef25sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"iter2id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef26= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"ntl-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)"));
ef26sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"ntl-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)"));
ef27= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"elems\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef27sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"elems\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef28= lookup_func( TmakeSimple( & local , "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"listargs2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)"));
ef28sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"listargs2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)"));
ef29= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"make-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef29sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"make-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef30= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef30sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef31= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef31sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef32= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"lex\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef32sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"lex\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef33= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef33sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef34= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef34sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef35= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef35sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef36= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef36sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef37= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef37sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef38= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef38sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef39= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"name\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef39sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"name\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef40= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"qlit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef40sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"qlit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef41= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef41sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef42= lookup_func( TmakeSimple( & local , "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"make-caller-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef42sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"make-caller-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef43= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"lit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef43sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"lit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_AsFix2muASF_C5_1( aterm * arg0 , aterm * arg1 , aterm * arg2) {
{
aterm * tmp[20];
PROF( prof_lf_AUX_AsFix2muASF_C5_1);
if( check_sym( arg0 , ef1sym)) {
t_protect( arg1);
tmp[ 0]= ( * ef5)( arg1);
t_protect( arg1);
tmp[ 1]= ( * ef6)( arg1 , ( * ef7)( ));
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 1]);
return ( * ef2)( lf2( make_list( null( ))) , ( * ef3)( lf3( make_list( ( * ef4)( tmp[ 0])))) , arg2);
}
if( check_sym( arg0 , ef8sym)) {
t_protect( arg1);
tmp[ 0]= ( * ef6)( arg1 , ( * ef10)( ));
t_protect( tmp[ 0]);
tmp[ 1]= ( * ef11)( tmp[ 0]);
t_protect( tmp[ 1]);
if( term_equal( tmp[ 1] , ( * ef12)( ))) {
t_protect( arg1);
tmp[ 2]= ( * ef6)( arg1 , ( * ef13)( ));
if( check_sym( tmp[ 2] , ef14sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
t_protect( tmp[ 3]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef9)( tmp[ 3] , arg2);
}
t_unprotect( tmp[ 2]);
}
t_protect( tmp[ 1]);
if( term_equal( tmp[ 1] , ( * ef16)( ))) {
t_protect( tmp[ 0]);
tmp[ 2]= ( * ef17)( tmp[ 0]);
t_protect( tmp[ 2]);
t_protect( arg2);
tmp[ 3]= ( * ef18)( tmp[ 2] , arg2);
if( check_sym( tmp[ 3] , ef19sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
tmp[ 5]= arg_1( tmp[ 3]);
t_protect( arg1);
tmp[ 6]= ( * ef6)( arg1 , ( * ef13)( ));
if( check_sym( tmp[ 6] , ef14sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
t_protect( tmp[ 7]);
t_protect( tmp[ 5]);
tmp[ 8]= ( * ef9)( tmp[ 7] , tmp[ 5]);
if( check_sym( tmp[ 8] , ef2sym)) {
tmp[ 9]= arg_0( tmp[ 8]);
tmp[ 10]= arg_1( tmp[ 8]);
tmp[ 11]= arg_2( tmp[ 8]);
if( check_sym( tmp[ 9] , lf2sym)) {
tmp[ 12]= arg_0( tmp[ 9]);
if( check_sym( tmp[ 10] , ef3sym)) {
tmp[ 13]= arg_0( tmp[ 10]);
if( check_sym( tmp[ 13] , lf3sym)) {
tmp[ 14]= arg_0( tmp[ 13]);
t_protect( tmp[ 4]);
t_protect( tmp[ 14]);
tmp[ 15]= ( * ef20)( tmp[ 4] , ( * ef3)( lf3( make_list( tmp[ 14]))));
t_protect( tmp[ 15]);
t_protect( tmp[ 12]);
tmp[ 16]= ( * ef21)( ( * ef22)( lf2( make_list( tmp[ 15]))) , ( * ef22)( lf2( make_list( tmp[ 12]))));
if( check_sym( tmp[ 16] , ef22sym)) {
tmp[ 17]= arg_0( tmp[ 16]);
if( check_sym( tmp[ 17] , lf2sym)) {
tmp[ 18]= arg_0( tmp[ 17]);
t_protect( tmp[ 18]);
t_protect( tmp[ 4]);
t_protect( tmp[ 14]);
t_protect( tmp[ 11]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
return ( * ef2)( lf2( make_list( tmp[ 18])) , ( * ef3)( lf3( make_list( ( * ef15)( tmp[ 4] , lf3( make_list( tmp[ 14])))))) , tmp[ 11]);
}
}
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 15]);
}
}
}
}
t_unprotect( tmp[ 8]);
}
t_unprotect( tmp[ 6]);
}
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 2]);
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
if( check_sym( arg0 , ef23sym)) {
t_protect( arg1);
tmp[ 0]= ( * ef6)( arg1 , ( * ef7)( ));
t_protect( tmp[ 0]);
tmp[ 1]= ( * ef25)( tmp[ 0]);
t_protect( tmp[ 1]);
t_protect( arg2);
tmp[ 2]= ( * ef26)( tmp[ 1] , arg2);
if( check_sym( tmp[ 2] , ef19sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
tmp[ 4]= arg_1( tmp[ 2]);
t_protect( arg1);
tmp[ 5]= ( * ef6)( arg1 , ( * ef27)( ));
if( check_sym( tmp[ 5] , ef14sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
t_protect( tmp[ 6]);
t_protect( tmp[ 4]);
tmp[ 7]= ( * ef28)( tmp[ 6] , tmp[ 4]);
if( check_sym( tmp[ 7] , ef2sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
tmp[ 9]= arg_1( tmp[ 7]);
tmp[ 10]= arg_2( tmp[ 7]);
if( check_sym( tmp[ 8] , lf2sym)) {
tmp[ 11]= arg_0( tmp[ 8]);
if( check_sym( tmp[ 9] , ef3sym)) {
tmp[ 12]= arg_0( tmp[ 9]);
if( check_sym( tmp[ 12] , lf3sym)) {
tmp[ 13]= arg_0( tmp[ 12]);
t_protect( tmp[ 1]);
tmp[ 14]= ( * ef29)( tmp[ 1] , ( * ef3)( lf3( make_list( ( * ef30)( ( * ef31)( lf4( cons( make_list( make_char( 110)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 108)) , make_list( make_char( 108))))))))))));
t_protect( tmp[ 14]);
t_protect( tmp[ 11]);
tmp[ 15]= ( * ef21)( ( * ef22)( lf2( make_list( tmp[ 14]))) , ( * ef22)( lf2( make_list( tmp[ 11]))));
if( check_sym( tmp[ 15] , ef22sym)) {
tmp[ 16]= arg_0( tmp[ 15]);
if( check_sym( tmp[ 16] , lf2sym)) {
tmp[ 17]= arg_0( tmp[ 16]);
t_protect( tmp[ 17]);
t_protect( tmp[ 13]);
t_protect( tmp[ 10]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
return ( * ef2)( lf2( make_list( tmp[ 17])) , ( * ef3)( lf3( make_list( ( * ef24)( tmp[ 1] , lf3( make_list( tmp[ 13])))))) , tmp[ 10]);
}
}
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 14]);
}
}
}
}
t_unprotect( tmp[ 7]);
}
t_unprotect( tmp[ 5]);
}
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
if( check_sym( arg0 , ef32sym)) {
t_protect( arg1);
if( term_equal( ( * ef6)( arg1 , ( * ef7)( )) , ( * ef33)( ( * ef34)( ) , ( * ef35)( ( * ef36)( ( * ef37)( ( * ef38)( lf4( cons( make_list( make_char( 34)) , cons( make_list( make_char( 67)) , cons( make_list( make_char( 72)) , cons( make_list( make_char( 65)) , cons( make_list( make_char( 82)) , make_list( make_char( 34))))))))))))))) {
t_protect( arg1);
tmp[ 0]= ( * ef6)( arg1 , ( * ef39)( ));
if( check_sym( tmp[ 0] , ef36sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , ef37sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
t_protect( tmp[ 2]);
tmp[ 3]= ( * ef40)( tmp[ 2]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return ( * ef2)( lf2( make_list( null( ))) , ( * ef3)( lf3( make_list( tmp[ 3]))) , arg2);
}
}
t_unprotect( tmp[ 0]);
}
t_protect( arg1);
tmp[ 0]= ( * ef6)( arg1 , ( * ef7)( ));
if( check_sym( tmp[ 0] , ef33sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
t_protect( tmp[ 1]);
if( term_equal( tmp[ 1] , ( * ef34)( ))) {
if( check_sym( tmp[ 2] , ef35sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , ef36sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 4] , ef37sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
t_protect( tmp[ 5]);
if( ! term_equal( tmp[ 5] , ( * ef38)( lf4( cons( make_list( make_char( 34)) , cons( make_list( make_char( 67)) , cons( make_list( make_char( 72)) , cons( make_list( make_char( 65)) , cons( make_list( make_char( 82)) , make_list( make_char( 34))))))))))) {
t_protect( arg1);
tmp[ 6]= ( * ef6)( arg1 , ( * ef39)( ));
if( check_sym( tmp[ 6] , ef36sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
if( check_sym( tmp[ 7] , ef37sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
tmp[ 9]= ( * ef31)( lf4( cons( make_list( make_char( 34)) , cons( make_list( make_char( 123)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 40)) , cons( make_list( make_char( 92)) , cons( make_list( make_char( 34)) , cons( make_list( make_char( 67)) , cons( make_list( make_char( 72)) , cons( make_list( make_char( 65)) , cons( make_list( make_char( 82)) , cons( make_list( make_char( 92)) , cons( make_list( make_char( 34)) , cons( make_list( make_char( 41)) , cons( make_list( make_char( 125)) , make_list( make_char( 34)))))))))))))))))))));
t_protect( tmp[ 9]);
t_protect( arg2);
tmp[ 10]= ( * ef26)( tmp[ 9] , arg2);
if( check_sym( tmp[ 10] , ef19sym)) {
tmp[ 11]= arg_0( tmp[ 10]);
tmp[ 12]= arg_1( tmp[ 10]);
t_protect( tmp[ 9]);
tmp[ 13]= ( * ef29)( tmp[ 9] , ( * ef3)( lf3( make_list( ( * ef30)( ( * ef31)( lf4( cons( make_list( make_char( 110)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 108)) , make_list( make_char( 108))))))))))));
t_protect( tmp[ 5]);
tmp[ 14]= ( * ef42)( tmp[ 5]);
t_protect( tmp[ 14]);
t_protect( tmp[ 12]);
tmp[ 15]= ( * ef18)( tmp[ 14] , tmp[ 12]);
if( check_sym( tmp[ 15] , ef19sym)) {
tmp[ 16]= arg_0( tmp[ 15]);
tmp[ 17]= arg_1( tmp[ 15]);
t_protect( tmp[ 16]);
tmp[ 18]= ( * ef20)( tmp[ 16] , ( * ef3)( lf3( make_list( ( * ef30)( ( * ef31)( lf4( cons( make_list( make_char( 110)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 108)) , make_list( make_char( 108))))))))))));
t_protect( tmp[ 8]);
tmp[ 19]= ( * ef43)( tmp[ 8]);
t_protect( tmp[ 16]);
t_protect( tmp[ 17]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
return ( * ef2)( lf2( cons( make_list( tmp[ 13]) , make_list( tmp[ 18]))) , ( * ef3)( lf3( make_list( ( * ef41)( tmp[ 16] , lf3( make_list( ( * ef41)( tmp[ 9] , lf3( make_list( tmp[ 19]))))))))) , tmp[ 17]);
}
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 13]);
}
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 9]);
}
}
t_unprotect( tmp[ 6]);
}
}
}
}
}
}
t_unprotect( tmp[ 0]);
}
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef2)( lf2( make_list( null( ))) , ( * ef3)( lf3( make_list( null( )))) , arg2);
}
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}

