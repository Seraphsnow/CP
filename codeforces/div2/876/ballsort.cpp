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

class myclass
{
public:
    ll n;
    ll *subs;
    ll b;
    myclass() {}
};

void solve()
{
    ll n;
    cin >> n;
    ll b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    bool sorted = true;
    for (int i = 0; i < n; i++)
    {
        if (b[i] != i + 1)
        {
            sorted = false;
            break;
        }
    }
    if (sorted)
    {
        for (int i = 0; i < n; i++)
        {
            cout << 0 << " ";
        }
        cout << endl;
        return;
    }
    myclass arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].n = n;
        arr[i].subs = new ll[n + 1];
        arr[i].b = b[i];
        for (int j = 1; j <= n; j++)
        {
            arr[i].subs[j] = -1;
        }
    }
    ll count = 1;
    for (int i = 1; i < n; i++)
    {
        if (b[i] > b[i - 1])
        {
            count++;
        }
        else
        {
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        bool full = true;
        for (int j = i + 1; j < n; j++)
        {
            if (b[j] > b[j - 1])
            {
                continue;
            }
            else
            {
                full = false;
                break;
            }
        }
        if (full)
        {
            arr[i].subs[0] = n - i;
        }
        else
        {
            arr[i].subs[0] = -1;
        }
    }
    for (int j = 1; j <= n; j++)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            arr[i].subs[j] = max<ll>(arr[i].subs[j - 1], 1);
            for (int k = i + 1; k < n; k++)
            {
                if (b[k] > b[k - 1])
                {
                    for (int m = k + 1; m < n; m++)
                    {
                        if (b[m] > b[k])
                        {
                            if (arr[m].subs[j - 1] == -1)
                            {
                                arr[i].subs[j] = max<ll>(arr[i].subs[j], k - i + 1);
                            }
                            else
                            {
                                arr[i].subs[j] = max<ll>(arr[i].subs[j], k - i + 1 + arr[m].subs[j - 1]);
                            }
                        }

                    }
                    arr[i].subs[j] = max<ll>(arr[i].subs[j], k-i+1);
                }
                else
                {
                    break;
                }
            }
            for (int k = i + 1; k < n; k++)
            {
                if (b[k] > b[i])
                {
                    if (arr[k].subs[j - 1] == -1)
                    {
                        arr[i].subs[j] = max<ll>(arr[i].subs[j], 1);
                    }
                    else
                    {
                        arr[i].subs[j] = max<ll>(arr[i].subs[j], 1 + arr[k].subs[j - 1]);
                    }
                }
                else
                {
                    continue;
                }
            }
            // loop lagana hai
        }
    }
    for(int j = 1;j <=n; j++){
        ll ans = arr[0].subs[j];
        for(int i = 1; i < n; i++){
            ans = max<ll>(ans, arr[i].subs[j-1]);
        }
        cout << n-ans << " ";
    }
    cout << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " ";
    //     for (int j = 0; j <= n; j++)
    //     {
    //         cout << arr[i].subs[j] << " ";
    //     }
    //     cout << endl;
    // }

    // for (int j = 2; j <= n; j++)
    // {
    //     for (int i = n - 1; i > 0; i++)
    //     {
    //         for (int k = i + 1; k < n; k++)
    //         {
    //             if (b[k] < b[i])
    //             {
    //                 continue;
    //             }
    //             else
    //             {
    //                 if (k > (i + arr[i].subs[2]))
    //             }
    //         }
    //     }
    // }
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