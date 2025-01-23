#include <bits/stdc++.h>
using namespace std;

int f(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int len = 2; len < n; len++) {  
        for (int i = 0; i < n - len; i++) {
            int j = i + len;
            dp[i][j] = INT_MAX;

            for (int k = i + 1; k < j; k++) {
                int cost = dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    int n;
    cout<<"Enter no of matrices";
    cin>>n;
    vector<int> arr1(n+1,0);
    for(int i = 0;i<n+1;i++){
        cin>>arr1[i];
    }
    cout<< f(arr1);
}
