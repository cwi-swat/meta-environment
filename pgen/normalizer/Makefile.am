#
#    PGEN - the SDF2 parse table generator.
#    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, The Netherlands. 
#
#    This program is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; either version 2 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program; if not, write to the Free Software
#    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

# $Id$
#
# Author: Merijn de Jonge (mdejonge@cwi.nl)

include ${top_srcdir}/make_rules

bin_PROGRAMS = normalizer
bin_SCRIPTS  = normalize-sdf

EXTRA_DIST   = normalize-sdf.sh.src normalize-normalize-check.sh.src \
               normalize-test.sdf

CLEANFILES   = normalize-sdf normalize-normalize-check

normalizer_SOURCES = normalizer.c asf-interface.c asf-interface.h
normalizer_LDADD   = -L$(PGEN)/c-source -lSdf2-Normalization \
                     -L$(PGEN)/c-lib -lnative \
                     -L$(ASC)/lib -lasc-support \
                     -L$(PT_SUPPORT)/libasfix-old/libasfix -lAsFix \
                     -L$(ATERM)/lib -lATB -lATerm \
                     $(SOCKLIBS)

SGLRLOC=${SGLR}/sglr/sglr

% : %.sh.src Makefile
	sed 's@__PKGDATADIR__@$(pkgdatadir)@g;\
	     s@__PT_SUPPORT__@$(PT_SUPPORT)@g;\
	     s@__BINDIR__@$(bindir)@g;\
	     s@__SGLR__@$(SGLRLOC)@g;\
	     s@__VERSION__@$(VERSION)@g;'\
	   < $< > $@
	chmod 755 $@
