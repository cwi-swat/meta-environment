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

SUBDIRS     = config editors graph-browser \
              in-output module-db utils tbscripts demo doc  \
              configuration-manager

EXTRA_DIST  = make_rules meta.sh.src meta.pod reconf

bin_SCRIPTS = meta

man_MANS    = meta.1

CLEANFILES  = meta meta.1

% : %.sh.src Makefile
	sed 's@__PREFIX__@$(prefix)@g;\
	     s@__ATERM__@$(ATERM)@g;\
	     s@__SGLR__@$(SGLR)@g;\
	     s@__PGEN__@$(PGEN)@g;\
	     s@__EVALUATOR__@$(EVALUATOR)@g;\
	     s@__TOOLBUS__@$(TOOLBUS)/toolbus@g;\
	     s@__WISH__@$(WISH)@g;\
	     s@__XEMACS__@$(XEMACS)@g;\
	     s@__GRAPHVIZ__@$(GRAPHVIZ)@g;' < $< > $@ && \
	chmod +x $@


