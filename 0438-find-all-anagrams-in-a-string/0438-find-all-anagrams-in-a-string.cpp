class Solution {
public:
    
    bool allZeros(vector<int>& counter){
        for(int &i : counter){
            if(i != 0)
            return false;
        }
        return true;
    }
    vector<int> findAnagrams(string txt, string pat) {
        vector<int> counter(26,0);
        
        // Map pat char count in vector
        for(int i=0; i<pat.length();i++){
            counter[pat[i] - 'a']++;
        }
        
        int i = 0;
        int j = 0;
        vector <int> ans;
        int n = txt.length();
        int k = pat.length();
        
        while(j<n){
            // Reducing char count if found in window 
            counter[txt[j] - 'a']--;
            
            if(j-i+1 < k){
                j++;
            }
            
            else if(j-i+1 == k){
                // check if all zero in counter
                if(allZeros(counter)){
                    ans.push_back(i);
                }
                // incrementing i th element before moving window
                counter[txt[i] - 'a']++;
                i++;
                j++;
            }
        }
        return ans;
        
	}

};