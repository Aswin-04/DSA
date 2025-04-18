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
        
        ListNode* temp = head;
        if(temp == nullptr) return nullptr;
        if(temp->next == nullptr) return temp;
        ListNode* newHead = reverseList(temp->next);
        ListNode* frontNode = temp->next;
        frontNode->next = temp;
        temp->next = nullptr;
        return newHead;
    }
};