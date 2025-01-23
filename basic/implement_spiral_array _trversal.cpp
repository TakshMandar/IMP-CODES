#include <bits/stdc++.h>
using namespace std;

void f(vector<vector<int>> arr){
    int n= arr.size();
    int m = arr[0].size();
    int top=0, bottom = n-1, left = 0, right = m-1;
    while(left<=right && top<=bottom){
        for(int i =left;i<=right;i++){
            cout<<arr[top][i];
        }
        top++;
        for(int i = top;i<=bottom;i++){
            cout<<arr[i][right];
        }
        right--;
        if(top<=bottom){
            for(int i =right;i>=left;i--){
                cout<< arr[bottom][i];
            }
            bottom--;
        }
        if(left<=right){
            for(int i =bottom ;i>=top;i--){
                cout<<arr[i][left];
            }
            left++;
        }
    }
}

int main(){
    vector<vector<int>> arr ={{1,2,3},{8,9,4},{7,6,5}};
    f(arr);
}