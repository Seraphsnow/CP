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

bool poss(ll med, ll *cost, ll *a, ll n, ll k)
{
    ll needed = 0;
    for (int i = 0; i <= (n - 1) / 2; i++)
    {
        if (a[i] <= med)
        {
            continue;
        }
        else
        {
            ll k = ceil((a[i]+1)/(med+1));
            needed += cost[k - 1];
        }
    }
    if (needed <= k)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve()
{

    ll n, m, k;
    cin >> n >> m >> k;
    ll *a;
    a = new ll[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll *cost;
    cost = new ll[m];
    for (int i = 0; i < m; i++)
    {
        cin >> cost[i];
    }
    ll *mincost;
    mincost = new ll[m];
    mincost[m - 1] = cost[m - 1];
    for (int i = m - 2; i >= 0; i--)
    {
        mincost[i] = min(mincost[i + 1], cost[i]);
    }
    sort(a, a + n);
    ll min = 0, max = a[(n - 1) / 2];
    
    while (true)
    {
        if (min == max)
        {
            cout << min << endl;
            return;
        }
        ll mid = (min + max) / 2;
        if (poss(mid, mincost, a, n, k))
        {
            max = mid ;
        }
        else
        {
            min = mid + 1;
        }
        //cout << min << " " << max << endl;
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