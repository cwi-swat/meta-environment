
bin_SCRIPTS=extract-relations merge-rstores rscript rstore2rviz

CLEANFILES=extract-relations merge-rstores rscript rscript2rviz

% : %.sh.src Makefile
	sed 's@__PREFIX__@$(prefix)@g;\
	     s@__BINDIR__@$(bindir)@g;\
	     s@__VERSION__@$(VERSION)@g;' < $< > $@ && \
	chmod +x $@



