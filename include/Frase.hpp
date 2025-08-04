#ifndef FRASE_HPP
#define FRASE_HPP
#include "alias.hpp"


struct txt
{
   str frase{}, autor{}, episodio{};
};

using info = std::pair<txt, flag>; //!! info sobre a frase e se foi usada ou não

class Frase
{
private:
  vec<info> m_frases{};
  size_type m_qtd{0};

  txt set_frases(const str& linha) {
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
  Frase& operator=(const Frase& other) = default;
  txt embalhador();
  size_type qtd() const { return m_qtd;}
  vec<info> get_frases() const { return m_frases; }
};


#endif  //<! FRASE_HPP