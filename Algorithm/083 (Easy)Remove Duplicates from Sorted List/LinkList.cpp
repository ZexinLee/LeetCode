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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        ListNode* last = head;
        if(head == NULL)
            return head;
        int currentval = temp->val;
        temp = temp->next;
        while(temp != NULL)
        {
            //cout << "temp:" << temp->val << "curr:" << currentval << endl;
            //if(temp->next != NULL)
            //    cout << temp->next->val << endl;
            if(temp->val == currentval)
            {
                last->next = temp->next;
                temp = temp->next;
            }
            else
            {
                last = temp;
                temp = temp->next;
                currentval = last->val;
            }
        }
        
        return head;
    }
};