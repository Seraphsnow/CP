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
    ll k, n;
    cin >> k >> n;
    ll a[k+1], b[n], times[k + 1], num = 0;
    vector<ll> nums;
    for (int i = 0; i < k + 1; i++)
    {
        times[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[n];
        b[n] = b[n] % (k + 1);
        times[b[n]]++;
        if (times[b[n]] == 1)
        {
            num++;
            nums.pb(b[n]);
        }
    }
    if (num > k)
    {
        num = k;
    }
    if (num != k)
    {
        for (int i = 0; i < num; i++)
        {
            cout << "? " << nums[i] << endl;
            cin >> a[nums[i]];
        }
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            cout << "? " << i << endl;
            cin >> a[i];
        }
    }
    cout << "! ";
    if (num == k)
    {
        a[k] = 0;
        for (int i = 0; i < k; i++)
        {
            a[k] -= a[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[b[n]] << " ";
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