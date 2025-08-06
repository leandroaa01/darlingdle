#ifndef DARLINGDLE_SIMULATION_HPP
#define DARLINGDLE_SIMULATION_HPP
#include "alias.hpp"
#include "Frase.hpp"
#include "game_state.hpp"

class DarlingDleSimulation
{
private:
 vec<str> m_paths = {  "data/frases.txt"};
 Frase m_frases;
 state m_game_state{state::INICIO};
 unsigned int m_score{0};
 flag m_bonus{false};
 flag m_acertou{false};
 void process();
 void update();
 void render();

 public:
 DarlingDleSimulation();
 ~DarlingDleSimulation() = default;

 flag game_over(const state &current_state);

 void run();
};

#endif // DARLINGDLE_SIMULATION_HPP