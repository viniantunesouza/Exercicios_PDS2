#include <iostream>
#include <string>

#include "fila.h"

using namespace std;

Fila::Fila(){
    primeiro_ = nullptr;
    ultimo_ = nullptr;
}

string Fila::primeiro(){
    return primeiro_->chave;
}

string Fila::ultimo(){
    return ultimo_->chave;
}

bool Fila::vazia(){
    return primeiro_ == nullptr && ultimo_ == nullptr;
}

void Fila::Inserir(string k){
    No* n = new No;
    n->chave = k;
    n->proximo = nullptr;
    if(vazia()){
        primeiro_ = n;
        ultimo_ = n;
    }
    else{
        ultimo_->proximo = n;
        ultimo_ = n;
    }
}

void Fila::Remover(){
    if(tamanho() == 1){
        delete primeiro_;
        primeiro_ = nullptr;
        ultimo_ = nullptr;
    }
    else{
        No* aux = primeiro_;
        primeiro_ = aux->proximo;
        delete aux;
    }
}

int Fila::tamanho(){
    int n = 0;
    for(No* it = primeiro_; it != nullptr; it = it->proximo){
        n++;
    }
    return n;
}

Fila::~Fila(){
    while(!vazia()){
        Remover();
    }
}