#include "hamburguer.hpp"

std::string Hamburguer::descricao() const {
  if(artesanal_){
    return (std::to_string(getQtd()) + "X Hamburguer " + tipo_ + " artesanal.");
  }
  else{
    return (std::to_string(getQtd()) + "X Hamburguer " + tipo_ + " simples.");
  }
}

Hamburguer::Hamburguer(std::string& tipo,
                       bool artesanal,
                       int qtd,
                       float valor_unitario) {
  tipo_ = tipo;
  artesanal_ = artesanal;
  m_qtd = qtd;
  m_valor_unitario = valor_unitario;
}