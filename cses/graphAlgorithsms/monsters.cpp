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

class comparator
{
public:
    bool operator()(pair<pll, ll> p1, pair<pll, ll> p2)
    {
        return p1.se > p2.se;
    }
};

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    char **arr;
    ll **heights;
    ll **monsterlevel;
    bool **mdone;
    pll **parents;
    pll **child;
    vector<pll> monster;
    priority_queue<pair<pll, ll>, vector<pair<pll, ll>>, comparator> mqueue;
    pll start;

    arr = new char *[n];
    heights = new ll *[n];
    monsterlevel = new ll *[n];
    mdone = new bool *[n];
    parents = new pll *[n];
    child = new pll *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new char[m];
        heights[i] = new ll[m];
        monsterlevel[i] = new ll[m];
        mdone[i] = new bool[m];
        parents[i] = new pll[m];
        child[i] = new pll[m];
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            heights[i][j] = -1;
            monsterlevel[i][j] = LONG_LONG_MAX;
            mdone[i][j] = 0;
            if (arr[i][j] == 'A')
            {
                start = {i, j};
                heights[i][j] = 0;
            }
            if (arr[i][j] == 'M')
            {
                monster.pb({i, j});
                monsterlevel[i][j] = 0;
                mqueue.push({{i, j}, 0});
            }
            parents[i][j] = {-1, -1};
        }
    }
    if (n == 1)
    {
        bool poss = true;
        for (int i = 0; i < start.se; i++)
        {
            if (arr[0][i] == '#' || arr[0][i] == 'M')
            {
                poss = false;
                break;
            }
        }
        if (poss)
        {
            cout << "YES\n";
            for (int i = 0; i < start.se; i++)
            {
                cout << "L";
            }
            cout << endl;
            return 0;
        }
        poss = true;
        for (int i = start.se + 1; i < m; i++)
        {
            if (arr[0][i] == '#' || arr[0][i] == 'M')
            {
                poss = false;
                break;
            }
        }
        if (poss)
        {
            cout << "YES\n";
            for (int i = start.se + 1; i < m; i++)
            {
                cout << "R";
            }
            cout << endl;
            return 0;
        }
        cout << "NO\n";
        return 0;
    }
    if (m == 1)
    {
        bool poss = true;
        for (int i = 0; i < start.fi; i++)
        {
            if (arr[i][0] == '#' || arr[i][0] == 'M')
            {
                poss = false;
                break;
            }
        }
        if (poss)
        {
            cout << "YES\n";
            for (int i = 0; i < start.fi; i++)
            {
                cout << "U";
            }
            cout << endl;
            return 0;
        }
        poss = true;
        for (int i = start.fi + 1; i < n; i++)
        {
            if (arr[i][0] == '#' || arr[i][0] == 'M')
            {
                poss = false;
                break;
            }
        }
        if (poss)
        {
            cout << "YES\n";
            for (int i = start.fi + 1; i < n; i++)
            {
                cout << "D";
            }
            cout << endl;
            return 0;
        }
        cout << "NO\n";
        return 0;
    }

    while (mqueue.size())
    {
        pair<pll, ll> top = mqueue.top();
        //cout << top.fi.fi << " " << top.fi.se << " " << top.se << endl;
        mdone[top.fi.fi][top.fi.se] = 1;
        mqueue.pop();
        if (top.fi.fi < n - 1)
        {
            if (arr[top.fi.fi + 1][top.fi.se] != '#' && monsterlevel[top.fi.fi + 1][top.fi.se] > top.se + 1)
            {
                monsterlevel[top.fi.fi + 1][top.fi.se] = top.se + 1;
                mqueue.push({{top.fi.fi + 1, top.fi.se}, top.se + 1});
            }
        }
        if (top.fi.fi > 0)
        {
            if (arr[top.fi.fi - 1][top.fi.se] != '#' && monsterlevel[top.fi.fi - 1][top.fi.se] > top.se + 1)
            {
                monsterlevel[top.fi.fi - 1][top.fi.se] = top.se + 1;
                mqueue.push({{top.fi.fi - 1, top.fi.se}, top.se + 1});
            }
        }
        if (top.fi.se > 0)
        {
            if (arr[top.fi.fi][top.fi.se - 1] != '#' && monsterlevel[top.fi.fi][top.fi.se - 1] > top.se + 1)
            {
                monsterlevel[top.fi.fi][top.fi.se - 1] = top.se + 1;
                mqueue.push({{top.fi.fi, top.fi.se - 1}, top.se + 1});
            }
        }
        if (top.fi.se < m-1)
        {
            if (arr[top.fi.fi][top.fi.se + 1] != '#' && monsterlevel[top.fi.fi][top.fi.se + 1] > top.se + 1)
            {
                monsterlevel[top.fi.fi][top.fi.se + 1] = top.se + 1;
                mqueue.push({{top.fi.fi, top.fi.se + 1}, top.se + 1});
            }
        }
        while (mqueue.size())
        {
            pair<pll, ll> top = mqueue.top();
            if (mdone[top.fi.fi][top.fi.se])
            {
                mqueue.pop();
            }
            else
            {
                break;
            }
        }
    }

    queue<pll> bfs;
    bfs.push(start);
    while (bfs.size())
    {

        pll top = bfs.front();
        //cout << top.fi << " " << top.se << endl;
        bfs.pop();
        if (top.fi < n - 1)
        {
            if (arr[top.fi + 1][top.se] != '#' && heights[top.fi + 1][top.se] == -1)
            {
                heights[top.fi + 1][top.se] = heights[top.fi][top.se] + 1;
                parents[top.fi + 1][top.se] = {top.fi,top.se};
                bfs.push({top.fi + 1, top.se});
            }
        }
        if (top.fi > 0)
        {
            if (arr[top.fi - 1][top.se] != '#' && heights[top.fi - 1][top.se] == -1)
            {
                heights[top.fi - 1][top.se] = heights[top.fi][top.se] + 1;
                parents[top.fi - 1][top.se] = {top.fi,top.se};

                bfs.push({top.fi - 1, top.se});
            }
        }
        if (top.se > 0)
        {
            if (arr[top.fi ][top.se - 1] != '#' && heights[top.fi][top.se - 1] == -1)
            {
                heights[top.fi][top.se - 1] = heights[top.fi][top.se] + 1;
                parents[top.fi][top.se - 1] = {top.fi,top.se};

                bfs.push({top.fi, top.se - 1});
            }
        }
        if (top.se < m-1)
        {
            if (arr[top.fi][top.se + 1] != '#' && heights[top.fi][top.se + 1] == -1)
            {
                heights[top.fi][top.se + 1] = heights[top.fi][top.se] + 1;
                parents[top.fi][top.se + 1] = {top.fi,top.se};

                bfs.push({top.fi, top.se + 1});
            }
        }
    }

    bool poss = false;
    pll border;
    for (int i = 0; i < m; i++)
    {
        if (arr[0][i] != '#' && monsterlevel[0][i] > heights[0][i] && heights[0][i] != -1)
        {
            poss = true;
            border = {0, i};
            break;
        }
        if (arr[n - 1][i] != '#' && monsterlevel[n - 1][i] > heights[n - 1][i] && heights[n-1][i] != -1)
        {
            poss = true;
            border = {n - 1, i};
            break;
        }
    }

    if (!poss)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i][0] != '#' && monsterlevel[i][0] > heights[i][0] && heights[i][0] != -1)
            {
                poss = true;
                border = {i, 0};
                break;
            }
            if (arr[i][m - 1] != '#' && monsterlevel[i][m - 1] > heights[i][m - 1] && heights[i][m-1] != -1)
            {
                poss = true;
                border = {i, m - 1};
                break;
            }
        }
    }
    if (poss)
    {
        cout << "YES\n";
        cout << heights[border.fi][border.se] << endl;
        // cout << monsterlevel[border.fi][border.se] << endl;
        
        pll currelem = border;
        //cout << currelem.fi << " " << currelem.se << endl;

        while (true)
        {
            if (currelem == start)
            {
                break;
            }
            pll par = parents[currelem.fi][currelem.se];
            child[par.fi][par.se] = currelem;

            currelem = par;
        //cout << currelem.fi << " " << currelem.se << endl;
        }
        //cout << 1 << endl;

        currelem = start;
        while (true)
        {
            if(currelem == border) break;
            pll chi = child[currelem.fi][currelem.se];
            if (chi.fi == currelem.fi + 1)
            {
                cout << "D";
            }
            else if (chi.fi == currelem.fi - 1)
            {
                cout << "U";
            }
            else if (chi.se == currelem.se + 1)
            {
                cout << "R";
            }
            else
            {
                cout << "L";
            }
            currelem = chi;
        }
        cout << endl;
    }
    else
    {
        cout << "NO\n";
    }
}