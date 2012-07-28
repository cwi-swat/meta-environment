; File: settings.ll
; ---------------------------------------------------------------------------- ;
; $Log$
; Revision 1.1  2003/04/15 08:48:25  jurgenv
; * added several specifications recovered via 'software archeology',
;   changed the extensions, but not tested any of them!
;
; Revision 1.1  1992/08/10  08:16:15  tip
; Initial revision
;
; ---------------------------------------------------------------------------- ;
; Display settings

(setq #:origin:pp t )                           ; pretty printing: t or ()
(setq #:origin:show-info () )                   ; show pre-comptd info: t or ()
(setq #:origin:color #:box2ctedit:red )         ; color of selections, choices:
                                                ;   #:box2ctedit:green
                                                ;   #:box2ctedit:red
                                                ;   ()             --- no color
(setq #:origin:font-nr 1 )                      ; font of selections
(setq #:origin:first-term () )                  ; print initial term: t or ()
(setq #:origin:last-term () )                   ; print final term: t or ()
(setq #:origin:redex () )                       ; print redexes: t or ()
(setq #:origin:contractum () )                  ; print contracta: t or ()

; ---------------------------------------------------------------------------- ;
