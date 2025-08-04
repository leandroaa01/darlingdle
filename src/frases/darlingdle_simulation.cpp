#include "../include/darlingdle_simulation.hpp"

DarlingDleSimulation::DarlingDleSimulation()
    : m_frases("../frases/frases.txt")
{
}

void DarlingDleSimulation::run()
{
    process();
    update();
    render();
}

void DarlingDleSimulation::process()
{
    // Processamento das frases
}

void DarlingDleSimulation::update()
{
    // Atualização do estado do jogo
}

void DarlingDleSimulation::render()
{
    // Renderização dos elementos na tela
}
