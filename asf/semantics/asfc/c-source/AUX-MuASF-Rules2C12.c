#include "support.h"
static asymbol * lf_AUX_MuASF_Rules2C12_3sym;
static aterm * lf_AUX_MuASF_Rules2C12_3( aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4);
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef24sym;
static funcptr ef24;
static asymbol * lf6sym;
static aterm * lf6( aterm * arg1);
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef25sym;
static funcptr ef25;
static asymbol * ef26sym;
static funcptr ef26;
static asymbol * ef27sym;
static funcptr ef27;
static asymbol * ef28sym;
static funcptr ef28;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * lf7sym;
static aterm * lf7( aterm * arg1);
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * ef16sym;
static funcptr ef16;
static asymbol * ef17sym;
static funcptr ef17;
static asymbol * ef18sym;
static funcptr ef18;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef19sym;
static funcptr ef19;
static asymbol * ef20sym;
static funcptr ef20;
static asymbol * ef21sym;
static funcptr ef21;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef22sym;
static funcptr ef22;
static asymbol * ef23sym;
static funcptr ef23;
static asymbol * ef29sym;
static funcptr ef29;
static asymbol * lf_AUX_MuASF_Rules2C12_1sym;
static aterm * lf_AUX_MuASF_Rules2C12_1( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * lf5sym;
static aterm * lf5( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf_AUX_MuASF_Rules2C12_2sym;
static aterm * lf_AUX_MuASF_Rules2C12_2( aterm * arg1);
static asymbol * new__1__lf_AUX_MuASF_Rules2C12_3sym;
static aterm * new__1__lf_AUX_MuASF_Rules2C12_3( aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4);
void register_AUX_MuASF_Rules2C12( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Rules2C12_3sym= TmkSymbol( "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"first-cond2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf6sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf7sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
lf_AUX_MuASF_Rules2C12_1sym= TmkSymbol( "listtype(sort(\"C-Rule\"),ql(\";\"))" , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"FV-Path\"),ql(\",\"))" , SYM_STRING);
lf5sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
lf_AUX_MuASF_Rules2C12_2sym= TmkSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , SYM_STRING);
new__1__lf_AUX_MuASF_Rules2C12_3sym= TmkSymbol( "new__1__lf_AUX_MuASF_Rules2C12_3" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"C-Rule\"),ql(\";\"))") , lf_AUX_MuASF_Rules2C12_1 , lf_AUX_MuASF_Rules2C12_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"NamePair\"),ql(\",\"))") , lf_AUX_MuASF_Rules2C12_2 , lf_AUX_MuASF_Rules2C12_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"first-cond2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Rules2C12_3 , lf_AUX_MuASF_Rules2C12_3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FV-Path\"),ql(\",\"))") , lf4 , lf4sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf5 , lf5sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf6 , lf6sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf7 , lf7sym);
}
void resolve_AUX_MuASF_Rules2C12( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"find-common-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"find-common-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-c-temp\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-c-temp\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"terms2cargs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"terms2cargs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-same-lhs-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-same-lhs-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-same-rhs-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-same-rhs-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"remove-first-cond\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"remove-first-cond\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)"));
ef17= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)"));
ef18= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"conds2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"conds2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef19= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-call-id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef19sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-call-id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef20= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef20sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef21= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-if-then-else\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef21sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-if-then-else\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef22= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef22sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef23= lookup_func( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"gtr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef23sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"gtr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef24= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef24sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef25= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"is-boolean-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef25sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"is-boolean-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef26= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef26sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef27= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funargs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef27sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funargs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef28= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef28sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef29= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"first-cond2cstats2\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef29sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"first-cond2cstats2\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
}
aterm * new__1__lf_AUX_MuASF_Rules2C12_3( aterm * arg0 , aterm * arg1 , aterm * arg2 , aterm * arg3) {
{
aterm * tmp[13];
PROF( prof_new__1__lf_AUX_MuASF_Rules2C12_3);
if( check_sym( arg0 , lf_AUX_MuASF_Rules2C12_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg2 , lf_AUX_MuASF_Rules2C12_2sym)) {
{
aterm * atmp20= arg_0( arg2);
t_protect( atmp00);
if( not_empty_list( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
if( check_sym( tmp[ 0] , ef1sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
tmp[ 3]= arg_2( tmp[ 0]);
tmp[ 4]= arg_3( tmp[ 0]);
tmp[ 5]= arg_4( tmp[ 0]);
if( check_sym( tmp[ 1] , lf4sym)) {
tmp[ 6]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , lf5sym)) {
tmp[ 7]= arg_0( tmp[ 2]);
t_protect( tmp[ 7]);
if( not_empty_list( tmp[ 7])) {
t_protect( tmp[ 7]);
tmp[ 8]= list_head( tmp[ 7]);
if( check_sym( tmp[ 8] , ef2sym)) {
tmp[ 9]= arg_0( tmp[ 8]);
tmp[ 10]= arg_1( tmp[ 8]);
t_protect( tmp[ 7]);
tmp[ 11]= list_tail( tmp[ 7]);
t_protect( atmp00);
tmp[ 12]= list_tail( atmp00);
t_protect( tmp[ 6]);
t_protect( tmp[ 9]);
t_protect( tmp[ 10]);
t_protect( tmp[ 3]);
t_protect( tmp[ 4]);
t_protect( tmp[ 5]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 8]);
return ( * ef29)( lf_AUX_MuASF_Rules2C12_1( cons( make_list( ( * ef1)( lf4( make_list( tmp[ 6])) , lf5( cons( make_list( ( * ef2)( tmp[ 9] , tmp[ 10])) , make_list( tmp[ 11]))) , tmp[ 3] , tmp[ 4] , tmp[ 5])) , make_list( tmp[ 12]))) , arg1 , arg2 , arg3);
}
t_unprotect( tmp[ 8]);
}
}
}
}
t_unprotect( tmp[ 0]);
}
}
}
}
}
return make_nf4( new__1__lf_AUX_MuASF_Rules2C12_3sym , arg0 , arg1 , arg2 , arg3);
}
}
aterm * lf_AUX_MuASF_Rules2C12_3( aterm * arg0 , aterm * arg1 , aterm * arg2 , aterm * arg3) {
{
aterm * tmp[101];
PROF( prof_lf_AUX_MuASF_Rules2C12_3);
if( check_sym( arg0 , lf_AUX_MuASF_Rules2C12_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg2 , lf_AUX_MuASF_Rules2C12_2sym)) {
{
aterm * atmp20= arg_0( arg2);
t_protect( atmp00);
if( not_empty_list( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
if( check_sym( tmp[ 0] , ef1sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
tmp[ 3]= arg_2( tmp[ 0]);
tmp[ 4]= arg_3( tmp[ 0]);
tmp[ 5]= arg_4( tmp[ 0]);
{
if( check_sym( tmp[ 1] , lf4sym)) {
tmp[ 6]= arg_0( tmp[ 1]);
{
if( check_sym( tmp[ 2] , lf5sym)) {
tmp[ 7]= arg_0( tmp[ 2]);
t_protect( tmp[ 7]);
if( not_empty_list( tmp[ 7])) {
t_protect( tmp[ 7]);
tmp[ 8]= list_head( tmp[ 7]);
if( check_sym( tmp[ 8] , ef2sym)) {
tmp[ 9]= arg_0( tmp[ 8]);
tmp[ 10]= arg_1( tmp[ 8]);
{
if( check_sym( tmp[ 9] , ef3sym)) {
tmp[ 11]= arg_0( tmp[ 9]);
tmp[ 12]= arg_1( tmp[ 9]);
if( check_sym( tmp[ 11] , ef4sym)) {
tmp[ 13]= arg_0( tmp[ 11]);
if( check_sym( tmp[ 13] , lf6sym)) {
tmp[ 14]= arg_0( tmp[ 13]);
if( check_sym( tmp[ 12] , lf7sym)) {
tmp[ 15]= arg_0( tmp[ 12]);
t_protect( tmp[ 14]);
if( not_empty_list( tmp[ 14])) {
t_protect( tmp[ 14]);
if( term_equal( list_head( tmp[ 14]) , make_char( 116))) {
t_protect( tmp[ 14]);
tmp[ 16]= list_tail( tmp[ 14]);
t_protect( tmp[ 16]);
if( not_empty_list( tmp[ 16])) {
t_protect( tmp[ 16]);
if( term_equal( list_head( tmp[ 16]) , make_char( 101))) {
t_protect( tmp[ 16]);
tmp[ 17]= list_tail( tmp[ 16]);
t_protect( tmp[ 17]);
if( not_empty_list( tmp[ 17])) {
t_protect( tmp[ 17]);
if( term_equal( list_head( tmp[ 17]) , make_char( 114))) {
t_protect( tmp[ 17]);
tmp[ 18]= list_tail( tmp[ 17]);
t_protect( tmp[ 18]);
if( not_empty_list( tmp[ 18])) {
t_protect( tmp[ 18]);
if( term_equal( list_head( tmp[ 18]) , make_char( 109))) {
t_protect( tmp[ 18]);
tmp[ 19]= list_tail( tmp[ 18]);
t_protect( tmp[ 19]);
if( not_empty_list( tmp[ 19])) {
t_protect( tmp[ 19]);
if( term_equal( list_head( tmp[ 19]) , make_char( 45))) {
t_protect( tmp[ 19]);
tmp[ 20]= list_tail( tmp[ 19]);
t_protect( tmp[ 20]);
if( not_empty_list( tmp[ 20])) {
t_protect( tmp[ 20]);
if( term_equal( list_head( tmp[ 20]) , make_char( 101))) {
t_protect( tmp[ 20]);
tmp[ 21]= list_tail( tmp[ 20]);
t_protect( tmp[ 21]);
if( not_empty_list( tmp[ 21])) {
t_protect( tmp[ 21]);
if( term_equal( list_head( tmp[ 21]) , make_char( 113))) {
t_protect( tmp[ 21]);
tmp[ 22]= list_tail( tmp[ 21]);
t_protect( tmp[ 22]);
if( not_empty_list( tmp[ 22])) {
t_protect( tmp[ 22]);
if( term_equal( list_head( tmp[ 22]) , make_char( 117))) {
t_protect( tmp[ 22]);
tmp[ 23]= list_tail( tmp[ 22]);
t_protect( tmp[ 23]);
if( not_empty_list( tmp[ 23])) {
t_protect( tmp[ 23]);
if( term_equal( list_head( tmp[ 23]) , make_char( 97))) {
t_protect( tmp[ 23]);
tmp[ 24]= list_tail( tmp[ 23]);
t_protect( tmp[ 24]);
if( is_single_element( tmp[ 24])) {
t_protect( tmp[ 24]);
if( term_equal( list_head( tmp[ 24]) , make_char( 108))) {
t_protect( tmp[ 15]);
if( not_empty_list( tmp[ 15])) {
t_protect( tmp[ 15]);
tmp[ 25]= list_head( tmp[ 15]);
t_protect( tmp[ 15]);
tmp[ 26]= list_tail( tmp[ 15]);
t_protect( tmp[ 26]);
if( is_single_element( tmp[ 26])) {
t_protect( tmp[ 26]);
tmp[ 27]= list_head( tmp[ 26]);
t_protect( tmp[ 7]);
tmp[ 28]= list_tail( tmp[ 7]);
t_protect( atmp00);
tmp[ 29]= list_tail( atmp00);
t_protect( tmp[ 6]);
t_protect( tmp[ 25]);
t_protect( tmp[ 27]);
t_protect( tmp[ 10]);
t_protect( tmp[ 28]);
t_protect( tmp[ 3]);
t_protect( tmp[ 4]);
t_protect( tmp[ 5]);
t_protect( tmp[ 29]);
t_protect( arg1);
t_protect( arg2);
t_protect( arg3);
tmp[ 30]= ( * ef6)( lf_AUX_MuASF_Rules2C12_1( cons( make_list( ( * ef1)( lf4( make_list( tmp[ 6])) , lf5( cons( make_list( ( * ef2)( ( * ef3)( ( * ef4)( lf6( cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 113)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 97)) , make_list( make_char( 108))))))))))))) , lf7( cons( make_list( tmp[ 25]) , make_list( tmp[ 27])))) , tmp[ 10])) , make_list( tmp[ 28]))) , tmp[ 3] , tmp[ 4] , tmp[ 5])) , make_list( tmp[ 29]))) , arg1 , arg2 , arg3);
if( check_sym( tmp[ 30] , ef7sym)) {
tmp[ 31]= arg_0( tmp[ 30]);
tmp[ 32]= arg_1( tmp[ 30]);
tmp[ 33]= arg_2( tmp[ 30]);
tmp[ 34]= arg_3( tmp[ 30]);
tmp[ 35]= arg_4( tmp[ 30]);
if( check_sym( tmp[ 33] , lf_AUX_MuASF_Rules2C12_1sym)) {
tmp[ 36]= arg_0( tmp[ 33]);
t_protect( tmp[ 36]);
if( not_empty_list( tmp[ 36])) {
t_protect( tmp[ 36]);
tmp[ 37]= list_head( tmp[ 36]);
if( check_sym( tmp[ 37] , ef1sym)) {
tmp[ 38]= arg_0( tmp[ 37]);
tmp[ 39]= arg_1( tmp[ 37]);
tmp[ 40]= arg_2( tmp[ 37]);
tmp[ 41]= arg_3( tmp[ 37]);
tmp[ 42]= arg_4( tmp[ 37]);
if( check_sym( tmp[ 38] , lf4sym)) {
tmp[ 43]= arg_0( tmp[ 38]);
if( check_sym( tmp[ 39] , lf5sym)) {
tmp[ 44]= arg_0( tmp[ 39]);
t_protect( tmp[ 44]);
if( not_empty_list( tmp[ 44])) {
t_protect( tmp[ 44]);
tmp[ 45]= list_head( tmp[ 44]);
if( check_sym( tmp[ 45] , ef2sym)) {
tmp[ 46]= arg_0( tmp[ 45]);
tmp[ 47]= arg_1( tmp[ 45]);
if( check_sym( tmp[ 46] , ef3sym)) {
tmp[ 48]= arg_0( tmp[ 46]);
tmp[ 49]= arg_1( tmp[ 46]);
if( check_sym( tmp[ 48] , ef4sym)) {
tmp[ 50]= arg_0( tmp[ 48]);
if( check_sym( tmp[ 50] , lf6sym)) {
tmp[ 51]= arg_0( tmp[ 50]);
if( check_sym( tmp[ 49] , lf7sym)) {
tmp[ 52]= arg_0( tmp[ 49]);
t_protect( tmp[ 51]);
if( not_empty_list( tmp[ 51])) {
t_protect( tmp[ 51]);
if( term_equal( list_head( tmp[ 51]) , make_char( 116))) {
t_protect( tmp[ 51]);
tmp[ 53]= list_tail( tmp[ 51]);
t_protect( tmp[ 53]);
if( not_empty_list( tmp[ 53])) {
t_protect( tmp[ 53]);
if( term_equal( list_head( tmp[ 53]) , make_char( 101))) {
t_protect( tmp[ 53]);
tmp[ 54]= list_tail( tmp[ 53]);
t_protect( tmp[ 54]);
if( not_empty_list( tmp[ 54])) {
t_protect( tmp[ 54]);
if( term_equal( list_head( tmp[ 54]) , make_char( 114))) {
t_protect( tmp[ 54]);
tmp[ 55]= list_tail( tmp[ 54]);
t_protect( tmp[ 55]);
if( not_empty_list( tmp[ 55])) {
t_protect( tmp[ 55]);
if( term_equal( list_head( tmp[ 55]) , make_char( 109))) {
t_protect( tmp[ 55]);
tmp[ 56]= list_tail( tmp[ 55]);
t_protect( tmp[ 56]);
if( not_empty_list( tmp[ 56])) {
t_protect( tmp[ 56]);
if( term_equal( list_head( tmp[ 56]) , make_char( 45))) {
t_protect( tmp[ 56]);
tmp[ 57]= list_tail( tmp[ 56]);
t_protect( tmp[ 57]);
if( not_empty_list( tmp[ 57])) {
t_protect( tmp[ 57]);
if( term_equal( list_head( tmp[ 57]) , make_char( 101))) {
t_protect( tmp[ 57]);
tmp[ 58]= list_tail( tmp[ 57]);
t_protect( tmp[ 58]);
if( not_empty_list( tmp[ 58])) {
t_protect( tmp[ 58]);
if( term_equal( list_head( tmp[ 58]) , make_char( 113))) {
t_protect( tmp[ 58]);
tmp[ 59]= list_tail( tmp[ 58]);
t_protect( tmp[ 59]);
if( not_empty_list( tmp[ 59])) {
t_protect( tmp[ 59]);
if( term_equal( list_head( tmp[ 59]) , make_char( 117))) {
t_protect( tmp[ 59]);
tmp[ 60]= list_tail( tmp[ 59]);
t_protect( tmp[ 60]);
if( not_empty_list( tmp[ 60])) {
t_protect( tmp[ 60]);
if( term_equal( list_head( tmp[ 60]) , make_char( 97))) {
t_protect( tmp[ 60]);
tmp[ 61]= list_tail( tmp[ 60]);
t_protect( tmp[ 61]);
if( is_single_element( tmp[ 61])) {
t_protect( tmp[ 61]);
if( term_equal( list_head( tmp[ 61]) , make_char( 108))) {
t_protect( tmp[ 52]);
if( not_empty_list( tmp[ 52])) {
t_protect( tmp[ 52]);
tmp[ 62]= list_head( tmp[ 52]);
t_protect( tmp[ 52]);
tmp[ 63]= list_tail( tmp[ 52]);
t_protect( tmp[ 63]);
if( is_single_element( tmp[ 63])) {
t_protect( tmp[ 63]);
tmp[ 64]= list_head( tmp[ 63]);
t_protect( tmp[ 44]);
tmp[ 65]= list_tail( tmp[ 44]);
t_protect( tmp[ 36]);
tmp[ 66]= list_tail( tmp[ 36]);
t_protect( tmp[ 34]);
tmp[ 67]= ( * ef8)( ( * ef9)( tmp[ 34]));
t_protect( tmp[ 62]);
t_protect( tmp[ 64]);
t_protect( tmp[ 41]);
t_protect( tmp[ 42]);
t_protect( tmp[ 34]);
t_protect( tmp[ 67]);
t_protect( arg1);
t_protect( arg2);
tmp[ 68]= ( * ef10)( ( * ef11)( ) , lf7( cons( make_list( tmp[ 62]) , make_list( tmp[ 64]))) , tmp[ 41] , tmp[ 42] , tmp[ 34] , tmp[ 67] , arg1 , arg2);
if( check_sym( tmp[ 68] , ef12sym)) {
tmp[ 69]= arg_0( tmp[ 68]);
tmp[ 70]= arg_1( tmp[ 68]);
tmp[ 71]= arg_2( tmp[ 68]);
t_protect( tmp[ 43]);
t_protect( tmp[ 62]);
t_protect( tmp[ 64]);
t_protect( tmp[ 47]);
t_protect( tmp[ 65]);
t_protect( tmp[ 40]);
t_protect( tmp[ 41]);
t_protect( tmp[ 42]);
t_protect( tmp[ 66]);
tmp[ 72]= ( * ef13)( ( * ef1)( lf4( make_list( tmp[ 43])) , lf5( cons( make_list( ( * ef2)( ( * ef3)( ( * ef4)( lf6( cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 113)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 97)) , make_list( make_char( 108))))))))))))) , lf7( cons( make_list( tmp[ 62]) , make_list( tmp[ 64])))) , tmp[ 47])) , make_list( tmp[ 65]))) , tmp[ 40] , tmp[ 41] , tmp[ 42]) , lf_AUX_MuASF_Rules2C12_1( make_list( tmp[ 66])));
if( check_sym( tmp[ 72] , ef14sym)) {
tmp[ 73]= arg_0( tmp[ 72]);
tmp[ 74]= arg_1( tmp[ 72]);
if( check_sym( tmp[ 73] , lf_AUX_MuASF_Rules2C12_1sym)) {
tmp[ 75]= arg_0( tmp[ 73]);
if( check_sym( tmp[ 74] , lf_AUX_MuASF_Rules2C12_1sym)) {
tmp[ 76]= arg_0( tmp[ 74]);
t_protect( tmp[ 43]);
t_protect( tmp[ 62]);
t_protect( tmp[ 64]);
t_protect( tmp[ 47]);
t_protect( tmp[ 65]);
t_protect( tmp[ 40]);
t_protect( tmp[ 41]);
t_protect( tmp[ 42]);
t_protect( tmp[ 75]);
tmp[ 77]= ( * ef15)( ( * ef1)( lf4( make_list( tmp[ 43])) , lf5( cons( make_list( ( * ef2)( ( * ef3)( ( * ef4)( lf6( cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 113)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 97)) , make_list( make_char( 108))))))))))))) , lf7( cons( make_list( tmp[ 62]) , make_list( tmp[ 64])))) , tmp[ 47])) , make_list( tmp[ 65]))) , tmp[ 40] , tmp[ 41] , tmp[ 42]) , lf_AUX_MuASF_Rules2C12_1( make_list( tmp[ 75])));
if( check_sym( tmp[ 77] , ef14sym)) {
tmp[ 78]= arg_0( tmp[ 77]);
tmp[ 79]= arg_1( tmp[ 77]);
if( check_sym( tmp[ 78] , lf_AUX_MuASF_Rules2C12_1sym)) {
tmp[ 80]= arg_0( tmp[ 78]);
if( check_sym( tmp[ 79] , lf_AUX_MuASF_Rules2C12_1sym)) {
tmp[ 81]= arg_0( tmp[ 79]);
t_protect( tmp[ 80]);
tmp[ 82]= ( * ef16)( lf_AUX_MuASF_Rules2C12_1( make_list( tmp[ 80])));
if( check_sym( tmp[ 82] , ef17sym)) {
tmp[ 83]= arg_0( tmp[ 82]);
if( check_sym( tmp[ 83] , lf_AUX_MuASF_Rules2C12_1sym)) {
tmp[ 84]= arg_0( tmp[ 83]);
t_protect( tmp[ 84]);
t_protect( tmp[ 35]);
t_protect( arg2);
t_protect( tmp[ 71]);
tmp[ 85]= ( * ef18)( lf_AUX_MuASF_Rules2C12_1( make_list( tmp[ 84])) , tmp[ 35] , arg2 , tmp[ 71]);
if( check_sym( tmp[ 85] , ef5sym)) {
tmp[ 86]= arg_0( tmp[ 85]);
tmp[ 87]= arg_1( tmp[ 85]);
t_protect( tmp[ 81]);
tmp[ 88]= ( * ef16)( lf_AUX_MuASF_Rules2C12_1( make_list( tmp[ 81])));
if( check_sym( tmp[ 88] , ef17sym)) {
tmp[ 89]= arg_0( tmp[ 88]);
if( check_sym( tmp[ 89] , lf_AUX_MuASF_Rules2C12_1sym)) {
tmp[ 90]= arg_0( tmp[ 89]);
t_protect( tmp[ 90]);
t_protect( arg1);
t_protect( arg2);
t_protect( tmp[ 71]);
tmp[ 91]= ( * ef18)( lf_AUX_MuASF_Rules2C12_1( make_list( tmp[ 90])) , arg1 , arg2 , tmp[ 71]);
if( check_sym( tmp[ 91] , ef5sym)) {
tmp[ 92]= arg_0( tmp[ 91]);
tmp[ 93]= arg_1( tmp[ 91]);
t_protect( tmp[ 76]);
t_protect( tmp[ 35]);
t_protect( arg2);
t_protect( tmp[ 71]);
tmp[ 94]= ( * ef18)( lf_AUX_MuASF_Rules2C12_1( make_list( tmp[ 76])) , tmp[ 35] , arg2 , tmp[ 71]);
if( check_sym( tmp[ 94] , ef5sym)) {
tmp[ 95]= arg_0( tmp[ 94]);
tmp[ 96]= arg_1( tmp[ 94]);
tmp[ 97]= ( * ef19)( ( * ef4)( lf6( cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 113)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 97)) , make_list( make_char( 108))))))))))))));
t_protect( tmp[ 31]);
t_protect( tmp[ 70]);
t_protect( tmp[ 10]);
t_protect( tmp[ 97]);
t_protect( tmp[ 69]);
t_protect( tmp[ 86]);
t_protect( tmp[ 92]);
t_protect( tmp[ 95]);
t_protect( tmp[ 32]);
tmp[ 98]= ( * ef20)( ( * ef20)( ( * ef20)( ( * ef20)( tmp[ 31] , tmp[ 70]) , ( * ef21)( tmp[ 10] , ( * ef8)( ( * ef22)( tmp[ 97] , tmp[ 69])) , tmp[ 86] , tmp[ 92])) , tmp[ 95]) , tmp[ 32]);
t_protect( tmp[ 87]);
t_protect( tmp[ 93]);
tmp[ 99]= ( * ef23)( tmp[ 87] , tmp[ 93]);
t_protect( tmp[ 96]);
t_protect( tmp[ 99]);
tmp[ 100]= ( * ef23)( tmp[ 96] , tmp[ 99]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 17]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 21]);
t_unprotect( tmp[ 22]);
t_unprotect( tmp[ 23]);
t_unprotect( tmp[ 24]);
t_unprotect( tmp[ 25]);
t_unprotect( tmp[ 26]);
t_unprotect( tmp[ 27]);
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 29]);
t_unprotect( tmp[ 30]);
t_unprotect( tmp[ 37]);
t_unprotect( tmp[ 45]);
t_unprotect( tmp[ 53]);
t_unprotect( tmp[ 54]);
t_unprotect( tmp[ 55]);
t_unprotect( tmp[ 56]);
t_unprotect( tmp[ 57]);
t_unprotect( tmp[ 58]);
t_unprotect( tmp[ 59]);
t_unprotect( tmp[ 60]);
t_unprotect( tmp[ 61]);
t_unprotect( tmp[ 62]);
t_unprotect( tmp[ 63]);
t_unprotect( tmp[ 64]);
t_unprotect( tmp[ 65]);
t_unprotect( tmp[ 66]);
t_unprotect( tmp[ 67]);
t_unprotect( tmp[ 68]);
t_unprotect( tmp[ 72]);
t_unprotect( tmp[ 77]);
t_unprotect( tmp[ 82]);
t_unprotect( tmp[ 85]);
t_unprotect( tmp[ 88]);
t_unprotect( tmp[ 91]);
t_unprotect( tmp[ 94]);
t_unprotect( tmp[ 97]);
t_unprotect( tmp[ 99]);
return ( * ef5)( tmp[ 98] , tmp[ 100]);
}
t_unprotect( tmp[ 94]);
}
t_unprotect( tmp[ 91]);
}
}
t_unprotect( tmp[ 88]);
}
t_unprotect( tmp[ 85]);
}
}
t_unprotect( tmp[ 82]);
}
}
}
t_unprotect( tmp[ 77]);
}
}
}
t_unprotect( tmp[ 72]);
}
t_unprotect( tmp[ 68]);
t_unprotect( tmp[ 67]);
t_unprotect( tmp[ 66]);
t_unprotect( tmp[ 65]);
t_unprotect( tmp[ 64]);
}
t_unprotect( tmp[ 63]);
t_unprotect( tmp[ 62]);
}
}
}
t_unprotect( tmp[ 61]);
}
}
t_unprotect( tmp[ 60]);
}
}
t_unprotect( tmp[ 59]);
}
}
t_unprotect( tmp[ 58]);
}
}
t_unprotect( tmp[ 57]);
}
}
t_unprotect( tmp[ 56]);
}
}
t_unprotect( tmp[ 55]);
}
}
t_unprotect( tmp[ 54]);
}
}
t_unprotect( tmp[ 53]);
}
}
}
}
}
}
}
t_unprotect( tmp[ 45]);
}
}
}
}
t_unprotect( tmp[ 37]);
}
}
}
t_unprotect( tmp[ 30]);
t_unprotect( tmp[ 29]);
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 27]);
}
t_unprotect( tmp[ 26]);
t_unprotect( tmp[ 25]);
}
}
}
t_unprotect( tmp[ 24]);
}
}
t_unprotect( tmp[ 23]);
}
}
t_unprotect( tmp[ 22]);
}
}
t_unprotect( tmp[ 21]);
}
}
t_unprotect( tmp[ 20]);
}
}
t_unprotect( tmp[ 19]);
}
}
t_unprotect( tmp[ 18]);
}
}
t_unprotect( tmp[ 17]);
}
}
t_unprotect( tmp[ 16]);
}
}
}
}
}
}
t_protect( tmp[ 7]);
tmp[ 11]= list_tail( tmp[ 7]);
t_protect( atmp00);
tmp[ 12]= list_tail( atmp00);
t_protect( tmp[ 9]);
tmp[ 13]= ( * ef24)( tmp[ 9]);
t_protect( tmp[ 13]);
if( ! term_equal( tmp[ 13] , ( * ef4)( lf6( cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 113)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 97)) , make_list( make_char( 108))))))))))))))) {
t_protect( tmp[ 10]);
if( term_equal( ( * ef25)( tmp[ 10]) , ( * ef26)( ))) {
t_protect( tmp[ 9]);
tmp[ 14]= ( * ef27)( tmp[ 9]);
if( check_sym( tmp[ 14] , ef28sym)) {
tmp[ 15]= arg_0( tmp[ 14]);
if( check_sym( tmp[ 15] , lf7sym)) {
tmp[ 16]= arg_0( tmp[ 15]);
t_protect( tmp[ 16]);
if( not_empty_list( tmp[ 16])) {
t_protect( arg3);
tmp[ 17]= ( * ef8)( ( * ef9)( arg3));
t_protect( tmp[ 16]);
t_protect( tmp[ 4]);
t_protect( tmp[ 5]);
t_protect( arg3);
t_protect( tmp[ 17]);
t_protect( arg1);
t_protect( arg2);
tmp[ 18]= ( * ef10)( ( * ef11)( ) , lf7( make_list( tmp[ 16])) , tmp[ 4] , tmp[ 5] , arg3 , tmp[ 17] , arg1 , arg2);
if( check_sym( tmp[ 18] , ef12sym)) {
tmp[ 19]= arg_0( tmp[ 18]);
tmp[ 20]= arg_1( tmp[ 18]);
tmp[ 21]= arg_2( tmp[ 18]);
t_protect( tmp[ 6]);
t_protect( tmp[ 9]);
t_protect( tmp[ 10]);
t_protect( tmp[ 11]);
t_protect( tmp[ 3]);
t_protect( tmp[ 4]);
t_protect( tmp[ 5]);
t_protect( tmp[ 12]);
tmp[ 22]= ( * ef15)( ( * ef1)( lf4( make_list( tmp[ 6])) , lf5( cons( make_list( ( * ef2)( tmp[ 9] , tmp[ 10])) , make_list( tmp[ 11]))) , tmp[ 3] , tmp[ 4] , tmp[ 5]) , lf_AUX_MuASF_Rules2C12_1( make_list( tmp[ 12])));
if( check_sym( tmp[ 22] , ef14sym)) {
tmp[ 23]= arg_0( tmp[ 22]);
tmp[ 24]= arg_1( tmp[ 22]);
if( check_sym( tmp[ 23] , lf_AUX_MuASF_Rules2C12_1sym)) {
tmp[ 25]= arg_0( tmp[ 23]);
if( check_sym( tmp[ 24] , lf_AUX_MuASF_Rules2C12_1sym)) {
tmp[ 26]= arg_0( tmp[ 24]);
t_protect( tmp[ 25]);
tmp[ 27]= ( * ef16)( lf_AUX_MuASF_Rules2C12_1( make_list( tmp[ 25])));
if( check_sym( tmp[ 27] , ef17sym)) {
tmp[ 28]= arg_0( tmp[ 27]);
if( check_sym( tmp[ 28] , lf_AUX_MuASF_Rules2C12_1sym)) {
tmp[ 29]= arg_0( tmp[ 28]);
t_protect( tmp[ 29]);
t_protect( arg1);
t_protect( arg2);
t_protect( tmp[ 21]);
tmp[ 30]= ( * ef18)( lf_AUX_MuASF_Rules2C12_1( make_list( tmp[ 29])) , arg1 , arg2 , tmp[ 21]);
if( check_sym( tmp[ 30] , ef5sym)) {
tmp[ 31]= arg_0( tmp[ 30]);
tmp[ 32]= arg_1( tmp[ 30]);
t_protect( tmp[ 26]);
tmp[ 33]= ( * ef16)( lf_AUX_MuASF_Rules2C12_1( make_list( tmp[ 26])));
if( check_sym( tmp[ 33] , ef17sym)) {
tmp[ 34]= arg_0( tmp[ 33]);
if( check_sym( tmp[ 34] , lf_AUX_MuASF_Rules2C12_1sym)) {
tmp[ 35]= arg_0( tmp[ 34]);
t_protect( tmp[ 35]);
t_protect( arg1);
t_protect( arg2);
t_protect( tmp[ 21]);
tmp[ 36]= ( * ef18)( lf_AUX_MuASF_Rules2C12_1( make_list( tmp[ 35])) , arg1 , arg2 , tmp[ 21]);
if( check_sym( tmp[ 36] , ef5sym)) {
tmp[ 37]= arg_0( tmp[ 36]);
tmp[ 38]= arg_1( tmp[ 36]);
t_protect( tmp[ 13]);
tmp[ 39]= ( * ef19)( tmp[ 13]);
t_protect( tmp[ 20]);
t_protect( tmp[ 10]);
t_protect( tmp[ 39]);
t_protect( tmp[ 19]);
t_protect( tmp[ 31]);
t_protect( tmp[ 37]);
tmp[ 40]= ( * ef20)( tmp[ 20] , ( * ef21)( tmp[ 10] , ( * ef8)( ( * ef22)( tmp[ 39] , tmp[ 19])) , tmp[ 31] , tmp[ 37]));
t_protect( tmp[ 32]);
t_protect( tmp[ 38]);
tmp[ 41]= ( * ef23)( tmp[ 32] , tmp[ 38]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 17]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 22]);
t_unprotect( tmp[ 27]);
t_unprotect( tmp[ 30]);
t_unprotect( tmp[ 33]);
t_unprotect( tmp[ 36]);
t_unprotect( tmp[ 39]);
return ( * ef5)( tmp[ 40] , tmp[ 41]);
}
t_unprotect( tmp[ 36]);
}
}
t_unprotect( tmp[ 33]);
}
t_unprotect( tmp[ 30]);
}
}
t_unprotect( tmp[ 27]);
}
}
}
t_unprotect( tmp[ 22]);
}
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 17]);
}
}
}
t_unprotect( tmp[ 14]);
}
}
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 11]);
}
}
t_unprotect( tmp[ 8]);
}
}
}
}
}
}
t_unprotect( tmp[ 0]);
}
}
}
}
}
if( check_sym( arg0 , lf_AUX_MuASF_Rules2C12_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg2 , lf_AUX_MuASF_Rules2C12_2sym)) {
{
aterm * atmp20= arg_0( arg2);
t_protect( atmp00);
if( not_empty_list( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
if( check_sym( tmp[ 0] , ef1sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
tmp[ 3]= arg_2( tmp[ 0]);
tmp[ 4]= arg_3( tmp[ 0]);
tmp[ 5]= arg_4( tmp[ 0]);
if( check_sym( tmp[ 1] , lf4sym)) {
tmp[ 6]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , lf5sym)) {
tmp[ 7]= arg_0( tmp[ 2]);
t_protect( tmp[ 7]);
if( not_empty_list( tmp[ 7])) {
t_protect( tmp[ 7]);
tmp[ 8]= list_head( tmp[ 7]);
if( check_sym( tmp[ 8] , ef2sym)) {
tmp[ 9]= arg_0( tmp[ 8]);
tmp[ 10]= arg_1( tmp[ 8]);
t_protect( tmp[ 7]);
tmp[ 11]= list_tail( tmp[ 7]);
t_protect( atmp00);
tmp[ 12]= list_tail( atmp00);
t_protect( tmp[ 6]);
t_protect( tmp[ 9]);
t_protect( tmp[ 10]);
t_protect( tmp[ 3]);
t_protect( tmp[ 4]);
t_protect( tmp[ 5]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 8]);
return new__1__lf_AUX_MuASF_Rules2C12_3( lf_AUX_MuASF_Rules2C12_1( cons( make_list( ( * ef1)( lf4( make_list( tmp[ 6])) , lf5( cons( make_list( ( * ef2)( tmp[ 9] , tmp[ 10])) , make_list( tmp[ 11]))) , tmp[ 3] , tmp[ 4] , tmp[ 5])) , make_list( tmp[ 12]))) , arg1 , arg2 , arg3);
}
t_unprotect( tmp[ 8]);
}
}
}
}
t_unprotect( tmp[ 0]);
}
}
}
}
}
return make_nf4( lf_AUX_MuASF_Rules2C12_3sym , arg0 , arg1 , arg2 , arg3);
}
}
aterm * lf_AUX_MuASF_Rules2C12_2( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Rules2C12_2);
return make_nf1( lf_AUX_MuASF_Rules2C12_2sym , arg0);
}
aterm * lf5( aterm * arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
aterm * lf_AUX_MuASF_Rules2C12_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Rules2C12_1);
return make_nf1( lf_AUX_MuASF_Rules2C12_1sym , arg0);
}
aterm * lf7( aterm * arg0) {
PROF( prof_lf7);
return make_nf1( lf7sym , arg0);
}
aterm * lf6( aterm * arg0) {
PROF( prof_lf6);
return make_nf1( lf6sym , arg0);
}

