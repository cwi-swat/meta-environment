<module> Pico/Semantic-Entities
<body>

  includes: ActionNotation, Pico/Abstract-Syntax,
            Pico/Semantic-Entities-Y .

  introduces: value .

  * Numeral =< natural .
  * Character-String =< string .
  * Identifier =< token .

  * value = natural | string | token | cell .
  * truth-value, value  =< datum .

  * bindable = cell .
  * storable = value .

</module>
