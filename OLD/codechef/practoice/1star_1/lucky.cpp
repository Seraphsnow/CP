#include<bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    while (t--)
    {
        long long int num,ans=0;
        cin >> num;
        while(num>0){
            if(num%10 == 4)ans++;
            num = num/10;
        }
        cout << ans << endl;
    }
    
}