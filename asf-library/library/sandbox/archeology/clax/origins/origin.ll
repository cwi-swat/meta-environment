; File: origin.ll
; ---------------------------------------------------------------------------- ;
; $Log$
; Revision 1.1  2003/04/15 08:48:25  jurgenv
; * added several specifications recovered via 'software archeology',
;   changed the extensions, but not tested any of them!
;
; Revision 1.2  1992/08/10  12:26:30  tip
; sharing probleem opgelost
;
; Revision 1.1  1992/08/10  08:14:10  tip
; Initial revision
;
; ---------------------------------------------------------------------------- ;
(setq #:sys-package:colon '#:origin)
; ---------------------------------------------------------------------------- ;
; #:origin:initialise : annotate each symbol in initial term.
;
(de :initialise (tree vtp)
  (#:EQM:tree:put-info tree 'origin (list vtp))
  (for (i 1 1 ({tree}:length vtp))
    (#:origin:initialise (#:EQM:tree:down tree i) ({tree}:down vtp i)) )
)
; ---------------------------------------------------------------------------- ;
(de :show (tree . path)
  (ifn path
    (:show-rec tree ())
  ; else
    (:show-rec tree (car path))
  )
)

(de :show-rec (tree path)
  (let*
    ( (op 	(#:EQM:tree:operator tree))
      (kind 	(#:SDFimpl:operator:kind op))
      (SM 	(send 'get-SM (send 'module (send 'EQMsel EDB))))
      (name     (if (neq kind 'lexical)
                  (#:SDFimpl:get-expand-string SM op)
                ; else
                  (#:EQM:tree:pretty (send 'eqm (send 'EQMsel EDB)) tree)
                ))
      (i 	1)
    )
    (print 
      "annotation of " kind " " name
      " at path " path " is " (mapcar '#:origin:vtp2path (#:origin:get tree))
    ) 		; show annotation of the root
    (#:EQM:tree:for-all-sons
      tree
      (lambda (son)
        (:show-rec son (cons i path))
        (incr i)
      )
    )
  )
)
; ---------------------------------------------------------------------------- ;
; #:origin:vtp2path (vtp) : map subtree of #:origin:initial-term to its path.
;
(de :vtp2path (vtp)
  (let
    ( (ptr vtp) 
      path )
    (while (neq ptr #:origin:initial-term)
      (newr path ({tree}:rank ptr))
      (setq ptr ({tree}:up ptr 1))
    )
    path
  )
)
; ---------------------------------------------------------------------------- ;
; #:origin:tree:navigate : return the subterm at path in tree
;
(de :tree:navigate (tree path)
  (let
    ( (rpath (reverse path)) 
      (ptr tree)
      elem )
    (while (nextl rpath elem)
      (setq ptr (#:EQM:tree:down ptr elem)))
    ptr
  )
)
; ---------------------------------------------------------------------------- ;
; #:origin:vtp:navigate : return the subterm at path in tree
;
(de :vtp:navigate (vtp path)
  (let
    ( (rpath (reverse path)) 
      (vtptr vtp)
      elem )
    (while (nextl rpath elem)
      (setq vtptr ({tree}:down vtptr (abs elem))))
    vtptr
  )
)
; ---------------------------------------------------------------------------- ;
(de :subs (vtp-tree)
  (:subs-rec vtp-tree () () () )
)

(de :subs-rec (vtp-tree path in-terms in-vars)
  (let*
    ( (op ({tree}:operator vtp-tree))
      (kind (#:SDFimpl:operator:kind op))
      (terms in-terms)
      (vars in-vars)
      (i 1)
      len last-abs op2 kind2 child
    )
    (selectq kind

; variable - add it to vars.

      (var
        (setq vars (:add-elem vars vtp-tree path))
      )

; constant/lexical - add it to the term-list

      ((constant lexical)
        (setq terms (:add-elem terms vtp-tree path)))

; function - add it to the terms ; then do the children recursively

      (function
        (setq terms (:add-elem terms vtp-tree path))
        ({tree}:for_all_sons
          vtp-tree
          (lambda (tree)
            (desetq (terms . vars) (:subs-rec tree (cons i path) terms vars))
            (incr i)))
      )

; list - add it to the terms ; then do the children recursively
;        negative child-numbers are used in order to indicate that 
;        the position of the child depends on the actual bindings. 

      (list
        (setq terms (:add-elem terms vtp-tree path))

; optimization - positions below list are absolute until a list-variable
;                is encountered.

        (setq len ({tree}:length vtp-tree))
        (setq last-abs 0)
        (while (and (eq last-abs 0) (le i len))
          (setq child ({tree}:down vtp-tree i))
          (setq op2 ({tree}:operator child))
          (setq kind2 (#:SDFimpl:operator:kind op2))

          (unless (and (eq kind2 'var) 
                       (eq (#:SDFimpl:var:class child) '{sublist}) )
            (incr last-abs)
          )
          (incr i)
        )
;       (print "list " (#:EDB:vtp2str EDB vtp-tree) 
;              " last absolute position is " last-abs)


        (setq i 1)
        ({tree}:for_all_sons
          vtp-tree
          (lambda (tree)
            (desetq (terms . vars) 
              (:subs-rec tree 
                         (cons (if (le i last-abs) i (- i)) path) 
                         terms 
                         vars) )
            (incr i)))
      )

      (t
        (print "*** panic in #:origin:subs-rec - unknown tree type: " kind)
        (print "             tree is : " (#:EDB:vtp2str EDB vtp-tree))
        (exit origin-error)
      )
    )
    (cons terms vars)
  )
)

(de :add-elem (tplist tree path)
  (let
    ( (newlist tplist) )
    (ifn newlist
      (setq newlist (list (cons tree (list path))))
    ; else
      (ifn ({tree}:equal (caar newlist) tree)
        (setq newlist (cons (car newlist) (:add-elem (cdr newlist) tree path)))
      ; else: trees are equal -- combine the paths 
        (setq newlist 
          (cons (cons (caar newlist) (:union (cdar newlist) (list path)))
                (cdr newlist)))
      )
    )
    newlist
  )
)
; ---------------------------------------------------------------------------- ;
(de :make-table (tlist1 tlist2)
  (let
    ( (result () )
      (ptr1 tlist1) 
      ptr2
      elem1
      elem2
    )
    (while (nextl ptr1 elem1)
      (setq ptr2 tlist2)
      (while (nextl ptr2 elem2)
        (when ({tree}:equal (car elem1) (car elem2))
          (newl result (cons (car elem1) (cons (cdr elem1) (cdr elem2))))
        )
      )
    )
    result
  )
)
; ---------------------------------------------------------------------------- ;
; #:origin:get : retrieve origin at root of term.
;
(de :get (tree)
  (cdr (#:EQM:tree:get-info tree 'origin))
)
; ---------------------------------------------------------------------------- ;
; #:origin:join : join origin with origin at root of term.
;
(de :join (tree org)
  (#:EQM:tree:put-info tree 'origin (#:origin:union (#:origin:get tree) org))
)
; ---------------------------------------------------------------------------- ;
; #:origin:union : compute union of 2 origins.
;
(de :union (org1 org2)
  (union org1 org2 'eq)
)
; ---------------------------------------------------------------------------- ;
; #:origin:abs-path : compute the absolute path.
;
(de :abs-path (vtp path bindings)
  (let
    ( (vtptr vtp)
      (rpath (reverse path))
      result
      actual-pos
      elem
      var-struct
    )
    (while (nextl rpath elem)
      (if (plusp elem)
        (progn
          (setq vtptr ({tree}:down vtptr elem))
          (newl result elem)
        )
      ; else - son of list-node ; compute actual position.
        (setq actual-pos 1)
        (for (i 1 1 (1- (abs elem)))
          (incr actual-pos
            (selectq (#:SDFimpl:tree:kind ({tree}:down vtptr i))
              (variable
                (selectq (#:SDFimpl:var:class ({tree}:down vtptr i))
                  ({tree} 1)
                  ({sublist} 
                    (setq var-struct
                      (cons (#:SDFimpl:var:name ({tree}:down vtptr i))
                            (#:SDFimpl:var:phylum ({tree}:down vtptr i))) )
                    (send 'length (cassoc var-struct bindings))
                  )
                )
              )
              (t 1)
            )
          )
        )
        (setq vtptr ({tree}:down vtptr (abs elem)))
        (newl result actual-pos)
      )
    )
    result
  )
)
; ---------------------------------------------------------------------------- ;
