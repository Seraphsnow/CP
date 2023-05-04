#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<long long int, long long int> a, pair<long long int, long long int> b){
    return a.first*b.second > b.first*a.second;
}

void solve()
{
    long long int n;
    cin >> n;
    vector<pair<long long int, long long int>> data;
    for(int i = 0; i < n; i++){
        long long int a1;
        cin >> a1;
        data.push_back({a1,0});
    }
    for(int i = 0; i < n; i++){
        long long int a1;
        cin >> a1;
        data[i].second = a1;
    }
    sort(data.begin(), data.end(), comparator);
    long long int ans=0, length=0;
    for(int i = 0; i < n ; i++){
        ans += length*data[i].second;
        length+=data[i].first;
    }
    cout << ans << endl;
    
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