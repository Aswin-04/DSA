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
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* left = dummy;
        ListNode* right = head;        
        for(int i=0; i < n; i++) {
            right = right->next;
        }

        while(right != nullptr) {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next; 
        head = dummy->next;
        dummy->next = nullptr;
        return head;
    }
};