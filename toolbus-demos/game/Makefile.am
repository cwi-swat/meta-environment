noinst_PROGRAMS = board

EXTRA_DIST      = game.tb ui-game.tcl

board_SOURCES   = board.c
board_LDADD     = $(TOOLBUSLIB)/lib -ltb

INCLUDES        = $(TOOLBUSLIB)/include -I.

CLEANFILES      = board.tif.c game.tifs

board.o : board.tif.c

%.tif.c : game.tifs
	$(top_builddir)/toolbus/ctif -tool $* -tifs $<

%.tifs: %.tb
	$(top_builddir)/toolbus/toolbus -gentifs $<
	@if [ "a$(VPATH)" != "a" ]; then \
	   mv $(srcdir)/$@ $@ ;\
	fi
