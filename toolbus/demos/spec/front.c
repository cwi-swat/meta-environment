#include <stdio.h>
#include <string.h>

typedef union{
        int nr_args;
        char list_it;} arity;

typedef struct{
        char ch;
        int nr;} abbrev;

typedef struct{
        char *mstr;
        arity ari;
        abbrev abbr;
        } item;

typedef struct tag_table_node {
        item it;
        struct tag_table_node *next;} table_node;

typedef table_node * table;

table cr_node(char *mstr, arity ari, abbrev abbr)
{table tnew;

 tnew = (table)malloc(sizeof(table_node));
 tnew->it.mstr = strdup(mstr);
 tnew->it.ari = ari;
 tnew->it.abbr = abbr;
 tnew->next = NULL;
 return tnew;
}

table tab = NULL;
abbrev abbr;


int add_item(char *mstr, arity ari)
{table tt = tab;
 int new_abbr = 0;

 abbr.ch = 'a';
 abbr.nr = 0;

 if (tab == NULL) {
        tab = cr_node(mstr, ari, abbr);
        new_abbr = 1;
 } else {
        while (tt->next != NULL && strcmp(tt->it.mstr, mstr) != 0) {
                if (tt->it.abbr.ch == abbr.ch)
                        abbr.nr = tt->it.abbr.nr + 1;
                tt = tt->next;
        };
        if (strcmp(tt->it.mstr, mstr) == 0)
                abbr = tt->it.abbr;
        else {
                if (tt->it.abbr.ch == abbr.ch)
                        abbr.nr = tt->it.abbr.nr + 1;
                tt->next = cr_node(mstr, ari, abbr);
                new_abbr = 1;
        };
 };

 return new_abbr;
}

char *aritobinstr(ari)
arity ari;
{
  /* convert ari (arity) into a string representing its binary value OR */
  /* '*' or '+' */
    if (ari.nr_args == 0) return("0");
    if (ari.nr_args == 1) return("1");
    if (ari.nr_args == 2) return("10");
}

void push(s, nargs)
char *s;
int nargs;
{
arity ari;

  ari.nr_args = nargs;
  if (add_item(s, ari))
    printf("!%c%d:%s=%s\n",abbr.ch, abbr.nr, aritobinstr(ari), s);
  printf("%c%d\n", abbr.ch, abbr.nr);
  fflush(stdout);
}

yyerror(s)
char *s;
{
  extern int lino, pos;
  fprintf(stderr, "syntax error at line %d, pos %d: %s\n", lino, pos, s);
  fclose(stdout);
  fclose(stderr);
  exit(1);
}

int yywrap()
{
  fprintf(stderr, "done\n");
  fclose(stdout);
  fclose(stderr);
  exit(0);
}


main()
{
  extern yyparse();

  if(yyparse())
    yyerror("");
  else
    yywrap();
}
