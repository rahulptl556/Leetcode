class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix_nums(n,0);
        prefix_nums[0] = nums[0]%k;
        if(prefix_nums[0] < 0){
            prefix_nums[0] += k;
        }
        for(int i=1; i<n; i++){
            prefix_nums[i] = prefix_nums[i-1] + nums[i];
            prefix_nums[i] %= k;
            if(prefix_nums[i] < 0){
                prefix_nums[i] += k;
            }
        }
    
        map<int,int> m;
        int ans{};
        for(int i=0; i<n; i++){
            ans += m[prefix_nums[i]];
            m[prefix_nums[i]]++;
            if(prefix_nums[i] == 0)ans++;
        }
        return ans;
    }
};