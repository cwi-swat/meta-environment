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

dnl Add --with-<pkg> switch. If this switch was not specified try to locate
dnl it by searching for one or more programs contained in that package.
dnl Abort configuration when no program could be found. The variable PKG contains the
dnl full path to the found program on return.
dnl
dnl Usage:
dnl    AC_PACKAGE_REQUIRE(package, programs, usage, actions_if_found )
dnl
dnl When --with-<pkg> was specified, the variable <PKG> will contain the
dnl value of the argument of the switch. If the switch was not specified,
its location is determined automatically using the <programs> argument.
dnl THis is a list of programs to search for to find the location of the
dnl package. If one such program is found, <PKG> is set to the full path to
dnl this program and <actions_if_found> is evaluated.
dnl
dnl Example
dnl    AC_PACKAGE_REQUIRE(wish, wish8.0 wish8.1 wish,
dnl                             [ --with-wish   location of wish program],)
dnl
dnl This would set the variable WISH to the location of the first program
dnl found or to the program as specified with the --with-wish switch.
AC_DEFUN(AC_PACKAGE_REQUIRE,
[
   dnl Add configuration switch
   AC_ARG_WITH($1, [$3],
      dnl switch was specified
      translit($1,`a-z',`A-Z')=${withval},
      dnl If switch not specified, try to find the program automatically
      [
         AC_PATH_PROGS(translit($1,`a-z',`A-Z'),$2,
         [
            dnl Not found; abort configuration
            AC_ERROR(Required \"$1\" program not found.)
         ])
         dnl Program found; evaluate <actions_of_found>
         $4
      ])
   AC_SUBST(translit($1,`a-z',`A-Z'))
])
