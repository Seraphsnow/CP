#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n, myans = 0, totallength = 0;
    cin >> n;
    vector<long long int> a, b, anslength, ansbeauty;
    for (int i = 0; i < n; i++)
    {
        int a1;
        cin >> a1;
        a.push_back(a1);
    }
    for (int i = 0; i < n; i++)
    {
        int a1;
        cin >> a1;
        b.push_back(a1);
    }
    anslength.push_back(a[0]);
    ansbeauty.push_back(b[0]);
    for (int i = 1; i < n; i++)
    {
        int max = i, maxbeauty;
        totallength += a[i - 1];
        myans += totallength * b[i];
        maxbeauty = myans;
        anslength.push_back(a[i]);
        ansbeauty.push_back(b[i]);
        for (int j = i - 1; j >= 0; j--)
        {
            long long int temp;
            temp = anslength[j+1];
            anslength[j+1] = anslength[j];
            anslength[j] = temp;
            temp = ansbeauty[j+1];
            ansbeauty[j+1] = ansbeauty[j];
            ansbeauty[j] = temp;
            myans = myans - anslength[j+1] * b[i] + a[i] * ansbeauty[j+1];
            if (myans >= maxbeauty)
            {
                max = j;
                maxbeauty = myans;
            }
        }
        anslength.erase(anslength.begin());
        ansbeauty.erase(ansbeauty.begin());
        anslength.insert(anslength.begin() + max, a[i]);
        ansbeauty.insert(ansbeauty.begin() + max, b[i]);
        myans = maxbeauty;
    }
    cout << myans << endl;
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