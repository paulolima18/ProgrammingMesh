data Seq a
  = Nil
  | Inicio a (Seq a)
  | Fim (Seq a) a
  deriving Show

sq = Inicio 10 (Fim Nil 10)

--primeiro :: Seq a -> a

type Tabuleiro = [String]

exemplo :: Tabuleiro
exemplo = ["..R.","R...","...R",".R.."]


aux :: (Int,Int) -> Tabuleiro -> [(Int,Int)]
aux (x,y) [] = []
aux (x,y) (h:t) = pos (x,y) h:aux (x,y+1) t
  where
    pos (x,y) (t:ts)
      | t == 'R' = (x,y)
      | otherwise = pos (x+1,y) ts


posicoes :: Tabuleiro -> [(Int,Int)]
posicoes tab = aux (0,0) tab
