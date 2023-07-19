#include <bits/stdc++.h>
using namespace std;

// For policy data structures
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;

// #define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<long long, long long>
#define ppll pair<pll, pll>

template <typename T>
void printArr(T *arr, ll size)
{
    cout << endl
         << endl;
    for (ll i = 0; i < size; i++)
    {
        cout << i << ": " << arr[i] << endl;
    }
    cout << endl
         << endl;
}

template <typename T>
void printVector(vector<T> arr)
{
    cout << endl
         << endl;
    for (ll i = 0; i < arr.size(); i++)
    {
        cout << i << ": " << arr[i] << endl;
    }
    cout << endl
         << endl;
}

template <typename T>
T gcd(T a, T b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a % b);
    }
}

template <typename T>
T min3(T a, T b, T c)
{
    return min<T>(a, min<T>(b, c));
}

template <typename T>
T min4(T a, T b, T c, T d)
{
    return min<T>(min<T>(a, d), min<T>(b, c));
}

template <typename T>
T max3(T a, T b, T c)
{
    return max<T>(a, max<T>(b, c));
}

template <typename T>
T max4(T a, T b, T c, T d)
{
    return max<T>(max<T>(a, d), max<T>(b, c));
}

void adv_tokenizer(string s, char del) // Split string
{
    stringstream ss(s);
    string word;
    while (!ss.eof())
    {
        getline(ss, word, del);
        cout << word << endl;
    }
}

bool comp(pair<pll, pll> p1, pair<pll, pll> p2)
{
    return p1.se.se < p2.se.se || (p1.se.se == p2.se.se && p1.se.fi < p2.se.fi);
}

void solve()
{
    ll n;
    cin >> n;
    pair<pll, pll> edges[n - 1];
    vector<pll> adj[n + 1];
    ll par[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        par[i] = -1;
        ll u, v;
        cin >> u >> v;
        edges[i].fi.fi = min<ll>(u, v);
        edges[i].fi.se = max<ll>(u, v);
        adj[u].pb({v, i});
        adj[v].pb({u, i});
        edges[i].se.fi = i;
        if (u == 1 || v == 1)
        {
            edges[i].se.se = 1;
        }
    }

    par[n - 1] = -1;
    par[n] = -1;
    queue<ll> bfs;
    bfs.push(1);
    par[1] = -2;
    while (bfs.size() > 0)
    {
        ll top = bfs.front();
        bfs.pop();
        for (int i = 0; i < adj[top].size(); i++)
        {
            pll ind = adj[top][i];
            if (par[ind.fi] == -1)
            {
                par[ind.fi] = ind.se;
                if (top != 1)
                {
                    if (edges[par[top]].se.fi < edges[ind.se].se.fi)
                    {
                        edges[ind.se].se.se = edges[par[top]].se.se;
                    }
                    else
                    {
                        edges[ind.se].se.se = edges[par[top]].se.se+1;
                    }
                }
                bfs.push(ind.fi);
            }
        }
    }
    ll currmax = 0;
    for(int i = 0; i <n-1; i++){
        //cout << i << " " << edges[i].se.se << endl;
        currmax = max<ll>(currmax, edges[i].se.se);
    }
    cout << currmax << endl;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}