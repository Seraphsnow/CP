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

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    set<ll> cols, rows;
    ll colmap[n + 1], rowmap[n + 1];
    for (int i = 0; i < n; i++)
    {
        cols.insert(i + 1);
        rows.insert(i + 1);
        colmap[i + 1] = 0;
        rowmap[i + 1] = 0;
    }
    cols.insert(n + 1);
    rows.insert(n + 1);
    for (int i = 0; i < q; i++)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll x, y;
            cin >> x >> y;
            colmap[x]++;
            if (colmap[x] == 1)
            {
                cols.erase(cols.find(x));
            }
            rowmap[y]++;
            if (rowmap[y] == 1)
            {
                rows.erase(rows.find(y));
            }
        }
        else if (t == 2)
        {
            ll x, y;
            cin >> x >> y;
            colmap[x]--;
            if (colmap[x] == 0)
            {
                cols.insert(x);
            }
            rowmap[y]--;
            if (rowmap[y] == 0)
            {
                rows.insert(y);
            }
        }
        else
        {
            ll x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            ll mincol = *cols.lower_bound(x1);
            if (mincol > x2)
            {
                cout << "YES\n";
                continue;
            }
            ll minrow = *rows.lower_bound(y1);
            if (minrow > y2)
            {
                cout << "YES\n";
                continue;
            }
            cout << "NO\n";
        }
    }
}