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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* ll1 = l1;
        ListNode* ll2 = l2;
        ListNode* sum = new ListNode(-1);
        ListNode* temp = sum;
        int carry = 0;

        while(ll1 && ll2) {
            
            int val = (ll1->val + ll2->val + carry);
            ListNode* newNode = new ListNode(val%10);
            carry = val/10;

            ll1 = ll1->next;
            ll2 = ll2->next;
            temp->next = newNode;
            temp = temp->next;
        }

        while(ll1) {
            int val = (ll1->val + carry);
            ListNode* newNode = new ListNode(val%10);
            carry = val/10;

            ll1 = ll1->next;
            temp->next = newNode;
            temp = temp->next;
        }

        while(ll2) {
            int val = (ll2->val + carry);
            ListNode* newNode = new ListNode(val%10);
            carry = val/10;

            ll2 = ll2->next;
            temp->next = newNode;
            temp = temp->next;
        }

        if(carry) {
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
        }

        return sum->next;
    }
};