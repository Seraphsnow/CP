#include <bits/stdc++.h>
#include <limits.h>
// For policy data structures
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;

using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll, ll>
#define ull unsigned long long

template <typename T>
void printArr(T *arr, ll n)
{
    cout << endl
         << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl
         << endl;
}

int main(int argc, char *argv[])
{
    ll n;
    cin >> n;
    ll arr[n];
    ll sum = 0, mymax = LONG_LONG_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        mymax = max(mymax, arr[i]);
    }
    if (sum > 2 * mymax)
    {
        cout << sum << endl;
    }
    else
    {
        cout << 2 * mymax << endl;
    }
}