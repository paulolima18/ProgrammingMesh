module Class1 where
import Data.Char

perimeter :: Double -> Double
perimeter radius = 2 * pi * radius

distance :: (Double,Double) -> (Double,Double) -> Double
distance (x1,y1) (x2,y2) = sqrt((x1-x2)^2 + (y1-y2)^2)

firstLast :: [t] -> (t,t)
firstLast list = (head list , last list)

multiple :: Int -> Int -> Bool
multiple x y = mod x y == 0

truncOdd :: [t] -> [t]
--truncOdd list = if(mod (length list) 2 == 0)then list else tail list
truncOdd list |mod(length list) 2 == 0 = list
              |otherwise = tail list

max2 :: Int -> Int -> Int
--max2 x y = if (div x y < 1) then y else x
max2 x y | x < y = y
         | otherwise = x

max3 :: Int -> Int -> Int -> Int
--max3 x y z = if (max2 x y > max2 y z) then max2 x y else max2 y z
max3 x y z | max2 x y > max2 y z = max2 x y
           | otherwise = max2 y z

--Exercise 2
nSquareRoot :: Double -> Double -> Double -> Double
nSquareRoot a b c | b^2 - 4*a*c > 0 = 2
                  | b^2 - 4*a*c == 0 = 1
                  | otherwise = 0

--root ::
--root a b c | nSquareRoot == 2 = [-b+sqrt(b^2 - 4*a*c),-b-sqrt(b^2 - 4*a*c)]
type Hour = (Int,Int)
validHour :: Hour -> Bool
validHour (a,b) = a >= 0 && a < 24 && b >= 0 && b < 60

hourLater :: Hour -> Hour -> Bool
hourLater (a,b)(c,d) | a > c = True
                     | a == c && b > d = True
                     |otherwise = False

hourMinutes :: Hour -> Int
hourMinutes (a,b) = 60*a + b

minutesHours :: Int -> Hour
minutesHours a = (div a 60,mod a 60)

hourDifference :: Hour -> Hour -> Int
hourDifference h1 h2 = hourMinutes h1 - hourMinutes h2

plusHour :: Hour -> Int -> Hour
plusHour (a,b) add |(b+add) < 60 = (a,b+add)
                   |otherwise = ((a+(div (b+add) 60)),mod (b+add) 60)

plusHour1 :: Hour -> Int -> Hour
plusHour1 hour add = let hm = hourMinutes hour
                     in minutesHours (hm+add)

data Hour2 = H Int Int deriving (Show,Eq)
h20 = H 0 15
h21 = H 23 15

validHour2 :: Hour2 -> Bool
validHour2  (H a b) = a >= 0 && a < 24 && b >= 0 && b < 60

hourLater2 :: Hour2 -> Hour2 -> Bool
hourLater2 (H a b) (H c d)
  | a > c = True
  | a == c && b > d = True
  | otherwise = False

hourMinutes2 :: Hour2 -> Int
hourMinutes2 (H a b) = 60*a + b

minutesHours2 :: Int -> Hour2
minutesHours2 a = (H (div a 60) (mod a 60))

hourDifference2 :: Hour2 -> Hour2 -> Int
hourDifference2 hour1 hour2 = hourMinutes2 hour1 - hourMinutes2 hour2

plusHour2 :: Hour2 -> Int -> Hour2
plusHour2 (H a b) add
  |(b+add) < 60 = (H a (b+add))
  |otherwise = (H (a+(div (b+add) 60)) (mod (b+add) 60))

plusHour22 :: Hour2 -> Int -> Hour2
plusHour22 hour add = let hm = hourMinutes2 hour
                     in  minutesHours2 (hm+add)

{--cria :: Int -> [[Int]]
cria 0 = []
cria x = aux x : cria (x-1)
 where
   aux 0 = []
   aux damn = damn: aux (damn-1)
--}

data Semaforo = Verde | Amarelo | Vermelho deriving (Show,Eq)

next :: Semaforo -> Semaforo
next Verde = Amarelo
next Amarelo = Vermelho
next Vermelho = Verde

stop :: Semaforo -> Bool
stop Vermelho = True
stop _ = False

safe :: Semaforo -> Semaforo -> Bool
safe _ Vermelho = True
safe Vermelho _ = True
safe _ _ = False

data Ponto = Cartesiano Double Double | Polar Double Double deriving (Show,Eq)
valc = Cartesiano (-1) 0
valp = Polar 1 pi

pontoVer :: Ponto -> Ponto -> Ponto
pontoVer p1 p2 = (Cartesiano (posx p1) (posy p2))

posx :: Ponto -> Double
posx (Cartesiano x y) = x
posx (Polar r a) = cos(a)*r

posy :: Ponto -> Double
posy (Cartesiano x y) = y
posy (Polar r a) = sin(a)*r

raio :: Ponto -> Double
raio (Cartesiano x y) = sqrt( (x^2) + (y^2) )
raio (Polar r a) = r

dist :: Ponto -> Ponto -> Double
dist p1 p2 = sqrt(((posx p1)-(posx p2))^2 + ((posy p1)-(posy p2))^2 )

data Figura = Circulo Ponto Double
  | Rectangulo Ponto Ponto
  | Triangulo Ponto Ponto Ponto deriving (Show,Eq)

cu = Circulo valc 1
ret = Rectangulo valc (Cartesiano 0 1)
tri = Triangulo valc (Cartesiano 0 1) (Cartesiano 1 0)

poligono :: Figura -> Bool
poligono (Circulo p d) = False
poligono _ = True

vertices :: Figura -> [Ponto]
vertices (Circulo p d) = []
vertices (Triangulo c c1 c2) = [pontoVer c c,pontoVer c1 c1,pontoVer c2 c2]
vertices (Rectangulo c c1) = [pontoVer c c,pontoVer c c1,pontoVer c1 c1,pontoVer c1 c]

area :: Figura -> Double
area (Triangulo p1 p2 p3) =
  let a = dist p1 p2
      b = dist p2 p3
      c = dist p3 p1
      s = (a+b+c) / 2 -- semi-perimetro
  in sqrt (s*(s-a)*(s-b)*(s-c)) -- formula de Heron
area (Circulo p d) = 2 * pi * d^2
area (Rectangulo c c1) = abs( (dist (pontoVer c c) (pontoVer c1 c)) * (dist (pontoVer c c1) (pontoVer c c)))


isLower1 :: Char -> Bool
isLower1 char = char >= 'a' && char <= 'z'

isDigit1 :: Char -> Bool
isDigit1 dig = dig >= '0' && dig <= '9'

isAlpha1 :: Char -> Bool
isAlpha1 char = isLower char || char >= 'A' && char <= 'Z'

toUpper1 :: Char -> Char
toUpper1 char
  | isLower char = chr(ord char + (ord 'a'- ord 'Z'))
  | otherwise = char

intToDigit1 :: Int -> Char
intToDigit1 num
  | (num >= 0 && num < 10) = chr( ord '0' + num)
  | (num >= 10 && num < 16) = chr ( ord 'a' + num-10)
  | otherwise = 'N'

digitToInt1 :: Char -> Int
digitToInt1 char
  | (char >= '0' && char <= '9') = ord char - ord '0'
  | (char >= 'a' && char <= 'f') = ord char - ord 'a' + 10
