#include "support.h"
static asymbol * lf_AUX_AsFix2muASFnames12_1sym;
static aterm * lf_AUX_AsFix2muASFnames12_1( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
void register_AUX_AsFix2muASFnames12( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_AsFix2muASFnames12_1sym= TmkSymbol( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"svar2muvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"svar2muvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)") , lf_AUX_AsFix2muASFnames12_1 , lf_AUX_AsFix2muASFnames12_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_AsFix2muASFnames12( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"varid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"varid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_AsFix2muASFnames12_1( aterm * arg0) {
{
aterm * tmp[2];
PROF( prof_lf_AUX_AsFix2muASFnames12_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef2sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , ef3sym)) {
{
aterm * atmp0000= arg_0( atmp000);
if( check_sym( atmp0000 , lf2sym)) {
{
aterm * atmp00000= arg_0( atmp0000);
if( m_not_empty_list( atmp00000)) {
t_protect( atmp00000);
if( term_equal( list_head( atmp00000) , make_char( 34))) {
tmp[ 0]= m_list_tail( atmp00000);
if( m_not_empty_list( tmp[ 0])) {
t_protect( tmp[ 0]);
tmp[ 1]= list_prefix( tmp[ 0]);
t_protect( tmp[ 0]);
if( term_equal( list_last( tmp[ 0]) , make_char( 34))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef4)( lf2( make_list( tmp[ 1])));
}
t_unprotect( tmp[ 1]);
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
return make_nf1( lf_AUX_AsFix2muASFnames12_1sym , arg0);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

