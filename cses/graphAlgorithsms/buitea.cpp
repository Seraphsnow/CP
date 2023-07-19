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

class node{
    public:
        node(){};
        ll index;
        ll height;
        vector<ll> adj;
        bool visited;
};

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    node nodes[n+1];
    for(int i = 1; i <=n; i++){
        nodes[i].index = i;
        nodes[i].visited = false;
    }
    for(int i= 0; i < m; i++){
        ll a, b;
        cin >> a >> b;
        nodes[a].adj.pb(b);
        nodes[b].adj.pb(a);
    }

    ll currind = 1;
    while(currind <= n){
        if(nodes[currind].visited){
            currind++;
            continue;
        }
        nodes[currind].height = 1;
        queue<ll> bfs;
        bfs.push(currind);
        nodes[currind].visited = true;
        while(bfs.size()){
            ll top = bfs.front();
            bfs.pop();
            for(int i = 0; i < nodes[top].adj.size(); i++){
                ll ind = nodes[top].adj[i];
                if(!nodes[ind].visited){
                    nodes[ind].visited = 1;
                    nodes[ind].height = nodes[top].height+1;
                    bfs.push(ind);
                }
                else{
                    if(ind!= top && nodes[ind].height == nodes[top].height){
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
                }   
            }
        }
    }
    for(int i = 1; i <=n; i++){
        if(nodes[i].height%2){
            cout << 1 << " ";
        }
        else{
            cout << 2 << " ";
        }
    }
    cout << endl;
}