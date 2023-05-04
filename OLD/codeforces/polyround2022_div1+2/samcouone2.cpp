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

bool lesserfunc(pll p1, pll p2){
    if (p1.se < p2.se) return true;
    else return false;
}

bool greaterfunc(pll p1, pll p2){
    if (p1.se > p2.se) return true;
    else return false;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll arr[n][m];
    ll numones[n], total = 0;
    bool same = true;

    for (int i = 0; i < n; i++)
    {
        numones[i] = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            numones[i] += arr[i][j];
        }
        total += numones[i];
        if (i != 0)
        {
            if (numones[i] != numones[i - 1])
            {
                same = false;
            }
        }
    }
    if (total % n != 0)
    {
        cout << -1 << endl;
        return;
    }

    if (same)
    {
        cout << 0 << endl;
        return;
    }

    vector<pll> mylessthan, mygreaterthan;
    for (int i = 0; i < n; i++)
    {
        if (numones[i] > total / n)
        {
            mygreaterthan.pb({i, numones[i]});
        }
        else if (numones[i] < total / n)
        {
            mylessthan.pb({i,numones[i]});
        }
    }
    sort(mylessthan.begin(), mylessthan.end(), greaterfunc);
    sort(mygreaterthan.begin(), mygreaterthan.end(), lesserfunc);
    
    ll times = 0;
    for (int i = 0; i < mygreaterthan.size(); i++)
    {
        times += mygreaterthan[i].se - total / n;
    }
    cout << times << endl;

    while(!mygreaterthan.empty()){
        bool elemdone = false;
        ll index= mygreaterthan.size()-1;
        for (int j = 0; j < m; j++)
        {
            if (arr[mygreaterthan[index].fi][j] == 0)
                continue;

            for (int k = mylessthan.size()-1; k>=0; k--)
            {
                if (arr[mylessthan[k].fi][j] == 1)
                    continue;
                else
                {
                    cout << mylessthan[k].fi + 1 << " " << mygreaterthan[index].fi + 1 << " " << j + 1 << endl;
                    arr[mylessthan[k].fi][j] = 1;
                    mylessthan[k].se++;
                    if (mylessthan[k].se == total / n)
                    {
                        mylessthan.erase(mylessthan.begin() + k);
                    }
                    arr[mygreaterthan[index].fi][j] = 0;
                    mygreaterthan[index].se--;
                    if (mygreaterthan[index].se == total / n)
                    {
                        mygreaterthan.erase(mygreaterthan.end());
                        elemdone = true;
                    }

                    break;
                }
            }
            if (elemdone)
                break;
        }
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