/*

    PGEN - the SDF2 parse table generator.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, 
                        The Netherlands. 

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

/*
   Author: Merijn de Jonge (mdejonge@cwi.nl)
   
   $Id$
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <aterm2.h>

#include "asf-interface.h"
#include <SDF.h>
#include <PT.h>
#include <asc-apply.h>
#include <asc-support.h>

#define INITIAL_TABLE_SIZE 8191

static PT_Tree addNormalizeFunction(char *str, PT_ParseTree parseTree)
{
  SDF_ModuleName sdfModuleName = SDF_makeModuleNameUnparameterized(
                               SDF_makeModuleIdWord(str));
  PT_Tree ptModuleName = PT_makeTreeFromTerm(
                           SDF_makeTermFromModuleName(sdfModuleName));
  PT_Tree newTree = NULL;

  if (PT_isValidParseTree(parseTree)) {
    PT_Tree ptSyntax = PT_getParseTreeTree(parseTree);

    newTree = ASC_applyFunction("normalize",
                                "Sdf2-Normalization",
                                "Grammar",
                                2,
                                ptModuleName,
                                ptSyntax);
  }
  else {
    ATerror("addRemoveVarsFunction: not a proper parse tree: %t\n",
              (ATerm) parseTree);

    return (PT_Tree) NULL;
  }

  return newTree;

}                                                       

ATerm normalize(ATerm sdf2term, char* topModule )
{
   PT_ParseTree parseTree = PT_makeParseTreeFromTerm(sdf2term);
   PT_Tree tree = addNormalizeFunction(topModule,parseTree);
   ATerm reduct = innermost(tree);
   PT_ParseTree ksdf = toasfix(reduct); 
   
   return PT_makeTermFromParseTree(ksdf);
}

void asc_init()
{
   ASC_initRunTime(INITIAL_TABLE_SIZE);
   register_all();
   resolve_all();
   init_all();
}
