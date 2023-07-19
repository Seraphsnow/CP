#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll, ll>

pll **a;
ll *num;

pll funa(ll i, ll j)
{
    if (i == j)
    {
        return {i, num[i]};
    }
    if (i == (j - 1))
    {
        if (num[i] > num[j])
        {
            return {i, num[i]};
        }
        else
        {
            return {j, num[j]};
        }
    }
    if (a[i][j].fi != -1)
    {
        return a[i][j];
    }
    pll p1 = funa(i + 1, j);
    pll p2 = funa(i, j - 1);
    if (p1.fi == (i + 1))
    {
        if (p2.fi == (i))
        {
            if ((num[i] + funa(i + 2, j).se) > (num[j] + funa(i + 1, j - 1).se))
            {
                a[i][j] = {i, num[i] + funa(i + 2, j).se};
                return a[i][j];
            }
            else
            {
                a[i][j] = {j, num[j] + funa(i + 1, j - 1).se};
                return a[i][j];
            }
        }
        else
        {
            if ((num[i] + funa(i + 2, j).se) > (num[j] + funa(i, j - 2).se))
            {
                a[i][j] = {i, num[i] + funa(i + 2, j).se};
                return a[i][j];
            }
            else
            {
                a[i][j] = {j, num[j] + funa(i, j - 2).se};
                return a[i][j];
            }
        }
    }
    else
    {
        if (p2.fi == (i))
        {
            if ((num[i] + funa(i + 1, j - 1).se) > (num[j] + funa(i + 1, j - 1).se))
            {
                a[i][j] = {i, num[i] + funa(i + 1, j-1).se};
                return a[i][j];
            }
            else
            {
                a[i][j] = {j, num[j] + funa(i + 1, j - 1).se};
                return a[i][j];
            }
        }
        else
        {
            if ((num[i] + funa(i + 1, j - 1).se) > (num[j] + funa(i, j - 2).se))
            {
                a[i][j] = {i, num[i] + funa(i + 1, j-1).se};
                return a[i][j];
            }
            else
            {
                a[i][j] = {j, num[j] + funa(i, j - 2).se};
                return a[i][j];
            }
        }
    }
}

pll funb(ll i, ll j)
{
}

int main(int argc, char *argv[])
{
    ll n;
    cin >> n;
    num = new ll[n];
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    a = new pll *[n];
    // b = new pll *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new pll[n];
        // b[i] = new pll[n];
        for (int j = 0; j < n; j++)
        {
            a[i][j] = {-1, -1};
            // b[i][j] = {-1, -1};
        }
    }
    cout << funa(0, n-1).se << endl;
}