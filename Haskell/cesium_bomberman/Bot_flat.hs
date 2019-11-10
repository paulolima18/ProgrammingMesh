-- | Este módulo define funções para a competição de bots do jogo __Bomberman__.
module Bot_flat where

import Bomberman

-- | Tipo que codifica a memória do ro'bot' entre 'Jogada's.
--
-- Para um ro'bot' sem 'Memoria' defina simplesmente @type Memoria = ()@.
--
-- Altere o tipo para um ro'bot' com mais 'Memoria'.
type Memoria = ()

-- | A 'Memoria' inicial do ro'bot' no início do jogo.
--
-- Para um ro'bot' sem 'Memoria' defina simplesmente @memoriaInicial = ()@.
memoriaInicial :: Memoria
memoriaInicial = undefined

-- | Define um ro'bot' capaz de jogar autonomamente o jogo, tomando decisões a caada instante de tempo do jogo.
bot :: Estado                   -- ^ O 'Estado' para o qual o ro'bot' deve tomar uma decisão.
    -> IdJogador                -- ^ O identificador do 'Jogador' associado ao ro'bot'.
    -> Word                     -- ^ O número de instantes de tempo até ao fim do jogo (permite estimar o aavanço da espiral).
    -> Memoria                  -- ^ 'Memoria' do ro'bot' entre jogadas.
    -> (Maybe Jogada,Memoria)   -- ^ Uma possível 'Jogada' e a 'Memoria' atualizada.
bot = undefined
