#include <bits/stdc++.h>
using namespace std;
//longest subarray with sum <=K
int slidingwindow(vector<int>&arr,int k){
    int l =0;
    int r =0;
    int n = arr.size();
    int sum =0;
    int maxlen =0;
    while(r<n){
        sum += arr[r];
        if(sum>k && l!=r){
            sum -=arr[l];
            l++;
        }
        if(sum<=k){
            maxlen = max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}

int main(){
    vector<int> arr = {2,5,1,10,10};
    int k =14;
    cout<< slidingwindow(arr,k);
}