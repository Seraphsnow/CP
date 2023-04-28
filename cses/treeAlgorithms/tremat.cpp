#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll, ll>

class Node
{
public:
    ll num;
    vector<ll> adj;
    ll level;
    bool done;
    Node(ll val)
    {
        num = val;
        level = -1;
        done = 0;
    }
};

bool comp(pair<Node *, ll> p1, pair<Node *, ll> p2)
{
    return p2.fi->level > p2.fi->level;
}

int main(int argc, char *argv[])
{
    ll n;
    cin >> n;
    pair<Node *, ll> nodes[n];
    for (int i = 0; i < n; i++)
    {
        nodes[i].fi = new Node(i);
        nodes[i].se = 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        nodes[a - 1].fi->adj.pb(b - 1);
        nodes[b - 1].fi->adj.pb(a - 1);
    }
    nodes[0].fi->level = 0;
    queue<ll> bfs;
    ll arr[n];
    ll index = n - 1;
    bfs.push(0);
    while (bfs.size() != 0)
    {
        ll node = bfs.front();
        arr[index] = node;
        for (int i = 0; i < nodes[node].fi->adj.size(); i++)
        {
            if (nodes[nodes[node].fi->adj[i]].fi->level == -1)
            {
                nodes[nodes[node].fi->adj[i]].fi->level = nodes[node].fi->level + 1;
                bfs.push(nodes[node].fi->adj[i]);
            }
        }
        index--;
        bfs.pop();
    }

    ll num = 0;
    for (int i = 0; i < n; i++)
    {
        Node *mynode = nodes[arr[i]].fi;
        if(mynode->done) continue;
        for (int j = 0; j < mynode->adj.size(); j++)
        {
            if (nodes[mynode->adj[j]].fi->done == 0)
            {
                mynode->done = 1;
                nodes[mynode->adj[j]].fi->done = 1;
                num++;
                break;
            }
        }
    }
    cout << num << endl;
}