/*
   Author: Merijn de Jonge (mdejonge@cwi.nl)
   
   $Id$
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <aterm1.h>

#include "asf-interface.h"
#include <PT.h>
#include <SDF.h>
#include <ASF.h>

static char myarguments[] = "hi:m:o:V";
static char* myname;

#define DB {fprintf(stderr, "%d-%s\n", __LINE__, __FILE__);}

#define USAGE "usage:\n" \
              "   normalizer [-h] [-i file] [-o file] [-V]\n" \
              "\n"\
              "where\n"\
              "   -h       displays this help\n"\
              "   -i file  use file as input\n"\
              "   -m name  use name as top module (defaults to Main)\n"\
              "   -o file  write output to file\n"\
              "   -V       display version information\n"\
              "\n\n"\
              "normalizer is a tool which reads as input the asfix "\
                 "representation of an\n"\
              "SDF2 definition and outputs the corresponding normalized "\
                 "definition in\nkernel SDF2 syntax.\n"
              

static void usage()
{
   fprintf( stdout, USAGE );
}

static void version()
{
   fprintf( stdout, "%s version %s\n", myname, VERSION );
}

int main( int argc, char* argv[] )
{
   ATerm bottomOfStack;
   PT_ParseTree term;

   FILE* iofile;
  
   extern char* optarg;
   extern int   optind;
   
   int c;
   
   char* input = NULL;
   char* output = NULL;
   char* top = "Main";
   
   myname = argv[0];
        
   /* Initialize AsFix library functions ans ASF+SDF Compiler functions */
   ATinit(argc, argv, &bottomOfStack);
   SDF_initSDFApi();
   asc_init();
   
   /* parse command line options */
   while( (c = getopt( argc, argv, myarguments ) ) != -1 )
   {
      switch(c)
      {
         case 'h': usage(); exit( 0 );
         case 'i': input = optarg; break;
         case 'm': top = optarg; break;
         case 'o': output = optarg; break;
         case 'V': version(); exit( 0 );
         default: usage(); exit( 1 );
      }
   }
   
   /* Open input (from standard input when "-" was passed as file name) */
   if (input == NULL || strcmp(input, "-") == 0) {
      iofile = stdin;
   }
   else {
      iofile = fopen(input, "r");
   }

   if (iofile == NULL) {
      ATerror("%s: cannot open %s\n", myname, input);
   }

   /* Read input term */
   term = PT_makeParseTreeFromTerm(ATreadFromFile(iofile));

   /* and normalize it */
   term = normalize(top, term);

   /* open output (standard output when "-" was passed as file name */
   if (output == NULL || strcmp(output, "-") == 0) {
      iofile = stdout;
   }
   else {
      iofile = fopen(output, "r");
   }
   
   if (iofile == NULL) {
      ATerror("%s: cannot open %s\n", myname, output);
   }
   
   /* write the normilized term */
   ATwriteToTextFile(PT_makeTermFromParseTree(term), iofile);
   
   exit(0);
         
}
