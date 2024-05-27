class Solution {
public:
    int maxArea(vector<int>& height){
        int n = height.size();
        vector<int> right(n);
        vector<int> left(n);
        stack <int> st;
        
        //create right smallest array
        for(int i=0; i<n; i++){
            while(!st.empty() && height[i] < height[st.top()]){
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        //empty it
        while(!st.empty()){
            right[st.top()] = n;
            st.pop();
        }
        //create left smallest array
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && height[i] < height[st.top()]){
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        //empty it
        while(!st.empty()){
            left[st.top()] = -1;
            st.pop();
        }
        
        // maxarea return
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans,height[i]*(right[i] - left[i] - 1));
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int col = matrix[0].size();
        int row = matrix.size();
        int ans = 0;
        
        vector<int> height(col,0);
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == '0'){
                    height[j] = 0; 
                }
                else{
                    height[j] += 1;
                }
            }
             ans = max(ans,maxArea(height));
        }
        return ans;
    }
};