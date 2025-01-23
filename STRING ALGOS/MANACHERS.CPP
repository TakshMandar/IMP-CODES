#include <bits/stdc++.h>
using namespace std;


vector<int> ManacherOdd(const string&s){
    int n = s.size();
    //marking the boundaries with these $ ans ^
    string modifiedstr = '$' + s +'^';
    vector<int> p(n+2);
    int leftboundary = 1, rightboundary = 1;
    for(int i = 0;i<n;i++){
        //this first line is for in the case of ababa here look at the second b the lB = 0 and rB = n-1 so dekhle
        p[i] = max(0, min(rightboundary - i, p[leftboundary + rightboundary - i]));
        //increase the radius from the centre with this oone
        while (modifiedstr[i - p[i]] == modifiedstr[i + p[i]]) {
            p[i]++;
        }
        // icreasing boundary if radius got increased
        if (i + p[i] > rightboundary) {
            leftboundary = i - p[i];
            rightboundary = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1); // removing the $ and ^
}

//in case of even length first transform
string transformString(const string& s) {
    int n = s.length();
    string transformedStr(2 * n + 1, '#');
    for (int i = 0; i < n; i++) {
        transformedStr[2 * i + 1] = s[i];
    }
    return transformedStr;
}