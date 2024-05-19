class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int s = 0;
        int e = col*row-1;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            if(target == matrix[mid/col][mid%col]){
                return true;
            }
            else if(target < matrix[mid/col][mid%col]){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        
        return false;
    }
};