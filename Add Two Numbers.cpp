#include <iostream>
using namespace std;

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

int main() {
    std::cout << "Hello, World!" << std::endl;
    ListNode *l1 = new ListNode(9);
    ListNode *p1 = l1;
    ListNode *tmp = new ListNode(2);
    p1->next = tmp;
    p1 = p1->next;
    p1->next = new ListNode(7);
    p1 = p1->next;

    ListNode *l2 = new ListNode(5);
    ListNode *p2 = l2;
    p2->next = new ListNode(9);
    p2 = p2->next;
    p2->next = new ListNode(8);
    p2 = p2->next;

    p1 = p2 = nullptr;

    auto rst = addTwoNumbers(l1,l2);
    while(rst!= nullptr) {
        auto tmp = rst;
        rst = rst->next;
        delete(tmp);
    }
    return 0;
}
