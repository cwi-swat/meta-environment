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

bin_PROGRAMS       = meta-paths imports remove-annotation apply-function
bin_SCRIPTS        = genmakefile parse-file parse-sdf2 ps-dot insert-license \
                     insert-header genamakefile change-sdf2-ext sdf2stats

man_MANS           = parse-sdf2.1

data_DATA          = genmakefile.proto lang.types

noinst_LIBRARIES   = libutils.a

TESTS              = perform-test

EXTRA_DIST         = genmakefile.in parse-file.sh.src parse-sdf2.sh.src \
                     ps-dot.sh.src insert-header.pl.src \
                     insert-license.sh.src test-help test-version \
                     genmakefile.proto lang.types perform-test.sh.src \
                     parse-sdf2.pod genamakefile.sh.src change-sdf2-ext \
                     sdf2stats

CLEANFILES         = genmakefile parse-file parse-sdf2 ps-dot insert-header \
                     insert-license perform-test parse-sdf2.1 genamakefile \
                     sdf2stats

meta_paths_SOURCES = meta-paths.c
meta_paths_LDADD   = libutils.a \
                     -L$(ASFIX)/lib -lAsFix \
                     -L$(ATERM)/lib -lATerm

imports_SOURCES    = imports.c
imports_LDADD      = libutils.a \
                     -L$(ASFIX)/lib -lAsFix \
                     -L$(ATERM)/lib -lATerm

remove_annotation_SOURCES = remove-annotation.c
remove_annotation_LDADD = -L$(ATERM)/lib -lATerm

apply_function_SOURCES = apply-function.c
apply_function_LDADD = -L$(ATERM)/lib -lATerm -L$(ASFIX)/lib -lAsFix

libutils_a_SOURCES = meta-utils.c meta-utils.h module-utils.c module-utils.h


INCLUDES           = -I$(ASFIX)/include -I$(ATERM)/include

% : %.sh.src Makefile
	sed 's@__BINDIR__@$(bindir)@g;\
	     s@__DATADIR__@$(datadir)@g;\
	     s@__BINFILES__@$(bin_PROGRAMS) $(bin_SCRIPTS)@g;\
	     s@__VERSION__@$(VERSION)@g;\
	     s@__PERL__@$(PERL)@g' < $< > $@ && \
	chmod +x $@

%: %.pl.src Makefile
	sed 's@__PERL__@$(PERL)@g' < $< > $@ && \
	chmod +x $@



	
