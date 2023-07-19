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
    ll n, m;
    cin >> n >> m;
    bool prime = true;
    if (m % 2 == 0)
    {
        prime = false;
    }
    for (int i = 3; i <= sqrt(m); i += 2)
    {
        if (m % i == 0)
        {
            prime = false;
        }
        if (!prime)
        {
            break;
        }
    }
    if (!prime)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << i * m + j + 1 << " ";
            }
            cout << endl;
        }
    }
    else
    {
        if (n % 2 == 1)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << ((2 * i) % n) * m + j + 1 << " ";
                }
                cout << endl;
            }
        }
        else if (n != 4)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (i < n / 2)
                    {
                        cout << (2 * i) * m + j + 1 << " ";
                    }
                    else
                    {
                        cout << ((2 * i + 1) % n) * m + j + 1 << " ";
                    }
                }
                cout << endl;
            }
        }
        else
        {
            for (int j = 0; j < m; j++)
            {
                cout << j + 1 << " ";
            }
            cout << endl;
            for (int j = 0; j < m; j++)
            {
                cout <<2*m + j + 1 << " ";
            }
            cout << endl;
            cout << 2*m << " ";
            for (int j = 0; j < m-1; j++)
            {
                cout << m + j + 1 << " ";
            }
            cout << endl;
            cout << 4*m << " ";
            for (int j = 0; j < m-1; j++)
            {
                cout <<3*m + j + 1 << " ";
            }
            cout << endl;
            
        }
    }
    cout << endl;
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