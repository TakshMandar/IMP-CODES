#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        stack<int> st;
        unordered_map<int,int> mpp;
        vector<int> nge(n1);
        for(int i =n2-1;i>=0;i--){
            while(!st.empty() and st.top() <=nums2[i]) st.pop();
            if(st.empty()) mpp[nums2[i]] = -1;
            else mpp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        for(int i =0;i<n1;i++){
            nge[i] = mpp[nums1[i]];
        }
        return nge;
    }
};