#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double

int main(int argc, char*argv[]){
    ll n,x;
    cin >> n >> x;
    ll p[n];
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    sort(p, p+n);
    ll indexf = 0, indexb = n-1, num = 0;
    while(true){
        if(indexb <= indexf){
            break;
        }
        if(p[indexf]+p[indexb] <= x){
            num++;
            indexf++;
            indexb--;
        }
        else{
            indexb--;
        }
    }
    cout << n - num << endl;
}