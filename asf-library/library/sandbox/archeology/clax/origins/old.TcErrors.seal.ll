; modified to show origins.
; Frank Tip 31-8-1992.

; -------------------------------------------------------------------------- ;
; condition: button always enabled.

(de #:SEAL:  TcErrors:OriginCondFunc1 ( instance ui-item SEAL )
  t
)

; -------------------------------------------------------------------------- ;
; action :
;
;       - haal focus op m.b.v. GSE functie
;	- bepaal pad naar focus.
;       - haal origin op
;       - highlight in Figue window

(de #:SEAL:TcErrors:OriginActFunc1 (instance ui-item SEAL)
  (let
    ( (focus (#:vtptrees:current (#:data:object:vtptrees instance)))
      (path '())
      root EQMsubtree origin )
    (setq root (#:tree:up focus -1))
    (while (neq focus root)
      (newl path (#:tree:rank focus))
      (setq focus (#:tree:up focus 1)) )
;----
(print "path = " path)
    (setq path (reverse path))		; something to do with "tc" fun
;----
    (setq EQMsubtree (#:origin:tree:navigate #:origin:final-term path))
    (setq origin (#:origin:get EQMsubtree))
;----
(print "origin = " (mapcar '#:origin:vtp2path origin))
;----
    (#:origin:show-subtrees origin)
  )
)
; -------------------------------------------------------------------------- ;
; configureren (of zo)

(de #:SEAL:configure-TcErrors (SEAL)
  (#:SEAL:add-item-to-table
    (#:SEAL:create-item "TcErrors"
                        'try-config
                        (list (#:SEAL:create-ui-item
                                'button
                                "Show Origin"
                                ()
                                '(#:SEAL:TcErrors:OriginCondFunc1)
                                ()
                                '(Focus Result)
                                ()
                                '(#:SEAL:TcErrors:OriginActFunc1)
                                ()
                              )
                        )
    )
    SEAL
  )
)
