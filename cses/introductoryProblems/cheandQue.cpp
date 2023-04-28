#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double

ll count(bool arr[][8], int left, int* queen){

    ll ans = 0;
    if(left == 0){
        return 1;
    }
    for(int i = 0; i < 8; i++){
        if(arr[8-left][i]){
            queen[8-left] = i;
            bool valid = 1;
            for(int j = 0; j < 8-left; j++){
                if(queen[j] == queen[8-left] || abs(queen[j] - queen[8-left]) == 8-left-j){
                    valid = 0;
                    break;
                }
            }
            if(valid){
                ans += count(arr, left-1, queen);
            }
        }
    }
    return ans;
    
}

int main(int argc, char*argv[]){
    bool arr[8][8];
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8;j++){
            char character;
            cin >> character;
            if(character == '.'){
                arr[i][j] = 1;
            }
            else{
                arr[i][j] = 0;
            }
            //cout << character << " ";
        }
        cout << endl;
    }
    
    int arr2[8];

    cout << count(arr, 8, arr2) << endl;
}