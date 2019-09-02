# Algorithm

TrieorBitmap

# Better Solution

```c++
struct node {
    node* child[27];
    int cnt;
    node() {
        cnt = 0;
        memset(child, 0, sizeof(child));
    }
};

class Solution {
public:
    node* root;
    const int CHARS = 26;
    void insert(vector < bool > &cnt, int last) {
        node *cur = root;
        for(int i = 0;i < CHARS;++i) {
            if(cnt[i]) {
                if(cur -> child[i] == NULL) {
                    cur -> child[i] = new node();
                }
                cur = cur -> child[i];
                if(i == last) {
                    // cout << i << "\n";
                    ++(cur -> cnt);
                }
            }
        }
    }
    
    void print() {
        queue < pair < node*, int > > q;
        q.push({root, 0});
        while(!q.empty()) {
            node *cur = q.front().first;
            int d = q.front().second;  q.pop();
            cout << (cur -> cnt) << "  d: " << d << "\n";
            for(int i = 0;i < CHARS;++i) {
                node* nxt = cur -> child[i];
                if(nxt != NULL) {
                    cout << char(i + 'a') << "  ";
                    q.push({nxt, d + 1});
                }
            }
            cout << "\n";
        }
    }
    
    int process(string &S, int idx, node* cur, bool yes, char passby, bool passed) {
        if(idx == S.size()) {
            return (yes and passed and (cur != NULL)) ? (cur -> cnt) : 0;
        }
        
        if(cur == NULL) {
            return 0;
        }
        
        // cout << idx << " " << yes << " " << passby << " " << passed << "\n";
        
        return ((yes and passed) ? (cur -> cnt) : 0) + process(S, idx + 1, cur, 0, passby, passed) + process(S, idx + 1, cur -> child[S[idx] - 'a'], 1, passby, passed | (S[idx] == passby));
    }
    
    vector<int> findNumOfValidWords(vector<string>& A, vector<string>& Q) {
        int n = A.size();
        root = new node();
        for(int i = 0;i < n;++i) {
            vector < bool > cnt(CHARS + 1, 0);
            int m = A[i].size();
            int last = 0;
            for(int j = 0;j < m;++j) {
                cnt[A[i][j] - 'a'] = true;
                last = max(last, A[i][j] - 'a');
            }
            insert(cnt, last);
        }
        // print();
        vector < int > ans;
        int Qn = Q.size();
        for(int i = 0;i < Qn;++i) {
            char ch = Q[i][0];
            sort(Q[i].begin(), Q[i].end());
            ans.push_back(process(Q[i], 0, root, 1, ch, 0));
        }
        
        return ans;
    }
};

/*
["aaaa","asas","able","ability","actt","actor","access"]
["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]

["apple","pleas","please"]
["aelwxyz","aelpxyz","aelpsxy","saelpxy","xaelpsy"]

["kkaz","kaaz","aazk","aaaz","abcdefghijklmnopqrstuvwxyz","kkka","kkkz","aaaa","kkkk","zzzz"]
["kazxyuv"]

*/
```

(The best run time solution in the leetcode)

Runtime: 192 ms, faster than 94.05% of C++ online submissions for Number of Valid Words for Each Puzzle.

Memory Usage: 72.5 MB, less than 100.00% of C++ online submissions for Number of Valid Words for Each Puzzle.

# Bitmap Solution

```c++
class Solution {
    vector<int> base;
    void born(vector<string>& words){
        for(auto& s: words){
            set<char> tmp;
            int bit = 0;
            for(auto c:s){
                tmp.insert(c);
                bit = bit | (1<<(c-'a'));
            }
            if(tmp.size() >7)continue;
            base.push_back(bit);
        }
    }
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> ans;
        born(words);
        
        for(auto& s: puzzles){
            int num = 0;
            int bit = 0;
            for(auto c: s){
                bit = bit | (1<<(c-'a'));
            }
            int firstBit = 1 << (s[0] - 'a');
            for(auto v: base){
                if((v & bit) == v && ((firstBit & v) == firstBit)){
                    num++;
                }
            }
            ans.push_back(num);
        }
        
        return ans;
    }
};
```

Runtime: 1772 ms, faster than 5.36% of C++ online submissions for Number of Valid Words for Each Puzzle.

Memory Usage: 72 MB, less than 100.00% of C++ online submissions for Number of Valid Words for Each Puzzle.

# Performance

Runtime: 192 ms, faster than 94.05% of C++ online submissions for Number of Valid Words for Each Puzzle.

Memory Usage: 72.5 MB, less than 100.00% of C++ online submissions for Number of Valid Words for Each Puzzle.

# Time Spent

Not Done

# Times of Wrong Answer

~

# Solution

```c++
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> ans;
        vector<map<char, int>> puzzlem;
        vector<map<char, int>> wordm;
        for(string s : words) {
            map<char, int> m0;
            for(int i = 0; i <= 25; i++) {
                m0['a' + i] = 0;
            }
            for(char c : s) {
                m0[c]++;
            }
            wordm.push_back(m0);
        }
        for(string s : puzzles) {
            map<char, int> m1;
            for(int i = 0; i <= 25; i++) {
                m1['a' + i] = 0;
            }
            for(char c : s) {
                m1[c]++;
            }
            puzzlem.push_back(m1);
        }
        int pos = 0;
        for(auto p : puzzlem) {
            int count = 0;
            for(auto tx : wordm) {
                bool check = true;
                if(tx[puzzles[pos][0]] == 0) {
                    continue;
                }
                for(int i = 0; i <= 25; i++) {
                    if(tx['a' + i] != 0 && p['a' + i] == 0) {
                        
                        check =  false;
                        break;
                    }
                }
                if(check) {
                    count++;   
                }
            }
            pos++;
            ans.push_back(count);
        }
        return ans;
    }
};
```

TLE

# Time Complexity

Best answer beats 94%: O(n+100l), n is length of word vector, l is length of puzzle.

Brute-Force with bitmap: O(nml), n is length of word vector, m is length of puzzle vector, l is length of words. l can be at most 7 in this question.

My answer brute force: O(nml), n is length of word vector, m is length of puzzle vector, l is length of words.

# Note & Tips

1. use basic array instead of constructing object to accelerate, if no pre-operation for this question, it will be definitely TLE.(as my answer)
2. Not Done because of TLE, 7/10 passing.
3. Use Trie(Prefix Tree)(in Chinese:字典树) can AC.
4. Use Brute-Force bitmap can also AC but near TLE(nearly 10 times of time of best answer).