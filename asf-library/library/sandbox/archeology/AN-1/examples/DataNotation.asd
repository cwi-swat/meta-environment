<module> DataNotation
<body>


  <module> General
    <body>
    %%  includes: Truth-Values, Numbers/Naturals, Strings/Basics.
    (0) x_ = x_ . %%
  </module>



  <module> Truth-Values
    <body>

    <module> Basics
      <body>
      introduces: truth-value , true , false  .
      * truth-value = true | false (individual) .
      closed.
    </module>

    <module> Specifics
      <body>
       %%  includes: Basics.
      introduces: _ is _, not _ .
      *  _ is _       :: truth-value, truth-value -> truth-value (total).
      *  not _        :: truth-value -> truth-value .
    </module>

  </module>



  <module> Numbers/Naturals
    <body>

    <module> Basics
      <body>
      introduces: natural .
      closed.
    </module>

    <module> Specifics
      <body>
      %%  includes: Basics.
      introduces:
        sum _ , predecessor _ , difference _ .
      * sum _         :: (natural, natural) -> natural (total) .
      * predecessor _ :: natural -> natural (partial) .
      * difference _  :: ( natural, natural ) -> natural (partial) .
     </module>

  </module>


  <module> Strings
    <body>

    <module> Basics
      <body>
      introduces:
        character , string , _ ^ _ .

      * _ ^ _       :: string, string -> string  (total) .
    </module>

  </module>
</module>
