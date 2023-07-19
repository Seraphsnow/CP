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

class comparator
{
public:
    bool operator()(pair<pll, ll> a, pair<pll, ll> b)
    {
        if (a.fi > b.fi)
        {
            return true;
        }
        return false;
    }
};

class comparator2
{
public:
    bool operator()(pll a, pll b)
    {
        if (a.fi > b.fi)
        {
            return true;
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<pll> un[n];
    vector<pll> adj[n];
    pll distances[n];
    ll distdirect[n];
    bool done[n], dirdone[n];
    for (int i = 0; i < n; i++)
    {
        distances[i] = {-1, -1};
        distdirect[i] = -1;
        done[i] = 0;
        dirdone[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        un[a - 1].pb({b - 1, c});
    }
    for (int i = 0; i < n; i++)
    {
        sort(un[i].begin(), un[i].end());
        if (un[i].size())
        {
            adj[i].pb(un[i][0]);
        }
        for (int j = 1; j < un[i].size(); j++)
        {
            if (un[i][j].fi == adj[i].back().fi)
            {
                adj[i].back().se = min<ll>(adj[i].back().se, un[i][j].se);
            }
            else
            {
                adj[i].pb(un[i][j]);
            }
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i + 1 << endl
    //          << endl;
    //     for (int j = 0; j < adj[i].size(); j++)
    //     {
    //         cout << adj[i][j].fi + 1 << " " << adj[i][j].se << endl;
    //     }
    //     cout << endl;
    // }
    distdirect[0] = 0;
    dirdone[0] = 1;
    priority_queue<pll, vector<pll>, comparator2> distdir;
    ll currnodedir = 0;
    ll countdir = 1;
    distdir.push({0,0});
    bool leftdir = true;
    while(leftdir){
        for(int i = 0; i < adj[currnodedir].size(); i++){
            pll ind = adj[currnodedir][i];
            if(!dirdone[ind.fi] && (distdirect[ind.fi] == -1 || distdirect[ind.fi] > distdirect[currnodedir] + ind.se)){
                distdirect[ind.fi] = distdirect[currnodedir] + ind.se;
                distdir.push({distdirect[ind.fi], ind.fi});
            }
        }
        leftdir = false;
        while(distdir.size()){
            currnodedir = distdir.top().se;
            if(!dirdone[currnodedir]){
                dirdone[currnodedir] = 1;
                distdir.pop();
                leftdir = true;
                break;
            }
            distdir.pop();
        }
        
    }

    distances[0] = {0, -1}; // fi contains cost, se contains max cost flight

    priority_queue<pair<pll, ll>, vector<pair<pll, ll>>, comparator> dist;
    ll currnode = 0;
    ll count = 1;

    done[0] = 1;
    dist.push({{0, -1}, 0});
    bool left = true;
    while (left)
    {
        // cout << currnode + 1 << endl;
        for (int i = 0; i < adj[currnode].size(); i++)
        {

            pll ind = adj[currnode][i];

            if (!done[ind.fi])
            {

                pll olddis = distances[ind.fi];
                pll route = distances[currnode];
                pll newdis;
                // if (ind.fi == 2)
                // {
                //     cout << olddis.fi << '  ' << olddis.se << endl;
                //     cout << route.fi << '  ' << route.se << endl;
                // }
                if (route.se == -1)
                {
                    newdis = {ind.se / 2, ind.se};
                }
                else
                {
                    if (route.se > ind.se)
                    {
                        newdis = {route.fi + ind.se, route.se};
                    }
                    else
                    {
                        if (distdirect[currnode] == -1)
                        {
                            newdis = {route.fi - (route.se / 2) + route.se + (ind.se / 2), ind.se};
                        }
                        else
                        {
                            newdis = {min<ll>(route.fi - (route.se / 2) + route.se, distdirect[currnode]) + (ind.se / 2), ind.se};
                        }
                    }
                }

                if (olddis.fi == -1 || olddis.fi > newdis.fi || (olddis.fi == newdis.fi && olddis.se > newdis.se))
                {
                    distances[ind.fi] = newdis;
                    dist.push({newdis, ind.fi});
                }
            }
        }
        left = false;
        while (dist.size())
        {
            currnode = dist.top().se;
            // cout << dist.top().fi.fi << " " << dist.top().fi.se << " " << dist.top().se + 1 << endl;
            if (!done[currnode])
            {
                done[currnode] = 1;
                dist.pop();
                left = true;
                break;
            }
            dist.pop();
        }
        count++;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " " << distances[i].fi << " " << distances[i].se << endl;
    // }
    cout << distances[n - 1].fi << endl;
}