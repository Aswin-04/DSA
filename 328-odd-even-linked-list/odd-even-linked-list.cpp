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
    ListNode* oddEvenList(ListNode* head) {
        
        if(!head || !head->next) return head;
        ListNode* evenHead = head->next;
        ListNode* temp = head;
        ListNode* nextNode = head;

        while(temp->next->next) {
            nextNode = temp->next;
            temp->next = temp->next->next;
            temp = nextNode;
        }
        temp->next = nullptr;

        temp = head;
        while(temp->next) {
            temp = temp->next;
        }

        temp->next = evenHead;
        return head;        
    }
};