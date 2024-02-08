class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int s = 0;
        int e = arr.size()-1;
        
        while(s<e){
            if(arr[s]+arr[e] == target){
                return {s+1,e+1};
            }
            else if(arr[s]+arr[e] > target){
                e--;
            }
            else if(arr[s]+arr[e]<target){
                s++;
            }
        }  
        return {};
    }
};