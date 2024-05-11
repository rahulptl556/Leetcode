class Solution {
public:
    int maxVowels(string str, int k) {
        int n = str.length();
        int i = 0;
        int j = 0;
        int count = 0;
        int maxi = INT_MIN;
        
        while(j<n){
            
            if (str[j] == 'a' || str[j] == 'e' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u'){
                count ++;
            }
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                maxi = max(count,maxi);
                if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
                    count --;
                }
                i++;
                j++;
            }
        }
        return maxi == INT_MIN? 0 : maxi;
    }
};