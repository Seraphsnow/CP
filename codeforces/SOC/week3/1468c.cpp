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
    ll n;
    cin >> n;
    ll min = 1, max = n;
    cout << "? " << min << " " << max << endl;
    cout.flush();
    ll m2;
    cin >> m2;
    bool c1 = false, c2 = false;
    while (true)
    {
        if (max == min)
        {
            cout << "! " << max << endl;
            return 0;
        }
        if (max == min + 1)
        {
            cout << "! " << max + min - m2 << endl;
            return 0;
        }
        ll mid = (min + max) / 2;
        if (m2 > mid)
        {
            cout << "? " << mid << " " << max << endl;
            ll newm2;
            cin >> newm2;
            if (newm2 == m2)
            {
                min = mid;
                m2 = newm2;
            }
            else
            {

                max = mid - 1;
                c1 = true;
                break;
                // if (min == max)
                // {
                //     cout << "! " << max << endl;
                //     return 0;
                // }
                // cout << "? " << min << " " << max << endl;
                // cin >> m2;
            }
        }
        else
        {
            cout << "? " << min << " " << mid << endl;
            ll newm2;
            cin >> newm2;
            if (newm2 == m2)
            {
                max = mid;
                m2 = newm2;
            }
            else
            {
                min = mid + 1;
                c2 = true;
                break;
                // if (min == max)
                // {
                //     cout << "! " << max << endl;
                //     return 0;
                // }
                // cout << "? " << min << " " << max << endl;
                // cin >> m2;
            }
        }
    }
    if (c1) // m2 is greater than max
    {
        while (true)
        {
            if (max == min)
            {
                cout << "! " << max << endl;
                return 0;
            }
            if (max == min + 1)
            {
                cout << "? " << min << " " << max << endl;
                ll m;
                cin >> m;
                cout << "! " << max + min - m << endl;
                return 0;
            }

            ll mid = (min + max) / 2;
            cout << "? " << mid << " " << m2 << endl;
            ll newm2;
            cin >> newm2;
            if (newm2 == m2)
            {
                min = mid;
            }
            else
            {

                max = mid - 1;
            }
        }
    }
    if (c2) // m2 is less than min
    {
        while (true)
        {
            if (max == min)
            {
                cout << "! " << max << endl;
                return 0;
            }
            if (max == min + 1)
            {
                cout << "? " << min << " " << max << endl;
                ll m;
                cin >> m;
                cout << "! " << max + min - m << endl;
                return 0;
            }

            ll mid = (min + max) / 2;
            cout << "? " << m2 << " " << mid << endl;
            ll newm2;
            cin >> newm2;
            if (newm2 == m2)
            {
                max = mid;
                m2 = newm2;
            }
            else
            {
                min = mid + 1;
            }
        }
    }
}