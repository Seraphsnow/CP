#include <bits/stdc++.h>
using namespace std;

// For policy data structures
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;

//#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

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
T min3(T a, T b, T c){
    return min<T>(a,min<T>(b,c));
}

template <typename T>
T min4(T a, T b, T c, T d){
    return min<T>(min<T>(a,d),min<T>(b,c));
}

template <typename T>
T max3(T a, T b, T c){
    return max<T>(a,max<T>(b,c));
}

template <typename T>
T max4(T a, T b, T c, T d){
    return max<T>(max<T>(a,d),max<T>(b,c));
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
    while(b>0){
        if(b%2 == 1){
            ans = (ans * pow)%m;
        }
        pow = (pow * pow) % m;
        b = b/2;
    }
    return ans;
}

ll modInverse(ll A, ll M)
{
    ll m0 = M;
    ll y = 0, x = 1;
 
    if (M == 1)
        return 0;
 
    while (A > 1) {
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

bool comp(pair<pll,ll> p1, pair<pll,ll> p2){
    return p1.se > p2.se;
}

void solve()
{
    ll n,m;
    cin >> n >> m;
    set<ll> ones;
    vector<pll> segs;
    for(int i = 0; i < m; i++){
        ll l,r;
        cin >> l >> r;
        segs.pb({l,r});
    }
    sort(segs.begin(), segs.end());
    vector<pair<pll,ll>> uns;
    uns.pb({segs[0], segs[0].fi-segs[0].se-1});
    for(int i = 1; i < m; i++){
        if(uns.back().fi!=segs[i]){
            uns.pb({segs[i],segs[i].fi-segs[i].se-1});
        }
    }
    sort(uns.begin(), uns.end(), comp);
    ll q;
    cin >> q;
    bool done = false;
    ll val = -1;
    for(int i = 0; i < q; i++){
        ll num;
        cin >> num;
        ones.insert(num);
        if(!done){
            for(int j = 0; j < uns.size(); j++){
                if(num>=uns[j].fi.fi && num<=uns[j].fi.se){
                    uns[j].se+=2;
                    if(uns[j].se>0){
                        done = true;
                        val = i+1;
                        //cout << uns[j].fi.fi << " " <<uns[j].fi.se << endl;
                        break;
                    }
                }
                if(uns[j].fi.se-uns[j].fi.fi > i){
                    break;
                }
            }
        }
    }
    cout << val << endl;
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