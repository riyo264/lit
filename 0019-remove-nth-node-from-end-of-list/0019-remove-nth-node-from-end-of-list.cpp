/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = 0;
        ListNode* temp = head;
        while(temp) {
            l++;
            temp = temp->next;
        }
        int node = l - n;
        temp = head;
        if(node == 0) {
            return head->next;
        }
        int c = 1;
        int pointer = 0;
        while(temp) {
            if(c != node) {
                temp = temp->next;
                c++;
                continue;
            }
            ListNode* m = temp->next;
            temp->next = m->next;
            m->next = nullptr;
            break;
        }
        return head;
    }
};