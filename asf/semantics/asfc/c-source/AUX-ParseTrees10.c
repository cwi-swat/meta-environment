#include "support.h"
static asymbol * lf_AUX_ParseTrees10_1sym;
static aterm * lf_AUX_ParseTrees10_1( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * ef16sym;
static funcptr ef16;
static asymbol * ef17sym;
static funcptr ef17;
static asymbol * ef18sym;
static funcptr ef18;
static asymbol * ef6sym;
static funcptr ef6;
void register_AUX_ParseTrees10( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_ParseTrees10_1sym= TmkSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees10_1 , lf_AUX_ParseTrees10_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_ParseTrees10( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"conditions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"conditions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-equ\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-equ\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"::\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"::\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"named-elem\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"named-elem\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef17= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef18= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"init\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"init\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_ParseTrees10_1( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[3];
PROF( prof_lf_AUX_ParseTrees10_1);
if( check_sym( arg0 , ef6sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef7sym)) {
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef8sym)) {
{
aterm * atmp010= arg_0( atmp01);
{
aterm * atmp011= arg_1( atmp01);
if( check_sym( atmp011 , ef9sym)) {
{
aterm * atmp0110= arg_0( atmp011);
if( check_sym( arg1 , ef10sym)) {
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef6)( ( * ef11)( ) , ( * ef9)( ( * ef12)( ( * ef13)( ( * ef14)( lf2( cons( make_list( make_char( 34)) , make_list( make_char( 34)))))))));
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
if( check_sym( arg0 , ef15sym)) {
{
aterm * atmp00= arg_0( arg0);
{
aterm * atmp01= arg_1( arg0);
t_protect( atmp01);
t_unprotect( arg0);
return lf_AUX_ParseTrees10_1( atmp01 , arg1);
}
}
}
if( check_sym( arg1 , ef1sym)) {
t_protect( arg0);
if( term_equal( ( * ef4)( arg0) , ( * ef5)( ))) {
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef2)( ( * ef3)( ));
}
}
if( check_sym( arg0 , ef6sym)) {
{
aterm * atmp00= arg_0( arg0);
{
aterm * atmp01= arg_1( arg0);
t_protect( atmp00);
tmp[ 0]= ( * ef18)( atmp00);
if( check_sym( tmp[ 0] , ef6sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
if( m_term_equal( atmp00 , tmp[ 1])) {
t_protect( tmp[ 2]);
t_protect( atmp01);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef16)( arg1 , ( * ef17)( tmp[ 2]) , ( * ef17)( atmp01));
}
}
t_unprotect( tmp[ 0]);
}
}
}
return make_nf2( lf_AUX_ParseTrees10_1sym , arg0 , arg1);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

