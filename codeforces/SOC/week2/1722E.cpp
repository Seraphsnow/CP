#include <bits/stdc++.h>
using namespace std;

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

bool comp(pll p1, pll p2)
{
    return p1.fi < p2.fi || (p1.fi == p2.fi && p1.se < p2.se);
}

ll binsearch(vector<pll> v, ll elem){
    ll i1 = 0, i2 = v.size()-1;
    while(true){
        ll mid = (i1+i2)/2;
        if(v[mid].se < elem){
            i1 = mid+1;
        }
        else if(v[mid].se == elem){
            return mid;
        }
        else{
            i2 = mid-1;
        }
        if(i1 >= i2) return i1;
    }
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<pll> rects;
    for (int i = 0; i < n; i++)
    {
        pll p1;
        cin >> p1.fi >> p1.se;
        rects.pb(p1);
    }
    map<ll, vector<pll>> hw;
    vector<ll> heights;
    
    sort(rects.begin(), rects.end(), comp);
    for (int i = 0; i < n; i++)
    {
        if(hw.find(rects[i].fi) == hw.end()){
            heights.pb(rects[i].fi);
            hw[rects[i].fi].pb({0,0});
            hw[rects[i].fi].pb({rects[i].se, rects[i].se});
        }
        else{
            if(hw[rects[i].fi].back().se == rects[i].se){
                hw[rects[i].fi].back().fi +=rects[i].se;
            }
            else hw[rects[i].fi].pb({hw[rects[i].fi].back().fi + rects[i].se, rects[i].se});
        }
    }
    for(int i = 0; i < q; i++){
        ll ans = 0;
        ll hs,ws,hb,wb;
        cin >> hs >> ws >> hb >> wb;
        ll index1 = upper_bound(heights.begin(), heights.end(), hs)-heights.begin(),index2 = lower_bound(heights.begin(), heights.end(), hb)-heights.begin();
        //cout << index1 << " " << index2 << endl;
        for(int j = index1; j < index2; j++){
            vector<pll> v = hw[heights[j]];
            ll i1 = binsearch(v, ws),i2 = binsearch(v, wb) ;
            if(v[i1].se > ws){
                i1--;
            }
            if(v[i2].se >= wb){
                i2--;
            }
            ans += heights[j]*(v[i2].fi-v[i1].fi);
        }
        cout << ans << endl;
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