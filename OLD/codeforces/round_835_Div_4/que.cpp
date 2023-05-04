#include <bits/stdc++.h>
using namespace std;

#define ll long long int
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
    for (int i = 0; i < size; i++)
    {
        cout << i << ": " << arr[i] << endl;
    }
    cout << endl
         << endl;
}

void solve()
{
    ll n, d;
    ll c; // dekhna overflow ka
    cin >> n >> c >> d;
    ll rewards[n], sum[n];
    
    for (int i = 0; i < n; i++)
    {
        cin >> rewards[i];
    }
    sort(rewards, rewards + n, greater<int>());
    for(int i = 0; i < n; i++){
        if(i == 0) sum[i] = rewards[i];
        else {
            sum[i] = sum[i-1] + rewards[i];
        }
    }
    if (rewards[0] * d < c)
    {
        cout << "Impossible\n";
        return;
    }
    for (int k = 0; true; k++)
    {
        if(k<n){
            ll cycles = d/(k+1), daysleft = d-cycles*(k+1);
            ll maxreward = cycles * sum[k];
            if(daysleft>0) maxreward += sum[daysleft-1];
            if(maxreward < c){
                cout << k - 1 << endl;
                break;
            }
        }
        else if(k<d){
            ll cycles = d/(k+1), daysleft = d-cycles*(k+1);
            ll maxreward = cycles * sum[n-1];
            if(daysleft>0 && daysleft<n) maxreward += sum[daysleft-1];
            else if (daysleft >=n) maxreward += sum[n-1];
            if(maxreward < c){
                cout << k - 1 << endl;
                break;
            }
        }
        else{
            cout << "Infinity\n";
            break;
        }
    }
}

int main(int argc, char *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}