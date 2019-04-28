class Solution {
public:
    double parser(string s) {
        double ans = 0;
        int inter1, inter2;
        bool inter1found = false, inter2found = false;
        string str1;
        string str2;
        string str3;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '.') {
                inter1 = i;
                inter1found = true;
            }
            if(s[i] == '(') {
                inter2 = i;
                inter2found = true;
            }
        }
        if(inter1found)
        {
            str1 = s.substr(0, inter1);
            ans += atoi(str1.c_str());
            if(inter2found)
            {
                str2 = s.substr(inter1 + 1, inter2 - inter1 - 1);
                str3 = s.substr(inter2 + 1, s.length() - inter2 - 2);
                // cout << "inter1: " << inter1 << " inter2: " << inter2 << endl;
                // cout << "len2: " << str2.length() << " len3: " << str3.length() << endl;
                // cout << "res1: " << (atoi(str3.c_str()) - atoi(str2.c_str())) << endl;
                ans += ( (atoi((str2+str3).c_str()) - atoi(str2.c_str())) / ((pow(10, str3.length() + str2.length()) - 1) - (pow(10, str2.length()) - 1)));
            }
            else
            {
                str2 = s.substr(inter1 + 1, s.length());
                ans += (atoi(str2.c_str()) / (pow(10, str2.length())) );
            }
        }
        else
        {
            str1 = s.substr(0, s.length());
            ans += atoi(str1.c_str());
        }
        return ans;
    }
    
    bool isRationalEqual(string S, string T) {
        double s = parser(S);
        double t = parser(T);
        cout << s << ' ' << t << endl;
        return s == t;
    }
};
