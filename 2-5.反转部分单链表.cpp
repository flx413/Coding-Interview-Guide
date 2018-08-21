typedef struct Node {
    int value;
    Node* next;

    Node( int data ) {
        this.value = data;
    }
} Node;

Node* reversePart( Node* head, int from, int to ) {
    int len = 0;
    Node* node1 = NULL;
    Node* fPre = NULL;
    Node* tPos = NULL;
    while( node1 != NULL ) {
        len++;
        fPre = len == from - 1 ? node1 : fPre;
        tPos = len == to + 1 ? node1 : tPos;
        node1 = node1->next;
    }
    if( from > to || from < 1 || to > len ) return head;

    node1 = fPre == NULL ? head : fPre.next;
    Node* node2 = node1->next;
    node1>next = tPos;
    Node* next = NULL;
    while( node2 != tPos ) {
        next = node2->next;
        node2->next = node1;
        node1 = node2;
        node2 = next;
    }
    if( fPre != NULL ) {
        fPre->next = node1;
        return head;
    }
    return node1;
}
