class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        for(int i=0; i<row; i++){
            
            // Check if target present in that row
            if(matrix[i][0] <= target && target <= matrix[i][col-1]){
                
                // Implement BS
                int s = 0;
                int e = col-1;
                
                while(s<=e){
                   int mid = s + (e-s)/2;
                   if(target == matrix[i][mid]){
                       return true;
                   }
                    else if(target > matrix[i][mid]){
                        // Go to right
                        s = mid+1;
                    }
                    else{
                       // Go to left
                       e = mid-1;
                   }
                }
            }
        }
        return false;
    }
};