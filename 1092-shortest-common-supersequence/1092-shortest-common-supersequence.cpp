class Solution {
public:
    
    int lcs(string &str1, string &str2, int n, int m, vector<vector<int>> &dp){
        if(n == 0 || m == 0){
            return dp[n][m] = 0;
        }
        
        if(dp[n][m] != -1){
            return  dp[n][m];
        }
        
        if(str1[n-1] == str2[m-1]){
            return  dp[n][m] = 1 + lcs(str1, str2, n-1, m-1, dp);
        }
        
        else{
            return  dp[n][m] = max(lcs(str1, str2, n, m-1, dp), lcs(str1, str2, n-1, m, dp));
        }
    }
    
    string shortestCommonSupersequence(string &str1, string &str2) {
        string s;

        int n = str1.length();
        int m = str2.length();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        lcs(str1, str2, n, m, dp); 
        
        int i = n;
        int j = m;
        
        // Creating the string  
        while(i!=0 && j!=0){
            if(str1[i-1] == str2[j-1]){
                s.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                s.push_back(str1[i-1]);
                i--;
            }
            else{
                s.push_back(str2[j-1]);
                j--;
            }
        }
        
        while(i != 0){
            s.push_back(str1[i-1]);
            i--;
        }
        while(j != 0){
            s.push_back(str2[j-1]);
            j--;
        }
        
        reverse(s.begin(), s.end());
        return s;
    }
};