module Class6 where

data BTree a = Empty | Node a (BTree a) (BTree a) deriving Show
tree :: BTree Int
tree = Node 5 (Node 3 (Node 2 Empty Empty)
                      (Node 4 Empty Empty))
              (Node 10 (Node 6 Empty Empty)
                       Empty)

--a
altura :: BTree a -> Int
altura Empty = 0
altura (Node value left right) = 1 + max (altura left) (altura right)
--b
contaNodos :: BTree a -> Int
contaNodos Empty = 0
contaNodos (Node value left right) = 1+(contaNodos left)+(contaNodos right)
--c
folhas :: BTree a -> Int
folhas Empty = 0
folhas (Node val Empty Empty) = 1
folhas (Node val left right) = folhas left + folhas right
--d
pruneReverse :: Int -> BTree a -> BTree a
pruneReverse x Empty = Empty
pruneReverse x (Node val left right)
  | altura (Node val left right) == x = Empty
  | otherwise = Node val (pruneReverse x left) (pruneReverse x right)

prune' :: Int -> BTree a -> BTree a
prune' 0 _ = Empty
prune' x Empty = Empty
prune' x (Node val left right) = Node val (prune' (x-1) left) (prune' (x-1) right)
--e
path :: [Bool] -> BTree a -> [a]
path [] (Node val e d) = []
path (True:t) (Node val e d) = val:path t d
path (False:t) (Node val e d) = val:path t e
--f
mirror :: BTree a -> BTree a
mirror Empty = Empty
mirror (Node val e d) = Node val (mirror e) (mirror d)
--g
zipWithBT :: (a -> b -> c) -> BTree a -> BTree b -> BTree c
zipWithBT _ Empty _ = Empty
zipWithBT _ _ Empty = Empty
zipWithBT func (Node a ea da) (Node b eb db)
  = Node (func a b)
    (zipWithBT func ea eb)
    (zipWithBT func da db)
--h
--unzipBT :: BTree (a,b,c) -> (BTree a,BTree b,BTree c)
--unzipBT (Node a b c) = (Node a
--2
avl :: BTree Int
avl = Node 7 (Node 3 (Node 1 Empty Empty)
                      (Node 4 Empty Empty))
             (Node 10 (Node 8 Empty Empty)
                       Empty)
--a
minimo :: Ord a => BTree a -> a
minimo (Node val Empty d) = val
minimo (Node val e d) = minimo e
--b
semMinimo :: Ord a => BTree a -> BTree a
semMinimo (Node val Empty d) = d
semMinimo (Node val e d) = Node val (semMinimo e) d
--c
minSmin :: Ord a => BTree a -> (a,BTree a)
minSmin (Node val Empty d) = (val,d)
minSmin (Node val e d) = (a,Node val b d)
  where (a,b) = minSmin e
--d
--remove :: Ord a => a -> BTree a -> BTree a
--remove new (Node val (Node val1 e1 d1) (Node val2 e2 d2))

--3
type Aluno = (Numero,Nome,Regime,Classificacao)
type Numero = Int
type Nome = String
data Regime = ORD | TE | MEL  deriving Show
data Classificacao
  = Aprov Int
  | Rep
  | Faltou
  deriving Show
type Turma = BTree Aluno

t10 :: BTree Aluno
t10 = Node (7,"George",ORD,Rep)
     (Node (3,"John",MEL,Aprov 60) (Node (1,"Kate",ORD,Aprov 70) Empty Empty)
                      (Node (4,"Michael",ORD,Aprov 75) Empty Empty))
             (Node (10,"Francis",ORD,Aprov 80) (Node (8,"Peter",TE,Rep) Empty Empty)
                       Empty)
--a (Encontra Elemento presente na arvore)
inscNum :: Numero -> Turma -> Bool
inscNum val Empty = False
inscNum val (Node (num,string,reg,mass) e d)
  | val == num = True
  | otherwise = inscNum val e || inscNum val d
--b
inscNome :: Nome -> Turma -> Bool
inscNome name Empty = False
inscNome name (Node (num,string,reg,mass) e d)
  | name == string = True
  | otherwise = inscNome name e || inscNome name d
--c
trabEst :: Turma -> [(Numero,Nome)]
trabEst Empty = []
trabEst (Node (num,string,TE,mass) e d) = [(num,string)] ++ trabEst e ++ trabEst d
trabEst (Node (num,string,_,mass) e d) = trabEst e ++ trabEst d
--d
nota :: Numero -> Turma -> Maybe Classificacao
nota val Empty = Nothing
nota val (Node (num,string,reg,mass) e d)
  | val == num = Just mass
  | val < num = nota val e
  | otherwise = nota val d
--e
{-
percFaltas :: Turma -> Float
percFaltas (Node (num,string,reg,mass) e d)
  = aux (Node (num,string,reg,mass) e d) /
  where
  | mass == Faltou =
  | otherwise = percFaltas-}
