#include "support.h"
static asymbol * lf_AUX_MuASF_Basics17_1sym;
static aterm * lf_AUX_MuASF_Basics17_1( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * new__1__lf_AUX_MuASF_Basics17_1sym;
static aterm * new__1__lf_AUX_MuASF_Basics17_1( aterm * arg1 , aterm * arg2 , aterm * arg3);
void register_AUX_MuASF_Basics17( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Basics17_1sym= TmkSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"prefix-id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
new__1__lf_AUX_MuASF_Basics17_1sym= TmkSymbol( "new__1__lf_AUX_MuASF_Basics17_1" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"prefix-id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics17_1 , lf_AUX_MuASF_Basics17_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_MuASF_Basics17( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
}
aterm * new__1__lf_AUX_MuASF_Basics17_1( aterm * arg0 , aterm * arg1 , aterm * arg2) {
{
aterm * tmp[2];
PROF( prof_new__1__lf_AUX_MuASF_Basics17_1);
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
if( check_sym( arg2 , ef2sym)) {
{
aterm * atmp20= arg_0( arg2);
if( check_sym( atmp20 , lf2sym)) {
{
aterm * atmp200= arg_0( atmp20);
t_protect( atmp000);
if( not_empty_list( atmp000)) {
t_protect( atmp000);
if( term_equal( list_head( atmp000) , make_char( 34))) {
t_protect( atmp000);
tmp[ 0]= list_tail( atmp000);
t_protect( tmp[ 0]);
if( not_empty_list( tmp[ 0])) {
t_protect( tmp[ 0]);
tmp[ 1]= list_prefix( tmp[ 0]);
t_protect( tmp[ 0]);
if( term_equal( list_last( tmp[ 0]) , make_char( 34))) {
t_protect( atmp200);
t_protect( atmp100);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( cons( make_list( tmp[ 1]) , cons( make_list( atmp200) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 95)) , make_list( atmp100)))))));
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
}
}
}
}
return make_nf3( new__1__lf_AUX_MuASF_Basics17_1sym , arg0 , arg1 , arg2);
}
}
aterm * lf_AUX_MuASF_Basics17_1( aterm * arg0 , aterm * arg1 , aterm * arg2) {
{
aterm * tmp[4];
PROF( prof_lf_AUX_MuASF_Basics17_1);
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
if( check_sym( arg2 , ef2sym)) {
{
aterm * atmp20= arg_0( arg2);
if( check_sym( atmp20 , lf2sym)) {
{
aterm * atmp200= arg_0( atmp20);
t_protect( atmp000);
if( not_empty_list( atmp000)) {
t_protect( atmp000);
if( term_equal( list_head( atmp000) , make_char( 34))) {
t_protect( atmp000);
tmp[ 0]= list_tail( atmp000);
t_protect( tmp[ 0]);
if( not_empty_list( tmp[ 0])) {
t_protect( tmp[ 0]);
tmp[ 1]= list_prefix( tmp[ 0]);
t_protect( tmp[ 0]);
if( term_equal( list_last( tmp[ 0]) , make_char( 34))) {
t_protect( atmp100);
if( not_empty_list( atmp100)) {
t_protect( atmp100);
if( term_equal( list_head( atmp100) , make_char( 34))) {
t_protect( atmp100);
tmp[ 2]= list_tail( atmp100);
t_protect( tmp[ 2]);
if( not_empty_list( tmp[ 2])) {
t_protect( tmp[ 2]);
tmp[ 3]= list_prefix( tmp[ 2]);
t_protect( tmp[ 2]);
if( term_equal( list_last( tmp[ 2]) , make_char( 34))) {
t_protect( atmp200);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 2]);
return ( * ef1)( lf2( cons( make_list( make_char( 34)) , cons( make_list( tmp[ 1]) , cons( make_list( atmp200) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 95)) , cons( make_list( tmp[ 3]) , make_list( make_char( 34))))))))));
}
t_unprotect( tmp[ 3]);
}
t_unprotect( tmp[ 2]);
}
}
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
if( check_sym( arg2 , ef2sym)) {
{
aterm * atmp20= arg_0( arg2);
if( check_sym( atmp20 , lf2sym)) {
{
aterm * atmp200= arg_0( atmp20);
t_protect( atmp000);
if( not_empty_list( atmp000)) {
t_protect( atmp000);
if( term_equal( list_head( atmp000) , make_char( 34))) {
t_protect( atmp000);
tmp[ 0]= list_tail( atmp000);
t_protect( tmp[ 0]);
if( not_empty_list( tmp[ 0])) {
t_protect( tmp[ 0]);
tmp[ 1]= list_prefix( tmp[ 0]);
t_protect( tmp[ 0]);
if( term_equal( list_last( tmp[ 0]) , make_char( 34))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return new__1__lf_AUX_MuASF_Basics17_1( ( * ef1)( lf2( cons( make_list( make_char( 34)) , cons( make_list( tmp[ 1]) , make_list( make_char( 34)))))) , arg1 , arg2);
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
}
}
}
}
return make_nf3( lf_AUX_MuASF_Basics17_1sym , arg0 , arg1 , arg2);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

