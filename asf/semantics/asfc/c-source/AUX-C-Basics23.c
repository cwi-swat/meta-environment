#include "support.h"
static asymbol * lf_AUX_C_Basics23_1sym;
static aterm * lf_AUX_C_Basics23_1( aterm * arg1);
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * ef4sym;
static funcptr ef4;
void register_AUX_C_Basics23( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_C_Basics23_1sym= TmkSymbol( "prod(id(\"C-Basics\"),w(\"\"),[l(\"translate-char\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"translate-char\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics23_1 , lf_AUX_C_Basics23_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_C_Basics23( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Integer-constant\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Integer-constant\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"integer-constant\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Integer-constant\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"integer-constant\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Integer-constant\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"space\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"space\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_C_Basics23_1( aterm * arg0) {
{
aterm * tmp[4];
PROF( prof_lf_AUX_C_Basics23_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
{
aterm * atmp000= arg_0( atmp00);
t_protect( atmp000);
if( not_empty_list( atmp000)) {
t_protect( atmp000);
tmp[ 0]= list_head( atmp000);
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 39))) {
t_protect( atmp000);
tmp[ 1]= list_tail( atmp000);
t_protect( tmp[ 1]);
if( is_single_element( tmp[ 1])) {
t_protect( tmp[ 1]);
tmp[ 2]= list_head( tmp[ 1]);
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 37))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 51)) , make_list( make_char( 55)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 38))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 51)) , make_list( make_char( 56)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 39))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 51)) , make_list( make_char( 57)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 40))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 52)) , make_list( make_char( 48)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 41))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 52)) , make_list( make_char( 49)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 42))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 52)) , make_list( make_char( 50)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 43))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 52)) , make_list( make_char( 51)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 44))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 52)) , make_list( make_char( 52)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 45))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 52)) , make_list( make_char( 53)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 46))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 52)) , make_list( make_char( 54)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 47))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 52)) , make_list( make_char( 55)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 48))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 52)) , make_list( make_char( 56)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 49))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 52)) , make_list( make_char( 57)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 50))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 53)) , make_list( make_char( 48)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 51))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 53)) , make_list( make_char( 49)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 52))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 53)) , make_list( make_char( 50)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 53))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 53)) , make_list( make_char( 51)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 54))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 53)) , make_list( make_char( 52)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 55))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 53)) , make_list( make_char( 53)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 56))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 53)) , make_list( make_char( 54)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 57))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 53)) , make_list( make_char( 55)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 58))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 53)) , make_list( make_char( 56)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 59))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 53)) , make_list( make_char( 57)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 60))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 54)) , make_list( make_char( 48)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 61))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 54)) , make_list( make_char( 49)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 62))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 54)) , make_list( make_char( 50)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 63))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 54)) , make_list( make_char( 51)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 64))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 54)) , make_list( make_char( 52)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 65))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 54)) , make_list( make_char( 53)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 66))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 54)) , make_list( make_char( 54)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 67))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 54)) , make_list( make_char( 55)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 68))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 54)) , make_list( make_char( 56)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 69))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 54)) , make_list( make_char( 57)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 70))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 55)) , make_list( make_char( 48)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 71))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 55)) , make_list( make_char( 49)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 72))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 55)) , make_list( make_char( 50)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 73))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 55)) , make_list( make_char( 51)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 74))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 55)) , make_list( make_char( 52)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 75))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 55)) , make_list( make_char( 53)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 76))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 55)) , make_list( make_char( 54)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 77))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 55)) , make_list( make_char( 55)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 78))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 55)) , make_list( make_char( 56)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 79))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 55)) , make_list( make_char( 57)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 80))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 56)) , make_list( make_char( 48)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 81))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 56)) , make_list( make_char( 49)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 82))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 56)) , make_list( make_char( 50)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 83))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 56)) , make_list( make_char( 51)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 84))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 56)) , make_list( make_char( 52)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 85))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 56)) , make_list( make_char( 53)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 86))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 56)) , make_list( make_char( 54)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 87))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 56)) , make_list( make_char( 55)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 88))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 56)) , make_list( make_char( 56)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 89))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 56)) , make_list( make_char( 57)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 90))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 57)) , make_list( make_char( 48)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 91))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 57)) , make_list( make_char( 49)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 93))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 57)) , make_list( make_char( 51)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 94))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 57)) , make_list( make_char( 52)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 95))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 57)) , make_list( make_char( 53)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 96))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 57)) , make_list( make_char( 54)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 97))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 57)) , make_list( make_char( 55)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 98))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 57)) , make_list( make_char( 56)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 99))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 57)) , make_list( make_char( 57)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 100))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 48)) , make_list( make_char( 48))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 101))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 48)) , make_list( make_char( 49))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 102))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 48)) , make_list( make_char( 50))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 103))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 48)) , make_list( make_char( 51))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 104))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 48)) , make_list( make_char( 52))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 105))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 48)) , make_list( make_char( 53))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 106))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 48)) , make_list( make_char( 54))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 107))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 48)) , make_list( make_char( 55))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 108))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 48)) , make_list( make_char( 56))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 109))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 48)) , make_list( make_char( 57))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 110))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 49)) , make_list( make_char( 48))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 111))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 49)) , make_list( make_char( 49))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 112))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 49)) , make_list( make_char( 50))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 113))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 49)) , make_list( make_char( 51))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 114))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 49)) , make_list( make_char( 52))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 115))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 49)) , make_list( make_char( 53))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 116))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 49)) , make_list( make_char( 54))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 117))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 49)) , make_list( make_char( 55))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 118))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 49)) , make_list( make_char( 56))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 119))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 49)) , make_list( make_char( 57))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 120))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 50)) , make_list( make_char( 48))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 121))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 50)) , make_list( make_char( 49))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 122))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 50)) , make_list( make_char( 50))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 123))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 50)) , make_list( make_char( 51))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 124))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 50)) , make_list( make_char( 52))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 125))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 50)) , make_list( make_char( 53))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 126))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , cons( make_list( make_char( 50)) , make_list( make_char( 54))))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 33))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 51)) , make_list( make_char( 51)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 34))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 51)) , make_list( make_char( 52)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 35))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 51)) , make_list( make_char( 53)))))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 36))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 51)) , make_list( make_char( 54)))))));
}
t_protect( tmp[ 1]);
tmp[ 3]= list_head( tmp[ 1]);
t_protect( tmp[ 3]);
if( term_equal( ( * ef1)( lf2( cons( make_list( make_char( 34)) , cons( make_list( tmp[ 3]) , make_list( make_char( 34)))))) , ( * ef5)( ))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 51)) , make_list( make_char( 50)))))));
}
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 2]);
}
t_unprotect( tmp[ 1]);
}
tmp[ 1]= make_char( 92);
t_protect( tmp[ 0]);
t_protect( tmp[ 1]);
if( term_equal( tmp[ 0] , tmp[ 1])) {
t_protect( atmp000);
tmp[ 2]= list_tail( atmp000);
t_protect( tmp[ 2]);
if( is_single_element( tmp[ 2])) {
t_protect( tmp[ 2]);
tmp[ 3]= list_head( tmp[ 2]);
t_protect( tmp[ 3]);
if( term_equal( tmp[ 3] , make_char( 110))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 49)) , make_list( make_char( 48)))))));
}
t_protect( tmp[ 3]);
if( term_equal( tmp[ 3] , make_char( 92))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 57)) , make_list( make_char( 50)))))));
}
t_protect( tmp[ 3]);
if( term_equal( tmp[ 3] , make_char( 116))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( make_list( make_char( 57))))));
}
t_unprotect( tmp[ 3]);
}
t_unprotect( tmp[ 2]);
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
}
}
}
}
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
{
aterm * atmp000= arg_0( atmp00);
t_protect( atmp000);
if( not_empty_list( atmp000)) {
t_protect( atmp000);
if( term_equal( list_head( atmp000) , make_char( 39))) {
t_protect( atmp000);
tmp[ 0]= list_tail( atmp000);
t_protect( tmp[ 0]);
if( is_single_element( tmp[ 0])) {
t_protect( tmp[ 0]);
tmp[ 1]= list_head( tmp[ 0]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
return ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 55)) , cons( make_list( make_char( 55)) , make_list( make_char( 55))))))));
}
t_unprotect( tmp[ 0]);
}
}
}
}
}
}
return make_nf1( lf_AUX_C_Basics23_1sym , arg0);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

