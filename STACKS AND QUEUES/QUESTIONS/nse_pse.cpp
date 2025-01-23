#include <bits/stdc++.h>
using namespace std;

vector<int> nse(vector<int>&arr){
    stack<int> st;
    int n = arr.size();
    vector<int> nse(n);
    for(int i =n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.empty()) nse[i] = n;
        else{
            nse[i] = st.top();
        }
        st.push(i);
    }
    return nse;
}
vector<int> pse(vector<int>&arr){
    stack<int> st;
    int n = arr.size();
    vector<int> pse(n);
    for(int i =0;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.empty()) pse[i] = -1;
        else{
            pse[i] = st.top();
        }
        st.push(i);
    }
    return pse;
}



int main(){
    vector<int> arr = {1,4,6,7,3,7,8,1};
    vector<int> ans = nse(arr);
    for(auto it: ans){
        cout<< it<<" ";
    }
    vector<int> ans2 = pse(arr);
    for(auto it: ans2){
        cout<< it<<" ";
    }
}

class Solution {
public:
    vector<int> nse(vector<int>&arr){
        stack<int> st;
        int n = arr.size();
        vector<int> nse(n);
        for(int i =n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) nse[i] = n;
            else{
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }
    //prev smaller and equal cause of the edge case [1,1] in this case [1,1] will be considered 2wcie so instead of considering it  //again we can just use prev smaller and equal element left = 1-0= 1; right = 2-1 ==> left*right*1 = 1;
    vector<int> pse(vector<int>&arr){
        stack<int> st;
        int n = arr.size();
        vector<int> pse(n);
        for(int i =0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()) pse[i] = -1;
            else{
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse;
    }
        int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> ps = pse(arr);
        vector<int> ns = nse(arr);
        int total = 0;
        int mod = (int)1e9 +7;
        for(int i= 0;i<n;i++){
            int left = i - ps[i];
            int right = ns[i] -i;
            total = (total +(left*1ll*right*arr[i])%mod)%mod;
        }
        return total;
    }
};