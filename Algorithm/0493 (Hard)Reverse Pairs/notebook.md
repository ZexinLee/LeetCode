# Thinking

## Brute-Force

Use 2 pointers to traverse the vector

​	time complexity O(n^2)

​	space complexity O(1)

Unfortunately, I got a TLE on the platform by brute-force.

## Further Thinking

1.Linear DP does not work in this case

2.Binary Search Tree is a good way to accelerate, but still TLE（BST reduce to linear array in the worst case）

​	time complexity O(n^2)

​	space complexity O(1)

3.Modified BIT algorithm can be accepted in this question

​	Binary Indexed Tree -- Fenwick Tree

​	time complexity O(nlogn)

4.Merge-Sort

​	Merge + count

​	time complexity O(nlogn)



## Best Solution for C++

Modified BIT algorithm

Merge-Sort

## Question

BIT algorithm is hard to comprehend(not mentioned in DSAA class), but I know the reason why BIT can AC while BST cannot.