class Solution {
public:
    bool buddyStrings(string A, string B) {
        vector<char> ns1;
        vector<char> ns2;
        vector<int> index;
        set<char> ns3;
        bool iscount = false;
        if(A.length() != B.length())
            return false;
        for(int i = 0; i < A.length(); i++)
        {
            if(A[i] != B[i])
            {
                ns1.push_back(A[i]);
                ns2.push_back(B[i]);
                index.push_back(i);
            }
            if(ns3.find(A[i]) != ns3.end())
            {
                iscount = true;
            }
            else
            {
                ns3.insert(A[i]);
            }
            if(index.size() > 2)
                return false;
        }
        if(index.size() == 0)
        {
            if(iscount)
                return true;
        }
        else if(index.size() == 2)
        {
            if(ns1[0] == ns2[1] && ns1[1] == ns2[0])
                return true;
        }
        return false;
    }
};
