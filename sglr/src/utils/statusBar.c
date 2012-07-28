/* $Id$ */

/** \file 
 * \ingroup utils
 */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <aterm1.h>

void SG_printDotAndNewLine() {
  if (isatty(fileno(stderr))) { 
    fprintf(stderr, ".\n"); 
  }
} 

void SG_printStatusBar(char *subject, long part, long whole) {
  static char bar[]  = "==============================";
  static char daisy[] = "|/-\\";
  static int len = -1;
  static int is_a_tty = -1;
  static int last_step = 0;
  int step = 0;

  if (is_a_tty == -1) {
    is_a_tty = isatty(fileno(stderr));
    len = strlen(bar);
  }

  if (!is_a_tty) {
    return;
  }

  if (whole == 0) {
    return;
  }

  step = (len*part)/whole;

  if (last_step > step) {
    last_step = 0;
  }

  if (step == 0) {
    return;
  }

  if (last_step != step) {
    fprintf(stderr,"\r%-20s [%-30.*s] %c %ld/%ld (%3d%%)",
	    subject,
	    step,
	    bar,
	    part != whole ? daisy[step & 0x03] : ' ',
	    part,
	    whole,
	    (int)((part*100)/whole));

    last_step = step;
  }

  return;
}
