# Algorithm

Simple merge.

# Better Solution

```c++
~
```

(The best run time solution in the leetcode)

# Performance

Runtime: 8 ms, faster than 76.95% of C++ online submissions for Merge Two Sorted Lists.

Memory Usage: 9 MB, less than 53.28% of C++ online submissions for Merge Two Sorted Lists.

# Time Spent

~

# Times of Wrong Answer

3

# Solution

```c++
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
```

The code of AC solution

# Time Complexity

O(l1+l2), l1,l2 represent the length of each linked list.

# Note & Tips

1. Simple linked list merge.