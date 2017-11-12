/***
设计一个具有getMin功能的栈
***/

#include <cstdio>
#include <stack>

using namespace std;

class StackWithMin {
public:
    void push( int x );
    void pop();
    int top();
    bool empty();
    int getMin();

private:
    stack<int> stackData;
    stack<int> stackMin;
};

void StackWithMin::push( int x ) {
    stackData.push( x );
    if( stackMin.empty() ) {
        stackMin.push( x );
    }
    else {
        if( stackMin.top() >= x ) {
            stackMin.push( x );
        }
    }
}

void StackWithMin::pop() {
    if( stackData.empty() ) {
        printf( "the stack is empty!" );
    }
    else {
        int cur = stackData.top();
        stackData.pop();
        if( cur == stackMin.top() ) {
            stackMin.pop();
        }
    }
}

int StackWithMin::getMin() {
    if( stackData.empty() ) {
        printf( "the stack is empty!" );
    }
    else {
        return stackMin.top();
    }
}

int StackWithMin::top() {
    if( stackData.empty() ) {
        printf( "the stack is empty!" );
    }
    else {
        return stackData.top();
    }
}

bool StackWithMin::empty() {
    return stackData.empty();
}

int main() {
    StackWithMin s;

    s.push( 3 );
    s.push( 4 );
    s.push( 5 );
    s.push( 1 );
    s.push( 2 );
    s.push( 1 );
    s.pop();
    s.pop();
    s.pop();

    printf( "%d\n", s.getMin() );

    return 0;
}
