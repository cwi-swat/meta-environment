#include "cons.tif.c"

#define MAXBALL 10
#define MAXCONS 10

typedef struct ball_repr
{
  char * name;
  int x;
  int y;
  TBbool changed;
} ball_repr;

typedef enum ckind { c_above, c_left, c_between} ckind;

typedef struct constraint
{
  ckind kind;
  int   b1;
  int b2;
  int b3;
} constraint;

ball_repr balls[MAXBALL];
int nball = -1;

constraint constraints[10];
int ncons = -1;

term *satisfy(void);

int get_index(char *name)
{
  int i;

  for(i = 0; i <= nball; i++)
    if(streq(balls[i].name, name))
      return i;
  return -1;
}

void update(char *name, int x, int y)
{
  int n = get_index(name);

  if(n == -1){
    if(nball == MAXBALL){
      fprintf(stderr, "Too many balls\n");
      return;
    }
    nball++;
    n = nball;
    balls[n].name = name;
    balls[n].changed = TBfalse;
  }
  balls[n].x = x;
  balls[n].y = y;
}

void add_constraint(ckind k, char *nb1, char *nb2, char *nb3)
{
  int b1 = get_index(nb1), b2 = get_index(nb2), b3 = get_index(nb3);

  if(b1 == -1 || b2 == -1 || (k == c_between && b3 == -1))
    return;
  if(ncons == MAXCONS){
      fprintf(stderr, "Too many constraints\n");
      return;
    }
  ncons++;
  constraints[ncons].kind = k;
  constraints[ncons].b1 = b1;
  constraints[ncons].b2 = b2;
  constraints[ncons].b3 = b3;
}

void ball(char *name, char *color, int x, int y)
{
  update(name, x, y);
}

term *move(char *name, int x, int y)
{
  update(name, x, y);
  return satisfy();
}

term *above(char *name1, char *name2)
{    
  add_constraint(c_above, name1, name2, NULL);
  return satisfy();
}

term *left(char *name1, char *name2)
{    
  add_constraint(c_left, name1, name2, NULL);
  return satisfy();
}

term *between(char *name1, char *name2, char *name3)
{    
  add_constraint(c_between, name1, name2, name3);
  return satisfy();
}

void rec_ack_event(term *t)
{
}

void rec_terminate(term *t)
{
  exit(0);
}

void pmove(int k)
{
  fprintf(stderr, "move(%s, %d, %d)\n", balls[k].name, balls[k].x, balls[k].y);
}

term *satisfy()
{
  int i, n = 0, b1, b2, b3, lx, rx, ly, ry, delta = 50;
  TBbool change = TBtrue;
  term *moves = TBmake("[]");
  
  while(change && (n < 20)){
    change = TBfalse;
    n++;
    for(i = 0; i <= ncons; i++){
      switch(constraints[i].kind){
      case c_above:
	b1 = constraints[i].b1;
	b2 = constraints[i].b2;
	if(balls[b1].y > balls[b2].y){
	  int newy = balls[b2].y - delta;
	  balls[b1].y = (newy > 0) ? newy : 0;
	  balls[b1].changed = change = TBtrue;
	}
	continue;
      case c_left:
	b1 = constraints[i].b1;
	b2 = constraints[i].b2;
	if(balls[b1].x >= balls[b2].x){
	  int newx = balls[b2].x - delta;
	  balls[b1].x = (newx > 0) ? newx : 0;
	  balls[b1].changed =  change = TBtrue;
	}
	continue;
      case c_between:
	b1 = constraints[i].b1;
	b2 = constraints[i].b2;
	b3 = constraints[i].b3;
	if(balls[b1].x < balls[b3].x){
	  lx = b1; rx = b3;
	} else {
	  lx = b3; rx = b1;
	}	
	if(balls[b1].y < balls[b3].y){
	  ly = b1; ry = b3;
	} else {
	  ly = b3; ry = b1;
	}	
	if((balls[b2].x < balls[lx].x) || (balls[b2].x > balls[rx].x) ||
	   (balls[b2].y < balls[ly].y) || (balls[b2].y > balls[ry].y)){
	  balls[b2].x = balls[lx].x + (balls[rx].x - balls[lx].x)/2;
	  balls[b2].y = balls[ly].y + (balls[ry].y - balls[ly].y)/2;
	  balls[b2].changed = change = TBtrue;
	}
	continue;
      }
    }
  }
  if(change)
    TBmsg("unstable solution\n");
  for(i = 0; i <= nball; i++)
    if(balls[i].changed){
      balls[i].changed = TBfalse;
      moves = TBmake("[move(%s,%d,%d),%l]",  balls[i].name, balls[i].x, balls[i].y, moves);
    }
/*  TBmsg("moves = %t\n", moves); */
  return TBmake("snd-value(%t)", moves);
}

void main(int argc, char *argv[])
{
  TBinit("cons", argc, argv, cons_handler, cons_check_in_sign);
  TBeventloop();
}
