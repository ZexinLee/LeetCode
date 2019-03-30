/*
	copy from https://leetcode.com/problems/construct-the-rectangle/discuss/97210/3-line-Clean-and-easy-understand-solution
	jianchao-li
*/
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int a = sqrt(area);
        while (area % a) {
            a--;
        }
        return {area / a, a};
    }
};