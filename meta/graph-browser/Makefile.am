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

EXTRA_DIST  = graph-browser.sh.src graphbrowser.tcl.src \
              graph-browser.pod graph-browser.1

bin_SCRIPTS = graph-browser
pkgdata_DATA   = graph-browser.tcl
man_MANS    = graph-browser.1


CLEANFILES  = graph-browser graph-browser.tcl graph-browser.1

% : %.sh.src Makefile
	@@if [ -z "$(GRAPHVIZ)" -o  ! -d $(GRAPHVIZ)/lib ]; then \
	   echo "Required package \`graphviz' not found. Please specify its\
	         location during configuration with the \`--with-graphviz'\
                 flag." >&2 ;\
	   exit 1 ;\
	 fi
	sed 's@__WISH__@$(WISH)@g;\
	     s@__GRAPHVIZ__@$(GRAPHVIZ)@g;\
	     s@__ASF_LIBRARY__@$(ASF_LIBRARY)@g;\
	     s@__DATADIR__@$(pkgdatadir)@g' < $< > $@ && \
	chmod +x $@

%.tcl: %.tcl.src Makefile
	sed 's@__USE_TIDE__@$(USE_TIDE)@g;\
             s@__ASF_LIBRARY__@$(ASF_LIBRARY)@g;' < $< > $@ 

