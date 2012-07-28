
AC_INIT
META_SETUP

META_REQUIRE_SOFTWARE(postgresql, psql)
META_REQUIRE_SOFTWARE(ruby, ruby)

AC_ARG_WITH(name,
   [  --with-database-name=NAME   Sisyphus database name ],
   DATABASE_NAME=$withval,
   DATABASE_NAME=sisyphus20)
AC_SUBST(DATABASE_NAME)

AC_ARG_WITH(host,
   [  --with-database-host=HOST   Sisyphus database host ],
   DATABASE_HOST=$withval,
   DATABASE_HOST=sjofar.sen.cwi.nl)
AC_SUBST(DATABASE_HOST)

AC_ARG_WITH(port,
   [  --with-database-port=PORT   Sisyphus database port ],
   DATABASE_PORT=$withval,
   DATABASE_PORT=5432)
AC_SUBST(DATABASE_PORT)

AC_ARG_WITH(user,
   [  --with-database-user=USER   Sisyphus database user ],
   DATABASE_USER=$withval,
   DATABASE_USER=sisyphus)
AC_SUBST(DATABASE_USER)


AC_OUTPUT

