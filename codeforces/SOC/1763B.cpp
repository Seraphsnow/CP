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

bool comp(pll p1, pll p2)
{
    return p1.se < p2.se;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<pll> mons;
    for (int i = 0; i < n; i++)
    {
        pll p1;
        cin >> p1.fi;
        mons.pb(p1);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> mons[i].se;
    }
    
    sort(mons.begin(), mons.end(), comp);

    // cout << endl
    //      << endl;
    // for (ll i = 0; i < mons.size(); i++)
    // {
    //     cout << i << ": " << mons[i].fi << " " << mons[i].se << endl;
    // }
    // cout << endl
    //      << endl;

    ll totaldmg = 0, minIndex = 0;
    while (k > 0)
    {
        totaldmg += k;
        while (minIndex < mons.size())
        {
            if (mons[minIndex].fi <= totaldmg)
            {
                minIndex++;
            }
            else
            {
                k -= mons[minIndex].se;
                break;
            }
        }
        if (minIndex == mons.size())
        {
            cout << "YES\n";
            return;
        }
        //cout << totaldmg << " " << k << " " << minIndex << endl;
    }
    cout << "NO\n";
    return;
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