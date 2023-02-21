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

string infixToprefix( string s ){

    Stack st;

    reverse( s.begin() , s.end() );     // have to reverse the string
    string res;

    for( int i = 0; i < s.size(); i++ ){
        if( ( s[i] >= 'a' and s[i] <= 'z' ) or ( s[i] >= 'A' and s[i] <= 'Z' ) ){
            res += s[i];
        }
        else if( s[i] == ')' ){         // assume close bracket -> open bracket
            st.push( s[i] );
        }
        else if( s[i] == '(' ){         // assume open bracket -> close bracket
            while( !st.isEmpty() and st.peek() != ')' ){    // also assume close -> open
                res += st.peek();
                st.pop();
            }
            if( !st.isEmpty() ){
                st.pop();
            }
        }
        else{
            while( !st.isEmpty() and precident( st.peek() ) >= precident( s[i] )){
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
    reverse( res.begin() , res.end() );     // have to return the reverse string
    return res;
}

int main(){

    //Stack st;
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
    cin >> s;                           // same as infix to postfix

    // reverse( s.begin() , s.end() );     // have to reverse the string
    // string res;

    // for( int i = 0; i < s.size(); i++ ){
    //     if( ( s[i] >= 'a' and s[i] <= 'z' ) or ( s[i] >= 'A' and s[i] <= 'Z' ) ){
    //         res += s[i];
    //     }
    //     else if( s[i] == ')' ){         // assume close bracket -> open bracket
    //         st.push( s[i] );
    //     }
    //     else if( s[i] == '(' ){         // assume open bracket -> close bracket
    //         while( !st.isEmpty() and st.peek() != ')' ){    // also assume close -> open
    //             res += st.peek();
    //             st.pop();
    //         }
    //         if( !st.isEmpty() ){
    //             st.pop();
    //         }
    //     }
    //     else{
    //         while( !st.isEmpty() and precident( st.peek() ) >= precident( s[i] )){
    //             res += st.peek();
    //             st.pop();
    //         }
    //         st.push( s[i] );
    //     }
    // }
    // while( !st.isEmpty() ){
    //     res += st.peek();
    //     st.pop();
    // }
    // reverse( res.begin() , res.end() );     // have to reverse the resulting string

    cout << infixToprefix( s ) << endl;

    // input   (a-b/c)*(a/k-l)
    // output   *-a/bc-/akl
    return 0;
}
