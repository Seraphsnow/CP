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

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, w;
    cin >> n >> w;
    vector<pll> data;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        ll wi, vi;
        cin >> wi >> vi;
        sum += vi;
        data.pb({wi, vi});
    }
    ll **arr;
    arr = new ll *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = new ll[sum + 1];
        arr[i][0] = 0;
    }
    for (int i = 1; i <= sum; i++)
    {
        arr[0][i] = -1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j >= data[i - 1].se)
            {
                if (arr[i - 1][j - data[i - 1].se] == -1)
                {
                    arr[i][j] = arr[i - 1][j];
                }
                else
                {
                    if (arr[i - 1][j] == -1)
                    {
                        arr[i][j] =  arr[i - 1][j - data[i - 1].se] + data[i - 1].fi;
                    }
                    else
                    {
                        arr[i][j] = min<ll>(arr[i - 1][j], arr[i - 1][j - data[i - 1].se] + data[i - 1].fi);
                    }
                }
            }
            else
            {
                arr[i][j] = arr[i - 1][j];
            }
        }
    }
    //cout << arr[1][30] << endl;
    for (int i = sum; i >= 0; i--)
    {
        //cout << i << " " << arr[n][i] << endl;
        if (arr[n][i] <= w && arr[n][i] != -1)
        {
            // cout << n << endl;
            // cout << arr[n][i] << endl;
            cout << i << endl;
            return 0;
        }
    }
}