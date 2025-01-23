#include <bits/stdc++.h>
using namespace std;

void dfs(int node , vector<int>&vis , vector<int> adj[]){
    vis[node] = 1;
    cout<<node<<" ";
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, vis, adj);
        }
    }
}

int main(){
    int n;
    cout<<"enter number of vertices :";
    cin>>n;
    cout<<endl;
    cout<<"enter number of edges :" ;
    int m;
    cin>>m;
    cout<<endl;
    vector<int> vis(n,0);
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u;
        int v;
        cout<<"enter u :";
        cin>>u;
        cout<<"enter v :";
        cin>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i =0;i<n;i++){
        if(!vis[i]){
            cout<<"Component :";
            dfs(i,vis,adj);
            cout<<endl;
        }
    }
}