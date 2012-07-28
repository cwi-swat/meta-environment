module Infix where {

infixl 10 +, - ;
infixl 15 * ;

big :: Int;
big = (+) 1 + 2 * 3 - 4;

}