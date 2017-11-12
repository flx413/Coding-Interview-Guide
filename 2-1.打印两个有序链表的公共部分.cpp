/***
打印两个有序链表的公共结点
只给出了函数实现过程
***/

typedef struct node {
    node( int v ) {
        this.val = v;
    }
    int val;
    struct node* next;
} Node;

void printCommonPart( Node* head1, Node* head2 ) {
    Node* p1 = head1;
    Node* p2 = head2;

    while( p1 && p2 ) {
        if( p1->val == p2->val ) {
            printf( "%d\n", p1->val );
            p1 = p1->next;
            p2 = p2->next;
        }
        else if( p1->val < p2->val ) {
            p1 = p1->next;
        }
        else {
            p2 = p2->val;
        }
    }
}

