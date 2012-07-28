(
  de
    #:CONFIG:  ExpandCondFunc1
    ( instance ui-item CONFIG )
    (
      and
        ( #:CONFIG:  all-mods-existsp (  ) CONFIG )
        ( #:CONFIG:  all-tt-consistentp ( list instance ) )
        (
          #:CONFIG:  focus-sort-is
            ( #:CONFIG:  instance-to-instance-name instance CONFIG )
            (  )
            "L-EXP"
            CONFIG
          )
      )
  )
  (
    de
      #:CONFIG:  ExpandActFunc1
      ( instance ui-item CONFIG )
      (
        let
          ( ( FocusVar ) ( DefsFocus ) )
          (
            tag
              error
              (
                ifn
                  ( #:CONFIG:  all-mods-existsp ( list "Lambda" ) CONFIG )
                  ( exit error )
                )
              ; hack of wilco ...
              (
                ifn
                  ( #:CONFIG:  all-tt-consistentp
                    (
                      list
                        instance
                        ( #:CONFIG:instance-name-to-instance 
                          (catenate (current-directory) "Defs") CONFIG )
                      )
                    )
                  (exit error)
                )
              (
                ifn
                  (
                    setq
                      FocusVar
                      (
                        #:CONFIG: var: check
                          "FocusVar"
                          'term
                          (
                            #:CONFIG:  get-focus-phylum instance (  ) CONFIG
                            )
                          (  )
                          (
                            #:CONFIG:  instance-to-instance-name
                              instance
                              CONFIG
                            )
                          (  )
                          (  )
                          ui-item
                          CONFIG
                        )
                    )
                  ( exit error )
                )
              (
                ifn
                  (
                    setq
                      DefsFocus
                      (
                        #:CONFIG: var: check
                          "DefsFocus"
                          'term
                          (
                            #:CONFIG:  get-focus-phylum 
                              ( #:CONFIG:instance-name-to-instance 
                                 (catenate (current-directory) "Defs")
                                 CONFIG
                              ) 
                              (  ) 
                              CONFIG
                            )
                          (  )
                          (catenate (current-directory) "Defs")
                          (  )
                          (  )
                          ui-item
                          CONFIG
                        )
                    )
                  ( exit error )
                )
              (
                ifn
                  (
                    #:CONFIG:  assign-focus
                      (
                        #:CONFIG:  instance-to-instance-name instance CONFIG
                        )
                      (
                        #:CONFIG:  reduce
                          "Lambda"
                          (
                            #:CONFIG:  create-action-term
                              "Lambda"
                              "expand"
                              (
                                list
                                  (
                                    #:CONFIG:  lookup-var-by-name
                                      ui-item
                                      "FocusVar"
                                    )
                                  (
                                    #:CONFIG:  lookup-var-by-name
                                      ui-item
                                      "DefsFocus"
                                    )
                                )
                              CONFIG
                            )
                          CONFIG
                        )
                      CONFIG
                    )
                  ( exit error )
                )
            )
        )
    )
  (
    de
      #:CONFIG:  AlphaCondFunc1
      ( instance ui-item CONFIG )
      (
        and
          ( #:CONFIG:  all-mods-existsp (  ) CONFIG )
          ( #:CONFIG:  all-tt-consistentp ( list instance ) )
          (
            #:CONFIG:  focus-sort-is
              ( #:CONFIG:  instance-to-instance-name instance CONFIG )
              (  )
              "L-EXP"
              CONFIG
            )
        )
    )
  (
    de
      #:CONFIG:  AlphaActFunc1
      ( instance ui-item CONFIG )
      (
        let
          ( ( FocusVar ) )
          (
            tag
              error
              (
                ifn
                  ( #:CONFIG:  all-mods-existsp ( list "Reduce" ) CONFIG )
                  ( exit error )
                )
              (
                ifn
                  ( #:CONFIG:  all-tt-consistentp ( list instance ) )
                  ( exit error )
                )
              (
                ifn
                  (
                    setq
                      FocusVar
                      (
                        #:CONFIG: var: check
                          "FocusVar"
                          'term
                          (
                            #:CONFIG:  get-focus-phylum instance (  ) CONFIG
                            )
                          (  )
                          (
                            #:CONFIG:  instance-to-instance-name
                              instance
                              CONFIG
                            )
                          (  )
                          (  )
                          ui-item
                          CONFIG
                        )
                    )
                  ( exit error )
                )
              (
                ifn
                  (
                    #:CONFIG:  assign-focus
                      (
                        #:CONFIG:  instance-to-instance-name instance CONFIG
                        )
                      (
                        #:CONFIG:  reduce
                          "Alpha"
                          (
                            #:CONFIG:  create-action-term
                              "Alpha"
                              "alpha-norm"
                              (
                                list
                                  (
                                    #:CONFIG:  lookup-var-by-name
                                      ui-item
                                      "FocusVar"
                                    )
                                )
                              CONFIG
                            )
                          CONFIG
                        )
                      CONFIG
                    )
                  ( exit error )
                )
            )
        )
    )
  (
    de
      #:CONFIG:  BetaCondFunc1
      ( instance ui-item CONFIG )
      (
        and
          ( #:CONFIG:  all-mods-existsp (  ) CONFIG )
          ( #:CONFIG:  all-tt-consistentp ( list instance ) )
          (
            #:CONFIG:  focus-sort-is
              ( #:CONFIG:  instance-to-instance-name instance CONFIG )
              (  )
              "L-EXP"
              CONFIG
            )
        )
    )
  (
    de
      #:CONFIG:  BetaActFunc1
      ( instance ui-item CONFIG )
      (
        let
          ( ( FocusVar ) )
          (
            tag
              error
              (
                ifn
                  ( #:CONFIG:  all-mods-existsp ( list "Convert" ) CONFIG )
                  ( exit error )
                )
              (
                ifn
                  ( #:CONFIG:  all-tt-consistentp ( list instance ) )
                  ( exit error )
                )
              (
                ifn
                  (
                    setq
                      FocusVar
                      (
                        #:CONFIG: var: check
                          "FocusVar"
                          'term
                          (
                            #:CONFIG:  get-focus-phylum instance (  ) CONFIG
                            )
                          (  )
                          (
                            #:CONFIG:  instance-to-instance-name
                              instance
                              CONFIG
                            )
                          (  )
                          (  )
                          ui-item
                          CONFIG
                        )
                    )
                  ( exit error )
                )
              (
                ifn
                  (
                    #:CONFIG:  assign-focus
                      (
                        #:CONFIG:  instance-to-instance-name instance CONFIG
                        )
                      (
                        #:CONFIG:  reduce
                          "Convert"
                          (
                            #:CONFIG:  create-action-term
                              "Convert"
                              "beta"
                              (
                                list
                                  (
                                    #:CONFIG:  lookup-var-by-name
                                      ui-item
                                      "FocusVar"
                                    )
                                )
                              CONFIG
                            )
                          CONFIG
                        )
                      CONFIG
                    )
                  ( exit error )
                )
            )
        )
    )
  (
    de
      #:CONFIG:  EtaCondFunc1
      ( instance ui-item CONFIG )
      (
        and
          ( #:CONFIG:  all-mods-existsp (  ) CONFIG )
          ( #:CONFIG:  all-tt-consistentp ( list instance ) )
          (
            #:CONFIG:  focus-sort-is
              ( #:CONFIG:  instance-to-instance-name instance CONFIG )
              (  )
              "L-EXP"
              CONFIG
            )
        )
    )
  (
    de
      #:CONFIG:  EtaActFunc1
      ( instance ui-item CONFIG )
      (
        let
          ( ( FocusVar ) )
          (
            tag
              error
              (
                ifn
                  ( #:CONFIG:  all-mods-existsp ( list "Convert" ) CONFIG )
                  ( exit error )
                )
              (
                ifn
                  ( #:CONFIG:  all-tt-consistentp ( list instance ) )
                  ( exit error )
                )
              (
                ifn
                  (
                    setq
                      FocusVar
                      (
                        #:CONFIG: var: check
                          "FocusVar"
                          'term
                          (
                            #:CONFIG:  get-focus-phylum instance (  ) CONFIG
                            )
                          (  )
                          (
                            #:CONFIG:  instance-to-instance-name
                              instance
                              CONFIG
                            )
                          (  )
                          (  )
                          ui-item
                          CONFIG
                        )
                    )
                  ( exit error )
                )
              (
                ifn
                  (
                    #:CONFIG:  assign-focus
                      (
                        #:CONFIG:  instance-to-instance-name instance CONFIG
                        )
                      (
                        #:CONFIG:  reduce
                          "Convert"
                          (
                            #:CONFIG:  create-action-term
                              "Convert"
                              "eta"
                              (
                                list
                                  (
                                    #:CONFIG:  lookup-var-by-name
                                      ui-item
                                      "FocusVar"
                                    )
                                )
                              CONFIG
                            )
                          CONFIG
                        )
                      CONFIG
                    )
                  ( exit error )
                )
            )
        )
    )
  (
    de
      #:CONFIG:  LMStepCondFunc1
      ( instance ui-item CONFIG )
      (
        and
          ( #:CONFIG:  all-mods-existsp (  ) CONFIG )
          ( #:CONFIG:  all-tt-consistentp ( list instance ) )
          (
            #:CONFIG:  focus-sort-is
              ( #:CONFIG:  instance-to-instance-name instance CONFIG )
              (  )
              "L-EXP"
              CONFIG
            )
        )
    )
  (
    de
      #:CONFIG:  LMStepActFunc1
      ( instance ui-item CONFIG )
      (
        let
          ( ( FocusVar ) )
          (
            tag
              error
              (
                ifn
                  ( #:CONFIG:  all-mods-existsp ( list "Reduce" ) CONFIG )
                  ( exit error )
                )
              (
                ifn
                  ( #:CONFIG:  all-tt-consistentp ( list instance ) )
                  ( exit error )
                )
              (
                ifn
                  (
                    setq
                      FocusVar
                      (
                        #:CONFIG: var: check
                          "FocusVar"
                          'term
                          (
                            #:CONFIG:  get-focus-phylum instance (  ) CONFIG
                            )
                          (  )
                          (
                            #:CONFIG:  instance-to-instance-name
                              instance
                              CONFIG
                            )
                          (  )
                          (  )
                          ui-item
                          CONFIG
                        )
                    )
                  ( exit error )
                )
              (
                ifn
                  (
                    #:CONFIG:  assign-focus
                      (
                        #:CONFIG:  instance-to-instance-name instance CONFIG
                        )
                      (
                        #:CONFIG:  reduce
                          "Reduce"
                          (
                            #:CONFIG:  create-action-term
                              "Reduce"
                              "lm-step"
                              (
                                list
                                  (
                                    #:CONFIG:  lookup-var-by-name
                                      ui-item
                                      "FocusVar"
                                    )
                                )
                              CONFIG
                            )
                          CONFIG
                        )
                      CONFIG
                    )
                  ( exit error )
                )
            )
        )
    )
  (
    de
      #:CONFIG:  LMReduceCondFunc1
      ( instance ui-item CONFIG )
      (
        and
          ( #:CONFIG:  all-mods-existsp (  ) CONFIG )
          ( #:CONFIG:  all-tt-consistentp ( list instance ) )
          (
            #:CONFIG:  focus-sort-is
              ( #:CONFIG:  instance-to-instance-name instance CONFIG )
              (  )
              "L-EXP"
              CONFIG
            )
        )
    )
  (
    de
      #:CONFIG:  LMReduceActFunc1
      ( instance ui-item CONFIG )
      (
        let
          ( ( FocusVar ) )
          (
            tag
              error
              (
                ifn
                  ( #:CONFIG:  all-mods-existsp ( list "Reduce" ) CONFIG )
                  ( exit error )
                )
              (
                ifn
                  ( #:CONFIG:  all-tt-consistentp ( list instance ) )
                  ( exit error )
                )
              (
                ifn
                  (
                    setq
                      FocusVar
                      (
                        #:CONFIG: var: check
                          "FocusVar"
                          'term
                          (
                            #:CONFIG:  get-focus-phylum instance (  ) CONFIG
                            )
                          (  )
                          (
                            #:CONFIG:  instance-to-instance-name
                              instance
                              CONFIG
                            )
                          (  )
                          (  )
                          ui-item
                          CONFIG
                        )
                    )
                  ( exit error )
                )
              (
                ifn
                  (
                    #:CONFIG:  assign-focus
                      (
                        #:CONFIG:  instance-to-instance-name instance CONFIG
                        )
                      (
                        #:CONFIG:  reduce
                          "Reduce"
                          (
                            #:CONFIG:  create-action-term
                              "Reduce"
                              "lm-red"
                              (
                                list
                                  (
                                    #:CONFIG:  lookup-var-by-name
                                      ui-item
                                      "FocusVar"
                                    )
                                )
                              CONFIG
                            )
                          CONFIG
                        )
                      CONFIG
                    )
                  ( exit error )
                )
            )
        )
    )
  (
    de
      #:CONFIG:  configure-Lambda
      ( CONFIG )
      (
        #:CONFIG:  add-item-to-table
          (
            #:CONFIG:  create-item
              "Lambda"
              'try-config
              (
                list
                  (
                    #:CONFIG:  create-ui-item
                      'button
                      "Expand"
                      (  )
                      '
                      ( #:CONFIG:  ExpandCondFunc1 )
                      (  )
                      '
                      ( FocusVar DefsFocus )
                      (  )
                      '
                      ( #:CONFIG:  ExpandActFunc1 )
                      (  )
                    )
                  (
                    #:CONFIG:  create-ui-item
                      'button
                      "Alpha"
                      (  )
                      '
                      ( #:CONFIG:  AlphaCondFunc1 )
                      (  )
                      '
                      ( FocusVar )
                      (  )
                      '
                      ( #:CONFIG:  AlphaActFunc1 )
                      (  )
                    )
                  (
                    #:CONFIG:  create-ui-item
                      'button
                      "Beta"
                      (  )
                      '
                      ( #:CONFIG:  BetaCondFunc1 )
                      (  )
                      '
                      ( FocusVar )
                      (  )
                      '
                      ( #:CONFIG:  BetaActFunc1 )
                      (  )
                    )
                  (
                    #:CONFIG:  create-ui-item
                      'button
                      "Eta"
                      (  )
                      '
                      ( #:CONFIG:  EtaCondFunc1 )
                      (  )
                      '
                      ( FocusVar )
                      (  )
                      '
                      ( #:CONFIG:  EtaActFunc1 )
                      (  )
                    )
                  (
                    #:CONFIG:  create-ui-item
                      'button
                      "LMStep"
                      (  )
                      '
                      ( #:CONFIG:  LMStepCondFunc1 )
                      (  )
                      '
                      ( FocusVar )
                      (  )
                      '
                      ( #:CONFIG:  LMStepActFunc1 )
                      (  )
                    )
                  (
                    #:CONFIG:  create-ui-item
                      'button
                      "LMReduce"
                      (  )
                      '
                      ( #:CONFIG:  LMReduceCondFunc1 )
                      (  )
                      '
                      ( FocusVar )
                      (  )
                      '
                      ( #:CONFIG:  LMReduceActFunc1 )
                      (  )
                    )
                )
            )
          CONFIG
        )
    )


