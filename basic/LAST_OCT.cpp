#include <bits/stdc++.h>
using namespace std;

long long minimumTotalDistance(vector<int>& robots , vector<vector<int>>& factory){
    int n1 = robots.size();
    int n2 = factory.size();
    long long totaldist = 0;
    for(int i = 0 ;i<n1;i++){
        int index = -1;
        long long mindist = LONG_LONG_MAX;
        for(int j = 0;j<n2;j++){
            if(factory[j][1] == 0) continue;
            else{
                if(mindist > abs(factory[j][0] - robots[i])){
                    mindist = abs(factory[j][0] - robots[i]);
                    index = j;
                }
            }
        }
        if(index !=-1){
            factory[index][1]--;
        }
        totaldist+= mindist;
    }
    return totaldist;
}