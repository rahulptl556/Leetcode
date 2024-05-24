class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int left = 0;
        int count = 0;
        
        for(int i=0; i<n; i++){
            if(s[i] == '('){
               left++;
            }
            else{
                if(left == 0){
                    count++;
                }
                else{
                    left--;;
                }
            }
        }
        return left+count;
        
    }
};