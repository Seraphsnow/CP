#include <bits/stdc++.h>
using namespace std;

// For policy data structures
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<long long, long long>
#define ppll pair<pll, pll>

typedef tree<ll,null_type,less_equal<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

typedef tree<ll,null_type,greater_equal<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set2;


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

class Range{
    public:
        ll left, right;
        ll index;
        ll inside;
        ll covers;
        Range(){
            inside = 0;
            covers = 0;
        };
};

bool comp(Range r1, Range r2){
    return r1.left < r2.left || (r1.left == r2.left && r1.right > r2.right);
}

bool comp2(Range r1, Range r2){
    return r1.index < r2.index;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    Range arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].left >> arr[i].right;
        arr[i].index = i;
    }
    sort(arr, arr+n, comp);
    indexed_set s;
    for(int i = n-1; i >= 0; i--){
        s.insert(arr[i].right);
        ll nums = s.order_of_key(arr[i].right+1);
        arr[i].covers = nums-1;
        
    }
    indexed_set2 s1;
    for(int i = 0; i < n; i++){
        s1.insert(arr[i].right);
        ll nums = s1.order_of_key(arr[i].right-1);
        arr[i].inside = nums-1;
    }

    sort(arr,arr+n, comp2);
    for(int i = 0; i < n; i++){
        cout << arr[i].covers << " ";
    }
    cout << "\n";
    for(int i = 0; i < n; i++){
        cout << arr[i].inside << " ";
    }
    cout << "\n";
}