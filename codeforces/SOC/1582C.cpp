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

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll mI = 0, MI = n - 1;
    while (mI < MI)
    {
        if (s[mI] == s[MI])
        {
            mI++;
            MI--;
        }
        else
        {
            break;
        }
    }
    if(mI >= MI){
        cout << 0 << "\n";
        return;
    }
    // Case 1
    ll tempmi = mI, tempMI = MI;
    char del = s[mI];
    ll num = 1;
    mI++;
    while (mI < MI)
    {
        if (s[mI] == s[MI])
        {
            mI++;
            MI--;
        }
        else if (s[mI] == del)
        {
            mI++;
            num++;
        }
        else if (s[MI] == del)
        {
            MI--;
            num++;
        }
        else
        {
            num = -1;
            break;
        }
    }
    // Case 2
    mI = tempmi;
    MI = tempMI;
    del = s[MI];
    ll num2 = 1;
    MI--;
    while (mI < MI)
    {
        if (s[mI] == s[MI])
        {
            mI++;
            MI--;
        }
        else if (s[mI] == del)
        {
            mI++;
            num2++;
        }
        else if (s[MI] == del)
        {
            MI--;
            num2++;
        }
        else
        {
            num2 = -1;
            break;
        }
    }
    if(num == -1 && num2 == -1){
        cout << -1 << "\n";
    }
    else if(num == -1){
        cout << num2 << "\n";
    }
    else if(num2 == -1){
        cout << num << "\n";
    }
    else{
        cout << min<ll>(num,num2) << "\n";
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