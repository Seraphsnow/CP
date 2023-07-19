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

ll *ks, *factor;
void setup()
{
    ks = new ll[20000001];
    factor = new ll [20000001];
    memset(ks, 0, 20000001 * sizeof(*ks));
    memset(factor, 0, 20000001 * sizeof(*ks));
    ks[1] = 1;
    factor[1] = 1;
    for (int i = 2; i <= 20000000; i++)
    {
        if (factor[i] == 0)
        {
            ks[i] = 2;
            factor[i] = i;
            ll num = 2 * i;
            while (num <= 20000000)
            {
                factor[num] = i;
                num += i;
            }
        }
    }
    for (int i = 2; i <= 20000000; i++)
    {
        if (ks[i] == 0)
        {
            ll small = i/factor[i];
            if(small%factor[i] == 0){
                ks[i] = ks[small];
            }
            else{
                ks[i] = 2*ks[small];
            }
        }
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

// ll primes(ll k, ll min)
// {
//     if (ks[k] != -1)
//     {
//         if (ks[k] == 0)
//         {
//             ks[k] = 2;
//         }
//         return ks[k];
//     }
//     if (k % 2 == 0)
//     {
//         ll newk = k;
//         while (newk % 2 == 0)
//         {
//             newk = newk / 2;
//         }
//         ks[k] = 2 * primes(newk, 3, ks);
//         return ks[k];
//     }
//     for (int i = min; i <= sqrt(k); i += 2)
//     {
//         if (k % i == 0)
//         {
//             ll newk = k;
//             while (newk % i == 0)
//             {
//                 newk = newk / i;
//             }
//             ks[k] = 2 * primes(newk, i + 2, ks);
//             return ks[k];
//         }
//     }

//     ks[k] = 2;
//     return 2;
// }

void solve()
{

    ll c, d, x;
    cin >> c >> d >> x;
    ll ans = 0;
    ll mygcd = gcd(c, gcd(d, x));
    c /= mygcd;
    d /= mygcd;
    x /= mygcd;
    for (int i = 1; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            if ((d + i) % c == 0)
                ans += ks[(d+i)/c];
            if (i != x / i)
            {
                if ((d + x / i) % c == 0)
                    ans += ks[(d+x/i)/c];
            }
        }
    }

    cout << ans << endl;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    setup();
    while (t--)
    {
        solve();
    }
}