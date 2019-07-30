class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int start,end,ships;
        ships = start = 0;
        end = people.size()-1; 
        
        while(start<=end)
        {
            if(people[start] + people[end] > limit)
            {
                end--; 
                ships++;   
            }
            else
            {
                start++;
                end--;
                ships++;
            }
        }
        return ships;
    }
};
