#include "support.h"
static Symbol lf_AUX_MuASF_Sign2C5_2sym;
static ATerm lf_AUX_MuASF_Sign2C5_2( ATerm arg1 , ATerm arg2);
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef14sym;
static funcptr ef14;
static Symbol lf6sym;
static ATerm lf6( ATerm arg1);
static Symbol ef31sym;
static funcptr ef31;
static Symbol ef27sym;
static funcptr ef27;
static Symbol ef35sym;
static funcptr ef35;
static Symbol ef13sym;
static funcptr ef13;
static Symbol ef15sym;
static funcptr ef15;
static Symbol ef16sym;
static funcptr ef16;
static Symbol ef17sym;
static funcptr ef17;
static Symbol ef19sym;
static funcptr ef19;
static Symbol ef25sym;
static funcptr ef25;
static Symbol ef26sym;
static funcptr ef26;
static Symbol ef18sym;
static funcptr ef18;
static Symbol ef23sym;
static funcptr ef23;
static Symbol ef24sym;
static funcptr ef24;
static Symbol lf7sym;
static ATerm lf7( ATerm arg1);
static Symbol ef20sym;
static funcptr ef20;
static Symbol ef21sym;
static funcptr ef21;
static Symbol ef22sym;
static funcptr ef22;
static Symbol ef28sym;
static funcptr ef28;
static Symbol ef29sym;
static funcptr ef29;
static Symbol ef30sym;
static funcptr ef30;
static Symbol ef39sym;
static funcptr ef39;
static Symbol ef40sym;
static funcptr ef40;
static Symbol ef32sym;
static funcptr ef32;
static Symbol lf8sym;
static ATerm lf8( ATerm arg1);
static Symbol ef33sym;
static funcptr ef33;
static Symbol ef2sym;
static funcptr ef2;
static Symbol lf_AUX_MuASF_Sign2C5_1sym;
static ATerm lf_AUX_MuASF_Sign2C5_1( ATerm arg1);
static Symbol ef3sym;
static funcptr ef3;
static Symbol lf4sym;
static ATerm lf4( ATerm arg1);
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef5sym;
static funcptr ef5;
static Symbol ef6sym;
static funcptr ef6;
static Symbol ef7sym;
static funcptr ef7;
static Symbol ef8sym;
static funcptr ef8;
static Symbol lf5sym;
static ATerm lf5( ATerm arg1);
static Symbol ef9sym;
static funcptr ef9;
static Symbol ef10sym;
static funcptr ef10;
static Symbol ef12sym;
static funcptr ef12;
static Symbol ef11sym;
static funcptr ef11;
static Symbol ef34sym;
static funcptr ef34;
static Symbol ef36sym;
static funcptr ef36;
static Symbol lf9sym;
static ATerm lf9( ATerm arg1);
static Symbol ef37sym;
static funcptr ef37;
static Symbol lf3sym;
static ATerm lf3( ATerm arg1);
static Symbol ef38sym;
static funcptr ef38;
void register_AUX_MuASF_Sign2C5( ) {
lf_AUX_MuASF_Sign2C5_2sym= ATmakeSymbol( "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"funcdef2cfuncs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Sign2C5_2sym);
lf6sym= ATmakeSymbol( "listtype(sort(\"Parameter-declaration\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf6sym);
lf7sym= ATmakeSymbol( "listtype(sort(\"Expression\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf7sym);
lf8sym= ATmakeSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf8sym);
lf_AUX_MuASF_Sign2C5_1sym= ATmakeSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Sign2C5_1sym);
lf4sym= ATmakeSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf4sym);
lf5sym= ATmakeSymbol( "listtype(sort(\"Type-specifier\"))" , 1 , ATtrue);
ATprotectSymbol( lf5sym);
lf9sym= ATmakeSymbol( "listtype(sort(\"SigArg\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf9sym);
lf3sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf3sym);
register_prod( ATparse( "listtype(sort(\"NamePair\"),ql(\",\"))") , lf_AUX_MuASF_Sign2C5_1 , lf_AUX_MuASF_Sign2C5_1sym);
register_prod( ATparse( "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"funcdef2cfuncs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Sign2C5_2 , lf_AUX_MuASF_Sign2C5_2sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
register_prod( ATparse( "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf4 , lf4sym);
register_prod( ATparse( "listtype(sort(\"Type-specifier\"))") , lf5 , lf5sym);
register_prod( ATparse( "listtype(sort(\"Parameter-declaration\"),ql(\",\"))") , lf6 , lf6sym);
register_prod( ATparse( "listtype(sort(\"Expression\"),ql(\",\"))") , lf7 , lf7sym);
register_prod( ATparse( "listtype(sort(\"Term\"),ql(\",\"))") , lf8 , lf8sym);
register_prod( ATparse( "listtype(sort(\"SigArg\"),ql(\",\"))") , lf9 , lf9sym);
}
void resolve_AUX_MuASF_Sign2C5( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\"),w(\"\"),sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\"),w(\"\"),sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
ef6= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
ef7= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)"));
ef8= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Type-specifier\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-specifiers\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Type-specifier\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-specifiers\"),w(\"\"),no-attrs)"));
ef9= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[l(\"static\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[l(\"static\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)"));
ef10= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)"));
ef11= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef12= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)"));
ef13= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)"));
ef14= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)"));
ef15= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef16= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef17= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef18= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef19= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef19sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef20= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef20sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef21= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)"));
ef21sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)"));
ef22= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef22sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef23= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef23sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef24= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
ef24sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
ef25= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Integer-constant\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef25sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Integer-constant\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef26= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"integer-constant\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Integer-constant\"),w(\"\"),no-attrs)"));
ef26sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"integer-constant\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Integer-constant\"),w(\"\"),no-attrs)"));
ef27= lookup_func( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[l(\"pn-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef27sym= lookup_sym( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[l(\"pn-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef28= lookup_func( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef28sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef29= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef29sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef30= lookup_func( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[l(\"np-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef30sym= lookup_sym( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[l(\"np-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef31= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),sort(\"Props\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef31sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),sort(\"Props\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef32= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Props\"),w(\"\"),no-attrs)"));
ef32sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Props\"),w(\"\"),no-attrs)"));
ef33= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef33sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef34= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef34sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef35= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef35sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef36= lookup_func( ATreadFromString( "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"sigargs2cargs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)"));
ef36sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"sigargs2cargs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)"));
ef37= lookup_func( ATreadFromString( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)"));
ef37sym= lookup_sym( ATreadFromString( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)"));
ef38= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)"));
ef38sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)"));
ef39= lookup_func( ATreadFromString( "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"countsigargs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)"));
ef39sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"countsigargs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)"));
ef40= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\"),w(\"\"),sort(\"Props\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef40sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\"),w(\"\"),sort(\"Props\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
static ATerm constant2= NULL;
static ATerm constant3= NULL;
static ATerm constant4= NULL;
static ATerm constant5= NULL;
static ATerm constant6= NULL;
static ATerm constant7= NULL;
static ATerm constant8= NULL;
static ATerm constant9= NULL;
static ATerm constant10= NULL;
static ATerm constant11= NULL;
static ATerm constant12= NULL;
static ATerm constant13= NULL;
static ATerm constant14= NULL;
static ATerm constant15= NULL;
static ATerm constant16= NULL;
static ATerm constant17= NULL;
static ATerm constant18= NULL;
static ATerm constant19= NULL;
static ATerm constant20= NULL;
static ATerm constant21= NULL;
static ATerm constant22= NULL;
static ATerm constant23= NULL;
static ATerm constant24= NULL;
static ATerm constant25= NULL;
static ATerm constant26= NULL;
void init_AUX_MuASF_Sign2C5( ) {
ATprotect( & constant0);
ATprotect( & constant1);
ATprotect( & constant2);
ATprotect( & constant3);
ATprotect( & constant4);
ATprotect( & constant5);
ATprotect( & constant6);
ATprotect( & constant7);
ATprotect( & constant8);
ATprotect( & constant9);
ATprotect( & constant10);
ATprotect( & constant11);
ATprotect( & constant12);
ATprotect( & constant13);
ATprotect( & constant14);
ATprotect( & constant15);
ATprotect( & constant16);
ATprotect( & constant17);
ATprotect( & constant18);
ATprotect( & constant19);
ATprotect( & constant20);
ATprotect( & constant21);
ATprotect( & constant22);
ATprotect( & constant23);
ATprotect( & constant24);
ATprotect( & constant25);
ATprotect( & constant26);
}
ATerm lf_AUX_MuASF_Sign2C5_2( ATerm arg0 , ATerm arg1) {
{
ATerm tmp[12];
PROF( prof_lf_AUX_MuASF_Sign2C5_2);
if( check_sym( arg0 , ef1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef2sym)) {
{
ATerm atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf3sym)) {
{
ATerm atmp0000= arg_0( atmp000);
if( check_sym( arg1 , lf_AUX_MuASF_Sign2C5_1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( not_empty_list( atmp0000)) {
if( term_equal( list_head( atmp0000) , make_char( 34))) {
tmp[ 0]= list_tail( atmp0000);
if( not_empty_list( tmp[ 0])) {
if( term_equal( list_head( tmp[ 0]) , make_char( 123))) {
tmp[ 1]= list_tail( tmp[ 0]);
tmp[ 2]= list_prefix( tmp[ 1]);
if( not_empty_list( tmp[ 1])) {
if( term_equal( list_last( tmp[ 1]) , make_char( 34))) {
tmp[ 3]= list_prefix( tmp[ 2]);
if( not_empty_list( tmp[ 2])) {
if( term_equal( list_last( tmp[ 2]) , make_char( 125))) {
tmp[ 4]= ( * ef27)( ( * ef2)( lf3( cons( ( constant0? constant0: ( constant0= make_list( make_char( 34)))) , cons( ( constant1? constant1: ( constant1= make_list( make_char( 123)))) , cons( make_list( tmp[ 3]) , ( constant2? constant2: ( constant2= cons( make_list( make_char( 125)) , make_list( make_char( 34)))))))))) , lf_AUX_MuASF_Sign2C5_1( make_list( atmp10)));
if( check_sym( tmp[ 4] , ef2sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 5] , lf3sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
return ( * ef3)( lf4( make_list( ( * ef1)( ( * ef2)( lf3( make_list( tmp[ 6])))))) , ( * ef4)( ( * ef5)( ( * ef6)( ( * ef7)( ( constant3? constant3: ( constant3= ( * ef8)( lf5( cons( make_list( ( * ef9)( )) , make_list( ( * ef10)( ( * ef11)( lf3( (ATerm) ATmakeList( 6 , char_table[ 83] , char_table[ 121] , char_table[ 109] , char_table[ 98] , char_table[ 111] , char_table[ 108])))))))))) , ( * ef12)( ( * ef11)( lf3( cons( make_list( tmp[ 6]) , ( constant4? constant4: ( constant4= (ATerm) ATmakeList( 3 , char_table[ 115] , char_table[ 121] , char_table[ 109]))))))))) , ( * ef7)( ( constant5? constant5: ( constant5= ( * ef8)( lf5( cons( make_list( ( * ef9)( )) , make_list( ( * ef10)( ( * ef11)( lf3( (ATerm) ATmakeList( 5 , char_table[ 65] , char_table[ 84] , char_table[ 101] , char_table[ 114] , char_table[ 109])))))))))) , ( * ef13)( ( * ef11)( lf3( make_list( tmp[ 6]))) , ( constant6? constant6: ( constant6= ( * ef14)( lf6( make_list( null( )))))))))) , ( * ef15)( ( * ef16)( ( * ef17)( ( * ef18)( ( * ef19)( ( * ef20)( ( * ef21)( ( * ef22)( ( * ef11)( lf3( cons( make_list( tmp[ 6]) , ( constant4? constant4: ( constant4= (ATerm) ATmakeList( 3 , char_table[ 115] , char_table[ 121] , char_table[ 109]))))))))) , ( * ef20)( ( * ef21)( ( * ef23)( ( constant7? constant7: ( constant7= ( * ef22)( ( * ef11)( lf3( (ATerm) ATmakeList( 12 , char_table[ 65] , char_table[ 84] , char_table[ 109] , char_table[ 97] , char_table[ 107] , char_table[ 101] , char_table[ 83] , char_table[ 121] , char_table[ 109] , char_table[ 98] , char_table[ 111] , char_table[ 108])))))) , ( * ef24)( lf7( cons( make_list( ( * ef20)( ( * ef21)( ( * ef22)( ( * ef11)( lf3( cons( ( constant8? constant8: ( constant8= make_list_char( 34))) , cons( ( constant9? constant9: ( constant9= make_list_char( 108))) , cons( ( constant10? constant10: ( constant10= make_list_char( 105))) , cons( ( constant11? constant11: ( constant11= make_list_char( 115))) , cons( ( constant12? constant12: ( constant12= make_list_char( 116))) , cons( ( constant12? constant12: ( constant12= make_list_char( 116))) , cons( ( constant13? constant13: ( constant13= make_list_char( 121))) , cons( ( constant14? constant14: ( constant14= make_list_char( 112))) , cons( ( constant15? constant15: ( constant15= make_list_char( 101))) , cons( ( constant16? constant16: ( constant16= make_list_char( 40))) , cons( make_list( tmp[ 3]) , ( constant17? constant17: ( constant17= (ATerm) ATmakeList( 2 , char_table[ 41] , char_table[ 34])))))))))))))))))))) , ( constant18? constant18: ( constant18= cons( make_list( ( * ef20)( ( * ef21)( ( * ef25)( ( * ef26)( lf3( make_list( make_char( 49)))))))) , make_list( ( * ef20)( ( * ef21)( ( * ef22)( ( * ef11)( lf3( (ATerm) ATmakeList( 6 , char_table[ 65] , char_table[ 84] , char_table[ 116] , char_table[ 114] , char_table[ 117] , char_table[ 101]))))))))))))))))))) , ( * ef18)( ( * ef20)( ( * ef21)( ( * ef23)( ( constant19? constant19: ( constant19= ( * ef22)( ( * ef11)( lf3( (ATerm) ATmakeList( 15 , char_table[ 65] , char_table[ 84] , char_table[ 112] , char_table[ 114] , char_table[ 111] , char_table[ 116] , char_table[ 101] , char_table[ 99] , char_table[ 116] , char_table[ 83] , char_table[ 121] , char_table[ 109] , char_table[ 98] , char_table[ 111] , char_table[ 108])))))) , ( * ef24)( lf7( make_list( ( * ef20)( ( * ef21)( ( * ef22)( ( * ef11)( lf3( cons( make_list( tmp[ 6]) , ( constant4? constant4: ( constant4= (ATerm) ATmakeList( 3 , char_table[ 115] , char_table[ 121] , char_table[ 109])))))))))))))))))));
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
if( term_equal( ( * ef28)( ( * ef2)( lf3( make_list( atmp0000)))) , ( constant20? constant20: ( constant20= ( * ef29)( ))))) {
tmp[ 0]= ( * ef30)( ( * ef2)( lf3( make_list( atmp0000))) , lf_AUX_MuASF_Sign2C5_1( make_list( atmp10)));
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , lf3sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
return ( * ef3)( lf4( make_list( ( * ef1)( ( * ef2)( lf3( make_list( atmp0000)))))) , ( * ef4)( ( * ef5)( ( * ef6)( ( * ef7)( ( constant3? constant3: ( constant3= ( * ef8)( lf5( cons( make_list( ( * ef9)( )) , make_list( ( * ef10)( ( * ef11)( lf3( (ATerm) ATmakeList( 6 , char_table[ 83] , char_table[ 121] , char_table[ 109] , char_table[ 98] , char_table[ 111] , char_table[ 108])))))))))) , ( * ef12)( ( * ef11)( lf3( cons( make_list( atmp0000) , ( constant4? constant4: ( constant4= (ATerm) ATmakeList( 3 , char_table[ 115] , char_table[ 121] , char_table[ 109]))))))))) , ( * ef7)( ( constant5? constant5: ( constant5= ( * ef8)( lf5( cons( make_list( ( * ef9)( )) , make_list( ( * ef10)( ( * ef11)( lf3( (ATerm) ATmakeList( 5 , char_table[ 65] , char_table[ 84] , char_table[ 101] , char_table[ 114] , char_table[ 109])))))))))) , ( * ef13)( ( * ef11)( lf3( make_list( atmp0000))) , ( constant6? constant6: ( constant6= ( * ef14)( lf6( make_list( null( )))))))))) , ( * ef15)( ( * ef16)( ( * ef17)( ( * ef18)( ( * ef19)( ( * ef20)( ( * ef21)( ( * ef22)( ( * ef11)( lf3( cons( make_list( atmp0000) , ( constant4? constant4: ( constant4= (ATerm) ATmakeList( 3 , char_table[ 115] , char_table[ 121] , char_table[ 109]))))))))) , ( * ef20)( ( * ef21)( ( * ef23)( ( constant7? constant7: ( constant7= ( * ef22)( ( * ef11)( lf3( (ATerm) ATmakeList( 12 , char_table[ 65] , char_table[ 84] , char_table[ 109] , char_table[ 97] , char_table[ 107] , char_table[ 101] , char_table[ 83] , char_table[ 121] , char_table[ 109] , char_table[ 98] , char_table[ 111] , char_table[ 108])))))) , ( * ef24)( lf7( cons( make_list( ( * ef20)( ( * ef21)( ( * ef22)( ( * ef11)( lf3( make_list( tmp[ 2]))))))) , ( constant21? constant21: ( constant21= cons( make_list( ( * ef20)( ( * ef21)( ( * ef25)( ( * ef26)( lf3( make_list( make_char( 48)))))))) , make_list( ( * ef20)( ( * ef21)( ( * ef22)( ( * ef11)( lf3( (ATerm) ATmakeList( 6 , char_table[ 65] , char_table[ 84] , char_table[ 116] , char_table[ 114] , char_table[ 117] , char_table[ 101]))))))))))))))))))) , ( * ef18)( ( * ef20)( ( * ef21)( ( * ef23)( ( constant19? constant19: ( constant19= ( * ef22)( ( * ef11)( lf3( (ATerm) ATmakeList( 15 , char_table[ 65] , char_table[ 84] , char_table[ 112] , char_table[ 114] , char_table[ 111] , char_table[ 116] , char_table[ 101] , char_table[ 99] , char_table[ 116] , char_table[ 83] , char_table[ 121] , char_table[ 109] , char_table[ 98] , char_table[ 111] , char_table[ 108])))))) , ( * ef24)( lf7( make_list( ( * ef20)( ( * ef21)( ( * ef22)( ( * ef11)( lf3( cons( make_list( atmp0000) , ( constant4? constant4: ( constant4= (ATerm) ATmakeList( 3 , char_table[ 115] , char_table[ 121] , char_table[ 109])))))))))))))))))));
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
if( check_sym( arg0 , ef31sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef2sym)) {
{
ATerm atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf3sym)) {
{
ATerm atmp0000= arg_0( atmp000);
{
ATerm atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef32sym)) {
{
ATerm atmp010= arg_0( atmp01);
if( check_sym( atmp010 , lf8sym)) {
{
ATerm atmp0100= arg_0( atmp010);
if( check_sym( arg1 , lf_AUX_MuASF_Sign2C5_1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( is_single_element( atmp0100)) {
tmp[ 0]= list_head( atmp0100);
if( check_sym( tmp[ 0] , ef33sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , ef2sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , lf3sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
if( not_empty_list( tmp[ 3])) {
if( term_equal( list_head( tmp[ 3]) , make_char( 101))) {
tmp[ 4]= list_tail( tmp[ 3]);
if( not_empty_list( tmp[ 4])) {
if( term_equal( list_head( tmp[ 4]) , make_char( 120))) {
tmp[ 5]= list_tail( tmp[ 4]);
if( not_empty_list( tmp[ 5])) {
if( term_equal( list_head( tmp[ 5]) , make_char( 116))) {
tmp[ 6]= list_tail( tmp[ 5]);
if( not_empty_list( tmp[ 6])) {
if( term_equal( list_head( tmp[ 6]) , make_char( 101))) {
tmp[ 7]= list_tail( tmp[ 6]);
if( not_empty_list( tmp[ 7])) {
if( term_equal( list_head( tmp[ 7]) , make_char( 114))) {
tmp[ 8]= list_tail( tmp[ 7]);
if( not_empty_list( tmp[ 8])) {
if( term_equal( list_head( tmp[ 8]) , make_char( 110))) {
tmp[ 9]= list_tail( tmp[ 8]);
if( not_empty_list( tmp[ 9])) {
if( term_equal( list_head( tmp[ 9]) , make_char( 97))) {
tmp[ 10]= list_tail( tmp[ 9]);
if( is_single_element( tmp[ 10])) {
if( term_equal( list_head( tmp[ 10]) , make_char( 108))) {
return ( * ef3)( ( constant22? constant22: ( constant22= lf4( make_list( null( ))))) , ( * ef4)( ( * ef5)( ( * ef6)( ( * ef7)( ( constant3? constant3: ( constant3= ( * ef8)( lf5( cons( make_list( ( * ef9)( )) , make_list( ( * ef10)( ( * ef11)( lf3( (ATerm) ATmakeList( 6 , char_table[ 83] , char_table[ 121] , char_table[ 109] , char_table[ 98] , char_table[ 111] , char_table[ 108])))))))))) , ( * ef12)( ( * ef11)( lf3( cons( make_list( atmp0000) , ( constant4? constant4: ( constant4= (ATerm) ATmakeList( 3 , char_table[ 115] , char_table[ 121] , char_table[ 109]))))))))) , ( * ef7)( ( constant23? constant23: ( constant23= ( * ef8)( lf5( cons( make_list( ( * ef9)( )) , make_list( ( * ef10)( ( * ef11)( lf3( (ATerm) ATmakeList( 7 , char_table[ 102] , char_table[ 117] , char_table[ 110] , char_table[ 99] , char_table[ 112] , char_table[ 116] , char_table[ 114])))))))))) , ( * ef12)( ( * ef11)( lf3( make_list( atmp0000))))))) , ( constant24? constant24: ( constant24= ( * ef34)( ))));
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
if( check_sym( arg0 , ef35sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef2sym)) {
{
ATerm atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf3sym)) {
{
ATerm atmp0000= arg_0( atmp000);
{
ATerm atmp01= arg_1( arg0);
if( check_sym( atmp01 , lf9sym)) {
{
ATerm atmp010= arg_0( atmp01);
if( check_sym( arg1 , lf_AUX_MuASF_Sign2C5_1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( not_empty_list( atmp0000)) {
if( term_equal( list_head( atmp0000) , make_char( 34))) {
tmp[ 0]= list_tail( atmp0000);
if( not_empty_list( tmp[ 0])) {
if( term_equal( list_head( tmp[ 0]) , make_char( 123))) {
tmp[ 1]= list_tail( tmp[ 0]);
tmp[ 2]= list_prefix( tmp[ 1]);
if( not_empty_list( tmp[ 1])) {
if( term_equal( list_last( tmp[ 1]) , make_char( 34))) {
tmp[ 3]= list_prefix( tmp[ 2]);
if( not_empty_list( tmp[ 2])) {
if( term_equal( list_last( tmp[ 2]) , make_char( 125))) {
if( not_empty_list( atmp010)) {
tmp[ 4]= ( * ef27)( ( * ef2)( lf3( cons( ( constant0? constant0: ( constant0= make_list( make_char( 34)))) , cons( ( constant1? constant1: ( constant1= make_list( make_char( 123)))) , cons( make_list( tmp[ 3]) , ( constant2? constant2: ( constant2= cons( make_list( make_char( 125)) , make_list( make_char( 34)))))))))) , lf_AUX_MuASF_Sign2C5_1( make_list( atmp10)));
if( check_sym( tmp[ 4] , ef2sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 5] , lf3sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
tmp[ 7]= ( * ef36)( lf9( make_list( atmp010)) , ( constant25? constant25: ( constant25= ( * ef37)( ( * ef38)( lf3( make_list( make_char( 49))))))));
return ( * ef3)( lf4( make_list( ( * ef35)( ( * ef2)( lf3( make_list( tmp[ 6]))) , lf9( make_list( atmp010))))) , ( * ef4)( ( * ef5)( ( * ef6)( ( * ef7)( ( constant3? constant3: ( constant3= ( * ef8)( lf5( cons( make_list( ( * ef9)( )) , make_list( ( * ef10)( ( * ef11)( lf3( (ATerm) ATmakeList( 6 , char_table[ 83] , char_table[ 121] , char_table[ 109] , char_table[ 98] , char_table[ 111] , char_table[ 108])))))))))) , ( * ef12)( ( * ef11)( lf3( cons( make_list( tmp[ 6]) , ( constant4? constant4: ( constant4= (ATerm) ATmakeList( 3 , char_table[ 115] , char_table[ 121] , char_table[ 109]))))))))) , ( * ef7)( ( constant5? constant5: ( constant5= ( * ef8)( lf5( cons( make_list( ( * ef9)( )) , make_list( ( * ef10)( ( * ef11)( lf3( (ATerm) ATmakeList( 5 , char_table[ 65] , char_table[ 84] , char_table[ 101] , char_table[ 114] , char_table[ 109])))))))))) , ( * ef13)( ( * ef11)( lf3( make_list( tmp[ 6]))) , tmp[ 7])))) , ( * ef15)( ( * ef16)( ( * ef17)( ( * ef18)( ( * ef19)( ( * ef20)( ( * ef21)( ( * ef22)( ( * ef11)( lf3( cons( make_list( tmp[ 6]) , ( constant4? constant4: ( constant4= (ATerm) ATmakeList( 3 , char_table[ 115] , char_table[ 121] , char_table[ 109]))))))))) , ( * ef20)( ( * ef21)( ( * ef23)( ( constant7? constant7: ( constant7= ( * ef22)( ( * ef11)( lf3( (ATerm) ATmakeList( 12 , char_table[ 65] , char_table[ 84] , char_table[ 109] , char_table[ 97] , char_table[ 107] , char_table[ 101] , char_table[ 83] , char_table[ 121] , char_table[ 109] , char_table[ 98] , char_table[ 111] , char_table[ 108])))))) , ( * ef24)( lf7( cons( make_list( ( * ef20)( ( * ef21)( ( * ef22)( ( * ef11)( lf3( cons( ( constant8? constant8: ( constant8= make_list_char( 34))) , cons( ( constant9? constant9: ( constant9= make_list_char( 108))) , cons( ( constant10? constant10: ( constant10= make_list_char( 105))) , cons( ( constant11? constant11: ( constant11= make_list_char( 115))) , cons( ( constant12? constant12: ( constant12= make_list_char( 116))) , cons( ( constant12? constant12: ( constant12= make_list_char( 116))) , cons( ( constant13? constant13: ( constant13= make_list_char( 121))) , cons( ( constant14? constant14: ( constant14= make_list_char( 112))) , cons( ( constant15? constant15: ( constant15= make_list_char( 101))) , cons( ( constant16? constant16: ( constant16= make_list_char( 40))) , cons( make_list( tmp[ 3]) , ( constant17? constant17: ( constant17= (ATerm) ATmakeList( 2 , char_table[ 41] , char_table[ 34])))))))))))))))))))) , ( constant18? constant18: ( constant18= cons( make_list( ( * ef20)( ( * ef21)( ( * ef25)( ( * ef26)( lf3( make_list( make_char( 49)))))))) , make_list( ( * ef20)( ( * ef21)( ( * ef22)( ( * ef11)( lf3( (ATerm) ATmakeList( 6 , char_table[ 65] , char_table[ 84] , char_table[ 116] , char_table[ 114] , char_table[ 117] , char_table[ 101]))))))))))))))))))) , ( * ef18)( ( * ef20)( ( * ef21)( ( * ef23)( ( constant19? constant19: ( constant19= ( * ef22)( ( * ef11)( lf3( (ATerm) ATmakeList( 15 , char_table[ 65] , char_table[ 84] , char_table[ 112] , char_table[ 114] , char_table[ 111] , char_table[ 116] , char_table[ 101] , char_table[ 99] , char_table[ 116] , char_table[ 83] , char_table[ 121] , char_table[ 109] , char_table[ 98] , char_table[ 111] , char_table[ 108])))))) , ( * ef24)( lf7( make_list( ( * ef20)( ( * ef21)( ( * ef22)( ( * ef11)( lf3( cons( make_list( tmp[ 6]) , ( constant4? constant4: ( constant4= (ATerm) ATmakeList( 3 , char_table[ 115] , char_table[ 121] , char_table[ 109])))))))))))))))))));
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
if( not_empty_list( atmp010)) {
if( term_equal( ( * ef28)( ( * ef2)( lf3( make_list( atmp0000)))) , ( constant20? constant20: ( constant20= ( * ef29)( ))))) {
tmp[ 0]= ( * ef30)( ( * ef2)( lf3( make_list( atmp0000))) , lf_AUX_MuASF_Sign2C5_1( make_list( atmp10)));
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , lf3sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
tmp[ 3]= ( * ef36)( lf9( make_list( atmp010)) , ( constant25? constant25: ( constant25= ( * ef37)( ( * ef38)( lf3( make_list( make_char( 49))))))));
tmp[ 4]= ( * ef39)( lf9( make_list( atmp010)));
if( check_sym( tmp[ 4] , ef37sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 5] , ef38sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
if( check_sym( tmp[ 6] , lf3sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
return ( * ef3)( lf4( make_list( ( * ef35)( ( * ef2)( lf3( make_list( atmp0000))) , lf9( make_list( atmp010))))) , ( * ef4)( ( * ef5)( ( * ef6)( ( * ef7)( ( constant3? constant3: ( constant3= ( * ef8)( lf5( cons( make_list( ( * ef9)( )) , make_list( ( * ef10)( ( * ef11)( lf3( (ATerm) ATmakeList( 6 , char_table[ 83] , char_table[ 121] , char_table[ 109] , char_table[ 98] , char_table[ 111] , char_table[ 108])))))))))) , ( * ef12)( ( * ef11)( lf3( cons( make_list( atmp0000) , ( constant4? constant4: ( constant4= (ATerm) ATmakeList( 3 , char_table[ 115] , char_table[ 121] , char_table[ 109]))))))))) , ( * ef7)( ( constant5? constant5: ( constant5= ( * ef8)( lf5( cons( make_list( ( * ef9)( )) , make_list( ( * ef10)( ( * ef11)( lf3( (ATerm) ATmakeList( 5 , char_table[ 65] , char_table[ 84] , char_table[ 101] , char_table[ 114] , char_table[ 109])))))))))) , ( * ef13)( ( * ef11)( lf3( make_list( atmp0000))) , tmp[ 3])))) , ( * ef15)( ( * ef16)( ( * ef17)( ( * ef18)( ( * ef19)( ( * ef20)( ( * ef21)( ( * ef22)( ( * ef11)( lf3( cons( make_list( atmp0000) , ( constant4? constant4: ( constant4= (ATerm) ATmakeList( 3 , char_table[ 115] , char_table[ 121] , char_table[ 109]))))))))) , ( * ef20)( ( * ef21)( ( * ef23)( ( constant7? constant7: ( constant7= ( * ef22)( ( * ef11)( lf3( (ATerm) ATmakeList( 12 , char_table[ 65] , char_table[ 84] , char_table[ 109] , char_table[ 97] , char_table[ 107] , char_table[ 101] , char_table[ 83] , char_table[ 121] , char_table[ 109] , char_table[ 98] , char_table[ 111] , char_table[ 108])))))) , ( * ef24)( lf7( cons( make_list( ( * ef20)( ( * ef21)( ( * ef22)( ( * ef11)( lf3( make_list( tmp[ 2]))))))) , cons( make_list( ( * ef20)( ( * ef21)( ( * ef25)( ( * ef26)( lf3( make_list( tmp[ 7]))))))) , ( constant26? constant26: ( constant26= make_list( ( * ef20)( ( * ef21)( ( * ef22)( ( * ef11)( lf3( (ATerm) ATmakeList( 6 , char_table[ 65] , char_table[ 84] , char_table[ 116] , char_table[ 114] , char_table[ 117] , char_table[ 101]))))))))))))))))))) , ( * ef18)( ( * ef20)( ( * ef21)( ( * ef23)( ( constant19? constant19: ( constant19= ( * ef22)( ( * ef11)( lf3( (ATerm) ATmakeList( 15 , char_table[ 65] , char_table[ 84] , char_table[ 112] , char_table[ 114] , char_table[ 111] , char_table[ 116] , char_table[ 101] , char_table[ 99] , char_table[ 116] , char_table[ 83] , char_table[ 121] , char_table[ 109] , char_table[ 98] , char_table[ 111] , char_table[ 108])))))) , ( * ef24)( lf7( make_list( ( * ef20)( ( * ef21)( ( * ef22)( ( * ef11)( lf3( cons( make_list( atmp0000) , ( constant4? constant4: ( constant4= (ATerm) ATmakeList( 3 , char_table[ 115] , char_table[ 121] , char_table[ 109])))))))))))))))))));
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
if( check_sym( arg0 , ef40sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef2sym)) {
{
ATerm atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf3sym)) {
{
ATerm atmp0000= arg_0( atmp000);
{
ATerm atmp01= arg_1( arg0);
if( check_sym( atmp01 , lf9sym)) {
{
ATerm atmp010= arg_0( atmp01);
{
ATerm atmp02= arg_2( arg0);
if( check_sym( atmp02 , ef32sym)) {
{
ATerm atmp020= arg_0( atmp02);
if( check_sym( atmp020 , lf8sym)) {
{
ATerm atmp0200= arg_0( atmp020);
if( check_sym( arg1 , lf_AUX_MuASF_Sign2C5_1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( not_empty_list( atmp010)) {
if( is_single_element( atmp0200)) {
tmp[ 0]= list_head( atmp0200);
if( check_sym( tmp[ 0] , ef33sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , ef2sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , lf3sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
if( not_empty_list( tmp[ 3])) {
if( term_equal( list_head( tmp[ 3]) , make_char( 101))) {
tmp[ 4]= list_tail( tmp[ 3]);
if( not_empty_list( tmp[ 4])) {
if( term_equal( list_head( tmp[ 4]) , make_char( 120))) {
tmp[ 5]= list_tail( tmp[ 4]);
if( not_empty_list( tmp[ 5])) {
if( term_equal( list_head( tmp[ 5]) , make_char( 116))) {
tmp[ 6]= list_tail( tmp[ 5]);
if( not_empty_list( tmp[ 6])) {
if( term_equal( list_head( tmp[ 6]) , make_char( 101))) {
tmp[ 7]= list_tail( tmp[ 6]);
if( not_empty_list( tmp[ 7])) {
if( term_equal( list_head( tmp[ 7]) , make_char( 114))) {
tmp[ 8]= list_tail( tmp[ 7]);
if( not_empty_list( tmp[ 8])) {
if( term_equal( list_head( tmp[ 8]) , make_char( 110))) {
tmp[ 9]= list_tail( tmp[ 8]);
if( not_empty_list( tmp[ 9])) {
if( term_equal( list_head( tmp[ 9]) , make_char( 97))) {
tmp[ 10]= list_tail( tmp[ 9]);
if( is_single_element( tmp[ 10])) {
if( term_equal( list_head( tmp[ 10]) , make_char( 108))) {
tmp[ 11]= ( * ef36)( lf9( make_list( atmp010)) , ( constant25? constant25: ( constant25= ( * ef37)( ( * ef38)( lf3( make_list( make_char( 49))))))));
return ( * ef3)( ( constant22? constant22: ( constant22= lf4( make_list( null( ))))) , ( * ef4)( ( * ef5)( ( * ef6)( ( * ef7)( ( constant3? constant3: ( constant3= ( * ef8)( lf5( cons( make_list( ( * ef9)( )) , make_list( ( * ef10)( ( * ef11)( lf3( (ATerm) ATmakeList( 6 , char_table[ 83] , char_table[ 121] , char_table[ 109] , char_table[ 98] , char_table[ 111] , char_table[ 108])))))))))) , ( * ef12)( ( * ef11)( lf3( cons( make_list( atmp0000) , ( constant4? constant4: ( constant4= (ATerm) ATmakeList( 3 , char_table[ 115] , char_table[ 121] , char_table[ 109]))))))))) , ( * ef7)( ( constant23? constant23: ( constant23= ( * ef8)( lf5( cons( make_list( ( * ef9)( )) , make_list( ( * ef10)( ( * ef11)( lf3( (ATerm) ATmakeList( 7 , char_table[ 102] , char_table[ 117] , char_table[ 110] , char_table[ 99] , char_table[ 112] , char_table[ 116] , char_table[ 114])))))))))) , ( * ef12)( ( * ef11)( lf3( make_list( atmp0000))))))) , ( constant24? constant24: ( constant24= ( * ef34)( ))));
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
}
return make_nf2( lf_AUX_MuASF_Sign2C5_2sym , arg0 , arg1);
}
}
ATerm lf3( ATerm arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
ATerm lf9( ATerm arg0) {
PROF( prof_lf9);
return make_nf1( lf9sym , arg0);
}
ATerm lf5( ATerm arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}
ATerm lf4( ATerm arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
ATerm lf_AUX_MuASF_Sign2C5_1( ATerm arg0) {
PROF( prof_lf_AUX_MuASF_Sign2C5_1);
return make_nf1( lf_AUX_MuASF_Sign2C5_1sym , arg0);
}
ATerm lf8( ATerm arg0) {
PROF( prof_lf8);
return make_nf1( lf8sym , arg0);
}
ATerm lf7( ATerm arg0) {
PROF( prof_lf7);
return make_nf1( lf7sym , arg0);
}
ATerm lf6( ATerm arg0) {
PROF( prof_lf6);
return make_nf1( lf6sym , arg0);
}

