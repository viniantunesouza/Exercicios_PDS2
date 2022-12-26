#include "vetor.h"
#include <iostream>

#include <string>

using namespace std;

Vetor::Vetor(int inicio, int fim){
    inicio_ = inicio;
    fim_ = fim;
    if(fim_ < inicio_){
        IntervaloVazio x{inicio_, fim_};
        throw x;
    }
    int tamanho = fim-inicio+1;
    elementos_ = new string[tamanho];
    inicializados_ = new bool[tamanho];
}

void Vetor::atribuir(int i, string valor){
    if (i < inicio_ || i > fim_){
        IndiceInvalido x{inicio_, fim_, i};
        throw x;
    }
    int lugar = i-inicio_;
    elementos_[lugar] = valor;
    inicializados_[lugar] = true;   
}

string Vetor::valor(int i) const{
    int lugar = i-inicio_;
    if (i < inicio_ || i > fim_){
        IndiceInvalido x{inicio_, fim_, i};
        throw x;
    }
    if (inicializados_[lugar] == false){
        IndiceNaoInicializado x{i};
        throw x;
    }
    return elementos_[lugar];   
}

Vetor::~Vetor(){
    delete [] elementos_;
    delete [] inicializados_;
}