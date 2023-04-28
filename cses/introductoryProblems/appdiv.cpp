#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double

ll opt(ll* arr,ll n,ll* arr1, ll* arr2, ll i1, ll i2){
    if(n == 0){
        ll ans = 0;
        for(int i = 0; i < i1; i++){
            ans+=arr1[i];
        }
        for(int i = 0; i < i2; i++){
            ans-=arr2[i];
        }
        return ans;
    }
    arr1[i1]= arr[n-1];
    ll ans1 = opt(arr, n-1, arr1, arr2, i1+1, i2);
    arr1[i1] = 0;
    arr2[i2] = arr[n-1];
    ll ans2 = opt(arr,n-1, arr1, arr2, i1, i2+1);
    if(abs(ans1) < abs(ans2)){
        return ans1;
    }
    else{
        return ans2;
    }
}

int main(int argc, char*argv[]){
    ll n;
    cin >> n;
    ll arr[n], arr1[n], arr2[n];
    ll sum = 0; 
    for(int i= 0; i < n; i++){
        cin >> arr[i];
        sum+=arr[i];
    }
    cout << abs(opt(arr, n, arr1, arr2, 0, 0)) << endl;
}