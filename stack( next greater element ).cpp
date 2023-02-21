#include<bits/stdc++.h>
using namespace std;


class node{

    public:
    int data;
    node *next;

    node( int n ){
        data = n;
        next = NULL;
    }
};

class Stack{

    node *top;
    public:

    Stack(){
        top = NULL;
    }

    void push( int data ){
        node *temp = new node( data );
        if( !temp ){
            cout << "Stack Overflow" << endl;
            exit(1);
        }
        temp -> data = data;
        temp -> next = top;
        top = temp;
    }

    bool isEmpty(){
        return top == NULL;
    }

    int peek(){
        if( !isEmpty() ) return top -> data;
        else exit(1);
    }

    void pop(){
        node *temp;
        if( top == NULL ){
            cout << "Stack Underflow" << endl;
            exit(1);
        }
        else{
            temp = top;
            top = top -> next;
            delete temp;
            // free( temp );   also we can use it
        }
    }

    int size(){
        vector< int > current_stack;
        node *temp;
        if( top == NULL ){
            cout << "Stack Underflow" << endl;
        }
        else{
            temp = top;
            while( temp != NULL ){
                //cout << temp -> data;
                current_stack.push_back( temp -> data );
                temp = temp -> next;
                // if( temp != NULL ){
                //     cout << "->";
                // }
            }
        }
        return current_stack.size();
    }

    void Display(){
       node *temp;
        if( top == NULL ){
            cout << "Stack Underflow" << endl;
        }
        else{
            temp = top;
            while( temp != NULL ){
                cout << temp -> data;
                temp = temp -> next;
                if( temp != NULL ){
                    cout << "->";
                }
            }
        } 
    }
};

int main(){

    Stack st;
    // string s;
    // cin >> s;

    // st.push('(');
    // st.push(')');
    // st.push('(');
    // cout << st.Display() << endl;
    // st.pop();
    // // st.Display();
    // cout << st.Display() << endl;
    // st.pop();
    // cout << st.Display() << endl;
    // st.pop();
    // cout << st.Display() << endl; 

    int n; cin >> n;
    vector< int > element(n);

    for( int i = 0; i < n; i++ ) cin >> element[i];
    st.push( element[0] );
    for( int i = 1; i < n; i++ ){
        if( st.isEmpty() ){
            st.push( element[i] );
            continue;
        }
        while( st.isEmpty() == false and st.peek() < element[i] ){
            cout << st.peek() <<" -> " << element[i] << endl;
            st.pop();
        }
        st.push( element[i] );
    }
    while( st.isEmpty() == false ){
        cout << st.peek() <<" -> " << "-1" << endl;
        st.pop();
    }
    
    // input
    //  4
    //  4 5 2 25
    //  output
    //  4 -> 5
    //  2 -> 25
    //  5 -> 25
    //  25 -> -1
    
    return 0;
}
