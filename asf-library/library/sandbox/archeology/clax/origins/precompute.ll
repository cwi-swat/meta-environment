; File: precompute.ll
; ---------------------------------------------------------------------------- ;
(setq #:sys-package:colon '#:origin)
; ---------------------------------------------------------------------------- ;
; #:origin:precompute : pre-compute all positional information and store it as
;                       annotation in eq.
;
; The following annotations are computed:
; ---------------------------------------
;
; 'lhs-vars    : vars occurring in lhs, bound during matching,
;                list with elements (var . pathlist)
; 'LR-subs     : common non-var subterms of lhs and rhs
;                list with elements (term . (l-pathlist . r-pathlist))
; 'SN-vars     : vars introduced by side S of condition #N
;                list with elements (var . pathlist)
; 'LC-SN-subs  : common non-var subterms of lhs and side S of condition N
;                list with elements (term . (l-pathlist . SN-pathlist))
; 'CR-SN-subs  : common non-var subterms of side S of condition N and rhs
;                list with elements (term . (SN-pathlist . r-pathlist))
; 'CC-SN-subs  : common non-var subterms of side S of condition N and all
;                subsequent non-variable-introducing conditions.
;                list with elements (S'N' . [(term . (SN-paths . S'N'-paths))])
;                where [ ... ] is another list.
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
      LR-subs lhs-vars lhs-subs rhs-vars rhs-subs cond left-side right-side
      left-vars left-subs right-vars right-subs LC-leftN-subs LC-rightN-subs 
      intro-side bound-vars side-vars side-subs new-side-vars elem S 
      opt-lhs-vars opt-side-vars phylum CR-SN-subs dummy
      N_ condlist_ leftN_ rightN_ leftN_-subs rightN_-subs type_
      SN-leftN_-subs SN-rightN_-subs leftN_-info rightN_-info SN-info )

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

; compute and annotate LR-subs

    (desetq (rhs-subs . rhs-vars) (#:origin:subs rhs))
    (setq LR-subs (:filter (#:origin:make-table lhs-subs rhs-subs)))
    (setq info (acons 'LR-subs LR-subs info))
    
; do for all conditions

    ({tree}:for_all_sons
      conds
      (lambda (cond)
        (setq left-side ({tree}:down cond 1))
        (setq right-side ({tree}:down cond 2))

; compute and annotate LC-leftN-subs and LC-rightN-subs

        (desetq (left-subs . left-vars) (#:origin:subs left-side))
        (desetq (right-subs . right-vars) (#:origin:subs right-side))
        (setq LC-leftN-subs (:filter (#:origin:make-table lhs-subs left-subs)))
        (setq LC-rightN-subs
          (:filter (#:origin:make-table lhs-subs right-subs)) )
        (setq info (acons (concat 'LC-left N '-subs) LC-leftN-subs info))
        (setq info (acons (concat 'LC-right N '-subs) LC-rightN-subs info))
        
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

; compute 'CR-SN-subs
; NB: VI-sides indicate relations involving the other side.

          (setq CR-SN-subs (:filter (#:origin:make-table side-subs rhs-subs)))
          (setq info 
            (acons (concat 'CR- (:other-side S) N '-subs) CR-SN-subs info))

; compute CC-SN-subs for all subsequent NVI sides S'N'.

          (setq N_ 1)
          (setq SN-info ())
          (setq condlist_ (#:EQM:EQMhandle:condlist eq))
          ({tree}:for_all_sons
            conds
            (lambda (cond)
              (when (gt N_ N)	; subsequent conditions only
                (setq leftN_ ({tree}:down cond 1))
                (setq rightN_ ({tree}:down cond 2))

                (desetq (leftN_-subs . dummy) (#:origin:subs leftN_))
                (desetq (rightN_-subs . dummy) (#:origin:subs rightN_))

; only compute common subterms for non-variable-introducing sides.
;   SN-leftN_-subs  : common subs of SN and leftN_  
;   SN-rightN_-subs : common subs of SN and rightN_  
;   SN-info         : collect info for all subs of S_N_ and SN in assoclist
;

                (setq type_ (caar condlist_))
                (unless (eq type_ 'match)
                  (setq SN-leftN_-subs
                    (:filter (#:origin:make-table side-subs leftN_-subs)) )
                  (when SN-leftN_-subs
                    (setq SN-info
                      (acons (concat 'left N_) SN-leftN_-subs SN-info))
                  )
                )
                (unless (eq type_ 'match-rev)
                  (setq SN-rightN_-subs
                    (:filter (#:origin:make-table side-subs rightN_-subs)) )
                  (when SN-rightN_-subs
                    (setq SN-info
                      (acons (concat 'right N_) SN-rightN_-subs SN-info))
                  )
                )

              )
              (nextl condlist_)
              (incr N_)
            )
          )
          (when SN-info
            (setq info
              (acons (concat 'CC- (:other-side S) N '-subs) SN-info info))
          )

        ) 	; end of processing match/match-rev condition.

        (incr N)
        (nextl condlist)
      )
    )
    info
  )
)
; ---------------------------------------------------------------------------- ;
; #:origin:show-precomputed-info : show the precomputed info for an eq.
;                                  shows only non-() info.
;
(de :show-precomputed-info (eq)
  (let
    ( elem
      (conds (#:EQM:EQMhandle:cond eq))
      lhs-vars LR-subs LC-leftN-subs LC-rightN-subs leftN-vars rightN-vars
      CR-leftN-subs CR-rightN-subs CC-leftN-subs CC-rightN-subs
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

; show LR-subs

    (when (setq LR-subs
                (cassq 'LR-subs (#:EQM:EQMhandle:get-info eq 'origin)) )
      (print "LR-subs: ")
      (mapc
        (lambda (elem)
          (print "  subterm " (#:EDB:vtp2str EDB (car elem)) " lhs "
            (cadr elem) " rhs " (cddr elem))
        )
        LR-subs
      )
    )

    (for (N 1 1 ({tree}:length conds))

; show LC-leftN-subs

      (when (setq LC-leftN-subs (cassq (concat 'LC-left N '-subs) 
                                    (#:EQM:EQMhandle:get-info eq 'origin)) )
        (print "LC-left" N "-subs:")
        (mapc
          (lambda (elem)
            (print "  subterm " (#:EDB:vtp2str EDB (car elem)) " lhs "
              (cadr elem) " left" N " " (cddr elem) )
          )
          LC-leftN-subs
        )
      )

; show LC-rightN-subs

      (when (setq LC-rightN-subs (cassq (concat 'LC-right N '-subs) 
                                     (#:EQM:EQMhandle:get-info eq 'origin)) )
        (print "LC-right" N "-subs:")
        (mapc
          (lambda (elem)
            (print "  subterm " (#:EDB:vtp2str EDB (car elem)) " lhs "
              (cadr elem) " right" N " " (cddr elem) )
          )
          LC-rightN-subs
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

; CR-leftN-subs

      (when (setq CR-leftN-subs (cassq (concat 'CR-left N '-subs)
                                    (#:EQM:EQMhandle:get-info eq 'origin)) )
        (print "CR-left" N "-subs:")
        (mapc
          (lambda (elem)
            (print "  subterm " (#:EDB:vtp2str EDB (car elem)) " <left " N "> "
              (cadr elem) " rhs " (cddr elem))
          )
          CR-leftN-subs
        )
      )

; CR-rightN-subs

      (when (setq CR-rightN-subs (cassq (concat 'CR-right N '-subs)
                                    (#:EQM:EQMhandle:get-info eq 'origin)) )
        (print "CR-right" N "-subs:")
        (mapc
          (lambda (elem)
            (print "  subterm " (#:EDB:vtp2str EDB (car elem)) " <right " N "> "
              (cadr elem) " rhs " (cddr elem))
          )
          CR-rightN-subs
        )
      )

; CC-leftN-subs

      (when (setq CC-leftN-subs (cassq (concat 'CC-left N '-subs)
                                    (#:EQM:EQMhandle:get-info eq 'origin)) )
        (print "CC-left" N "-subs: ")

        (mapc
          (lambda (elem)
            (mapc
              (lambda (elem2)
                (print " subterm " (#:EDB:vtp2str EDB (car elem2))
                  " <left " N "> " (cadr elem2)
                  " " (car elem) " " (cddr elem2)
                )
              )
              (cdr elem)
            )
          )
          CC-leftN-subs
        )
      )

; CC-rightN-subs

      (when (setq CC-rightN-subs (cassq (concat 'CC-right N '-subs)
                                    (#:EQM:EQMhandle:get-info eq 'origin)) )
        (print "CC-right" N "-subs:")

        (mapc
          (lambda (elem)
            (mapc
              (lambda (elem2)
                (print " subterm " (#:EDB:vtp2str EDB (car elem2))
                  " <right " N "> " (cadr elem2)
                  " " (car elem) " " (cddr elem2)
                )
              )
              (cdr elem)
            )
          )
          CC-rightN-subs
        )
      )
    )
  )
)
; ---------------------------------------------------------------------------- ;
; #:origin:filter : remove all subterms of phylum LISP from a list.
;
(de :filter (subs)
  (let
    ( elem nl-subs )
    (while (nextl subs elem)
      (setq phylum (#:tree:son_phylum (#:tree:up (car elem ) 1)
                                      (#:tree:rank (car elem))))
      (unless (eq (#:phylum:name phylum) 'LISP)
        (newl nl-subs elem)
      )
    )
    nl-subs
  )
)
; ---------------------------------------------------------------------------- ;
; #:origin:other-side : other side of a condition.
;
(de :other-side (side)
  (if (eq side 'left)
    'right
  ; else
    'left
  )
)
; ---------------------------------------------------------------------------- ;
