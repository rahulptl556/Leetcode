class Solution {
public:
    void parenthesis(int n, int l, int r, string &temp, vector<string>&ans){

  if(l == n && r == n){
    ans.push_back(temp);
    return;
  }
  
  if(l <= n){
    temp.push_back('(');
    parenthesis(n,l+1,r,temp,ans);
    temp.pop_back();
  }
  
  if(r < l){
    temp.push_back(')');
    parenthesis(n,l,r+1,temp,ans);
    temp.pop_back();
  }
}

    vector<string> generateParenthesis(int n) {
        string temp;
        vector<string> ans = {};
        parenthesis(n,0,0,temp,ans);
        return ans;
    }
};