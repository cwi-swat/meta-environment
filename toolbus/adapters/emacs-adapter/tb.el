; $Id$

; This is the elisp file that defines the communication between emacs
; and the emacs adapter.

; The global variables

(defvar lenspec nil
  "The length of the header of a term send back to the ToolBus, in characters"
  )
(defvar min-msg-size nil
  "The minimal length of a term to be sent back to the ToolBus, in characters"
  )
(defvar current-partial-msg ""
  "The variable that holds partial messages from the ToolBus, while waiting
for the rest of the msg"
  )
(defvar debug ()
  "If set to t (debug-out string) produces debug output. If set to () not"
  )

; The functions
(defun TBinit (args)
  "Called when starting emacs. ARGS are the arguments that are passed along to any ToolBus tool. "
  (debug-out (concat "args of TBinit are: " (prin1-to-string args)))
  (setq adapter-process                      ; The handle to the adapter
	(let ((process-connection-type nil)) ; Use a pipe
	  (apply 'start-process "adapter" "*adapter*" "emacs-adapter" (split-string args))
	  ;; Start a proces named "adapter" which uses "*adapter*" as
	  ;; its buffer. The executable "emacs-adapter" is executed
	  ;; with args as arguments
	  )
	)
  (set-process-filter adapter-process 'handle-term-from-toolbus)
  ;; Set handle-term-from-toolbus as the process-filter for the
  ;; adapter process. This function is passed all output from the
  ;; adapter
  (process-kill-without-query adapter-process)
  ;; Do not require a confirmation to kill the adapter process when
  ;; killing xemacs. (I was hoping they had something like this :-)
  (add-hook 'kill-emacs-hook 'TBkillemacs)
  ;; Call TBkillemacs just before killing emacs
  )

(defun handle-term-from-toolbus (proc string)
  "This is the filter function that processes input from the toolbus. PROC 
is the adapter process, STRING is the string to be processed"
  (debug-out "In handle-term")
  (debug-out string)
  (setq new-string (concat current-partial-msg string))
  ;; In case there was a string left from the previous call to
  ;; handle-term-from-toolbus, paste it before the new string
  (debug-out (concat "String conc with old string: " new-string))
  (let ((eval-list (split-string new-string "\n"))
	;; Split the incoming string on newlines, there is one lisp
	;; expression per line coming in.
	(last-char (substring new-string -1)))
    ;; Save the last character of the incoming string. If it is not a
    ;; "\n" then more will come.
    (debug-out (concat "eval-list: " (prin1-to-string eval-list)))
    (debug-out (concat "last-char: " last-char))
    (while (< 2 (list-length eval-list))
      ;; eval-list always has an empty "" as its last element, hence
      ;; the bigger than 2. If it is bigger than 2 we know we are
      ;; dealing with complete lisp expressions. Only the last one can
      ;; be partial.
      (debug-out (concat "car of eval-list: " (car eval-list)))
      (eval (car (read-from-string (car eval-list))))
      ;; Take the head of the list (the first lisp expression), parse
      ;; it (that's what read-from-string does) and evaluate it.
      (set 'eval-list (cdr eval-list))
      ;; Remove the head of the eval-list and loop the loop.
      )
    ;; While loop finished. Now we only have one (possibly partial)
    ;; lisp expression left.
    (if (not (string= last-char "\n"))
	;; Then it's a partial message. Save it and wait for next call
	;; to handle-term-from-toolbus, when the rest will arrive
	(setq current-partial-msg (car eval-list))
      ;; else: do the same as above
      (progn (eval (car (read-from-string (car eval-list))))
	     (setq current-partial-msg "")
	     ;; There is no partial message left, so we set it to ""
	     )
      )
    )
  )
(defun TBkillemacs () 
  "This function is called when emacs is killed. It tells the ToolBus to disconnect emacs"
  (TBsend "snd-disconnect")
  )
  
(defun TBevent (event)
  "Send EVENT to the ToolBus as a snd-event(EVENT)"
  (TBsend (concat "snd-event(" event ")"))
)

(defun TBvalue (term)
  "Sends TERM to the ToolBus as snd-value(TERM)"
  (TBsend (concat "snd-value(" term ")"))
  )

(defun TBsend (term)
  "TBsend send an arbitrary term to the ToolBus"
  (let ((fullmsg (set-min-msg-size 
		  (concat (num-to-lenspec 
			   (+ lenspec
			      (length term))) 
			  ":"
			  term))
		 ;; First we make the lenspec header: the length of
		 ;; the term to be sent including the header. The
		 ;; header should be lenspec characters long, so if
		 ;; the actual number is less characters we pad it
		 ;; with 0's. Then there is the ":" between header and
		 ;; body, and then the actual term.
		 )
	 )
    (process-send-string adapter-process fullmsg)
    ;; And send the full message to the adapter process
    ()
    ;; return nil
    )
  )

(defun TBstring (str)
  "Escape strings following ToolBus conventions"
  (concat "\"" (replace-in-string (replace-in-string (replace-in-string (replace-in-string str "\\\\" "\\\\\\\\") "\n" "\\\\n") "\t" "\\\\t") "\"" "\\\\\"") "\"")
  ;; We escape \n \t " and \
)
  

; Aux functions

(defun set-lenspec (len)
  "Sets the length of the term header for ToolBus terms. This should be called upon initialization. lenspec is from ../../src/terms.h"
  (setq lenspec len)
)

(defun set-minmsgsize (len)
  "Sets the minimal length of a term to be sent to the ToolBus. minmsgsize is from ../../src/utils.c"
  (setq min-msg-size len)
)

(defun num-to-lenspec (num)
  "Returns NUM with 0's prefixed, to make num as wide as `lenspec'"
  (truncate-string-to-width 
   (store-substring 
    (make-string (- lenspec 1) 
		 (string-to-char "0"))
    ;;Make a string that is lenspec - 1 zeroes
    (- (- lenspec 1)
       (length (number-to-string num)))
    ;; Calculate the length of num as a decimal string, and subtract
    ;; it from lenspec - 1
    (number-to-string num))
   ;; And insert num as decimal string in the string of zeroes
   (- lenspec 1)
   ;; And truncate anything that sticks out after lenspec - 1
   )
  )
     
(defun set-min-msg-size (msg)
  "Pads MSG with whitespace characters to make it exactly `min-msg-size' long"
  (if (< min-msg-size 
	 (length msg)
	 )
      ;; If msg is longer than min-msg-size, return it unchanged
      msg
    ;; else, make a string of " " that is min-msg-size long, and
    ;; insert msg at position 0
    (store-substring (make-string min-msg-size 
				  (string-to-char " "))
		     0 msg) 
    )
  )

(defun debugp ()
  "Is debugging on or off?"
  debug
  )

(defun debug-out (str)
  "Send string to stdout, for debugging"
  (if (debugp)
      ;; if debugging is on
      (send-string-to-terminal (concat str "\n"))
    ;; else nothing
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

