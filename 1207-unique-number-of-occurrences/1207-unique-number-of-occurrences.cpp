class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int newArr[2001] = {0};
        for (int i = 0; i < arr.size(); i++){
            newArr[arr[i] + 1000]++;
        }
        sort(newArr, newArr + 2001);
        for (int i = 1; i < 2001; i++) {
            if (newArr[i] > 0 && newArr[i] == newArr[i - 1]) {
                return false;
            }
        }
        return true; // Added return statement
    }
};
