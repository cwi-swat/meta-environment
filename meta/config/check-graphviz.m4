dnl Copyright (C) 2000 Merijn de Jonge <mdejonge@cwi.nl>
dnl
dnl This program is free software; you can redistribute it and/or modify
dnl it under the terms of the GNU General Public License as published by
dnl the Free Software Foundation; either version 2, or (at your option)
dnl any later version.
dnl
dnl This program is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl GNU General Public License for more details.
dnl
dnl You should have received a copy of the GNU General Public License
dnl along with this program; if not, write to the Free Software
dnl Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
dnl 02111-1307, USA.

dnl $Id$

dnl Author Merijn de Jonge (mdejonge@cwi.nl)

dnl Check for version of graphviz. GRAPHVIZ variable should be defined.

AC_DEFUN(META_GRAPHVIZ_VERSION,
[
   dnl Extract dot version in the following steps:
   dnl 1) get full version: "dot version gviz1.5.1 (09-29-99)"
   dnl 2) extract version part: "gviz1.5.1"
   dnl 3) remove gviz prefix: "1.5.1"

   dot_version_string=`${GRAPHVIZ}/bin/dot -V 2>&1`
   if test $? -ne 0; then
      AC_ERROR( [ No dot program available or other error.] )
   fi

   dot_version_string=`echo "$dot_version_string" | cut -f3 -d' '`
   dot_version_number=`echo "$dot_version_string" | sed 's/gviz//g'`

   case $dot_version_number in
      0.* | 1.[[0-4]]* )
         AC_ERROR( [ dot version >= 1.5 required (found $dot_version_string), check your graphviz configuration. ] )
         ;;
   esac
])

dnl Check for graphviz package and test for corrrect verion >= 1.5
AC_DEFUN(META_CHECK_GRAPHVIZ,
[
   AC_PACKAGE_REQUIRE(graphviz, 
                      dot, 
                      [  --with-graphviz=DIR     graphviz package is in DIR],
                      GRAPHVIZ=`dirname \`dirname ${GRAPHVIZ}\`` )

   META_GRAPHVIZ_VERSION

   dnl Try to find tcldot library
   f=`echo ${GRAPHVIZ}/lib/Tcldot/Tcldot.so.*`
   if test "a$f" = 'a${GRAPHVIZ}/lib/Tcldot/Tcldot.so.*' ; then
      AC_ERROR( "No Tcldot library found; check your graphviz configuration." )
   fi
])
