#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll, ll>
#define MOD 1000000007
int main(int argc, char *argv[])
{

    ll n;
    cin >> n;
    pll** arr1 = new pll*[n];
    for(int i = 0; i < n; i++){
        arr1[i] = new pll[n];
    }

    //cout << "hi" << endl;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            char mychar;
            cin >> mychar;
            if (mychar == '*')
            {
                arr1[i][j].se = 0;
            }
            else
            {
                arr1[i][j].se = 1;
            }
        }
    }

    if (arr1[0][0].se)
        arr1[0][0].fi = 1;
    else
        arr1[0][0].fi = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                continue;
            arr1[i][j].fi = 0;
            if (!arr1[i][j].se)
                continue;
            if (j >= 1 && arr1[i][j - 1].se)
            {
                arr1[i][j].fi += arr1[i][j - 1].fi;
            }
            if (i >= 1 && arr1[i - 1][j].se)
            {
                arr1[i][j].fi += arr1[i - 1][j].fi;
            }
            arr1[i][j].fi = arr1[i][j].fi % MOD;
            //cout << arr1[i][j].fi << " " << i << " " << j << endl;
        }
    }
    cout << arr1[n - 1][n - 1].fi << endl;
}