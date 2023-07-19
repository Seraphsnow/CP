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
    ll q;
    cin >> q;
    set<ll> s;
    s.insert(0);
    map<ll, ll> mm;
    for (int i = 0; i < q; i++)
    {
        char ins;
        cin >> ins;
        if (ins == '+')
        {
            ll num;
            cin >> num;
            s.insert(num);
            mm[num] = 2;
        }
        else
        {
            ll k;
            cin >> k;
            ll num = k;
            if (mm.find(k) != mm.end())
            {
                num = k * mm[k];
                // cout << endl;
                // cout << k << " " << mm[k] << endl;
                // cout << endl;
            }
            while (true)
            {
                if (s.find(num) == s.end())
                {
                    cout << num << endl;
                    mm[k] = num / k;
                    break;
                }
                else
                {
                    num += k;
                }
            }
        }
    }
}