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

class node
{
public:
    ll index;
    vector<pll> adj;
    ll distance;
    bool done;
    ll count;
    ll minsize;
    ll maxsize;
    node() {}
};

class comparator
{
public:
    bool operator()(pll a, pll b)
    {
        if (a.fi > b.fi)
        {
            return true;
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    node nodes[n + 1];
    priority_queue<pll, vector<pll>, comparator> dist;
    for (int i = 1; i <= n; i++)
    {
        nodes[i].index = i;
        nodes[i].distance = LONG_LONG_MAX;
        nodes[i].done = false;
        nodes[i].count = 0;
        nodes[i].minsize = -1;
        nodes[i].maxsize = -1;
    }
    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        nodes[a].adj.pb({b, c});
    }

    nodes[1].distance = 0;
    ll last = 1;
    ll done = 1;
    nodes[1].done = 1;
    nodes[1].count = 1;
    nodes[1].minsize = 0;
    nodes[1].maxsize = 0;
    while (done < n)
    {
        ll currnode = last;
        for (int i = 0; i < nodes[currnode].adj.size(); i++)
        {
            pll ind = nodes[currnode].adj[i];
            if (!nodes[ind.fi].done && nodes[ind.fi].distance > nodes[currnode].distance + ind.se)
            {
                nodes[ind.fi].distance = nodes[currnode].distance + ind.se;
                nodes[ind.fi].count = nodes[currnode].count;
                nodes[ind.fi].maxsize = nodes[currnode].maxsize + 1;
                nodes[ind.fi].minsize = nodes[currnode].minsize + 1;
                dist.push({nodes[ind.fi].distance, ind.fi});
            }
            else if (!nodes[ind.fi].done && nodes[ind.fi].distance == nodes[currnode].distance + ind.se)
            {
                nodes[ind.fi].count = (nodes[ind.fi].count + nodes[currnode].count) % 1000000007;
                nodes[ind.fi].maxsize = max<ll>(nodes[currnode].maxsize + 1, nodes[ind.fi].maxsize);
                nodes[ind.fi].minsize = min<ll>(nodes[currnode].minsize + 1, nodes[ind.fi].minsize);
            }
        }
        while (true)
        {
            last = dist.top().se;
            if (!nodes[last].done)
            {
                nodes[last].done = 1;
                dist.pop();
                break;
            }
            dist.pop();
        }
        done++;
    }
    cout << nodes[n].distance << endl;
    cout << nodes[n].count << endl;
    cout << nodes[n].minsize << endl;
    cout << nodes[n].maxsize << endl;
}