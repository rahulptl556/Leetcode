class Solution {
public:
    
    string shortestCommonSupersequence(string str1, string str2) {
        string s;

        int n = str1.length();
        int m = str2.length();
        
        // Create the DP table
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // Fill the DP table using the iterative LCS approach
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        // Now, backtrack to construct the SCS
        int i = n, j = m;
        
        while (i != 0 && j != 0) {
            if (str1[i-1] == str2[j-1]) {
                s.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if (dp[i-1][j] > dp[i][j-1]) {
                s.push_back(str1[i-1]);
                i--;
            } else {
                s.push_back(str2[j-1]);
                j--;
            }
        }
        
        // Add remaining characters of str1 (if any)
        while (i != 0) {
            s.push_back(str1[i-1]);
            i--;
        }

        // Add remaining characters of str2 (if any)
        while (j != 0) {
            s.push_back(str2[j-1]);
            j--;
        }
        
        // Reverse the result since it was constructed backwards
        reverse(s.begin(), s.end());
        return s;
    }
};
