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
    ll n1;
    cin >> n1;
    ll ans1 = 0;
    for (int j = 1; j <= n1; j++)
    {
        ll n = j;
        vector<pll> primes;
        ll count = 0;
        while (n % 2 == 0)
        {
            n = n / 2;
            count++;
        }
        if (count > 0)
        {
            primes.pb({2, count});
        }
        for (int i = 3; i <= sqrt(n); i++)
        {
            count = 0;
            while (n % i == 0)
            {
                n = n / i;
                count++;
            }
            if (count > 0)
            {
                primes.pb({i, count});
            }
        }
        if (n > 2)
        {
            primes.pb({n, 1});
        }
        ll ans = 1;
        for (int i = 0; i < primes.size(); i++)
        {
            if (primes[i].se == 1)
            {
                ans = (ans * (primes[i].fi + 1) % 1000000007) % 1000000007;
            }
            else
            {
                ans = (ans * ((lround(pow(primes[i].fi, primes[i].se + 1)) - 1) / (primes[i].fi - 1)) % 1000000007) % 1000000007;
            }
        }
        ans1 = (ans1 + ans)%1000000007;
    }
    cout << ans1 << endl;
}