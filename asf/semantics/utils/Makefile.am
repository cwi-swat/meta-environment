#    Meta-Environment - An environment for language prototyping.
#    Copyright (C) 2000  Stichting Mathematisch Centrum,
#                        Amsterdam, The Netherlands.
#
#    This program is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; either version 2 of the License, or (at
#    your option) any later version.
#
#    This program is distributed in the hope that it will be useful, but
#    WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#    General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program; if not, write to the Free Software
#    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
#    USA
#
#
# $Id$

include ${top_srcdir}/make_rules

INCLUDES	  = -I$(PT_SUPPORT)/include -I$(ATERM)/include

bin_PROGRAMS	  = apply-function

bin_SCRIPTS	  = genmakefile genamakefile

pkgdata_DATA  = genmakefile.proto
EXTRA_DIST	  = genamakefile.sh.src

apply_function_SOURCES	= apply-function.c
apply_function_LDADD	= -L$(ASC_SUPPORT)/lib -lasc-support \
                          -L$(PT_SUPPORT)/lib -lPT \
			  -L$(ATERM)/lib -lATerm

% : %.sh.src Makefile
	sed 's@__BINDIR__@$(bindir)@g;\
             s@__DATADIR__@$(datadir)@g;\
             s@__PT_SUPPORT__@$(PT_SUPPORT)@g;\
             s@__BINFILES__@$(bin_PROGRAMS) $(bin_SCRIPTS)@g;\
             s@__VERSION__@$(VERSION)@g;\
             s@__PERL__@$(PERL)@g' < $< > $@ && \
	chmod +x $@

