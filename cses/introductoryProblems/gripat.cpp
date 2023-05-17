#include <bits/stdc++.h>
#include <limits.h>
// For policy data structures
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;

using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll, ll>
#define ppll pair<pll, pll>
#define ull unsigned long long

template <typename T>
void printArr(T *arr, ll n)
{
    cout << endl
         << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl
         << endl;
}

class my
{
public:
    ll left, right, down, up;
    bool arr[7][7];
    my()
    {
        // for (int i = 0; i < 7; i++)
        // {
        //     for (int j = 0; j < 7; j++)
        //     {
        //         arr[i][j] = 0;
        //     }
        // }
    }
    my(bool arr2[7][7])
    {
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                arr[i][j] = arr2[i][j];
            }
        }
    }
    bool set(ll l, ll r, ll d, ll u)
    {
        left = l;
        right = r;
        down = d;
        up = u;
        if (d > u + 6 || d < u || r > l + 6 || r < l || arr[right - left][down - up] || (l + r + d + u != 48 && r == l && d == u+6))
        {
            return false;
        }
        else
        {
            arr[right - left][down - up] = 1;
            return true;
        }
    }
};

int main(int argc, char *argv[])
{
    string inp;
    cin >> inp;
    queue<my *> paths; // up down left right
    my *zero;
    zero = new my();
    bool possible = zero->set(0, 0, 0, 0);
    paths.push(zero);
    for (int i = 0; i < inp.size(); i++)
    {
        ll num = paths.size();
        for (int j = 0; j < num; j++)
        {
            my *p = paths.front();
            if (inp[i] == '?' || inp[i] == 'D')
            {
                my *path;
                path = new my(p->arr);
                if (path->set(p->left, p->right, p->down + 1, p->up))
                {
                    paths.push(path);
                }
            }
            if (inp[i] == '?' || inp[i] == 'U')
            {
                my *path;
                path = new my(p->arr);
                if (path->set(p->left, p->right, p->down, p->up + 1))
                {
                    paths.push(path);
                }
            }
            if (inp[i] == '?' || inp[i] == 'L')
            {
                my *path;
                path = new my(p->arr);
                if (path->set(p->left + 1, p->right, p->down, p->up))
                {
                    paths.push(path);
                }
            }
            if (inp[i] == '?' || inp[i] == 'R')
            {
                my *path;
                path = new my(p->arr);
                if (path->set(p->left, p->right + 1, p->down, p->up))
                {
                    paths.push(path);
                }
            }
            paths.pop();
        }
        cout << paths.size() << endl;
    }
    cout << paths.size() << endl;
}