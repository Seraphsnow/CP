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

void solve()
{
    ll n;
    cin >> n;
    ll freq[n];
    pll pairs[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> freq[i];
        pairs[i] = {-1, 0};
    }
    pairs[n] = {-1, -1};
    ll arr[n];
    ll num = 1;
    for (int i = 0; i < n; i++)
    {
        ll myfre = freq[i];
        if(myfre > n ){
            cout << -1 << endl;
            return;
        }
        if (pairs[myfre].fi == -1)
        {
            pairs[myfre] = {num, 1};
            arr[i] = num;
            num++;
        }
        else
        {
            arr[i] = pairs[myfre].fi;
            pairs[myfre].se++;
        }
        if (pairs[myfre].se == myfre)
        {
            pairs[myfre] = {-1, 0};
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (pairs[i].fi != -1)
        {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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