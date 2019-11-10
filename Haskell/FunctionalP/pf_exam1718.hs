-- 1
insert1 :: Ord a => a -> [a] -> [a]
insert1 val [] = [val]
insert1 val (h:t)
  | val > h = h : insert1 val t
  | otherwise = val : h : t

-- 2
getCat :: [Maybe a] -> [a]
getCat [] = []
getCat (Just val:t) = val : getCat t
getCat (Nothing:t) = getCat t

-- 3

data Exp a
  = Const a
  | Var String
  | Mais (Exp a) (Exp a)
  | Mult (Exp a) (Exp a)

expression :: Show a => Exp a -> String
expression (Const val) = show val
expression (Var string) = string
expression (Mais a b) = "(" ++ expression a ++ " + " ++ expression b ++ ")"
expression (Mult a b) = "(" ++ expression a ++ " * " ++ expression b ++ ")"

instance Show a => Show (Exp a) where
  show = expression

-- 4

sortOn :: Ord b => (a -> b) -> [a] -> [a]
sortOn func [] = []
sortOn func (h:t) = sort h (sortOn func t)
  where
    sort h [] = []
    sort h (x:t)
      | func h < func x = h : x : t
      | otherwise = x : sort h t

-- 5

minMax :: (Int,Int) -> [Int] -> Int
minMax (a,b) []
  | b /= a = b - a
  | otherwise = b
minMax (a,b) (h:t)
  | a > h && b >= h = minMax (h,b) t
  | a > h && b <= h = minMax (h,h) t
  | a <= h && b >= h = minMax (a,b) t
  | a <= h && b <= h = minMax (a,h) t

amplitude :: [Int] -> Int
amplitude [] = 0
amplitude (h:t) = minMax (h,h) t

-- 5.2

sort1 :: Int -> [Int] -> [Int]
sort1 h [] = []
sort1 h (x:t)
  | h < x = h : x : t
  | otherwise = x : sort1 h t

sorting :: [Int] -> [Int]
sorting [] = []
sorting (h:t) = sort1 h (sorting t)

parte :: [Int] -> [Int]
parte list = sorting list

-- 6.1
data Imagem
  = Quadrado Int
  | Mover (Int,Int) Imagem
  | Juntar [Imagem]

ex :: Imagem
ex = Mover (5,5) (Juntar [Mover (0,1) (Quadrado 5),
     Quadrado 4,
     Mover (4,3) (Quadrado 2)])

conta :: Imagem -> Int
conta (Juntar []) = 0
conta (Quadrado _) = 1
conta (Mover _ image) = conta image
conta (Juntar (h:t)) = conta h + conta (Juntar t)

apaga ::  Imagem -> IO Imagem
