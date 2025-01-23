#include <bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> parent,rank,size;
public:
    DisjointSet(int n ){
        //resize so that is works for both 1 based and 0 based indexing graphs
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i = 0 ; i <=n ; i++){
            parent[i] = i;
        }
    }

    int findUparent(int n){
        if(n == parent[n]){
            return n;
        }
        return parent[n] = findUparent(parent[n]);
    }

    void UnionbyRank(int u,int v){
        int Up_u = findUparent(u);
        int Up_v = findUparent(v);
        if(Up_u==Up_v) return;
        if(rank[Up_u] > rank[Up_v]){
            parent[Up_v] = Up_u;
        }
        else if(rank[Up_u] < rank[Up_v]){
            parent[Up_u] = Up_v;
        }
        else{
            parent[Up_u] = Up_v;
            rank[Up_v]++;
        }
    }

    void UnionbySize(int u,int v){
        int Up_u = findUparent(u);
        int Up_v = findUparent(v);
        if(Up_u==Up_v) return;
        if(size[Up_v] > size[Up_u]){
            parent[Up_u] = Up_v;
            size[Up_v] += size[Up_u];
        }
        else{
            parent[Up_v] = Up_u;
            size[Up_u] += size[Up_v];
        }
    }
};
int spanningTree(int V, vector<vector<int>> adj[]){
    vector<pair<int,pair<int,int>>> edges;
    int MST_wt;
    for(int i = 0;i<V;i++){
        for(auto it: adj[i]){
            int adjNode = it[0];
            int wt = it[1];
            int node = i;
            edges.push_back({wt,{node,adjNode}});
        }
    }
    DisjointSet ds(V);
    sort(edges.begin(),edges.end());
    for(auto it:edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if(ds.findUparent(u) != ds.findUparent(v)){
            MST_wt+=wt;
            ds.UnionbySize(u,v);
        }
    }
    return MST_wt;
}
/*
Time Complexity: O(N+E) + O(E logE) + O(E*4α*2)   where N = no. of nodes and E = no. of edges. O(N+E) for extracting edge information from the adjacency list. O(E logE) for sorting the array consists of the edge tuples. Finally, we are using the disjoint set operations inside a loop. The loop will continue to E times. Inside that loop, there are two disjoint set operations like findUPar() and UnionBySize() each taking 4 and so it will result in 4*2. That is why the last term O(E*4*2) is added.

Space Complexity: O(N) + O(N) + O(E) where E = no. of edges and N = no. of nodes. O(E) space is taken by the array that we are using to store the edge information. And in the disjoint set data structure, we are using two N-sized arrays i.e. a parent and a size array (as we are using unionBySize() function otherwise, a rank array of the same size if unionByRank() is used) which result in the first two terms O(N).
*/
