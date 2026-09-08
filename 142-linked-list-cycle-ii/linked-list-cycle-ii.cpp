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
        if(head == nullptr)
        return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast) {
                slow = head;
                while(true) {
                    if(slow == fast) {
                        return slow;
                    }
                    slow = slow->next;
                    fast = fast->next;
                }
            }
        }
        return nullptr;
    }
};