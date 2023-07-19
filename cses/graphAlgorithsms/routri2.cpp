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

ll mypow(ll a, ll b, ll m)
{
    ll ans = 1, pow = a;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            ans = (ans * pow) % m;
        }
        pow = (pow * pow) % m;
        b = b / 2;
    }
    return ans;
}

ll modInverse(ll A, ll M)
{
    ll m0 = M;
    ll y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1)
    {
        // q is quotient
        ll q = A / M;
        ll t = M;

        // m is remainder now, process same as
        // Euclid's algo
        M = A % M, A = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
}

vector<ll> *adj;

bool dfs(bool *visited, ll currnode, ll *parents)
{
    visited[currnode] = true;
    for (int i = 0; i < adj[currnode].size(); i++)
    {
        cout << currnode << " " << i << endl;
        ll ind = adj[currnode][i];
        cout << ind << endl;
        if (!visited[ind])
        {
            parents[ind] = currnode;
            ll done = dfs(visited, ind, parents);
            if (done)
            {
                return done;
            }
        }
        else
        {
            ll curr = currnode;
            vector<ll> pars;

            while (parents[curr] != -1)
            {
                pars.pb(curr);
                if (parents[curr] == ind)
                {
                    return true;
                    cout << pars.size() + 2 << endl;
                    cout << ind + 1 << " ";
                    for (int j = 0; j < pars.size(); j++)
                    {
                        cout << pars[pars.size() - 1 - j] + 1 << " ";
                    }
                    cout << ind + 1 << endl;
                    return true;
                }
                else
                {
                    curr = parents[curr];
                }
            }
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    adj = new vector<ll>[n];
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a - 1].pb(b - 1);
    }
    bool visited[n];
    bool poss[n];
    ll parents[n];
    ll exited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        parents[i] = -1;
        exited[i] = 0;
        poss[i] = 1;
    }
    ll currnode = 0;
    bool done = false;
    while (currnode < n)
    {
        if (visited[currnode])
        {
            currnode++;
            continue;
        }
        stack<ll> dfs;
        dfs.push(currnode);
        while (dfs.size())
        {
            ll top = dfs.top();

            visited[top] = true;
            bool found = false;
            for (int i = 0; i < adj[top].size(); i++)
            {
                ll ind = adj[top][i];
                if (!visited[ind])
                {
                    parents[ind] = top;
                    dfs.push(ind);
                    found = true;
                    break;
                }
                else
                {
                    // if (poss)
                    // {
                    ll curr = top;
                    vector<ll> pars;
                    // cout << top << " " << ind << endl;
                    if (!exited[ind])
                    {
                        while (parents[curr] != -1)
                        {
                            pars.pb(curr);
                            if (parents[curr] == ind)
                            {
                                // return true;
                                cout << pars.size() + 2 << endl;
                                cout << ind + 1 << " ";
                                for (int j = 0; j < pars.size(); j++)
                                {
                                    cout << pars[pars.size() - 1 - j] + 1 << " ";
                                }
                                cout << ind + 1 << endl;
                                return 0;
                            }
                            else
                            {
                                curr = parents[curr];
                            }
                        }
                    }

                    // poss[ind] = 0;
                    // }
                }
            }
            if (found)
            {
                continue;
            }
            else
            {
                exited[dfs.top()] = 1;
                dfs.pop();
            }
        }
        currnode++;
    }
    cout << "IMPOSSIBLE" << endl;
}