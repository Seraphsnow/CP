#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double

int main(int argc, char*argv[]){
    ll n,m,k;
    cin >> n >> m >> k;
    ll des[n];
    for(int i = 0; i < n; i++){
        cin >> des[i];
    }
    ll size[m];
    for(int i = 0; i < m; i++){
        cin >> size[i];
    }
    sort(des, des+n);
    sort(size, size+m);
    ll indexn = 0, indexm = 0, total = 0;
    while(true){
        if(indexn == n || indexm == m) break;
        if(des[indexn]-size[indexm] >= -1*k && des[indexn]-size[indexm] <= k){
            indexn++;
            indexm++;
            total++;
        }
        else if(des[indexn]-size[indexm]>k){
            indexm++;
        }
        else{
            indexn++;
        }
    }
    cout << total << endl;
}