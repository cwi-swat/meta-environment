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
#
# $Id$
#

KINDS = meta-header sglr-header pgen-header asc-header
EXTS = .c-style .sh-style .autoconf .tex-style .html .lisp-style

ALLHEADERS = $(foreach ext, $(EXTS), $(addsuffix $(ext), $(KINDS)))


all: $(ALLHEADERS)

clean:
	rm -f $(ALLHEADERS)

meta-header.base: header.base
	sed 's/TOOLDESC/Meta-Environment - An environment for language prototyping./' < $< > $@

sglr-header.base: header.base
	sed 's/TOOLDESC/SGLR - the Scannerless Generalized LR parser./' < $< > $@

pgen-header.base: header.base
	sed 's/TOOLDESC/PGEN - the SDF2 parse table generator./' < $< > $@

asc-header.base: header.base
	sed 's/TOOLDESC/Asf Sdf Compiler Runtime Library/' < $< > $@

# for .c and .tb
%.c-style: %.base
	( echo '/*'; \
	  cat $<; \
	  echo '*/'; \
	) > $@

# for makefiles, shellscripts and pod
%.sh-style: %.base
	sed 's/^/#/g' < $< > $@

%.autoconf: %.base
	sed 's/^/dnl/g' < $< > $@

# for asf+sdf spec and tex files
%.tex-style: %.base
	sed 's/^/%%/g' < $< > $@

%.lisp-style: %.base
	sed 's/^/; /g' < $< > $@

%.html: %.base
	( echo '<!--'; \
	  cat $<; \
	  echo '-->'; \
	) > $@

