; File: propagate.ll
; ---------------------------------------------------------------------------- ;
; $Log$
; Revision 1.1  2003/04/15 08:48:24  jurgenv
; * added several specifications recovered via 'software archeology',
;   changed the extensions, but not tested any of them!
;
; Revision 1.3  1992/08/19  14:19:51  tip
; unsharing bug fixed.
;
; Revision 1.2  1992/08/10  12:26:41  tip
; sharing probleem opgelost
;
; Revision 1.1  1992/08/10  08:15:27  tip
; Initial revision
;
; ---------------------------------------------------------------------------- ;
(setq #:sys-package:colon '#:origin)
; ---------------------------------------------------------------------------- ;
(de :propagate-symbol (tree1 vtp1 pathlist1 tree2 vtp2 pathlist2 bindings)
  (let
    ( abs-path1 abs-path2 )
    (mapc
      (lambda (p1)
        (mapc
          (lambda (p2)
            (setq abs-path1 (#:origin:abs-path vtp1 p1 bindings))
            (setq abs-path2 (#:origin:abs-path vtp2 p2 bindings))
            (#:origin:join
              (#:origin:tree:navigate tree2 abs-path2)
              (#:origin:get (#:origin:tree:navigate tree1 abs-path1)) )
          )
          pathlist2
        )
      )
      pathlist1
    )
  )
)
; ---------------------------------------------------------------------------- ;
(de :propagate-to-bindings (tree vtp pathlist bindings)
  (let
    ( var var-struct bin abs-path ) 
 
    (setq var (#:origin:vtp:navigate vtp (car pathlist)))
    (setq var-struct (cons (#:SDFimpl:var:name var) (#:SDFimpl:var:phylum var)))
    (setq bin (cassoc var-struct bindings))

    (selectq (#:SDFimpl:var:class var)

; Not a list variable => binding is a tree

       ({tree}
         (mapc
           (lambda (rel-path)
             (setq abs-path (#:origin:abs-path vtp rel-path bindings))
             (:propagate-rec (#:origin:tree:navigate tree abs-path) bin)
           )
           pathlist
         )
       )
 
;; List variable => binding is a list-var struct
 
       ({sublist}
         (mapc
           (lambda (rel-path)
             (let
               ( (len (#:EQM:list-var:length bin))
                 (ptr2 (#:EQM:list-var:term-ptr bin))
                 (abs-path (#:origin:abs-path vtp rel-path bindings))
                 ptr1
               )
               (setq ptr1 (#:origin:tree:navigate tree abs-path))
               (for (i 0 1 (1- len))
                 (:propagate-rec (#:EQM:tree:right ptr1 i)
                                 (#:EQM:tree:right ptr2 i) ) )
             )
           )
           pathlist
         )
       )
    )
  )
)
; ---------------------------------------------------------------------------- ;
; #:origin:propagate-rec : recursively propagate origins of tree1 to tree2.
;
(de :propagate-rec (tree1 tree2)
; (ifn (#:EQM:tree:equal tree1 tree2)
;   (progn
;     (print "Error - different trees in :propagate-rec")
;     (exit origin)
;   )
; ; else
    (#:origin:join tree2 (#:origin:get tree1))
    (for (i 1 1 (#:EQM:tree:length tree1))
      (:propagate-rec (#:EQM:tree:down tree1 i) (#:EQM:tree:down tree2 i)) )
; )
)
; ---------------------------------------------------------------------------- ;
; #:origin:unshare-binding : remove lhs-to-rhs sharing of binding of var.
;
(de :unshare-binding (var bindings)
  (let
    ( binding var-struct )
    (setq var-struct (#:EQM:make-var var))
    (setq binding (assoc var-struct bindings))
    (if (typep (cdr binding) '#:EQM:list-var)
      (let
        ( (len (#:EQM:list-var:length (cdr binding)))
          (ptr (#:EQM:list-var:term-ptr (cdr binding)))
          sublist )
        (setq sublist (mapcon '#:EQM:tree:copy (firstn len ptr)))
        (#:EQM:list-var:term-ptr (cdr binding) sublist)
      )
    ; else
      (rplacd binding (#:EQM:tree:copy (cdr binding)))
    )
  )
)
; ---------------------------------------------------------------------------- ;
