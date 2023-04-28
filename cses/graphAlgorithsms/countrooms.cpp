#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll, ll>

void dfs(bool **arr, ll n, ll m, ll i, ll j)
{
    arr[i][j] = false;
    if (i < n - 1 && arr[i + 1][j])
    {
        dfs(arr, n, m, i + 1, j);
    }
    if (j < m - 1 && arr[i][j + 1])
    {
        dfs(arr, n, m, i, j+1);
    }
    if (i >  0 && arr[i - 1][j])
    {
        dfs(arr, n, m, i - 1, j);
    }
    if (j >  0 && arr[i][j +-1])
    {
        dfs(arr, n, m, i, j - 1);
    }
    return;
}

int main(int argc, char *argv[])
{
    ll n, m;
    cin >> n >> m;
    bool **arr;
    arr = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new bool[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char my;
            cin >> my;
            if (my == '#')
            {
                arr[i][j] = false;
            }
            else
            {
                arr[i][j] = true;
            }
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {

    //         if (arr[i][j])
    //         {
    //             cout << ".";
    //         }
    //         else
    //         {
    //             cout << "#";
    //         }
    //     }
    //     cout << endl;
    // }
    ll rooms = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!arr[i][j])
                continue;
            // bfs
            dfs(arr, n, m, i, j);
            rooms++;
        }
    }
    cout << rooms << endl;
}