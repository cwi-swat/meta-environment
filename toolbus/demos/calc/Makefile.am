#
#    ToolBus -- The ToolBus Application Architecture
#    Copyright (C) 1998-2000  Stichting Mathematisch Centrum, Amsterdam, 
#                             The  Netherlands.
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
noinst_PROGRAMS = clock log calc batch
EXTRA_DIST      = calc.tb delay.h ui-calc.tcl

clock_SOURCES   = clock.c
clock_LDADD     = -L$(top_builddir)/libtb -ltb

log_SOURCES     = log.c
log_LDADD       = -L$(top_builddir)/libtb -ltb

calc_SOURCES    = calc.c
calc_LDADD      = -L$(top_builddir)/libtb -ltb

batch_SOURCES   = batch.c
batch_LDADD     = -L$(top_builddir)/libtb -ltb

INCLUDES        = -I$(top_srcdir)/libtb -I.

CLEANFILES      = clock.tif.c log.tif.c calc.tif.c batch.tif.c calc.tifs

${srcdir}/%.c: %.tif.c

%.tif.c: calc.tifs
	$(top_builddir)/toolbus/ctif -tool $* -tifs $<

%.tifs: %.tb
	$(top_builddir)/toolbus/toolbus -gentifs $<
	@if [ "a$(VPATH)" != "a" ]; then \
	   mv $(srcdir)/$@ $@ ;\
	fi

