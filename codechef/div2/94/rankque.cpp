#include <bits/stdc++.h>
using namespace std;

// For policy data structures
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

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

ll mypow(ll a, ll b, ll m)
{
    ll ans = 1, pow = a;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            ans = (ans * pow) % m;
        }
        pow = (pow * pow) % m;
        b = b / 2;
    }
    return ans;
}

ll modInverse(ll A, ll M)
{
    ll m0 = M;
    ll y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1)
    {
        // q is quotient
        ll q = A / M;
        ll t = M;

        // m is remainder now, process same as
        // Euclid's algo
        M = A % M, A = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
}

bool comp1(ppll p1, ppll p2)
{
    return p1.fi.fi < p2.fi.fi || (p1.fi.fi == p2.fi.fi && p1.fi.se < p2.fi.se);
}
bool comp2(ppll p1, ppll p2)
{
    return p1.fi.se < p2.fi.se;
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    ppll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].fi.fi;
        a[i].fi.se = i;
    }
    sort(a, a + n, comp1);
    ll currind = 0;
    ll counts[n];

    while (currind < n)
    {
        ll num = a[currind].fi.fi;
        ll count = 0;
        currind++;
        while (currind < n && a[currind].fi.fi == num)
        {
            currind++;
            count++;
        }
        for (int i = currind - count - 1; i < currind; i++)
        {
            counts[i] = count;
            count--;
        }
    }
    ordered_set indices;
    for (int i = 0; i < n; i++)
    {
        indices.insert(a[i].fi.se);
        ll rank = indices.order_of_key(a[i].fi.se);
        ll nums = i + 1;
        // cout << rank << endl;
        a[i].se.fi = a[i].fi.se - rank;
        a[i].se.se = n - (i + 1) - a[i].se.fi - counts[i];
    }
    // for (int i = 0; i < n; i++)
    // {
    //     ppll num = a[i];
    //     cout << num.fi.fi << " " << num.fi.se << " "  << num.se.fi << " " << num.se.se << endl;

    // }
    sort(a, a + n, comp2);
    for(int i = 0; i < q; i++){
        ll k,r;
        cin >> k >> r;
        k--;

        ppll num = a[k];
        ll rank = num.se.fi+num.se.se+1;
        cout << num.fi.fi << " " << num.fi.se << " ";
        // cout << rank << " " << r << " " << k << " ";
        cout << num.se.fi << " " << num.se.se << endl;
        if(rank <=r){
            cout << 0 << endl;
        }
        else{
            ll diff = rank-r;
            ll currmin = min<ll>(num.se.fi, num.se.se);
            if(2*currmin >= diff){
                cout << (diff+1)/2 << endl;
            }
            else{
                cout << diff-currmin << endl;
            }
        }
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