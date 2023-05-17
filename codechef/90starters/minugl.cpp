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
    vector<ll> adj;
    ll ugliness;
    ll height;
    ll parent;
    bool visited;
    vector<ll> children;
    node()
    {
        parent = -1;
        ugliness = -1;
        height = 0;
        visited = false;
    };
};

void solve()
{
    ll n, q;
    cin >> n >> q;
    node arr[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        arr[a].adj.pb(b);
        arr[b].adj.pb(a);
    }
    vector<ll> bfsStack;
    bfsStack.push_back(1);
    ll currindex = 0;
    while (currindex < bfsStack.size())
    {
        ll index = bfsStack[currindex];
        arr[index].visited = 1;
        for (int i = 0; i < arr[index].adj.size(); i++)
        {
            ll adin = arr[index].adj[i];
            if (arr[adin].visited == 0)
            {
                arr[adin].parent = index;
                bfsStack.pb(adin);
                arr[adin].visited = 1;
                arr[index].children.pb(adin);
            }
        }
        currindex++;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        ll index = bfsStack[i];
        for (int j = 0; j < arr[index].children.size(); j++)
        {
            arr[index].height = max<ll>(arr[index].height, arr[arr[index].children[j]].height+1);
        }
    }
    for(int i = 0; i < n; i++){
        ll index = bfsStack[i];
        if(arr[index].parent == -1){
            arr[index].ugliness = arr[index].height;
        }
        else{
            arr[index].ugliness = arr[index].height;
            ll par = arr[index].parent;
            for(int j = 0; j < arr[par].children.size(); j++){
                if(arr[par].children[j] == index) continue;
                else{
                    arr[index].ugliness = max<ll>(arr[index].ugliness, arr[arr[par].children[j]].height+2);
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << arr[i+1].ugliness << endl;
    }
    // for (int i = 0; i < q; i++)
    // {
    //     ll k;
    //     cin >> k;
    //     ll ans = LONG_LONG_MAX;
    //     for(int j = 0; j < k; j++){
    //         ll index;
    //         cin >> index;
    //         ans = min<ll>(ans, arr[index].ugliness);
    //     }
    //     cout << ans << endl;
    // }
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