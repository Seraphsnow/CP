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
#define MOD 998244353
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

ll ans[300001];

void setup(){
    for(int i = 0;i < 300001;i++){
        ans[i] = -1;
    }
    ans[0] = 1;
}

ll hyper(ll n){
    if(ans[n]!=-1){
        return ans[n];
    }
    else{
        if(n%2 == 1){
            ans[n] = 0;
            return ans[n];
        }
        ll currans = 0;
        for(int i = 0; i <= n-2; i++){
            currans = (currans + hyper(i)*hyper(n-2-i)) % MOD;
        }
        ans[n] = currans;
        return currans;
    }
}

void solve()
{
    ll n,k;
    cin >> n >> k;
    if(k == 0){
        cout << hyper(n) << endl;
        return;
    }
    pll ints[k];
    for(int i = 0; i < k; i++){
        cin >> ints[i].fi >> ints[i].se;
    }
    sort(ints, ints+k);
    ll arr[n+1];
    for(int i = 0; i <= n; i++){
        arr[i] = -1;
    }
    set<pll> nums;
    for(int i = 0; i <k; i++){
        ll l = ints[i].fi, r = ints[i].se;
        if(nums.size() == 0){
            nums.insert({l,r});
        }
        else{
            pll pair = *nums.lower_bound({l,-1});
            if(pair.fi > r){
                
            }
        }
    }
    ll total = n;
    ll ans = 1;
    ll currindex = 1;
    while(currindex <= n){
        // cout << "hi" << endl;
        // cout << currindex << endl;
        if(arr[currindex] == -1){
            currindex++;
        }
        else{
            ans = (ans * hyper(arr[currindex]+1-currindex))% MOD;
            total = total - (arr[currindex]+1-currindex);
            currindex = arr[currindex]+1;
        }
    }
    
    ans = (ans * hyper(total))%MOD;
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