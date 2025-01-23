#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {2,1,1,5,6,2,3,1};
    int n= nums.size();
    vector<int> bak1(n,0);
    for(int i = 1;i<n-1;i++){
        if(nums[i] <= nums[i-1]){
            bak1[i] = 1+bak1[i-1];
        }
        else{
            bak1[i] = bak1[i-1];
        }
    }
    for(auto it: bak1){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> back2(n,0);
    for(int i = n-2;i>0;i--){
        if(nums[i] <=nums[i+1]){
            back2[i] = 1+back2[i+1];
        }
        else{
            back2[i] = back2[i+1];
        }
    }
    for(auto it:back2){
        cout<<it<<" ";
    }
    int ans = INT_MAX;
    for(int i = 1;i<n-1;i++){
        ans = min(ans, bak1[i]+back2[i]);
    }
    cout<<ans;
}