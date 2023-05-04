#include<bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]){
    int testcases;
    cin >> testcases;
    for(int i = 0 ; i < testcases; i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a == (b + c) || b == (c + a)|| c == (a+b)) cout << "YES\n";
        else cout << "NO\n";
    }

}