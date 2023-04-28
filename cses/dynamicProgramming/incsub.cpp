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
#define ull unsigned long long

template <typename T>
void printArr(T* arr, ll n){
    cout << endl << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
    cout << endl << endl;
}

ll binarySearch(ll arr[], ll l, ll r, ll x)
{
    //cout << l << " " << r << endl;

    if (l == r  || l > r)
    {
        return l;
    }
    ll m = (l + r) / 2;
    //cout << m << endl;
    if (arr[m] == x)
    {
        return m;
    }
    else if (arr[m] < x)
    {
        return binarySearch(arr, m + 1, r, x);
    }
    else
    {
        return binarySearch(arr, l, m-1, x);
    }
}

int main(int argc, char *argv[])
{
    ll n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = LONG_LONG_MAX;
        
    }
    //cout << arr[0] << endl;
    cin >> arr[0];

    for (int i = 1; i < n; i++)
    {
        ll num;
        cin >> num;
        ll index = binarySearch(arr, 0, n - 1, num);
        if(arr[index] >= num) arr[index] = num;
        else{
            arr[index+1] = num;
        }
        //printArr<ll>(arr, n);
    }
    for(int i = n-1; i>=0; i--){
        //cout << i << endl;
        if(arr[i] != LONG_LONG_MAX){
            //cout << arr[i] << " " << LONG_LONG_MAX << endl;
            cout << i+1 << endl;
            break;
        }
    }
}