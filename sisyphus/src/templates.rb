module BundleTemplates
  CHANGELOG = <<END_OF_CHANGELOG
ChangeLog file for <%=bundle.name.upcase%>-BUNDLE version <%=bundle.version%>.

See the ChangeLog files in the sub-directories of the bundled packages for
a history of changes of the packages.
END_OF_CHANGELOG

  AUTHORS = <<END_OF_AUTHORS
Autobundle is developed by Merijn de Jonge (mdejonge@cs.uu.nl). Check out

   http://www.program-transformation.org/Tools/AutoBundle

for more information.

For the authors of the bundled packages see the AUTHORS file in the package
sub-directories.
END_OF_AUTHORS

  NEWS = <<END_OF_NEWS
NEWS file for <%=bundle.name.upcase%>-BUNDLE version <%=bundle.version%>.

See the NEWS files in the sub-directories of the bundled packages for
information about changes and new features of these packages.
END_OF_NEWS

  README = <<END_OF_README
-----------------------------------------------------------------------------

        <%=bundle.name.upcase%>-BUNDLE version <%=bundle.version%>.

This bundle has been generated with Autobundle. Follow the instructions below
to automatically (i) download and unpack all bundled software packages, and
(ii) configure, build, and install the downloaded packages.

-----------------------------------------------------------------------------

(i) In case all required packages are already available and the file
    ./SOFTWARE exists, this step can be skipped.

     To download and unpack the required packages, type:

     > ./collect.sh

     After "./collect.sh" finishes, the build environment is complete.

(ii) Then, to configure, build and install, type:

     > ./configure <<configuration parameters>>
     > gmake

     You may want to supply an installation directory with the configuration
     parameter --prefix=<dir>. The command

     > ./configure --help

     gives a complete list of available configuration parameters.

-----------------------------------------------------------------------------

For information about bundled packages see the README files in each package
subdirectory. After gmake collect finishes, the file ./SOFTWARE contains a
list of all bundled packages.

After installation the copyright and README files of all packages are
installed in ${prefix}/share/doc.

For information about autobundle see:

     http://www.program-transformation.org/Tools/AutoBundle
     http://www.program-transformation.org/package-base/

There you will also find links to the home pages of the bundled packages.

-----------------------------------------------------------------------------
END_OF_README

  COLLECT_SH =<<END_OF_COLLECT_SH
#! /bin/sh
#
# Autobundle -- Tool suite for automated source tree composition
#
# Copyright (C) 2002-2004 Merijn de Jonge <mdejonge@cs.uu.nl>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
# 02111-1307, USA.

# $Id: collect.sh 7345 2004-09-14 12:06:01Z merijn $

# Author: Merijn de Jonge (mdejonge@cs.uu.nl)


# This script will collect all required packages for an autobundle
# distribution. 
#
# The ingredients of a bundle are defined in a package list file (default
# ./pkg-list). Each line in the file `pkg-list' should have the following
# structure:
#
#   <pkg-name>,<pkg-version>,<pkg location>
#
# pkg location is an url specifying the location of the package, e.g.:
#   cvs://cvs..:/CVS    Specifies that the package should be build by first
#                       checking it out from the repository and then
#                       executing a "make dist" to build a distribution
#   svn://https://..../ Checkout package from Subversion repository
#   http://www.cw...    Obtain a complete distribution via http
#   ftp://ftp.cw...     Obtain a complete distribution via ftp
#   file:///home/x/...  Obtain a distribution from _local_ file system
#
# The collect script creates a file SOFTWARE which contains a list of
# package names, package versions, and package locations.

usage () {
cat <<ENDCAT >&2
This script will collect all required packages for an autobundle
distribution.

usage:
  collect [--force] [--configure <configure>] [--pkg-list <pkg-list>] [pkg ...]
  collect [-h] [--help]
where
  --configure <configure>    specifies Autoconf configure script to use
                             (default ./configure.ac)
  --pkg-list <pkg-list>      specifies package list file (default ./pkg-list)
  --force                    specifies that packages should always be
                             retrieved even they are already present
  --help|-h                  displays this help
  pkg                        specifies the names of packages that should
                             be retrieved (by default all packages from
                             <pkg-list> are retrieved

The collect script creates a file SOFTWARE which contains a list of package
names, package versions, and package locations that have been retrieved.
ENDCAT
}


# Unset variables to prevent conflicts with make.
unset MAKEFLAGS
unset MAKELEVEL


# default values
CONFIGURE=configure.ac  # Default configure script
PKG_LIST=pkg-list       # Default  package list file
FORCE=false             # Force package retrieval when package is already available
PKGS=                   # Empty package list

# Don't throw away any packages that are checked out from a version control
# system, but save them in a specific  directoy (e.g., ${_pkg}-cvs)
save_vcs () {
   _pkg=$1
   if [ ! -d ${_pkg} ]; then
      return
   fi
   fullname=`cd ${_pkg}; basename \`/bin/pwd\``
   if [ -d ./${_pkg}/CVS ]; then
      echo "A copy of the CVS checked out version of"\\
           "${_pkg} is saved in ${_pkg}-cvs." >&2
      mv ${fullname} ${_pkg}-cvs
   elif [ -d ./${_pkg}/.svn ]; then
      echo "A copy of the Subversion checked out version of"\\
           "${_pkg} is saved in ${_pkg}-svn." >&2
      mv ${fullname} ${_pkg}-svn
   fi
}

# Restore a previously checked-out version
restore_vcs() {
   pkg=$1
   pkg_version=$2
   # If we have already a saved CVS copy; rename it to
   # ${pkg}-${pkg_version} such that a cvs update command can be
   # performed.
   if [ -d ${pkg}-cvs -a -d ${pkg}-cvs/CVS ]; then
      rm -fr ./${pkg}-${pkg_version}
      mv ${pkg}-cvs ${pkg}-${pkg_version}
   # If we have already a saved Subversion copy; rename it to
   # ${pkg}-${pkg_version} such that a svn update command can be
   # performed.
   elif [ -d ${pkg}-svn -a -d ${pkg}-svn/.svn ]; then
      rm -fr ./${pkg}-${pkg_version}
      mv ${pkg}-svn ${pkg}-${pkg_version}
   fi
}

# Update, if we already have a checked-out version
update_vcs () {
   pkg=$1
   pkg_version=$2
   
   # If we already have the package checked out using Subversion, perform a
   # svn update and remove the version that we just checked out
   if [ -d ${pkg}-${pkg_version} -a -d ${pkg}-${pkg_version}/.svn ]; then
   (
      rm -fr ./${pkg}
      cd ${pkg}-${pkg_version}
      svn update
   )
   # Or, if we already have the package checked out using CVS, perform a cvs
   # update and remove the version that we just checked out
   elif [ -d ${pkg}-${pkg_version} -a -d ${pkg}-${pkg_version}/CVS ]; then
   (
      rm -fr ./${pkg}
      cd ${pkg}-${pkg_version}
      cvs update
   )
   # otherwise, rename the checked out version to pkg-version
   else
      rm -fr ${pkg}-${pkg_version}
      mv ${pkg} ${pkg}-${pkg_version}
   fi
}

# Set-up the build environment for a package that has been checked-out from 
# a version control system
vcs_init() {
   pkg=$1
   
   # initialized autotools build system
   init_autotools ${pkg}

   # retrieve package version
   autotools_pkg_version ${pkg}
  
   # restore (if possible) a previously checked-out version
   restore_vcs ${pkg} ${pkg_version}

   # update if we already have a checked-out version
   update_vcs ${pkg} ${pkg_version}
}

# create configure script and Makefile.in's 
init_autotools()
{
   pkg=$1
   (  cd ${pkg}; aclocal; autoheader; libtoolize; automake -a; autoconf ) \\
      2>/dev/null 1>/dev/null
}

# Determine package version from configure.ac or configure.in in
# case it was defined in the pkg-list file as '*'.
autotools_pkg_version()
{
   pkg=$1
   if [ -f ${pkg}/configure.ac ]; then
      CONFIG_FILE=${pkg}/configure.ac
   else
      CONFIG_FILE=${pkg}/configure.in
   fi
   pkg_version=`grep 'AC_INIT' ${CONFIG_FILE} \\
                | cut -d, -f2 \\
                | tr -d '[( )]'`
}

do_collect () {
   pkg="$1"
   pkg_version="$2"
   pkg_url="$3"


   case "${pkg_url}" in
      svn://* )
         echo "Obtaining \"${pkg}\" from Subversion.">&2
         svnroot=`echo ${pkg_url} | sed 's@svn://@@g'`

         # Obtain sources using svn checkout
         rm -f ${pkg}
         svn checkout -q ${svnroot}/${pkg}
        
         vcs_init ${pkg}

         ;;
        
      cvs://* )
         echo "Obtaining \"${pkg}\" from CVS.">&2
         cvsroot=`echo ${pkg_url} | sed 's@cvs://@@g'`

         # Obtain sources using cvs checkout
         rm -f ${pkg}
         cvs -Q -d ${cvsroot} checkout ${pkg}

         vcs_init ${pkg}
         
         ;;

      file://* | http://* | ftp://* )
         # Save cvs checked out versions
         save_vcs ${pkg}
         
         protocol="`echo ${pkg_url} | cut -d: -f 1 | tr [:lower:] [:upper:]`"


         # Skip if we already have the package and the --force switch was not used
         if [ -d ${pkg}-${pkg_version} -a "a${FORCE}" = "afalse" ]; then
            return
         fi

         # clean up old and unpacked software package
         if [ -d "${pkg}-${pkg_version}" ]; then
            rm -fr "${pkg}-${pkg_version}"
         fi

         (
            echo -n "Obtaining a distribution of \"${pkg}\" via ${protocol}." >&2
            curl -L -f -s ${pkg_url}/${pkg}-${pkg_version}.tar.gz -o ${tmp}.tar.gz || exit 1
            (gunzip  -c ${tmp}.tar.gz  | tar xf - ) 2>/dev/null || exit 1
         ) || eval 'echo " failed."; exit 1'
         echo " done." >&2
         ;;
      * ) echo unrecognized url: \"$pkg_url\" >&2; exit 1 ;;
   esac
   
   # check whether obtaining and unpacking source distributions succeeded
   if [ ! -d ${pkg}-${pkg_version} ]; then
      echo "Obtaining and/or unpacking of \"${pkg}-${pkg_version}\" failed." >&2;
      exit 1
   fi
   
}

while [ "x$1" != "x" ]
  do
    case $1 in
      --configure ) CONFIGURE=$2; shift; shift ;;
--pkg-list )  PKG_LIST=$2; shift; shift ;;
--force )     FORCE=true ; shift ;;
-h | --help ) usage; exit 0 ;;
-* | --* )    usage; exit 1;;
* )           PKGS="${PKGS} $1"; shift ;;
esac
done

tmp=/tmp/autobundle-$$
trap "rm -f ${tmp}*" 0 1 2 3 4 5 6 7 8 9 10

ALL_PKGS="`grep -v '^#' ${PKG_LIST} | cut -d, -f1`"

if [ "a${PKGS}" = "a" ]; then
  PKGS="${ALL_PKGS}"
  fi
  
  tmp_PKG_LIST=${tmp}.pkgs
rm -f  ${tmp_PKG_LIST}

for pkg in ${PKGS}
do
   pkg_version=`tr -d '\ \t' < ${PKG_LIST} | grep \^${pkg}, | cut -d, -f2`
   pkg_url=`tr -d '\ \t' < ${PKG_LIST} | grep \^${pkg}, | cut -d, -f3-`
   # trip trailing backslash from pkg_url
   pkg_url="`echo ${pkg_url} | sed 's|/$||'`"


   # Obtain sources of software package
   do_collect "${pkg}" "${pkg_version}" "${pkg_url}" || exit 1
 
   # remove old link to pkg-version
   rm -f "./${pkg}" 2>/dev/null

   # Create link <pkg> to <pkg>-<version>
   ln -s "${pkg}-${pkg_version}" "${pkg}"

   echo "${pkg},${pkg_version},${pkg_url}" >> ${tmp_PKG_LIST}
done

# Get the name of the autobundle package
pkg_name="`grep 'AC_INIT' ${CONFIGURE} \\
            | sed 's/AC_INIT//' \\
            | tr -d '[( )]' \\
            | cut -d, -f 1 \\
            | tr '[a-z]' '[A-Z]'`"

# Generate text file describing all packages in an autobundle package 
pkg_version=`grep 'AC_INIT' ${CONFIGURE} \\
             | cut -d, -f2 \\
             | tr -d '[( )]'`

(
cat <<EOF

${pkg_name} version ${pkg_version} is a collection of the following packages:

EOF
 
for pkg in ${ALL_PKGS}
do
   pkg_version=`grep \^${pkg}, ${tmp_PKG_LIST} | cut -d, -f2`
   pkg_url=`grep \^${pkg}, ${tmp_PKG_LIST} | cut -d, -f3-`

   echo "   ${pkg}-${pkg_version} from ${pkg_url}"
done

echo
echo "${pkg_name} is bundled on `date '+%c'` with"
echo "autobundle (http://www.cwi.nl/~mdejonge/autobundle/)."

cp) > SOFTWARE
END_OF_COLLECT_SH

PRE_CHECKS_MAKEFILE_AM =<<END_OF_MAKEFILE_AM
# Autobundle -- Tool suite for automated source tree composition

# Author: Merijn de Jonge (mdejonge@cs.uu.nl)

# Copyright (C) 2002-2004 Merijn de Jonge <mdejonge@cs.uu.nl>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
# 02111-1307, USA.

# $Id: Makefile.am.pre-checks.templ 6181 2004-05-10 12:46:54Z merijn $

# This Makefile defines several checks for make targets. It is intended to
# check that all required tools and libraries are available and to abort the
# build process if not.

# These checks are not performed during execution of configure because
# not all make targets depend on the same tools/libraries.

PRE_CHECKS=gnumake-check

all install install-strip check: $(PRE_CHECKS)

# Check whether $(MAKE) is GNU make
gnumake-check:
	@gnumake=`$(MAKE) -f /dev/null -v 2>&1 | grep GNU || true` ;\\
	if [ "a$$gnumake" = "a" ] ;\\
	then \\
	   echo "Use GNU make to build this software bundle." >&2 ;\\
	   exit 1;\\
	fi
END_OF_MAKEFILE_AM


CONFIGURE_AC =<<END_OF_CONFIGURE_AC
AC_INIT([<%=bundle.name%>],[<%=bundle.version%>])
AB_INIT_AUTOBUNDLE
AM_INIT_AUTOMAKE

AC_PATH_PROG([CURL], [curl])
if test -z "$CURL"; then
   AC_MSG_ERROR([curl command not found])
fi
AC_SUBST([CURL])

PKGS="<%=bundle.packages.join(' ')%>"
AC_SUBST([PKGS])

AC_CONFIG_FILES([
   Makefile
   pre-checks/Makefile
])
AC_OUTPUT

<% bundle.packages.each do |package| %>
AB_CONFIG_PKG([<%=package%>],[
   --with-bundled-packages='${PKGS}'
<% bundle.dependencies[package].each do |dep| %>
   --with-<%=dep.name%>=\\\\\\${prefix}
<% end %>
])
<% end %>
END_OF_CONFIGURE_AC

MAKEFILE_AM = <<END_OF_MAKEFILE_AM
# Autobundle -- Tool suite for automated source tree composition

# Author: Merijn de Jonge (mdejonge@cs.uu.nl)

# Copyright (C) 2002-2004 Merijn de Jonge <mdejonge@cs.uu.nl>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
# 02111-1307, USA.

# $Id: Makefile.am.templ 7349 2004-09-14 12:10:28Z merijn $

# If you want to exclude packages from the build process, issue
#    gmake EXCLUDE="<packages_to_exclude>"
# Note that this may lead to build failures due to package dependencies.
BUILD_PKGS   = $(filter-out $(EXCLUDE), $(PKGS))
DIST_SUBDIRS = pre-checks \\
	       $(BUILD_PKGS)

EXTRA_DIST   = $(EXTRA_FILES)
EXTRA_FILES  = SOFTWARE README collect.sh pkg-list

# We need at least one subdir to be defined such that automake will generate
# the code for traversing subdirectories
SUBDIRS      = pre-checks

# Location where to install README and Copyright files
docdir = $(datadir)/doc

# Always install the file SOFTWARE in $(docdir)
doc_DATA = SOFTWARE

PKG_DOCFILES = README COPYING COPYRIGHT LICENSE

all: install

check clean:
	PATH=$(bindir):$${PATH}; export PATH ;\\
	for subdir in $(DIST_SUBDIRS); do \\
	   ( cd $$subdir && $(MAKE) $@ ) || exit 1 ;\\
	done

collect :
	./collect.sh --configure configure.ac --pkg-list pkg-list

bundle : collect
	./configure
	$(MAKE) dist

# Install and uninstall hooks for installing/uninstalling packages and
# documentation files
install-exec-hook:
	PATH=$(bindir):$${PATH}; export PATH ;\\
	for subdir in $(DIST_SUBDIRS); do \\
	   ( cd $$subdir && $(MAKE) all install ) || exit 1 ;\\
	done

uninstall-hook:
	PATH=$(bindir):$${PATH}; export PATH ;\\
	for subdir in $(DIST_SUBDIRS); do \\
	   ( cd $$subdir && $(MAKE) uninstall ) || exit 1 ;\\
	done

# Local target to install README and Copyright files
install-data-local:
	$(mkinstalldirs) $(DESTDIR)$(docdir)
	for p in $(PKGS); do \\
	   for f in $(PKG_DOCFILES); do \\
	      if [ -f $$p/$$f ]; then \\
		 $(INSTALL_DATA) $$p/$$f $(DESTDIR)$(docdir)/$$p.$$f ;\\
	      fi ;\\
	   done ;\\
	done

uninstall-local:
	for p in $(PKGS); do \\
	   for f in $(PKG_DOCFILES) ; do \\
	      if [ -f $(docdir)/$$p.$$f ]; then \\
		 $(RM) $(docdir)/$$p.$$f ;\\
	      fi ;\\
	   done ;\\
	done
END_OF_MAKEFILE_AM

# The strange layouting of template patterns is required
# for proper newline handling (for a line beginning and 
# ending with < and > resp. the newlines are omitted
PKG_LIST =<<END_OF_PKG_LIST
<% bundle.packages.each do |package| %><%=package.name%>
,<%=package.version%>,<%=bundle.location%>
<% end %>
END_OF_PKG_LIST
end
