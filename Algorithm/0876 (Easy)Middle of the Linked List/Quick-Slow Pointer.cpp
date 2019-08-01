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
    ListNode* middleNode(ListNode* head) {
        ListNode* quick = head;
        ListNode* slow = head;
        while(quick != NULL && quick->next != NULL) {
            slow = slow->next;
            quick = quick->next->next;
        }
        return slow;
    }
};