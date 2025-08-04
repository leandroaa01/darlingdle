
#include "../include/Frase.hpp"

Frase::Frase(str path)
{
  std::ifstream arquivo(path);
  if (not arquivo.is_open())
  { // Verifica se o arquivo foi aberto com sucesso
    error("Erro ao abrir o arquivo: " + path);
    return;
  }
  str linha{};

  std::getline(arquivo, linha);
  //!! pega a quantidade de frases
  m_qtd = std::stoi(linha);
  //!! ignora a linha de cabeçalho da tabela
  std::getline(arquivo, linha);

  while (std::getline(arquivo, linha))
  {
    if (not linha.empty())
    {
      txt c = set_frases(linha);
      m_frases.emplace_back(c, false);
    }
  }
}
txt Frase::embalhador()
{
    if (m_frases.empty())
    {
        error("Nenhuma frase disponível.");
        return txt{}; //!! Retorna um objeto vazio se não houver frases
    }
  //!! Embaralhar as frases
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(m_frases.begin(), m_frases.end(), g);
  //!! Retorna a primeira frase embaralhada ou um objeto vazio se não houver frases
  m_frases.front().second = true; // Marca a frase como usada
  return m_frases.front().first;
}

