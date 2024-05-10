class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int i = 0;
        int j = 0;
        int maxi = INT_MIN;
        int n = s.length();
        int length;
        
        if(n == 0){
            return 0;
        }
        
        while(j<n){
            mp[s[j]]++;
            
            if(mp.size() == j-i+1){
                length = j-i+1;
                maxi = max(length,maxi);
                j++;
            }
            
            else if(mp.size() < j-i+1){
                
                while(mp.size() < j-i+1){
                    mp[s[i]]--;

                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};