#include <bits/stdc++.h>
#include <limits.h>
//#pragma GCC optimize("O3")
using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll, ll>

#define MOD 1000000007

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
    int n, x;
    cin >> n >> x;
    int coins[n];
    int currgcd = x;
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    int **arr;
    arr = new int *[x + 1];
    for (int i = 0; i <= x; i++)
    {
        arr[i] = new int[n];
        arr[i][0] = 0;
    }
    sort(coins, coins + n);
    
    for (int i = 1; i <= x; i++)// any number 
    {
        if (i % coins[0] == 0)
        {
            arr[i][0] = 1;
        }
    }
    for(int i = 0; i <n; i++){
        arr[0][i] = 1;
    }
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= n - 1; j++)
        {
            arr[i][j] = arr[i][j-1];
            if (i >= coins[j])
            {
                arr[i][j] = arr[i][j] + arr[i-coins[j]][j];
                if(arr[i][j]>=1000000007){
                    arr[i][j]-=1000000007;
                }
            }
        }
    }

    cout << arr[x][n-1] << endl;
}