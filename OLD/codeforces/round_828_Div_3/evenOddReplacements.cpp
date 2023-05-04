#include<bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n,q;
        cin >> n >> q;
        long long int arr[n];
        long long int sum = 0;
        int numOdd=0, numEven=0;
        for(int j = 0; j < n ; j++){
            cin >> arr[j];
            sum+=arr[j];
            if(arr[j]%2) numOdd++;
            else numEven++;
        }
        for(int k = 0; k < q; k++){
            long long int odd, num;
            cin >> odd >> num;
            if(odd) sum = sum + numOdd*num;
            else sum = sum + numEven*num;
            if(num%2!=0){
                if(odd){
                    numEven = numEven+numOdd;
                    numOdd = 0;
                }
                else{
                    numOdd = numOdd + numEven;
                    numEven = 0;
                }
            }
            cout << sum << endl;
        }
        // for(int k = 0; k < q;k++){
        //     int odd, num;
        //     cin >> odd >> num;
        //     for(int l = 0; l < n; l++){
        //         if(arr[l]%2 == odd){
        //             sum+=num;
        //             arr[l]+=num;
        //         }
        //     }
        //     cout << sum << endl;
        //}
    }
}