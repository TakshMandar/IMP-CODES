#include <bits/stdc++.h>
using namespace std;

void printsub(vector<int>&arr,int ind, vector<int>&ans,int&a){
    if(ind ==arr.size()){
        int mini = INT_MAX;
        for(auto it:ans){
            cout<< it<<" ";
            mini = min(mini,it);
        }
        if(mini != INT_MAX) a += mini;
        if(ans.size() == 0) cout<<"{}"<<" ";
        cout<<endl;
        return;
    }
    else{
        ans.push_back(arr[ind]);
        printsub(arr,ind+1,ans,a);
        ans.pop_back();
        printsub(arr,ind+1,ans,a);
    }
}

int main(){
    vector<int> arr = {3,1,2,4};
    vector<int> ans;
    int a=0;
    printsub(arr,0,ans,a);
    cout<<a;
}