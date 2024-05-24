class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[' ){
                st.push(s[i]);
            }
            else{
                // If stack is empty
                if(st.empty()){
                    return false;
                }
                // Checking for '('
                if(s[i] == ')'){
                    if(st.top() != '('){
                        return false;
                    }
                    else{
                        st.pop();
                    }
                }
                
                // Checking for '['
                if(s[i] == ']'){
                    if(st.top() != '['){
                        return false;
                    }
                    else{
                        st.pop();
                    }
                }
                
                // Checking for '{'
                if(s[i] == '}'){
                    if(st.top() != '{'){
                        return false;
                    }
                    else{
                        st.pop();
                    }
                }
            }
        }
        
        return st.empty();
    }
};