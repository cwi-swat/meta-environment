; File: aux.ll
; ---------------------------------------------------------------------------- ;
; $Id $
; ---------------------------------------------------------------------------- ;
(setq #:sys-package:colon '#:origin)
; ---------------------------------------------------------------------------- ;
; #:origin:show-subtree : highlight a subtree in a GSE instance.
;
;(de #:origin:show-subtree (GSE path)
;  (let*
;    ( (subtree (#:origin:vtp:navigate (#:GSE:tree GSE) path))
;      (coords (#:GSE:get-coords GSE subtree)) )
;    (#:GSE:show-n-high GSE (car coords) (cadr coords))
;  )
;)
; ---------------------------------------------------------------------------- ;
; #:origin:show-subtrees : highlight a list of subtrees in pp-window.
;
(de #:origin:show-subtrees (vtp-list)
  (#:box2ctedit:clear-all-selections)
  (#:box2ctedit:show-subtrees vtp-list)
; (mapc
;   (lambda (vtp)
;     (print (#:EDB:vtp2str EDB vtp)) )
;   vtp-list
; )
)
; ---------------------------------------------------------------------------- ;
