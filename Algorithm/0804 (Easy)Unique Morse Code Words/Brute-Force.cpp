class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> code({".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."});
        set<string> ans;
        int count = 0;
        for(auto v : words)
        {
            string a = "";
            for(char c : v)
                a += (code[c - 'a']);
            if(ans.count(a) == 0)
            {
                ans.insert(a);
                count++;
            }
        }
        return count;
    }
};
