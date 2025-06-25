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
        
        if(!head->next) return nullptr;
        ListNode* fast = head;
        int len = 0;
        while(fast && fast->next) {
            len+=2;
            fast = fast->next->next;
        }

        if(fast) len+=1;

        int idx = len-n+1;
        ListNode* cur = head;
        ListNode* prev = nullptr;

        int ctr = 1;
        while(ctr < idx) {
            prev = cur;
            cur = cur->next;
            ctr++;
        }

        if(!prev) {
            head = cur->next;
            cur->next = nullptr;
        }

        else {
            prev->next = cur->next;
            cur->next = nullptr;
        }

        return head;
    }
};