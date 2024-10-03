class Solution {
public:

    bool subset(vector<int>& nums, int n, int target, vector<vector<int>> &dp){
        // base condn
        if(target == 0){
            return true;
        }
        if(n == 0 & target!=0){
            return false;
        }
        
        if(dp[n][target] != -1){
            return dp[n][target];
        }
        
        
        if(nums[n-1] <= target){
             // If the element is smaller than the target implement choice diagram
             return dp[n][target] = subset(nums,n-1,target-nums[n-1],dp) || subset(nums,n-1,target,dp);
        }
       
        else{
            //Else if larger -> dont include
            return dp[n][target] = subset(nums,n-1,target,dp);
        }
        
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i=0; i<n; i++){
            total += nums[i];
        }
        int target = (total/2);
        
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1)); 
        
        if(total%2 != 0){
            return false;
        }
        else{
            return subset(nums,n,total/2,dp);
        }
    }
};