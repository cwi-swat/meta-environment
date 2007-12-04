EXTRA_DIST			= calc.tb ui-calc.tcl
CLEANFILES			= *.tif.[ch] calc.tifs

INCLUDES			= $(TOOLBUSLIB_CFLAGS) $(ATERM_CFLAGS) 

noinst_PROGRAMS		= clock log calc batch

clock_SOURCES		= clock.c clock.h clock-main.c
clock_LDADD			= $(TOOLBUSLIB_LIBS) $(ATERM_LIBS) 

log_SOURCES			= log.c log.h log-main.c
log_LDADD			= $(TOOLBUSLIB_LIBS) $(ATERM_LIBS) 

calc_SOURCES		= calc.c calc.h calc-main.c
calc_LDADD			= $(TOOLBUSLIB_LIBS) $(ATERM_LIBS) 

batch_SOURCES		= batch.c batch.h batch-main.c
batch_LDADD			= $(TOOLBUSLIB_LIBS) $(ATERM_LIBS) 
