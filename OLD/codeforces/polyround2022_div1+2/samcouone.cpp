#include <bits/stdc++.h>
using namespace std;

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

bool compare1(pair<vector<ll>, pll> p1, pair<vector<ll>, pll> p2)
{
    if (p1.se.se > p2.se.se)
        return true;
    return false;
}

bool compare2(pair<vector<ll>, pll> p1, pair<vector<ll>, pll> p2)
{
    if (p1.se.se < p2.se.se)
        return true;
    return false;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> indices[n + 1];
    ll numones[n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ll aij;
            cin >> aij;
            if (aij == 1)
            {
                indices[i].pb(j);
            }
        }
        numones[i] = indices[i].size();
    }
    ll total = accumulate(numones + 1, numones + n + 1, 0);
    if (total % n != 0)
    {
        cout << -1 << endl;
        return;
    }
    bool same = true;
    for (int i = 2; i < n + 1; i++)
    {
        if (numones[i] != numones[i - 1])
        {
            same = false;
            break;
        }
    }
    if (same)
    {
        cout << 0 << endl;
        return;
    }
    vector<pair<vector<ll>, pll>> lessthan, greaterthan;
    for (int i = 1; i < n + 1; i++)
    {
        if (numones[i] > total / n)
        {
            greaterthan.pb({indices[i], {i, numones[i]}});
        }
        else if (numones[i] < total / n)
        {
            lessthan.pb({indices[i], {i, numones[i]}});
        }
    }
    sort(greaterthan.begin(), greaterthan.end(), compare1);
    sort(lessthan.begin(), lessthan.end(), compare2);
    ll k = 0;
    for (int i = 0; i < greaterthan.size(); i++)
    {
        k += greaterthan[i].fi.size() - total / n;
    }
    cout << k << endl;
    ll i = 0, j = 0;
    while (!greaterthan.empty())
    {
        ll gti = greaterthan.size() - 1;
        vector<ll> myindices = greaterthan[gti].fi;
        ll index = greaterthan[gti].se.fi;
        while (myindices.size() != total / n)
        {
            ll triplem = myindices[myindices.size()-1];
            for (ll i = lessthan.size(); i >= 0; i--)
            {
                find()
            }
        }
    }
}

int main(int argc, char *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}