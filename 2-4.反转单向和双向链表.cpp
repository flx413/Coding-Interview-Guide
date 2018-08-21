typedef struct Node {
    int value;
    Node* next;

    Node( int data ) {
        this.value = data;
    }
} Node;

Node* reverseList( Node* head ) {
    Node* pre = NULL;
    Node* next = NULL;
    while( head != NULL ) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }

    return pre;
}



typedef struct DoubleNode {
    int value;
    DoubleNode* next;
    DoubleNode* last;
    DoubleNode( int data ) {
        this.value = data;
    }
} DoubleNode;

DoubleNode* reverseList( DoubleNode* head ) {
    DoubleNode* pre = NULL;
    DoubleNode* next = NULL;
    while( head != NULL ) {
        next = head->next;
        head->next = pre;
        head->last = next;
        pre = head;
        head = next;
    }

    return pre;
}
