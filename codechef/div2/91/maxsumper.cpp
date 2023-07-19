#include <bits/stdc++.h>
using namespace std;

// For policy data structures
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;

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

bool comp(pll p1, pll p2){
    return p1.fi < p2.fi ||(p1.fi == p2.fi && p1.se < p2.se);
}

bool comp2(pll p1, pll p2){
    return p1.se > p2.se;
}


void solve()
{
    ll n,q;
    cin >> n >> q;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    pll arr[q];
    for(int i=0; i < q;i++){
        cin >> arr[i].fi >> arr[i].se;
        arr[i].fi--;
        arr[i].se--;
    }
    sort(arr, arr+q, comp);
    pll index[n];
    ll currind = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i = 0; i < n; i++){
        while(currind < q && arr[currind].fi <= i){
            pq.push(arr[currind].se);
            currind++;
        }
        while(pq.size()>0 && pq.top() < i){
            pq.pop();
        }
        index[i].fi = i;
        index[i].se = pq.size();
    }
    sort(index, index+n, comp2);
    sort(a, a+n, greater<ll>());
    ll ans[n], x = 0;
    for(int i = 0; i < n; i++){
        ans[index[i].fi] = a[i];
        x+=index[i].se*a[i];
    }
    cout << x << endl;
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
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