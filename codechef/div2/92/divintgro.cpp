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

bool poss(ll mymin, ll* a, ll n, ll k){
    ll total = 0;
    for(int i = 0; i < n; i++){
        total+=min<ll>(mymin, a[i]);
    }
    if(total >= k*mymin){
        return true;
    }
    else{
        return false;
    }
}

void solve()
{
    ll n,k;
    cin >> n >> k;
    ll a[n];
    ll pref[n+1];
    pref[0] = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pref[i+1] = pref[i]+a[i];
    }
    if( k > n){
        cout << 0 << endl;
        return;
    }
    ll min = 1;
    while(true){
        if(poss(min, a, n, k)){
            min = min*2;
        }
        else{
            break;
        }
    }
    ll max = min;
     min = max/2;
    while(true){
        if(min == max){
            cout << min << endl;
            return;
        }
        ll mid = (min+max+1)/2;
        if(poss(mid, a, n, k)){
            min = mid;
        }
        else{
            max = mid-1;
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