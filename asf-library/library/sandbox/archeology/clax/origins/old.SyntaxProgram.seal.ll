(
  de
    #:SEAL:  SyntaxProgram:EvaluateCondFunc1
    ( instance ui-item SEAL )
    (
      and
        ( #:SEAL:  all-mods-existsp ( list "EvalProgram" ) SEAL )
        ( #:SEAL:  all-tt-consistentp ( list instance ) SEAL )
        ( #:SEAL:  focus-sort-is instance ( list ' root ) "PROGRAM" SEAL )
      )
  )
  (
    de
      #:SEAL:  SyntaxProgram:EvaluateActFunc1
      ( instance ui-item SEAL )
      (
        tag
          error
          (
            ifn
              ( #:SEAL:  all-mods-existsp ( list "EvalProgram" ) SEAL )
              ( exit error )
            )
          (
            ifn
              ( #:SEAL:  all-tt-consistentp ( list instance ) SEAL )
              ( exit error )
            )
          (
            ifn
              (
                #:SEAL: var: check
                  "Root"
                  'term
                  ( #:SEAL:  get-focus-phylum instance ( list ' root ) SEAL )
                  (  )
                  instance
                  ( #:SEAL:  get-focus-tree instance ( list ' root ) SEAL )
                  (  )
                  ui-item
                  SEAL
                )
              ( exit error )
            )
          (
            ifn
              (
                #:SEAL: var: check
                  "Result"
                  'term
                  (
                    #:SEAL:  find-function-sort
                      "EvalProgram"
                      "eval-program"
                      ( list ( #:SEAL:  lookup-var-by-name ui-item "Root" ) )
                      SEAL
                    )
                  (  )
                  'config
                  (
                    #:SEAL:  reduce
                      "EvalProgram"
                      (
                        #:SEAL:  create-action-term
                          "EvalProgram"
                          "eval-program"
                          (
                            list
                              ( #:SEAL:  lookup-var-by-name ui-item "Root" )
                            )
                          SEAL
                        )
                      SEAL
                    )
                  "EvalProgram"
                  ui-item
                  SEAL
                )
              ( exit error )
            )
        )
    )
  (
    de
      #:SEAL:  SyntaxProgram:TypecheckCondFunc1
      ( instance ui-item SEAL )
      (
        and
          ( #:SEAL:  all-mods-existsp ( list "Tc" ) SEAL )
          ( #:SEAL:  all-tt-consistentp ( list instance ) SEAL )
          ( #:SEAL:  focus-sort-is instance ( list ' root ) "PROGRAM" SEAL )
        )
    )
  (
    de
      #:SEAL:  SyntaxProgram:TypecheckActFunc1
      ( instance ui-item SEAL )
      (
        tag
          error
          (
            ifn
              ( #:SEAL:  all-mods-existsp ( list "Tc" ) SEAL )
              ( exit error )
            )
          (
            ifn
              ( #:SEAL:  all-tt-consistentp ( list instance ) SEAL )
              ( exit error )
            )
          (
            ifn
              (
                #:SEAL: var: check
                  "Root"
                  'term
                  ( #:SEAL:  get-focus-phylum instance ( list ' root ) SEAL )
                  (  )
                  instance
                  ( #:SEAL:  get-focus-tree instance ( list ' root ) SEAL )
                  (  )
                  ui-item
                  SEAL
                )
              ( exit error )
            )
          (
            ifn
              (
                #:SEAL: var: check
                  "Result"
                  'term
                  (
                    #:SEAL:  find-function-sort
                      "Tc"
                      "tc"
                      ( list ( #:SEAL:  lookup-var-by-name ui-item "Root" ) )
                      SEAL
                    )
                  (  )
                  'config
                  (
                    #:SEAL:  reduce
                      "Tc"
                      (
                        #:SEAL:  create-action-term
                          "Tc"
                          "tc"
                          (
                            list
                              ( #:SEAL:  lookup-var-by-name ui-item "Root" )
                            )
                          SEAL
                        )
                      SEAL
                    )
                  "Tc"
                  ui-item
                  SEAL
                )
              ( exit error )
            )
          (
            ifn
              (
                #:SEAL:  create-output
                  "Errors.tc"
                  (
                    #:SEAL: var: modulename
                      ( #:SEAL:  lookup-var-by-name ui-item "Result" )
                      SEAL
                    )
                  ( #:SEAL:  lookup-var-by-name ui-item "Result" )
                  SEAL
                )
              ( exit error )
            )
        )
    )
  (
    de
      #:SEAL:  SyntaxProgram:ErrorsCondFunc1
      ( instance ui-item SEAL )
      (
        and
          ( #:SEAL:  all-mods-existsp ( list "TcErrors" ) SEAL )
          ( #:SEAL:  all-tt-consistentp ( list instance ) SEAL )
          ( #:SEAL:  focus-sort-is instance ( list ' root ) "PROGRAM" SEAL )
        )
    )
  (
    de
      #:SEAL:  SyntaxProgram:ErrorsActFunc1
      ( instance ui-item SEAL )
      (
        tag
          error
          (
            ifn
              ( #:SEAL:  all-mods-existsp ( list "TcErrors" ) SEAL )
              ( exit error )
            )
          (
            ifn
              ( #:SEAL:  all-tt-consistentp ( list instance ) SEAL )
              ( exit error )
            )
          (
            ifn
              (
                #:SEAL: var: check
                  "Root"
                  'term
                  ( #:SEAL:  get-focus-phylum instance ( list ' root ) SEAL )
                  (  )
                  instance
                  ( #:SEAL:  get-focus-tree instance ( list ' root ) SEAL )
                  (  )
                  ui-item
                  SEAL
                )
              ( exit error )
            )
          (
            ifn
              (
                #:SEAL: var: check
                  "Result"
                  'term
                  (
                    #:SEAL:  find-function-sort
                      "TcErrors"
                      "errors"
                      ( list ( #:SEAL:  lookup-var-by-name ui-item "Root" ) )
                      SEAL
                    )
                  (  )
                  'config
                  (
                    #:SEAL:  reduce
                      "TcErrors"
                      (
                        #:SEAL:  create-action-term
                          "TcErrors"
                          "errors"
                          (
                            list
                              ( #:SEAL:  lookup-var-by-name ui-item "Root" )
                            )
                          SEAL
                        )
                      SEAL
                    )
                  "TcErrors"
                  ui-item
                  SEAL
                )
              ( exit error )
            )
          (
            ifn
              (
                #:SEAL:  create-output
                  "Errors.err"
                  (
                    #:SEAL: var: modulename
                      ( #:SEAL:  lookup-var-by-name ui-item "Result" )
                      SEAL
                    )
                  ( #:SEAL:  lookup-var-by-name ui-item "Result" )
                  SEAL
                )
              ( exit error )
            )
        )
    )
  (
    de
      #:SEAL:  configure-SyntaxProgram
      ( SEAL )
      (
        #:SEAL:  add-item-to-table
          (
            #:SEAL:  create-item
              "SyntaxProgram"
              'try-config
              (
                list
                  (
                    #:SEAL:  create-ui-item
                      'button
                      "Evaluate"
                      (  )
                      '
                      ( #:SEAL:  SyntaxProgram:EvaluateCondFunc1 )
                      (  )
                      '
                      ( Root Result )
                      (  )
                      '
                      ( #:SEAL:  SyntaxProgram:EvaluateActFunc1 )
                      (  )
                    )
                  (
                    #:SEAL:  create-ui-item
                      'button
                      "Typecheck"
                      (  )
                      '
                      ( #:SEAL:  SyntaxProgram:TypecheckCondFunc1 )
                      (  )
                      '
                      ( Root Result )
                      (  )
                      '
                      ( #:SEAL:  SyntaxProgram:TypecheckActFunc1 )
                      (  )
                    )
                  (
                    #:SEAL:  create-ui-item
                      'button
                      "Errors"
                      (  )
                      '
                      ( #:SEAL:  SyntaxProgram:ErrorsCondFunc1 )
                      (  )
                      '
                      ( Root Result )
                      (  )
                      '
                      ( #:SEAL:  SyntaxProgram:ErrorsActFunc1 )
                      (  )
                    )
                )
            )
          SEAL
        )
    )
