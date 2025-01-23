#include <bits/stdc++.h>
using namespace std;

//You are given an array of integer val[] and a target value your task is to find all unique pairs pf integers in the array whose absolute diff
//is equal to the target . The soln should involve first sorting the array and then apply a search stratergy to find the pairs..

//quick sort;


int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

void func(vector<int>& arr,int n,int target){
    qs(arr,0,n-1);
    int i = 0;
    int j = 1;
    set<pair<int,int>> se;
    while(i<n && j<n){
        int diff = abs(arr[j]-arr[i]);
        if(i!=j && diff == target && se.find({arr[i],arr[j]}) == se.end()){
            se.insert({arr[i],arr[j]});
            i++;
            j++;
        }
        else if(diff<target){
            j++;
        }
        else{
            i++;
        }
    }
    for(auto it:se){
        cout<<'{'<<it.first<<','<<it.second<<'}'<<endl;
    }
}

int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    vector<int> arr(n);
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"enter target";
    cin>>target;
    func(arr,n,target);
}