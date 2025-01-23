#include <sstream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "HELLO MY NAME IS TAKSH";
    stringstream ss(s);
    string word;
    while(ss >> word){
        cout<<word;
    }
    
}