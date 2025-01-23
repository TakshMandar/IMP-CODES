#include <bits/stdc++.h>
using namespace std;

bool f(string st){
    int n = st.length();
    stack<char> s;
    for(int i =0;i<n;i++){
        s.push(st[i]);
    }
    for(int i =0;i<n;i++){
        if(st[i] != st[n-i-1]) return false;
        s.pop();
    }
    return true;
}

int main(){
    string str = "boob";
    cout << f(str);
}