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
    for (ll i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    if (n % 2)
    { // n is odd
        ll myarr[2][n];
        for (int i = 0; i <= (n - 1) / 2; i++)
        {
            myarr[0][2 * i] = arr[i];
        }
        for (int i = 0; i <= (n - 3) / 2; i++)
        {
            myarr[0][2 * i + 1] = arr[(n + 1) / 2 + i];
        }

        for (int i = 0; i <= (n - 3) / 2; i++)
        {
            myarr[1][2 * i + 1] = arr[i];
        }
        for (int i = 0; i <= (n - 1) / 2; i++)
        {
            myarr[1][2 * i] = arr[(n - 1) / 2 + i];
        }

        bool allowed = true;
        for (int i = 2; i < n; i++)
        {
            if ((myarr[0][i - 2] >= myarr[0][i - 1] && myarr[0][i - 1] >= myarr[0][i]) || (myarr[0][i - 2] <= myarr[0][i - 1] && myarr[0][i - 1] <= myarr[0][i]))
            {
                allowed = false;
                break;
            }
        }
        if (allowed)
        {
            printArr(myarr[0], n);
            return;
        }
        allowed = true;
        for (int i = 2; i < n; i++)
        {
            if ((myarr[1][i - 2] >= myarr[1][i - 1] && myarr[1][i - 1] >= myarr[1][i]) || (myarr[1][i - 2] <= myarr[1][i - 1] && myarr[1][i - 1] <= myarr[1][i]))
            {
                allowed = false;
                break;
            }
        }
        if (allowed)
        {
            printArr(myarr[1], n);
            return;
        }
        cout << -1 << endl;
        return;
    }
    else
    { // n is even
        ll myarr[2][n];
        for (int i = 0; i < n / 2; i++)
        {
            myarr[0][2 * i] = arr[i];
            myarr[0][2 * i + 1] = arr[n / 2 + i];
            myarr[1][2 * i] = arr[n / 2 + i];
            myarr[1][2 * i + 1] = arr[i];
        }
        bool allowed = true;
        for (int i = 2; i < n; i++)
        {
            if ((myarr[0][i - 2] >= myarr[0][i - 1] && myarr[0][i - 1] >= myarr[0][i]) || (myarr[0][i - 2] <= myarr[0][i - 1] && myarr[0][i - 1] <= myarr[0][i]))
            {
                allowed = false;
                break;
            }
        }
        if (allowed)
        {
            printArr(myarr[0], n);
            return;
        }
        allowed = true;
        for (int i = 2; i < n; i++)
        {
            if ((myarr[1][i - 2] >= myarr[1][i - 1] && myarr[1][i - 1] >= myarr[1][i]) || (myarr[1][i - 2] <= myarr[1][i - 1] && myarr[1][i - 1] <= myarr[1][i]))
            {
                allowed = false;
                break;
            }
        }
        if (allowed)
        {
            printArr(myarr[1], n);
            return;
        }
        cout << -1 << endl;
        return;
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