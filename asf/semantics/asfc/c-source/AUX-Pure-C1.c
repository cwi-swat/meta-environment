#include "support.h"
static asymbol * lf_AUX_Pure_C1_2sym;
static aterm * lf_AUX_Pure_C1_2( aterm * arg1);
static asymbol * lf_AUX_Pure_C1_3sym;
static aterm * lf_AUX_Pure_C1_3( aterm * arg1);
static asymbol * lf_AUX_Pure_C1_1sym;
static aterm * lf_AUX_Pure_C1_1( aterm * arg1);
static asymbol * lf_AUX_Pure_C1_4sym;
static aterm * lf_AUX_Pure_C1_4( aterm * arg1);
static asymbol * lf_AUX_Pure_C1_5sym;
static aterm * lf_AUX_Pure_C1_5( aterm * arg1);
static asymbol * lf_AUX_Pure_C1_6sym;
static aterm * lf_AUX_Pure_C1_6( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Pure_C1_7sym;
static aterm * lf_AUX_Pure_C1_7( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Pure_C1_8sym;
static aterm * lf_AUX_Pure_C1_8( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * lf_AUX_Pure_C1_9sym;
static aterm * lf_AUX_Pure_C1_9( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Pure_C1_10sym;
static aterm * lf_AUX_Pure_C1_10( aterm * arg1);
static asymbol * lf_AUX_Pure_C1_11sym;
static aterm * lf_AUX_Pure_C1_11( aterm * arg1);
static asymbol * lf_AUX_Pure_C1_12sym;
static aterm * lf_AUX_Pure_C1_12( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Pure_C1_13sym;
static aterm * lf_AUX_Pure_C1_13( );
static asymbol * lf_AUX_Pure_C1_14sym;
static aterm * lf_AUX_Pure_C1_14( aterm * arg1);
static asymbol * lf_AUX_Pure_C1_15sym;
static aterm * lf_AUX_Pure_C1_15( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * lf_AUX_Pure_C1_16sym;
static aterm * lf_AUX_Pure_C1_16( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Pure_C1_17sym;
static aterm * lf_AUX_Pure_C1_17( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * lf_AUX_Pure_C1_18sym;
static aterm * lf_AUX_Pure_C1_18( aterm * arg1);
static asymbol * lf_AUX_Pure_C1_19sym;
static aterm * lf_AUX_Pure_C1_19( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Pure_C1_20sym;
static aterm * lf_AUX_Pure_C1_20( );
static asymbol * lf_AUX_Pure_C1_21sym;
static aterm * lf_AUX_Pure_C1_21( aterm * arg1);
static asymbol * lf_AUX_Pure_C1_23sym;
static aterm * lf_AUX_Pure_C1_23( aterm * arg1);
static asymbol * lf_AUX_Pure_C1_22sym;
static aterm * lf_AUX_Pure_C1_22( aterm * arg1);
static asymbol * lf_AUX_Pure_C1_24sym;
static aterm * lf_AUX_Pure_C1_24( );
static asymbol * lf_AUX_Pure_C1_25sym;
static aterm * lf_AUX_Pure_C1_25( );
static asymbol * lf_AUX_Pure_C1_26sym;
static aterm * lf_AUX_Pure_C1_26( aterm * arg1);
static asymbol * lf_AUX_Pure_C1_27sym;
static aterm * lf_AUX_Pure_C1_27( aterm * arg1);
static asymbol * lf_AUX_Pure_C1_28sym;
static aterm * lf_AUX_Pure_C1_28( aterm * arg1);
static asymbol * lf_AUX_Pure_C1_29sym;
static aterm * lf_AUX_Pure_C1_29( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Pure_C1_30sym;
static aterm * lf_AUX_Pure_C1_30( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Pure_C1_32sym;
static aterm * lf_AUX_Pure_C1_32( aterm * arg1);
static asymbol * lf_AUX_Pure_C1_31sym;
static aterm * lf_AUX_Pure_C1_31( aterm * arg1);
static asymbol * lf_AUX_Pure_C1_33sym;
static aterm * lf_AUX_Pure_C1_33( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Pure_C1_34sym;
static aterm * lf_AUX_Pure_C1_34( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Pure_C1_35sym;
static aterm * lf_AUX_Pure_C1_35( aterm * arg1);
static asymbol * lf_AUX_Pure_C1_36sym;
static aterm * lf_AUX_Pure_C1_36( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Pure_C1_37sym;
static aterm * lf_AUX_Pure_C1_37( );
static asymbol * lf_AUX_Pure_C1_38sym;
static aterm * lf_AUX_Pure_C1_38( );
static asymbol * lf_AUX_Pure_C1_39sym;
static aterm * lf_AUX_Pure_C1_39( );
static asymbol * lf_AUX_Pure_C1_40sym;
static aterm * lf_AUX_Pure_C1_40( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Pure_C1_41sym;
static aterm * lf_AUX_Pure_C1_41( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Pure_C1_42sym;
static aterm * lf_AUX_Pure_C1_42( aterm * arg1);
static asymbol * lf_AUX_Pure_C1_43sym;
static aterm * lf_AUX_Pure_C1_43( aterm * arg1);
static asymbol * lf_AUX_Pure_C1_44sym;
static aterm * lf_AUX_Pure_C1_44( aterm * arg1);
static asymbol * lf_AUX_Pure_C1_45sym;
static aterm * lf_AUX_Pure_C1_45( aterm * arg1);
static asymbol * lf_AUX_Pure_C1_47sym;
static aterm * lf_AUX_Pure_C1_47( aterm * arg1);
static asymbol * lf_AUX_Pure_C1_46sym;
static aterm * lf_AUX_Pure_C1_46( aterm * arg1);
void register_AUX_Pure_C1( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Pure_C1_2sym= TmkSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"integer-constant\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Integer-constant\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Pure_C1_3sym= TmkSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_1sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf_AUX_Pure_C1_4sym= TmkSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"string\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"String\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_5sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_6sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_7sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_8sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\"),w(\"\"),l(\"else\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_9sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[l(\"while\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_10sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[l(\"return\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_11sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_12sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_13sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_14sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_15sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_16sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_17sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_18sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_19sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\"),w(\"\"),sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_20sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_21sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_23sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Type-specifier\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-specifiers\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_22sym= TmkSymbol( "listtype(sort(\"Type-specifier\"))" , SYM_STRING);
lf_AUX_Pure_C1_24sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[l(\"static\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_25sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[l(\"void\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_26sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_27sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"*\"),w(\"\"),sort(\"Declarator\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_28sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_29sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"Integer-constant\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_30sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_32sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_31sym= TmkSymbol( "listtype(sort(\"Parameter-declaration\"),ql(\",\"))" , SYM_STRING);
lf_AUX_Pure_C1_33sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_34sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_35sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_36sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Unary-operator\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_37sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"&\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Unary-operator\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_38sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Unary-operator\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_39sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"!\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Unary-operator\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_40sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_41sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_42sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_43sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Integer-constant\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_44sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"String\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_45sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_47sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Pure_C1_46sym= TmkSymbol( "listtype(sort(\"Expression\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf_AUX_Pure_C1_1 , lf_AUX_Pure_C1_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"integer-constant\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Integer-constant\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_2 , lf_AUX_Pure_C1_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_3 , lf_AUX_Pure_C1_3sym);
register_prod( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"string\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"String\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_4 , lf_AUX_Pure_C1_4sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_5 , lf_AUX_Pure_C1_5sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_6 , lf_AUX_Pure_C1_6sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_7 , lf_AUX_Pure_C1_7sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\"),w(\"\"),l(\"else\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_8 , lf_AUX_Pure_C1_8sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"while\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_9 , lf_AUX_Pure_C1_9sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"return\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_10 , lf_AUX_Pure_C1_10sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_11 , lf_AUX_Pure_C1_11sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_12 , lf_AUX_Pure_C1_12sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_13 , lf_AUX_Pure_C1_13sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_14 , lf_AUX_Pure_C1_14sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_15 , lf_AUX_Pure_C1_15sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_16 , lf_AUX_Pure_C1_16sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_17 , lf_AUX_Pure_C1_17sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_18 , lf_AUX_Pure_C1_18sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\"),w(\"\"),sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_19 , lf_AUX_Pure_C1_19sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_20 , lf_AUX_Pure_C1_20sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_21 , lf_AUX_Pure_C1_21sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Type-specifier\"))") , lf_AUX_Pure_C1_22 , lf_AUX_Pure_C1_22sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Type-specifier\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-specifiers\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_23 , lf_AUX_Pure_C1_23sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"static\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_24 , lf_AUX_Pure_C1_24sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"void\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_25 , lf_AUX_Pure_C1_25sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_26 , lf_AUX_Pure_C1_26sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"*\"),w(\"\"),sort(\"Declarator\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_27 , lf_AUX_Pure_C1_27sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_28 , lf_AUX_Pure_C1_28sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"Integer-constant\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_29 , lf_AUX_Pure_C1_29sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_30 , lf_AUX_Pure_C1_30sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Parameter-declaration\"),ql(\",\"))") , lf_AUX_Pure_C1_31 , lf_AUX_Pure_C1_31sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_32 , lf_AUX_Pure_C1_32sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_33 , lf_AUX_Pure_C1_33sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_34 , lf_AUX_Pure_C1_34sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_35 , lf_AUX_Pure_C1_35sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Unary-operator\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_36 , lf_AUX_Pure_C1_36sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"&\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Unary-operator\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_37 , lf_AUX_Pure_C1_37sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Unary-operator\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_38 , lf_AUX_Pure_C1_38sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"!\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Unary-operator\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_39 , lf_AUX_Pure_C1_39sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_40 , lf_AUX_Pure_C1_40sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_41 , lf_AUX_Pure_C1_41sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_42 , lf_AUX_Pure_C1_42sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Integer-constant\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_43 , lf_AUX_Pure_C1_43sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"String\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_44 , lf_AUX_Pure_C1_44sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_45 , lf_AUX_Pure_C1_45sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Expression\"),ql(\",\"))") , lf_AUX_Pure_C1_46 , lf_AUX_Pure_C1_46sym);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_47 , lf_AUX_Pure_C1_47sym);
}
void resolve_AUX_Pure_C1( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_Pure_C1_46( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C1_46);
return make_nf1( lf_AUX_Pure_C1_46sym , arg0);
}
aterm * lf_AUX_Pure_C1_47( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C1_47);
return make_nf1( lf_AUX_Pure_C1_47sym , arg0);
}
aterm * lf_AUX_Pure_C1_45( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C1_45);
return make_nf1( lf_AUX_Pure_C1_45sym , arg0);
}
aterm * lf_AUX_Pure_C1_44( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C1_44);
return make_nf1( lf_AUX_Pure_C1_44sym , arg0);
}
aterm * lf_AUX_Pure_C1_43( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C1_43);
return make_nf1( lf_AUX_Pure_C1_43sym , arg0);
}
aterm * lf_AUX_Pure_C1_42( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C1_42);
return make_nf1( lf_AUX_Pure_C1_42sym , arg0);
}
aterm * lf_AUX_Pure_C1_41( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Pure_C1_41);
return make_nf2( lf_AUX_Pure_C1_41sym , arg0 , arg1);
}
aterm * lf_AUX_Pure_C1_40( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Pure_C1_40);
return make_nf2( lf_AUX_Pure_C1_40sym , arg0 , arg1);
}
aterm * lf_AUX_Pure_C1_39( ) {
PROF( prof_lf_AUX_Pure_C1_39);
return make_nf0( lf_AUX_Pure_C1_39sym);
}
aterm * lf_AUX_Pure_C1_38( ) {
PROF( prof_lf_AUX_Pure_C1_38);
return make_nf0( lf_AUX_Pure_C1_38sym);
}
aterm * lf_AUX_Pure_C1_37( ) {
PROF( prof_lf_AUX_Pure_C1_37);
return make_nf0( lf_AUX_Pure_C1_37sym);
}
aterm * lf_AUX_Pure_C1_36( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Pure_C1_36);
return make_nf2( lf_AUX_Pure_C1_36sym , arg0 , arg1);
}
aterm * lf_AUX_Pure_C1_35( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C1_35);
return make_nf1( lf_AUX_Pure_C1_35sym , arg0);
}
aterm * lf_AUX_Pure_C1_34( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Pure_C1_34);
return make_nf2( lf_AUX_Pure_C1_34sym , arg0 , arg1);
}
aterm * lf_AUX_Pure_C1_33( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Pure_C1_33);
return make_nf2( lf_AUX_Pure_C1_33sym , arg0 , arg1);
}
aterm * lf_AUX_Pure_C1_31( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C1_31);
return make_nf1( lf_AUX_Pure_C1_31sym , arg0);
}
aterm * lf_AUX_Pure_C1_32( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C1_32);
return make_nf1( lf_AUX_Pure_C1_32sym , arg0);
}
aterm * lf_AUX_Pure_C1_30( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Pure_C1_30);
return make_nf2( lf_AUX_Pure_C1_30sym , arg0 , arg1);
}
aterm * lf_AUX_Pure_C1_29( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Pure_C1_29);
return make_nf2( lf_AUX_Pure_C1_29sym , arg0 , arg1);
}
aterm * lf_AUX_Pure_C1_28( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C1_28);
return make_nf1( lf_AUX_Pure_C1_28sym , arg0);
}
aterm * lf_AUX_Pure_C1_27( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C1_27);
return make_nf1( lf_AUX_Pure_C1_27sym , arg0);
}
aterm * lf_AUX_Pure_C1_26( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C1_26);
return make_nf1( lf_AUX_Pure_C1_26sym , arg0);
}
aterm * lf_AUX_Pure_C1_25( ) {
PROF( prof_lf_AUX_Pure_C1_25);
return make_nf0( lf_AUX_Pure_C1_25sym);
}
aterm * lf_AUX_Pure_C1_24( ) {
PROF( prof_lf_AUX_Pure_C1_24);
return make_nf0( lf_AUX_Pure_C1_24sym);
}
aterm * lf_AUX_Pure_C1_22( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C1_22);
return make_nf1( lf_AUX_Pure_C1_22sym , arg0);
}
aterm * lf_AUX_Pure_C1_23( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C1_23);
return make_nf1( lf_AUX_Pure_C1_23sym , arg0);
}
aterm * lf_AUX_Pure_C1_21( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C1_21);
return make_nf1( lf_AUX_Pure_C1_21sym , arg0);
}
aterm * lf_AUX_Pure_C1_20( ) {
PROF( prof_lf_AUX_Pure_C1_20);
return make_nf0( lf_AUX_Pure_C1_20sym);
}
aterm * lf_AUX_Pure_C1_19( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Pure_C1_19);
return make_nf2( lf_AUX_Pure_C1_19sym , arg0 , arg1);
}
aterm * lf_AUX_Pure_C1_18( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C1_18);
return make_nf1( lf_AUX_Pure_C1_18sym , arg0);
}
aterm * lf_AUX_Pure_C1_17( aterm * arg0 , aterm * arg1 , aterm * arg2) {
PROF( prof_lf_AUX_Pure_C1_17);
return make_nf3( lf_AUX_Pure_C1_17sym , arg0 , arg1 , arg2);
}
aterm * lf_AUX_Pure_C1_16( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Pure_C1_16);
return make_nf2( lf_AUX_Pure_C1_16sym , arg0 , arg1);
}
aterm * lf_AUX_Pure_C1_15( aterm * arg0 , aterm * arg1 , aterm * arg2) {
PROF( prof_lf_AUX_Pure_C1_15);
return make_nf3( lf_AUX_Pure_C1_15sym , arg0 , arg1 , arg2);
}
aterm * lf_AUX_Pure_C1_14( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C1_14);
return make_nf1( lf_AUX_Pure_C1_14sym , arg0);
}
aterm * lf_AUX_Pure_C1_13( ) {
PROF( prof_lf_AUX_Pure_C1_13);
return make_nf0( lf_AUX_Pure_C1_13sym);
}
aterm * lf_AUX_Pure_C1_12( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Pure_C1_12);
return make_nf2( lf_AUX_Pure_C1_12sym , arg0 , arg1);
}
aterm * lf_AUX_Pure_C1_11( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C1_11);
return make_nf1( lf_AUX_Pure_C1_11sym , arg0);
}
aterm * lf_AUX_Pure_C1_10( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C1_10);
return make_nf1( lf_AUX_Pure_C1_10sym , arg0);
}
aterm * lf_AUX_Pure_C1_9( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Pure_C1_9);
return make_nf2( lf_AUX_Pure_C1_9sym , arg0 , arg1);
}
aterm * lf_AUX_Pure_C1_8( aterm * arg0 , aterm * arg1 , aterm * arg2) {
PROF( prof_lf_AUX_Pure_C1_8);
return make_nf3( lf_AUX_Pure_C1_8sym , arg0 , arg1 , arg2);
}
aterm * lf_AUX_Pure_C1_7( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Pure_C1_7);
return make_nf2( lf_AUX_Pure_C1_7sym , arg0 , arg1);
}
aterm * lf_AUX_Pure_C1_6( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Pure_C1_6);
return make_nf2( lf_AUX_Pure_C1_6sym , arg0 , arg1);
}
aterm * lf_AUX_Pure_C1_5( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C1_5);
return make_nf1( lf_AUX_Pure_C1_5sym , arg0);
}
aterm * lf_AUX_Pure_C1_4( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C1_4);
return make_nf1( lf_AUX_Pure_C1_4sym , arg0);
}
aterm * lf_AUX_Pure_C1_1( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C1_1);
return make_nf1( lf_AUX_Pure_C1_1sym , arg0);
}
aterm * lf_AUX_Pure_C1_3( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C1_3);
return make_nf1( lf_AUX_Pure_C1_3sym , arg0);
}
aterm * lf_AUX_Pure_C1_2( aterm * arg0) {
PROF( prof_lf_AUX_Pure_C1_2);
return make_nf1( lf_AUX_Pure_C1_2sym , arg0);
}

