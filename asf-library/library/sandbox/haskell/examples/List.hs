module List where {
--import Tuple;
{- This is comment to demonstrate {- nested comments in Haskell -} -}

data List a = Nil | Cons a (List a);

mapList f Nil = Nil;
mapList f (Cons x xs) = Cons(f x)(mapList f xs);

mymap f [] = [];
mymap f (x : xs) = f x : mymap f xs;

myfoldr plus zero [] = zero;
myfoldr plus zero (x : xs) = x `plus` myfoldr plus zero xs

}  