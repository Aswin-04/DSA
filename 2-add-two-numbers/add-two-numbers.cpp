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
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* dummy = new ListNode();
        ListNode* l3 = dummy;

        int carry = 0;
        while(ptr1 && ptr2) {
            int sum = ptr1->val + ptr2->val + carry;
            int val = sum%10;
            carry = sum/10;

            ListNode* newNode = new ListNode(val);
            l3->next = newNode;

            l3 = l3->next;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        while(ptr1) {
            int sum = ptr1->val + carry;
            int val = sum%10;
            carry = sum/10;

            ListNode* newNode = new ListNode(val);
            l3->next = newNode;

            l3 = l3->next;
            ptr1 = ptr1->next;
        }

        while(ptr2) {
            int sum = ptr2->val + carry;
            int val = sum%10;
            carry = sum/10;

            ListNode* newNode = new ListNode(val);
            l3->next = newNode;

            l3 = l3->next;
            ptr2 = ptr2->next;
        }

        if(carry) {
            ListNode* newNode = new ListNode(carry);
            l3->next = newNode;
        }

        return dummy->next;
    }
};