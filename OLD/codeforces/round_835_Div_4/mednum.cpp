#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define ld long double 
#define fi first 
#define se second 
#define pb push_back 
#define pll pair<long long ,long long > 
#define ppll pair < pll , pll >

void solve(){
    int a, b,c;
    cin >> a >> b >> c;
    if((a <= b && b <= c )|| (a>=b && b>=c)) cout << b << endl;
    else if(( a <= c && c<= b) || (a>=c && c>=b)) cout << c << endl;
    else cout << a << endl;

}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}