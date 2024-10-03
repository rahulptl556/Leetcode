class Solution {
public:

    bool subset(vector<int>& nums, int n, int target, vector<vector<int>> &dp){
        for(int i=0; i<n+1; i++){
            for(int j=0; j<target+1; j++){
             //Initialization
                if(j == 0){
                    dp[i][j] = true;
                }
                else if(i == 0 && j!=0){
                    dp[i][j] = false;
                }
                
                else if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] =  dp[i-1][j];
                }
           
            }
        }
        return dp[n][target];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i=0; i<n; i++){
            total += nums[i];
        }
        int target = (total/2);
        
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, 0)); 
        
        if(total%2 != 0){
            return false;
        }
        else{
            return subset(nums,n,total/2,dp);
        }
    }
};