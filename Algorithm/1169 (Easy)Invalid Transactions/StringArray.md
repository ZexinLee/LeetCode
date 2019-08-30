# Algorithm

String operation and array

# Better Solution

```c++
class Solution {
private:
    struct Transaction {
        string name;
        int min;
        int amount;
        string city;
        Transaction(string n, int m, int a, string c) : name(n), min(m), amount(a), city(c) {}
    };
    
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        if (!transactions.size()) return {};
        int n(transactions.size());
        
        vector<Transaction> data;
        unordered_map<string,vector<int>> name_ids;
        for (int i(0); i < transactions.size(); ++i) {
            string name, city;
            int min(0), amnt(0), j(0);
            while (transactions[i][j] != ',') name += transactions[i][j++]; ++j;
            while (transactions[i][j] != ',') min = min*10 + (transactions[i][j++]-'0'); ++j;
            while (transactions[i][j] != ',') amnt = amnt*10 + (transactions[i][j++]-'0'); ++j;
            while (j < transactions[i].size()) city += transactions[i][j++];
            data.push_back(Transaction(name, min, amnt, city));
            name_ids[name].push_back(i);
        }
        
        vector<string> res;
        
        for (int i(0); i < n; ++i) {
            if (data[i].amount > 1000) res.push_back(transactions[i]);
            else {
                for (int j : name_ids[data[i].name]) {
                    if (data[j].city != data[i].city &&  abs(data[j].min-data[i].min) <= 60) {
                        res.push_back(transactions[i]);
                        break;
                    }
                }
            }
        }
        
        return res;
    }
};
```

(The best run time solution in the leetcode)

# Performance

Runtime: 928 ms, faster than 5.21% of C++ online submissions for Invalid Transactions.

Memory Usage: 230.8 MB, less than 100.00% of C++ online submissions for Invalid Transactions.

# Time Spent

50 min

# Times of Wrong Answer

~

# Solution

```c++
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
    vector<string> ans;
    /* <person, position>, <money, time> */
    vector<vector<string>> store1;
    vector<vector<int>> store2;
    vector<bool> check;

    string person;
    int time;
    int money;
    string position;
    for(string s : transactions) {
        vector<int> pos;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ',') {
                pos.push_back(i);
            }
        }
        person = s.substr(0, pos[0]);
        time = stoi(s.substr(pos[0] + 1, pos[1] - pos[0] - 1));
        money = stoi(s.substr(pos[1] + 1, pos[2] - pos[1] - 1));
        position = s.substr(pos[2] + 1, pos[3] - pos[2] - 1);
        store1.push_back(vector<string>{person,position});
        store2.push_back(vector<int>{time,money});
//        cout << person << " " << time << " " << money << " " << position << " ";
//        cout << endl;
    }

    for(int i = 0; i < store1.size(); i++) {
        for(int j = i + 1; j < store1.size(); j++) {
            if(store2[i][0] > store2[j][0]) {
                auto temp1 = store1[i];
                store1[i] = store1[j];
                store1[j] = temp1;
                auto temp2 = store2[i];
                store2[i] = store2[j];
                store2[j] = temp2;
                auto temp3 = transactions[i];
                transactions[i] = transactions[j];
                transactions[j] = temp3;
            }
        }
    }
    for(int i = 0; i < store1.size(); i++) {
        cout << store1[i][0] << " " << store1[i][1] << " " << store2[i][0] << " " << store2[i][1];
        cout << endl;
        if(store2[i][1] > 1000) {
            check.push_back(false);
        } else {
            check.push_back(true);
        }
    }
    for(int i = 0; i < store1.size(); i++) {
        if(!check[i]) {
            continue;
        } else {
            for(int j = i; j >= 0; j--) {
                if(store1[i][0] == store1[j][0] && store1[i][1] != store1[j][1] && store2[i][0] - store2[j][0] <= 60) {
                    check[i] = false;
                }
                if(store2[i][0] - store2[j][0] > 60) {
                    break;
                }
            }
            for(int j = i; j < store1.size();j++) {
                if(store1[i][0] == store1[j][0] && store1[i][1] != store1[j][1] && store2[j][0] - store2[i][0] <= 60) {
                    check[i] = false;
                }
                if(store2[j][0] - store2[i][0] > 60) {
                    break;
                }
            }
        }

    }

    for(int i = 0; i < check.size(); i++) {
        cout << check[i];
        if(!check[i]) {
            ans.push_back(transactions[i]);
        }
    }
    return ans;
    }
};
```

The code of AC solution

# Time Complexity

O(n^2)

# Note & Tips

1. I misunderstood the question for first 30 min.
2. String operation `split()` in C++ is not easy and no STL can help. To use a template of `split()` can save time.