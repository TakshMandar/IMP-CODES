//longest string chain
#include <bits/stdc++.h>
using namespace std;
bool comp(string& s1, string& s2){
    return s1.size() <= s2.size();
}
bool compare(string&s1,string&s2){
    int n1 = s1.size();
    int n2 = s2.size();
    if(n1 != n2+1) return false;
    int first = 0;
    int second =0;
    while(first<n1){
        if(second < n2 && s1[first] == s2[second]){
            first++;
            second++;
        }
        else{
            first++;
        }
    }
    if(first == n1 && second == n2) return true;
    return false;
}
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),comp);
        vector<int> dp(n,1);
        int maxi =1;
        for(int i =0;i<n;i++){
            for(int prev = 0;prev<i;prev++){
                if(compare(words[i],words[prev]) && 1 + dp[prev] > dp[i]){
                    dp[i] =1+dp[prev];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
int main(){
    vector<string> arr = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
    sort(arr.begin(),arr.end(),comp);
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<< longestStrChain(arr);
}