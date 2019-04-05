class Solution {
public:
    string countAndSay(int n) {
        if (n==1)
        {
            return "1";
        }
        string prev = countAndSay(n-1);
        string curr = "";
        int numRepeats = 1;
        for (int i = 0; i < prev.size() - 1; i++)
        {
            if (prev[i] == prev[i+1])
            {
                numRepeats++;
            }
            else
            {
                curr += to_string(numRepeats) + prev[i];
                numRepeats = 1;
            }
        }
		// you may not be able to get a chance to complete your string if you get repeated numbers as your ending
		// so we need to add this line here
        curr += to_string(numRepeats) + prev[prev.size() - 1];
        return curr;
    }
};