class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> tmap;
        int i = 0;
        int j = 0;
        int sIndex;
        int mini = INT_MAX;
        int length;
        int n = s.length();
        int reqCount = t.length();
        
        for(char &ch : t){
            tmap[ch]++;
        }
        while(j<n){
            if(tmap.find(s[j]) != tmap.end()){
                if(tmap[s[j]] > 0){
                    reqCount--;
                }
                tmap[s[j]]--;
            }
            
            while(reqCount == 0){
                length = j-i+1;
                if(length < mini){
                    mini = length;
                    sIndex = i;
                }
                
                // Removing i
                if(tmap.find(s[i]) != tmap.end()){
                    tmap[s[i]]++;
                    if(tmap[s[i]] > 0){
                        reqCount++;
                    }
                }
                i++;
            }
         j++;
               
        }
        return mini == INT_MAX? "" : s.substr(sIndex,mini);
    }
};