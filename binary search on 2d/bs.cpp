#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int low =0;
    int high = m*n-1;
    while(low<=high){
        int mid = high + (low- high)/2;
        int i = mid/m;
        mid = mid % m;
        if(matrix[i][mid] == target) return true;
        else if(matrix[i][mid] < target) low = mid+1;
        else high = mid -1;
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>> arr(n,vector<int> (m));
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            int val;
            cout<< "enter value for"<< i<<"and"<<j;
            cin>>val;
            arr[i][j] = val;
        }
    }
    cout<< searchMatrix(arr,1);
}