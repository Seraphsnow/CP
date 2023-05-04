#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define ld long double 
#define fi first 
#define se second 
#define pb push_back 
#define pll pair<long long ,long long > 
#define ppll pair < pll , pll >

template <typename T>
void printArr(T*arr, ll size){
    for(ll i = 1; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void adv_tokenizer(string s, char del)//Split string
{
    stringstream ss(s);
    string word;
    while (!ss.eof()) {
        getline(ss, word, del);
        cout << word << endl;
    }
}

void solve(){
    ll n;
    cin >> n;
    ll arr[n+1];
    ll pq[n+1];
    for(int i = 1; i<=n;i++){
        cin >> arr[i];
        pq[arr[i]] = i;
    }
    if(n == 2){
        if(arr[1] == 1){
            cout << "Possible\n2 1\n2 1\n";
        }
        else{
            cout << "Impossible\n";
        }
        return;
    }
    ll q[n+1],p[n+1];
    ll done[n+1];//qinv
    for(int i = 1; i < n+1; i++){
        done[i] = -1;
        q[i] = -1;
        p[i] = -1;
    }
    int i = 1;
    while(true){
        bool found=false;
        for(int j = 1; j < n; j++){
            if(done[j] == -1 && j !=i && j!= pq[i]){
                found = true;
                done[j] = i;
                q[i] = j;
                break;
            }
        }
        if(!found){
            if(i == n-1){// 1 switch needed
                //n-1 has no pre image, if it did, then i won't be n-1
                //need to find x such that q[n-1] = original q[x] and q[x] = n-1 is possible
                for(int x = 1; x < n-1; x++){
                    if((q[x] != pq[n-1]) && (pq[x]!=n-1)){
                        int originalx = x, originalqx = q[x];
                        q[n-1] = q[originalx];
                        q[x] = n-1;
                        done[n-1] = x;
                        done[originalqx] = n-1;
                        found = true;
                        break;
                    }
                }
            }
            else{// i == n and atmost 2 switches needed
                if(done[n] == -1){// n has no preimage
                    for(int x = 1; x < n; x++){// checking if 1 switch enuf
                        if((q[x] != pq[n]) && (pq[x]!=n)){
                            int originalx = x, originalqx = q[x];
                            q[n] = q[originalx];
                            q[x] = n;
                            done[n] = x;
                            done[originalqx] = n;
                            found = true;
                            break;
                        }
                    }
                    if(!found){// need 2 switches
                        q[done[pq[n]]] = n;
                        done[n] = done[pq[n]];
                        done[pq[n]] = -1;
                        for(int x = 1; x < n; x++){
                            //need to find x such that q[n] = original q[x] and x != pq[n] is possible
                            if((q[x]!=pq[n]) && (x!=pq[n])){
                                int originalx = x, originalqx = q[x];
                                q[n] = q[originalx];
                                q[x] = pq[n];
                                done[pq[n]] = x;
                                done[originalqx] = n;
                                found = true;
                                break;
                            }
                        }
                    }
                }
                else{// done[pq[n]] == -1
                    for(int x = 1; x < n; x++){// checking if 1 switch enuf
                        if((q[x] != pq[n]) && (x!=pq[n])){
                            int originalx = x, originalqx = q[x];
                            q[n] = q[originalx];
                            q[x] = pq[n];
                            done[pq[n]] = x;
                            done[originalqx] = n;
                            found = true;
                            break;
                        }
                    }
                    if(!found){// need 2 switches
                        q[done[n]] = pq[n];
                        done[pq[n]] = done[n];
                        done[n] = -1;
                        for(int x = 1; x < n; x++){
                            //need to find x such that q[n] = original q[x] and pq[x] != n is possible
                            if((q[x]!=pq[n]) && (pq[x]!=n)){
                                int originalx = x, originalqx = q[x];
                                q[n] = q[originalx];
                                q[x] = n;
                                done[n] = x;
                                done[originalqx] = n;
                                found = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        i++;
        if(i == n+1) break;
    }
    for(int i = 1; i <=n;i++){
        if(q[i]<0) cout << "BT";
        else p[q[i]] = pq[i];
    }
    cout << "Possible\n";
    printArr<ll>(p, n+1);
    printArr<ll>(q, n+1);

}

int main(int argc, char*argv[]){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}