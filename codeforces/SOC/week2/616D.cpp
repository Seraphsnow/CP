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

int main(int argc, char *argv[])
{
    ll n, k;
    cin >> n >> k;
    unordered_map<ll, ll> nums;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        nums[arr[i]]=0;
    }
    ll l = 0, r = 0;
    ll lmax = 0, rmax = 0, currmax = 0;
    ll numkeys = 0;

    nums[arr[0]] = 1;
    numkeys++;
    while (true)
    {

        if(r == n-1){
            break;
        }
        if (numkeys < k)
        {

            if (nums[arr[r + 1]] == 0)
            {
                nums[arr[r + 1]] = 1;
                r++;
                numkeys++;
                
                if (r -l > currmax)
                {
                    lmax = l;
                    rmax = r;
                    currmax = r - l;
                    //cout << lmax << ' ' << rmax << endl;
                }
            }
            else
            {
                nums[arr[r + 1]]++;
                r++;
                if (r - l > currmax)
                {
                    lmax = l;
                    rmax = r;
                    currmax = r - l;
                }
            }
        }
        else
        {
            if (nums[arr[r + 1]] == 0)
            {
                if(nums[arr[l]] == 1){
                    nums[arr[l]] = 0;
                    nums[arr[r+1]] = 1;
                    l++;
                    r++;
                }
                else{
                    nums[arr[l]]--;
                    l++;
                }
            }
            else
            {
                nums[arr[r + 1]]++;
                r++;
                if (r - l > currmax)
                {
                    lmax = l;
                    rmax = r;
                    currmax = r - l;
                }
            }
        }
    }
    cout << lmax+1 << " " << rmax+1 << endl;
}