module SOS where {

-- Booleans

data Bool = False | True;

-- Integers

square :: int -> int;
square = \x -> (x * x);

-- Lists

data List a = Nil | Cons a (List a);

map :: (a -> b) -> List a -> List b;
map = \f l ->
      case l of 
     { Nil       -> Nil
     ; Cons x xs -> Cons(f x)(map f xs)
     };

foldr :: b -> (a -> b -> b) -> List a -> b;
foldr = \n c xs -> 
        case xs of
        { Nil       -> n
        ; Cons y ys -> c y (foldr n c ys)
        };

upto :: Int -> Int -> List Int;
upto = \low high ->
       case low > high of
       { False -> Cons low (upto(low + 1)(high))
       ; True  -> Nil
       };

sum :: List Int -> Int;
sum = foldr 0 (+);

sos :: Int -> Int -> Int;
sos = \lo hi ->
      sum(map(square)(upto lo hi))

}
