#include "pizza.hpp"

#include <string>

std::string Pizza::descricao() const {
  if(borda_recheada_){
    return (std::to_string(getQtd()) + "X Pizza " + sabor_ + ", " + std::to_string(pedacos_) + " pedacos e borda recheada.");
  }
  else{
    return (std::to_string(getQtd()) + "X Pizza " + sabor_ + ", " + std::to_string(pedacos_) + " pedacos e sem borda recheada.");
  }
}

Pizza::Pizza(std::string& sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario) {
  sabor_ = sabor;
  pedacos_ = pedacos;
  borda_recheada_ = borda_recheada;
  m_qtd = qtd;
  m_valor_unitario = valor_unitario;
}