; improve readability of legacy constructs
(defun head (list) (car list))
(defun tail (list) (cdr list))

(defvar current-partial-msg "")
(defvar must-send-modified t)

; used to parse keyboard shortcuts
(require 'edmacro)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; data-structure (hash-table) for storing font properties:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(setq categories (make-hash-table :test 'equal))

(defun put-category (type category properties)
  (puthash (list type category) properties categories)
)

(defun get-category-properties (type category)
  (gethash (list type category) categories '(foreground-color . "black"))
)

(defun get-external-category-properties (category)
  (get-category-properties 'EXTERNAL category)
)

(defun register-category (category properties)
  (put-category 'EXTERNAL category properties)
)

(defun register-focus (properties)
  (put-category 'INTERNAL 'FOCUS properties)
)

(defun get-focus-properties ()
  (get-category-properties 'INTERNAL 'FOCUS)
)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

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

(defun clear-overlays (category)
(let ((overlays (overlays-in 1 (point-max)))
        found)
    (while overlays
      (let* ((overlay (car overlays))
	    (thecat (overlay-get overlay 'category)))
	(if (equal thecat category)
          (delete-overlay overlay)
        )
      )
      (setq overlays (cdr overlays)))
    ))

(defun set-focus (start end)
  (setq must-send-modified ())
  (let ((modified (buffer-modified-p)))
    (clear-overlays 'FOCUS)
    (let ((overlay (make-overlay start end nil nil)))
      (overlay-put overlay 'face (get-focus-properties))
      (overlay-put overlay 'category 'FOCUS)
      (overlay-put overlay 'priority 2)
    )
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


(defun set-highlight (start end category)
  (setq must-send-modified ())
  (let ((modified (buffer-modified-p)))
    (let ((overlay (make-overlay start end nil nil)))
      (overlay-put overlay 'face (get-external-category-properties category))
      (overlay-put overlay 'category category)
      (overlay-put overlay 'priority 1)
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
