#include "syn-edit.tif.c"
#include <unistd.h>

char *text[] = {
/*       01234567890123456789  */
/* 1 */ "begin",
/* 2 */ "  x : int;",
/* 3 */ "  if x > 0 then",
/* 4 */ "     x := 3",
/* 5 */ "  fi",
/* 6 */ "end" };

typedef struct focus {
  char * path;
  char * first;
  char * last;
} focus;

focus focustab[] = {
  {"11",   "2.2",  "2.3"},
  {"1",    "2.2",  "2.10"},
  {"21",   "2.6",  "2.9"},
  {"212",  "3.9",  "3.10"},
  {"222",  "4.10", "4.11"},
  {"122",  "4.5",  "4.6"},
  {"22",   "4.5",  "4.11"},
  {"112",  "3.5",  "3.6"},
  {"12",   "3.5",  "3.10"},
  {"2",    "3.2",  "5.15"},
  {"",     "1.0",  "6.15"},
   0
};


focus * mousepoint(int x, int y)
{
  focus *f;
  int fx, fy, lx, ly;

  for( f = &focustab[0]; f->path; f++){
    sscanf(f->first, "%d.%d", &fx, &fy);
    sscanf(f->last, "%d.%d", &lx, &ly);

    if(fx <= x && x <= lx && fy <= y && y <= ly)
      return f;
  }
  return NULL;
}


focus * find(char *path)
{ 
  focus *f;
  for( f = &focustab[0]; f->path; f++){
    if(strcmp(path, f->path) == 0){
      return f;
    }
  }
  return NULL;
}

focus * move_up(char * path)
{
  if(strlen(path) > 0){
    path = &path[1];
    return find(path);
  } else
    return find(path);
}

focus *move_down(char * path)
{ focus *f;
  char new_path[10];
  sprintf(new_path, "1%s", path);
  if((f = find(new_path)))
    return f;
  else
    return find(path);
}

focus *move_next(char * path)
{ focus *f;
  char new_path[10];
  sprintf(new_path, "%s", path);
  new_path[0]++;
  if((f = find(new_path)))
    return f;
  else
    return find(path);
}

char *name_table[20];
int name_max = 0;

int findname(char *name) {
  int i;

  for(i = 0; i < name_max; i++){
    if(strcmp(name, name_table[i]) == 0)
      return i;
  }
  i = name_max++;
  name_table[i] = name;
  return i;
}

focus *current_focus[20];

term *edit(char *filename)
  {
    current_focus[findname(filename)] = find("");
    return TBmake("snd-value(ok)");
  }

term *tree_up(char *filename)
  { focus *f;
    int k;
    k = findname(filename);
    current_focus[k] = f = move_up(current_focus[k]->path);
    return TBmake("snd-value(focus(%s,%s))", f->first, f->last);
  }

term * tree_down(char *filename)
  { focus *f;
    int k;

    k = findname(filename);
    current_focus[k] = f = move_down(current_focus[k]->path);
    return TBmake("snd-value(focus(%s,%s))", f->first, f->last);
  }

term * tree_next(char *filename)
  { focus *f;
    int k;
     
    k = findname(filename);
    current_focus[k] = f = move_next(current_focus[k]->path);
    return TBmake("snd-value(focus(%s,%s))", f->first, f->last);
  }

term *mouse(char *filename, int x, int y)
  { focus *f;
    int k;

    k = findname(filename);
    current_focus[k] = f = mousepoint(x, y);
    return TBmake("snd-value(focus(%s,%s))", f->first, f->last);
  }

void close_editor(char *filename)
  { 

  }

void rec_terminate(term *t)
{
  exit(0);
}

void main(int argc, char *argv[])
{
  TBinit("syn-edit", argc, argv, syn_edit_handler, syn_edit_check_in_sign);
  TBeventloop();
}
