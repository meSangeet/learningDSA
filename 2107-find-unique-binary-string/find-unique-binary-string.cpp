class Solution {
public:
    string func(int i, string cur, int n, set<string> &st){
        if(i == n){
            if(st.count(cur)){
                return "";
            }
            return cur;
        }

        cur.push_back('1');
        string temp = func(i+1, cur, n, st);
        if(temp != "") return temp;

        cur.pop_back();

        cur.push_back('0');
        temp = func(i+1, cur, n, st);
        cur.pop_back();
        return temp;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> st(nums.begin(), nums.end());
        string cur = "";
        return func(0,cur,nums[0].size(),st);
    }
};