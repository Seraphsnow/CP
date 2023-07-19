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

bool pal(pair<int, int> **arr, ll i, ll j, string s)
{
    // cout << i << " " << j << endl;
    if (i == j + 1)
    {
        // cout << 1 << endl;
        return 1;
    }
    if (i > j)
    {
        return 0;
    }

    if (i == j - 1)
    {

        if (s[i] != s[j])
        {
            // cout << 2 << endl;
            arr[i][j].fi = 1;
            arr[i][j].se = j;
            return 1;
        }
        else
        {
            arr[i][j].fi = 0;
            return 0;
        }
    }
    if (arr[i][j].fi != -1)
    {
        return arr[i][j].fi;
    }
    if (j % 2 == i % 2)
    {
        return 0;
    }
    bool ans = 0;
    ll count = 1;
    if (pal(arr,i,i+1,s) && s[i + 1] != s[i + 2] && pal(arr, i + 2, j, s))
    {
        arr[i][j].fi = 1;
        arr[i][j].se = i + 1;
        return 1;
    }
    for (int k = i + 3; k < j; k += 2)
    {
        if (s[k] != s[k + 1] && pal(arr, i + 1, k - 1, s) && pal(arr, k + 1, j, s))
        {

            arr[i][j].fi = 1;
            arr[i][j].se = k;
            return 1;
        }
    }
    if (pal(arr, i + 1, j - 1, s))
    {

        arr[i][j].fi = 1;
        arr[i][j].se = j;
        return 1;
    }

    arr[i][j].fi = 0;
    return 0;
}

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if (n % 2 == 1)
    {
        cout << "NO\n";
        return;
    }
    pair<int, int> **arr;
    arr = new pair<int, int> *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new pair<int, int>[n];

        for (int j = 0; j < n; j++)
        {
            arr[i][j] = {-1, -1};
        }
        arr[i][i] = {0, -1};
    }
    if (pal(arr, 0, n - 1, s))
    {
        cout << "YES" << endl;
        string ans = "";
        bool done[n];

        for (int i = 0; i < n; i++)
        {
            ans = ans + "!";
            done[i] = 0;
        }
        queue<pll> pairs;
        pairs.push({0, n - 1});
        while (pairs.size())
        {
            pll top = pairs.front();
            
            pairs.pop();
            ll ind1 = arr[top.fi][top.se].se;
            //cout << top.fi << " " << top.se << " " << ind1 << endl;
            ans[top.fi] = '(';
            ans[ind1] = ')';
            if (top.fi == (top.se - 1))
            {
                continue;
            }
            else
            {
                if (ind1 == top.se)
                {
                    pairs.push({top.fi + 1, top.se - 1});
                }
                else
                {
                    if (top.fi != ind1 - 1)
                    {
                        pairs.push({top.fi + 1, ind1 - 1});
                    }
                    pairs.push({ind1 + 1, top.se});
                }
            }
        }
        cout << ans << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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