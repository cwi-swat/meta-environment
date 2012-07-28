(setq #:sys-package:colon 'SEAL)

(de :reduce (module-name term SEAL) ;-> term

;reduces <term> in context of module <module-name>
; <term> is a VTP tree, <module-name> is a string, SEAL is the Conf. Manag.
  (let ( (new-term)
         (meta)
       )
  (setq meta (:get-meta SEAL))
  (send 'reduce (send 'status meta))

  (ifn (send 'debug-on? meta)
    (setq new-term (#:EQM:evaluate (send 'EQM-select (send 'get-module meta module-name))
                                   term
                                   ()
                                   () ))
  ; else
    (setq x (vector ()))
    (#:EQM:evaluate (send 'EQM-select (send 'get-module meta module-name))
                    term
                    (acons 'EDB x ())
                    () )
    (while (not (setq new-term (vref x 0)))
      (when (peek-event) (manage-event (read-event))) )
  )

  (send 'pop (send 'status meta))
  new-term
  )
)


