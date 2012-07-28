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

FIG	= evalexp-mlin.fig evalexp-tlog.fig evalsym-tlog.fig evaltree-tlin.fig \
	evalexp-tlin.eps evalsym-tlin.fig evaltree-mlin.fig evaltree-tlog.fig

EPS	= evalexp-mlin.eps evalexp-tlog.eps evalsym-tlog.eps evaltree-tlin.eps \
    evalexp-tlin.eps evalsym-tlin.eps evaltree-mlin.eps evaltree-tlog.eps

include general-make

all: format.ps

# Unit test target
test:	all
	@true

%.eps: %.fig
	fig2dev -Leps $< $@

format.ps: format.dvi
	dvips -o format.ps format.dvi

format.dvi: format.ltx ${EPS}
