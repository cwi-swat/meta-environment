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

INPUTS = editors.ltx new-meta.ltx toolbus.ltx ui.ltx \
         interpreter.ltx repos.ltx treerepr.ltx newarch.tex \
	 metabib.bib

PICTURES = newmeta.ps toolbus.ps

all: ps

# Unit test target
test:	all
	@true

ps: new-meta.ps 

new-meta.ps: new-meta.dvi 
	dvips -o new-meta.ps new-meta.dvi

new-meta.dvi: $(INPUTS) $(PICTURES)

prev: new-meta.dvi
	xdvi new-meta.dvi &

print: new-meta.ps
	lpr new-meta.ps

toolbus.ps: toolbus.fig
	fig2dev -Lps toolbus.fig toolbus.ps
