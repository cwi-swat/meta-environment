/*

    ToolBus -- The ToolBus Application Architecture
    Copyright (C) 1998-2000  Stichting Mathematisch Centrum, Amsterdam, 
                             The  Netherlands.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/
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
