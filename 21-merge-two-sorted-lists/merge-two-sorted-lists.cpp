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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* head = new ListNode();
        ListNode* tempNode = head;
        ListNode* tempNode1 = list1;
        ListNode* tempNode2 = list2;

        while(tempNode1 != nullptr && tempNode2 != nullptr) {
            if(tempNode1->val <= tempNode2->val) {
                tempNode->next = tempNode1;
                tempNode1 = tempNode1->next;
            }

            else {
                tempNode->next = tempNode2;
                tempNode2 = tempNode2->next;
            }

            tempNode = tempNode->next;
        }

        while(tempNode1 != nullptr) {
            tempNode->next = tempNode1;
            tempNode1 = tempNode1->next;
            tempNode = tempNode->next;
        }

        while(tempNode2 != nullptr) {
            tempNode->next = tempNode2;
            tempNode2 = tempNode2->next;
            tempNode = tempNode->next; 
        }

        if(head == nullptr) return head;

        ListNode* prevHead = head;
        head = head->next;
        prevHead->next = nullptr;
        return head;
    }
};