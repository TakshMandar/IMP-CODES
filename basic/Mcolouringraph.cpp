#include <bits/stdc++.h>
using namespace std;

bool isSafe(int color, int node){
    for(auto it:adj[node]){
        if(vis[it] ==color){
            return false;
        }
    }
    return true;
}
void f(node){
    if(node==0){
        allvisited;
        return true;
    }
        for(int col =0;col<m;j++){
            if(isSafe(col,i)){
                vis[i] = col;
                if(f(node+1))return true;
                else{
                    vis[i] = -1;
                }
            }
        }
        return false;

}