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

ll luck(ll num){
    ll max = 0, min = 9;
    while(num>0){
        ll dig = num%10;
        if(dig > max){
            max = dig;
        }
        if(dig < min){
            min = dig;
        }
        num = num / 10;
    }
    return max - min;
}

void solve()
{
    ll l, r;
    cin >> l >> r;
    if ((r - l) >= 99)
    {
        if (l % 100 <= 90)
        {
            ll num = l / 100;
            num = num * 100;
            num = num + 90;
            cout << num << endl;
        }
        else if (r % 100 >= 90)
        {
            ll num = r / 100;
            num = num * 100;
            num = num + 90;
            cout << num << endl;
        }
        else
        {
            ll num = l / 100;
            num = num * 100;
            num = num + 190;
            cout << num << endl;
        }
    }
    else{
        ll num = l, currmax = luck(l);
        for(int i = l+1;i <= r; i++){
            if(luck(i)>currmax){
                num = i;
                currmax = luck(i);
            }
        }
        cout << num << endl;
    }
}

int main(int argc, char *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}