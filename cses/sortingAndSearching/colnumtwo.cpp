#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll, ll>

template <typename T>
void printArr(T *arr, ll size)
{
    cout << endl
         << endl;
    for (ll i = 0; i < size; i++)
    {
        cout << i+1 << ": " << arr[i] << endl;
    }
    cout << endl
         << endl;
}

bool comp(pair<pll, ll> p1, pair<pll, ll> p2)
{
    return p1.fi.fi < p2.fi.fi;
}
int main(int argc, char *argv[])
{
    ll n, m;
    cin >> n >> m;
    ll numatpos[n + 1], posofnum[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> numatpos[i];
        posofnum[numatpos[i]] = i;
    }
    ll ans = 1;
    for (int i = 2; i <= n; i++)
    {
        if (posofnum[i] < posofnum[i - 1])
        {
            ans++;
        }
    }

    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << ans << endl;
            continue;
        }
        if (a > b)
        {
            ll temp = a;
            a = b;
            b = temp;
        } // a is always less than b
        ll na = numatpos[a], nb = numatpos[b];
        // pos of na increases to b
        if (abs(na - nb) != 1)
        {
            if (na == 1)
            {
                if (posofnum[na + 1] < b && posofnum[na + 1] > a)
                {
                    ans++;
                }
            }
            else if (na == n)
            {
                if (posofnum[na - 1] < b && posofnum[na - 1] > a)
                {
                    ans--;
                }
            }
            else
            {
                if (posofnum[na - 1] < posofnum[na + 1])
                {
                    if (a < posofnum[na - 1] && b > posofnum[na - 1] && b < posofnum[na + 1])
                    {
                        ans--;
                    }
                    else if (a < posofnum[na + 1] && a > posofnum[na - 1] && b > posofnum[na + 1])
                    {
                        ans++;
                    }
                }
                else
                {
                    if (a < posofnum[na - 1] && b > posofnum[na - 1] && a > posofnum[na + 1])
                    {
                        ans--;
                    }
                    else if (a < posofnum[na + 1] && b < posofnum[na - 1] && b > posofnum[na + 1])
                    {
                        ans++;
                    }
                }
            }
            if (nb == 1)
            {
                if (posofnum[nb + 1] < b && posofnum[nb + 1] > a)
                {
                    ans--;
                }
            }
            else if (nb == n)
            {
                if (posofnum[nb - 1] < b && posofnum[nb - 1] > a)
                {
                    ans++;
                }
            }
            else
            {
                if (posofnum[nb - 1] < posofnum[nb + 1])
                {
                    if (a > posofnum[nb - 1] && a < posofnum[nb + 1] && b > posofnum[nb + 1])
                    {
                        ans--;
                    }
                    else if (b < posofnum[nb + 1] && b > posofnum[nb - 1] && a < posofnum[nb - 1])
                    {
                        ans++;
                    }
                }
                else
                {
                    if (a < posofnum[nb - 1] && b > posofnum[nb - 1] && a > posofnum[nb + 1])
                    {
                        ans++;
                    }
                    else if (a < posofnum[nb + 1] && b < posofnum[nb - 1] && b > posofnum[nb + 1])
                    {
                        ans--;
                    }
                }
            }
        }
        else
        {

            if (na == nb + 1)
            {
                if (na == n)
                {
                    if (posofnum[nb - 1] < a || posofnum[nb - 1] > b)
                    {
                        ans--;
                    }
                }
                else if (nb == 1)
                {
                    if (posofnum[na + 1] > b || posofnum[na + 1] < a)
                    {
                        ans--;
                    }
                }
                else
                {
                    if (posofnum[nb - 1] > a && posofnum[nb - 1] < b && posofnum[na + 1] > a && posofnum[na + 1] < b)
                    {
                        ans++;
                    }
                    else if ((posofnum[na + 1] < a || posofnum[na + 1] > b) && (posofnum[nb - 1] < a || posofnum[nb - 1] > b))
                    {
                        ans--;
                    }
                }
            }
            else
            {
                if (na == 1)
                {
                    if (posofnum[nb + 1] < a || posofnum[nb + 1] > b)
                    {
                        ans++;
                    }
                }
                else if (nb == n)
                {
                    if (posofnum[na - 1] > b || posofnum[na - 1] < a)
                    {
                        ans++;
                    }
                }
                else
                {
                    if (posofnum[na - 1] > a && posofnum[na - 1] < b && posofnum[nb + 1] > a && posofnum[nb + 1] < b)
                    {
                        ans--;
                    }
                    else if ((posofnum[nb + 1] < a || posofnum[nb + 1] > b) && (posofnum[na - 1] < a || posofnum[na - 1] > b))
                    {
                        ans++;
                    }
                }
            }
        }

        ll temp = numatpos[a];
        numatpos[a] = numatpos[b];
        numatpos[b] = temp;
        posofnum[numatpos[b]] = b;
        posofnum[numatpos[a]] = a;
        cout << ans << endl;
        // printArr<ll>(numatpos + 1, n);
        // printArr<ll>(posofnum + 1, n);
    }
}