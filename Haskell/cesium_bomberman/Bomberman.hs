{- | Este módulo define os tipos de dados comuns às duas competições.

 O objetivo da competição é implementar o clássico jogo __Bomberman__ em​ /b​attle mode/.

 <<http://www.otakia.com/wp-content/uploads/2013/06/Bomberman-93-U-026.png>>

 A ideia geral do jogo é colocar bombas estrategicamente de forma a matar inimigos e destruir obstáculos no mapa. A explosão de uma bomba pode desencadear explosões de outras bombas, destruir obstáculos, matar inimigos ou matar o próprio jogador.

 Cada jogo tem uma duração fixa. Para forçar os jogadores a efectuar acções, num mapa de dimensão ​@n@​, quando faltarem ​@(n-2)^2​@ instantes de tempo o mapa começa a fechar-se com 'Bloco's de 'Pedra' num efeito de espiral que começa na posição 1 1. Este efeito pode, por exemplo, ser visto no vídeo ​<https://www.youtube.com/watch?v=l9-wQfkJCNM​> (começando sensivelmente no instante 1:57). Em cada instante de tempo cai um bloco de pedra que elimina tudo o que estiver na respectiva posição.
-}
module Bomberman where

import Data.Map (Map(..))

-- * Tipos de dados auxiliares.

-- | Um 'Mapa' é uma matriz quadrada de 'Bloco's.
--
-- Assumem-se algumas regras adicionais de boa formação de 'Mapa's:
--
--  * O tamanho é sempre tamanho ímpar.
--
--  * Os 'Bloco's de 'Pedra' estão sempre na mesma 'Posicao' (todo o contorno do mapa e, para cada linha ou coluna, alternadamente).
--
--  * Os quatro cantos têm sempre 3 'Bloco's 'Vazio's, para permitir ao 'Jogador' em cada canto movimentar-se no início do jogo.
type Mapa = [[Bloco]]

-- | Um 'Bloco' do 'Mapa'.
data Bloco
    = Pedra     -- ^ Um 'Bloco' de 'Pedra' indestrutível.
    | Tijolo    -- ^ Um 'Bloco' de 'Tijolo' destrutível (por 'Bombas').
    | Vazio     -- ^ Um 'Bloco' 'Vazio'.
  deriving (Eq,Ord,Enum,Bounded,Read,Show)
    
-- | Um 'PowerUp' disponível no 'Mapa'.
data PowerUp
    = Bombs     -- ^ Um 'PowerUp' do tipo 'Bombs' aumenta o número de 'Bombas' simultâneas que um 'Jogador' pode colocar em uma unidade.
    | Flames    -- ^ Um 'PowerUp' do tipo 'Flames' aumenta o raio das explosões das 'Bombas' de um 'Jogador' em uma unidade.
  deriving (Eq,Ord,Enum,Bounded,Read,Show)

-- | Uma linha.
type Linha = Word

-- | Uma coluna.
type Coluna = Word

-- | Uma 'Posicao' no 'Mapa'.
type Posicao = (Linha,Coluna)

-- | Todos os 'PowerUps' disponíveis no 'Mapa', ordenados por 'Posicao'.
type PowerUps = Map Posicao PowerUp

-- | Todas as 'Bombas' em contagem decrescente no 'Mapa', ordenadas por 'Posicao'.
-- Assumem-se alguma regras adicionais para 'Bombas':
--
--  * Um 'Jogador' não se pode movimentar para a 'Posicao' onde esteja uma 'Bomba'.
--
--  * Cada 'Bomba' demora 10 instantes de tempo a explodir.
-- 
--  * Quando uma 'Bomba' explode lança chamas com dimensão igual ao seu raio nas quatro direções.
--
--  * A explosão de uma 'Bomba' elimina todos os 'Jogadores' e 'PowerUps' (já destapados) que atinge. Se as chamas atingirem outra 'Bomba', o tempo dessa bomba passa para 1, de forma a forçar a sua explosão no próximo instante de tempo.
--
--  * Quando a explosão de uma 'Bomba' atinge um bloco do tipo 'Tijolo', destrói o mesmo revelando possíveis 'PowerUps' que estejam escondidos atrás. Tal como a 'Pedra', o 'Tijolo' e os ​'PowerUps' também bloqueiam a passagem das chamas.
type Bombas = Map Posicao Bomba

-- | Instantes de tempo do jogo.
type Tempo = Word

-- | Uma bomba em contagem decrescente no 'Mapa'.
data Bomba = Bomba
    { jogadorBomba :: IdJogador     -- ^ O 'Jogador' que colocou a 'Bomba'.
    , raioBomba :: Word             -- ^ O raio da explosão da 'Bomba'.
    , tempoBomba :: Tempo           -- ^ Quantos instantes de 'Tempo' faltam para a 'Bomba' explodir. Uma 'Bomba' @b@ explode quando @tempoBomba b == 0@.
    }
  deriving (Eq,Ord,Read,Show)

-- | O identificador de um 'Jogador'.
--
-- O jogo tem no máximo 4 jogadores, com identificadores entre @0@ e @3@.
type IdJogador = Word

-- | Todos os 'Jogadores' atualmente em jogo, ordenador por 'IdJogador'.
type Jogadores = Map IdJogador Jogador

-- | Informação adicional de um 'Jogador'.
data Jogador = Jogador
    { posicaoJogador :: Posicao -- ^ 'Posicao' do jogador. Diferentes 'Jogadores' podem estar na mesma 'Posicao'.
    , bombsJogador :: Word      -- ^ O número de powerups 'Bombs' apanhados pelo 'Jogador'. O 'Jogador' @j@ pode colocar @bombsJogador j + 1@ 'Bombas' simultâneas.
    , flamesJogador :: Word     -- ^ O número de powerups 'Flames' apanhados pelo 'Jogador'. As explosões das 'Bombas' colocadas pelo 'Jogador' @j@ têm raio @flamesJogador j + 1@.
    }
  deriving (Eq,Ord,Read,Show)

-- | O estado interno do jobo Bomberman.
data Estado = Estado
    { mapa :: Mapa           -- ^ O 'Mapa' do jogo.
    , powerUps :: PowerUps   -- ^ Os `PowerUps` espalhados pelo 'Mapa'.
    , bombas :: Bombas       -- ^ As 'Bombas' em contagem decrescente no 'Mapa'.
    , jogadores :: Jogadores -- ^ Os 'Jogadores' atualmente em jogo.
    }
  deriving (Eq,Ord,Read,Show)

-- | Uma jogada válida.
data Jogada
    = U -- ^ Move para cima.
    | D -- ^ Move para baixo.
    | L -- ^ Move para a esquerda.
    | R -- ^ Move para a direita.
    | B -- ^ Coloca uma 'Bomba'.
  deriving (Eq,Ord,Enum,Bounded,Read,Show)

