# Algorithm

Implement adder

Linkedlist

# Better Solution

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* head= new ListNode(0);
        ListNode* prev=head;
        int carry=0;
        while(temp1!=NULL && temp2!=NULL)
        {
            int n=temp1->val+temp2->val+carry;
            carry=n/10;
            
            if(n>9)
            {
                n=n%10;
            }
            if(temp1==l1 && temp2==l2)
            {
                head->val=n;
                prev=head; 
            
            }
            else
            {
                ListNode* newnode=new ListNode(n);
                prev->next=newnode;
                prev=newnode;
            }
            temp1=temp1->next;
            temp2=temp2->next;
            
        }
        
        if(temp1!=NULL)
        {
            while(temp1!=NULL)
            {
                int n=temp1->val+carry;
                carry=n/10;
                if(n==10)
                {
                    n=0;
                }
                ListNode* newnode= new ListNode(n);
                prev->next=newnode;
                prev=newnode;
                temp1=temp1->next;
                
            }
                
        }
        if(temp2!=NULL)
        {
            while( temp2!=NULL)
            {
                int n=temp2->val+carry;
                carry=n/10;
                if(n==10)
                {
                    n=0;
                }
                ListNode* newnode= new ListNode(n);
                prev->next=newnode;
                prev=newnode;
                temp2=temp2->next;
            }
        }
        if(carry!=0)
        {
            ListNode* newnode= new ListNode(1);
            prev->next=newnode;
        }
            
        return head;
        
    }
};
```

4 ms solution

(The best run time solution in the leetcode) 

# Performance

Runtime: 24 ms, faster than 64.84% of C++ online submissions for Add Two Numbers.

Memory Usage: 11.6 MB, less than 5.14% of C++ online submissions for Add Two Numbers.

# Time Spent

From the beginning of the question to the time of the first AC.

# Times of Wrong Answer

0

# Solution

```c++
/*
	Copy from https://leetcode.com/problems/add-two-numbers/discuss/1012/Recursive-8-line-C%2B%2B-solution
*/
class Solution {

	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			if (l1 == NULL and l2 == NULL) return NULL;
			else if (l1 == NULL) return l2; 
			else if (l2 == NULL) return l1; 

			int a = l1->val + l2->val;
			ListNode *p = new ListNode(a % 10);
			p->next = addTwoNumbers(l1->next,l2->next);
			if (a >= 10) p->next = addTwoNumbers(p->next, new ListNode(1));
			return p;
		}
  };
```

The code of AC solution

# Time Complexity

O(n)

# Note & Tips

1. Implement an fully-adder by linked-list.
2. Use stack is better.