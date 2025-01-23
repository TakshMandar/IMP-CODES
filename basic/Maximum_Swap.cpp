#include <bits/stdc++.h>
using namespace std;

int f(int x){
    string s = to_string(x);
    int n = s.length();
    priority_queue<pair<char,int>> pq;
    for(int i =0;i<n;i++){
        pq.push({s[i] , i});
    }
    for(int i =0;i<n;i++){
        char x = pq.top().first;
        cout<<(x-48)<<" ";
        int ind = pq.top().second;
        if(x > s[i] && i < ind){
            swap(s[ind],s[i]);
            break;
        }
        if(i<ind) pq.push({x,ind});
        pq.pop();
    }
    const string str = s;
    int ans = stoi(str);
    return ans;

}
int maximumSwap(int num) {
    string st = to_string(num);
    int n = st.size();
    priority_queue<pair<char, int>> pq;
    for(int i = 0; i < n; i++)
    {
        pq.push({st[i], i});
    }
    for(int j = 0; j < n; j++)
    {
        while(! pq.empty() && pq.top().second < j){
            pq.pop();
        }
        if(pq.top().first > st[j])
        {
            swap(st[j], st[pq.top().second]);
            break;
        }            
    }
    return stoi(st);
}

int main(){
    int x = 99901;
    cout<< maximumSwap(x);
}