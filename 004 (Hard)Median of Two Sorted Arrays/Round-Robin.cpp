class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = nums1.size() + nums2.size();
        double pos1,temp;
        int x = 0, y = 0;
        if(sum >> 1 << 1 == sum){
            for(int i = 0; i < sum / 2 + 1; i++){
                if(x < nums1.size() && y < nums2.size()){
                    if(nums1[x] < nums2[y])
                        temp = nums1[x++];
                    else
                        temp = nums2[y++];
                }
                else if(x < nums1.size())
                    temp = nums1[x++];
                else
                    temp = nums2[y++];
                if(i == sum / 2 - 1)
                    pos1 = temp;
                if(i == sum / 2)
                    return (pos1+temp)/2;
            }
        }
        else{
            for(int i = 0; i < sum / 2 + 1; i++){
                if(x < nums1.size() && y < nums2.size()){
                    if(nums1[x] < nums2[y])
                        temp = nums1[x++];
                    else
                        temp = nums2[y++];
                }
                else if(x < nums1.size())
                    temp = nums1[x++];
                else
                    temp = nums2[y++];
                if(i == sum / 2)
                    return temp;
            }
        }
        
    return 0;
    }
};