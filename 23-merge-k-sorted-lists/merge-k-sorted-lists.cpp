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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int, int> freqHash;
        int n = lists.size();
        if(n == 0) return nullptr;

        for(int i=0; i < n; i++) {
            ListNode* curNode = lists[i];
            while(curNode != nullptr) {
                freqHash[curNode->val]++;
                curNode = curNode->next;
            }
        }

        ListNode* dummy = new ListNode();
        ListNode* curNode = dummy;
        for(auto it=freqHash.begin(); it != freqHash.end(); it++) {
            int val = it->first;
            int freq = it->second;
            for(int i=0; i < freq; i++) {
                ListNode* newNode = new ListNode(val);
                curNode->next = newNode;
                curNode = curNode->next;
            }   
        }

        ListNode* resNode = dummy->next;
        delete dummy;
        return resNode;
    }
};