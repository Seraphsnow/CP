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

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin >> n >> k;
    map<ll,ll> s;
    ll unique = 0, numelem= 0;
    ll ans = 0;
    ll arr[n], minind = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        if(s.find(arr[i])!=s.end()){
            s[arr[i]]++;
            numelem++;
            ans += numelem;
            continue;
        }

        if(unique < k){
            s[arr[i]] = 1;
            unique++;
            numelem++;
        }
        else{
            while(unique == k){
                if(s[arr[minind]] != 1){
                    s[arr[minind]]--;
                    numelem--;
                    minind++;
                }
                else{
                    s.erase(arr[minind]);
                    numelem--;
                    minind++;
                    unique--;
                }
            }
            s[arr[i]]=1;
            unique++;
            numelem++;
        }
        ans+=numelem;
    }
    cout << ans << endl;
}