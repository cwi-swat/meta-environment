
/* go.c
   Jan Kort
   8912041
*/
#include "string.h"
#include "go.tif.c"

#define SIZE 19

#define EMPTY -1
#define BLACK 0
#define WHITE 1

#define NO_ID -1

struct hist_struct {
  int row;
  int col;
  int color;
};

struct game_struct {
  int board[SIZE+1][SIZE+1]; /* 1..19 x 1..19                */
  struct hist_struct history[1000];
  int black;                 /* Pid of black player or NO_ID */
  int white;                 /* Pid of white player or NO_ID */
  int turn;                  /* Who's turn: BLACK or WHITE   */
} game;

int movenr; /* Add a move number to each move */

int check5(int row, int col, int color) {
int cnt, i, j;

/* check for horizontal row of 5 or more */
  cnt = 1;
  for (j = col+1; j <= 19; j++)
    if (game.board[row][j] == color) cnt++;
    else break;
  if (cnt >= 5) return 1;

/* check for vertical row of 5 or more */
  cnt = 1;
  for (i = row+1; i <= 19; i++)
    if (game.board[i][col] == color) cnt++;
    else break;
  if (cnt >= 5) return 1;

/* check for left top to right bottom diagonal of 5 or more stones */
  cnt = 1;
  for (i = row+1, j = col+1 ; (i <= 19) && (j <= 19) ; i++, j++)
    if (game.board[i][j] == color) cnt++;
    else break;
  if (cnt >= 5) return 1;

/* check for right top to left bottom diagonal of 5 or more stones */
  cnt = 1;
  for (i = row-1, j = col+1 ; (i >= 1) && (j <= 19) ; i--, j++)
    if (game.board[i][j] == color) cnt++;
    else break;
  if (cnt >= 5) return 1;

  return 0;
}

int wincolor ( void ) {
int row, col, color;
  for (row = 1; row <= 19; row++)
    for (col = 1; col <= 19; col++) {
      color = game.board[row][col];
      if (color != EMPTY) if (check5(row, col, color)) return color;
    }
  return EMPTY;
}

term *winner( void ) {
int color;
  color = wincolor();
  if (color != EMPTY) return TBmake("snd-value(winner(%d))", color);
  else return TBmake("snd-value(nowinner)");
}

void init_board()
{
  int x,y;
  for (x = 1; x <= 19; x++)
    for (y = 1; y <= 19; y++)
      game.board[x][y] = EMPTY;
  game.black = NO_ID;
  game.white = NO_ID;
  game.turn  = BLACK;
  movenr = 1;
}

term *getmoves( void ) {
int row, col, color;
int i;
char list[2000];
char tmp[256];
term *move;
term *moves;
  strcpy(list, "[");
  for (i = 1; i < movenr; i++) {
    row = game.history[i].row;
    col = game.history[i].col;
    color = game.history[i].color;
    move = TBmake("[%d,%d,%d,%d]", i, row, col, color);

    sprintf(tmp, "[%d,%d,%d,%d]", i, row, col, color);
    if (i > 1) strcat(list, ",");
    strcat(list, tmp);
  }
  strcat(list, "]");
  moves = TBmake(list);
/*  TBprintf(stdout, "moves = %t\n", moves);*/
  return TBmake("snd-value(moves(%t))", moves);
}

term *place(int pid, int row, int col) {
term *move;
  if (((pid == game.black) && (game.turn == BLACK)) ||
      ((pid == game.white) && (game.turn == WHITE))) {
    if (game.board[row][col] == EMPTY) {
      game.board[row][col] = game.turn;
      game.history[movenr].row = row;
      game.history[movenr].col = col;
      game.history[movenr].color = game.turn;
      move = TBmake("[%d,%d,%d,%d]", movenr, row, col, game.turn);
      game.turn = (game.turn == BLACK) ? WHITE : BLACK;
      movenr++;
      return TBmake("snd-value(ok(%t))", move);
    } else {
      return TBmake("snd-value(error(0))");
    }
  } else {
    return TBmake("snd-value(error(1))");
  }
}

term *playercolor(int pid) {
  if (game.black == pid) return TBmake("snd-value(color(0))");
  if (game.white == pid) return TBmake("snd-value(color(1))");
  return TBmake("snd-value(nocolor)");
}

/* Assign a color to a player */
void assigncolor(int pid) {
  if (game.black == NO_ID) {
    game.black = pid;
  } else if (game.white == NO_ID) {
    game.white = pid;
  } else {
  }
}

/* Player quits the game, remove him from the game structure so someone
   else can take his place. */
void playerquit(int pid) {
  if (pid == game.black) game.black = NO_ID;
  if (pid == game.white) game.white = NO_ID;
}

void rec_terminate(term *t)
{
  exit(0);
}

void main(int argc, char *argv[])
{
  extern term_list *tool_in_sign, *tool_out_sign;
  term *trm;

  TBinit("go", argc, argv, go_handler, go_check_in_sign);

  init_board();

  TBeventloop();
}

