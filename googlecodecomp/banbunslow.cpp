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

void solve(ll index)
{
    ll n, k;
    cin >> n >> k;
    ll arr[n+1];
    ll sum = 0;
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        ll num;
        cin >> num;
        sum += num;
        arr[i] = sum;
    }

    ll ans = LONG_LONG_MAX;
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (arr[j] - arr[i] == k)
            {
                ans = min<ll>(ans, j - i);
                //cout << j << " "<< i << endl;
            }
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            for(int m = j+1; m <= n; m++){
                for(int l = m+1; l <= n; l++){
                    if(arr[j] - arr[i] + arr[l] - arr[m] == k){
                        ans = min<ll>(ans, j+l-i-m);
                        //cout << i << " " << j << " " << m << " " << l << endl;
                    }
                }
            }
        }
    }
    if(ans == LONG_LONG_MAX){
        ans = -1;
    }
    cout << "Case #" << index << ": " << ans << endl;
}

int main(int argc, char *argv[])
{
    ll t;
    cin >> t;
    ll index = 1;
    while (t--)
    {
        solve(index);
        index++;
    }
}