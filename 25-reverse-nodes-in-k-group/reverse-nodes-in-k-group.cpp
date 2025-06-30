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
    ListNode * reverseNodes(ListNode* prevGroupTail, ListNode* head, int k) {
        int ctr = 0;
        ListNode* prev = prevGroupTail;
        ListNode* cur = head;

        while(ctr < k) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            ctr++;
        }
        head->next = cur;
        prevGroupTail->next = prev;

        return head;
    }

    int getListLen(ListNode* head) {
        ListNode* fast = head;
        int ctr = 0;

        while(fast && fast->next) {
            fast = fast->next->next;
            ctr+=2;
        }

        if(fast) ctr++;
        return ctr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = getListLen(head);
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prevGroupTail = dummy;
        ListNode* curr = head;

        while(n >= k) {
            prevGroupTail = reverseNodes(prevGroupTail, curr, k);
            curr = curr->next;
            n-=k;
        }

        return dummy->next;
    }
};