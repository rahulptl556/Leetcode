class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        //creating a map
        map<int, int> m;
        
        for(auto x: tasks) m[x]++;
        int ans = 0;
        for(auto x: m) {
            if(x.second < 2) return -1;
            ans += ceil(1.0 * x.second / 3);
        }
        return ans;
    }
};