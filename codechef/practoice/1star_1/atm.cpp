#include<bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]){
    int x;
    double y;
    cout << fixed << setprecision(2);
    cin >> x >> y;
    if(x<=y-0.5 && x%5==0) cout << y-x-0.5 << endl;
    else cout << y << endl;
}