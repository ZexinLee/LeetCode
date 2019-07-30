class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> mails;
        bool hasplus, isdomain;
        string temp;
        int count = 0;
        for(auto email : emails)
        {
            hasplus = false;
            isdomain = false;
            temp = "";
            for(int i = 0; i < email.length(); i++)
            {
                if(isdomain)
                {
                    temp += email[i];
                }
                else
                {
                    if(email[i] == '@')
                    {
                        temp += '@';
                        isdomain = true;
                        continue;
                    }
                    if(hasplus)
                    {
                        continue;
                    }
                    else
                    {
                        if(email[i] == '.')
                            continue;
                        else if(email[i] == '+')
                        {
                            hasplus = true;
                            continue;
                        }
                        else
                        {
                            temp += email[i];
                        }
                    }
                }
            }
            if(mails.count(temp) == 0)
            {
                count++;
                mails.insert(temp);
            }
        }
        return count;
    }
};
