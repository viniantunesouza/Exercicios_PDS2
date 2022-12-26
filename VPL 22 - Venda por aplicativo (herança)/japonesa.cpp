#include "japonesa.hpp"

std::string Japonesa::descricao() const {
  return (std::to_string(getQtd()) + "X Comida japonesa - " + combinado_ + ", " + std::to_string(sushis_) + " sushis, " + std::to_string(temakis_) + " temakis e " + std::to_string(hots_) + " hots.");
}

Japonesa::Japonesa(std::string& combinado,
                   int sushis,
                   int temakis,
                   int hots,
                   int qtd,
                   float valor_unitario) {
  combinado_ = combinado;
  sushis_ = sushis;
  temakis_ = temakis;
  hots_ = hots;
  m_qtd = qtd;
  m_valor_unitario = valor_unitario;
}