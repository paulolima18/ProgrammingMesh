import Data.Either
--(1)
enumFromTo1 :: Int -> Int -> [Int] --Create List from start to end
enumFromTo1 start end | start == end = [end]
                      | otherwise = start:enumFromTo1 (start+1) end
--(2)
enumFromThenTo1 :: Int -> Int -> Int -> [Int] --
enumFromThenTo1 a b c | a > c = []
                      | otherwise = a:enumFromThenTo1 b (b+(b-a)) c
--(3)
(+-+) :: [a] -> [a] -> [a]
(+-+) [] [] = []
(+-+) [] (c:d) = c: (+-+)[] d
(+-+) (a:[]) (c:d) = a: (+-+)[] (c:d)
(+-+) (a:b) (c:d) = a:(+-+) b (c:d)
--(4)
(!-!) :: [a] -> Int -> a
(!-!) (a:b) 0 = a
(!-!) (a:b) index = (!-!) b (index-1)
--(5)
reverse1 :: [a] -> [a]
reverse1 [] = []
reverse1 a = last a:reverse1 (init a)
--(6)
take1 :: Int -> [a] -> [a]
take1 0 (a:b) = []
take1 num (a:[]) = [a]
take1 num (a:b) = a: take1 (num-1) b
--(7)
drop1 :: Int -> [a] -> [a]
drop1 0 (a:b) = a:b
drop1 num [] = []
drop1 num (a:b) = drop1 (num-1) b
--(8)
zip1 :: [a] -> [b] -> [(a,b)]
zip1 (a:[]) (c:d) = (a,c):[]
zip1 (a:b) (c:[]) = (a,c):[]
zip1 (a:b) (c:d) = (a,c):zip1 b d
--(9)
elem1 :: Eq a => a -> [a] -> Bool
elem1 num [] = False
elem1 num (a:b) | num == a = True
                | otherwise = elem1 num b
  --(10)
replicate1 :: Int -> a -> [a]
replicate1 0 num = []
replicate1 range num = num:replicate1 (range-1) num
--(11)
intersperse1 :: a -> [a] -> [a]
intersperse1 num (a:[]) = [a]
intersperse1 num (a:b) = a:num:intersperse1 num b
--(12)
group1 :: Eq a => [a] -> [[a]]
group1 [] = []
group1 list = aux list:group1 (drop(length(aux list)) list)
  where
    aux (h:[]) = [h]
    aux (h:t)
      | h == head(t) = h:aux t
      | otherwise = [h]
--(13)
concat1 :: [[a]] -> [a]
concat1 [] = []
concat1 ([]:b) = concat1 b
concat1 (a:b) = head(a):concat1 (tail(a):b)
--(14)
inits1 :: [a] -> [[a]]
inits1 [] = [[]]
inits1 (h:t) = []:(aux h (inits1 t))
  where
    aux x [] = []
    aux x (y:y2) = (x:y):(aux x y2)
--(15)
tails1 :: [a] -> [[a]]
tails1 [] = [[]]
tails1 (h:t) = (h:t):tails1 t
--(16)
isPrefixOf1 :: Eq a => [a] -> [a] -> Bool
isPrefixOf1 [] list = True
isPrefixOf1 (h:t) (x:y)
  | h == x = isPrefixOf1 t y
  | otherwise = False
--(17)
isSuffixOf1 :: Eq a => [a] -> [a] -> Bool
isSuffixOf1 [] list = True
isSuffixOf1 l1 l2
  | last(l1) == last(l2) = isSuffixOf1 (init l1) (init l2)
  | otherwise = False
--(18)
isSubsequenceOf1 :: Eq a => [a] -> [a] -> Bool
isSubsequenceOf1 [] _ = True
isSubsequenceOf1 _ [] = False
isSubsequenceOf1 (h:t) (x:y)
  | h == x = isSubsequenceOf1 t y
  | otherwise = isSubsequenceOf1 (h:t) y
--(19)
elemIndices1 :: Eq a => a -> [a] -> [Int]
elemIndices1 x [] = []
elemIndices1 x (h:t) = aux x (h:t) 0
  where
    aux x [] k = []
    aux x (h:t) k
     | x == h = k:aux x t (k+1)
     | otherwise = aux x t (k+1)
--(20)
nub1 :: Eq a => [a] -> [a]
nub1 [] = []
nub1 (h:t)
  | aux h t = h:nub1 t
  | otherwise = nub1 t
  where
    aux h [] = True
    aux h (t:d)
      | h == t = False
      | otherwise = aux h d

nub2 :: Eq a => [a] -> [a]
nub2 [] = []
nub2 (h:t)
  | elem h t = nub2 t
  | otherwise = h:nub2 t
--(21)
delete :: Eq a => a -> [a] -> [a]
delete x [] = []
delete x (h:t)
  | x == h = head(t):tail(t)
  | otherwise = h:delete x t
--(22)
(\-\) :: Eq a => [a] -> [a] -> [a]
(\-\) list [] = list
(\-\) [] list = []
(\-\) (h:t) (x:y)
  | h == x = (\-\) t y
  | otherwise = h:(\-\) t (x:y)

meh :: Eq a => [a] -> [a] -> [a]
meh l1 [] = l1
meh l1 (x:y) = meh (aux l1 (x:y)) y
  where
    aux [] [] = []
    aux (h:t) [] = h:aux t []
    aux (h:t) (x:y)
      | h == x = aux t []
      | otherwise = h:aux t (x:y)
--(23)
union1 :: Eq a => [a] -> [a] -> [a]
union1 [] list = list
union1 list [] = list
union1 l1 l2 = aux l1 l2
  where
    aux [] (x:_) = x:[]
    aux (h:t) (x:y)
      | h == x = union1 (h:t) y
      | otherwise = h:aux t (x:y)
--(24)
intersect1 :: Eq a => [a] -> [a] -> [a]
intersect1 l [] = []
intersect1 [] l = []
intersect1 (h:t) l2
  | elem h l2 = h:intersect1 t l2
  | otherwise = intersect1 t l2
  --(25)
insert1 :: Ord a => a -> [a] -> [a]
insert1 x [] = x:[]
insert1 x (h:t)
  | x <= h = x:h:t
  | otherwise = h:insert1 x t
--(26)
unwords1 :: [String] -> String
unwords1 ([]:[]) = []
unwords1 ([]:t) = ' ':unwords1 t
unwords1 (h:t) = head(h):unwords1(tail(h):t)
--(27)
unlines1 :: [String] -> String
unlines1 [] = []
unlines1 ([]:t) = '\n':unlines1 t
unlines1 (h:t) = head(h):unlines1(tail(h):t)
--(28)
pMaior :: Ord a => [a] -> Int
pMaior (x:[]) = 0
pMaior (h:t)
  | h > maximum t = 0
  | otherwise = 1 + pMaior t
--(29)
temRepetidos :: Eq a => [a] -> Bool
temRepetidos [] = False
temRepetidos (h:t)
  | elem h t = True
  | otherwise = temRepetidos t
--(30)
algarismos :: [Char] -> [Char]
algarismos [] = []
algarismos (h:t)
  | h >= '0' && h <= '9' = h:algarismos t
  | otherwise = algarismos t
--(31)
posImpares :: [a] -> [a]
posImpares [] = []
posImpares (_:[]) = []
posImpares (h:h1:t) = h1:posImpares t
--(32)
posPares :: [a] -> [a]
posPares [] = []
posPares (h:[]) = h:[]
posPares (h:h1:t) = h:posPares t
--(33)
isSorted :: Ord a => [a] -> Bool
isSorted [] = True
isSorted (x:[]) = True
isSorted (h:t)
  | h > minimum t = False
  | otherwise = isSorted t
--(34)
iSort :: Ord a => [a] -> [a]
iSort [] = []
iSort (h:t) = insert1 h (iSort t)
--(35)
menor :: String -> String -> Bool
menor list [] = False
menor [] list = True
menor (h:t) (x:y)
  | h == x = menor t y
  | h < x = True
  | otherwise = False
--(36)
elemMSet :: Eq a => a -> [(a,Int)] -> Bool
elemMSet x [] = False
elemMSet x (h:t)
  | x == fst h = True
  | otherwise = elemMSet x t
--(37)
lengthMSet :: [(a,Int)] -> Int
lengthMSet [] = 0
lengthMSet (h:t) = (snd h )+lengthMSet t
--(38)
converteMSet :: [(a,Int)] -> [a]
converteMSet [] = []
converteMSet ((a,i):t)
  | i > 0 = a:converteMSet ((a,(i-1)):t)
  | otherwise = converteMSet t
--(39)
insereMSet :: Eq a => a -> [(a,Int)] -> [(a,Int)]
insereMSet x [] = []
insereMSet x (h:t)
  | x == fst h = ((fst h),((snd h)+1)):t
  | otherwise = h:insereMSet x t
--(40)
removeMSet :: Eq a => a -> [(a,Int)] -> [(a,Int)]
removeMSet x [] = []
removeMSet x (h:t)
  | (x == fst h) && (snd h == 1) = removeMSet x t
  | (x == fst h) && (snd h > 1) = (fst h,((snd h)-1) ):removeMSet x t
  | otherwise = h:removeMSet x t
--(41)
constroiMSet :: Ord a => [a] -> [(a,Int)]
constroiMSet (h:[]) = [(h,1)]
constroiMSet (h:h1:t)
  | h == h1 = (h,aux(h:h1:t)):constroiMSet(drop(aux(h:h1:t)) (h:h1:t))
  | otherwise = (h,1):constroiMSet (h1:t)
  where
    aux (h:h1:t)
      | h == h1 = 1 + aux(h1:t)
      | otherwise = 1
--(42)
partitionEithers1 :: [Either a b] -> ([a],[b])
partitionEithers1 [] = ([],[])
partitionEithers1 ((Left a):t) =
  let (as,bs) = partitionEithers1 t
  in (a:as,bs)
partitionEithers1 ((Right b):t) =
  let (as,bs) = partitionEithers1 t
  in (as,b:bs)
--(43)
catMaybes :: [Maybe a] -> [a]
catMaybes [] = []
catMaybes (Nothing:t) = catMaybes t
catMaybes ((Just a):t) = a:catMaybes t
--(44)
data Movimento = Norte | Sul | Este | Oeste deriving Show -- assumindo que anda 1 em cada direcao
posicao :: (Int,Int) -> [Movimento] -> (Int,Int)
posicao (x,y) [] = (x,y)
posicao (x,y) (Norte:t) = posicao (x,y+1) t
posicao (x,y) (Sul:t) = posicao (x,y-1) t
posicao (x,y) (Este:t) = posicao (x+1,y) t
posicao (x,y) (Oeste:t) = posicao (x-1,y) t
--(45)
caminho :: (Int,Int) -> (Int,Int) -> [Movimento]
caminho (x,y) (x1,y1)
  | y > y1 = Sul:caminho (x,y-1) (x1,y1)
  | y < y1 = Norte:caminho (x,y+1) (x1,y1)
  | (y == y1 && x > x1) = Oeste:caminho (x-1,y) (x1,y1)
  | (y == y1 && x < x1) = Este:caminho (x+1,y) (x1,y1)
  | otherwise = []
--(46)
vertical :: [Movimento] -> Bool
vertical [] = True
vertical (Este:t) = False
vertical (Oeste:t) = False
vertical (Sul:t) = vertical t
vertical (Norte:t) = vertical t
--(47)
data Posicao = Pos Int Int deriving Show
maisCentral :: [Posicao] -> Posicao
maisCentral [(Pos a b)] = Pos a b
maisCentral ((Pos a b):(Pos c d):t)
  | sqrt((fromIntegral a^2) + (fromIntegral b^2)) >= sqrt((fromIntegral c^2) + (fromIntegral d^2)) = maisCentral ((Pos c d):t)
  | otherwise = maisCentral ((Pos a b):t)
--(48)
vizinhos :: Posicao -> [Posicao] -> [Posicao]
vizinhos pos [] = []
vizinhos (Pos a b) ((Pos c d):t)
  | (a == c || b == d) = vizinhos (Pos a b) t
  | otherwise = (Pos c d):vizinhos (Pos a b) t
--(49)
mesmaOrdenada :: [Posicao] -> Bool
mesmaOrdenada [pos] = True
mesmaOrdenada ((Pos a b):(Pos c d):t)
  | b == d = mesmaOrdenada ((Pos c d):t)
  | otherwise = False
--(50)

data Semaforo = Verde | Amarelo | Vermelho deriving Show
ok :: [Semaforo] -> Bool
ok [] = True
ok l = aux l 0
  where
    aux (Vermelho:t) x =
      | x <= 1 = aux l x
      | otherwise = False
    aux (_:t) =
      | x <= 1 = aux l (x+1)
      | otherwise = False
--interseccaoOK :: [Semaforo] -> Bool
--interseccaoOK (h:h1:t)
--  |
{-
data Semaforo = Verde | Amarelo | Vermelho deriving (Show,Eq)
interseccaoOK :: [Semaforo] -> Bool
interseccaoOK [] = True
interseccaoOK (h:t) = aux h
  where --true seguro de passar
    aux Vermelho = interseccaoOK t
    aux Verde = not((elem Verde t) || (elem Amarelo t))
    aux Amarelo = not((elem Verde t) || (elem Amarelo t))
-}
