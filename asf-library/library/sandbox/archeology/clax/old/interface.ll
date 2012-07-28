; File: interface.ll
; ---------------------------------------------------------------------------- ;
; $Log$
; Revision 1.1  2003/04/15 08:48:24  jurgenv
; * added several specifications recovered via 'software archeology',
;   changed the extensions, but not tested any of them!
;
; Revision 1.3  1992/08/14  13:48:26  tip
; EQM hooks.
;
; Revision 1.2  1992/08/10  12:26:04  tip
; sharing probleem opgelost
;
; Revision 1.1  1992/08/10  08:12:50  tip
; Initial revision
;
; ---------------------------------------------------------------------------- ;
(setq #:sys-package:colon '#:origin)

(defvar #:origin:initial-term)
(defvar #:origin:final-term)
; ---------------------------------------------------------------------------- ;
; #:origin:init : pp the original term in the ctedit-window.
;
(de :init (SM vtp-tree)
  (setq #:origin:initial-term ({tree}:copy vtp-tree))
  (when #:origin:pp
    (#:box2ctedit:pp SM #:origin:initial-term)
  )
)
; ---------------------------------------------------------------------------- ;
; #:origin:reduce-start : called once, when the reduction starts.
;
(de :reduce-start (EDB eqm-term)
  (#:origin:initialise eqm-term #:origin:initial-term)
 
  (when #:origin:first-term
    (print "ORIGINAL TERM:")
    (#:origin:show eqm-term)
    (print)
  )
)
; ---------------------------------------------------------------------------- ;
; #:origin:reduce-end : called once, after normal termination.
;
(de :reduce-end (EDB eqm-result)
  (setq #:origin:final-term eqm-result)
  (when #:origin:last-term
    (print "RESULT:")
    (#:origin:show eqm-result)
  )
)
; ---------------------------------------------------------------------------- ;
; #:origin:apply-eq: called after successful evaluation of all conditions.
;
; Propagate annotations according to the 'lr-subs annotation of eq.
;
(de :apply-eq (EDB eq tp contractum bindings)
  (let
    ( (redex (#:origin:tree:navigate (#:EQM:get-term tp) (#:EQM:get-path tp))) )
    (mapc
      (lambda (elem)
        (#:origin:propagate-symbol 
          redex (#:EQM:EQMhandle:lhs eq) (cadr elem) 
          contractum (#:EQM:EQMhandle:rhs eq) (cddr elem) 
          bindings ) )
      (cassq 'lr-subs (#:EQM:EQMhandle:get-info eq 'origin))
    )

; relate top symbols of redex and contractum
    
    (when (:get redex)
      (#:origin:join contractum (#:origin:get redex))
    )

    (when #:origin:redex
      (print "REDEX:")
      (#:origin:show redex)
    )
    (when #:origin:contractum
      (print "CONTRACTUM:")
      (#:origin:show contractum)
    )

  )
)
; ---------------------------------------------------------------------------- ;
; #:origin:match : called when a match is found, before trying any conditions
;
; Propagate origins to bindings according to 'lhs-vars annotation of eq.
;
(de :match (EDB eq tp bindings)
  (when #:origin:show-info
    (#:origin:show-precomputed-info eq)
  )
  (let
    ( (redex (#:origin:tree:navigate (#:EQM:get-term tp) (#:EQM:get-path tp))) )
    (mapc
      (lambda (elem)
        (#:origin:unshare-binding (car elem) bindings)
        (#:origin:propagate-to-bindings redex 
                                        (#:EQM:EQMhandle:lhs eq)
                                        (cdr elem) 
                                        bindings ) )
      (cassq 'lhs-vars (#:EQM:EQMhandle:get-info eq 'origin))
    )

  )
)
; ---------------------------------------------------------------------------- ;
; #:origin:eval-cond-end : is called after the evaluation of a condition.
;
; Propagate origins to bindings for each element of 'SN-vars
;
(de :eval-cond-end (EDB eq vtp-cond bindings)
  (when bindings
    (let
      ( stack top annot vtp-side last-side SN-vars )
      (setq stack (#:EQM:EQMhandle:get-info eq 'last-side))
      (setq top (car stack))
      (setq annot (concat (nth 0 top) (nth 1 top) '-vars))
      (setq vtp-side (selectq (nth 0 top)
                    (left ({tree}:down vtp-cond 1))
                    (right ({tree}:down vtp-cond 2))
                  ) )
      (setq last-side (cdr top))
      (when (setq SN-vars (cassq annot (#:EQM:EQMhandle:get-info eq 'origin)))
        (mapc
          (lambda (elem)
            (#:origin:unshare-binding (car elem) bindings)
            (#:origin:propagate-to-bindings last-side vtp-side 
                                            (cdr elem) bindings) )
          SN-vars
        )
      )
      (#:EQM:EQMhandle:put-info eq 'last-side (cdr stack))
    )
  )
)
; ---------------------------------------------------------------------------- ;
; #:origin:cond-side-start : start of evaluation of condition side.
;
; Propagate annotations according to 'SN-subs.
;

(de :cond-side-start (EDB eq cond side instside bindings)
  (let
    ( top tp S )
    (setq top (car (#:EQM:get-stack (#:EDB:EQMinfo EDB))))
    (setq tp (#:EQM:stack:term-path top))
    (setq S (#:EQM:stack:cond-side top))
    (mapc
      (lambda (elem) 
        (#:origin:propagate-symbol 
          (#:origin:tree:navigate (#:EQM:get-term tp)(#:EQM:get-path tp))
          (#:EQM:EQMhandle:lhs eq)
          (cadr elem)
          instside
          (if (eq S 'left) ({tree}:down cond 1) ({tree}:down cond 2))
          (cddr elem)
           bindings ) )
      (cassq (concat S (#:EQM:stack:cond-rank top) '-subs)
             (#:EQM:EQMhandle:get-info eq 'origin) )
    )
  )
)
; ---------------------------------------------------------------------------- ;
(de :cond-side-end (EDB eq cond side instside bindings)
  (let
    ( top  )
    (setq top (car (#:EQM:get-stack (#:EDB:EQMinfo EDB))))
    (#:EQM:EQMhandle:put-info eq 'last-side
      (cons 
        (list (if ({tree}:equal side ({tree}:down cond 1)) 'left 'right)
              (#:EQM:stack:cond-rank top)
              side )
            (#:EQM:EQMhandle:get-info eq 'last-side) ) )
  )
)
; ---------------------------------------------------------------------------- ;
(de :eval-cond-start (EDB eq kind vtp-cond bindings))
(de :init-backtrack (EDB))
(de :redo-backtrack (EDB))
(de :end-backtrack (EDB))
; ---------------------------------------------------------------------------- ;
