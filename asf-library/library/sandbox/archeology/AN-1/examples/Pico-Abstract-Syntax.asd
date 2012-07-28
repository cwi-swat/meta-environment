<module> Pico/Abstract-Syntax
<body>
  includes: StandardLexical.
  <grammar>
  *  Numeral          = [[ Digit+ ]] .
  *  Character-String = [[ '"' Graphic-Character* '"' ]] .
  *  Literal          = Numeral | Character-String .
  *  Identifier       = [[ LowercaseLetter <LowercaseLetter|Digit>* ]] .
  *  Expression       = Literal | Identifier |
                        [[ Expression Operator Expression ]]   |
                        [[ "(" Expression ")" ]] .
  *  Operator         = "+" | "-" |  "||".
  *  Statement        = [[ Identifier ":=" Expression ]] |
                        [[ "if" Expression "then" Statements
                           < "else" Statements >?  "fi" ]]  |
                        [[ "while" Expression "do" Statements "od" ]] |
                        [[ "repeat" Statements "until" Expression ]] .
  *  Statements       = < Statement < ";" Statement >* > .
  *  Declaration      = [[ Identifier ":"  Type ]] .
  *  Declarations     = < Declaration < "," Declaration > * > .
  *  Type             = "natural" | "string" .
  *  Decls            = [[ "declare" Declarations? ";" ]] .
  *  Program          = [[ "begin" Decls Statements "end" ]] .
  </grammar>
</module>
