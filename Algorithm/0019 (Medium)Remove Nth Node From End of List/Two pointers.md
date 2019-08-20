# Algorithm

Use two pointers, one run to the end and count steps, the other run to the target node. Then remove the target node.

# Better Solution

```c++
~
```

(The best run time solution in the leetcode)

# Performance

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Nth Node From End of List.

Memory Usage: 8.6 MB, less than 75.00% of C++ online submissions for Remove Nth Node From End of List.

# Time Spent

~

# Times of Wrong Answer

1

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
    	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* start = new ListNode(0);//add new node
		start->next = head;
		ListNode *fast = start, *slow = start;
		while (n--) {
			if(fast->next)
				fast = fast->next;
		}
		while (fast->next) {
			slow = slow->next;
			fast = fast->next;
		}
		fast = slow->next;
		slow->next = fast->next;
		delete(fast);
		head = start->next;
		delete(start);
		return head;
	}
};

```

The code of AC solution

# Time Complexity

O(n)

# Note & Tips

1. An application of two-pointer method.