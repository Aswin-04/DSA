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

    ListNode* mergeLL(ListNode* l1, ListNode* l2) {
        ListNode* ptr = new ListNode(0);
        ListNode* curr = ptr;

        while(l1 && l2) {
            if(l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }

            else {
                curr->next = l2;
                l2 = l2->next;
            }

            curr = curr->next;
        }

        curr->next = (l1 ? l1 : l2);
        return ptr->next;
    }

    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        if(!slow->next) return slow;
        ListNode* fast = head->next;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = nullptr;
        return temp;
    }

    ListNode* mergeSortLL(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }

        ListNode* mid = findMid(head);
        ListNode* l1 = mergeSortLL(head);
        ListNode* l2 = mergeSortLL(mid);
        return mergeLL(l1, l2);
    }

    ListNode* sortList(ListNode* head) {
        return mergeSortLL(head);
    }
};