#include <iostream>
#include <vector>

using namespace std;

int main(){
    int l1,l2,c2;

    cin >> l1 >> l2 >> c2;

    vector<vector<int>> matriz1(l1, vector<int>(l2));
    vector<vector<int>> matriz2(l2, vector<int>(c2));
    vector<vector<int>> matriz3(l1, vector<int>(c2));

    //Constroi a matriz 1
    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < l2; j++) {
            cin >>  matriz1[i][j];
        }
    }

    //Constroi a matriz 2
    for (int i = 0; i < l2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >>  matriz2[i][j];
        }
    }

    //Constroi a matriz 3
    for (int i = 0; i < l1; i++)
        for (int j = 0; j < c2; j++) {
            matriz3[i][j] = 0;
        }

    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < l2; k++) {
                matriz3[i][j] += matriz1[i][k] * matriz2[k][j];
            }        
        }
    }

    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << matriz3[i][j] << " ";
            if (j == c2-1) {
                cout << endl;
            }
        }
    }


    return 0;
}