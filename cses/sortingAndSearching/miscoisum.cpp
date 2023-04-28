#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll,ll>
int main(int argc, char*argv[]){
    ll n;
    cin >> n;
    ll arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        if(arr[i]> sum+1){
            cout << sum+1 << endl;
            return 0;
        }
        else{
            sum+=arr[i];
        }
    }
    cout << sum+1 << endl;
}