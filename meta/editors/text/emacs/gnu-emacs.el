; improve readability of legacy constructs
(defun head (list) (car list))
(defun tail (list) (cdr list))

(defvar current-partial-msg "")
(defvar must-send-modified t)

; used to parse keyboard shortcuts
(require 'edmacro)

(defun init (args)
  (setq emacs-connector
    (let ((process-connection-type nil))
         (apply 'start-process "emacs-connector" "*Meta*" "emacs-connector"
           (split-string args))
    )
  )
  (set-process-filter emacs-connector 'handle-input-from-hive)
  (process-kill-without-query emacs-connector)
  (define-key global-map [mouse-1] 'mouse-clicked)
  (add-hook 'after-change-functions 'buffer-modified () t)
)

(defun handle-input-from-hive (proc args)
  (setq new-string (concat current-partial-msg args))
  (let ((eval-list (split-string new-string "\n"))
	(last-char (substring new-string -1)))
    (while (< 1 (length eval-list))
      (eval (head (read-from-string (head eval-list))))
      (set 'eval-list (tail eval-list))
    )
    (if (not (string= last-char "\n"))
      (setq current-partial-msg (head eval-list))
      (progn (eval (head (read-from-string (head eval-list))))
        (setq current-partial-msg "")
      )
    )
  )
)

(defun clear-focus ()
  (setq must-send-modified ())
  (let ((modified (buffer-modified-p)))
    (remove-text-properties 1 (point-max) '(face))
    (set-buffer-modified-p modified)
  )
  (setq must-send-modified t)
)

(defun set-focus (start end)
  (setq must-send-modified ())
  (let ((modified (buffer-modified-p)))
    (remove-text-properties 1 (point-max) '(face))
    (put-text-property start end 'face 'region)
    (set-buffer-modified-p modified)
  )
  (setq must-send-modified t)
)

(defun clear-highlights ()
(let ((overlays (overlays-in 1 (point-max)))
        found)
    (while overlays
      (let ((overlay (car overlays)))
        (delete-overlay overlay)
      )
      (setq overlays (cdr overlays)))
    ))

; a partial implementation for the syntax highlighting interface
; the idea is that we will implement the full configurability later.
; At least the following code exhibits the functionality needed to set text
; properties:
(defun set-highlight (start end)
  (setq must-send-modified ())
  (let ((modified (buffer-modified-p)))
    (let ((overlay (make-overlay start end nil nil)))
      (overlay-put overlay 'face 'bold)
; color is in hexadecimal RGB values
      (overlay-put overlay 'face '(foreground-color . "RGB:85/85/85"))
    )
    (set-buffer-modified-p modified)
  )
  (setq must-send-modified t)
)

(defun reread-contents ()
  (setq must-send-modified ())
  (revert-buffer nil t)
  (setq must-send-modified t)
)

(defun is-modified ()
  (if (eq (buffer-modified-p) t)
    (send-to-hive "modified#1")
    (send-to-hive "modified#0")
  )
)

(defun send-to-hive (message)
  (process-send-string emacs-connector message)
)

(defun meta-menu-event (menu)
  (send-to-hive menu)
)

(defun debug-out (msg)
  (switch-to-buffer "meta-debug")
  (print msg (get-buffer "meta-debug"))
)

(defun get-location-buffer-pos (location)
  (head (tail location))
)

(defun get-event-location (event)
  (head (tail event))
)

(defun mouse-clicked (event)
  (interactive "e")
  (send-to-hive (prin1-to-string (get-location-buffer-pos (get-event-location event))))
)

(defun buffer-modified (start end old-length)
  (if (eq must-send-modified t)
    (send-to-hive "modified")
  )
)

(defun write-contents ()
  (save-buffer)
  (send-to-hive "handshake")
  (send-to-hive "contents-written")
)
