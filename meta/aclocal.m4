dnl
dnl    Meta-Environment - An environment for language prototyping.
dnl    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, The Netherlands. 
dnl
dnl    This program is free software; you can redistribute it and/or modify
dnl    it under the terms of the GNU General Public License as published by
dnl    the Free Software Foundation; either version 2 of the License, or
dnl    (at your option) any later version.
dnl
dnl    This program is distributed in the hope that it will be useful,
dnl    but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl    GNU General Public License for more details.
dnl
dnl    You should have received a copy of the GNU General Public License
dnl    along with this program; if not, write to the Free Software
dnl    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
dnl
dnl $Id$

dnl Configure sub components with additional configure flags
dnl usage:
dnl    AC_CONFIG_PKG(pkgname, configure flags)
dnl 
dnl where
dnl     pkgname = the name of the package (i.e., the name of the directory
dnl               where the package is located
dnl     flags   = additional configure flags to be passed to the package
dnl               configure script
dnl 
dnl note.
dnl    -AC_CONFIG_PKG should be called __after__ any calls to AC_OUTPUT.
dnl    -Multiple package names may be listed which will all be configured with
dnl     the same configure flags
dnl    -Use multiple calls to AC_CONFIG_PKG to configure multiple packages
dnl     differently.


AC_DEFUN(AC_CONFIG_PKG,
[
   AC_REQUIRE([AC_CONFIG_AUX_DIR_DEFAULT])
   dnl Save configuration flags
   ac_saved_args=$ac_configure_args
   dnl Add package specific flags
   ac_configure_args="$2 $ac_configure_args"
   dnl configure sub-package
   AC_OUTPUT_SUBDIRS($1)
   dnl Restore configuration flags
   ac_configure_args=$ac_saved_args
]
)