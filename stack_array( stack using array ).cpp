#include<bits/stdc++.h>
int const n = 100;
using namespace std;


class Stack{
    int *element;
    int top;
    public:
    Stack(){
        element = new int[n];
        top = -1;
    }
    void push( int x ){
        if( top == n-1 ){
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        element[top] = x;
    }
    void pop(){
        if( top == -1 ){
            cout << "No element to pop" << endl;
            return;
        }
        top--;
    }
    int peek(){
        if( top == -1 ){
            cout << "No element in stack" << endl;
            return -1;
        }
        return element[top];
    }
    bool Empty(){
        return top == -1;
    }
};

int main(){

    Stack st;
    st.push( 1 );
    st.push( 2 );
    st.push( 3 );
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << st.Empty() << endl;
    
    // output
    //    3
    //    2
    //    No element to pop
    //    1
    return 0;
}
