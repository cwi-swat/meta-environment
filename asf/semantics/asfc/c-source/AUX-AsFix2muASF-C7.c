#include  "support.h"
static Symbol lf_AUX_AsFix2muASF_C7_1sym ;
static ATerm lf_AUX_AsFix2muASF_C7_1 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef15sym ;
static funcptr ef15 ;
static Symbol ef16sym ;
static funcptr ef16 ;
static Symbol ef17sym ;
static funcptr ef17 ;
static Symbol ef18sym ;
static funcptr ef18 ;
static Symbol ef19sym ;
static funcptr ef19 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef24sym ;
static funcptr ef24 ;
static Symbol ef25sym ;
static funcptr ef25 ;
static Symbol ef27sym ;
static funcptr ef27 ;
static Symbol ef29sym ;
static funcptr ef29 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef30sym ;
static funcptr ef30 ;
static Symbol ef22sym ;
static funcptr ef22 ;
static Symbol ef23sym ;
static funcptr ef23 ;
static Symbol ef42sym ;
static funcptr ef42 ;
static Symbol ef34sym ;
static funcptr ef34 ;
static Symbol ef43sym ;
static funcptr ef43 ;
static Symbol ef26sym ;
static funcptr ef26 ;
static Symbol ef35sym ;
static funcptr ef35 ;
static Symbol ef36sym ;
static funcptr ef36 ;
static Symbol ef37sym ;
static funcptr ef37 ;
static Symbol ef40sym ;
static funcptr ef40 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol ef41sym ;
static funcptr ef41 ;
static Symbol ef38sym ;
static funcptr ef38 ;
static Symbol ef39sym ;
static funcptr ef39 ;
static Symbol ef28sym ;
static funcptr ef28 ;
static Symbol ef31sym ;
static funcptr ef31 ;
static Symbol ef44sym ;
static funcptr ef44 ;
static Symbol ef45sym ;
static funcptr ef45 ;
static Symbol ef20sym ;
static funcptr ef20 ;
static Symbol ef21sym ;
static funcptr ef21 ;
static Symbol ef32sym ;
static funcptr ef32 ;
static Symbol lf5sym ;
static ATerm lf5 ( ATerm arg1 ) ;
static Symbol ef33sym ;
static funcptr ef33 ;
static Symbol ef46sym ;
static funcptr ef46 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
void register_AUX_AsFix2muASF_C7 ( ) {
lf_AUX_AsFix2muASF_C7_1sym = ATmakeSymbol ( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"aterm2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)"
 , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AsFix2muASF_C7_1sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"AFun\"),ql(\".\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf5sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf5sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"FuncDef\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
register_prod ( ATparse ( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"aterm2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)" ) , lf_AUX_AsFix2muASF_C7_1 , lf_AUX_AsFix2muASF_C7_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"FuncDef\"),ql(\";\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"AFun\"),ql(\".\"))" ) , lf4 , lf4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf5 , lf5sym ) ;
}
void resolve_AUX_AsFix2muASF_C7 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[ql(\"avar2muvar\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[ql(\"avar2muvar\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"appl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"appl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"args2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"args2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\".\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\".\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"prod\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"prod\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"is-bracket-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"is-bracket-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"args\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"args\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"cffunc2id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"cffunc2id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef17 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"attrs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef17sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"attrs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef18 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix2Sign-C\"),w(\"\"),[l(\"attrs2terms\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef18sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix2Sign-C\"),w(\"\"),[l(\"attrs2terms\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef19 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"nt-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)" ) ) ;
ef19sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"nt-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)" ) ) ;
ef20 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)" ) ) ;
ef20sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)" ) ) ;
ef21 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"make-external-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) ) ;
ef21sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"make-external-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) ) ;
ef22 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Signs\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++_ss\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef22sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Signs\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++_ss\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef23 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)" ) ) ;
ef23sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)" ) ) ;
ef24 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef24sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef25 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-list-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef25sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-list-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef26 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"sym\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef26sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"sym\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef27 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"iter2id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef27sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"iter2id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef28 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"ntl-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)" ) ) ;
ef28sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"ntl-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)" ) ) ;
ef29 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"elems\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef29sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"elems\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef30 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"listargs2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef30sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"listargs2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef31 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"make-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) ) ;
ef31sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"make-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) ) ;
ef32 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef32sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef33 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef33sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef34 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"lex\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef34sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"lex\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef35 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef35sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef36 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef36sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef37 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef37sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef38 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef38sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef39 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef39sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef40 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
ef40sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
ef41 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"name\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef41sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"name\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef42 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"qlit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef42sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"qlit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef43 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef43sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef44 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"make-caller-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef44sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"make-caller-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef45 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"nt-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)" ) ) ;
ef45sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"nt-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)" ) ) ;
ef46 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"lit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef46sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"lit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
static ATerm constant3 = NULL ;
static ATerm constant4 = NULL ;
static ATerm constant5 = NULL ;
static ATerm constant6 = NULL ;
static ATerm constant7 = NULL ;
static ATerm constant8 = NULL ;
static ATerm constant9 = NULL ;
static ATerm constant10 = NULL ;
static ATerm constant11 = NULL ;
void init_AUX_AsFix2muASF_C7 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
ATprotect ( & constant3 ) ;
ATprotect ( & constant4 ) ;
ATprotect ( & constant5 ) ;
ATprotect ( & constant6 ) ;
ATprotect ( & constant7 ) ;
ATprotect ( & constant8 ) ;
ATprotect ( & constant9 ) ;
ATprotect ( & constant10 ) ;
ATprotect ( & constant11 ) ;
}
ATerm lf_AUX_AsFix2muASF_C7_1 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
{
ATerm tmp [ 23 ] ;
FUNC_ENTRY ( lf_AUX_AsFix2muASF_C7_1sym , ATmakeAppl ( lf_AUX_AsFix2muASF_C7_1sym , arg0 , arg1 , arg2 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
tmp [ 0 ] = ( * ef5 ) ( arg1 ) ;
FUNC_EXIT ( ( * ef2 ) ( lf2 ( make_list ( null ( ) ) ) , ( * ef3 ) ( lf3 ( make_list ( ( * ef4 ) ( tmp [ 0 ] ) ) ) ) , arg2 ) ) ;
}
if ( check_sym ( arg0 , ef6sym ) ) {
tmp [ 0 ] = ( * ef8 ) ( arg1 , ( constant0 ? constant0 : ( constant0 = lf4 ( make_list ( ( * ef9 ) ( ) ) ) ) ) ) ;
tmp [ 1 ] = ( * ef10 ) ( tmp [ 0 ] ) ;
if ( term_equal ( tmp [ 1 ] , ( constant1 ? constant1 : ( constant1 = ( * ef11 ) ( ) ) ) ) ) {
tmp [ 2 ] = ( * ef8 ) ( arg1 , ( constant2 ? constant2 : ( constant2 = lf4 ( make_list ( ( * ef12 ) ( ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 2 ] , ef13sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
FUNC_EXIT ( ( * ef7 ) ( tmp [ 3 ] , arg2 ) ) ;
}
}
if ( term_equal ( tmp [ 1 ] , ( constant3 ? constant3 : ( constant3 = ( * ef15 ) ( ) ) ) ) ) {
tmp [ 2 ] = ( * ef16 ) ( tmp [ 0 ] ) ;
tmp [ 3 ] = ( * ef8 ) ( tmp [ 0 ] , ( constant4 ? constant4 : ( constant4 = lf4 ( make_list ( ( * ef17 ) ( ) ) ) ) ) ) ;
tmp [ 4 ] = ( * ef18 ) ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 4 ] , ef3sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 5 ] , lf3sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
tmp [ 7 ] = ( * ef19 ) ( tmp [ 2 ] , ( * ef3 ) ( lf3 ( make_list ( tmp [ 6 ] ) ) ) , arg2 ) ;
if ( check_sym ( tmp [ 7 ] , ef20sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
tmp [ 9 ] = arg_1 ( tmp [ 7 ] ) ;
tmp [ 10 ] = ( * ef8 ) ( arg1 , ( constant2 ? constant2 : ( constant2 = lf4 ( make_list ( ( * ef12 ) ( ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 10 ] , ef13sym ) ) {
tmp [ 11 ] = arg_0 ( tmp [ 10 ] ) ;
tmp [ 12 ] = ( * ef7 ) ( tmp [ 11 ] , tmp [ 9 ] ) ;
if ( check_sym ( tmp [ 12 ] , ef2sym ) ) {
tmp [ 13 ] = arg_0 ( tmp [ 12 ] ) ;
tmp [ 14 ] = arg_1 ( tmp [ 12 ] ) ;
tmp [ 15 ] = arg_2 ( tmp [ 12 ] ) ;
if ( check_sym ( tmp [ 13 ] , lf2sym ) ) {
tmp [ 16 ] = arg_0 ( tmp [ 13 ] ) ;
if ( check_sym ( tmp [ 14 ] , ef3sym ) ) {
tmp [ 17 ] = arg_0 ( tmp [ 14 ] ) ;
if ( check_sym ( tmp [ 17 ] , lf3sym ) ) {
tmp [ 18 ] = arg_0 ( tmp [ 17 ] ) ;
tmp [ 19 ] = ( * ef21 ) ( tmp [ 8 ] , ( * ef3 ) ( lf3 ( make_list ( tmp [ 18 ] ) ) ) ) ;
tmp [ 20 ] = ( * ef22 ) ( ( * ef23 ) ( lf2 ( make_list ( tmp [ 19 ] ) ) ) , ( * ef23 ) ( lf2 ( make_list ( tmp [ 16 ] ) ) ) ) ;
if ( check_sym ( tmp [ 20 ] , ef23sym ) ) {
tmp [ 21 ] = arg_0 ( tmp [ 20 ] ) ;
if ( check_sym ( tmp [ 21 ] , lf2sym ) ) {
tmp [ 22 ] = arg_0 ( tmp [ 21 ] ) ;
FUNC_EXIT ( ( * ef2 ) ( lf2 ( make_list ( tmp [ 22 ] ) ) , ( * ef3 ) ( lf3 ( make_list ( ( * ef14 ) ( tmp [ 8 ] , lf3 ( make_list ( tmp [ 18 ] ) ) ) ) ) ) , tmp [ 15 ] ) ) ;
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
if ( check_sym ( arg0 , ef24sym ) ) {
tmp [ 0 ] = ( * ef8 ) ( arg1 , ( constant5 ? constant5 : ( constant5 = lf4 ( make_list ( ( * ef26 ) ( ) ) ) ) ) ) ;
tmp [ 1 ] = ( * ef27 ) ( tmp [ 0 ] ) ;
tmp [ 2 ] = ( * ef28 ) ( tmp [ 1 ] , arg2 ) ;
if ( check_sym ( tmp [ 2 ] , ef20sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
tmp [ 4 ] = arg_1 ( tmp [ 2 ] ) ;
tmp [ 5 ] = ( * ef8 ) ( arg1 , ( constant6 ? constant6 : ( constant6 = lf4 ( make_list ( ( * ef29 ) ( ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 5 ] , ef13sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
tmp [ 7 ] = ( * ef30 ) ( tmp [ 6 ] , tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 7 ] , ef2sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
tmp [ 9 ] = arg_1 ( tmp [ 7 ] ) ;
tmp [ 10 ] = arg_2 ( tmp [ 7 ] ) ;
if ( check_sym ( tmp [ 8 ] , lf2sym ) ) {
tmp [ 11 ] = arg_0 ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 9 ] , ef3sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 9 ] ) ;
if ( check_sym ( tmp [ 12 ] , lf3sym ) ) {
tmp [ 13 ] = arg_0 ( tmp [ 12 ] ) ;
tmp [ 14 ] = ( * ef31 ) ( tmp [ 1 ] , ( constant7 ? constant7 : ( constant7 = ( * ef3 ) ( lf3 ( make_list ( ( * ef32 ) ( ( * ef33 ) ( lf5 ( cons ( make_list ( make_char ( 110 ) ) , cons ( make_list ( make_char ( 117 ) ) , cons ( make_list ( make_char ( 108 ) ) , make_list ( make_char ( 108 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ;
tmp [ 15 ] = ( * ef22 ) ( ( * ef23 ) ( lf2 ( make_list ( tmp [ 14 ] ) ) ) , ( * ef23 ) ( lf2 ( make_list ( tmp [ 11 ] ) ) ) ) ;
if ( check_sym ( tmp [ 15 ] , ef23sym ) ) {
tmp [ 16 ] = arg_0 ( tmp [ 15 ] ) ;
if ( check_sym ( tmp [ 16 ] , lf2sym ) ) {
tmp [ 17 ] = arg_0 ( tmp [ 16 ] ) ;
FUNC_EXIT ( ( * ef2 ) ( lf2 ( make_list ( tmp [ 17 ] ) ) , ( * ef3 ) ( lf3 ( make_list ( ( * ef25 ) ( tmp [ 1 ] , lf3 ( make_list ( tmp [ 13 ] ) ) ) ) ) ) , tmp [ 10 ] ) ) ;
}
}
}
}
}
}
}
}
}
if ( check_sym ( arg0 , ef34sym ) ) {
if ( term_equal ( ( * ef8 ) ( arg1 , ( constant5 ? constant5 : ( constant5 = lf4 ( make_list ( ( * ef26 ) ( ) ) ) ) ) ) , ( constant8 ? constant8 : ( constant8 = ( * ef35 ) ( ( * ef36 ) ( ) , ( * ef37 ) ( ( * ef38 ) ( ( * ef39 ) ( ( * ef40 ) ( lf5 ( ( ATerm ) ATmakeList ( 6 , char_table [ 34 ] , char_table [ 67 ] , char_table [ 72 ] , char_table [ 65 ] , char_table [ 82 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ) ) ) {
tmp [ 0 ] = ( * ef8 ) ( arg1 , ( constant9 ? constant9 : ( constant9 = lf4 ( make_list ( ( * ef41 ) ( ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 0 ] , ef38sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , ef39sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ;
tmp [ 3 ] = ( * ef42 ) ( tmp [ 2 ] ) ;
FUNC_EXIT ( ( * ef2 ) ( lf2 ( make_list ( null ( ) ) ) , ( * ef3 ) ( lf3 ( make_list ( tmp [ 3 ] ) ) ) , arg2 ) ) ;
}
}
}
tmp [ 0 ] = ( * ef8 ) ( arg1 , ( constant5 ? constant5 : ( constant5 = lf4 ( make_list ( ( * ef26 ) ( ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 0 ] , ef35sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ;
if ( term_equal ( tmp [ 1 ] , ( constant10 ? constant10 : ( constant10 = ( * ef36 ) ( ) ) ) ) ) {
if ( check_sym ( tmp [ 2 ] , ef37sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef38sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 4 ] , ef39sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
if ( ! term_equal ( tmp [ 5 ] , ( * ef40 ) ( lf5 ( cons ( make_list ( make_char ( 34 ) ) , cons ( make_list ( make_char ( 67 ) ) , cons ( make_list ( make_char ( 72 ) ) , cons ( make_list ( make_char ( 65 ) ) , cons ( make_list ( make_char ( 82 ) ) , make_list ( make_char ( 34 ) ) ) ) ) ) ) ) ) ) ) {
tmp [ 6 ] = ( * ef8 ) ( arg1 , ( constant9 ? constant9 : ( constant9 = lf4 ( make_list ( ( * ef41 ) ( ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 6 ] , ef38sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
if ( check_sym ( tmp [ 7 ] , ef39sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
tmp [ 9 ] = ( constant11 ? constant11 : ( constant11 = ( * ef33 ) ( lf5 ( cons ( make_list ( make_char ( 34 ) ) , cons ( make_list ( make_char ( 123 ) ) , cons ( make_list ( make_char ( 115 ) ) , cons ( make_list ( make_char ( 111 ) ) , cons ( make_list ( make_char ( 114 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 40 ) ) , cons ( make_list ( make_char ( 92 ) ) , cons ( make_list ( make_char ( 34 ) ) , cons ( make_list ( make_char ( 67 ) ) , cons ( make_list ( make_char ( 72 ) ) , cons ( make_list ( make_char ( 65 ) ) , cons ( make_list ( make_char ( 82 ) ) , cons ( make_list ( make_char ( 92 ) ) , cons ( make_list ( make_char ( 34 ) ) , cons ( make_list ( make_char ( 41 ) ) , cons ( make_list ( make_char ( 125 ) ) , make_list ( make_char ( 34 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ;
tmp [ 10 ] = ( * ef28 ) ( tmp [ 9 ] , arg2 ) ;
if ( check_sym ( tmp [ 10 ] , ef20sym ) ) {
tmp [ 11 ] = arg_0 ( tmp [ 10 ] ) ;
tmp [ 12 ] = arg_1 ( tmp [ 10 ] ) ;
tmp [ 13 ] = ( * ef31 ) ( tmp [ 9 ] , ( constant7 ? constant7 : ( constant7 = ( * ef3 ) ( lf3 ( make_list ( ( * ef32 ) ( ( * ef33 ) ( lf5 ( cons ( make_list ( make_char ( 110 ) ) , cons ( make_list ( make_char ( 117 ) ) , cons ( make_list ( make_char ( 108 ) ) , make_list ( make_char ( 108 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ;
tmp [ 14 ] = ( * ef44 ) ( tmp [ 5 ] ) ;
tmp [ 15 ] = ( * ef45 ) ( tmp [ 14 ] , tmp [ 12 ] ) ;
if ( check_sym ( tmp [ 15 ] , ef20sym ) ) {
tmp [ 16 ] = arg_0 ( tmp [ 15 ] ) ;
tmp [ 17 ] = arg_1 ( tmp [ 15 ] ) ;
tmp [ 18 ] = ( * ef21 ) ( tmp [ 16 ] , ( constant7 ? constant7 : ( constant7 = ( * ef3 ) ( lf3 ( make_list ( ( * ef32 ) ( ( * ef33 ) ( lf5 ( cons ( make_list ( make_char ( 110 ) ) , cons ( make_list ( make_char ( 117 ) ) , cons ( make_list ( make_char ( 108 ) ) , make_list ( make_char ( 108 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ;
tmp [ 19 ] = ( * ef46 ) ( tmp [ 8 ] ) ;
FUNC_EXIT ( ( * ef2 ) ( lf2 ( cons ( make_list ( tmp [ 13 ] ) , make_list ( tmp [ 18 ] ) ) ) , ( * ef3 ) ( lf3 ( make_list ( ( * ef43 ) ( tmp [ 16 ] , lf3 ( make_list ( ( * ef43 ) ( tmp [ 9 ] , lf3 ( make_list ( tmp [ 19 ] ) ) ) ) ) ) ) ) ) , tmp [ 17 ] ) ) ;
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
FUNC_EXIT ( ( * ef2 ) ( lf2 ( make_list ( null ( ) ) ) , ( * ef3 ) ( lf3 ( make_list ( null ( ) ) ) ) , arg2 ) ) ;
FUNC_EXIT ( make_nf3 ( lf_AUX_AsFix2muASF_C7_1sym , arg0 , arg1 , arg2 ) ) ;
}
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}
ATerm lf5 ( ATerm arg0 ) {
CONS_ENTRY ( lf5sym , ATmakeAppl ( lf5sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf5sym , arg0 ) ) ;
}
ATerm lf4 ( ATerm arg0 ) {
CONS_ENTRY ( lf4sym , ATmakeAppl ( lf4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf4sym , arg0 ) ) ;
}

