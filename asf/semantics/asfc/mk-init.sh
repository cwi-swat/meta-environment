#!/bin
#
#  Date: 18/2/1998
# Athor: Merijn de jonge
#
# Shell script that writes to stdout function definition of register_all
# and resolve_all.
#
# First a list is constructed based on all files AUC*.c in current
# directory. For each matching file the extension is removed and '-' is
# translated to '_'. Next we write to stdout function declarations of the
# form "extern void register_f(); and extern void resolve_f(); Finally we
# create the functions register_all (that calls register_f() for each
# element of the list) and the function resolve_all (that calls resolve_f()
# for each element in the list).
#
# Output of this file should be saved in init.c (or some other file). This
# file should be compiled and linked with the other modules of the
# compiled specification.

lst=`ls AUX*.c | sed 's/.c$//g;s/-/_/g'`

mk_decls()
{
   for d in $lst
   do
      echo "extern void register_$d();"
      echo "extern void resolve_$d();"
   done
}

mk_register_all()
{
   echo "void register_all() {"
   for d in $lst
   do
      echo "   register_$d();"
   done
   echo "}"
}

mk_resolve_all()
{
   echo "void resolve_all() {"
   for d in $lst
   do
      echo "   resolve_$d();"
   done
   echo "}"
}

mk_decls
mk_register_all
mk_resolve_all

# eof 
