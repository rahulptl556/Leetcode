class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        
        int candidate = 0;
        int count = 0;
        for(int i=0; i<n; i++){
            if(count == 0){
                count++;
                candidate = arr[i];
            }
            else if(count>0 && arr[i] == candidate){
                count++;
            }
            else if(count>0 && arr[i] != candidate){
                count--;
            }
        }
        return candidate;
    }
};