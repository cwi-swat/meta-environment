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
#include "toolbus.h"
#include "terms.h"
#include "env.h"

#define ENVDB(x)

env *assign(var *v, term *t, env *e)
{
  register env *e1;
  register sym_idx sym = var_sym(v);

  ENVDB(TBmsg("assign(%t,%t,%t)\n", v, t, e);)
  assert(is_env(e));
  for(e1 = e; e1; e1 = env_next(e1)){
    if(sym == env_sym(e1)){
      env_val(e1) = t;
      return e;
    }
  }
  e1 = mk_env(v, t, NULL);
  env_next(e1) = e;

  ENVDB(TBmsg("assign returns: %t\n", e1);)
  return e1;
}

env *update(register env *e, register env *u)
{ 
  for( ; u; u = env_next(u)){
    e = assign(env_var(u), env_val(u), e);
  }
  return e;
}

term *value(var *v, env *e)
{
  register env *e1;
  register sym_idx sym = var_sym(v);

  ENVDB(TBmsg("value of %t in %t\n", v, e);)

  for(e1 = e; e1; e1 = env_next(e1)){  
    if(sym == env_sym(e1)){
      register term *val = env_val(e1);
      ENVDB(TBmsg("val = %t\n", val));
      return val;
    }
  }
  ENVDB(TBmsg("val = %t\n", v));
  return v;
}

term *substitute(term *, env *);

env *create_env(term_list *vars, const char *pname,
                term_list *terms, env *parent_env)
{
  register env *e = parent_env;

  assert(is_list(vars));
  assert(is_list(terms));

  ENVDB(TBmsg("create_env(%t, %t, %t)\n", vars, terms, parent_env);)

  for( ; vars ; vars = next(vars)){
    if(!terms)
      err_fatal("create_env -- too few actual parameters for process %s\n", pname);
    e = mk_env(first(vars), substitute(first(terms), parent_env), e);
    terms = next(terms);
  }
  if(terms)
    err_fatal("create_env -- too many actual parameters for process %s\n", pname);

  ENVDB(TBmsg("create_env returns: %t\n", e);)
  return e;
}

env *undefine(register term_list *vars, env *parent_env)
{
  register env *e = parent_env, *e1, *preve;

  ENVDB(TBmsg("### undefine: %t in %t\n", vars, parent_env);)
  for( ; vars; vars = next(vars)){
    for(preve = e1 = e; e1; preve = e1, e1 = env_next(e1)){
      if(var_sym(first(vars)) == env_sym(e1)){
	if(e1 == e){
	  e = env_next(e1);
	} else {
	  env_next(preve) = env_next(e1);
	}
	break;
      }
    }
  }
  ENVDB(TBmsg("### undefine returns: %t\n", e);)
  return e;
}

env *define(register term_list *vars, env *parent_env)
{
  ENVDB(TBmsg("@@@@ define %t in %t\n", vars, parent_env));
  for( ; vars; vars =  next(vars)){
    parent_env = mk_env(first(vars), Undefined, parent_env);
  }
  ENVDB(TBmsg("@@@@ define returns: %t\n", parent_env));
  return parent_env;
}


void init_env(void)
{
}
