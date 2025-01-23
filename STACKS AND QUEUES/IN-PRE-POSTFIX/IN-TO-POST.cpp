#include <bits/stdc++.h>
using namespace std;

string Intopost(string s){
    stack<char> st;
    string ans ="";
    int i =0;
    int n = s.length();
    while(i<n){
        if((s[i] >='A' and s[i] <='Z') or (s[i] >='a' and s[i]<='z') or (s[i] >='0' and s[i] <='9')){
            ans = ans +s[i];
        }
        else if(s[i] =='('){
            st.push(s[i]);
        }
        else if(s[i] ==')'){
            while(!st.empty() && st.top() != '('){
                ans+=st.top();
                st.pop();
            }
            st.pop(); //pop the opening bracket
        }
        else{
            //operator
            while(!st.empty() && priority(s[i]) <= priority(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    return ans;
}