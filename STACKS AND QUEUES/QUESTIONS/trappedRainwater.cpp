#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int l =0;
        int r = n-1;
        int Lmax,Rmax, total =0;
        while(l<r){
            if(arr[l]<=arr[r]){
                if(Lmax>arr[l]){
                    total += Lmax - arr[l];
                }
                else{
                    Lmax = arr[l];
                }
                l++;
            }
            else{
                if(Rmax>arr[r]){
                    total+= Rmax - arr[r];
                }
                else{
                    Rmax = arr[r];
                }
                r--;
            }
        }
        return total;
    }
};