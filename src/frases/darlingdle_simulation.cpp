#include "../include/darlingdle_simulation.hpp"


DarlingDleSimulation::DarlingDleSimulation()
    : m_frases("../frases/frases.txt")
{
}

flag DarlingDleSimulation::game_over(const state &current_state)
{
    // Verifica se o jogo terminou com base no estado atual
    return current_state == state::FIM or current_state == state::SAIDA;
}

void DarlingDleSimulation::run()
{
    while (not game_over(m_game_state)) {
        process();
        update();
        render();
    }
}

void DarlingDleSimulation::process()
{
  switch (m_game_state)
  {
   case state::INICIO:
        // Lógica para o estado de início
        m_game_state = state::BOAVINDAS;
        break;

    case state::BOAVINDAS:
        // Lógica para boas-vindas
        m_game_state = state::ESCOLHA;
        break;

    case state::ESCOLHA:
        // Lógica para escolha do jogo
        m_game_state = state::COMECAR;
        break;

    case state::COMECAR:
        // Lógica para iniciar o jogo
        m_game_state = state::JOGANDO;
        break;

    case state::JOGANDO:
        // Lógica do jogo em si
        break;

    case state::VITORIA:
        // Lógica de vitória
        m_game_state = state::BONUS;
        break;

    case state::BONUS:
        // Lógica de bônus
        m_game_state = state::PARAR;
        break;
    
    case state::PROXIMO:
        // Lógica para o próximo jogo ou próxima fase
        m_game_state = state::JOGANDO;
        break;

    case state::PARAR:
        // Lógica para parar o jogo
        m_game_state = state::FIM;
        break;

    case state::FIM:
        // Lógica de finalização do jogo
        break;

    default:
        break;
  }
}

void DarlingDleSimulation::update()
{
    
}

void DarlingDleSimulation::render()
{
    // Renderização dos elementos na tela
}
