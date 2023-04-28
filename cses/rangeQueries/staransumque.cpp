#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double

int main(int argc, char*argv[]){
    ll n, q;
    cin >> n >> q;
    ll arr[n];
    ll sum[n+1];
    sum[0] = 0;
    ll mysum = 0;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mysum+=arr[i];
        sum[i+1] =mysum;
    }
    for(int i = 0; i < q; i++){
        int a,b;
        cin >> a >> b;
        cout << sum[b]-sum[a-1] << endl;
    }
}