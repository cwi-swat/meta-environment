#include "support.h"
static asymbol * lf_AUX_Pure_C3_2sym;
static aterm * lf_AUX_Pure_C3_2( aterm * arg1);
static asymbol * lf_AUX_Pure_C3_3sym;
static aterm * lf_AUX_Pure_C3_3( aterm * arg1);
static asymbol * lf_AUX_Pure_C3_1sym;
static aterm * lf_AUX_Pure_C3_1( aterm * arg1);
static asymbol * lf_AUX_Pure_C3_4sym;
static aterm * lf_AUX_Pure_C3_4( aterm * arg1);
static asymbol * lf_AUX_Pure_C3_5sym;
static aterm * lf_AUX_Pure_C3_5( aterm * arg1);
static asymbol * lf_AUX_Pure_C3_6sym;
static aterm * lf_AUX_Pure_C3_6( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Pure_C3_7sym;
static aterm * lf_AUX_Pure_C3_7( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Pure_C3_8sym;
static aterm * lf_AUX_Pure_C3_8( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * lf_AUX_Pure_C3_9sym;
static aterm * lf_AUX_Pure_C3_9( aterm * arg1);
static asymbol * lf_AUX_Pure_C3_10sym;
static aterm * lf_AUX_Pure_C3_10( aterm * arg1);
static asymbol * lf_AUX_Pure_C3_11sym;
static aterm * lf_AUX_Pure_C3_11( );
static asymbol * lf_AUX_Pure_C3_12sym;
static aterm * lf_AUX_Pure_C3_12( aterm * arg1);
static asymbol * lf_AUX_Pure_C3_13sym;
static aterm * lf_AUX_Pure_C3_13( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * lf_AUX_Pure_C3_14sym;
static aterm * lf_AUX_Pure_C3_14( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Pure_C3_15sym;
static aterm * lf_AUX_Pure_C3_15( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * lf_AUX_Pure_C3_16sym;
static aterm * lf_AUX_Pure_C3_16( aterm * arg1);
static asymbol * lf_AUX_Pure_C3_17sym;
static aterm * lf_AUX_Pure_C3_17( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Pure_C3_18sym;
static aterm * lf_AUX_Pure_C3_18( );
static asymbol * lf_AUX_Pure_C3_19sym;
static aterm * lf_AUX_Pure_C3_19( aterm * arg1);
static asymbol * lf_AUX_Pure_C3_21sym;
static aterm * lf_AUX_Pure_C3_21( aterm * arg1);
static asymbol * lf_AUX_Pure_C3_20sym;
static aterm * lf_AUX_Pure_C3_20( aterm * arg1);
static asymbol * lf_AUX_Pure_C3_22sym;
static aterm * lf_AUX_Pure_C3_22( );
static asymbol * lf_AUX_Pure_C3_23sym;
static aterm * lf_AUX_Pure_C3_23( );
static asymbol * lf_AUX_Pure_C3_24sym;
static aterm * lf_AUX_Pure_C3_24( aterm * arg1);
static asymbol * lf_AUX_Pure_C3_25sym;
static aterm * lf_AUX_Pure_C3_25( aterm * arg1);
static asymbol * lf_AUX_Pure_C3_26sym;
static aterm * lf_AUX_Pure_C3_26( aterm * arg1);
static asymbol * lf_AUX_Pure_C3_27sym;
static aterm * lf_AUX_Pure_C3_27( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Pure_C3_28sym;
static aterm * lf_AUX_Pure_C3_28( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Pure_C3_30sym;
static aterm * lf_AUX_Pure_C3_30( aterm * arg1);
static asymbol * lf_AUX_Pure_C3_29sym;
static aterm * lf_AUX_Pure_C3_29( aterm * arg1);
static asymbol * lf_AUX_Pure_C3_31sym;
static aterm * lf_AUX_Pure_C3_31( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Pure_C3_32sym;
static aterm * lf_AUX_Pure_C3_32( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Pure_C3_33sym;
static aterm * lf_AUX_Pure_C3_33( aterm * arg1);
static asymbol * lf_AUX_Pure_C3_34sym;
static aterm * lf_AUX_Pure_C3_34( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Pure_C3_35sym;
static aterm * lf_AUX_Pure_C3_35( );
static asymbol * lf_AUX_Pure_C3_36sym;
static aterm * lf_AUX_Pure_C3_36( );
static asymbol * lf_AUX_Pure_C3_37sym;
static aterm * lf_AUX_Pure_C3_37( );
static asymbol * lf_AUX_Pure_C3_38sym;
static aterm * lf_AUX_Pure_C3_38( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Pure_C3_39sym;
static aterm * lf_AUX_Pure_C3_39( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Pure_C3_40sym;
static aterm * lf_AUX_Pure_C3_40( aterm * arg1);
static asymbol * lf_AUX_Pure_C3_41sym;
static aterm * lf_AUX_Pure_C3_41( aterm * arg1);
static asymbol * lf_AUX_Pure_C3_42sym;
static aterm * lf_AUX_Pure_C3_42( aterm * arg1);
static asymbol * lf_AUX_Pure_C3_43sym;
static aterm * lf_AUX_Pure_C3_43( aterm * arg1);
static asymbol * lf_AUX_Pure_C3_45sym;
static aterm * lf_AUX_Pure_C3_45( aterm * arg1);
static asymbol * lf_AUX_Pure_C3_44sym;
static aterm * lf_AUX_Pure_C3_44( aterm * arg1);
void register_AUX_Pure_C3( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Pure_C3_2sym= TmkSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"integer-constant\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Integer-constant\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Pure_C3_3sym= TmkSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_1sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf_AUX_Pure_C3_4sym= TmkSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"string\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"String\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_5sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_6sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_7sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_8sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\"),w(\"\"),l(\"else\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_9sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[l(\"return\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_10sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_11sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_12sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_13sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_14sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_15sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_16sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_17sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\"),w(\"\"),sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_18sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_19sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_21sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Type-specifier\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-specifiers\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_20sym= TmkSymbol( "listtype(sort(\"Type-specifier\"))" , SYM_STRING);
lf_AUX_Pure_C3_22sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[l(\"static\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_23sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[l(\"void\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_24sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_25sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"*\"),w(\"\"),sort(\"Declarator\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_26sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_27sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"Integer-constant\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_28sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_30sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_29sym= TmkSymbol( "listtype(sort(\"Parameter-declaration\"),ql(\",\"))" , SYM_STRING);
lf_AUX_Pure_C3_31sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_32sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_33sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_34sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Unary-operator\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_35sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"&\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Unary-operator\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_36sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Unary-operator\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_37sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"!\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Unary-operator\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_38sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_39sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_40sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_41sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Integer-constant\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_42sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"String\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_43sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_45sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C3_44sym= TmkSymbol( "listtype(sort(\"Expression\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf_AUX_Pure_C3_1 , lf_AUX_Pure_C3_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"integer-constant\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Integer-constant\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_2 , lf_AUX_Pure_C3_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_3 , lf_AUX_Pure_C3_3sym);
register_prod( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"string\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"String\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_4 , lf_AUX_Pure_C3_4sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_5 , lf_AUX_Pure_C3_5sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_6 , lf_AUX_Pure_C3_6sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_7 , lf_AUX_Pure_C3_7sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\"),w(\"\"),l(\"else\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_8 , lf_AUX_Pure_C3_8sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"return\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_9 , lf_AUX_Pure_C3_9sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_10 , lf_AUX_Pure_C3_10sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_11 , lf_AUX_Pure_C3_11sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_12 , lf_AUX_Pure_C3_12sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_13 , lf_AUX_Pure_C3_13sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_14 , lf_AUX_Pure_C3_14sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_15 , lf_AUX_Pure_C3_15sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_16 , lf_AUX_Pure_C3_16sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\"),w(\"\"),sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_17 , lf_AUX_Pure_C3_17sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_18 , lf_AUX_Pure_C3_18sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_19 , lf_AUX_Pure_C3_19sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Type-specifier\"))") , lf_AUX_Pure_C3_20 , lf_AUX_Pure_C3_20sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Type-specifier\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-specifiers\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_21 , lf_AUX_Pure_C3_21sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"static\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_22 , lf_AUX_Pure_C3_22sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"void\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_23 , lf_AUX_Pure_C3_23sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_24 , lf_AUX_Pure_C3_24sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"*\"),w(\"\"),sort(\"Declarator\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_25 , lf_AUX_Pure_C3_25sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_26 , lf_AUX_Pure_C3_26sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"Integer-constant\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_27 , lf_AUX_Pure_C3_27sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_28 , lf_AUX_Pure_C3_28sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Parameter-declaration\"),ql(\",\"))") , lf_AUX_Pure_C3_29 , lf_AUX_Pure_C3_29sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_30 , lf_AUX_Pure_C3_30sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_31 , lf_AUX_Pure_C3_31sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_32 , lf_AUX_Pure_C3_32sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_33 , lf_AUX_Pure_C3_33sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Unary-operator\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_34 , lf_AUX_Pure_C3_34sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"&\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Unary-operator\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_35 , lf_AUX_Pure_C3_35sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Unary-operator\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_36 , lf_AUX_Pure_C3_36sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"!\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Unary-operator\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_37 , lf_AUX_Pure_C3_37sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_38 , lf_AUX_Pure_C3_38sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_39 , lf_AUX_Pure_C3_39sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_40 , lf_AUX_Pure_C3_40sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Integer-constant\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_41 , lf_AUX_Pure_C3_41sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"String\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_42 , lf_AUX_Pure_C3_42sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_43 , lf_AUX_Pure_C3_43sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Expression\"),ql(\",\"))") , lf_AUX_Pure_C3_44 , lf_AUX_Pure_C3_44sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C3_45 , lf_AUX_Pure_C3_45sym);
}
void resolve_AUX_Pure_C3( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_Pure_C3_44( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C3_44);
return make_nf1( lf_AUX_Pure_C3_44sym , arg0);
}
aterm * lf_AUX_Pure_C3_45( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C3_45);
return make_nf1( lf_AUX_Pure_C3_45sym , arg0);
}
aterm * lf_AUX_Pure_C3_43( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C3_43);
return make_nf1( lf_AUX_Pure_C3_43sym , arg0);
}
aterm * lf_AUX_Pure_C3_42( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C3_42);
return make_nf1( lf_AUX_Pure_C3_42sym , arg0);
}
aterm * lf_AUX_Pure_C3_41( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C3_41);
return make_nf1( lf_AUX_Pure_C3_41sym , arg0);
}
aterm * lf_AUX_Pure_C3_40( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C3_40);
return make_nf1( lf_AUX_Pure_C3_40sym , arg0);
}
aterm * lf_AUX_Pure_C3_39( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Pure_C3_39);
return make_nf2( lf_AUX_Pure_C3_39sym , arg0 , arg1);
}
aterm * lf_AUX_Pure_C3_38( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Pure_C3_38);
return make_nf2( lf_AUX_Pure_C3_38sym , arg0 , arg1);
}
aterm * lf_AUX_Pure_C3_37( ) {
PROF( prof_lf_AUX_Pure_C3_37);
return make_nf0( lf_AUX_Pure_C3_37sym);
}
aterm * lf_AUX_Pure_C3_36( ) {
PROF( prof_lf_AUX_Pure_C3_36);
return make_nf0( lf_AUX_Pure_C3_36sym);
}
aterm * lf_AUX_Pure_C3_35( ) {
PROF( prof_lf_AUX_Pure_C3_35);
return make_nf0( lf_AUX_Pure_C3_35sym);
}
aterm * lf_AUX_Pure_C3_34( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Pure_C3_34);
return make_nf2( lf_AUX_Pure_C3_34sym , arg0 , arg1);
}
aterm * lf_AUX_Pure_C3_33( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C3_33);
return make_nf1( lf_AUX_Pure_C3_33sym , arg0);
}
aterm * lf_AUX_Pure_C3_32( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Pure_C3_32);
return make_nf2( lf_AUX_Pure_C3_32sym , arg0 , arg1);
}
aterm * lf_AUX_Pure_C3_31( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Pure_C3_31);
return make_nf2( lf_AUX_Pure_C3_31sym , arg0 , arg1);
}
aterm * lf_AUX_Pure_C3_29( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C3_29);
return make_nf1( lf_AUX_Pure_C3_29sym , arg0);
}
aterm * lf_AUX_Pure_C3_30( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C3_30);
return make_nf1( lf_AUX_Pure_C3_30sym , arg0);
}
aterm * lf_AUX_Pure_C3_28( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Pure_C3_28);
return make_nf2( lf_AUX_Pure_C3_28sym , arg0 , arg1);
}
aterm * lf_AUX_Pure_C3_27( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Pure_C3_27);
return make_nf2( lf_AUX_Pure_C3_27sym , arg0 , arg1);
}
aterm * lf_AUX_Pure_C3_26( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C3_26);
return make_nf1( lf_AUX_Pure_C3_26sym , arg0);
}
aterm * lf_AUX_Pure_C3_25( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C3_25);
return make_nf1( lf_AUX_Pure_C3_25sym , arg0);
}
aterm * lf_AUX_Pure_C3_24( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C3_24);
return make_nf1( lf_AUX_Pure_C3_24sym , arg0);
}
aterm * lf_AUX_Pure_C3_23( ) {
PROF( prof_lf_AUX_Pure_C3_23);
return make_nf0( lf_AUX_Pure_C3_23sym);
}
aterm * lf_AUX_Pure_C3_22( ) {
PROF( prof_lf_AUX_Pure_C3_22);
return make_nf0( lf_AUX_Pure_C3_22sym);
}
aterm * lf_AUX_Pure_C3_20( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C3_20);
return make_nf1( lf_AUX_Pure_C3_20sym , arg0);
}
aterm * lf_AUX_Pure_C3_21( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C3_21);
return make_nf1( lf_AUX_Pure_C3_21sym , arg0);
}
aterm * lf_AUX_Pure_C3_19( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C3_19);
return make_nf1( lf_AUX_Pure_C3_19sym , arg0);
}
aterm * lf_AUX_Pure_C3_18( ) {
PROF( prof_lf_AUX_Pure_C3_18);
return make_nf0( lf_AUX_Pure_C3_18sym);
}
aterm * lf_AUX_Pure_C3_17( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Pure_C3_17);
return make_nf2( lf_AUX_Pure_C3_17sym , arg0 , arg1);
}
aterm * lf_AUX_Pure_C3_16( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C3_16);
return make_nf1( lf_AUX_Pure_C3_16sym , arg0);
}
aterm * lf_AUX_Pure_C3_15( aterm * arg0 , aterm * arg1 , aterm * arg2) {
PROF( prof_lf_AUX_Pure_C3_15);
return make_nf3( lf_AUX_Pure_C3_15sym , arg0 , arg1 , arg2);
}
aterm * lf_AUX_Pure_C3_14( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Pure_C3_14);
return make_nf2( lf_AUX_Pure_C3_14sym , arg0 , arg1);
}
aterm * lf_AUX_Pure_C3_13( aterm * arg0 , aterm * arg1 , aterm * arg2) {
PROF( prof_lf_AUX_Pure_C3_13);
return make_nf3( lf_AUX_Pure_C3_13sym , arg0 , arg1 , arg2);
}
aterm * lf_AUX_Pure_C3_12( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C3_12);
return make_nf1( lf_AUX_Pure_C3_12sym , arg0);
}
aterm * lf_AUX_Pure_C3_11( ) {
PROF( prof_lf_AUX_Pure_C3_11);
return make_nf0( lf_AUX_Pure_C3_11sym);
}
aterm * lf_AUX_Pure_C3_10( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C3_10);
return make_nf1( lf_AUX_Pure_C3_10sym , arg0);
}
aterm * lf_AUX_Pure_C3_9( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C3_9);
return make_nf1( lf_AUX_Pure_C3_9sym , arg0);
}
aterm * lf_AUX_Pure_C3_8( aterm * arg0 , aterm * arg1 , aterm * arg2) {
PROF( prof_lf_AUX_Pure_C3_8);
return make_nf3( lf_AUX_Pure_C3_8sym , arg0 , arg1 , arg2);
}
aterm * lf_AUX_Pure_C3_7( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Pure_C3_7);
return make_nf2( lf_AUX_Pure_C3_7sym , arg0 , arg1);
}
aterm * lf_AUX_Pure_C3_6( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Pure_C3_6);
return make_nf2( lf_AUX_Pure_C3_6sym , arg0 , arg1);
}
aterm * lf_AUX_Pure_C3_5( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C3_5);
return make_nf1( lf_AUX_Pure_C3_5sym , arg0);
}
aterm * lf_AUX_Pure_C3_4( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C3_4);
return make_nf1( lf_AUX_Pure_C3_4sym , arg0);
}
aterm * lf_AUX_Pure_C3_1( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C3_1);
return make_nf1( lf_AUX_Pure_C3_1sym , arg0);
}
aterm * lf_AUX_Pure_C3_3( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C3_3);
return make_nf1( lf_AUX_Pure_C3_3sym , arg0);
}
aterm * lf_AUX_Pure_C3_2( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C3_2);
return make_nf1( lf_AUX_Pure_C3_2sym , arg0);
}

