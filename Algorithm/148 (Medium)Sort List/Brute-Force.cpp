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
    ListNode* sortList(ListNode* head) {
        vector<int> vals;
        ListNode *s;
        int i;
                
        for (s = head; s != nullptr; s = s->next) {
            vals.push_back(s->val);
        }
        sort(vals.begin(), vals.end());
        for (s = head, i = 0; s != nullptr; s = s->next) {
            s->val = vals[i++];
        }
        return head;
        
    }
};
