/*
	from 	https://leetcode.com/problems/add-two-numbers/solution/
	lemonelson	Last Edit: January 19, 2019 3:37 PM
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *n1 = l1, *n2 = l2, *pre_sum;
    struct ListNode *units_digit_sum = NULL;
    int value, carry = 0;
    while(n1 != NULL || n2 != NULL || carry != 0){
        value = 0;
        if(n1 != NULL){
            value += n1->val;
            n1 = n1->next;   
        }
        if(n2 != NULL){
            value += n2->val;
            n2 = n2->next;
        }
        value += carry;
        carry = value/10;
        value %= 10;
        struct ListNode *cur_sum = (struct ListNode *)malloc(sizeof(struct ListNode));
        cur_sum->val = value;
        cur_sum->next = NULL;
        
        if(units_digit_sum == NULL)
            units_digit_sum = cur_sum;
        else
            pre_sum->next = cur_sum;
        
        pre_sum = cur_sum;      
    }
    return units_digit_sum;
}