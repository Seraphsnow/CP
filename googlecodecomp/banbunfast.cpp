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
    if(b == 0) return a;
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

void solve(int index1)
{
    ll n, k;
    cin >> n >> k;
    ll arr[n + 1];
    ll sum = 0;
    arr[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll num;
        cin >> num;
        sum += num;
        arr[i] = sum;
    }

    ll ans = n+1;
    
    ll nums[k+1];
    for(ll i = 0; i <=k; i++){
        nums[i] = n+1;
    }
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= i; j++)
        {
            if (arr[i] - arr[j] == k)
            {
                ans = min(ans, i-j);
            }
            else if (arr[i] - arr[j] < k)
            {
                nums[arr[i]-arr[j]] = min(i-j, nums[arr[i]-arr[j]]);
            }
        }
        for(ll l = i+1; l <= n; l++){
            if(arr[l]-arr[i] < k){
                ans = min(l-i+ nums[k-arr[l]+arr[i]], ans);
            }
            else{
                break;
            }
        }
    }
    
    if (ans == n+1)
    {
        ans = -1;
    }
    cout << "Case #" << index1 << ": " << ans << endl;
}

int main(int argc, char *argv[])
{
    int t;
    cin >> t;
    int index = 1;
    while (t--)
    {
        solve(index);
        index++;
    }
}