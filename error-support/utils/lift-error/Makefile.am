
bin_PROGRAMS=lift-error

INCLUDES=\
	-I${ATERM}/include\
	-I${top_srcdir}/lib

lift_error_SOURCES=\
	lift-error.c

lift_error_LDADD=\
	-L${ATERM}/lib -lATerm\
	-L${top_builddir}/lib -lErrorAPI
