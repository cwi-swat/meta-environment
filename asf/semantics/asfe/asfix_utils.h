/*
 * utils.h
 *
 * Extra utility functions on asfix that the evaluator uses.
 * This utility module is ment only to be used in evaluator.c
 *
 *
 * $Id$
 */

#ifndef EVALUATOR_UTILS_H
#define EVALUATOR_UTILS_H

extern ATerm tagCurrentRule;

/* This global indicates if whitespace will be saved as much as possible
 * during rewriting.
 */
extern ATbool keep_whitespace;

/* The definition of term equality depends on the choice to
 * keep whitespace or to throw it all away when rewriting.
 */
#define isAsFixEqual(t1,t2) ((keep_whitespace) ? isEqualModuloWhitespace(t1,t2) : ATisEqual(t1,t2))

/* isEqualModuloWhitespace computes equality disregarding any whitespace in the 
 * asfix. Both terms must contain whitespace keywords, but they may be different.
 */
ATbool isEqualModuloWhitespace(ATerm asfix1, ATerm asfix2);

/* skipWhiteSpace. This function moves the list pointer to an 
 * element that is not layout (whitespace or a separator).
 */
ATermList skipWhitespace(ATermList list);

/* skipToEndOfWhitespace. this function moves the list pointer
 * while the pointer is on whitespace.
 */
ATermList skipToEndOfWhitespace(ATermList list);

/* asource. This function asources an asfix term to text and 
 * creates a quoted literal ATerm for it.
 */
ATerm asource(ATerm asfix);

#endif
