
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findnextgreater(int ind,vector<int>&arr){
        int n = arr.size();
        for(int i=0;i<ind;i++){
            if(arr[i]>arr[ind]){
                return arr[i];
            }
        }
        return -1;
    }
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        int cnt =0;
        int i =n-1;
        stack<int> st;
        while(cnt<=n && i>=0){
            while(!st.empty() && st.top() <=nums[i]) st.pop();
            if(st.empty()){
                int el = findnextgreater(i,nums);
                nge[i] = el;
            }
            else{
                nge[i] = st.top();
            }
            st.push(nums[i]);
            i--;
            cnt++;
        }
        return nge;
    }
};