#
#    Meta-Environment - An environment for language prototyping.
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
include general-make

CHAPS	= 
PICS	= 

# fig2dev-3.2 is essential
#FIG2DEV	= /home/mdejonge/bin/fig2dev-3.2
FIG2DEV	= fig2dev

doc: manual.ps

all: 

manual.dvi: manual.ltx

# when manual.dvi is up-to-date, it will have created manual.idx
# we need to run makeindex on this file, then re-latex and convert
# the dvi to postscript
manual.ps: manual.dvi
	makeindex manual.idx
	latex manual.ltx
	dvips -o $@ $<

spell: at.ltx
#	detex at.ltx | spell +words.txt
	detex manual.ltx | spell -b +words.txt

clean:
	rm -f *~ manual.idx \
		manual.dvi manual.ps

dist: manual.ps
	cp manual.ps ${DISTDIR}

install:

# end of Makefile
