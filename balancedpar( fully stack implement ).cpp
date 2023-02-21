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

int maxiumdepth( string s ){
    Stack st;

    int maxdepth = 0;
    for( int i = 0; i < s.size(); i++ ){
        if( s[i] == '(' ){
            st.push( s[i] );
            if( st.size() > maxdepth ){
                maxdepth = st.size();
            }
        }
        if( s[i] == ')' ){
            st.pop();
        }
    }
    return maxdepth;
}

int main(){

    //Stack st;
    string s;
    cin >> s;

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

    cout << maxiumdepth( s ) << endl;

    return 0;
}
