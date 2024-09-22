class Solution {
public:

    bool subsetSum(vector<int>& nums, int target, int n, vector<vector<int>>& dp){

        
        if(n == 0 && target != 0){
            return false;
        }
        else if(target == 0){
            return true;
        }

        else if( dp[n][target] != -1){
            return  dp[n][target];
        }

        else if(nums[n-1] <= target){
            return dp[n][target] = subsetSum(nums,target-nums[n-1],n-1,dp) || subsetSum(nums,target,n-1,dp);
        }
        else{
            return  dp[n][target] = subsetSum(nums,target,n-1,dp);
        }

    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        if(sum % 2 != 0){
            return false;
        }
        int target = sum/2;
        
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        
        return subsetSum(nums,target,n,dp);
    }
};