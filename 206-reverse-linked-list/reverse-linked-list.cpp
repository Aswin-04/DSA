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
    ListNode* reverseList(ListNode* head) {
        
        if(head == nullptr) return nullptr;
        ListNode* crnt = head;
        ListNode* prev = nullptr;
        
        while(crnt != nullptr) {
            ListNode* next = crnt->next;
            crnt->next = prev;
            prev = crnt;
            crnt = next;
        }

        return prev;
    }
};