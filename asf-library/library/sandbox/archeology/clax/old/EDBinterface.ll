; File: interface.ll
; ---------------------------------------------------------------------------- ;
; $Id $
; ---------------------------------------------------------------------------- ;
(setq #:sys-package:colon '#:EDB)
; ---------------------------------------------------------------------------- ;
; #:EDB:initialise : called once, before the reduction starts. Initializes EDB.
;
(de :initialise (EQMsel term env runtime-info . opts)
  (let ( EDB vect )
    (setq vect (car opts))
    (unless (vectorp vect) (setq vect (makevector 1 ())))
    (setq EDB (:init EQMsel env runtime-info vect))
    (:print2 EDB "EDB v6.6, 21 Oct. 1992.")
    (:print EDB)
    (:prompt EDB)

; origin
    (let
      ( (SM (send 'get-SM (send 'module EQMsel))) )
      (#:origin:init SM term)
    )

    EDB
  ) 
)
; ---------------------------------------------------------------------------- ;
; #:EDB:reduce-start : called once, when the reduction starts.
;
(de :reduce-start (EDB eqm-term)

; origin
  (#:origin:reduce-start EDB eqm-term)
)
; ---------------------------------------------------------------------------- ;
; #:EDB:reduce-end : called once, after normal termination.
;
(de :reduce-end (EDB eqm-result)
  (let
    ( impl-result EQMsel EQM steps )
    (setq EQMsel (#:EDB:EQMsel EDB))
    (setq EQM (#:EQM:EQMsel:eqm EQMsel))
    (setq impl-result (#:EQM:tree:leximplode EQM eqm-result))
    (:print EDB)
    (:print EDB "Normal form: " (#:EDB:EQMterm2str EDB impl-result))
    (setq steps (#:EDB:steps EDB))
    (:print EDB "End of reduction, total number of steps: " steps ".")

; put vtp result in the vector for SEAL.

    (when (#:EDB:vect EDB)
      (vset (#:EDB:vect EDB) 0 (#:EQM:tree:2vtp impl-result)) )

; origin
  (#:origin:reduce-end EDB eqm-result)

    (#:EDB:end-of-reduction EDB 'true)
  )
)
; ---------------------------------------------------------------------------- ;
; #:EDB:apply-eq: called after successful evaluation of all conditions.
;
(de :apply-eq (EDB eq tp result bindings)

; origin
 (#:origin:apply-eq EDB eq tp result bindings)

  (#:EDB:last-control EDB 'apply-eq)
  (#:EDB:current-bindings EDB bindings)
  (#:EDB:current-tp EDB tp)
  (#:EDB:current-eq EDB eq)
  (#:EDB:current-result EDB result)

; (print "match, term = " (#:EDB:get-subtree (#:EQM:get-term tp) (#:EQM:get-path tp)))


  (#:EDB:steps EDB (1+ (#:EDB:steps EDB)))		; incr. steps
  (#:EDB:check-end-of-go EDB)
; --- get user command just before applying eq ---
  (#:EDB:control EDB)

)
; ---------------------------------------------------------------------------- ;
; #:EDB:match : is called when a match is found, before trying any conditions.
;
(de :match (EDB eq tp bindings)

; origin
  (#:origin:match EDB eq tp bindings)
  (#:EDB:last-control EDB 'match)
  (#:EDB:current-bindings EDB bindings)
  (#:EDB:current-tp EDB tp)
  (#:EDB:current-eq EDB eq)
  (#:EDB:current-result EDB () )
  (#:EDB:control EDB)
)
; ---------------------------------------------------------------------------- ;
; #:EDB:eval-cond-start : is called before the evaluation a condition.
;
(de :eval-cond-start (EDB eq kind vtp-cond bindings)

; origin
  (#:origin:eval-cond-start EDB eq kind vtp-cond bindings)


  (#:EDB:last-control EDB 'eval-cond-start)
  (#:EDB:current-bindings EDB bindings)
  (#:EDB:current-result EDB () )

  (let
    ( (tag-str (string (#:EQM:EQMhandle:tag eq))) 
      (cond-str (:vtp2str EDB vtp-cond bindings)) )
; --- in step mode, show condition instd/uninstd ---
    (when (eq (#:EDB:debug-mode EDB) 'step)
      (if (#:EDB:inst-conds EDB)
        (:print EDB cond-str " for equation " tag-str " ???")
      ; else
        (:print EDB
          "CHECKING " 
            (:vtp2str EDB vtp-cond)
          " for eq. " tag-str ", BINDINGS:"
        )
        (ifn (equal bindings 'empty)
          (:pr-bng EDB bindings)
        ; else
          (:print2 EDB "None.")
        )
      )
; --- user command ---
      (#:EDB:control EDB)
    )
  )
)
; ---------------------------------------------------------------------------- ;
; #:EDB:eval-cond-end : is called after the evaluation of a condition.
;
(de :eval-cond-end (EDB eq vtp-cond bindings)

; origin
  (#:origin:eval-cond-end EDB eq vtp-cond bindings)

  (#:EDB:last-control EDB 'eval-cond-end)
  (#:EDB:current-bindings EDB bindings)
  (#:EDB:current-result EDB () )

  (let
    ( (tag-str (string (#:EQM:EQMhandle:tag eq)))
      (cond-str (:vtp2str EDB vtp-cond bindings)) )
    (#:EDB:check-end-of-skip EDB)
; --- in step mode, show condition instd/uninstd ---
    (when (eq (#:EDB:debug-mode EDB) 'step)
      (if (#:EDB:inst-conds EDB)
        (:print EDB cond-str " for equation " tag-str
          (ifn bindings " FAILED." " SUCCEEDED."))
      ; else
        (:print EDB (:vtp2str EDB vtp-cond) " for equation " tag-str 
          (ifn bindings " FAILED." " SUCCEEDED, BINDINGS:"))
        (ifn bindings
          () ; condition failed, no bindings to show.
        ; else
          (ifn (equal bindings 'empty)
            (:pr-bng EDB bindings)
          ; else
            (:print2 EDB "None.")
          )
        )
      ) ; if inst-conds
    ) ; when mode step & show conds
; --- user command ---
    (#:EDB:control EDB)
  )
)
; ---------------------------------------------------------------------------- ;
; #:EDB:cond-side-start : called at start of the evaluation of a condition side.
;
(de :cond-side-start (EDB eq cond side instside bindings)

; origin
  (#:origin:cond-side-start EDB eq cond side instside bindings)

)
; ---------------------------------------------------------------------------- ;
; #:EDB:cond-side-end : called at end of the evaluation of a condition side.
;
(de :cond-side-end (EDB eq cond side instside bindings)

; origin
  (#:origin:cond-side-end EDB eq cond side instside bindings)

)
; ---------------------------------------------------------------------------- ;
; #:EDB:continue : continue after suspend.
;
(de :continue (EDB)
  (when (#:EDB:env EDB)
    (schedule
      (lambda (env)
        (#:EDB:env EDB env)
      )
      (resume (#:EDB:env EDB))
    )
  )
)
; ---------------------------------------------------------------------------- ;
; #:EDB:equations-changed : called when editing causes changes in the eqs.
;
(de :equations-changed (EDB)
  (:print EDB "*** EDB WARNING *** EQUATIONS HAVE BEEN CHANGED !!!")
)
; ---------------------------------------------------------------------------- ;
; #:EDB:init-backtrack : called when backtracking starts.
;
(de #:EDB:init-backtrack (EDB)

; origin
  (#:origin:init-backtrack EDB)

)
; ---------------------------------------------------------------------------- ;
; #:EDB:redo-backtrack : back to state of init-backtrack.
;
(de #:EDB:redo-backtrack (EDB)
  (when (eq (#:EDB:debug-mode EDB) 'step)
    (:print EDB "BACK:") )

; origin
  (#:origin:redo-backtrack EDB)

)
; ---------------------------------------------------------------------------- ;
; #:EDB:end-backtrack : end backtracking.
;
(de #:EDB:end-backtrack (EDB)

; origin
(#:origin:end-backtrack EDB)
)
; ---------------------------------------------------------------------------- ;
