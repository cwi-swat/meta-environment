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

dnl Check for version of wish. 

dnl Check version of tk package by cunsulting tkConfig.sh and set WISH
dnl variable to full path to wish program $1/bin/wish/<tkversion>
AC_DEFUN(META_WISH_VERSION_CHECK,
[
   dnl See if we found a valid version of wish; version 8.0 or 
   dnl above is required
   tk_version=`eval . $1/lib/tkConfig.sh ; echo ${TK_VERSION} 2>/dev/null`
   if test "a${tk_version}" = "a"; then
      AC_ERROR( [ No wish program available or other error. ] )
   fi

   dnl Check for correct version (>= 8.0)
   case ${tk_version} in
      [[0-7]].* )
         AC_ERROR( [ Wish version >= 8.X required (found $tk_version) ] ) ;;
   esac
   WISH=$1/bin/wish${tk_version}
])
