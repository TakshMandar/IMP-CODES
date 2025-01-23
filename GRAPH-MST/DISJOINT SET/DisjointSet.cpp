#include<bits/stdc++.h>
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

int main(){
    DisjointSet ds(7);
    ds.UnionbyRank(1,2);
    ds.UnionbyRank(2,3);
    ds.UnionbyRank(4,5);
    ds.UnionbyRank(6,7);
    ds.UnionbyRank(5,6);

    if(ds.findUparent(3) == ds.findUparent(7)) cout<<"Same";
    else cout<<"Not same"<<endl;
    ds.UnionbyRank(3,7);

    if(ds.findUparent(3) == ds.findUparent(7)) cout<<"Same";
    else cout<<"Not same";
    return 0;
}