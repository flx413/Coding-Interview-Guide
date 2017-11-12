/***
仅用递归函数和栈操作
实现栈的逆序
***/

#include <iostream>
#include <stack>

using namespace std;

int getAndRemoveLastElement( stack<int> &s ) {
    int result = s.top();
    s.pop();

    if( s.empty() ) {
        return result;
    }
    else {
        int last = getAndRemoveLastElement( s );
        s.push( result );
        return last;
    }
}

void reverse( stack<int> &s ) {
    if( s.empty() ) {
        return;
    }
    else {
        int i = getAndRemoveLastElement( s );
        reverse( s );
        s.push( i );
    }
}

int main() {
    stack<int> s;
    s.push( 1 );
    s.push( 2 );
    s.push( 3 );

    reverse( s );

    while( !s.empty() ) {
        printf( "%d\n", s.top() );
        s.pop();
    }

    return 0;
}
