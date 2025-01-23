#include <bits/stdc++.h>
using namespace std;

int f(int ind,int prev, vector<int> & arr,int n){
    if(ind==n) return 0;
    int len = f(ind+1,prev,arr,n);
    if(prev == -1 || arr[ind] % arr[prev] == 0 || arr[prev] % arr[ind] ==0){
        len = 1+ f(ind+1,ind,arr,n);
    }
    return len;
}

vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    //dp[i] stores the LDS till the index i , and the hash array stores the prev index stored in the LDS initially its equal to hash[i] =i
    // dp[i] = 1 initially;
    vector<int> dp(n,1) , hash(n);
    int maxi =1;
    int lastindex =0;
    sort(nums.begin(),nums.end());
    //In a subsequence, the elements need to follow the order of the original array whereas in a subset there is no constraint on the order of the elements. 
    //so yea hum sort krte hai usse yeh maintain rhta h ki saare previous elements bhi nums[i] % nums[prev] ==0 condition ko satisfy krenge with the new element;
    for(int i=0;i<n;i++){
        hash[i] = i;
        for(int prev =0;prev<=i-1;prev++){
            if((nums[i] % nums[prev] ==0) && 1+dp[prev] > dp[i]){
                dp[i] =1+dp[prev];
                hash[i] = prev;
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
            lastindex =i;
        }
    }
    vector<int> temp;
    temp.push_back(nums[lastindex]);
    while(hash[lastindex] != lastindex){
        lastindex = hash[lastindex];
        temp.push_back(nums[lastindex]);
    }
    reverse(temp.begin(),temp.end());
    return temp;
}
int main(){
    int n = 5;
    vector<int> arr = {1,2,4,8,10};
    cout <<f(0,-1,arr,n);
    vector<int> ans = largestDivisibleSubset(arr);
    for(auto it:ans){
        cout<<it<<" ";
    }
}

