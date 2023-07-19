#include <bits/stdc++.h>
using namespace std;

// For policy data structures
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;

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
    bool part;
    ll height;

    node()
    {
        height = -1;
        part = 0;
    };
    ll index;
    vector<pll> adj;
    ll par;
    ll paredgenum;
    vector<pll> child;
};

void solve()
{
    ll n;
    cin >> n;
    node arr[n + 1];
    pll edges[n];
    for (int i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        arr[i + 1].index = i + 1;
        arr[a].adj.pb({b, i + 1});
        arr[b].adj.pb({a, i + 1});
        edges[i + 1] = {a, b};
    }
    if (n % 3 != 0)
    {
        cout << -1 << endl;
        return;
    }
    if (n == 3)
    {
        cout << 0 << endl
             << endl;
        return;
    }
    arr[n].index = n;
    vector<ll> bfs;
    ll currindex = 0;
    bfs.push_back(1);
    arr[1].height = 0;
    arr[1].par = -1;
    arr[1].paredgenum = -1;

    while (currindex < n)
    {
        ll index = bfs[currindex];
        for (int i = 0; i < arr[index].adj.size(); i++)
        {
            ll adjindex = arr[index].adj[i].fi;
            ll edgenum = arr[index].adj[i].se;
            if (arr[adjindex].height == -1)
            {
                arr[adjindex].height = arr[index].height + 1;
                arr[adjindex].par = index;
                arr[adjindex].paredgenum = edgenum;
                bfs.push_back(adjindex);
                arr[index].child.push_back({adjindex, edgenum});
            }
        }
        currindex++;
    }
    //printVector(bfs);
    vector<ll> cuts;
    for (int i = n - 1; i >= 0; i--)
    {
        ll index = bfs[i];
        //cout << index << endl;
        
        if (arr[index].part)
        {
            continue;
        }
        arr[index].part = true;
        ll parent = arr[index].par;
        // for(int i = 0; i < arr[parent].child.size(); i++){
        //     cout << arr[parent].child[i].fi << endl;
        // }
        if (parent == -1)
        {
            cout << -1 << endl;
            return;
        }
        if (arr[parent].child.size() >= 3)
        {
            cout << -1<< endl;
            return;
        }
        else if (arr[parent].child.size() == 2)
        {
            if (arr[parent].par != -1)
            {
                cuts.pb(arr[parent].paredgenum);
                ll gp = arr[parent].par;
                for (int i = 0; i < arr[gp].child.size(); i++)
                {
                    if (arr[gp].child[i].fi == parent)
                    {
                        arr[gp].child.erase(arr[gp].child.begin() + i);
                        break;
                    }
                }
            }

            arr[parent].part = true;
            for (int i = 0; i < 2; i++)
            {
                arr[arr[parent].child[i].fi].part = true;
            }
        }
        else if (arr[parent].child.size() == 1)
        {
            arr[parent].part = true;
            ll gp = arr[parent].par;
            if (gp == -1)
            {
                cout << -1 << endl;
                return;
            }
            else
            {
                ll ggp = arr[gp].par;
                if (ggp != -1)
                {
                    cuts.pb(arr[gp].paredgenum);
                    for (int i = 0; i < arr[ggp].child.size(); i++)
                    {
                        if (arr[ggp].child[i].fi == gp)
                        {
                            arr[ggp].child.erase(arr[ggp].child.begin() + i);
                            break;
                        }
                    }
                }
            }
            arr[gp].part = true;
            for (int i = 0; i < arr[gp].child.size(); i++)
            {
                if (arr[gp].child[i].fi == parent)
                    continue;
                else
                {
                    ll ccind = arr[gp].child[i].fi;
                    arr[ccind].par = -1;
                }
            }
        }
    }
    cout << cuts.size() << endl;
    for(int i = 0; i< cuts.size();i++){
        cout << cuts[i] << " ";
    }
    cout << endl;
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