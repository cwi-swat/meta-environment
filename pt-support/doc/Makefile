#
#    MEPT -- The Meta-Environment Parse Tree library
#
#    Copyright (C) 2001  Stichting Mathematisch Centrum, Amsterdam, 
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
include general-make

# fig2dev-3.2 is essential
FIG2DEV = fig2dev

doc: PTdoc.ps

all:

PTdoc.dvi: PTdoc.ltx      

PTdoc.ps: PTdoc.dvi
	#makeindex PTdoc.idx
	latex PTdoc.ltx
	dvips -o $@ $<

spell: PTdoc.ltx
	detex PTdoc.ltx | spell -b +words.txt

clean:
	rm -f *~ PTdoc.idx PTdoc.dvi PTdoc.ps

dist: PTdoc.ps
	cp PTdoc.ps ${DISTDIR}

install:    
