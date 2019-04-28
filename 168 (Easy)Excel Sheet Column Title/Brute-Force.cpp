class Solution {
public:
    string convertToTitle(int n) {

        const char hashmap[28] = "0ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string ret;
        int remainder;
        int shang;
        while(n > 0)
        {
            shang = n / 26; // 如果我们当前在处理个位，shang就是在26进制下的右移操作。ABZ >> 1 = AB
            remainder = n % 26;
            if(!remainder)
            {
                ret.push_back('Z');
                n = shang - 1; // 让其减少1
            }
            else{
                ret.push_back(hashmap[remainder]);
                n = shang;
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
