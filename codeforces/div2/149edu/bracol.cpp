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

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<pll,bool>> seqs;
    ll count = 0;
    bool t1 = false, t2 = false;
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            count++;
        }
        else{
            count--;
        }
        if(count == 0){
            if(s[i] == ')'){
                if(seqs.size()== 0){
                    seqs.pb({{1,i+1},1});
                }
                else{
                    seqs.pb({{seqs.back().fi.se+1,i+1},1});
                }
                t1 = true;
            }
            else{
                if(seqs.size()== 0){
                    seqs.pb({{1,i+1},0});
                }
                else{
                    seqs.pb({{seqs.back().fi.se+1,i+1},0});
                }
                t2 = true;
            }
        }
    }
    if(count != 0){
        cout << -1 << endl;
        return;
    }
    if(t1 && t2){
        cout << 2 << endl;
        for(int i = 0; i < seqs.size(); i++){
            for(int j = seqs[i].fi.fi; j<=seqs[i].fi.se; j++){
                if(seqs[i].se){
                    cout << 1 << " ";
                }
                else{
                    cout << 2 << " ";
                }
            }
        }
    }
    else{
        cout << 1 << endl;
        for(int i = 0; i < n; i++){
            cout << 1 << " ";
        }
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