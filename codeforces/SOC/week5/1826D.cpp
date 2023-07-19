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
    ll n;
    cin >> n;
    ll b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    ll l = 0, r = 2;
    set<pll> elems;
    elems.insert({b[0], 0});
    elems.insert({b[1], 1});
    elems.insert({b[2], 2});
    ll ans = b[0] + b[1] + b[2] - 2;
    while (true)
    {
        if (elems.size() == 3)
        {
            if (r != n - 1)
            {
                elems.insert({b[r + 1], r + 1});
                r++;
                ll currans = (*next(elems.end(), -1)).fi + (*next(elems.end(), -2)).fi + (*next(elems.end(), -3)).fi - elems.size() + 1;
                ans = max<ll>(ans, currans);
            }
            else
            {
                break;
            }
        }
        else
        {
            pll elem = (*(next(elems.end(), -3)));
            if (r != n - 1 && b[r + 1] > elem.fi)
            {
                elems.insert({b[r + 1], r + 1});
                r++;
            }
            else if(b[l] < elem.fi || 
                        (b[l] == elem.fi &&
                            (
                                (l < elem.se) || 
                                (
                                    (*(next(elems.end(), -3))).fi >== (b[l]-1)
                                )
                            )
                        )
                    )
            {
                elems.erase({b[l],l});
                l++;
            }
            else{
                ll nextind = min((*(next(elems.end(), -2))).se , (*(next(elems.end(), -1))).se );
                for(int i = r+1; i <=nextind; i++){
                    
                }
            }
        }
        // cout << l << " " << r << endl;
    }
    cout << ans << endl;
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