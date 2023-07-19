#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
private:
    void solve(string digits, int ind, string curr, vector<string> &ans, vector<string> &ds)
    {
        if(ind == digits.length())
        {
            ans.push_back(curr);
            return;
        }
        int index = digits[ind] - '0';
        for(int i = 0; i<ds[index].length(); i++)
        {
            curr.push_back(ds[index][i]);
            solve(digits, ind+1, curr, ans, ds);
            curr.pop_back();
        }

        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        if(digits.length() == 0) return ans;
        vector<string> ds = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, 0, "", ans, ds);
        return ans;
    }
};

int main()
{
    return 0;
}