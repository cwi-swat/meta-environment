; $Id$

; This implements a number of functions for use with the ToolBus emacs-adapter

; Define lenspec and min-msg-size
; lenspec is from ../../src/terms.h
(setq lenspec 8)
; min-msg-size is from ../../src/utils.c
(setq min-msg-size 128)

;TBevent send an event to the ToolBus
(defun TBevent (event)
  (TBsend (concat "snd-event(" event ")"))
)

;TBsend send an arbitrary term to the ToolBus
(defun TBsend (term)
  (interactive)
; This writes to stderr. 
  (send-string-to-terminal (concat (num-to-lenspec (+ lenspec
						      (length term))) 
				   ":"
				   (set-min-msg-size term))
			   nil
			   nil))

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
