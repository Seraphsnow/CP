#include <bits/stdc++.h>
using namespace std;

// For policy data structures
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;

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
    ll n;
    cin >> n;
    ll neighbor[n];
    for (int i = 0; i < n; i++)
    {
        cin >> neighbor[i];
        neighbor[i]--;
    }

    bool visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    ll lines = 0, circles = 0, index = 0;
    while (index < n)
    {
        ll currindex;
        if (!visited[index])
        {
            currindex = index;
        }
        else
        {
            index++;
            continue;
        }
        ll origindex = currindex;
        visited[origindex] = true;
        while (true)
        {
            ll prev = currindex;
            currindex = neighbor[currindex];
            visited[currindex] = 1;
                
            if (!visited[neighbor[currindex]])
            {
                continue;
            }
            else{
                if(neighbor[currindex] == prev){
                    lines++;
                }
                else if(neighbor[currindex] == origindex){
                    circles++;
                }
                break;
            }
        }
    }
    // bool visited[n];
    // bool start[n];
    // ll final[n];
    // for (int i = 0; i < n; i++)
    // {
    //     visited[i] = false;
    //     start[i] = false;
    //     final[i] = -1;
    // }
    // ll index = 0, lines = 0, circles = 0;
    // while (index < n)
    // {
    //     ll currindex;
    //     if (visited[index] == 0)
    //     {
    //         currindex = index;
    //     }
    //     else
    //     {
    //         index++;
    //         continue;
    //     }
    //     visited[currindex] = true;
    //     start[currindex] = true;
    //     ll origindex = currindex;
    //     while (true)
    //     {
    //         if (visited[neighbor[currindex]] == 0)
    //         {
    //             currindex = neighbor[currindex];
    //             visited[currindex] = true;
    //         }
    //         else
    //         {
    //             if (neighbor[neighbor[currindex]] == currindex)
    //             {
    //                 final[origindex] = currindex;
    //                 lines++;
    //             }
    //             else
    //             {
    //                 if (final[neighbor[currindex]] != -1)
    //                 {
    //                     start[neighbor[currindex]] = 0;
    //                     final[origindex] = final[neighbor[currindex]];
    //                 }
    //                 else{
    //                     final[origindex] = origindex;
    //                     circles++;
    //                 }
    //             }
    //             visited[neighbor[currindex]] = true;
    //             break;
    //         }
    //     }
    // }
    if(lines > 0){
        cout << circles+1 << " " << circles + lines << endl;
    }
    else{
        cout << circles << " " << circles << endl;
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