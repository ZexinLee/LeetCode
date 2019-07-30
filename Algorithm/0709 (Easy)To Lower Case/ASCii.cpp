class Solution {
public:
    string toLowerCase(string str) {
        for(char &a : str)
            if(a >= 'A' && a <= 'Z')
                a += 32;
        return str;
    }
};
