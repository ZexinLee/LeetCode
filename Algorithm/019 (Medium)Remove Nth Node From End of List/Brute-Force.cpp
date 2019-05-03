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
