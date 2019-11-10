module Class8 where

import Data.List

data Cores
  = Verde Int
  | Vermelho Int
  | Azul Int

r :: Cores
r = Vermelho 20
v = Verde 80
a = Azul 50

lc ::[Cores]
lc = [r,v,a]

coresIguais :: Cores -> Cores -> Bool
coresIguais (Verde _) (Verde _) = True
coresIguais (Vermelho _ ) (Vermelho _ ) = True
coresIguais (Azul _ ) (Azul _ ) = True
coresIguais _ _ = False

intenso :: Cores -> Int
intenso (Verde i) = i
intenso (Vermelho i) = i
intenso (Azul i) = i

comparaCores :: Cores -> Cores -> Bool
comparaCores a b = intenso a <= intenso b

instance Eq Cores where
  (==) = coresIguais

instance Ord Cores where
  (<=) a b = comparaCores a b

showCores :: Cores -> String
showCores (Vermelho i)
  | i <= 20 = "Vermelho Claro"
  | i > 75 = "Vermelho Escuro"
  | otherwise = "Vermelho"
showCores (Verde i)
  | i <= 20 = "Verde Claro"
  | i > 75 = "Verde Escuro"
  | otherwise = "Verde"
showCores (Azul i)
  | i <= 20 = "Azul Claro"
  | i > 75 = "Azul Escuro"
  | otherwise = "Azul"

instance Show Cores where
  show = showCores

data Exp a
  = Const a
  | Simetrico (Exp a)
  | Mais (Exp a) (Exp a)
  | Menos (Exp a) (Exp a)
  | Mult (Exp a) (Exp a)

ex = (Const 2) `Mais` ((Const 3) `Mult` (Const 5))

ex' = (Const 17)

calcula :: Num a => Exp a -> a
calcula (Const val) = val
calcula (Mais func func2) = calcula func + calcula func2
calcula (Simetrico func) = (-(calcula func))
calcula (Menos func func2) = calcula func - calcula func2
calcula (Mult func func2) = calcula func * calcula func2
-- ok
infixa :: Show a => Exp a -> String
infixa (Mais func func2) = "("++infixa func ++ "+" ++ infixa func2++")"
infixa (Menos func func2) = "("++infixa func ++ "-" ++ infixa func2++")"
infixa (Simetrico func) = "-(" ++ infixa func++")"
infixa (Mult func func2) = "("++infixa func ++ "*" ++ infixa func2++")"
infixa (Const val) =  show val
--ok
instance Show a => Show (Exp a) where
  show = infixa

igualExp :: (Num a,Eq a) => Exp a -> Exp a -> Bool
igualExp e1 e2 = calcula e1 == calcula e2

instance (Num a,Eq a) => Eq (Exp a) where
  (==) a b = igualExp a b

soma :: Num a => Exp a -> Exp a -> Exp a
soma e1 e2 = Const(calcula e1 + calcula e2)

menos :: Num a => Exp a -> Exp a -> Exp a
menos e1 e2 = Const(calcula e1 - calcula e2)

multi :: Num a => Exp a -> Exp a -> Exp a
multi e1 e2 = Const(calcula e1 * calcula e2)

absolute :: Num a => Exp a -> Exp a
absolute e1 = Const (abs (calcula e1))

simbExp :: (Num a,Ord a) => Exp a -> Exp a
simbExp e1
  | (calcula e1) < 0 = Const (-1)
  | otherwise = Const 1
--sign e = Const $ signum $ (calcula e)

inteiro :: Num a => Integer -> Exp a
inteiro a = Const (fromInteger a)

instance (Ord a,Num a) => Num (Exp a) where
  (+) = soma
  (-) = menos
  (*) = multi
  abs = absolute
  signum = simbExp
  fromInteger = inteiro
