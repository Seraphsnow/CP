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
    string s;
    cin >> n >> s;
    ll length = 1;
    char mychar = s[0];
    ll lengths[26][n + 1];
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            lengths[i][j] = 0;
        }
    }
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            length++;
        }
        else
        {
            for (int k = 0; k <= length; k++)
            {
                lengths[mychar - 97][k] += length + 1 - k;
            }
            length = 1;
            mychar = s[i];
        }
    }
    for (int k = 0; k <= length; k++)
    {
        lengths[mychar - 97][k] += length + 1 - k;
    }
    ll mymax[26];

    for (int j = 0; j < 26; j++)
    {
        mymax[j] = 0;
        for (int i = n; i >= 0; i--)
        {
            if (lengths[j][i] > 1)
            {
                mymax[j] = i;
                break;
            }
        }
    }
    ll max = 0;
    for (int i = 0; i < 26; i++)
    {
        if (mymax[i] > max)
        {
            max = mymax[i];
        }
    }
    cout << max << endl;
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