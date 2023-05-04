#include<bits/stdc++.h>
using namespace std;

long long int beauty(vector<long long int> a,vector<long long int> b){
    long long int ans = 0;
    long long int length = 0;
    for(int i = 0; i < a.size(); i++){
        ans += length*b[i];
        length += a[i];
    }
    return ans;
}

void print(vector<long long int> a ){
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << "HI";
    }
    cout << endl;
}

void solve(){
    long long int n;
    cin >> n;
    vector<long long int> a,b,anslength, ansbeauty;
    for(int i = 0; i < n ; i++){
        int a1;
        cin >> a1;
        a.push_back(a1);
    }
    for(int i = 0; i < n ; i++){
        int a1;
        cin >> a1;
        b.push_back(a1);
    }
    for(int i = 0; i < n; i++){
        int max=-1, maxbeauty = -1;
        for(int j = i; j >= 0 ; j--){
            anslength.insert(anslength.begin()+j, a[i]);
            ansbeauty.insert(ansbeauty.begin()+j, b[i]);
            if(beauty(anslength,ansbeauty)>maxbeauty){
                max = j;
                maxbeauty = beauty(anslength,ansbeauty);
            }
            anslength.erase(anslength.begin()+j);
            ansbeauty.erase(ansbeauty.begin()+j);
        }
        anslength.insert(anslength.begin()+max, a[i]);
        ansbeauty.insert(ansbeauty.begin()+max, b[i]);
    }
    cout << beauty(anslength, ansbeauty) << endl;
}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}