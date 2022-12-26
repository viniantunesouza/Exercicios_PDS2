#include "venda.hpp"

#include <iomanip>

Venda::~Venda() {
  for(int i = 0; i < m_pedidos.size(); i++){
    m_pedidos.pop_back();
  }
}

void Venda::adicionaPedido(Pedido* p) {
  m_pedidos.push_back(p);
}

void Venda::imprimeRelatorio() const {
  int pedidos = 0;
  float valor = 0;

  for (auto it = m_pedidos.begin(); it != m_pedidos.end(); it++){
    std::cout << "Pedido " << std::to_string(pedidos+1) << std::endl;
    std::cout << (*it)->resumo();
    valor += (*it)->calculaTotal();
    pedidos++;
  }
  std::cout << "Relatorio de Vendas" << std::endl;
  std::cout << "Total de vendas: R$ " << std::fixed << std::setprecision(2) << valor << std::endl;
  std::cout << "Total de pedidos: " << std::to_string(pedidos) << std::endl; 
}