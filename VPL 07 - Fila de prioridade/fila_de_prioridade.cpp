#include "fila_de_prioridade.h"

#include <list>
#include <string>
#include <vector>

using std::string;
using std::vector;

void FilaDePrioridade::Adicionar(Pessoa p) {
    list<Pessoa>::iterator it;
    if (lista_.size() == 0){
        lista_.push_back(p);
    }
    else if (lista_.size() == 1){
        it = lista_.begin();
        if (it->prioridade < p.prioridade){
            lista_.push_front(p);
        }
        else
            lista_.push_back(p);
    }
    else
        for (it = lista_.begin(); it != lista_.end(); it++){
            if (it->prioridade < p.prioridade){
                lista_.insert(it,p);
                break;
            }
        }
        if (it == lista_.end()){
            lista_.push_back(p);
        }
}

string FilaDePrioridade::RemoverMaiorPrioridade() {
    string primeiroNome;
    list<Pessoa>::iterator it = lista_.begin();
    primeiroNome = it->nome;
    lista_.erase(it);
    return primeiroNome;
}

void FilaDePrioridade::Remover(string nome) {
    list<Pessoa>::iterator it;
    string consulta = nome;
    for (it = lista_.begin(); it != lista_.end(); it++) {
        if (it->nome == consulta) {
            lista_.erase(it);
            break;
        }
    }
}

int FilaDePrioridade::tamanho() {
  return lista_.size();
}

vector<string> FilaDePrioridade::listar() {
  vector<string> v;
  list<Pessoa>::iterator it;
  for (it = lista_.begin(); it != lista_.end(); it++) {
    v.push_back(it->nome);
  }
  return v; 
}