# Algorithm

String operation

# Better Solution

```c++
class Solution {
private:
    string dict = "0123456789-+";
public:
    int myAtoi(string str) {
        if (str.length() == 0) return 0;
        int pos = 0;
        while (pos < str.length() && str[pos] == ' ') {
            pos++;
        }
        if (pos == str.length()) return 0;
        if (dict.find(str[pos]) == string::npos) return 0;
        long long result = 0;
        int symbol = 1;
        int maxLength = 10;
        if (dict.find(str[pos]) > 9) {
            if (str[pos] == '-') symbol = -1;
            pos++;
        }
        while (maxLength > 0 && dict.find(str[pos]) != string::npos && dict.find(str[pos]) < 10) {
            result *= 10;
            result += dict.find(str[pos]);
            pos++;
            if (result != 0) maxLength--;
        }
        if (maxLength == 0 && dict.find(str[pos]) != string::npos && dict.find(str[pos]) < 10) {
            if (symbol == 1) return INT_MAX;
            return INT_MIN;
        }
        // cout<<"result: "<<result<<endl;
        result *= symbol;
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;
        return (int) result;
    }
};
```

0ms runtime solution -> use dictionary

(The best run time solution in the leetcode)

# Performance

Runtime: 4 ms, faster than 84.06% of C++ online submissions for String to Integer (atoi).

Memory Usage: 8.5 MB, less than 67.16% of C++ online submissions for String to Integer (atoi).

# Time Spent

From the beginning of the question to the time of the first AC.

# Times of Wrong Answer

~

# Solution

```c++
class Solution {
public:
    int myAtoi(string str) {
        long long store = 0;
        int sign = 1;
        bool status = true;
        bool stop = false;
        for(int i = 0; i < str.length(); i++)
        {
            if(status)
            {
                if(str[i] == ' ')
                {
                    status = true;
                }
                else if(str[i] == '-')
                {
                    status = false;
                    sign = -1;
                }
                else if(str[i] == '+')
                {
                    status = false;
                    sign = 1;
                }
                else if(str[i] >= '0' && str[i] <= '9')
                {
                    status = false;
                    store += (str[i] - '0');
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                if(str[i] >= '0' && str[i] <= '9')
                {
                    store *= 10;
                    store += (str[i] - '0');
                }
                else
                {
                    stop = true;
                }
            }
            
            if(sign*store >= INT_MAX)
            {
                return INT_MAX;
            }
            if(sign*store <= INT_MIN)
            {
                return INT_MIN;
            }
            if(stop)
            {
                break;
            }
        }
        return (int)(sign*store);
    }
};
```

The code of AC solution

# Time Complexity

O(n)

# Note & Tips

1. a simple implementation of `atoi()`.