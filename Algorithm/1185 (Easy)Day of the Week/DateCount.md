# Algorithm

Count date by mod 7

# Better Solution

```c++
~
```

(The best run time solution in the leetcode)

# Performance

Runtime: 4 ms, faster than 33.33% of C++ online submissions for Day of the Week.

Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Day of the Week.

# Time Spent

22 min 48 second

# Times of Wrong Answer

3

# Solution

```c++
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        // 1971.1.1 Friday
        map<int, string> calendar = {{0, "Friday"}, {1, "Saturday"}, {2, "Sunday"}, {3, "Monday"}, {4, "Tuesday"}, {5, "Wednesday"}, {6, "Thursday"}};
        int daycount = 0;
        for(int i = 1971; i < year; i++) {
            daycount += ((i % 4 == 0) ? 366: 365);
        }
        for(int i = 1; i < month; i++) {
            if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
                daycount += 31;
            }
            else if(i == 4 || i == 6 || i == 9 || i == 11) {
                daycount += 30;
            }
            else if(i == 2) {
                daycount += ((year % 4 == 0) ? 29 : 28);
            }
        }
        daycount += (day - 1);
        cout << daycount;
        daycount %= 7;
        return calendar[daycount];
    }
};
```

The code of AC solution

# Time Complexity

O(1)

# Note & Tips

1. Some corner cases need to cover.