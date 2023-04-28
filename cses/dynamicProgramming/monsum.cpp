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

int main(int argc, char *argv[])
{
    ll n;
    cin >> n;
    set<ll> nums;

    for (int i = 0; i < n; i++)
    {
        //cout << "hi\n";
        ll num;
        cin >> num;
        ll arr[nums.size()];
        ll index = 0;
        for (auto x : nums)
        {
            if (nums.count(x + num) == 0){
                arr[index] = x+num;
                index++;
            }
                
        }
        for(int j = 0; j < index; j++){
            nums.insert(arr[j]);
        }
        if (nums.count(num) == 0)
            nums.insert(num);
    }

    set<ll>::iterator itr;
    cout << nums.size() << endl;
    for (itr = nums.begin(); itr != nums.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
}