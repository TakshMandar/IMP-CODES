#include <bits/stdc++.h>
using namespace std;

class QUEUE{
    int * arr;
    int maxsize, cursize, front, rear;
    QUEUE(){
        maxsize = 16;
        arr = new int[16];
        cursize = 0;
        front =-1;
        rear =-1;
    }
public:
    QUEUE(int max){
        maxsize = max;
        arr = new int[maxsize];
        cursize = 0;
        front =-1;
        rear =-1;
    }
    void push(int x);
    void pop();
    void top();
};

void QUEUE::top(){
    if(cursize == 0){
        cout<<"empty shit"<<endl;
        return;
    }
    cout<< arr[front]<<endl;
    return;
}

void QUEUE::push(int x){
    if(cursize == maxsize-1){
        cout<<"OVERFLOW BITCH";
        return;
    }
    if(front ==-1){
        rear=0;
        front=0;
        arr[front] = x;
        cursize++;
        return;
    }
    front = (front+1)%maxsize;
    arr[front]=x;
    cursize++;
    return;
}

void QUEUE::pop(){
    if(rear == -1){
        cout<<"UNDERFLOW"<<endl;
        return;
    }
    int y = arr[rear];
    if(cursize==1){
        rear = -1;
        front =-1;
    }
    else rear = (rear+1)%maxsize;
    cursize--;
    cout<<y<<endl;
}

int main(){
    QUEUE qt(5);
    QUEUE* qt2 = new QUEUE(100);
    qt.push(3);
    qt.push(4);
    qt.push(2);
    qt.top();
    qt.pop();
    qt.pop();
    qt.pop();
    qt.top();
    qt.push(3);
    qt.push(4);
    qt.push(2);
    qt.push(3);
    qt.push(4);
    qt.push(2);

    queue<int> q;
    q.push(1);
    q.push(2);
    cout<<q.front();
}