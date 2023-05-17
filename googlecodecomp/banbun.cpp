#include <bits/stdc++.h>
using namespace std;

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

bool comp(pair<int, pair<int,int>> p1, pair<int, pair<int,int>> p2)
{
    return p1.fi < p2.fi;
}

class my
{
public:
    my()
    {
    }
    my(int nu)
    {
        num = nu;
    }
    int num;
    vector<pair<int,int>> pairs;
};

void solve(int index1)
{
    int n, k;
    cin >> n >> k;
    int arr[n + 1];
    int sum = 0;
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        sum += num;
        arr[i] = sum;
    }

    int ans = INT_MAX;
    vector<pair<int, pair<int,int>>> sums;

    vector<pll> nums[k+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (arr[j] - arr[i] == k)
            {
                ans = min(ans, j - i);
                //cout << j << " " << i << endl;
            }
            else if (arr[j] - arr[i] < k)
            {
                nums[arr[j]-arr[i]].push_back({j,i});
                for(int l = 0; l < nums[k-arr[j]+arr[i]].size(); l++){
                    if(nums[k-arr[j]+arr[i]][l].fi < i){
                        ans = min<ll>(ans, nums[k-arr[j]+arr[i]][l].fi - nums[k-arr[j]+arr[i]][l].se + j - i);
                    }
                }
            }
            else{
                break;
            }
        }
    }
    
    if (ans == INT_MAX)
    {
        ans = -1;
    }
    cout << "Case #" << index1 << ": " << ans << endl;
}

int main(int argc, char *argv[])
{
    int t;
    cin >> t;
    int index = 1;
    while (t--)
    {
        solve(index);
        index++;
    }
}