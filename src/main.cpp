#include <iostream>
#include "Frase.hpp"



int main() {
    str path{"data/frases.txt"}; // Cria um objeto ifstream

    Frase Frase(path);           // Passa o objeto ifstream para o construtor
    return 0;
}