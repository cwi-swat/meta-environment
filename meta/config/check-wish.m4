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

dnl Check for version of wish. WISH variable should be defined.
AC_DEFUN(META_WISH_VERSION,
[
   dnl See if we found a valid verion of wish; version 8.0 or above
   wish_version=`echo 'puts "$tk_version" ; exit;' | ${WISH} 2>/dev/null`
   if test "a${wish_version}" = "a"; then
      AC_ERROR( [ No wish program available or other error. ] )
   fi

   dnl Check for correct version (>= 8.00)
   case ${wish_version} in
      [[0-7]].* )
         AC_ERROR( [ Wish version >= 8.X required (found $wish_version) ] ) ;;
   esac
])

dnl Check for wish and test for corrrect verion >= 8.0
AC_DEFUN(META_CHECK_WISH,
[
   AC_PACKAGE_REQUIRE(wish, 
                      wish8.1 wish8.0 wish, 
                      [  --with-wish=DIR         wish program is in DIR],)
   META_WISH_VERSION
])
