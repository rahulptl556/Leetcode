class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        int count[2001]={0};
        for(int i=0;i<arr.size();i++){
            count[arr[i]+1000]++;
        }
        sort(count,count+2001);
        for(int i=0;i<2000;i++){
            if(count[i]==count[i+1] && count[i]>0){
                //cout<<count[i]<<" ";
                return false;
            }
        }
        return true;
    }
};