/* The code for the reshuffling of the equations in a module.
 */

#include "module-db.h"


extern ATerm modules_db;
ATerm compile_db = NULL;
ATermList modules_to_process;
ATbool compiling = ATfalse;

ATerm top_module;
char *output_path = ".";

void initialize_output_path(ATerm name)
{
  top_module = name;
  if( getenv( "COMPILER_OUTPUT" ) != NULL )
     output_path = getenv( "COMPILER_OUTPUT" );
}

void change_compile_db(ATerm new_db)
{
  if(!ATisEqual(new_db, compile_db))
    compile_db = new_db;
}

int equal_term(ATerm term1,ATerm term2)
{
  char *text1, *text2;
  ATerm t1[9], t2[9];

  if(ATmatchTerm(term1,pattern_asfix_sort,&text1) &&
     ATmatchTerm(term2,pattern_asfix_sort,&text2))
    return ATisEqual(term1,term2);
  else if(ATmatchTerm(term1,pattern_asfix_l,&text1) &&
          ATmatchTerm(term2,pattern_asfix_l,&text2))
    return ATisEqual(term1,term2);
  else if(ATmatchTerm(term1,pattern_asfix_ql,&text1) &&
          ATmatchTerm(term2,pattern_asfix_ql,&text2))
    return ATisEqual(term1,term2);
  else if(ATmatchTerm(term1,pattern_asfix_iter,
                     &t1[0],&t1[1],&t1[2]) &&
          ATmatchTerm(term2,pattern_asfix_iter,
                     &t2[0],&t2[1],&t2[2]))
    return equal_term(t1[0],t2[0]) &&
           equal_term(t1[2],t2[2]);
  else if(ATmatchTerm(term1,pattern_asfix_itersep,
                     &t1[0],&t1[1],&t1[2],&t1[3],&t1[4],
                     &t1[5],&t1[6],&t1[7],&t1[8]) &&
          ATmatchTerm(term2,pattern_asfix_itersep,
                     &t2[0],&t2[1],&t2[2],&t2[3],&t2[4],
                     &t2[5],&t2[6],&t2[7],&t2[8]))
    return equal_term(t1[2],t2[2]) &&
           equal_term(t1[4],t2[4]) &&
           equal_term(t1[8],t2[8]);
  else return ATfalse;
}

int equal_args(ATermList args1,ATermList args2)
{
  ATerm arg1,arg2;
  ATbool equal;

  equal = ATtrue;
  while(equal && !ATisEmpty(args1) && !ATisEmpty(args2)) {
    arg1 = ATgetFirst(args1);
    arg2 = ATgetFirst(args2);
    if(!asfix_is_whitespace(arg1) && !asfix_is_whitespace(arg2)) {
      equal = equal_term(arg1,arg2);
    }
    args1 = ATgetNext(args1);
    args2 = ATgetNext(args2);
  }
  return equal && ATisEmpty(args1) && ATisEmpty(args2);
}

int equal_attrs(ATerm attrs1,ATerm attrs2)
{
  ATerm w1[2], w2[2], l1[2], l2[2];
  ATermList args1, args2;

  if(ATmatchTerm(attrs1,pattern_asfix_noattrs) &&
     ATmatchTerm(attrs2,pattern_asfix_noattrs))
    return ATtrue;
  else if(!ATmatchTerm(attrs1,pattern_asfix_noattrs) &&
          !ATmatchTerm(attrs2,pattern_asfix_noattrs)) {
    if(ATmatchTerm(attrs1, pattern_asfix_attrs,
                  &l1[0],&w1[0],&args1,&w1[1],&l1[1])) {
      if(ATmatchTerm(attrs2, pattern_asfix_attrs,
                    &l2[0],&w2[0],&args2,&w2[1],&l2[1]))
        return equal_args(args1,args2);
      else
        return ATfalse;
    }
    else
      return ATfalse;
  }
  else
    return ATfalse;
}

int equal_prod(ATerm prod1, ATerm prod2)
{
  ATerm mname1, lit1, sort1, w1[4], attrs1;
  ATerm mname2, lit2, sort2, w2[4], attrs2;
  ATermList args1, args2;

  if(ATmatchTerm(prod1, pattern_asfix_prod,
                &mname1,&w1[0],&args1,&w1[1],&lit1,&w1[2],
                &sort1,&w1[3],&attrs1)) {
    if(ATmatchTerm(prod2, pattern_asfix_prod,
                  &mname2,&w2[0],&args2,&w2[1],&lit2,&w2[2],
                  &sort2,&w2[3],&attrs2)) {
      if(ATisEqual(mname1,mname2) && equal_args(args1,args2) &&
         ATisEqual(sort1,sort2) && equal_attrs(attrs1,attrs2))
        return ATtrue;
    }
  }
  return ATfalse;
}

/* The function {\tt get_lex_funcs_for_sort} traverse a list
   of modules and looks for all lexical functions
   with the given sorts as result sort. */
ATermList get_lex_funcs_for_sort(ATerm sort, ATermList mods)
{
  ATerm lmod, amod, lexfunc, rsort;
  ATermList lexfuncs;
  ATermList functions = ATempty;

  while(!ATisEmpty(mods)) {
    lmod = ATgetFirst(mods);
    amod = GetValue(modules_db,lmod);
    lexfuncs = AFgetModuleLexfuncs(amod);
    lexfuncs = asfix_filter_layout(lexfuncs);
    while(!ATisEmpty(lexfuncs)) {
      lexfunc = ATgetFirst(lexfuncs);
      rsort = AFgetProdSort(lexfunc);
      if(equal_term(sort,rsort)) {
        if(!ATisEmpty(functions))
          functions = ATappend(functions,
                               ATreadFromString("w(\"\\n\")"));
        functions = ATappend(functions, lexfunc);
      }
      lexfuncs = ATgetNext(lexfuncs);
    }
    mods = ATgetNext(mods);
  }
  return functions;
}

/* The function {\tt get_equations_for_func} traverse a list
   of modules and looks for all equations with the given
   context-free function as outermost function symbol in the
   left-hand side. */
ATermList get_equations_for_func(ATerm func,ATermList mods)
{
  ATerm mod, amod, eq, lhs, ofs;
  ATermList eqs;
  ATermList equations = ATempty;

  while(!ATisEmpty(mods)) {
    mod = ATgetFirst(mods);
    amod = GetValue(modules_db,mod);
    eqs = (ATermList)asfix_get_module_eqs(amod);
    eqs = asfix_filter_layout(eqs);
    while(!ATisEmpty(eqs)) {
      eq = ATgetFirst(eqs);
      lhs = asfix_get_equ_lhs(eq);
      ofs = asfix_get_appl_prod(lhs);
      if(equal_prod(func,ofs)) {
        if(!ATisEmpty(equations))
          equations = ATappend(equations, ATreadFromString( "w(\"\\n\")"));
        equations = ATappend(equations, eq);
      }
      eqs = ATgetNext(eqs);
    }
    mods = ATgetNext(mods);
  };
  return equations;
}

void add_section(ATerm module, ATerm section)
{
  ATerm newmodule = GetValue(compile_db,module);
  ATermList sections = AFgetModuleSections(newmodule);
  if(!ATisEmpty(sections)) {
    sections = ATconcat(sections,
                        ATmakeList2(pattern_asfix_nlws,
                                    section));
    newmodule = AFputModuleSections(newmodule,sections);
  }
  else
    newmodule = AFputModuleSections(newmodule,ATmakeList1(section));
  change_compile_db(PutValue(compile_db,module,newmodule));
}

ATerm unique_new_name(ATerm name)
{
  char *text, *newtext;
  ATerm newname;
  int n = 1;

  if(ATmatchTerm(name,pattern_asfix_id,&text)) {
    newtext = malloc(strlen(text)+16);
    sprintf(newtext,"AUX-%s%d",text,n);
    newname = ATmakeTerm(pattern_asfix_id,newtext);
    while(GetValue(compile_db,newname)) {
      n++;
      sprintf(newtext,"AUX-%s%d",text,n);
      newname = ATmakeTerm(pattern_asfix_id,newtext);
    }
    free(newtext);
    return newname;
  }
  else {
    ATerror("illegal name %t\n", name);
    return NULL; /* silence the compiler */
  }
}

ATerm create_new_module(ATerm modname)
{
  ATerm newmodule = AFinitModule();
  ATerm newmodname = unique_new_name(modname);
ATfprintf(stderr,"Creating new module: %t\n",newmodname);
  newmodule = AFputModuleName(newmodule,newmodname);
  change_compile_db(PutValue(compile_db,newmodname,newmodule));
  return newmodname;
}

void add_equations(ATerm module, ATermList eqs)
{
  ATerm newmodule = GetValue(compile_db,module);
  newmodule = AFputModuleEqs(newmodule,eqs);
  change_compile_db(PutValue(compile_db,module,newmodule));
}

void write_asfix_file(int cid,ATerm modname)
{
  char *text, *fname;
  int len;
  FILE *output, *input;
  ATerm oldmod, element;
  ATbool write;

  ATerm amod = GetValue(compile_db,modname);

  if(ATmatchTerm(modname,pattern_asfix_id,&text)) {
    len = strlen(output_path) + 1 + strlen(text) + strlen(".asfix");
    fname = malloc(len + 1);
    if(!fname) 
      ATerror("Not enough memory\n");
    sprintf(fname, "%s/%s.asfix", output_path, text);
    /* Check whether it is necessary to generate new C code. */
    input = fopen(fname,"r");
    if(input) {
      oldmod = ATreadFromTextFile(input);
      write = !ATisEqual(oldmod,amod);
      fclose(input);
    }
    else
      write = ATtrue;
    if(write) {
      output = fopen(fname,"w");
      if(!output)
        ATfprintf(stderr,"Cannot open file %s\n",fname);
      else {   
        ATfprintf(output,"%t",amod);
        ATfprintf(output, "\n");
        fclose(output);
      }
      /* write full path name instead of only module name */
      ATfprintf(stderr,"Writing: %s\n", fname);
      element = ATmake("snd-event(generate-code(<term>,<term>))",
                       modname,amod);
      if(!compiling) {
        compiling = ATtrue;
        ATBwriteTerm(cid,element);
      }
      else
        modules_to_process = ATappend(modules_to_process,element);
    }
    free(fname);
  }
  else 
    ATerror("Illegal module name %t\n", modname);
}

/* This function uses the sorts to determine whether there are equations
 * for the lexical functions.
 */
void reshuffle_lexical_constructor_functions(int cid,
                                             ATerm modname, ATerm newmod,
                                             ATermList orgmods)
{
  ATerm prod, amod, sort, newsection, newsubsection, newmodname;
  ATermList sorts, funcs, eqs;

ATfprintf(stderr,"Reshuffling module per sort: %t\n", modname);
  amod = GetValue(modules_db,modname);
  sorts = AFgetModuleSorts(amod);
  sorts = asfix_filter_layout(sorts);
  while(!ATisEmpty(sorts)) {
    sort = ATgetFirst(sorts);
ATfprintf(stderr,"Reshuffling sort: %t\n",sort);
    funcs = get_lex_funcs_for_sort(sort,orgmods);
    if(!ATisEmpty(funcs)) {
      newsubsection = AFinitLexicalSyntaxSection();
      newsubsection = AFputSectionArgs(newsubsection,funcs);
      newsection = AFinitExportSection();
      newsection = AFputSectionArgs(newsection,
                                    ATmakeList1(newsubsection));
      prod = make_caller_prod(sort);
      eqs = get_equations_for_func(prod,orgmods);
      if(!ATisEmpty(eqs)) {
/* There are equations for the lexical constructor of sort SORT.
 * So, a new module has to be created containing these lexical functions
 * and the corresponding equations.
 */
        newmodname = create_new_module(modname);
        add_section(newmodname,newsection);
        add_equations(newmodname,eqs);
        write_asfix_file(cid,newmodname);
      }
      else
/* There are no equations for the lexical constructor of sort SORT.
 * So, this function is to be added to the module containing no
 * equations.
 */
        add_section(newmod,newsection);
    }
    sorts = ATgetNext(sorts);
  }
}

void reshuffle_modules(int cid,ATermList mods)
{
  ATerm mod, newmod, newmodname, oldamod, cffunc;
  ATermList cffuncs, eqs, orgmods;
  ATerm newsubsection, newsection;

  change_compile_db(CreateValueStore());
ATfprintf(stderr,"Reshuffling modules: %t\n",mods);
  orgmods = mods;
  while(!ATisEmpty(mods)) {
    mod = ATgetFirst(mods);
    newmod = create_new_module(mod);
    reshuffle_lexical_constructor_functions(cid,mod,newmod,orgmods);
ATfprintf(stderr,"reshuffle_per_sort finished\n");
    oldamod = GetValue(modules_db,mod);
    cffuncs = AFgetModuleCFfuncs(oldamod);
    cffuncs = asfix_filter_layout(cffuncs);
    while(!ATisEmpty(cffuncs)) {
      cffunc = ATgetFirst(cffuncs);
      newsubsection = AFinitContextFreeSyntaxSection();
      newsubsection = AFputSectionArgs(newsubsection,
                                       ATmakeList1(cffunc));
      newsection = AFinitExportSection();
      newsection = AFputSectionArgs(newsection,
                                    ATmakeList1(newsubsection));
      eqs = get_equations_for_func(cffunc,orgmods);
      if(!ATisEmpty(eqs)) {
        newmodname = create_new_module(mod);
        add_section(newmodname,newsection);
        add_equations(newmodname,eqs);
        write_asfix_file(cid,newmodname);
      }
      else {
        add_section(newmod,newsection);
      }
      cffuncs = ATgetNext(cffuncs);
    }
    write_asfix_file(cid,newmod);
    while(ATBpeekOne(cid))
      ATBhandleOne(cid);
    mods = ATgetNext(mods);
  }
  if(!compiling && ATisEmpty(modules_to_process))
    ATBwriteTerm(cid,ATmake("snd-event(done)"));
}

extern ATermList GetallKeys(ATermList compile_db);

void print_makefile(ATerm name)
{
  char *text, *mtext, *fname;
  int len;
  FILE *output;
  ATerm module;
  ATermList modules = GetallKeys((ATermList) compile_db);

  if(ATmatchTerm(name,pattern_asfix_id,&text)) {
    len = strlen(output_path) + 1 + strlen("Makefile-") + strlen(text);
    fname = malloc(len + 1);
    if(!fname) 
      ATerror("Not enough memory\n");
    sprintf(fname, "%s/Makefile-%s", output_path, text);
    /* Check whether it is necessary to generate new C code. */
    output = fopen(fname,"w");
    if(!output)
      ATfprintf(stderr,"Cannot open file %s\n",fname);
    else {   
      ATfprintf(output,"# Makefile for target \"%s\" automatically generated.\n",text);
      ATfprintf(output,"#\n\n");
      ATfprintf(output,"# DEBUG-LIBS:     libraries containing debugging information\n");
      ATfprintf(output,"# DEBUG-CC-FLAGS: compiler flags to store debugging information in object files\n");
      ATfprintf(output,"# DEBUG-LD-FLAGS: optional flags for linking with debugging information\n");
      ATfprintf(output,"# DEBUG-COMP:     compiler to use\n");
      ATfprintf(output,"DEBUG-LIBS     = -lsupport-dbg -lATB-dbg -lAsFix-dbg -lATerm-dbg\n");
      ATfprintf(output,"DEBUG-CC-FLAGS = -g -Wall -pedantic\n");
      ATfprintf(output,"DEBUG-LD-FLAGS =\n");
      ATfprintf(output,"DEBUG-COMP     = gcc\n\n");
      ATfprintf(output,"# PROFILE-LIBS:     libraries containing profile information\n");
      ATfprintf(output,"# PROFILE-CC-FLAGS: compiler flags to store profile information in object files\n");
      ATfprintf(output,"# PROFILE-LD-FLAGS: optional flags for linking profiled object code\n");
      ATfprintf(output,"# PROFILE-COMP:     compiler to use\n");
      ATfprintf(output,"PROFILE-LIBS     = -lsupport-prof -lATB-prof -lAsFix-prof -lATerm-prof\n");
      ATfprintf(output,"PROFILE-CC-FLAGS = -pg\n");
      ATfprintf(output,"PROFILE-LD-FLAGS = -pg\n");
      ATfprintf(output,"PROFILE-COMP     = gcc\n\n");
      ATfprintf(output,"# There should be no need to change anything below\n\n");
      ATfprintf(output,"prefix          = /home/gipe/petr\n");
      ATfprintf(output,"exec_prefix     = \n");
      ATfprintf(output,"bindir          = $(exec_prefix)/bin\n");
      ATfprintf(output,"libdir          = $(exec_prefix)/lib\n");
      ATfprintf(output,"includedir      = $(prefix)/include\n\n");
      ATfprintf(output,"SHELL           = /bin/sh\n");
      ATfprintf(output,"CC              = cc\n");
      ATfprintf(output,"CPP             = gcc -E\n");
      ATfprintf(output,"CPPFLAGS        = gcc -E $(XCPPFLAGS)\n");
      ATfprintf(output,"DEFS            =  -DHAVE_LIBDL=1  $(XDEFS)\n");
      ATfprintf(output,"INCLUDES        =  $(XINCLUDES)\n");
      ATfprintf(output,"LIBS            = -ldl  $(XLIBS)\n");
      ATfprintf(output,"SOCKLIBS        = -lsocket -lnsl\n\n");
      ATfprintf(output,"ATERM           = $(prefix)\n\n");
      ATfprintf(output,"XINCLUDES       = -I$(ATERM)/include -I$(includedir)\n");
      ATfprintf(output,"XLIBS           = -L$(prefix)/lib -L$(ATERM)/lib\\\n");
      ATfprintf(output,"                  $(VAR-LIBS) $(SOCKLIBS) $(GELLIBS)\n");
      ATfprintf(output,"VAR-LIBS        = -lsupport-cc -lATB-cc -lAsFix-cc -lATerm-cc\n");
      ATfprintf(output,"VAR-FLAGS       = -O $(XCFLAGS)\n\n");
      ATfprintf(output,"SRCS=\\\n");
      while (!ATisEmpty(modules)) {
        module = ATgetFirst(modules);
        if(ATmatchTerm(module,pattern_asfix_id,&mtext)) {
          ATfprintf(output,"    %s.c\\\n", mtext);
        }
        modules = ATgetNext(modules);
      }
      ATfprintf(output,"    init.c\n\n");
      ATfprintf(output,"OBJS=$(SRCS:.c=.o)\n\n");
      ATfprintf(output,"# Make rules\n");
      ATfprintf(output,".c.o:\n");
      ATfprintf(output,"\t$(CC) $(CFLAGS) $(VAR-FLAGS) $(DEFS) $(INCLUDES) -c $< -o $@\n\n");
      ATfprintf(output,"%s : $(OBJS)\n",text);
      ATfprintf(output,"\t$(CC) $(LDFLAGS) -o %s $(OBJS) $(LIBDIR) $(LIBS)\n\n",text);
      ATfprintf(output,"debug:\n");
      ATfprintf(output,"\t$(MAKE) -f Makefile-%s %s-dbg CC=\"$(DEBUG-COMP)\" VAR-FLAGS=\"$(DEBUG-FLAGS)\" VAR-LIBS=\"$(DEBUG-LIBS)\"\n\n",text,text);
      ATfprintf(output,"profile:\n");
      ATfprintf(output,"\t$(MAKE) -f Makefile-%s %s-prof CC=\"$(PROFILE-COMP)\" VAR-FLAGS=\"$(PROFILE-CC-FLAGS)\" VAR-LIBS=\"$(PROFILE-LIBS)\"\n\n",text,text);
      ATfprintf(output,"%s-dbg: $(OBJS)\n",text);
      ATfprintf(output,"\t$(CC) $(LDFLAGS) $(DEBUG-LD-FLAGS) -o %s-dbg $(OBJS) $(LIBDIR) $(LIBS)\n\n",text);
      ATfprintf(output,"%s-prof: $(OBJS)\n",text);
      ATfprintf(output,"\t$(CC) $(LDFLAGS) $(PROFILE-LD-FLAGS) -o %s-prof $(OBJS) $(LIBDIR) $(LIBS)\n\n",text);
      ATfprintf(output,"init.c:\n");
      ATfprintf(output,"\t(echo \"/*GENERATED AUTOMATICALLY, DO NOT MODIFY */\" ;\\\n");
      ATfprintf(output,"\tNAMES=`ls AUX*.c | sed 's/.c$$//g;s/-/_/g'`; export NAMES ;\\\n");
      ATfprintf(output,"\tfor file in $${NAMES}; do \\\n");
      ATfprintf(output,"\techo \"extern void register_$$file();\" ;\\\n");
      ATfprintf(output,"\techo \"extern void resolve_$$file();\"  ;\\\n");
      ATfprintf(output,"\techo \"extern void init_$$file();\"  ;\\\n");
      ATfprintf(output,"\tdone ;\\\n");
      ATfprintf(output,"\techo \"void register_all() {\" ;\\\n");
      ATfprintf(output,"\tfor file in $${NAMES}; do \\\n");
      ATfprintf(output,"\techo \"  register_$$file();\" ;\\\n");
      ATfprintf(output,"\tdone ;\\\n");
      ATfprintf(output,"\techo \"}\" ;\\\n");
      ATfprintf(output,"\techo \"void resolve_all() {\" ;\\\n");
      ATfprintf(output,"\tfor file in $${NAMES}; do \\\n");
      ATfprintf(output,"\techo \"  resolve_$$file();\"  ;\\\n");
      ATfprintf(output,"\tdone ;\\\n");
      ATfprintf(output,"\techo \"}\" ;\\\n");
      ATfprintf(output,"\techo \"void init_all() {\" ;\\\n");
      ATfprintf(output,"\tfor file in $${NAMES}; do \\\n");
      ATfprintf(output,"\techo \"  init_$$file();\"  ;\\\n");
      ATfprintf(output,"\tdone ;\\\n");
      ATfprintf(output,"\techo \"}\" ) > $@\n\n");
      ATfprintf(output,"clean:\n");
      ATfprintf(output,"\t$(RM) $(OBJS) init.c %s %s-db %s-prof\n",text,text,text);
      ATfprintf(output, "\n");
      fclose(output);
    }
    /* write full path name instead of only module name */
    ATfprintf(stderr,"Writing: %s\n", fname);
  }
  else
    ATerror("illegal name %t\n", name);
}

ATermList get_imported_modules(ATerm name);
ATbool complete_specification(ATerm module);

void process_next_module(int cid)
{
  ATerm event;

ATfprintf(stderr,"process_next_module entered\n");
  if(!ATisEmpty(modules_to_process)) {
    compiling = ATtrue;
    event = ATgetFirst(modules_to_process);
    modules_to_process = ATgetNext(modules_to_process);
    ATBwriteTerm(cid,event);
  }
  else {
    print_makefile(top_module);
    ATBwriteTerm(cid,ATmake("snd-event(done)"));
  }
}

void rec_ack_event(int cid, ATerm term)
{
  ATerm name, mod;

  if(ATmatch(term,"generate-code(<term>,<term>)",&name,&mod)) {
    compiling = ATfalse;
    process_next_module(cid);
  }
  else if(ATmatch(term,"done")) {
    compiling = ATfalse;
    ATfprintf(stderr,"Compilation completed\n");
  }
  else
    exit(1);
}

void compile_module(int cid, ATerm mod)
{
  ATermList imports;

  if(complete_specification(mod)) {
    ATfprintf(stderr,"Reshuffling ... \n");
    initialize_output_path(mod);
    modules_to_process = ATempty;
    imports = get_imported_modules(mod);
    reshuffle_modules(cid,imports);
  }
  else {
    ATfprintf(stderr,"Specification is incomplete and can not be compiled!\n");
    ATBwriteTerm(cid,ATmake("snd-event(done)"));
  }
}
