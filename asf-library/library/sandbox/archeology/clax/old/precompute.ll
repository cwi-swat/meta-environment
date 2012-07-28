; File: precompute.ll
; ---------------------------------------------------------------------------- ;
; $Log$
; Revision 1.1  2003/04/15 08:48:24  jurgenv
; * added several specifications recovered via 'software archeology',
;   changed the extensions, but not tested any of them!
;
; Revision 1.3  1992/08/14  13:48:58  tip
; EQM hooks.
;
; Revision 1.2  1992/08/11  11:13:10  tip
; + filtering lisp constants from common subs.
;
; Revision 1.1  1992/08/10  08:14:44  tip
; Initial revision
;
; ---------------------------------------------------------------------------- ;
(setq #:sys-package:colon '#:origin)
; ---------------------------------------------------------------------------- ;
; #:origin:precompute : pre-compute all positional information and store it as
;                       annotation in eq.
; The following annotations are added:
; 'lhs-vars : vars occurring in lhs, bound during matching,
;             = list with elements (var . pathlist)
; 'lr-subs  : common non-var subterms of lhs and rhs
;             = list with elements (term . (l-pathlist . r-pathlist))
; 'SN-vars   : vars introduced by side S of condition #N
;             = list with elements (var . pathlist)
; 'SN-subs  : common non-var subterms of lhs and side S of condition N
;             = list with elements (term . (l-pathlist . SN-pathlist))
;
; The optional argument phyla is a list of phyla. If present, only the 
; origins of these phyla are tracked. If called without this argument, all
; origins are tracked. *** not implemented yet ***
;
(de :precompute (EQM eq . phyla)
  (let
    ( (conds    (#:EQM:EQMhandle:cond eq))
      (condlist (#:EQM:EQMhandle:condlist eq))
      (lhs      (#:EQM:EQMhandle:lhs eq))
      (rhs      (#:EQM:EQMhandle:rhs eq))
      info
      (N 1)
      lr-subs lhs-vars lhs-subs rhs-vars rhs-subs cond left-side right-side
      left-vars left-subs right-vars right-subs leftN-subs rightN-subs 
      intro-side bound-vars side-vars side-subs new-side-vars elem S 
      opt-lhs-vars opt-side-vars nl-lr-subs phylum nl-leftN-subs
      nl-rightN-subs )

; compute and annotate lhs-vars

    (desetq (lhs-subs . lhs-vars) (#:origin:subs lhs))

; bound-vars is a list containing all bound variables

    (setq bound-vars (mapcar 'car lhs-vars))

; filter out all variables appearing exactly once in the lhs

    (while (nextl lhs-vars elem)
      (when (gt (length (cdr elem)) 1)
        (newl opt-lhs-vars elem)
      )
    )

    (setq info (acons 'lhs-vars opt-lhs-vars info))

; compute and annotate lr-subs

    (desetq (rhs-subs . rhs-vars) (#:origin:subs rhs))
    (setq lr-subs (#:origin:make-table lhs-subs rhs-subs)) 

; filter out common subterms of phylum LISP for lr-subs

    (while (nextl lr-subs elem)
      (setq phylum (#:tree:son_phylum (#:tree:up (car elem) 1)
                                      (#:tree:rank (car elem))))
      (unless (eq (#:phylum:name phylum) 'LISP)
        (newl nl-lr-subs elem)
      )
    )

    (setq info (acons 'lr-subs nl-lr-subs info))
    
; do for all conditions

    ({tree}:for_all_sons
      conds
      (lambda (cond)
        (setq left-side ({tree}:down cond 1))
        (setq right-side ({tree}:down cond 2))

; compute and annotate leftN-subs and rightN-subs

        (desetq (left-subs . left-vars) (#:origin:subs left-side))
        (desetq (right-subs . right-vars) (#:origin:subs right-side))
        (setq leftN-subs (#:origin:make-table lhs-subs left-subs))

; filter out common subterms of phylum LISP for leftN-subs
 
        (setq nl-leftN-subs ())
        (while (nextl leftN-subs elem)
          (setq phylum (#:tree:son_phylum (#:tree:up (car elem) 1)
                                          (#:tree:rank (car elem))))
          (unless (eq (#:phylum:name phylum) 'LISP)
            (newl nl-leftN-subs elem)
          )
        )

        (setq rightN-subs (#:origin:make-table lhs-subs right-subs))

; filter out common subterms of phylum LISP for rightN-subs

        (setq nl-rightN-subs ())
        (while (nextl rightN-subs elem)
          (setq phylum (#:tree:son_phylum (#:tree:up (car elem) 1)
                                          (#:tree:rank (car elem))))
          (unless (eq (#:phylum:name phylum) 'LISP)
            (newl nl-rightN-subs elem)
          )
        )

        (setq info (acons (concat 'left N '-subs) nl-leftN-subs info))
        (setq info (acons (concat 'right N '-subs) nl-rightN-subs info))
        
; if condition introduces variables compute and annotate 'SN-vars

        (setq type (caar condlist))
        (when (memq type '(match match-rev))
          (selectq type
            (match
              (setq intro-side left-side)
              (setq S 'left) )
            (match-rev
              (setq intro-side right-side)
              (setq S 'right)
            )
          )

; determine variables in condition side

          (desetq (side-subs . side-vars) (#:origin:subs intro-side))

; remove all bound-variables

          (setq new-side-vars ())
          (while (nextl side-vars elem)
            (unless 
              (any (lambda (bound-var) ({tree}:equal bound-var (car elem)))
                   bound-vars )
              (newl new-side-vars elem)
              (newl bound-vars (car elem))
            )
          )
; filter out all new variables appearing exactly once in the side

    (setq opt-side-vars ())
    (while (nextl side-vars elem)
      (when (gt (length (cdr elem)) 1)
        (newl opt-side-vars elem)
      )
    )


; annotate 'SN-vars

          (setq info (acons (concat S N '-vars) opt-side-vars info))
        )

        (incr N)
        (nextl condlist)
      )
    )
    info
  )
)
; ---------------------------------------------------------------------------- ;
; #:origin:show-precomputed-info : show the precomputed info of an eq.
;                                  compact is boolean. if true, show only
;                                  non-() info.
;
(de :show-precomputed-info (eq)
  (let
    ( elem
      (conds (#:EQM:EQMhandle:cond eq))
      lhs-vars lr-subs leftN-subs rightN-subs leftN-vars rightN-vars
    )
    (print)
    (print "Equation: " (#:EQM:EQMhandle:tag eq))

; show lhs-vars

    (when (setq lhs-vars
                (cassq 'lhs-vars (#:EQM:EQMhandle:get-info eq 'origin)) )
      (print "lhs-vars: ")
      (mapc
        (lambda (elem)
          (print "  variable " (#:EDB:vtp2str EDB (car elem)) " at " (cdr elem))
        )
        lhs-vars
      )
    )

; show lr-subs

    (when (setq lr-subs
                (cassq 'lr-subs (#:EQM:EQMhandle:get-info eq 'origin)) )
      (print "lr-subs: ")
      (mapc
        (lambda (elem)
          (print "  subterm " (#:EDB:vtp2str EDB (car elem)) " lhs "
            (cadr elem) " rhs " (cddr elem))
        )
        lr-subs
      )
    )

    (for (N 1 1 ({tree}:length conds))

; show leftN-subs

      (when (setq leftN-subs (cassq (concat 'left N '-subs) 
                                    (#:EQM:EQMhandle:get-info eq 'origin)) )
        (print "left" N "-subs:")
        (mapc
          (lambda (elem)
            (print "  subterm " (#:EDB:vtp2str EDB (car elem)) " lhs "
              (cadr elem) " left" N " " (cddr elem) )
          )
          leftN-subs
        )
      )

; show rightN-subs

      (when (setq rightN-subs (cassq (concat 'right N '-subs) 
                                     (#:EQM:EQMhandle:get-info eq 'origin)) )
        (print "right" N "-subs:")
        (mapc
          (lambda (elem)
            (print "  subterm " (#:EDB:vtp2str EDB (car elem)) " lhs "
              (cadr elem) " right" N " " (cddr elem) )
          )
          rightN-subs
        )
      )

; leftN-vars

      (when (setq leftN-vars (cassq (concat 'left N '-vars)
                                    (#:EQM:EQMhandle:get-info eq 'origin)) )
        (print "left" N "-vars:")
        (mapc
          (lambda (elem)
            (print "  new variable " (#:EDB:vtp2str EDB (car elem)) " at "
              (cdr elem)
            )
          )
          leftN-vars
        )
      )

; rightN-vars

      (when (setq rightN-vars (cassq (concat 'right N '-vars)
                                     (#:EQM:EQMhandle:get-info eq 'origin)) )
        (print "right" N "-vars:")
        (mapc
          (lambda (elem)
            (print "  new variable " (#:EDB:vtp2str EDB (car elem)) " at "
              (cdr elem)
            )
          )
          rightN-vars
        )
      )
    )
  )
)
; ---------------------------------------------------------------------------- ;
