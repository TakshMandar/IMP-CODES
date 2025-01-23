#include <bits/stdc++.h>
using namespace std;
//failed shit lol
int f(int i , int prev , vector<int>& nums,int n ,vector<vector<int>>& dp){
    if(i == n) return 0;
    if(dp[i][prev+1] != -1) return dp[i][prev+1];
    int len = f(i+1,prev,nums,n,dp);
    if(prev == -1 || nums[i]>nums[prev]){
        len = max(len , 1 + f(i+1,i,nums,n,dp)); 
    }
    return dp[i][prev+1] = len;
}
void subs(vector<int>&nums , vector<int>&ds , int ind,int prev,int n,int maxlen){
    if(ind == n){
        if(ds.size() == maxlen){
            for(auto it : ds){
                cout<< it<<" ";
            }
        }
        cout<<endl;
        return;
    }
    subs(nums,ds,ind+1,prev,n,maxlen);
    if(prev == -1 || nums[ind]>nums[prev]){
        ds.push_back(nums[ind]);
        subs(nums,ds,ind+1,ind,n,maxlen); 
    }
}

int main(){
    vector<int> nums = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    int n = 16;
    vector<vector<int>> dp(n,vector<int> (n,-1));
    int maxlen = f(0,-1,nums,n,dp);
    cout<<maxlen;
    vector<int> ds;
    subs(nums,ds,0,-1,n,maxlen);
}