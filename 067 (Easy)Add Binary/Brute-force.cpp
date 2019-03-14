class Solution {
public:
    string add(string str1, string str2) {
        string new_str;
        int sum = 0, carry = 0;
        int str1_bit, str2_bit;
        int move = max(str1.length(), str2.length());
        for(int i = 0; i < move; i++) {
        	str1_bit = (i >= str1.length()) ? 0 : str1[i] - '0';
        	str2_bit = (i >= str2.length()) ? 0 : str2[i] - '0';
        	new_str += ((str1_bit + str2_bit + carry) % 2 == 0) ? '0' : '1';
        	carry = (str1_bit + str2_bit + carry >= 2) ? 1 : 0;
        }
        if(carry)
        	new_str += '1';
        return new_str;
    }
    
    string reverse(string str) {
        string new_str;
        int len = str.length() - 1;
        for(int i = 0; i < str.length(); i++) {
            new_str += str[len--];
        }
        return new_str;
    }
    
    string addBinary(string a, string b) {
        return reverse(add(reverse(a), reverse(b)));
    }
};