/*

    PGEN - the SDF2 parse table generator.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, The Netherlands.

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

#include <stdio.h>
#include <unistd.h>  

/*{{{ statistic operations */

#define PT_COND_STRING(s)   (s?s:"") 

extern ATbool statisticsMode;

#define IF_STATISTICS(s)     if(statisticsMode) {s;}
double PT_Timer(void);

FILE *PT_OpenLog(char *program, char *fnam);
FILE *PT_log(void);
void  PTcloseLog(void);   

/*}}}  */  
