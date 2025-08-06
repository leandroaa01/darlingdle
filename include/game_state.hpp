#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP
#include "alias.hpp"

enum class GameState : byte
{
    INICIO = 0,
    BOAVINDAS,
    ESCOLHA,
    SAIDA,
    COMECAR,
    JOGANDO,
    VITORIA,
    BONUS,
    PARAR,
    PROXIMO,
    FIM

};

using state = GameState;