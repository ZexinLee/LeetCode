class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;
        for(auto &v : nums)
        {
            switch(v)
            {
                case 0: 
                    count0++;
                    break;
                case 1:
                    count1++;
                    break;
                case 2:
                    count2++;
                    break;
            }
        }
        for(auto &v : nums)
        {
            if(count0)
            {
                count0--;
                v = 0;
            }
            else if(count1)
            {
                count1--;
                v = 1;
            }
            else
            {
                count2--;
                v = 2;
            }
        }
    }
};
