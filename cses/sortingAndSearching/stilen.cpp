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
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    ll best;
    if(n%2 == 1){
        best = arr[(n-1)/2];
    }
    else{
        best = (arr[(n-2)/2]+arr[n/2])/2;
    }
    ll check = 0;
    for(int i = 0; i < n; i++){
        check+=abs(best-arr[i]);
    }
    cout << check << endl;
}