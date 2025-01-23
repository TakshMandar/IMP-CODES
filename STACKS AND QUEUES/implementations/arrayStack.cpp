#include <bits/stdc++.h>
using namespace std;

class STACK{
private:
    int arr[1000];
    int top;
public:
    STACK(){
        top =-1;
    }
    void push(int x);
    void pop(){
        if(top == -1){
            cout<< "UNDERFLOW"<<endl;
            return;
        }
        int y = arr[top];
        top--;
        cout<< y<<endl;
        return;
    }
    void peek();
    bool isEmpty();
};
bool STACK::isEmpty(){
    if(top==-1) return true;
    return false;
}
void STACK::push(int x){
    if(top == 999) return;
    top = top+1;
    arr[top] = x;
    return;
}
void STACK::peek(){
    if(top ==-1){
        cout<<"no elements"<<endl;
        return;
    }
    cout<<arr[top]<<endl;
    return;
}

int main(){
    STACK st;
    st.push(3);
    st.peek();
    st.pop();
    st.push(2);
    st.push(5);
    st.pop();
    st.peek();
    cout<<st.isEmpty();
    return 0;;
}