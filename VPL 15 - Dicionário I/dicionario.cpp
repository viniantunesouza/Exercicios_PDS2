#include "dicionario.h"

using namespace std;

Dicionario::Dicionario(){
    elementos_ = {};
}

int Dicionario::tamanho(){
    if(elementos_.empty()){
        return 0;
    }
    else{
        int j = 0;
        for(auto it = elementos_.begin(); it != elementos_.end(); it++){
            j++;
        }
        return j;
    }
}

bool Dicionario::pertence(string chave){
    if(tamanho() == 0){
        return false;
    }
    for(auto it = elementos_.begin(); it != elementos_.end(); it++){
        if(it->chave == chave){
            return true;
        }
    }
    return false;
}

string Dicionario::menor(){
    string menor = elementos_.begin()->chave;
    for(auto it = elementos_.begin(); it != elementos_.end(); it++){
        if(it->chave < menor){
            menor = it->chave;
        }
    }
    return menor;
}

string Dicionario::valor(string chave){
    for(auto it = elementos_.begin(); it != elementos_.end(); it++){
        if(it->chave == chave){
            return it->valor;
        }
    }
    return "";
}

void Dicionario::Inserir(string chave, string valor){
    elementos_.push_back(Elemento{chave,valor});
}

void Dicionario::Remover(string chave){
    for(auto it = elementos_.begin(); it != elementos_.end(); it++){
        if(it->chave == chave){
            elementos_.erase(it);
            break;
        }
    }
}

void Dicionario::Alterar(string chave, string valor){
    for(auto it = elementos_.begin(); it != elementos_.end(); it++){
        if(it->chave == chave){
            it->valor = valor;
        }
    }
}

Dicionario::~Dicionario(){
    list<Elemento>::iterator it;
    while(tamanho() != 0){
        it = elementos_.begin();
        Remover(it->chave);
    }
}
