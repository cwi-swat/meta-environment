#include "support.h"
static asymbol * lf_AUX_Grammars5_1sym;
static aterm * lf_AUX_Grammars5_1( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * lookup__1__lf_AUX_Grammars5_1sym;
static aterm * lookup__1__lf_AUX_Grammars5_1( aterm * arg1 , aterm * arg2);
static asymbol * new__1__lookup__1__lf_AUX_Grammars5_1sym;
static aterm * new__1__lookup__1__lf_AUX_Grammars5_1( aterm * arg1 , aterm * arg2);
void register_AUX_Grammars5( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Grammars5_1sym= TmkSymbol( "prod(id(\"Grammars\"),w(\"\"),[l(\"norm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbols\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"Symbol\"))" , SYM_STRING);
lookup__1__lf_AUX_Grammars5_1sym= TmkSymbol( "lookup__1__lf_AUX_Grammars5_1" , SYM_STRING);
new__1__lookup__1__lf_AUX_Grammars5_1sym= TmkSymbol( "new__1__lookup__1__lf_AUX_Grammars5_1" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[l(\"norm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbols\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)") , lf_AUX_Grammars5_1 , lf_AUX_Grammars5_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Symbol\"))") , lf2 , lf2sym);
}
void resolve_AUX_Grammars5( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Symbols\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Symbols\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[ql(\"Layout\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[ql(\"Layout\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
}
aterm * new__1__lookup__1__lf_AUX_Grammars5_1( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[2];
PROF( prof_new__1__lookup__1__lf_AUX_Grammars5_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( arg1 , ef1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , lf2sym)) {
{
aterm * atmp100= arg_0( atmp10);
t_protect( atmp000);
if( not_empty_list( atmp000)) {
t_protect( atmp100);
if( not_empty_list( atmp100)) {
t_protect( atmp100);
tmp[ 0]= list_head( atmp100);
t_protect( atmp100);
tmp[ 1]= list_tail( atmp100);
t_protect( tmp[ 1]);
if( not_empty_list( tmp[ 1])) {
t_protect( atmp000);
t_unprotect( arg0);
t_unprotect( arg1);
return lookup__1__lf_AUX_Grammars5_1( ( * ef1)( lf2( cons( make_list( atmp000) , make_list( tmp[ 0])))) , ( * ef1)( lf2( make_list( tmp[ 1]))));
}
t_unprotect( tmp[ 1]);
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
return make_nf2( new__1__lookup__1__lf_AUX_Grammars5_1sym , arg0 , arg1);
}
}
aterm * lookup__1__lf_AUX_Grammars5_1( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[2];
PROF( prof_lookup__1__lf_AUX_Grammars5_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( arg1 , ef1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , lf2sym)) {
{
aterm * atmp100= arg_0( atmp10);
t_protect( atmp000);
if( not_empty_list( atmp000)) {
t_protect( atmp100);
if( not_empty_list( atmp100)) {
return ok( ( * ef2)( lf_AUX_Grammars5_1( arg0) , ( * ef2)( ( * ef1)( lf2( make_list( ( * ef3)( ( * ef4)( ))))) , lf_AUX_Grammars5_1( arg1))));
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
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( arg1 , ef1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , lf2sym)) {
{
aterm * atmp100= arg_0( atmp10);
t_protect( atmp000);
if( not_empty_list( atmp000)) {
t_protect( atmp100);
if( not_empty_list( atmp100)) {
t_protect( atmp100);
tmp[ 0]= list_head( atmp100);
t_protect( atmp100);
tmp[ 1]= list_tail( atmp100);
t_protect( tmp[ 1]);
if( not_empty_list( tmp[ 1])) {
t_unprotect( arg1);
return new__1__lookup__1__lf_AUX_Grammars5_1( arg0 , ( * ef1)( lf2( cons( make_list( tmp[ 0]) , make_list( tmp[ 1])))));
}
t_unprotect( tmp[ 1]);
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
return make_nf2( lookup__1__lf_AUX_Grammars5_1sym , arg0 , arg1);
}
}
aterm * lf_AUX_Grammars5_1( aterm * arg0) {
{
aterm * tmp[2];
PROF( prof_lf_AUX_Grammars5_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
{
aterm * atmp000= arg_0( atmp00);
t_protect( arg0);
tmp[ 0]= lookup__1__lf_AUX_Grammars5_1( ( * ef1)( lf2( make_list( null( )))) , arg0);
if( check_sym( tmp[ 0] , oksym)) {
tmp[ 1]= arg_0( tmp[ 0]);
t_protect( tmp[ 1]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return tmp[ 1];
}
t_unprotect( tmp[ 0]);
t_protect( atmp000);
if( ! not_empty_list( atmp000)) {
t_unprotect( arg0);
return ( * ef1)( lf2( make_list( null( ))));
}
t_protect( atmp000);
if( is_single_element( atmp000)) {
t_protect( atmp000);
tmp[ 0]= list_head( atmp000);
t_unprotect( arg0);
return ( * ef1)( lf2( make_list( tmp[ 0])));
}
}
}
}
}
return make_nf1( lf_AUX_Grammars5_1sym , arg0);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

