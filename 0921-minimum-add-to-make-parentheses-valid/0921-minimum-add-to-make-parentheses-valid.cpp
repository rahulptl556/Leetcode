class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int left = 0;
        int count = 0;
        stack <char> st;
        
        for(int i=0; i<n; i++){
            if(s[i] == '('){
               st.push(s[i]);
            }
            else{
                if(st.empty()){
                    count++;
                }
                else{
                    st.pop();
                }
            }
        }
        if(st.empty()){
            return count;
        }
        else{
            count += st.size();
            return count;
        }
        
    }
};