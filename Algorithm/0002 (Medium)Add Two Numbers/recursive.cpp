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