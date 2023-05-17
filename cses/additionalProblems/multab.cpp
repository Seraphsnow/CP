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

pll range(ll n, ll elem)
{
    ll mymin = 0, mymax = 0;
    for (int i = n; i >= 1; i--)
    {
        if ((elem - 1) / i > n)
        {
            mymin += n * i;
            break;
        }
        else
        {
            mymin += (elem - 1) / i;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if ((elem) / i > n)
        {
            mymax += n * i;
            break;
        }
        else
        {
            mymax += (elem) / i;
        }
    }
    return {mymin + 1, mymax};
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll wanted = (n * n + 1) / 2;
    // cout << wanted << endl;
    ll max = (n/4 + 1)*(n - n/4);
    pll curr = range(n, max);
    if (curr.fi <= wanted)
    {
        cout << max << endl;
    }
    else
    {
        ll min = max / 2;
        // cout << min << " " << range(n, min).fi << " " << range(n, min).se << endl;
        while (true)
        {
            ll mid = (min + max) / 2;
            // cout << mid << " " << range(n, mid).fi << " " << range(n, mid).se << endl;

            pll curr = range(n, mid);
            if (wanted > curr.se)
            {
                min = mid;
            }
            else if (wanted < curr.fi)
            {
                max = mid;
            }
            else
            {
                cout << mid << endl;
                break;
            }
        }
    }
}