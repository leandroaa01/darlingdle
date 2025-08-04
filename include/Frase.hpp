#ifndef FRASE_HPP
#define FRASE_HPP
#include "alias.hpp"


struct txt
{
   str frase{}, autor{}, episodio{};
};

class Frase
{
private:
  vec<txt> m_frases{};

  txt separado_de_conteudo(const str& linha) {
    size_t fimFrase = linha.rfind('"'); // posição do último aspas
    size_t iniFrase = linha.find('"');  // posição do primeiro aspas

    txt  c;
    if (iniFrase != str::npos && fimFrase != str::npos && fimFrase > iniFrase) {
        c.frase = linha.substr(iniFrase + 1, fimFrase - iniFrase - 1); // frase sem aspas
        str resto = linha.substr(fimFrase + 2); // pula o último " e a vírgula
        strtream  ss(resto);
        std::getline(ss, c.autor, ',');
        std::getline(ss, c.episodio);
        
        // Remover espaços extras
        if (!c.autor.empty() && c.autor[0] == ' ') c.autor.erase(0, 1);
        if (!c.episodio.empty() && c.episodio[0] == ' ') c.episodio.erase(0, 1);
    }
    return c;
}
public:
    Frase(str path);
    ~Frase() = default;
};

Frase::Frase(str path)
{
    std::ifstream arquivo(path);
    if (!arquivo.is_open()) { // Verifica se o arquivo foi aberto com sucesso
        std::cerr << "Erro ao abrir o arquivo.\n";
        return;
    }
    std::string linha;

    // Ignorar as duas primeiras linhas
    std::getline(arquivo, linha);
    std::getline(arquivo, linha);



    while (std::getline(arquivo, linha)) {
        if (!linha.empty()) {
            txt c = separado_de_conteudo(linha);
            m_frases.push_back(c);
        }
    }

    // Exemplo de exibição
    for (const auto& f : m_frases) {
        std::cout << "Frase: " << f.frase << "\nAutor: " << f.autor << "\nEpisódio: " << f.episodio << "\n---\n";
    }
}

#endif  //<! FRASE_HPP