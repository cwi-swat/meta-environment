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

#ifdef USE_TIDE

/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <tcl.h>
#include <tk.h>
#include <aterm2.h>

#include "debug-adapter.tif.h"

/*}}}  */
/*{{{  defines */

#define STATE_STOPPED  0
#define STATE_RUNNING  1

#define MAX_RULES   1024

#define PORT_INITIAL      0
#define PORT_STEP         1
#define PORT_LOCATION     2
#define PORT_VAR_ACCESS   3
#define PORT_EXPR_CHANGED 4
#define PORT_METHOD_ENTRY 5
#define PORT_METHOD_EXIT  6
#define PORT_STOPPED      7
#define PORT_STARTED      8
#define PORT_EXCEPTION    9
#define NR_PORT_TYPES     10

/*}}}  */
/*{{{  types */

typedef struct
{
	ATbool enabled;
	ATerm owner;
	ATerm type;
	ATerm port;
	int porttype;
	ATerm cond;
	ATerm act;
} Rule;

typedef struct
{
	char filename[BUFSIZ];
	int start_line;
	int start_col;
	int end_line;
	int end_col;
} cpe_struct;

/*}}}  */
/*{{{  globals */

extern char *script; /* from tcltk-adapter.c */

ATbool use_tide  = ATfalse;
int tide_cid  = -1;
static ATbool porttrace = ATfalse;
static Tcl_Interp *tide_interp;

static char the_pid[BUFSIZ];

static int state = STATE_STOPPED;

static cpe_struct cpe = {"", -1, -1, -1, -1};

Rule rules[MAX_RULES] = { { ATfalse, NULL, NULL, NULL, -1, NULL, NULL } };
int  nr_enabled_rules[NR_PORT_TYPES] = { 0 };
int  enabled_rules[NR_PORT_TYPES][MAX_RULES];

/*}}}  */

/*{{{  static int get_porttype(ATerm port) */

/**
	* Determine the type of the port
	*/

static int get_porttype(ATerm port)
{
	AFun fun = ATgetAFun((ATermAppl)port);
	char *name = ATgetName(fun);

	if(strcmp(name, "step") == 0)
		return PORT_STEP;

	if(strcmp(name, "location") == 0)
		return PORT_LOCATION;

	if(strcmp(name, "var-access") == 0)
		return PORT_VAR_ACCESS;

	if(strcmp(name, "expr-changed") == 0)
		return PORT_EXPR_CHANGED;

	if(strcmp(name, "method-entry") == 0)
		return PORT_METHOD_ENTRY;

	if(strcmp(name, "method-exit") == 0)
		return PORT_METHOD_EXIT;

	if(strcmp(name, "stopped") == 0)
		return PORT_STOPPED;

	if(strcmp(name, "started") == 0)
		return PORT_STARTED;

	if(strcmp(name, "exception") == 0)
		return PORT_EXCEPTION;

	ATabort("unknown port: %t\n", port);
	return -1;
}

/*}}}  */

/*{{{  void disable_rule(int conn, char *pid, ATerm owner, int rid) */

void disable_rule(int conn, char *pid, ATerm owner, int rid)
{
	int porttype, last, i;

	if (!rules[rid].enabled) {
		ATwarning("** Warning, disabling already disabled rule: %d\n", rid);
		return;
	}

	rules[rid].enabled = ATfalse;
	porttype = rules[rid].porttype;
	last = --nr_enabled_rules[porttype];
	for(i=0; i<=last; i++)
		if(enabled_rules[porttype][i] == rid)
			break;
	if (i > last)
		ATabort("No such rule: %d\n", rid);

	enabled_rules[porttype][i] = enabled_rules[porttype][last];
}

/*}}}  */
/*{{{  void enable_rule(int conn, char *pid, ATerm owner, int rid) */

void enable_rule(int conn, char *pid, ATerm owner, int rid)
{
	int porttype, last;

	if (rules[rid].enabled) {
		ATwarning("** Warning, enabling already enabled rule: %d\n", rid);
		return;
	}

	porttype = rules[rid].porttype;
	last = nr_enabled_rules[porttype]++;
	
	fprintf(stderr, "enabled rule %d (porttype=%d), count=%d\n",
			rid, porttype, nr_enabled_rules[porttype]);

	enabled_rules[porttype][last] = rid;

	rules[rid].enabled = ATtrue;
}

/*}}}  */
/*{{{  void modify_rule(conn, char *pid, owner, rid, port, cond, act) */

void modify_rule(int conn, char *pid, ATerm owner, int rid, 
								 ATerm port, ATerm cond, ATerm act)
{
	ATbool isActive = rules[rid].enabled;

	if(isActive)
		disable_rule(conn, pid, owner, rid);
	
	rules[rid].port = port;
	rules[rid].cond = cond;
	rules[rid].act  = act;

	if(isActive)
		enable_rule(conn, pid, owner, rid);
}

/*}}}  */
/*{{{  ATerm create_rule(conn, char *pid, owner, type, port, cond, act) */

ATerm create_rule(int conn, char *pid, ATerm owner, ATerm type, 
									ATerm port, ATerm cond, ATerm act)
{
	int rid;

	for(rid=0; rules[rid].port && rid < MAX_RULES; rid++)
		;
	if(rid >= MAX_RULES)
		ATerror("maximum number of rules (%d) exceeded.\n", MAX_RULES);

	rules[rid].enabled = ATfalse;
	rules[rid].owner = owner;
	rules[rid].type  = type;
	rules[rid].port  = port;
	rules[rid].cond  = cond;
	rules[rid].act   = act;

	rules[rid].porttype = get_porttype(port);

	ATprotect(&rules[rid].owner);
	ATprotect(&rules[rid].type);
	ATprotect(&rules[rid].port);
	ATprotect(&rules[rid].cond);
	ATprotect(&rules[rid].act);
	
	/* enable_rule(conn, pid, owner, rid); */

	return ATmake("snd-value(rule-created(<str>,<term>,<int>,"
								"<term>,<term>,<term>,<term>))",
								pid, owner, rid, type, port, cond, act);
}

/*}}}  */
/*{{{  void delete_rule(int conn, char *pid, ATerm owner, int rid) */

void delete_rule(int conn, char *pid, ATerm owner, int rid)
{
	int i, porttype;

	porttype = rules[rid].porttype;

	if(rules[rid].enabled) {
		int last = --nr_enabled_rules[porttype];
		for(i=0; i<=last; i++) {
			if(enabled_rules[porttype][i] == rid) {
				enabled_rules[porttype][i] = enabled_rules[porttype][last];
				break;
			}
		}
	}

	ATunprotect(&rules[rid].act);
	ATunprotect(&rules[rid].cond);
	ATunprotect(&rules[rid].port);
	ATunprotect(&rules[rid].type);
	ATunprotect(&rules[rid].owner);

	rules[rid].owner = NULL;
	rules[rid].type  = NULL;
	rules[rid].port  = NULL;
	rules[rid].cond  = NULL;
	rules[rid].act   = NULL;
}

/*}}}  */
/*{{{  void rec_ack_event(int conn, ATerm evt) */

void rec_ack_event(int conn, ATerm evt)
{
}

/*}}}  */
/*{{{  void rec_terminate(int conn, ATerm msg) */

void rec_terminate(int conn, ATerm msg)
{
	exit(0);
}

/*}}}  */
/*{{{  void tcl_tide_handler(ClientData data, int mask) */

void tcl_tide_handler(ClientData data, int mask)
{
  if(ATBpeekOne(tide_cid))
    ATBhandleOne(tide_cid);
}

/*}}}  */
/*{{{  int handle_tide_error(Tcl_Interp *interp, code, msg, info) */

int handle_tide_error(Tcl_Interp *interp, char *code, char *msg, char *info)
{
  if(use_tide) {
    /*dap_activate_rules(0, TB_make("[exception,at,error,<str>,<str>]", msg, info));*/
    /*return 1; For now, we also want to print the error. */
  }
  return 0;
}

/*}}}  */

static void generate_watchpoint(int rid, ATerm watchpoint)
{
	ATBpostEvent(tide_cid, ATmake("watchpoint(<term>,<str>,<int>,<term>)",
						rules[rid].owner, the_pid, rid, watchpoint));
}

static ATerm eval_expr(ATerm expr)
{
	ATerm eval;

	if (ATgetType(expr) == AT_LIST) {
		ATermList list   = (ATermList) expr;
		ATermList result = ATempty;
		while (!ATisEmpty(list)) {
			ATerm res = eval_expr(ATgetFirst(list));
			list = ATgetNext(list);
			if (!ATisEqual(res, ATparse("true")))
				result = ATappend(result, res);
		}
		if (ATisEmpty(result))
			return ATparse("true");
		return (ATerm) result;
	}
	
	if (ATisEqual(expr, ATparse("true")))
		return expr;
	
	if (ATisEqual(expr, ATparse("false")))
		return expr;
	
	if (ATisEqual(expr, ATparse("break"))) {
		state = STATE_STOPPED;
		return ATparse("true");
	}

	if (ATisEqual(expr, ATparse("resume"))) {
		state = STATE_RUNNING;
		return ATparse("true");
	}

	if (ATisEqual(expr, ATparse("cpe"))) {
		if (cpe.filename == NULL || cpe.filename[0] == '\0')
			return ATparse("cpe(unknown)");
		else
			return ATmake("cpe(src-line,<str>,<int>)",
						   cpe.filename, cpe.start_line);
	}
	
	if (ATisEqual(expr, ATparse("state"))) {
		if (state == STATE_RUNNING)
			return ATparse("running");
		else
			return ATparse("stopped");
	}
	
	if (ATmatch(expr, "eval(<term>)", &eval)) {
		char tcl_script[BUFSIZ];
		sprintf(tcl_script, "expr %s", ATgetName(ATgetAFun((ATermAppl)eval)));
		if (Tcl_Eval(tide_interp, tcl_script) == TCL_OK)
			return ATmake("value(<str>)", Tcl_GetStringResult(tide_interp));
		else
			return ATmake("error(<str>)", Tcl_GetStringResult(tide_interp));
	}
	
	return ATmake("unknown-expression(<term>)", expr);
}

static void activate_rule(int rid)
{
	ATerm cond_result, act_result;

   	cond_result = eval_expr(rules[rid].cond);
	if (ATisEqual(cond_result, ATparse("true")))
		act_result = eval_expr(rules[rid].act);
	
	if (ATisEqual(act_result, ATparse("true")))
		return;

	if (ATgetType(act_result) == AT_LIST) {
		ATermList list = (ATermList) act_result;
		while(!ATisEmpty(list)) {
			generate_watchpoint(rid, ATgetFirst(list));
			list = ATgetNext(list);
		}
	} else
		generate_watchpoint(rid, act_result);
}

static void activate_rules(int porttype)
{
	int i;
	
	for(i=0;i<nr_enabled_rules[porttype]; i++)
		activate_rule(enabled_rules[porttype][i]);
}

/*{{{  ATerm evaluate(int conn, char *pid, ATerm expr) */

ATerm evaluate(int conn, char *pid, ATerm expr)
{
	return ATmake("snd-value(evaluated(<str>,<term>,<term>))",
				  pid, expr, eval_expr(expr));
}

/*}}}  */

/*{{{  int Tcl_TBtide(ClientData data, Tcl_Interp *interp, argc, argv[]) */

/*
	Sample code to determine stackdepth in Tcl.
  case ES_STEP_OVER:
  	Tcl_Eval(interp, "info level");
	level = atoi(interp->result);
	if(level <= dap_get_stop_level(0, 0))
		dap_change_exec_state(0, ES_STOP);
	break;
*/

int Tcl_TBtide(ClientData data, Tcl_Interp *interp, int argc, char *argv[])
{
	ATerm port;

	if(argc != 3) {
		/* DEPRECATED: interp->result = "TBtide expects 3 arguments"; */
		Tcl_SetResult(interp, "TBtide expects 3 arguments", TCL_STATIC);
		return TCL_ERROR;
	}
  
	fprintf(stderr, "argv[0]: %s\n", argv[0]);
	fprintf(stderr, "argv[1]: %s\n", argv[1]);
	fprintf(stderr, "argv[2]: %s\n", argv[2]);

	port = ATparse(argv[1]);
  
	if (ATgetType(port) != AT_LIST)
		ATwarning("Illegal port: %t\n", port);
	else {
		int porttype = get_porttype(ATgetFirst((ATermList)port));

		if(porttrace)
			ATprintf("port: %t\n", port);
	  
		if (porttype == PORT_LOCATION) {
			ATerm info_elt = ATelementAt((ATermList)port, 2);
			strcpy(cpe.filename, ATgetName(ATgetAFun((ATermAppl)info_elt)));
			info_elt = ATelementAt((ATermList)port, 3);
			cpe.start_line = ATgetInt((ATermInt)info_elt);
			info_elt = ATelementAt((ATermList)port, 4);
			cpe.start_col = ATgetInt((ATermInt)info_elt);
			info_elt = ATelementAt((ATermList)port, 5);
			cpe.end_line = ATgetInt((ATermInt)info_elt);
			info_elt = ATelementAt((ATermList)port, 6);
			cpe.end_col = ATgetInt((ATermInt)info_elt);
		}
	  
		if(use_tide) {
			activate_rules(porttype);
			activate_rules(PORT_STEP);
			
			if (state == STATE_STOPPED)
				activate_rules(PORT_STOPPED);

			if (state == STATE_STOPPED) {
				while(state == STATE_STOPPED)
					ATBhandleOne(tide_cid);
				activate_rules(PORT_STARTED);
			}
		}
	}

	if(strlen(argv[2]) != 0) {
		fprintf(stderr, "executing: %s\n", argv[2]);
		return Tcl_Eval(interp, argv[2]);
	}

	return TCL_OK;
}

/*}}}  */
/*{{{  int Tide_Init(Tcl_Interp *interp) */

int Tide_Init(Tcl_Interp *interp)
{
  tide_interp = interp;

  Tcl_CreateCommand(interp, "TBtide", Tcl_TBtide, NULL, NULL);

  if(use_tide || porttrace) {
    if(Tcl_EvalFile(interp, LIBDIR "/tide.tcl") != TCL_OK) {
      Tcl_AddErrorInfo(interp, "while loading file " LIBDIR "/tide.tcl\n");
      return TCL_ERROR;
    }
  }

  if(use_tide)
    Tcl_CreateFileHandler(tide_cid, TCL_READABLE, tcl_tide_handler, NULL);

  return TCL_OK;
}

/*}}}  */

#endif
/*{{{  void init_tide_support(int argc, char *argv[]) */

void init_tide_support(int argc, char *argv[])
{
#ifdef USE_TIDE
  int i, port = 9500;
  char *host = NULL; 

  for(i=1; i<argc; i++) {
    if(streq(argv[i], "-tide"))
      use_tide = ATtrue;
    if(streq(argv[i], "-porttrace"))
      porttrace = ATtrue;
    if(streq(argv[i], "-TB_TIDE_PORT")) {
      port = atoi(argv[++i]);
      use_tide = ATtrue;
    }
    if(streq(argv[i], "-TB_TIDE_HOST")) {
      host = argv[++i];
      use_tide = ATtrue;
    }
  }

  if(use_tide) {
		tide_cid = ATBconnect("debug-adapter", host, port,
													debug_adapter_handler);
		if (script != NULL)
			strcpy(the_pid, script);
		else
			sprintf(the_pid, "Tcl/Tk-%d", (int) getpid());

		ATBwriteTerm(tide_cid,
					 ATmake("snd-event(process-created(<str>))", the_pid));
  }

/*}}}  */
#endif
}
