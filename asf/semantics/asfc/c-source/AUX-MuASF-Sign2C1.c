#include "support.h"
static asymbol * lf_AUX_MuASF_Sign2C1_1sym;
static aterm * lf_AUX_MuASF_Sign2C1_1( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef31sym;
static funcptr ef31;
static asymbol * ef32sym;
static funcptr ef32;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef33sym;
static funcptr ef33;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * lf5sym;
static aterm * lf5( aterm * arg1);
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * ef16sym;
static funcptr ef16;
static asymbol * ef17sym;
static funcptr ef17;
static asymbol * ef18sym;
static funcptr ef18;
static asymbol * ef19sym;
static funcptr ef19;
static asymbol * ef20sym;
static funcptr ef20;
static asymbol * ef22sym;
static funcptr ef22;
static asymbol * ef24sym;
static funcptr ef24;
static asymbol * lf7sym;
static aterm * lf7( aterm * arg1);
static asymbol * ef25sym;
static funcptr ef25;
static asymbol * ef26sym;
static funcptr ef26;
static asymbol * ef21sym;
static funcptr ef21;
static asymbol * ef23sym;
static funcptr ef23;
static asymbol * lf6sym;
static aterm * lf6( aterm * arg1);
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * ef27sym;
static funcptr ef27;
static asymbol * ef28sym;
static funcptr ef28;
static asymbol * ef29sym;
static funcptr ef29;
static asymbol * ef30sym;
static funcptr ef30;
static asymbol * ef34sym;
static funcptr ef34;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * ef35sym;
static funcptr ef35;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
void register_AUX_MuASF_Sign2C1( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Sign2C1_1sym= TmkSymbol( "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"signopt2cfuncs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ModId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"SignatureOpt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FT-tuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf5sym= TmkSymbol( "listtype(sort(\"Parameter-declaration\"),ql(\",\"))" , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"Type-specifier\"))" , SYM_STRING);
lf7sym= TmkSymbol( "listtype(sort(\"Expression\"),ql(\",\"))" , SYM_STRING);
lf6sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"signopt2cfuncs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ModId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"SignatureOpt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FT-tuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Sign2C1_1 , lf_AUX_MuASF_Sign2C1_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"NamePair\"),ql(\",\"))") , lf2 , lf2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf3 , lf3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Type-specifier\"))") , lf4 , lf4sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Parameter-declaration\"),ql(\",\"))") , lf5 , lf5sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf6 , lf6sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Expression\"),ql(\",\"))") , lf7 , lf7sym);
}
void resolve_AUX_MuASF_Sign2C1( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"SignatureOpt\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"SignatureOpt\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NameTable\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NameTable\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FT-tuple\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FT-tuple\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\"),w(\"\"),sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\"),w(\"\"),sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Type-specifier\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-specifiers\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Type-specifier\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-specifiers\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"void\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"void\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)"));
ef17= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef17sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef18= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef19= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef19sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef20= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef20sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef21= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef21sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef22= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef22sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef23= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef23sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef24= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
ef24sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
ef25= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Unary-operator\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef25sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Unary-operator\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef26= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"&\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Unary-operator\"),w(\"\"),no-attrs)"));
ef26sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"&\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Unary-operator\"),w(\"\"),no-attrs)"));
ef27= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"modname2iname\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ModId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef27sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"modname2iname\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ModId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef28= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"modname2rname\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ModId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef28sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"modname2rname\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ModId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef29= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"namepairs2rstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef29sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"namepairs2rstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef30= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"namepairs2lstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef30sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"namepairs2lstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef31= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"signature\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SignatureOpt\"),w(\"\"),no-attrs)"));
ef31sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"signature\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SignatureOpt\"),w(\"\"),no-attrs)"));
ef32= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef32sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef33= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Declaration-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Declaration-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef33sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Declaration-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Declaration-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef34= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"funcdefs2cfuncs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)"));
ef34sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"funcdefs2cfuncs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)"));
ef35= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)"));
ef35sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Sign2C1_1( aterm * arg0 , aterm * arg1 , aterm * arg2) {
{
aterm * tmp[9];
PROF( prof_lf_AUX_MuASF_Sign2C1_1);
if( check_sym( arg1 , ef1sym)) {
if( check_sym( arg2 , ef2sym)) {
{
aterm * atmp20= arg_0( arg2);
if( check_sym( atmp20 , lf2sym)) {
{
aterm * atmp200= arg_0( atmp20);
{
aterm * atmp21= arg_1( arg2);
{
aterm * atmp22= arg_2( arg2);
{
aterm * atmp23= arg_3( arg2);
t_protect( arg0);
tmp[ 0]= ( * ef27)( arg0);
t_protect( arg0);
tmp[ 1]= ( * ef28)( arg0);
t_protect( atmp200);
tmp[ 2]= ( * ef29)( lf2( make_list( atmp200)));
t_protect( atmp200);
tmp[ 3]= ( * ef30)( lf2( make_list( atmp200)));
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
return ( * ef3)( lf3( make_list( null( ))) , ( * ef4)( ( * ef5)( ( * ef6)( ( * ef7)( ( * ef8)( lf4( make_list( ( * ef9)( )))) , ( * ef10)( tmp[ 0] , ( * ef11)( lf5( make_list( null( ))))) , ( * ef12)( ( * ef4)( ( * ef6)( ( * ef13)( ( * ef8)( lf4( make_list( ( * ef14)( ( * ef15)( lf6( cons( make_list( make_char( 97)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 110)) , make_list( make_char( 97)))))))))))) , ( * ef16)( ( * ef15)( lf6( cons( make_list( make_char( 108)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 99)) , cons( make_list( make_char( 97)) , make_list( make_char( 108)))))))))))) , ( * ef17)( ( * ef18)( ( * ef19)( ( * ef20)( ( * ef21)( ( * ef22)( ( * ef23)( ( * ef15)( lf6( cons( make_list( make_char( 84)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 65)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 110)) , make_list( make_char( 97)))))))))))))) , ( * ef24)( lf7( cons( make_list( ( * ef21)( ( * ef23)( ( * ef15)( lf6( cons( make_list( make_char( 78)) , cons( make_list( make_char( 85)) , cons( make_list( make_char( 76)) , make_list( make_char( 76)))))))))) , make_list( ( * ef25)( ( * ef26)( ) , ( * ef21)( ( * ef23)( ( * ef15)( lf6( cons( make_list( make_char( 108)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 99)) , cons( make_list( make_char( 97)) , make_list( make_char( 108)))))))))))))))))))) , tmp[ 2])))) , ( * ef7)( ( * ef8)( lf4( make_list( ( * ef9)( )))) , ( * ef10)( tmp[ 1] , ( * ef11)( lf5( make_list( null( ))))) , ( * ef12)( ( * ef4)( ( * ef6)( ( * ef13)( ( * ef8)( lf4( make_list( ( * ef14)( ( * ef15)( lf6( cons( make_list( make_char( 97)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 110)) , make_list( make_char( 97)))))))))))) , ( * ef16)( ( * ef15)( lf6( cons( make_list( make_char( 108)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 99)) , cons( make_list( make_char( 97)) , make_list( make_char( 108)))))))))))) , ( * ef17)( ( * ef18)( ( * ef19)( ( * ef20)( ( * ef21)( ( * ef22)( ( * ef23)( ( * ef15)( lf6( cons( make_list( make_char( 84)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 65)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 110)) , make_list( make_char( 97)))))))))))))) , ( * ef24)( lf7( cons( make_list( ( * ef21)( ( * ef23)( ( * ef15)( lf6( cons( make_list( make_char( 78)) , cons( make_list( make_char( 85)) , cons( make_list( make_char( 76)) , make_list( make_char( 76)))))))))) , make_list( ( * ef25)( ( * ef26)( ) , ( * ef21)( ( * ef23)( ( * ef15)( lf6( cons( make_list( make_char( 108)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 99)) , cons( make_list( make_char( 97)) , make_list( make_char( 108)))))))))))))))))))) , tmp[ 3]))))));
}
}
}
}
}
}
}
}
if( check_sym( arg1 , ef31sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef32sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( check_sym( atmp100 , lf3sym)) {
{
aterm * atmp1000= arg_0( atmp100);
if( check_sym( arg2 , ef2sym)) {
{
aterm * atmp20= arg_0( arg2);
if( check_sym( atmp20 , lf2sym)) {
{
aterm * atmp200= arg_0( atmp20);
{
aterm * atmp21= arg_1( arg2);
{
aterm * atmp22= arg_2( arg2);
{
aterm * atmp23= arg_3( arg2);
t_protect( atmp1000);
if( not_empty_list( atmp1000)) {
t_protect( arg0);
tmp[ 0]= ( * ef27)( arg0);
t_protect( arg0);
tmp[ 1]= ( * ef28)( arg0);
t_protect( atmp200);
tmp[ 2]= ( * ef29)( lf2( make_list( atmp200)));
t_protect( atmp200);
tmp[ 3]= ( * ef30)( lf2( make_list( atmp200)));
t_protect( atmp1000);
t_protect( atmp200);
tmp[ 4]= ( * ef34)( lf3( make_list( atmp1000)) , lf2( make_list( atmp200)));
if( check_sym( tmp[ 4] , ef35sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
tmp[ 6]= arg_1( tmp[ 4]);
tmp[ 7]= arg_2( tmp[ 4]);
if( check_sym( tmp[ 5] , lf3sym)) {
tmp[ 8]= arg_0( tmp[ 5]);
t_protect( tmp[ 8]);
t_protect( tmp[ 6]);
t_protect( tmp[ 7]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 4]);
return ( * ef3)( lf3( make_list( tmp[ 8])) , ( * ef33)( tmp[ 6] , ( * ef4)( ( * ef5)( ( * ef6)( ( * ef7)( ( * ef8)( lf4( make_list( ( * ef9)( )))) , ( * ef10)( tmp[ 0] , ( * ef11)( lf5( make_list( null( ))))) , ( * ef12)( ( * ef4)( ( * ef6)( ( * ef13)( ( * ef8)( lf4( make_list( ( * ef14)( ( * ef15)( lf6( cons( make_list( make_char( 97)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 110)) , make_list( make_char( 97)))))))))))) , ( * ef16)( ( * ef15)( lf6( cons( make_list( make_char( 108)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 99)) , cons( make_list( make_char( 97)) , make_list( make_char( 108)))))))))))) , ( * ef17)( ( * ef17)( ( * ef18)( ( * ef19)( ( * ef20)( ( * ef21)( ( * ef22)( ( * ef23)( ( * ef15)( lf6( cons( make_list( make_char( 84)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 65)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 110)) , make_list( make_char( 97)))))))))))))) , ( * ef24)( lf7( cons( make_list( ( * ef21)( ( * ef23)( ( * ef15)( lf6( cons( make_list( make_char( 78)) , cons( make_list( make_char( 85)) , cons( make_list( make_char( 76)) , make_list( make_char( 76)))))))))) , make_list( ( * ef25)( ( * ef26)( ) , ( * ef21)( ( * ef23)( ( * ef15)( lf6( cons( make_list( make_char( 108)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 99)) , cons( make_list( make_char( 97)) , make_list( make_char( 108)))))))))))))))))))) , tmp[ 7]) , tmp[ 2])))) , ( * ef7)( ( * ef8)( lf4( make_list( ( * ef9)( )))) , ( * ef10)( tmp[ 1] , ( * ef11)( lf5( make_list( null( ))))) , ( * ef12)( ( * ef4)( ( * ef6)( ( * ef13)( ( * ef8)( lf4( make_list( ( * ef14)( ( * ef15)( lf6( cons( make_list( make_char( 97)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 110)) , make_list( make_char( 97)))))))))))) , ( * ef16)( ( * ef15)( lf6( cons( make_list( make_char( 108)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 99)) , cons( make_list( make_char( 97)) , make_list( make_char( 108)))))))))))) , ( * ef17)( ( * ef18)( ( * ef19)( ( * ef20)( ( * ef21)( ( * ef22)( ( * ef23)( ( * ef15)( lf6( cons( make_list( make_char( 84)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 65)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 110)) , make_list( make_char( 97)))))))))))))) , ( * ef24)( lf7( cons( make_list( ( * ef21)( ( * ef23)( ( * ef15)( lf6( cons( make_list( make_char( 78)) , cons( make_list( make_char( 85)) , cons( make_list( make_char( 76)) , make_list( make_char( 76)))))))))) , make_list( ( * ef25)( ( * ef26)( ) , ( * ef21)( ( * ef23)( ( * ef15)( lf6( cons( make_list( make_char( 108)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 99)) , cons( make_list( make_char( 97)) , make_list( make_char( 108)))))))))))))))))))) , tmp[ 3])))))));
}
}
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
else {
t_protect( arg0);
tmp[ 0]= ( * ef27)( arg0);
t_protect( arg0);
tmp[ 1]= ( * ef28)( arg0);
t_protect( atmp200);
tmp[ 2]= ( * ef29)( lf2( make_list( atmp200)));
t_protect( atmp200);
tmp[ 3]= ( * ef30)( lf2( make_list( atmp200)));
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
return ( * ef3)( lf3( make_list( null( ))) , ( * ef4)( ( * ef5)( ( * ef6)( ( * ef7)( ( * ef8)( lf4( make_list( ( * ef9)( )))) , ( * ef10)( tmp[ 0] , ( * ef11)( lf5( make_list( null( ))))) , ( * ef12)( ( * ef4)( ( * ef6)( ( * ef13)( ( * ef8)( lf4( make_list( ( * ef14)( ( * ef15)( lf6( cons( make_list( make_char( 97)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 110)) , make_list( make_char( 97)))))))))))) , ( * ef16)( ( * ef15)( lf6( cons( make_list( make_char( 108)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 99)) , cons( make_list( make_char( 97)) , make_list( make_char( 108)))))))))))) , ( * ef17)( ( * ef18)( ( * ef19)( ( * ef20)( ( * ef21)( ( * ef22)( ( * ef23)( ( * ef15)( lf6( cons( make_list( make_char( 84)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 65)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 110)) , make_list( make_char( 97)))))))))))))) , ( * ef24)( lf7( cons( make_list( ( * ef21)( ( * ef23)( ( * ef15)( lf6( cons( make_list( make_char( 78)) , cons( make_list( make_char( 85)) , cons( make_list( make_char( 76)) , make_list( make_char( 76)))))))))) , make_list( ( * ef25)( ( * ef26)( ) , ( * ef21)( ( * ef23)( ( * ef15)( lf6( cons( make_list( make_char( 108)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 99)) , cons( make_list( make_char( 97)) , make_list( make_char( 108)))))))))))))))))))) , tmp[ 2])))) , ( * ef7)( ( * ef8)( lf4( make_list( ( * ef9)( )))) , ( * ef10)( tmp[ 1] , ( * ef11)( lf5( make_list( null( ))))) , ( * ef12)( ( * ef4)( ( * ef6)( ( * ef13)( ( * ef8)( lf4( make_list( ( * ef14)( ( * ef15)( lf6( cons( make_list( make_char( 97)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 110)) , make_list( make_char( 97)))))))))))) , ( * ef16)( ( * ef15)( lf6( cons( make_list( make_char( 108)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 99)) , cons( make_list( make_char( 97)) , make_list( make_char( 108)))))))))))) , ( * ef17)( ( * ef18)( ( * ef19)( ( * ef20)( ( * ef21)( ( * ef22)( ( * ef23)( ( * ef15)( lf6( cons( make_list( make_char( 84)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 65)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 110)) , make_list( make_char( 97)))))))))))))) , ( * ef24)( lf7( cons( make_list( ( * ef21)( ( * ef23)( ( * ef15)( lf6( cons( make_list( make_char( 78)) , cons( make_list( make_char( 85)) , cons( make_list( make_char( 76)) , make_list( make_char( 76)))))))))) , make_list( ( * ef25)( ( * ef26)( ) , ( * ef21)( ( * ef23)( ( * ef15)( lf6( cons( make_list( make_char( 108)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 99)) , cons( make_list( make_char( 97)) , make_list( make_char( 108)))))))))))))))))))) , tmp[ 3]))))));
}
}
}
}
}
}
}
}
}
}
}
}
}
}
return make_nf3( lf_AUX_MuASF_Sign2C1_1sym , arg0 , arg1 , arg2);
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
aterm * lf6( aterm * arg0) {
PROF( prof_lf6);
return make_nf1( lf6sym , arg0);
}
aterm * lf7( aterm * arg0) {
PROF( prof_lf7);
return make_nf1( lf7sym , arg0);
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
aterm * lf5( aterm * arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}

