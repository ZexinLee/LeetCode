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