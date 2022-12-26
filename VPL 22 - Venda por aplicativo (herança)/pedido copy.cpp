#include "pedido.hpp"


Pedido::~Pedido() {
  for(int i = 0; i < m_produtos.size(); i++){
    m_produtos.pop_back();
  }
}

void Pedido::setEndereco(const std::string& endereco) {
  m_endereco = endereco;
}

float Pedido::calculaTotal() const {
  float valor_total = 0;
  for(auto it = m_produtos.begin(); it != m_produtos.end(); it++){
    valor_total += (*it)->getValor() * (*it)->getQtd();
  }
  return valor_total;
}

void Pedido::adicionaProduto(Produto* p) {
  m_produtos.push_back(p);
}

std::string Pedido::resumo() const {
  std::string resumo = "";
   for(auto it = m_produtos.begin(); it != m_produtos.end(); it++){
    resumo += (*it)->descricao() + "\n";
  }
  resumo += ("Endereco: " + m_endereco + "\n");
  return resumo;
}