noinst_PROGRAMS = board

EXTRA_DIST      = game.tb ui-game.tcl

board_SOURCES   = board.c
board_LDADD     = -L$(top_builddir)/libtb -ltb

INCLUDES        = -I$(top_srcdir)/libtb -I.

CLEANFILES      = board.tif.c game.tifs

$(srcdir)/board.c : board.tif.c

board.tif.c : game.tifs
	$(top_builddir)/toolbus/ctif -tool board -tifs $<

%.tifs: %.tb
	$(top_builddir)/toolbus/toolbus -gentifs $<
	@if [ "a$(VPATH)" != "a" ]; then \
	   mv $(srcdir)/$@ $@ ;\
	fi
