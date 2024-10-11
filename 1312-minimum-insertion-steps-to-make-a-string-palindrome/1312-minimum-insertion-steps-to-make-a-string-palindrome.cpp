class Solution {
public:
    
    int solve(string &s1, string &s2, int n, int m, vector<vector<int>> &dp){
        if(n==0 || m==0){
            return dp[n][m] = 0;
        }
        
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        
        else if(s1[n-1] == s2[m-1]){
            return dp[n][m] = 1 + solve(s1,s2,n-1,m-1,dp);
        }
        
        else{
            return dp[n][m] = max(solve(s1,s2,n-1,m,dp), solve(s1,s2,n,m-1,dp));
        }
        
    }


    int minInsertions(string &s) {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int n = s.length();
        int m = s2.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));

        solve(s,s2,n,m,dp);
        
        int lcs = dp[n][m];
        // cout << lcs <<endl;
        
        int ans = n-lcs;
        // cout << ans;

        return ans;
    }
};