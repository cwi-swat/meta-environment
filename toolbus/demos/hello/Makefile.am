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
noinst_PROGRAMS   = hello printer hello-gen

noinst_DATA       = hello1.tb.tex hello2.tb.tex hello3.tb.tex hello.c.tex \
                    hello-gen.c.tex hello.tif.c.tex pipe.tb.tex \
                    hello.tcl.tex hello.perl.tex Hello.java.tex \
                    HelloTool.java.tex hello.py.tex

EXTRA_DIST        = hello1.tb \
                    hello2.tb \
                    hello3.tb \
                    hello.tcl \
                    hello.perl \
                    hello.pl \
                    hello.pl.tb \
                    pipe.tb \
                    PC.tb producer.c store.c \
                    hello.py hello2py.tb no-pl.sh \
                    hello2java.tb Hello.java HelloTool.java

hello_SOURCES     = hello.c
hello_LDADD       = -L$(top_builddir)/libtb -ltb

hello_gen_SOURCES = hello-gen.c
hello_gen_LDADD   = -L$(top_builddir)/libtb -ltb
$(srcdir)/hello-gen.c : hello.tif.c

printer_SOURCES   = printer.c
printer_LDADD     = -L$(top_builddir)/libtb -ltb

INCLUDES          = -I$(top_srcdir)/libtb -I.

CLEANFILES        = hello.tif.c hello2.tifs *.tex

hello.tif.c: hello2.tifs
	$(top_builddir)/toolbus/ctif -tool hello -tifs $<

%.tifs: %.tb
	$(top_builddir)/toolbus/toolbus -gentifs $<
	@if [ "a$(VPATH)" != "a" ]; then \
	   mv $(srcdir)/$@ $@ ;\
	fi

%.tb.tex : %.tb
	$(top_builddir)/toolbus/script2latex <$< >$@

%.c.tex : %.c
	$(top_builddir)/toolbus/verbatim < $< > $@

%.tcl.tex : %.tcl
	$(top_builddir)/toolbus/verbatim < $< > $@

%.perl.tex : %.perl
	$(top_builddir)/toolbus/verbatim < $< > $@

%.py.tex : %.py
	$(top_builddir)/toolbus/verbatim < $< > $@

%.java.tex : %.java
	$(top_builddir)/toolbus/verbatim < $< > $@
