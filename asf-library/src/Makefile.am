include ${top_srcdir}/templates/make_rules

BUILTIN_NAMES:=$(shell cd $(top_srcdir)/lib; grep -r "built-in" * | \
                       sed -e 's@.*built-in(\"\(.*\)\").*@\1@g' | \
                       sed -e 's@-@_@g')

include_HEADERS=asf-builtins.h
lib_LIBRARIES=libasf-builtins.a

libasf_builtins_a_SOURCES=asf-builtins.h asf-builtins.c 

CLEANFILES+=asf-builtins.h

INCLUDES=-I$(ATERM)/include -I$(PT_SUPPORT)/include

asf-builtins.h: Makefile
	@(echo '#ifndef BUILTINS_H' ;\
	  echo '#define BUILTINS_H' ;\
	  echo '#include <MEPT.h>'  ;\
          echo '' ;\
	  echo 'void initBuiltins(void);' ;\
	  echo 'PT_Tree forwardBuiltin(ATerm builtin, PT_Tree input);' ;\
	  for b in ${BUILTIN_NAMES}; do \
             echo "PT_Tree $${b}(ATerm builtin, PT_Tree input);" ; \
          done ;\
          echo '#endif' ) > $@


