class Solution {
public:
    void func(int n, int i, int c1, int c2, string &cur, vector<string> &ans){
        if(i == 2*n+1){
            ans.push_back(cur);
            return;
        }

        //if c1 is remaining
        if(c1 < n){
            cur.push_back('(');
            func(n, i+1, c1+1, c2, cur, ans);
            cur.pop_back();
        }

        if(c2 < c1){
            cur.push_back(')');
            func(n, i+1, c1, c2+1, cur, ans);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str = "";
        func(n, 1, 0, 0, str, ans);
        return ans;
    }
};