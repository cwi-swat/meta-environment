#
#    PGEN - the SDF2 parse table generator.
#    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, 
#                        The Netherlands. 
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
#
# $Id$

include ${top_srcdir}/make_rules

bin_PROGRAMS = parsetablegen
bin_SCRIPTS  = sdf2table 
data_DATA    = parsetablegen.idef
man_MANS     = sdf2table.1

EXTRA_DIST   = parsetablegen.idef sdf2table.src \
               parsetablegen.tif.h parsetablegen.tif.c sdf2table.pod

SRCS         = parsetablegen.c ksdf2table.c atsets.c flatten.c \
               characters.c first.c follow.c goto.c parse-table.c \
               predicted.c priorities.c reductions.c sdf-help.c statistics.c

HDRS         = atsets.h ksdf2table.h statistics.h


parsetablegen_SOURCES = $(SRCS) $(HDRS)
parsetablegen_LDADD   = parsetablegen.tif.o \
                        -L$(PGEN)/c-source -lSdf2-Normalization \
                        -L$(PGEN)/c-lib -lnative \
                        -L$(ASC)/lib -lasc-support \
                        -L$(PT_SUPPORT)/libasfix-old/libasfix -lAsFix \
                        -L$(ATERM)/lib -lATB -lATerm \
                        $(SOCKLIBS)

# remove built files during "make clean"
CLEANFILES = parsetablegen.tifs sdf2table sdf2table.1

parsetablegen.o : parsetablegen.tif.h
sdf-help.o : parsetablegen.tif.h

% : %.src Makefile
	sed 's@__BINDIR__@$(bindir)@g;s@__DATADIR__@$(pkgdatadir)@g;' < $< > $@ &&\
	chmod +x $@
