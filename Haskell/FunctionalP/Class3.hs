module Class3 where

import Data.Maybe
import Class1

--data Hora = H Int Int deriving Show
type Etapa = (Hour2,Hour2)
type Viagem = [Etapa]

ex = (H 9 30,H 10 25)
exemplo = [(H 9 30,H 10 25),(H 11 20,H 12 45),(H 13 30, H 14 45)]

testarEtapa :: Etapa -> Bool
testarEtapa (H h1 m1,H h2 m2)
  = validHour2(H h1 m1) && validHour2(H h2 m2) && (h2>h1 || ((h1==h2) && m2 > m1))

testarViagem :: Viagem -> Bool
testarViagem [] = True
testarViagem (h:t)
  | testarEtapa h = testarViagem t
  | otherwise = False

  {-testarViagem [e] = testarEtapa e
  testarViagem (e1:e2:e3)
    = testarEtapa e1
    &&
    testarEtapa(snd e1,fst e2)
    &&
    testarViagem(e2:e3)
  -}

horaPartidaChegada :: Viagem -> (Hour2,Hour2)
horaPartidaChegada list = (fst(head list),snd(last list))

tempoViagem :: Viagem -> Int
tempoViagem [] = 0
tempoViagem (h:t) = abs(uncurry hourDifference2 h +tempoViagem t)

tempoEspera :: Viagem -> Int
tempoEspera [] = 0
tempoEspera [x] = 0
tempoEspera (f:s:t) = abs(hourDifference2(snd f) (fst s))+tempoEspera (s:t)

tempoTotal :: Viagem -> Int
tempoTotal list = abs(hourDifference2 (fst(head list)) (snd(last list)) )

type Poligono = [Ponto]

poli = [Cartesiano 0 0,Cartesiano 1 0]

comprimento :: Poligono -> Double
comprimento [] = 0
comprimento [x] = 0
comprimento (h:y:xs) = dist h y + comprimento(y:xs) -- Dist em Class1

closeLine :: Poligono -> Bool
closeLine figure = head figure == last figure

pt = [Cartesiano 0 2,Cartesiano 2 2,Cartesiano 2 0,Cartesiano 0 0,Cartesiano 0 2]

triangula :: Poligono -> [Figura]
triangula [p1,p2,p3] = []
triangula (p1:p2:p3:t) = Triangulo p1 p2 p3:triangula (p2:p3:t)

area :: Poligono -> Double
area [p1,p2,p3] = 0
--area (p1:p2:p3:t) =

mover :: Poligono -> Ponto -> Poligono
mover [] p = [p]
mover (h:t) p = p:t

zoom :: Double -> Poligono -> Poligono
zoom x (Cartesiano a b:t) = Cartesiano (a*x) (b*x):zoom x t

data Contacto
  = Casa Integer
  | Trab Integer
  | Tlm Integer
  | Email String deriving Show

-- funcoes compreensao
-- g = [x| x <- [1..10], mod x 2 == 0]
-- g2 = [(x,y) | x <- [1..10],y <- [1..5], x *y < 5]

type Nome = String
type Agenda = [(Nome,[Contacto])]

name = "Lima"
email = "sth@true.com"
genda = [("Lima",[Email email])]
--((namek,(h:t)):l
acrescEmail :: Nome -> String -> Agenda -> Agenda
acrescEmail name email (h:t) = h:(name,[Email email]):t
--
verEmails :: Nome -> Agenda -> Maybe [String]
verEmails name [] = Nothing
verEmails name ((spy,list):t) | name /= spy = verEmails name t
verEmails name ((spy,list):t) = aux list
  where
    aux (Email x:t) = Just [x]
    aux (h:t) = aux t
    aux [] = Nothing
--
consTelefs :: [Contacto] -> [Integer]
consTelefs (Email _ :t) = consTelefs t
consTelefs (Casa num:t) = num:consTelefs t
consTelefs (Trab num:t) = num:consTelefs t
consTelefs (Tlm num:t) = num:consTelefs t
consTelefs [] = []
--
casa :: Nome -> Agenda -> Maybe Integer
casa name [] = Nothing
casa name ((spy,list):t) | name /= spy = casa name t
casa name ((spy,list):t) = aux list
  where
    aux (Casa x:t) = Just x
    aux (h:t) = aux t
    aux [] = Nothing
--
type Dia = Int
type Mes = Int
type Ano = Int
data Data = D Dia Mes Ano deriving Show
type TabDN = [(Nome,Data)]
--
tab = [("Lima",D 20 4 1999),("Patricia",D 23 10 1992),("Dias",D 13 8 2000)]
procura :: Nome -> TabDN -> Maybe Data
procura name ((n,D d m a):t)
  | name == n = Just (D d m a)
  | otherwise = procura name t
procura name [] = Nothing
--
idade :: Data -> Nome -> TabDN -> Maybe Int
idade (D d m a) name ((n,D d1 m1 a1):t)
  | name == n = Just ((a - a1)+ aux m m1 d d1)
  | otherwise = idade (D d m a) name t
  where
    aux m m1 d d1
      | m1-m > 0 = -1
      | m1-m < 0 = 0
      | d1-d > 0 = -1
      | d1-d <= 0 = 0
idade (D d m a) name [] = Nothing
--
anterior :: Data -> Data -> Bool
anterior (D d m a) (D d1 m1 a1)
  | a1-a > 0 = True
  | a1-a < 0 = False
  | m1-m > 0 = True
  | m1-m < 0 = False
  | d1-d > 0 = True
  | d1-d <= 0 = False
--
data Movimento = Credito Float | Debito Float

data Extrato = Ext Float [(Data,String,Movimento)]

extValor :: Extrato -> Float -> [Movimento]
extValor Ext total ((date,string,Credito mov):t) val
  | mov > val = mov:extValor t val
  | otherwise = extValor t val
extValor [] val = []
