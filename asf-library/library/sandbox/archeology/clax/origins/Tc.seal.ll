; modified to show origins.
; Frank Tip 31-8-1992.

; -------------------------------------------------------------------------- ;
; condition: button always enabled.

(de #:SEAL:  Tc:OriginCondFunc1 ( instance ui-item SEAL )
  t
)

; -------------------------------------------------------------------------- ;
; action :
;
;       - haal focus op m.b.v. GSE functie
;	- bepaal pad naar focus.
;       - haal origin op
;       - highlight in Figue window

(de #:SEAL:Tc:OriginActFunc1 (instance ui-item SEAL)
  (let
    ( (focus (#:vtptrees:current (#:data:object:vtptrees instance)))
      (on-sublist (#:focus:on-sublist (#:data:object:focus instance)))
      (path '())
      root EQMsubtree origin origins focal-length)

    (ifn on-sublist
      (setq focal-length 1)
    ; else
      (setq focal-length (nth 1 on-sublist))
    )

    (setq root (#:tree:up focus -1))
    (while (neq focus root)
      (newl path (#:tree:rank focus))
      (setq focus (#:tree:up focus 1)) )
;----
;(print "path = " path)
    (setq path (reverse path))          ; something to do with "tc" fun
;----
    (setq EQMsubtree (#:origin:tree:navigate #:origin:final-term path))
;   (setq origin (#:origin:get EQMsubtree))
    (for (i 1 1 focal-length)
      (setq origin (#:origin:get-all-origins (#:EQM:tree:right EQMsubtree (1- i)
)))
      (newl origins origin)
    )
    (setq origins (apply 'append origins))
;----
;(print "origin = " (mapcar '#:origin:vtp2path origin))
;----
    (#:origin:show-subtrees origins)
  )
)
; -------------------------------------------------------------------------- ;
; configureren (of zo)

(de #:SEAL:configure-Tc (SEAL)
  (#:SEAL:add-item-to-table
    (#:SEAL:create-item "Tc"
                        'try-config
                        (list (#:SEAL:create-ui-item
                                'button
                                "Show Origin"
                                ()
                                '(#:SEAL:Tc:OriginCondFunc1)
                                ()
                                '(Focus Result)
                                ()
                                '(#:SEAL:Tc:OriginActFunc1)
                                ()
                              )
                        )
    )
    SEAL
  )
)
