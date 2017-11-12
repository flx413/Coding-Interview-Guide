#include <iostream>
#include <stack>

using namespace std;

void stackSort( stack<int> &s ) {
    stack<int> help;
    while( !s.empty() ) {
        int cur = s.top();
        s.pop();
        while( !help.empty() && cur > help.top() ) {
                int top = help.top();
                help.pop();
                s.push( top );
        }
        help.push( cur );
    }

    while( !help.empty() ) {
        s.push( help.top() );
        help.pop();
    }
}

void printStack( stack<int> &s ) {
    while( !s.empty() ) {
        printf( "%d\n", s.top() );
        s.pop();
    }
}

int main() {
    stack<int> stackData;

    stackData.push( 3 );
    stackData.push( 2 );
    stackData.push( 1 );
    stackData.push( 5 );
    stackData.push( 4 );

    stackSort( stackData );

    printStack( stackData );

    return 0;
}
