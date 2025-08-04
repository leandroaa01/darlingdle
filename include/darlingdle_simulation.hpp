#ifndef DARLINGDLE_SIMULATION_HPP
#define DARLINGDLE_SIMULATION_HPP
#include "alias.hpp"
#include "Frase.hpp"

class DarlingDleSimulation
{
private:
 Frase m_frases;
 void process();
 void update();
 void render();

 public:
 DarlingDleSimulation();
 ~DarlingDleSimulation() = default;

 void run();
};

#endif // DARLINGDLE_SIMULATION_HPP