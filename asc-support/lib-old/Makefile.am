#
#    Asf Sdf Compiler Runtime Library
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
#
# $Id$

include make_rules

lib_LIBRARIES            = libasc-support.a

include_HEADERS          = asc-support.h
EXTRA_DIST               = rewriter.tb

SRCS = asc-support.c asc-support.h rewriter.c
ALLSRCS = asc-support.c asc-support.h rewriter.c rewriter.tif.c

libasc_support_a_SOURCES = $(SRCS)
libasc_support_a_LIBADD  = rewriter.tif.o

BUILT_SOURCES            = rewriter.tif.c rewriter.tif.h

# Default include directories
INCLUDES   = -I. -I$(ATERMINC)

CLEANFILES = rewriter.tif.c rewriter.tif.h

${srcdir}/rewriter.c: rewriter.tif.h

# The output of toolbus is moved to $@ to make sure the generated
# .tifs file exists in the current directory. The ToolBus idef2tif by
# default uses the dirname of its file name argument to determine the
# location the output. This does not work correct when using VPATH in
# the Makefile.
%.tifs: %.tb
	$(TOOLBUSBIN)/toolbus -gentifs $<
	@if [ "a${VPATH}" != "a" ]; then \
	   mv ${srcdir}/$@ $@ ;\
	fi

%.tif.c %.tif.h: %.tifs
	$(ATERMBIN)/tifstoc -tool $* $<

test: all
	@echo "Test not yet implemented for asc-support"
