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

vector<ll> decToBinary(ll n)
{
    // Size of an integer is assumed to be 32 bits
    vector<ll> ans;
    for (ll i = 31; i >= 0; i--)
    {
        ll k = n >> i;
        if (k & 1)
            ans.pb(1);
        else
            ans.pb(0);
    }
    return ans;
}

void solve()
{
    ll n;
    cin >> n;
    ll arr[n], ors = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ors = ors | arr[i];
    }
    if (ors == 0)
    {
        cout << n << endl;
        return;
    }
    ll all[n][n + 1];
    all[0][n] = ors;
    for (int i = 0; i < n; i++)
    {
        ll myor = 0;
        all[i][0] = 0;
        for (int j = i; j < n; j++)
        {
            myor = myor | arr[j];
            all[i][j - i + 1] = myor;
        }
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j <= n - i; j++)
        {
            if (all[j][i] == (all[0][j] | all[j + i][n - j - i]))
            {
                cout << i << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
    return;
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