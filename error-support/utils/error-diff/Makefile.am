
bin_PROGRAMS=error-diff

INCLUDES= \
	-I${top_srcdir}/lib \
	-I${ATERM}/include

if MAINTAINER_MODE
ATERM_LIB = ATerm-dbg
else
ATERM_LIB = ATerm
endif

error_diff_SOURCES=\
	error-diff.c

error_diff_LDADD=\
	-L${ATERM}/lib -l$(ATERM_LIB)\
	-L${top_builddir}/lib -lErrorAPI
