#include "jogo_da_vida.h"
#include <vector>
#include <iostream>

using namespace std;

vector<int> vizinho1(int i, int j, int linhas, int colunas){
    int vizinho_x = i-1;
    int vizinho_y = j-1;
    if (vizinho_x < 0){
        vizinho_x = linhas-1;
    }
    if (vizinho_y < 0){
        vizinho_y = colunas-1;
    }
    vector<int> posicao{vizinho_x,vizinho_y};
    return posicao;
}

vector<int> vizinho2(int i, int j, int linhas, int colunas){
    int vizinho_x = i-1;
    int vizinho_y = j;
    if (vizinho_x < 0){
        vizinho_x = linhas-1;
    }
    vector<int> posicao{vizinho_x,vizinho_y};
    return posicao;
}

vector<int> vizinho3(int i, int j, int linhas, int colunas){
    int vizinho_x = i-1;
    int vizinho_y = j+1;
    if (vizinho_x < 0){
        vizinho_x = linhas-1;
    }
    if (vizinho_y > (colunas-1)){
        vizinho_y = 0;
    }
    vector<int> posicao{vizinho_x,vizinho_y};
    return posicao;
}

vector<int> vizinho4(int i, int j, int linhas, int colunas){
    int vizinho_x = i;
    int vizinho_y = j-1;
    if (vizinho_y < 0){
        vizinho_y = colunas-1;
    }
    vector<int> posicao{vizinho_x,vizinho_y};
    return posicao;
}

vector<int> vizinho6(int i, int j, int linhas, int colunas){
    int vizinho_x = i;
    int vizinho_y = j+1;
    if (vizinho_y > colunas-1){
        vizinho_y = 0;
    }
    vector<int> posicao{vizinho_x,vizinho_y};
    return posicao;
}

vector<int> vizinho7(int i, int j, int linhas, int colunas){
    int vizinho_x = i+1;
    int vizinho_y = j-1;
    if (vizinho_x > (linhas-1)){
        vizinho_x = 0;
    }
    if (vizinho_y < 0){
        vizinho_y = colunas-1;
    }
    vector<int> posicao{vizinho_x,vizinho_y};
    return posicao;
}

vector<int> vizinho8(int i, int j, int linhas, int colunas){
    int vizinho_x = i+1;
    int vizinho_y = j;
    if (vizinho_x > (linhas-1)){
        vizinho_x = 0;
    }
    vector<int> posicao{vizinho_x,vizinho_y};
    return posicao;
}

vector<int> vizinho9(int i, int j, int linhas, int colunas){
    int vizinho_x = i+1;
    int vizinho_y = j+1;
    if (vizinho_x > (linhas-1)){
        vizinho_x = 0;
    }
    if (vizinho_y > (colunas-1)){
        vizinho_y = 0;
    }
    vector<int> posicao{vizinho_x,vizinho_y};
    return posicao;
}

JogoDaVida::JogoDaVida(int l, int c){
    vector<vector<bool>> matriz(l, vector<bool>(c,false));
    vivas_ = matriz;
}

bool JogoDaVida::viva(int i, int j){
    if(i < 0 || j < 0 || i >= linhas() || j >= colunas()){
        ExcecaoCelulaInvalida e{i,j};
        throw e;
    }
    return vivas_[i][j];
}

void JogoDaVida::Matar(int i, int j){
    if(i < 0 || j < 0 || i >= linhas() || j >= colunas()){
        ExcecaoCelulaInvalida e{i,j};
        throw e;
    }
    vivas_[i][j] = false;
}

void JogoDaVida::Reviver(int i, int j){
    if(i < 0 || j < 0 || i >= linhas() || j >= colunas()){
        ExcecaoCelulaInvalida e{i,j};
        throw e;
    }
    vivas_[i][j] = true;
}

int JogoDaVida::NumeroDeVizinhasVivas(int x, int y){
    int vivas = 0;
    vector<vector<int>> vizinhos{
        vizinho1(x,y,linhas(),colunas()),
        vizinho2(x,y,linhas(),colunas()),
        vizinho3(x,y,linhas(),colunas()),
        vizinho4(x,y,linhas(),colunas()),
        vizinho6(x,y,linhas(),colunas()),
        vizinho7(x,y,linhas(),colunas()),
        vizinho8(x,y,linhas(),colunas()),
        vizinho9(x,y,linhas(),colunas())
    };
    for(int i = 0; i < vizinhos.size(); i++){
        if(viva(vizinhos[i][0],vizinhos[i][1])){
            vivas++;
        }
    }
    return vivas;
}

void JogoDaVida::ExecutarProximaIteracao(){
    vector<vector<bool>> novo_(linhas(), vector<bool>(colunas(), false));
    for(int i = 0; i < linhas(); i++){
        for(int j = 0; j < colunas(); j++){
            if((viva(i,j)) && (NumeroDeVizinhasVivas(i,j) < 2 || NumeroDeVizinhasVivas(i,j) > 3)){
                novo_[i][j] = false;
            }
            else if((viva(i,j)) && (NumeroDeVizinhasVivas(i,j) == 2 || NumeroDeVizinhasVivas(i,j) == 3)){
                novo_[i][j] = true;
            }
            else if((!viva(i,j)) && (NumeroDeVizinhasVivas(i,j) == 3)){
                novo_[i][j] = true;
            }
        }
    }
    vivas_ = novo_;
}
