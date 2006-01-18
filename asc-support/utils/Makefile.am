
EXTRA_DIST = asc-support-config.src $(wildcard *.sh)

bin_SCRIPTS = asc-support-config
noinst_SCRIPTS = gen-forward.sh gen-protos.sh gen-link-test.sh


CLEANFILES = asc-support-config

ASC_INCLUDES=\
        -I$(prefix)/include \
	-I$(PT_SUPPORT)/include \
	-I$(ASF_SUPPORT)/include \
	-I$(ERROR_SUPPORT)/include \
	-I$(TOOLBUSLIB)/include \
	-I$(SGLR)/include \
	-I$(TIDE_SUPPORT)/include \
	-I$(ATERM)/include

ASC_LD_FLAGS=\
	-L${prefix}/lib -lasc-support-me \
	-L${SGLR}/lib -lsglr \
	-L${TIDE_SUPPORT}/lib -ltide-adapter \
	-L${ASF_SUPPORT}/lib -lASFME \
	-L${PT_SUPPORT}/lib -lmept -lPTMEPT \
	-L${TOOLBUSLIB}/lib -lATB  \
	-L${ERROR_SUPPORT}/lib -lErrorAPI \
	${ATERM}/lib/libATerm.a \
	${SOCKLIBS}


% : %.src Makefile
	sed 's@__PREFIX__@$(prefix)@g;\
             s@__LDFLAGS__@$(ASC_LD_FLAGS)@g;\
             s@__INCLUDES__@$(ASC_INCLUDES)@g' < $< > $@ && \
	chmod +x $@
