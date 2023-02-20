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

    Stack s;
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

    string t;
    cin >> t;
    
    for( int i = 0; i < t.length(); i++ ){      // the difference between this and prefix
                                                // evaluation is traverse should be used from first
        if( t[i] >= '0' and t[i] <= '9' ){
            s.push( t[i] - '0' );
        }
        else{
            int op2 = s.peek();     // here will be op1 in in prefix evaluation
            s.pop();
            int op1 = s.peek();
            s.pop();

            switch ( t[i] )
            {
            case '+':
                s.push( op1 + op2 );
                break;
            case '-':
                s.push( op1 - op2 );
                break;
            case '*':
                s.push( op1 * op2 );
                break;
            case '/':
                s.push( op1 / op2 );
                break;
            case '^':
                s.push( pow(op1 , op2 ));
                break;
            }
        }
    }
    cout << s.peek() << endl;
    
    // 46+2/5*7+
    // ans is 32
    
    return 0;
}