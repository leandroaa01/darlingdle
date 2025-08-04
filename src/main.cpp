#include <iostream>
#include "Frase.hpp"



int main()
{
  //!! caminho do arquivo de frases
  str path{"data/frases.txt"};
  //!! instância da classe Frase
  Frase Frase(path);
  //!! obtém uma frase embaralhada
  txt frase{Frase.embalhador()};
  print("tente adivinhar quem disse a frase: ");
  print("\"" << frase.frase << "\"\n");
  print("Autor: " << frase.autor);
  print("Episódio: " << frase.episodio);
  
  //!! loop do jogo
  flag acetou{false};
  while (!acetou) {
    print("Quem disse a frase? ");
    str resposta;
    read(resposta);
    std::transform(resposta.begin(), resposta.end(), resposta.begin(),::tolower); // Normaliza a resposta para minúsculas
    auto autor{frase.autor};
    std::transform(autor.begin(), autor.end(), autor.begin(), ::tolower); // Normaliza o autor para minúsculas
    //!! remover espaçoes em branco
    resposta.erase(remove(resposta.begin(), resposta.end(), ' '), resposta.end());
    autor.erase(remove(autor.begin(), autor.end(), ' '), autor.end());
   
    if (resposta.empty()) {
      continue; // Pula para a próxima iteração do loop
    }
   
    if (resposta == autor) {
      print("Acertou!");
      acetou = true;
      print("bonus: qual o episódio? ");
      str episodio;
      read(episodio);
      //!! converte para intero o episódio
      int episodio_num{ frase.episodio.empty() ? 0 : std::stoi(frase.episodio) };
      if (episodio == std::to_string(episodio_num)) {
        print("Muito bem! Você acertou o episódio também!");
      }
      else
      {
        print("Errou! A resposta era: " << frase.episodio);
        print("Mas você acertou o autor!");
      }
    }else {
        print("Errou! Tente novamente.");
      }
  }
  print("Fim do jogo!");
    return 0;
}