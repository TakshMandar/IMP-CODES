#include <bits/stdc++.h>
using namespace std;

int f(string s1,string t,int ind1,int n,string s){
    if(ind1 == n){
        if(s == t) return 1;
        else return 0;
    }
    int take = f(s1,t,ind1+1,n,s+s1[ind1]);
    int nottake = f(s1,t,ind1+1,n,s);
    return take + nottake;
}

int main(){
    string s1 = "rabbbit";
    int n = s1.length();
    string t = "rabbit";
    string s = "";
    cout<< f(s1,t,0,n,s);
}