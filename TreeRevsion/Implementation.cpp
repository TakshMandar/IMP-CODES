#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = nullptr;
    }
    Node(int val, Node* left , Node* right){
        data = val;
        this->left = left;
        this->right = right;
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    cout<<"works";
    root->right = new Node(3);
    return 0;
}