class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n = height.size();
        //lets create vector and stack we need
        vector<int> right(n);
        vector<int> left(n);
        stack<int> st;
        
        //create right min array
        for(int i=0; i<n; i++){
            while(!st.empty() && height[i] < height[st.top()]){
                // put the index in array
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        } 
        
        //while stack is not empty put size(n) 
        while(!st.empty()){
                right[st.top()] = n;
                st.pop();
        }
        // create left min array
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && height[i] < height[st.top()]){
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        } 
        
        //while stack is not empty put -1
        while(!st.empty()){
                left[st.top()] = -1;
                st.pop();
        }
        
        int area = 0;
        for(int i=0; i<n; i++){
            area = max(area,height[i]*(right[i] - left[i] -1));
        }
        return area;
        
    }
};