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
#define ull unsigned long long

ll distance(string s1, string s2, ll **arr, ll i1, ll i2)
{
    if (i1 == -1)
    {
        return i2 + 1;
    }
    if (i2 == -1)
    {
        return i1 + 1;
    }
    if (arr[i1][i2] != -1)
    {
        return arr[i1][i2];
    }

    arr[i1][i2] = min<ll>(distance(s1, s2, arr, i1, i2 - 1) + 1, distance(s1, s2, arr, i1 - 1, i2) + 1);
    if (s1[i1] == s2[i2])
    {
        arr[i1][i2] = min<ll>(arr[i1][i2], distance(s1, s2, arr, i1 - 1, i2 - 1));
    }
    else
    {
        arr[i1][i2] = min<ll>(arr[i1][i2], distance(s1, s2, arr, i1 - 1, i2 - 1) + 1);
    }
    return arr[i1][i2];
};

int main(int argc, char *argv[])
{
    string s1, s2;
    cin >> s1 >> s2;
    ll **arr;
    arr = new ll *[s1.size()];
    for (int i = 0; i < s1.size(); i++)
    {
        arr[i] = new ll[s2.size()];
    }
    for (int i = 0; i < s1.size(); i++)
    {
        for (int j = 0; j < s2.size(); j++)
        {
            if (i == 0)
            {
                if (s1[i] == s2[j])
                    arr[i][j] = j;
                else
                    arr[i][j] = j + 1;
            }
            else if (j == 0)
            {
                if (s1[i] == s2[j])
                    arr[i][j] = i;
                else
                    arr[i][j] = i + 1;
            }
            else{
                if(s1[i] == s2[j]){
                    arr[i][j] = arr[i-1][j-1];
                }
                else{
                    arr[i][j] = min(min(arr[i-1][j]+1, arr[i][j-1]+1), arr[i-1][j-1]+1);
                }
            }
        }
    }
    cout << arr[s1.size()-1][s2.size()-1] << endl;
    //cout << distance(s1, s2, arr, s1.size() - 1, s2.size() - 1) << endl;
}