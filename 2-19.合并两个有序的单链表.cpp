#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    Node *next;
    Node(int v) : val(v) { next = NULL; }
};

Node* Merge(Node *head1, Node *head2)
{
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node *head = NULL;
    Node *pre = NULL;
    Node *p1 = head1;
    Node *p2 = head2;
    if (p1->val > p2->val)
    {
        head = p2;
        pre = p2;
        p2 = p2->next;
    }
    else
    {
        head = p1;
        pre = p1;
        p1 = p1->next;
    }

    while (NULL != p1 && NULL != p2)
    {
        if (p1->val > p2->val)
        {
            pre->next = p2;
            pre = p2;
            p2 = p2->next;
        }
        else
        {
            pre->next = p1;
            pre = p1;
            p1 = p1->next;
        }
    }

    if (NULL != p1) pre->next = p1;
    if (NULL != p2) pre->next = p2;

    return head;
}

void PrintList(Node *head)
{
    Node *p = head;
    while (NULL != p)
    {
        printf("%d ", p->val);
        p = p->next;
    }
}
int main() {
    Node *node1_1 = new Node(1);
    Node *node1_2 = new Node(2);
    Node *node1_3 = new Node(3);
    Node *node1_4 = new Node(4);
    Node *node1_5 = new Node(5);

    Node *node2_1 = new Node(0);
    Node *node2_2 = new Node(3);
    Node *node2_3 = new Node(4);
    Node *node2_4 = new Node(7);
    Node *node2_5 = new Node(10);

    node1_1->next = node1_2;
    node1_2->next = node1_3;
    node1_3->next = node1_4;
    node1_4->next = node1_5;

    node2_1->next = node2_2;
    node2_2->next = node2_3;
    node2_3->next = node2_4;
    node2_4->next = node2_5;

    Node *head1 = node1_1;
    Node *head2 = node2_1;
    Node *head = Merge(head1, head2);
    PrintList(head);
    
    return 0;
}