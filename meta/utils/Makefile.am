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

bin_PROGRAMS       = meta-paths 
bin_SCRIPTS        = parse-file parse-sdf2 ps-dot insert-license \
                     insert-header change-sdf2-ext sdf2stats \
                     change-eqs-ext

man_MANS           = parse-sdf2.1

data_DATA          = lang.types

noinst_LIBRARIES   = libutils.a

TESTS              = perform-test

EXTRA_DIST         = parse-file.sh.src parse-sdf2.sh.src \
                     ps-dot.sh.src insert-header.pl.src \
                     insert-license.sh.src test-help test-version \
                     lang.types perform-test.sh.src \
                     parse-sdf2.pod change-sdf2-ext \
                     sdf2stats change-eqs-ext

CLEANFILES         = parse-file parse-sdf2 ps-dot insert-header \
                     insert-license perform-test parse-sdf2.1 \
                     sdf2stats

meta_paths_SOURCES = meta-paths.c
meta_paths_LDADD   = libutils.a \
                     -L$(PT_SUPPORT)/lib -lPT \
                     -L$(ATERM)/lib -lATerm

libutils_a_SOURCES = meta-utils.c meta-utils.h 

INCLUDES           = -I$(PT_SUPPORT)/include -I$(ATERM)/include

% : %.sh.src Makefile
	sed 's@__BINDIR__@$(bindir)@g;\
	     s@__DATADIR__@$(datadir)@g;\
	     s@__PT_SUPPORT__@$(PT_SUPPORT)@g;\
	     s@__BINFILES__@$(bin_PROGRAMS) $(bin_SCRIPTS)@g;\
	     s@__VERSION__@$(VERSION)@g;\
	     s@__PERL__@$(PERL)@g' < $< > $@ && \
	chmod +x $@

%: %.pl.src Makefile
	sed 's@__PERL__@$(PERL)@g' < $< > $@ && \
	chmod +x $@
