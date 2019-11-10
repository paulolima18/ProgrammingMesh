{- | Este módulo define funções para a competição de compressão de 'Estado's do jogo __Bomberman__.

 O objectivo desta competição é, dada uma descrição do 'Estado' do jogo implementar um mecanismo de compressão / descompressão que permita poupar caracteres e, desta forma, poupar espaço em disco quando o estado do jogo for gravado (permitindo, por exemplo, fazer pausa durante o jogo com o objectivo de o retomar mais tarde).

 O mecanismo de codificação tem que ser invertível, ou seja, dado um qualquer 'Estado' do jogo ​@e@, tem que ser sempre verdade que:

 prop> descomprime (comprime e) == e

 O método de avaliação da qualidade de compresssão é o comprimento da 'ByteString' resultante.
-}
module Compressao_flat where

import qualified Data.Map as Map
import qualified Data.ByteString.Char8 as B
import Bomberman

maps =[[Pedra,Pedra,Pedra,Pedra,Pedra,Pedra,Pedra,Pedra,Pedra,Pedra,Pedra,Pedra],
       [Pedra,Vazio,Pedra,Vazio,Pedra,Vazio,Pedra,Vazio,Tijolo,Vazio,Vazio,Pedra],
       [Pedra,Vazio,Vazio,Vazio,Vazio,Vazio,Vazio,Vazio,Vazio,Vazio,Vazio,Pedra],
       [Pedra,Tijolo,Tijolo,Tijolo,Pedra,Tijolo,Pedra,Tijolo,Pedra,Tijolo,Tijolo,Pedra],
       [Pedra,Vazio,Vazio,Vazio,Vazio,Vazio,Vazio,Vazio,Vazio,Vazio,Vazio,Pedra],
       [Pedra,Vazio,Vazio,Vazio,Vazio,Vazio,Vazio,Vazio,Vazio,Vazio,Vazio,Pedra],
       [Pedra,Vazio,Vazio,Vazio,Tijolo,Vazio,Vazio,Vazio,Tijolo,Vazio,Vazio,Pedra],
       [Pedra,Vazio,Vazio,Vazio,Vazio,Vazio,Vazio,Vazio,Vazio,Vazio,Vazio,Pedra],
       [Pedra,Vazio,Vazio,Tijolo,Vazio,Vazio,Vazio,Vazio,Tijolo,Vazio,Vazio,Pedra],
       [Pedra,Vazio,Vazio,Vazio,Vazio,Vazio,Vazio,Vazio,Vazio,Vazio,Vazio,Pedra],
       [Pedra,Tijolo,Tijolo,Tijolo,Tijolo,Tijolo,Tijolo,Tijolo,Tijolo,Tijolo,Tijolo,Pedra],
       [Pedra,Pedra,Pedra,Pedra,Pedra,Pedra,Pedra,Pedra,Pedra,Pedra,Pedra,Pedra]]

maps1 =[[Pedra,Pedra,Pedra,Pedra,Pedra,Pedra],
      [Pedra,Tijolo,Tijolo,Vazio,Vazio,Pedra],
      [Pedra,Pedra,Pedra,Pedra,Pedra,Pedra],
      [Pedra,Vazio,Vazio,Vazio,Vazio,Pedra],
      [Pedra,Vazio,Vazio,Vazio,Vazio,Pedra],
      [Pedra,Pedra,Pedra,Pedra,Pedra,Pedra]]

soma :: Word -> Word -> (Word,Word)
soma a b = (a,b)
{-
P -- Pedra
V -- Vazio
T -- Tijolo
_//_
Q -- Linha de Pedras
W -- Linhas de Vazios
E -- Linhas de Tijolos
//
# -- End of Element
$ -- End of List
F -- Flames
B -- Bombs
-}
powers = Map.fromList [((1,1),Flames),((3,3),Bombs),((5,5),Bombs),((7,7),Flames)]
bomb = Map.fromList [((3,3),Bomba 2 1 1),((1,6),Bomba 0 0 1),((8,2),Bomba 3 1 1),((7,2),Bomba 2 1 1)]
player = Map.fromList [(0,Jogador (1,1) 1 1),(1,Jogador (3,3) 2 3),(3,Jogador (6,3) 2 3),(2,Jogador (3,6) 2 3)]
play = Estado maps powers bomb player
--
powers1 = Map.fromList []
bomb1 = Map.fromList []
player1 = Map.fromList [(0,Jogador (1,1) 1 1)]
play1 = Estado maps1 powers1 bomb1 player1

--
isDigit :: Char -> Bool
isDigit char = char >= '0' && char <= '9'
--
isntDigit :: Char -> Bool
isntDigit char = char < '0' || char > '9'

-- | Comprimento do mapa
mapaSize :: Mapa -> Int
mapaSize mapa = length (head mapa)
-- |
noRoof :: Mapa -> Mapa
noRoof (h:t) = take ((-2)+(mapaSize t)) t
-- |
lineFirstDown :: [Bloco] -> String
lineFirstDown [] = "n"
lineFirstDown (Pedra:t) = 'P':lineFirstDown t
lineFirstDown (Vazio:t) = 'V':lineFirstDown t
lineFirstDown (Tijolo:t) = 'T':lineFirstDown t

-- | Transforming a map into a String
mapFirstDown :: Int -> Mapa -> String
mapFirstDown size [] = "f"
mapFirstDown size (h:t)
  = lineFirstDown (take size (tail h)) ++ mapFirstDown size t

-- | Agrupa em Blocos iguais
group :: String -> String
group list = (takeWhile (/='n') list)
--
joint :: Int -> String -> String
joint count [] = []
joint count (x:y:z)
  | x /= y && count == 0 = x:joint 0 (y:z)
  | x /= y && count > 0 = show (count+1) ++ [x] ++ joint 0 (y:z)
  | x == y = joint (count+1) (y:z)
joint count (x:z)
  | count == 0 = [x]
  | otherwise = show (count+1) ++ [x]

-- | Doing the same as "mapFirstDown" but smaller
mapSecondDown :: String -> String
mapSecondDown ('f':_) = "f"
mapSecondDown list
  = joint 0 (group list)++"n"
  ++ mapSecondDown (drop 1 (dropWhile (/='n') list))
--
mapResume :: Mapa -> String
mapResume mapa
  = mapFourthDown (mapaSize mapa)
  (compact 0 'a'
  (mapThirdDown ((mapaSize mapa)-2)
  (mapSecondDown (mapFirstDown ((mapaSize mapa)-2) (noRoof mapa)))))

-- | Receives "WnEnEnWnWnEnWnWnWnWnf"
compact :: Int -> Char -> String -> String
compact 0 char ('f':_) = "f"
compact val char ('f':_) = show val ++ [char] ++ "nf"
compact val char (h:t)
  | (h == 'W' || h == 'Q' || h == 'E') && (h /= t!!1) && val == 0
    = ([h]++"n") ++ compact 0 h (tail t)
  | (h == 'W' || h == 'Q' || h == 'E') && (h /= t!!1) && val > 0
    = show (val+1) ++ [h]++"n"++compact 0 h (tail t)
  | (h == 'W' || h == 'Q' || h == 'E') && (h == t!!1)
    = compact (val+1) h (tail t)
  | otherwise = takeWhile (/='n') (h:t) ++ "n" ++ compact 0 h (drop 1 (dropWhile (/='n') (h:t)))

-- | Doing the same as "mapSecondDown" but even smaller
mapThirdDown :: Int -> String -> String
mapThirdDown size ('f':_) = "f"
mapThirdDown size (h:t)
  | isDigit h && (read (takeWhile isDigit (h:t))) == size && ((head (dropWhile isDigit (h:t))) == 'V')
    = "Wn" ++ mapThirdDown size (drop 1 (dropWhile (/='n') (h:t)))
  | isDigit h && (read (takeWhile isDigit (h:t))) == size && ((head (dropWhile isDigit (h:t))) == 'P')
    = "Qn"++mapThirdDown size (drop 1 (dropWhile (/='n') (h:t)))
  | isDigit h && (read (takeWhile isDigit (h:t))) == size && ((head (dropWhile isDigit (h:t))) == 'T')
    = "En"++mapThirdDown size (drop 1 (dropWhile (/='n') (h:t)))
  | otherwise = takeWhile (/='n') (h:t) ++"n"++ mapThirdDown size (drop 1 (dropWhile (/='n') (h:t)))
--
dope :: String -> Bool
dope "W" = True
dope "Q" = True
dope "E" = True
--
mapFourthDown ::Int -> String -> String
mapFourthDown size [] = []
mapFourthDown size string
  |(isDigit (head(string))) && read(takeWhile isDigit string) == (size-2)
   && dope (take 1 (dropWhile isDigit string))
    = (takeWhile isDigit string)++take 1(dropWhile isDigit string)
  | otherwise
    = (takeWhile isDigit string)++take 1(dropWhile isDigit string)
      ++ mapFourthDown size (drop 1 (dropWhile isDigit string))
--
superManDown :: PowerUps -> String
superManDown power
  = filter (\x ->  (x/='[') && (x/=']') && (x/='(') && (x/=')')) (show (Map.toList power))
--
gokuDown :: String -> String
gokuDown [] = []
gokuDown list
  | (head (boringC list)) == 'F'
    = (takeWhile isDigit list)
    ++ [(head (boringC list))]
    ++ takeWhile isDigit (drop 1 (dropWhile isDigit list))
    ++"n"++gokuDown (drop 7 (boringC list))
  | otherwise
    = (takeWhile isDigit list)
    ++ [(head (boringC list))]
    ++ takeWhile isDigit (drop 1 (dropWhile isDigit list))
    ++"n"++gokuDown (drop 6 (boringC list))
--
powerZ :: PowerUps -> String
powerZ  powers = (gokuDown(superManDown powers))
--
tsarDown :: Bombas -> String
tsarDown bombas
  = filter
  (\x ->  (x/='[') && (x/=']') && (x/='(')
  && (x/=')') && (x/='{') && (x/='}') && (x/='=') && (x/=' '))
  (show (Map.toList bombas))
--
nagasakiDown :: Int -> String -> String
nagasakiDown count [] = []
nagasakiDown 4 list
  = takeWhile isDigit list
  ++"n" ++ nagasakiDown 0 (dropWhile isntDigit (dropWhile isDigit list))
nagasakiDown count list
  | count /= 2
    = takeWhile isDigit list
    ++"|" ++ nagasakiDown (count+1) (dropWhile isntDigit (dropWhile isDigit list))
  | otherwise
    = [head(list)]
      ++ nagasakiDown (count+1) (dropWhile isntDigit (drop 1 list))
--
atomicZ :: Bombas -> String
atomicZ  bombas = (nagasakiDown 0 (tsarDown bombas))
--
--
socratesDown :: Jogadores -> String
socratesDown player
  = filter
  (\x ->  (x/='[') && (x/=']') && (x/='(')
  && (x/=')') && (x/='{') && (x/='}') && (x/='=') && (x/=' '))
  (show (Map.toList player))
--
fakerDown :: Int -> String -> String
fakerDown count [] = []
fakerDown 4 list
  = takeWhile isDigit list++"n"
  ++fakerDown 0 (dropWhile isntDigit (dropWhile isDigit list))
fakerDown count list
  | count /= 0
    = takeWhile isDigit list
    ++"|" ++fakerDown (count+1) (dropWhile isntDigit (dropWhile isDigit list))
  | otherwise
    = [(head list)]
    ++fakerDown (count+1) (dropWhile isntDigit (dropWhile isDigit list))
--

crZ :: Jogadores -> String
crZ  player = reverse(drop 1 (reverse (fakerDown 0 (socratesDown player))))
--

-- | A função de compressão.
comprime :: Estado      -- ^ O 'Estado' a comprimir.
         -> B.ByteString  -- ^ Uma 'ByteString' comprimida que codifica o 'Estado' dado.
comprime (Estado mapa powers bombas jogadores)
  | powers == (Map.fromList []) && bombas == (Map.fromList []) && jogadores == (Map.fromList [])
    = B.pack( show (mapaSize mapa) ++ "|"
      ++ (mapResume mapa)
      ++ powerZ powers
      ++ atomicZ bombas
      ++ crZ jogadores)
  | otherwise
    = B.pack( show (mapaSize mapa) ++ "|"
      ++ (mapResume mapa)
      ++ powerZ powers
      ++"f"++ atomicZ bombas
      ++"f"++ crZ jogadores)
--
what :: B.ByteString -> String
what string = B.unpack string
--
lineFirstUp :: Int -> Char -> [Bloco]
lineFirstUp 0 x = []
lineFirstUp count 'P' = Pedra : lineFirstUp (count-1) 'P'
lineFirstUp count 'V' = Vazio : lineFirstUp (count-1) 'V'
lineFirstUp count 'T' = Tijolo : lineFirstUp (count-1) 'T'

wholeLine :: Int -> Char -> [Bloco]
wholeLine 0 x = []
wholeLine count 'Q' = Pedra : wholeLine (count-1) 'Q'
wholeLine count 'W' = Vazio : wholeLine (count-1) 'W'
wholeLine count 'E' = Tijolo : wholeLine (count-1) 'E'
--
wholeMap :: Int -> Int -> Char -> Mapa
wholeMap 0 x size = []
wholeMap count size 'W' = (Pedra:(wholeLine size 'W')++[Pedra]):wholeMap (count-1) size 'W'
wholeMap count size 'Q' = (Pedra:(wholeLine size 'Q')++[Pedra]):wholeMap (count-1) size 'Q'
wholeMap count size 'E' = (Pedra:(wholeLine size 'E')++[Pedra]):wholeMap (count-1) size 'E'
--
mapFirstUp :: Int -> String -> Mapa
mapFirstUp size ('f':_) = []
mapFirstUp size string
  | (isDigit (head(string))) && read(takeWhile isDigit string) == size && (head(dropWhile isDigit string) == 'W' ||head(dropWhile isDigit string) =='Q'||head(dropWhile isDigit string) =='E')
    = wholeMap size size (head(dropWhile isDigit string))
  | not (head(dropWhile isDigit string) == 'W' ||head(dropWhile isDigit string) =='Q'||head(dropWhile isDigit string) =='E')
    = (Pedra
    : extra size (takeWhile (/='n') string)
    ++[Pedra])
    : mapFirstUp size (drop 1 (dropWhile (/='n') string))
  | (head(string) == 'W' ||head(string) =='Q'||head(string) =='E')
    = (Pedra
    : extra size (takeWhile (/='n') string)
    ++[Pedra])
    : mapFirstUp size (drop 1 (dropWhile (/='n') string))
  | (head(dropWhile isDigit string) == 'W' ||head(dropWhile isDigit string) =='Q'||head(dropWhile isDigit string) =='E')
    =
    extraZ (read (takeWhile isDigit string) :: Int) size (dropWhile isDigit (takeWhile (/='n') string))
    ++ mapFirstUp size (drop 1 (dropWhile (/='n') string))
--
{-
| isDigit (head string) && (head(dropWhile isDigit string) == 'W' ||head(dropWhile isDigit string) =='Q'||head(dropWhile isDigit string) =='E')
  = wholeLine size
    (head (drop (length (takeWhile isDigit string)) string ))
    ++ extra size  (show ((read (takeWhile isDigit string) :: Int)-1)++(drop 1 string))
------------------------------------
| ((head string) == 'W' ||(head string) =='Q'||(head string) =='E')
  = wholeLine size
    (head (drop (length (takeWhile isDigit string)) string ))
    ++ extra size (drop (1+(length (takeWhile isDigit string))) string)
-}

extraZ :: Int -> Int -> String -> Mapa
extraZ 0 size list = []
extraZ val size (h:t)
  = (Pedra:wholeLine size h ++[Pedra])
    : extraZ (val-1) size (h:t)
--
extra :: Int -> String -> [Bloco]
extra size [] = []
extra size string
  | isDigit (head string)
    = lineFirstUp (read (takeWhile isDigit string) :: Int)
      (head (drop (length (takeWhile isDigit string)) string ))
      ++ extra size (drop (1+(length (takeWhile isDigit string))) string)
  | ((head string) == 'W' ||(head string) =='Q'||(head string) =='E')
    = wholeLine size
      (head (drop (length (takeWhile isDigit string)) string ))
      ++ extra size (drop (1+(length (takeWhile isDigit string))) string)
  | otherwise = lineFirstUp 1 (head string) ++ extra size (drop 1 string)
-- | Transforms in string with PowerUps
goPower :: String -> String
goPower string = drop 1 (dropWhile (/='f') string)
-- |
flamBomb :: Char -> PowerUp
flamBomb 'F' = Flames
flamBomb 'B' = Bombs
-- | --> "1,1,Fn3,3,Bnf3,3,0,0,1nf0,1,1,1,1nf"
--
boringA :: Int -> String -> Word
boringA 0 list = read(takeWhile isDigit list)
boringA x list = boringA (x-1) (drop 1 (dropWhile isDigit list))

--
boringC :: String -> String
boringC list = drop 1 (dropWhile isDigit (drop 1 (dropWhile isDigit list)))
--
boringEnd :: String -> String
boringEnd list
 = drop 1 (dropWhile (/='n') list)
--
obamaUp :: String -> [((Word,Word),PowerUp)]
obamaUp [] = []
obamaUp ('f':t) = []
obamaUp ('n':t) = obamaUp t
obamaUp list
  = ( (boringA 0 list, boringA 1 list),flamBomb (head(dropWhile isDigit list)) )
  : obamaUp (boringEnd list)

-- | --> powers = Map.fromList [((1,1),Flames),((3,3),Bombs)]
trumpUp :: String -> PowerUps
trumpUp list = Map.fromList (obamaUp list)
--
freddy :: B.ByteString -> PowerUps
freddy list = trumpUp(goPower(B.unpack list))
--
-- | Transforms in string with Bombas
goBombs :: String -> String
goBombs string = drop 1 (dropWhile (/='f') (goPower string) )

-- | --> Map.fromList [((3,3),Bomba 0 0 1)]
eu :: String -> [((Word,Word),Bomba)]
eu [] = []
eu ('f':_) = []
eu string
  = ((boringA 0 string,boringA 1 string),
  Bomba (read [(head(boringC string))]) (boringA 0 (drop 1 (boringC string))) (boringA 3 string))
  : eu (drop 1 (dropWhile (/='n') string))
--
mercury :: B.ByteString -> Bombas
mercury list = Map.fromList (eu(goBombs(B.unpack list)))
--
goPlayer :: String -> String
goPlayer string = drop 1(dropWhile (/='f') (goBombs string))

-- | --> Map.fromList [(0,Jogador (1,1) 1 1)]
playBoy :: String -> [(Word,Jogador)]
playBoy [] = []
playBoy string
  = ((read[(head string)]),Jogador ((read(takeWhile isDigit (drop 1 string))::Word),boringA 1 string) (boringA 2 string) (boringA 3 string))
  :playBoy (drop 1 (dropWhile (/='n') string))

-- | Creates a 'Map' of 'Jogadores' using recursive functions and a ByteString
gaspar :: B.ByteString -> Jogadores
gaspar list = Map.fromList (playBoy(goPlayer(B.unpack list)))

-- | Function that 'creates' top & bottom of map given the size of it
roofs :: Int -> [Bloco]
roofs 0 = []
roofs x = Pedra:roofs(x-1)


full string = (read(takeWhile isDigit (B.unpack string)))
-- | Transforms ByteString part of Compression in Mapa type for descomprime
wtf :: B.ByteString -> Mapa
wtf string
  = (roofs (full string))
  :(mapFirstUp ((full string)-2) (B.unpack(usable string)) )
  ++ [(roofs (full string))]
--
usable :: B.ByteString -> B.ByteString
usable list = B.pack(drop 1 (dropWhile isDigit (B.unpack list)))
-- | A função de descompressão.
descomprime :: B.ByteString   -- ^ Uma 'ByteString' comprimida.
            -> Estado       -- ^ O 'Estado' descomprimido codificado pela 'ByteString' dada.
descomprime  string
  = Estado
  (wtf string)
  (freddy (usable string))
  (mercury (usable string))
  (gaspar (usable string))


k play = 1-(fromIntegral(length $B.unpack$comprime play)/fromIntegral(length $show play))
--89.53068592057761
{-
Estado
(mapFirstUp(B.unpack (string)))
freddy string
mercury string
gaspar list
-}
-- Estado (mapFirstUp(unpack string)) (read (drop 1( dropWhile (/='f')(unpack string))))
