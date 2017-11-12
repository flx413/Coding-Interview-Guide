/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        ListNode* cur = head;
        while( cur != NULL ) {
            n--;
            cur = cur->next;
        }

        if( n > 0 ) return NULL;
        if( n == 0 ) return head->next;

        cur = head;
        n++;    // ÏÈÈÃn×Ô¼Ó1
        while( n < 0 ) {
            cur = cur->next;
            n++;
        }
        ListNode* next = cur->next;
        cur->next = next->next;

        delete next;

        return head;
    }
};


