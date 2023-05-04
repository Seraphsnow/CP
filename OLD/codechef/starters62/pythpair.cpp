#include<bits/stdc++.h>
using namespace std;

class mydata{
    public: 
        int pow;
        int reducedN;
};

mydata* powOf2(long long int n){
    int pow = 0;
    while(n%4==0){
        pow+=1;
        n = n >> 2;
    }
    mydata* ans;
    ans = new mydata();
    ans->pow = pow;
    ans->reducedN = n;
    return ans;
}

int isSquare(int n){
    
    int mysqrt = round(sqrt(n));
    if(n == mysqrt*mysqrt) return mysqrt;
    else return -1;
}

void solve(){
    long long int n;
    cin >> n;
    mydata meradta= *powOf2(n);
    long long int mysqrt = ceil(sqrt(meradta.reducedN));
    for(int i = 0; i<mysqrt; i++){
        long long int reducedb = isSquare(meradta.reducedN - i*i);
        if(reducedb!=-1){
            long long int a = i* pow(2,meradta.pow), b = reducedb*pow(2,meradta.pow);
            cout << a << " " << b <<" " << endl;
            return;
        }
    }
    cout << "-1" << endl;
}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}