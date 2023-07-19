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
    return p1.fi > p2.fi;
}
void solve()
{
    ll n,s1,s2;
    cin >> n >> s1 >> s2;
    pll r[n];
    for(int i = 0; i <n; i++){
        cin >> r[i].fi;
        r[i].se = i+1;
    }
    sort(r, r+n, comp);
    vector<ll> a,b;
    ll ta =s1, tb = s2;
    for(int i = 0; i < n; i++){
        if(ta < tb){
            a.pb(r[i].se);
            ta+=s1;
        }
        else{
            b.pb(r[i].se);
            tb+=s2;
        }
    }
    cout << a.size() << " ";
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
    cout << b.size() << " ";
    for(int i = 0; i < b.size(); i++){
        cout << b[i] << " ";
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