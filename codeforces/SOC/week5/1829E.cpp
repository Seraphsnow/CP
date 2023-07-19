#include <bits/stdc++.h>
using namespace std;
 
// For policy data structures
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
 
// using namespace __gnu_pbds;
 
// #define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
 
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
 
template <typename T>
T min3(T a, T b, T c)
{
    return min<T>(a, min<T>(b, c));
}
 
template <typename T>
T min4(T a, T b, T c, T d)
{
    return min<T>(min<T>(a, d), min<T>(b, c));
}
 
template <typename T>
T max3(T a, T b, T c)
{
    return max<T>(a, max<T>(b, c));
}
 
template <typename T>
T max4(T a, T b, T c, T d)
{
    return max<T>(max<T>(a, d), max<T>(b, c));
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
    ll n, m;
    cin >> n >> m;
    ll **arr;
    arr = new ll *[n];
    bool **visited;
    visited = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new ll[m];
        visited[i] = new bool[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            visited[i][j] = (arr[i][j] == 0);
        }
    }
    if (n == 1)
    {
        ll ans = 0, currsum = 0;
        for (int i = 0; i < m; i++)
        {
            if (arr[0][i] > 0)
            {
                currsum += arr[0][i];
            }
            else
            {
                currsum = 0;
            }
            ans = max<ll>(ans, currsum);
        }
        cout << ans << endl;
        return;
    }
    if (m == 1)
    {
        ll ans = 0, currsum = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i][0] > 0)
            {
                currsum += arr[i][0];
            }
            else
            {
                currsum = 0;
            }
            ans = max<ll>(ans, currsum);
        }
        cout << ans << endl;
        return;
    }
    ll i = 0, j = 0;
    ll ans = 0;
    while (i != n && j != m)
    {
        if (!visited[i][j])
        {
            queue<pll> bfs;
            bfs.push({i, j});
            visited[i][j] = 1;
            ll currans = 0;
            while (bfs.size() > 0)
            {
                pll top = bfs.front();
                currans += arr[top.fi][top.se];
                if (top.fi == 0)
                {
                    if (top.se == 0)
                    {
                        if (!visited[top.fi + 1][top.se])
                        {
                            bfs.push({top.fi + 1, top.se});
                            visited[top.fi + 1][top.se] = 1;
                        }
                        if (!visited[top.fi][top.se + 1])
                        {
                            bfs.push({top.fi, top.se + 1});
                            visited[top.fi][top.se + 1] = 1;
                        }
                    }
                    else if (top.se == m - 1)
                    {
                        if (!visited[top.fi + 1][top.se])
                        {
                            bfs.push({top.fi + 1, top.se});
                            visited[top.fi + 1][top.se] = 1;
                        }
                        if (!visited[top.fi][top.se - 1])
                        {
                            bfs.push({top.fi, top.se - 1});
                            visited[top.fi][top.se - 1] = 1;
                        }
                    }
                    else
                    {
                        if (!visited[top.fi + 1][top.se])
                        {
                            bfs.push({top.fi + 1, top.se});
                            visited[top.fi + 1][top.se] = 1;
                        }
                        if (!visited[top.fi][top.se + 1])
                        {
                            bfs.push({top.fi, top.se + 1});
                            visited[top.fi][top.se + 1] = 1;
                        }
 
                        if (!visited[top.fi][top.se - 1])
                        {
                            bfs.push({top.fi, top.se - 1});
                            visited[top.fi][top.se - 1] = 1;
                        }
                    }
                }
                else if (top.fi == n - 1)
                {
                    if (top.se == 0)
                    {
                        if (!visited[top.fi - 1][top.se])
                        {
                            bfs.push({top.fi - 1, top.se});
                            visited[top.fi - 1][top.se] = 1;
                        }
                        if (!visited[top.fi][top.se + 1])
                        {
                            bfs.push({top.fi, top.se + 1});
                            visited[top.fi][top.se + 1] = 1;
                        }
                    }
                    else if (top.se == m - 1)
                    {
                        if (!visited[top.fi - 1][top.se])
                        {
                            bfs.push({top.fi - 1, top.se});
                            visited[top.fi - 1][top.se] = 1;
                        }
                        if (!visited[top.fi][top.se - 1])
                        {
                            bfs.push({top.fi, top.se - 1});
                            visited[top.fi][top.se - 1] = 1;
                        }
                    }
                    else
                    {
                        if (!visited[top.fi - 1][top.se])
                        {
                            bfs.push({top.fi - 1, top.se});
                            visited[top.fi - 1][top.se] = 1;
                        }
                        if (!visited[top.fi][top.se + 1])
                        {
                            bfs.push({top.fi, top.se + 1});
                            visited[top.fi][top.se + 1] = 1;
                        }
                        if (!visited[top.fi][top.se - 1])
                        {
                            bfs.push({top.fi, top.se - 1});
                            visited[top.fi][top.se - 1] = 1;
                        }
                    }
                }
                else
                {
                    if (top.se == 0)
                    {
                        if (!visited[top.fi - 1][top.se])
                        {
                            bfs.push({top.fi - 1, top.se});
                            visited[top.fi - 1][top.se] = 1;
                        }
 
                        if (!visited[top.fi][top.se + 1])
                        {
                            bfs.push({top.fi, top.se + 1});
                            visited[top.fi][top.se + 1] = 1;
                        }
 
                        if (!visited[top.fi + 1][top.se])
                        {
                            bfs.push({top.fi + 1, top.se});
                            visited[top.fi + 1][top.se] = 1;
                        }
                    }
                    else if (top.se == m - 1)
                    {
 
                        if (!visited[top.fi - 1][top.se])
                        {
                            bfs.push({top.fi - 1, top.se});
                            visited[top.fi - 1][top.se] = 1;
                        }
                        if (!visited[top.fi + 1][top.se])
                        {
                            bfs.push({top.fi + 1, top.se});
                            visited[top.fi + 1][top.se] = 1;
                        }
 
                        if (!visited[top.fi][top.se - 1])
                        {
                            bfs.push({top.fi, top.se - 1});
                            visited[top.fi][top.se - 1] = 1;
                        }
                    }
                    else
                    {
 
                        if (!visited[top.fi - 1][top.se])
                        {
                            bfs.push({top.fi - 1, top.se});
                            visited[top.fi - 1][top.se] = 1;
                        }
 
                        if (!visited[top.fi][top.se + 1])
                        {
                            bfs.push({top.fi, top.se + 1});
                            visited[top.fi][top.se + 1] = 1;
                        }
 
                        if (!visited[top.fi + 1][top.se])
                        {
                            bfs.push({top.fi + 1, top.se});
                            visited[top.fi + 1][top.se] = 1;
                        }
 
                        if (!visited[top.fi][top.se - 1])
                        {
                            bfs.push({top.fi, top.se - 1});
                            visited[top.fi][top.se - 1] = 1;
                        }
                    }
                }
                bfs.pop();
            }
            ans = max<ll>(ans, currans);
        }
        i++;
        if (i == n)
        {
            i = 0;
            j++;
        }
    }
    cout << ans << endl;
}
 
int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}