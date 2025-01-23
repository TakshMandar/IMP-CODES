#include <bits/stdc++.h>
using namespace std;

int prims(int n,vector<vector<int>> adj[],vector<vector<int>> MST[]){
    priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
    vector<int> vis(n,0);
    int sum = 0;
    pq.push({0,{0,-1}}); // {wt,{node,parent}}
    while(!pq.empty()){
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop();
        if(vis[node] == 1) continue;
        vis[node] = 1;
        MST[parent].push_back({node,wt});
        MST[node].push_back({parent,wt});
        sum+= wt;
        for(auto it:adj[node]){
            int adjNode = it[0];
            int edW = it[1];
            if(!vis[adjNode]) pq.push({edW,{adjNode,node}});
        }
    }
    return sum;
}

//TC-->O(ELOGE)
//SC-->O(E)
//GREEDY SHIT