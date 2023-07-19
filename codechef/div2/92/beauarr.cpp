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

void solve()
{
    ll MOD = 1000000007;
    ll n, k;
    cin >> n >> k;
    vector<ll> a;
    for (int i = 0; i < n; i++)
    {
        ll num;
        cin >> num;
        a.pb(num);
        // cin >> a[i];
    }

    sort(a.begin(), a.end());
    ll currindex = 0;
    vector<ll> finelems;

    while (k >= 0 && currindex < n - 1)
    {
        // cout << k << " " << currindex << endl;
        if (k >= (currindex + 1) * (a[currindex + 1] - a[currindex]))
        {
            k -= (currindex + 1) * (a[currindex + 1] - a[currindex]);
            currindex++;

            // cout << k << endl;
        }
        else
        {
            ll add = k / (currindex + 1);
            ll left = k - add * (currindex + 1);
            for (int i = 0; i < n; i++)
            {
                if (i <= currindex)
                {
                    if (i < left)
                    {
                        finelems.pb(a[currindex] + add + 1);
                    }
                    else
                    {
                        finelems.pb(a[currindex] + add);
                    }
                }
                else{
                    finelems.pb(a[i]);
                }
            }
            break;
        }
    }

    if (k != 0)
    {
        ll add = k / n;
        ll left = k - add * n;
        for (int i = 0; i < n; i++)
        {
            if (i < left)
            {
                finelems.pb(a[n - 1] + add + 1);
            }
            else
            {
                finelems.pb(a[n - 1] + add);
            }
        }
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            finelems[i] = finelems[i] % MOD;
            sum += finelems[i];
            sum = sum % MOD;
        }
        ll ans = 0;
        ans += sum * sum;
        for (int i = 0; i < n; i++)
        {
            ans -= finelems[i] * finelems[i];
            ans = (MOD * MOD + ans) % MOD;
        }
        cout << (ans * 500000004) % MOD << endl;
    }
    else
    {
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {

            finelems[i] = finelems[i] % MOD;
            sum += finelems[i];
            sum = sum % MOD;
        }
        ll ans = 0;
        ans += sum * sum;
        for (int i = 0; i < n; i++)
        {
            ans -= finelems[i] * finelems[i];
            ans = (MOD * MOD + ans) % MOD;
        }
        cout << (ans * 500000004) % MOD << endl;
    }
    // printVector<ll>(finelems);
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