
EXTRA_DIST	= sisyphus.sql

sql_DATA	= sisyphus.postgresql sisyphus.sqlite3

sqldir		= $(pkdatadir)/sql

CLEANFILES 	= sisyphus.postgresql sisyphus.sqlite3

%.postgresql : %.sql
	cat $< > $@

%.sqlite3 : %.sql
	cat $< \
	| sed -e 's/serial/integer/' \
	| sed -e 's/primary key/primary key autoincrement/' \
	| sed -e 's/^drop.*$$//' \
	> $@


