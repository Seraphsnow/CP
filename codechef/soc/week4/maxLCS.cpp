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

ll match(ll** arr, string s1, string s2, ll l1, ll l2){
    if(arr[l1][l2]!=-1){
        return arr[l1][l2];
    }
    if(l1 == 0 || l2 == 0){
        arr[l1][l2] = 0;
        return 0;
    }
    if(s1[l1-1] == s2[l2-1]){
        arr[l1][l2] =  max<ll>(max<ll>(match(arr, s1, s2, l1-1, l2),match(arr, s1, s2, l1, l2-1)),1+match(arr, s1, s2, l1-1, l2-1));
        return arr[l1][l2];
    }
    else{
        arr[l1][l2] =  max<ll>(match(arr, s1, s2, l1-1, l2),match(arr, s1, s2, l1, l2-1));
        return arr[l1][l2];
    }
}

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    string s2 = "";
    for(int i = n-1; i >=0; i--){
        s2 = s2+s[i];
    }
    //cout << s2 << endl;
    ll** arr;
    arr = new ll* [n+1];
    for(int i = 0; i <=n; i++){
        arr[i] = new ll [n+1];
        for(int j = 0; j <=n; j++){
            arr[i][j] = -1;
        }
    }
    for(int i = 0; i <=n;i++){
        arr[i][0] =0;
        arr[0][i] = 0;
    }
    for(int i = 1; i <=n; i++){
        for(int j = 1; j<=n; j++){
            if(s[i-1] == s2[j-1]){
                arr[i][j] = max<ll>(max<ll>(arr[i][j-1], arr[i-1][j]),1+arr[i-1][j-1]);
            }
            else{
                arr[i][j] = max<ll>(arr[i][j-1], arr[i-1][j]);
            }
        }
    }
    cout << arr[n][n]/2 << endl;
    //ll max = match(arr, s,s2, n,n);
    //cout << max /2 << endl;
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