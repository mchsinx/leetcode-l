/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode *ph = &head;
        ListNode *p = ph;
        int cint = 0;
    
        while(l1 || l2 || cint) {
            if(l1) {
                cint += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                cint += l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(cint % 10);
            p = p->next;
            cint /= 10;
        }

        return ph->next;
    }
};
