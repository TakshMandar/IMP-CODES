#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V , vector<vector<int>> adj[],int sr){
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    pq.push({0,0});
    vector<int> dist(V,1e9);
    dist[sr] = 0;
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it: adj[node]){
            int edgeweight = it[1];
            int adjnode = it[0];
            if(dis+edgeweight < dist[adjnode]){
                dist[adjnode] = dis + edgeweight;
                pq.push({dist[adjnode] , adjnode});
            }
        }
    }
    return dist;
}