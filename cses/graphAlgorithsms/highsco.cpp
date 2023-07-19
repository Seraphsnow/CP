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

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<pair<pll, ll>> edges;
    ll *distances;
    bool *reachable;
    distances = new ll[n];
    reachable = new bool[n];
    vector<ll> adj[n];
    for (int i = 0; i < n; i++)
    {
        distances[i] = LONG_LONG_MIN;
    }
    distances[0] = 0;
    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        edges.pb({{a - 1, b - 1}, c});
        adj[b-1].pb(a-1);
    }
    queue<ll> bfs;
    bfs.push(n-1);
    reachable[n-1] = true;
    while(bfs.size()){
        ll top = bfs.front();
        bfs.pop();
        for(int i = 0; i < adj[top].size(); i++){
            ll ind = adj[top][i];
            if(!reachable[ind]){
                bfs.push(ind);
                reachable[ind] = true;
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            ll a = edges[j].fi.fi, b = edges[j].fi.se, c = edges[j].se;
            if (distances[a] != LONG_LONG_MIN)
            {
                distances[b] = max<ll>(distances[b], distances[a] + c);
            }
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << distances[i] << endl;
    // }
    ll dis1[n];
    for(int i = 0; i < n; i++){
        dis1[i] = distances[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            ll a = edges[j].fi.fi, b = edges[j].fi.se, c = edges[j].se;
            if (distances[a] != LONG_LONG_MIN)
            {
                distances[b] = max<ll>(distances[b], distances[a] + c);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(dis1[i]!=distances[i] && reachable[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << dis1[n - 1] << endl;
}