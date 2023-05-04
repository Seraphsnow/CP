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


int solve(int N, int *A)
{
    int arr[N+1][N];
    for(int i = 0; i<N; i++){
        arr[N][i] =  0; 
    }
    for(int i = 0; i < N; i++){
        ll sum = 0;
        while(A[i]%2 == 0){
            sum+=1;
            A[i] = A[i]/2;
        }
        arr[i][2] =  
        for(int j = 3; j < sqrt(N); j++){
            while(A[i]%j == 0){
                
            }
        }
    }
}

int main(int argc, char *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        cout << solve(N, A) << endl;
    }
}