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
    ll n, m, q;
    cin >> n >> m >> q;
    ll **distances;
    distances = new ll *[n];
    vector<pll> *adj;
    adj = new vector<pll>[n];
    // vector<pll> *un;
    // un = new vector<pll>[n];
    ll **un;
    un = new ll *[n];

    ll i, j, k;
    for (i = 0; i < n; i++)
    {

        distances[i] = new ll[n];
        un[i] = new ll[n];
        for (ll j = 0; j < n; j++)
        {
            distances[i][j] = LONG_LONG_MAX;
            un[i][j] = LONG_LONG_MAX;
        }
        distances[i][i] = 0;
    }

    for (i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        un[a - 1][b - 1] = min<ll>(un[a - 1][b - 1], c);
        un[b - 1][a - 1] = min<ll>(un[b - 1][a - 1], c);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (un[i][j] != LONG_LONG_MAX)
            {
                adj[i].pb({j, un[i][j]});
            }
        }
    }
    ll distances1[n];
    bool done[n];
    ll currnode;
    ll count;
    ll dis;
    ll minind, minDis;
    for (i = 0; i < n; i++)
    {
        priority_queue<pll, vector<pll>, comparator> dist;
        //vector<ll> alddone;
        for (j = 0; j < n; j++)
        {
            done[j] = 0;
            distances1[j] = min<ll>(distances[j][i],distances[i][j]);
            dist.push({distances1[j], j});
        }
        currnode = i;
        count = 1;
        done[i] = 1;
        // alddone.pb(i);
        // for(j = 0; j< alddone.size(); j++){
        //     dist.push({distances1[j], j});
        // }
        while (dist.size())
        {
            dis = distances1[currnode];
            if (dis != LONG_LONG_MAX)
            {

                for (k = 0; k < adj[currnode].size(); k++)
                {
                    pll ind = adj[currnode][k];

                    if (!done[ind.fi] && distances1[ind.fi] > dis + ind.se)
                    {
                        distances1[ind.fi] = dis + ind.se;
                        dist.push({distances1[ind.fi], ind.fi});
                    }
                }
            }

            // minind = -1;
            // minDis = LONG_LONG_MAX;
            // for (k = 0; k < n; k++)
            // {
            //     if (!done[k])
            //     {
            //         if (distances1[k] <= minDis)
            //         {
            //             minDis = distances1[k];
            //             minind = k;
            //         }
            //     }
            // }
            // done[minind] = 1;
            // currnode = minind;

            while(dist.size()){
                currnode = dist.top().se;
                if(!done[currnode]){
                    done[currnode] = 1;
                    dist.pop();
                    break;
                }
                dist.pop();
            }
            count++;
        }
        for (j = 0; j < n; j++)
        {
            distances[j][i] = distances1[j];
            //distances[i][j] = distances1[j];
        }
        // for(j = 0; j < n; j++){
        //     cout << distances[j][i] << " ";
        // }
        // cout << endl;
    }

    for (i = 0; i < q; i++)
    {
        ll a, b;
        cin >> a >> b;
        if (distances[a - 1][b - 1] == LONG_LONG_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << distances[a - 1][b - 1] << endl;
        }
    }
}