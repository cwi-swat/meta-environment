; File: interface.ll
; ---------------------------------------------------------------------------- ;
; $Log$
; Revision 1.1  2003/04/15 08:48:25  jurgenv
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
    ( (redex (#:origin:tree:navigate (#:EQM:get-term tp) (#:EQM:get-path tp)))
      (rhs (#:EQM:EQMhandle:rhs eq))
      path abs-path)

; perform 'LR-subs propagations

    (mapc
      (lambda (elem)
        (#:origin:propagate-symbol 
          redex (#:EQM:EQMhandle:lhs eq) (cadr elem) 
          contractum (#:EQM:EQMhandle:rhs eq) (cddr elem) 
          bindings ) )
      (cassq 'LR-subs (#:EQM:EQMhandle:get-info eq 'origin))
    )

; perform top symbol propagation
    
    (when (:get redex) (#:origin:join contractum (#:origin:get redex)))

; perform CR propagations

    (setq CR-info
      (cassq 'CR-origins (#:EQM:EQMhandle:get-info eq 'tmp-origins)) )
    (mapc
      (lambda (elem)
        (mapc
          (lambda (path)
            (setq abs-path (#:origin:abs-path rhs path bindings))
            (#:origin:propagate-origin contractum abs-path (cdr elem))
          )
          (car elem)
        )
      )
      CR-info
    )

; print info

    (when #:origin:redex (print "REDEX:") (#:origin:show redex))
    (when #:origin:contractum (print "CONTRACTUM:") (#:origin:show contractum))

; pop 'tmp-origins stack

    (#:EQM:EQMhandle:put-info eq 'tmp-origins
      (cdr (#:EQM:EQMhandle:get-info eq 'tmp-origins)) )

  )
)
; ---------------------------------------------------------------------------- ;
; #:origin:match : called when a match is found, before trying any conditions
;
; Propagate origins to bindings according to 'lhs-vars annotation of eq.
;
(de :match (EDB eq tp bindings)

  (when #:origin:show-info (#:origin:show-precomputed-info eq))

; push () on 'tmp-origins stack

  (#:EQM:EQMhandle:put-info eq 'tmp-origins
    (cons () (#:EQM:EQMhandle:get-info eq 'tmp-origins)) )

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
  (if bindings
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
  ; else --- condition failed

; pop 'tmp-origins stack

    (#:EQM:EQMhandle:put-info eq 'tmp-origins
      (cdr (#:EQM:EQMhandle:get-info eq 'tmp-origins)) )
  )
)
; ---------------------------------------------------------------------------- ;
; #:origin:cond-side-start : start of evaluation of condition side.
 
 

(de :cond-side-start (EDB eq cond side instside bindings)
  (let
    ( (top (car (#:EQM:get-stack (#:EDB:EQMinfo EDB))))
      tp S N CC-info elem path abs-path )

    (setq tp (#:EQM:stack:term-path top))
    (setq S (#:EQM:stack:cond-side top))
    (setq N (#:EQM:stack:cond-rank top))

; propagate annotations according to 'LC-SN-subs.

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
      (cassq (concat 'LC- S (#:EQM:stack:cond-rank top) '-subs)
             (#:EQM:EQMhandle:get-info eq 'origin) )
    )

; perform CC propagations for common subterms.

    (setq CC-info (cassq (concat S N '-origins)
                  (#:EQM:EQMhandle:get-info eq 'tmp-origins) ) )
    (mapc
      (lambda (elem)
        (mapc
          (lambda (path)
            (setq abs-path (#:origin:abs-path side path bindings))
            (#:origin:propagate-origin instside path (cdr elem))
          )
          (car elem)
        )
      )
      CC-info
    )


  )
)
; ---------------------------------------------------------------------------- ;
(de :cond-side-end (EDB eq cond side instside bindings)
  (let
    ( (top (car (#:EQM:get-stack (#:EDB:EQMinfo EDB))))
      (S (if (eq side ({tree}:down cond 1)) 'left 'right)) 
      N annot CR-SN-subs elem origin tmp-origins CR-info
      CC-info CC-SN-subs elem2 path )

    (setq N (#:EQM:stack:cond-rank top))

; store info in 'tmp-origins assoclist for CR subterm propagations.

    (setq annot (concat 'CR- S N '-subs))
    (setq CR-SN-subs (cassq annot (#:EQM:EQMhandle:get-info eq 'origin)))
    (mapc
      (lambda (elem)
        (mapc
          (lambda (path)
            (setq origin (#:origin:get (#:origin:tree:navigate instside path)))

            (setq tmp-origins (#:EQM:EQMhandle:get-info eq 'tmp-origins))
            (setq CR-info (cassq 'CR-origins tmp-origins))
            (newl CR-info (cons (cddr elem) origin))

            (setq tmp-origins (delq (assq 'CR-origins tmp-origins) tmp-origins))
            (setq tmp-origins (acons 'CR-origins CR-info tmp-origins))

            (#:EQM:EQMhandle:put-info eq 'tmp-origins tmp-origins)
          )
          (cadr elem)
        )
      )
      CR-SN-subs
    )

; store info in 'tmp-origins assoclist for CC subterm propagations.

    (setq annot (concat 'CC- S N '-subs))
    (setq CC-SN-subs (cassq annot (#:EQM:EQMhandle:get-info eq 'origin)))
    (mapc
      (lambda (elem) 		; elem is (S'N' . [(term . (plist . plist))])
        (mapc
          (lambda (elem2)	; elem2 is (term. (plist . plist))
            (mapc
              (lambda (path)

                (setq origin
                  (#:origin:get (#:origin:tree:navigate instside path)) )
                (setq tmp-origins (#:EQM:EQMhandle:get-info eq 'tmp-origins))
                (setq CC-info (cassq (concat (car elem) '-origins) tmp-origins))
                (newl CC-info (cons (cddr elem2) origin))

                (setq tmp-origins
                      (delq (assq (concat (car elem) '-origins) tmp-origins)
                            tmp-origins))
                (setq tmp-origins
                  (acons (concat (car elem) '-origins) CC-info tmp-origins) )

                (#:EQM:EQMhandle:put-info eq 'tmp-origins tmp-origins)
              )
              (cadr elem2)
            )
          )
          (cdr elem)
        )
      )
      CC-SN-subs
    )

; push last condition side on stack.

    (#:EQM:EQMhandle:put-info eq 'last-side
      (cons (list S N side) (#:EQM:EQMhandle:get-info eq 'last-side)) )

  )
)
; ---------------------------------------------------------------------------- ;
(de :eval-cond-start (EDB eq kind vtp-cond bindings))
(de :init-backtrack (EDB))
(de :redo-backtrack (EDB))
(de :end-backtrack (EDB))
; ---------------------------------------------------------------------------- ;
