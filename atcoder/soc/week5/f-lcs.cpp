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
    string s, t;
    cin >> s >> t;
    ll **arr;
    arr = new ll *[s.size() + 1];
    for (int i = 0; i <= s.size(); i++)
    {
        arr[i] = new ll [t.size() + 1];
    }
    for (int i = 0; i <= s.size(); i++)
    {
        arr[i][0] = 0;
    }
    for (int i = 0; i <= t.size(); i++)
    {
        arr[0][i] = 0;
    }

    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 1; j <= t.size(); j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                arr[i][j] = arr[i-1][j-1]+1;
            }
            else
            {
                if(arr[i-1][j] > arr[i][j-1]){
                    arr[i][j] = arr[i-1][j];
                }
                else{
                    arr[i][j] = arr[i][j-1];
                }
            }
        }
    }
    ll currind = s.size(), currindt = t.size();
    string ans = "";
    while(true){
        if(arr[currind][currindt] == 0){
            break;
        }
        if(s[currind-1] == t[currindt-1]){
            ans = ans + s[currind-1];
            currind--;
            currindt--;
        }
        else{
            if(arr[currind-1][currindt] == arr[currind][currindt]){
                currind--;
            }
            else{
                currindt--;
            }
        }
    }
    string s2="";
    for(int i = 0; i < ans.size(); i++){
        s2+=ans[ans.size()-1-i];
    }
    cout << s2 << endl;
}