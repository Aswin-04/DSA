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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // find the middle node of the linkedlist
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the right half of the linkedlist
        ListNode* cur = slow;
        ListNode* prev = nullptr;
        while(cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        // merge both halves of linked list
        ListNode* first = head;
        ListNode* second = prev;
        ListNode* temp1;
        ListNode* temp2;

        while(second->next != nullptr) {
            temp1 = first->next;
            temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }

        if(temp2) {
            second->next = temp2;
            second->next->next = nullptr;
        }
    }
};