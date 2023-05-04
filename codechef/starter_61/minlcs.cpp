#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int arr[2][26];
    for(int l = 0; l < 52; l++){
        arr[l/26][l%26] = 0;
    }
    for(int j = 0; j < 2;j++){
        for(int i = 0; i < n;i++){
            char elem; 
            cin >> elem;
            cout << elem << endl;
            arr[j][elem-97]++;
        }
    }
    int ans=0;
    for(int m = 0; m < 26;m++){
        int letter;
        letter = min(arr[1][m],arr[0][m]);
        ans = max(letter,ans);
    }
    cout << ans << endl;
}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    for(int i = 0 ; i < t; i++){
        solve();
    }
}