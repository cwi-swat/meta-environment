
bin_PROGRAMS=error-diff

INCLUDES= \
	-I${top_srcdir}/lib \
	-I${ATERM}/include

error_diff_SOURCES=\
	error-diff.c

error_diff_LDADD=\
	-L${ATERM}/lib -lATerm\
	-L${top_builddir}/lib -lErrorAPI
