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
    int sz(ListNode* a) {
        int n = 0;
        while(a != nullptr) {
            n++;
            a = a->next;
        }
        return n;
    }

    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        int m = sz(a);
        int n = sz(b);
        ListNode* temp1 = a;
        ListNode* temp2 = b;
        if(m > n) {
            for(int i = 1; i <= m - n; i++) {
                temp1 = temp1->next;
            }
        }
        if(n > m) {
            for(int i = 1; i <= n - m; i++) {
                temp2 = temp2->next;
            }
        }
        while(temp1 != nullptr) {
            if(temp1 == temp2)
            return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;
    }
};