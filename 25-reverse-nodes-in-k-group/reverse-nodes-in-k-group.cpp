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
    ListNode * reverseNodes(ListNode* prevNode, ListNode* curNode, ListNode*& head, int k) {
        int ctr = 0;
        ListNode* cur = curNode;
        ListNode* prev = nullptr;
        while(ctr < k) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            ctr++;
        }
        curNode->next = cur;
        if(prevNode) prevNode->next = prev;
        if(head == nullptr) {
            head = prev;
        }
        return curNode;
    }

    int getListLen(ListNode* head) {
        ListNode* fast = head;
        int ctr = 0;

        while(fast && fast->next) {
            fast = fast->next->next;
            ctr+=2;
        }

        if(fast) ctr++;
        return ctr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = getListLen(head);
        ListNode* newHead = nullptr;

        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(n >= k) {
            prev = reverseNodes(prev, cur, newHead, k);
            cur = cur->next;
            n-=k;
        }

        return newHead;
    }
};