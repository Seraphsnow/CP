#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s, ans = "";
    cin >> s;
    int j = 0;
    if (n == 1)
    {
        cout << "YES\n";
        return;
    }
    bool find1 = false;
    for (int i = 0; i < n; i++)
    {
        if (!find1)
        {
            if (s[i] == '0')
                continue;
            else{
                find1 = true;
            }
        }
        else{
            if(s[i] == '1'){
                find1 = false;

            }
            else{
                cout << "NO\n";
                return;
            }
        }
    }
    if(find1) cout << "NO\n";
    else cout << "YES\n";
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