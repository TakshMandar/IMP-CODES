#include <bits/stdc++.h>
using namespace std;


void longestCommonSubsequence(string s1, string s2,int n1,int n2) {
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    for(int ind1 = n1-1;ind1>=0;ind1--){
        for(int ind2 = n2-1;ind2>=0;ind2--){
            int maxi = INT_MIN;
            if(s1[ind1] == s2[ind2]){
                maxi = max(maxi,1+dp[ind1+1][ind2+1]);
            }
            else{
                maxi = max(maxi,max(dp[ind1+1][ind2],dp[ind1][ind2+1]));
            }
            dp[ind1][ind2] = maxi;
        }
    }
    int index  = 0;
    string s = "";
    int i = 0, j = 0;
    while (i<n1 && j <n2) {
        
        if (s1[i] == s2[j]) {
            s += s1[i];
            i++;
            j++;
        }
        else if (dp[i + 1][j] > dp[i][j + 1])
            i++;
        else
            j++;
    }
    cout <<s<<endl;
    cout<<s.length();
}
// TC->O(N1 X N2);
// SC->O(N1 XN2)
int main(){
    string s1;
    cin>>s1;
    string s2;
    cin>> s2;
    longestCommonSubsequence(s1,s2,s1.length(),s2.length());
}