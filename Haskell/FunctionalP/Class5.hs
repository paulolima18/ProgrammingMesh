module Class5 where
import Data.List
--1
--a
any1 :: (a -> Bool) -> [a] -> Bool
any1 func (h:t) = foldr ((||).func) False t
--b
zipWith1 :: (a->b->c) -> [a] -> [b] -> [c]
zipWith1 func (x:xs) (y:ys) = func x y:zipWith1 func xs ys
zipWith1 func _ _ = []
--c
takeWhile1 :: (a -> Bool) -> [a] -> [a]
takeWhile1 func (h:t)
 | func h = h:takeWhile1 func t
 | otherwise = []
takeWhile1 func [] = []
--d
len :: [a] -> Int
len  = foldr func 0
  where func x r = r+1
dropWhile1 :: (a -> Bool) -> [a] -> [a]
dropWhile1 func (h:t)
  | func h = dropWhile1 func t
  | otherwise = h:t
dropWhile1 func [] = []
--e
span1 :: (a -> Bool) -> [a] -> ([a],[a])
span1 func [] = ([],[])
span1 func (x:xs) | func x = (x:lt,ld)
                  | otherwise = ([],x:xs)

    where (lt,ld) = span1 func xs
--f
deleteBy1 :: (a -> a -> Bool) -> a -> [a] -> [a]
deleteBy1 func a (h:t)
  | func a h = t
  | otherwise = h:deleteBy1 func a t
deleteBy1 func a [] = []
--g
--sortOn1 :: Ord b => (a -> b) -> [a] -> [a]
--sortOn1 func ((a,b):t) =
--2
--a
type Polinomio = [Monomio]
type Monomio = (Float,Int)

p :: Polinomio
p = [(2,3),(4,5),(5,3),(3,4)]
--a
selgrau :: Int -> Polinomio -> Polinomio
selgrau x = filter func
  where func (c,g) = g == x
--b
conta :: Int -> Polinomio -> Int
conta grau = foldl func 0
  where
    func r (a,b)
      | grau == b = r+1
      | otherwise = r
--c
grau :: Polinomio -> Int
grau = foldr func 0
  where
    func (a,b) r
      | r < b = b
      | otherwise = r
grau' :: Polinomio -> Int
grau' = foldr (\ (a,b) r -> max b r) 0
--d
deriv :: Polinomio -> Polinomio
deriv = map func
  where func (c,g) = (c* fromIntegral g,g-1)
-- e
calcula :: Float -> Polinomio -> Float
calcula f = foldr func 0.0
  where func (a,b) r = a* f^b +r
--f
simp :: Polinomio -> Polinomio
simp = filter func
  where func (c,g) = c == 0
--g
mult :: Monomio -> Polinomio -> Polinomio
mult (a,b) = map func
  where func (c,g) = (c*a,g+b)
