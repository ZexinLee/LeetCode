# Algorithm

BFS

The solution above is slow, and BFS can help to make sure we process a single cell only once (well, twice in our case to scan for the land first).

Here, we find our land cells and put surrounding water cells in the queue. We mark water cells as visited and continue the expansion from land cells until there are no more water cells left. In the end, the number of steps in DFS is how far can we go from the land.

# Better Solution

```c++
class Solution {
public:
    int maxDistance(vector<vector<int>>& g, int steps = 0) {
      queue<pair<int, int>> q, q1;
      for (auto i = 0; i < g.size(); ++i)
        for (auto j = 0; j < g[i].size(); ++j)
          if (g[i][j] == 1)
            q.push({ i - 1, j }), q.push({ i + 1, j }), q.push({ i, j - 1 }), q.push({ i, j + 1 });
      while (!q.empty()) {
        ++steps;
        while (!q.empty()) {
          int i = q.front().first, j = q.front().second;
          q.pop();
          if (i >= 0 && j >= 0 && i < g.size() && j < g[i].size() && g[i][j] == 0) {
            g[i][j] = steps;
            q1.push({ i - 1, j }), q1.push({ i + 1, j }), q1.push({ i, j - 1 }), q1.push({ i, j + 1 });
          }
        }
        swap(q1, q);
      }
      return steps == 1 ? -1 : steps - 1;
    }
};
```

(The best run time solution in the leetcode)

# Performance

Runtime: 80 ms, faster than 43.19% of C++ online submissions for As Far from Land as Possible.

Memory Usage: 23.3 MB, less than 100.00% of C++ online submissions for As Far from Land as Possible.

# Time Spent

~

# Times of Wrong Answer

4

# Solution

```c++

```

The code of AC solution

# Time Complexity

Runtime: O(n * n). We process an individual cell only once (or twice).
Memory: O(n) for the queue.

# Note & Tips

1. Brute-Force in this question will cause TLE.