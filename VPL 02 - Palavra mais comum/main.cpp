#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(){
    int i = 0, maior = 0;
    string frase, inter, mais;
    map<string,int> contador;

    getline(cin, frase, '\0');

    stringstream X(frase);

    while (getline(X, inter, ' ')) {
        contador[inter]++;
    }

    map<string,int>::iterator it;
    for (it = contador.begin(); it != contador.end(); ++it) {
        if (it->second > maior) {
            maior = it->second;
            mais = it->first;
        }
    }

    cout << mais << endl;

    return 0;
}