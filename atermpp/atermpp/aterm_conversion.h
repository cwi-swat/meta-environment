// ======================================================================
//
// Copyright (c) 2004 Wieger Wesselink
//
// ----------------------------------------------------------------------
//
// file          : atermpp/aterm_conversion.h
// date          : 12/06/04
// version       : 0.2
//
// author(s)     : Wieger Wesselink  <J.W.Wesselink@tue.nl>
//
// ======================================================================

#ifndef ATERM_CONVERSION_H
#define ATERM_CONVERSION_H

/** @file
  * This file contains utility functions for pointer conversions between
  * different types of ATerm pointers.
  */

namespace { // unnamed namespace

  inline
  ATermList void2list(void* t)
  { return reinterpret_cast<ATermList>(t); }
  
  inline
  const ATermList void2list(const void* t)
  { return reinterpret_cast<ATermList>(const_cast<void*>(t)); }
  
  inline
  void* list2void(ATermList l)
  { return reinterpret_cast<void*>(l); }
  
  // --- appl ---
  inline
  ATermAppl void2appl(void* t)
  { return reinterpret_cast<ATermAppl>(t); }
  
  inline
  const ATermAppl void2appl(const void* t)
  { return reinterpret_cast<ATermAppl>(const_cast<void*>(t)); }
  
  inline
  void* appl2void(ATermAppl l)
  { return reinterpret_cast<void*>(l); }
  
  // --- real ---
  inline
  ATermReal void2real(void* t)
  { return reinterpret_cast<ATermReal>(t); }
  
  inline
  const ATermReal void2real(const void* t)
  { return reinterpret_cast<ATermReal>(const_cast<void*>(t)); }
  
  inline
  void* real2void(ATermReal l)
  { return reinterpret_cast<void*>(l); }
  
  // --- blob ---
  inline
  ATermBlob void2blob(void* t)
  { return reinterpret_cast<ATermBlob>(t); }
  
  inline
  const ATermBlob void2blob(const void* t)
  { return reinterpret_cast<ATermBlob>(const_cast<void*>(t)); }
  
  inline
  void* blob2void(ATermBlob l)
  { return reinterpret_cast<void*>(l); }
  
  // --- int  ---
  inline
  ATermInt void2int(void* t)
  { return reinterpret_cast<ATermInt>(t); }
  
  inline
  const ATermInt void2int(const void* t)
  { return reinterpret_cast<ATermInt>(const_cast<void*>(t)); }
  
  inline
  void* int2void(ATermInt l)
  { return reinterpret_cast<void*>(l); }

  // --- place_holder  ---
  inline
  ATermPlaceholder void2place_holder(void* t)
  { return reinterpret_cast<ATermPlaceholder>(t); }

} // unnamed namespace

#endif // ATERM_CONVERSION_H
