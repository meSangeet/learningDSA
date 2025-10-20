class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        string str1 = "--X", str2 = "X--", str3 = "X++", str4 = "++X";
        int ans = 0;
        for(int i = 0; i<operations.size(); i++)
        {
            if(operations[i] == str1 || operations[i] == str2)
            {
                ans--;
            }else{
                ans++;
            }
        }
        return ans;
    }
};