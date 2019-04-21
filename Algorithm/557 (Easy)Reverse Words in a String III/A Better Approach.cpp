class Solution {
public:
     string reverseWords(string s) {
        istringstream iss(s);
        string ret{};
        string word;

        if (s.empty()) 
            return s;

        while (iss >> word) {
            for (int i{}, j = word.size() -1; i < j; i++, j--) {
                swap(word[i], word[j]);
            }
            ret += word + ' ';
        }
        ret.pop_back();
        return ret;        
    }
};