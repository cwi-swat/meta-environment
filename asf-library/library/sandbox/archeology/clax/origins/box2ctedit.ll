; File box2ctedit.ll
; ---------------------------------------------------------------------------- ;
; $Log$
; Revision 1.1  2003/04/15 08:48:25  jurgenv
; * added several specifications recovered via 'software archeology',
;   changed the extensions, but not tested any of them!
;
; Revision 1.1  1992/08/10  08:12:11  tip
; Initial revision
;
; ---------------------------------------------------------------------------- ;
;
(defvar #:sys-package:colon 'box2ctedit)
; ---------------------------------------------------------------------------- ;
(defvar :last-printed-tree ())		; get rid of this one!
(defvar :last-selection -1)
(defvar :ctedit )
(defvar :red (make-color 28000 0 0))
(defvar :green (make-color 0 28000 0))
(defvar :black (make-color 0 0 0))
(defvar #:box2ctedit:grey (make-color 20000 20000 20000))
; ---------------------------------------------------------------------------- ;
(de :pp (SM tree)
  (let ( (vtpdef (#:SDFimpl:get-vtpdef SM))
	 decor )
    (tag not_found
      (setq decor (#:name:decor 'btp {tree} vtpdef)) )
    (unless decor
      (setq decor (#:tree:new_decor 'btp 'lisp vtpdef)) )
    (:display-boxtree (#:vtp2box:vtp2box SM tree decor))
    (setq :last-printed-tree tree)
))
; ---------------------------------------------------------------------------- ;
(de :pp-gse-tree (GSE)
  (let ( tree SM boxtree decor )
    (unless (setq tree ({GSE}:tree GSE))
      (error ':pp-gse-tree "no tree available" ()) )
    (unless (setq SM ({GSE}:get-SM GSE))
      (error ':pp-gse-tree "no syntax manager found" ()) )

    (tag not_found
      (setq decor (#:name:decor 'btp {tree} (#:SDFimpl:get-vtpdef SM))) )
    (unless decor
      (setq decor (#:tree:new_decor 'btp 'lisp (#:SDFimpl:get-vtpdef SM))) )

    (unless (setq boxtree (#:vtp2box:vtp2box SM tree decor))
      (error ':pp-gse-tree "generation of the boxtree failed" ()) )
    (:display-boxtree boxtree)
    (setq :last-printed-tree tree)
))
; ---------------------------------------------------------------------------- ;
(de :display-boxtree (boxtree)
    (if (and (boundp ':ctedit) :ctedit (send 'page :ctedit))
      ({page}:reformat (send 'page :ctedit) () `(c () . ,boxtree) )
      (let ( ctedit-view )
        (setq ctedit-view
	  (create-figue-view ({page}:create 400 boxtree)
			     (cons 0 0) (cons 300 400)))
        (setq :ctedit (send 'object ctedit-view)) )
        (send 'text-color :ctedit #:box2ctedit:grey)
        (send 'redisplay #:box2ctedit:ctedit ())
	({ctedit-window}:observe :ctedit 'click (cons :red 1))
	({ctedit-window}:mouse :ctedit 'click)
    )
)
; ---------------------------------------------------------------------------- ;
(de :show-focus (GSE)
  (let ( (focus (#:vtptrees:current (#:data:object:vtptrees GSE)))
	 (page (send 'page :ctedit))
	 focus-path )
    (setq focus-path (#:xref:denumberize (#:xref:get-boxtree-path focus)))
    ({page}:selection-path page 'focus (list focus-path))
    ({page}:reformat page (combine-page-selections page))
))
; ---------------------------------------------------------------------------- ;
(de :show-subtree (tree)
  (let ( (page (send 'page :ctedit))
	 path )
    (setq path (#:xref:denumberize (#:xref:get-boxtree-path tree)))
    ({page}:selection-path page 'red-subtree (list path))
    ({page}:reformat page (combine-page-selections page))
))
; ---------------------------------------------------------------------------- ;
(de {ctedit-window}:up-event (object event)
 (when ({ctedit-window}:mouse object)
  (lets ((mouse-pos (cons (#:event:x event) (#:event:y event)))
         (page ({ctedit-window}:page object))
         (path ({format}:pointer-path ({page}:format page)
                        (add-vector mouse-pos ({ctedit-window}:ul object))))
	 tree
        )
    (when path
      (setq tree
	(#:xref:find-closest-subtree :last-printed-tree
				     (cadr (#:xref:numberize (car path))) ))
      (setq path (list (#:xref:denumberize (#:xref:get-boxtree-path tree)))) )
    ({page}:selection-path page ({ctedit-window}:mouse object) path)
    ({page}:reformat page (combine-page-selections page)))))

; ---------------------------------------------------------------------------- ;
; #:box2ctedit:show-subtrees : shows the subtrees in the tree-list as
;			       selected subtrees.
;
; Unfortunately, a selection consists of only one path...
; Selections have names subtree0, subtree1, ...
; Global variable :last-selection contains the number of selections used.
;
(de :show-subtrees (tree-list)
  (let 
    ( (page (send 'page :ctedit))
      (selnr 0)
      tree selname path )
    (while (nextl tree-list tree)
      (setq path (#:xref:denumberize (#:xref:get-boxtree-path tree)))
      (setq selname (symbol () (catenate "subtree" selnr)))
      ({ctedit-window}:observe :ctedit selname (cons #:origin:color 
                                                     #:origin:font-nr))
      ({page}:selection-path page selname (list path))
      (incr selnr) )
    (setq :last-selection (max (1- selnr) :last-selection))
    ({page}:reformat page (combine-page-selections page))
    ({ctedit-window}:redisplay :ctedit ())
  )
)
; ---------------------------------------------------------------------------- ;
; #:box2ctedit:clear-all-selections : clear all subtree* selections.
; uses global variable :last-selection.
;
(de #:box2ctedit:clear-all-selections ()
  (let
    ( (page (send 'page #:box2ctedit:ctedit)) 
      selname )
    (for (i 0 1 #:box2ctedit:last-selection)
      (setq selname (symbol () (catenate "subtree" i)))
      ({ctedit-window}:observe :ctedit selname ()) )
    ({page}:reformat page (combine-page-selections page))
    ({ctedit-window}:redisplay :ctedit ())
    (setq #:box2ctedit:last-selection -1)
  )
)
; ---------------------------------------------------------------------------- ;
