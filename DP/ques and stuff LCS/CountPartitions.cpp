#include <bits/stdc++.h>
using namespace std;
int mod = (int)1e9+7;
int perfectSum(vector<int> &arr, int n, int sum)
{
        // Your code goes here
    vector<int> prev(sum+1,0) , cur(sum+1,0);
    if(arr[0]==0) prev[0] = 2;
    else prev[0]=1;
        
    if (arr[0]!=0 && arr[0] <= sum) {
        prev[arr[0]] = 1;
    }
        
    for(int i=1; i<n; i++) {
        for(int j=0; j<=sum; j++) {
            int take = 0;
            if(arr[i] <= j) {
                take = prev[j - arr[i]];
            }
            int notTake = prev[j]; 
                
            cur[j] = (take + notTake) % mod;
        }
        prev = cur;
    }
    return prev[sum];
}
int countPartitions(int n, int d, vector<int>& arr) {
    int totalsum = 0;
    for(auto it: arr){
        totalsum += it;
    }
    if(totalsum - d <0 || (totalsum -d)%2 != 0) return false;
    return perfectSum(arr,n,(totalsum - d)/2)%mod;
}

int main(){
    vector<int> arr={5,2,6,4};
    int d = 3;
    int n = 4;
    cout<<countPartitions(n,d,arr);
}