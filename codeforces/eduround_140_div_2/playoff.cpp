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

int main(int argc, char *argv[])
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ones = 0, zeros = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            ones++;
        }
        else
        {
            zeros++;
        }
    }
    if (ones == n)
    {
        ll win = pow(2, n);
        cout << win << endl;
    }
    else
    {
        ll min = pow(2,ones);
        for (ll i = min; i < 2 * min; i++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}