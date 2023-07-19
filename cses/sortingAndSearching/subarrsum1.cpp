#include <bits/stdc++.h>
#include <limits.h>
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
#define pll pair<ll, ll>
#define ppll pair<pll, pll>
#define ull unsigned long long

template <typename T>
void printArr(T *arr, ll n)
{
    cout << endl
         << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl
         << endl;
}

int main(int argc, char *argv[])
{
    ll n, x;
    cin >> n >> x;
    ll arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    ll currsum = 0;
    ll minindex = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        currsum+=arr[i];
        while(currsum > x){
            currsum -=arr[minindex];
            minindex++;
        }
        if(currsum == x){
            ans++;
        }
    }
    cout << ans << endl;
}