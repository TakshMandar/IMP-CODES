#include <bits./stdc++.h>
using namespace std;

struct Node{
public:
    int data;
    Node* next;
public:
    Node(int d){
        data = d;
        next = NULL;
    }
};

struct Stack{
    Node* top;
    int size;
public:
    Stack(){
        top = NULL;
        size =0;
    }
    void push(int x){
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        cout<< "element pushed"<<endl;
        size++;
    }
    int pop(){
        if(top == NULL) return -1;
        Node* temp = top;
        int data = top->data;
        top = top->next;
        delete(temp);
        size--;
        return data;
    }
    void peak(){
        if(top == NULL) return;
        cout<<top->data;
    }
    void printStack(){
        Node* curr = top;
        while(curr !=nullptr){
           cout<<curr->data;
           curr = curr->next;
        }
        return;
    }
};
