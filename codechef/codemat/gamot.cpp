#include <bits/stdc++.h>
using namespace std;

#define ll long long

// void mygcd(ll &x, ll &y, ll &u, ll &v)
// {
//     if (x == y)
//         return;
//     else if (x > y)
//     {
//         if (x % y == 0)
//         {
//             u = u + v * (x / y - 1);
//             x = y;

//         }
//         else
//         {
//             u = u + v * (x / y);
//             x = x % y;
//             mygcd(y, x, u, v);
//         }
//     }
//     else
//     {
//         if (y % x == 0)
//         {
//             v = v + u * (y / x - 1);
//             y = x;

//         }
//         else
//         {
//             v = v + u * (y / x);
//             y = y % x;
//             mygcd(y, x, u, v);
//         }
//     }
// }

void solve()
{
    long long int a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << "0\n";
        return;
    }
    long long int x, y, u, v;
    x = a;
    u = a;
    y = b;
    v = b;
    // mygcd(x,y,u,v);
    while(x!=y){
        if(x>y){
            if(x%y == 0){
                u = u + (x/y-1) * v;
                x = y;
            }
            else{
                u = u + (x/y)*v;
                x = x%y;
                
            }
        }
        else{
            if(y%x == 0){
                v = v + (y/x-1) * u;
                y = x;
                
            }
            else{
                v = v + u * (y/x);
                y = y %x;
                
            }
        }
    }
    cout << u + v - x - y << endl;
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