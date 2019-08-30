# Algorithm

My solution: Hashmap + Brute force in array



# Better Solution

```c++
static const int __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
private:
	map<int, int> myMap;
	// returns the frequency of the smallest character
	inline int getFrequencySmallestCharacter(string &s) {
		char cMin = 'z'+1;
		int count = 0;
		for (char c : s) {
			if (c < cMin) {
				count = 1;
				cMin = c;
			}
			else if (c == cMin)
				count++;
		}
		return count;
	}

	inline int getFrequenciesGreaterthan(string &s) {
		int count = 0;
		int qcount = getFrequencySmallestCharacter(s);

		// Add count for all > qCount
		for (auto iter = myMap.upper_bound(qcount); iter != myMap.end(); iter++)
			count += iter->second;

		return count;
	}
public:
	vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words) {
		vector<int> ret;
		int queriesLength = queries.size();
		int wordsLength = words.size();

		// Loop over words and create a map
		// Key = frequency of min char
		// Value = number of times it occurred over all strings in the vector
		for (int i = 0; i < wordsLength; i++) {
			myMap[getFrequencySmallestCharacter(words[i])]++;
		}

		// Get the frequency of min char for the query and find the sum of 
		// 'values' for 'keys' in the above created map.
		for (int i = 0; i < queriesLength; i++) {
			ret.push_back(getFrequenciesGreaterthan(queries[i]));
		}

		return ret;
	}
};
```

(The best run time solution in the leetcode)

# Performance

Runtime: 80 ms, faster than 9.25% of C++ online submissions for Compare Strings by Frequency of the Smallest Character.

Memory Usage: 11 MB, less than 100.00% of C++ online submissions for Compare Strings by Frequency of the Smallest Character.

# Time Spent

10 min

# Times of Wrong Answer

0

# Solution

```c++
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
            map<char, int> m;
    vector<int> queriesnum;
    vector<int> ansnum;
    vector<int> returnnum;
    for(int i = 0; i <= 25; i++) {
        m['a' + i] = 0;
    }
    for(string s : queries) {
        for(int i = 0; i <= 25; i++) {
            m['a' + i] = 0;
        }
        for(char c : s) {
            if(c >= 'a' && c <= 'z') {
                m[c]++;
            }
        }
        for(auto p : m) {
            if(p.second != 0) {
                queriesnum.push_back(p.second);
                break;
            }
        }
    }
    for(string s : words) {
        for(int i = 0; i <= 25; i++) {
            m['a' + i] = 0;
        }
        for(char c : s) {
            if(c >= 'a' && c <= 'z') {
                m[c]++;
            }
        }
        for(auto p : m) {
            if(p.second != 0) {
                ansnum.push_back(p.second);
                break;
            }
        }
    }
    int count = 0;
    for(int i = 0; i < queriesnum.size(); i++) {
        count = 0;
        for(int temp : ansnum) {
            if(queriesnum[i] < temp) {
                count++;
            }
        }
        returnnum.push_back(count);
    }
    return returnnum;
    }
};
```

The code of AC solution

# Time Complexity

O(mn), m is the length of queries array, n is the length of words array.

# Note & Tips

1. Using iterator can get higher performance than using index to traverse a vector.
2. turn off I/O sync.