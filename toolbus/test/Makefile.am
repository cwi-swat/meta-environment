TESTS           = TBmatch1 TermIO test-removesocket $(OK_TESTS) \
                  $(ERROR_TESTS)

noinst_PROGRAMS = TBmatch1 TermIO

EXTRA_DIST      = bind.tb expr-errors.tb expr.tb garbage.tb if.tb msg.tb \
                  notes.tb scope.tb tc-errors.tb tc.tb types.tb \
                  expr-errors.tb.out scope.tb.out tc-errors.tb.out \
                  test-removesocket.src

OK_TESTS        = if-ok msg-ok notes-ok bind-ok expr-ok types-ok garbage-ok
ERROR_TESTS     = expr-errors-fail tc-errors-fail scope-fail

CLEANFILES      = $(OK_TESTS) $(ERROR_TESTS) test-removesocket

LDADD           = -L../libtb -ltb
INCLUDES        = -I$(top_srcdir)/libtb

%-ok : %.tb
	echo '$(top_builddir)/toolbus/toolbus -TB_PORT 9999 $< 2>/dev/null >/dev/null'  > $@
	chmod +x $@

%-fail : %.tb
	echo 'trap "rm -f tmp" 0' > $@
	echo '$(top_builddir)/toolbus/toolbus -TB_PORT 9999 $< 2>&1 >/dev/null \\' >> $@
	echo "| sed 's/^[^,]*, //' > tmp" >> $@
	echo 'diff $<.out tmp' >> $@
	chmod +x $@

% : %.src Makefile
	sed 's@__TOP_BUILDDIR__@$(top_builddir)@g;\
             s@__SRCDIR__@$(srcdir)@g' <$< > $@
	chmod +x $@

