
include $(top_srcdir)/Makefile.meta

EXTRA_DIST = asc-support-config.src $(wildcard *.sh)

bin_SCRIPTS = asc-support-config
noinst_SCRIPTS = gen-forward.sh gen-protos.sh gen-link-test.sh


CLEANFILES = asc-support-config

ASC_INCLUDES=\
        -I$(prefix)/include \
	$(PT_SUPPORT_CFLAGS) \
	$(ASF_SUPPORT_CFLAGS) \
	$(ERROR_SUPPORT_CFLAGS) \
	$(TOOLBUSLIB_CFLAGS) \
	$(SGLR_CFLAGS) \
	$(TIDE_SUPPORT_CFLAGS) \
	$(ATERM_CFLAGS) 

ASC_LD_FLAGS=\
	-L${prefix}/lib -lasc-support-me \
	$(SGLR_LIBS) \
	$(TIDE_SUPPORT_LIBS) \
	$(ASF_SUPPORT_LIBS) \
	$(PT_SUPPORT_LIBS) \
	$(TOOLBUSLIB_LIBS) \
	$(ERROR_SUPPORT_LIBS) \
	$(ATERM_LIBS) \
	${SOCKLIBS}


% : %.src Makefile
	sed "s@__PREFIX__@$(prefix)@g;\
             s@__LDFLAGS__@$(ASC_SUPPORT_LIBS)@g;\
             s@__INCLUDES__@$(ASC_SUPPORT_CFLAGS)@g" < $< > $@ && \
	chmod +x $@
