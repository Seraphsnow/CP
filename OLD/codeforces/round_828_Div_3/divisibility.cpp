#include<bits/stdc++.h>
#include<math.h>

using namespace std;

int largestpower(long long int num){
    int ans = 0;
    while(true){
        if(num%2)break;
        ans += 1;
        num = num/2;
    }
    return ans;
}

int* totalpower(int num){
    int* ans = new int [int(floor(log2(num)))+1];
    ans[0] = floor(log2(num));
    int accumulation = 0;
    int pow2 = (int(floor(log2(num))),2);
    for(int i = floor(log2(num)); i > 0; i++){
        ans[i] = num/pow2 - accumulation;
        accumulation += ans[i];
        pow2 = pow2/2;
    }
    return ans;
}



int main(int argc, char* argv[]){
    int t;
    cin >> t;
    for(int a = 0; a < t; a++){
        int n;
        cin >> n;
        long long int arr[n];
        int mypow = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            mypow += largestpower(arr[i]);
        }
        int biggestpower = pow(2,floor(log2(n)));
        int count = 0;
        int accumulation =0;

        while(true){
            if(mypow >= n){
                cout << count << endl;
                break;
            }
            else if(biggestpower == 1){
                cout << -1 << endl;
                break;
            }
            else{
                int maxAdd = log2(biggestpower);
                int numAdd = n/biggestpower - accumulation;
                int needed = ceil(1.0*(n-mypow)/maxAdd);
                if(needed <= numAdd){
                    cout << count + needed << endl;
                    break;
                }
                else{
                    count = count + numAdd;
                    mypow = mypow + (int(n/biggestpower) - accumulation)*log2(biggestpower); 
                }
                accumulation = n/biggestpower;
                // count = count + 1;
                // accumulation += int(n/biggestpower)*log2(biggestpower);
                biggestpower = biggestpower/2;
            }
        }        


    }
}