/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int sizeofLL(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp) {
            cnt++;
            temp = temp->next;
        }

        return cnt;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int l1 = sizeofLL(headA);
        int l2 = sizeofLL(headB);

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while(l1 > l2 && tempA) {
            l1--;
            tempA = tempA->next;
        }

        while(l2 > l1 && tempB) {
            l2--;
            tempB = tempB->next;
        }

        if(tempA == tempB) return tempA;

        while(tempA && tempB) {
            if(tempA->next == tempB->next) return tempA->next;
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return nullptr;
    }
};