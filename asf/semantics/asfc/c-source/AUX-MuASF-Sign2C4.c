#include "support.h"
static asymbol * lf_AUX_MuASF_Sign2C4_2sym;
static aterm * lf_AUX_MuASF_Sign2C4_2( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * lf6sym;
static aterm * lf6( aterm * arg1);
static asymbol * ef28sym;
static funcptr ef28;
static asymbol * ef24sym;
static funcptr ef24;
static asymbol * ef32sym;
static funcptr ef32;
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
static asymbol * ef22sym;
static funcptr ef22;
static asymbol * ef23sym;
static funcptr ef23;
static asymbol * lf7sym;
static aterm * lf7( aterm * arg1);
static asymbol * ef20sym;
static funcptr ef20;
static asymbol * ef21sym;
static funcptr ef21;
static asymbol * ef25sym;
static funcptr ef25;
static asymbol * ef26sym;
static funcptr ef26;
static asymbol * ef27sym;
static funcptr ef27;
static asymbol * ef35sym;
static funcptr ef35;
static asymbol * ef29sym;
static funcptr ef29;
static asymbol * lf8sym;
static aterm * lf8( aterm * arg1);
static asymbol * ef30sym;
static funcptr ef30;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf_AUX_MuASF_Sign2C4_1sym;
static aterm * lf_AUX_MuASF_Sign2C4_1( aterm * arg1);
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * lf5sym;
static aterm * lf5( aterm * arg1);
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef31sym;
static funcptr ef31;
static asymbol * ef33sym;
static funcptr ef33;
static asymbol * lf9sym;
static aterm * lf9( aterm * arg1);
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef34sym;
static funcptr ef34;
void register_AUX_MuASF_Sign2C4( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Sign2C4_2sym= TmkSymbol( "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"funcdef2cfuncs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf6sym= TmkSymbol( "listtype(sort(\"Parameter-declaration\"),ql(\",\"))" , SYM_STRING);
lf7sym= TmkSymbol( "listtype(sort(\"Expression\"),ql(\",\"))" , SYM_STRING);
lf8sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
lf_AUX_MuASF_Sign2C4_1sym= TmkSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , SYM_STRING);
lf5sym= TmkSymbol( "listtype(sort(\"Type-specifier\"))" , SYM_STRING);
lf9sym= TmkSymbol( "listtype(sort(\"SigArg\"),ql(\",\"))" , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"NamePair\"),ql(\",\"))") , lf_AUX_MuASF_Sign2C4_1 , lf_AUX_MuASF_Sign2C4_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"funcdef2cfuncs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Sign2C4_2 , lf_AUX_MuASF_Sign2C4_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf4 , lf4sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Type-specifier\"))") , lf5 , lf5sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Parameter-declaration\"),ql(\",\"))") , lf6 , lf6sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Expression\"),ql(\",\"))") , lf7 , lf7sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf8 , lf8sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"SigArg\"),ql(\",\"))") , lf9 , lf9sym);
}
void resolve_AUX_MuASF_Sign2C4( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\"),w(\"\"),sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\"),w(\"\"),sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Type-specifier\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-specifiers\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Type-specifier\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-specifiers\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"static\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"static\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"*\"),w(\"\"),sort(\"Declarator\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"*\"),w(\"\"),sort(\"Declarator\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef17= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef18= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef19= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef19sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef20= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef20sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef21= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef21sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef22= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef22sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef23= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
ef23sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
ef24= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"pn-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef24sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"pn-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef25= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef25sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef26= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef26sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef27= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"np-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef27sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"np-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef28= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),sort(\"Props\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef28sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),sort(\"Props\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef29= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Props\"),w(\"\"),no-attrs)"));
ef29sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Props\"),w(\"\"),no-attrs)"));
ef30= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef30sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef31= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef31sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef32= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef32sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef33= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"sigargs2cargs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)"));
ef33sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"sigargs2cargs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)"));
ef34= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef34sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef35= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\"),w(\"\"),sort(\"Props\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef35sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\"),w(\"\"),sort(\"Props\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Sign2C4_2( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[12];
PROF( prof_lf_AUX_MuASF_Sign2C4_2);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef2sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf3sym)) {
{
aterm * atmp0000= arg_0( atmp000);
if( check_sym( arg1 , lf_AUX_MuASF_Sign2C4_1sym)) {
{
aterm * atmp10= arg_0( arg1);
t_protect( atmp0000);
if( not_empty_list( atmp0000)) {
t_protect( atmp0000);
if( term_equal( list_head( atmp0000) , make_char( 34))) {
t_protect( atmp0000);
tmp[ 0]= list_tail( atmp0000);
t_protect( tmp[ 0]);
if( not_empty_list( tmp[ 0])) {
t_protect( tmp[ 0]);
if( term_equal( list_head( tmp[ 0]) , make_char( 123))) {
t_protect( tmp[ 0]);
tmp[ 1]= list_tail( tmp[ 0]);
t_protect( tmp[ 1]);
tmp[ 2]= list_prefix( tmp[ 1]);
t_protect( tmp[ 1]);
if( not_empty_list( tmp[ 1])) {
t_protect( tmp[ 1]);
if( term_equal( list_last( tmp[ 1]) , make_char( 34))) {
t_protect( tmp[ 2]);
tmp[ 3]= list_prefix( tmp[ 2]);
t_protect( tmp[ 2]);
if( not_empty_list( tmp[ 2])) {
t_protect( tmp[ 2]);
if( term_equal( list_last( tmp[ 2]) , make_char( 125))) {
t_protect( tmp[ 3]);
t_protect( arg1);
tmp[ 4]= ( * ef24)( ( * ef2)( lf3( cons( make_list( make_char( 34)) , cons( make_list( make_char( 123)) , cons( make_list( tmp[ 3]) , cons( make_list( make_char( 125)) , make_list( make_char( 34)))))))) , arg1);
if( check_sym( tmp[ 4] , ef2sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 5] , lf3sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
t_protect( tmp[ 6]);
t_protect( tmp[ 6]);
t_protect( tmp[ 6]);
t_protect( tmp[ 6]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 4]);
return ( * ef3)( lf4( make_list( ( * ef1)( ( * ef2)( lf3( make_list( tmp[ 6])))))) , ( * ef4)( ( * ef5)( ( * ef6)( ( * ef7)( ( * ef8)( lf5( cons( make_list( ( * ef9)( )) , make_list( ( * ef10)( ( * ef11)( lf3( cons( make_list( make_char( 97)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 98)) , cons( make_list( make_char( 111)) , make_list( make_char( 108))))))))))))))) , ( * ef12)( ( * ef13)( ( * ef11)( lf3( cons( make_list( tmp[ 6]) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 121)) , make_list( make_char( 109))))))))))) , ( * ef7)( ( * ef8)( lf5( cons( make_list( ( * ef9)( )) , make_list( ( * ef10)( ( * ef11)( lf3( cons( make_list( make_char( 97)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , make_list( make_char( 109))))))))))))) , ( * ef12)( ( * ef14)( ( * ef11)( lf3( make_list( tmp[ 6]))) , ( * ef15)( lf6( make_list( null( ))))))))) , ( * ef16)( ( * ef17)( ( * ef18)( ( * ef19)( ( * ef20)( ( * ef21)( ( * ef11)( lf3( cons( make_list( tmp[ 6]) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 121)) , make_list( make_char( 109))))))))) , ( * ef20)( ( * ef22)( ( * ef21)( ( * ef11)( lf3( cons( make_list( make_char( 84)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 107)) , cons( make_list( make_char( 83)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 98)) , cons( make_list( make_char( 111)) , make_list( make_char( 108))))))))))))) , ( * ef23)( lf7( cons( make_list( ( * ef20)( ( * ef21)( ( * ef11)( lf3( cons( make_list( make_char( 34)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 40)) , cons( make_list( tmp[ 3]) , cons( make_list( make_char( 41)) , make_list( make_char( 34))))))))))))))))))) , make_list( ( * ef20)( ( * ef21)( ( * ef11)( lf3( cons( make_list( make_char( 83)) , cons( make_list( make_char( 89)) , cons( make_list( make_char( 77)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 83)) , cons( make_list( make_char( 84)) , cons( make_list( make_char( 82)) , cons( make_list( make_char( 73)) , cons( make_list( make_char( 78)) , make_list( make_char( 71))))))))))))))))))))))))));
}
}
t_unprotect( tmp[ 4]);
}
}
t_unprotect( tmp[ 3]);
}
}
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 1]);
}
}
t_unprotect( tmp[ 0]);
}
}
t_protect( atmp0000);
if( term_equal( ( * ef25)( ( * ef2)( lf3( make_list( atmp0000)))) , ( * ef26)( ))) {
t_protect( atmp0000);
t_protect( arg1);
tmp[ 0]= ( * ef27)( ( * ef2)( lf3( make_list( atmp0000))) , arg1);
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , lf3sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
t_protect( atmp0000);
t_protect( atmp0000);
t_protect( atmp0000);
t_protect( tmp[ 2]);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return ( * ef3)( lf4( make_list( arg0)) , ( * ef4)( ( * ef5)( ( * ef6)( ( * ef7)( ( * ef8)( lf5( cons( make_list( ( * ef9)( )) , make_list( ( * ef10)( ( * ef11)( lf3( cons( make_list( make_char( 97)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 98)) , cons( make_list( make_char( 111)) , make_list( make_char( 108))))))))))))))) , ( * ef12)( ( * ef13)( ( * ef11)( lf3( cons( make_list( atmp0000) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 121)) , make_list( make_char( 109))))))))))) , ( * ef7)( ( * ef8)( lf5( cons( make_list( ( * ef9)( )) , make_list( ( * ef10)( ( * ef11)( lf3( cons( make_list( make_char( 97)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , make_list( make_char( 109))))))))))))) , ( * ef12)( ( * ef14)( ( * ef11)( lf3( make_list( atmp0000))) , ( * ef15)( lf6( make_list( null( ))))))))) , ( * ef16)( ( * ef17)( ( * ef18)( ( * ef19)( ( * ef20)( ( * ef21)( ( * ef11)( lf3( cons( make_list( atmp0000) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 121)) , make_list( make_char( 109))))))))) , ( * ef20)( ( * ef22)( ( * ef21)( ( * ef11)( lf3( cons( make_list( make_char( 84)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 107)) , cons( make_list( make_char( 83)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 98)) , cons( make_list( make_char( 111)) , make_list( make_char( 108))))))))))))) , ( * ef23)( lf7( cons( make_list( ( * ef20)( ( * ef21)( ( * ef11)( lf3( make_list( tmp[ 2])))))) , make_list( ( * ef20)( ( * ef21)( ( * ef11)( lf3( cons( make_list( make_char( 83)) , cons( make_list( make_char( 89)) , cons( make_list( make_char( 77)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 83)) , cons( make_list( make_char( 84)) , cons( make_list( make_char( 82)) , cons( make_list( make_char( 73)) , cons( make_list( make_char( 78)) , make_list( make_char( 71))))))))))))))))))))))))));
}
}
t_unprotect( tmp[ 0]);
}
}
}
}
}
}
}
}
}
if( check_sym( arg0 , ef28sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef2sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf3sym)) {
{
aterm * atmp0000= arg_0( atmp000);
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef29sym)) {
{
aterm * atmp010= arg_0( atmp01);
if( check_sym( atmp010 , lf8sym)) {
{
aterm * atmp0100= arg_0( atmp010);
if( check_sym( arg1 , lf_AUX_MuASF_Sign2C4_1sym)) {
{
aterm * atmp10= arg_0( arg1);
t_protect( atmp0100);
if( is_single_element( atmp0100)) {
t_protect( atmp0100);
tmp[ 0]= list_head( atmp0100);
if( check_sym( tmp[ 0] , ef30sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , ef2sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , lf3sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
t_protect( tmp[ 3]);
if( not_empty_list( tmp[ 3])) {
t_protect( tmp[ 3]);
if( term_equal( list_head( tmp[ 3]) , make_char( 101))) {
t_protect( tmp[ 3]);
tmp[ 4]= list_tail( tmp[ 3]);
t_protect( tmp[ 4]);
if( not_empty_list( tmp[ 4])) {
t_protect( tmp[ 4]);
if( term_equal( list_head( tmp[ 4]) , make_char( 120))) {
t_protect( tmp[ 4]);
tmp[ 5]= list_tail( tmp[ 4]);
t_protect( tmp[ 5]);
if( not_empty_list( tmp[ 5])) {
t_protect( tmp[ 5]);
if( term_equal( list_head( tmp[ 5]) , make_char( 116))) {
t_protect( tmp[ 5]);
tmp[ 6]= list_tail( tmp[ 5]);
t_protect( tmp[ 6]);
if( not_empty_list( tmp[ 6])) {
t_protect( tmp[ 6]);
if( term_equal( list_head( tmp[ 6]) , make_char( 101))) {
t_protect( tmp[ 6]);
tmp[ 7]= list_tail( tmp[ 6]);
t_protect( tmp[ 7]);
if( not_empty_list( tmp[ 7])) {
t_protect( tmp[ 7]);
if( term_equal( list_head( tmp[ 7]) , make_char( 114))) {
t_protect( tmp[ 7]);
tmp[ 8]= list_tail( tmp[ 7]);
t_protect( tmp[ 8]);
if( not_empty_list( tmp[ 8])) {
t_protect( tmp[ 8]);
if( term_equal( list_head( tmp[ 8]) , make_char( 110))) {
t_protect( tmp[ 8]);
tmp[ 9]= list_tail( tmp[ 8]);
t_protect( tmp[ 9]);
if( not_empty_list( tmp[ 9])) {
t_protect( tmp[ 9]);
if( term_equal( list_head( tmp[ 9]) , make_char( 97))) {
t_protect( tmp[ 9]);
tmp[ 10]= list_tail( tmp[ 9]);
t_protect( tmp[ 10]);
if( is_single_element( tmp[ 10])) {
t_protect( tmp[ 10]);
if( term_equal( list_head( tmp[ 10]) , make_char( 108))) {
t_protect( atmp0000);
t_protect( atmp0000);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
return ( * ef3)( lf4( make_list( null( ))) , ( * ef4)( ( * ef5)( ( * ef6)( ( * ef7)( ( * ef8)( lf5( cons( make_list( ( * ef9)( )) , make_list( ( * ef10)( ( * ef11)( lf3( cons( make_list( make_char( 97)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 98)) , cons( make_list( make_char( 111)) , make_list( make_char( 108))))))))))))))) , ( * ef12)( ( * ef13)( ( * ef11)( lf3( cons( make_list( atmp0000) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 121)) , make_list( make_char( 109))))))))))) , ( * ef7)( ( * ef8)( lf5( cons( make_list( ( * ef9)( )) , make_list( ( * ef10)( ( * ef11)( lf3( cons( make_list( make_char( 102)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 99)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 116)) , make_list( make_char( 114))))))))))))))) , ( * ef13)( ( * ef11)( lf3( make_list( atmp0000))))))) , ( * ef31)( ));
}
}
t_unprotect( tmp[ 10]);
}
}
t_unprotect( tmp[ 9]);
}
}
t_unprotect( tmp[ 8]);
}
}
t_unprotect( tmp[ 7]);
}
}
t_unprotect( tmp[ 6]);
}
}
t_unprotect( tmp[ 5]);
}
}
t_unprotect( tmp[ 4]);
}
}
}
}
}
t_unprotect( tmp[ 0]);
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
if( check_sym( arg0 , ef32sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef2sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf3sym)) {
{
aterm * atmp0000= arg_0( atmp000);
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , lf9sym)) {
{
aterm * atmp010= arg_0( atmp01);
if( check_sym( arg1 , lf_AUX_MuASF_Sign2C4_1sym)) {
{
aterm * atmp10= arg_0( arg1);
t_protect( atmp0000);
if( not_empty_list( atmp0000)) {
t_protect( atmp0000);
if( term_equal( list_head( atmp0000) , make_char( 34))) {
t_protect( atmp0000);
tmp[ 0]= list_tail( atmp0000);
t_protect( tmp[ 0]);
if( not_empty_list( tmp[ 0])) {
t_protect( tmp[ 0]);
if( term_equal( list_head( tmp[ 0]) , make_char( 123))) {
t_protect( tmp[ 0]);
tmp[ 1]= list_tail( tmp[ 0]);
t_protect( tmp[ 1]);
tmp[ 2]= list_prefix( tmp[ 1]);
t_protect( tmp[ 1]);
if( not_empty_list( tmp[ 1])) {
t_protect( tmp[ 1]);
if( term_equal( list_last( tmp[ 1]) , make_char( 34))) {
t_protect( tmp[ 2]);
tmp[ 3]= list_prefix( tmp[ 2]);
t_protect( tmp[ 2]);
if( not_empty_list( tmp[ 2])) {
t_protect( tmp[ 2]);
if( term_equal( list_last( tmp[ 2]) , make_char( 125))) {
t_protect( atmp010);
if( not_empty_list( atmp010)) {
t_protect( tmp[ 3]);
t_protect( arg1);
tmp[ 4]= ( * ef24)( ( * ef2)( lf3( cons( make_list( make_char( 34)) , cons( make_list( make_char( 123)) , cons( make_list( tmp[ 3]) , cons( make_list( make_char( 125)) , make_list( make_char( 34)))))))) , arg1);
if( check_sym( tmp[ 4] , ef2sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 5] , lf3sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
t_protect( atmp010);
tmp[ 7]= ( * ef33)( lf9( make_list( atmp010)) , ( * ef34)( lf3( make_list( make_char( 49)))));
t_protect( tmp[ 6]);
t_protect( atmp010);
t_protect( tmp[ 6]);
t_protect( tmp[ 6]);
t_protect( tmp[ 6]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 4]);
return ( * ef3)( lf4( make_list( ( * ef32)( ( * ef2)( lf3( make_list( tmp[ 6]))) , lf9( make_list( atmp010))))) , ( * ef4)( ( * ef5)( ( * ef6)( ( * ef7)( ( * ef8)( lf5( cons( make_list( ( * ef9)( )) , make_list( ( * ef10)( ( * ef11)( lf3( cons( make_list( make_char( 97)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 98)) , cons( make_list( make_char( 111)) , make_list( make_char( 108))))))))))))))) , ( * ef12)( ( * ef13)( ( * ef11)( lf3( cons( make_list( tmp[ 6]) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 121)) , make_list( make_char( 109))))))))))) , ( * ef7)( ( * ef8)( lf5( cons( make_list( ( * ef9)( )) , make_list( ( * ef10)( ( * ef11)( lf3( cons( make_list( make_char( 97)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , make_list( make_char( 109))))))))))))) , ( * ef12)( ( * ef14)( ( * ef11)( lf3( make_list( tmp[ 6]))) , tmp[ 7]))))) , ( * ef16)( ( * ef17)( ( * ef18)( ( * ef19)( ( * ef20)( ( * ef21)( ( * ef11)( lf3( cons( make_list( tmp[ 6]) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 121)) , make_list( make_char( 109))))))))) , ( * ef20)( ( * ef22)( ( * ef21)( ( * ef11)( lf3( cons( make_list( make_char( 84)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 107)) , cons( make_list( make_char( 83)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 98)) , cons( make_list( make_char( 111)) , make_list( make_char( 108))))))))))))) , ( * ef23)( lf7( cons( make_list( ( * ef20)( ( * ef21)( ( * ef11)( lf3( cons( make_list( make_char( 34)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 40)) , cons( make_list( tmp[ 3]) , cons( make_list( make_char( 41)) , make_list( make_char( 34))))))))))))))))))) , make_list( ( * ef20)( ( * ef21)( ( * ef11)( lf3( cons( make_list( make_char( 83)) , cons( make_list( make_char( 89)) , cons( make_list( make_char( 77)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 83)) , cons( make_list( make_char( 84)) , cons( make_list( make_char( 82)) , cons( make_list( make_char( 73)) , cons( make_list( make_char( 78)) , make_list( make_char( 71))))))))))))))))))))))))));
}
}
t_unprotect( tmp[ 4]);
}
}
}
t_unprotect( tmp[ 3]);
}
}
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 1]);
}
}
t_unprotect( tmp[ 0]);
}
}
t_protect( atmp010);
if( not_empty_list( atmp010)) {
t_protect( atmp0000);
if( term_equal( ( * ef25)( ( * ef2)( lf3( make_list( atmp0000)))) , ( * ef26)( ))) {
t_protect( atmp0000);
t_protect( arg1);
tmp[ 0]= ( * ef27)( ( * ef2)( lf3( make_list( atmp0000))) , arg1);
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , lf3sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
t_protect( atmp010);
tmp[ 3]= ( * ef33)( lf9( make_list( atmp010)) , ( * ef34)( lf3( make_list( make_char( 49)))));
t_protect( atmp0000);
t_protect( atmp0000);
t_protect( atmp0000);
t_protect( tmp[ 2]);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return ( * ef3)( lf4( make_list( arg0)) , ( * ef4)( ( * ef5)( ( * ef6)( ( * ef7)( ( * ef8)( lf5( cons( make_list( ( * ef9)( )) , make_list( ( * ef10)( ( * ef11)( lf3( cons( make_list( make_char( 97)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 98)) , cons( make_list( make_char( 111)) , make_list( make_char( 108))))))))))))))) , ( * ef12)( ( * ef13)( ( * ef11)( lf3( cons( make_list( atmp0000) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 121)) , make_list( make_char( 109))))))))))) , ( * ef7)( ( * ef8)( lf5( cons( make_list( ( * ef9)( )) , make_list( ( * ef10)( ( * ef11)( lf3( cons( make_list( make_char( 97)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , make_list( make_char( 109))))))))))))) , ( * ef12)( ( * ef14)( ( * ef11)( lf3( make_list( atmp0000))) , tmp[ 3]))))) , ( * ef16)( ( * ef17)( ( * ef18)( ( * ef19)( ( * ef20)( ( * ef21)( ( * ef11)( lf3( cons( make_list( atmp0000) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 121)) , make_list( make_char( 109))))))))) , ( * ef20)( ( * ef22)( ( * ef21)( ( * ef11)( lf3( cons( make_list( make_char( 84)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 107)) , cons( make_list( make_char( 83)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 98)) , cons( make_list( make_char( 111)) , make_list( make_char( 108))))))))))))) , ( * ef23)( lf7( cons( make_list( ( * ef20)( ( * ef21)( ( * ef11)( lf3( make_list( tmp[ 2])))))) , make_list( ( * ef20)( ( * ef21)( ( * ef11)( lf3( cons( make_list( make_char( 83)) , cons( make_list( make_char( 89)) , cons( make_list( make_char( 77)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 83)) , cons( make_list( make_char( 84)) , cons( make_list( make_char( 82)) , cons( make_list( make_char( 73)) , cons( make_list( make_char( 78)) , make_list( make_char( 71))))))))))))))))))))))))));
}
}
t_unprotect( tmp[ 0]);
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
if( check_sym( arg0 , ef35sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef2sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf3sym)) {
{
aterm * atmp0000= arg_0( atmp000);
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , lf9sym)) {
{
aterm * atmp010= arg_0( atmp01);
{
aterm * atmp02= arg_2( arg0);
if( check_sym( atmp02 , ef29sym)) {
{
aterm * atmp020= arg_0( atmp02);
if( check_sym( atmp020 , lf8sym)) {
{
aterm * atmp0200= arg_0( atmp020);
if( check_sym( arg1 , lf_AUX_MuASF_Sign2C4_1sym)) {
{
aterm * atmp10= arg_0( arg1);
t_protect( atmp010);
if( not_empty_list( atmp010)) {
t_protect( atmp0200);
if( is_single_element( atmp0200)) {
t_protect( atmp0200);
tmp[ 0]= list_head( atmp0200);
if( check_sym( tmp[ 0] , ef30sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , ef2sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , lf3sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
t_protect( tmp[ 3]);
if( not_empty_list( tmp[ 3])) {
t_protect( tmp[ 3]);
if( term_equal( list_head( tmp[ 3]) , make_char( 101))) {
t_protect( tmp[ 3]);
tmp[ 4]= list_tail( tmp[ 3]);
t_protect( tmp[ 4]);
if( not_empty_list( tmp[ 4])) {
t_protect( tmp[ 4]);
if( term_equal( list_head( tmp[ 4]) , make_char( 120))) {
t_protect( tmp[ 4]);
tmp[ 5]= list_tail( tmp[ 4]);
t_protect( tmp[ 5]);
if( not_empty_list( tmp[ 5])) {
t_protect( tmp[ 5]);
if( term_equal( list_head( tmp[ 5]) , make_char( 116))) {
t_protect( tmp[ 5]);
tmp[ 6]= list_tail( tmp[ 5]);
t_protect( tmp[ 6]);
if( not_empty_list( tmp[ 6])) {
t_protect( tmp[ 6]);
if( term_equal( list_head( tmp[ 6]) , make_char( 101))) {
t_protect( tmp[ 6]);
tmp[ 7]= list_tail( tmp[ 6]);
t_protect( tmp[ 7]);
if( not_empty_list( tmp[ 7])) {
t_protect( tmp[ 7]);
if( term_equal( list_head( tmp[ 7]) , make_char( 114))) {
t_protect( tmp[ 7]);
tmp[ 8]= list_tail( tmp[ 7]);
t_protect( tmp[ 8]);
if( not_empty_list( tmp[ 8])) {
t_protect( tmp[ 8]);
if( term_equal( list_head( tmp[ 8]) , make_char( 110))) {
t_protect( tmp[ 8]);
tmp[ 9]= list_tail( tmp[ 8]);
t_protect( tmp[ 9]);
if( not_empty_list( tmp[ 9])) {
t_protect( tmp[ 9]);
if( term_equal( list_head( tmp[ 9]) , make_char( 97))) {
t_protect( tmp[ 9]);
tmp[ 10]= list_tail( tmp[ 9]);
t_protect( tmp[ 10]);
if( is_single_element( tmp[ 10])) {
t_protect( tmp[ 10]);
if( term_equal( list_head( tmp[ 10]) , make_char( 108))) {
t_protect( atmp010);
tmp[ 11]= ( * ef33)( lf9( make_list( atmp010)) , ( * ef34)( lf3( make_list( make_char( 49)))));
t_protect( atmp0000);
t_protect( atmp0000);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
return ( * ef3)( lf4( make_list( null( ))) , ( * ef4)( ( * ef5)( ( * ef6)( ( * ef7)( ( * ef8)( lf5( cons( make_list( ( * ef9)( )) , make_list( ( * ef10)( ( * ef11)( lf3( cons( make_list( make_char( 97)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 98)) , cons( make_list( make_char( 111)) , make_list( make_char( 108))))))))))))))) , ( * ef12)( ( * ef13)( ( * ef11)( lf3( cons( make_list( atmp0000) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 121)) , make_list( make_char( 109))))))))))) , ( * ef7)( ( * ef8)( lf5( cons( make_list( ( * ef9)( )) , make_list( ( * ef10)( ( * ef11)( lf3( cons( make_list( make_char( 102)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 99)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 116)) , make_list( make_char( 114))))))))))))))) , ( * ef13)( ( * ef11)( lf3( make_list( atmp0000))))))) , ( * ef31)( ));
}
}
t_unprotect( tmp[ 10]);
}
}
t_unprotect( tmp[ 9]);
}
}
t_unprotect( tmp[ 8]);
}
}
t_unprotect( tmp[ 7]);
}
}
t_unprotect( tmp[ 6]);
}
}
t_unprotect( tmp[ 5]);
}
}
t_unprotect( tmp[ 4]);
}
}
}
}
}
t_unprotect( tmp[ 0]);
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
}
}
}
}
return make_nf2( lf_AUX_MuASF_Sign2C4_2sym , arg0 , arg1);
}
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
aterm * lf9( aterm * arg0) {
PROF( prof_lf9);
return make_nf1( lf9sym , arg0);
}
aterm * lf5( aterm * arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
aterm * lf_AUX_MuASF_Sign2C4_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Sign2C4_1);
return make_nf1( lf_AUX_MuASF_Sign2C4_1sym , arg0);
}
aterm * lf8( aterm * arg0) {
PROF( prof_lf8);
return make_nf1( lf8sym , arg0);
}
aterm * lf7( aterm * arg0) {
PROF( prof_lf7);
return make_nf1( lf7sym , arg0);
}
aterm * lf6( aterm * arg0) {
PROF( prof_lf6);
return make_nf1( lf6sym , arg0);
}

