#!/bin/sh
#
#    Meta-Environment - An environment for language prototyping.
#    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, The Netherlands. 
#
#    This program is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; either version 2 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program; if not, write to the Free Software
#    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
#
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
      echo "extern void init_$d();"
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

mk_init_all()
{
   echo "void init_all() {"
   for d in $lst
   do
      echo "   init_$d();"
   done
   echo "}"
}


mk_decls
mk_register_all
mk_resolve_all
mk_init_all

# eof 
