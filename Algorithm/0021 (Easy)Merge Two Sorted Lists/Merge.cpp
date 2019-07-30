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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        int te;
        if(l1 == NULL)
        {
            if(l2 == NULL)
                return l1;
            else
            {
              te = l2->val;
              l2 = l2->next;
            }
        }
        else if(l2 == NULL)
        {
            te = l1->val;
            l1 = l1->next;
        }   
        else
        {
            if(l1->val > l2->val)
            {
                te = l2->val;
                l2 = l2->next;
            }
            else
            {
                te = l1->val;
                l1 = l1->next;
            }
        }
        
        
        ListNode* ans = new ListNode(te);
        ListNode* current = ans;
        while(l1 != NULL || l2 != NULL)
        {
            if(l1 == NULL)
            {
                flag1:current->next = new ListNode(l2->val);
                l2 = l2->next;
                current = current->next;
                continue;
            }    
            if(l2 == NULL)
            {
                flag2:current->next = new ListNode(l1->val);
                l1 = l1->next;
                current = current->next;
                continue;
            }
            if(l1->val > l2->val)
            {
                goto flag1;
            }
            else
            {
                goto flag2;
            }
        }
        return ans;
    }
};