#include  "asc-support.h"
static Symbol lf_AUX_TermAsFix2muASF4_1sym ;
static ATerm lf_AUX_TermAsFix2muASF4_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef11sym ;
static funcptr ef11 ;
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
static Symbol ef43sym ;
static funcptr ef43 ;
static Symbol ef34sym ;
static funcptr ef34 ;
static Symbol ef5sym ;
static funcptr ef5 ;
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
static Symbol ef9sym ;
static funcptr ef9 ;
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
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
void register_AUX_TermAsFix2muASF4 ( ) {
lf_AUX_TermAsFix2muASF4_1sym = ATmakeSymbol ( "prod(id(\"TermAsFix2muASF\"),w(\"\"),[ql(\"term2muasf\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_TermAsFix2muASF4_1sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"AFun\"),ql(\".\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf5sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf5sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"FuncDef\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
register_prod ( ATparse ( "prod(id(\"TermAsFix2muASF\"),w(\"\"),[ql(\"term2muasf\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)" ) , lf_AUX_TermAsFix2muASF4_1 , lf_AUX_TermAsFix2muASF4_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"FuncDef\"),ql(\";\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"AFun\"),ql(\".\"))" ) , lf4 , lf4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf5 , lf5sym ) ;
}
void resolve_AUX_TermAsFix2muASF4 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-var-term\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-var-term\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[ql(\"avar2muvar\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[ql(\"avar2muvar\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFix2muASF\"),w(\"\"),[ql(\"term-args2muasf\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFix2muASF\"),w(\"\"),[ql(\"term-args2muasf\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-appl-term\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-appl-term\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\".\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\".\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"prod\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"prod\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"is-bracket-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"is-bracket-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"args\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"args\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"make-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"make-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"cffunc2id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"cffunc2id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef17 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"attrs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef17sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"attrs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef18 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix2Sign\"),w(\"\"),[l(\"attrs2terms\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef18sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix2Sign\"),w(\"\"),[l(\"attrs2terms\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef19 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"nt-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)" ) ) ;
ef19sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"nt-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)" ) ) ;
ef20 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)" ) ) ;
ef20sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)" ) ) ;
ef21 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Signature-Ops\"),w(\"\"),[l(\"make-external-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) ) ;
ef21sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Signature-Ops\"),w(\"\"),[l(\"make-external-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) ) ;
ef22 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Signature-Ops\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef22sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Signature-Ops\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef23 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)" ) ) ;
ef23sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)" ) ) ;
ef24 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"make-list-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef24sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"make-list-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef25 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-list-term\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef25sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-list-term\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef26 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"sym\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef26sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"sym\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef27 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"iter2id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef27sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"iter2id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef28 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"ntl-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)" ) ) ;
ef28sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"ntl-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)" ) ) ;
ef29 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"elems\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef29sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"elems\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef30 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFix2muASF\"),w(\"\"),[ql(\"term-listargs2muasf\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef30sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFix2muASF\"),w(\"\"),[ql(\"term-listargs2muasf\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef31 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Signature-Ops\"),w(\"\"),[l(\"make-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) ) ;
ef31sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Signature-Ops\"),w(\"\"),[l(\"make-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) ) ;
ef32 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef32sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef33 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef33sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef34 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-lex-term\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef34sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-lex-term\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
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
ef42 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"qlit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef42sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"qlit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef43 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef43sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef44 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"make-lex-cons-func\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef44sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"make-lex-cons-func\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef45 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"nt-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)" ) ) ;
ef45sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"nt-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)" ) ) ;
ef46 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"lit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef46sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"lit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
static ATerm constant3 = NULL ;
static ATerm constant4 = NULL ;
void init_AUX_TermAsFix2muASF4 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
ATprotect ( & constant3 ) ;
ATprotect ( & constant4 ) ;
}
ATerm lf_AUX_TermAsFix2muASF4_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 25 ] ;
FUNC_ENTRY ( lf_AUX_TermAsFix2muASF4_1sym , ATmakeAppl ( lf_AUX_TermAsFix2muASF4_1sym , arg0 , arg1 ) ) ;
( tmp [ 0 ] = ( * ef5 ) ( ) ) ;
if ( term_equal ( ( * ef4 ) ( arg0 ) , tmp [ 0 ] ) ) {
( tmp [ 1 ] = ( * ef6 ) ( arg0 ) ) ;
FUNC_EXIT ( ( * ef1 ) ( lf2 ( make_list ( null ( ) ) ) , ( * ef2 ) ( lf3 ( make_list ( ( * ef3 ) ( tmp [ 1 ] ) ) ) ) , arg1 ) ) ;
}
( tmp [ 1 ] = ( * ef8 ) ( arg0 ) ) ;
if ( term_equal ( tmp [ 1 ] , tmp [ 0 ] ) ) {
( tmp [ 2 ] = ( * ef9 ) ( arg0 , lf4 ( make_list ( ( * ef10 ) ( ) ) ) ) ) ;
( tmp [ 3 ] = ( * ef11 ) ( tmp [ 2 ] ) ) ;
if ( term_equal ( tmp [ 3 ] , ( constant0 ? constant0 : ( constant0 = ( * ef15 ) ( ) ) ) ) ) {
( tmp [ 4 ] = ( * ef16 ) ( tmp [ 2 ] ) ) ;
( tmp [ 5 ] = ( * ef9 ) ( tmp [ 2 ] , lf4 ( make_list ( ( * ef17 ) ( ) ) ) ) ) ;
( tmp [ 6 ] = ( * ef18 ) ( tmp [ 5 ] ) ) ;
if ( check_sym ( tmp [ 6 ] , ef2sym ) ) {
( tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ) ;
if ( check_sym ( tmp [ 7 ] , lf3sym ) ) {
( tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ) ;
( tmp [ 9 ] = ( * ef19 ) ( tmp [ 4 ] , ( * ef2 ) ( lf3 ( make_list ( tmp [ 8 ] ) ) ) , arg1 ) ) ;
if ( check_sym ( tmp [ 9 ] , ef20sym ) ) {
( tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ) ;
( tmp [ 11 ] = arg_1 ( tmp [ 9 ] ) ) ;
( tmp [ 12 ] = ( * ef9 ) ( arg0 , lf4 ( make_list ( ( * ef12 ) ( ) ) ) ) ) ;
if ( check_sym ( tmp [ 12 ] , ef13sym ) ) {
( tmp [ 13 ] = arg_0 ( tmp [ 12 ] ) ) ;
( tmp [ 14 ] = ( * ef7 ) ( tmp [ 13 ] , tmp [ 11 ] ) ) ;
if ( check_sym ( tmp [ 14 ] , ef1sym ) ) {
( tmp [ 15 ] = arg_0 ( tmp [ 14 ] ) ) ;
( tmp [ 16 ] = arg_1 ( tmp [ 14 ] ) ) ;
( tmp [ 17 ] = arg_2 ( tmp [ 14 ] ) ) ;
if ( check_sym ( tmp [ 15 ] , lf2sym ) ) {
( tmp [ 18 ] = arg_0 ( tmp [ 15 ] ) ) ;
if ( check_sym ( tmp [ 16 ] , ef2sym ) ) {
( tmp [ 19 ] = arg_0 ( tmp [ 16 ] ) ) ;
if ( check_sym ( tmp [ 19 ] , lf3sym ) ) {
( tmp [ 20 ] = arg_0 ( tmp [ 19 ] ) ) ;
( tmp [ 21 ] = ( * ef21 ) ( tmp [ 10 ] , ( * ef2 ) ( lf3 ( make_list ( tmp [ 20 ] ) ) ) ) ) ;
( tmp [ 22 ] = ( * ef22 ) ( ( * ef23 ) ( lf2 ( make_list ( tmp [ 21 ] ) ) ) , ( * ef23 ) ( lf2 ( make_list ( tmp [ 18 ] ) ) ) ) ) ;
if ( check_sym ( tmp [ 22 ] , ef23sym ) ) {
( tmp [ 23 ] = arg_0 ( tmp [ 22 ] ) ) ;
if ( check_sym ( tmp [ 23 ] , lf2sym ) ) {
( tmp [ 24 ] = arg_0 ( tmp [ 23 ] ) ) ;
FUNC_EXIT ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 24 ] ) ) , ( * ef2 ) ( lf3 ( make_list ( ( * ef14 ) ( tmp [ 10 ] , lf3 ( make_list ( tmp [ 20 ] ) ) ) ) ) ) , tmp [ 17 ] ) ) ;
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
if ( term_equal ( tmp [ 3 ] , ( constant1 ? constant1 : ( constant1 = ( * ef5 ) ( ) ) ) ) ) {
( tmp [ 4 ] = ( * ef9 ) ( arg0 , lf4 ( make_list ( ( * ef12 ) ( ) ) ) ) ) ;
if ( check_sym ( tmp [ 4 ] , ef13sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
FUNC_EXIT ( ( * ef7 ) ( tmp [ 5 ] , arg1 ) ) ;
}
}
}
if ( term_equal ( ( * ef25 ) ( arg0 ) , tmp [ 0 ] ) ) {
( tmp [ 2 ] = ( * ef9 ) ( arg0 , lf4 ( make_list ( ( * ef26 ) ( ) ) ) ) ) ;
( tmp [ 3 ] = ( * ef27 ) ( tmp [ 2 ] ) ) ;
( tmp [ 4 ] = ( * ef28 ) ( tmp [ 3 ] , arg1 ) ) ;
if ( check_sym ( tmp [ 4 ] , ef20sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
( tmp [ 6 ] = arg_1 ( tmp [ 4 ] ) ) ;
( tmp [ 7 ] = ( * ef9 ) ( arg0 , lf4 ( make_list ( ( * ef29 ) ( ) ) ) ) ) ;
if ( check_sym ( tmp [ 7 ] , ef13sym ) ) {
( tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ) ;
( tmp [ 9 ] = ( * ef30 ) ( tmp [ 8 ] , tmp [ 6 ] ) ) ;
if ( check_sym ( tmp [ 9 ] , ef1sym ) ) {
( tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ) ;
( tmp [ 11 ] = arg_1 ( tmp [ 9 ] ) ) ;
( tmp [ 12 ] = arg_2 ( tmp [ 9 ] ) ) ;
if ( check_sym ( tmp [ 10 ] , lf2sym ) ) {
( tmp [ 13 ] = arg_0 ( tmp [ 10 ] ) ) ;
if ( check_sym ( tmp [ 11 ] , ef2sym ) ) {
( tmp [ 14 ] = arg_0 ( tmp [ 11 ] ) ) ;
if ( check_sym ( tmp [ 14 ] , lf3sym ) ) {
( tmp [ 15 ] = arg_0 ( tmp [ 14 ] ) ) ;
( tmp [ 16 ] = ( * ef31 ) ( tmp [ 3 ] , ( * ef2 ) ( lf3 ( make_list ( ( * ef32 ) ( ( * ef33 ) ( lf5 ( ( ATerm ) ATmakeList ( 4 , char_table [ 110 ] , char_table [ 117 ] , char_table [ 108 ] , char_table [ 108 ] ) ) ) ) ) ) ) ) ) ;
( tmp [ 17 ] = ( * ef22 ) ( ( * ef23 ) ( lf2 ( make_list ( tmp [ 16 ] ) ) ) , ( * ef23 ) ( lf2 ( make_list ( tmp [ 13 ] ) ) ) ) ) ;
if ( check_sym ( tmp [ 17 ] , ef23sym ) ) {
( tmp [ 18 ] = arg_0 ( tmp [ 17 ] ) ) ;
if ( check_sym ( tmp [ 18 ] , lf2sym ) ) {
( tmp [ 19 ] = arg_0 ( tmp [ 18 ] ) ) ;
FUNC_EXIT ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 19 ] ) ) , ( * ef2 ) ( lf3 ( make_list ( ( * ef24 ) ( tmp [ 3 ] , lf3 ( make_list ( tmp [ 15 ] ) ) ) ) ) ) , tmp [ 12 ] ) ) ;
}
}
}
}
}
}
}
}
}
( tmp [ 2 ] = ( * ef34 ) ( arg0 ) ) ;
if ( term_equal ( tmp [ 2 ] , tmp [ 0 ] ) ) {
( tmp [ 3 ] = ( * ef9 ) ( arg0 , lf4 ( make_list ( ( * ef26 ) ( ) ) ) ) ) ;
if ( check_sym ( tmp [ 3 ] , ef35sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ) ;
( tmp [ 5 ] = arg_1 ( tmp [ 3 ] ) ) ;
if ( term_equal ( tmp [ 4 ] , ( constant2 ? constant2 : ( constant2 = ( * ef36 ) ( ) ) ) ) ) {
if ( check_sym ( tmp [ 5 ] , ef37sym ) ) {
( tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ) ;
if ( check_sym ( tmp [ 6 ] , ef38sym ) ) {
( tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ) ;
if ( check_sym ( tmp [ 7 ] , ef39sym ) ) {
( tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ) ;
if ( ! term_equal ( tmp [ 8 ] , ( * ef40 ) ( lf5 ( cons ( make_list ( make_char ( 34 ) ) , cons ( make_list ( make_char ( 67 ) ) , cons ( make_list ( make_char ( 72 ) ) , cons ( make_list ( make_char ( 65 ) ) , cons ( make_list ( make_char ( 82 ) ) , make_list ( make_char ( 34 ) ) ) ) ) ) ) ) ) ) ) {
( tmp [ 9 ] = ( * ef9 ) ( arg0 , lf4 ( make_list ( ( * ef41 ) ( ) ) ) ) ) ;
if ( check_sym ( tmp [ 9 ] , ef38sym ) ) {
( tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ) ;
if ( check_sym ( tmp [ 10 ] , ef39sym ) ) {
( tmp [ 11 ] = arg_0 ( tmp [ 10 ] ) ) ;
( tmp [ 12 ] = ( * ef33 ) ( lf5 ( ( ATerm ) ATmakeList ( 18 , char_table [ 34 ] , char_table [ 123 ] , char_table [ 115 ] , char_table [ 111 ] , char_table [ 114 ] , char_table [ 116 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 67 ] , char_table [ 72 ] , char_table [ 65 ] , char_table [ 82 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 125 ] , char_table [ 34 ] ) ) ) ) ;
( tmp [ 13 ] = ( * ef28 ) ( tmp [ 12 ] , arg1 ) ) ;
if ( check_sym ( tmp [ 13 ] , ef20sym ) ) {
( tmp [ 14 ] = arg_0 ( tmp [ 13 ] ) ) ;
( tmp [ 15 ] = arg_1 ( tmp [ 13 ] ) ) ;
( tmp [ 16 ] = ( * ef31 ) ( tmp [ 12 ] , ( * ef2 ) ( lf3 ( make_list ( ( * ef32 ) ( ( * ef33 ) ( lf5 ( ( ATerm ) ATmakeList ( 4 , char_table [ 110 ] , char_table [ 117 ] , char_table [ 108 ] , char_table [ 108 ] ) ) ) ) ) ) ) ) ) ;
( tmp [ 17 ] = ( * ef44 ) ( tmp [ 8 ] ) ) ;
( tmp [ 18 ] = ( * ef45 ) ( tmp [ 17 ] , tmp [ 15 ] ) ) ;
if ( check_sym ( tmp [ 18 ] , ef20sym ) ) {
( tmp [ 19 ] = arg_0 ( tmp [ 18 ] ) ) ;
( tmp [ 20 ] = arg_1 ( tmp [ 18 ] ) ) ;
( tmp [ 21 ] = ( * ef21 ) ( tmp [ 19 ] , ( * ef2 ) ( lf3 ( make_list ( ( * ef32 ) ( ( * ef33 ) ( lf5 ( ( ATerm ) ATmakeList ( 4 , char_table [ 110 ] , char_table [ 117 ] , char_table [ 108 ] , char_table [ 108 ] ) ) ) ) ) ) ) ) ) ;
( tmp [ 22 ] = ( * ef46 ) ( tmp [ 11 ] ) ) ;
FUNC_EXIT ( ( * ef1 ) ( lf2 ( cons ( make_list ( tmp [ 16 ] ) , make_list ( tmp [ 21 ] ) ) ) , ( * ef2 ) ( lf3 ( make_list ( ( * ef43 ) ( tmp [ 19 ] , lf3 ( make_list ( ( * ef43 ) ( tmp [ 12 ] , lf3 ( make_list ( tmp [ 22 ] ) ) ) ) ) ) ) ) ) , tmp [ 20 ] ) ) ;
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
if ( term_equal ( ( * ef9 ) ( arg0 , ( constant3 ? constant3 : ( constant3 = lf4 ( make_list ( ( * ef26 ) ( ) ) ) ) ) ) , ( constant4 ? constant4 : ( constant4 = ( * ef35 ) ( ( * ef36 ) ( ) , ( * ef37 ) ( ( * ef38 ) ( ( * ef39 ) ( ( * ef40 ) ( lf5 ( ( ATerm ) ATmakeList ( 6 , char_table [ 34 ] , char_table [ 67 ] , char_table [ 72 ] , char_table [ 65 ] , char_table [ 82 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ) ) ) {
( tmp [ 3 ] = ( * ef9 ) ( arg0 , lf4 ( make_list ( ( * ef41 ) ( ) ) ) ) ) ;
if ( check_sym ( tmp [ 3 ] , ef38sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ) ;
if ( check_sym ( tmp [ 4 ] , ef39sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
( tmp [ 6 ] = ( * ef42 ) ( tmp [ 5 ] ) ) ;
FUNC_EXIT ( ( * ef1 ) ( lf2 ( make_list ( null ( ) ) ) , ( * ef2 ) ( lf3 ( make_list ( tmp [ 6 ] ) ) ) , arg1 ) ) ;
}
}
}
}
FUNC_EXIT ( ( * ef1 ) ( lf2 ( make_list ( null ( ) ) ) , ( * ef2 ) ( lf3 ( make_list ( null ( ) ) ) ) , arg1 ) ) ;
FUNC_EXIT ( make_nf2 ( lf_AUX_TermAsFix2muASF4_1sym , arg0 , arg1 ) ) ;
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

