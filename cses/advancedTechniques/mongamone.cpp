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

int main(int argc, char *argv[])
{
    ll n, x;
    cin >> n >> x;
    ll s[n], f[n+1];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
    }
    ll arr[n];
    for(int i=0; i < n; i++){
        arr[i] = LONG_LONG_MAX;
    }
    arr[n-1] = 0;
    for(int i = n-2; i >=0; i++){

        for(int j = i+1; j < n; j++){
            arr[i] = min<ll>(arr[i], f[i]*s[j] + arr[j]);
        }
    }
    ll ans = LONG_LONG_MAX;
    for(int i = 0; i < n; i++){
        ans = min(ans, x*s[i] + arr[i]);
    }
    cout << ans << endl;
}