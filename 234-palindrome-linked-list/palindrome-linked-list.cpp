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

    ListNode* reverseLL(ListNode* head) {
        ListNode* temp = head;
        ListNode* nextNode = head;
        ListNode* prev = nullptr;

        while(temp) {
            nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if(slow->next == nullptr) return true;
        slow->next = reverseLL(slow->next);

        ListNode* first = head;
        ListNode* second = slow->next;

        while(second) {
            if(first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }

        slow->next = reverseLL(slow->next);
        return true;

    }
};