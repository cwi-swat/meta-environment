;;;; $Id$
;;
;;
;;
;; This file contains lisp code that can be used for
;; dumping reduction results on file.
;; The basic functionality includes:
;; - term representation, which can be either VTP internally
;;   or GEL externally
;; - reduction functionality, either based on EQM or on ASF2C.



(defvar #:sys-package:colon '#:DUMP)
(defvar :outfile (catenate "/tmp/effe." (gensym)))

;; Representing functions
(defstruct :asdf-function
  mod-name	; module in which it is defined.
  result-mod	; module which contains sufficient syntax for result
)
(defstruct :asdf-function:compiled
  fun-name	; name following GSE menu expansion.
  executable   	; name of compiled C executable to be invoked.
  id		; short descriptive name (used for naming generated files)
)
(defstruct :asdf-function:interpreted
  fun-name	; name following ctasdf.conf patterns.
  phylum	; phylum used to parse fun-name.
)


;; Representing terms.
(defstruct :asdf-term
  edit		; editor involved.
  mod-name	; name of module over which it is defined.
)
(defstruct :asdf-term:compiled
  gel-file	; name of gel file containing tree
  the-vtp-tree  ; nil if not yet computed, otherwise vtp representation.
)
(defstruct :asdf-term:interpreted
  vtp-tree	; pointer to vtp tree
)


;; \paragraph{Creating Terms}
(de :make-int-asdf-term (edit)
  (new-init :asdf-term:interpreted
    edit 		edit
    mod-name		(send 'name edit)
    vtp-tree		(send 'tree edit)
  )
)
(de :make-cc-asdf-term (edit)
  (let* ((term  (new-init :asdf-term:compiled
		    edit		edit
		    mod-name		(send 'name edit)
		)
         )
         (geln  (send 'tmp-name term ()))
        )
    (send 'gel-file term geln)
    (:tree-to-GEL-file (send 'SM term) (send 'tree edit) geln)
    term
  )
)

;; \paragraph{Deleting Terms}
(de :asdf-term:compiled:kill (term)
  (send 'edit      term ())
  (send 'mod-name  term ())
  (:clean-up (list (send 'gel-file term)))
  (send 'gel-file  term ())
  (send 'the-vtp-tree term ())
)
(de :asdf-term:interpreted:kill (term)
  (send 'edit     term ())
  (send 'mod-name term ())
  (send 'vtp-tree term ())
)
 
;; Auxiliary operations on terms
(de :asdf-term:SM (term)
  (send 'SM-select 
    (:load-module (send 'meta (send 'edit term)) (send 'mod-name term))
  )
) 

(de :asdf-term:compiled:vtp-tree (term)
  (let ((vtp-tree  (send 'the-vtp-tree term)))
    (unless vtp-tree
      (setq vtp-tree (send 'the-vtp-tree term (:GEL-file-to-tree (send 'SM term) (send 'gel-file term))))
    )
    vtp-tree
  )
)
(de :asdf-term:tmp-name (term id)
  (:get-tmp-name (send 'gse-inst (send 'edit term)) id)
)
(de :asdf-term:interpreted:gel-file (term)
  (let ((tmp-name	(send 'tmp-name term ())))
    (:tree-to-GEL-file 
      (send 'SM term) 
      (send 'vtp-tree term)   
      (send 'tmp-name term)
    )
    tmp-name
  )
)


;; Applying a function to a term.
(de :asdf-function:compiled:reduce-term (fun term)
  (let* ((name-in	(send 'tmp-name term (send 'id fun)))
	(name-out	(catenate name-in ".out"))
       )
    (:file-copy (send 'gel-file term) name-in)
    (:append-to-GEL-file name-in (catenate (send 'mod-name fun) ": " (send 'fun-name fun)))
    (:GEL-reduce (send 'executable fun) name-in name-out)
    (:clean-up (list name-in))
    (new-init :asdf-term:compiled
        edit		(send 'edit term)
        gel-file	name-out
	mod-name	(send 'result-mod fun)
    )
  )
)

(de :asdf-function:interpreted:reduce-term (fun term)
  (let* ((edit (send 'edit term))
 	 (lmod (:load-module (send 'meta edit) (send 'mod-name fun)))
         eqm-result
       )
    (setq eqm-result
      (:hidden-reduction 
	edit 
	lmod 
	(send 'fun-name fun) 
	(send 'phylum fun)
	(send 'vtp-tree term)
      )
    )
    (new-init :asdf-term:interpreted
      edit	edit
      mod-name	(send 'result-mod fun)
      vtp-tree  eqm-result
    )
  )
)

;; Writing a function.
(de :asdf-term:write-on-file (term filename)
  (when filename
    ;; Make sure PpBig (see below) knows which file we mean
    (setq :outfile filename)
    (with ((rmargin (1+ (slen (outbuf)))))
      (print filename)
    )
    (:redirect-output filename)
  )
  ; (send 'write-prelude term filename)
  ({Meta}:print-term (send 'SM term) (send 'vtp-tree term))
  (when filename
    (:reredirect-output)
    ; (print " ...done.")
  )
)

;; we have to adapt a function from PP !!
(de #:PP:produce-text (outfile) ;-> list of strings
  (let (strings)
    (ifn #:PP:PpBig
      (progn
        (setq strings (#:file:readtext outfile))
        (deletefile outfile)
        strings
      )
    ;else
    (comline (catenate "mv " outfile " " #:DUMP:outfile))
    (comline (catenate "cat " #:DUMP:outfile))
    )
  )
)



(de :asdf-term:write-prelude (term output-file)
  (with ((rmargin (1+ (slen (outbuf)))))
    (print "%% Generated code from \\")
    (print "%% " (when (send 'edit term) (send 'dir-file (send 'edit term))) " \\")
    (when output-file (print (catenate "%% " output-file " \\")))
    (print "%% Date: " (date))
  )
)
 
(de :load-module (meta mname)
  (let ((mod (send 'find-module meta mname)))
    (if mod
      ; then
      mod
      ; else
      (if (send 'file-exists? (send 'search-path meta) (catenate mname ".syn"))
        ;then 
        (send 'add-modname meta "." (concat mname))
        ;else
        (print "Not loading " mname " (does not exist).") 
        ()
      )
    )
  )
)


(de :reload-module (meta mname)
  (let ((mod (send 'find-module meta mname)))
    (cond
      (mod
        ; module already exists  -- get better text from file.
        (let ((synedit  (send 'synedit mod))
              (eqsedit  (send 'eqsedit mod))
             )
          (send 'revert-text-from-file synedit)
          (send 'revert-text-from-file eqsedit)
          (send 'tree synedit)

	  ; reparse equations only done when needed: don't do it here.
          ; (send 'tree eqsedit)
          mod
        )
      )
      (t
        ; module does not yet exist. Load it.
        (:load-module meta mname)
      )
    )
  )
)


(de :reload-module-when-existing (meta mname)
  (when (send 'find-module meta mname) 
    (print "Reloading " mname " as well.")
    (:reload-module meta mname)
  )
)  


(de :do-the-reduction (edit tmod actual-tree parsed-pattern)
  (let ((EQM-select (send 'EQM-select tmod))
        (meta       (send 'meta edit))
        result
       )
    (cond
     ((and parsed-pattern actual-tree)
      ({MODDESCR}:search-and-subs parsed-pattern actual-tree)
      (setq result (send 'EQM-evaluate meta edit EQM-select parsed-pattern))
     ) 
     ((not parsed-pattern)
      (print ':do-the-reduction " Encountering error in parsed-pattern: "
         parsed-pattern
      )
     )
     ((not actual-tree)
      (print ':do-the-reduction " Encountering error in actual-tree: "
         actual-tree
      )
     )
    )
    result
  )
)



(de :parse (mod text phylum)
 (when mod
  (let ((SM-selection (send 'SM-select mod)))
    (#:SDFimpl:parse SM-selection 'string text
      (if phylum
        ; then
        (list (#:SDFimpl:get-phylum SM-selection phylum))
        ; else
        ()
      )
    )
  )
 )
)

(de :hidden-reduction (edit tmod function phylum tree)
  (let ((parsed-pattern (:parse tmod function phylum))
        result-tree
       )
    (:mprin (catenate "Reducing " function " -> " phylum " ... "))
    (setq {Meta}:print-EQM-result ())
    (setq result-tree
      (:do-the-reduction 
        edit 
        tmod 
        tree
        parsed-pattern
      )
    )
    (setq {Meta}:print-EQM-result t)
    (print "done.")
    result-tree
  )
)


(de :mprin (str)
  (prin str) (flush)
)



(de :redirect-output (file)
  ;; we can't use ``collecting garbage ...'' within our generated files.
  (:gc-message-off)
  (output (concat file))
)

(de :reredirect-output ()
  (output ())
  (:gc-message-on)
)

(de :gc-message-off ()
;  (de gc-before-alarm () ())
;  (de gcalarm () ())
)

(de :gc-message-on ()
;  (de gc-before-alarm () (prin "Collecting garbage...") (flush))
;  (de gcalarm () (print "done. "))
)

(de gc-before-alarm () ())
(de gcalarm () ())


;; Redefinitions from ASDF/meta/top-level.ll
(defvar    #:Meta:print-EQM-result           t)

(de #:Meta:EQM-evaluate (meta editor EQM-selection tree)
;;----------------
;; N.B.: This function has been slightly adapted for ASD!!
;; Make sure that future versions are properly incorporated.
  (let* ((status         (send 'status meta))
         (inc-storage    (send 'inc-storage editor))
         (result         ())
        )
    (when status (send 'reduce status))

    (unless inc-storage 
      (setq inc-storage (send 'inc-storage editor (#:INC:create-storage)))
    )
    (when (and tree EQM-selection)
      (setq result
        (#:EQM:evaluate 
          EQM-selection 
          tree 
          (acons 'INC inc-storage
                (when (send 'debug-on? meta) (acons 'EDB t ()))
          )
          ()
        )
      )
    )
    (when #:Meta:print-EQM-result (#:Meta:print-term (send 'get-SM editor) result))
    (when status (send 'pop status))
    result
  )
)

(de #:Meta:print-term (SM tree)
  (when tree
    (mapc 
      '#:Meta:print-long-string 
      (#:box2str:pp SM tree)
    )
  )
)


(defvar #:Meta:pp-factor .1) 
;; factor with which white space in front of string is reduced.

;; Strings longer than 80 characters (or longer than the value
;; of (rmargin)) can cause problems if plain print is used.
;; Make sure these problems don't occur.
(de #:Meta:print-long-string (str)
  (with
    ((rmargin (1+ (slen (outbuf)))))
    (progn
      (print (#:Meta:reduce-white-space str #:Meta:pp-factor))
    )
  )
)


(de #:Meta:white-front-pos (str pos)
  (if (eqstring (substring str pos 1) " ")
    (#:Meta:white-front-pos str (add pos 1))
    ; else
    pos
  )
)
  
(de #:Meta:reduce-white-space (str factor)
  (substring 
    str 
    (fix (* (- 1 factor) (#:Meta:white-front-pos str 0)))
  )
)

;; To make sure the buttons work OK for the ASCII interface as well.
(de  #:Meta:editing:editing:ascii:gse-inst (ed) ed)
(de  #:Meta:editing:editing:ascii:MM (ed) ed)
(de  #:Meta:editing:editing:ascii:vtptrees (ed) ())



;; top level function; interpreted mode.

;; Example call:
;; (#:DUMP:dump-it 
;;    GSE                       ;; editor structure
;;    'McCabe                   ;; ASF+SDF module name containing function
;;    "mc-cabe( <Program> )"    ;; function template
;;    'Int      		;; resulting sort
;;    'Integers			;; resulting module
;;    ".mccabe"			;; postfix appended to editor name.
;; )
;; Returns a string containing the file name of the dumped result.
(de :dump-it (GSE mod-name fun-name phylum result-mod postfix)
  (let* ((edit (send 'MM GSE))
	 (term (:make-int-asdf-term edit))
	 function
	 res-term
	 (new-file (catenate (send 'dir-file edit) postfix))
	)
    (setq function
      (new-init :asdf-function:interpreted
	mod-name	mod-name
	fun-name	fun-name
	phylum		phylum
	result-mod	result-mod
      )
    )
    (setq res-term (send 'reduce-term function term))
    (send 'write-on-file res-term new-file)
    (send 'kill term)
    (send 'kill res-term)
    new-file
  )
)
