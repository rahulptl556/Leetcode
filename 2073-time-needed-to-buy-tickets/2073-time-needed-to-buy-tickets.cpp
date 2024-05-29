class Solution {
public:
    int timeRequiredToBuy(vector<int>& arr, int k) {
        int time = 0;
        int n = arr.size();
            
        for(int i=0; i<n; i++){
            if(i<=k){
                if(arr[i] <= arr[k]){
                    time+= arr[i];
                }
                else{
                    time+= arr[k];
                }
            }
            if(i>k){
                if(arr[i] < arr[k]){
                    time += arr[i];
                }
                else{
                    time += arr[k]-1;
                }
            }
        }
        return time;
    }
};