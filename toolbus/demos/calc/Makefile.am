noinst_PROGRAMS = clock log calc batch
noinst_DATA     = calc.tb.tex
EXTRA_DIST      = calc.tb delay.h ui-calc.tcl

clock_SOURCES   = clock.c
clock_LDADD     = -L$(top_builddir)/libtb -ltb

log_SOURCES     = log.c
log_LDADD       = -L$(top_builddir)/libtb -ltb

calc_SOURCES    = calc.c
calc_LDADD      = -L$(top_builddir)/libtb -ltb

batch_SOURCES   = batch.c
batch_LDADD     = -L$(top_builddir)/libtb -ltb

INCLUDES        = -I$(top_srcdir)/libtb -I.

CLEANFILES      = clock.tif.c log.tif.c calc.tif.c batch.tif.c calc.tifs \
                  c.tb.tex

$(srcdir)/clock.c: clock.tif.c
clock.tif.c: calc.tifs
	$(top_builddir)/toolbus/ctif -tool clock -tifs $<

$(srcdir)/log.c :log.tif.c
log.tif.c: calc.tifs
	$(top_builddir)/toolbus/ctif -tool log -tifs $<

$(srcdir)/calc.c: calc.tif.c
calc.tif.c: calc.tifs
	$(top_builddir)/toolbus/ctif -tool calc -tifs $<

$(srcdir)/batch.c:batch.tif.c
batch.tif.c: calc.tifs
	$(top_builddir)/toolbus/ctif -tool batch -tifs $<

%.tifs: %.tb
	$(top_builddir)/toolbus/toolbus -gentifs $<
	@if [ "a$(VPATH)" != "a" ]; then \
	   mv $(srcdir)/$@ $@ ;\
	fi

%.tb.tex: %.tb
	$(top_builddir)/toolbus/script2latex < $< > $@
