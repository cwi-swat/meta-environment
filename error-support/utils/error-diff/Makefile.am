
bin_PROGRAMS=error-diff

AM_CPPFLAGS = \
	-I$(top_srcdir)/lib \
	$(ATERM_CFLAGS)

error_diff_SOURCES=\
	error-diff.c

error_diff_LDADD=\
	-L$(top_builddir)/lib -lErrorAPI \
	$(ATERM_LIBS)
