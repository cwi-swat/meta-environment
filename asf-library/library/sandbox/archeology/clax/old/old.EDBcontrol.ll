; File: main.ll -  Main control of EDB.
; ---------------------------------------------------------------------------- ;
; $Log$
; Revision 1.1  2003/04/15 08:48:24  jurgenv
; * added several specifications recovered via 'software archeology',
;   changed the extensions, but not tested any of them!
;
; Revision 1.1  1992/08/10  08:08:42  tip
; Initial revision
;
; ---------------------------------------------------------------------------- ;
(setq #:sys-package:colon '#:EDB)
; ---------------------------------------------------------------------------- ;
(de :control (EDB)
  (let*
    ( (tag (string (#:EQM:EQMhandle:tag eq)))
      (tp (#:EDB:current-tp EDB))
      (path (#:EQM:get-path tp))
      (eq (#:EDB:current-eq EDB))
      (result (#:EDB:current-result EDB))
      (bindings (#:EDB:current-bindings EDB))
      (term (#:EDB:get-subtree (#:EQM:get-term tp) path))
      (place (#:EDB:last-control EDB))
      pats pat )
    (selectq (#:EDB:debug-mode EDB)
      ('go
        (if (#:EDB:stop-at-breaks EDB)
          (selectq place
;           (apply-eq
;             (print "APPLY: term = " (#:EDB:EQMterm2str EDB term))
;             (cond  
;               ( (member tag (#:EDB:break-rules EDB))
;                 (#:EDB:print EDB "*" (#:EDB:steps EDB) "* break at " tag)
;                 (#:EDB:print-info EDB term result eq bindings place)
;                 (#:EDB:prompt EDB)
;                 (suspend))
;               ( (setq pats (#:EDB:pattern:match EDB term))
;                 (when pats
;                   (if (setq pat (caar pats))
;                     (progn

;                       (#:EDB:print EDB "*" (#:EDB:steps EDB) "* break at "
;                         (string (:pattern:id pat)) " = "
;                         (string (car (:pattern:text pat))) )
;                       (#:EDB:print-info EDB term result eq bindings place)
;                       (#:EDB:prompt EDB)
;                       (suspend)
;                     )
;                   ; else
;                     (when (setq pat (cadr pats))
;                       (#:EDB:print EDB "*" (#:EDB:steps EDB) "* display at "
;                         (string (:pattern:id pat)) " = "
;                         (string (car (:pattern:text pat))) )
;                       (#:EDB:print-info EDB term result eq bindings place)
;                     )
;                   )
;                 )
;               )
;               ( (#:EDB:show-tags EDB)
;                 (:print EDB tag)
;               )
;             )
;           )
            (match
;             (print "MATCH: term = " (#:EDB:EQMterm2str EDB term))
              (when (setq pats (#:EDB:pattern:match EDB term))
                (when (setq pat (or (caar pats) (cadr pats)))

; origin

(when #:origin:pp
  (let*
    ( (redex-path path) 
      rel-subject-paths		; paths to subjects within the match-pattern
      abs-subject-paths		; paths from root to subjects.
      (subject-orgs ())		; origins of the subjects.
      paths-to-show		; the computed paths in the original term.
      org abs-path subj-org
      alist
    )

    (with
      ( (inchan (openi "org.subjects")) )
      (setq alist (read))
      (setq rel-subject-paths (cassoc (symbol () (#:EDB:pattern:id pat)) alist))
      (close)
    )

;   (print "rel-subject-paths = " rel-subject-paths)
;   (print "redex path = " redex-path)
    (while (nextl rel-subject-paths rel-path)
      (newl abs-subject-paths (append rel-path redex-path))
    )
;   (print "abs-subject-paths = " abs-subject-paths)

    (while (nextl abs-subject-paths abs-path)
      (setq subj-org
        (cdr (#:EQM:tree:get-info
               (#:origin:tree:navigate (#:EQM:get-term tp) abs-path)
               'origin) ) )
;     (print "abs path = " abs-path " ; subj-org = " subj-org)
      (when subj-org
        (newl subject-orgs subj-org) )
    )
;   (#:origin:show term)
;   (print "subject-orgs = " subject-orgs)

    (setq paths-to-show (apply 'append subject-orgs))
;   (print "paths-to-show = " paths-to-show)

    (#:origin:show-subtrees paths-to-show)
  )
)

                  (#:EDB:print EDB "MATCH: *" (#:EDB:steps EDB) "* with "
                    (string (:pattern:id pat)) " = "
                    (string (car (:pattern:text pat))) )
                  (#:EDB:print-info EDB term result eq bindings place)
                  (#:EDB:prompt EDB)
                  (when (caar pats)
                    (suspend)
                  )
                )
              )
            )
          )
        ; else : in go-mode & stop-at-breaks = ()
          (when (#:EDB:show-tags EDB)
            (:print EDB tag)
          )
        )
      )
      ('step
        (when (eq place 'apply-eq)
          (#:EDB:print-info EDB term result eq bindings place))
        (#:EDB:prompt EDB)
        (suspend))
    )
  )
)
; ---------------------------------------------------------------------------- ;
(de :check-end-of-go (EDB)
  (when
    (and
      (eq (#:EDB:debug-mode EDB) 'go)
      (#:EDB:do-goto EDB)
      (eq (#:EDB:goto-step EDB) (#:EDB:steps EDB)))
    (#:EDB:do-goto EDB ())
    (#:EDB:debug-mode EDB 'step)
  )
)
; ---------------------------------------------------------------------------- ;
(de :check-end-of-skip (EDB)
  (when (and (#:EDB:do-skip EDB) 
       (eq (#:EDB:cond-level EDB) (#:EDB:skip-to-level EDB)))
    (#:EDB:do-skip EDB () )        ; turn skip off
    (#:EDB:debug-mode EDB 'step)
  )
)
; ---------------------------------------------------------------------------- ;
