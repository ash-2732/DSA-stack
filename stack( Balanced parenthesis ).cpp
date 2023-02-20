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
            free( temp );
        }
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
    // s.push( 11 );
    // s.push( 22 );
    // s.push( 33 );
    // s.push( 44 );

    // s.Display();

    // cout << endl;
    // cout << s.peek() << endl;

    // s.pop();
    // s.pop();

    // s.Display();
    // cout << endl;
    // cout << s.peek() << endl;

    // s.pop();
    // s.pop();
    // //cout << s.peek() << endl;
    // if( s.isEmpty() ) cout << "Hello" << endl;
    // else cout << "Hi" << endl;

    string s;
    cin >> s;

    for( int i = 0; i < s.size(); i++ ){

        if( s[i] == '(' or s[i] == '{' or s[i] == '[' ){
            st.push( s[i] );
        }
        if( st.isEmpty() ){
            cout << "Imbalanced" << endl;
            return 0;
        }
        else{
            if( s[i] == ')' and st.peek() == '(' ) st.pop();
            if( s[i] == '}' and st.peek() == '{' ) st.pop();
            if( s[i] == ']' and st.peek() == '[' ) st.pop();
        }
    }
    if( st.isEmpty() ) cout << "Balanced" << endl;
    else cout << "Imbalanced" << endl;

    return 0;
}
