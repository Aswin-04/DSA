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
        int m=0;
        ListNode* temp = head;

        if(!temp->next) return nullptr;

        while(temp) {
            m++;
            temp = temp->next;
        }

        n = m - n;
        m = 0;
        ListNode* prev = nullptr;
        temp = head;
        while(temp && m < n) {
            m++;
            prev = temp;
            temp = temp->next;
        }

        if(!prev) {
            prev = temp;
            temp = temp->next;
            delete prev;
            return temp;
        }
        prev->next = temp->next;
        temp->next = nullptr;
        delete temp;

        return head;
    }
};