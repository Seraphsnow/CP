#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define ull unsigned long long

void solve()
{
    ull k;
    cin >> k;
    ull ans = 9, mul = 1, check = 9, num;
    while (check < k)
    {
        ans *= 10;
        mul += 1;
        check += ans * mul;
    }
    check = check - ans * mul;
//    cout << check << endl;

    num = pow(10, mul - 1);
    num = num -1;
    k = k - check; // digits after num
    // mul is the number of digits in each num at this point
    //cout << num << endl;
    //cout << (k-1)/mul + 1 << endl;
    num = num +  (k-1)/mul + 1;

    //cout << num << endl;
    ull digs = (k - 1)% mul;
    //cout << k << endl << check << endl << num << endl << mul << endl<< digs << endl ;
    cout << to_string(num)[digs] << endl;
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