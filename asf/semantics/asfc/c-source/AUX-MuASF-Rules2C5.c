#include "support.h"
static asymbol * lf_AUX_MuASF_Rules2C5_4sym;
static aterm * lf_AUX_MuASF_Rules2C5_4( aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4);
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * lf_AUX_MuASF_Rules2C5_2sym;
static aterm * lf_AUX_MuASF_Rules2C5_2( aterm * arg1);
static asymbol * lf_AUX_MuASF_Rules2C5_3sym;
static aterm * lf_AUX_MuASF_Rules2C5_3( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf_AUX_MuASF_Rules2C5_1sym;
static aterm * lf_AUX_MuASF_Rules2C5_1( aterm * arg1);
void register_AUX_MuASF_Rules2C5( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Rules2C5_4sym= TmkSymbol( "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"asfrules2cfuncs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FT-tuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_MuASF_Rules2C5_2sym= TmkSymbol( "listtype(sort(\"Rule\"),ql(\";\"))" , SYM_STRING);
lf_AUX_MuASF_Rules2C5_3sym= TmkSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , SYM_STRING);
lf_AUX_MuASF_Rules2C5_1sym= TmkSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf_AUX_MuASF_Rules2C5_1 , lf_AUX_MuASF_Rules2C5_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Rule\"),ql(\";\"))") , lf_AUX_MuASF_Rules2C5_2 , lf_AUX_MuASF_Rules2C5_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"NamePair\"),ql(\",\"))") , lf_AUX_MuASF_Rules2C5_3 , lf_AUX_MuASF_Rules2C5_3sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"asfrules2cfuncs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FT-tuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Rules2C5_4 , lf_AUX_MuASF_Rules2C5_4sym);
}
void resolve_AUX_MuASF_Rules2C5( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FT-tuple\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FT-tuple\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"RenameVars\"),w(\"\"),[l(\"rename-in-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"RenameVars\"),w(\"\"),[l(\"rename-in-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"asfrules2cfunc\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"asfrules2cfunc\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Declaration-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Declaration-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Declaration-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Declaration-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"asfrules2cfuncs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FT-tuple\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"asfrules2cfuncs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FT-tuple\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Rules2C5_4( aterm * arg0 , aterm * arg1 , aterm * arg2 , aterm * arg3) {
{
aterm * tmp[8];
PROF( prof_lf_AUX_MuASF_Rules2C5_4);
if( check_sym( arg0 , lf_AUX_MuASF_Rules2C5_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg1 , lf_AUX_MuASF_Rules2C5_2sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( arg2 , lf_AUX_MuASF_Rules2C5_2sym)) {
{
aterm * atmp20= arg_0( arg2);
if( check_sym( arg3 , lf_AUX_MuASF_Rules2C5_3sym)) {
{
aterm * atmp30= arg_0( arg3);
t_protect( atmp10);
if( not_empty_list( atmp10)) {
t_protect( atmp20);
if( not_empty_list( atmp20)) {
t_protect( atmp10);
tmp[ 0]= ( * ef4)( lf_AUX_MuASF_Rules2C5_2( make_list( atmp10)));
if( check_sym( tmp[ 0] , ef5sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , lf_AUX_MuASF_Rules2C5_2sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
t_protect( tmp[ 2]);
if( not_empty_list( tmp[ 2])) {
t_protect( tmp[ 2]);
t_protect( atmp30);
tmp[ 3]= ( * ef6)( lf_AUX_MuASF_Rules2C5_2( make_list( tmp[ 2])) , lf_AUX_MuASF_Rules2C5_3( make_list( atmp30)));
t_protect( atmp00);
t_protect( atmp20);
t_protect( atmp30);
tmp[ 4]= ( * ef8)( lf_AUX_MuASF_Rules2C5_1( make_list( atmp00)) , lf_AUX_MuASF_Rules2C5_2( make_list( atmp20)) , lf_AUX_MuASF_Rules2C5_3( make_list( atmp30)));
if( check_sym( tmp[ 4] , ef1sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
tmp[ 6]= arg_1( tmp[ 4]);
if( check_sym( tmp[ 5] , lf_AUX_MuASF_Rules2C5_1sym)) {
tmp[ 7]= arg_0( tmp[ 5]);
t_protect( tmp[ 7]);
t_protect( tmp[ 6]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 4]);
return ( * ef1)( lf_AUX_MuASF_Rules2C5_1( make_list( tmp[ 7])) , ( * ef7)( tmp[ 6] , ( * ef2)( ( * ef3)( tmp[ 3]))));
}
}
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 3]);
}
}
}
t_unprotect( tmp[ 0]);
}
else {
t_protect( atmp10);
tmp[ 0]= ( * ef4)( lf_AUX_MuASF_Rules2C5_2( make_list( atmp10)));
if( check_sym( tmp[ 0] , ef5sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , lf_AUX_MuASF_Rules2C5_2sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
t_protect( tmp[ 2]);
if( not_empty_list( tmp[ 2])) {
t_protect( tmp[ 2]);
t_protect( atmp30);
tmp[ 3]= ( * ef6)( lf_AUX_MuASF_Rules2C5_2( make_list( tmp[ 2])) , lf_AUX_MuASF_Rules2C5_3( make_list( atmp30)));
t_protect( atmp00);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf_AUX_MuASF_Rules2C5_1( make_list( atmp00)) , ( * ef2)( ( * ef3)( tmp[ 3])));
}
}
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
return make_nf4( lf_AUX_MuASF_Rules2C5_4sym , arg0 , arg1 , arg2 , arg3);
}
}
aterm * lf_AUX_MuASF_Rules2C5_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Rules2C5_1);
return make_nf1( lf_AUX_MuASF_Rules2C5_1sym , arg0);
}
aterm * lf_AUX_MuASF_Rules2C5_3( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Rules2C5_3);
return make_nf1( lf_AUX_MuASF_Rules2C5_3sym , arg0);
}
aterm * lf_AUX_MuASF_Rules2C5_2( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Rules2C5_2);
return make_nf1( lf_AUX_MuASF_Rules2C5_2sym , arg0);
}

