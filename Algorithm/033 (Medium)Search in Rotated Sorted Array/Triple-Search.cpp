class Solution {
public:
    
    /*
       
       /      |
      /mid1   |
     /        |
    /left     |
 ------------------
              |      /right
              |     /
              |    /mid2
              |   /
           
           */
    
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        while(left<=right){
            int mid=(left+right)/2;
            if (nums[mid]==target) return mid;
            if (nums[mid]>=nums[left]) {  //mid1
                if (target>=nums[left]&&target<=nums[mid]) {
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }else{                        //mid2
                if (target>=nums[mid]&&target<=nums[right]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
        }
        return -1;
    }
};