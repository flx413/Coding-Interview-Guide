#include <iostream>
#include <stack>

#define ERROR -10000

using namespace std;

class myQueue {
    public:
        void add( int x );
        int poll();
        int peek();
    private:
        stack<int> s1;
        stack<int> s2;
};

void myQueue::add( int x ) {
    s1.push( x );
}

int myQueue::poll() {
    int res;
    res = peek();

    if( res != ERROR ) {
        s2.pop();
    }

    return res;
}

int myQueue::peek() {
    int res;
    if( !s2.empty() ) {
        res = s2.top();
    }
    else {
        if( s1.empty() ) {
            printf( "the queue is empty!\n" );
            return ERROR;
        }
        else {
            while( !s1.empty() ) {
                int cur = s1.top();
                s1.pop();
                s2.push( cur );
            }
            res = s2.top();
        }
    }

    return res;
}

int main() {
    myQueue q;
    q.add( 1 );
    q.add( 2 );
    q.add( 3 );
    printf( "%d\n", q.peek() );
    q.poll();
    printf( "%d\n", q.peek() );
    q.poll();
    q.add( 5 );
    q.add( 6 );
    printf( "%d\n", q.peek() );
    q.poll();
    printf( "%d\n", q.peek() );
    q.poll();
    printf( "%d\n", q.peek() );

    return 0;
}
