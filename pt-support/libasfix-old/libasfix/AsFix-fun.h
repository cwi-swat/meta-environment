/*

    AsFix -- The AsFix (ASF+SDF Prefix) library
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

   $Id$
*/
/* Definition file for AsFix
 * Currently, this file has been written by hand, but it can easily
 * be generated automatically from AsFix.gram
 */


#define p_sort_chars           0
#define p_sym_chars            0
#define p_iter_chars           0
#define p_sep_chars            0

#define p_module_filename      2
#define p_module_sections      4
#define p_module_equations     6
#define p_module_abbrevs       8

#define p_iter_sym             0
#define p_iter_iter            2
#define p_itersep_sym          2
#define p_itersep_sep          4
#define p_itersep_iter         8

#define p_prod_module_name     0
#define p_prod_syms            2
#define p_prod_sym             6
#define p_prod_attrs           8
#define p_imports_ids          2
#define p_var_sym              1
#define p_meta_var_sym         1
#define p_lex_sym              1
#define p_appl_prod            0
#define p_appl_args            2
#define p_sappl_name           0
#define p_list_sym             0
#define p_list_w               1
#define p_list_elems           2
#define p_ceq_equ_module_name  0
#define p_ceq_when_module_name 0
#define p_ceq_impl_module_name 0

#define p_term_name            0
#define p_term_filename        2
#define p_term_id              4
#define p_term_term            6
#define p_term_abbrevs         8
#define p_term_w1              1
#define p_term_w2              3
#define p_term_w3              5

#define p_prod_skel_syms       0
#define p_prod_skel_prod       2

#define p_parsetree_amb_cnt    1

#define FARG(t,p) list_index(fun_args(t),p+1)
