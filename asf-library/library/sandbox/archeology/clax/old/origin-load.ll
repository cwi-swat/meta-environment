; Loadfile for origin functions.
; ---------------------------------------------------------------------------- ;
; $Log$
; Revision 1.3  2006/03/08 13:24:28  jurgenv
; * merged first-class layout
; * added definition of whitespace language
;
; Revision 1.1.12.1  2006/03/06 12:39:12  jurgenv
; * imported changes from trunk on the first-class-layout branch
;
; Revision 1.2  2005/12/15 12:16:04  kooiker
;  * library/sandbox/archeology/clax/{old,origins}/aux.ll
;    - renamed to auxiliary.ll because on Windows and thus Cygwin filenames are
;      not allowed to be called aux.*, prn.*, con.* etc.
;
; Revision 1.1  2003/04/15 08:48:24  jurgenv
; * added several specifications recovered via 'software archeology',
;   changed the extensions, but not tested any of them!
;
; Revision 1.3  1992/08/19  14:19:40  tip
; *** empty log message ***
;
; Revision 1.2  1992/08/14  13:48:51  tip
; EQM hooks.
;
; Revision 1.1  1992/08/10  08:13:35  tip
; Initial revision
;
; ---------------------------------------------------------------------------- ;
; Load the origins.

(print "Loading origin functions.")
(loadfile "EDBinterface.ll" t)
(loadfile "EDBcontrol.ll" t)
(loadfile "precompute.ll" t)
(loadfile "interface.ll" t)
(loadfile "origin.ll" t)
(loadfile "propagate.ll" t)
(loadfile "auxiliary.ll" t)

; ---------------------------------------------------------------------------- ;
; Load the LeLisp sets:

(unless (typefn 'union)
  (libload sets))

; ---------------------------------------------------------------------------- ;
; Load the pretty printer:

(print "Loading the PP.")
(loadmodule 'contrib/figue/gfxobj () t)
(loadmodule 'centaur/sources/PP () t)
(loadfile "box2ctedit.ll" t)

; ---------------------------------------------------------------------------- ;
; Load the settings:

(print "Loading Settings.")
(loadfile "settings.ll" t)

; ---------------------------------------------------------------------------- ;
; define EQMhook:

(#:EQM:defhook origin #:origin:precompute)

; ---------------------------------------------------------------------------- ;
; Compile origin code.

;(compile-all-in-core)
