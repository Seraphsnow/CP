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

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.fi < p2.fi;
}

void solve()
{
    int n;
    cin >> n;
    pair<int, int> arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].fi;
        arr[i].se = i;
    }
    if (n == 1)
    {
        cout << 0 << "\n";
        return;
    }
    if (n % 2 == 0)
    {
        sort(arr, arr + n);
        ll ans = n / 2, i1 = n / 2 - 1, p1 = arr[i1].se, i2 = n / 2, p2 = arr[i2].se;
        if (p1 > p2)
        {
            cout << ans << "\n";
            return;
        }
        else
        {
            ans--;
        }
        i1--;
        i2++;
        while (i1 >= 0 && i2 <= n)
        {
            if (arr[i1].se < p1 && arr[i2].se > p2)
            {
                p1 = arr[i1].se;
                p2 = arr[i2].se;
                i1--;
                i2++;
                ans--;
            }
            else
            {
                cout << ans << endl;
                return;
            }
        }
        cout << ans << endl;
    }
    else
    {
        sort(arr, arr + n);
        ll ans = (n - 1) / 2, i1 = (n - 1) / 2 - 1, p1 = arr[i1].se, i2 = (n + 1) / 2, p2 = arr[i2].se, i3 = (n - 1) / 2, p3 = arr[i3].se;
        ;
        if (!(p1 < p3 && p3 < p2))
        {
            cout << ans << "\n";
            return;
        }
        else
        {
            ans--;
        }
        i1--;
        i2++;
        while (i1 >= 0 && i2 <= n)
        {
            if (arr[i1].se < p1 && arr[i2].se > p2)
            {
                p1 = arr[i1].se;
                p2 = arr[i2].se;
                i1--;
                i2++;
                ans--;
            }
            else
            {
                cout << ans << endl;
                return;
            }
        }
        cout << ans << endl;
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