#include<bits/stdc++.h>
using namespace std;



long long int solve(vector<long long int>a,vector<long long int> b, map<vector<long long int>, long long int> data){
    int length = a.size();
    if(length == 1){
        return 0;
    }
    else if (length == 2){
        return max(a[0]*b[1], a[1]*b[0]);
    }
    else{
        if(data.find(a)!=data.end()){cout << 'h'; return data[a];}
        long long int mymax = 0;
        for(int i = 0; i < length; i++){
            vector<long long int> arr1 , arr2;
            long long int beauty = 0;
            for(int j = 0; j < length; j++){
                if(j == i){
                    continue;
                }
                arr1.push_back(a[j]);
                arr2.push_back(b[j]);
                beauty+=b[j];
            }
            mymax = max(mymax, beauty*a[i] + solve(arr1,arr2, data));
        }
        data.insert({a,mymax});
        return mymax;
    }
}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        vector<long long int> a ,b;
        map<vector<long long int>,long long int> data;
        for(int i = 0; i < n ;i++){
            long long int a1;
            cin >> a1;
            a.push_back(a1);
        }
        for(int i = 0; i < n ;i++){
            long long int b1;
            cin >> b1;
            b.push_back(b1);
        } 
        cout << solve(a, b,data) << endl;
    }
}