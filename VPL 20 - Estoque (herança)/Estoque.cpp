#include <string>
#include <iostream>

#include "Estoque.hpp"

Estoque::Estoque(){
    estoque_ = {};
}

void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  estoque_[mercadoria] += qtd;
}

void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  if(estoque_[mercadoria] < qtd){
    std::cout << mercadoria << "insuficiente" << std::endl;
  }
  else if(estoque_.find(mercadoria) == estoque_.end()){
    std::cout << mercadoria << "inexistente" << std::endl;
  }
  else{
    estoque_[mercadoria] -= qtd;
  }
}

unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
  if(estoque_.find(mercadoria) == estoque_.end()){
    return 0;
  }
  else{
    return (estoque_.find(mercadoria))->second;
  }
}

void Estoque::imprime_estoque() const {
  for (auto it = estoque_.begin(); it != estoque_.end(); it++){
    std::cout << it->first << ", " << it->second << std::endl;
  }
}

Estoque& Estoque::operator += (const Estoque& rhs) {
  for (auto it = (rhs.estoque_).begin(); it != (rhs.estoque_).end(); it++){
    this->add_mercadoria(it->first, it->second);
  }
  return *this;
}

Estoque& Estoque::operator -= (const Estoque& rhs) {
  for (auto it = (rhs.estoque_).begin(); it != (rhs.estoque_).end(); it++){
    this->sub_mercadoria(it->first, it->second);
  }
  return *this;
}

bool operator < (Estoque& lhs, Estoque& rhs) {
    int aux = 0;
    for (auto it = (lhs.estoque_).begin(); it != (lhs.estoque_).end(); it++){
        if(rhs.get_qtd(it->first) != 0 && (rhs.get_qtd(it->first) > (it->second))){
            aux++;
        }
    }
    return (aux == lhs.estoque_.size());
}

bool operator > (Estoque& lhs, Estoque& rhs) {
    return (rhs<lhs);
}