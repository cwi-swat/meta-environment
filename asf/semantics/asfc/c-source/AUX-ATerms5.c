#include "support.h"
static asymbol * lf_AUX_ATerms5_2sym;
static aterm * lf_AUX_ATerms5_2( aterm * arg1);
static asymbol * lf_AUX_ATerms5_3sym;
static aterm * lf_AUX_ATerms5_3( aterm * arg1);
static asymbol * lf_AUX_ATerms5_4sym;
static aterm * lf_AUX_ATerms5_4( aterm * arg1);
static asymbol * lf_AUX_ATerms5_5sym;
static aterm * lf_AUX_ATerms5_5( aterm * arg1);
static asymbol * lf_AUX_ATerms5_6sym;
static aterm * lf_AUX_ATerms5_6( aterm * arg1);
static asymbol * lf_AUX_ATerms5_7sym;
static aterm * lf_AUX_ATerms5_7( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_ATerms5_8sym;
static aterm * lf_AUX_ATerms5_8( aterm * arg1);
static asymbol * lf_AUX_ATerms5_9sym;
static aterm * lf_AUX_ATerms5_9( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_ATerms5_10sym;
static aterm * lf_AUX_ATerms5_10( aterm * arg1);
static asymbol * lf_AUX_ATerms5_11sym;
static aterm * lf_AUX_ATerms5_11( aterm * arg1);
static asymbol * lf_AUX_ATerms5_12sym;
static aterm * lf_AUX_ATerms5_12( );
static asymbol * lf_AUX_ATerms5_13sym;
static aterm * lf_AUX_ATerms5_13( aterm * arg1);
static asymbol * lf_AUX_ATerms5_14sym;
static aterm * lf_AUX_ATerms5_14( aterm * arg1);
static asymbol * lf_AUX_ATerms5_15sym;
static aterm * lf_AUX_ATerms5_15( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_ATerms5_16sym;
static aterm * lf_AUX_ATerms5_16( aterm * arg1);
static asymbol * lf_AUX_ATerms5_17sym;
static aterm * lf_AUX_ATerms5_17( aterm * arg1);
static asymbol * lf_AUX_ATerms5_18sym;
static aterm * lf_AUX_ATerms5_18( aterm * arg1);
static asymbol * lf_AUX_ATerms5_1sym;
static aterm * lf_AUX_ATerms5_1( aterm * arg1);
void register_AUX_ATerms5( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_ATerms5_2sym= TmkSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_ATerms5_3sym= TmkSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"aname\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AName\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_ATerms5_4sym= TmkSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_ATerms5_5sym= TmkSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_ATerms5_6sym= TmkSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AName\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_ATerms5_7sym= TmkSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_ATerms5_8sym= TmkSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_ATerms5_9sym= TmkSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_ATerms5_10sym= TmkSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AVar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_ATerms5_11sym= TmkSymbol( "prod(id(\"ATerms\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_ATerms5_12sym= TmkSymbol( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_ATerms5_13sym= TmkSymbol( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_ATerms5_14sym= TmkSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_ATerms5_15sym= TmkSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_ATerms5_16sym= TmkSymbol( "prod(id(\"ATerms\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , SYM_STRING);
lf_AUX_ATerms5_17sym= TmkSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_ATerms5_18sym= TmkSymbol( "prod(id(\"ATerms\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , SYM_STRING);
lf_AUX_ATerms5_1sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf_AUX_ATerms5_1 , lf_AUX_ATerms5_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_2 , lf_AUX_ATerms5_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aname\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AName\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_3 , lf_AUX_ATerms5_3sym);
register_prod( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_4 , lf_AUX_ATerms5_4sym);
register_prod( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_5 , lf_AUX_ATerms5_5sym);
register_prod( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AName\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_6 , lf_AUX_ATerms5_6sym);
register_prod( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_7 , lf_AUX_ATerms5_7sym);
register_prod( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_8 , lf_AUX_ATerms5_8sym);
register_prod( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_9 , lf_AUX_ATerms5_9sym);
register_prod( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AVar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_10 , lf_AUX_ATerms5_10sym);
register_prod( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_11 , lf_AUX_ATerms5_11sym);
register_prod( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_12 , lf_AUX_ATerms5_12sym);
register_prod( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_13 , lf_AUX_ATerms5_13sym);
register_prod( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_14 , lf_AUX_ATerms5_14sym);
register_prod( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_15 , lf_AUX_ATerms5_15sym);
register_prod( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))") , lf_AUX_ATerms5_16 , lf_AUX_ATerms5_16sym);
register_prod( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_17 , lf_AUX_ATerms5_17sym);
register_prod( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))") , lf_AUX_ATerms5_18 , lf_AUX_ATerms5_18sym);
}
void resolve_AUX_ATerms5( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_ATerms5_2( aterm * arg0) {
{
aterm * tmp[1];
PROF( prof_lf_AUX_ATerms5_2);
if( check_sym( arg0 , lf_AUX_ATerms5_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( m_not_empty_list( atmp00)) {
t_protect( atmp00);
if( term_equal( list_head( atmp00) , make_char( 48))) {
tmp[ 0]= m_list_tail( atmp00);
if( m_not_empty_list( tmp[ 0])) {
t_unprotect( arg0);
return lf_AUX_ATerms5_2( lf_AUX_ATerms5_1( make_list( tmp[ 0])));
}
t_unprotect( tmp[ 0]);
}
}
}
}
return make_nf1( lf_AUX_ATerms5_2sym , arg0);
}
}
aterm * lf_AUX_ATerms5_1( aterm * arg0) {
PROF( prof_lf_AUX_ATerms5_1);
return make_nf1( lf_AUX_ATerms5_1sym , arg0);
}
aterm * lf_AUX_ATerms5_18( aterm * arg0) {
PROF( prof_lf_AUX_ATerms5_18);
return make_nf1( lf_AUX_ATerms5_18sym , arg0);
}
aterm * lf_AUX_ATerms5_17( aterm * arg0) {
PROF( prof_lf_AUX_ATerms5_17);
return make_nf1( lf_AUX_ATerms5_17sym , arg0);
}
aterm * lf_AUX_ATerms5_16( aterm * arg0) {
PROF( prof_lf_AUX_ATerms5_16);
return make_nf1( lf_AUX_ATerms5_16sym , arg0);
}
aterm * lf_AUX_ATerms5_15( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_ATerms5_15);
return make_nf2( lf_AUX_ATerms5_15sym , arg0 , arg1);
}
aterm * lf_AUX_ATerms5_14( aterm * arg0) {
PROF( prof_lf_AUX_ATerms5_14);
return make_nf1( lf_AUX_ATerms5_14sym , arg0);
}
aterm * lf_AUX_ATerms5_13( aterm * arg0) {
PROF( prof_lf_AUX_ATerms5_13);
return make_nf1( lf_AUX_ATerms5_13sym , arg0);
}
aterm * lf_AUX_ATerms5_12( ) {
PROF( prof_lf_AUX_ATerms5_12);
return make_nf0( lf_AUX_ATerms5_12sym);
}
aterm * lf_AUX_ATerms5_11( aterm * arg0) {
PROF( prof_lf_AUX_ATerms5_11);
return make_nf1( lf_AUX_ATerms5_11sym , arg0);
}
aterm * lf_AUX_ATerms5_10( aterm * arg0) {
PROF( prof_lf_AUX_ATerms5_10);
return make_nf1( lf_AUX_ATerms5_10sym , arg0);
}
aterm * lf_AUX_ATerms5_9( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_ATerms5_9);
return make_nf2( lf_AUX_ATerms5_9sym , arg0 , arg1);
}
aterm * lf_AUX_ATerms5_8( aterm * arg0) {
PROF( prof_lf_AUX_ATerms5_8);
return make_nf1( lf_AUX_ATerms5_8sym , arg0);
}
aterm * lf_AUX_ATerms5_7( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_ATerms5_7);
return make_nf2( lf_AUX_ATerms5_7sym , arg0 , arg1);
}
aterm * lf_AUX_ATerms5_6( aterm * arg0) {
PROF( prof_lf_AUX_ATerms5_6);
return make_nf1( lf_AUX_ATerms5_6sym , arg0);
}
aterm * lf_AUX_ATerms5_5( aterm * arg0) {
PROF( prof_lf_AUX_ATerms5_5);
return make_nf1( lf_AUX_ATerms5_5sym , arg0);
}
aterm * lf_AUX_ATerms5_4( aterm * arg0) {
PROF( prof_lf_AUX_ATerms5_4);
return make_nf1( lf_AUX_ATerms5_4sym , arg0);
}
aterm * lf_AUX_ATerms5_3( aterm * arg0) {
PROF( prof_lf_AUX_ATerms5_3);
return make_nf1( lf_AUX_ATerms5_3sym , arg0);
}

