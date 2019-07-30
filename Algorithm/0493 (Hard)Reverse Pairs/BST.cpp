/*
	copy from https://leetcode.com/problems/reverse-pairs/solution/
/*

class Node {
public:
    Node *left, *right;
    int val;
    int count_ge;
    Node(int val)
    {
        this->val = val;
        this->count_ge = 1;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution {
public:
    Node* insert(Node* head, int val)
    {
        if (head == NULL)
            return new Node(val);
        else if (val == head->val)
            head->count_ge++;
        else if (val < head->val)
            head->left = insert(head->left, val);
        else {
            head->count_ge++;
            head->right = insert(head->right, val);
        }
        return head;
    }

    int search(Node* head, long long target)
    {
        if (head == NULL)
            return 0;
        else if (target == head->val)
            return head->count_ge;
        else if (target < head->val)
            return head->count_ge + search(head->left, target);
        else
            return search(head->right, target);
    }

    int reversePairs(vector<int>& nums)
    {
        Node* head = NULL;
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += search(head, nums[i] * 2LL + 1);
            head = insert(head, nums[i]);
        }
        return count;
    }
};
