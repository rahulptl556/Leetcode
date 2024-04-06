class Solution {
    
public:
    void subSeq(vector<int> arr,int i, int size, vector<int> temp,vector<vector<int>> &ans){
          if(i == size){
            ans.push_back(temp);
            return;
          }
          //Not included
          subSeq(arr,i+1,size,temp,ans);

          //Included
          temp.push_back(arr[i]);
          subSeq(arr,i+1,size,temp,ans);
    }
    vector<vector<int>> subsets(vector<int>& arr) {
          vector<int> temp = {};
          vector<vector<int>> ans = {};
          subSeq(arr, 0,arr.size(), temp, ans);
        return ans;
    }
};