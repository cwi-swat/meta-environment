; $Id$

(send-string-to-terminal "tb.el invoked\n" nil nil)

; This implements a number of functions for use with the ToolBus emacs-adapter

(defvar lenspec nil
  "The length of the header of a term send back to the ToolBus, in characters"
  )
(defvar min-msg-size nil
  "The minimal length of a term to be sent back to the ToolBus, in characters"
  )

(defun TBinit (args)
  "Called when starting emacs. ARGS are the arguments that are passed along to any ToolBus tool. "
;;  (setq process-connection-type nil)
  (setq adapter-process 
	(let ((process-connection-type nil)) ; Use a pipe
	  (start-process "adapter" "*adapter*" "emacs-adapter" args)
	  )
	)
  )


;;(setq chunk 5120)

; Define lenspec and min-msg-size. These should be called upon initialization.
; lenspec is from ../../src/terms.h
(defun set-lenspec (len)
  "Sets the length of the term header for ToolBus terms"
  (setq lenspec len)
)
; min-msg-size is from ../../src/utils.c
(defun set-minmsgsize (len)
  "Sets the minimal length of a term to be sent to the ToolBus"
  (setq min-msg-size len)
)

;TBevent send an event to the ToolBus
(defun TBevent (event)
  (TBsend (concat "snd-event(" event ")"))
)

(defun TBvalue (term)
  "Sends TERM to the ToolBus as snd-value(TERM)"
  (TBsend (concat "snd-value(" term ")"))
  )

(defun TBsend (term)
  "TBsend send an arbitrary term to the ToolBus"
  (send-string-to-terminal "In TBsend\n")
;;  (gnuserv-kill-all-clients)
   (let ((fullmsg (set-min-msg-size 
		   (concat (num-to-lenspec 
			    (+ lenspec
			       (length term))) 
			   ":"
			   term))
 			
		  )
	 )
;;   (send-string-to-terminal "Made fullmsg\n")
;;   (send-string-to-terminal (concat "fullmsg is " 
;;				    (number-to-string (length fullmsg))
;;				    "bytes\n")
;;			    )
;;    (send-string-to-terminal fullmsg)
   (process-send-string adapter-process fullmsg)
;;   (process-send-string adapter-process "\n") ;; !!!!!!!!!!!!!!!!!!!!!!!!
   ()
   )
   )

(defun TBstring (str)
  "Escape strings following ToolBus conventions"
  (interactive "s")
  (concat "\"" (replace-in-string (replace-in-string (replace-in-string str "\n" "\\\\n") "\t" "\\\\t") "\"" "\\\\\"") "\"")
)
;Aux functions
(defun num-to-lenspec (num)
  "Returns NUM with 0's prefixed, to make num as wide as `lenspec'"
  (truncate-string-to-width 
   (store-substring 
    (make-string (- lenspec 1) 
		 (string-to-char "0"))
    (- (- lenspec 1)
       (length (number-to-string num)))
    (number-to-string num))
   (- lenspec 1)))
     
(defun set-min-msg-size (msg)
  "Pads MSG with whitespace characters to make it exactly `min-msg-size' long"
  (if (< min-msg-size 
	 (length msg)
	 )
      msg
    (store-substring (make-string min-msg-size 
				  (string-to-char " "))
		     0 msg) 
    )
  )

; Testing, testing, 1 2 3
(defun return-value (val)
  (send-string-to-terminal "In return value" nil nil)
  (TBvalue (TBstring val))
)
(defun return-val (val)
  (send-string-to-terminal "In return value" nil nil)
  (TBvalue val)
)

