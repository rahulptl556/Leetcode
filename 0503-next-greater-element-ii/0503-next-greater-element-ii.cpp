class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n,-1);
        int index;
        
        for(int i=0; i<2*n; i++){
            index = i%n;
          while(!st.empty() && arr[index] > arr[st.top()]){
              ans[st.top()] = arr[index];
              st.pop();
          }  
            st.push(index);
        }
        return ans;        
    }
};