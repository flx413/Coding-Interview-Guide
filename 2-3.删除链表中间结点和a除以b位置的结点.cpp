typedef struct Node {
    int value;
    Node* next;

    Node( int data ) {
        this.value = data;
    }
} Node;

Node* removeMidNode( Node* head ) {
    if( head == NULL || head->next == NULL ) {
        return head;
    }
    if( head->next->next == NULL ) {
        return head->next;
    }

    Node* pre = head;
    Node* cur = head->next->next;
    while( cur->next != NULL && cur->next->next != NULL ) {
        pre = pre->next;
        cur = cur->next->next;
    }
    Node* mid = pre->next;
    pre->next = pre->next->next;
    delete mid;
    mid = NULL;

    return head;
}

Node* removeByRatio( Node* head, int a, int b ) {
    if( a < 1 || a > b ) return head;

    int len = 0;
    Node* cur = head;
    while( cur != NULL ) {
        len++;
        cur = cur->next;
    }

    int pos = (int)ceil( ((double)( a * n ) ) / (double)b );
    if( pos == 1 ) {
        head = head->next;
    }
    else if( pos > 1 ) {
        cur = head;
        while( --pos != 1 ) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
    }

    return head;
}
