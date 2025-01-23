#include <bits/stdc++.h>
using namespace std;

void LPS(string pat, int M,vector<int>&lps){
    lps[0]= 0;
    int length =0;
    int i =1;
    while(i<M){
        if(pat[i] == pat[length]){
            lps[i] = length + 1;
            i++;
            length++;
        }
        else{
            
            if(length!=0) length=lps[length-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}
vector <int> search(string pat, string txt)
{
    int N = txt.length();
    int M = pat.length();
    vector<int> Lps(M);
    LPS(pat,M,Lps);
    int i = 0;
    int j =0;
    vector<int> result;
    while(i<N){
        if(txt[i] == pat[j]){
            i++;
            j++;
        }
        if(j==M){
            result.push_back(i-j);
            j = Lps[j-1];
        }
        else if(txt[i]!=pat[j]){
            if(j!=0){
                j = Lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    return result;
}