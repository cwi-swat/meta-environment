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

SUBDIRS     = asfix asc-support sglr pgen compiler asfix2c-compiler editors \
              evaluator graph-browser in-output module-db utils toolbus \
              grammars demo doc asf-syntax

EXTRA_DIST  = make_rules meta.sh.src meta.pod

bin_SCRIPTS = meta

man_MANS    = meta.1

CLEANFILES  = meta meta.1

TOOLBUSDEFS = $(TRAVERSALSDEF)

% : %.sh.src Makefile
	sed 's@__PREFIX__@$(prefix)@g;\
	     s@__BINDIR__@$(bindir)@g;\
	     s@__DATADIR__@$(datadir)@g;\
	     s@__TOOLBUS__@$(TOOLBUSBIN)/toolbus@g;\
	     s@__TOOLBUS_DEFS__@$(TOOLBUSDEFS)@g;\
	     s@__WISH__@$(WISH)@g;\
	     s@__GRAPHVIZ__@$(GRAPHVIZ)@g;' < $< > $@ && \
	chmod +x $@


