
bin_PROGRAMS=error-diff

INCLUDES= \
	-I${ATERM}/include\
	-I${top_srcdir}/lib

error_diff_SOURCES=\
	error-diff.c

error_diff_LDADD=\
	-L${ATERM}/lib -lATerm\
	-L${top_builddir}/lib -lErrorAPI
