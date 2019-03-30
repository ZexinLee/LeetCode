# Thinking

## Brute-Force

Use 2 pointers to traverse the vector

​	time complexity O(n^2)

​	space complexity O(1)

## Further Thinking

Use a hash map to store numbers can match, only need to traverse once

​	time complexity O(nlogn)

​	space complexity O(n)

## Best Solution for C++

Optimize hash table

​	**map.find("")->second** is more efficient than **map[""] **