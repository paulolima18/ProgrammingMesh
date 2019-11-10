module Class7 where

data Exp
  = Const Int
  | Simetrico Exp
  | Mais Exp Exp
  | Menos Exp Exp
  | Mult Exp Exp
  deriving (Show)

e :: Exp
e = (Const 2) `Mais` ((Const 3) `Mult` (Const 5))
--a
calcula :: Exp -> Int
calcula (Const val) = val
calcula (Mais func func2) = calcula func + calcula func2
calcula (Simetrico func) = (-(calcula func))
calcula (Menos func func2) = calcula func - calcula func2
calcula (Mult func func2) = calcula func * calcula func2
--b
infixa :: Exp -> String
infixa (Mais func func2) = "("++infixa func ++ "+" ++ infixa func2++")"
infixa (Menos func func2) = "("++infixa func ++ "-" ++ infixa func2++")"
infixa (Simetrico func) = "-(" ++ infixa func++")"
infixa (Mult func func2) = "("++infixa func ++ "*" ++ infixa func2++")"
infixa (Const val) =  show val
--
posfixa :: Exp -> String
posfixa (Mais func func2) = posfixa func ++ posfixa func2 ++ "+" ++ " "
posfixa (Menos func func2) = posfixa func ++ posfixa func2 ++ "-" ++ " "
posfixa (Simetrico func) = "-(" ++ posfixa func++")" ++ " "
posfixa (Mult func func2) = posfixa func ++ posfixa func2++ "*" ++ " "
posfixa (Const val) =  show val ++ " "
--
data RTree a = R a [RTree a]
rtree
  = R 5 [ R 7 []
        , R 2 [ R 4 []
              , R 5 []
              ]
        , R 4 [ R 7 []
              ]
        ]

soma :: Num a => RTree a -> a
soma (R a []) = a
soma (R a list) = a + (sum(map soma list))
