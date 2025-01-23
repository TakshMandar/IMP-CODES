#include <bits/stdc++.h>
using namespace std;

//linear search 
//Time Complexity = O(N)
int linear(vector<int>&arr , int target){
    int n = arr.size();
    for(int i =0;i<n;i++){
        if(arr[i]==k){
            return i;
        }
    }
    return -1;
}
//Binary Search 
//Time complexity - O(logn) if sorted;
//if not sorted then O(logn + nlogn) = O(logn);
int Binary(vector<int>&arr , int k){
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int low =0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == k) return mid;
        else if(arr[mid] > k) high = mid -1;
        else {
            low = mid+1;
        }
    }
    return -1;
}