class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack <char> st; 
        stack <char> tt;
        
        int n = s.length();
        int x = t.length();
        
        for(int i=0; i<n; i++){
            if(s[i] == '#'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }
        for(int i=0; i<x; i++){
            if(t[i] == '#'){
                 if(!tt.empty()){
                    tt.pop();
                }
            }
            else{
                tt.push(t[i]);
            }
        }
        
        return st==tt;
        
    }
};