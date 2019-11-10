--Exercise 1

type MSet a = [(a,Int)]

-- Test set
mset :: MSet Char
mset = [('b',4),('a',2),('c',1)]

--a
cardMSet :: MSet a -> Int
cardMSet [] = 0
cardMSet ((a,b):t) = b + cardMSet t

--b
moda :: MSet a -> [a]
moda [] = []
moda ((a,b):t) = famous [a] b t
  where
    famous new b [] = new
    famous new b ((x,y):t)
      | b > y = famous new b t
      | b == y = famous (x:new) b t
      | otherwise = famous [x] y t
--c
converteMSet :: MSet a -> [a]
converteMSet [] = []
converteMSet ((a,b):t) = aux a b ++ converteMSet t
  where
    aux a 0 = []
    aux a b = a : aux a (b-1)
--d

-- aux1
inMSet :: Eq a => MSet a -> a -> Bool
inMSet [] new = False
inMSet ((a,b):t) new
  | a == new = True
  | otherwise = inMSet t new

-- aux2
addMSet :: Eq a => MSet a -> a -> Int -> MSet a
addMSet ((a,b):t) new i
  | a == new = ((a,b+i):t)
  | otherwise = (a,b) : addMSet t new i

-- aux3
insertMSet :: Eq a => MSet a -> a -> Int -> MSet a
insertMSet [] new i = [(new,i)]
insertMSet set@((a,b):t) new i
  | i == 0 = set
  | i >= b = (new,i):set
  | otherwise = (a,b) : insertMSet t new i

-- | main function
addNcopies :: Eq a => MSet a -> a -> Int -> MSet a
addNcopies set new i
  | inMSet set new = addMSet set new i
  | otherwise = insertMSet set new i

-- Exercise 2

data SReais
  = AA Double Double | FF Double Double
  | AF Double Double | FA Double Double
  | Uniao SReais SReais

sreal :: SReais
sreal = Uniao (Uniao (AA 4.2 5.5) (AF 3.1 7.0)) (FF (-12.3) 30.0)

-- a

visible :: SReais -> String
visible (AA x y) = "]" ++ show x ++ "," ++ show y ++ "["
visible (AF x y) = "]" ++ show x ++ "," ++ show y ++ "]"
visible (FA x y) = "[" ++ show x ++ "," ++ show y ++ "["
visible (FF x y) = "[" ++ show x ++ "," ++ show y ++ "]"
visible (Uniao x y) = "(" ++ show x ++ "U" ++ show y ++ ")"

instance Show SReais where
  show = visible

-- b
pertence :: Double -> SReais -> Bool
pertence x (Uniao a b) = pertence x a || pertence x b
pertence x (AA a b) = x == a || x == b
pertence x (FA a b) = x == a || x == b
pertence x (FF a b) = x == a || x == b
pertence x (AF a b) = x == a || x == b

-- c
--tira :: Double -> SReais -> SReais

-- Exercise 3

data RTree a = R a [RTree a]

-- debug
rtree
  = R 5 [ R 7 []
        , R 2 [ R 4 []
              , R 5 []
              ]
        , R 4 [ R 7 []
              ]
        ]

-- a
debug :: [RTree a] -> Int -> Bool
debug [] 0 = False
debug (R a list:t) 0 = True
debug (R a list:t) x = debug t (x-1)

lol :: [Int] -> RTree a -> Bool
lol [] (R a list) = True
lol (x:xs) (R a list)
  | debug list (x-1)
    = lol xs (list!!(x-1))
  | otherwise = False

result :: [Int] -> RTree a -> [a]
result (x:xs) (R a list)
  | debug  list (x-1)
    = a : result xs (list!!(x-1))
  | otherwise = []
result [] (R a list) = [a]

percorre :: [Int] -> RTree a -> Maybe [a]
percorre [] (R a list) = Just []
percorre (x:xs) (R a []) = Nothing
percorre path rtree
  | lol path rtree
    = Just (result path rtree)
  | otherwise = Nothing

-- b

inRTree :: a -> RTree a -> Bool
inRTree x (R a list)
  | x == a = True
  | otherwise = map inRTree x list

procura :: Eq a => a -> RTree a -> Maybe [Int]
procura k rtree
  | inRTree a rtree
    = Nothing
  | otherwise = Nothing
