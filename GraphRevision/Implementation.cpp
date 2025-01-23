#include <bits/stdc++.h>
using namespace std;

void bfs(int V,vector<int>& bfs,vector<int> adj[]){
    vector<int> vis(V,0);
    vis[0]=1;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
}
void addedge(int u ,int v , vector<int> adj[]){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    vector<int> BFS;
    vector<int> adj[5];
    for(auto it: BFS){
        cout<<it<<" ";
    }
    addedge(0,1,adj);
    addedge(1,2,adj);
    addedge(1,3,adj);
    addedge(0,4,adj);
    bfs(5,BFS,adj);
    for(auto it: BFS){
        cout<<it<<" ";
    }
}