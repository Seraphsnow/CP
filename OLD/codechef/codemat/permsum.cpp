#include <bits/stdc++.h>
using namespace std;

vector<int> divisors(int N)
{
    vector<int> ansfront, ansback;

    for (int i = 1; i <= sqrt(N); i++)
    {
        if (N % i == 0)
        {
            ansfront.push_back(i);
            if (i != sqrt(N))
                ansback.push_back(N / i);
        }
    }
    for (; ansback.size() != 0;)
    {
        ansfront.push_back(ansback[ansback.size() - 1]);
        ansback.pop_back();
    }
    return ansfront;
}

void solve()
{
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    set<int> ans;
    vector<int> divisor = divisors(N);
    for (int i = 0; i < divisor.size(); i++)
    {
        int divisor1 = divisor[i];
        for (int j = 0; j < divisor1; j++)
        {
            long long int ans1 = 0;
            for (int k = 0; k < N/divisor1; k++)
            {
                ans1 += arr[(j+ k * divisor1)%N];
            }
            ans.insert(ans1);
        }
    }
    set<int>::iterator itr;
    for(itr = ans.begin(); itr!=  ans.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;
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