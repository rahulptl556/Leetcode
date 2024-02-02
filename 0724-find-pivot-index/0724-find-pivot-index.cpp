class Solution {
public:
    int sumLeft(vector<int>& nums, int l, int x){
        int sum = 0;
        while(l < x){
            sum += nums[l];
            l++;
        }
        return sum;
    }
    
    int sumRight(vector<int>& nums, int x, int r){
        int sum = 0;
        while(x < r){
            sum += nums[x];
            x++;
        }
        return sum;
    }
    
    int pivotIndex(vector<int>& nums) {
       int size = nums.size();
        
        for (int x = 0; x < size; x++) {
            int leftSum = sumLeft(nums, 0, x);
            int rightSum = sumRight(nums, x + 1, size);
            
            if (leftSum == rightSum) {
                return x; // Pivot index found
            }
        }
        
        return -1; // No pivot index found
    }
};
