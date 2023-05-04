#include<bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]){
    int t;
    cin>> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        if( (a+b+c) == 180) cout << "YES\n";
        else cout << "NO\n";
    }
}