# Algorithm

Simple traversal in linear array

# Better Solution

```c++
~
```

(The best run time solution in the leetcode)

# Performance

Runtime: 8 ms, faster than 33.33% of C++ online submissions for Distance Between Bus Stops.

Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Distance Between Bus Stops.

# Time Spent

12 min 30 second

# Times of Wrong Answer

1

# Solution

```c++
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int dis1 = 0, dis2 = 0;
        int n = distance.size();
        int s = min(start, destination);
        int d = max(start, destination);
        for(int i = s; i < d; i++) {
            dis1 += distance[i];
        }
        cout << "dis1:" << dis1 << endl;
        for(int i = d; i < n; i++) {
            dis2 += distance[i];
        }
        for(int i = 0; i < s; i++) {
            dis2 += distance[i];
        }
        cout << "dis2:" << dis2 << endl;
        return min(dis1, dis2);
    }
};
```

The code of AC solution

# Time Complexity

O(n)

# Note & Tips

1. Note that destination may less than start