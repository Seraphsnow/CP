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

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    string s1 = s.substr(0, n), s2 = s.substr(n, n);
    if (s1 != s2)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    ll first1 = -1, first0 = -1;
    if (s[n - 1] == '0')
    {
        for (int i = 0; i < n; i++)
        {
            if (s2[i] == '1')
            {
                first1 = n + i;
                break;
            }
        }
        if (first1 != -1)
        {
            for (int i = 1; i < n; i++)
            {
                cout << i << " ";
            }
            cout << first1 + 1 << " " << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (s2[i] == '0')
            {
                first0 = n + i;
                break;
            }
        }
        if (first0 != -1)
        {
            for (int i = 1; i < n; i++)
            {
                cout << i << " ";
            }
            cout << first0 + 1 << " " << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
}

int main(int argc, char *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}