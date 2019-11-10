import Data.Char

dobros :: [Float] -> [Float]
dobros list = map (2*) list

numOcorre :: Char -> String -> Int
numOcorre char [] = 0
numOcorre char (a:b)
  | char == a = 1+numOcorre char b
  | otherwise = numOcorre char b

positivos :: [Int] -> Bool
positivos [] = True
positivos (a:b)
  | a > 0 = positivos b
  | otherwise = False

soPos :: [Int] -> [Int]
soPos [] = []
soPos (a:b)
  | a > 0 = a:soPos b
  | otherwise = soPos b

somaNeg :: [Int] -> Int
somaNeg [] = 0
somaNeg (a:b)
  | a < 0 = a+somaNeg b
  | otherwise = somaNeg b

tresUlt :: [a] -> [a]
tresUlt [] = []
tresUlt l
  | length(l) == 3 = l
  | length(l) > 3 = tresUlt (tail l)
  | otherwise = l

segundos :: [(a,b)] -> [b]
segundos [] = []
segundos (h:t) = (snd h):segundos t

nosPrimeiros :: (Eq a) => a -> [(a,b)] -> Bool
nosPrimeiros a [] = False
nosPrimeiros a (b:c)
  | a == fst b = True
  | otherwise = nosPrimeiros a c

sumTriplos :: (Num a, Num b, Num c) => [(a,b,c)] -> (a,b,c)
first (a,_,_) = a
second (_,a,_) = a
third (_,_,a) = a
sumTriplos (a:b) = (first(a)+first(head b)+first(last b),second(a)+second(head b)+second(last b),third(a)+third(head b)+third(last b))

soDigitos :: [Char] -> [Char]
soDigitos [] = []
soDigitos (a:b)
  | a >= '0' && a <= '9' = a:soDigitos b
  | otherwise = soDigitos b

minusculas :: [Char] -> Int
minusculas [] = 0
minusculas (a:b)
  | a >= 'a' && a <= 'z' = 1+minusculas b
  | otherwise = minusculas b

nums :: String -> [Int]
nums [] = []
nums (a:b)
  | a >= '0' && a <= '9' = (ord a - ord ('0')): nums b
  | otherwise = nums b

type Polinomio = [Monomio]
type Monomio = (Float,Int)



conta :: Int -> Polinomio -> Int
conta n [] = 0
conta n (a:b)
  | snd(a) == n = 1+conta n b
  | otherwise = conta n b

grau :: Polinomio -> Int
grau (a:b) = 1 -- not done

selgrau :: Int -> Polinomio -> Polinomio
selgrau n [] = []
selgrau n (a:b)
  | n == snd(a) = a:selgrau n b
  | otherwise = selgrau n b

deriv :: Polinomio -> Polinomio
deriv [] = []
deriv (a:b) = (fromIntegral(snd a)*fst a,(snd a)-1):deriv b

calcula :: Float -> Polinomio -> Float
calcula val [] = 0
--calcula val (a:b) = realToFrac(fromIntegral(fst a)* fromIntegral(val^(snd a)))+ calcula val b -- not done

simp :: Polinomio -> Polinomio
simp [] = []
simp (a:b)
  | (fst a) == 0 = simp b
  | otherwise = a:simp b

mult :: Monomio -> Polinomio -> Polinomio
mult (f,i) [] = []
mult (f,i) (a:b) = (f*fst a,i+snd a): mult (f,i) b

normaliza :: Polinomio -> Polinomio
normaliza (a:b)

soma :: Polinomio -> Polinomio -> Polinomio
soma (h:t) (a:b) = snd(h) ==
