;; used to generated stupid equations. Not necessary anymore.
(de #:AG:upper-and-lower ()
  (for (i (cascii 'A)  1 (cascii 'Z))
    (let ((up  (ascii (uppercase i)))
	  (low (ascii (lowercase i)))
	 )
      (print "  [" up  "1] " 
	     "convert-string-uppercase(""" low """) = """ up """"
      )
      (print "  [" up  "2] " 
             "convert-string-lowercase("""  up """) = """ low """"
      )
      (print "  [" up  "3] " "is-uppercase(""" up """) = true")
      (print "  [" up  "4] " "is-lowercase(""" low """) = true")
      )
    )
  )
)
