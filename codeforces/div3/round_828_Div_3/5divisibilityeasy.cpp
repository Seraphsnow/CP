#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a == 1)return b;
    else if(b == 1) return a;
    else return gcd(b, b%a);
}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    for(int z = 0; z < t; z++){
        long long int a,b,c,d;
        cin >> a >> b >> c >> d;
        bool solved = 0;
        for(int i = a+1; i < c+1; i++){
            for(int j = b+1; j < d+1; j++){
                if((gcd(j,b) == 1 && i%b != 0) || (gcd(i,a) == 1 && j%a != 0)) continue;
                if((i*j)%(a*b) == 0){ 
                    cout << i << " " << j << endl;
                    solved = 1;
                    break;
                }
            }
            if(solved) break;
        }
        if(!solved) cout << "-1 -1\n";
    }
}