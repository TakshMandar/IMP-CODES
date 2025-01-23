#include <bits/stdc++.h>
using namespace std; 
  
int main(){
    multimap<int,int> mpp;
    mpp.insert({1,2});
    mpp.insert({1,3});
    for(auto it=mpp.find(3);it!=mpp.end();it++){
        cout<<it->first<<it->second;
    }
}
class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> ans;
        long long x = -1;
        for(int i = 0;i<n;i++){
            vector<int> maybe;
            long long score = arr[i][2];
            long long start = arr[i][0];
            long long end = arr[i][1];
            maybe.push_back(i);
            int cnt = 0;
            for(int j = i+1;j<n;j++){
                
                long long s2 = arr[j][0];
                long long end2 = arr[j][1];
                if(s2<= end && end2>=start){
                    continue;
                }
                else{
                    start = min(start,s2);
                    end = max(end2,end);
                    score += arr[j][2];
                    maybe.push_back(j);
                }
                if(cnt == 4)
                    break;
            }
            if(score >= x){
                if(maybe.size() < ans.size() && x == score ){
                    ans = maybe;
                    continue;
                }
                x = score;
                ans = maybe;
            }
        }
        return ans;
    }
};