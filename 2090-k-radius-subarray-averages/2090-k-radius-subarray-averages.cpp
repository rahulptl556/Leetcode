class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int i= 0;
        int j= 0;
        long long sum = 0;
        int n = nums.size();
        vector<int> ans(n,-1);
        int avg;
        
        while(j<n){
            sum +=nums[j];
            
             if(j-i+1 < 2*k+1){
                j++;
            }
            
            else if(j-i+1==2*k+1){ 
                
                avg=sum/(j-i+1);
                ans[i+k] = avg;
                
                sum-=nums[i];
                i++;
                j++;
          }
        }
        return ans;
    }
};