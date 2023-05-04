#include<bits/stdc++.h>
using namespace std;

char checkRow(int i, char arr[8][8]){
    if(arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2] && arr[i][0] == arr[i][3] && arr[i][0] == arr[i][4] && arr[i][0] == arr[i][5] && arr[i][0] == arr[i][6] && arr[i][0] == arr[i][7]) return arr[i][0];
    else return '.';
}
char checkColumn(int i, char arr[8][8]){
    if(arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i] &&arr[0][i] == arr[3][i] &&arr[0][i] == arr[4][i] &&arr[0][i] == arr[5][i] &&arr[0][i] == arr[6][i] &&arr[0][i] == arr[7][i]) return arr[0][i];
    else return '.';
}

int main(int argc, char*argv[]){
    int testcases;
    cin >> testcases;
    for(int i = 0; i < testcases; i++){
        char arr[8][8];
        bool solved = 0;
        for(int j = 0; j < 8;j++){
            for(int k = 0; k < 8; k++){
                cin >> arr[j][k];
            }
        }
        for(int l = 0; l < 8; l++){
            if(checkColumn(l,arr) == 'R' || checkRow(l,arr) == 'R') {cout << "R\n";break;}
            else if(checkColumn(l,arr) == 'B' || checkRow(l,arr) == 'B') {cout << "B\n";break;}
        }
    }
}