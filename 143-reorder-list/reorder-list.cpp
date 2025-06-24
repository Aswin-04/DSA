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
    void reorderList(ListNode* head) {

        vector<ListNode*> listArr;
        ListNode* cur = head;
        while(cur) {
            listArr.push_back(cur);
            cur = cur->next;
        }

        int i=1;
        int j=listArr.size()-1;

        cur = head;
        cur->next = listArr[j];
        cur = cur->next;
        j--;

        while(i <= j) {
            cur->next = listArr[i];
            cur = cur->next;
            i++;
            if(i > j) break;
            cur->next = listArr[j];
            cur = cur->next; 
            j--;
        }

        cur->next = nullptr;
    }
};