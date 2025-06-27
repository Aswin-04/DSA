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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;

        while(l1 && l2) {
            if(l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        if(l1) cur->next = l1;
        if(l2) cur->next = l2;
        
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // TC --> O(n logk)
        if(lists.size() == 0) return nullptr;

        while(lists.size() > 1) {
            vector<ListNode*> mergedLists;
            for(int i=0; i < lists.size(); i+=2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i+1) < lists.size() ? lists[i+1] : nullptr;
                mergedLists.push_back(mergeTwoLists(l1, l2));
            } 
            lists = mergedLists;
        }
        return lists[0];
    }
};