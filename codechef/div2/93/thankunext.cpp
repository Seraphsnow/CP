#include <bits/stdc++.h>
using namespace std;

// For policy data structures
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;

//#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

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
T min3(T a, T b, T c){
    return min<T>(a,min<T>(b,c));
}

template <typename T>
T min4(T a, T b, T c, T d){
    return min<T>(min<T>(a,d),min<T>(b,c));
}

template <typename T>
T max3(T a, T b, T c){
    return max<T>(a,max<T>(b,c));
}

template <typename T>
T max4(T a, T b, T c, T d){
    return max<T>(max<T>(a,d),max<T>(b,c));
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

class comparator{
    public:
        bool operator()(pll p1, pll p2){
            return p1.se < p2.se;
        }
};

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    pll nodes[k];
    bool done[n];
    ll currmax[n];
    priority_queue<pll, vector<pll>, comparator> mails;
    for(int i = 0; i <n; i++){
        done[i] = 0;
        currmax[i] = 0;
    }
    vector<ll> adj[n];
    for(int i = 0; i < k; i++){
        cin >> nodes[i].fi;
        nodes[i].fi--;
    }
    for(int i = 0; i < k; i++){
        cin >>nodes[i].se;
        mails.push(nodes[i]);
        currmax[nodes[i].fi] = nodes[i].se;
    }
    for(int i = 0; i < m; i++){
        ll u,v;
        cin >> u >> v;
        adj[u-1].pb(v-1);
        adj[v-1].pb(u-1);
    }

    bool left = true;

    while(left){
        pll top = mails.top();
        //cout << top.se << endl;
        mails.pop();
        done[top.fi] = 1;
        for(int i = 0; i < adj[top.fi].size(); i++){
            ll ind = adj[top.fi][i];
            if(!done[ind] && top.se-1 > currmax[ind]){
                mails.push({ind, top.se-1});
                currmax[ind] = top.se-1;
            }
        }
        left = false;
        while(mails.size()){
            pll front = mails.top();
            if(done[front.fi] || front.se < 1){
                mails.pop();
            }
            else{
                left = true;
                break;
            }
        }
    }
    ll poss = true;
    for(int i = 0; i < n; i++){
        if(!done[i]){
            poss = false;
            break;
        }
    }
    if(poss){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
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