; $Id$

; This implements a number of functions for use with the ToolBus emacs-adapter

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

;TBsend send an arbitrary term to the ToolBus
(defun TBsend (term)
  (interactive)
; This writes to stderr. 
  (send-string-to-terminal (set-min-msg-size (concat (num-to-lenspec (+ lenspec
						      (length term))) 
				   ":"
				   term))
			   nil
			   nil))

(defun TBstring (str)
  "Escape strings following ToolBus conventions"
  (interactive "s")
  (concat "\"" (replace-in-string (replace-in-string (replace-in-string str "\n" "\\\\n") "\t" "\\\\t") "\"" "\\\\\"") "\"")
)
;Aux functions
(defun num-to-lenspec (num)
  (truncate-string-to-width 
   (store-substring 
    (make-string (- lenspec 1) 
		 (string-to-char "0"))
    (- (- lenspec 1)
       (length (number-to-string num)))
    (number-to-string num))
   (- lenspec 1)))
     
(defun set-min-msg-size (msg)
  (if (< min-msg-size (length msg)) msg
    (store-substring
     (make-string min-msg-size (string-to-char " "))
     0 msg) )
  )

(defun aap ()
  (interactive)
  (TBevent "apenoot")
)
