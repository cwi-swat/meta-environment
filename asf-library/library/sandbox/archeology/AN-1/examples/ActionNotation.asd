<module> ActionNotation
  <body>

  <module> Actions
  <body>
  %%  needs: Yielders .

  introduces:
    action ,
    complete , fail , unfold , unfolding _ ,
    _ or _ ,  _ and _ ,  _ and then _ ,
    give _ , check _ , _ then _ ,
    bind _ to _ , _ moreover _ , _ hence _ ,
    allocate _ , store _ in _ .

  * complete         : action .
  * fail             : action .
  * unfold           : action .
  * unfolding _     :: action -> action .
  *  _ or _         :: action, action -> action
                       (associative, commutative, idempotent, unit is fail).
  *  _ and _        :: action, action -> action
                       (associative, unit is complete).
  *  _ and then _   :: action, action -> action .

  * give _          :: yielder -> action .
  * check _         :: yielder -> action
                       (associative, unit is complete).
  * _ then _        :: action, action -> action .

  * bind _ to _     :: yielder, yielder -> action
                       (associative) .
  * _ moreover _    :: action, action -> action
                       (associative, unit is complete) .
  * _ hence _       :: action, action -> action
                       (associative) .

  * allocate _      :: yielder -> action .
  * store _ in _    :: yielder, yielder -> action .
  </module>


  <module> Yielders
  <body>

  %%  needs: Data.
  introduces:
    yielder ,
    the _ yielded by _ ,
    given _ , given _#_ , it ,
    the _ bound to _ ,
    the _ stored in _ .

  * the _ yielded by _  :: data, yielder -> yielder .

  * given _             :: data -> yielder (strict) .
  * given _ # _         :: datum, natural -> yielder .
  * it                   : yielder .

  * the _ bound to _    :: yielder, yielder -> yielder .

  * the _ stored in _   :: yielder, yielder -> yielder .

  includes: ActionNotation-Y.
  </module>


  <module> Data
  <body>
  %%  includes: DataNotation/General.
  includes: DataNotation.
  introduces:
    datum , data , a _ , an _ , the _ , of _ ,
    token , bindable , cell , storable .

  * data = datum* .
  * a _ , an _ , the _ , of _ :: yielder -> yielder (total) .

  (1) d_ =< data =>
      (10) a   d_ = d_ ;
      (11) an  d_ = d_ ;
      (12) the d_ = d_ ;
      (13) of  d_ = d_ .

  </module>

</module>
