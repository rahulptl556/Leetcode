class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        int m = s + (e-s)/2; 
        while(s <= e){
            if(target == nums[m]){
                return m;
            }
            if(target < nums[m]){
                e = m - 1;
            }
            if(target > nums[m]){
                s = m + 1;
            }
            m = s + (e-s)/2;
        }
        return -1;
    }
};