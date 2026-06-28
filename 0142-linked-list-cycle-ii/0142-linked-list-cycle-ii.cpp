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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slo = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            slo = slo->next;
            fast = fast->next->next;
            if(slo == fast) {
                slo = head;
                while(slo != fast) {
                    slo = slo->next;
                    fast = fast->next;
                }
                return slo;
            }
        }
        return NULL;
    }
};