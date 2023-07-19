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

bool poss(ll *arr, ll n, ll k, ll maxsum)
{
    ll sum = 0;
    ll left = k;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxsum)
        {
            return false;
        }
        if (sum + arr[i] <= maxsum)
        {
            sum += arr[i];
        }
        else
        {
            sum = arr[i];
            left--;
            if (left <= 0)
            {
                return false;
            }
        }
    }
    if (left >= 1)
    {
        return true;
    }
    else{
        return false;
    }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        ll num;
        cin >> arr[i];
    }
    ll max = 1;
    while (true)
    {
        if (poss(arr, n, k, max))
        {
            break;
        }
        else
        {
            max = max * 2;
        }
        //cout << max << endl;
    }
    ll min = max/2;
    while(true){
        if(min == max){
            cout << min << endl;
            return 0;
        }
        ll mid = (min+max)/2;
        if(poss(arr, n, k, mid)){
            max = mid;
        }
        else{
            min = mid+1;
        }
    }
}