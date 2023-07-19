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

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    if (n == 1)
    {
        char *elems;
        elems = new char[m];
        ll start, end;
        for (int i = 0; i < m; i++)
        {
            cin >> elems[i];
            if (elems[i] == 'A')
            {
                start = i;
            }
            if (elems[i] == 'B')
            {
                end = i;
            }
        }
        if (start < end)
        {

            for (int i = start + 1; i < end; i++)
            {
                if (elems[i] == '#')
                {
                    cout << "NO\n";
                    return 0;
                }
            }
            cout << "YES\n";
            cout << end - start << endl;
            string s = "";
            for (int i = 0; i < end - start; i++)
            {
                s = s + "R";
            }
            cout << s << endl;
            return 0;
        }
        else
        {
            for (int i = start + 1; i < end; i++)
            {
                if (elems[i] == '#')
                {
                    cout << "NO\n";
                    return 0;
                }
            }
            cout << "YES\n";
            cout << start - end << endl;
            string s = "";
            for (int i = 0; i < start - end; i++)
            {
                s = s + "L";
            }
            cout << s << endl;
            return 0;
        }
    }
    else if (m == 1)
    {
        char *elems;
        elems = new char[n];
        ll start, end;
        for (int i = 0; i < n; i++)
        {
            cin >> elems[i];
            if (elems[i] == 'A')
            {
                start = i;
            }
            if (elems[i] == 'B')
            {
                end = i;
            }
        }
        if (start < end)
        {

            for (int i = start + 1; i < end; i++)
            {
                if (elems[i] == '#')
                {
                    cout << "NO\n";
                    return 0;
                }
            }
            cout << "YES\n";
            cout << end - start << endl;
            string s = "";
            for (int i = 0; i < end - start; i++)
            {
                s = s + "D";
            }
            cout << s << endl;
            return 0;
        }
        else
        {
            for (int i = start + 1; i < end; i++)
            {
                if (elems[i] == '#')
                {
                    cout << "NO\n";
                    return 0;
                }
            }
            cout << "YES\n";
            cout << start - end << endl;
            string s = "";
            for (int i = 0; i < start - end; i++)
            {
                s = s + "U";
            }
            cout << s << endl;
            return 0;
        }
    }
    char **elems;
    pll **parents,** child;

    pll start, end;
    elems = new char *[n];
    parents = new pll *[n];
    child = new pll *[n];
    for (int i = 0; i < n; i++)
    {
        elems[i] = new char[m];
        parents[i] = new pll[m];
        child[i] = new pll[m];
        for (int j = 0; j < m; j++)
        {
            cin >> elems[i][j];
            parents[i][j] = {-1, -1};
            if (elems[i][j] == 'A')
            {
                start.fi = i;
                start.se = j;
                parents[i][j] = {-2, -2};
            }
            if (elems[i][j] == 'B')
            {
                end.fi = i;
                end.se = j;
                child[i][j] = {-2,-2};
            }
        }
    }
    queue<pll> bfs;
    bool poss = false;
    bfs.push(start);
    while (bfs.size() != 0)
    {

        pll top = bfs.front();
        //cout << top.fi << " " << top.se << endl;
        bfs.pop();
        if (top == end)
        {
            poss = true;
            break;
        }
        if (top.fi == 0)
        {
            if (top.se == 0)
            {
                if (elems[top.fi + 1][top.se] != '#' && parents[top.fi + 1][top.se].fi == -1)
                {
                    bfs.push({top.fi + 1, top.se});
                    parents[top.fi + 1][top.se] = top;
                }
                if (elems[top.fi][top.se + 1] != '#' && parents[top.fi][top.se + 1].fi == -1)
                {
                    bfs.push({top.fi, top.se + 1});
                    parents[top.fi][top.se + 1] = top;
                }
            }
            else if (top.se == m - 1)
            {
                if (elems[top.fi + 1][top.se] != '#' && parents[top.fi + 1][top.se].fi == -1)
                {
                    bfs.push({top.fi + 1, top.se});
                    parents[top.fi + 1][top.se] = top;
                }
                if (elems[top.fi][top.se - 1] != '#' && parents[top.fi][top.se - 1].fi == -1)
                {
                    bfs.push({top.fi, top.se - 1});
                    parents[top.fi][top.se - 1] = top;
                }
            }
            else
            {
                if (elems[top.fi + 1][top.se] != '#' && parents[top.fi + 1][top.se].fi == -1)
                {
                    bfs.push({top.fi + 1, top.se});
                    parents[top.fi + 1][top.se] = top;
                }
                if (elems[top.fi][top.se + 1] != '#' && parents[top.fi][top.se + 1].fi == -1)
                {
                    bfs.push({top.fi, top.se + 1});
                    parents[top.fi][top.se + 1] = top;
                }
                if (elems[top.fi][top.se - 1] != '#' && parents[top.fi][top.se - 1].fi == -1)
                {
                    bfs.push({top.fi, top.se - 1});
                    parents[top.fi][top.se - 1] = top;
                }
            }
        }
        else if (top.fi == n - 1)
        {
            if (top.se == 0)
            {
                if (elems[top.fi - 1][top.se] != '#' && parents[top.fi - 1][top.se].fi == -1)
                {
                    bfs.push({top.fi - 1, top.se});
                    parents[top.fi - 1][top.se] = top;
                }
                if (elems[top.fi][top.se + 1] != '#' && parents[top.fi][top.se + 1].fi == -1)
                {
                    bfs.push({top.fi, top.se + 1});
                    parents[top.fi][top.se + 1] = top;
                }
            }
            else if (top.se == m - 1)
            {
                if (elems[top.fi - 1][top.se] != '#' && parents[top.fi - 1][top.se].fi == -1)
                {
                    bfs.push({top.fi - 1, top.se});
                    parents[top.fi - 1][top.se] = top;
                }
                if (elems[top.fi][top.se - 1] != '#' && parents[top.fi][top.se - 1].fi == -1)
                {
                    bfs.push({top.fi, top.se - 1});
                    parents[top.fi][top.se - 1] = top;
                }
            }
            else
            {
                if (elems[top.fi - 1][top.se] != '#' && parents[top.fi - 1][top.se].fi == -1)
                {
                    bfs.push({top.fi - 1, top.se});
                    parents[top.fi - 1][top.se] = top;
                }
                if (elems[top.fi][top.se + 1] != '#' && parents[top.fi][top.se + 1].fi == -1)
                {
                    bfs.push({top.fi, top.se + 1});
                    parents[top.fi][top.se + 1] = top;
                }
                if (elems[top.fi][top.se - 1] != '#' && parents[top.fi][top.se - 1].fi == -1)
                {
                    bfs.push({top.fi, top.se - 1});
                    parents[top.fi][top.se - 1] = top;
                }
            }
        }
        else
        {
            if (top.se == 0)
            {
                if (elems[top.fi + 1][top.se] != '#' && parents[top.fi + 1][top.se].fi == -1)
                {
                    bfs.push({top.fi + 1, top.se});
                    parents[top.fi + 1][top.se] = top;
                }
                if (elems[top.fi][top.se + 1] != '#' && parents[top.fi][top.se + 1].fi == -1)
                {
                    bfs.push({top.fi, top.se + 1});
                    parents[top.fi][top.se + 1] = top;
                }
                if (elems[top.fi - 1][top.se] != '#' && parents[top.fi - 1][top.se].fi == -1)
                {
                    bfs.push({top.fi - 1, top.se});
                    parents[top.fi - 1][top.se] = top;
                }
            }
            else if (top.se == m - 1)
            {
                if (elems[top.fi + 1][top.se] != '#' && parents[top.fi + 1][top.se].fi == -1)
                {
                    bfs.push({top.fi + 1, top.se});
                    parents[top.fi + 1][top.se] = top;
                }
                if (elems[top.fi][top.se - 1] != '#' && parents[top.fi][top.se - 1].fi == -1)
                {
                    bfs.push({top.fi, top.se - 1});
                    parents[top.fi][top.se - 1] = top;
                }
                if (elems[top.fi - 1][top.se] != '#' && parents[top.fi - 1][top.se].fi == -1)
                {
                    bfs.push({top.fi - 1, top.se});
                    parents[top.fi - 1][top.se] = top;
                }
            }
            else
            {
                if (elems[top.fi + 1][top.se] != '#' && parents[top.fi + 1][top.se].fi == -1)
                {
                    bfs.push({top.fi + 1, top.se});
                    parents[top.fi + 1][top.se] = top;
                }
                if (elems[top.fi][top.se + 1] != '#' && parents[top.fi][top.se + 1].fi == -1)
                {
                    bfs.push({top.fi, top.se + 1});
                    parents[top.fi][top.se + 1] = top;
                }
                if (elems[top.fi][top.se - 1] != '#' && parents[top.fi][top.se - 1].fi == -1)
                {
                    bfs.push({top.fi, top.se - 1});
                    parents[top.fi][top.se - 1] = top;
                }
                if (elems[top.fi - 1][top.se] != '#' && parents[top.fi - 1][top.se].fi == -1)
                {
                    bfs.push({top.fi - 1, top.se});
                    parents[top.fi - 1][top.se] = top;
                }
            }
        }
    }
    //cout << poss << endl;
    string s = "";
    if (poss)
    {
        cout << "YES\n";
        pll curr = end;
        ll size = 0;
        while (true)
        {
            pll par = parents[curr.fi][curr.se];
            child[par.fi][par.se] = curr;
            curr = par;
            size++;
            if (curr == start)
            {
                break;
            }
            //cout << curr.fi << " " << curr.se << endl;
        }
        cout << size << endl;
        curr = start;
        while(true){
            pll chi = child[curr.fi][curr.se];
            if(chi.fi ==curr.fi+1){
                cout << "D";
            }
            else if(chi.fi == curr.fi-1){
                cout << "U";
            }
            else if(chi.se == curr.se+1){
                cout << "R";
            }
            else{
                cout << "L";
            }
            curr = chi;
            if(curr == end){
                break;
            }
        }
        cout << endl;
    }
    else
    {
        cout << "NO\n";
    }
}