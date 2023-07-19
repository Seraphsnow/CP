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
    vector<ll> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bool visited[n + 1];
    ll parent[n + 1];
    ll child[n + 1];
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
        parent[i] = -1;
        child[i] = -1;
    }
    queue<ll> bfs;
    bfs.push(1);
    visited[1] = true;
    bool poss = false;
    while (bfs.size() > 0)
    {
        ll top = bfs.front();
        bfs.pop();
        if (top == n)
        {
            poss = true;
            break;
        }
        for (int i = 0; i < adj[top].size(); i++)
        {
            if (!visited[adj[top][i]])
            {
                bfs.push(adj[top][i]);
                visited[adj[top][i]] = 1;
                parent[adj[top][i]] = top;
            }
        }
    }
    if (!poss)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        ll size = 1;
        ll curr = n;
        while (true)
        {
            ll par = parent[curr];
            child[par] = curr;
            size++;
            curr = par;
            if (curr == 1)
            {
                break;
            }
        }
        //cout << "hi" << endl;

        curr = 1;
        cout << size << endl;
        cout << curr << " ";
        while (true)
        {
            curr = child[curr];
            cout << curr << " ";
            if (curr == n)
            {
                break;
            }
        }
        cout << endl;
    }
}