# Algorithm

Simply judge mod.

# Better Solution

```c++
class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string> result;
        result.resize(n);
        
        for (auto i = 1; i <= n; ++i)
        {
            unsigned int index = i - 1;
            std::string value = "";
            
            if (i % 15 == 0)
            {
                // FizzBuzz
                value = "FizzBuzz";
            }
            else if(i % 3 == 0)
            {
                // Fizz
                value = "Fizz";
            }
            else if(i % 5 == 0)
            {
                // Buzz
                value = "Buzz";
            }
            else
            {
                // just a number
                // result[index] = "1";
                value = to_string(i);
            }
            result[index] = value;
        }
        return result;
    }
};
```

Initialize at first to reduce memory operation.

(The best run time solution in the leetcode)

# Performance

Runtime: 8 ms, faster than 63.76% of C++ online submissions for Fizz Buzz.

Memory Usage: 10.5 MB, less than 43.56% of C++ online submissions for Fizz Buzz.

# Time Spent

4 min 1 seconds

# Times of Wrong Answer

0

# Solution

```c++
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i = 1; i <= n; i++) {
            if(i % 3 == 0 && i % 5 == 0) {
                ans.push_back("FizzBuzz");
            } else if(i % 3 == 0) {
                ans.push_back("Fizz");
            } else if(i % 5 == 0) {
                ans.push_back("Buzz"); 
            } else {
                ans.push_back(to_string(i));
            }
        }
        return ans;
    }
};
```

The code of AC solution

# Time Complexity

O(n)

# Note & Tips

1. If you know vector size and index first, you should initialize the size to reduce memory operation.