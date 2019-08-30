# Algorithm

Using hashmap to store cumulative sum of N-first node and the pointer of each node. When hashmap hit, revert to the hit node(to delete the zero sum) and so on.

# Better Solution

```c++
~
```

(The best run time solution in the leetcode)

# Performance

Runtime: 12 ms, faster than 86.02% of C++ online submissions for Remove Zero Sum Consecutive Nodes from Linked List.

Memory Usage: 10.5 MB, less than 100.00% of C++ online submissions for Remove Zero Sum Consecutive Nodes from Linked List.

# Time Spent

Not Done

# Times of Wrong Answer

~

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        ListNode* root =new ListNode(0);
        root->next=head;
        unordered_map<int,ListNode*>um;
        um[0]=root;
        int ac=0;
        
        while(head!=NULL){
            ac+=head->val;
            
            //found value
            if(um.find(ac)!=um.end()){
                ListNode* prev= um[ac];
                ListNode* start= prev;
                
                //delete bad references
                int aux = ac;
                while(prev!=head){
                    prev=prev->next;
                    aux+=prev->val;
                    if(prev!=head)um.erase(aux);
                }
                
                start->next = head->next;
            }else{
                um[ac]= head;
            }
            
            head=head->next;
        }
        
        return root->next;
    }
};
```

The code of AC solution

# Time Complexity

O(n)

# Note & Tips

1. Some corner cases need to take into considerations.(or RE will happen)
2. revert operation need to delete bad reference, to prevent wild pointer case(may cause memory leak).