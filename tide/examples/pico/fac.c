#include "pico-support.h"

PICOPROGRAM("fac.pico");

void
picomain ()
{
  PICONATURAL (input);
  PICONATURAL (output);
  PICONATURAL (repnr);
  PICONATURAL (rep);
  debugstep (8);
  input = 4;
  debugstep (9);
  output = 1;
  debugstep (10);
  while (input - 1)
    {
      debugstep (11);
      rep = output;
      debugstep (12);
      repnr = input;
      debugstep (13);
      while (repnr - 1)
	{
	  debugstep (14);
	  output = output + rep;
	  debugstep (16);
	  repnr = repnr - 1;
	}
      debugstep (18);
      input = input - 1;
    }
  finish ();
}
