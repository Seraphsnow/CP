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
    ll k;
    cin >> k;
    ll teams = 1;
    for (int i = 0; i < k; i++)
    {
        teams = teams * 2;
    }
    ll arr[teams + 1];
    ll seeds[teams+1];
    for(int i = 0; i <= teams; i++){
        arr[i]=-1;
    }
    for (int i = 0; i < teams; i++)
    {
        ll num;
        cin >> num;
        seeds[i+1] = num;
        if (num != -1)
        {
            arr[num] = i + 1;
        }
    }
    ll ans = 1;
    ll div =2;
    ll modinv = 499122177;
    ll start = 1;
    for (int j = 0; j < k; j++)
    {
        // cout << teams << endl;
        // cout << div << endl;
        // cout << ans << endl;
        bool arr2[teams/2];
        for(int i = 0; i < teams/2; i++){
            arr2[i] = 0;
        }
        ll count = 0, count2 = 0;
        for (int i = teams; i > teams/2; i--)
        {
            if(arr[i]!=-1){
                if(arr2[(arr[i]-1)/div] == 1){
                    cout << 0 << endl;
                    return 0;
                }
                else{
                    arr2[(arr[i]-1)/div] = 1;
                }
                
            }
            else{
                count++;

            }
        }

        //cout << count << endl;
        for(int i = 1; i<=count;i++){
            ans = (ans * i) % MOD;
        }
        for(int i = 0; i < teams/2; i++){
            if(!arr2[i]){
                ll c = 0;
                bool done = false;
                for(int k = 0; k < div; k++){
                    if(seeds[i*div+k+1] == -1){
                        c++;
                        if(!done){
                            seeds[i*div+k+1] = teams -i;
                            done = true;
                        }
                    }
                }
                ans = (ans * c) % MOD;
            }
        }
        teams = teams/2;
        div = div*2;
        start = (start*modinv) % MOD;
    }
    cout << ans << endl;
    
}