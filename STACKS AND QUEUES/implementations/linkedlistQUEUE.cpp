#include <bits/stdc++.h>
using namespace std;
//rear ->insert it points at the top;
//front-> pop it points at the first element inserted;
class Node{
public:
    int data;
    Node* next;
public:
    Node(int dat){
        data = dat;
        next = nullptr;
    }
};
class QUEUE{
public:
    Node* front;
    Node *rear;
    int currsize;
public:
    QUEUE(){
        front = NULL;
        rear = NULL;
        currsize = 0;
    }
    void Enqueue(int x);
    void Dequeue();
    bool empty();
    int peek();
};

bool QUEUE::empty(){
    return front == NULL;
}

void QUEUE::Enqueue(int x){
    Node* temp = new Node(x);
    if(temp ==NULL){
        cout<< "heap is exhausted"<<endl;
    }
    else{
        if(front == nullptr){
            front = temp;
            rear = temp;
        }
        else{
            rear->next = temp;
            rear = temp;
        }
        cout<<x<<"Inserted into queue"<<endl;
        currsize++;
    }
}

void QUEUE::Dequeue(){
    if(front == nullptr){
        cout<<"Queue is empty bitch"<<endl;
        return;
    }
    int u = front->data;
    Node* temp = front;
    front = front->next;
    currsize--;
    delete temp;
    cout<<"element removed"<<u<<endl;
    return;
}

int QUEUE::peek(){
    if(empty()){
        cout<<"QUEUE IS EMPTY"<<endl;
        return -1;
    }
    return front->data ;
}

int main(){
    QUEUE qt;
    qt.Enqueue(2);
    qt.Enqueue(3);
    qt.Enqueue(6);
    qt.Dequeue();
    cout<<qt.peek()<<endl;
    cout<<qt.empty();
}