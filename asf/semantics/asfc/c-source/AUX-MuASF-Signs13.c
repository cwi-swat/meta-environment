#include "support.h"
static asymbol * lf_AUX_MuASF_Signs13_2sym;
static aterm * lf_AUX_MuASF_Signs13_2( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf_AUX_MuASF_Signs13_1sym;
static aterm * lf_AUX_MuASF_Signs13_1( aterm * arg1);
void register_AUX_MuASF_Signs13( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Signs13_2sym= TmkSymbol( "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"addto-sign\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"SignatureOpt\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SignatureOpt\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_MuASF_Signs13_1sym= TmkSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf_AUX_MuASF_Signs13_1 , lf_AUX_MuASF_Signs13_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"addto-sign\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"SignatureOpt\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SignatureOpt\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Signs13_2 , lf_AUX_MuASF_Signs13_2sym);
}
void resolve_AUX_MuASF_Signs13( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"SignatureOpt\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"SignatureOpt\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"signature\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SignatureOpt\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"signature\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SignatureOpt\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++_ss\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++_ss\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
}
aterm * lf_AUX_MuASF_Signs13_2( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[3];
PROF( prof_lf_AUX_MuASF_Signs13_2);
if( check_sym( arg0 , ef1sym)) {
if( check_sym( arg1 , lf_AUX_MuASF_Signs13_1sym)) {
{
aterm * atmp10= arg_0( arg1);
t_protect( atmp10);
if( not_empty_list( atmp10)) {
t_protect( atmp10);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef2)( ( * ef3)( lf_AUX_MuASF_Signs13_1( make_list( atmp10))));
}
else {
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef1)( );
}
}
}
}
if( check_sym( arg0 , ef2sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef3sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf_AUX_MuASF_Signs13_1sym)) {
{
aterm * atmp0000= arg_0( atmp000);
if( check_sym( arg1 , lf_AUX_MuASF_Signs13_1sym)) {
{
aterm * atmp10= arg_0( arg1);
t_protect( atmp0000);
if( ! not_empty_list( atmp0000)) {
t_protect( atmp10);
if( not_empty_list( atmp10)) {
t_protect( atmp10);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef2)( ( * ef3)( lf_AUX_MuASF_Signs13_1( make_list( atmp10))));
}
else {
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef1)( );
}
}
else {
t_protect( atmp10);
if( not_empty_list( atmp10)) {
t_protect( atmp0000);
t_protect( atmp10);
tmp[ 0]= ( * ef4)( ( * ef3)( lf_AUX_MuASF_Signs13_1( make_list( atmp0000))) , ( * ef3)( lf_AUX_MuASF_Signs13_1( make_list( atmp10))));
if( check_sym( tmp[ 0] , ef3sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , lf_AUX_MuASF_Signs13_1sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
t_protect( tmp[ 2]);
if( not_empty_list( tmp[ 2])) {
t_protect( tmp[ 2]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return ( * ef2)( ( * ef3)( lf_AUX_MuASF_Signs13_1( make_list( tmp[ 2]))));
}
}
}
t_unprotect( tmp[ 0]);
}
else {
t_protect( atmp0000);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef2)( ( * ef3)( lf_AUX_MuASF_Signs13_1( make_list( atmp0000))));
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
return make_nf2( lf_AUX_MuASF_Signs13_2sym , arg0 , arg1);
}
}
aterm * lf_AUX_MuASF_Signs13_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Signs13_1);
return make_nf1( lf_AUX_MuASF_Signs13_1sym , arg0);
}

