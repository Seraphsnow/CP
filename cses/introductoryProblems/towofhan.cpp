#include <bits/stdc++.h>
#include <cmath>
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
void printArr(T *arr, int n)
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

vector<pll> solve(ll n, ll start, ll finish, ll extra){
    if(n == 1){
        vector<pll> ans;
        ans.push_back({start,finish});
        return ans;
    }
    vector<pll> ans = solve(n-1, start, extra, finish);
    vector<pll> ans2 = solve(n-1, extra, finish, start);
    ans.pb({start,finish});
    for(int i = 0; i < ans2.size(); i++){
        ans.pb(ans2[i]);
    }
    return ans;
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    vector<pll> ans = solve(n, 1, 3, 2);
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i].fi << " " << ans[i].se << endl;
    }
    
}