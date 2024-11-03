class Solution {

    bool isPalindrome(string &s, int start, int end){
        //code to check palindrome
        while(start < end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

public:
    int minCut(string s) {
        /*
            n-1 -> total no of possible cuts -> 2^n 

            () | ()

            min length = 1

            dp[0] -> minimum no of cuts such that < condition > for the array 0 to last //goal
            dp[i] -> same above condition from i to last




        */
        int n = s.length();

        vector<int> dp(n, INT_MAX);
        //base case 
        dp[n-1] = 0;
        for(int i = n-2; i>=0; i--){
            // cout<<" i - "<<i<<endl;
            for(int j = i; j < n; j++){
                // cout<<"j - "<<j<<endl;
                // bool flag = true;
                // int start = 
                if(isPalindrome(s, i, j)){
                    // cout<<i<<" "<<j<<endl;
                    if(j+1 != n)
                    dp[i] = min(dp[i], 1 + dp[j+1]);
                    else
                    dp[i] = 0;
                }
                // cout<<dp[i]<<endl
            }
        }

        return dp[0];
    }
};