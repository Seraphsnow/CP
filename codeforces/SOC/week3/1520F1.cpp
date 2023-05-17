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

void solve(ll n)
{
    ll k;
    cin >> k;
    ll possmin = 1, possmax = n;
    ll tillnow = 0;
    for (int i = 0; i < 20; i++)
    {
        ll mid = (possmin + possmax) / 2;
        cout << "? " << possmin << " " << mid << endl;
        cout.flush();
        ll ans;
        cin >> ans;
        if (tillnow + (mid-possmin+1-ans) >= k)
        {
            possmax = mid;
        }
        else{
            tillnow+= mid-possmin+1-ans;
            possmin = mid+1;
        }
        if(possmin == possmax){
            cout << "! " << possmin << endl;
            cout.flush();
            return;
        }
    }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, n;
    cin >> n >> t;
    while (t--)
    {
        solve(n);
    }
}