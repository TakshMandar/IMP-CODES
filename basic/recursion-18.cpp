#include <bits/stdc++.h>
using namespace std;

int n;
class Solution {
  public:
    void f(string ST, string s, int x, int y , int nr[], int nc[], vector<vector<int>> &mat,vector<string>& ans,vector<vector<int>>&vis){
        if( x== n-1 && y == n-1){
            ans.push_back(s);
            return;
        }
        for(int i =0;i<4;i++){
            int nrr = nr[i]+x;
            int ncc = nc[i]+y;
            if(nrr<n && ncc<n && nrr>=0 && ncc>=0 && !vis[nrr][ncc]){
                if(mat[nrr][ncc] == 1){
                    vis[nrr][ncc] = 1;
                    f(ST,s + ST[i],nrr,ncc,nr,nc,mat,ans,vis);
                    vis[nrr][ncc] = 0;
                }
            }  
        }
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> ans;
        string s = "";
        n = mat.size();
        if(mat[0][0] == 0) return ans;
        int nr[4] = {0,-1,0,1};
        int nc[4] = {-1,0,1,0};
        string ST = "LURD";
        vector<vector<int>> vis(n,vector<int>(n,0));
        f(ST,s,0,0,nr,nc,mat,ans,vis);
        return ans;
    }
};