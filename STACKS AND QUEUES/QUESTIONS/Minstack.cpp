#include <bits/stdc++.h>
using namespace std;
//TC-O(1) SC->O(2xn)
class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
    }
    
    void push(int val) {
       if(st.empty()){
        st.push({val,val});
       }
       else{
        st.push({val,min(val,st.top().second)});
       }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        int x =st.top().first;
        return x;
    }
    
    int getMin() {
        if(st.empty()){
            return -1;
        }
        return st.top().second;
    }
};

