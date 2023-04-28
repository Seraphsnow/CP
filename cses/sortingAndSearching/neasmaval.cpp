#include<bits/stdc++.h>
#include<limits.h>
// For policy data structures
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;

using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll,ll>
#define ull unsigned long long

template <typename T>
void printArr(T* arr, ll n){
    cout << endl << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
    cout << endl << endl;
}

int main(int argc, char*argv[]){
    ll n;
    cin >> n;
    ll arr[n];
    ll ans[n];
    cin >> arr[0];
    ans[0] = 0;
    cout << 0 << " ";
    for(int i = 1; i < n; i++){
        cin >> arr[i];
        ll index = i-1;
        while(index!= -1){
            if(arr[index]<arr[i]){
                ans[i] = index+1;
                break;
            }
            else{
                index = ans[index]-1;
            }
        }
        if(index == -1){
            ans[i] = 0;
        }
        cout << ans[i] << " ";
    }
    cout << endl;
}