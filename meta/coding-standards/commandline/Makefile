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
#! gmake

CENTER="Meta-Environment Documentation"
RELEASE="Meta-Conventions 1.0"

target=commandline
files=meta-skel ${target}.7 ${target}.txt ${target}.html ${target}.bok

all:	${files}

# Unit test target
test:	all
	@echo "Unit test not yet implemented for: ${BINFILES}"; false

%.7:	%.pod
	-pod2man --center=${CENTER} --release=${RELEASE} --section=7 $< > $@
		
%.txt: %.pod
	-pod2text $< > $@

%.html: %.pod
	-pod2html $< > $@
	-rm -f pod2html-*


%.bok: %.pod
	-pod2docbook $< > $@

clean:
	-rm -f ${files}
