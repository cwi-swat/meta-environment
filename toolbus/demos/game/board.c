#include "board.tif.c"

#define MAXSQUARE 16

typedef enum player {empty, playerA, playerB} player;

char *board[MAXSQUARE][MAXSQUARE];

int max = MAXSQUARE;

void init_board()
{
  int i, j;
  for(i = 0; i < max; i++)
    for(j = 0; j < max; j++)
      board[i][j] = NULL;
}

void rec_terminate(term *trm)
{
  exit(0);
}

term *push(char *p, int row, int col)
{
  if(row < 0 || row >= max || col < 0 || col >= max)
    return TBmake("snd-value(error(\"illegal move\"))");
  board[row][col] = p;
  return TBmake("snd-value(ok)");
}

void main(int argc, char *argv[])
{
  int i = 0;

  while(i < argc){
    if(streq(argv[i], "-size")){
      max = atoi(argv[i+1]);
      break;
    }
    i++;
  }
  TBinit("board", argc, argv, board_handler, board_check_in_sign);
  TBeventloop();
}
