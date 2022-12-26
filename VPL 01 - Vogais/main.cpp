#include <iostream>
#include <string>

using namespace std;

int main() {
    string palavra;
    int p = 0, a = 0, e = 0, i = 0, o = 0, u = 0;

    cin >> palavra;

    while (p <= (palavra.size())) {
        
        if (palavra[p]=='a'){
            a = a + 1;
        }
        if (palavra[p]=='e'){
            e = e + 1;
        }
        if (palavra[p]=='i'){
            i = i + 1;
        }
        if (palavra[p]=='o'){
            o = o + 1;
        }
        if (palavra[p]=='u'){
            u = u + 1;
        }

        p = p + 1;
    }

    if (a != 0){
        cout << "a " << a << endl;
    }

    if (e != 0){
        cout << "e " << e << endl;
    }

    if (i != 0){
        cout << "i " << i << endl;
    }

    if (o != 0){
        cout << "o " << o << endl;
    }

    if (u != 0){
        cout << "u " << u << endl;
    }
    
    return 0;
}