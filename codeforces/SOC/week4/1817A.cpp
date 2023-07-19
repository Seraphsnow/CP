#include <bits/stdc++.h>
using namespace std;

// For policy data structures
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<long long, long long>
#define ppll pair<pll, pll>
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

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
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> s1;
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i - 1] >= a[i] && a[i] >= a[i + 1])
        {
            s1.pb(i + 1);
        }
    }
    s1.pb(n);
    // for(auto it = s1.begin(); it!= s1.end(); ++it){
    //     cout << *it << endl;
    // }
    for (int i = 0; i < q; i++)
    {
        ll l, r;
        cin >> l >> r;
        ll l1 = upper_bound(s1.begin(), s1.end(), l)-s1.begin();
        ll r2 = lower_bound(s1.begin(), s1.end(), r)-s1.begin();
        //cout << l1 << r2 << endl;
        ll numrem = r2-l1;
        if(numrem < 0){
            numrem = 0;
        }
        cout << r - l + 1 - numrem << endl;
    }
}