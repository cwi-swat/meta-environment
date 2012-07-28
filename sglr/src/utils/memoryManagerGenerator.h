/* $Id$ */

/** \file 
 * \ingroup utils
 */

#ifndef __MEMORY_MANAGER_H__
#define __MEMORY_MANAGER_H__

#include <string.h>
#include <stdlib.h>

/** 
 * Generates a type specialized memory manager wrapping calls to calloc. 
 * The design patterns used here are Factory and Prototype. The generated 
 * malloc function is a factory for certain kinds of objects. The factory 
 * preallocates a #preallocSize number of objects, and returns a pointer to the 
 * first. When an object is returned to the manager using the free function,
 * it is stored in a linked list of reusable objects.
 *
 * \pre the struct you pass in must contain at least one pointer
 * to its own struct type. The name of this field is given to the
 * GENERATE_MEMORY_MANAGER as #next.
 *
 * This code is fully buzzword compliant:
 * <ul>
 * <li> generics </li>
 * <li> template based meta programming </li>
 * <li> factory </li>
 * <li> generative programming </li>
 * <li> type safe </li>
 * </ul>
 * 
 * \param type the name used for the generated functions
 * \param structName the name of the struct type to allocate
 * \param next the name of the field in the struct that is a pointer to its own 
 * struct type
 * \param preallocSize the number of objects to allocate each time malloc is 
 * called
 * 
 * \return a pointer to the first element of the allocated memory.
 */
#define GENERATE_MEMORY_MANAGER(type,structName,next,preallocSize) \
static type new_##type##_pool;\
static type reuse_##type##_pool;\
static void free##type(type p)\
{\
  memset(p, 0, sizeof(struct structName));\
  p->next = (type) reuse_##type##_pool;\
  reuse_##type##_pool = p;\
}\
static type malloc##type(int *isNew) \
{\
  type tmp = NULL;\
  *isNew = 0;\
\
  if (reuse_##type##_pool != NULL) {\
    tmp = reuse_##type##_pool;\
    reuse_##type##_pool = (reuse_##type##_pool)->next;\
    tmp->next = NULL;\
    return tmp;\
  }\
\
  if (new_##type##_pool == NULL) {\
    struct structName *pool;\
    int i;\
\
    pool = calloc(preallocSize, sizeof(struct structName));\
\
    for (i=0; i<preallocSize-1; i++) {\
      pool[i].next = pool+i+1;\
    }\
    pool[i].next = NULL;\
    new_##type##_pool = pool;\
  }\
\
  tmp = new_##type##_pool;\
  new_##type##_pool = (new_##type##_pool)->next;\
  tmp->next = NULL;\
  *isNew = 1;\
\
  return tmp;\
}

#endif /* __MEMORY_MANAGER_H__ */
