dnl aclocal.m4 generated automatically by aclocal 1.4-p5

dnl Copyright (C) 1994, 1995-8, 1999, 2001 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl This program is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY, to the extent permitted by law; without
dnl even the implied warranty of MERCHANTABILITY or FITNESS FOR A
dnl PARTICULAR PURPOSE.

# Do all the work for Automake.  This macro actually does too much --
# some checks are only needed if your package does certain things.
# But this isn't really a big deal.

# serial 1

dnl Usage:
dnl AM_INIT_AUTOMAKE(package,version, [no-define])

AC_DEFUN([AM_INIT_AUTOMAKE],
[AC_REQUIRE([AC_PROG_INSTALL])
PACKAGE=[$1]
AC_SUBST(PACKAGE)
VERSION=[$2]
AC_SUBST(VERSION)
dnl test to see if srcdir already configured
if test "`cd $srcdir && pwd`" != "`pwd`" && test -f $srcdir/config.status; then
  AC_MSG_ERROR([source directory already configured; run "make distclean" there first])
fi
ifelse([$3],,
AC_DEFINE_UNQUOTED(PACKAGE, "$PACKAGE", [Name of package])
AC_DEFINE_UNQUOTED(VERSION, "$VERSION", [Version number of package]))
AC_REQUIRE([AM_SANITY_CHECK])
AC_REQUIRE([AC_ARG_PROGRAM])
dnl FIXME This is truly gross.
missing_dir=`cd $ac_aux_dir && pwd`
AM_MISSING_PROG(ACLOCAL, aclocal, $missing_dir)
AM_MISSING_PROG(AUTOCONF, autoconf, $missing_dir)
AM_MISSING_PROG(AUTOMAKE, automake, $missing_dir)
AM_MISSING_PROG(AUTOHEADER, autoheader, $missing_dir)
AM_MISSING_PROG(MAKEINFO, makeinfo, $missing_dir)
AC_REQUIRE([AC_PROG_MAKE_SET])])

#
# Check to make sure that the build environment is sane.
#

AC_DEFUN([AM_SANITY_CHECK],
[AC_MSG_CHECKING([whether build environment is sane])
# Just in case
sleep 1
echo timestamp > conftestfile
# Do `set' in a subshell so we don't clobber the current shell's
# arguments.  Must try -L first in case configure is actually a
# symlink; some systems play weird games with the mod time of symlinks
# (eg FreeBSD returns the mod time of the symlink's containing
# directory).
if (
   set X `ls -Lt $srcdir/configure conftestfile 2> /dev/null`
   if test "[$]*" = "X"; then
      # -L didn't work.
      set X `ls -t $srcdir/configure conftestfile`
   fi
   if test "[$]*" != "X $srcdir/configure conftestfile" \
      && test "[$]*" != "X conftestfile $srcdir/configure"; then

      # If neither matched, then we have a broken ls.  This can happen
      # if, for instance, CONFIG_SHELL is bash and it inherits a
      # broken ls alias from the environment.  This has actually
      # happened.  Such a system could not be considered "sane".
      AC_MSG_ERROR([ls -t appears to fail.  Make sure there is not a broken
alias in your environment])
   fi

   test "[$]2" = conftestfile
   )
then
   # Ok.
   :
else
   AC_MSG_ERROR([newly created file is older than distributed files!
Check your system clock])
fi
rm -f conftest*
AC_MSG_RESULT(yes)])

dnl AM_MISSING_PROG(NAME, PROGRAM, DIRECTORY)
dnl The program must properly implement --version.
AC_DEFUN([AM_MISSING_PROG],
[AC_MSG_CHECKING(for working $2)
# Run test in a subshell; some versions of sh will print an error if
# an executable is not found, even if stderr is redirected.
# Redirect stdin to placate older versions of autoconf.  Sigh.
if ($2 --version) < /dev/null > /dev/null 2>&1; then
   $1=$2
   AC_MSG_RESULT(found)
else
   $1="$3/missing $2"
   AC_MSG_RESULT(missing)
fi
AC_SUBST($1)])

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

dnl AC_PACKAGE_REQUIRE
dnl Add --with-<pkg> switch. If this switch was not specified try to locate
dnl it by searching for one or more programs contained in that package. 
dnl Abort configuration when no program could be found. The variable PKG
dnl contains the dnl full path to the found program on return.
dnl
dnl Usage:
dnl    AC_PACKAGE_REQUIRE(package, programs, usage )
dnl
dnl When --with-<pkg> was specified, the variable <PKG> will contain the
dnl value of the argument of the switch. If the switch was not specified,
dnl its location is determined automatically using the <programs> argument.
dnl This is a list of programs to search for to find the location of the
dnl package. If one such program is found, <PKG> is set to
dnl <path_to_program>/../..
dnl
dnl Example
dnl    AC_PACKAGE_REQUIRE(wish, wish8.0 wish8.1 wish,
dnl                             [ --with-wish   location of wish program])
dnl
dnl This would set the variable WISH to the location of the first program
dnl found or to the program as specified with the --with-wish switch.
AC_DEFUN(AC_PACKAGE_REQUIRE,
[AC_PACKAGE_OPTIONAL([$1],[$2],[$3],[AC_PACKAGE_NOT_FOUND([$1])])
])

dnl AC_PACKAGE_OPTIONAL
dnl Similar to AC_PACKAGE_REQUIRE but in case the package could not be
dnl found, don't abort configuration proces but instead perform the actions
dnl as specified in actions-of-not-found.
dnl
dnl Usage:
dnl    AC_PACKAGE_OPTIONAL(package, programs, usage, actions-if-not-found )
AC_DEFUN(AC_PACKAGE_OPTIONAL,
[AC_PACKAGE_REQUIRE1([$1],[$2],[$3],
    dnl Program found; assign result to upper($1)
    [translit($1,-a-z,_A-Z)=`dirname \`dirname $translit($1,a-z-,A-Z_)\``],
    dnl else perforom actions in <actions-of-not-found>.
    [$4])
])

dnl AC_PROGRAM_REQUIRE
dnl Add --with-<pkg> switch. If this switch was not specified try to locate
dnl it by searching for one or more programs contained in that package.
dnl Abort configuration when no program could be found. The variable PKG contains the
dnl full path to the found program on return.
dnl
dnl Usage:
dnl    AC_PACKAGE_REQUIRE(package, programs, usage )
dnl
dnl When --with-<pkg> was specified, the variable <PKG> will contain the
dnl value of the argument of the switch. If the switch was not specified,
dnl its location is determined automatically using the <programs> argument.
dnl This is a list of programs to search for to find the location of the
dnl package. If one such program is found, <PKG> is set to <path_to_program>
dnl
dnl Example
dnl    AC_PROGRAM_REQUIRE(wish, wish8.0 wish8.1 wish,
dnl                             [ --with-wish   location of wish program])
dnl
dnl This would set the variable WISH to the location of the first program
dnl found or to the program as specified with the --with-wish switch.
AC_DEFUN(AC_PROGRAM_REQUIRE,
   [AC_PACKAGE_REQUIRE1([$1],[$2],[$3],,AC_PACKAGE_NOT_FOUND([$1]))])

dnl AC_PACKAGE_REQUIRE1 
dnl Implementation for AC_PACKAGE_OPTIONAL, AC_PACKAGE_REQUIRE and 
dnl AC_PROGRAM_REQUIRE. The commands in the fourht argument are evaluated 
dnl after a successful search for a package program and is used to obtain 
dnl the installation directory from a full path to a program. For example 
dnl to obtain /usr/local from /usr/local/bin/wish
AC_DEFUN(AC_PACKAGE_REQUIRE1,
[
   dnl Add configuration switch
   AC_ARG_WITH($1, [$3],
      dnl switch was specified
      translit($1,a-z-,A-Z_)=${withval},
      dnl If switch not specified, try to find the program automatically
      [
         AC_PATH_PROGS(translit($1,a-z-,A-Z_),$2)
         dnl Not found; evaluate <actions if-not-found>
         if test "a$translit($1,a-z-,A-Z_)" = "a" ; then
	    $5
         else
         dnl Program found; evaluate <actions-if-found>
            $4
         fi
      ])
])

AC_DEFUN(AC_PACKAGE_NOT_FOUND,
[
   AC_MSG_ERROR(Required package or program \"$1\" not found.)
])

