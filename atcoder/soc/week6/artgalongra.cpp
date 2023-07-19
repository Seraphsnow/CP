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

class comparator
{
public:
    bool operator()(pll p1, pll p2)
    {
        return p1.fi < p2.fi;
    }
};

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> adj[n];
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a - 1].pb(b - 1);
        adj[b - 1].pb(a - 1);
    }
    bool guarded[n];
    for (int i = 0; i < n; i++)
    {
        guarded[i] = 0;
    }
    priority_queue<pll, vector<pll>, comparator> que;
    for (int i = 0; i < k; i++)
    {
        ll p, h;
        cin >> p >> h;
        que.push({h, p-1});
    }
    while (que.size())
    {
        pll top = que.top();
        que.pop();
        if (guarded[top.se])
        {
            continue;
        }
        guarded[top.se] = 1;
        if(top.fi == 0){
            continue;
        }
        for (int i = 0; i < adj[top.se].size(); i++)
        {
            ll ind = adj[top.se][i];
            if (!guarded[ind])
            {
                que.push({top.fi - 1, ind});
            }
        }
    }
    ll count = 0;
    for (int i = 0; i < n; i++)
    {
        if (guarded[i])
        {
            count++;
        }
    }
    cout << count << endl;
    for (int i = 0; i < n; i++)
    {
        if (guarded[i])
        {
            cout << i+1 << " ";
        }
    }
    cout << endl;
}