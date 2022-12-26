#include "vetor.h"

#include <string>

using namespace std;

Vetor::Vetor(int inicio, int fim){
    inicio_ = inicio;
    int tamanho = fim-inicio+1;
    elementos_ = new string[tamanho];
}

void Vetor::atribuir(int i, string valor){
    int lugar = i-inicio_;
    elementos_[lugar] = valor;   
}

string Vetor::valor(int i) const{
    int lugar = i-inicio_;
    return elementos_[lugar];   
}

Vetor::~Vetor(){
    delete [] elementos_;
}