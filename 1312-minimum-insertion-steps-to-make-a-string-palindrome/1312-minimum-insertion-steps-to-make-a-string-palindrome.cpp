class Solution {
public:


    int minInsertions(string s) {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int n = s.length();
        int m = s2.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1,0));

        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                }

                if(s[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }

        int lcs = dp[n][m];
        cout << lcs <<endl;
        
        int ans = n-lcs;
        cout << ans;

        return ans;
    }
};