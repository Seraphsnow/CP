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
int main(int argc, char *argv[])
{
    ll n, m;
    cin >> n >> m;
    vector<ll> adj[2 * m + 1];
    bool arr[m+1];
    for (int i = 0; i < m; i++)
    {
        char c1, c2;
        ll n1, n2;
        cin >> c1 >> n1 >> c2 >> n2;
        if (c1 == '+' && c2 == '+')
        {
            adj[m + n1].pb(n2);
            adj[m + n2].pb(n1);
        }
        else if (c1 == '+' && c2 == '-')
        {
            adj[m + n1].pb(m + n2);
            adj[n2].pb(n1);
        }
        else if (c1 == '-' && c2 == '+')
        {
            adj[n1].pb(n2);
            adj[m + n2].pb(m + n1);
        }
        else
        {
            adj[n1].pb(m + n2);
            adj[n2].pb(m + n1);
        }
    }
    
}