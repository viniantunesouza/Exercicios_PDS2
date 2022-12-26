#include <iostream>
#include <vector>

using namespace std;

int main(){
    int var = 10; // 1) Declare uma variável do tipo inteiro e atribua o valor '10'

    int *ptr = nullptr; // 2) Declare um ponteiro para inteiros e inicialize com valor nulo (aka 'nullptr')

    int v[10] = {9,8,7,6,5,4,3,2,1,0}; // 3) Declare um vetor de inteiros e inicialize com valores de 9 a 0 (nessa ordem)

    cout << &var << endl;  // 4) Imprima o ENDEREÇO da variável declarada em (1)

    cout << var << endl; // 5) Imprima o CONTEÚDO da variável declarada em (1)

    cout << &ptr << endl; // 6) Imprima o ENDEREÇO da variável declarada em (2)

    cout << ptr << endl; // 7) Imprima o CONTEÚDO da variável declarada em (2)

    cout << &v << endl; // 8) Imprima o ENDEREÇO da variável declarada em (3)

    cout << &v[0] << endl; // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)

    cout << v[0] << endl; // 10) Imprima o CONTEÚDO da primeira posição da variável declarada em (3)

    ptr = &var; // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)

    cout << &ptr << endl; // 12) Imprima o CONTEÚDO da variável declarada em (2)

    cout << (*ptr) << endl; // 13) Imprima o CONTEÚDO da varíavel que é apontada por (2)

    cout << (&var == ptr) << endl; // 14) Imprima o resultado da comparação do ENDEREÇO de (1) e do CONTEÚDO de (2)

    (*ptr) = 5; // 15) Coloque o VALOR '5' na varíavel que é apontada pela variável de (2)

    cout << var << endl; // 16) Imprima o CONTEÚDO da variável declarada em (1)

    ptr = &v[0]; // 17) Atribua o CONTEÚDO da variável de (3) à variável de (2)

    cout << ptr << endl; // 18) Imprima o CONTEÚDO da variável declarada em (2) 

    cout << (*ptr) << endl; // 19) Imprima o CONTEÚDO da variável que é apontada pela variável de (2)

    ptr = &v[0]; // 20) Atribua o ENDEREÇO da primeira posição de (3) à variável de (2)

    cout << ptr << endl; // 21) Imprima o CONTEÚDO da variável declarada em (2) 

    cout << (*ptr) << endl; // 22) Imprima o CONTEÚDO da variável que é apontada pela variável de (2) 

    for (int i = 0; i <= 8; i++) {
        cout << v[i] << " ";
    }

    cout << v[9] << endl; // 23) Imprima os elementos de (3) utilizando a notação [] (e.g. v[i])

    for (int i = 0; i <= 8; i++) {
        cout << *(v + i) << " ";
    }

    cout << *(v + 9) << endl; // 24) Imprima os elementos de (3) utilizando a notação ponteiro/deslocamento (e.g. *(v + i))

    return 0;
}