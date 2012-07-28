<module> Pico/Semantic-Functions
<body>

  needs: Pico/Abstract-Syntax, Pico/Semantic-Entities.



  <module> Evaluating-Expressions
  <body>

  introduces:  evaluate _ , the operation-result of _ .

  * evaluate _ :: Expression -> action .

  [11]  evaluate N_ : Numeral  = give N_ .

  [12]  evaluate C_ : Character-String = give C_ .

  [13]  evaluate I_:Identifier =
         give the value stored in the cell bound to I_ .

  [14]  evaluate [[ "(" E_:Expression ")" ]] = evaluate E_ .

  [15]  evaluate [[ E_1:Expression O_:Operator E_2:Expression ]] =
         ( evaluate E_1 and evaluate E_2 )
         then give the operation-result of O_ .

  * the operation-result of _ :: Operator -> yielder .

  [16]  the operation-result of "+" = the natural yielded by
         the sum of (the given natural #1, the given natural #2) .

  [17]  the operation-result of "-" = the natural yielded by
         the difference of (the given natural #1, the given natural #2) .

  [18]  the operation-result of "||" = the string yielded by
          ((the given string #1) ^ (the given string #2)) .
  </module>




  <module> Executing-Statements
  <body>

  introduces: execute _ .

   %%  needs: Evaluating-Expressions.

  * execute _ :: Statements -> action .

  [20] execute < S_1: Statement ";" S_2: Statements > =
         execute S_1 and then execute S_2 .

  [21] execute [[ I_:Identifier ":=" E_:Expression ]] =
         evaluate E_ then store the given value
           in the cell bound to I_ .

  [22] execute [[ "if" E_:Expression "then" S_1:Statements "fi" ]] =
         evaluate E_ then give not (it is 0) then
         ( ( check the given truth-value and  then execute S_1 )
           or
           ( check not the given truth-value and then complete ) ) .

  [23] execute [[ "if" E_:Expression "then" S_1:Statements
                  "else" S_2:Statements "fi" ]] =
         evaluate E_ then give not (it is 0) then
         ( ( check the given truth-value and then execute S_1 )
           or
           ( check not the given truth-value and then execute S_2 ) ) .

  [24] execute [[ "while" E_:Expression "do" S_:Statements "od" ]] =
         unfolding
         ( evaluate E_ then give not (it is 0) then
           ( ( check (it is true) and then execute S_ and then unfold )
             or
             ( check (it is false) ) ) ) .

  [25] execute [[ "repeat" S_:Statements "until" E_:Expression ]] =
         unfolding
         ( execute S_ then
           evaluate E_ then give not (it is 0) then
           ( ( check (it is true) )
             or
             ( check (it is false) and then unfold ) ) ) .
  </module>




  <module> Elaborating-Declarations
  <body>

  introduces:  elaborate _ , the initial-value of _ .

  * elaborate _ :: Declarations -> action .

  [31] elaborate < D_1: Declaration "," D_2: Declarations > =
         elaborate D_1 moreover elaborate D_2 .

  [32] elaborate [[ I_:Identifier  ":" T_:Type ]] =
         allocate a cell then
         (  bind I_ to the given cell
            and store the initial-value of T_ in it ) .

  * the initial-value of _ :: Type -> data .

  [33] the initial-value of "natural" = 0 .

  [34] the initial-value of "string" = "#".

  </module>




  <module> Running-Programs
  <body>

  introduces: run _ .

  %%  needs: Executing-Statements, Elaborating-Declarations.

  * run _ :: Program -> action .

  [40]  run [[ "begin" "declare" D_:Declarations ";" S_:Statements "end" ]] =
          elaborate D_ hence execute S_ .

  [41]  run [[ "begin" "declare" ";" S_:Statements "end" ]] =
           execute S_ .

  </module>

</module>
