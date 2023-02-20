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

int precident( char c ){
    if( c == '^' ) return 3;
    else if( c == '*' or c == '/' ) return 2;
    else if( c == '+' or c == '-' ) return 1;
    else return -1;
}
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
    string res;

    for( int i = 0; i < s.size(); i++ ){
        if( ( s[i] >= 'a' and s[i] <= 'z' ) or ( s[i] >= 'A' and s[i] <= 'Z' ) ){
            res += s[i];
        }
        else if( s[i] == '(' ){
            st.push( s[i] );
        }
        else if( s[i] == ')' ){
            while( !st.isEmpty() and st.peek() != '(' ){
                res += st.peek();
                st.pop();
            }
            if( !st.isEmpty() ){
                st.pop();
            }
        }
        else{
            while( !st.isEmpty() and precident( st.peek()) > precident( s[i] )){
                res += st.peek();
                st.pop();
            }
            st.push( s[i] );
        }
    }
    while( !st.isEmpty() ){
        res += st.peek();
        st.pop();
    }
    cout << res << endl;
    
    // input     (a-b/c)*(a/k-l)
    // output     abc/-ak/l-*
    return 0;
}
