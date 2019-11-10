module Class9 where

import System.Random

acumularNumeros :: [Int] -> IO [Int]
acumularNumeros list
  | length list == 90 = return list
  | otherwise = do v <- randomRIO(1,90)
                   print v
                   let newl = if elem v list
                              then list
                              else v:list in acumularNumeros newl

bingo :: IO ()
bingo = do newl <- acumularNumeros []
           print newl

gerarChave :: IO (Int,Int,Int,Int)
gerarChave
  = do d1 <- randomRIO (0,9)
       d2 <- randomRIO (0,9)
       d3 <- randomRIO (0,9)
       d4 <- randomRIO (0,9)
       return (d1,d2,d3,d4)

introduz :: IO (Int,Int,Int,Int)
introduz
  = do a <- getChar
       b <- getChar
       c <- getChar
       d <- getChar
       return (read [a],read [b],read [c],read [d])

help :: Int -> Int -> Int
help a b
  | a == b = 1
  | otherwise = 0

howMany :: (Int,Int,Int,Int) -> (Int,Int,Int,Int) -> Int
howMany (x,y,z,k) (a,b,c,d) = help x a + help y b + help z c + help k d

joga ::(Int,Int,Int,Int) -> (Int,Int,Int,Int) ->  IO (Int,Int,Int,Int)
joga chaves valores
  | howMany chaves valores == 4 = return valores
  | otherwise = do vs <- introduz
                   joga chaves vs

masterMind :: IO ()
masterMind
  = do chave <- gerarChave
       print chave
       try <- introduz
       chavesEnc <- joga chave try
       print chavesEnc
