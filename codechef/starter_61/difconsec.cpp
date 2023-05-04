#include<bits/stdc++.h>
#include<string>
using namespace std;

void solve(){
    int n;
    string num;
    cin >> n >> num;
    int count = 0;
    for(int i = 1; i < n ; i++){
        if(num[i-1] == num[i]) count++;
    }
    cout << count << endl;
}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    for(int i = 0 ; i < t; i++){
        solve();
    }
}