#include <bits/stdc++.h>
using namespace std;

// For policy data structures
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<long long, long long>
#define ppll pair<pll, pll>

typedef tree<pll, null_type, less<pll>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

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
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    indexed_set s1;
    for (int i = 0; i < k; i++)
    {
        s1.insert({arr[i], i});
    }
    cout << (*s1.find_by_order((k - 1) / 2)).fi << " ";
    for (int i = k; i < n; i++)
    {
        s1.insert({arr[i], i});
        s1.erase({arr[i - k], i - k});
        cout << (*s1.find_by_order((k - 1) / 2)).fi << " ";
    }
    cout << endl;
}