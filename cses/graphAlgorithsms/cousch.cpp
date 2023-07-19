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

class Node
{
public:
    Node() {}
    ll index;
    ll height;
    vector<ll> adj;
    ll parent;
    ll endtime;
};

bool comp(Node n1, Node n2){
    return n1.endtime > n2.endtime;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    Node nodes[n + 1];
    for (int i = 1; i <= n; i++)
    {
        nodes[i].index = i;
        nodes[i].height = -1;
        nodes[i].parent = -1;
        nodes[i].endtime = -1;
    }
    for (int i = 0; i < m; i++)
    {
        ll a, c;
        cin >> a >> c;
        nodes[a].adj.pb(c);
        // nodes[c].adj.pb(a);
    }
    ll currind = 1;
    ll end = 0;
    while (currind <= n)
    {
        if (nodes[currind].height != -1)
        {
            currind++;
            continue;
        }
        stack<ll> dfs;
        dfs.push(currind);
        nodes[currind].height = 0;

        while (dfs.size())
        {
            ll top = dfs.top();
            bool found = false;
            for (int i = 0; i < nodes[top].adj.size(); i++)
            {
                ll ind = nodes[top].adj[i];
                if (nodes[ind].height == -1)
                {
                    nodes[ind].height = nodes[top].height + 1;
                    nodes[ind].parent = top;
                    dfs.push(ind);
                    found = true;
                    break;
                }
                else{
                    if(nodes[ind].endtime == -1){
                        cout << "IMPOSSIBLE" << endl;
                        return 0;
                    }
                }
            }
            if (found)
            {
                continue;
            }
            else
            {
                nodes[dfs.top()].endtime = end;
                end++;
                dfs.pop();
            }
        }
    }
    sort(nodes+1,nodes+n+1, comp);
    for(int i = 1; i <=n; i++){
        cout << nodes[i].index << " ";
    }
    cout << endl;
}